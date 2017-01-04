h20220
s 00002/00002/01223
d D 7.4 89/01/14 12:58:35 bostic 25 24
c Chris Torek; patch for MTLERRM code
e
s 00003/00001/01222
d D 7.3 88/06/06 12:17:30 karels 24 23
c init muinfo
e
s 00471/00748/00752
d D 7.2 88/05/06 17:22:25 bostic 23 22
c Chris Torek's new version; massive reformatting
e
s 00001/00001/01499
d D 7.1 86/06/05 01:32:18 mckusick 22 21
c 4.3BSD release version
e
s 00007/00010/01493
d D 6.6 86/02/23 23:22:05 karels 21 20
c lint
e
s 00007/00001/01496
d D 6.5 85/06/08 14:09:31 mckusick 20 19
c Add copyright
e
s 00014/00010/01483
d D 6.4 85/03/13 09:49:47 ralph 19 18
c change printf error messages to tprintf's.
e
s 00990/00152/00503
d D 6.3 84/09/25 11:26:13 mckusick 18 17
c TU78 error recovery (Griff Smith - ulysses!ggs)
e
s 00015/00015/00640
d D 6.2 84/08/29 20:53:21 bloom 17 16
c change to includes.  no more ../h
e
s 00000/00000/00655
d D 6.1 83/07/29 07:35:12 sam 16 15
c 4.2 distribution
e
s 00002/00001/00653
d D 4.15 82/12/17 12:09:51 sam 15 14
c sun merge
e
s 00001/00002/00653
d D 4.14 82/10/20 02:23:58 root 14 13
c lint
e
s 00001/00003/00654
d D 4.13 82/10/17 23:07:47 root 13 12
c lint
e
s 00003/00004/00654
d D 4.12 82/10/17 15:31:58 root 12 11
c minor lint
e
s 00016/00024/00642
d D 4.11 82/10/17 11:55:00 root 11 10
c open/ioctl routine return errors; hpopen!!!
e
s 00004/00004/00662
d D 4.10 82/10/10 17:20:00 root 10 9
c vax header files in their place
e
s 00010/00008/00656
d D 4.9 82/09/12 03:05:11 root 9 8
c physio returns errors
e
s 00007/00010/00657
d D 4.8 82/08/22 21:17:52 root 8 7
c fully uio()'d
e
s 00016/00009/00651
d D 4.7 82/08/13 00:24:10 root 7 6
c hacks for chardev uio
e
s 00026/00022/00634
d D 4.6 82/08/01 19:28:51 sam 6 5
c new ioctl's
e
s 00004/00003/00652
d D 4.5 82/07/15 20:33:29 kre 5 4
c slave routines now have sn passwd as param rather than in struct
e
s 00014/00014/00641
d D 4.4 82/07/13 18:09:35 sam 4 3
c bdbtofsb maps block device blocks to DEV_BSIZE blocks
e
s 00016/00008/00639
d D 4.3 82/03/14 17:55:14 sam 3 2
c lint
e
s 00006/00004/00641
d D 4.2 82/01/17 20:28:22 root 2 1
c remove spl0's from block tape routines
e
s 00645/00000/00000
d D 4.1 81/11/04 10:43:57 wnj 1 0
c date and time created 81/11/04 10:43:57 by wnj
e
u
U
t
T
I 1
D 20
/*	%M%	%I%	%E%	*/
E 20
I 20
/*
D 22
 * Copyright (c) 1982 Regents of the University of California.
E 22
I 22
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 22
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 20

#include "mu.h"
#if NMT > 0
/*
 * TM78/TU78 tape driver
 *
D 18
 *	Behavior in complex error situations is uncertain...
E 18
I 18
 *	Original author - ?
 *	Most error recovery bug fixes - ggs (ulysses!ggs)
I 23
 *	`read reverse' error recovery - ggs (ulysses!ggs)
E 23
E 18
 *
I 18
 * OPTIONS:
 *	MTLERRM - Long error message text - twd, Brown University
D 23
 *	MTRDREV - `read reverse' error recovery - ggs (ulysses!ggs)
E 23
 *
E 18
 * TODO:
D 18
 *	test error recovery
 *	add odd byte count kludge from VMS driver
 *	write dump routine
E 18
I 18
 *	Add odd byte count kludge from VMS driver (?)
 *	Write dump routine
E 18
 */
I 18

E 18
I 15
D 23
#include "../machine/pte.h"

E 23
E 15
D 17
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/buf.h"
#include "../h/conf.h"
#include "../h/dir.h"
#include "../h/file.h"
#include "../h/user.h"
#include "../h/map.h"
D 15
#include "../h/pte.h"
E 15
D 10
#include "../h/mbareg.h"
#include "../h/mbavar.h"
E 10
D 6
#include "../h/mtio.h"
E 6
#include "../h/ioctl.h"
I 6
#include "../h/mtio.h"
E 6
#include "../h/cmap.h"
D 10
#include "../h/cpu.h"
E 10
I 7
#include "../h/uio.h"
E 17
I 17
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
I 19
#include "tty.h"
I 23
#include "syslog.h"
E 23
E 19
E 17
E 7

I 23
#include "../vax/pte.h"
E 23
D 10
#include "../h/mtreg.h"
E 10
I 10
#include "../vax/cpu.h"
D 17
#include "../vaxmba/mbareg.h"
#include "../vaxmba/mbavar.h"
#include "../vaxmba/mtreg.h"
E 17
I 17
#include "mbareg.h"
#include "mbavar.h"
#include "mtreg.h"
E 17
E 10

D 18
struct	buf	rmtbuf[NMT];
struct	buf	cmtbuf[NMT];
E 18
I 18
#define MTTIMEOUT	10000		/* loop limit for controller test */
#define	INF		1000000L	/* a block number that won't exist */
#define MASKREG(r)	((r) & 0xffff)	/* the control registers have 16 bits */
E 18

D 18
short	mttypes[] =
	{ MBDT_TU78, 0 };
struct	mba_device *mtinfo[NMT];
int	mtattach(), mtslave(), mtustart(), mtstart(), mtndtint(), mtdtint();
struct	mba_driver mtdriver =
    { mtattach, mtslave, mtustart, mtstart, mtdtint, mtndtint,
      mttypes, "mt", "mu", mtinfo };
E 18
I 18
/* Bits for sc_flags */
E 18

D 18
#define MASKREG(r)	((r) & 0xffff)
E 18
I 18
#define	H_WRITTEN	01		/* last operation was a write */
#define H_EOT		02		/* end of tape encountered */
#define H_IEOT		04		/* ignore EOT condition */
E 18

D 18
/* bits in minor device */
E 18
I 18
D 23
/* Bits in minor device */
E 23
I 23
int	mt_do_readrev = 1;
E 23

E 18
D 23
#define	MUUNIT(dev)	(minor(dev)&03)
#define	H_NOREWIND	04
D 18
#define	H_6250BPI	08
E 18
I 18
#define	H_6250BPI	010
E 18

#define MTUNIT(dev)	(mutomt[MUUNIT(dev)])

D 18
#define	INF	(daddr_t)1000000L	/* a block number that wont exist */
E 18
I 18
#ifdef MTRDREV
	int mt_do_readrev = 1;
#else
	int mt_do_readrev = 0;
#endif
E 18

E 23
I 18
/* Per unit status information */

E 18
struct	mu_softc {
D 18
	char	sc_openf;
	char	sc_flags;
	daddr_t	sc_blkno;
	daddr_t	sc_nxrec;
	u_short	sc_erreg;
	u_short	sc_dsreg;
	short	sc_resid;
	short	sc_dens;
	struct	mba_device *sc_mi;
	int	sc_slave;
E 18
I 18
D 23
	char	sc_openf;		/* unit is open if != 0 */
	char	sc_flags;		/* state flags */
	daddr_t	sc_blkno;		/* current physical block number */
	daddr_t	sc_nxrec;		/* firewall input block number */
	u_short	sc_erreg;		/* copy of mter or mtner */
	u_short	sc_dsreg;		/* copy of mtds */
	short	sc_resid;		/* residual function count for ioctl */
	short	sc_dens;		/* density code - MT_GCR or zero */
	struct	mba_device *sc_mi;	/* massbus structure for unit */
	int	sc_slave;		/* slave number for unit */
	int	sc_i_mtas;		/* mtas at slave attach time */
	int	sc_i_mtner;		/* mtner at slave attach time */
	int	sc_i_mtds;		/* mtds at slave attach time */
#ifdef MTLERRM
	char	*sc_mesg;		/* text for interrupt type code */
	char	*sc_fmesg;		/* text for tape error code */
#endif
I 19
	struct	tty *sc_ttyp;		/* record user's tty for errors */
E 23
I 23
	char	sc_openf;	/* unit is open if != 0 */
	char	sc_flags;	/* state flags */
	daddr_t	sc_blkno;	/* current physical block number */
	daddr_t	sc_nxrec;	/* firewall input block number */
	u_short	sc_erreg;	/* copy of mter or mtner */
	u_short	sc_dsreg;	/* copy of mtds */
	short	sc_resid;	/* residual function count for ioctl */
	short	sc_dens;	/* density code - MT_GCR or zero */
	int	sc_i_mtas;	/* mtas at slave attach time */
	int	sc_i_mtner;	/* mtner at slave attach time */
	int	sc_i_mtds;	/* mtds at slave attach time */
	struct	tty *sc_ttyp;	/* record user's tty for errors */
	int	sc_blks;	/* number of I/O operations since open */
	int	sc_softerrs;	/* number of soft I/O errors since open */
E 23
E 19
E 18
} mu_softc[NMU];
D 18
short	mutomt[NMU];
E 18

D 18
/*
 * Bits for sc_flags.
 */
#define	H_WRITTEN 1	/* last operation was a write */
E 18
I 18
D 23
struct	buf	rmtbuf[NMT];		/* data transfer buffer structures */
E 23
struct	buf	cmtbuf[NMT];		/* tape command buffer structures */
E 18

D 18
char	mtds_bits[] = MTDS_BITS;
E 18
I 18
D 23
struct	mba_device *mtinfo[NMT];	/* unit massbus structure pointers */
short	mutomt[NMU];			/* tape unit to controller number map */
E 23
I 23
struct	mba_device *mtinfo[NMT];	/* unit to ctlr structures */
struct	mba_slave *muinfo[NMU];		/* unit to slave structures */

E 23
char	mtds_bits[] = MTDS_BITS;	/* mtds bit names for error messages */
short	mttypes[] = { MBDT_TU78, 0 };
E 18

I 18
int	mtattach(), mtslave(), mtustart(), mtstart(), mtndtint(), mtdtint();
struct	mba_driver mtdriver =
	{ mtattach, mtslave, mtustart, mtstart, mtdtint, mtndtint,
	  mttypes, "mt", "mu", mtinfo };

D 23
void mtcreset();
E 23
I 23
/* Bits in minor device */
#define	MUUNIT(dev)	(minor(dev)&03)
#define	H_NOREWIND	04
#define	H_6250BPI	010
E 23

I 23
#define MTUNIT(dev)	(muinfo[MUUNIT(dev)]->ms_ctlr)

void	mtcreset();

E 23
E 18
/*ARGSUSED*/
mtattach(mi)
	struct mba_device *mi;
{
I 23

	/* void */
E 23
D 3

E 3
I 3
D 13
#ifdef lint
D 7
	mtread(0); mtwrite(0); mtioctl(0, 0, 0, 0);
E 7
I 7
	mtread(0, 0); mtwrite(0); mtioctl(0, 0, 0, 0);
E 7
#endif
E 13
I 13
D 18

E 18
I 18
D 21
#ifdef lint
	mtread(0); mtwrite(0); mtioctl(0, 0, 0, 0);
#endif
E 21
E 18
E 13
E 3
}

D 5
mtslave(mi, ms)
E 5
I 5
mtslave(mi, ms, sn)
E 5
	struct mba_device *mi;
	struct mba_slave *ms;
I 5
	int sn;
