h05700
s 00001/00001/00870
d D 7.6 88/10/22 15:13:56 karels 34 33
c use ubaalloc macros; use qbgetpri for Q-bus device probe routines
e
s 00000/00006/00871
d D 7.5 88/05/27 17:33:02 karels 33 32
c re-lint
e
s 00008/00007/00869
d D 7.4 88/05/27 16:10:24 karels 32 31
c new diskerr routine
e
s 00000/00024/00876
d D 7.3 88/05/06 17:17:05 bostic 31 30
c changes for raw{read,write} stuff
e
s 00001/00001/00899
d D 7.2 87/01/14 08:47:52 karels 30 29
c rename dk.h to dkstat.h
e
s 00001/00001/00899
d D 7.1 86/06/05 01:10:11 mckusick 29 28
c 4.3BSD release version
e
s 00001/00001/00899
d D 6.12 86/03/04 23:09:47 karels 28 27
c lint
e
s 00007/00002/00893
d D 6.11 85/10/11 16:30:22 mckusick 27 26
c fix to avoid hanging the UNIBUS (from Steve Schoch@ames)
e
s 00001/00001/00894
d D 6.10 85/09/17 18:36:12 eric 26 25
c facilities in syslog
e
s 00003/00001/00892
d D 6.9 85/09/16 22:08:57 karels 25 24
c off by one, and need resid
e
s 00028/00020/00865
d D 6.8 85/09/14 17:19:13 bloom 24 23
c get rid of interleave code, add macro to get unit number, add error return
c codes to strategy, reading last block after end of partition returns size = 0
e
s 00004/00002/00881
d D 6.7 85/08/08 13:52:57 bloom 23 22
c support partial dumps for large memory
e
s 00007/00001/00876
d D 6.6 85/06/08 14:16:43 mckusick 22 21
c Add copyright
e
s 00011/00013/00866
d D 6.5 85/05/02 17:58:47 edward 21 20
c configuring spunned down drives really works now.
e
s 00002/00001/00877
d D 6.4 85/03/12 15:31:10 ralph 20 19
c change softecc printf's to log's.
e
s 00015/00009/00863
d D 6.3 84/12/20 15:49:49 karels 19 18
c attempt to configure RL02's that aren't spun up.
e
s 00016/00016/00856
d D 6.2 84/08/29 20:08:13 bloom 18 17
c Change to includes.  No more ../h
e
s 00000/00000/00872
d D 6.1 83/07/29 07:27:43 sam 17 16
c 4.2 distribution
e
s 00001/00001/00871
d D 4.15 83/05/27 13:52:33 sam 16 15
c lint
e
s 00013/00000/00859
d D 4.14 83/05/18 02:20:55 sam 15 14
c add entry point for swap partition sizing at boot time
e
s 00058/00036/00801
d D 4.13 83/04/30 17:07:56 root 14 13
c dump routine
e
s 00001/00000/00836
d D 4.12 83/02/10 20:15:13 sam 13 11
c hz now only in kernel.h
e
s 00002/00000/00836
d R 4.12 83/02/10 19:55:36 sam 12 11
c hz now only in kernel.h
e
s 00002/00001/00834
d D 4.11 82/12/17 12:02:20 sam 11 10
c sun merge
e
s 00001/00001/00834
d D 4.10 82/11/26 18:17:01 sam 10 9
c don't call ubadone at ubareset time
e
s 00007/00007/00828
d D 4.9 82/10/20 03:12:33 root 9 8
c lint
e
s 00028/00022/00807
d D 4.8 82/10/17 20:17:49 root 8 7
c lint
e
s 00015/00004/00814
d D 4.7 82/10/17 11:49:05 root 7 6
c ioctl/open return errors, not u.u_error; remove ubarelses (it is
c now done in uba.c); add open routines to some disk drivers
e
s 00004/00004/00814
d D 4.6 82/10/10 17:27:20 root 6 5
c header files for vax are in their place
e
s 00004/00006/00814
d D 4.5 82/09/12 03:07:11 root 5 4
c physio returns error, not in u.u_error
e
s 00003/00002/00817
d D 4.4 82/08/22 21:18:16 root 4 3
c fully uio()'d
e
s 00005/00003/00814
d D 4.3 82/08/13 00:15:37 root 3 2
c changes for char dev uio'ing
e
s 00001/00001/00816
d D 4.2 82/07/15 20:00:10 kre 2 1
c probe routines return size of unibus dev regs to reserve space
e
s 00817/00000/00000
d D 4.1 82/05/26 15:16:03 sam 1 0
c date and time created 82/05/26 15:16:03 by sam
e
u
U
t
T
I 1
D 22
/*	%M%	%I%	%E%	*/
E 22
I 22
/*
D 29
 * Copyright (c) 1982 Regents of the University of California.
E 29
I 29
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 29
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 22

#include "rb.h"
#if NIDC > 0
D 7
int idcdebug = 0;
#define printd if(idcdebug)printf
int idctrb[1000];
int *trp = idctrb;
E 7
I 7
int	idcdebug = 0;
#define	printd if(idcdebug)printf
int	idctrb[1000];
int	*trp = idctrb;
E 7
D 8
#define	trace(a,b) {*trp++ = (int)a; *trp++ = (int)b; if(trp>&idctrb[998])trp=idctrb;}
E 8
I 8
#define	trace(a,b) {*trp++ = *(int*)a; *trp++ = (int)b; if(trp>&idctrb[998])trp=idctrb;}
E 8
/*
 * IDC (RB730) disk driver
 *
 * There can only ever be one IDC on a machine,
 * and only on a VAX-11/730.  We take advantage
 * of that to simplify the driver.
 *
 * TODO:
D 21
 *	dk_busy
E 21
 *	ecc
D 14
 *	dump
E 14
 */
I 11
D 32
#include "../machine/pte.h"

