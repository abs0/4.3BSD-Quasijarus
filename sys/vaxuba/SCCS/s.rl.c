h50821
s 00001/00001/00671
d D 7.6 88/10/22 15:14:04 karels 18 17
c use ubaalloc macros; use qbgetpri for Q-bus device probe routines
e
s 00001/00000/00671
d D 7.5 88/05/27 17:33:00 karels 17 16
c re-lint
e
s 00005/00002/00666
d D 7.4 88/05/27 16:10:34 karels 16 15
c new diskerr routine
e
s 00000/00024/00668
d D 7.3 88/05/06 17:17:10 bostic 15 14
c changes for raw{read,write} stuff
e
s 00001/00001/00691
d D 7.2 87/01/14 08:47:59 karels 14 13
c rename dk.h to dkstat.h
e
s 00001/00001/00691
d D 7.1 86/06/05 01:15:28 mckusick 13 12
c 4.3BSD release version
e
s 00001/00001/00691
d D 6.7 86/02/23 23:17:45 karels 12 11
c lint
e
s 00003/00001/00689
d D 6.6 85/09/16 22:09:46 karels 11 10
c off by one, and need resid
e
s 00024/00017/00666
d D 6.5 85/09/14 17:20:10 bloom 10 9
c get rid of interleave code, add macro to get unit number, add error return
c codes to strategy, reading last block after end of partition returns size = 0
e
s 00007/00001/00676
d D 6.4 85/06/08 14:20:11 mckusick 9 8
c Add copyright
e
s 00005/00003/00672
d D 6.3 84/11/27 15:28:49 karels 8 7
c add missing E partition; 0-terminate rlstd array; correct slave code
c to find drives that aren't spun up (per spm@mit-athena)
e
s 00016/00016/00659
d D 6.2 84/08/29 20:09:34 bloom 7 6
c Change to includes.  No more ../h
e
s 00000/00000/00675
d D 6.1 83/07/29 07:28:37 sam 6 5
c 4.2 distribution
e
s 00011/00000/00664
d D 4.5 83/06/24 15:01:23 sam 5 4
c need sizes routine for swapping
e
s 00085/00169/00579
d D 4.4 83/06/13 23:01:22 sam 4 3
c lint
e
s 00014/00000/00734
d D 4.3 83/05/18 02:21:14 sam 3 2
c add entry point for swap partition sizing at boot time
e
s 00029/00017/00705
d D 4.2 83/05/14 20:25:15 sam 2 1
c uio'd; changes for ubareset working; add open routine
e
s 00722/00000/00000
d D 4.1 83/02/08 23:11:47 sam 1 0
c date and time created 83/02/08 23:11:47 by sam
e
u
U
t
T
I 1
D 9
/*	%M%	%I%	%E%	*/
E 9
I 9
/*
D 13
 * Copyright (c) 1982 Regents of the University of California.
E 13
I 13
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 13
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 9

#include "rl.h"
D 2
#if NHL > 0
E 2
I 2
#if NRL > 0
E 2
/*
 * UNIBUS RL02 disk driver
D 4
 * (not yet converted to 4.1c)
E 4
 */
I 4
#include "../machine/pte.h"
E 4

D 7
#include "../h/param.h"
#include "../h/systm.h"
D 4
#include "../h/cpu.h"
#include "../h/nexus.h"
E 4
#include "../h/dk.h"
I 4
#include "../h/dkbad.h"
E 4
#include "../h/buf.h"
#include "../h/conf.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/map.h"
D 4
#include "../h/pte.h"
#include "../h/mtpr.h"
E 4
#include "../h/vm.h"
D 4
#include "../h/ubavar.h"
#include "../h/ubareg.h"
E 4
#include "../h/cmap.h"
I 4
#include "../h/uio.h"
#include "../h/kernel.h"
E 7
I 7
#include "param.h"
#include "systm.h"
D 14
#include "dk.h"
E 14
I 14
#include "dkstat.h"
E 14
#include "dkbad.h"
I 16
#include "ioctl.h"
#include "disklabel.h"
E 16
#include "buf.h"
#include "conf.h"
#include "dir.h"
#include "user.h"
#include "map.h"
#include "vm.h"
#include "cmap.h"
#include "uio.h"
#include "kernel.h"
I 17
#include "syslog.h"
E 17
E 7
E 4

D 4
#include "../h/rlreg.h"
E 4
I 4
#include "../vax/cpu.h"
#include "../vax/nexus.h"
D 7
#include "../vaxuba/ubavar.h"
#include "../vaxuba/ubareg.h"
#include "../vaxuba/rlreg.h"
E 7
I 7
#include "ubavar.h"
#include "ubareg.h"
#include "rlreg.h"
E 7
E 4

/* Pending Controller items and statistics */
struct	rl_softc {
	int	rl_softas;	/* Attention sumary, (seeks pending) */
	int	rl_ndrive;	/* Number of drives on controller */
	int	rl_wticks;	/* Monitor time for function */
} rl_softc[NHL];

