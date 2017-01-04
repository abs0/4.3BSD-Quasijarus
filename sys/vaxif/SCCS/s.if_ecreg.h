h29753
s 00013/00002/00063
d D 7.2 88/08/04 15:16:48 bostic 9 8
c add Berkeley specific copyright
e
s 00001/00001/00064
d D 7.1 86/06/05 01:35:22 mckusick 8 7
c 4.3BSD release version
e
s 00000/00000/00065
d D 6.4 85/08/09 11:39:40 sklower 7 6
c Latest fixes from Nesheim@cornell
e
s 00001/00001/00064
d D 6.3 85/07/02 22:40:00 sklower 6 5
c Helpful Fixes from Bill Nesheim@Cornell.
e
s 00007/00001/00058
d D 6.2 85/06/08 13:53:53 mckusick 5 4
c Add copyright
e
s 00000/00000/00059
d D 6.1 83/07/29 07:37:33 sam 4 3
c 4.2 distribution
e
s 00001/00000/00058
d D 4.3 82/07/21 09:42:13 feldman 3 2
c 3com updates for 780 (from Bill Reeves)
e
s 00001/00000/00057
d D 4.2 82/06/26 13:59:48 sam 2 1
c more mnemonic
e
s 00057/00000/00000
d D 4.1 82/04/11 02:12:30 feldman 1 0
c date and time created 82/04/11 02:12:30 by feldman
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
D 8
 * Copyright (c) 1982 Regents of the University of California.
E 8
I 8
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 8
D 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 9
I 9
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 9
 *
 *	%W% (Berkeley) %G%
 */
E 5

/*
 * 3Com Ethernet controller registers.
 */
struct ecdevice {
	short	ec_rcr;		/* Receive Control Register */
	short	ec_xcr;		/* Transmit Control Register */
};

/*
 * Control and status bits -- rcr
 */
#define	EC_SPIE		0x8000		/* set parity interrupt enable */
#define	EC_ASTEP	0x4000		/* increment address counter */
#define	EC_AROM		0x2000		/* 1: Use address ROM, 0: use RAM */
#define	EC_PE		0x2000		/* Parity error */
#define	EC_AWCLK	0x1000		/* address write clock bit */
#define	EC_PIE		0x1000		/* Parity interrupt enable (read) */
#define	EC_ADATA	0x0f00		/* address/filtering */
#define	EC_RDONE	0x0080		/* receive done */
I 3
#define	EC_MDISAB	0x0080		/* memory disable */
E 3
#define	EC_RINTEN	0x0040		/* receive interrupt enable */
#define	EC_RCLR		0x0020		/* clear RDONE bit */
#define	EC_RWBN		0x0010		/* submit buffer for receive */
#define	EC_RBN		0x000f		/* buffer number */

#define	EC_RBITS	"\10\16PE\15PIE\10RDONE\7RINTEN"

/*
 * Control and status bits -- xcr
 */
#define	EC_JAM		0x8000		/* collision dectected */
#define	EC_JINTEN	0x4000		/* collision interrupt enable */
#define	EC_JCLR		0x2000		/* clear collision detect */
#define	EC_UECLR	0x0100		/* reset controller */
#define	EC_XDONE	0x0080		/* transmit done */
#define	EC_XINTEN	0x0040		/* transmit interrupt enable */
#define	EC_XCLR		0x0020		/* clear XDONE bit */
#define	EC_XWBN		0x0010		/* submit buffer for transmit */
#define	EC_XBN		0x000f		/* buffer number */

#define	EC_XBITS	"\10\20JAM\17JINTEN\10XDONE\7XINTEN"

/*
 * Useful combinations
 */
D 6
#define	EC_READ		(EC_AROM|0x600|EC_RINTEN|EC_RWBN)
E 6
I 6
#define	EC_READ		(0x600|EC_RINTEN|EC_RWBN)
E 6
#define	EC_WRITE	(EC_JINTEN|EC_XINTEN|EC_XWBN)
I 2
#define	EC_CLEAR	(EC_JINTEN|EC_XINTEN|EC_JCLR)
E 2

/*
 * Buffer number definitions
 */
#define	ECTBF		0		/* Buffer for transmit */
#define	ECRLBF		1		/* First buffer for receive */
#define	ECRHBF		15		/* Last buffer for receive */

#define	ECRDOFF		528		/* Packet offset in read buffer */
E 1
