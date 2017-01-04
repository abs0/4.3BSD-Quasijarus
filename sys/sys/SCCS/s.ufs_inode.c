h17563
s 00008/00008/00682
d D 7.5 87/06/21 15:46:00 mckusick 66 65
c geteblk => malloc for copy of indirect pointers
e
s 00001/00001/00689
d D 7.4 87/06/21 15:30:44 mckusick 65 64
c geteblk => malloc, so m_bufp => m_fs as it should be
e
s 00004/00004/00686
d D 7.3 87/06/05 00:05:35 mckusick 64 63
c change free() to blkfree() to allow for malloc()/free()
e
s 00014/00029/00676
d D 7.2 87/04/02 15:49:19 karels 63 61
c working with pack labels
e
s 00033/00029/00676
d D 7.1.1.1 87/04/02 15:41:14 karels 62 61
c add ifdefs for dev_bsize (almost working)
e
s 00001/00001/00704
d D 7.1 86/06/05 00:12:57 mckusick 61 60
c 4.3BSD release version
e
s 00003/00003/00702
d D 6.19 86/02/23 23:11:12 karels 60 59
c lint
e
s 00003/00004/00702
d D 6.18 86/02/20 15:19:56 karels 59 58
c lint and cleanups from Sam
e
s 00006/00005/00700
d D 6.17 85/09/04 13:32:23 bloom 58 57
c lint cleanup
e
s 00007/00001/00698
d D 6.16 85/06/08 14:51:52 mckusick 57 56
c Add copyright
e
s 00002/00002/00697
d D 6.15 85/03/20 11:14:34 mckusick 56 55
c don't try to truncate inodes on read-only file systems (from sun!shannon)
e
s 00000/00001/00699
d D 6.14 85/03/19 20:49:17 mckusick 55 54
c eliminate extraneous include of conf.h
e
s 00001/00001/00699
d D 6.13 85/03/13 20:15:03 mckusick 54 53
c don't try to truncate inodes on read-only file systems (from sun!shannon)
e
s 00047/00010/00653
d D 6.12 85/02/11 17:11:09 mckusick 53 52
c must zero out unused portion of partial blocks when truncating files
e
s 00011/00011/00652
d D 6.11 84/08/29 20:26:02 bloom 52 51
c Change to includes.  no more ../h
e
s 00001/00001/00662
d D 6.10 84/08/03 20:34:27 mckusick 51 50
c increase size of hash table header to reduce collisions
e
s 00001/00009/00662
d D 6.9 84/07/20 01:13:07 mckusick 50 49
c use new `cacheinval' macro
e
s 00005/00003/00666
d D 6.8 84/07/15 11:54:57 karels 49 48
c iget must lock old inode before dqrele()
e
s 00002/00002/00667
d D 6.7 84/07/04 13:22:34 mckusick 48 47
c save time, use ILOCK and IUNLOCK to avoid call overhead
e
s 00006/00003/00663
d D 6.6 84/07/02 15:22:43 mckusick 47 46
c eliminate unnecessary panic when id's wrap
e
s 00044/00000/00622
d D 6.5 84/06/27 20:40:14 sam 46 45
c convert namei cache to hold soft references to inodes so that 
c . and .. may be placed in the cache
e
s 00001/00003/00621
d D 6.4 84/05/22 11:18:26 karels 45 44
c remove paranoid test; make hashsize a power of two (avoid unsigned
c modulo)
e
s 00004/00008/00620
d D 6.3 84/02/15 21:13:49 karels 44 43
c use ITIME in irele to update times in irele without write to disk
e
s 00005/00000/00623
d D 6.2 84/02/07 17:36:54 karels 43 42
c force iupdate from irele if count still > 0,
c avoiding delayed updates from namei cache
e
s 00000/00000/00623
d D 6.1 83/07/29 06:42:24 sam 42 41
c 4.2 distribution
e
s 00004/00001/00619
d D 4.36 83/06/11 00:49:10 sam 41 40
c update inode time stamps when no work so touch works
e
s 00014/00041/00606
d D 4.35 83/05/21 15:45:12 sam 40 39
c indirtrunc always returns blocks released for use with i_blocks; 
c macro-ized to eliminate DEV_BSHIFT
e
s 00002/00000/00645
d D 4.34 83/03/15 09:50:21 sam 39 38
c botched non-QUOTA code (from kre)
e
s 00001/00001/00644
d D 4.33 83/02/10 16:05:57 sam 38 37
c guard against negative mod parameters
e
s 00131/00140/00514
d D 4.32 83/02/05 17:14:17 sam 37 36
c rewrite itrunc and indirtrunc to work (and handle triple indirect 
c blocks as well)
e
s 00183/00076/00471
d D 4.31 82/11/13 22:52:57 sam 36 35
c merge of 4.1b and 4.1c
e
s 00004/00002/00543
d D 4.30 82/10/23 10:26:56 root 35 34
c missing declaration of size
e
s 00002/00005/00543
d D 4.29 82/10/19 10:32:18 root 34 33
c more lint
e
s 00007/00007/00541
d D 4.28 82/10/17 21:51:22 root 33 32
c more lint
e
s 00004/00003/00544
d D 4.27 82/10/17 20:55:12 root 32 31
c lint
e
s 00003/00004/00544
d D 4.26 82/10/17 14:06:34 root 31 30
c fix lint
e
s 00007/00022/00541
d D 4.25 82/10/10 16:02:38 root 30 29
c move vax header files to their own directory
e
s 00004/00003/00559
d D 4.24 82/09/06 22:57:37 root 29 28
c 
e
s 00010/00007/00552
d D 4.23 82/08/10 17:52:17 sam 28 27
c new fs system calls prior to truncate and rename
e
s 00018/00018/00541
d D 4.22 82/08/03 14:02:38 sam 27 26
c cosmetics
e
s 00007/00017/00552
d D 4.21 82/07/30 10:58:39 sam 26 25
c rewrite of nami + reorganization of wdir
e
s 00005/00156/00564
d D 4.20 82/07/25 23:14:46 root 25 24
c pull maknode and wdir to ufs_nami.c
e
s 00026/00004/00694
d D 4.19 82/07/24 18:12:11 root 24 23
c merge with calder
e
s 00079/00006/00619
d D 4.18 82/07/22 18:46:19 kre 23 22
c disc quotas
e
s 00001/00000/00624
d D 4.17 82/07/03 16:56:57 kre 22 21
c complete fix of 4.15 (clear i_rdev in real inode before
c second iupdate - otherwise all the good work is undone)
c 4.15 is probably not really needed (does no real good).
e
s 00002/00000/00622
d D 4.16 82/07/01 21:07:30 kre 21 20
c replace 2 lines accidentally dropped in 4.13
e
s 00007/00003/00615
d D 4.15 82/07/01 01:17:55 root 20 19
c clear dino on disk in itrunc in all cases
e
s 00007/00028/00611
d D 4.14 82/06/30 06:25:24 kre 19 18
c remove insque/remque asm's in favour of macros
c (it doesn't work without this, register numbers are wrong)
e
s 00186/00044/00453
d D 4.13 82/06/29 23:03:03 kre 18 17
c inode LRU cache added (from Chris Maltby, Sydney Uni)
e
s 00000/00004/00497
d D 4.12 82/06/10 12:40:54 mckusick 17 16
c change iput() to irele() when releasing unlocked inodes
e
s 00017/00006/00484
d D 4.11 82/06/07 23:52:27 mckusick 16 15
c irele() becomes iunlock(); new irele() does iput() for already unlocked inodes
c fixes race condition in adding entries to directories.
e
s 00165/00118/00325
d D 4.10 82/04/19 19:35:35 mckusic 15 14
c merge into new file system
e
s 00001/00001/00442
d D 4.9 82/02/27 14:54:28 wnj 14 13
c symbolic links
e
s 00001/00001/00442
d D 4.8 82/02/15 13:28:23 wnj 13 12
c new multiple-group stuff
e
s 00047/00053/00396
d D 4.7 81/11/08 16:49:04 wnj 12 11
c plock/prele -> ilock/irele
e
s 00001/00002/00448
d D 4.6 81/10/11 13:02:12 wnj 11 10
c first bootable version
e
s 00038/00000/00412
d D 4.5 81/04/28 02:53:14 root 10 9
c plock/prele here now
e
s 00001/00001/00411
d D 4.4 81/03/09 01:47:05 wnj 9 8
c lint and a few minor fixed
e
s 00001/00003/00411
d D 4.3 81/03/06 11:37:13 wnj 8 7
c use tablefull()
e
s 00004/00003/00410
d D 4.2 81/02/26 23:29:19 wnj 7 6
c rid of NINODE
e
s 00000/00000/00413
d D 4.1 80/11/09 17:31:58 bill 6 5
c minor fixups to restart stuff; version 4.1 for distrib
e
s 00037/00004/00376
d D 3.5 80/10/03 10:45:14 bill 5 4
c file system update orderings
e
s 00000/00000/00380
d D 3.4 80/07/08 00:39:06 bill 4 3
c trivial
e
s 00001/00001/00379
d D 3.3 80/06/07 02:45:57 bill 3 2
c %H%->%G%
e
s 00001/00001/00379
d D 3.2 80/04/13 12:37:04 bill 2 1
c IUPDAT
e
s 00380/00000/00000
d D 3.1 80/04/09 16:03:20 bill 1 0
c date and time created 80/04/09 16:03:20 by bill
e
u
U
f b 
t
T
I 1
D 3
/*	%M%	%I%	%H%	*/
E 3
I 3
D 9
/*	%M%	%I%	%G%	*/
E 9
I 9
D 57
/*	%M%	%I%	%E%	*/
E 57
I 57
/*
D 61
 * Copyright (c) 1982 Regents of the University of California.
E 61
I 61
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 61
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 57
E 9
E 3

I 15
D 17
/* merged into kernel:	@(#)iget.c 2.2 4/8/82 */

E 17
E 15
D 52
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/mount.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/inode.h"
D 15
#include "../h/ino.h"
#include "../h/filsys.h"
E 15
I 15
#include "../h/fs.h"
E 15
#include "../h/conf.h"
#include "../h/buf.h"
E 52
I 52
#include "param.h"
#include "systm.h"
#include "mount.h"
#include "dir.h"
#include "user.h"
#include "inode.h"
#include "fs.h"
D 55
#include "conf.h"
E 55
#include "buf.h"
I 58
#include "cmap.h"
E 58
E 52
D 30
#include "../h/inline.h"
E 30
I 24
D 27
#ifdef	QUOTA
E 27
I 27
#ifdef QUOTA
E 27
D 52
#include "../h/quota.h"
E 52
I 52
#include "quota.h"
E 52
#endif
I 29
D 52
#include "../h/kernel.h"
E 52
I 52
#include "kernel.h"
I 66
#include "malloc.h"
E 66
E 52
E 29
E 24

D 45
#define	INOHSZ	63
E 45
I 45
D 51
#define	INOHSZ	64
E 51
I 51
#define	INOHSZ	512
E 51
E 45
I 18
#if	((INOHSZ&(INOHSZ-1)) == 0)
#define	INOHASH(dev,ino)	(((dev)+(ino))&(INOHSZ-1))
#else
E 18
D 38
#define	INOHASH(dev,ino)	(((dev)+(ino))%INOHSZ)
E 38
I 38
#define	INOHASH(dev,ino)	(((unsigned)((dev)+(ino)))%INOHSZ)
E 38
D 18
short	inohash[INOHSZ];
short	ifreel;
E 18
I 18
#endif
E 18

I 18
union ihead {				/* inode LRU cache, Chris Maltby */
	union  ihead *ih_head[2];
	struct inode *ih_chain[2];
} ihead[INOHSZ];

struct inode *ifreeh, **ifreet;

E 18
/*
 * Initialize hash links for inodes
 * and build inode free list.
 */
ihinit()
{
	register int i;
I 7
	register struct inode *ip = inode;
I 18
	register union  ihead *ih = ihead;
E 18
E 7

D 18
	ifreel = 0;
D 7
	for (i = 0; i < NINODE - 1; i++)
		inode[i].i_hlink = i+1;
	inode[NINODE - 1].i_hlink = -1;
E 7
I 7
	for (i = 0; i < ninode-1; i++, ip++)
		ip->i_hlink = i+1;
	ip->i_hlink = -1;
E 7
	for (i = 0; i < INOHSZ; i++)
		inohash[i] = -1;
E 18
I 18
	for (i = INOHSZ; --i >= 0; ih++) {
		ih->ih_head[0] = ih;
		ih->ih_head[1] = ih;
	}
	ifreeh = ip;
	ifreet = &ip->i_freef;
	ip->i_freeb = &ifreeh;
	ip->i_forw = ip;
	ip->i_back = ip;
	for (i = ninode; --i > 0; ) {
		++ip;
		ip->i_forw = ip;
		ip->i_back = ip;
		*ifreet = ip;
		ip->i_freeb = ifreet;
		ifreet = &ip->i_freef;
	}
	ip->i_freef = NULL;
E 18
}

I 18
#ifdef notdef
E 18
/*
I 18
 * Find an inode if it is incore.
 * This is the equivalent, for inodes,
 * of ``incore'' in bio.c or ``pfind'' in subr.c.
 */
struct inode *
ifind(dev, ino)
	dev_t dev;
	ino_t ino;
{
	register struct inode *ip;
	register union  ihead *ih;

	ih = &ihead[INOHASH(dev, ino)];
	for (ip = ih->ih_chain[0]; ip != (struct inode *)ih; ip = ip->i_forw)
		if (ino==ip->i_number && dev==ip->i_dev)
			return (ip);
	return ((struct inode *)0);
}
#endif notdef

/*
E 18
D 15
 * Find an inode if it is incore.
 * This is the equivalent, for inodes,
 * of ``incore'' in bio.c or ``pfind'' in subr.c.
 */
struct inode *
ifind(dev, ino)
D 12
dev_t dev;
ino_t ino;
E 12
I 12
	dev_t dev;
	ino_t ino;
E 12
{
	register struct inode *ip;

	for (ip = &inode[inohash[INOHASH(dev,ino)]]; ip != &inode[-1];
	    ip = &inode[ip->i_hlink])
		if (ino==ip->i_number && dev==ip->i_dev)
			return (ip);
	return ((struct inode *)0);
}

/*
E 15
 * Look up an inode by device,inumber.
 * If it is in core (in the inode structure),
 * honor the locking protocol.
 * If it is not in core, read it in from the
 * specified device.
 * If the inode is mounted on, perform
 * the indicated indirection.
 * In all cases, a pointer to a locked
 * inode structure is returned.
 *
D 8
 * printf warning: no inodes -- if the inode
 *	structure is full
E 8
 * panic: no imt -- if the mounted file
 *	system is not in the mount table.
 *	"cannot happen"
 */
struct inode *
D 15
iget(dev, ino)
E 15
I 15
iget(dev, fs, ino)
E 15
D 12
dev_t dev;
ino_t ino;
E 12
I 12
	dev_t dev;
I 15
	register struct fs *fs;
E 15
	ino_t ino;
E 12
{
D 18
	register struct inode *ip;
E 18
I 18
D 19
	register struct inode *ip;	/* known to be r11 - see "asm" below */
	register union  ihead *ih;	/* known to be r10 - see "asm" below */
E 19
I 19
	register struct inode *ip;
	register union  ihead *ih;
E 19
E 18
	register struct mount *mp;
	register struct buf *bp;
	register struct dinode *dp;
D 18
	register int slot;
E 18
I 18
	register struct inode *iq;
I 47
D 50
	struct inode *xp;
E 50
E 47
E 18

I 47
D 59

E 59
E 47
loop:
I 15
D 45
	if (getfs(dev) != fs)
		panic("iget: bad fs");
E 45
E 15
D 18
	slot = INOHASH(dev, ino);
	ip = &inode[inohash[slot]];
	while (ip != &inode[-1]) {
E 18
I 18
	ih = &ihead[INOHASH(dev, ino)];
	for (ip = ih->ih_chain[0]; ip != (struct inode *)ih; ip = ip->i_forw)
E 18
D 12
		if(ino == ip->i_number && dev == ip->i_dev) {
			if((ip->i_flag&ILOCK) != 0) {
E 12
I 12
		if (ino == ip->i_number && dev == ip->i_dev) {
I 46
			/*
			 * Following is essentially an inline expanded
			 * copy of igrab(), expanded inline for speed,
			 * and so that the test for a mounted on inode
			 * can be deferred until after we are sure that
			 * the inode isn't busy.
			 */
E 46
D 30
			if ((ip->i_flag&ILOCK) != 0) {
E 30
I 30
			if ((ip->i_flag&ILOCKED) != 0) {
E 30
E 12
				ip->i_flag |= IWANT;
				sleep((caddr_t)ip, PINOD);
				goto loop;
			}
D 12
			if((ip->i_flag&IMOUNT) != 0) {
E 12
I 12
			if ((ip->i_flag&IMOUNT) != 0) {
E 12
D 15
				for(mp = &mount[0]; mp < &mount[NMOUNT]; mp++)
E 15
I 15
				for (mp = &mount[0]; mp < &mount[NMOUNT]; mp++)
E 15
D 12
				if(mp->m_inodp == ip) {
E 12
I 12
D 18
				if (mp->m_inodp == ip) {
E 12
					dev = mp->m_dev;
I 15
					fs = mp->m_bufp->b_un.b_fs;
E 15
					ino = ROOTINO;
					goto loop;
				}
E 18
I 18
					if(mp->m_inodp == ip) {
						dev = mp->m_dev;
D 65
						fs = mp->m_bufp->b_un.b_fs;
E 65
I 65
						fs = mp->m_fs;
E 65
						ino = ROOTINO;
						goto loop;
					}
E 18
				panic("no imt");
			}
I 18
			if (ip->i_count == 0) {		/* ino on free list */
				if (iq = ip->i_freef)
					iq->i_freeb = ip->i_freeb;
				else
					ifreet = ip->i_freeb;
				*ip->i_freeb = iq;
				ip->i_freef = NULL;
				ip->i_freeb = NULL;
			}
E 18
			ip->i_count++;
D 30
			ip->i_flag |= ILOCK;
E 30
I 30
			ip->i_flag |= ILOCKED;
E 30
			return(ip);
		}
D 18
		ip = &inode[ip->i_hlink];
	}
D 12
	if(ifreel < 0) {
E 12
I 12
	if (ifreel < 0) {
E 18
I 18

	if ((ip = ifreeh) == NULL) {
E 18
E 12
D 8
		printf("Inode table overflow\n");
E 8
I 8
		tablefull("inode");
E 8
		u.u_error = ENFILE;
		return(NULL);
	}
I 49
	if (ip->i_count)
		panic("free inode isn't");
E 49
D 18
	ip = &inode[ifreel];
	ifreel = ip->i_hlink;
	ip->i_hlink = inohash[slot];
	inohash[slot] = ip - inode;
E 18
I 18
	if (iq = ip->i_freef)
		iq->i_freeb = &ifreeh;
	ifreeh = iq;
	ip->i_freef = NULL;
	ip->i_freeb = NULL;
	/*
	 * Now to take inode off the hash chain it was on
	 * (initially, or after an iflush, it is on a "hash chain"
	 * consisting entirely of itself, and pointed to by no-one,
	 * but that doesn't matter), and put it on the chain for
	 * its new (ino, dev) pair
	 */
D 19
#ifndef	UNFAST
	asm("remque	(r11),r0");
	asm("insque	(r11),(r10)");
#else
		/* remque */
	ip->i_back->i_forw = ip->i_forw;
	ip->i_forw->i_back = ip->i_back;
		/* insque */
	ip->i_forw = ih->ih_chain[0];
	ip->i_back = (struct inode *)ih;
	ih->ih_chain[0]->i_back = ip;
	ih->ih_chain[0] = ip;
#endif
E 19
I 19
	remque(ip);
	insque(ip, ih);
I 23
D 27
#ifdef	QUOTA
E 27
I 27
D 49
#ifdef QUOTA
E 27
	dqrele(ip->i_dquot);
#endif
E 49
E 23
E 19
E 18
	ip->i_dev = dev;
I 15
	ip->i_fs = fs;
E 15
	ip->i_number = ino;
I 46
D 50
	ip->i_id = ++nextinodeid;	/* also used in rename */
	/*
	 * At an absurd rate of 100 calls/second,
D 47
	 * this should occur once every 16 months.
E 47
I 47
	 * this should occur once every 8 months.
E 47
	 */
D 47
	if (nextinodeid == 0)
		panic("iget: wrap");
E 47
I 47
	if (nextinodeid < 0)
		for (nextinodeid = 0, xp = inode; xp < inodeNINODE; xp++)
			xp->i_id = 0;
E 50
I 50
	cacheinval(ip);
E 50
E 47
E 46
D 30
	ip->i_flag = ILOCK;
E 30
I 30
	ip->i_flag = ILOCKED;
E 30
	ip->i_count++;
D 15
	ip->i_un.i_lastr = 0;
	bp = bread(dev, itod(ino));
E 15
I 15
	ip->i_lastr = 0;
I 49
#ifdef QUOTA
	dqrele(ip->i_dquot);
#endif
I 62
#ifdef SECSIZE
	bp = bread(dev, fsbtodb(fs, itod(fs, ino)), (int)fs->fs_bsize,
	    fs->fs_dbsize);
#else SECSIZE
E 62
E 49
D 32
	bp = bread(dev, fsbtodb(fs, itod(fs, ino)), fs->fs_bsize);
E 32
I 32
	bp = bread(dev, fsbtodb(fs, itod(fs, ino)), (int)fs->fs_bsize);
I 62
#endif SECSIZE
E 62
E 32
E 15
	/*
	 * Check I/O errors
	 */
D 12
	if((bp->b_flags&B_ERROR) != 0) {
E 12
I 12
	if ((bp->b_flags&B_ERROR) != 0) {
E 12
		brelse(bp);
I 18
		/*
		 * the inode doesn't contain anything useful, so it would
		 * be misleading to leave it on its hash chain.
		 * 'iput' will take care of putting it back on the free list.
		 */
D 19
#ifndef	UNFAST
		asm("remque	(r11),r0");
#else
		ip->i_back->i_forw = ip->i_forw;
		ip->i_forw->i_back = ip->i_back;
#endif
E 19
I 19
		remque(ip);
E 19
		ip->i_forw = ip;
		ip->i_back = ip;
		/*
		 * we also loose its inumber, just in case (as iput
		 * doesn't do that any more) - but as it isn't on its
		 * hash chain, I doubt if this is really necessary .. kre
		 * (probably the two methods are interchangable)
		 */
		ip->i_number = 0;
I 23
D 27
#ifdef	QUOTA
E 27
I 27
#ifdef QUOTA
E 27
		ip->i_dquot = NODQUOT;
#endif
E 23
E 18
		iput(ip);
		return(NULL);
	}
	dp = bp->b_un.b_dino;
D 15
	dp += itoo(ino);
	iexpand(ip, dp);
E 15
I 15
	dp += itoo(fs, ino);
	ip->i_ic = dp->di_ic;
E 15
	brelse(bp);
I 23
D 27
#ifdef	QUOTA
E 27
I 27
#ifdef QUOTA
E 27
	if (ip->i_mode == 0)
		ip->i_dquot = NODQUOT;
	else
		ip->i_dquot = inoquota(ip);
#endif
E 23
D 15
	return(ip);
E 15
I 15
	return (ip);
I 46
}

/*
 * Convert a pointer to an inode into a reference to an inode.
 *
 * This is basically the internal piece of iget (after the
 * inode pointer is located) but without the test for mounted
 * filesystems.  It is caller's responsibility to check that
 * the inode pointer is valid.
 */
igrab(ip)
	register struct inode *ip;
{
	while ((ip->i_flag&ILOCKED) != 0) {
		ip->i_flag |= IWANT;
		sleep((caddr_t)ip, PINOD);
	}
	if (ip->i_count == 0) {		/* ino on free list */
		register struct inode *iq;

		if (iq = ip->i_freef)
			iq->i_freeb = ip->i_freeb;
		else
			ifreet = ip->i_freeb;
		*ip->i_freeb = iq;
		ip->i_freef = NULL;
		ip->i_freeb = NULL;
	}
	ip->i_count++;
	ip->i_flag |= ILOCKED;
E 46
E 15
}

I 25
D 26
#ifdef MATISSE
int	badinum = 3197;
#else
E 25
I 24
int	badinum = -1;
I 25
#endif
E 26
E 25
E 24
D 15
iexpand(ip, dp)
D 12
register struct inode *ip;
register struct dinode *dp;
E 12
I 12
	register struct inode *ip;
	register struct dinode *dp;
E 12
{
	register char *p1, *p2;
	register int i;

	ip->i_mode = dp->di_mode;
	ip->i_nlink = dp->di_nlink;
	ip->i_uid = dp->di_uid;
	ip->i_gid = dp->di_gid;
	ip->i_size = dp->di_size;
	p1 = (char *)ip->i_un.i_addr;
	p2 = (char *)dp->di_addr;
	for(i=0; i<NADDR; i++) {
		*p1++ = *p2++;
		*p1++ = *p2++;
		*p1++ = *p2++;
		*p1++ = 0;
	}
}

E 15
/*
 * Decrement reference count of
 * an inode structure.
 * On the last reference,
 * write the inode out and if necessary,
 * truncate and deallocate the file.
 */
iput(ip)
D 12
register struct inode *ip;
E 12
I 12
	register struct inode *ip;
E 12
{
I 16

D 30
	if ((ip->i_flag & ILOCK) == 0)
E 30
I 30
	if ((ip->i_flag & ILOCKED) == 0)
E 30
		panic("iput");
I 24
D 26
/* XXX */
	if (ip->i_number == badinum && (ip->i_mode&IFMT) == IFCHR &&
	    (major(ip->i_dev) != 3 || minor(ip->i_dev) != 2))
		panic("/dev/null");
/* XXX */
E 26
E 24
D 48
	iunlock(ip);
E 48
I 48
	IUNLOCK(ip);
E 48
	irele(ip);
}

irele(ip)
	register struct inode *ip;
{
E 16
D 31
	register int i, x;
	register struct inode *jp;
E 31
I 15
	int mode;
E 15

I 16
D 17
	if (ip->i_flag & ILOCK)
		panic("irele");
E 17
E 16
D 12
	if(ip->i_count == 1) {
E 12
I 12
D 54
	if (ip->i_count == 1) {
E 54
I 54
D 56
	if (ip->i_count == 1 && ip->i_fs->fs_ronly != 0) {
E 56
I 56
	if (ip->i_count == 1) {
E 56
E 54
E 12
D 30
		ip->i_flag |= ILOCK;
E 30
I 30
		ip->i_flag |= ILOCKED;
E 30
D 12
		if(ip->i_nlink <= 0) {
E 12
I 12
D 56
		if (ip->i_nlink <= 0) {
E 56
I 56
		if (ip->i_nlink <= 0 && ip->i_fs->fs_ronly == 0) {
E 56
E 12
D 28
			itrunc(ip);
E 28
I 28
D 36
			itrunc(ip, 0);
E 36
I 36
			itrunc(ip, (u_long)0);
E 36
E 28
I 15
			mode = ip->i_mode;
E 15
			ip->i_mode = 0;
I 22
			ip->i_rdev = 0;
E 22
			ip->i_flag |= IUPD|ICHG;
D 15
			ifree(ip->i_dev, ip->i_number);
E 15
I 15
			ifree(ip, ip->i_number, mode);
I 23
D 27
#ifdef	QUOTA
E 27
I 27
#ifdef QUOTA
E 27
D 36
			chkiq(ip->i_dev, ip, ip->i_uid, 0);
E 36
I 36
D 40
			(void)chkiq(ip->i_dev, ip, ip->i_uid, 0);
E 40
I 40
			(void) chkiq(ip->i_dev, ip, ip->i_uid, 0);
E 40
E 36
			dqrele(ip->i_dquot);
			ip->i_dquot = NODQUOT;
#endif
E 23
E 15
		}
D 2
		iupdat(ip, &time, &time);
E 2
I 2
D 5
		IUPDAT(ip, &time, &time);
E 5
I 5
D 29
		IUPDAT(ip, &time, &time, 0);
E 29
I 29
D 33
		IUPDAT(ip, &time.tv_sec, &time.tv_sec, 0);
E 33
I 33
D 34
		IUPDAT(ip, time, time, 0);
E 34
I 34
		IUPDAT(ip, &time, &time, 0);
E 34
E 33
E 29
E 5
E 2
D 12
		prele(ip);
E 12
I 12
D 16
		irele(ip);
E 16
I 16
D 48
		iunlock(ip);
E 48
I 48
		IUNLOCK(ip);
E 48
E 16
E 12
D 18
		i = INOHASH(ip->i_dev, ip->i_number);
		x = ip - inode;
		if (inohash[i] == x) {
			inohash[i] = ip->i_hlink;
E 18
I 18
		ip->i_flag = 0;
		/*
		 * Put the inode on the end of the free list.
		 * Possibly in some cases it would be better to
		 * put the inode at the head of the free list,
		 * (eg: where i_mode == 0 || i_number == 0)
		 * but I will think about that later .. kre
		 * (i_number is rarely 0 - only after an i/o error in iget,
		 * where i_mode == 0, the inode will probably be wanted
		 * again soon for an ialloc, so possibly we should keep it)
		 */
		if (ifreeh) {
			*ifreet = ip;
			ip->i_freeb = ifreet;
E 18
		} else {
D 18
			for (jp = &inode[inohash[i]]; jp != &inode[-1];
			    jp = &inode[jp->i_hlink])
				if (jp->i_hlink == x) {
					jp->i_hlink = ip->i_hlink;
					goto done;
				}
			panic("iput");
E 18
I 18
			ifreeh = ip;
			ip->i_freeb = &ifreeh;
E 18
		}
D 18
done:
		ip->i_hlink = ifreel;
		ifreel = x;
		ip->i_flag = 0;
		ip->i_number = 0;
E 18
I 18
		ip->i_freef = NULL;
		ifreet = &ip->i_freef;
I 43
D 44
	} else if ((ip->i_flag & (IUPD|IACC|ICHG)) &&
	    ((ip->i_flag & ILOCKED) == 0)) {
		ip->i_flag |= ILOCKED;
		iupdat(ip, &time, &time, 0);
		iunlock(ip);
E 43
E 18
D 16
	} else
D 12
		prele(ip);
E 12
I 12
		irele(ip);
E 16
I 16
	}
E 44
I 44
	} else if (!(ip->i_flag & ILOCKED))
		ITIMES(ip, &time, &time);
E 44
E 16
E 12
	ip->i_count--;
}

/*
 * Check accessed and update flags on
 * an inode structure.
 * If any is on, update the inode
 * with the current time.
I 5
 * If waitfor is given, then must insure
 * i/o order so wait for write to complete.
E 5
 */
D 5
iupdat(ip, ta, tm)
E 5
I 5
iupdat(ip, ta, tm, waitfor)
E 5
D 12
register struct inode *ip;
time_t *ta, *tm;
I 5
int waitfor;
E 12
I 12
	register struct inode *ip;
D 33
	time_t *ta, *tm;
E 33
I 33
	struct timeval *ta, *tm;
E 33
	int waitfor;
E 12
E 5
{
	register struct buf *bp;
	struct dinode *dp;
D 15
	register char *p1, *p2;
	register int i;
E 15
I 15
D 62
D 63
	register struct fs *fp;
E 63
I 63
	register struct fs *fs;
E 63
E 62
I 62
	register struct fs *fs;
E 62
E 15

D 12
	if((ip->i_flag&(IUPD|IACC|ICHG)) != 0) {
		if(getfs(ip->i_dev)->s_ronly)
E 12
I 12
D 15
	if ((ip->i_flag&(IUPD|IACC|ICHG)) != 0) {
		if (getfs(ip->i_dev)->s_ronly)
E 15
I 15
D 62
D 63
	fp = ip->i_fs;
E 63
I 63
	fs = ip->i_fs;
E 63
E 62
I 62
	fs = ip->i_fs;
E 62
D 44
	if ((ip->i_flag & (IUPD|IACC|ICHG)) != 0) {
E 44
I 44
	if ((ip->i_flag & (IUPD|IACC|ICHG|IMOD)) != 0) {
E 44
D 62
D 63
		if (fp->fs_ronly)
E 63
I 63
		if (fs->fs_ronly)
E 63
E 62
I 62
		if (fs->fs_ronly)
E 62
E 15
E 12
			return;
D 15
		bp = bread(ip->i_dev, itod(ip->i_number));
E 15
I 15
D 62
D 63
		bp = bread(ip->i_dev, fsbtodb(fp, itod(fp, ip->i_number)),
D 32
			fp->fs_bsize);
E 32
I 32
			(int)fp->fs_bsize);
E 63
I 63
		bp = bread(ip->i_dev, fsbtodb(fs, itod(fs, ip->i_number)),
			(int)fs->fs_bsize);
E 63
E 62
I 62
#ifdef SECSIZE
		bp = bread(ip->i_dev, fsbtodb(fs, itod(fs, ip->i_number)),
			(int)fs->fs_bsize, fs->fs_dbsize);
#else SECSIZE
		bp = bread(ip->i_dev, fsbtodb(fs, itod(fs, ip->i_number)),
			(int)fs->fs_bsize);
#endif SECSIZE
E 62
E 32
E 15
		if (bp->b_flags & B_ERROR) {
			brelse(bp);
			return;
		}
D 15
		dp = bp->b_un.b_dino;
		dp += itoo(ip->i_number);
		dp->di_mode = ip->i_mode;
		dp->di_nlink = ip->i_nlink;
		dp->di_uid = ip->i_uid;
		dp->di_gid = ip->i_gid;
		dp->di_size = ip->i_size;
		p1 = (char *)dp->di_addr;
		p2 = (char *)ip->i_un.i_addr;
		for(i=0; i<NADDR; i++) {
			*p1++ = *p2++;
			*p1++ = *p2++;
			*p1++ = *p2++;
D 11
			if(*p2++ != 0 && (ip->i_mode&IFMT)!=IFMPC
			   && (ip->i_mode&IFMT)!=IFMPB)
E 11
I 11
D 12
			if(*p2++ != 0)
E 12
I 12
			if (*p2++ != 0)
E 12
E 11
				printf("iaddress > 2^24\n");
		}
E 15
D 12
		if(ip->i_flag&IACC)
E 12
I 12
		if (ip->i_flag&IACC)
E 12
D 15
			dp->di_atime = *ta;
E 15
I 15
D 33
			ip->i_atime = *ta;
E 33
I 33
			ip->i_atime = ta->tv_sec;
E 33
E 15
D 12
		if(ip->i_flag&IUPD)
E 12
I 12
		if (ip->i_flag&IUPD)
E 12
D 15
			dp->di_mtime = *tm;
E 15
I 15
D 33
			ip->i_mtime = *tm;
E 33
I 33
			ip->i_mtime = tm->tv_sec;
E 33
E 15
D 12
		if(ip->i_flag&ICHG)
E 12
I 12
		if (ip->i_flag&ICHG)
E 12
D 15
			dp->di_ctime = time;
E 15
I 15
D 29
			ip->i_ctime = time;
E 29
I 29
			ip->i_ctime = time.tv_sec;
E 29
E 15
D 44
		ip->i_flag &= ~(IUPD|IACC|ICHG);
E 44
I 44
		ip->i_flag &= ~(IUPD|IACC|ICHG|IMOD);
E 44
I 21
D 62
D 63
		dp = bp->b_un.b_dino + itoo(fp, ip->i_number);
E 63
I 63
		dp = bp->b_un.b_dino + itoo(fs, ip->i_number);
E 63
E 62
I 62
		dp = bp->b_un.b_dino + itoo(fs, ip->i_number);
E 62
		dp->di_ic = ip->i_ic;
E 21
I 15
D 18
		dp = bp->b_un.b_dino + itoo(fp, ip->i_number);
		dp->di_ic = ip->i_ic;
E 18
E 15
D 5
		bdwrite(bp);
E 5
I 5
		if (waitfor)
			bwrite(bp);
		else
			bdwrite(bp);
E 5
	}
}

I 37
#define	SINGLE	0	/* index of single indirect block */
#define	DOUBLE	1	/* index of double indirect block */
#define	TRIPLE	2	/* index of triple indirect block */
E 37
/*
D 28
 * Free all the disk blocks associated
 * with the specified inode structure.
 * The blocks of the file are removed
D 25
 * in reverse order. This FILO
 * algorithm will tend to maintain
 * a contiguous free list much longer
 * than FIFO.
E 25
I 25
 * in reverse order.
E 28
I 28
 * Truncate the inode ip to at most
 * length size.  Free affected disk
 * blocks -- the blocks of the file
 * are removed in reverse order.
I 37
 *
 * NB: triple indirect blocks are untested.
E 37
E 28
E 25
 */
D 28
itrunc(ip)
E 28
I 28
D 37
itrunc(ip, length)
E 28
D 12
register struct inode *ip;
E 12
I 12
	register struct inode *ip;
E 37
I 37
itrunc(oip, length)
D 53
	struct inode *oip;
E 53
I 53
	register struct inode *oip;
E 53
E 37
I 28
D 36
	register int length;
E 36
I 36
	u_long length;
E 36
E 28
E 12
{
D 53
	register i;
E 53
D 34
	dev_t dev;
E 34
D 36
	daddr_t bn;
I 5
	struct inode itmp;
E 36
I 36
	register daddr_t lastblock;
D 37
	daddr_t bn, lastdiblock, lastsiblock;
E 37
I 37
D 59
	daddr_t bn, lastiblock[NIADDR];
E 59
I 59
	daddr_t bn, lbn, lastiblock[NIADDR];
E 59
E 37
E 36
I 15
	register struct fs *fs;
I 36
D 37
	int j;
E 37
I 37
	register struct inode *ip;
I 53
	struct buf *bp;
D 58
	int offset, lbn, osize, size, error, count, level, s;
E 58
I 58
D 59
	int offset, lbn, osize, size, count, level, s;
E 59
I 59
D 62
D 63
	int offset, osize, size, count, level, s;
E 63
I 63
	int offset, osize, size, count, level;
E 63
E 62
I 62
	int offset, osize, size, count, level;
E 62
E 59
E 58
	long nblocks, blocksreleased = 0;
	register int i;
	dev_t dev;
E 53
	struct inode tip;
D 40
	int level;
E 37
E 36
I 23
D 27
#ifdef	QUOTA
E 27
I 27
#ifdef QUOTA
E 40
E 27
D 36
	register long cnt = 0;
	long tloop();
E 36
I 36
D 53
	long blocksreleased = 0, nblocks;
	long indirtrunc();
E 36
D 40
#endif
E 40
I 40
	int level;
E 53
I 53
	extern long indirtrunc();
D 62
D 63
	extern struct cmap *mfind();
E 63
E 62
E 53
E 40
I 26
D 36
	/*
	 * Only plain files, directories and symbolic
	 * links contain blocks.
	 */
	i = ip->i_mode & IFMT;
	if (i != IFREG && i != IFDIR && i != IFLNK)
		return;
E 36
I 36

E 36
I 28
D 37
	if (ip->i_size <= length)
E 37
I 37
D 41
	if (oip->i_size <= length)
E 41
I 41
	if (oip->i_size <= length) {
		oip->i_flag |= ICHG|IUPD;
		iupdat(oip, &time, &time, 1);
E 41
E 37
		return;
I 41
	}
E 41
E 28
E 26
E 23
E 15
E 5
D 36

E 36
I 36
D 37
#ifdef notdef
	/* this is superfluous given size check above */
	i = ip->i_mode & IFMT;
	if (i != IFREG && i != IFDIR && i != IFLNK) {
		printf("itrunc: i# %d, size %d\n", ip->i_number, ip->i_size);
		return;
	}
#endif
E 37
E 36
D 12
	if (ip->i_vfdcnt)
		panic("itrunc");
E 12
D 20
	i = ip->i_mode & IFMT;
D 14
	if (i!=IFREG && i!=IFDIR)
E 14
I 14
D 15
	if (i!=IFREG && i!=IFDIR && i!=IFLNK)
E 15
I 15
	if (i != IFREG && i != IFDIR && i != IFLNK)
E 15
E 14
		return;
E 20
I 5
D 15

E 15
	/*
D 36
	 * Clean inode on disk before freeing blocks
	 * to insure no duplicates if system crashes.
E 36
I 36
D 37
	 * Update size of file on disk before
	 * we start freeing blocks.  If we crash
	 * while free'ing blocks below, the file
	 * size will be believed and the blocks
	 * returned to the free list.
	 * After updating the copy on disk we
	 * put the old size back so macros like
	 * blksize will work.
E 37
I 37
	 * Calculate index into inode's block list of
	 * last direct and indirect blocks (if any)
	 * which we want to keep.  Lastblock is -1 when
	 * the file is truncated to 0.
E 37
E 36
	 */
D 36
	itmp = *ip;
D 28
	itmp.i_size = 0;
E 28
I 28
	itmp.i_size = length;
E 28
D 15
	for (i = 0; i < NADDR; i++)
		itmp.i_un.i_addr[i] = 0;
E 15
I 15
	for (i = 0; i < NDADDR; i++)
		itmp.i_db[i] = 0;
	for (i = 0; i < NIADDR; i++)
		itmp.i_ib[i] = 0;
E 15
	itmp.i_flag |= ICHG|IUPD;
D 29
	iupdat(&itmp, &time, &time, 1);
E 29
I 29
D 33
	iupdat(&itmp, &time.tv_sec, &time.tv_sec, 1);
E 33
I 33
D 34
	iupdat(&itmp, time, time, 1);
E 34
I 34
	iupdat(&itmp, &time, &time, 1);
E 34
E 33
E 29
	ip->i_flag &= ~(IUPD|IACC|ICHG);
E 36
I 36
D 37
	j = ip->i_size;
	ip->i_size = length;
	ip->i_flag |= ICHG|IUPD;
	iupdat(ip, &time, &time, 1);
	ip->i_size = j;
E 36

I 20
D 26
	/*
	 * Only plain files, directories and symbolic
	 * links contain blocks.
	 */
	i = ip->i_mode & IFMT;
	if (i != IFREG && i != IFDIR && i != IFLNK)
		return;
E 26
E 20
	/*
D 36
	 * Now return blocks to free list... if machine
	 * crashes, they will be harmless MISSING blocks.
E 36
I 36
	 * Calculate last direct, single indirect and
	 * double indirect block (if any) which we want
	 * to keep.  Lastblock is -1 when the file is
	 * truncated to 0.
E 36
	 */
E 5
D 31
	dev = ip->i_dev;
E 31
D 15
	for(i=NADDR-1; i>=0; i--) {
		bn = ip->i_un.i_addr[i];
E 15
I 15
	fs = ip->i_fs;
E 37
I 37
	fs = oip->i_fs;
E 37
I 36
	lastblock = lblkno(fs, length + fs->fs_bsize - 1) - 1;
D 37
	lastsiblock = lastblock - NDADDR;
	lastdiblock = lastsiblock - NINDIR(fs);
E 37
I 37
	lastiblock[SINGLE] = lastblock - NDADDR;
	lastiblock[DOUBLE] = lastiblock[SINGLE] - NINDIR(fs);
	lastiblock[TRIPLE] = lastiblock[DOUBLE] - NINDIR(fs) * NINDIR(fs);
E 37
D 40
#ifdef QUOTA
	nblocks = fs->fs_bsize / DEV_BSIZE;
#endif
E 40
I 40
	nblocks = btodb(fs->fs_bsize);
E 40
E 36
	/*
D 36
	 * release double indirect block first
E 36
I 36
D 37
	 * Double indirect block first
E 37
I 37
D 53
	 * Update size of file and block pointers
E 53
I 53
	 * Update the size of the file. If the file is not being
	 * truncated to a block boundry, the contents of the
	 * partial block following the end of the file must be
	 * zero'ed in case it ever become accessable again because
	 * of subsequent file growth.
	 */
	osize = oip->i_size;
	offset = blkoff(fs, length);
	if (offset == 0) {
		oip->i_size = length;
	} else {
		lbn = lblkno(fs, length);
		bn = fsbtodb(fs, bmap(oip, lbn, B_WRITE, offset));
		if (u.u_error || (long)bn < 0)
			return;
		oip->i_size = length;
		size = blksize(fs, oip, lbn);
D 62
D 63
		count = howmany(size, DEV_BSIZE);
E 63
I 63
		count = howmany(size, CLBYTES);
E 63
E 62
I 62
		count = howmany(size, CLBYTES);
E 62
		dev = oip->i_dev;
D 62
D 63
		s = splimp();
		for (i = 0; i < count; i += CLSIZE)
			if (mfind(dev, bn + i))
				munhash(dev, bn + i);
		splx(s);
E 63
I 63
		for (i = 0; i < count; i++)
			munhash(dev, bn + i * CLBYTES / DEV_BSIZE);
E 63
E 62
I 62
		for (i = 0; i < count; i++)
#ifdef SECSIZE
			munhash(dev, bn + i * CLBYTES / fs->fs_dbsize);
#else SECSIZE
			munhash(dev, bn + i * CLBYTES / DEV_BSIZE);
#endif SECSIZE
E 62
		bp = bread(dev, bn, size);
		if (bp->b_flags & B_ERROR) {
			u.u_error = EIO;
			oip->i_size = osize;
			brelse(bp);
			return;
		}
D 59
		bzero(bp->b_un.b_addr + offset, size - offset);
E 59
I 59
		bzero(bp->b_un.b_addr + offset, (unsigned)(size - offset));
E 59
		bdwrite(bp);
	}
	/*
	 * Update file and block pointers
E 53
	 * on disk before we start freeing blocks.
	 * If we crash before free'ing blocks below,
	 * the blocks will be returned to the free list.
	 * lastiblock values are also normalized to -1
	 * for calls to indirtrunc below.
D 53
	 * (? fsck doesn't check validity of pointers in indirect blocks)
E 53
E 37
E 36
	 */
D 36
	bn = ip->i_ib[NIADDR-1];
	if (bn != (daddr_t)0) {
		ip->i_ib[NIADDR - 1] = (daddr_t)0;
E 36
I 36
D 37
	bn = ip->i_ib[NIADDR - 1];
	if (bn != 0) {
		/*
		 * If lastdiblock is negative, it's value
		 * is meaningless; in this case we set it to
		 * -NINDIR(fs) so calculations performed in
		 * indirtrunc come out right.
		 */
		if (lastdiblock < 0)
			lastdiblock -= lastsiblock;
E 36
D 23
		tloop(ip, bn, 1);
E 23
I 23
D 27
#ifdef	QUOTA
E 27
I 27
#ifdef QUOTA
E 27
D 36
		cnt +=
E 36
I 36
		blocksreleased +=
E 36
#endif
D 36
			tloop(ip, bn, 1);
E 36
I 36
			indirtrunc(ip, bn, lastdiblock, 1);
		if (lastdiblock < 0) {
			ip->i_ib[NIADDR - 1] = 0;
			free(ip, bn, (off_t)fs->fs_bsize);
#ifdef QUOTA
			blocksreleased += nblocks;
#endif
E 37
I 37
	tip = *oip;
I 53
	tip.i_size = osize;
E 53
	for (level = TRIPLE; level >= SINGLE; level--)
		if (lastiblock[level] < 0) {
			oip->i_ib[level] = 0;
			lastiblock[level] = -1;
E 37
		}
E 36
E 23
D 37
	}
I 36
	if (lastdiblock >= 0)
		goto done;
E 37
I 37
	for (i = NDADDR - 1; i > lastblock; i--)
		oip->i_db[i] = 0;
D 53
	oip->i_size = length;
E 53
	oip->i_flag |= ICHG|IUPD;
D 53
	iupdat(oip, &time, &time, 1);
	ip = &tip;
E 53
I 53
	syncip(oip);
E 53

E 37
E 36
	/*
D 36
	 * release single indirect blocks second
E 36
I 36
D 37
	 * Single indirect blocks second.
	 * First, those which can be totally
	 * zapped, then possibly one which
	 * needs to be partially cleared.
E 37
I 37
	 * Indirect blocks first.
E 37
E 36
	 */
I 53
	ip = &tip;
E 53
D 36
	for (i = NIADDR - 2; i >= 0; i--) {
E 36
I 36
D 37
	j = lastsiblock < 0 ? -1 : lastsiblock / NINDIR(fs);
	for (i = NIADDR - 2; i > j; i--) {
E 36
		bn = ip->i_ib[i];
E 37
I 37
	for (level = TRIPLE; level >= SINGLE; level--) {
		bn = ip->i_ib[level];
E 37
D 36
		if (bn != (daddr_t)0) {
			ip->i_ib[i] = (daddr_t)0;
E 36
I 36
		if (bn != 0) {
E 36
D 23
			tloop(ip, bn, 0);
E 23
I 23
D 27
#ifdef	QUOTA
E 27
I 27
D 40
#ifdef QUOTA
E 40
E 27
D 36
			cnt +=
E 36
I 36
D 37
			blocksreleased += nblocks +
E 37
I 37
			blocksreleased +=
E 37
E 36
D 40
#endif
D 36
				tloop(ip, bn, 0);
E 36
I 36
D 37
				indirtrunc(ip, bn, (daddr_t)-1, 0);
			ip->i_ib[i] = 0;
			free(ip, bn, (off_t)fs->fs_bsize);
E 36
E 23
		}
	}
I 36
	if (lastsiblock >= 0) {
		bn = ip->i_ib[j];
		if (bn != 0)
E 37
I 37
				indirtrunc(ip, bn, lastiblock[level], level);
E 40
I 40
			    indirtrunc(ip, bn, lastiblock[level], level);
E 40
			if (lastiblock[level] < 0) {
				ip->i_ib[level] = 0;
D 64
				free(ip, bn, (off_t)fs->fs_bsize);
E 64
I 64
				blkfree(ip, bn, (off_t)fs->fs_bsize);
E 64
E 37
D 40
#ifdef QUOTA
E 40
D 37
			blocksreleased +=
E 37
I 37
				blocksreleased += nblocks;
E 37
D 40
#endif
E 40
D 37
				indirtrunc(ip, bn, lastsiblock, 0);
		goto done;
E 37
I 37
			}
		}
		if (lastiblock[level] >= 0)
			goto done;
E 37
	}
I 37

E 37
E 36
	/*
D 36
	 * finally release direct blocks
E 36
I 36
D 37
	 * All whole direct blocks.
E 37
I 37
	 * All whole direct blocks or frags.
E 37
E 36
	 */
D 36
	for (i = NDADDR - 1; i>=0; i--) {
E 36
I 36
	for (i = NDADDR - 1; i > lastblock; i--) {
D 58
		register int size;
E 58
I 58
D 60
		register int bsize;
E 60
I 60
		register off_t bsize;
E 60
E 58

E 36
I 23
D 34
		register size;

E 34
E 23
		bn = ip->i_db[i];
E 15
D 12
		if(bn == (daddr_t)0)
E 12
I 12
D 36
		if (bn == (daddr_t)0)
E 36
I 36
		if (bn == 0)
E 36
E 12
			continue;
D 15
		ip->i_un.i_addr[i] = (daddr_t)0;
		switch(i) {

		default:
			free(dev, bn);
			break;

		case NADDR-3:
			tloop(dev, bn, 0, 0);
			break;

		case NADDR-2:
			tloop(dev, bn, 1, 0);
			break;

		case NADDR-1:
			tloop(dev, bn, 1, 1);
		}
E 15
I 15
D 36
		ip->i_db[i] = (daddr_t)0;
I 31
#ifndef QUOTA
		fre(ip, bn, (off_t)blksize(fs, ip, i));
#else
E 31
D 23
		fre(ip, bn, (off_t)blksize(fs, ip, i));
E 23
I 23
D 35
		fre(ip, bn, size = (off_t)blksize(fs, ip, i));
D 27
#ifdef	QUOTA
E 27
I 27
D 31
#ifdef QUOTA
E 31
E 27
		cnt += size / DEV_BSIZE;
E 35
I 35
		{ int size;
		  fre(ip, bn, size = (off_t)blksize(fs, ip, i));
		  cnt += size / DEV_BSIZE;
		}
E 36
I 36
		ip->i_db[i] = 0;
D 58
		size = (off_t)blksize(fs, ip, i);
		free(ip, bn, size);
D 40
#ifdef QUOTA
		blocksreleased += size / DEV_BSIZE;
E 36
E 35
#endif
E 40
I 40
		blocksreleased += btodb(size);
E 58
I 58
		bsize = (off_t)blksize(fs, ip, i);
D 64
		free(ip, bn, bsize);
E 64
I 64
		blkfree(ip, bn, bsize);
E 64
		blocksreleased += btodb(bsize);
E 58
E 40
E 23
E 15
	}
I 37
	if (lastblock < 0)
		goto done;

E 37
D 36
	ip->i_size = 0;
E 36
D 5
	ip->i_flag |= ICHG|IUPD;
E 5
I 5
	/*
D 36
	 * Inode was written and flags updated above.
	 * No need to modify flags here.
E 36
I 36
	 * Finally, look for a change in size of the
	 * last direct block; release any frags.
E 36
	 */
I 36
D 37
	if (lastblock >= 0 && ip->i_db[lastblock] != 0) {
E 37
I 37
	bn = ip->i_db[lastblock];
	if (bn != 0) {
D 60
		int oldspace, newspace;
E 60
I 60
		off_t oldspace, newspace;
E 60

E 37
		/*
		 * Calculate amount of space we're giving
		 * back as old block size minus new block size.
		 */
D 37
		i = blksize(fs, ip, lastblock);
E 37
I 37
		oldspace = blksize(fs, ip, lastblock);
E 37
		ip->i_size = length;
D 37
		i = i - blksize(fs, ip, lastblock);
		if (i > 0) {
E 37
I 37
		newspace = blksize(fs, ip, lastblock);
		if (newspace == 0)
			panic("itrunc: newspace");
		if (oldspace - newspace > 0) {
E 37
			/*
			 * Block number of space to be free'd is
			 * the old block # plus the number of frags
			 * required for the storage we're keeping.
			 */
D 37
			bn = ip->i_db[lastblock] +
				numfrags(fs, fs->fs_bsize - i);
			free(ip, bn, i);
E 37
I 37
			bn += numfrags(fs, newspace);
D 64
			free(ip, bn, oldspace - newspace);
E 64
I 64
			blkfree(ip, bn, oldspace - newspace);
E 64
E 37
E 36
I 23
D 27
#ifdef	QUOTA
E 27
I 27
D 40
#ifdef QUOTA
E 27
D 36
	(void) chkdq(ip, -cnt, 0);
E 36
I 36
D 37
			blocksreleased += i / DEV_BSIZE;
E 37
I 37
			blocksreleased += (oldspace - newspace) / DEV_BSIZE;
E 37
E 36
#endif
E 40
I 40
			blocksreleased += btodb(oldspace - newspace);
E 40
I 36
		}
	}
done:
D 37
	/*
	 * Finished free'ing blocks, complete
	 * inode update to reflect new length.
	 */
E 37
I 37
/* BEGIN PARANOIA */
	for (level = SINGLE; level <= TRIPLE; level++)
		if (ip->i_ib[level] != oip->i_ib[level])
			panic("itrunc1");
	for (i = 0; i < NDADDR; i++)
		if (ip->i_db[i] != oip->i_db[i])
			panic("itrunc2");
/* END PARANOIA */
I 40
	oip->i_blocks -= blocksreleased;
	if (oip->i_blocks < 0)			/* sanity */
		oip->i_blocks = 0;
	oip->i_flag |= ICHG;
E 40
E 37
#ifdef QUOTA
D 40
	(void) chkdq(ip, -blocksreleased, 0);
E 40
I 40
	(void) chkdq(oip, -blocksreleased, 0);
E 40
#endif
D 37
	ip->i_size = length;
	ip->i_flag |= ICHG|IUPD;
	iupdat(ip, &time, &time, 1);
E 37
E 36
E 23
E 5
}

I 36
/*
 * Release blocks associated with the inode ip and
 * stored in the indirect block bn.  Blocks are free'd
 * in LIFO order up to (but not including) lastbn.  If
D 37
 * doubleindirect is indicated, this block is a double
 * indirect block and recursive calls to indirtrunc must
 * be used to cleanse single indirect blocks instead of
 * a simple free.
E 37
I 37
 * level is greater than SINGLE, the block is an indirect
 * block and recursive calls to indirtrunc must be used to
 * cleanse other indirect blocks.
 *
 * NB: triple indirect blocks are untested.
E 37
 */
E 36
I 23
D 27
#ifdef	QUOTA
E 27
I 27
D 40
#ifdef QUOTA
E 40
E 27
long
D 40
#endif
E 40
E 23
D 15
tloop(dev, bn, f1, f2)
dev_t dev;
daddr_t bn;
E 15
I 15
D 36
tloop(ip, bn, indflg)
E 36
I 36
D 37
indirtrunc(ip, bn, lastbn, doubleindirect)
E 37
I 37
indirtrunc(ip, bn, lastbn, level)
E 37
E 36
	register struct inode *ip;
D 36
	daddr_t bn;
	int indflg;
E 36
I 36
	daddr_t bn, lastbn;
D 37
	int doubleindirect;
E 37
I 37
	int level;
E 37
E 36
E 15
{
D 36
	register i;
	register struct buf *bp;
E 36
I 36
	register int i;
D 37
	struct buf *bp;
E 37
I 37
D 66
	struct buf *bp, *copy;
E 37
E 36
	register daddr_t *bap;
E 66
I 66
	struct buf *bp;
E 66
I 15
D 37
	register struct fs *fs;
E 37
I 37
	register struct fs *fs = ip->i_fs;
E 37
E 15
D 36
	daddr_t nb;
E 36
I 36
D 66
	daddr_t nb, last;
E 66
I 66
	register daddr_t *bap;
	daddr_t *copy, nb, last;
E 66
I 37
	long factor;
E 37
E 36
I 23
D 27
#ifdef	QUOTA
E 27
I 27
D 40
#ifdef QUOTA
E 40
E 27
D 36
	register long cnt = 0;
E 36
I 36
	int blocksreleased = 0, nblocks;
E 36
D 40
#endif
E 40
E 23

D 37
	bp = NULL;
D 15
	for(i=NINDIR-1; i>=0; i--) {
E 15
I 15
	fs = ip->i_fs;
E 37
I 37
	/*
	 * Calculate index in current block of last
	 * block to be kept.  -1 indicates the entire
	 * block so we need not calculate the index.
	 */
	factor = 1;
	for (i = SINGLE; i < level; i++)
		factor *= NINDIR(fs);
E 37
D 36
	for (i = NINDIR(fs) - 1; i >= 0; i--) {
E 36
I 36
	last = lastbn;
D 37
	if (doubleindirect)
		last /= NINDIR(fs);
E 37
I 37
	if (lastbn > 0)
		last /= factor;
E 37
D 40
#ifdef QUOTA
	nblocks = fs->fs_bsize / DEV_BSIZE;
#endif
E 40
I 40
	nblocks = btodb(fs->fs_bsize);
E 40
D 37
	for (i = NINDIR(fs) - 1; i > last; i--) {
E 36
E 15
D 12
		if(bp == NULL) {
E 12
I 12
		if (bp == NULL) {
I 36
			struct buf *copy;
E 37
I 37
	/*
	 * Get buffer of block pointers, zero those 
	 * entries corresponding to blocks to be free'd,
	 * and update on disk copy first.
	 */
D 66
	copy = geteblk((int)fs->fs_bsize);
E 66
I 62
#ifdef SECSIZE
	bp = bread(ip->i_dev, fsbtodb(fs, bn), (int)fs->fs_bsize,
	    fs->fs_dbsize);
#else SECSIZE
E 62
	bp = bread(ip->i_dev, fsbtodb(fs, bn), (int)fs->fs_bsize);
I 62
#endif SECSIZE
E 62
	if (bp->b_flags&B_ERROR) {
D 66
		brelse(copy);
E 66
		brelse(bp);
D 40
#ifdef QUOTA
E 40
		return (0);
I 39
D 40
#else
		return;
E 39
#endif
E 40
	}
	bap = bp->b_un.b_daddr;
D 66
	bcopy((caddr_t)bap, (caddr_t)copy->b_un.b_daddr, (u_int)fs->fs_bsize);
E 66
I 66
	MALLOC(copy, daddr_t *, fs->fs_bsize, M_TEMP, M_WAITOK);
	bcopy((caddr_t)bap, (caddr_t)copy, (u_int)fs->fs_bsize);
E 66
	bzero((caddr_t)&bap[last + 1],
	  (u_int)(NINDIR(fs) - (last + 1)) * sizeof (daddr_t));
	bwrite(bp);
D 66
	bp = copy, bap = bp->b_un.b_daddr;
E 66
I 66
	bap = copy;
E 66
E 37

D 37
			copy = geteblk((int)fs->fs_bsize);
E 36
E 12
D 15
			bp = bread(dev, bn);
E 15
I 15
D 32
			bp = bread(ip->i_dev, fsbtodb(fs, bn), fs->fs_bsize);
E 32
I 32
			bp = bread(ip->i_dev, fsbtodb(fs, bn),
				(int)fs->fs_bsize);
E 32
E 15
D 36
			if (bp->b_flags & B_ERROR) {
E 36
I 36
			if (bp->b_flags&B_ERROR) {
				brelse(copy);
E 36
				brelse(bp);
D 36
				return;
E 36
I 36
				return (NULL);
E 36
			}
			bap = bp->b_un.b_daddr;
I 36
			/*
			 * Update pointers before freeing blocks.
			 * If we crash before freeing the blocks
			 * they'll be recovered as missing.
			 */
			bcopy((caddr_t)bap, (caddr_t)copy->b_un.b_daddr,
				(u_int)fs->fs_bsize);
			bzero((caddr_t)&bap[last + 1],
			  (u_int)(NINDIR(fs) - (last + 1)) * sizeof (daddr_t));
			bwrite(bp);
			bp = copy, bap = bp->b_un.b_daddr;
E 36
		}
E 37
I 37
	/*
	 * Recursively free totally unused blocks.
	 */
	for (i = NINDIR(fs) - 1; i > last; i--) {
E 37
		nb = bap[i];
D 12
		if(nb == (daddr_t)0)
E 12
I 12
D 36
		if (nb == (daddr_t)0)
E 36
I 36
		if (nb == 0)
E 36
E 12
			continue;
D 12
		if(f1) {
E 12
I 12
D 15
		if (f1) {
E 12
			brelse(bp);
			bp = NULL;
			tloop(dev, nb, f2, 0);
		} else
			free(dev, nb);
E 15
I 15
D 23
		if (indflg)
			tloop(ip, nb, 0);
		else
E 23
I 23
D 36
		if (indflg) {
E 36
I 36
D 37
		if (doubleindirect)
E 37
I 37
		if (level > SINGLE)
E 37
E 36
D 27
#ifdef	QUOTA
E 27
I 27
D 40
#ifdef QUOTA
E 40
E 27
D 36
			cnt +=
E 36
I 36
			blocksreleased +=
E 36
D 40
#endif
D 36
				tloop(ip, nb, 0);
		} else {
E 23
D 33
			fre(ip, nb, fs->fs_bsize);
E 33
I 33
			fre(ip, nb, (int)fs->fs_bsize);
E 36
I 36
D 37
				indirtrunc(ip, nb, (daddr_t)-1, 0);
E 37
I 37
				indirtrunc(ip, nb, (daddr_t)-1, level - 1);
E 40
I 40
			    indirtrunc(ip, nb, (daddr_t)-1, level - 1);
E 40
E 37
D 60
		free(ip, nb, (int)fs->fs_bsize);
E 60
I 60
D 64
		free(ip, nb, (off_t)fs->fs_bsize);
E 64
I 64
		blkfree(ip, nb, (off_t)fs->fs_bsize);
E 64
E 60
E 36
E 33
I 23
D 27
#ifdef	QUOTA
E 27
I 27
D 40
#ifdef QUOTA
E 40
E 27
D 36
			cnt += fs->fs_bsize / DEV_BSIZE;
E 36
I 36
		blocksreleased += nblocks;
E 36
D 40
#endif
E 40
D 36
		}
E 36
E 23
E 15
	}
I 36
D 37
	if (doubleindirect && lastbn >= 0) {
		last = lastbn % NINDIR(fs);
		if (bp == NULL)
			panic("indirtrunc");
E 37
I 37

	/*
	 * Recursively free last partial block.
	 */
	if (level > SINGLE && lastbn >= 0) {
		last = lastbn % factor;
E 37
		nb = bap[i];
		if (nb != 0)
D 40
#ifdef QUOTA
			blocksreleased +=
#endif
D 37
				indirtrunc(ip, nb, last, 0);
E 37
I 37
				indirtrunc(ip, nb, last, level - 1);
E 40
I 40
			blocksreleased += indirtrunc(ip, nb, last, level - 1);
E 40
E 37
	}
E 36
D 12
	if(bp != NULL)
E 12
I 12
D 37
	if (bp != NULL)
E 12
		brelse(bp);
E 37
I 37
D 66
	brelse(bp);
E 66
I 66
	FREE(copy, M_TEMP);
E 66
E 37
D 15
	free(dev, bn);
E 15
I 15
D 33
	fre(ip, bn, fs->fs_bsize);
E 33
I 33
D 36
	fre(ip, bn, (int)fs->fs_bsize);
E 36
E 33
I 23
D 27
#ifdef	QUOTA
E 27
I 27
D 40
#ifdef QUOTA
E 40
E 27
D 36
	cnt += fs->fs_bsize / DEV_BSIZE;
	return(cnt);
E 36
I 36
	return (blocksreleased);
E 36
D 40
#endif
E 40
E 23
E 15
D 25
}

/*
 * Make a new file.
 */
struct inode *
maknode(mode)
I 15
	int mode;
E 15
{
	register struct inode *ip;
I 15
	ino_t ipref;
E 15

D 15
	ip = ialloc(u.u_pdir->i_dev);
E 15
I 15
	if ((mode & IFMT) == IFDIR)
		ipref = dirpref(u.u_pdir->i_fs);
	else
		ipref = u.u_pdir->i_number;
	ip = ialloc(u.u_pdir, ipref, mode);
E 15
D 12
	if(ip == NULL) {
E 12
I 12
	if (ip == NULL) {
E 12
		iput(u.u_pdir);
		return(NULL);
	}
I 23
#ifdef	QUOTA
	if (ip->i_dquot != NODQUOT)
		panic("maknode: dquot");
#endif
E 23
	ip->i_flag |= IACC|IUPD|ICHG;
D 12
	if((mode&IFMT) == 0)
E 12
I 12
D 15
	if ((mode&IFMT) == 0)
E 15
I 15
	if ((mode & IFMT) == 0)
E 15
E 12
		mode |= IFREG;
	ip->i_mode = mode & ~u.u_cmask;
	ip->i_nlink = 1;
	ip->i_uid = u.u_uid;
D 13
	ip->i_gid = u.u_gid;
E 13
I 13
	ip->i_gid = u.u_pdir->i_gid;
I 23
#ifdef	QUOTA
	ip->i_dquot = inoquota(ip);
#endif
E 23
E 13
I 5

	/*
	 * Make sure inode goes to disk before directory entry.
	 */
	iupdat(ip, &time, &time, 1);
D 15

E 15
E 5
	wdir(ip);
I 15
	if (u.u_error) {
		/*
		 * write error occurred trying to update directory
		 * so must deallocate the inode
		 */
		ip->i_nlink = 0;
		ip->i_flag |= ICHG;
		iput(ip);
		return(NULL);
	}
E 15
	return(ip);
}

/*
 * Write a directory entry with
 * parameters left as side effects
 * to a call to namei.
 */
wdir(ip)
D 12
struct inode *ip;
E 12
I 12
	struct inode *ip;
E 12
{
I 15
	register struct direct *dp, *ndp;
	struct fs *fs;
	struct buf *bp;
	int lbn, bn, base;
	int loc, dsize, spccnt, newsize;
	char *dirbuf;
E 15

	u.u_dent.d_ino = ip->i_number;
D 15
	bcopy((caddr_t)u.u_dbuf, (caddr_t)u.u_dent.d_name, DIRSIZ);
	u.u_count = sizeof(struct direct);
E 15
	u.u_segflg = 1;
D 15
	u.u_base = (caddr_t)&u.u_dent;
	writei(u.u_pdir);
E 15
I 15
	newsize = DIRSIZ(&u.u_dent);
	/*
	 * if u.u_count == 0, a new directory block must be allocated.
	 */
	if (u.u_count == 0) {
		u.u_dent.d_reclen = DIRBLKSIZ;
		u.u_count = newsize;
		u.u_base = (caddr_t)&u.u_dent;
I 24
/*ZZ*/if((u.u_offset&0x1ff))panic("wdir: newblk");
E 24
		writei(u.u_pdir);
		iput(u.u_pdir);
		return;
	}
	/*
	 * must read in an existing directory block
	 * to prepare to place the new entry into it.
	 */
	fs = u.u_pdir->i_fs;
	lbn = lblkno(fs, u.u_offset);
	base = blkoff(fs, u.u_offset);
	bn = fsbtodb(fs, bmap(u.u_pdir, lbn, B_WRITE, base + u.u_count));
	if (u.u_offset + u.u_count > u.u_pdir->i_size)
I 24
/*ZZ*/{if((u.u_offset+u.u_count-1&~0x1ff)!=(u.u_pdir->i_size-1&~0x1ff))
/*ZZ*/  printf("wdir i_size dir %s/%d (of=%d,cnt=%d,psz=%d))\n",
/*ZZ*/       u.u_pdir->i_fs->fs_fsmnt,u.u_pdir->i_number,u.u_offset,
/*ZZ*/       u.u_count,u.u_pdir->i_size);
E 24
		u.u_pdir->i_size = u.u_offset + u.u_count;
I 24
/*ZZ*/}
E 24
	bp = bread(u.u_pdir->i_dev, bn, blksize(fs, u.u_pdir, lbn));
	if (bp->b_flags & B_ERROR) {
		brelse(bp);
		return;
	}
	dirbuf = bp->b_un.b_addr + base;
	dp = (struct direct *)dirbuf;
	dsize = DIRSIZ(dp);
	spccnt = dp->d_reclen - dsize;
	/*
	 * if there is insufficient room to make an entry at this point
	 * namei insures that compacting from u.u_offset for u.u_count
	 * bytes will provide the necessary space.
	 */
	for (loc = dp->d_reclen; loc < u.u_count; ) {
		ndp = (struct direct *)(dirbuf + loc);
		if (dp->d_ino == 0) {
			spccnt += dsize;
		} else {
			dp->d_reclen = dsize;
			dp = (struct direct *)((char *)dp + dsize);
		}
		dsize = DIRSIZ(ndp);
		spccnt += ndp->d_reclen - dsize;
I 24
/*ZZ*/if(spccnt>512)panic("wdir spccnt");
/*ZZ*/if((loc&~0x1ff)!=(loc+ndp->d_reclen-1&~0x1ff))
/*ZZ*/printf("wdir: compact loc %d reclen %d (dir %s/%d)\n",loc,ndp->d_reclen,
/*ZZ*/u.u_pdir->i_fs->fs_fsmnt,u.u_pdir->i_number);
E 24
		loc += ndp->d_reclen;
		bcopy(ndp, dp, dsize);
	}
	/*
	 * Update the pointer fields in the previous entry (if any),
	 * copy in the new entry, and write out the block.
	 */
	if (dp->d_ino == 0) {
		if (spccnt + dsize < newsize)
D 24
			panic("wdir: compact failed");
E 24
I 24
			panic("wdir: compact failed (1)");
/*ZZ*/if(spccnt+dsize>512)panic("wdir: compact screwup");
E 24
		u.u_dent.d_reclen = spccnt + dsize;
	} else {
		if (spccnt < newsize)
D 24
			panic("wdir: compact failed");
E 24
I 24
			panic("wdir: compact failed (2)");
E 24
		u.u_dent.d_reclen = spccnt;
I 24
/*ZZ*/if ((((char *)dp-bp->b_un.b_addr)&0x1ff)+dsize>512) panic("wdir: reclen");
E 24
		dp->d_reclen = dsize;
		dp = (struct direct *)((char *)dp + dsize);
	}
I 24
/*ZZ*/if((((char*)dp-bp->b_un.b_addr)&0x1ff)+u.u_dent.d_reclen>512)panic("wdir: botch");
E 24
	bcopy(&u.u_dent, dp, newsize);
	bwrite(bp);
	u.u_pdir->i_flag |= IUPD|ICHG;
E 15
	iput(u.u_pdir);
E 25
I 18
}

/*
D 62
D 63
 * remove any inodes in the inode cache belonging to dev
E 63
I 63
 * Remove any inodes in the inode cache belonging to dev.
E 63
E 62
I 62
 * Remove any inodes in the inode cache belonging to dev.
E 62
 *
 * There should not be any active ones, return error if any are found
D 62
D 63
 * (nb: this is a user error, not a system err)
 *
 * Also, count the references to dev by block devices - this really
 * has nothing to do with the object of the procedure, but as we have
 * to scan the inode table here anyway, we might as well get the
 * extra benefit.
 *
 * this is called from sumount()/sys3.c when dev is being unmounted
E 63
I 63
 * (nb: this is a user error, not a system err).
E 63
E 62
I 62
 * (nb: this is a user error, not a system err).
E 62
 */
I 23
D 27
#ifdef	QUOTA
E 27
I 27
#ifdef QUOTA
E 27
D 24
iflush(dev, qi);
E 24
I 24
iflush(dev, iq)
E 24
	dev_t dev;
D 24
	struct inode *qi;
E 24
I 24
	struct inode *iq;
E 24
#else
E 23
iflush(dev)
	dev_t dev;
I 23
#endif
E 23
{
D 19
	register struct inode *ip;	/* known to be r11 - see 'asm' below */
E 19
I 19
	register struct inode *ip;
E 19
D 62
D 63
	register open = 0;
E 63
E 62

	for (ip = inode; ip < inodeNINODE; ip++) {
I 23
D 27
#ifdef	QUOTA
E 27
I 27
#ifdef QUOTA
E 27
		if (ip != iq && ip->i_dev == dev)
#else
E 23
		if (ip->i_dev == dev)
I 23
#endif
E 23
			if (ip->i_count)
D 62
D 63
				return(-1);
E 63
I 63
				return (EBUSY);
E 63
E 62
I 62
				return (EBUSY);
E 62
			else {
D 19
#ifndef	UNFAST
				asm("remque	(r11),r0");
#else
				ip->i_back->i_forw = ip->i_forw;
				ip->i_forw->i_back = ip->i_back;
#endif
E 19
I 19
				remque(ip);
E 19
				ip->i_forw = ip;
				ip->i_back = ip;
				/*
				 * as i_count == 0, the inode was on the free
				 * list already, just leave it there, it will
				 * fall off the bottom eventually. We could
				 * perhaps move it to the head of the free
				 * list, but as umounts are done so
				 * infrequently, we would gain very little,
				 * while making the code bigger.
				 */
I 23
D 27
#ifdef	QUOTA
E 27
I 27
#ifdef QUOTA
E 27
				dqrele(ip->i_dquot);
				ip->i_dquot = NODQUOT;
#endif
E 23
			}
D 62
D 63
		else if (ip->i_count && (ip->i_mode&IFMT)==IFBLK &&
		    ip->i_rdev == dev)
			open++;
E 63
E 62
	}
D 62
D 63
	return (open);
E 63
I 63
	return (0);
E 63
E 62
I 62
	return (0);
E 62
E 18
}
I 10

D 12
#ifdef plock
#undef plock
E 12
I 12
D 30
#ifdef ilock
#undef ilock
E 12
#endif
D 12
#ifdef prele
#undef prele
E 12
I 12
D 16
#ifdef irele
#undef irele
E 16
I 16
#ifdef iunlock
#undef iunlock
E 16
E 12
#endif
E 30
/*
D 12
 * Lock an inode (should be called ilock).
 * If its already locked,
 * set the WANT bit and sleep.
E 12
I 12
 * Lock an inode. If its already locked, set the WANT bit and sleep.
E 12
 */
D 12
plock(ip)
register struct inode *ip;
E 12
I 12
ilock(ip)
	register struct inode *ip;
E 12
{

D 12
	while(ip->i_flag&ILOCK) {
E 12
I 12
D 30
	while (ip->i_flag&ILOCK) {
E 12
		ip->i_flag |= IWANT;
		sleep((caddr_t)ip, PINOD);
	}
	ip->i_flag |= ILOCK;
E 30
I 30
	ILOCK(ip);
E 30
}

/*
D 12
 * Unlock an inode.
 * If WANT bit is on,
 * wakeup.
E 12
I 12
 * Unlock an inode.  If WANT bit is on, wakeup.
E 12
 */
D 12
prele(ip)
register struct inode *ip;
E 12
I 12
D 16
irele(ip)
E 16
I 16
iunlock(ip)
E 16
	register struct inode *ip;
E 12
{

D 30
	ip->i_flag &= ~ILOCK;
D 12
	if(ip->i_flag&IWANT) {
E 12
I 12
	if (ip->i_flag&IWANT) {
E 12
		ip->i_flag &= ~IWANT;
		wakeup((caddr_t)ip);
	}
E 30
I 30
	IUNLOCK(ip);
E 30
}
E 10
E 1
