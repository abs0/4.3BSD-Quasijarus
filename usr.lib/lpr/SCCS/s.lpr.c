h34005
s 00012/00000/00690
d D 5.5 04/09/03 19:01:50 msokolov 37 36
c lpr -O mechanism for specifying processing options for advanced printers
e
s 00010/00005/00680
d D 5.4 88/06/30 17:59:58 bostic 36 35
c install approved copyright notice
e
s 00010/00004/00675
d D 5.3 88/05/05 18:08:09 bostic 35 34
c written by Ralph Campbell; add Berkeley specific header
e
s 00002/00000/00677
d D 5.2 85/11/17 15:53:34 eric 34 33
c clean up logging
e
s 00013/00001/00664
d D 5.1 85/06/06 10:04:47 dist 33 32
c Add copyright
e
s 00010/00008/00655
d D 4.29 85/02/14 09:05:00 ralph 32 31
c check real gid as well as members in /etc/group
e
s 00018/00000/00645
d D 4.28 85/02/01 16:33:42 miriam 31 30
c Put in restricted group access.
e
s 00008/00002/00637
d D 4.27 84/12/05 14:09:41 ralph 30 29
c close -s (symbolic links) security bug.
e
s 00008/00001/00631
d D 4.26 83/09/15 16:39:58 ralph 29 28
c added error messages for zero length files.
e
s 00008/00000/00624
d D 4.25 83/07/27 09:25:17 ralph 28 27
c fix ownership of cf and df files so users can read df files
e
s 00004/00001/00620
d D 4.24 83/07/17 00:11:26 sam 27 26
c put sccs id's to some use
e
s 00041/00012/00580
d D 4.23 83/06/29 17:09:09 ralph 26 25
c changed to use unix domain ipc.
e
s 00002/00002/00590
d D 4.22 83/06/22 09:31:30 ralph 25 24
c added -n option to print ditroff files.
e
s 00038/00029/00554
d D 4.21 83/06/17 15:10:51 ralph 24 23
c added multiple copy control by printcap
e
s 00004/00004/00579
d D 4.20 83/06/15 14:57:18 sam 23 22
c open and flock defines changed
e
s 00002/00002/00581
d D 4.19 83/06/02 12:27:40 ralph 22 20
c made local variables static to improve separation between functions.
e
s 00001/00001/00582
d R 4.19 83/06/02 12:23:23 ralph 21 20
c made local variables static to improve separation between functions.
e
s 00007/00002/00576
d D 4.18 83/05/26 09:18:28 ralph 20 19
c fixed -P option so -Pprinter and -P printer both work.
e
s 00000/00001/00578
d D 4.17 83/05/18 16:45:16 ralph 19 18
c fixed lprm segmentation fault when remote is down.
e
s 00032/00026/00547
d D 4.16 83/05/13 11:52:41 ralph 18 17
c bug fixes and changes for lpc command.
e
s 00053/00102/00520
d D 4.15 83/04/29 11:51:53 ralph 17 16
c changes for new printer daemon.
e
s 00003/00003/00619
d D 4.14 83/04/05 14:53:12 ralph 16 15
c fixed exit codes
e
s 00011/00013/00611
d D 4.13 83/03/29 13:13:26 ralph 15 14
c modified to allow unlimited size copy files.
e
s 00001/00001/00623
d D 4.12 83/03/17 15:59:31 ralph 14 13
c changed messages to include printer name
e
s 00029/00004/00595
d D 4.11 83/03/11 15:31:18 ralph 13 12
c fixes q order problems and temporary file names when inchar > 'z'.
e
s 00001/00001/00598
d D 4.10 83/03/09 10:37:18 ralph 12 11
c fix for when getlogin returns an empty string.
e
s 00041/00046/00558
d D 4.9 83/03/07 10:46:23 ralph 11 9
c fixed several bugs.
e
s 00040/00045/00559
d R 4.9 83/03/01 11:22:53 ralph 10 9
c fixed several bugs.
e
s 00086/00059/00518
d D 4.8 83/02/11 14:42:57 ralph 9 7
c bugs fixed and vpr options merged into lpr.
e
s 00086/00059/00518
d R 4.8 83/02/10 17:08:15 ralph 8 7
c bugs fixed and vpr options merged into lpr.
e
s 00020/00023/00557
d D 4.7 83/01/07 16:09:56 ralph 7 6
c added status file to spooldir and other improvements.
e
s 00004/00004/00576
d D 4.6 83/01/05 13:43:21 root 6 5
c changed -c to -l so default is copy instead of linking
e
s 00268/00208/00312
d D 4.5 83/01/05 11:27:00 root 5 4
c Working version of remote spooling.
e
s 00059/00053/00461
d D 4.4 82/12/02 11:59:08 ralph 4 3
c Updated directory scanning and sorting for new dir.h
e
s 00001/00001/00513
d D 4.3 81/05/19 09:46:08 sam 3 2
c -P option bug finally fixed
e
s 00001/00001/00513
d D 4.2 81/05/12 16:09:29 sam 2 1
c bug on -P option
e
s 00514/00000/00000
d D 4.1 81/05/09 16:34:14 root 1 0
c date and time created 81/05/09 16:34:14 by root
e
u
U
t
/*
 *
 *      1.1 mike  5/77 - all files copied to spooler space
 *    	(see note below)
 *
 *      1.2 dlm 26 Sep 1977
 *      fix for allowing variable indents (-i flag)
 *
 *      1.3 dlm/njl 12 Dec 1977
 *      fix for open pipe when spawning progess (affects lpd)
 *
 *      1.4 dlm 24 Feb 1978
 *      test for data files; add -C option for classification
 *      and change format of $L card; reversed 1.1 on copies
 *
 *      1.5 dlm 27 Mar 1978
 *      add job name and -h option
 *
 *	2.0 was 21 Dec 1978
 *	-h option changed to -J
 *	added -H option to cause header page to be
 *	  printed, default is no header page
 *	added -p option to cause files to be printed
 *	  using pr
 *	default for classification changed
 *
 *	2.1 was 14 Mar 1979
 *	multiple printer logic changed,
 *	printer number sent to daemon.
 *
 *	3.0 sjl 6 May 1980
 *	Mods for Version 7, plus portability
 *	(in preparation for UNIX/24V)
 *
 *	3.1 sjl Oct 28 1980
 *	Mods for protected spooling area, see note below
 *
 *	3.2 sjl Mar 13 1981
 *	Add N card for file names to help out sq
 *
 *	3.3 sjl	Mar 27 1981 from decvax!shannon
 *	Mods and cleanup for 4bsd.
 *	Send mail option added.
 *
 *	4.0 sjl Mar 28 1981
 *	Support multiple printers and daemons through termcap-like
 *	  data base
 *
 *	4.1 sjl	Apr 28 1981
 *	Check for printer being down (mode 0 on device)
 *
 *	4.2 was May 1 1981
 *	Clean up handling of printcap database, add more defaults
 */

char lpr_id[] = "~|^`lpr.c:\t4.2\t1 May 1981\n";

