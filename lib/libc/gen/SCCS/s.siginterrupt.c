h14850
s 00002/00002/00028
d D 5.2 86/03/09 19:56:14 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00021
d D 5.1 85/06/05 12:34:30 mckusick 2 1
c Add copyright
e
s 00022/00000/00000
d D 4.1 85/03/11 22:32:11 mckusick 1 0
c date and time created 85/03/11 22:32:11 by mckusick
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
 * Copyright (c) 1985 Regents of the University of California.
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

#include <signal.h>

/*
 * Set signal state to prevent restart of system calls
 * after an instance of the indicated signal.
 */
siginterrupt(sig, flag)
	int sig, flag;
{
	struct sigvec sv;
	int ret;

	if ((ret = sigvec(sig, 0, &sv)) < 0)
		return (ret);
	if (flag)
		sv.sv_flags |= SV_INTERRUPT;
	else
		sv.sv_flags &= ~SV_INTERRUPT;
	return (sigvec(sig, &sv, 0));
}
E 1
