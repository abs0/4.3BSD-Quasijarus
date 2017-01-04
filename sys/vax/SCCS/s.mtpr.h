h52948
s 00008/00006/00128
d D 7.7 04/03/18 19:23:21 msokolov 19 18
c generalise a few conditionals from VAX650 to CVAX
c DEC STD 032 IPRs like TODR should not be conditionalised
e
s 00001/00000/00133
d D 7.6 04/01/04 01:45:07 msokolov 18 17
c CADR is known as CCR on SOC
e
s 00002/00000/00131
d D 7.5 88/11/09 09:28:16 tef 17 16
c MCESR register doesn't exist on ka650
e
s 00006/00006/00125
d D 7.4 88/08/27 07:00:56 tef 16 15
c Add support for microvax 3000.
e
s 00072/00037/00059
d D 7.3 88/05/07 14:20:09 karels 15 14
c vax 8200 support from torek: generalize cpu support, ops, clock ops
e
s 00005/00002/00091
d D 7.2 86/08/09 15:10:03 karels 14 13
c generalize uba code to handle Q bus more gracefully
e
s 00001/00001/00092
d D 7.1 86/06/05 00:46:25 mckusick 13 11
c 4.3BSD release version
e
s 00000/00000/00093
d R 6.4 86/04/22 10:48:24 kridle 12 11
c Added MicroVAX II Support (KA630)
e
s 00023/00001/00070
d D 6.3 85/08/05 18:54:10 bloom 11 10
c add support for 8600
e
s 00007/00001/00064
d D 6.2 85/06/08 13:44:14 mckusick 10 9
c Add copyright
e
s 00000/00000/00065
d D 6.1 83/07/29 07:20:45 sam 9 8
c 4.2 distribution
e
s 00002/00002/00063
d D 4.6 83/07/09 00:58:31 sam 8 7
c couldn't configure 730 only
e
s 00002/00002/00063
d D 4.5 81/02/25 23:35:57 wnj 7 6
c convert VAX=??? to VAX???
e
s 00043/00042/00022
d D 4.4 81/02/21 21:29:43 wnj 6 5
c misc changes for first working interlockable version
e
s 00001/00001/00063
d D 4.3 81/02/19 21:41:27 wnj 5 4
c %G%->%E%
e
s 00015/00003/00049
d D 4.2 80/12/17 11:46:16 wnj 4 3
c combined 750/780
e
s 00000/00000/00052
d D 4.1 80/11/09 17:01:16 bill 3 2
c stamp for 4bsd
e
s 00001/00001/00051
d D 3.2 80/06/07 02:58:51 bill 2 1
c %H%->%G%
e
s 00052/00000/00000
d D 3.1 80/04/09 16:24:22 bill 1 0
c date and time created 80/04/09 16:24:22 by bill
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%H%	*/
E 2
I 2
D 5
/*	%M%	%I%	%G%	*/
E 5
I 5
D 10
/*	%M%	%I%	%E%	*/
E 10
I 10
/*
D 13
 * Copyright (c) 1982 Regents of the University of California.
E 13
I 13
D 14
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 14
I 14
D 15
 * Copyright (c) 1982 Regents of the University of California.
E 15
I 15
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 15
E 14
E 13
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 10
E 5
E 2

I 19
#if defined(KERNEL) || defined(STANDALONE) || defined(LOCORE)
#include "../vax/cpucond.h"
#else
#include <vax/cpucond.h>
#endif

E 19
/*
 * VAX processor register numbers
 */