/* 
D 4
 * this struct is used to keep the state of the controller for the last
 * transfer done.  Since only one transfer can be done at a time per
E 4
I 4
 * State of controller from last transfer.
 * Since only one transfer can be done at a time per
E 4
 * controller, only allocate one for each controller.
 */
struct	rl_stat {
	short	rl_cyl[4];	/* Current cylinder for each drive */
	short	rl_dn;		/* drive number currently transferring */
	short	rl_cylnhd;	/* current cylinder and head of transfer */
	u_short	rl_bleft;	/* bytes left to transfer */
	u_short	rl_bpart;	/* bytes transferred */
} rl_stat[NHL];

I 10
#define rlunit(dev)	(minor(dev) >> 3)

E 10
/* THIS SHOULD BE READ OFF THE PACK, PER DRIVE */
I 4
/* Last cylinder not used. Saved for Bad Sector File */
E 4
struct	size {
	daddr_t	nblocks;
	int	cyloff;
} rl02_sizes[8] = {
D 4
	14440,  	0,		/* A=cyl   0 thru 360 */
	 6040,        361,		/* B=cyl 361 thru 511 */
	20480,	        0,		/* C=cyl   0 thru 511 */
	    0,          0,		/* D= Not Defined     */
	    0,          0,		/* E= Not Defined     */
E 4
I 4
	15884,		0,		/* A=cyl   0 thru 397 */
	 4520,		398,		/* B=cyl 398 thru 510 */
	   -1,		0,		/* C=cyl   0 thru 511 */
	 4520,		398,		/* D=cyl 398 thru 510 */
I 8
	    0,          0,		/* E= Not Defined     */
E 8
E 4
	    0,          0,		/* F= Not Defined     */
D 4
	    0,          0,		/* G= Not Defined     */
E 4
I 4
	20440,	        0,		/* G=cyl   0 thru 510 */
E 4
	    0,          0,		/* H= Not Defined     */
};
/* END OF STUFF WHICH SHOULD BE READ IN PER DISK */

int	rlprobe(), rlslave(), rlattach(), rldgo(), rlintr();
struct	uba_ctlr	*rlminfo[NHL];
struct	uba_device	*rldinfo[NRL];
struct	uba_device	*rlip[NHL][4];

/* RL02 driver structure */
D 8
u_short	rlstd[] = { 0174400 };
E 8
I 8
u_short	rlstd[] = { 0174400, 0 };
E 8
struct	uba_driver hldriver =
    { rlprobe, rlslave, rlattach, rldgo, rlstd, "rl", rldinfo, "hl", rlminfo };

/* User table per controller */
struct	buf	rlutab[NRL];

/* RL02 drive structure */
struct	RL02 {
	short	nbpt;		/* Number of 512 byte blocks/track */
	short	ntrak;
	short	nbpc;		/* Number of 512 byte blocks/cylinder */
	short	ncyl;
	short	btrak;		/* Number of bytes/track */
	struct	size *sizes;
} rl02 = {
	20,	2,	40,	512,	20*512,	rl02_sizes /* rl02/DEC*/
};

D 15
struct	buf	rrlbuf[NRL];

E 15
#define	b_cylin b_resid		/* Last seek as CYL<<1 | HD */

D 10
#ifdef INTRLVE
daddr_t dkblock();
#endif

E 10
int	rlwstart, rlwatch();		/* Have started guardian */

/* Check that controller exists */
/*ARGSUSED*/
rlprobe(reg)
	caddr_t reg;
{
	register int br, cvec;

#ifdef lint	
	br = 0; cvec = br; br = cvec;
I 4
	rlintr(0);
E 4
#endif
D 4
	((struct rldevice *)reg)->rlcs = RL_IE | RL_NOOP;  /* Enable intrpt */
	DELAY(10);	/* Ensure interrupt takes place (10 microsec ) */
	((struct rldevice *)reg)->rlcs &= ~RL_IE;  /* Disable intrpt */
E 4
I 4
	((struct rldevice *)reg)->rlcs = RL_IE | RL_NOOP;
	DELAY(10);
	((struct rldevice *)reg)->rlcs &= ~RL_IE;
E 4
D 2
	return (1);
E 2
I 2
	return (sizeof (struct rldevice));
E 2
}

