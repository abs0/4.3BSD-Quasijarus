h30651
s 00014/00000/00276
d D 1.13 2013/01/14 00:40:06 msokolov 13 12
c class ready-to-serve flag implemented
e
s 00000/00088/00276
d D 1.12 2013/01/13 16:43:44 msokolov 12 11
c class refresh/reload split out into classreload.c
e
s 00001/00001/00363
d D 1.11 2013/01/06 07:03:32 msokolov 11 10
c MSDNS => FalconDNS
e
s 00002/00002/00362
d D 1.10 2011/12/25 05:48:47 msokolov 10 9
c allow comments at the end of zone or NS-anchor lines
e
s 00020/00004/00344
d D 1.9 2011/12/15 00:16:32 msokolov 9 8
c new syntax for secondary zones
e
s 00095/00000/00253
d D 1.8 2011/12/13 02:41:13 msokolov 8 7
c class reloading implemented
e
s 00037/00000/00216
d D 1.7 2011/09/12 06:20:30 msokolov 7 6
c NS-anchor directive implemented
e
s 00030/00019/00186
d D 1.6 2011/07/14 22:51:46 msokolov 6 5
c daemonization better thought through
e
s 00001/00001/00204
d D 1.5 2011/07/13 23:45:44 msokolov 5 4
c preparations for zone file reading
e
s 00075/00001/00130
d D 1.4 2011/07/13 20:30:57 msokolov 4 3
c parsing of zone lines implemented
e
s 00063/00000/00068
d D 1.3 2011/07/13 19:23:14 msokolov 3 2
c we now read the class def file, although don't do anything with it yet
e
s 00004/00004/00064
d D 1.2 11/07/11 16:42:40 msokolov 2 1
c catch class redefinition, don't bother trying to catch no classes
e
s 00068/00000/00000
d D 1.1 11/07/11 08:04:02 msokolov 1 0
c MSDNS project started, template compiles
e
u
U
t
T
I 1
/*
D 11
 * Michael Sokolov's Domain Name Server (MSDNS)
E 11
I 11
 * FalconDNS daemon by Michael Spacefalcon
E 11
 *
 * Class management functions
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
I 9
#include <netinet/in.h>
#include <arpa/inet.h>
E 9
I 3
#include <arpa/nameser.h>
I 4
#include <ctype.h>
E 4
E 3
#include <stdio.h>
#include <strings.h>
#include <syslog.h>
I 3
#include "defs.h"
E 3
#include "class.h"
#include "globals.h"
I 3
#include "selectloop.h"
I 8
D 12
#include "zone.h"
E 12
E 8
E 3

D 6
extern char *malloc();
E 6
I 6
extern char *myalloc();
E 6

register_class(classnum, classfile)
	char *classfile;
{
	register struct class *cl;
I 6
	register char *dp;
E 6

	if (classnum >= 255) {
D 6
		fprintf(stderr,
		"msdns: class numbers greater than 254 aren't supported\n");
		exit(1);
E 6
I 6
		init_error(LOG_ERR,
			"class numbers greater than 254 aren't supported\n");
		return;
E 6
	}
I 2
	if (class_array[classnum]) {
D 6
		fprintf(stderr, "msdns: redefinition of class %d\n", classnum);
		exit(1);
E 6
I 6
		if (!initdone) {
			fprintf(stderr,
				"msdns: redefinition of class %d\n", classnum);
			exit(1);
		}
		/*
		 * We don't support in-flight modification
		 * of already-registered classes except via
		 * a separate refresh-class command, so we just
		 * silently ignore the class line.
		 */
		return;
E 6
	}
E 2
D 6
	if (strlen(classfile) > MAX_FILENAME) {
		fprintf(stderr, "msdns: %s: class file name too long\n",
			classfile);
		exit(1);
E 6
I 6
	dp = myalloc(sizeof(struct class) + strlen(classfile) + 1);
	if (!dp) {
		init_error(LOG_CRIT, "malloc failure registering class %d\n",
			classnum);
		return;
E 6
	}
D 6
	cl = (struct class *)malloc(sizeof(struct class));
	if (!cl) {
		perror("msdns: malloc failure registering a class");
		exit(1);
	}
E 6
I 6
	cl = (struct class *)dp;
	dp += sizeof(struct class);
E 6
	bzero(cl, sizeof(struct class));
	cl->c_class = classnum;
D 6
	strcpy(cl->c_filename, classfile);
E 6
I 6
	strcpy(dp, classfile);
	cl->c_filename = dp;
E 6
	cl->c_fileread_needed = 1;
	class_array[classnum] = cl;
	classes_needing_fileread++;
I 6
	syslog(LOG_DEBUG, "registered class id %d using file %s",
		classnum, classfile);
E 6
	return(0);
}

