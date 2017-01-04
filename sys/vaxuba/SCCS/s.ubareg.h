h28737
s 00007/00005/00282
d D 7.7 88/10/20 17:03:55 karels 50 49
c change ubaalloc macros to allow 2047 map registers on Q-bus,
c use the macros, and add qbgetpri for Q-bus device probe routines
e
s 00007/00002/00280
d D 7.6 88/08/27 15:50:57 karels 49 48
c enlarge qbus address space if GATEWAY
e
s 00002/00002/00280
d D 7.5 88/08/27 07:20:42 tef 48 47
c Add support for microvax 3000.
e
s 00062/00005/00220
d D 7.4 88/05/14 11:34:04 karels 47 46
c DWBUA support for 8200, other changes from torek
e
s 00001/00000/00224
d D 7.3 88/04/07 17:22:19 karels 46 45
c add UBAIOADDR (used in standalone)
e
s 00064/00031/00160
d D 7.2 86/08/09 15:15:54 karels 45 44
c generalize uba code to handle Q bus more gracefully
e
s 00001/00001/00190
d D 7.1 86/06/05 01:19:38 mckusick 44 43
c 4.3BSD release version
e
s 00006/00000/00185
d D 6.7 86/04/22 11:04:44 kridle 43 42
c MicroVAX II Integration (KA630)
e
s 00042/00037/00143
d D 6.6 85/08/05 19:25:52 bloom 42 41
c add support for 8600
e
s 00007/00001/00173
d D 6.5 85/06/08 14:42:59 mckusick 41 40
c Add copyright
e
s 00003/00000/00171
d D 6.4 85/01/18 11:03:01 karels 40 39
c more bits for 780 uba
e
s 00001/00010/00170
d D 6.3 84/02/15 11:52:32 karels 39 38
c MAXNUBA no longer used (replaced by NUBA)
e
s 00005/00001/00175
d D 6.2 83/09/29 09:18:41 karels 38 37
c IF_UBAPURGE->UBAPURGE for 730; MAXNUBA is 2 on 750
e
s 00000/00000/00176
d D 6.1 83/07/29 07:29:41 sam 37 36
c 4.2 distribution
e
s 00006/00003/00170
d D 4.31 82/11/13 23:00:54 sam 36 35
c merge of 4.1b with 4.1c
e
s 00004/00004/00169
d D 4.30 82/05/26 15:35:50 sam 35 34
c 7ZZ -> 730
e
s 00007/00002/00166
d D 4.29 82/05/19 15:56:16 wnj 34 33
c add ubdevreg macro
e
s 00003/00003/00165
d D 4.28 82/04/11 01:09:15 feldman 33 32
c support for ec driver
e
s 00002/00002/00166
d D 4.27 82/03/18 02:23:56 root 32 31
c fix typos
e
s 00001/00001/00167
d D 4.26 81/12/03 17:33:39 wnj 31 30
c cleanup
e
s 00004/00004/00164
d D 4.25 81/12/02 17:26:30 wnj 30 29
c more cleanup
e
s 00032/00000/00136
d D 4.24 81/11/26 11:54:29 wnj 29 28
c before carry to arpavax
e
s 00004/00000/00132
d D 4.23 81/10/29 20:51:54 wnj 28 27
c misc changes
e
s 00004/00004/00128
d D 4.22 81/04/03 00:09:45 root 27 26
c s/730/7ZZ
e
s 00005/00000/00127
d D 4.21 81/03/21 16:13:13 wnj 26 25
c 730 changes
e
s 00002/00002/00125
d D 4.20 81/03/14 19:22:38 wnj 25 24
c fixed up uba??? macros
e
s 00006/00003/00121
d D 4.19 81/03/13 21:50:36 wnj 24 23
c parameterized macros for uba addresses
e
s 00000/00000/00124
d D 4.18 81/03/09 00:27:37 wnj 23 22
c lint
e
s 00071/00166/00053
d D 4.17 81/03/08 16:16:27 wnj 22 21
c split header files in 2 and rename structures for sanity
e
s 00004/00001/00215
d D 4.16 81/03/06 11:40:10 wnj 21 20
c spelling errors and add NEXFLT_BITS and UBASR_BITS
e
s 00012/00001/00204
d D 4.15 81/02/27 02:38:24 wnj 20 19
c dynamic alloc kernel version
e
s 00001/00001/00204
d D 4.14 81/02/26 22:07:35 wnj 19 18
c fixes for 750/780
e
s 00000/00002/00205
d D 4.13 81/02/26 04:29:55 wnj 18 17
c cosmetics
e
s 00000/00001/00207
d D 4.12 81/02/23 23:44:26 wnj 17 16
c get rid of uh_active
e
s 00001/00000/00207
d D 4.11 81/02/23 20:34:08 wnj 16 15
c add ud_xclu
e
s 00002/00000/00205
d D 4.10 81/02/22 21:47:19 wnj 15 14
c working interlocked version
e
s 00019/00020/00186
d D 4.9 81/02/21 21:29:46 wnj 14 13
c misc changes for first working interlockable version
e
s 00001/00001/00205
d D 4.8 81/02/19 21:42:45 wnj 13 12
c %G%->%E%
e
s 00027/00013/00179
d D 4.7 81/02/19 21:31:39 wnj 12 11
c various changes related to first dgo attempt
e
s 00023/00015/00169
d D 4.6 81/02/16 20:44:05 wnj 11 10
c more mods to working new version
e
s 00158/00118/00026
d D 4.5 81/02/15 12:14:20 wnj 10 9
c bootable autoconf version
e
s 00010/00007/00134
d D 4.4 81/02/07 15:54:02 wnj 9 8
c minor inconsequential changes
e
s 00008/00000/00133
d D 4.3 80/12/26 11:59:29 wnj 8 7
c add PHYSU* for standalone drivers
e
s 00009/00002/00124
d D 4.2 80/12/17 11:47:06 wnj 7 6
c combined 750/780
e
s 00000/00000/00126
d D 4.1 80/11/09 17:01:58 bill 6 5
c stamp for 4bsd
e
s 00003/00003/00123
d D 3.5 80/10/09 00:08:31 bill 5 4
c minor typos
e
s 00013/00000/00113
d D 3.4 80/06/22 12:39:43 bill 4 3
c added (as yet unused) structure describing ubaset() return value
e
s 00001/00001/00112
d D 3.3 80/06/07 03:01:45 bill 3 2
c %H%->%G%
e
s 00001/00001/00112
d D 3.2 80/04/11 10:20:14 bill 2 1
c 6pages kmap
e
s 00113/00000/00000
d D 3.1 80/04/09 16:25:45 bill 1 0
c date and time created 80/04/09 16:25:45 by bill
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%H%	*/
E 3
I 3
D 13
/*	%M%	%I%	%G%	*/
E 13
I 13
D 41
/*	%M%	%I%	%E%	*/
E 41
I 41
/*
D 44
 * Copyright (c) 1982 Regents of the University of California.
E 44
I 44
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 44
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 41
E 13
E 3

/*
D 10
 * Unibus adapter
E 10
I 10
D 12
 * unibus adapter
E 12
I 12
D 22
 * UNIBUS adaptor
E 22
I 22
D 45
 * VAX UNIBUS adapter registers
E 45
I 45
D 47
 * VAX UNIBUS adapter definitions
E 47
I 47
 * VAX UNIBUS adapter registers
E 47
E 45
E 22
E 12
E 10
 */
