h34773
s 00007/00096/00051
d D 7.2 87/02/19 17:36:33 karels 9 8
c merge common code from dmf and dmz drivers
e
s 00001/00001/00146
d D 7.1 86/06/05 01:07:49 mckusick 8 7
c 4.3BSD release version
e
s 00005/00002/00142
d D 6.5 86/04/12 14:13:47 karels 7 6
c remember dma count, as can't calculate correctly on Emulex;
c revert to "sticky" baudrate except for portselector
e
s 00002/00006/00142
d D 6.4 85/11/08 19:54:56 karels 6 5
c autoconfiguration vector calculations redone (by bloom);
c share unibus resources between multiplexor types; set open parameters
c uniformly, 9600 default; move modem control to line discipline;
c remove lcr, tms byte definitions, as must write as word
e
s 00007/00001/00141
d D 6.3 85/06/08 14:41:40 mckusick 5 4
c Add copyright
e
s 00027/00000/00115
d D 6.2 85/04/30 13:40:46 bloom 4 3
c add support for dmf lineprinter
e
s 00000/00000/00115
d D 6.1 83/07/29 07:27:22 sam 3 2
c 4.2 distribution
e
s 00001/00002/00114
d D 4.2 83/05/14 20:23:52 sam 2 1
c from steveg@tektronix.UUCP; even/odd parity remnant from dh
e
s 00116/00000/00000
d D 4.1 83/05/14 20:15:08 sam 1 0
c date and time created 83/05/14 20:15:08 by sam
e
u
U
t
T
I 1
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
/*
D 8
 * Copyright (c) 1982 Regents of the University of California.
E 8
I 8
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 5

/*
 * DMF-32 definitions.
 */

/*
D 9
 * "dmf" (unqualified) refers to the async portion of the dmf32,
E 9
I 9
 * "dmfa" refers to the async portion of the dmf32,
E 9
 * "dmfc" to the combo portion,
 * "dmfs" to the sync portion,
 * "dmfl" to the lp portion, and
 * "dmfd" to the dr portion.
 */
struct dmfdevice {
	short	dmfccsr0;		/* combo csr 0 */
	short	dmfccsr1;		/* combo csr 1 */
D 9
	short	dmfs[4];
	short	dmfcsr;			/* control-status register */
	short	dmflpr;			/* line parameter register */
	short	dmfrbuf;		/* receiver buffer (ro) */
	union {
		u_short	dmfirw;		/* indirect register word */
		u_char	dmfirc[2];	/*    "         "    bytes */
	} dmfun;
D 7
	short	dmfl[2];
	short	dmfd[4];
E 7
I 7
	short	dmfl_ctrl;	/* line printer control register */
	short	dmfl_indrct;	/* line printer indirect register */
	short	dmfd[4];	/* for dr11 (not implemented) */
E 9
I 9
	short	dmfs[4];		/* synch. device */
	struct	dmx_octet dmfa;		/* asynch portion */
	short	dmfl_ctrl;		/* line printer control register */
	short	dmfl_indrct;		/* line printer indirect register */
	short	dmfd[4];		/* for dr11 (not implemented) */
E 9
E 7
};

D 9
#define	dmfrsp	dmfrbuf		/* receive silo parameter register (wo) */
#define	dmftbuf	dmfun.dmfirc[0]	/* transmit buffer */
#define	dmftsc	dmfun.dmfirc[0]	/* transmit silo count */
#define	dmfrms	dmfun.dmfirc[1]	/* receive modem status */
D 6
#define	dmflcr	dmfun.dmfirc[0]	/* line control register */
#define	dmftms	dmfun.dmfirc[1]	/* transmit modem status */
E 6
I 6
#define	dmflctms dmfun.dmfirw	/* line control, transmit modem status */
E 6
#define	dmftba	dmfun.dmfirw	/* transmit buffer address */
#define	dmftcc	dmfun.dmfirw	/* transmit character count */
E 9

D 9
/* bits in dmfcsr */
#define	DMF_TI	0100000		/* transmit interrupt */
#define	DMF_TIE	0040000		/* transmit interrupt enable */
#define	DMF_NXM	0020000		/* non-existant memory */
#define	DMF_LIN	0003400		/* transmit line number */
#define	DMF_RI	0000200		/* receiver interrupt */
#define	DMF_RIE	0000100		/* receiver interrupt enable */
#define	DMF_CLR	0000040		/* master reset */
#define	DMF_IAD	0000037		/* indirect address register */

#define	DMFIR_TBUF	000	/* select tbuf indirect register */
#define	DMFIR_LCR	010	/* select lcr indirect register */
#define	DMFIR_TBA	020	/* select tba indirect register */
#define	DMFIR_TCC	030	/* select tcc indirect register */

