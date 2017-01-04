h07175
s 00006/00004/00871
d D 7.2 88/01/28 12:18:34 bostic 25 24
c vaxuba/rx.c sets ui->ui_dk = 1 which screws up disk stats, plus 
c lint; from Chris Torek
e
s 00001/00001/00874
d D 7.1 86/06/05 01:16:06 mckusick 24 23
c 4.3BSD release version
e
s 00007/00001/00868
d D 6.4 85/06/08 14:21:28 mckusick 23 22
c Add copyright
e
s 00012/00012/00857
d D 6.3 84/08/29 20:09:47 bloom 22 21
c Change to includes.  No more ../h
e
s 00003/00002/00866
d D 6.2 84/07/09 08:51:19 karels 21 20
c can't keep open count; clear lock on failed open
e
s 00000/00000/00868
d D 6.1 83/07/29 07:28:46 sam 20 19
c 4.2 distribution
e
s 00003/00003/00865
d D 4.19 83/05/21 15:57:08 sam 19 18
c macro-ized
e
s 00055/00039/00813
d D 4.18 83/05/11 09:34:30 helge 18 17
c fixed bugs in hard error handling, made density error hard...
e
s 00004/00001/00848
d D 4.17 83/04/29 10:46:05 helge 17 16
c format ioctl didn't reset double dens. bit when asked to format single dens.
e
s 00032/00023/00817
d D 4.16 83/04/26 16:27:50 helge 16 15
c fixed ioctl problems
e
s 00003/00003/00837
d D 4.15 83/04/15 11:51:25 helge 15 14
c fixed bug that swapped the meaning of the interleave bit in the minor device number
e
s 00034/00039/00806
d D 4.14 83/04/15 11:40:20 helge 14 13
c fixes in close, watchdog, and hard error handling
e
s 00081/00039/00764
d D 4.13 83/04/15 09:05:30 helge 13 12
c automatic detection of density and some other improvements
e
s 00039/00021/00764
d D 4.12 83/04/09 15:33:09 helge 12 11
c cleanup, still some problems with open/close
e
s 00061/00040/00724
d D 4.11 83/04/06 18:27:45 helge 11 10
c seem to work ok in both character and block mode.........
e
s 00106/00086/00658
d D 4.10 83/04/04 17:16:30 helge 10 9
c substantially rewritten to accomodate block devices, not yet tested!
e
s 00026/00015/00718
d D 4.9 83/03/29 16:11:07 helge 9 8
c works ok for character devices, not for block devices
e
s 00065/00041/00668
d D 4.8 83/03/28 12:14:07 helge 8 7
c interrupt- and watchdog-routines fixed, still needs more testing
e
s 00128/00051/00581
d D 4.7 83/03/26 20:09:05 helge 7 6
c intermediate version, still in debugging phase
e
s 00035/00027/00597
d D 4.6 83/03/23 09:50:20 helge 6 5
c intermediate version,hangs the system, do not use
e
s 00012/00011/00612
d D 4.5 83/03/20 18:45:54 helge 5 4
c some bugfixes, still not working.......
e
s 00001/00001/00622
d D 4.4 83/02/21 18:23:17 helge 4 3
c what happened to the sccs id??
e
s 00017/00011/00606
d D 4.3 83/02/21 18:19:44 helge 3 2
c now even compiles, but still untested...
e
s 00202/00205/00415
d D 4.2 83/02/21 15:13:24 sam 2 1
c first understanding
e
s 00620/00000/00000
d D 4.1 83/02/08 23:14:29 sam 1 0
c date and time created 83/02/08 23:14:29 by sam
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
D 4
/*	rx.c	4.2	83/02/21	*/
E 4
I 4
D 23
/*	%M%	%I%	%E%	*/
E 23
I 23
/*
D 24
 * Copyright (c) 1982 Regents of the University of California.
E 24
I 24
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 24
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 23
E 4
E 3

#include "rx.h"
#if NFX > 0
/*
 * RX02 floppy disk device driver
 *
D 2
 * From drivers by Richard Wales and Bill Shannon
 * (untested, or even compiled)
E 2
I 2
D 6
 * WARNING, UNTESTED
E 6
I 6
D 7
 * -- WARNING, UNTESTED --
E 7
I 7
D 9
 * -- WARNING, NOT THOROUGHLY TESTED --
E 9
E 7
E 6
E 2
 */
I 8

/*
I 12
 * TODO:
D 13
 *	- Make the driver automatically detect the density of
 *	  the floppy disks ( this is easily done using the 
 *	  'read status' command )
E 13
I 13
 *	- clean up the code for multisector transfers using
 *	  a 'transfer in progress' flag
 *	- Test Deleted Data read/write 
D 14
 *	- Test error handling/reporting and 'volume valid'
 *	  handling.
E 14
I 14
 *	- Test error handling/reporting and 'volume valid' stuff
E 14
E 13
 *
E 12
D 10
 * TODO:
D 9
 *    -	Make the driver recognize when the drive subsystem 
 * 	has been turned off, so it can initialize the controller. 
E 9
 *    - Make it possible to access blocks containing less than
 *	512 bytes properly.
 *
E 10
 * 	Note: If the drive subsystem is
 * 	powered off at boot time, the controller won't interrupt!
 */

E 8
I 2
#include "../machine/pte.h"

E 2
D 22
#include "../h/param.h"
D 2
#include "../h/systm.h"
#include "../h/cpu.h"
E 2
#include "../h/buf.h"
I 2
#include "../h/systm.h"
E 2
#include "../h/conf.h"
I 3
#include "../h/errno.h"
#include "../h/time.h"
E 3
D 2
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/map.h"
#include "../h/pte.h"
#include "../h/clist.h"
#include "../h/tty.h"
#include "../h/file.h"
E 2
I 2
#include "../h/kernel.h"
#include "../h/uio.h"
I 3
#include "../h/file.h"
E 22
I 22
#include "param.h"
#include "buf.h"
#include "systm.h"
#include "conf.h"
#include "errno.h"
#include "time.h"
#include "kernel.h"
#include "uio.h"
#include "file.h"
E 22
E 3
E 2

I 2
#include "../vax/cpu.h"
E 2
#include "../vax/nexus.h"
I 14

E 14
D 22
#include "../vaxuba/ubavar.h"
#include "../vaxuba/ubareg.h"
#include "../vaxuba/rxreg.h"
E 22
I 22
#include "ubavar.h"
#include "ubareg.h"
#include "rxreg.h"
E 22

I 11
#define b_cylin	b_resid

E 11
/* per-controller data */
struct	rx_ctlr {
	int	rxc_state;	/* controller state */
#define	RXS_READ	1	/* read started	*/
#define	RXS_EMPTY	2	/* empty started */
#define	RXS_FILL	3	/* fill started	*/
#define	RXS_WRITE	4	/* write started */
#define	RXS_FORMAT	5	/* format started */
#define	RXS_RDSTAT	6	/* status read started */
#define	RXS_RDERR	7	/* error read started */
I 2
D 10
#define RXS_IDLE	8	/* device is idle */
E 10
I 10
#define	RXS_IDLE	8	/* device is idle */
E 10
E 2
	u_short	rxc_rxcs;	/* extended error status */
	u_short	rxc_rxdb;
	u_short	rxc_rxxt[4];
I 8
	int	rxc_tocnt;	/* for watchdog routine */
E 8
D 2
	u_short	rxc_tocnt;	/* for watchdog routine */
#define	RX_MAXTIMEOUT	20	/* # seconds to wait before giving up */
E 2
I 2
#define	RX_MAXTIMEOUT	30	/* # seconds to wait before giving up */
E 2
} rx_ctlr[NFX];
D 6
struct buf	rrxbuf[NFX];	/* buffer for I/O */
struct buf	erxbuf[NFX];	/* buffer for reading error status */
E 6

I 6
/* per-drive buffers */
D 7
struct buf	rrxbuf[NRX];	/* buffers for I/O */
E 7
I 7
struct buf	rrxbuf[NRX];	/* buffers for raw I/O */
E 7
struct buf	erxbuf[NRX];	/* buffers for reading error status */
I 7
D 12
struct buf	rxutab[NRX];	/* per drive buffer queue heads */
E 12
I 12
struct buf	rxutab[NRX];	/* per drive buffers */
E 12
E 7

