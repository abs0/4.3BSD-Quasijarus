h03632
s 00001/00001/00128
d D 7.1 86/06/05 00:15:32 mckusick 13 12
c 4.3BSD release version
e
s 00007/00001/00122
d D 6.4 85/06/08 14:57:32 mckusick 12 11
c Add copyright
e
s 00011/00011/00112
d D 6.3 84/08/29 20:27:36 bloom 11 10
c Change to includes.  no more ../h
e
s 00007/00030/00116
d D 6.2 84/07/08 16:17:52 mckusick 10 9
c rework `namei' interface to eliminate global variables
e
s 00000/00000/00146
d D 6.1 83/07/29 06:46:06 sam 9 8
c 4.2 distribution
e
s 00001/00001/00145
d D 4.7 83/06/21 20:36:16 sam 8 7
c change NOCOMPAT to COMPAT and make it work
e
s 00026/00000/00120
d D 4.6 83/05/31 01:04:16 sam 7 6
c collect all the compatibility stuff in single files
e
s 00004/00011/00116
d D 4.5 83/05/27 12:50:14 sam 6 5
c merge of bill's code plus lint (plus, of course, cleanup of bill's bugs)
e
s 00001/00002/00126
d D 4.4 82/12/28 23:49:02 sam 5 4
c copyin & copyout now return EFAULT and all callers uniformly 
c return (or ignore) this value
e
s 00001/00001/00127
d D 4.3 82/12/28 13:08:27 sam 4 3
c old inode #'s were 16-bits (argh)
e
s 00092/00000/00036
d D 4.2 82/12/23 16:22:54 sam 3 1
c make stat backwards compatible
e
s 00087/00000/00036
d R 4.2 82/12/23 15:58:25 sam 2 1
c make stat backwards compatiblemake stat backwards compatible
e
s 00036/00000/00000
d D 4.1 82/10/20 03:06:31 root 1 0
c date and time created 82/10/20 03:06:31 by root
e
u
U
t
T
I 1
D 12
/*	%M%	%I%	%E%	*/
E 12
I 12
/*
D 13
 * Copyright (c) 1982 Regents of the University of California.
E 13
I 13
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 13
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 12

D 11
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/inode.h"
#include "../h/fs.h"
#include "../h/mount.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/buf.h"
#include "../h/conf.h"
E 11
I 11
#include "param.h"
#include "systm.h"
#include "inode.h"
#include "fs.h"
#include "mount.h"
#include "dir.h"
#include "user.h"
#include "buf.h"
#include "conf.h"
E 11

D 10
/*
 * Return the next character fromt the
 * kernel string pointed at by dirp.
 */
schar()
{
	return (*u.u_dirp++ & 0377);
}

/*
 * Return the next character from the
 * user string pointed at by dirp.
 */
uchar()
{
	register c;

	c = fubyte(u.u_dirp++);
	if (c == -1) {
		u.u_error = EFAULT;
		c = 0;
	}
	return (c);
}
I 3

E 10
D 8
#ifndef NOCOMPAT
E 8
I 8
#ifdef COMPAT
E 8
D 11
#include "../h/file.h"
D 10
#include "../h/nami.h"
E 10
D 6
#include "../h/descrip.h"
E 6
#include "../h/kernel.h"
E 11
I 11
#include "file.h"
#include "kernel.h"
E 11

/*
 * Oh, how backwards compatibility is ugly!!!
 */
struct	ostat {
	dev_t	ost_dev;
D 4
	u_int	ost_ino;
E 4
I 4
	u_short	ost_ino;
E 4
	u_short ost_mode;
	short  	ost_nlink;
	short  	ost_uid;
	short  	ost_gid;
	dev_t	ost_rdev;
	int	ost_size;
	int	ost_atime;
	int	ost_mtime;
	int	ost_ctime;
};

/*
 * The old fstat system call.
 */
ofstat()
{
	register struct file *fp;
	register struct a {
		int	fd;
		struct ostat *sb;
D 6
	} *uap;
E 6
I 6
	} *uap = (struct a *)u.u_ap;
	extern struct file *getinode();
E 6

D 6
	uap = (struct a *)u.u_ap;
	fp = getf(uap->fd);
E 6
I 6
	fp = getinode(uap->fd);
E 6
	if (fp == NULL)
		return;
D 6
	if (fp->f_type == DTYPE_SOCKET) {
		struct ostat ub;

		bzero((caddr_t)&ub, sizeof (ub));
		(void) copyout((caddr_t)&ub, (caddr_t)uap->sb, sizeof (ub));
	} else
		ostat1(fp->f_inode, uap->sb);
E 6
I 6
	ostat1((struct inode *)fp->f_data, uap->sb);
E 6
}

/*
 * Old stat system call.  This version follows links.
 */
ostat()
{
	register struct inode *ip;
	register struct a {
		char	*fname;
		struct ostat *sb;
D 10
	} *uap;
E 10
I 10
	} *uap = (struct a *)u.u_ap;
	register struct nameidata *ndp = &u.u_nd;
E 10

D 10
	uap = (struct a *)u.u_ap;
	ip = namei(uchar, LOOKUP, 1);
E 10
I 10
	ndp->ni_nameiop = LOOKUP | FOLLOW;
	ndp->ni_segflg = UIO_USERSPACE;
	ndp->ni_dirp = uap->fname;
	ip = namei(ndp);
E 10
	if (ip == NULL)
		return;
	ostat1(ip, uap->sb);
	iput(ip);
}

ostat1(ip, ub)
	register struct inode *ip;
	struct ostat *ub;
{
	struct ostat ds;

	IUPDAT(ip, &time, &time, 0);
	/*
	 * Copy from inode table
	 */
	ds.ost_dev = ip->i_dev;
	ds.ost_ino = (short)ip->i_number;
	ds.ost_mode = (u_short)ip->i_mode;
	ds.ost_nlink = ip->i_nlink;
	ds.ost_uid = (short)ip->i_uid;
	ds.ost_gid = (short)ip->i_gid;
	ds.ost_rdev = (dev_t)ip->i_rdev;
	ds.ost_size = (int)ip->i_size;
	ds.ost_atime = (int)ip->i_atime;
	ds.ost_mtime = (int)ip->i_mtime;
	ds.ost_ctime = (int)ip->i_ctime;
D 5
	if (copyout((caddr_t)&ds, (caddr_t)ub, sizeof(ds)) < 0)
		u.u_error = EFAULT;
E 5
I 5
	u.u_error = copyout((caddr_t)&ds, (caddr_t)ub, sizeof(ds));
E 5
}
I 7

/*
 * Set IUPD and IACC times on file.
 * Can't set ICHG.
 */
outime()
{
	register struct a {
		char	*fname;
		time_t	*tptr;
	} *uap = (struct a *)u.u_ap;
	register struct inode *ip;
	time_t tv[2];
	struct timeval tv0, tv1;

D 10
	if ((ip = owner(1)) == NULL)
E 10
I 10
	if ((ip = owner(uap->fname, FOLLOW)) == NULL)
E 10
		return;
	u.u_error = copyin((caddr_t)uap->tptr, (caddr_t)tv, sizeof (tv));
	if (u.u_error == 0) {
		ip->i_flag |= IACC|IUPD|ICHG;
		tv0.tv_sec = tv[0]; tv0.tv_usec = 0;
		tv1.tv_sec = tv[1]; tv1.tv_usec = 0;
		iupdat(ip, &tv0, &tv1, 0);
	}
	iput(ip);
}
E 7
#endif
E 3
E 1
