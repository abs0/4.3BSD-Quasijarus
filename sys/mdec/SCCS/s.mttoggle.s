h32334
s 00001/00001/00032
d D 7.1 86/06/05 01:52:42 mckusick 4 3
c 4.3BSD release version
e
s 00009/00001/00024
d D 6.2 85/06/08 12:19:54 mckusick 3 2
c Add copyright
e
s 00000/00000/00025
d D 6.1 83/07/29 07:43:15 sam 2 1
c 4.2 distribution
e
s 00025/00000/00000
d D 4.1 83/02/16 22:06:33 sam 1 0
c date and time created 83/02/16 22:06:33 by sam
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
 * Prototype toggle in bootstrap code for mt type tapes.
 * If on anything but a 780 with a tape at drive 0 of mba 1
 * this will have to be repaired by patching mba and mt.
 */
	movl	mba,r10
	mull3	mt,$0x80,r11
	addl3	r11,r10,r11
	addl2	$0x400,r11
	movzbl	$1,4(r10)
	movzbl	$4,8(r11)		/* drive zero, one record */
	clrl	12(r10)			/* set address to zero */
	movl	$0x80000000,0x800(r10)	/* validate map register */
	cvtwl	$-512,16(r10)		/* set byte count */
	movzwl	$512,20(r11)		/* set byte count */
0:
	movl	0x44(r11),r0
	bbc	$15,r0,0b
	movzbl	$071,(r11)		/* read forward, go */
	halt
	.align	2
mba:	.long	0x20012000
mt:	.long	0
E 1
