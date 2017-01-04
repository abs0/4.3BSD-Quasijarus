h38482
s 00001/00000/00033
d D 7.2 87/12/10 18:44:03 karels 11 10
c watch out for bogus combinations of vax options with compat mode
e
s 00001/00001/00032
d D 7.1 86/06/05 00:47:07 mckusick 10 9
c 4.3BSD release version
e
s 00007/00001/00026
d D 6.2 85/06/08 13:44:51 mckusick 9 8
c Add copyright
e
s 00000/00000/00027
d D 6.1 83/07/29 07:20:57 sam 8 7
c 4.2 distribution
e
s 00005/00001/00022
d D 4.4 81/04/22 18:38:08 wnj 7 6
c fix bug in PSL_FPD clearing
e
s 00014/00014/00009
d D 4.3 81/02/23 20:52:04 wnj 6 5
c put in leading 0's
e
s 00001/00001/00022
d D 4.2 81/02/19 21:41:56 wnj 5 4
c %G%->%E%
e
s 00000/00000/00023
d D 4.1 80/11/09 17:01:33 bill 4 3
c stamp for 4bsd
e
s 00001/00001/00022
d D 3.3 80/06/07 03:00:11 bill 3 2
c %H%->%G%
e
s 00004/00002/00019
d D 3.2 80/05/15 17:22:05 bill 2 1
c more symbolic!
e
s 00021/00000/00000
d D 3.1 80/04/09 16:25:05 bill 1 0
c date and time created 80/04/09 16:25:05 by bill
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%H%	*/
E 3
I 3
D 5
/*	%M%	%I%	%G%	*/
E 5
I 5
D 9
/*	%M%	%I%	%E%	*/
E 9
I 9
/*
D 10
 * Copyright (c) 1982 Regents of the University of California.
E 10
I 10
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 9
E 5
E 3

/*
 * VAX program status longword
 */

D 6
#define	PSL_C		0x1		/* carry bit */
#define	PSL_V		0x2		/* overflow bit */
#define	PSL_Z		0x4		/* zero bit */
#define	PSL_N		0x8		/* negative bit */
I 2
#define	PSL_ALLCC	0xf		/* all cc bits - unlikely */
E 2
#define	PSL_T		0x10		/* trace enable bit */
#define	PSL_IV		0x20		/* integer overflow enable bit */
#define	PSL_FU		0x40		/* floating point underflow enable */
#define	PSL_DV		0x80		/* decimal overflow enable bit */
#define	PSL_IPL		0x1f0000	/* interrupt priority level */
D 2
#define	PSL_PRVMOD	0xc00000	/* previous mode */
#define	PSL_CURMOD	0x3000000	/* current mode */
E 2
I 2
#define	PSL_PRVMOD	0xc00000	/* previous mode (all on is user) */
#define	PSL_CURMOD	0x3000000	/* current mode (all on is user) */
E 2
#define	PSL_IS		0x4000000	/* interrupt stack */
#define	PSL_FPD		0x8000000	/* first part done */
E 6
I 6
#define	PSL_C		0x00000001	/* carry bit */
#define	PSL_V		0x00000002	/* overflow bit */
#define	PSL_Z		0x00000004	/* zero bit */
#define	PSL_N		0x00000008	/* negative bit */
#define	PSL_ALLCC	0x0000000f	/* all cc bits - unlikely */
#define	PSL_T		0x00000010	/* trace enable bit */
#define	PSL_IV		0x00000020	/* integer overflow enable bit */
#define	PSL_FU		0x00000040	/* floating point underflow enable */
#define	PSL_DV		0x00000080	/* decimal overflow enable bit */
#define	PSL_IPL		0x001f0000	/* interrupt priority level */
#define	PSL_PRVMOD	0x00c00000	/* previous mode (all on is user) */
#define	PSL_CURMOD	0x03000000	/* current mode (all on is user) */
#define	PSL_IS		0x04000000	/* interrupt stack */
#define	PSL_FPD		0x08000000	/* first part done */
E 6
#define	PSL_TP		0x40000000	/* trace pending */
#define	PSL_CM		0x80000000	/* compatibility mode */
I 2
D 7
#define	PSL_USERCLR	0x3c20ff00	/* bits must be clear in user mode */
E 7
I 7

#define	PSL_MBZ		0x3020ff00	/* must be zero bits */

#define	PSL_USERSET	(PSL_PRVMOD|PSL_CURMOD)
#define	PSL_USERCLR	(PSL_IS|PSL_IPL|PSL_MBZ)
I 11
#define	PSL_CM_CLR	(PSL_FPD|PSL_DV|PSL_FU|PSL_IV)
E 11
E 7
E 2
E 1
