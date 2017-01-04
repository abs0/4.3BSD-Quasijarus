h35155
s 00019/00003/00608
d D 7.3 87/11/12 15:21:25 mckusick 76 75
c write dirty buffers that are growing to avoid bread'ing stale 
c data from the disk over the newer data in the buffer.
e
s 00005/00004/00606
d D 7.2 87/04/02 15:49:12 karels 75 73
c working with pack labels
e
s 00079/00004/00606
d D 7.1.1.1 87/04/02 15:41:08 karels 74 73
c add ifdefs for dev_bsize (almost working)
e
s 00001/00001/00609
d D 7.1 86/06/05 00:11:54 mckusick 73 72
c 4.3BSD release version
e
s 00012/00012/00598
d D 6.9 86/02/20 15:19:38 karels 72 71
c lint and cleanups from Sam
e
s 00004/00000/00606
d D 6.8 85/10/23 16:13:44 mckusick 71 70
c sanity checks in getblk() and geteblk()
e
s 00001/00003/00605
d D 6.7 85/09/17 10:40:42 karels 70 69
c I've wanted to make this comment untrue for a long time...
e
s 00010/00002/00598
d D 6.6 85/09/13 19:23:28 mckusick 69 68
c wrong constant used by coincidence (PGSHIFT should be DEV_BSHIFT)
e
s 00007/00001/00593
d D 6.5 85/06/08 14:50:13 mckusick 68 67
c Add copyright
e
s 00010/00010/00584
d D 6.4 84/08/29 20:25:28 bloom 67 66
c Change to includes.  no more ../h
e
s 00001/00001/00593
d D 6.3 84/08/07 22:42:49 mckusick 66 65
c avoid calling brealloc() when unnecessary
e
s 00010/00008/00584
d D 6.2 84/01/03 19:43:45 sam 65 64
c pack block size into trace record for buffer cache
e
s 00000/00000/00592
d D 6.1 83/07/29 06:40:55 sam 64 63
c 4.2 distribution
e
s 00000/00004/00592
d D 4.48 83/07/01 02:20:38 sam 63 62
c purge #if sun's
e
s 00005/00183/00591
d D 4.47 83/06/14 23:51:48 sam 62 61
c move machine dependent parts out
e
s 00004/00004/00770
d D 4.46 83/05/21 15:43:00 sam 61 60
c macro-ized for speeeeeeeeeeeeed
e
s 00000/00016/00774
d D 4.45 83/05/18 01:58:11 sam 60 58
c changes from sun to do swapping on variable sized devices
e
s 00000/00015/00775
d R 4.45 83/05/06 09:24:42 sam 59 58
c from pugs@sun.UUCP; removes dirty page pushes from bio routines
e
s 00001/00000/00789
d D 4.44 83/05/02 07:18:10 sam 58 57
c another missing splx; from shannon@sun.UUCP
e
s 00001/00000/00788
d D 4.43 83/05/01 19:21:55 sam 57 56
c missing splx causes long periods of running at spl6; 
c from shannon@sun.UUCP
e
s 00002/00001/00786
d D 4.42 83/04/04 21:48:50 sam 56 55
c hack, but it fixes EBADF
e
s 00001/00005/00786
d D 4.41 82/12/19 17:41:34 sam 55 54
c bwrite shouldn't clear B_AGE or brelse won't put it at the head 
c of the free list (Mike Karels); also geterror call is extraneous
e
s 00117/00016/00674
d D 4.40 82/12/17 11:48:23 sam 54 53
c sun merge
e
s 00179/00077/00511
d D 4.39 82/11/13 22:52:27 sam 53 52
c merge of 4.1b and 4.1c
e
s 00000/00000/00588
d D 4.39 82/10/19 10:32:02  53 52
c more lint
e
s 00000/00000/00588
d D 4.38 82/10/17 21:51:03 root 52 51
c more lint
e
s 00003/00003/00585
d D 4.37 82/10/17 14:06:17 root 51 50
c fix lint
e
s 00005/00005/00583
d D 4.36 82/09/04 09:20:52 root 50 49
c new names for some counters
e
s 00006/00004/00582
d D 4.35 82/08/13 00:04:59 wnj 49 48
c fixes to get uio'd readi for char devs
e
s 00050/00022/00536
d D 4.34 82/06/14 22:59:41 root 48 47
c fixes to interactions of new fs and buffer cache with partial blocks
c including removal of superblocks from cache and refined readahead and
c brealloc routine
e
s 00010/00009/00548
d D 4.33 82/06/07 23:47:12 mckusick 47 46
c fix read-ahead block calculation
e
s 00004/00005/00553
d D 4.32 82/06/01 23:22:04 mckusick 46 45
c incorporate brealloc into geteblk()
e
s 00072/00197/00486
d D 4.31 82/05/31 19:13:27 mckusick 45 43
c clean up code; put common queue operations into macros
e
s 00073/00199/00484
d R 4.31 82/05/22 16:28:03 mckusick 44 43
c clean up code; put common list operations into macros
e
s 00000/00214/00683
d D 4.30 82/05/22 15:55:21 mckusick 43 41
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
D 68
/*	%M%	%I%	%E%	*/
E 68
I 68
/*
D 73
 * Copyright (c) 1982 Regents of the University of California.
E 73
I 73
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 73
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 68
E 35
E 34
E 29
E 7

I 54
#include "../machine/pte.h"

E 54
I 41
D 45
/* merged into kernel:	 @(#)bio.c 2.3 4/8/82 */

E 45
E 41
I 2
D 3
int	distrust = 1;		/* TEST */
E 3
E 2
D 67
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/buf.h"
#include "../h/conf.h"
#include "../h/proc.h"
#include "../h/seg.h"
D 54
#include "../h/pte.h"
E 54
#include "../h/vm.h"
I 16
#include "../h/trace.h"
E 67
I 67
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
E 67
E 16

I 48
D 53
int bioprintfs = 0;

E 53
E 48
I 2
/*
D 45
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
D 43
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
short	*swsize;		/* CAN WE JUST USE B_BCOUNT? */
int	*swpf;
E 43
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

E 43
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

/*
E 45
 * Read in (if necessary) the block and return a buffer pointer.
 */
struct buf *
I 74
#ifdef SECSIZE
bread(dev, blkno, size, secsize)
#else SECSIZE
E 74
D 41
bread(dev, blkno)
dev_t dev;
daddr_t blkno;
E 41
I 41
bread(dev, blkno, size)
I 74
#endif SECSIZE
E 74
	dev_t dev;
	daddr_t blkno;
	int size;
I 74
#ifdef SECSIZE
	long secsize;
