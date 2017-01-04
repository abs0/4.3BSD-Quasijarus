h05739
s 00001/00000/00018
d D 5.4 88/02/27 15:30:45 bostic 5 4
c 2.10BSD long/int fix
e
s 00001/00001/00017
d D 5.3 87/09/30 12:04:41 bostic 4 3
c long/int bug; bug report 4.3BSD/lib/32
e
s 00002/00002/00016
d D 5.2 86/03/09 19:23:30 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00009
d D 5.1 85/05/30 10:28:14 dist 2 1
c Add copyright
e
s 00010/00000/00000
d D 4.1 83/06/09 11:24:35 sam 1 0
c date and time created 83/06/09 11:24:35 by sam
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

/*
 * Backwards compatible pause.
 */
pause()
{
I 5
	long sigblock();
E 5

D 4
	sigpause(sigblock(0));
E 4
I 4
	sigpause(sigblock(0L));
E 4
}
E 1
