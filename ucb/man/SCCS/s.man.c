h21739
s 00000/00001/00616
d D 5.14 04/10/20 20:53:23 msokolov 31 30
c remove bogus unlink
e
s 00001/00002/00616
d D 5.13 87/04/26 14:30:36 bostic 30 29
c bug report 4.2BSD/ucb/95
e
s 00005/00010/00613
d D 5.12 86/03/20 06:30:22 lepreau 29 27
c do for whatis what did for apropos in 5.8
e
s 00007/00012/00611
d R 5.12 86/03/20 06:25:47 lepreau 28 27
c do same for whatis as did for apropos in 5.8
e
s 00024/00025/00599
d D 5.11 86/02/24 10:41:18 lepreau 27 26
c fix ss: unititalized, typo bug; lint
e
s 00008/00007/00616
d D 5.10 86/02/24 08:24:05 lepreau 26 25
c Env var MANPATH overrides default; remove unused subsecs
e
s 00001/00002/00622
d D 5.9 86/02/24 03:21:41 lepreau 25 24
c vpr is gone so use vtroff for -t
e
s 00006/00012/00618
d D 5.8 86/01/10 03:24:10 lepreau 24 23
c fix apropos so it doesn't stop after first manpath component
e
s 00002/00002/00628
d D 5.7 85/09/24 13:45:36 bloom 23 22
c umask should be 0 (why create something that may not be modifiable later) 
c use mv -f
e
s 00005/00026/00625
d D 5.6 85/08/29 16:37:24 bloom 22 21
c fix signal handling a bit and get rid of private copy of system()
e
s 00008/00006/00643
d D 5.5 85/08/27 13:15:58 bloom 21 20
c fix bug with .so when not going to a terminal (from ks@purdue)
e
s 00001/00001/00648
d D 5.4 85/08/09 13:55:51 mckusick 20 19
c files are group, but not world writable
e
s 00073/00024/00576
d D 5.3 85/08/07 17:23:03 mckusick 19 18
c use cat? if man? not available. more lienient in mano (from ks@purdue)
e
s 00001/00000/00599
d D 5.2 85/06/09 13:15:05 mckusick 18 17
c uninitialized variable bug
e
s 00013/00001/00586
d D 5.1 85/05/31 09:22:15 dist 17 16
c Add copyright
e
s 00006/00007/00581
d D 1.16 85/04/24 14:44:05 bloom 16 15
c incorrectly distinguished between man? and cat?
e
s 00001/00001/00587
d D 1.15 85/04/07 01:44:50 sam 15 14
c another blunder (wrong check on return value from pathstat)
e
s 00001/00001/00587
d D 1.14 85/04/07 01:35:40 sam 14 13
c using wrong stat buffer 
e
s 00202/00122/00386
d D 1.13 85/04/07 01:25:58 sam 13 12
c support alternate manual directories for man, apropos, and whatis 
c (a side effect of this is that the whatis database gets moved to the man dir)
e
s 00001/00001/00507
d D 1.12 85/03/27 14:41:00 karels 12 11
c spell appropriate appropriately
e
s 00031/00020/00477
d D 1.11 84/02/03 11:54:24 ralph 11 10
c use cat'able file if stdout != tty and fix system() for signals.
e
s 00054/00020/00443
d D 1.10 83/09/19 20:20:51 karels 10 9
c do 'more -s %s' instead of 'cat -s |ul|more -f';
c put magic search lists and commands at top
e
s 00001/00001/00462
d D 1.9 83/08/11 21:31:02 sam 9 8
c standardize sccs keyword lines
e
s 00001/00001/00462
d D 1.8 83/08/08 17:58:42 karels 8 7
c added 3c to list of subsec
e
s 00001/00001/00462
d D 1.7 83/04/02 17:06:30 sam 7 6
c botch
e
s 00001/00001/00462
d D 1.6 83/03/31 21:11:46 nicklin 6 5
c added p (project) and r (revision control) subsections to section 1
e
s 00006/00005/00457
d D 1.5 83/03/07 21:49:24 sam 5 4
c add 'v' entries for most sections
e
s 00001/00001/00461
d D 1.4 83/01/17 10:51:29 nicklin 4 3
c relative pathnames in ".so" references are assumed relative to /usr/man
e
s 00010/00004/00452
d D 1.3 83/01/12 10:36:50 nicklin 3 2
c Added -P option to specify alternative man root directory.
e
s 00004/00004/00452
d D 1.2 83/01/03 20:47:26 sam 2 1
c add .3n for network related stuff in section 3
e
s 00456/00000/00000
d D 1.1 82/05/10 17:46:29 sam 1 0
c date and time created 82/05/10 17:46:29 by sam
e
u
U
t
T
I 17
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 17
I 1
D 2
/* Copyright (c) 1982 Regents of the University of California */
E 2
I 2
#ifndef lint
I 17
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
E 17
D 9
static char sccsid[] = " %W% (Berkeley) %G%";
E 9
I 9
static char sccsid[] = "%W% (Berkeley) %G%";
E 9
D 17
#endif
E 17
I 17
#endif not lint
E 17
E 2

