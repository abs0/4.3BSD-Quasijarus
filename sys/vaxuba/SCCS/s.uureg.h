h58540
s 00001/00001/00036
d D 7.1 86/06/05 01:23:28 mckusick 7 6
c 4.3BSD release version
e
s 00007/00001/00030
d D 6.2 85/06/08 14:30:14 mckusick 6 5
c Add copyright
e
s 00000/00000/00031
d D 6.1 83/07/29 07:30:54 sam 5 4
c 4.2 distribution
e
s 00010/00015/00021
d D 4.3 83/05/08 21:37:16 helge 4 2
c merged constants for receive and xmit status registers
e
s 00010/00015/00021
d R 4.3 83/05/08 21:31:13 helge 3 2
c cleanup
e
s 00016/00016/00020
d D 4.2 83/04/09 14:07:13 helge 2 1
c changed all occurances of 'tu' to 'uu'
e
s 00036/00000/00000
d D 4.1 83/04/09 12:40:52 helge 1 0
c date and time created 83/04/09 12:40:52 by helge
e
u
U
t
T
I 6
/*
D 7
 * Copyright (c) 1982 Regents of the University of California.
E 7
I 7
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 6
I 1

D 6
/*	%M%	%I%	%E%	*/
E 6

/*
D 2
 * TU58 UNIBUS controller registers
E 2
I 2
 * DL11-E/DL11-W UNIBUS (for TU58) controller registers
E 2
 */
D 2
struct tudevice {
	short	turcs;	/* receiver status register */
	short	turdb;	/* receiver data buffer register */
	short	tutcs;	/* transmitter status register */
	short	tutdb;	/* transmitter data buffer register */
E 2
I 2
struct uudevice {
D 4
	short	uurcs;	/* receiver status register */
	short	uurdb;	/* receiver data buffer register */
	short	uutcs;	/* transmitter status register */
	short	uutdb;	/* transmitter data buffer register */
E 4
I 4
	short	rcs;	/* receiver status register */
	short	rdb;	/* receiver data buffer register */
	short	tcs;	/* transmitter status register */
	short	tdb;	/* transmitter data buffer register */
E 4
E 2
};

/*
D 4
 * Receiver status register status/command bits
E 4
I 4
 * Receiver/transmitter status register status/command bits
E 4
 */
D 2
#define TURCS_DONE	0x80	/* Receiver done (byte ready) */
#define TURCS_INTR	0x40	/* Receiver interrupt enable */
E 2
I 2
D 4
#define UURCS_DONE	0x80	/* Receiver done (byte ready) */
#define UURCS_INTR	0x40	/* Receiver interrupt enable */
E 4
I 4
#define UUCS_DONE	0x80	/* done/ready */
#define	UUCS_READY	0x80
#define UUCS_INTR	0x40	/* interrupt enable */
#define	UUCS_MAINT	0x02	/* maintenance check (xmitter only) */
#define	UUCS_BREAK	0x01	/* send break (xmitter only) */
E 4
E 2

/*
 * Receiver data buffer register status bits
 */
D 2
#define	TURDB_ERROR	0x8000	/* Error (overrun or break) */
#define TURDB_ORUN	0x4000	/* Data overrun error */
#define	TURDB_BREAK	0x2000	/* TU58 break */
E 2
I 2
#define	UURDB_ERROR	0x8000	/* Error (overrun or break) */
#define UURDB_ORUN	0x4000	/* Data overrun error */
#define	UURDB_BREAK	0x2000	/* TU58 break */
E 2
D 4

/*
 * Transmitter status register status/command bits
 */
D 2
#define	TUTCS_READY	0x80	/* transmitter ready */
#define	TUTCS_INTR	0x40	/* transmitter interrupt enable */
#define	TUTCS_MAINT	0x02	/* maintenance check */
#define	TUTCS_BREAK	0x01	/* send break */
E 2
I 2
#define	UUTCS_READY	0x80	/* transmitter ready */
#define	UUTCS_INTR	0x40	/* transmitter interrupt enable */
#define	UUTCS_MAINT	0x02	/* maintenance check */
#define	UUTCS_BREAK	0x01	/* send break */
E 4
E 2

D 2
#define	TUDB_DMASK	0x00ff	/* data mask (send and receive data) */
E 2
I 2
#define	UUDB_DMASK	0x00ff	/* data mask (send and receive data) */
E 2

E 1
