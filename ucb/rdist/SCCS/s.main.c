h26472
s 00010/00005/00270
d D 5.3 88/06/29 20:19:36 bostic 20 19
c install approved copyright notice
e
s 00010/00004/00265
d D 5.2 88/02/01 11:34:50 bostic 19 18
c add new Berkeley headers
e
s 00014/00002/00255
d D 5.1 85/06/06 08:52:10 dist 18 17
c Add copyright
e
s 00011/00004/00246
d D 4.15 85/05/16 17:21:57 bloom 17 16
c check for Distfile if distfile doesn't exist
e
s 00019/00003/00231
d D 4.14 85/02/04 14:31:21 ralph 16 15
c added -m option to update listed hosts only.
e
s 00003/00002/00231
d D 4.13 84/12/06 14:59:22 ralph 15 13
c added FILE variable for special commands, allow symbolic links to non-existing file
e
s 00008/00002/00231
d R 4.13 84/09/21 09:23:44 ralph 14 13
c fix security hole
e
s 00010/00002/00223
d D 4.12 84/06/28 11:45:12 ralph 13 12
c handle symbolic and hard links.
e
s 00001/00003/00224
d D 4.11 84/04/09 15:59:06 ralph 12 10
c added labels for partial updates.
e
s 00000/00002/00225
d R 4.11 84/04/06 15:48:45 ralph 11 10
c added labels for partial updates.
e
s 00037/00058/00190
d D 4.10 84/02/09 16:07:01 ralph 10 9
c read entire distfile and sort entries by host.
e
s 00012/00008/00236
d D 4.9 83/11/29 16:00:41 ralph 9 8
c bug fixes and added `special' command.
e
s 00003/00001/00241
d D 4.8 83/11/01 14:29:39 ralph 8 7
c fixes for -r and -w.
e
s 00006/00002/00236
d D 4.7 83/10/26 11:42:42 ralph 7 6
c added -b option for binary compare. Fixed -r w/ except.
e
s 00004/00000/00234
d D 4.6 83/10/20 12:15:05 ralph 6 5
c added -r option to remove extra files.
e
s 00085/00012/00149
d D 4.5 83/10/12 16:39:05 ralph 5 4
c fixed install flags, file comparisons, mail addresses, added -c.
e
s 00006/00084/00155
d D 4.4 83/10/10 16:21:02 ralph 4 3
c took out update feature. Too many rcp's as it is.
e
s 00001/00001/00238
d D 4.3 83/10/10 16:16:12 ralph 3 2
c stable version that works.
e
s 00101/00015/00138
d D 4.2 83/09/27 14:38:59 ralph 2 1
c First stable version.
e
s 00153/00000/00000
d D 4.1 83/09/07 13:20:12 ralph 1 0
c date and time created 83/09/07 13:20:12 by ralph
e
u
U
t
T
I 18
/*
 * Copyright (c) 1983 Regents of the University of California.
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

E 18
I 1
#ifndef lint
D 18
static	char *sccsid = "%W% (Berkeley) %E%";
#endif
E 18
I 18
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
D 19
#endif not lint
E 19
I 19
#endif /* not lint */
E 19

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 19
#endif not lint
E 19
I 19
#endif /* not lint */
E 19
E 18

#include "defs.h"

I 16
#define NHOSTS 100

E 16
/*
 * Remote distribution program.
 */

D 17
char	*distfile = "distfile";
E 17
I 17
char	*distfile = NULL;
E 17
D 2
char	*tmpfile = "/tmp/rdistXXXXXX";
E 2
I 2
D 9
char	tmpfile[] = "/tmp/rdistAXXXXXX";
E 9
I 9
char	tmpfile[] = "/tmp/rdistXXXXXX";
E 9
char	*tmpname = &tmpfile[5];
D 9
char	*tmpinc = &tmpfile[10];
E 9
E 2

int	debug;		/* debugging flag */
int	nflag;		/* NOP flag, just print commands without executing */
int	qflag;		/* Quiet. Don't print messages */
D 5
int	vflag;		/* verify only */
int	yflag;		/* update iff remote younger than master */
E 5
I 5
int	options;	/* global options */
E 5
int	iamremote;	/* act as remote server for transfering files */

D 12
int	filec;		/* number of files to update */
char	**filev;	/* list of files/directories to update */
E 12
FILE	*fin = NULL;	/* input file pointer */
D 10
int	rem = 0;	/* file descriptor to remote source/sink process */
E 10
I 10
int	rem = -1;	/* file descriptor to remote source/sink process */
E 10
char	host[32];	/* host name */
D 10
int	errs;		/* number of errors while sending/receiving */
E 10
I 10
int	nerrs;		/* number of errors while sending/receiving */
E 10
char	user[10];	/* user's name */
char	homedir[128];	/* user's home directory */
int	userid;		/* user's user ID */
D 2
int	usergid;	/* user's group ID */
E 2
I 2
int	groupid;	/* user's group ID */
D 4
int	iamupdate;
E 4
E 2

I 8
struct	passwd *pw;	/* pointer to static area used by getpwent */
struct	group *gr;	/* pointer to static area used by getgrent */

E 8
D 10
int	cleanup();
int	lostconn();

E 10
main(argc, argv)
	int argc;
	char *argv[];
{
	register char *arg;
D 8
	register struct	passwd *pw;
E 8
I 5
	int cmdargs = 0;
I 16
	char *dhosts[NHOSTS], **hp = dhosts;
E 16
E 5

D 2
	setpwent();
E 2
I 2
D 4
	arg = rindex(argv[0], '/');
	if (arg == NULL)
		arg = argv[0];
	else
		arg++;
	if (!strcmp(arg, "update"))
		iamupdate++;

E 4
E 2
	pw = getpwuid(userid = getuid());
D 2
	endpwent();
E 2
	if (pw == NULL) {
D 2
		fprintf(stderr, "rdist: Who are you?\n");
E 2
I 2
		fprintf(stderr, "%s: Who are you?\n", argv[0]);
E 2
		exit(1);
	}
	strcpy(user, pw->pw_name);
	strcpy(homedir, pw->pw_dir);
D 2
	usergid = pw->pw_gid;
E 2
I 2
	groupid = pw->pw_gid;
E 2
	gethostname(host, sizeof(host));

	while (--argc > 0) {
		if ((arg = *++argv)[0] != '-')
			break;
		if (!strcmp(arg, "-Server"))
			iamremote++;
		else while (*++arg)
			switch (*arg) {
			case 'f':
				if (--argc <= 0)
					usage();
				distfile = *++argv;
				if (distfile[0] == '-' && distfile[1] == '\0')
					fin = stdin;
				break;

I 16
			case 'm':
				if (--argc <= 0)
					usage();
				if (hp >= &dhosts[NHOSTS-2]) {
					fprintf(stderr, "rdist: too many destination hosts\n");
					exit(1);
				}
				*hp++ = *++argv;
				break;

E 16
			case 'd':
I 2
				if (--argc <= 0)
					usage();
				define(*++argv);
				break;

			case 'D':
E 2
				debug++;
				break;

I 5
			case 'c':
				cmdargs++;
				break;

E 5
			case 'n':
I 9
				if (options & VERIFY) {
					printf("rdist: -n overrides -v\n");
					options &= ~VERIFY;
				}
E 9
				nflag++;
				break;

			case 'q':
				qflag++;
				break;

I 7
			case 'b':
				options |= COMPARE;
				break;

E 7
I 6
D 9
			case 'r':
E 9
I 9
			case 'R':
E 9
				options |= REMOVE;
				break;

E 6
			case 'v':
I 9
				if (nflag) {
					printf("rdist: -n overrides -v\n");
					break;
				}
E 9
D 5
				vflag++;
E 5
I 5
				options |= VERIFY;
E 5
				break;

I 5
			case 'w':
				options |= WHOLE;
				break;

E 5
			case 'y':
D 5
				yflag++;
E 5
I 5
				options |= YOUNGER;
E 5
				break;

I 13
			case 'h':
				options |= FOLLOW;
				break;

			case 'i':
				options |= IGNLNKS;
				break;

E 13
			default:
				usage();
			}
	}
I 16
	*hp = NULL;
E 16
I 2

I 15
	setreuid(0, userid);
E 15
	mktemp(tmpfile);
E 2
D 10
	signal(SIGPIPE, lostconn);
E 10
I 10

E 10
	if (iamremote) {
		server();
D 10
		exit(errs);
E 10
I 10
D 15
		exit(nerrs);
E 15
I 15
		exit(nerrs != 0);
E 15
E 10
	}
D 2
	filec = argc;
	filev = argv;
E 2

D 2
	if (fin == NULL && (fin = fopen(distfile, "r")) == NULL) {
		perror(distfile);
		exit(1);
	}
	mktemp(tmpfile);
E 2
D 10
	signal(SIGHUP, cleanup);
	signal(SIGINT, cleanup);
	signal(SIGQUIT, cleanup);
	signal(SIGTERM, cleanup);

E 10
D 2
	yyparse();
E 2
I 2
D 4
	if (iamupdate)
		doupdate(argc, argv);
	else {
		filec = argc;
		filev = argv;
		if (fin == NULL && (fin = fopen(distfile, "r")) == NULL) {
			perror(distfile);
			exit(1);
		}
		yyparse();
E 4
I 4
D 5
	filec = argc;
	filev = argv;
	if (fin == NULL && (fin = fopen(distfile, "r")) == NULL) {
		perror(distfile);
		exit(1);
E 5
I 5
	if (cmdargs)
		docmdargs(argc, argv);
	else {
D 10
		filec = argc;
		filev = argv;
E 10
D 17
		if (fin == NULL && (fin = fopen(distfile, "r")) == NULL) {
			perror(distfile);
			exit(1);
E 17
I 17
		if (fin == NULL) {
			if(distfile == NULL) {
				if((fin = fopen("distfile","r")) == NULL)
					fin = fopen("Distfile", "r");
			} else
				fin = fopen(distfile, "r");
			if(fin == NULL) {
				perror(distfile ? distfile : "distfile");
				exit(1);
			}
E 17
		}
		yyparse();
I 10
		if (nerrs == 0)
D 16
			docmds(argc, argv);
E 16
I 16
			docmds(dhosts, argc, argv);
E 16
E 10
E 5
E 4
	}
I 4
D 5
	yyparse();
E 5
E 4

E 2
D 10
	exit(errs);
E 10
I 10
D 15
	exit(nerrs);
E 15
I 15
	exit(nerrs != 0);
E 15
E 10
}

usage()
{
D 2
	printf("Usage: rdist [-f distfile] [-n] [-q] [-y] [-d] [file ...]\n");
E 2
I 2
D 5
	printf("Usage: rdist [-f distfile] [-d var=value] [-nqyD] [file ...]\n");
E 5
I 5
D 7
	printf("Usage: rdist [-nqvwyD] [-f distfile] [-d var=value] [file ...]\n");
	printf("or: rdist [-nqvwyD] -c source [...] machine[:dest]\n");
E 7
I 7
D 13
	printf("Usage: rdist [-nqbrvwyD] [-f distfile] [-d var=value] [file ...]\n");
	printf("or: rdist [-nqbrvwyD] -c source [...] machine[:dest]\n");
E 13
I 13
D 16
	printf("Usage: rdist [-nqbhirvwyD] [-f distfile] [-d var=value] [file ...]\n");
E 16
I 16
	printf("Usage: rdist [-nqbhirvwyD] [-f distfile] [-d var=value] [-m host] [file ...]\n");
E 16
	printf("or: rdist [-nqbhirvwyD] -c source [...] machine[:dest]\n");
E 13
E 7
E 5
D 4
	exit(1);
}

/*
 * rcp like interface for distributing files.
 */
doupdate(nargs, args)
	int nargs;
	char *args[];
{
	struct block *bp, *files, *hosts, *cmds, *prev;
D 3
	int i, firsttime = 1;
E 3
I 3
	int i;
E 3
	char *pos, dest[BUFSIZ];

	if (nargs < 2)
		upusage();

	prev = NULL;
	bp = files = ALLOC(block);
	for (i = 0; i < nargs - 1; bp = ALLOC(block), i++) {
		bp->b_type = NAME;
		bp->b_name = args[i];
		if (prev != NULL)
			prev->b_next = bp;
		bp->b_next = bp->b_args = NULL;
		prev = bp;
	}

	hosts = ALLOC(block);
	hosts->b_type = NAME;
	hosts->b_name = args[i];
	hosts->b_name = args[i];
	hosts->b_next = hosts->b_args = NULL;
	if ((pos = index(hosts->b_name, ':')) != NULL) {
		*pos++ = '\0';
		strcpy(dest, pos);
	} else
		dest[0] = '\0';

	hosts = expand(hosts, 0);

	if (dest[0] == '\0')
		cmds = NULL;
	else {
		cmds = ALLOC(block);
		if (vflag)
			cmds->b_type = VERIFY;
		else
			cmds->b_type = INSTALL;
		cmds->b_name = dest;
		cmds->b_next = cmds->b_args = NULL;
	}

	if (debug) {
		printf("doupdate()\nfiles = ");
		prnames(files);
		printf("hosts = ");
		prnames(hosts);
	}
	dohcmds(files, hosts, cmds);
}

upusage()
{
	printf("Usage: update [-nqyD] source [...] machine[:dest]\n");
E 4
E 2
	exit(1);
}

/*
I 5
 * rcp like interface for distributing files.
 */
docmdargs(nargs, args)
	int nargs;
	char *args[];
{
D 10
	struct block *bp, *files, *hosts, *cmds, *prev;
E 10
I 10
	register struct namelist *nl, *prev;
	register char *cp;
	struct namelist *files, *hosts;
	struct subcmd *cmds;
	char *dest;
	static struct namelist tnl = { NULL, NULL };
E 10
	int i;
D 10
	char *pos, dest[BUFSIZ];
E 10

	if (nargs < 2)
		usage();

	prev = NULL;
D 10
	bp = files = ALLOC(block);
	for (i = 0; i < nargs - 1; bp = ALLOC(block), i++) {
		bp->b_type = NAME;
		bp->b_name = args[i];
		if (prev != NULL)
			prev->b_next = bp;
		bp->b_next = bp->b_args = NULL;
		prev = bp;
E 10
I 10
	for (i = 0; i < nargs - 1; i++) {
		nl = makenl(args[i]);
		if (prev == NULL)
			files = prev = nl;
		else {
			prev->n_next = nl;
			prev = nl;
		}
E 10
	}

D 10
	hosts = ALLOC(block);
	hosts->b_type = NAME;
	hosts->b_name = args[i];
	hosts->b_name = args[i];
	hosts->b_next = hosts->b_args = NULL;
	if ((pos = index(hosts->b_name, ':')) != NULL) {
		*pos++ = '\0';
		strcpy(dest, pos);
	} else
		dest[0] = '\0';
E 10
I 10
	cp = args[i];
	if ((dest = index(cp, ':')) != NULL)
		*dest++ = '\0';
	tnl.n_name = cp;
	hosts = expand(&tnl, E_ALL);
I 16
	if (nerrs)
		exit(1);
E 16
E 10

D 9
	hosts = expand(hosts, 0);
E 9
I 9
D 10
	hosts = expand(hosts, 1);
E 9

	if (dest[0] == '\0')
E 10
I 10
	if (dest == NULL || *dest == '\0')
E 10
		cmds = NULL;
	else {
D 10
		cmds = ALLOC(block);
		cmds->b_type = INSTALL;
		cmds->b_options = options;
		cmds->b_name = dest;
		cmds->b_next = cmds->b_args = NULL;
E 10
I 10
		cmds = makesubcmd(INSTALL);
		cmds->sc_options = options;
		cmds->sc_name = dest;
E 10
	}

	if (debug) {
		printf("docmdargs()\nfiles = ");
		prnames(files);
		printf("hosts = ");
		prnames(hosts);
	}
D 10
	dohcmds(files, hosts, cmds);
E 10
I 10
D 12
	insert(files, hosts, cmds);
E 12
I 12
	insert(NULL, files, hosts, cmds);
E 12
D 16
	docmds(0, NULL);
E 16
I 16
	docmds(NULL, 0, NULL);
E 16
E 10
}

/*
E 5
D 10
 * Remove temporary files and do any cleanup operations before exiting.
 */
cleanup()
{
D 5
	(void) unlink(tmpfile);
E 5
I 5
D 9
	do {
		(void) unlink(tmpfile);
		(*tmpinc)--;
	} while (*tmpinc >= 'A');
E 9
I 9
	(void) unlink(tmpfile);
E 9
E 5
	exit(1);
}

/*
E 10
 * Print a list of NAME blocks (mostly for debugging).
 */
D 10
prnames(bp)
	register struct block *bp;
E 10
I 10
prnames(nl)
	register struct namelist *nl;
E 10
{
	printf("( ");
D 10
	while (bp != NULL) {
		printf("%s ", bp->b_name);
		bp = bp->b_next;
E 10
I 10
	while (nl != NULL) {
		printf("%s ", nl->n_name);
		nl = nl->n_next;
E 10
	}
	printf(")\n");
}

/*VARARGS*/
warn(fmt, a1, a2,a3)
	char *fmt;
{
	extern int yylineno;

	fprintf(stderr, "rdist: line %d: Warning: ", yylineno);
	fprintf(stderr, fmt, a1, a2, a3);
	fputc('\n', stderr);
}
E 1
