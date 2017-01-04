h62575
s 00034/00071/00859
d D 7.3 88/05/06 17:17:15 bostic 40 39
c changes for raw{read,write} stuff
e
s 00016/00003/00914
d D 7.2 87/04/17 14:10:04 karels 39 38
c fix race in open; log excessive soft errs
e
s 00001/00001/00916
d D 7.1 86/06/05 01:22:16 mckusick 38 37
c 4.3BSD release version
e
s 00001/00001/00916
d D 6.8 86/02/23 23:20:16 karels 37 36
c lint
e
s 00001/00001/00916
d D 6.7 86/02/20 19:54:51 karels 36 35
c lint
e
s 00003/00002/00914
d D 6.6 85/10/01 09:41:47 karels 35 34
c no ENXIO if busy
e
s 00007/00001/00909
d D 6.5 85/06/08 14:28:49 mckusick 34 33
c Add copyright
e
s 00006/00002/00904
d D 6.4 85/03/13 09:45:22 ralph 33 32
c change error message printf's to tprintf's to the user.
e
s 00001/00001/00905
d D 6.3 84/11/27 15:38:18 karels 32 31
c how did this ever  work?
e
s 00016/00016/00890
d D 6.2 84/08/29 20:11:35 bloom 31 30
c Change to includes.  No more ../h
e
s 00000/00000/00906
d D 6.1 83/07/29 07:30:28 sam 30 29
c 4.2 distribution
e
s 00002/00010/00904
d D 4.29 83/03/06 16:07:56 sam 29 28
c have FSF thru BSR done one operation at a time; resid's aren't 
c working and it causes all ioctl's to return an EIO
e
s 00001/00001/00913
d D 4.28 83/02/20 23:43:07 layer 28 27
c another typo
e
s 00001/00001/00913
d D 4.27 83/02/20 23:33:32 sam 27 26
c typo
e
s 00079/00052/00835
d D 4.26 83/02/20 19:19:42 sam 26 25
c fixes from dave martindale; ioctl botch; handle frame count register 
c sanely; interpret correctable error bit properly; don't automatically close 
c on errors on raw device; handle EOT more like ht driver
e
s 00002/00001/00885
d D 4.25 82/12/17 12:05:35 sam 25 24
c sun merge
e
s 00001/00003/00885
d D 4.24 82/12/05 22:05:39 sam 24 23
c kernel.h required for lbolt definition
e
s 00001/00001/00887
d D 4.23 82/11/26 18:18:24 sam 23 22
c don't call ubadone at ubareset time
e
s 00005/00002/00883
d D 4.22 82/11/13 23:01:11 sam 22 21
c merge of 4.1b with 4.1c
e
s 00001/00002/00884
d D 4.21 82/10/17 23:07:06 root 21 20
c lint
e
s 00018/00025/00868
d D 4.20 82/10/17 11:52:04 root 20 19
c ioctl/open return errors, not u.u_error; remove ubarelses (it is
c now done in uba.c); add open routines to some disk drivers
e
s 00004/00004/00889
d D 4.19 82/10/10 17:30:20 root 19 18
c header files for vax are in their place
e
s 00011/00008/00882
d D 4.18 82/09/12 03:12:01 root 18 17
c 
e
s 00008/00011/00882
d D 4.17 82/08/22 21:22:30 root 17 16
c fully uio()'d
e
s 00015/00007/00878
d D 4.16 82/08/13 00:18:27 root 16 15
c changes for char dev uio'ing
e
s 00016/00020/00869
d D 4.15 82/08/01 19:26:41 sam 15 14
c new ioctl's
e
s 00001/00000/00888
d D 4.14 82/07/15 19:55:23 kre 14 13
c probe routines return size of unibus dev regs to reserve space
e
s 00013/00013/00875
d D 4.13 82/07/13 18:14:24 sam 13 12
c bdbtofsb maps block device blocks DEV_BSIZE units
e
s 00003/00010/00885
d D 4.12 82/05/27 10:45:55 root 12 11
c funky fix for probe from SI (sam)
e
s 00001/00001/00894
d D 4.11 82/03/14 14:28:31 root 11 10
c #if 0 -> #if notdef
e
s 00006/00004/00889
d D 4.10 82/01/17 20:29:16 root 10 9
c remove spl0's from block tape routines
e
s 00005/00003/00888
d D 4.9 81/11/18 15:51:49 wnj 9 8
c lint
e
s 00001/00000/00890
d D 4.8 81/11/13 14:45:41 sam 8 7
c reset timeout counter
e
s 00001/00001/00889
d D 4.7 81/11/11 15:52:10 root 7 6
c fix config stuff w/ shift of ut.h -> tj.h
e
s 00001/00001/00889
d D 4.6 81/11/11 14:04:30 sam 6 5
c change printf in uttimer
e
s 00003/00002/00887
d D 4.5 81/11/10 12:39:24 root 5 4
c fix splx bug in timer routines
e
s 00036/00007/00853
d D 4.4 81/11/08 17:15:43 wnj 4 3
c add watchdog
e
s 00015/00035/00845
d D 4.3 81/11/07 10:38:43 wnj 3 2
c fixes from shannon
e
s 00147/00109/00733
d D 4.2 81/11/06 09:16:13 sam 2 1
c first semi-working version
e
s 00842/00000/00000
d D 4.1 81/11/04 11:03:17 wnj 1 0
c date and time created 81/11/04 11:03:17 by wnj
e
u
U
t
T
I 1
D 34
/*	%M%	%I%	%E%	*/
E 34
I 34
/*
D 38
 * Copyright (c) 1982 Regents of the University of California.
E 38
I 38
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 38
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 34

D 7
#include "ut.h"
E 7
I 7
#include "tj.h"
E 7
#if NUT > 0
D 3
#define UTDEBUG	1
E 3
/*
 * System Industries Model 9700 Tape Drive
 *   emulates a TU45 on the UNIBUS
 *
 * TODO:
 *	check out attention processing
 *	try reset code and dump code
 */
I 25
D 39
#include "../machine/pte.h"

E 39
E 25
D 31
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/buf.h"
#include "../h/conf.h"
#include "../h/dir.h"
#include "../h/file.h"
#include "../h/user.h"
#include "../h/map.h"
D 25
#include "../h/pte.h"
E 25
D 19
#include "../h/ubareg.h"
#include "../h/ubavar.h"
E 19
D 15
#include "../h/mtio.h"
E 15
#include "../h/ioctl.h"
I 15
#include "../h/mtio.h"
E 15
#include "../h/cmap.h"
D 19
#include "../h/cpu.h"
E 19
I 16
#include "../h/uio.h"
I 24
#include "../h/kernel.h"
E 31
I 31
#include "param.h"
#include "systm.h"
#include "buf.h"
#include "conf.h"
#include "dir.h"
#include "file.h"
#include "user.h"
#include "map.h"
#include "ioctl.h"
#include "mtio.h"
#include "cmap.h"
#include "uio.h"
#include "kernel.h"
I 33
#include "tty.h"
I 39
#include "syslog.h"
E 39
E 33
E 31
E 24
E 16

I 39
#include "../machine/pte.h"
E 39
D 19
#include "../h/utreg.h"
E 19
I 19
#include "../vax/cpu.h"
D 31
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
#include "../vaxuba/utreg.h"
E 31
I 31
#include "ubareg.h"
#include "ubavar.h"
#include "utreg.h"
E 31
E 19

D 40
struct	buf	rutbuf[NUT];	/* bufs for raw i/o */
E 40
struct	buf	cutbuf[NUT];	/* bufs for control operations */
struct	buf	tjutab[NTJ];	/* bufs for slave queue headers */

