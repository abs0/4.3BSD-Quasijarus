h63850
s 00086/00171/00063
d D 5.4 88/07/07 16:13:18 bostic 8 7
c arg parsing error; bug report 4.3BSD/ucb/227.  Anyway, leave didn't need
c V6 compatibility, its own sleep routine, or getlogin().  Int pointers
c into struct tm's aren't nice.  Not much of the original code left.
e
s 00010/00005/00224
d D 5.3 88/06/29 21:50:51 bostic 7 6
c install approved copyright notice
e
s 00046/00018/00183
d D 5.2 87/12/02 14:53:01 bostic 6 5
c bug report 4.3BSD/ucb/148; null pointer dereference, syntax checking
c on "hhmm" value, use stderr for error messages add Berkeley specific
c header, originally written by Mark Horton.
e
s 00016/00001/00185
d D 5.1 85/05/31 09:18:56 dist 5 4
c Add copyright
e
s 00055/00042/00131
d D 4.4 84/06/06 15:12:44 ralph 4 3
c fix +hhmm option.
e
s 00005/00003/00168
d D 4.3 83/03/31 11:56:44 edward 3 2
c Fixed to ignore SIGTTOU.
e
s 00000/00001/00171
d D 4.2 83/02/09 15:16:30 sam 2 1
c no more setexit
e
s 00172/00000/00000
d D 4.1 80/10/01 17:27:18 bill 1 0
c date and time created 80/10/01 17:27:18 by bill
e
u
U
t
T
I 1
D 5
static char *sccsid = "%W% (Berkeley) %G%";
E 5
I 5
/*
D 8
 * Copyright (c) 1980 Regents of the University of California.
E 8
I 8
 * Copyright (c) 1980, 1988 Regents of the University of California.
E 8
D 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
E 6
 */

#ifndef lint
char copyright[] =
D 8
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
E 8
I 8
"%Z% Copyright (c) 1980, 1988 Regents of the University of California.\n\
E 8
 All rights reserved.\n";
D 6
#endif not lint
E 6
I 6
#endif /* not lint */
E 6

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 6
#endif not lint
E 6
I 6
#endif /* not lint */
E 6

I 8
#include <sys/param.h>
#include <sys/time.h>
E 8
E 5
#include <stdio.h>
I 6
#include <ctype.h>
E 6
I 3
D 8
#include <signal.h>
E 8
I 8

E 8
E 3
/*
D 4
 * leave [hhmm]
E 4
I 4
 * leave [[+]hhmm]
E 4
 *
 * Reminds you when you have to leave.
 * Leave prompts for input and goes away if you hit return.
 * It nags you like a mother hen.
 */
D 4
char origlogin[20], thislogin[20];
E 4
I 4
D 8
char origlogin[20];
E 4
char *getlogin();
char *whenleave;
char *ctime();
char buff[100];

E 8
D 4
main(argc,argv)
E 4
I 4
main(argc, argv)
E 4
D 8
char **argv;
E 8
I 8
	int argc;
	char **argv;
E 8
{
D 6
	long when, tod, now, diff, hours, minutes;
E 6
I 6
D 8
	long when, now, diff, hours, minutes;
E 6
I 4
	char *cp;
E 4
	int *nv;
D 6
	int atoi();
E 6
I 6
	int gethm();
E 6
	int *localtime();
E 8
I 8
	register u_int secs;
	register int hours, minutes;
	register char c, *cp;
	struct tm *t, *localtime();
	time_t now, time();
	int plusnow;
	char buf[50];
E 8

I 4
D 6
	strcpy(origlogin, getlogin());
E 6
I 6
D 8
	if ((cp = getlogin()) == NULL) {
		fputs("leave: You are not logged in.\n", stderr);
		exit(1);
	}
	strcpy(origlogin, cp);
E 8
E 6
E 4
	if (argc < 2) {
D 8
		printf("When do you have to leave? ");
		fflush(stdout);
D 4
		buff[read(0,buff,sizeof buff)] = 0;
	} else {
		strcpy(buff,argv[1]);
	}

	if (buff[0] == '\n')
E 4
I 4
		buff[read(0, buff, sizeof buff)] = 0;
		cp = buff;
E 8
I 8
#define	MSG1	"When do you have to leave? "
		(void)write(1, MSG1, sizeof(MSG1) - 1);
		cp = fgets(buf, sizeof(buf), stdin);
		if (*cp == '\n')
			exit(0);
E 8
	} else
		cp = argv[1];
D 8
	if (*cp == '\n')
E 4
		exit(0);
E 8
I 8

