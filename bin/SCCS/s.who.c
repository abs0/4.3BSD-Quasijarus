h63877
s 00003/00003/00096
d D 5.4 88/04/20 10:49:47 bostic 10 9
c report utmp file name if can't open; bug report 4.2BSD/bin/176
e
s 00059/00064/00040
d D 5.3 87/04/06 14:49:55 karels 9 8
c reformat to standards; guess if not logged in
e
s 00064/00053/00040
d D 5.2 86/12/10 16:41:00 bostic 8 7
c general cleanup
e
s 00015/00002/00078
d D 5.1 85/05/02 14:49:27 dist 7 6
c 
e
s 00001/00001/00079
d D 4.6 83/08/19 16:19:33 sam 6 5
c incorrect max login name size
e
s 00013/00005/00067
d D 4.5 83/05/23 00:03:07 sam 5 4
c utmp format changed; show host for remote logins now
e
s 00010/00008/00062
d D 4.4 82/03/15 04:24:00 root 4 3
c machine independent
e
s 00001/00003/00069
d D 4.3 81/03/11 18:49:31 toy 3 2
c print machine!name, not (machine) name
e
s 00006/00003/00066
d D 4.2 80/11/01 14:54:39 bill 2 1
c Have who reflect identity of the system.
e
s 00069/00000/00000
d D 4.1 80/10/01 17:29:35 bill 1 0
c date and time created 80/10/01 17:29:35 by bill
e
u
U
t
T
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 7
I 5
#ifndef lint
E 5
I 1
D 7
static char *sccsid = "%W% (Berkeley) %G%";
I 5
#endif
E 7
I 7
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 7
E 5
/*
 * who
 */

D 8
#include <stdio.h>
E 8
I 8
D 9
#include <sys/param.h>
E 9
I 9
#include <stdio.h>
E 9
E 8
#include <utmp.h>
#include <pwd.h>
I 8
D 9
#include <stdio.h>
#include <strings.h>
E 9
E 8
I 2
D 4
#include <whoami.h>
E 4
#include <ctype.h>
E 2

D 8
#define NMAX sizeof(utmp.ut_name)
#define LMAX sizeof(utmp.ut_line)
I 5
#define	HMAX sizeof(utmp.ut_host)
E 8
I 8
D 9
#define NMAX	sizeof(utmp.ut_name)
#define LMAX	sizeof(utmp.ut_line)
#define HMAX	sizeof(utmp.ut_host)
E 9
I 9
#define NMAX sizeof(utmp.ut_name)
#define LMAX sizeof(utmp.ut_line)
#define	HMAX sizeof(utmp.ut_host)
E 9
E 8
E 5

D 4
struct utmp utmp;
struct passwd *pw;
struct passwd *getpwuid();
E 4
I 4
D 8
struct	utmp utmp;
struct	passwd *pw;
struct	passwd *getpwuid();
char	hostname[32];
E 8
I 8
D 9
static struct utmp	utmp;		/* read buffer */
E 9
I 9
struct	utmp utmp;
struct	passwd *pw;
struct	passwd *getpwuid();
E 9
E 8
E 4

D 4
char *ttyname(), *rindex(), *ctime(), *strcpy();
E 4
I 4
D 8
char	*ttyname(), *rindex(), *ctime(), *strcpy();

E 4
main(argc, argv)
D 4
char **argv;
E 4
I 4
	int argc;
	char **argv;
E 8
I 8
D 9
main(argc,argv)
int	argc;
char	**argv;
E 9
I 9
char	*ttyname(), *rindex(), *ctime(), *strcpy();

main(argc, argv)
	int argc;
	char **argv;
