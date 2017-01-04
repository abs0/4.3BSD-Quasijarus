h24886
s 00001/00001/00154
d D 5.4 87/10/22 09:59:09 bostic 13 12
c ANSI C; sprintf now returns an int.
e
s 00001/00001/00154
d D 5.3 86/04/20 05:30:40 lepreau 12 11
c ^G -> \007
e
s 00013/00007/00142
d D 5.2 85/06/04 00:25:02 bloom 11 9
c add support for arbitrary number of utmp entries
e
s 00013/00007/00142
d R 5.2 85/06/03 11:14:55 bloom 10 9
c add support for arbitrary number of utmp entries
e
s 00016/00001/00133
d D 5.1 85/05/02 14:49:10 dist 9 8
c 
e
s 00067/00056/00067
d D 4.8 84/03/30 11:27:45 ralph 8 7
c use non-blocking I/O instead of forking so much.
e
s 00001/00001/00122
d D 4.7 83/07/01 23:57:09 wnj 7 6
c include problems
e
s 00003/00012/00120
d D 4.6 82/03/15 04:19:28 root 6 5
c machine independent
e
s 00003/00001/00129
d D 4.5 81/06/12 13:23:15 root 5 4
c I suppressed wall messages to the sleeper program
e
s 00001/00001/00129
d D 4.4 81/05/06 18:44:43 mark 4 3
c 2nd try at delta from last bug fix
e
s 00000/00000/00130
d D 4.3 81/05/06 18:43:04 mark 3 2
c fixed portability bug - time(0) returns a long.
e
s 00039/00015/00091
d D 4.2 81/03/10 07:02:14 wnj 2 1
c miscellaneous minor fixups
e
s 00106/00000/00000
d D 4.1 80/10/01 17:29:26 bill 1 0
c date and time created 80/10/01 17:29:26 by bill
e
u
U
t
T
I 1
D 2
static char *sccsid = "%W% (Berkeley) %G%";
E 2
I 2
D 9
static char *sccsid = "%W% (Berkeley) %E%";
E 9
I 9
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 9
E 2
/*
 * wall.c - Broadcast a message to all users.
 *
 * This program is not related to David Wall, whose Stanford Ph.D. thesis
 * is entitled "Mechanisms for Broadcast and Selective Broadcast".
 */

#include <stdio.h>
#include <utmp.h>
D 7
#include <time.h>
E 7
I 7
D 8
#include <sys/time.h>
E 8
I 8
#include <errno.h>
E 8
E 7
I 2
D 6
#include <whoami.h>
E 6
#include <signal.h>
I 8
#include <sys/time.h>
#include <fcntl.h>
I 11
#include <sys/types.h>
#include <sys/stat.h>
E 11

E 8
E 2
D 11
#define	USERS	128
E 11
I 5
#define IGNOREUSER	"sleeper"
E 5

I 6
char	hostname[32];
E 6
char	mesg[3000];
int	msize,sline;
D 11
struct	utmp utmp[USERS];
E 11
I 11
struct	utmp *utmp;
E 11
char	*strcpy();
char	*strcat();
I 11
char	*malloc();
E 11
D 8
char who[9] = "???";
E 8
I 8
char	who[9] = "???";
E 8
D 4
long	clock;
E 4
I 4
long	clock, time();
E 4
struct tm *localtime();
struct tm *localclock;

I 8
extern	errno;

