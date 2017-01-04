h01244
s 00005/00003/00304
d D 7.11 88/05/24 19:26:08 mckusick 27 26
c lint
e
s 00013/00014/00294
d D 7.10 88/05/22 15:09:10 karels 26 25
c lint
e
s 00001/00000/00307
d D 7.9 88/05/19 22:09:44 karels 25 24
c avoid race between mountfs and update
e
s 00005/00002/00302
d D 7.8 88/05/02 00:03:35 mckusick 24 23
c add compatibility for dynamic cylinder groups;
c delete last reference to fs_dbsize
e
s 00046/00043/00258
d D 7.7 87/11/30 19:40:02 mckusick 23 22
c major cleanup of mountfs and fixed a bug too!
e
s 00019/00020/00282
d D 7.6 87/06/21 15:32:01 mckusick 22 21
c replace geteblk and wmemall with malloc to hold superblock related data
e
s 00001/00000/00301
d D 7.5 87/06/04 14:54:13 karels 21 20
c save cpg in pack label too
e
s 00001/00001/00300
d D 7.4 87/05/03 18:07:25 sam 20 19
c check ip before dereferencing (can only happen when called to mount root)
e
s 00034/00023/00267
d D 7.3 87/04/02 15:49:26 karels 19 17
c working with pack labels
e
s 00091/00023/00267
d D 7.2.1.1 87/04/02 15:41:18 karels 18 17
c add ifdefs for dev_bsize (almost working)
e
s 00003/00000/00287
d D 7.2 87/01/13 17:56:48 mckusick 17 16
c add sanity checks for old file systems
e
s 00001/00001/00286
d D 7.1 86/06/05 00:13:22 mckusick 16 15
c 4.3BSD release version
e
s 00002/00001/00285
d D 6.14 86/04/23 12:28:26 mckusick 15 14
c must invalidate any names for mounted on inode
e
s 00005/00003/00281
d D 6.13 86/02/18 12:34:07 karels 14 13
c don't close, binval on failed mount because already mounted.
e
s 00000/00001/00284
d D 6.12 85/09/04 13:32:39 bloom 13 12
c lint cleanup
e
s 00007/00001/00278
d D 6.11 85/06/08 14:52:23 mckusick 12 11
c Add copyright
e
s 00015/00002/00264
d D 6.10 85/05/22 19:55:32 mckusick 11 10
c differentiate several errors; close special device if mount fails
e
s 00001/00001/00265
d D 6.9 84/09/28 15:53:08 mckusick 10 9
c use macros
e
s 00011/00011/00255
d D 6.8 84/08/29 20:26:19 bloom 9 8
c Change to includes.  no more ../h
e
s 00001/00001/00265
d D 6.7 84/07/18 09:37:31 karels 8 7
c don't zero name, zero pad it.
e
s 00003/00002/00263
d D 6.6 84/07/08 22:35:12 mckusick 7 6
c use new interface to `copyinstr' and `copystr'
e
s 00021/00017/00244
d D 6.5 84/07/08 16:19:48 mckusick 6 5
c rework `namei' interface to eliminate global variables
e
s 00016/00009/00245
d D 6.4 84/06/26 13:51:02 karels 5 4
c check superblock magic, size before copying; better error codes
c from mount
e
s 00004/00002/00250
d D 6.3 84/02/07 14:53:05 karels 4 3
c missing iput's on errors
e
s 00002/00001/00250
d D 6.2 84/01/03 23:41:53 mckusick 3 2
c add system wide cacheing of path names in namei() (from kre)
e
s 00000/00000/00251
d D 6.1 83/07/29 06:43:19 sam 2 1
c 4.2 distribution
e
s 00251/00000/00000
d D 4.1 83/05/27 14:02:54 sam 1 0
c date and time created 83/05/27 14:02:54 by sam
e
u
U
f b 
t
T
I 1
D 12
/*	%M%	%I%	%E%	*/
E 12
I 12
/*
D 16
 * Copyright (c) 1982 Regents of the University of California.
E 16
I 16
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 16
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 12

D 9
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/inode.h"
#include "../h/proc.h"
#include "../h/fs.h"
#include "../h/buf.h"
#include "../h/mount.h"
#include "../h/file.h"
D 6
#include "../h/nami.h"
E 6
#include "../h/conf.h"
E 9
I 9
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "inode.h"
#include "proc.h"
#include "fs.h"
#include "buf.h"
#include "mount.h"
#include "file.h"
#include "conf.h"
I 19
#include "ioctl.h"
#include "disklabel.h"
#include "stat.h"
I 22
#include "malloc.h"
E 22
E 19
I 18
#include "ioctl.h"
#include "disklabel.h"
#include "stat.h"
E 18
E 9

smount()
{
	register struct a {
		char	*fspec;
		char	*freg;
		int	ronly;
D 6
	} *uap;
E 6
I 6
	} *uap = (struct a *)u.u_ap;
E 6
	dev_t dev;
	register struct inode *ip;
	register struct fs *fs;
D 13
	register char *cp;
E 13
I 6
	register struct nameidata *ndp = &u.u_nd;
I 7
	u_int len;
E 7
E 6

D 6
	uap = (struct a *)u.u_ap;
	u.u_error = getmdev(&dev);
E 6
I 6
	u.u_error = getmdev(&dev, uap->fspec);
E 6
	if (u.u_error)
		return;
D 6
	u.u_dirp = (caddr_t)uap->freg;
D 3
	ip = namei(uchar, LOOKUP, 1);
E 3
I 3
	ip = namei(uchar, LOOKUP | NOCACHE, 1);
E 6
I 6
D 15
	ndp->ni_nameiop = LOOKUP | NOCACHE | FOLLOW;
E 15
I 15
	ndp->ni_nameiop = LOOKUP | FOLLOW;
E 15
	ndp->ni_segflg = UIO_USERSPACE;
	ndp->ni_dirp = (caddr_t)uap->freg;
	ip = namei(ndp);
E 6
E 3
	if (ip == NULL)
		return;
D 11
	if (ip->i_count!=1 || (ip->i_mode&IFMT) != IFDIR) {
E 11
I 11
	if (ip->i_count != 1) {
E 11
		iput(ip);
		u.u_error = EBUSY;
		return;
	}
I 11
	if ((ip->i_mode&IFMT) != IFDIR) {
		iput(ip);
		u.u_error = ENOTDIR;
		return;
	}
E 11
	fs = mountfs(dev, uap->ronly, ip);
D 23
	if (fs == 0)
E 23
I 23
	if (fs == 0) {
		iput(ip);
E 23
		return;
I 23
	}
E 23
D 6
	u.u_dirp = uap->freg;
	for (cp = fs->fs_fsmnt; cp < &fs->fs_fsmnt[sizeof(fs->fs_fsmnt) - 2]; )
		if ((*cp++ = uchar()) == 0)
			u.u_dirp--;		/* get 0 again */
	*cp = 0;
E 6
I 6
D 7
	bzero(fs->fs_fsmnt, sizeof(fs->fs_fsmnt));
	copyinstr(uap->freg, fs->fs_fsmnt, sizeof(fs->fs_fsmnt));
E 7
I 7
	(void) copyinstr(uap->freg, fs->fs_fsmnt, sizeof(fs->fs_fsmnt)-1, &len);
D 8
	bzero(fs->fs_fsmnt, sizeof (fs->fs_fsmnt) - len);
E 8
I 8
	bzero(fs->fs_fsmnt + len, sizeof (fs->fs_fsmnt) - len);
E 8
E 7
E 6
}

D 5
/* this routine has lousy error codes */
E 5
D 23
/* this routine has races if running twice */
E 23
struct fs *
mountfs(dev, ronly, ip)
	dev_t dev;
	int ronly;
	struct inode *ip;
{
D 23
	register struct mount *mp = 0;
	struct buf *tp = 0;
	register struct buf *bp = 0;
E 23
I 23
	register struct mount *mp;
	struct mount *fmp = NULL;
D 26
	struct buf *tp = NULL;
E 26
	register struct buf *bp = NULL;
E 23
	register struct fs *fs;
D 18
D 19
	int blks;
E 19
I 19
	struct partinfo dpart;
	int havepart = 0, blks;
E 19
E 18
I 18
	struct partinfo dpart;
	int havepart = 0, blks;
E 18
D 23
	caddr_t space;
E 23
I 23
	caddr_t base, space;
E 23
	int i, size;
I 5
	register error;
I 11
	int needclose = 0;
E 11
E 5

I 23
	for (mp = &mount[0]; mp < &mount[NMOUNT]; mp++) {
		if (mp->m_fs == NULL) {
			if (fmp == NULL)
				fmp = mp;
		} else if (dev == mp->m_dev) {
			u.u_error = EBUSY;		/* XXX */
			return ((struct fs *) NULL);
		}
	}
	if ((mp = fmp) == NULL) {
		u.u_error = EMFILE;		/* needs translation      XXX */
		return ((struct fs *) NULL);
	}
	mp->m_fs = (struct fs *)1;	/* just to reserve this slot */
	mp->m_dev = dev;
I 25
	mp->m_inodp = NULL;
E 25
E 23
D 5
	u.u_error =
E 5
I 5
	error =
E 5
D 18
D 19
	    (*bdevsw[major(dev)].d_open)(dev, ronly ? FREAD : FREAD|FWRITE);
E 19
I 19
	    (*bdevsw[major(dev)].d_open)(dev, ronly ? FREAD : FREAD|FWRITE,
	        S_IFBLK);
E 19
E 18
I 18
	    (*bdevsw[major(dev)].d_open)(dev, ronly ? FREAD : FREAD|FWRITE,
	        S_IFBLK);
E 18
D 5
	if (u.u_error) {
		u.u_error = EIO;
E 5
I 5
D 23
	if (error)
E 5
		goto out;
E 23
I 23
	if (error) {
		u.u_error = error;
		mp->m_fs = NULL;
		return ((struct fs *) NULL);
	}
E 23
I 11
	needclose = 1;
I 19
	if ((*bdevsw[major(dev)].d_ioctl)(dev, DIOCGPART,
	    (caddr_t)&dpart, FREAD) == 0) {
		havepart = 1;
		size = dpart.disklab->d_secsize;
	} else
		size = DEV_BSIZE;
E 19
I 18
#ifdef SECSIZE
	/*
	 * If possible, determine hardware sector size
	 * and adjust fsbtodb to correspond.
	 */
#endif SECSIZE
	if ((*bdevsw[major(dev)].d_ioctl)(dev, DIOCGPART,
	    (caddr_t)&dpart, FREAD) == 0) {
		havepart = 1;
		size = dpart.disklab->d_secsize;
#ifdef SECSIZE
		if (size < MINSECSIZE) {
			error = EINVAL;
			goto out;
		}
#endif SECSIZE
	} else
		size = DEV_BSIZE;
#ifdef SECSIZE
	tp = bread(dev, (daddr_t)(SBOFF / size), SBSIZE, size);
#else SECSIZE
E 18
E 11
D 5
	}
E 5
D 26
	tp = bread(dev, SBLOCK, SBSIZE);
I 18
#endif SECSIZE
E 18
D 23
	if (tp->b_flags & B_ERROR)
E 23
I 23
	if (tp->b_flags & B_ERROR) {
E 26
I 26
	bp = bread(dev, SBLOCK, SBSIZE);
	if (bp->b_flags & B_ERROR) {
E 26
		mp->m_fs = NULL;
E 23
		goto out;
D 23
	for (mp = &mount[0]; mp < &mount[NMOUNT]; mp++)
D 22
		if (mp->m_bufp != 0 && dev == mp->m_dev) {
E 22
I 22
		if (mp->m_fs != NULL && dev == mp->m_dev) {
E 22
			mp = 0;
I 5
			error = EBUSY;
I 14
D 18
D 19
			needclose = 0;
E 19
E 18
E 14
E 5
			goto out;
		}
	for (mp = &mount[0]; mp < &mount[NMOUNT]; mp++)
D 22
		if (mp->m_bufp == 0)
E 22
I 22
		if (mp->m_fs == NULL)
E 22
			goto found;
	mp = 0;
I 5
	error = EMFILE;		/* needs translation */
E 5
	goto out;
found:
D 22
	mp->m_bufp = tp;	/* just to reserve this slot */
E 22
I 22
	mp->m_fs = tp->b_un.b_fs;	/* just to reserve this slot */
E 22
	mp->m_dev = NODEV;
D 22
	fs = tp->b_un.b_fs;
E 22
I 22
	fs = mp->m_fs;
E 23
I 23
	}
D 26
	fs = tp->b_un.b_fs;
E 26
I 26
	fs = bp->b_un.b_fs;
E 26
E 23
E 22
I 5
D 18
D 19
	if (fs->fs_magic != FS_MAGIC || fs->fs_bsize > MAXBSIZE
	    || fs->fs_bsize < sizeof(struct fs)) {
E 19
I 19
	if (fs->fs_magic != FS_MAGIC || fs->fs_bsize > MAXBSIZE ||
	    fs->fs_bsize < sizeof(struct fs)) {
I 22
		mp->m_fs = NULL;
E 22
E 19
E 18
I 18
	if (fs->fs_magic != FS_MAGIC || fs->fs_bsize > MAXBSIZE ||
	    fs->fs_bsize < sizeof(struct fs)) {
E 18
		error = EINVAL;		/* also needs translation */
		goto out;
	}
E 5
D 22
	bp = geteblk((int)fs->fs_sbsize);
	mp->m_bufp = bp;
	bcopy((caddr_t)tp->b_un.b_addr, (caddr_t)bp->b_un.b_addr,
E 22
I 22
D 27
	mp->m_fs = (struct fs *)malloc(fs->fs_sbsize, M_SUPERBLK, M_WAITOK);
E 27
I 27
	mp->m_fs = (struct fs *)malloc((u_long)fs->fs_sbsize, M_SUPERBLK,
	    M_WAITOK);
E 27
D 26
	bcopy((caddr_t)tp->b_un.b_addr, (caddr_t)mp->m_fs,
E 26
I 26
	bcopy((caddr_t)bp->b_un.b_addr, (caddr_t)mp->m_fs,
E 26
E 22
	   (u_int)fs->fs_sbsize);
D 26
	brelse(tp);
D 23
	tp = 0;
E 23
I 23
	tp = NULL;
E 26
I 26
	brelse(bp);
	bp = NULL;
E 26
E 23
D 22
	fs = bp->b_un.b_fs;
E 22
I 22
	fs = mp->m_fs;
E 22
D 5
	if (fs->fs_magic != FS_MAGIC || fs->fs_bsize > MAXBSIZE)
		goto out;
E 5
	fs->fs_ronly = (ronly != 0);
	if (ronly == 0)
		fs->fs_fmod = 1;
I 19
	if (havepart) {
		dpart.part->p_fstype = FS_BSDFFS;
		dpart.part->p_fsize = fs->fs_fsize;
		dpart.part->p_frag = fs->fs_frag;
I 21
		dpart.part->p_cpg = fs->fs_cpg;
E 21
D 24
		fs->fs_dbsize = size;
E 24
	}
E 19
I 18
#ifdef SECSIZE
	/*
	 * If we have a disk label, force per-partition
	 * filesystem information to be correct
	 * and set correct current fsbtodb shift.
	 */
#endif SECSIZE
	if (havepart) {
		dpart.part->p_fstype = FS_BSDFFS;
		dpart.part->p_fsize = fs->fs_fsize;
		dpart.part->p_frag = fs->fs_frag;
#ifdef SECSIZE
#ifdef tahoe
		/*
		 * Save the original fsbtodb shift to restore on updates.
		 * (Console doesn't understand fsbtodb changes.)
		 */
		fs->fs_sparecon[0] = fs->fs_fsbtodb;
#endif
		i = fs->fs_fsize / size;
		for (fs->fs_fsbtodb = 0; i > 1; i >>= 1)
			fs->fs_fsbtodb++;
#endif SECSIZE
		fs->fs_dbsize = size;
	}
E 18
	blks = howmany(fs->fs_cssize, fs->fs_fsize);
D 22
	space = wmemall(vmemall, (int)fs->fs_cssize);
E 22
I 22
D 23
	space = (caddr_t)malloc(fs->fs_cssize, M_SUPERBLK, M_WAITOK);
E 22
D 5
	if (space == 0)
E 5
I 5
	if (space == 0) {
E 23
I 23
D 27
	base = space = (caddr_t)malloc(fs->fs_cssize, M_SUPERBLK, M_WAITOK);
E 27
I 27
	base = space = (caddr_t)malloc((u_long)fs->fs_cssize, M_SUPERBLK,
	    M_WAITOK);
E 27
	if (space == NULL) {
E 23
		error = ENOMEM;
E 5
		goto out;
I 5
	}
E 5
	for (i = 0; i < blks; i += fs->fs_frag) {
		size = fs->fs_bsize;
		if (i + fs->fs_frag > blks)
			size = (blks - i) * fs->fs_fsize;
I 18
#ifdef SECSIZE
		tp = bread(dev, fsbtodb(fs, fs->fs_csaddr + i), size,
		    fs->fs_dbsize);
#else SECSIZE
E 18
D 26
		tp = bread(dev, fsbtodb(fs, fs->fs_csaddr + i), size);
I 18
#endif SECSIZE
E 18
		if (tp->b_flags&B_ERROR) {
E 26
I 26
		bp = bread(dev, fsbtodb(fs, fs->fs_csaddr + i), size);
		if (bp->b_flags&B_ERROR) {
E 26
D 22
			wmemfree(space, (int)fs->fs_cssize);
E 22
I 22
D 23
			free(space, M_SUPERBLK);
E 23
I 23
D 27
			free(base, M_SUPERBLK);
E 27
I 27
			free((caddr_t)base, M_SUPERBLK);
E 27
E 23
E 22
			goto out;
		}
D 26
		bcopy((caddr_t)tp->b_un.b_addr, space, (u_int)size);
E 26
I 26
		bcopy((caddr_t)bp->b_un.b_addr, space, (u_int)size);
E 26
D 10
		fs->fs_csp[i / fs->fs_frag] = (struct csum *)space;
E 10
I 10
		fs->fs_csp[fragstoblks(fs, i)] = (struct csum *)space;
E 10
		space += size;
D 26
		brelse(tp);
D 23
		tp = 0;
E 23
I 23
		tp = NULL;
E 26
I 26
		brelse(bp);
		bp = NULL;
E 26
E 23
	}
	mp->m_inodp = ip;
D 23
	mp->m_dev = dev;
E 23
	if (ip) {
		ip->i_flag |= IMOUNT;
I 15
		cacheinval(ip);
E 15
		iunlock(ip);
	}
I 17
	/* Sanity checks for old file systems.			   XXX */
	fs->fs_npsect = MAX(fs->fs_npsect, fs->fs_nsect);	/* XXX */
	fs->fs_interleave = MAX(fs->fs_interleave, 1);		/* XXX */
I 19
D 24

E 24
I 24
	if (fs->fs_postblformat == FS_42POSTBLFMT)		/* XXX */
		fs->fs_nrpos = 8;				/* XXX */
E 24
E 19
I 18

E 18
E 17
	return (fs);
out:
D 5
	u.u_error = EBUSY;
E 5
I 5
D 23
	if (error == 0)
		error = EIO;
I 19
D 20
	if (needclose)
E 20
I 20
	if (needclose && ip)
E 20
		(void) closei((dev_t)ip->i_rdev, IFBLK,
		    ronly? FREAD : FREAD|FWRITE);
E 19
I 18
	if (needclose)
		(void) closei((dev_t)ip->i_rdev, IFBLK,
		    ronly? FREAD : FREAD|FWRITE);
E 18
E 5
	if (ip)
		iput(ip);
D 22
	if (mp)
		mp->m_bufp = 0;
	if (bp)
		brelse(bp);
E 22
I 22
	if (mp && mp->m_fs)
E 23
I 23
	if (needclose)
		(void) closei(dev, IFBLK, ronly? FREAD : FREAD|FWRITE);
	if (mp->m_fs) {
E 23
		free((caddr_t)mp->m_fs, M_SUPERBLK);
I 23
		mp->m_fs = NULL;
	}
E 23
E 22
D 26
	if (tp)
		brelse(tp);
E 26
I 26
	if (bp)
		brelse(bp);
E 26
I 11
D 14
	if (needclose)
		(*bdevsw[major(dev)].d_close)(dev, ronly ? FREAD : FREAD|FWRITE);
	binval(dev);
E 14
I 14
D 18
D 19
	if (needclose) {
		(*bdevsw[major(dev)].d_close)(dev, ronly? FREAD : FREAD|FWRITE);
		binval(dev);
	}
E 19
E 18
E 14
E 11
I 5
D 23
	u.u_error = error;
E 5
	return (0);
E 23
I 23
	u.u_error = error ? error : EIO;			/* XXX */
	return ((struct fs *) NULL);
E 23
}

umount()
{
	struct a {
		char	*fspec;
D 6
	};
E 6
I 6
	} *uap = (struct a *)u.u_ap;
E 6

D 6
	u.u_error = unmount1(0);
E 6
I 6
	u.u_error = unmount1(uap->fspec, 0);
E 6
}

D 6
unmount1(forcibly)
E 6
I 6
unmount1(fname, forcibly)
	caddr_t fname;
E 6
	int forcibly;
{
	dev_t dev;
	register struct mount *mp;
D 18
D 19
	int stillopen, flag, error;
E 19
I 19
	int error;
E 19
E 18
I 18
	int error;
E 18
	register struct inode *ip;
	register struct fs *fs;

I 19
	forcibly = 0;					/* XXX */
E 19
I 18
	forcibly = 0;					/* XXX */
E 18
D 6
	error = getmdev(&dev);
E 6
I 6
	error = getmdev(&dev, fname);
E 6
	if (error)
		return (error);
	for (mp = &mount[0]; mp < &mount[NMOUNT]; mp++)
D 22
		if (mp->m_bufp != NULL && dev == mp->m_dev)
E 22
I 22
		if (mp->m_fs != NULL && dev == mp->m_dev)
E 22
			goto found;
	return (EINVAL);
found:
	xumount(dev);	/* remove unused sticky files from text table */
I 3
	nchinval(dev);	/* flush the name cache */
E 3
	update();
#ifdef QUOTA
D 18
D 19
	if ((stillopen = iflush(dev, mp->m_qinod)) < 0 && !forcibly)
E 19
I 19
	if ((error = iflush(dev, mp->m_qinod)) && !forcibly)
E 19
E 18
I 18
	if ((error = iflush(dev, mp->m_qinod)) && !forcibly)
E 18
#else
D 18
D 19
	if ((stillopen = iflush(dev)) < 0 && !forcibly)
E 19
I 19
	if ((error = iflush(dev)) && !forcibly)
E 19
E 18
I 18
	if ((error = iflush(dev)) && !forcibly)
E 18
#endif
D 18
D 19
		return (EBUSY);
	if (stillopen < 0)
		return (EBUSY);			/* XXX */
E 19
I 19
		return (error);
E 19
E 18
I 18
		return (error);
E 18
#ifdef QUOTA
	closedq(mp);
	/*
	 * Here we have to iflush again to get rid of the quota inode.
D 18
D 19
	 * A drag, but it would be ugly to cheat, & this doesn't happen often
E 19
I 19
	 * A drag, but it would be ugly to cheat, & this doesn't happen often.
E 19
E 18
I 18
	 * A drag, but it would be ugly to cheat, & this doesn't happen often.
E 18
	 */
	(void)iflush(dev, (struct inode *)NULL);
#endif
	ip = mp->m_inodp;
	ip->i_flag &= ~IMOUNT;
D 18
D 19
	irele(ip);
E 19
E 18
D 22
	fs = mp->m_bufp->b_un.b_fs;
	wmemfree((caddr_t)fs->fs_csp[0], (int)fs->fs_cssize);
D 18
D 19
	flag = !fs->fs_ronly;
E 19
E 18
	brelse(mp->m_bufp);
	mp->m_bufp = 0;
E 22
I 22
	fs = mp->m_fs;
	free((caddr_t)fs->fs_csp[0], M_SUPERBLK);
	free((caddr_t)mp->m_fs, M_SUPERBLK);
D 23
	mp->m_fs = 0;
E 22
	mp->m_dev = 0;
E 23
I 23
	mp->m_fs = NULL;
	mp->m_dev = NODEV;
E 23
	mpurge(mp - &mount[0]);
D 18
D 19
	if (!stillopen) {
		(*bdevsw[major(dev)].d_close)(dev, flag);
		binval(dev);
	}
	return (0);
E 19
I 19
	error = closei(dev, IFBLK, fs->fs_ronly? FREAD : FREAD|FWRITE);
	irele(ip);
	return (error);
E 19
E 18
I 18
	error = closei(dev, IFBLK, fs->fs_ronly? FREAD : FREAD|FWRITE);
	irele(ip);
	return (error);
E 18
}

sbupdate(mp)
	struct mount *mp;
{
D 22
	register struct fs *fs = mp->m_bufp->b_un.b_fs;
E 22
I 22
	register struct fs *fs = mp->m_fs;
E 22
	register struct buf *bp;
	int blks;
	caddr_t space;
	int i, size;

I 18
#ifdef SECSIZE
	bp = getblk(mp->m_dev, (daddr_t)fsbtodb(fs, SBOFF / fs->fs_fsize),
	    (int)fs->fs_sbsize, fs->fs_dbsize);
#else SECSIZE
E 18
	bp = getblk(mp->m_dev, SBLOCK, (int)fs->fs_sbsize);
I 18
#endif SECSIZE
E 18
	bcopy((caddr_t)fs, bp->b_un.b_addr, (u_int)fs->fs_sbsize);
I 24
	/* Restore compatibility to old file systems.		   XXX */
	if (fs->fs_postblformat == FS_42POSTBLFMT)		/* XXX */
		bp->b_un.b_fs->fs_nrpos = -1;			/* XXX */
E 24
I 18
#ifdef SECSIZE
#ifdef tahoe
	/* restore standard fsbtodb shift */
	bp->b_un.b_fs->fs_fsbtodb = fs->fs_sparecon[0];
	bp->b_un.b_fs->fs_sparecon[0] = 0;
#endif
#endif SECSIZE
E 18
	bwrite(bp);
	blks = howmany(fs->fs_cssize, fs->fs_fsize);
	space = (caddr_t)fs->fs_csp[0];
	for (i = 0; i < blks; i += fs->fs_frag) {
		size = fs->fs_bsize;
		if (i + fs->fs_frag > blks)
			size = (blks - i) * fs->fs_fsize;
I 18
#ifdef SECSIZE
		bp = getblk(mp->m_dev, fsbtodb(fs, fs->fs_csaddr + i), size,
		    fs->fs_dbsize);
#else SECSIZE
E 18
		bp = getblk(mp->m_dev, fsbtodb(fs, fs->fs_csaddr + i), size);
I 18
#endif SECSIZE
E 18
		bcopy(space, bp->b_un.b_addr, (u_int)size);
		space += size;
		bwrite(bp);
	}
}

/*
 * Common code for mount and umount.
 * Check that the user's argument is a reasonable
 * thing on which to mount, and return the device number if so.
 */
D 6
getmdev(pdev)
E 6
I 6
getmdev(pdev, fname)
	caddr_t fname;
E 6
	dev_t *pdev;
{
	dev_t dev;
	register struct inode *ip;
I 6
	register struct nameidata *ndp = &u.u_nd;
E 6

	if (!suser())
		return (u.u_error);
D 6
	ip = namei(uchar, LOOKUP, 1);
E 6
I 6
	ndp->ni_nameiop = LOOKUP | FOLLOW;
	ndp->ni_segflg = UIO_USERSPACE;
	ndp->ni_dirp = fname;
	ip = namei(ndp);
E 6
D 11
	if (ip == NULL)
E 11
I 11
	if (ip == NULL) {
		if (u.u_error == ENOENT)
			return (ENODEV); /* needs translation */
E 11
		return (u.u_error);
I 11
	}
E 11
D 4
	if ((ip->i_mode&IFMT) != IFBLK)
E 4
I 4
	if ((ip->i_mode&IFMT) != IFBLK) {
		iput(ip);
E 4
		return (ENOTBLK);
I 4
	}
E 4
	dev = (dev_t)ip->i_rdev;
I 4
	iput(ip);
E 4
	if (major(dev) >= nblkdev)
		return (ENXIO);
D 4
	iput(ip);
E 4
	*pdev = dev;
	return (0);
}
E 1