D 2
static char sccsid[] = "	%M%	%I%	%E%	";

E 2
#include <stdio.h>
#include <ctype.h>
#include <sgtty.h>
D 13
#include <sys/types.h>
E 13
I 13
#include <sys/param.h>
E 13
#include <sys/stat.h>
#include <signal.h>
I 13
#include <strings.h>

E 13
/*
 * man
I 10
 * link also to apropos and whatis
 * This version uses more for underlining and paging.
E 10
 */
I 10
D 13
#define	MANDIR	"/usr/man"		/* this is deeply embedded */
E 13
D 30
#define	NROFFCAT "nroff -h -man"	/* for nroffing to cat file */
E 30
#define	NROFF	"nroff -man"		/* for nroffing to tty */
#define	MORE	"more -s"		/* paging filter */
D 11
#define	CAT	"cat -s"		/* for '-' opt (no more) */
E 11
I 11
#define	CAT_	"/bin/cat"		/* for when output is not a tty */
#define	CAT_S	"/bin/cat -s"		/* for '-' opt (no more) */
E 11

D 25
#define TROFFCMD \
"troff -t -man /usr/lib/tmac/tmac.vcat %s | /usr/lib/rvsort |/usr/ucb/vpr -t"
E 25
I 25
#define TROFFCMD "vtroff -man %s"
E 25

D 13
/*  for troff:
#define	TROFFCMD "troff -man %s"
*/

E 13
#define	ALLSECT	"1nl6823457po"	/* order to look through sections */
#define	SECT1	"1nlo"		/* sections to look at if 1 is specified */
D 26
#define	SUBSEC1	"mcgprv"	/* subsections to try in section 1 */
#define	SUBSEC2	"v"
#define	SUBSEC3	"jxmsnvcf"
#define	SUBSEC4	"pfvsn"
#define	SUBSEC8	"vc"
E 26
I 26
#define	SUBSEC1	"cg"		/* subsections to try in section 1 */
#define	SUBSEC3	"sxmncf"
#define	SUBSEC4	"pfn"
#define	SUBSEC8	"cv"
E 26

I 13
#define	WHATIS	"whatis"

E 13
E 10
int	nomore;
D 27
int	cflag;
E 27
I 11
char	*CAT	= CAT_;
E 11
I 3
char	*manpath = "/usr/man";
E 3
char	*strcpy();
char	*strcat();
I 26
char	*getenv();
I 27
char	*calloc();
E 27
E 26
char	*trim();
int	remove();
I 13
int	apropos();
int	whatis();
E 13
int	section;
int	subsec;
int	troffit;
D 27
int	killtmp;
E 27
I 19
int	mypid;
E 19

#define	eq(a,b)	(strcmp(a,b) == 0)

