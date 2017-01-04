h51808
s 00001/00001/00165
d D 7.1 86/06/05 01:29:34 mckusick 17 16
c 4.3BSD release version
e
s 00007/00001/00159
d D 6.2 85/06/08 14:06:14 mckusick 16 15
c Add copyright
e
s 00000/00000/00160
d D 6.1 83/07/29 07:34:42 sam 15 14
c 4.2 distribution
e
s 00003/00000/00157
d D 4.13 83/02/18 00:32:56 sam 14 12
c more si shit!!!!!
e
s 00002/00000/00157
d R 4.13 83/02/18 00:30:41 sam 13 12
c more si shit
e
s 00001/00001/00156
d D 4.12 83/01/27 15:29:49 helge 12 11
c fixed error in HPER2_BITS (SSE)
e
s 00025/00000/00132
d D 4.11 82/05/20 15:07:20 sam 11 10
c si and capricorn kludges
e
s 00005/00000/00127
d D 4.10 82/02/08 22:50:07 root 10 9
c defines needed for ML11
e
s 00001/00001/00126
d D 4.9 81/08/31 03:15:59 root 9 8
c fix per mike accetta
e
s 00001/00001/00126
d D 4.8 81/06/27 12:05:38 wnj 8 7
c remove HPER1_UNS from hard errors until figure out why it happens
e
s 00003/00001/00124
d D 4.7 81/03/17 18:15:12 wnj 7 6
c fix register definitions (mr 2 and er 2 dcrud... see comment)
e
s 00001/00001/00124
d D 4.6 81/03/09 13:21:18 wnj 6 5
c fix defn of SSE
e
s 00054/00052/00071
d D 4.5 81/03/09 00:26:55 wnj 5 4
c lint
e
s 00009/00000/00114
d D 4.4 81/02/25 23:29:27 wnj 4 3
c functional version with %b printf, etc
e
s 00107/00046/00007
d D 4.3 81/02/23 20:34:28 wnj 3 2
c extensive...
e
s 00000/00000/00053
d D 4.2 81/02/19 21:40:40 wnj 2 1
c %G%->%E%
e
s 00053/00000/00000
d D 4.1 81/02/19 21:34:10 wnj 1 0
c date and time created 81/02/19 21:34:10 by wnj
e
u
U
t
T
I 1
D 16
/*	%M%	%I%	%E%	*/
E 16
I 16
/*
D 17
 * Copyright (c) 1982 Regents of the University of California.
E 17
I 17
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 17
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 16

D 3
struct	device
E 3
I 3
struct hpdevice
E 3
{
D 3
	int	hpcs1;		/* control and Status register 1 */
	int	hpds;		/* Drive Status */
	int	hper1;		/* Error register 1 */
	int	hpmr;		/* Maintenance */ 
	int	hpas;		/* Attention Summary */
	int	hpda;		/* Desired address register */
	int	hpdt;		/* Drive type */
	int	hpla;		/* Look ahead */
E 3
I 3
	int	hpcs1;		/* control and status register 1 */
	int	hpds;		/* drive status */
	int	hper1;		/* error register 1 */
	int	hpmr;		/* maintenance */ 
	int	hpas;		/* attention summary */
	int	hpda;		/* desired address register */
	int	hpdt;		/* drive type */
	int	hpla;		/* look ahead */
E 3
	int	hpsn;		/* serial number */
D 3
	int	hpof;		/* Offset register */
	int	hpdc;		/* Desired Cylinder address register */
	int	hpcc;		/* Current Cylinder */
	int	hper2;		/* Error register 2 */
	int	hper3;		/* Error register 3 */
	int	hpec1;		/* Burst error bit position */
	int	hpec2;		/* Burst error bit pattern */
E 3
I 3
	int	hpof;		/* offset register */
	int	hpdc;		/* desired cylinder address register */
	int	hpcc;		/* current cylinder */
I 11
#define	hphr	hpcc		/* holding register */
E 11
I 7
/* on an rp drive, mr2 is called er2 and er2 is called er3 */
/* we use rm terminology here */
	int	hpmr2;		/* maintenance register 2 */
E 7
	int	hper2;		/* error register 2 */
