h38730
s 00006/00000/00061
d D 5.2 86/11/11 21:07:10 mckusick 8 7
c add CCI (tahoe) support
e
s 00007/00003/00054
d D 5.1 85/06/05 15:47:43 dist 7 6
c Add copyright
e
s 00000/00000/00057
d D 2.1 84/02/08 20:42:22 aoki 6 5
c synchronize to version 2
e
s 00000/00000/00057
d D 1.5 83/09/19 07:08:39 thien 5 4
c changing to unlinted source
e
s 00020/00003/00037
d D 1.4 83/02/02 11:28:39 peter 4 3
c use pre-defined machine types to define machine-dependent characteristics.
e
s 00012/00005/00028
d D 1.3 83/02/01 21:42:58 peter 3 2
c use pre-processor defines for machine type.
c should use machine type for ADDR16/32 and DEC11.
e
s 00001/00000/00032
d D 1.2 81/03/06 22:56:25 mckusic 2 1
c add DEC11 mode
e
s 00032/00000/00000
d D 1.1 80/10/01 22:59:14 peter 1 0
c date and time created 80/10/01 22:59:14 by peter
e
u
U
t
T
I 1
D 7
/* Copyright (c) 1979 Regents of the University of California */

/* static	char sccsid[] = "%Z%%M% %I% %G%"; */
E 7
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 7

/*
 *	am i generating an obj file (OBJ),
 *	postfix binary input to the 2nd pass of the portable c compiler (PC),
 *	or pTrees (PTREE)?
 */
#undef	OBJ
#define	PC
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
I 8
 *	tahoe	for cci power 6/32
E 8
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
D 4
#undef	ADDR16
#define	ADDR32
#undef	DEC11
E 4
I 4
#ifdef vax
#   undef	ADDR16
#   define	ADDR32
#   define	DEC11
#endif vax
#ifdef pdp11
#   define	ADDR16
#   undef	ADDR32
#   define	DEC11
#endif vax
#ifdef mc68000
#   undef	ADDR16
#   define	ADDR32
#   undef	DEC11
#endif mc68000
I 8
#ifdef tahoe
#   undef	ADDR16
#   define	ADDR32
#   undef	DEC11
#endif tahoe
E 8
#ifdef z8000
#   define	ADDR16
#   undef	ADDR32
#   undef	DEC11
#endif z8000
E 4

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
D 3

E 3
E 1