setup_class_linked_list()
{
	int class;
	register struct class *cp, **dp;

	dp = &class_list;
	for (class = 0; class < 255; class++) {
		cp = class_array[class];
		if (!cp)
			continue;
		*dp = cp;
		dp = &cp->c_next;
	}
	*dp = NULL;
D 2
	if (!cp) {
		fprintf(stderr, "msdns: no classes defined\n");
		exit(1);
	}
E 2
	return(0);
I 3
}

I 13
void
class_ready_check(cl)
	register struct class *cl;
{
	if (cl->c_ready_to_serve)
		return;
	if (cl->c_fileread || cl->c_fileread_needed || cl->c_outstanding_loads)
		return;
	cl->c_ready_to_serve = 1;
	syslog(LOG_INFO, "class %d: all loads complete, ready to serve",
		cl->c_class);
}

E 13
I 4
static void
handle_zone_line(cl, cp)
	struct class *cl;
	register char *cp;
{
D 9
	char *domname, *filename, *arg3;
E 9
I 9
	char *domname, *filename, *arg3, *arg4;
E 9
	int remote = 0;
I 9
	u_long fromaddr = INADDR_NONE;
E 9

	while (isspace(*cp))
		cp++;
	if (!*cp) {
syntaxerr:	syslog(LOG_ERR, "%s: line %d: zone line syntax error, skipping",
			cl->c_filename, cl->c_fileread_lineno);
		return;
	}
	for (domname = cp; *cp && !isspace(*cp); cp++)
		;
	if (!*cp)
		goto syntaxerr;
	*cp++ = '\0';
	while (isspace(*cp))
		cp++;
	if (!*cp)
		goto syntaxerr;
	for (filename = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
	while (isspace(*cp))
		cp++;
D 10
	if (*cp) {
E 10
I 10
	if (*cp && *cp != '#') {
E 10
		for (arg3 = cp; *cp && !isspace(*cp); cp++)
			;
		if (*cp)
			*cp++ = '\0';
D 9
		if (!strcmp(arg3, "remote"))
E 9
I 9
		if (!strcmp(arg3, "from")) {
E 9
			remote = 1;
D 9
		else
E 9
I 9
			while (isspace(*cp))
				cp++;
			if (!*cp)
				goto syntaxerr;
			for (arg4 = cp; *cp && !isspace(*cp); cp++)
				;
			if (*cp)
				*cp++ = '\0';
			if (strcasecmp(arg4, "mname")) {
				fromaddr = inet_addr(arg4);
				if (fromaddr == INADDR_NONE)
					goto syntaxerr;
			}
		} else
E 9
			syslog(LOG_ERR,
		"%s: line %d: 3rd argument '%s' not understood and ignored",
				cl->c_filename, cl->c_fileread_lineno, arg3);
	}
D 5
	/* zone_add_request(cl, domname, filename, remote); */
E 5
I 5
D 9
	zone_add_request(cl, domname, filename, remote);
E 9
I 9
	zone_add_request(cl, domname, filename, remote, fromaddr);
E 9
E 5
}

static void
I 7
handle_nsanchor_line(cl, cp)
	struct class *cl;
	register char *cp;
{
	char *domname, *filename;

	while (isspace(*cp))
		cp++;
	if (!*cp) {
syntaxerr:	syslog(LOG_ERR,
			"%s: line %d: NS-anchor line syntax error, skipping",
			cl->c_filename, cl->c_fileread_lineno);
		return;
	}
	for (domname = cp; *cp && !isspace(*cp); cp++)
		;
	if (!*cp)
		goto syntaxerr;
	*cp++ = '\0';
	while (isspace(*cp))
		cp++;
	if (!*cp)
		goto syntaxerr;
	for (filename = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
	while (isspace(*cp))
		cp++;
D 10
	if (*cp)
E 10
I 10
	if (*cp && *cp != '#')
E 10
		goto syntaxerr;
	nsanchor_add_request(cl, domname, filename);
}

static void
E 7
process_classdef_line(cl, cp)
	struct class *cl;
	register char *cp;
{
	register char *np;

	while (isspace(*cp))
		cp++;
	if (!*cp || *cp == '#')
		return;
	if (!isalpha(*cp)) {
		syslog(LOG_ERR, "%s: line %d: unable to parse, skipping line",
			cl->c_filename, cl->c_fileread_lineno);
		return;
	}
	for (np = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
	if (!strcmp(np, "zone"))
		handle_zone_line(cl, cp);
I 7
	else if (!strcmp(np, "NS-anchor"))
		handle_nsanchor_line(cl, cp);
E 7
	else
		syslog(LOG_ERR,
			"%s: line %d: unknown keyword '%s', skipping line",
			cl->c_filename, cl->c_fileread_lineno, np);
}

E 4
void
classfile_read_handler(cl)
	register struct class *cl;
{
	char linebuf[FGETS_BUFSIZE];
	register FILE *f;

	f = cl->c_fileread;
	if (!fgets(linebuf, sizeof linebuf, f)) {
		FD_CLR(fileno(f), &select_for_read);
		fclose(f);
		cl->c_fileread = 0;
		class_fileread_inprogress = 0;
D 6
		if (debug)
			syslog(LOG_DEBUG,
E 6
I 6
		syslog(LOG_DEBUG,
E 6
			"finished reading def file for class %d: %d lines",
D 6
				cl->c_class, cl->c_fileread_lineno);
E 6
I 6
			cl->c_class, cl->c_fileread_lineno);
I 8
		if (cl->c_fileread_oldzones)
			delete_marked_zones(cl);
I 13
		class_ready_check(cl);
E 13
E 8
E 6
		return;
	}
	cl->c_fileread_lineno++;
D 4
	/* process_classdef_line(cl, linebuf); */
E 4
I 4
	process_classdef_line(cl, linebuf);
E 4
}

class_fileread_start(cl)
	register struct class *cl;
{
	register FILE *f;
	register int fd;

	cl->c_fileread_needed = 0;
	classes_needing_fileread--;
	f = fopen(cl->c_filename, "r");
	if (!f) {
		syslog(LOG_CRIT, "can't open def file %s for class %d: %m",
			cl->c_filename, cl->c_class);
		return(-1);
	}
	cl->c_fileread = f;
	cl->c_fileread_lineno = 0;
	fd = fileno(f);
	select_desc[fd].sel_read = classfile_read_handler;
	select_desc[fd].sel_opaque = (caddr_t) cl;
	FD_SET(fd, &select_for_read);
	if (fd > select_max_fd)
		select_max_fd = fd;
	class_fileread_inprogress = 1;
I 8
	if (cl->c_zonelist) {
		cl->c_fileread_oldzones = 1;
		mark_delcandidate_zones(cl);
	} else
		cl->c_fileread_oldzones = 0;
E 8
	return(0);
}

class_fileread_find()
{
	register struct class *cl;

	for (cl = class_list; cl; cl = cl->c_next)
		if (cl->c_fileread_needed)
			return(class_fileread_start(cl));
	syslog(LOG_CRIT, "BUG in class_fileread_find(): no class found");
	abort();
I 8
D 12
}

/*
 * We have two kinds of class reload: soft (normal) and hard.
 * Soft reload means simply re-reading the class definition file,
 * adding any new zones or NS-anchors, detecting changes to zone or
 * NS-anchor arguments, and deleting any zones which no longer appear
 * in the class definition file.  A soft reload is meant to be
 * non-disruptive: if a zone has changed, the old tree won't go away
 * until the new one is ready, no unnecessary discarding of unaffected
 * parts of the active domain data tree, existing zone structures
 * remain intact.
 *
 * Hard reload means first discarding all existing data for the class,
 * i.e., all zones and the entire active domain tree, then reloading
 * the class as if freshly on boot.  A hard reload is service-impacting.
 * To make it a little less inefficient, we do this trick: first make
 * all zones "forget" their active trees, then delete the zones themselves,
 * and finally discard the domain data tree from the root.
 */

class_reload_req(cl, hard)
	register struct class *cl;
{
	register struct zone *z;

	/* abort any previously-started fileread for fresh restart */
	if (cl->c_fileread) {
		FD_CLR(fileno(cl->c_fileread), &select_for_read);
		fclose(cl->c_fileread);
		cl->c_fileread = 0;
		class_fileread_inprogress = 0;
	}
	if (hard) {
		for (z = cl->c_zonelist; z; z = z->z_next_perclass)
			z->z_activetree = 0;
		while (z = cl->c_zonelist)
			delete_zone(z);
		if (cl->c_root) {
			free_subtree(cl->c_root);
			cl->c_root = 0;
			syslog(LOG_INFO, "class %d: cleared for hard reload",
				cl->c_class);
		}
	}
	cl->c_fileread_needed = 1;
	classes_needing_fileread++;
	syslog(LOG_INFO, "class %d scheduled for reload", cl->c_class);
}

void
cmd_reload_class(args)
	char *args;
{
	register char *cp, *arg1;
	int classnum, hard;
	register struct class *cl;

	for (cp = args; isspace(*cp); cp++)
		;
	if (!isalnum(*cp)) {
badusage:	syslog(LOG_ERR, "usage: reload-class {<num>|all} [hard]");
		return;
	}
	for (arg1 = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
	while (isspace(*cp))
		cp++;
	hard = (*cp == 'h');
	if (!strcmp(arg1, "all")) {
		for (cl = class_list; cl; cl = cl->c_next)
			class_reload_req(cl, hard);
		return;
	}
	if (!isdigit(*arg1))
		goto badusage;
	classnum = atoi(arg1);
	if (classnum >= 255)
		goto badusage;
	cl = class_array[classnum];
	if (!cl) {
		syslog(LOG_ERR, "reload-class: class %d not defined", classnum);
		return;
	}
	class_reload_req(cl, hard);
E 12
E 8
E 3
}
E 1
