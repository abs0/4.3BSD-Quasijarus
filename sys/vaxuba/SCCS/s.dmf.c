h00856
s 00001/00001/00629
d D 7.6 04/12/09 23:56:27 msokolov 47 46
c FNDELAY support
e
s 00001/00001/00629
d D 7.5 89/01/24 17:24:03 bostic 46 45
c typo in attach routines; bug report 4.3BSD-tahoe/sys/34
e
s 00133/00537/00497
d D 7.4 87/02/19 17:36:28 karels 45 44
c merge common code from dmf and dmz drivers
e
s 00020/00011/01014
d D 7.3 86/12/19 11:46:30 karels 44 43
c correct uba reallocation on reset
e
s 00004/00011/01021
d D 7.2 86/07/08 10:16:37 karels 43 41
c save dma count (for Emulex bug)
e
s 00003/00011/01021
d R 7.2 86/07/07 15:53:04 karels 42 41
c save dma count for Emulex
e
s 00001/00001/01031
d D 7.1 86/06/05 01:07:21 mckusick 41 40
c 4.3BSD release version
e
s 00002/00002/01030
d D 6.19 86/04/12 17:34:04 karels 40 39
c typos
e
s 00008/00003/01024
d D 6.18 86/04/12 14:12:36 karels 39 38
c remember dma count, as can't calculate correctly on Emulex;
c revert to "sticky" baudrate except for portselector
e
s 00081/00068/00946
d D 6.17 86/03/19 22:42:34 karels 38 37
c fixes to dmf lp from Keith Muller
e
s 00001/00000/01013
d D 6.16 86/03/13 11:24:24 karels 37 36
c more (obscure) lint
e
s 00019/00022/00994
d D 6.15 86/02/23 23:16:52 karels 36 35
c lint
e
s 00122/00132/00894
d D 6.14 86/02/21 12:02:01 karels 35 33
c lint and reformatting
e
s 00121/00131/00895
d R 6.14 86/02/20 19:52:16 karels 34 33
c lint and reformatting
e
s 00005/00004/01021
d D 6.13 86/02/17 22:58:58 karels 33 32
c correct uba allocation after reset
e
s 00002/00002/01023
d D 6.12 85/12/19 17:40:55 karels 32 30
c consistency: use dmflctms as 16-bit register
e
s 00001/00001/01024
d R 6.12 85/11/10 16:47:59 karels 31 30
c typo
e
s 00066/00075/00959
d D 6.11 85/11/08 19:54:36 karels 30 29
c autoconfiguration vector calculations redone (by bloom);
c share unibus resources between multiplexor types; set open parameters
c uniformly, 9600 default; move modem control to line discipline;
c remove lcr, tms byte definitions, as must write as word
e
s 00001/00001/01033
d D 6.10 85/09/17 18:34:21 eric 29 28
c facilities in syslog
e
s 00001/00001/01033
d D 6.9 85/08/13 05:09:51 lepreau 28 27
c add PASS8: pass all 8 bits of input
e
s 00007/00001/01027
d D 6.8 85/06/08 14:15:06 mckusick 27 26
c Add copyright
e
s 00015/00003/01013
d D 6.7 85/06/04 12:05:47 bloom 26 25
c cleanup carrier-drop code
e
s 00411/00107/00605
d D 6.6 85/06/04 12:03:51 bloom 25 24
c add dynamic use of dma and support for lineprinter interface
e
s 00002/00001/00710
d D 6.5 85/03/12 14:22:53 ralph 24 23
c change silo overflow printf's to log's.
e
s 00002/00001/00709
d D 6.4 84/12/20 15:55:02 bloom 23 22
c call param routine when ioctls change hardware configuration
e
s 00016/00016/00694
d D 6.3 84/08/30 11:43:34 bloom 22 21
c changes to includes.  no more ../h
e
s 00003/00002/00707
d D 6.2 84/02/16 12:49:18 karels 21 20
c replace MAXNUBA by NUBA
e
s 00000/00000/00709
d D 6.1 83/07/29 07:27:15 sam 20 19
c 4.2 distribution
e
s 00001/00001/00708
d D 4.19 83/05/27 13:52:03 sam 19 18
c lint
e
s 00002/00002/00707
d D 4.18 83/05/14 20:23:41 sam 18 17
c from steveg@tektronix.UUCP; even/odd parity remnant from dh
e
s 00016/00117/00693
d D 4.17 83/05/14 20:21:49 sam 17 16
c fixes from km@emory.UUCP to make modem control work (untested here)
e
s 00002/00001/00808
d D 4.16 82/12/17 12:01:38 sam 16 15
c sun merge
e
s 00004/00003/00805
d D 4.15 82/12/05 21:47:48 sam 15 14
c reorganized tty structuer
e
s 00002/00000/00806
d D 4.14 82/10/22 00:00:18 root 14 13
c lint
e
s 00003/00001/00803
d D 4.13 82/10/21 21:19:51 root 13 12
c lint
e
s 00011/00011/00793
d D 4.12 82/10/20 01:42:33 root 12 11
c lint
e
s 00001/00004/00803
d D 4.11 82/10/17 20:17:30 root 11 10
c lint
e
s 00016/00016/00791
d D 4.10 82/10/17 11:48:28 root 10 9
c ioctl/open return errors, not u.u_error; remove ubarelses (it is
c now done in uba.c); add open routines to some disk drivers
e
s 00001/00001/00806
d D 4.9 82/10/13 22:41:52 root 9 8
c l_write returns a value; pass it on
e
s 00003/00002/00804
d D 4.8 82/10/10 17:26:40 root 8 7
c header files for vax are in their place
e
s 00003/00002/00803
d D 4.7 82/08/22 21:17:21 root 7 6
c fully uio()'d
e
s 00004/00002/00801
d D 4.6 82/08/13 00:15:05 root 6 5
c changes for char dev uio'ing
e
s 00017/00021/00786
d D 4.5 82/08/01 19:24:37 sam 5 4
c new ioctl's
e
s 00001/00001/00806
d D 4.4 82/07/15 19:59:33 kre 4 3
c probe routines return size of unibus dev regs to reserve space
e
s 00028/00029/00779
d D 4.3 82/05/27 17:22:19 sam 3 2
c upgrade to current tty.h
e
s 00001/00005/00807
d D 4.2 82/05/27 16:01:19 sam 2 1
c purge mpx trash
e
s 00812/00000/00000
d D 4.1 82/05/26 15:16:01 sam 1 0
c date and time created 82/05/26 15:16:01 by sam
e
u
U
t
T
I 1
D 27
/*	%M%	%I%	%E%	*/
E 27
I 27
/*
D 41
 * Copyright (c) 1982 Regents of the University of California.
E 41
I 41
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 41
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 27

D 45
#include "dmf.h"
#if NDMF > 0
E 45
/*
 * DMF32 driver
 *
I 25
 *
E 25
 * TODO:
 *	test with modem
 *	load as much as possible into silo
D 25
 *	get correct numbers for receive silo parameter timeout
E 25
 *	use auto XON/XOFF
 *	test reset code
D 25
 *	test with more than one unit
 *	optimize for efficient DMA and dynamically
 *	  decide between silo and DMA mode
E 25
I 25
D 45
 ****************************
 * DMF32 line printer driver
 *
 * the line printer on dmfx is indicated by a minor device code of 128+x
 *
 * the flags field of the config file is interpreted like so:
 * bits		meaning
 * ----		-------
 * 0-7		soft carrier bits for ttys part of dmf32
 * 8-15		number of cols/line on the line printer
 *			if 0, 132 will be used.
 * 16-23	number of lines/page on the line printer
 *			if 0, 66 will be used.
D 38
 *
E 38
I 38
 * 24		if 1 DO NOT use the auto format mode of the
 *			line printer parallel port
E 45
E 38
E 25
 */
I 45
#include "dmf.h"
#if NDMF > 0

#ifndef NDMF_LP
#define	NDMF_LP	NDMF
#endif	NDMF_LP
E 45
I 16
#include "../machine/pte.h"

E 16
#include "bk.h"
I 21
#include "uba.h"
E 21
D 22
#include "../h/param.h"
#include "../h/conf.h"
#include "../h/dir.h"
#include "../h/user.h"
I 15
#include "../h/ioctl.h"
E 15
#include "../h/tty.h"
#include "../h/map.h"
D 16
#include "../h/pte.h"
E 16
#include "../h/buf.h"
#include "../h/vm.h"
D 8
#include "../h/ubareg.h"
#include "../h/ubavar.h"
E 8
#include "../h/bk.h"
#include "../h/clist.h"
D 2
#include "../h/mx.h"
E 2
#include "../h/file.h"
I 6
#include "../h/uio.h"
E 22
I 22
#include "param.h"
#include "conf.h"
#include "dir.h"
#include "user.h"
I 37
#include "proc.h"
E 37
#include "ioctl.h"
#include "tty.h"
#include "map.h"
#include "buf.h"
#include "vm.h"
#include "bkmac.h"
#include "clist.h"
#include "file.h"
#include "uio.h"
I 25
#include "kernel.h"
E 25
I 24
#include "syslog.h"
E 24
E 22
I 8

I 45
#include "dmx.h"
E 45
D 22
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
I 17
#include "../vaxuba/dmfreg.h"
E 22
I 22
#include "ubareg.h"
#include "ubavar.h"
I 45
#include "dmxreg.h"
E 45
#include "dmfreg.h"
I 45
#include "dmreg.h"
E 45
E 22
E 17
E 8
E 6

I 45
extern	int dmx_timeout;		/* silo timeout, in ms */
extern	char dmx_speeds[];
int	dmfstart();

E 45
/*
D 45
 * Definition of the driver for the auto-configuration program.
E 45
I 45
 * The clist space is mapped by one terminal driver onto each UNIBUS.
 * The identity of the board which allocated resources is recorded,
 * so the process may be repeated after UNIBUS resets.
 * The UBACVT macro converts a clist space address for unibus uban
 * into an i/o space address for the DMA routine.
E 45
 */
I 45
int	dmf_uballoc[NUBA];	/* which dmf (if any) allocated unibus map */
int	cbase[NUBA];		/* base address of clists in unibus map */

/*
 * Autoconfiguration and variables for DMF32
 */
E 45
int	dmfprobe(), dmfattach(), dmfrint(), dmfxint();
I 25
int	dmflint();
E 25
struct	uba_device *dmfinfo[NDMF];
u_short	dmfstd[] = { 0 };
struct	uba_driver dmfdriver =
	{ dmfprobe, 0, dmfattach, 0, dmfstd, "dmf", dmfinfo };

I 25
D 30
int	dmf_timeout = 50;		/* silo timeout, in ms */
E 30
I 30
D 45
int	dmf_timeout = 10;		/* silo timeout, in ms */
E 30
int	dmf_mindma = 4;			/* don't dma below this point */