D 7
	int	hper3;		/* error register 3 */
E 7
	int	hpec1;		/* burst error bit position */
	int	hpec2;		/* burst error bit pattern */
E 3
};

D 3
#define	GO	01
#define	PRESET	020
#define	RTC	016
#define	OFFSET	014
#define	SEEK	04
#define	SEARCH	030
#define	RECAL	06
#define	DCLR	010
#define	WCOM	060
#define	RCOM	070
#define	RELEASE	012
E 3
I 3
/* hpcs1 */
#define	HP_SC	0100000		/* special condition */
#define	HP_TRE	0040000		/* transfer error */
#define	HP_DVA	0004000		/* drive available */
#define	HP_RDY	0000200		/* controller ready */
#define	HP_IE	0000100		/* interrupt enable */
/* bits 5-1 are the command */
#define	HP_GO	0000001
E 3

D 3
#define	DVA	04000
#define	IE	0100
#define	PIP	020000
#define	DRY	0200
#define	ERR	040000
#define	TRE	040000
#define	DCK	0100000
#define	WLE	04000
#define	ECH	0100
#define	VV	0100
#define	DPR	0400
#define	MOL	010000
#define	FMT22	010000
#define	P400	020
#define	M400	0220
#define	P800	040
#define	M800	0240
#define	P1200	060
#define	M1200	0260
E 3
I 3
/* commands */
#define	HP_NOP		000		/* no operation */
#define	HP_UNLOAD	002		/* offline drive */
#define	HP_SEEK		004		/* seek */
#define	HP_RECAL	006		/* recalibrate */
#define	HP_DCLR		010		/* drive clear */
#define	HP_RELEASE	012		/* release */
#define	HP_OFFSET	014		/* offset */
#define	HP_RTC		016		/* return to centerline */
#define	HP_PRESET	020		/* read-in preset */
#define	HP_PACK		022		/* pack acknowledge */
#define	HP_SEARCH	030		/* search */
#define	HP_DIAGNOSE	034		/* diagnose drive */
#define	HP_WCDATA	050		/* write check data */
#define	HP_WCHDR	052		/* write check header and data */
#define	HP_WCOM		060		/* write data */
#define	HP_WHDR		062		/* write header */
#define	HP_WTRACKD	064		/* write track descriptor */
#define	HP_RCOM		070		/* read data */
#define	HP_RHDR		072		/* read header and data */
#define	HP_RTRACKD	074		/* read track descriptor */
	
/* hpds */
D 5
#define	HP_ATA		0100000		/* attention active */
#define	HP_ERR		0040000		/* composite drive error */
#define	HP_PIP		0020000		/* positioning in progress */
#define	HP_MOL		0010000		/* medium on line */
#define	HP_WRL		0004000		/* write locked */
#define	HP_LST		0002000		/* last sector transferred */
#define	HP_PGM		0001000		/* programmable */
#define	HP_DPR		0000400		/* drive present */
#define	HP_DRY		0000200		/* drive ready */
#define	HP_VV		0000100		/* volume valid */
E 5
I 5
#define	HPDS_ATA	0100000		/* attention active */
#define	HPDS_ERR	0040000		/* composite drive error */
#define	HPDS_PIP	0020000		/* positioning in progress */
#define	HPDS_MOL	0010000		/* medium on line */
#define	HPDS_WRL	0004000		/* write locked */
#define	HPDS_LST	0002000		/* last sector transferred */
#define	HPDS_PGM	0001000		/* programmable */
#define	HPDS_DPR	0000400		/* drive present */
#define	HPDS_DRY	0000200		/* drive ready */
#define	HPDS_VV		0000100		/* volume valid */
E 5
/* bits 1-5 are spare */
D 5
#define	HP_OM		0000001		/* offset mode */
E 5
I 5
#define	HPDS_OM		0000001		/* offset mode */
E 5

I 4
D 5
#define	HP_DREADY	(HP_DPR|HP_DRY|HP_MOL|HP_VV)
E 5
I 5
#define	HPDS_DREADY	(HPDS_DPR|HPDS_DRY|HPDS_MOL|HPDS_VV)
E 5
#define	HPDS_BITS \
"\10\20ATA\17ERR\16PIP\15MOL\14WRL\13LST\12PGM\11DPR\10DRY\7VV\1OM"