E 6
/* per-drive data */
struct rx_softc {
D 2
	int sc_flags;		/* drive status flags */
E 2
I 2
	int	sc_flags;	/* drive status flags */
E 2
D 13
#define	RXF_DBLDEN	0x01	/* use double density */
#define	RXF_DIRECT	0x02	/* use direct sector mapping */
#define	RXF_TRKZERO	0x04	/* start mapping on track 0 */
#define	RXF_DEVTYPE	0x07	/* density and mapping flags */
E 13
I 13
D 15
#define	RXF_DIRECT	0x01	/* use direct sector mapping */
#define	RXF_TRKZERO	0x02	/* start mapping on track 0 */
E 15
I 15
D 16
#define	RXF_TRKZERO	0x01	/* start mapping on track 0 */
#define	RXF_DIRECT	0x02	/* use direct sector mapping */
E 16
I 16
#define	RXF_DIRECT	0x01	/* if set: use direct sector mapping */
#define	RXF_TRKONE	0x02	/* if set: start mapping on track 1 */
E 16
E 15
#define	RXF_DBLDEN	0x04	/* use double density */
#define	RXF_DEVTYPE	0x07	/* mapping flags */
E 13
D 12
#define	RXF_OPEN	0x10	/* open */
E 12
I 12
#define	RXF_LOCK	0x10	/* exclusive use */
E 12
#define	RXF_DDMK	0x20	/* deleted-data mark detected */
#define	RXF_USEWDDS	0x40	/* write deleted-data sector */
I 12
#define	RXF_FORMAT	0x80	/* format in progress */
I 18
#define	RXF_BAD		0x100	/* drive bad, cannot be used */
E 18
E 12
D 2
	int sc_csbits;		/* constant bits for CS register */
	int sc_lsector;		/* logical sector number for I/O */
	int sc_psector;		/* physical sector number for I/O */
	int sc_ptrack;		/* physical track number for I/O */
E 2
I 2
	int	sc_csbits;	/* constant bits for CS register */
D 8
	int	sc_tocnt;	/* for watchdog routine */
E 8
I 7
D 12
	caddr_t	sc_uaddr;	/* save orig. unibus address while */
				/* doing multisector transfers */
	long	sc_bcnt;	/* save total transfer count for */
				/* multisector transfers */
I 11
	long	sc_resid;	/* no of bytes left to transfer in multisect */
				/* operations */
E 11
I 10
	int	sc_offset;	/* raw mode kludge: gives the offset into */
				/* a block of DEV_BSIZE for the current */
				/* request */
E 12
I 11
	int	sc_open;	/* count number of opens */
I 12
	int	sc_offset;	/* raw mode kludge to avoid restricting */
				/* single sector transfers to start on */
				/* DEV_BSIZE boundaries */
	/*
	 * The rest of this structure is used to 
	 * store temporaries while simulating multi 
	 * sector transfers
	 */
	caddr_t	sc_uaddr;	/* unibus base address */
	long	sc_bcnt;	/* total transfer count */
D 15
	long	sc_resid;	/* no of bytes left to transfer */
E 15
I 15
	long	sc_resid;	/* no. of bytes left to transfer */
E 15
E 12
E 11
E 10
E 7
E 2
} rx_softc[NRX];

I 2
struct rxerr {
	short	rxcs;
	short	rxdb;
	short	rxxt[4];	/* error code dump from controller */
D 5
} rxerr[NFX];
E 5
I 5
} rxerr[NRX];
/* End of per-drive data */
E 5

E 2
struct	uba_device *rxdinfo[NRX];
struct	uba_ctlr *rxminfo[NFX];
I 11

I 18
struct buf *savebp;

E 18
E 11
D 5
int rxprobe(), rxslave(), rxattach(), rxdgo(), rxintr();
int rxwatch(), rxphys();
E 5
I 5
int rxprobe(), rxslave(), rxattach(), rxdgo(), rxintr(), rxwatch(), rxphys();
E 5
u_short rxstd[] = { 0177170, 0177150, 0 };
struct uba_driver fxdriver =
  { rxprobe, rxslave, rxattach, rxdgo, rxstd, "rx", rxdinfo, "fx", rxminfo };

int	rxwstart;
D 5
#define	RXUNIT(dev)	(minor(dev)>>4)
E 5
I 5
#define	RXUNIT(dev)	(minor(dev)>>3)
I 6
D 10
#define MASKREG(reg)	(reg&0xffff)
E 10
I 10
#define	MASKREG(reg)	(reg&0xffff)
D 11
#define NDPC	2				/* # drives per controller */
E 11
E 10
E 6
E 5

D 2
/* a drive's letter name, based on density and sector mapping */
#define	DEVNAME(dev)	('a'+((dev)&DEVTYPE))
#define	UNITNAME(unit)	DEVNAME(sc->sc_flags)

E 2
/* constants related to floppy data capacity */
#define	RXSECS	2002				/* # sectors on a floppy */
D 2
#define	DDSTATE	(sc->sc_flags&DBLDEN)		/* double-density device? */
E 2
I 2
D 13
#define	DDSTATE	(sc->sc_flags&RXF_DBLDEN)
E 13
I 13
#define	DDSTATE	(sc->sc_csbits&RX_DDEN)
E 13
E 2
#define	NBPS	(DDSTATE ? 256 : 128)		/* # bytes per sector */
D 11
#define	NWPS	(DDSTATE ? 128 : 64)		/* # words per sector */
E 11
#define	RXSIZE	(DDSTATE ? 512512 : 256256)	/* # bytes per disk */
D 11
#define	SECSHFT	(DDSTATE ? 8 : 7)		/* # bits to shift for sctr # */
E 11
#define	SECMASK	(DDSTATE ? 0xff : 0x7f)		/* shifted-out bits of offset */

D 2
#define	B_CTRL	0x80000000		/* control (format) request */
E 2
I 2
D 13
#define	B_CTRL	0x80000000			/* control (format) request */
E 13
I 13
#define	B_CTRL		0x80000000		/* control (format) request */
#define B_RDSTAT	0x40000000		/* read drive status (open) */
E 13
E 2

/*ARGSUSED*/
rxprobe (reg)
	caddr_t reg;
{
D 2
	register int br, cvec;		/* value-result */
E 2
I 2
	register int br, cvec;			/* value-result */
E 2
	struct rxdevice *rxaddr = (struct rxdevice *)reg;

#ifdef lint
	br = 0; cvec = br; br = cvec;
I 2
	rxintr(0);
E 2
#endif lint
	rxaddr->rxcs = RX_INTR;
	DELAY(10);
	rxaddr->rxcs = 0;
	return (sizeof (*rxaddr));
}

I 25
/*ARGSUSED*/
E 25
D 10
rxslave(ui,reg)
E 10
I 10
rxslave(ui, reg)
E 10
	struct uba_device *ui;
	caddr_t reg;
{
D 25

	ui->ui_dk = 1;
E 25
	return (ui->ui_slave == 0 || ui->ui_slave == 1);
}

/*ARGSUSED*/
rxattach(ui)
	struct uba_device *ui;
{

}

/*ARGSUSED1*/
rxopen(dev, flag)
	dev_t dev;
D 16
	int flag;