E 32
E 11
D 18
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/buf.h"
#include "../h/conf.h"
#include "../h/dir.h"
#include "../h/user.h"
D 11
#include "../h/pte.h"
E 11
#include "../h/map.h"
#include "../h/vm.h"
D 6
#include "../h/ubareg.h"
#include "../h/ubavar.h"
E 6
#include "../h/dk.h"
D 6
#include "../h/cpu.h"
E 6
#include "../h/cmap.h"
#include "../h/dkbad.h"
I 3
#include "../h/uio.h"
I 13
#include "../h/kernel.h"
E 18
I 18
#include "param.h"
#include "systm.h"
#include "buf.h"
#include "conf.h"
#include "dir.h"
#include "user.h"
#include "map.h"
#include "vm.h"
I 32
#include "ioctl.h"
#include "disklabel.h"
E 32
D 30
#include "dk.h"
E 30
I 30
#include "dkstat.h"
E 30
#include "cmap.h"
#include "dkbad.h"
#include "uio.h"
#include "kernel.h"
I 20
#include "syslog.h"
E 20
E 18
E 13
E 3

I 32
#include "../machine/pte.h"
E 32
D 6
#include "../h/idcreg.h"
E 6
I 6
#include "../vax/cpu.h"
D 18
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
#include "../vaxuba/idcreg.h"
E 18
I 18
#include "ubareg.h"
#include "ubavar.h"
#include "idcreg.h"
E 18
E 6

struct idc_softc {
	int	sc_bcnt;	/* number of bytes to transfer */
	int	sc_resid;	/* total number of bytes to transfer */
	int	sc_ubaddr;	/* Unibus address of data */
	short	sc_unit;	/* unit doing transfer */
	short	sc_softas;	/* software attention summary bits */
	union idc_dar {
		long	dar_l;
		u_short	dar_w[2];
		u_char	dar_b[4];
	} sc_un;		/* prototype disk address register */
} idc_softc;

#define	dar_dar		dar_l		/* the whole disk address */
#define	dar_cyl		dar_w[1]	/* cylinder address */
#define	dar_trk		dar_b[1]	/* track */
#define	dar_sect	dar_b[0]	/* sector */
#define	sc_dar		sc_un.dar_dar
#define	sc_cyl		sc_un.dar_cyl
#define	sc_trk		sc_un.dar_trk
#define	sc_sect		sc_un.dar_sect

I 24
#define idcunit(dev)	(minor(dev) >> 3)

E 24
/* THIS SHOULD BE READ OFF THE PACK, PER DRIVE */
struct size {
	daddr_t	nblocks;
	int	cyloff;
} rb02_sizes[8] ={
	15884,	0,		/* A=cyl 0 thru 399 */
	4480,	400,		/* B=cyl 400 thru 510 */
	20480,	0,		/* C=cyl 0 thru 511 */
	0,	0,
	0,	0,
	0,	0,
	0,	0,
	0,	0,
}, rb80_sizes[8] ={
	15884,	0,		/* A=cyl 0 thru 36 */
	33440,	37,		/* B=cyl 37 thru 114 */
	242606,	0,		/* C=cyl 0 thru 558 */
	0,	0,
	0,	0,
	0,	0,
	82080,	115,		/* G=cyl 115 thru 304 */
	110143,	305,		/* H=cyl 305 thru 558 */
};
/* END OF STUFF WHICH SHOULD BE READ IN PER DISK */

int	idcprobe(), idcslave(), idcattach(), idcdgo(), idcintr();
struct	uba_ctlr *idcminfo[NIDC];
struct	uba_device *idcdinfo[NRB];

u_short	idcstd[] = { 0174400, 0};
struct	uba_driver idcdriver =
 { idcprobe, idcslave, idcattach, idcdgo, idcstd, "rb", idcdinfo, "idc", idcminfo, 0 };
struct	buf idcutab[NRB];
union	idc_dar idccyl[NRB];

struct	idcst {
	short	nbps;
	short	nsect;
	short	ntrak;
	short	nspc;
	short	ncyl;
	struct	size *sizes;
} idcst[] = {
	256, NRB02SECT, NRB02TRK, NRB02SECT*NRB02TRK, NRB02CYL,	rb02_sizes,
	512, NRB80SECT, NRB80TRK, NRB80SECT*NRB80TRK, NRB80CYL,	rb80_sizes,
};

D 31
struct	buf ridcbuf[NRB];

E 31
#define	b_cylin	b_resid

D 24
#ifdef INTRLVE
daddr_t	dkblock();
#endif

E 24
int	idcwstart, idcwticks, idcwatch();

I 8
/*ARGSUSED*/
E 8
idcprobe(reg)
	caddr_t reg;
{
	register int br, cvec;
	register struct idcdevice *idcaddr;

#ifdef lint	
	br = 0; cvec = br; br = cvec;
#endif
	idcaddr = (struct idcdevice *)((caddr_t)uba_hd[0].uh_uba + 0x200);
	idcaddr->idccsr = IDC_ATTN|IDC_IE;
	while ((idcaddr->idccsr & IDC_CRDY) == 0)
		;
	idcaddr->idccsr = IDC_ATTN|IDC_CRDY;
D 2
	return (1);
E 2
I 2
	return (sizeof (struct idcdevice));
E 2
}

