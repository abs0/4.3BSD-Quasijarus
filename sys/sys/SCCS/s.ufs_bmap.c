h19968
s 00000/00000/00213
d D 7.2 87/04/02 15:49:18 karels 11 9
c working with pack labels
e
s 00005/00000/00213
d D 7.1.1.1 87/04/02 15:41:12 karels 10 9
c add ifdefs for dev_bsize (almost working)
e
s 00001/00001/00212
d D 7.1 86/06/05 00:12:18 mckusick 9 8
c 4.3BSD release version
e
s 00007/00001/00206
d D 6.4 85/06/08 14:50:46 mckusick 8 7
c Add copyright
e
s 00000/00001/00207
d D 6.3 85/03/19 20:48:38 mckusick 7 6
c eliminate extraneous include of conf.h
e
s 00009/00009/00199
d D 6.2 84/08/29 20:25:45 bloom 6 5
c Change to includes.  no more ../h
e
s 00000/00000/00208
d D 6.1 83/07/29 06:41:43 sam 5 4
c 4.2 distribution
e
s 00002/00000/00206
d D 5.4 83/03/15 09:48:22 sam 4 3
c watch return val from realloccg (from kre)
e
s 00010/00009/00196
d D 5.3 82/11/13 22:52:45 sam 3 2
c merge of 4.1b and 4.1c
e
s 00025/00021/00180
d D 5.2 82/09/25 22:49:31 mckusick 2 1
c rearrange blkpref to centralize and make smarter about block layout
e
s 00201/00000/00000
d D 5.1 82/07/15 20:54:13 root 1 0
c date and time created 82/07/15 20:54:13 by root
e
u
U
f b 
t
T
I 1
D 8
/*	%M%	%I%	%E%	*/
E 8
I 8
/*
D 9
 * Copyright (c) 1982 Regents of the University of California.
E 9
I 9
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 8

D 6
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/conf.h"
#include "../h/inode.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/buf.h"
#include "../h/proc.h"
#include "../h/fs.h"
E 6
I 6
#include "param.h"
#include "systm.h"
D 7
#include "conf.h"
E 7
#include "inode.h"
#include "dir.h"
#include "user.h"
#include "buf.h"
#include "proc.h"
#include "fs.h"
E 6

/*
 * Bmap defines the structure of file system storage
 * by returning the physical block number on a device given the
 * inode and the logical block number in a file.
 * When convenient, it also leaves the physical
 * block number of the next block of the file in rablock
 * for use in read-ahead.
 */
