h51909
s 00003/00005/00170
d D 7.2 88/05/26 09:40:43 karels 8 7
c remove extra \'s in strings
e
s 00001/00001/00174
d D 7.1 86/06/05 01:22:42 mckusick 7 6
c 4.3BSD release version
e
s 00007/00001/00168
d D 6.2 85/06/08 14:29:15 mckusick 6 5
c Add copyright
e
s 00000/00000/00169
d D 6.1 83/07/29 07:30:37 sam 5 4
c 4.2 distribution
e
s 00001/00001/00168
d D 4.4 81/11/11 15:30:01 sam 4 3
c fix SCCS line
e
s 00091/00093/00078
d D 4.3 81/11/07 10:51:34 wnj 3 2
c cleanup (hex now)
e
s 00008/00004/00163
d D 4.2 81/11/06 10:50:02 root 2 1
c redefine hard errors
e
s 00167/00000/00000
d D 4.1 81/11/04 10:54:14 wnj 1 0
c date and time created 81/11/04 10:54:14 by wnj
e
u
U
t
T
I 1
D 4
/*	%M%	%E%	%I%	*/
E 4
I 4
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
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 6
E 4

/*
 * System Industries Model 9700 Tape Drive
 *   emulates TU45 on the UNIBUS
 */

D 3
struct	utdevice
{
E 3
I 3
struct utdevice {
E 3
	u_short	utcs1;		/* control status register 1 */
	short	utwc;		/* word count register */
	u_short	utba;		/* low 16-bits of bus address */
D 2
	u_short	utfc;		/* frame counter */
E 2
I 2
	short	utfc;		/* frame counter */
E 2
	u_short	utcs2;		/* control status register 2 */
	u_short	utds;		/* drive status register */
	u_short	uter;		/* error register */
	u_short	utas;		/* attention status register */
	u_short	utcc;		/* NRZI CRC character for validation */
	u_short	utdb;		/* data buffer reg (not emulated) */
	u_short	utmr;		/* maintenance reg (not emulated) */
	u_short	utdt;		/* drive type register (not emulated) */
	u_short	utsn;		/* serial number reg (not emulated) */
	u_short	uttc;		/* tape control register */
	u_short	utbae;		/* buffer address extension register */
	u_short	utcs3;		/* control and status register 3 */
};

/*
 * utcs1 --
 *   cmds, interrupt enable, extended address bits, and status
 */
D 3
#define	UT_GO		01		/* go bit */
E 3
I 3
#define	UT_GO		0x0001		/* go bit */
E 3
/* function codes reside in bits 5-1 */
D 3
#define	UT_NOP		(0)		/* no operation */
#define	UT_REWOFFL	(01<<1)		/* rewind offline */
#define UT_LOOP		(02<<1)		/* loop read/write */
#define	UT_REW		(03<<1)		/* rewind */
#define	UT_CLEAR	(04<<1)		/* drive clear */
#define	UT_SENSE	(05<<1)		/* drive sense */
#define	UT_PRESET	(010<<1)	/* read in preset */
#define	UT_DIAGN	(011<<1)	/* diagnostic mode set */
#define	UT_ERASE	(012<<1)	/* erase */
#define	UT_WEOF		(013<<1)	/* write tape mark */
#define	UT_SFORW	(014<<1)	/* forward space block */
#define	UT_SREV		(015<<1)	/* reverse space block */
#define	UT_SFORWF	(016<<1)	/* forward space file */
#define	UT_SREVF	(017<<1)	/* reverse space file */
#define	UT_WCHFORW	(024<<1)	/* write check forward */
#define	UT_WCHREV	(027<<1)	/* write check reverse */
#define	UT_WCOM		(030<<1)	/* write forward */
#define	UT_RCOM		(034<<1)	/* read forward */
#define	UT_RREV		(037<<1)	/* read reverse */
E 3
I 3
#define	UT_NOP		0x0000		/* no operation */
#define	UT_REWOFFL	0x0002		/* rewind offline */
#define	UT_LOOP		0x0004		/* loop read/write */
#define	UT_REW		0x0006		/* rewind */
#define	UT_CLEAR	0x0008		/* drive clear */
#define	UT_SENSE	0x000a		/* drive sense */
#define	UT_PRESET	0x0010		/* read in preset */
#define	UT_DIAGN	0x0012		/* diagnostic mode set */
#define	UT_ERASE	0x0014		/* erase */
#define	UT_WEOF		0x0016		/* write tape mark */
#define	UT_SFORW	0x0018		/* forward space block */
#define	UT_SREV		0x001a		/* reverse space block */
#define	UT_SFORWF	0x001c		/* forward space file */
#define	UT_SREVF	0x001e		/* reverse space file */
#define	UT_WCHFORW	0x0028		/* write check forward */
#define	UT_WCHREV	0x002e		/* write check reverse */
#define	UT_WCOM		0x0030		/* write forward */
#define	UT_RCOM		0x0038		/* read forward */
#define	UT_RREV		0x003e		/* read reverse */
E 3
/* the remainder are control and status bits */
D 3
#define	UT_IE		0000100		/* interrupt-enable */
#define	UT_RDY		0000200		/* controller ready */
#define	UT_EADDR	0001400		/* extended address bits */
E 3
I 3
#define	UT_IE		0x0040		/* interrupt-enable */
#define	UT_RDY		0x0080		/* controller ready */
#define	UT_EADDR	0x0300		/* extended address bits */
E 3
/* bit 10 unused */
D 3
#define	UT_DVA		0004000		/* drive available */
E 3
I 3
#define	UT_DVA		0x0800		/* drive available */
E 3
/* bit 12 unused */
/* bit 13 - massbus control parity error not emulated */
D 3
#define	UT_TRE		0040000		/* transfer error */
#define	UT_SC		0100000		/* special condition */
E 3
I 3
#define	UT_TRE		0x4000		/* transfer error */
#define	UT_SC		0x8000		/* special condition */
E 3

#define	UT_BITS \
"\10\20SC\17TRE\14DVA\10RDY\7IE\1GO"

/*
 * utcs2 --
D 3
 *   error flags and unit select
E 3
I 3
 *   controller clear, error flags, and unit select
E 3
 */
D 3
#define	UTCS2_DLT	0100000		/* data late */
#define	UTCS2_WCE	0040000		/* write check error */
#define	UTCS2_PE	0020000		/* parity error */
#define	UTCS2_NED	0010000		/* non existent drive */
#define	UTCS2_NEM	0004000		/* non existant memory */
#define	UTCS2_PGE	0002000		/* program error */
#define	UTCS2_MXF	0001000		/* missed transfer */
#define	UTCS2_RPE	0000400		/* rom parity error */
#define	UTCS2_OR	0000200		/* output ready (not emulated) */
#define	UTCS2_IR	0000100		/* input ready (not emulated) */
#define	UTCS2_CLR	0000040		/* controller clear */
#define	UTCS2_PAT	0000020		/* parity test */
#define	UTCS2_BAI	0000010		/* UNIBUS address increment inhibit */
/* bits 2-0 unit select */
E 3
I 3
/* bits 0-2 are unit select */
#define	UTCS2_BAI	0x0008		/* UNIBUS address increment inhibit */
#define	UTCS2_PAT	0x0010		/* parity test */
#define	UTCS2_CLR	0x0020		/* controller clear */
#define	UTCS2_IR	0x0040		/* input ready (not emulated) */
#define	UTCS2_OR	0x0080		/* output ready (not emulated) */
#define	UTCS2_RPE	0x0100		/* rom parity error */
#define	UTCS2_MXF	0x0200		/* missed transfer */
#define	UTCS2_NEM	0x0400		/* non existant memory */
#define	UTCS2_PGE	0x0800		/* program error */
#define	UTCS2_NED	0x1000		/* non existent drive */
#define	UTCS2_PE	0x2000		/* parity error */
#define	UTCS2_WCE	0x4000		/* write check error */
#define	UTCS2_DLT	0x8000		/* data late */
E 3

D 3
#define UTCS2_BITS \
E 3
I 3
#define	UTCS2_BITS \
E 3
D 8
"\10\20DLT\17WCE\16PE\15NED\14\NEM\13\PGE\12\MXF\11RPE\10OR\7IR\6CLR\5PAT\4\BAI"
E 8
I 8
"\10\20DLT\17WCE\16PE\15NED\14NEM\13PGE\12MXF\11RPE\10OR\7IR\6CLR\5PAT\4BAI"
E 8

/*
 * utds --
D 3
 *   drive status register
E 3
I 3
 *   beginning of tape, end of tape, error summary bit, plus lots more
E 3
 */
D 3
#define	UTDS_ATA	0100000		/* attention active */
#define	UTDS_ERR	0040000		/* composite error */
#define	UTDS_PIP	0020000		/* positioning in progress */
#define	UTDS_MOL	0010000		/* medium on line */
#define	UTDS_WRL	0004000		/* write lock */
#define	UTDS_EOT	0002000		/* end of tape */
#define	UTDS_GCR	0001000		/* GCR status */
#define	UTDS_DPR	0000400		/* drive present (always 1) */
#define	UTDS_DRY	0000200		/* drive ready */
#define	UTDS_SSC	0000100		/* slave status change */
#define	UTDS_PES	0000040		/* phase encode status */
#define	UTDS_SDWN	0000020		/* slowing down */
#define	UTDS_IDB	0000010		/* identification burst */
#define	UTDS_TM		0000004		/* tape mark */
#define	UTDS_BOT	0000002		/* beginning of tape */
#define	UTDS_SLA	0000001		/* slave attention */
E 3
I 3
#define	UTDS_SLA	0x0001		/* slave attention */
#define	UTDS_BOT	0x0002		/* beginning of tape */
#define	UTDS_TM		0x0004		/* tape mark */
#define	UTDS_IDB	0x0008		/* identification burst */
#define	UTDS_SDWN	0x0010		/* slowing down */
#define	UTDS_PES	0x0020		/* phase encode status */
#define	UTDS_SSC	0x0040		/* slave status change */
#define	UTDS_DRY	0x0080		/* drive ready */
#define	UTDS_DPR	0x0100		/* drive present (always 1) */
#define	UTDS_GCR	0x0200		/* GCR status */
#define	UTDS_EOT	0x0400		/* end of tape */
#define	UTDS_WRL	0x0800		/* write lock */
#define	UTDS_MOL	0x1000		/* medium on line */
#define	UTDS_PIP	0x2000		/* positioning in progress */
#define	UTDS_ERR	0x4000		/* composite error */
#define	UTDS_ATA	0x8000		/* attention active */
E 3

#define	UTDS_BITS \
D 8
"\10\20ATA\17ERR\16PIP\15MOL\14WRL\13EOT\12GCR\11DPR\10DRY\
\7SSC\6PES\5SDWN\4IDB\3TM\2BOT\1SLA"
E 8
I 8
"\10\20ATA\17ERR\16PIP\15MOL\14WRL\13EOT\12GCR\11DPR\10DRY\7SSC\6PES\5SDWN\4IDB\3TM\2BOT\1SLA"
E 8

/*
 * uter --
D 3
 *   general error register
E 3
I 3
 *   detailed breakdown of error summary bit from cs2
E 3
 */
D 3
#define	UTER_COR	0100000		/* correctible data error */
#define	UTER_UNS	0040000		/* unsafe */
#define	UTER_OPI	0020000		/* operation incomplete */
#define	UTER_DTE	0010000		/* drive timing error */
#define	UTER_NEF	0004000		/* non executable function */
#define	UTER_CS		0002000		/* correctable skew */
#define	UTER_FCE	0001000		/* frame count error */
#define	UTER_NSG	0000400		/* non standard gap */
#define	UTER_PEF	0000200		/* PE format error */
#define	UTER_INC	0000100		/* incorrectable data */
#define	UTER_DPAR	0000040		/* data bus parity error */
#define	UTER_FMT	0000020		/* format error */
#define	UTER_RPE	0000010		/* read data parity error */
#define	UTER_RMR	0000004		/* register modification refused */
#define	UTER_ILR	0000002		/* illegal register (always 0) */
#define	UTER_ILF	0000001		/* illegal function */
E 3
I 3
#define	UTER_ILF	0x0001		/* illegal function */
#define	UTER_ILR	0x0002		/* illegal register (always 0) */
#define	UTER_RMR	0x0004		/* register modification refused */
#define	UTER_RPE	0x0008		/* read data parity error */
#define	UTER_FMT	0x0010		/* format error */
#define	UTER_DPAR	0x0020		/* data bus parity error */
#define	UTER_INC	0x0040		/* incorrectable data */
#define	UTER_PEF	0x0080		/* PE format error */
#define	UTER_NSG	0x0100		/* non standard gap */
#define	UTER_FCE	0x0200		/* frame count error */
#define	UTER_CS		0x0400		/* correctable skew */
#define	UTER_NEF	0x0800		/* non executable function */
#define	UTER_DTE	0x1000		/* drive timing error */
#define	UTER_OPI	0x2000		/* operation incomplete */
#define	UTER_UNS	0x4000		/* unsafe */
#define	UTER_COR	0x8000		/* correctible data error */
E 3

D 2
/* those errors we consider "hard" errors */
#define	UTER_HARD	(UTER_UNS|UTER_DTE|UTER_NEF|UTER_NSG|UTER_PEF|UTER_INC|\
			 UTER_DPAR|UTER_FMT|UTER_RPE|UTER_RMR|UTER_ILF)
