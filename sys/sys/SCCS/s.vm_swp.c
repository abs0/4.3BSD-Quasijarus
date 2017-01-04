h25254
s 00100/00049/00213
d D 7.4 88/05/06 17:14:08 bostic 69 68
c raw{read,write} changes
e
s 00048/00054/00214
d D 7.3 87/04/02 15:49:42 karels 68 66
c working with pack labels
e
s 00079/00054/00214
d D 7.2.1.1 87/04/02 15:41:36 karels 67 66
c add ifdefs for dev_bsize (almost working)
e
s 00005/00000/00263
d D 7.2 86/11/03 12:01:20 karels 66 65
c merge in tahoe support
e
s 00001/00001/00262
d D 7.1 86/06/05 00:21:47 mckusick 65 64
c 4.3BSD release version
e
s 00005/00005/00258
d D 6.9 86/02/21 13:12:52 karels 64 63
c spl's
e
s 00004/00001/00259
d D 6.8 86/01/30 19:08:44 mckusick 63 62
c do not distpte() after a swapin error (from sun!shannon)
e
s 00002/00002/00258
d D 6.7 85/08/28 10:11:03 bloom 62 61
c add newlines to printf's
e
s 00007/00001/00253
d D 6.6 85/06/08 15:18:14 mckusick 61 60
c Add copyright
e
s 00003/00008/00251
d D 6.5 85/03/12 18:13:13 mckusick 60 59
c make swkill messages more informative
e
s 00002/00001/00257
d D 6.4 84/10/31 11:58:40 karels 59 58
c fix scatter-gather in physio (from Larry Allen)
e
s 00012/00012/00246
d D 6.3 84/08/29 20:30:44 bloom 58 57
c Change to includes.  no more ../h
e
s 00000/00008/00258
d D 6.2 83/09/09 16:56:09 mckusick 57 56
c remove some crap from vm_swp.c (shannon)
e
s 00000/00000/00266
d D 6.1 83/07/29 06:53:26 sam 56 55
c 4.2 distribution
e
s 00002/00002/00264
d D 4.41 83/05/21 15:49:01 sam 55 54
c macvro = macro-ized
e
s 00027/00007/00239
d D 4.40 83/05/18 01:58:42 sam 54 52
c changes from sun to do swapping on variable sized devices
e
s 00024/00000/00246
d R 4.40 83/05/06 09:25:01 sam 53 52
c from pugs@sun.UUCP; removes dirty page pushes from bio routines
e
s 00001/00000/00245
d D 4.39 83/01/20 17:03:20 sam 52 51
c get rid of noise from cpp
e
s 00011/00003/00234
d D 4.38 83/01/17 18:11:07 sam 51 50
c brain damage for network disk
e
s 00006/00003/00231
d D 4.37 82/12/17 11:50:47 sam 50 49
c sun merge
e
s 00001/00001/00233
d D 4.36 82/11/02 11:51:24 root 49 48
c typo
e
s 00008/00014/00226
d D 4.35 82/10/31 13:51:11 root 48 47
c fixes from 68k
e
s 00002/00002/00238
d D 4.34 82/10/21 21:00:49 root 47 46
c lint
e
s 00000/00000/00240
d D 4.34 82/10/19 10:34:19  47 46
c more lint
e
s 00000/00000/00240
d D 4.33 82/10/17 21:52:44 root 46 45
c more lint
e
s 00004/00026/00236
d D 4.32 82/08/22 21:16:06 root 45 44
c fully uio()'d
e
s 00050/00016/00212
d D 4.31 82/08/13 00:05:16 wnj 44 43
c fixes to get uio'd readi for char devs
e
s 00000/00669/00228
d D 4.30 82/05/22 15:46:08 mckusick 43 41
c break swap() and physio() out of bio.c
e
s 00095/00466/00431
d R 4.30 82/05/12 15:23:29 sam 42 41
c heavily reorganized
e
s 00123/00036/00774
d D 4.29 82/04/19 19:24:17 mckusic 41 40
c merge in the new file system
e
s 00002/00002/00808
d D 4.28 82/03/31 09:04:27 wnj 40 39
c 63k < 65536, but 65k >
e
s 00003/00002/00807
d D 4.27 82/03/26 21:26:49 wnj 39 38
c missing splx(s); raise physio size limit to 65k
e
s 00002/00002/00807
d D 4.26 82/03/13 12:50:00 sam 38 37
c lint
e
s 00019/00014/00790
d D 4.25 82/01/17 20:12:05 root 37 36
c make bio and disk drivers not do spl0 so can call from panic without trap 2's
e
s 00011/00005/00793
d D 4.24 82/01/17 03:57:03 wnj 36 35
c fix up rebooting via spl changes in getblk
e
s 00001/00001/00797
d D 4.23 81/07/25 21:01:43 wnj 35 34
c restore sccs line
e
s 00007/00004/00791
d D 4.22 81/07/25 20:59:50 wnj 34 33
c fixed fsdtodb() spuriously in trace() calls by removing
c added a TR_SWAPIO for green.
e
s 00003/00001/00792
d D 4.21 81/05/08 21:52:33 wnj 33 32
c fix bug in physio which weirded out tape drive
e
s 00002/00001/00791
d D 4.20 81/04/24 00:14:57 wnj 32 31
c count pages paged out
e
s 00001/00001/00791
d D 4.19 81/04/23 22:39:07 wnj 31 30
c fix per mja@cmu
e
s 00015/00015/00777
d D 4.18 81/03/11 18:32:11 wnj 30 29
c fix trace code
e
s 00001/00001/00791
d D 4.17 81/03/09 01:51:56 wnj 29 28
c %G% -> %E%
e
s 00003/00000/00789
d D 4.16 81/03/09 00:32:20 wnj 28 27
c lint
e
s 00005/00003/00784
d D 4.15 81/03/06 10:30:01 wnj 27 26
c uprintf when user procs killed
e
s 00005/00005/00782
d D 4.14 81/02/27 17:49:16 wnj 26 25
c system sized at boot version
e
s 00002/00002/00785
d D 4.13 81/02/26 04:28:30 wnj 25 24
c cosmetic for new config and 750/780
e
s 00005/00002/00782
d D 4.12 81/02/25 22:28:05 wnj 24 23
c dont throw away super-blocks on error
e
s 00003/00001/00781
d D 4.11 81/02/15 12:09:29 kre 23 22
c bootable autoconf version
e
s 00003/00003/00779
d D 4.10 81/02/10 16:06:27 kre 22 21
c first compiling autoconf version
e
s 00007/00005/00775
d D 4.9 81/02/07 15:46:40 kre 21 20
c invalidate buffer cache (correctly, through hash headers)
e
s 00000/00001/00780
d D 4.8 81/02/03 23:11:19 wnj 20 19
c random reference (still) to b_hlink
e
s 00003/00003/00778
d D 4.7 81/02/01 17:59:10 wnj 19 18
c fix to incore()
e
s 00060/00100/00721
d D 4.6 81/01/31 23:41:10 wnj 18 17
c new hashing and buffer queue stuff
e
s 00027/00002/00794
d D 4.5 81/01/28 11:46:37 kre 17 16
c buffer invalidate routine and checks for B_INVAL flag
e
s 00033/00003/00763
d D 4.4 80/12/26 12:22:07 wnj 16 15
c add EPAWNJ tracing
e
s 00004/00002/00762
d D 4.3 80/11/24 12:47:15 bill 15 14
c recover from out of range block numbers
e
s 00001/00001/00763
d D 4.2 80/11/10 00:31:03 bill 14 13
c minor lint
e
s 00000/00000/00764
d D 4.1 80/11/09 16:52:56 bill 13 12
c stamp for 4bsd
e
s 00008/00003/00756
d D 3.12 80/09/16 17:31:47 bill 12 11
c fix bufunhash race condition
e
s 00004/00002/00755
d D 3.11 80/08/24 21:22:30 bill 11 10
c fix race in swap which was crashing system regularly
e
s 00002/00000/00755
d D 3.10 80/07/29 09:14:49 bill 10 9
c new mba stuff
e
s 00001/00000/00754
d D 3.9 80/07/19 19:54:08 bill 9 8
c return in iodone
e
s 00000/00002/00754
d D 3.8 80/06/24 19:27:55 bill 8 7
c no swplo
e
s 00001/00001/00755
d D 3.7 80/06/07 02:44:26 bill 7 6
c %H%->%G%
e
s 00001/00002/00755
d D 3.6 80/05/18 11:30:50 bill 6 5
c lint
e
s 00001/00001/00756
d D 3.5 80/05/15 16:30:00 bill 5 4
c SIGKIL->SIGKILL
e
s 00019/00019/00738
d D 3.4 80/05/08 10:20:21 bill 4 3
c VOID=>void
e
s 00001/00033/00756
d D 3.3 80/04/14 10:00:08 bill 3 2
c remove distrust code and oincore
e
s 00136/00043/00653
d D 3.2 80/04/13 12:19:23 bill 2 1
c first working hashed version
e
s 00696/00000/00000
d D 3.1 80/04/09 16:02:54 bill 1 0
c date and time created 80/04/09 16:02:54 by bill
e
u
U
f b 
t
T
I 1
D 7
/*	%M%	%I%	%H%	*/
E 7
I 7
D 29
/*	%M%	%I%	%G%	*/
E 29
I 29
D 34
/*	%M%	%I%	%E%	*/
E 34
I 34
D 35
/*	bio.c	4.21	81/05/08	*/
E 35
I 35
D 61
/*	%M%	%I%	%E%	*/
E 61
I 61
/*
D 65
 * Copyright (c) 1982 Regents of the University of California.
E 65
I 65
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 65
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 61
E 35
E 34
E 29
E 7

I 50
#include "../machine/pte.h"

E 50
I 41
D 43
/* merged into kernel:	 @(#)bio.c 2.3 4/8/82 */