/* bits in dmflpr */
#define	BITS6	(01<<3)
#define	BITS7	(02<<3)
#define	BITS8	(03<<3)
#define	TWOSB	0200
#define	PENABLE	040
D 2
/* DEC manuals incorrectly say this bit causes generation of even parity. */
#define	OPAR	0100
E 2
I 2
#define	EPAR	0100
E 2

#define	DMF_IE	(DMF_TIE|DMF_RIE)

#define	DMF_SILOCNT	32		/* size of DMF output silo (per line) */

/* bits in dmfrbuf */
#define	DMF_DSC		0004000		/* data set change */
#define	DMF_PE		0010000		/* parity error */
#define	DMF_FE		0020000		/* framing error */
#define	DMF_DO		0040000		/* data overrun */

/* bits in dmfrms */
#define	DMF_USRR	0004		/* user modem signal (pin 25) */
#define	DMF_SR		0010		/* secondary receive */
#define	DMF_CTS		0020		/* clear to send */
#define	DMF_CAR		0040		/* carrier detect */
#define	DMF_RNG		0100		/* ring */
#define	DMF_DSR		0200		/* data set ready */

/* bits in dmftms */
#define	DMF_USRW	0001		/* user modem signal (pin 18) */
#define	DMF_DTR		0002		/* data terminal ready */
#define	DMF_RATE	0004		/* data signal rate select */
#define	DMF_ST		0010		/* secondary transmit */
#define	DMF_RTS		0020		/* request to send */
#define	DMF_BRK		0040		/* pseudo break bit */
#define	DMF_PREEMPT	0200		/* preempt output */

/* flags for modem control */
#define	DMF_ON	(DMF_DTR|DMF_RTS)
#define	DMF_OFF	0

D 6
/* bits in dmflcr */
E 6
I 6
/* bits in dmflctms */
E 6
#define	DMF_MIE		0040		/* modem interrupt enable */
#define	DMF_FLUSH	0020		/* flush transmit silo */
#define	DMF_RBRK	0010		/* real break bit */
#define	DMF_RE		0004		/* receive enable */
#define	DMF_AUTOX	0002		/* auto XON/XOFF */
#define	DMF_TE		0001		/* transmit enable */

#define	DMFLCR_ENA	(DMF_MIE|DMF_RE|DMF_TE)

/* bits in dm lsr, copied from dh.c */
#define	DML_USR		0001000		/* usr modem sig, not a real DM bit */
#define	DML_DSR		0000400		/* data set ready, not a real DM bit */
#define	DML_RNG		0000200		/* ring */
#define	DML_CAR		0000100		/* carrier detect */
#define	DML_CTS		0000040		/* clear to send */
#define	DML_SR		0000020		/* secondary receive */
#define	DML_ST		0000010		/* secondary transmit */
#define	DML_RTS		0000004		/* request to send */
#define	DML_DTR		0000002		/* data terminal ready */
#define	DML_LE		0000001		/* line enable */
D 6

#define SETLCR(pt, exp) \
	pt->dmfun.dmfirw = (((pt)->dmftms)<<8) | ((exp)&0xff)
E 6
I 4

E 9
/* dmf line printer csr def */
#define DMFL_PEN	(1<<0)		/* print enable */
#define DMFL_RESET	(1<<1)		/* master reset */
#define DMFL_FORMAT	(1<<2)		/* format control */
#define DMFL_UNUSED	(3<<3)
#define DMFL_MAINT	(1<<5)		/* maintenance mode on */
#define DMFL_IE		(1<<6)		/* intr enable */
#define DMFL_PDONE	(1<<7)		/* print done bit */
#define DMFL_INDIR	(7<<8)		/* indirect reg */
#define DMFL_UNUSED2	(1<<11)
#define DMFL_CONV	(1<<12)		/* connect verify */
#define	DMFL_DAVRDY	(1<<13)		/* davfu ready */
#define DMFL_OFFLINE	(1<<14)		/* printer offline */
#define DMFL_DMAERR	(1<<15)		/* dma error bit */
#define DMFL_BUFSIZ	512		/* max chars per dma */
#define DMFL_DEFCOLS	132		/* default # of cols/line <=255 */
#define DMFL_DEFLINES	66		/* default # of lines/page <=255 */
I 7
#define DMFL_OPTIONS	((1 << 8) | (1 << 9) | (1 << 15))
D 9
					/* auto cr, real ff, no lower to upper */
E 9
I 9
				/* auto cr, real ff, no lower to upper */
E 9
E 7

/*
 *  Bits in the configuration register
 */
#define DMFC_CONFMASK	0xf000		/* picks off the configuration bits */
#define	DMFC_DR		0x1000		/* DR11 parallel interface */
#define DMFC_LP		0x2000		/* LP dma parallel lineprinter i'face */
#define DMFC_SYNC	0x4000		/* Synchronous serial interface */
#define DMFC_ASYNC	0x8000		/* 8 Serial ports */
E 4
E 1
