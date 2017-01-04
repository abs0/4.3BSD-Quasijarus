h26679
s 00002/00002/00028
d D 5.2 86/03/09 19:44:11 donn 4 3
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00021
d D 5.1 85/06/05 12:01:18 mckusick 3 2
c Add copyright
e
s 00002/00000/00020
d D 4.2 84/03/22 09:52:53 ralph 2 1
c round up seconds so it doesn't return zero if there's time left.
e
s 00020/00000/00000
d D 4.1 83/06/10 21:58:57 sam 1 0
c date and time created 83/06/10 21:58:57 by sam
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 4
#ifndef lint
E 4
I 4
#if defined(LIBC_SCCS) && !defined(lint)
E 4
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif not lint
E 4
I 4
#endif LIBC_SCCS and not lint
E 4
E 3

/*
 * Backwards compatible alarm.
 */
#include <sys/time.h>

alarm(secs)
	int secs;
{
	struct itimerval it, oitv;
	register struct itimerval *itp = &it;

	timerclear(&itp->it_interval);
	itp->it_value.tv_sec = secs;
	itp->it_value.tv_usec = 0;
	if (setitimer(ITIMER_REAL, itp, &oitv) < 0)
		return (-1);
I 2
	if (oitv.it_value.tv_usec)
		oitv.it_value.tv_sec++;
E 2
	return (oitv.it_value.tv_sec);
}
E 1
