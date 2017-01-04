h14309
s 00007/00001/00214
d D 5.1 85/06/06 09:49:39 dist 8 7
c Add copyright
e
s 00000/00002/00215
d D 4.7 83/06/25 02:09:45 sam 7 6
c remove #if's, now in a library
e
s 00032/00023/00185
d D 4.6 83/06/25 01:13:13 sam 6 5
c so much...clean up after ralph's merge of wendel and mo code;
c purge VMUNIX include since changes for signals make it no longer portable 
c to systems other than 4.2; fix ventel for no echo strapping; do setjmps 
c instead of assuming interrupted system calls; purge lcmd, if people use 
e
s 00001/00000/00207
d D 4.5 83/06/15 13:51:38 ralph 5 4
c changes for local info, parity, vadic auto dialers
e
s 00027/00028/00180
d D 4.4 81/11/29 22:49:04 sam 4 3
c reformatting
e
s 00006/00006/00202
d D 4.3 81/11/20 10:44:16 sam 3 2
c cosmetics
e
s 00008/00008/00200
d D 4.2 81/09/17 09:43:39 sam 2 1
c split out bizcomp 1031 and 1022
e
s 00208/00000/00000
d D 4.1 81/05/09 16:45:09 root 1 0
c date and time created 81/05/09 16:45:09 by root
e
u
U
t
T
I 8
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 8
I 1
D 6
/*	%M%	%I%	%E%	*/
E 6
I 6
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 8
#endif
E 8
I 8
#endif not lint
E 8

E 6
#include "tip.h"

D 2
#if BIZCOMP
E 2
I 2
D 7
#if BIZ1031
E 7
E 2
#define MAXRETRY	3		/* sync up retry count */
D 6
#define DISCONNECT	"\21\25\11\24"	/* disconnection string */
E 6
I 6
#define DISCONNECT_CMD	"\21\25\11\24"	/* disconnection string */
E 6

I 5
D 6
static char *sccsid = "%W% %G%";
E 5
static int sigALRM();
static int timeout = 0;
E 6
I 6
static	int sigALRM();
static	int timeout = 0;
static	jmp_buf timeoutbuf;
E 6

/*
D 2
 * Dial up on a BIZCOMP with either
E 2
I 2
 * Dial up on a BIZCOMP Model 1031 with either
E 2
 * 	tone dialing (mod = "f")
 *	pulse dialing (mod = "w")
 */
static int
biz_dialer(num, mod)
D 3
char *num, *mod;
E 3
I 3
	char *num, *mod;
E 3
{
	register int connected = 0;

	if (!bizsync(FD)) {
		logent(value(HOST), "", "biz", "out of sync");
		printf("bizcomp out of sync\n");
		delock(uucplock);
		exit(0);
	}
	if (boolean(value(VERBOSE)))
		printf("\nstarting call...");
	echo("#\rk$\r$\n");			/* disable auto-answer */
	echo("$>$.$ #\r");			/* tone/pulse dialing */
	echo(mod);
	echo("$\r$\n");
	echo("$>$.$ #\re$ ");			/* disconnection sequence */
D 6
	echo(DISCONNECT);
E 6
I 6
	echo(DISCONNECT_CMD);
E 6
	echo("\r$\n$\r$\n");
	echo("$>$.$ #\rr$ ");			/* repeat dial */
	echo(num);
	echo("\r$\n");
	if (boolean(value(VERBOSE)))
		printf("ringing...");
	/*
	 * The reply from the BIZCOMP should be:
	 *	`^G NO CONNECTION\r\n^G\r\n'	failure
	 *	` CONNECTION\r\n^G'		success
	 */
	connected = detect(" ");
#ifdef ACULOG
	if (timeout) {
		char line[80];

		sprintf(line, "%d second dial timeout",
			number(value(DIALTIMEOUT)));
		logent(value(HOST), num, "biz", line);
	}
#endif
	if (!connected)
		flush(" NO CONNECTION\r\n\07\r\n");
	else
		flush("CONNECTION\r\n\07");
	if (timeout)
D 2
		biz_disconnect();	/* insurance */
E 2
I 2
		biz31_disconnect();	/* insurance */
E 2
D 4
	return(connected);
E 4
I 4
	return (connected);
E 4
}

D 2
bizw_dialer(num, acu)
E 2
I 2
biz31w_dialer(num, acu)
E 2
D 3
char *num, *acu;
E 3
I 3
	char *num, *acu;
E 3
{
I 6

E 6
D 4
	return(biz_dialer(num, "w"));
E 4
I 4
	return (biz_dialer(num, "w"));
E 4
}

D 2
bizf_dialer(num, acu)
E 2
I 2
biz31f_dialer(num, acu)
E 2
D 3
char *num, *acu;
E 3
I 3
	char *num, *acu;
E 3
{
I 6

E 6
D 4
	return(biz_dialer(num, "f"));
E 4
I 4
	return (biz_dialer(num, "f"));
E 4
}

