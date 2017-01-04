h03776
s 00001/00001/00841
d D 7.1 86/06/05 01:23:00 mckusick 15 14
c 4.3BSD release version
e
s 00001/00001/00841
d D 6.4 85/11/22 06:39:51 tef 14 13
c standard list of device addresses must be null terminated.
e
s 00007/00001/00835
d D 6.3 85/06/08 14:29:36 mckusick 13 12
c Add copyright
e
s 00011/00011/00825
d D 6.2 84/08/29 20:11:53 bloom 12 11
c Change to includes.  No more ../h
e
s 00000/00000/00836
d D 6.1 83/07/29 07:30:40 sam 11 10
c 4.2 distribution
e
s 00018/00010/00818
d D 4.10 83/07/27 10:46:14 helge 10 9
c final touch to uuclose...
e
s 00112/00065/00716
d D 4.9 83/07/24 23:09:39 helge 9 8
c uuclose and watchdog rewritten, silenced 'read stalled', and major cleanup
e
s 00005/00003/00776
d D 4.8 83/07/07 11:39:48 sam 8 7
c silence noise
e
s 00037/00041/00742
d D 4.7 83/06/16 14:43:41 helge 7 6
c works?
e
s 00070/00079/00713
d D 4.6 83/06/11 19:44:32 helge 6 5
c first version that really works, pseudo DMA in locore.s
e
s 00297/00334/00495
d D 4.5 83/06/08 00:10:27 helge 5 4
c sort of works..... but not completed
e
s 00112/00108/00717
d D 4.4 83/06/01 09:19:15 helge 4 3
c works some times, crashes most of the time
e
s 00318/00270/00507
d D 4.3 83/05/08 20:11:24 helge 3 2
c rewritten, includes fixes from mike obrien, not tested
e
s 00396/00323/00381
d D 4.2 83/04/10 17:17:22 helge 2 1
c intermediate version
e
s 00704/00000/00000
d D 4.1 83/04/08 11:16:39 helge 1 0
c date and time created 83/04/08 11:16:39 by helge
e
u
U
t
T
I 1
D 2
/*	tu.c	4.13	83/02/10	*/
E 2
I 2
D 13
/*	%M%	%I%	%E%	*/
E 13
I 13
/*
D 15
 * Copyright (c) 1982 Regents of the University of California.
E 15
I 15
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 15
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 13
E 2

D 2
#if defined(VAX750) || defined(VAX730)
E 2
I 2
D 3
#include "uu->h"
E 3
I 3
#include "uu.h"
E 3
D 4
#if NDL > 0
E 4
I 4
#if NUU > 0
E 4
E 2
/*
D 2
 * TU58 DECtape II device driver
E 2
I 2
 * TU58 DECtape II/DL11 device driver
I 3
D 4
 * (based on a driver written by Mike Obrien @ RAND)
E 4
E 3
E 2
 *
I 4
D 5
 *  ******   Warning: untested  ******
 *
E 5
E 4
D 2
 * This driver controls the console TU58s on a VAX-11/750 or VAX-11/730.
 * It could be easily modified for a Unibus TU58.  The TU58
 * is treated as a block device (only).  Error detection and
E 2
I 2
D 7
 * The TU58 * is treated as a block device (only).  Error detection and
E 2
 * recovery is almost non-existant.  It is assumed that the
E 7
I 7
 * The TU58 is treated as a block device (only).  Error detection and
 * recovery is not very extensive, but sufficient to handle the most
D 9
 * common errors. It is assumed that the
E 7
 * TU58 will follow the RSP protocol exactly, very few protocol
D 2
 * errors are checked for.  It is assumed that the 750 uses standard
 * RSP while the 730 uses Modified RSP (MRSP).  At the time when 750's
 * are converted to MRSP (by replacing EPROMS in the TU58), the tests
 * based on MRSP can be removed.
E 2
I 2
 * errors are checked for.  
E 9
I 9
 * common errors. It is assumed that the TU58 will follow the RSP 
 * protocol exactly, very few protocol errors are checked for.  
 *
 * To reduce interrupt latency, `options UUDMA' should be specified 
 * in the config file to make sure the `pseudo-DMA' code in locore.s
 * will be compiled into the system. Otherwise overrun errors will 
 * occur frequently (these errors are not reported).
 *
 * TODO:
 *
 * - Add ioctl code to wind/rewind cassette
 *
E 9
E 2
 */
I 2

D 3
/* 
 * TODO:
 * -	Split the uu structure into a per controller 
 * 	part and a per drive part.
 */
E 3
I 3
#include "../machine/pte.h"
E 3

E 2
D 12
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/buf.h"
#include "../h/conf.h"
D 3
#include "../h/dir.h"
E 3
I 3
#include "../h/time.h"
E 3
D 2
#include "../h/user.h"
E 2
#include "../h/kernel.h"
I 2
#include "../h/errno.h"
D 7
#include "../h/uio.h"
E 7
D 3
#include "../h/user.h"
E 3
#include "../h/file.h"
E 12
I 12
#include "param.h"
#include "systm.h"
#include "buf.h"
#include "conf.h"
#include "time.h"
#include "kernel.h"
#include "errno.h"
#include "file.h"
E 12
E 2

#include "../vax/cpu.h"
D 3
#include "../vax/mtpr.h"
E 3
I 3
#include "../vax/nexus.h"
I 5
#include "../vax/rsp.h"
E 5

E 3
I 2
D 12
#include "../vaxuba/ubavar.h"
#include "../vaxuba/ubareg.h"
#include "../vaxuba/uureg.h"
E 12
I 12
#include "ubavar.h"
#include "ubareg.h"
#include "uureg.h"
E 12
E 2

D 2
#define	printd	if(tudebug) printf
E 2
I 2
D 3
#define	printd	if(uudebug) printf
E 3
I 3
D 5
#define	printd	if (uudebug) printf
E 3
E 2
#ifdef	printd
D 2
int	tudebug;	/* printd */
E 2
I 2
D 3
int	uudebug;	/* printd */
E 3
I 3
D 4
int	uudebug;		/* printd */
E 4
I 4
int	uudebug = 0;		/* printd */
E 4
E 3
E 2
#endif	printd

E 5
D 2
#define	NTU	((cpu == VAX_750) ? 1 : 2)
#define DNUM    01      /* mask for drive number (should match NTU) */
#if !defined(MRSP) || lint
E 2
I 2
D 3
#if	!defined(MRSP) || lint
E 2
#define	MRSP	(cpu != VAX_750)
#endif
E 3
#define	NTUBLK	512		/* number of blocks on a TU58 cassette */
D 2
#define WRV     02              /* bit in minor dev => write w. read verify */
#define NTUQ    2               /* # of blocks which can be queued up */
#define	TUIPL	((cpu == VAX_750) ? 0x17 : 0x14)
E 2
I 2
D 4
#define	WRV     02              /* bit in minor dev => write w. read verify */
E 4
I 4
#define	WRV     01              /* bit in minor dev => write w. read verify */
E 4
D 3
#define	NDPC	02		/* # drives per controller */
E 3
I 3
#define	NDPC	02		/* drives per controller */
D 4
#define	NUU	NDPC * NDL	/* number of drives */
#define	DNUM	01		/* mask for drive number */
E 4
I 4
#define	NUX	NDPC * NUU	/* number of drives */
E 4
D 9
#define	NTUQ	02		/* # of block which can be queued up */
E 9
I 9
#define	NUUQ	02		/* # of block which can be queued up */
E 9
I 4
#define	UMASK	01		/* unit number mask */
D 5
#define UUIPL	04		/* ipl level to use */
E 5
I 5
#define UUIPL	0x14		/* ipl level to use */
E 5
E 4
E 3
E 2

D 5
/*
D 2
 * Device register bits
 */
#define	READY	0200		/* transmitter ready */
#define	DONE	0200		/* receiver done */
#define	IE	0100		/* interrupt enable */
#define	BREAK	1		/* send break */

/*
E 2
 * Structure of a command packet
 */
struct packet {
	u_char	pk_flag;	/* indicates packet type (cmd, data, etc.) */
	u_char	pk_mcount;	/* length of packet (bytes) */
	u_char	pk_op;		/* operation to perform (read, write, etc.) */
	u_char	pk_mod;		/* modifier for op or returned status */
	u_char	pk_unit;	/* unit number */
	u_char	pk_sw;		/* switches */
	u_short	pk_seq;		/* sequence number, always zero */
	u_short	pk_count;	/* requested byte count for read or write */
	u_short	pk_block;	/* block number for read, write, or seek */
	u_short	pk_chksum;	/* checksum, by words with end around carry */
};

E 5
D 2
struct packet tucmd;		/* a command sent to the TU58 */
struct packet tudata;		/* a command or data returned from TU58 */
E 2
I 2
D 4
struct packet uucmd[NDL];	/* a command sent to the TU58 */
struct packet uudata[NDL];	/* a command or data returned from TU58 */
E 4
I 4
struct packet uucmd[NUU];	/* a command sent to the TU58 */
struct packet uudata[NUU];	/* a command or data returned from TU58 */
struct buf uitab[NUU];		/* buffer queue headers */
E 4
E 2

/*
D 2
 * State information
E 2
I 2
D 5
 * per controller state information
E 5
I 5
 * Driver soft carrier structure
E 5
E 2
 */
D 2
struct tu {
	u_char	*tu_rbptr;	/* pointer to buffer for read */
	int	tu_rcnt;	/* how much to read */
	u_char	*tu_wbptr;	/* pointer to buffer for write */
	int	tu_wcnt;	/* how much to write */
	int	tu_state;	/* current tu_state of tansfer operation */
	int	tu_flag;	/* read in progress flag */
	char	*tu_addr;	/* real buffer data address */
	int	tu_count;	/* real requested count */
	int	tu_serrs;	/* count of soft errors */
	int	tu_cerrs;	/* count of checksum errors */
	int	tu_herrs;	/* count of hard errors */
	char    tu_dopen[2];	/* drive is open */
} tu;
E 2
I 2
D 5
struct uu_ctlr {
	u_char	*uu_rbptr;	/* pointer to buffer for read */
	int	uu_rcnt;	/* how much to read */
	u_char	*uu_wbptr;	/* pointer to buffer for write */
	int	uu_wcnt;	/* how much to write */
	int	uu_state;	/* current uu_state of tansfer operation */
	int	uu_flag;	/* read in progress flag */
	char	*uu_addr;	/* real buffer data address */
	int	uu_count;	/* real requested count */
	int	uu_serrs;	/* count of soft errors */
	int	uu_cerrs;	/* count of checksum errors */
	int	uu_herrs;	/* count of hard errors */
	char    uu_dopen[NDPC];	/* drive is open */
D 4
} uu_ctlr[NDL];
E 4
I 4
} uu_ctlr[NUU];
E 5
I 5
struct uu_softc {
	u_char	*tu_rbptr;	/* pointer to buffer for read */
	int	tu_rcnt;	/* how much to read */
	u_char	*tu_wbptr;	/* pointer to buffer for write */
	int	tu_wcnt;	/* how much to write */
	int	tu_state;	/* current state of tansfer operation */
	int	tu_flag;	/* read in progress flag */
	char	*tu_addr;	/* real buffer data address */
	int	tu_count;	/* real requested count */
	int	tu_serrs;	/* count of soft errors */
	int	tu_cerrs;	/* count of checksum errors */
	int	tu_herrs;	/* count of hard errors */
	char    tu_dopen[2];	/* drive is open */
D 6
};
E 6
I 6
} uu_softc[NUU];
E 6
E 5
E 4
E 2

D 5
/*
D 2
 * States
E 2
I 2
 * controller states
E 2
 */
D 2
#define	TUS_INIT1	0	/* sending nulls */
#define	TUS_INIT2	1	/* sending inits */
#define	TUS_IDLE	2	/* initialized, no transfer in progress */
#define	TUS_SENDH	3	/* sending header */
#define	TUS_SENDD	4	/* sending data */
#define	TUS_SENDC	5	/* sending checksum */
#define	TUS_SENDR	6	/* sending read command packet */
#define	TUS_SENDW	7	/* sending write command packet */
#define	TUS_GETH	8	/* reading header */
#define	TUS_GETD	9	/* reading data */
#define	TUS_GETC	10	/* reading checksum */
#define	TUS_GET		11	/* reading an entire packet */
#define	TUS_WAIT	12	/* waiting for continue */
E 2
I 2
#define	UUS_INIT1	0	/* sending nulls */
#define	UUS_INIT2	1	/* sending inits */
#define	UUS_IDLE	2	/* initialized, no transfer in progress */
#define	UUS_SENDH	3	/* sending header */
#define	UUS_SENDD	4	/* sending data */
#define	UUS_SENDC	5	/* sending checksum */
#define	UUS_SENDR	6	/* sending read command packet */
#define	UUS_SENDW	7	/* sending write command packet */
#define	UUS_GETH	8	/* reading header */
#define	UUS_GETD	9	/* reading data */
#define	UUS_GETC	10	/* reading checksum */
#define	UUS_GET		11	/* reading an entire packet */
#define	UUS_WAIT	12	/* waiting for continue */
E 5
I 5
D 6
struct uu_softc uu_softc[NUU];
E 5
E 2