E 9
E 8
E 4
{
D 8
	register char *tp, *s;
	register FILE *fi;
	extern char _sobuf[];
E 8
I 8
D 9
	register FILE	*fp;			/* utmp file pointer */
	register char	*tp,			/* tty name */
			*fname;			/* utmp file name */
	struct passwd	*pw,			/* user passwd structure */
			*getpwuid();
	char	hostname[MAXHOSTNAMELEN],	/* host name */
		*ttyname();
	uid_t	getuid();
	long	time();
E 9
I 9
	register char *tp, *s;
	register FILE *fi;
E 9
E 8

D 8
	setbuf(stdout, _sobuf);
	s = "/etc/utmp";
	if(argc == 2)
		s = argv[1];
D 5
	if (argc==3) {
E 5
I 5
	if (argc == 3) {
E 5
		tp = ttyname(0);
		if (tp)
			tp = rindex(tp, '/') + 1;
		else {	/* no tty - use best guess from passwd file */
			pw = getpwuid(getuid());
D 6
			strcpy(utmp.ut_name, pw?pw->pw_name: "?");
E 6
I 6
			strncpy(utmp.ut_name, pw ? pw->pw_name : "?", NMAX);
E 6
			strcpy(utmp.ut_line, "tty??");
			time(&utmp.ut_time);
			putline();
			exit(0);
		}
E 8
I 8
D 9
	switch(argc) {
		case 2:
			fname = argv[1];
			break;
		case 3:
			if (!(tp = ttyname(0))) {
				/*
				 * no tty -- use best guess from passwd file.
				 * next line is a kludge, but as of now getuid
				 * returns a "uid_t" and getpwuid takes an int.
				 */
				pw = getpwuid((int)getuid());
				strncpy(utmp.ut_name,pw ? pw->pw_name : "?",NMAX);
				strcpy(utmp.ut_line,"tty??");
				time(&utmp.ut_time);
				putline();
				exit(0);
			}
			tp = rindex(tp,'/') + 1;
			if (gethostname(hostname,sizeof(hostname)) == -1) {
				perror("gethostname");
				exit(1);
			}
		case 1:
			fname = "/etc/utmp";
			break;
		default:
			fputs("usage: who [ utmp_file ]\nor who am i\n",stderr);
			exit(1);
E 9
I 9
	s = "/etc/utmp";
	if(argc == 2)
		s = argv[1];
	if (argc == 3) {
		tp = ttyname(0);
		if (tp)
			tp = rindex(tp, '/') + 1;
		else {	/* no tty - use best guess from passwd file */
D 10
			strcpy(utmp.ut_line, "tty??");
E 10
I 10
			(void)strcpy(utmp.ut_line, "tty??");
E 10
			guess();
			exit(0);
		}
E 9
E 8
	}
D 8
	if ((fi = fopen(s, "r")) == NULL) {
		puts("who: cannot open utmp");
E 8
I 8
D 9
	if (!(fp = fopen(fname,"r"))) {
		perror(fname);
E 9
I 9
D 10
	if ((fi = fopen(s, "r")) == NULL) {
		puts("who: cannot open utmp");
E 10
I 10
	if (!(fi = fopen(s, "r"))) {
		fprintf(stderr, "who: cannot read %s.\n", s);
E 10
E 9
E 8
		exit(1);
	}
D 8
	while (fread((char *)&utmp, sizeof(utmp), 1, fi) == 1) {
E 8
I 8
D 9
	while (fread((char *)&utmp,sizeof(utmp),1,fp) == 1)
E 9
I 9
	while (fread((char *)&utmp, sizeof(utmp), 1, fi) == 1) {
E 9
E 8
D 5
		if(argc==3) {
E 5
I 5
		if (argc == 3) {
E 5
I 2
D 4
			static char myname[]=sysname;
E 4
I 4
D 8
			gethostname(hostname, sizeof (hostname));
E 4
E 2
			if (strcmp(utmp.ut_line, tp))
				continue;
D 2
#ifdef vax
			printf("(Vax) ");
#endif
E 2
I 2
D 3
			if (islower(*myname))
				*myname = toupper(*myname);
			printf("(%s) ",myname);
E 3
I 3
D 4
			printf("%s!",myname);
E 4
I 4
			printf("%s!", hostname);
E 4
E 3
E 2
			putline();
			exit(0);
E 8
I 8
D 9
			if (!strcmp(utmp.ut_line,tp)) {
				printf("%s!",hostname);
				putline();
				exit(0);
			}
E 8
		}
D 5
		if(utmp.ut_name[0] == '\0' && argc==1)
E 5
I 5
D 8
		if (utmp.ut_name[0] == '\0' && argc == 1)
E 5
			continue;
		putline();
	}
E 8
I 8
		else if (argc != 1 || *utmp.ut_name)
E 9
I 9
			if (strcmp(utmp.ut_line, tp))
				continue;
E 9
			putline();
I 9
			exit(0);
		}
		if (utmp.ut_name[0] == '\0' && argc == 1)
			continue;
		putline();
	}
	if (argc == 3) {
		strncpy(utmp.ut_line, tp, sizeof(utmp.ut_line));
		guess();
	}
	exit(0);
E 9
E 8
}

putline()
{
D 8
	register char *cbuf;
E 8
I 8
D 9
	register char	*cbuf;
	char	*ctime();
E 9
I 9
	register char *cbuf;
E 9
E 8

D 5
	printf("%-*.*s %-*.*s", NMAX, NMAX, utmp.ut_name, LMAX, LMAX, utmp.ut_line);
E 5
I 5
D 8
	printf("%-*.*s %-*.*s",
		NMAX, NMAX, utmp.ut_name,
		LMAX, LMAX, utmp.ut_line);
E 5
	cbuf = ctime(&utmp.ut_time);
D 5
	printf("%.12s\n", cbuf+4);
E 5
I 5
	printf("%.12s", cbuf+4);
	if (utmp.ut_host[0])
		printf("\t(%.*s)", HMAX, utmp.ut_host);
E 8
I 8
D 9
	cbuf = ctime(&utmp.ut_time) + 4;
	printf("%-*.*s %-*.*s%.12s",NMAX,NMAX,utmp.ut_name,LMAX,LMAX,utmp.ut_line,cbuf);
	if (*utmp.ut_host)
		printf("\t(%.*s)",HMAX,utmp.ut_host);
E 9
I 9
	printf("%-*.*s %-*.*s",
		NMAX, NMAX, utmp.ut_name,
		LMAX, LMAX, utmp.ut_line);
	cbuf = ctime(&utmp.ut_time);
	printf("%.12s", cbuf+4);
	if (utmp.ut_host[0])
		printf("\t(%.*s)", HMAX, utmp.ut_host);
E 9
E 8
	putchar('\n');
I 9
}

guess()
{

	pw = getpwuid(getuid());
	strncpy(utmp.ut_name, pw ? pw->pw_name : "?", NMAX);
	time(&utmp.ut_time);
	putline();
E 9
E 5
}
E 1