E 43
E 41
I 2
D 3
int	distrust = 1;		/* TEST */
E 3
E 2
D 58
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/buf.h"
#include "../h/conf.h"
#include "../h/proc.h"
#include "../h/seg.h"
D 50
#include "../h/pte.h"
E 50
#include "../h/vm.h"
I 16
#include "../h/trace.h"
I 54
#include "../h/map.h"
E 54
I 44
#include "../h/uio.h"
E 58
I 58
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "buf.h"
#include "conf.h"
#include "proc.h"
#include "seg.h"
#include "vm.h"
#include "trace.h"
#include "map.h"
#include "uio.h"
I 67
#ifdef SECSIZE
#include "file.h"
#include "ioctl.h"
#include "disklabel.h"
#endif SECSIZE
E 67
E 58
E 44
E 16

I 2
/*
D 43
 * The following several routines allocate and free
 * buffers with various side effects.  In general the
 * arguments to an allocate routine are a device and
 * a block number, and the value is a pointer to
 * to the buffer header; the buffer is marked "busy"
 * so that no one else can touch it.  If the block was
 * already in core, no I/O need be done; if it is
 * already busy, the process waits until it becomes free.
 * The following routines allocate a buffer:
 *	getblk
 *	bread
 *	breada
 *	baddr	(if it is incore)
 * Eventually the buffer must be released, possibly with the
 * side effect of writing it out, by using one of
 *	bwrite
 *	bdwrite
 *	bawrite
 *	brelse
 */

I 28
struct	buf bfreelist[BQUEUES];
struct	buf bswlist, *bclnlist;

E 28
#define	BUFHSZ	63
I 41
#define RND	(MAXBSIZE/DEV_BSIZE)
E 41
D 18
#define	BUFHASH(blkno)	(blkno % BUFHSZ)
short	bufhash[BUFHSZ];
E 18
I 18
struct	bufhd bufhash[BUFHSZ];
D 19
#define	BUFHASH(dev,blkno)	\
		((struct buf *)&bufhash[((int)dev+(int)blkno) % BUFHSZ])
E 19
I 19
#define	BUFHASH(dev, dblkno)	\
D 41
		((struct buf *)&bufhash[((int)(dev)+(int)(dblkno)) % BUFHSZ])
E 41
I 41
	((struct buf *)&bufhash[((int)(dev)+(((int)(dblkno))/RND)) % BUFHSZ])
E 41
E 19
E 18

/*
 * Initialize hash links for buffers.
 */
bhinit()
{
	register int i;
I 18
	register struct bufhd *bp;
E 18

D 18
	for (i = 0; i < BUFHSZ; i++)
		bufhash[i] = -1;
E 18
I 18
	for (bp = bufhash, i = 0; i < BUFHSZ; i++, bp++)
		bp->b_forw = bp->b_back = (struct buf *)bp;
E 18
}

E 2
/* #define	DISKMON	1 */

#ifdef	DISKMON
struct {
	int	nbuf;
	long	nread;
	long	nreada;
	long	ncache;
	long	nwrite;
D 26
	long	bufcount[NBUF];
E 26
I 26
	long	bufcount[64];
E 26
} io_info;
#endif

/*
E 43
 * Swap IO headers -
 * They contain the necessary information for the swap I/O.
 * At any given time, a swap header can be in three
 * different lists. When free it is in the free list, 
 * when allocated and the I/O queued, it is on the swap 
 * device list, and finally, if the operation was a dirty 
 * page push, when the I/O completes, it is inserted 
 * in a list of cleaned pages to be processed by the pageout daemon.
 */
D 26
struct	buf swbuf[NSWBUF];
short	swsize[NSWBUF];		/* CAN WE JUST USE B_BCOUNT? */
int	swpf[NSWBUF];
E 26
I 26
struct	buf *swbuf;
D 54
short	*swsize;		/* CAN WE JUST USE B_BCOUNT? */
int	*swpf;
E 54
E 26

D 2
/*
 * The following several routines allocate and free
 * buffers with various side effects.  In general the
 * arguments to an allocate routine are a device and
 * a block number, and the value is a pointer to
 * to the buffer header; the buffer is marked "busy"
 * so that no one else can touch it.  If the block was
 * already in core, no I/O need be done; if it is
 * already busy, the process waits until it becomes free.
 * The following routines allocate a buffer:
 *	getblk
 *	bread
 *	breada
 *	baddr	(if it is incore)
 * Eventually the buffer must be released, possibly with the
 * side effect of writing it out, by using one of
 *	bwrite
 *	bdwrite
 *	bawrite
 *	brelse
 */
E 2
D 43

D 25
#ifdef	FASTVAX
E 25
I 25
#ifndef	UNFAST
E 25
#define	notavail(bp) \
{ \
D 38
	int s = spl6(); \
E 38
I 38
	int x = spl6(); \
E 38
	(bp)->av_back->av_forw = (bp)->av_forw; \
	(bp)->av_forw->av_back = (bp)->av_back; \
	(bp)->b_flags |= B_BUSY; \
D 38
	splx(s); \
E 38
I 38
	splx(x); \
E 38
}
#endif

E 43
/*
D 43
 * Read in (if necessary) the block and return a buffer pointer.
 */
struct buf *
D 41
bread(dev, blkno)
dev_t dev;
daddr_t blkno;
E 41
I 41
bread(dev, blkno, size)
	dev_t dev;
	daddr_t blkno;
	int size;
E 41
{
	register struct buf *bp;

D 41
	bp = getblk(dev, blkno);
E 41
I 41
	bp = getblk(dev, blkno, size);
E 41
	if (bp->b_flags&B_DONE) {
I 16
D 30
#ifdef	EPAWNJ
		trace(TR_BREAD|TR_HIT, dev, blkno);
E 30
I 30
#ifdef	TRACE
		trace(TR_BREADHIT, dev, blkno);
E 30
#endif
E 16
#ifdef	DISKMON
		io_info.ncache++;
#endif
		return(bp);
	}
	bp->b_flags |= B_READ;
D 41
	bp->b_bcount = BSIZE;
E 41
	(*bdevsw[major(dev)].d_strategy)(bp);
I 16
D 30
#ifdef	EPAWNJ
	trace(TR_BREAD|TR_MISS, dev, blkno);
E 30
I 30
#ifdef	TRACE
	trace(TR_BREADMISS, dev, blkno);
E 30
#endif
E 16
#ifdef	DISKMON
	io_info.nread++;
#endif
	u.u_vm.vm_inblk++;		/* pay for read */
	iowait(bp);
	return(bp);
}

/*
 * Read in the block, like bread, but also start I/O on the
 * read-ahead block (which is not allocated to the caller)
 */
struct buf *
D 41
breada(dev, blkno, rablkno)
dev_t dev;
daddr_t blkno, rablkno;
E 41
I 41
breada(dev, blkno, rablkno, size)
	dev_t dev;
	daddr_t blkno, rablkno;
	int size;