I 42

/*
D 45
 * size of unibus address space in pages
E 45
I 45
 * "UNIBUS" adaptor types.
 * This code is used for both UNIBUSes and Q-buses
 * with different types of adaptors.
 * Definition of a type includes support code for that type.
E 45
 */
D 45
#define UBAPAGES 512
E 45
I 45
#if VAX780 || VAX8600
#define	DW780	1		/* has adaptor regs, sr: 780/785/8600 */
#endif
E 45

I 45
#if VAX750
#define	DW750	2		/* has adaptor regs, no sr: 750, 730 */
#endif

#if VAX730
#define	DW730	3		/* has adaptor regs, no sr: 750, 730 */
#endif

D 48
#if VAX630
E 48
I 48
#if VAX630 || VAX650
E 48
#define	QBA	4		/* 22-bit Q-bus, no adaptor regs: uVAX II */
#endif

#if VAX8200 || VAX8500 || VAX8800
#define	DWBUA	5		/* BI UNIBUS adaptor: 8200/8500/8800 */
#endif

E 45
/*
D 45
 * Number of UNIBUS map registers.  We can't use the last 8k of UNIBUS
 * address space for i/o transfers since it is used by the devices,
 * hence have slightly less than 256K of UNIBUS address space.
E 45
I 45
 * Size of unibus memory address space in pages
 * (also number of map registers).
D 49
 * QBAPAGES should be 8192, but umem needs to be expanded.
E 49
I 49
D 50
 * QBAPAGES should be 8192, but we don't need nearly
 * that much address space; choose pragmatically.
E 50
I 50
 * QBAPAGES should be 8192, but we don't need nearly that much
 * address space, and the return from the allocation routine
 * can accommodate at most 2047 (ubavar.h: UBA_MAXMR);
 * QBAPAGES must be at least UBAPAGES.  Choose pragmatically.
E 50
E 49
E 45
 */
D 45
#define	NUBMREG	496
E 45
I 45
#define	UBAPAGES	496
#define	NUBMREG		496
D 49
#define	QBAPAGES	UBAPAGES	/* for now; should be 8192 */
E 49
I 49
D 50
#ifdef GATEWAY
#define	QBAPAGES	1024		/* tunable: min UBAPAGES, max 8192 */
E 50
I 50
#if defined(GATEWAY) && !defined(QNIVERT)
#define	QBAPAGES	1024
E 50
#else
D 50
#define	QBAPAGES	UBAPAGES	/* tunable: min UBAPAGES, max 8192 */
E 50
I 50
#define	QBAPAGES	UBAPAGES
E 50
#endif
E 49
I 46
#define	UBAIOADDR	0760000		/* start of I/O page */
E 46
#define	UBAIOPAGES	16
E 45

E 42
I 11
D 22
#if VAX750
#define	UBA750	((struct uba_regs *)0xf30000)
#define	UMEM750	((u_short *)0xfc0000)
#endif
E 11

E 22
I 20
#ifndef LOCORE
E 20
D 2
#define	UBA0		0x80040000	/* sys virt i/o for UBA 0 */
E 2
I 2
D 10
#define	UBA0		0x80060000	/* sys virt i/o for UBA 0 */
E 2
#define	UBA0_DEV (UBA0+0x2000-0160000)	/* sys virt of device regs */
D 7

E 7
#define	UNIBASE 0760000	 		/* UNIBUS phys base of i/o reg's */

I 7
#if VAX==780
I 8
#define	PHYSUBA0	0x20006000
D 9
#define	PHYSUMEM	0x2013e000
E 9
I 9
#define	PHYSUDEV0	0x20100000
E 9
#else
#define	PHYSUBA0	0xf30000
D 9
#define	PHYSUMEM	(0xfc0000+UNIBASE)
E 9
I 9
#define	PHYSUDEV0	0xfc0000
E 9
#endif
I 9
#define	PHYSUMEM0	(PHYSUDEV0+0x3e000)
#define	PHYSUMEM	PHYSUMEM0
#define	PHYSUDEVSZ	0x40000
E 9