D 4
/* Check that drive exists and is functional*/
E 4
rlslave(ui, reg)
	struct uba_device *ui;
	caddr_t reg;
{
	register struct rldevice *rladdr = (struct rldevice *)reg;
	short ctr = 0;

	/*
	 * DEC reports that:
	 * For some unknown reason the RL02 (seems to be only drive 1)
	 * does not return a valid drive status the first time that a
	 * GET STATUS request is issued for the drive, in fact it can
	 * take up to three or more GET STATUS requests to obtain the
	 * correct status.
	 * In order to overcome this, the driver has been modified to
	 * issue a GET STATUS request and validate the drive status
	 * returned.  If a valid status is not returned after eight
	 * attempts, then an error message is printed.
	 */
	do {
		rladdr->rlda.getstat = RL_RESET;
		rladdr->rlcs = (ui->ui_slave <<8) | RL_GETSTAT; /* Get status*/
		rlwait(rladdr);
D 4
	} while( (rladdr->rlmp.getstat&RLMP_STATUS) != RLMP_STATOK && ++ctr<8 );


E 4
I 4
D 8
	} while ((rladdr->rlmp.getstat&RLMP_STATUS) != RLMP_STATOK && ++ctr<8);
E 8
I 8
	} while ((rladdr->rlcs & (RL_CRDY|RL_ERR)) != RL_CRDY && ++ctr < 8);

E 8
E 4
	if ((rladdr->rlcs & RL_DE) || (ctr >= 8))
D 4
		return (0);			 /* Error return */
	if ((rladdr->rlmp.getstat & RLMP_DT) == 0 ) {	/* NO RL01'S */
		printf("rl01 drives not supported (drive %d)\n", ui->ui_slave );
E 4
I 4
D 8
		return (0);
E 8
I 8
		return (0); 
E 8
	if ((rladdr->rlmp.getstat & RLMP_DT) == 0 ) {
		printf("rl%d: rl01's not supported\n", ui->ui_slave);
E 4
		return(0);
	}
	return (1);
}

D 4
/* Initialize controller */
E 4
rlattach(ui)
	register struct uba_device *ui;
{
	register struct rldevice *rladdr;

	if (rlwstart == 0) {
D 4
		timeout(rlwatch, (caddr_t)0, hz);   /* Watch for lost intr */
E 4
I 4
		timeout(rlwatch, (caddr_t)0, hz);
E 4
		rlwstart++;
	}
	/* Initialize iostat values */
	if (ui->ui_dk >= 0)
		dk_mspw[ui->ui_dk] = .000003906;   /* 16bit transfer time? */
	rlip[ui->ui_ctlr][ui->ui_slave] = ui;
D 4
	rl_softc[ui->ui_ctlr].rl_ndrive++;	   /* increment device/ctrl */
E 4
I 4
	rl_softc[ui->ui_ctlr].rl_ndrive++;
E 4
	rladdr = (struct rldevice *)ui->ui_addr;
D 4

E 4
	/* reset controller */
	rladdr->rlda.getstat = RL_RESET;	/* SHOULD BE REPEATED? */
	rladdr->rlcs = (ui->ui_slave << 8) | RL_GETSTAT; /* Reset DE bit */
	rlwait(rladdr);
D 4

	/* Determine disk posistion */
E 4
I 4
	/* determine disk posistion */
E 4
	rladdr->rlcs = (ui->ui_slave << 8) | RL_RHDR;
	rlwait(rladdr);
D 4

E 4
	/* save disk drive posistion */
	rl_stat[ui->ui_ctlr].rl_cyl[ui->ui_slave] =
D 4
		(rladdr->rlmp.readhdr & 0177700) >> 6;
E 4
I 4
	     (rladdr->rlmp.readhdr & 0177700) >> 6;
E 4
	rl_stat[ui->ui_ctlr].rl_dn = -1;
}
 
I 2
rlopen(dev)
	dev_t dev;
{
D 10
	register int unit = minor(dev) >> 3;
E 10
I 10
	register int unit = rlunit(dev);
E 10
D 4
	register struct uba_device *mi;
E 4
I 4
	register struct uba_device *ui;
E 4

	if (unit >= NRL || (ui = rldinfo[unit]) == 0 || ui->ui_alive == 0)
		return (ENXIO);
	return (0);
}

E 2
rlstrategy(bp)
	register struct buf *bp;
{
	register struct uba_device *ui;
	register int drive;
	register struct buf *dp;
D 4
	int partition = minor(bp->b_dev) & 07;
E 4
I 4
	int partition = minor(bp->b_dev) & 07, s;
E 4
	long bn, sz;

D 4
	sz = (bp->b_bcount+511) >> 9;	/* Blocks to transfer */

	drive = dkunit(bp);		/* Drive number */
E 4
I 4
	sz = (bp->b_bcount+511) >> 9;
D 10
	drive = dkunit(bp);
E 4
	if (drive >= NRL)
E 10
I 10
	drive = rlunit(bp->b_dev);
	if (drive >= NRL) {
		bp->b_error = ENXIO;
E 10
		goto bad;
I 10
	}
E 10
D 4
	ui = rldinfo[drive];		/* Controller uba_device */
E 4
I 4
	ui = rldinfo[drive];
E 4
D 10
	if (ui == 0 || ui->ui_alive == 0)
E 10
I 10
	if (ui == 0 || ui->ui_alive == 0) {
		bp->b_error = ENXIO;
E 10
		goto bad;
I 10
	}
E 10
	if (bp->b_blkno < 0 ||
D 10
	    (bn = dkblock(bp))+sz > rl02.sizes[partition].nblocks)
E 10
I 10
	    (bn = bp->b_blkno)+sz > rl02.sizes[partition].nblocks) {
D 11
		if (bp->b_blkno == rl02.sizes[partition].nblocks + 1)
E 11
I 11
		if (bp->b_blkno == rl02.sizes[partition].nblocks) {
		    bp->b_resid = bp->b_bcount;
E 11
		    goto done;
I 11
		}
E 11
		bp->b_error = EINVAL;
E 10
		goto bad;
I 10
	}