T
I 33
/*
 * Copyright (c) 1983 Regents of the University of California.
D 35
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 35
I 35
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 36
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 36
I 36
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
E 36
E 35
 */

E 33
I 1
D 20
/*	%M%	%I%	%E%	*/
E 20
I 20
D 22
/*	lpr.c	4.17	83/05/18	*/
E 22
I 22
D 27
/*	%M%	%I%	%E%	*/
E 27
I 27
#ifndef lint
I 33
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
D 35
#endif not lint
E 35
I 35
#endif /* not lint */
E 35

#ifndef lint
E 33
static char sccsid[] = "%W% (Berkeley) %G%";
D 33
#endif
E 33
I 33
D 35
#endif not lint
E 35
I 35
#endif /* not lint */
E 35
E 33

E 27
E 22
E 20
/*
 *      lpr -- off line print
D 9
 *              also known as print
E 9
I 5
 *
 * Allows multiple printers and printers on remote machines by
 * using information from a printer data base.
E 5
 */

D 17
#include <sys/types.h>
#include <sys/stat.h>
I 5
#include <sys/file.h>
E 5
#include <signal.h>
#include <pwd.h>
#include <stdio.h>
#include <ctype.h>
#include "lp.local.h"
E 17
I 17
D 26
#include "lp.h"
E 26
I 26
#include <stdio.h>
#include <sys/types.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <pwd.h>
I 31
#include <grp.h>
E 31
#include <signal.h>
#include <ctype.h>
I 34
#include <syslog.h>
E 34
#include "lp.local.h"
E 26
E 17

D 5
/*
 * Multiple printer scheme using info from printer data base:
 *
 *	DN		who to invoke to print stuff
D 4
 *	SA		rectory used as spool queue
E 4
I 4
 *	SA		directory used as spool queue
E 4
 *
 * daemon identifies what printer it should use (in the case of the
 *  same code being shared) by inspecting its argv[1].
 */
char    *tfname;		/* tmp copy of df before linking */
char    *cfname;		/* copy files */
char    *lfname;		/* linked files */
char    *dfname;		/* daemon files, linked from tf's */
E 5
I 5
char    *tfname;		/* tmp copy of cf before linking */
char    *cfname;		/* daemon control files, linked from tf's */
char    *dfname;		/* data files */
E 5

int	nact;			/* number of jobs to act on */
D 5
int	tff;			/* daemon file descriptor */
E 5
I 5
int	tfd;			/* control file descriptor */
E 5
int     mailflg;		/* send mail */
D 5
int	jflag;			/* job name specified */
int	qflg;			/* q job, but don't exec daemon */
E 5
I 5
int	qflag;			/* q job, but don't exec daemon */
E 5
D 9
int	prflag;			/* ``pr'' files */
E 9
I 9
char	format = 'f';		/* format char for printing files */
E 9
I 5
int	rflag;			/* remove files upon completion */	
D 6
int	cflag;			/* force copy */
E 6
I 6
D 17
int	lflag;			/* link flag */
E 6
E 5
char	*person;		/* user name */
E 17
I 17
int	sflag;			/* symbolic link flag */
E 17
int	inchar;			/* location to increment char in file names */
int     ncopies = 1;		/* # of copies to make */
int	iflag;			/* indentation wanted */
int	indent;			/* amount to indent */
D 5
char	*daemname;		/* path name to daemon program */
char	*DN;			/* daemon name */
char	*SA;			/* spooling area */
char	*LP;			/* line printer device */
E 5
I 5
D 17
char	*DN;			/* path name to daemon program */
char	*LP;			/* line printer device name */
char	*RM;			/* remote machine name if no local printer */
char	*SD;			/* spool directory */
E 5
int     MX;			/* maximum size in blocks of a print file */
E 17
D 5
int	hdr = 1;		/* 1 =>'s default header */
E 5
I 5
int	hdr = 1;		/* print header or not (default is yes) */
E 5
D 9
int     user;			/* user id */
E 9
I 9
int     userid;			/* user id */
I 17
char	*person;		/* user name */
E 17
E 9
D 5
int	spgroup;		/* daemon's group for creating spool files */
E 5
char	*title;			/* pr'ing title */
I 9
char	*fonts[4];		/* troff font names */
char	*width;			/* width for versatec printing */
I 26
char	host[32];		/* host name */
E 26
E 9
D 4
char	*class = SYSTEM_NAME;	/* class title on header page */
E 4
I 4
D 5
char	classbuf[32];		/* class title on header page */
char	*class = classbuf;
E 5
I 5
D 17
char	host[32];		/* host name */
E 17
char	*class = host;		/* class title on header page */
E 5
E 4
char    *jobname;		/* job name on header page */
I 37
char	*options;		/* processing options for advanced printers */
E 37
I 26
char	*name;			/* program name */
char	*printer;		/* printer name */
D 30
char	buf[BUFSIZ];
E 30
I 30
struct	stat statb;
E 30
E 26
D 17
char	*name;			/* program name */
E 17
D 5
char	*printer;		/* printer name */
E 5

I 26
int	MX;			/* maximum number of blocks to copy */
int	MC;			/* maximum number of copies allowed */
I 28
int	DU;			/* daemon user-id */
E 28
char	*SD;			/* spool directory */
char	*LO;			/* lock file name */
I 31
char	*RG;			/* restrict group */
E 31
short	SC;			/* suppress multiple copies */

char	*getenv();
char	*rindex();
E 26
D 17
char	*pgetstr();
D 5
char	*mktmp();
E 5
char	*malloc();
char	*getenv();
char	*rindex();
E 17
I 11
char	*linked();
I 17
int	cleanup();
E 17
E 11

I 4
D 5
/* ARGSUSED */
E 5
I 5
/*ARGSUSED*/
E 5
E 4
main(argc, argv)
D 4
int argc;
char *argv[];
E 4
I 4
	int argc;
	char *argv[];
