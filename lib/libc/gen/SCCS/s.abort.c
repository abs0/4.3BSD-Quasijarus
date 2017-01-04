h19455
s 00001/00001/00020
d D 5.4 87/09/30 12:18:53 bostic 5 4
c long/int bug; bug report 4.3BSD/lib/25
e
s 00002/00002/00019
d D 5.3 86/03/09 19:43:59 donn 4 3
c added LIBC_SCCS condition for sccs ids
e
s 00002/00002/00019
d D 5.2 85/07/26 17:43:57 karels 3 2
c Really, let's not shoot all our friends
e
s 00009/00001/00012
d D 5.1 85/05/30 10:40:16 dist 2 1
c Add copyright
e
s 00013/00000/00000
d D 4.1 85/01/24 14:29:08 ralph 1 0
c date and time created 85/01/24 14:29:08 by ralph
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
D 3
 * Copyright (c) 1980 Regents of the University of California.
E 3
I 3
 * Copyright (c) 1985 Regents of the University of California.
E 3
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
E 2

/* C library -- abort */

#include "signal.h"

abort()
{
D 5
	sigblock(~0);
E 5
I 5
	sigblock(~0L);
E 5
	signal(SIGILL, SIG_DFL);
	sigsetmask(~sigmask(SIGILL));
D 3
	kill(0, SIGILL);
E 3
I 3
	kill(getpid(), SIGILL);
E 3
}
E 1
