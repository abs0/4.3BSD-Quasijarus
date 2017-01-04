h60010
s 00000/00000/00697
d D 7.1 88/05/31 08:42:10 karels 9 8
c bring up to revision 7 for tahoe release
e
s 00005/00002/00692
d D 1.6 88/05/26 09:41:29 karels 8 6
c lint
e
s 00003/00001/00693
d R 7.1 88/05/21 18:32:59 karels 7 6
c bring up to revision 7 for tahoe release
e
s 00003/00014/00691
d D 1.5 86/12/23 08:33:23 sam 6 5
c intermediate i/o buffer must be physically contiguous for DMA
e
s 00023/00022/00682
d D 1.4 86/12/15 20:25:11 sam 5 4
c lint
e
s 00501/00496/00203
d D 1.3 86/12/11 08:29:21 sam 4 3
c put tabs back; change address modifier since i/o buffer 
c might be anywhere in physical memory (also avoid overlap with dumb 
c 24-bit devices); fix backwards mtpr; autoconfig interrupt vector
e
s 00002/00001/00697
d D 1.2 86/11/29 13:43:14 sam 3 1
c cleanups
e
s 00001/00000/00698
d R 1.2 86/11/29 13:42:07 sam 2 1
c missing include
e
s 00698/00000/00000
d D 1.1 86/11/29 12:09:52 sam 1 0
c date and time created 86/11/29 12:09:52 by sam
e
u
U
t
T
I 1
D 8
/*	%M%	%I%	%E%	*/
E 8
I 8
/*
 *	%W% (Berkeley) %G%
 */
E 8

#include "ik.h"
#if NIK > 0
/*
 * PS300/IKON DR-11W Device Driver.
 */
#include "param.h"
#include "buf.h"
#include "cmap.h"
#include "conf.h"
#include "dir.h"
#include "dkstat.h"
#include "map.h"
#include "systm.h"
#include "user.h"
#include "vmmac.h"
#include "proc.h"
#include "uio.h"
#include "kernel.h"
I 3
#include "syslog.h"
E 3

#include "../tahoe/mtpr.h"
#include "../tahoe/pte.h"

#include "../tahoevba/vbavar.h"
#include "../tahoevba/ikreg.h"
#include "../tahoevba/psreg.h"
#include "../tahoevba/psproto.h"

D 4
int     ikprobe(), ikattach(), iktimer();
struct  vba_device *ikinfo[NIK];
long    ikstd[] = { 0 };
struct  vba_driver ikdriver = { ikprobe, 0, ikattach, 0, ikstd, "ik", ikinfo };
E 4
I 4
int	ikprobe(), ikattach(), iktimer();
struct	vba_device *ikinfo[NIK];
long	ikstd[] = { 0 };
struct	vba_driver ikdriver = { ikprobe, 0, ikattach, 0, ikstd, "ik", ikinfo };
E 4

D 4
#define splik()         spl4()
E 4
I 4
#define splik()		spl4()
E 4
/*
 * Devices are organized in pairs with the odd valued
 * device being used for ``diagnostic'' purposes.  That
 * is diagnostic devices don't get auto-attach'd and
 * detach'd on open-close.
 */
D 4
#define IKUNIT(dev)     (minor(dev) >> 1)
#define IKDIAG(dev)     (minor(dev) & 01)       /* is a diagnostic unit */
E 4
I 4
#define IKUNIT(dev)	(minor(dev) >> 1)
#define IKDIAG(dev)	(minor(dev) & 01)	/* is a diagnostic unit */
E 4

