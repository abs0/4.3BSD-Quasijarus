h45413
s 00006/00000/00033
d D 7.2 87/01/13 10:57:48 karels 9 8
c mv machine dependent from sys_process.c
e
s 00001/00001/00032
d D 7.1 86/06/05 00:47:28 mckusick 8 7
c 4.3BSD release version
e
s 00001/00000/00032
d D 6.3 85/06/08 22:16:39 mckusick 7 6
c botched copyright
e
s 00007/00001/00025
d D 6.2 85/06/08 13:45:21 mckusick 6 5
c Add copyright
e
s 00000/00000/00026
d D 6.1 83/07/29 07:21:04 sam 5 4
c 4.2 distribution
e
s 00001/00001/00025
d D 4.2 81/02/19 21:42:06 wnj 4 3
c %G%->%E%
e
s 00000/00000/00026
d D 4.1 80/11/09 17:01:39 bill 3 2
c stamp for 4bsd
e
s 00001/00001/00025
d D 3.2 80/06/07 03:00:33 bill 2 1
c %H%->%G%
e
s 00026/00000/00000
d D 3.1 80/04/09 16:25:15 bill 1 0
c date and time created 80/04/09 16:25:15 by bill
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%H%	*/
E 2
I 2
D 4
/*	%M%	%I%	%G%	*/
E 4
I 4
D 6
/*	%M%	%I%	%E%	*/
E 6
E 4
E 2
/*
I 6
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

I 7
/*
E 7
E 6
 * Location of the users' stored
 * registers relative to R0.
 * Usage is u.u_ar0[XX].
 */
#define	R0	(-18)
#define	R1	(-17)
#define	R2	(-16)
#define	R3	(-15)
#define	R4	(-14)
#define	R5	(-13)
#define	R6	(-12)
#define	R7	(-11)
#define	R8	(-10)
#define	R9	(-9)
#define	R10	(-8)
#define	R11	(-7)
#define	R12	(-21)
#define	R13	(-20)

#define AP	(-21)
#define	FP	(-20)
#define	SP	(-5)
#define	PS	(-1)
#define	PC	(-2)
I 9

#ifdef IPCREG
#define	NIPCREG 16
int ipcreg[NIPCREG] =
	{R0,R1,R2,R3,R4,R5,R6,R7,R8,R9,R10,R11,AP,FP,SP,PC};
#endif
E 9
E 1
