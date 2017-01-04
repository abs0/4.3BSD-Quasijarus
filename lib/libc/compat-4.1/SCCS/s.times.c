h55208
s 00002/00002/00044
d D 5.2 86/03/09 19:24:13 donn 4 3
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00037
d D 5.1 85/05/30 10:29:23 dist 3 2
c Add copyright
e
s 00002/00002/00036
d D 4.2 83/06/02 16:18:08 sam 2 1
c blech...can't type
e
s 00038/00000/00000
d D 4.1 83/05/31 00:05:45 sam 1 0
c date and time created 83/05/31 00:05:45 by sam
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
 * Copyright (c) 1980 Regents of the University of California.
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

#include <sys/time.h>
#include <sys/resource.h>

/*
 * Backwards compatible times.
 */
struct tms {
	int	tms_utime;		/* user time */
	int	tms_stime;		/* system time */
	int	tms_cutime;		/* user time, children */
	int	tms_cstime;		/* system time, children */
};

times(tmsp)
D 2
	register struct times *tmsp;
E 2
I 2
	register struct tms *tmsp;
E 2
{
	struct rusage ru;

	if (getrusage(RUSAGE_SELF, &ru) < 0)
		return (-1);
D 2
	tmsp->tms_utime = scale60(&ru.ru_time);
E 2
I 2
	tmsp->tms_utime = scale60(&ru.ru_utime);
E 2
	tmsp->tms_stime = scale60(&ru.ru_stime);
	if (getrusage(RUSAGE_CHILDREN, &ru) < 0)
		return (-1);
	tmsp->tms_cutime = scale60(&ru.ru_utime);
	tmsp->tms_cstime = scale60(&ru.ru_stime);
	return (0);
}

static
scale60(tvp)
	register struct timeval *tvp;
{

	return (tvp->tv_sec * 60 + tvp->tv_usec / 16667);
}
E 1