E 4
{
I 9
D 17
	extern char *getlogin();
	extern struct passwd *getpwuid(), *getpwnam();
E 17
I 17
	extern struct passwd *getpwuid();
E 17
	struct passwd *pw;
I 31
	struct group *gptr;
E 31
	extern char *itoa();
E 9
D 11
	register char *arg;
E 11
I 11
	register char *arg, *cp;
I 30
	char buf[BUFSIZ];
E 30
E 11
D 5
	int i, c, f, flag, out();
	char *sp;
	struct stat sbuf;
E 5
I 5
D 17
	int i, f, out();
	char *printer = NULL;
E 17
I 17
	int i, f;
E 17
	struct stat stb;
E 5

D 17
	/*
	 * Strategy to maintain protected spooling area:
	 *	1. Spooling area is writable only by daemon and spooling group
	 *	2. lpr runs setuid root and setgrp spooling group; it uses
	 *	   root to access any file it wants (verifying things before
	 *	   with an access call) and group id to know how it should
	 *	   set up ownership of files in spooling area.
D 5
	 *	3. Files in spooling area are owned by printer and spooling
E 5
I 5
	 *	3. Files in spooling area are owned by daemon and spooling
E 5
	 *	   group, with mode 660.
D 5
	 *	4. lpd runs setuid daemon and setgrp spooling group to
E 5
I 5
	 *	4. lpd runs setuid root and setgrp spooling group to
E 5
	 *	   access files and printer.  Users can't get to anything
D 5
	 *	   w/o help of sq and dq programs.
E 5
I 5
	 *	   w/o help of lpq and lprm programs.
E 5
	 */
E 17
I 4
D 5
	gethostname(classbuf, sizeof (classbuf));
E 4
	user = getuid();
	spgroup = getegid();
E 5
D 4
	if(signal(SIGHUP, SIG_IGN) != SIG_IGN)
E 4
I 4
	if (signal(SIGHUP, SIG_IGN) != SIG_IGN)
E 4
D 17
		signal(SIGHUP, out);
E 17
I 17
		signal(SIGHUP, cleanup);
E 17
D 4
	if(signal(SIGINT, SIG_IGN) != SIG_IGN)
E 4
I 4
	if (signal(SIGINT, SIG_IGN) != SIG_IGN)
E 4
D 17
		signal(SIGINT, out);
E 17
I 17
		signal(SIGINT, cleanup);
E 17
D 4
	if(signal(SIGQUIT, SIG_IGN) != SIG_IGN)
E 4
I 4
	if (signal(SIGQUIT, SIG_IGN) != SIG_IGN)
E 4
D 17
		signal(SIGQUIT, out);
E 17
I 17
		signal(SIGQUIT, cleanup);
E 17
D 4
	if(signal(SIGTERM, SIG_IGN) != SIG_IGN)
E 4
I 4
	if (signal(SIGTERM, SIG_IGN) != SIG_IGN)
E 4
D 17
		signal(SIGTERM, out);
E 17
I 17
		signal(SIGTERM, cleanup);
E 17
D 5
	flag = 0;
	if ((printer = getenv("PRINTER")) == NULL)
		printer = DEFLP;
E 5
I 5

D 18
	gethostname(host, sizeof (host));
E 18
D 9
	user = getuid();
E 9
E 5
	name = argv[0];
I 18
	gethostname(host, sizeof (host));
I 34
	openlog("lpd", 0, LOG_LPR);
E 34
E 18

D 5
	while (argc>1 && (arg = argv[1])[0]=='-') {
E 5
I 5
D 17
	while (argc > 1 && (arg = argv[1])[0] == '-') {
E 17
I 17
	while (argc > 1 && argv[1][0] == '-') {
E 17
		argc--;
D 17
		argv++;
E 17
I 17
		arg = *++argv;
E 17
E 5
		switch (arg[1]) {

D 5
		case 'c':		/* force copy of files */
			flag = '+';
E 5
I 5
		case 'P':		/* specifiy printer name */
D 20
			printer = &arg[2];
E 20
I 20
			if (arg[2])
				printer = &arg[2];
			else if (argc > 1) {
				argc--;
				printer = *++argv;
			}
E 20
E 5
			break;

		case 'C':		/* classification spec */
			hdr++;
			if (arg[2])
				class = &arg[2];
D 5
			else if (argc >= 2) {
				++argv;
				arg = argv[1];
E 5
I 5
D 9
			else if (argc > 0) {
E 9
I 9
			else if (argc > 1) {
E 9
E 5
				argc--;
D 5
				class = arg;
E 5
I 5
				class = *++argv;
E 5
			}
			break;

D 5
		case 'r':		/* remove file when done */
			flag = '-';
			break;

		case 'm':		/* send mail when done */
			mailflg++;
			break;

		case 'q':		/* just q job */
			qflg++;
			break;

		case 'J':		/* job spec */
			jflag++, hdr++;
			if (arg[2]) {
E 5
I 5
		case 'J':		/* job name */
			hdr++;
			if (arg[2])
E 5
				jobname = &arg[2];
D 5
				break;
			}
			if (argc>=2) {
				++argv;
				arg = argv[1];
				jobname = &arg[0];
E 5
I 5
D 9
			else if (argc > 0) {
E 9
I 9
			else if (argc > 1) {
E 9
E 5
				argc--;
I 5
				jobname = *++argv;
E 5
			}
			break;

I 37
		case 'O':		/* processing options */
			if (arg[2])
				options = &arg[2];
			else if (argc > 1) {
				argc--;
				options = *++argv;
			}
			break;

E 37
D 5
		case 'i':		/* indent output */
			iflag++;
			indent = arg[2] ? atoi(&arg[2]) : 8;
E 5
I 5
		case 'T':		/* pr's title line */
			if (arg[2])
				title = &arg[2];
D 9
			else if (argc > 0) {
E 9
I 9
			else if (argc > 1) {
E 9
				argc--;
				title = *++argv;
			}
E 5
			break;

D 9
		case 'p':		/* use pr to print files */
			prflag++;
E 9
I 9
		case 'l':		/* literal output */
		case 'p':		/* print using ``pr'' */
D 17
		case 't':		/* print troff output */
E 17
I 17
		case 't':		/* print troff output (cat files) */
I 25
		case 'n':		/* print ditroff output */
E 25
		case 'd':		/* print tex output (dvi files) */
		case 'g':		/* print graph(1G) output */
E 17
		case 'c':		/* print cifplot output */
		case 'v':		/* print vplot output */
			format = arg[1];
E 9
			break;

I 17
		case 'f':		/* print fortran output */
			format = 'r';
			break;

E 17
I 9
		case '4':		/* troff fonts */
		case '3':
		case '2':
		case '1':
			if (argc > 1) {
				argc--;
				fonts[arg[1] - '1'] = *++argv;
D 25
				format = 't';
E 25
			}
			break;

		case 'w':		/* versatec page width */
			width = arg+2;
			break;

E 9
D 5
		case 'h':		/* pr's title line */
			if (arg[2])
				title = &arg[2];
			else if (argc >= 2) {
				++argv;
				arg = argv[1];
				argc--;
				title = arg;
			}
E 5
I 5
		case 'r':		/* remove file when done */
			rflag++;
E 5
			break;

D 5
		case 'P':		/* specifiy printer name */
D 2
			printer = argv[2];
E 2
I 2
D 3
			printer = arg[2];
E 3
I 3
			printer = &arg[2];
E 5
I 5
		case 'm':		/* send mail when done */
			mailflg++;
E 5
E 3
E 2
			break;

D 5
		case 'H':		/* toggle want of header page */
E 5
I 5
		case 'h':		/* toggle want of header page */
E 5
			hdr = !hdr;
			break;

I 5
D 6
		case 'c':		/* force copy of files */
			cflag++;
E 6
I 6
D 9
		case 'l':		/* try to link files */
E 9
I 9
		case 's':		/* try to link files */
E 9
D 17
			lflag++;
E 17
I 17
			sflag++;
E 17
E 6
			break;

		case 'q':		/* just q job */
			qflag++;
			break;

		case 'i':		/* indent output */
			iflag++;
			indent = arg[2] ? atoi(&arg[2]) : 8;
			break;

E 5
D 11
		default:		/* n copies ? */
			if (isdigit(arg[1]))
				ncopies = atoi(&arg[1]);
E 11
I 11
		case '#':		/* n copies */
D 24
			if (isdigit(arg[2]))
				ncopies = atoi(&arg[2]);
E 24
I 24
			if (isdigit(arg[2])) {
				i = atoi(&arg[2]);
				if (i > 0)
					ncopies = i;
			}
E 24
E 11
		}
D 5
		argc--;
		argv++;
E 5
	}
I 5
	if (printer == NULL && (printer = getenv("PRINTER")) == NULL)
		printer = DEFLP;
E 5
D 17
	if (!chkprinter(printer)) {
D 5
		fprintf(stderr, "%s: no entry for default printer %s\n", name,
			printer);
E 5
I 5
D 11
		printf("%s: unknown printer\n", name, printer);
E 11
I 11
		printf("%s: unknown printer %s\n", name, printer);
E 11
E 5
D 16
		exit(2);
E 16
I 16
		exit(1);
E 16
	}
E 17
I 17
	chkprinter(printer);
I 24
	if (SC && ncopies > 1)
		fatal("multiple copies are not allowed");
	if (MC > 0 && ncopies > MC)
		fatal("only %d copies are allowed", MC);
E 24
E 17
I 9
	/*
I 18
D 24
	 * Check to make sure queuing is enabled.
	 */
	(void) sprintf(line, "%s/%s", SD, LO);
	if (stat(line, &stb) == 0 && (stb.st_mode & 010))
		fatal("Printer queue is disabled");
	/*
E 24
E 18
D 17
	 * Get the identity of the person doing the lpr and initialize the
	 * control file.
E 17
I 17
	 * Get the identity of the person doing the lpr using the same
	 * algorithm as lprm. 
E 17
	 */
	userid = getuid();
D 12
	if ((person = getlogin()) == NULL) {
E 12
I 12
D 17
	if ((person = getlogin()) == NULL || strlen(person) == 0) {
E 12
		if ((pw = getpwuid(userid)) == NULL)
			person = "Unknown User";
		else
			person = pw->pw_name;
	} else if ((pw = getpwnam(person)) != NULL)
		userid = pw->pw_uid;		/* in case of su */
E 17
I 17
	if ((pw = getpwuid(userid)) == NULL)
		fatal("Who are you?");
	person = pw->pw_name;
	/*
I 31
	 * Check for restricted group access.
	 */
D 32
	if (RG != 0) {
E 32
I 32
	if (RG != NULL) {
E 32
		if ((gptr = getgrnam(RG)) == NULL)
			fatal("Restricted group specified incorrectly");
D 32
		while (*gptr->gr_mem != NULL) {
			if ((strcmp(person,*gptr->gr_mem)) == 0)
				break;
			gptr->gr_mem++;
E 32
I 32
		if (gptr->gr_gid != getgid()) {
			while (*gptr->gr_mem != NULL) {
				if ((strcmp(person, *gptr->gr_mem)) == 0)
					break;
				gptr->gr_mem++;
			}
			if (*gptr->gr_mem == NULL)
				fatal("Not a member of the restricted group");
E 32
		}
D 32
		if (*gptr->gr_mem == NULL)
			fatal("Not a member of the restricted group");
E 32
	}
	/*
E 31
I 24
	 * Check to make sure queuing is enabled if userid is not root.
	 */
D 26
	(void) sprintf(line, "%s/%s", SD, LO);
	if (userid && stat(line, &stb) == 0 && (stb.st_mode & 010))
E 26
I 26
	(void) sprintf(buf, "%s/%s", SD, LO);
	if (userid && stat(buf, &stb) == 0 && (stb.st_mode & 010))
E 26
		fatal("Printer queue is disabled");
	/*
E 24
	 * Initialize the control file.
	 */
E 17
E 9
D 5
	i = getpid();
	f = strlen(SA)+11;
	tfname = mktmp("tf", i, f);
	cfname = mktmp("cf", i, f);
	lfname = mktmp("lf", i, f);
	dfname = mktmp("df", i, f);
	inchar = f-7;
	tff = nfile(tfname);
	if (jflag == 0) {
E 5
I 5
	mktemps();
	tfd = nfile(tfname);
I 28
	(void) fchown(tfd, DU, -1);	/* owned by daemon for protection */
E 28
D 9
	if (jobname == NULL) {
E 5
D 4
		if(argc == 1)
E 4
I 4
		if (argc == 1)
E 4
D 5
			jobname = &dfname[f-10];
E 5
I 5
			jobname = &cfname[inchar-2];
E 5
		else
			jobname = argv[1];
E 9
I 9
	card('H', host);
	card('P', person);
I 37
	if (options)
		card('O', options);
E 37
	if (hdr) {
		if (jobname == NULL) {
			if (argc == 1)
D 11
				jobname = &cfname[inchar-2];
E 11
I 11
				jobname = "stdin";
E 11
			else
D 17
				jobname = argv[1];
E 17
I 17
				jobname = (arg = rindex(argv[1], '/')) ? arg+1 : argv[1];
E 17
		}
		card('J', jobname);
		card('C', class);
		card('L', person);
E 9
	}
D 9
	ident();
E 9
I 9
	if (iflag)
		card('I', itoa(indent));
	if (mailflg)
		card('M', person);
D 17
	if (format == 't')
E 17
I 17
D 25
	if (format == 't' || format == 'd')
E 25
I 25
	if (format == 't' || format == 'n' || format == 'd')
E 25
E 17
		for (i = 0; i < 4; i++)
			if (fonts[i] != NULL)
				card('1'+i, fonts[i]);
D 11
	else if ((format == 'f' || format == 'l' || format == 'p') && width)
E 11
I 11
	if (width != NULL)
E 11
		card('W', width);
E 9

I 17
	/*
	 * Read the files and spool them.
	 */
E 17
D 4
	if(argc == 1)
E 4
I 4
	if (argc == 1)
E 4
		copy(0, " ");
D 4
	else while(--argc) {
		if(test(arg = *++argv) == -1)	/* file reasonable */
E 4
I 4
	else while (--argc) {
D 5
		if (test(arg = *++argv) == -1)	/* file reasonable */
E 4
			continue;
E 5
I 5
D 7
		if (test(arg = *++argv))
E 7
I 7
D 11
		if ((i = test(arg = *++argv)) < 0)
E 11
I 11
		if ((f = test(arg = *++argv)) < 0)
E 11
E 7
			continue;	/* file unreasonable */
E 5

D 5
		if (flag == '+')		/* force copy flag */
			goto cf;
		if (stat(arg, &sbuf) < 0) {
D 4
			printf("lpr:");
E 4
I 4
			printf("%s:", name);
E 4
			perror(arg);
			continue;
E 5
I 5
D 6
		if (!cflag && linked(arg)) {
E 6
I 6
D 7
		if (lflag && linked(arg)) {
E 7
I 7
D 11
		if (i && lflag && linked(arg)) {
E 11
I 11
D 18
		if ((f & 1) && (cp = linked(arg)) != NULL) {
E 18
I 18
		if (sflag && (cp = linked(arg)) != NULL) {
I 30
			(void) sprintf(buf, "%d %d", statb.st_dev, statb.st_ino);
			card('S', buf);
E 30
E 18
E 11
E 7
E 6
D 9
			if (prflag)
E 9
I 9
			if (format == 'p')
E 9
				card('T', title ? title : arg);
D 9
			for (i = 0;i < ncopies; i++)
				card(prflag ? 'R' : 'F', &dfname[inchar-2]);
E 9
I 9
			for (i = 0; i < ncopies; i++)
				card(format, &dfname[inchar-2]);
E 9
			card('U', &dfname[inchar-2]);
I 11
D 18
			if (f & 2)
E 18
I 18
			if (f)
E 18
				card('U', cp);
E 11
			card('N', arg);
			dfname[inchar]++;
			nact++;
E 5
D 7
		}
D 4
		if((sbuf.st_mode&04) == 0)
E 4
I 4
D 5
		if ((sbuf.st_mode&04) == 0)
E 4
			goto cf;
D 4
		if(*arg == '/' && flag != '-') {
			for(i=0;i<ncopies;i++) {
E 4
I 4
		if (*arg == '/' && flag != '-') {
			for (i=0;i<ncopies;i++) {
E 4
				if (prflag) {
					if (title)
						card('H', title);
					card('R', arg);
				} else
					card('F', arg);
				card('N', arg);
E 5
I 5
		else {
E 7
I 7
D 18
		} else {
E 7
D 11
			if ((f = open(arg, 0)) < 0) {
E 11
I 11
			if ((i = open(arg, 0)) < 0) {
E 11
				printf("%s: cannot open %s\n", name, arg);
				continue;
E 5
			}
D 5
			nact++;
			continue;
E 5
I 5
D 11
			copy(f, arg);
			(void) close(f);
E 5
		}
D 4
		if(link(arg, lfname) < 0)
E 4
I 4
D 5
		if (link(arg, lfname) < 0)
E 4
			goto cf;
D 4
		for(i=0;i<ncopies;i++) {
E 4
I 4
		for (i=0;i<ncopies;i++) {
E 4
			if (prflag) {
				card('H', title ? title : arg);
				card('R', lfname);
			} else 
				card('F', lfname);
			card('N', arg);
		}
		card('U', lfname);
		lfname[inchar]++;
		nact++;
		goto df;
E 5
I 5
		if (rflag) {
			register char *cp;
E 5

D 5
	cf:
D 4
		if((f = open(arg, 0)) < 0) {
E 4
I 4
		if ((f = open(arg, 0)) < 0) {
E 4
			printf("%s: cannot open %s\n", name, arg);
			continue;
E 5
I 5
			if ((cp = rindex(arg, '/')) == NULL)
				f = access(".", 2);
			else {
				*cp = '\0';
				f = access(arg, 2);
				*cp = '/';
			}
			if (f || unlink(arg))
E 11
I 11
			copy(i, arg);
			(void) close(i);
			if ((f & 2) && unlink(arg))
E 11
				printf("%s: cannot remove %s\n", name, arg);
E 18
I 18
			continue;
E 18
E 5
		}
I 18
		if (sflag)
			printf("%s: %s: not linked, copying instead\n", name, arg);
D 23
		if ((i = open(arg, 0)) < 0) {
E 23
I 23
		if ((i = open(arg, O_RDONLY)) < 0) {
E 23
			printf("%s: cannot open %s\n", name, arg);
			continue;
		}
		copy(i, arg);
		(void) close(i);
		if (f && unlink(arg) < 0)
			printf("%s: %s: not removed\n", name, arg);
E 18
D 5
		copy(f, arg);
		close(f);

	df:
D 4
		if(flag == '-' && unlink(arg))
E 4
I 4
		if (flag == '-' && unlink(arg))
E 4
			printf("%s: cannot remove %s\n", name, arg);
E 5
	}

D 4
	if(nact) {
E 4
I 4
	if (nact) {
I 13
		(void) close(tfd);
E 13
E 4
		tfname[inchar]--;
I 13
		/*
		 * Touch the control file to fix position in the queue.
		 */
D 23
		if ((tfd = open(tfname, 2)) >= 0) {
E 23
I 23
		if ((tfd = open(tfname, O_RDWR)) >= 0) {
E 23
			char c;

			if (read(tfd, &c, 1) == 1 && lseek(tfd, 0L, 0) == 0 &&
			    write(tfd, &c, 1) != 1) {
				printf("%s: cannot touch %s\n", name, tfname);
				tfname[inchar]++;
D 17
				out();
E 17
I 17
				cleanup();
E 17
			}
			(void) close(tfd);
		}
E 13
D 4
		if(link(tfname, dfname) < 0) {
E 4
I 4
D 5
		if (link(tfname, dfname) < 0) {
E 4
			printf("%s: cannot rename %s\n", name, dfname);
E 5
I 5
		if (link(tfname, cfname) < 0) {
			printf("%s: cannot rename %s\n", name, cfname);
E 5
			tfname[inchar]++;
D 17
			out();
E 17
I 17
			cleanup();
E 17
		}
		unlink(tfname);
D 5
		if (qflg)		/* just q things up */
E 5
I 5
		if (qflag)		/* just q things up */
E 5
			exit(0);
D 5
		if (stat(LP, &sbuf) >= 0 && (sbuf.st_mode&0777) == 0) {
			printf("job queued, but printer down\n");
E 5
I 5
D 17
		if (*LP && stat(LP, &stb) >= 0 && (stb.st_mode & 0777) == 0) {
D 14
			printf("jobs queued, but line printer is down.\n");
E 14
I 14
			printf("jobs queued, but %s is down.\n", printer);
E 14
E 5
			exit(0);
		}
D 4
		for(f = 0; f < NOFILE; close(f++))
E 4
I 4
D 5
		for (f = 0; f < NOFILE; close(f++))
E 4
			;
		open("/dev/tty", 0);
		open("/dev/tty", 1);
		dup2(1, 2);
		execl(DN, rindex(DN, '/') ? rindex(DN, '/')+1 : DN, printer, 0);
		dfname[inchar]++;
E 5
I 5
D 11
		execl(DN, arg = rindex(DN, "/") ? arg+1 : DN, printer, 0);
E 11
I 11
		execl(DN, (arg = rindex(DN, '/')) ? arg+1 : DN, printer, 0);
E 11
		printf("jobs queued, but cannot start daemon.\n");
E 17
I 17
D 22
		if (!startdaemon())
E 22
I 22
D 26
		if (!startdaemon(host))
E 26
I 26
		if (!startdaemon(printer))
E 26
E 22
			printf("jobs queued, but cannot start daemon.\n");
E 17
		exit(0);
E 5
	}
D 17
	out();
I 5
	/*NOTREACHED*/
E 17
I 17
	cleanup();
	/* NOTREACHED */
E 17
E 5
}

I 5
/*
 * Create the file n and copy from file descriptor f.
 */
E 5
copy(f, n)
D 4
int f;
char n[];
E 4
I 4
	int f;
	char n[];
E 4
{
D 5
	int ff, i, nr, nc;
E 5
I 5
	register int fd, i, nr, nc;
I 30
	char buf[BUFSIZ];
E 30
E 5
D 26
	char buf[BUFSIZ];
E 26

D 4
	for(i=0;i<ncopies;i++) {
E 4
I 4
D 5
	for (i=0;i<ncopies;i++) {
E 4
		if (prflag) {
			card('H', title ? title : n);
			card('R', cfname);
		} else 
			card('F', cfname);
		card('N', n);
	}
	card('U', cfname);
	ff = nfile(cfname);
E 5
I 5
D 9
	if (prflag)
E 9
I 9
	if (format == 'p')
E 9
		card('T', title ? title : n);
	for (i = 0; i < ncopies; i++)
D 9
		card(prflag ? 'R' : 'F', &dfname[inchar-2]);
E 9
I 9
		card(format, &dfname[inchar-2]);
E 9
	card('U', &dfname[inchar-2]);
	card('N', n);
	fd = nfile(dfname);
E 5
	nr = nc = 0;
D 4
	while((i = read(f, buf, BUFSIZ)) > 0) {
E 4
I 4
	while ((i = read(f, buf, BUFSIZ)) > 0) {
E 4
D 5
		if (write(ff, buf, i) != i) {
E 5
I 5
		if (write(fd, buf, i) != i) {
E 5
			printf("%s: %s: temp file write error\n", name, n);
			break;
		}
		nc += i;
D 4
		if(nc >= BUFSIZ) {
E 4
I 4
		if (nc >= BUFSIZ) {
E 4
			nc -= BUFSIZ;
D 4
			if(nr++ > MX) {
E 4
I 4
D 15
			if (nr++ > MX) {
E 15
I 15
			nr++;
			if (MX > 0 && nr > MX) {
E 15
E 4
				printf("%s: %s: copy file is too large\n", name, n);
				break;
			}
		}
	}
D 5
	close(ff);
E 5
I 5
	(void) close(fd);
E 5
D 29
	nact++;
E 29
I 29
	if (nc==0 && nr==0) 
		printf("%s: %s: empty input file\n", name, f ? n : "stdin");
	else
		nact++;
E 29
}

I 5
/*
D 11
 * Try and link the file to dfname. Return true if successful.
E 11
I 11
 * Try and link the file to dfname. Return a pointer to the full
 * path name if successful.
E 11
 */
I 11
char *
E 11
linked(file)
	register char *file;
{
	register char *cp;
D 18
	char buf[BUFSIZ];
E 18
I 18
	static char buf[BUFSIZ];
E 18

D 11
	if (link(file, dfname) == 0)
		return(1);
E 11
	if (*file != '/') {
		if (getwd(buf) == NULL)
D 11
			return(0);
E 11
I 11
			return(NULL);
E 11
		while (file[0] == '.') {
			switch (file[1]) {
			case '/':
				file += 2;
				continue;
			case '.':
				if (file[2] == '/') {
					if ((cp = rindex(buf, '/')) != NULL)
						*cp = '\0';
					file += 3;
					continue;
				}
			}
			break;
		}
		strcat(buf, "/");
		strcat(buf, file);
		file = buf;
	}
D 11
	return(symlink(file, dfname) == 0);
E 11
I 11
	return(symlink(file, dfname) ? NULL : file);
E 11
}

/*
 * Put a line into the control file.
 */
E 5
card(c, p2)
D 4
register char c, *p2;
E 4
I 4
	register char c, *p2;
E 4
{
I 30
	char buf[BUFSIZ];
E 30
D 26
	char buf[BUFSIZ];
E 26
	register char *p1 = buf;
D 5
	int col = 0;
E 5
I 5
	register int len = 2;
E 5

	*p1++ = c;
D 4
	while((c = *p2++) != '\0') {
E 4
I 4
	while ((c = *p2++) != '\0') {
E 4
		*p1++ = c;
D 5
		col++;
E 5
I 5
		len++;
E 5
	}
	*p1++ = '\n';
D 5
	write(tff, buf, col+2);
E 5
I 5
	write(tfd, buf, len);
E 5
}

I 5
/*
D 9
 * Get the identity of the person doing the lpr and save it in the
 * control file.
 */
E 5
ident()
{
	extern char *getlogin();
	extern struct passwd *getpwuid();
	struct passwd *pw;
	extern char *itoa();

	if ((person = getlogin()) == NULL) {
		if ((pw = getpwuid(user)) == NULL)
			person = "Unknown User";
		else
			person = pw->pw_name;
	}

I 5
	card('H', host);
	card('P', person);
E 5
	if (hdr) {
D 5
		card('J',jobname);
		card('C',class);
E 5
I 5
		card('J', jobname);
		card('C', class);
E 5
		card('L', person);
	}
	if (iflag)
		card('I', itoa(indent));
	if (mailflg)
		card('M', person);
}

I 5
/*
E 9
 * Create a new file in the spool directory.
 */
D 17

E 17
E 5
nfile(n)
D 4
char *n;
E 4
I 4
	char *n;
E 4
{
	register f;
I 4
D 5
	int oldumask = umask(022);		/* should block signals */
E 5
I 5
	int oldumask = umask(0);		/* should block signals */
E 5
E 4

D 4
	if((f = creat(n, FILMOD)) < 0) {
E 4
I 4
	f = creat(n, FILMOD);
	(void) umask(oldumask);
	if (f < 0) {
E 4
		printf("%s: cannot create %s\n", name, n);
D 17
		out();
E 17
I 17
		cleanup();
E 17
	}
I 28
	if (fchown(f, userid, -1) < 0) {
		printf("%s: cannot chown %s\n", name, n);
		cleanup();
	}
E 28
I 11
D 17
#ifdef BSD41C
E 17
E 11
D 5
	if (chown(n, user, spgroup) < 0) {
E 5
I 5
D 9
	if (chown(n, user, getegid()) < 0) {
E 9
I 9
D 18
	if (chown(n, userid, -1) < 0) {
I 11
D 17
#else
	if (chown(n, userid, getegid()) < 0) {
#endif
E 17
E 11
E 9
E 5
		unlink(n);
		printf("%s: cannot chown %s\n", name, n);
D 17
		out();
E 17
I 17
		cleanup();
E 17
	}
E 18
D 13
	n[inchar]++;
E 13
I 13
	if (++n[inchar] > 'z') {
		if (++n[inchar-2] == 't') {
			printf("too many files - break up the job\n");
D 17
			out();
E 17
I 17
			cleanup();
E 17
		}
		n[inchar] = 'A';
	} else if (n[inchar] == '[')
		n[inchar] = 'a';
E 13
D 4
	return(f);
E 4
I 4
D 5
	return (f);
E 5
I 5
	return(f);
E 5
E 4
}

I 5
/*
 * Cleanup after interrupts and errors.
 */
E 5
D 17
out()
E 17
I 17
cleanup()
E 17
{
	register i;

	signal(SIGHUP, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
	i = inchar;
	if (tfname)
D 4
		while(tfname[i] != 'A') {
E 4
I 4
D 15
		while (tfname[i] != 'A') {
E 4
			tfname[i]--;
E 15
I 15
		do
E 15
			unlink(tfname);
D 15
		}
E 15
I 15
		while (tfname[i]-- != 'A');
E 15
	if (cfname)
D 4
		while(cfname[i] != 'A') {
E 4
I 4
D 15
		while (cfname[i] != 'A') {
E 4
			cfname[i]--;
E 15
I 15
		do
E 15
			unlink(cfname);
D 15
		}
E 15
I 15
		while (cfname[i]-- != 'A');
E 15
D 5
	if (lfname)
D 4
		while(lfname[i] != 'A') {
E 4
I 4
		while (lfname[i] != 'A') {
E 4
			lfname[i]--;
			unlink(lfname);
		}
E 5
	if (dfname)
D 4
		while(dfname[i] != 'A') {
E 4
I 4
D 13
		while (dfname[i] != 'A') {
E 4
			dfname[i]--;
			unlink(dfname);
E 13
I 13
D 15
		while (dfname[i-2] >= 'd') {
			while (dfname[i] != 'A') {
				dfname[i]--;
E 15
I 15
		do {
			do
E 15
				unlink(dfname);
D 15
			}
			dfname[i-2]--;
E 13
		}
E 15
I 15
			while (dfname[i]-- != 'A');
			dfname[i] = 'z';
		} while (dfname[i-2]-- != 'd');
E 15
D 16
	exit();
E 16
I 16
	exit(1);
E 16
}

I 5
/*
 * Test to see if this is a printable file.
D 7
 * Return -1 if it is not, else 0
E 7
I 7
D 11
 * Return -1 if it is not, 1 if it's publically readable, else 0
E 11
I 11
D 18
 * Return -1 if it is not, 1 if we should try to link and or in 2 if
E 18
I 18
 * Return -1 if it is not, 0 if its printable, and 1 if
E 18
 * we should remove it after printing.
E 11
E 7
 */
E 5
test(file)
D 4
char *file;
E 4
I 4
	char *file;
E 4
{
D 5
	struct exec buf;
	struct stat mbuf;
E 5
I 5
	struct exec execb;
D 30
	struct stat statb;
E 30
E 5
D 11
	int fd;
E 11
I 11
	register int fd;
	register char *cp;
E 11

	if (access(file, 4) < 0) {
		printf("%s: cannot access %s\n", name, file);
D 4
		return(-1);
E 4
I 4
D 5
		return (-1);
E 5
I 5
		return(-1);
E 5
E 4
	}
D 4
	if(stat(file, &mbuf) < 0) {
E 4
I 4
D 5
	if (stat(file, &mbuf) < 0) {
E 5
I 5
	if (stat(file, &statb) < 0) {
E 5
E 4
		printf("%s: cannot stat %s\n", name, file);
D 5
		return (-1);
E 5
I 5
		return(-1);
E 5
	}
D 5
	if ((mbuf.st_mode&S_IFMT) == S_IFDIR) {
E 5
I 5
	if ((statb.st_mode & S_IFMT) == S_IFDIR) {
E 5
		printf("%s: %s is a directory\n", name, file);
D 4
		return(-1);
E 4
I 4
D 5
		return (-1);
E 5
I 5
		return(-1);
E 5
E 4
	}
I 29
	if (statb.st_size == 0) {
		printf("%s: %s is an empty file\n", name, file);
		return(-1);
 	}
E 29
D 5

E 5
D 4
	if((fd = open(file, 0)) < 0) {
E 4
I 4
D 23
	if ((fd = open(file, 0)) < 0) {
E 23
I 23
	if ((fd = open(file, O_RDONLY)) < 0) {
E 23
E 4
		printf("%s: cannot open %s\n", name, file);
D 4
		return(-1);
E 4
I 4
D 5
		return (-1);
E 5
I 5
		return(-1);
E 5
E 4
	}
D 5
	if (read(fd, &buf, sizeof(buf)) == sizeof(buf))
		switch(buf.a_magic) {
E 5
I 5
	if (read(fd, &execb, sizeof(execb)) == sizeof(execb))
		switch(execb.a_magic) {
E 5
		case A_MAGIC1:
		case A_MAGIC2:
		case A_MAGIC3:
#ifdef A_MAGIC4
		case A_MAGIC4:
#endif
			printf("%s: %s is an executable program", name, file);
			goto error1;

		case ARMAG:
			printf("%s: %s is an archive file", name, file);
			goto error1;
		}
I 5
	(void) close(fd);
D 11
	if (rflag) {	/* check to make sure user can delete this file */
		register char	*cp = rindex(file, '/');
E 5

D 5
	close(fd);
D 4
	return(0);
E 4
I 4
	return (0);
E 5
I 5
		if (cp == NULL)
D 9
			file = ".";
		else
E 9
I 9
			fd = access(".", 2);
		else {
E 11
I 11
D 18
	fd = 0;
D 17
	if (lflag && (statb.st_mode & 04))
E 17
I 17
	if (sflag && (statb.st_mode & 04))
E 17
		fd |= 1;
E 18
	if (rflag) {
		if ((cp = rindex(file, '/')) == NULL) {
			if (access(".", 2) == 0)
D 18
				fd |= 2;
E 18
I 18
				return(1);
E 18
		} else {
E 11
E 9
			*cp = '\0';
D 9
		if (access(file, 2) < 0) {
E 9
I 9
D 11
			fd = access(file, 2);
E 11
I 11
D 18
			if (access(file, 2) == 0)
				fd |= 2;
E 18
I 18
			fd = access(file, 2);
E 18
E 11
E 9
			*cp = '/';
I 18
			if (fd == 0)
				return(1);
E 18
I 9
		}
I 18
		printf("%s: %s: is not removable by you\n", name, file);
E 18
D 11
		if (fd < 0) {
E 9
			printf("%s: cannot remove %s\n", name, file);
			return(-1);
		}
E 11
D 9
		*cp = '/';
E 9
	}
I 7
D 11
	if (statb.st_mode & 04)
		return(1);
E 7
	return(0);
E 11
I 11
D 18
	return(fd);
E 18
I 18
	return(0);
E 18
E 11

E 5
E 4
error1:
	printf(" and is unprintable\n");
D 5
	close(fd);
D 4
	return(-1);
E 4
I 4
	return (-1);
E 5
I 5
	(void) close(fd);
	return(-1);
E 5
E 4
}

/*
 * itoa - integer to string conversion
 */
char *
itoa(i)
D 4
register int i;
E 4
I 4
	register int i;
E 4
{
	static char b[10] = "########";
	register char *p;

	p = &b[8];
	do
		*p-- = i%10 + '0';
	while (i /= 10);
D 4
	return(++p);
E 4
I 4
D 5
	return (++p);
E 5
I 5
	return(++p);
E 5
E 4
}

/*
 * Perform lookup for printer name or abbreviation --
D 5
 *   return pointer to daemon structure
E 5
 */
chkprinter(s)
D 4
register char *s;
E 4
I 4
D 26
	register char *s;
E 26
I 26
	char *s;
E 26
E 4
{
D 17
	static char buf[BUFSIZ/2];
	char b[BUFSIZ];
	int stat;
	char *bp = buf;
E 17
I 17
	int status;
I 30
	char buf[BUFSIZ];
E 30
I 26
	static char pbuf[BUFSIZ/2];
	char *bp = pbuf;
	extern char *pgetstr();
E 26
E 17

D 17
	if ((stat = pgetent(b, s)) < 0) {
D 5
		fprintf(stderr, "%s: can't open printer description file\n", name);
E 5
I 5
		printf("%s: can't open printer description file\n", name);
E 5
D 16
		exit(3);
E 16
I 16
		exit(1);
E 16
	} else if (stat == 0)
D 4
		return(NULL);
E 4
I 4
D 5
		return (NULL);
E 5
I 5
		return(0);
E 5
E 4
	if ((DN = pgetstr("dn", &bp)) == NULL)
		DN = DEFDAEMON;
	if ((LP = pgetstr("lp", &bp)) == NULL)
		LP = DEFDEVLP;
E 17
I 17
D 26
	if ((status = pgetent(line, s)) < 0)
E 26
I 26
	if ((status = pgetent(buf, s)) < 0)
E 26
		fatal("cannot open printer description file");
	else if (status == 0)
D 26
		fatal("unknown printer");
E 26
I 26
		fatal("%s: unknown printer", s);
E 26
E 17
D 5
	if ((SA = pgetstr("sa", &bp)) == NULL)
		SA = DEFSPOOL;
E 5
I 5
	if ((SD = pgetstr("sd", &bp)) == NULL)
		SD = DEFSPOOL;
I 18
	if ((LO = pgetstr("lo", &bp)) == NULL)
		LO = DEFLOCK;
I 31
D 32
	RG = pgetstr("rg",&bp);
E 32
I 32
	RG = pgetstr("rg", &bp);
E 32
E 31
E 18
E 5
	if ((MX = pgetnum("mx")) < 0)
		MX = DEFMX;
I 24
	if ((MC = pgetnum("mc")) < 0)
		MC = DEFMAXCOPIES;
I 28
	if ((DU = pgetnum("du")) < 0)
		DU = DEFUID;
E 28
E 24
I 18
D 26
	if ((DU = pgetnum("du")) < 0)
		DU = DEFUID;
E 26
I 24
	SC = pgetflag("sc");
E 24
E 18
D 4
	return(1);
E 4
I 4
D 5
	return (1);
E 5
I 5
D 17
	RM = pgetstr("rm", &bp);
	return(1);
E 17
I 17
D 19
	RM = host;		/* machine for getport to connect to */
E 19
E 17
E 5
E 4
}

/*
D 5
 * Make a temp file
E 5
I 5
 * Make the temp files.
E 5
 */
I 5
mktemps()
{
D 7
	register int fd, len;
E 7
I 7
D 24
	register int c, len;
E 7
	int n;
E 24
I 24
	register int c, len, fd, n;
	register char *cp;
I 30
	char buf[BUFSIZ];
E 30
E 24
D 26
	char buf[BUFSIZ], *mktemp();
E 26
I 26
	char *mktemp();
E 26
I 7
D 24
	FILE *fp;
E 24
E 7

	(void) sprintf(buf, "%s/.seq", SD);
D 7
	if ((fd = open(buf, 2)) < 0) {
		n = umask(0);
		fd = creat(buf, FILMOD);
		(void) umask(n);
		if (fd < 0) {
			printf("%s: cannot create %s\n", name, buf);
			exit(1);
		}
		n = 1;
	}
	else {
		if (flock(fd, FEXLOCK)) {
E 7
I 7
D 24
	if ((fp = fopen(buf, "r+")) == NULL) {
D 9
		printf("%s: cannot create %s\n", name, buf);
		exit(1);
E 9
I 9
		if ((fp = fopen(buf, "w")) == NULL) {
			printf("%s: cannot create %s\n", name, buf);
			exit(1);
E 24
I 24
	if ((fd = open(buf, O_RDWR|O_CREAT, 0661)) < 0) {
		printf("%s: cannot create %s\n", name, buf);
		exit(1);
	}
	if (flock(fd, LOCK_EX)) {
		printf("%s: cannot lock %s\n", name, buf);
		exit(1);
	}
	n = 0;
	if ((len = read(fd, buf, sizeof(buf))) > 0) {
		for (cp = buf; len--; ) {
			if (*cp < '0' || *cp > '9')
				break;
			n = n * 10 + (*cp++ - '0');
E 24
		}
D 24
		setbuf(fp, buf);
		n = 0;
E 9
	} else {
		setbuf(fp, buf);
I 9
D 17
#ifdef BSD41C
E 17
E 9
D 23
		if (flock(fileno(fp), FEXLOCK)) {
E 23
I 23
		if (flock(fileno(fp), LOCK_EX)) {
E 23
E 7
			printf("%s: cannot lock %s\n", name, buf);
			exit(1);
		}
I 9
D 17
#endif
E 17
E 9
D 7
		if (read(fd, (char *)&n, sizeof(n)) != sizeof(n))
			n = 1;
E 7
I 7
		n = 0;
		while ((c = getc(fp)) >= '0' && c <= '9')
			n = n * 10 + (c - '0');
E 24
E 7
	}
	len = strlen(SD) + strlen(host) + 8;
	tfname = mktemp("tf", n, len);
	cfname = mktemp("cf", n, len);
	dfname = mktemp("df", n, len);
	inchar = strlen(SD) + 3;
	n = (n + 1) % 1000;
D 7
	(void) lseek(fd, 0L, 0);
	(void) write(fd, &n, sizeof(n));
	(void) close(fd);
E 7
I 7
D 24
	(void) fseek(fp, 0L, 0);
	fprintf(fp, "%d\n", n);
	(void) fclose(fp);
E 24
I 24
	(void) lseek(fd, 0L, 0);
	sprintf(buf, "%03d\n", n);
	(void) write(fd, buf, strlen(buf));
	(void) close(fd);	/* unlocks as well */
E 24
E 7
}

/*
 * Make a temp file name.
 */
E 5
char *
D 5
mktmp(id, pid, n)
D 4
char *id;
E 4
I 4
	char *id;
E 5
I 5
mktemp(id, num, len)
	char	*id;
	int	num, len;
E 5
E 4
{
	register char *s;
I 26
	extern char *malloc();
E 26

D 5
	if ((s = malloc(n)) == NULL) {
		fprintf(stderr, "%s: out of memory\n", name);
E 5
I 5
D 17
	if ((s = malloc(len)) == NULL) {
		printf("%s: out of memory\n", name);
E 5
		exit(1);
	}
E 17
I 17
	if ((s = malloc(len)) == NULL)
		fatal("out of memory");
E 17
D 5
	sprintf(s, "%s/%sA%05d", SA, id, pid);
D 4
	return(s);
E 4
I 4
	return (s);
E 5
I 5
	(void) sprintf(s, "%s/%sA%03d%s", SD, id, num, host);
	return(s);
I 26
}

/*VARARGS1*/
fatal(msg, a1, a2, a3)
	char *msg;
{
	printf("%s: ", name);
	printf(msg, a1, a2, a3);
	putchar('\n');
	exit(1);
E 26
E 5
E 4
}
E 1
