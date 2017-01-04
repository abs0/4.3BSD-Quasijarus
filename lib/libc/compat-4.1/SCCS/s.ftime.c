h20637
s 00002/00002/00036
d D 5.2 86/03/09 19:22:50 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00029
d D 5.1 85/05/30 10:26:47 dist 2 1
c Add copyright
e
s 00030/00000/00000
d D 4.1 83/05/31 00:19:54 sam 1 0
c date and time created 83/05/31 00:19:54 by sam
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 3
#ifndef lint
E 3
I 3
#if defined(LIBC_SCCS) && !defined(lint)
E 3
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif not lint
E 3
I 3
#endif LIBC_SCCS and not lint
E 3
E 2

#include <sys/types.h>
#include <sys/time.h>

/*
 * Backwards compatible ftime.
 */

/* from old timeb.h */
struct timeb {
	time_t	time;
	u_short	millitm;
	short	timezone;
	short	dstflag;
};

ftime(tp)
	register struct timeb *tp;
{
	struct timeval t;
	struct timezone tz;

	if (gettimeofday(&t, &tz) < 0)
		return (-1);
	tp->time = t.tv_sec;
	tp->millitm = t.tv_usec / 1000;
	tp->timezone = tz.tz_minuteswest;
	tp->dstflag = tz.tz_dsttime;
}
E 1
