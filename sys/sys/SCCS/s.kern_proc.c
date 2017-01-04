h02089
s 00000/00001/00118
d D 7.2 87/07/13 23:34:02 mckusick 99 98
c do not need inode.h
e
s 00001/00001/00118
d D 7.1 86/06/05 00:03:17 mckusick 98 97
c 4.3BSD release version
e
s 00003/00009/00116
d D 6.7 85/11/04 17:52:42 karels 97 96
c cleanup spgrp, rm unused code (should rm it all)
e
s 00007/00001/00118
d D 6.6 85/06/08 14:36:39 mckusick 96 95
c Add copyright
e
s 00032/00023/00087
d D 6.5 84/12/20 14:28:26 karels 95 94
c make spgrp use child pointers instead of linear searches
e
s 00018/00018/00092
d D 6.4 84/08/29 20:19:44 bloom 94 93
c Change to includes.  no more ../h
e
s 00000/00001/00110
d D 6.3 84/07/08 16:13:09 mckusick 93 92
c rework `namei' interface to eliminate global variables
e
s 00027/00000/00084
d D 6.2 84/05/22 11:44:35 karels 92 91
c linked lists of active, zombie and free procs; avoid linear proc
c searches wherever possible
e
s 00000/00000/00084
d D 6.1 83/07/29 06:33:11 sam 91 90
c 4.2 distribution
e
s 00001/00989/00083
d D 4.64 83/05/27 12:46:35 sam 90 89
c merge of bill's code plus lint (plus, of course, cleanup of bill's bugs)
e
s 00006/00024/01066
d D 4.63 83/05/21 15:32:09 sam 89 88
c purge mush; limit interpreter name to a sane value to cut down on 
c kernel stack size requirements
e
s 00005/00005/01085
d D 4.62 83/05/18 02:01:49 sam 88 87
c do it shannon's way -- all the same + sun changes
e
s 00001/00001/01089
d D 4.61 83/04/06 19:17:18 mckusick 87 86
c properly terminate system name
e
s 00001/00001/01089
d D 4.60 83/04/05 15:57:19 sam 86 85
c insure gethostname returns null-terminated string
e
s 00000/00001/01090
d D 4.59 83/02/16 18:18:45 sam 85 84
c fix access and problems with setgid and saccess
e
s 00001/00001/01090
d D 4.58 83/02/10 21:53:20 sam 84 83
c eliminate /usr/include dependencies{
e
s 00000/00001/01091
d D 4.57 83/01/17 16:21:08 sam 83 82
c purge extraneous suword (buffer is obtained zero filled)
e
s 00002/00004/01090
d D 4.56 82/12/28 23:46:14 sam 82 81
c copyin & copyout now return EFAULT and all callers uniformly 
c return (or ignore) this value
e
s 00025/00009/01069
d D 4.55 82/12/28 19:53:12 sam 81 80
c new wait call (returns struct rusage instead of vtimes)
e
s 00001/00001/01077
d D 4.54 82/12/21 15:06:21 sam 80 79
c units (it's always units)
e
s 00006/00006/01072
d D 4.53 82/12/17 11:43:52 sam 79 78
c sun merge
e
s 00001/00000/01077
d D 4.52 82/12/16 12:15:53 sam 78 77
c looking at file table entries which are free
e
s 00001/00001/01076
d D 4.51 82/12/14 17:09:21 sam 77 76
c typed mbufs
e
s 00003/00003/01074
d D 4.50 82/12/09 19:01:33 sam 76 75
c u.u_pofile flags are now UF_*
e
s 00007/00007/01070
d D 4.49 82/12/05 21:56:12 sam 75 74
c put back old style closef call; add temp panic 'til we find 
c missing mbuf free (so exit will panic "nicely")
e
s 00007/00006/01070
d D 4.48 82/11/13 22:49:50 sam 74 73
c merge of 4.1b and 4.1c
e
s 00003/00002/01073
d D 4.47 82/11/02 11:29:28 root 73 72
c missing {}'s
e
s 00031/00005/01044
d D 4.46 82/10/31 14:37:15 root 72 71
c fixes from 68k
e
s 00002/00001/01047
d D 4.45 82/10/23 09:56:16 root 71 70
c bug fix with calling m_get after freeing stack we are using
e
s 00001/00001/01047
d D 4.44 82/10/22 01:13:54 root 70 69
c lint
e
s 00004/00004/01044
d D 4.43 82/10/21 20:56:40 root 69 68
c lint
e
s 00000/00000/01048
d D 4.43 82/10/19 10:30:45  69 68
c more lint
e
s 00000/00000/01048
d D 4.42 82/10/17 23:03:17 root 68 67
c lint
e
s 00001/00001/01047
d D 4.41 82/10/17 21:48:45 root 67 66
c more lint
e
s 00001/00001/01047
d D 4.40 82/10/10 15:02:27 root 66 65
c split header files over to vax directories
e
s 00008/00004/01040
d D 4.39 82/09/12 01:55:51 root 65 64
c wait3 returns old vtimes structure
e
s 00002/00002/01042
d D 4.38 82/09/08 08:01:50 root 64 63
c clear real timeout on exit; label_t now structure 
e
s 00210/00001/00834
d D 4.37 82/09/06 22:48:03 root 63 62
c 
e
s 00037/00026/00798
d D 4.36 82/09/04 09:09:37 root 62 61
c timer, rusage, hostid stuff
e
s 00001/00001/00823
d D 4.35 82/08/24 15:04:35 root 61 60
c new groups stuff
e
s 00024/00009/00800
d D 4.34 82/08/22 20:31:53 root 60 59
c put in rdwri() and move pfind procedure here
e
s 00007/00018/00802
d D 4.33 82/08/14 18:53:50 root 59 58
c no more readi()
e
s 00001/00000/00819
d D 4.32 82/08/13 00:03:57 wnj 58 57
c fixes to get uio'd readi for char devs
e
s 00011/00006/00808
d D 4.31 82/08/11 21:11:18 root 57 56
c first use of readip()
e
s 00010/00004/00804
d D 4.30 82/08/10 17:41:25 sam 56 55
c file locking
e
s 00002/00000/00806
d D 4.29 82/07/25 23:12:12 root 55 54
c check for error in vinifod and kill process
e
s 00044/00030/00762
d D 4.28 82/07/24 18:09:20 root 54 53
c merge with calder
e
s 00046/00001/00746
d D 4.27 82/07/22 13:21:18 kre 53 52
c mush, father / son / brother proc pointers
e
s 00020/00015/00727
d D 4.26 82/04/19 19:35:09 mckusic 52 51
c merge into new file system
e
s 00002/00002/00740
d D 4.25 82/04/02 12:12:17 wnj 51 50
c bug fixes from elz and utcsrgv!thomson
e
s 00001/00001/00741
d D 4.24 82/03/27 20:35:22 wnj 50 49
c bug fix per u toronto (collyer)
e
s 00002/00002/00740
d D 4.23 82/02/27 14:54:47 wnj 49 48
c symbolic links
e
s 00001/00000/00741
d D 4.22 82/02/15 13:28:47 wnj 48 47
c new multiple-group stuff
e
s 00001/00001/00740
d D 4.21 82/01/30 19:16:52 wnj 47 46
c spl5 not splimp
e
s 00001/00000/00740
d D 4.20 82/01/25 18:38:31 wnj 46 45
c bug fixes (round 1)
e
s 00001/00002/00739
d D 4.19 82/01/24 22:02:09 wnj 45 44
c clean up SDETACH
e
s 00002/00002/00739
d D 4.18 82/01/19 06:39:38 wnj 44 43
c closef parameter indicating whether error return
c to complete non-blc
e
s 00002/00004/00739
d D 4.17 81/11/21 15:18:49 wnj 43 42
c undo botch introduced by fixing lint
e
s 00004/00002/00739
d D 4.16 81/11/20 14:43:55 wnj 42 41
c more lint
e
s 00000/00000/00741
d D 4.15 81/11/18 15:45:39 wnj 41 40
c more cleanup
e
s 00000/00000/00741
d D 4.14 81/11/16 14:21:26 wnj 40 39
c lint
e
s 00034/00039/00707
d D 4.13 81/11/08 17:05:58 wnj 39 38
c major cleanups for socket code
e
s 00001/00004/00745
d D 4.12 81/04/28 02:55:54 root 38 37
c fix to #! with 2 args
e
s 00001/00001/00748
d D 4.11 81/04/23 03:00:41 wnj 37 36
c ANOM->SEQL
e
s 00001/00001/00748
d D 4.10 81/03/09 01:49:21 wnj 36 35
c lint and a few minor fixed
e
s 00002/00032/00747
d D 4.9 81/03/06 11:38:43 wnj 35 34
c get rid of UCBIPC stuff
e
s 00003/00003/00776
d D 4.8 81/02/28 17:17:24 wnj 34 33
c changes for rmalloc, rmfree, malloc.c
e
s 00004/00004/00775
d D 4.7 81/02/26 23:40:11 wnj 33 32
c rid of NPROC
e
s 00001/00001/00778
d D 4.6 81/02/26 23:31:46 wnj 32 31
c rid of NFILE
e
s 00002/00000/00777
d D 4.5 81/02/03 14:39:00 wnj 31 30
c fix to ptrace() found by kipp
e
s 00033/00002/00744
d D 4.4 81/02/01 18:01:15 wnj 30 29
c UCBIPC crud
e
s 00131/00055/00615
d D 4.3 81/01/28 12:02:27 kre 29 28
c #! execs
e
s 00001/00001/00669
d D 4.2 80/11/09 23:35:09 bill 28 27
c function results (void)'ed for minor lint
e
s 00000/00000/00670
d D 4.1 80/11/09 17:31:43 bill 27 26
c minor fixups to restart stuff; version 4.1 for distrib
e
s 00002/00000/00668
d D 3.26 80/10/13 09:58:43 bill 26 25
c panic if init dies
e
s 00002/00001/00666
d D 3.25 80/10/11 21:31:58 bill 25 24
c %cpu
e
s 00001/00001/00666
d D 3.24 80/10/02 10:40:25 bill 24 23
c first attempt at reboot stuff
e
s 00001/00001/00666
d D 3.23 80/09/30 22:50:15 bill 23 22
c 1 line fix to exitin code from elz
e
s 00063/00100/00604
d D 3.22 80/09/25 17:08:59 bill 22 21
c exec cleanup, new signal compatibility mode
e
s 00009/00003/00695
d D 3.21 80/09/19 17:16:13 bill 21 20
c avoid ETXTBSY botch
e
s 00001/00001/00697
d D 3.20 80/09/16 17:11:51 bill 20 19
c s/limit/vlimit/
e
s 00000/00000/00698
d D 3.19 80/07/13 14:13:40 bill 19 18
c inherit SDETACH on fork(), vfork()
e
s 00001/00000/00697
d D 3.18 80/07/12 19:55:14 bill 18 17
c limit.h included
e
s 00001/00001/00696
d D 3.17 80/07/12 19:34:37 bill 17 16
c forgot ctob()
e
s 00005/00000/00692
d D 3.16 80/07/12 18:14:41 bill 16 15
c limit code
e
s 00003/00003/00689
d D 3.15 80/07/11 08:14:10 bill 15 14
c fix setting of SDETACH 
e
s 00001/00000/00691
d D 3.14 80/07/03 01:42:23 bill 14 13
c set SDETACH for ps
e
s 00001/00001/00690
d D 3.13 80/06/30 09:01:53 bill 13 12
c TBIA(0)
e
s 00010/00012/00681
d D 3.12 80/06/24 19:28:57 bill 12 11
c no swplo
e
s 00001/00001/00692
d D 3.11 80/06/07 02:47:44 bill 11 10
c %H%->%G%
e
s 00001/00001/00692
d D 3.10 80/06/06 14:59:09 bill 10 9
c set pgrp to self when inherited by init
e
s 00002/00001/00691
d D 3.9 80/06/04 14:59:46 bill 9 8
c more cosmetics
e
s 00012/00009/00680
d D 3.8 80/06/04 13:34:05 bill 8 7
c wait bug fix and cosmetics
e
s 00015/00002/00674
d D 3.7 80/06/02 12:39:26 bill 7 6
c 
e
s 00007/00008/00669
d D 3.6 80/05/24 19:43:47 bill 6 5
c new sig stuff
e
s 00094/00027/00583
d D 3.5 80/05/18 11:34:55 bill 5 4
c first stab + revised wait
e
s 00004/00004/00606
d D 3.4 80/05/15 17:01:20 bill 4 3
c new signal names
e
s 00008/00008/00602
d D 3.3 80/05/08 10:23:18 bill 3 2
c VOID=>void
e
s 00005/00001/00605
d D 3.2 80/04/11 10:15:59 bill 2 1
c fix bug in exece at badarg:
e
s 00606/00000/00000
d D 3.1 80/04/09 16:04:26 bill 1 0
c date and time created 80/04/09 16:04:26 by bill
e
u
U
t
T
I 1
D 11
/*	%M%	%I%	%H%	*/
E 11
I 11
D 36
/*	%M%	%I%	%G%	*/
E 36
I 36
D 96
/*	%M%	%I%	%E%	*/
E 96
I 96
/*
D 98
 * Copyright (c) 1982 Regents of the University of California.
E 98
I 98
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 98
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 96
E 36
E 11

I 79
#include "../machine/reg.h"
#include "../machine/pte.h"
#include "../machine/psl.h"

E 79
D 94
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/map.h"
D 66
#include "../h/mtpr.h"
E 66
#include "../h/dir.h"
#include "../h/user.h"
I 62
#include "../h/kernel.h"
E 62
#include "../h/proc.h"
#include "../h/buf.h"
D 79
#include "../h/reg.h"
E 79
#include "../h/inode.h"
#include "../h/seg.h"
#include "../h/acct.h"
I 5
D 8
#include <wait.h>
E 8
I 8
D 72
#include "/usr/include/wait.h"
E 72
I 72
D 84
#include <wait.h>
E 84
I 84
#include "../h/wait.h"
E 84
E 72
E 8
E 5
D 79
#include "../h/pte.h"
E 79
#include "../h/vm.h"
#include "../h/text.h"
I 5
D 79
#include "../h/psl.h"
E 79
I 18
D 20
#include "../h/limit.h"
E 20
I 20
D 62
#include "../h/vlimit.h"
E 62
I 21
#include "../h/file.h"
I 53
#include "../h/quota.h"
I 54
D 90
#include "../h/descrip.h"
E 90
I 57
#include "../h/uio.h"
I 62
#include "../h/mbuf.h"
E 94
I 94
#include "param.h"
#include "systm.h"
#include "map.h"
#include "dir.h"
#include "user.h"
#include "kernel.h"
#include "proc.h"
#include "buf.h"
D 99
#include "inode.h"
E 99
#include "seg.h"
#include "acct.h"
#include "wait.h"
#include "vm.h"
#include "text.h"
#include "file.h"
#include "quota.h"
#include "uio.h"
#include "mbuf.h"
E 94
I 74
D 93
#include "../h/nami.h"
E 93
E 74
E 62
E 57
E 54
E 53
E 21
E 20
E 18
E 5

I 95
/*
D 97
 * Change the process group of top and all descendents to npgrp.
 * If npgrp is -1, instead clear any pending stops.
E 97
I 97
 * Clear any pending stops for top and all descendents.
E 97
 */
E 95
I 62
D 90
gethostid()
{

I 63
	u.u_r.r_val1 = hostid;
E 63
}

sethostid()
{
I 63
	struct a {
		int	hostid;
	} *uap = (struct a *)u.u_ap;
E 63

I 63
	if (suser())
		hostid = uap->hostid;
E 63
}

I 63
gethostname()
{
	register struct a {
		char	*hostname;
		int	len;
	} *uap = (struct a *)u.u_ap;
	register u_int len;

	len = uap->len;
D 88
	if (len > hostnamelen)
		len = hostnamelen;
E 88
I 88
	if (len > hostnamelen + 1)
		len = hostnamelen + 1;
E 88
D 82
	if (copyout((caddr_t)hostname, (caddr_t)uap->hostname, len))
		u.u_error = EFAULT;
E 82
I 82
	u.u_error = copyout((caddr_t)hostname, (caddr_t)uap->hostname, len);
E 82
}

sethostname()
{
	register struct a {
		char	*hostname;
		u_int	len;
	} *uap = (struct a *)u.u_ap;

	if (!suser())
		return;
	if (uap->len > sizeof (hostname) - 1) {
		u.u_error = EINVAL;
		return;
	}
D 86
	hostnamelen = uap->len;
E 86
I 86
D 88
	hostnamelen = uap->len + 1;
E 88
I 88
	hostnamelen = uap->len;
E 88
E 86
D 82
	if (copyin((caddr_t)uap->hostname, hostname, uap->len))
		u.u_error = EFAULT;
E 82
I 82
	u.u_error = copyin((caddr_t)uap->hostname, hostname, uap->len);
E 82
D 87
	hostname[hostnamelen] = 0;
E 87
I 87
D 88
	hostname[uap->len] = 0;
E 88
I 88
	hostname[hostnamelen] = 0;
E 88
E 87
}

E 63
E 62
/*
 * exec system call, with and without environments.
 */
struct execa {
	char	*fname;
	char	**argp;
	char	**envp;
};

D 62
exec()
E 62
I 62
execv()
E 62
{
	((struct execa *)u.u_ap)->envp = NULL;
D 62
	exece();
E 62
I 62
	execve();
E 62
}

D 62
exece()
E 62
I 62
execve()
E 62
{
	register nc;
	register char *cp;
	register struct buf *bp;
	register struct execa *uap;
	int na, ne, ucp, ap, c;
I 29
	int indir, uid, gid;
	char *sharg;
E 29
	struct inode *ip;
	swblk_t bno;
I 29
D 52
	char cfname[DIRSIZ];
E 52
I 52
D 89
	char cfname[MAXNAMLEN + 1];
E 89
I 89
	char cfname[MAXCOMLEN + 1];
E 89
E 52
	char cfarg[SHSIZE];
I 57
D 60
	struct uio uio;
	struct iovec iovec;
E 60
I 59
	int resid;
E 59
E 57
E 29

D 49
	if ((ip = namei(uchar, 0)) == NULL)
E 49
I 49
D 74
	if ((ip = namei(uchar, 0, 1)) == NULL)
E 74
I 74
	if ((ip = namei(uchar, LOOKUP, 1)) == NULL)
E 74
E 49
		return;
I 29
D 39

E 39
E 29
	bno = 0;
	bp = 0;
I 29
	indir = 0;
	uid = u.u_uid;
	gid = u.u_gid;
D 39

E 39
	if (ip->i_mode & ISUID)
		uid = ip->i_uid;
	if (ip->i_mode & ISGID)
		gid = ip->i_gid;

  again:
E 29
D 39
	if(access(ip, IEXEC))
E 39
I 39
	if (access(ip, IEXEC))
E 39
		goto bad;
I 31
D 39
	if((u.u_procp->p_flag&STRC) && access(ip, IREAD))
E 39
I 39
	if ((u.u_procp->p_flag&STRC) && access(ip, IREAD))
E 39
		goto bad;
E 31
D 39
	if((ip->i_mode & IFMT) != IFREG ||
E 39
I 39
	if ((ip->i_mode & IFMT) != IFREG ||
E 39
	   (ip->i_mode & (IEXEC|(IEXEC>>3)|(IEXEC>>6))) == 0) {
		u.u_error = EACCES;
		goto bad;
	}
I 29

E 29
	/*
I 29
	 * Read in first few bytes of file for segment sizes, ux_mag:
	 *	407 = plain executable
	 *	410 = RO text
	 *	413 = demand paged RO text
	 * Also an ASCII line beginning with #! is
	 * the file name of a ``shell'' and arguments may be prepended
	 * to the argument list if given here.
	 *
	 * SHELL NAMES ARE LIMITED IN LENGTH.
	 *
	 * ONLY ONE ARGUMENT MAY BE PASSED TO THE SHELL FROM
	 * THE ASCII LINE.
	 */
I 79
	u.u_exdata.ux_shell[0] = 0;	/* for zero length files */
E 79
D 57
	u.u_base = (caddr_t)&u.u_exdata;
	u.u_count = sizeof(u.u_exdata);
	u.u_offset = 0;
	u.u_segflg = 1;
	readi(ip);
	u.u_segflg = 0;
E 57
I 57
D 59
	uio.uio_iov = &iovec;
	uio.uio_iovcnt = 1;
	iovec.iov_base = (caddr_t)&u.u_exdata;
	iovec.iov_len = sizeof (u.u_exdata);
	uio.uio_offset = 0;
	uio.uio_segflg = 1;
I 58
	uio.uio_resid = iovec.iov_len;
E 58
	u.u_error = readip(ip, &uio);
E 59
I 59
D 60
	u.u_error = readip1(ip, (caddr_t)&u.u_exdata, sizeof (u.u_exdata),
E 60
I 60
	u.u_error = rdwri(UIO_READ, ip, (caddr_t)&u.u_exdata, sizeof (u.u_exdata),
E 60
	    0, 1, &resid);
E 59
E 57
D 39
	if(u.u_error)
E 39
I 39
	if (u.u_error)
E 39
		goto bad;
I 57
D 59
	u.u_count = uio.uio_resid;
E 59
I 59
	u.u_count = resid;
I 60
#ifndef lint
E 60
E 59
E 57
D 42
	if (u.u_count > sizeof(u.u_exdata) - sizeof(u.u_exdata.Ux_A)
		&& u.u_exdata.ux_shell[0] != '#') {
E 42
I 42
D 43
#if 0
	if (u.u_count > sizeof(u.u_exdata) - sizeof(u.u_exdata.Ux_A))
#endif
	if (u.u_exdata.ux_shell[0] != '#') {
E 43
I 43
	if (u.u_count > sizeof(u.u_exdata) - sizeof(u.u_exdata.Ux_A) &&
	    u.u_exdata.ux_shell[0] != '#') {
E 43
E 42
		u.u_error = ENOEXEC;
		goto bad;
	}
I 60
#endif
E 60
	switch (u.u_exdata.ux_mag) {

	case 0407:
		u.u_exdata.ux_dsize += u.u_exdata.ux_tsize;
		u.u_exdata.ux_tsize = 0;
		break;

	case 0413:
	case 0410:
		if (u.u_exdata.ux_tsize == 0) {
			u.u_error = ENOEXEC;
			goto bad;
		}
		break;

	default:
		if (u.u_exdata.ux_shell[0] != '#' ||
		    u.u_exdata.ux_shell[1] != '!' ||
		    indir) {
			u.u_error = ENOEXEC;
			goto bad;
		}
		cp = &u.u_exdata.ux_shell[2];		/* skip "#!" */
		while (cp < &u.u_exdata.ux_shell[SHSIZE]) {
			if (*cp == '\t')
				*cp = ' ';
			else if (*cp == '\n') {
				*cp = '\0';
				break;
			}
			cp++;
		}
		if (*cp != '\0') {
			u.u_error = ENOEXEC;
			goto bad;
		}
		cp = &u.u_exdata.ux_shell[2];
		while (*cp == ' ')
			cp++;
		u.u_dirp = cp;
		while (*cp && *cp != ' ')
			cp++;
		sharg = NULL;
		if (*cp) {
			*cp++ = '\0';
			while (*cp == ' ')
				cp++;
			if (*cp) {
				bcopy((caddr_t)cp, (caddr_t)cfarg, SHSIZE);
				sharg = cfarg;
			}
		}
I 89
		if (u.u_dent.d_namlen > MAXCOMLEN)
			u.u_dent.d_namlen = MAXCOMLEN;
E 89
D 52
		bcopy((caddr_t)u.u_dbuf, (caddr_t)cfname, DIRSIZ);
E 52
I 52
		bcopy((caddr_t)u.u_dent.d_name, (caddr_t)cfname,
D 60
		    u.u_dent.d_namlen + 1);
E 60
I 60
		    (unsigned)(u.u_dent.d_namlen + 1));
I 89
		cfname[MAXCOMLEN] = 0;
E 89
E 60
E 52
		indir = 1;
		iput(ip);
D 49
		ip = namei(schar, 0);
E 49
I 49
D 74
		ip = namei(schar, 0, 1);
E 74
I 74
		ip = namei(schar, LOOKUP, 1);
E 74
E 49
		if (ip == NULL)
			return;
		goto again;
	}

	/*
E 29
	 * Collect arguments on "file" in swap space.
	 */
	na = 0;
	ne = 0;
	nc = 0;
	uap = (struct execa *)u.u_ap;
D 12
	if ((bno = malloc(swapmap, ctod(clrnd((int) btoc(NCARGS))))) == 0) {
E 12
I 12
D 34
	if ((bno = malloc(argmap, ctod(clrnd((int) btoc(NCARGS))))) == 0) {
E 34
I 34
D 69
	if ((bno = rmalloc(argmap, ctod(clrnd((int) btoc(NCARGS))))) == 0) {
E 69
I 69
	if ((bno = rmalloc(argmap, (long)ctod(clrnd((int)btoc(NCARGS))))) == 0) {
E 69
E 34
E 12
		swkill(u.u_procp, "exece");
		goto bad;
	}
	if (bno % CLSIZE)
D 34
		panic("execa malloc");
E 34
I 34
		panic("execa rmalloc");
E 34
	if (uap->argp) for (;;) {
		ap = NULL;
D 29
		if (uap->argp) {
E 29
I 29
D 38
		if (na == 1 && indir) {
			if (sharg == NULL)
				ap = (int)uap->fname;
		} else if (na == 2 && indir && sharg != NULL)
E 38
I 38
		if (indir && (na == 1 || na == 2 && sharg))
E 38
			ap = (int)uap->fname;
		else if (uap->argp) {
E 29
			ap = fuword((caddr_t)uap->argp);
			uap->argp++;
		}
		if (ap==NULL && uap->envp) {
			uap->argp = NULL;
			if ((ap = fuword((caddr_t)uap->envp)) == NULL)
				break;
			uap->envp++;
			ne++;
		}
D 52
		if (ap==NULL)
E 52
I 52
		if (ap == NULL)
E 52
			break;
		na++;
D 39
		if(ap == -1)
E 39
I 39
		if (ap == -1)
E 39
			u.u_error = EFAULT;
		do {
			if (nc >= NCARGS-1)
				u.u_error = E2BIG;
D 29
			if ((c = fubyte((caddr_t)ap++)) < 0)
E 29
I 29
			if (indir && na == 2 && sharg != NULL)
				c = *sharg++ & 0377;
			else if ((c = fubyte((caddr_t)ap++)) < 0)
E 29
				u.u_error = EFAULT;
D 2
			if (u.u_error)
E 2
I 2
			if (u.u_error) {
				if (bp)
					brelse(bp);
				bp = 0;
E 2
				goto badarg;
I 2
			}
E 2
D 52
			if ((nc&BMASK) == 0) {
E 52
I 52
			if (nc % (CLSIZE*NBPG) == 0) {
E 52
				if (bp)
					bdwrite(bp);
D 8
				bp = getblk(swapdev, (daddr_t)(dbtofsb(swplo+bno)+(nc>>BSHIFT)));
E 8
I 8
D 12
				bp = getblk(swapdev,
				    (daddr_t)(dbtofsb(swplo+bno)+(nc>>BSHIFT)));
E 12
I 12
D 52
				bp = getblk(argdev,
				    (daddr_t)(dbtofsb(bno)+(nc>>BSHIFT)));
E 52
I 52
D 72
				bp = getblk(argdev, bno + nc / NBPG,
E 72
I 72
				bp = getblk(argdev, bno + ctod(nc / NBPG),
E 72
				    CLSIZE*NBPG);
E 52
E 12
E 8
				cp = bp->b_un.b_addr;
			}
			nc++;
			*cp++ = c;
D 52
		} while (c>0);
E 52
I 52
		} while (c > 0);
E 52
	}
	if (bp)
		bdwrite(bp);
	bp = 0;
	nc = (nc + NBPW-1) & ~(NBPW-1);
D 22
	if (getxfile(ip, nc) || u.u_error) {
E 22
I 22
D 24
	getxfile(ip, nc);
E 24
I 24
D 29
	getxfile(ip, nc + (na+4)*NBPW);
E 29
I 29
D 52
	if (indir)
		bcopy((caddr_t)cfname, (caddr_t)u.u_dbuf, DIRSIZ);
E 52
I 52
	if (indir) {
		u.u_dent.d_namlen = strlen(cfname);
		bcopy((caddr_t)cfname, (caddr_t)u.u_dent.d_name,
D 60
		    u.u_dent.d_namlen + 1);
E 60
I 60
		    (unsigned)(u.u_dent.d_namlen + 1));
E 60
	}
E 52
	getxfile(ip, nc + (na+4)*NBPW, uid, gid);
E 29
E 24
	if (u.u_error) {
E 22
badarg:
D 52
		for (c = 0; c < nc; c += BSIZE)
D 12
			if (bp = baddr(swapdev, dbtofsb(swplo+bno)+(c>>BSHIFT))) {
E 12
I 12
			if (bp = baddr(argdev, dbtofsb(bno)+(c>>BSHIFT))) {
E 52
I 52
D 73
		for (c = 0; c < nc; c += CLSIZE*NBPG)
D 72
			if (bp = baddr(argdev, bno + c / NBPG, CLSIZE*NBPG)) {
E 72
I 72
			bp = baddr(argdev, bno + ctod(c / NBPG), CLSIZE*NBPG));
E 73
I 73
		for (c = 0; c < nc; c += CLSIZE*NBPG) {
			bp = baddr(argdev, bno + ctod(c / NBPG), CLSIZE*NBPG);
E 73
			if (bp) {
E 72
E 52
E 12
				bp->b_flags |= B_AGE;		/* throw away */
				bp->b_flags &= ~B_DELWRI;	/* cancel io */
				brelse(bp);
				bp = 0;
			}
I 73
		}
E 73
		goto bad;
	}

	/*
	 * copy back arglist
	 */
D 39

E 39
	ucp = USRSTACK - nc - NBPW;
	ap = ucp - na*NBPW - 3*NBPW;
	u.u_ar0[SP] = ap;
D 3
	VOID suword((caddr_t)ap, na-ne);
E 3
I 3
	(void) suword((caddr_t)ap, na-ne);
E 3
	nc = 0;
	for (;;) {
		ap += NBPW;
		if (na==ne) {
D 3
			VOID suword((caddr_t)ap, 0);
E 3
I 3
			(void) suword((caddr_t)ap, 0);
E 3
			ap += NBPW;
		}
		if (--na < 0)
			break;
D 3
		VOID suword((caddr_t)ap, ucp);
E 3
I 3
		(void) suword((caddr_t)ap, ucp);
E 3
		do {
D 52
			if ((nc&BMASK) == 0) {
E 52
I 52
			if (nc % (CLSIZE*NBPG) == 0) {
E 52
				if (bp)
					brelse(bp);
D 9
				bp = bread(swapdev, (daddr_t)(dbtofsb(swplo+bno)+(nc>>BSHIFT)));
E 9
I 9
D 12
				bp = bread(swapdev,
				    (daddr_t)(dbtofsb(swplo+bno)+(nc>>BSHIFT)));
E 12
I 12
D 52
				bp = bread(argdev,
				    (daddr_t)(dbtofsb(bno)+(nc>>BSHIFT)));
E 52
I 52
D 80
				bp = bread(argdev, bno + nc / NBPG,
E 80
I 80
				bp = bread(argdev, bno + ctod(nc / NBPG),
E 80
				    CLSIZE*NBPG);
E 52
E 12
E 9
				bp->b_flags |= B_AGE;		/* throw away */
				bp->b_flags &= ~B_DELWRI;	/* cancel io */
				cp = bp->b_un.b_addr;
			}
D 3
			VOID subyte((caddr_t)ucp++, (c = *cp++));
E 3
I 3
			(void) subyte((caddr_t)ucp++, (c = *cp++));
E 3
			nc++;
		} while(c&0377);
	}
D 3
	VOID suword((caddr_t)ap, 0);
	VOID suword((caddr_t)ucp, 0);
E 3
I 3
	(void) suword((caddr_t)ap, 0);
D 83
	(void) suword((caddr_t)ucp, 0);
E 83
E 3
	setregs();
bad:
	if (bp)
		brelse(bp);
	if (bno)
D 12
		mfree(swapmap, ctod(clrnd((int) btoc(NCARGS))), bno);
E 12
I 12
D 34
		mfree(argmap, ctod(clrnd((int) btoc(NCARGS))), bno);
E 34
I 34
D 70
		rmfree(argmap, ctod(clrnd((int) btoc(NCARGS))), bno);
E 70
I 70
		rmfree(argmap, (long)ctod(clrnd((int) btoc(NCARGS))), bno);
E 70
E 34
E 12
	iput(ip);
}

/*
 * Read in and set up memory for executed file.
D 22
 * Zero return is normal;
 * non-zero means only the text is being replaced
E 22
 */
D 29
getxfile(ip, nargc)
E 29
I 29
getxfile(ip, nargc, uid, gid)
E 29
register struct inode *ip;
{
D 22
	register sep;
E 22
	register size_t ts, ds, ss;
D 21
	register int overlay;
E 21
I 21
D 22
	int overlay;
E 22
E 21
D 29
	int pagi = 0;
E 29
I 29
	int pagi;
E 29

D 29
	/*
	 * read in first few bytes
	 * of file for segment
	 * sizes:
D 22
	 * ux_mag = 407/410/411/405
E 22
I 22
	 * ux_mag = 407/410/413
E 22
	 *  407 is plain executable
	 *  410 is RO text
D 22
	 *  411 is separated ID
	 *  405 is overlaid text
	 *  412 is demand paged plain executable (NOT IMPLEMENTED)
E 22
	 *  413 is demand paged RO text
	 */

	u.u_base = (caddr_t)&u.u_exdata;
	u.u_count = sizeof(u.u_exdata);
	u.u_offset = 0;
	u.u_segflg = 1;
	readi(ip);
	u.u_segflg = 0;
	if(u.u_error)
		goto bad;
	if (u.u_count!=0) {
		u.u_error = ENOEXEC;
		goto bad;
	}
D 22
	sep = 0;
	overlay = 0;
E 22
	switch (u.u_exdata.ux_mag) {

D 22
	case 0405:
		overlay++;
		break;

	case 0412:
		u.u_error = ENOEXEC;
		goto bad;

E 22
	case 0407:
		u.u_exdata.ux_dsize += u.u_exdata.ux_tsize;
		u.u_exdata.ux_tsize = 0;
		break;

	case 0413:
E 29
I 29
	if (u.u_exdata.ux_mag == 0413)
E 29
		pagi = SPAGI;
D 29
		/* fall into ... */
E 29
I 29
	else
		pagi = 0;
E 29
D 39

D 29
	case 0410:
		if (u.u_exdata.ux_tsize == 0) {
			u.u_error = ENOEXEC;
			goto bad;
		}
		break;

D 22
	case 0411:
		u.u_error = ENOEXEC;
		goto bad;

E 22
	default:
		u.u_error = ENOEXEC;
		goto bad;
	}
E 29
	if(u.u_exdata.ux_tsize!=0 && (ip->i_flag&ITEXT)==0 && ip->i_count!=1) {
E 39
I 39
	if (u.u_exdata.ux_tsize!=0 && (ip->i_flag&ITEXT)==0 &&
	    ip->i_count!=1) {
E 39
D 21
		u.u_error = ETXTBSY;
		goto bad;
E 21
I 21
		register struct file *fp;

D 32
		for (fp = file; fp < &file[NFILE]; fp++)
E 32
I 32
D 39
		for (fp = file; fp < fileNFILE; fp++)
E 39
I 39
		for (fp = file; fp < fileNFILE; fp++) {
D 54
			if (fp->f_flag & FSOCKET)
				continue;
E 39
E 32
			if (fp->f_inode == ip && (fp->f_flag&FWRITE)) {
E 54
I 54
			if (fp->f_type == DTYPE_FILE &&
I 78
			    fp->f_count > 0 &&
E 78
			    fp->f_inode == ip && (fp->f_flag&FWRITE)) {
E 54
				u.u_error = ETXTBSY;
				goto bad;
			}
I 39
		}
E 39
E 21
	}

	/*
D 39
	 * find text and data sizes
	 * try them out for possible
	 * exceed of max sizes
E 39
I 39
	 * Compute text and data sizes and make sure not too large.
E 39
	 */
D 39

E 39
	ts = clrnd(btoc(u.u_exdata.ux_tsize));
	ds = clrnd(btoc((u.u_exdata.ux_dsize+u.u_exdata.ux_bsize)));
	ss = clrnd(SSIZE + btoc(nargc));
D 22
	if (overlay) {
D 8
		if ((u.u_procp->p_flag & SPAGI) || u.u_sep==0 && ctos(ts) != ctos(u.u_tsize) || nargc) {
E 8
I 8
		if ((u.u_procp->p_flag & SPAGI) ||
		    u.u_sep==0 && ctos(ts) != ctos(u.u_tsize) || nargc) {
E 8
			u.u_error = ENOMEM;
			goto bad;
		}
		ds = u.u_dsize;
		ss = u.u_ssize;
		sep = u.u_sep;
		xfree();
		xalloc(ip, pagi);
		u.u_ar0[PC] = u.u_exdata.ux_entloc + 2; /* skip over entry mask */
	} else {
		if (chksize(ts, ds, ss))
			goto bad;
		u.u_cdmap = zdmap;
		u.u_csmap = zdmap;
		if (swpexpand(ds, ss, &u.u_cdmap, &u.u_csmap) == NULL)
			goto bad;
E 22
I 22
	if (chksize(ts, ds, ss))
		goto bad;
I 39

	/*
	 * Make sure enough space to start process.
	 */
E 39
	u.u_cdmap = zdmap;
	u.u_csmap = zdmap;
	if (swpexpand(ds, ss, &u.u_cdmap, &u.u_csmap) == NULL)
		goto bad;
E 22

D 22
		/*
		 * At this point, committed to the new image!
		 * Release virtual memory resources of old process, and
		 * initialize the virtual memory of the new process.
		 * If we resulted from vfork(), instead wakeup our
		 * parent who will set SVFDONE when he has taken back
		 * our resources.
		 */
		u.u_prof.pr_scale = 0;
		if ((u.u_procp->p_flag & SVFORK) == 0)
			vrelvm();
		else {
			u.u_procp->p_flag &= ~SVFORK;
			u.u_procp->p_flag |= SKEEP;
			wakeup((caddr_t)u.u_procp);
			while ((u.u_procp->p_flag & SVFDONE) == 0)
				sleep((caddr_t)u.u_procp, PZERO - 1);
			u.u_procp->p_flag &= ~(SVFDONE|SKEEP);
		}
		u.u_procp->p_flag &= ~(SPAGI|SANOM|SUANOM);
		u.u_procp->p_flag |= pagi;
		u.u_dmap = u.u_cdmap;
		u.u_smap = u.u_csmap;
		vgetvm(ts, ds, ss);
E 22
I 22
	/*
	 * At this point, committed to the new image!
	 * Release virtual memory resources of old process, and
	 * initialize the virtual memory of the new process.
	 * If we resulted from vfork(), instead wakeup our
	 * parent who will set SVFDONE when he has taken back
	 * our resources.
	 */
D 62
	u.u_prof.pr_scale = 0;
E 62
	if ((u.u_procp->p_flag & SVFORK) == 0)
		vrelvm();
	else {
		u.u_procp->p_flag &= ~SVFORK;
		u.u_procp->p_flag |= SKEEP;
		wakeup((caddr_t)u.u_procp);
		while ((u.u_procp->p_flag & SVFDONE) == 0)
			sleep((caddr_t)u.u_procp, PZERO - 1);
		u.u_procp->p_flag &= ~(SVFDONE|SKEEP);
	}
D 37
	u.u_procp->p_flag &= ~(SPAGI|SANOM|SUANOM|SNUSIG);
E 37
I 37
	u.u_procp->p_flag &= ~(SPAGI|SSEQL|SUANOM|SNUSIG);
E 37
	u.u_procp->p_flag |= pagi;
	u.u_dmap = u.u_cdmap;
	u.u_smap = u.u_csmap;
	vgetvm(ts, ds, ss);
E 22

D 22
		if (pagi == 0) {
			/*
			 * Read in data segment.
			 */
			u.u_base = (char *)ctob(ts);
			u.u_offset = sizeof(u.u_exdata)+u.u_exdata.ux_tsize;
			u.u_count = u.u_exdata.ux_dsize;
			readi(ip);
		}
		xalloc(ip, pagi);
		if (pagi && u.u_procp->p_textp)
			vinifod((struct fpte *)dptopte(u.u_procp, 0),
			    PG_FTEXT, u.u_procp->p_textp->x_iptr,
			    1 + ts/CLSIZE, (int)btoc(u.u_exdata.ux_dsize));

		/* THIS SHOULD BE DONE AT A LOWER LEVEL, IF AT ALL */
D 13
		mtpr(TBIA,1);
E 13
I 13
		mtpr(TBIA, 0);
E 13

E 22
I 22
D 59
	if (pagi == 0) {
E 22
		/*
D 22
		 * set SUID/SGID protections, if no tracing
E 22
I 22
		 * Read in data segment.
E 22
		 */
D 22
		if ((u.u_procp->p_flag&STRC)==0) {
			if(ip->i_mode&ISUID)
				if(u.u_uid != 0) {
					u.u_uid = ip->i_uid;
					u.u_procp->p_uid = ip->i_uid;
				}
			if(ip->i_mode&ISGID)
				u.u_gid = ip->i_gid;
		} else
D 4
			psignal(u.u_procp, SIGTRC);
E 4
I 4
			psignal(u.u_procp, SIGTRAP);
E 22
I 22
		u.u_base = (char *)ctob(ts);
		u.u_offset = sizeof(u.u_exdata)+u.u_exdata.ux_tsize;
		u.u_count = u.u_exdata.ux_dsize;
		readi(ip);
E 22
E 4
	}
E 59
I 59
	if (pagi == 0)
D 60
		u.u_error = readip1(ip, (char*)ctob(ts), u.u_exdata.ux_dsize,
		    sizeof(u.u_exdata)+u.u_exdata.ux_tsize, 0, 0);
E 60
I 60
		u.u_error =
		    rdwri(UIO_READ, ip,
D 72
			(char*)ctob(ts), (int)u.u_exdata.ux_dsize,
E 72
I 72
			(char *)ctob(dptov(u.u_procp, 0)),
			(int)u.u_exdata.ux_dsize,
E 72
			(int)(sizeof(u.u_exdata)+u.u_exdata.ux_tsize),
			0, (int *)0);
E 60
E 59
I 22
	xalloc(ip, pagi);
	if (pagi && u.u_procp->p_textp)
		vinifod((struct fpte *)dptopte(u.u_procp, 0),
		    PG_FTEXT, u.u_procp->p_textp->x_iptr,
D 69
		    1 + ts/CLSIZE, (int)btoc(u.u_exdata.ux_dsize));
E 69
I 69
		    (long)(1 + ts/CLSIZE), (int)btoc(u.u_exdata.ux_dsize));
E 69

I 72
#ifdef vax
E 72
	/* THIS SHOULD BE DONE AT A LOWER LEVEL, IF AT ALL */
I 66
#include "../vax/mtpr.h"		/* XXX */
E 66
	mtpr(TBIA, 0);
I 72
#endif
E 72

I 55
	if (u.u_error)
		swkill(u.u_procp, "i/o error mapping pages");
E 55
	/*
	 * set SUID/SGID protections, if no tracing
	 */
	if ((u.u_procp->p_flag&STRC)==0) {
D 29
		if(ip->i_mode&ISUID)
			if(u.u_uid != 0) {
				u.u_uid = ip->i_uid;
				u.u_procp->p_uid = ip->i_uid;
			}
		if(ip->i_mode&ISGID)
			u.u_gid = ip->i_gid;
E 29
I 29
D 39
#ifndef	MELB
		if(u.u_uid != 0)
#endif
		{
			u.u_uid = uid;
			u.u_procp->p_uid = uid;
		}
E 39
I 39
		u.u_uid = uid;
		u.u_procp->p_uid = uid;
E 39
		u.u_gid = gid;
I 48
D 61
		u.u_grps[gid/(sizeof(int)*8)] |= 1 << (gid%(sizeof(int)*8));
E 61
I 61
D 69
		entergroup(gid);
E 69
I 69
D 85
		(void) entergroup(gid);
E 85
E 69
E 61
E 48
E 29
	} else
		psignal(u.u_procp, SIGTRAP);
E 22
	u.u_tsize = ts;
	u.u_dsize = ds;
	u.u_ssize = ss;
D 22
	u.u_sep = sep;
E 22
bad:
D 22
	return(overlay);
E 22
I 22
	return;
E 22
}

/*
 * Clear registers on exec
 */
setregs()
{
D 4
	register int *rp;
E 4
I 4
	register int (**rp)();
E 4
	register i;
I 30
D 35
#ifdef UCBIPC
	register struct port *pt;
#endif UCBIPC
E 35
E 30
I 5
	long sigmask;
E 5

D 5
	for(rp = &u.u_signal[0]; rp < &u.u_signal[NSIG]; rp++)
D 4
		if((*rp & 1) == 0)
E 4
I 4
		if(((int)*rp & 1) == 0)
E 4
			*rp = 0;
E 5
I 5
D 39
	for(rp = &u.u_signal[0], sigmask = 1L; rp < &u.u_signal[NSIG];
E 39
I 39
D 51
	for (rp = &u.u_signal[0], sigmask = 1L; rp < &u.u_signal[NSIG];
E 51
I 51
	for (rp = &u.u_signal[1], sigmask = 1L; rp < &u.u_signal[NSIG];
E 51
E 39
	    sigmask <<= 1, rp++) {
		switch (*rp) {

		case SIG_IGN:
		case SIG_DFL:
		case SIG_HOLD:
			continue;

		default:
			/*
D 6
			 * Normal or deferring catch.
			 * If deferred, now hold it, else
			 * revert to default.
E 6
I 6
			 * Normal or deferring catch; revert to default.
E 6
			 */
D 6
			if (SIGISDEFER(*rp))
				*rp = SIG_HOLD;
			else
				*rp = SIG_DFL;
E 6
I 6
			(void) spl6();
			*rp = SIG_DFL;
E 6
			if ((int)*rp & 1)
				u.u_procp->p_siga0 |= sigmask;
			else
D 50
				u.u_procp->p_siga1 &= ~sigmask;
E 50
I 50
				u.u_procp->p_siga0 &= ~sigmask;
E 50
			if ((int)*rp & 2)
				u.u_procp->p_siga1 |= sigmask;
			else
				u.u_procp->p_siga1 &= ~sigmask;
I 6
			(void) spl0();
E 6
			continue;
		}
	}
I 72
#ifdef vax
E 72
E 5
/*
D 39
	for(rp = &u.u_ar0[0]; rp < &u.u_ar0[16];)
E 39
I 39
	for (rp = &u.u_ar0[0]; rp < &u.u_ar0[16];)
E 39
		*rp++ = 0;
*/
D 72
	u.u_ar0[PC] = u.u_exdata.ux_entloc + 2; /* skip over entry mask */
E 72
I 72
	u.u_ar0[PC] = u.u_exdata.ux_entloc+2;
#endif
#ifdef sun
	{ register struct regs *r = (struct regs *)u.u_ar0;
	  for (i = 0; i < 8; i++) {
		r->r_dreg[i] = 0;
		if (&r->r_areg[i] != &r->r_sp)
			r->r_areg[i] = 0;
	  }
	  r->r_sr = PSL_USERSET;
	  r->r_pc = u.u_exdata.ux_entloc;
	}
#endif
E 72
D 39
	for(i=0; i<NOFILE; i++) {
E 39
I 39
	for (i=0; i<NOFILE; i++) {
E 39
D 76
		if (u.u_pofile[i]&EXCLOSE) {
E 76
I 76
		if (u.u_pofile[i]&UF_EXCLOSE) {
E 76
I 30
D 35
#ifndef UCBIPC
E 35
E 30
D 44
			closef(u.u_ofile[i]);
E 44
I 44
D 56
			closef(u.u_ofile[i], 1);
E 56
I 56
			closef(u.u_ofile[i], 1, u.u_pofile[i]);
E 56
E 44
			u.u_ofile[i] = NULL;
I 30
D 35
#else UCBIPC
			if (u.u_pofile[i]&ISPORT) {
				pt = u.u_oport[i];
				if (--pt->pt_count == 0)
					ptclose(pt);
				u.u_pofile[i] &= ~ISPORT;
				u.u_oport[i] = NULL;
			} else {
				closef(u.u_ofile[i]);
				u.u_ofile[i] = NULL;
			}
#endif UCBIPC
E 35
E 30
I 5
D 56
			u.u_pofile[i] &= ~EXCLOSE;
E 56
I 56
			u.u_pofile[i] = 0;
E 56
E 5
		}
I 72
D 79
#ifdef SUNMMAP
E 79
		u.u_pofile[i] &= ~UF_MAPPED;
D 79
#endif
E 79
E 72
D 5
		u.u_pofile[i] &= ~EXCLOSE;
E 5
	}
I 39

E 39
	/*
	 * Remember file name for accounting.
	 */
	u.u_acflag &= ~AFORK;
D 52
	bcopy((caddr_t)u.u_dbuf, (caddr_t)u.u_comm, DIRSIZ);
E 52
I 52
	bcopy((caddr_t)u.u_dent.d_name, (caddr_t)u.u_comm,
D 60
	    u.u_dent.d_namlen + 1);
E 60
I 60
	    (unsigned)(u.u_dent.d_namlen + 1));
I 72
#ifdef sun
	u.u_eosys = REALLYRETURN;
#endif
E 72
E 60
E 52
}

/*
D 39
 * exit system call:
 * pass back caller's arg
E 39
I 39
 * Exit system call: pass back caller's arg
E 39
 */
rexit()
{
	register struct a {
		int	rval;
	} *uap;

	uap = (struct a *)u.u_ap;
	exit((uap->rval & 0377) << 8);
}

/*
 * Release resources.
 * Save u. area for parent to look at.
 * Enter zombie state.
 * Wake up parent and init processes,
 * and dispose of children.
 */
exit(rv)
{
	register int i;
	register struct proc *p, *q;
D 56
	register struct file *f;
E 56
I 30
D 35
#ifdef UCBIPC
	register struct port *pt;
#endif UCBIPC
E 35
E 30
	register int x;
I 71
D 77
	struct mbuf *m = m_getclr(M_WAIT);
E 77
I 77
	struct mbuf *m = m_getclr(M_WAIT, MT_ZOMBIE);
E 77
E 71

#ifdef PGINPROF
	vmsizmon();
#endif
	p = u.u_procp;
	p->p_flag &= ~(STRC|SULOCK);
	p->p_flag |= SWEXIT;
D 62
	p->p_clktim = 0;
E 62
I 62
D 64
	timerclear(&p->p_seltimer);
E 64
E 62
I 5
	(void) spl6();
	if ((int)SIG_IGN & 1)
		p->p_siga0 = ~0;
	else
		p->p_siga0 = 0;
	if ((int)SIG_IGN & 2)
		p->p_siga1 = ~0;
	else
D 6
		p->p_siga0 = 0;
E 6
I 6
		p->p_siga1 = 0;
E 6
	(void) spl0();
E 5
D 12
	rate.v_pgin -= p->p_aveflt;
E 12
D 25
	p->p_aveflt = 0;
E 25
I 25
	p->p_cpticks = 0;
	p->p_pctcpu = 0;
E 25
D 39
	for(i=0; i<NSIG; i++)
E 39
I 39
	for (i=0; i<NSIG; i++)
E 39
D 4
		u.u_signal[i] = 1;
E 4
I 4
		u.u_signal[i] = SIG_IGN;
I 64
D 65
	untimeout(unrto, p);
E 65
I 65
D 67
	untimeout(realitexpire, p);
E 67
I 67
	untimeout(realitexpire, (caddr_t)p);
E 67
E 65
E 64
E 4
	/*
	 * Release virtual memory.  If we resulted from
	 * a vfork(), instead give the resources back to
	 * the parent.
	 */
	if ((p->p_flag & SVFORK) == 0)
		vrelvm();
	else {
		p->p_flag &= ~SVFORK;
		wakeup((caddr_t)p);
		while ((p->p_flag & SVFDONE) == 0)
			sleep((caddr_t)p, PZERO - 1);
		p->p_flag &= ~SVFDONE;
	}
D 39
	for(i=0; i<NOFILE; i++) {
E 39
I 39
D 56
	for (i=0; i<NOFILE; i++) {
E 56
I 56
	for (i = 0; i < NOFILE; i++) {
D 75
#ifdef notdef
		/* why was this like this? */
E 75
I 75
		struct file *f;
		int p;

E 75
E 56
E 39
I 30
D 35
#ifndef UCBIPC
E 35
E 30
		f = u.u_ofile[i];
		u.u_ofile[i] = NULL;
D 44
		closef(f);
E 44
I 44
D 75
		closef(f, 1);
I 56
#else
		closef(u.u_ofile[i], 1, u.u_pofile[i]);
		u.u_ofile[i] = NULL;
E 75
I 75
		p = u.u_pofile[i];
E 75
		u.u_pofile[i] = 0;
D 75
#endif
E 75
I 75
		closef(f, 1, p);
E 75
E 56
E 44
I 30
D 35
#else UCBIPC
		if (u.u_pofile[i]&ISPORT) {
			pt = u.u_oport[i];
			if (--pt->pt_count == 0)
				ptclose(pt);
			u.u_oport[i] = NULL;
		} else {
			f = u.u_ofile[i];
			u.u_ofile[i] = NULL;
			closef(f);
		}
#endif UCBIPC
E 35
E 30
	}
D 39
	plock(u.u_cdir);
E 39
I 39
	ilock(u.u_cdir);
E 39
	iput(u.u_cdir);
	if (u.u_rdir) {
D 39
		plock(u.u_rdir);
E 39
I 39
		ilock(u.u_rdir);
E 39
		iput(u.u_rdir);
	}
I 16
D 62
	u.u_limit[LIM_FSIZE] = INFINITY;
E 62
I 62
	u.u_rlimit[RLIMIT_FSIZE].rlim_cur = RLIM_INFINITY;
E 62
E 16
	acct();
I 53
#ifdef QUOTA
	qclean();
I 72
#endif
#ifdef sun
D 88
	ctxfree(&u);
E 88
I 88
	ctxfree(u.u_procp);
E 88
E 72
#endif
E 53
	vrelpt(u.u_procp);
	vrelu(u.u_procp, 0);
I 46
D 47
	(void) slpimp();		/* hack for mem alloc race XXX */
E 47
I 47
	(void) spl5();		/* hack for mem alloc race XXX */
E 47
E 46
	multprog--;
D 12
	spl7();			/* clock will get mad because of overlaying */
E 12
I 12
D 39
/*	spl7();			/* clock will get mad because of overlaying */
E 39
D 23
	noproc = 1;
E 23
E 12
	p->p_stat = SZOMB;
I 23
	noproc = 1;
E 23
	i = PIDHASH(p->p_pid);
	x = p - proc;
	if (pidhash[i] == x)
		pidhash[i] = p->p_idhash;
	else {
		for (i = pidhash[i]; i != 0; i = proc[i].p_idhash)
			if (proc[i].p_idhash == x) {
				proc[i].p_idhash = p->p_idhash;
				goto done;
			}
		panic("exit");
	}
I 26
	if (p->p_pid == 1)
		panic("init died");
E 26
done:
D 62
	((struct xproc *)p)->xp_xstat = rv;		/* overlay */
	((struct xproc *)p)->xp_vm = u.u_vm;		/* overlay */
	vmsadd(&((struct xproc *)p)->xp_vm, &u.u_cvm);
E 62
I 62
	p->p_xstat = rv;
I 75
if (m == 0)
panic("exit: m_getclr");
E 75
D 71
	{ struct mbuf *m = m_getclr(M_DONTWAIT); p->p_ru = mtod(m, struct rusage *); }
E 71
I 71
	p->p_ru = mtod(m, struct rusage *);
E 71
	*p->p_ru = u.u_ru;
	ruadd(p->p_ru, &u.u_cru);
E 62
D 33
	for(q = &proc[0]; q < &proc[NPROC]; q++)
E 33
I 33
D 39
	for(q = proc; q < procNPROC; q++)
E 33
D 5
		if(q->p_ppid == p->p_pid) {
			wakeup((caddr_t)&proc[1]);
E 5
I 5
		if(q->p_pptr == p) {
E 39
I 39
	for (q = proc; q < procNPROC; q++)
		if (q->p_pptr == p) {
I 53
			if (q->p_osptr)
				q->p_osptr->p_ysptr = q->p_ysptr;
			if (q->p_ysptr)
				q->p_ysptr->p_osptr = q->p_osptr;
			if (proc[1].p_cptr)
				proc[1].p_cptr->p_ysptr = q;
			q->p_osptr = proc[1].p_cptr;
			q->p_ysptr = NULL;
			proc[1].p_cptr = q;

E 53
E 39
			q->p_pptr = &proc[1];
E 5
			q->p_ppid = 1;
I 14
D 15
			q->p_flag |= SDETACH;
E 15
E 14
D 5
			if (q->p_stat==SSTOP)
				setrun(q);
E 5
I 5
			wakeup((caddr_t)&proc[1]);
			/*
D 7
			 * Stopped or traced processes are killed
E 7
I 7
			 * Traced processes are killed
E 7
			 * since their existence means someone is screwing up.
I 7
D 15
			 * Traced processes are sent a hangup and a continue.
E 15
I 15
			 * Stopped processes are sent a hangup and a continue.
E 15
			 * This is designed to be ``safe'' for setuid
			 * processes since they must be willing to tolerate
			 * hangups anyways.
E 7
			 */
D 7
			if (q->p_stat == SSTOP || q->p_flag&STRC) {
E 7
I 7
			if (q->p_flag&STRC) {
E 7
				q->p_flag &= ~STRC;
				psignal(q, SIGKILL);
I 7
			} else if (q->p_stat == SSTOP) {
				psignal(q, SIGHUP);
				psignal(q, SIGCONT);
D 8
				/*
				 * Protect this process from future
				 * tty signals, and clear TSTP if pending.
				 */
				q->p_pgrp = 0;
				q->p_sig &= ~(1<<(SIGTSTP-1));
E 8
E 7
			}
I 8
			/*
			 * Protect this process from future
D 15
			 * tty signals, and clear TSTP/TTIN/TTOU if pending.
E 15
I 15
D 45
			 * tty signals, clear TSTP/TTIN/TTOU if pending,
			 * and set SDETACH bit on procs.
E 45
I 45
			 * tty signals, clear TSTP/TTIN/TTOU if pending.
E 45
E 15
			 */
D 10
			q->p_pgrp = 0;
E 10
I 10
D 12
			q->p_pgrp = q->p_pid;
E 10
#define	bit(a)	(1<<(a-1))
			q->p_sig &= ~(bit(SIGTSTP)|bit(SIGTTIN)|bit(SIGTTOU));
E 12
I 12
D 28
			spgrp(q, -1);
E 28
I 28
			(void) spgrp(q, -1);
E 28
E 12
E 8
E 5
		}
D 5
	q = pfind(p->p_ppid);
	if (q)
		wakeup((caddr_t)q);
E 5
I 5
D 51
	wakeup((caddr_t)p->p_pptr);
E 51
	psignal(p->p_pptr, SIGCHLD);
I 51
	wakeup((caddr_t)p->p_pptr);
E 51
E 5
	swtch();
}

I 81
wait()
{
	struct rusage ru, *rup;

	if ((u.u_ar0[PS] & PSL_ALLCC) != PSL_ALLCC) {
		u.u_error = wait1(0, (struct rusage *)0);
		return;
	}
	rup = (struct rusage *)u.u_ar0[R1];
	u.u_error = wait1(u.u_ar0[R0], &ru);
	if (u.u_error)
		return;
	(void) copyout((caddr_t)&ru, (caddr_t)rup, sizeof (struct rusage));
}

#ifndef NOCOMPAT
E 81
I 65
D 79
#include <vtimes.h>
E 79
I 79
#include "../h/vtimes.h"
E 79

E 65
D 63
wait()
E 63
I 63
owait()
E 63
{
I 5
D 62
	struct vtimes vm;
	struct vtimes *vp;
E 62
I 62
D 65
	struct rusage ru, *rup;
E 65
I 65
	struct rusage ru;
	struct vtimes *vtp, avt;
E 65
E 62
E 5

D 5
	wait1((struct vtimes *)0);
E 5
I 5
	if ((u.u_ar0[PS] & PSL_ALLCC) != PSL_ALLCC) {
D 62
		wait1(0, (struct vtimes *)0);
E 62
I 62
D 81
		wait1(0, (struct rusage *)0);
E 81
I 81
		u.u_error = wait1(0, (struct rusage *)0);
E 81
E 62
		return;
	}
D 62
	vp = (struct vtimes *)u.u_ar0[R1];
	wait1(u.u_ar0[R0], &vm);
E 62
I 62
D 65
	rup = (struct rusage *)u.u_ar0[R1];
E 65
I 65
	vtp = (struct vtimes *)u.u_ar0[R1];
E 65
D 81
	wait1(u.u_ar0[R0], &ru);
E 81
I 81
	u.u_error = wait1(u.u_ar0[R0], &ru);
E 81
E 62
	if (u.u_error)
		return;
D 62
	(void) copyout((caddr_t)&vm, (caddr_t)vp, sizeof (struct vtimes));
E 62
I 62
D 65
	(void) copyout((caddr_t)&ru, (caddr_t)rup, sizeof (struct rusage));
E 65
I 65
	getvtimes(&ru, &avt);
	(void) copyout((caddr_t)&avt, (caddr_t)vtp, sizeof (struct vtimes));
E 65
E 62
E 5
}
I 81
#endif
E 81

/*
 * Wait system call.
 * Search for a terminated (zombie) child,
 * finally lay it to rest, and collect its status.
 * Look also for stopped (traced) children,
 * and pass back status from them.
 */
D 5
wait1(vp)
E 5
I 5
D 62
wait1(options, vp)
	register options;
E 5
	struct vtimes *vp;
E 62
I 62
wait1(options, ru)
	register int options;
	struct rusage *ru;
E 62
{
	register f;
D 53
	register struct proc *p;
E 53
I 53
	register struct proc *p, *q;
E 53

	f = 0;
D 5

E 5
loop:
D 33
	for(p = &proc[0]; p < &proc[NPROC]; p++)
E 33
I 33
D 39
	for(p = proc; p < procNPROC; p++)
E 33
D 5
	if(p->p_ppid == u.u_procp->p_pid) {
E 5
I 5
	if(p->p_pptr == u.u_procp) {
E 39
I 39
	for (p = proc; p < procNPROC; p++)
	if (p->p_pptr == u.u_procp) {
E 39
E 5
		f++;
D 39
		if(p->p_stat == SZOMB) {
E 39
I 39
		if (p->p_stat == SZOMB) {
E 39
			u.u_r.r_val1 = p->p_pid;
D 62
			u.u_r.r_val2 = ((struct xproc *)p)->xp_xstat;
			((struct xproc *)p)->xp_xstat = 0;
			if (vp)
				*vp = ((struct xproc *)p)->xp_vm;
			vmsadd(&u.u_cvm, &((struct xproc *)p)->xp_vm);
			((struct xproc *)p)->xp_vm = zvms;
E 62
I 62
			u.u_r.r_val2 = p->p_xstat;
			p->p_xstat = 0;
			if (ru)
				*ru = *p->p_ru;
			ruadd(&u.u_cru, p->p_ru);
D 69
			m_free(dtom(p->p_ru));
E 69
I 69
			(void) m_free(dtom(p->p_ru));
E 69
			p->p_ru = 0;
E 62
			p->p_stat = NULL;
			p->p_pid = 0;
			p->p_ppid = 0;
I 53
			if (q = p->p_ysptr)
				q->p_osptr = p->p_osptr;
			if (q = p->p_osptr)
				q->p_ysptr = p->p_ysptr;
			if ((q = p->p_pptr)->p_cptr == p)
				q->p_cptr = p->p_osptr;
E 53
I 5
			p->p_pptr = 0;
I 53
			p->p_ysptr = 0;
			p->p_osptr = 0;
			p->p_cptr = 0;
E 53
E 5
			p->p_sig = 0;
I 5
			p->p_siga0 = 0;
			p->p_siga1 = 0;
E 5
			p->p_pgrp = 0;
			p->p_flag = 0;
			p->p_wchan = 0;
I 5
			p->p_cursig = 0;
E 5
D 81
			return;
E 81
I 81
			return (0);
E 81
		}
D 5
		if(p->p_stat == SSTOP) {
			if((p->p_flag&SWTED) == 0) {
				p->p_flag |= SWTED;
				u.u_r.r_val1 = p->p_pid;
				u.u_r.r_val2 = (fsig(p)<<8) | 0177;
				return;
			}
			continue;
E 5
I 5
		if (p->p_stat == SSTOP && (p->p_flag&SWTED)==0 &&
		    (p->p_flag&STRC || options&WUNTRACED)) {
			p->p_flag |= SWTED;
			u.u_r.r_val1 = p->p_pid;
			u.u_r.r_val2 = (p->p_cursig<<8) | WSTOPPED;
D 81
			return;
E 81
I 81
			return (0);
E 81
E 5
		}
	}
D 5
	if(f) {
		sleep((caddr_t)u.u_procp, PWAIT);
		goto loop;
E 5
I 5
D 81
	if (f==0) {
		u.u_error = ECHILD;
		return;
E 81
I 81
	if (f == 0) {
		return (ECHILD);
E 81
E 5
	}
D 5
	u.u_error = ECHILD;
E 5
I 5
	if (options&WNOHANG) {
		u.u_r.r_val1 = 0;
D 81
		return;
E 81
I 81
		return (0);
E 81
	}
I 6
D 22
/*
E 6
	if (setjmp(u.u_qsav)) {
E 22
I 22
D 64
	if ((u.u_procp->p_flag&SNUSIG) && setjmp(u.u_qsav)) {
E 64
I 64
	if ((u.u_procp->p_flag&SNUSIG) && setjmp(&u.u_qsave)) {
E 64
E 22
		u.u_eosys = RESTARTSYS;
D 81
		return;
E 81
I 81
		return (0);
E 81
	}
I 6
D 22
*/
E 22
E 6
	sleep((caddr_t)u.u_procp, PWAIT);
	goto loop;
E 5
}

/*
 * fork system call.
 */
fork()
{

	u.u_cdmap = zdmap;
	u.u_csmap = zdmap;
	if (swpexpand(u.u_dsize, u.u_ssize, &u.u_cdmap, &u.u_csmap) == 0) {
		u.u_r.r_val2 = 0;
		return;
	}
	fork1(0);
}

fork1(isvfork)
{
	register struct proc *p1, *p2;
I 53
D 89
#ifndef	QUOTA
E 89
E 53
	register a;

	a = 0;
I 53
D 89
#else
	if (u.u_quota != NOQUOT && u.u_quota->q_plim &&
	    u.u_quota->q_cnt >= u.u_quota->q_plim) {
		u.u_error = EPROCLIM;
		return;
	}
#endif
E 89
E 53
	p2 = NULL;
D 33
	for(p1 = &proc[0]; p1 < &proc[NPROC]; p1++) {
E 33
I 33
D 39
	for(p1 = proc; p1 < procNPROC; p1++) {
E 39
I 39
	for (p1 = proc; p1 < procNPROC; p1++) {
I 53
D 89
#ifdef QUOTA
		if (p1->p_stat == NULL) {
			p2 = p1;
			break;
		}
#else
E 89
E 53
E 39
E 33
		if (p1->p_stat==NULL && p2==NULL)
			p2 = p1;
		else {
			if (p1->p_uid==u.u_uid && p1->p_stat!=NULL)
				a++;
		}
I 53
D 89
#endif
E 89
E 53
	}
I 29
D 30

E 30
E 29
	/*
	 * Disallow if
	 *  No processes at all;
	 *  not su and too many procs owned; or
	 *  not su and would take last slot.
	 */
I 35
	if (p2==NULL)
		tablefull("proc");
I 53
D 89
#ifdef QUOTA
	if (p2==NULL || (u.u_uid!=0 && p2==procNPROC-1)) {
#else
E 89
E 53
E 35
D 29
	if (p2==NULL || (u.u_uid!=0 && (p2==&proc[NPROC-1] || a>MAXUPRC))) {
E 29
I 29
D 30
	if (p2==NULL || (u.u_uid!=0 && (p2>=&proc[NPROC-5] || a>MAXUPRC))) {
E 30
I 30
D 33
	if (p2==NULL || (u.u_uid!=0 && (p2==&proc[NPROC-1] || a>MAXUPRC))) {
E 33
I 33
	if (p2==NULL || (u.u_uid!=0 && (p2==procNPROC-1 || a>MAXUPRC))) {
I 53
D 89
#endif
E 89
E 53
E 33
E 30
E 29
		u.u_error = EAGAIN;
		if (!isvfork) {
D 3
			VOID vsexpand(0, &u.u_cdmap, 1);
			VOID vsexpand(0, &u.u_csmap, 1);
E 3
I 3
			(void) vsexpand(0, &u.u_cdmap, 1);
			(void) vsexpand(0, &u.u_csmap, 1);
E 3
		}
		goto out;
	}
	p1 = u.u_procp;
D 39
	if(newproc(isvfork)) {
E 39
I 39
	if (newproc(isvfork)) {
E 39
		u.u_r.r_val1 = p1->p_pid;
		u.u_r.r_val2 = 1;  /* child */
D 62
		u.u_start = time;
E 62
I 62
		u.u_start = time.tv_sec;
E 62
		u.u_acflag = AFORK;
I 53
D 89
#ifdef QUOTA
		u.u_qflags &= ~QUF_LOGIN;
#endif
E 89
E 53
		return;
	}
	u.u_r.r_val1 = p2->p_pid;

out:
	u.u_r.r_val2 = 0;
}

E 90
I 54
D 97
spgrp(top, npgrp)
E 97
I 97
spgrp(top)
E 97
D 90
register struct proc *top;
E 90
I 90
D 95
	register struct proc *top;
E 95
I 95
	struct proc *top;
E 95
E 90
{
D 95
	register struct proc *pp, *p;
E 95
I 95
	register struct proc *p;
E 95
	int f = 0;

D 95
	for (p = top; npgrp == -1 || u.u_uid == p->p_uid ||
	    !u.u_uid || inferior(p); p = pp) {
		if (npgrp == -1) {
#define	bit(a)	(1<<(a-1))
			p->p_sig &= ~(bit(SIGTSTP)|bit(SIGTTIN)|bit(SIGTTOU));
		} else
E 95
I 95
	p = top;
	for (;;) {
D 97
		if (npgrp == -1)
			p->p_sig &=
E 97
I 97
		p->p_sig &=
E 97
			  ~(sigmask(SIGTSTP)|sigmask(SIGTTIN)|sigmask(SIGTTOU));
D 97
		else
E 95
			p->p_pgrp = npgrp;
E 97
		f++;
		/*
D 95
		 * Search for children.
E 95
I 95
		 * If this process has children, descend to them next,
		 * otherwise do any siblings, and if done with this level,
		 * follow back up the tree (but not past top).
E 95
		 */
D 95
		for (pp = proc; pp < procNPROC; pp++)
			if (pp->p_pptr == p)
				goto cont;
		/*
		 * Search for siblings.
		 */
		for (; p != top; p = p->p_pptr)
			for (pp = p + 1; pp < procNPROC; pp++)
				if (pp->p_pptr == p->p_pptr)
					goto cont;
		break;
	cont:
		;
E 95
I 95
		if (p->p_cptr)
			p = p->p_cptr;
		else if (p == top)
			return (f);
		else if (p->p_osptr)
			p = p->p_osptr;
		else for (;;) {
			p = p->p_pptr;
			if (p == top)
				return (f);
D 97
if (p == &proc[1])
	panic("spgrp");
E 97
			if (p->p_osptr) {
				p = p->p_osptr;
				break;
			}
		}
E 95
	}
D 95
	return (f);
E 95
}

E 54
/*
D 54
 * break system call.
 *  -- bad planning: "break" is a dirty word in C.
E 54
I 54
 * Is p an inferior of the current process?
E 54
 */
D 54
sbreak()
E 54
I 54
inferior(p)
D 60
register struct proc *p;
E 60
I 60
	register struct proc *p;
E 60
E 54
{
D 54
	struct a {
		char	*nsiz;
	};
	register int n, d;
E 54

D 54
	/*
	 * set n to new data size
	 * set d to new-old
	 */

	n = btoc(((struct a *)u.u_ap)->nsiz);
	if (!u.u_sep)
		n -= ctos(u.u_tsize) * stoc(1);
	if (n < 0)
		n = 0;
	d = clrnd(n - u.u_dsize);
I 16
D 17
	if (u.u_dsize+d > u.u_limit[LIM_DATA]) {
E 17
I 17
	if (ctob(u.u_dsize+d) > u.u_limit[LIM_DATA]) {
E 17
		u.u_error = ENOMEM;
		return;
	}
E 16
	if (chksize(u.u_tsize, u.u_dsize+d, u.u_ssize))
		return;
	if (swpexpand(u.u_dsize+d, u.u_ssize, &u.u_dmap, &u.u_smap)==0)
		return;
	expand(d, P0BR);
E 54
I 54
	for (; p != u.u_procp; p = p->p_pptr)
		if (p->p_ppid == 0)
			return (0);
	return (1);
I 60
}

struct proc *
pfind(pid)
	int pid;
{
	register struct proc *p;

	for (p = &proc[pidhash[PIDHASH(pid)]]; p != &proc[0]; p = &proc[p->p_idhash])
		if (p->p_pid == pid)
			return (p);
	return ((struct proc *)0);
I 63
D 90
}

/*
 * Create a new process-- the internal version of
 * sys fork.
 * It returns 1 in the new process, 0 in the old.
 */
newproc(isvfork)
	int isvfork;
{
	register struct proc *p;
	register struct proc *rpp, *rip;
	register int n;
	register struct file *fp;

	p = NULL;
	/*
	 * First, just locate a slot for a process
	 * and copy the useful info from this process into it.
	 * The panic "cannot happen" because fork has already
	 * checked for the existence of a slot.
	 */
retry:
	mpid++;
	if (mpid >= 30000) {
		mpid = 0;
		goto retry;
	}
	for (rpp = proc; rpp < procNPROC; rpp++) {
		if (rpp->p_stat == NULL && p==NULL)
			p = rpp;
		if (rpp->p_pid==mpid || rpp->p_pgrp==mpid)
			goto retry;
	}
	if ((rpp = p) == NULL)
		panic("no procs");

	/*
	 * Make a proc table entry for the new process.
	 */
	rip = u.u_procp;
#ifdef QUOTA
D 89
	(rpp->p_quota = rip->p_quota)->q_cnt++;
E 89
I 89
	rpp->p_quota = rip->p_quota;
	rpp->p_quota->q_cnt++;
E 89
#endif
	rpp->p_stat = SIDL;
	timerclear(&rpp->p_realtimer.it_value);
	rpp->p_flag = SLOAD | (rip->p_flag & (SPAGI|SNUSIG));
	if (isvfork) {
		rpp->p_flag |= SVFORK;
		rpp->p_ndx = rip->p_ndx;
	} else
		rpp->p_ndx = rpp - proc;
	rpp->p_uid = rip->p_uid;
	rpp->p_pgrp = rip->p_pgrp;
	rpp->p_nice = rip->p_nice;
	rpp->p_textp = isvfork ? 0 : rip->p_textp;
	rpp->p_pid = mpid;
	rpp->p_ppid = rip->p_pid;
	rpp->p_pptr = rip;
	rpp->p_osptr = rip->p_cptr;
	if (rip->p_cptr)
		rip->p_cptr->p_ysptr = rpp;
	rpp->p_ysptr = NULL;
	rpp->p_cptr = NULL;
	rip->p_cptr = rpp;
	rpp->p_time = 0;
	rpp->p_cpu = 0;
	rpp->p_siga0 = rip->p_siga0;
	rpp->p_siga1 = rip->p_siga1;
	/* take along any pending signals, like stops? */
	if (isvfork) {
		rpp->p_tsize = rpp->p_dsize = rpp->p_ssize = 0;
		rpp->p_szpt = clrnd(ctopt(UPAGES));
		forkstat.cntvfork++;
		forkstat.sizvfork += rip->p_dsize + rip->p_ssize;
	} else {
		rpp->p_tsize = rip->p_tsize;
		rpp->p_dsize = rip->p_dsize;
		rpp->p_ssize = rip->p_ssize;
		rpp->p_szpt = rip->p_szpt;
		forkstat.cntfork++;
		forkstat.sizfork += rip->p_dsize + rip->p_ssize;
	}
	rpp->p_rssize = 0;
	rpp->p_maxrss = rip->p_maxrss;
	rpp->p_wchan = 0;
	rpp->p_slptime = 0;
	rpp->p_pctcpu = 0;
	rpp->p_cpticks = 0;
	n = PIDHASH(rpp->p_pid);
	p->p_idhash = pidhash[n];
	pidhash[n] = rpp - proc;
	multprog++;

	/*
	 * Increase reference counts on shared objects.
	 */
	for (n = 0; n < NOFILE; n++) {
		fp = u.u_ofile[n];
		if (fp == NULL)
			continue;
		fp->f_count++;
D 74
		if (u.u_pofile[n]&RDLOCK)
			fp->f_inode->i_rdlockc++;
		if (u.u_pofile[n]&WRLOCK)
			fp->f_inode->i_wrlockc++;
E 74
I 74
D 76
		if (u.u_pofile[n]&SHLOCK)
E 76
I 76
		if (u.u_pofile[n]&UF_SHLOCK)
E 76
			fp->f_inode->i_shlockc++;
D 76
		if (u.u_pofile[n]&EXLOCK)
E 76
I 76
		if (u.u_pofile[n]&UF_EXLOCK)
E 76
			fp->f_inode->i_exlockc++;
E 74
	}
	u.u_cdir->i_count++;
	if (u.u_rdir)
		u.u_rdir->i_count++;

	/*
	 * Partially simulate the environment
	 * of the new process so that when it is actually
	 * created (by copying) it will look right.
	 * This begins the section where we must prevent the parent
	 * from being swapped.
	 */
	rip->p_flag |= SKEEP;
	if (procdup(rpp, isvfork))
		return (1);

	/*
	 * Make child runnable and add to run queue.
	 */
	(void) spl6();
	rpp->p_stat = SRUN;
	setrq(rpp);
	(void) spl0();

	/*
	 * Cause child to take a non-local goto as soon as it runs.
	 * On older systems this was done with SSWAP bit in proc
	 * table; on VAX we use u.u_pcb.pcb_sswap so don't need
	 * to do rpp->p_flag |= SSWAP.  Actually do nothing here.
	 */
	/* rpp->p_flag |= SSWAP; */

	/*
	 * Now can be swapped.
	 */
	rip->p_flag &= ~SKEEP;

	/*
	 * If vfork make chain from parent process to child
	 * (where virtal memory is temporarily).  Wait for
	 * child to finish, steal virtual memory back,
	 * and wakeup child to let it die.
	 */
	if (isvfork) {
		u.u_procp->p_xlink = rpp;
		u.u_procp->p_flag |= SNOVM;
		while (rpp->p_flag & SVFORK)
			sleep((caddr_t)rpp, PZERO - 1);
		if ((rpp->p_flag & SLOAD) == 0)
			panic("newproc vfork");
		uaccess(rpp, Vfmap, &vfutl);
		u.u_procp->p_xlink = 0;
		vpassvm(rpp, u.u_procp, &vfutl, &u, Vfmap);
		u.u_procp->p_flag &= ~SNOVM;
		rpp->p_ndx = rpp - proc;
		rpp->p_flag |= SVFDONE;
		wakeup((caddr_t)rpp);
	}

	/*
	 * 0 return means parent.
	 */
	return (0);
E 90
E 63
E 60
E 54
}
I 92

/*
 * init the process queues
 */
pqinit()
{
	register struct proc *p;

	/*
	 * most procs are initially on freequeue
	 *	nb: we place them there in their "natural" order.
	 */

	freeproc = NULL;
	for (p = procNPROC; --p > proc; freeproc = p)
		p->p_nxt = freeproc;

	/*
	 * but proc[0] is special ...
	 */

	allproc = p;
	p->p_nxt = NULL;
	p->p_prev = &allproc;

	zombproc = NULL;
}
E 92
E 1
