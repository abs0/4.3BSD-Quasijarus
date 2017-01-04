h19524
s 00002/00002/00026
d D 5.3 86/03/09 20:00:06 donn 5 4
c added LIBC_SCCS condition for sccs ids
e
s 00001/00001/00027
d D 5.2 85/10/30 17:06:25 mckusick 4 3
c time returns a long, not time_t
e
s 00009/00001/00019
d D 5.1 85/05/30 10:52:36 dist 3 2
c Add copyright
e
s 00001/00001/00019
d D 4.2 83/02/27 11:19:37 sam 2 1
c oops
e
s 00020/00000/00000
d D 4.1 83/02/24 10:17:18 sam 1 0
c date and time created 83/02/24 10:17:18 by sam
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

D 5
#ifndef lint
E 5
I 5
#if defined(LIBC_SCCS) && !defined(lint)
E 5
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif not lint
E 5
I 5
#endif LIBC_SCCS and not lint
E 5
E 3

/*
 * Backwards compatible time call.
 */
#include <sys/types.h>
#include <sys/time.h>

D 4
time_t
E 4
I 4
long
E 4
time(t)
	time_t *t;
{
	struct timeval tt;

D 2
	if (getimeofday(&tt, (struct timezone *)0) < 0)
E 2
I 2
	if (gettimeofday(&tt, (struct timezone *)0) < 0)
E 2
		return (-1);
	if (t)
		*t = tt.tv_sec;
	return (tt.tv_sec);
}
E 1