D 4
struct  ik_softc {
        uid_t   is_uid;         /* uid of open processes */
        u_short is_timeout;     /* current timeout (seconds) */
        u_short is_error;       /* internal error codes */
        u_short is_flags;
#define IKF_ATTACHED    0x1     /* unit is attached (not used yet) */
        union {
                u_short w[2];
                u_long  l;
        } is_nameaddr;          /* address of last symbol lookup */
	caddr_t	is_buf;		/* i/o buffer XXX */
E 4
I 4
struct	ik_softc {
	uid_t	is_uid;		/* uid of open processes */
	u_short is_timeout;	/* current timeout (seconds) */
	u_short is_error;	/* internal error codes */
	u_short is_flags;
#define IKF_ATTACHED	0x1	/* unit is attached (not used yet) */
	union {
		u_short w[2];
		u_long	l;
	} is_nameaddr;		/* address of last symbol lookup */
D 6
	caddr_t is_buf;		/* i/o buffer XXX */
E 6
I 6
	caddr_t is_buf[PS_MAXDMA];/* i/o buffer XXX */
E 6
E 4
} ik_softc[NIK];

D 4
struct  buf iktab[NIK];         /* unit command queue headers */
struct  buf rikbuf[NIK];        /* buffers for read/write operations */
struct  buf cikbuf[NIK];        /* buffers for control operations */
E 4
I 4
struct	buf iktab[NIK];		/* unit command queue headers */
struct	buf rikbuf[NIK];	/* buffers for read/write operations */
struct	buf cikbuf[NIK];	/* buffers for control operations */
E 4

/* buf overlay definitions */
D 4
#define b_command       b_resid
E 4
I 4
#define b_command	b_resid
E 4

D 4
int     ikdiotimo = PS_DIOTIMO; /* dio polling timeout */
int     iktimeout = PS_TIMEOUT; /* attention/dma timeout (in hz) */
E 4
I 4
int	ikdiotimo = PS_DIOTIMO; /* dio polling timeout */
int	iktimeout = PS_TIMEOUT; /* attention/dma timeout (in hz) */
E 4

ikprobe(reg, vi)
D 4
        caddr_t reg;
E 4
I 4
	caddr_t reg;
E 4
	struct vba_device *vi;
{
D 4
        register int br, cvec;          /* r12, r11 */
E 4
I 4
	register int br, cvec;		/* r12, r11 */
E 4
	register struct ikdevice *ik;

I 5
#ifdef lint
	br = 0; cvec = br; br = cvec;
	ikintr(0);
#endif
E 5
D 4
        if (badaddr(reg, 2))
                return (0);
E 4
I 4
	if (badaddr(reg, 2))
		return (0);
E 4
	ik = (struct ikdevice *)reg;
	ik->ik_vec = --vi->ui_hd->vh_lastiv;
D 4
        /*
         * Try and reset the PS300.  Since this
         * won't work if it's powered off, we
         * can't use sucess/failure to decide
         * if the device is present.
         */
E 4
I 4
	/*
D 6
	 * Use extended non-privileged address modifier to
	 * insure DMA to/from intermediate buffer works when
	 * buffer is not in lower 16Mb of memory (also avoids
	 * other 24-bit devices mapped into overlapping regions).
E 6
I 6
	 * Use extended non-privileged address modifier
	 * to avoid address overlap with 24-bit devices.
E 6
	 */
	ik->ik_mod = 0xf1;			/* address modifier */
	/*
	 * Try and reset the PS300.  Since this
	 * won't work if it's powered off, we
	 * can't use sucess/failure to decide
	 * if the device is present.
	 */
E 4
	br = 0;
D 4
        if (!psreset(ik, IKCSR_IENA) || br == 0)
E 4
I 4
	(void) psreset(ik, IKCSR_IENA);
	if (br == 0)				/* XXX */
E 4
		br = 0x18, cvec = ik->ik_vec;	/* XXX */
D 4
        return (sizeof (struct ikdevice));
E 4
I 4
	return (sizeof (struct ikdevice));
E 4
}

/*
 * Perform a ``hard'' reset.
 */
psreset(ik, iena)
D 4
        register struct ikdevice *ik;
E 4
I 4
	register struct ikdevice *ik;
E 4
{

D 4
        ik->ik_csr = IKCSR_MCLR|iena;
        DELAY(10000);
        ik->ik_csr = IKCSR_FNC3;
        return (dioread(ik) == PS_RESET);
E 4
I 4
	ik->ik_csr = IKCSR_MCLR|iena;
	DELAY(10000);
	ik->ik_csr = IKCSR_FNC3|iena;
	if (!iena)
		return (dioread(ik) == PS_RESET);
	return (1);
E 4
}

ikattach(vi)
D 4
        struct vba_device *vi;
E 4
I 4
	struct vba_device *vi;
E 4
{
D 4
        register struct ikdevice *ik;
E 4

D 4
        ikinfo[vi->ui_unit] = vi;
        ik = (struct ikdevice *)vi->ui_addr;
        ik->ik_vec = IKVEC_BASE + vi->ui_unit;  /* interrupt vector */
        ik->ik_mod = IKMOD_STD;                 /* address modifier */
        ik_softc[vi->ui_unit].is_uid = -1;
E 4
I 4
	ik_softc[vi->ui_unit].is_uid = -1;
E 4
}

/*
 * Open a PS300 and attach.  We allow multiple
 * processes with the same uid to share a unit.
 */
/*ARGSUSED*/
ikopen(dev, flag)
D 4
        dev_t dev;
        int flag;
E 4
I 4
	dev_t dev;
	int flag;
E 4
{
D 4
        register int unit = IKUNIT(dev);
        register struct ik_softc *sc;
        struct vba_device *vi;
        struct ikdevice *ik;
        int reset;
E 4
I 4
	register int unit = IKUNIT(dev);
	register struct ik_softc *sc;
	struct vba_device *vi;
	struct ikdevice *ik;
	int reset;
E 4

D 4
        if (unit >= NIK || (vi = ikinfo[unit]) == 0 || vi->ui_alive == 0)
                return (ENXIO);
        sc = &ik_softc[unit];
        if (sc->is_uid != -1 && sc->is_uid != u.u_uid)
                return (EBUSY);
        if (sc->is_uid == -1) {
E 4
I 4
	if (unit >= NIK || (vi = ikinfo[unit]) == 0 || vi->ui_alive == 0)
		return (ENXIO);
	sc = &ik_softc[unit];
D 5
	if (sc->is_uid != -1 && sc->is_uid != u.u_uid)
E 5
I 5
	if (sc->is_uid != (uid_t)-1 && sc->is_uid != u.u_uid)
E 5
		return (EBUSY);
D 5
	if (sc->is_uid == -1) {
E 5
I 5
	if (sc->is_uid == (uid_t)-1) {
E 5
E 4
D 6
		sc->is_buf = (caddr_t)wmemall(vmemall, PS_MAXDMA);
		if (sc->is_buf == 0)
			return (ENOMEM);
E 6
D 4
                sc->is_timeout = 0;
                timeout(iktimer, unit, hz);
                /*
                 * Perform PS300 attach for first process.
                 */
                if (!IKDIAG(dev)) {
                        reset = 0;
                again:
                        if (ikcommand(dev, PS_ATTACH, 1)) {
                                /*
                                 * If attach fails, perform a hard
                                 * reset once, then retry the command.
                                 */
                                ik = (struct ikdevice *)ikinfo[unit]->ui_addr;
                                if (!reset++ && psreset(ik, 0))
                                        goto again;
                                untimeout(iktimer, unit);
E 4
I 4
		sc->is_timeout = 0;
D 5
		timeout(iktimer, unit, hz);
E 5
I 5
		timeout(iktimer, (caddr_t)unit, hz);
E 5
		/*
		 * Perform PS300 attach for first process.
		 */
		if (!IKDIAG(dev)) {
			reset = 0;
		again:
			if (ikcommand(dev, PS_ATTACH, 1)) {
				/*
				 * If attach fails, perform a hard
				 * reset once, then retry the command.
				 */
				ik = (struct ikdevice *)ikinfo[unit]->ui_addr;
				if (!reset++ && psreset(ik, 0))
					goto again;
D 5
				untimeout(iktimer, unit);
E 5
I 5
				untimeout(iktimer, (caddr_t)unit);
E 5
E 4
D 6
				wmemfree(sc->is_buf, PS_MAXDMA);
				sc->is_buf = 0;
E 6
D 4
                                return (EIO);
                        }
                }
                sc->is_uid = u.u_uid;
        }
        return (0);
}
E 4
I 4
				return (EIO);
			}
		}
		sc->is_uid = u.u_uid;
	}
	return (0);
}
E 4

/*ARGSUSED*/
ikclose(dev, flag)
D 4
        dev_t dev;
        int flag;
E 4
I 4
	dev_t dev;
	int flag;
E 4
{
D 4
        int unit = IKUNIT(dev);
E 4
I 4
	int unit = IKUNIT(dev);
E 4
	register struct ik_softc *sc = &ik_softc[unit];

D 4
        if (!IKDIAG(dev))
                (void) ikcommand(dev, PS_DETACH, 1);    /* auto detach */
        sc->is_uid = -1;
E 4
I 4
	if (!IKDIAG(dev))
		(void) ikcommand(dev, PS_DETACH, 1);	/* auto detach */
	sc->is_uid = -1;
E 4
D 6
	if (sc->is_buf) {
		wmemfree(sc->is_buf, PS_MAXDMA);
		sc->is_buf = 0;
	}
E 6
D 4
        untimeout(iktimer, unit);
E 4
I 4
D 5
	untimeout(iktimer, unit);
E 5
I 5
	untimeout(iktimer, (caddr_t)unit);
E 5
E 4
}

ikread(dev, uio)
D 4
        dev_t dev;
        struct uio *uio;
E 4
I 4
	dev_t dev;
	struct uio *uio;
E 4
{

D 4
        return (ikrw(dev, uio, B_READ));
E 4
I 4
	return (ikrw(dev, uio, B_READ));
E 4
}

ikwrite(dev, uio)
D 4
        dev_t dev;
        struct uio *uio;
E 4
I 4
	dev_t dev;
	struct uio *uio;
E 4
{

D 4
        return (ikrw(dev, uio, B_WRITE));
E 4
I 4
	return (ikrw(dev, uio, B_WRITE));
E 4
}

/*
 * Take read/write request and perform physical i/o
 * transaction with PS300.  This involves constructing
 * a physical i/o request vector based on the uio
 * vector, performing the dma, and, finally, moving
 * the data to it's final destination (because of CCI
 * VERSAbus bogosities).
 */
ikrw(dev, uio, rw)
D 4
        dev_t dev;
        register struct uio *uio;
        int rw;
E 4
I 4
	dev_t dev;
	register struct uio *uio;
	int rw;
E 4
{
D 4
        int error, unit = IKUNIT(dev), s, wrcmd;
        register struct buf *bp;
        register struct iovec *iov;
        register struct psalist *ap;
        struct ik_softc *sc = &ik_softc[unit];
E 4
I 4
	int error, unit = IKUNIT(dev), s, wrcmd;
	register struct buf *bp;
	register struct iovec *iov;
	register struct psalist *ap;
	struct ik_softc *sc = &ik_softc[unit];
E 4

D 4
        if (unit >= NIK)
                return (ENXIO);
        bp = &rikbuf[unit];
        error = 0, iov = uio->uio_iov, wrcmd = PS_WRPHY;
        for (; !error && uio->uio_iovcnt; iov++, uio->uio_iovcnt--) { 
                /*
                 * Hack way to set PS300 address w/o doing an lseek
                 * and specify write physical w/ refresh synchronization.
                 */
                if (iov->iov_len == 0) {
                        if ((int)iov->iov_base&PSIO_SYNC)
                                wrcmd = PS_WRPHY_SYNC;
                        uio->uio_offset = (int)iov->iov_base & ~PSIO_SYNC;
                        continue;
                }
                if (iov->iov_len > PS_MAXDMA) {
                        sc->is_error = PSERROR_INVALBC, error = EINVAL;
                        continue;
                }
                if ((int)uio->uio_offset&01) {
                        sc->is_error = PSERROR_BADADDR, error = EINVAL;
                        continue;
                }
                s = splbio();
                while (bp->b_flags&B_BUSY) {
                        bp->b_flags |= B_WANTED;
                        sleep((caddr_t)bp, PRIBIO+1);
                }
                splx(s);
                bp->b_flags = B_BUSY | rw;
                /*
                 * Construct address descriptor in buffer.
                 */
                ap = (struct psalist *)sc->is_buf;
                ap->nblocks = 1;
                /* work-around dr300 word swapping */
                ap->addr[0] = uio->uio_offset & 0xffff;
                ap->addr[1] = uio->uio_offset >> 16;
                ap->wc = (iov->iov_len + 1) >> 1;
                if (rw == B_WRITE) {
                        error = copyin(iov->iov_base, (caddr_t)&ap[1],
                            iov->iov_len);
                        if (!error)
                                error = ikcommand(dev, wrcmd,
                                    iov->iov_len + sizeof (*ap));
                } else {
                        caddr_t cp;
                        int len;
E 4
I 4
	if (unit >= NIK)
		return (ENXIO);
	bp = &rikbuf[unit];
	error = 0, iov = uio->uio_iov, wrcmd = PS_WRPHY;
	for (; !error && uio->uio_iovcnt; iov++, uio->uio_iovcnt--) { 
		/*
		 * Hack way to set PS300 address w/o doing an lseek
		 * and specify write physical w/ refresh synchronization.
		 */
		if (iov->iov_len == 0) {
			if ((int)iov->iov_base&PSIO_SYNC)
				wrcmd = PS_WRPHY_SYNC;
			uio->uio_offset = (int)iov->iov_base & ~PSIO_SYNC;
			continue;
		}
		if (iov->iov_len > PS_MAXDMA) {
			sc->is_error = PSERROR_INVALBC, error = EINVAL;
			continue;
		}
		if ((int)uio->uio_offset&01) {
			sc->is_error = PSERROR_BADADDR, error = EINVAL;
			continue;
		}
		s = splbio();
		while (bp->b_flags&B_BUSY) {
			bp->b_flags |= B_WANTED;
			sleep((caddr_t)bp, PRIBIO+1);
		}
		splx(s);
		bp->b_flags = B_BUSY | rw;
		/*
		 * Construct address descriptor in buffer.
		 */
		ap = (struct psalist *)sc->is_buf;
		ap->nblocks = 1;
		/* work-around dr300 word swapping */
		ap->addr[0] = uio->uio_offset & 0xffff;
		ap->addr[1] = uio->uio_offset >> 16;
		ap->wc = (iov->iov_len + 1) >> 1;
		if (rw == B_WRITE) {
			error = copyin(iov->iov_base, (caddr_t)&ap[1],
D 5
			    iov->iov_len);
E 5
I 5
			    (unsigned)iov->iov_len);
E 5
			if (!error)
				error = ikcommand(dev, wrcmd,
				    iov->iov_len + sizeof (*ap));
		} else {
			caddr_t cp;
			int len;
E 4

D 4
                        error = ikcommand(dev, PS_RDPHY, sizeof (*ap));
                        cp = (caddr_t)&ap[1], len = iov->iov_len;
                        for (; len > 0; len -= NBPG, cp += NBPG)
                                mtpr(cp, P1DC);
                        if (!error)
                                error = copyout((caddr_t)&ap[1], iov->iov_base,
                                    iov->iov_len);
                }
                (void) splbio();
                if (bp->b_flags&B_WANTED)
                        wakeup((caddr_t)bp);
                splx(s);
                uio->uio_resid -= iov->iov_len;
                uio->uio_offset += iov->iov_len;
                bp->b_flags &= ~(B_BUSY|B_WANTED);
        }
        return (error);
}
E 4
I 4
			error = ikcommand(dev, PS_RDPHY, sizeof (*ap));
			cp = (caddr_t)&ap[1], len = iov->iov_len;
			for (; len > 0; len -= NBPG, cp += NBPG)
				mtpr(P1DC, cp);
			if (!error)
				error = copyout((caddr_t)&ap[1], iov->iov_base,
D 5
				    iov->iov_len);
E 5
I 5
				    (unsigned)iov->iov_len);
E 5
		}
		(void) splbio();
		if (bp->b_flags&B_WANTED)
			wakeup((caddr_t)bp);
		splx(s);
		uio->uio_resid -= iov->iov_len;
		uio->uio_offset += iov->iov_len;
		bp->b_flags &= ~(B_BUSY|B_WANTED);
	}
	return (error);
}
E 4

