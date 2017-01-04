h35624
s 00005/00141/00029
d D 7.2 88/05/07 14:19:59 karels 22 21
c vax 8200 support from torek: generalize cpu support, ops, clock ops
e
s 00001/00001/00169
d D 7.1 86/06/05 00:45:57 mckusick 21 20
c 4.3BSD release version
e
s 00051/00000/00119
d D 6.5 85/09/07 22:41:32 bloom 20 19
c add 8600 support
e
s 00007/00001/00112
d D 6.4 85/06/08 13:43:48 mckusick 19 18
c Add copyright
e
s 00002/00001/00111
d D 6.3 84/12/20 15:08:57 karels 18 17
c 730 fixes
e
s 00036/00008/00076
d D 6.2 84/02/02 11:31:32 karels 17 16
c support for M780E (from salkind@nyu)
e
s 00000/00000/00084
d D 6.1 83/07/29 07:20:38 sam 16 15
c 4.2 distribution
e
s 00001/00001/00083
d D 4.14 83/07/09 18:18:19 sam 15 13
c can't reference stuff in param.c
e
s 00001/00001/00083
d R 4.14 83/07/09 18:15:27 sam 14 13
c need HZ, not hz
e
s 00001/00001/00083
d D 4.13 83/07/09 16:20:18 kre 13 12
c restore mem err reports to 10 mins (from 6 - since HZ changed)
e
s 00002/00002/00082
d D 4.12 82/11/15 12:05:54 feldman 12 11
c fix memory err reporting enable/disable for 750
e
s 00012/00012/00072
d D 4.11 82/05/26 15:35:43 sam 11 10
c 7ZZ -> 730
e
s 00003/00003/00081
d D 4.10 82/05/26 15:33:39 sam 10 9
c bits defined wrong for 750
e
s 00012/00012/00072
d D 4.9 81/04/03 00:09:37 root 9 8
c s/730/7ZZ
e
s 00010/00004/00074
d D 4.8 81/04/02 15:20:05 root 8 7
c fix 780 error loggin stuff
e
s 00000/00000/00078
d D 4.7 81/03/21 16:13:09 wnj 7 6
c 730 changes
e
s 00015/00010/00063
d D 4.6 81/03/21 16:12:47 wnj 6 5
c 
e
s 00001/00001/00072
d D 4.5 81/03/07 01:42:34 toy 5 4
c Fixed M_CORR
e
s 00053/00009/00020
d D 4.4 81/03/03 12:39:17 wnj 4 3
c new defines to handle cmrd interrupts
e
s 00007/00001/00022
d D 4.3 81/02/23 20:34:52 wnj 3 2
c add MAXNMCR
e
s 00000/00000/00023
d D 4.2 81/02/19 21:41:15 wnj 2 1
c %G%->%E%
e
s 00023/00000/00000
d D 4.1 81/02/19 21:34:15 wnj 1 0
c date and time created 81/02/19 21:34:15 by wnj
e
u
U
t
T
I 1
D 19
/*	%M%	%I%	%E%	*/
E 19
I 19
/*
D 21
 * Copyright (c) 1982 Regents of the University of California.
E 21
I 21
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 21
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 19

/*
D 22
 * Memory controller registers
I 4
 *
 * The way in which the data is stored in these registers varies
D 17
 * per cpu, so we define macros here to mask that.
E 17
I 17
 * per controller and cpu, so we define macros here to mask that.
E 17
E 4
 */
struct	mcr {
D 17
	int	mc_reg[3];
E 17
I 17
	int	mc_reg[6];
E 17
};

I 4
/*
E 22
 * Compute maximum possible number of memory controllers,
 * for sizing of the mcraddr array.
 */
E 4
I 3
D 22
#if VAX780
E 22
I 22
#if VAX8200 || VAX780
E 22
#define	MAXNMCR		4
#else
#define	MAXNMCR		1
#endif

E 3
D 4
#ifdef	KERNEL
int	nmcr;
D 3
struct	mcr *mcraddr[4];
E 3
I 3
struct	mcr *mcraddr[MAXNMCR];
E 4
I 4
D 6
#if VAX750
E 6
D 22
/*
D 6
 * For the 11/750 the memory controller is at the following address.
 * On 11/780, memory controllers are located at one or more
 * places in nexus space.
 */
#define	MCR_750		((struct nexus *)0xf20000)
E 4
E 3
#endif

