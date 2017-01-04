h35645
s 00001/00001/00418
d D 7.8 99/10/02 11:28:53 msokolov 25 24
c use the NOSUBSINST define to determine when to supply scanc in C instead of
c specific CPU types
e
s 00001/00001/00418
d D 7.7 89/05/01 14:17:21 bostic 24 23
c add VAX650 to the processors needs scanc
e
s 00004/00002/00415
d D 7.6 88/05/19 22:09:46 karels 23 22
c avoid race between mountfs and update
e
s 00004/00004/00413
d D 7.5 87/06/21 15:30:51 mckusick 22 21
c geteblk => malloc, so m_bufp => m_fs as it should be
e
s 00000/00000/00417
d D 7.4 87/04/02 15:49:32 karels 21 19
c working with pack labels
e
s 00012/00000/00417
d D 7.3.1.1 87/04/02 15:41:25 karels 20 19
c add ifdefs for dev_bsize (almost working)
e
s 00000/00001/00417
d D 7.3 87/03/10 14:20:53 mckusick 19 18
c only set ICHG when fsync'ing a file descriptor that is open for writing
e
s 00005/00005/00413
d D 7.2 86/11/03 12:00:42 karels 18 17
c merge in tahoe support
e
s 00001/00001/00417
d D 7.1 86/06/05 00:14:23 mckusick 17 16
c 4.3BSD release version
e
s 00004/00001/00414
d D 6.11 86/04/28 09:25:12 kridle 16 15
c Added code to define scanc if VAX630 is defined.
e
s 00003/00003/00412
d D 6.10 86/02/21 11:35:50 karels 15 14
c make those switches int!
e
s 00004/00003/00411
d D 6.9 86/02/20 15:21:05 karels 14 13
c lint and cleanups from Sam
e
s 00007/00001/00407
d D 6.8 85/06/08 14:53:46 mckusick 13 12
c Add copyright
e
s 00041/00000/00367
d D 6.7 85/05/27 15:00:19 mckusick 12 11
c add C definitions of special vax hardware
e
s 00000/00002/00367
d D 6.6 85/03/19 20:49:46 mckusick 11 10
c eliminate extraneous include of conf.h
e
s 00011/00011/00358
d D 6.5 84/08/29 20:26:55 bloom 10 9
c Change to includes.  no more ../h
e
s 00038/00008/00331
d D 6.4 84/08/09 11:22:55 mckusick 9 8
c fix `fsync' to work efficiently with big files
e
s 00001/00001/00338
d D 6.3 84/07/10 15:17:13 mckusick 8 7
c parenthesis botch (from kre)
e
s 00002/00001/00337
d D 6.2 84/02/07 17:34:56 karels 7 6
c avoid iupdate/iput if unmodified (in update)
e
s 00000/00000/00338
d D 6.1 83/07/29 06:44:31 sam 6 5
c 4.2 distribution
e
s 00002/00000/00336
d D 4.5 83/03/21 19:52:36 sam 5 4
c don't forget the inode 
e
s 00001/00002/00335
d D 4.4 82/12/17 11:48:58 sam 4 3
c sun merge
e
s 00187/00000/00150
d D 4.3 82/11/13 22:53:31 sam 3 2
c merge of 4.1b and 4.1c
e
s 00001/00001/00149
d D 4.2 82/10/21 20:59:25 root 2 1
c lint
e
s 00150/00000/00000
d D 4.1 82/10/20 03:06:12 root 1 0
c date and time created 82/10/20 03:06:12 by root
e
u
U
f b 
t
T
I 1
D 13
/*	%M%	%I%	%E%	*/
E 13
I 13
/*
D 17
 * Copyright (c) 1982 Regents of the University of California.
E 17
I 17
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 17
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 13

#ifdef KERNEL
D 10
#include "../h/param.h"
I 3
#include "../h/systm.h"
#include "../h/mount.h"
E 3
#include "../h/fs.h"
I 3
#include "../h/conf.h"
#include "../h/buf.h"
#include "../h/inode.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/quota.h"
#include "../h/kernel.h"
E 10
I 10
#include "param.h"
#include "systm.h"
#include "mount.h"
#include "fs.h"
D 11
#include "conf.h"
E 11
#include "buf.h"
#include "inode.h"
#include "dir.h"
#include "user.h"
#include "quota.h"
#include "kernel.h"
E 10
E 3
#else
#include <sys/param.h>
I 3
#include <sys/systm.h>
#include <sys/mount.h>
E 3
#include <sys/fs.h>
I 3
D 11
#include <sys/conf.h>
E 11
#include <sys/buf.h>
#include <sys/inode.h>
#include <sys/dir.h>
#include <sys/user.h>
#include <sys/quota.h>
D 4
#include <sys/kernel.h>
E 4
E 3
#endif

I 3
#ifdef KERNEL
int	syncprt = 0;

/*
 * Update is the internal name of 'sync'.  It goes through the disk
 * queues to initiate sandbagged IO; goes through the inodes to write
 * modified nodes; and it goes through the mount table to initiate
 * the writing of the modified super blocks.
 */
update()
{
	register struct inode *ip;
	register struct mount *mp;
	struct fs *fs;

	if (syncprt)
		bufstats();
	if (updlock)
		return;
	updlock++;
	/*
	 * Write back modified superblocks.
	 * Consistency check that the superblock
	 * of each file system is still in the buffer cache.
	 */
	for (mp = &mount[0]; mp < &mount[NMOUNT]; mp++) {
D 4
		if (mp->m_bufp == NULL)
E 4
I 4
D 22
		if (mp->m_bufp == NULL || mp->m_dev == NODEV)
E 22
I 22
D 23
		if (mp->m_fs == NULL || mp->m_dev == NODEV)
E 23
I 23
		if (mp->m_fs == NULL || mp->m_fs == (struct fs *)1)   /* XXX */
E 23
E 22
E 4
			continue;
D 22
		fs = mp->m_bufp->b_un.b_fs;
E 22
I 22
		fs = mp->m_fs;
E 22
		if (fs->fs_fmod == 0)
			continue;
		if (fs->fs_ronly != 0) {		/* XXX */
			printf("fs = %s\n", fs->fs_fsmnt);
			panic("update: rofs mod");
		}
		fs->fs_fmod = 0;
		fs->fs_time = time.tv_sec;
		sbupdate(mp);
	}
	/*
	 * Write back each (modified) inode.
	 */
	for (ip = inode; ip < inodeNINODE; ip++) {
D 7
		if ((ip->i_flag & ILOCKED) != 0 || ip->i_count == 0)
E 7
I 7
		if ((ip->i_flag & ILOCKED) != 0 || ip->i_count == 0 ||
D 8
		    (ip->i_flag & (IACC|IUPD|ICHG) == 0))
E 8
I 8
		    (ip->i_flag & (IMOD|IACC|IUPD|ICHG)) == 0)
E 8
E 7
			continue;
		ip->i_flag |= ILOCKED;
		ip->i_count++;
		iupdat(ip, &time, &time, 0);
		iput(ip);
	}
	updlock = 0;
	/*
	 * Force stale buffer cache information to be flushed,
	 * for all devices.
	 */
	bflush(NODEV);
}

/*
 * Flush all the blocks associated with an inode.
D 9
 * Note that we make a more stringent check of
 * writing out any block in the buffer pool that may
 * overlap the inode. This brings the inode up to
 * date with recent mods to the cooked device.
E 9
I 9
 * There are two strategies based on the size of the file;
 * large files are those with more than (nbuf / 2) blocks.
 * Large files
 * 	Walk through the buffer pool and push any dirty pages
 *	associated with the device on which the file resides.
 * Small files
 *	Look up each block in the file to see if it is in the 
 *	buffer pool writing any that are found to disk.
 *	Note that we make a more stringent check of
 *	writing out any block in the buffer pool that may
 *	overlap the inode. This brings the inode up to
 *	date with recent mods to the cooked device.
E 9
 */
syncip(ip)
	register struct inode *ip;
{
	register struct fs *fs;
D 9
	long lbn, lastlbn;
E 9
I 9
	register struct buf *bp;
	struct buf *lastbufp;
D 14
	long lbn, lastlbn, s;
E 14
I 14
	long lbn, lastlbn;
	int s;
E 14
E 9
	daddr_t blkno;

	fs = ip->i_fs;
	lastlbn = howmany(ip->i_size, fs->fs_bsize);
D 9
	for (lbn = 0; lbn < lastlbn; lbn++) {
		blkno = fsbtodb(fs, bmap(ip, lbn, B_READ));
		blkflush(ip->i_dev, blkno, blksize(fs, ip, lbn));
E 9
I 9
	if (lastlbn < nbuf / 2) {
I 20
#ifdef SECSIZE
		lastlbn--;
		s = fsbtodb(fs, fs->fs_frag);
E 20
		for (lbn = 0; lbn < lastlbn; lbn++) {
			blkno = fsbtodb(fs, bmap(ip, lbn, B_READ));
I 20
			blkflush(ip->i_dev, blkno, s);
		}
		if (lastlbn >= 0)
			blkflush(ip->i_dev, blkno, (int)fsbtodb(fs,
			    blksize(fs, ip, lbn) / fs->fs_fsize));
#else SECSIZE
		for (lbn = 0; lbn < lastlbn; lbn++) {
			blkno = fsbtodb(fs, bmap(ip, lbn, B_READ));
E 20
			blkflush(ip->i_dev, blkno, blksize(fs, ip, lbn));
		}
I 20
#endif SECSIZE
E 20
	} else {
		lastbufp = &buf[nbuf];
		for (bp = buf; bp < lastbufp; bp++) {
			if (bp->b_dev != ip->i_dev ||
			    (bp->b_flags & B_DELWRI) == 0)
				continue;
D 14
			s = spl6();
E 14
I 14
			s = splbio();
E 14
			if (bp->b_flags & B_BUSY) {
				bp->b_flags |= B_WANTED;
				sleep((caddr_t)bp, PRIBIO+1);
				splx(s);
				bp--;
				continue;
			}
			splx(s);
			notavail(bp);
			bwrite(bp);
		}
E 9
	}
I 5
D 19
	ip->i_flag |= ICHG;
E 19
	iupdat(ip, &time, &time, 1);
E 5
}
#endif

E 3
extern	int around[9];
extern	int inside[9];
extern	u_char *fragtbl[];

/*
 * Update the frsum fields to reflect addition or deletion 
 * of some frags.
 */
fragacct(fs, fragmap, fraglist, cnt)
	struct fs *fs;
	int fragmap;
	long fraglist[];
	int cnt;
{
	int inblk;
	register int field, subfield;
	register int siz, pos;

	inblk = (int)(fragtbl[fs->fs_frag][fragmap]) << 1;
	fragmap <<= 1;
	for (siz = 1; siz < fs->fs_frag; siz++) {
		if ((inblk & (1 << (siz + (fs->fs_frag % NBBY)))) == 0)
			continue;
		field = around[siz];
		subfield = inside[siz];
		for (pos = siz; pos <= fs->fs_frag; pos++) {
			if ((fragmap & field) == subfield) {
				fraglist[siz] += cnt;
				pos += siz;
				field <<= siz;
				subfield <<= siz;
			}
			field <<= 1;
			subfield <<= 1;
		}
	}
}

#ifdef KERNEL
/*
 * Check that a specified block number is in range.
 */
badblock(fs, bn)
	register struct fs *fs;
	daddr_t bn;
{

	if ((unsigned)bn >= fs->fs_size) {
		printf("bad block %d, ", bn);
		fserr(fs, "bad block");
		return (1);
	}
	return (0);
}
#endif

/*
 * block operations
 *
 * check if a block is available
 */
isblock(fs, cp, h)
	struct fs *fs;
	unsigned char *cp;
	daddr_t h;
{
	unsigned char mask;

D 15
	switch (fs->fs_frag) {
E 15
I 15
	switch ((int)fs->fs_frag) {
E 15
	case 8:
		return (cp[h] == 0xff);
	case 4:
		mask = 0x0f << ((h & 0x1) << 2);
		return ((cp[h >> 1] & mask) == mask);
	case 2:
		mask = 0x03 << ((h & 0x3) << 1);
		return ((cp[h >> 2] & mask) == mask);
	case 1:
		mask = 0x01 << (h & 0x7);
		return ((cp[h >> 3] & mask) == mask);
	default:
		panic("isblock");
		return (NULL);
	}
}

/*
 * take a block out of the map
 */
clrblock(fs, cp, h)
	struct fs *fs;
D 2
	unsigned char *cp;
E 2
I 2
	u_char *cp;
E 2
	daddr_t h;
{

D 15
	switch ((fs)->fs_frag) {
E 15
I 15
	switch ((int)fs->fs_frag) {
E 15
	case 8:
		cp[h] = 0;
		return;
	case 4:
		cp[h >> 1] &= ~(0x0f << ((h & 0x1) << 2));
		return;
	case 2:
		cp[h >> 2] &= ~(0x03 << ((h & 0x3) << 1));
		return;
	case 1:
		cp[h >> 3] &= ~(0x01 << (h & 0x7));
		return;
	default:
		panic("clrblock");
	}
}

/*
 * put a block into the map
 */
setblock(fs, cp, h)
	struct fs *fs;
	unsigned char *cp;
	daddr_t h;
{

D 15
	switch (fs->fs_frag) {
E 15
I 15
	switch ((int)fs->fs_frag) {
E 15

	case 8:
		cp[h] = 0xff;
		return;
	case 4:
		cp[h >> 1] |= (0x0f << ((h & 0x1) << 2));
		return;
	case 2:
		cp[h >> 2] |= (0x03 << ((h & 0x3) << 1));
		return;
	case 1:
		cp[h >> 3] |= (0x01 << (h & 0x7));
		return;
	default:
		panic("setblock");
	}
}
I 3

#ifdef KERNEL
/*
 * Getfs maps a device number into a pointer to the incore super block.
 *
 * The algorithm is a linear search through the mount table. A
 * consistency check of the super block magic number is performed.
I 23
 * Filesystems still working on a mount are skipped.
E 23
 *
 * panic: no fs -- the device is not mounted.
 *	this "cannot happen"
 */
struct fs *
getfs(dev)
	dev_t dev;
{
	register struct mount *mp;
	register struct fs *fs;

	for (mp = &mount[0]; mp < &mount[NMOUNT]; mp++) {
D 22
		if (mp->m_bufp == NULL || mp->m_dev != dev)
E 22
I 22
D 23
		if (mp->m_fs == NULL || mp->m_dev != dev)
E 23
I 23
		if (mp->m_dev != dev || mp->m_fs == NULL ||
		    mp->m_fs == (struct fs *)1)			/* XXX */
E 23
E 22
			continue;
D 22
		fs = mp->m_bufp->b_un.b_fs;
E 22
I 22
		fs = mp->m_fs;
E 22
		if (fs->fs_magic != FS_MAGIC) {
			printf("dev = 0x%x, fs = %s\n", dev, fs->fs_fsmnt);
			panic("getfs: bad magic");
		}
		return (fs);
	}
	printf("dev = 0x%x\n", dev);
	panic("getfs: no fs");
	return (NULL);
}

/*
 * Getfsx returns the index in the file system
 * table of the specified device.  The swap device
 * is also assigned a pseudo-index.  The index may
 * be used as a compressed indication of the location
 * of a block, recording
 *	<getfsx(dev),blkno>
 * rather than
 *	<dev, blkno>
 * provided the information need remain valid only
 * as long as the file system is mounted.
 */
getfsx(dev)
	dev_t dev;
{
	register struct mount *mp;

	if (dev == swapdev)
		return (MSWAPX);
	for(mp = &mount[0]; mp < &mount[NMOUNT]; mp++)
		if (mp->m_dev == dev)
			return (mp - &mount[0]);
	return (-1);
}

/*
 * Print out statistics on the current allocation of the buffer pool.
 * Can be enabled to print out on every ``sync'' by setting "syncprt"
 * above.
 */
bufstats()
{
	int s, i, j, count;
	register struct buf *bp, *dp;
	int counts[MAXBSIZE/CLBYTES+1];
	static char *bname[BQUEUES] = { "LOCKED", "LRU", "AGE", "EMPTY" };

	for (bp = bfreelist, i = 0; bp < &bfreelist[BQUEUES]; bp++, i++) {
		count = 0;
		for (j = 0; j <= MAXBSIZE/CLBYTES; j++)
			counts[j] = 0;
D 14
		s = spl6();
E 14
I 14
		s = splbio();
E 14
		for (dp = bp->av_forw; dp != bp; dp = dp->av_forw) {
			counts[dp->b_bufsize/CLBYTES]++;
			count++;
		}
		splx(s);
		printf("%s: total-%d", bname[i], count);
		for (j = 0; j <= MAXBSIZE/CLBYTES; j++)
			if (counts[j] != 0)
				printf(", %d-%d", j * CLBYTES, counts[j]);
		printf("\n");
	}
}
#endif
I 12

D 16
#if !defined(vax)
E 16
I 16
D 18
#if !defined(vax) || defined(VAX630)
E 18
I 18
D 24
#if (!defined(vax) && !defined(tahoe)) || defined(VAX630)
E 24
I 24
D 25
#if (!defined(vax) && !defined(tahoe)) || defined(VAX630) || defined(VAX650)
E 25
I 25
#if (!defined(vax) && !defined(tahoe)) || defined(NOSUBSINST)
E 25
E 24
E 18
E 16
/*
D 18
 * C definitions of special vax instructions.
E 18
I 18
 * C definitions of special instructions.
 * Normally expanded with inline.
E 18
 */
scanc(size, cp, table, mask)
	u_int size;
	register u_char *cp, table[];
	register u_char mask;
{
	register u_char *end = &cp[size];

	while (cp < end && (table[*cp] & mask) == 0)
		cp++;
	return (end - cp);
}
I 16
D 18

E 18
#endif
D 18
#if !defined(vax)
E 18
E 16

I 18
#if !defined(vax) && !defined(tahoe)
E 18
skpc(mask, size, cp)
	register u_char mask;
	u_int size;
	register u_char *cp;
{
	register u_char *end = &cp[size];

	while (cp < end && *cp == mask)
		cp++;
	return (end - cp);
}

locc(mask, size, cp)
	register u_char mask;
	u_int size;
	register u_char *cp;
{
	register u_char *end = &cp[size];

	while (cp < end && *cp != mask)
		cp++;
	return (end - cp);
}
D 18
#endif vax
E 18
I 18
#endif
E 18
E 12
E 3
E 1