/*
 * Perform a PS300 command.
 */
ikcommand(dev, com, count)
D 4
        dev_t dev;
        int com, count;
E 4
I 4
	dev_t dev;
	int com, count;
E 4
{
D 4
        register struct buf *bp;
        register int s;
E 4
I 4
	register struct buf *bp;
	register int s;
E 4

D 4
        bp = &cikbuf[IKUNIT(dev)];
        s = splik();
        while (bp->b_flags&B_BUSY) {
                if (bp->b_flags&B_DONE)
                        break;
                bp->b_flags |= B_WANTED;
                sleep((caddr_t)bp, PRIBIO);
        }
        bp->b_flags = B_BUSY|B_READ;
        splx(s);
        bp->b_dev = dev;
        bp->b_command = com;
        bp->b_bcount = count;
        ikstrategy(bp);
        biowait(bp);
        if (bp->b_flags&B_WANTED)
                wakeup((caddr_t)bp);
        bp->b_flags &= B_ERROR;
        return (geterror(bp));
E 4
I 4
	bp = &cikbuf[IKUNIT(dev)];
	s = splik();
	while (bp->b_flags&B_BUSY) {
		if (bp->b_flags&B_DONE)
			break;
		bp->b_flags |= B_WANTED;
		sleep((caddr_t)bp, PRIBIO);
	}
	bp->b_flags = B_BUSY|B_READ;
	splx(s);
	bp->b_dev = dev;
	bp->b_command = com;
	bp->b_bcount = count;
	ikstrategy(bp);
	biowait(bp);
	if (bp->b_flags&B_WANTED)
		wakeup((caddr_t)bp);
	bp->b_flags &= B_ERROR;
	return (geterror(bp));
E 4
}

