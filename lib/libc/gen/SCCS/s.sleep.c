h57128
s 00002/00001/00065
d D 5.3 87/09/30 12:16:40 bostic 10 9
c long/int bug; bug report 4.3BSD/lib/27
e
s 00002/00002/00064
d D 5.2 86/03/09 19:57:06 donn 9 8
c added LIBC_SCCS condition for sccs ids
e
s 00007/00001/00059
d D 5.1 85/05/30 10:51:09 dist 8 7
c Add copyright
e
s 00003/00004/00057
d D 4.7 84/12/08 21:31:58 karels 7 6
c minor race problem
e
s 00001/00001/00060
d D 4.6 83/09/11 21:57:10 karels 6 5
c minor bugfix (avoid unlikely race)
e
s 00009/00014/00052
d D 4.5 83/08/14 16:15:12 karels 5 4
c don't use setjmp/longjmp, or problems if an interrupt routine
c does a lonjmp before the timer goes off.
e
s 00004/00002/00062
d D 4.4 83/07/01 18:33:00 sam 4 3
c include fixes
e
s 00008/00005/00056
d D 4.3 83/06/12 01:28:34 sam 3 2
c beware of signals other than SIGALRM interrupting sigpause; 
c also when alarm overlaps previous, use 1 sec reset value to allow time to return
e
s 00038/00018/00023
d D 4.2 83/06/10 22:43:32 sam 2 1
c modernized
e
s 00041/00000/00000
d D 4.1 80/12/21 16:40:06 wnj 1 0
c date and time created 80/12/21 16:40:06 by wnj
e
u
U
t
T
I 8
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 8
I 1
D 2
/* %W% (Berkeley) %G% */
E 2
I 2
D 4
/*	%W% (Berkeley) %G%	*/
E 4
I 4
D 9
#ifndef lint
E 9
I 9
#if defined(LIBC_SCCS) && !defined(lint)
E 9
static char sccsid[] = "%W% (Berkeley) %G%";
D 8
#endif
E 8
I 8
D 9
#endif not lint
E 9
I 9
#endif LIBC_SCCS and not lint
E 9
E 8
E 4

I 4
#include <sys/time.h>
E 4
E 2
#include <signal.h>
D 5
#include <setjmp.h>
E 5
I 2
D 4
#include <time.h>
E 4
E 2

D 5
static jmp_buf jmp;

E 5
I 2
D 7
#define	mask(s)	(1<<((s)-1))
E 7
#define	setvec(vec, a) \
	vec.sv_handler = a; vec.sv_mask = vec.sv_onstack = 0

I 5
static int ringring;

E 5
E 2
sleep(n)
D 2
unsigned n;
E 2
I 2
	unsigned n;
E 2
{
D 2
	int sleepx();
	unsigned altime;
	int (*alsig)() = SIG_DFL;
E 2
I 2
D 10
	int sleepx(), omask;
E 10
I 10
	int sleepx();
	long omask;
E 10
	struct itimerval itv, oitv;
	register struct itimerval *itp = &itv;
	struct sigvec vec, ovec;
E 2

D 2
	if (n==0)
E 2
I 2
	if (n == 0)
E 2
		return;
D 2
	altime = alarm(1000);	/* time to maneuver */
E 2
I 2
	timerclear(&itp->it_interval);
	timerclear(&itp->it_value);
	if (setitimer(ITIMER_REAL, itp, &oitv) < 0)
		return;
D 7
	setvec(ovec, SIG_DFL);
E 2
D 5
	if (setjmp(jmp)) {
D 2
		signal(SIGALRM, alsig);
		alarm(altime);
E 2
I 2
		(void) sigvec(SIGALRM, &ovec, (struct sigvec *)0);
		(void) setitimer(ITIMER_REAL, &oitv, (struct itimerval *)0);
E 2
		return;
	}
E 5
D 2
	if (altime) {
		if (altime > n)
			altime -= n;
E 2
I 2
	omask = sigblock(0);
E 7
	itp->it_value.tv_sec = n;
	if (timerisset(&oitv.it_value)) {
		if (timercmp(&oitv.it_value, &itp->it_value, >))
			oitv.it_value.tv_sec -= itp->it_value.tv_sec;
E 2
		else {
D 2
			n = altime;
			altime = 1;
E 2
I 2
			itp->it_value = oitv.it_value;
			/*
D 3
			 * Set the reset value to the smallest possible,
			 * the system will round it to the clock resolution.
E 3
I 3
			 * This is a hack, but we must have time to
D 5
			 * return from the setitimer after the longjmp
E 5
I 5
			 * return from the setitimer after the alarm
E 5
			 * or else it'll be restarted.  And, anyway,
			 * sleep never did anything more than this before.
E 3
			 */
D 3
			oitv.it_value.tv_sec = 0;
			oitv.it_value.tv_usec = 1;
E 3
I 3
			oitv.it_value.tv_sec = 1;
			oitv.it_value.tv_usec = 0;
E 3
E 2
		}
	}
D 2
	alsig = signal(SIGALRM, sleepx);
	alarm(n);
	for(;;)
		pause();
E 2
I 2
	setvec(vec, sleepx);
	(void) sigvec(SIGALRM, &vec, &ovec);
I 7
	omask = sigblock(sigmask(SIGALRM));
E 7
D 5
	if (setitimer(ITIMER_REAL, itp, (struct itimerval *)0) < 0)
		longjmp(jmp, 1);
D 3
	sigpause(omask &~ mask(SIGALRM));
E 3
I 3
	for (;;)
E 5
I 5
D 6
	(void) setitimer(ITIMER_REAL, itp, (struct itimerval *)0);
E 6
	ringring = 0;
I 6
	(void) setitimer(ITIMER_REAL, itp, (struct itimerval *)0);
E 6
	while (!ringring)
E 5
D 7
		sigpause(omask &~ mask(SIGALRM));
E 7
I 7
		sigpause(omask &~ sigmask(SIGALRM));
E 7
E 3
E 2
D 5
	/*NOTREACHED*/
E 5
I 5
	(void) sigvec(SIGALRM, &ovec, (struct sigvec *)0);
I 7
	(void) sigsetmask(omask);
E 7
	(void) setitimer(ITIMER_REAL, &oitv, (struct itimerval *)0);
E 5
}

static
sleepx()
{
I 2

E 2
D 5
	longjmp(jmp, 1);
E 5
I 5
	ringring = 1;
E 5
}
E 1
