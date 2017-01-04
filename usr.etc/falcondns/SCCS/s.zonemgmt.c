h64150
s 00001/00001/00473
d D 1.19 2013/08/10 08:24:09 msokolov 19 18
c don't set Z_RETRYING when MNAME query is delayed for not-ready-to-serve
e
s 00008/00001/00466
d D 1.18 2013/01/14 00:40:08 msokolov 18 17
c class ready-to-serve flag implemented
e
s 00001/00001/00466
d D 1.17 2013/01/06 08:30:36 msokolov 17 16
c preparations for librification:
c s/store_label_casepreserve/copy_label_casepreserve/
c s/store_label_can/copy_label_can/
e
s 00001/00001/00466
d D 1.16 2013/01/06 07:03:47 msokolov 16 15
c MSDNS => FalconDNS
e
s 00002/00000/00465
d D 1.15 2011/12/25 23:56:55 msokolov 15 14
c watch out for zone_fileread_roundrobin when deleting a zone
e
s 00010/00002/00455
d D 1.14 2011/12/16 07:01:55 msokolov 14 13
c zonesecond.c code tied in
e
s 00076/00000/00381
d D 1.13 2011/12/15 02:40:42 msokolov 13 12
c refresh-zone command implemented
e
s 00003/00002/00378
d D 1.12 2011/12/15 02:18:20 msokolov 12 11
c prep for zone refresh generalization
e
s 00004/00002/00376
d D 1.11 2011/12/15 01:31:46 msokolov 11 10
c zone def change handling: be more careful with zones_needing_fileread count
e
s 00060/00000/00318
d D 1.10 2011/12/15 01:28:35 msokolov 10 9
c reload-zone command implemented
e
s 00017/00002/00301
d D 1.9 2011/12/15 01:13:59 msokolov 9 8
c zone definition change implemented
e
s 00028/00009/00275
d D 1.8 2011/12/15 01:03:41 msokolov 8 7
c beginning of refactoring
e
s 00002/00000/00282
d D 1.7 2011/12/13 02:46:29 msokolov 7 6
c syslog zone deletion
e
s 00072/00006/00210
d D 1.6 2011/12/13 01:22:00 msokolov 6 5
c zone deletion support
e
s 00047/00000/00169
d D 1.5 2011/07/18 05:54:13 msokolov 5 4
c basic refresh logic implemented
e
s 00001/00001/00168
d D 1.4 2011/07/17 00:38:24 msokolov 4 3
c label case handling rethought slightly
e
s 00017/00011/00152
d D 1.3 2011/07/14 07:42:36 msokolov 3 2
c a few fixes
e
s 00004/00002/00159
d D 1.2 2011/07/13 23:45:47 msokolov 2 1
c preparations for zone file reading
e
s 00161/00000/00000
d D 1.1 2011/07/13 23:11:48 msokolov 1 0
c date and time created 2011/07/13 23:11:48 by msokolov
e
u
U
t
T
I 1
/*
D 16
 * Michael Sokolov's Domain Name Server (MSDNS)
E 16
I 16
 * FalconDNS daemon by Michael Spacefalcon
E 16
 *
 * Zone management functions
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
I 5
#include <sys/stat.h>
E 5
#include <arpa/nameser.h>
I 10
#include <ctype.h>
E 10
#include <stdio.h>
#include <strings.h>
#include <syslog.h>
#include "defs.h"
#include "dname.h"
#include "class.h"
#include "zone.h"
I 5
#include "tree.h"
#include "rr.h"
#include "selectloop.h"
E 5
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
D 6
	struct dname *dn;
E 6
I 6
	register struct dname *dn;
E 6
	char *asc;
{
	int malloclen, dnsize;
	register u_char *dp;
D 6
	struct zone *z;
E 6
I 6
	register struct zone *z;
E 6

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
D 3
	z->z_ascii_domname = asc;
E 3
I 3
	z->z_ascii_domname = (char *)dp;
I 6
	z->z_refcount = 1;
E 6
E 3
	return(z);
}

I 6
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

E 6
D 8
zone_add_request(cl, domname, filename, remote)
E 8
I 8
zone_add_request(cl, domname, filename, remote, fromaddr)
E 8
	struct class *cl;
	char *domname, *filename;
I 8
	u_long fromaddr;
E 8
{
	struct dname dname;
D 3
	register struct zone *z;
E 3
I 3
	register struct zone *z, *znext;
E 3

	if (parse_ascii_dname(domname, &dname) < 0) {
D 2
		syslog(LOG_ERR, "%s: line %d: zone: invalid domain-name",
			cl->c_filename, cl->c_fileread_lineno);
E 2
I 2
		syslog(LOG_ERR, "%s: line %d: zone: invalid domain-name %s",
			cl->c_filename, cl->c_fileread_lineno, domname);
E 2
		return;
	}
	if (strlen(filename) > MAX_FILENAME) {
		syslog(LOG_ERR, "%s: line %d: zone file name is too long",
			cl->c_filename, cl->c_fileread_lineno);
		return;
	}
	z = find_zone_in_catalog(cl, &dname);
	if (z)
D 8
		return(zone_mod_request(z, filename, remote));
E 8
I 8
		return(zone_mod_request(z, filename, remote, fromaddr));
E 8
	z = alloc_struct_zone(&dname, domname);
D 3
	if (!z)
		return(-1);	/* syslog already done in myalloc */
