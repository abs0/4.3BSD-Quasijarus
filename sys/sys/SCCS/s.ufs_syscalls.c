h16684
s 00001/00001/01369
d D 7.3 87/04/18 16:27:02 karels 98 97
c don't clear set-gid when su creates file when not groupmember
e
s 00002/00000/01368
d D 7.2 87/03/10 14:20:57 mckusick 97 96
c only set ICHG when fsync'ing a file descriptor that is open for writing
e
s 00001/00001/01367
d D 7.1 86/06/05 00:14:45 mckusick 96 95
c 4.3BSD release version
e
s 00009/00007/01359
d D 6.23 86/03/04 19:53:22 karels 95 94
c relax restrictions on *chown: allow owner to change group if member
e
s 00005/00003/01361
d D 6.22 86/02/23 23:11:56 karels 94 93
c lint
e
s 00013/00020/01351
d D 6.21 85/09/05 15:09:19 mckusick 93 91
c allocate file table entry before creating file in case file table is full
e
s 00010/00017/01354
d R 6.21 85/09/04 20:48:08 mckusick 92 91
c allocate file table entry before creating file in case file table is full
e
s 00011/00000/01360
d D 6.20 85/08/26 17:15:14 bloom 91 90
c fix whole in sticky directories
e
s 00007/00001/01353
d D 6.19 85/06/08 14:54:42 mckusick 90 89
c Add copyright
e
s 00015/00004/01339
d D 6.18 85/05/22 20:03:04 mckusick 89 88
c return EINVAL instead of ENXIO for readlink of a non symbolic link;
c check for read-only file system in [f]chmod, [f]chown, and utimes;
c do not clear the sticky bit when modifying directories
e
s 00004/00001/01339
d D 6.17 85/03/19 17:09:55 mckusick 88 87
c do not follow symbolic links on exclusive open (from kre)
e
s 00004/00000/01336
d D 6.16 85/02/22 15:12:05 mckusick 87 86
c insure that directories are always a multiple of DIRBLKSIZ in size
e
s 00006/00003/01330
d D 6.15 85/01/21 13:36:06 mckusick 86 85
c cannot use ni_pdir when `namei' fails
e
s 00016/00016/01317
d D 6.14 84/08/29 20:27:03 bloom 85 84
c Change to includes.  no more ../h
e
s 00066/00080/01267
d D 6.13 84/07/27 11:29:31 mckusick 84 83
c rewrite `rename' and `rmdir' to properly invalidate the cache
e
s 00002/00001/01345
d D 6.12 84/07/20 01:13:26 mckusick 83 82
c use new `cacheinval' macro
e
s 00143/00094/01203
d D 6.11 84/07/08 16:16:25 mckusick 82 81
c rework `namei' interface to eliminate global variables
e
s 00012/00012/01285
d D 6.10 84/07/04 13:21:06 mckusick 81 80
c save time, use ILOCK and IUNLOCK to avoid call overhead
e
s 00008/00004/01289
d D 6.9 84/07/02 15:15:42 mckusick 80 79
c Follow same protocol as `unlink' to prevent potential race condition.
e
s 00002/00006/01291
d D 6.8 84/06/30 16:41:02 sam 79 78
c rename: if source has gone away when time to unlink, don't touch 
c link count (consider race with unlink)
e
s 00001/00000/01296
d D 6.7 84/06/27 20:40:59 sam 78 77
c convert namei cache to hold soft references to inodes so that 
c . and .. may be placed in the cache
e
s 00010/00007/01286
d D 6.6 84/05/24 17:57:52 sam 77 76
c correct error code for lseek on pipes/sockets; in-line expand 
c getf in getinode
e
s 00001/00001/01292
d D 6.5 84/02/10 14:54:57 karels 76 74
c open(...,FTRUNC...) requires write permission
e
s 00002/00002/01291
d R 6.5 84/02/10 14:48:11 karels 75 74
c open(..,FTRUNC..) requires write permission
e
s 00003/00003/01290
d D 6.4 84/01/03 23:40:44 mckusick 74 73
c add system wide cacheing of path names in namei() (from kre)
e
s 00000/00002/01293
d D 6.3 83/09/30 11:10:26 sam 73 72
c code for interrupted open calls tested (it works)
e
s 00001/00000/01294
d D 6.2 83/09/25 16:12:15 mckusick 72 71
c kludge to allow `badsect' to set block numbers
e
s 00000/00000/01294
d D 6.1 83/08/06 10:46:24 sam 71 70
c 4.2 distribution
e
s 00001/00001/01293
d D 4.62 83/08/06 10:43:25 sam 70 68
c typo
e
s 00000/00000/01294
d R 6.1 83/07/29 06:44:41 sam 69 68
c 4.2 distribution
e
s 00019/00006/01275
d D 4.61 83/07/09 14:15:09 sam 68 66
c parameter checking in lseek
e
s 00019/00006/01275
d R 4.61 83/07/09 01:42:35 sam 67 66
c correct lseek to check whence; make code more clear?
e
s 00001/00038/01280
d D 4.60 83/06/12 14:28:56 sam 66 65
c cleanup fstat
e
s 00000/00028/01318
d D 4.59 83/05/31 01:03:56 sam 65 64
c collect all the compatibility stuff in single files
e
s 00025/00010/01321
d D 4.58 83/05/28 19:10:06 mckusick 64 63
c must do a complete path check when moving directories to new parent
e
s 00342/00211/00989
d D 4.57 83/05/27 12:49:36 sam 63 62
c merge of bill's code plus lint (plus, of course, cleanup of bill's bugs)
e
s 00012/00035/01188
d D 4.56 83/05/21 15:46:38 sam 62 61
c purge mush; stuff for i_blocks
e
s 00002/00004/01221
d D 4.55 83/04/01 17:32:19 sam 61 60
c blew it, can't allow anyone but super-user to chown
e
s 00044/00024/01181
d D 4.54 83/03/31 13:49:40 sam 60 59
c add utimes call; protection fixes galore
e
s 00001/00001/01204
d D 4.53 83/03/22 11:36:12 sam 59 58
c oops
e
s 00019/00010/01186
d D 4.52 83/03/21 21:36:43 sam 58 57
c check delete permission on source before doing any work
e
s 00002/00000/01194
d D 4.51 83/02/20 14:54:02 sam 57 55
c fix incompatibility between access and setgid
e
s 00001/00001/01193
d R 4.51 83/02/10 18:42:13 sam 56 55
c groups set members are shorts, not ints; hz no longer in systm.h
e
s 00006/00008/01188
d D 4.50 83/02/10 13:44:32 sam 55 54
c have direnter return errors so new inodes can be thrown away
e
s 00012/00000/01184
d D 4.49 83/01/22 16:50:58 sam 54 53
c patch two holes in rename
e
s 00003/00002/01181
d D 4.48 83/01/11 14:46:19 sam 53 52
c irele should be iput in rename
e
s 00042/00023/01141
d D 4.47 83/01/01 17:14:38 sam 52 51
c avoid linked to directories as targets; iput and irele on 
c directory inodes can clear u.u_error, so kludge things for the moment 
c to insure important errors get back to the user
e
s 00003/00005/01161
d D 4.46 82/12/28 23:48:30 sam 51 50
c copyin & copyout now return EFAULT and all callers uniformly 
c return (or ignore) this value
e
s 00004/00000/01162
d D 4.45 82/12/24 18:14:00 sam 50 49
c zero trash in stat structure
e
s 00001/00001/01161
d D 4.44 82/12/19 13:04:05 sam 49 48
c use ENOTEMPTY errno
e
s 00004/00004/01158
d D 4.43 82/12/09 19:02:07 sam 48 47
c u.u_pofile flags are now UF_*
e
s 00349/00072/00813
d D 4.42 82/11/13 22:53:38 sam 47 46
c merge of 4.1b and 4.1c
e
s 00004/00004/00881
d D 4.41 82/10/19 10:32:46 root 46 45
c more lint
e
s 00008/00004/00877
d D 4.40 82/10/17 21:51:50 root 45 44
c more lint
e
s 00001/00001/00880
d D 4.39 82/10/17 11:30:27 root 44 43
c openi returns value
e
s 00000/00004/00881
d D 4.38 82/10/10 16:02:54 root 43 42
c move vax header files to their own directory
e
s 00001/00001/00884
d D 4.37 82/09/06 22:57:52 root 42 41
c 
e
s 00005/00004/00880
d D 4.36 82/09/04 09:21:40 root 41 40
c time is now a structure
e
s 00008/00004/00876
d D 4.35 82/08/24 15:06:33 root 40 39
c new groups stuff
e
s 00011/00015/00869
d D 4.34 82/08/22 21:11:10 root 39 38
c use rdwri()
e
s 00001/00005/00883
d D 4.33 82/08/14 23:56:59 root 38 37
c use readip1()
e
s 00268/00199/00620
d D 4.32 82/08/10 17:51:57 sam 37 36
c new fs system calls prior to truncate and rename
e
s 00057/00040/00762
d D 4.31 82/07/25 23:18:00 root 36 35
c first functional version with new ufs_nami.c
e
s 00009/00003/00793
d D 4.30 82/07/24 18:12:27 root 35 34
c merge with calder
e
s 00051/00000/00745
d D 4.29 82/07/22 12:13:29 kre 34 33
c disc quotas & MUSH
e
s 00151/00006/00594
d D 4.28 82/07/15 20:49:04 root 33 32
c efs crud
e
s 00000/00003/00600
d D 4.27 82/06/25 21:29:05 wnj 32 31
c drop #ifdef SIMFS for /etc/config's sake
e
s 00014/00010/00589
d D 4.26 82/06/10 12:41:08 mckusick 31 30
c change iput() to irele() when releasing unlocked inodes
e
s 00003/00003/00596
d D 4.25 82/06/07 23:54:07 mckusick 30 29
c irele() becomes iunlock(); new irele() does iput() for already unlocked inodes
e
s 00002/00003/00597
d D 4.24 82/06/04 00:15:27 mckusick 29 28
c provide blksize in stat system call
e
s 00044/00031/00556
d D 4.23 82/04/19 19:37:01 mckusic 28 27
c merge into new file system
e
s 00004/00004/00583
d D 4.22 82/04/01 11:48:05 root 27 26
c lstat <-> stat
e
s 00416/00207/00171
d D 4.21 82/03/18 19:26:30 root 26 25
c rearrange for kirk
e
s 00002/00000/00376
d D 4.20 82/03/16 17:38:47 root 25 24
c fix to symlink
e
s 00001/00001/00375
d D 4.19 82/03/12 16:29:48 sam 24 23
c lint
e
s 00097/00006/00279
d D 4.18 82/02/27 14:55:11 wnj 23 22
c symbolic links
e
s 00003/00001/00282
d D 4.17 82/01/19 06:39:56 wnj 22 21
c closef parameter indicating whether error return
c to complete non-blc
e
s 00001/00001/00282
d D 4.16 82/01/16 20:59:37 wnj 21 20
c clean crashes! 
e
s 00000/00000/00283
d D 4.15 81/11/18 15:45:57 wnj 20 19
c more cleanup
e
s 00002/00000/00281
d D 4.14 81/11/16 14:21:49 wnj 19 18
c lint
e
s 00001/00001/00280
d D 4.13 81/11/14 16:44:12 wnj 18 17
c before header overlay
e
s 00036/00046/00245
d D 4.12 81/11/08 17:06:36 wnj 17 16
c major cleanups for socket code
e
s 00006/00000/00285
d D 4.11 81/08/12 14:48:15 ecc 16 15
c new bbnnet
e
s 00008/00005/00277
d D 4.10 81/04/28 02:59:24 root 15 14
c fstat for ports now in pipe.c
e
s 00001/00001/00281
d D 4.9 81/03/09 01:49:47 wnj 14 13
c lint and a few minor fixed
e
s 00007/00002/00275
d D 4.8 81/03/03 11:08:14 wnj 13 12
c mount puts names in s_fsmnt
e
s 00001/00001/00276
d D 4.7 81/02/26 23:29:24 wnj 12 11
c rid of NINODE
e
s 00001/00001/00276
d D 4.6 81/02/16 20:51:35 wnj 11 10
c fix placement of mpurge bug
e
s 00001/00000/00276
d D 4.5 81/02/15 12:21:52 kre 10 9
c bug fix in umount
e
s 00011/00010/00265
d D 4.4 81/01/31 23:27:36 wnj 9 8
c changes for cached super-blocks
e
s 00011/00003/00264
d D 4.3 81/01/28 12:04:22 kre 8 7
c cache purging
e
s 00000/00002/00267
d D 4.2 81/01/20 19:46:34 toy 7 6
c Removed #ifdef UCB.   (MCT)
e
s 00000/00000/00269
d D 4.1 80/11/09 17:32:52 bill 6 5
c minor fixups to restart stuff; version 4.1 for distrib
e
s 00001/00001/00268
d D 3.5 80/10/03 10:45:34 bill 5 4
c file system update orderings
e
s 00001/00000/00268
d D 3.4 80/07/06 11:20:49 bill 4 3
c first cached version
e
s 00001/00001/00267
d D 3.3 80/06/07 02:48:00 bill 3 2
c %H%->%G%
e
s 00002/00001/00266
d D 3.2 80/04/14 09:58:04 bill 2 1
c IUPDAT fast inline from inline.h in stat()
e
s 00267/00000/00000
d D 3.1 80/04/09 16:04:33 bill 1 0
c date and time created 80/04/09 16:04:33 by bill
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
D 14
/*	%M%	%I%	%G%	*/
E 14
I 14
D 90
/*	%M%	%I%	%E%	*/
E 90
I 90
/*
D 96
 * Copyright (c) 1982 Regents of the University of California.
E 96
I 96
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 96
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 90
E 14
E 3

I 28
D 29
/* merged into kernel:	@(#)sys3.c 2.2 4/8/82 */