E 2
I 2
/*
 * These errors we consider "hard"; UTER_OPI and UTER_RPE
 * are considered "soft", at least for the moment.
 */
#define	UTER_HARD	(UTER_UNS|UTER_NEF|UTER_DPAR|UTER_FMT|UTER_RMR|\
			 UTER_ILR|UTER_ILF)
E 2

#define	UTER_BITS \
D 3
"\10\20COR\17UNS\16DOPI\15DTE\14NEF\13CS\12FCE\11NSG\10PEF\
E 3
I 3
D 8
"\10\20COR\17UNS\16OPI\15DTE\14NEF\13CS\12FCE\11NSG\10PEF\
E 3
\7INC\6DPAR\5FMT\4RPE\3RMR\2ILR\1ILF"
E 8
I 8
"\10\20COR\17UNS\16OPI\15DTE\14NEF\13CS\12FCE\11NSG\10PEF\7INC\6DPAR\5FMT\4RPE\3RMR\2ILR\1ILF"
E 8

/*
 * uttc --
D 3
 *   tape control register
E 3
I 3
 *   tape format and density
E 3
 */
D 3
#define	UTTC_ACCL	0100000		/* acceleration */
#define	UTTC_FCS	0040000		/* frame count status */
#define	UTTC_TCW	0020000		/* tape control write */
#define	UTTC_EAODTE	0010000		/* enable aborts on data transfer
					   errors (not emulated) */