E 16
{ 
	register int unit = RXUNIT(dev);
	register struct rx_softc *sc;
	register struct uba_device *ui;
I 7
D 8
	register struct rxdevice *rxaddr;
E 8
I 8
	struct rx_ctlr *rxc;
D 12
	int ctlr;
E 12
E 8
E 7

D 2
	if (unit >= NRX || (minor(dev) & (0xf^DEVTYPE)) ||
	    (ui = rxdinfo[unit]) == 0 || ui->ui_alive == 0) {
		u.u_error = ENXIO;
		return;
	}
E 2
I 2
D 5
	if (unit >= NRX || (minor(dev) & 0x8) ||
	    (ui = rxdinfo[unit]) == 0 || ui->ui_alive == 0)
E 5
I 5
	if (unit >= NRX || (ui = rxdinfo[unit]) == 0 || ui->ui_alive == 0)
E 5
		return (ENXIO);
E 2
	sc = &rx_softc[unit];
D 2
	if (sc->sc_flags & RXF_OPEN) {
		u.u_error = EBUSY;
		return;
	}
	sc->sc_flags = RXF_OPEN | (minor(dev) & DEVTYPE);
	sc->sc_csbits |= (ui->ui_slave == 1 ? RX_DRV1 : RX_DRV0) |
		 ((minor(dev) & DBLDEN) ? RX_DDEN : RX_SDEN) | RX_INTR;
E 2
I 2
D 11
	if (sc->sc_flags & RXF_OPEN)
		return (EBUSY);
I 8
	ctlr = ui->ui_mi->um_ctlr;
	rxc = &rx_ctlr[ctlr];
E 8
	sc->sc_flags = RXF_OPEN | (minor(dev) & RXF_DEVTYPE);
	sc->sc_csbits = RX_INTR;
	sc->sc_csbits |= ui->ui_slave == 0 ? RX_DRV0 : RX_DRV1;
	sc->sc_csbits |= minor(dev) & RXF_DBLDEN ? RX_DDEN : RX_SDEN;
I 7
D 8
	rxaddr = (struct rxdevice *)rxminfo[unit]->um_addr;
	if (rxaddr->rxcs == 0x800) {
		/*
		 * If the drive subsystem has been powered down,
		 * the rx211 controller must be initialized.
		 */
		rxreset(rxminfo[unit]->um_ubanum);
E 8
I 8
	rxc->rxc_tocnt = 0;
	if (rxwstart == 0) {
D 10
		rxtimo(ctlr);				/* start watchdog */
E 10
		rxwstart++;
I 10
		rxtimo();				/* start watchdog */
E 11
I 11
D 13
	if (sc->sc_open++ == 0) {
D 12
		ctlr = ui->ui_mi->um_ctlr;
		rxc = &rx_ctlr[ctlr];
E 12
I 12
		rxc = &rx_ctlr[ui->ui_mi->um_ctlr];
E 12
		sc->sc_flags = ( minor(dev) & RXF_DEVTYPE );
E 13
I 13
	if (sc->sc_open == 0 && sc->sc_csbits == 0) {
		struct buf *bp = &erxbuf[unit];
		/*
		 * lock the device while an open 
		 * is in progress
		 */
D 16
		sc->sc_flags = (minor(dev) & RXF_DEVTYPE) || RXF_LOCK;
E 16
I 16
		sc->sc_flags = (minor(dev) & RXF_DEVTYPE) | RXF_LOCK;
E 16
E 13
		sc->sc_csbits = RX_INTR;
		sc->sc_csbits |= ui->ui_slave == 0 ? RX_DRV0 : RX_DRV1;
D 13
		sc->sc_csbits |= minor(dev) & RXF_DBLDEN ? RX_DDEN : RX_SDEN;
E 13
I 13

		bp->b_dev = dev;
		bp->b_flags = B_RDSTAT | B_BUSY;
		bp->b_error = 0;
		bp->b_blkno = 0;
I 18
		sc->sc_offset = 0;
		sc->sc_resid  = 0;
E 18
		/*
		 * read device status to determine if
		 * a floppy is present in the drive and
		 * what density it is
		 */
		rxstrategy(bp);
		iowait(bp);
		if (bp->b_flags & B_ERROR) {
			sc->sc_csbits = 0;
I 21
			sc->sc_flags &= ~RXF_LOCK;
E 21
			return (bp->b_error);
		}
E 13
		if (rxwstart++ == 0) {
I 13
			rxc = &rx_ctlr[ui->ui_mi->um_ctlr];
E 13
			rxc->rxc_tocnt = 0;
D 14
			rxtimo();			/* start watchdog */
E 14
I 14
D 16
			timeout(rxtimo(), (caddr_t)0, hz);  /* start watchdog */
E 16
I 16
			timeout(rxwatch, (caddr_t)0, hz);  /* start watchdog */
E 16
E 14
		}
I 13
#ifdef RXDEBUG
		printf("rxopen: csbits=0x%x\n", sc->sc_csbits);
#endif
		sc->sc_flags &= ~RXF_LOCK;
E 13
I 12
	} else	{
D 13
		if ((sc->sc_flags&RXF_DBLDEN) != (dev&RXF_DBLDEN)) {
			/* 
			 * Can't open the device if the density does 
			 * not match the currently selected density 
			 */
			return(ENODEV);	
		}
		if (sc->sc_flags&RXF_LOCK)
E 13
I 13
		if (sc->sc_flags & RXF_LOCK)
E 13
			return(EBUSY);
E 12
E 11
E 10
E 8
	}
I 13
D 21
	sc->sc_open++;
E 21
I 21
	sc->sc_open = 1;
E 21
E 13
E 7
	return (0);
E 2
}

/*ARGSUSED1*/
rxclose(dev, flag)
	dev_t dev;
D 16
	int flag;
E 16
{
	register struct rx_softc *sc = &rx_softc[RXUNIT(dev)];
I 13
D 14
	register struct buf *dp = &rxutab[RXUNIT(dev)];
E 14
E 13
I 10
D 11
	int i;
E 11
E 10

D 11
	sc->sc_flags &= ~RXF_OPEN;
	sc->sc_csbits = 0;
I 8
D 10
	rxwstart = 0;
E 10
I 10
	for (i=0; i<NFX*NDPC; i++) {
		if (rx_softc[i].sc_flags&RXF_OPEN)
			break;
E 11
I 11
D 14
	if (--sc->sc_open == 0 ) {
I 13
		if (dp->b_active)
			iowait(dp->b_actl);
E 13
		sc->sc_csbits = 0;
		rxwstart--;
E 11
	}
E 14
I 14
D 21
	--sc->sc_open;
E 21
I 21
	sc->sc_open = 0;
E 21
I 16
#ifdef RXDEBUG
E 16
E 14
I 12
	printf("rxclose: dev=0x%x, sc_open=%d\n", dev, sc->sc_open);
I 16
#endif
E 16
E 12
D 11
	if (i == NFX*NDPC)
		rxwstart = 0;			/* Turn off watchdog if all */
						/* devices are closed */
E 11
E 10
D 9
	printf("rxclose: dev=0x%x\n", dev);
E 9
E 8
}

rxstrategy(bp)
	register struct buf *bp;
{
	struct uba_device *ui;
D 5
	register struct rx_softc *sc;
E 5
D 10
	register struct uba_ctlr *um;
E 10
I 2
D 7
	int s;
E 7
I 7
	register struct buf *dp;
	struct rx_softc *sc;
	int s, unit = RXUNIT(bp->b_dev);
E 7
E 2

I 10
	if (unit >= NRX)
		goto bad;
E 10
D 7
	ui = rxdinfo[RXUNIT(bp->b_dev)];
	if (ui == 0 || ui->ui_alive == 0) {
		bp->b_flags |= B_ERROR;
		iodone(bp);
		return;
	}
E 7
I 7
	ui = rxdinfo[unit];
D 13
	sc = &rx_softc[unit];
E 13
	if (ui == 0 || ui->ui_alive == 0) 
		goto bad;
I 13
	sc = &rx_softc[unit];
E 13
E 7
D 2
	s = spl5();
E 2
D 10
	um = ui->ui_mi;
E 10
D 7
	bp->b_actf = NULL;
E 7
I 7
D 19
	if (bp->b_blkno < 0 || (bp->b_blkno * DEV_BSIZE) > RXSIZE )
E 19
I 19
	if (bp->b_blkno < 0 || dbtob(bp->b_blkno) > RXSIZE)
E 19
		goto bad;
I 18
	if (sc->sc_flags & RXF_BAD) {
		bp->b_error = EIO;
		goto dbad;
	}
	s = spl5();
E 18
I 11
#ifdef RXDEBUG
D 18
	printf("rxstrategy: bp=0x%x, flgs=0x%x, unit=%d, block=%d, count=%d\n", 
E 18
I 18
	printf("rxstrat: bp=0x%x, fl=0x%x, un=%d, bl=%d, cnt=%d\n", 
E 18
		bp, bp->b_flags, unit, bp->b_blkno, bp->b_bcount);
#endif
E 11
E 7
I 2
D 18
	s = spl5();
E 18
I 11
	bp->b_cylin = bp->b_blkno;	/* don't care to calculate trackno */
E 11
E 2
D 6
	if (um->um_tab.b_actf->b_actf == NULL)
		um->um_tab.b_actf->b_actf = bp;
E 6
I 6
D 7
	if (um->um_tab.b_actf == NULL)
		um->um_tab.b_actf = bp;
E 6
	else
D 6
		um->um_tab.b_actf->b_actl->b_forw = bp;
	um->um_tab.b_actf->b_actl = bp;
	bp = um->um_tab.b_actf;
D 2
	if (bp->b_actf && bp->b_active == 0)
		(void) rxstart(um);
E 2
I 2
	if (!um->um_tab.b_active && bp->b_actf)
		rxstart(um);
E 6
I 6
		um->um_tab.b_actl->b_forw = bp;
	um->um_tab.b_actl = bp;
E 7
I 7
D 10
	dp = &rxutab[ui->ui_unit];
	disksort(dp, bp);
	rxustart(ui);
E 10
I 10
	dp = &rxutab[unit];
E 10
D 11
	bp->b_resid = bp->b_bcount;
E 11
D 10
	sc->sc_uaddr = bp->b_un.b_addr;
	sc->sc_bcnt = bp->b_bcount;
E 7
	rxstart(um);
E 10
I 10
	disksort(dp, bp);
	if (dp->b_active == 0) {
		rxustart(ui);
		bp = &ui->ui_mi->um_tab;
		if (bp->b_actf && bp->b_active == 0)
			rxstart(ui->ui_mi);
	}
E 10
E 6
E 2
	splx(s);
I 7
	return;

D 11
bad:	bp->b_flags |= B_ERROR;
E 11
I 11
bad:
I 18
	bp->b_error = ENXIO;
dbad:
E 18
	bp->b_flags |= B_ERROR;
E 11
	iodone(bp);
I 13
D 18
	bp->b_error = ENXIO;
E 18
E 13
	return;
E 7
}

/*
I 7
 * Unit start routine.
D 10
 * Put this unit on the ready queue for the controller,
 * unless it is already there.
E 10
I 10
 * Put this unit on the ready queue for the controller
E 10
 */
rxustart(ui)
	register struct uba_device *ui;
{
D 10
	struct buf *dp;
	struct uba_ctlr *um;

	dp = &rxutab[ui->ui_unit];
	um = ui->ui_mi;

	if (!dp->b_active) {
		dp->b_forw = NULL;
		if (um->um_tab.b_actf == NULL)
			um->um_tab.b_actf = dp;
		else
			um->um_tab.b_actl->b_forw = dp;
		um->um_tab.b_actl = dp;
		dp->b_active++;
	}
E 10
I 10
	struct buf *dp = &rxutab[ui->ui_unit];
	struct uba_ctlr *um = ui->ui_mi;
	
	dp->b_forw = NULL;
	if (um->um_tab.b_actf == NULL)
		um->um_tab.b_actf = dp;
	else
		um->um_tab.b_actl->b_forw = dp;
	um->um_tab.b_actl = dp;
	dp->b_active++;
E 10
}
/*
E 7
 * Sector mapping routine.
 * Two independent sets of choices are available:
 *
 * (a) The first logical sector may either be on track 1 or track 0.
 * (b) The sectors on a track may either be taken in 2-for-1 interleaved
 *	 fashion or directly.
 * This gives a total of four possible mapping schemes.
 *
 * Physical tracks on the RX02 are numbered 0-76.  Physical sectors on
 * each track are numbered 1-26.
 *
 * When interleaving is used, sectors on the first logical track are
 * taken in the order 1, 3, 5, ..., 25, 2, 4, 6, ..., 26.  A skew of
 * six sectors per track is also used (to allow time for the heads to
 * move); hence, the sectors on the second logical track are taken in
 * the order 7, 9, 11, ..., 25, 1, 3, 5, 8, 10, 12, ..., 26, 2, 4, 6;
 * the third logical track starts with sector 13; and so on.
 *
 * When the mapping starts with track 1, track 0 is the last logical
 * track, and this track is always handled directly (without inter-
 * leaving), even when the rest of the disk is interleaved.  (This is
 * still compatible with DEC RT-11, which does not use track 0 at all.)
 */
D 2
rxmap(sc)
	register struct rx_softc *sc;
E 2
I 2
rxmap(bp, psector, ptrack)
	struct buf *bp;
	int *psector, *ptrack;
E 2
{
	register int lt, ls, ptoff;
I 2
	struct rx_softc *sc = &rx_softc[RXUNIT(bp->b_dev)];
E 2

D 2
	lt = sc->sc_lsector / 26;
	ls = sc->sc_lsector % 26;
E 2
I 2
D 3
	ls = bp->b_blkno * (NBPS / DEV_BLKSIZE);
E 3
I 3
D 6
	ls = bp->b_blkno * (NBPS / DEV_BSIZE);
E 6
I 6
D 7
	ls = ( bp->b_blkno * DEV_BSIZE ) / NBPS;
E 7
I 7
D 10
	ls = ( bp->b_blkno * DEV_BSIZE + ( sc->sc_bcnt - bp->b_resid )) / NBPS;
E 10
I 10
D 11
	ls = ( bp->b_blkno * DEV_BSIZE + ( sc->sc_offset - bp->b_resid ))/NBPS;
E 11
I 11
D 19
	ls = ( bp->b_blkno * DEV_BSIZE + ( sc->sc_offset - sc->sc_resid ))/NBPS;
E 19
I 19
	ls = (dbtob(bp->b_blkno) + (sc->sc_offset - sc->sc_resid)) / NBPS;
E 19
E 11
E 10
E 7
E 6
E 3
	lt = ls / 26;
	ls %= 26;
E 2
	/*
	 * The "physical track offset" (ptoff) takes the
	 * starting physical track (0 or 1) and the desired
	 * interleaving into account.  If lt+ptoff >= 77,
	 * then interleaving is not performed.
	 */
	ptoff = 0;
D 2
	if (sc->sc_flags&DIRECT)
		ptoff += 77;
	if (sc->sc_flags&TRKZERO)
E 2
I 2
D 13
	if (sc->sc_flags&RXF_DIRECT)
E 13
I 13
	if (sc->sc_flags & RXF_DIRECT)
E 13
		ptoff = 77;
D 7
	if (sc->sc_flags&RXF_TRKZERO)
E 7
I 7
D 8
	if (!sc->sc_flags&RXF_TRKZERO)
E 8
I 8
D 11
	if (!(sc->sc_flags&RXF_TRKZERO))
E 11
I 11
D 13
	if (sc->sc_flags&RXF_TRKZERO)
E 13
I 13
D 16
	if (sc->sc_flags & RXF_TRKZERO)
E 16
I 16
	if (sc->sc_flags & RXF_TRKONE)
E 16
E 13
E 11
E 8
E 7
E 2
		ptoff++;
	if (lt + ptoff < 77)
		ls = ((ls << 1) + (ls >= 13) + (6*lt)) % 26;
D 2
	sc->sc_ptrack = (lt + ptoff) % 77;
	sc->sc_psector = ls + 1;
E 2
I 2
	*ptrack = (lt + ptoff) % 77;
	*psector = ls + 1;
E 2
}

I 7
/*
D 10
 * Controller start routine
E 10
I 10
 * Controller start routine.
 * Start a new transfer or continue a multisector
 * transfer. If this is a new transfer (dp->b_active == 1)
 * save the start address of the data buffer and the total
 * byte count in the soft control structure. These are
 * restored into the buffer structure when the transfer has
 * been completed, before calling 'iodone'.
E 10
 */
E 7
rxstart(um)
	register struct uba_ctlr *um;
{
	register struct rxdevice *rxaddr;
	register struct rx_ctlr *rxc;
	register struct rx_softc *sc;
D 7
	struct buf *bp;
E 7
I 7
	struct buf *dp, *bp;
E 7
D 2
	int unit;
E 2
I 2
	int unit, sector, track;
E 2

D 2
	if ((bp = um->um_tab.b_actf->b_actf) == NULL)
E 2
I 2
D 6
	if (um->um_tab.b_active || (bp = um->um_tab.b_actf->b_actf) == NULL)
E 6
I 6
D 7
	if (um->um_tab.b_active || (bp = um->um_tab.b_actf) == NULL)
E 7
I 7
	if (um->um_tab.b_active)
E 7
E 6
E 2
		return;
I 7
loop:
	if ((dp = um->um_tab.b_actf) == NULL)
		return;
	if ((bp = dp->b_actf) == NULL) {
		um->um_tab.b_actf = dp->b_forw;
		goto loop;
	}
I 14
	um->um_tab.b_active++;
E 14
E 7
I 2
D 10
	um->um_tab.b_active++;
E 10
E 2
	unit = RXUNIT(bp->b_dev);
	sc = &rx_softc[unit];
I 18
	if (sc->sc_flags & RXF_BAD) {
		rxpurge(um);
		return;
	}
E 18
I 10
	if (dp->b_active == 1) {
I 11
		sc->sc_resid = bp->b_bcount;
E 11
		sc->sc_uaddr = bp->b_un.b_addr;
		sc->sc_bcnt = bp->b_bcount;
		sc->sc_offset += sc->sc_bcnt;
		dp->b_active++;
	}
D 14
	um->um_tab.b_active++;
E 14
E 10
D 2
	sc->sc_tocnt = 0;
E 2
	rxaddr = (struct rxdevice *)um->um_addr;
	rxc = &rx_ctlr[um->um_ctlr];
I 7
D 8
	sc->sc_tocnt = 0;
E 8
D 11
	bp->b_bcount = bp->b_resid;
E 11
I 11
	bp->b_bcount = sc->sc_resid;
E 11
	if (bp->b_bcount > NBPS)
		bp->b_bcount = NBPS;
E 7
D 2
	if (bp->b_flags&B_CTRL) {		/* format */
E 2
I 2
D 8
	rxtimo(bp->b_dev);				/* start watchdog */
E 8
I 8
	rxc->rxc_tocnt = 0;
I 11
#ifdef RXDEBUG
	printf("rxstart: ");
#endif
E 11
E 8
D 9
	if (bp->b_flags&B_CTRL) {			/* format */
E 9
I 9
	if (rxaddr->rxcs == 0x800) {
		/*
D 10
		 * Simulated check for 'volume valid', check
E 10
I 10
D 13
		 * 'Volume valid'?, check
E 10
		 * if the drive unit has been powered down
E 13
I 13
		 * 'Volume valid'? (check if the 
		 * drive unit has been powered down)
E 13
		 */
		rxaddr->rxcs = RX_INIT;
		while((rxaddr->rxcs&RX_DONE) == 0)
			;
	}
D 13
	if (bp->b_flags&B_CTRL) {				/* format */
E 13
I 13
	if (bp->b_flags & B_CTRL) {				/* format */
E 13
E 9
E 2
		rxc->rxc_state = RXS_FORMAT;
		rxaddr->rxcs = RX_FORMAT | sc->sc_csbits;
D 2
		while ((rxaddr->rxcs&RXTREQ) == 0)
E 2
I 2
		while ((rxaddr->rxcs&RX_TREQ) == 0)
E 2
			;
		rxaddr->rxdb = 'I';
		return;
	}
I 13
	if (bp->b_flags & B_RDSTAT) {			/* read drive status */
		rxc->rxc_state = RXS_RDSTAT;
		rxaddr->rxcs = RX_RDSTAT | sc->sc_csbits;
		return;
	}
E 13
D 2
	if (bp->b_flags&B_READ) {		/* read */
E 2
I 2
D 8
	if (bp->b_flags&B_READ) {			/* read */
		rxmap(bp, &sector, &track);
E 8
I 8

D 9
	if (bp->b_flags&B_WRITE) {
		rxc->rxc_state = RXS_FILL;			/* write */
		um->um_cmd = RX_FILL;
		(void) ubago(rxdinfo[unit]);

	} else {
E 9
I 9
D 13
	if (bp->b_flags&B_READ) {
E 13
I 13
	if (bp->b_flags & B_READ) {
E 13
E 9
		rxmap(bp, &sector, &track);			/* read */
I 11
#ifdef RXDEBUG
		printf("read tr=%d, sc=%d", track, sector);
#endif
E 11
E 8
E 2
		rxc->rxc_state = RXS_READ;
		rxaddr->rxcs = RX_READ | sc->sc_csbits;
I 5
D 7
		printf("rxstart: (read) track=%d, sector=%d\n", track, sector);
E 7
I 7
D 8
		printf("rxstart/r: tr=%d, sc=%d, bl=%d, cnt=%d\n", 
			track, sector, bp->b_blkno, bp->b_bcount);
E 8
E 7
E 5
D 2
		while ((rxaddr->rxcs&RXTREQ) == 0)
E 2
I 2
		while ((rxaddr->rxcs&RX_TREQ) == 0)
E 2
			;
D 2
		rxaddr->rxdb = sc->sc_psector;
		while ((rxaddr->rxcs&RXTREQ) == 0)
E 2
I 2
		rxaddr->rxdb = (u_short)sector;
		while ((rxaddr->rxcs&RX_TREQ) == 0)
E 2
			;
D 2
		rxaddr->rxdb = sc->sc_ptrack;
E 2
I 2
		rxaddr->rxdb = (u_short)track;
I 9
	} else {
I 11
#ifdef RXDEBUG
		printf("write");
#endif
E 11
		rxc->rxc_state = RXS_FILL;			/* write */
		um->um_cmd = RX_FILL;
		(void) ubago(rxdinfo[unit]);
E 9
E 2
D 8
		return;
E 8
	}
I 9
#ifdef RXDEBUG
E 9
D 2
	/* write */
	rxc->rxc_state = RXS_FILL;
E 2
I 2
D 8
	rxc->rxc_state = RXS_FILL;			/* write */
E 2
	um->um_cmd = RX_FILL;
	(void) ubago(rxdinfo[unit]);
E 8
I 8
D 11
	printf("rxstart: flgs=0x%x, unit=%d, tr=%d, sc=%d, bl=%d, cnt=%d\n", 
		bp->b_flags, unit, track, sector, bp->b_blkno, bp->b_bcount);
E 11
I 11
	printf("\n");
E 11
I 9
#endif
E 9
E 8
}

rxdgo(um)
	struct uba_ctlr *um;
{
	register struct rxdevice *rxaddr = (struct rxdevice *)um->um_addr;
	int ubinfo = um->um_ubinfo;
D 6
	struct buf *bp = &rrxbuf[um->um_ctlr];
E 6
I 6
D 7
	struct buf *bp = um->um_tab.b_actf;
E 7
I 7
	struct buf *bp = um->um_tab.b_actf->b_actf;
E 7
E 6
	struct rx_softc *sc = &rx_softc[RXUNIT(bp->b_dev)];
	struct rx_ctlr *rxc = &rx_ctlr[um->um_ctlr];

D 6
	bp = um->um_tab.b_actf;
E 6
D 2
	rx_softc[RXUNIT(bp->b_actf->b_dev)].sc_tocnt = 0;
	bp->b_active++;
E 2
I 2
D 7
	sc->sc_tocnt = 0;
E 7
I 7
	rxaddr->rxcs = um->um_cmd | ((ubinfo & 0x30000) >> 4) | sc->sc_csbits;
E 7
E 2
	if (rxc->rxc_state != RXS_RDERR) {
D 2
		while ((rxaddr->rxcs&RXTREQ) == 0)
E 2
I 2
		while ((rxaddr->rxcs&RX_TREQ) == 0)
E 2
			;
D 2
		rxaddr->rxdb = bp->b_count >> 1;
E 2
I 2
D 8
		rxaddr->rxdb = bp->b_bcount >> 1;
E 8
I 8
		rxaddr->rxdb = (u_short) bp->b_bcount >> 1;
E 8
E 2
	}
D 2
	while ((rxaddr->rxcs&RXTREQ) == 0)
E 2
I 2
	while ((rxaddr->rxcs&RX_TREQ) == 0)
E 2
		;
D 2
	rxaddr->rxdb = ubinfo & 0xffff;
E 2
I 2
D 8
	rxaddr->rxdb = ubinfo;
E 8
I 8
	rxaddr->rxdb = (u_short) ubinfo;
E 8
E 2
D 7
	rxaddr->rxcs = um->um_cmd | ((ubinfo & 0x30000) >> 4) | sc->sc_csbits;
E 7
}

D 2
rxintr(ctlr)
	int ctlr;
E 2
I 2
D 8
rxintr(dev)
	dev_t dev;
E 8
I 8
rxintr(ctlr)
	int ctlr;
E 8
E 2
{
D 2
	struct uba_ctlr *um = rxminfo[ctlr];
	register struct rxdevice *rxaddr = (struct rxdevice *)um->um_addr;
	register struct buf *bp = &rrxbuf[ctlr];
	int unit = RXUNIT(bp->b_dev);
E 2
I 2
D 8
	int unit = RXUNIT(dev), sector, track;
	struct uba_ctlr *um = rxminfo[unit];
E 8
I 8
	int unit, sector, track;
	struct uba_ctlr *um = rxminfo[ctlr];
E 8
	register struct rxdevice *rxaddr;
D 7
	register struct buf *bp;
E 7
I 7
	register struct buf *bp, *dp;
E 7
E 2
D 8
	register struct rx_softc *sc = &rx_softc[unit];
	struct uba_device *ui = rxdinfo[unit];
E 8
I 8
	register struct rx_softc *sc;
	struct uba_device *ui;
E 8
D 2
	struct rxerr *er = &rxerr[ctlr];
	register struct rx_ctlr *rxc = &rx_ctlr[ctlr];
	register struct rxdeferr *ed;
E 2
I 2
	struct rxerr *er;
D 14
	register struct rx_ctlr *rxc;
E 14
I 14
	struct rx_ctlr *rxc;
E 14
E 2

D 2
	if (um->um_tab.b_actf->b_active) {
		bp = um->um_tab.b_actf->b_actf;
		if ((rxaddr->rxcs & RXERR) &&
		    rxc->rxc_state != RXS_RDSTAT && rxc->rxc_state != RXS_RDERR)
			bp->b_flags |= B_ERROR;
		ubadone(um);
		um->um_tab.b_actf->b_active = 0;
		um->um_tab.b_actf->b_actf = bp->b_forw;
		bp->b_active = 0;
		bp->b_errcnt = 0;
		bp->b_resid = 0;
		iodone(bp);
	}
	if (um->um_tab.b_actf->b_actf == 0) {
		sc->sc_iostate &= ~VAS_DMA;
		if (sc->sc_iostate&VAS_WANT) {
			sc->sc_iostate &= ~VAS_WANT;
			wakeup((caddr_t)&sc->sc_iostate);
		}
E 2
I 2
D 8
	sc->sc_tocnt = 0;
E 8
	if (!um->um_tab.b_active)
E 2
		return;
I 7
	dp = um->um_tab.b_actf;
	if (!dp->b_active)
		return;
I 8
	bp = dp->b_actf;
	unit = RXUNIT(bp->b_dev);
	sc = &rx_softc[unit];
	ui = rxdinfo[unit];
E 8
E 7
D 2
	}
	if (um->um_tab.b_actf->b_active == 0)
		rxstart(um);
E 2
I 2
	rxaddr = (struct rxdevice *)um->um_addr;
	rxc = &rx_ctlr[um->um_ctlr];
I 8
	rxc->rxc_tocnt = 0;
E 8
D 6
	er = &rxerr[um->um_ctlr];
	bp = um->um_tab.b_actf->b_actf;
I 5
	printf("rxintr: unit=%d, state=0x%x\n", unit, rxc->rxc_state);
E 6
I 6
	er = &rxerr[unit];
I 9
#ifdef RXDEBUG
E 9
D 7
	bp = um->um_tab.b_actf;
	printf("rxintr: unit=%d, state=0x%x, ctrlr status=0x%x\n", 
E 7
I 7
D 8
	bp = dp->b_actf;
	printf("rxintr: dev=%d, state=0x%x, status=0x%x\n", 
E 7
		unit, rxc->rxc_state, rxaddr->rxcs);
E 8
I 8
D 11
	printf("rxintr: dev=0x%x, state=0x%x, status=0x%x\n", 
E 11
I 11
D 18
	printf("rxintr: dev=%x, state=%d, status=0x%x", 
E 11
		bp->b_dev, rxc->rxc_state, rxaddr->rxcs);
E 18
I 18
	printf("rxint: dev=%x, st=%d, cs=0x%x, db=0x%x\n", 
		bp->b_dev, rxc->rxc_state, rxaddr->rxcs, rxaddr->rxdb);
E 18
I 9
#endif
E 9
E 8
E 6
E 5
	if ((rxaddr->rxcs & RX_ERR) &&
D 10
	    rxc->rxc_state != RXS_RDSTAT && rxc->rxc_state != RXS_RDERR)
E 10
I 10
	    (rxc->rxc_state != RXS_RDSTAT) && (rxc->rxc_state != RXS_RDERR))
E 10
		goto error;
E 2
	switch (rxc->rxc_state) {

I 2
	/*
	 * Incomplete commands.  Perform next step
	 * and return.  Note that b_active is set on
	 * entrance and, therefore, also on exit.
	 */
E 2
	case RXS_READ:
		if (rxaddr->rxdb & RXES_DDMARK)
			sc->sc_flags |= RXF_DDMK;
		else
			sc->sc_flags &= ~RXF_DDMK;
		rxc->rxc_state = RXS_EMPTY;
		um->um_cmd = RX_EMPTY;
		(void) ubago(ui);
I 11
D 18
#ifdef RXDEBUG
		printf("\n");
#endif
E 18
E 11
		return;

	case RXS_FILL:
		rxc->rxc_state = RXS_WRITE;
		if (sc->sc_flags & RXF_USEWDDS) {
			rxaddr->rxcs = RX_WDDS | sc->sc_csbits;
			sc->sc_flags &= ~RXF_USEWDDS;
		} else
			rxaddr->rxcs = RX_WRITE | sc->sc_csbits;
I 10
		rxmap(bp, &sector, &track);
E 10
D 2
		while ((rxaddr->rxcs&RXTREQ) == 0)
E 2
I 2
		while ((rxaddr->rxcs&RX_TREQ) == 0)
E 2
			;
D 2
		rxaddr->rxdb = sc->sc_psector;
		while ((rxaddr->rxcs&RXTREQ) == 0)
E 2
I 2
D 10
		rxmap(bp, &sector, &track);
E 10
		rxaddr->rxdb = sector;
		while ((rxaddr->rxcs&RX_TREQ) == 0)
E 2
			;
D 2
		rxaddr->rxdb = sc->sc_ptrack;
E 2
I 2
		rxaddr->rxdb = track;
I 11
D 18
#ifdef RXDEBUG
		printf("\n");
#endif
E 18
E 11
E 2
		return;

D 2
	case RXS_EMPTY:
	case RXS_WRITE:
	case RXS_FORMAT:
		bp->b_resid = 0;
		break;

E 2
I 2
	/*
	 * Possibly completed command.
	 */
E 2
	case RXS_RDSTAT:
I 13
		if (bp->b_flags & B_RDSTAT) {
			if ((rxaddr->rxdb&RXES_READY) == 0) {
				bp->b_flags |= B_ERROR;
				bp->b_error = ENODEV;
			} else {
				sc->sc_csbits |= rxaddr->rxdb&RXES_DBLDEN ?
					RX_DDEN : RX_SDEN;
			}
			goto rdone;
		}
E 13
D 2
		if (rxaddr->rxdb&RX_READY)
E 2
I 2
		if (rxaddr->rxdb&RXES_READY)
E 2
			goto rderr;
D 9
		bp->b_error = EBUSY;
E 9
I 9
D 12
		bp->b_error = EIO;
E 12
I 12
D 18
		bp->b_error = EBUSY;
E 18
I 18
		bp->b_error = ENODEV;
E 18
E 12
E 9
		bp->b_flags |= B_ERROR;
D 2
		break;
E 2
I 2
		goto done;
E 2

I 2
	/*
	 * Command completed.
	 */
	case RXS_EMPTY:
	case RXS_WRITE:	
D 13
	case RXS_FORMAT:
E 13
		goto done;

I 13
	case RXS_FORMAT:
		goto rdone;

E 13
E 2
	case RXS_RDERR:
D 2
		printf("rx%d%c: hard error, lsn%d (trk %d psec %d) ",
			unit, UNITNAME(unit),
			sc->sc_lsector, sc->sc_ptrack, sc->sc_psector);
		ed = rxdeferr;
		while (; ed->errval && ed->errval != (er->rxxt[0]&0xff); ed++)
			;
		printf ("cs=%b, db=%b, err=%x (%s)\n",
			er->rxcs&0xffff, rxaddr->rxcs_BITS,
			er->rxdb&0x0ffff, RXES_BITS,
			er->rxxt[0]&0xffff, ed->errmsg);
		break;
E 2
I 2
D 10
		rxmap(bp, &sector, &track);
		printf("rx%d: hard error, lsn%d (trk %d psec %d) ",
D 3
			unit, bp->b_blkno * (NBPS / DEV_BLKSIZE),
E 3
I 3
			unit, bp->b_blkno * (NBPS / DEV_BSIZE),
E 3
			track, sector);
D 6
		printf("cs=%b, db=%b, err=%x\n", er->rxcs, 
			RXCS_BITS, er->rxdb, RXES_BITS, er->rxxt[0]);
E 6
I 6
		printf("cs=%b, db=%b, err=%x\n", MASKREG(er->rxcs), 
			RXCS_BITS, MASKREG(er->rxdb), RXES_BITS, 
			MASKREG(er->rxxt[0]));
		printf("errstatus: 0x%x, 0x%x, 0x%x, 0x%x\n", er->rxxt[0],
			er->rxxt[1], er->rxxt[2], er->rxxt[3]);
E 10
I 9
D 16
		bp = bp->b_back;		/* kludge, see 'rderr:' */
E 16
I 16
D 18
		bp = bp->b_back;
E 18
I 18
		bp = savebp;
E 18
E 16
I 10
		rxmap(bp, &sector, &track);
		printf("rx%d: hard error, trk %d psec %d ",
			unit, track, sector);
		printf("cs=%b, db=%b, err=", MASKREG(er->rxcs), 
			RXCS_BITS, MASKREG(er->rxdb), RXES_BITS);
D 16
		printf("0x%x, 0x%x, 0x%x, 0x%x\n", MASKREG(er->rxxt[0]),
E 16
I 16
		printf("%x, %x, %x, %x\n", MASKREG(er->rxxt[0]),
E 16
			MASKREG(er->rxxt[1]), MASKREG(er->rxxt[2]), 
			MASKREG(er->rxxt[3]));
E 10
E 9
E 6
		goto done;
E 2

	default:
D 2
		printf ("rx%d: state %d (reset)",
			unit, State);
		rxreset (unit);
E 2
I 2
D 7
		printf("rx%d: state %d (reset)", unit, rxc->rxc_state);
E 7
I 7
		printf("rx%d: state %d (reset)\n", unit, rxc->rxc_state);
E 7
		rxreset(um->um_ubanum);
E 2
D 7
		printf("\n");
E 7
		return;
	}
D 2
done:
	rxc->rxc_state = RXS_IDLE;
	ubadone(um);
	iodone(bp);
	return;

E 2
error:
	/*
	 * In case of an error:
D 14
	 *  (a) Give up now if a format (ioctl) was in progress, or if a
	 *	  density error was detected.
E 14
I 14
	 *  (a) Give up now if a format (ioctl) was in progress, if a
	 *	  density error was detected, or if the drive went offline
E 14
	 *  (b) Retry up to nine times if a CRC (data) error was detected,
	 *	  then give up if the error persists.
	 *  (c) In all other cases, reinitialize the drive and try the
	 *	  operation once more before giving up.
	 */
D 2
	if (rxc->rxc_state == RXS_FORMAT || (rxaddr->rxdb&RX_DENERR))
E 2
I 2
	if (rxc->rxc_state == RXS_FORMAT || (rxaddr->rxdb&RXES_DENERR))
E 2
		goto giveup;
	if (rxaddr->rxdb & RXES_CRCERR) {
D 2
		sc->sc_errs++;
E 2
D 18
		if (++bp->b_errcnt >= 10)
E 18
I 18
		if (++um->um_tab.b_errcnt >= 10)
E 18
			goto giveup;
		goto retry;
	}
D 18
	bp->b_errcnt += 9;
	if (bp->b_errcnt >= 10)
E 18
I 18
	um->um_tab.b_errcnt += 9;
	if (um->um_tab.b_errcnt >= 10)
E 18
		goto giveup;
	rxaddr->rxcs = RX_INIT;
	/* no way to get an interrupt for "init done", so just wait */
D 2
	while ((rxaddr->rxdb&RX_IDONE) == 0)
E 2
I 2
D 9
	while ((rxaddr->rxdb&RX_DONE) == 0)
E 9
I 9
	while ((rxaddr->rxcs&RX_DONE) == 0)
E 9
E 2
		;
I 14
	/* if someone opened the drive: give up */
	if ((rxaddr->rxdb&RXES_READY) == 0)
		goto giveup;
E 14
retry:
D 2
	rxstart(ui->ui_mi);
E 2
I 2
	/*
	 * In case we already have UNIBUS resources, give
	 * them back since we reallocate things in rxstart.
I 6
D 13
	 * Also, the active flag must be reset, otherwise rxstart
D 11
	 * will refuse to restart the transfer
E 11
I 11
	 * will not restart the transfer
E 13
E 11
E 6
	 */
	if (um->um_ubinfo)
		ubadone(um);
I 6
	um->um_tab.b_active = 0;
E 6
	rxstart(um);
E 2
	return;
I 2

E 2
giveup:
	/*
	 * Hard I/O error --
D 2
	 * read the error registers, print them on the console, and give up.
	 * The reason for the "read status" is that I don't want to clutter
	 * the system log with errors for "drive not ready" conditions
	 * (which usually mean that the user tried to do I/O without a disk
	 * in the drive), and the only way to determine whether the drive is
	 * ready is by doing a "read status" before examining RX2ES.
	 * Density errors are not noted on the console either, since the
	 * only way to determine the density of an unknown disk is to try
	 * one density or the other at random and see which one doesn't give
	 * a density error.
E 2
I 2
D 18
	 * Density errors are not noted on the console since the
	 * only way to determine the density of an unknown disk
	 * is to try one density or the other at random and see
	 * which one doesn't give a density error.
E 18
I 18
	 * ALL errors are considered fatal and will abort the
	 * transfer and purge the i/o request queue
E 18
E 2
	 */
D 18
	if (rxaddr->rxdb & RXES_DENERR) {
D 2
		bp->b_error = ENODEV;
E 2
I 2
D 9
		bp->b_error = EIO;
E 9
I 9
		bp->b_error = ENODEV;
E 9
E 2
		bp->b_flags |= B_ERROR;
		goto done;
	}
E 18
I 18
	sc->sc_flags |= RXF_BAD;
	sc->sc_resid = 0;	/* make sure the transfer is terminated */
E 18
	rxc->rxc_state = RXS_RDSTAT;
	rxaddr->rxcs = RX_RDSTAT | sc->sc_csbits;
	return;
I 2

E 2
rderr:
	/*
D 18
	 * A hard error (other than not ready or density) has occurred.
E 18
I 18
	 * A hard error (other than not ready) has occurred.
E 18
	 * Read the extended error status information.
	 * Before doing this, save the current CS and DB register values,
	 * because the read error status operation may modify them.
I 2
D 10
	 * Insert buffer with request at the head of the queue.
E 10
I 10
D 18
	 * Insert buffer with request at the head of the queue, and
	 * save a pointer to the data buffer, so it can be restored
	 * when the read error status operation is finished.
E 18
I 18
	 * Insert buffer with request at the head of the queue.
E 18
E 10
E 2
	 */
	bp->b_error = EIO;
	bp->b_flags |= B_ERROR;
D 18
	ubadone(um);
I 9
D 11
	erxbuf[unit].b_back = bp;	/* kludge to save the buffer pointer */
					/* while processing the error */
E 11
I 11
	erxbuf[unit].b_back = bp;	/* save the data buffer pointer */
E 18
I 18
	if (um->um_ubinfo)
		ubadone(um);
	savebp = bp;
E 18
E 11
E 9
	er->rxcs = rxaddr->rxcs;
	er->rxdb = rxaddr->rxdb;
D 3
	bp = &erxbuf[ctlr];
E 3
I 3
	bp = &erxbuf[unit];
E 3
	bp->b_un.b_addr = (caddr_t)er->rxxt;
	bp->b_bcount = sizeof (er->rxxt);
	bp->b_flags &= ~(B_DIRTY|B_UAREA|B_PHYS|B_PAGET);
D 2
	um->um_tab.b_actf = bp->b_actf = bp;
E 2
I 2
D 6
	if (um->um_tab.b_actf->b_actf == NULL)
		um->um_tab.b_actf->b_actl = bp;
	bp->b_forw = um->um_tab.b_actf->b_actf;
	um->um_tab.b_actf->b_actf = bp;
E 6
I 6
D 7
	if (um->um_tab.b_actf == NULL)
		um->um_tab.b_actl = bp;
	bp->b_forw = um->um_tab.b_actf;
	um->um_tab.b_actf = bp;
E 7
I 7
D 10
	if (um->um_tab.b_actf->b_actf == NULL)
		um->um_tab.b_actf->b_actl = bp;
	bp->b_forw = um->um_tab.b_actf->b_actf;
	um->um_tab.b_actf->b_actf = bp;
E 10
I 10
	if (dp->b_actf == NULL)
		dp->b_actl = bp;
	bp->b_forw = dp->b_actf;
	dp->b_actf = bp;
E 10
E 7
E 6
E 2
	rxc->rxc_state = RXS_RDERR;
	um->um_cmd = RX_RDERR;
	(void) ubago(ui);
I 2
	return;
I 13

E 13
done:
I 13
	ubadone(um);
rdone:
E 13
	um->um_tab.b_active = 0;
D 6
	um->um_tab.b_actf->b_actf = bp->b_forw;
E 6
I 6
D 7
	um->um_tab.b_actf = bp->b_forw;
E 7
I 7
	um->um_tab.b_errcnt = 0;
D 13
	ubadone(um);
E 13
D 11
	if ((bp->b_resid -= NBPS) > 0) {
E 11
I 11
	if ((sc->sc_resid -= NBPS) > 0) {
E 11
		bp->b_un.b_addr += NBPS;
I 11
D 18
#ifdef RXDEBUG
		printf("\n");
#endif
E 18
E 11
		rxstart(um);
		return;
	}
	bp->b_un.b_addr = sc->sc_uaddr;
E 7
E 6
	bp->b_resid = 0;
I 7
	bp->b_bcount = sc->sc_bcnt;
I 10
D 11
	sc->sc_offset = 0;	/* move this statement to a more appropriate place! */
E 11
I 11
	dp->b_actf = bp->av_forw;
E 11
E 10
E 7
	iodone(bp);
I 11
	sc->sc_offset = 0;
E 11
	rxc->rxc_state = RXS_IDLE;
D 7
	ubadone(um);
E 7
I 7
	um->um_tab.b_actf = dp->b_forw;
	dp->b_active = 0;
	dp->b_errcnt = 0;
D 11
	dp->b_actf = bp->av_forw;
E 11
I 11
#ifdef RXDEBUG
D 18
	printf(" old bp=0x%x, new=0x%x\n", bp, dp->b_actf);
E 18
I 18
	printf(".. bp=%x, new=%x\n", bp, dp->b_actf);
E 18
#endif
E 11
E 7
	/*
D 6
	 * If this unit has more work to do,
E 6
I 6
D 7
	 * If this unit (controller) has more work to do,
E 7
I 7
D 10
	 * If this controller has more work to do,
E 10
I 10
	 * If this unit has more work to do,
E 10
E 7
E 6
	 * start it up right away
	 */
D 3
	if (um->um_tab->b_actf->b_actf)
		rxstart(ui);
E 3
I 3
D 6
	if (um->um_tab.b_actf->b_actf)
E 6
I 6
D 10
	if (um->um_tab.b_actf)
E 6
		rxstart(um);
E 10
I 10
	if (dp->b_actf)
		rxustart(ui);

	rxstart(um);
E 10
E 3
E 2
}

/*ARGSUSED*/
I 7
D 10
#ifdef notdef
E 7
minrxphys(bp)
	struct buf *bp;
{
I 3
	struct rx_softc *sc = &rx_softc[RXUNIT(bp->b_dev)];
E 10
E 3

D 10
	if (bp->b_bcount > NBPS)
		bp->b_bcount = NBPS;
}
I 7
#endif
E 7

E 10
D 2
rxtimo()
E 2
I 2
D 8
rxtimo(dev)
	dev_t dev;
E 8
I 8
D 14
/* 
D 10
 * Wake up every second and if an interrupt is pending
 * but nothing has happened increment a counter.
E 10
I 10
 * Wake up every second, check if an interrupt is pending
D 11
 * on one of the present controllers.
 * if it is, but nothing has happened increment a counter.
E 11
I 11
 * on one (or more) of the present controllers.
 * If it is, but nothing has happened increment a counter.
E 11
E 10
 * If nothing happens for RX_MAXTIMEOUT seconds, 
D 10
 * call the interrupt routine (hoping that it will 
 * detect an error condition in the controller)
E 10
I 10
 * call the interrupt routine with the 'dead' controller
 * as an argument, thereby simulating an interrupt.
 * If this occurs, the error bit will probably be set
 * in the controller, and the interrupt routine will
 * be able to recover ( or at least report) the error
 * appropriately.
E 10
 */
E 14
D 10
rxtimo(ctlr)
	int ctlr;
E 10
I 10
D 16
rxtimo()
E 16
I 16
rxwatch()
E 16
E 10
E 8
E 2
{
D 8
	register struct rx_softc *sc = &rx_softc[RXUNIT(dev)];
E 8
I 8
D 10
	register struct rx_ctlr *rxc = &rx_ctlr[ctlr];
E 10
I 10
D 14
	register struct rx_ctlr *rxc;
E 14
I 14
	register struct uba_device *ui;
E 14
	register struct uba_ctlr *um;
D 14
	int i;
E 14
I 14
	register struct rx_softc *sc;
	struct rx_ctlr *rxc;
	int i, dopen = 0;
E 14
E 10
E 8

D 2
	if (sc->sc_openf)
		timeout(rxtimo, (caddr_t)dev, hz/2);
E 2
I 2
D 8
	if (sc->sc_flags & RXF_OPEN)
		timeout(rxtimo, (caddr_t)dev, hz);
E 2
	if (++sc->sc_tocnt < RX_MAXTIMEOUT)
E 8
I 8
D 10
	if (rxwstart > 0) 
		timeout(rxtimo, (caddr_t)ctlr, hz);
	if (++rxc->rxc_tocnt < RX_MAXTIMEOUT)
E 8
		return;
I 6
D 7
	printf("rx: timeout on dev %d\n", dev);
E 7
I 7
D 8
	printf("rx: timeout dev 0x%x\n", dev);
	sc->sc_tocnt = 0;
E 7
E 6
D 2
	sc->sc_tocnt = 0;
E 2
	rxintr(dev);
E 8
I 8
	printf("rx: timeout\n");
	rxintr(ctlr);
E 10
I 10
D 14
	if (rxwstart > 0) {
		timeout(rxtimo, (caddr_t)0, hz);
		for (i=0; i<NFX; i++) {
			um = rxminfo[i];
D 12
			if (um == 0 || um->um_alive ||	
			    um->um_tab.b_active == 0)
E 12
I 12
			if (um == 0 || um->um_alive || um->um_tab.b_active == 0)
E 12
				continue;
			rxc = &rx_ctlr[i];
			if (++rxc->rxc_tocnt < RX_MAXTIMEOUT) {
				printf("fx%d: timeout\n", i);
				rxintr(i);
			}
E 14
I 14
	for (i=0; i<NRX; i++) {
		ui = rxdinfo[i];
D 16
		sc = &rx_softc[i];
		um = ui->ui_mi;
E 16
		if (ui == 0 || ui->ui_alive == 0)
			continue;
D 16
		if ((sc->sc_open == 0) && (um->um_tab.b_active == 0)) {
E 16
I 16
		sc = &rx_softc[i];
		if ((sc->sc_open == 0) && (rxutab[i].b_active == 0)) {
E 16
			sc->sc_csbits = 0;
			continue;
E 14
		}
I 14
		dopen++;
I 16
		um = ui->ui_mi;
E 16
		rxc = &rx_ctlr[um->um_ctlr];
D 16
		if (++rxc->rxc_tocnt < RX_MAXTIMEOUT) {
			printf("fx%d: timeout\n", um->um_ctlr);
			rxintr(um->um_ctlr);
E 16
I 16
		if (++rxc->rxc_tocnt >= RX_MAXTIMEOUT) {
			rxc->rxc_tocnt = 0;
			if (um->um_tab.b_active) {	
				printf("rx%d: timeout\n", i);/* for debugging */
				rxintr(um->um_ctlr);
			}
E 16
		}
E 14
	}
I 14
	if (dopen)
D 16
		timeout(rxtimo(), (caddr_t)0, hz);
E 16
I 16
		timeout(rxwatch, (caddr_t)0, hz);
E 16
	else
		rxwstart = 0;
E 14
E 10
E 8
}

rxreset(uban)
	int uban;
{
	register struct uba_ctlr *um;
	register struct rxdevice *rxaddr;
	register int ctlr;

	for (ctlr = 0; ctlr < NFX; ctlr++) {
		if ((um = rxminfo[ctlr]) == 0 || um->um_ubanum != uban ||
		    um->um_alive == 0)
			continue;
D 5
		printf(" fx%d", ctlr);
E 5
I 5
D 7
		printf(" fx%d: ", ctlr);
E 5
		if (um->um_ubinfo) {
			printf("<%d>", (um->um_ubinfo>>28)&0xf);
E 7
I 7
D 25
		if (um->um_ubinfo)
E 25
I 25
		printf(" fx%d", ctlr);
		if (um->um_ubinfo) {
			printf("<%d>", UBAI_BDP(um->um_ubinfo));
E 25
E 7
D 2
			ubadone (um);
E 2
I 2
			um->um_ubinfo = 0;
I 25
		}
E 25
E 2
D 7
		}
E 7
		rx_ctlr[ctlr].rxc_state = RXS_IDLE;
		rxaddr = (struct rxdevice *)um->um_addr;
D 2
		rxaddr->rxcs = RXINIT;
		while ((rxaddr->rxdb&RX_IDONE) == 0)
E 2
I 2
		rxaddr->rxcs = RX_INIT;
D 9
		while ((rxaddr->rxdb&RX_DONE) == 0)
E 9
I 9
		while ((rxaddr->rxcs&RX_DONE) == 0)
E 9
E 2
			;
D 2
		(void) rxstart(um);
E 2
I 2
		rxstart(um);
E 2
	}
}

I 7
D 10
/*
 * make the world believe this is a 
 * 512b/s device
 */

E 10
E 7
D 2
rxread(dev)
E 2
I 2
rxread(dev, uio)
E 2
	dev_t dev;
I 2
	struct uio *uio;
E 2
{
D 7
	int unit = RXUNIT(dev), ctlr = rxdinfo[unit]->ui_ctlr;
I 3
	struct rx_softc *sc = &rx_softc[RXUNIT(dev)];
E 7
I 7
D 10
	int unit = RXUNIT(dev) ;
E 10
I 10
	int unit = RXUNIT(dev);
E 10
	struct rx_softc *sc = &rx_softc[unit];
E 7
E 3

D 2
	if (u.u_offset + u.u_count > RXSIZE) {
		u.u_error = ENXIO;
		return;
	}
	if (u.u_offset < 0 || (u.u_offset & SECMASK) != 0)
		goto bad;
	physio(rxstrategy, &rrxbuf[ctlr], dev, B_READ, minrxphys);
E 2
I 2
	if (uio->uio_offset + uio->uio_resid > RXSIZE)
		return (ENXIO);
	if (uio->uio_offset < 0 || (uio->uio_offset & SECMASK) != 0)
D 12
		return (EIO);
E 12
I 12
		return (ENXIO);
E 12
I 10
	sc->sc_offset = uio->uio_offset % DEV_BSIZE;
E 10
D 5
	return (physio(rxstrategy, &rrxbuf[ctlr], dev, B_READ, minrxphys));
E 5
I 5
D 7
	return (physio(rxstrategy, &rrxbuf[ctlr], dev, B_READ, minrxphys, uio));
E 7
I 7
	return (physio(rxstrategy, &rrxbuf[unit], dev, B_READ, minphys, uio));
E 7
E 5
E 2
}

D 2
rxwrite(dev)
E 2
I 2
rxwrite(dev, uio)
E 2
	dev_t dev;
I 2
	struct uio *uio;
E 2
{
D 7
	int unit = RXUNIT(dev), ctlr = rxdinfo[unit]->ui_ctlr;
I 3
	struct rx_softc *sc = &rx_softc[RXUNIT(dev)];
E 7
I 7
	int unit = RXUNIT(dev);
	struct rx_softc *sc = &rx_softc[unit];
E 7
E 3

D 2
	if (u.u_offset + u.u_count > RXSIZE) {
		u.u_error = ENXIO;
		return;
	}
	if (u.u_offset < 0 || (u.u_offset & SECMASK) != 0)
		goto bad;
	physio(rxstrategy, &rrxbuf[ctlr], dev, B_WRITE, minrxphys);
E 2
I 2
	if (uio->uio_offset + uio->uio_resid > RXSIZE)
		return (ENXIO);
	if (uio->uio_offset < 0 || (uio->uio_offset & SECMASK) != 0)
D 12
		return (EIO);
E 12
I 12
		return (ENXIO);
E 12
I 10
	sc->sc_offset = uio->uio_offset % DEV_BSIZE;
E 10
D 5
	return (physio(rxstrategy, &rrxbuf[ctlr], dev, B_WRITE, minrxphys));
E 5
I 5
D 7
	return(physio(rxstrategy, &rrxbuf[ctlr], dev, B_WRITE, minrxphys, uio));
E 7
I 7
	return(physio(rxstrategy, &rrxbuf[unit], dev, B_WRITE, minphys, uio));
E 7
E 5
E 2
}

/*
 * Control routine:
D 16
 * processes three kinds of requests:
E 16
I 16
 * processes four kinds of requests:
E 16
 *
D 5
 *	(1) Set density according to that specified by the open device.
E 5
I 5
 *	(1) Set density (i.e., format the diskette) according to 
D 16
 *		  that specified by the open device.
E 16
I 16
 *		  that specified data parameter
E 16
E 5
 *	(2) Arrange for the next sector to be written with a deleted-
 *		  data mark.
 *	(3) Report whether the last sector read had a deleted-data mark
I 16
 *	(4) Report the density of the diskette in the indicated drive
 *	    (since the density it automatically determined by the driver,
 *	     this is the only way to let an application program know the
 *	     density)
E 16
D 12
 *		  (by returning with an EIO error code if it did).
E 12
 *
 * Requests relating to deleted-data marks can be handled right here.
D 7
 * A "set density" request, however, must additionally be processed
 * through "rxstart", just like a read or write request.
E 7
I 7
 * A "set density" (format) request, however, must additionally be 
 * processed through "rxstart", just like a read or write request.
E 7
D 2
 *
 * Note that there was a bug in sys/ioctl.c which failed to pass the
 * "flag" argument to the device "ioctl" routine.  This bug had to be
 * fixed to allow "rxioctl" to determine whether the device is open
 * for input or output, since certain control calls are legal only for
 * input or only for output.
E 2
 */
I 16

E 16
/*ARGSUSED3*/
D 2
rxioctl(dev, cmd, addr, flag)
E 2
I 2
rxioctl(dev, cmd, data, flag)
E 2
	dev_t dev;
D 16
	int cmd;
E 16
D 2
	caddr_t addr;
E 2
I 2
	caddr_t data;
E 2
D 16
	int flag;
E 16
{   
	int unit = RXUNIT(dev);
	struct rx_softc *sc = &rx_softc[unit];
D 2
	register struct buf *bp;
	int ctlr, s;
E 2

D 16
	switch (cmd) {
E 16
I 16
D 18
	switch (cmd&RXIOC_MASK) {
E 18
I 18
	switch (cmd) {
E 18
E 16

D 2
	case IO_FORMAT:
		break;

	case IO_WDDS:
E 2
I 2
	case RXIOC_FORMAT:
I 16
D 18
#ifdef notdef	/* temporarily removed (the flag argument is */
		/* is actually always zero at this point) */
E 18
E 16
E 2
		if ((flag&FWRITE) == 0)
D 2
			u.u_error = EBADF;
		else
			sc->sc_flags |= RXF_USEWDDS;
		return;
E 2
I 2
			return (EBADF);
I 16
D 18
#endif
E 18
E 16
I 12
D 19
		if (sc->sc_open > 1 )
E 19
I 19
		if (sc->sc_open > 1)
E 19
D 16
			return(EBUSY);
E 16
I 16
			return (EBUSY);
E 16
I 13
D 17
		sc->sc_csbits |= *(int *)data ? RX_DDEN : RX_SDEN;
E 17
I 17
		if (*(int *)data)
			sc->sc_csbits |= RX_DDEN;
		else
			sc->sc_csbits &= ~RX_DDEN;
E 17
E 13
E 12
D 3
		return (rxformat(unit));
E 3
I 3
		return (rxformat(dev));
E 3
E 2

D 2
	case IO_RDDSMK:
		if ((flag&FREAD) == 0)
			u.u_error = EBADF;
		else if (sc->sc_flags & RXF_DDMK)
			u.u_error = EIO;
		return;
E 2
I 2
	case RXIOC_WDDS:
		sc->sc_flags |= RXF_USEWDDS;
		return (0);
E 2

D 2
	default:
		u.u_error = ENXIO;
		return;
E 2
I 2
	case RXIOC_RDDSMK:
		*(int *)data = sc->sc_flags & RXF_DDMK;
		return (0);
I 13

	case RXIOC_GDENS:
		*(int *)data = sc->sc_csbits & RX_DDEN;
		return (0);
E 13
E 2
	}
I 2
	return (ENXIO);
}
E 2

D 2
	if ((flag&FWRITE) == 0) {
		u.u_error = EBADF;
		return;
	}
	ctl = rxdinfo[unit]->ui_mi->um_ctlr;
E 2
I 2
/*
 * Initiate a format command.
 */
D 3
rxformat(unit)
	int unit;
E 3
I 3
rxformat(dev)
	dev_t dev;
E 3
{
D 3
	int ctlr = rxdinfo[unit]->ui_mi->um_ctlr;
E 3
I 3
D 7
	int ctlr = rxdinfo[RXUNIT(dev)]->ui_mi->um_ctlr;
E 7
I 7
	int unit = RXUNIT(dev);
E 7
E 3
	struct buf *bp;
D 3
	struct rx_softc *sc = &rx_softc[unit];
E 3
I 3
D 7
	struct rx_softc *sc = &rx_softc[RXUNIT(dev)];
E 7
I 7
	struct rx_softc *sc = &rx_softc[unit];
E 7
E 3
D 25
	int s, error = 0;
E 25
I 25
	int error = 0;
E 25

E 2
D 6
	bp = &rrxbuf[ctlr];
E 6
I 6
D 7
	bp = &rrxbuf[RXUNIT(dev)];
E 7
I 7
	bp = &rrxbuf[unit];
E 7
E 6
D 13
	s = spl5();
	while (bp->b_flags & B_BUSY)
		sleep(bp, PRIBIO);
E 13
	bp->b_flags = B_BUSY | B_CTRL;
D 13
	splx(s);
E 13
I 2
D 12
	sc->sc_flags = RXS_FORMAT;
E 12
I 12
	sc->sc_flags = RXF_FORMAT | RXF_LOCK;
E 12
E 2
	bp->b_dev = dev;
	bp->b_error = 0;
D 2
	u.u_offset = 0;
	bp->b_bcount = NBPS;
E 2
I 2
D 13
	bp->b_resid = 0;
E 2
	rxstrategy (bp);
E 13
I 13
	bp->b_blkno = 0;
	rxstrategy(bp);
E 13
	iowait(bp);
I 2
	if (bp->b_flags & B_ERROR)
		error = bp->b_error;
E 2
	bp->b_flags &= ~B_BUSY;
D 2
	wakeup(bp);
E 2
I 2
D 13
	wakeup((caddr_t)bp);
E 13
I 12
	sc->sc_flags &= ~RXF_LOCK;
E 12
	return (error);
I 18
}

/*
 * A permanent hard error condition has occured,
 * purge the buffer queue
 */
rxpurge(um)
	register struct uba_ctlr *um;
{
	register struct buf *bp, *dp;

	dp = um->um_tab.b_actf;
	while (dp->b_actf) {
		dp->b_errcnt++;
		bp = dp->b_actf;
		bp->b_error = EIO;
		bp->b_flags |= B_ERROR;
		iodone(bp);
		dp->b_actf = bp->av_forw;
	}
E 18
E 2
}
#endif
E 1