E 3
I 3
	if (!z) {
memfail:	syslog(LOG_CRIT,
			"unable to allocate memory to register zone %s (%d)",
			domname, cl->c_class);
		return;
	}
E 3
	z->z_class = cl;
	strcpy(z->z_filename, filename);
	if (remote)
		z->z_flags |= Z_REMOTE;
I 8
	z->z_fromaddr_config = fromaddr;
E 8
	if (add_zone_to_catalog(z) < 0) {
		free(z);
D 3
		return;
E 3
I 3
		goto memfail;
E 3
	}
D 3
	z->z_next_perclass = cl->c_zonelist;
	if (z->z_next_perclass)
		*z->z_next_perclass->z_backref_perclass = z;
E 3
I 3
	znext = cl->c_zonelist;
	z->z_next_perclass = znext;
	if (znext)
		znext->z_backref_perclass = &z->z_next_perclass;
E 3
	cl->c_zonelist = z;
	z->z_backref_perclass = &cl->c_zonelist;
D 3
	z->z_next_global = global_zone_list;
	if (z->z_next_global)
		*z->z_next_global->z_backref_global = z;
E 3
I 3
	znext = global_zone_list;
	z->z_next_global = znext;
	if (znext)
		znext->z_backref_global = &z->z_next_global;
E 3
	global_zone_list = z;
	z->z_backref_global = &global_zone_list;
	syslog(LOG_INFO, "class %d: zone %s registered", cl->c_class, domname);
I 2
	z->z_flags |= Z_FILEREAD_NEEDED;
	zones_needing_fileread++;
I 18
	cl->c_outstanding_loads++;
E 18
E 2
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
D 6
	struct catalog *parent;
E 6
	int depth;

	c = &cl->c_catalog;
	depth = dn->dn_nlabels;
	while (depth--) {
		sought_label = dn->dn_labels[depth];
D 6
		parent = c;
E 6
		for (pp = &c->cat_firstchild; c = *pp; pp = &c->cat_nextsib)
			if (label_match_can(sought_label, c))
				break;
		if (!c) {
			c = (struct catalog *)myalloc(sizeof(struct catalog));
			if (!c)
				return(-1);
			bzero(c, sizeof(struct catalog));
D 4
			store_label_in_node(sought_label, c);
E 4
I 4
D 17
			store_label_can(sought_label, c);
E 17
I 17
			copy_label_can(sought_label, c);
E 17
E 4
D 6
			c->cat_parent = parent;
E 6
			*pp = c;
		}
	}
	c->cat_zone = z;
I 6
	z->z_catnode = c;
E 6
	return(0);
}

D 8
zone_mod_request(z, filename, remote)
E 8
I 8
zone_mod_request(z, filename, remote, fromaddr)
E 8
D 6
	struct zone *z;
E 6
I 6
	register struct zone *z;
E 6
	char *filename;
I 8
	u_long fromaddr;
