h02272
s 00003/00001/00981
d D 7.1 88/05/21 18:32:53 karels 8 7
c bring up to revision 7 for tahoe release
e
s 00665/00771/00317
d D 1.6 86/12/15 20:25:03 sam 7 6
c lint
e
s 00001/00000/01087
d D 1.5 86/11/29 13:32:50 sam 6 5
c add disclaimer
e
s 00002/00000/01085
d D 1.4 86/11/25 22:43:37 sam 5 4
c probe csr address
e
s 00014/00012/01071
d D 1.3 86/11/23 19:23:53 sam 4 3
c make it compile
e
s 00194/00000/00889
d D 1.2 86/11/23 18:30:33 sam 3 1
c merge dr11 device ioctls into dr driver to save extra device
e
s 00194/00000/00889
d R 1.2 86/11/23 18:29:35 sam 2 1
c 
e
s 00889/00000/00000
d D 1.1 86/07/20 11:25:59 sam 1 0
c date and time created 86/07/20 11:25:59 by sam
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

#include "dr.h"
#if NDR > 0
D 7

/*      DRV11-W DMA interface driver.
E 7
I 7
/*
 * DRV11-W DMA interface driver.
 *
E 7
I 6
 * UNTESTED WITH 4.3
E 6
 */
D 7

E 7
#include "../machine/mtpr.h"
#include "../machine/pte.h"

#include "param.h"
#include "conf.h"
#include "dir.h"
#include "user.h"
#include "proc.h"
#include "map.h"
#include "ioctl.h"
#include "buf.h"
#include "vm.h"
#include "uio.h"
I 7
#include "kernel.h"
E 7

#include "../tahoevba/vbavar.h"
#include "../tahoevba/drreg.h"

#define YES 1
#define NO  0

struct  vba_device  *drinfo[NDR];
struct  dr_aux dr_aux[NDR];

D 7
caddr_t vtoph();
E 7
unsigned drminphys();
D 7
int     drprobe(), drintr(), drattach(), drtime(), drrwtimo();
int     drstrategy();
extern struct  vba_device  *drinfo[];
static long drstd[] = { 0 };
E 7
I 7
int	 drprobe(), drintr(), drattach(), drtimo(), drrwtimo();
int	 drstrategy();
extern	struct  vba_device  *drinfo[];
static	long drstd[] = { 0 };
E 7
struct  vba_driver drdriver =
D 7
	{ drprobe, 0, drattach, 0, drstd, "rs", drinfo };
extern long hz;
E 7
I 7
    { drprobe, 0, drattach, 0, drstd, "rs", drinfo };
E 7

#define RSUNIT(dev) (minor(dev) & 7)
#define SPL_UP spl5

/* -------- Per-unit data -------- */

extern struct dr_aux dr_aux[];

D 7
struct rs_data {
    struct buf  rs_buf;
    int         rs_ubainfo;
    short       rs_debug;
    short       rs_busy;
    short       rs_tout; 
    short       rs_uid;
    short       rs_isopen;
    short       rs_func;
} rs_data[NDR];


E 7
#ifdef DR_DEBUG
D 7
long DR11 = 0;
E 7
I 7
long	DR11 = 0;
E 7
#endif

drprobe(reg, vi)
D 7
    caddr_t reg;
    struct vba_device *vi;
E 7
I 7
	caddr_t reg;
	struct vba_device *vi;
E 7
{
D 7
    register int br, cvec;		/* must be r12, r11 */
    register struct rsdevice *dr;
    register ushort status;
E 7
I 7
	register int br, cvec;		/* must be r12, r11 */
	struct rsdevice *dr;
E 7

I 5
D 7
    if (badaddr(reg, 2))
	return (0);
E 5
    dr = (struct rsdevice *)reg;
#ifdef notdef
D 4
    dr->dr_intvec = --vi->ui_hd->vh_lastiv;
E 4
I 4
    dr->dr_intvect = --vi->ui_hd->vh_lastiv;
E 4
#else
D 4
    dr->dr_intvec = DRINTV+vi->ui_unit;
E 4
I 4
    dr->dr_intvect = DRINTV+vi->ui_unit;
E 7
I 7
#ifdef lint
	br = 0; cvec = br; br = cvec;
	drintr(0);
E 7
E 4
#endif
I 7
	if (badaddr(reg, 2))
		return (0);
	dr = (struct rsdevice *)reg;
	dr->dr_intvect = --vi->ui_hd->vh_lastiv;
E 7
#ifdef DR_DEBUG
D 7
    printf("dprobe: Set interrupt vector %lx and init\n",dr->dr_intvec);
E 7
I 7
	printf("dprobe: Set interrupt vector %lx and init\n",dr->dr_intvec);
E 7
#endif
D 7
    /* generate interrupt here for autoconfig */
    dr->dr_cstat = MCLR;		/* init board and device */
    status = dr->dr_cstat;		/* read initial status */
E 7
I 7
	/* generate interrupt here for autoconfig */
	dr->dr_cstat = MCLR;		/* init board and device */
E 7
#ifdef DR_DEBUG
D 7
    printf("drprobe: Initial status %lx\n",status & 0xffff);
E 7
I 7
	printf("drprobe: Initial status %lx\n", dr->dr_cstat);
E 7
#endif
D 4
    br = 0x18, cvec = dr->dr_intvec;	/* XXX */
E 4
I 4
D 7
    br = 0x18, cvec = dr->dr_intvect;	/* XXX */
E 4
    return (sizeof (struct rsdevice));		/* DR11 exist */
E 7
I 7
	br = 0x18, cvec = dr->dr_intvect;	/* XXX */
	return (sizeof (struct rsdevice));		/* DR11 exist */
E 7
}

/* ARGSUSED */
drattach(ui)
D 7
struct vba_device *ui;
E 7
I 7
	struct vba_device *ui;
E 7
{
D 7
    register struct dr_aux *rsd;
E 7
I 7
	register struct dr_aux *rsd;
E 7

D 7
    rsd = &dr_aux[ui->ui_unit];
    rsd->dr_flags = DR_PRES;		/* This dr11 is present */
    rsd->dr_addr = (struct rsdevice *)ui->ui_addr; /* Save addr of this dr11 */
    rsd->dr_istat = 0;
    rsd->dr_bycnt = 0;
    rsd->dr_cmd = 0;
    rsd->currenttimo = 0;
    return;
E 7
I 7
	rsd = &dr_aux[ui->ui_unit];
	rsd->dr_flags = DR_PRES;		/* This dr11 is present */
	rsd->dr_addr = (struct rsdevice *)ui->ui_addr; /* Save addr of this dr11 */
	rsd->dr_istat = 0;
	rsd->dr_bycnt = 0;
	rsd->dr_cmd = 0;
	rsd->currenttimo = 0;
E 7
}

D 7
dropen (dev, flag)
dev_t dev;
int flag;
E 7
I 7
/*ARGSUSED*/
dropen(dev, flag)
	dev_t dev;
	int flag;
E 7
{
D 7
    register int unit = RSUNIT(dev);
    register struct rsdevice *dr;
    register struct dr_aux *rsd;
E 7
I 7
	register int unit = RSUNIT(dev);
	register struct rsdevice *dr;
	register struct dr_aux *rsd;
E 7

D 7
    if ((drinfo[unit] == 0) || (!drinfo[unit]->ui_alive))
	return ENXIO;

    dr = RSADDR(unit);
    rsd = &dr_aux[unit];
    if (rsd->dr_flags & DR_OPEN) {
E 7
I 7
	if (drinfo[unit] == 0 || !drinfo[unit]->ui_alive)
		return (ENXIO);
	dr = RSADDR(unit);
	rsd = &dr_aux[unit];
	if (rsd->dr_flags & DR_OPEN) {
E 7
#ifdef DR_DEBUG
D 7
	printf("\ndropen: dr11 unit %ld already open",unit);
E 7
I 7
		printf("\ndropen: dr11 unit %ld already open",unit);
E 7
#endif
D 7
	return ENXIO;      		/* DR11 already open */
    }
    rsd->dr_flags |= DR_OPEN;		/* Mark it OPEN */
    rsd->dr_istat = 0;			/* Clear status of previous interrupt */
    rsd->rtimoticks = hz;		/* Set read no stall timout to 1 sec */
    rsd->wtimoticks = hz*60;		/* Set write no stall timout to 1 min */
    dr->dr_cstat = DR_ZERO;		/* Clear function & latches */
    dr->dr_pulse = (RDMA | RATN);	/* clear leftover attn & e-o-r flags */
    drtimo(dev);			/* start the self kicker */
    return 0;
E 7
I 7
		return (ENXIO);	  		/* DR11 already open */
	}
	rsd->dr_flags |= DR_OPEN;	/* Mark it OPEN */
	rsd->dr_istat = 0;		/* Clear status of previous interrupt */
	rsd->rtimoticks = hz;		/* Set read no stall timout to 1 sec */
	rsd->wtimoticks = hz*60;	/* Set write no stall timout to 1 min */
	dr->dr_cstat = DR_ZERO;		/* Clear function & latches */
	dr->dr_pulse = (RDMA | RATN);	/* clear leftover attn & e-o-r flags */
	drtimo(dev);			/* start the self kicker */
	return (0);
E 7
}

drclose (dev)
D 7
dev_t dev;
E 7
I 7
	dev_t dev;
