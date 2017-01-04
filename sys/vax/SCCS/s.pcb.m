h44903
s 00001/00001/00041
d D 7.1 86/06/05 01:08:17 mckusick 8 7
c 4.3BSD release version
e
s 00007/00001/00035
d D 6.2 85/06/08 13:56:00 mckusick 7 6
c Add copyright
e
s 00000/00000/00036
d D 6.1 83/07/29 07:20:55 sam 6 5
c 4.2 distribution
e
s 00035/00039/00001
d D 4.3 81/02/23 20:33:09 wnj 5 4
c cleanup with /* */
e
s 00001/00001/00039
d D 4.2 81/02/19 21:45:55 wnj 4 3
c %G%->%E%
e
s 00000/00000/00040
d D 4.1 80/11/09 17:00:19 bill 3 2
c stamp for 4bsd
e
s 00001/00001/00039
d D 3.2 80/06/07 02:59:39 bill 2 1
c %H%->%G%
e
s 00040/00000/00000
d D 3.1 80/04/09 16:24:51 bill 1 0
c date and time created 80/04/09 16:24:51 by bill
e
u
U
t
T
I 1
D 5
#
D 2
#	%M%	%I%	%H%
E 2
I 2
D 4
#	%M%	%I%	%G%
E 4
I 4
#	%M%	%I%	%E%
E 4
E 2
#
#
#	VAX process control block
#
E 5
I 5
D 7
/* 	%M%	%I%	%E%	*/
E 7
I 7
/*
D 8
 * Copyright (c) 1982 Regents of the University of California.
E 8
I 8
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 7
E 5

D 5
	.set	PCB_KSP,0	# kernel stack pointer
	.set	PCB_ESP,4	# exec stack pointer
	.set	PCB_SSP,8	# supervisor stack pointer
	.set	PCB_USP,12	# user stack pointer
	.set	PCB_R0,16
	.set	PCB_R1,20
	.set	PCB_R2,24
	.set	PCB_R3,28
	.set	PCB_R4,32
	.set	PCB_R5,36
	.set	PCB_R6,40
	.set	PCB_R7,44
	.set	PCB_R8,48
	.set	PCB_R9,52
	.set	PCB_R10,56
	.set	PCB_R11,60
	.set	PCB_R12,64
	.set	PCB_R13,68
	.set	PCB_PC,72	# program counter
	.set	PCB_PSL,76	# program status longword
	.set	PCB_P0BR,80	# seg 0 base register
	.set	PCB_P0LR,84	# seg 0 length register and astlevel
	.set	PCB_P1BR,88	# seg 1 base register
	.set	PCB_P1LR,92	# seg 1 length register and pme

#
#	software pcb (extension)
#

	.set	PCB_SZPT,96	# number of pages of user page table
	.set	PCB_CMAP2,100
	.set	PCB_SSWAP,104
	.set	PCB_SIGC,108
E 5
I 5
/*
 * VAX process control block
 */
	.set	PCB_KSP,	0
	.set	PCB_ESP,	4
	.set	PCB_SSP,	8
	.set	PCB_USP,	12
	.set	PCB_R0,		16
	.set	PCB_R1,		20
	.set	PCB_R2,		24
	.set	PCB_R3,		28
	.set	PCB_R4,		32
	.set	PCB_R5,		36
	.set	PCB_R6,		40
	.set	PCB_R7,		44
	.set	PCB_R8,		48
	.set	PCB_R9,		52
	.set	PCB_R10,	56
	.set	PCB_R11,	60
	.set	PCB_R12,	64
	.set	PCB_R13,	68
	.set	PCB_PC,		72
	.set	PCB_PSL,	76
	.set	PCB_P0BR,	80
	.set	PCB_P0LR,	84
	.set	PCB_P1BR,	88
	.set	PCB_P1LR,	92
/*
 * Software pcb extension
 */
	.set	PCB_SZPT,	96	/* number of user page table pages */
	.set	PCB_CMAP2,	100	/* saved cmap2 across cswitch (ick) */
	.set	PCB_SSWAP,	104	/* flag for non-local goto */
	.set	PCB_SIGC,	108	/* signal trampoline code */
E 5
E 1
