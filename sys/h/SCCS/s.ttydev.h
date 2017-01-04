h47258
s 00000/00007/00044
d D 7.2 86/10/13 22:07:52 karels 7 6
c rm old hardware defs
e
s 00001/00001/00050
d D 7.1 86/06/04 23:30:27 mckusick 6 5
c 4.3BSD release version
e
s 00007/00001/00044
d D 6.2 85/06/08 15:11:06 mckusick 5 4
c Add copyright
e
s 00000/00000/00045
d D 6.1 83/07/29 06:14:40 sam 4 3
c 4.2 distribution
e
s 00007/00004/00038
d D 4.3 83/05/18 02:42:26 sam 3 2
c sun changes
e
s 00007/00000/00035
d D 4.2 82/12/05 21:54:39 sam 2 1
c handle multiple #include's cleanly; include more stuff from tty.h
e
s 00035/00000/00000
d D 4.1 82/12/02 11:26:56 sam 1 0
c date and time created 82/12/02 11:26:56 by sam
e
u
U
t
T
I 1
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
/*
D 6
 * Copyright (c) 1982 Regents of the University of California.
E 6
I 6
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 5

/*
 * Terminal definitions related to underlying hardware.
 */
I 2
#ifndef _TTYDEV_
#define	_TTYDEV_
E 2

I 2
D 3
/* hardware bits */
#define	DONE	0200
#define	IENABLE	0100

E 3
E 2
/*
 * Speeds
 */
#define B0	0
#define B50	1
#define B75	2
#define B110	3
#define B134	4
#define B150	5
#define B200	6
#define B300	7
#define B600	8
#define B1200	9
#define	B1800	10
#define B2400	11
#define B4800	12
#define B9600	13
#define EXTA	14
#define EXTB	15

#ifdef KERNEL
I 3
/*
D 7
 * Hardware bits.
 * SHOULD NOT BE HERE.
 */
#define	DONE	0200
#define	IENABLE	0100

E 3
/*
E 7
 * Modem control commands.
 */
#define	DMSET		0
#define	DMBIS		1
#define	DMBIC		2
#define	DMGET		3
I 2
#endif
E 2
#endif
E 1