D 6
#define	KSP	0		/* kernel stack pointer */
#define	ESP	1		/* exec stack pointer */
#define	SSP	2		/* supervisor stack pointer */
#define	USP	3		/* user stack pointer */
#define	ISP	4		/* interrupt stack pointer */
#define	P0BR	8		/* p0 base register */
#define	P0LR	9		/* p0 length register */
#define	P1BR	10		/* p1 base register */
#define	P1LR	11		/* p1 length register */
#define	SBR	12		/* system segment base register */
#define	SLR	13		/* system segment length register */
#define	PCBB	16		/* process control block base */
#define	SCBB	17		/* system control block base */
#define	IPL	18		/* interrupt priority level */
#define	ASTLVL	19		/* async. system trap level */
#define	SIRR	20		/* software interrupt request */
#define	SISR	21		/* software interrupt summary */
#define	ICCS	24		/* interval clock control */
#define	NICR	25		/* next interval count */
#define	ICR	26		/* interval count */
#define	TODR	27		/* time of year (day) */
#define	RXCS	32		/* console receiver control and status */
#define	RXDB	33		/* console receiver data buffer */
#define	TXCS	34		/* console transmitter control and status */
#define	TXDB	35		/* console transmitter data buffer */
#define	MAPEN	56		/* memory management enable */
#define	TBIA	57		/* translation buffer invalidate all */
#define	TBIS	58		/* translation buffer invalidate single */
#define	PMR	61		/* performance monitor enable */
#define	SID	62		/* system identification */
E 6
I 6
#define	KSP	0x0		/* kernel stack pointer */
#define	ESP	0x1		/* exec stack pointer */
#define	SSP	0x2		/* supervisor stack pointer */
#define	USP	0x3		/* user stack pointer */
#define	ISP	0x4		/* interrupt stack pointer */
#define	P0BR	0x8		/* p0 base register */
#define	P0LR	0x9		/* p0 length register */
#define	P1BR	0xa		/* p1 base register */
#define	P1LR	0xb		/* p1 length register */
#define	SBR	0xc		/* system segment base register */
#define	SLR	0xd		/* system segment length register */
#define	PCBB	0x10		/* process control block base */
#define	SCBB	0x11		/* system control block base */
#define	IPL	0x12		/* interrupt priority level */
#define	ASTLVL	0x13		/* async. system trap level */
#define	SIRR	0x14		/* software interrupt request */
#define	SISR	0x15		/* software interrupt summary */
I 15
#if VAX8200
#define	IPIR	0x16		/* interprocessor interrupt register */
#endif
#if VAX750 || VAX730
#define	MCSR	0x17		/* machine check status register */
#endif
E 15
#define	ICCS	0x18		/* interval clock control */
#define	NICR	0x19		/* next interval count */
#define	ICR	0x1a		/* interval count */
I 15
D 16
#if VAX8600 || VAX8200 || VAX780 || VAX750 || VAX730
E 16
I 16
D 19
#if VAX8600 || VAX8200 || VAX780 || VAX750 || VAX730 || VAX650
E 19
E 16
E 15
#define	TODR	0x1b		/* time of year (day) */
I 15
D 19
#endif
E 19
#if VAX750 || VAX730
#define	CSRS	0x1c		/* console storage receive status register */
#define	CSRD	0x1d		/* console storage receive data register */
#define	CSTS	0x1e		/* console storage transmit status register */
#define	CSTD	0x1f		/* console storage transmit data register */
#endif
E 15
#define	RXCS	0x20		/* console receiver control and status */
#define	RXDB	0x21		/* console receiver data buffer */
#define	TXCS	0x22		/* console transmitter control and status */
#define	TXDB	0x23		/* console transmitter data buffer */
I 15
D 16
#if VAX8200 || VAX750 || VAX730
E 16
I 16
D 19
#if VAX8200 || VAX750 || VAX730 || VAX650
E 19
I 19
#if VAX8200 || VAX750 || VAX730 || NEED_CVAX_SUPPORT
E 19
E 16
#define	TBDR	0x24		/* translation buffer disable register */
#define	CADR	0x25		/* cache disable register */
I 18
#define	CCR	CADR		/* it's called Cache Control Register on SOC */
E 18
I 17
#endif
#if VAX8200 || VAX750 || VAX730
E 17
#define	MCESR	0x26		/* machine check error summary register */
#endif
D 16
#if VAX750 || VAX730
E 16
I 16
D 19
#if VAX750 || VAX730 || VAX650
E 19
I 19
#if VAX750 || VAX730 || NEED_CVAX_SUPPORT
E 19
E 16
#define	CAER	0x27		/* cache error */
#endif
#define	ACCS	0x28		/* accelerator control and status */
#if VAX780
#define	ACCR	0x29		/* accelerator maintenance */
#endif
#if VAX8200 || VAX780
#define	WCSA	0x2c		/* WCS address */
#define	WCSD	0x2d		/* WCS data */
#endif
#if VAX8200
#define	WCSL	0x2e		/* WCS load */
#endif
#if VAX8600 || VAX780
#define	SBIFS	0x30		/* SBI fault and status */
#define	SBIS	0x31		/* SBI silo */
#define	SBISC	0x32		/* SBI silo comparator */
#define	SBIMT	0x33		/* SBI maintenance */
#define	SBIER	0x34		/* SBI error register */
#define	SBITA	0x35		/* SBI timeout address */
#define	SBIQC	0x36		/* SBI quadword clear */
#endif
D 16
#if VAX750 || VAX730 || VAX630
#define	IUR	0x37		/* init unibus (Qbus on 630) register */
E 16
I 16
#if VAX750 || VAX730 || VAX630 || VAX650
#define	IUR	0x37		/* init unibus (Qbus on 6x0) register */
E 16
#endif
E 15
#define	MAPEN	0x38		/* memory management enable */
#define	TBIA	0x39		/* translation buffer invalidate all */
#define	TBIS	0x3a		/* translation buffer invalidate single */
I 15
#if VAX750 || VAX730
#define	TB	0x3b		/* translation buffer */
#endif
#if VAX780
#define	MBRK	0x3c		/* micro-program breakpoint */
#endif
E 15
#define	PMR	0x3d		/* performance monitor enable */
#define	SID	0x3e		/* system identification */
E 6
D 15