E 5
{
	register struct mu_softc *sc = &mu_softc[ms->ms_unit];
	register struct mtdevice *mtaddr = (struct mtdevice *)mi->mi_drv;
D 18
	int s = spl7(), rtn = 0;
E 18
I 18
D 21
	int s = spl7(), rtn = 0, i;
E 21
I 21
	int s = spl5(), rtn = 0, i;
E 21
E 18

I 18
D 23
	/* Just in case the controller is ill, reset it.  Then issue	*/
	/* a sense operation and wait about a second for it to respond.	*/

E 23
I 23
	/*
	 * Just in case the controller is ill, reset it.  Then issue
	 * a sense operation and wait about a second for it to respond.
	 */
E 23
	mtcreset(mtaddr);
E 18
	mtaddr->mtas = -1;
D 5
	mtaddr->mtncs[ms->ms_slave] = MT_SENSE|MT_GO;
E 5
I 5
	mtaddr->mtncs[sn] = MT_SENSE|MT_GO;
E 5
D 18
	while (mtaddr->mtas == 0)
		;
	if ((mtaddr->mtner & MTER_INTCODE) == MTER_DONE &&
	    (mtaddr->mtds & MTDS_PRES)) {
E 18
I 18
D 23
	for (i = MTTIMEOUT; i> 0; i--) {
E 23
I 23
	for (i = MTTIMEOUT; i > 0; i--) {
E 23
		DELAY(50);
		if (MASKREG(mtaddr->mtas) != 0)
			break;
	}
	sc->sc_i_mtas = mtaddr->mtas;
	sc->sc_i_mtner = mtaddr->mtner;
	sc->sc_i_mtds = mtaddr->mtds;

D 23
	/* If no response, whimper.  If wrong response, call it an	*/
	/* unsolicited interrupt and use mtndtint to log and correct.	*/
	/* Otherwise, note whether this slave exists.			*/

	if (i <= 0) {
E 23
I 23
	/*
	 * If no response, whimper.  If wrong response, call it an
	 * unsolicited interrupt and use mtndtint to log and correct.
	 * Otherwise, note whether this slave exists.
	 */
	if (i <= 0)
E 23
		printf("mt: controller hung\n");
D 23
	} else if ((mtaddr->mtner & MTER_INTCODE) != MTER_DONE) {
E 23
I 23
	else if ((mtaddr->mtner & MTER_INTCODE) != MTER_DONE)
E 23
		(void) mtndtint(mi);
D 23
	} else if (mtaddr->mtds & MTDS_PRES) {
E 18
		sc->sc_mi = mi;
D 5
		sc->sc_slave = ms->ms_slave;
E 5
I 5
		sc->sc_slave = sn;
E 5
		mutomt[ms->ms_unit] = mi->mi_unit;
E 23
I 23
D 24
	else if (mtaddr->mtds & MTDS_PRES)
E 24
I 24
	else if (mtaddr->mtds & MTDS_PRES) {
		muinfo[ms->ms_unit] = ms;
E 24
E 23
		rtn = 1;
I 24
	}
E 24
D 23
	}
E 23
I 18

D 23
	/* Cancel the interrupt, then wait a little while for it to go away. */

E 23
I 23
	/* cancel the interrupt, then wait a little while for it to go away */
E 23
E 18
	mtaddr->mtas = mtaddr->mtas;
I 18
	DELAY(10);
E 18
	splx(s);
	return (rtn);
}

mtopen(dev, flag)
	dev_t dev;
	int flag;
{
	register int muunit;
D 23
	register struct mba_device *mi;
E 23
	register struct mu_softc *sc;
I 23
	register struct mba_slave *ms;
E 23
D 18
	int olddens, dens;
E 18

	muunit = MUUNIT(dev);
D 18
	if (muunit >= NMU || (sc = &mu_softc[muunit])->sc_openf ||
D 11
	    (mi = mtinfo[MTUNIT(dev)]) == 0 || mi->mi_alive == 0) {
		u.u_error = ENXIO;
		return;
	}
E 11
I 11
	    (mi = mtinfo[MTUNIT(dev)]) == 0 || mi->mi_alive == 0)
E 18
I 18
D 23
	if (   (muunit >= NMU)
	    || ((mi = mtinfo[MTUNIT(dev)]) == 0)
	    || (mi->mi_alive == 0) )
E 23
I 23
	if (muunit >= NMU || (ms = muinfo[muunit]) == NULL ||
	    ms->ms_alive == 0 || mtinfo[ms->ms_ctlr]->mi_alive == 0)
E 23
E 18
		return (ENXIO);
E 11
D 18
	olddens = sc->sc_dens;
	dens = sc->sc_dens = (minor(dev)&H_6250BPI) ? MT_GCR : 0;
E 18
I 18
	if ((sc = &mu_softc[muunit])->sc_openf)
		return (EBUSY);
I 23
	sc->sc_openf = 1;
E 23
	sc->sc_dens = (minor(dev) & H_6250BPI) ? MT_GCR : 0;
E 18
	mtcommand(dev, MT_SENSE, 1);
D 18
	sc->sc_dens = olddens;
E 18
	if ((sc->sc_dsreg & MTDS_ONL) == 0) {
		uprintf("mu%d: not online\n", muunit);
I 23
		sc->sc_openf = 0;
E 23
D 11
		u.u_error = EIO;
		return;
E 11
I 11
		return (EIO);
E 11
	}
D 18
	if ((flag&FWRITE) && (sc->sc_dsreg&MTDS_FPT)) {
E 18
I 18
	if ((sc->sc_dsreg & MTDS_AVAIL) == 0) {
		uprintf("mu%d: not online (port selector)\n", muunit);
I 23
		sc->sc_openf = 0;
E 23
		return (EIO);
	}
	if ((flag & FWRITE) && (sc->sc_dsreg & MTDS_FPT)) {
E 18
		uprintf("mu%d: no write ring\n", muunit);
I 23
		sc->sc_openf = 0;
E 23
D 11
		u.u_error = EIO;
		return;
E 11
I 11
		return (EIO);
E 11
	}
D 18
	if ((sc->sc_dsreg & MTDS_BOT) == 0 && (flag&FWRITE) &&
	    dens != sc->sc_dens) {
E 18
I 18
D 23
	if (   ((sc->sc_dsreg & MTDS_BOT) == 0)
	    && (flag & FWRITE)
	    && (   (   (sc->sc_dens == MT_GCR)
		    && (sc->sc_dsreg & MTDS_PE) )
		|| (   (sc->sc_dens != MT_GCR)
		    && ((sc->sc_dsreg & MTDS_PE) == 0)))) {
E 23
I 23
	if ((sc->sc_dsreg & MTDS_BOT) == 0 && (flag & FWRITE) &&
	    (sc->sc_dens == MT_GCR) != ((sc->sc_dsreg & MTDS_PE) == 0)) {
E 23
E 18
		uprintf("mu%d: can't change density in mid-tape\n", muunit);
I 23
		sc->sc_openf = 0;
E 23
D 11
		u.u_error = EIO;
		return;
E 11
I 11
		return (EIO);
E 11
	}
D 23
	sc->sc_openf = 1;
E 23
	sc->sc_blkno = (daddr_t)0;
D 18
	sc->sc_nxrec = INF;
E 18
I 18

D 23
	/* Since cooked I/O may do a read-ahead before a write, trash	*/
	/* on a tape can make the first write fail.  Suppress the first	*/
	/* read-ahead unless definitely doing read-write		*/

	sc->sc_nxrec =  ((flag & (FTRUNC | FWRITE)) == (FTRUNC | FWRITE))
		      ? (daddr_t)0
		      : (daddr_t)INF;
E 23
I 23
	/*
	 * Since cooked I/O may do a read-ahead before a write, trash
	 * on a tape can make the first write fail.  Suppress the first
	 * read-ahead unless definitely doing read-write.
	 */
	sc->sc_nxrec = ((flag & (FTRUNC | FWRITE)) == (FTRUNC | FWRITE)) ?
	    (daddr_t)0 : (daddr_t)INF;
E 23
E 18
	sc->sc_flags = 0;
I 23
	sc->sc_blks = 0;
	sc->sc_softerrs = 0;
E 23
I 19
	sc->sc_ttyp = u.u_ttyp;
E 19
D 18
	sc->sc_dens = dens;
E 18
I 11
	return (0);
E 11
}

mtclose(dev, flag)
	register dev_t dev;
D 18
	register flag;
E 18
I 18
	register int flag;
E 18
{
	register struct mu_softc *sc = &mu_softc[MUUNIT(dev)];

D 18
	if (flag == FWRITE || ((flag&FWRITE) && (sc->sc_flags&H_WRITTEN)))
E 18
I 18
D 23
	if (   ((flag & (FREAD | FWRITE)) == FWRITE)
	    || (   (flag & FWRITE)
		&& (sc->sc_flags & H_WRITTEN) ))
E 23
I 23
	if ((flag & (FREAD | FWRITE)) == FWRITE ||
	    ((flag & FWRITE) && (sc->sc_flags & H_WRITTEN)))
E 23
E 18
		mtcommand(dev, MT_CLS|sc->sc_dens, 1);
D 18
	if ((minor(dev)&H_NOREWIND) == 0)
E 18
I 18
	if ((minor(dev) & H_NOREWIND) == 0)
E 18
		mtcommand(dev, MT_REW, 0);
I 23
	if (sc->sc_blks > 100 && sc->sc_softerrs > sc->sc_blks / 100)
		log(LOG_INFO, "mu%d: %d soft errors in %d blocks\n",
		    MUUNIT(dev), sc->sc_softerrs, sc->sc_blks);
E 23
	sc->sc_openf = 0;
}

mtcommand(dev, com, count)
	dev_t dev;
	int com, count;
{
	register struct buf *bp;
I 2
D 23
	register int s;
E 23
I 23
	int s;
E 23
E 2

	bp = &cmtbuf[MTUNIT(dev)];
D 2
	(void) spl5();
E 2
I 2
	s = spl5();
E 2
D 18
	while (bp->b_flags&B_BUSY) {
		if(bp->b_repcnt == 0 && (bp->b_flags&B_DONE))
E 18
I 18
	while (bp->b_flags & B_BUSY) {
D 23
		if((bp->b_repcnt == 0) && (bp->b_flags & B_DONE))
E 23
I 23
		if (bp->b_repcnt == 0 && (bp->b_flags & B_DONE))
E 23
E 18
			break;
		bp->b_flags |= B_WANTED;
		sleep((caddr_t)bp, PRIBIO);
	}
	bp->b_flags = B_BUSY|B_READ;
D 2
	(void) spl0();
E 2
I 2
	splx(s);
E 2
	bp->b_dev = dev;
	bp->b_command = com;
	bp->b_repcnt = count;
	bp->b_blkno = 0;
I 18
	bp->b_error = 0;
E 18
	mtstrategy(bp);
	if (count == 0)
		return;
D 23
	iowait(bp);
E 23
I 23
	biowait(bp);
E 23
D 18
	if (bp->b_flags&B_WANTED)
E 18
I 18
	if (bp->b_flags & B_WANTED)
E 18
		wakeup((caddr_t)bp);
	bp->b_flags &= B_ERROR;
}

mtstrategy(bp)
	register struct buf *bp;
{
D 23
	register struct mba_device *mi = mtinfo[MTUNIT(bp->b_dev)];
E 23
	register struct buf *dp;
I 2
D 23
	register int s;
E 23
I 23
	struct mba_device *mi = mtinfo[MTUNIT(bp->b_dev)];
	int s;
E 23
E 2

I 18
D 23
	/* If this is a data transfer operation, set the resid to a	*/
	/* default value (EOF) to simplify getting it right during	*/
	/* error recovery or bail out.					*/

E 23
I 23
	/*
	 * If this is a data transfer operation, set the resid to a
	 * default value (EOF) to simplify getting it right during
	 * error recovery or bail out.
	 */
E 23
	if (bp != &cmtbuf[MTUNIT(bp->b_dev)])
		bp->b_resid = bp->b_bcount;

D 23
	/* Link this request onto the end of the queue for this		*/
	/* controller, then start I/O if not already active.		*/

E 23
I 23
	/*
	 * Link this request onto the end of the queue for this
	 * controller, then start I/O if not already active.
	 */
E 23
E 18
	bp->av_forw = NULL;
	dp = &mi->mi_tab;
D 2
	(void) spl5();
E 2
I 2
	s = spl5();
E 2
	if (dp->b_actf == NULL)
		dp->b_actf = bp;
	else
		dp->b_actl->av_forw = bp;
	dp->b_actl = bp;
	if (dp->b_active == 0)
		mbustart(mi);
D 2
	(void) spl0();
E 2
I 2
	splx(s);
E 2
}

mtustart(mi)
	register struct mba_device *mi;
{
D 18
	register struct mtdevice *mtaddr =
	    (struct mtdevice *)mi->mi_drv;
E 18
I 18
	register struct mtdevice *mtaddr = (struct mtdevice *)mi->mi_drv;
E 18
	register struct buf *bp = mi->mi_tab.b_actf;
	register struct mu_softc *sc = &mu_softc[MUUNIT(bp->b_dev)];
	daddr_t blkno;
I 21
	int count;
E 21

D 18
	sc->sc_flags &= ~H_WRITTEN;
E 18
	if (sc->sc_openf < 0) {
		bp->b_flags |= B_ERROR;
		return (MBU_NEXT);
	}
	if (bp != &cmtbuf[MTUNIT(bp->b_dev)]) {
D 4
		if (dbtofsb(bp->b_blkno) > sc->sc_nxrec) {
E 4
I 4
D 18
		if (bdbtofsb(bp->b_blkno) > sc->sc_nxrec) {
E 18
I 18
D 23

		/* Signal "no space" if out of tape unless suppressed	*/
		/* by MTIOCIEOT.					*/

		if (   ((sc->sc_flags & (H_EOT | H_IEOT)) == H_EOT)
		    && ((bp->b_flags & B_READ) == 0) ) {
E 23
I 23
		/*
		 * Data transfer.  If write at end of tape,
		 * signal "no space" unless suppressed
		 * by MTIOCIEOT.
		 */
		if ((sc->sc_flags & (H_EOT | H_IEOT)) == H_EOT &&
		    (bp->b_flags & B_READ) == 0) {
E 23
E 18
E 4
			bp->b_flags |= B_ERROR;
D 18
			bp->b_error = ENXIO;
E 18
I 18
			bp->b_error = ENOSPC;
E 18
			return (MBU_NEXT);
		}
D 4
		if (dbtofsb(bp->b_blkno) == sc->sc_nxrec &&
E 4
I 4
D 18
		if (bdbtofsb(bp->b_blkno) == sc->sc_nxrec &&
E 4
		    bp->b_flags&B_READ) {
			bp->b_resid = bp->b_bcount;
			clrbuf(bp);
			return (MBU_NEXT);
E 18
I 18

D 23
		/* special case tests for cooked mode */

		if (bp != &rmtbuf[MTUNIT(bp->b_dev)]) {

E 23
I 23
		if (bp->b_flags & B_RAW) {
			/* raw transfer; never seek */
			sc->sc_blkno = bdbtofsb(bp->b_blkno);
			sc->sc_nxrec = sc->sc_blkno + 1;
		} else {
E 23
			/* seek beyond end of file */
D 23

E 23
			if (bdbtofsb(bp->b_blkno) > sc->sc_nxrec) {
				bp->b_flags |= B_ERROR;
				bp->b_error = ENXIO;
				return (MBU_NEXT);
			}

D 23
			/* This should be end of file, but the buffer	   */
			/* system wants a one-block look-ahead.  Humor it. */

			if (   (bdbtofsb(bp->b_blkno) == sc->sc_nxrec)
			    && (bp->b_flags & B_READ) ) {
E 23
I 23
			/*
			 * This should be end of file, but the buffer
			 * system wants a one-block look-ahead.  Humor it.
			 */
			if (bdbtofsb(bp->b_blkno) == sc->sc_nxrec &&
			    bp->b_flags & B_READ) {
				bp->b_resid = bp->b_bcount;
E 23
				clrbuf(bp);
				return (MBU_NEXT);
			}

			/* If writing, mark the next block invalid. */
D 23

E 23
			if ((bp->b_flags & B_READ) == 0)
				sc->sc_nxrec = bdbtofsb(bp->b_blkno) + 1;
E 18
		}
D 18
		if ((bp->b_flags&B_READ)==0)
D 4
			sc->sc_nxrec = dbtofsb(bp->b_blkno) + 1;
E 4
I 4
			sc->sc_nxrec = bdbtofsb(bp->b_blkno) + 1;
E 18
E 4
	} else {
I 18
D 23

E 23
		/* It's a command, do it now. */
D 23

E 23
E 18
		mtaddr->mtncs[MUUNIT(bp->b_dev)] =
			(bp->b_repcnt<<8)|bp->b_command|MT_GO;
		return (MBU_STARTED);
	}
D 4
	if ((blkno = sc->sc_blkno) == dbtofsb(bp->b_blkno)) {
E 4
I 4
D 18
	if ((blkno = sc->sc_blkno) == bdbtofsb(bp->b_blkno)) {
E 18
I 18

D 23
	/* If raw I/O, or if the tape is positioned correctly for	*/
	/* cooked I/O, set the byte count, unit number and repeat count	*/
	/* then tell the MASSBUS to proceed.  Note that a negative	*/
	/* bcount tells mbstart to map the buffer for "read backwards".	*/

	if (   (bp == &rmtbuf[MTUNIT(bp->b_dev)])
	    || ((blkno = sc->sc_blkno) == bdbtofsb(bp->b_blkno)) ) {
E 23
I 23
	/*
	 * If raw I/O, or if the tape is positioned correctly for
	 * cooked I/O, set the byte count, unit number and repeat count
	 * then tell the MASSBUS to proceed.  Note that a negative
	 * bcount tells mbstart to map the buffer for "read backwards".
	 */
	if ((blkno = sc->sc_blkno) == bdbtofsb(bp->b_blkno)) {
E 23
E 18
E 4
		if (mi->mi_tab.b_errcnt == 2) {
I 18
D 23
			mtaddr->mtbc = -(bp->b_bcount);
E 23
I 23
			mtaddr->mtbc = -bp->b_bcount;
E 23
E 18
			mtaddr->mtca = MUUNIT(bp->b_dev);
		} else {
			mtaddr->mtbc = bp->b_bcount;
			mtaddr->mtca = (1<<2)|MUUNIT(bp->b_dev);
		}
		return (MBU_DODATA);
	}
I 18

	/* Issue skip operations to position the next block for cooked I/O. */

E 18
D 4
	if (blkno < dbtofsb(bp->b_blkno))
E 4
I 4
	if (blkno < bdbtofsb(bp->b_blkno))
E 4
D 21
		mtaddr->mtncs[MUUNIT(bp->b_dev)] =
D 3
		  (min(dbtofsb(bp->b_blkno) - blkno, 0377)<<8)| MT_SFORW|MT_GO;
E 3
I 3
D 4
		  (min((unsigned)(dbtofsb(bp->b_blkno) - blkno), 0377) << 8) |
E 4
I 4
		  (min((unsigned)(bdbtofsb(bp->b_blkno) - blkno), 0377) << 8) |
E 4
			MT_SFORW|MT_GO;
E 21
I 21
D 23
		count = (unsigned)(bdbtofsb(bp->b_blkno) - blkno);
E 23
I 23
		count = bdbtofsb(bp->b_blkno) - blkno;
E 23
E 21
E 3
	else
D 21
		mtaddr->mtncs[MUUNIT(bp->b_dev)] =
D 3
		  (min(blkno - dbtofsb(bp->b_blkno), 0377)<<8)| MT_SREV|MT_GO;
E 3
I 3
D 4
		  (min((unsigned)(blkno - dbtofsb(bp->b_blkno)), 0377) << 8) |
E 4
I 4
		  (min((unsigned)(blkno - bdbtofsb(bp->b_blkno)), 0377) << 8) |
E 4
			MT_SREV|MT_GO;
E 21
I 21
D 23
		count = (unsigned)(blkno - bdbtofsb(bp->b_blkno));
	if (count > 0377)
E 23
I 23
		count = blkno - bdbtofsb(bp->b_blkno);
	if ((unsigned)count > 0377)
E 23
		count = 0377;
	mtaddr->mtncs[MUUNIT(bp->b_dev)] = count | MT_SFORW|MT_GO;
E 21
E 3
	return (MBU_STARTED);
}

mtstart(mi)
	register struct mba_device *mi;
{
	register struct buf *bp = mi->mi_tab.b_actf;
	register struct mu_softc *sc = &mu_softc[MUUNIT(bp->b_dev)];

	if (bp->b_flags & B_READ)
		if (mi->mi_tab.b_errcnt == 2)
D 23
			return(MT_READREV|MT_GO);
E 23
I 23
			return (MT_READREV|MT_GO);
E 23
		else
D 23
			return(MT_READ|MT_GO);
E 23
I 23
			return (MT_READ|MT_GO);
E 23
	else
D 23
		return(MT_WRITE|sc->sc_dens|MT_GO);
E 23
I 23
		return (MT_WRITE|sc->sc_dens|MT_GO);
E 23
}

mtdtint(mi, mbsr)
	register struct mba_device *mi;
	int mbsr;
{
	register struct mtdevice *mtaddr = (struct mtdevice *)mi->mi_drv;
	register struct buf *bp = mi->mi_tab.b_actf;
	register struct mu_softc *sc;
I 18
	register int er;
E 18

D 18
	/* I'M NOT SURE IF THIS SHOULD ALWAYS BE THE CASE SO FOR NOW... */
	if ((mtaddr->mtca&3) != MUUNIT(bp->b_dev)) {
E 18
I 18
	/* I'M still NOT SURE IF THIS SHOULD ALWAYS BE THE CASE SO FOR NOW... */
D 23

E 23
	if ((mtaddr->mtca & 3) != MUUNIT(bp->b_dev)) {
E 18
		printf("mt: wrong unit!\n");
		mtaddr->mtca = MUUNIT(bp->b_dev);
	}
I 18

	er = MASKREG(mtaddr->mter);
E 18
	sc = &mu_softc[MUUNIT(bp->b_dev)];
D 18
	sc->sc_erreg = mtaddr->mter;
	if((bp->b_flags & B_READ) == 0)
E 18
I 18
	sc->sc_erreg = er;
	if (bp->b_flags & B_READ)
		sc->sc_flags &= ~H_WRITTEN;
	else
E 18
		sc->sc_flags |= H_WRITTEN;
D 18
	switch (sc->sc_erreg & MTER_INTCODE) {
E 18
I 18
	switch (er & MTER_INTCODE) {

	case MTER_EOT:
		sc->sc_flags |= H_EOT;
D 23

E 23
		/* fall into MTER_DONE */

E 18
	case MTER_DONE:
D 18
	case MTER_LONGREC:
		if (mi->mi_tab.b_errcnt != 2)
E 18
I 18
		sc->sc_blkno++;
		if (mi->mi_tab.b_errcnt == 2) {
			bp->b_bcount = bp->b_resid;
			bp->b_resid -= MASKREG(mtaddr->mtbc);
D 23
			if (   (bp->b_resid > 0)
			    && (bp != &rmtbuf[MTUNIT(bp->b_dev)]) )
E 23
I 23
			if (bp->b_resid > 0 && (bp->b_flags & B_RAW) == 0)
E 23
				bp->b_flags |= B_ERROR;
D 23
		} else {
E 23
I 23
		} else
E 23
			bp->b_resid = 0;
D 23
		}
E 23
		break;

	case MTER_SHRTREC:
		sc->sc_blkno++;
		bp->b_bcount = bp->b_resid;
		bp->b_resid -= MASKREG(mtaddr->mtbc);
D 23
		if (bp != &rmtbuf[MTUNIT(bp->b_dev)])
E 23
I 23
		if ((bp->b_flags & B_RAW) == 0)
E 23
			bp->b_flags |= B_ERROR;
		break;

	case MTER_RETRY:
D 23

		/* Simple re-try.  Since resid is always a copy of the	*/
		/* original byte count, use it to restore the count.	*/

E 23
I 23
		/*
		 * Simple re-try.  Since resid is always a copy of the
		 * original byte count, use it to restore the count.
		 */
E 23
		mi->mi_tab.b_errcnt = 1;
		bp->b_bcount = bp->b_resid;
D 23
		return(MBD_RETRY);
E 23
I 23
		return (MBD_RETRY);
E 23

	case MTER_RDOPP:
D 23

		/* The controller just decided to read it backwards.	*/
		/* If the controller returns a byte count of zero,	*/
		/* change it to 1, since zero encodes 65536, which	*/
		/* isn't quite what we had in mind.  The byte count	*/
		/* may be larger than the size of the input buffer, so	*/
		/* limit the count to the buffer size.  After		*/
		/* making the byte count reasonable, set bcount to the	*/
		/* negative of the controller's version of the byte	*/
		/* count so that the start address for the transfer is	*/
		/* set up correctly.					*/

E 23
I 23
		/*
		 * The controller just decided to read it backwards.
		 * If the controller returns a byte count of zero,
		 * change it to 1, since zero encodes 65536, which
		 * isn't quite what we had in mind.  The byte count
		 * may be larger than the size of the input buffer, so
		 * limit the count to the buffer size.  After
		 * making the byte count reasonable, set bcount to the
		 * negative of the controller's version of the byte
		 * count so that the start address for the transfer is
		 * set up correctly.
		 */
E 23
		if (mt_do_readrev) {
			mi->mi_tab.b_errcnt = 2;
			if ((bp->b_bcount = MASKREG(mtaddr->mtbc)) == 0)
				bp->b_bcount = 1;
			if (bp->b_bcount > bp->b_resid)
				bp->b_bcount = bp->b_resid;
			bp->b_bcount = -(bp->b_bcount);
			return(MBD_RETRY);
		} else if (MASKREG(mtaddr->mtbc) <= bp->b_resid) {
E 18
			sc->sc_blkno++;
I 18
			bp->b_bcount = bp->b_resid;
			bp->b_resid -= MASKREG(mtaddr->mtbc);
			bp->b_flags |= B_ERROR;
			break;
		}
		bp->b_flags |= B_ERROR;
D 23

E 23
		/* fall into MTER_LONGREC */

	case MTER_LONGREC:
		sc->sc_blkno++;
		bp->b_bcount = bp->b_resid;
E 18
		bp->b_resid = 0;
I 18
		bp->b_error = ENOMEM;
		bp->b_flags |= B_ERROR;
E 18
		break;

	case MTER_NOTCAP:
		printf("mu%d: blank tape\n", MUUNIT(bp->b_dev));
		goto err;

	case MTER_TM:
D 18
	case MTER_EOT:
		sc->sc_blkno++;
	err:
		bp->b_resid = bp->b_bcount;
D 4
		sc->sc_nxrec = dbtofsb(bp->b_blkno);
E 4
I 4
		sc->sc_nxrec = bdbtofsb(bp->b_blkno);
E 4
		break;
E 18
D 23

D 18
	case MTER_SHRTREC:
E 18
I 18
		/* End of file.  Since the default byte count has	*/
		/* already been set, just count the block and proceed.	*/

E 23
I 23
		/*
		 * End of file.  Since the default byte count has
		 * already been set, just count the block and proceed.
		 */
E 23
E 18
		sc->sc_blkno++;
I 18
	err:
E 18
D 23
		if (bp != &rmtbuf[MTUNIT(bp->b_dev)])
D 18
			bp->b_flags |= B_ERROR;
		if (mi->mi_tab.b_errcnt == 2)
			bp->b_bcount = bp->b_resid;	/* restore saved value */
		bp->b_resid = bp->b_bcount - mtaddr->mtbc;
E 18
I 18
			sc->sc_nxrec = bdbtofsb(bp->b_blkno);
E 23
I 23
		sc->sc_nxrec = bdbtofsb(bp->b_blkno);
E 23
E 18
		break;

D 18
	case MTER_RDOPP:
		mi->mi_tab.b_errcnt = 2;	/* indicate "read opposite" */
		bp->b_resid = bp->b_bcount;	/* save it */
		bp->b_bcount = mtaddr->mtbc;	/* use this instead */
		return(MBD_RETRY);

	case MTER_RETRY:
		mi->mi_tab.b_errcnt = 1;	/* indicate simple retry */
		return(MBD_RETRY);

E 18
	case MTER_OFFLINE:
		if (sc->sc_openf > 0) {
			sc->sc_openf = -1;
D 19
			printf("mu%d: offline\n", MUUNIT(bp->b_dev));
E 19
I 19
D 23
			tprintf(sc->sc_ttyp, "mu%d: offline\n", MUUNIT(bp->b_dev));
E 23
I 23
			tprintf(sc->sc_ttyp, "mu%d: offline\n",
			    MUUNIT(bp->b_dev));
E 23
E 19
		}
		bp->b_flags |= B_ERROR;
		break;

I 18
	case MTER_NOTAVL:
		if (sc->sc_openf > 0) {
			sc->sc_openf = -1;
D 19
			printf("mu%d: offline (port selector)\n", MUUNIT(bp->b_dev));
E 19
I 19
			tprintf(sc->sc_ttyp, "mu%d: offline (port selector)\n",
			    MUUNIT(bp->b_dev));
E 19
		}
		bp->b_flags |= B_ERROR;
		break;

E 18
	case MTER_FPT:
D 19
		printf("mu%d: no write ring\n", MUUNIT(bp->b_dev));
E 19
I 19
D 23
		tprintf(sc->sc_ttyp, "mu%d: no write ring\n", MUUNIT(bp->b_dev));
E 23
I 23
		tprintf(sc->sc_ttyp, "mu%d: no write ring\n",
		    MUUNIT(bp->b_dev));
E 23
E 19
		bp->b_flags |= B_ERROR;
		break;

I 18
	case MTER_UNREAD:
		sc->sc_blkno++;
		bp->b_bcount = bp->b_resid;
		bp->b_resid -= MIN(MASKREG(mtaddr->mtbc), bp->b_bcount);

D 23
		/* Code 010 means a garbage record, nothing serious. */

		if (((er & MTER_FAILCODE) >> 10) == 010) {
D 19
			printf("mu%d: rn=%d bn=%d unreadable record\n",
E 19
I 19
			tprintf(sc->sc_ttyp, "mu%d: rn=%d bn=%d unreadable record\n",
E 23
I 23
		/* code 010 means a garbage record, nothing serious. */
		if ((er & MTER_FAILCODE) == (010 << MTER_FSHIFT)) {
			tprintf(sc->sc_ttyp,
			    "mu%d: rn=%d bn=%d unreadable record\n",
E 23
E 19
			    MUUNIT(bp->b_dev), sc->sc_blkno, bp->b_blkno);
			bp->b_flags |= B_ERROR;
			break;
		}

D 23
		/* Anything else might be a hardware problem,	*/
		/* fall into the error report.			*/
E 23
I 23
		/*
		 * Anything else might be a hardware problem,
		 * fall into the error report.
		 */
E 23

E 18
	default:
D 18
		printf("mu%d: hard error bn%d mbsr=%b er=%x ds=%b\n",
		    MUUNIT(bp->b_dev), bp->b_blkno,
		    mbsr, mbsr_bits, sc->sc_erreg,
		    sc->sc_dsreg, mtds_bits);
E 18
I 18
D 23

		/* The bits in sc->sc_dsreg are from the last sense	*/
		/* command.  To get the most recent copy, you have to	*/
		/* do a sense at interrupt level, which requires nested	*/
		/* error processing.  This is a bit messy, so leave	*/
		/* well enough alone.					*/

D 19
		printf("mu%d: hard error (data transfer) rn=%d bn=%d mbsr=%b er=%o (octal) ds=%b\n",
E 19
I 19
		tprintf(sc->sc_ttyp, "mu%d: hard error (data transfer) rn=%d bn=%d mbsr=%b er=%o (octal) ds=%b\n",
E 23
I 23
		/*
		 * The bits in sc->sc_dsreg are from the last sense
		 * command.  To get the most recent copy, you have to
		 * do a sense at interrupt level, which requires nested
		 * error processing.  This is a bit messy, so leave
		 * well enough alone.
		 */
		tprintf(sc->sc_ttyp, "\
mu%d: hard error (data transfer) rn=%d bn=%d mbsr=%b er=0%o ds=%b\n",
E 23
E 19
		    MUUNIT(bp->b_dev), sc->sc_blkno, bp->b_blkno,
		    mbsr, mbsr_bits, er,
		    MASKREG(sc->sc_dsreg), mtds_bits);
#ifdef MTLERRM
D 23
		mtintfail(sc);
		printf("     interrupt code = %o (octal) <%s>\n     failure code = %o (octal) <%s>\n",
		    er & MTER_INTCODE, sc->sc_mesg,
		    (er & MTER_FAILCODE) >> 10, sc->sc_fmesg);
E 23
I 23
		mtintfail(er);
E 23
#endif
E 18
		bp->b_flags |= B_ERROR;
D 18
		mtaddr->mtid = MTID_CLR;		/* reset the TM78 */
		DELAY(250);
		while ((mtaddr->mtid & MTID_RDY) == 0)	/* wait for it */
			;
		return (MBD_DONE);
E 18
I 18

D 23
		/* The TM78 manual says to reset the controller after	*/
		/* TM fault B or MASSBUS fault.				*/

		if (   ((er & MTER_INTCODE) == MTER_TMFLTB)
		    || ((er & MTER_INTCODE) == MTER_MBFLT) ) {
E 23
I 23
		/*
		 * The TM78 manual says to reset the controller after
		 * TM fault B or MASSBUS fault.
		 */
		if ((er & MTER_INTCODE) == MTER_TMFLTB ||
		    (er & MTER_INTCODE) == MTER_MBFLT)
E 23
			mtcreset(mtaddr);
D 23
		}
E 23
E 18
	}
D 18
	/* CHECK FOR MBA ERROR WHEN NO OTHER ERROR INDICATED? */
E 18
I 18

D 23
	/* Just in case some strange error slipped through, (drive off	*/
	/* line during read-reverse error recovery comes to mind) make	*/
	/* sure the byte count is reasonable.				*/

E 23
I 23
	/*
	 * Just in case some strange error slipped through (drive off
	 * line during read-reverse error recovery comes to mind), make
	 * sure the byte count is reasonable.
	 */
E 23
	if (bp->b_bcount < 0)
		bp->b_bcount = bp->b_resid;
I 23

	if ((bp->b_flags & B_ERROR) == 0) {
		/* this counts reverse reads as soft errors */
		sc->sc_blks++;
		if (mi->mi_tab.b_errcnt) /* alternatively, if == 1 */
			sc->sc_softerrs++;
	}
E 23
E 18
	return (MBD_DONE);
}

mtndtint(mi)
	register struct mba_device *mi;
{
	register struct mtdevice *mtaddr = (struct mtdevice *)mi->mi_drv;
	register struct buf *bp = mi->mi_tab.b_actf;
	register struct mu_softc *sc;
D 18
	int er, fc, unit;
E 18
I 18
	register int er, fc;
	int unit;
E 18

	unit = (mtaddr->mtner >> 8) & 3;
	er = MASKREG(mtaddr->mtner);
D 18
	/* WILL THIS OCCUR IF ANOTHER DRIVE COMES ONLINE? */
E 18
I 18
	sc = &mu_softc[unit];
	sc->sc_erreg = er;

	/* Check for unsolicited interrupts. */
I 23
	if (bp == NULL || unit != MUUNIT(bp->b_dev)) {
		if ((er & MTER_INTCODE) == MTER_ONLINE)
			return (MBN_SKIP);
E 23

E 18
D 23
	if (bp == 0 || unit != MUUNIT(bp->b_dev)) {	/* consistency check */
D 18
		if ((er & MTER_INTCODE) != MTER_ONLINE)
			printf("mt: unit %d random interrupt\n", unit);
E 18
I 18
		if ((er & MTER_INTCODE) != MTER_ONLINE) {
			printf("mt: unit %d unexpected interrupt (non data transfer) er=%o (octal) ds=%b\n",
			    unit, er, MASKREG(sc->sc_dsreg), mtds_bits);
E 23
I 23
		printf("mu%d: stray intr (non data transfer) er=0%o ds=%b\n",
		    unit, er, MASKREG(sc->sc_dsreg), mtds_bits);
E 23
#ifdef MTLERRM
D 23
			mtintfail(sc);
			printf("    interrupt code = %o (octal) <%s>\n    failure code = %o (octal) <%s>\n",
			    er & MTER_INTCODE, sc->sc_mesg,
			    (er & MTER_FAILCODE) >> 10, sc->sc_fmesg);
E 23
I 23
		mtintfail(er);
E 23
#endif
D 23
			if (   ((er & MTER_INTCODE) == MTER_TMFLTB)
			    || ((er & MTER_INTCODE) == MTER_MBFLT) ) {

				/* Reset the controller, then set error	*/
				/* status if there was anything active	*/
				/* when the fault occurred.  This may	*/
				/* shoot an innocent bystander, but	*/
				/* it's better than letting an error	*/
				/* slip through.			*/

				mtcreset(mtaddr);
				if (bp != 0) {
					bp->b_flags |= B_ERROR;
					return (MBN_DONE);
				}
E 23
I 23
		if ((er & MTER_INTCODE) == MTER_TMFLTB ||
		    (er & MTER_INTCODE) == MTER_MBFLT) {
			/*
			 * Reset the controller, then set error status
			 * if there was anything active when the fault
			 * occurred.  This may shoot an innocent
			 * bystander, but it's better than letting
			 * an error slip through.
			 */
			mtcreset(mtaddr);
			if (bp != NULL) {
				bp->b_flags |= B_ERROR;
				return (MBN_DONE);
E 23
			}
		}
E 18
		return (MBN_SKIP);
	}
D 23
	if (bp == 0)
		return (MBN_SKIP);
E 23
I 18

E 18
	fc = (mtaddr->mtncs[unit] >> 8) & 0xff;
D 18
	sc = &mu_softc[unit];
	sc->sc_erreg = er;
E 18
	sc->sc_resid = fc;
I 18

D 23
	/* Clear the "written" flag after any operation that changes	*/
	/* the position of the tape.					*/

	if (   (bp != &cmtbuf[MTUNIT(bp->b_dev)])
	    || (bp->b_command != MT_SENSE) )
E 23
I 23
	/*
	 * Clear the "written" flag after any operation that changes
	 * the position of the tape.
	 */
	if (bp != &cmtbuf[MTUNIT(bp->b_dev)] || bp->b_command != MT_SENSE)
E 23
		sc->sc_flags &= ~H_WRITTEN;

E 18
	switch (er & MTER_INTCODE) {
I 18

	case MTER_EOT:
		sc->sc_flags |= H_EOT;
D 23

E 23
		/* fall into MTER_DONE */

E 18
	case MTER_DONE:
I 18
D 23

E 23
		/* If this is a command buffer, just update the status.	*/
D 23

E 23
E 18
		if (bp == &cmtbuf[MTUNIT(bp->b_dev)]) {
	done:
			if (bp->b_command == MT_SENSE)
				sc->sc_dsreg = MASKREG(mtaddr->mtds);
D 18
			bp->b_resid = fc;
E 18
			return (MBN_DONE);
		}
D 18
		/* this is UGLY!  (but is it correct?) */
E 18
I 18

D 23
		/* It's not a command buffer, must be a cooked I/O	*/
		/* skip operation (perhaps a shaky assumption, but it	*/
		/* wasn't my idea).					*/

E 23
I 23
		/*
		 * It's not a command buffer, must be a cooked I/O
		 * skip operation (perhaps a shaky assumption, but it
		 * wasn't my idea).
		 */
E 23
E 18
D 4
		if ((fc = dbtofsb(bp->b_blkno) - sc->sc_blkno) < 0)
E 4
I 4
		if ((fc = bdbtofsb(bp->b_blkno) - sc->sc_blkno) < 0)
E 4
D 3
			sc->sc_blkno -= min(0377, -fc);
E 3
I 3
			sc->sc_blkno -= MIN(0377, -fc);
E 3
		else
D 3
			sc->sc_blkno += min(0377, fc);
E 3
I 3
			sc->sc_blkno += MIN(0377, fc);
E 3
		return (MBN_RETRY);

I 18
	case MTER_ONLINE:		/* ddj -- shouldn't happen but did */
E 18
	case MTER_RWDING:
		return (MBN_SKIP);	/* ignore "rewind started" interrupt */

	case MTER_NOTCAP:
D 19
		printf("mu%d: blank tape\n", MUUNIT(bp->b_dev));
E 19
I 19
		tprintf(sc->sc_ttyp, "mu%d: blank tape\n", MUUNIT(bp->b_dev));
E 19
I 18
		bp->b_flags |= B_ERROR;
		return (MBN_DONE);
E 18

	case MTER_TM:
D 18
	case MTER_EOT:
E 18
	case MTER_LEOT:
D 4
		if (sc->sc_blkno > dbtofsb(bp->b_blkno)) {
			sc->sc_nxrec = dbtofsb(bp->b_blkno) + fc;
E 4
I 4
D 18
		if (sc->sc_blkno > bdbtofsb(bp->b_blkno)) {
			sc->sc_nxrec = bdbtofsb(bp->b_blkno) + fc;
E 18
I 18
D 23

		/* For an ioctl skip operation, count a tape mark as	*/
		/* a record.  If there's anything left to do, update	*/
		/* the repeat count and re-start the command.		*/

E 23
I 23
		/*
		 * For an ioctl skip operation, count a tape mark as
		 * a record.  If there's anything left to do, update
		 * the repeat count and re-start the command.
		 */
E 23
		if (bp == &cmtbuf[MTUNIT(bp->b_dev)]) {
			if ((sc->sc_resid = bp->b_repcnt = fc - 1) == 0)
				return (MBN_DONE);
			else
				return (MBN_RETRY);
D 23

		/* Cooked I/O again.  Just update the books and wait	*/
		/* for someone else to return end of file or complain	*/
		/* about a bad seek.					*/

		} else if (sc->sc_blkno > bdbtofsb(bp->b_blkno)) {
			sc->sc_nxrec = bdbtofsb(bp->b_blkno) + fc - 1;
E 18
E 4
			sc->sc_blkno = sc->sc_nxrec;
E 23
		} else {
D 4
			sc->sc_blkno = dbtofsb(bp->b_blkno) - fc;
E 4
I 4
D 18
			sc->sc_blkno = bdbtofsb(bp->b_blkno) - fc;
E 4
			sc->sc_nxrec = sc->sc_blkno - 1;
E 18
I 18
D 23
			sc->sc_nxrec = bdbtofsb(bp->b_blkno) - fc;
			sc->sc_blkno = sc->sc_nxrec + 1;
E 23
I 23
			/*
			 * Cooked I/O again.  Just update the books and
			 * wait for someone else to return end of file or
			 * complain about a bad seek.
			 */
			if (sc->sc_blkno > bdbtofsb(bp->b_blkno)) {
				sc->sc_nxrec = bdbtofsb(bp->b_blkno) + fc - 1;
				sc->sc_blkno = sc->sc_nxrec;
			} else {
				sc->sc_nxrec = bdbtofsb(bp->b_blkno) - fc;
				sc->sc_blkno = sc->sc_nxrec + 1;
			}
E 23
E 18
		}
		return (MBN_RETRY);

	case MTER_FPT:
D 19
		printf("mu%d: no write ring\n", MUUNIT(bp->b_dev));
E 19
I 19
D 23
		tprintf(sc->sc_ttyp, "mu%d: no write ring\n", MUUNIT(bp->b_dev));
E 23
I 23
		tprintf(sc->sc_ttyp, "mu%d: no write ring\n",
		    MUUNIT(bp->b_dev));
E 23
E 19
		bp->b_flags |= B_ERROR;
		return (MBN_DONE);

	case MTER_OFFLINE:
I 18
D 23

E 23
		/* If `off line' was intentional, don't complain. */
D 23

		if (   (bp == &cmtbuf[MTUNIT(bp->b_dev)])
		    && (bp->b_command == MT_UNLOAD) )
E 23
I 23
		if (bp == &cmtbuf[MTUNIT(bp->b_dev)] &&
		    bp->b_command == MT_UNLOAD)
E 23
			return(MBN_DONE);
E 18
		if (sc->sc_openf > 0) {
			sc->sc_openf = -1;
D 19
			printf("mu%d: offline\n", MUUNIT(bp->b_dev));
E 19
I 19
D 23
			tprintf(sc->sc_ttyp, "mu%d: offline\n", MUUNIT(bp->b_dev));
E 23
I 23
			tprintf(sc->sc_ttyp, "mu%d: offline\n",
			    MUUNIT(bp->b_dev));
E 23
E 19
		}
		bp->b_flags |= B_ERROR;
		return (MBN_DONE);

I 18
	case MTER_NOTAVL:
		if (sc->sc_openf > 0) {
			sc->sc_openf = -1;
D 19
			printf("mu%d: offline (port selector)\n", MUUNIT(bp->b_dev));
E 19
I 19
D 23
			tprintf(sc->sc_ttyp, "mu%d: offline (port selector)\n", MUUNIT(bp->b_dev));
E 23
I 23
			tprintf(sc->sc_ttyp, "mu%d: offline (port selector)\n",
			    MUUNIT(bp->b_dev));
E 23
E 19
		}
		bp->b_flags |= B_ERROR;
		return (MBN_DONE);

E 18
	case MTER_BOT:
		if (bp == &cmtbuf[MTUNIT(bp->b_dev)])
			goto done;
D 18
		/* FALL THROUGH */
E 18
D 23

E 23
I 18
		/* fall through */

E 18
	default:
D 18
		printf("mu%d: hard error bn%d er=%o ds=%b\n",
		    MUUNIT(bp->b_dev), bp->b_blkno,
		    sc->sc_erreg, sc->sc_dsreg, mtds_bits);
		mtaddr->mtid = MTID_CLR;		/* reset the TM78 */
		DELAY(250);
		while ((mtaddr->mtid & MTID_RDY) == 0)	/* wait for it */
			;
E 18
I 18
D 19
		printf("mu%d: hard error (non data transfer) rn=%d bn=%d er=%o (octal) ds=%b\n",
E 19
I 19
D 23
		tprintf(sc->sc_ttyp, "mu%d: hard error (non data transfer) rn=%d bn=%d er=%o (octal) ds=%b\n",
E 23
I 23
		tprintf(sc->sc_ttyp, "\
mu%d: hard error (non data transfer) rn=%d bn=%d er=0%o ds=%b\n",
E 23
E 19
		    MUUNIT(bp->b_dev), sc->sc_blkno, bp->b_blkno,
		    er, MASKREG(sc->sc_dsreg), mtds_bits);
#ifdef MTLERRM
D 23
		mtintfail(sc);
		printf("     interrupt code = %o (octal) <%s>\n     failure code = %o (octal) <%s>\n",
		    (er & MTER_INTCODE), sc->sc_mesg,
		    (er & MTER_FAILCODE) >> 10, sc->sc_fmesg);
E 23
I 23
		mtintfail(er);
E 23
#endif
D 23
		if (   ((er & MTER_INTCODE) == MTER_TMFLTB)
		    || ((er & MTER_INTCODE) == MTER_MBFLT) ) {
E 23
I 23
		if ((er & MTER_INTCODE) == MTER_TMFLTB ||
		    (er & MTER_INTCODE) == MTER_MBFLT)
E 23
			mtcreset(mtaddr);	/* reset the controller */
D 23
		}
E 23
E 18
		bp->b_flags |= B_ERROR;
		return (MBN_DONE);
	}
	/* NOTREACHED */
}

I 18
D 23
void mtcreset(mtaddr)
E 23
I 23
void
mtcreset(mtaddr)
E 23
	register struct mtdevice *mtaddr;
{
	register int i;

	mtaddr->mtid = MTID_CLR;		/* reset the TM78 */
	DELAY(200);
	for (i = MTTIMEOUT; i > 0; i--) {
		DELAY(50);			/* don't nag */
		if ((mtaddr->mtid & MTID_RDY) != 0)
			return;			/* exit when ready */
	}
	printf("mt: controller hung\n");
}

E 18
D 7
mtread(dev)
E 7
I 7
D 23
mtread(dev, uio)
E 7
	dev_t dev;
I 7
	struct uio *uio;
E 7
{
I 9
	int errno;
E 9

D 7
	mtphys(dev);
E 7
I 7
D 9
	u.u_error = mtphys(dev, uio);
E 7
	if (u.u_error)
		return;
D 7
	physio(mtstrategy, &rmtbuf[MTUNIT(dev)], dev, B_READ, minphys);
E 7
I 7
	physio(mtstrategy, &rmtbuf[MTUNIT(dev)], dev, B_READ, minphys, uio);
E 9
I 9
	errno = mtphys(dev, uio);
	if (errno)
		return (errno);
	return (physio(mtstrategy, &rmtbuf[MTUNIT(dev)], dev, B_READ, minphys, uio));
E 9
E 7
}

I 18

E 18
D 8
mtwrite(dev)
E 8
I 8
mtwrite(dev, uio)
	dev_t dev;
	struct uio *uio;
E 8
{
I 9
	int errno;
E 9

D 7
	mtphys(dev);
E 7
I 7
D 8
	mtphys(dev, 0);
E 8
I 8
D 9
	u.u_error = mtphys(dev, uio);
E 8
E 7
	if (u.u_error)
		return;
D 7
	physio(mtstrategy, &rmtbuf[MTUNIT(dev)], dev, B_WRITE, minphys);
E 7
I 7
D 8
	physio(mtstrategy, &rmtbuf[MTUNIT(dev)], dev, B_WRITE, minphys, 0);
E 8
I 8
	physio(mtstrategy, &rmtbuf[MTUNIT(dev)], dev, B_WRITE, minphys, uio);
E 9
I 9
	errno = mtphys(dev, uio);
	if (errno)
		return (errno);
	return (physio(mtstrategy, &rmtbuf[MTUNIT(dev)], dev, B_WRITE, minphys, uio));
E 9
E 8
E 7
}

D 7
mtphys(dev)
E 7
I 7
mtphys(dev, uio)
E 7
	dev_t dev;
I 7
	struct uio *uio;
E 7
{
	register int mtunit;
D 18
	register struct mu_softc *sc;
	register struct mba_device *mi;
	daddr_t a;
E 18
I 18
	struct mba_device *mi;
	register int bsize = uio->uio_iov->iov_len;
E 18

	mtunit = MTUNIT(dev);
D 8
	if (mtunit >= NMT || (mi = mtinfo[mtunit]) == 0 || mi->mi_alive == 0) {
		u.u_error = ENXIO;
E 8
I 8
D 18
	if (mtunit >= NMT || (mi = mtinfo[mtunit]) == 0 || mi->mi_alive == 0)
E 18
I 18
	if (   (mtunit >= NMT)
	    || ((mi = mtinfo[mtunit]) == 0)
	    || (mi->mi_alive == 0) )
E 18
E 8
D 7
		return;
E 7
I 7
		return (ENXIO);
E 7
D 8
	}
D 7
	a = u.u_offset >> 9;
E 7
I 7
	if (uio)
		a = uio->uio_offset >> 9;
	else
		a = u.u_offset >> 9;
E 8
I 8
D 18
	a = uio->uio_offset >> 9;
E 8
E 7
	sc = &mu_softc[MUUNIT(dev)];
D 4
	sc->sc_blkno = dbtofsb(a);
	sc->sc_nxrec = dbtofsb(a)+1;
E 4
I 4
	sc->sc_blkno = bdbtofsb(a);
	sc->sc_nxrec = bdbtofsb(a)+1;
E 18
I 18
	if (   (bsize > 0xffff)	/* controller limit */
	    || (bsize <= 0) )	/* ambiguous */
		return (EINVAL);
E 18
I 7
	return (0);
E 7
E 4
}

E 23
/*ARGSUSED*/
D 6
mtioctl(dev, cmd, addr, flag)
E 6
I 6
mtioctl(dev, cmd, data, flag)
E 6
	dev_t dev;
	int cmd;
D 6
	caddr_t addr;
E 6
I 6
	caddr_t data;
E 6
	int flag;
{
	register struct mu_softc *sc = &mu_softc[MUUNIT(dev)];
	register struct buf *bp = &cmtbuf[MTUNIT(dev)];
D 18
	register callcount;
D 3
	register int n, op;
E 3
I 3
	register int op;
E 3
	int fcount;
D 6
	struct mtop mtop;
	struct mtget mtget;
E 6
I 6
	struct mtop *mtop;
	struct mtget *mtget;
E 6
	/* we depend of the values and order of the MT codes here */
E 18
I 18
	register struct mtop *mtop;
	register struct mtget *mtget;
	int callcount, fcount;
	int op;

	/* We depend on the values and order of the MT codes here. */

E 18
	static mtops[] =
	{MT_WTM,MT_SFORWF,MT_SREVF,MT_SFORW,MT_SREV,MT_REW,MT_UNLOAD,MT_SENSE};

	switch (cmd) {
D 6
		case MTIOCTOP:	/* tape operation */
		if (copyin((caddr_t)addr, (caddr_t)&mtop, sizeof(mtop))) {
			u.u_error = EFAULT;
			return;
		}
		switch(mtop.mt_op) {
E 6
I 6

D 18
	case MTIOCTOP:	/* tape operation */
E 18
I 18
	/* tape operation */

	case MTIOCTOP:
E 18
D 12
		mtop = (struct mtop *)mtop;
		switch(mtop->mt_op) {
E 12
I 12
		mtop = (struct mtop *)data;
		switch (mtop->mt_op) {
E 12

E 6
		case MTWEOF:
D 6
			callcount = mtop.mt_count;
E 6
I 6
			callcount = mtop->mt_count;
E 6
			fcount = 1;
			break;
I 6

E 6
		case MTFSF: case MTBSF:
D 6
			callcount = mtop.mt_count;
E 6
I 6
			callcount = mtop->mt_count;
E 6
			fcount = 1;
			break;
I 6

E 6
		case MTFSR: case MTBSR:
			callcount = 1;
D 6
			fcount = mtop.mt_count;
E 6
I 6
			fcount = mtop->mt_count;
E 6
			break;
I 6

E 6
		case MTREW: case MTOFFL:
			callcount = 1;
			fcount = 1;
			break;
I 6

E 6
		default:
D 11
			u.u_error = ENXIO;
			return;
E 11
I 11
			return (ENXIO);
E 11
		}
D 11
		if (callcount <= 0 || fcount <= 0) {
			u.u_error = ENXIO;
			return;
		}
E 11
I 11
D 18
		if (callcount <= 0 || fcount <= 0)
E 18
I 18
D 23
		if ((callcount <= 0) || (fcount <= 0))
E 23
I 23
		if (callcount <= 0 || fcount <= 0)
E 23
E 18
			return (EINVAL);
E 11
D 6
		op = mtops[mtop.mt_op];
E 6
I 6
		op = mtops[mtop->mt_op];
E 6
		if (op == MT_WTM)
			op |= sc->sc_dens;
		while (--callcount >= 0) {
D 18
			register int n;
E 18
I 18
			register int n, fc = fcount;
E 18

			do {
D 3
				n = min(fcount, 0xff);
E 3
I 3
D 18
				n = MIN(fcount, 0xff);
E 18
I 18
				n = MIN(fc, 0xff);
E 18
E 3
				mtcommand(dev, op, n);
D 18
				fcount -= n;
			} while (fcount);
D 6
			if ((mtop.mt_op == MTFSR || mtop.mt_op == MTBSR) &&
E 6
I 6
			if ((mtop->mt_op == MTFSR || mtop->mt_op == MTBSR) &&
E 6
D 11
			    bp->b_resid) {
				u.u_error = EIO;
				break;
			}
E 11
I 11
			    bp->b_resid)
				return (EIO);
E 11
			if (bp->b_flags&B_ERROR)
E 18
I 18
				n -= sc->sc_resid;
				fc -= n;
				switch (mtop->mt_op) {

				case MTWEOF:
					sc->sc_blkno += (daddr_t)n;
					sc->sc_nxrec = sc->sc_blkno - 1;
					break;

				case MTOFFL:
				case MTREW:
				case MTFSF:
					sc->sc_blkno = (daddr_t)0;
					sc->sc_nxrec = (daddr_t)INF;
					break;

				case MTBSF:
					if (sc->sc_resid) {
						sc->sc_blkno = (daddr_t)0;
						sc->sc_nxrec = (daddr_t)INF;
					} else {
						sc->sc_blkno = (daddr_t)(-1);
						sc->sc_nxrec = (daddr_t)(-1);
					}
					break;

				case MTFSR:
					sc->sc_blkno += (daddr_t)n;
					break;

				case MTBSR:
					sc->sc_blkno -= (daddr_t)n;
					break;
				}
				if (sc->sc_resid)
					break;
			} while (fc);
			if (fc) {
				sc->sc_resid = callcount + fc;
D 23
				if (   (mtop->mt_op == MTFSR)
				    || (mtop->mt_op == MTBSR) )
E 23
I 23
				if (mtop->mt_op == MTFSR ||
				    mtop->mt_op == MTBSR)
E 23
					return (EIO);
D 23
				else
					break;
E 23
I 23
				break;
E 23
			}
			if (bp->b_flags & B_ERROR)
E 18
				break;
		}
D 11
		geterror(bp);
		return;
E 11
I 11
D 14
		geterror(bp);		/* XXX */
		return (u.u_error);	/* XXX */
E 14
I 14
		return (geterror(bp));
E 14
E 11
I 6

I 18
	/* tape status */
D 23

E 23
E 18
E 6
	case MTIOCGET:
D 6
		mtget.mt_erreg = sc->sc_erreg;
		mtget.mt_resid = sc->sc_resid;
E 6
I 6
		mtget = (struct mtget *)data;
		mtget->mt_erreg = sc->sc_erreg;
		mtget->mt_resid = sc->sc_resid;
E 6
		mtcommand(dev, MT_SENSE, 1);	/* update drive status */
D 6
		mtget.mt_dsreg = sc->sc_dsreg;
		mtget.mt_type = MT_ISMT;
		if (copyout((caddr_t)&mtget, addr, sizeof(mtget)))
			u.u_error = EFAULT;
E 6
I 6
		mtget->mt_dsreg = sc->sc_dsreg;
		mtget->mt_type = MT_ISMT;
E 6
D 11
		return;
E 11
I 11
		break;
E 11
I 6

I 18
	/* ignore EOT condition */
D 23

E 23
	case MTIOCIEOT:
		sc->sc_flags |= H_IEOT;
		break;

	/* enable EOT condition */
D 23

E 23
	case MTIOCEEOT:
		sc->sc_flags &= ~H_IEOT;
		break;

E 18
E 6
	default:
D 11
		u.u_error = ENXIO;
E 11
I 11
		return (ENXIO);
E 11
	}
I 11
	return (0);
E 11
}

#define	DBSIZE	20

mtdump()
{
	register struct mba_device *mi;
	register struct mba_regs *mp;
D 12
	register struct mtdevice *mtaddr;
E 12
	int blk, num;
	int start;

	start = 0;
	num = maxfree;
#define	phys(a,b)		((b)((int)(a)&0x7fffffff))
	if (mtinfo[0] == 0)
		return (ENXIO);
	mi = phys(mtinfo[0], struct mba_device *);
	mp = phys(mi->mi_hd, struct mba_hd *)->mh_physmba;
	mp->mba_cr = MBCR_IE;
D 3
	mtaddr = (struct mtdevice *)&mp->mba_drv[mi->mi_drive];
E 3
I 3
#if lint
D 12
	blk = blk; num = num; start = start;
E 12
I 12
	blk = 0; num = blk; start = num; blk = start;
E 12
	return (0);
#endif
E 3
#ifdef notyet
I 3
	mtaddr = (struct mtdevice *)&mp->mba_drv[mi->mi_drive];
E 3
	mtaddr->mttc = MTTC_PDP11|MTTC_1600BPI;
	mtaddr->mtcs1 = MT_DCLR|MT_GO;
	while (num > 0) {
		blk = num > DBSIZE ? DBSIZE : num;
		mtdwrite(start, blk, mtaddr, mp);
		start += blk;
		num -= blk;
	}
	mteof(mtaddr);
	mteof(mtaddr);
	mtwait(mtaddr);
	if (mtaddr->mtds&MTDS_ERR)
		return (EIO);
	mtaddr->mtcs1 = MT_REW|MT_GO;
	return (0);
}

mtdwrite(dbuf, num, mtaddr, mp)
	register dbuf, num;
	register struct mtdevice *mtaddr;
	struct mba_regs *mp;
{
	register struct pte *io;
	register int i;

	mtwait(mtaddr);
	io = mp->mba_map;
	for (i = 0; i < num; i++)
		*(int *)io++ = dbuf++ | PG_V;
	mtaddr->mtfc = -(num*NBPG);
	mp->mba_sr = -1;
	mp->mba_bcr = -(num*NBPG);
	mp->mba_var = 0;
	mtaddr->mtcs1 = MT_WCOM|MT_GO;
}

mtwait(mtaddr)
	struct mtdevice *mtaddr;
{
	register s;

	do
		s = mtaddr->mtds;
	while ((s & MTDS_DRY) == 0);
}

mteof(mtaddr)
	struct mtdevice *mtaddr;
{

	mtwait(mtaddr);
	mtaddr->mtcs1 = MT_WEOF|MT_GO;
#endif notyet
}
I 18

#ifdef MTLERRM
D 23
mtintfail(sc)
	register struct mu_softc *sc;
{
	switch (sc->sc_erreg & MTER_INTCODE) {
E 23
I 23
/*
 * Failure messages for each failure code, per interrupt code.
 * Each table ends with a code of -1 as a default.
 */
struct fmesg {
	int	f_code;
	char	*f_mesg;
};
E 23

D 23
	/* unexpected BOT detected */
E 23
I 23
static char unclass[] = "unclassified failure code";
E 23

D 23
	case MTER_BOT:
		sc->sc_mesg = "unexpected BOT";
		switch ((sc->sc_erreg & MTER_FAILCODE) >> 10) {
		case 01:
			sc->sc_fmesg = "tape was at BOT";
			break;
		case 02:
			sc->sc_fmesg = "BOT seen after tape started";
			break;
		case 03:
			sc->sc_fmesg = "ARA ID detected";
			break;
		default:
			sc->sc_fmesg = "unclassified failure code";
		}
		break;
E 23
I 23
/* MTER_BOT */
static struct fmesg botmsg[] = {
	01,	"tape was at BOT",
	02,	"BOT seen after tape started",
	03,	"ARA ID detected",
	-1,	unclass
};
E 23

D 23
	/* unexpected LEOT detected */
E 23
I 23
/* MTER_NOTRDY */
static struct fmesg notrdymsg[] = {
	01,	"TU on-line but not ready",
	02,	"fatal error has occurred",
D 25
	03,	"access allowed by not really"
E 25
I 25
	03,	"access allowed but not ready",
E 25
	-1,	unclass
};
E 23

D 23
	case MTER_LEOT:
		sc->sc_mesg = "unexpected LEOT";
		sc->sc_fmesg = "";
		break;
E 23
I 23
/* MTER_NOTCAP */
static struct fmesg notcapmsg[] = {
	01,	"no record found within 25 feet",
	02,	"ID burst neither PE nor GCR",
	03,	"ARA ID not found",
	04,	"no gap found after ID burst",
	-1,	unclass
};
E 23

D 23
	/* rewinding */
E 23
I 23
/* MTER_LONGREC */
static struct fmesg longrecmsg[] = {
	00,	"extended sense data not found",
	01,	"extended sense data updated",
	-1,	unclass
};
E 23

D 23
	case MTER_RWDING:
		sc->sc_mesg = "tape rewinding";
		sc->sc_fmesg = "";
		break;
E 23
I 23
/* MTER_UNREAD, MTER_ERROR, MTER_EOTERR, MTER_BADTAPE */
static struct fmesg code22msg[] = {
	01,	"GCR write error",
	02,	"GCR read error",
	03,	"PE read error",
	04,	"PE write error",
	05,	"at least 1 bit set in ECCSTA",
	06,	"PE write error",
	07,	"GCR write error",
	010,	"RSTAT contains bad code",
	011,	"PE write error",
	012,	"MASSBUS parity error",
	013,	"invalid data transferred",
	-1,	unclass
};
E 23

D 23
	/* not ready */
E 23
I 23
/* MTER_TMFLTA */
static struct fmesg tmfltamsg[] = {
	01,	"illegal command code",
	02,	"DT command issued when NDT command active",
	03,	"WMC error",
	04,	"RUN not received from MASSBUS controller",
	05,	"mismatch in command read - function routine",
	06,	"ECC ROM parity error",
	07,	"XMC ROM parity error",
	010,	"mismatch in command read - ID burst command",
	011,	"mismatch in command read - verify ARA burst command",
	012,	"mismatch in command read - verify ARA ID command",
	013,	"mismatch in command read - verify gap command",
	014,	"mismatch in command read - read id burst command",
	015,	"mismatch in command read - verify ARA ID command",
	016,	"mismatch in command read - verify gap command",
	017,	"mismatch in command read - find gap command",
	020,	"WMC LEFT failed to set",
	021,	"XL PE set in INTSTA register",
	022,	"XMC DONE did not set",
	023,	"WMC ROM PE or RD PE set in WMCERR register",
	-1,	unclass
};
E 23

D 23
	case MTER_NOTRDY:
		sc->sc_mesg = "drive not ready";
		switch ((sc->sc_erreg & MTER_FAILCODE) >> 10) {
		case 01:
			sc->sc_fmesg = "TU on-line but not ready";
			break;
		case 02:
			sc->sc_fmesg = "fatal error has occurred";
			break;
		case 03:
			sc->sc_fmesg = "access allowed but not really";
			break;
		default:
			sc->sc_fmesg = "unclassified failure code";
		}
		break;
E 23
I 23
/* MTER_TUFLTA */
static struct fmesg tufltamsg[] = {
	01,	"TU status parity error",
	02,	"TU command parity error",
	03,	"rewinding tape went offline",
	04,	"tape went not ready during DSE",
	05,	"TU CMD status changed during DSE",
	06,	"TU never came up to speed",
	07,	"TU velocity changed",
	010,	"TU CMD did not load correctly to start tape motion",
	011,	"TU CMD did not load correctly to set drive density",
	012,	"TU CMD did not load correctly to start tape motion to write BOT ID",
	013,	"TU CMD did not load correctly to backup tape to BOT after failing to write BOT ID",
	014,	"failed to write density ID burst",
	015,	"failed to write ARA burst",
	016,	"failed to write ARA ID",
	017,	"ARA error bit set in MTA status B register",
	021,	"could not find a gap after ID code was written correctly",
	022,	"TU CMD did not load correctly to start tape motion to read ID burst",
	023,	"timeout looking for BOT after detecting ARA ID burst",
	024,	"failed to write tape mark",
	025,	"tape never came up to speed while trying to reposition for retry of writing tape mark",
	026,	"TU CMD did not load correctly to start tape motion in erase gap routine",
	027,	"could not detect a gap in in erase gap routine",
	030,	"could not detect a gap after writing record",
	031,	"read path terminated before entire record was written",
	032,	"could not find a gap after writing record and read path terminated early",
	033,	"TU CMD did not load correctly to backup for retry of write tape mark",
	034,	"TU velocity changed after up to speed while trying to reposition for retry of writing tape mark",
	035,	"TU CMD did not load correctly to backup to retry a load of BOT ID",
	036,	"timeout looking for BOT after failing to write BOT ID",
	037,	"TU velocity changed while writing PE gap before starting to write record",
	040,	"TU CMD did not load correctly to set PE tape density at start of write BOT ID burst",
	041,	"TU CMD did not load correctly to set GCR tape density after writing Density ID",
	042,	"TU CMD did not load correctly to set PE tape density at start of read from BOT",
	043,	"TU CMD did not load correctly to set GCR tape density after reading a GCR Density ID burst",
};
E 23

D 23
	/* not available */
E 23
I 23
/* MTER_TMFLTB */
static char inlinetest[] = "inline test failed";
static struct fmesg tmfltbmsg[] = {
	00,	"RST0 interrupt occurred with TM RDY set",
	01,	"power failed to interrupt",
	02,	"unknown interrupt on channel 5.5",
	03,	"unknown interrupt on channel 6.5",
	04,	"unknown interrupt on channel 7",
	05,	"unknown interrupt on channel 7.5",
	06,	"CAS contention retry count expired",
	07,	"CAS contention error not retryable",
	010,	"queue error, could not find queue entry",
	011,	"queue entry already full",
	012,	"8085 ROM parity error",
	013,	inlinetest,
	013,	inlinetest,
	014,	inlinetest,
	015,	inlinetest,
	016,	inlinetest,
	017,	inlinetest,
	020,	inlinetest,
	021,	inlinetest,
	022,	inlinetest,
	023,	inlinetest,
	024,	inlinetest,
	025,	inlinetest,
	026,	inlinetest,
	027,	inlinetest,
	030,	inlinetest,
	031,	inlinetest,
	032,	inlinetest,
	033,	inlinetest,
	034,	inlinetest,
	035,	inlinetest,
	036,	inlinetest,
	037,	inlinetest,
	040,	inlinetest,
	041,	inlinetest,
	042,	inlinetest,
	043,	inlinetest,
	044,	inlinetest,
D 25
	045,	inlinetest
E 25
I 25
	045,	inlinetest,
E 25
	046,	inlinetest,
	047,	inlinetest,
	050,	inlinetest,
	051,	inlinetest,
	052,	inlinetest,
	053,	inlinetest,
	054,	inlinetest,
	055,	inlinetest,
	056,	inlinetest,
	057,	inlinetest,
	-1,	unclass
};
E 23

D 23
	case MTER_NOTAVL:
		sc->sc_mesg = "drive not available";
		sc->sc_fmesg = "";
		break;
E 23
I 23
/* MTER_MBFLT */
static struct fmesg mbfltmsg[] = {
	01,	"control bus parity error",
	02,	"illegal register referenced",
	-1,	unclass
};
E 23

D 23
	/* unit does not exist */
E 23
I 23
/*
 * MTER_LEOT, MTER_RWDING, NTER_NOTAVL, MTER_NONEX, MTER_KEYFAIL,
 * and default: no failure message.
 */
static struct fmesg nullmsg[] = {
	-1,	""
};
E 23

D 23
	case MTER_NONEX:
		sc->sc_mesg = "unit does not exist";
		sc->sc_fmesg = "";
		break;
E 23
I 23
/*
 * Interrupt code table.
 */
static struct errmsg {
	int	e_code;
	char	*e_mesg;
	struct	fmesg *e_fmesg;
} errmsg[] = {
	MTER_BOT,	"unexpected BOT",	botmsg,
	MTER_LEOT,	"unexpected LEOT",	nullmsg,
	MTER_RWDING,	"tape rewinding",	nullmsg,
	MTER_NOTRDY,	"drive not ready",	notrdymsg,
	MTER_NOTAVL,	"drive not available",	nullmsg,
	MTER_NONEX,	"unit does not exist",	nullmsg,
	MTER_NOTCAP,	"not capable",		notcapmsg,
	MTER_LONGREC,	"long record",		longrecmsg,
	MTER_UNREAD,	"unreadable record",	code22msg,
	MTER_ERROR,	"error",		code22msg,
	MTER_EOTERR,	"EOT error",		code22msg,
	MTER_BADTAPE,	"tape position lost",	code22msg,
	MTER_TMFLTA,	"TM fault A",		tmfltamsg,
	MTER_TUFLTA,	"TU fault A",		tufltamsg,
	MTER_TMFLTB,	"TM fault B",		tmfltbmsg,
	MTER_MBFLT,	"MB fault",		mbfltmsg,
	MTER_KEYFAIL,	"keypad entry error",	nullmsg,
	-1,		"unclassified error",	nullmsg
};
E 23

D 23
	/* not capable */

	case MTER_NOTCAP:
		sc->sc_mesg = "not capable";
		switch ((sc->sc_erreg & MTER_FAILCODE) >> 10) {
		case 01:
			sc->sc_fmesg = "no record found within 25 feet";
			break;
		case 02:
			sc->sc_fmesg = "ID burst neither PE nor GCR";
			break;
		case 03:
			sc->sc_fmesg = "ARA ID not found";
			break;
		case 04:
			sc->sc_fmesg = "no gap found after ID burst";
			break;
		default:
			sc->sc_fmesg = "unclassified failure code";
		}
		break;

	/* long tape record */

	case MTER_LONGREC:
		sc->sc_mesg = "long record";
		switch ((sc->sc_erreg & MTER_FAILCODE) >> 10) {
		case 00:
			sc->sc_fmesg = "extended sense data not found";
			break;
		case 01:
			sc->sc_fmesg = "extended sense data updated";
			break;
		default:
			sc->sc_fmesg = "unclassified failure code";
		}
		break;

	/* unreadable */

	case MTER_UNREAD:
		sc->sc_mesg = "unreadable record";
		goto code22;

	/* error */

	case MTER_ERROR:
		sc->sc_mesg = "error";
		goto code22;

	/* EOT error */

	case MTER_EOTERR:
		sc->sc_mesg = "EOT error";
		goto code22;

	/* tape position lost */

	case MTER_BADTAPE:
		sc->sc_mesg = "bad tape";
	code22:
		switch ((sc->sc_erreg & MTER_FAILCODE) >> 10) {
		case 01:
			sc->sc_fmesg = "GCR write error";
			break;
		case 02:
			sc->sc_fmesg = "GCR read error";
			break;
		case 03:
			sc->sc_fmesg = "PE read error";
			break;
		case 04:
			sc->sc_fmesg = "PE write error";
			break;
		case 05:
			sc->sc_fmesg = "at least 1 bit set in ECCSTA";
			break;
		case 06:
			sc->sc_fmesg = "PE write error";
			break;
		case 07:
			sc->sc_fmesg = "GCR write error";
			break;
		case 010:
			sc->sc_fmesg = "RSTAT contains bad code";
			break;
		case 011:
			sc->sc_fmesg = "PE write error";
			break;
		case 012:
			sc->sc_fmesg = "MASSBUS parity error";
			break;
		case 013:
			sc->sc_fmesg = "invalid data transferred";
			break;
		default:
			sc->sc_fmesg = "unclassified failure code";
		}
		break;

	/* TM fault A */

	case MTER_TMFLTA:
		sc->sc_mesg = "TM fault A";
		switch ((sc->sc_erreg & MTER_FAILCODE) >> 10) {
		case 01:
			sc->sc_fmesg = "illegal command code";
			break;
		case 02:
			sc->sc_fmesg = "DT command issued when NDT command active";
			break;
		case 03:
			sc->sc_fmesg = "WMC error";
			break;
		case 04:
			sc->sc_fmesg = "RUN not received from MASSBUS controller";
			break;
		case 05:
			sc->sc_fmesg = "mismatch in command read - function routine";
			break;
		case 06:
			sc->sc_fmesg = "ECC ROM parity error";
			break;
		case 07:
			sc->sc_fmesg = "XMC ROM parity error";
			break;
		case 010:
			sc->sc_fmesg = "mismatch in command read - ID burst command";
			break;
		case 011:
			sc->sc_fmesg = "mismatch in command read - verify ARA burst command";
			break;
		case 012:
			sc->sc_fmesg = "mismatch in command read - verify ARA ID command";
			break;
		case 013:
			sc->sc_fmesg = "mismatch in command read - verify gap command";
			break;
		case 014:
			sc->sc_fmesg = "mismatch in command read - read id burst command";
			break;
		case 015:
			sc->sc_fmesg = "mismatch in command read - verify ARA ID command";
			break;
		case 016:
			sc->sc_fmesg = "mismatch in command read - verify gap command";
			break;
		case 017:
			sc->sc_fmesg = "mismatch in command read - find gap command";
			break;
		case 020:
			sc->sc_fmesg = "WMC LEFT failed to set";
			break;
		case 021:
			sc->sc_fmesg = "XL PE set in INTSTA register";
			break;
		case 022:
			sc->sc_fmesg = "XMC DONE did not set";
			break;
		case 023:
			sc->sc_fmesg = "WMC ROM PE or RD PE set in WMCERR register";
			break;
		default:
			sc->sc_fmesg = "unclassified failure code";
		}
		break;
E 23
I 23
/*
 * Decode an interrupt-time failure.
 */
mtintfail(erreg)
	int erreg;
{
	register struct errmsg *e;
	register struct fmesg *f;
	register int ecode, fcode;
E 23

D 23
	/* TU fault A */

	case MTER_TUFLTA:
		sc->sc_mesg = "TU fault A";
		switch ((sc->sc_erreg & MTER_FAILCODE) >> 10) {
		case 01:
			sc->sc_fmesg = "TU status parity error";
E 23
I 23
	ecode = erreg & MTER_INTCODE;
	fcode = (erreg & MTER_FAILCODE) >> MTER_FSHIFT;
	for (e = errmsg; e->e_code >= 0; e++)
		if (e->e_code == ecode)
E 23
			break;
D 23
		case 02:
			sc->sc_fmesg = "TU command parity error";
E 23
I 23
	for (f = e->e_fmesg; f->f_code >= 0; f++)
		if (f->f_code == fcode)
E 23
			break;
D 23
		case 03:
			sc->sc_fmesg = "rewinding tape went offline";
			break;
		case 04:
			sc->sc_fmesg = "tape went not ready during DSE";
			break;
		case 05:
			sc->sc_fmesg = "TU CMD status changed during DSE";
			break;
		case 06:
			sc->sc_fmesg = "TU never came up to speed";
			break;
		case 07:
			sc->sc_fmesg = "TU velocity changed";
			break;
		case 010:
			sc->sc_fmesg = "TU CMD did not load correctly to start tape motion";
			break;
		case 011:
			sc->sc_fmesg = "TU CMD did not load correctly to set drive density";
			break;
		case 012:
			sc->sc_fmesg = "TU CMD did not load correctly to start tape motion to write BOT ID";
			break;
		case 013:
			sc->sc_fmesg = "TU CMD did not load correctly to backup tape to BOT after failing to write BOT ID";
			break;
		case 014:
			sc->sc_fmesg = "failed to write density ID burst";
			break;
		case 015:
			sc->sc_fmesg = "failed to write ARA burst";
			break;
		case 016:
			sc->sc_fmesg = "failed to write ARA ID";
			break;
		case 017:
			sc->sc_fmesg = "ARA error bit set in MTA status B register";
			break;
		case 021:
			sc->sc_fmesg = "could not find a gap after ID code was written correctly";
			break;
		case 022:
			sc->sc_fmesg = "TU CMD did not load correctly to start tape motion to read ID burst";
			break;
		case 023:
			sc->sc_fmesg = "timeout looking for BOT after detecting ARA ID burst";
			break;
		case 024:
			sc->sc_fmesg = "failed to write tape mark";
			break;
		case 025:
			sc->sc_fmesg = "tape never came up to speed while trying to reposition for retry of writing tape mark";
			break;
		case 026:
			sc->sc_fmesg = "TU CMD did not load correctly to start tape motion in erase gap routine";
			break;
		case 027:
			sc->sc_fmesg = "could not detect a gap in in erase gap routine";
			break;
		case 030:
			sc->sc_fmesg = "could not detect a gap after writing record";
			break;
		case 031:
			sc->sc_fmesg = "read path terminated before entire record was written";
			break;
		case 032:
			sc->sc_fmesg = "could not find a gap after writing record and read path terminated early";
			break;
		case 033:
			sc->sc_fmesg = "TU CMD did not load correctly to backup for retry of write tape mark";
			break;
		case 034:
			sc->sc_fmesg = "TU velocity changed after up to speed while trying to reposition for retry of writing tape mark";
			break;
		case 035:
			sc->sc_fmesg = "TU CMD did not load correctly to backup to retry a load of BOT ID";
			break;
		case 036:
			sc->sc_fmesg = "timeout looking for BOT after failing to write BOT ID";
			break;
		case 037:
			sc->sc_fmesg = "TU velocity changed while writing PE gap before starting to write record";
			break;
		case 040:
			sc->sc_fmesg = "TU CMD did not load correctly to set PE tape density at start of write BOT ID burst";
			break;
		case 041:
			sc->sc_fmesg = "TU CMD did not load correctly to set GCR tape density after writing Density ID";
			break;
		case 042:
			sc->sc_fmesg = "TU CMD did not load correctly to set PE tape density at start of read from BOT";
			break;
		case 043:
			sc->sc_fmesg = "TU CMD did not load correctly to set GCR tape density after reading a GCR Density ID burst";
			break;
		default:
			sc->sc_fmesg = "unclassified failure code";
		}
		break;

	/* TM fault B */

	case MTER_TMFLTB:
		sc->sc_mesg = "TM fault B";
		switch ((sc->sc_erreg & MTER_FAILCODE) >> 10) {
		case 00:
			sc->sc_fmesg = "RST0 interrupt occurred with TM RDY set";
			break;
		case 01:
			sc->sc_fmesg = "power failed to interrupt";
			break;
		case 02:
			sc->sc_fmesg = "unknown interrupt on channel 5.5";
			break;
		case 03:
			sc->sc_fmesg = "unknown interrupt on channel 6.5";
			break;
		case 04:
			sc->sc_fmesg = "unknown interrupt on channel 7";
			break;
		case 05:
			sc->sc_fmesg = "unknown interrupt on channel 7.5";
			break;
		case 06:
			sc->sc_fmesg = "CAS contention retry count expired";
			break;
		case 07:
			sc->sc_fmesg = "CAS contention error not retryable";
			break;
		case 010:
			sc->sc_fmesg = "queue error, could not find queue entry";
			break;
		case 011:
			sc->sc_fmesg = "queue entry already full";
			break;
		case 012:
			sc->sc_fmesg = "8085 ROM parity error";
			break;
		case 013:
		case 014:
		case 015:
		case 016:
		case 017:
		case 020:
		case 021:
		case 022:
		case 023:
		case 024:
		case 025:
		case 026:
		case 027:
		case 030:
		case 031:
		case 032:
		case 033:
		case 034:
		case 035:
		case 036:
		case 037:
		case 040:
		case 041:
		case 042:
		case 043:
		case 044:
		case 045:
		case 046:
		case 047:
		case 050:
		case 051:
		case 052:
		case 053:
		case 054:
		case 055:
		case 056:
		case 057:
			sc->sc_fmesg = "inline test failed";
			break;
		default:
			sc->sc_fmesg = "unclassified failure code";
		}
		break;

	/* MASSBUS fault */

	case MTER_MBFLT:
		sc->sc_mesg = "MB fault";
		switch ((sc->sc_erreg & MTER_FAILCODE) >> 10) {
		case 01:
			sc->sc_fmesg = "control bus parity error";
			break;
		case 02:
			sc->sc_fmesg = "illegal register referenced";
			break;
		default:
			sc->sc_fmesg = "unclassified failure code";
		}
		break;

	/* keypad entry error */

	case MTER_KEYFAIL:
		sc->sc_mesg = "keypad entry error";
		sc->sc_fmesg = "";
		break;
	default:
		sc->sc_mesg = "unclassified error";
		sc->sc_fmesg = "";
		break;
	}
E 23
I 23
	printf("    interrupt code = 0%o <%s>\n", ecode, e->e_mesg);
	printf("    failure code = 0%o <%s>\n", fcode, f->f_mesg);
E 23
}
D 23
#endif MTLERRM
E 18
#endif
E 23
I 23
#endif /* MTLERRM */
#endif /* NMT > 0 */
E 23
E 1
