h52980
s 00007/00001/00107
d D 5.1 85/04/30 12:54:22 dist 15 14
c Add copyright
e
s 00000/00002/00108
d D 4.14 83/06/25 02:10:02 sam 14 13
c remove #if's, now in a library
e
s 00007/00012/00103
d D 4.13 83/06/25 01:13:48 sam 13 12
c so much...clean up after ralph's merge of wendel and mo code;
c purge VMUNIX include since changes for signals make it no longer portable 
c to systems other than 4.2; fix ventel for no echo strapping; do setjmps 
c instead of assuming interrupted system calls; purge lcmd, if people use 
e
s 00001/00000/00114
d D 4.12 83/06/15 13:52:24 ralph 12 11
c changes for local info, parity, vadic auto dialers
e
s 00005/00026/00109
d D 4.11 81/11/29 22:50:01 sam 11 10
c reformatting
e
s 00001/00001/00134
d D 4.10 81/11/20 10:44:33 sam 10 9
c cosmetics
e
s 00022/00001/00113
d D 4.9 81/09/21 15:19:59 sam 9 8
c misplaced alarm, add debugging #ifdefs
e
s 00001/00001/00113
d D 4.8 81/08/24 10:50:47 sam 8 7
c close acu after connection to allow multiplexing of vadic dialer
e
s 00000/00002/00114
d D 4.7 81/07/23 14:41:53 sam 7 6
c fix signal actions on 1st timeout
e
s 00003/00008/00113
d D 4.6 81/07/11 14:04:44 sam 6 5
c cleanup after "hw" attribute addition (instead of shannon mods)
e
s 00006/00001/00115
d D 4.5 81/06/21 14:21:15 sam 5 4
c fix to kill off child on aborts
e
s 00014/00004/00102
d D 4.4 81/06/16 17:26:36 sam 4 3
c cosmetic surgery
e
s 00076/00047/00030
d D 4.3 81/06/16 16:43:04 sam 3 2
c lots of patches to satisfy the DN-11's wants
e
s 00001/00000/00076
d D 4.2 81/06/04 12:12:45 sam 2 1
c fixed problem with exclusive open in dn11 handler
e
s 00076/00000/00000
d D 4.1 81/05/09 16:45:15 root 1 0
c date and time created 81/05/09 16:45:15 by root
e
u
U
t
T
I 15
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 15
I 1
D 13
/*	%M%	%I%	%E%	*/
E 13
I 13
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 15
#endif
E 15
I 15
#endif not lint
E 15
E 13
I 3

D 14
#if DN11
E 14
E 3
/*
 * Routines for dialing up on DN-11
 */
#include "tip.h"
I 3
D 13
#include <setjmp.h>
#include <errno.h>
E 13
E 3

D 13
int dn_abort();

D 3
#if DN11
E 3
I 3
int alarmtr();

I 12
static char *sccsid = "%W% %G%";
E 13
I 13
int dn_abort(), alarmtr();
E 13
E 12
static jmp_buf jmpbuf;
I 5
static int child = -1, dn;
E 5

E 3
dn_dialer(num, acu)
D 10
char *num, *acu;
E 10
I 10
	char *num, *acu;