E 29
D 32
#ifdef SIMFS
#include "../h/sysrenam.h"
#endif
E 32
E 28
D 85
#include "../h/param.h"
#include "../h/systm.h"
D 26
#include "../h/mount.h"
#include "../h/ino.h"
#include "../h/reg.h"
#include "../h/buf.h"
#include "../h/filsys.h"
E 26
#include "../h/dir.h"
#include "../h/user.h"
I 41
#include "../h/kernel.h"
E 41
D 26
#include "../h/inode.h"
E 26
I 26
D 28
#include "../h/reg.h"
E 28
E 26
#include "../h/file.h"
I 28
#include "../h/stat.h"
E 28
D 26
#include "../h/conf.h"
#include "../h/stat.h"
E 26
I 26
#include "../h/inode.h"
D 28
#include "../h/ino.h"
#include "../h/pte.h"
#include "../h/vm.h"
E 28
I 28
#include "../h/fs.h"
E 28
#include "../h/buf.h"
D 28
#include "../h/mtpr.h"
E 28
#include "../h/proc.h"
E 26
I 2
D 43
#include "../h/inline.h"
I 33
D 37
#ifdef EFS
#include "../net/in.h"
#include "../h/efs.h"
#endif
E 37
I 37
/* no reason to inline expand these guys here */
#undef ilock
#undef iunlock
E 43
E 37
I 34
#include "../h/quota.h"
I 35
D 63
#include "../h/descrip.h"
E 63
I 39
#include "../h/uio.h"
#include "../h/socket.h"
I 45
#include "../h/socketvar.h"
I 47
D 82
#include "../h/nami.h"
E 82
I 63
#include "../h/mount.h"
E 85
I 85
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "kernel.h"
#include "file.h"
#include "stat.h"
#include "inode.h"
#include "fs.h"
#include "buf.h"
#include "proc.h"
#include "quota.h"
#include "uio.h"
#include "socket.h"
#include "socketvar.h"
#include "mount.h"
E 85
E 63
E 47
E 45
E 39
E 35
E 34
E 33
I 26
D 28
#include "../h/conf.h"
E 26
I 19
#include "../h/socket.h"
#include "../h/socketvar.h"
I 26
#include "../h/stat.h"
E 28
E 26
E 19
E 2

I 63
extern	struct fileops inodeops;
struct	file *getinode();

E 63
I 47
/*
 * Change current working directory (``.'').
 */
E 47
I 26
chdir()
{

	chdirec(&u.u_cdir);
}

I 47
/*
 * Change notion of root (``/'') directory.
 */
E 47
chroot()
{

	if (suser())
		chdirec(&u.u_rdir);
}

I 47
/*
 * Common routine for chroot and chdir.
 */
E 47
chdirec(ipp)
D 37
register struct inode **ipp;
E 37
I 37
	register struct inode **ipp;
E 37
{
	register struct inode *ip;
	struct a {
		char	*fname;
D 82
	};
E 82
I 82
	} *uap = (struct a *)u.u_ap;
	register struct nameidata *ndp = &u.u_nd;
E 82

D 47
	ip = namei(uchar, 0, 1);
	if(ip == NULL)
E 47
I 47
D 82
	ip = namei(uchar, LOOKUP, 1);
E 82
I 82
	ndp->ni_nameiop = LOOKUP | FOLLOW;
	ndp->ni_segflg = UIO_USERSPACE;
	ndp->ni_dirp = uap->fname;
	ip = namei(ndp);
E 82
	if (ip == NULL)
E 47
		return;
D 47
	if((ip->i_mode&IFMT) != IFDIR) {
E 47
I 47
	if ((ip->i_mode&IFMT) != IFDIR) {
E 47
		u.u_error = ENOTDIR;
		goto bad;
	}
D 47
	if(access(ip, IEXEC))
E 47
I 47
	if (access(ip, IEXEC))
E 47
		goto bad;
D 30
	irele(ip);
E 30
I 30
D 81
	iunlock(ip);
E 81
I 81
	IUNLOCK(ip);
E 81
E 30
D 31
	if (*ipp) {
		ilock(*ipp);
		iput(*ipp);
	}
E 31
I 31
	if (*ipp)
		irele(*ipp);
E 31
	*ipp = ip;
	return;

bad:
	iput(ip);
}

E 26
/*
I 26
 * Open system call.
 */
