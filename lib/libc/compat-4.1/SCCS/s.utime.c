h08865
s 00002/00002/00023
d D 5.2 86/03/09 19:24:23 donn 4 3
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00016
d D 5.1 85/05/30 10:29:39 dist 3 2
c Add copyright
e
s 00001/00000/00016
d D 4.2 83/05/31 00:13:39 sam 2 1
c include forgotten
e
s 00016/00000/00000
d D 4.1 83/05/31 00:11:38 sam 1 0
c date and time created 83/05/31 00:11:38 by sam
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

I 2
#include <sys/time.h>
E 2
/*
 * Backwards compatible utime.
 */

utime(name, otv)
	char *name;
	int otv[];
{
	struct timeval tv[2];

	tv[0].tv_sec = otv[0]; tv[0].tv_usec = 0;
	tv[1].tv_sec = otv[1]; tv[1].tv_usec = 0;
	return (utimes(name, tv));
}
E 1