E 8
main(argc, argv)
char *argv[];
{
D 8
	register i;
	register char c;
E 8
I 8
	register int i, c;
E 8
	register struct utmp *p;
D 11
	FILE *f;
E 11
I 11
	int f;
	struct stat statb;
E 11
I 2
D 8
	FILE *mf;
E 8
E 2

I 6
D 11
	gethostname(hostname, sizeof (hostname));
E 6
D 8
	if((f = fopen("/etc/utmp", "r")) == NULL) {
E 8
I 8
	if ((f = fopen("/etc/utmp", "r")) == NULL) {
E 11
I 11
	(void) gethostname(hostname, sizeof (hostname));
	if ((f = open("/etc/utmp", O_RDONLY, 0)) < 0) {
E 11
E 8
		fprintf(stderr, "Cannot open /etc/utmp\n");
		exit(1);
	}
	clock = time( 0 );
	localclock = localtime( &clock );
D 2
	fread((char *)utmp, sizeof(struct utmp), USERS, f);
	fclose(f);
	f = stdin;
E 2
I 2
D 8
	mf = stdin;
E 2
	if(argc >= 2) {
E 8
I 8
	sline = ttyslot();	/* 'utmp' slot no. of sender */
D 11
	c = fread((char *)utmp, sizeof(struct utmp), USERS, f);
	fclose(f);
E 11
I 11
	(void) fstat(f, &statb);
	utmp = (struct utmp *)malloc(statb.st_size);
	c = read(f, (char *)utmp, statb.st_size);
	(void) close(f);
	c /= sizeof(struct utmp);
E 11
	if (sline)
		strncpy(who, utmp[sline].ut_name, sizeof(utmp[sline].ut_name));
D 13
	sprintf(mesg,
E 13
I 13
	(void)sprintf(mesg,
E 13
D 12
	    "\nBroadcast Message from %s@%s (%.*s) at %d:%02d ...\r\n\n"
E 12
I 12
	    "\n\007\007Broadcast Message from %s@%s (%.*s) at %d:%02d ...\r\n\n"
E 12
		, who
		, hostname
		, sizeof(utmp[sline].ut_line)
		, utmp[sline].ut_line
		, localclock -> tm_hour
		, localclock -> tm_min
	);
	msize = strlen(mesg);
	if (argc >= 2) {
E 8
		/* take message from unix file instead of standard input */
D 2
		if((f = fopen(argv[1], "r")) == NULL) {
E 2
I 2
D 8
		if((mf = fopen(argv[1], "r")) == NULL) {
E 2
			fprintf(stderr,"Cannot open %s\n", argv[1]);
E 8
I 8
		if (freopen(argv[1], "r", stdin) == NULL) {
			perror(argv[1]);
E 8
			exit(1);
		}
	}
D 2
	while((i = getc(f)) != EOF) mesg[msize++] = i;
	fclose(f);
	sline = ttyslot(2); /* 'utmp' slot no. of sender */
	if (sline) {
		for (i=0;(c=utmp[sline].ut_name[i]) && i<sizeof(utmp[0].ut_name);i++)
			who[i]=c;
		who[i] = '\0'; /* sender initials */
E 2
I 2
D 8
	while((i = getc(mf)) != EOF) {
E 8
I 8
	while ((i = getchar()) != EOF) {
		if (i == '\n')
			mesg[msize++] = '\r';
E 8
		if (msize >= sizeof mesg) {
			fprintf(stderr, "Message too long\n");
			exit(1);
E 2
		}
I 2
		mesg[msize++] = i;
	}
D 8
	fclose(mf);
	sline = ttyslot(2); /* 'utmp' slot no. of sender */
	fread((char *)utmp, sizeof(struct utmp), USERS, f);
	fclose(f);
	if (sline)
		strncpy(who, utmp[sline].ut_name, sizeof(utmp[sline].ut_name));
E 2
	for(i=0; i<USERS; i++) {
E 8
I 8
	fclose(stdin);
	for (i=0; i<c; i++) {
E 8
		p = &utmp[i];
D 5
		if(p->ut_name[0] == 0)
E 5
I 5
D 8
		if ((p->ut_name[0] == 0) ||
		    (strncmp (p->ut_name, IGNOREUSER, sizeof(p->ut_name)) == 0))
E 8
I 8
		if (p->ut_name[0] == 0 ||
		    strncmp(p->ut_name, IGNOREUSER, sizeof(p->ut_name)) == 0)
E 8
E 5
			continue;
I 2
D 6
	/***		this might be nice, but utmp gets so out of date !!
E 2
		sleep(1);
I 2
	***/
E 6
E 2
		sendmes(p->ut_line);
	}
	exit(0);
}

sendmes(tty)
char *tty;
{
D 8
	register i;
	char t[50], buf[BUFSIZ];
	register char *cp;
	register int c, ch;
	FILE *f;
E 8
I 8
	register f, flags;
	static char t[50] = "/dev/";
	int e, i;
E 8

I 8
	strcpy(t + 5, tty);

	if ((f = open(t, O_WRONLY|O_NDELAY)) < 0) {
		if (errno != EWOULDBLOCK)
			perror(t);
		return;
	}
	if ((flags = fcntl(f, F_GETFL, 0)) == -1) {
		perror(t);
		return;
	}
	if (fcntl(f, F_SETFL, flags | FNDELAY) == -1)
		goto oldway;
	i = write(f, mesg, msize);
	e = errno;
	(void) fcntl(f, F_SETFL, flags);
	if (i == msize) {
		(void) close(f);
		return;
	}
	if (e != EWOULDBLOCK) {
		errno = e;
		perror(t);
		(void) close(f);
		return;
	}
oldway:
E 8
I 2
D 6
/***			you can't do this with lots of users & MAXUPROC
E 2
	i = fork();
	if(i == -1) {
		fprintf(stderr, "Try again\n");
		return;
	}
I 2
 ***/
E 6
	while ((i = fork()) == -1)
		if (wait((int *)0) == -1) {
			fprintf(stderr, "Try again\n");
			return;
		}
E 2
D 8
	if(i)
E 8
I 8
	if (i) {
		(void) close(f);
E 8
		return;
D 8
	strcpy(t, "/dev/");
	strcat(t, tty);

I 2
	signal(SIGALRM, SIG_DFL);	/* blow away if open hangs */
	alarm(10);

E 2
	if((f = fopen(t, "w")) == NULL) {
		fprintf(stderr,"cannot open %s\n", t);
		exit(1);
E 8
	}
D 8
	setbuf(f, buf);
D 2
	fprintf(f, "\nBroadcast Message from %s (%s) at %d:%02d ...\r\n\n"
	       ,who, utmp[sline].ut_line
	       , localclock -> tm_hour , localclock -> tm_min );
E 2
I 2
	fprintf(f,
	    "\nBroadcast Message from %s!%s (%.*s) at %d:%02d ...\r\n\n"
D 6
		, sysname
E 6
I 6
		, hostname
E 6
		, who
		, sizeof(utmp[sline].ut_line)
		, utmp[sline].ut_line
		, localclock -> tm_hour
		, localclock -> tm_min
	);
E 2
	/* fwrite(mesg, msize, 1, f); */
	for (cp = mesg, c = msize; c-- > 0; cp++) {
		ch = *cp;
		if (ch == '\n')
			putc('\r', f);
		putc(ch, f);
	}
E 8

D 8
	/*
	 * Bitchin'.
	 */

E 8
I 8
	(void) write(f, mesg, msize);
E 8
	exit(0);
}
E 1
