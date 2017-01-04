h28568
s 00001/00001/00167
d D 7.4 99/09/08 10:06:58 msokolov 30 29
c have to make the miniroot 3 MB, it just doesn't fit...
e
s 00000/00017/00168
d D 7.3 88/05/06 17:14:49 bostic 29 28
c remove sw{read,write} for raw{read,write} changes
e
s 00029/00015/00156
d D 7.2 87/04/02 15:49:40 karels 28 26
c working with pack labels
e
s 00044/00015/00156
d D 7.1.1.1 87/04/02 15:41:35 karels 27 26
c add ifdefs for dev_bsize (almost working)
e
s 00001/00001/00170
d D 7.1 86/06/05 00:21:18 mckusick 26 25
c 4.3BSD release version
e
s 00007/00001/00164
d D 6.6 85/06/08 15:17:29 mckusick 25 24
c Add copyright
e
s 00002/00000/00163
d D 6.5 85/05/22 20:07:19 mckusick 24 23
c only allow the super-user to do swapon()
e
s 00002/00006/00161
d D 6.4 85/01/29 16:26:47 bloom 23 22
c check if swapping on default device so swapon won't complain
e
s 00010/00010/00157
d D 6.3 84/08/29 20:30:33 bloom 22 21
c Change to includes.  no more ../h
e
s 00006/00003/00161
d D 6.2 84/07/08 16:17:58 mckusick 21 20
c rework `namei' interface to eliminate global variables
e
s 00000/00000/00164
d D 6.1 83/07/29 06:53:06 sam 20 19
c 4.2 distribution
e
s 00024/00011/00140
d D 4.18 83/05/18 01:58:31 sam 19 18
c changes from sun to do swapping on variable sized devices
e
s 00004/00001/00147
d D 4.17 83/05/10 15:18:36 sam 18 17
c swapon, swapoff, and unmount aren't going to be implemented, 
c so purge the hooks from the system
e
s 00001/00001/00147
d D 4.16 83/02/13 11:18:09 sam 17 16
c increase size of mini root so there's space to build floppy/cassette
e
s 00002/00001/00146
d D 4.15 82/11/13 22:55:08 sam 16 15
c merge of 4.1b and 4.1c
e
s 00002/00001/00145
d D 4.14 82/11/02 11:49:29 root 15 14
c typo
e
s 00006/00003/00140
d D 4.13 82/10/31 13:49:57 root 14 13
c fixes from 68k
e
s 00002/00002/00141
d D 4.12 82/10/22 01:15:12 root 13 12
c lint
e
s 00003/00002/00140
d D 4.11 82/10/21 23:54:47 root 12 11
c lint
e
s 00001/00001/00141
d D 4.10 82/10/21 21:00:44 root 11 10
c lint
e
s 00001/00001/00141
d D 4.9 82/09/06 22:58:51 root 10 9
c 
e
s 00009/00004/00133
d D 4.8 82/08/22 21:14:17 root 9 8
c uio'd
e
s 00011/00000/00126
d D 4.7 82/07/15 20:39:28 root 8 7
c add mini root for new bootstrap style
e
s 00001/00001/00125
d D 4.6 82/06/25 21:31:22 wnj 7 6
c remove spurious i_un.
e
s 00001/00001/00125
d D 4.5 82/03/12 15:53:11 sam 6 5
c missing arg to nami
e
s 00001/00001/00125
d D 4.4 81/03/09 01:54:16 wnj 5 4
c %G% -> %E%
e
s 00009/00003/00117
d D 4.3 81/02/28 17:37:16 wnj 4 3
c rmalloc and related stuff
e
s 00000/00004/00120
d D 4.2 80/11/09 22:56:05 bill 3 2
c minor lint
e
s 00000/00000/00124
d D 4.1 80/11/09 16:54:00 bill 2 1
c stamp for 4bsd
e
s 00124/00000/00000
d D 3.1 80/10/12 22:05:40 bill 1 0
c date and time created 80/10/12 22:05:40 by bill
e
u
U
f b 
t
T
I 1
D 5
/*	%M%	%I%	%G%	*/
E 5
I 5
D 25
/*	%M%	%I%	%E%	*/
E 25
I 25
/*
D 26
 * Copyright (c) 1982 Regents of the University of California.
E 26
I 26
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 26
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 25
E 5

D 22
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/buf.h"
#include "../h/conf.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/inode.h"
#include "../h/map.h"
I 9
#include "../h/uio.h"
I 15
#include "../h/file.h"
E 22
I 22
#include "param.h"
#include "systm.h"
#include "buf.h"
#include "conf.h"
#include "dir.h"
#include "user.h"
#include "inode.h"
#include "map.h"
#include "uio.h"
#include "file.h"
I 28
#include "stat.h"
E 28
I 27
#include "stat.h"
E 27
E 22
I 16
D 21
#include "../h/nami.h"
E 21
E 16
E 15
E 9

D 29
struct	buf rswbuf;
E 29
/*
 * Indirect driver for multi-controller paging.
 */
swstrategy(bp)
	register struct buf *bp;
{
D 27
D 28
	int sz, off, seg;
	dev_t dev;
E 28
I 28
	int sz, off, seg, index;
	register struct swdevt *sp;
E 28
E 27
I 27
	int sz, off, seg, index;
	register struct swdevt *sp;
E 27

I 8
#ifdef GENERIC
	/*
	 * A mini-root gets copied into the front of the swap
	 * and we run over top of the swap area just long
	 * enough for us to do a mkfs and restor of the real
	 * root (sure beats rewriting standalone restor).
	 */
D 17
#define	MINIROOTSIZE	2048
E 17
I 17
D 30
#define	MINIROOTSIZE	4096
E 30
I 30
#define	MINIROOTSIZE	6144
E 30
E 17
	if (rootdev == dumpdev)
		bp->b_blkno += MINIROOTSIZE;
#endif
E 8
D 14
	sz = (bp->b_bcount+511)/512;
E 14
I 14
D 15
	sz = howmany(bp->b_bocunt, DEV_BSIZE);
E 15
I 15
	sz = howmany(bp->b_bcount, DEV_BSIZE);
E 15
E 14
D 19
	off = bp->b_blkno % DMMAX;
	if (bp->b_blkno+sz > nswap || off+sz > DMMAX) {
E 19
I 19
	if (bp->b_blkno+sz > nswap) {
E 19
		bp->b_flags |= B_ERROR;
D 27
D 28
		iodone(bp);
E 28
I 28
		biodone(bp);
E 28
E 27
I 27
		biodone(bp);
E 27
		return;
	}
D 19
	seg = bp->b_blkno / DMMAX;
	dev = swdevt[seg % nswdev].sw_dev;
	seg /= nswdev;
	bp->b_blkno = seg*DMMAX + off;
E 19
I 19
	if (nswdev > 1) {
		off = bp->b_blkno % dmmax;
		if (off+sz > dmmax) {
			bp->b_flags |= B_ERROR;
D 27
D 28
			iodone(bp);
E 28
I 28
			biodone(bp);
E 28
E 27
I 27
			biodone(bp);
E 27
			return;
		}
		seg = bp->b_blkno / dmmax;
D 27
D 28
		dev = swdevt[seg % nswdev].sw_dev;
E 28
I 28
		index = seg % nswdev;
E 28
E 27
I 27
		index = seg % nswdev;
E 27
		seg /= nswdev;
		bp->b_blkno = seg*dmmax + off;
	} else
D 27
D 28
		dev = swdevt[0].sw_dev;
E 19
	bp->b_dev = dev;
	if (dev == 0)
E 28
I 28
		index = 0;
	sp = &swdevt[index];
	bp->b_dev = sp->sw_dev;
	if (bp->b_dev == 0)
E 28
E 27
I 27
		index = 0;
	sp = &swdevt[index];
#ifdef SECSIZE
	bp->b_blkno <<= sp->sw_bshift;
	bp->b_blksize = sp->sw_blksize;
#endif SECSIZE
	bp->b_dev = sp->sw_dev;
	if (bp->b_dev == 0)
E 27
		panic("swstrategy");
D 27
D 28
	(*bdevsw[major(dev)].d_strategy)(bp);
E 28
I 28
	(*bdevsw[major(bp->b_dev)].d_strategy)(bp);
E 28
E 27
I 27
	(*bdevsw[major(bp->b_dev)].d_strategy)(bp);
E 27
D 29
}

D 9
swread(dev)
E 9
I 9
swread(dev, uio)
	dev_t dev;
	struct uio *uio;
E 9
{

D 9
	physio(swstrategy, &rswbuf, dev, B_READ, minphys);
E 9
I 9
D 13
	physio(swstrategy, &rswbuf, dev, B_READ, minphys, uio);
E 13
I 13
	return (physio(swstrategy, &rswbuf, dev, B_READ, minphys, uio));
E 13
E 9
}

D 9
swwrite(dev)
E 9
I 9
swwrite(dev, uio)
	dev_t dev;
	struct uio *uio;
E 9
{

D 9
	physio(swstrategy, &rswbuf, dev, B_WRITE, minphys);
E 9
I 9
D 13
	physio(swstrategy, &rswbuf, dev, B_WRITE, minphys, uio);
E 13
I 13
	return (physio(swstrategy, &rswbuf, dev, B_WRITE, minphys, uio));
E 29
E 13
E 9
}

/*
 * System call swapon(name) enables swapping on device name,
 * which must be in the swdevsw.  Return EBUSY
 * if already swapping on this device.
 */
D 10
vswapon()
E 10
I 10
D 18
oswapon()
E 18
I 18
swapon()
E 18
E 10
{
I 18
	struct a {
		char	*name;
D 21
	};
E 21
I 21
	} *uap = (struct a *)u.u_ap;
E 21
E 18
D 3
	register struct a {
		char	*sname;
	} *uap;
E 3
	register struct inode *ip;
	dev_t dev;
	register struct swdevt *sp;
I 21
	register struct nameidata *ndp = &u.u_nd;
E 21

I 24
	if (!suser())
		return;
E 24
D 3
	uap = (struct a *)u.u_ap;
E 3
D 6
	ip = namei(uchar, 0);
E 6
I 6
D 16
	ip = namei(uchar, 0, 1);
E 16
I 16
D 21
	ip = namei(uchar, LOOKUP, 1);
E 21
I 21
	ndp->ni_nameiop = LOOKUP | FOLLOW;
	ndp->ni_segflg = UIO_USERSPACE;
	ndp->ni_dirp = uap->name;
	ip = namei(ndp);
E 21
E 16
E 6
	if (ip == NULL)
		return;
	if ((ip->i_mode&IFMT) != IFBLK) {
		u.u_error = ENOTBLK;
		iput(ip);
		return;
	}
D 7
	dev = (dev_t)ip->i_un.i_rdev;
E 7
I 7
	dev = (dev_t)ip->i_rdev;
E 7
	iput(ip);
	if (major(dev) >= nblkdev) {
		u.u_error = ENXIO;
		return;
	}
D 23
	/*
	 * Search starting at second table entry,
	 * since first (primary swap area) is freed at boot.
	 */
	for (sp = &swdevt[1]; sp->sw_dev; sp++)
E 23
I 23
	for (sp = &swdevt[0]; sp->sw_dev; sp++)
E 23
		if (sp->sw_dev == dev) {
			if (sp->sw_freed) {
				u.u_error = EBUSY;
				return;
			}
D 27
D 28
			swfree(sp - swdevt);
E 28
I 28
			u.u_error = swfree(sp - swdevt);
E 28
E 27
I 27
			u.u_error = swfree(sp - swdevt);
E 27
			return;
		}
D 23
	u.u_error = ENODEV;
E 23
I 23
	u.u_error = EINVAL;
E 23
}

I 27
#ifdef SECSIZE
long	argdbsize;		/* XXX */

#endif SECSIZE
E 27
/*
 * Swfree(index) frees the index'th portion of the swap map.
 * Each of the nswdev devices provides 1/nswdev'th of the swap
D 19
 * space, which is laid out with blocks of DMMAX pages circularly
E 19
I 19
 * space, which is laid out with blocks of dmmax pages circularly
E 19
 * among the devices.
 */
swfree(index)
	int index;
{
I 28
	register struct swdevt *sp;
E 28
I 27
	register struct swdevt *sp;
E 27
	register swblk_t vsbase;
D 11
	register int blk;
E 11
I 11
	register long blk;
I 14
	dev_t dev;
I 19
	register swblk_t dvbase;
	register int nblks;
I 28
	int error;
E 28
I 27
	int error;
E 27
E 19
E 14
E 11

I 14
D 27
D 28
	dev = swdevt[index].sw_dev;
	(*bdevsw[major(dev)].d_open)(dev, FREAD|FWRITE);
E 14
	swdevt[index].sw_freed = 1;
D 19
	for (vsbase = index*DMMAX; vsbase < nswap; vsbase += nswdev*DMMAX) {
		blk = nswap - vsbase;
		if (blk > DMMAX)
			blk = DMMAX;
E 19
I 19
	nblks = swdevt[index].sw_nblks;
E 28
I 28
	sp = &swdevt[index];
	dev = sp->sw_dev;
	if (error = (*bdevsw[major(dev)].d_open)(dev, FREAD|FWRITE, S_IFBLK))
		return (error);
	sp->sw_freed = 1;
	nblks = sp->sw_nblks;
E 28
E 27
I 27
	sp = &swdevt[index];
	dev = sp->sw_dev;
	if (error = (*bdevsw[major(dev)].d_open)(dev, FREAD|FWRITE, S_IFBLK))
		return (error);
	sp->sw_freed = 1;
	nblks = sp->sw_nblks;
E 27
	for (dvbase = 0; dvbase < nblks; dvbase += dmmax) {
		blk = nblks - dvbase;
		if ((vsbase = index*dmmax + dvbase*nswdev) >= nswap)
			panic("swfree");
		if (blk > dmmax)
			blk = dmmax;
E 19
		if (vsbase == 0) {
			/*
			 * Can't free a block starting at 0 in the swapmap
D 4
			 * but need some space for argmap so use this
E 4
I 4
			 * but need some space for argmap so use 1/2 this
E 4
			 * hunk which needs special treatment anyways.
			 */
D 27
D 28
			argdev = swdevt[0].sw_dev;
E 28
I 28
			argdev = sp->sw_dev;
E 28
E 27
I 27
			argdev = sp->sw_dev;
#ifdef SECSIZE
			argdbsize = sp->sw_blksize;
			rminit(argmap,
			   ((blk / 2) * DEV_BSIZE - CLBYTES) / argdbsize,
			   CLBYTES / argdbsize, "argmap", ARGMAPSIZE);
#else SECSIZE
E 27
D 4
			mfree(argmap, blk-CLSIZE, vsbase+CLSIZE);
E 4
I 4
D 12
			rminit(argmap, blk/2-CLSIZE, CLSIZE,
E 12
I 12
D 14
			rminit(argmap, (long)(blk/2-CLSIZE), (long)CLSIZE,
E 12
			    "argmap", ARGMAPSIZE);
E 14
I 14
			rminit(argmap, (long)(blk/2-ctod(CLSIZE)),
			    (long)ctod(CLSIZE), "argmap", ARGMAPSIZE);
I 27
#endif SECSIZE
E 27
E 14
			/*
			 * First of all chunks... initialize the swapmap
			 * the second half of the hunk.
			 */
D 12
			rminit(swapmap, blk/2, blk/2, "swap", nswapmap);
E 12
I 12
			rminit(swapmap, (long)blk/2, (long)blk/2,
			    "swap", nswapmap);
I 28
		} else if (dvbase == 0) {
			/*
			 * Don't use the first cluster of the device
			 * in case it starts with a label or boot block.
			 */
			rmfree(swapmap, blk - ctod(CLSIZE),
			    vsbase + ctod(CLSIZE));
E 28
I 27
		} else if (dvbase == 0) {
			/*
			 * Don't use the first cluster of the device
			 * in case it starts with a label or boot block.
			 */
			rmfree(swapmap, blk - ctod(CLSIZE),
			    vsbase + ctod(CLSIZE));
E 27
E 12
E 4
		} else
D 4
			mfree(swapmap, blk, vsbase);
E 4
I 4
			rmfree(swapmap, blk, vsbase);
E 4
	}
I 28
	return (0);
E 28
I 27
	return (0);
E 27
}
E 1