E 8
{
I 8
	int oldremote;

E 8
I 6
	z->z_flags &= ~Z_DEL_CANDIDATE;
D 8
	if (!strcmp(z->z_filename, filename))
E 8
I 8
	z->z_fromaddr_config = fromaddr;
	oldremote = (z->z_flags & Z_REMOTE) != 0;
	if (!strcmp(z->z_filename, filename) && remote == oldremote)
E 8
		return;
E 6
D 9
	syslog(LOG_ERR,
		"class %d zone %s: zone mod request not implemented yet",
E 9
I 9
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
D 11
	z->z_flags |= Z_FILEREAD_NEEDED;
	zones_needing_fileread++;
E 11
I 11
	if (!(z->z_flags & Z_FILEREAD_NEEDED)) {
		z->z_flags |= Z_FILEREAD_NEEDED;
		zones_needing_fileread++;
I 18
		z->z_class->c_outstanding_loads++;
E 18
	}
E 11
	syslog(LOG_INFO,
		"class %d zone %s: definition changed, scheduled reload",
E 9
		z->z_class->c_class, z->z_ascii_domname);
I 5
}

void
D 12
local_zone_refresh_handler(z)
E 12
I 12
zone_refresh(z)
E 12
	register struct zone *z;
{
	struct stat st;

	z->z_refresh = 0;
I 12
D 14
	/* diversion for remote/secondary zone code path will go here */
E 14
I 14
	if (z->z_flags & Z_REMOTE) {
		remote_zone_refresh(z);
		return;
	}
E 14
E 12
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
I 18
		z->z_class->c_outstanding_loads++;
E 18
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
D 12
	t->tim_func = local_zone_refresh_handler;
E 12
I 12
	t->tim_func = zone_refresh;
E 12
	t->tim_arg = (caddr_t) z;
	time_schedule(t);
	z->z_refresh = t;
I 14
D 19
	if (retry)
E 19
I 19
	if (retry == 1)
E 19
		z->z_flags |= Z_RETRYING;
	else
		z->z_flags &= ~Z_RETRYING;
E 14
I 6
}

D 8
delete_zone(z)
E 8
I 8
zone_abort_activities(z)
E 8
	register struct zone *z;
{
D 8
	register struct zone *next;

	if (z->z_refresh)
E 8
I 8
	if (z->z_refresh) {
E 8
		timesched_discard(z->z_refresh);
I 8
		z->z_refresh = 0;
	}
E 8
	if (z->z_fileread) {
		FD_CLR(fileno(z->z_fileread), &select_for_read);
		fclose(z->z_fileread);
I 8
		z->z_fileread = 0;
E 8
		zone_fileread_inprogress = 0;
I 18
		z->z_class->c_outstanding_loads--;
E 18
	}
D 8
	if (z->z_tree_inprogress)
E 8
I 8
	if (z->z_tree_inprogress) {
E 8
		free_subtree(z->z_tree_inprogress);
I 8
		z->z_tree_inprogress = 0;
	}
D 14
	/* TODO: abort secondary zone activities */
E 14
I 14
	abort_remote_zone_refresh(z);
E 14
}

delete_zone(z)
	register struct zone *z;
{
	register struct zone *next;

	zone_abort_activities(z);
E 8
	if (z->z_activetree)
		replace_zone_tree(z->z_activetree, 0);
D 18
	if (z->z_flags & Z_FILEREAD_NEEDED)
E 18
I 18
	if (z->z_flags & Z_FILEREAD_NEEDED) {
E 18
		zones_needing_fileread--;
I 18
		z->z_class->c_outstanding_loads--;
	}
E 18
	z->z_catnode->cat_zone = 0;
	next = z->z_next_perclass;
	if (next)
		next->z_backref_perclass = z->z_backref_perclass;
	*z->z_backref_perclass = next;
	next = z->z_next_global;
	if (next)
		next->z_backref_global = z->z_backref_global;
	*z->z_backref_global = next;
I 15
	if (zone_fileread_roundrobin == z)
		zone_fileread_roundrobin = 0;
E 15
I 7
	syslog(LOG_INFO, "class %d: zone %s deleted\n", z->z_class->c_class,
		z->z_ascii_domname);
E 7
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
I 10
}

void
I 13
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
I 14
	z->z_flags &= ~Z_RETRYING;
E 14
	zone_refresh(z);
}

void
E 13
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
I 18
	cl->c_outstanding_loads++;
E 18
	syslog(LOG_INFO, "reload-zone: %s (%d) scheduled for file read",
		z->z_ascii_domname, classnum);
E 10
E 6
E 5
}
E 1
