h16498
s 00011/00000/00113
d D 7.3 04/03/06 01:48:21 msokolov 25 24
c nexus notion extended to VAXBI, XMI, CDAL, etc.
e
s 00000/00004/00113
d D 7.2 86/08/09 16:11:32 karels 24 22
c microvax II no longer has nexi
e
s 00002/00004/00113
d R 7.2 86/08/09 15:12:03 karels 23 22
c microvax II no longer has nexi
e
s 00001/00001/00116
d D 7.1 86/06/05 00:46:37 mckusick 22 21
c 4.3BSD release version
e
s 00004/00000/00113
d D 6.7 86/04/22 10:48:20 kridle 21 20
c Added MicroVAX II Support (KA630)
e
s 00007/00006/00106
d D 6.6 86/03/30 19:02:23 karels 20 19
c fix cleanups
e
s 00005/00000/00107
d D 6.5 85/09/07 23:13:14 bloom 19 18
c add support for 256K memory chips (from ghg@purdue)
e
s 00001/00001/00106
d D 6.4 85/09/04 08:45:11 bloom 18 17
c missed ifdef for 8600
e
s 00009/00000/00098
d D 6.3 85/08/05 18:56:08 bloom 17 16
c add support for 8600
e
s 00007/00001/00091
d D 6.2 85/06/08 13:44:24 mckusick 16 15
c Add copyright
e
s 00000/00000/00092
d D 6.1 83/08/01 12:08:31 sam 15 13
c 4.2 distribution
e
s 00000/00000/00092
d R 4.13 83/08/01 12:05:12 sam 14 13
c 4.2 distribution
e
s 00006/00000/00086
d D 4.12 83/08/01 12:03:29 sam 13 11
c add support for second uba on 750; move rpb in front of 
c scb, otherwise it would be at variable location; add nexi numbers 
c for 64K chip controllers and ci
e
s 00000/00000/00086
d R 6.1 83/07/29 07:20:49 sam 12 11
c 4.2 distribution
e
s 00003/00003/00083
d D 4.11 82/05/26 15:35:46 sam 11 10
c 7ZZ -> 730
e
s 00003/00003/00083
d D 4.10 81/04/03 00:09:41 root 10 9
c s/730/7ZZ
e
s 00001/00001/00085
d D 4.9 81/04/02 15:24:12 root 9 8
c nnex730 set to 16
e
s 00004/00000/00082
d D 4.8 81/03/21 16:13:11 wnj 8 7
c 730 changes
e
s 00012/00010/00070
d D 4.7 81/03/13 21:50:08 wnj 7 6
c new defns for better percpu and 11/750 autoconf using nexus's
e
s 00002/00002/00078
d D 4.6 81/03/09 00:27:15 wnj 6 5
c lint
e
s 00009/00001/00071
d D 4.5 81/03/06 11:40:06 wnj 5 4
c spelling errors and add NEXFLT_BITS and UBASR_BITS
e
s 00001/00001/00071
d D 4.4 81/02/27 02:38:42 wnj 4 3
c dynamic alloc kernel version
e
s 00009/00001/00063
d D 4.3 81/02/26 23:17:42 wnj 3 2
c def and use NNEXUS
e
s 00001/00001/00063
d D 4.2 81/02/19 21:41:36 wnj 2 1
c %G%->%E%
e
s 00064/00000/00000
d D 4.1 81/02/19 21:34:20 wnj 1 0
c date and time created 81/02/19 21:34:20 by wnj
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%G%	*/
E 2
I 2
D 16
/*	%M%	%I%	%E%	*/
E 16
I 16
/*
D 22
 * Copyright (c) 1982 Regents of the University of California.
E 22
I 22
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 22
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 16
E 2

/*
 * Information about nexus's.
I 7
 *
 * Each machine has an address of backplane slots (nexi).
 * Each nexus is some type of adapter, whose code is the low
 * byte of the first word of the adapter address space.
 * At boot time the system looks through the array of available
 * slots and finds the interconnects for the machine.
E 7
 */
I 20
#define	NNEXSBI		16
E 20
I 17
#if VAX8600
D 20
#define	NNEX8600	16
E 20
I 20
#define	NNEX8600	NNEXSBI
E 20
#define	NEXA8600	((struct nexus *)(0x20000000))
#define	NEXB8600	((struct nexus *)(0x22000000))
#endif
E 17
#if VAX780
D 20
#define	NNEX780	16
E 20
I 20
#define	NNEX780	NNEXSBI
E 20
#define	NEX780	((struct nexus *)0x20000000)
#endif
#if VAX750
D 7
#define	NNEX750	4
#define	NEX750	((struct nexus *)0xf28000)
E 7
I 7
D 20
#define	NNEX750	16
E 20
I 20
#define	NNEX750	NNEXSBI
E 20
#define	NEX750	((struct nexus *)0xf20000)
E 7
#endif
I 8
D 10
#if VAX730
D 9
#define	NNEX730	8
E 9
I 9
#define	NNEX730	16
E 9
#define	NEX730	((struct nexus *)0xf20000)
E 10
I 10
D 11
#if VAX7ZZ
#define	NNEX7ZZ	16
#define	NEX7ZZ	((struct nexus *)0xf20000)
E 11
I 11
#if VAX730
D 20
#define	NNEX730	16
E 20
I 20
#define	NNEX730	NNEXSBI
E 20
#define	NEX730	((struct nexus *)0xf20000)
E 11
E 10
#endif
I 21
D 24
#if VAX630
#define	NNEX630	1
#define	NEX630	((struct nexus *)0x20088000)
#endif
E 24
E 21
E 8
#define	NEXSIZE	0x2000

