h52751
s 00001/00001/00272
d D 7.1 86/06/05 00:43:14 mckusick 21 20
c 4.3BSD release version
e
s 00000/00002/00273
d D 6.5 86/03/10 20:37:18 karels 20 19
c more than 780's and 750's by now...
e
s 00004/00002/00271
d D 6.4 85/08/07 17:21:49 bloom 19 18
c fix hang if trying to read too much
e
s 00007/00001/00266
d D 6.3 85/06/08 13:41:48 mckusick 18 17
c Add copyright
e
s 00011/00011/00256
d D 6.2 84/08/28 18:09:32 bloom 17 15
c Change to includes.  No more ../h
e
s 00001/00001/00266
d R 6.2 84/08/22 18:55:12 mckusick 16 15
c use IMIN macro to save call overhead
e
s 00000/00000/00267
d D 6.1 83/07/29 07:19:46 sam 15 14
c 4.2 distribution
e
s 00000/00000/00267
d D 4.11 82/10/21 20:58:37 root 14 13
c lint
e
s 00001/00005/00266
d D 4.10 82/10/17 15:24:53 root 13 12
c fix lint
e
s 00005/00008/00266
d D 4.9 82/10/17 12:01:44 root 12 11
c return errors from open/ioctl routines; update conf table for
e
s 00017/00013/00257
d D 4.8 82/10/13 22:13:49 root 11 10
c rearrange header files
e
s 00022/00019/00248
d D 4.7 82/08/22 21:19:34 root 10 9
c fully uio()'d
e
s 00001/00001/00266
d D 4.6 82/06/14 22:43:48 root 9 8
c geteblk needs a constant
e
s 00001/00001/00266
d D 4.5 81/03/09 01:53:01 wnj 8 7
c %G% -> %E%
e
s 00001/00000/00266
d D 4.4 81/02/28 13:40:34 wnj 7 6
c include cpu.h
e
s 00007/00001/00259
d D 4.3 81/02/25 23:36:35 wnj 6 5
c convert VAX==??? to VAX???
e
s 00002/00000/00258
d D 4.2 80/12/17 10:36:40 wnj 5 4
c compile only when on 780
e
s 00000/00000/00258
d D 4.1 80/11/09 16:52:24 bill 4 3
c stamp for 4bsd
e
s 00001/00001/00257
d D 3.3 80/06/07 02:45:37 bill 3 2
c %H%->%G%
e
s 00004/00004/00254
d D 3.2 80/05/08 10:21:16 bill 2 1
c VOID=>void
e
s 00258/00000/00000
d D 3.1 80/04/09 16:03:12 bill 1 0
c date and time created 80/04/09 16:03:12 by bill
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
D 8
/*	%M%	%I%	%G%	*/
E 8
I 8
D 18
/*	%M%	%I%	%E%	*/
E 18
I 18
/*
D 21
 * Copyright (c) 1982 Regents of the University of California.
E 21
I 21
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 21
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 18
E 8
E 3

I 5
D 6
#if VAX==780
E 6
I 6
#if VAX780
E 6
E 5
D 11
#include "../h/flp.h"
E 11
D 17
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/conf.h"
#include "../h/dir.h"
#include "../h/user.h"
D 11
#include "../h/mtpr.h"
E 11
#include "../h/buf.h"
D 11
#include "../h/cons.h"
I 7
#include "../h/cpu.h"
E 11
I 10
#include "../h/uio.h"
E 17
I 17
#include "param.h"
#include "systm.h"
#include "conf.h"
#include "dir.h"
#include "user.h"
#include "buf.h"
#include "uio.h"
E 17
E 10
E 7

I 11
D 17
#include "../vax/cons.h"
#include "../vax/cpu.h"
#include "../vax/flp.h"
#include "../vax/mtpr.h"
E 17
I 17
#include "cons.h"
#include "cpu.h"
#include "flp.h"
#include "mtpr.h"
E 17

E 11
struct {
	short	fl_state;		/* open and busy flags */
	short	fl_active;		/* driver state flag */
	struct	buf *fl_buf;		/* buffer we're using */
	unsigned char *fl_xaddr;	/* transfer address */
	short	fl_errcnt;
} fltab;

/*ARGSUSED*/
flopen(dev, flag)
	dev_t dev;
	int flag;
{
	struct buf *geteblk();

I 6
D 20
#if VAX750
E 20
D 12
	if (cpu != VAX_780) {
		u.u_error = ENXIO;
		return;
	}
E 12
I 12
	if (cpu != VAX_780)
		return (ENXIO);
E 12
D 20
#endif
E 20
E 6
D 12
	if (fltab.fl_state != 0) {
		u.u_error = ENXIO;
		return;
	}
E 12
I 12
	if (fltab.fl_state != 0)
		return (ENXIO);
E 12
	fltab.fl_state = FL_OPEN;
D 9
	fltab.fl_buf = geteblk();
E 9
I 9
	fltab.fl_buf = geteblk(512);
E 9
	fltab.fl_active = FL_IDLE;
I 12
	return (0);
E 12
}

