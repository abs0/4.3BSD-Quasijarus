/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * Zone management functions
 */

#ifndef lint
static char sccsid[] = "@(#)zonemgmt.c	1.19 (IFCTF) 2013/08/10";
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/nameser.h>
#include <ctype.h>
#include <stdio.h>
#include <strings.h>
#include <syslog.h>
#include "defs.h"
#include "dname.h"
#include "class.h"
#include "zone.h"
#include "tree.h"
#include "rr.h"
#include "selectloop.h"
#include "globals.h"

extern u_char *myalloc();

struct zone *
find_zone_in_catalog(cl, dn)
	struct class *cl;
	struct dname *dn;
{
	register struct catalog *c;
	register u_char *sought_label;
	int depth;

	c = &cl->c_catalog;
	depth = dn->dn_nlabels;
	while (depth--) {
		sought_label = dn->dn_labels[depth];
		for (c = c->cat_firstchild; c; c = c->cat_nextsib)
			if (label_match_can(sought_label, c))
				break;
		if (!c)
			return(0);
	}
	return(c->cat_zone);
}

struct zone *
alloc_struct_zone(dn, asc)
	register struct dname *dn;
	char *asc;
{
	int malloclen, dnsize;
	register u_char *dp;
	register struct zone *z;

	dnsize = dn_spaceneeded(dn);
	malloclen = sizeof(struct zone) + dnsize + strlen(asc) + 1;
	dp = myalloc(malloclen);
	if (!dp)
		return(0);
	z = (struct zone *)dp;
	bzero(z, sizeof(struct zone));
	dp += sizeof(struct zone);
	dname_copy(dn, dp);
	z->z_dname = (struct dname *)dp;
	dp += dnsize;
	strcpy(dp, asc);
	z->z_ascii_domname = (char *)dp;
	z->z_refcount = 1;
	return(z);
}

void
free_struct_zone(z)
	register struct zone *z;
{
	if (--z->z_refcount > 0)
		return;
	if (z->z_refcount < 0) {
		syslog(LOG_CRIT, "BUG: z_refcount decremented past zero");
		abort();
	}
	free(z);
}

zone_add_request(cl, domname, filename, remote, fromaddr)
	struct class *cl;
	char *domname, *filename;
	u_long fromaddr;
{
	struct dname dname;
	register struct zone *z, *znext;

	if (parse_ascii_dname(domname, &dname) < 0) {
		syslog(LOG_ERR, "%s: line %d: zone: invalid domain-name %s",
			cl->c_filename, cl->c_fileread_lineno, domname);
		return;
	}
	if (strlen(filename) > MAX_FILENAME) {
		syslog(LOG_ERR, "%s: line %d: zone file name is too long",
			cl->c_filename, cl->c_fileread_lineno);
		return;
	}
	z = find_zone_in_catalog(cl, &dname);
	if (z)
		return(zone_mod_request(z, filename, remote, fromaddr));
	z = alloc_struct_zone(&dname, domname);
	if (!z) {
memfail:	syslog(LOG_CRIT,
			"unable to allocate memory to register zone %s (%d)",
			domname, cl->c_class);
		return;
	}
	z->z_class = cl;
	strcpy(z->z_filename, filename);
	if (remote)
		z->z_flags |= Z_REMOTE;
	z->z_fromaddr_config = fromaddr;
	if (add_zone_to_catalog(z) < 0) {
		free(z);
		goto memfail;
	}
	znext = cl->c_zonelist;
	z->z_next_perclass = znext;
	if (znext)
		znext->z_backref_perclass = &z->z_next_perclass;
	cl->c_zonelist = z;
	z->z_backref_perclass = &cl->c_zonelist;
	znext = global_zone_list;
	z->z_next_global = znext;
	if (znext)
		znext->z_backref_global = &z->z_next_global;
	global_zone_list = z;
	z->z_backref_global = &global_zone_list;
	syslog(LOG_INFO, "class %d: zone %s registered", cl->c_class, domname);
	z->z_flags |= Z_FILEREAD_NEEDED;
	zones_needing_fileread++;
	cl->c_outstanding_loads++;
}

/*
 * This function is called when we've already verified that the zone
 * doesn't exist in the catalog yet.
 *
 * This operation may require allocating new catalog nodes
 * and therefore can fail because of malloc.  -1 return in that case.
 */
add_zone_to_catalog(z)
	struct zone *z;
{
	struct class *cl = z->z_class;
	struct dname *dn = z->z_dname;
	register struct catalog *c, **pp;
	register u_char *sought_label;
	int depth;