I 8
/*ARGSUSED*/
E 8
idcslave(ui, reg)
	struct uba_device *ui;
	caddr_t reg;
{
	register struct idcdevice *idcaddr;
	register int i;

	idcaddr = (struct idcdevice *)((caddr_t)uba_hd[0].uh_uba + 0x200);
	ui->ui_type = 0;
	idcaddr->idcmpr = IDCGS_GETSTAT;
	idcaddr->idccsr = IDC_GETSTAT|(ui->ui_slave<<8);
D 9
	idcwait(idcaddr, 0);
E 9
I 9
	(void) idcwait(idcaddr, 0);
E 9
	i = idcaddr->idcmpr;
	idcaddr->idccsr = IDC_CRDY|(1<<(ui->ui_slave+16));
D 19
	/* read header to synchronize microcode */
E 19
D 9
	idcwait(idcaddr, 0);
E 9
I 9
	(void) idcwait(idcaddr, 0);
E 9
D 19
	idcaddr->idccsr = (ui->ui_slave<<8)|IDC_RHDR;
D 9
	idcwait(idcaddr, 0);
E 9
I 9
	(void) idcwait(idcaddr, 0);
E 9
	if (idcaddr->idccsr & IDC_ERR)
		return (0);
	i = idcaddr->idcmpr;		/* read header word 1 */
	i = idcaddr->idcmpr;		/* read header word 2 */
E 19
I 19
D 21
	if (idcaddr->idccsr&IDC_R80) {
		/* read header to synchronize microcode */
		idcaddr->idccsr = (ui->ui_slave<<8)|IDC_RHDR;
		(void) idcwait(idcaddr, 0);
		if (idcaddr->idccsr & IDC_ERR)
			return (0);
		i = idcaddr->idcmpr;		/* read header word 1 */
		i = idcaddr->idcmpr;		/* read header word 2 */
E 21
I 21
	/* read header to synchronize microcode */
	idcaddr->idccsr = (ui->ui_slave<<8)|IDC_RHDR;
	(void) idcwait(idcaddr, 0);
	i = idcaddr->idcmpr;		/* read header word 1 */
	i = idcaddr->idcmpr;		/* read header word 2 */
E 21
E 19
I 8
#ifdef lint
D 19
	i = i;
E 19
I 19
D 21
		i = i;
E 21
I 21
	i = i;
E 21
E 19
#endif
I 21
	if ((idcaddr->idccsr & (IDC_ERR|IDC_R80)) == IDC_R80)
E 21
E 8
D 19
	if (idcaddr->idccsr&IDC_R80)
E 19
		ui->ui_type = 1;
I 19
D 21
	} else
E 21
I 21
	else if ((idcaddr->idccsr & (IDC_DE|IDC_R80)) == 0)
E 21
		/*
		 * RB02 may not have pack spun up, just look for drive error.
		 */
D 21
		if (idcaddr->idccsr & IDC_DE)
			return (0);
E 21
I 21
		ui->ui_type = 0;
	else
		return (0);
E 21
E 19
	return (1);
}

idcattach(ui)
	register struct uba_device *ui;
{

	/*
	 * Fix all addresses to correspond
	 * to the "real" IDC address.
	 */
	ui->ui_mi->um_addr = ui->ui_addr = (caddr_t)uba_hd[0].uh_uba + 0x200;
	ui->ui_physaddr = (caddr_t)uba_hd[0].uh_physuba + 0x200;
	if (idcwstart == 0) {
		timeout(idcwatch, (caddr_t)0, hz);
		idcwstart++;
	}
	if (ui->ui_dk >= 0)
		if (ui->ui_type)
			dk_mspw[ui->ui_dk] = 1.0 / (60 * NRB80SECT * 256);
		else
			dk_mspw[ui->ui_dk] = 1.0 / (60 * NRB02SECT * 128);
	idccyl[ui->ui_unit].dar_dar = -1;
	ui->ui_flags = 0;
I 7
}

idcopen(dev)
	dev_t dev;
{
D 24
	register int unit = minor(dev) >> 3;
E 24
I 24
	register int unit = idcunit(dev);
E 24
	register struct uba_device *ui;

	if (unit >= NRB || (ui = idcdinfo[unit]) == 0 || ui->ui_alive == 0)
		return (ENXIO);
	return (0);
E 7
}
 
idcstrategy(bp)
	register struct buf *bp;
{
	register struct uba_device *ui;
	register struct idcst *st;
	register int unit;
	register struct buf *dp;
	int xunit = minor(bp->b_dev) & 07;
	long bn, sz;

	sz = (bp->b_bcount+511) >> 9;
D 24
	unit = dkunit(bp);
	if (unit >= NRB)
E 24
I 24
	unit = idcunit(bp->b_dev);
	if (unit >= NRB) {
		bp->b_error = ENXIO;
E 24
		goto bad;
I 24
	}
E 24
	ui = idcdinfo[unit];
D 24
	if (ui == 0 || ui->ui_alive == 0)
E 24
I 24
	if (ui == 0 || ui->ui_alive == 0) {
		bp->b_error = ENXIO;
E 24
		goto bad;
I 24
	}
E 24
	st = &idcst[ui->ui_type];
	if (bp->b_blkno < 0 ||
D 24
	    (bn = dkblock(bp))+sz > st->sizes[xunit].nblocks)
E 24
I 24
	    (bn = bp->b_blkno)+sz > st->sizes[xunit].nblocks) {
D 25
		if (bp->b_blkno == st->sizes[xunit].nblocks + 1)
E 25
I 25
		if (bp->b_blkno == st->sizes[xunit].nblocks) {
			bp->b_resid = bp->b_bcount;
E 25
			goto done;
I 25
		}
E 25
		bp->b_error = EINVAL;
E 24
		goto bad;
I 24
	}
E 24
	if (ui->ui_type == 0)
		bn *= 2;
	bp->b_cylin = bn/st->nspc + st->sizes[xunit].cyloff;
	(void) spl5();
D 8
	trace('strt',bp);
E 8
I 8
	trace("strt",bp);
E 8
	dp = &idcutab[ui->ui_unit];
	disksort(dp, bp);
	if (dp->b_active == 0) {
D 8
		trace('!act',dp);
E 8
I 8
		trace("!act",dp);
E 8
		(void) idcustart(ui);
		bp = &ui->ui_mi->um_tab;
		if (bp->b_actf && bp->b_active == 0)
			(void) idcstart(ui->ui_mi);
	}
	(void) spl0();
	return;

bad:
	bp->b_flags |= B_ERROR;
I 24
done:
E 24
	iodone(bp);
	return;
}

