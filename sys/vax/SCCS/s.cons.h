h16122
s 00001/00001/00038
d D 7.1 86/06/05 00:42:09 mckusick 14 13
c 4.3BSD release version
e
s 00016/00005/00023
d D 6.3 85/09/16 20:58:40 karels 13 12
c rearrange tocons bits for 8600 support; let's get the useracc
c RW flag right (maybe use symbolic defn's?)
e
s 00007/00001/00021
d D 6.2 85/06/08 13:40:58 mckusick 12 11
c Add copyright
e
s 00000/00000/00022
d D 6.1 83/07/29 07:19:36 sam 11 10
c 4.2 distribution
e
s 00009/00008/00013
d D 4.6 81/02/23 20:48:12 wnj 10 9
c pad with 0's
e
s 00001/00001/00020
d D 4.5 81/02/19 21:39:49 wnj 9 8
c %G%->%E%
e
s 00003/00008/00018
d D 4.4 81/02/03 23:03:55 wnj 8 7
c cleanup to console flags (aps/kre)
e
s 00007/00000/00019
d D 4.3 80/12/17 11:45:56 wnj 7 6
c combined 750/780
e
s 00003/00002/00016
d D 4.2 80/11/09 17:30:50 bill 6 5
c new boot flags
e
s 00000/00000/00018
d D 4.1 80/11/09 17:00:46 bill 5 4
c stamp for 4bsd
e
s 00001/00001/00017
d D 3.3 80/06/07 02:56:54 bill 4 3
c %H%->%G%
e
s 00002/00000/00016
d D 3.2 80/04/14 18:18:25 bill 3 1
c added TXDB_AUTOR and TXDB_BOOT
e
s 00001/00001/00015
d R 3.2 80/04/14 18:14:33 bill 2 1
c added TXDB_AUTOR and TXDB_BOOT
e
s 00016/00000/00000
d D 3.1 80/04/09 16:23:38 bill 1 0
c date and time created 80/04/09 16:23:38 by bill
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%H%	*/
E 4
I 4
D 9
/*	%M%	%I%	%G%	*/
E 9
I 9
D 12
/*	%M%	%I%	%E%	*/
E 12
I 12
/*
D 14
 * Copyright (c) 1982 Regents of the University of California.
E 14
I 14
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 14
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 12
E 9
E 4

/*
 * VAX console interface registers
 */

D 10
#define	RXCS_IE		0x40		/* receiver interrupt enable */
#define	RXCS_DONE	0x80		/* receiver done */
#define	RXDB_DATA	0xff		/* received character */
#define	RXDB_ID		0xf00		/* channel id */
E 10
I 10
#define	RXCS_IE		0x00000040	/* receiver interrupt enable */
#define	RXCS_DONE	0x00000080	/* receiver done */

#define	RXDB_DATA	0x000000ff	/* received character */
#define	RXDB_ID		0x00000f00	/* channel id */
E 10
#define	RXDB_ERR	0x80000000	/* receiver error */

D 10
#define	TXCS_IE		0x40		/* transmitter interrupt enable */
#define	TXCS_RDY	0x80		/* transmitter ready for next char */
#define	TXDB_DATA	0xff		/* transmitter byte */
#define	TXDB_ID		0xf00		/* channel id */
E 10
I 10
#define	TXCS_IE		0x00000040	/* transmitter interrupt enable */
#define	TXCS_RDY	0x00000080	/* transmitter ready for next char */
I 13
#if VAX8600
#define	TXCS_ID		0x00000300	/* interrupt ID field */
#define	TXCS_WMASK	0x00008000	/* enable mask write */
#define	TXCS_TXMASK	0x00ff0000	/* transmit enable channel mask: */
#define	TXCS_CTERM	0x00010000	/*	console terminal */
#define	TXCS_RTERM	0x00020000	/*	remote diagnostic port */
#define	TXCS_EMM	0x00040000	/*	Environmental Monitor Module */
#define	TXCS_LCONS	0x00080000	/*	Logical console */
#endif

E 13
#define	TXDB_DATA	0x000000ff	/* transmitter byte */
D 13
#define	TXDB_ID		0x00000f00	/* channel id */
E 13
I 13
#define	TXDB_ID		0x00000f00	/* channel id- not on 8600 */
#define	TXDB_CONS	0x00000f00	/* channel id for console subsystem */
E 13
E 10
I 7

D 8
#if VAX==780
E 7
I 3
D 6
#define	TXDB_AUTOR	0xf03		/* auto-restart command */
#define	TXDB_BOOT	0xf04		/* boot command */
E 6
I 6
#define	TXDB_WSI	0xf02		/* set warm start inhibit */
#define	TXDB_CWSI	0xf03		/* clear warm start inhibit */
#define	TXDB_BOOT	0xf04		/* enable boot */
I 7
#endif
#if VAX==750
E 8
I 8
D 13
#define	TXDB_DONE	0xf01		/* software done */
E 8
#define	TXDB_BOOT	0xf02		/* reboot */
D 8
#define	TXDB_CCSF	0xf04		/* clear cold-start flag */
#endif
E 8
I 8
#define	TXDB_CWSI	0xf03		/* clear warm start inhibit */
#define	TXDB_CCSI	0xf04		/* clear cold-start inhibit */
E 13
I 13
#define	TXDB_DONE	0x01		/* software done */
#define	TXDB_BOOT	0x02		/* reboot */
#define	TXDB_CWSI	0x03		/* clear warm start inhibit */
#define	TXDB_CCSI	0x04		/* clear cold-start inhibit */
E 13
E 8
E 7
E 6
E 3
E 1
