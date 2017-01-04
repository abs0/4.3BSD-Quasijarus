h08253
s 00001/00000/00176
d D 5.10 04/03/02 17:49:28 msokolov 21 20
c redesign handling of VAXBI and peripheral nexus devices
e
s 00010/00005/00166
d D 5.9 88/06/18 13:43:03 bostic 20 19
c install approved copyright notice
e
s 00010/00004/00161
d D 5.8 88/04/29 13:43:33 bostic 19 18
c add Berkeley specific header; original conception by Michael Toy
e
s 00044/00012/00121
d D 5.7 88/04/26 13:31:07 bostic 18 17
c add getopt; create system directory if it doesn't already exist
e
s 00001/00000/00132
d D 5.6 87/11/12 10:52:52 bostic 17 16
c give main an exit(0); bug report 4.3BSD/etc/97
e
s 00001/00001/00131
d D 5.5 87/10/22 11:08:20 bostic 16 15
c ANSI C; sprintf now returns an int.
e
s 00012/00001/00120
d D 5.4 87/01/13 11:07:31 karels 15 14
c add symlink for "machine"
e
s 00003/00002/00118
d D 5.3 86/10/13 15:35:32 sam 14 13
c replace ancient sun support with tahoe support
e
s 00001/00000/00119
d D 5.2 86/01/11 20:36:43 lepreau 13 11
c symlink ../h -> sys so that genassym.c will work (cause cc -I. is done) and
c thus can build off independent /sys trees.
e
s 00001/00000/00119
d R 5.2 86/01/11 16:54:02 lepreau 12 11
c symlink(../h, sys) to make genassym.c work
e
s 00013/00001/00106
d D 5.1 85/05/08 11:57:30 dist 11 10
c Add copyright
e
s 00003/00001/00104
d D 1.10 83/08/11 22:54:08 sam 10 9
c standardize sccs keyword lines
e
s 00002/00000/00103
d D 1.9 83/05/18 00:19:46 sam 9 8
c dynamically create swap configuration files
e
s 00005/00001/00098
d D 1.8 82/12/09 21:33:46 sam 8 7
c somehow the -p option went away
e
s 00009/00008/00090
d D 1.7 82/10/25 00:58:56 root 7 6
c lint and cleanup
e
s 00068/00070/00030
d D 1.6 82/10/24 22:28:32 root 6 5
c from sun
e
s 00005/00001/00095
d D 1.5 82/10/11 12:08:52 sam 5 4
c -p option to create profiling kernel
e
s 00001/00000/00095
d D 1.4 81/03/09 16:48:38 toy 4 3
c Added reminder
e
s 00005/00003/00090
d D 1.3 81/02/26 01:44:52 wnj 3 2
c put away mikes stuff
e
s 00017/00000/00076
d D 1.2 81/02/25 22:27:50 toy 2 1
c Made prefix right.
e
s 00076/00000/00000
d D 1.1 81/02/24 15:51:22 toy 1 0
c date and time created 81/02/24 15:51:22 by toy
e
u
U
t
T
I 11
/*
 * Copyright (c) 1980 Regents of the University of California.
D 19
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 19
I 19
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 20
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 20
I 20
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 20
E 19
 */

E 11
I 1
D 6
/*
 * %M%	%I%	%E%
 * Config
 *	Do system configuration for VAX/UNIX
 *		1) Build system data structures
 *		2) Build makefile
 *		3) Create header files for devices
 *	Michael Toy -- Berkeley -- 1981
 */
E 6
I 6
D 10
/*	%M%	%I%	%E%	*/
E 10
I 10
#ifndef lint
I 11
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
D 19
#endif not lint
E 19
I 19
#endif /* not lint */
E 19

#ifndef lint
E 11
static char sccsid[] = "%W% (Berkeley) %G%";
D 11
#endif
E 11
I 11
D 19
#endif not lint
E 19
I 19
#endif /* not lint */
E 19
E 11
E 10
E 6

I 18
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
E 18
#include <stdio.h>
#include <ctype.h>
#include "y.tab.h"
#include "config.h"

I 18
static char *PREFIX;

E 18
I 6
/*
 * Config builds a set of files for building a UNIX
 * system given a description of the desired system.
 */
E 6
main(argc, argv)
D 6
int argc;
char **argv;
E 6
I 6
	int argc;
	char **argv;