E 8
D 4
	if (buff[0] == '+') {
		diff = atoi(buff+1);
E 4
I 4
	if (*cp == '+') {
D 8
		cp++;
D 6
		if (*cp < '0' || *cp > '9')
E 6
I 6
		if (!gethm(cp, &hours, &minutes))
E 8
I 8
		plusnow = 1;
		++cp;
	} else {
		plusnow = 0;
		(void)time(&now);
		t = localtime(&now);
	}

	for (hours = 0; (c = *cp) && c != '\n'; ++cp) {
		if (!isdigit(c))
E 8
E 6
			usage();
D 6
		tod = atoi(cp);
		hours = tod / 100;
		minutes = tod % 100;
E 6
D 8
		if (minutes < 0 || minutes > 59)
			usage();
		diff = 60*hours+minutes;
E 4
		doalarm(diff);
I 4
		exit(0);
E 8
I 8
		hours = hours * 10 + (c - '0');
E 8
E 4
	}
D 4
	if (buff[0] < '0' || buff[0] > '9') {
		printf("usage: %s [hhmm]\n",argv[0]);
		exit(1);
	}
	strcpy(origlogin,getlogin());

	tod = atoi(buff);
E 4
I 4
D 6
	if (*cp < '0' || *cp > '9')
E 6
I 6
D 8
	if (!gethm(cp, &hours, &minutes))
E 6
		usage();
D 6
	tod = atoi(cp);
E 4
	hours = tod / 100;
E 6
	if (hours > 12)
		hours -= 12;
	if (hours == 12)
		hours = 0;
E 8
I 8
	minutes = hours % 100;
	hours /= 100;
E 8
D 6
	minutes = tod % 100;
E 6

D 4
	if (hours < 0 || hours > 12 || minutes < 0 || minutes > 59) {
		printf("usage: %s [hhmm]\n",argv[0]);
		exit(1);
	}
E 4
I 4
D 8
	if (hours < 0 || hours > 12 || minutes < 0 || minutes > 59)
E 8
I 8
	if (minutes < 0 || minutes > 59)
E 8
		usage();
E 4
D 8

D 2
	setexit();	/* refigure time if killed */
E 2
	time(&now);
	nv = localtime(&now);
	when = 60*hours+minutes;
D 4
	if (nv[2] > 12) nv[2] -= 12;	/* do am/pm bit */
E 4
I 4
	if (nv[2] > 12)
		nv[2] -= 12;	/* do am/pm bit */
E 4
	now = 60*nv[2] + nv[1];
	diff = when - now;
	while (diff < 0)
		diff += 12*60;
D 4
	if (diff > 11*60) printf("That time has already passed!\n");
E 4
I 4
	if (diff > 11*60) {
D 6
		printf("That time has already passed!\n");
E 6
I 6
		fprintf(stderr, "That time has already passed!\n");
E 6
		exit(1);
E 8
I 8
	if (plusnow)
		secs = hours * 60 * 60 + minutes * 60;
	else {
		if (hours > 23 || t->tm_hour > hours ||
		    t->tm_hour == hours && minutes <= t->tm_min)
			usage();
		secs = (hours - t->tm_hour) * 60 * 60;
		secs += (minutes - t->tm_min) * 60;
E 8
	}
E 4
D 8
	doalarm(diff);
E 8
I 8
	doalarm(secs);
E 8
	exit(0);
}

I 4
D 8
usage()
E 8
I 8
static
doalarm(secs)
	u_int secs;
E 8
{
D 6
	printf("usage: leave [[+]hhmm]\n");
E 6
I 6
D 8
	fprintf(stderr, "usage: leave [[+]hhmm]\n");
E 6
	exit(1);
}
E 8
I 8
	register int bother;
	time_t daytime, time();
	int pid;
	char *ctime();
E 8
E 4

I 6
D 8
int
gethm(cp, hp, mp)
register char *cp;
int *hp, *mp;
{
	register char c;
	register int tod;
E 8
I 8
	if (pid = fork()) {
		(void)time(&daytime);
		daytime += secs;
		printf("Alarm set for %.16s. (pid %d)\n",
		    ctime(&daytime), pid);
		exit(0);
	}
	sleep((u_int)2);		/* let parent print set message */
E 8

D 8
	tod = 0;
	while ((c = *cp++) != '\0') {
		if (!isdigit(c))
			return(0);
		tod = tod * 10 + (c - '0');
E 8
I 8
	/*
	 * if write fails, we've lost the terminal through someone else
	 * causing a vhangup by logging in.
	 */
#define	FIVEMIN	(5 * 60)
#define	MSG2	"\07\07You have to leave in 5 minutes.\n"
	if (secs >= FIVEMIN) {
		sleep(secs - FIVEMIN);
		if (write(1, MSG2, sizeof(MSG2) - 1) != sizeof(MSG2) - 1)
			exit(0);
		secs = FIVEMIN;
E 8
	}
D 8
	*hp = tod / 100;
	*mp = tod % 100;
	return(1);
}
E 8

E 6
D 8
doalarm(nmins)
long nmins;
{
	char *msg1, *msg2, *msg3, *msg4;
	register int i;
	int slp1, slp2, slp3, slp4;
	int seconds, gseconds;
	long daytime;

	seconds = 60 * nmins;
	if (seconds <= 0)
		seconds = 1;
	gseconds = seconds;

	msg1 = "You have to leave in 5 minutes";
	if (seconds <= 60*5) {
		slp1 = 0;
	} else {
		slp1 = seconds - 60*5;
		seconds = 60*5;
E 8
I 8
#define	ONEMIN	(60)
#define	MSG3	"\07\07Just one more minute!\n"
	if (secs >= ONEMIN) {
		sleep(secs - ONEMIN);
		if (write(1, MSG3, sizeof(MSG3) - 1) != sizeof(MSG3) - 1)
			exit(0);
E 8
	}

D 8
	msg2 = "Just one more minute!";
	if (seconds <= 60) {
		slp2 = 0;
	} else {
		slp2 = seconds - 60;
		seconds = 60;
E 8
I 8
#define	MSG4	"\07\07Time to leave!\n"
	for (bother = 10; bother--;) {
		sleep((u_int)ONEMIN);
		if (write(1, MSG4, sizeof(MSG4) - 1) != sizeof(MSG4) - 1)
			exit(0);
E 8
	}

D 8
	msg3 = "Time to leave!";
	slp3 = seconds;

	msg4 = "You're going to be late!";
	slp4 = 60;

	time(&daytime);
	daytime += gseconds;
	whenleave = ctime(&daytime);
D 4
	printf("Alarm set for %s\n",whenleave);
E 4
I 4
	printf("Alarm set for %s", whenleave);
E 4
	if (fork())
		exit(0);
D 3
	signal(2,1);
	signal(3,1);
	signal(15,1);
E 3
I 3
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
E 3

	if (slp1)
D 4
		bother(slp1,msg1);
E 4
I 4
		bother(slp1, msg1);
E 4
	if (slp2)
D 4
		bother(slp2,msg2);
	bother(slp3,msg3);
	for (;;) {
		bother(slp4,msg4);
	}
E 4
I 4
		bother(slp2, msg2);
	bother(slp3, msg3);
	for (i = 0; i < 10; i++)
		bother(slp4, msg4);
	printf("That was the last time I'll tell you. Bye.\n");
E 8
I 8
#define	MSG5	"\07\07That was the last time I'll tell you.  Bye.\n"
	(void)write(1, MSG5, sizeof(MSG5) - 1);
E 8
	exit(0);
E 4
}

D 4
bother(slp,msg)
E 4
I 4
D 8
bother(slp, msg)
E 4
int slp;
char *msg;
E 8
I 8
static
usage()
E 8
{
D 8

	delay(slp);
D 4
	printf("\7\7\7");
	printf("%s\n",msg);
E 4
I 4
	printf("\7\7\7%s\n", msg);
E 8
I 8
	fprintf(stderr, "usage: leave [[+]hhmm]\n");
	exit(1);
E 8
E 4
}
D 8

/*
 * delay is like sleep but does it in 100 sec pieces and
 * knows what zero means.
 */
D 4
delay(secs) int secs; {
E 4
I 4
delay(secs)
int secs;
{
E 4
	int n;
I 6
	register char *l;
E 6

D 4
	while(secs>0) {
E 4
I 4
	while (secs > 0) {
E 4
		n = 100;
D 4
		secs = secs - 100;
		if (secs < 0) {
			n = n + secs;
		}
E 4
I 4
		if (secs < n)
			n = secs;
		secs -= n;
E 4
		if (n > 0)
			sleep(n);
D 4
		strcpy(thislogin,getlogin());
		if (strcmp(origlogin, thislogin))
E 4
I 4
D 6
		if (strcmp(origlogin, getlogin()))
E 6
I 6
		l = getlogin();
		if (l == NULL)
			exit(0);
		if (strcmp(origlogin, l) != 0)
E 6
E 4
			exit(0);
	}
}

#ifdef V6
char *getlogin() {
#include <utmp.h>

	static struct utmp ubuf;
	int ufd;

	ufd = open("/etc/utmp",0);
	seek(ufd, ttyn(0)*sizeof(ubuf), 0);
	read(ufd, &ubuf, sizeof(ubuf));
	ubuf.ut_name[sizeof(ubuf.ut_name)] = 0;
	return(&ubuf.ut_name);
}
#endif
E 8
E 1