#if VAX==780
E 8
E 7
/* UBA Configuration Register, CNFGR */
#define	PARFLT		0x80000000	/* SBI Parity Fault */
#define	WSQFLT		0x40000000	/* SBI Write Sequence Fault */
#define	URDFLT		0x20000000	/* SBI Unexpected Read Fault */
#define	ISQFLT		0x10000000	/* SBI Interlock Sequence Fault */
#define	MXTFLT		0x8000000	/* SBI Multiple Transmitter Fault */
#define	XMTFLT		0x4000000	/* UBA is transmit faulter */
#define	ADPDN		0x800000	/* Adapter Power Down */
#define	ADPUP		0x400000	/* Adapter Power Up */
#define	UBINIT		0x40000		/* UNIBUS INIT is asserted */
#define	UBPDN		0x20000		/* UNIBUS Power Down */
#define	UBIC		0x10000		/* UNIBUS Initialization */
					/* UNIBUS Ready */
#define	UBACOD		0xff		/* UBA Code bits */
 
/* UBA Control Register, UBACR */
 
#define	MRD16		0x40000000	/* Map Reg Disable Bit 4 */
#define	MRD8		0x20000000	/* Map Reg Disable Bit 3 */
#define	MRD4		0x10000000	/* Map Reg Disable Bit 2 */
#define	MRD2		0x8000000	/* Map Reg Disable Bit 1 */
#define	MRD1		0x4000000	/* Map Reg Disable Bit 0 */
#define	IFS		0x40	  	/* Interrupt Field Switch */
#define	BRIE		0x20	  	/* BR Interrupt Enable */
#define	USEFIE		0x10	  	/* UNIBUS to SBI Error Field IE */
#define	SUEFIE		0x8	  	/* SBI to UNIBUS Error Field IE */
#define	CNFIE		0x4	  	/* Configuration IE */
#define	UPF		0x2	  	/* UNIBUS Power Fail */
#define	ADINIT		0x1	  	/* Adapter Init */
 
/* UBA Status Register, UASR */
#define	BR7FULL		0x8000000	/* BR7 Receive Vector Rg Full */
#define	BR6FULL		0x4000000	/* BR6 Receive Vector Reg Full */
#define	BR5FULL		0x2000000	/* BR5 Receive Vector Reg Full */
#define	BR4FULL		0x1000000	/* BR4 Receive Vector Reg Full */
#define	RDTO		0x400		/* UNIBUS to SBI Read Data Timeout */
#define	RDS		0x200		/* Read Data Substitute */
#define	CRD		0x100		/* Corrected Read Data */
#define	CXTER		0x80		/* Command Transmit Error */
#define	CXTMO		0x40		/* Command Transmit Timeout */
#define	DPPE		0x20		/* Data Path Parity Error */
#define	IVMR		0x10		/* Invalid Map Register */
#define	MRPF		0x8		/* Map Register Parity Failure */
#define	LEB		0x4		/* Lost Error */
#define	UBSTO		0x2		/* UNIBUS Select Timeout */
#define	UBSSTO		0x1		/* UNIBUS Slave Sync Timeout */
 
/* Failed Map Entry Register, FMER */
 
#define	FMRN		0x1ff		/* Failed Map Reg. No. Field */
 
/* Failed UNIBUS Address Register, FUBAR */
#define	FUA		0xffff		/* Failed UNIBUS Address Field */
 
/* BR Receive Vector register, BRRVR */
#define	AIRI		0x80000000	/* Adapter Interrupt Request */
#define	DIV		0xffff		/* Device Interrupt Vector Field */
I 7
#endif
E 7
 
/* Data Path Register, DPR */
#define	BNE		0x80000000	/* Buffer Not Empty - Purge */
#define	BTE		0x40000000	/* Buffer Transfer Error */
#define	DPF		0x20000000	/* DP Function (RO) */
#define	BS		0x7f0000	/* Buffer State Field */
#define	BUBA		0xffff		/* Buffered UNIBUS Address */
 
/* Map Register, MR */
#define	MRV		0x80000000	/* Map Register Valid */
D 5
#define	BO		0x2000000		/* Byte Offset Bit */
#define	DPDB		0x1e00000		/* Data Path Designator Field */
#define	SBIPFN		0xfffff			/* SBI Page Address Field */
E 5
I 5
#define	BO		0x2000000	/* Byte Offset Bit */
#define	DPDB		0x1e00000	/* Data Path Designator Field */
#define	SBIPFN		0xfffff		/* SBI Page Address Field */
E 5

E 10
I 10
D 19
#if VAX780
E 19
E 10
/*
I 47
 * DWBUA hardware registers.
 */
struct dwbua_regs {
	int	pad1[456];		/* actually bii regs + pad */
	int	bua_csr;		/* control and status register */
	int	bua_offset;		/* vector offset register */
	int	bua_fubar;		/* failed UNIBUS address register */
	int	bua_bifar;		/* BI failed address register */
	int	bua_udiag[5];		/* micro diagnostics (R/O) */
	int	pad2[3];
/* dpr[0] is for DDP; dpr's 1 through 5 are for BPD's 1 through 5 */
	int	bua_dpr[6];		/* data path registers */
	int	pad3[10];
	int	bua_bdps[20];		/* buffered data path space *//*???*/
	int	pad4[8];
	struct	pte bua_map[UBAPAGES];	/* unibus map registers */
	int	pad5[UBAIOPAGES];	/* no maps for device address space */
};

#ifdef DWBUA
/* bua_csr */
#define	BUACSR_ERR	0x80000000	/* composite error */
#define	BUACSR_BIF	0x10000000	/* BI failure */
#define	BUACSR_SSYNTO	0x08000000	/* slave sync timeout */
#define	BUACSR_UIE	0x04000000	/* unibus interlock error */
#define	BUACSR_IVMR	0x02000000	/* invalid map register */
#define	BUACSR_BADBDP	0x01000000	/* bad BDP select */
#define	BUACSR_BUAEIE	0x00100000	/* bua error interrupt enable (?) */
#define	BUACSR_UPI	0x00020000	/* unibus power init */
#define	BUACSR_UREGDUMP	0x00010000	/* microdiag register dump */
#define	BUACSR_IERRNO	0x000000ff	/* mask for internal errror number */

/* bua_offset */
#define	BUAOFFSET_MASK	0x00003e00	/* hence max offset = 15872 */