E 25
/*
D 17
 * In this driver, "dmf" (unqualified) refers to the async portion
 * of the dmf32, "dmfc" to the combo portion, "dmfs" to the sync
 * portion, "dmfl" to the lp portion, and "dmfd" to the dr portion.
 */
struct dmfdevice
{
	short	dmfccsr0;		/* combo csr 0 */
	short	dmfccsr1;		/* combo csr 1 */
	short	dmfs[4];
	short	dmfcsr;			/* control-status register */
	short	dmflpr;			/* line parameter register */
	short	dmfrbuf;		/* receiver buffer (ro) */
	union {
		u_short	dmfirw;		/* indirect register word */
		u_char	dmfirc[2];	/*    "         "    bytes */
	} dmfun;
	short	dmfl[2];
	short	dmfd[4];
};

#define	dmfrsp	dmfrbuf		/* receive silo parameter register (wo) */
#define	dmftbuf	dmfun.dmfirc[0]	/* transmit buffer */
#define	dmftsc	dmfun.dmfirc[0]	/* transmit silo count */
#define	dmfrms	dmfun.dmfirc[1]	/* receive modem status */
#define	dmflcr	dmfun.dmfirc[0]	/* line control register */
#define	dmftms	dmfun.dmfirc[1]	/* transmit modem status */
#define	dmftba	dmfun.dmfirw	/* transmit buffer address */
#define	dmftcc	dmfun.dmfirw	/* transmit character count */

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
/* DEC manuals incorrectly say this bit causes generation of even parity. */
#define	OPAR	0100

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

/* bits in dmflcr */
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

/*
E 17
 * Local variables for the driver
 */
char	dmf_speeds[] =
	{ 0, 0, 1, 2, 3, 4, 0, 5, 6, 7, 010, 012, 014, 016, 017, 0 };

I 30
#ifndef	PORTSELECTOR
#define	ISPEED	B9600
#define	IFLAGS	(EVENP|ODDP|ECHO)
#else
#define	ISPEED	B4800
#define	IFLAGS	(EVENP|ODDP)
#endif

E 45
E 30
struct	tty dmf_tty[NDMF*8];
D 45
char	dmfsoftCAR[NDMF];
I 25

