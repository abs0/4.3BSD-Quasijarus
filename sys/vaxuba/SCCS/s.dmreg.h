h00938
s 00001/00001/00042
d D 7.1 86/06/05 01:08:10 mckusick 4 3
c 4.3BSD release version
e
s 00007/00001/00036
d D 6.2 85/06/08 14:15:35 mckusick 3 2
c Add copyright
e
s 00000/00000/00037
d D 6.1 83/07/29 07:27:25 sam 2 1
c 4.2 distribution
e
s 00037/00000/00000
d D 4.1 82/12/30 13:12:55 sam 1 0
c date and time created 82/12/30 13:12:55 by sam
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
 * DM-11 device register definitions.
 */
struct dmdevice {
	short	dmcsr;		/* control status register */
	short	dmlstat;	/* line status register */
	short	dmpad1[2];
};

/* bits in dm csr */
#define	DM_RF		0100000		/* ring flag */
#define	DM_CF		0040000		/* carrier flag */
#define	DM_CTS		0020000		/* clear to send */
#define	DM_SRF		0010000		/* secondary receive flag */
#define	DM_CS		0004000		/* clear scan */
#define	DM_CM		0002000		/* clear multiplexor */
#define	DM_MM		0001000		/* maintenance mode */
#define	DM_STP		0000400		/* step */
#define	DM_DONE		0000200		/* scanner is done */
#define	DM_IE		0000100		/* interrupt enable */
#define	DM_SE		0000040		/* scan enable */
#define	DM_BUSY		0000020		/* scan busy */

/* bits in dm lsr */
#define	DML_RNG		0000200		/* ring */
#define	DML_CAR		0000100		/* carrier detect */
#define	DML_CTS		0000040		/* clear to send */
#define	DML_SR		0000020		/* secondary receive */
#define	DML_ST		0000010		/* secondary transmit */
#define	DML_RTS		0000004		/* request to send */
#define	DML_DTR		0000002		/* data terminal ready */
#define	DML_LE		0000001		/* line enable */

#define	DML_ON		(DML_DTR|DML_RTS|DML_LE)
#define	DML_OFF		(DML_LE)
E 1