/* bua_dpr */
#define	BUADPR_DPSEL	0x00e00000	/* data path select (?) */
#define	BUADPR_PURGE	0x00000001	/* purge bdp */

/* bua_map -- in particular, those bits that are not in DW780s & DW750s */
#define	BUAMR_IOADR	0x40000000	/* I/O address space */
#define	BUAMR_LAE	0x04000000	/* longword access enable */
	/* I see no reason to use either one, though ... act 6 Aug 1987 */

#define	UBA_PURGEBUA(uba, bdp) \
	(((struct dwbua_regs *)(uba))->bua_dpr[bdp] |= BUADPR_PURGE)
#else
#define	UBA_PURGEBUA(uba, bdp)
#endif

/*
E 47
D 10
 * Unibus maps
 */
D 9
#ifdef	KERNEL
#define	UAMSIZ 50

struct	map ubamap[UAMSIZ];
char	bdpwant;		/* someone is waiting for buffered data path */ 
E 9
D 7
struct	map bdpmap[15];
E 7
I 7
#if VAX==780
#define	NUBABDP	15
#else
#define	NUBABDP	3
#endif

I 9
#ifdef	KERNEL
#define	UAMSIZ 50

struct	map ubamap[UAMSIZ];
char	bdpwant;		/* someone is waiting for buffered data path */ 
E 9
struct	map bdpmap[NUBABDP];
E 7
char	umrwant;		/* ... for unibus map registers */
#endif

/*
E 10
D 22
 * UBA registers
E 22
I 22
D 45
 * UBA hardware registers
E 45
I 45
 * DW780/DW750 hardware registers
E 45
E 22
 */
D 10