idcustart(ui)
	register struct uba_device *ui;
{
	register struct buf *bp, *dp;
	register struct uba_ctlr *um;
	register struct idcdevice *idcaddr;
	register struct idcst *st;
	union idc_dar cyltrk;
	daddr_t bn;
	int unit;

	if (ui == 0)
		return (0);
	dk_busy &= ~(1<<ui->ui_dk);
	dp = &idcutab[ui->ui_unit];
	um = ui->ui_mi;
	unit = ui->ui_slave;
D 8
	trace('ust', dp);
E 8
I 8
	trace("ust", dp);
E 8
	idcaddr = (struct idcdevice *)um->um_addr;
	if (um->um_tab.b_active) {
		idc_softc.sc_softas |= 1<<unit;
D 8
		trace('umac',idc_softc.sc_softas);
E 8
I 8
		trace("umac",idc_softc.sc_softas);
E 8
		return (0);
	}
	if ((bp = dp->b_actf) == NULL) {
D 8
		trace('!bp',0);
E 8
I 8
		trace("!bp",0);
E 8
		return (0);
	}
	if (dp->b_active) {
D 8
		trace('dpac',dp->b_active);
E 8
I 8
		trace("dpac",dp->b_active);
E 8
		goto done;
	}
	dp->b_active = 1;
	/* CHECK DRIVE READY? */
D 24
	bn = dkblock(bp);
E 24
I 24
	bn = bp->b_blkno;
E 24
D 8
	trace('seek', bn);
E 8
I 8
	trace("seek", bn);
E 8
	if (ui->ui_type == 0)
		bn *= 2;
	st = &idcst[ui->ui_type];
	cyltrk.dar_cyl = bp->b_cylin;
	cyltrk.dar_trk = (bn / st->nsect) % st->ntrak;
	cyltrk.dar_sect = 0;
	printd("idcustart, unit %d, cyltrk 0x%x\n", unit, cyltrk.dar_dar);
	/*
	 * If on cylinder, no need to seek.
	 */
	if (cyltrk.dar_dar == idccyl[ui->ui_unit].dar_dar)
		goto done;
	/*
	 * RB80 can change heads (tracks) just by loading
	 * the disk address register, perform optimization
	 * here instead of doing a full seek.
	 */
	if (ui->ui_type && cyltrk.dar_cyl == idccyl[ui->ui_unit].dar_cyl) {
		idcaddr->idccsr = IDC_CRDY|IDC_IE|IDC_SEEK|(unit<<8);
		idcaddr->idcdar = cyltrk.dar_dar;
		idccyl[ui->ui_unit].dar_dar = cyltrk.dar_dar;
		goto done;
	}
	/*
	 * Need to do a full seek.  Select the unit, clear
	 * its attention bit, set the command, load the
	 * disk address register, and then go.
	 */
	idcaddr->idccsr =
	    IDC_CRDY|IDC_IE|IDC_SEEK|(unit<<8)|(1<<(unit+16));
	idcaddr->idcdar = cyltrk.dar_dar;
	idccyl[ui->ui_unit].dar_dar = cyltrk.dar_dar;
	printd("  seek");
	idcaddr->idccsr = IDC_IE|IDC_SEEK|(unit<<8);
	if (ui->ui_dk >= 0) {
		dk_busy |= 1<<ui->ui_dk;
		dk_seek[ui->ui_dk]++;
	}
	/*
	 * RB80's initiate seeks very quickly.  Wait for it
	 * to come ready rather than taking the interrupt.
	 */
	if (ui->ui_type) {
		if (idcwait(idcaddr, 10) == 0)
			return (1);
		idcaddr->idccsr &= ~IDC_ATTN;
		/* has the seek completed? */
		if (idcaddr->idccsr & IDC_DRDY) {
			printd(", drdy");
			idcaddr->idccsr =
			    IDC_CRDY|IDC_IE|IDC_SEEK|(unit<<8)|(1<<(unit+16));
			goto done;
		}
	}
	printd(", idccsr = 0x%x\n", idcaddr->idccsr);
	return (1);
done:
	if (dp->b_active != 2) {
D 8
		trace('!=2',dp->b_active);
E 8
I 8
		trace("!=2",dp->b_active);
E 8
		dp->b_forw = NULL;
		if (um->um_tab.b_actf == NULL)
			um->um_tab.b_actf = dp;
		else {
D 8
			trace('!NUL',um->um_tab.b_actl);
E 8
I 8
			trace("!NUL",um->um_tab.b_actl);
E 8
			um->um_tab.b_actl->b_forw = dp;
		}
		um->um_tab.b_actl = dp;
		dp->b_active = 2;
	}
	return (0);
}

idcstart(um)
	register struct uba_ctlr *um;
{
	register struct buf *bp, *dp;
	register struct uba_device *ui;
	register struct idcdevice *idcaddr;
	register struct idc_softc *sc;
	struct idcst *st;
	daddr_t bn;
	int sn, tn, cmd;

loop:
	if ((dp = um->um_tab.b_actf) == NULL) {
D 8
		trace('nodp',um);
E 8
I 8
		trace("nodp",um);
E 8
		return (0);
	}
	if ((bp = dp->b_actf) == NULL) {
D 8
		trace('nobp', dp);
E 8
I 8
		trace("nobp", dp);
E 8
		um->um_tab.b_actf = dp->b_forw;
		goto loop;
	}
	um->um_tab.b_active = 1;
D 24
	ui = idcdinfo[dkunit(bp)];
	bn = dkblock(bp);
E 24
I 24
	ui = idcdinfo[idcunit(bp->b_dev)];
	bn = bp->b_blkno;
E 24
D 8
	trace('star',bp);
E 8
I 8
	trace("star",bp);
E 8
	if (ui->ui_type == 0)
		bn *= 2;
	sc = &idc_softc;
	st = &idcst[ui->ui_type];
	sn = bn%st->nspc;
	tn = sn/st->nsect;
	sn %= st->nsect;
	sc->sc_sect = sn;
	sc->sc_trk = tn;
	sc->sc_cyl = bp->b_cylin;
	idcaddr = (struct idcdevice *)ui->ui_addr;
	printd("idcstart, unit %d, dar 0x%x", ui->ui_slave, sc->sc_dar);
	if (bp->b_flags & B_READ)
		cmd = IDC_IE|IDC_READ|(ui->ui_slave<<8);
	else
		cmd = IDC_IE|IDC_WRITE|(ui->ui_slave<<8);
	idcaddr->idccsr = IDC_CRDY|cmd;
	if ((idcaddr->idccsr&IDC_DRDY) == 0) {
D 24
		printf("rb%d: not ready\n", dkunit(bp));
E 24
I 24
		printf("rb%d: not ready\n", idcunit(bp->b_dev));
E 24
		um->um_tab.b_active = 0;
		um->um_tab.b_errcnt = 0;
		dp->b_actf = bp->av_forw;
		dp->b_active = 0;
		bp->b_flags |= B_ERROR;
		iodone(bp);
		goto loop;
	}
	idccyl[ui->ui_unit].dar_dar = sc->sc_dar;
	idccyl[ui->ui_unit].dar_sect = 0;
	sn = (st->nsect - sn) * st->nbps;
	if (sn > bp->b_bcount)
		sn = bp->b_bcount;
	sc->sc_bcnt = sn;
	sc->sc_resid = bp->b_bcount;
	sc->sc_unit = ui->ui_slave;
	printd(", bcr 0x%x, cmd 0x%x\n", sn, cmd);
	um->um_cmd = cmd;
	(void) ubago(ui);
	return (1);
}

