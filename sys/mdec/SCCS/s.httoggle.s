h17824
s 00001/00001/00030
d D 7.1 86/06/05 01:52:13 mckusick 4 3
c 4.3BSD release version
e
s 00010/00001/00021
d D 6.2 85/06/08 12:19:30 mckusick 3 2
c Add copyright
e
s 00000/00000/00022
d D 6.1 83/07/29 07:43:10 sam 2 1
c 4.2 distribution
e
s 00022/00000/00000
d D 4.1 83/02/16 22:06:30 sam 1 0
c date and time created 83/02/16 22:06:30 by sam
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
D 4
 * Copyright (c) 1980 Regents of the University of California.
E 4
I 4
 * Copyright (c) 1980, 1986 Regents of the University of California.
E 4
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
_sccsid:.asciz	"%W% (Berkeley) %G%"
#endif not lint

E 3

/*
 * Prototype toggle in bootstrap code for ht type tapes.
 * If on anything but a 780 with a tape at slave 1 of mba 1
 * this will have to be repaired by patching mba and ht.
 */
	movl	mba,r10
	mull3	ht,$0x80,r11
	addl3	r11,r10,r11
	addl2	$0x400,r11
	movl	$1,4(r10)
	movl	$9,(r11)
	cvtwl	$012300,0x24(r11)
	clrl	12(r10)
	movl	$0x80000000,0x800(r10)
	cvtwl	$-512,16(r10)
	movl	$0x39,(r11)
	halt
	.align	2
mba:	.long	0x20012000
ht:	.long	0
E 1