E 10
D 47
struct uba_regs
{
E 47
I 47
struct uba_regs {
E 47
D 14
	int	uba_cnfgr;
	int	uba_cr;
	int	uba_sr;
	int	uba_dcr;
	int	uba_fmer;
	int	uba_fubar;
E 14
I 14
	int	uba_cnfgr;		/* configuration register */
	int	uba_cr;			/* control register */
	int	uba_sr;			/* status register */
	int	uba_dcr;		/* diagnostic control register */
	int	uba_fmer;		/* failed map entry register */
	int	uba_fubar;		/* failed UNIBUS address register */
E 14
	int	pad1[2];
	int	uba_brsvr[4];
D 14
	int	uba_brrvr[4];
	int	uba_dpr[16];
E 14
I 14
	int	uba_brrvr[4];		/* receive vector registers */
	int	uba_dpr[16];		/* buffered data path register */
E 14
	int	pad2[480];
D 14
	struct	pte uba_map[496];
I 10
	int	pad3[16];
E 14
I 14
D 42
	struct	pte uba_map[496];	/* unibus map register */
E 42
I 42
D 45
	struct	pte uba_map[NUBMREG];	/* unibus map register */
E 42
	int	pad3[16];		/* no maps for device address space */
E 45
I 45
	struct	pte uba_map[UBAPAGES];	/* unibus map register */
	int	pad3[UBAIOPAGES];	/* no maps for device address space */
E 45
E 14
E 10
};
I 20
#endif
E 20
I 4

I 19
D 42
#if VAX780
E 42
I 42
D 45
#if defined(VAX780) || defined(VAX8600)
E 45
I 45
#ifdef DW780
E 45
E 42
E 19
D 10
union	ub_info {
	struct ub_Info {
	unsigned int	Ub_off:18,
			Ub_npf:10,
			Ub_bdp:4;
	} ub_I;
	int	ub_word;
E 10
I 10
D 22
/* UBA control register, UBACR */
#define	UBA_MRD16	0x40000000	/* map reg disable bit 4 */
#define	UBA_MRD8	0x20000000	/* map reg disable bit 3 */
#define	UBA_MRD4	0x10000000	/* map reg disable bit 2 */
#define	UBA_MRD2	0x08000000	/* map reg disable bit 1 */
#define	UBA_MRD1	0x04000000	/* map reg disable bit 0 */
#define	UBA_IFS		0x00000040	/* interrupt field switch */
#define	UBA_BRIE	0x00000020	/* BR interrupt enable */
#define	UBA_USEFIE	0x00000010	/* UNIBUS to SBI error field IE */
#define	UBA_SUEFIE	0x00000008	/* SBI to UNIBUS error field IE */
#define	UBA_CNFIE	0x00000004	/* configuration IE */
#define	UBA_UPF		0x00000002	/* UNIBUS power fail */
#define	UBA_ADINIT	0x00000001	/* adapter init */
E 22
I 22
/* uba_cnfgr */
#define	UBACNFGR_UBINIT	0x00040000	/* unibus init asserted */
#define	UBACNFGR_UBPDN	0x00020000	/* unibus power down */
#define	UBACNFGR_UBIC	0x00010000	/* unibus init complete */
E 22

I 40
#define UBACNFGR_BITS \
"\40\40PARFLT\37WSQFLT\36URDFLT\35ISQFLT\34MXTFLT\33XMTFLT\30ADPDN\27ADPUP\23UBINIT\22UBPDN\21UBIC"

E 40
D 22
/* UBA status register, UASR */
#define	UBA_BR7FULL	0x08000000	/* BR7 receive vector reg full */
#define	UBA_BR6FULL	0x04000000	/* BR6 receive vector reg full */
#define	UBA_BR5FULL	0x02000000	/* BR5 receive vector reg full */
#define	UBA_BR4FULL	0x01000000	/* BR4 receive vector reg full */
#define	UBA_RDTO	0x00000400	/* UNIBUS to SBI read data timeout */
#define	UBA_RDS		0x00000200	/* read data substitute */
#define	UBA_CRD		0x00000100	/* corrected read data */
#define	UBA_CXTER	0x00000080	/* command transmit error */
#define	UBA_CXTMO	0x00000040	/* command transmit timeout */
#define	UBA_DPPE	0x00000020	/* data path parity error */
#define	UBA_IVMR	0x00000010	/* invalid map register */
#define	UBA_MRPF	0x00000008	/* map register parity failure */
#define	UBA_LEB		0x00000004	/* lost error */
#define	UBA_UBSTO	0x00000002	/* UNIBUS select timeout */
D 21
#define	UBA_UBSSTO	0x00000001	/* UNIBUS slave sync timeout */
E 21
I 21
#define	UBA_UBSSYNTO	0x00000001	/* UNIBUS slave sync timeout */
E 22
I 22
/* uba_cr */
#define	UBACR_MRD16	0x40000000	/* map reg disable bit 4 */
#define	UBACR_MRD8	0x20000000	/* map reg disable bit 3 */
#define	UBACR_MRD4	0x10000000	/* map reg disable bit 2 */
#define	UBACR_MRD2	0x08000000	/* map reg disable bit 1 */
#define	UBACR_MRD1	0x04000000	/* map reg disable bit 0 */
#define	UBACR_IFS	0x00000040	/* interrupt field switch */
#define	UBACR_BRIE	0x00000020	/* BR interrupt enable */
#define	UBACR_USEFIE	0x00000010	/* UNIBUS to SBI error field IE */
#define	UBACR_SUEFIE	0x00000008	/* SBI to UNIBUS error field IE */
#define	UBACR_CNFIE	0x00000004	/* configuration IE */
#define	UBACR_UPF	0x00000002	/* UNIBUS power fail */
#define	UBACR_ADINIT	0x00000001	/* adapter init */
E 22

I 22
/* uba_sr */
#define	UBASR_BR7FULL	0x08000000	/* BR7 receive vector reg full */
#define	UBASR_BR6FULL	0x04000000	/* BR6 receive vector reg full */
#define	UBASR_BR5FULL	0x02000000	/* BR5 receive vector reg full */
#define	UBASR_BR4FULL	0x01000000	/* BR4 receive vector reg full */
#define	UBASR_RDTO	0x00000400	/* UNIBUS to SBI read data timeout */
#define	UBASR_RDS	0x00000200	/* read data substitute */
#define	UBASR_CRD	0x00000100	/* corrected read data */
#define	UBASR_CXTER	0x00000080	/* command transmit error */
#define	UBASR_CXTMO	0x00000040	/* command transmit timeout */
#define	UBASR_DPPE	0x00000020	/* data path parity error */
#define	UBASR_IVMR	0x00000010	/* invalid map register */
#define	UBASR_MRPF	0x00000008	/* map register parity failure */
#define	UBASR_LEB	0x00000004	/* lost error */
#define	UBASR_UBSTO	0x00000002	/* UNIBUS select timeout */
#define	UBASR_UBSSYNTO	0x00000001	/* UNIBUS slave sync timeout */

E 22
#define	UBASR_BITS \
"\20\13RDTO\12RDS\11CRD\10CXTER\7CXTMO\6DPPE\5IVMR\4MRPF\3LEB\2UBSTO\1UBSSYNTO"
E 21

D 22
/* BR receive vector register, BRRVR */
#define	UBA_AIRI	0x80000000	/* adapter interrupt request */
#define	UBA_DIV		0x0000ffff	/* device interrupt vector field */
#endif
E 22
I 22
/* uba_brrvr[] */
#define	UBABRRVR_AIRI	0x80000000	/* adapter interrupt request */
#define	UBABRRVR_DIV	0x0000ffff	/* device interrupt vector field */
D 42
#endif VAX780
E 42
I 42
#endif
E 42
E 22
 
D 22
/* data path register, DPR */
E 22
I 22
/* uba_dpr */
E 22
D 42
#if VAX780
E 42
I 42
D 45
#if defined(VAX780) || defined(VAX8600)
E 45
I 45
#ifdef DW780
E 45
E 42
D 22
#define	UBA_BNE		0x80000000	/* buffer not empty - purge */
#define	UBA_BTE		0x40000000	/* buffer transfer error */
#define	UBA_DPF		0x20000000	/* DP function (RO) */
#define	UBA_BS		0x007f0000	/* buffer state field */
#define	UBA_BUBA	0x0000ffff	/* buffered UNIBUS address */
#endif
E 22
I 22
#define	UBADPR_BNE	0x80000000	/* buffer not empty - purge */
#define	UBADPR_BTE	0x40000000	/* buffer transfer error */
#define	UBADPR_DPF	0x20000000	/* DP function (RO) */
#define	UBADPR_BS	0x007f0000	/* buffer state field */
#define	UBADPR_BUBA	0x0000ffff	/* buffered UNIBUS address */
I 28
#define	UBA_PURGE780(uba, bdp) \
    ((uba)->uba_dpr[bdp] |= UBADPR_BNE)
E 28
D 42
#endif VAX780
E 42
I 42
#else
#define UBA_PURGE780(uba, bdp)
#endif
E 42
E 22
D 45
#if VAX750
E 45
I 45
#ifdef DW750
E 45
D 14
#define	UBA_ERROR	0x20000000
#define	UBA_NXM		0x40000000
#define	UBA_UCE		0x20000000
#define	UBA_PURGE	0x00000001
E 14
I 14
D 22
#define	UBA_ERROR	0x80000000	/* error occurred */
#define	UBA_NXM		0x40000000	/* nxm from memory */
#define	UBA_UCE		0x20000000	/* uncorrectable error */
#define	UBA_PURGE	0x00000001	/* purge bdp */
E 14
#endif
E 22
I 22
#define	UBADPR_ERROR	0x80000000	/* error occurred */
#define	UBADPR_NXM	0x40000000	/* nxm from memory */
#define	UBADPR_UCE	0x20000000	/* uncorrectable error */
#define	UBADPR_PURGE	0x00000001	/* purge bdp */
I 28
D 36
#define	UBA_PURGE750(uba, bdp) \
    ((uba)->uba_dpr[bdp] |= (UBADPR_PURGE|UBADPR_NXM|UBADPR_UCE))
E 36
I 36
/* the DELAY is for a hardware problem */
#define	UBA_PURGE750(uba, bdp) { \
    ((uba)->uba_dpr[bdp] |= (UBADPR_PURGE|UBADPR_NXM|UBADPR_UCE)); \
    DELAY(8); \
}
E 36
E 28
D 42
#endif VAX750
E 22
 
E 42
I 42
#else
#define UBA_PURGE750(uba, bdp)
#endif

E 42
I 29
/*
 * Macros for fast buffered data path purging in time-critical routines.
 *
 * Too bad C pre-processor doesn't have the power of LISP in macro
 * expansion...
 */
D 42
#if defined(VAX780) && defined(VAX750)
E 42
I 42

D 45
#if defined(VAX8600) || defined(VAX780) || defined(VAX750)
E 45
I 45
D 47
#if DW780 || DW750
E 47
I 47
/* THIS IS WRONG, should use pointer to uba_hd */
#if DWBUA || DW780 || DW750
E 47
E 45
E 42
#define	UBAPURGE(uba, bdp) { \
	switch (cpu) { \
I 47
	case VAX_8200: UBA_PURGEBUA(uba, bdp); break; \
E 47
D 30
	case VAX_780: UBA_PURGE780(uba, bdp); break; \
	case VAX_750: UBA_PURGE750(uba, bdp); break; \
E 30
I 30
D 42
	case VAX_780: UBA_PURGE780((uba), (bdp)); break; \
E 42
I 42
	case VAX_8600: case VAX_780: UBA_PURGE780((uba), (bdp)); break; \
E 42
	case VAX_750: UBA_PURGE750((uba), (bdp)); break; \
E 30
	} \
}
D 45
#endif
D 42
#if defined(VAX780) && !defined(VAX750)
#define	UBAPURGE(uba, bdp) { \
D 32
	if (cpu==VAX_780) {
E 32
I 32
	if (cpu==VAX_780) { \
E 32
D 30
		UBA_PURGE780(uba, bdp); break; \
E 30
I 30
D 31
		UBA_PURGE780((uba), (bdp)); break; \
E 31
I 31
		UBA_PURGE780((uba), (bdp)); \
E 31
E 30
	} \
}
#endif
#if !defined(VAX780) && defined(VAX750)
#define	UBAPURGE(uba, bdp) { \
D 32
	if (cpu==VAX_750) {
E 32
I 32
	if (cpu==VAX_750) { \
E 32
D 30
		UBA_PURGE750(uba, bdp); break; \
E 30
I 30
D 36
		UBA_PURGE750((uba), (bdp)); break; \
E 36
I 36
		UBA_PURGE750((uba), (bdp)); \
E 36
E 30
	} \
}
#endif
#if !defined(VAX780) && !defined(VAX750)
E 42
I 42
#if !defined(VAX8600) && !defined(VAX780) && !defined(VAX750)
E 45
I 45
#else
E 45
E 42
D 38
#define	IF_UBAPURGE(uba, bdp)
E 38
I 38
#define	UBAPURGE(uba, bdp)
E 38
#endif

