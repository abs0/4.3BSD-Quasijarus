h46720
s 00002/00001/00068
d D 5.3 87/09/30 12:15:29 bostic 4 3
c long/int bug; bug report 4.3BSD/lib/28
e
s 00002/00002/00067
d D 5.2 86/03/09 20:01:08 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00007/00001/00062
d D 5.1 85/06/05 12:43:23 mckusick 2 1
c Add copyright
e
s 00063/00000/00000
d D 1.1 85/03/14 17:56:37 serge 1 0
c date and time created 85/03/14 17:56:37 by serge
e
u
U
t
T
I 2
/*
 * Copyright (c) 1985 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 2
I 1
D 3
#ifndef lint
E 3
I 3
#if defined(LIBC_SCCS) && !defined(lint)
E 3
static char sccsid[] = "%W% (Berkeley) %G%";
D 2
#endif
E 2
I 2
D 3
#endif not lint
E 3
I 3
#endif LIBC_SCCS and not lint
E 3
E 2

#include <sys/time.h>
#include <signal.h>

#define USPS	1000000		/* number of microseconds in a second */
#define TICK	10000		/* system clock resolution in microseconds */

#define	setvec(vec, a) \
	vec.sv_handler = a; vec.sv_mask = vec.sv_onstack = 0

static int ringring;

usleep(n)
	unsigned n;
{
D 4
	int sleepx(), omask;
E 4
I 4
	int sleepx();
	long omask;
E 4
	struct itimerval itv, oitv;
	register struct itimerval *itp = &itv;
	struct sigvec vec, ovec;

	if (n == 0)
		return;
	timerclear(&itp->it_interval);
	timerclear(&itp->it_value);
	if (setitimer(ITIMER_REAL, itp, &oitv) < 0)
		return;
	itp->it_value.tv_sec = n / USPS;
	itp->it_value.tv_usec = n % USPS;
	if (timerisset(&oitv.it_value)) {
		if (timercmp(&oitv.it_value, &itp->it_value, >)) {
			oitv.it_value.tv_sec -= itp->it_value.tv_sec;
			oitv.it_value.tv_usec -= itp->it_value.tv_usec;
			if (oitv.it_value.tv_usec < 0) {
				oitv.it_value.tv_usec += USPS;
				oitv.it_value.tv_sec--;
			}
		} else {
			itp->it_value = oitv.it_value;
			oitv.it_value.tv_sec = 0;
			oitv.it_value.tv_usec = 2 * TICK;
		}
	}
	setvec(vec, sleepx);
	(void) sigvec(SIGALRM, &vec, &ovec);
	omask = sigblock(sigmask(SIGALRM));
	ringring = 0;
	(void) setitimer(ITIMER_REAL, itp, (struct itimerval *)0);
	while (!ringring)
		sigpause(omask &~ sigmask(SIGALRM));
	(void) sigvec(SIGALRM, &ovec, (struct sigvec *)0);
	(void) sigsetmask(omask);
	(void) setitimer(ITIMER_REAL, &oitv, (struct itimerval *)0);
}

static
sleepx()
{

	ringring = 1;
}
E 1