D 36
struct dmfl_softc
{
	unsigned dmfl_state; 		/* soft state bits */
	unsigned dmfl_info;		/* uba info */
	unsigned short dmfl_lines;	/* lines per page (66 def.) */
	unsigned short dmfl_cols; 	/* cols per line (132 def.) */
	char dmfl_buf[DMFL_BUFSIZ];
E 36
I 36
struct dmfl_softc {
	u_int	dmfl_state; 		/* soft state bits */
	int	dmfl_info;		/* uba info */
	u_short	dmfl_lines;		/* lines per page (66 def.) */
	u_short	dmfl_cols; 		/* cols per line (132 def.) */
I 38
	u_short	dmfl_format;		/* fflag for auto form feed */
E 38
	char	dmfl_buf[DMFL_BUFSIZ];
E 36
} dmfl_softc[NDMF];

/*
 * convert device number into DMF line printer unit number
 */
#define	DMFL_UNIT(d)	(minor(d)&0xF)	/* up to 16 DMFs */

#define ASLP 1		/* waiting for interrupt from dmf */
#define OPEN 2		/* line printer is open */
#define ERROR 4		/* error while printing, driver
			 refuses to do anything till closed */
I 38
#define MOREIO 8	/* more data for printer */
E 38

E 45
I 45
struct	dmx_softc dmf_softc[NDMF];
E 45
E 25
D 13
int	ndmf = NDMF*8;
E 13
I 13
#ifndef lint
int	ndmf = NDMF*8;			/* used by iostat */
#endif
E 13
D 45
int	dmfact;				/* mask of active dmf's */
int	dmfstart(), ttrstrt();
E 45

D 25
#ifdef DMFDMA
E 25
/*
D 44
 * The clist space is mapped by the driver onto each UNIBUS.
E 44
I 44
D 45
 * The clist space is mapped by one terminal driver onto each UNIBUS.
 * The identity of the board which allocated resources is recorded,
 * so the process may be repeated after UNIBUS resets.
E 44
 * The UBACVT macro converts a clist space address for unibus uban
 * into an i/o space address for the DMA routine.
 */
D 21
int	dmf_ubinfo[MAXNUBA];		/* info about allocated unibus map */
static int cbase[MAXNUBA];		/* base address in unibus map */
E 21
I 21
D 44
int	dmf_ubinfo[NUBA];		/* info about allocated unibus map */
D 30
static int cbase[NUBA];			/* base address in unibus map */
E 30
I 30
int	cbase[NUBA];			/* base address in unibus map */
E 44
I 44
int	dmf_uballoc[NUBA];	/* which dmf (if any) allocated unibus map */
int	cbase[NUBA];		/* base address of clists in unibus map */
E 44
E 30
E 21
#define	UBACVT(x, uban)		(cbase[uban] + ((x)-(char *)cfree))
D 25
#endif
E 25
I 25
char	dmf_dma[NDMF*8];
E 25

/*
E 45
 * Routine for configuration to set dmf interrupt.
 */
/*ARGSUSED*/
dmfprobe(reg, ctlr)
	caddr_t reg;
D 25
	int ctlr;
E 25
I 25
	struct uba_device *ctlr;
E 25
{
	register int br, cvec;		/* these are ``value-result'' */
	register struct dmfdevice *dmfaddr = (struct dmfdevice *)reg;
I 25
	register int i;
	register unsigned int a;
	static char *dmfdevs[]=
		{"parallel","printer","synch","asynch"};
	unsigned int dmfoptions;
I 30
	static int (*intrv[3])() = { (int (*)())0, (int (*)())0, (int (*)())0 };
E 30
E 25

#ifdef lint
	br = 0; cvec = br; br = cvec;
I 14
	dmfxint(0); dmfrint(0);
D 36
	dmfsrint(); dmfsxint(); dmfdaint(); dmfdbint(); dmflint();
E 36
I 36
	dmfsrint(); dmfsxint(); dmfdaint(); dmfdbint(); dmflint(0);
E 36
E 14
#endif
I 25
	/*
	 * Pick the usual size DMF vector here (don't decrement it here).
	 * grab configuration; note that the DMF32
	 * doesn't seem to put the right bits in this
	 * register until AFTER the interrupt vector is set.
	 */
E 25
	br = 0x15;
D 25
	cvec = (uba_hd[numuba].uh_lastiv -= 4*8);
	dmfaddr->dmfccsr0 = cvec >> 2;
E 25
I 25
	cvec = (uba_hd[numuba].uh_lastiv - 4*8);
D 30
	dmfaddr->dmfccsr0 = (cvec >> 2) ;
E 30
I 30
	dmfaddr->dmfccsr0 = (cvec >> 2);
E 30
	dmfoptions = dmfaddr->dmfccsr0 & DMFC_CONFMASK;

	/* catch a couple of special cases:  Able vmz/32n and vmz/lp	*/
	if (dmfoptions == DMFC_ASYNC) {
D 30
		/* Async portion only  -  vmz/32n */
		/* device dmf0 csr 0160400	vector dmfrint dmfxint  */
		cvec = (uba_hd[numuba].uh_lastiv -= 8);	/* only 8 bytes req'd */
		dmfaddr->dmfccsr0 = (cvec - 2*8) >> 2;	/* program 020 less   */
		printf("dmf%d: Able vmz32/n\n", ctlr->ui_unit);
E 30
I 30
		/* Async portion only */

		cvec = (uba_hd[numuba].uh_lastiv -= 8);
		dmfaddr->dmfccsr0 = (cvec - 2*8) >> 2;
		intrv[0] = ctlr->ui_intr[4];
		intrv[1] = ctlr->ui_intr[5];
		ctlr->ui_intr = intrv;
E 30
D 35
	}
	else if (dmfoptions == DMFC_LP) {
E 35
I 35
	} else if (dmfoptions == DMFC_LP) {
E 35
D 30
		/* LP portion only - vmz/lp */
		/* device dmf0 csr 0160400	vector dmflint */
E 30
I 30
		/* LP portion only */
E 30

D 30
		cvec = (uba_hd[numuba].uh_lastiv -= 8);	/* only 8 bytes req'd */
		dmfaddr->dmfccsr0 = (cvec - 3*8) >> 2;	/* program 030 less   */
		printf("dmf%d: Able vmz/lp\n", ctlr->ui_unit);
E 30
I 30
		cvec = (uba_hd[numuba].uh_lastiv -= 8);
		ctlr->ui_intr = &ctlr->ui_intr[6];
E 30
D 35
	}
I 30
	else if (dmfoptions == (DMFC_LP|DMFC_ASYNC)) {
E 35
I 35
	} else if (dmfoptions == (DMFC_LP|DMFC_ASYNC)) {
E 35
D 45
		/* LP ans Async portions only */
E 45
I 45
		/* LP and Async portions only */
E 45

		cvec = (uba_hd[numuba].uh_lastiv -= 2*8);
		ctlr->ui_intr = &ctlr->ui_intr[4];
D 35
	}
E 30
	else {
E 35
I 35
	} else {
E 35
D 30
		/* anything else we program like a dec dmf32	*/
		/* device dmf0 vector dmfsrint dmfsxint dmfdaint dmfdbint dmfrint dmfxint dmflint */
E 30
I 30
		/* All other configurations get everything */
E 30

		cvec = (uba_hd[numuba].uh_lastiv -= 4*8);
D 30
		dmfaddr->dmfccsr0 = (cvec >> 2) ;
		a = (dmfaddr->dmfccsr0>>12) & 0xf;
		printf("dmf%d:", ctlr->ui_unit);
		for(i=0;a != 0;++i,a >>= 1) {
			if(a&1)
				printf(" %s",dmfdevs[i]);
		}
		printf(".\n");
E 30
	}
I 30
	a = (dmfoptions >> 12) & 0xf;
	printf("dmf%d:", ctlr->ui_unit);
D 35
	for(i=0;a != 0;++i,a >>= 1) {
		if(a&1)
E 35
I 35
	for (i = 0; a != 0; ++i, a >>= 1) {
		if (a & 1)
E 35
			printf(" %s",dmfdevs[i]);
	}
	printf(".\n");
E 30

	if (dmfoptions & DMFC_LP)
D 40
		dmfaddr->dmfl[0] = DMFL_RESET;
E 40
I 40
		dmfaddr->dmfl_ctrl = DMFL_RESET;
E 40
E 25
D 35
	/* NEED TO SAVE IT SOMEWHERE FOR OTHER DEVICES */
E 35
D 4
	return (1);
E 4
I 4
	return (sizeof (struct dmfdevice));
E 4
}

/*
 * Routine called to attach a dmf.
 */
dmfattach(ui)
D 45
	struct uba_device *ui;
E 45
I 45
	register struct uba_device *ui;
E 45
{
I 25
D 45
	register int cols = (ui->ui_flags>>8) & 0xff;
	register int lines = (ui->ui_flags>>16) & 0xff;
E 45
I 45
	register struct dmx_softc *sc;
E 45
E 25

D 25
	dmfsoftCAR[ui->ui_unit] = ui->ui_flags;
E 25
I 25
D 45
	dmfsoftCAR[ui->ui_unit] = ui->ui_flags & 0xff;
D 39
	dmfl_softc[ui->ui_unit].dmfl_cols = cols==0?DMFL_DEFCOLS:cols;
	dmfl_softc[ui->ui_unit].dmfl_lines = lines==0?DMFL_DEFLINES:lines;
E 39
I 39
	dmfl_softc[ui->ui_unit].dmfl_cols = cols == 0 ? DMFL_DEFCOLS : cols;
	dmfl_softc[ui->ui_unit].dmfl_lines = lines == 0 ? DMFL_DEFLINES : lines;
E 39
I 38
 	if ((ui->ui_flags >> 24) & 0x1)
 		dmfl_softc[ui->ui_unit].dmfl_format = (2 << 8);
 	else
 		dmfl_softc[ui->ui_unit].dmfl_format = (2 << 8) | DMFL_FORMAT;
E 45
I 45
	sc = &dmf_softc[ui->ui_unit];
	sc->dmx_type = 'f';
	sc->dmx_unit = ui->ui_unit;
	sc->dmx_unit0 = 0;
	sc->dmx_ubanum = ui->ui_ubanum;
	sc->dmx_softCAR = ui->ui_flags & 0xff;
	sc->dmx_tty = &dmf_tty[ui->ui_unit * 8];
	sc->dmx_octet =
	    (struct dmx_octet *)&((struct dmfdevice *)ui->ui_addr)->dmfa;

E 45
E 38
I 33
	cbase[ui->ui_ubanum] = -1;
I 44
D 46
	dmf_uballoc[ui->ui_unit] = -1;
E 46
I 46
	dmf_uballoc[ui->ui_ubanum] = -1;
E 46
I 45
#if NDMF_LP > 0
	dmflattach(ui);
#endif NDMF_LP
E 45
E 44
E 33
E 25
}

D 45

E 45
/*
 * Open a DMF32 line, mapping the clist onto the uba if this
 * is the first dmf on this uba.  Turn on this dmf if this is
 * the first use of it.
 */
/*ARGSUSED*/
dmfopen(dev, flag)
	dev_t dev;
{
	register struct tty *tp;
D 45
	register int unit, dmf;
E 45
I 45
	register struct dmx_softc *sc;
	int unit, dmf;
E 45
	register struct dmfdevice *addr;
	register struct uba_device *ui;
	int s;

	unit = minor(dev);
I 25
D 35
	if(unit & 0200)
		return(dmflopen(dev,flag));
E 35
I 35
	if (unit & 0200)
		return (dmflopen(dev,flag));
E 35
E 25
	dmf = unit >> 3;
D 10
	if (unit >= NDMF*8 || (ui = dmfinfo[dmf])== 0 || ui->ui_alive == 0) {
		u.u_error = ENXIO;
		return;
	}
E 10
I 10
	if (unit >= NDMF*8 || (ui = dmfinfo[dmf])== 0 || ui->ui_alive == 0)
		return (ENXIO);
I 45

E 45
E 10
	tp = &dmf_tty[unit];
D 3
	if (tp->t_state&XCLUDE && u.u_uid!=0) {
E 3
I 3
D 10
	if (tp->t_state&TS_XCLUDE && u.u_uid!=0) {
E 3
		u.u_error = EBUSY;
		return;
	}
E 10
I 10
D 45
	if (tp->t_state&TS_XCLUDE && u.u_uid!=0)
		return (EBUSY);
E 45
I 45
	sc = &dmf_softc[dmf];
E 45
E 10
	addr = (struct dmfdevice *)ui->ui_addr;
D 45
	tp->t_addr = (caddr_t)addr;
E 45
I 45
	tp->t_addr = (caddr_t)(&addr->dmfa);
E 45
	tp->t_oproc = dmfstart;
D 3
	tp->t_iproc = NULL;
	tp->t_state |= WOPEN;
E 3
I 3
D 45
	tp->t_state |= TS_WOPEN;
E 45
I 45
	tp->t_dev = dev;			/* needed before dmxopen */

E 45
E 3
	/*
D 45
	 * While setting up state for this uba and this dmf,
E 45
I 45
	 * While setting up state for this uba,
E 45
	 * block uba resets which can clear the state.
	 */
D 25
	s = spl5();
#ifdef DMFDMA
E 25
I 25
D 45
	s = spltty();
E 45
I 45
	s = spl6();
E 45
E 25
D 30
	if (dmf_ubinfo[ui->ui_ubanum] == 0) {
E 30
I 30
D 33
	if (cbase[ui->ui_ubanum] == 0) {
E 33
I 33
	if (cbase[ui->ui_ubanum] == -1) {
E 33
E 30
D 44
		dmf_ubinfo[ui->ui_ubanum] =
		    uballoc(ui->ui_ubanum, (caddr_t)cfree,
			nclist*sizeof(struct cblock), 0);
D 33
		cbase[ui->ui_ubanum] = dmf_ubinfo[ui->ui_ubanum]&0x3ffff;
E 33
I 33
		cbase[ui->ui_ubanum] = UBAI_ADDR(dmf_ubinfo[ui->ui_ubanum]);
E 44
I 44
		dmf_uballoc[ui->ui_ubanum] = dmf;
		cbase[ui->ui_ubanum] = UBAI_ADDR(uballoc(ui->ui_ubanum,
		    (caddr_t)cfree, nclist*sizeof(struct cblock), 0));
E 44
E 33
	}
D 25
#endif
E 25
D 45
	if ((dmfact&(1<<dmf)) == 0) {
		addr->dmfcsr |= DMF_IE;
		dmfact |= (1<<dmf);
D 25
		addr->dmfrsp = 1;	/* DON'T KNOW WHAT TO SET IT TO YET */
E 25
I 25
		addr->dmfrsp = dmf_timeout;
E 25
	}
E 45
	splx(s);
D 45
	/*
D 38
	 * If this is first open, initialze tty state to default.
E 38
I 38
	 * If this is first open, initialize tty state to default.
E 38
	 */
D 3
	if ((tp->t_state&ISOPEN) == 0) {
E 3
I 3
	if ((tp->t_state&TS_ISOPEN) == 0) {
E 3
		ttychars(tp);
I 39
#ifndef PORTSELECTOR
E 39
D 30
		if (tp->t_ispeed == 0) {
			tp->t_ispeed = B300;
			tp->t_ospeed = B300;
			tp->t_flags = ODDP|EVENP|ECHO;
		}
E 30
I 30
D 38
		tp->t_ispeed = ISPEED;
		tp->t_ospeed = ISPEED;
		tp->t_flags = IFLAGS;
E 38
I 38
		if (tp->t_ispeed == 0) {
I 39
#else
			tp->t_state |= TS_HUPCLS;
#endif PORTSELECTOR
E 39
			tp->t_ispeed = ISPEED;
			tp->t_ospeed = ISPEED;
			tp->t_flags = IFLAGS;
I 39
#ifndef PORTSELECTOR
E 39
		}
I 39
#endif PORTSELECTOR
E 39
E 38
E 30
		dmfparam(unit);
	}
	/*
	 * Wait for carrier, then process line discipline specific open.
	 */
D 38
	if ((dmfmctl(dev, DMF_ON, DMSET) & (DMF_CAR<<8)) ||
	    (dmfsoftCAR[dmf] & (1<<(unit&07))))
D 3
		tp->t_state |= CARR_ON;
E 3
I 3
		tp->t_state |= TS_CARR_ON;
E 38
E 3
D 25
	s = spl5();
E 25
I 25
	s = spltty();
E 25
D 3
	while ((tp->t_state & CARR_ON) == 0) {
		tp->t_state |= WOPEN;
E 3
I 3
D 38
	while ((tp->t_state & TS_CARR_ON) == 0) {
E 38
I 38
	for (;;) {
		if ((dmfmctl(dev, DMF_ON, DMSET) & (DMF_CAR<<8)) ||
		    (dmfsoftCAR[dmf] & (1<<(unit&07))))
			tp->t_state |= TS_CARR_ON;
		if (tp->t_state & TS_CARR_ON)
			break;
E 38
		tp->t_state |= TS_WOPEN;
E 3
		sleep((caddr_t)&tp->t_rawq, TTIPRI);
	}
	splx(s);
D 10
	(*linesw[tp->t_line].l_open)(dev, tp);
E 10
I 10
	return ((*linesw[tp->t_line].l_open)(dev, tp));
E 45
I 45

D 47
	return (dmxopen(tp, sc));
E 47
I 47
	return (dmxopen(tp, sc, flag));
E 47
E 45
E 10
}

/*
 * Close a DMF32 line.
 */
/*ARGSUSED*/
dmfclose(dev, flag)
	dev_t dev;
	int flag;
{
D 45
	register struct tty *tp;
E 45
	register unit;

	unit = minor(dev);
I 25
D 35
	if(unit & 0200)
		return(dmflclose(dev,flag));
E 35
I 35
	if (unit & 0200) {
D 45
		dmflclose(dev,flag);
E 45
I 45
		dmflclose(dev, flag);
E 45
		return;
	}
E 35
D 45
		
E 25
	tp = &dmf_tty[unit];
	(*linesw[tp->t_line].l_close)(tp);
D 12
	dmfmctl(unit, DMF_BRK, DMBIC);
E 12
I 12
	(void) dmfmctl(unit, DMF_BRK, DMBIC);
E 12
D 3
	if (tp->t_state&HUPCLS || (tp->t_state&ISOPEN)==0)
E 3
I 3
	if (tp->t_state&TS_HUPCLS || (tp->t_state&TS_ISOPEN)==0)
E 3
D 12
		dmfmctl(unit, DMF_OFF, DMSET);
E 12
I 12
		(void) dmfmctl(unit, DMF_OFF, DMSET);
E 12
	ttyclose(tp);
E 45
I 45
	dmxclose(&dmf_tty[unit]);
E 45
}

D 6
dmfread(dev)
E 6
I 6
dmfread(dev, uio)
E 6
	dev_t dev;
I 6
	struct uio *uio;
E 6
{
	register struct tty *tp;

I 25
D 35
	if(minor(dev)&0200)
E 35
I 35
	if (minor(dev) & 0200)
E 35
		return(ENXIO);
E 25
	tp = &dmf_tty[minor(dev)];
D 6
	(*linesw[tp->t_line].l_read)(tp);
E 6
I 6
	return ((*linesw[tp->t_line].l_read)(tp, uio));
E 6
}

D 7
dmfwrite(dev)
E 7
I 7
dmfwrite(dev, uio)
E 7
	dev_t dev;
I 7
	struct uio *uio;
E 7
{
	register struct tty *tp;

I 25
D 35
	if(minor(dev)&0200)
		return(dmflwrite(dev,uio));
E 35
I 35
	if (minor(dev) & 0200)
		return (dmflwrite(dev,uio));
E 35
E 25
	tp = &dmf_tty[minor(dev)];
D 7
	(*linesw[tp->t_line].l_write)(tp);
E 7
I 7
D 9
	(*linesw[tp->t_line].l_write)(tp, uio);
E 9
I 9
	return ((*linesw[tp->t_line].l_write)(tp, uio));
E 9
E 7
}

/*
 * DMF32 receiver interrupt.
 */
dmfrint(dmf)
	int dmf;
{
D 25
	register struct tty *tp;
E 25
D 45
	register c;
I 35
	register struct tty *tp;
E 35
	register struct dmfdevice *addr;
	register struct tty *tp0;
D 25
	register struct uba_device *ui;
E 25
I 25
D 35
	register dev;
E 35
	int unit;
E 25
D 17
	int overrun = 0;
E 17
I 17
D 30
	int overrun = 0, s;
E 30
I 30
	int overrun = 0;
I 35
	register struct uba_device *ui;
E 45
I 45
	struct uba_device *ui;
E 45
E 35
E 30
E 17

D 25
	ui = dmfinfo[dmf];
	if (ui == 0 || ui->ui_alive == 0)
		return;
	addr = (struct dmfdevice *)ui->ui_addr;
	tp0 = &dmf_tty[dmf<<3];
E 25
I 25
D 35
	{
		register struct uba_device *ui;

		ui = dmfinfo[dmf];
		if (ui == 0 || ui->ui_alive == 0)
			return;
		addr = (struct dmfdevice *)ui->ui_addr;
	}
E 35
I 35
	ui = dmfinfo[dmf];
	if (ui == 0 || ui->ui_alive == 0)
		return;
D 45
	addr = (struct dmfdevice *)ui->ui_addr;
E 35
	tp0 = &dmf_tty[dmf * 8];
E 25
	/*
	 * Loop fetching characters from the silo for this
	 * dmf until there are no more in the silo.
	 */
	while ((c = addr->dmfrbuf) < 0) {
D 25
		tp = tp0 + ((c>>8)&07);
E 25
I 25
D 35
		register struct tty *tp;
E 35

		unit = (c >> 8) & 07;
		tp = tp0 + unit;
D 35
		dev = unit + dmf * 8;
E 35
E 25
		if (c & DMF_DSC) {
I 17
D 25
			s = spl5();
E 17
			addr->dmfcsr = DMF_IE | DMFIR_TBUF | ((c>>8)&07);
E 25
I 25
D 30
			s = spltty();
E 30
			addr->dmfcsr = DMF_IE | DMFIR_TBUF | unit;
E 25
D 30
			if (addr->dmfrms & DMF_CAR) {
D 3
				if ((tp->t_state & CARR_ON) == 0) {
E 3
I 3
				if ((tp->t_state & TS_CARR_ON) == 0) {
E 3
					wakeup((caddr_t)&tp->t_rawq);
D 3
					tp->t_state |= CARR_ON;
E 3
I 3
					tp->t_state |= TS_CARR_ON;
I 26
				} else if ((tp->t_flags & MDMBUF) &&
				    (tp->t_state & TS_TTSTOP)) {
					tp->t_state &= ~TS_TTSTOP;
					ttstart(tp);
E 26
E 3
				}
D 26
			} else {
D 3
				if (tp->t_state & CARR_ON) {
E 3
I 3
				if (tp->t_state & TS_CARR_ON) {
E 26
I 26
			} else if ((tp->t_state & TS_WOPEN) == 0 &&
			    tp->t_flags & MDMBUF) {
			    	if ((tp->t_state & TS_TTSTOP) == 0) {
					tp->t_state |= TS_TTSTOP;
					dmfstop(tp, 0);
				}
			} else if ((tp->t_state & TS_CARR_ON) &&
			    (tp->t_flags & NOHANG) == 0 &&
			    (dmfsoftCAR[dmf] & (1<<unit)) == 0) {
				if (tp->t_state&TS_ISOPEN) {
E 26
E 3
					gsignal(tp->t_pgrp, SIGHUP);
					gsignal(tp->t_pgrp, SIGCONT);
					addr->dmfcsr = DMF_IE | DMFIR_LCR |
D 25
						((c>>8)&07);
E 25
I 25
						unit;
E 25
					addr->dmftms = 0;
D 19
					flushtty(tp, FREAD|FWRITE);
E 19
I 19
					ttyflush(tp, FREAD|FWRITE);
E 19
				}
D 3
				tp->t_state &= ~CARR_ON;
E 3
I 3
				tp->t_state &= ~TS_CARR_ON;
E 30
I 30
			if (addr->dmfrms & DMF_CAR)
				(void)(*linesw[tp->t_line].l_modem)(tp, 1);
D 35
			else if ((dmfsoftCAR[dmf] & (1<<unit)) == 0 &&
E 35
I 35
			else if ((dmfsoftCAR[dmf] & (1 << unit)) == 0 &&
E 35
			    (*linesw[tp->t_line].l_modem)(tp, 0) == 0) {
				addr->dmfcsr = DMF_IE | DMFIR_LCR | unit;
				addr->dmflctms = DMFLCR_ENA;
E 30
E 3
			}
I 17
D 30
			splx(s);
E 30
E 17
			continue;
		}
D 3
		if ((tp->t_state&ISOPEN)==0) {
E 3
I 3
D 35
		if ((tp->t_state&TS_ISOPEN)==0) {
E 35
I 35
		if ((tp->t_state&TS_ISOPEN) == 0) {
E 35
E 3
D 30
			wakeup((caddr_t)tp);
			continue;
E 30
I 30
			wakeup((caddr_t)&tp->t_rawq);
#ifdef PORTSELECTOR
D 35
			if ((tp->t_state&TS_WOPEN) == 0)
E 35
I 35
			if ((tp->t_state & TS_WOPEN) == 0)
E 35
#endif
				continue;
E 30
		}
D 25
		if (c & DMF_PE)
			if ((tp->t_flags&(EVENP|ODDP))==EVENP
			 || (tp->t_flags&(EVENP|ODDP))==ODDP )
				continue;
		if ((c & DMF_DO) && overrun == 0) {
D 24
			printf("dmf%d: silo overflow\n", dmf);
E 24
I 24
			log(KERN_RECOV, "dmf%d: silo overflow\n", dmf);
E 24
			overrun = 1;
E 25
I 25
D 26
		if(c & (DMF_PE|DMF_DO|DMF_FE)) {
E 26
I 26
		if (c & (DMF_PE|DMF_DO|DMF_FE)) {
E 26
			if (c & DMF_PE)
D 35
				if ((tp->t_flags&(EVENP|ODDP))==EVENP
			 	|| (tp->t_flags&(EVENP|ODDP))==ODDP )
E 35
I 35
				if ((tp->t_flags & (EVENP|ODDP)) == EVENP
			 	|| (tp->t_flags & (EVENP|ODDP)) == ODDP)
E 35
					continue;
			if ((c & DMF_DO) && overrun == 0) {
D 29
				log(KERN_RECOV, "dmf%d: silo overflow\n", dmf);
E 29
I 29
				log(LOG_WARNING, "dmf%d: silo overflow\n", dmf);
E 29
				overrun = 1;
			}
			if (c & DMF_FE)
				/*
			 	* At framing error (break) generate
			 	* a null (in raw mode, for getty), or a
			 	* interrupt (in cooked/cbreak mode).
			 	*/
D 35
				if (tp->t_flags&RAW)
E 35
I 35
				if (tp->t_flags & RAW)
E 35
					c = 0;
				else
					c = tp->t_intrc;
E 25
		}
D 25
		if (c & DMF_FE)
			/*
			 * At framing error (break) generate
			 * a null (in raw mode, for getty), or a
			 * interrupt (in cooked/cbreak mode).
			 */
			if (tp->t_flags&RAW)
				c = 0;
			else
D 15
				c = tun.t_intrc;
E 15
I 15
				c = tp->t_intrc;
E 25
E 15
#if NBK > 0
		if (tp->t_line == NETLDISC) {
			c &= 0177;
			BKINPUT(c, tp);
		} else
#endif
			(*linesw[tp->t_line].l_rint)(c, tp);
	}
E 45
I 45
	dmxrint(&dmf_softc[dmf]);
E 45
}

/*
 * Ioctl for DMF32.
 */
D 45
/*ARGSUSED*/
E 45
D 5
dmfioctl(dev, cmd, addr, flag)
E 5
I 5
dmfioctl(dev, cmd, data, flag)
E 5
	dev_t dev;
D 5
	caddr_t addr;
E 5
I 5
	caddr_t data;
E 5
{
D 45
	register struct tty *tp;
	register int unit = minor(dev);
D 11
	register int dmf = unit >> 3;
	register struct device *dmfaddr;
E 11
I 10
	int error;
E 45
I 45
	int unit = minor(dev);
E 45
E 10
D 5
	int temp;
E 5
 
I 25
D 35
	if(unit & 0200)
E 35
I 35
	if (unit & 0200)
E 35
		return (ENOTTY);
E 25
D 45
	tp = &dmf_tty[unit];
D 5
	cmd = (*linesw[tp->t_line].l_ioctl)(tp, cmd, addr);
E 5
I 5
D 10
	cmd = (*linesw[tp->t_line].l_ioctl)(tp, cmd, data, flag);
E 5
	if (cmd == 0)
		return;
D 5
	if (ttioctl(tp, cmd, addr, flag)) {
		if (cmd==TIOCSETP || cmd==TIOCSETN)
E 5
I 5
	if (ttioctl(tp, cmd, data, flag)) {
E 10
I 10
	error = (*linesw[tp->t_line].l_ioctl)(tp, cmd, data, flag);
	if (error >= 0)
		return (error);
	error = ttioctl(tp, cmd, data, flag);
	if (error >= 0) {
E 10
D 23
		if (cmd == TIOCSETP || cmd == TIOCSETN)
E 23
I 23
		if (cmd == TIOCSETP || cmd == TIOCSETN || cmd == TIOCLBIS ||
		    cmd == TIOCLBIC || cmd == TIOCLSET)
E 23
E 5
			dmfparam(unit);
D 10
	} else switch(cmd) {
E 10
I 10
		return (error);
	}
	switch (cmd) {
E 10

	case TIOCSBRK:
D 12
		dmfmctl(dev, DMF_BRK, DMBIS);
E 12
I 12
		(void) dmfmctl(dev, DMF_BRK, DMBIS);
E 12
		break;
I 5

E 5
	case TIOCCBRK:
D 12
		dmfmctl(dev, DMF_BRK, DMBIC);
E 12
I 12
		(void) dmfmctl(dev, DMF_BRK, DMBIC);
E 12
		break;
I 5

E 5
	case TIOCSDTR:
D 12
		dmfmctl(dev, DMF_DTR|DMF_RTS, DMBIS);
E 12
I 12
		(void) dmfmctl(dev, DMF_DTR|DMF_RTS, DMBIS);
E 12
		break;
I 5

E 5
	case TIOCCDTR:
D 12
		dmfmctl(dev, DMF_DTR|DMF_RTS, DMBIC);
E 12
I 12
		(void) dmfmctl(dev, DMF_DTR|DMF_RTS, DMBIC);
E 12
		break;
I 5

E 5
	case TIOCMSET:
D 5
		if (copyin(addr, (caddr_t) &temp, sizeof(temp)))
			u.u_error = EFAULT;
		else
			dmfmctl(dev, dmtodmf(temp), DMSET);
E 5
I 5
D 12
		dmfmctl(dev, dmtodmf(*(int *)data), DMSET);
E 12
I 12
		(void) dmfmctl(dev, dmtodmf(*(int *)data), DMSET);
E 12
E 5
		break;
I 5

E 5
	case TIOCMBIS:
D 5
		if (copyin(addr, (caddr_t) &temp, sizeof(temp)))
			u.u_error = EFAULT;
		else
			dmfmctl(dev, dmtodmf(temp), DMBIS);
E 5
I 5
D 12
		dmfmctl(dev, dmtodmf(*(int *)data), DMBIS);
E 12
I 12
		(void) dmfmctl(dev, dmtodmf(*(int *)data), DMBIS);
E 12
E 5
		break;
I 5

E 5
	case TIOCMBIC:
D 5
		if (copyin(addr, (caddr_t) &temp, sizeof(temp)))
			u.u_error = EFAULT;
		else
			dmfmctl(dev, dmtodmf(temp), DMBIC);
E 5
I 5
D 12
		dmfmctl(dev, dmtodmf(*(int *)data), DMBIC);
E 12
I 12
		(void) dmfmctl(dev, dmtodmf(*(int *)data), DMBIC);
E 12
E 5
		break;
I 5

E 5
	case TIOCMGET:
D 5
		temp = dmftodm(dmfmctl(dev, 0, DMGET));
		if (copyout((caddr_t) &temp, addr, sizeof(temp)))
			u.u_error = EFAULT;
E 5
I 5
		*(int *)data = dmftodm(dmfmctl(dev, 0, DMGET));
E 5
		break;
I 5

E 5
	default:
D 10
		u.u_error = ENOTTY;
E 10
I 10
		return (ENOTTY);
E 10
	}
I 10
	return (0);
E 45
I 45
	return (dmxioctl(&dmf_tty[unit], cmd, data, flag));
E 45
E 10
}

D 45
dmtodmf(bits)
	register int bits;
{
	register int b;

	b = bits & 012;
	if (bits & DML_ST) b |= DMF_RATE;
	if (bits & DML_RTS) b |= DMF_RTS;
	if (bits & DML_USR) b |= DMF_USRW;
	return(b);
}

dmftodm(bits)
	register int bits;
{
	register int b;

	b = (bits & 012) | ((bits >> 7) & 0760) | DML_LE;
	if (bits & DMF_USRR) b |= DML_USR;
	if (bits & DMF_RTS) b |= DML_RTS;
	return(b);
}
 

E 45
/*
D 45
 * Set parameters from open or stty into the DMF hardware
 * registers.
 */
dmfparam(unit)
	register int unit;
{
	register struct tty *tp;
	register struct dmfdevice *addr;
	register int lpar, lcr;
	int s;

	tp = &dmf_tty[unit];
	addr = (struct dmfdevice *)tp->t_addr;
	/*
	 * Block interrupts so parameters will be set
	 * before the line interrupts.
	 */
D 25
	s = spl5();
E 25
I 25
	s = spltty();
E 25
	addr->dmfcsr = (unit&07) | DMFIR_LCR | DMF_IE;
	if ((tp->t_ispeed)==0) {
D 3
		tp->t_state |= HUPCLS;
E 3
I 3
		tp->t_state |= TS_HUPCLS;
E 3
D 12
		dmfmctl(unit, DMF_OFF, DMSET);
E 12
I 12
		(void) dmfmctl(unit, DMF_OFF, DMSET);
I 30
		splx(s);
E 30
E 12
		return;
	}
	lpar = (dmf_speeds[tp->t_ospeed]<<12) | (dmf_speeds[tp->t_ispeed]<<8);
	lcr = DMFLCR_ENA;
	if ((tp->t_ispeed) == B134)
		lpar |= BITS6|PENABLE;
D 15
	else if ((tp->t_flags&RAW) || (tp->t_local&LLITOUT))
E 15
I 15
D 28
	else if (tp->t_flags & (RAW|LITOUT))
E 28
I 28
	else if (tp->t_flags & (RAW|LITOUT|PASS8))
E 28
E 15
		lpar |= BITS8;
	else {
		lpar |= BITS7|PENABLE;
		/* CHECK FOR XON/XOFF AND SET lcr |= DMF_AUTOX; */
	}
D 18
	if ((tp->t_flags&EVENP) == 0)
		lpar |= OPAR;
E 18
I 18
	if (tp->t_flags&EVENP)
		lpar |= EPAR;
E 18
	if ((tp->t_ospeed) == B110)
		lpar |= TWOSB;
	lpar |= (unit&07);
	addr->dmflpr = lpar;
D 17
	addr->dmflcr = lcr;
E 17
I 17
D 32
	SETLCR(addr, lcr);
E 32
I 32
	addr->dmflctms = (addr->dmflctms &~ 0xff) | lcr;
E 32
E 17
	splx(s);
}

/*
E 45
 * DMF32 transmitter interrupt.
 * Restart the idle line.
 */
dmfxint(dmf)
	int dmf;
{
I 25
D 35
	int u = dmf * 8;
	struct tty *tp0 = &dmf_tty[u];
E 35
I 35
D 45
	int unit0 = dmf * 8;
	struct tty *tp0 = &dmf_tty[unit0];
E 35
E 25
	register struct tty *tp;
	register struct dmfdevice *addr;
	register struct uba_device *ui;
D 25
	register int unit, t;
#ifdef DMFDMA
E 25
I 25
	register int t;
E 25
	short cntr;
E 45
I 17
D 25
	int s;
E 17
#endif
E 25

D 45
	ui = dmfinfo[dmf];
	addr = (struct dmfdevice *)ui->ui_addr;
	while ((t = addr->dmfcsr) & DMF_TI) {
D 25
		unit = dmf*8 + ((t>>8)&07);
		tp = &dmf_tty[unit];
D 3
		tp->t_state &= ~BUSY;
E 3
I 3
		tp->t_state &= ~TS_BUSY;
E 3
		if (t & DMF_NXM) {
			printf("dmf%d: NXM line %d\n", dmf, unit&7);
E 25
I 25
		if (t & DMF_NXM)
E 25
			/* SHOULD RESTART OR SOMETHING... */
D 25
		}
E 25
I 25
			printf("dmf%d: NXM line %d\n", dmf, t >> 8 & 7);
		t = t >> 8 & 7;
		tp = tp0 + t;
		tp->t_state &= ~TS_BUSY;
E 25
D 3
		if (tp->t_state&FLUSH)
			tp->t_state &= ~FLUSH;
E 3
I 3
		if (tp->t_state&TS_FLUSH)
			tp->t_state &= ~TS_FLUSH;
E 3
D 25
#ifdef DMFDMA
		else {
I 17
			s = spl5();
E 17
			addr->dmfcsr = DMFIR_TBUF | DMF_IE | (unit&07);
			if (addr->dmftsc == 0) {
				/*
				 * Do arithmetic in a short to make up
				 * for lost 16&17 bits.
				 */
				addr->dmfcsr = DMFIR_TBA | DMF_IE | (unit&07);
				cntr = addr->dmftba -
				    UBACVT(tp->t_outq.c_cf, ui->ui_ubanum);
				ndflush(&tp->t_outq, (int)cntr);
			}
I 17
			splx(s);
E 25
I 25
D 35
		else if (dmf_dma[u + t]) {
E 35
I 35
D 43
		else if (dmf_dma[unit0 + t]) {
E 35
			/*
			 * Do arithmetic in a short to make up
			 * for lost 16&17 bits.
			 */
			addr->dmfcsr = DMFIR_TBA | DMF_IE | t;
			cntr = addr->dmftba -
			    UBACVT(tp->t_outq.c_cf, ui->ui_ubanum);
			ndflush(&tp->t_outq, (int)cntr);
E 25
E 17
		}
E 43
I 43
		else if (dmf_dma[unit0 + t])
			ndflush(&tp->t_outq, (int)dmf_dma[unit0 + t]);
		dmf_dma[unit0 + t] = 0;
E 43
D 25
#endif
E 25
		if (tp->t_line)
			(*linesw[tp->t_line].l_start)(tp);
		else
			dmfstart(tp);
	}
E 45
I 45
	dmxxint(&dmf_softc[dmf]);
E 45
}

/*
D 45
 * Start (restart) transmission on the given DMF32 line.
E 45
I 45
 * Start (restart) transmission on the given line.
E 45
 */
dmfstart(tp)
D 45
	register struct tty *tp;
E 45
I 45
	struct tty *tp;
E 45
{
D 45
	register struct dmfdevice *addr;
D 11
	register int car, dmf, unit, nch;
E 11
I 11
	register int unit, nch;
E 11
	int s;
I 25
	register int dmf;
E 45
E 25

D 45
	unit = minor(tp->t_dev);
I 25
	dmf = unit >> 3;
E 25
D 11
	dmf = unit >> 3;
E 11
	unit &= 07;
	addr = (struct dmfdevice *)tp->t_addr;

	/*
	 * Must hold interrupts in following code to prevent
	 * state of the tp from changing.
	 */
D 25
	s = spl5();
E 25
I 25
	s = spltty();
E 25
	/*
	 * If it's currently active, or delaying, no need to do anything.
	 */
D 3
	if (tp->t_state&(TIMEOUT|BUSY|TTSTOP))
E 3
I 3
	if (tp->t_state&(TS_TIMEOUT|TS_BUSY|TS_TTSTOP))
E 3
		goto out;
	/*
	 * If there are still characters in the silo,
	 * just reenable the transmitter.
	 */
	addr->dmfcsr = DMF_IE | DMFIR_TBUF | unit;
	if (addr->dmftsc) {
		addr->dmfcsr = DMF_IE | DMFIR_LCR | unit;
D 17
		addr->dmflcr |= DMF_TE;
E 17
I 17
D 30
		SETLCR(addr, addr->dmflcr|DMF_TE);
E 30
I 30
		addr->dmflctms = addr->dmflctms | DMF_TE;
E 30
E 17
D 3
		tp->t_state |= BUSY;
E 3
I 3
		tp->t_state |= TS_BUSY;
E 3
		goto out;
	}
	/*
	 * If there are sleepers, and output has drained below low
	 * water mark, wake up the sleepers.
	 */
D 3
	if ((tp->t_state&ASLEEP) && tp->t_outq.c_cc<=TTLOWAT(tp)) {
		tp->t_state &= ~ASLEEP;
E 3
I 3
D 25
	if ((tp->t_state&TS_ASLEEP) && tp->t_outq.c_cc<=TTLOWAT(tp)) {
		tp->t_state &= ~TS_ASLEEP;
E 3
D 2
		if (tp->t_chan)
			mcstart(tp->t_chan, (caddr_t)&tp->t_outq);
		else
			wakeup((caddr_t)&tp->t_outq);
E 2
I 2
		wakeup((caddr_t)&tp->t_outq);
E 25
I 25
	if (tp->t_outq.c_cc<=TTLOWAT(tp)) {
		if (tp->t_state&TS_ASLEEP) {
			tp->t_state &= ~TS_ASLEEP;
			wakeup((caddr_t)&tp->t_outq);
		}
		if (tp->t_wsel) {
			selwakeup(tp->t_wsel, tp->t_state & TS_WCOLL);
			tp->t_wsel = 0;
			tp->t_state &= ~TS_WCOLL;
		}
E 25
E 2
	}
	/*
	 * Now restart transmission unless the output queue is
	 * empty.
	 */
	if (tp->t_outq.c_cc == 0)
		goto out;
D 15
	if (tp->t_flags&RAW || tp->t_local&LLITOUT)
E 15
I 15
	if (tp->t_flags & (RAW|LITOUT))
E 15
		nch = ndqb(&tp->t_outq, 0);
	else {
D 25
		nch = ndqb(&tp->t_outq, 0200);
		/*
		 * If first thing on queue is a delay process it.
		 */
		if (nch == 0) {
E 25
I 25
		if ((nch = ndqb(&tp->t_outq, 0200)) == 0) {
			/*
		 	* If first thing on queue is a delay process it.
		 	*/
E 25
			nch = getc(&tp->t_outq);
			timeout(ttrstrt, (caddr_t)tp, (nch&0x7f)+6);
D 3
			tp->t_state |= TIMEOUT;
E 3
I 3
			tp->t_state |= TS_TIMEOUT;
E 3
			goto out;
		}
	}
	/*
	 * If characters to transmit, restart transmission.
	 */
D 25
	if (nch) {
#ifdef DMFDMA
E 25
I 25
	if (nch >= dmf_mindma) {
		register car;

D 43
		dmf_dma[minor(tp->t_dev)] = 1;
E 43
I 43
		dmf_dma[minor(tp->t_dev)] = nch;
E 43
E 25
		addr->dmfcsr = DMF_IE | DMFIR_LCR | unit;
D 17
		addr->dmflcr |= DMF_TE;
E 17
I 17
D 30
		SETLCR(addr, addr->dmflcr|DMF_TE);
E 30
I 30
		addr->dmflctms = addr->dmflctms | DMF_TE;
E 30
E 17
		car = UBACVT(tp->t_outq.c_cf, dmfinfo[dmf]->ui_ubanum);
		addr->dmfcsr = DMF_IE | DMFIR_TBA | unit;
		addr->dmftba = car;
D 25
		addr->dmftcc = ((car>>2)&0xc000) | nch;
#else
E 25
I 25
		addr->dmftcc = ((car >> 2) & 0xc000) | nch;
		tp->t_state |= TS_BUSY;
	} else if (nch) {
E 25
		register char *cp = tp->t_outq.c_cf;
		register int i;

I 25
		dmf_dma[minor(tp->t_dev)] = 0;
E 25
		nch = MIN(nch, DMF_SILOCNT);
		addr->dmfcsr = DMF_IE | DMFIR_LCR | unit;
D 17
		addr->dmflcr |= DMF_TE;
E 17
I 17
D 30
		SETLCR(addr, addr->dmflcr|DMF_TE);
E 30
I 30
		addr->dmflctms = addr->dmflctms | DMF_TE;
E 30
E 17
		addr->dmfcsr = DMF_IE | DMFIR_TBUF | unit;
		for (i = 0; i < nch; i++)
			addr->dmftbuf = *cp++;
		ndflush(&tp->t_outq, nch);
D 25
#endif
E 25
D 3
		tp->t_state |= BUSY;
E 3
I 3
		tp->t_state |= TS_BUSY;
E 3
	}
out:
	splx(s);
E 45
I 45
	dmxstart(tp, &dmf_softc[minor(tp->t_dev) >> 3]);
E 45
}

/*
 * Stop output on a line, e.g. for ^S/^Q or output flush.
 */
D 45
/*ARGSUSED*/
E 45
dmfstop(tp, flag)
D 45
	register struct tty *tp;
E 45
I 45
	struct tty *tp;
E 45
{
D 45
	register struct dmfdevice *addr;
D 25
	register int unit, s;
E 25
I 25
	register unit = minor(tp->t_dev) & 7;
	int s;
E 45
E 25

D 45
	addr = (struct dmfdevice *)tp->t_addr;
	/*
	 * Block input/output interrupts while messing with state.
	 */
D 25
	s = spl5();
D 3
	if (tp->t_state & BUSY) {
E 3
I 3
	if (tp->t_state & TS_BUSY) {
E 3
		/*
		 * Device is transmitting; stop output
		 * by selecting the line and disabling
		 * the transmitter.  If this is a flush
		 * request then flush the output silo,
		 * otherwise we will pick up where we
		 * left off by enabling the transmitter.
		 */
		unit = minor(tp->t_dev);
		addr->dmfcsr = DMFIR_LCR | (unit&07) | DMF_IE;
D 17
		addr->dmflcr &= ~DMF_TE;
E 17
I 17
		SETLCR(addr, addr->dmflcr &~ DMF_TE);
E 17
D 3
		if ((tp->t_state&TTSTOP)==0) {
			tp->t_state |= FLUSH;
E 3
I 3
		if ((tp->t_state&TS_TTSTOP)==0) {
			tp->t_state |= TS_FLUSH;
E 3
D 17
			addr->dmflcr |= DMF_FLUSH;
E 17
I 17
			SETLCR(addr, addr->dmflcr|DMF_FLUSH);
E 17
		} else
E 25
I 25
	s = spltty();
	if (flag) {
		addr->dmfcsr = DMF_IE | DMFIR_TBUF | unit;
		if (addr->dmftsc) {
			/*
			 * Flush regardless of whether we're transmitting
			 * (TS_BUSY), if the silo contains untransmitted
			 * characters.
			 */
			addr->dmfcsr = DMFIR_LCR | unit | DMF_IE;
D 30
			SETLCR(addr, addr->dmflcr | DMF_TE | DMF_FLUSH);
E 30
I 30
			addr->dmflctms = addr->dmflctms | DMF_TE | DMF_FLUSH;
E 30
			/* this will interrupt so let dmfxint handle the rest */
			tp->t_state |= TS_FLUSH|TS_BUSY;
		}
	} else {
		if (tp->t_state & TS_BUSY) {
			/*
			 * Stop transmission by disabling
			 * the transmitter.  We'll pick up where we
			 * left off by reenabling in dmfstart.
			 */
			addr->dmfcsr = DMFIR_LCR | unit | DMF_IE;
D 30
			SETLCR(addr, addr->dmflcr &~ DMF_TE);
E 30
I 30
			addr->dmflctms = addr->dmflctms &~ DMF_TE;
E 30
			/* no interrupt here */
E 25
D 3
			tp->t_state &= ~BUSY;
E 3
I 3
			tp->t_state &= ~TS_BUSY;
I 25
		}
E 25
E 3
	}
	splx(s);
E 45
I 45
	dmxstop(tp, &dmf_softc[minor(tp->t_dev) >> 3], flag);
E 45
}

/*
D 45
 * DMF32 modem control
 */
dmfmctl(dev, bits, how)
	dev_t dev;
	int bits, how;
{
	register struct dmfdevice *dmfaddr;
	register int unit, mbits, lcr;
	int s;

	unit = minor(dev);
	dmfaddr = (struct dmfdevice *)(dmf_tty[unit].t_addr);
	unit &= 07;
D 25
	s = spl5();
E 25
I 25
	s = spltty();
E 25
	dmfaddr->dmfcsr = DMF_IE | DMFIR_TBUF | unit;
	mbits = dmfaddr->dmfrms << 8;
	dmfaddr->dmfcsr = DMF_IE | DMFIR_LCR | unit;
D 30
	mbits |= dmfaddr->dmftms;
	lcr = dmfaddr->dmflcr;
E 30
I 30
D 32
	lcr = dmfaddr->dmflcmts;
E 32
I 32
	lcr = dmfaddr->dmflctms;
E 32
	mbits |= (lcr & 0xff00) >> 8;
E 30
	switch (how) {
	case DMSET:
D 17
		mbits = bits;
E 17
I 17
		mbits = (mbits &0xff00) | bits;
E 17
		break;

	case DMBIS:
		mbits |= bits;
		break;

	case DMBIC:
		mbits &= ~bits;
		break;

	case DMGET:
		(void) splx(s);
		return(mbits);
	}
D 17
	dmfaddr->dmftms = mbits&037;
E 17
	if (mbits & DMF_BRK)
		lcr |= DMF_RBRK;
	else
		lcr &= ~DMF_RBRK;
D 17
	dmfaddr->dmflcr = lcr;
E 17
I 17
D 30
	lcr = ((mbits & 037) << 8) | (lcr & 0xff);
	dmfaddr->dmfun.dmfirw = lcr;
E 30
I 30
	dmfaddr->dmflctms = ((mbits & 037) << 8) | (lcr & 0xff);
E 30
E 17
	(void) splx(s);
	return(mbits);
}

/*
E 45
 * Reset state of driver if UBA reset was necessary.
 * Reset the csr, lpr, and lcr registers on open lines, and
 * restart transmitters.
 */
dmfreset(uban)
	int uban;
{
D 45
	register int dmf, unit;
E 45
I 45
	register int dmf;
E 45
	register struct tty *tp;
	register struct uba_device *ui;
	register struct dmfdevice *addr;
	int i;

D 25
#ifdef DMFDMA
E 25
D 30
	if (dmf_ubinfo[uban] == 0)
		return;
D 10
	ubarelse(uban, &dmf_ubinfo[uban]);
E 10
	dmf_ubinfo[uban] = uballoc(uban, (caddr_t)cfree,
	    nclist*sizeof (struct cblock), 0);
	cbase[uban] = dmf_ubinfo[uban]&0x3ffff;
E 30
D 25
#endif
E 25
	for (dmf = 0; dmf < NDMF; dmf++) {
		ui = dmfinfo[dmf];
		if (ui == 0 || ui->ui_alive == 0 || ui->ui_ubanum != uban)
			continue;
		printf(" dmf%d", dmf);
I 30
D 33
		if (cbase[uban] == 0) {
E 33
I 33
D 44
		if (dmf_ubinfo[uban]) {
E 33
			dmf_ubinfo[uban] = uballoc(uban, (caddr_t)cfree,
			    nclist*sizeof (struct cblock), 0);
D 33
			cbase[uban] = dmf_ubinfo[uban]&0x3ffff;
E 33
I 33
			cbase[uban] = UBAI_ADDR(dmf_ubinfo[uban]);
E 44
I 44
		if (dmf_uballoc[uban] == dmf) {
			int info;

			info = uballoc(uban, (caddr_t)cfree,
			    nclist * sizeof(struct cblock), UBA_CANTWAIT);
			if (info)
				cbase[uban] = UBAI_ADDR(info);
			else {
				printf(" [can't get uba map]");
				cbase[uban] = -1;
			}
E 44
E 33
		}
E 30
		addr = (struct dmfdevice *)ui->ui_addr;
D 45
		addr->dmfcsr = DMF_IE;
D 25
		addr->dmfrsp = 1;
E 25
I 25
		addr->dmfrsp = dmf_timeout;
E 25
		unit = dmf * 8;
		for (i = 0; i < 8; i++) {
			tp = &dmf_tty[unit];
E 45
I 45
		addr->dmfa.csr = DMF_IE;
		addr->dmfa.rsp = dmx_timeout;
		tp = &dmf_tty[dmf * 8];
		for (i = 0; i < 8; i++, tp++) {
E 45
D 3
			if (tp->t_state & (ISOPEN|WOPEN)) {
E 3
I 3
			if (tp->t_state & (TS_ISOPEN|TS_WOPEN)) {
E 3
D 45
				dmfparam(unit);
D 12
				dmfmctl(unit, DMF_ON, DMSET);
E 12
I 12
				(void) dmfmctl(unit, DMF_ON, DMSET);
E 45
I 45
				dmxparam(tp);
				(void) dmxmctl(tp, DMF_ON, DMSET);
E 45
E 12
D 3
				tp->t_state &= ~BUSY;
E 3
I 3
				tp->t_state &= ~TS_BUSY;
E 3
				dmfstart(tp);
			}
D 45
			unit++;
E 45
		}
I 45
#if NDMF_LP > 0
		dmflint(dmf);
#endif
E 45
	}
}

I 45
#if NDMF_LP > 0
E 45
I 38
D 39
#if NDMF > 0
E 39
E 38
I 25
D 35
/* dmflopen -- open the line printer port on a dmf32
 *
E 35
I 35
/*
I 45
 * DMF32 line printer driver
 *
 * the line printer on dmfx is indicated by a minor device code of 128+x
 *
 * the flags field of the config file is interpreted like so:
 * bits		meaning
 * ----		-------
 * 0-7		soft carrier bits for ttys part of dmf32
 * 8-15		number of cols/line on the line printer
 *			if 0, 132 will be used.
 * 16-23	number of lines/page on the line printer
 *			if 0, 66 will be used.
 * 24		if 1 DO NOT use the auto format mode of the
 *			line printer parallel port
 */

struct dmfl_softc {
	u_int	dmfl_state; 		/* soft state bits */
	int	dmfl_info;		/* uba info */
	u_short	dmfl_lines;		/* lines per page (66 def.) */
	u_short	dmfl_cols; 		/* cols per line (132 def.) */
	u_short	dmfl_format;		/* fflag for auto form feed */
	char	dmfl_buf[DMFL_BUFSIZ];
} dmfl_softc[NDMF];

/*
 * convert device number into DMF line printer unit number
 */
#define	DMFL_UNIT(d)	(minor(d) & 0xf)	/* up to 16 DMFs */

#define ASLP 1		/* waiting for interrupt from dmf */
#define OPEN 2		/* line printer is open */
#define ERROR 4		/* error while printing, driver
			 refuses to do anything till closed */
#define MOREIO 8	/* more data for printer */

/*
 * Attach printer portion of dmf.
 */
dmflattach(ui)
	register struct uba_device *ui;
{
	register int unit = ui->ui_unit;
	register int cols = (ui->ui_flags>>8) & 0xff;
	register int lines = (ui->ui_flags>>16) & 0xff;
	register struct dmfl_softc *sc;

	sc = &dmfl_softc[unit];
	sc->dmfl_cols = cols == 0 ? DMFL_DEFCOLS : cols;
	sc->dmfl_lines = lines == 0 ? DMFL_DEFLINES : lines;
 	if ((ui->ui_flags >> 24) & 0x1)
 		sc->dmfl_format = (2 << 8);
 	else
 		sc->dmfl_format = (2 << 8) | DMFL_FORMAT;
}

/*
E 45
 * dmflopen -- open the line printer port on a dmf32
E 35
 */
D 35
dmflopen(dev,flag)
dev_t dev;
int flag;
E 35
I 35
/* ARGSUSED */
dmflopen(dev, flag)
	dev_t dev;
	int flag;
E 35
{
	register int dmf;
	register struct dmfl_softc *sc;
	register struct uba_device *ui;
	register struct dmfdevice *addr;

D 35

	dmf = DMFL_UNIT(dev) ;
	if(((sc= &dmfl_softc[dmf])->dmfl_state & OPEN) ||
E 35
I 35
	dmf = DMFL_UNIT(dev);
D 38
	if (((sc= &dmfl_softc[dmf])->dmfl_state & OPEN) ||
E 35
		((ui=dmfinfo[dmf]) == 0) || ui->ui_alive == 0)
			return(ENXIO);
E 38
I 38
	if (dmf >= NDMF || (ui = dmfinfo[dmf]) == 0 || ui->ui_alive == 0)
		return (ENXIO);
	sc = &dmfl_softc[dmf];
	if (sc->dmfl_state & OPEN)
		return (EBUSY);
E 38
	addr = (struct dmfdevice *)ui->ui_addr;
D 35
	if((addr->dmfl[0] & DMFL_OFFLINE))
	{
E 35
I 35
D 38
	if ((addr->dmfl[0] & DMFL_OFFLINE)) {
E 35
		/*printf("dmf: line printer offline/jammed\n");*/
E 38
I 38
	if (addr->dmfl_ctrl & DMFL_OFFLINE) {
#ifdef notdef
		log(LOG_WARNING, "dmf%d: line printer offline/jammed\n",
			dmf);
#endif
E 38
D 35
		return(EIO);
E 35
I 35
		return (EIO);
E 35
	}
D 35
	if((addr->dmfl[0]&DMFL_CONV))
	{
E 35
I 35
D 38
	if ((addr->dmfl[0] & DMFL_CONV)) {
E 35
		printf("dmf:line printer disconnected\n");
E 38
I 38
	if ((addr->dmfl_ctrl & DMFL_CONV)) {
		log(LOG_WARNING, "dmf%d: line printer disconnected\n", dmf);
E 38
D 35
		return(EIO);
E 35
I 35
		return (EIO);
E 35
	}

D 38
	addr->dmfl[0] = 0;
E 38
I 38
	addr->dmfl_ctrl = 0;
E 38
	sc->dmfl_state |= OPEN;
D 35
	return 0;
E 35
I 35
	return (0);
E 35
}

D 35
dmflclose(dev,flag)
dev_t dev;
int flag;
E 35
I 35
/* ARGSUSED */
dmflclose(dev, flag)
	dev_t dev;
	int flag;
E 35
{
D 38
	register int dmf= DMFL_UNIT(dev);
E 38
I 38
	register int dmf = DMFL_UNIT(dev);
E 38
	register struct dmfl_softc *sc = &dmfl_softc[dmf];
I 38
	register struct uba_device *ui = dmfinfo[dmf];
E 38

D 35
	dmflout(dev,"\f",1);
E 35
I 35
D 36
	dmflout(dev, "\f", 1);
E 36
I 36
D 38
	(void)dmflout(dev, "\f", 1);
E 38
E 36
E 35
	sc->dmfl_state = 0;
D 35
	if(sc->dmfl_info != 0)
E 35
I 35
	if (sc->dmfl_info != 0)
E 35
D 36
		ubarelse((struct dmfdevice *)(dmfinfo[dmf])->ui_ubanum,
E 36
I 36
D 38
		ubarelse((int)dmfinfo[dmf]->ui_ubanum,
E 36
			&(sc->dmfl_info));
E 38
I 38
		ubarelse((int)ui->ui_ubanum, &sc->dmfl_info);
E 38

D 35
	((struct dmfdevice *)(dmfinfo[dmf]->ui_addr))->dmfl[0]=0;
	return 0;
E 35
I 35
D 38
	((struct dmfdevice *)(dmfinfo[dmf]->ui_addr))->dmfl[0] = 0;
E 38
I 38
	((struct dmfdevice *)ui->ui_addr)->dmfl_ctrl = 0;
E 38
D 36
	return (0);
E 36
E 35
}

D 35
dmflwrite(dev,uio)
dev_t dev;
struct uio *uio;
E 35
I 35
dmflwrite(dev, uio)
	dev_t dev;
	struct uio *uio;
E 35
{
D 36
	register unsigned int n;
E 36
I 36
	register int n;
E 36
	register int error;
	register struct dmfl_softc *sc;

	sc = &dmfl_softc[DMFL_UNIT(dev)];
D 35
	if(sc->dmfl_state&ERROR) return(EIO);
	while(n=min(DMFL_BUFSIZ,(unsigned)uio->uio_resid))
	{
		if(error=uiomove(&sc->dmfl_buf[0],(int)n,
			UIO_WRITE,uio))
		{
E 35
I 35
D 38
	if (sc->dmfl_state&ERROR)
		return(EIO);
D 36
	while (n = min(DMFL_BUFSIZ, (unsigned)uio->uio_resid)) {
E 36
I 36
	while (n = MIN(DMFL_BUFSIZ, (unsigned)uio->uio_resid)) {
E 36
		if (error = uiomove(&sc->dmfl_buf[0], (int)n, UIO_WRITE, uio)) {
E 35
			printf("uio move error\n");
E 38
I 38
	if (sc->dmfl_state & ERROR)
		return (EIO);
	while (n = (unsigned)uio->uio_resid) {
		if (n > DMFL_BUFSIZ) {
			n = DMFL_BUFSIZ;
			sc->dmfl_state |= MOREIO;
		} else
			sc->dmfl_state &= ~MOREIO;
		if (error = uiomove(sc->dmfl_buf, (int)n, UIO_WRITE, uio))
E 38
D 35
			return(error);
E 35
I 35
			return (error);
E 35
D 38
		}
D 35
		if(error=dmflout(dev,&sc->dmfl_buf[0],n))
		{
			return(error);
		}
E 35
I 35
		if (error = dmflout(dev, &sc->dmfl_buf[0], n))
E 38
I 38
		if (error = dmflout(dev, sc->dmfl_buf, n))
E 38
			return (error);
E 35
	}
D 35
	return 0;
E 35
I 35
	return (0);
E 35
}


D 35
/* dmflout -- start io operation to dmf line printer
E 35
I 35
/*
 * dmflout -- start io operation to dmf line printer
E 35
 *		cp is addr of buf of n chars to be sent.
 *
 *	-- dmf will be put in formatted output mode, this will
 *		be selectable from an ioctl if the
 *		need ever arises.
 */
D 35
dmflout(dev,cp,n)
dev_t dev;
char *cp;
int n;
E 35
I 35
dmflout(dev, cp, n)
	dev_t dev;
	char *cp;
	int n;
E 35
{
	register struct dmfl_softc *sc;
	register int dmf;
	register struct uba_device *ui;
	register struct dmfdevice *d;
D 36
	register unsigned info;
	register unsigned i;
E 36
I 36
D 38
	int i;
E 38
I 38
	int s;
E 38
E 36

D 35
	dmf = DMFL_UNIT(dev) ;
	sc= &dmfl_softc[dmf];
	if(sc->dmfl_state&ERROR) return(EIO);
	ui= dmfinfo[dmf];
	/* allocate unibus resources, will be released when io
	 * operation is done
E 35
I 35
	dmf = DMFL_UNIT(dev);
	sc = &dmfl_softc[dmf];
	if (sc->dmfl_state & ERROR)
		return (EIO);
	ui = dmfinfo[dmf];
	/*
	 * allocate unibus resources, will be released when io
	 * operation is done.
E 35
	 */
D 35
	sc->dmfl_info=
	info=
		uballoc(ui->ui_ubanum,cp,n,0);
	d= (struct dmfdevice *)ui->ui_addr;
	d->dmfl[0] = (2<<8) | DMFL_FORMAT; /* indir reg 2 */
E 35
I 35
D 36
	sc->dmfl_info = info = uballoc(ui->ui_ubanum,cp,n,0);
E 36
I 36
D 38
	sc->dmfl_info = uballoc(ui->ui_ubanum,cp,n,0);
E 38
I 38
	if (sc->dmfl_info == 0)
		sc->dmfl_info = uballoc(ui->ui_ubanum, cp, n, 0);
E 38
E 36
	d = (struct dmfdevice *)ui->ui_addr;
D 38
	d->dmfl[0] = (2<<8) | DMFL_FORMAT;	/* indir reg 2 */
E 38
I 38
	d->dmfl_ctrl = sc->dmfl_format;		/* indir reg 2 */
E 38
E 35
	/* indir reg auto increments on r/w */
	/* SO DON'T CHANGE THE ORDER OF THIS CODE */
D 35
	d->dmfl[1] = 0; /* prefix chars & num */
	d->dmfl[1] = 0; /* suffix chars & num */
	d->dmfl[1] = info; 	/* dma lo 16 bits addr */
E 35
I 35
D 38
	d->dmfl[1] = 0;			/* prefix chars & num */
	d->dmfl[1] = 0;			/* suffix chars & num */
D 36
	d->dmfl[1] = info; 		/* dma lo 16 bits addr */
E 36
I 36
	d->dmfl[1] = sc->dmfl_info; 		/* dma lo 16 bits addr */
E 38
I 38
	d->dmfl_indrct = 0;			/* prefix chars & num */
	d->dmfl_indrct = 0;			/* suffix chars & num */
	d->dmfl_indrct = sc->dmfl_info; 	/* dma lo 16 bits addr */
	d->dmfl_indrct = -n;			/* number of chars */
E 38
E 36
E 35

D 38
	/* NOT DOCUMENTED !! */
	d->dmfl[1] = -n;		/* number of chars */
	/* ----------^-------- */

D 36
	d->dmfl[1] = ((info>>16)&3) /* dma hi 2 bits addr */
E 36
I 36
	d->dmfl[1] = ((sc->dmfl_info>>16)&3) /* dma hi 2 bits addr */
E 36
		| (1<<8) /* auto cr insert */
		| (1<<9) /* use real ff */
		| (1<<15); /* no u/l conversion */
	d->dmfl[1] = sc->dmfl_lines 	/* lines per page */
		| (sc->dmfl_cols<<8);	/* carriage width */
E 38
I 38
	d->dmfl_indrct = ((sc->dmfl_info>>16)&3) | DMFL_OPTIONS;
						/* dma hi 2 bits addr */
	d->dmfl_indrct = sc->dmfl_lines 	/* lines per page */
		| (sc->dmfl_cols<<8);		/* carriage width */
E 38
	sc->dmfl_state |= ASLP;
D 35
	i=spltty();
E 35
I 35
D 38
	i = spltty();
E 35
	d->dmfl[0] |= DMFL_PEN|DMFL_IE;
E 38
I 38
	s = spltty();
	d->dmfl_ctrl |= DMFL_PEN | DMFL_IE;
E 38
D 35
	while(sc->dmfl_state & ASLP)
	{
		sleep(&sc->dmfl_buf[0],(PZERO+8));
		while(sc->dmfl_state&ERROR)
		{
			timeout(dmflint,dmf,10*hz);
			sleep(&sc->dmfl_state,(PZERO+8));
E 35
I 35
	while (sc->dmfl_state & ASLP) {
D 38
		sleep(&sc->dmfl_buf[0], (PZERO+8));
E 38
I 38
		sleep(sc->dmfl_buf, PZERO + 8);
E 38
		while (sc->dmfl_state & ERROR) {
D 36
			timeout(dmflint, dmf, 10*hz);
			sleep(&sc->dmfl_state, (PZERO+8));
E 36
I 36
D 38
			timeout(dmflint, (caddr_t)dmf, 10*hz);
			sleep((caddr_t)&sc->dmfl_state, (PZERO+8));
E 38
I 38
			timeout(dmflint, (caddr_t)dmf, 10 * hz);
			sleep((caddr_t)&sc->dmfl_state, PZERO + 8);
E 38
E 36
E 35
		}
D 35
		/*if(sc->dmfl_state&ERROR) return (EIO);*/
E 35
I 35
D 38
		/*if (sc->dmfl_state&ERROR) return (EIO);*/
E 38
E 35
	}
D 38
	splx(i);
E 38
I 38
	splx(s);
E 38
D 35
	return(0);
E 35
I 35
	return (0);
E 35
}
D 35
/* dmflint -- handle an interrupt from the line printer part of the dmf32
 *
 */
E 35

I 35
/*
 * dmflint -- handle an interrupt from the line printer part of the dmf32
 */
E 35
dmflint(dmf)
D 35
int dmf;
E 35
I 35
	int dmf;
E 35
{
D 35

E 35
	register struct uba_device *ui;
	register struct dmfl_softc *sc;
	register struct dmfdevice *d;
I 38
	short dmfl_stats;
E 38

D 35
	ui= dmfinfo[dmf];
	sc= &dmfl_softc[dmf];
	d= (struct dmfdevice *)ui->ui_addr;
E 35
I 35
	ui = dmfinfo[dmf];
	sc = &dmfl_softc[dmf];
	d = (struct dmfdevice *)ui->ui_addr;
E 35

D 38
	d->dmfl[0] &= ~DMFL_IE;

E 38
I 38
	d->dmfl_ctrl &= ~DMFL_IE;
D 40
	dmfl_stats = d->dmf_ctrl;
E 40
I 40
	dmfl_stats = d->dmfl_ctrl;
E 40
E 38
D 35
	if(sc->dmfl_state&ERROR)
	{
E 35
I 35
	if (sc->dmfl_state & ERROR) {
E 35
D 38
		printf("dmfl: intr while in error state \n");
D 35
		if((d->dmfl[0]&DMFL_OFFLINE) == 0)
E 35
I 35
		if ((d->dmfl[0]&DMFL_OFFLINE) == 0)
E 38
I 38
		if ((dmfl_stats & DMFL_OFFLINE) == 0)
E 38
E 35
			sc->dmfl_state &= ~ERROR;
D 36
		wakeup(&sc->dmfl_state);
E 36
I 36
		wakeup((caddr_t)&sc->dmfl_state);
E 36
		return;
	}
D 35
	if(d->dmfl[0]&DMFL_DMAERR)
	{
E 35
I 35
D 38
	if (d->dmfl[0] & DMFL_DMAERR)
E 35
		printf("dmf:NXM\n");
D 35
	}
	if(d->dmfl[0]&DMFL_OFFLINE)
	{
E 35
I 35
	if (d->dmfl[0] & DMFL_OFFLINE) {
E 35
		printf("dmf:printer error\n");
E 38
I 38
	if (dmfl_stats & DMFL_DMAERR)
		log(LOG_WARNING, "dmf%d: NXM\n", dmf);
	if (dmfl_stats & DMFL_OFFLINE) {
		log(LOG_WARNING, "dmf%d: printer error\n", dmf);
E 38
		sc->dmfl_state |= ERROR;
	}
D 35
	if(d->dmfl[0]&DMFL_PDONE)
	{
E 35
I 35
D 38
	if (d->dmfl[0] & DMFL_PDONE) {
E 38
E 35
#ifdef notdef
D 35
		printf("bytes= %d\n",d->dmfl[1]);
		printf("lines= %d\n",d->dmfl[1]);
E 35
I 35
D 38
		printf("bytes= %d\n", d->dmfl[1]);
		printf("lines= %d\n", d->dmfl[1]);
E 35
#endif
E 38
I 38
	if (dmfl_stats & DMFL_PDONE) {
		printf("bytes= %d\n", d->dmfl_indrct);
		printf("lines= %d\n", d->dmfl_indrct);
E 38
	}
I 38
#endif
E 38
	sc->dmfl_state &= ~ASLP;
D 36
	wakeup(&sc->dmfl_buf[0]);
E 36
I 36
D 38
	wakeup((caddr_t)&sc->dmfl_buf[0]);
E 36
D 35
	if(sc->dmfl_info != 0)
		ubarelse(ui->ui_ubanum,&sc->dmfl_info);
E 35
I 35
	if (sc->dmfl_info != 0)
E 38
I 38
	wakeup((caddr_t)sc->dmfl_buf);
	if (sc->dmfl_info && (sc->dmfl_state & MOREIO) == 0)
E 38
		ubarelse(ui->ui_ubanum, &sc->dmfl_info);
E 35
D 38
	sc->dmfl_info = 0;
E 38
D 35

E 35
}
I 45
#endif NDMF_LP
E 45

E 25
/* stubs for interrupt routines for devices not yet supported */

D 35
dmfsrint() { printf("dmfsrint\n"); }
E 35
I 35
dmfsrint()
{
	printf("dmfsrint\n");
}
E 35

D 35
dmfsxint() { printf("dmfsxint\n"); }
E 35
I 35
dmfsxint()
{
	printf("dmfsxint\n");
}
E 35

D 35
dmfdaint() { printf("dmfdaint\n"); }
E 35
I 35
dmfdaint()
{
	printf("dmfdaint\n");
}
E 35

D 35
dmfdbint() { printf("dmfdbint\n"); }

D 25
dmflint() { printf("dmflint\n"); }
E 25
I 25

E 35
I 35
dmfdbint()
{
	printf("dmfdbint\n");
}
E 35
E 25
D 38
#endif
E 38
I 38
#endif NDMF
E 38
E 1