struct uba_ctlr *utminfo[NUT];
struct uba_device *tjdinfo[NTJ];
D 4
int utprobe(), utslave(), utattach(), utdgo();
E 4
I 4
int utprobe(), utslave(), utattach(), utdgo(), utintr(), uttimer();
E 4
u_short utstd[] = { 0772440, 0 };
struct uba_driver utdriver =
  { utprobe, utslave, utattach, utdgo, utstd, "tj", tjdinfo, "ut", utminfo, 0 };

I 26
#define	MASKREG(reg)	((reg)&0xffff)

E 26
/* bits in minor device */
#define	TJUNIT(dev)	(minor(dev)&03)
#define	T_NOREWIND	04
#define	T_1600BPI	010
#define	T_6250BPI	020
short	utdens[] = { UT_NRZI, UT_PE, UT_GCR, UT_NRZI };

/* slave to controller mapping table */
short	tjtout[NTJ];
#define UTUNIT(dev)	(tjtout[TJUNIT(dev)])

#define	INF	(daddr_t)1000000L	/* a block number that wont exist */

struct	tj_softc {
	char	sc_openf;	/* exclusive open */
	char	sc_lastiow;	/* last I/O operation was a write */
	daddr_t	sc_blkno;	/* next block to transfer */
	daddr_t	sc_nxrec;	/* next record on tape */
	u_short	sc_erreg;	/* image of uter */
	u_short	sc_dsreg;	/* image of utds */
D 2
	short	sc_resid;	/* residual from transfer */
E 2
I 2
	u_short	sc_resid;	/* residual from transfer */
E 2
	u_short	sc_dens;	/* sticky selected density */
I 4
	daddr_t	sc_timo;	/* time until timeout expires */
	short	sc_tact;	/* timeout is active flag */
I 33
	struct	tty *sc_ttyp;	/* record user's tty for errors */
I 39
	int	sc_blks;	/* number of I/O operations since open */
	int	sc_softerrs;	/* number of soft I/O errors since open */
E 39
E 33
E 4
} tj_softc[NTJ];

/*
 * Internal per/slave states found in sc_state
 */
#define	SSEEK		1	/* seeking */
#define	SIO		2	/* doing sequential I/O */
#define	SCOM		3	/* sending a control command */
#define	SREW		4	/* doing a rewind op */
I 2
#define	SERASE		5	/* erase inter-record gap */
#define	SERASED		6	/* erased inter-record gap */
E 2

I 9
/*ARGSUSED*/
E 9
D 3
#if UTDEBUG
int	utdebug;
#define printd	if (utdebug) printf
#else
#define	printd
#endif

E 3
D 4
/*
 * A NOP should get an interrupt back, if the
 *  device is there.
 */
E 4
utprobe(reg)
	caddr_t reg;
{
	register int br, cvec;
#ifdef lint
	br=0; cvec=br; br=cvec;
I 9
	utintr(0);
E 9
#endif
I 9
D 11
#if 0
E 11
I 11
D 12
#if notdef
E 12
E 11
E 9
I 2
	/*
D 12
	 * It appears the controller won't interrupt unless the
	 * slave is off-line...this is as bad as the TS-11.
E 12
I 12
	 * The SI documentation says you must set the RDY bit
	 * (even though it's read-only) to force an interrupt.
E 12
	 */
D 9
#ifdef notdef
E 9
E 2
D 12
	((struct utdevice *) reg)->utcs1 = UT_IE|UT_NOP|UT_GO;
E 12
I 12
	((struct utdevice *) reg)->utcs1 = UT_IE|UT_NOP|UT_RDY;
E 12
	DELAY(10000);
I 14
	return (sizeof (struct utdevice));
E 14
D 12
	((struct utdevice *) reg)->utcs1 = UT_CLEAR|UT_GO;
I 2
#else
	br = 0x15;
	cvec = 0164;
E 2
	return(1);
I 2
#endif
E 12
E 2
}

/*ARGSUSED*/
utslave(ui, reg)
	struct uba_device *ui;
	caddr_t reg;
{
	/*
	 * A real TU45 would support the slave present bit
	 * int the drive type register, but this thing doesn't,
	 * so there's no way to determine if a slave is present or not.
	 */
	 return(1);
}

utattach(ui)
	struct uba_device *ui;
{
	tjtout[ui->ui_unit] = ui->ui_mi->um_ctlr;
}

/*
 * Open the device with exclusive access.
 */
utopen(dev, flag)
	dev_t dev;
	int flag;
{
	register int tjunit = TJUNIT(dev);
	register struct uba_device *ui;
	register struct tj_softc *sc;
	int olddens, dens;
I 10
	register int s;
E 10

D 35
	if (tjunit >= NTJ || (sc = &tj_softc[tjunit])->sc_openf ||
D 20
	    (ui = tjdinfo[tjunit]) == 0 || ui->ui_alive == 0) {
		u.u_error = ENXIO;
		return;
	}
E 20
I 20
	    (ui = tjdinfo[tjunit]) == 0 || ui->ui_alive == 0)
E 35
I 35
	if (tjunit >= NTJ || (ui = tjdinfo[tjunit]) == 0 || ui->ui_alive == 0)
E 35
		return (ENXIO);
I 35
	if ((sc = &tj_softc[tjunit])->sc_openf)
		return (EBUSY);
I 39
	sc->sc_openf = 1;
E 39
E 35
E 20
	olddens = sc->sc_dens;
D 20
	dens = sc->sc_dens = utdens[(minor(dev)&(T_1600BPI|T_6250BPI))>>3]|
				PDP11FMT|(ui->ui_slave&07);
E 20
I 20
	dens = sc->sc_dens =
	    utdens[(minor(dev)&(T_1600BPI|T_6250BPI))>>3]|
	      PDP11FMT|(ui->ui_slave&07);
E 20
get:
	utcommand(dev, UT_SENSE, 1);
	if (sc->sc_dsreg&UTDS_PIP) {
D 22
		sleep((caddr_t) &lbolt, PZERO+1);
E 22
I 22
D 24
#ifdef notdef
		/* this needs to be fixed */
E 24
		sleep((caddr_t)&lbolt, PZERO+1);
D 24
#endif
E 24
E 22
		goto get;
	}
	sc->sc_dens = olddens;
	if ((sc->sc_dsreg&UTDS_MOL) == 0) {
I 39
		sc->sc_openf = 0;
E 39
		uprintf("tj%d: not online\n", tjunit);
D 20
		u.u_error = EIO;
		return;
E 20
I 20
		return (EIO);
E 20
	}
	if ((flag&FWRITE) && (sc->sc_dsreg&UTDS_WRL)) {
I 39
		sc->sc_openf = 0;
E 39
		uprintf("tj%d: no write ring\n", tjunit);
D 20
		u.u_error = EIO;
		return;
E 20
I 20
		return (EIO);
E 20
	}
	if ((sc->sc_dsreg&UTDS_BOT) == 0 && (flag&FWRITE) &&
	    dens != sc->sc_dens) {
I 39
		sc->sc_openf = 0;
E 39
		uprintf("tj%d: can't change density in mid-tape\n", tjunit);
D 20
		u.u_error = EIO;
		return;
E 20
I 20
		return (EIO);
E 20
	}
D 39
	sc->sc_openf = 1;
E 39
	sc->sc_blkno = (daddr_t)0;
	sc->sc_nxrec = INF;
	sc->sc_lastiow = 0;
I 39
	sc->sc_blks = 0;
	sc->sc_softerrs = 0;
E 39
	sc->sc_dens = dens;
I 33
	sc->sc_ttyp = u.u_ttyp;
