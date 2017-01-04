h06241
s 00002/00002/00019
d D 5.3 86/03/09 21:10:51 donn 5 4
c added LIBC_SCCS condition for sccs ids
e
s 00001/00001/00020
d D 5.2 85/06/05 18:56:42 mckusick 4 3
c Fix copyright
e
s 00010/00001/00011
d D 5.1 85/05/30 15:19:11 dist 3 2
c Add copyright
e
s 00001/00001/00011
d D 4.2 84/11/01 23:51:12 sam 2 1
c change ENTRY & ASENTRY to allow setting the register save mask
e
s 00012/00000/00000
d D 4.1 83/06/27 15:41:44 root 1 0
c date and time created 83/06/27 15:41:44 by root
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
#ifdef LIBC_SCCS
E 5
D 4
static char sccsid[] = "%W% (Berkeley) %G%";
E 4
I 4
	.asciz	"%W% (Berkeley) %G%"
E 4
D 5
#endif not lint
E 5
I 5
#endif LIBC_SCCS
E 5

E 3

/* abs - int absolute value */

#include "DEFS.h"

D 2
ENTRY(abs)
E 2
I 2
ENTRY(abs, 0)
E 2
	movl	4(ap),r0
	bgeq	1f
	mnegl	r0,r0
1:
	ret
E 1
