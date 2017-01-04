h04527
s 00009/00009/00050
d D 5.4 86/03/07 12:32:48 minshall 7 6
c Clean up for lint; change some stderr to stdout; bug fix
c (in ruserpass.c, routine rnetrc()).
e
s 00001/00001/00058
d D 5.3 86/02/03 14:41:39 minshall 6 5
c Changes from Steve Jacobson (from <csvsj@ucbopal>).
e
s 00001/00001/00058
d D 5.2 86/01/13 19:33:11 mckusick 5 4
c numerous bug fixes from sun!gorodish!guy
e
s 00007/00001/00052
d D 5.1 85/05/31 17:01:14 dist 4 3
c Add copyright
e
s 00014/00005/00039
d D 4.3 85/03/11 13:32:01 ralph 3 2
c minor fixes from ut-sally
e
s 00002/00002/00042
d D 4.2 84/02/10 14:16:25 ralph 2 1
c allow longer passwords for non-UNIX hosts.
e
s 00044/00000/00000
d D 4.1 83/05/26 11:25:36 mo 1 0
c date and time created 83/05/26 11:25:36 by mo
e
u
U
t
T
I 4
/*
D 6
 * Copyright (c) 1980 Regents of the University of California.
E 6
I 6
 * Copyright (c) 1985 Regents of the University of California.
E 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 4
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif
E 4
I 4
#endif not lint
E 4

#include <stdio.h>
#include <signal.h>
#include <sgtty.h>

I 3
static	struct sgttyb ttyb;
static	int flags;
static	FILE *fi;

static intfix()
{
	ttyb.sg_flags = flags;
	if (fi != NULL)
D 7
		stty(fileno(fi), &ttyb);
E 7
I 7
		(void) stty(fileno(fi), &ttyb);
E 7
	exit(SIGINT);
}

E 3
char *
D 7
getpass(prompt)
E 7
I 7
mygetpass(prompt)
E 7
char *prompt;
{
D 3
	struct sgttyb ttyb;
	int flags;
E 3
	register char *p;
	register c;
D 3
	FILE *fi;
E 3
D 2
	static char pbuf[9];
E 2
I 2
D 5
	static char pbuf[50];
E 5
I 5
	static char pbuf[50+1];
E 5
E 2
	int (*signal())();
	int (*sig)();

D 3
	if ((fi = fdopen(open("/dev/tty", 2), "r")) == NULL)
E 3
I 3
	if ((fi = fopen("/dev/tty", "r")) == NULL)
E 3
		fi = stdin;
	else
		setbuf(fi, (char *)NULL);
D 3
	sig = signal(SIGINT, SIG_IGN);
E 3
I 3
	sig = signal(SIGINT, intfix);
E 3
D 7
	gtty(fileno(fi), &ttyb);
E 7
I 7
	(void) gtty(fileno(fi), &ttyb);
E 7
	flags = ttyb.sg_flags;
	ttyb.sg_flags &= ~ECHO;
D 7
	stty(fileno(fi), &ttyb);
	fprintf(stderr, "%s", prompt); fflush(stderr);
E 7
I 7
	(void) stty(fileno(fi), &ttyb);
	fprintf(stderr, "%s", prompt); (void) fflush(stderr);
E 7
	for (p=pbuf; (c = getc(fi))!='\n' && c!=EOF;) {
D 2
		if (p < &pbuf[8])
E 2
I 2
		if (p < &pbuf[sizeof(pbuf)-1])
E 2
			*p++ = c;
	}
	*p = '\0';
D 7
	fprintf(stderr, "\n"); fflush(stderr);
E 7
I 7
	fprintf(stderr, "\n"); (void) fflush(stderr);
E 7
	ttyb.sg_flags = flags;
D 7
	stty(fileno(fi), &ttyb);
	signal(SIGINT, sig);
E 7
I 7
	(void) stty(fileno(fi), &ttyb);
	(void) signal(SIGINT, sig);
E 7
	if (fi != stdin)
D 7
		fclose(fi);
E 7
I 7
		(void) fclose(fi);
E 7
	return(pbuf);
}
E 1