/*VARARGS3*/
daddr_t
bmap(ip, bn, rwflg, size)
	register struct inode *ip;
	daddr_t bn;
	int rwflg;
	int size;	/* supplied only when rwflg == B_WRITE */
{
	register int i;
	int osize, nsize;
	struct buf *bp, *nbp;
	struct fs *fs;
	int j, sh;
D 2
	daddr_t nb, *bap, pref, blkpref();
E 2
I 2
	daddr_t nb, lbn, *bap, pref, blkpref();
E 2

	if (bn < 0) {
		u.u_error = EFBIG;
		return ((daddr_t)0);
	}
	fs = ip->i_fs;
	rablock = 0;
	rasize = 0;		/* conservative */

	/*
	 * If the next write will extend the file into a new block,
	 * and the file is currently composed of a fragment
	 * this fragment has to be extended to be a full block.
	 */
	nb = lblkno(fs, ip->i_size);
	if (rwflg == B_WRITE && nb < NDADDR && nb < bn) {
		osize = blksize(fs, ip, nb);
		if (osize < fs->fs_bsize && osize > 0) {
			bp = realloccg(ip, ip->i_db[nb],
D 2
				nb == 0 ? 0 : ip->i_db[nb - 1] + fs->fs_frag,
E 2
I 2
D 3
				blkpref(ip, nb, nb, &ip->i_db[0]),
E 2
				osize, fs->fs_bsize);
E 3
I 3
				blkpref(ip, nb, (int)nb, &ip->i_db[0]),
				osize, (int)fs->fs_bsize);
I 4
			if (bp == NULL)
				return ((daddr_t)-1);
E 4
E 3
			ip->i_size = (nb + 1) * fs->fs_bsize;
			ip->i_db[nb] = dbtofsb(fs, bp->b_blkno);
			ip->i_flag |= IUPD|ICHG;
			bdwrite(bp);
		}
	}
	/*
	 * The first NDADDR blocks are direct blocks
	 */
	if (bn < NDADDR) {
D 2
		i = bn;
		nb = ip->i_db[i];
E 2
I 2
		nb = ip->i_db[bn];
E 2
		if (rwflg == B_READ) {
			if (nb == 0)
				return ((daddr_t)-1);
			goto gotit;
		}
D 2
		if (nb == 0 || ip->i_size < (i + 1) * fs->fs_bsize) {
E 2
I 2
		if (nb == 0 || ip->i_size < (bn + 1) * fs->fs_bsize) {
E 2
			if (nb != 0) {
				/* consider need to reallocate a frag */
				osize = fragroundup(fs, blkoff(fs, ip->i_size));
				nsize = fragroundup(fs, size);
				if (nsize <= osize)
					goto gotit;
D 2
				bp = realloccg(ip, nb, i == 0 ?
					0 : ip->i_db[i - 1] + fs->fs_frag,
E 2
I 2
				bp = realloccg(ip, nb,
D 3
					blkpref(ip, bn, bn, &ip->i_db[0]),
E 3
I 3
					blkpref(ip, bn, (int)bn, &ip->i_db[0]),
E 3
E 2
					osize, nsize);
			} else {
D 2
				if (ip->i_size < (i + 1) * fs->fs_bsize)
E 2
I 2
				if (ip->i_size < (bn + 1) * fs->fs_bsize)
E 2
					nsize = fragroundup(fs, size);
				else
					nsize = fs->fs_bsize;
D 2
				bp = alloc(ip, i > 0 ?
					ip->i_db[i - 1] + fs->fs_frag : 0,
E 2
I 2
				bp = alloc(ip,
D 3
					blkpref(ip, bn, bn, &ip->i_db[0]),
E 3
I 3
					blkpref(ip, bn, (int)bn, &ip->i_db[0]),
E 3
E 2
					nsize);
			}
			if (bp == NULL)
				return ((daddr_t)-1);
			nb = dbtofsb(fs, bp->b_blkno);
			if ((ip->i_mode&IFMT) == IFDIR)
				/*
				 * Write directory blocks synchronously
				 * so they never appear with garbage in
				 * them on the disk.
				 */
				bwrite(bp);
			else
				bdwrite(bp);
D 2
			ip->i_db[i] = nb;
E 2
I 2
			ip->i_db[bn] = nb;
E 2
			ip->i_flag |= IUPD|ICHG;
		}
gotit:
D 2
		if (i < NDADDR - 1) {
			rablock = fsbtodb(fs, ip->i_db[i+1]);
			rasize = blksize(fs, ip, i+1);
E 2
I 2
		if (bn < NDADDR - 1) {
			rablock = fsbtodb(fs, ip->i_db[bn + 1]);
			rasize = blksize(fs, ip, bn + 1);
E 2
		}
		return (nb);
	}

	/*
	 * Determine how many levels of indirection.
	 */
I 2
	pref = 0;
E 2
	sh = 1;
I 2
	lbn = bn;
E 2
	bn -= NDADDR;
	for (j = NIADDR; j>0; j--) {
		sh *= NINDIR(fs);
		if (bn < sh)
			break;
		bn -= sh;
	}
	if (j == 0) {
		u.u_error = EFBIG;
		return ((daddr_t)0);
	}

	/*
	 * fetch the first indirect block
	 */
	nb = ip->i_ib[NIADDR - j];
	if (nb == 0) {
D 2
		if (rwflg==B_READ ||
		    (bp = alloc(ip, (daddr_t)0, fs->fs_bsize)) == NULL)
E 2
I 2
		if (rwflg == B_READ)
E 2
			return ((daddr_t)-1);
I 2
D 3
		pref = blkpref(ip, lbn, 0, 0);
	        bp = alloc(ip, pref, fs->fs_bsize);
E 3
I 3
		pref = blkpref(ip, lbn, 0, (daddr_t *)0);
	        bp = alloc(ip, pref, (int)fs->fs_bsize);
E 3
		if (bp == NULL)
			return ((daddr_t)-1);
E 2
		nb = dbtofsb(fs, bp->b_blkno);
		/*
		 * Write synchronously so that indirect blocks
		 * never point at garbage.
		 */
		bwrite(bp);
		ip->i_ib[NIADDR - j] = nb;
		ip->i_flag |= IUPD|ICHG;
	}

	/*
	 * fetch through the indirect blocks
	 */
	for (; j <= NIADDR; j++) {
I 10
#ifdef SECSIZE
		bp = bread(ip->i_dev, fsbtodb(fs, nb), (int)fs->fs_bsize,
		    fs->fs_dbsize);
#else SECSIZE
E 10
D 3
		bp = bread(ip->i_dev, fsbtodb(fs, nb), fs->fs_bsize);
E 3
I 3
		bp = bread(ip->i_dev, fsbtodb(fs, nb), (int)fs->fs_bsize);
I 10
#endif SECSIZE
E 10
E 3
		if (bp->b_flags & B_ERROR) {
			brelse(bp);
			return ((daddr_t)0);
		}
		bap = bp->b_un.b_daddr;
		sh /= NINDIR(fs);
		i = (bn / sh) % NINDIR(fs);
		nb = bap[i];
		if (nb == 0) {
			if (rwflg==B_READ) {
				brelse(bp);
				return ((daddr_t)-1);
			}
D 2
			if (i % (fs->fs_fsize / sizeof(daddr_t)) == 0 ||
			    bap[i - 1] == 0)
				pref = blkpref(ip->i_fs);
			else
				pref = bap[i - 1] + fs->fs_frag;
E 2
I 2
			if (pref == 0)
				if (j < NIADDR)
D 3
					pref = blkpref(ip, lbn, 0, 0);
E 3
I 3
					pref = blkpref(ip, lbn, 0,
						(daddr_t *)0);
E 3
				else
					pref = blkpref(ip, lbn, i, &bap[0]);
E 2
D 3
		        nbp = alloc(ip, pref, fs->fs_bsize);
E 3
I 3
		        nbp = alloc(ip, pref, (int)fs->fs_bsize);
E 3
			if (nbp == NULL) {
				brelse(bp);
				return ((daddr_t)-1);
			}
			nb = dbtofsb(fs, nbp->b_blkno);
			if (j < NIADDR || (ip->i_mode&IFMT) == IFDIR)
				/*
				 * Write synchronously so indirect blocks
				 * never point at garbage and blocks
				 * in directories never contain garbage.
				 */
				bwrite(nbp);
			else
				bdwrite(nbp);
			bap[i] = nb;
			bdwrite(bp);
		} else
			brelse(bp);
	}

	/*
	 * calculate read-ahead.
	 */
	if (i < NINDIR(fs) - 1) {
		rablock = fsbtodb(fs, bap[i+1]);
		rasize = fs->fs_bsize;
	}
	return (nb);
}
E 1