I 17
#if VAX8600
D 20
#define	MAXNNEXUS 32
E 20
I 20
#define	MAXNNEXUS (2 * NNEXSBI)
E 20
#else 
E 17
I 3
D 7
#if VAX780
#define	NNEXUS	16
#else
#define	NNEXUS	6		/* 4 mba slots + mem + uba */
#endif
E 7
I 7
D 20
#define	MAXNNEXUS 16
E 20
I 20
#define	MAXNNEXUS NNEXSBI
E 20
I 17
#endif
E 17
E 7

#ifndef LOCORE
E 3
struct	nexus {
	union nexcsr {
		long	nex_csr;
		u_char	nex_type;
	} nexcsr;
	long	nex_pad[NEXSIZE / sizeof (long) - 1];
};
I 3
D 4
#endif
E 4
E 3
#ifdef	KERNEL
D 3
extern struct nexus nexus[16];
E 3
I 3
D 6
extern struct nexus nexus[NNEXUS];
E 6
I 6
D 7
struct nexus nexus[NNEXUS];
E 7
I 7
struct nexus nexus[MAXNNEXUS];
E 7
E 6
I 4
#endif
E 4
E 3
#endif

/*
 * Bits in high word of nexus's.
 */
#define	SBI_PARFLT	(1<<31)		/* sbi parity fault */
#define	SBI_WSQFLT	(1<<30)		/* write sequence fault */
D 5
#define	SBI_UIDFLT	(1<<29)		/* unexpected read data fault */
E 5
I 5
#define	SBI_URDFLT	(1<<29)		/* unexpected read data fault */
E 5
#define	SBI_ISQFLT	(1<<28)		/* interlock sequence fault */
#define	SBI_MXTFLT	(1<<27)		/* multiple transmitter fault */
#define	SBI_XMTFLT	(1<<26)		/* transmit fault */

#define	NEX_CFGFLT	(0xfc000000)
I 5

#ifndef LOCORE
D 18
#if VAX780
E 18
I 18
#if defined(VAX780) || defined(VAX8600)
E 18
#define	NEXFLT_BITS \
"\20\40PARFLT\37WSQFLT\36URDFLT\35ISQFLT\34MXTFLT\33XMTFLT"
D 6
extern	char nexflt_bits[];
E 6
I 6
D 7
char	nexflt_bits[];
E 7
E 6
#endif
#endif
E 5

#define	NEX_APD		(1<<23)		/* adaptor power down */
#define	NEX_APU		(1<<22)		/* adaptor power up */

#define	MBA_OT		(1<<21)		/* overtemperature */

#define	UBA_UBINIT	(1<<18)		/* unibus init */
#define	UBA_UBPDN	(1<<17)		/* unibus power down */
#define	UBA_UBIC	(1<<16)		/* unibus initialization complete */

/*
 * Types for nex_type.
 */
I 7
#define	NEX_ANY		0		/* pseudo for handling 11/750 */
E 7
#define	NEX_MEM4	0x08		/* 4K chips, non-interleaved mem */
#define	NEX_MEM4I	0x09		/* 4K chips, interleaved mem */
#define	NEX_MEM16	0x10		/* 16K chips, non-interleaved mem */
#define	NEX_MEM16I	0x11		/* 16K chips, interleaved mem */
#define	NEX_MBA		0x20		/* Massbus adaptor */
#define	NEX_UBA0	0x28		/* Unibus adaptor */
D 7
#define	NEX_UBA1	0x29		/* 4 flavours  for 4 addr spaces */
E 7
I 7
#define	NEX_UBA1	0x29		/* 4 flavours for 4 addr spaces */
E 7
#define	NEX_UBA2	0x2a
#define	NEX_UBA3	0x2b
#define	NEX_DR32	0x30		/* DR32 user i'face to SBI */
I 13
#define	NEX_CI		0x38		/* CI adaptor */
E 13
#define	NEX_MPM0	0x40		/* Multi-port mem */
#define	NEX_MPM1	0x41		/* Who knows why 4 different ones ? */
#define	NEX_MPM2	0x42
#define	NEX_MPM3	0x43
I 13
#define	NEX_MEM64L	0x68		/* 64K chips, non-interleaved, lower */
#define	NEX_MEM64LI	0x69		/* 64K chips, ext-interleaved, lower */
#define	NEX_MEM64U	0x6a		/* 64K chips, non-interleaved, upper */
#define	NEX_MEM64UI	0x6b		/* 64K chips, ext-interleaved, upper */
#define	NEX_MEM64I	0x6c		/* 64K chips, interleaved */
I 19
#define	NEX_MEM256L	0x70		/* 256K chips, non-interleaved, lower */
#define	NEX_MEM256LI	0x71		/* 256K chips, ext-interleaved, lower */
#define	NEX_MEM256U	0x72		/* 256K chips, non-interleaved, upper */
#define	NEX_MEM256UI	0x73		/* 256K chips, ext-interleaved, upper */
#define	NEX_MEM256I	0x74		/* 256K chips, interleaved */
I 25

/*
 * We have extended the notion of nexus beyond SBI and friends to newer VAX
 * nexus buses, including node-based VAXBI and XMI and amorphous nexus buses
 * like CDAL.  We introduce the notion of nexus class to distinguish between
 * these disparate kinds of nexi.
 */
#define	NEXCLASS_SBI	1		/* and friends like CMI */
#define	NEXCLASS_VAXBI	2
#define	NEXCLASS_XMI	3
#define	NEXCLASS_AMORPH	4		/* amorphous nexus buses like CDAL */
E 25
E 19
E 13
E 1