I 42


E 42
E 29
D 22
/* map register, MR */
#define	UBA_MRV		0x80000000	/* map register valid */
#define	UBA_BO		0x02000000	/* byte offset bit */
#define	UBA_DPDB	0x01e00000	/* data path designator field */
#define	UBA_SBIPFN	0x000fffff	/* SBI page address field */
E 22
I 22
/* uba_mr[] */
#define	UBAMR_MRV	0x80000000	/* map register valid */
#define	UBAMR_BO	0x02000000	/* byte offset bit */
#define	UBAMR_DPDB	0x01e00000	/* data path designator field */
D 47
#define	UBAMR_SBIPFN	0x000fffff	/* SBI page address field */
E 47
I 47
#define	UBAMR_SBIPFN	0x001fffff	/* SBI page address field */
E 47
E 22

D 22
#define	UBA_DPSHIFT	21		/* shift to data path designator */
E 22
I 22
#define	UBAMR_DPSHIFT	21		/* shift to data path designator */
E 22

I 20
D 22
#ifndef LOCORE
E 22
E 20
/*
D 11
 * each UNIBUS mass storage controller has uba_minfo structure.
E 11
I 11
D 22
 * Each UNIBUS mass storage controller has uba_minfo structure,
 * and a uba_dinfo structure (as below) for each attached drive.
E 22
I 22
D 42
 * Number of UNIBUS map registers.  We can't use the last 8k of UNIBUS
 * address space for i/o transfers since it is used by the devices,
 * hence have slightly less than 256K of UNIBUS address space.
E 22
E 11
 */