	c = &cl->c_catalog;
	depth = dn->dn_nlabels;
	while (depth--) {
		sought_label = dn->dn_labels[depth];
		for (pp = &c->cat_firstchild; c = *pp; pp = &c->cat_nextsib)
			if (label_match_can(sought_label, c))
				break;
		if (!c) {
			c = (struct catalog *)myalloc(sizeof(struct catalog));
			if (!c)
				return(-1);
			bzero(c, sizeof(struct catalog));
			copy_label_can(sought_label, c);
			*pp = c;
		}
	}
	c->cat_zone = z;
	z->z_catnode = c;
	return(0);
}

zone_mod_request(z, filename, remote, fromaddr)
	register struct zone *z;
	char *filename;
	u_long fromaddr;
{
	int oldremote;

	z->z_flags &= ~Z_DEL_CANDIDATE;
	z->z_fromaddr_config = fromaddr;
	oldremote = (z->z_flags & Z_REMOTE) != 0;
	if (!strcmp(z->z_filename, filename) && remote == oldremote)
		return;
	/*
	 * We implement modification by aborting any in-progress fileread
	 * or remote zone refresh activities, canceling any scheduled
	 * refresh, changing the filename and/or the remote flag, then
	 * scheduling a new fileread, which if successful will then
	 * trigger the rest just like on a fresh boot.
	 */
	zone_abort_activities(z);
	strcpy(z->z_filename, filename);
	if (remote)
		z->z_flags |= Z_REMOTE;
	else
		z->z_flags &= ~Z_REMOTE;
	if (!(z->z_flags & Z_FILEREAD_NEEDED)) {
		z->z_flags |= Z_FILEREAD_NEEDED;
		zones_needing_fileread++;
		z->z_class->c_outstanding_loads++;
	}
	syslog(LOG_INFO,
		"class %d zone %s: definition changed, scheduled reload",
		z->z_class->c_class, z->z_ascii_domname);
}

void
zone_refresh(z)
	register struct zone *z;
{
	struct stat st;

	z->z_refresh = 0;
	if (z->z_flags & Z_REMOTE) {
		remote_zone_refresh(z);
		return;
	}
	if (stat(z->z_filename, &st) < 0) {
		syslog(LOG_CRIT, "zone refresh: %s (%d): can't stat %s: %m",
			z->z_ascii_domname, z->z_class->c_class, z->z_filename);
		schedule_zone_refresh(z, 1);
		return;
	}
	if (st.st_mtime != z->z_file_mtime) {
		syslog(LOG_NOTICE,
			"zone refresh: %s (%d): %s changed, scheduling reload",
			z->z_ascii_domname, z->z_class->c_class, z->z_filename);
		z->z_flags |= Z_FILEREAD_NEEDED;
		zones_needing_fileread++;
		z->z_class->c_outstanding_loads++;
	} else
		schedule_zone_refresh(z, 0);
}

schedule_zone_refresh(z, retry)
	register struct zone *z;
{
	register struct node *n;
	register struct timesched *t;

	n = z->z_activetree;
	if (!n)
		return;
	t = (struct timesched *)myalloc(sizeof(struct timesched));
	if (!t)
		return;
	t->tim_time = current_time + (retry ? n->n_soa->soa_retry
					    : n->n_soa->soa_refresh);
	t->tim_func = zone_refresh;
	t->tim_arg = (caddr_t) z;
	time_schedule(t);
	z->z_refresh = t;
	if (retry == 1)
		z->z_flags |= Z_RETRYING;
	else
		z->z_flags &= ~Z_RETRYING;
}

zone_abort_activities(z)
	register struct zone *z;
{
	if (z->z_refresh) {
		timesched_discard(z->z_refresh);
		z->z_refresh = 0;
	}
	if (z->z_fileread) {
		FD_CLR(fileno(z->z_fileread), &select_for_read);
		fclose(z->z_fileread);
		z->z_fileread = 0;
		zone_fileread_inprogress = 0;
		z->z_class->c_outstanding_loads--;
	}
	if (z->z_tree_inprogress) {
		free_subtree(z->z_tree_inprogress);
		z->z_tree_inprogress = 0;
	}
	abort_remote_zone_refresh(z);
}

delete_zone(z)
	register struct zone *z;
{
	register struct zone *next;

	zone_abort_activities(z);
	if (z->z_activetree)
		replace_zone_tree(z->z_activetree, 0);
	if (z->z_flags & Z_FILEREAD_NEEDED) {
		zones_needing_fileread--;
		z->z_class->c_outstanding_loads--;
	}
	z->z_catnode->cat_zone = 0;
	next = z->z_next_perclass;
	if (next)
		next->z_backref_perclass = z->z_backref_perclass;
	*z->z_backref_perclass = next;
	next = z->z_next_global;
	if (next)
		next->z_backref_global = z->z_backref_global;
	*z->z_backref_global = next;
	if (zone_fileread_roundrobin == z)
		zone_fileread_roundrobin = 0;
	syslog(LOG_INFO, "class %d: zone %s deleted\n", z->z_class->c_class,
		z->z_ascii_domname);
	free_struct_zone(z);
}

