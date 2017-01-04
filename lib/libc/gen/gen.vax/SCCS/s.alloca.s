h28352
s 00002/00002/00020
d D 5.3 86/03/09 21:11:03 donn 5 4
c added LIBC_SCCS condition for sccs ids
e
s 00001/00001/00021
d D 5.2 85/06/05 18:56:55 mckusick 4 3
c Fix copyright
e
s 00010/00001/00012
d D 5.1 85/05/30 15:11:56 dist 3 2
c Add copyright
e
s 00002/00002/00011
d D 4.2 84/11/01 23:51:15 sam 2 1
c change ENTRY & ASENTRY to allow setting the register save mask
e
s 00013/00000/00000
d D 4.1 83/06/27 16:08:47 root 1 0
c date and time created 83/06/27 16:08:47 by root
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
D 2
/* like alloc, but automatic automatic free in return */
E 2
I 2
/* like alloc, but automatic free in return */
E 2

#include "DEFS.h"

D 2
ENTRY(alloca)
E 2
I 2
ENTRY(alloca, 0)
E 2
	subl2	4(ap),sp	/* crude allocation */
	movl	16(fp),r1	/* pc */
	movq	8(fp),ap	/* new (old) ap and fp */
	bicl2	$3,sp		/* 4-byte align */
	addl2	$7*4,sp		/* reuse space of mscp */
	movl	sp,r0		/* return value */
	jmp 	(r1)		/* funny return */
E 1
