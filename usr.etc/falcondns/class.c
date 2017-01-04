/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * Class management functions
 */

#ifndef lint
static char sccsid[] = "@(#)class.c	1.13 (IFCTF) 2013/01/14";
#endif

#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <arpa/nameser.h>
#include <ctype.h>
#include <stdio.h>
#include <strings.h>
#include <syslog.h>
#include "defs.h"
#include "class.h"
#include "globals.h"
#include "selectloop.h"

extern char *myalloc();

register_class(classnum, classfile)
	char *classfile;
{
	register struct class *cl;
	register char *dp;

	if (classnum >= 255) {
		init_error(LOG_ERR,
			"class numbers greater than 254 aren't supported\n");
		return;
	}
	if (class_array[classnum]) {
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
	}
	dp = myalloc(sizeof(struct class) + strlen(classfile) + 1);
	if (!dp) {
		init_error(LOG_CRIT, "malloc failure registering class %d\n",
			classnum);
		return;
	}
	cl = (struct class *)dp;
	dp += sizeof(struct class);
	bzero(cl, sizeof(struct class));
	cl->c_class = classnum;
	strcpy(dp, classfile);
	cl->c_filename = dp;
	cl->c_fileread_needed = 1;
	class_array[classnum] = cl;
	classes_needing_fileread++;
	syslog(LOG_DEBUG, "registered class id %d using file %s",
		classnum, classfile);
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
	return(0);
}

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

static void
handle_zone_line(cl, cp)
	struct class *cl;
	register char *cp;
{
	char *domname, *filename, *arg3, *arg4;
	int remote = 0;
	u_long fromaddr = INADDR_NONE;

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
	if (*cp && *cp != '#') {
		for (arg3 = cp; *cp && !isspace(*cp); cp++)
			;
		if (*cp)
			*cp++ = '\0';
		if (!strcmp(arg3, "from")) {
			remote = 1;
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
			syslog(LOG_ERR,
		"%s: line %d: 3rd argument '%s' not understood and ignored",
				cl->c_filename, cl->c_fileread_lineno, arg3);
	}
	zone_add_request(cl, domname, filename, remote, fromaddr);
}

static void
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
	if (*cp && *cp != '#')
		goto syntaxerr;
	nsanchor_add_request(cl, domname, filename);
}

static void
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
	else if (!strcmp(np, "NS-anchor"))
		handle_nsanchor_line(cl, cp);
	else
		syslog(LOG_ERR,
			"%s: line %d: unknown keyword '%s', skipping line",
			cl->c_filename, cl->c_fileread_lineno, np);
}

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
		syslog(LOG_DEBUG,
			"finished reading def file for class %d: %d lines",
			cl->c_class, cl->c_fileread_lineno);
		if (cl->c_fileread_oldzones)
			delete_marked_zones(cl);
		class_ready_check(cl);
		return;
	}
	cl->c_fileread_lineno++;
	process_classdef_line(cl, linebuf);
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
	if (cl->c_zonelist) {
		cl->c_fileread_oldzones = 1;
		mark_delcandidate_zones(cl);
	} else
		cl->c_fileread_oldzones = 0;
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
}
