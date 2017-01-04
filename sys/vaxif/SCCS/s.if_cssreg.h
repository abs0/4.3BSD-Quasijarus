h59842
s 00013/00002/00065
d D 7.2 88/08/04 15:14:08 bostic 5 4
c add Berkeley specific header
e
s 00001/00001/00066
d D 7.1 86/06/05 01:34:30 mckusick 4 3
c 4.3BSD release version
e
s 00007/00001/00060
d D 6.2 85/06/08 13:52:21 mckusick 3 2
c Add copyright
e
s 00000/00000/00061
d D 6.1 83/07/29 07:37:13 sam 2 1
c 4.2 distribution
e
s 00061/00000/00000
d D 4.1 82/07/20 22:39:15 sam 1 0
c date and time created 82/07/20 22:39:15 by sam
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
D 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
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
E 5
 *
 *	%W% (Berkeley) %G%
 */
E 3

/* 
 * DEC/CSS IMP11-A ARPAnet interface
 */

struct cssdma {
	short	wc;		/* word count */
	u_short	ba;		/* bus address (low 16 bits) */
	short	csr;		/* status register */
	short	db;		/* data buffer*/
};

struct cssdevice {
	struct	cssdma	css_output;	/* transmit DR11-B */
	struct	cssdma	css_hole;	/* unclever gap */
	struct	cssdma	css_input;	/* receive DR11-B */
};

#define css_icsr        css_input.csr
#define css_iba         css_input.ba
#define css_iwc         css_input.wc
#define css_ocsr        css_output.csr
#define css_oba         css_output.ba
#define css_owc         css_output.wc

/*
 * Bits Common to both input and out CSR's
 */
#define CSS_ERR         0x8000          /* error present */
#define CSS_NXM         0x4000          /* non-existant memory */
#define	CSS_ATTN	0x2000		/* attention */
#define	CSS_MAINT	0x1000		/* maintenance mode */
#define	CSS_CYCLE	0x0100		/* force bus cycle */
#define CSS_RDY         0x0080          /* ready */
#define CSS_IE          0x0040          /* interrupt enable */
#define	CSS_XA		0x0030		/* extended address bits */
#define	CSS_CLR		0x0020		/* clear status (reset) */
#define CSS_GO          0x0001          /* start operation */

/*
 * Input Control Status Register
 */
#define IN_EOM          0x0800          /* end-of-message recieved */
#define IN_IMPNR	0x0400          /* IMP not ready */
#define IN_RLE          0x0200          /* ready line error */
#define IN_WEN          0x0008          /* write enable */
#define IN_HRDY         0x0004          /* host ready */

#define CSS_INBITS \
"\20\20ERR\17NXM\16ATTN\15MAINT\14EOM\13IMPNR\12RLE\11CYCLE\10RDY\7IE\6XBA17\5XBA16\4WE\3HRDY\2CLR\1GO"


/*
 * Output Control Status Register
 */
#define OUT_TXEC	0x0008          /* tx error clear */
#define OUT_ENLB	0x0004          /* enable last bit */

#define CSS_OUTBITS \
"\20\20ERR\17NXM\16ATTN\15MAINT\11CYCLE\10RDY\7IE\6XBA17\5XBA16\4TXEC\3ENLB\2CLR\1GO"
E 1
