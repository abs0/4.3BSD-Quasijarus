h53500
s 00001/00001/00029
d D 7.1 86/06/05 01:54:36 mckusick 7 6
c 4.3BSD release version
e
s 00009/00001/00021
d D 6.2 85/06/08 12:22:25 mckusick 6 5
c Add copyright
e
s 00000/00000/00022
d D 6.1 83/07/29 07:43:43 sam 5 4
c 4.2 distribution
e
s 00006/00005/00016
d D 4.3 83/03/06 17:36:23 sam 4 3
c missing setup of tape density and format
e
s 00001/00001/00020
d D 4.2 83/02/21 17:10:13 sam 3 1
c from mo
e
s 00001/00001/00020
d R 4.2 83/02/21 17:06:30 sam 2 1
c from mo
e
s 00021/00000/00000
d D 4.1 83/02/16 23:17:35 sam 1 0
c date and time created 83/02/16 23:17:35 by sam
e
u
U
t
T
I 1
D 6
/*	%M%	%I%	%E%	*/
E 6
I 6
/*
D 7
 * Copyright (c) 1980 Regents of the University of California.
E 7
I 7
 * Copyright (c) 1980, 1986 Regents of the University of California.
E 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
_sccsid:.asciz	"%W% (Berkeley) %G%"
#endif not lint
E 6

/*
D 4
 * Prototype toggle in bootstrap code for tm type tapes.
E 4
I 4
 * Prototype toggle in bootstrap code for ut type tapes.
E 4
 * If on anything but a 780 with the drive on uba0
 * this will have to be repaired by patching uba and umem.
 */
begin:
	movl	uba,r1
	movl	$0x80200000,0x800(r1)
	clrl	0x804(r1)
	movl	umem,r2
	bisl2	$0172440,r2
D 4
	mnegw	$512,06(r2)
	mnegw	$256,02(r2)
	clrw	04(r2)
D 3
	movw	$071,2(r2)
E 3
I 3
	movw	$071,(r2)
E 4
I 4
	movw	$0x04c0,26(r2)		/* set tape density & format */
	mnegw	$512,6(r2)		/* set frame count */
	mnegw	$256,2(r2)		/* set word count */
	clrw	4(r2)			/* set bus address */
	movw	$0x39,(r2)		/* set command and go */
E 4
E 3
	halt
	.align	2
uba:	.long	0x20006000
umem:	.long	0x2013e000
E 1