E 7
{
D 7
    register int unit = RSUNIT(dev);
    register struct dr_aux *dra;
    register struct rsdevice *rs;
    register short s;
E 7
I 7
	register int unit = RSUNIT(dev);
	register struct dr_aux *dra;
	register struct rsdevice *rs;
	register short s;
E 7

D 7
    dra = &dr_aux[unit];
    if (!(dra->dr_flags & DR_OPEN)) {
E 7
I 7
	dra = &dr_aux[unit];
	if ((dra->dr_flags & DR_OPEN) == 0) {
E 7
#ifdef DR_DEBUG
D 7
	printf("\ndrclose: DR11 device %ld not open",unit);
E 7
I 7
		printf("\ndrclose: DR11 device %ld not open",unit);
E 7
#endif
D 7
	return;
    }
    dra->dr_flags &= ~(DR_OPEN|DR_ACTV);
    rs = dra->dr_addr;
    s=SPL_UP();
    rs->dr_cstat = DR_ZERO;
    if (dra->dr_buf.b_flags & B_BUSY) {
    	dra->dr_buf.b_flags &= ~B_BUSY;
	wakeup(&dra->dr_buf.b_flags);
    }
    splx(s);
    return;
E 7
I 7
		return;
	}
	dra->dr_flags &= ~(DR_OPEN|DR_ACTV);
	rs = dra->dr_addr;
	s = SPL_UP();
	rs->dr_cstat = DR_ZERO;
	if (dra->dr_buf.b_flags & B_BUSY) {
		dra->dr_buf.b_flags &= ~B_BUSY;
		wakeup((caddr_t)&dra->dr_buf.b_flags);
	}
	splx(s);
E 7
}


/*	drread() works exactly like drwrite() except that the
	B_READ flag is used when physio() is called
*/
drread (dev, uio)
D 7
dev_t dev;
struct uio *uio;
E 7
I 7
	dev_t dev;
	struct uio *uio;