D 4
#define	M780_HIERR	0x20000000
#define	M780_ERLOG	0x10000000
#define	M750_UNCORR	0xc0000000
#define	M750_CORERR	0x40000000
#define	M750_ERLOG	(M750_UNCORR|M750_CORERR)
E 4
I 4
/*
E 6
D 17
 * For each processor type we define 5 macros:
E 17
I 17
 * For each controller type we define 5 macros:
E 17
 *	M???_INH(mcr)		inhibits further crd interrupts from mcr
 *	M???_ENA(mcr)		enables another crd interrupt from mcr
 *	M???_ERR(mcr)		tells whether an error is waiting
 *	M???_SYN(mcr)		gives the syndrome bits of the error
 *	M???_ADDR(mcr)		gives the address of the error
 */
I 20

#if VAX8600
/*
 * 8600 register bit definitions
 */
#define	M8600_ICRD	0x400		/* inhibit crd interrupts */
#define M8600_TB_ERR	0xf00		/* translation buffer error mask */
/*
 * MDECC register
 */
#define	M8600_ADDR_PE	0x080000	/* address parity error */
#define M8600_DBL_ERR	0x100000	/* data double bit error */
#define	M8600_SNG_ERR	0x200000	/* data single bit error */
#define	M8600_BDT_ERR	0x400000	/* bad data error */

/*
 * ESPA register is used to address scratch pad registers in the Ebox.
 * To access a register in the scratch pad, write the ESPA with the address
 * and then read the ESPD register.  
 *
 * NOTE:  In assmebly code, the the mfpr instruction that reads the ESPD
 *	  register must immedately follow the mtpr instruction that setup
 *	  the ESPA register -- per the VENUS processor register spec.
 *
 * The scratchpad registers that are supplied for a single bit ECC 
 * error are:
 */
#define	SPAD_MSTAT1	0x25		/* scratch pad mstat1 register	*/
#define SPAD_MSTAT2	0x26		/* scratch pad mstat2 register	*/
#define SPAD_MDECC	0x27		/* scratch pad mdecc register	*/
#define SPAD_MEAR	0x2a		/* scratch pad mear register	*/

#define M8600_MEMERR(mdecc) ((mdecc) & 0x780000)
#define M8600_HRDERR(mdecc) ((mdecc) & 0x580000)
#define M8600_ENA (mtpr(MERG, (mfpr(MERG) & ~M8600_ICRD)))
#define M8600_INH (mtpr(EHSR, 0), mtpr(MERG, (mfpr(MERG) | M8600_ICRD)))
#define M8600_SYN(mdecc) (((mdecc) >> 9) & 0x3f)
#define M8600_ADDR(mear) ((mear) & 0x3ffffffc)
#define M8600_ARRAY(mear) (((mear) >> 22) & 0x0f)

#define M8600_MDECC_BITS "\20\27BAD_DT_ERR\26SNG_BIT_ERR\25DBL_BIT_ERR\
\24ADDR_PE"
#define M8600_MSTAT1_BITS "\20\30CPR_PE_A\27CPR_PE_B\26ABUS_DT_PE\
\25ABUS_CTL_MSK_PE\24ABUS_ADR_PE\23ABUS_C/A_CYCLE\22ABUS_ADP_1\21ABUS_ADP_0\
\20TB_MISS\17BLK_HIT\16C0_TAG_MISS\15CHE_MISS\14TB_VAL_ERR\13TB_PTE_B_PE\
\12TB_PTE_A_PE\11TB_TAG_PE\10WR_DT_PE_B3\7WR_DT_PE_B2\6WR_DT_PE_B1\
\5WR_DT_PE_B0\4CHE_RD_DT_PE\3CHE_SEL\2ANY_REFL\1CP_BW_CHE_DT_PE"
#define M8600_MSTAT2_BITS "\20\20CP_BYT_WR\17ABUS_BD_DT_CODE\10MULT_ERR\
\7CHE_TAG_PE\6CHE_TAG_W_PE\5CHE_WRTN_BIT\4NXM\3CP-IO_BUF_ERR\2MBOX_LOCK"
#endif VAX8600

E 22
E 20
#if VAX780
D 22
#define	M780_ICRD	0x40000000	/* inhibit crd interrupts, in [2] */
D 8
#define	M780_HIERR	0x20000000	/* high error rate, in reg[2] */
E 8
I 8
#define	M780_HIER	0x20000000	/* high error rate, in reg[2] */
E 8
#define	M780_ERLOG	0x10000000	/* error log request, in reg[2] */
I 8
/* on a 780, memory crd's occur only when bit 15 is set in the SBIER */
/* register; bit 14 there is an error bit which we also clear */
/* these bits are in the back of the ``red book'' (or in the VMS code) */
E 8
E 4

