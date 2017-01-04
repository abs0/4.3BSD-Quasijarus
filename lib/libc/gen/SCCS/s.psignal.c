h14552
s 00002/00002/00034
d D 5.2 86/03/09 19:52:49 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00010/00001/00026
d D 5.1 85/05/30 10:48:04 dist 2 1
c Add copyright
e
s 00027/00000/00000
d D 4.1 83/02/10 22:46:00 sam 1 0
c date and time created 83/02/10 22:46:00 by sam
e
u
U
t
T
I 1
D 2
/*	%W% (Berkeley) %G%	*/
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
 * Print the name of the signal indicated
 * along with the supplied message.
 */
#include <signal.h>

extern	char *sys_siglist[];

psignal(sig, s)
	unsigned sig;
	char *s;
{
	register char *c;
	register n;

	c = "Unknown signal";
	if (sig < NSIG)
		c = sys_siglist[sig];
	n = strlen(s);
	if (n) {
		write(2, s, n);
		write(2, ": ", 2);
	}
	write(2, c, strlen(c));
	write(2, "\n", 1);
}
E 1
