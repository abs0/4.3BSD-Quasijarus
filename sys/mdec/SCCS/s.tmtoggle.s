h14609
s 00001/00001/00027
d D 7.1 86/06/05 01:53:24 mckusick 4 3
c 4.3BSD release version
e
s 00009/00001/00019
d D 6.2 85/06/08 12:20:53 mckusick 3 2
c Add copyright
e
s 00000/00000/00020
d D 6.1 83/07/29 07:43:26 sam 2 1
c 4.2 distribution
e
s 00020/00000/00000
d D 4.1 83/02/16 22:06:38 sam 1 0
c date and time created 83/02/16 22:06:38 by sam
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
 * Prototype toggle in bootstrap code for tm type tapes.
 * If on anything but a 780 with the drive on uba0
 * this will have to be repaired by patching uba and umem.
 */
begin:
	movl	uba,r1
	movl	$0x80200000,0x800(r1)
	clrl	0x804(r1)
	movl	umem,r2
	bisl2	$0172520,r2
	mnegw	$512,4(r2)
	clrw	6(r2)
	movw	$03,2(r2)
	halt
	.align	2
uba:	.long	0x20006000
umem:	.long	0x2013e000
E 1