E 4
/* hper1 */
D 5
#define	HP_DCK		0100000		/* data check */
#define	HP_UNS		0040000		/* drive unsafe */
#define	HP_OPI		0020000		/* operation incomplete */
#define	HP_DTE		0010000		/* drive timing error */
#define	HP_WLE		0004000		/* write lock error */
#define	HP_IAE		0002000		/* invalid address error */
#define	HP_AOE		0001000		/* address overflow error */
#define	HP_HCRC		0000400		/* header crc error */
#define	HP_HCE		0000200		/* header compare error */
#define	HP_ECH		0000100		/* ecc hard error */
#define HP_WCF		0000040		/* write clock fail */
#define	HP_FER		0000020		/* format error */
#define	HP_PAR		0000010		/* parity error */
#define	HP_RMR		0000004		/* register modification refused */
#define	HP_ILR		0000002		/* illegal register */
#define	HP_ILF		0000001		/* illegal function */
E 5
I 5
#define	HPER1_DCK	0100000		/* data check */
#define	HPER1_UNS	0040000		/* drive unsafe */
#define	HPER1_OPI	0020000		/* operation incomplete */
#define	HPER1_DTE	0010000		/* drive timing error */
#define	HPER1_WLE	0004000		/* write lock error */
#define	HPER1_IAE	0002000		/* invalid address error */
#define	HPER1_AOE	0001000		/* address overflow error */
#define	HPER1_HCRC	0000400		/* header crc error */
#define	HPER1_HCE	0000200		/* header compare error */
#define	HPER1_ECH	0000100		/* ecc hard error */
#define HPER1_WCF	0000040		/* write clock fail */
#define	HPER1_FER	0000020		/* format error */
#define	HPER1_PAR	0000010		/* parity error */
#define	HPER1_RMR	0000004		/* register modification refused */
#define	HPER1_ILR	0000002		/* illegal register */
#define	HPER1_ILF	0000001		/* illegal function */
E 5

