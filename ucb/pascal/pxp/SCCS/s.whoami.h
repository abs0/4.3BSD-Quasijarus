h43850
s 00006/00000/00047
d D 5.2 87/04/07 15:48:33 mckusick 5 4
c update for CCI
e
s 00007/00001/00040
d D 5.1 85/06/05 15:58:35 dist 4 3
c Add copyright
e
s 00000/00000/00041
d D 2.1 84/02/08 20:22:02 aoki 3 2
c synchronizing at version 2
e
s 00038/00002/00003
d D 1.2 83/02/05 17:29:14 mckusick 2 1
c update to have ADDR16, etc
e
s 00005/00000/00000
d D 1.1 83/02/05 12:49:18 mckusick 1 0
c date and time created 83/02/05 12:49:18 by mckusick
e
u
U
t
T
I 1
D 4
/*	%W%	(Berkeley)	%E%	*/
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 4

D 2
#define PXP 1
E 2
I 2
/*
 *	we assume one of the following will be defined by the preprocessor:
 *	vax	for vaxes
 *	pdp11	for pdp11's
 *	mc68000	for motorola mc68000's
I 5
 *	tahoe	for cci power 6/32's
E 5
 */
E 2

D 2
#define putchar pchr
E 2
I 2
/*
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
I 5
#ifdef tahoe
#undef	ADDR16
#define	ADDR32
#undef	DEC11
#endif tahoe
E 5
#ifdef pdp11
#define	ADDR16
#undef	ADDR32
#define	DEC11
#endif pdp11

/*
 *	am i pi or pxp?
 */
#undef PI
#define	PXP

/*
 *	am i both passes, or am i only one of the two passes pi0 or pi1?
 */
#define	PI01
#undef	PI0
#undef	PI1
E 2
E 1
