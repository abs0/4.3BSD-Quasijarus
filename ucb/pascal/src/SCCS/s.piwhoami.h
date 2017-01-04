h15315
s 00006/00000/00057
d D 5.2 86/11/12 09:52:05 mckusick 7 6
c add CCI (tahoe) support
e
s 00007/00003/00050
d D 5.1 85/06/05 15:48:16 dist 6 5
c Add copyright
e
s 00000/00000/00053
d D 2.1 84/02/08 20:42:36 aoki 5 4
c synchronize to version 2
e
s 00001/00000/00052
d D 1.4 83/09/19 07:08:41 thien 4 3
c changing to unlinted source
e
s 00024/00005/00028
d D 1.3 83/01/22 00:52:56 mckusick 3 2
c generalize for port to the mc68000
e
s 00001/00000/00032
d D 1.2 81/03/06 21:18:30 mckusic 2 1
c add DEC11 mode
e
s 00032/00000/00000
d D 1.1 80/10/01 22:59:30 peter 1 0
c date and time created 80/10/01 22:59:30 by peter
e
u
U
t
T
I 1
D 6
/* Copyright (c) 1979 Regents of the University of California */

/* static	char sccsid[] = "%Z%%M% %I% %G%"; */
E 6
I 6
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 6

/*
 *	am i generating an obj file (OBJ),
 *	postfix binary input to the 2nd pass of the portable c compiler (PC),
 *	or pTrees (PTREE)?
 */
#define	OBJ
#undef	PC
#undef	PTREE

/*
D 3
 *	am i the vax or the pdp11 version
E 3
I 3
 *	we assume one of the following will be defined by the preprocessor:
 *	vax	for vaxes
 *	pdp11	for pdp11's
 *	mc68000	for motorola mc68000's
I 7
 *	tahoe	for cci power 6/32's
E 7
E 3
 */
D 3
#define VAX
#undef	PDP11
I 2
#define DEC11
E 3
E 2

/*
I 3
 *	hardware characteristics:
 *	address size (16 or 32 bits) and byte ordering (normal or dec11 family).
 */
#ifdef vax
#undef	ADDR16
#define	ADDR32
#define	DEC11
#endif vax
#ifdef mc68000
#undef	ADDR16
#define	ADDR32
#undef	DEC11
#endif mc68000
I 7
#ifdef tahoe
#undef	ADDR16
#define	ADDR32
#undef	DEC11
#endif tahoe
E 7
#ifdef pdp11
#define	ADDR16
#undef	ADDR32
#define	DEC11
#endif pdp11

/*
E 3
 *	am i pi or pxp?
 */
#define PI
#undef	PXP

/*
 *	am i both passes, or am i only one of the two passes pi0 or pi1?
 */
#define	PI01
#undef	PI0
#undef	PI1
I 4
#define DEBUG
E 4
D 3

E 3
E 1