E 10
D 4

E 4
	/* bn is in 512 byte block size */
	bp->b_cylin = bn/rl02.nbpc + rl02.sizes[partition].cyloff;
D 4
	(void) spl5();
E 4
I 4
	s = spl5();
E 4
	dp = &rlutab[ui->ui_unit];
	disksort(dp, bp);
	if (dp->b_active == 0) {
D 4
		(void) rlustart(ui);
E 4
I 4
		rlustart(ui);
E 4
		bp = &ui->ui_mi->um_tab;
		if (bp->b_actf && bp->b_active == 0)
D 4
			(void) rlstart(ui->ui_mi);
E 4
I 4
			rlstart(ui->ui_mi);
E 4
	}
D 4
	(void) spl0();
E 4
I 4
	splx(s);
E 4
	return;

bad:
	bp->b_flags |= B_ERROR;
I 10
done:
E 10
	iodone(bp);
	return;
}

/*
 * Unit start routine.
 * Seek the drive to be where the data is
 * and then generate another interrupt
 * to actually start the transfer.
 */
rlustart(ui)
	register struct uba_device *ui;
{
	register struct buf *bp, *dp;
	register struct uba_ctlr *um;
	register struct rldevice *rladdr;
	daddr_t bn;
D 4
	short cyl, sn, hd, diff;
E 4
I 4
	short hd, diff;
E 4

	if (ui == 0)
D 4
		return (0);
E 4
I 4
		return;
E 4
	um = ui->ui_mi;
D 4
	dk_busy &= ~(1<<ui->ui_dk);	/* Kernel define, drives busy */
E 4
I 4
	dk_busy &= ~(1 << ui->ui_dk);
E 4
	dp = &rlutab[ui->ui_unit];
	if ((bp = dp->b_actf) == NULL)
D 4
		goto out;
E 4
I 4
		return;
E 4
	/*
	 * If the controller is active, just remember
	 * that this device has to be positioned...
	 */
	if (um->um_tab.b_active) {
		rl_softc[um->um_ctlr].rl_softas |=  1<<ui->ui_slave;
D 4
		return (0);
E 4
I 4
		return;
E 4
	}
	/*
	 * If we have already positioned this drive,
	 * then just put it on the ready queue.
	 */
	if (dp->b_active)
		goto done;
D 4
	dp->b_active = 1;	/* Posistioning drive */
E 4
I 4
	dp->b_active = 1;	/* positioning drive */
E 4
	rladdr = (struct rldevice *)um->um_addr;

	/*
	 * Figure out where this transfer is going to
	 * and see if we are seeked correctly.
	 */
D 10
	bn = dkblock(bp);		/* Block # desired */
E 10
I 10
	bn = bp->b_blkno;		/* Block # desired */
E 10
	/*
D 4
	 * these next two look funky... but we need to map
	 * 512 byte logical disk blocks to 256 byte sectors.
	 * (rl02's are stupid).
E 4
I 4
	 * Map 512 byte logical disk blocks
	 * to 256 byte sectors (rl02's are stupid).
E 4
	 */
D 4
	sn = (bn % rl02.nbpt) << 1;	/* Sector # desired */
E 4
	hd = (bn / rl02.nbpt) & 1;	/* Get head required */
D 4

E 4
	diff = (rl_stat[um->um_ctlr].rl_cyl[ui->ui_slave] >> 1) - bp->b_cylin;
	if ( diff == 0 && (rl_stat[um->um_ctlr].rl_cyl[ui->ui_slave] & 1) == hd)
		goto done;		/* on cylinder and head */
D 4

search:
E 4
	/*
	 * Not at correct position.
	 */
D 4

E 4
	rl_stat[um->um_ctlr].rl_cyl[ui->ui_slave] = (bp->b_cylin << 1) | hd;
D 4

E 4
	if (diff < 0)
		rladdr->rlda.seek = -diff << 7 | RLDA_HGH | hd << 4;
	else
		rladdr->rlda.seek = diff << 7 | RLDA_LOW | hd << 4;
	rladdr->rlcs = (ui->ui_slave << 8) | RL_SEEK;

	/*
	 * Mark unit busy for iostat.
	 */
	if (ui->ui_dk >= 0) {
		dk_busy |= 1<<ui->ui_dk;
		dk_seek[ui->ui_dk]++;
	}
D 2
	rlwait( rladdr );
E 2
I 2
	rlwait(rladdr);
E 2
D 4

	/*
	 * fall through since we are now at the correct cylinder
	 */
E 4
done:
	/*
	 * Device is ready to go.
	 * Put it on the ready queue for the controller
	 * (unless its already there.)
	 */
	if (dp->b_active != 2) {
		dp->b_forw = NULL;
		if (um->um_tab.b_actf == NULL)
			um->um_tab.b_actf = dp;
		else
			um->um_tab.b_actl->b_forw = dp;
		um->um_tab.b_actl = dp;
		dp->b_active = 2;	/* Request on ready queue */
	}
D 4
out:
	return (0);
E 4
}