D 4
#define	MCR_750		((struct nexus *)0xf20000)
E 4
I 4
D 8
#define	M780_INH(mcr)	((mcr)->mc_reg[2] = (M780_ICRD|M780_HIERR|M780_ERLOG))
#define	M780_ENA(mcr)	((mcr)->mc_reg[2] = (M780_HIERR|M780_ERLOG))
#define	M780_ERR(mcr)	((mcr)->mc_reg[2] & (M780_ERLOG))
E 8
I 8
D 17
#define	M780_INH(mcr)	\
E 17
I 17
#define	M780C_INH(mcr)	\
E 17
	(((mcr)->mc_reg[2] = (M780_ICRD|M780_HIER|M780_ERLOG)), mtpr(SBIER, 0))
D 17
#define	M780_ENA(mcr)	\
E 17
I 17
#define	M780C_ENA(mcr)	\
E 17
	(((mcr)->mc_reg[2] = (M780_HIER|M780_ERLOG)), mtpr(SBIER, 3<<14))
D 17
#define	M780_ERR(mcr)	\
E 17
I 17
#define	M780C_ERR(mcr)	\
E 17
	((mcr)->mc_reg[2] & (M780_ERLOG))
E 8
E 4

I 4
D 17
#define	M780_SYN(mcr)	((mcr)->mc_reg[2] & 0xff)
#define	M780_ADDR(mcr)	(((mcr)->mc_reg[2] >> 8) & 0xfffff)
E 17
I 17
#define	M780C_SYN(mcr)	((mcr)->mc_reg[2] & 0xff)
#define	M780C_ADDR(mcr)	(((mcr)->mc_reg[2] >> 8) & 0xfffff)

#define	M780EL_INH(mcr)	\
	(((mcr)->mc_reg[2] = (M780_ICRD|M780_HIER|M780_ERLOG)), mtpr(SBIER, 0))
#define	M780EL_ENA(mcr)	\
	(((mcr)->mc_reg[2] = (M780_HIER|M780_ERLOG)), mtpr(SBIER, 3<<14))
#define	M780EL_ERR(mcr)	\
	((mcr)->mc_reg[2] & (M780_ERLOG))

#define	M780EL_SYN(mcr)	((mcr)->mc_reg[2] & 0x7f)
#define	M780EL_ADDR(mcr)	(((mcr)->mc_reg[2] >> 11) & 0x1ffff)

#define	M780EU_INH(mcr)	\
	(((mcr)->mc_reg[3] = (M780_ICRD|M780_HIER|M780_ERLOG)), mtpr(SBIER, 0))
#define	M780EU_ENA(mcr)	\
	(((mcr)->mc_reg[3] = (M780_HIER|M780_ERLOG)), mtpr(SBIER, 3<<14))
#define	M780EU_ERR(mcr)	\
	((mcr)->mc_reg[3] & (M780_ERLOG))

#define	M780EU_SYN(mcr)	((mcr)->mc_reg[3] & 0x7f)
#define	M780EU_ADDR(mcr)	(((mcr)->mc_reg[3] >> 11) & 0x1ffff)
E 17
#endif

#if VAX750
#define	M750_ICRD	0x10000000	/* inhibit crd interrupts, in [1] */
#define	M750_UNCORR	0xc0000000	/* uncorrectable error, in [0] */
D 10
#define	M750_CORERR	0x40000000	/* correctable error, in [0] */
E 10
I 10
#define	M750_CORERR	0x20000000	/* correctable error, in [0] */
E 10

D 12
#define	M750_INH(mcr)	((mcr)->mc_reg[1] = M750_ICRD)
E 12
I 12
#define	M750_INH(mcr)	((mcr)->mc_reg[1] = 0)
E 12
D 5
#define	M750_ENA(mcr)	((mcr)->mc_reg[0] = (M750_UNCORR|M750_CORR), \
E 5
I 5
#define	M750_ENA(mcr)	((mcr)->mc_reg[0] = (M750_UNCORR|M750_CORERR), \
E 5
D 12
			    (mcr)->mc_reg[1] = 0)
E 12
I 12
			    (mcr)->mc_reg[1] = M750_ICRD)
E 12
#define	M750_ERR(mcr)	((mcr)->mc_reg[0] & (M750_UNCORR|M750_CORERR))

D 10
#define	M750_SYN(mcr)	((mcr)->mc_reg[0] & 0x3f)
#define	M750_ADDR(mcr)	(((mcr)->mc_reg[0] >> 8) & 0x7fff)
E 10
I 10
#define	M750_SYN(mcr)	((mcr)->mc_reg[0] & 0x7f)
#define	M750_ADDR(mcr)	(((mcr)->mc_reg[0] >> 9) & 0x7fff)
E 10
#endif