/* bit 11 not used */
#define	UTTC_DEN	0003400		/* density select (see below) */
#define	UTTC_FMT	0000360		/* format select (see below) */
#define	UTTC_EVPAR	0000010		/* even parity */
E 3
/* bits 0-2 are slave select */
I 3
#define	UTTC_EVPAR	0x0008		/* even parity */
#define	UTTC_FMT	0x00f0		/* format select (see below) */
#define	UTTC_DEN	0x0700		/* density select (see below) */
/* bit 11 not used */
#define	UTTC_EAODTE	0x1000		/* (not emulated) */
#define	UTTC_TCW	0x2000		/* tape control write */
#define	UTTC_FCS	0x4000		/* frame count status */
#define	UTTC_ACCL	0x8000		/* acceleration */
E 3

/* the bits to stuff in UTTC_DEN */
D 3
#define	UT_NRZI		0000000		/* 800 bpi code */
#define	UT_PE		0002000		/* 1600 bpi code */
#define	UT_GCR		0002400		/* 6250 bpi code */
E 3
I 3
#define	UT_NRZI		0x0000		/* 800 bpi code */
#define	UT_PE		0x0400		/* 1600 bpi code */
#define	UT_GCR		0x0500		/* 6250 bpi code */
E 3

/* tape formats - only PDP-11 standard is supported */
D 3
#define	PDP11FMT	0000300		/* PDP-11 standard */
E 3
I 3
#define	PDP11FMT	0x00c0		/* PDP-11 standard */
E 3

#define	b_repcnt  b_bcount
#define	b_command b_resid
I 2
#define	b_state	  b_active  
E 2
E 1
