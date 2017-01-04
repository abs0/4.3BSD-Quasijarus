h27629
s 00001/00001/00052
d D 7.1 86/06/05 01:06:35 mckusick 4 3
c 4.3BSD release version
e
s 00007/00001/00046
d D 6.2 85/06/08 14:14:18 mckusick 3 2
c Add copyright
e
s 00000/00000/00047
d D 6.1 83/07/29 07:27:13 sam 2 1
c 4.2 distribution
e
s 00047/00000/00000
d D 4.1 82/12/30 13:12:52 sam 1 0
c date and time created 82/12/30 13:12:52 by sam
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
 * Copyright (c) 1982 Regents of the University of California.
E 4
I 4
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 4
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 3

/* 
 * DH-11 device register definitions.
 */
struct dhdevice {
	union {
		short	dhcsr;		/* control-status register */
		char	dhcsrl;		/* low byte for line select */
	} un;
	short	dhrcr;			/* receive character register */
	short	dhlpr;			/* line parameter register */
	u_short dhcar;			/* current address register */
	short	dhbcr;			/* byte count register */
	u_short	dhbar;			/* buffer active register */
	short	dhbreak;		/* break control register */
	short	dhsilo;			/* silo status register */
};

/* Bits in dhcsr */
#define	DH_TI	0100000		/* transmit interrupt */
#define	DH_SI	0040000		/* storage interrupt */
#define	DH_TIE	0020000		/* transmit interrupt enable */
#define	DH_SIE	0010000		/* storage interrupt enable */
#define	DH_MC	0004000		/* master clear */
#define	DH_NXM	0002000		/* non-existant memory */
#define	DH_MM	0001000		/* maintenance mode */
#define	DH_CNI	0000400		/* clear non-existant memory interrupt */
#define	DH_RI	0000200		/* receiver interrupt */
#define	DH_RIE	0000100		/* receiver interrupt enable */

/* Bits in dhlpr */
#define	BITS6	01
#define	BITS7	02
#define	BITS8	03
#define	TWOSB	04
#define	PENABLE	020
/* DEC manuals incorrectly say this bit causes generation of even parity. */
#define	OPAR	040
#define	HDUPLX	040000

#define	DH_IE	(DH_TIE|DH_SIE|DH_RIE)

/* Bits in dhrcr */
#define	DH_PE		0010000		/* parity error */
#define	DH_FE		0020000		/* framing error */
#define	DH_DO		0040000		/* data overrun */
E 1