E 33
I 2
	/*
	 * For 6250 bpi take exclusive use of the UNIBUS.
	 */
	ui->ui_driver->ud_xclu = (dens&(T_1600BPI|T_6250BPI)) == T_6250BPI;
I 4
D 10
	(void) spl6();
E 10
I 10
D 37
	s = spl6();
E 37
I 37
	s = splclock();
E 37
E 10
	if (sc->sc_tact == 0) {
		sc->sc_timo = INF;
		sc->sc_tact = 1;
		timeout(uttimer, (caddr_t)dev, 5*hz);
	}
D 10
	(void) spl0();
E 10
I 10
	splx(s);
I 20
	return (0);
E 20
E 10
E 4
E 2
}

utclose(dev, flag)
	register dev_t dev;
	register flag;
{
	register struct tj_softc *sc = &tj_softc[TJUNIT(dev)];

	if (flag == FWRITE || ((flag&FWRITE) && sc->sc_lastiow)) {
		utcommand(dev, UT_WEOF, 1);
		utcommand(dev, UT_WEOF, 1);
		utcommand(dev, UT_SREV, 1);
	}
	if ((minor(dev)&T_NOREWIND) == 0)
		utcommand(dev, UT_REW, 0);
I 39
	if (sc->sc_blks > 100 && sc->sc_softerrs > sc->sc_blks / 100)
		log(LOG_INFO, "tj%d: %d soft errors in %d blocks\n",
		    TJUNIT(dev), sc->sc_softerrs, sc->sc_blks);
E 39
	sc->sc_openf = 0;
}

utcommand(dev, com, count)
	dev_t dev;
	int com, count;
{
	register struct buf *bp;
I 10
	register int s;
E 10

	bp = &cutbuf[UTUNIT(dev)];
D 10
	(void) spl5();
E 10
I 10
	s = spl5();
E 10
	while (bp->b_flags&B_BUSY) {
		if(bp->b_repcnt == 0 && (bp->b_flags&B_DONE))
			break;
		bp->b_flags |= B_WANTED;
		sleep((caddr_t)bp, PRIBIO);
	}
	bp->b_flags = B_BUSY|B_READ;
D 10
	(void) spl0();
E 10
I 10
	splx(s);
E 10
	bp->b_dev = dev;
	bp->b_command = com;
	bp->b_repcnt = count;
	bp->b_blkno = 0;
	utstrategy(bp);
	if (count == 0)
		return;
	iowait(bp);
	if (bp->b_flags&B_WANTED)
		wakeup((caddr_t)bp);
	bp->b_flags &= B_ERROR;
}

/*
 * Queue a tape operation.
 */
utstrategy(bp)
	register struct buf *bp;
{
	int tjunit = TJUNIT(bp->b_dev);
	register struct uba_ctlr *um;
	register struct buf *dp;
I 40
	int s;
E 40

	/*
	 * Put transfer at end of unit queue
	 */
	dp = &tjutab[tjunit];
	bp->av_forw = NULL;
I 32
	um = tjdinfo[tjunit]->ui_mi;
E 32
D 40
	(void) spl5();
E 40
I 40
	s = spl5();
E 40
	if (dp->b_actf == NULL) {
		dp->b_actf = bp;
		/*
		 * Transport not active, so...
		 * put at end of controller queue
		 */
		dp->b_forw = NULL;
D 32
		um = tjdinfo[tjunit]->ui_mi;
E 32
		if (um->um_tab.b_actf == NULL)
			um->um_tab.b_actf = dp;
		else
			um->um_tab.b_actl->b_forw = dp;
		um->um_tab.b_actl = dp;
	} else
		dp->b_actl->av_forw = bp;
	dp->b_actl = bp;
	/*
	 * If the controller is not busy, set it going.
	 */
D 2
	if (um->um_tab.b_active == 0)
E 2
I 2
	if (um->um_tab.b_state == 0)
E 2
		utstart(um);
D 40
	(void) spl0();
E 40
I 40
	splx(s);
E 40
}

