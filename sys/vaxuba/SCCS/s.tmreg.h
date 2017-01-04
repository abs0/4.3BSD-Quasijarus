h39306
s 00001/00001/00097
d D 7.1 86/06/05 01:17:30 mckusick 10 9
c 4.3BSD release version
e
s 00029/00000/00069
d D 6.3 85/09/20 17:15:29 mckusick 9 8
c add AVIV support
e
s 00007/00001/00062
d D 6.2 85/06/08 14:23:48 mckusick 8 7
c Add copyright
e
s 00000/00000/00063
d D 6.1 83/07/29 07:29:17 sam 7 6
c 4.2 distribution
e
s 00001/00001/00062
d D 4.6 82/02/03 19:15:42 root 6 5
c fix device register structure's names
e
s 00019/00019/00044
d D 4.5 81/03/09 00:27:34 wnj 5 4
c lint
e
s 00008/00000/00055
d D 4.4 81/02/25 23:30:15 wnj 4 3
c functional version with %b printf, etc
e
s 00043/00039/00012
d D 4.3 81/02/21 21:29:58 wnj 3 2
c misc changes for first working interlockable version
e
s 00002/00000/00049
d D 4.2 81/02/19 21:42:30 wnj 2 1
c %G%->%E%
e
s 00049/00000/00000
d D 4.1 81/02/19 21:34:31 wnj 1 0
c date and time created 81/02/19 21:34:31 by wnj
e
u
U
t
T
I 2
D 8
/*	%M%	%I%	%E%	*/
E 8
I 8
/*
D 10
 * Copyright (c) 1982 Regents of the University of California.
E 10
I 10
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 8

I 3
/*
 * TM11 controller registers
 */