E 6
{
I 5
D 6
    if (argc > 1 && strcmp(argv[1], "-p") == 0) {
	argv++, argc--;
	profiling++;
    }
E 5
    if (argc != 2)
    {
D 5
	fprintf(stderr, "usage: config <sysname>\n");
E 5
I 5
	fprintf(stderr, "usage: config [ -p ] <sysname>\n");
E 5
	exit(1);
    }
I 2
    PREFIX = argv[1];
E 2
    if (freopen(argv[1], "r", stdin) == NULL)
    {
	perror(argv[1]);
	exit(2);
    }
    dtab = NULL;
    if (yyparse())
	exit(3);
    else
    {
	ioconf();			/* Print ioconf.c */
	ubglue();			/* Create ubglue.s */
E 6
I 6

I 8
D 18
	if (argc > 1 && eq("-p", argv[1])) {
		profiling++;
		argc--, argv++;
	}
E 8
	if (argc != 2) {
D 8
		fprintf(stderr, "usage: config sysname\n");
E 8
I 8
		fprintf(stderr, "usage: config [ -p ] sysname\n");
E 18
I 18
	extern char *optarg;
	extern int optind;
	struct stat buf;
	int ch;
	char *p;

	while ((ch = getopt(argc, argv, "p")) != EOF)
		switch((char)ch) {
		case 'p':
			profiling++;
			break;
		case '?':
		default:
			goto usage;
		}
	argc -= optind;
	argv += optind;

	if (argc != 1) {
usage:		fputs("usage: config [-p] sysname\n", stderr);
E 18
E 8
		exit(1);
	}
D 18
	PREFIX = argv[1];
	if (freopen(argv[1], "r", stdin) == NULL) {
		perror(argv[1]);
E 18
I 18

	if (freopen(PREFIX = *argv, "r", stdin) == NULL) {
		perror(PREFIX);
E 18
		exit(2);
	}
I 18
	if (stat(p = path((char *)NULL), &buf)) {
		if (mkdir(p, 0755)) {
			perror(p);
			exit(2);
		}
	}
	else if ((buf.st_mode & S_IFMT) != S_IFDIR) {
		fprintf(stderr, "config: %s isn't a directory.\n", p);
		exit(2);
	}

E 18
	dtab = NULL;
I 9
	confp = &conf_list;
E 9
	if (yyparse())
		exit(3);
	switch (machine) {

	case MACHINE_VAX:
I 21
		vax_flatten_nexi();
E 21
		vax_ioconf();		/* Print ioconf.c */
		ubglue();		/* Create ubglue.s */
		break;

D 14
	case MACHINE_SUN:
		sun_ioconf();
E 14
I 14
	case MACHINE_TAHOE:
		tahoe_ioconf();
		vbglue();
E 14
		break;

	default:
		printf("Specify machine type, e.g. ``machine vax''\n");
		exit(1);
	}
I 13
D 15
	symlink("../h", path("sys"));	/* make genassym.c work */
E 15
I 15
	/*
	 * make symbolic links in compilation directory
	 * for "sys" (to make genassym.c work along with #include <sys/xxx>)
	 * and similarly for "machine".
	 */
	{
	char xxx[80];

D 18
	(void) symlink("../h", path("sys"));	
E 18
I 18
	(void) symlink("../h", path("sys"));
E 18
D 16
	sprintf(xxx, "../%s", machinename);
E 16
I 16
	(void) sprintf(xxx, "../%s", machinename);
E 16
	(void) symlink(xxx, path("machine"));
	}
E 15
E 13
E 6
	makefile();			/* build Makefile */
	headers();			/* make a lot of .h files */
I 9
	swapconf();			/* swap config files */
E 9
I 4
	printf("Don't forget to run \"make depend\"\n");
I 17
	exit(0);
E 17
E 4
D 6
    }
E 6
}

/*
 * get_word
 *	returns EOF on end of file
 *	NULL on end of line
 *	pointer to the word otherwise
 */
D 6

char *get_word(fp)
register FILE *fp;
E 6
I 6
char *
get_word(fp)
	register FILE *fp;
E 6
{
D 6
    static char line[80];
    register int ch;
    register char *cp;
E 6
I 6
	static char line[80];
	register int ch;
	register char *cp;
E 6

D 6
    while((ch = getc(fp)) != EOF)
	if (ch != ' ' && ch != '\t')
	    break;
    if (ch == EOF)
	return EOF;
    if (ch == '\n')
	return NULL;
    cp = line;
    *cp++ = ch;
    while((ch = getc(fp)) != EOF)
    {
	if (isspace(ch))
	    break;
E 6
I 6
	while ((ch = getc(fp)) != EOF)
		if (ch != ' ' && ch != '\t')
			break;
	if (ch == EOF)
D 7
		return (EOF);
E 7
I 7
		return ((char *)EOF);
E 7
	if (ch == '\n')
		return (NULL);
	cp = line;
E 6
	*cp++ = ch;
D 6
    }
    *cp = '\0';
    if (ch == EOF)
	return EOF;
    ungetc(ch, fp);
    return line;
E 6
I 6
	while ((ch = getc(fp)) != EOF) {
		if (isspace(ch))
			break;
		*cp++ = ch;
	}
	*cp = 0;
	if (ch == EOF)
D 7
		return (EOF);
	ungetc(ch, fp);
E 7
I 7
		return ((char *)EOF);
	(void) ungetc(ch, fp);
E 7
	return (line);
E 6
I 2
}

/*
D 6
 * path:
 *	Prepend the path to a filename
E 6
I 6
 * prepend the path to a filename
E 6
 */
I 7
char *
E 7
D 6

E 6
path(file)
D 6
char *file;
E 6
I 6
	char *file;
E 6
{
D 6
    register char *cp;
E 6
I 6
	register char *cp;
E 6

D 3
    cp = malloc(strlen(PREFIX)+strlen(file)+1);
    strcpy(cp, PREFIX);
    strcpy(cp, file);
E 3
I 3
D 6
    cp = malloc(strlen(PREFIX)+strlen(file)+5);
    strcpy(cp, "../");
    strcat(cp, PREFIX);
    strcat(cp, "/");
    strcat(cp, file);
E 3
    return cp;
E 6
I 6
D 7
	cp = malloc(strlen(PREFIX)+strlen(file)+5);
	strcpy(cp, "../");
	strcat(cp, PREFIX);
	strcat(cp, "/");
	strcat(cp, file);
E 7
I 7
	cp = malloc((unsigned)(strlen(PREFIX)+strlen(file)+5));
	(void) strcpy(cp, "../");
	(void) strcat(cp, PREFIX);
D 18
	(void) strcat(cp, "/");
	(void) strcat(cp, file);
E 18
I 18
	if (file) {
		(void) strcat(cp, "/");
		(void) strcat(cp, file);
	}
E 18
E 7
	return (cp);
E 6
E 2
}
E 1
