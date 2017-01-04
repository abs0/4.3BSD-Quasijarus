h05746
s 00001/00001/00731
d D 7.1 86/06/05 00:49:32 mckusick 33 32
c 4.3BSD release version
e
s 00011/00011/00721
d D 6.7 86/02/23 23:07:26 karels 32 31
c lint
e
s 00001/00000/00731
d D 6.6 86/02/19 22:15:28 karels 31 30
c lint
e
s 00007/00001/00724
d D 6.5 85/06/08 13:47:02 mckusick 30 29
c Add copyright
e
s 00010/00010/00715
d D 6.4 84/08/28 18:11:00 bloom 29 28
c Change to includes.  No more ../h
e
s 00001/00001/00724
d D 6.3 84/03/08 10:14:50 karels 28 27
c fix keywords
e
s 00001/00001/00724
d D 6.2 83/10/12 11:31:38 karels 27 26
c typo in tu_restart
e
s 00000/00000/00725
d D 6.1 83/07/29 07:21:28 sam 26 25
c 4.2 distribution
e
s 00094/00060/00631
d D 4.24 83/07/27 21:07:56 helge 25 23
c fixed close and watchdog routines and a number of other minor problems
e
s 00094/00060/00631
d R 4.24 83/07/27 21:05:14 helge 24 23
c fixed close and watchdog routines, and a number of other minor problems
e
s 00006/00006/00685
d D 4.23 83/07/21 15:14:40 helge 23 22
c changed pcnt to tu_pcnt to avoid conflict with the uu driver
e
s 00001/00001/00690
d D 4.22 83/07/18 14:06:12 helge 22 21
c fixed ifdef botch
e
s 00009/00009/00682
d D 4.21 83/07/07 11:38:51 sam 21 20
c silence some noise
e
s 00001/00001/00690
d D 4.20 83/06/17 22:01:26 helge 20 19
c ooops -- lost header in previous merge...
e
s 00006/00003/00685
d D 4.19 83/06/17 21:58:30 helge 19 18
c cleanup
e
s 00113/00063/00575
d D 4.18 83/06/16 16:59:22 helge 18 17
c removed debug printf's, seems to work ok ...
e
s 00001/00002/00637
d D 4.17 83/06/01 19:26:59 sam 17 16
c must give full path name
e
s 00003/00086/00636
d D 4.16 83/06/01 12:00:27 helge 16 15
c moved structs and constants related to the transfer protocol to tu58.h
e
s 00032/00015/00690
d D 4.15 83/05/08 17:10:35 helge 15 14
c changes per mike obrien
e
s 00001/00000/00704
d D 4.14 83/05/05 10:01:35 helge 14 13
c added missing state printout
e
s 00001/00000/00703
d D 4.13 83/02/10 18:43:07 sam 13 12
c hz not in systm.h anymore
e
s 00001/00001/00702
d D 4.12 82/11/13 22:59:04 sam 12 11
c merge of 4.1b with 4.1c
e
s 00006/00005/00697
d D 4.11 82/10/20 01:37:48 root 11 10
c lint
e
s 00007/00007/00695
d D 4.10 82/10/17 15:25:13 root 10 9
c fix lint
e
s 00004/00005/00698
d D 4.9 82/10/17 12:01:52 root 9 8
c return errors from open/ioctl routines; update conf table for
e
s 00003/00002/00700
d D 4.8 82/10/13 22:15:06 root 8 7
c rearrange header files
e
s 00275/00191/00427
d D 4.7 82/08/22 21:19:55 root 7 6
c fully uio()'d
e
s 00090/00032/00528
d D 4.6 82/05/27 16:43:26 sam 6 5
c mods from obrien at rand
e
s 00003/00005/00557
d D 4.5 82/05/26 15:44:17 sam 5 4
c 7ZZ -> 730
e
s 00006/00004/00556
d D 4.4 82/01/17 20:29:07 root 4 3
c remove spl0's from block tape routines
e
s 00005/00001/00555
d D 4.3 81/11/20 00:53:52 wnj 3 2
c lint
e
s 00057/00048/00499
d D 4.2 81/11/18 15:51:02 wnj 2 1
c lint
e
s 00547/00000/00000
d D 4.1 81/11/04 10:47:47 wnj 1 0
c date and time created 81/11/04 10:47:47 by wnj
e
u
U
t
T
I 1
D 6
/*	%M%	%E%	%I%	*/
E 6
I 6
D 19
/*	%M%	%I%	%E%	*/
E 19
I 19
D 20
/*	tu.c	4.18	83/06/16	*/
E 20
I 20
D 25
/*	%M%	%I%	%E%	*/
E 25
I 25
D 28
/*	%M	%I%	%E%	*/
E 28
I 28
D 30
/*	%M%	%I%	%E%	*/
E 30
I 30
/*
D 33
 * Copyright (c) 1982 Regents of the University of California.
E 33
I 33
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 33
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 30
E 28
E 25
E 20
E 19
E 6

D 5
#if defined(VAX750) || defined(VAX7ZZ)
E 5
I 5
#if defined(VAX750) || defined(VAX730)
E 5
/*
 * TU58 DECtape II device driver
 *
D 5
 * Bill Shannon - DEC - 01/12/81
 *
 * This driver controls the console TU58s on a VAX-11/750 or VAX-11/7ZZ.
E 5
I 5
D 18
 * This driver controls the console TU58s on a VAX-11/750 or VAX-11/730.
E 5
 * It could be easily modified for a Unibus TU58.  The TU58
 * is treated as a block device (only).  Error detection and
 * recovery is almost non-existant.  It is assumed that the
 * TU58 will follow the RSP protocol exactly, very few protocol
 * errors are checked for.  It is assumed that the 750 uses standard
D 5
 * RSP while the 7ZZ uses Modified RSP (MRSP).  At the time when 750's
E 5
I 5
 * RSP while the 730 uses Modified RSP (MRSP).  At the time when 750's
E 5
 * are converted to MRSP (by replacing EPROMS in the TU58), the tests
 * based on MRSP can be removed.
E 18
I 18
D 21
 * This driver controls the console TU58(s) on a VAX-11/750 or VAX-11/730.
 * The TU58 is treated as a block device (only).  The error detection and
E 21
I 21
 * TU58 console cassette driver (for VAX-11/750 or VAX-11/730).
 * The TU58 is treated as a block device (only).  Error detection and
E 21
 * recovery is not extensive, but sufficient for most situations. It is 
D 21
 * assumed that the TU58 will follow the RSP (or MRSP) protocol 
 * exactly, very few protocol errors are checked for.  
 * It is also assumed that the 730 uses Modified RSP
 * (MRSP), while the 750 may use either RSP or MRSP depending on
 * whether defined(MRSP) is true or not.
E 21
I 21
 * assumed that the TU58 will follow the RSP (or MRSP) protocol exactly,
 * very few protocol errors are checked for.  It is also assumed that
 * the 730 uses Modified RSP (MRSP), while the 750 may use either RSP
 * or MRSP depending on whether defined(MRSP) is true or not.
E 21
 * In the case of a 750 without MRSP, the only way for the CPU to
 * keep up with the tu58 is to lock out virtually everything else.
D 25
 * This is taken care of by a pseudo DMA routine in locore.s.
E 25
I 19
 *
D 21
 * NOTE: This driver will not work in multiuser mode 
 *	 unless MRSP is used!!
E 21
I 21
D 25
 * NOTE: This driver will not work multiuser without MRSP
E 25
I 25
 * NOTE: Reading large amounts of data from the tu58 is likely
 *	 to crash your system if you are running multiuser.
 *	 	******FOR SINGLE USER USE ONLY*****
E 25
E 21
E 19
E 18
 */
