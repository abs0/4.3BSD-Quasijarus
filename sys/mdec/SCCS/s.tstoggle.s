h39894
s 00001/00001/00040
d D 7.1 86/06/05 01:53:45 mckusick 4 3
c 4.3BSD release version
e
s 00009/00001/00032
d D 6.2 85/06/08 12:21:20 mckusick 3 2
c Add copyright
e
s 00000/00000/00033
d D 6.1 83/07/29 07:43:30 sam 2 1
c 4.2 distribution
e
s 00033/00000/00000
d D 4.1 83/02/16 22:06:42 sam 1 0
c date and time created 83/02/16 22:06:42 by sam
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
 * Prototype toggle in bootstrap code for ts type tapes.
 * If on anything but a 780 with the drive on uba0
 * this will have to be repaired by patching uba and umem.
 */
	.set	UBA0,0x20006000
	.set	UMEM0,0x2013e000
	.set	UBA_MAP,0x800
	.set	TSADDR,0772520-0760000

start:
	movl	uba,r10
	movl	mrv,UBA_MAP(r10)
	addl3	mrv,$1,UBA_MAP+4(r10)
	addl3	umem,$TSADDR,r11
	clrw	2(r11)
1:	tstb	2(r11)
	bgeq	1b
	movw	$0x200+setchr,(r11)
1:	tstb	2(r11)
	bgeq	1b
	movw	$0x200+read,(r11)
	halt
	.align	2
uba:	.long	UBA0
umem:	.long	UMEM0
mrv:	.long	0x80000000
setchr:	.word	0xc004,0x200+char,0,0x8	# set characteristics command
char:	.word	0x200+status,0,0xe,0	# characteristics
read:	.word	0xc001,0,0,0x200	# read command
status:
E 1