/*
 * Start up a transfer on a drive.
 */
rlstart(um)
	register struct uba_ctlr *um;
{
	register struct buf *bp, *dp;
	register struct uba_device *ui;
	register struct rldevice *rladdr;
	register struct rl_stat *st = &rl_stat[um->um_ctlr];
	daddr_t bn;
	short sn, cyl, cmd;

loop:
D 4
	/*
	 * Pull a request off the controller queue
	 */
E 4
	if ((dp = um->um_tab.b_actf) == NULL) {
		st->rl_dn = -1;
		st->rl_cylnhd = 0;
		st->rl_bleft = 0;
		st->rl_bpart = 0;
D 4
		return (0);
E 4
I 4
		return;
E 4
	}
	if ((bp = dp->b_actf) == NULL) {
		um->um_tab.b_actf = dp->b_forw;
		goto loop;
	}
	/*
	 * Mark controller busy, and
D 4
	 * determine destinationst.
E 4
I 4
	 * determine destination.
E 4
	 */
	um->um_tab.b_active++;
D 10
	ui = rldinfo[dkunit(bp)];		/* Controller */
	bn = dkblock(bp);			/* 512 byte Block number */
E 10
I 10
	ui = rldinfo[rlunit(bp->b_dev)];	/* Controller */
	bn = bp->b_blkno;			/* 512 byte Block number */
E 10
	cyl = bp->b_cylin << 1;			/* Cylinder */
	cyl |= (bn / rl02.nbpt) & 1;		/* Get head required */
	sn = (bn % rl02.nbpt) << 1;		/* Sector number */
	rladdr = (struct rldevice *)ui->ui_addr;
D 4

	/*
	 * Check that controller is ready
	 */
E 4
D 2
	rlwait( rladdr );
E 2
I 2
	rlwait(rladdr);
E 2
D 4

	/*
	 * Setup for the transfer, and get in the
	 * UNIBUS adaptor queue.
	 */
E 4
	rladdr->rlda.rw = cyl<<6 | sn;
D 4

E 4
	/* save away current transfers drive status */
	st->rl_dn = ui->ui_slave;
	st->rl_cylnhd = cyl;
	st->rl_bleft = bp->b_bcount;
	st->rl_bpart = rl02.btrak - (sn * NRLBPSC);
D 4

	/* RL02 must seek between cylinders and between tracks */
	/* Determine maximum data transfer at this time */
	if( st->rl_bleft < st->rl_bpart)
E 4
I 4
	/*
	 * RL02 must seek between cylinders and between tracks,
	 * determine maximum data transfer at this time.
	 */
	if (st->rl_bleft < st->rl_bpart)
E 4
		st->rl_bpart = st->rl_bleft;
D 4

E 4
	rladdr->rlmp.rw = -(st->rl_bpart >> 1);
	if (bp->b_flags & B_READ)
		cmd = RL_IE | RL_READ | (ui->ui_slave << 8);
	else
		cmd = RL_IE | RL_WRITE | (ui->ui_slave << 8);
	um->um_cmd = cmd;
	(void) ubago(ui);
D 4
	return (1);
E 4
}

D 4
/*
 * Now all ready to go, stuff the registers.
 */
E 4
rldgo(um)
	register struct uba_ctlr *um;
{
	register struct rldevice *rladdr = (struct rldevice *)um->um_addr;

D 4

	/* Place in unibus address for transfer (lower 18 bits of um_ubinfo) */
	/* Then execute instruction */
E 4
	rladdr->rlba = um->um_ubinfo;
	rladdr->rlcs = um->um_cmd|((um->um_ubinfo>>12)&RL_BAE);
}

/*
 * Handle a disk interrupt.
 */