E 7
{	register struct dr_aux *dra;
	register struct buf *bp;
D 7
	register long spl, err;
    	register int unit = RSUNIT(dev);
E 7
I 7
	register int spl, err;
	register int unit = RSUNIT(dev);
E 7

D 7
    if (   uio->uio_iov->iov_len <= 0		/* Negative count */
	|| uio->uio_iov->iov_len & 1		/* odd count */
	|| (int)uio->uio_iov->iov_base & 1	/* odd destination address */
       )
	return EINVAL;

E 7
I 7
	if (uio->uio_iov->iov_len <= 0 ||	/* Negative count */
	    uio->uio_iov->iov_len & 1 ||	/* odd count */
	    (int)uio->uio_iov->iov_base & 1)	/* odd destination address */
		return (EINVAL);
E 7
#ifdef DR_DEBUG
D 7
    if (DR11 & 8) {
	printf("\ndrread: (len:%ld)(base:%lx)",
    		uio->uio_iov->iov_len,(int)uio->uio_iov->iov_base); 
    }
E 7
I 7
	if (DR11 & 8)
		printf("\ndrread: (len:%ld)(base:%lx)",
		    uio->uio_iov->iov_len,(int)uio->uio_iov->iov_base); 
E 7
#endif
D 7

    dra = &dr_aux[RSUNIT(dev)];
    dra->dr_op = DR_READ;
    bp =  &dra->dr_buf;
    bp->b_resid = 0;
    if (dra->dr_flags & DR_NORSTALL) {
	/* We are in no stall mode, start the timer, raise IPL so nothing
	   can stop us once the timer's running */
	spl = SPL_UP();
	timeout(drrwtimo,(caddr_t)((dra->currenttimo<<8) | unit),
				dra->rtimoticks);
    	err = physio (drstrategy, bp, dev,B_READ, drminphys, uio);
	splx(spl);
	if (err)
		return(err);
	dra->currenttimo++;		/* Update current timeout number */
	/* Did we timeout */
	if (dra->dr_flags & DR_TMDM) {
		dra->dr_flags &= ~DR_TMDM;	/* Clear timeout flag */
		u.u_error = 0;		/* Made the error ourself, ignore it */
E 7
I 7
	dra = &dr_aux[RSUNIT(dev)];
	dra->dr_op = DR_READ;
	bp =  &dra->dr_buf;
	bp->b_resid = 0;
	if (dra->dr_flags & DR_NORSTALL) {
		/*
		 * We are in no stall mode, start the timer,
		 * raise IPL so nothing can stop us once the
		 * timer's running
		 */
		spl = SPL_UP();
		timeout(drrwtimo, (caddr_t)((dra->currenttimo<<8) | unit),
		    (int)dra->rtimoticks);
		err = physio(drstrategy, bp, dev,B_READ, drminphys, uio);
		splx(spl);
		if (err)
			return (err);
		dra->currenttimo++;	/* Update current timeout number */
		/* Did we timeout */
		if (dra->dr_flags & DR_TMDM) {
			dra->dr_flags &= ~DR_TMDM; /* Clear timeout flag */
			u.u_error = 0;	/* Made the error ourself, ignore it */
		}
		return (err);
E 7
	}
D 7
    }
    else {
    	return physio (drstrategy, bp, dev,B_READ, drminphys, uio);
    }
E 7
I 7
	return (physio(drstrategy, bp, dev,B_READ, drminphys, uio));
E 7
}

D 7
drwrite (dev, uio)
dev_t dev;
struct uio *uio;
E 7
I 7
drwrite(dev, uio)
	dev_t dev;
	struct uio *uio;
E 7
{	register struct dr_aux *dra;
	register struct buf *bp;
D 7
    	register int unit = RSUNIT(dev);
	register long spl, err;
E 7
I 7
	register int unit = RSUNIT(dev);
	int spl, err;
E 7

D 7
    if (   uio->uio_iov->iov_len <= 0
	|| uio->uio_iov->iov_len & 1
	|| (int)uio->uio_iov->iov_base & 1
       )
	return EINVAL;

E 7
I 7
	if (uio->uio_iov->iov_len <= 0 || uio->uio_iov->iov_len & 1 ||
	    (int)uio->uio_iov->iov_base & 1)
		return (EINVAL);
E 7
#ifdef DR_DEBUG
D 7
    if (DR11 & 4) {
	printf("\ndrwrite: (len:%ld)(base:%lx)",
    		uio->uio_iov->iov_len,(int)uio->uio_iov->iov_base); 
    }
E 7
I 7
	if (DR11 & 4)
		printf("\ndrwrite: (len:%ld)(base:%lx)",
		    uio->uio_iov->iov_len,(int)uio->uio_iov->iov_base); 
E 7
#endif
D 7

    dra = &dr_aux[RSUNIT(dev)];
    dra->dr_op = DR_WRITE;
    bp =  &dra->dr_buf;
    bp->b_resid = 0;
    if (dra->dr_flags & DR_NOWSTALL) {
	/* We are in no stall mode, start the timer, raise IPL so nothing
	   can stop us once the timer's running */
	spl = SPL_UP();
	timeout(drrwtimo,(caddr_t)((dra->currenttimo<<8) | unit),
				dra->wtimoticks);
    	err = physio (drstrategy, bp, dev,B_WRITE, drminphys, uio);
	splx(spl);
	if (err)
		return(err);
	dra->currenttimo++;		/* Update current timeout number */
	/* Did we timeout */
	if (dra->dr_flags & DR_TMDM) {
		dra->dr_flags &= ~DR_TMDM;	/* Clear timeout flag */
		u.u_error = 0;		/* Made the error ourself, ignore it */
E 7
I 7
	dra = &dr_aux[RSUNIT(dev)];
	dra->dr_op = DR_WRITE;
	bp =  &dra->dr_buf;
	bp->b_resid = 0;
	if (dra->dr_flags & DR_NOWSTALL) {
		/*
		 * We are in no stall mode, start the timer,
		 * raise IPL so nothing can stop us once the
		 * timer's running
		 */
		spl = SPL_UP();
		timeout(drrwtimo,(caddr_t)((dra->currenttimo<<8) | unit),
		    (int)dra->wtimoticks);
		err = physio (drstrategy, bp, dev,B_WRITE, drminphys, uio);
		splx(spl);
		if (err)
			return (err);
		dra->currenttimo++;	/* Update current timeout number */
		/* Did we timeout */
		if (dra->dr_flags & DR_TMDM) {
			dra->dr_flags &= ~DR_TMDM;	/* Clear timeout flag */
			u.u_error = 0;	/* Made the error ourself, ignore it */
		}
		return (err);
E 7
	}
D 7
    }
    else {
    	return physio (drstrategy, bp, dev,B_WRITE, drminphys, uio);
    }
E 7
I 7
	return (physio(drstrategy, bp, dev,B_WRITE, drminphys, uio));
E 7
}

D 7
/*  Routine used by calling program to issue commands to dr11 driver and 
    through it to the device.
    It is also used to read status from the device and driver and to wait 
    for attention interrupts.
    Status is returned in an 8 elements unsigned short integer array, the 
    first two elements of the array are also used to pass arguments to 
    drioctl() if required.
    The function bits to be written to the dr11 are included in the cmd
    argument. Even if they are not being written to the dr11 in a particular
    drioctl() call, they will update the copy of cmd that is stored in the
    driver. When drstrategy() is called, this updated copy is used if a 
    deferred function bit write has been specified. The "side effect" of
    calls to the drioctl() requires that the last call prior to a read or
    write has an appropriate copy of the function bits in cmd if they are
    to be used in drstrategy().
    When used as command value, the contents of data[0] is the command
    parameter.
*/

drioctl(dev, cmd, data, flag)
dev_t dev;
int cmd;
long *data;
int flag;
E 7
I 7
/*
 * Routine used by calling program to issue commands to dr11 driver and 
 * through it to the device.
 * It is also used to read status from the device and driver and to wait 
 * for attention interrupts.
 * Status is returned in an 8 elements unsigned short integer array, the 
 * first two elements of the array are also used to pass arguments to 
 * drioctl() if required.
 * The function bits to be written to the dr11 are included in the cmd
 * argument. Even if they are not being written to the dr11 in a particular
 * drioctl() call, they will update the copy of cmd that is stored in the
 * driver. When drstrategy() is called, this updated copy is used if a 
 * deferred function bit write has been specified. The "side effect" of
 * calls to the drioctl() requires that the last call prior to a read or
 * write has an appropriate copy of the function bits in cmd if they are
 * to be used in drstrategy().
 * When used as command value, the contents of data[0] is the command
 * parameter.
 */
drioctl(dev, cmd, data)
	dev_t dev;
	int cmd;
	long *data;
E 7
{
D 7
    register int unit = RSUNIT(dev);
    register struct dr_aux *dra;
    register struct rsdevice *rsaddr = RSADDR(unit);
    struct dr11io dio;
    ushort s, errcode, status;
    long temp;
E 7
I 7
	register int unit = RSUNIT(dev);
	register struct dr_aux *dra;
	register struct rsdevice *rsaddr = RSADDR(unit);
	int s;
	u_short status;
	long temp;
E 7

#ifdef DR_DEBUG
D 7
    if (DR11 & 0x10)
    printf("\ndrioctl: (dev:%lx)(cmd:%lx)(data:%lx)(data[0]:%lx)",
	dev,cmd,data,data[0]);
E 7
I 7
	if (DR11 & 0x10)
		printf("\ndrioctl: (dev:%lx)(cmd:%lx)(data:%lx)(data[0]:%lx)",
		    dev,cmd,data,data[0]);
E 7
#endif
I 7
	dra = &dr_aux[unit];
	dra->dr_cmd = 0;	/* Fresh copy; clear all previous flags */
	switch (cmd) {
E 7

D 7
    dra = &dr_aux[unit];
    dra->dr_cmd = 0;		/* Fresh copy; clear all previous flags */

    switch (cmd) {

    case DRWAIT:
	/* Wait for attention interrupt */
E 7
I 7
	case DRWAIT:		/* Wait for attention interrupt */
E 7
#ifdef DR_DEBUG
D 7
	printf("\ndrioctl: wait for attention interrupt");
E 7
I 7
		printf("\ndrioctl: wait for attention interrupt");
E 7
#endif
D 7
	s = SPL_UP();
	/* If the attention flag in dr_flags is set, it probably means that
	   an attention has arrived by the time a previous DMA end-of-range
	   interrupt was serviced. If ATRX is set, we will return with out
	   sleeping, since we have received an attention since the last call
	   to wait on attention.
	   This may not be appropriate for some applications.
	*/
	if (!(dra->dr_flags & DR_ATRX)) {
		dra->dr_flags |= DR_ATWT;	/* Set waiting flag */
		rsaddr->dr_pulse = IENB;	/* Enable interrupt; use pulse
						   reg. so function bits are
						   not changed */
		sleep((caddr_t)&dra->dr_cmd,DRPRI);
	}
	splx(s);
	break;
E 7
I 7
		s = SPL_UP();
		/* 
		 * If the attention flag in dr_flags is set, it probably
		 * means that an attention has arrived by the time a
		 * previous DMA end-of-range interrupt was serviced. If
		 * ATRX is set, we will return with out sleeping, since
		 * we have received an attention since the last call to
		 * wait on attention.  This may not be appropriate for
		 * some applications.
		 */
		if ((dra->dr_flags & DR_ATRX) == 0) {
			dra->dr_flags |= DR_ATWT;	/* Set waiting flag */
			/*
			 * Enable interrupt; use pulse reg.
			 * so function bits are not changed
			 */
			rsaddr->dr_pulse = IENB;
			sleep((caddr_t)&dra->dr_cmd, DRPRI);
		}
		splx(s);
		break;
E 7

D 7
    case DRPIOW:
	/* Write to p-i/o register */
	rsaddr->dr_data = data[0];
	break;
E 7
I 7
	case DRPIOW:			/* Write to p-i/o register */
		rsaddr->dr_data = data[0];
		break;
E 7

D 7
    case DRPACL:
	/* Send pulse to device */
	rsaddr->dr_pulse = FCN2;
	break;
E 7
I 7
	case DRPACL:			/* Send pulse to device */
		rsaddr->dr_pulse = FCN2;
		break;
E 7

D 7
    case DRDACL:
	/* Defer alco pulse until go */
	dra->dr_cmd |= DR_DACL;
	break;
E 7
I 7
	case DRDACL:			/* Defer alco pulse until go */
		dra->dr_cmd |= DR_DACL;
		break;
E 7

D 7
    case DRPCYL:
	/* Set cycle with next go */
	dra->dr_cmd |= DR_PCYL;
	break;
E 7
I 7
	case DRPCYL:			/* Set cycle with next go */
		dra->dr_cmd |= DR_PCYL;
		break;
E 7

D 7
    case DRDFCN:
	/* Do not update function bits until next go issued */
	dra->dr_cmd |= DR_DFCN;
	break;
E 7
I 7
	case DRDFCN:			/* Update function with next go */
		dra->dr_cmd |= DR_DFCN;
		break;
E 7

D 7
    case DRRATN:
	/* Reset attention flag -- use with extreme caution */
	rsaddr->dr_pulse = RATN;
	break;
E 7
I 7
	case DRRATN:			/* Reset attention flag */
		rsaddr->dr_pulse = RATN;
		break;
E 7

D 7
    case DRRDMA:
	/* Reset DMA e-o-r flag -- should never used */
	rsaddr->dr_pulse = RDMA;
	break;
E 7
I 7
	case DRRDMA:			/* Reset DMA e-o-r flag */
		rsaddr->dr_pulse = RDMA;
		break;
E 7

D 7
    case DRSFCN:
	/* Set function bits */
	temp = data[0] & DR_FMSK;
	rsaddr->dr_cstat = temp;	/* Write to control register */
	/* This has a very important side effect -- It clears the interrupt
	   enable flag. That is fine for this driver, but if it is desired
	   to leave interrupt enable at all times, it will be necessary to
	   to read the status register first to get IENB, or carry a software
	   flag that indicates whether interrupts are set, and or this into 
	   the controll register value being written.
	*/
	break;
E 7
I 7
	case DRSFCN:			/* Set function bits */
		temp = data[0] & DR_FMSK;
		/*
		 * This has a very important side effect -- It clears
		 * the interrupt enable flag. That is fine for this driver,
		 * but if it is desired to leave interrupt enable at all
		 * times, it will be necessary to read the status register
		 * first to get IENB, or carry a software flag that indicates
		 * whether interrupts are set, and or this into the control
		 * register value being written.
		 */
		rsaddr->dr_cstat = temp;
		break;
E 7

D 7
    case DRRPER:
	/* Clear parity flag */
	rsaddr->dr_pulse = RPER;
	break;
E 7
I 7
	case DRRPER:			/* Clear parity flag */
		rsaddr->dr_pulse = RPER;
		break;
E 7

D 7
    case DRSETRSTALL:
	/* Set read stall mode. */
	dra->dr_flags &= (~DR_NORSTALL);
	break;
E 7
I 7
	case DRSETRSTALL:		/* Set read stall mode. */
		dra->dr_flags &= (~DR_NORSTALL);
		break;
E 7

D 7
    case DRSETNORSTALL:
	/* Set no stall read  mode. */
	dra->dr_flags |= DR_NORSTALL;
	break;
E 7
I 7
	case DRSETNORSTALL:		/* Set no stall read  mode. */
		dra->dr_flags |= DR_NORSTALL;
		break;
E 7

D 7
    case DRGETRSTALL:
	/* Returns true if in read stall mode. */
	data[0]  = (dra->dr_flags & DR_NORSTALL)? 0 : 1;
	break;
E 7
I 7
	case DRGETRSTALL:		/* Returns true if in read stall mode */
		data[0]  = (dra->dr_flags & DR_NORSTALL)? 0 : 1;
		break;
E 7

D 7
    case DRSETRTIMEOUT:
	/* Set the number of ticks before a no stall read times out.
	   The argument is given in tenths of a second. */
	if (data[0] < 1) {
		u.u_error = EINVAL;
		temp = 1;
	}
	dra->rtimoticks = (data[0] * hz )/10;
	break;
E 7
I 7
	case DRSETRTIMEOUT:		/* Set read stall timeout (1/10 secs) */
		if (data[0] < 1) {
			u.u_error = EINVAL;
			temp = 1;
		}
		dra->rtimoticks = (data[0] * hz )/10;
		break;
E 7

D 7
    case DRGETRTIMEOUT:
	/* Returns the number of tenths of seconds before
	   a no stall read times out. */
	/* The argument is given in tenths of a second. */
	data[0] = ((dra->rtimoticks)*10)/hz;
	break;
E 7
I 7
	case DRGETRTIMEOUT:		/* Return read stall timeout */
		data[0] = ((dra->rtimoticks)*10)/hz;
		break;
E 7

D 7
    case DRSETWSTALL:
	/* Set write stall mode. */
	dra->dr_flags &= (~DR_NOWSTALL);
	break;
E 7
I 7
	case DRSETWSTALL:		/* Set write stall mode. */
		dra->dr_flags &= (~DR_NOWSTALL);
		break;
E 7

D 7
    case DRSETNOWSTALL:
	/* Set write stall mode. */
	dra->dr_flags |= DR_NOWSTALL;
	break;
E 7
I 7
	case DRSETNOWSTALL:		/* Set write stall mode. */
		dra->dr_flags |= DR_NOWSTALL;
		break;
E 7

D 7
    case DRGETWSTALL:
	/* Returns true if in write stall mode. */
	data[0] = (dra->dr_flags & DR_NOWSTALL)? 0 : 1;
	break;
E 7
I 7
	case DRGETWSTALL:		/* Return true if in write stall mode */
		data[0] = (dra->dr_flags & DR_NOWSTALL)? 0 : 1;
		break;
E 7

D 7
    case DRSETWTIMEOUT:
	/* Set the number of ticks before a no stall write times out.
	   The argument is given in tenths of a second. */
	if (data[0] < 1) {
		u.u_error = EINVAL;
		temp = 1;
	}
	dra->wtimoticks = (data[0] * hz )/10;
	break;
E 7
I 7
	case DRSETWTIMEOUT:		/* Set write stall timeout (1/10's) */
		if (data[0] < 1) {
			u.u_error = EINVAL;
			temp = 1;
		}
		dra->wtimoticks = (data[0] * hz )/10;
		break;
E 7

D 7
    case DRGETWTIMEOUT:
	/* Returns the number of tenths of seconds before
	   a no stall write times out. */
	/* The argument is given in tenths of a second. */
	data[0] = ((dra->wtimoticks)*10)/hz;
	break;
E 7
I 7
	case DRGETWTIMEOUT:		/* Return write stall timeout */
		data[0] = ((dra->wtimoticks)*10)/hz;
		break;
E 7

D 7
    case DRWRITEREADY:
	/* Returns a value of 1 if the device can accept
	   data, 0 otherwise. Internally this is the
	   DR11-W STAT A bit. */
E 7
I 7
	case DRWRITEREADY:		/* Return true if can write data */
		data[0] = (rsaddr->dr_cstat & STTA)? 1 : 0;
		break;
E 7

D 7
	data[0] = (rsaddr->dr_cstat & STTA)? 1 : 0;
	break;
E 7
I 7
	case DRREADREADY:		/* Return true if data to be read */
		data[0] = (rsaddr->dr_cstat & STTB)? 1 : 0;
		break;
E 7

D 7
    case DRREADREADY:
	/* Returns a value of 1 if the device has data
	   for host to be read, 0 otherwise. Internally
	   this is the DR11-W STAT B bit. */
	data[0] = (rsaddr->dr_cstat & STTB)? 1 : 0;
	break;
E 7
I 7
	case DRBUSY:			/* Return true if device busy */
		/*
		 * Internally this is the DR11-W
		 * STAT C bit, but there is a bug in the Omega 500/FIFO
		 * interface board that it cannot drive this signal low
		 * for certain DR11-W ctlr such as the Ikon. We use the
		 * REDY signal of the CSR on the Ikon DR11-W instead. 
		 */
#ifdef notdef
		data[0] = (rsaddr->dr_cstat & STTC)? 1 : 0;
#else
		data[0] = ((rsaddr->dr_cstat & REDY)? 0 : 1);
#endif
		break;
E 7

D 7
    case DRBUSY:
	/* Returns a value of 1 if the device is busy,
	   0 otherwise. Internally this is the DR11-W
	   STAT C bit, but there is a bug in the Omega 500/FIFO interface
	   board that it cannot drive this signal low for certain DR11-W
	   ctlr such as the Ikon. We use the REDY signal of the CSR on
	   the Ikon DR11-W instead. 
E 7
I 7
	case DRRESET:			/* Reset device */
		/* Reset DMA ATN RPER flag */
		rsaddr->dr_pulse = (MCLR|RDMA|RATN|RPER);
		DELAY(0x1f000);
		while ((rsaddr->dr_cstat & REDY) == 0)
			sleep((caddr_t)dra, DRPRI);	/* Wakeup by drtimo() */
		dra->dr_istat = 0;
		dra->dr_cmd = 0;
		dra->currenttimo = 0;
		break;
E 7

D 7
	data[0] = (rsaddr->dr_cstat & STTC)? 1 : 0;
	*/

	data[0] = ((rsaddr->dr_cstat & REDY)? 0 : 1);
	break;

    case DRRESET:
	rsaddr->dr_pulse = (MCLR|RDMA|RATN|RPER);/* Reset DMA ATN RPER flag */
	DELAY(0x1f000);
	while (!(rsaddr->dr_cstat & REDY)) {
		sleep((caddr_t)dra, DRPRI);	/* Wakeup by drtimo() */
E 7
I 7
	case DR11STAT: {		/* Copy back dr11 status to user */
		register struct dr11io *dr = (struct dr11io *)data;
		dr->arg[0] = dra->dr_flags;
		dr->arg[1] = rsaddr->dr_cstat;
		dr->arg[2] = dra->dr_istat;	/* Status at last interrupt */
		dr->arg[3] = rsaddr->dr_data;	/* P-i/o input data */
		status = (u_short)((rsaddr->dr_addmod << 8) & 0xff00);
		dr->arg[4] = status | (u_short)(rsaddr->dr_intvect & 0xff);
		dr->arg[5] = rsaddr->dr_range;
		dr->arg[6] = rsaddr->dr_rahi;
		dr->arg[7] = rsaddr->dr_ralo;
		break;
E 7
	}
D 7
    	dra->dr_istat = 0;
    	dra->dr_cmd = 0;
    	dra->currenttimo = 0;
	break;
E 7
I 7
	case DR11LOOP:			/* Perform loopback test */
		/*
		 * NB: MUST HAVE LOOPBACK CABLE ATTACHED --
		 * Test results are printed on system console
		 */
		if (suser())
			dr11loop(rsaddr, dra, unit);
		break;
E 7

I 3
D 4
    case DR11STAT:
E 4
I 4
D 7
    case DR11STAT: {
	register struct dr11io *dr = (struct dr11io *)data;
E 4
    	/* Copy back dr11 status to user */
D 4
    	data->arg[0] = dra->dr_flags;
    	data->arg[1] = rsaddr->dr_cstat;
    	data->arg[2] = dra->dr_istat;	/* Status reg. at last interrupt */
    	data->arg[3] = rsaddr->dr_data;	/* P-i/o input data */
E 4
I 4
    	dr->arg[0] = dra->dr_flags;
    	dr->arg[1] = rsaddr->dr_cstat;
    	dr->arg[2] = dra->dr_istat;	/* Status reg. at last interrupt */
    	dr->arg[3] = rsaddr->dr_data;	/* P-i/o input data */
E 4
    	status = (ushort)((rsaddr->dr_addmod << 8) & 0xff00);
D 4
    	data->arg[4] = status | (ushort)(rsaddr->dr_intvect & 0xff);
    	data->arg[5] = rsaddr->dr_range;
    	data->arg[6] = rsaddr->dr_rahi;
    	data->arg[7] = rsaddr->dr_ralo;
E 4
I 4
    	dr->arg[4] = status | (ushort)(rsaddr->dr_intvect & 0xff);
    	dr->arg[5] = rsaddr->dr_range;
    	dr->arg[6] = rsaddr->dr_rahi;
    	dr->arg[7] = rsaddr->dr_ralo;
E 4
	break;
I 4
    }
E 4
    case DR11LOOP:
	/* Perform loopback test -- MUST HAVE LOOPBACK CABLE ATTACHED --
	   Test results are printed on system console */
	if (suser())
		dr11loop(rsaddr,dra,unit);
	break;

E 3
    default:
	printf("\ndrioctl: Invalid ioctl cmd : %lx",cmd);
	return EINVAL;
    }

E 7
I 7
	default:
		return (EINVAL);
	}
E 7
#ifdef DR_DEBUG
D 7
    if (DR11 & 0x10)
    	printf("**** (data[0]:%lx)",data[0]);
E 7
I 7
	if (DR11 & 0x10)
		printf("**** (data[0]:%lx)",data[0]);
E 7
#endif
D 7
    return 0;
E 7
I 7
	return (0);
E 7
I 3
}

D 7
#define NPAT 2
#define DMATBL 20
ushort tstpat[DMATBL] = { 0xAAAA, 0x5555};
long DMAin = 0;
E 7
I 7
#define NPAT	2
#define DMATBL	20
u_short	tstpat[DMATBL] = { 0xAAAA, 0x5555};
long	DMAin = 0;
E 7

D 7
dr11loop(dr,dra,unit)
struct rsdevice *dr;
struct dr_aux *dra;
long unit;
{	register long result, ix;
	long baddr, wait;
E 7
I 7
/*
 * Perform loopback test -- MUST HAVE LOOPBACK CABLE ATTACHED
 * Test results are printed on system console
 */
dr11loop(dr, dra, unit)
	struct rsdevice *dr;
	struct dr_aux *dra;
	int unit;
{
	register long result, ix;
	long addr, wait;
E 7

	dr->dr_cstat = MCLR;		/* Clear board & device, disable intr */
D 7

	/* Perform loopback test -- MUST HAVE LOOPBACK CABLE ATTACHED --
	   Test results are printed on system console */
	printf("\n\t ----- DR11 unit %ld loopback test -----",unit);

E 7
I 7
	printf("\n\t ----- DR11 unit %ld loopback test -----", unit);
E 7
	printf("\n\t Program I/O ...");
	for (ix=0;ix<NPAT;ix++) {
		dr->dr_data = tstpat[ix];	/* Write to Data out register */
D 7
		result = (dr->dr_data & 0xFFFF);	/* Read it back */
E 7
I 7
		result = dr->dr_data & 0xFFFF;	/* Read it back */
E 7
		if (result != tstpat[ix]) {
			printf("Failed, expected : %lx --- actual : %lx",
D 7
				tstpat[ix],result);
E 7
I 7
				tstpat[ix], result);
E 7
			return;
		}
	}
D 7

E 7
	printf("OK\n\t Functions & Status Bits ...");
	dr->dr_cstat = (FCN1 | FCN3);
	result = dr->dr_cstat & 0xffff;		/* Read them back */
	if ((result & (STTC | STTA)) != (STTC |STTA)) {
		printf("Failed, expected : %lx --- actual : %lx, ISR:%lx",
D 7
			(STTA|STTC),(result & (STTA|STTC)), result);
E 7
I 7
			(STTA|STTC), (result & (STTA|STTC)), result);
E 7
		return;
	}
	dr->dr_cstat = FCN2;
	result = dr->dr_cstat & 0xffff;		/* Read them back */
	if ((result & STTB) != STTB) {
		printf("Failed, expected : %lx --- actual : %lx, ISR:%lx",
D 7
			STTB,(result & STTB), result);
E 7
I 7
			STTB, (result & STTB), result);
E 7
		return;
	}
D 7

E 7
	printf("OK\n\t DMA output ...");
D 7

	if (DMAin) goto dmain;

E 7
I 7
	if (DMAin)
		goto dmain;
E 7
	/* Initialize DMA data buffer */
D 7
	for(ix=0;ix<DMATBL;ix++) tstpat[ix] = 0xCCCC + ix;
E 7
I 7
	for (ix=0; ix<DMATBL; ix++)
		tstpat[ix] = 0xCCCC + ix;
E 7
	tstpat[DMATBL-1] = 0xCCCC;	/* Last word output */
D 7

E 7
	/* Setup normal DMA */
D 7
	baddr = (long)vtoph(0,tstpat);		/* Virtual --> physical */
    	dr->dr_walo = (ushort)((baddr >> 1) & 0xffff);
    	dr->dr_wahi = (ushort)((baddr >> 17) & 0x7fff);
E 7
I 7
	addr = (long)vtoph((struct proc *)0, (unsigned)tstpat);
	dr->dr_walo = (addr >> 1) & 0xffff;
	dr->dr_wahi = (addr >> 17) & 0x7fff;
	/* Set DMA range count: (number of words - 1) */
	dr->dr_range = DMATBL - 1;
	/* Set address modifier code to be used for DMA access to memory */
	dr->dr_addmod = DRADDMOD;
E 7

D 7
    	/* Set DMA range count: (number of words - 1) */
    	dr->dr_range = (ushort)(DMATBL - 1);
E 7
I 7
	/*
	 * Clear dmaf and attf to assure a clean dma start, also disable
	 * attention interrupt
	 */
	dr->dr_pulse = RDMA|RATN|RMSK;  /* Use pulse register */
	dr->dr_cstat = GO|CYCL;		  /* GO...... */
E 7

D 7
    	/* Set  address modifier code to be used for DMA access to memory */
    	dr->dr_addmod = (char)DRADDMOD;

    	/* Clear dmaf and attf to assure a clean dma start, also disable
	   attention interrupt
	*/
    	dr->dr_pulse = (ushort)(RDMA|RATN|RMSK);  /* Use pulse register */
    	dr->dr_cstat = (GO|CYCL);		  /* GO...... */

E 7
	/* Wait for DMA complete; REDY and DMAF are true in ISR */
	wait = 0;
D 7
	while ((result=(dr->dr_cstat & (REDY | DMAF))) != (REDY|DMAF)) {
		printf("\n\tWait for DMA complete...ISR : %lx",result);
E 7
I 7
	while ((result=(dr->dr_cstat & (REDY|DMAF))) != (REDY|DMAF)) {
		printf("\n\tWait for DMA complete...ISR : %lx", result);
E 7
		if (++wait > 5) {
			printf("\n\t DMA output fails...timeout!!, ISR:%lx",
				result);
			return;
		}
	}
D 7

E 7
	result = dr->dr_data & 0xffff;		/* Read last word output */	
	if (result != 0xCCCC) {
		printf("\n\t Fails, expected : %lx --- actual : %lx",
D 7
			0xCCCC,result);
E 7
I 7
			0xCCCC, result);
E 7
		return;
	}
D 7

E 7
	printf("OK\n\t DMA input ...");
D 7

E 7
dmain:
	dr->dr_data = 0x1111;		/* DMA input data */
	/* Setup normal DMA */
D 7
	baddr = (long)vtoph(0,tstpat);		/* Virtual --> physical */
    	dr->dr_walo = (ushort)((baddr >> 1) & 0xffff);
    	dr->dr_wahi = (ushort)((baddr >> 17) & 0x7fff);

    	/* Set DMA range count: (number of words - 1) */
    	dr->dr_range = (ushort)(DMATBL - 1);

    	/* Set  address modifier code to be used for DMA access to memory */
    	dr->dr_addmod = (char)DRADDMOD;
	/* Set FCN1 in ICR to DMA in*/
	dr->dr_cstat = FCN1;

	if (!(dra->dr_flags & DR_LOOPTST)) {
E 7
I 7
	addr = (long)vtoph((struct proc *)0, (unsigned)tstpat);
	dr->dr_walo = (addr >> 1) & 0xffff;
	dr->dr_wahi = (addr >> 17) & 0x7fff;
	dr->dr_range = DMATBL - 1;
	dr->dr_addmod = (char)DRADDMOD;
	dr->dr_cstat = FCN1;		/* Set FCN1 in ICR to DMA in*/
	if ((dra->dr_flags & DR_LOOPTST) == 0) {
E 7
		/* Use pulse reg */  
D 7
    		dr->dr_pulse = (ushort)(RDMA|RATN|RMSK|CYCL|GO);
E 7
I 7
		dr->dr_pulse = RDMA|RATN|RMSK|CYCL|GO;
E 7
		/* Wait for DMA complete; REDY and DMAF are true in ISR */
		wait = 0;
D 7
		while ((result=(dr->dr_cstat & (REDY | DMAF))) 
						!= (REDY|DMAF)) {
E 7
I 7
		while ((result=(dr->dr_cstat & (REDY|DMAF))) != (REDY|DMAF)) {
E 7
			printf("\n\tWait for DMA to complete...ISR:%lx",result);
			if (++wait > 5) {
				printf("\n\t DMA input timeout!!, ISR:%lx",
					result);
				return;
			}
		}
D 7
	}
	else  {
E 7
I 7
	} else  {
E 7
		/* Enable DMA e-o-r interrupt */
D 7
    		dr->dr_pulse = (ushort)(IENB|RDMA|RATN|CYCL|GO);
E 7
I 7
		dr->dr_pulse = IENB|RDMA|RATN|CYCL|GO;
E 7
		/* Wait for DMA complete; DR_LOOPTST is false in dra->dr_flags*/
		wait = 0;
		while (dra->dr_flags & DR_LOOPTST) { 
			result = dr->dr_cstat & 0xffff;
D 7
			printf("\n\tWait for DMA e-o-r intr...ISR:%lx",result);
E 7
I 7
			printf("\n\tWait for DMA e-o-r intr...ISR:%lx", result);
E 7
			if (++wait > 7) {
				printf("\n\t DMA e-o-r timeout!!, ISR:%lx",
					result);
				dra->dr_flags &= ~DR_LOOPTST;
				return;
			}
		}
		dra->dr_flags |= DR_LOOPTST;
	}
D 7

	mtpr(tstpat,P1DC);			/* Purge cache */
	mtpr((0x3ff+(long)tstpat),P1DC);
	for(ix=0;ix<DMATBL;ix++) {
E 7
I 7
	mtpr(P1DC, tstpat);			/* Purge cache */
	mtpr(P1DC, 0x3ff+tstpat);
	for (ix=0; ix<DMATBL; ix++) {
E 7
		if (tstpat[ix] != 0x1111) {
D 7
			printf("\n\t Fails, ix:%ld,expected : %lx --- actual : %lx",
				ix,0x1111,tstpat[ix]);
E 7
I 7
			printf("\n\t Fails, ix:%d, expected:%x --- actual:%x",
				ix, 0x1111, tstpat[ix]);
E 7
			return;
		}
	}
D 7
	if (!(dra->dr_flags & DR_LOOPTST)) {
E 7
I 7
	if ((dra->dr_flags & DR_LOOPTST) == 0) {
E 7
		dra->dr_flags |= DR_LOOPTST;
		printf(" OK..\n\tDMA end of range interrupt...");
		goto dmain;
	}
D 7


E 7
	printf(" OK..\n\tAttention interrupt....");
D 7
	/* Pulse FCN2 in pulse register with IENB */
    	dr->dr_pulse = (ushort)(IENB|RDMA);
    	dr->dr_pulse = (ushort)FCN2;

E 7
I 7
	dr->dr_pulse = IENB|RDMA;
	dr->dr_pulse = FCN2;
E 7
	/* Wait for ATTN interrupt; DR_LOOPTST is false in dra->dr_flags*/
	wait = 0;
	while (dra->dr_flags & DR_LOOPTST) { 
		result = dr->dr_cstat & 0xffff;
		printf("\n\tWait for Attention intr...ISR:%lx",result);
		if (++wait > 7) {
			printf("\n\t Attention interrupt timeout!!, ISR:%lx",
				result);
			dra->dr_flags &= ~DR_LOOPTST;
			return;
		}
	}
	dra->dr_flags &= ~DR_LOOPTST;
	printf(" OK..\n\tDone...");
E 3
}

/* Reset state on Unibus reset */
I 7
/*ARGSUSED*/
E 7
drreset(uban)
D 7
int uban;
E 7
I 7
	int uban;
E 7
{
D 7
    register int i;
    register struct vba_device *ui;
    register struct dr_aux *dra;
E 7

D 7
    for (i = 0; i < NDR; i++, dra++) {
	if (   (ui = drinfo[i]) == 0
	    || !ui->ui_alive
	    || ui->ui_vbanum != uban
	   )
	    continue;
	printf("\ndrreset: %ld",i);
	/* Do something; reset board */
    }
    return;
E 7
}

/*
 * An interrupt is caused either by an error,
 * base address overflow, or transfer complete
 */
D 7
drintr (unit)
register long unit;
E 7
I 7
drintr(dr11)
	int dr11;
E 7
{
D 7
    register struct dr_aux *dra = &dr_aux[unit];
    register struct rsdevice *rsaddr = RSADDR(unit);
    register struct buf *bp;
    register short status, csrtmp;
E 7
I 7
	register struct dr_aux *dra = &dr_aux[dr11];
	register struct rsdevice *rsaddr = RSADDR(dr11);
	register struct buf *bp;
	register short status;
E 7

D 7
    status = rsaddr->dr_cstat & 0xffff;		/* get board status register */
    dra->dr_istat = status;

E 7
I 7
	status = rsaddr->dr_cstat & 0xffff;	/* get board status register */
	dra->dr_istat = status;
E 7
#ifdef DR_DEBUG
D 7
    if (DR11 & 2)
    	printf("\ndrintr: dr11 status : %lx",status & 0xffff);
E 7
I 7
	if (DR11 & 2)
		printf("\ndrintr: dr11 status : %lx",status & 0xffff);
E 7
#endif
I 7
	if (dra->dr_flags & DR_LOOPTST) {	/* doing loopback test */
		dra->dr_flags &= ~DR_LOOPTST;
		return;
	}
	/*
	 * Make sure this is not a stray interrupt; at least one of dmaf or attf
	 * must be set. Note that if the dr11 interrupt enable latch is reset 
	 * during a hardware interrupt ack sequence, and by the we get to this 
	 * point in the interrupt code it will be 0. This is done to give the
	 * programmer some control over how the two more-or-less independent
	 * interrupt sources on the board are handled.
	 * If the attention flag is set when drstrategy() is called to start a
	 * dma read or write an interrupt will be generated as soon as the
	 * strategy routine enables interrupts for dma end-of-range. This will
	 * cause execution of the interrupt routine (not necessarily bad) and
	 * will cause the interrupt enable mask to be reset (very bad since the
	 * dma end-of-range condition will not be able to generate an interrupt
	 * when it occurs) causing the dma operation to time-out (even though
	 * the dma transfer will be done successfully) or hang the process if a
	 * software time-out capability is not implemented. One way to avoid 
	 * this situation is to check for a pending attention interrupt (attf
	 * set) by calling drioctl() before doing a read or a write. For the
	 * time being this driver will solve the problem by clearing the attf
	 * flag in the status register before enabling interrupts in
	 * drstrategy().
	 *
	 * **** The IKON 10084 for which this driver is written will set both
	 * attf and dmaf if dma is terminated by an attention pulse. This will
	 * cause a wakeup(&dr_aux), which will be ignored since it is not being 
	 * waited on, and an iodone(bp) which is the desired action. Some other
	 * dr11 emulators, in particular the IKON 10077 for the Multibus, donot
	 * dmaf in this case. This may require some addtional code in the inter-
	 * rupt routine to ensure that en iodone(bp) is issued when dma is term-
	 * inated by attention.
	 */
	bp = dra->dr_actf;
	if ((status & (ATTF | DMAF)) == 0) {
		printf("dr%d: stray interrupt, status=%x", dr11, status);
		return;
	}
	if (status & DMAF) {		/* End-of-range interrupt */
		dra->dr_flags |= DR_DMAX;
E 7

D 7
    if (dra->dr_flags & DR_LOOPTST) {
	/* Controller is doing loopback test */
    	dra->dr_flags &= ~DR_LOOPTST;
	return;
    }

    /* Make sure this is not a stray interrupt; at least one of dmaf or attf
       must be set. Note that if the dr11 interrupt enable latch is reset 
       during a hardware interrupt ack sequence, and by the we get to this 
       point in the interrupt code it will be 0. This is done to give the
       programmer some control over how the two more-or-less independent
       interrupt sources on the board are handled.
       If the attention flag is set when drstrategy() is called to start a
       dma read or write an interrupt will be generated as soon as the
       strategy routine enables interrupts for dma end-of-range. This will
       cause execution of the interrupt routine (not necessarily bad) and
       will cause the interrupt enable mask to be reset (very bad since the
       dma end-of-range condition will not be able to generate an interrupt
       when it occurs) causing the dma operation to time-out (even though
       the dma transfer will be done successfully) or hang the process if a
       software time-out capability is not implemented. One way to avoid 
       this situation is to check for a pending attention interrupt (attf
       set) by calling drioctl() before doing a read or a write. For the
       time being this driver will solve the problem by clearing the attf
       flag in the status register before enabling interrupts in drstrategy().

       **** The IKON 10084 for which this driver is written will set both
       attf and dmaf if dma is terminated by an attention pulse. This will
       cause a wakeup(&dr_aux), which will be ignored since it is not being 
       waited on, and an iodone(bp) which is the desired action. Some other
       dr11 emulators, in particular the IKON 10077 for the Multibus, donot
       dmaf in this case. This may require some addtional code in the inter-
       rupt routine to ensure that en iodone(bp) is issued when dma is term-
       inated by attention.
    */

    bp = dra->dr_actf;
    if (!(status & (ATTF | DMAF))) {
	printf("\ndrintr: Stray interrupt, dr11 status : %lx",status);
	return;
    }
    if (status & DMAF) {
	/* End-of-range interrupt */
	dra->dr_flags |= DR_DMAX;

E 7
#ifdef DR_DEBUG
D 7
    if (DR11 & 2)
	printf("\ndrintr: e-o-r interrupt,cstat:%lx,dr_flags:%lx",
		status&0xffff,dra->dr_flags & DR_ACTV);
E 7
I 7
		if (DR11 & 2)
		printf("\ndrintr: e-o-r interrupt,cstat:%lx,dr_flags:%lx",
			status&0xffff, dra->dr_flags & DR_ACTV);
E 7
#endif
D 7
	if (!(dra->dr_flags & DR_ACTV)) {
		/* We are not doing DMA !! */
		bp->b_flags |= B_ERROR;
	}
	else {
		if (dra->dr_op == DR_READ) mtpr(bp->b_un.b_addr,P1DC);
		dra->dr_bycnt -= bp->b_bcount;
		if (dra->dr_bycnt >0) {
			bp->b_un.b_addr += bp->b_bcount;
			bp->b_bcount = (dra->dr_bycnt > NBPG) ? NBPG:
E 7
I 7
		if ((dra->dr_flags & DR_ACTV) == 0) {
			/* We are not doing DMA !! */
			bp->b_flags |= B_ERROR;
		} else {
			if (dra->dr_op == DR_READ)
				mtpr(P1DC, bp->b_un.b_addr);
			dra->dr_bycnt -= bp->b_bcount;
			if (dra->dr_bycnt >0) {
				bp->b_un.b_addr += bp->b_bcount;
				bp->b_bcount = (dra->dr_bycnt > NBPG) ? NBPG:
E 7
					dra->dr_bycnt;
D 7
			drstart(rsaddr,dra,bp);
			return;
E 7
I 7
				drstart(rsaddr, dra, bp);
				return;
			}
E 7
		}
I 7
		dra->dr_flags &= ~DR_ACTV;
		wakeup((caddr_t)dra);		/* Wakeup waiting in drwait() */
		rsaddr->dr_pulse = (RPER|RDMA|RATN); /* reset dma e-o-r flag */
E 7
	}
D 7
	dra->dr_flags &= ~DR_ACTV;
	wakeup(dra);			/* Wakeup proc waiting in drwait() */
	rsaddr->dr_pulse = (RPER|RDMA|RATN);	/* reset dma e-o-r flag */
    }

    /* Now test for attention interrupt -- It may be set in addition to 
       the dma e-o-r interrupt. If we get one we will issue a wakeup to
       the drioctl() routine which is presumable waiting for one.
       The program may have to monitor the attention interrupt received
       flag in addition to doing waits for the interrupt. Futhermore, 
       interrupts are not enabled unless dma is in progress or drioctl()
       has been called to wait for attention -- this may produce some
       strange results if attf is set on the dr11 when a read or a write
       is initiated, since that will enables interrupts.
       **** The appropriate code for this interrupt routine will probably
       be rather application dependent.
    */

    if (status & ATTF) {
	dra->dr_flags |= DR_ATRX;
	dra->dr_flags &= ~DR_ATWT;
	rsaddr->dr_cstat = RATN;	/* reset attention flag */
	wakeup((caddr_t)&dra->dr_cmd);
	/* Some applications which use attention to terminate dma may also
	   want to issue an iodone() here to wakeup physio().
 	*/
    }
    return;
E 7
I 7
	/*
	 * Now test for attention interrupt -- It may be set in addition to 
	 * the dma e-o-r interrupt. If we get one we will issue a wakeup to
	 * the drioctl() routine which is presumable waiting for one.
	 * The program may have to monitor the attention interrupt received
	 * flag in addition to doing waits for the interrupt. Futhermore, 
	 * interrupts are not enabled unless dma is in progress or drioctl()
	 * has been called to wait for attention -- this may produce some
	 * strange results if attf is set on the dr11 when a read or a write
	 * is initiated, since that will enables interrupts.
	 * **** The appropriate code for this interrupt routine will probably
	 * be rather application dependent.
	 */
	if (status & ATTF) {
		dra->dr_flags |= DR_ATRX;
		dra->dr_flags &= ~DR_ATWT;
		rsaddr->dr_cstat = RATN;	/* reset attention flag */
		/*
		 * Some applications which use attention to terminate
		 * dma may also want to issue an iodone() here to
		 * wakeup physio().
		 */
		wakeup((caddr_t)&dra->dr_cmd);
	}
E 7
}

unsigned
drminphys(bp)
D 7
struct buf *bp;
E 7
I 7
	struct buf *bp;
E 7
{
D 7
    if (bp->b_bcount > 65536)
	bp->b_bcount = 65536;
E 7
I 7

	if (bp->b_bcount > 65536)
		bp->b_bcount = 65536;
E 7
}

/*
D 7
 *  This routine performs the device unique operations on the DR11W
 *  it is passed as an argument to and invoked by physio
E 7
I 7
 * This routine performs the device unique operations on the DR11W
 * it is passed as an argument to and invoked by physio
E 7
 */
drstrategy (bp)
D 7
register struct buf *bp;
E 7
I 7
	register struct buf *bp;
E 7
{
D 7
    register int s;
    int unit = RSUNIT(bp->b_dev);
    register struct rsdevice *rsaddr = RSADDR(unit);
    register struct dr_aux *dra = &dr_aux[unit];
    register short go = 0;
    register long baddr, ok;
E 7
I 7
	register int s;
	int unit = RSUNIT(bp->b_dev);
	register struct rsdevice *rsaddr = RSADDR(unit);
	register struct dr_aux *dra = &dr_aux[unit];
	register int ok;
E 7
#ifdef DR_DEBUG
D 7
    register char *caddr;
    long drva();
E 7
I 7
	register char *caddr;
	long drva();
E 7
#endif

D 7

    if (!(dra->dr_flags & DR_OPEN)) {
	/* Device not open */
	bp->b_error = ENXIO;
	bp->b_flags |= B_ERROR;
	iodone (bp);
	return;
    }

    while (dra->dr_flags & DR_ACTV) {
	/* Device is active; should never be in here... */
	sleep((caddr_t)&dra->dr_flags,DRPRI);
    }

    dra->dr_actf = bp;

E 7
I 7
	if ((dra->dr_flags & DR_OPEN) == 0) {	/* Device not open */
		bp->b_error = ENXIO;
		bp->b_flags |= B_ERROR;
		iodone (bp);
		return;
	}
	while (dra->dr_flags & DR_ACTV)
		/* Device is active; should never be in here... */
		sleep((caddr_t)&dra->dr_flags,DRPRI);
	dra->dr_actf = bp;
E 7
#ifdef DR_DEBUG
D 7
    drva(dra,bp->b_proc,bp->b_un.b_addr,bp->b_bcount);
E 7
I 7
	drva(dra, bp->b_proc, bp->b_un.b_addr, bp->b_bcount);
E 7
#endif
D 7

    dra->dr_oba = bp->b_un.b_addr;	/* Save original addr, count */
    dra->dr_obc = bp->b_bcount;
    dra->dr_bycnt = bp->b_bcount;	/* Save xfer count used by drintr() */

    if ((((long)bp->b_un.b_addr & 0x3fffffff) >> PGSHIFT) !=
	((((long)bp->b_un.b_addr & 0x3fffffff) + bp->b_bcount) >> PGSHIFT)) {
    	bp->b_bcount = NBPG - (((long)bp->b_un.b_addr) & PGOFSET);
    }

    dra->dr_flags |= DR_ACTV;	/* Mark it active (use in intr handler) */
    s = SPL_UP();
    drstart(rsaddr,dra,bp);
    splx(s);

    ok = drwait(rsaddr,dra);
E 7
I 7
	dra->dr_oba = bp->b_un.b_addr;	/* Save original addr, count */
	dra->dr_obc = bp->b_bcount;
	dra->dr_bycnt = bp->b_bcount;	/* Save xfer count used by drintr() */
	if ((((long)bp->b_un.b_addr & 0x3fffffff) >> PGSHIFT) !=
	    ((((long)bp->b_un.b_addr & 0x3fffffff) + bp->b_bcount) >> PGSHIFT))
		bp->b_bcount = NBPG - (((long)bp->b_un.b_addr) & PGOFSET);
	dra->dr_flags |= DR_ACTV;	/* Mark active (use in intr handler) */
	s = SPL_UP();
	drstart(rsaddr,dra,bp);
	splx(s);
	ok = drwait(rsaddr,dra);
E 7
#ifdef DR_DEBUG
D 7
    if (DR11 & 0x40) {
	caddr = (char *)dra->dr_oba;
    	if (dra->dr_op == DR_READ)
		printf("\nAfter read: (%lx)(%lx)",caddr[0]&0xff,caddr[1]&0xff);
    }
E 7
I 7
	if (DR11 & 0x40) {
		caddr = (char *)dra->dr_oba;
		if (dra->dr_op == DR_READ)
			printf("\nAfter read: (%lx)(%lx)",
			    caddr[0]&0xff, caddr[1]&0xff);
	}
E 7
#endif
D 7
    dra->dr_flags &= ~DR_ACTV;		/* Clear active flag */
    bp->b_un.b_addr = dra->dr_oba;	/* Restore original addr, count */
    bp->b_bcount = dra->dr_obc;

    if (!ok) bp->b_flags |= B_ERROR;
    iodone(bp);				/* Mark buffer B_DONE,so physstrat()
					   in ml/machdep.c won't sleep */
    wakeup((caddr_t)&dra->dr_flags);

    /* Return to the calling program (physio()). Physio() will sleep
       until awaken by a call to iodone() in the interupt handler --
       which will be called by the dispatcher when it receives dma
       end-of-range interrupt.
    */
    return;
E 7
I 7
	dra->dr_flags &= ~DR_ACTV;		/* Clear active flag */
	bp->b_un.b_addr = dra->dr_oba;	/* Restore original addr, count */
	bp->b_bcount = dra->dr_obc;
	if (!ok)
		bp->b_flags |= B_ERROR;
	/* Mark buffer B_DONE,so physstrat() in ml/machdep.c won't sleep */
	iodone(bp);			
	wakeup((caddr_t)&dra->dr_flags);
	/*
	 * Return to the calling program (physio()). Physio() will sleep
	 * until awaken by a call to iodone() in the interupt handler --
	 * which will be called by the dispatcher when it receives dma
	 * end-of-range interrupt.
	 */
E 7
}

D 7
drwait(rs,dr)
register struct rsdevice *rs;
register struct dr_aux *dr;
E 7
I 7
drwait(rs, dr)
	register struct rsdevice *rs;
	register struct dr_aux *dr;
E 7
{
D 7
	register long status, s;
E 7
I 7
	int s;
E 7

	s = SPL_UP();
D 7
    	while (dr->dr_flags & DR_ACTV)
		sleep((caddr_t)dr,DRPRI);
E 7
I 7
	while (dr->dr_flags & DR_ACTV)
		sleep((caddr_t)dr, DRPRI);
E 7
	splx(s);
D 7

	if (dr->dr_flags & DR_TMDM) {
		/* DMA timed out */
E 7
I 7
	if (dr->dr_flags & DR_TMDM) {		/* DMA timed out */
E 7
		dr->dr_flags &= ~DR_TMDM;
D 7
		return(0);
E 7
I 7
		return (0);
E 7
	}
D 7
	else {
		if (rs->dr_cstat & (PERR|BERR|TERR)) {
			(dr->dr_actf)->b_flags |= B_ERROR;
			return(0);
		}
E 7
I 7
	if (rs->dr_cstat & (PERR|BERR|TERR)) {
		dr->dr_actf->b_flags |= B_ERROR;
		return (0);
E 7
	}
	dr->dr_flags &= ~DR_DMAX;
D 7
	return(1);
E 7
I 7
	return (1);
E 7
}

D 7

drrwtimo(tinfo)
register unsigned long tinfo;
E 7
/*
D 7
 * 	The lower 8-bit of tinfo is the minor device number, the
 *	remaining higher 8-bit is the current timout number
*/
{	register long unit = tinfo & 0xff;
E 7
I 7
 *
 * The lower 8-bit of tinfo is the minor device number, the
 * remaining higher 8-bit is the current timout number
 */
drrwtimo(tinfo)
	register u_long tinfo;
{
	register long unit = tinfo & 0xff;
E 7
	register struct dr_aux *dr = &dr_aux[unit];
	register struct rsdevice *rs = dr->dr_addr;

D 7
	/* If this is not the timeout that drwrite/drread is waiting
	   for then we should just go away */
	if ((tinfo & (~0xff)) != (dr->currenttimo << 8)) return;

E 7
I 7
	/*
	 * If this is not the timeout that drwrite/drread is waiting
	 * for then we should just go away
	 */
	if ((tinfo &~ 0xff) != (dr->currenttimo << 8))
		return;
E 7
	/* Mark the device timed out */
	dr->dr_flags |= DR_TMDM;
	dr->dr_flags &= ~DR_ACTV;
	rs->dr_pulse = RMSK;			/* Inihibit interrupt */
	rs->dr_pulse = (RPER|RDMA|RATN|IENB);	/* Clear DMA logic */
D 7

	/* Some applications will not issue a master after dma timeout,
	   since doing so sends an INIT H pulse to the external device,
	   which may produce undesirable side-effects.  */

E 7
I 7
	/*
	 * Some applications will not issue a master after dma timeout,
	 * since doing so sends an INIT H pulse to the external device,
	 * which may produce undesirable side-effects.
	 */
E 7
	/* Wake up process waiting in drwait() and flag the error */
D 7
	(dr->dr_actf)->b_flags |= B_ERROR;
E 7
I 7
	dr->dr_actf->b_flags |= B_ERROR;
E 7
	wakeup((caddr_t)dr->dr_cmd);
}

D 7

E 7
/*
D 7
 *	Kick the driver every second
*/
E 7
I 7
 * Kick the driver every second
 */
E 7
drtimo(dev)
D 7
dev_t dev;
E 7
I 7
	dev_t dev;
E 7
{
D 7
    	register int unit = RSUNIT(dev);
E 7
I 7
	register int unit = RSUNIT(dev);
E 7
	register struct dr_aux *dr;

D 7
    	dr = &dr_aux[unit];
E 7
I 7
	dr = &dr_aux[unit];
E 7
	if (dr->dr_flags & DR_OPEN)
D 7
		timeout(drtimo,(caddr_t)dev,hz);
E 7
I 7
		timeout(drtimo, (caddr_t)dev, hz);
E 7
	wakeup((caddr_t)dr);	/* Wakeup any process waiting for interrupt */
}

D 7

E 7
#ifdef DR_DEBUG
I 7
drva(dra, p, va, bcnt)
	struct dr_aux *dra;
	struct proc *p;
	char *va;
	long bcnt;
{
	register long first, last , np;
E 7

D 7
drva(dra,p,va,bcnt)
struct dr_aux *dra;
struct proc *p;
char *va;
long bcnt;
{	register long first, last , np;

E 7
	if (DR11 & 0x20)  {
D 7
		first = ((long)(vtoph(p,va))) >> 10;
		last = ((long)(vtoph(p,va+bcnt))) >> 10;
E 7
I 7
		first = ((long)(vtoph(p, (unsigned)va))) >> 10;
		last = ((long)(vtoph(p, (unsigned)va+bcnt))) >> 10;
E 7
		np = bcnt / 0x3ff;
		printf("\ndrva: (op:%ld)(first:%ld)(last:%ld)(np:%ld)(cnt:%ld)",
			dra->dr_op,first,last,np,bcnt);
	}
}
#endif

I 7
drstart(rsaddr, dra, bp)
	register struct rsdevice *rsaddr;
	register struct dr_aux *dra;
	register struct buf *bp;
{
	register long addr;
	u_short go;
E 7

D 7
drstart(rsaddr,dra,bp)
register struct rsdevice *rsaddr;
register struct dr_aux *dra;
register struct buf *bp;
{	register long baddr;
	ushort go;
	register char *caddr;

E 7
#ifdef DR_DEBUG
D 7
	if ((dra->dr_op == DR_READ) && (DR11 & 8)) {
E 7
I 7
	if (dra->dr_op == DR_READ && (DR11 & 8)) {
		char *caddr = (char *)bp->b_un.b_addr;
E 7
		printf("\ndrstart: READ, bcnt:%ld",bp->b_bcount);
D 7
    		caddr = (char *)bp->b_un.b_addr;
E 7
		printf(",(%lx)(%lx)",caddr[0]&0xff,caddr[1]&0xff);
	}
#endif
D 7
    /* we are doing raw IO, bp->b_un.b_addr is user's address */
    baddr = (long)vtoph(bp->b_proc,(caddr_t)bp->b_un.b_addr);

    /* Set DMA address into DR11 interace registers: DR11 requires that
       the address be right shifted 1 bit position before it is written
       to the board (The board will left shift it one bit position before
       it places the address on the bus
    */
    rsaddr->dr_walo = (ushort)((baddr >> 1) & 0xffff);
    rsaddr->dr_wahi = (ushort)((baddr >> 17) & 0x7fff);

    /* Set DMA range count: (number of words - 1) */
    rsaddr->dr_range = (ushort)((bp->b_bcount >> 1) - 1);

    /* Set address modifier code to be used for DMA access to memory */
    rsaddr->dr_addmod = (char)DRADDMOD;

    /* Now determine whether this is a read or a write. ***** This is
       probably only usefull for link mode operation, since dr11 doesnot
       controll the direction of data transfer. The C1 control input 
       controls whether the hardware is doing a read or a write. In link
       mode this is controlled by function 1 latch (looped back by the
       cable) and could be set the program. In the general case, the dr11
       doesnot know in advance what the direction of transfer is - although
       the program and protocol logic probably is
    */

E 7
I 7
	/* we are doing raw IO, bp->b_un.b_addr is user's address */
	addr = (long)vtoph(bp->b_proc, (unsigned)bp->b_un.b_addr);
	/*
	 * Set DMA address into DR11 interace registers: DR11 requires that
	 * the address be right shifted 1 bit position before it is written
	 * to the board (The board will left shift it one bit position before
	 * it places the address on the bus
	 */
	rsaddr->dr_walo = (addr >> 1) & 0xffff;
	rsaddr->dr_wahi = (addr >> 17) & 0x7fff;
	/* Set DMA range count: (number of words - 1) */
	rsaddr->dr_range = (bp->b_bcount >> 1) - 1;
	/* Set address modifier code to be used for DMA access to memory */
	rsaddr->dr_addmod = DRADDMOD;
	/*
	 * Now determine whether this is a read or a write. ***** This is
	 * probably only usefull for link mode operation, since dr11 doesnot
	 * controll the direction of data transfer. The C1 control input 
	 * controls whether the hardware is doing a read or a write. In link
	 * mode this is controlled by function 1 latch (looped back by the
	 * cable) and could be set the program. In the general case, the dr11
	 * doesnot know in advance what the direction of transfer is - although
	 * the program and protocol logic probably is
	 */
E 7
#ifdef DR_DEBUG
D 7
   if (DR11 & 1)
    printf("\ndrstrat: about to GO..,dr_cmd:%lx,drstat:%lx,drcnt:%ld,cdata:%lx,OP:%ld",
	dra->dr_cmd,rsaddr->dr_cstat,rsaddr->dr_range,rsaddr->dr_data,dra->dr_op);
E 7
I 7
	if (DR11 & 1)
		printf(
"\ndrstrat: about to GO..,dr_cmd:%lx,drstat:%lx,drcnt:%ld,cdata:%lx,OP:%ld",
		    dra->dr_cmd, rsaddr->dr_cstat, rsaddr->dr_range,
		    rsaddr->dr_data, dra->dr_op);
E 7
#endif
D 7

    /* Update function latches may have been done already by drioctl() if
       request from drioctl()
    */
    if (dra->dr_cmd & DR_DFCN) {
	/* deferred function write */
    	dra->dr_cmd &= ~DR_DFCN;	/* Clear request */
	go = dra->dr_cmd & DR_FMSK;	/* mask out fcn bits */
	rsaddr->dr_cstat = go;		/* Write it to the board */
    }

    /* Clear dmaf and attf to assure a clean dma start */
    rsaddr->dr_pulse = (ushort)(RATN|RDMA|RPER);
    rsaddr->dr_cstat = (ushort)(IENB|GO|CYCL|dra->dr_op); /* GO...... */

    /* Now check for software cycle request -- usually by transmitter in
       link mode.
    */
    if (dra->dr_cmd & DR_PCYL) {
    	dra->dr_cmd &= ~DR_PCYL;	/* Clear request */
	rsaddr->dr_pulse = CYCL;	/* Use pulse register again */
    }

    /* Now check for deferred ACLO FCNT2 pulse request -- usually to tell
       the transmitter (via its attention) that we have enabled dma.
    */
    if (dra->dr_cmd & DR_DACL) {
    	dra->dr_cmd &= ~DR_DACL;	/* Clear request */
	rsaddr->dr_pulse = FCN2;	/* Use pulse register again */
    }
E 7
I 7
	/*
	 * Update function latches may have been done already by drioctl() if
	 * request from drioctl()
	 */
	if (dra->dr_cmd & DR_DFCN) {		/* deferred function write */
		dra->dr_cmd &= ~DR_DFCN;	/* Clear request */
		go = dra->dr_cmd & DR_FMSK;	/* mask out fcn bits */
		rsaddr->dr_cstat = go;		/* Write it to the board */
	}
	/* Clear dmaf and attf to assure a clean dma start */
	rsaddr->dr_pulse = RATN|RDMA|RPER;
	rsaddr->dr_cstat = IENB|GO|CYCL|dra->dr_op; /* GO...... */
	/*
	 * Now check for software cycle request -- usually
	 * by transmitter in link mode.
	 */
	if (dra->dr_cmd & DR_PCYL) {
		dra->dr_cmd &= ~DR_PCYL;	/* Clear request */
		rsaddr->dr_pulse = CYCL;	/* Use pulse register again */
	}
	/*
	 * Now check for deferred ACLO FCNT2 pulse request -- usually to tell
	 * the transmitter (via its attention) that we have enabled dma.
	 */
	if (dra->dr_cmd & DR_DACL) {
		dra->dr_cmd &= ~DR_DACL;	/* Clear request */
		rsaddr->dr_pulse = FCN2;	/* Use pulse register again */
	}
E 7
}
D 7

E 7
#endif  NDR
E 1
