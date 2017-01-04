h52374
s 00005/00125/00020
d D 7.2 87/02/19 17:36:38 karels 4 3
c merge common code from dmf and dmz drivers
e
s 00001/00001/00144
d D 7.1 86/06/05 01:08:56 mckusick 3 2
c 4.3BSD release version
e
s 00030/00040/00115
d D 6.2 85/12/19 17:49:27 karels 2 1
c try to make this sucker work!  futz modem control to not look like
c a DM-11 internally, careful about word-only registers; still modem control
c doesn't work right
e
s 00155/00000/00000
d D 6.1 85/10/17 14:14:57 mckusick 1 0
c date and time created 85/10/17 14:14:57 by mckusick
e
u
U
t
T
I 1
/*
D 3
 * Copyright (c) 1985 Regents of the University of California.
E 3
I 3
 * Copyright (c) 1985, 1986 Regents of the University of California.
E 3
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

/*
D 4
 * HISTORY
 * 23-Apr-85  Joe Camaratta (jcc) at Siemens RTL
 *	Header file for DEC's DMZ32
E 4
I 4
 * Registers for DMZ-32.
 * Defined in terms of dmx_octet common registers.
E 4
 */
D 4

E 4
struct dmzdevice {
D 4
	short dmz_config;	/* configuration cntl and status register */
	short dmz_diag;		/* diagnostic control and status register */
	struct {
		short octet_csr;	/* octet control and status */
		short octet_lprm;	/* line parameter */
		union{
			short octet_rb;		/* receiver buffer */
			short octet_rsp;	/* receive silo parameter */
		} octet_receive;
		union{
			u_short word;		/* word */
			u_char bytes[2];	/* bytes */
		} octet_ir;			/* indirect registers */
	} octet[3];
	short dmz_unused[2];
E 4
I 4
	short	dmz_config;			/* configuration csr */
	short	dmz_diag;			/* diagnostic csr */
	struct	dmx_octet dmz_octet[3];		/* per-octet registers */
E 4
};

D 4
#define octet_sato octet_rsp

/* aliases for asynchronous indirect control registers */
#define	IR_TBUF		000	/* transmit character */
D 2
#define	IR_RMS		000	/* receive modem status register */
#define	IR_TSC		000	/* transmit silo count */
E 2
I 2
#define	IR_RMSTSC	000	/* receive modem status, transmit silo count */
E 2
#define	IR_LCTMR	010	/* line control and transmit modem */
#define	IR_TBA		020	/* transmit buffer address register */
#define	IR_TCC		030	/* transmit character count (DMA) */

#define	octet_tbf	octet_ir.bytes[0]	/* transmit buffer */
D 2
#define	octet_tbf2	octet_ir.word		/* transmit buffer for 2 chars */
#define	octet_rms	octet_ir.bytes[1]	/* receive modem status */
#define	octet_tsc	octet_ir.bytes[0]	/* transmit silo count */
#define	octet_lctmr	octet_ir.word		/* line control and transmit modem */
E 2
I 2
#define	octet_tbf2	octet_ir.word		/* transmit buffer, 2 chars */
#define	octet_rmstsc	octet_ir.word	/* rcv modem status, xmit silo count */
#define	octet_lctmr	octet_ir.word		/* line control, xmit modem */
E 2
#define	octet_tba	octet_ir.word		/* transmit buffer address */
#define	octet_tcc	octet_ir.word		/* transmit character count */

/* bits in octet_csr */
#define	DMZ_TRDY	0100000		/* transmit ready */
#define	DMZ_TIE		0040000		/* transmit interrupt enable */
#define	DMZ_NXM		0030000		/* non-existant memory */
#define	DMZ_LIN		0003400		/* transmit line number */
#define	DMZ_RRDY	0000200		/* receiver data available */
#define	DMZ_RIE		0000100		/* receiver interrupt enable */
#define	DMZ_RESET	0000040		/* master reset */
#define	DMZ_IAD		0000037		/* indirect address register */

#define	DMZ_IE		(DMZ_TIE | DMZ_RIE)	/* enable transmit and receive */

/* bits in octet_lprm (taken from dmfreg.h) */
#define	DMZ_6BT		0010		/* 6 bits per character */
#define	DMZ_7BT		0020		/* 7 bits per character */
#define	DMZ_8BT		0030		/* 8 bits per character */
#define	DMZ_PEN		0040		/* parity enable */
#define	DMZ_EPR		0100		/* even parity */
#define	DMZ_SCD		0200		/* stop code */
#define	DMZ_XTE		0170000		/* transmit rate */
#define	DMZ_RRT		0007400		/* receive rate */
#define	DMZ_LSL		0000007		/* line select */

/* baud rates */
#define	BR_50		000
#define	BR_75		001
#define	BR_110		002
#define	BR_134_5	003
#define	BR_150		004
#define	BR_300		005
#define	BR_600		006
#define	BR_1200		007
#define	BR_1800		010
#define	BR_2000		011
#define	BR_2400		012
#define	BR_3600		013
#define	BR_4800		014
#define	BR_7200		015
#define	BR_9600		016
#define	BR_19200	017