/*
 * Physio strategy routine
 */
ikstrategy(bp)
D 4
        register struct buf *bp;
E 4
I 4
	register struct buf *bp;
E 4
{
D 4
        register struct buf *dp;
E 4
I 4
	register struct buf *dp;
E 4

D 4
        /*
         * Put request at end of controller queue.
         */
        dp = &iktab[IKUNIT(bp->b_dev)];
        bp->av_forw = NULL;
        (void) splik();
        if (dp->b_actf != NULL) {
                dp->b_actl->av_forw = bp;
                dp->b_actl = bp;
        } else
                dp->b_actf = dp->b_actl = bp;
        if (!dp->b_active)
                ikstart(dp);
        (void) spl0();
E 4
I 4
	/*
	 * Put request at end of controller queue.
	 */
	dp = &iktab[IKUNIT(bp->b_dev)];
	bp->av_forw = NULL;
	(void) splik();
	if (dp->b_actf != NULL) {
		dp->b_actl->av_forw = bp;
		dp->b_actl = bp;
	} else
		dp->b_actf = dp->b_actl = bp;
	if (!dp->b_active)
		ikstart(dp);
	(void) spl0();
E 4
}

/*
 * Start the next command on the controller's queue.
 */
ikstart(dp)
D 4
        register struct buf *dp;
E 4
I 4
	register struct buf *dp;
