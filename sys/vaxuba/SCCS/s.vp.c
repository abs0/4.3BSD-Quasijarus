h22664
s 00001/00001/00352
d D 7.1 86/06/05 01:24:02 mckusick 40 39
c 4.3BSD release version
e
s 00000/00001/00353
d D 6.7 86/02/20 19:55:02 karels 39 38
c lint
e
s 00007/00001/00347
d D 6.6 85/06/08 14:30:59 mckusick 38 37
c Add copyright
e
s 00001/00001/00347
d D 6.5 85/04/10 11:35:12 karels 37 36
c setstate doesn't make anything else happen (from tef)
e
s 00012/00012/00336
d D 6.4 84/08/29 20:12:26 bloom 36 35
c Change to includes.  No more ../h
e
s 00144/00287/00204
d D 6.3 83/09/25 12:13:15 karels 35 34
c restore old (working) version
e
s 00001/00003/00490
d D 6.2 83/09/20 16:52:30 karels 34 33
c always reset vector from 200->174 (until probe done right)
e
s 00000/00000/00493
d D 6.1 83/07/29 07:31:06 sam 33 32
c 4.2 distribution
e
s 00287/00142/00206
d D 4.26 83/06/16 14:42:59 sam 32 31
c checked in for ralph
e
s 00005/00007/00343
d D 4.25 83/03/31 19:16:59 sam 31 30
c update ioctls
e
s 00001/00000/00349
d D 4.24 83/03/10 17:16:32 sam 30 29
c must have ioctl.h before vcmd.h
e
s 00001/00000/00348
d D 4.23 83/02/10 20:15:43 sam 29 27
c hz now only in kernel.h
e
s 00002/00000/00348
d R 4.23 83/02/10 20:03:42 sam 28 27
c hz now only in kernel.h
e
s 00002/00001/00346
d D 4.22 82/12/17 12:06:12 sam 27 26
c sun merge
e
s 00010/00017/00337
d D 4.21 82/10/17 11:52:32 root 26 25
c ioctl/open return errors, not u.u_error; remove ubarelses (it is
c now done in uba.c); add open routines to some disk drivers
e
s 00003/00003/00351
d D 4.20 82/10/10 22:38:56 root 25 24
c minor fixes relating to u.u_error handling
e
s 00003/00002/00351
d D 4.19 82/10/10 17:30:47 root 24 23
c header files for vax are in their place
e
s 00005/00005/00348
d D 4.18 82/09/12 03:12:47 root 23 22
c 
e
s 00005/00001/00348
d D 4.17 82/08/22 21:23:01 root 22 21
c fully uio()'d
e
s 00002/00001/00347
d D 4.16 82/08/13 00:19:41 root 21 20
c 
e
s 00001/00000/00347
d D 4.15 82/07/15 19:58:04 kre 20 19
c probe routines return size of unibus dev regs to reserve space
e
s 00001/00001/00346
d D 4.14 82/05/19 14:48:45 sam 19 18
c it's a kludge, so keep based on the machine name
e
s 00001/00001/00346
d D 4.13 82/05/19 10:28:49 root 18 17
c took out explicit reference to ERNIE for vpprobe and put in OVPR
e
s 00001/00001/00346
d D 4.12 82/05/04 13:38:47 sam 17 16
c CAD kludges and cleanup conf.c
e
s 00005/00000/00342
d D 4.11 82/04/01 18:35:01 sam 16 15
c missing select routines
e
s 00004/00000/00338
d D 4.10 81/11/18 15:52:15 wnj 15 14
c lint
e
s 00012/00001/00326
d D 4.9 81/04/02 01:44:27 wnj 14 13
c fixes from ernie
e
s 00192/00115/00135
d D 4.8 81/03/10 16:57:05 wnj 13 12
c ht typos; mba maintain dk_busy for seeks; up minor fixes; va and vp new working versions
e
s 00001/00001/00249
d D 4.7 81/03/09 01:56:16 wnj 12 11
c %G% -> %E%
e
s 00001/00001/00249
d D 4.6 81/02/27 03:15:28 wnj 11 10
c s/HZ/hz/
e
s 00002/00002/00248
d D 4.5 80/12/30 18:51:39 wnj 10 9
c ubafree() becomes ubarelse() to fix race conditions
e
s 00002/00002/00248
d D 4.4 80/12/30 18:18:58 wnj 9 8
c fix ubafree(i), i = 0 to be UBAFREECLR(i) to avoid races
e
s 00001/00001/00249
d D 4.3 80/12/19 11:44:42 wnj 8 7
c s,../conf/,,
e
s 00002/00001/00248
d D 4.2 80/12/17 10:46:55 wnj 7 6
c set all address bits
e
s 00000/00000/00249
d D 4.1 80/11/09 16:53:16 bill 6 5
c stamp for 4bsd
e
s 00007/00006/00242
d D 3.5 80/10/19 22:16:33 bill 5 4
c ../conf/*.h
e
s 00021/00004/00227
d D 3.4 80/06/22 12:35:27 bill 4 3
c vpreset
e
s 00001/00001/00230
d D 3.3 80/06/07 02:50:08 bill 3 2
c %H%->%G%
e
s 00011/00011/00220
d D 3.2 80/05/08 10:25:21 bill 2 1
c VOID=>void
e
s 00231/00000/00000
d D 3.1 80/04/09 16:05:32 bill 1 0
c date and time created 80/04/09 16:05:32 by bill
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
D 12
/*	%M%	%I%	%G%	*/
E 12
I 12
D 38
/*	%M%	%I%	%E%	*/
E 38
I 38
/*
D 40
 * Copyright (c) 1982 Regents of the University of California.
E 40
I 40
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 40
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 38
E 12
E 3

I 5
D 8
#include "../conf/vp.h"
E 8
I 8
#include "vp.h"
E 8
#if NVP > 0
/*
 * Versatec matrix printer/plotter
 * dma interface driver
I 14
 *
 * SETUP NOTES:
 *	Set up both print and plot interrupts to go through the same vector
I 35
 *	(or kludge probe to reset second vector to first;
 *	default 174/200 is already handled).
E 35
 *	Give the address of the plcsr register in the config specification
E 14
 */