E 3
E 2
I 1
D 6
struct device {
E 6
I 6
struct tmdevice {
E 6
D 3
	u_short	tmer;
	u_short	tmcs;
	short	tmbc;
	u_short tmba;
	short	tmdb;
	short	tmrd;
E 3
I 3
	u_short	tmer;		/* error register, per drive */
	u_short	tmcs;		/* control-status register */
	short	tmbc;		/* byte/frame count */
	u_short tmba;		/* address */
	short	tmdb;		/* data buffer */
	short	tmrd;		/* read lines */
	short	tmmr;		/* maintenance register */
I 9
#ifdef	AVIV
	short	tmfsr;		/* formatter status reading */
#endif
E 9
E 3
};

#define	b_repcnt  b_bcount
#define	b_command b_resid

/* bits in tmcs */
D 3
#define	GO	01
#define	OFFL	0
#define	RCOM	02
#define	WCOM	04
#define	WEOF	06
#define	SFORW	010
#define	SREV	012
#define	WIRG	014
#define	REW	016
#define	IENABLE	0100
#define	CUR	0200
#define	NOP	IENABLE
#define	DCLR	010000
#define	D800	060000
#define	ERROR	0100000
E 3
I 3
#define	TM_GO		0000001
#define	TM_OFFL		0000000		/* offline */
#define	TM_RCOM		0000002		/* read */
#define	TM_WCOM		0000004		/* write */
#define	TM_WEOF		0000006		/* write-eof */
#define	TM_SFORW	0000010		/* space forward */
#define	TM_SREV		0000012		/* space backwards */
#define	TM_WIRG		0000014		/* write with xtra interrecord gap */
#define	TM_REW		0000016		/* rewind */
#define	TM_SENSE	TM_IE		/* sense (internal to driver) */
I 4

#define	tmreverseop(cmd)		((cmd)==TM_SREV || (cmd)==TM_REW)

E 4
/* TM_SNS is a pseudo-op used to get tape status */
#define	TM_IE		0000100		/* interrupt enable */
#define	TM_CUR		0000200		/* control unit is ready */
#define	TM_DCLR		0010000		/* drive clear */
#define	TM_D800		0060000		/* select 800 bpi density */
#define	TM_ERR		0100000		/* drive error summary */
E 3

/* bits in tmer */
D 3
#define	TUR	1
#define	RWS	02
#define	WRL	04
#define	SDWN	010
#define	BOT	040
#define	SELR	0100
#define	NXM	0200
#define	TMBTE	0400
#define	RLE	01000
#define	EOT	02000
#define	BGL	04000
#define	PAE	010000
#define	CRE	020000
#define	EOF	040000
#define	ILC	0100000
E 3
I 3
D 5
#define	TM_TUR		0000001		/* tape unit ready */
#define	TM_RWS		0000002		/* tape unit rewinding */
#define	TM_WRL		0000004		/* tape unit write protected */
#define	TM_SDWN		0000010		/* gap settling down */
I 4
#define	TM_CH7		0000020		/* 7 channel tape */
E 4
#define	TM_BOT		0000040		/* at beginning of tape */
#define	TM_SELR		0000100		/* tape unit properly selected */
#define	TM_NXM		0000200		/* non-existant memory */
#define	TM_BTE		0000400		/* bad tape error */
#define	TM_RLE		0001000		/* record length error */
#define	TM_EOT		0002000		/* at end of tape */
#define	TM_BGL		0004000		/* bus grant late */
#define	TM_PAE		0010000		/* parity error */
#define	TM_CRE		0020000		/* cyclic redundancy error */
#define	TM_EOF		0040000		/* end of file */
#define	TM_ILC		0100000		/* illegal command */
E 5
I 5
#define	TMER_ILC	0100000		/* illegal command */
#define	TMER_EOF	0040000		/* end of file */
#define	TMER_CRE	0020000		/* cyclic redundancy error */
#define	TMER_PAE	0010000		/* parity error */
#define	TMER_BGL	0004000		/* bus grant late */
#define	TMER_EOT	0002000		/* at end of tape */
#define	TMER_RLE	0001000		/* record length error */
#define	TMER_BTE	0000400		/* bad tape error */
#define	TMER_NXM	0000200		/* non-existant memory */
#define	TMER_SELR	0000100		/* tape unit properly selected */
#define	TMER_BOT	0000040		/* at beginning of tape */
#define	TMER_CH7	0000020		/* 7 channel tape */
#define	TMER_SDWN	0000010		/* gap settling down */
#define	TMER_WRL	0000004		/* tape unit write protected */
#define	TMER_RWS	0000002		/* tape unit rewinding */
#define	TMER_TUR	0000001		/* tape unit ready */
E 5
I 4

D 5
#define	TMEREG_BITS	\
E 5
I 5
#define	TMER_BITS	\
E 5
"\10\20ILC\17EOF\16CRE\15PAE\14BGL\13EOT\12RLE\11BTE\10NXM\
\7SELR\6BOT\5CH7\4SDWN\3WRL\2RWS\1TUR"
E 4
E 3

D 3
#define	HARD    (ILC|EOT)
#define	SOFT	(CRE|PAE|BGL|RLE|TMBTE|NXM)

E 3
I 3
D 5
#define	TM_HARD		(TM_ILC|TM_EOT)
#define	TM_SOFT		(TM_CRE|TM_PAE|TM_BGL|TM_RLE|TM_BTE|TM_NXM)
E 5
I 5
#define	TMER_HARD	(TMER_ILC|TMER_EOT)
#define	TMER_SOFT	(TMER_CRE|TMER_PAE|TMER_BGL|TMER_RLE|TMER_BTE|TMER_NXM)
I 9

#ifdef	AVIV
/* bits in tmmr (formatter diagnostic reading) */
#define	DTS		000000		/* select dead track status */
#   define	DTS_MASK	0xff

#define	DAB		010000		/* select diagnostic aid bits */
#   define  DAB_MASK		037	/* reject code only */

#define	RWERR		020000		/* select read-write errors */
#    define RWERR_MASK		01777	/* include bit 9 (MAI) */
#    define RWERR_BITS \
"\10\12MAI\11CRC ERR\10WTMCHK\7UCE\6PART REC\5MTE\3END DATA CHK\
\2VEL ERR\1DIAG MODE"

#define	DRSENSE		030000		/* select drive sense */
#    define DRSENSE_MASK	0777
#    define DRSENSE_BITS \
"\10\11WRTS\10EOTS\7BOTS\6WNHB\5PROS\4BWDS\3HDNG\2RDYS\1ON LINE"

#define	CRCF		040000		/* CRC-F Generator */

#define	FSR_BITS \
"\10\20REJ\17TMS\16OVRN\15DATACHK\14SSC\13EOTS\12WRTS\11ROMPS\10CRERR\
\7ONLS\6BOTS\5HDENS\4BUPER\3FPTS\2REWS\1RDYS"
#endif	AVIV
E 9
E 5
E 3
E 1