E 4
{
D 4
        register struct buf *bp;
        register struct ikdevice *ik;
        register struct ik_softc *sc;
        register struct psalist *ap;
        u_short bc, csr;
        u_int addr;
        int unit;
E 4
I 4
	register struct buf *bp;
	register struct ikdevice *ik;
	register struct ik_softc *sc;
D 5
	register struct psalist *ap;
E 5
	u_short bc, csr;
	u_int addr;
	int unit;
E 4

loop:
D 4
        /*
         * Pull a request off the controller queue
         */
        if ((bp = dp->b_actf) == NULL) {
                dp->b_active = 0;
                return;
        }
        /*
         * Mark controller busy and process this request.
         */
        dp->b_active = 1;
        unit = IKUNIT(bp->b_dev);
        sc = &ik_softc[unit];
        ik = (struct ikdevice *)ikinfo[unit]->ui_addr;
        switch (bp->b_command) {
E 4
I 4
	/*
	 * Pull a request off the controller queue
	 */
	if ((bp = dp->b_actf) == NULL) {
		dp->b_active = 0;
		return;
	}
	/*
	 * Mark controller busy and process this request.
	 */
	dp->b_active = 1;
	unit = IKUNIT(bp->b_dev);
	sc = &ik_softc[unit];
	ik = (struct ikdevice *)ikinfo[unit]->ui_addr;
D 5
	switch (bp->b_command) {
E 5
I 5
	switch ((int)bp->b_command) {
E 5
E 4

D 4
        case PS_ATTACH:         /* logical unit attach */
        case PS_DETACH:         /* logical unit detach */
        case PS_LOOKUP:         /* name lookup */
        case PS_RDPHY:          /* physical i/o read */
        case PS_WRPHY:          /* physical i/o write */
        case PS_WRPHY_SYNC:     /* physical i/o write w/ sync */
                /*
                 * Handshake command and, optionally,
                 * byte count and byte swap flag.
                 */
                if (sc->is_error = diowrite(ik, bp->b_command))
                        goto bad;
                if (bp->b_command < PS_DETACH) {
                        if (sc->is_error = diowrite(ik, bp->b_bcount))
                                goto bad;
                        if (sc->is_error = diowrite(ik, 0 /* !swab */))
                                goto bad;
                }
                /*
                 * Set timeout and wait for an attention interrupt.
                 */
                sc->is_timeout = iktimeout;
                return;
E 4
I 4
	case PS_ATTACH:		/* logical unit attach */
	case PS_DETACH:		/* logical unit detach */
	case PS_LOOKUP:		/* name lookup */
	case PS_RDPHY:		/* physical i/o read */
	case PS_WRPHY:		/* physical i/o write */
	case PS_WRPHY_SYNC:	/* physical i/o write w/ sync */
		/*
		 * Handshake command and, optionally,
		 * byte count and byte swap flag.
		 */
D 5
		if (sc->is_error = diowrite(ik, bp->b_command))
E 5
I 5
		if (sc->is_error = diowrite(ik, (u_short)bp->b_command))
E 5
			goto bad;
		if (bp->b_command < PS_DETACH) {
D 5
			if (sc->is_error = diowrite(ik, bp->b_bcount))
E 5
I 5
			if (sc->is_error = diowrite(ik, (u_short)bp->b_bcount))
E 5
				goto bad;
D 5
			if (sc->is_error = diowrite(ik, 0 /* !swab */))
E 5
I 5
			if (sc->is_error = diowrite(ik, (u_short)0 /* !swab */))
E 5
				goto bad;
		}
		/*
		 * Set timeout and wait for an attention interrupt.
		 */
		sc->is_timeout = iktimeout;
		return;
E 4

D 4
        case PS_DMAOUT:         /* dma data host->PS300 */
                bc = bp->b_bcount;
                csr = IKCSR_CYCLE;
                break;
E 4
I 4
	case PS_DMAOUT:		/* dma data host->PS300 */
		bc = bp->b_bcount;
		csr = IKCSR_CYCLE;
		break;
E 4

D 4
        case PS_DMAIN:          /* dma data PS300->host */
                bc = bp->b_bcount;
                csr = IKCSR_CYCLE|IKCSR_FNC1;
                break;
E 4
I 4
	case PS_DMAIN:		/* dma data PS300->host */
		bc = bp->b_bcount;
		csr = IKCSR_CYCLE|IKCSR_FNC1;
		break;
E 4

D 4
        default:
                log(LOG_ERR, "ik%d: bad cmd %x\n", unit, bp->b_command);
                sc->is_error = PSERROR_BADCMD;
                goto bad;
        }
        /* initiate dma transfer */
        addr = vtoph((struct proc *)0, sc->is_buf);
        ik->ik_bahi = addr >> 17;
        ik->ik_balo = (addr >> 1) & 0xffff;
        ik->ik_wc = ((bc + 1) >> 1) - 1;        /* round & convert */
        ik->ik_pulse = IKPULSE_RATTF|IKPULSE_RDMAF;
        sc->is_timeout = iktimeout;
        ik->ik_csr = IKCSR_IENA|IKCSR_GO|csr;
        return;
E 4
I 4
	default:
		log(LOG_ERR, "ik%d: bad cmd %x\n", unit, bp->b_command);
		sc->is_error = PSERROR_BADCMD;
		goto bad;
	}
	/* initiate dma transfer */
D 5
	addr = vtoph((struct proc *)0, sc->is_buf);
E 5
I 5
	addr = vtoph((struct proc *)0, (unsigned)sc->is_buf);
E 5
	ik->ik_bahi = addr >> 17;
	ik->ik_balo = (addr >> 1) & 0xffff;
	ik->ik_wc = ((bc + 1) >> 1) - 1;	/* round & convert */
	ik->ik_pulse = IKPULSE_RATTF|IKPULSE_RDMAF;
	sc->is_timeout = iktimeout;
	ik->ik_csr = IKCSR_IENA|IKCSR_GO|csr;
	return;
E 4
bad:
D 4
        bp->b_flags |= B_ERROR;
        dp->b_actf = bp->av_forw;               /* remove from queue */
        biodone(bp);
        goto loop;
E 4
I 4
	bp->b_flags |= B_ERROR;
	dp->b_actf = bp->av_forw;		/* remove from queue */
	biodone(bp);
	goto loop;
E 4
}

#define FETCHWORD(i) { \
D 4
        int v; \
E 4
I 4
D 5
	int v; \
E 4
\
E 5
D 4
        v = dioread(ik); \
        if (v == -1) { \
                sc->is_error = PSERROR_NAMETIMO; \
                goto bad; \
        } \
        sc->is_nameaddr.w[i] = v; \
E 4
I 4
	v = dioread(ik); \
	if (v == -1) { \
		sc->is_error = PSERROR_NAMETIMO; \
		goto bad; \
	} \
	sc->is_nameaddr.w[i] = v; \
E 4
}

/*
 * Process a device interrupt.
 */