I 27
#include "../machine/pte.h"

E 27
E 5
D 4
#ifdef ERNIE
E 4
D 36
#include "../h/param.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/buf.h"
#include "../h/systm.h"
#include "../h/map.h"
I 30
#include "../h/ioctl.h"
E 30
D 27
#include "../h/pte.h"
E 27
D 13
#include "../h/uba.h"
E 13
I 13
D 24
#include "../h/ubavar.h"
#include "../h/ubareg.h"
E 24
#include "../h/vcmd.h"
I 21
#include "../h/uio.h"
I 29
#include "../h/kernel.h"
E 36
I 36
#include "param.h"
#include "dir.h"
#include "user.h"
#include "buf.h"
#include "systm.h"
#include "map.h"
#include "ioctl.h"
#include "vcmd.h"
#include "uio.h"
#include "kernel.h"
E 36
E 29
I 24

D 36
#include "../vaxuba/ubavar.h"
#include "../vaxuba/ubareg.h"
E 36
I 36
#include "ubavar.h"
#include "ubareg.h"
E 36
I 32
D 35
#include "../vaxuba/vpreg.h"
E 35
E 32
E 24
E 21
E 13

I 32
D 35
int	vpdebug = 0;
#define dprintf if(vpdebug)printf

E 35
E 32
D 5
/*
 * Versatec matrix printer/plotter
 * dma interface driver
 */
E 5
D 13
int	vpbdp = 1;

E 13
unsigned minvpph();

I 35
#define	VPPRI	(PZERO-1)

struct	vpdevice {
	short	plbcr;
	short	pbxaddr;
	short	prbcr;
	u_short pbaddr;
	short	plcsr;
	short	plbuf;
	short	prcsr;
	u_short prbuf;
};

#define	VP_ERROR	0100000
#define	VP_DTCINTR	0040000
#define	VP_DMAACT	0020000
#define	VP_READY	0000200
#define	VP_IENABLE	0000100
#define	VP_TERMCOM	0000040
#define	VP_FFCOM	0000020
#define	VP_EOTCOM	0000010
#define	VP_CLRCOM	0000004
#define	VP_RESET	0000002
#define	VP_SPP		0000001

E 35
D 32
#define	VPPRI	(PZERO-1)