D 4
/*
 * VAX-11/780 specific registers
 */
E 4
I 4
D 7
#if VAX==780
E 7
I 7
D 8
#if VAX780
E 8
I 8
D 11
#if defined(VAX780)
E 11
I 11
#if defined(VAX780) || defined(VAX8600)
E 11
E 8
E 7
E 4
D 6
#define	ACCS	40		/* accelerator control and status */
#define	ACCR	41		/* accelerator maintenance */
#define	WCSA	44		/* WCS address */
#define	WCSD	45		/* WCS data */
#define	SBIFS	48		/* SBI fault and status */
#define	SBIS	49		/* SBI silo */
#define	SBISC	50		/* SBI silo comparator */
#define	SBIMT	51		/* SBI maintenance */
#define	SBIER	52		/* SBI error register */
#define	SBITA	53		/* SBI timeout address */
#define	SBIQC	54		/* SBI quadword clear */
#define	MBRK	60		/* micro-program breakpoint */
E 6
I 6
#define	ACCS	0x28		/* accelerator control and status */
I 11
#endif

#if defined(VAX8600)
E 15
I 15
D 16
#if VAX8600 || VAX8200
E 16
I 16
D 19
#if VAX8600 || VAX8200 || VAX650
E 19
E 16
E 15
#define TBCHK	0x3f		/* Translation Buffer Check */
I 15
D 19
#endif
E 19
#if VAX8600
E 15
#define PAMACC	0x40		/* PAMM access */
#define PAMLOC	0x41		/* PAMM location */
#define CSWP	0x42		/* Cache sweep */
#define MDECC	0x43		/* MBOX data ecc register */
#define MENA	0x44		/* MBOX error enable register */
#define MDCTL	0x45		/* MBOX data control register */
#define MCCTL	0x46		/* MBOX mcc control register */
#define MERG	0x47		/* MBOX	error generator register */
#define CRBT	0x48		/* Console reboot */
#define DFI	0x49		/* Diag fault insertion register */
#define EHSR	0x4a		/* Error handling status register */
#define STXCS	0x4c		/* Console block storage C/S */
#define STXDB	0x4d		/* Console block storage D/B */
#define ESPA	0x4e		/* EBOX scratchpad address */
#define ESPD	0x4f		/* EBOX sratchpad data */
#endif
D 15

#if defined(VAX780)
E 11
#define	ACCR	0x29		/* accelerator maintenance */
#define	WCSA	0x2c		/* WCS address */
#define	WCSD	0x2d		/* WCS data */
#define	SBIFS	0x30		/* SBI fault and status */
#define	SBIS	0x31		/* SBI silo */
#define	SBISC	0x32		/* SBI silo comparator */
#define	SBIMT	0x33		/* SBI maintenance */
#define	SBIER	0x34		/* SBI error register */
#define	SBITA	0x35		/* SBI timeout address */
#define	SBIQC	0x36		/* SBI quadword clear */
#define	MBRK	0x3c		/* micro-program breakpoint */
E 6
I 4
#endif

D 7
#if VAX==750
E 7
I 7
D 8
#if VAX750
E 8
I 8
#if defined(VAX750) || defined(VAX730)
E 8
E 7
I 6
#define	MCSR	0x17		/* machine check status register */
E 6
#define	CSRS	0x1c		/* console storage receive status register */
#define	CSRD	0x1d		/* console storage receive data register */
#define	CSTS	0x1e		/* console storage transmit status register */
#define	CSTD	0x1f		/* console storage transmit data register */
#define	TBDR	0x24		/* translation buffer disable register */
#define	CADR	0x25		/* cache disable register */
#define	MCESR	0x26		/* machine check error summary register */
#define	CAER	0x27		/* cache error */
D 14
#define	IUR	0x37		/* init unibus register */
E 14
#define	TB	0x3b		/* translation buffer */
I 14
#endif

#if defined(VAX750) || defined(VAX730) || defined(VAX630)
#define	IUR	0x37		/* init unibus register */
E 15
I 15
#if VAX8200
#define	RXCS1	0x50		/* receive csr, console line 1 */
#define	RXDB1	0x51		/* receive data buffer, console line 1 */
#define	TXCS1	0x52		/* transmit csr, console line 1 */
#define	TXDB1	0x53		/* transmit data buffer, console line 1 */
#define	RXCS2	0x54		/* etc */
#define	RXDB2	0x55
#define	TXCS2	0x56
#define	TXDB2	0x57
#define	RXCS3	0x58
#define	RXDB3	0x59
#define	TXCS3	0x5a
#define	TXDB3	0x5b
#define	RXCD	0x5c		/* receive console data register */
#define	CACHEX	0x5d		/* cache invalidate register */
#define	BINID	0x5e		/* VAXBI node ID register */
#define	BISTOP	0x5f		/* VAXBI stop register */
E 15
E 14
#endif
E 4
E 1
