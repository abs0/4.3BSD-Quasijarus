h06444
s 00002/00002/00026
d D 5.2 86/03/09 19:23:21 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00019
d D 5.1 85/05/30 10:27:57 dist 2 1
c Add copyright
e
s 00020/00000/00000
d D 4.1 83/05/30 23:56:47 sam 1 0
c date and time created 83/05/30 23:56:47 by sam
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

#include <sys/time.h>
#include <sys/resource.h>

/*
 * Backwards compatible nice.
 */
nice(incr)
	int incr;
{
	int prio;
	extern int errno;

	errno = 0;
	prio = getpriority(PRIO_PROCESS, 0);
	if (prio == -1 && errno)
		return (-1);
	return (setpriority(PRIO_PROCESS, 0, prio + incr));
}
E 1