idcdgo(um)
	register struct uba_ctlr *um;
{
	register struct idcdevice *idcaddr = (struct idcdevice *)um->um_addr;
	register struct idc_softc *sc = &idc_softc;

	/*
	 * VERY IMPORTANT: must load registers in this order.
	 */
D 34
	idcaddr->idcbar = sc->sc_ubaddr = um->um_ubinfo&0x3ffff;
E 34
I 34
	idcaddr->idcbar = sc->sc_ubaddr = UBAI_ADDR(um->um_ubinfo);
E 34
	idcaddr->idcbcr = -sc->sc_bcnt;
	idcaddr->idcdar = sc->sc_dar;
	printd("idcdgo, ubinfo 0x%x, cmd 0x%x\n", um->um_ubinfo, um->um_cmd);
	idcaddr->idccsr = um->um_cmd;
D 8
	trace('go', um);
E 8
I 8
	trace("go", um);
E 8
	um->um_tab.b_active = 2;
	/*** CLEAR SPURIOUS ATTN ON R80? ***/
}

idcintr(idc)
	int idc;
{
	register struct uba_ctlr *um = idcminfo[idc];
	register struct uba_device *ui;
	register struct idcdevice *idcaddr = (struct idcdevice *)um->um_addr;
	register struct idc_softc *sc = &idc_softc;
	register struct buf *bp, *dp;
	struct idcst *st;
	int unit, as, er, cmd, ds = 0;

	printd("idcintr, idccsr 0x%x", idcaddr->idccsr);
top:
	idcwticks = 0;
D 8
	trace('intr', um->um_tab.b_active);
E 8
I 8
	trace("intr", um->um_tab.b_active);
E 8
	if (um->um_tab.b_active == 2) {
		/*
		 * Process a data transfer complete interrupt.
		 */
		um->um_tab.b_active = 1;
		dp = um->um_tab.b_actf;
		bp = dp->b_actf;
D 24
		ui = idcdinfo[dkunit(bp)];
E 24
I 24
		ui = idcdinfo[idcunit(bp->b_dev)];
E 24
		unit = ui->ui_slave;
		st = &idcst[ui->ui_type];
		idcaddr->idccsr = IDC_IE|IDC_CRDY|(unit<<8);
		if ((er = idcaddr->idccsr) & IDC_ERR) {
			if (er & IDC_DE) {
				idcaddr->idcmpr = IDCGS_GETSTAT;
				idcaddr->idccsr = IDC_GETSTAT|(unit<<8);
D 9
				idcwait(idcaddr, 0);
E 9
I 9
				(void) idcwait(idcaddr, 0);
E 9
				ds = idcaddr->idcmpr;
				idcaddr->idccsr =
				    IDC_IE|IDC_CRDY|(1<<(unit+16));
			}
			printd(", er 0x%x, ds 0x%x", er, ds);
			if (ds & IDCDS_WL) {
D 24
				printf("rb%d: write locked\n", dkunit(bp));
E 24
I 24
				printf("rb%d: write locked\n",
					idcunit(bp->b_dev));
E 24
				bp->b_flags |= B_ERROR;
			} else if (++um->um_tab.b_errcnt > 28 || er&IDC_HARD) {
hard:
D 32
				harderr(bp, "rb");
				printf("csr=%b ds=%b\n", er, IDCCSR_BITS, ds, 
E 32
I 32
				diskerr(bp, "rb", "hard error", LOG_PRINTF, -1,
				    (struct disklabel *)0);
				printf(" csr=%b ds=%b\n", er, IDCCSR_BITS, ds, 
E 32
				    ui->ui_type?IDCRB80DS_BITS:IDCRB02DS_BITS);
				bp->b_flags |= B_ERROR;
			} else if (er & IDC_DCK) {
D 28
				switch (er & IDC_ECS) {
E 28
I 28
				switch ((int)(er & IDC_ECS)) {
E 28
				case IDC_ECS_NONE:
					break;
				case IDC_ECS_SOFT:
					idcecc(ui);
					break;
				case IDC_ECS_HARD:
				default:
					goto hard;
				}
			} else
				/* recoverable error, set up for retry */
				goto seek;
		}
		if ((sc->sc_resid -= sc->sc_bcnt) != 0) {
			sc->sc_ubaddr += sc->sc_bcnt;
			/*
			 * Current transfer is complete, have
			 * we overflowed to the next track?
			 */
			if ((sc->sc_sect += sc->sc_bcnt/st->nbps) == st->nsect) {
				sc->sc_sect = 0;
				if (++sc->sc_trk == st->ntrak) {
					sc->sc_trk = 0;
					sc->sc_cyl++;
				} else if (ui->ui_type) {
					/*
					 * RB80 can change heads just by
					 * loading the disk address register.
					 */
					idcaddr->idccsr = IDC_SEEK|IDC_CRDY|
					    IDC_IE|(unit<<8);
					printd(", change to track 0x%x", sc->sc_dar);
					idcaddr->idcdar = sc->sc_dar;
					idccyl[ui->ui_unit].dar_dar = sc->sc_dar;
					idccyl[ui->ui_unit].dar_sect = 0;
					goto cont;
				}
				/*
				 * Changing tracks on RB02 or cylinders
				 * on RB80, start a seek.
				 */
seek:
				cmd = IDC_IE|IDC_SEEK|(unit<<8);
				idcaddr->idccsr = cmd|IDC_CRDY;
				idcaddr->idcdar = sc->sc_dar;
				printd(", seek to 0x%x\n", sc->sc_dar);
				idccyl[ui->ui_unit].dar_dar = sc->sc_dar;
				idccyl[ui->ui_unit].dar_sect = 0;
				sc->sc_bcnt = 0;
				idcaddr->idccsr = cmd;
				if (ui->ui_type) {
					if (idcwait(idcaddr, 10) == 0)
						return;
					idcaddr->idccsr &= ~IDC_ATTN;
					if (idcaddr->idccsr & IDC_DRDY)
						goto top;
				}
			} else {
				/*
				 * Continue transfer on current track.
				 */
cont:
				sc->sc_bcnt = (st->nsect-sc->sc_sect)*st->nbps;
				if (sc->sc_bcnt > sc->sc_resid)
					sc->sc_bcnt = sc->sc_resid;
				if (bp->b_flags & B_READ)
					cmd = IDC_IE|IDC_READ|(unit<<8);
				else
					cmd = IDC_IE|IDC_WRITE|(unit<<8);
				idcaddr->idccsr = cmd|IDC_CRDY;
				idcaddr->idcbar = sc->sc_ubaddr;
				idcaddr->idcbcr = -sc->sc_bcnt;
				idcaddr->idcdar = sc->sc_dar;
				printd(", continue I/O 0x%x, 0x%x\n", sc->sc_dar, sc->sc_bcnt);
				idcaddr->idccsr = cmd;
				um->um_tab.b_active = 2;
			}
			return;
		}
		/*
		 * Entire transfer is done, clean up.
		 */
		ubadone(um);
		dk_busy &= ~(1 << ui->ui_dk);
		um->um_tab.b_active = 0;
		um->um_tab.b_errcnt = 0;
		um->um_tab.b_actf = dp->b_forw;
		dp->b_active = 0;
		dp->b_errcnt = 0;
		dp->b_actf = bp->av_forw;
D 8
		trace('done', dp); trace(um->um_tab.b_actf, dp->b_actf);
E 8
I 8
		trace("done", dp); trace(&um->um_tab.b_actf, dp->b_actf);
E 8
		bp->b_resid = sc->sc_resid;
		printd(", iodone, resid 0x%x\n", bp->b_resid);
		iodone(bp);
		if (dp->b_actf)
			if (idcustart(ui))
				return;
	} else if (um->um_tab.b_active == 1) {
		/*
		 * Got an interrupt while setting up for a command
		 * or doing a mid-transfer seek.  Save any attentions
		 * for later and process a mid-transfer seek complete.
		 */
		as = idcaddr->idccsr;
		idcaddr->idccsr = IDC_IE|IDC_CRDY|(as&IDC_ATTN);
		as = (as >> 16) & 0xf;
		unit = sc->sc_unit;
		sc->sc_softas |= as & ~(1<<unit);
		if (as & (1<<unit)) {
			printd(", seek1 complete");
			um->um_tab.b_active = 2;
			goto top;
		}
		printd(", as1 %o\n", as);
		return;
	}
	/*
	 * Process any seek initiated or complete interrupts.
	 */
	as = idcaddr->idccsr;
	idcaddr->idccsr = IDC_IE|IDC_CRDY|(as&IDC_ATTN);
	as = ((as >> 16) & 0xf) | sc->sc_softas;
	sc->sc_softas = 0;
D 8
	trace('as', as);
E 8
I 8
	trace("as", as);
E 8
	printd(", as %o", as);
	for (unit = 0; unit < NRB; unit++)
		if (as & (1<<unit)) {
			as &= ~(1<<unit);
			idcaddr->idccsr = IDC_IE|IDC_CRDY|(unit<<8);
			ui = idcdinfo[unit];
			if (ui) {
				printd(", attn unit %d", unit);
				if (idcaddr->idccsr & IDC_DRDY)
					if (idcustart(ui)) {
						sc->sc_softas = as;
						return;
					}
			} else {
				printd(", unsol. intr. unit %d", unit);
			}
		}
	printd("\n");
	if (um->um_tab.b_actf && um->um_tab.b_active == 0) {
D 8
		trace('stum',um->um_tab.b_actf);
E 8
I 8
		trace("stum",um->um_tab.b_actf);
E 8
D 9
		idcstart(um);
E 9
I 9
		(void) idcstart(um);
E 9
	}
}

D 8
idcwait(addr, cnt)
E 8
I 8
idcwait(addr, n)
E 8
	register struct idcdevice *addr;
D 8
	register int cnt;
E 8
I 8
	register int n;
E 8
{
	register int i;

D 8
	while (--cnt && (addr->idccsr & IDC_CRDY) == 0)
E 8
I 8
	while (--n && (addr->idccsr & IDC_CRDY) == 0)
E 8
		for (i = 10; i; i--)
			;
D 8
	return (cnt);
E 8
I 8
	return (n);
E 8
D 31
}

D 3
idcread(dev)
E 3
I 3
idcread(dev, uio)
E 3
	dev_t dev;
I 3
	struct uio *uio;
E 3
{
D 24
	register int unit = minor(dev) >> 3;
E 24
I 24
	register int unit = idcunit(dev);
E 24

	if (unit >= NRB)
D 5
		u.u_error = ENXIO;
	else
D 3
		physio(idcstrategy, &ridcbuf[unit], dev, B_READ, minphys);
E 3
I 3
		physio(idcstrategy, &ridcbuf[unit], dev, B_READ, minphys, uio);
E 5
I 5
		return (ENXIO);
	return (physio(idcstrategy, &ridcbuf[unit], dev, B_READ, minphys, uio));
E 5
E 3
}

D 4
idcwrite(dev)
E 4
I 4
idcwrite(dev, uio)
E 4
	dev_t dev;
I 4
	struct uio *uio;
E 4
{
D 24
	register int unit = minor(dev) >> 3;
E 24
I 24
	register int unit = idcunit(dev);
E 24

	if (unit >= NRB)
D 5
		u.u_error = ENXIO;
	else
D 3
		physio(idcstrategy, &ridcbuf[unit], dev, B_WRITE, minphys);
E 3
I 3
D 4
		physio(idcstrategy, &ridcbuf[unit], dev, B_WRITE, minphys, 0);
E 4
I 4
		physio(idcstrategy, &ridcbuf[unit], dev, B_WRITE, minphys, uio);
E 5
I 5
		return (ENXIO);
	return (physio(idcstrategy, &ridcbuf[unit], dev, B_WRITE, minphys, uio));
E 31
E 5
E 4
E 3
}

idcecc(ui)
	register struct uba_device *ui;
{
	register struct idcdevice *idc = (struct idcdevice *)ui->ui_addr;
	register struct buf *bp = idcutab[ui->ui_unit].b_actf;
	register struct uba_ctlr *um = ui->ui_mi;
D 33
	register struct idcst *st;
E 33
	register int i;
	struct uba_regs *ubp = ui->ui_hd->uh_uba;
	int bit, byte, mask;
	caddr_t addr;
	int reg, npf, o;
D 33
	int cn, tn, sn;
E 33

D 27
	printf("idcecc: HELP!\n");
E 27
	npf = btop(idc->idcbcr + idc_softc.sc_bcnt) - 1;;
	reg = btop(idc_softc.sc_ubaddr) + npf;
	o = (int)bp->b_un.b_addr & PGOFSET;
D 33
	st = &idcst[ui->ui_type];
	cn = idc_softc.sc_cyl;
	tn = idc_softc.sc_trk;
	sn = idc_softc.sc_sect;
E 33
	um->um_tab.b_active = 1;	/* Either complete or continuing... */
D 20
	printf("rb%d%c: soft ecc sn%d\n", dkunit(bp),
E 20
I 20
D 24
	log(KERN_RECOV, "rb%d%c: soft ecc sn%d\n", dkunit(bp),
E 24
I 24
D 26
	log(KERN_RECOV, "rb%d%c: soft ecc sn%d\n", idcunit(bp->b_dev),
E 26
I 26
D 32
	log(LOG_WARNING, "rb%d%c: soft ecc sn%d\n", idcunit(bp->b_dev),
E 26
E 24
E 20
	    'a'+(minor(bp->b_dev)&07),
	    (cn*st->ntrak + tn) * st->nsect + sn + npf);
E 32
I 32
	diskerr(bp, "rb", "soft ecc", LOG_WARNING, npf, (struct disklabel *)0);
	addlog("\n");
E 32
	mask = idc->idceccpat;
	i = idc->idceccpos - 1;		/* -1 makes 0 origin */
	bit = i&07;
	i = (i&~07)>>3;
	byte = i + o;
	while (i < 512 && (int)ptob(npf)+i < idc_softc.sc_bcnt && bit > -11) {
D 27
		addr = ptob(ubp->uba_map[reg+btop(byte)].pg_pfnum)+
E 27
I 27
		/*
		 * should be:
		 *	addr = ptob(ubp->uba_map[reg+btop(byte)].pg_pfnum)+
		 *		(byte & PGOFSET);
		 * but this generates an extzv which hangs the UNIBUS.
		 */
		addr = ptob(*(int *)&ubp->uba_map[reg+btop(byte)]&0x1fffff)+
E 27
		    (byte & PGOFSET);
		putmemc(addr, getmemc(addr)^(mask<<bit));
		byte++;
		i++;
		bit -= 8;
	}
	idc_softc.sc_bcnt += idc->idcbcr;
	um->um_tab.b_errcnt = 0;	/* error has been corrected */
	return;
}

idcreset(uban)
	int uban;
{
	register struct uba_ctlr *um;
	register struct uba_device *ui;
	register unit;

	if ((um = idcminfo[0]) == 0 || um->um_ubanum != uban ||
	    um->um_alive == 0)
		return;
	printf(" idc0");
	um->um_tab.b_active = 0;
	um->um_tab.b_actf = um->um_tab.b_actl = 0;
	if (um->um_ubinfo) {
		printf("<%d>", (um->um_ubinfo>>28)&0xf);
D 10
		ubadone(um);
E 10
I 10
		um->um_ubinfo = 0;
E 10
	}
	for (unit = 0; unit < NRB; unit++) {
		if ((ui = idcdinfo[unit]) == 0 || ui->ui_alive == 0)
			continue;
		idcutab[unit].b_active = 0;
		(void) idcustart(ui);
	}
	(void) idcstart(um);
}

idcwatch()
{
	register struct uba_ctlr *um;
	register unit;

	timeout(idcwatch, (caddr_t)0, hz);
	um = idcminfo[0];
	if (um == 0 || um->um_alive == 0)
		return;
	if (um->um_tab.b_active == 0) {
		for (unit = 0; unit < NRB; unit++)
			if (idcutab[unit].b_active)
				goto active;
		idcwticks = 0;
		return;
	}
active:
	idcwticks++;
	if (idcwticks >= 20) {
		idcwticks = 0;
		printf("idc0: lost interrupt\n");
		idcintr(0);
	}
}

I 8
/*ARGSUSED*/
E 8
idcdump(dev)
	dev_t dev;
{
D 14
#ifdef notdef
E 14
	struct idcdevice *idcaddr;
	char *start;
D 14
	int num, blk, unit, dbsize;
E 14
I 14
	int num, blk, unit;
E 14
	struct size *sizes;
	register struct uba_regs *uba;
	register struct uba_device *ui;
	struct idcst *st;
I 14
D 16
	struct idc_dar dar;
E 16
I 16
	union idc_dar dar;
E 16
	int nspg;
E 14

D 24
	unit = minor(dev) >> 3;
E 24
I 24
	unit = idcunit(dev);
E 24
	if (unit >= NRB)
		return (ENXIO);
#define	phys(cast, addr) ((cast)((int)addr & 0x7fffffff))
	ui = phys(struct uba_device *, idcdinfo[unit]);
	if (ui->ui_alive == 0)
		return (ENXIO);
	uba = phys(struct uba_hd *, ui->ui_hd)->uh_physuba;
	ubainit(uba);
	idcaddr = (struct idcdevice *)ui->ui_physaddr;
D 14
	num = maxfree;
	start = 0;
/***
	idcaddr->idccs1 = IDC_CCLR;
	idcaddr->idccs2 = unit;
	idcaddr->idccs1 = idctypes[ui->ui_type]|IDC_DCLR|IDC_GO;
D 9
	idcwait(idcaddr);
E 9
I 9
	(void) idcwait(idcaddr);
E 9
	dbsize = 20 or 31;
***/
	st = &idcst[ui->ui_type];
E 14
I 14
	if (idcwait(idcaddr, 100) == 0)
		return (EFAULT);
	/*
	 * Since we can only transfer one track at a time, and
	 * the rl02 has 256 byte sectors, all the calculations
	 * are done in terms of physical sectors (i.e. num and blk
	 * are in sectors not NBPG blocks.
	 */
	st = phys(struct idcst *, &idcst[ui->ui_type]);
E 14
	sizes = phys(struct size *, st->sizes);
D 14
	if (dumplo < 0 || dumplo + num >= sizes[minor(dev)&07].nblocks)
E 14
I 14
D 23
	if (dumplo < 0 || dumplo + maxfree >= sizes[minor(dev)&07].nblocks)
E 23
I 23
	if (dumplo < 0)
E 23
E 14
		return (EINVAL);
I 23
	if (dumplo + maxfree >= sizes[minor(dev)&07].nblocks)
		num = sizes[minor(dev)&07].nblocks - dumplo;
E 23
I 14
	nspg = NBPG / st->nbps;
D 23
	num = maxfree * nspg;
E 23
I 23
	num = num * nspg;
E 23
	start = 0;

E 14
	while (num > 0) {
		register struct pte *io;
		register int i;
D 14
		int cn, sn, tn;
E 14
		daddr_t bn;

D 14
		blk = num > dbsize ? dbsize : num;
E 14
I 14
		bn = (dumplo + btop(start)) * nspg;
		dar.dar_cyl = bn / st->nspc + sizes[minor(dev)&07].cyloff;
		bn %= st->nspc;
		dar.dar_trk = bn / st->nsect;
		dar.dar_sect = bn % st->nsect;
		blk = st->nsect - dar.dar_sect;
		if (num < blk)
			blk = num;

E 14
		io = uba->uba_map;
D 14
		for (i = 0; i < blk; i++)
E 14
I 14
		for (i = 0; i < (blk + nspg - 1) / nspg; i++)
E 14
			*(int *)io++ = (btop(start)+i) | (1<<21) | UBAMR_MRV;
		*(int *)io = 0;
D 14
		bn = dumplo + btop(start);
		cn = bn/st->nspc + sizes[minor(dev)&07].cyloff;
		sn = bn%st->nspc;
		tn = sn/st->nsect;
		sn = sn%st->nsect;
/***
		idcaddr->idccyl = cn;
		rp = (short *) &idcaddr->idcda;
		*rp = (tn << 8) + sn;
		*--rp = 0;
		*--rp = -blk*NBPG / sizeof (short);
		*--rp = idctypes[ui->ui_type]|IDC_GO|IDC_WRITE;
D 9
		idcwait(idcaddr);
E 9
I 9
		(void) idcwait(idcaddr);
E 9
***/
		if (idcaddr->idccsr & IDC_ERR)
E 14
I 14

		idcaddr->idccsr = IDC_CRDY | IDC_SEEK | unit<<8;
		if ((idcaddr->idccsr&IDC_DRDY) == 0)
			return (EFAULT);
		idcaddr->idcdar = dar.dar_dar;
		idcaddr->idccsr = IDC_SEEK | unit << 8;
		while ((idcaddr->idccsr & (IDC_CRDY|IDC_DRDY))
			!= (IDC_CRDY|IDC_DRDY))
			;
		if (idcaddr->idccsr & IDC_ERR) {
			printf("rb%d: seek, csr=%b\n",
				unit, idcaddr->idccsr, IDCCSR_BITS);
E 14
			return (EIO);
D 14
		start += blk*NBPG;
E 14
I 14
		}

		idcaddr->idccsr = IDC_CRDY | IDC_WRITE | unit<<8;
		if ((idcaddr->idccsr&IDC_DRDY) == 0)
			return (EFAULT);
		idcaddr->idcbar = 0;			/* start addr 0 */
		idcaddr->idcbcr = - (blk * st->nbps);
		idcaddr->idcdar = dar.dar_dar;
		idcaddr->idccsr = IDC_WRITE | unit << 8;
		while ((idcaddr->idccsr & (IDC_CRDY|IDC_DRDY))
			!= (IDC_CRDY|IDC_DRDY))
			;
		if (idcaddr->idccsr & IDC_ERR) {
			printf("rb%d: write, csr=%b\n",
				unit, idcaddr->idccsr, IDCCSR_BITS);
			return (EIO);
		}

		start += blk * st->nbps;
E 14
		num -= blk;
	}
	return (0);
D 14
#else
	return (ENXIO);
#endif
E 14
}
I 15
 
idcsize(dev)
	dev_t dev;
{
D 24
	int unit = minor(dev) >> 3;
E 24
I 24
	int unit = idcunit(dev);
E 24
	struct uba_device *ui;
	struct idcst *st;

	if (unit >= NRB || (ui = idcdinfo[unit]) == 0 || ui->ui_alive == 0)
		return (-1);
	st = &idcst[ui->ui_type];
	return (st->sizes[minor(dev) & 07].nblocks);
}
E 15
#endif
E 1