main(argc, argv)
	int argc;
	char *argv[];
{
I 26
	char *mp;
E 26

I 26
	if ((mp = getenv("MANPATH")) != NULL)
		manpath = mp;
E 26
D 22
	if (signal(SIGINT, SIG_IGN) == SIG_DFL) {
		signal(SIGINT, remove);
		signal(SIGQUIT, remove);
		signal(SIGTERM, remove);
	}
E 22
D 19
	umask(0);
E 19
I 19
D 20
	umask(022);
E 20
I 20
D 23
	umask(02);
E 23
I 23
	umask(0);
E 23
E 20
	mypid = getpid();
E 19
I 10
	if (strcmp(argv[0], "apropos") == 0) {
D 13
		apropos(argc-1, argv+1);
E 13
I 13
		runpath(argc-1, argv+1, apropos);
E 13
		exit(0);
	}
	if (strcmp(argv[0], "whatis") == 0) {
D 13
		whatis(argc-1, argv+1);
E 13
I 13
		runpath(argc-1, argv+1, whatis);
E 13
		exit(0);
	}
E 10
	if (argc <= 1) {
		fprintf(stderr, "Usage: man [ section ] name ...\n");
D 10
		fprintf(stderr, "or: man -k keyword ...\n");
		fprintf(stderr, "or: man -f file ...\n");
E 10
		exit(1);
	}
D 3
	if (chdir("/usr/man") < 0) {
		fprintf(stderr, "Can't chdir to /usr/man.\n");
		exit(1);
	}
E 3
	argc--, argv++;
	while (argc > 0 && argv[0][0] == '-') {
		switch(argv[0][1]) {

		case 0:
			nomore++;
I 11
			CAT = CAT_S;
E 11
			break;

		case 't':
			troffit++;
			break;

		case 'k':
			apropos(argc-1, argv+1);
			exit(0);

		case 'f':
			whatis(argc-1, argv+1);
			exit(0);
I 3

D 13
		case 'P':
E 13
I 13
		case 'P':		/* backwards compatibility */
		case 'M':
			if (argc < 2) {
				fprintf(stderr, "%s: missing path\n", *argv);
				exit(1);
			}
E 13
			argc--, argv++;
			manpath = *argv;
			break;
E 3
		}
		argc--, argv++;
I 3
	}
D 13
	if (chdir(manpath) < 0) {
		fprintf(stderr, "Can't chdir to %s.\n", manpath);
		exit(1);
E 3
	}
E 13
	if (troffit == 0 && nomore == 0 && !isatty(1))
		nomore++;
	section = 0;
	do {
		if (eq(argv[0], "local")) {
			section = 'l';
			goto sectin;
		} else if (eq(argv[0], "new")) {
			section = 'n';
			goto sectin;
I 10
		} else if (eq(argv[0], "old")) {
			section = 'o';
			goto sectin;
E 10
		} else if (eq(argv[0], "public")) {
			section = 'p';
			goto sectin;
D 13
		} else if (argv[0][0] >= '0' && argv[0][0] <= '9' && (argv[0][1] == 0 || argv[0][2] == 0)) {
E 13
I 13
		} else if (isdigit(argv[0][0]) &&
		    (argv[0][1] == 0 || argv[0][2] == 0)) {
E 13
			section = argv[0][0];
			subsec = argv[0][1];
sectin:
			argc--, argv++;
			if (argc == 0) {
D 13
				fprintf(stderr, "But what do you want from section %s?\n", argv[-1]);
E 13
I 13
				fprintf(stderr,
				    "But what do you want from section %s?\n",
				    argv[-1]);
E 13
				exit(1);
			}
			continue;
		}
		manual(section, argv[0]);
		argc--, argv++;
	} while (argc > 0);
	exit(0);
}

I 13
runpath(ac, av, f)
	int ac;
	char *av[];
	int (*f)();
{

	if (ac > 0 && strcmp(av[0], "-M") == 0 || strcmp(av[0], "-P") == 0) {
		if (ac < 2) {
			fprintf(stderr, "%s: missing path\n", av[0]);
			exit(1);
		}
		manpath = av[1];
		ac -= 2, av += 2;
	}
	(*f)(ac, av);
	exit(0);
}

E 13
manual(sec, name)
D 13
	char sec;
	char *name;
E 13
I 13
	char sec, *name;