open()
{
D 63
	register struct inode *ip;
	register struct a {
E 63
I 63
	struct a {
E 63
		char	*fname;
D 37
		int	rwmode;
E 37
I 37
D 63
		int	flags;
E 63
		int	mode;
E 37
D 63
	} *uap;
I 37
D 47
	int checkpermissions = 1;
E 47
I 47
	int checkpermissions = 1, flags;
E 63
I 63
		int	crtmode;
	} *uap = (struct a *) u.u_ap;
E 63
E 47
E 37

D 63
	uap = (struct a *)u.u_ap;
D 37
	ip = namei(uchar, 0, 1);
E 37
I 37
D 47
	if (uap->flags&FCREATE) {
		ip = namei(uchar, 1, 1);
E 47
I 47
	flags = uap->flags + 1;
	if ((flags&FTRUNCATE) && (flags&FWRITE) == 0) {
		u.u_error = EINVAL;
		return;
	}
	if (flags&FCREATE) {
		ip = namei(uchar, CREATE, 1);
E 47
		if (ip == NULL) {
			if (u.u_error)
				return;
			ip = maknode(uap->mode&07777&(~ISVTX));
			checkpermissions = 0;
D 47
			uap->flags &= ~FTRUNCATE;
E 47
I 47
			flags &= ~FTRUNCATE;
E 47
		}
	} else
D 47
		ip = namei(uchar, 0, 1);
E 47
I 47
		ip = namei(uchar, LOOKUP, 1);
E 47
E 37
	if (ip == NULL)
		return;
D 37
	open1(ip, ++uap->rwmode, 0);
E 37
I 37
D 47
	open1(ip, ++uap->flags, checkpermissions);
E 47
I 47
	open1(ip, flags, checkpermissions);
E 63
I 63
D 82
	copen(uap->mode-FOPEN, uap->crtmode);
E 82
I 82
	copen(uap->mode-FOPEN, uap->crtmode, uap->fname);
E 82
E 63
E 47
E 37
}

I 37
D 63
#ifndef NOCOMPAT
E 63
E 37
/*
 * Creat system call.
 */
D 35
creat()
E 35
I 35
D 63
ocreat()
E 63
I 63
creat()
E 63
E 35
{
D 63
	register struct inode *ip;
	register struct a {
E 63
I 63
	struct a {
E 63
		char	*fname;
		int	fmode;
D 63
	} *uap;
E 63
I 63
	} *uap = (struct a *)u.u_ap;
E 63

D 63
	uap = (struct a *)u.u_ap;
D 47
	ip = namei(uchar, 1, 1);
E 47
I 47
	ip = namei(uchar, CREATE, 1);
E 47
	if (ip == NULL) {
		if (u.u_error)
			return;
		ip = maknode(uap->fmode&07777&(~ISVTX));
D 37
		if (ip==NULL)
E 37
I 37
		if (ip == NULL)
E 37
			return;
D 37
		open1(ip, FWRITE, 2);
E 37
I 37
		open1(ip, FWRITE, 0);
E 37
	} else
D 37
		open1(ip, FWRITE, 1);
E 37
I 37
D 47
		open1(ip, FWRITE|FTRUNCATE, 0);
E 47
I 47
		open1(ip, FWRITE|FTRUNCATE, 1);
E 63
I 63
D 82
	copen(FWRITE|FCREAT|FTRUNC, uap->fmode);
E 82
I 82
	copen(FWRITE|FCREAT|FTRUNC, uap->fmode, uap->fname);
E 82
E 63
E 47
E 37
}
I 37
D 63
#endif
E 63
E 37

/*
 * Common code for open and creat.
D 37
 * Check permissions, allocate an open file structure,
 * and call the device open routine if any.
E 37
I 37
D 63
 * Check permissions (if we haven't done so already),
 * allocate an open file structure, and call
 * the device open routine, if any.
E 63
I 63
 * Check permissions, allocate an open file structure,
 * and call the device open routine if any.
E 63
E 37
 */
D 37
open1(ip, mode, trf)
E 37
I 37
D 63
open1(ip, mode, checkpermissions)
E 37
	register struct inode *ip;
	register mode;
E 63
I 63
D 82
copen(mode, arg)
E 82
I 82
copen(mode, arg, fname)
E 82
	register int mode;
	int arg;
I 82
	caddr_t fname;
E 82
E 63
{
I 63
	register struct inode *ip;
E 63
	register struct file *fp;
I 82
	register struct nameidata *ndp = &u.u_nd;
E 82
D 37
	int i;
E 37
I 37
D 63
	int i, flags;
E 63
I 63
D 93
	int i;
E 93
I 93
	int indx;
E 93
E 63
E 37

D 37
	if (trf != 2) {
E 37
I 37
D 63
	if (checkpermissions) {
E 63
I 63
D 93
#ifdef notdef
	if ((mode&(FREAD|FWRITE)) == 0) {
		u.u_error = EINVAL;
E 93
I 93
	fp = falloc();
	if (fp == NULL)
E 93
		return;
D 93
	}
#endif
E 93
I 93
	indx = u.u_r.r_val1;
E 93
I 82
	ndp->ni_segflg = UIO_USERSPACE;
	ndp->ni_dirp = fname;
E 82
	if (mode&FCREAT) {
D 82
		ip = namei(uchar, CREATE, 1);
E 82
I 82
D 88
		ndp->ni_nameiop = CREATE | FOLLOW;
E 88
I 88
		if (mode & FEXCL)
			ndp->ni_nameiop = CREATE;
		else
			ndp->ni_nameiop = CREATE | FOLLOW;
E 88
		ip = namei(ndp);
E 82
		if (ip == NULL) {
			if (u.u_error)
D 93
				return;
E 93
I 93
				goto bad1;
E 93
D 82
			ip = maknode(arg&07777&(~ISVTX));
E 82
I 82
			ip = maknode(arg&07777&(~ISVTX), ndp);
E 82
			if (ip == NULL)
D 93
				return;
E 93
I 93
				goto bad1;
E 93
			mode &= ~FTRUNC;
		} else {
			if (mode&FEXCL) {
				u.u_error = EEXIST;
D 93
				iput(ip);
				return;
E 93
I 93
				goto bad;
E 93
			}
			mode &= ~FCREAT;
		}
	} else {
D 82
		ip = namei(uchar, LOOKUP, 1);
E 82
I 82
		ndp->ni_nameiop = LOOKUP | FOLLOW;
		ip = namei(ndp);
E 82
		if (ip == NULL)
D 93
			return;
E 93
I 93
			goto bad1;
E 93
	}
	if ((ip->i_mode & IFMT) == IFSOCK) {
		u.u_error = EOPNOTSUPP;
		goto bad;
	}
	if ((mode&FCREAT) == 0) {
E 63
E 37
		if (mode&FREAD)
D 37
			(void) access(ip, IREAD);
E 37
I 37
			if (access(ip, IREAD))
				goto bad;
E 37
D 76
		if (mode&FWRITE) {
E 76
I 76
		if (mode&(FWRITE|FTRUNC)) {
E 76
D 37
			(void) access(ip, IWRITE);
			if ((ip->i_mode&IFMT) == IFDIR)
E 37
I 37
			if (access(ip, IWRITE))
				goto bad;
			if ((ip->i_mode&IFMT) == IFDIR) {
E 37
				u.u_error = EISDIR;
I 37
				goto bad;
			}
E 37
		}
	}
D 31
	if (u.u_error)
		goto out;
E 31
I 31
D 37
	if (u.u_error) {
		iput(ip);
		return;
E 37
I 37
D 63

	/*
	 * Check locking on inode.  Release "inode lock"
	 * while doing so in case we block inside flocki.
	 */
	flags = 0;
D 47
	if (mode&(FRDLOCK|FWRLOCK)) {
E 47
I 47
	if (mode&(FSHLOCK|FEXLOCK)) {
E 47
		iunlock(ip);
		flags = flocki(ip, 0, mode);
		ilock(ip);
		if (u.u_error)
			goto bad;
E 37
	}
E 31
D 37
	if (trf == 1)
		itrunc(ip);
E 37
I 37
	if (mode&FTRUNCATE)
E 63
I 63
D 93
	fp = falloc();
	if (fp == NULL)
		goto bad;
E 93
	if (mode&FTRUNC)
E 63
D 47
		itrunc(ip, 0);
E 47
I 47
		itrunc(ip, (u_long)0);
E 47
E 37
D 30
	irele(ip);
E 30
I 30
D 81
	iunlock(ip);
E 81
I 81
	IUNLOCK(ip);
E 81
E 30
D 63
	if ((fp = falloc()) == NULL)
		goto out;
D 37
	fp->f_flag = mode&(FREAD|FWRITE);
E 37
I 37
	fp->f_flag = mode & FMODES;
E 37
I 35
	fp->f_type = DTYPE_FILE;
E 63
I 63
	fp->f_flag = mode&FMASK;
	fp->f_type = DTYPE_INODE;
	fp->f_ops = &inodeops;
	fp->f_data = (caddr_t)ip;
E 63
E 35
D 93
	i = u.u_r.r_val1;
E 93
D 63
	fp->f_inode = ip;
I 33
D 37
#ifdef EFS
	openi(ip, mode&(FREAD|FWRITE), trf);
#else
E 33
	openi(ip, mode&(FREAD|FWRITE));
I 33
#endif
E 33
	if (u.u_error == 0)
E 37
I 37
D 44
	openi(ip, mode);
E 44
I 44
	u.u_error = openi(ip, mode);
E 44
	if (u.u_error == 0) {
		u.u_pofile[i] = flags;
E 63
I 63
D 73
#ifdef notdef
E 73
	if (setjmp(&u.u_qsave)) {
		if (u.u_error == 0)
			u.u_error = EINTR;
D 93
		u.u_ofile[i] = NULL;
E 93
I 93
		u.u_ofile[indx] = NULL;
E 93
		closef(fp);
E 63
E 37
		return;
I 37
	}
I 63
D 73
#endif
E 73
	u.u_error = openi(ip, mode);
	if (u.u_error == 0)
		return;
E 63
E 37
D 93
	u.u_ofile[i] = NULL;
	fp->f_count--;
D 63
out:
E 63
D 31
	if (ip != NULL)
		iput(ip);
E 31
I 31
	irele(ip);
I 37
	return;
E 93
I 93
	ILOCK(ip);
E 93
bad:
	iput(ip);
I 93
bad1:
	u.u_ofile[indx] = NULL;
	fp->f_count--;
E 93
E 37
E 31
}

/*
 * Mknod system call
 */
mknod()
{
	register struct inode *ip;
	register struct a {
		char	*fname;
		int	fmode;
		int	dev;
D 82
	} *uap;
E 82
I 82
	} *uap = (struct a *)u.u_ap;
	register struct nameidata *ndp = &u.u_nd;
E 82

D 82
	uap = (struct a *)u.u_ap;
E 82
D 63
	if (suser()) {
D 47
		ip = namei(uchar, 1, 0);
E 47
I 47
		ip = namei(uchar, CREATE, 0);
E 47
		if (ip != NULL) {
			u.u_error = EEXIST;
			goto out;
		}
E 63
I 63
	if (!suser())
		return;
D 82
	ip = namei(uchar, CREATE, 0);
E 82
I 82
	ndp->ni_nameiop = CREATE;
	ndp->ni_segflg = UIO_USERSPACE;
	ndp->ni_dirp = uap->fname;
	ip = namei(ndp);
E 82
	if (ip != NULL) {
		u.u_error = EEXIST;
		goto out;
E 63
	}
	if (u.u_error)
		return;
D 82
	ip = maknode(uap->fmode);
E 82
I 82
	ip = maknode(uap->fmode, ndp);
E 82
	if (ip == NULL)
		return;
D 63
	if (uap->dev) {
		/*
		 * Want to be able to use this to make badblock
		 * inodes, so don't truncate the dev number.
		 */
D 28
		ip->i_un.i_rdev = uap->dev;
E 28
I 28
		ip->i_rdev = uap->dev;
E 28
		ip->i_flag |= IACC|IUPD|ICHG;
E 63
I 63
	switch (ip->i_mode & IFMT) {

I 72
	case IFMT:	/* used by badsect to flag bad sectors */
E 72
	case IFCHR:
	case IFBLK:
		if (uap->dev) {
			/*
			 * Want to be able to use this to make badblock
			 * inodes, so don't truncate the dev number.
			 */
			ip->i_rdev = uap->dev;
			ip->i_flag |= IACC|IUPD|ICHG;
		}
E 63
	}

out:
	iput(ip);
}

/*
 * link system call
 */
link()
{
	register struct inode *ip, *xp;
	register struct a {
		char	*target;
		char	*linkname;
D 82
	} *uap;
E 82
I 82
	} *uap = (struct a *)u.u_ap;
	register struct nameidata *ndp = &u.u_nd;
E 82

D 82
	uap = (struct a *)u.u_ap;
D 47
	ip = namei(uchar, 0, 1);    /* well, this routine is doomed anyhow */
E 47
I 47
	ip = namei(uchar, LOOKUP, 1); /* well, this routine is doomed anyhow */
E 82
I 82
	ndp->ni_nameiop = LOOKUP | FOLLOW;
	ndp->ni_segflg = UIO_USERSPACE;
	ndp->ni_dirp = uap->target;
	ip = namei(ndp);	/* well, this routine is doomed anyhow */
E 82
E 47
	if (ip == NULL)
		return;
D 33
	if ((ip->i_mode&IFMT)==IFDIR && !suser())
		goto out1;
E 33
I 33
D 47
	if ((ip->i_mode&IFMT)==IFDIR && !suser()) {
E 47
I 47
	if ((ip->i_mode&IFMT) == IFDIR && !suser()) {
E 47
		iput(ip);
		return;
	}
E 33
	ip->i_nlink++;
	ip->i_flag |= ICHG;
D 41
	iupdat(ip, &time, &time, 1);
E 41
I 41
D 45
	iupdat(ip, &time.tv_sec, &time.tv_sec, 1);
E 45
I 45
D 46
	iupdat(ip, time, time, 1);
E 46
I 46
	iupdat(ip, &time, &time, 1);
E 46
E 45
E 41
D 30
	irele(ip);
E 30
I 30
D 81
	iunlock(ip);
E 81
I 81
	IUNLOCK(ip);
E 81
E 30
D 82
	u.u_dirp = (caddr_t)uap->linkname;
D 47
	xp = namei(uchar, 1, 0);
E 47
I 47
	xp = namei(uchar, CREATE, 0);
E 82
I 82
	ndp->ni_nameiop = CREATE;
	ndp->ni_segflg = UIO_USERSPACE;
	ndp->ni_dirp = (caddr_t)uap->linkname;
	xp = namei(ndp);
E 82
E 47
	if (xp != NULL) {
		u.u_error = EEXIST;
		iput(xp);
		goto out;
	}
	if (u.u_error)
		goto out;
D 82
	if (u.u_pdir->i_dev != ip->i_dev) {
		iput(u.u_pdir);
E 82
I 82
	if (ndp->ni_pdir->i_dev != ip->i_dev) {
		iput(ndp->ni_pdir);
E 82
		u.u_error = EXDEV;
		goto out;
	}
D 36
	wdir(ip);
E 36
I 36
D 55
	direnter(ip);
E 55
I 55
D 82
	u.u_error = direnter(ip);
E 82
I 82
	u.u_error = direnter(ip, ndp);
E 82
E 55
E 36
out:
	if (u.u_error) {
		ip->i_nlink--;
		ip->i_flag |= ICHG;
	}
D 39
out1:
E 39
D 31
	iput(ip);
E 31
I 31
	irele(ip);
E 31
}

/*
 * symlink -- make a symbolic link
 */
symlink()
{
	register struct a {
		char	*target;
		char	*linkname;
D 82
	} *uap;
E 82
I 82
	} *uap = (struct a *)u.u_ap;
E 82
	register struct inode *ip;
	register char *tp;
	register c, nc;
I 82
	register struct nameidata *ndp = &u.u_nd;
E 82

D 82
	uap = (struct a *)u.u_ap;
E 82
	tp = uap->target;
	nc = 0;
	while (c = fubyte(tp)) {
		if (c < 0) {
			u.u_error = EFAULT;
			return;
		}
		tp++;
		nc++;
	}
D 82
	u.u_dirp = uap->linkname;
D 47
	ip = namei(uchar, 1, 0);
E 47
I 47
	ip = namei(uchar, CREATE, 0);
E 82
I 82
	ndp->ni_nameiop = CREATE;
	ndp->ni_segflg = UIO_USERSPACE;
	ndp->ni_dirp = uap->linkname;
	ip = namei(ndp);
E 82
E 47
	if (ip) {
		iput(ip);
		u.u_error = EEXIST;
		return;
	}
	if (u.u_error)
		return;
D 82
	ip = maknode(IFLNK | 0777);
E 82
I 82
	ip = maknode(IFLNK | 0777, ndp);
E 82
	if (ip == NULL)
		return;
D 39
	u.u_base = uap->target;
	u.u_count = nc;
	u.u_offset = 0;
	u.u_segflg = 0;
	writei(ip);
E 39
I 39
D 94
	u.u_error = rdwri(UIO_WRITE, ip, uap->target, nc, 0, 0, (int *)0);
E 94
I 94
	u.u_error = rdwri(UIO_WRITE, ip, uap->target, nc, (off_t)0, 0,
	    (int *)0);
E 94
I 47
	/* handle u.u_error != 0 */
E 47
E 39
	iput(ip);
}

/*
 * Unlink system call.
 * Hard to avoid races here, especially
 * in unlinking directories.
 */
unlink()
{
D 47
	register struct inode *ip, *pp;
E 47
	struct a {
		char	*fname;
D 82
	};
E 82
I 82
	} *uap = (struct a *)u.u_ap;
E 82
I 28
D 39
	struct fs *fs;
	struct buf *bp;
	int lbn, bn, base;
E 39
I 31
D 47
	int unlinkingdot = 0;
E 47
I 47
	register struct inode *ip, *dp;
I 82
	register struct nameidata *ndp = &u.u_nd;
E 82
E 47
E 31
E 28

D 47
	pp = namei(uchar, 2, 0);
D 36
	if(pp == NULL)
E 36
I 36
	if (pp == NULL)
E 47
I 47
D 82
	ip = namei(uchar, DELETE | LOCKPARENT, 0);
E 82
I 82
	ndp->ni_nameiop = DELETE | LOCKPARENT;
	ndp->ni_segflg = UIO_USERSPACE;
	ndp->ni_dirp = uap->fname;
	ip = namei(ndp);
E 82
	if (ip == NULL)
E 47
E 36
		return;
I 33
D 37
#ifdef EFS
	/* divert to extended file system if off machine. */
	if (efsinode(pp)) {
		dev_t ndev = pp->i_rdev;
E 37
D 47

D 37
		iput(pp);	/* avoid recursive hang on inode */
		efsunlink(ndev);
		if (u.u_error != EEXIST)
			return;

		/*
		 * If a null pathname remainder, then do
		 * the unlink locally after restoring state.
		 */
		u.u_error = 0;
		u.u_dirp = (caddr_t)u.u_arg[0];
		pp = namei(uchar, 2, 0);
	}
#endif

E 37
E 33
	/*
	 * Check for unlink(".")
	 * to avoid hanging on the iget
	 */
	if (pp->i_number == u.u_dent.d_ino) {
		ip = pp;
		ip->i_count++;
I 31
		unlinkingdot++;
E 31
	} else
D 28
		ip = iget(pp->i_dev, u.u_dent.d_ino);
E 28
I 28
		ip = iget(pp->i_dev, pp->i_fs, u.u_dent.d_ino);
E 28
	if(ip == NULL)
		goto out1;
	if((ip->i_mode&IFMT)==IFDIR && !suser())
E 47
I 47
D 82
	dp = u.u_pdir;
E 82
I 82
	dp = ndp->ni_pdir;
E 82
	if ((ip->i_mode&IFMT) == IFDIR && !suser())
E 47
		goto out;
	/*
	 * Don't unlink a mounted file.
	 */
D 47
	if (ip->i_dev != pp->i_dev) {
E 47
I 47
	if (ip->i_dev != dp->i_dev) {
E 47
		u.u_error = EBUSY;
		goto out;
	}
	if (ip->i_flag&ITEXT)
		xrele(ip);	/* try once to free text */
D 36
/*
	if ((ip->i_flag&ITEXT) && ip->i_nlink==1) {
 		u.u_error = ETXTBSY;
		goto out;
E 36
I 36
D 82
	if (dirremove()) {
E 82
I 82
	if (dirremove(ndp)) {
E 82
		ip->i_nlink--;
		ip->i_flag |= ICHG;
E 36
	}
D 36
*/
D 28
	u.u_offset -= sizeof(struct direct);
	u.u_base = (caddr_t)&u.u_dent;
	u.u_count = sizeof(struct direct);
	u.u_dent.d_ino = 0;
	writei(pp);
E 28
I 28
	if (u.u_count == 0) {
		/*
		 * first entry in block, so set d_ino to zero.
		 */
I 35
/*ZZ*/if(u.u_offset&0x1ff)printf("missed dir compact dir %s/%d off %d file %s\n"
/*ZZ*/,pp->i_fs->fs_fsmnt,pp->i_number,u.u_offset,u.u_dent.d_name);
E 35
		u.u_base = (caddr_t)&u.u_dent;
		u.u_count = DIRSIZ(&u.u_dent);
		u.u_dent.d_ino = 0;
		writei(pp);
	} else {
		/*
		 * updating preceeding entry to skip over current entry.
		 */
		fs = pp->i_fs;
		lbn = lblkno(fs, u.u_offset);
		base = blkoff(fs, u.u_offset);
		bn = fsbtodb(fs, bmap(pp, lbn, B_WRITE, base + u.u_count));
		bp = bread(pp->i_dev, bn, blksize(fs, pp, lbn));
		if (bp->b_flags & B_ERROR) {
			brelse(bp);
			goto out;
		}
		((struct direct *)(bp->b_un.b_addr + base))->d_reclen +=
		    u.u_dent.d_reclen;
I 35
/*ZZ*/if(((int)(bp->b_un.b_addr + base)&0x1ff)+u.u_dent.d_reclen>512)
/*ZZ*/	panic("unlink: reclen");
E 35
		bwrite(bp);
		pp->i_flag |= IUPD|ICHG;
	}
E 28
	ip->i_nlink--;
	ip->i_flag |= ICHG;

E 36
out:
D 31
	iput(ip);
E 31
I 31
D 47
	if (unlinkingdot)
E 47
I 47
	if (dp == ip)
E 47
		irele(ip);
	else
		iput(ip);
E 31
D 47
out1:
	iput(pp);
E 47
I 47
	iput(dp);
E 47
}

/*
 * Seek system call
 */
D 41
seek()
E 41
I 41
lseek()
E 41
{
	register struct file *fp;
	register struct a {
D 37
		int	fdes;
E 37
I 37
		int	fd;
E 37
		off_t	off;
		int	sbase;
D 82
	} *uap;
E 82
I 82
	} *uap = (struct a *)u.u_ap;
E 82

D 82
	uap = (struct a *)u.u_ap;
E 82
D 37
	fp = getf(uap->fdes);
E 37
I 37
D 63
	fp = getf(uap->fd);
E 63
I 63
D 77
	fp = getinode(uap->fd);
E 63
E 37
	if (fp == NULL)
E 77
I 77
	GETF(fp, uap->fd);
	if (fp->f_type != DTYPE_INODE) {
		u.u_error = ESPIPE;
E 77
		return;
I 77
	}
E 77
D 35
	if (fp->f_flag&FSOCKET) {
E 35
I 35
D 63
	if (fp->f_type == DTYPE_SOCKET) {
E 35
		u.u_error = ESPIPE;
		return;
	}
D 37
	if (uap->sbase == 1)
E 37
I 37
	if (uap->sbase == FSEEK_RELATIVE)
E 63
I 63
D 68
	if (uap->sbase == L_INCR)
E 63
E 37
		uap->off += fp->f_offset;
D 33
	else if (uap->sbase == 2)
E 33
I 33
D 37
	else if (uap->sbase == 2) {
#ifdef EFS
		struct inode *ip = fp->f_inode;
		uap->off += efsinode(ip) ? efsfilesize(fp) : ip->i_size;
#else
E 37
I 37
D 63
	else if (uap->sbase == FSEEK_EOF)
E 37
E 33
		uap->off += fp->f_inode->i_size;
E 63
I 63
	else if (uap->sbase == L_XTND)
		uap->off += ((struct inode *)fp->f_data)->i_size;
E 63
I 33
D 37
#endif
	}
E 37
E 33
	fp->f_offset = uap->off;
	u.u_r.r_off = uap->off;
E 68
I 68
	switch (uap->sbase) {

	case L_INCR:
		fp->f_offset += uap->off;
		break;

	case L_XTND:
		fp->f_offset = uap->off + ((struct inode *)fp->f_data)->i_size;
		break;

	case L_SET:
		fp->f_offset = uap->off;
		break;

	default:
		u.u_error = EINVAL;
		return;
	}
	u.u_r.r_off = fp->f_offset;
E 68
}

/*
 * Access system call
 */
saccess()
{
	register svuid, svgid;
	register struct inode *ip;
	register struct a {
		char	*fname;
		int	fmode;
D 82
	} *uap;
E 82
I 82
	} *uap = (struct a *)u.u_ap;
	register struct nameidata *ndp = &u.u_nd;
E 82

D 82
	uap = (struct a *)u.u_ap;
E 82
	svuid = u.u_uid;
	svgid = u.u_gid;
	u.u_uid = u.u_ruid;
	u.u_gid = u.u_rgid;
D 47
	ip = namei(uchar, 0, 1);
E 47
I 47
D 82
	ip = namei(uchar, LOOKUP, 1);
E 82
I 82
	ndp->ni_nameiop = LOOKUP | FOLLOW;
	ndp->ni_segflg = UIO_USERSPACE;
	ndp->ni_dirp = uap->fname;
	ip = namei(ndp);
E 82
E 47
I 33
D 37
#ifdef EFS
	if (efsinode(ip)) {
		dev_t ndev = ip->i_rdev;

		iput(ip);
		efssaccess(ndev);
		if (u.u_error != EEXIST)
			return;
		u.u_error = 0;
		u.u_dirp = (caddr_t)u.u_arg[0];
		ip = namei(uchar, 0, 1);
	}
#endif
E 37
E 33
	if (ip != NULL) {
D 37
		if (uap->fmode&(IREAD>>6))
			(void) access(ip, IREAD);
		if (uap->fmode&(IWRITE>>6))
			(void) access(ip, IWRITE);
		if (uap->fmode&(IEXEC>>6))
			(void) access(ip, IEXEC);
E 37
I 37
D 47
		if (uap->fmode&FACCESS_READ && access(ip, IREAD))
E 47
I 47
D 63
		if ((uap->fmode&FACCESS_READ) && access(ip, IREAD))
E 63
I 63
		if ((uap->fmode&R_OK) && access(ip, IREAD))
E 63
E 47
			goto done;
D 47
		if (uap->fmode&FACCESS_WRITE && access(ip, IWRITE))
E 47
I 47
D 63
		if ((uap->fmode&FACCESS_WRITE) && access(ip, IWRITE))
E 63
I 63
		if ((uap->fmode&W_OK) && access(ip, IWRITE))
E 63
E 47
			goto done;
D 47
		if (uap->fmode&FACCESS_EXECUTE && access(ip, IEXEC))
E 47
I 47
D 63
		if ((uap->fmode&FACCESS_EXECUTE) && access(ip, IEXEC))
E 63
I 63
		if ((uap->fmode&X_OK) && access(ip, IEXEC))
E 63
E 47
			goto done;
done:
E 37
		iput(ip);
	}
	u.u_uid = svuid;
	u.u_gid = svgid;
}

/*
E 26
D 63
 * the fstat system call.
 */
fstat()
{
	register struct file *fp;
	register struct a {
D 37
		int	fdes;
E 37
I 37
		int	fd;
E 37
		struct stat *sb;
	} *uap;

	uap = (struct a *)u.u_ap;
D 37
	fp = getf(uap->fdes);
E 37
I 37
	fp = getf(uap->fd);
E 37
D 17
	if(fp == NULL)
E 17
I 17
	if (fp == NULL)
E 17
		return;
I 33
D 37
#ifdef EFS
	if (efsinode(fp->f_inode)) {
		efsfstat(fp->f_inode->i_rdev, fp);
		return;
	}
#endif
E 37
E 33
D 15
	stat1(fp->f_inode, uap->sb, fp->f_flag&FPIPE? fp->f_un.f_offset: 0);
E 15
I 15
D 17
	if (fp->f_flag&FPORT) {
		ptstat(fp);
		return;
	}
I 16
#ifdef BBNNET
	if (fp->f_flag&FNET) {
	    	u.u_error = EINVAL;
		return;
	}
#endif
E 16
	stat1(fp->f_inode, uap->sb);
E 17
I 17
D 35
	if (fp->f_flag & FSOCKET)
E 35
I 35
	if (fp->f_type == DTYPE_SOCKET)
E 35
D 18
		sostat(fp->f_socket);
E 18
I 18
		u.u_error = sostat(fp->f_socket, uap->sb);
E 18
	else
		stat1(fp->f_inode, uap->sb);
E 17
E 15
}

/*
E 63
D 17
 * the stat system call.
E 17
I 17
D 23
 * Stat system call.
E 23
I 23
D 27
 * Stat system call.  This version does not follow links.
E 27
I 27
D 28
 * Stat system call; this follows links.
E 28
I 28
 * Stat system call.  This version follows links.
E 28
E 27
E 23
E 17
 */
stat()
{
D 63
	register struct inode *ip;
	register struct a {
		char	*fname;
		struct stat *sb;
	} *uap;
E 63

D 63
	uap = (struct a *)u.u_ap;
D 23
	ip = namei(uchar, 0);
E 23
I 23
D 27
	ip = namei(uchar, 0, 0);
E 27
I 27
D 47
	ip = namei(uchar, 0, 1);
E 47
I 47
	ip = namei(uchar, LOOKUP, 1);
E 47
E 27
E 23
D 17
	if(ip == NULL)
E 17
I 17
	if (ip == NULL)
E 17
		return;
I 33
D 37
#ifdef EFS
	if (efsinode(ip)) {
		dev_t ndev = ip->i_rdev;

		iput(ip);
		efsstat(ndev);
		if (u.u_error != EEXIST)
			return;
		u.u_error = 0;
		u.u_dirp = (caddr_t)u.u_arg[0];
		ip = namei(uchar, 0, 1);
	}
#endif
E 37
E 33
D 15
	stat1(ip, uap->sb, (off_t)0);
E 15
I 15
	stat1(ip, uap->sb);
E 15
	iput(ip);
E 63
I 63
D 82
	stat1(1);
E 82
I 82
	stat1(FOLLOW);
E 82
E 63
}

/*
I 23
D 27
 * Lstat system call.  This version does follow links.
E 27
I 27
D 28
 * Lstat system call; like stat but doesn't follow links.
E 28
I 28
 * Lstat system call.  This version does not follow links.
E 28
E 27
 */
lstat()
{
I 63

D 82
	stat1(0);
E 82
I 82
	stat1(NOFOLLOW);
E 82
}

stat1(follow)
	int follow;
{
E 63
	register struct inode *ip;
	register struct a {
		char	*fname;
D 63
		struct stat *sb;
E 63
I 63
		struct stat *ub;
E 63
D 82
	} *uap;
E 82
I 82
	} *uap = (struct a *)u.u_ap;
E 82
I 63
	struct stat sb;
I 82
	register struct nameidata *ndp = &u.u_nd;
E 82
E 63

D 82
	uap = (struct a *)u.u_ap;
D 27
	ip = namei(uchar, 0, 1);
E 27
I 27
D 47
	ip = namei(uchar, 0, 0);
E 47
I 47
D 63
	ip = namei(uchar, LOOKUP, 0);
E 63
I 63
	ip = namei(uchar, LOOKUP, follow);
E 82
I 82
	ndp->ni_nameiop = LOOKUP | follow;
	ndp->ni_segflg = UIO_USERSPACE;
	ndp->ni_dirp = uap->fname;
	ip = namei(ndp);
E 82
E 63
E 47
E 27
	if (ip == NULL)
		return;
I 33
D 37
#ifdef EFS
	if (efsinode(ip)) {
		dev_t ndev = ip->i_rdev;

		iput(ip);
		efslstat(ndev);
		if (u.u_error != EEXIST)
			return;
		u.u_error = 0;
		u.u_dirp = (caddr_t)u.u_arg[0];
		ip = namei(uchar, 0, 0);
	}
#endif
E 37
E 33
D 24
	stat1(ip, uap->sb, (off_t)0);
E 24
I 24
D 63
	stat1(ip, uap->sb);
E 63
I 63
D 66
	(void) statinode(ip, &sb);
E 66
I 66
	(void) ino_stat(ip, &sb);
E 66
E 63
E 24
	iput(ip);
I 63
	u.u_error = copyout((caddr_t)&sb, (caddr_t)uap->ub, sizeof (sb));
E 63
}

/*
E 23
D 63
 * The basic routine for fstat and stat:
 * get the inode and pass appropriate parts back.
 */
D 15
stat1(ip, ub, pipeadj)
E 15
I 15
stat1(ip, ub)
E 15
D 17
register struct inode *ip;
struct stat *ub;
E 17
I 17
	register struct inode *ip;
	struct stat *ub;
E 17
D 15
off_t pipeadj;
E 15
{
D 28
	register struct dinode *dp;
	register struct buf *bp;
E 28
	struct stat ds;

D 2
	iupdat(ip, &time, &time);
E 2
I 2
D 5
	IUPDAT(ip, &time, &time);
E 5
I 5
D 41
	IUPDAT(ip, &time, &time, 0);
E 41
I 41
D 45
	IUPDAT(ip, &time.tv_sec, &time.tv_sec, 0);
E 45
I 45
D 46
	IUPDAT(ip, time, time, 0);
E 46
I 46
	IUPDAT(ip, &time, &time, 0);
E 46
E 45
E 41
E 5
E 2
	/*
D 17
	 * first copy from inode table
E 17
I 17
D 29
	 * First copy from inode table
E 29
I 29
	 * Copy from inode table
E 29
E 17
	 */
	ds.st_dev = ip->i_dev;
	ds.st_ino = ip->i_number;
	ds.st_mode = ip->i_mode;
	ds.st_nlink = ip->i_nlink;
	ds.st_uid = ip->i_uid;
	ds.st_gid = ip->i_gid;
D 28
	ds.st_rdev = (dev_t)ip->i_un.i_rdev;
E 28
I 28
	ds.st_rdev = (dev_t)ip->i_rdev;
E 28
D 15
	ds.st_size = ip->i_size - pipeadj;
E 15
I 15
	ds.st_size = ip->i_size;
E 15
D 28
	/*
D 17
	 * next the dates in the disk
E 17
I 17
D 23
	 * Next the dates in the disk
E 23
I 23
	 * next the dates in the disk
E 23
E 17
	 */
	bp = bread(ip->i_dev, itod(ip->i_number));
	dp = bp->b_un.b_dino;
	dp += itoo(ip->i_number);
	ds.st_atime = dp->di_atime;
	ds.st_mtime = dp->di_mtime;
	ds.st_ctime = dp->di_ctime;
	brelse(bp);
E 28
I 28
	ds.st_atime = ip->i_atime;
I 50
	ds.st_spare1 = 0;
E 50
	ds.st_mtime = ip->i_mtime;
I 50
	ds.st_spare2 = 0;
E 50
	ds.st_ctime = ip->i_ctime;
I 50
	ds.st_spare3 = 0;
E 50
I 29
D 37
	ds.st_blksize = ip->i_fs->fs_bsize;
E 37
I 37
	/* this doesn't belong here */
	if ((ip->i_mode&IFMT) == IFBLK)
		ds.st_blksize = BLKDEV_IOSIZE;
	else if ((ip->i_mode&IFMT) == IFCHR)
		ds.st_blksize = MAXBSIZE;
	else
		ds.st_blksize = ip->i_fs->fs_bsize;
I 50
D 62
	ds.st_spare4[0] = ds.st_spare4[1] = ds.st_spare4[2] = 0;
E 62
I 62
	ds.st_blocks = ip->i_blocks;
	ds.st_spare4[0] = ds.st_spare4[1] = 0;
E 62
E 50
E 37
E 29
E 28
D 51
	if (copyout((caddr_t)&ds, (caddr_t)ub, sizeof(ds)) < 0)
		u.u_error = EFAULT;
E 51
I 51
	u.u_error = copyout((caddr_t)&ds, (caddr_t)ub, sizeof(ds));
E 51
}

/*
E 63
D 17
 * the dup system call.
E 17
I 17
D 23
 * Dup system call.
E 23
I 23
 * Return target name of a symbolic link
E 23
E 17
 */
I 23
readlink()
{
	register struct inode *ip;
	register struct a {
		char	*name;
		char	*buf;
		int	count;
D 39
	} *uap;
E 39
I 39
	} *uap = (struct a *)u.u_ap;
I 82
	register struct nameidata *ndp = &u.u_nd;
E 82
	int resid;
E 39

D 47
	ip = namei(uchar, 0, 0);
E 47
I 47
D 82
	ip = namei(uchar, LOOKUP, 0);
E 82
I 82
	ndp->ni_nameiop = LOOKUP;
	ndp->ni_segflg = UIO_USERSPACE;
	ndp->ni_dirp = uap->name;
	ip = namei(ndp);
E 82
E 47
	if (ip == NULL)
		return;
I 33
D 37
#ifdef EFS
	if (efsinode(ip)) {
		dev_t ndev = ip->i_rdev;

		iput(ip);
		efsreadlink(ndev);
		if (u.u_error != EEXIST)
			return;
		u.u_error = 0;
		u.u_dirp = (caddr_t)u.u_arg[0];
		ip = namei(uchar, 0, 0);
		return (0);
	}
#endif
E 37
E 33
	if ((ip->i_mode&IFMT) != IFLNK) {
D 89
		u.u_error = ENXIO;
E 89
I 89
		u.u_error = EINVAL;
E 89
		goto out;
	}
D 39
	uap = (struct a *)u.u_ap;
D 38
	u.u_offset = 0;
	u.u_base = uap->buf;
	u.u_count = uap->count;
	u.u_segflg = 0;
	readi(ip);
E 38
I 38
	u.u_error = readip1(ip, uap->buf, uap->count, 0, 0, 0);
E 39
I 39
D 94
	u.u_error = rdwri(UIO_READ, ip, uap->buf, uap->count, 0, 0, &resid);
E 94
I 94
	u.u_error = rdwri(UIO_READ, ip, uap->buf, uap->count, (off_t)0, 0,
	    &resid);
E 94
E 39
E 38
out:
	iput(ip);
D 39
	u.u_r.r_val1 = uap->count - u.u_count;
E 39
I 39
	u.u_r.r_val1 = uap->count - resid;
E 39
}

I 47
/*
 * Change mode of a file given path name.
 */
E 47
D 26
/*
 * symlink -- make a symbolic link
 */
symlink()
E 26
I 26
chmod()
E 26
{
I 26
D 37
	register struct inode *ip;
E 26
	register struct a {
E 37
I 37
	struct inode *ip;
	struct a {
E 37
D 26
		char	*target;
		char	*linkname;
E 26
I 26
		char	*fname;
		int	fmode;
E 26
D 82
	} *uap;
E 82
I 82
	} *uap = (struct a *)u.u_ap;
E 82
D 26
	register struct inode *ip;
	register char *tp;
	register c, nc;
E 26

D 82
	uap = (struct a *)u.u_ap;
D 26
	tp = uap->target;
	nc = 0;
	while (c = fubyte(tp)) {
		if (c < 0) {
			u.u_error = EFAULT;
			return;
		}
		tp++;
		nc++;
	}
	u.u_dirp = uap->linkname;
	ip = namei(uchar, 1, 0);
	if (ip) {
		iput(ip);
		u.u_error = EEXIST;
E 26
I 26
	if ((ip = owner(1)) == NULL)
E 82
I 82
	if ((ip = owner(uap->fname, FOLLOW)) == NULL)
E 82
E 26
		return;
I 33
D 37
#ifdef EFS
	if (efsinode(ip)) {
		dev_t ndev = ip->i_rdev;
E 37
I 37
D 89
	chmod1(ip, uap->fmode);
E 89
I 89
	u.u_error = chmod1(ip, uap->fmode);
E 89
I 47
	iput(ip);
E 47
}
E 37

I 47
/*
 * Change mode of a file given a file descriptor.
 */
E 47
D 37
		iput(ip);
		efschmod(ndev);
		if (u.u_error != EEXIST)
			return;
		u.u_error = 0;
		u.u_dirp = (caddr_t)u.u_arg[0];
		ip = owner(1);
E 37
I 37
fchmod()
{
	struct a {
		int	fd;
		int	fmode;
D 82
	} *uap;
E 82
I 82
	} *uap = (struct a *)u.u_ap;
E 82
	register struct inode *ip;
	register struct file *fp;

D 82
	uap = (struct a *)u.u_ap;
E 82
D 63
	fp = getf(uap->fd);
E 63
I 63
	fp = getinode(uap->fd);
E 63
	if (fp == NULL)
		return;
D 63
	if (fp->f_type == DTYPE_SOCKET) {
		u.u_error = EINVAL;
		return;
E 37
	}
D 37
#endif
E 37
I 37
	ip = fp->f_inode;
E 63
I 63
	ip = (struct inode *)fp->f_data;
E 63
D 47
	ilock(ip);
	if (u.u_uid != ip->i_uid && !suser()) {
		iunlock(ip);
E 47
I 47
	if (u.u_uid != ip->i_uid && !suser())
E 47
		return;
D 47
	}
E 47
I 47
D 81
	ilock(ip);
E 81
I 81
	ILOCK(ip);
E 81
E 47
D 89
	chmod1(ip, uap->fmode);
E 89
I 89
	u.u_error = chmod1(ip, uap->fmode);
E 89
I 47
D 81
	iunlock(ip);
E 81
I 81
	IUNLOCK(ip);
E 81
E 47
}

I 47
/*
 * Change the mode on a file.
 * Inode must be locked before calling.
 */
E 47
chmod1(ip, mode)
	register struct inode *ip;
	register int mode;
{
I 40
D 63
	register int *gp;
E 63

I 89
	if (ip->i_fs->fs_ronly)
		return (EROFS);
E 89
E 40
E 37
E 33
D 26
	}
I 25
	if (u.u_error)
		return;
E 25
	ip = maknode(IFLNK | 0777);
	if (ip == NULL)
		return;
	u.u_base = uap->target;
	u.u_count = nc;
	u.u_offset = 0;
	u.u_segflg = 0;
	writei(ip);
E 26
I 26
	ip->i_mode &= ~07777;
D 33
	if (u.u_uid)
E 33
I 33
	if (u.u_uid) {
E 33
D 37
		uap->fmode &= ~ISVTX;
E 37
I 37
D 89
		mode &= ~ISVTX;
E 89
I 89
		if ((ip->i_mode & IFMT) != IFDIR)
			mode &= ~ISVTX;
E 89
I 57
D 60
		if (u.u_gid == ip->i_gid)
			goto ok;
E 57
E 37
I 33
D 40
		if (ip->i_gid >= NGRPS ||
		    (u.u_grps[ip->i_gid/(sizeof(int)*8)] &
		     (1 << ip->i_gid%(sizeof(int)*8))) == 0)
D 37
			uap->fmode &= ~ISGID;
I 34
#if	MUSH
E 37
I 37
			mode &= ~ISGID;
E 40
I 40
		for (gp = u.u_groups; gp < &u.u_groups[NGROUPS]; gp++)
			if (*gp == ip->i_gid)
				goto ok;
		mode &= ~ISGID;
ok:
		;
E 60
I 60
		if (!groupmember(ip->i_gid))
			mode &= ~ISGID;
E 60
E 40
D 62
#ifdef MUSH
E 37
D 60
		if (u.u_quota->q_syflags & QF_UMASK && u.u_uid != 0 &&
E 60
I 60
		if (u.u_quota->q_syflags & QF_UMASK && 
E 60
		    (ip->i_mode & IFMT) != IFCHR)
D 37
			uap->fmode &= ~u.u_cmask;
E 37
I 37
			mode &= ~u.u_cmask;
E 37
#endif
E 62
E 34
	}
E 33
D 37
	ip->i_mode |= uap->fmode&07777;
E 37
I 37
	ip->i_mode |= mode&07777;
E 37
	ip->i_flag |= ICHG;
	if (ip->i_flag&ITEXT && (ip->i_mode&ISVTX)==0)
		xrele(ip);
I 89
	return (0);
E 89
I 34
D 37
#ifdef MELB
	if ((ip->i_mode & ISUID) && ip->i_uid == 0)
		printf("%s: ino %d (%s) setuid root\n"
		    , getfs(ip->i_dev)->s_fsmnt
		    , ip->i_number
		    , u.u_dent.d_name
		);
#endif
E 37
E 34
E 26
D 47
	iput(ip);
E 47
}

I 47
/*
 * Set ownership given a path name.
 */
E 47
D 26
/*
 * the dup system call.
 */
E 23
dup()
E 26
I 26
chown()
E 26
{
D 26
	register struct file *fp;
E 26
I 26
D 37
	register struct inode *ip;
E 26
	register struct a {
E 37
I 37
	struct inode *ip;
	struct a {
E 37
D 26
		int	fdes;
		int	fdes2;
E 26
I 26
		char	*fname;
		int	uid;
		int	gid;
E 26
D 82
	} *uap;
E 82
I 82
	} *uap = (struct a *)u.u_ap;
E 82
I 34
D 37
#if	QUOTA
	register long change;
#endif
E 37
E 34
D 26
	register i, m;
E 26

D 82
	uap = (struct a *)u.u_ap;
D 26
	m = uap->fdes & ~077;
	uap->fdes &= 077;
	fp = getf(uap->fdes);
D 17
	if(fp == NULL)
E 17
I 17
	if (fp == NULL)
E 26
I 26
D 60
	if (!suser() || (ip = owner(0)) == NULL)
E 60
I 60
D 61
	if ((ip = owner(0)) == NULL)
E 61
I 61
	if (!suser() || (ip = owner(0)) == NULL)
E 82
I 82
D 95
	if (!suser() || (ip = owner(uap->fname, NOFOLLOW)) == NULL)
E 95
I 95
	if ((ip = owner(uap->fname, NOFOLLOW)) == NULL)
E 95
E 82
E 61
E 60
E 26
E 17
		return;
D 26
	if ((m&0100) == 0) {
		if ((i = ufalloc()) < 0)
			return;
	} else {
		i = uap->fdes2;
		if (i<0 || i>=NOFILE) {
			u.u_error = EBADF;
			return;
		}
D 17
		if (u.u_vrpages[i]) {
			u.u_error = ETXTBSY;
			return;
		}
E 17
		u.u_r.r_val1 = i;
	}
D 17
	if (i!=uap->fdes) {
E 17
I 17
	if (i != uap->fdes) {
E 17
		if (u.u_ofile[i]!=NULL)
D 22
			closef(u.u_ofile[i]);
E 22
I 22
			closef(u.u_ofile[i], 0);
		if (u.u_error)
			return;
E 22
		u.u_ofile[i] = fp;
		fp->f_count++;
	}
E 26
I 26
D 33
	ip->i_uid = uap->uid;
	ip->i_gid = uap->gid;
E 33
I 33
D 37
#ifdef EFS
	if (efsinode(ip)) {
		dev_t ndev = ip->i_rdev;
E 37
I 37
D 60
	chown1(ip, uap->uid, uap->gid);
E 60
I 60
	u.u_error = chown1(ip, uap->uid, uap->gid);
E 60
I 47
	iput(ip);
E 47
}
E 37

I 47
/*
 * Set ownership given a file descriptor.
 */
E 47
D 37
		iput(ip);
		efschown(ndev);
		if (u.u_error != EEXIST)
			return;
		u.u_error = 0;
		u.u_dirp = (caddr_t)u.u_arg[0];
		ip = owner(0);
E 37
I 37
fchown()
{
	struct a {
		int	fd;
		int	uid;
		int	gid;
D 82
	} *uap;
E 82
I 82
	} *uap = (struct a *)u.u_ap;
E 82
	register struct inode *ip;
	register struct file *fp;

D 82
	uap = (struct a *)u.u_ap;
E 82
D 63
	fp = getf(uap->fd);
E 63
I 63
	fp = getinode(uap->fd);
E 63
	if (fp == NULL)
		return;
D 63
	if (fp->f_type == DTYPE_SOCKET) {
		u.u_error = EINVAL;
		return;
E 37
	}
D 37
#endif
I 34
#if	QUOTA
E 37
I 37
	ip = fp->f_inode;
E 63
I 63
	ip = (struct inode *)fp->f_data;
E 63
D 47
	ilock(ip);
	if (!suser()) {
		iunlock(ip);
E 47
I 47
D 60
	if (!suser())
E 60
I 60
D 61
	if (ip->i_uid != u.u_uid && !suser())
E 61
I 61
D 95
	if (!suser())
E 61
E 60
E 47
		return;
E 95
D 47
	}
E 47
I 47
D 81
	ilock(ip);
E 81
I 81
	ILOCK(ip);
E 81
E 47
D 60
	chown1(ip, uap->uid, uap->gid);
E 60
I 60
	u.u_error = chown1(ip, uap->uid, uap->gid);
E 60
I 47
D 81
	iunlock(ip);
E 81
I 81
	IUNLOCK(ip);
E 81
E 47
}

/*
 * Perform chown operation on inode ip;
 * inode must be locked prior to call.
 */
chown1(ip, uid, gid)
	register struct inode *ip;
	int uid, gid;
{
#ifdef QUOTA
	register long change;
I 60
#endif
E 60

I 89
	if (ip->i_fs->fs_ronly)
		return (EROFS);
E 89
I 60
	if (uid == -1)
		uid = ip->i_uid;
	if (gid == -1)
		gid = ip->i_gid;
I 95
	if (uid != ip->i_uid && !suser())
		return (u.u_error);
	if (gid != ip->i_gid && !groupmember((gid_t)gid) && !suser())
		return (u.u_error);
E 95
D 61
	if (u.u_uid && ip->i_gid != gid && !groupmember(gid))
		return (EPERM);
E 61
#ifdef QUOTA
E 60
E 37
E 34
D 62
	/*
I 34
	 * This doesn't allow for holes in files (which hopefully don't
	 * happen often in files that we chown), and is not accurate anyway
	 * (eg: it totally ignores 3 level indir blk files - but hopefully
	 * noone who can make a file that big will have a quota)
	 */
D 37
	if (ip->i_uid == uap->uid)
E 37
I 37
	if (ip->i_uid == uid)
E 62
I 62
D 70
	if (ip->i_uid != uid)		/* this just speeds things a little */
E 70
I 70
	if (ip->i_uid == uid)		/* this just speeds things a little */
E 70
E 62
E 37
		change = 0;
D 62
	else {
		register struct fs *fs = ip->i_fs;

		if (ip->i_size > (change = NDADDR * fs->fs_bsize)) {
			register off_t size;

			size = blkroundup(fs, ip->i_size) - change;
			change += size;
			change += fs->fs_bsize;
D 37
			/* This assumes NIADDR <= 2 */
E 37
I 37
			/* this assumes NIADDR <= 2 */
E 37
			if (size > NINDIR(fs) * fs->fs_bsize)
				change += fs->fs_bsize;
		} else
			change = fragroundup(fs, ip->i_size);
		change /= DEV_BSIZE;
	}
D 47
	chkdq(ip, -change, 1);
	chkiq(ip->i_dev, ip, ip->i_uid, 1);
E 47
I 47
	(void)chkdq(ip, -change, 1);
	(void)chkiq(ip->i_dev, ip, ip->i_uid, 1);
E 62
I 62
	else
		change = ip->i_blocks;
	(void) chkdq(ip, -change, 1);
	(void) chkiq(ip->i_dev, ip, ip->i_uid, 1);
E 62
E 47
	dqrele(ip->i_dquot);
#endif
D 60
	/*
E 34
D 37
	 * keep uid/gid's in sane range - no err, so chown(file, uid, -1)
	 * will do something useful
E 37
I 37
	 * keep uid/gid's in sane range -- no err,
	 * so chown(file, uid, -1) will do something useful
E 37
	 */
D 37
	if (uap->uid >= 0 && uap->uid <= 32767)	/* should have a const	*/
		ip->i_uid = uap->uid;
	if (uap->gid >= 0 && uap->gid <= 32767)	/* same here		*/
		ip->i_gid = uap->gid;
E 37
I 37
	if (uid >= 0 && uid <= 32767)	/* should have a constant */
		ip->i_uid = uid;
	if (gid >= 0 && gid <= 32767)	/* same here */
		ip->i_gid = gid;
E 60
I 60
	ip->i_uid = uid;
	ip->i_gid = gid;
E 60
E 37
E 33
	ip->i_flag |= ICHG;
	if (u.u_ruid != 0)
		ip->i_mode &= ~(ISUID|ISGID);
I 34
D 37
#if	QUOTA
E 37
I 37
#ifdef QUOTA
E 37
	ip->i_dquot = inoquota(ip);
D 47
	chkdq(ip, change, 1);
D 37
	chkiq(ip->i_dev, NULL, uap->uid, 1);
E 37
I 37
	chkiq(ip->i_dev, NULL, uid, 1);
E 47
I 47
D 62
	(void)chkdq(ip, change, 1);
	(void)chkiq(ip->i_dev, (struct inode *)NULL, uid, 1);
I 60
	return (u.u_error);
E 60
E 47
E 37
#endif
E 62
I 62
	(void) chkdq(ip, change, 1);
D 94
	(void) chkiq(ip->i_dev, (struct inode *)NULL, uid, 1);
E 94
I 94
	(void) chkiq(ip->i_dev, (struct inode *)NULL, (uid_t)uid, 1);
E 94
	return (u.u_error);		/* should == 0 ALWAYS !! */
#else
E 62
I 60
	return (0);
I 62
#endif
E 62
E 60
E 34
D 47
	iput(ip);
E 47
E 26
}

I 60
D 65
#ifndef NOCOMPAT
E 60
/*
D 17
 * the mount system call.
E 17
I 17
D 26
 * Mount system call.
E 26
I 26
 * Set IUPD and IACC times on file.
 * Can't set ICHG.
E 26
E 17
 */
D 13
smount()
{
E 13
I 13
D 17
smount() {
E 17
I 17
D 26
smount()
E 26
I 26
D 42
utime()
E 42
I 42
outime()
E 42
E 26
{
E 17
E 13
D 26
	dev_t dev;
	register struct inode *ip;
	register struct mount *mp;
	struct mount *smp;
	register struct filsys *fp;
	struct buf *bp;
E 26
	register struct a {
D 26
		char	*fspec;
		char	*freg;
		int	ronly;
E 26
I 26
		char	*fname;
		time_t	*tptr;
E 26
D 60
	} *uap;
E 60
I 60
	} *uap = (struct a *)u.u_ap;
E 60
I 13
D 26
	register char *cp;
E 26
I 26
	register struct inode *ip;
	time_t tv[2];
I 45
	struct timeval tv0, tv1;
E 45
E 26
E 13

D 60
	uap = (struct a *)u.u_ap;
E 60
D 26
	dev = getmdev();
D 17
	if(u.u_error)
E 17
I 17
	if (u.u_error)
E 26
I 26
	if ((ip = owner(1)) == NULL)
E 26
E 17
		return;
D 26
	u.u_dirp = (caddr_t)uap->freg;
D 23
	ip = namei(uchar, 0);
E 23
I 23
	ip = namei(uchar, 0, 1);
E 23
D 17
	if(ip == NULL)
E 17
I 17
	if (ip == NULL)
E 17
		return;
D 17
	if(ip->i_count!=1 || (ip->i_mode&(IFBLK&IFCHR))!=0)
E 17
I 17
	if (ip->i_count!=1 || (ip->i_mode&IFMT) != IFDIR)
E 17
		goto out;
	smp = NULL;
D 17
	for(mp = &mount[0]; mp < &mount[NMOUNT]; mp++) {
		if(mp->m_bufp != NULL) {
			if(dev == mp->m_dev)
E 17
I 17
	for (mp = &mount[0]; mp < &mount[NMOUNT]; mp++) {
		if (mp->m_bufp != NULL) {
			if (dev == mp->m_dev)
E 17
				goto out;
		} else
D 17
		if(smp == NULL)
E 17
I 17
		if (smp == NULL)
E 17
			smp = mp;
E 26
I 26
D 51
	if (copyin((caddr_t)uap->tptr, (caddr_t)tv, sizeof(tv))) {
		u.u_error = EFAULT;
	} else {
E 51
I 51
D 60
	u.u_error = copyin((caddr_t)uap->tptr, (caddr_t)tv, sizeof(tv));
E 60
I 60
	u.u_error = copyin((caddr_t)uap->tptr, (caddr_t)tv, sizeof (tv));
E 60
	if (u.u_error == 0) {
E 51
I 33
D 37
#ifdef EFS
		if (efsinode(ip)) {
			dev_t ndev = ip->i_rdev;

			iput(ip);
			efsutime(ndev, uap->fname, tv);
			if (u.u_error != EEXIST)
				return;
			u.u_error = 0;
			u.u_dirp = (caddr_t)u.u_arg[0];
			ip = owner(1);
		}
#endif
E 37
E 33
		ip->i_flag |= IACC|IUPD|ICHG;
D 45
		iupdat(ip, &tv[0], &tv[1], 0);
E 45
I 45
		tv0.tv_sec = tv[0]; tv0.tv_usec = 0;
		tv1.tv_sec = tv[1]; tv1.tv_usec = 0;
		iupdat(ip, &tv0, &tv1, 0);
E 45
E 26
	}
D 26
	mp = smp;
D 17
	if(mp == NULL)
E 17
I 17
	if (mp == NULL)
E 17
		goto out;
	(*bdevsw[major(dev)].d_open)(dev, !uap->ronly);
D 17
	if(u.u_error)
E 17
I 17
	if (u.u_error)
E 17
		goto out;
	bp = bread(dev, SUPERB);
D 17
	if(u.u_error) {
E 17
I 17
	if (u.u_error) {
E 17
		brelse(bp);
		goto out1;
	}
	mp->m_inodp = ip;
	mp->m_dev = dev;
D 9
	mp->m_bufp = geteblk();
	bcopy((caddr_t)bp->b_un.b_addr, mp->m_bufp->b_un.b_addr, BSIZE);
	fp = mp->m_bufp->b_un.b_filsys;
E 9
I 9
	bp->b_flags |= B_LOCKED;
	mp->m_bufp = bp;
	fp = bp->b_un.b_filsys;
E 9
	fp->s_ilock = 0;
	fp->s_flock = 0;
	fp->s_ronly = uap->ronly & 1;
	fp->s_nbehind = 0;
	fp->s_lasti = 1;
I 13
	u.u_dirp = uap->freg;
	for (cp = fp->s_fsmnt; cp < &fp->s_fsmnt[sizeof (fp->s_fsmnt) - 1]; )
		if ((*cp++ = uchar()) == 0)
			u.u_dirp--;		/* get 0 again */
	*cp = 0;
E 13
	brelse(bp);
	ip->i_flag |= IMOUNT;
D 17
	prele(ip);
E 17
I 17
	irele(ip);
E 17
	return;

out:
	u.u_error = EBUSY;
out1:
E 26
	iput(ip);
}
I 60
#endif
E 60

E 65
I 60
utimes()
{
	register struct a {
		char	*fname;
		struct	timeval *tptr;
	} *uap = (struct a *)u.u_ap;
	register struct inode *ip;
	struct timeval tv[2];

D 82
	if ((ip = owner(1)) == NULL)
E 82
I 82
	if ((ip = owner(uap->fname, FOLLOW)) == NULL)
E 82
		return;
I 89
	if (ip->i_fs->fs_ronly) {
		u.u_error = EROFS;
		iput(ip);
		return;
	}
E 89
	u.u_error = copyin((caddr_t)uap->tptr, (caddr_t)tv, sizeof (tv));
	if (u.u_error == 0) {
		ip->i_flag |= IACC|IUPD|ICHG;
		iupdat(ip, &tv[0], &tv[1], 0);
	}
	iput(ip);
}

E 60
I 47
/*
 * Flush any pending I/O.
 */
E 47
D 26
/*
 * the umount system call.
 */
sumount()
E 26
I 26
sync()
E 26
{
D 26
	dev_t dev;
	register struct inode *ip;
	register struct mount *mp;
	struct buf *bp;
I 8
D 9
	int flag;
	int stillopen = 0;
E 9
I 9
	int stillopen, flag;
E 9
E 8
	register struct a {
		char	*fspec;
	};
E 26

D 26
	dev = getmdev();
D 17
	if(u.u_error)
E 17
I 17
	if (u.u_error)
E 17
		return;
	xumount(dev);	/* remove unused sticky files from text table */
E 26
D 21
	update();
E 21
I 21
D 46
	update(0);
E 46
I 46
	update();
E 46
I 36
D 66
}

I 47
/*
 * Apply an advisory lock on a file descriptor.
 */
E 47
I 37
flock()
{
D 63
	struct a {
E 63
I 63
	register struct a {
E 63
		int	fd;
		int	how;
D 63
	} *uap;
E 63
I 63
	} *uap = (struct a *)u.u_ap;
E 63
	register struct file *fp;
	register int cmd, flags;

D 63
	uap = (struct a *)u.u_ap;
	fp = getf(uap->fd);
E 63
I 63
	fp = getinode(uap->fd);
E 63
	if (fp == NULL)
		return;
D 63
	if (fp->f_type == DTYPE_SOCKET) {		/* XXX */
		u.u_error = EINVAL;
		return;
	}
E 63
	cmd = uap->how;
D 47
	flags = u.u_pofile[uap->fd] & (RDLOCK|WRLOCK);
E 47
I 47
D 48
	flags = u.u_pofile[uap->fd] & (SHLOCK|EXLOCK);
E 48
I 48
	flags = u.u_pofile[uap->fd] & (UF_SHLOCK|UF_EXLOCK);
E 48
E 47
D 63
	if (cmd&FUNLOCK) {
E 63
I 63
	if (cmd&LOCK_UN) {
E 63
		if (flags == 0) {
			u.u_error = EINVAL;
			return;
		}
D 63
		funlocki(fp->f_inode, flags);
E 63
I 63
		funlocki((struct inode *)fp->f_data, flags);
E 63
D 47
		u.u_pofile[uap->fd] &= ~(RDLOCK|WRLOCK);
E 47
I 47
D 48
		u.u_pofile[uap->fd] &= ~(SHLOCK|EXLOCK);
E 48
I 48
		u.u_pofile[uap->fd] &= ~(UF_SHLOCK|UF_EXLOCK);
E 48
E 47
		return;
	}
	/*
	 * No reason to write lock a file we've already
	 * write locked, similarly with a read lock.
	 */
D 47
	if ((flags&WRLOCK) && (cmd&FWRLOCK) ||
	    (flags&RDLOCK) && (cmd&FRDLOCK))
E 47
I 47
D 48
	if ((flags&EXLOCK) && (cmd&FEXLOCK) ||
	    (flags&SHLOCK) && (cmd&FSHLOCK))
E 48
I 48
D 63
	if ((flags&UF_EXLOCK) && (cmd&FEXLOCK) ||
	    (flags&UF_SHLOCK) && (cmd&FSHLOCK))
E 63
I 63
	if ((flags&UF_EXLOCK) && (cmd&LOCK_EX) ||
	    (flags&UF_SHLOCK) && (cmd&LOCK_SH))
E 63
E 48
E 47
		return;
D 63
	u.u_pofile[uap->fd] = flocki(fp->f_inode, u.u_pofile[uap->fd], cmd);
E 63
I 63
	u.u_pofile[uap->fd] =
	    flocki((struct inode *)fp->f_data, u.u_pofile[uap->fd], cmd);
E 66
E 63
}

I 47
/*
 * Truncate a file given its path name.
 */
E 47
truncate()
{
	struct a {
		char	*fname;
D 47
		int	length;
E 47
I 47
D 95
		u_long	length;
E 95
I 95
		off_t	length;
E 95
E 47
D 39
	} *uap;
E 39
I 39
	} *uap = (struct a *)u.u_ap;
E 39
	struct inode *ip;
I 82
	register struct nameidata *ndp = &u.u_nd;
E 82

D 47
	ip = namei(uchar, 0, 1);
E 47
I 47
D 82
	ip = namei(uchar, LOOKUP, 1);
E 82
I 82
	ndp->ni_nameiop = LOOKUP | FOLLOW;
	ndp->ni_segflg = UIO_USERSPACE;
	ndp->ni_dirp = uap->fname;
	ip = namei(ndp);
E 82
E 47
	if (ip == NULL)
		return;
	if (access(ip, IWRITE))
		goto bad;
	if ((ip->i_mode&IFMT) == IFDIR) {
		u.u_error = EISDIR;
		goto bad;
	}
D 95
	itrunc(ip, uap->length);
E 95
I 95
	itrunc(ip, (u_long)uap->length);
E 95
D 47
	return;
E 47
bad:
	iput(ip);
}

I 47
/*
 * Truncate a file given a file descriptor.
 */
E 47
ftruncate()
{
	struct a {
		int	fd;
D 47
		int	length;
E 47
I 47
D 95
		u_long	length;
E 95
I 95
		off_t	length;
E 95
E 47
D 39
	} *uap;
E 39
I 39
	} *uap = (struct a *)u.u_ap;
E 39
	struct inode *ip;
	struct file *fp;

D 63
	fp = getf(uap->fd);
E 63
I 63
	fp = getinode(uap->fd);
E 63
	if (fp == NULL)
		return;
D 63
	if (fp->f_type == DTYPE_SOCKET) {
		u.u_error = EINVAL;
		return;
	}
E 63
	if ((fp->f_flag&FWRITE) == 0) {
		u.u_error = EINVAL;
		return;
	}
D 63
	ip = fp->f_inode;
E 63
I 63
	ip = (struct inode *)fp->f_data;
E 63
D 81
	ilock(ip);
E 81
I 81
	ILOCK(ip);
E 81
D 95
	itrunc(ip, uap->length);
E 95
I 95
	itrunc(ip, (u_long)uap->length);
E 95
I 47
D 81
	iunlock(ip);
E 81
I 81
	IUNLOCK(ip);
E 81
E 47
}

I 47
/*
 * Synch an open file.
 */
fsync()
{
	struct a {
		int	fd;
	} *uap = (struct a *)u.u_ap;
	struct inode *ip;
	struct file *fp;

D 63
	fp = getf(uap->fd);
E 63
I 63
	fp = getinode(uap->fd);
E 63
	if (fp == NULL)
		return;
D 63
	if (fp->f_type == DTYPE_SOCKET) {
		u.u_error = EINVAL;
		return;
	}
	ip = fp->f_inode;
E 63
I 63
	ip = (struct inode *)fp->f_data;
E 63
D 81
	ilock(ip);
E 81
I 81
	ILOCK(ip);
I 97
	if (fp->f_flag&FWRITE)
		ip->i_flag |= ICHG;
E 97
E 81
	syncip(ip);
D 81
	iunlock(ip);
E 81
I 81
	IUNLOCK(ip);
E 81
}

/*
 * Rename system call.
 * 	rename("foo", "bar");
 * is essentially
 *	unlink("bar");
 *	link("foo", "bar");
 *	unlink("foo");
 * but ``atomically''.  Can't do full commit without saving state in the
 * inode on disk which isn't feasible at this time.  Best we can do is
 * always guarantee the target exists.
 *
 * Basic algorithm is:
 *
 * 1) Bump link count on source while we're linking it to the
 *    target.  This also insure the inode won't be deleted out
D 84
 *    from underneath us while we work.
E 84
I 84
 *    from underneath us while we work (it may be truncated by
 *    a concurrent `trunc' or `open' for creation).
E 84
 * 2) Link source to destination.  If destination already exists,
 *    delete it first.
D 84
 * 3) Unlink source reference to inode if still around.
 * 4) If a directory was moved and the parent of the destination
E 84
I 84
 * 3) Unlink source reference to inode if still around. If a
 *    directory was moved and the parent of the destination
E 84
 *    is different from the source, patch the ".." entry in the
 *    directory.
 *
 * Source and destination must either both be directories, or both
 * not be directories.  If target is a directory, it must be empty.
 */
E 47
rename()
{
I 39
D 47
#ifdef notdef
E 47
E 39
	struct a {
		char	*from;
		char	*to;
D 82
	} *uap;
E 82
I 82
	} *uap = (struct a *)u.u_ap;
E 82
I 39
D 47
#endif
E 47
I 47
	register struct inode *ip, *xp, *dp;
I 80
D 84
	struct inode *zp;
E 80
	int oldparent, parentdifferent, doingdirectory;
E 84
I 84
	struct dirtemplate dirbuf;
	int doingdirectory = 0, oldparent = 0, newparent = 0;
E 84
I 82
	register struct nameidata *ndp = &u.u_nd;
E 82
I 52
	int error = 0;
E 52
E 47
E 39

I 47
D 82
	uap = (struct a *)u.u_ap;
D 58
	ip = namei(uchar, LOOKUP | LOCKPARENT, 0);
E 58
I 58
	ip = namei(uchar, DELETE | LOCKPARENT, 0);
E 82
I 82
	ndp->ni_nameiop = DELETE | LOCKPARENT;
	ndp->ni_segflg = UIO_USERSPACE;
	ndp->ni_dirp = uap->from;
	ip = namei(ndp);
E 82
E 58
	if (ip == NULL)
		return;
D 82
	dp = u.u_pdir;
E 82
I 82
	dp = ndp->ni_pdir;
E 82
D 84
	oldparent = 0, doingdirectory = 0;
E 84
	if ((ip->i_mode&IFMT) == IFDIR) {
		register struct direct *d;

D 82
		d = &u.u_dent;
E 82
I 82
		d = &ndp->ni_dent;
E 82
		/*
D 58
		 * Avoid "." and ".." for obvious reasons.
E 58
I 58
		 * Avoid ".", "..", and aliases of "." for obvious reasons.
E 58
		 */
D 58
		if (d->d_name[0] == '.') {
			if (d->d_namlen == 1 ||
			    (d->d_namlen == 2 && d->d_name[1] == '.')) {
E 58
I 58
		if ((d->d_namlen == 1 && d->d_name[0] == '.') ||
		    (d->d_namlen == 2 && bcmp(d->d_name, "..", 2) == 0) ||
D 84
		    (dp == ip)) {
E 84
I 84
		    (dp == ip) || (ip->i_flag & IRENAME)) {
E 84
			iput(dp);
			if (dp == ip)
				irele(ip);
			else
E 58
D 52
				u.u_error = EINVAL;
E 52
				iput(ip);
I 52
D 58
				u.u_error = EINVAL;
E 52
				return;
			}
E 58
I 58
			u.u_error = EINVAL;
			return;
E 58
		}
I 84
		ip->i_flag |= IRENAME;
E 84
		oldparent = dp->i_number;
		doingdirectory++;
	}
D 58
	irele(dp);
E 58
I 58
	iput(dp);
E 58

	/*
	 * 1) Bump link count while we're moving stuff
	 *    around.  If we crash somewhere before
	 *    completing our work, the link count
	 *    may be wrong, but correctable.
	 */
	ip->i_nlink++;
	ip->i_flag |= ICHG;
	iupdat(ip, &time, &time, 1);
D 81
	iunlock(ip);
E 81
I 81
	IUNLOCK(ip);
E 81

	/*
	 * When the target exists, both the directory
	 * and target inodes are returned locked.
	 */
D 82
	u.u_dirp = (caddr_t)uap->to;
D 74
	xp = namei(uchar, CREATE | LOCKPARENT, 0);
E 74
I 74
	xp = namei(uchar, CREATE | LOCKPARENT | NOCACHE, 0);
E 82
I 82
	ndp->ni_nameiop = CREATE | LOCKPARENT | NOCACHE;
	ndp->ni_dirp = (caddr_t)uap->to;
	xp = namei(ndp);
E 82
E 74
D 52
	if (u.u_error)
E 52
I 52
	if (u.u_error) {
		error = u.u_error;
E 52
		goto out;
I 52
	}
E 52
D 82
	dp = u.u_pdir;
E 82
I 82
	dp = ndp->ni_pdir;
E 82
	/*
I 58
	 * If ".." must be changed (ie the directory gets a new
D 64
	 * parent) then the user must have write permission.
E 64
I 64
	 * parent) then the source directory must not be in the
	 * directory heirarchy above the target, as this would
	 * orphan everything below the source directory. Also
	 * the user must have write permission in the source so
	 * as to be able to change "..". We must repeat the call 
	 * to namei, as the parent directory is unlocked by the
	 * call to checkpath().
E 64
	 */
D 84
	parentdifferent = oldparent != dp->i_number;
D 59
	if (parentdifferent && access(ip, IWRITE))
E 59
I 59
D 64
	if (doingdirectory && parentdifferent && access(ip, IWRITE))
E 59
		goto bad;
E 64
I 64
	if (doingdirectory && parentdifferent) {
E 84
I 84
	if (oldparent != dp->i_number)
		newparent = dp->i_number;
	if (doingdirectory && newparent) {
E 84
		if (access(ip, IWRITE))
			goto bad;
		do {
D 82
			dp = u.u_pdir;
E 82
I 82
			dp = ndp->ni_pdir;
E 82
			if (xp != NULL)
				iput(xp);
			u.u_error = checkpath(ip, dp);
			if (u.u_error)
				goto out;
D 82
			u.u_dirp = (caddr_t)uap->to;
D 74
			xp = namei(uchar, CREATE | LOCKPARENT, 0);
E 74
I 74
			xp = namei(uchar, CREATE | LOCKPARENT | NOCACHE, 0);
E 82
I 82
			xp = namei(ndp);
E 82
E 74
			if (u.u_error) {
				error = u.u_error;
				goto out;
			}
D 82
		} while (dp != u.u_pdir);
E 82
I 82
		} while (dp != ndp->ni_pdir);
E 82
	}
E 64
	/*
E 58
	 * 2) If target doesn't exist, link the target
	 *    to the source and unlink the source. 
	 *    Otherwise, rewrite the target directory
	 *    entry to reference the source inode and
	 *    expunge the original entry's existence.
	 */
D 58
	parentdifferent = oldparent != dp->i_number;
E 58
	if (xp == NULL) {
		if (dp->i_dev != ip->i_dev) {
D 52
			u.u_error = EXDEV;
E 52
I 52
			error = EXDEV;
E 52
D 64
			goto bad;
		}
		/*
I 54
		 * Disallow rename(foo, foo/bar).
		 */
		if (dp->i_number == ip->i_number) {
			error = EEXIST;
E 64
			goto bad;
		}
		/*
E 54
D 84
		 * Account for ".." in directory.
		 * When source and destination have the
		 * same parent we don't fool with the
		 * link count -- this isn't required
		 * because we do a similar check below.
E 84
I 84
		 * Account for ".." in new directory.
		 * When source and destination have the same
		 * parent we don't fool with the link count.
E 84
		 */
D 84
		if (doingdirectory && parentdifferent) {
E 84
I 84
		if (doingdirectory && newparent) {
E 84
			dp->i_nlink++;
			dp->i_flag |= ICHG;
			iupdat(dp, &time, &time, 1);
		}
D 55
		direnter(ip);
D 52
		if (u.u_error)
E 52
I 52
		if (u.u_error) {
			error = u.u_error;
E 55
I 55
D 82
		error = direnter(ip);
E 82
I 82
		error = direnter(ip, ndp);
E 82
		if (error)
E 55
E 52
			goto out;
I 52
D 55
		}
E 55
E 52
	} else {
		if (xp->i_dev != dp->i_dev || xp->i_dev != ip->i_dev) {
D 52
			u.u_error = EXDEV;
E 52
I 52
			error = EXDEV;
E 52
			goto bad;
		}
I 54
		/*
		 * Short circuit rename(foo, foo).
		 */
		if (xp->i_number == ip->i_number)
			goto bad;
E 54
		/*
I 91
		 * If the parent directory is "sticky", then the user must
		 * own the parent directory, or the destination of the rename,
		 * otherwise the destination may not be changed (except by
		 * root). This implements append-only directories.
		 */
		if ((dp->i_mode & ISVTX) && u.u_uid != 0 &&
		    u.u_uid != dp->i_uid && xp->i_uid != u.u_uid) {
			error = EPERM;
			goto bad;
		}
		/*
E 91
D 52
		 * Target must be empty if a directory.
E 52
I 52
		 * Target must be empty if a directory
		 * and have no links to it.
E 52
		 * Also, insure source and target are
		 * compatible (both directories, or both
		 * not directories).
		 */
		if ((xp->i_mode&IFMT) == IFDIR) {
D 52
			if (!dirempty(xp)) {
D 49
				u.u_error = EEXIST;	/* XXX */
E 49
I 49
				u.u_error = ENOTEMPTY;
E 52
I 52
D 84
			if (!dirempty(xp) || xp->i_nlink > 2) {
E 84
I 84
			if (!dirempty(xp, dp->i_number) || xp->i_nlink > 2) {
E 84
				error = ENOTEMPTY;
E 52
E 49
				goto bad;
			}
			if (!doingdirectory) {
D 52
				u.u_error = ENOTDIR;
E 52
I 52
				error = ENOTDIR;
E 52
				goto bad;
			}
I 84
			cacheinval(dp);
E 84
		} else if (doingdirectory) {
D 52
			u.u_error = EISDIR;
E 52
I 52
			error = EISDIR;
E 52
			goto bad;
		}
D 82
		dirrewrite(dp, ip);
E 82
I 82
		dirrewrite(dp, ip, ndp);
E 82
D 52
		if (u.u_error)
E 52
I 52
		if (u.u_error) {
			error = u.u_error;
E 52
			goto bad1;
I 52
		}
E 52
		/*
D 52
		 * If this is a directory we know it is
		 * empty and we can squash the inode and
		 * any space associated with it.  Otherwise,
		 * we've got a plain file and the link count
		 * simply needs to be adjusted.
E 52
I 52
		 * Adjust the link count of the target to
		 * reflect the dirrewrite above.  If this is
		 * a directory it is empty and there are
		 * no links to it, so we can squash the inode and
		 * any space associated with it.  We disallowed
		 * renaming over top of a directory with links to
D 84
		 * it above, as we've no way to determine if
		 * we've got a link or the directory itself, and
		 * if we get a link, then ".." will be screwed up.
E 84
I 84
		 * it above, as the remaining link would point to
		 * a directory without "." or ".." entries.
E 84
E 52
		 */
I 52
		xp->i_nlink--;
E 52
		if (doingdirectory) {
D 52
			xp->i_nlink = 0;
E 52
I 52
			if (--xp->i_nlink != 0)
				panic("rename: linked directory");
E 52
			itrunc(xp, (u_long)0);
D 52
		} else
			xp->i_nlink--;
E 52
I 52
		}
E 52
		xp->i_flag |= ICHG;
		iput(xp);
I 53
		xp = NULL;
E 53
	}

	/*
	 * 3) Unlink the source.
	 */
D 82
	u.u_dirp = uap->from;
D 80
	dp = namei(uchar, DELETE, 0);
E 80
I 80
	zp = namei(uchar, DELETE | LOCKPARENT, 0);
	dp = u.u_pdir;
E 82
I 82
	ndp->ni_nameiop = DELETE | LOCKPARENT;
	ndp->ni_segflg = UIO_USERSPACE;
	ndp->ni_dirp = uap->from;
D 84
	zp = namei(ndp);
E 84
I 84
	xp = namei(ndp);
E 84
D 86
	dp = ndp->ni_pdir;
E 86
I 86
	if (xp != NULL)
		dp = ndp->ni_pdir;
	else
		dp = NULL;
E 86
E 82
E 80
	/*
D 84
	 * Insure directory entry still exists and
	 * has not changed since the start of all
	 * this.  If either has occured, forget about
D 79
	 * about deleting the original entry and just
	 * adjust the link count in the inode.
E 79
I 79
	 * about deleting the original entry.
E 84
I 84
	 * Insure that the directory entry still exists and has not
	 * changed while the new name has been entered. If the source is
	 * a file then the entry may have been unlinked or renamed. In
	 * either case there is no further work to be done. If the source
	 * is a directory then it cannot have been rmdir'ed; its link
	 * count of three would cause a rmdir to fail with ENOTEMPTY.
	 * The IRENAME flag insures that it cannot be moved by another
	 * rename.
E 84
E 79
	 */
D 79
	if (dp == NULL || u.u_dent.d_ino != ip->i_number) {
		ip->i_nlink--;
		ip->i_flag |= ICHG;
	} else {
E 79
I 79
D 80
	if (dp != NULL && u.u_dent.d_ino == ip->i_number) {
E 80
I 80
D 84
	if (dp != NULL && zp == ip) {
E 84
I 84
D 86
	if (dp == NULL || xp != ip) {
E 86
I 86
	if (xp != ip) {
E 86
		if (doingdirectory)
D 86
			panic("rename: lost entry");
E 86
I 86
			panic("rename: lost dir entry");
E 86
	} else {
E 84
E 80
E 79
		/*
D 84
		 * If source is a directory, must adjust
		 * link count of parent directory also.
		 * If target didn't exist and source and
		 * target have the same parent, then we
		 * needn't touch the link count, it all
		 * balances out in the end.  Otherwise, we
		 * must do so to reflect deletion of ".."
		 * done above.
E 84
I 84
		 * If the source is a directory with a
		 * new parent, the link count of the old
		 * parent directory must be decremented
		 * and ".." set to point to the new parent.
E 84
		 */
D 84
		if (doingdirectory && (xp != NULL || parentdifferent)) {
E 84
I 84
		if (doingdirectory && newparent) {
E 84
			dp->i_nlink--;
			dp->i_flag |= ICHG;
I 84
			error = rdwri(UIO_READ, xp, (caddr_t)&dirbuf,
				sizeof (struct dirtemplate), (off_t)0, 1,
				(int *)0);
			if (error == 0) {
				if (dirbuf.dotdot_namlen != 2 ||
				    dirbuf.dotdot_name[0] != '.' ||
				    dirbuf.dotdot_name[1] != '.') {
					printf("rename: mangled dir\n");
				} else {
					dirbuf.dotdot_ino = newparent;
					(void) rdwri(UIO_WRITE, xp,
					    (caddr_t)&dirbuf,
					    sizeof (struct dirtemplate),
					    (off_t)0, 1, (int *)0);
					cacheinval(dp);
				}
			}
E 84
		}
D 82
		if (dirremove()) {
E 82
I 82
		if (dirremove(ndp)) {
E 82
D 80
			ip->i_nlink--;
			ip->i_flag |= ICHG;
E 80
I 80
D 84
			zp->i_nlink--;
			zp->i_flag |= ICHG;
E 84
I 84
			xp->i_nlink--;
			xp->i_flag |= ICHG;
E 84
E 80
		}
I 52
D 84
		if (error == 0)		/* conservative */
E 84
I 84
		xp->i_flag &= ~IRENAME;
		if (error == 0)		/* XXX conservative */
E 84
			error = u.u_error;
E 52
	}
I 80
D 84
	if (zp != NULL)
		iput(zp);
E 80
	irele(ip);
E 84
	if (dp)
		iput(dp);
I 84
	if (xp)
		iput(xp);
	irele(ip);
	if (error)
		u.u_error = error;
	return;
E 84

D 84
	/*
	 * 4) Renaming a directory with the parent
	 *    different requires ".." to be rewritten.
	 *    The window is still there for ".." to
	 *    be inconsistent, but this is unavoidable,
	 *    and a lot shorter than when it was done
	 *    in a user process.
	 */
D 52
	if (doingdirectory && parentdifferent && u.u_error == 0) {
E 52
I 52
	if (doingdirectory && parentdifferent && error == 0) {
E 52
		struct dirtemplate dirbuf;

D 82
		u.u_dirp = uap->to;
		ip = namei(uchar, LOOKUP | LOCKPARENT, 0);
E 82
I 82
		ndp->ni_nameiop = LOOKUP | LOCKPARENT;
		ndp->ni_segflg = UIO_USERSPACE;
		ndp->ni_dirp = uap->to;
		ip = namei(ndp);
E 82
		if (ip == NULL) {
			printf("rename: .. went away\n");
			return;
		}
D 82
		dp = u.u_pdir;
E 82
I 82
		dp = ndp->ni_pdir;
E 82
		if ((ip->i_mode&IFMT) != IFDIR) {
			printf("rename: .. not a directory\n");
			goto stuck;
		}
D 52
		u.u_error = rdwri(UIO_READ, ip, (caddr_t)&dirbuf,
E 52
I 52
		error = rdwri(UIO_READ, ip, (caddr_t)&dirbuf,
E 52
			sizeof (struct dirtemplate), (off_t)0, 1, (int *)0);
D 52
		if (u.u_error == 0) {
E 52
I 52
		if (error == 0) {
E 52
			dirbuf.dotdot_ino = dp->i_number;
I 78
D 83
			dp->i_id = ++nextinodeid;
E 83
I 83
			cacheinval(dp);
E 83
E 78
			(void) rdwri(UIO_WRITE, ip, (caddr_t)&dirbuf,
			  sizeof (struct dirtemplate), (off_t)0, 1, (int *)0);
		}
stuck:
		irele(dp);
		iput(ip);
	}
D 52
	return;
E 52
I 52
	goto done;

E 84
E 52
bad:
D 53
	iput(u.u_pdir);
E 53
I 53
	iput(dp);
E 53
bad1:
	if (xp)
D 53
		irele(xp);
E 53
I 53
		iput(xp);
E 53
out:
	ip->i_nlink--;
	ip->i_flag |= ICHG;
	irele(ip);
I 52
D 84
done:
E 84
	if (error)
		u.u_error = error;
E 52
E 47
}

E 37
/*
 * Make a new file.
 */
struct inode *
D 82
maknode(mode)
E 82
I 82
maknode(mode, ndp)
E 82
	int mode;
I 82
	register struct nameidata *ndp;
E 82
{
	register struct inode *ip;
I 82
	register struct inode *pdir = ndp->ni_pdir;
E 82
	ino_t ipref;

	if ((mode & IFMT) == IFDIR)
D 82
		ipref = dirpref(u.u_pdir->i_fs);
E 82
I 82
		ipref = dirpref(pdir->i_fs);
E 82
	else
D 82
		ipref = u.u_pdir->i_number;
	ip = ialloc(u.u_pdir, ipref, mode);
E 82
I 82
		ipref = pdir->i_number;
	ip = ialloc(pdir, ipref, mode);
E 82
	if (ip == NULL) {
D 82
		iput(u.u_pdir);
E 82
I 82
		iput(pdir);
E 82
D 37
		return(NULL);
E 37
I 37
		return (NULL);
E 37
	}
D 37
#ifdef	QUOTA
E 37
I 37
#ifdef QUOTA
E 37
	if (ip->i_dquot != NODQUOT)
		panic("maknode: dquot");
#endif
	ip->i_flag |= IACC|IUPD|ICHG;
	if ((mode & IFMT) == 0)
		mode |= IFREG;
	ip->i_mode = mode & ~u.u_cmask;
	ip->i_nlink = 1;
	ip->i_uid = u.u_uid;
D 82
	ip->i_gid = u.u_pdir->i_gid;
E 82
I 82
	ip->i_gid = pdir->i_gid;
E 82
I 60
D 98
	if (ip->i_mode & ISGID && !groupmember(ip->i_gid))
E 98
I 98
	if (ip->i_mode & ISGID && !groupmember(ip->i_gid) && !suser())
E 98
		ip->i_mode &= ~ISGID;
E 60
D 37
#ifdef	QUOTA
E 37
I 37
#ifdef QUOTA
E 37
	ip->i_dquot = inoquota(ip);
#endif

	/*
	 * Make sure inode goes to disk before directory entry.
	 */
D 41
	iupdat(ip, &time, &time, 1);
E 41
I 41
D 45
	iupdat(ip, &time.tv_sec, &time.tv_sec, 1);
E 45
I 45
D 46
	iupdat(ip, time, time, 1);
E 46
I 46
	iupdat(ip, &time, &time, 1);
E 46
E 45
E 41
D 55
	direnter(ip);
E 55
I 55
D 82
	u.u_error = direnter(ip);
E 82
I 82
	u.u_error = direnter(ip, ndp);
E 82
E 55
	if (u.u_error) {
		/*
D 55
		 * write error occurred trying to update directory
		 * so must deallocate the inode
E 55
I 55
		 * Write error occurred trying to update directory
		 * so must deallocate the inode.
E 55
		 */
		ip->i_nlink = 0;
		ip->i_flag |= ICHG;
		iput(ip);
D 37
		return(NULL);
E 37
I 37
		return (NULL);
E 37
	}
D 37
	return(ip);
E 37
I 37
	return (ip);
I 63
}

/*
 * A virgin directory (no blushing please).
 */
struct dirtemplate mastertemplate = {
	0, 12, 1, ".",
	0, DIRBLKSIZ - 12, 2, ".."
};

/*
 * Mkdir system call
 */
mkdir()
{
	struct a {
		char	*name;
		int	dmode;
D 82
	} *uap;
E 82
I 82
	} *uap = (struct a *)u.u_ap;
E 82
	register struct inode *ip, *dp;
	struct dirtemplate dirtemplate;
I 82
	register struct nameidata *ndp = &u.u_nd;
E 82

D 82
	uap = (struct a *)u.u_ap;
	ip = namei(uchar, CREATE, 0);
E 82
I 82
	ndp->ni_nameiop = CREATE;
	ndp->ni_segflg = UIO_USERSPACE;
	ndp->ni_dirp = uap->name;
	ip = namei(ndp);
E 82
	if (u.u_error)
		return;
	if (ip != NULL) {
		iput(ip);
		u.u_error = EEXIST;
		return;
	}
D 82
	dp = u.u_pdir;
E 82
I 82
	dp = ndp->ni_pdir;
E 82
	uap->dmode &= 0777;
	uap->dmode |= IFDIR;
	/*
	 * Must simulate part of maknode here
	 * in order to acquire the inode, but
	 * not have it entered in the parent
	 * directory.  The entry is made later
	 * after writing "." and ".." entries out.
	 */
	ip = ialloc(dp, dirpref(dp->i_fs), uap->dmode);
	if (ip == NULL) {
		iput(dp);
		return;
	}
#ifdef QUOTA
	if (ip->i_dquot != NODQUOT)
		panic("mkdir: dquot");
#endif
	ip->i_flag |= IACC|IUPD|ICHG;
	ip->i_mode = uap->dmode & ~u.u_cmask;
	ip->i_nlink = 2;
	ip->i_uid = u.u_uid;
	ip->i_gid = dp->i_gid;
#ifdef QUOTA
	ip->i_dquot = inoquota(ip);
#endif
	iupdat(ip, &time, &time, 1);

	/*
	 * Bump link count in parent directory
	 * to reflect work done below.  Should
	 * be done before reference is created
	 * so reparation is possible if we crash.
	 */
	dp->i_nlink++;
	dp->i_flag |= ICHG;
	iupdat(dp, &time, &time, 1);

	/*
	 * Initialize directory with "."
	 * and ".." from static template.
	 */
	dirtemplate = mastertemplate;
	dirtemplate.dot_ino = ip->i_number;
	dirtemplate.dotdot_ino = dp->i_number;
	u.u_error = rdwri(UIO_WRITE, ip, (caddr_t)&dirtemplate,
		sizeof (dirtemplate), (off_t)0, 1, (int *)0);
	if (u.u_error) {
		dp->i_nlink--;
		dp->i_flag |= ICHG;
		goto bad;
	}
I 87
	if (DIRBLKSIZ > ip->i_fs->fs_fsize)
		panic("mkdir: blksize");     /* XXX - should grow with bmap() */
	else
		ip->i_size = DIRBLKSIZ;
E 87
	/*
	 * Directory all set up, now
	 * install the entry for it in
	 * the parent directory.
	 */
D 82
	u.u_error = direnter(ip);
E 82
I 82
	u.u_error = direnter(ip, ndp);
E 82
	dp = NULL;
	if (u.u_error) {
D 82
		u.u_dirp = uap->name;
D 74
		dp = namei(uchar, LOOKUP, 0);
E 74
I 74
		dp = namei(uchar, LOOKUP | NOCACHE, 0);
E 82
I 82
		ndp->ni_nameiop = LOOKUP | NOCACHE;
		ndp->ni_segflg = UIO_USERSPACE;
		ndp->ni_dirp = uap->name;
		dp = namei(ndp);
E 82
E 74
		if (dp) {
			dp->i_nlink--;
			dp->i_flag |= ICHG;
		}
	}
bad:
	/*
	 * No need to do an explicit itrunc here,
	 * irele will do this for us because we set
	 * the link count to 0.
	 */
	if (u.u_error) {
		ip->i_nlink = 0;
		ip->i_flag |= ICHG;
	}
	if (dp)
		iput(dp);
	iput(ip);
}

/*
 * Rmdir system call.
 */
rmdir()
{
	struct a {
		char	*name;
D 82
	};
E 82
I 82
	} *uap = (struct a *)u.u_ap;
E 82
	register struct inode *ip, *dp;
I 82
	register struct nameidata *ndp = &u.u_nd;
E 82

D 82
	ip = namei(uchar, DELETE | LOCKPARENT, 0);
E 82
I 82
	ndp->ni_nameiop = DELETE | LOCKPARENT;
	ndp->ni_segflg = UIO_USERSPACE;
	ndp->ni_dirp = uap->name;
	ip = namei(ndp);
E 82
	if (ip == NULL)
		return;
D 82
	dp = u.u_pdir;
E 82
I 82
	dp = ndp->ni_pdir;
E 82
	/*
	 * No rmdir "." please.
	 */
	if (dp == ip) {
		irele(dp);
		iput(ip);
		u.u_error = EINVAL;
		return;
	}
	if ((ip->i_mode&IFMT) != IFDIR) {
		u.u_error = ENOTDIR;
		goto out;
	}
	/*
	 * Don't remove a mounted on directory.
	 */
	if (ip->i_dev != dp->i_dev) {
		u.u_error = EBUSY;
		goto out;
	}
	/*
	 * Verify the directory is empty (and valid).
	 * (Rmdir ".." won't be valid since
	 *  ".." will contain a reference to
	 *  the current directory and thus be
	 *  non-empty.)
	 */
D 84
	if (ip->i_nlink != 2 || !dirempty(ip)) {
E 84
I 84
	if (ip->i_nlink != 2 || !dirempty(ip, dp->i_number)) {
E 84
		u.u_error = ENOTEMPTY;
		goto out;
	}
	/*
	 * Delete reference to directory before purging
	 * inode.  If we crash in between, the directory
	 * will be reattached to lost+found,
	 */
D 82
	if (dirremove() == 0)
E 82
I 82
	if (dirremove(ndp) == 0)
E 82
		goto out;
	dp->i_nlink--;
	dp->i_flag |= ICHG;
I 84
	cacheinval(dp);
E 84
	iput(dp);
	dp = NULL;
	/*
	 * Truncate inode.  The only stuff left
	 * in the directory is "." and "..".  The
	 * "." reference is inconsequential since
	 * we're quashing it.  The ".." reference
	 * has already been adjusted above.  We've
	 * removed the "." reference and the reference
	 * in the parent directory, but there may be
	 * other hard links so decrement by 2 and
	 * worry about them later.
	 */
	ip->i_nlink -= 2;
	itrunc(ip, (u_long)0);
I 83
	cacheinval(ip);
E 83
out:
	if (dp)
		iput(dp);
	iput(ip);
}

struct file *
getinode(fdes)
	int fdes;
{
D 77
	register struct file *fp;
E 77
I 77
	struct file *fp;
E 77

D 77
	fp = getf(fdes);
	if (fp == 0)
		return (0);
E 77
I 77
	if ((unsigned)fdes >= NOFILE || (fp = u.u_ofile[fdes]) == NULL) {
		u.u_error = EBADF;
		return ((struct file *)0);
	}
E 77
	if (fp->f_type != DTYPE_INODE) {
		u.u_error = EINVAL;
D 77
		return (0);
E 77
I 77
		return ((struct file *)0);
E 77
	}
	return (fp);
}

/*
 * mode mask for creation of files
 */
umask()
{
	register struct a {
		int	mask;
D 82
	} *uap;
E 82
I 82
	} *uap = (struct a *)u.u_ap;
E 82

D 82
	uap = (struct a *)u.u_ap;
E 82
	u.u_r.r_val1 = u.u_cmask;
	u.u_cmask = uap->mask & 07777;
E 63
E 37
E 36
E 21
D 17
	for(mp = &mount[0]; mp < &mount[NMOUNT]; mp++)
		if(mp->m_bufp != NULL && dev == mp->m_dev)
E 17
I 17
D 26
	for (mp = &mount[0]; mp < &mount[NMOUNT]; mp++)
		if (mp->m_bufp != NULL && dev == mp->m_dev)
E 17
			goto found;
	u.u_error = EINVAL;
	return;

found:
I 10
	stillopen = 0;
E 10
D 12
	for(ip = &inode[0]; ip < &inode[NINODE]; ip++)
E 12
I 12
D 17
	for(ip = inode; ip < inodeNINODE; ip++)
E 17
I 17
	for (ip = inode; ip < inodeNINODE; ip++)
E 17
E 12
D 9
		if(ip->i_number != 0 && dev == ip->i_dev) {
E 9
I 9
		if (ip->i_number != 0 && dev == ip->i_dev) {
E 9
			u.u_error = EBUSY;
			return;
D 8
		}
I 4
	mpurge(mp - &mount[0]);
E 4
	(*bdevsw[major(dev)].d_close)(dev, 0);
E 8
I 8
D 9
		} else if (ip->i_number != 0 && (ip->i_mode&IFMT) == IFBLK
			&& ip->i_un.i_rdev == dev)
				stillopen++;
E 9
I 9
		} else if (ip->i_number != 0 && (ip->i_mode&IFMT) == IFBLK &&
		    ip->i_un.i_rdev == dev)
			stillopen++;
E 9
E 8
	ip = mp->m_inodp;
	ip->i_flag &= ~IMOUNT;
D 17
	plock(ip);
E 17
I 17
	ilock(ip);
E 17
	iput(ip);
D 9
	bp = mp->m_bufp;
E 9
I 9
	if ((bp = getblk(dev, SUPERB)) != mp->m_bufp)
		panic("umount");
	bp->b_flags &= ~B_LOCKED;
E 9
I 8
	flag = !bp->b_un.b_filsys->s_ronly;
E 8
	mp->m_bufp = NULL;
	brelse(bp);
I 11
	mpurge(mp - &mount[0]);
E 11
I 8
	if (!stillopen) {
D 11
		mpurge(mp - &mount[0]);
E 11
		(*bdevsw[major(dev)].d_close)(dev, flag);
		binval(dev);
	}
E 8
}

/*
 * Common code for mount and umount.
 * Check that the user's argument is a reasonable
 * thing on which to mount, and return the device number if so.
 */
dev_t
getmdev()
{
	dev_t dev;
	register struct inode *ip;

D 7
#ifdef UCB
E 7
	if (!suser())
		return(NODEV);
D 7
#endif
E 7
D 23
	ip = namei(uchar, 0);
E 23
I 23
	ip = namei(uchar, 0, 1);
E 23
D 17
	if(ip == NULL)
E 17
I 17
	if (ip == NULL)
E 17
		return(NODEV);
D 17
	if((ip->i_mode&IFMT) != IFBLK)
E 17
I 17
	if ((ip->i_mode&IFMT) != IFBLK)
E 17
		u.u_error = ENOTBLK;
	dev = (dev_t)ip->i_un.i_rdev;
D 17
	if(major(dev) >= nblkdev)
E 17
I 17
	if (major(dev) >= nblkdev)
E 17
		u.u_error = ENXIO;
	iput(ip);
	return(dev);
E 26
}
E 1