/* bits in octet_rb (taken from dmfreg.h) */
#define	DMZ_DSC		0004000		/* data set change */
#define	DMZ_PE		0010000		/* parity error */
#define	DMZ_FE		0020000		/* framing error */
#define	DMZ_DO		0040000		/* data overrun */
#define	DMZ_DV		0100000		/* data valid */
#define	DMZ_RL		0003400		/* line */
#define	DMZ_RD		0000377		/* data */
#define	DMZ_AT		0000377		/* alarm timeout */

D 2
/* bits in dmz_rms (taken from dmfreg.h) */
#define	DMZ_USR		0004		/* user modem signal (pin 25) */
#define	DMZ_SR		0010		/* secondary receive */
#define	DMZ_CTS		0020		/* clear to send */
#define	DMZ_CAR		0040		/* carrier detect */
#define	DMZ_RNG		0100		/* ring */
#define	DMZ_DSR		0200		/* data set ready */
E 2
I 2
/* bits in dmz_rmstsc */
#define	DMZ_TSC		0x00ff		/* transmit silo count */
#define	DMZ_USRR	0x0400		/* user modem signal (pin 25) */
#define	DMF_SR		0x0800		/* secondary receive */
#define	DMZ_CTS		0x1000		/* clear to send */
#define	DMZ_CAR		0x2000		/* carrier detect */
#define	DMZ_RNG		0x4000		/* ring */
#define	DMZ_DSR		0x8000		/* data set ready */
E 2

D 2
/* bits in dmz_tms (taken from dmfreg.h) */
#define	DMZ_USW		0001		/* user modem signal (pin 18) */
#define	DMZ_DTR		0002		/* data terminal ready */
#define	DMZ_RAT		0004		/* data signal rate select */
#define	DMZ_ST		0010		/* secondary transmit */
#define	DMZ_RTS		0020		/* request to send */
#define	DMZ_BRK		0040		/* pseudo break bit */
#define	DMZ_PMT		0200		/* preempt output */
E 2
I 2
/* bits in dmz_lctmr (tms half) */
#define	DMZ_USRW	0x0100		/* user modem signal (pin 18) */
#define	DMZ_DTR		0x0200		/* data terminal ready */
#define	DMZ_RATE	0x0400		/* data signal rate select */
#define	DMF_ST		0x0800		/* secondary transmit */
#define	DMZ_RTS		0x1000		/* request to send */
#define	DMZ_PREEMPT	0x8000		/* preempt output */
E 2

D 2
#define	DMZ_ON		(DMZ_DTR|DMZ_RTS)
#define	DMZ_OFF		0

/* bits in octet_lctmr */
E 2
I 2
/* bits in octet_lctmr (lc half) */
E 2
#define	DMZ_MIE		0040		/* modem interrupt enable */
#define	DMZ_FLS		0020		/* flush transmit silo */
D 2
#define	DMZ_RBK		0010		/* real break bit */
E 2
I 2
#define	DMZ_BRK		0010		/* send break bit */
E 2
#define	DMZ_RE		0004		/* receive enable */
#define	DMZ_AUT		0002		/* auto XON/XOFF */
#define	DMZ_TE		0001		/* transmit enable */
#define	DMZ_CF		0300		/* control function */

#define	DMZ_LCE		(DMZ_MIE|DMZ_RE|DMZ_TE)
I 2
#define	DMZ_ON		(DMZ_DTR|DMZ_RTS|DMZ_LCE)
#define	DMZ_OFF		DMZ_LCE
E 2

I 2

E 2
/* bits in octet_tcc */
#define	DMZ_HA		0140000		/* high address bits */

D 2
/* bits in dm lsr, copied from dmzreg.h, copied from dh.c */
#define	DM_USR		0001000		/* usr modem sig, not a real DM bit */
#define	DM_DSR		0000400		/* data set ready, not a real DM bit */
#define	DM_RNG		0000200		/* ring */
#define	DM_CAR		0000100		/* carrier detect */
#define	DM_CTS		0000040		/* clear to send */
#define	DM_SR		0000020		/* secondary receive */
#define	DM_ST		0000010		/* secondary transmit */
#define	DM_RTS		0000004		/* request to send */
#define	DM_DTR		0000002		/* data terminal ready */
#define	DM_LE		0000001		/* line enable */
E 2
I 2
/* bits added to dm lsr for DMGET/DMSET */
#define	DML_USR		0001000		/* usr modem sig, not a real DM bit */
#define	DML_DSR		0000400		/* data set ready, not a real DM bit */
E 2

#define	DMZ_SIZ		32		/* size of DMZ output silo (per line) */
E 4

D 2
#define	DMZ(a)		a/24
#define	OCTET(a)	(a%24)/8
#define	LINE(a)		(a%24)%8
E 2
I 2
#define	DMZ(a)		(a/24)
#define	OCTET(a)	((a%24)/8)
#define	LINE(a)		((a%24)%8)
E 2

#define	DMZ_NOC_MASK	03
#define	DMZ_INTERFACE	000
E 1