E 13
{
	char section = sec;
D 10
	char work[100], work2[100], cmdbuf[100];
E 10
I 10
D 13
	char work[100], work2[100], cmdbuf[150];
E 13
I 13
	char work[100], work2[100];
	char path[MAXPATHLEN+1], realname[MAXPATHLEN+1];
	char cmdbuf[150];
E 13
E 10
D 27
	int ss;
E 27
I 27
	int ss = 0;
E 27
	struct stat stbuf, stbuf2;
	int last;
D 10
	char *sp = "1nl6823457p";
E 10
I 10
	char *sp = ALLSECT;
I 13
	FILE *it;
	char abuf[BUFSIZ];
E 13
E 10

	strcpy(work, "manx/");
	strcat(work, name);
	strcat(work, ".x");
	last = strlen(work) - 1;
	if (section == '1') {
D 5
		sp = "1nl";
E 5
I 5
D 10
		sp = "1nlo";
E 10
I 10
		sp = SECT1;
E 10
E 5
		section = 0;
	}
D 29
	if (section == 0) {
E 29
I 29
	if (section == 0) {		/* no section or section 1 given */
E 29
D 27
		ss = 0;
E 27
		for (section = *sp++; section; section = *sp++) {
			work[3] = section;
			work[last] = section;
			work[last+1] = 0;
I 10
			work[last+2] = 0;
E 10
D 13
			if (stat(work, &stbuf) >= 0)
E 13
I 13
			if (pathstat(work, path, &stbuf))
E 13
				break;
D 7
			if (work[last] >= '1' && work[last] <= '4') {
E 7
I 7
			if (work[last] >= '1' && work[last] <= '8') {
E 7
				char *cp;
search:
				switch (work[last]) {
D 5
				case '1': cp = "mcgx"; break;
				case '2': cp = "jvx"; break;
D 2
				case '3': cp = "jxmsf"; break;
E 2
I 2
				case '3': cp = "jxmsfn"; break;
E 2
				case '4': cp = "xpfin"; break;
E 5
I 5
D 6
				case '1': cp = "mcgv"; break;
E 6
I 6
D 10
				case '1': cp = "mcgprv"; break;
E 6
				case '2': cp = "v"; break;
D 8
				case '3': cp = "jxmsfnv"; break;
E 8
I 8
				case '3': cp = "jxmsfnvc"; break;
E 8
				case '4': cp = "pfvsn"; break;
				case '8': cp = "vc"; break;
E 10
I 10
				case '1': cp = SUBSEC1; break;
D 26
				case '2': cp = SUBSEC2; break;
E 26
				case '3': cp = SUBSEC3; break;
				case '4': cp = SUBSEC4; break;
				case '8': cp = SUBSEC8; break;
I 18
				default:  cp = ""; break;
E 18
E 10
E 5
				}
				while (*cp) {
					work[last+1] = *cp++;
D 13
					if (stat(work, &stbuf) >= 0) {
E 13
I 13
					if (pathstat(work, path, &stbuf)) {
E 13
						ss = work[last+1];
						goto found;
					}
				}
D 27
				if (ss = 0)
E 27
I 27
				if (ss == 0)
E 27
					work[last+1] = 0;
			}
		}
		if (section == 0) {
			if (sec == 0)
				printf("No manual entry for %s.\n", name);
			else
D 13
				printf("No entry for %s in section %c of the manual.\n", name, sec);
E 13
I 13
				printf("No entry for %s in section %c%s.\n",
				   name, sec, " of the manual");
E 13
			return;
		}
D 29
	} else {
E 29
I 29
	} else {			/* section given */
E 29
		work[3] = section;
		work[last] = section;
		work[last+1] = subsec;
I 10
		work[last+2] = 0;
E 10
D 13
		if (stat(work, &stbuf) < 0) {
E 13
I 13
D 15
		if (pathstat(work, path, &stbuf) < 0) {
E 15
I 15
		if (!pathstat(work, path, &stbuf)) {
E 15
E 13
D 10
			if ((section >= '1' && section <= '4') && subsec == 0) {
E 10
I 10
			if ((section >= '1' && section <= '8') && subsec == 0) {
E 10
				sp = "\0";
				goto search;
			}
I 19
D 29
			else if (section == 'o') {
E 29
I 29
			else if (section == 'o') {	/* XXX */
E 29
				char *cp;
				char sec;
				for (sec = '0'; sec <= '8'; sec++) {
					work[last] = sec;
					if (pathstat(work, path, &stbuf))
						goto found;
					switch (work[last]) {
					case '1': cp = SUBSEC1; break;
D 26
					case '2': cp = SUBSEC2; break;
E 26
					case '3': cp = SUBSEC3; break;
					case '4': cp = SUBSEC4; break;
					case '8': cp = SUBSEC8; break;
					default:  cp = ""; break;
					}
					while (*cp) {
						work[last+1] = *cp++;
						if (pathstat(work, path, &stbuf)) {
							ss = work[last+1];
							goto found;
						}
					}
D 27
					if (ss = 0)
E 27
I 27
					if (ss == 0)
E 27
						work[last+1] = 0;
				}
			}
E 19
			printf("No entry for %s in section %c", name, section);
			if (subsec)
				putchar(subsec);
			printf(" of the manual.\n");
			return;
		}
	}
found:
D 13
	if (troffit)
		troff(work);
	else {
		FILE *it;
		char abuf[BUFSIZ];
E 13
I 13
	sprintf(realname, "%s/%s", path, work);
	if (troffit) {
D 21
		troff(realname);
E 21
I 21
		troff(path, work);
E 21
		return;
	}
	if (!nomore) {
		if ((it = fopen(realname, "r")) == NULL) {
D 19
			perror(realname);
			exit(1);
E 19
I 19
			goto catit;
E 19
		}
		if (fgets(abuf, BUFSIZ-1, it) &&
		   strncmp(abuf, ".so ", 4) == 0) {
			register char *cp = abuf+4;
			char *dp;
E 13

D 13
		if (!nomore) {
			if ((it = fopen(work, "r")) == NULL) {
				perror(work);
				exit(1);
			}
			if (fgets(abuf, BUFSIZ-1, it) &&
			   abuf[0] == '.' && abuf[1] == 's' &&
			   abuf[2] == 'o' && abuf[3] == ' ') {
				register char *cp = abuf+strlen(".so ");
				char *dp;

				while (*cp && *cp != '\n')
					cp++;
				*cp = 0;
				while (cp > abuf && *--cp != '/')
					;
D 4
				dp = ".so /usr/man/man";
E 4
I 4
				dp = ".so man";
E 4
				if (cp != abuf+strlen(dp)+1) {
E 13
I 13
			while (*cp && *cp != '\n')
				cp++;
			*cp = 0;
			while (cp > abuf && *--cp != '/')
				;
			dp = ".so man";
			if (cp != abuf+strlen(dp)+1) {
E 13
tohard:
I 11
D 13
					fclose(it);
E 11
					nomore = 1;
					strcpy(work, abuf+4);
					goto hardway;
				}
				for (cp = abuf; *cp == *dp && *cp; cp++, dp++)
					;
				if (*dp)
					goto tohard;
				strcpy(work, cp-3);
E 13
I 13
				fclose(it);
				nomore = 1;
				strcpy(work, abuf+4);
				goto hardway;
E 13
			}
D 13
			fclose(it);
E 13
I 13
			for (cp = abuf; *cp == *dp && *cp; cp++, dp++)
				;
			if (*dp)
				goto tohard;
			strcpy(work, cp-3);
E 13
D 11
			strcpy(work2, "cat");
			strcpy(work2+3, work+3);
			work2[4] = 0;
			if (stat(work2, &stbuf2) < 0)
E 11
I 11
		}
D 13
		strcpy(work2, "cat");
		work2[3] = work[3];
		work2[4] = 0;
		if (stat(work2, &stbuf2) < 0)
E 13
I 13
		fclose(it);
	}
I 19
catit:
E 19
	strcpy(work2, "cat");
	work2[3] = work[3];
	work2[4] = 0;
	sprintf(realname, "%s/%s", path, work2);
D 14
	if (stat(realname, &stbuf) < 0)
E 14
I 14
	if (stat(realname, &stbuf2) < 0)
E 14
		goto hardway;
	strcpy(work2+4, work+4);
	sprintf(realname, "%s/%s", path, work2);
	if (stat(realname, &stbuf2) < 0 || stbuf2.st_mtime < stbuf.st_mtime) {
		if (nomore)
E 13
			goto hardway;
D 13
		strcpy(work2+4, work+4);
		if (stat(work2, &stbuf2) < 0 || stbuf2.st_mtime < stbuf.st_mtime) {
			if (nomore)
E 11
				goto hardway;
D 11
			strcpy(work2+3, work+3);
			if (stat(work2, &stbuf2) < 0 || stbuf2.st_mtime < stbuf.st_mtime) {
				printf("Reformatting page.  Wait...");
				fflush(stdout);
				unlink(work2);
				sprintf(cmdbuf,
D 10
"nroff -h -man %s > /tmp/man%d; trap '' 1 15; mv /tmp/man%d %s", work, getpid(), getpid(), work2);
E 10
I 10
			"%s %s > /tmp/man%d; trap '' 1 15; mv /tmp/man%d %s",
				    NROFFCAT, work, getpid(), getpid(), work2);
E 10
				if (system(cmdbuf)) {
					printf(" aborted (sorry)\n");
					remove();
					/*NOTREACHED*/
				}
				printf(" done\n");
E 11
I 11
			printf("Reformatting page.  Wait...");
			fflush(stdout);
			unlink(work2);
			sprintf(cmdbuf,
		"%s %s > /tmp/man%d; trap '' 1 15; /bin/mv /tmp/man%d %s",
				NROFFCAT, work, getpid(), getpid(), work2);
			if (system(cmdbuf, 0)) {
				printf(" aborted (sorry)\n");
				remove();
				/*NOTREACHED*/
E 11
			}
D 11
			strcpy(work, work2);
E 11
I 11
			printf(" done\n");
E 13
I 13
		printf("Reformatting page.  Wait...");
		fflush(stdout);
D 31
		unlink(work2);
E 31
I 22
		if (signal(SIGINT, SIG_IGN) == SIG_DFL) {
D 27
			signal(SIGINT, remove);
			signal(SIGQUIT, remove);
			signal(SIGTERM, remove);
E 27
I 27
			(void) signal(SIGINT, remove);
			(void) signal(SIGQUIT, remove);
			(void) signal(SIGTERM, remove);
E 27
		}
E 22
D 19
		sprintf(cmdbuf,
	"%s %s/%s > /tmp/man%d; trap '' 1 15; /bin/mv /tmp/man%d %s/%s",
			NROFFCAT, path, work, getpid(), getpid(), path, work2);
E 19
I 19
		sprintf(cmdbuf, "%s %s/%s > /tmp/man%d; trap '' 1 15",
D 30
			NROFFCAT, path, work, mypid);
E 30
I 30
			NROFF, path, work, mypid);
E 30
E 19
D 27
		if (system(cmdbuf, 0)) {
E 27
I 27
		if (system(cmdbuf)) {
E 27
			printf(" aborted (sorry)\n");
			remove();
			/*NOTREACHED*/
E 13
E 11
		}
I 19
D 23
		sprintf(cmdbuf, "/bin/mv /tmp/man%d %s/%s 2>/dev/null",
E 23
I 23
		sprintf(cmdbuf, "/bin/mv -f /tmp/man%d %s/%s 2>/dev/null",
E 23
			mypid, path, work2);
D 27
		if (system(cmdbuf, 0)) {
E 27
I 27
		if (system(cmdbuf)) {
E 27
			sprintf(path,  "/");
			sprintf(work2, "tmp/man%d", mypid);
		}
E 19
I 11
D 13
		strcpy(work, work2);
E 13
I 13
		printf(" done\n");
	}
	strcpy(work, work2);
E 13
E 11
hardway:
D 13
		nroff(work);
E 13
I 13
D 16
	sprintf(realname, "%s/%s", path, work);
	nroff(realname);
E 16
I 16
	nroff(path, work);
I 19
	if (work2[0] == 't')
		remove();
E 19
E 16
}

/*
 * Use the manpath to look for
 * the file name.  The result of
 * stat is returned in stbuf, the
 * successful path in path.
 */
pathstat(name, path, stbuf)
	char *name, path[];
	struct stat *stbuf;
{
	char *cp, *tp, *ep;
I 19
	char **cpp;
	static char *manpaths[] = {"man", "cat", 0};
D 29
	static char *nopaths[]  = {"",    0};
E 29
I 29
	static char *nopaths[]  = {"", 0};
E 29
E 19

D 19
	for (cp = manpath; cp && *cp; cp = tp) {
		tp = index(cp, ':');
		if (tp) {
			if (tp == cp)
				strcpy(path, name);
			else
				sprintf(path, "%.*s/%s", tp-cp, cp, name);
			ep = path + (tp-cp);
			tp++;
		} else {
			sprintf(path, "%s/%s", cp, name);
			ep = path + strlen(cp);
E 19
I 19
	if (strncmp(name, "man", 3) == 0)
		cpp = manpaths;
	else
		cpp = nopaths;
	for ( ; *cpp ; cpp++) {
		for (cp = manpath; cp && *cp; cp = tp) {
			tp = index(cp, ':');
			if (tp) {
				if (tp == cp) {
					sprintf(path, "%s%s", *cpp,
						name+strlen(*cpp));
				}
				else {
					sprintf(path, "%.*s/%s%s", tp-cp, cp, 
						*cpp, name+strlen(*cpp));
				}
				ep = path + (tp-cp);
				tp++;
			} else {
				sprintf(path, "%s/%s%s", cp, *cpp,
					name+strlen(*cpp));
				ep = path + strlen(cp);
			}
			if (stat(path, stbuf) >= 0) {
				*ep = '\0';
				return (1);
			}
E 19
		}
D 19
		if (stat(path, stbuf) >= 0) {
			*ep = '\0';
			return (1);
		}
E 19
E 13
	}
I 13
	return (0);
E 13
}

D 16
nroff(cp)
	char *cp;
E 16
I 16
nroff(pp, wp)
	char *pp, *wp;
E 16
{
	char cmd[BUFSIZ];

I 21
	chdir(pp);
E 21
D 10
	sprintf(cmd, nomore ?
	    "%s %s" : "%s %s|/usr/ucb/ul|/usr/ucb/more -f",
	    cp[0] == 'c' ? "cat -s" : "nroff -man", cp);
E 10
I 10
D 16
	if (cp[0] == 'c')
		sprintf(cmd, "%s %s", nomore? CAT : MORE, cp);
E 16
I 16
D 19
	if (wp[0] == 'c')
E 19
I 19
	if (wp[0] == 'c' || wp[0] == 't')
E 19
D 21
		sprintf(cmd, "%s %s/%s", nomore? CAT : MORE, pp, wp);
E 21
I 21
		sprintf(cmd, "%s %s", nomore? CAT : MORE, wp);
E 21
E 16
	else
D 16
		sprintf(cmd, nomore? "%s %s" : "%s %s|%s", NROFF, cp, MORE);
E 16
I 16
D 21
		sprintf(cmd, nomore? "%s %s/%s" : "%s %s/%s|%s", NROFF, pp, wp, MORE);
E 21
I 21
		sprintf(cmd, nomore? "%s %s" : "%s %s|%s", NROFF, wp, MORE);
E 21
E 16
E 10
D 27
	system(cmd);
E 27
I 27
	(void) system(cmd);
E 27
}

D 21
troff(cp)
	char *cp;
E 21
I 21
troff(pp, wp)
	char *pp, *wp;
E 21
{
	char cmdbuf[BUFSIZ];

D 10
	sprintf(cmdbuf,
"troff -t -man /usr/lib/tmac/tmac.vcat %s|/usr/lib/rvsort|/usr/ucb/vpr -t",
		cp);
E 10
I 10
D 21
	sprintf(cmdbuf, TROFFCMD, cp);
E 21
I 21
	chdir(pp);
	sprintf(cmdbuf, TROFFCMD, wp);
E 21
E 10
D 27
	system(cmdbuf);
E 27
I 27
	(void) system(cmdbuf);
E 27
}

any(c, sp)
	register int c;
	register char *sp;
{
	register int d;

	while (d = *sp++)
		if (c == d)
			return (1);
	return (0);
}

remove()
{
	char name[15];

D 19
	sprintf(name, "/tmp/man%d", getpid());
E 19
I 19
	sprintf(name, "/tmp/man%d", mypid);
E 19
	unlink(name);
	exit(1);
}

I 27
unsigned int
blklen(ip)
	register char **ip;
{
	register unsigned int i = 0;

	while (*ip++)
		i++;
	return (i);
}

E 27
apropos(argc, argv)
	int argc;
	char **argv;
{
D 13
	char buf[BUFSIZ];
	char *gotit;
E 13
I 13
	char buf[BUFSIZ], file[MAXPATHLEN+1];
	char *gotit, *cp, *tp;
E 13
	register char **vp;
I 13
D 24
	int more;
E 24
E 13

	if (argc == 0) {
D 10
		fprintf(stderr, "man: -k what?\n");
E 10
I 10
		fprintf(stderr, "apropos what?\n");
E 10
		exit(1);
	}
D 13
	if (freopen("/usr/lib/whatis", "r", stdin) == NULL) {
		perror("/usr/lib/whatis");
		exit (1);
	}
E 13
D 27
	gotit = (char *) calloc(1, blklen(argv));
E 27
I 27
	gotit = calloc(1, blklen(argv));
E 27
D 13
	while (fgets(buf, sizeof buf, stdin) != NULL)
E 13
I 13
D 24
	for (more = 1, cp = manpath; more && cp; cp = tp) {
E 24
I 24
	for (cp = manpath; cp; cp = tp) {
E 24
		tp = index(cp, ':');
		if (tp) {
			if (tp == cp)
				strcpy(file, WHATIS);
			else
				sprintf(file, "%.*s/%s", tp-cp, cp, WHATIS);
			tp++;
		} else
			sprintf(file, "%s/%s", cp, WHATIS);
		if (freopen(file, "r", stdin) == NULL)
			continue;
		while (fgets(buf, sizeof buf, stdin) != NULL)
			for (vp = argv; *vp; vp++)
				if (match(buf, *vp)) {
					printf("%s", buf);
					gotit[vp - argv] = 1;
					for (vp++; *vp; vp++)
						if (match(buf, *vp))
							gotit[vp - argv] = 1;
					break;
				}
D 24
		more = 0;
E 13
		for (vp = argv; *vp; vp++)
D 13
			if (match(buf, *vp)) {
				printf("%s", buf);
				gotit[vp - argv] = 1;
				for (vp++; *vp; vp++)
					if (match(buf, *vp))
						gotit[vp - argv] = 1;
				break;
			}
E 13
I 13
			if (gotit[vp - argv] == 0)
				more = 1;
E 24
	}
E 13
	for (vp = argv; *vp; vp++)
		if (gotit[vp - argv] == 0)
D 12
			printf("%s: nothing apropriate\n", *vp);
E 12
I 12
			printf("%s: nothing appropriate\n", *vp);
E 12
}

D 24
match(buf, str)
	char *buf, *str;
E 24
I 24
match(bp, str)
	register char *bp;
	char *str;
E 24
{
D 24
	register char *bp, *cp;
E 24

D 24
	bp = buf;
E 24
	for (;;) {
		if (*bp == 0)
			return (0);
		if (amatch(bp, str))
			return (1);
		bp++;
	}
}

amatch(cp, dp)
	register char *cp, *dp;
{

	while (*cp && *dp && lmatch(*cp, *dp))
		cp++, dp++;
	if (*dp == 0)
		return (1);
	return (0);
}

lmatch(c, d)
D 24
	char c, d;
E 24
I 24
	register int c, d;
E 24
{

	if (c == d)
		return (1);
	if (!isalpha(c) || !isalpha(d))
		return (0);
	if (islower(c))
		c = toupper(c);
	if (islower(d))
		d = toupper(d);
	return (c == d);
}

D 27
blklen(ip)
	register int *ip;
{
	register int i = 0;

	while (*ip++)
		i++;
	return (i);
}

E 27
whatis(argc, argv)
	int argc;
	char **argv;
{
D 13
	register char **avp;
E 13
I 13
	register char *gotit, **vp;
	char buf[BUFSIZ], file[MAXPATHLEN+1], *cp, *tp;
D 29
	int more;
E 29
E 13

	if (argc == 0) {
D 10
		fprintf(stderr, "man: -f what?\n");
E 10
I 10
		fprintf(stderr, "whatis what?\n");
E 10
		exit(1);
	}
D 13
	if (freopen("/usr/lib/whatis", "r", stdin) == NULL) {
		perror("/usr/lib/whatis");
		exit (1);
	}
	for (avp = argv; *avp; avp++)
		*avp = trim(*avp);
	whatisit(argv);
	exit(0);
}

whatisit(argv)
	char **argv;
{
	char buf[BUFSIZ];
	register char *gotit;
	register char **vp;

E 13
I 13
	for (vp = argv; *vp; vp++)
		*vp = trim(*vp);
E 13
D 24
	gotit = (char *)calloc(1, blklen(argv));
E 24
I 24
D 27
	gotit = (char *) calloc(1, blklen(argv));
E 27
I 27
	gotit = calloc(1, blklen(argv));
E 27
E 24
D 13
	while (fgets(buf, sizeof buf, stdin) != NULL)
E 13
I 13
D 29
	for (more = 1, cp = manpath; more && cp; cp = tp) {
E 29
I 29
	for (cp = manpath; cp; cp = tp) {
E 29
		tp = index(cp, ':');
		if (tp) {
			if (tp == cp)
				strcpy(file, WHATIS);
			else
				sprintf(file, "%.*s/%s", tp-cp, cp, WHATIS);
			tp++;
		} else
			sprintf(file, "%s/%s", cp, WHATIS);
		if (freopen(file, "r", stdin) == NULL)
			continue;
		while (fgets(buf, sizeof buf, stdin) != NULL)
			for (vp = argv; *vp; vp++)
				if (wmatch(buf, *vp)) {
					printf("%s", buf);
					gotit[vp - argv] = 1;
					for (vp++; *vp; vp++)
						if (wmatch(buf, *vp))
							gotit[vp - argv] = 1;
					break;
				}
D 29
		more = 0;
E 13
		for (vp = argv; *vp; vp++)
D 13
			if (wmatch(buf, *vp)) {
				printf("%s", buf);
				gotit[vp - argv] = 1;
				for (vp++; *vp; vp++)
					if (wmatch(buf, *vp))
						gotit[vp - argv] = 1;
				break;
			}
E 13
I 13
			if (gotit[vp - argv] == 0)
				more = 1;
E 29
	}
E 13
	for (vp = argv; *vp; vp++)
		if (gotit[vp - argv] == 0)
			printf("%s: not found\n", *vp);
}

wmatch(buf, str)
	char *buf, *str;
{
	register char *bp, *cp;

	bp = buf;
again:
	cp = str;
	while (*bp && *cp && lmatch(*bp, *cp))
		bp++, cp++;
	if (*cp == 0 && (*bp == '(' || *bp == ',' || *bp == '\t' || *bp == ' '))
		return (1);
	while (isalpha(*bp) || isdigit(*bp))
		bp++;
	if (*bp != ',')
		return (0);
	bp++;
	while (isspace(*bp))
		bp++;
	goto again;
}

char *
trim(cp)
	register char *cp;
{
	register char *dp;

	for (dp = cp; *dp; dp++)
		if (*dp == '/')
			cp = dp + 1;
	if (cp[0] != '.') {
D 13
		if (cp + 3 <= dp && dp[-2] == '.' && any(dp[-1], "cosa12345678npP"))
E 13
I 13
		if (cp + 3 <= dp && dp[-2] == '.' &&
		    any(dp[-1], "cosa12345678npP"))
E 13
			dp[-2] = 0;
D 13
		if (cp + 4 <= dp && dp[-3] == '.' && any(dp[-2], "13") && isalpha(dp[-1]))
E 13
I 13
		if (cp + 4 <= dp && dp[-3] == '.' &&
		    any(dp[-2], "13") && isalpha(dp[-1]))
E 13
			dp[-3] = 0;
	}
	return (cp);
D 22
}

system(s)
char *s;
{
	int status, pid, w;
I 11
	int (*saveintr)(), (*savequit)();
E 11

	if ((pid = vfork()) == 0) {
		execl("/bin/sh", "sh", "-c", s, 0);
		_exit(127);
	}
I 11
	saveintr = signal (SIGINT, SIG_IGN);
	savequit = signal (SIGQUIT, SIG_IGN);
E 11
	while ((w = wait(&status)) != pid && w != -1)
		;
I 11
	(void) signal (SIGQUIT, saveintr);
	(void) signal (SIGQUIT, savequit);
E 11
	if (w == -1)
		status = -1;
	return (status);
E 22
}
E 1
