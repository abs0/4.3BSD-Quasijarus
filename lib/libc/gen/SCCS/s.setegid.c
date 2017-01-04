h54516
s 00002/00002/00014
d D 5.2 86/03/09 19:55:06 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00007
d D 5.1 85/06/05 12:31:39 mckusick 2 1
c Add copyright
e
s 00008/00000/00000
d D 4.1 83/06/30 17:20:30 sam 1 0
c date and time created 83/06/30 17:20:30 by sam
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
 * Copyright (c) 1983 Regents of the University of California.
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

setegid(egid)
	int egid;
{

	return (setregid(-1, egid));
}
E 1