/*ARGSUSED*/
flclose(dev, flag)
	dev_t dev;
	int flag;
{

	brelse(fltab.fl_buf);
	fltab.fl_state = 0;
}

D 10
flstrategy(rw)
	int rw;
E 10
I 10
floperation(rw, uio)
	enum uio_rw rw;
	struct uio *uio;
E 10
{
	register struct buf *bp;
D 10
	register unsigned i;
E 10
I 10
	register int i;
I 11
	int error;
E 11
E 10

	/*
	 * Assume one block read/written for each call - 
	 * and enforce this by checking for block size of 128.
	 * Use the b_blkno field to address
	 * physical, 128-byte blocks (u.u_offset/128).
	 * This is checked for validity, and is further interpreted as:
	 *
	 *	track# * (sectors/track) + sector #
	 */
D 10
	if (u.u_count == 0) 
E 10
I 10
	if (uio->uio_resid == 0) 
E 10
D 11
		return;
E 11
I 11
		return (0);
E 11
D 2
	VOID spl4();
E 2
I 2
	(void) spl4();
E 2
	while (fltab.fl_state & FL_BUSY)
		sleep((caddr_t)&fltab, PRIBIO);
	fltab.fl_state |= FL_BUSY;
D 2
	VOID spl0();
E 2
I 2
	(void) spl0();
E 2

	bp = fltab.fl_buf;
I 11
	error = 0;
E 11
D 10
	while ((i = min(RXBYSEC, u.u_count)) != 0) {
		bp->b_blkno = u.u_offset>>7;
		if (bp->b_blkno >= MAXSEC || (u.u_offset & 0177) != 0) {
E 10
I 10
	while ((i = imin(RXBYSEC, uio->uio_resid)) > 0) {
		bp->b_blkno = uio->uio_offset>>7;
D 13
		if (bp->b_blkno >= MAXSEC || (uio->uio_offset & 0177) != 0) {
E 10
			/* block number out of range */
			/* or offset in middle of block */
E 13
I 13
D 19
		if (bp->b_blkno >= MAXSEC || (uio->uio_offset & 0177) != 0)
E 13
D 11
			u.u_error = ENXIO;
E 11
I 11
			return (ENXIO);
E 19
I 19
		if (bp->b_blkno >= MAXSEC || (uio->uio_offset & 0177) != 0) {
			error = ENXIO;
			break;
		}
E 19
E 11
D 13
			break;	
		}
E 13
D 10
		if (rw == B_WRITE) {
			iomove(bp->b_un.b_addr, i, B_WRITE);
			if (u.u_error != 0)
E 10
I 10
		if (rw == UIO_WRITE) {
D 11
			u.u_error = uiomove(bp->b_un.b_addr, i, UIO_WRITE, uio);
			if (u.u_error)
E 11
I 11
			error = uiomove(bp->b_un.b_addr, i, UIO_WRITE, uio);
			if (error)
E 11
E 10
				break;
		}
D 10
		bp->b_flags = rw;
E 10
I 10
		bp->b_flags = rw == UIO_WRITE ? B_WRITE : B_READ;
E 10
D 2
		VOID spl4(); 
E 2
I 2
		(void) spl4(); 
E 2
		flstart();
		while ((bp->b_flags & B_DONE) == 0)
			sleep((caddr_t)bp, PRIBIO);	
D 2
		VOID spl0();
E 2
I 2
		(void) spl0();
E 2
		if (bp->b_flags & B_ERROR) {
D 11
			u.u_error = EIO;
E 11
I 11
			error = EIO;
E 11
			break;
		}
D 10
		if (rw == B_READ) {
			iomove(bp->b_un.b_addr, i, B_READ);
			if (u.u_error != 0)
E 10
I 10
		if (rw == UIO_READ) {
D 11
			u.u_error = uiomove(bp->b_un.b_addr, i, UIO_READ, uio);
			if (u.u_error)
E 11
I 11
			error = uiomove(bp->b_un.b_addr, i, UIO_READ, uio);
			if (error)
E 11
E 10
				break;
		}
	}
D 10
	u.u_count = bp->b_resid;
E 10
	fltab.fl_state &= ~FL_BUSY;
	wakeup((caddr_t)&fltab);
I 11
	return (error);
E 11
}

/*ARGSUSED*/
D 10
flread(dev)
E 10
I 10
flread(dev, uio)
E 10
	dev_t dev;
I 10
	struct uio *uio;
E 10
{

D 10
	flstrategy(B_READ);
E 10
I 10
D 11
	floperation(UIO_READ, uio);
E 11
I 11
	return (floperation(UIO_READ, uio));
E 11
E 10
}

/*ARGSUSED*/
D 10
flwrite(dev)
E 10
I 10
flwrite(dev, uio)
E 10
	dev_t dev;
I 10
	struct uio *uio;
E 10
{

D 10
	flstrategy(B_WRITE);
E 10
I 10
D 11
	floperation(UIO_WRITE, uio);
E 11
I 11
	return (floperation(UIO_WRITE, uio));
E 11
E 10
}

flstart()
{
	register struct buf *bp;

	bp = fltab.fl_buf;
	fltab.fl_active = FL_MAND;
	fltab.fl_errcnt = 0;
	fltab.fl_xaddr = (unsigned char *) bp->b_un.b_addr;
	bp->b_resid = 0;
	bp->b_bcount = RXBYSEC; /* always transfer a full sector */

	if ((mfpr(TXCS) & TXCS_RDY) == 0)
		/* not ready to receive order */
		return;
	/*
	 * Wake up floppy LSI software with command
	 */
	fltab.fl_active = FL_SEC;
	if ((bp->b_flags&B_READ) == B_READ)
		mtpr(TXDB, FL_RS);
	else
		mtpr(TXDB, FL_WS);
}

/*
 * See if we want to transmit something
 * to the floppy - and do it
 */
conxfl()
{
	register int databyte;
	register struct buf *bp;

	bp = fltab.fl_buf;
	switch (fltab.fl_active) {

	case FL_MAND:		/* send command */
		if ((bp->b_flags&B_READ) == B_READ)
			mtpr(TXDB,FL_RS);
		else
			mtpr(TXDB,  FL_WS);
		fltab.fl_active = FL_SEC;
		break;

	case FL_SEC:		/* send sector address */
		databyte = (int)bp->b_blkno % RXSTRK + 1;
		mtpr(TXDB, FL_DATA | databyte);
		fltab.fl_active = FL_TRACK;
		break;

	case FL_TRACK:		/* send track address */
		databyte = (int)bp->b_blkno / RXSTRK;
		mtpr(TXDB , FL_DATA | databyte);
		if ((bp->b_flags&B_READ) == B_READ)
			/* prepare to receive complete */
			fltab.fl_active = FL_COM;
		else
			/* prepare to send data */
			fltab.fl_active = FL_DAX;
		break;

	case FL_DAX:
		databyte = *(fltab.fl_xaddr++);
		mtpr(TXDB, FL_DATA | databyte);
		if (--bp->b_bcount == 0)
			fltab.fl_active = FL_COM;
		break;

	case FL_CAN:		/* give cancel order */
		mtpr(TXDB, FL_CANCEL);
		if (++fltab.fl_errcnt <= FLERRS) {
			/* If error count permits, retry order */
			fltab.fl_active = FL_MAND;
			bp->b_bcount = RXBYSEC;
			fltab.fl_xaddr = (unsigned char *) bp->b_un.b_addr;
		} else {
			/*
			 * We're really stupid today - call it an
			 * error and give up
			 */
			bp->b_flags |= B_ERROR | B_DONE;
			bp->b_resid = -RXBYSEC;
			fltab.fl_active = FL_IDLE;
			wakeup((caddr_t)bp);
		}
	}
}

cnrfl(c)
	int c;
{
	register int datum;
	register struct buf *bp;

	datum = c;
	bp = fltab.fl_buf;
	if (datum == FL_PERR) {
		/*
		 * Got a protocol error - cancel the
		 * current function and try again if error count isn't
		 * too great.  First, though, make sure that an actual
		 * transaction is in progress (so a spurious error from
		 * the LSI won't screw us up too much!
		 */
		if (fltab.fl_active != FL_IDLE)
			fltab.fl_active = FL_CAN;
	} else switch(fltab.fl_active ) {

	case FL_DAR:		/* expecting a datum */
		if ((c&RXDB_ID) != FL_DATA)
			goto error;
		*(fltab.fl_xaddr++) = (c & RXDB_DATA);
		if (--bp->b_bcount==0) {
			fltab.fl_active = FL_IDLE;
			bp->b_flags |= B_DONE;
			wakeup((caddr_t)bp);
		}
		break;

	case FL_COM:		/* expecting a "function complete" */
		if ((c&RXDB_ID)!= FL_FFC || (c&FL_ERR) == FL_ERR){
error:
			bp->b_flags |= B_ERROR | B_DONE;
			bp->b_resid = -bp->b_bcount;
			fltab.fl_active = FL_IDLE;
			wakeup((caddr_t)bp);
		} else if ((bp->b_flags&B_READ) == B_READ)
			/* got function complete, now get data */
			fltab.fl_active = FL_DAR;
		else {
			/* got function complete on write - finish up */
			fltab.fl_active = FL_IDLE;
			bp->b_flags |= B_DONE;
				wakeup((caddr_t)bp);
		}
		break;
	}
}
I 5
#endif
E 5
E 1