ikintr(ikon)
D 4
        int ikon;
E 4
I 4
	int ikon;
E 4
{
D 4
        register struct ikdevice *ik;
        register struct buf *bp, *dp;
        struct ik_softc *sc;
        register u_short data;
        u_short i, v;
E 4
I 4
	register struct ikdevice *ik;
	register struct buf *bp, *dp;
	struct ik_softc *sc;
	register u_short data;
D 5
	u_short i, v;
E 5
I 5
	int v;
E 5
E 4

D 4
        /* should go by controller, but for now... */
        if (ikinfo[ikon] == 0)
                return;
        ik = (struct ikdevice *)ikinfo[ikon]->ui_addr;
        /*
         * Discard all non-attention interrupts.  The
         * interrupts we're throwing away should all be
         * associated with DMA completion.
         */
        data = ik->ik_data;
        if ((ik->ik_csr&(IKCSR_ATTF|IKCSR_STATC)) != IKCSR_ATTF) {
                ik->ik_pulse = IKPULSE_RATTF|IKPULSE_RDMAF|IKPULSE_SIENA;
                return;
        }
        /*
         * Fetch attention code immediately.
         */
        ik->ik_csr = IKCSR_RATTF|IKCSR_RDMAF|IKCSR_FNC1;
        ik->ik_pulse = IKPULSE_FNC2;
        /*
         * Get device and block structures, and a pointer
         * to the vba_device for the device.  We receive an
         * unsolicited interrupt whenever the PS300 is power
         * cycled (so ignore it in that case).
         */
        dp = &iktab[ikon];
        if ((bp = dp->b_actf) == NULL) {
                if (PS_CODE(data) != PS_RESET)          /* power failure */
                        log(LOG_WARNING, "ik%d: spurious interrupt, code %x\n",
                            ikon, data);
                goto enable;
        }
        sc = &ik_softc[IKUNIT(bp->b_dev)];
        sc->is_timeout = 0;                     /* disable timer */
        switch (PS_CODE(data)) {
E 4
I 4
	/* should go by controller, but for now... */
	if (ikinfo[ikon] == 0)
		return;
	ik = (struct ikdevice *)ikinfo[ikon]->ui_addr;
	/*
	 * Discard all non-attention interrupts.  The
	 * interrupts we're throwing away should all be
	 * associated with DMA completion.
	 */
	data = ik->ik_data;
	if ((ik->ik_csr&(IKCSR_ATTF|IKCSR_STATC)) != IKCSR_ATTF) {
		ik->ik_pulse = IKPULSE_RATTF|IKPULSE_RDMAF|IKPULSE_SIENA;
		return;
	}
	/*
	 * Fetch attention code immediately.
	 */
	ik->ik_csr = IKCSR_RATTF|IKCSR_RDMAF|IKCSR_FNC1;
	ik->ik_pulse = IKPULSE_FNC2;
	/*
	 * Get device and block structures, and a pointer
	 * to the vba_device for the device.  We receive an
	 * unsolicited interrupt whenever the PS300 is power
	 * cycled (so ignore it in that case).
	 */
	dp = &iktab[ikon];
	if ((bp = dp->b_actf) == NULL) {
		if (PS_CODE(data) != PS_RESET)		/* power failure */
			log(LOG_WARNING, "ik%d: spurious interrupt, code %x\n",
			    ikon, data);
		goto enable;
	}
	sc = &ik_softc[IKUNIT(bp->b_dev)];
	sc->is_timeout = 0;			/* disable timer */
	switch (PS_CODE(data)) {
E 4

D 4
        case PS_LOOKUP:                         /* name lookup */
                if (data == PS_LOOKUP) {        /* dma name */
                        bp->b_command = PS_DMAOUT;
                        goto opcont;
                }
                if (data == PS_DMAOK(PS_LOOKUP)) {
                        /* reenable interrupt and wait for address */
                        sc->is_timeout = iktimeout;
                        goto enable;
                }
                /*
                 * Address should be present, extract it one
                 * word at a time from the PS300 (yech).
                 */
                if (data != PS_ADROK(PS_LOOKUP))
                        goto bad;
                FETCHWORD(0);
                FETCHWORD(1);
                goto opdone;
E 4
I 4
	case PS_LOOKUP:				/* name lookup */
		if (data == PS_LOOKUP) {	/* dma name */
			bp->b_command = PS_DMAOUT;
			goto opcont;
		}
		if (data == PS_DMAOK(PS_LOOKUP)) {
			/* reenable interrupt and wait for address */
			sc->is_timeout = iktimeout;
			goto enable;
		}
		/*
		 * Address should be present, extract it one
		 * word at a time from the PS300 (yech).
		 */
		if (data != PS_ADROK(PS_LOOKUP))
			goto bad;
		FETCHWORD(0);
		FETCHWORD(1);
		goto opdone;
E 4

D 4
        case PS_WRPHY_SYNC:                     /* physical i/o write w/ sync */
                if (data == PS_WRPHY_SYNC) {    /* start dma transfer */
                        bp->b_command = PS_DMAOUT;
                        goto opcont;
                }
                if (data != PS_DMAOK(PS_WRPHY_SYNC))
                        goto bad;
                goto opdone;
E 4
I 4
	case PS_WRPHY_SYNC:			/* physical i/o write w/ sync */
		if (data == PS_WRPHY_SYNC) {	/* start dma transfer */
			bp->b_command = PS_DMAOUT;
			goto opcont;
		}
		if (data != PS_DMAOK(PS_WRPHY_SYNC))
			goto bad;
		goto opdone;
E 4

D 4
        case PS_WRPHY:                          /* physical i/o write */
                if (data == PS_WRPHY) { /* start dma transfer */
                        bp->b_command = PS_DMAOUT;
                        goto opcont;
                }
                if (data != PS_DMAOK(PS_WRPHY))
                        goto bad;
                goto opdone;
E 4
I 4
	case PS_WRPHY:				/* physical i/o write */
		if (data == PS_WRPHY) { /* start dma transfer */
			bp->b_command = PS_DMAOUT;
			goto opcont;
		}
		if (data != PS_DMAOK(PS_WRPHY))
			goto bad;
		goto opdone;
E 4

D 4
        case PS_ATTACH:                         /* attach unit */
        case PS_DETACH:                         /* detach unit */
        case PS_ABORT:                          /* abort code from ps300 */
                if (data != bp->b_command)
                        goto bad;
                goto opdone;
E 4
I 4
	case PS_ATTACH:				/* attach unit */
	case PS_DETACH:				/* detach unit */
	case PS_ABORT:				/* abort code from ps300 */
		if (data != bp->b_command)
			goto bad;
		goto opdone;
E 4

D 4
        case PS_RDPHY:                          /* physical i/o read */
                if (data == PS_RDPHY) {         /* dma address list */
                        bp->b_command = PS_DMAOUT;
                        goto opcont;
                }
                if (data == PS_ADROK(PS_RDPHY)) {
                        /* collect read byte count and start dma */
                        bp->b_bcount = dioread(ik);
                        if (bp->b_bcount == -1)
                                goto bad;
                        bp->b_command = PS_DMAIN;
                        goto opcont;
                }
                if (data == PS_DMAOK(PS_RDPHY))
                        goto opdone;
                goto bad;
        }
E 4
I 4
	case PS_RDPHY:				/* physical i/o read */
		if (data == PS_RDPHY) {		/* dma address list */
			bp->b_command = PS_DMAOUT;
			goto opcont;
		}
		if (data == PS_ADROK(PS_RDPHY)) {
			/* collect read byte count and start dma */
			bp->b_bcount = dioread(ik);
			if (bp->b_bcount == -1)
				goto bad;
			bp->b_command = PS_DMAIN;
			goto opcont;
		}
		if (data == PS_DMAOK(PS_RDPHY))
			goto opdone;
		goto bad;
	}
E 4
bad:
D 4
        sc->is_error = data;
        bp->b_flags |= B_ERROR;
E 4
I 4
	sc->is_error = data;
	bp->b_flags |= B_ERROR;
E 4
opdone:
D 4
        dp->b_actf = bp->av_forw;               /* remove from queue */
        biodone(bp);
E 4
I 4
	dp->b_actf = bp->av_forw;		/* remove from queue */
	biodone(bp);
E 4
opcont:
D 4
        ikstart(dp);
E 4
I 4
	ikstart(dp);
E 4
enable:
D 4
        ik->ik_pulse = IKPULSE_SIENA;           /* explicitly reenable */
E 4
I 4
	ik->ik_pulse = IKPULSE_SIENA;		/* explicitly reenable */
E 4
}