D 6
#define	NTU	((cpu == VAX_750) ? 1 : 2)

#define	MRSP	(cpu != VAX_750)

E 6
D 29
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/buf.h"
#include "../h/conf.h"
#include "../h/dir.h"
#include "../h/user.h"
I 13
#include "../h/kernel.h"
E 29
I 29
#include "param.h"
#include "systm.h"
#include "buf.h"
#include "conf.h"
#include "dir.h"
#include "user.h"
#include "kernel.h"
E 29
E 13
D 8
#include "../h/mtpr.h"
#include "../h/cpu.h"
E 8
I 8

D 29
#include "../vax/cpu.h"
#include "../vax/mtpr.h"
E 8
D 17

I 16
#include "tu58.h"
E 17
I 17
#include "../vax/rsp.h"
E 29
I 29
#include "cpu.h"
#include "mtpr.h"
#include "rsp.h"
E 29
E 17

E 16
#define	printd	if(tudebug) printf
#ifdef	printd
int	tudebug;	/* printd */
#endif	printd

I 6
#define	NTU	((cpu == VAX_750) ? 1 : 2)
D 18
#define DNUM    01      /* mask for drive number (should match NTU) */
I 7
D 12
#ifndef MRSP
E 12
I 12
#if !defined(MRSP) || lint
E 12
E 7
#define	MRSP	(cpu != VAX_750)
I 7
#endif
E 18
I 18
#define DNUM    01		/* mask for drive number (should match NTU) */
E 18
E 7
E 6
#define	NTUBLK	512		/* number of blocks on a TU58 cassette */
D 6

E 6
I 6
#define WRV     02              /* bit in minor dev => write w. read verify */
#define NTUQ    2               /* # of blocks which can be queued up */
E 6
D 32
#define	TUIPL	((cpu == VAX_750) ? 0x17 : 0x14)
E 32
I 32
#define	spltu()	((cpu == VAX_750) ? spl7() : spl4())
E 32

I 25
#ifndef MRSP
#define MRSP (cpu != VAX_750)
#endif

E 25
/*
I 18
 * State information 
 */
struct tu {
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
} tu;


/*
E 18
 * Device register bits
 */
#define	READY	0200		/* transmitter ready */
#define	DONE	0200		/* receiver done */
#define	IE	0100		/* interrupt enable */
#define	BREAK	1		/* send break */

D 16
/*
 * Structure of a command packet
 */
D 2

E 2
struct packet {
	u_char	pk_flag;	/* indicates packet type (cmd, data, etc.) */
	u_char	pk_mcount;	/* length of packet (bytes) */
	u_char	pk_op;		/* operation to perform (read, write, etc.) */
D 2
	u_char	pk_mod;		/* modifier for op or returned status */
E 2
I 2
D 6
	char	pk_mod;		/* modifier for op or returned status */
E 6
I 6
	u_char	pk_mod;		/* modifier for op or returned status */
E 6
E 2
	u_char	pk_unit;	/* unit number */
	u_char	pk_sw;		/* switches */
	u_short	pk_seq;		/* sequence number, always zero */
	u_short	pk_count;	/* requested byte count for read or write */
	u_short	pk_block;	/* block number for read, write, or seek */
	u_short	pk_chksum;	/* checksum, by words with end around carry */
};

E 16
struct packet tucmd;		/* a command sent to the TU58 */
struct packet tudata;		/* a command or data returned from TU58 */
I 16
D 18
struct tu tu;
E 18
E 16

D 16
/*
 * State information
 */
D 2

E 2
struct tu {
D 7
	u_char	*rbptr;		/* pointer to buffer for read */
	int	rcnt;		/* how much to read */
	u_char	*wbptr;		/* pointer to buffer for write */
	int	wcnt;		/* how much to write */
	int	state;		/* current state of tansfer operation */
	int	flag;		/* read in progress flag */
	char	*addr;		/* real buffer data address */
	int	count;		/* real requested count */
	int	serrs;		/* count of soft errors */
	int	cerrs;		/* count of checksum errors */
	int	herrs;		/* count of hard errors */
I 6
	char    dopen[2];       /* drive is open */
E 7
I 7
	u_char	*tu_rbptr;	/* pointer to buffer for read */
	int	tu_rcnt;	/* how much to read */
	u_char	*tu_wbptr;	/* pointer to buffer for write */
	int	tu_wcnt;	/* how much to write */
D 15
	int	tu_state;	/* current tu_state of tansfer operation */
E 15
I 15
	int	tu_state;	/* current state of tansfer operation */
E 15
	int	tu_flag;	/* read in progress flag */
	char	*tu_addr;	/* real buffer data address */
	int	tu_count;	/* real requested count */
	int	tu_serrs;	/* count of soft errors */
	int	tu_cerrs;	/* count of checksum errors */
	int	tu_herrs;	/* count of hard errors */
	char    tu_dopen[2];	/* drive is open */
E 7
E 6
} tu;

/*
 * States
 */
D 7
#define	INIT1	0		/* sending nulls */
#define	INIT2	1		/* sending inits */
#define	IDLE	2		/* initialized, no transfer in progress */
#define	SENDH	3		/* sending header */
#define	SENDD	4		/* sending data */
#define	SENDC	5		/* sending checksum */
#define	SENDR	6		/* sending read command packet */
#define	SENDW	7		/* sending write command packet */
#define	GETH	8		/* reading header */
#define	GETD	9		/* reading data */
#define	GETC	10		/* reading checksum */
#define	GET	11		/* reading an entire packet */
#define	WAIT	12		/* waiting for continue */
E 7
I 7
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
E 7

I 7
#define	TUS_NSTATES	13
E 16
char *tustates[TUS_NSTATES] = {
	"INIT1", "INIT2", "IDLE", "SENDH", "SENDD", "SENDC", "SENDR",
D 18
	"SENDW", "GETH", "GETD", "GETC", "GET", "WAIT"
E 18
I 18
	"SENDW", "GETH", "GETD", "GETC", "GET", "WAIT", "RCVERR", "CHKERR"
E 18
};
D 16
#define	printstate(state) \
	if ((state) < TUS_NSTATES) \
		printf("%s", tustates[(state)]); \
	else \
		printf("%d", (state));

E 7
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
#define	TUOP_INIT	1		/* initialize */
#define	TUOP_READ	2		/* read block */
#define	TUOP_WRITE	3		/* write block */
#define	TUOP_SEEK	5		/* seek to block */
#define TUOP_DIAGNOSE	7		/* run micro-diagnostics */
#define	TUOP_END	0100		/* end packet */

/*
I 6
 * Mod Flags
 */
#define TUMD_WRV        1               /* write with read verify */

/*
E 6
 * Switches
 */
#define	TUSW_MRSP	010		/* use Modified RSP */
E 16

u_char	tunull[2] = { 0, 0 };	/* nulls to send for initialization */
u_char	tuinit[2] = { TUF_INITF, TUF_INITF };	/* inits to send */
D 6

