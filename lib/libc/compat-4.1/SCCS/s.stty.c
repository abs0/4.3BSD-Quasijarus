h18163
s 00002/00002/00020
d D 5.2 86/03/09 19:23:53 donn 4 3
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00013
d D 5.1 85/05/30 10:28:50 dist 3 2
c Add copyright
e
s 00005/00009/00009
d D 4.2 83/07/04 11:56:16 sam 2 1
c split out gtty
e
s 00018/00000/00000
d D 4.1 80/12/21 16:40:21 wnj 1 0
c date and time created 80/12/21 16:40:21 by wnj
e
u
U
t
T
I 1
D 2
/* %W% (Berkeley) %G% */
E 2
I 2
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

E 2
/*
D 2
 * Writearound to old stty and gtty system calls
E 2
I 2
 * Writearound to old stty system call.
E 2
 */

#include <sgtty.h>

stty(fd, ap)
D 2
struct sgtty *ap;
E 2
I 2
	struct sgtty *ap;
E 2
{
D 2
	return(ioctl(fd, TIOCSETP, ap));
}
E 2

D 2
gtty(fd, ap)
struct sgtty *ap;
{
	return(ioctl(fd, TIOCGETP, ap));
E 2
I 2
	return(ioctl(fd, TIOCSETP, ap));
E 2
}
E 1
