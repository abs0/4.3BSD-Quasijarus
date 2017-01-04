h33635
s 00018/00000/00061
d D 7.2 04/03/19 22:47:03 msokolov 2 1
c move CACR and machine check definitions here
e
s 00061/00000/00000
d D 7.1 04/01/04 01:46:13 msokolov 1 0
c separated out of ka650.h
e
u
U
t
T
I 1
/*
 * Copyright (c) 1988 The Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Mt. Xinu.
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
 *
 *	%W% (Berkeley) %G%
 */

/*
 * Definitions for the CVAX chip.
 * Common to all systems using CVAX.
 */

/*
 * CAER: Memory System Error Register (IPR 39)
 */
#define CAER_DAL	0x00000040	/* CDAL or level 2 cache data parity */
#define CAER_MCD	0x00000020	/* mcheck due to DAL parity error */
#define CAER_MCC	0x00000010	/* mcheck due to 1st lev cache parity */
#define CAER_DAT	0x00000002	/* data parity in 1st level cache */
#define CAER_TAG	0x00000001	/* tag parity in 1st level cache */

/*
 * CADR: Cache Disable Register (IPR 37)
 */
#define CADR_STMASK	0x000000f0	/* 1st level cache state mask */
#define CADR_SEN2	0x00000080	/* 1st level cache set 2 enabled */
#define CADR_SEN1	0x00000040	/* 1st level cache set 1 enabled */
#define CADR_CENI	0x00000020	/* 1st level I-stream caching enabled */
#define CADR_CEND	0x00000010	/* 1st level D-stream caching enabled */

/*
I 2
 * CACR: Cache Control Register (2nd level cache) (cbd_cacr)
 * Used on KA650, KA42 and probably others.
 */
#define CACR_CEN	0x00000010	/* Cache enable */
#define CACR_CPE	0x00000020	/* Cache Parity Error */

#define NMCVAX	15
struct mcvaxframe {
	int	mcvax_bcnt;		/* byte count == 0xc */
	int	mcvax_summary;		/* summary parameter */
	int	mcvax_mrvaddr;		/* most recent vad */
	int	mcvax_istate1;		/* internal state */
	int	mcvax_istate2;		/* internal state */
	int	mcvax_pc;		/* trapped pc */
	int	mcvax_psl;		/* trapped psl */
};

/*
E 2
 * Internal State Info 2: (for mcheck recovery)
 */
#define IS2_VCR		0x00008000	/* VAX Can't Restart flag */

/*
 * We have SOC definitions here too, as SOC is basically a CVAX variant.
 */

/*
 * SOC has CCR instead of original CVAX CADR
 */
#define	CCR_WWP		0x00000008	/* Write wrong parity */
#define	CCR_ENA		0x00000004	/* Enable cache */
#define	CCR_FLU		0x00000002	/* Flush cache */
#define	CCR_DIA		0x00000001	/* Diagnostic access enable */
E 1