I 4
#define	HPER1_BITS \
"\10\20DCK\17UNS\16OPI\15DTE\14WLE\13IAE\12AOE\11HCRC\10HCE\
\7ECH\6WCF\5FER\4PAR\3RMR\2ILR\1ILF"
E 4
D 5
/* THIS NEEDS TO BE DOUBLE CHECKED... */
#define	HPER1_HARD    (HP_UNS|HP_WLE|HP_IAE|HP_AOE|HP_FER|HP_RMR|HP_ILR|HP_ILF)
E 5
I 5
#define	HPER1_HARD    \
D 8
	(HPER1_UNS|HPER1_WLE|HPER1_IAE|HPER1_AOE|\
E 8
I 8
	(HPER1_WLE|HPER1_IAE|HPER1_AOE|\
E 8
	 HPER1_FER|HPER1_RMR|HPER1_ILR|HPER1_ILF)
E 5

/* hper2 */
D 5
#define	HP_BSE		0100000		/* bad sector error */
#define	HP_SKI		0040000		/* seek incomplete */
#define	HP_OPE		0020000		/* operator plug error */
#define	HP_IVC		0010000		/* invalid command */
#define	HP_LSC		0004000		/* loss of system clock */
#define	HP_LBC		0002000		/* loss of bit check */
#define	HP_DVC		0000200		/* device check */
#define	HP_DPE		0000010		/* data parity error */
E 5
I 5
#define	HPER2_BSE	0100000		/* bad sector error */
#define	HPER2_SKI	0040000		/* seek incomplete */
#define	HPER2_OPE	0020000		/* operator plug error */
#define	HPER2_IVC	0010000		/* invalid command */
#define	HPER2_LSC	0004000		/* loss of system clock */
#define	HPER2_LBC	0002000		/* loss of bit check */
#define	HPER2_DVC	0000200		/* device check */
D 6
#define	HPER2_SSE	0000020		/* skip sector error (rm80) */
E 6
I 6
#define	HPER2_SSE	0000040		/* skip sector error (rm80) */
E 6
#define	HPER2_DPE	0000010		/* data parity error */
E 5

I 4
#define	HPER2_BITS \
D 5
"\10\20BSE\17SKI\16OPE\15IVC\14LSC\13LBC\10DVC\4DPE"
E 4
#define	HPER2_HARD    (HP_BSE|HP_OPE)
E 5
I 5
D 12
"\10\20BSE\17SKI\16OPE\15IVC\14LSC\13LBC\10DVC\5SSE\4DPE"
E 12
I 12
"\10\20BSE\17SKI\16OPE\15IVC\14LSC\13LBC\10DVC\6SSE\4DPE"
E 12
D 9
#define	HPER2_HARD    (HPER2_BSE|HPER2_OPE)
E 9
I 9
#define	HPER2_HARD    (HPER2_OPE)
E 9
E 5

/* hpof */
D 5
#define	HP_CMO		0100000		/* command modifier */
#define	HP_MTD		0040000		/* move track descriptor */
#define	HP_FMT22	0010000		/* 16 bit format */
#define	HP_ECI		0004000		/* ecc inhibit */
#define	HP_HCI		0002000		/* header compare inhibit */
#define	HP_SSEI		0001000		/* skip sector inhibit */
E 5
I 5
#define	HPOF_CMO	0100000		/* command modifier */
#define	HPOF_MTD	0040000		/* move track descriptor */
#define	HPOF_FMT22	0010000		/* 16 bit format */
#define	HPOF_ECI	0004000		/* ecc inhibit */
#define	HPOF_HCI	0002000		/* header compare inhibit */
#define	HPOF_SSEI	0001000		/* skip sector inhibit */
E 5

D 5
#define	HP_P400		020		/*  +400 uinches */
#define	HP_M400		0220		/*  -400 uinches */
#define	HP_P800		040		/*  +800 uinches */
#define	HP_M800		0240		/*  -800 uinches */
#define	HP_P1200	060		/* +1200 uinches */
#define	HP_M1200	0260		/* -1200 uinches */
E 5
I 5
#define	HPOF_P400	020		/*  +400 uinches */
#define	HPOF_M400	0220		/*  -400 uinches */
#define	HPOF_P800	040		/*  +800 uinches */
#define	HPOF_M800	0240		/*  -800 uinches */
#define	HPOF_P1200	060		/* +1200 uinches */
#define	HPOF_M1200	0260		/* -1200 uinches */
I 10

I 11
/* hphr (alias hpcc) commands */
#define	HPHR_MAXCYL	0x8017		/* maximum cylinder address */
#define	HPHR_MAXTRAK	0x8018		/* maximum track address */
#define	HPHR_MAXSECT	0x8019		/* maximum sector address */
#define	HPHR_FMTENABLE	0xffff		/* enable format command in cs1 */

E 11
/* hpmr */
#define	HPMR_SZ		0174000		/* ML11 system size */
#define	HPMR_ARRTYP	0002000		/* ML11 array type */
#define	HPMR_TRT	0001400		/* ML11 transfer rate */
I 11

/*
 * Systems Industries kludge: use value in
 * the serial # register to figure out real drive type.
 */
#define	SIMB_MB	0xff00		/* model byte value */
#define	SIMB_S6	0x2000		/* switch s6 */
#define	SIMB_LU	0x0007		/* logical unit (should = drive #) */

#define	SI9775D	0x0700		/* 9775 direct */
#define	SI9775M	0x0e00		/* 9775 mapped */
#define	SI9730D	0x0b00		/* 9730 direct */
#define	SI9730M	0x0d00		/* 9730 mapped */
#define	SI9766	0x0300		/* 9766 */
#define	SI9762	0x0100		/* 9762 */
I 14
#define	SICAPD	0x0500		/* Capricorn direct */
#define	SICAPN	0x0400		/* Capricorn mapped */
#define	SI9751D	0x0f00		/* Eagle direct */
E 14

#define	SIRM03	0x8000		/* RM03 indication */
#define	SIRM05	0x0000		/* RM05 pseudo-indication */
E 11
E 10
E 5
E 3
E 1
