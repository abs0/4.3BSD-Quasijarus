h34144
s 00001/00001/00145
d D 7.1 86/06/05 00:12:38 mckusick 49 48
c 4.3BSD release version
e
s 00007/00001/00139
d D 6.5 85/06/08 14:51:25 mckusick 48 47
c Add copyright
e
s 00001/00001/00139
d D 6.4 85/03/18 15:19:00 karels 47 46
c add gid_t for groups; copy u.u_groups to int array for copyin/out
e
s 00013/00013/00127
d D 6.3 84/08/29 20:25:55 bloom 46 45
c Change to includes.  no more ../h
e
s 00007/00003/00133
d D 6.2 84/07/08 16:15:51 mckusick 45 44
c rework `namei' interface to eliminate global variables
e
s 00000/00000/00136
d D 6.1 83/07/29 06:42:02 sam 44 43
c 4.2 distribution
e
s 00000/00026/00136
d D 4.35 83/05/27 12:49:29 sam 43 42
c merge of bill's code plus lint (plus, of course, cleanup of bill's bugs)
e
s 00002/00001/00160
d D 4.34 83/03/31 13:58:24 sam 42 40
c tighten up group search by checking for NOGROUP terminator
e
s 00002/00001/00160
d R 4.34 83/03/31 13:46:46 sam 41 40
c add NOGROUP identifier; add groupmember function; tighten group 
c lookup loop to stop at first NOGROUP entry
e
s 00025/00001/00136
d D 4.33 83/02/20 14:41:44 sam 40 37
c fix problem with access and setgid being incompatible
e
s 00040/00010/00127
d R 4.33 83/02/16 18:19:12 sam 39 37
c fix access and problems with setgid and saccess
e
s 00001/00001/00136
d R 4.33 83/02/10 18:42:06 sam 38 37
c groups set members are shorts, not ints; hz no longer in systm.h
e
s 00001/00001/00136
d D 4.32 82/12/31 16:54:27 sam 37 36
c group checks backwards
e
s 00002/00001/00135
d D 4.31 82/12/17 11:48:50 sam 36 35
c sun merge
e
s 00002/00001/00134
d D 4.30 82/11/13 22:52:51 sam 35 34
c merge of 4.1b and 4.1c
e
s 00005/00002/00130
d D 4.29 82/10/31 01:03:21 root 34 33
c allow writing on special files in read-only filesystem
e
s 00007/00013/00125
d D 4.28 82/10/17 11:35:00 root 33 32
c openi returns values
e
s 00007/00004/00131
d D 4.27 82/08/24 15:06:08 root 32 31
c new groups stuff
e
s 00004/00024/00131
d D 4.26 82/08/03 16:59:30 sam 31 29
c purge EFS crap
e
s 00004/00016/00139
d R 4.26 82/08/03 14:03:28 sam 30 29
c purge EFS stuff
e
s 00001/00168/00154
d D 4.25 82/07/24 18:12:00 root 29 28
c merge with calder
e
s 00032/00000/00290
d D 4.24 82/07/15 20:48:41 root 28 27
c EFS crud
e
s 00007/00005/00283
d D 4.23 82/04/19 19:35:26 mckusic 27 26
c merge into new file system
e
s 00003/00002/00285
d D 4.22 82/02/27 14:54:22 wnj 26 25
c symbolic links
e
s 00003/00001/00284
d D 4.21 82/02/15 13:28:16 wnj 25 24
c new multiple-group stuff
e
s 00002/00001/00283
d D 4.20 82/01/25 18:38:12 wnj 24 23
c bug fixes (round 1)
e
s 00007/00002/00277
d D 4.19 82/01/19 06:39:14 wnj 23 22
c closef parameter indicating whether error return
c to complete non-blc
e
s 00001/00001/00278
d D 4.18 82/01/19 05:16:41 root 22 21
c dont lose memory when closing non-blocking socket; this is blocking operation; set linger to 0 to not block then
e
s 00000/00000/00279
d D 4.17 81/11/18 15:44:43 wnj 21 20
c more cleanup
e
s 00002/00000/00277
d D 4.16 81/11/16 14:20:16 wnj 20 19
c lint
e
s 00001/00001/00276
d D 4.15 81/11/14 16:42:49 wnj 19 18
c before header overlay
e
s 00051/00061/00226
d D 4.14 81/11/08 16:47:41 wnj 18 17
c ilock/irele and get rid of FPORT and FNET stuff
e
s 00013/00019/00274
d D 4.13 81/10/11 13:02:05 wnj 17 16
c first bootable version
e
s 00006/00001/00287
d D 4.12 81/08/12 14:45:16 ecc 16 15
c new bbnnet
e
s 00001/00000/00287
d D 4.11 81/05/15 10:33:59 root 15 14
c zero f_inode when files allocated, so no trashy pointers for PORTs
e
s 00006/00000/00281
d D 4.10 81/05/12 17:18:12 root 14 13
c add tcp/ip
e
s 00010/00010/00271
d D 4.9 81/04/28 02:52:32 root 13 12
c changes to put in port code
e
s 00001/00001/00280
d D 4.8 81/03/09 01:47:00 wnj 12 11
c lint and a few minor fixed
e
s 00001/00010/00280
d D 4.7 81/03/06 11:36:58 wnj 11 10
c use tablefull()... no more UCBIPC
e
s 00010/00008/00280
d D 4.6 81/02/27 17:44:44 wnj 10 9
c dynamic allocation kernel
e
s 00002/00002/00286
d D 4.5 81/02/26 23:31:42 wnj 9 8
c rid of NFILE
e
s 00010/00008/00278
d D 4.4 81/02/01 18:01:24 wnj 8 7
c UCBIPC crud
e
s 00024/00009/00262
d D 4.3 81/01/28 12:03:08 kre 7 6
c call close with fp, not cp; flush buffer cache on last close
e
s 00001/00003/00270
d D 4.2 81/01/26 20:40:36 wnj 6 5
c multiplexore fix
e
s 00000/00000/00273
d D 4.1 80/11/09 17:31:51 bill 5 4
c minor fixups to restart stuff; version 4.1 for distrib
e
s 00002/00001/00271
d D 3.4 80/09/14 13:07:53 bill 4 3
c fix closef bug
e
s 00013/00007/00259
d D 3.3 80/07/19 20:11:47 bill 3 2
c circ search in falloc (poor mans 2 minute free list)
e
s 00001/00001/00265
d D 3.2 80/06/07 02:45:32 bill 2 1
c %H%->%G%
e
s 00266/00000/00000
d D 3.1 80/04/09 16:03:11 bill 1 0
c date and time created 80/04/09 16:03:11 by bill
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%H%	*/
E 2
I 2
D 12
/*	%M%	%I%	%G%	*/
E 12
I 12
D 29
/*	%M%	%I%	%E%	*/
E 29
I 29
D 31
/*	fio.c	4.25	82/07/17	*/
E 31
I 31
D 48
/*	%M%	%I%	%E%	*/
E 48
I 48
/*
D 49
 * Copyright (c) 1982 Regents of the University of California.
E 49
I 49
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 49
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 48
E 31
E 29
E 12
E 2

I 36
#include "../machine/reg.h"

E 36
I 27
D 29
/* merged into kernel:	@(#)fio.c 2.2 4/8/82 */

E 29
E 27
D 46
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
D 27
#include "../h/filsys.h"
E 27
I 27
#include "../h/fs.h"
E 27
#include "../h/file.h"
#include "../h/conf.h"
#include "../h/inode.h"
D 36
#include "../h/reg.h"
E 36
#include "../h/acct.h"
I 7
#include "../h/mount.h"
I 20
#include "../h/socket.h"
#include "../h/socketvar.h"
I 23
#include "../h/proc.h"
E 46
I 46
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "fs.h"
#include "file.h"
#include "conf.h"
#include "inode.h"
#include "acct.h"
#include "mount.h"
#include "socket.h"
#include "socketvar.h"
#include "proc.h"
E 46
I 35
D 45
#include "../h/nami.h"
E 45
E 35
I 28
D 31
#ifdef EFS
#include "../net/in.h"
#include "../h/efs.h"
#endif
E 31
E 28
E 23
E 20
E 7

/*
D 18
 * Convert a user supplied
 * file descriptor into a pointer
 * to a file structure.
 * Only task is to check range
 * of the descriptor.
E 18
I 18
D 29
 * Convert a user supplied file descriptor into a pointer
 * to a file structure.  Only task is to check range of the descriptor.
 * Critical paths should use the GETF macro, defined in inline.h.
E 18
 */
struct file *
getf(f)
D 18
register int f;
E 18
I 18
	register int f;
E 18
{
	register struct file *fp;

D 8
	if(0 <= f && f < NOFILE) {
		fp = u.u_ofile[f];
		if(fp != NULL)
			return(fp);
E 8
I 8
	if ((unsigned)f >= NOFILE || (fp = u.u_ofile[f]) == NULL) {
		u.u_error = EBADF;
		return (NULL);
E 8
	}
D 8
	u.u_error = EBADF;
	return(NULL);
E 8
I 8
D 11
#ifdef UCBIPC
	if (u.u_pofile[f] & ISPORT) {
		u.u_error = EISPORT;
		return (NULL);
	}
#endif
E 11
	return (fp);
E 8
}

/*
 * Internal form of close.
 * Decrement reference count on
 * file structure.
 * Also make sure the pipe protocol
 * does not constipate.
 *
 * Decrement reference count on the inode following
 * removal to the referencing file structure.
 * Call device handler on last close.
I 23
 * Nouser indicates that the user isn't available to present
 * errors to.
E 23
 */
D 23
closef(fp)
E 23
I 23
closef(fp, nouser)
E 23
D 18
register struct file *fp;
E 18
I 18
	register struct file *fp;
E 18
{
	register struct inode *ip;
I 7
	register struct mount *mp;
E 7
	int flag, mode;
	dev_t dev;
	register int (*cfunc)();
D 6
	struct chan *cp;
E 6

D 18
	if(fp == NULL)
E 18
I 18
	if (fp == NULL)
E 18
		return;
	if (fp->f_count > 1) {
		fp->f_count--;
		return;
	}
D 13
	ip = fp->f_inode;
E 13
	flag = fp->f_flag;
I 14
D 18
#ifdef BBNNET
	if (flag&FNET) {
		netclose(fp);
		return;
	}
#endif
E 14
I 13
	if (flag & FPORT) {
		ptclose(fp);
E 18
I 18
	if (flag & FSOCKET) {
I 24
		u.u_error = 0;			/* XXX */
E 24
D 19
		skclose(fp->f_socket);
E 19
I 19
D 22
		soclose(fp->f_socket);
E 22
I 22
D 23
		soclose(fp->f_socket, u.u_procp->p_flag&SWEXIT);
E 23
I 23
		soclose(fp->f_socket, nouser);
D 24
		if (u.u_error)
E 24
I 24
		if (nouser == 0 && u.u_error)
E 24
			return;
E 23
E 22
E 19
		fp->f_socket = 0;
E 18
		fp->f_count = 0;
		return;
	}
	ip = fp->f_inode;
E 13
D 6
	cp = fp->f_un.f_chan;
E 6
D 27
	dev = (dev_t)ip->i_un.i_rdev;
E 27
I 27
	dev = (dev_t)ip->i_rdev;
E 27
D 7
	mode = ip->i_mode;
E 7
I 7
	mode = ip->i_mode & IFMT;
E 7
D 13

E 13
D 18
	plock(ip);
E 18
I 18
	ilock(ip);
E 18
D 13
	fp->f_count = 0;
	if(flag & FPIPE) {
		ip->i_mode &= ~(IREAD|IWRITE);
		wakeup((caddr_t)ip+1);
		wakeup((caddr_t)ip+2);
	}
E 13
	iput(ip);
I 13
	fp->f_count = 0;
E 13

D 7
	switch(mode&IFMT) {
E 7
I 7
D 13
	switch(mode) {
E 13
I 13
	switch (mode) {
E 13
E 7

	case IFCHR:
D 17
	case IFMPC:
E 17
		cfunc = cdevsw[major(dev)].d_close;
I 28
#ifdef EFS
		/*
		 * Every close() must call the driver if the
		 * extended file system is being used -- not
		 * just the last close.  Pass along the file
		 * pointer for reference later.
		 */
		if (major(dev) == efs_major) {
			(*cfunc)(dev, flag, fp, nouser);
			return;
		}
#endif
E 28
		break;

	case IFBLK:
I 7
		/*
		 * We don't want to really close the device if it is mounted
		 */
		for (mp = mount; mp < &mount[NMOUNT]; mp++)
			if (mp->m_bufp != NULL && mp->m_dev == dev)
				return;
E 7
D 17
	case IFMPB:
E 17
		cfunc = bdevsw[major(dev)].d_close;
		break;
I 18

E 18
	default:
		return;
	}
D 18

D 7
	if (flag & FMP)
		goto call;
E 7
I 7
D 17
	if ((flag & FMP) == 0) {
D 9
		for(fp=file; fp < &file[NFILE]; fp++)
E 9
I 9
D 16
		for(fp=file; fp < fileNFILE; fp++)
E 16
I 16
		for(fp=file; fp < fileNFILE; fp++) {
E 17
I 17
	for(fp=file; fp < fileNFILE; fp++) {
E 17
#ifdef BBNNET
			if (fp->f_flag & FNET)
				continue;
#endif
E 18
I 18
	for (fp = file; fp < fileNFILE; fp++) {
		if (fp->f_flag & FSOCKET)
			continue;
E 18
E 16
E 9
D 13
			if (fp->f_count && (ip=fp->f_inode)->i_un.i_rdev==dev &&
E 13
I 13
D 17
			if (fp->f_count && (ip = fp->f_inode) &&
			    ip->i_un.i_rdev == dev &&
E 13
			    (ip->i_mode&IFMT) == mode)
				return;
I 16
		}
E 16
E 7
D 8

E 8
D 7
	for(fp=file; fp < &file[NFILE]; fp++)
D 4
		if (fp->f_count && fp->f_inode==ip)
E 4
I 4
		if (fp->f_count && (ip=fp->f_inode)->i_un.i_rdev==dev &&
		    (ip->i_mode&IFMT) == (mode&IFMT))
E 4
			return;
E 7
I 7
		if (mode == IFBLK) {
			/*
			 * on last close of a block device (that isn't mounted)
			 * we must invalidate any in core blocks
			 */
			bflush(dev);
			binval(dev);
		}
E 17
I 17
		if (fp->f_count && (ip = fp->f_inode) &&
D 18
		    ip->i_un.i_rdev == dev &&
		    (ip->i_mode&IFMT) == mode)
E 18
I 18
D 27
		    ip->i_un.i_rdev == dev && (ip->i_mode&IFMT) == mode)
E 27
I 27
		    ip->i_rdev == dev && (ip->i_mode&IFMT) == mode)
E 27
E 18
			return;
E 17
	}
I 17
	if (mode == IFBLK) {
		/*
D 18
		 * on last close of a block device (that isn't mounted)
E 18
I 18
		 * On last close of a block device (that isn't mounted)
E 18
		 * we must invalidate any in core blocks
		 */
		bflush(dev);
		binval(dev);
	}
E 17
E 7
D 8

E 8
D 7
call:
E 7
D 6
	(*cfunc)(dev, flag, cp);
E 6
I 6
	(*cfunc)(dev, flag, fp);
E 6
}

/*
E 29
D 18
 * openi called to allow handler
E 18
I 18
D 43
 * Openi called to allow handler
E 18
 * of special files to initialize and
 * validate before actual IO.
 */
I 28
D 31
#ifdef EFS
openi(ip, rw, trf)
#else
E 28
openi(ip, rw)
I 28
#endif
E 31
I 31
openi(ip, mode)
E 31
E 28
D 18
register struct inode *ip;
E 18
I 18
	register struct inode *ip;
E 18
{
D 33
	dev_t dev;
	register unsigned int maj;
E 33
I 33
	dev_t dev = (dev_t)ip->i_rdev;
	register u_int maj = major(dev);
E 33

D 27
	dev = (dev_t)ip->i_un.i_rdev;
E 27
I 27
D 33
	dev = (dev_t)ip->i_rdev;
E 27
	maj = major(dev);
E 33
D 18
	switch(ip->i_mode&IFMT) {
E 18
I 18
	switch (ip->i_mode&IFMT) {
E 18

	case IFCHR:
D 17
	case IFMPC:
E 17
D 18
		if(maj >= nchrdev)
E 18
I 18
		if (maj >= nchrdev)
E 18
D 33
			goto bad;
I 28
D 31
#ifdef EFS
		(*cdevsw[maj].d_open)(dev, rw, trf);
#else
E 28
		(*cdevsw[maj].d_open)(dev, rw);
I 28
#endif
E 31
I 31
		(*cdevsw[maj].d_open)(dev, mode);
E 31
E 28
		break;
E 33
I 33
			return (ENXIO);
		return ((*cdevsw[maj].d_open)(dev, mode));
E 33

	case IFBLK:
D 17
	case IFMPB:
E 17
D 18
		if(maj >= nblkdev)
E 18
I 18
		if (maj >= nblkdev)
E 18
D 33
			goto bad;
D 31
		(*bdevsw[maj].d_open)(dev, rw);
E 31
I 31
		(*bdevsw[maj].d_open)(dev, mode);
E 33
I 33
			return (ENXIO);
		return ((*bdevsw[maj].d_open)(dev, mode));
E 33
E 31
	}
D 33
	return;

bad:
	u.u_error = ENXIO;
E 33
I 33
	return (0);
E 33
}

/*
E 43
 * Check mode permission on inode pointer.
 * Mode is READ, WRITE or EXEC.
 * In the case of WRITE, the
 * read-only status of the file
 * system is checked.
 * Also in WRITE, prototype text
 * segments cannot be written.
 * The mode is shifted to select
 * the owner/group/other fields.
 * The super user is granted all
 * permissions.
 */
access(ip, mode)
D 18
register struct inode *ip;
E 18
I 18
	register struct inode *ip;
	int mode;
E 18
{
	register m;
I 32
D 47
	register int *gp;
E 47
I 47
	register gid_t *gp;
E 47
E 32

	m = mode;
D 18
	if(m == IWRITE) {
		if(getfs(ip->i_dev)->s_ronly != 0) {
E 18
I 18
	if (m == IWRITE) {
I 40
		/*
		 * Disallow write attempts on read-only
		 * file systems; unless the file is a block
		 * or character device resident on the
		 * file system.
		 */
E 40
D 27
		if (getfs(ip->i_dev)->s_ronly != 0) {
E 27
I 27
		if (ip->i_fs->fs_ronly != 0) {
E 27
E 18
D 34
			u.u_error = EROFS;
D 18
			return(1);
E 18
I 18
			return (1);
E 34
I 34
			if ((ip->i_mode & IFMT) != IFCHR &&
			    (ip->i_mode & IFMT) != IFBLK) {
				u.u_error = EROFS;
				return (1);
			}
E 34
E 18
		}
D 40
		if (ip->i_flag&ITEXT)		/* try to free text */
E 40
I 40
		/*
		 * If there's shared text associated with
		 * the inode, try to free it up once.  If
		 * we fail, we can't allow writing.
		 */
		if (ip->i_flag&ITEXT)
E 40
			xrele(ip);
D 18
		if(ip->i_flag & ITEXT) {
E 18
I 18
		if (ip->i_flag & ITEXT) {
E 18
			u.u_error = ETXTBSY;
D 18
			return(1);
E 18
I 18
			return (1);
E 18
		}
	}
I 40
	/*
	 * If you're the super-user,
	 * you always get access.
	 */
E 40
D 18
	if(u.u_uid == 0)
		return(0);
	if(u.u_uid != ip->i_uid) {
E 18
I 18
	if (u.u_uid == 0)
		return (0);
I 40
	/*
	 * Access check is based on only
	 * one of owner, group, public.
	 * If not owner, then check group.
	 * If not a member of the group, then
	 * check public access.
	 */
E 40
	if (u.u_uid != ip->i_uid) {
E 18
		m >>= 3;
I 40
		if (u.u_gid == ip->i_gid)
			goto found;
E 40
D 18
		if(u.u_gid != ip->i_gid)
E 18
I 18
D 25
		if (u.u_gid != ip->i_gid)
E 25
I 25
D 32
		if (ip->i_gid >= NGRPS ||
		    (u.u_grps[ip->i_gid/(sizeof(int)*8)] &
		     (1 << ip->i_gid%(sizeof(int)*8)) == 0))
E 25
E 18
			m >>= 3;
E 32
I 32
D 42
		for (gp = u.u_groups; gp < &u.u_groups[NGROUPS]; gp++)
E 42
I 42
		gp = u.u_groups;
		for (; gp < &u.u_groups[NGROUPS] && *gp != NOGROUP; gp++)
E 42
D 37
			if (ip->i_gid != *gp)
E 37
I 37
			if (ip->i_gid == *gp)
E 37
				goto found;
		m >>= 3;
found:
		;
E 32
	}
D 18
	if((ip->i_mode&m) != 0)
		return(0);

E 18
I 18
	if ((ip->i_mode&m) != 0)
		return (0);
E 18
	u.u_error = EACCES;
D 18
	return(1);
E 18
I 18
	return (1);
E 18
}

/*
 * Look up a pathname and test if
 * the resultant inode is owned by the
 * current user.
 * If not, try for super-user.
 * If permission is granted,
 * return inode pointer.
 */
struct inode *
D 26
owner()
E 26
I 26
D 45
owner(follow)
E 45
I 45
owner(fname, follow)
	caddr_t fname;
E 45
	int follow;
E 26
{
	register struct inode *ip;
I 45
	register struct nameidata *ndp = &u.u_nd;
E 45

D 26
	ip = namei(uchar, 0);
E 26
I 26
D 35
	ip = namei(uchar, 0, follow);
E 35
I 35
D 45
	ip = namei(uchar, LOOKUP, follow);
E 45
I 45
	ndp->ni_nameiop = LOOKUP | follow;
	ndp->ni_segflg = UIO_USERSPACE;
	ndp->ni_dirp = fname;
	ip = namei(ndp);
E 45
E 35
E 26
D 18
	if(ip == NULL)
		return(NULL);
	if(u.u_uid == ip->i_uid)
		return(ip);
	if(suser())
		return(ip);
E 18
I 18
	if (ip == NULL)
		return (NULL);
I 28
D 31
#ifdef EFS
	/*
	 * References to extended file system are
	 * returned to the caller.
	 */
	if (efsinode(ip))
		return (ip);
#endif
E 31
E 28
	if (u.u_uid == ip->i_uid)
		return (ip);
	if (suser())
		return (ip);
E 18
	iput(ip);
D 18
	return(NULL);
E 18
I 18
	return (NULL);
E 18
}

/*
 * Test if the current user is the
 * super user.
 */
suser()
{

D 18
	if(u.u_uid == 0) {
E 18
I 18
	if (u.u_uid == 0) {
E 18
		u.u_acflag |= ASU;
D 18
		return(1);
E 18
I 18
		return (1);
E 18
	}
	u.u_error = EPERM;
D 18
	return(0);
E 18
I 18
	return (0);
E 18
D 29
}

/*
 * Allocate a user file descriptor.
 */
ufalloc()
{
	register i;

D 18
	for(i=0; i<NOFILE; i++)
		if(u.u_ofile[i] == NULL) {
E 18
I 18
	for (i=0; i<NOFILE; i++)
		if (u.u_ofile[i] == NULL) {
E 18
			u.u_r.r_val1 = i;
			u.u_pofile[i] = 0;
D 18
			return(i);
E 18
I 18
			return (i);
E 18
		}
	u.u_error = EMFILE;
D 18
	return(-1);
E 18
I 18
	return (-1);
E 18
}

I 3
D 10
struct	file *lastf = &file[0];
E 10
I 10
struct	file *lastf;
E 10
E 3
/*
 * Allocate a user file descriptor
 * and a file structure.
 * Initialize the descriptor
 * to point at the file structure.
D 11
 *
 * no file -- if there are no available
 * 	file structures.
E 11
 */
struct file *
falloc()
{
	register struct file *fp;
	register i;

	i = ufalloc();
D 10
	if(i < 0)
E 10
I 10
	if (i < 0)
E 10
D 18
		return(NULL);
E 18
I 18
		return (NULL);
E 18
D 3
	for(fp = &file[0]; fp < &file[NFILE]; fp++)
		if(fp->f_count == 0) {
			u.u_ofile[i] = fp;
			fp->f_count++;
			fp->f_un.f_offset = 0;
			return(fp);
		}
E 3
I 3
D 9
	for(fp = lastf; fp < &file[NFILE]; fp++)
E 9
I 9
D 10
	for(fp = lastf; fp < fileNFILE; fp++)
E 9
		if(fp->f_count == 0)
E 10
I 10
	if (lastf == 0)
		lastf = file;
	for (fp = lastf; fp < fileNFILE; fp++)
		if (fp->f_count == 0)
E 10
			goto slot;
D 10
	for(fp = &file[0]; fp < lastf; fp++)
		if(fp->f_count == 0)
E 10
I 10
	for (fp = file; fp < lastf; fp++)
		if (fp->f_count == 0)
E 10
			goto slot;
E 3
D 11
	printf("no file\n");
E 11
I 11
	tablefull("file");
E 11
	u.u_error = ENFILE;
D 10
	return(NULL);
E 10
I 10
	return (NULL);
E 10
I 3
slot:
	u.u_ofile[i] = fp;
	fp->f_count++;
D 18
	fp->f_un.f_offset = 0;
E 18
I 18
	fp->f_offset = 0;
E 18
I 15
	fp->f_inode = 0;
E 15
	lastf = fp + 1;
D 10
	return(fp);
E 10
I 10
	return (fp);
E 29
E 10
E 3
}
E 1