rlintr(rl21)
	register rl21;
{
	register struct buf *bp, *dp;
	register struct uba_ctlr *um = rlminfo[rl21];
	register struct uba_device *ui;
	register struct rldevice *rladdr = (struct rldevice *)um->um_addr;
	register unit;
	struct rl_softc *rl = &rl_softc[um->um_ctlr];
	struct rl_stat *st = &rl_stat[um->um_ctlr];
D 4
	int as = rl->rl_softas;
	int needie = 1, waitdry, status;
E 4
I 4
	int as = rl->rl_softas, status;
E 4

	rl->rl_wticks = 0;
	rl->rl_softas = 0;
D 4

	/*
	 * Get device and block structures, and a pointer
	 * to the uba_device for the drive.
	 */
E 4
	dp = um->um_tab.b_actf;
	bp = dp->b_actf;
D 10
	ui = rldinfo[dkunit(bp)];
E 10
I 10
	ui = rldinfo[rlunit(bp->b_dev)];
E 10
D 4
	dk_busy &= ~(1 << ui->ui_dk);	/* Clear busy bit */
E 4
I 4
	dk_busy &= ~(1 << ui->ui_dk);
E 4

	/*
	 * Check for and process errors on
	 * either the drive or the controller.
	 */
	if (rladdr->rlcs & RL_ERR) {
		u_short err;
D 4
		rlwait( rladdr );

E 4
I 4
		rlwait(rladdr);
E 4
		err = rladdr->rlcs;
D 4

E 4
		/* get staus and reset controller */
		rladdr->rlda.getstat = RL_GSTAT;
		rladdr->rlcs = (ui->ui_slave << 8) | RL_GETSTAT;
		rlwait(rladdr);
		status = rladdr->rlmp.getstat;
D 4

E 4
		/* reset drive */
		rladdr->rlda.getstat = RL_RESET;
		rladdr->rlcs = (ui->ui_slave <<8) | RL_GETSTAT; /* Get status*/
		rlwait(rladdr);
D 4

		if ( (status & RLMP_WL) == RLMP_WL ) {
E 4
I 4
		if ((status & RLMP_WL) == RLMP_WL) {
E 4
			/*
			 * Give up on write protected devices
			 * immediately.
			 */
D 10
			printf("rl%d: write protected\n", dkunit(bp));
E 10
I 10
			printf("rl%d: write protected\n", rlunit(bp->b_dev));
E 10
			bp->b_flags |= B_ERROR;
		} else if (++um->um_tab.b_errcnt > 10) {
			/*
			 * After 10 retries give up.
			 */
D 16
			harderr(bp, "rl");
D 4
			printf("cs=%b mp=%b\n",
				err, RLCS_BITS, status, RLER_BITS);

E 4
I 4
			printf("cs=%b mp=%b\n", err, RLCS_BITS,
E 16
I 16
			diskerr(bp, "rl", "hard error", LOG_PRINTF, -1,
			    (struct disklabel *)0);
			printf(" cs=%b mp=%b\n", err, RLCS_BITS,
E 16
			    status, RLER_BITS);
E 4
			bp->b_flags |= B_ERROR;
		} else
			um->um_tab.b_active = 0;	 /* force retry */
D 4

		/* Determine disk posistion */
E 4
I 4
		/* determine disk position */
E 4
		rladdr->rlcs = (ui->ui_slave << 8) | RL_RHDR;
		rlwait(rladdr);
D 4

		/* save disk drive posistion */
		st->rl_cyl[ui->ui_slave] = (rladdr->rlmp.readhdr & 0177700) >> 6;
E 4
I 4
		/* save disk drive position */
		st->rl_cyl[ui->ui_slave] =
		    (rladdr->rlmp.readhdr & 0177700) >> 6;
E 4
	}
D 4

E 4
	/*
	 * If still ``active'', then don't need any more retries.
	 */
	if (um->um_tab.b_active) {
		/* RL02 check if more data from previous request */
D 4
		if ( (bp->b_flags & B_ERROR) == 0 &&
		     (st->rl_bleft -= st->rl_bpart) > 0 ) {
E 4
I 4
		if ((bp->b_flags & B_ERROR) == 0 &&
		     (int)(st->rl_bleft -= st->rl_bpart) > 0) {
E 4
			/*
D 4
			 * the following code was modeled from the rk07
E 4
I 4
			 * The following code was modeled from the rk07
E 4
			 * driver when an ECC error occured.  It has to
			 * fix the bits then restart the transfer which is
			 * what we have to do (restart transfer).
			 */
			int reg, npf, o, cmd, ubaddr, diff, head;

D 4

E 4
			/* seek to next head/track */
D 4

E 4
			/* increment head and/or cylinder */
			st->rl_cylnhd++;
			diff = (st->rl_cyl[ui->ui_slave] >> 1) -
				(st->rl_cylnhd >> 1);
			st->rl_cyl[ui->ui_slave] = st->rl_cylnhd;
			head = st->rl_cylnhd & 1;
D 4
			rlwait( rladdr );

			if ( diff < 0 )
				rladdr->rlda.seek = -diff << 7 | RLDA_HGH | head << 4;
E 4
I 4
			rlwait(rladdr);
			if (diff < 0)
				rladdr->rlda.seek =
				    -diff << 7 | RLDA_HGH | head << 4;
E 4
			else
D 4
				rladdr->rlda.seek = diff << 7 | RLDA_LOW | head << 4;
E 4
I 4
				rladdr->rlda.seek =
				    diff << 7 | RLDA_LOW | head << 4;
E 4
			rladdr->rlcs = (ui->ui_slave << 8) | RL_SEEK;
D 4

E 4
			npf = btop( bp->b_bcount - st->rl_bleft );
D 18
			reg = btop(um->um_ubinfo&0x3ffff) + npf;
E 18
I 18
			reg = btop(UBAI_ADDR(um->um_ubinfo)) + npf;
E 18
			o = (int)bp->b_un.b_addr & PGOFSET;
			ubapurge(um);
			um->um_tab.b_active++;
D 4

			rlwait( rladdr );
E 4
I 4
			rlwait(rladdr);
E 4
			rladdr->rlda.rw = st->rl_cylnhd << 6;
D 4
			if ( st->rl_bleft < (st->rl_bpart = rl02.btrak) )
E 4
I 4
			if (st->rl_bleft < (st->rl_bpart = rl02.btrak))
E 4
				st->rl_bpart = st->rl_bleft;
			rladdr->rlmp.rw = -(st->rl_bpart >> 1);
			cmd = (bp->b_flags&B_READ ? RL_READ : RL_WRITE) |
D 4
				RL_IE | (ui->ui_slave << 8);
E 4
I 4
			    RL_IE | (ui->ui_slave << 8);
E 4
			ubaddr = (int)ptob(reg) + o;
			cmd |= ((ubaddr >> 12) & RL_BAE);
D 4

E 4
			rladdr->rlba = ubaddr;
			rladdr->rlcs = cmd;
			return;
		}
D 4

E 4
		um->um_tab.b_active = 0;
		um->um_tab.b_errcnt = 0;
		dp->b_active = 0;
		dp->b_errcnt = 0;
D 4

E 4
		/* "b_resid" words remaining after error */
		bp->b_resid = st->rl_bleft;
		um->um_tab.b_actf = dp->b_forw;
		dp->b_actf = bp->av_forw;
D 4

retry:
E 4
		st->rl_dn = -1;
		st->rl_bpart = st->rl_bleft = 0;
		iodone(bp);
		/*
		 * If this unit has more work to do,
		 * then start it up right away.
		 */
		if (dp->b_actf)
D 4
			if (rlustart(ui))
				needie = 0;
E 4
I 4
			rlustart(ui);
E 4
		as &= ~(1<<ui->ui_slave);
	} else
		as |= (1<<ui->ui_slave);
D 4
	/*
	 * Release unibus resources and flush data paths.
	 */
E 4
	ubadone(um);
D 4

E 4
	/* reset state info */
	st->rl_dn = -1;
	st->rl_cylnhd = st->rl_bpart = st->rl_bleft = 0;
D 4

doattn:
E 4
	/*
	 * Process other units which need attention.
	 * For each unit which needs attention, call
	 * the unit start routine to place the slave
	 * on the controller device queue.
	 */
D 12
	while (unit = ffs(as)) {
E 12
I 12
	while (unit = ffs((long)as)) {
E 12
		unit--;		/* was 1 origin */
		as &= ~(1<<unit);
D 4
		(void) rlustart(rlip[rl21][unit]);
E 4
I 4
		rlustart(rlip[rl21][unit]);
E 4
	}
	/*
	 * If the controller is not transferring, but
	 * there are devices ready to transfer, start
	 * the controller.
	 */
	if (um->um_tab.b_actf && um->um_tab.b_active == 0)
D 4
		(void) rlstart(um);
E 4
I 4
		rlstart(um);
E 4
}

D 2
rlwait( rladdr )
register struct rldevice *rladdr;
E 2
I 2
rlwait(rladdr)
	register struct rldevice *rladdr;
E 2
{
I 2

E 2
	while ((rladdr->rlcs & RL_CRDY) == 0)
D 4
		continue;         /* Wait */
E 4
I 4
		;
E 4
D 15
}

D 2
rlread(dev)
E 2
I 2
rlread(dev, uio)
E 2
	dev_t dev;
I 2
	struct uio *uio;
E 2
{
D 10
	register int unit = minor(dev) >> 3;
E 10
I 10
	register int unit = rlunit(dev);
E 10

	if (unit >= NRL)
D 2
		u.u_error = ENXIO;
	else
		physio(rlstrategy, &rrlbuf[unit], dev, B_READ, minphys);
E 2
I 2
		return (ENXIO);
	return (physio(rlstrategy, &rrlbuf[unit], dev, B_READ, minphys, uio));
E 2
}

D 2
rlwrite(dev)
E 2
I 2
rlwrite(dev, uio)
E 2
	dev_t dev;
I 2
	struct uio *uio;
E 2
{
D 10
	register int unit = minor(dev) >> 3;
E 10
I 10
	register int unit = rlunit(dev);
E 10

	if (unit >= NRL)
D 2
		u.u_error = ENXIO;
	else
		physio(rlstrategy, &rrlbuf[unit], dev, B_WRITE, minphys);
E 2
I 2
		return (ENXIO);
	return (physio(rlstrategy, &rrlbuf[unit], dev, B_WRITE, minphys, uio));
E 15
E 2
}

/*
 * Reset driver after UBA init.
 * Cancel software state of all pending transfers
 * and restart all units and the controller.
 */
rlreset(uban)
	int uban;
{
	register struct uba_ctlr *um;
	register struct uba_device *ui;
	register struct rldevice *rladdr;
	register struct rl_stat *st;
D 4
	register int	rl21, unit;
E 4
I 4
	register int rl21, unit;
E 4

	for (rl21 = 0; rl21 < NHL; rl21++) {
		if ((um = rlminfo[rl21]) == 0 || um->um_ubanum != uban ||
		    um->um_alive == 0)
			continue;
D 4
		printf(" Reset hl%d", rl21);
E 4
I 4
		printf(" hl%d", rl21);
E 4
		rladdr = (struct rldevice *)um->um_addr;
		st = &rl_stat[rl21];
		um->um_tab.b_active = 0;
		um->um_tab.b_actf = um->um_tab.b_actl = 0;
		if (um->um_ubinfo) {
			printf("<%d>", (um->um_ubinfo>>28)&0xf);
D 2
			ubadone(um);
E 2
I 2
			um->um_ubinfo = 0;
E 2
		}
D 4

E 4
		/* reset controller */
		st->rl_dn = -1;
		st->rl_cylnhd = 0;
		st->rl_bleft = 0;
		st->rl_bpart = 0;
D 2
		rlwait( rladdr );
E 2
I 2
		rlwait(rladdr);
E 2
D 4

E 4
		for (unit = 0; unit < NRL; unit++) {
			rladdr->rlcs = (unit << 8) | RL_GETSTAT;
D 2
			rlwait( rladdr );
E 2
I 2
			rlwait(rladdr);
E 2
D 4

E 4
			/* Determine disk posistion */
			rladdr->rlcs = (unit << 8) | RL_RHDR;
			rlwait(rladdr);
D 4

E 4
			/* save disk drive posistion */
			st->rl_cyl[unit] =
				(rladdr->rlmp.readhdr & 0177700) >> 6;
D 4

E 4
			if ((ui = rldinfo[unit]) == 0)
				continue;
			if (ui->ui_alive == 0 || ui->ui_mi != um)
				continue;
			rlutab[unit].b_active = 0;
D 4
			(void) rlustart(ui);
E 4
I 4
			rlustart(ui);
E 4
		}
D 4
		(void) rlstart(um);
E 4
I 4
		rlstart(um);
E 4
	}
}

/*
 * Wake up every second and if an interrupt is pending
 * but nothing has happened increment a counter.
 * If nothing happens for 20 seconds, reset the UNIBUS
 * and begin anew.
 */
rlwatch()
{
	register struct uba_ctlr *um;
	register rl21, unit;
	register struct rl_softc *rl;

	timeout(rlwatch, (caddr_t)0, hz);
	for (rl21 = 0; rl21 < NHL; rl21++) {
		um = rlminfo[rl21];
		if (um == 0 || um->um_alive == 0)
			continue;
		rl = &rl_softc[rl21];
		if (um->um_tab.b_active == 0) {
			for (unit = 0; unit < NRL; unit++)
				if (rlutab[unit].b_active &&
				    rldinfo[unit]->ui_mi == um)
					goto active;
			rl->rl_wticks = 0;
			continue;
		}
active:
		rl->rl_wticks++;
		if (rl->rl_wticks >= 20) {
			rl->rl_wticks = 0;
			printf("hl%d: lost interrupt\n", rl21);
			ubareset(um->um_ubanum);
		}
	}
}

I 4
/*ARGSUSED*/
E 4
rldump(dev)
	dev_t dev;
{
D 4
	/* don't think there is room on swap for it anyway. */
}
I 3
 
rlsize(dev)
	dev_t dev;
{
	int unit = minor(dev) >> 3;
	struct uba_device *ui;
	struct rlst *st;
E 4

D 4
	if (unit >= NRL || (ui = rldinfo[unit]) == 0 || ui->ui_alive == 0)
		return (-1);
	st = &rl02;
	return (st->sizes[minor(dev) & 07].nblocks);
E 4
I 4
	/* don't think there is room on swap for it anyway. */
E 4
}
I 5

rlsize(dev)
	dev_t dev;
{
D 10
	register int unit = minor(dev) >> 3;
E 10
I 10
	register int unit = rlunit(dev);
E 10
	register struct uba_device *ui;

	if (unit >= NRL || (ui = rldinfo[unit]) == 0 || ui->ui_alive == 0)
		return (-1);
	return (rl02.sizes[minor(dev) & 07].nblocks);
}
E 5
#endif
E 3
E 1