D 12
struct	uba_minfo {
E 12
I 12
D 22
struct uba_minfo {
E 12
D 11
	short	um_num;		/* controller index in driver */
E 11
I 11
	struct	uba_driver *um_driver;
	short	um_ctlr;	/* controller index in driver */
E 11
	short	um_ubanum;	/* the uba it is on */
	short	um_alive;	/* controller exists */
I 11
	int	(**um_intr)();	/* interrupt handler(s) */
E 11
	caddr_t	um_addr;	/* address of device in i/o space */
D 11
	struct	buf um_tab;	/* queue for this controller */
E 11
D 12
	struct	uba_info *um_forw;
E 12
I 11
	struct	uba_hd *um_hd;
I 12
	int	um_cmd;		/* communication to dgo() */
	int	um_ubinfo;	/* save unibus registers, etc */
E 12
	struct	buf um_tab;	/* queue for this controller */
E 11
E 10
};
E 22
I 22
#define	NUBMREG	496

E 22
I 10
/*
E 42
D 11
 * each UNIBUS device has a uba_dinfo structure.
 * controllers which are not for mass storage often have ONLY
 * a uba_dinfo structure, and no uba_minfo structure.
 * if a controller has many drives attached, then there will
 * be several uba_dinfo structures pointing at the same uba_minfo
E 11
I 11
D 22
 * Each UNIBUS device has a uba_dinfo structure.
 * If a controller has many drives attached, then there will
 * be several uba_dinfo structures associated with a single uba_minfo
E 11
 * structure.
E 22
I 22
 * Number of unibus buffered data paths and possible uba's per cpu type.
E 22
 */
I 42
#define	NBDP8600	15
E 42
D 12
struct	uba_dinfo {
E 12
I 12
D 22
struct uba_dinfo {
E 12
	struct	uba_driver *ui_driver;
D 11
	short	ui_name;
E 11
	short	ui_unit;	/* unit number on the system */
I 11
	short	ui_ctlr;	/* mass ctlr number; -1 if none */
E 11
	short	ui_ubanum;	/* the uba it is on */
	short	ui_slave;	/* slave on controller */
	int	(**ui_intr)();	/* interrupt handler(s) */
	caddr_t	ui_addr;	/* address of device in i/o space */
I 12
	short	ui_dk;		/* if init 1 set to number for iostat */
	short	ui_flags;	/* param to device init. */
E 12
	short	ui_alive;	/* device exists */
	short	ui_type;	/* driver specific type information */
D 12
	short	ui_dk;		/* device number for iostat */
E 12
	caddr_t	ui_physaddr;	/* phys addr, for standalone (dump) code */
I 12
	struct	uba_dinfo *ui_forw;
E 12
D 14
/* if the driver isn't also a controller, this is the controller it is on */
E 14
I 14
/* if the device isn't also a controller, this is the controller it is on */
E 14
	struct	uba_minfo *ui_mi;
	struct	uba_hd *ui_hd;
};
I 20
#endif
E 22
I 22
D 45
#define	NBDP780	15
#define	NBDP750	3
I 26
D 27
#define	NBDP730	0
E 27
I 27
D 35
#define	NBDP7ZZ	0
E 35
I 35
#define	NBDP730	0
I 43
#define	NBDP630	0
E 43
E 35
E 27
E 26
#define	MAXNBDP	15
E 45
I 45
#define	NBDP780		15
I 47
#define	NBDPBUA		5
E 47
#define	NBDP750		3
#define	NBDP730		0
#define	MAXNBDP		15
E 45
E 22
E 20
E 10

D 10
#define	ub_off	ub_I.Ub_off
#define	ub_npf	ub_I.Ub_npf
#define	ub_bdp	ub_I.Ub_bdp
E 10
I 10
D 42
#define	NUBA780	4
D 39
#define	NUBA750	1
E 39
I 39
#define	NUBA750	2
E 39
I 26
D 27
#define	NUBA730	1
E 27
I 27
D 35
#define	NUBA7ZZ	1
E 35
I 35
#define	NUBA730	1
E 35
E 27
E 26
D 39
#if VAX780
#define	MAXNUBA	4
#else
I 38
#if VAX750
#define	MAXNUBA	2
#else
E 38
#define	MAXNUBA	1
I 38
#endif
E 38
#endif
E 39

E 42
I 20
D 22
#ifndef LOCORE
E 22
E 20
/*
D 11
 * header per uba.		CAUTION: size & offsets known in uba.m
E 11
I 11
D 22
 * This structure exists per-uba.
E 22
I 22
D 24
 * For VAXen with specific UBA addresses, give the addresses.
E 24
I 24
D 34
 * Formulas for locations of the last 8k of UNIBUS memory
 * for each possible uba.
E 34
I 34
D 42
 * Symbolic addresses of UNIBUS memory for UBAs.
E 42
I 42
 * Symbolic BUS addresses for UBAs.
E 42
E 34
E 24
E 22
D 18
 *
 * N.B.: THE SIZE AND SHAPE OF THIS STRUCTURE IS KNOWN IN uba.m.
E 18
E 11
 */
I 42

I 43
D 48
#if VAX630
E 48
I 48
#if VAX630 || VAX650
E 48
D 45
#define	UMEM630		((u_short *)(0x1ffc2000))
E 45
I 45
#define	QBAMAP630	((struct pte *)0x20088000)
#define	QMEM630		0x30000000
#define	QIOPAGE630	0x20000000
/*
 * Q-bus control registers
 */
#define	QIPCR		0x1f40		/* from start of iopage */
/* bits in QIPCR */
#define	Q_DBIRQ		0x0001		/* doorbell interrupt request */
#define	Q_LMEAE		0x0020		/* local mem external access enable */
#define	Q_DBIIE		0x0040		/* doorbell interrupt enable */
#define	Q_AUXHLT	0x0100		/* auxiliary processor halt */
#define	Q_DMAQPE	0x8000		/* Q22 bus address space parity error */
E 45
#endif

E 43
E 42
I 26
D 27
#if VAX730
#define	UMEM730		((u_short *)(0xffe000))
E 27
I 27
D 35
#if VAX7ZZ
D 33
#define	UMEM7ZZ		((u_short *)(0xffe000))
E 33
I 33
#define	UMEM7ZZ		((u_short *)(0xfc0000))
E 35
I 35
#if VAX730
D 45
#define	UMEM730		((u_short *)(0xfc0000))
E 45
I 45
#define	UMEM730		0xfc0000
E 45
E 35
E 33
E 27
#endif
I 42

E 42
E 26
D 22
struct	uba_hd {
D 17
	int	uh_active;		/* bit per device transferring */
E 17
	struct	uba_regs *uh_uba;	/* virt addr of uba */
	struct	uba_regs *uh_physuba;	/* phys addr of uba */
	int	(**uh_vec)();		/* interrupt vector */
D 12
	struct	uba_minfo *uh_actf;	/* head of queue to transfer */
	struct	uba_minfo *uh_actl;	/* tail of queue to transfer */
E 12
I 12
	struct	uba_dinfo *uh_actf;	/* head of queue to transfer */
	struct	uba_dinfo *uh_actl;	/* tail of queue to transfer */
E 12
	short	uh_mrwant;		/* someone is waiting for map reg */
	short	uh_bdpwant;		/* someone awaits bdp's */
	int	uh_bdpfree;		/* free bdp's */
	int	uh_hangcnt;		/* number of ticks hung */
	int	uh_zvcnt;		/* number of 0 vectors */
I 15
	short	uh_users;		/* transient bdp use count */
	short	uh_xclu;		/* an rk07 is using this uba! */
E 15
D 11
#define	UAMSIZ 50
	struct	map uh_map[UAMSIZ];
E 11
I 11
#define	UAMSIZ	50
	struct	map *uh_map;
E 11
D 20
} uba_hd[MAXNUBA];
E 20
I 20
};
#ifdef KERNEL
struct	uba_hd uba_hd[MAXNUBA];
#endif
E 20
D 12
#ifdef KERNEL
extern	struct	uba_minfo ubminit[];
extern	struct	uba_dinfo ubdinit[];
int	numuba;
#endif
E 12
/*
D 11
 * each unibus driver defines entries for a set of routines
E 11
I 11
 * Each UNIBUS driver defines entries for a set of routines
E 11
 * as well as an array of types which are acceptable to it.
 */
struct uba_driver {
D 14
	int	(*ud_cntrlr)();		/* see if a driver is really there */
	int	(*ud_slave)();		/* see if a slave is there; init */
	int	(*ud_dgo)();		/* routine to stuff driver regs */
/* dgo is called back by the unibus (usu ubaalloc), when the bus is ready */
D 11
	short	ud_maxslave;		/* max number of slaves */
E 11
	short	ud_needexcl;		/* need exclusive use of uba (rk07) */
E 14
I 14
	int	(*ud_probe)();		/* see if a driver is really there */
	int	(*ud_slave)();		/* see if a slave is there */
	int	(*ud_attach)();		/* setup driver for a slave */
	int	(*ud_dgo)();		/* fill csr/ba to start transfer */
E 14
	u_short	*ud_addr;		/* device csr addresses */
D 12
	char	*ud_pname;
E 12
I 12
	char	*ud_dname;		/* name of a device */
E 12
D 11
	struct	uba_dinfo **ud_info;	/* backpointers to ubinit structs */
E 11
I 11
	struct	uba_dinfo **ud_dinfo;	/* backpointers to ubdinit structs */
I 12
	char	*ud_mname;		/* name of a controller */
E 12
	struct	uba_minfo **ud_minfo;	/* backpointers to ubminit structs */
I 16
	short	ud_xclu;		/* want exclusive use of bdp's */
E 16
E 11
};
I 20
#endif
E 20

/*
 * unibus maps
 */
#define	NBDP780	15
#define	NBDP750	3
#define	MAXNBDP	15

#define	NUBMREG	496

/*
 * flags to uba map/bdp allocation routines
 */
#define	UBA_NEEDBDP	1		/* transfer needs a bdp */
#define	UBA_CANTWAIT	2		/* don't block me */
#define	UBA_NEED16	3		/* need 16 bit addresses only */
I 12

/*
 * UNIBUS related kernel variables
 */
I 20
#ifndef LOCORE
E 20
#ifdef KERNEL
extern	struct	uba_minfo ubminit[];
extern	struct	uba_dinfo ubdinit[];
int	numuba;
extern	struct pte UMEMmap[MAXNUBA][16];
extern	char umem[MAXNUBA][16*NBPG];
extern	int (*UNIvec[])();
#if VAX780
extern	Xua0int(), Xua1int(), Xua2int(), Xua3int();
I 20
#endif
E 20
#endif
E 22
I 22
#if VAX750
D 24
#define	UBA750	((struct uba_regs *)0xf30000)
#define	UMEM750	((u_short *)0xfc0000)
E 24
I 24
D 25
#define	UMEM750(i)	((u_short *)(0xffe000-(i)*0x4000))
E 25
I 25
D 33
#define	UMEM750(i)	((u_short *)(0xffe000-(i)*0x40000))
E 33
I 33
D 45
#define	UMEM750(i)	((u_short *)(0xfc0000-(i)*0x40000))
E 45
I 45
#define	UMEM750(i)	(0xfc0000-(i)*0x40000)
E 45
E 33
E 25
#endif
I 42

E 42
#if VAX780
D 25
#define	UMEM780(i)	((u_short *)(0x2013e000+(i)*0x4000))
E 25
I 25
D 33
#define	UMEM780(i)	((u_short *)(0x2013e000+(i)*0x40000))
E 33
I 33
D 45
#define	UMEM780(i)	((u_short *)(0x20100000+(i)*0x40000))
E 45
I 45
#define	UMEM780(i)	(0x20100000+(i)*0x40000)
I 47
#endif

#if VAX8200		/* BEWARE, argument is node, not ubanum */
#define	UMEM8200(i)	(0x20400000+(i)*0x40000)
E 47
E 45
E 33
E 25
E 24
E 22
#endif
I 34

I 42
#if VAX8600
D 45
#define	UMEMA8600(i)	((u_short *)(0x20100000+(i)*0x40000))
#define	UMEMB8600(i)	((u_short *)(0x22100000+(i)*0x40000))
E 45
I 45
#define	UMEMA8600(i)	(0x20100000+(i)*0x40000)
#define	UMEMB8600(i)	(0x22100000+(i)*0x40000)
E 45
#endif

E 42
/*
 * Macro to offset a UNIBUS device address, often expressed as
D 42
 * something like 0172520 by forcing it into the last 8K of UNIBUS space.
E 42
I 42
D 45
 * something like 0172520 by forcing it into the last 8K of UNIBUS memory
 * space.
E 45
I 45
 * something like 0172520, by forcing it into the last 8K
 * of UNIBUS memory space.
E 45
E 42
 */
D 45
#define	ubdevreg(addr)	(0760000|((addr)&017777))
I 43

E 45
I 45
#define	ubdevreg(addr)	((addr) & 017777)
E 45
E 43
E 34
E 12
E 10
E 4
E 1