D 13
struct	vpregs {
E 13
I 13
struct	vpdevice {
E 13
	short	plbcr;
D 7
	short	fill;
E 7
I 7
	short	pbxaddr;
E 7
	short	prbcr;
D 13
	unsigned short pbaddr;
E 13
I 13
	u_short pbaddr;
E 13
	short	plcsr;
	short	plbuf;
	short	prcsr;
D 13
	unsigned short prbuf;
E 13
I 13
	u_short prbuf;
E 13
};

D 5
#define	VPADDR	((struct vpregs *)(UBA0_DEV + 0177500))

E 5
D 13
#define	ERROR	0100000
#define	DTCINTR	040000
#define	DMAACT	020000
#define	READY	0200
#define	IENABLE	0100
#define	TERMCOM	040
#define	FFCOM	020
#define	EOTCOM	010
#define	CLRCOM	04
#define	RESET	02
#define	SPP	01
E 13
I 13
#define	VP_ERROR	0100000
#define	VP_DTCINTR	0040000
#define	VP_DMAACT	0020000
#define	VP_READY	0000200
#define	VP_IENABLE	0000100
#define	VP_TERMCOM	0000040
#define	VP_FFCOM	0000020
#define	VP_EOTCOM	0000010
#define	VP_CLRCOM	0000004
#define	VP_RESET	0000002
#define	VP_SPP		0000001
E 13

E 32
D 13
struct {
	int	vp_state;
	int	vp_count;
	int	vp_bufp;
I 4
	struct	buf *vp_bp;
E 4
} vp11;
int	vp_ubinfo;
E 13
I 13
struct vp_softc {
I 32
D 35
	u_char	sc_openf;
	u_char	sc_iostate;
	short	sc_tocnt;
E 35
E 32
	int	sc_state;
	int	sc_count;
I 35
	int	sc_bufp;
	struct	buf *sc_bp;
	int	sc_ubinfo;
E 35
D 32
	int	sc_bufp;
	struct	buf *sc_bp;
	int	sc_ubinfo;
E 32
} vp_softc[NVP];
E 13

D 13
struct	buf rvpbuf;
E 13
I 13
/* sc_state bits */
I 35
#define	VPSC_BUSY	0001000
E 35
D 32
#define	VPSC_BUSY	0001000
E 32
#define	VPSC_MODE	0000700
I 35
#define	VPSC_SPP	0000400
#define	VPSC_PLOT	0000200
#define	VPSC_PRINT	0000100
E 35
D 32
#define	VPSC_SPP	0000400
#define	VPSC_PLOT	0000200
#define	VPSC_PRINT	0000100
E 32
#define	VPSC_CMNDS	0000076
I 35
#define	VPSC_OPEN	0000001
E 35
D 32
#define	VPSC_OPEN	0000001
E 32
E 13

I 32
D 35
/* sc_iostate bits */
#define VPS_IDLE	0
#define VPS_WANT	1
#define VPS_DMA		4

/* sc_tocnt */
#define IDLE 0
#define ACTIVE 1

E 35
E 32
D 13
#define	VISOPEN	01
#define	CMNDS	076
#define	MODE	0700
#define	PRINT	0100
#define	PLOT	0200
#define	PPLOT	0400
#define	VBUSY	01000
E 13
I 13
struct	uba_device *vpdinfo[NVP];
E 13

D 13
vpopen()
E 13
I 13
#define	VPUNIT(dev)	(minor(dev))

struct	buf rvpbuf[NVP];

D 32
int	vpprobe(), vpattach();
E 32
I 32
D 35
int	vpprobe(), vpslave(), vpattach(), vpdgo();
E 35
I 35
int	vpprobe(), vpattach();
E 35
E 32
struct	uba_device *vpdinfo[NVP];
I 32
D 35
struct	uba_ctlr *vpminfo[NVP];
struct	buf vpbhdr[NVP];
E 35
E 32
u_short	vpstd[] = { 0777500, 0 };
struct	uba_driver vpdriver =
D 32
    { vpprobe, 0, vpattach, 0, vpstd, "vp", vpdinfo };
E 32
I 32
D 35
    { vpprobe, vpslave, vpattach, vpdgo, vpstd, "zv", vpdinfo, "vp", vpminfo };
E 35
I 35
    { vpprobe, 0, vpattach, 0, vpstd, "vp", vpdinfo };
E 35
E 32

vpprobe(reg)
	caddr_t reg;
E 13
{
I 13
	register int br, cvec;		/* value-result */
	register struct vpdevice *vpaddr = (struct vpdevice *)(reg-010);
E 13

I 15
#ifdef lint
	br = 0; cvec = br; br = cvec;
	vpintr(0);
#endif
E 15
D 13
	if (vp11.vp_state & VISOPEN) {
E 13
I 13
	vpaddr->prcsr = VP_IENABLE|VP_DTCINTR;
	vpaddr->pbaddr = 0;
	vpaddr->pbxaddr = 0;
D 14
	vpaddr->plbcr = 1;
E 14
I 14
	vpaddr->prbcr = 1;
E 14
	DELAY(10000);
	vpaddr->prcsr = 0;
I 14
D 17
#ifdef ERNIE
E 17
I 17
D 18
#if ERNIE || CAD
E 18
I 18
D 19
#if OVPR || CAD
E 19
I 19
D 32
#if ERNIE || CAD || UCBVAX
E 32
I 32
D 34
#if ERNIE || CAD 
E 32
E 19
E 18
E 17
	/* UNTIL REWIRED, GET INTERRUPT AT 200 BUT WANT 174 */
E 34
I 34
D 35
	/* GET INTERRUPT AT 200 BUT WANT 174 IF HAVE TWO VECTORS */
E 35
I 35
	/* GET INTERRUPT AT SECOND VECTOR BUT WANT FIRST */
E 35
E 34
	if (cvec == 0200) {
		printf("vp reset vec from 200 to 174\n");
		cvec = 0174;
	}
D 34
#endif
E 34
I 20
	return (sizeof (struct vpdevice));
E 20
E 14
}

/*ARGSUSED*/
I 32
D 35
vpslave(ui, reg)
	struct uba_device *ui;
	caddr_t reg;
{

	ui->ui_dk = 0;
	return (ui->ui_unit <= 0);
}

/*ARGSUSED*/
E 35
E 32
vpattach(ui)
	struct uba_device *ui;
{

I 32
D 35
	/*
	 * To adjust the standard address back to the beginning of
	 * the register field.
	 */
E 35
E 32
	ui->ui_addr -= 010;
	ui->ui_physaddr -= 010;
I 32
D 35
	ui->ui_mi->um_tab.b_actf = &vpbhdr[ui->ui_unit];
	ui->ui_mi->um_addr -= 010;
E 35
E 32
}

I 32
D 35


E 35
E 32
vpopen(dev)
	dev_t dev;
{
	register struct vp_softc *sc;
	register struct vpdevice *vpaddr;
	register struct uba_device *ui;
I 32
D 35
	int unit = VPUNIT(dev);
	int error;
E 35
E 32

D 32
	if (VPUNIT(dev) >= NVP ||
	    ((sc = &vp_softc[minor(dev)])->sc_state&VPSC_OPEN) ||
D 26
	    (ui = vpdinfo[VPUNIT(dev)]) == 0 || ui->ui_alive == 0) {
E 13
		u.u_error = ENXIO;
		return;
	}
E 26
I 26
	    (ui = vpdinfo[VPUNIT(dev)]) == 0 || ui->ui_alive == 0)
E 32
I 32
D 35
	if (unit >= NVP || ((sc = &vp_softc[unit])->sc_openf) ||
	    (ui = vpdinfo[unit]) == 0 || ui->ui_alive == 0)
E 35
I 35
	if (VPUNIT(dev) >= NVP ||
	    ((sc = &vp_softc[minor(dev)])->sc_state&VPSC_OPEN) ||
	    (ui = vpdinfo[VPUNIT(dev)]) == 0 || ui->ui_alive == 0)
E 35
E 32
		return (ENXIO);
E 26
D 13
	vp11.vp_state = VISOPEN | PRINT | CLRCOM | RESET;
	vp11.vp_count = 0;
	VPADDR->prcsr = IENABLE | DTCINTR;
	vptimo();
	while (vp11.vp_state & CMNDS) {
E 13
I 13
	vpaddr = (struct vpdevice *)ui->ui_addr;
D 32
	sc->sc_state = VPSC_OPEN|VPSC_PRINT | VP_CLRCOM|VP_RESET;
	sc->sc_count = 0;
E 32
I 32
D 35
	sc->sc_openf = 1;
	sc->sc_state = VPRINT;
	sc->sc_iostate = VPS_IDLE;
	dprintf("vpopen: called\n");
E 35
I 35
	sc->sc_state = VPSC_OPEN|VPSC_PRINT | VP_CLRCOM|VP_RESET;
	sc->sc_count = 0;
E 35
E 32
	vpaddr->prcsr = VP_IENABLE|VP_DTCINTR;
D 32
	vptimo(dev);
	while (sc->sc_state & VPSC_CMNDS) {
E 13
D 2
		VOID spl4();
E 2
I 2
		(void) spl4();
E 2
D 13
		if (vperror(READY)) {
			vpclose();
E 13
I 13
		if (vpwait(dev)) {
			vpclose(dev);
E 13
D 26
			u.u_error = EIO;
			return;
E 26
I 26
			return (EIO);
E 26
		}
D 13
		vpstart();
E 13
I 13
		vpstart(dev);
E 13
D 2
		VOID spl0();
E 2
I 2
		(void) spl0();
E 2
	}
I 26
	return (0);
E 32
I 32
D 35
	error = vpcmd(dev,VP_CLRCOM|VP_RESET);
	if (error)
		vpclose(dev);
	dprintf("vpopen: returned %d\n",error);
	return (error);
E 35
I 35
	vptimo(dev);
	while (sc->sc_state & VPSC_CMNDS) {
		(void) spl4();
		if (vpwait(dev)) {
			vpclose(dev);
			return (EIO);
		}
		vpstart(dev);
		(void) spl0();
	}
	return (0);
E 35
E 32
E 26
}

vpstrategy(bp)
	register struct buf *bp;
{
D 32
	register int e;
E 32
I 32
D 35
	register int s;
E 35
I 35
	register int e;
E 35
E 32
I 13
	register struct vp_softc *sc = &vp_softc[VPUNIT(bp->b_dev)];
	register struct uba_device *ui = vpdinfo[VPUNIT(bp->b_dev)];
	register struct vpdevice *vpaddr = (struct vpdevice *)ui->ui_addr;
I 32
D 35
	register struct uba_ctlr *um;
E 35
E 32
E 13

D 2
	VOID spl4();
E 2
I 2
D 32
	(void) spl4();
E 2
D 13
	while (vp11.vp_state & VBUSY)
		sleep((caddr_t)&vp11, VPPRI);
	vp11.vp_state |= VBUSY;
D 2
	VOID spl0();
E 2
I 2
D 4
	(void) spl0();
E 4
I 4
	vp11.vp_bp = bp;
E 4
E 2
	vp_ubinfo = ubasetup(bp, vpbdp);
	vp11.vp_bufp = vp_ubinfo & 0x3ffff;
D 2
	VOID spl4();
E 2
I 2
D 4
	(void) spl4();
E 4
E 2
	if (e = vperror(READY))
E 13
I 13
	while (sc->sc_state & VPSC_BUSY)
		sleep((caddr_t)sc, VPPRI);
	sc->sc_state |= VPSC_BUSY;
	sc->sc_bp = bp;
	sc->sc_ubinfo = ubasetup(ui->ui_ubanum, bp, UBA_NEEDBDP);
	if (e = vpwait(bp->b_dev))
E 13
		goto brkout;
D 13
	vp11.vp_count = bp->b_bcount;
	vpstart();
	while ((vp11.vp_state&PLOT ? VPADDR->plcsr : VPADDR->prcsr) & DMAACT)
		sleep((caddr_t)&vp11, VPPRI);
	vp11.vp_count = 0;
	vp11.vp_bufp = 0;
	if ((vp11.vp_state&MODE) == PPLOT)
		vp11.vp_state = (vp11.vp_state &~ MODE) | PLOT;
E 13
I 13
	sc->sc_count = bp->b_bcount;
	vpstart(bp->b_dev);
	while (((sc->sc_state&VPSC_PLOT) ? vpaddr->plcsr : vpaddr->prcsr) & VP_DMAACT)
		sleep((caddr_t)sc, VPPRI);
	sc->sc_count = 0;
	if ((sc->sc_state&VPSC_MODE) == VPSC_SPP)
		sc->sc_state = (sc->sc_state &~ VPSC_MODE) | VPSC_PLOT;
E 13
D 2
	VOID spl0();
E 2
I 2
	(void) spl0();
E 2
brkout:
D 9
	ubafree(vp_ubinfo), vp_ubinfo = 0;
E 9
I 9
D 10
	UBAFREECLR(vp_ubinfo);
E 10
I 10
D 13
	ubarelse(&vp_ubinfo);
E 10
E 9
	vp11.vp_state &= ~VBUSY;
I 4
	vp11.vp_bp = 0;
E 13
I 13
	ubarelse(ui->ui_ubanum, &sc->sc_ubinfo);
	sc->sc_state &= ~VPSC_BUSY;
	sc->sc_bp = 0;
E 13
E 4
D 25
	iodone(bp);
E 25
	if (e)
E 32
I 32
D 35
	dprintf("vpstrategy(%x)\n", bp);
	ui = vpdinfo[VPUNIT(bp->b_dev)];
	if (ui == 0 || ui->ui_alive == 0) {
E 35
I 35
	(void) spl4();
	while (sc->sc_state & VPSC_BUSY)
		sleep((caddr_t)sc, VPPRI);
	sc->sc_state |= VPSC_BUSY;
	sc->sc_bp = bp;
	sc->sc_ubinfo = ubasetup(ui->ui_ubanum, bp, UBA_NEEDBDP);
	if (e = vpwait(bp->b_dev))
		goto brkout;
	sc->sc_count = bp->b_bcount;
	vpstart(bp->b_dev);
	while (((sc->sc_state&VPSC_PLOT) ? vpaddr->plcsr : vpaddr->prcsr) & VP_DMAACT)
		sleep((caddr_t)sc, VPPRI);
	sc->sc_count = 0;
	if ((sc->sc_state&VPSC_MODE) == VPSC_SPP)
		sc->sc_state = (sc->sc_state &~ VPSC_MODE) | VPSC_PLOT;
	(void) spl0();
brkout:
	ubarelse(ui->ui_ubanum, &sc->sc_ubinfo);
	sc->sc_state &= ~VPSC_BUSY;
	sc->sc_bp = 0;
	if (e)
E 35
E 32
D 25
		u.u_error = EIO;
E 25
I 25
		bp->b_flags |= B_ERROR;
D 32
	iodone(bp);
E 25
D 13
	wakeup((caddr_t)&vp11);
E 13
I 13
	wakeup((caddr_t)sc);
E 32
I 32
D 35
		iodone(bp);
		return;
	}
	um = ui->ui_mi;
	bp->b_actf = NULL;
	s = spl4();
	if (um->um_tab.b_actf->b_actf == NULL)
		um->um_tab.b_actf->b_actf = bp;
	else {
		printf("bp = 0x%x, um->um_tab.b_actf->b_actf = 0x%x\n",
			bp, um->um_tab.b_actf->b_actf);
		panic("vpstrategy");
		um->um_tab.b_actf->b_actl->b_forw = bp;
	}
	um->um_tab.b_actf->b_actl = bp;
	bp = um->um_tab.b_actf;
	dprintf("vpstrategy: bp=%x actf=%x active=%d\n",
		bp, bp->b_actf, bp->b_active);
	if (bp->b_actf && bp->b_active == 0)
		(void) vpstart(um);
	splx(s);
E 35
I 35
	iodone(bp);
	wakeup((caddr_t)sc);
E 35
E 32
E 13
}

int	vpblock = 16384;

unsigned
minvpph(bp)
D 13
struct buf *bp;
E 13
I 13
	struct buf *bp;
E 13
{

	if (bp->b_bcount > vpblock)
		bp->b_bcount = vpblock;
}

/*ARGSUSED*/
D 23
vpwrite(dev)
E 23
I 23
vpwrite(dev, uio)
E 23
I 13
	dev_t dev;
I 23
	struct uio *uio;
E 23
E 13
{

D 13
	physio(vpstrategy, &rvpbuf, dev, B_WRITE, minvpph);
E 13
I 13
D 21
	physio(vpstrategy, &rvpbuf[VPUNIT(dev)], dev, B_WRITE, minvpph);
E 21
I 21
D 22
	physio(vpstrategy, &rvpbuf[VPUNIT(dev)], dev, B_WRITE, minvpph, 0);
E 22
I 22
	if (VPUNIT(dev) >= NVP)
D 23
		u.u_error = ENXIO;
	else
		physio(vpstrategy, &rvpbuf[VPUNIT(dev)], dev, B_WRITE,
		    minvpph, uio);
E 23
I 23
		return (ENXIO);
	return (physio(vpstrategy, &rvpbuf[VPUNIT(dev)], dev, B_WRITE,
		    minvpph, uio));
E 23
E 22
E 21
E 13
}

D 13
vperror(bit)
E 13
I 13
D 32
vpwait(dev)
	dev_t dev;
E 32
I 32
D 35
/*
 * Start a DMA transfer to the versatec.
 * Not used for non-DMA commands.
 */
vpstart(um)
	register struct uba_ctlr *um;
E 35
I 35
vpwait(dev)
	dev_t dev;
E 35
E 32
E 13
{
D 13
	register int state, e;
E 13
I 13
D 32
	register struct vpdevice *vpaddr =
	    (struct vpdevice *)vpdinfo[VPUNIT(dev)]->ui_addr;
	register struct vp_softc *sc = &vp_softc[VPUNIT(dev)];
	register int e;
E 32
I 32
D 35
	register struct vp_softc *sc;
	register struct vpdevice *vpaddr = (struct vpdevice *)um->um_addr;
	register struct buf *bp;
	register int unit;
	short bit;
E 35
I 35
	register struct vpdevice *vpaddr =
	    (struct vpdevice *)vpdinfo[VPUNIT(dev)]->ui_addr;
	register struct vp_softc *sc = &vp_softc[VPUNIT(dev)];
	register int e;
E 35
E 32
E 13

D 13
	state = vp11.vp_state & PLOT;
	while ((e = (state ? VPADDR->plcsr : VPADDR->prcsr) & (bit|ERROR)) == 0)
		sleep((caddr_t)&vp11, VPPRI);
	return (e & ERROR);
E 13
I 13
D 32
	for (;;) {
		e = (sc->sc_state & VPSC_PLOT) ? vpaddr->plcsr : vpaddr->prcsr;
		if (e & (VP_READY|VP_ERROR))
			break;
		sleep((caddr_t)sc, VPPRI);
	}
D 25
	/* I wish i could tell whether an error indicated an npr timeout */
E 25
I 25
	/* I WISH I COULD TELL WHETHER AN ERROR INDICATED AN NPR TIMEOUT */
E 25
	return (e & VP_ERROR);
E 32
I 32
D 35
	dprintf("vpstart(%x), bp=%x\n", um, um->um_tab.b_actf->b_actf);
	if ((bp = um->um_tab.b_actf->b_actf) == NULL)
		return;
	unit = VPUNIT(bp->b_dev);
	sc = &vp_softc[unit];
	if (sc->sc_state&VPRINTPLOT)
		vpaddr->plcsr |= VP_SPP;
	else
		vpaddr->plcsr &= ~VP_SPP;
	sc->sc_iostate |= VPS_DMA;
	sc->sc_count = bp->b_bcount;
	(void) ubago(vpdinfo[unit]);
E 35
I 35
	for (;;) {
		e = (sc->sc_state & VPSC_PLOT) ? vpaddr->plcsr : vpaddr->prcsr;
		if (e & (VP_READY|VP_ERROR))
			break;
		sleep((caddr_t)sc, VPPRI);
	}
	/* I WISH I COULD TELL WHETHER AN ERROR INDICATED AN NPR TIMEOUT */
	return (e & VP_ERROR);
E 35
E 32
E 13
}

D 13
vpstart()
E 13
I 13
D 32
vpstart(dev)
	dev_t;
E 32
I 32
D 35
vpdgo(um)
	register struct uba_ctlr *um;
E 35
I 35
vpstart(dev)
	dev_t;
E 35
E 32
E 13
{
D 13
	register short bit;
E 13
I 13
D 32
	register struct vp_softc *sc = &vp_softc[VPUNIT(dev)];
	register struct vpdevice *vpaddr =
	    (struct vpdevice *)vpdinfo[VPUNIT(dev)]->ui_addr;
	short bit;
E 32
I 32
D 35
	register struct vp_softc *sc;
	register struct vpdevice *vpaddr = (struct vpdevice *)um->um_addr;
	register struct buf *bp;
E 35
I 35
	register struct vp_softc *sc = &vp_softc[VPUNIT(dev)];
	register struct vpdevice *vpaddr =
	    (struct vpdevice *)vpdinfo[VPUNIT(dev)]->ui_addr;
	short bit;
E 35
E 32
E 13

I 32
D 35
	bp = um->um_tab.b_actf;
	sc = &vp_softc[VPUNIT(bp->b_actf->b_dev)];
E 35
E 32
D 13
	if (vp11.vp_count) {
		VPADDR->pbaddr = vp11.vp_bufp;
I 7
		VPADDR->pbxaddr = (vp11.vp_bufp>>12)&0x30;
E 7
		if (vp11.vp_state & (PRINT|PPLOT))
			VPADDR->prbcr = vp11.vp_count;
E 13
I 13
	if (sc->sc_count) {
D 32
		vpaddr->pbaddr = sc->sc_ubinfo;
		vpaddr->pbxaddr = (sc->sc_ubinfo>>12)&0x30;
		if (sc->sc_state & (VPSC_PRINT|VPSC_SPP))
E 32
I 32
D 35
		dprintf("vpdgo: active\n");
		bp->b_active++;
		sc->sc_tocnt = IDLE;
		vpaddr->pbaddr = um->um_ubinfo;
		vpaddr->pbxaddr = (um->um_ubinfo>>12)&0x30;
		if (sc->sc_state & (VPRINT|VPRINTPLOT))
E 35
I 35
		vpaddr->pbaddr = sc->sc_ubinfo;
		vpaddr->pbxaddr = (sc->sc_ubinfo>>12)&0x30;
		if (sc->sc_state & (VPSC_PRINT|VPSC_SPP))
E 35
E 32
			vpaddr->prbcr = sc->sc_count;
E 13
		else
D 13
			VPADDR->plbcr = vp11.vp_count;
E 13
I 13
			vpaddr->plbcr = sc->sc_count;
E 13
D 32
		return;
E 32
I 32
D 35
		vptimo(VPUNIT(bp->b_actf->b_dev));
E 35
I 35
		return;
E 35
E 32
	}
I 35
	for (bit = 1; bit != 0; bit <<= 1)
		if (sc->sc_state&bit&VPSC_CMNDS) {
			vpaddr->plcsr |= bit;
			sc->sc_state &= ~bit;
			return;
		}
E 35
D 32
	for (bit = 1; bit != 0; bit <<= 1)
D 13
		if (vp11.vp_state&bit&CMNDS) {
			VPADDR->plcsr |= bit;
			vp11.vp_state &= ~bit;
E 13
I 13
		if (sc->sc_state&bit&VPSC_CMNDS) {
			vpaddr->plcsr |= bit;
			sc->sc_state &= ~bit;
E 13
			return;
		}
E 32
}

/*ARGSUSED*/
D 31
vpioctl(dev, cmd, addr, flag)
E 31
I 31
vpioctl(dev, cmd, data, flag)
I 35
	dev_t dev;
	int cmd;
E 35
E 31
I 13
D 32
	dev_t dev;
	int cmd;
E 32
E 13
D 31
	register caddr_t addr;
E 31
I 31
	register caddr_t data;
I 35
	int flag;
E 35
E 31
I 13
D 32
	int flag;
E 32
E 13
{
D 32
	register int m;
E 32
I 32
D 35
	register int vcmd;
E 35
I 35
D 39
	register int m;
E 39
E 35
E 32
I 13
	register struct vp_softc *sc = &vp_softc[VPUNIT(dev)];
I 35
	register struct vpdevice *vpaddr =
	    (struct vpdevice *)vpdinfo[VPUNIT(dev)]->ui_addr;
E 35
D 32
	register struct vpdevice *vpaddr =
	    (struct vpdevice *)vpdinfo[VPUNIT(dev)]->ui_addr;
E 32
E 13

I 32
D 35
	dprintf("vpioctl: called with %x\n",*(int *)data);
E 35
E 32
	switch (cmd) {

D 13
	case ('v'<<8)+0:
D 2
		VOID suword(addr, vp11.vp_state);
E 2
I 2
		(void) suword(addr, vp11.vp_state);
E 13
I 13
	case VGETSTATE:
D 31
		(void) suword(addr, sc->sc_state);
E 31
I 31
		*(int *)data = sc->sc_state;
E 31
E 13
E 2
D 26
		return;
E 26
I 26
D 37
		break;
E 37
I 37
		return (0);
E 37
E 26

D 13
	case ('v'<<8)+1:
E 13
I 13
	case VSETSTATE:
E 13
D 31
		m = fuword(addr);
D 26
		if (m == -1) {
			u.u_error = EFAULT;
			return;
		}
E 26
I 26
		if (m == -1)
			return (EFAULT);
E 31
E 26
D 13
		vp11.vp_state = (vp11.vp_state & ~MODE) | (m&(MODE|CMNDS));
E 13
I 13
D 32
		sc->sc_state =
D 31
		    (sc->sc_state & ~VPSC_MODE) | (m&(VPSC_MODE|VPSC_CMNDS));
E 31
I 31
		    (sc->sc_state & ~VPSC_MODE) |
		    ((*(int *)data) & (VPSC_MODE|VPSC_CMNDS));
E 31
E 13
		break;
E 32
I 32
D 35
		return (vpcmd(dev, *(int *)data));
E 35
I 35
		sc->sc_state =
		    (sc->sc_state & ~VPSC_MODE) |
		    ((*(int *)data) & (VPSC_MODE|VPSC_CMNDS));
		break;
E 35
E 32

	default:
D 26
		u.u_error = ENOTTY;
		return;
E 26
I 26
		return (ENOTTY);
E 26
	}
D 2
	VOID spl4();
	VOID vperror(READY);
E 2
I 2
D 32
	(void) spl4();
D 13
	(void) vperror(READY);
E 2
	if (vp11.vp_state&PPLOT)
		VPADDR->plcsr |= SPP;
E 13
I 13
	(void) vpwait(dev);
	if (sc->sc_state&VPSC_SPP)
		vpaddr->plcsr |= VP_SPP;
E 13
	else
D 13
		VPADDR->plcsr &= ~SPP;
	vp11.vp_count = 0;
	while (CMNDS & vp11.vp_state) {
D 2
		VOID vperror(READY);
E 2
I 2
		(void) vperror(READY);
E 2
		vpstart();
E 13
I 13
		vpaddr->plcsr &= ~VP_SPP;
	sc->sc_count = 0;
	while (sc->sc_state & VPSC_CMNDS) {
		(void) vpwait(dev);
		vpstart(dev);
E 32
I 32
D 35
	return (0);
}

vpcmd(dev, vcmd)
	dev_t dev;
	int vcmd;
{
	register struct vp_softc *sc = &vp_softc[VPUNIT(dev)];
	int error = 0;
	int s, cmd, state;

	state = 0;
	cmd = 0;
	dprintf("vpcmd: called on %x with %x\n",dev,vcmd);
	switch (vcmd&VPSC_MODE) {

	case VPRINT:
		/*
		 * Set state to print. This will cause count to be loaded
		 * into the appropriate byte count register next time vpstart
		 * is called.
		 */
		state = VPRINT;
		break;

	case VPLOT:
		/*
		 * Set state to plot. This will cause count to be loaded
		 * into the appropriate byte count register next time vpstart
		 * is called.
		 */
		state = VPLOT;
		break;

	case VPRINTPLOT:
		state = VPRINTPLOT;
		break;
E 35
I 35
	(void) spl4();
	(void) vpwait(dev);
	if (sc->sc_state&VPSC_SPP)
		vpaddr->plcsr |= VP_SPP;
	else
		vpaddr->plcsr &= ~VP_SPP;
	sc->sc_count = 0;
	while (sc->sc_state & VPSC_CMNDS) {
		(void) vpwait(dev);
		vpstart(dev);
E 35
E 32
E 13
	}
D 2
	VOID spl0();
E 2
I 2
D 32
	(void) spl0();
E 32
I 32
D 35
	dprintf("vpcmd: state=%x, vcmd=%x\n", state, vcmd&VPSC_CMNDS);
	if (state)
		sc->sc_state = (sc->sc_state & ~(VPLOT|VPRINT|VPRINTPLOT))
			| state;
	if (vcmd&VPSC_CMNDS) {
		while (sc->sc_iostate&VPS_DMA) {
			sc->sc_iostate |= VPS_WANT;
			sleep((caddr_t)&sc->sc_iostate, VPPRI);
		}
		cmd = vcmd & VPSC_CMNDS;
		if (cmd && vpdopio(dev, cmd))
			error = EIO;
		splx(s);
		return (error);
	}
E 35
I 35
	(void) spl0();
E 35
E 32
I 26
	return (0);
E 26
E 2
}

I 32
D 35
/*
 * Perform non-DMA commands.
 */
vpdopio(dev, cmd)
	dev_t dev;
	int cmd;
{
	register struct vpdevice *vpaddr =
	    (struct vpdevice *)vpminfo[VPUNIT(dev)]->um_addr;
	register struct vp_softc *sc = &vp_softc[VPUNIT(dev)];
	register int gerror, bit;

	dprintf("vpdio: called on %x with %x\n",dev,cmd);
	gerror = 0;
	for (bit = 1; bit != 0; bit <<= 1) {
		if (cmd&bit&VPSC_CMNDS) {
			if (sc->sc_state & VPLOT)
				vpaddr->plcsr |= bit;
			else
				vpaddr->prcsr |= bit;
			cmd &= ~bit;
			dprintf("vpdio: wait for %x\n",bit);
			while ((vpaddr->prcsr&(VP_READY|VP_ERROR)) == 0)
				;
			gerror |= vpaddr->prcsr&VP_ERROR;
		}
	}
	dprintf("vpdio: done\n");
	return (gerror);
}

E 35
E 32
D 13
vptimo()
E 13
I 13
vptimo(dev)
	dev_t dev;
E 13
{
I 13
	register struct vp_softc *sc = &vp_softc[VPUNIT(dev)];
E 13

D 13
	if (vp11.vp_state&VISOPEN)
D 11
		timeout(vptimo, (caddr_t)0, HZ/10);
E 11
I 11
		timeout(vptimo, (caddr_t)0, hz/10);
E 11
	vpintr(0);
E 13
I 13
D 32
	if (sc->sc_state&VPSC_OPEN)
		timeout(vptimo, (caddr_t)dev, hz/10);
E 32
I 32
D 35
	if (sc->sc_openf == 0)
		return;

	if (sc->sc_tocnt ==  IDLE)
	{
		sc->sc_tocnt = ACTIVE;
		timeout(vptimo, (caddr_t)dev, hz/2);
		return;
	}
	/*
	 * Timer timed out
	 */
	sc->sc_tocnt = IDLE;
	dprintf("vptimo: calling vpintr\n");
	/* 
	 * lost interrupt
	 */
E 35
I 35
	if (sc->sc_state&VPSC_OPEN)
		timeout(vptimo, (caddr_t)dev, hz/10);
E 35
E 32
	vpintr(dev);
E 13
}

I 32
D 35

E 35
E 32
/*ARGSUSED*/
vpintr(dev)
I 13
	dev_t dev;
E 13
{
I 13
D 32
	register struct vp_softc *sc = &vp_softc[VPUNIT(dev)];
E 32
I 32
D 35
	register struct uba_ctlr *um;
	struct vpdevice *vpaddr;
	struct buf *bp;
	register int unit = VPUNIT(dev), e;
	register struct vp_softc *sc = &vp_softc[unit];
E 35
I 35
	register struct vp_softc *sc = &vp_softc[VPUNIT(dev)];
E 35
E 32
E 13

D 13
	wakeup((caddr_t)&vp11);
E 13
I 13
D 32
	wakeup((caddr_t)sc);
E 32
I 32
D 35
	sc->sc_tocnt = IDLE;
	untimeout(vptimo, (caddr_t)dev);
	um = vpminfo[unit];
	vpaddr = (struct vpdevice *)um->um_addr;
	e = (sc->sc_state & VPLOT) ? vpaddr->plcsr : vpaddr->prcsr;
	dprintf("vpintr: um=0x%x, e=0x%x, b_active %d\n",
		um, e, um->um_tab.b_actf->b_active);
	if ((e&(VP_READY|VP_ERROR)) == 0)
		return;
	if (um->um_tab.b_actf->b_active) {
		bp = um->um_tab.b_actf->b_actf;
		if (e&VP_ERROR)
			bp->b_flags |= B_ERROR;
		/* Ok, print done, next must be plot */
		if (sc->sc_state&VPRINTPLOT)
			sc->sc_state = (sc->sc_state & ~VPRINTPLOT) | VPLOT;
		ubadone(um);
		um->um_tab.b_actf->b_active = 0;
		um->um_tab.b_actf->b_actf = bp->b_forw;
		bp->b_active = 0;
		bp->b_errcnt = 0;
		bp->b_resid = 0;
		sc->sc_count = 0;
		iodone(bp);
		dprintf("vpintr: iodone\n");
	} else
		return;
	if (um->um_tab.b_actf->b_actf == 0) {
		sc->sc_iostate &= ~VPS_DMA;
		if (sc->sc_iostate&VPS_WANT) {
			sc->sc_iostate &= ~VPS_WANT;
			wakeup((caddr_t)&sc->sc_iostate);
		}
		return;
	}
	if (um->um_tab.b_actf->b_active == 0)
		vpstart(um);
E 35
I 35
	wakeup((caddr_t)sc);
E 35
E 32
E 13
}

D 13
vpclose()
E 13
I 13
vpclose(dev)
	dev_t dev;
E 13
{
I 13
	register struct vp_softc *sc = &vp_softc[VPUNIT(dev)];
	register struct vpdevice *vpaddr =
	    (struct vpdevice *)vpdinfo[VPUNIT(dev)]->ui_addr;
E 13

I 32
D 35
	dprintf("vpclose: called on %x\n",dev);
	while (sc->sc_iostate != VPS_IDLE)
		sleep((caddr_t)&sc->sc_iostate, VPPRI);
	sc->sc_openf = 0;
E 35
E 32
D 13
	vp11.vp_state = 0;
	vp11.vp_count = 0;
	vp11.vp_bufp = 0;
	VPADDR->plcsr = 0;
E 13
I 13
	sc->sc_state = 0;
I 35
	sc->sc_count = 0;
E 35
D 32
	sc->sc_count = 0;
E 32
	vpaddr->plcsr = 0;
I 32
D 35
	vpaddr->prcsr = 0;
E 35
E 32
E 13
}
D 4
#endif
E 4
I 4

D 13
vpreset()
E 13
I 13
vpreset(uban)
	int uban;
E 13
{
I 13
	register int vp11;
D 32
	register struct uba_device *ui;
	register struct vp_softc *sc = vp_softc;
E 32
I 32
D 35
	register struct uba_ctlr *um;
E 35
I 35
	register struct uba_device *ui;
	register struct vp_softc *sc = vp_softc;
E 35
E 32
	register struct vpdevice *vpaddr;
I 32
D 35
	register struct vp_softc *sc;
E 35
E 32
E 13

I 32
D 35
	dprintf("vpreset: called\n");
E 35
E 32
D 13
	if ((vp11.vp_state & VISOPEN) == 0)
		return;
	printf(" vp");
	VPADDR->prcsr = IENABLE | DTCINTR;
	if ((vp11.vp_state & VBUSY) == 0)
		return;
	if (vp_ubinfo) {
		printf("<%d>", (vp_ubinfo>>28)&0xf);
D 9
		ubafree(vp_ubinfo), vp_ubinfo = 0;
E 9
I 9
D 10
		UBAFREECLR(vp_ubinfo);
E 10
I 10
		ubarelse(&vp_ubinfo);
E 13
I 13
	for (vp11 = 0; vp11 < NVP; vp11++, sc++) {
D 32
		if ((ui = vpdinfo[vp11]) == 0 || ui->ui_alive == 0 ||
		    ui->ui_ubanum != uban || (sc->sc_state&VPSC_OPEN) == 0)
E 32
I 32
D 35
		if ((um = vpminfo[vp11]) == 0 || um->um_ubanum != uban ||
		    um->um_alive == 0)
E 35
I 35
		if ((ui = vpdinfo[vp11]) == 0 || ui->ui_alive == 0 ||
		    ui->ui_ubanum != uban || (sc->sc_state&VPSC_OPEN) == 0)
E 35
E 32
			continue;
I 32
D 35
		sc = &vp_softc[um->um_ctlr];
		if (sc->sc_openf == 0)
			continue;
E 35
E 32
		printf(" vp%d", vp11);
D 32
		vpaddr = (struct vpdevice *)ui->ui_addr;
E 32
I 32
D 35
		vpaddr = (struct vpdevice *)um->um_addr;
		vpaddr->prbcr = 0;
		vpaddr->plbcr = 0;
E 35
I 35
		vpaddr = (struct vpdevice *)ui->ui_addr;
E 35
E 32
		vpaddr->prcsr = VP_IENABLE|VP_DTCINTR;
D 32
		if ((sc->sc_state & VPSC_BUSY) == 0)
			continue;
D 26
		if (sc->sc_ubinfo) {
			printf("<%d>", (sc->sc_ubinfo>>28)&0xf);
			ubarelse(ui->ui_ubanum, &sc->sc_ubinfo);
		}
E 26
I 26
		sc->sc_ubinfo = 0;
E 26
		sc->sc_count = sc->sc_bp->b_bcount;
		vpstart(sc->sc_bp->b_dev);
E 32
I 32
D 35
		sc->sc_iostate = VPS_IDLE;
		um->um_tab.b_actf->b_active = 0;
/*
		um->um_tab.b_actf->b_actf = um->um_tab.b_actf->b_actl = 0;
*/
		if (um->um_ubinfo) {
			printf("<%d>", (um->um_ubinfo >> 28) & 0xf);
			um->um_ubinfo = 0;
		}
		(void) vpstart(um);
E 35
I 35
		if ((sc->sc_state & VPSC_BUSY) == 0)
			continue;
		sc->sc_ubinfo = 0;
		sc->sc_count = sc->sc_bp->b_bcount;
		vpstart(sc->sc_bp->b_dev);
E 35
E 32
E 13
E 10
E 9
	}
D 13
	vp11.vp_bufp = vp_ubinfo & 0x3ffff;
	vp11.vp_count = vp11.vp_bp->b_bcount;
	vpstart();
E 13
}
I 16

vpselect()
{
	return (1);
}
E 16
I 5
#endif
E 5
E 4
E 1