E 6
I 6
D 23
static char pcnt[2];            /* pee/vee counters */
E 23
I 23
static char tu_pcnt[2];            		/* pee/vee counters */
E 23
E 6
int	tutimer = 0;
I 25
int	tuwake();
E 25
D 6

E 6
D 23
struct buf tutab;		/* I/O queue header */
E 23
I 23
struct buf tutab;				/* I/O queue header */
E 23

/*
 * Open the TU58
 */
D 2

E 2
I 2
/*ARGSUSED*/
E 2
tuopen(dev, flag)
{
	extern int tuwatch();
I 4
	register s;
E 4

I 2
#ifdef lint
	turintr(); tuwintr();
#endif
E 2
D 6
	if (minor(dev) >= NTU) {
E 6
I 6
D 7
	if ((minor(dev)&DNUM) >= NTU || tu.dopen[minor(dev)&DNUM]) {
E 7
I 7
D 9
	if ((minor(dev)&DNUM) >= NTU || tu.tu_dopen[minor(dev)&DNUM]) {
E 7
E 6
		u.u_error = ENXIO;
		return;
	}
E 9
I 9
D 25
	if ((minor(dev)&DNUM) >= NTU || tu.tu_dopen[minor(dev)&DNUM])
E 25
I 25
	if ((minor(dev)&DNUM) >= NTU)
E 25
		return (ENXIO);
E 9
D 25
	if (tutimer == 0) {
		tutimer++;
E 25
I 25
	if (tu.tu_dopen[minor(dev)&DNUM])
		return (EBUSY);
	if (tutimer++ == 0)
E 25
		timeout(tuwatch, (caddr_t)0, hz);
D 25
	}
I 6
D 7
	tu.dopen[minor(dev)&DNUM]++;
E 7
I 7
	tu.tu_dopen[minor(dev)&DNUM]++;
E 25
I 25

E 25
E 7
E 6
D 4
	splx(TUIPL);
E 4
I 4
D 32
	s = splx(TUIPL);
E 32
I 32
	s = spltu();
E 32
I 25
	tu.tu_dopen[minor(dev)&DNUM]++;
E 25
E 4
D 7
	if (tu.state != IDLE) {
		tureset();
D 6
		sleep((caddr_t)&tu, PZERO);
E 6
I 6
		sleep((caddr_t)&tu, PZERO+1);
E 6
		tutab.b_active = NULL;
D 2
		if (tu.state != IDLE) {	/* couldn't initialize */
E 2
I 2
		if (tu.state != IDLE) {		/* couldn't initialize */
E 2
			u.u_error = ENXIO;
			tu.state = INIT1;
I 6
			tu.dopen[minor(dev)&DNUM] = 0;
E 6
			tu.rcnt = tu.wcnt = 0;
			mtpr(CSTS, 0);
			mtpr(CSRS, 0);
		}
	} else
E 7
I 7
	/*
	 * If the cassette's already initialized,
	 * just enable interrupts and return.
	 */
	if (tu.tu_state == TUS_IDLE) {
E 7
		mtpr(CSRS, IE);
I 7
D 18
		splx(s);
D 9
		return;
E 9
I 9
		return (0);
E 18
I 18
		goto ok;
E 18
E 9
	}

	/* 
	 * Must initialize, reset the cassette
	 * and wait for things to settle down.
	 */
	tureset();
	sleep((caddr_t)&tu, PZERO+1);
	tutab.b_active = NULL;
	if (tu.tu_state != TUS_IDLE) {
D 18
		u.u_error = ENXIO;
E 18
		tu.tu_state = TUS_INIT1;
		tu.tu_dopen[minor(dev)&DNUM] = 0;
		tu.tu_rcnt = tu.tu_wcnt = 0;
		mtpr(CSTS, 0);
		mtpr(CSRS, 0);
I 18
		splx(s);
		return (EIO);
E 18
	}
I 18
ok:
E 18
E 7
D 4
	spl0();
E 4
I 4
	splx(s);
I 9
	return (0);
E 9
E 4
}

/*
D 25
 * Close the TU58
E 25
I 25
 * Close the TU58, but make sure all
 * outstanding i/o is complete first..
E 25
 */
I 31
/* ARGSUSED */
E 31
D 2

E 2
D 25
tuclose(dev)
E 25
I 25
tuclose(dev, flag)
	dev_t dev;
	int flag;
E 25
{
I 25
	int s, unit = minor(dev);
	struct buf *bp, *last = NULL;
E 25
I 2

E 2
D 25
	if (tutab.b_active == 0) {
		mtpr(CSRS, 0);
E 25
I 25
D 32
	s = splx(TUIPL);
E 32
I 32
	s = spltu();
E 32
	while (tu_pcnt[unit])
		sleep(&tu_pcnt[unit], PRIBIO);
	/*
	 * No more writes are pending, scan the 
	 * buffer queue for oustanding reads from
	 * this unit.
	 */
	for (bp = tutab.b_actf; bp; bp = bp->b_actf) {
		if (bp->b_dev == dev)
			last = bp;
	}
	if (last) {
		last->b_flags |= B_CALL;
		last->b_iodone = tuwake;
		sleep((caddr_t)last, PRIBIO);
	}
	tu.tu_dopen[unit&DNUM] = 0;
	if (!tu.tu_dopen[0] && !tu.tu_dopen[1]) {
E 25
		tutimer = 0;
I 25
		mtpr(CSRS, 0);
		tu.tu_flag = 0;
E 25
	}
D 7
	if (tu.serrs + tu.cerrs + tu.herrs != 0) {	/* any errors ? */
E 7
I 7
D 18
	if (tu.tu_serrs + tu.tu_cerrs + tu.tu_herrs != 0) {
		/*
		 * A tu58 is like nothing ever seen before;
		 * I guess this is appropriate then...
		 */
E 7
D 6
		uprintf("tu%d: %d soft errors, %d chksum errors, %d hard errors\n",
E 6
I 6
		uprintf(
		   "tu%d: %d soft errors, %d chksum errors, %d hard errors\n",
E 6
D 7
			minor(dev), tu.serrs, tu.cerrs, tu.herrs);
		tu.serrs = tu.cerrs = tu.herrs = 0;
E 7
I 7
			minor(dev), tu.tu_serrs, tu.tu_cerrs, tu.tu_herrs);
		tu.tu_serrs = tu.tu_cerrs = tu.tu_herrs = 0;
E 7
	}
E 18
I 6
D 7
	tu.dopen[minor(dev)&DNUM] = 0;
E 7
I 7
D 25
	tu.tu_dopen[minor(dev)&DNUM] = 0;
E 25
I 25
	splx(s);
E 25
E 7
E 6
}

I 25
tuwake(bp)
	struct buf *bp;
{
D 32
	wakeup(bp);
E 32
I 32
	wakeup((caddr_t)bp);
E 32
}

E 25
/*
 * Reset the TU58
 */
D 2

E 2
tureset()
{
I 2

I 25
	mtpr(CSRS, 0);
E 25
E 2
D 7
	tu.state = INIT1;
	tu.wbptr = tunull;
	tu.wcnt = sizeof tunull;
E 7
I 7
	tu.tu_state = TUS_INIT1;
	tu.tu_wbptr = tunull;
	tu.tu_wcnt = sizeof (tunull);
E 7
	tucmd.pk_flag = TUF_CMD;
D 7
	tucmd.pk_mcount = sizeof tucmd - 4;
E 7
I 7
	tucmd.pk_mcount = sizeof (tucmd) - 4;
E 7
	tucmd.pk_mod = 0;
	tucmd.pk_seq = 0;
D 18
	tucmd.pk_sw = MRSP ? TUSW_MRSP : 0;
E 18
I 18
D 25
#ifdef MRSP
	tucmd.pk_sw = TUSW_MRSP;
#else
	tucmd.pk_sw = 0;
#endif
E 25
I 25
	tucmd.pk_sw = MRSP ? TUSW_MRSP : 0;
E 25
E 18
	tutab.b_active++;
D 25
	mtpr(CSRS, 0);
E 25
D 19
	mtpr(CSTS, IE|BREAK);
	tuxintr();		/* start output */
E 19
I 19
	mtpr(CSTS, IE | BREAK);
	tuxintr();			/* start output */
E 19
D 7
	return;
E 7
}

/*
 * Strategy routine for block I/O
 */
D 2

E 2
tustrategy(bp)
D 2
register struct buf *bp;
E 2
I 2
	register struct buf *bp;
E 2
{
I 4
	register int s;
E 4
I 2

E 2
D 7
	if (bp->b_blkno >= NTUBLK) {	/* block number out of range? */
E 7
I 7
	if (bp->b_blkno >= NTUBLK) {
E 7
		bp->b_flags |= B_ERROR;
		iodone(bp);
		return;
	}
I 6
	if ((bp->b_flags&B_READ) == 0)
D 23
		tu_pee(&pcnt[minor(bp->b_dev)&DNUM]);
E 23
I 23
		tu_pee(&tu_pcnt[minor(bp->b_dev)&DNUM]);
E 23
E 6
	bp->av_forw = NULL;
D 4
	splx(TUIPL);
E 4
I 4
D 32
	s = splx(TUIPL);
E 32
I 32
	s = spltu();
E 32
E 4
	if (tutab.b_actf == NULL)
		tutab.b_actf = bp;
	else
		tutab.b_actl->av_forw = bp;
	tutab.b_actl = bp;
	if (tutab.b_active == NULL)
		tustart();
D 4
	spl0();
E 4
I 4
	splx(s);
E 4
}

/*
 * Start the transfer
 */
D 2

E 2
tustart()
{
	register struct buf *bp;
I 25
	int s;
E 25

D 2
    top:
E 2
	if ((bp = tutab.b_actf) == NULL)
		return;
I 25
D 32
	s = splx(TUIPL);
E 32
I 32
	s = spltu();
E 32
E 25
D 7
	if (tu.state != IDLE) {
E 7
I 7
	if (tu.tu_state != TUS_IDLE) {
E 7
		tureset();
I 25
		splx(s);
E 25
		return;
	}
	tutab.b_active++;
	tutab.b_errcnt = 0;
	tucmd.pk_op = bp->b_flags&B_READ ? TUOP_READ : TUOP_WRITE;
D 6
	tucmd.pk_unit = minor(bp->b_dev);
E 6
I 6
	tucmd.pk_mod = ((bp->b_flags&B_READ) == 0 && (minor(bp->b_dev)&WRV)) ?
	    TUMD_WRV : 0;
	tucmd.pk_unit = (minor(bp->b_dev)&DNUM);
D 18
	tucmd.pk_sw = MRSP ? TUSW_MRSP : 0;
E 18
I 18
D 25
#ifdef MRSP
	tucmd.pk_sw = TUSW_MRSP;
#else
	tucmd.pk_sw = 0;
#endif
E 25
I 25
	tucmd.pk_sw = MRSP ? TUSW_MRSP : 0;
E 25
E 18
E 6
D 7
	tucmd.pk_count = tu.count = bp->b_bcount;
E 7
I 7
	tucmd.pk_count = tu.tu_count = bp->b_bcount;
E 7
	tucmd.pk_block = bp->b_blkno;
D 2
	tucmd.pk_chksum = tuchk(*((short *)&tucmd), &tucmd.pk_op,
			tucmd.pk_mcount);
E 2
I 2
	tucmd.pk_chksum =
D 11
	    tuchk(*((short *)&tucmd), (caddr_t)&tucmd.pk_op,
E 11
I 11
	    tuchk(*((short *)&tucmd), (u_short *)&tucmd.pk_op,
E 11
		(int)tucmd.pk_mcount);
E 2
D 7
	tu.state = bp->b_flags&B_READ ? SENDR : SENDW;
	tu.addr = bp->b_un.b_addr;
	tu.count = bp->b_bcount;
	tu.wbptr = (u_char *)&tucmd;
	tu.wcnt = sizeof tucmd;
E 7
I 7
	tu.tu_state = bp->b_flags&B_READ ? TUS_SENDR : TUS_SENDW;
	tu.tu_addr = bp->b_un.b_addr;
D 18
	tu.tu_count = bp->b_bcount;
E 18
	tu.tu_wbptr = (u_char *)&tucmd;
	tu.tu_wcnt = sizeof (tucmd);
E 7
	tuxintr();
I 25
	splx(s);
E 25
}

/*
 * TU58 receiver interrupt
 */
D 2

E 2
turintr()
{
	register struct buf *bp;
	register int c;

D 18
	c = mfpr(CSRD)&0xff;		/* get the char, clear the interrupt */
	if (MRSP) {
		while ((mfpr(CSTS)&READY) == 0)
			;
		mtpr(CSTD, TUF_CONT);	/* ACK */
E 18
I 18
	c = mfpr(CSRD)&0xff;
D 25
#ifdef MRSP
	while ((mfpr(CSTS)&READY) == 0)
		;
	mtpr(CSTD, TUF_CONT);			/* ACK */
	if (tu.tu_rcnt) {
		*tu.tu_rbptr++ = c;
		if (--tu.tu_rcnt)
			return;
E 25
I 25
	if (MRSP) {
		while ((mfpr(CSTS)&READY) == 0)
			;
		mtpr(CSTD, TUF_CONT);			/* ACK */
		if (tu.tu_rcnt) {
			*tu.tu_rbptr++ = c;
			if (--tu.tu_rcnt)
				return;
		}
E 25
E 18
	}
I 15
D 18
top:
E 15
D 2
	if (tu.rcnt) {		/* still waiting for data? */
E 2
I 2
D 7
	if (tu.rcnt) {			/* still waiting for data? */
E 2
		*tu.rbptr++ = c;	/* yup, put it there */
D 2
		if (--tu.rcnt)	/* decrement count, any left? */
			return;	/* get some more */
E 2
I 2
		if (--tu.rcnt)		/* decrement count, any left? */
E 7
I 7
	if (tu.tu_rcnt) {		/* still waiting for data? */
		*tu.tu_rbptr++ = c;	/* yup, put it there */
		if (--tu.tu_rcnt)	/* decrement count, any left? */
E 7
			return;		/* get some more */
E 2
	}
E 18
I 18
D 25
#endif
E 25
E 18

	/*
D 18
	 * We got all the data we were expecting for now,
D 7
	 * switch on the state of the transfer.
E 7
I 7
D 15
	 * switch on the tu_state of the transfer.
E 15
I 15
	 * switch on the state of the transfer.
E 18
I 18
	 * Switch on the state of the transfer.
E 18
E 15
E 7
	 */
D 2

E 2
D 7
	switch(tu.state) {
E 7
I 7
	switch(tu.tu_state) {
E 7
I 2

I 18
D 25
#ifndef MRSP
E 25
E 18
E 2
D 7
	case INIT2:
		if (c == TUF_CONT)	/* did we get the expected continue? */
			tu.state = IDLE;
		else
			tu.state = INIT1;	/* bad news... */
		tu.flag = 0;
E 7
I 7
	/*
I 18
	 * Probably an overrun error,
	 * cannot happen if MRSP is used
	 */
	case TUS_RCVERR:
D 25
		printf(" overrun, recovered ");		/* DEBUG */
E 25
I 25
		mtpr(CSRS, 0);					/* flush */
		printf("overrun error, transfer restarted\n");	/* DEBUG */
E 25
		tu.tu_serrs++;
		tu_restart();
		break;
D 25
#endif
E 25

	/*
E 18
	 * If we get an unexpected "continue",
	 * start all over again...
	 */
	case TUS_INIT2:
		tu.tu_state = c == TUF_CONT ? TUS_IDLE : TUS_INIT1;
		tu.tu_flag = 0;
E 7
		wakeup((caddr_t)&tu);
		tustart();
		break;

D 7
	case WAIT:			/* waiting for continue */
E 7
I 7
	/*
	 * Only transition from this state
	 * is on a "continue", so if we don't
	 * get it, reset the world.
	 */
	case TUS_WAIT:			/* waiting for continue */
E 7
D 15
		if (c != TUF_CONT) {
E 15
I 15
		switch(c) {
		case TUF_CONT:  /* got the expected continue */
			tu.tu_flag = 0;
			tudata.pk_flag = TUF_DATA;
			tudata.pk_mcount = MIN(128, tu.tu_count);
			tudata.pk_chksum =
D 32
			    tuchk(*((short *)&tudata), (caddr_t)tu.tu_addr,
E 32
I 32
			    tuchk(*((short *)&tudata), (u_short *)tu.tu_addr,
E 32
				(int)tudata.pk_mcount);
			tu.tu_state = TUS_SENDH;
			tu.tu_wbptr = (u_char *)&tudata;
			tu.tu_wcnt = 2;
			tuxintr();
			break;

		case TUF_CMD:   /* sending us an END packet...error */
			tu.tu_state = TUS_GET;
			tu.tu_rbptr = (u_char *) &tudata;
D 18
			tu.tu_rcnt = sizeof (tudata);
E 18
I 18
			tu.tu_rcnt = sizeof (tudata) - 1;
E 18
			tu.tu_flag = 1;
			mtpr (CSTS, 0);
D 18
			goto top;
E 18
I 18
			*tu.tu_rbptr = c;
			break;
E 18

		case TUF_INITF:
			tureset();
			break;

		default:        /* something random...bad news */
E 15
D 7
			tu.state = INIT1;	/* bad news... */
E 7
I 7
			tu.tu_state = TUS_INIT1;
E 7
			break;
		}
D 7
		tu.flag = 0;
E 7
I 7
D 15
		tu.tu_flag = 0;
E 7
		tudata.pk_flag = TUF_DATA;
D 2
		tudata.pk_mcount = min(128, tu.count);
		tudata.pk_chksum = tuchk(*((short *)&tudata), tu.addr,
					tudata.pk_mcount);
E 2
I 2
D 7
		tudata.pk_mcount = MIN(128, tu.count);
E 7
I 7
		tudata.pk_mcount = MIN(128, tu.tu_count);
E 7
		tudata.pk_chksum =
D 7
		    tuchk(*((short *)&tudata), (caddr_t)tu.addr,
E 7
I 7
D 11
		    tuchk(*((short *)&tudata), (caddr_t)tu.tu_addr,
E 11
I 11
		    tuchk(*((short *)&tudata), (u_short *)tu.tu_addr,
E 11
E 7
			(int)tudata.pk_mcount);
E 2
D 7
		tu.state = SENDH;
		tu.wbptr = (u_char *)&tudata;
		tu.wcnt = 2;
E 7
I 7
		tu.tu_state = TUS_SENDH;
		tu.tu_wbptr = (u_char *)&tudata;
		tu.tu_wcnt = 2;
E 7
		tuxintr();
E 15
		break;

I 6
D 7
	case SENDW:
		if (c == TUF_CONT) {
			tureset();
			break;
		} else
E 7
I 7
	case TUS_SENDW:
D 15
		if (c != TUF_CONT)
E 15
I 15
		if (c != TUF_CONT && c != TUF_INITF) 
E 15
E 7
			goto bad;
I 7
		tureset();
		break;
E 7

E 6
D 7
	case GETH:		/* got header, get data */
D 2
		if (tudata.pk_flag == TUF_DATA)	/* is it a data message? */
			tu.rbptr = (u_char *)tu.addr;	/* yes, put it in buffer */
		tu.rcnt = tudata.pk_mcount;	/* amount to get */
E 2
I 2
		if (tudata.pk_flag == TUF_DATA)		/* data message? */
			tu.rbptr = (u_char *)tu.addr;	/* yes put in buffer */
		tu.rcnt = tudata.pk_mcount;		/* amount to get */
E 2
		tu.state = GETD;
E 7
I 7
	/*
	 * Got header, now get data; amount to
D 18
	 * fetch is include in packet.
E 18
I 18
	 * fetch is included in packet.
E 18
	 */
	case TUS_GETH:
I 18
D 25
#ifdef MRSP
E 18
		if (tudata.pk_flag == TUF_DATA)
E 25
I 25
		if (MRSP && (tudata.pk_flag == TUF_DATA))
E 25
			tu.tu_rbptr = (u_char *)tu.tu_addr;
I 18
D 25
#endif
E 25
E 18
		tu.tu_rcnt = tudata.pk_mcount;
		tu.tu_state = TUS_GETD;
E 7
		break;

D 7
	case GETD:		/* got data, get checksum */
		tu.rbptr = (u_char *)&tudata.pk_chksum;
		tu.rcnt = sizeof tudata.pk_chksum;
		tu.state = GETC;
E 7
I 7
	/*
	 * Got the data, now fetch the checksum.
	 */
	case TUS_GETD:
		tu.tu_rbptr = (u_char *)&tudata.pk_chksum;
		tu.tu_rcnt = sizeof (tudata.pk_chksum);
		tu.tu_state = TUS_GETC;
E 7
		break;

I 18
D 25
#ifdef MRSP
E 25
I 25
	case TUS_CHKERR:		/* from tudma only */
		tu.tu_cerrs++;
		goto tus_get;

E 25
E 18
D 7
	case GET:
	case GETC:		/* got entire packet */
E 7
I 7
	case TUS_GET:
I 18
D 25
#endif
E 25
I 25
		if (MRSP)
			/* 
		 	 * The checksum has already been calculated and
		 	 * verified in the pseudo DMA routine
		 	 */
			goto tus_get;

E 25
E 18
	case TUS_GETC:
		/* got entire packet */
E 7
D 18
#ifdef notdef
E 18
D 2
		if (tuchk(*((short *)&tudata), tudata.pk_flag == TUF_DATA ? tu.addr 
		    : &tudata.pk_op, tudata.pk_mcount) != tudata.pk_chksum)
E 2
I 2
		if (tudata.pk_chksum !=
D 11
		    tuchk(*((short *)&tudata),
D 7
		     tudata.pk_flag == TUF_DATA ? tu.addr : &tudata.pk_op,
E 7
I 7
		     tudata.pk_flag == TUF_DATA ? tu.tu_addr : &tudata.pk_op,
E 11
I 11
		    tuchk(*((short *)&tudata), (u_short *)
D 18
		     (tudata.pk_flag == TUF_DATA ? tu.tu_addr : &tudata.pk_op),
E 18
I 18
		     (tudata.pk_flag == TUF_DATA ? 
		     (u_short *) tu.tu_addr : (u_short *)&tudata.pk_op),
E 18
E 11
E 7
		     (int)tudata.pk_mcount))
I 18
D 25
	case TUS_CHKERR:
E 25
E 18
E 2
D 7
			tu.cerrs++;
E 7
I 7
			tu.tu_cerrs++;
I 18
D 25
#ifndef MRSP
	case TUS_GET:
		/* 
		 * The checksum has already been calculated and
		 * verified in the pseudo DMA routine
		 */
E 18
E 7
#endif
E 25
I 25
tus_get:
E 25
D 2
		if (tudata.pk_flag == TUF_DATA) {	/* was it a data packet? */
			tu.addr += tudata.pk_mcount;	/* update buf addr */
			tu.count -= tudata.pk_mcount;	/* and byte count */
E 2
I 2
		if (tudata.pk_flag == TUF_DATA) {
			/* data packet, advance to next */
D 7
			tu.addr += tudata.pk_mcount;
			tu.count -= tudata.pk_mcount;
E 2
			tu.state = GETH;
			tu.rbptr = (u_char *)&tudata;	/* next packet */
			tu.rcnt = 2;
E 7
I 7
			tu.tu_addr += tudata.pk_mcount;
			tu.tu_count -= tudata.pk_mcount;
			tu.tu_state = TUS_GETH;
			tu.tu_rbptr = (u_char *)&tudata; /* next packet */
			tu.tu_rcnt = 2;
E 7
D 2
		} else				/* was it an end packet? */
		if (tudata.pk_flag == TUF_CMD && tudata.pk_op == TUOP_END) {
			tu.state = IDLE;		/* all done reading */
E 2
I 2
		} else if (tudata.pk_flag==TUF_CMD && tudata.pk_op==TUOP_END) {
			/* end packet, idle and reenable transmitter */
D 7
			tu.state = IDLE;
E 2
			tu.flag = 0;
E 7
I 7
			tu.tu_state = TUS_IDLE;
			tu.tu_flag = 0;
E 7
D 2
			mtpr(CSTS, IE);		/* reenable transmitter */
E 2
I 2
			mtpr(CSTS, IE);
E 2
			printd("ON ");
			if ((bp = tutab.b_actf) == NULL) {
D 7
				printf("tu: no bp!\n");
				printf("active %d\n", tutab.b_active);
E 7
I 7
D 18
				printf("tu: no bp, active %d\n",tutab.b_active);
E 18
I 18
				printf("tu%d: no bp, active %d\n",
					tudata.pk_unit, tutab.b_active);
E 18
E 7
				tustart();
				return;
			}
D 6
			if (tudata.pk_mod < 0) {	/* hard error */
E 6
I 6
			if (tudata.pk_mod > 1) {        /* hard error */
E 6
				bp->b_flags |= B_ERROR;
D 7
				tu.herrs++;
E 7
I 7
				tu.tu_herrs++;
E 7
D 18
				harderr(bp, "tu");
E 18
I 18
				printf("tu%d: hard error bn%d,", 
					minor(bp->b_dev)&DNUM, bp->b_blkno);
E 18
D 6
				printf("  pk_mod %d\n", -tudata.pk_mod);
E 6
I 6
				printf("  pk_mod %o\n", tudata.pk_mod&0377);
E 6
D 10
			} else if (tudata.pk_mod > 0)	/* soft error */
E 10
I 10
			} else if (tudata.pk_mod != 0)	/* soft error */
E 10
D 7
				tu.serrs++;
E 7
I 7
				tu.tu_serrs++;
E 7
			tutab.b_active = NULL;
			tutab.b_actf = bp->av_forw;
D 7
			bp->b_resid = tu.count;
E 7
I 7
			bp->b_resid = tu.tu_count;
E 7
I 6
			if ((bp->b_flags&B_READ) == 0)
D 23
				tu_vee(&pcnt[minor(bp->b_dev)&DNUM]);
E 23
I 23
				tu_vee(&tu_pcnt[minor(bp->b_dev)&DNUM]);
E 23
E 6
			iodone(bp);
			tustart();
		} else {
D 18
			printf("neither data nor end: %o %o\n",
D 2
				tudata.pk_flag&0xff, tudata.pk_op&0xff);
E 2
I 2
			    tudata.pk_flag&0xff, tudata.pk_op&0xff);
E 18
I 18
			/*
			 * Neither data nor end: data was lost
			 * somehow, restart the transfer
			 */
E 18
E 2
			mtpr(CSRS, 0);		/* flush the rest */
D 7
			tu.state = INIT1;
E 7
I 7
D 18
			tu.tu_state = TUS_INIT1;
E 18
I 18
			tu_restart();
			tu.tu_serrs++;
E 18
E 7
		}
		break;

D 7
	case IDLE:
	case INIT1:
E 7
I 7
	case TUS_IDLE:
	case TUS_INIT1:
E 7
		break;

I 6
D 7
	bad:
E 7
E 6
D 2
	default:		/* what are we doing here??? */
E 2
I 2
	default:
I 7
bad:
E 7
E 2
		if (c == TUF_INITF) {
D 7
			printf("TU protocol error, state %d\n", tu.state);
D 2
			printf("%o %d %d\n", tucmd.pk_op, tucmd.pk_count, tucmd.pk_block);
E 2
I 2
			printf("%o %d %d\n",
E 7
I 7
D 18
			printf("tu protocol error, state=");
E 18
I 18
			printf("tu%d protocol error, state=", 
							(int)tudata.pk_unit);
E 18
			printstate(tu.tu_state);
			printf(", op=%x, cnt=%d, block=%d\n",
E 7
			    tucmd.pk_op, tucmd.pk_count, tucmd.pk_block);
E 2
			tutab.b_active = NULL;
			if (bp = tutab.b_actf) {
				bp->b_flags |= B_ERROR;
				tutab.b_actf = bp->av_forw;
I 6
				if ((bp->b_flags&B_READ) == 0)
D 23
					tu_vee(&pcnt[minor(bp->b_dev)&DNUM]);
E 23
I 23
					tu_vee(&tu_pcnt[minor(bp->b_dev)&DNUM]);
E 23
E 6
				iodone(bp);
			}
D 7
			tu.state = INIT1;
E 7
I 7
			tu.tu_state = TUS_INIT1;
E 7
		} else {
D 7
			printf("TU receive state error %d %o\n", tu.state, c);
		/*	tu.state = INIT1; */
E 7
I 7
D 18
			printf("tu receive state error, state=");
E 18
I 18
			printf("tu%d: receive state error, state=",
						(int)tudata.pk_unit);
E 18
I 14
			printstate(tu.tu_state);
E 14
D 18
			printf(", byte=%x\n", c);
E 18
I 18
			printf(", byte=%x\n", c & 0xff);
E 18
D 25
#ifdef notdef
D 18
			tu.tu_state = TUS_INIT1; */
E 18
I 18
			tu.tu_state = TUS_INIT1;
E 18
#endif
E 7
			wakeup((caddr_t)&tu);
E 25
I 25
			if (tutab.b_actf)
				tu_restart();
			else
				wakeup((caddr_t)&tu);
E 25
		}
	}
}

/*
 * TU58 transmitter interrupt
 */
D 2

E 2
tuxintr()
{
D 2
    top:
	if (tu.wcnt) {			/* still stuff to send out? */
E 2
I 2

top:
D 7
	if (tu.wcnt) {
E 7
I 7
	if (tu.tu_wcnt) {
E 7
		/* still stuff to send, send one byte */
E 2
		while ((mfpr(CSTS) & READY) == 0)
			;
D 2
		mtpr(CSTD, *tu.wbptr++);	/* yup, send another byte */
		tu.wcnt--;		/* decrement count */
E 2
I 2
D 7
		mtpr(CSTD, *tu.wbptr++);
		tu.wcnt--;
E 7
I 7
		mtpr(CSTD, *tu.tu_wbptr++);
		tu.tu_wcnt--;
E 7
E 2
		return;
	}

	/*
	 * Last message byte was sent out.
D 7
	 * Switch on state of transfer.
E 7
I 7
D 15
	 * Switch on tu_state of transfer.
E 15
I 15
	 * Switch on state of transfer.
E 15
E 7
	 */
D 2

E 2
D 7
	printd("tuxintr: state %d\n", tu.state);
	switch(tu.state) {
E 7
I 7
	if (tudebug) {
		printf("tuxintr: state=");
		printstate(tu.tu_state);
	}
	switch(tu.tu_state) {
E 7
I 2

E 2
D 7
	case INIT1:		/* two nulls sent, remove break, send inits */
E 7
I 7
	/*
	 * Two nulls have been sent, remove break, and send inits
	 */
	case TUS_INIT1:	
E 7
		mtpr(CSTS, IE);
		printd("ON2 ");
D 7
		tu.state = INIT2;
		tu.wbptr = tuinit;
		tu.wcnt = sizeof tuinit;
E 7
I 7
		tu.tu_state = TUS_INIT2;
		tu.tu_wbptr = tuinit;
		tu.tu_wcnt = sizeof (tuinit);
E 7
		goto top;

D 7
	case INIT2:		/* inits sent, wait for continue */
E 7
I 7
	/*
	 * Inits have been sent, wait for a continue msg.
	 */
	case TUS_INIT2:	
E 7
D 2
		mfpr(CSRD);
E 2
I 2
		(void) mfpr(CSRD);
E 2
		mtpr(CSRS, IE);
D 7
		tu.flag = 1;
E 7
I 7
		tu.tu_flag = 1;
E 7
		break;

D 7
	case IDLE:		/* stray interrupt? */
E 7
I 7
D 18
	case TUS_IDLE:		/* stray interrupt? */
E 7
		break;

E 18
D 7
	case SENDR:		/* read cmd packet sent, get ready for data */
		tu.state = GETH;
		tu.rbptr = (u_char *)&tudata;
		tu.rcnt = 2;
		tu.flag = 1;
E 7
I 7
	/*
	 * Read cmd packet sent, get ready for data
	 */
	case TUS_SENDR:
		tu.tu_state = TUS_GETH;
		tu.tu_rbptr = (u_char *)&tudata;
		tu.tu_rcnt = 2;
		tu.tu_flag = 1;
E 7
		mtpr(CSTS, 0);	/* disable transmitter interrupts */
		printd("OFF ");
		break;

D 7
	case SENDW:		/* write cmd packet sent, wait for continue */
		tu.state = WAIT;
		tu.flag = 1;
E 7
I 7
	/*
	 * Write cmd packet sent, wait for continue
	 */
	case TUS_SENDW:	
		tu.tu_state = TUS_WAIT;
		tu.tu_flag = 1;
E 7
		if ((mfpr(CSRS)&IE) == 0) {
			printf("NO IE\n");
			mtpr(CSRS, IE);
		}
		break;

D 7
	case SENDH:		/* header sent, send data */
		tu.state = SENDD;
		tu.wbptr = (u_char *)tu.addr;
		tu.wcnt = tudata.pk_mcount;
E 7
I 7
	/*
	 * Header sent, send data.
	 */
	case TUS_SENDH:
		tu.tu_state = TUS_SENDD;
		tu.tu_wbptr = (u_char *)tu.tu_addr;
		tu.tu_wcnt = tudata.pk_mcount;
E 7
		goto top;

D 7
	case SENDD:		/* data sent, send checksum */
		tu.state = SENDC;
		tu.wbptr = (u_char *)&tudata.pk_chksum;
		tu.wcnt = sizeof tudata.pk_chksum;
E 7
I 7
	/*
	 * Data sent, follow with checksum.
	 */
	case TUS_SENDD:	
		tu.tu_state = TUS_SENDC;
		tu.tu_wbptr = (u_char *)&tudata.pk_chksum;
		tu.tu_wcnt = sizeof tudata.pk_chksum;
E 7
		goto top;

D 7
	case SENDC:		/* checksum sent, wait for continue */
		tu.addr += tudata.pk_mcount;	/* update buffer address */
		tu.count -= tudata.pk_mcount;	/* and count */
		if (tu.count == 0) {		/* all done? */
			tu.state = GET;		/* set up to get end packet */
			tu.rbptr = (u_char *)&tudata;
			tu.rcnt = sizeof tudata;
			tu.flag = 1;
			mtpr(CSTS, 0);
			printd("OFF2 ");
		} else {
			tu.state = WAIT;	/* wait for continue */
			tu.flag = 1;
E 7
I 7
	/* 
	 * Checksum sent, wait for continue.
	 */
	case TUS_SENDC:
		/*
		 * Updata buffer address and count.
		 */
		tu.tu_addr += tudata.pk_mcount;
		tu.tu_count -= tudata.pk_mcount;
		if (tu.tu_count) {
			tu.tu_state = TUS_WAIT;
			tu.tu_flag = 1;
			break;
E 7
		}
I 7

		/*
		 * End of transmission, get ready for end packet.
		 */
		tu.tu_state = TUS_GET;
		tu.tu_rbptr = (u_char *)&tudata;
		tu.tu_rcnt = sizeof (tudata);
		tu.tu_flag = 1;
		mtpr(CSTS, 0);
		printd("OFF2 ");
E 7
		break;

D 7
	default:	/* random interrupt, probably from MRSP ACK */
E 7
I 7
	/*
	 * Random interrupt, probably from MRSP ACK
	 */
I 18
D 25
	case TUS_IDLE:		/* stray interrupt? */
E 25
I 25
	case TUS_IDLE:
E 25

E 18
	default:
E 7
		break;
I 18

E 18
	}
D 7
	printd("  new state %d\n", tu.state);
E 7
I 7
	if (tudebug) {
		printd("  new tu_state=");
		printstate(tu.tu_state);
	}
E 7
}

/*
 * Compute checksum TU58 fashion
D 6
 *
 * *** WARNING ***
 * This procedure is not in C because
 * it has to be fast and it is hard to
 * do add-carry in C.  Sorry.
E 6
 */
D 2

E 2
I 2
D 3
/*ARGSUSED*/
E 3
E 2
D 6
tuchk(word0, wp, n)
D 2
register int word0;	/* r11 */
register char *wp;	/* r10 */
register int n;		/* r9 */
E 2
I 2
	register int word0;	/* known to be r11 */
	register caddr_t wp;	/* known to be r10 */
	register int n;		/* known to be r9 */
E 6
I 6
D 10
#ifdef notdef
E 10
I 10
#ifdef lint
E 10
tuchk(word, cp, n)
	register word;
	register unsigned short *cp;
I 11
	int n;
E 11
E 6
E 2
{
I 3
D 6
#ifdef lint
	/* for some reason ARGSUSED doesn't work to quiet lint */
	word0 = 0; n = word0; word0 = n;
	wp = 0; wp = wp;
#endif
E 6
I 6
D 11
	register c = n >> 1;
E 11
I 11
	register int c = n >> 1;
E 11
	register long temp;
E 6
E 3
I 2

I 6
	do {
		temp = *cp++;	/* temp, only because vax cc won't *r++ */
		word += temp;
	} while (--c > 0);
	if (n & 1)
		word += *(unsigned char *)cp;
D 10
	while (word & 0xFFFF0000)
		word = (word & 0xFFFF) + ((word >> 16) & 0xFFFF);
E 10
I 10
	while (word & 0xffff0000)
		word = (word & 0xffff) + ((word >> 16) & 0xffff);
E 10
	return (word);
}
#else
tuchk(word0, wp, n)
D 10
register int word0;	/* r11 */
register char *wp;	/* r10 */
register int n;		/* r9 */
E 10
I 10
	register int word0;	/* r11 */
D 32
	register char *wp;	/* r10 */
E 32
I 32
	register u_short *wp;	/* r10 */
E 32
	register int n;		/* r9 */
E 10
{
E 6
E 2
	asm("loop:");
	asm("	addw2	(r10)+,r11");	/* add a word to sum */
	asm("	adwc	$0,r11");	/* add in carry, end-around */
	asm("	acbl	$2,$-2,r9,loop");	/* done yet? */
	asm("	blbc	r9,ok");	/* odd byte count? */
	asm("	movzbw	(r10),r10");	/* yes, get last byte */
	asm("	addw2	r10,r11");	/* add it in */
	asm("	adwc	$0,r11");	/* and the carry */
	asm("ok:");
	asm("	movl	r11,r0");	/* return sum */
I 2
D 6
#ifdef lint
	return (0);
#endif
E 6
E 2
}
I 6
#endif
E 6

tuwatch()
{
	register int s;
	register struct buf *bp;

D 25
	if (tutimer == 0) {
D 7
		tu.flag = 0;
E 7
I 7
		tu.tu_flag = 0;
E 25
I 25
	if (tutimer == 0)
E 25
E 7
		return;
I 25

	if (tu.tu_flag == 0) {		/* if no read in progress - skip */
		timeout(tuwatch, (caddr_t)0, hz);
		return;
E 25
	}
D 7
	if (tu.flag)
		tu.flag++;
	if (tu.flag > 40) {
		printf("tu: read stalled\n");
		printf("%X %X %X %X %X %X %X %X\n", tu.rbptr, tu.rcnt,
		tu.wbptr, tu.wcnt, tu.state, tu.flag, tu.addr, tu.count);
		tu.flag = 0;
		s = splx(TUIPL);
D 2
		mfpr(CSRD);
E 2
I 2
		(void) mfpr(CSRD);
E 2
		mtpr(CSRS, IE);		/* in case we were flushing */
		mtpr(CSTS, IE);
		tu.state = IDLE;
		if (tutab.b_active) {
			if (++tutab.b_errcnt > 1) {
				if (bp = tutab.b_actf) {
					bp->b_flags |= B_ERROR;
I 6
					if ((bp->b_flags&B_READ) == 0)
						tu_vee(&pcnt[minor(bp->b_dev)&DNUM]);
E 6
					iodone(bp);
				}
			} else
				tustart();
		} else
			wakeup((caddr_t)&tu);
		splx(s);
E 7
I 7
D 25
	if (tu.tu_flag)
		tu.tu_flag++;
	if (tu.tu_flag <= 40) {
E 25
I 25
	if (tu.tu_flag++ <= 40) {
E 25
		timeout(tuwatch, (caddr_t)0, hz);
		return;
E 7
	}
I 7
D 18
	printf("tu: read stalled\n");
E 18
I 18
	printf("tu%d: read stalled\n", tudata.pk_unit);
I 21
D 25
#ifdef notdef
E 25
I 25
#ifdef TUDEBUG
E 25
E 21
E 18
	printf("%X %X %X %X %X %X %X %X\n", tu.tu_rbptr, tu.tu_rcnt,
		tu.tu_wbptr, tu.tu_wcnt, tu.tu_state, tu.tu_flag,
		tu.tu_addr, tu.tu_count);
I 21
#endif
E 21
D 18
	tu.tu_flag = 0;
E 18
D 32
	s = splx(TUIPL);
E 32
I 32
	s = spltu();
E 32
I 18
	tu.tu_flag = 0;
E 18
	(void) mfpr(CSRD);
	mtpr(CSRS, IE);		/* in case we were flushing */
	mtpr(CSTS, IE);
	tu.tu_state = TUS_IDLE;
	if (!tutab.b_active) {
		wakeup((caddr_t)&tu);
		goto retry;
	}
	if (++tutab.b_errcnt <= 1) {
		tustart();
		goto retry;
	}
	if (bp = tutab.b_actf) {
		bp->b_flags |= B_ERROR;
		if ((bp->b_flags&B_READ) == 0)
D 23
			tu_vee(&pcnt[minor(bp->b_dev)&DNUM]);
E 23
I 23
			tu_vee(&tu_pcnt[minor(bp->b_dev)&DNUM]);
E 23
		iodone(bp);
	}
retry:
	splx(s);
E 7
	timeout(tuwatch, (caddr_t)0, hz);
I 6
}

tu_pee(cp)
D 7
char *cp;
E 7
I 7
	char *cp;
E 7
{
	register int s;

D 32
	s = splx(TUIPL);
E 32
I 32
	s = spltu();
E 32
D 7
	if (++(*cp) > NTUQ) {
E 7
I 7
	if (++(*cp) > NTUQ)
E 7
		sleep(cp, PRIBIO);
D 7
	}
E 7
	splx(s);
}

tu_vee(cp)
D 7
char *cp;
E 7
I 7
	char *cp;
E 7
{
	register int s;

D 32
	s = splx(TUIPL);
E 32
I 32
	s = spltu();
E 32
D 7
	if (--(*cp) <= NTUQ) {
E 7
I 7
	if (--(*cp) <= NTUQ)
E 7
		wakeup(cp);
D 7
	}
E 7
	splx(s);
E 6
}
D 22
#endif
E 22
I 18

tu_restart()
{
	tureset();
D 27
	timeout(tustart(), (caddr_t)0, hz * 3);
E 27
I 27
	timeout(tustart, (caddr_t)0, hz * 3);
E 27
}
I 25

E 25
I 22
#endif
E 22
E 18
E 1