#endif SECSIZE
E 74
E 41
{
	register struct buf *bp;

I 53
	if (size == 0)
		panic("bread: size 0");
I 74
#ifdef SECSIZE
	bp = getblk(dev, blkno, size, secsize);
#else SECSIZE
E 74
E 53
D 41
	bp = getblk(dev, blkno);
E 41
I 41
	bp = getblk(dev, blkno, size);
I 74
#endif SECSIZE
E 74
E 41
D 76
	if (bp->b_flags&B_DONE) {
E 76
I 76
	if (bp->b_flags&(B_DONE|B_DELWRI)) {
E 76
I 16
D 30
#ifdef	EPAWNJ
		trace(TR_BREAD|TR_HIT, dev, blkno);
E 30
I 30
D 45
#ifdef	TRACE
E 45
D 65
		trace(TR_BREADHIT, dev, blkno);
E 65
I 65
		trace(TR_BREADHIT, pack(dev, size), blkno);
E 65
E 30
D 45
#endif
E 16
#ifdef	DISKMON
		io_info.ncache++;
#endif
E 45
D 72
		return(bp);
E 72
I 72
		return (bp);
E 72
	}
	bp->b_flags |= B_READ;
I 53
	if (bp->b_bcount > bp->b_bufsize)
		panic("bread");
E 53
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
D 45
#ifdef	TRACE
E 45
D 65
	trace(TR_BREADMISS, dev, blkno);
E 65
I 65
	trace(TR_BREADMISS, pack(dev, size), blkno);
E 65
E 30
D 45
#endif
E 16
#ifdef	DISKMON
	io_info.nread++;
#endif
E 45
D 50
	u.u_vm.vm_inblk++;		/* pay for read */
E 50
I 50
	u.u_ru.ru_inblock++;		/* pay for read */
E 50
D 45
	iowait(bp);
E 45
I 45
	biowait(bp);
E 45
D 72
	return(bp);
E 72
I 72
	return (bp);
E 72
}

/*
 * Read in the block, like bread, but also start I/O on the
 * read-ahead block (which is not allocated to the caller)
 */
struct buf *
I 74
#ifdef SECSIZE
breada(dev, blkno, size, secsize, rablkno, rabsize)
#else SECSIZE
E 74
D 41
breada(dev, blkno, rablkno)
dev_t dev;
daddr_t blkno, rablkno;
E 41
I 41
D 47
breada(dev, blkno, rablkno, size)
E 47
I 47
D 51
breada(dev, blkno, size, rablkno, rasize)
E 51
I 51
breada(dev, blkno, size, rablkno, rabsize)
I 74
#endif SECSIZE
E 74
E 51
E 47
	dev_t dev;
D 47
	daddr_t blkno, rablkno;
	int size;
E 47
I 47
	daddr_t blkno; int size;
I 74
#ifdef SECSIZE
	long secsize;
#endif SECSIZE
E 74
D 51
	daddr_t rablkno; int rasize;
E 51
I 51
	daddr_t rablkno; int rabsize;
E 51
E 47
E 41
{
	register struct buf *bp, *rabp;

	bp = NULL;
I 45
	/*
	 * If the block isn't in core, then allocate
	 * a buffer and initiate i/o (getblk checks
	 * for a cache hit).
	 */
E 45
	if (!incore(dev, blkno)) {
I 74
#ifdef SECSIZE
		bp = getblk(dev, blkno, size, secsize);
#else SECSIZE
E 74
D 41
		bp = getblk(dev, blkno);
E 41
I 41
		bp = getblk(dev, blkno, size);
I 74
#endif SECSIZE
E 74
E 41
D 76
		if ((bp->b_flags&B_DONE) == 0) {
E 76
I 76
		if ((bp->b_flags&(B_DONE|B_DELWRI)) == 0) {
E 76
			bp->b_flags |= B_READ;
I 53
			if (bp->b_bcount > bp->b_bufsize)
				panic("breada");
E 53
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
D 45
#ifdef	TRACE
E 45
D 65
			trace(TR_BREADMISS, dev, blkno);
E 65
I 65
			trace(TR_BREADMISS, pack(dev, size), blkno);
E 65
E 30
D 45
#endif
E 16
#ifdef	DISKMON
			io_info.nread++;
#endif
E 45
D 50
			u.u_vm.vm_inblk++;		/* pay for read */
E 50
I 50
			u.u_ru.ru_inblock++;		/* pay for read */
E 50
D 45
		}
I 16
D 30
#ifdef	EPAWNJ
E 30
I 30
#ifdef	TRACE
E 30
		else
E 45
I 45
		} else
E 45
D 30
			trace(TR_BREAD|TR_HIT, dev, blkno);
E 30
I 30
D 65
			trace(TR_BREADHIT, dev, blkno);
E 65
I 65
			trace(TR_BREADHIT, pack(dev, size), blkno);
E 65
E 30
D 45
#endif
E 45
E 16
	}
I 45

	/*
	 * If there's a read-ahead block, start i/o
	 * on it also (as above).
	 */
E 45
	if (rablkno && !incore(dev, rablkno)) {
I 74
#ifdef SECSIZE
		rabp = getblk(dev, rablkno, rabsize, secsize);
#else SECSIZE
E 74
D 41
		rabp = getblk(dev, rablkno);
E 41
I 41
D 47
		rabp = getblk(dev, rablkno, size);
E 47
I 47
D 51
		rabp = getblk(dev, rablkno, rasize);
E 51
I 51
		rabp = getblk(dev, rablkno, rabsize);
I 74
#endif SECSIZE
E 74
E 51
E 47
E 41
D 16
		if (rabp->b_flags & B_DONE)
E 16
I 16
D 76
		if (rabp->b_flags & B_DONE) {
E 76
I 76
		if (rabp->b_flags & (B_DONE|B_DELWRI)) {
E 76
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
D 45
#ifdef	TRACE
E 45
D 65
			trace(TR_BREADHITRA, dev, blkno);
E 65
I 65
			trace(TR_BREADHITRA, pack(dev, rabsize), blkno);
E 65
E 30
D 45
#endif
E 45
		} else {
E 16
			rabp->b_flags |= B_READ|B_ASYNC;
I 53
			if (rabp->b_bcount > rabp->b_bufsize)
				panic("breadrabp");
E 53
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
D 45
#ifdef	TRACE
E 45
D 65
			trace(TR_BREADMISSRA, dev, rablock);
E 65
I 65
			trace(TR_BREADMISSRA, pack(dev, rabsize), rablock);
E 65
E 30
D 45
#endif
E 16
#ifdef	DISKMON
			io_info.nreada++;
#endif
E 45
D 50
			u.u_vm.vm_inblk++;		/* pay in advance */
E 50
I 50
			u.u_ru.ru_inblock++;		/* pay in advance */
E 50
		}
	}
I 45

	/*
D 47
	 * If we get here with bp NULL, then the block
	 * must've been in core and bread will find it for us.
E 47
I 47
	 * If block was in core, let bread get it.
	 * If block wasn't in core, then the read was started
	 * above, and just wait for it.
E 47
	 */
E 45
D 47
	if(bp == NULL)
D 41
		return(bread(dev, blkno));
E 41
I 41
		return(bread(dev, blkno, size));
E 47
I 47
	if (bp == NULL)
I 74
#ifdef SECSIZE
		return (bread(dev, blkno, size, secsize));
#else SECSIZE
E 74
		return (bread(dev, blkno, size));
I 74
#endif SECSIZE
E 74
E 47
E 41
D 45
	iowait(bp);
E 45
I 45
	biowait(bp);
E 45
D 47
	return(bp);
E 47
I 47
	return (bp);
E 47
}

/*
 * Write the buffer, waiting for completion.
 * Then release the buffer.
 */
bwrite(bp)
D 45
register struct buf *bp;
E 45
I 45
	register struct buf *bp;
E 45
{
	register flag;

	flag = bp->b_flags;
D 55
	bp->b_flags &= ~(B_READ | B_DONE | B_ERROR | B_DELWRI | B_AGE);
E 55
I 55
	bp->b_flags &= ~(B_READ | B_DONE | B_ERROR | B_DELWRI);
E 55
D 41
	bp->b_bcount = BSIZE;
E 41
D 45
#ifdef	DISKMON
	io_info.nwrite++;
#endif
E 45
	if ((flag&B_DELWRI) == 0)
D 50
		u.u_vm.vm_oublk++;		/* noone paid yet */
E 50
I 50
		u.u_ru.ru_oublock++;		/* noone paid yet */
E 50
I 16
D 30
#ifdef	EPAWNJ
E 30
I 30
D 45
#ifdef	TRACE
E 45
E 30
D 34
	trace(TR_BWRITE, bp->b_dev, dbtofsb(bp->b_blkno));
E 34
I 34
D 65
	trace(TR_BWRITE, bp->b_dev, bp->b_blkno);
E 65
I 65
	trace(TR_BWRITE, pack(bp->b_dev, bp->b_bcount), bp->b_blkno);
E 65
I 48
D 53
if (bioprintfs)
printf("write %x blk %d count %d\n", bp->b_dev, bp->b_blkno, bp->b_bcount);
E 53
I 53
	if (bp->b_bcount > bp->b_bufsize)
		panic("bwrite");
E 53
E 48
E 34
D 45
#endif
E 45
E 16
	(*bdevsw[major(bp->b_dev)].d_strategy)(bp);
I 45

	/*
	 * If the write was synchronous, then await i/o completion.
	 * If the write was "delayed", then we put the buffer on
	 * the q of blocks awaiting i/o completion status.
D 55
	 * Otherwise, the i/o must be finished and we check for
	 * an error.
E 55
	 */
E 45
	if ((flag&B_ASYNC) == 0) {
D 45
		iowait(bp);
E 45
I 45
		biowait(bp);
E 45
		brelse(bp);
	} else if (flag & B_DELWRI)
		bp->b_flags |= B_AGE;
D 55
	else
D 49
		geterror(bp);
E 49
I 49
		u.u_error = geterror(bp);
E 55
E 49
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
D 45
register struct buf *bp;
E 45
I 45
	register struct buf *bp;
E 45
{
D 22
	register struct buf *dp;
E 22
I 22
D 74
D 75
	register int flags;
E 75
E 74
E 22

	if ((bp->b_flags&B_DELWRI) == 0)
D 50
		u.u_vm.vm_oublk++;		/* noone paid yet */
E 50
I 50
		u.u_ru.ru_oublock++;		/* noone paid yet */
E 50
D 22
	dp = bdevsw[major(bp->b_dev)].d_tab;
	if(dp->b_flags & B_TAPE)
E 22
I 22
D 74
D 75
	flags = bdevsw[major(bp->b_dev)].d_flags;
	if(flags & B_TAPE)
E 75
I 75
	if (bdevsw[major(bp->b_dev)].d_flags & B_TAPE)
E 75
E 74
I 74
	if (bdevsw[major(bp->b_dev)].d_flags & B_TAPE)
E 74
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
D 45
register struct buf *bp;
E 45
I 45
	register struct buf *bp;
E 45
{

	bp->b_flags |= B_ASYNC;
	bwrite(bp);
}

/*
D 45
 * release the buffer, with no I/O implied.
E 45
I 45
 * Release the buffer, with no I/O implied.
E 45
 */
brelse(bp)
D 45
register struct buf *bp;
E 45
I 45
	register struct buf *bp;
E 45
{
D 18
	register struct buf **backp;
E 18
I 18
	register struct buf *flist;
E 18
	register s;

I 65
	trace(TR_BRELSE, pack(bp->b_dev, bp->b_bufsize), bp->b_blkno);
E 65
I 45
	/*
	 * If someone's waiting for the buffer, or
	 * is waiting for a buffer wake 'em up.
	 */
E 45
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
I 45

	/*
	 * Stick the buffer back on a free list.
	 */
E 45
E 24
I 2
D 18
	}
E 18
E 2
D 72
	s = spl6();
E 72
I 72
	s = splbio();
E 72
D 18
	if(bp->b_flags & (B_AGE|B_ERROR)) {
		backp = &bfreelist.av_forw;
		(*backp)->av_back = bp;
		bp->av_forw = *backp;
		*backp = bp;
		bp->av_back = &bfreelist;
E 18
I 18
D 53
	if (bp->b_flags & (B_ERROR|B_INVAL)) {
E 53
I 53
	if (bp->b_bufsize <= 0) {
		/* block has no buffer ... put at front of unused buffer list */
		flist = &bfreelist[BQ_EMPTY];
		binsheadfree(bp, flist);
	} else if (bp->b_flags & (B_ERROR|B_INVAL)) {
E 53
		/* block has no info ... put at front of most free list */
D 53
		flist = &bfreelist[BQUEUES-1];
E 53
I 53
		flist = &bfreelist[BQ_AGE];
E 53
D 45
		flist->av_forw->av_back = bp;
		bp->av_forw = flist->av_forw;
		flist->av_forw = bp;
		bp->av_back = flist;
E 45
I 45
		binsheadfree(bp, flist);
E 45
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
D 45
		flist->av_back->av_forw = bp;
		bp->av_back = flist->av_back;
		flist->av_back = bp;
		bp->av_forw = flist;
E 45
I 45
		binstailfree(bp, flist);
E 45
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
D 45
dev_t dev;
daddr_t blkno;
E 45
I 45
	dev_t dev;
	daddr_t blkno;
E 45
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
D 45
		    !(bp->b_flags & B_INVAL))
E 45
I 45
		    (bp->b_flags & B_INVAL) == 0)
E 45
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
I 74
#ifdef SECSIZE
baddr(dev, blkno, size, secsize)
#else SECSIZE
E 74
D 41
baddr(dev, blkno)
dev_t dev;
daddr_t blkno;
E 41
I 41
baddr(dev, blkno, size)
I 74
#endif SECSIZE
E 74
	dev_t dev;
	daddr_t blkno;
	int size;
I 74
#ifdef SECSIZE
	long secsize;
#endif SECSIZE
E 74
E 41
{

	if (incore(dev, blkno))
I 74
#ifdef SECSIZE
		return (bread(dev, blkno, size, secsize));
#else SECSIZE
E 74
D 41
		return (bread(dev, blkno));
E 41
I 41
		return (bread(dev, blkno, size));
I 74
#endif SECSIZE
E 74
E 41
	return (0);
}

/*
 * Assign a buffer for the given block.  If the appropriate
 * block is already associated, return it; otherwise search
 * for the oldest non-busy buffer and reassign it.
I 36
 *
I 76
 * If we find the buffer, but it is dirty (marked DELWRI) and
 * its size is changing, we must write it out first. When the
 * buffer is shrinking, the write is done by brealloc to avoid
 * losing the unwritten data. When the buffer is growing, the
 * write is done by getblk, so that bread will not read stale
 * disk data over the modified data in the buffer.
 *
E 76
 * We use splx here because this routine may be called
 * on the interrupt stack during a dump, and we don't
 * want to lower the ipl back to 0.
E 36
 */
struct buf *
I 74
#ifdef SECSIZE
getblk(dev, blkno, size, secsize)
#else SECSIZE
E 74
D 41
getblk(dev, blkno)
dev_t dev;
daddr_t blkno;
E 41
I 41
getblk(dev, blkno, size)
I 74
#endif SECSIZE
E 74
	dev_t dev;
	daddr_t blkno;
	int size;
I 74
#ifdef SECSIZE
	long secsize;
#endif SECSIZE
E 74
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
D 53
	register struct buf *bp, *dp, *ep;
E 53
I 53
	register struct buf *bp, *dp;
E 53
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
D 45
#ifdef	DISKMON
	register int i;
#endif
E 45
I 36
	int s;
E 36
E 23
E 18
E 15

I 71
	if (size > MAXBSIZE)
		panic("getblk: size too big");
E 71
I 15
D 54
	if ((unsigned)blkno >= 1 << (sizeof(int)*NBBY-PGSHIFT))
E 54
I 54
D 69
	if ((unsigned)blkno >= 1 << (sizeof(int)*NBBY-PGSHIFT))	/* XXX */
E 54
		blkno = 1 << ((sizeof(int)*NBBY-PGSHIFT) + 1);
E 69
I 69
	/*
	 * To prevent overflow of 32-bit ints when converting block
	 * numbers to byte offsets, blknos > 2^32 / DEV_BSIZE are set
	 * to the maximum number that can be converted to a byte offset
	 * without overflow. This is historic code; what bug it fixed,
	 * or whether it is still a reasonable thing to do is open to
	 * dispute. mkm 9/85
	 */
	if ((unsigned)blkno >= 1 << (sizeof(int)*NBBY-DEV_BSHIFT))
		blkno = 1 << ((sizeof(int)*NBBY-DEV_BSHIFT) + 1);
E 69
I 45
	/*
	 * Search the cache for the block.  If we hit, but
	 * the buffer is in use for i/o, then we wait until
	 * the i/o has completed.
	 */
E 45
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
D 45
    loop:
E 45
I 45
loop:
E 45
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
D 72
		s = spl6();
E 72
I 72
		s = splbio();
E 72
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
D 45
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
E 45
		notavail(bp);
I 76
		if (bp->b_bcount != size) {
			if (bp->b_bcount < size && (bp->b_flags&B_DELWRI)) {
				bp->b_flags &= ~B_ASYNC;
				bwrite(bp);
				goto loop;
			}
			if (brealloc(bp, size) == 0)
				goto loop;
		}
E 76
I 41
D 48
		brealloc(bp, size);
E 48
I 48
D 66
		if (brealloc(bp, size) == 0)
E 66
I 66
		if (bp->b_bcount != size && brealloc(bp, size) == 0)
E 66
			goto loop;
E 48
E 41
		bp->b_flags |= B_CACHE;
D 72
		return(bp);
E 72
I 72
		return (bp);
E 72
	}
I 2
D 3
	if (distrust)
	if (oincore(dev, blkno))		/* TEST */
		panic("getblk 2");		/* TEST */
E 3
	if (major(dev) >= nblkdev)
		panic("blkdev");
I 45
D 53
	/*
	 * Not found in the cache, select something from
	 * a free list.  Preference is to LRU list, then AGE list.
	 */
E 45
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
D 45
#ifdef TRACE
E 45
E 30
D 34
	trace(TR_BRELSE, bp->b_dev, dbtofsb(bp->b_blkno));
E 34
I 34
	trace(TR_BRELSE, bp->b_dev, bp->b_blkno);
E 34
D 45
#endif
E 45
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
E 53
I 53
	bp = getnewbuf();
E 53
I 41
	bfree(bp);
E 41
D 45
	bp->b_back->b_forw = bp->b_forw;
	bp->b_forw->b_back = bp->b_back;
	bp->b_forw = dp->b_forw;
	bp->b_back = dp;
	dp->b_forw->b_back = bp;
	dp->b_forw = bp;
E 45
I 45
	bremhash(bp);
	binshash(bp, dp);
E 45
	bp->b_dev = dev;
I 74
#ifdef SECSIZE
	bp->b_blksize = secsize;
#endif SECSIZE
E 74
D 41
	bp->b_blkno = dblkno;
E 41
I 41
	bp->b_blkno = blkno;
I 53
	bp->b_error = 0;
E 53
D 48
	brealloc(bp, size);
E 48
I 48
	if (brealloc(bp, size) == 0)
		goto loop;
E 48
E 41
I 2
D 18
	i = BUFHASH(blkno);
	bp->b_hlink = bufhash[i];
	bufhash[i] = bp - buf;
E 18
E 2
D 72
	return(bp);
E 72
I 72
	return (bp);
E 72
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
D 53
	register struct buf *bp, *dp;
I 37
	int s;
E 53
I 53
	register struct buf *bp, *flist;
E 53
E 37
E 6
E 2

I 71
	if (size > MAXBSIZE)
		panic("geteblk: size too big");
E 71
loop:
D 4
	VOID spl6();
E 4
I 4
D 37
	(void) spl6();
E 37
I 37
D 53
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
D 45
#ifdef TRACE
E 45
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
D 45
#endif
E 45
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
E 53
I 53
	bp = getnewbuf();
	bp->b_flags |= B_INVAL;
E 53
E 18
D 45
	bp->b_back->b_forw = bp->b_forw;
	bp->b_forw->b_back = bp->b_back;
	bp->b_forw = dp->b_forw;
	bp->b_back = dp;
	dp->b_forw->b_back = bp;
	dp->b_forw = bp;
E 45
I 45
	bfree(bp);
	bremhash(bp);
D 53
	binshash(bp, dp);
E 53
I 53
	flist = &bfreelist[BQ_AGE];
	binshash(bp, flist);
E 53
E 45
	bp->b_dev = (dev_t)NODEV;
I 74
#ifdef SECSIZE
	bp->b_blksize = DEV_BSIZE;
#endif SECSIZE
E 74
I 53
	bp->b_error = 0;
E 53
I 41
D 46
	bp->b_bcount = size;
E 46
I 46
D 48
	brealloc(bp, size);
E 48
I 48
	if (brealloc(bp, size) == 0)
		goto loop;
E 48
E 46
E 41
I 2
D 20
	bp->b_hlink = -1;
E 20
E 2
D 72
	return(bp);
E 72
I 72
	return (bp);
E 72
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
I 54
 * If can't get space, buffer is released
E 54
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
D 74
D 75
	 * First need to make sure that all overlaping previous I/O
E 75
I 75
	 * First need to make sure that all overlapping previous I/O
E 75
E 74
I 74
	 * First need to make sure that all overlapping previous I/O
E 74
	 * is dispatched with.
	 */
	if (size == bp->b_bcount)
D 48
		return;
D 46
	if (size < bp->b_bcount) {
		bp->b_bcount = size;
		return;
	}
E 46
I 46
	if (size < bp->b_bcount || bp->b_dev == NODEV)
E 48
I 48
		return (1);
	if (size < bp->b_bcount) { 
		if (bp->b_flags & B_DELWRI) {
			bwrite(bp);
			return (0);
		}
		if (bp->b_flags & B_LOCKED)
			panic("brealloc");
E 48
D 53
		goto allocit;
E 53
I 53
D 54
		allocbuf(bp, size);
		return (1);
E 54
I 54
		return (allocbuf(bp, size));
E 54
E 53
D 48

E 46
	start = bp->b_blkno + (bp->b_bcount / DEV_BSIZE);
	last = bp->b_blkno + (size / DEV_BSIZE) - 1;
	if (bp->b_bcount == 0) {
		start++;
		if (start == last)
			goto allocit;
E 48
	}
I 48
	bp->b_flags &= ~B_DONE;
D 53
	if (bp->b_dev == NODEV)
		goto allocit;
E 53
I 53
D 54
	if (bp->b_dev == NODEV) {
		allocbuf(bp, size);
		return (1);
	}
E 54
I 54
	if (bp->b_dev == NODEV)
		return (allocbuf(bp, size));
E 54
E 53

I 65
	trace(TR_BREALLOC, pack(bp->b_dev, size), bp->b_blkno);
E 65
	/*
	 * Search cache for any buffers that overlap the one that we
	 * are trying to allocate. Overlapping buffers must be marked
	 * invalid, after being written out if they are dirty. (indicated
	 * by B_DELWRI) A disk block must be mapped by at most one buffer
	 * at any point in time. Care must be taken to avoid deadlocking
	 * when two buffer are trying to get the same set of disk blocks.
	 */
	start = bp->b_blkno;
I 74
#ifdef SECSIZE
	last = start + size/bp->b_blksize - 1;
#else SECSIZE
E 74
D 61
	last = start + (size / DEV_BSIZE) - 1;
E 61
I 61
	last = start + btodb(size) - 1;
I 74
#endif SECSIZE
E 74
E 61
E 48
	dp = BUFHASH(bp->b_dev, bp->b_blkno);
loop:
D 45
	(void) spl0();
E 45
	for (ep = dp->b_forw; ep != dp; ep = ep->b_forw) {
D 48
		if (ep->b_blkno < start || ep->b_blkno > last ||
		    ep->b_dev != bp->b_dev || ep->b_flags&B_INVAL)
E 48
I 48
		if (ep == bp || ep->b_dev != bp->b_dev || (ep->b_flags&B_INVAL))
E 48
			continue;
I 48
		/* look for overlap */
		if (ep->b_bcount == 0 || ep->b_blkno > last ||
I 74
#ifdef SECSIZE
		    ep->b_blkno + ep->b_bcount/ep->b_blksize <= start)
#else SECSIZE
E 74
D 61
		    ep->b_blkno + (ep->b_bcount / DEV_BSIZE) <= start)
E 61
I 61
		    ep->b_blkno + btodb(ep->b_bcount) <= start)
I 74
#endif SECSIZE
E 74
E 61
			continue;
D 53
if (bioprintfs)
if (ep->b_flags&B_BUSY)
printf("sleeping on:dev 0x%x, blks %d-%d, flg 0%o allocing dev 0x%x, blks %d-%d, flg 0%o\n",
ep->b_dev, ep->b_blkno, ep->b_blkno + (ep->b_bcount / DEV_BSIZE) - 1,
ep->b_flags, bp->b_dev, start, last, bp->b_flags);
E 53
E 48
D 72
		s = spl6();
E 72
I 72
		s = splbio();
E 72
		if (ep->b_flags&B_BUSY) {
			ep->b_flags |= B_WANTED;
			sleep((caddr_t)ep, PRIBIO+1);
D 45
			splx(s);
E 45
I 45
D 53
			(void) splx(s);
E 53
I 53
			splx(s);
E 53
E 45
			goto loop;
		}
D 45
		(void) spl0();
E 45
I 45
D 53
		(void) splx(s);
E 53
I 53
		splx(s);
E 53
E 45
D 48
		/*
		 * What we would really like to do is kill this
		 * I/O since it is now useless. We cannot do that
		 * so we force it to complete, so that it cannot
		 * over-write our useful data later.
		 */
E 48
I 48
		notavail(ep);
E 48
		if (ep->b_flags & B_DELWRI) {
D 48
			notavail(ep);
			ep->b_flags |= B_ASYNC;
E 48
I 48
D 53
if (bioprintfs)
printf("DELWRI:dev 0x%x, blks %d-%d, flg 0%o allocing dev 0x%x, blks %d-%d, flg 0%o\n",
ep->b_dev, ep->b_blkno, ep->b_blkno + (ep->b_bcount / DEV_BSIZE) - 1,
ep->b_flags, bp->b_dev, start, last, bp->b_flags);
E 53
E 48
			bwrite(ep);
			goto loop;
		}
I 48
		ep->b_flags |= B_INVAL;
		brelse(ep);
E 48
	}
D 53
allocit:
E 53
I 53
D 54
	allocbuf(bp, size);
	return (1);
E 54
I 54
	return (allocbuf(bp, size));
E 54
}

/*
D 62
 * Expand or contract the actual memory allocated to a buffer.
I 54
 * If no memory is available, release buffer and take error exit
E 54
 */
allocbuf(tp, size)
	register struct buf *tp;
	int size;
{
	register struct buf *bp, *ep;
	int sizealloc, take;
I 54
#ifdef sun
	register char *a;
	int osize;
#endif
E 54

I 54
#ifndef sun
E 54
	sizealloc = roundup(size, CLBYTES);
I 54
#else
	sizealloc = roundup(size, BUFALLOCSIZE);
#endif
E 54
E 53
	/*
D 53
	 * Here the buffer is already available, so all we
	 * need to do is set the size. Someday a better memory
	 * management scheme will be implemented.
E 53
I 53
	 * Buffer size does not change
E 53
	 */
D 53
	bp->b_bcount = size;
I 48
	return (1);
E 53
I 53
	if (sizealloc == tp->b_bufsize)
		goto out;
I 54
#ifndef sun
E 54
	/*
	 * Buffer size is shrinking.
	 * Place excess space in a buffer header taken from the
	 * BQ_EMPTY buffer list and placed on the "most free" list.
	 * If no extra buffer headers are available, leave the
	 * extra space in the present buffer.
	 */
	if (sizealloc < tp->b_bufsize) {
		ep = bfreelist[BQ_EMPTY].av_forw;
		if (ep == &bfreelist[BQ_EMPTY])
			goto out;
		notavail(ep);
		pagemove(tp->b_un.b_addr + sizealloc, ep->b_un.b_addr,
		    (int)tp->b_bufsize - sizealloc);
		ep->b_bufsize = tp->b_bufsize - sizealloc;
		tp->b_bufsize = sizealloc;
		ep->b_flags |= B_INVAL;
		ep->b_bcount = 0;
		brelse(ep);
		goto out;
	}
	/*
	 * More buffer space is needed. Get it out of buffers on
	 * the "most free" list, placing the empty headers on the
	 * BQ_EMPTY buffer header list.
	 */
	while (tp->b_bufsize < sizealloc) {
		take = sizealloc - tp->b_bufsize;
		bp = getnewbuf();
		if (take >= bp->b_bufsize)
			take = bp->b_bufsize;
		pagemove(&bp->b_un.b_addr[bp->b_bufsize - take],
		    &tp->b_un.b_addr[tp->b_bufsize], take);
		tp->b_bufsize += take;
		bp->b_bufsize = bp->b_bufsize - take;
		if (bp->b_bcount > bp->b_bufsize)
			bp->b_bcount = bp->b_bufsize;
		if (bp->b_bufsize <= 0) {
			bremhash(bp);
			binshash(bp, &bfreelist[BQ_EMPTY]);
			bp->b_dev = (dev_t)NODEV;
			bp->b_error = 0;
			bp->b_flags |= B_INVAL;
		}
		brelse(bp);
	}
I 54
#else
	/*
	 * Buffer size is shrinking
	 * Just put the tail end back in the map
	 */
	if (sizealloc < tp->b_bufsize) {
		rmfree(buffermap, (long)(tp->b_bufsize - sizealloc),
			(long)(tp->b_un.b_addr + sizealloc));
		tp->b_bufsize = sizealloc;
		goto out;
	}
	/*
	 * Buffer is being expanded or created
	 * If being expanded, attempt to get contiguous
	 * section, otherwise get a new chunk and copy.
	 * If no space, free up a buffer on the AGE list
	 * and try again.
	 */
	do {
		if ((osize = tp->b_bufsize)) {
			a = (char *)rmget(buffermap, (long)(sizealloc-osize),
				(long)(tp->b_un.b_addr + osize));
			if (a == 0) {
				a = (char *)rmalloc(buffermap, (long)sizealloc);
				if (a != 0) {
					bcopy(tp->b_un.b_addr, a, osize);
					rmfree(buffermap, (long)osize,
						(long)tp->b_un.b_addr);
					tp->b_un.b_addr = a;
				}
			}
		} else {
			a = (char *)rmalloc(buffermap, (long)sizealloc);
			if (a != 0)
				tp->b_un.b_addr = a;
		}
	} while (a == 0 && bfreemem());
	if (a == 0) {
		brelse(tp);
		return (0);
	}
	tp->b_bufsize = sizealloc;
#endif
E 54
out:
	tp->b_bcount = size;
I 54
	return (1);
E 54
E 53
E 48
}

/*
 * Release space associated with a buffer.
 */
bfree(bp)
	struct buf *bp;
{
D 54
	/*
D 53
	 * Here the buffer does not change, so all we
	 * need to do is set the size. Someday a better memory
	 * management scheme will be implemented.
E 53
I 53
	 * This stub is provided to allow the system to reclaim
	 * memory from the buffer pool. Currently we do not migrate
	 * memory between the buffer memory pool and the user memory
	 * pool.
E 53
	 */
E 54
I 54
#ifdef sun
	if (bp->b_bufsize) {
		rmfree(buffermap, (long)bp->b_bufsize, (long)bp->b_un.b_addr);
		bp->b_bufsize = 0;
	}
#endif
E 54
	bp->b_bcount = 0;
}

I 54
#ifdef sun
E 54
/*
I 54
 * Attempt to free up buffer space by flushing
 * something in the free list.
 * Don't wait for something, that could cause deadlocks
 * We start with BQ_AGE because we know BQ_EMPTY take no memory.
 */
bfreemem()
{
	register struct buf *bp, *dp;
	int s;

loop:
	s = spl6();
	for (dp = &bfreelist[BQ_AGE]; dp > bfreelist; dp--)
		if (dp->av_forw != dp)
			break;
	splx(s);
	if (dp == bfreelist) {		/* no free blocks */
		return (0);
	}
	bp = dp->av_forw;
	notavail(bp);
	if (bp->b_flags & B_DELWRI) {
		bp->b_flags |= B_ASYNC;
		bwrite(bp);
		goto loop;
	}
	trace(TR_BRELSE, bp->b_dev, bp->b_blkno);
	bp->b_flags = B_BUSY | B_INVAL;
	bfree(bp);
	bremhash(bp);
	binshash(bp, &bfreelist[BQ_EMPTY]);
	bp->b_dev = (dev_t)NODEV;
	bp->b_error = 0;
	brelse(bp);
	return (1);
}
#endif

/*
E 62
E 54
I 53
 * Find a buffer which is available for use.
 * Select something from a free list.
 * Preference is to AGE list, then LRU list.
 */
struct buf *
getnewbuf()
{
	register struct buf *bp, *dp;
	int s;

loop:
D 72
	s = spl6();
E 72
I 72
	s = splbio();
E 72
I 54
D 63
#ifndef sun
E 63
E 54
	for (dp = &bfreelist[BQ_AGE]; dp > bfreelist; dp--)
I 54
D 63
#else
	for (dp = &bfreelist[BQ_EMPTY]; dp > bfreelist; dp--)
#endif
E 63
E 54
		if (dp->av_forw != dp)
			break;
	if (dp == bfreelist) {		/* no free blocks */
		dp->b_flags |= B_WANTED;
		sleep((caddr_t)dp, PRIBIO+1);
I 57
		splx(s);
E 57
		goto loop;
	}
	splx(s);
	bp = dp->av_forw;
	notavail(bp);
	if (bp->b_flags & B_DELWRI) {
		bp->b_flags |= B_ASYNC;
		bwrite(bp);
		goto loop;
	}
D 65
	trace(TR_BRELSE, bp->b_dev, bp->b_blkno);
E 65
I 65
	trace(TR_BRELSE, pack(bp->b_dev, bp->b_bufsize), bp->b_blkno);
E 65
	bp->b_flags = B_BUSY;
	return (bp);
}

/*
E 53
E 41
 * Wait for I/O completion on the buffer; return errors
 * to the user.
 */
D 45
iowait(bp)
E 45
I 45
biowait(bp)
E 45
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
D 72
	s = spl6();
E 72
I 72
	s = splbio();
E 72
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
D 49
	geterror(bp);
E 49
I 49
D 56
	u.u_error = geterror(bp);
E 56
I 56
	if (u.u_error == 0)			/* XXX */
		u.u_error = geterror(bp);
E 56
E 49
}

D 25
#ifndef FASTVAX
E 25
I 25
D 45
#ifdef UNFAST
E 45
E 25
/*
D 45
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
E 45
D 62
 * Mark I/O complete on a buffer. If the header
 * indicates a dirty page push completion, the
 * header is inserted into the ``cleaned'' list
 * to be processed by the pageout daemon. Otherwise
 * release it if I/O is asynchronous, and wake 
 * up anyone waiting for it.
E 62
I 62
 * Mark I/O complete on a buffer.
 * If someone should be called, e.g. the pageout
 * daemon, do so.  Otherwise, wake up anyone
 * waiting for it.
E 62
 */
D 45
iodone(bp)
register struct buf *bp;
E 45
I 45
biodone(bp)
	register struct buf *bp;
E 45
{
D 60
	register int s;
E 60

I 10
	if (bp->b_flags & B_DONE)
D 45
		panic("dup iodone");
E 45
I 45
		panic("dup biodone");
E 45
E 10
	bp->b_flags |= B_DONE;
D 60
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
I 54
		return;
	}
E 60
	if (bp->b_flags & B_CALL) {
		bp->b_flags &= ~B_CALL;
		(*bp->b_iodone)(bp);
E 54
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
I 53
 * Insure that no part of a specified block is in an incore buffer.
I 75
#ifdef SECSIZE
 * "size" is given in device blocks (the units of b_blkno).
#endif SECSIZE
E 75
I 74
#ifdef SECSIZE
 * "size" is given in device blocks (the units of b_blkno).
#endif SECSIZE
E 74
 */
blkflush(dev, blkno, size)
	dev_t dev;
	daddr_t blkno;
I 74
#ifdef SECSIZE
	int size;
#else SECSIZE
E 74
	long size;
I 74
#endif SECSIZE
E 74
{
	register struct buf *ep;
	struct buf *dp;
	daddr_t start, last;
	int s;

	start = blkno;
I 74
#ifdef SECSIZE
	last = start + size - 1;
#else SECSIZE
E 74
D 61
	last = start + (size / DEV_BSIZE) - 1;
E 61
I 61
	last = start + btodb(size) - 1;
I 74
#endif SECSIZE
E 74
E 61
	dp = BUFHASH(dev, blkno);
loop:
	for (ep = dp->b_forw; ep != dp; ep = ep->b_forw) {
		if (ep->b_dev != dev || (ep->b_flags&B_INVAL))
			continue;
		/* look for overlap */
		if (ep->b_bcount == 0 || ep->b_blkno > last ||
I 74
#ifdef SECSIZE
		    ep->b_blkno + ep->b_bcount / ep->b_blksize <= start)
#else SECSIZE
E 74
D 61
		    ep->b_blkno + (ep->b_bcount / DEV_BSIZE) <= start)
E 61
I 61
		    ep->b_blkno + btodb(ep->b_bcount) <= start)
I 74
#endif SECSIZE
E 74
E 61
			continue;
D 72
		s = spl6();
E 72
I 72
		s = splbio();
E 72
		if (ep->b_flags&B_BUSY) {
			ep->b_flags |= B_WANTED;
			sleep((caddr_t)ep, PRIBIO+1);
			splx(s);
			goto loop;
		}
		if (ep->b_flags & B_DELWRI) {
			splx(s);
			notavail(ep);
			bwrite(ep);
			goto loop;
		}
		splx(s);
	}
}