/*
 * Watchdog timer.
 */
iktimer(unit)
D 4
        int unit;
E 4
I 4
	int unit;
E 4
{
D 4
        register struct ik_softc *sc = &ik_softc[unit];
E 4
I 4
	register struct ik_softc *sc = &ik_softc[unit];
E 4

D 4
        if (sc->is_timeout && --sc->is_timeout == 0) {
                register struct buf *dp, *bp;
                int s;
E 4
I 4
	if (sc->is_timeout && --sc->is_timeout == 0) {
		register struct buf *dp, *bp;
		int s;
E 4

D 3
                log(LOG_ERROR, "ik%d: timeout\n", unit);
E 3
I 3
D 4
                log(LOG_ERR, "ik%d: timeout\n", unit);
E 3
                s = splik();
                /* should abort current command */
                dp = &iktab[unit];
                if (bp = dp->b_actf) {
                        sc->is_error = PSERROR_CMDTIMO;
                        bp->b_flags |= B_ERROR;
                        dp->b_actf = bp->av_forw;       /* remove from queue */
                        biodone(bp);
                        ikstart(dp);
                }
                splx(s);
        }
        timeout(iktimer, unit, hz);
}
E 4
I 4
		log(LOG_ERR, "ik%d: timeout\n", unit);
		s = splik();
		/* should abort current command */
		dp = &iktab[unit];
		if (bp = dp->b_actf) {
			sc->is_error = PSERROR_CMDTIMO;
			bp->b_flags |= B_ERROR;
			dp->b_actf = bp->av_forw;	/* remove from queue */
			biodone(bp);
			ikstart(dp);
		}
		splx(s);
	}
D 5
	timeout(iktimer, unit, hz);
E 5
I 5
	timeout(iktimer, (caddr_t)unit, hz);
E 5
}
E 4

/*
 * Handshake read from DR300.
 */
dioread(ik)
D 4
        register struct ikdevice *ik;
E 4
I 4
	register struct ikdevice *ik;
E 4
{
D 4
        register int timeout;
        u_short data;
E 4
I 4
D 5
	register int timeout;
E 5
I 5
	register int t;
E 5
	u_short data;
E 4

D 4
        for (timeout = ikdiotimo; timeout > 0; timeout--)
                if ((ik->ik_csr&(IKCSR_ATTF|IKCSR_STATC)) == IKCSR_ATTF) {
                        data = ik->ik_data;
                        ik->ik_csr = IKCSR_RATTF|IKCSR_RDMAF|IKCSR_FNC1;
                        ik->ik_pulse = IKPULSE_FNC2;
                        return (data);
                }
        return (-1);
}
E 4
I 4
D 5
	for (timeout = ikdiotimo; timeout > 0; timeout--)
E 5
I 5
	for (t = ikdiotimo; t > 0; t--)
E 5
		if ((ik->ik_csr&(IKCSR_ATTF|IKCSR_STATC)) == IKCSR_ATTF) {
			data = ik->ik_data;
			ik->ik_csr = IKCSR_RATTF|IKCSR_RDMAF|IKCSR_FNC1;
			ik->ik_pulse = IKPULSE_FNC2;
			return (data);
		}
	return (-1);
}
E 4

/*
 * Handshake write to DR300. 
 *
 * Interrupts are enabled before completing the work
 * so the caller should either be at splik or be
 * prepared to take the interrupt immediately.
 */
diowrite(ik, v)
D 4
        register struct ikdevice *ik;
        u_short v;
E 4
I 4
	register struct ikdevice *ik;
	u_short v;