E 10
{
	extern errno;
D 3
	char *p, *q, b[30];
	int child = -1, dn, t, connected = 1;
E 3
I 3
	char *p, *q, phone[40];
D 5
	int child = -1, dn, lt, nw, connected = 1;
E 5
I 5
	int lt, nw, connected = 1;
E 5
	register int timelim;
E 3

I 4
	if (boolean(value(VERBOSE)))
		printf("\nstarting call...");
E 4
I 2
D 3
	ioctl(FD, TIOCNXCL, 0);	/* get rid of exclusive open from hunt() */
E 3
E 2
	if ((dn = open(acu, 1)) < 0) {
D 3
		if (errno == 6)
E 3
I 3
D 6
		if (errno == ENXIO)
E 6
I 6
		if (errno == EBUSY)
E 6
E 3
D 4
			printf("line busy\n");
E 4
I 4
			printf("line busy...");
E 4
I 3
		else
D 4
			printf("acu open error\n");
E 4
I 4
			printf("acu open error...");
E 4
E 3
D 11
		return(0);
E 11
I 11
		return (0);
E 11
	}
D 3
	if ((child = fork()) == -1) {
		printf("can't fork\n");
E 3
I 3
	if (setjmp(jmpbuf)) {
D 4
		printf("dn11 write error...");
E 4
		kill(child, SIGKILL);
		close(dn);
E 3
D 11
		return(0);
E 11
I 11
		return (0);
E 11
	}
D 3
	if (child == 0) {
E 3
I 3
	signal(SIGALRM, alarmtr);
	timelim = 5 * strlen(num);
	alarm(timelim < 30 ? 30 : timelim);
	if ((child = fork()) == 0) {
I 4
		/*
		 * ignore this stuff for aborts
		 */
E 4
E 3
		signal(SIGALRM, SIG_IGN);
I 4
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
I 9
D 11
#ifdef DEBUG
		printf("child: sleep\n");
#endif
E 11
E 9
E 4
D 3
		pause();
E 3
I 3
		sleep(2);
I 9
D 11
#ifdef DEBUG
		printf("child: write\n");
#endif
E 11
E 9
		nw = write(dn, num, lt = strlen(num));
I 9
D 11
#ifdef DEBUG
		printf("child: write finished\n");
#endif
E 11
E 9
D 6
		if (nw != lt) {
			printf("dn11 write failed...");
			exit(1);
		}
		exit(0);
E 6
I 6
		exit(nw != lt);
E 6
E 3
	}
D 3
	sleep(2);
	/*
	 * copy phone #, assure EON
	 */
	for (p = b, q = num; *p = *q; p++, q++)
		;
	if (*(p-1) != '<') {
		if (*(p-1) != '-')
			*p++ = '-';
		*p++ = '<';
	}
	close(FD);
	t = p-b;
	signal(SIGALRM, dn_abort);
	alarm(5*t);
	t = write(dn, b, t);
	alarm(0);
	if (t < 0) {
		printf("dn11 write error\n");
		connected = 0;
		goto error;
	}
	alarm(40);		/* was 5; sometimes missed carrier */
E 3
I 3
D 4
	/*  open line - will return on carrier */
E 4
I 4
	/*
	 * open line - will return on carrier
	 */
I 9
D 11
#ifdef DEBUG
	printf("parent: child %d, open begin\n", child);
#endif
E 11
E 9
E 4
E 3
D 6
	FD = open(DV, 2);
D 3
	alarm(0);
E 3
	if (FD < 0) {
E 6
I 6
	if ((FD = open(DV, 2)) < 0) {
E 6
D 3
		if (errno == 4)
			printf("lost carrier\n");
		connected = 0;
		goto error;
E 3
I 3
		if (errno == EIO)
			printf("lost carrier...");
		else
			printf("dialup line open failed...");
		alarm(0);
		kill(child, SIGKILL);
		close(dn);
D 11
		return(0);
E 11
I 11
		return (0);
E 11
E 3
	}
I 9
	alarm(0);
D 11
#ifdef DEBUG
	printf("parent: open finished\n");
#endif
E 11
E 9
D 3
	ioctl(FD, TIOCEXCL, 0);
	ioctl(FD, TIOCHPCL, 0);
error: 
	kill(child, SIGKILL);
	alarm(10);
	while ((t = wait((int *)NULL)) != -1 && t != child)
E 3
I 3
	ioctl(dn, TIOCHPCL, 0);
	signal(SIGALRM, SIG_DFL);
I 9
D 11
#ifdef DEBUG
	printf("parent: wait for child\n");
#endif
E 11
E 9
	while ((nw = wait(&lt)) != child && nw != -1)
I 9
D 11
#ifdef DEBUG
		printf("wait finds child with pid %d\n", nw)
#endif
E 11
E 9
E 3
		;
D 9
	alarm(0);
E 9
D 3
	signal(SIGALRM, SIG_DFL);
	return(connected);
E 3
I 3
	fflush(stdout);
I 8
	close(dn);
E 8
	if (lt != 0) {
		close(FD);
D 8
		close(dn);
E 8
D 11
		return(0);
E 11
I 11
		return (0);
E 11
	}
D 11
	return(1);
E 11
I 11
	return (1);
E 11
E 3
}

D 3
dn_disconnect() { }
E 3
I 3
alarmtr()
{
I 13

E 13
	alarm(0);
D 7
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
E 7
	longjmp(jmpbuf, 1);
}
E 3

D 3
dn_abort() { }
E 3
I 3
/*
 * Insurance, for some reason we don't seem to be
 *  hanging up...
 */
dn_disconnect()
{
I 13

E 13
I 4
	sleep(2);
E 4
D 13
#ifdef VMUNIX
E 13
	if (FD > 0)
		ioctl(FD, TIOCCDTR, 0);
D 13
#endif
E 13
	close(FD);
}

dn_abort()
{
I 13

E 13
I 4
	sleep(2);
I 5
	if (child > 0)
		kill(child, SIGKILL);
	if (dn > 0)
		close(dn);
E 5
E 4
D 13
#ifdef VMUNIX
E 13
	if (FD > 0)
		ioctl(FD, TIOCCDTR, 0);
D 13
#endif
E 13
	close(FD);
}
E 3
D 14
#endif
E 14
E 1