mark_delcandidate_zones(cl)
	struct class *cl;
{
	register struct zone *z;

	for (z = cl->c_zonelist; z; z = z->z_next_perclass)
		z->z_flags |= Z_DEL_CANDIDATE;
}

delete_marked_zones(cl)
	struct class *cl;
{
	register struct zone *z, *nz;

	for (z = cl->c_zonelist; z; z = nz) {
		nz = z->z_next_perclass;
		if (z->z_flags & Z_DEL_CANDIDATE)
			delete_zone(z);
	}
}

void
cmd_refresh_zone(args)
	char *args;
{
	register char *cp;
	char *arg1, *arg2;
	int classnum;
	register struct class *cl;
	struct dname dname;
	register struct zone *z;

	for (cp = args; isspace(*cp); cp++)
		;
	if (!isdigit(*cp)) {
badusage:	syslog(LOG_ERR, "usage: refresh-zone class domain-name");
		return;
	}
	for (arg1 = cp; *cp && !isspace(*cp); cp++)
		;
	if (!*cp)
		goto badusage;
	*cp++ = '\0';
	while (isspace(*cp))
		cp++;
	if (!*cp)
		goto badusage;
	for (arg2 = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
	classnum = atoi(arg1);
	if (classnum >= 255)
		goto badusage;
	cl = class_array[classnum];
	if (!cl) {
		syslog(LOG_ERR, "refresh-zone: class %d not defined", classnum);
		return;
	}
	if (parse_ascii_dname(arg2, &dname) < 0)
		goto badusage;
	z = find_zone_in_catalog(cl, &dname);
	if (!z) {
		syslog(LOG_ERR, "refresh-zone: %s not found in class %d", arg2,
			classnum);
		return;
	}
	if (z->z_flags & Z_FILEREAD_NEEDED) {
		syslog(LOG_INFO,
		"refresh-zone: %s (%d) is already scheduled for file read",
			z->z_ascii_domname, classnum);
		return;
	}
	if (z->z_fileread) {
		syslog(LOG_INFO,
			"refresh-zone: %s (%d) is already in file read",
			z->z_ascii_domname, classnum);
		return;
	}
	if (z->z_mname_query || z->z_soa_check || z->z_puller_pid) {
		syslog(LOG_INFO, "refresh-zone: %s (%d) is already in refresh",
			z->z_ascii_domname, classnum);
		return;
	}
	if (!z->z_activetree) {
		syslog(LOG_ERR,
	"refresh-zone: %s (%d) has no active tree, use reload-zone instead",
			z->z_ascii_domname, classnum);
		return;
	}
	if (z->z_refresh) {
		timesched_discard(z->z_refresh);
		z->z_refresh = 0;
	}
	z->z_flags &= ~Z_RETRYING;
	zone_refresh(z);
}

void
cmd_reload_zone(args)
	char *args;
{
	register char *cp;
	char *arg1, *arg2;
	int classnum;
	register struct class *cl;
	struct dname dname;
	register struct zone *z;

	for (cp = args; isspace(*cp); cp++)
		;
	if (!isdigit(*cp)) {
badusage:	syslog(LOG_ERR, "usage: reload-zone class domain-name");
		return;
	}
	for (arg1 = cp; *cp && !isspace(*cp); cp++)
		;
	if (!*cp)
		goto badusage;
	*cp++ = '\0';
	while (isspace(*cp))
		cp++;
	if (!*cp)
		goto badusage;
	for (arg2 = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
	classnum = atoi(arg1);
	if (classnum >= 255)
		goto badusage;
	cl = class_array[classnum];
	if (!cl) {
		syslog(LOG_ERR, "reload-zone: class %d not defined", classnum);
		return;
	}
	if (parse_ascii_dname(arg2, &dname) < 0)
		goto badusage;
	z = find_zone_in_catalog(cl, &dname);
	if (!z) {
		syslog(LOG_ERR, "reload-zone: %s not found in class %d", arg2,
			classnum);
		return;
	}
	if (z->z_flags & Z_FILEREAD_NEEDED) {
		syslog(LOG_INFO,
		"reload-zone: %s (%d) is already scheduled for file read",
			z->z_ascii_domname, classnum);
		return;
	}
	zone_abort_activities(z);
	z->z_flags |= Z_FILEREAD_NEEDED;
	zones_needing_fileread++;
	cl->c_outstanding_loads++;
	syslog(LOG_INFO, "reload-zone: %s (%d) scheduled for file read",
		z->z_ascii_domname, classnum);
}