E 4
{
D 4
        register int timeout;
        register u_short csr;
E 4
I 4
D 5
	register int timeout;
E 5
I 5
	register int t;
E 5
	register u_short csr;
E 4

top:
D 4
        /*
         * Deposit data and generate dr300 attention
         */
        ik->ik_data = v;
        ik->ik_csr = IKCSR_RDMAF|IKCSR_RATTF;
        ik->ik_pulse = IKPULSE_FNC2;
        for (timeout = ikdiotimo; timeout > 0; timeout--) {
                csr = ik->ik_csr;
#define IKCSR_DONE      (IKCSR_STATA|IKCSR_STATC)
                if ((csr&IKCSR_DONE) == IKCSR_DONE) {
                        /* 
                         * Done, complete handshake by notifying dr300.
                         */
                        ik->ik_csr = IKCSR_IENA;        /* ~IKCSR_FNC1 */
                        ik->ik_pulse = IKPULSE_FNC2;
                        return (0);
                }
                /* beware of potential deadlock with dioread */
                if ((csr&(IKCSR_ATTF|IKCSR_STATC)) == IKCSR_ATTF)
                        goto top;
        }
        ik->ik_csr = IKCSR_IENA;
        return (PSERROR_DIOTIMO);
}
E 4
I 4
	/*
	 * Deposit data and generate dr300 attention
	 */
	ik->ik_data = v;
	ik->ik_csr = IKCSR_RDMAF|IKCSR_RATTF;
	ik->ik_pulse = IKPULSE_FNC2;
D 5
	for (timeout = ikdiotimo; timeout > 0; timeout--) {
E 5
I 5
	for (t = ikdiotimo; t > 0; t--) {
E 5
		csr = ik->ik_csr;
#define IKCSR_DONE	(IKCSR_STATA|IKCSR_STATC)
		if ((csr&IKCSR_DONE) == IKCSR_DONE) {
			/* 
			 * Done, complete handshake by notifying dr300.
			 */
			ik->ik_csr = IKCSR_IENA;	/* ~IKCSR_FNC1 */
			ik->ik_pulse = IKPULSE_FNC2;
			return (0);
		}
		/* beware of potential deadlock with dioread */
		if ((csr&(IKCSR_ATTF|IKCSR_STATC)) == IKCSR_ATTF)
			goto top;
	}
	ik->ik_csr = IKCSR_IENA;
	return (PSERROR_DIOTIMO);
}
E 4

/*ARGSUSED*/
ikioctl(dev, cmd, data, flag)
D 4
        dev_t dev;
        int cmd;
        caddr_t data;
        int flag;
E 4
I 4
	dev_t dev;
	int cmd;
	caddr_t data;
	int flag;
E 4
{
D 4
        int error = 0, unit = IKUNIT(dev), s;
        register struct ik_softc *sc = &ik_softc[unit];
E 4
I 4
	int error = 0, unit = IKUNIT(dev), s;
	register struct ik_softc *sc = &ik_softc[unit];
E 4

D 4
        switch (cmd) {
E 4
I 4
	switch (cmd) {
E 4

D 4
        case PSIOGETERROR:              /* get error code for last operation */
                *(int *)data = sc->is_error;
                break;
E 4
I 4
	case PSIOGETERROR:		/* get error code for last operation */
		*(int *)data = sc->is_error;
		break;
E 4

D 4
        case PSIOLOOKUP: {              /* PS300 name lookup */
                register struct pslookup *lp = (struct pslookup *)data;
                register struct buf *bp;
E 4
I 4
	case PSIOLOOKUP: {		/* PS300 name lookup */
		register struct pslookup *lp = (struct pslookup *)data;
		register struct buf *bp;
E 4

D 4
                if (lp->pl_len > PS_MAXNAMELEN)
                        return (EINVAL);
                bp = &rikbuf[unit];
                s = splbio();
                while (bp->b_flags&B_BUSY) {
                        bp->b_flags |= B_WANTED;
                        sleep((caddr_t)bp, PRIBIO+1);
                }
                splx(s);
                bp->b_flags = B_BUSY | B_WRITE;
                error = copyin(lp->pl_name, sc->is_buf, lp->pl_len);
                if (error == 0) {
                        if (lp->pl_len&1)
                                sc->is_buf[lp->pl_len] = '\0';
                        error = ikcommand(dev, PS_LOOKUP, lp->pl_len);
                }
                s = splbio();
                if (bp->b_flags&B_WANTED)
                        wakeup((caddr_t)bp);
                splx(s);
                bp->b_flags &= ~(B_BUSY|B_WANTED);
                lp->pl_addr = sc->is_nameaddr.l;
                break;
        }
        default:
                return (ENOTTY);
        }
        return (error);
E 4
I 4
		if (lp->pl_len > PS_MAXNAMELEN)
			return (EINVAL);
		bp = &rikbuf[unit];
		s = splbio();
		while (bp->b_flags&B_BUSY) {
			bp->b_flags |= B_WANTED;
			sleep((caddr_t)bp, PRIBIO+1);
		}
		splx(s);
		bp->b_flags = B_BUSY | B_WRITE;
D 5
		error = copyin(lp->pl_name, sc->is_buf, lp->pl_len);
E 5
I 5
D 8
		error = copyin(lp->pl_name, sc->is_buf, (unsigned)lp->pl_len);
E 8
I 8
		error = copyin(lp->pl_name, (caddr_t)sc->is_buf,
		    (unsigned)lp->pl_len);
E 8
E 5
		if (error == 0) {
			if (lp->pl_len&1)
				sc->is_buf[lp->pl_len] = '\0';
			error = ikcommand(dev, PS_LOOKUP, lp->pl_len);
		}
		s = splbio();
		if (bp->b_flags&B_WANTED)
			wakeup((caddr_t)bp);
		splx(s);
		bp->b_flags &= ~(B_BUSY|B_WANTED);
		lp->pl_addr = sc->is_nameaddr.l;
		break;
	}
	default:
		return (ENOTTY);
	}
	return (error);
E 4
}
#endif
E 1