I 6
D 9
#if VAX730
#define	M730_CRD	0x40000000	/* crd, in [1] */
#define	M730_FTBPE	0x20000000	/* force tbuf parity error, in [1] */
#define	M730_ENACRD	0x10000000	/* enable crd interrupt, in [1] */
#define	M730_MME	0x08000000	/* mem-man enable (ala ipr), in [1] */
#define	M730_DM		0x04000000	/* diagnostic mode, in [1] */
#define	M730_DISECC	0x02000000	/* disable ecc, in [1] */
E 9
I 9
D 11
#if VAX7ZZ
#define	M7ZZ_CRD	0x40000000	/* crd, in [1] */
#define	M7ZZ_FTBPE	0x20000000	/* force tbuf parity error, in [1] */
#define	M7ZZ_ENACRD	0x10000000	/* enable crd interrupt, in [1] */
#define	M7ZZ_MME	0x08000000	/* mem-man enable (ala ipr), in [1] */
#define	M7ZZ_DM		0x04000000	/* diagnostic mode, in [1] */
#define	M7ZZ_DISECC	0x02000000	/* disable ecc, in [1] */
E 11
I 11
#if VAX730
I 18
#define	M730_UNCORR	0x80000000	/* rds, uncorrectable error, in [1] */
E 18
#define	M730_CRD	0x40000000	/* crd, in [1] */
#define	M730_FTBPE	0x20000000	/* force tbuf parity error, in [1] */
#define	M730_ENACRD	0x10000000	/* enable crd interrupt, in [1] */
#define	M730_MME	0x08000000	/* mem-man enable (ala ipr), in [1] */
#define	M730_DM		0x04000000	/* diagnostic mode, in [1] */
#define	M730_DISECC	0x02000000	/* disable ecc, in [1] */
E 11
E 9

D 9
#define	M730_INH(mcr)	((mcr)->mc_reg[1] = M730_MME)
#define	M730_ENA(mcr)	((mcr)->mc_reg[1] = (M730_MME|M730_ENACRD))
#define	M730_ERR(mcr)	((mcr)->mc_reg[1] & M730_CRD)
#define	M730_SYN(mcr)	((mcr)->mc_reg[0] & 0x7f)
#define	M730_ADDR(mcr)	(((mcr)->mc_reg[0] >> 8) & 0x7fff)
E 9
I 9
D 11
#define	M7ZZ_INH(mcr)	((mcr)->mc_reg[1] = M7ZZ_MME)
#define	M7ZZ_ENA(mcr)	((mcr)->mc_reg[1] = (M7ZZ_MME|M7ZZ_ENACRD))
#define	M7ZZ_ERR(mcr)	((mcr)->mc_reg[1] & M7ZZ_CRD)
#define	M7ZZ_SYN(mcr)	((mcr)->mc_reg[0] & 0x7f)
#define	M7ZZ_ADDR(mcr)	(((mcr)->mc_reg[0] >> 8) & 0x7fff)
E 11
I 11
#define	M730_INH(mcr)	((mcr)->mc_reg[1] = M730_MME)
#define	M730_ENA(mcr)	((mcr)->mc_reg[1] = (M730_MME|M730_ENACRD))
D 18
#define	M730_ERR(mcr)	((mcr)->mc_reg[1] & M730_CRD)
E 18
I 18
#define	M730_ERR(mcr)	((mcr)->mc_reg[1] & (M730_UNCORR|M730_CRD))
E 18
#define	M730_SYN(mcr)	((mcr)->mc_reg[0] & 0x7f)
#define	M730_ADDR(mcr)	(((mcr)->mc_reg[0] >> 8) & 0x7fff)
E 11
E 9
#endif

E 22
I 17
/* controller types */
#define	M780C	1
#define	M780EL	2
#define	M780EU	3
D 22
#define	M750	4
#define	M730	5
E 22
I 22
#endif
E 22

E 17
E 6
E 4
D 13
#define	MEMINTVL	(60*60*10)		/* 10 minutes */
E 13
I 13
D 15
#define	MEMINTVL	(hz*60*10)		/* 10 minutes */
E 15
I 15
#define	MEMINTVL	(60*10)		/* 10 minutes */
E 15
E 13
I 4

#ifdef	KERNEL
int	nmcr;
D 22
struct	mcr *mcraddr[MAXNMCR];
E 22
I 22
caddr_t	mcraddr[MAXNMCR];
#if VAX780
E 22
I 17
int	mcrtype[MAXNMCR];
I 22
#endif
E 22
E 17
#endif
D 6

E 6
E 4
E 1
