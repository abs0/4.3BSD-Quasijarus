h40906
s 00013/00002/00063
d D 7.2 88/08/04 15:12:35 bostic 6 5
c add Berkeley specific copyright
e
s 00001/00001/00064
d D 7.1 86/06/05 01:34:18 mckusick 5 4
c 4.3BSD release version
e
s 00007/00001/00058
d D 6.2 85/06/08 13:51:39 mckusick 4 3
c Add copyright
e
s 00000/00000/00059
d D 6.1 83/07/29 07:37:06 sam 3 2
c 4.2 distribution
e
s 00001/00001/00058
d D 4.2 82/02/21 12:12:03 sam 2 1
c cosmetics
e
s 00059/00000/00000
d D 4.1 82/02/04 12:30:29 root 1 0
c date and time created 82/02/04 12:30:29 by root
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
D 5
 * Copyright (c) 1982 Regents of the University of California.
E 5
I 5
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 5
D 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
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
E 6
 *
 *	%W% (Berkeley) %G%
 */
E 4

/*
 * ACC LH/DH-11 interface
 */

struct accdma {
	short	csr;	/* control and status */
	short	db;	/* data buffer */
	u_short	ba;	/* buss address */
	short	wc;	/* word count */
};

struct accdevice {
	struct	accdma input;
	struct	accdma output;
};

#define	icsr	input.csr
#define	iba	input.ba
#define	iwc	input.wc
#define	ocsr	output.csr
#define	oba	output.ba
#define	owc	output.wc

/*
 * Bits Common to both input and out CSR's
 */
#define	ACC_ERR		0x8000		/* error present */
#define	ACC_NXM		0x4000		/* non-existant memory */
#define	ACC_RDY		0x0080		/* ready */
D 2
#define ACC_IE		0x0040		/* interrupt enable */
E 2
I 2
#define	ACC_IE		0x0040		/* interrupt enable */
E 2
#define	ACC_RESET	0x0002		/* reset interface */
#define	ACC_GO		0x0001		/* start operation */

/*
 * Input Control Status Register
 */
#define IN_EOM		0x2000		/* end-of-message recieved */
#define IN_HRDY		0x0800		/* host ready */
#define IN_IMPBSY	0x0400		/* IMP not ready */
#define IN_RMR		0x0200		/* receive master ready error */
#define IN_IBF		0x0100		/* input data buffer full */
#define IN_WEN		0x0008		/* write enable */
#define IN_MRDY		0x0004		/* master ready */

#define ACC_INBITS \
"\20\20ERR\17NXM\16EOM\14HRDY\13IMPBSY\12RMR\11IBF\10RDY\7IE\
\4WEN\3MRDY\2RESET\1GO"

/*
 * Output Control Status Register
 */
#define OUT_TMR		0x0200		/* transmit master ready error */
#define OUT_BBACK	0x0008		/* bus back */
#define OUT_ENLB 	0x0004		/* enable last bit */

#define ACC_OUTBITS \
"\20\20ERR\17NXM\12TMR\10RDY\7IE\4BBACK\3ENLB\2RESET\1GO"
E 1