E 41
{
	register struct buf *bp, *rabp;

	bp = NULL;
	if (!incore(dev, blkno)) {
D 41
		bp = getblk(dev, blkno);
E 41
I 41
		bp = getblk(dev, blkno, size);
E 41
		if ((bp->b_flags&B_DONE) == 0) {
			bp->b_flags |= B_READ;
D 41
			bp->b_bcount = BSIZE;
E 41
			(*bdevsw[major(dev)].d_strategy)(bp);
I 16
D 30
#ifdef	EPAWNJ
			trace(TR_BREAD|TR_MISS, dev, blkno);
E 30
I 30
#ifdef	TRACE
			trace(TR_BREADMISS, dev, blkno);
E 30
#endif
E 16
#ifdef	DISKMON
			io_info.nread++;
#endif
			u.u_vm.vm_inblk++;		/* pay for read */
		}
I 16
D 30
#ifdef	EPAWNJ
E 30
I 30
#ifdef	TRACE
E 30
		else
D 30
			trace(TR_BREAD|TR_HIT, dev, blkno);
E 30
I 30
			trace(TR_BREADHIT, dev, blkno);
E 30
#endif
E 16
	}
	if (rablkno && !incore(dev, rablkno)) {
D 41
		rabp = getblk(dev, rablkno);
E 41
I 41
		rabp = getblk(dev, rablkno, size);
E 41
D 16
		if (rabp->b_flags & B_DONE)
E 16
I 16
		if (rabp->b_flags & B_DONE) {
E 16
			brelse(rabp);
D 16
		else {
E 16
I 16
D 30
#ifdef	EPAWNJ
			trace(TR_BREAD|TR_HIT|TR_RA, dev, blkno);
E 30
I 30
#ifdef	TRACE
			trace(TR_BREADHITRA, dev, blkno);
E 30
#endif
		} else {
E 16
			rabp->b_flags |= B_READ|B_ASYNC;
D 41
			rabp->b_bcount = BSIZE;
E 41
			(*bdevsw[major(dev)].d_strategy)(rabp);
I 16
D 30
#ifdef	EPAWNJ
			trace(TR_BREAD|TR_MISS|TR_RA, dev, rablock);
E 30
I 30
#ifdef	TRACE
			trace(TR_BREADMISSRA, dev, rablock);
E 30
#endif
E 16
#ifdef	DISKMON
			io_info.nreada++;
#endif
			u.u_vm.vm_inblk++;		/* pay in advance */
		}
	}
	if(bp == NULL)
D 41
		return(bread(dev, blkno));
E 41
I 41
		return(bread(dev, blkno, size));
E 41
	iowait(bp);
	return(bp);
}

/*
 * Write the buffer, waiting for completion.
 * Then release the buffer.
 */
bwrite(bp)
register struct buf *bp;
{
	register flag;

	flag = bp->b_flags;
	bp->b_flags &= ~(B_READ | B_DONE | B_ERROR | B_DELWRI | B_AGE);
D 41
	bp->b_bcount = BSIZE;
E 41
#ifdef	DISKMON
	io_info.nwrite++;
#endif
	if ((flag&B_DELWRI) == 0)
		u.u_vm.vm_oublk++;		/* noone paid yet */
I 16
D 30
#ifdef	EPAWNJ
E 30
I 30
#ifdef	TRACE
E 30
D 34
	trace(TR_BWRITE, bp->b_dev, dbtofsb(bp->b_blkno));
E 34
I 34
	trace(TR_BWRITE, bp->b_dev, bp->b_blkno);
E 34
#endif
E 16
	(*bdevsw[major(bp->b_dev)].d_strategy)(bp);
	if ((flag&B_ASYNC) == 0) {
		iowait(bp);
		brelse(bp);
	} else if (flag & B_DELWRI)
		bp->b_flags |= B_AGE;
	else
		geterror(bp);
}

/*
 * Release the buffer, marking it so that if it is grabbed
 * for another purpose it will be written out before being
 * given up (e.g. when writing a partial block where it is
 * assumed that another write for the same block will soon follow).
 * This can't be done for magtape, since writes must be done
 * in the same order as requested.
 */
bdwrite(bp)
register struct buf *bp;
{
D 22
	register struct buf *dp;
E 22
I 22
	register int flags;
E 22

	if ((bp->b_flags&B_DELWRI) == 0)
		u.u_vm.vm_oublk++;		/* noone paid yet */
D 22
	dp = bdevsw[major(bp->b_dev)].d_tab;
	if(dp->b_flags & B_TAPE)
E 22
I 22
	flags = bdevsw[major(bp->b_dev)].d_flags;
	if(flags & B_TAPE)
E 22
		bawrite(bp);
	else {
		bp->b_flags |= B_DELWRI | B_DONE;
		brelse(bp);
	}
}

/*
 * Release the buffer, start I/O on it, but don't wait for completion.
 */
bawrite(bp)
register struct buf *bp;
{

	bp->b_flags |= B_ASYNC;
	bwrite(bp);
}

/*
 * release the buffer, with no I/O implied.
 */
brelse(bp)
register struct buf *bp;
{
D 18
	register struct buf **backp;
E 18
I 18
	register struct buf *flist;
E 18
	register s;

	if (bp->b_flags&B_WANTED)
		wakeup((caddr_t)bp);
D 18
	if (bfreelist.b_flags&B_WANTED) {
		bfreelist.b_flags &= ~B_WANTED;
		wakeup((caddr_t)&bfreelist);
E 18
I 18
	if (bfreelist[0].b_flags&B_WANTED) {
		bfreelist[0].b_flags &= ~B_WANTED;
		wakeup((caddr_t)bfreelist);
E 18
	}
D 2
	if (bp->b_flags&B_ERROR)
E 2
I 2
D 18
	if ((bp->b_flags&B_ERROR) && bp->b_dev != NODEV) {
		bunhash(bp);
E 18
I 18
D 24
	if ((bp->b_flags&B_ERROR) && bp->b_dev != NODEV)
E 18
E 2
		bp->b_dev = NODEV;  /* no assoc. on error */
E 24
I 24
	if (bp->b_flags&B_ERROR)
		if (bp->b_flags & B_LOCKED)
			bp->b_flags &= ~B_ERROR;	/* try again later */
		else
			bp->b_dev = NODEV;  		/* no assoc */
E 24
I 2
D 18
	}
E 18
E 2
	s = spl6();
D 18
	if(bp->b_flags & (B_AGE|B_ERROR)) {
		backp = &bfreelist.av_forw;
		(*backp)->av_back = bp;
		bp->av_forw = *backp;
		*backp = bp;
		bp->av_back = &bfreelist;
E 18
I 18
	if (bp->b_flags & (B_ERROR|B_INVAL)) {
		/* block has no info ... put at front of most free list */
		flist = &bfreelist[BQUEUES-1];
		flist->av_forw->av_back = bp;
		bp->av_forw = flist->av_forw;
		flist->av_forw = bp;
		bp->av_back = flist;
E 18
	} else {
D 18
		backp = &bfreelist.av_back;
		(*backp)->av_forw = bp;
		bp->av_back = *backp;
		*backp = bp;
		bp->av_forw = &bfreelist;
E 18
I 18
		if (bp->b_flags & B_LOCKED)
			flist = &bfreelist[BQ_LOCKED];
		else if (bp->b_flags & B_AGE)
			flist = &bfreelist[BQ_AGE];
		else
			flist = &bfreelist[BQ_LRU];
		flist->av_back->av_forw = bp;
		bp->av_back = flist->av_back;
		flist->av_back = bp;
		bp->av_forw = flist;
E 18
	}
	bp->b_flags &= ~(B_WANTED|B_BUSY|B_ASYNC|B_AGE);
	splx(s);
}

I 2
D 3
/* HASHING IS A GUN LIKE CHANGE, THIS IS THE SAFETY */
struct buf *
oincore(dev, blkno)
	dev_t dev;
	daddr_t blkno;
{
	register struct buf *bp;
	register struct buf *dp;
	register int dblkno = fsbtodb(blkno);

	dp = bdevsw[major(dev)].d_tab;
	for (bp=dp->b_forw; bp != dp; bp = bp->b_forw)
		if (bp->b_blkno==dblkno && bp->b_dev==dev &&
		    bp >= buf && bp < &buf[NBUF])
			return (bp);
	return ((struct buf *)0);
}

E 3
E 2
/*
 * See if the block is associated with some buffer
 * (mainly to avoid getting hung up on a wait in breada)
 */
incore(dev, blkno)
dev_t dev;
daddr_t blkno;
{
	register struct buf *bp;
I 18
	register struct buf *dp;
E 18
D 2
	register struct buf *dp;
E 2
D 41
	register int dblkno = fsbtodb(blkno);
E 41

D 2
	dp = bdevsw[major(dev)].d_tab;
	for (bp=dp->b_forw; bp != dp; bp = bp->b_forw)
		if (bp->b_blkno==dblkno && bp->b_dev==dev)
			return(1);
	return(0);
E 2
I 2
D 18
	for (bp = &buf[bufhash[BUFHASH(blkno)]]; bp != &buf[-1];
	    bp = &buf[bp->b_hlink])
D 3
		if (bp->b_blkno == dblkno && bp->b_dev == dev) {
			if (distrust)
			if (oincore(dev, blkno) != bp)		/* TEST */
				panic("incore 1");		/* TEST */
E 3
I 3
D 17
		if (bp->b_blkno == dblkno && bp->b_dev == dev)
E 17
I 17
		if (bp->b_blkno == dblkno && bp->b_dev == dev
					&& !(bp->b_flags & B_INVAL))
E 18
I 18
D 19
	dp = BUFHASH(dev, blkno);
E 19
I 19
D 41
	dp = BUFHASH(dev, dblkno);
E 41
I 41
	dp = BUFHASH(dev, blkno);
E 41
E 19
	for (bp = dp->b_forw; bp != dp; bp = bp->b_forw)
D 41
		if (bp->b_blkno == dblkno && bp->b_dev == dev &&
E 41
I 41
		if (bp->b_blkno == blkno && bp->b_dev == dev &&
E 41
		    !(bp->b_flags & B_INVAL))
E 18
E 17
E 3
			return (1);
D 3
		}
	if (distrust)
	if (oincore(dev, blkno))				/* TEST */
		panic("incore 2");				/* TEST */
E 3
	return (0);
E 2
}

struct buf *
D 41
baddr(dev, blkno)
dev_t dev;
daddr_t blkno;
E 41
I 41
baddr(dev, blkno, size)
	dev_t dev;
	daddr_t blkno;
	int size;
E 41
{

	if (incore(dev, blkno))
D 41
		return (bread(dev, blkno));
E 41
I 41
		return (bread(dev, blkno, size));
E 41
	return (0);
}

/*
 * Assign a buffer for the given block.  If the appropriate
 * block is already associated, return it; otherwise search
 * for the oldest non-busy buffer and reassign it.
I 36
 *
 * We use splx here because this routine may be called
 * on the interrupt stack during a dump, and we don't
 * want to lower the ipl back to 0.
E 36
 */
struct buf *
D 41
getblk(dev, blkno)
dev_t dev;
daddr_t blkno;
E 41
I 41
getblk(dev, blkno, size)
	dev_t dev;
	daddr_t blkno;
	int size;
E 41
{
D 2
	register struct buf *bp;
	register struct buf *dp;
#ifdef	DISKMON
	register i;
#endif
E 2
I 2
	register struct buf *bp, *dp, *ep;
D 15
	register int i, x;
E 2
	register int dblkno = fsbtodb(blkno);
E 15
I 15
D 18
	register int i, x, dblkno;
E 18
I 18
D 23
	register int i, x;
E 23
D 41
	register int dblkno = fsbtodb(blkno);
E 41
I 23
#ifdef	DISKMON
	register int i;
#endif
I 36
	int s;
E 36
E 23
E 18
E 15

I 15
	if ((unsigned)blkno >= 1 << (sizeof(int)*NBBY-PGSHIFT))
		blkno = 1 << ((sizeof(int)*NBBY-PGSHIFT) + 1);
D 41
	dblkno = fsbtodb(blkno);
I 18
	dp = BUFHASH(dev, dblkno);
E 41
I 41
	dp = BUFHASH(dev, blkno);
E 41
E 18
E 15
D 2
	if(major(dev) >= nblkdev)
		panic("blkdev");

E 2
    loop:
D 4
	VOID spl0();
E 4
I 4
D 36
	(void) spl0();
E 36
E 4
D 2
	dp = bdevsw[major(dev)].d_tab;
	if(dp == NULL)
		panic("devtab");
	for (bp=dp->b_forw; bp != dp; bp = bp->b_forw) {
		if (bp->b_blkno!=dblkno || bp->b_dev!=dev)
E 2
I 2
D 18
	for (bp = &buf[bufhash[BUFHASH(blkno)]]; bp != &buf[-1];
	    bp = &buf[bp->b_hlink]) {
D 17
		if (bp->b_blkno != dblkno || bp->b_dev != dev)
E 17
I 17
		if (bp->b_blkno != dblkno || bp->b_dev != dev
					|| bp->b_flags & B_INVAL)
E 18
I 18
	for (bp = dp->b_forw; bp != dp; bp = bp->b_forw) {
D 41
		if (bp->b_blkno != dblkno || bp->b_dev != dev ||
E 41
I 41
		if (bp->b_blkno != blkno || bp->b_dev != dev ||
E 41
		    bp->b_flags&B_INVAL)
E 18
E 17
E 2
			continue;
I 2
D 3
		if (distrust)
		if (bp != oincore(dev, blkno))		/* TEST */
			panic("getblk 1");		/* TEST */
E 3
E 2
D 4
		VOID spl6();
E 4
I 4
D 36
		(void) spl6();
E 36
I 36
		s = spl6();
E 36
E 4
		if (bp->b_flags&B_BUSY) {
			bp->b_flags |= B_WANTED;
			sleep((caddr_t)bp, PRIBIO+1);
I 36
			splx(s);
E 36
			goto loop;
		}
D 4
		VOID spl0();
E 4
I 4
D 36
		(void) spl0();
E 36
I 36
		splx(s);
E 36
E 4
#ifdef	DISKMON
		i = 0;
		dp = bp->av_forw;
D 18
		while (dp != &bfreelist) {
E 18
I 18
		while ((dp->b_flags & B_HEAD) == 0) {
E 18
			i++;
			dp = dp->av_forw;
		}
D 26
		if (i<NBUF)
E 26
I 26
		if (i<64)
E 26
			io_info.bufcount[i]++;
#endif
		notavail(bp);
I 41
		brealloc(bp, size);
E 41
		bp->b_flags |= B_CACHE;
		return(bp);
	}
I 2
D 3
	if (distrust)
	if (oincore(dev, blkno))		/* TEST */
		panic("getblk 2");		/* TEST */
E 3
	if (major(dev) >= nblkdev)
		panic("blkdev");
D 18
	dp = bdevsw[major(dev)].d_tab;
	if (dp == NULL)
		panic("devtab");
E 18
E 2
D 4
	VOID spl6();
E 4
I 4
D 36
	(void) spl6();
E 36
I 36
	s = spl6();
E 36
E 4
D 18
	if (bfreelist.av_forw == &bfreelist) {
		bfreelist.b_flags |= B_WANTED;
		sleep((caddr_t)&bfreelist, PRIBIO+1);
E 18
I 18
	for (ep = &bfreelist[BQUEUES-1]; ep > bfreelist; ep--)
		if (ep->av_forw != ep)
			break;
	if (ep == bfreelist) {		/* no free blocks at all */
		ep->b_flags |= B_WANTED;
		sleep((caddr_t)ep, PRIBIO+1);
I 36
		splx(s);
E 36
E 18
		goto loop;
	}
D 14
	spl0();
E 14
I 14
D 36
	(void) spl0();
E 36
I 36
	splx(s);
E 36
E 14
D 18
	bp = bfreelist.av_forw;
E 18
I 18
	bp = ep->av_forw;
E 18
	notavail(bp);
	if (bp->b_flags & B_DELWRI) {
		bp->b_flags |= B_ASYNC;
		bwrite(bp);
		goto loop;
	}
I 2
D 18
	if (bp->b_dev == NODEV)
		goto done;
	/* INLINE EXPANSION OF bunhash(bp) */
E 18
I 16
D 30
#ifdef EPAWNJ
E 30
I 30
#ifdef TRACE
E 30
D 34
	trace(TR_BRELSE, bp->b_dev, dbtofsb(bp->b_blkno));
E 34
I 34
	trace(TR_BRELSE, bp->b_dev, bp->b_blkno);
E 34
#endif
E 16
I 12
D 18
	(void) spl6();
E 12
	i = BUFHASH(dbtofsb(bp->b_blkno));
	x = bp - buf;
	if (bufhash[i] == x) {
		bufhash[i] = bp->b_hlink;
	} else {
		for (ep = &buf[bufhash[i]]; ep != &buf[-1];
		    ep = &buf[ep->b_hlink])
			if (ep->b_hlink == x) {
				ep->b_hlink = bp->b_hlink;
				goto done;
			}
		panic("getblk");
	}
done:
I 12
	(void) spl0();
E 12
	/* END INLINE EXPANSION */
E 18
E 2
	bp->b_flags = B_BUSY;
I 41
	bfree(bp);
E 41
	bp->b_back->b_forw = bp->b_forw;
	bp->b_forw->b_back = bp->b_back;
	bp->b_forw = dp->b_forw;
	bp->b_back = dp;
	dp->b_forw->b_back = bp;
	dp->b_forw = bp;
	bp->b_dev = dev;
D 41
	bp->b_blkno = dblkno;
E 41
I 41
	bp->b_blkno = blkno;
	brealloc(bp, size);
E 41
I 2
D 18
	i = BUFHASH(blkno);
	bp->b_hlink = bufhash[i];
	bufhash[i] = bp - buf;
E 18
E 2
	return(bp);
}

/*
 * get an empty block,
 * not assigned to any particular device
 */
struct buf *
D 41
geteblk()
E 41
I 41
geteblk(size)
	int size;
E 41
{
D 2
	register struct buf *bp;
	register struct buf *dp;
E 2
I 2
D 6
	register struct buf *bp, *dp, *ep;
	register int i, x;
E 6
I 6
	register struct buf *bp, *dp;
I 37
	int s;
E 37
E 6
E 2

loop:
D 4
	VOID spl6();
E 4
I 4
D 37
	(void) spl6();
E 37
I 37
	s = spl6();
E 37
E 4
D 18
	while (bfreelist.av_forw == &bfreelist) {
		bfreelist.b_flags |= B_WANTED;
		sleep((caddr_t)&bfreelist, PRIBIO+1);
E 18
I 18
	for (dp = &bfreelist[BQUEUES-1]; dp > bfreelist; dp--)
		if (dp->av_forw != dp)
			break;
	if (dp == bfreelist) {		/* no free blocks */
		dp->b_flags |= B_WANTED;
		sleep((caddr_t)dp, PRIBIO+1);
		goto loop;
E 18
	}
D 4
	VOID spl0();
E 4
I 4
D 37
	(void) spl0();
E 37
I 37
	splx(s);
E 37
E 4
D 18
	dp = &bfreelist;
	bp = bfreelist.av_forw;
E 18
I 18
	bp = dp->av_forw;
E 18
	notavail(bp);
	if (bp->b_flags & B_DELWRI) {
		bp->b_flags |= B_ASYNC;
		bwrite(bp);
		goto loop;
	}
I 2
D 16
	if (bp->b_dev != NODEV)
E 16
I 16
D 18
	if (bp->b_dev != NODEV) {
E 18
D 30
#ifdef EPAWNJ
E 30
I 30
#ifdef TRACE
E 30
D 18
		trace(TR_BRELSE, bp->b_dev, dbtofsb(bp->b_blkno));
E 18
I 18
D 34
	trace(TR_BRELSE, bp->b_dev, dbtofsb(bp->b_blkno));
E 34
I 34
	trace(TR_BRELSE, bp->b_dev, bp->b_blkno);
E 34
E 18
#endif
E 16
D 18
		bunhash(bp);
I 16
	}
E 16
E 2
	bp->b_flags = B_BUSY;
E 18
I 18
	bp->b_flags = B_BUSY|B_INVAL;
E 18
	bp->b_back->b_forw = bp->b_forw;
	bp->b_forw->b_back = bp->b_back;
	bp->b_forw = dp->b_forw;
	bp->b_back = dp;
	dp->b_forw->b_back = bp;
	dp->b_forw = bp;
	bp->b_dev = (dev_t)NODEV;
I 41
	bp->b_bcount = size;
E 41
I 2
D 20
	bp->b_hlink = -1;
E 20
E 2
	return(bp);
I 2
}

D 18
bunhash(bp)
	register struct buf *bp;
{
	register struct buf *ep;
D 12
	register int i, x;
E 12
I 12
	register int i, x, s;
E 12

	if (bp->b_dev == NODEV)
		return;
I 12
	s = spl6();
E 12
	i = BUFHASH(dbtofsb(bp->b_blkno));
	x = bp - buf;
	if (bufhash[i] == x) {
		bufhash[i] = bp->b_hlink;
D 12
		return;
E 12
I 12
		goto ret;
E 12
	}
	for (ep = &buf[bufhash[i]]; ep != &buf[-1];
	    ep = &buf[ep->b_hlink])
		if (ep->b_hlink == x) {
			ep->b_hlink = bp->b_hlink;
D 12
			return;
E 12
I 12
			goto ret;
E 12
		}
	panic("bunhash");
I 12
ret:
	splx(s);
E 12
E 2
}

E 18
/*
I 41
 * Allocate space associated with a buffer.
 */
brealloc(bp, size)
	register struct buf *bp;
	int size;
{
	daddr_t start, last;
	register struct buf *ep;
	struct buf *dp;
	int s;

	/*
	 * First need to make sure that all overlaping previous I/O
	 * is dispatched with.
	 */
	if (size == bp->b_bcount)
		return;
	if (size < bp->b_bcount) {
		bp->b_bcount = size;
		return;
	}
	start = bp->b_blkno + (bp->b_bcount / DEV_BSIZE);
	last = bp->b_blkno + (size / DEV_BSIZE) - 1;
	if (bp->b_bcount == 0) {
		start++;
		if (start == last)
			goto allocit;
	}
	dp = BUFHASH(bp->b_dev, bp->b_blkno);
loop:
	(void) spl0();
	for (ep = dp->b_forw; ep != dp; ep = ep->b_forw) {
		if (ep->b_blkno < start || ep->b_blkno > last ||
		    ep->b_dev != bp->b_dev || ep->b_flags&B_INVAL)
			continue;
		s = spl6();
		if (ep->b_flags&B_BUSY) {
			ep->b_flags |= B_WANTED;
			sleep((caddr_t)ep, PRIBIO+1);
			splx(s);
			goto loop;
		}
		(void) spl0();
		/*
		 * What we would really like to do is kill this
		 * I/O since it is now useless. We cannot do that
		 * so we force it to complete, so that it cannot
		 * over-write our useful data later.
		 */
		if (ep->b_flags & B_DELWRI) {
			notavail(ep);
			ep->b_flags |= B_ASYNC;
			bwrite(ep);
			goto loop;
		}
	}
allocit:
	/*
	 * Here the buffer is already available, so all we
	 * need to do is set the size. Someday a better memory
	 * management scheme will be implemented.
	 */
	bp->b_bcount = size;
}

/*
 * Release space associated with a buffer.
 */
bfree(bp)
	struct buf *bp;
{
	/*
	 * Here the buffer does not change, so all we
	 * need to do is set the size. Someday a better memory
	 * management scheme will be implemented.
	 */
	bp->b_bcount = 0;
}

/*
E 41
 * Wait for I/O completion on the buffer; return errors
 * to the user.
 */
iowait(bp)
D 41
register struct buf *bp;
E 41
I 41
	register struct buf *bp;
E 41
{
I 37
	int s;
E 37

D 4
	VOID spl6();
E 4
I 4
D 37
	(void) spl6();
E 37
I 37
	s = spl6();
E 37
E 4
	while ((bp->b_flags&B_DONE)==0)
		sleep((caddr_t)bp, PRIBIO);
D 4
	VOID spl0();
E 4
I 4
D 37
	(void) spl0();
E 37
I 37
	splx(s);
E 37
E 4
	geterror(bp);
}

D 25
#ifndef FASTVAX
E 25
I 25
#ifdef UNFAST
E 25
/*
 * Unlink a buffer from the available list and mark it busy.
 * (internal interface)
 */
notavail(bp)
register struct buf *bp;
{
	register s;

	s = spl6();
	bp->av_back->av_forw = bp->av_forw;
	bp->av_forw->av_back = bp->av_back;
	bp->b_flags |= B_BUSY;
	splx(s);
}
#endif

/*
 * Mark I/O complete on a buffer. If the header
 * indicates a dirty page push completion, the
 * header is inserted into the ``cleaned'' list
 * to be processed by the pageout daemon. Otherwise
 * release it if I/O is asynchronous, and wake 
 * up anyone waiting for it.
 */
iodone(bp)
register struct buf *bp;
{
	register int s;

I 10
	if (bp->b_flags & B_DONE)
		panic("dup iodone");
E 10
	bp->b_flags |= B_DONE;
	if (bp->b_flags & B_DIRTY) {
		if (bp->b_flags & B_ERROR)
			panic("IO err in push");
		s = spl6();
D 32
		cnt.v_pgout++;
E 32
		bp->av_forw = bclnlist;
		bp->b_bcount = swsize[bp - swbuf];
		bp->b_pfcent = swpf[bp - swbuf];
I 32
		cnt.v_pgout++;
		cnt.v_pgpgout += bp->b_bcount / NBPG;
E 32
		bclnlist = bp;
		if (bswlist.b_flags & B_WANTED)
			wakeup((caddr_t)&proc[2]);
		splx(s);
I 9
		return;
E 9
	}
	if (bp->b_flags&B_ASYNC)
		brelse(bp);
	else {
		bp->b_flags &= ~B_WANTED;
		wakeup((caddr_t)bp);
	}
}

/*
 * Zero the core associated with a buffer.
 */
clrbuf(bp)
D 41
struct buf *bp;
E 41
I 41
	struct buf *bp;
E 41
{
D 41
	register *p;
	register c;
E 41
I 41
	register int *p;
	register int c;
E 41

	p = bp->b_un.b_words;
D 41
	c = BSIZE/sizeof(int);
E 41
I 41
	c = bp->b_bcount/sizeof(int);
E 41
	do
		*p++ = 0;
	while (--c);
	bp->b_resid = 0;
}

/*
E 43
 * swap I/O -
 *
 * If the flag indicates a dirty page push initiated
 * by the pageout daemon, we map the page into the i th
 * virtual page of process 2 (the daemon itself) where i is
 * the index of the swap header that has been allocated.
 * We simply initialize the header and queue the I/O but
 * do not wait for completion. When the I/O completes,
D 67
D 68
 * iodone() will link the header to a list of cleaned
E 68
I 68
 * biodone() will link the header to a list of cleaned
E 68
E 67
I 67
 * biodone() will link the header to a list of cleaned
E 67
 * pages to be processed by the pageout daemon.
 */
swap(p, dblkno, addr, nbytes, rdflg, flag, dev, pfcent)
	struct proc *p;
	swblk_t dblkno;
	caddr_t addr;
D 47
	int flag, nbytes;
E 47
I 47
	int nbytes, rdflg, flag;
E 47
	dev_t dev;
D 47
	unsigned pfcent;
E 47
I 47
	u_int pfcent;
E 47
{
	register struct buf *bp;
D 48
	register int c;
E 48
I 48
D 69
	register u_int c;
E 48
	int p2dp;
E 69
	register struct pte *dpte, *vpte;
I 37
D 69
	int s;
I 54
	extern swdone();
I 63
	int error = 0;
E 69
I 69
	register u_int c;
	int p2dp, s, error = 0;
	struct buf *getswbuf();
	int swdone();
E 69
E 63
E 54
E 37

D 4
	VOID spl6();
E 4
I 4
D 37
	(void) spl6();
E 37
I 37
D 64
	s = spl6();
E 64
I 64
D 69
	s = splbio();
E 64
E 37
E 4
	while (bswlist.av_forw == NULL) {
		bswlist.b_flags |= B_WANTED;
		sleep((caddr_t)&bswlist, PSWP+1);
	}
	bp = bswlist.av_forw;
	bswlist.av_forw = bp->av_forw;
D 4
	VOID spl0();
E 4
I 4
D 37
	(void) spl0();
E 37
I 37
	splx(s);
E 37
E 4

E 69
I 69
	bp = getswbuf(PSWP+1);
E 69
	bp->b_flags = B_BUSY | B_PHYS | rdflg | flag;
I 67
#ifdef SECSIZE
	bp->b_blksize = DEV_BSIZE;
#endif SECSIZE
E 67
	if ((bp->b_flags & (B_DIRTY|B_PGIN)) == 0)
		if (rdflg == B_READ)
			sum.v_pswpin += btoc(nbytes);
		else
			sum.v_pswpout += btoc(nbytes);
	bp->b_proc = p;
	if (flag & B_DIRTY) {
		p2dp = ((bp - swbuf) * CLSIZE) * KLMAX;
		dpte = dptopte(&proc[2], p2dp);
		vpte = vtopte(p, btop(addr));
		for (c = 0; c < nbytes; c += NBPG) {
			if (vpte->pg_pfnum == 0 || vpte->pg_fod)
				panic("swap bad pte");
			*dpte++ = *vpte++;
		}
D 54
		bp->b_un.b_addr = (caddr_t)ctob(p2dp);
E 54
I 54
		bp->b_un.b_addr = (caddr_t)ctob(dptov(&proc[2], p2dp));
		bp->b_flags |= B_CALL;
		bp->b_iodone = swdone;
		bp->b_pfcent = pfcent;
E 54
	} else
		bp->b_un.b_addr = addr;
	while (nbytes > 0) {
D 48
		c = imin(ctob(120), nbytes);
		bp->b_bcount = c;
E 48
I 48
		bp->b_bcount = nbytes;
		minphys(bp);
		c = bp->b_bcount;
E 48
		bp->b_blkno = dblkno;
		bp->b_dev = dev;
I 11
D 54
		if (flag & B_DIRTY) {
			swpf[bp - swbuf] = pfcent;
			swsize[bp - swbuf] = nbytes;
		}
E 54
I 34
#ifdef TRACE
		trace(TR_SWAPIO, dev, bp->b_blkno);
#endif
E 34
E 11
D 8
		if (dev == swapdev)
			bp->b_blkno += swplo;
E 8
D 48
		(*bdevsw[major(dev)].d_strategy)(bp);
E 48
I 48
D 49
		physstrat(bp, bdevsw[major(dev).d_strategy, PSWP);
E 49
I 49
D 69
		physstrat(bp, bdevsw[major(dev)].d_strategy, PSWP);
E 69
I 69
		(*bdevsw[major(dev)].d_strategy)(bp);
		/* pageout daemon doesn't wait for pushed pages */
E 69
E 49
E 48
		if (flag & B_DIRTY) {
			if (c < nbytes)
				panic("big push");
D 11
			swsize[bp - swbuf] = nbytes;
			swpf[bp - swbuf] = pfcent;
E 11
D 63
			return;
E 63
I 63
D 67
D 68
			return (error);
E 68
I 68
			return (0);
I 69
		} else {
			s = splbio();
			while ((bp->b_flags & B_DONE) == 0)
				sleep((caddr_t)bp, PSWP);
			splx(s);
E 69
E 68
E 67
I 67
			return (0);
E 67
E 63
		}
D 4
		VOID spl6();
E 4
I 4
D 37
		(void) spl6();
E 37
I 37
D 48
		s = spl6();
E 37
E 4
		while((bp->b_flags&B_DONE)==0)
			sleep((caddr_t)bp, PSWP);
D 4
		VOID spl0();
E 4
I 4
D 37
		(void) spl0();
E 37
I 37
		splx(s);
E 48
E 37
E 4
		bp->b_un.b_addr += c;
		bp->b_flags &= ~B_DONE;
		if (bp->b_flags & B_ERROR) {
			if ((flag & (B_UAREA|B_PAGET)) || rdflg == B_WRITE)
				panic("hard IO err in swap");
D 60
			swkill(p, (char *)0);
E 60
I 60
			swkill(p, "swap: read error from swap device");
I 63
			error = EIO;
E 63
E 60
		}
		nbytes -= c;
I 67
#ifdef SECSIZE
		if (flag & B_PGIN && nbytes > 0)
			panic("big pgin");
#endif SECSIZE
E 67
D 48
		dblkno += btoc(c);
E 48
I 48
D 55
		dblkno += c / DEV_BSIZE;
E 55
I 55
		dblkno += btodb(c);
E 55
E 48
	}
D 4
	VOID spl6();
E 4
I 4
D 37
	(void) spl6();
E 37
I 37
D 64
	s = spl6();
E 64
I 64
D 69
	s = splbio();
E 69
E 64
E 37
E 4
	bp->b_flags &= ~(B_BUSY|B_WANTED|B_PHYS|B_PAGET|B_UAREA|B_DIRTY);
D 69
	bp->av_forw = bswlist.av_forw;
	bswlist.av_forw = bp;
	if (bswlist.b_flags & B_WANTED) {
		bswlist.b_flags &= ~B_WANTED;
		wakeup((caddr_t)&bswlist);
		wakeup((caddr_t)&proc[2]);
	}
I 54
	splx(s);
E 69
I 69
	freeswbuf(bp);
E 69
I 63
	return (error);
E 63
}

/*
 * Put a buffer on the clean list after I/O is done.
 * Called from biodone.
 */
swdone(bp)
	register struct buf *bp;
{
	register int s;

	if (bp->b_flags & B_ERROR)
		panic("IO err in push");
D 64
	s = spl6();
E 64
I 64
	s = splbio();
E 64
	bp->av_forw = bclnlist;
	cnt.v_pgout++;
	cnt.v_pgpgout += bp->b_bcount / NBPG;
	bclnlist = bp;
	if (bswlist.b_flags & B_WANTED)
		wakeup((caddr_t)&proc[2]);
E 54
D 4
	VOID spl0();
E 4
I 4
D 37
	(void) spl0();
E 37
I 37
	splx(s);
E 37
E 4
}

/*
 * If rout == 0 then killed on swap error, else
 * rout is the name of the routine where we ran out of
 * swap space.
 */
swkill(p, rout)
	struct proc *p;
	char *rout;
{
I 27
D 60
	char *mesg;
E 60
E 27

D 27
	printf("%d: ", p->p_pid);
E 27
I 27
D 60
	printf("pid %d: ", p->p_pid);
E 27
	if (rout)
D 27
		printf("out of swap space in %s\n", rout);
E 27
I 27
		printf(mesg = "killed due to no swap space\n");
E 27
	else
D 27
		printf("killed on swap error\n");
E 27
I 27
		printf(mesg = "killed on swap error\n");
	uprintf("sorry, pid %d was %s", p->p_pid, mesg);
E 60
I 60
D 62
	printf("pid %d: %s", p->p_pid, rout);
	uprintf("sorry, pid %d was killed in %s", p->p_pid, rout);
E 62
I 62
	printf("pid %d: %s\n", p->p_pid, rout);
	uprintf("sorry, pid %d was killed in %s\n", p->p_pid, rout);
E 62
E 60
E 27
	/*
	 * To be sure no looping (e.g. in vmsched trying to
	 * swap out) mark process locked in core (as though
	 * done by user) after killing it so noone will try
	 * to swap it out.
	 */
D 5
	psignal(p, SIGKIL);
E 5
I 5
	psignal(p, SIGKILL);
E 5
	p->p_flag |= SULOCK;
}

/*
D 43
 * make sure all write-behind blocks
 * on dev (or NODEV for all)
 * are flushed out.
 * (from umount and update)
I 41
 * (and temporarily pagein)
E 41
 */
bflush(dev)
dev_t dev;
{
	register struct buf *bp;
I 18
	register struct buf *flist;
I 37
	int s;
E 37
E 18

loop:
D 4
	VOID spl6();
E 4
I 4
D 37
	(void) spl6();
E 37
I 37
	s = spl6();
E 37
E 4
D 18
	for (bp = bfreelist.av_forw; bp != &bfreelist; bp = bp->av_forw) {
E 18
I 18
	for (flist = bfreelist; flist < &bfreelist[BQUEUES]; flist++)
	for (bp = flist->av_forw; bp != flist; bp = bp->av_forw) {
E 18
		if (bp->b_flags&B_DELWRI && (dev == NODEV||dev==bp->b_dev)) {
			bp->b_flags |= B_ASYNC;
			notavail(bp);
			bwrite(bp);
			goto loop;
		}
	}
D 4
	VOID spl0();
E 4
I 4
D 37
	(void) spl0();
E 37
I 37
	splx(s);
E 37
E 4
}

/*
E 43
 * Raw I/O. The arguments are
 *	The strategy routine for the device
D 69
 *	A buffer, which will always be a special buffer
 *	  header owned exclusively by the device for this purpose
E 69
I 69
 *	A buffer, which will either be a special buffer header owned
 *	    exclusively by the device for this purpose, or NULL,
 *	    indicating that we should use a swap buffer
E 69
 *	The device number
 *	Read/write flag
 * Essentially all the work is computing physical addresses and
 * validating them.
 * If the user has the proper access privilidges, the process is
 * marked 'delayed unlock' and the pages involved in the I/O are
 * faulted and locked. After the completion of the I/O, the above pages
 * are unlocked.
 */
D 44
physio(strat, bp, dev, rw, mincnt)
int (*strat)(); 
register struct buf *bp;
unsigned (*mincnt)();
E 44
I 44
physio(strat, bp, dev, rw, mincnt, uio)
	int (*strat)(); 
	register struct buf *bp;
	dev_t dev;
	int rw;
D 69
	unsigned (*mincnt)();
E 69
I 69
	u_int (*mincnt)();
E 69
	struct uio *uio;
E 44
{
I 45
D 59
	register struct iovec *iov = uio->uio_iov;
E 59
I 59
	register struct iovec *iov;
E 59
E 45
	register int c;
I 44
D 45
	struct uio auio;
	register struct iovec *iov;
	struct iovec aiov;
E 45
E 44
	char *a;
I 37
D 44
	int s;
E 44
I 44
D 69
	int s, error = 0;
E 69
I 69
	int s, allocbuf = 0, error = 0;
	struct buf *getswbuf();
E 69
I 67
#ifdef SECSIZE
	int bsize;
	struct partinfo dpart;
#endif SECSIZE
E 67
E 44
E 37

D 44
	if (useracc(u.u_base,u.u_count,rw==B_READ?B_WRITE:B_READ) == NULL) {
E 44
I 44
D 45
	if (uio == 0) {
		uio = &auio;
		uio->uio_iov = &aiov;
		uio->uio_iovcnt = 1;
		uio->uio_offset = u.u_offset;
		uio->uio_segflg = u.u_segflg;
		iov = &aiov;
		iov->iov_base = u.u_base;
		iov->iov_len = u.u_count;
		uio->uio_resid = iov->iov_len;
	} else
		iov = uio->uio_iov;
E 45
D 67
D 68
nextiov:
D 45
	if (uio->uio_iovcnt == 0) {
		u.u_count = uio->uio_resid;
E 45
I 45
	if (uio->uio_iovcnt == 0)
E 45
		return (0);
I 59
	iov = uio->uio_iov;
E 59
D 45
	}
	if (useracc(iov->iov_base,iov->iov_len,rw==B_READ?B_WRITE:B_READ) == NULL) {
		u.u_count = uio->uio_resid;
E 44
		u.u_error = EFAULT;
E 45
I 45
	if (useracc(iov->iov_base,(u_int)iov->iov_len,rw==B_READ?B_WRITE:B_READ) == NULL)
E 45
D 44
		return;
E 44
I 44
		return (EFAULT);
E 44
D 45
	}
E 45
D 4
	VOID spl6();
E 4
I 4
D 37
	(void) spl6();
E 37
I 37
D 64
	s = spl6();
E 64
I 64
	s = splbio();
E 64
E 37
E 4
	while (bp->b_flags&B_BUSY) {
		bp->b_flags |= B_WANTED;
		sleep((caddr_t)bp, PRIBIO+1);
	}
I 39
	splx(s);
E 39
	bp->b_error = 0;
	bp->b_proc = u.u_procp;
D 44
	bp->b_un.b_addr = u.u_base;
D 31
	while (u.u_count != 0 && bp->b_error==0) {
E 31
I 31
D 33
	while (u.u_count != 0 && (bp->b_flags&B_ERROR)==0) {
E 33
I 33
	while (u.u_count != 0) {
E 44
I 44
	bp->b_un.b_addr = iov->iov_base;
	while (iov->iov_len > 0) {
E 44
E 33
E 31
		bp->b_flags = B_BUSY | B_PHYS | rw;
		bp->b_dev = dev;
D 44
		bp->b_blkno = u.u_offset >> PGSHIFT;
		bp->b_bcount = u.u_count;
E 44
I 44
D 48
		bp->b_blkno = uio->uio_offset >> PGSHIFT;
E 48
I 48
D 55
		bp->b_blkno = uio->uio_offset / DEV_BSIZE;
E 55
I 55
		bp->b_blkno = btodb(uio->uio_offset);
E 55
E 48
		bp->b_bcount = iov->iov_len;
E 44
		(*mincnt)(bp);
		c = bp->b_bcount;
		u.u_procp->p_flag |= SPHYSIO;
		vslock(a = bp->b_un.b_addr, c);
D 48
		(*strat)(bp);
E 48
I 48
		physstrat(bp, strat, PRIBIO);
E 48
D 4
		VOID spl6();
E 4
I 4
D 64
		(void) spl6();
E 64
I 64
		(void) splbio();
E 64
E 4
D 48
		while ((bp->b_flags&B_DONE) == 0)
			sleep((caddr_t)bp, PRIBIO);
E 48
		vsunlock(a, c, rw);
		u.u_procp->p_flag &= ~SPHYSIO;
		if (bp->b_flags&B_WANTED)
			wakeup((caddr_t)bp);
E 68
I 68
D 69
	for (;;) {
		if (uio->uio_iovcnt == 0)
			return (0);
E 69
I 69
	if (bp == NULL) {
		allocbuf = 1;
		bp = getswbuf(PRIBIO+1);
	}
	for (; uio->uio_iovcnt; uio->uio_iov++, uio->uio_iovcnt--) {
E 69
		iov = uio->uio_iov;
D 69
		if (useracc(iov->iov_base, (u_int)iov->iov_len,
		    rw==B_READ? B_WRITE : B_READ) == NULL)
			return (EFAULT);
		s = splbio();
		while (bp->b_flags&B_BUSY) {
			bp->b_flags |= B_WANTED;
			sleep((caddr_t)bp, PRIBIO+1);
E 69
I 69
		if (!useracc(iov->iov_base, (u_int)iov->iov_len,
		    rw == B_READ ? B_WRITE : B_READ)) {
			error = EFAULT;
			break;
E 69
		}
E 68
E 67
I 67
#ifdef SECSIZE
	if ((unsigned)major(dev) < nchrdev &&
	    (*cdevsw[major(dev)].d_ioctl)(dev, DIOCGPART, (caddr_t)&dpart,
	    FREAD) == 0)
		bsize = dpart.disklab->d_secsize;
	else
		bsize = DEV_BSIZE;
#endif SECSIZE
	for (;;) {
		if (uio->uio_iovcnt == 0)
			return (0);
		iov = uio->uio_iov;
		if (useracc(iov->iov_base, (u_int)iov->iov_len,
		    rw==B_READ? B_WRITE : B_READ) == NULL)
			return (EFAULT);
		s = splbio();
		while (bp->b_flags&B_BUSY) {
			bp->b_flags |= B_WANTED;
			sleep((caddr_t)bp, PRIBIO+1);
		}
E 67
D 4
		VOID spl0();
E 4
I 4
D 37
		(void) spl0();
E 37
I 37
D 69
		splx(s);
E 69
I 69
		if (!allocbuf) {	/* only if sharing caller's buffer */
			s = splbio();
			while (bp->b_flags&B_BUSY) {
				bp->b_flags |= B_WANTED;
				sleep((caddr_t)bp, PRIBIO+1);
			}
			splx(s);
		}
E 69
I 44
D 67
D 68
		c -= bp->b_resid;
E 44
E 37
E 4
		bp->b_un.b_addr += c;
D 44
		u.u_count -= c;
		u.u_offset += c;
E 44
I 44
		iov->iov_len -= c;
		uio->uio_resid -= c;
		uio->uio_offset += c;
E 68
I 68
		bp->b_error = 0;
		bp->b_proc = u.u_procp;
		bp->b_un.b_addr = iov->iov_base;
		while (iov->iov_len > 0) {
D 69
			bp->b_flags = B_BUSY | B_PHYS | rw;
E 69
I 69
			bp->b_flags = B_BUSY | B_PHYS | B_RAW | rw;
E 69
			bp->b_dev = dev;
			bp->b_blkno = btodb(uio->uio_offset);
			bp->b_bcount = iov->iov_len;
			(*mincnt)(bp);
			c = bp->b_bcount;
			u.u_procp->p_flag |= SPHYSIO;
			vslock(a = bp->b_un.b_addr, c);
D 69
			physstrat(bp, strat, PRIBIO);
			(void) splbio();
E 69
I 69
			(*strat)(bp);
			s = splbio();
			while ((bp->b_flags & B_DONE) == 0)
				sleep((caddr_t)bp, PRIBIO);
E 69
			vsunlock(a, c, rw);
			u.u_procp->p_flag &= ~SPHYSIO;
D 69
			if (bp->b_flags&B_WANTED)
E 69
I 69
			if (bp->b_flags&B_WANTED)	/* rare */
E 69
				wakeup((caddr_t)bp);
			splx(s);
			c -= bp->b_resid;
			bp->b_un.b_addr += c;
			iov->iov_len -= c;
			uio->uio_resid -= c;
			uio->uio_offset += c;
			/* temp kludge for tape drives */
			if (bp->b_resid || (bp->b_flags&B_ERROR))
				break;
		}
D 69
		bp->b_flags &= ~(B_BUSY|B_WANTED|B_PHYS);
E 69
I 69
		bp->b_flags &= ~(B_BUSY | B_WANTED | B_PHYS | B_RAW);
E 69
		error = geterror(bp);
E 68
E 67
I 67
		bp->b_error = 0;
		bp->b_proc = u.u_procp;
#ifdef SECSIZE
		bp->b_blksize = bsize;
#endif SECSIZE
		bp->b_un.b_addr = iov->iov_base;
		while (iov->iov_len > 0) {
			bp->b_flags = B_BUSY | B_PHYS | rw;
			bp->b_dev = dev;
#ifdef SECSIZE
			bp->b_blkno = uio->uio_offset / bsize;
#else SECSIZE
			bp->b_blkno = btodb(uio->uio_offset);
#endif SECSIZE
			bp->b_bcount = iov->iov_len;
			(*mincnt)(bp);
			c = bp->b_bcount;
			u.u_procp->p_flag |= SPHYSIO;
			vslock(a = bp->b_un.b_addr, c);
			physstrat(bp, strat, PRIBIO);
			(void) splbio();
			vsunlock(a, c, rw);
			u.u_procp->p_flag &= ~SPHYSIO;
			if (bp->b_flags&B_WANTED)
				wakeup((caddr_t)bp);
			splx(s);
			c -= bp->b_resid;
			bp->b_un.b_addr += c;
			iov->iov_len -= c;
			uio->uio_resid -= c;
			uio->uio_offset += c;
			/* temp kludge for tape drives */
			if (bp->b_resid || (bp->b_flags&B_ERROR))
				break;
		}
		bp->b_flags &= ~(B_BUSY|B_WANTED|B_PHYS);
		error = geterror(bp);
E 67
E 44
I 33
D 50
		if (bp->b_flags&B_ERROR)
E 50
I 50
		/* temp kludge for tape drives */
D 51
		if (bp->b_resid || bp->b_flags&B_ERROR)
E 51
I 51
D 67
D 68
		if (bp->b_resid || (bp->b_flags&B_ERROR))
E 51
E 50
			break;
E 68
I 68
		if (bp->b_resid || error)
D 69
			return (error);
		uio->uio_iov++;
		uio->uio_iovcnt--;
E 69
I 69
			break;
E 69
E 68
E 67
I 67
		if (bp->b_resid || error)
			return (error);
		uio->uio_iov++;
		uio->uio_iovcnt--;
E 67
E 33
	}
I 69
	if (allocbuf)
		freeswbuf(bp);
	return (error);
E 69
D 67
D 68
	bp->b_flags &= ~(B_BUSY|B_WANTED|B_PHYS);
D 44
	u.u_count = bp->b_resid;
	geterror(bp);
E 44
I 44
	error = geterror(bp);
D 45
	if (error) {
		u.u_error = error;
		u.u_count = uio->uio_resid;
E 45
I 45
D 50
	if (error)
E 50
I 50
	/* temp kludge for tape drives */
	if (bp->b_resid || error)
E 50
E 45
		return (error);
D 45
	}
E 45
	uio->uio_iov++;
	uio->uio_iovcnt--;
	goto nextiov;
E 68
E 67
E 44
}
D 67
D 68

I 66
#if defined(tahoe)
#define	MAXPHYS	(KLMAX * CLBYTES)
#endif
#if defined(vax)
E 66
I 51
#define	MAXPHYS	(63 * 1024)
I 66
#endif
E 68
E 67
E 66

D 57
/* network disk brain damage */
#include "nd.h"
#if NND > 0
I 52
#undef MAXPHYS
E 52
#define	MAXPHYS	(32 * 1024)
#endif

E 57
E 51
D 48
/*ARGSUSED*/
E 48
D 69
unsigned
E 69
I 69
u_int
E 69
minphys(bp)
D 44
struct buf *bp;
E 44
I 44
	struct buf *bp;
E 44
{
D 69

E 69
D 39
	if (bp->b_bcount > 60 * 1024)
		bp->b_bcount = 60 * 1024;
E 39
I 39
D 40
	if (bp->b_bcount > 65 * 1024)
		bp->b_bcount = 65 * 1024;
E 40
I 40
D 51
	if (bp->b_bcount > 63 * 1024)
		bp->b_bcount = 63 * 1024;
E 51
I 51
	if (bp->b_bcount > MAXPHYS)
		bp->b_bcount = MAXPHYS;
I 69
}

static
struct buf *
getswbuf(prio)
	int prio;
{
	int s;
	struct buf *bp;

	s = splbio();
	while (bswlist.av_forw == NULL) {
		bswlist.b_flags |= B_WANTED;
		sleep((caddr_t)&bswlist, prio);
	}
	bp = bswlist.av_forw;
	bswlist.av_forw = bp->av_forw;
	splx(s);
	return (bp);
}

static
freeswbuf(bp)
	struct buf *bp;
{
	int s;

	s = splbio();
	bp->av_forw = bswlist.av_forw;
	bswlist.av_forw = bp;
	if (bswlist.b_flags & B_WANTED) {
		bswlist.b_flags &= ~B_WANTED;
		wakeup((caddr_t)&bswlist);
		wakeup((caddr_t)&proc[2]);
	}
	splx(s);
}

rawread(dev, uio)
	dev_t dev;
	struct uio *uio;
{
	return (physio(cdevsw[major(dev)].d_strategy, (struct buf *)NULL,
	    dev, B_READ, minphys, uio));
}

rawwrite(dev, uio)
	dev_t dev;
	struct uio *uio;
{
	return (physio(cdevsw[major(dev)].d_strategy, (struct buf *)NULL,
	    dev, B_WRITE, minphys, uio));
E 69
E 51
E 40
E 39
}
I 41
D 57

E 57
E 41
D 43

/*
 * Pick up the device's error number and pass it to the user;
 * if there is an error but the number is 0 set a generalized
 * code.  Actually the latter is always true because devices
 * don't yet return specific errors.
 */
geterror(bp)
register struct buf *bp;
{

	if (bp->b_flags&B_ERROR)
		if ((u.u_error = bp->b_error)==0)
			u.u_error = EIO;
I 17
}

/*
 * Invalidate in core blocks belonging to closed or umounted filesystem
 *
 * This is not nicely done at all - the buffer ought to be removed from the
 * hash chains & have its dev/blkno fields clobbered, but unfortunately we
 * can't do that here, as it is quite possible that the block is still
 * being used for i/o. Eventually, all disc drivers should be forced to
 * have a close routine, which ought ensure that the queue is empty, then
 * properly flush the queues. Until that happy day, this suffices for
 * correctness.						... kre
 */
binval(dev)
dev_t dev;
{
D 21
	register struct buf *bp, *dp;
E 21
I 21
	register struct buf *bp;
	register struct bufhd *hp;
#define dp ((struct buf *)hp)
E 21

D 21
	dp = bdevsw[major(dev)].d_tab;
D 18

E 18
	for (bp = dp->b_forw; bp != dp; bp = bp->b_forw)
		if (bp->b_dev == dev)
			bp->b_flags |= B_INVAL;
E 21
I 21
	for (hp = bufhash; hp < &bufhash[BUFHSZ]; hp++)
		for (bp = dp->b_forw; bp != dp; bp = bp->b_forw)
			if (bp->b_dev == dev)
				bp->b_flags |= B_INVAL;
E 21
E 17
}
E 43
E 1
