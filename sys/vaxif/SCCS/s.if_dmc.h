h43188
s 00007/00006/00105
d D 7.5 99/09/07 11:33:41 msokolov 11 10
x 8
c Change the MTU back to 1284. Sure, 1500 is more reasonable, but we have to keep
c compatibility with existing stable releases which all universally agree on
c 1284...
e
s 00013/00002/00099
d D 7.4 88/08/04 15:16:10 bostic 10 9
c add Berkeley specific copyright
e
s 00003/00003/00098
d D 7.3 88/05/26 09:40:13 karels 9 8
c '8' isn't an octal digit
e
s 00002/00001/00099
d D 7.2 87/12/12 19:38:48 karels 8 7
c change DMCMTU from 1284 to 1500
e
s 00001/00001/00099
d D 7.1 86/06/05 01:35:14 mckusick 7 6
c 4.3BSD release version
e
s 00007/00001/00093
d D 6.4 85/06/08 13:53:41 mckusick 6 5
c Add copyright
e
s 00029/00017/00065
d D 6.3 84/12/20 16:10:46 karels 5 4
c from salkind
e
s 00018/00002/00064
d D 6.2 84/09/26 10:14:56 tef 4 3
c new defines for use with new if_dmc.c
e
s 00000/00000/00066
d D 6.1 83/07/29 07:37:21 sam 3 2
c 4.2 distribution
e
s 00001/00001/00065
d D 4.2 82/02/21 12:12:07 sam 2 1
c cosmetics
e
s 00066/00000/00000
d D 4.1 82/02/15 11:46:52 root 1 0
c date and time created 82/02/15 11:46:52 by root
e
u
U
t
T
I 1
D 6
/*	%M%	%I%	%E%	*/
E 6
I 6
/*
D 7
 * Copyright (c) 1982 Regents of the University of California.
E 7
I 7
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 7
D 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
I 10
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
E 10
 *
 *	%W% (Berkeley) %G%
 */
E 6

/*
 * DMC-11 Interface
 */

struct dmcdevice {
D 5
	union {
		char	b[8];
		short	w[4];
	} un;
E 5
I 5
        char    bsel0;
	char 	bsel1;
	char	bsel2;
	char 	bsel3;
	short	sel4;
	short	sel6;
E 5
};

D 5
#define	bsel0	un.b[0]
#define	bsel1	un.b[1]
#define	bsel2	un.b[2]
#define	bsel3	un.b[3]
#define	bsel4	un.b[4]
#define	bsel5	un.b[5]
#define	bsel6	un.b[6]
#define	bsel7	un.b[7]
#define	sel0	un.w[0]
#define	sel2	un.w[1]
#define	sel4	un.w[2]
#define	sel6	un.w[3]
E 5
I 5
/*
D 11
 * dmc software packet encapsulation.  This allows the dmc
 * link to be multiplexed among several protocols.
 * The first eight bytes of the dmc header are garbage,
 * since on a vax the uba has been known to mung these
 * bytes.  The next two bytes encapsulate packet type.
E 11
I 11
 * dmc/dmv software packet encapsulation.  This allows the
 * dmc/dmv link to be multiplexed among several protocols.
 * The first eight bytes of the dmc/dmv header are garbage
 * for historical reasons (the guy who wrote the original
 * dmc driver had a broken uba that munged these bytes).
 * The next two bytes encapsulate packet type.
E 11
 */
struct dmc_header {
D 11
	char	dmc_buf[8];	/* space for uba on vax */
E 11
I 11
	char	dmc_buf[8];
E 11
	short	dmc_type;	/* encapsulate packet type */
};
E 5

D 4
#define	DMCMTU	(2048)
E 4
I 4
D 5
#define	DMCMTU	(1024)
E 5
I 5
/* packet types */
#define	DMC_IPTYPE	1
#define	DMC_TRAILER	2
#define	DMC_NTRAILER	16

/*
 * DMCMTU includes space for data (1024) + 
 * protocol header (256) + trailer descriptor (4).
 * The software link encapsulation header (dmc_header)
 * is handled separately.
I 8
	#define DMCMTU  1284
E 8
 */
D 8
#define DMCMTU  1284
E 8
I 8
#define DMCMTU  1500
E 8
E 5
E 4

D 2
#define RDYSCAN	16	/* loop delay for RDYI after RQI */
E 2
I 2
#define	RDYSCAN	16	/* loop delay for RDYI after RQI */
E 2

/* defines for bsel0 */
#define	DMC_BACCI	0
#define	DMC_CNTLI	1
#define	DMC_PERR	2
#define	DMC_BASEI	3
#define	DMC_WRITE	0		/* transmit block */
#define	DMC_READ	4		/* read block */
#define	DMC_RQI		0040		/* port request bit */
#define	DMC_IEI		0100		/* enable input interrupts */
#define	DMC_RDYI	0200		/* port ready */
I 4
D 9
#define	DMC0BITS	"\10\8RDI\7IEI\6RQI"
E 9
I 9
#define	DMC0BITS	"\10\10RDI\7IEI\6RQI"
E 9
E 4

/* defines for bsel1 */
#define	DMC_MCLR	0100		/* DMC11 Master Clear */
#define	DMC_RUN		0200		/* clock running */
I 4
D 9
#define	DMC1BITS	"\10\8RUN\7MCLR"
E 9
I 9
#define	DMC1BITS	"\10\10RUN\7MCLR"
E 9
E 4

/* defines for bsel2 */
#define	DMC_BACCO	0
#define	DMC_CNTLO	1
#define	DMC_OUX		0		/* transmit block */
#define	DMC_OUR		4		/* read block */
#define	DMC_IEO		0100		/* enable output interrupts */
#define	DMC_RDYO	0200		/* port available */
I 4
D 9
#define	DMC2BITS	"\10\8RDO\7IEO"
E 9
I 9
#define	DMC2BITS	"\10\10RDO\7IEO"
E 9
E 4

/* defines for CNTLI mode */
#define	DMC_HDPLX	02000		/* half duplex DDCMP operation */
#define	DMC_SEC		04000		/* half duplex secondary station */
#define	DMC_MAINT	00400		/* enter maintenance mode */

/* defines for BACCI/O and BASEI mode */
#define	DMC_XMEM	0140000		/* xmem bit position */
#define	DMC_CCOUNT	0037777		/* character count mask */
#define	DMC_RESUME	0002000		/* resume (BASEI only) */

/* defines for CNTLO */
#define	DMC_CNTMASK	01777
D 4
#define	DMC_FATAL	01620
E 4
I 4

#define	DMC_DATACK	01
#define	DMC_TIMEOUT	02
#define	DMC_NOBUFS	04
#define	DMC_MAINTREC	010
#define	DMC_LOSTDATA	020
#define	DMC_DISCONN	0100
#define	DMC_START	0200
#define	DMC_NEXMEM	0400
#define	DMC_ERROR	01000

#define	DMC_FATAL (DMC_ERROR|DMC_NEXMEM|DMC_START|DMC_LOSTDATA|DMC_MAINTREC)
#define	CNTLO_BITS	\
   "\10\12ERROR\11NEXMEM\10START\7DISC\5LSTDATA\4MAINT\3NOBUF\2TIMEO\1DATACK"
E 4
E 1