utstart(um)
	register struct uba_ctlr *um;
{
D 2
	register struct utdevice *utaddr;
E 2
I 2
	register struct utdevice *addr;
E 2
	register struct buf *bp, *dp;
	register struct tj_softc *sc;
	struct uba_device *ui;
	int tjunit;
	daddr_t blkno;

loop:
	/*
	 * Scan controller queue looking for units with
	 * transaction queues to dispatch
	 */
	if ((dp = um->um_tab.b_actf) == NULL)
		return;
	if ((bp = dp->b_actf) == NULL) {
		um->um_tab.b_actf = dp->b_forw;
		goto loop;
	}
D 2
	utaddr = (struct utdevice *)um->um_addr;
E 2
I 2
	addr = (struct utdevice *)um->um_addr;
E 2
	tjunit = TJUNIT(bp->b_dev);
	ui = tjdinfo[tjunit];
	sc = &tj_softc[tjunit];
	/* note slave select, density, and format were merged on open */
D 2
	utaddr->uttc = sc->sc_dens;
	sc->sc_dsreg = utaddr->utds;
	sc->sc_erreg = utaddr->uter;
	sc->sc_resid = utaddr->utwc;
E 2
I 2
	addr->uttc = sc->sc_dens;
	sc->sc_dsreg = addr->utds;
	sc->sc_erreg = addr->uter;
D 26
	/* watch this, sports fans */
	sc->sc_resid = bp->b_flags&B_READ ?
		bp->b_bcount - ((-addr->utfc)&0xffff) : -addr->utwc<<1;
E 26
I 26
	sc->sc_resid = MASKREG(addr->utfc);
E 26
E 2
	/*
	 * Default is that last command was NOT a write command;
	 * if we do a write command we will notice this in utintr().
	 */
	sc->sc_lastiow = 0;
D 2
	printd("utstart: openf=%d ds=%b\n", sc->sc_openf, utaddr->utds,
		UTDS_BITS);
	if (sc->sc_openf < 0 || (utaddr->utds&UTDS_MOL) == 0) {
E 2
I 2
D 3
	printd("utstart: cmd=%o openf=%d ds=%b\n", bp->b_command>>1,
		sc->sc_openf, addr->utds, UTDS_BITS);
E 3
	if (sc->sc_openf < 0 || (addr->utds&UTDS_MOL) == 0) {
E 2
		/*
		 * Have had a hard error on a non-raw tape
		 * or the tape unit is now unavailable
		 * (e.g. taken off line).
		 */
		bp->b_flags |= B_ERROR;
		goto next;
	}
	if (bp == &cutbuf[UTUNIT(bp->b_dev)]) {
		/*
		 * Execute a control operation with the specified
		 * count.
		 */
		if (bp->b_command == UT_SENSE)
			goto next;
I 26
		if (bp->b_command == UT_SFORW && (addr->utds & UTDS_EOT)) {
			bp->b_resid = bp->b_bcount;
			goto next;
		}
E 26
		/*
		 * Set next state; handle timeouts
		 */
D 4
		if (bp->b_command == UT_REW)
E 4
I 4
		if (bp->b_command == UT_REW) {
E 4
D 2
			um->um_tab.b_active = SREW;
E 2
I 2
			um->um_tab.b_state = SREW;
E 2
D 4
		else
E 4
I 4
			sc->sc_timo = 5*60;
		} else {
E 4
D 2
			um->um_tab.b_active = SCOM;
E 2
I 2
			um->um_tab.b_state = SCOM;
I 4
			sc->sc_timo = imin(imax(10*(int)-bp->b_repcnt,60),5*60);
		}
E 4
E 2
		/* NOTE: this depends on the ut command values */
		if (bp->b_command >= UT_SFORW && bp->b_command <= UT_SREVF)
D 2
			utaddr->utfc = bp->b_repcnt;
E 2
I 2
			addr->utfc = -bp->b_repcnt;
E 2
		goto dobpcmd;
	}
	/*
D 40
	 * The following checks boundary conditions for operations
	 * on non-raw tapes.  On raw tapes the initialization of
	 * sc->sc_nxrec by utphys causes them to be skipped normally
	 * (except in the case of retries).
E 40
I 40
	 * For raw I/O, save the current block
	 * number in case we have to retry.
E 40
	 */
D 13
	if (dbtofsb(bp->b_blkno) > sc->sc_nxrec) {
E 13
I 13
D 40
	if (bdbtofsb(bp->b_blkno) > sc->sc_nxrec) {
E 13
		/* can't read past end of file */
		bp->b_flags |= B_ERROR;
		bp->b_error = ENXIO;
		goto next;
E 40
I 40
	if (bp->b_flags & B_RAW) {
		if (um->um_tab.b_errcnt == 0) {
			sc->sc_blkno = bdbtofsb(bp->b_blkno);
			sc->sc_nxrec = sc->sc_blkno + 1;
		}
E 40
	}
D 13
	if (dbtofsb(bp->b_blkno) == sc->sc_nxrec && (bp->b_flags&B_READ)) {
E 13
I 13
D 40
	if (bdbtofsb(bp->b_blkno) == sc->sc_nxrec && (bp->b_flags&B_READ)) {
E 13
		/* read at eof returns 0 count */
		bp->b_resid = bp->b_bcount;
		clrbuf(bp);
		goto next;
E 40
I 40
	else {
		/*
		 * Handle boundary cases for operation
		 * on non-raw tapes.
		 */
		if (bdbtofsb(bp->b_blkno) > sc->sc_nxrec) {
			/* can't read past end of file */
			bp->b_flags |= B_ERROR;
			bp->b_error = ENXIO;
			goto next;
		}
		if (bdbtofsb(bp->b_blkno) == sc->sc_nxrec &&
		    (bp->b_flags&B_READ)) {
			/*
			 * Reading at end of file returns 0 bytes.
			 */
			bp->b_resid = bp->b_bcount;
			clrbuf(bp);
			goto next;
		}
		if ((bp->b_flags&B_READ) == 0)
			sc->sc_nxrec = bdbtofsb(bp->b_blkno) + 1;
E 40
	}
D 40
	if ((bp->b_flags&B_READ) == 0)
D 13
		sc->sc_nxrec = dbtofsb(bp->b_blkno)+1;
E 13
I 13
		sc->sc_nxrec = bdbtofsb(bp->b_blkno)+1;
E 40
E 13
	/*
	 * If the tape is correctly positioned, set up all the
	 * registers but the csr, and give control over to the
	 * UNIBUS adaptor routines, to wait for resources to
	 * start I/O.
	 */
D 13
	if ((blkno = sc->sc_blkno) == dbtofsb(bp->b_blkno)) {
E 13
I 13
	if ((blkno = sc->sc_blkno) == bdbtofsb(bp->b_blkno)) {
E 13
D 2
		utaddr->utwc = -(((bp->b_bcount)+1)>>1);
E 2
I 2
		addr->utwc = -(((bp->b_bcount)+1)>>1);
		addr->utfc = -bp->b_bcount;
E 2
		if ((bp->b_flags&B_READ) == 0) {
			/*
			 * On write error retries erase the
D 2
			 * inter-record gap
E 2
I 2
			 * inter-record gap before rewriting.
E 2
			 */
D 2
			if (um->um_tab.b_errcnt)
				um->um_cmd = UT_ERASE;
			else
				um->um_cmd = UT_WCOM;
E 2
I 2
			if (um->um_tab.b_errcnt) {
D 3
				printd("utstart: erase\n");
E 3
				if (um->um_tab.b_state != SERASED) {
D 3
					um->um_tab.b_state = SERASED;
E 3
I 3
					um->um_tab.b_state = SERASE;
I 4
					sc->sc_timo = 60;
E 4
E 3
					addr->utcs1 = UT_ERASE|UT_IE|UT_GO;
					return;
				}
D 3
				printd("utstart: erased\n");
E 3
			}
I 26
			if (addr->utds & UTDS_EOT) {
				bp->b_resid = bp->b_bcount;
				um->um_tab.b_state = 0;
				goto next;
			}
E 26
			um->um_cmd = UT_WCOM;
E 2
		} else
			um->um_cmd = UT_RCOM;
I 4
		sc->sc_timo = 60;
E 4
D 2
		um->um_tab.b_active = SIO;
E 2
I 2
		um->um_tab.b_state = SIO;
E 2
		(void) ubago(ui);
		return;
	}
	/*
	 * Tape positioned incorrectly; seek forwards or
	 * backwards to the correct spot.  This happens for
	 * raw tapes only on error retries.
	 */
D 3
	printd("utstart: seek, blkno=%d dbtofsb=%d\n", blkno,
		dbtofsb(bp->b_blkno));
E 3
D 2
	um->um_tab.b_active = SSEEK;
E 2
I 2
	um->um_tab.b_state = SSEEK;
E 2
D 13
	if (blkno < dbtofsb(bp->b_blkno)) {
D 2
		utaddr->utfc = blkno - dbtofsb(bp->b_blkno);
E 2
I 2
		addr->utfc = blkno - dbtofsb(bp->b_blkno);
E 13
I 13
	if (blkno < bdbtofsb(bp->b_blkno)) {
		addr->utfc = blkno - bdbtofsb(bp->b_blkno);
E 13
E 2
		bp->b_command = UT_SFORW;
	} else {
D 2
		utaddr->utfc = dbtofsb(bp->b_blkno) - blkno;
E 2
I 2
D 13
		addr->utfc = dbtofsb(bp->b_blkno) - blkno;
E 13
I 13
		addr->utfc = bdbtofsb(bp->b_blkno) - blkno;
E 13
E 2
		bp->b_command = UT_SREV;
	}
I 4
	sc->sc_timo = imin(imax(10 * -addr->utfc, 60), 5*60);
E 4

dobpcmd:
	/*
	 * Perform the command setup in bp.
	 */
D 3
	printd("utstart: dobpcmd\n");
E 3
D 2
	utaddr->utcs1 = bp->b_command|UT_IE|UT_GO;
E 2
I 2
	addr->utcs1 = bp->b_command|UT_IE|UT_GO;
E 2
	return;
next:
	/*
	 * Advance to the next command in the slave queue,
	 * posting notice and releasing resources as needed.
	 */
D 3
	printd("utstart: next\n");
E 3
	if (um->um_ubinfo)
		ubadone(um);
	um->um_tab.b_errcnt = 0;
	dp->b_actf = bp->av_forw;
	iodone(bp);
	goto loop;
}

/*
 * Start operation on controller --
 * UNIBUS resources have been allocated.
 */
utdgo(um)
	register struct uba_ctlr *um;
{
	register struct utdevice *addr = (struct utdevice *)um->um_addr;

	addr->utba = (u_short) um->um_ubinfo;
D 26
	addr->utcs1 = um->um_cmd|((um->um_ubinfo>>8)&0x30)|UT_IE|UT_GO;
E 26
I 26
	addr->utcs1 = um->um_cmd|((um->um_ubinfo>>8)&0x300)|UT_IE|UT_GO;
E 26
D 2
	printd("utdgo: cs1=%b\n", addr->utcs1, UT_BITS);
E 2
I 2
D 3
	printd("utdgo: cs1=%b fc=%x wc=%x\n", addr->utcs1, UT_BITS,
		addr->utfc, addr->utwc);
E 3
E 2
}

/*
 * Ut interrupt handler
 */
/*ARGSUSED*/
utintr(ut11)
	int ut11;
{
	struct buf *dp;
	register struct buf *bp;
	register struct uba_ctlr *um = utminfo[ut11];
	register struct utdevice *addr;
	register struct tj_softc *sc;
D 2
	int tjunit;
E 2
I 2
	u_short tjunit, cs2, cs1;
E 2
	register state;

	if ((dp = um->um_tab.b_actf) == NULL)
		return;
	bp = dp->b_actf;
	tjunit = TJUNIT(bp->b_dev);
	addr = (struct utdevice *)tjdinfo[tjunit]->ui_addr;
	sc = &tj_softc[tjunit];
	/*
	 * Record status...
	 */
I 8
	sc->sc_timo = INF;
E 8
	sc->sc_dsreg = addr->utds;
	sc->sc_erreg = addr->uter;
D 2
	sc->sc_resid = addr->utwc;
E 2
I 2
D 26
	sc->sc_resid = bp->b_flags&B_READ ?
		bp->b_bcount - (-addr->utfc)&0xffff : -addr->utwc<<1;
E 26
I 26
	sc->sc_resid = MASKREG(addr->utfc);
E 26
E 2
D 3
	printd("utintr: state=%d cs1=%b cs2=%b ds=%b er=%b\n",
D 2
		um->um_tab.b_active,
E 2
I 2
		um->um_tab.b_state,
E 2
		((struct utdevice *) addr)->utcs1, UT_BITS,
		((struct utdevice *) addr)->utcs2, UTCS2_BITS,
		((struct utdevice *) addr)->utds, UTDS_BITS,
		((struct utdevice *) addr)->uter, UTER_BITS);
E 3
D 2
	/*
	 * Check for stray attentions from slaves going online, offline,
	 * or a completing rewind.  (The rewind started interrupt
	 * satisfied the requestor of the rewind.)
	 */
	if (((addr->utcs1&(UT_SC|UT_TRE)) == UT_SC) &&
	    (addr->utds&UTDS_ERR) == 0) {
		addr->utas = 0xff;	/* writing a 1 clears attention */
		/*
		 * If we're doing a rewind and we're at the beginning
		 * of tape, then the attention and the rewind 
		 * command may complete at the same time -- resulting in only
		 * one interrupt.  In this case, simulate things to look like
		 * the attention was the command complete.
		 */
		if (bp->b_command != UT_REW && bp->b_command != UT_REWOFFL)
			return;
		if ((addr->utds&UTDS_BOT) == 0)
			return;
		um->um_tab.b_active = SCOM;
	}
	if((bp->b_flags&B_READ) == 0)
E 2
I 2
	if ((bp->b_flags&B_READ) == 0)
E 2
		sc->sc_lastiow = 1;
D 2
	state = um->um_tab.b_active;
	um->um_tab.b_active = 0;
E 2
I 2
	state = um->um_tab.b_state;
	um->um_tab.b_state = 0;
E 2
	/*
	 * Check for errors...
	 */
	if ((addr->utds&UTDS_ERR) || (addr->utcs1&UT_TRE)) {
D 2
#ifdef notdef
E 2
		/*
I 3
		 * To clear the ERR bit, we must issue a drive clear
		 * command, and to clear the TRE bit we must set the
		 * controller clear bit.
		 */
		cs2 = addr->utcs2;
		if ((cs1 = addr->utcs1)&UT_TRE)
			addr->utcs2 |= UTCS2_CLR;
		/* is this dangerous ?? */
		while ((addr->utcs1&UT_RDY) == 0)
			;
		addr->utcs1 = UT_CLEAR|UT_GO;
		/*
E 3
D 2
		 * if this bit were emulated, it would allow us to wait
		 * for the transport to settle
E 2
I 2
D 26
		 * If we hit a tape mark or EOT update our position.
E 26
I 26
		 * If we were reading at 1600 or 6250 bpi and the error
		 * was corrected, then don't consider this an error.
E 26
E 2
		 */
D 2
		while (addr->utds&UTDS_SDWN)
			;
#endif
		/*
		 * If we hit the end of tape, update our position
		 */
		if (addr->utds&UTDS_EOT) {
E 2
I 2
D 3
		if (addr->utds&(UTDS_TM|UTDS_EOT)) {
E 3
I 3
D 26
		if (sc->sc_dsreg&(UTDS_TM|UTDS_EOT)) {
E 3
E 2
			/*
D 2
			 * Set blkno and nxrec on sensing end of tape.
E 2
I 2
D 3
			 * Set blkno and nxrec 
E 3
I 3
			 * Set blkno and nxrec
E 3
E 2
			 */
			if (bp == &cutbuf[UTUNIT(bp->b_dev)]) {
D 13
				if (sc->sc_blkno > dbtofsb(bp->b_blkno)) {
E 13
I 13
				if (sc->sc_blkno > bdbtofsb(bp->b_blkno)) {
E 13
D 2
					/* reversing */
E 2
					sc->sc_nxrec =
D 13
					      dbtofsb(bp->b_blkno) - addr->utfc;
E 13
I 13
					      bdbtofsb(bp->b_blkno) - addr->utfc;
E 13
					sc->sc_blkno = sc->sc_nxrec;
				} else {
D 2
					/* spacing forward */
E 2
					sc->sc_blkno =
D 13
					      dbtofsb(bp->b_blkno) + addr->utfc;
E 13
I 13
					      bdbtofsb(bp->b_blkno) + addr->utfc;
E 13
					sc->sc_nxrec = sc->sc_blkno-1;
				}
D 2
			} else		/* eof on read */
E 2
I 2
			} else
E 2
D 13
				sc->sc_nxrec = dbtofsb(bp->b_blkno);
E 13
I 13
				sc->sc_nxrec = bdbtofsb(bp->b_blkno);
E 13
			state = SCOM;		/* force completion */
D 3
			addr->utcs1 = UT_CLEAR|UT_GO;
E 3
			/*
D 2
			 * Stuff fc so that it will be unstuffed correctly
			 * later to get the residual.
E 2
I 2
			 * Stuff so we can unstuff later
			 * to get the residual.
E 2
			 */
I 2
			addr->utwc = (-bp->b_bcount)>>1;
E 2
			addr->utfc = -bp->b_bcount;
I 2
			if (sc->sc_dsreg&UTDS_EOT)
				goto harderror;
E 2
			goto opdone;
E 26
I 26
D 27
		if (sc->sc_errreg & UTER_COR && (bp->b_flags & B_READ) &&
E 27
I 27
		if (sc->sc_erreg & UTER_COR && (bp->b_flags & B_READ) &&
E 27
		    (addr->uttc & UTTC_DEN) != UT_NRZI) {
D 33
			printf(
E 33
I 33
			tprintf(sc->sc_ttyp,
E 33
			  "ut%d: soft error bn%d cs1=%b er=%b cs2=%b ds=%b\n",
			  tjunit, bp->b_blkno, cs1, UT_BITS, sc->sc_erreg,
			  UTER_BITS, cs2, UTCS2_BITS, sc->sc_dsreg, UTDS_BITS);
			sc->sc_erreg &= ~UTER_COR;
E 26
		}
I 2
D 3
		cs2 = addr->utcs2;		/* save it for printf below */
		if ((cs1 = addr->utcs1)&UT_TRE)
			addr->utcs2 |= UTCS2_CLR;
E 2
		addr->utcs1 = UT_CLEAR|UT_GO;	/* must clear ERR bit */
I 2
		printd("after clear: cs1=%b er=%b cs2=%b ds=%b\n",
			addr->utcs1, UT_BITS, addr->uter, UTER_BITS,
			addr->utcs2, UTCS2_BITS, addr->utds, UTDS_BITS);
E 3
E 2
		/*
		 * If we were reading from a raw tape and the only error
		 * was that the record was too long, then we don't consider
		 * this an error.
		 */
D 40
		if (bp == &rutbuf[UTUNIT(bp->b_dev)] && (bp->b_flags&B_READ) &&
E 40
I 40
		if ((bp->b_flags & (B_READ|B_RAW)) == (B_READ|B_RAW) &&
E 40
		    (sc->sc_erreg&UTER_FCE))
I 26
			sc->sc_erreg &= ~UTER_FCE;
D 28
		if (sc->sc_errreg == 0)
E 28
I 28
		if (sc->sc_erreg == 0)
E 28
E 26
			goto ignoreerr;
		/*
I 2
D 26
		 * Fix up errors which occur due to backspacing "over" the
		 * front of the tape.
E 26
I 26
		 * Fix up errors which occur due to backspacing
		 * "over" the front of the tape.
E 26
		 */
D 26
		if ((sc->sc_dsreg&UTDS_BOT) &&
		    (bp->b_command == UT_SREV || bp->b_command == UT_SREV) &&
E 26
I 26
		if ((sc->sc_dsreg & UTDS_BOT) && bp->b_command == UT_SREV &&
E 26
		    ((sc->sc_erreg &= ~(UTER_NEF|UTER_FCE)) == 0))
			goto opdone;
		/*
E 2
		 * Retry soft errors up to 8 times
		 */
		if ((sc->sc_erreg&UTER_HARD) == 0 && state == SIO) {
			if (++um->um_tab.b_errcnt < 7) {
				sc->sc_blkno++;
				ubadone(um);
				goto opcont;
			}
D 26
		} else
I 2
harderror:
E 2
			/*
			 * Hard or non-I/O errors on non-raw tape
D 2
			 * cause it to close.
E 2
I 2
			 * cause it to close; also, reading off the
			 * end of the tape.
E 2
			 */
D 2
			if (sc->sc_openf > 0 && bp != &rutbuf[UTUNIT(bp->b_dev)])
E 2
I 2
			if (sc->sc_openf > 0 &&
			    bp != &rutbuf[UTUNIT(bp->b_dev)] ||
			    sc->sc_dsreg&UTDS_EOT)
E 2
				sc->sc_openf = -1;
E 26
I 26
		}
E 26
		/*
I 26
		 * Hard or non-I/O errors on non-raw tape
		 * cause it to close.
		 */
D 40
		if (sc->sc_openf > 0 && bp != &rutbuf[UTUNIT(bp->b_dev)])
E 40
I 40
		if ((bp->b_flags&B_RAW) == 0 && sc->sc_openf > 0)
E 40
			sc->sc_openf = -1;
		/*
E 26
		 * Couldn't recover error.
		 */
D 2
		printf("ut%d: hard error bn%d er=%b cs2=%b\n", tjunit,
			bp->b_blkno, sc->sc_erreg, UTER_BITS,
			addr->utcs2, UTCS2_BITS);
E 2
I 2
D 33
		printf("ut%d: hard error bn%d cs1=%b er=%b cs2=%b ds=%b\n",
E 33
I 33
		tprintf(sc->sc_ttyp,
			"ut%d: hard error bn%d cs1=%b er=%b cs2=%b ds=%b\n",
E 33
			tjunit, bp->b_blkno, cs1, UT_BITS, sc->sc_erreg,
			UTER_BITS, cs2, UTCS2_BITS, sc->sc_dsreg, UTDS_BITS);
E 2
		bp->b_flags |= B_ERROR;
		goto opdone;
	}
I 26

E 26
ignoreerr:
	/*
I 26
	 * If we hit a tape mark update our position.
	 */
	if (sc->sc_dsreg & UTDS_TM && bp->b_flags & B_READ) {
		/*
		 * Set blkno and nxrec
		 */
		if (bp == &cutbuf[UTUNIT(bp->b_dev)]) {
			if (sc->sc_blkno > bdbtofsb(bp->b_blkno)) {
				sc->sc_nxrec =
				     bdbtofsb(bp->b_blkno) - addr->utfc;
				sc->sc_blkno = sc->sc_nxrec;
			} else {
				sc->sc_blkno =
				     bdbtofsb(bp->b_blkno) + addr->utfc;
				sc->sc_nxrec = sc->sc_blkno-1;
			}
		} else
			sc->sc_nxrec = bdbtofsb(bp->b_blkno);
		/*
		 * Note: if we get a tape mark on a read, the
		 * frame count register will be zero, so b_resid
		 * will be calculated correctly below.
		 */
		goto opdone;
	}
	/*
E 26
	 * Advance tape control FSM.
	 */
	switch (state) {

	case SIO:		/* read/write increments tape block # */
		sc->sc_blkno++;
I 39
		sc->sc_blks++;
		if (um->um_tab.b_errcnt)
			sc->sc_softerrs++;
E 39
D 2
		goto opdone;
E 2
I 2
		break;
E 2

D 26
	case SCOM:		/* forw/rev space updates current position */
E 26
I 26
	case SCOM:		/* motion commands update current position */
E 26
		if (bp == &cutbuf[UTUNIT(bp->b_dev)])
D 36
		switch (bp->b_command) {
E 36
I 36
		switch ((int)bp->b_command) {
E 36

		case UT_SFORW:
			sc->sc_blkno -= bp->b_repcnt;
			break;

		case UT_SREV:
			sc->sc_blkno += bp->b_repcnt;
			break;
I 26

		case UT_REWOFFL:
			addr->utcs1 = UT_CLEAR|UT_GO;
			break;
E 26
		}
D 2
		goto opdone;
E 2
I 2
		break;
E 2

	case SSEEK:
D 13
		sc->sc_blkno = dbtofsb(bp->b_blkno);
E 13
I 13
		sc->sc_blkno = bdbtofsb(bp->b_blkno);
E 13
		goto opcont;

I 2
	case SERASE:
		/*
		 * Completed erase of the inter-record gap due to a
		 * write error; now retry the write operation.
		 */
		um->um_tab.b_state = SERASED;
		goto opcont;

	case SREW:			/* clear attention bit */
		addr->utcs1 = UT_CLEAR|UT_GO;
		break;

E 2
	default:
I 2
		printf("bad state %d\n", state);
E 2
		panic("utintr");
	}

opdone:
	/*
	 * Reset error count and remove
	 * from device queue
	 */
	um->um_tab.b_errcnt = 0;
D 2
	dp->b_actf = bp->b_forw;
E 2
I 2
	dp->b_actf = bp->av_forw;
D 26
	bp->b_resid = bp->b_command&B_READ ?
		bp->b_bcount - ((-addr->utfc)&0xffff) : -addr->utwc<<1;
E 26
I 26
	/*
	 * For read command, frame count register contains
	 * actual length of tape record.  Otherwise, it
	 * holds negative residual count.
	 */
	if (state == SIO && um->um_cmd == UT_RCOM) {
		bp->b_resid = 0;
		if (bp->b_bcount > MASKREG(addr->utfc))
			bp->b_resid = bp->b_bcount - MASKREG(addr->utfc);
	} else
		bp->b_resid = MASKREG(-addr->utfc);
E 26
E 2
	ubadone(um);
	iodone(bp);
	/*
	 * Circulate slave to end of controller queue
	 * to give other slaves a chance
	 */
	um->um_tab.b_actf = dp->b_forw;
	if (dp->b_actf) {
		dp->b_forw = NULL;
		if (um->um_tab.b_actf == NULL)
			um->um_tab.b_actf = dp;
		else
			um->um_tab.b_actl->b_forw = dp;
		um->um_tab.b_actl = dp;
	}
	if (um->um_tab.b_actf == 0)
		return;
opcont:
	utstart(um);
I 4
}

/*
 * Watchdog timer routine.
 */
uttimer(dev)
	int dev;
{
	register struct tj_softc *sc = &tj_softc[TJUNIT(dev)];
I 5
	register short x;
E 5

	if (sc->sc_timo != INF && (sc->sc_timo -= 5) < 0) {
D 6
		printf("te%d: lost interrupt\n", TJUNIT(dev));
E 6
I 6
		printf("tj%d: lost interrupt\n", TJUNIT(dev));
E 6
		sc->sc_timo = INF;
D 5
		(void) spl5();
E 5
I 5
		x = spl5();
E 5
		utintr(UTUNIT(dev));
D 5
		(void) spl0();
E 5
I 5
		(void) splx(x);
E 5
	}
	timeout(uttimer, (caddr_t)dev, 5*hz);
E 4
D 40
}

/*
 * Raw interface for a read
 */
D 16
utread(dev)
E 16
I 16
utread(dev, uio)
E 16
	dev_t dev;
I 16
	struct uio *uio;
E 16
{
I 18
	int errno;
E 18
D 16
	utphys(dev);
E 16
I 16

D 18
	u.u_error = utphys(dev, uio);
E 16
	if (u.u_error)
		return;
D 16
	physio(utstrategy, &rutbuf[UTUNIT(dev)], dev, B_READ, minphys);
E 16
I 16
	physio(utstrategy, &rutbuf[UTUNIT(dev)], dev, B_READ, minphys, uio);
E 18
I 18
	errno = utphys(dev, uio);
	if (errno)
		return (errno);
	return (physio(utstrategy, &rutbuf[UTUNIT(dev)], dev, B_READ, minphys, uio));
E 18
E 16
}

/*
 * Raw interface for a write
 */
D 17
utwrite(dev)
E 17
I 17
utwrite(dev, uio)
E 17
I 16
	dev_t dev;
I 17
	struct uio *uio;
E 17
E 16
{
D 16
	utphys(dev);
E 16
I 16
D 17
	utphys(dev, 0);
E 17
I 17
D 18
	u.u_error = utphys(dev, uio);
E 17
E 16
	if (u.u_error)
		return;
D 16
	physio(utstrategy, &rutbuf[UTUNIT(dev)], dev, B_WRITE, minphys);
E 16
I 16
D 17
	physio(utstrategy, &rutbuf[UTUNIT(dev)], dev, B_WRITE, minphys, 0);
E 17
I 17
	physio(utstrategy, &rutbuf[UTUNIT(dev)], dev, B_WRITE, minphys, uio);
E 18
I 18
	int errno;

	errno = utphys(dev, uio);
	if (errno)
		return (errno);
	return (physio(utstrategy, &rutbuf[UTUNIT(dev)], dev, B_WRITE, minphys, uio));
E 18
E 17
E 16
}

/*
 * Check for valid device number dev and update our notion
 * of where we are on the tape
 */
D 16
utphys(dev)
E 16
I 16
utphys(dev, uio)
E 16
	dev_t dev;
I 16
	struct uio *uio;
E 16
{
	register int tjunit = TJUNIT(dev);
	register struct tj_softc *sc;
	register struct uba_device *ui;
D 2
	register daddr_t a;
E 2

D 17
	if (tjunit >= NTJ || (ui=tjdinfo[tjunit]) == 0 || ui->ui_alive == 0) {
		u.u_error = ENXIO;
		return;
	}
E 17
I 17
	if (tjunit >= NTJ || (ui=tjdinfo[tjunit]) == 0 || ui->ui_alive == 0)
		return (ENXIO);
E 17
D 2
	a = u.u_offset >> 9;
E 2
	sc = &tj_softc[tjunit];
D 2
	sc->sc_blkno = dbtofsb(a);
	sc->sc_nxrec = dbtofsb(a)+1;
E 2
I 2
D 13
	sc->sc_blkno = dbtofsb(u.u_offset>>9);
E 13
I 13
D 16
	sc->sc_blkno = bdbtofsb(u.u_offset>>9);
E 16
I 16
D 17
	if (uio)
		sc->sc_blkno = bdbtofsb(uio->uio_offset>>9);
	else
		sc->sc_blkno = bdbtofsb(u.u_offset>>9);
E 17
I 17
	sc->sc_blkno = bdbtofsb(uio->uio_offset>>9);
E 17
E 16
E 13
	sc->sc_nxrec = sc->sc_blkno+1;
I 17
	return (0);
E 40
E 17
E 2
}

/*ARGSUSED*/
D 15
utioctl(dev, cmd, addr, flag)
E 15
I 15
utioctl(dev, cmd, data, flag)
E 15
	dev_t dev;
D 15
	caddr_t addr;
E 15
I 15
	caddr_t data;
E 15
{
	register struct tj_softc *sc = &tj_softc[TJUNIT(dev)];
	register struct buf *bp = &cutbuf[UTUNIT(dev)];
	register callcount;
	int fcount;
D 15
	struct mtop mtop;
	struct mtget mtget;
E 15
I 15
	struct mtop *mtop;
	struct mtget *mtget;
E 15
	/* we depend of the values and order of the MT codes here */
	static utops[] =
      {UT_WEOF,UT_SFORWF,UT_SREVF,UT_SFORW,UT_SREV,UT_REW,UT_REWOFFL,UT_SENSE};

	switch (cmd) {

	case MTIOCTOP:
D 15
		if (copyin((caddr_t)addr, (caddr_t)&mtop, sizeof(mtop))) {
			u.u_error = EFAULT;
			return;
		}
		switch(mtop.mt_op) {
E 15
I 15
		mtop = (struct mtop *)data;
		switch(mtop->mt_op) {
E 15

		case MTWEOF:
I 29
		case MTFSF: case MTBSF:
		case MTFSR: case MTBSR:
E 29
D 15
			callcount = mtop.mt_count;
E 15
I 15
			callcount = mtop->mt_count;
E 15
			fcount = 1;
			break;

D 29
		case MTFSF: case MTBSF:
		case MTFSR: case MTBSR:
			callcount = 1;
D 15
			fcount = mtop.mt_count;
E 15
I 15
			fcount = mtop->mt_count;
E 15
			break;

E 29
		case MTREW: case MTOFFL: case MTNOP:
			callcount = 1;
			fcount = 1;
			break;

		default:
D 20
			u.u_error = ENXIO;
			return;
E 20
I 20
			return (ENXIO);
E 20
		}
D 20
		if (callcount <= 0 || fcount <= 0) {
			u.u_error = ENXIO;
			return;
		}
E 20
I 20
		if (callcount <= 0 || fcount <= 0)
			return (EINVAL);
E 20
		while (--callcount >= 0) {
D 15
			utcommand(dev, utops[mtop.mt_op], fcount);
E 15
I 15
			utcommand(dev, utops[mtop->mt_op], fcount);
E 15
D 2
			if ((mtop.mt_op == MTFSR || mtop.mt_op == MTBSR) &&
E 2
I 2
D 29
			/* note this depends on the mtop values */
D 15
			if ((mtop.mt_op >= MTFSF || mtop.mt_op <= MTBSR) &&
E 15
I 15
D 26
			if ((mtop->mt_op >= MTFSF || mtop->mt_op <= MTBSR) &&
E 26
I 26
			if ((mtop->mt_op >= MTFSF && mtop->mt_op <= MTBSR) &&
E 26
E 15
E 2
D 22
			    bp->b_resid) {
E 22
I 22
			    bp->b_resid)
E 22
D 20
				u.u_error = EIO;
				break;
			}
E 20
I 20
				return (EIO);
E 29
E 20
			if ((bp->b_flags&B_ERROR) || (sc->sc_dsreg&UTDS_BOT))
				break;
		}
D 20
		geterror(bp);
		return;
E 20
I 20
D 21
		geterror(bp);		/* XXX */
		return (u.u_error);	/* XXX */
E 21
I 21
		return (geterror(bp));
E 21
E 20

	case MTIOCGET:
D 15
		mtget.mt_dsreg = sc->sc_dsreg;
		mtget.mt_erreg = sc->sc_erreg;
		mtget.mt_resid = sc->sc_resid;
		mtget.mt_type = MT_ISUT;
		if (copyout((caddr_t)&mtget, addr, sizeof(mtget)))
			u.u_error = EFAULT;
E 15
I 15
		mtget = (struct mtget *)data;
		mtget->mt_dsreg = sc->sc_dsreg;
		mtget->mt_erreg = sc->sc_erreg;
		mtget->mt_resid = sc->sc_resid;
		mtget->mt_type = MT_ISUT;
E 15
D 20
		return;
E 20
I 20
		break;
E 20

	default:
D 20
		u.u_error = ENXIO;
E 20
I 20
		return (ENXIO);
E 20
	}
I 20
	return (0);
E 20
}

utreset(uban)
	int uban;
{
	register struct uba_ctlr *um;
	register ut11, tjunit;
	register struct uba_device *ui;
	register struct buf *dp;

	for (ut11 = 0; ut11 < NUT; ut11++) {
		if ((um = utminfo[ut11]) == 0 || um->um_alive == 0 ||
		   um->um_ubanum != uban)
			continue;
		printf(" ut%d", ut11);
D 2
		um->um_tab.b_active = 0;
E 2
I 2
		um->um_tab.b_state = 0;
E 2
		um->um_tab.b_actf = um->um_tab.b_actl = 0;
		if (um->um_ubinfo) {
			printf("<%d>", (um->um_ubinfo>>28)&0xf);
D 23
			ubadone(um);
E 23
I 23
			um->um_ubinfo = 0;
E 23
		}
		((struct utdevice *)(um->um_addr))->utcs1 = UT_CLEAR|UT_GO;
I 2
		((struct utdevice *)(um->um_addr))->utcs2 |= UTCS2_CLR;
E 2
		for (tjunit = 0; tjunit < NTJ; tjunit++) {
			if ((ui = tjdinfo[tjunit]) == 0 || ui->ui_mi != um ||
			    ui->ui_alive == 0)
				continue;
			dp = &tjutab[tjunit];
D 2
			dp->b_active = 0;
E 2
I 2
			dp->b_state = 0;
E 2
			dp->b_forw = 0;
			if (um->um_tab.b_actf == NULL)
				um->um_tab.b_actf = dp;
			else
				um->um_tab.b_actl->b_forw = dp;
			um->um_tab.b_actl = dp;
			if (tj_softc[tjunit].sc_openf > 0)
				tj_softc[tjunit].sc_openf = -1;
		}
		utstart(um);
	}
}

/*
 * Do a stand-alone core dump to tape --
 * from here down, routines are used only in dump context
 */
#define	DBSIZE	20

utdump()
{
	register struct uba_device *ui;
	register struct uba_regs *up;
D 2
	register struct utdevice *utaddr;
E 2
I 2
	register struct utdevice *addr;
E 2
	int blk, num = maxfree;
	int start = 0;

#define	phys(a,b)		((b)((int)(a)&0x7fffffff))
	if (tjdinfo[0] == 0)
		return (ENXIO);
	ui = phys(tjdinfo[0], struct uba_device *);
	up = phys(ui->ui_hd, struct uba_hd *)->uh_physuba;
D 9
	ubainit();
E 9
I 9
	ubainit(up);
E 9
	DELAY(1000000);
D 2
	utwait(utaddr);
	utaddr = (struct utdevice *)ui->ui_physaddr;
	/* do it at 1600 bpi so tape can be read on other machines */
	utaddr->uttc = UT_PE|PDP11FMT;	/* implicit slave 0 or-ed in */
	utaddr->utcs1 = UT_CLEAR|UT_GO;
E 2
I 2
D 9
	utwait(addr);
E 9
	addr = (struct utdevice *)ui->ui_physaddr;
I 9
	utwait(addr);
E 9
	/*
	 * Be sure to set the appropriate density here.  We use
	 * 6250, but maybe it should be done at 1600 to insure the
	 * tape can be read by most any other tape drive available.
	 */
	addr->uttc = UT_GCR|PDP11FMT;	/* implicit slave 0 or-ed in */
	addr->utcs1 = UT_CLEAR|UT_GO;
E 2
	while (num > 0) {
		blk = num > DBSIZE ? DBSIZE : num;
D 2
		utdwrite(start, blk, utaddr, up);
E 2
I 2
		utdwrite(start, blk, addr, up);
		if ((addr->utds&UTDS_ERR) || (addr->utcs1&UT_TRE))
			return(EIO);
E 2
		start += blk;
		num -= blk;
	}
D 2
	uteof(utaddr);
	uteof(utaddr);
	utwait(utaddr);
	if (utaddr->utds&UTDS_ERR)
E 2
I 2
	uteof(addr);
	uteof(addr);
	utwait(addr);
	if ((addr->utds&UTDS_ERR) || (addr->utcs1&UT_TRE))
E 2
		return(EIO);
D 2
	utaddr->utcs1 = UT_REW|UT_GO;
E 2
I 2
	addr->utcs1 = UT_REW|UT_GO;
E 2
	return (0);
}

D 2
utdwrite(dbuf, num, utaddr, up)
E 2
I 2
utdwrite(dbuf, num, addr, up)
E 2
	register dbuf, num;
D 2
	register struct utdevice *utaddr;
E 2
I 2
	register struct utdevice *addr;
E 2
	struct uba_regs *up;
{
	register struct pte *io;
	register int npf;

D 2
	utwait(utaddr);
E 2
I 2
	utwait(addr);
E 2
	io = up->uba_map;
	npf = num + 1;
	while (--npf != 0)
		*(int *)io++ = (dbuf++ | (1<<UBAMR_DPSHIFT) | UBAMR_MRV);
	*(int *)io = 0;
D 2
	utaddr->utwc = -((num*NBPG)<<1);
	utaddr->utba = 0;
	utaddr->utcs1 = UT_WCOM|UT_GO;
E 2
I 2
	addr->utwc = -((num*NBPG)>>1);
	addr->utfc = -(num*NBPG);
	addr->utba = 0;
	addr->utcs1 = UT_WCOM|UT_GO;
E 2
}

D 2
utwait(utaddr)
	struct utdevice *utaddr;
E 2
I 2
utwait(addr)
	struct utdevice *addr;
E 2
{
	register s;

	do
D 2
		s = utaddr->utds;
E 2
I 2
		s = addr->utds;
E 2
	while ((s&UTDS_DRY) == 0);
}

D 2
uteof(utaddr)
	struct utdevice *utaddr;
E 2
I 2
uteof(addr)
	struct utdevice *addr;
E 2
{

D 2
	utwait(utaddr);
	utaddr->utcs1 = UT_WEOF|UT_GO;
E 2
I 2
	utwait(addr);
	addr->utcs1 = UT_WEOF|UT_GO;
E 2
}
#endif
E 1