/*
E 53
D 45
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
E 45
D 43
 * swap I/O -
 *
 * If the flag indicates a dirty page push initiated
 * by the pageout daemon, we map the page into the i th
 * virtual page of process 2 (the daemon itself) where i is
 * the index of the swap header that has been allocated.
 * We simply initialize the header and queue the I/O but
 * do not wait for completion. When the I/O completes,
 * iodone() will link the header to a list of cleaned
 * pages to be processed by the pageout daemon.
 */
swap(p, dblkno, addr, nbytes, rdflg, flag, dev, pfcent)
	struct proc *p;
	swblk_t dblkno;
	caddr_t addr;
	int flag, nbytes;
	dev_t dev;
	unsigned pfcent;
{
	register struct buf *bp;
	register int c;
	int p2dp;
	register struct pte *dpte, *vpte;
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

	bp->b_flags = B_BUSY | B_PHYS | rdflg | flag;
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
		bp->b_un.b_addr = (caddr_t)ctob(p2dp);
	} else
		bp->b_un.b_addr = addr;
	while (nbytes > 0) {
		c = imin(ctob(120), nbytes);
		bp->b_bcount = c;
		bp->b_blkno = dblkno;
		bp->b_dev = dev;
I 11
		if (flag & B_DIRTY) {
			swpf[bp - swbuf] = pfcent;
			swsize[bp - swbuf] = nbytes;
		}
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
		(*bdevsw[major(dev)].d_strategy)(bp);
		if (flag & B_DIRTY) {
			if (c < nbytes)
				panic("big push");
D 11
			swsize[bp - swbuf] = nbytes;
			swpf[bp - swbuf] = pfcent;
E 11
			return;
		}
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
E 37
E 4
		bp->b_un.b_addr += c;
		bp->b_flags &= ~B_DONE;
		if (bp->b_flags & B_ERROR) {
			if ((flag & (B_UAREA|B_PAGET)) || rdflg == B_WRITE)
				panic("hard IO err in swap");
			swkill(p, (char *)0);
		}
		nbytes -= c;
		dblkno += btoc(c);
	}
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
	bp->b_flags &= ~(B_BUSY|B_WANTED|B_PHYS|B_PAGET|B_UAREA|B_DIRTY);
	bp->av_forw = bswlist.av_forw;
	bswlist.av_forw = bp;
	if (bswlist.b_flags & B_WANTED) {
		bswlist.b_flags &= ~B_WANTED;
		wakeup((caddr_t)&bswlist);
		wakeup((caddr_t)&proc[2]);
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
 * If rout == 0 then killed on swap error, else
 * rout is the name of the routine where we ran out of
 * swap space.
 */
swkill(p, rout)
	struct proc *p;
	char *rout;
{
I 27
	char *mesg;
E 27

D 27
	printf("%d: ", p->p_pid);
E 27
I 27
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
E 43
D 62
 * make sure all write-behind blocks
E 62
I 62
 * Make sure all write-behind blocks
E 62
 * on dev (or NODEV for all)
 * are flushed out.
 * (from umount and update)
I 41
D 62
 * (and temporarily pagein)
E 62
E 41
 */
bflush(dev)
D 45
dev_t dev;
E 45
I 45
	dev_t dev;
E 45
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
D 72
	s = spl6();
E 72
I 72
	s = splbio();
E 72
E 37
E 4
D 18
	for (bp = bfreelist.av_forw; bp != &bfreelist; bp = bp->av_forw) {
E 18
I 18
D 53
	for (flist = bfreelist; flist < &bfreelist[BQUEUES]; flist++)
E 53
I 53
	for (flist = bfreelist; flist < &bfreelist[BQ_EMPTY]; flist++)
E 53
	for (bp = flist->av_forw; bp != flist; bp = bp->av_forw) {
E 18
D 45
		if (bp->b_flags&B_DELWRI && (dev == NODEV||dev==bp->b_dev)) {
E 45
I 45
		if ((bp->b_flags & B_DELWRI) == 0)
			continue;
		if (dev == NODEV || dev == bp->b_dev) {
E 45
			bp->b_flags |= B_ASYNC;
			notavail(bp);
			bwrite(bp);
I 58
			splx(s);
E 58
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
D 43

/*
 * Raw I/O. The arguments are
 *	The strategy routine for the device
 *	A buffer, which will always be a special buffer
 *	  header owned exclusively by the device for this purpose
 *	The device number
 *	Read/write flag
 * Essentially all the work is computing physical addresses and
 * validating them.
 * If the user has the proper access privilidges, the process is
 * marked 'delayed unlock' and the pages involved in the I/O are
 * faulted and locked. After the completion of the I/O, the above pages
 * are unlocked.
 */
physio(strat, bp, dev, rw, mincnt)
int (*strat)(); 
register struct buf *bp;
unsigned (*mincnt)();
{
	register int c;
	char *a;
I 37
	int s;
E 37

	if (useracc(u.u_base,u.u_count,rw==B_READ?B_WRITE:B_READ) == NULL) {
		u.u_error = EFAULT;
		return;
	}
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
	while (bp->b_flags&B_BUSY) {
		bp->b_flags |= B_WANTED;
		sleep((caddr_t)bp, PRIBIO+1);
	}
I 39
	splx(s);
E 39
	bp->b_error = 0;
	bp->b_proc = u.u_procp;
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
E 33
E 31
		bp->b_flags = B_BUSY | B_PHYS | rw;
		bp->b_dev = dev;
		bp->b_blkno = u.u_offset >> PGSHIFT;
		bp->b_bcount = u.u_count;
		(*mincnt)(bp);
		c = bp->b_bcount;
		u.u_procp->p_flag |= SPHYSIO;
		vslock(a = bp->b_un.b_addr, c);
		(*strat)(bp);
D 4
		VOID spl6();
E 4
I 4
		(void) spl6();
E 4
		while ((bp->b_flags&B_DONE) == 0)
			sleep((caddr_t)bp, PRIBIO);
		vsunlock(a, c, rw);
		u.u_procp->p_flag &= ~SPHYSIO;
		if (bp->b_flags&B_WANTED)
			wakeup((caddr_t)bp);
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
		bp->b_un.b_addr += c;
		u.u_count -= c;
		u.u_offset += c;
I 33
		if (bp->b_flags&B_ERROR)
			break;
E 33
	}
	bp->b_flags &= ~(B_BUSY|B_WANTED|B_PHYS);
	u.u_count = bp->b_resid;
	geterror(bp);
}

/*ARGSUSED*/
unsigned
minphys(bp)
struct buf *bp;
{

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
	if (bp->b_bcount > 63 * 1024)
		bp->b_bcount = 63 * 1024;
E 40
E 39
}
I 41

E 43
E 41

/*
 * Pick up the device's error number and pass it to the user;
D 70
 * if there is an error but the number is 0 set a generalized
 * code.  Actually the latter is always true because devices
 * don't yet return specific errors.
E 70
I 70
 * if there is an error but the number is 0 set a generalized code.
E 70
 */
geterror(bp)
D 45
register struct buf *bp;
E 45
I 45
	register struct buf *bp;
E 45
{
I 49
	int error = 0;
E 49

	if (bp->b_flags&B_ERROR)
D 49
		if ((u.u_error = bp->b_error)==0)
			u.u_error = EIO;
E 49
I 49
		if ((error = bp->b_error)==0)
			return (EIO);
	return (error);
E 49
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
D 45
dev_t dev;
E 45
I 45
	dev_t dev;
E 45
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
E 1