E 6
D 2
#define	TUS_NSTATES	13
char *tustates[TUS_NSTATES] = {
E 2
I 2
D 5
#define	UUS_NSTATES	13
char *uustates[UUS_NSTATES] = {
E 5
I 5
#if defined(VAX750) || defined(VAX730)
extern char *tustates[];
#else
char *tustates[TUS_NSTATES] = {
E 5
E 2
	"INIT1", "INIT2", "IDLE", "SENDH", "SENDD", "SENDC", "SENDR",
D 6
	"SENDW", "GETH", "GETD", "GETC", "GET", "WAIT"
E 6
I 6
	"SENDW", "GETH", "GETD", "GETC", "GET", "WAIT", "RCVERR", "CHKERR"
E 6
};
I 5
#endif
E 5
I 3

D 4
#define	UNIT(dev)	(minor(dev)&DNUM)
E 4
I 4
#define	UNIT(dev)	(minor(dev)>>1)
E 4
E 3
D 5
#define	printstate(state) \
D 2
	if ((state) < TUS_NSTATES) \
		printf("%s", tustates[(state)]); \
E 2
I 2
	if ((state) < UUS_NSTATES) \
		printf("%s", uustates[(state)]); \
E 2
	else \
		printf("%d", (state));
E 5

D 5
/*
 * Packet Flags
 */
#define	TUF_DATA	1		/* data packet */
#define	TUF_CMD		2		/* command packet */
#define	TUF_INITF	4		/* initialize */
#define	TUF_CONT	020		/* continue */
#define	TUF_XOFF	023		/* flow control */

/*
 * Op Codes
 */
I 2
#define	TUOP_NOOP	0		/* no operation */
E 2
#define	TUOP_INIT	1		/* initialize */
#define	TUOP_READ	2		/* read block */
#define	TUOP_WRITE	3		/* write block */
#define	TUOP_SEEK	5		/* seek to block */
D 2
#define TUOP_DIAGNOSE	7		/* run micro-diagnostics */
E 2
I 2
#define	TUOP_DIAGNOSE	7		/* run micro-diagnostics */
E 2
#define	TUOP_END	0100		/* end packet */

/*
 * Mod Flags
 */
#define TUMD_WRV        1               /* write with read verify */

/*
 * Switches
 */
D 3
#define	TUSW_MRSP	010		/* use Modified RSP */
E 3

E 5
D 2
u_char	tunull[2] = { 0, 0 };	/* nulls to send for initialization */
u_char	tuinit[2] = { TUF_INITF, TUF_INITF };	/* inits to send */
static char pcnt[2];            /* pee/vee counters */
int	tutimer = 0;
struct buf tutab;		/* I/O queue header */
E 2
I 2
D 7
u_char	uunull[2] = { 0, 0 };	/* nulls to send for initialization */
E 7
I 7
D 9
u_char	uunull[4] = { 0, 0, 0, 0 };	/* nulls to send for initialization */
E 9
I 9
u_char	uunull[2] = { 0, 0 };		/* nulls to send for initialization */
E 9
E 7
u_char	uuinit[2] = { TUF_INITF, TUF_INITF };	/* inits to send */
E 2

D 2
/*
 * Open the TU58
 */
E 2
I 2
struct	uba_device	*uudinfo[NUU];
D 4
struct	uba_ctlr	*uuminfo[NDL];
E 4

D 3
int uuprobe(), uuslave(), uuattach(), uurintr(), uuxintr(), uuwatch();
E 3
I 3
D 4
int uuprobe(), uuslave(), uuattach(), uudgo(), uurintr(), uuxintr(), uuwatch();
E 3
u_short uustd[] = { 0176500, 0 };
struct uba_driver dldriver =
D 3
    { uuprobe, uuslave, uuattach, uudgo, uustd, "uu", uudinfo, "dl", uuminfo };
E 3
I 3
    { uuprobe, uuslave, uuattach, uudgo, uustd, "uu", uudinfo, "uu", uuminfo };
E 4
I 4
int uuprobe(), uuattach(), uurintr(), uuxintr(), uuwatch();
D 14
u_short uustd[] = { 0176500 };
E 14
I 14
u_short uustd[] = { 0176500, 0 };
E 14
struct uba_driver uudriver =
    { uuprobe, 0, uuattach, 0, uustd, "uu", uudinfo };
E 4
E 3

int	uuwstart;
I 10
int	uuwake();
E 10
I 3
D 4
static char pcnt[2];			/* pee/vee counters */
E 4
I 4
D 5
static char pcnt[NUX];			/* pee/vee counters */
E 5
I 5
D 9
static char pcnt[NUX];			/* pee/vee counters, one per drive */
E 9
I 9
static char uu_pcnt[NUX];		/* pee/vee counters, one per drive */
E 9
E 5
E 4
E 3

E 2
/*ARGSUSED*/
D 2
tuopen(dev, flag)
E 2
I 2
uuprobe(reg)
	caddr_t reg;
E 2
{
D 2
	extern int tuwatch();
	register s;
E 2
I 2
	register int br, cvec;			/* value result */
	struct uudevice *uuaddr = (struct uudevice *)reg;
D 5
	int i;
E 5
E 2

#ifdef lint
D 2
	turintr(); tuwintr();
E 2
I 2
	br = 0; cvec = br; br = cvec;
	uurintr(0); uuxintr(0);
E 2
#endif
D 2
	if ((minor(dev)&DNUM) >= NTU || tu.tu_dopen[minor(dev)&DNUM])
E 2
I 2
D 4
	uuaddr->rcs = UUCS_INTR;
	uuaddr->tdb = TUF_INITF;
	DELAY(10000);
	i = uuaddr->rdb;
	uuaddr->rcs = 0;
E 4
I 4
	uuaddr->tcs = UUCS_INTR;
	DELAY(1000);
	uuaddr->tcs = 0;
	cvec -= 4;		/* since we are using the xmitter intrpt */
E 4
	return(sizeof (*uuaddr));
}

D 3
uuslave(ui, reg);
E 3
I 3
D 4
uuslave(ui, reg)
E 3
	struct uba_device *ui;
	caddr_t reg;
{
	return (ui->ui_slave == 0 || ui->ui_slave == 1);
}

/*ARGSUSED*/
E 4
uuattach(ui)
D 4
	struct uba_device *ui;
E 4
I 4
	register struct uba_device *ui;
E 4
{
D 3

E 3
I 3
D 4
	/* no local state to set up */
E 4
E 3
}

/*ARGSUSED1*/
uuopen(dev, flag)
	dev_t dev;
	int flag;	
{
	register struct uba_device *ui;
D 5
	register struct uu_ctlr *uuc;
E 5
I 5
D 6
	register struct tu *uuc;
E 6
I 6
	register struct uu_softc *uuc;
E 6
E 5
	register struct uudevice *uuaddr;
D 4
	register struct uba_ctlr *um;
E 4
D 3
	int ctlr, unit = minor(dev), s;
E 3
I 3
	int ctlr, unit = UNIT(dev), s;
E 3

D 4
	if (unit >= NUU || (ui = uudinfo[unit]) == 0 || ui->ui_alive == 0)
E 4
I 4
	ctlr = unit / NDPC;
	if (unit >= NUX || (ui = uudinfo[ctlr]) == 0 || ui->ui_alive == 0)
E 4
E 2
		return (ENXIO);
D 2
	if (tutimer == 0) {
		tutimer++;
		timeout(tuwatch, (caddr_t)0, hz);
	}
	tu.tu_dopen[minor(dev)&DNUM]++;
	s = splx(TUIPL);
E 2
I 2
D 4
	um = ui->ui_mi;
	ctlr = um->um_ctlr;
E 4
D 5
	uuc = &uu_ctlr[ctlr];
D 3
	if (uuc->uu_dopen[unit%NDPC])
E 3
I 3
D 4
	if (uuc->uu_dopen[unit&DNUM])
E 4
I 4
	if (uuc->uu_dopen[unit&UMASK])
E 5
I 5
	uuc = &uu_softc[ctlr];
	if (uuc->tu_dopen[unit&UMASK])
E 5
E 4
E 3
		return (EBUSY);
	if (uuwstart++ == 0)
		timeout(uuwatch, (caddr_t)0, hz);

D 3
	uuc->uu_dopen[unit%NDPC]++;
	uuaddr = (struct uudevice *)ui->ui_mi->um_addr;
E 3
I 3
D 4
	uuc->uu_dopen[unit&DNUM]++;
	uuaddr = (struct uudevice *)um->um_addr;
E 3
	s = spl5();
E 4
I 4
D 5
	uuc->uu_dopen[unit&UMASK]++;
E 5
I 5
	uuc->tu_dopen[unit&UMASK]++;
E 5
	uuaddr = (struct uudevice *)ui->ui_addr;
	s = splx(UUIPL);
E 4
E 2
	/*
I 6
	 * If the other device on this controller
D 9
	 * is already active, just return
E 9
I 9
	 * is already active, no need to initialize
E 9
	 */
	if (uuc->tu_dopen[0] && uuc->tu_dopen[1])
D 7
		return;
E 7
I 7
		goto ok;
E 7

	/*
E 6
D 2
	 * If the cassette's already initialized,
E 2
I 2
	 * If the unit already initialized,
E 2
	 * just enable interrupts and return.
	 */
D 2
	if (tu.tu_state == TUS_IDLE) {
		mtpr(CSRS, IE);
E 2
I 2
D 3
	if (uu->uu_state == TUS_IDLE) {
E 3
I 3
D 5
	if (uuc->uu_state == UUS_IDLE) {
E 5
I 5
	if (uuc->tu_state == TUS_IDLE) {
E 5
E 3
		uuaddr->rcs = UUCS_INTR;
E 2
D 4
		splx(s);
E 4
I 4
D 5
		(void) splx(s);
E 4
		return (0);
E 5
I 5
		goto ok;
E 5
	}

	/* 
	 * Must initialize, reset the cassette
	 * and wait for things to settle down.
	 */
D 2
	tureset();
	sleep((caddr_t)&tu, PZERO+1);
	tutab.b_active = NULL;
	if (tu.tu_state != TUS_IDLE) {
		u.u_error = ENXIO;
		tu.tu_state = TUS_INIT1;
		tu.tu_dopen[minor(dev)&DNUM] = 0;
		tu.tu_rcnt = tu.tu_wcnt = 0;
		mtpr(CSTS, 0);
		mtpr(CSRS, 0);
E 2
I 2
	uureset(ctlr);
	sleep((caddr_t)uuc, PZERO+1);
D 4
	um->um_tab.b_active = NULL;
E 4
I 4
	uitab[ctlr].b_active = NULL;
E 4
D 3
	if (uu->uu_state != TUS_IDLE) {
		uu->uu_state = TUS_INIT1;
		uu->uu_dopen[unit%NDPC] = 0;
		uu->uu_rcnt = uu->uu_wcnt = 0;
E 3
I 3
D 5
	if (uuc->uu_state != UUS_IDLE) {
		uuc->uu_state = UUS_INIT1;
D 4
		uuc->uu_dopen[unit&DNUM] = 0;
E 4
I 4
		uuc->uu_dopen[unit&UMASK] = 0;
E 4
		uuc->uu_rcnt = uuc->uu_wcnt = 0;
E 5
I 5
	if (uuc->tu_state != TUS_IDLE) {
		uuc->tu_state = TUS_INIT1;
		uuc->tu_dopen[unit&UMASK] = 0;
		uuc->tu_rcnt = uuc->tu_wcnt = 0;
E 5
E 3
		uuaddr->rcs = 0;
		uuaddr->tcs = 0;
		splx(s);
D 5
		return (ENXIO);
E 5
I 5
		return (EIO);
E 5
E 2
	}
I 5
ok:
E 5
	splx(s);
	return (0);
}

I 9
/*
 * Wait for all outstanding IO on this drive
 * complete, before closing. If both drives on
 * this controller are idle, mark the controller
 * `inactive'.
 */

E 9
D 2
/*
 * Close the TU58
 */
tuclose(dev)
E 2
I 2
uuclose(dev, flag)
	dev_t dev;
	int flag;
E 2
{
I 2
D 3
	register struct uba_ctlr *um = uudinfo[minor(dev)]->ui_mi;
	register struct uudevice *uuaddr;
E 3
I 3
D 4
	register struct uba_ctlr *um = uudinfo[UNIT(dev)]->ui_mi;
E 4
E 3
D 5
	register struct uu_ctlr *uuc;
E 5
I 5
D 6
	register struct tu *uuc;
E 6
I 6
D 9
	register struct uu_softc *uuc;
E 9
I 9
	int s, unit = UNIT(dev);
	register struct uu_softc *uuc = &uu_softc[unit/NDPC];
	struct buf *bp, *last = NULL;
	struct uudevice *uuaddr = (struct uudevice *)uudinfo[unit/NDPC]->ui_addr;
E 9
E 6
E 5
I 4
D 7
	int unit = UNIT(dev);
I 5
	int ctlr = unit/NDPC;
E 7
E 5
E 4
E 2

D 2
	if (tutab.b_active == 0) {
		mtpr(CSRS, 0);
		tutimer = 0;
E 2
I 2
D 3
	if (um->um_tab.b_active == 0) {
		uuaddr = (struct uudevice *)um->um_addr;
		uuaddr->rcs = 0;
		uuwstart--;
E 2
	}
E 3
I 3
D 5
	uuwstart--;
E 3
D 2
	if (tu.tu_serrs + tu.tu_cerrs + tu.tu_herrs != 0) {
E 2
I 2
D 4
	uuc = &uu_ctlr[um->um_ctlr];
E 4
I 4
	uuc = &uu_ctlr[unit%NDPC];
E 4
	if (uuc->uu_serrs + uuc->uu_cerrs + uuc->uu_herrs != 0) {
E 5
I 5
D 7
	uuc = &uu_softc[ctlr];
	if (uuc->tu_serrs + uuc->tu_cerrs + uuc->tu_herrs != 0) {
E 5
E 2
		/*
		 * A tu58 is like nothing ever seen before;
		 * I guess this is appropriate then...
		 */
		uprintf(
D 2
		   "tu%d: %d soft errors, %d chksum errors, %d hard errors\n",
			minor(dev), tu.tu_serrs, tu.tu_cerrs, tu.tu_herrs);
		tu.tu_serrs = tu.tu_cerrs = tu.tu_herrs = 0;
E 2
I 2
D 4
		   "uu%d: %d soft errors, %d chksum errors, %d hard errors\n",
D 3
		    minor(dev), uuc->uu_serrs, uuc->uu_cerrs, uuc->uu_herrs);
E 3
I 3
		    UNIT(dev), uuc->uu_serrs, uuc->uu_cerrs, uuc->uu_herrs);
E 4
I 4
		   "uu%d: %d soft errors, %d checksum errors, %d hard errors\n",
D 5
		    unit, uuc->uu_serrs, uuc->uu_cerrs, uuc->uu_herrs);
E 4
E 3
		    uuc->uu_serrs = uuc->uu_cerrs = uuc->uu_herrs = 0;
E 5
I 5
		    unit, uuc->tu_serrs, uuc->tu_cerrs, uuc->tu_herrs);
		    uuc->tu_serrs = uuc->tu_cerrs = uuc->tu_herrs = 0;
E 5
E 2
	}
D 2
	tu.tu_dopen[minor(dev)&DNUM] = 0;
E 2
I 2
D 3
	uuc->uu_dopen[minor(dev)%NDPC] = 0;
E 3
I 3
D 4
	uuc->uu_dopen[UNIT(dev)] = 0;
E 4
I 4
D 5
	uuc->uu_dopen[unit%NDPC] = 0;
E 5
I 5
	uuc->tu_dopen[unit&UMASK] = 0;
E 7
I 7
D 9
	uuc = &uu_softc[UNIT(dev)/NDPC];
	uuc->tu_dopen[UNIT(dev)&UMASK] = 0;
E 9
I 9
	s = splx(UUIPL);
	while (uu_pcnt[unit])
		sleep(&uu_pcnt[unit], PRIBIO);
	/*
	 * No more writes are pending, scan the 
	 * buffer queue for oustanding reads from
	 * this unit.
	 */
D 10
	for (bp = uitab[unit/NDPC].b_actf; bp; bp = bp->b_actf)
E 10
I 10
	for (bp = uitab[unit/NDPC].b_actf; bp; bp = bp->b_actf) {
E 10
		if (bp->b_dev == dev)
			last = bp;
D 10
	if (last) 
		iowait(last);
E 10
I 10
	}
	if (last) {
		last->b_flags |= B_CALL;
		last->b_iodone = uuwake;
		sleep((caddr_t)last, PRIBIO);
	}
E 10
	uuc->tu_dopen[unit&UMASK] = 0;
	if (!uuc->tu_dopen[0] && !uuc->tu_dopen[1]) {
		uuc->tu_flag = 0;
		uuaddr->rcs = 0;
D 10
		/*
		 * Make sure the device is left in a
		 * known state....
		 */
		if (uuc->tu_state != TUS_IDLE)
			uuc->tu_state = TUS_INIT1;
E 10
	}
	splx(s);
E 9
E 7
E 5
E 4
E 3
E 2
}

I 10
uuwake(bp)
	struct buf *bp;
{
	wakeup(bp);
}

E 10
D 2
/*
 * Reset the TU58
 */
tureset()
E 2
I 2
uureset(ctlr)
	int ctlr;
E 2
{
I 2
D 3
	register struct uu_ctlr *uuc = uu_ctlr[ctlr];
	register struct packet *cmd = uucmd[ctlr];
	register struct uudevice *uuaddr;
E 3
I 3
D 5
	register struct uu_ctlr *uuc = &uu_ctlr[ctlr];
E 5
I 5
D 6
	register struct tu *uuc = &uu_softc[ctlr];
E 6
I 6
	register struct uu_softc *uuc = &uu_softc[ctlr];
E 6
E 5
	register struct packet *cmd = &uucmd[ctlr];
E 3
D 4
	struct uba_ctlr *um = uuminfo[ctlr];
I 3
	register struct uudevice *uuaddr = (struct uudevice *)um->um_addr;
E 4
I 4
	struct uba_device *ui = uudinfo[ctlr];
	register struct uudevice *uuaddr = (struct uudevice *)ui->ui_addr;
E 4
E 3
E 2

D 2
	tu.tu_state = TUS_INIT1;
	tu.tu_wbptr = tunull;
	tu.tu_wcnt = sizeof (tunull);
	tucmd.pk_flag = TUF_CMD;
	tucmd.pk_mcount = sizeof (tucmd) - 4;
	tucmd.pk_mod = 0;
	tucmd.pk_seq = 0;
	tucmd.pk_sw = MRSP ? TUSW_MRSP : 0;
	tutab.b_active++;
	mtpr(CSRS, 0);
	mtpr(CSTS, IE|BREAK);
	tuxintr();		/* start output */
E 2
I 2
D 4
	um->um_tab.b_active++;
E 4
I 4
D 6
	printf ("uureset\n");
E 6
	uitab[ctlr].b_active++;
E 4
D 3
	uuc->uu_state = TUS_INIT1;
E 3
I 3
D 5
	uuc->uu_state = UUS_INIT1;
E 3
	uuc->uu_wbptr = uunull;
	uuc->uu_wcnt = sizeof (uunull);
E 5
I 5
	uuc->tu_state = TUS_INIT1;
	uuc->tu_wbptr = uunull;
	uuc->tu_wcnt = sizeof (uunull);
I 9
	uuc->tu_rcnt = 0;
E 9
E 5
	cmd->pk_flag = TUF_CMD;
D 3
	cmd->pk_mcount = sizeof (uucmd) - 4;
E 3
I 3
	cmd->pk_mcount = sizeof (*cmd) - 4;
E 3
	cmd->pk_mod = 0;
	cmd->pk_seq = 0;
D 3
	cmd->pk_sw = MRSP ? TUSW_MRSP : 0;
	uuaddr = (struct uudevice *)um->um_addr;
E 3
I 3
	cmd->pk_sw = 0;
E 3
	uuaddr->rcs = 0;
	uuaddr->tcs = UUCS_INTR | UUCS_BREAK;
	uuxintr(ctlr);				/* start output */
E 2
}

I 3
D 4
uudgo()
{
}

E 4
E 3
/*
 * Strategy routine for block I/O
 */
D 2
tustrategy(bp)
E 2
I 2
uustrategy(bp)
E 2
	register struct buf *bp;
{
D 2
	register int s;
E 2
I 2
D 3
	register struct buf *dp;
E 3
I 3
	register struct buf *uutab;
E 3
	struct uba_device *ui;
D 3
	struct uu_ctlr *uuc;
	int s, unit = minor(bp->b_dev);
E 3
I 3
D 4
	int s, unit = UNIT(bp->b_dev);
E 4
I 4
D 9
	int s, unit = UNIT(minor(bp->b_dev));
E 9
I 9
	int s, unit = UNIT(bp->b_dev);
E 9
E 4
E 3
E 2

D 2
	if (bp->b_blkno >= NTUBLK) {
		bp->b_flags |= B_ERROR;
		iodone(bp);
		return;
E 2
I 2
D 4
	if (unit > NUU)
E 4
I 4
D 9
	if (unit > NUX)
E 9
I 9
	if ((unit > NUX) || (bp->b_blkno >= NTUBLK))
E 9
E 4
		goto bad;
D 9
	if (bp->b_blkno >= NTUBLK)
		goto bad;
E 9
D 4
	ui = uudinfo[unit];
E 4
I 4
	ui = uudinfo[unit/NDPC];
E 4
	if (ui == 0 || ui->ui_alive == 0)
		goto bad;
D 3
	uuc = &uu_ctlr[ui->ui_mi->um_ctlr];
E 3
I 3
D 4
	uutab = &ui->ui_mi->um_tab;	/* one request queue per controller */
E 4
I 4
	uutab = &uitab[unit/NDPC];	/* one request queue per controller */
I 7
	s = splx(UUIPL);
E 7
E 4
	if ((bp->b_flags&B_READ) == 0)
D 4
		uu_pee(&pcnt[UNIT(bp->b_dev)]);
E 3
	s = spl5();
D 3
	bp->b_cylin = bp->b_blkno;
	dp = &uuutab[unit];
	disksort(dp, bp);
	if (dp->b_active == 0) {
		uuustart(ui);
		bp = &ui->ui_mi->um_tab;
		if (bp->b_actf && bp->b_active == 0)
			uustart(ui->ui_mi);
E 2
	}
E 3
I 3
	bp->av_forw = NULL;
E 4
I 4
D 5
		uu_pee(&pcnt[unit]);
	printf("uustrat: unit=%d, bp=%x\n", unit, bp);
E 5
I 5
D 9
		tu_pee(&pcnt[unit]);
E 5
D 7
	s = splx(UUIPL);
E 7
D 5
	bp->b_forw = NULL;
E 5
I 5
	bp->av_forw = NULL;
E 9
I 9
		tu_pee(&uu_pcnt[unit]);
	bp->b_actf = NULL;
E 9
E 5
E 4
	if (uutab->b_actf == NULL)
		uutab->b_actf = bp;
	else
D 4
		uutab->b_actl->av_forw = bp;
E 4
I 4
D 5
		uutab->b_actl->b_forw = bp;
E 5
I 5
D 9
		uutab->b_actl->av_forw = bp;
E 9
I 9
		uutab->b_actl->b_actf = bp;
E 9
E 5
E 4
	uutab->b_actl = bp;
	if (uutab->b_active == 0)
D 4
		uustart(ui->ui_mi);
E 4
I 4
		uustart(ui);
E 4
E 3
D 2
	if ((bp->b_flags&B_READ) == 0)
		tu_pee(&pcnt[minor(bp->b_dev)&DNUM]);
	bp->av_forw = NULL;
	s = splx(TUIPL);
	if (tutab.b_actf == NULL)
		tutab.b_actf = bp;
	else
		tutab.b_actl->av_forw = bp;
	tutab.b_actl = bp;
	if (tutab.b_active == NULL)
		tustart();
E 2
	splx(s);
I 2
	return;

bad:
	bp->b_flags |= B_ERROR;
I 3
	bp->b_error = ENXIO;
E 3
	iodone(bp);
	return;
E 2
}

/*
I 2
D 3
 * Unit start routine.
 * Put this unit on the ready queue for the controller
 */
uuustart(ui)
	register struct uba_device *ui;
{
	struct buf *dp = &uuutab[ui->ui_unit];
	struct uba_ctlr *um = ui->ui_mi;
	
	dp->b_forw = NULL;
	if (um->um_tab.b_actf == NULL)
		um->um_tab.b_actf = dp;
	else
		um->um_tab.b_actl->b_forw = dp;
	um->um_tab.b_actl = dp;
	dp->b_active++;
}
/*
E 3
E 2
 * Start the transfer
 */
D 2
tustart()
E 2
I 2
D 4
uustart(um)
	register struct uba_ctlr *um;
E 4
I 4
uustart(ui)
	register struct uba_device *ui;
E 4
E 2
{
I 2
D 3
	register struct uudevice *uuaddr;
E 3
E 2
	register struct buf *bp;
I 2
D 5
	register struct uu_ctlr *uuc;
E 5
I 5
D 6
	register struct tu *uuc;
E 6
I 6
	register struct uu_softc *uuc;
E 6
E 5
D 3
	struct buf *dp;
E 3
	struct packet *cmd;
D 3
	int unit;
E 3
I 3
D 4
	int ctlr;
E 4
I 4
D 10
	int ctlr = ui->ui_unit;
E 10
I 10
	int ctlr = ui->ui_unit, s;
E 10
E 4
E 3
E 2

D 2
	if ((bp = tutab.b_actf) == NULL)
E 2
I 2
D 3
loop:
	if ((dp = um->um_tab.b_actf) == NULL)
E 3
I 3
D 4
	bp = um->um_tab.b_actf;
	if (bp == NULL)
E 4
I 4
	if ((bp = uitab[ctlr].b_actf) == NULL)
E 4
E 3
E 2
		return;
I 10
	s = splx(UUIPL);
E 10
D 2
	if (tu.tu_state != TUS_IDLE) {
		tureset();
E 2
I 2
D 3
	if ((bp = dp->b_actf) == NULL) {
		um->um_tab.b_actf = dp->b_forw;
		goto loop;
	}
	unit = minor(bp->b_dev);
	uuc = &uu_ctlr[um->um_ctlr];
	cmd = &uucmd[um->um_ctlr];
	if (uuc->uu_state != TUS_IDLE) {
		uureset(um->um_ctlr);
E 3
I 3
D 4
	ctlr = um->um_ctlr;
E 4
D 5
	uuc = &uu_ctlr[ctlr];
E 5
I 5
	uuc = &uu_softc[ctlr];
E 5
D 9
	cmd = &uucmd[ctlr];
E 9
D 5
	if (uuc->uu_state != UUS_IDLE) {
E 5
I 5
	if (uuc->tu_state != TUS_IDLE) {
E 5
		uureset(ctlr);
I 10
		splx(s);
E 10
E 3
E 2
		return;
	}
I 9
	cmd = &uucmd[ctlr];
E 9
D 2
	tutab.b_active++;
	tutab.b_errcnt = 0;
	tucmd.pk_op = bp->b_flags&B_READ ? TUOP_READ : TUOP_WRITE;
	tucmd.pk_mod = ((bp->b_flags&B_READ) == 0 && (minor(bp->b_dev)&WRV)) ?
E 2
I 2
D 4
	um->um_tab.b_active++;
E 4
I 4
	uitab[ctlr].b_active++;
E 4
D 3
	uuaddr = (struct uudevice *)um->um_addr;
E 3
D 5
	cmd->pk_op = bp->b_flags&B_READ ? TUOP_READ : TUOP_WRITE;
	cmd->pk_mod = ((bp->b_flags&B_READ) == 0 && (minor(bp->b_dev)&WRV)) ?
E 2
	    TUMD_WRV : 0;
E 5
I 5
	uitab[ctlr].b_errcnt = 0;
	uuc->tu_addr = bp->b_un.b_addr;
	uuc->tu_count = cmd->pk_count = bp->b_bcount;
	cmd->pk_block = bp->b_blkno;
	if (bp->b_flags&B_READ) {
		cmd->pk_op = TUOP_READ;
		cmd->pk_mod = 0;
		uuc->tu_state = TUS_SENDR;
	} else {
		cmd->pk_op = TUOP_WRITE;
		cmd->pk_mod = minor(bp->b_dev)&WRV ? TUMD_WRV : 0;
		uuc->tu_state = TUS_SENDW;
	}
E 5
D 2
	tucmd.pk_unit = (minor(bp->b_dev)&DNUM);
	tucmd.pk_sw = MRSP ? TUSW_MRSP : 0;
	tucmd.pk_count = tu.tu_count = bp->b_bcount;
	tucmd.pk_block = bp->b_blkno;
	tucmd.pk_chksum =
	    tuchk(*((short *)&tucmd), (u_short *)&tucmd.pk_op,
		(int)tucmd.pk_mcount);
	tu.tu_state = bp->b_flags&B_READ ? TUS_SENDR : TUS_SENDW;
	tu.tu_addr = bp->b_un.b_addr;
	tu.tu_count = bp->b_bcount;
	tu.tu_wbptr = (u_char *)&tucmd;
	tu.tu_wcnt = sizeof (tucmd);
	tuxintr();
E 2
I 2
D 3
	cmd->pk_unit = (minor(bp->b_dev)&DNUM);
	cmd->pk_sw = MRSP ? TUSW_MRSP : 0;
	cmd->pk_count = uu->uu_count = bp->b_bcount;
E 3
I 3
D 4
	cmd->pk_unit = UNIT(bp->b_dev);
E 4
I 4
D 9
	cmd->pk_unit = UNIT(minor(bp->b_dev));
E 9
I 9
	cmd->pk_unit = UNIT(bp->b_dev)&UMASK;
E 9
E 4
	cmd->pk_sw = 0;
D 5
	cmd->pk_count = uuc->uu_count = bp->b_bcount;
E 3
	cmd->pk_block = bp->b_blkno;
E 5
	cmd->pk_chksum =
D 3
	    uuchk(*((short *)&cmd), (u_short *)&cmd.pk_op,
		(int)cmd.pk_mcount);
	uuc->uu_state = bp->b_flags&B_READ ? TUS_SENDR : TUS_SENDW;
E 3
I 3
D 5
	    uuchk(*((short *)cmd), (u_short *)&cmd->pk_op,
		(int)cmd->pk_mcount);
	uuc->uu_state = bp->b_flags&B_READ ? UUS_SENDR : UUS_SENDW;
E 3
	uuc->uu_addr = bp->b_un.b_addr;
	uuc->uu_count = bp->b_bcount;
D 3
	uuc->uu_wbptr = (u_char *)&uucmd;
	uuc->uu_wcnt = sizeof (uucmd);
	uuxintr(um->um_ctlr);
E 3
I 3
	uuc->uu_wbptr = (u_char *)cmd;
	uuc->uu_wcnt = sizeof (*cmd);
E 5
I 5
	    tuchk(*((short *)cmd), (u_short *)&cmd->pk_op, (int)cmd->pk_mcount);
	uuc->tu_wbptr = (u_char *)cmd;
	uuc->tu_wcnt = sizeof (*cmd);
E 5
	uuxintr(ctlr);
I 10
	splx(s);
E 10
E 3
E 2
}

/*
D 6
 * TU58 receiver interrupt
E 6
I 6
D 9
 * TU58 receiver interrupt,
 * handles whatever condition the
 * pseudo DMA routine in locore is 
 * unable to handle, or, if UUDMA is
 * undefined, handle all receiver interrupt
 * processing
E 9
I 9
 * TU58 receiver interrupt, handles whatever condition the
 * pseudo DMA routine in locore is unable to handle, 
 * or, if UUDMA is undefined, handle all receiver interrupt
 * processing.
E 9
E 6
 */
D 2
turintr()
E 2
I 2
D 3
uurintr()
E 3
I 3
uurintr(ctlr)
	int ctlr;
E 3
E 2
{
D 3
	register struct buf *bp;
	register int c;
E 3
I 3
D 4
	struct uba_ctlr *um = uuminfo[ctlr];
	register struct buf *bp = um->um_tab.b_actf;
E 4
I 4
	struct uba_device *ui = uudinfo[ctlr];
E 4
D 5
	register struct uu_ctlr *uuc = &uu_ctlr[ctlr];
E 5
I 5
D 6
	register struct tu *uuc = &uu_softc[ctlr];
E 6
I 6
	register struct uu_softc *uuc = &uu_softc[ctlr];
E 6
E 5
D 4
	register struct uudevice *uuaddr = (struct uudevice *)um->um_addr;
	register struct buf *uutab = &um->um_tab;
E 4
I 4
	register struct uudevice *uuaddr = (struct uudevice *)ui->ui_addr;
	register struct buf *uutab = &uitab[ctlr];
D 5
	register struct buf *bp = uutab->b_actf;
E 5
E 4
	struct packet *data, *cmd;
D 4
	int c;
E 4
I 4
D 5
	int c, unit = UNIT(minor(bp->b_dev));
E 5
I 5
	struct buf *bp;
	int c, unit;
E 5
E 4
E 3

D 3
	c = mfpr(CSRD)&0xff;		/* get the char, clear the interrupt */
	if (MRSP) {
		while ((mfpr(CSTS)&READY) == 0)
			;
		mtpr(CSTD, TUF_CONT);	/* ACK */
E 3
I 3
D 4
	if (!uutab->b_active)
E 4
I 4
	c = uuaddr->rdb;
D 5
	/*
	 * We may have a stray interrupt, but read
	 * the data anyway, otherwise we'll get an overrun
	 * next time
	 */
	if (uutab->b_active == 0)
E 4
		return;
	cmd = &uucmd[ctlr];
E 5
I 5
	data = &uudata[ctlr];
E 5
D 4
	c = uuaddr->rdb;
E 4
D 6
	if (c & UURDB_ERROR) {
E 6
I 6
	cmd = &uucmd[ctlr];
#if !defined(UUDMA)
	if (c & UURDB_ERROR)
		uuc->tu_state = TUS_RCVERR;
	else {
		if (uuc->tu_rcnt) {
			*uuc->tu_rbptr++ = c;
			if (--uuc->tu_rcnt)
				return;
		}
	}
#endif

	/*
	 * Switch on the tu_state of the transfer.
	 */
	switch(uuc->tu_state) {

	/*
	 * A data error occured in uudma
	 * (either overrun or break)
	 */
	case TUS_RCVERR:
E 6
D 5
		if (c & UURDB_ORUN) {
D 4
			printf("data overrun, ");
			goto bad;
E 4
I 4
			printf("uu%d: data overrun (ignored)\n", unit);
E 4
		} else {
			printf("uu%d: break received, device reset, state=", 
D 4
				UNIT(bp->b_dev));
E 4
I 4
				unit);
E 4
			printstate(uuc->uu_state);
			uureset(ctlr);
			printf("\n");
			return;
		}
E 5
I 5
D 7
		if (c & UURDB_ORUN) 
			printf("uu(%d): data overrun, bytes left: %d",
			  ui->ui_unit, 
			  uuc->tu_count + uuc->tu_rcnt - data->pk_mcount);
		else
			printf("uu(%d): break received", ui->ui_unit);
D 6
		printf(", device reset, state="); 
		printstate(uuc->tu_state);
		uureset(ctlr);
		printf("\n");
		timeout(uustart, (caddr_t)ui, hz/2);	/* start uustart when */
							/* reset is done */
		return;
E 5
E 3
	}
I 4
D 5
	data = &uudata[ctlr];
E 5
E 4
D 2
	if (tu.tu_rcnt) {		/* still waiting for data? */
		*tu.tu_rbptr++ = c;	/* yup, put it there */
		if (--tu.tu_rcnt)	/* decrement count, any left? */
E 2
I 2
D 3
	if (uu->uu_rcnt) {		/* still waiting for data? */
		*uu->uu_rbptr++ = c;	/* yup, put it there */
		if (--uu->uu_rcnt)	/* decrement count, any left? */
E 3
I 3
top:
D 5
	c &= 0xff;
	if (uuc->uu_rcnt) {		/* still waiting for data? */
		*uuc->uu_rbptr++ = c;	/* yup, put it there */
		if (--uuc->uu_rcnt)	/* decrement count, any left? */
E 5
I 5
	c &= UUDB_DMASK;
	if (uuc->tu_rcnt) {		/* still waiting for data? */
		*uuc->tu_rbptr++ = c;	/* yup, put it there */
		if (--uuc->tu_rcnt)	/* decrement count, any left? */
E 5
E 3
E 2
			return;		/* get some more */
	}
I 5
	cmd = &uucmd[ctlr];
E 6
I 6
		printf(", transfer restarted\n"); 
E 7
I 7
		if ((c & UURDB_ORUN) == 0)
			printf("uu%d: break received, transfer restarted\n",
D 8
								data->pk_unit);
E 8
I 8
			    data->pk_unit);
I 9
#ifdef UUDEBUG
		else
			printf("uu%d: data overrun, recovered\n", 
			    data->pk_unit);
#endif
E 9
E 8
		uuc->tu_serrs++;
E 7
		uu_restart(ctlr, ui);	
		break;
E 6
E 5
I 3
D 4
	data = &uudata[ctlr];
E 4
E 3

	/*
D 6
	 * We got all the data we were expecting for now,
D 2
	 * switch on the tu_state of the transfer.
E 2
I 2
D 5
	 * switch on the uu_state of the transfer.
E 5
I 5
	 * switch on the tu_state of the transfer.
E 5
E 2
	 */
D 2
	switch(tu.tu_state) {
E 2
I 2
D 3
	switch(uu->uu_state) {
E 3
I 3
D 5
	switch(uuc->uu_state) {
E 5
I 5
	switch(uuc->tu_state) {
E 5
E 3
E 2

	/*
E 6
	 * If we get an unexpected "continue",
	 * start all over again...
	 */
D 3
	case TUS_INIT2:
D 2
		tu.tu_state = c == TUF_CONT ? TUS_IDLE : TUS_INIT1;
		tu.tu_flag = 0;
		wakeup((caddr_t)&tu);
		tustart();
E 2
I 2
		uu->uu_state = c == TUF_CONT ? TUS_IDLE : TUS_INIT1;
		uu->uu_flag = 0;
		wakeup((caddr_t)&uu);
		uustart();
E 3
I 3
D 5
	case UUS_INIT2:
		uuc->uu_state = c == TUF_CONT ? UUS_IDLE : UUS_INIT1;
		uuc->uu_flag = 0;
E 5
I 5
	case TUS_INIT2:
		uuc->tu_state = c == TUF_CONT ? TUS_IDLE : TUS_INIT1;
		uuc->tu_flag = 0;
E 5
		wakeup((caddr_t)uuc);
D 4
		uustart(um);
E 4
I 4
		uustart(ui);
E 4
E 3
E 2
		break;

	/*
	 * Only transition from this state
	 * is on a "continue", so if we don't
	 * get it, reset the world.
	 */
D 3
	case TUS_WAIT:			/* waiting for continue */
		if (c != TUF_CONT) {
D 2
			tu.tu_state = TUS_INIT1;
E 2
I 2
			uu->uu_state = TUS_INIT1;
E 3
I 3
D 5
	case UUS_WAIT:			/* waiting for continue */
E 5
I 5
	case TUS_WAIT:			/* waiting for continue */
E 5
		switch(c) {
		case TUF_CONT:  /* got the expected continue */
D 5
			uuc->uu_flag = 0;
E 5
I 5
			uuc->tu_flag = 0;
E 5
			data->pk_flag = TUF_DATA;
D 5
			data->pk_mcount = MIN(128, uuc->uu_count);
E 5
I 5
			data->pk_mcount = MIN(128, uuc->tu_count);
E 5
			data->pk_chksum =
D 5
			    tuchk(*((short *)data), (caddr_t)uuc->uu_addr,
E 5
I 5
			    tuchk(*((short *)data), (caddr_t)uuc->tu_addr,
E 5
				(int)data->pk_mcount);
D 5
			uuc->uu_state = UUS_SENDH;
			uuc->uu_wbptr = (u_char *)data;
			uuc->uu_wcnt = 2;
E 5
I 5
			uuc->tu_state = TUS_SENDH;
			uuc->tu_wbptr = (u_char *)data;
			uuc->tu_wcnt = 2;
E 5
D 4
			tuxintr();
E 4
I 4
			uuxintr(ctlr);
E 4
E 3
E 2
			break;
I 3

		case TUF_CMD:   /* sending us an END packet...error */
D 5
			uuc->uu_state = UUS_GET;
			uuc->uu_rbptr = (u_char *) data;
			uuc->uu_rcnt = sizeof (*data);
			uuc->uu_flag = 1;
E 5
I 5
			uuc->tu_state = TUS_GET;
			uuc->tu_rbptr = (u_char *)data;
D 6
			uuc->tu_rcnt = sizeof (*data);
E 6
I 6
			uuc->tu_rcnt = sizeof (*data) - 1;
E 6
			uuc->tu_flag = 1;
E 5
			uuaddr->tcs = 0;
D 6
			goto top;
E 6
I 6
			*uuc->tu_rbptr++ = c & UUDB_DMASK;
			break;
E 6

		case TUF_INITF:
D 4
			tureset();
E 4
I 4
			uureset(ctlr);
E 4
			break;

		default:        /* something random...bad news */
D 5
			uuc->uu_state = UUS_INIT1;
E 5
I 5
			uuc->tu_state = TUS_INIT1;
E 5
			break;
E 3
		}
D 2
		tu.tu_flag = 0;
		tudata.pk_flag = TUF_DATA;
		tudata.pk_mcount = MIN(128, tu.tu_count);
		tudata.pk_chksum =
		    tuchk(*((short *)&tudata), (u_short *)tu.tu_addr,
			(int)tudata.pk_mcount);
		tu.tu_state = TUS_SENDH;
		tu.tu_wbptr = (u_char *)&tudata;
		tu.tu_wcnt = 2;
		tuxintr();
E 2
I 2
D 3
		uu->uu_flag = 0;
		uudata.pk_flag = TUF_DATA;
		uudata.pk_mcount = MIN(128, uu->uu_count);
		uudata.pk_chksum =
		    uuchk(*((short *)&uudata), (u_short *)uu->uu_addr,
			(int)uudata.pk_mcount);
		uu->uu_state = TUS_SENDH;
		uu->uu_wbptr = (u_char *)&uudata;
		uu->uu_wcnt = 2;
		uuxintr();
E 3
E 2
		break;

D 3
	case TUS_SENDW:
E 3
I 3
D 5
	case UUS_SENDW:
E 3
		if (c != TUF_CONT)
E 5
I 5
	case TUS_SENDW:
		if (c != TUF_CONT && c != TUF_INITF)
E 5
			goto bad;
D 2
		tureset();
E 2
I 2
D 3
		uureset();
E 3
I 3
D 6
		uureset(ctlr);
E 6
I 6
		uu_restart(ctlr, ui);
E 6
E 3
E 2
		break;

	/*
	 * Got header, now get data; amount to
D 2
	 * fetch is include in packet.
E 2
I 2
	 * fetch is included in packet.
I 6
	 * (data packets are handled entirely
	 * in uudma)
E 6
E 2
	 */
D 3
	case TUS_GETH:
D 2
		if (tudata.pk_flag == TUF_DATA)
			tu.tu_rbptr = (u_char *)tu.tu_addr;
		tu.tu_rcnt = tudata.pk_mcount;
		tu.tu_state = TUS_GETD;
E 2
I 2
		if (uudata.pk_flag == TUF_DATA)
			uu->uu_rbptr = (u_char *)uu->uu_addr;
		uu->uu_rcnt = uudata.pk_mcount;
		uu->uu_state = TUS_GETD;
E 3
I 3
D 5
	case UUS_GETH:
		if (data->pk_flag == TUF_DATA)
			uuc->uu_rbptr = (u_char *)uuc->uu_addr;
		uuc->uu_rcnt = data->pk_mcount;
		uuc->uu_state = UUS_GETD;
E 5
I 5
	case TUS_GETH:
I 7
#ifndef UUDMA
		if (data->pk_flag == TUF_DATA)
			uuc->tu_rbptr = (u_char *)uuc->tu_addr;
#endif
E 7
D 6
		if (data->pk_flag == TUF_DATA) {
			uu_getblk((u_char *)uuc->tu_addr, data, uuaddr);
			goto getc;
		} 
E 6
		uuc->tu_rcnt = data->pk_mcount;
		uuc->tu_state = TUS_GETD;
E 5
E 3
E 2
		break;

	/*
	 * Got the data, now fetch the checksum.
	 */
D 3
	case TUS_GETD:
D 2
		tu.tu_rbptr = (u_char *)&tudata.pk_chksum;
		tu.tu_rcnt = sizeof (tudata.pk_chksum);
		tu.tu_state = TUS_GETC;
E 2
I 2
		uu->uu_rbptr = (u_char *)&uudata.pk_chksum;
		uu->uu_rcnt = sizeof (uudata.pk_chksum);
		uu->uu_state = TUS_GETC;
E 3
I 3
D 5
	case UUS_GETD:
		uuc->uu_rbptr = (u_char *)&data->pk_chksum;
		uuc->uu_rcnt = sizeof (data->pk_chksum);
		uuc->uu_state = UUS_GETC;
E 5
I 5
	case TUS_GETD:
		uuc->tu_rbptr = (u_char *)&data->pk_chksum;
		uuc->tu_rcnt = sizeof (data->pk_chksum);
		uuc->tu_state = TUS_GETC;
E 5
E 3
E 2
		break;

D 3
	case TUS_GET:
	case TUS_GETC:
E 3
I 3
D 5
	case UUS_GET:
	case UUS_GETC:
E 5
I 5
D 6
	case TUS_GET:
E 6
	case TUS_GETC:
D 6
getc:
E 6
E 5
E 3
		/* got entire packet */
D 6
#ifdef notdef
E 6
D 2
		if (tudata.pk_chksum !=
		    tuchk(*((short *)&tudata), (u_short *)
		     (tudata.pk_flag == TUF_DATA ? tu.tu_addr : &tudata.pk_op),
		     (int)tudata.pk_mcount))
			tu.tu_cerrs++;
E 2
I 2
D 3
		if (uudata.pk_chksum !=
		    uuchk(*((short *)&uudata), (u_short *)
		     (uudata.pk_flag == TUF_DATA ? uu->uu_addr : &uudata.pk_op),
		     (int)uudata.pk_mcount))
			uu->uu_cerrs++;
E 3
I 3
		if (data->pk_chksum !=
D 5
		    uuchk(*((short *)data), (u_short *)
		     (data->pk_flag == TUF_DATA ? uuc->uu_addr : &data->pk_op),
E 5
I 5
		    tuchk(*((short *)data), (u_short *)
D 6
		     (data->pk_flag == TUF_DATA ? uuc->tu_addr : &data->pk_op),
E 6
I 6
		     (data->pk_flag == TUF_DATA ?
D 7
		     (u_short *)  uuc->tu_addr : (u_short *)&data->pk_op),
E 7
I 7
		     (u_short *) uuc->tu_addr : (u_short *)&data->pk_op),
E 7
E 6
E 5
		     (int)data->pk_mcount))
I 6
	case TUS_CHKERR:
E 6
D 5
			uuc->uu_cerrs++;
E 5
I 5
			uuc->tu_cerrs++;
E 5
E 3
E 2
D 6
#endif
E 6
I 6
	case TUS_GET:
E 6
D 2
		if (tudata.pk_flag == TUF_DATA) {
E 2
I 2
D 3
		if (uudata.pk_flag == TUF_DATA) {
E 3
I 3
		if (data->pk_flag == TUF_DATA) {
E 3
E 2
			/* data packet, advance to next */
D 2
			tu.tu_addr += tudata.pk_mcount;
			tu.tu_count -= tudata.pk_mcount;
			tu.tu_state = TUS_GETH;
			tu.tu_rbptr = (u_char *)&tudata; /* next packet */
			tu.tu_rcnt = 2;
		} else if (tudata.pk_flag==TUF_CMD && tudata.pk_op==TUOP_END) {
E 2
I 2
D 3
			uu->uu_addr += uudata.pk_mcount;
			uu->uu_count -= uudata.pk_mcount;
			uu->uu_state = TUS_GETH;
			uu->uu_rbptr = (u_char *)&uudata; /* next packet */
			uu->uu_rcnt = 2;
		} else if (uudata.pk_flag==TUF_CMD && uudata.pk_op==TUOP_END) {
E 3
I 3
D 5
			uuc->uu_addr += data->pk_mcount;
			uuc->uu_count -= data->pk_mcount;
			uuc->uu_state = UUS_GETH;
			uuc->uu_rbptr = (u_char *)data;	/* next packet */
			uuc->uu_rcnt = 2;
E 5
I 5
			uuc->tu_addr += data->pk_mcount;
			uuc->tu_count -= data->pk_mcount;
			uuc->tu_state = TUS_GETH;
			uuc->tu_rbptr = (u_char *)data;	/* next packet */
			uuc->tu_rcnt = 2;
E 5
		} else if (data->pk_flag==TUF_CMD && data->pk_op==TUOP_END) {
E 3
E 2
			/* end packet, idle and reenable transmitter */
D 2
			tu.tu_state = TUS_IDLE;
			tu.tu_flag = 0;
E 2
I 2
D 3
			uu->uu_state = TUS_IDLE;
			uu->uu_flag = 0;
E 2
			mtpr(CSTS, IE);
E 3
I 3
D 5
			uuc->uu_state = UUS_IDLE;
			uuc->uu_flag = 0;
			uuaddr->rcs = UUCS_INTR;
E 3
			printd("ON ");
D 2
			if ((bp = tutab.b_actf) == NULL) {
				printf("tu: no bp, active %d\n",tutab.b_active);
				tustart();
E 2
I 2
D 3
			if ((bp = uutab.b_actf) == NULL) {
				printf("uu: no bp, active %d\n",uutab.b_active);
				uustart();
E 3
I 3
			if (bp == NULL) {
E 5
I 5
			uuc->tu_state = TUS_IDLE;
			uuc->tu_flag = 0;
			uuaddr->tcs = UUCS_INTR;
			if ((bp = uutab->b_actf) == NULL) {
E 5
D 4
				printf("uu: no bp active\n");
				uustart(um);
E 4
I 4
D 7
				printf("uu(%d): no bp, active %d\n", 
D 5
					uitab[ctlr].b_active);
E 5
I 5
					ui->ui_unit, uitab[ctlr].b_active);
E 7
I 7
				printf("uu%d: no bp, active %d\n", 
D 8
					data->pk_unit, uitab[ctlr].b_active);
E 8
I 8
				    data->pk_unit, uitab[ctlr].b_active);
E 8
E 7
E 5
				uustart(ui);
E 4
E 3
E 2
				return;
			}
I 5
D 9
			unit = UNIT(minor(bp->b_dev));
E 9
I 9
			unit = UNIT(bp->b_dev);
E 9
E 5
D 2
			if (tudata.pk_mod > 1) {        /* hard error */
E 2
I 2
D 3
			if (uudata.pk_mod > 1) {        /* hard error */
E 3
I 3
			if (data->pk_mod > 1) {        /* hard error */
I 6
				printf("uu%d: hard error bn%d,", unit, 
D 8
								bp->b_blkno);
E 8
I 8
				    bp->b_blkno);
E 8
D 9
				printf(" pk_mod %o\n", data->pk_mod&0xff);
E 9
I 9
				printf(" pk_mod 0%o\n", data->pk_mod&0xff);
E 9
E 6
E 3
E 2
				bp->b_flags |= B_ERROR;
D 2
				tu.tu_herrs++;
				harderr(bp, "tu");
				printf("  pk_mod %o\n", tudata.pk_mod&0377);
			} else if (tudata.pk_mod != 0)	/* soft error */
				tu.tu_serrs++;
			tutab.b_active = NULL;
			tutab.b_actf = bp->av_forw;
			bp->b_resid = tu.tu_count;
E 2
I 2
D 3
				uu->uu_herrs++;
E 3
I 3
D 5
				uuc->uu_herrs++;
E 5
I 5
				uuc->tu_herrs++;
E 5
E 3
D 6
				harderr(bp, "uu");
D 3
				printf("  pk_mod %o\n", uudata.pk_mod&0377);
			} else if (uudata.pk_mod != 0)	/* soft error */
				uu->uu_serrs++;
			uutab.b_active = NULL;
			uutab.b_actf = bp->av_forw;
			bp->b_resid = uu->uu_count;
E 3
I 3
				printf(" pk_mod %o\n", data->pk_mod&0xff);
E 6
D 9
			} else if (data->pk_mod != 0)	/* soft error */
E 9
I 9
			} else if (data->pk_mod)	/* soft error */
E 9
D 5
				uuc->uu_serrs++;
E 5
I 5
				uuc->tu_serrs++;
E 5
			uutab->b_active = NULL;
D 4
			uutab->b_actf = bp->av_forw;
E 4
I 4
D 5
			uutab->b_actf = bp->b_forw;
E 4
			bp->b_resid = uuc->uu_count;
E 5
I 5
D 9
			uutab->b_actf = bp->av_forw;
E 9
I 9
			uutab->b_actf = bp->b_actf;
E 9
			bp->b_resid = uuc->tu_count;
E 5
E 3
E 2
			if ((bp->b_flags&B_READ) == 0)
D 2
				tu_vee(&pcnt[minor(bp->b_dev)&DNUM]);
E 2
I 2
D 3
				uu_vee(&pcnt[minor(bp->b_dev)&DNUM]);
E 3
I 3
D 4
				uu_vee(&pcnt[UNIT(bp->b_dev)]);
E 4
I 4
D 5
				uu_vee(&pcnt[unit]);
E 5
I 5
D 9
				tu_vee(&pcnt[unit]);
E 9
I 9
				tu_vee(&uu_pcnt[unit]);
E 9
E 5
E 4
E 3
E 2
			iodone(bp);
I 5
D 6
			printf(".");
E 6
E 5
D 2
			tustart();
E 2
I 2
D 3
			uustart();
E 3
I 3
D 4
			uustart(um);
E 4
I 4
			uustart(ui);
E 4
E 3
E 2
		} else {
D 7
			printf("neither data nor end: %o %o\n",
D 2
			    tudata.pk_flag&0xff, tudata.pk_op&0xff);
E 2
I 2
D 3
			    uudata.pk_flag&0xff, uudata.pk_op&0xff);
E 2
			mtpr(CSRS, 0);		/* flush the rest */
D 2
			tu.tu_state = TUS_INIT1;
E 2
I 2
			uu->uu_state = TUS_INIT1;
E 3
I 3
			    data->pk_flag&0xff, data->pk_op&0xff);
E 7
I 7
			/*
			 * Neither data nor end: data was lost
D 9
			 * somehow, restart the transfer.
E 9
I 9
			 * somehow, flush and restart the transfer.
E 9
			 */
E 7
D 9
			uuaddr->rcs = 0;		/* flush the rest */
E 9
I 9
			uuaddr->rcs = 0;
E 9
D 5
			uuc->uu_state = UUS_INIT1;
E 5
I 5
D 7
			uuc->tu_state = TUS_INIT1;
E 7
I 6
			uu_restart(ctlr, ui);
I 7
			uuc->tu_serrs++;
E 7
E 6
E 5
E 3
E 2
		}
		break;

D 3
	case TUS_IDLE:
	case TUS_INIT1:
E 3
I 3
D 5
	case UUS_IDLE:
	case UUS_INIT1:
E 5
I 5
	case TUS_IDLE:
	case TUS_INIT1:
E 5
E 3
		break;

	default:
bad:
		if (c == TUF_INITF) {
D 2
			printf("tu protocol error, state=");
			printstate(tu.tu_state);
E 2
I 2
D 3
			printf("uu protocol error, state=");
			printstate(uu->uu_state);
E 3
I 3
D 4
			printf("uu%d protocol error, state=", UNIT(bp->b_dev));
E 4
I 4
D 7
			printf("uu%d protocol error, state=", unit);
E 7
I 7
			printf("uu%d protocol error, state=", data->pk_unit);
E 7
E 4
D 5
			printstate(uuc->uu_state);
E 5
I 5
			printstate(uuc->tu_state);
E 5
E 3
E 2
			printf(", op=%x, cnt=%d, block=%d\n",
D 2
			    tucmd.pk_op, tucmd.pk_count, tucmd.pk_block);
			tutab.b_active = NULL;
			if (bp = tutab.b_actf) {
E 2
I 2
D 3
			    uucmd.pk_op, uucmd.pk_count, uucmd.pk_block);
			uutab.b_active = NULL;
			if (bp = uutab.b_actf) {
E 3
I 3
			    cmd->pk_op, cmd->pk_count, cmd->pk_block);
			uutab->b_active = NULL;
			if (bp = uutab->b_actf) {
E 3
E 2
				bp->b_flags |= B_ERROR;
D 2
				tutab.b_actf = bp->av_forw;
E 2
I 2
D 3
				uutab.b_actf = bp->av_forw;
E 3
I 3
D 4
				uutab->b_actf = bp->av_forw;
E 4
I 4
D 5
				uutab->b_actf = bp->b_forw;
E 5
I 5
D 9
				uutab->b_actf = bp->av_forw;
E 9
I 9
				uutab->b_actf = bp->b_actf;
E 9
E 5
E 4
E 3
E 2
				if ((bp->b_flags&B_READ) == 0)
D 2
					tu_vee(&pcnt[minor(bp->b_dev)&DNUM]);
E 2
I 2
D 3
					uu_vee(&pcnt[minor(bp->b_dev)&DNUM]);
E 3
I 3
D 4
					uu_vee(&pcnt[UNIT(bp->b_dev)]);
E 4
I 4
D 5
					uu_vee(&pcnt[unit]);
E 5
I 5
D 9
					tu_vee(&pcnt[unit]);
E 9
I 9
					tu_vee(&uu_pcnt[unit]);
E 9
E 5
E 4
E 3
E 2
				iodone(bp);
			}
D 2
			tu.tu_state = TUS_INIT1;
E 2
I 2
D 3
			uu->uu_state = TUS_INIT1;
E 3
I 3
D 5
			uuc->uu_state = UUS_INIT1;
E 5
I 5
			uuc->tu_state = TUS_INIT1;
E 5
E 3
E 2
		} else {
D 2
			printf("tu receive state error, state=");
E 2
I 2
D 3
			printf("uu receive state error, state=");
E 3
I 3
			printf("uu%d receive state error, state=", 
D 4
				UNIT(bp->b_dev));
E 4
I 4
D 7
				unit);
E 7
I 7
				data->pk_unit);
E 7
E 4
D 5
			printstate(uuc->uu_state);
E 5
I 5
			printstate(uuc->tu_state);
E 5
E 3
E 2
D 6
			printf(", byte=%x\n", c);
E 6
I 6
			printf(", byte=%x\n", c & 0xff);
E 6
#ifdef notdef
D 2
			tu.tu_state = TUS_INIT1; */
E 2
I 2
D 3
			uu->uu_state = TUS_INIT1; */
E 3
I 3
D 4
			uuc->uu_state = UUS_INIT1; */
E 4
I 4
D 5
			uuc->uu_state = UUS_INIT1;
E 5
I 5
			uuc->tu_state = TUS_INIT1;
E 5
E 4
E 3
E 2
#endif
D 2
			wakeup((caddr_t)&tu);
E 2
I 2
D 3
			wakeup((caddr_t)&uu);
E 3
I 3
			wakeup((caddr_t)uuc);
E 3
E 2
		}
	}
}

D 6
/*
I 5
 * Simulate DMA input from the TU58,
 * usually 128 bytes plus the 2 byte checksum
 * will be read, leaving the CPU `dead' for 
 * approximately 0.135 seconds @ 9600 baud
 */
uu_getblk(buffer, data, uuaddr)
	register u_char *buffer;
	register struct uudevice *uuaddr;
	struct packet *data;
{
	int s;
	int count = (unsigned) data->pk_mcount + 2;
E 6

D 6
	s = spl5();		/* make sure we don't get interrupted by */
				/* disk i/o */
	uuaddr->rcs = 0;	/* disable interrupts temporarily */
	while (count--) {
		while ((uuaddr->rcs & UUCS_READY) == 0)
			;	
		*buffer++ = uuaddr->rdb & UUDB_DMASK;
		if (count == 2)
			buffer = (u_char *)&data->pk_chksum;
	}
	uuaddr->rcs = UUCS_INTR;
	(void) splx(s);
}

E 6
/*
E 5
 * TU58 transmitter interrupt
 */
D 2
tuxintr()
E 2
I 2
D 3
uuxintr()
E 3
I 3
uuxintr(ctlr)
	int ctlr;
E 3
E 2
{
I 3
D 5
	register struct uu_ctlr *uuc = &uu_ctlr[ctlr];
E 5
I 5
D 6
	register struct tu *uuc = &uu_softc[ctlr];
E 6
I 6
	register struct uu_softc *uuc = &uu_softc[ctlr];
E 6
E 5
D 4
	register struct uudevice *uuaddr = 
				(struct uudevice *) uuminfo[ctlr]->um_addr;
E 4
I 4
	register struct uudevice *uuaddr;
E 4
	register struct packet *data;
I 4
	struct uba_device *ui = uudinfo[ctlr];
E 4
	int c;
E 3

I 4
	data = &uudata[ctlr];
	uuaddr = (struct uudevice *) ui->ui_addr;
E 4
top:
D 2
	if (tu.tu_wcnt) {
E 2
I 2
D 3
	if (uu->uu_wcnt) {
E 3
I 3
D 5
	if (uuc->uu_wcnt) {
E 5
I 5
D 9
	if (uuc->tu_wcnt) {
E 9
I 9
	if (uuc->tu_wcnt > 0) {
E 9
E 5
E 3
E 2
		/* still stuff to send, send one byte */
D 3
		while ((mfpr(CSTS) & READY) == 0)
E 3
I 3
		while ((uuaddr->tcs & UUCS_READY) == 0)
E 3
			;
D 2
		mtpr(CSTD, *tu.tu_wbptr++);
		tu.tu_wcnt--;
E 2
I 2
D 3
		mtpr(CSTD, *uu->uu_wbptr++);
		uu->uu_wcnt--;
E 3
I 3
D 5
		uuaddr->tdb = *uuc->uu_wbptr++;
		uuc->uu_wcnt--;
E 5
I 5
		uuaddr->tdb = *uuc->tu_wbptr++;
		uuc->tu_wcnt--;
E 5
E 3
E 2
		return;
	}
I 3
D 4
	data = &uudata[ctlr];
E 4
E 3

	/*
	 * Last message byte was sent out.
D 2
	 * Switch on tu_state of transfer.
E 2
I 2
D 5
	 * Switch on uu_state of transfer.
E 5
I 5
	 * Switch on tu_state of transfer.
E 5
E 2
	 */
D 2
	if (tudebug) {
		printf("tuxintr: state=");
		printstate(tu.tu_state);
E 2
I 2
D 5
	if (uudebug) {
		printf("uuxintr: state=");
D 3
		printstate(uu->uu_state);
E 3
I 3
		printstate(uuc->uu_state);
E 3
E 2
	}
D 2
	switch(tu.tu_state) {
E 2
I 2
D 3
	switch(uu->uu_state) {
E 3
I 3
	switch(uuc->uu_state) {
E 5
I 5
	switch(uuc->tu_state) {
E 5
E 3
E 2

	/*
	 * Two nulls have been sent, remove break, and send inits
	 */
D 3
	case TUS_INIT1:	
		mtpr(CSTS, IE);
E 3
I 3
D 5
	case UUS_INIT1:	
E 5
I 5
	case TUS_INIT1:	
I 9
		uuc->tu_flag = 0;
E 9
E 5
		uuaddr->tcs = UUCS_INTR;
E 3
D 5
		printd("ON2 ");
D 2
		tu.tu_state = TUS_INIT2;
		tu.tu_wbptr = tuinit;
		tu.tu_wcnt = sizeof (tuinit);
E 2
I 2
D 3
		uu->uu_state = TUS_INIT2;
		uu->uu_wbptr = uuinit;
		uu->uu_wcnt = sizeof (uuinit);
E 3
I 3
		uuc->uu_state = UUS_INIT2;
		uuc->uu_wbptr = uuinit;
		uuc->uu_wcnt = sizeof (uuinit);
E 5
I 5
		uuc->tu_state = TUS_INIT2;
		uuc->tu_wbptr = uuinit;
		uuc->tu_wcnt = sizeof (uuinit);
E 5
E 3
E 2
		goto top;

	/*
	 * Inits have been sent, wait for a continue msg.
	 */
D 3
	case TUS_INIT2:	
		(void) mfpr(CSRD);
		mtpr(CSRS, IE);
D 2
		tu.tu_flag = 1;
E 2
I 2
		uu->uu_flag = 1;
E 3
I 3
D 5
	case UUS_INIT2:	
E 5
I 5
	case TUS_INIT2:	
E 5
D 4
		c = uuaddr->rdb;		/* not used */
E 4
I 4
		c = uuaddr->rdb;	/* prevent overrun error */
E 4
		uuaddr->rcs = UUCS_INTR;
D 5
		uuc->uu_flag = 1;
E 5
I 5
		uuc->tu_flag = 1;
E 5
E 3
E 2
		break;

D 3
	case TUS_IDLE:		/* stray interrupt? */
E 3
I 3
D 5
	case UUS_IDLE:		/* stray interrupt? */
E 5
I 5
D 7
	case TUS_IDLE:		/* stray interrupt? */
E 5
E 3
		break;

E 7
	/*
	 * Read cmd packet sent, get ready for data
	 */
D 3
	case TUS_SENDR:
D 2
		tu.tu_state = TUS_GETH;
		tu.tu_rbptr = (u_char *)&tudata;
		tu.tu_rcnt = 2;
		tu.tu_flag = 1;
E 2
I 2
		uu->uu_state = TUS_GETH;
		uu->uu_rbptr = (u_char *)&uudata;
		uu->uu_rcnt = 2;
		uu->uu_flag = 1;
E 2
		mtpr(CSTS, 0);	/* disable transmitter interrupts */
E 3
I 3
D 5
	case UUS_SENDR:
		uuc->uu_state = UUS_GETH;
		uuc->uu_rbptr = (u_char *)data;
		uuc->uu_rcnt = 2;
		uuc->uu_flag = 1;
E 5
I 5
	case TUS_SENDR:
		uuc->tu_state = TUS_GETH;
		uuc->tu_rbptr = (u_char *)data;
		uuc->tu_rcnt = 2;
		uuc->tu_flag = 1;
E 5
D 9
		uuaddr->tcs = 0;	/* disable transmitter interrupts */
E 9
I 9
		uuaddr->tcs = 0;
E 9
E 3
D 5
		printd("OFF ");
E 5
I 5
		uuaddr->rcs = UUCS_INTR;
E 5
		break;

	/*
	 * Write cmd packet sent, wait for continue
	 */
D 3
	case TUS_SENDW:	
D 2
		tu.tu_state = TUS_WAIT;
		tu.tu_flag = 1;
E 2
I 2
		uu->uu_state = TUS_WAIT;
		uu->uu_flag = 1;
E 2
		if ((mfpr(CSRS)&IE) == 0) {
E 3
I 3
D 5
	case UUS_SENDW:	
		uuc->uu_state = UUS_WAIT;
		uuc->uu_flag = 1;
E 5
I 5
	case TUS_SENDW:	
		uuc->tu_state = TUS_WAIT;
		uuc->tu_flag = 1;
E 5
		if ((uuaddr->rcs&UUCS_INTR) == 0) {
E 3
			printf("NO IE\n");
D 3
			mtpr(CSRS, IE);
E 3
I 3
			uuaddr->rcs = UUCS_INTR;
E 3
		}
		break;

	/*
	 * Header sent, send data.
	 */
D 3
	case TUS_SENDH:
D 2
		tu.tu_state = TUS_SENDD;
		tu.tu_wbptr = (u_char *)tu.tu_addr;
		tu.tu_wcnt = tudata.pk_mcount;
E 2
I 2
		uu->uu_state = TUS_SENDD;
		uu->uu_wbptr = (u_char *)uu->uu_addr;
		uu->uu_wcnt = uudata.pk_mcount;
E 3
I 3
D 5
	case UUS_SENDH:
		uuc->uu_state = UUS_SENDD;
		uuc->uu_wbptr = (u_char *)uuc->uu_addr;
		uuc->uu_wcnt = data->pk_mcount;
E 5
I 5
	case TUS_SENDH:
		uuc->tu_state = TUS_SENDD;
		uuc->tu_wbptr = (u_char *)uuc->tu_addr;
		uuc->tu_wcnt = data->pk_mcount;
E 5
E 3
E 2
		goto top;

	/*
	 * Data sent, follow with checksum.
	 */
D 3
	case TUS_SENDD:	
D 2
		tu.tu_state = TUS_SENDC;
		tu.tu_wbptr = (u_char *)&tudata.pk_chksum;
		tu.tu_wcnt = sizeof tudata.pk_chksum;
E 2
I 2
		uu->uu_state = TUS_SENDC;
		uu->uu_wbptr = (u_char *)&uudata.pk_chksum;
		uu->uu_wcnt = sizeof uudata.pk_chksum;
E 3
I 3
D 5
	case UUS_SENDD:	
		uuc->uu_state = UUS_SENDC;
		uuc->uu_wbptr = (u_char *)&data->pk_chksum;
		uuc->uu_wcnt = sizeof (data->pk_chksum);
E 5
I 5
	case TUS_SENDD:	
		uuc->tu_state = TUS_SENDC;
		uuc->tu_wbptr = (u_char *)&data->pk_chksum;
D 9
		uuc->tu_wcnt = sizeof (data->pk_chksum);
E 9
I 9
		uuc->tu_wcnt = 2;
E 9
E 5
E 3
E 2
		goto top;

	/* 
	 * Checksum sent, wait for continue.
	 */
D 3
	case TUS_SENDC:
E 3
I 3
D 5
	case UUS_SENDC:
E 5
I 5
	case TUS_SENDC:
E 5
E 3
		/*
D 5
		 * Updata buffer address and count.
E 5
I 5
		 * Update buffer address and count.
E 5
		 */
D 2
		tu.tu_addr += tudata.pk_mcount;
		tu.tu_count -= tudata.pk_mcount;
		if (tu.tu_count) {
			tu.tu_state = TUS_WAIT;
			tu.tu_flag = 1;
E 2
I 2
D 3
		uu->uu_addr += uudata.pk_mcount;
		uu->uu_count -= uudata.pk_mcount;
		if (uu->uu_count) {
			uu->uu_state = TUS_WAIT;
			uu->uu_flag = 1;
E 3
I 3
D 5
		uuc->uu_addr += data->pk_mcount;
		uuc->uu_count -= data->pk_mcount;
		if (uuc->uu_count) {
			uuc->uu_state = UUS_WAIT;
			uuc->uu_flag = 1;
E 5
I 5
		uuc->tu_addr += data->pk_mcount;
		uuc->tu_count -= data->pk_mcount;
D 9
		if (uuc->tu_count) {
E 9
I 9
		if (uuc->tu_count > 0) {
E 9
			uuc->tu_state = TUS_WAIT;
			uuc->tu_flag = 1;
E 5
E 3
E 2
			break;
		}

		/*
		 * End of transmission, get ready for end packet.
		 */
D 2
		tu.tu_state = TUS_GET;
		tu.tu_rbptr = (u_char *)&tudata;
		tu.tu_rcnt = sizeof (tudata);
		tu.tu_flag = 1;
E 2
I 2
D 3
		uu->uu_state = TUS_GET;
		uu->uu_rbptr = (u_char *)&uudata;
		uu->uu_rcnt = sizeof (uudata);
		uu->uu_flag = 1;
E 2
		mtpr(CSTS, 0);
E 3
I 3
D 5
		uuc->uu_state = UUS_GET;
		uuc->uu_rbptr = (u_char *)data;
		uuc->uu_rcnt = sizeof (*data);
		uuc->uu_flag = 1;
E 5
I 5
		uuc->tu_state = TUS_GET;
		uuc->tu_rbptr = (u_char *)data;
		uuc->tu_rcnt = sizeof (*data);
		uuc->tu_flag = 1;
E 5
D 9
		uuaddr->tcs = 0;		/* disable transm. interrupts */
E 9
I 9
		uuaddr->tcs = 0;
E 9
E 3
D 5
		printd("OFF2 ");
E 5
		break;

	/*
D 3
	 * Random interrupt, probably from MRSP ACK
E 3
I 3
	 * Random interrupt
E 3
	 */
I 7
	case TUS_IDLE:		/* stray interrupt? */

E 7
	default:
		break;
	}
D 2
	if (tudebug) {
		printd("  new tu_state=");
		printstate(tu.tu_state);
E 2
I 2
D 5
	if (uudebug) {
		printd("  new uu_state=");
D 3
		printstate(uu->uu_state);
E 3
I 3
		printstate(uuc->uu_state);
I 4
		printf("\n");
E 5
I 5
}

uuwatch()
{
D 6
	register struct tu *uuc;
E 6
I 6
	register struct uu_softc *uuc;
E 6
	register struct uudevice *uuaddr;
	struct uba_device *ui;
	struct buf *bp, *uutab;
	int s, ctlr, active = 0;

	for (ctlr=0; ctlr<NUU; ctlr++) {
		int i;

		uuc = &uu_softc[ctlr];
I 9

		if (uuc->tu_dopen[0] || uuc->tu_dopen[1])
			active++;
		if (uuc->tu_flag == 0)
			/*
			 * If no read is in progress
			 * just skip
			 */
			continue;

E 9
		ui = uudinfo[ctlr];
		uuaddr = (struct uudevice *)ui->ui_addr;
		uutab = &uitab[ctlr];
D 9
		if ((uuc->tu_dopen[0] == 0) && (uuc->tu_dopen[1] == 0) && 
		    (uutab->b_active == 0)) {
I 7
			/*
			 * If both devices on this controller have
			 * been closed and the request queue is
			 * empty, mark ths controller not active
			 */
E 7
			uuc->tu_flag = 0;
			uuaddr->rcs = 0;
E 9
I 9
		if (uuc->tu_flag++ < 40)
E 9
			continue;
D 9
		}
		active++;
		if (uuc->tu_flag)
			uuc->tu_flag++;
		if (uuc->tu_flag <= 40)
			continue;
E 9
D 7
		printf("uu(%d): read stalled\n", ctlr);
E 7
I 7
		printf("uu%d: read stalled\n", uudata[ctlr].pk_unit);
I 8
D 9
#ifdef notdef
E 9
I 9
#ifdef UUDEBUG
E 9
E 8
E 7
		printf("%X %X %X %X %X %X %X\n", uuc->tu_rbptr, uuc->tu_rcnt,
D 7
		       uuc->tu_wbptr, uuc->tu_wcnt, uuc->tu_state, uuc->tu_addr, uuc->tu_count);
E 7
I 7
		       uuc->tu_wbptr, uuc->tu_wcnt, uuc->tu_state, uuc->tu_addr,
		       uuc->tu_count);
I 8
#endif
E 8
E 7
D 9
		uuc->tu_flag = 0;
E 9
		s = splx(UUIPL);
I 9
		uuc->tu_flag = 0;
E 9
		i = uuaddr->rdb;		/* dummy */
		uuaddr->rcs = UUCS_INTR;	/* in case we were flushing */
		uuaddr->tcs = UUCS_INTR;
		uuc->tu_state = TUS_IDLE;
		if (!uutab->b_active) {
			wakeup((caddr_t)uuc);
			goto retry;
		}
		if (++uutab->b_errcnt <= 1) {
			uustart(ui);
			goto retry;
		}
		if (bp = uutab->b_actf) {
			bp->b_flags |= B_ERROR;
			if ((bp->b_flags&B_READ) == 0)
D 9
				tu_vee(&pcnt[UNIT(minor(bp->b_dev))]);
E 9
I 9
				tu_vee(&uu_pcnt[UNIT(bp->b_dev)]);
E 9
			iodone(bp);
		}
retry:
		(void) splx(s);
E 5
E 4
E 3
E 2
	}
I 5
	if (active)
		timeout(uuwatch, (caddr_t)0, hz);
	else
		uuwstart = 0;
	return;
E 5
}

I 5
#if !defined(VAX750) && !defined(VAX730)
E 5
/*
 * Compute checksum TU58 fashion
 */
#ifdef lint
D 2
tuchk(word, cp, n)
E 2
I 2
D 5
uuchk(word, cp, n)
E 5
I 5
tuchk(word, cp, n)
E 5
E 2
	register word;
	register unsigned short *cp;
	int n;
{
	register int c = n >> 1;
	register long temp;

	do {
		temp = *cp++;	/* temp, only because vax cc won't *r++ */
		word += temp;
	} while (--c > 0);
	if (n & 1)
		word += *(unsigned char *)cp;
	while (word & 0xffff0000)
		word = (word & 0xffff) + ((word >> 16) & 0xffff);
	return (word);
}
#else
D 2
tuchk(word0, wp, n)
	register int word0;	/* r11 */
	register char *wp;	/* r10 */
	register int n;		/* r9 */
E 2
I 2
D 5
uuchk(word0, wp, n)
E 5
I 5
tuchk(word0, wp, n)
E 5
	register int word0;			/* r11 */
	register char *wp;			/* r10 */
	register int n;				/* r9 */
E 2
{
	asm("loop:");
D 2
	asm("	addw2	(r10)+,r11");	/* add a word to sum */
	asm("	adwc	$0,r11");	/* add in carry, end-around */
E 2
I 2
	asm("	addw2	(r10)+,r11");		/* add a word to sum */
	asm("	adwc	$0,r11");		/* add in carry, end-around */
E 2
	asm("	acbl	$2,$-2,r9,loop");	/* done yet? */
D 2
	asm("	blbc	r9,ok");	/* odd byte count? */
	asm("	movzbw	(r10),r10");	/* yes, get last byte */
	asm("	addw2	r10,r11");	/* add it in */
	asm("	adwc	$0,r11");	/* and the carry */
E 2
I 2
	asm("	blbc	r9,ok");		/* odd byte count? */
	asm("	movzbw	(r10),r10");		/* yes, get last byte */
	asm("	addw2	r10,r11");		/* add it in */
	asm("	adwc	$0,r11");		/* and the carry */
E 2
	asm("ok:");
D 2
	asm("	movl	r11,r0");	/* return sum */
E 2
I 2
	asm("	movl	r11,r0");		/* return sum */
E 2
}
#endif

I 9
/*
 * Make sure this incredibly slow device
 * doesn't eat up all the buffers in the
 * system by putting the requesting process
 * (remember: this device is 'single-user')
 * to sleep if the write-behind queue grows
 * larger than NUUQ.
 */
E 9
D 2
tuwatch()
E 2
I 2
D 5
uuwatch()
E 2
{
D 3
	register int s;
	register struct buf *bp;
E 3
I 3
	register struct uu_ctlr *uuc;
	register struct uudevice *uuaddr;
D 4
	struct uba_ctlr *um;
E 4
I 4
	struct uba_device *ui;
E 4
	struct buf *bp, *uutab;
	int s;
E 3

D 2
	if (tutimer == 0) {
		tu.tu_flag = 0;
E 2
I 2
D 3
	if (uutimer == 0) {
		uu->uu_flag = 0;
E 3
I 3
	if (uuwstart == 0)
E 3
E 2
		return;
I 3
D 4
	for (s=0; s<NDL; s++) {
E 4
I 4
	for (s=0; s<NUU; s++) {
E 4
		int i;

		uuc = &uu_ctlr[s];
D 4
		um = uuminfo[s];
E 4
I 4
		ui = uudinfo[s];
E 4
		if (uuc->uu_flag)
			uuc->uu_flag++;
		if (uuc->uu_flag <= 40)
			continue;
		printf("uu%d: read stalled\n", s);
		printf("%X %X %X %X %X %X %X %X\n", uuc->uu_rbptr, uuc->uu_rcnt,
		       uuc->uu_wbptr, uuc->uu_wcnt, uuc->uu_state, uuc->uu_flag,
		       uuc->uu_addr, uuc->uu_count);
		uuc->uu_flag = 0;
D 4
		uuaddr = (struct uudevice *)um->um_addr;
		uutab = &um->um_tab;
E 4
I 4
		uuaddr = (struct uudevice *)ui->ui_addr;
		uutab = &uitab[s];
E 4
		i = uuaddr->rdb;		/* dummy */
		uuaddr->rcs = UUCS_INTR;	/* in case we were flushing */
		uuaddr->tcs = UUCS_INTR;
		uuc->uu_state = UUS_IDLE;
		if (!uutab->b_active) {
			wakeup((caddr_t)uuc);
			continue;
		}
		if (++uutab->b_errcnt <= 1) {
D 4
			uustart(um);
E 4
I 4
			uustart(ui);
E 4
			continue;
		}
		if (bp = uutab->b_actf) {
			bp->b_flags |= B_ERROR;
			if ((bp->b_flags&B_READ) == 0)
D 4
				uu_vee(&pcnt[UNIT(bp->b_dev)]);
E 4
I 4
				uu_vee(&pcnt[UNIT(minor(bp->b_dev))]);
E 4
			iodone(bp);
		}
E 3
	}
D 2
	if (tu.tu_flag)
		tu.tu_flag++;
	if (tu.tu_flag <= 40) {
		timeout(tuwatch, (caddr_t)0, hz);
E 2
I 2
D 3
	if (uu->uu_flag)
		uu->uu_flag++;
	if (uu->uu_flag <= 40) {
		timeout(uuwatch, (caddr_t)0, hz);
E 2
		return;
E 3
I 3
	timeout(uuwatch, (caddr_t)0, hz);
	return;
}

I 4

uuioctl(dev, cmd, data, flag)
	dev_t dev;
	caddr_t data;
{
	/*
	 * to be added later
	 */
	return (ENXIO);
}

E 4
uu_pee(cp)
E 5
I 5
tu_pee(cp)
E 5
D 9
char *cp;
E 9
I 9
	char *cp;
E 9
{
	register int s;

D 4
	s = spl5();
E 4
I 4
	s = splx(UUIPL);
E 4
D 9
	if (++(*cp) > NTUQ) {
E 9
I 9
	if (++(*cp) > NUUQ) 
E 9
		sleep(cp, PRIBIO);
E 3
D 9
	}
E 9
D 2
	printf("tu: read stalled\n");
	printf("%X %X %X %X %X %X %X %X\n", tu.tu_rbptr, tu.tu_rcnt,
		tu.tu_wbptr, tu.tu_wcnt, tu.tu_state, tu.tu_flag,
		tu.tu_addr, tu.tu_count);
	tu.tu_flag = 0;
E 2
I 2
D 3
	printf("uu: read stalled\n");
	printf("%X %X %X %X %X %X %X %X\n", uu->uu_rbptr, uu->uu_rcnt,
		uu->uu_wbptr, uu->uu_wcnt, uu->uu_state, uu->uu_flag,
		uu->uu_addr, uu->uu_count);
	uu->uu_flag = 0;
E 2
	s = splx(TUIPL);
	(void) mfpr(CSRD);
	mtpr(CSRS, IE);		/* in case we were flushing */
	mtpr(CSTS, IE);
D 2
	tu.tu_state = TUS_IDLE;
	if (!tutab.b_active) {
		wakeup((caddr_t)&tu);
E 2
I 2
	uu->uu_state = TUS_IDLE;
	if (!uutab.b_active) {
		wakeup((caddr_t)&uu);
E 2
		goto retry;
E 3
I 3
	splx(s);
}

D 5
uu_vee(cp)
E 5
I 5
tu_vee(cp)
E 5
D 9
char *cp;
E 9
I 9
	char *cp;
E 9
{
	register int s;

D 4
	s = spl5();
E 4
I 4
	s = splx(UUIPL);
E 4
D 9
	if (--(*cp) <= NTUQ) {
E 9
I 9
	if (--(*cp) <= NUUQ) 
E 9
		wakeup(cp);
E 3
D 9
	}
E 9
D 2
	if (++tutab.b_errcnt <= 1) {
		tustart();
E 2
I 2
D 3
	if (++uutab.b_errcnt <= 1) {
		uustart();
E 2
		goto retry;
	}
D 2
	if (bp = tutab.b_actf) {
E 2
I 2
	if (bp = uutab.b_actf) {
E 2
		bp->b_flags |= B_ERROR;
		if ((bp->b_flags&B_READ) == 0)
D 2
			tu_vee(&pcnt[minor(bp->b_dev)&DNUM]);
E 2
I 2
			uu_vee(&pcnt[minor(bp->b_dev)&DNUM]);
E 2
		iodone(bp);
	}
retry:
E 3
	splx(s);
D 2
	timeout(tuwatch, (caddr_t)0, hz);
}

tu_pee(cp)
	char *cp;
{
	register int s;

	s = splx(TUIPL);
	if (++(*cp) > NTUQ)
		sleep(cp, PRIBIO);
	splx(s);
}

tu_vee(cp)
	char *cp;
{
	register int s;

	s = splx(TUIPL);
	if (--(*cp) <= NTUQ)
		wakeup(cp);
	splx(s);
E 2
I 2
D 3
	timeout(uuwatch, (caddr_t)0, hz);
E 3
E 2
}
I 5
#endif

uuioctl(dev, cmd, data, flag)
	dev_t dev;
	caddr_t data;
{
	/*
D 7
	 * to be added later
E 7
I 7
	 * add code to wind/rewind cassette here
E 7
	 */
	return (ENXIO);
}

E 5
D 9
#endif
I 3

E 9
I 6
uu_restart(ctlr, ui)
	int ctlr;
	struct uba_device *ui;
{
	uureset(ctlr);
	timeout(uustart, (caddr_t)ui, hz * 3);
}
I 9

#endif
E 9
E 6
E 3
E 1