D 2
biz_disconnect()
E 2
I 2
biz31_disconnect()
E 2
{
D 6
	write(FD, DISCONNECT, 4);
E 6
I 6

	write(FD, DISCONNECT_CMD, 4);
E 6
	sleep(2);
	ioctl(FD, TIOCFLUSH);
}

D 2
biz_abort()
E 2
I 2
biz31_abort()
E 2
{
I 6

E 6
	write(FD, "\33", 1);
D 6
	timeout = 1;
E 6
}

static int
echo(s)
D 3
register char *s;
E 3
I 3
	register char *s;
E 3
{
	char c;

D 4
	while (c = *s++)
		switch(c)
		{
			case '$':
				read(FD, &c, 1);
				s++;
				break;
			case '#':
				c = *s++;
				write(FD, &c, 1);
				break;
			default:
				write(FD, &c, 1);
				read(FD, &c, 1);
		}
E 4
I 4
	while (c = *s++) switch (c) {

	case '$':
		read(FD, &c, 1);
		s++;
		break;

	case '#':
		c = *s++;
		write(FD, &c, 1);
		break;

	default:
		write(FD, &c, 1);
		read(FD, &c, 1);
	}
E 4
}

static int
sigALRM()
{
D 6
	signal(SIGALRM, SIG_IGN);
	printf("\07timeout waiting for reply\n");
E 6
I 6

E 6
	timeout = 1;
I 6
	longjmp(timeoutbuf, 1);
E 6
}

static int
detect(s)
D 3
register char *s;
E 3
I 3
	register char *s;
E 3
{
	char c;
I 6
	int (*f)();
E 6

D 2
	signal(SIGALRM, biz_abort);
E 2
I 2
D 6
	signal(SIGALRM, biz31_abort);
E 6
I 6
	f = signal(SIGALRM, sigALRM);
E 6
E 2
	timeout = 0;
D 4
	while (*s)
	{
E 4
I 4
	while (*s) {
I 6
		if (setjmp(timeoutbuf)) {
			printf("\07timeout waiting for reply\n");
			biz31_abort();
			break;
		}
E 6
E 4
		alarm(number(value(DIALTIMEOUT)));
		read(FD, &c, 1);
		alarm(0);
D 6
		if (timeout)
D 4
			return(0);
E 4
I 4
			return (0);
E 6
E 4
		if (c != *s++)
D 4
			return(0);
E 4
I 4
D 6
			return (0);
E 6
I 6
			break;
E 6
E 4
	}
D 6
	signal(SIGALRM, SIG_DFL);
D 4
	return(1);
E 4
I 4
	return (1);
E 6
I 6
	signal(SIGALRM, f);
	return (timeout == 0);
E 6
E 4
}

static int
flush(s)
D 3
register char *s;
E 3
I 3
	register char *s;
E 3
{
	char c;
I 6
	int (*f)();
E 6

D 6
	signal(SIGALRM, sigALRM);
	timeout = 0;
E 6
I 6
	f = signal(SIGALRM, sigALRM);
E 6
D 4
	while (*s++)
	{
E 4
I 4
	while (*s++) {
I 6
		if (setjmp(timeoutbuf))
			break;
E 6
E 4
		alarm(10);
		read(FD, &c, 1);
		alarm(0);
D 6
		if (timeout)
			break;
E 6
	}
D 6
	signal(SIGALRM, SIG_DFL);
E 6
I 6
	signal(SIGALRM, f);
E 6
	timeout = 0;			/* guard against disconnection */
D 4
	return(1);
E 4
I 4
D 6
	return (1);
E 6
E 4
}

/*
 * This convoluted piece of code attempts to get
 *  the bizcomp in sync.  If you don't have the capacity or nread
 *  call there are gory ways to simulate this.
 */
static int
bizsync(fd)
{
#ifdef FIOCAPACITY
	struct capacity b;
#	define chars(b)	((b).cp_nbytes)
#	define IOCTL	FIOCAPACITY
#endif
#ifdef FIONREAD
	long b;
#	define chars(b)	(b)
#	define IOCTL	FIONREAD
#endif
	register int already = 0;
	char buf[10];

retry:
	if (ioctl(fd, IOCTL, (caddr_t)&b) >= 0 && chars(b) > 0)
		ioctl(fd, TIOCFLUSH);
	write(fd, "\rp>\r", 4);
	sleep(1);
	if (ioctl(fd, IOCTL, (caddr_t)&b) >= 0) {
		if (chars(b) != 10) {
	nono:
			if (already > MAXRETRY)
D 4
				return(0);
E 4
I 4
				return (0);
E 4
D 6
			write(fd, DISCONNECT, 4);
E 6
I 6
			write(fd, DISCONNECT_CMD, 4);
E 6
			sleep(2);
			already++;
			goto retry;
		} else {
			read(fd, buf, 10);
			if (strncmp(buf, "p >\r\n\r\n>", 8))
				goto nono;
		}
	}
D 4
	return(1);
E 4
I 4
	return (1);
E 4
}
D 7
#endif
E 7
E 1
