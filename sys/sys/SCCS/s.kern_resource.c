h47014
s 00000/00007/00240
d D 7.2 87/07/20 15:31:16 mckusick 38 37
c delete unneeded header files
e
s 00001/00001/00246
d D 7.1 86/06/05 00:03:52 mckusick 37 36
c 4.3BSD release version
e
s 00002/00002/00245
d D 6.9 86/05/14 15:53:46 karels 36 35
c missing error return
e
s 00001/00001/00246
d D 6.8 85/10/23 18:14:36 karels 35 34
c maxdsize and maxtsize in bytes; careful of confusing blocks and pages
e
s 00007/00001/00240
d D 6.7 85/06/08 14:37:16 mckusick 34 33
c Add copyright
e
s 00001/00001/00240
d D 6.6 85/05/22 16:15:38 mckusick 33 32
c return EPERM when non-super-user tries to set another process's priority
e
s 00009/00004/00232
d D 6.5 85/03/08 15:43:35 mckusick 32 31
c impose the real vm limit rather than the best guess
e
s 00027/00025/00209
d D 6.4 84/11/20 11:15:28 karels 31 30
c NZERO now 0 (use PRIO_{MIN,MAX}); cleanup u.u_error crap (going to
c toss that sucker!)
e
s 00011/00011/00223
d D 6.3 84/08/29 20:20:02 bloom 30 29
c Change to includes.  no more ../h
e
s 00004/00008/00230
d D 6.2 84/05/22 11:44:49 karels 29 28
c linked lists of active, zombie and free procs; avoid linear proc
c searches wherever possible
e
s 00000/00000/00238
d D 6.1 83/07/29 06:33:36 sam 28 27
c 4.2 distribution
e
s 00000/00083/00238
d D 4.22 83/05/27 12:47:03 sam 27 26
c merge of bill's code plus lint (plus, of course, cleanup of bill's bugs)
e
s 00001/00001/00320
d D 4.21 83/05/23 00:30:28 sam 26 25
c looking at wrong proc
e
s 00001/00000/00320
d D 4.20 83/02/10 18:41:53 sam 25 23
c groups set members are shorts, not ints; hz no longer in systm.h
e
s 00001/00000/00320
d R 4.20 83/02/10 16:08:50 sam 24 23
c removing hz from systm.h
e
s 00014/00023/00306
d D 4.19 82/12/28 23:46:54 sam 23 22
c copyin & copyout now return EFAULT and all callers uniformly 
c return (or ignore) this value
e
s 00001/00001/00328
d D 4.18 82/12/17 11:44:27 sam 22 21
c sun merge
e
s 00001/00001/00328
d D 4.17 82/10/19 10:30:58 root 21 20
c more lint
e
s 00004/00003/00325
d D 4.16 82/10/17 21:49:10 root 20 19
c more lint
e
s 00001/00001/00327
d D 4.15 82/10/17 14:04:42 root 19 18
c fix lint
e
s 00105/00011/00223
d D 4.14 82/09/12 10:20:26 root 18 17
c 4.2 style
e
s 00012/00119/00222
d D 4.13 82/09/06 22:49:11 root 17 16
c 
e
s 00207/00037/00134
d D 4.12 82/09/04 09:11:33 root 16 15
c compilable 4.2 calls, not tested
e
s 00005/00007/00166
d D 4.11 82/08/22 20:32:56 root 15 14
c write accounting records with rdwri()
e
s 00059/00000/00114
d D 4.10 82/07/24 18:10:07 root 14 13
c merge with calder
e
s 00007/00005/00107
d D 4.9 82/07/12 18:16:32 kre 13 11
c Allow acct file swap w/o losing any info;
c use NODEV for ac_tty if proc had no controlling tty.
e
s 00000/00000/00112
d R 4.9 82/07/12 17:13:11 kre 12 11
c allow acct file switch with no info loss,
c make ac_tty be NODEV if proc has no controlling tty.
e
s 00001/00002/00111
d D 4.8 82/06/10 12:40:48 mckusick 11 10
c change iput() to irele() when releasing unlocked inodes
e
s 00002/00002/00111
d D 4.7 82/06/07 23:53:51 mckusick 10 9
c irele() becomes iunlock(); new irele() does iput() for already unlocked inodes
e
s 00001/00001/00112
d D 4.6 82/02/27 14:54:14 wnj 9 8
c symbolic links
e
s 00004/00004/00109
d D 4.5 81/11/08 16:46:31 wnj 8 7
c plock/prele --> ilock/irele
e
s 00004/00025/00109
d D 4.4 81/03/09 01:46:37 wnj 7 6
c lint and a few minor fixed
e
s 00018/00015/00116
d D 4.3 81/03/09 00:31:53 wnj 6 5
c lint
e
s 00005/00005/00126
d D 4.2 80/11/09 22:59:05 bill 5 4
c minor lint
e
s 00000/00000/00131
d D 4.1 80/11/09 17:31:18 bill 4 3
c minor fixups to restart stuff; version 4.1 for distrib
e
s 00001/00001/00130
d D 3.3 80/06/07 02:44:16 bill 3 2
c %H%->%G%
e
s 00003/00001/00128
d D 3.2 80/04/12 17:30:25 bill 2 1
c save accounting information
e
s 00129/00000/00000
d D 3.1 80/04/09 16:02:50 bill 1 0
c date and time created 80/04/09 16:02:50 by bill
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%H%	*/
E 3
I 3
D 7
/*	%M%	%I%	%G%	*/
E 7
I 7
D 34
/*	%M%	%I%	%E%	*/
E 34
I 34
/*
D 37
 * Copyright (c) 1982 Regents of the University of California.
E 37
I 37
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 37
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 34
E 7
E 3

D 30
#include "../h/param.h"
#include "../h/systm.h"
D 17
#include "../h/acct.h"
E 17
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/inode.h"
#include "../h/proc.h"
#include "../h/seg.h"
I 14
#include "../h/fs.h"
I 15
#include "../h/uio.h"
I 16
#include "../h/vm.h"
I 25
#include "../h/kernel.h"
E 30
I 30
#include "param.h"
D 38
#include "systm.h"
E 38
#include "dir.h"
#include "user.h"
D 38
#include "inode.h"
E 38
#include "proc.h"
D 38
#include "seg.h"
#include "fs.h"
#include "uio.h"
#include "vm.h"
#include "kernel.h"
E 38
E 30
E 25
E 16
E 15
E 14

I 18
/*
 * Resource controls and accounting.
 */

E 18
I 16
getpriority()
{
	register struct a {
		int	which;
		int	who;
	} *uap = (struct a *)u.u_ap;
	register struct proc *p;
I 31
	int low = PRIO_MAX + 1;
E 31

D 31
	u.u_r.r_val1 = NZERO+20;
	u.u_error = ESRCH;
E 31
	switch (uap->which) {

	case PRIO_PROCESS:
		if (uap->who == 0)
			p = u.u_procp;
		else
			p = pfind(uap->who);
		if (p == 0)
D 36
			return;
E 36
I 36
			break;
E 36
D 26
		u.u_r.r_val1 = u.u_procp->p_nice;
E 26
I 26
D 31
		u.u_r.r_val1 = p->p_nice;
E 26
I 18
		u.u_error = 0;
E 31
I 31
		low = p->p_nice;
E 31
E 18
		break;

	case PRIO_PGRP:
		if (uap->who == 0)
			uap->who = u.u_procp->p_pgrp;
D 18
		for (p = proc; p < procNPROC; p++)
E 18
I 18
D 29
		for (p = proc; p < procNPROC; p++) {
			if (p->p_stat == NULL)
				continue;
E 29
I 29
		for (p = allproc; p != NULL; p = p->p_nxt) {
E 29
E 18
			if (p->p_pgrp == uap->who &&
D 31
			    p->p_nice < u.u_r.r_val1) {
				u.u_r.r_val1 = p->p_nice;
				u.u_error = 0;
			}
E 31
I 31
			    p->p_nice < low)
				low = p->p_nice;
E 31
I 18
		}
E 18
		break;

I 18
	case PRIO_USER:
		if (uap->who == 0)
			uap->who = u.u_uid;
D 29
		for (p = proc; p < procNPROC; p++) {
			if (p->p_stat == NULL)
				continue;
E 29
I 29
		for (p = allproc; p != NULL; p = p->p_nxt) {
E 29
			if (p->p_uid == uap->who &&
D 31
			    p->p_nice < u.u_r.r_val1) {
				u.u_r.r_val1 = p->p_nice;
				u.u_error = 0;
			}
E 31
I 31
			    p->p_nice < low)
				low = p->p_nice;
E 31
		}
		break;

E 18
	default:
		u.u_error = EINVAL;
D 31
		break;
E 31
I 31
		return;
E 31
	}
D 31
	u.u_r.r_val1 -= NZERO;
E 31
I 31
	if (low == PRIO_MAX + 1) {
		u.u_error = ESRCH;
		return;
	}
	u.u_r.r_val1 = low;
E 31
}

setpriority()
{
	register struct a {
		int	which;
		int	who;
		int	prio;
	} *uap = (struct a *)u.u_ap;
	register struct proc *p;
I 31
	int found = 0;
E 31

D 31
	u.u_error = ESRCH;
E 31
	switch (uap->which) {

	case PRIO_PROCESS:
D 18
		p = pfind(uap->who);
E 18
I 18
		if (uap->who == 0)
			p = u.u_procp;
		else
			p = pfind(uap->who);
E 18
		if (p == 0)
D 36
			return;
E 36
I 36
			break;
E 36
		donice(p, uap->prio);
I 31
		found++;
E 31
		break;

	case PRIO_PGRP:
I 18
		if (uap->who == 0)
			uap->who = u.u_procp->p_pgrp;
E 18
D 29
		for (p = proc; p < procNPROC; p++)
E 29
I 29
		for (p = allproc; p != NULL; p = p->p_nxt)
E 29
D 31
			if (p->p_pgrp == uap->who)
E 31
I 31
			if (p->p_pgrp == uap->who) {
E 31
				donice(p, uap->prio);
I 31
				found++;
			}
E 31
		break;

I 18
	case PRIO_USER:
		if (uap->who == 0)
			uap->who = u.u_uid;
D 29
		for (p = proc; p < procNPROC; p++)
E 29
I 29
		for (p = allproc; p != NULL; p = p->p_nxt)
E 29
D 31
			if (p->p_uid == uap->who)
E 31
I 31
			if (p->p_uid == uap->who) {
E 31
				donice(p, uap->prio);
I 31
				found++;
			}
E 31
		break;

E 18
	default:
		u.u_error = EINVAL;
D 31
		break;
E 31
I 31
		return;
E 31
	}
I 31
	if (found == 0)
		u.u_error = ESRCH;
E 31
}

donice(p, n)
	register struct proc *p;
	register int n;
{

	if (u.u_uid && u.u_ruid &&
	    u.u_uid != p->p_uid && u.u_ruid != p->p_uid) {
D 18
		u.u_error = EPERM;
E 18
I 18
D 33
		u.u_error = EACCES;
E 33
I 33
		u.u_error = EPERM;
E 33
E 18
		return;
	}
D 18
	n += p->p_nice;
E 18
I 18
D 31
	n += NZERO;
E 18
	if (n >= 2*NZERO)
		n = 2*NZERO - 1;
	if (n < 0)
		n = 0;
E 31
I 31
	if (n > PRIO_MAX)
		n = PRIO_MAX;
	if (n < PRIO_MIN)
		n = PRIO_MIN;
E 31
D 18
	if (n < p->p_nice && !suser())
E 18
I 18
	if (n < p->p_nice && !suser()) {
		u.u_error = EACCES;
E 18
		return;
I 18
	}
E 18
	p->p_nice = n;
	(void) setpri(p);
D 31
	if (u.u_error == ESRCH)
		u.u_error = 0;
E 31
}

D 17
setlimit()
E 17
I 17
setrlimit()
E 17
{
	register struct a {
		u_int	which;
		struct	rlimit *lim;
	} *uap = (struct a *)u.u_ap;
	struct rlimit alim;
	register struct rlimit *alimp;
I 32
D 35
	extern int maxdmap;
E 35
I 35
	extern unsigned maxdmap;
E 35
E 32

	if (uap->which >= RLIM_NLIMITS) {
		u.u_error = EINVAL;
		return;
	}
	alimp = &u.u_rlimit[uap->which];
D 23
	if (copyin((caddr_t)uap->lim, (caddr_t)&alim, sizeof (struct rlimit))) {
		u.u_error = EFAULT;
E 23
I 23
	u.u_error = copyin((caddr_t)uap->lim, (caddr_t)&alim,
		sizeof (struct rlimit));
	if (u.u_error)
E 23
		return;
D 23
	}
E 23
	if (alim.rlim_cur > alimp->rlim_max || alim.rlim_max > alimp->rlim_max)
		if (!suser())
			return;
	switch (uap->which) {

	case RLIMIT_DATA:
D 32
		if (alim.rlim_cur > ctob(MAXDSIZ))
			alim.rlim_cur = ctob(MAXDSIZ);
E 32
I 32
		if (alim.rlim_cur > maxdmap)
			alim.rlim_cur = maxdmap;
		if (alim.rlim_max > maxdmap)
			alim.rlim_max = maxdmap;
E 32
		break;

	case RLIMIT_STACK:
D 32
		if (alim.rlim_cur > ctob(MAXSSIZ))
			alim.rlim_cur = ctob(MAXSSIZ);
E 32
I 32
		if (alim.rlim_cur > maxdmap)
			alim.rlim_cur = maxdmap;
		if (alim.rlim_max > maxdmap)
			alim.rlim_max = maxdmap;
E 32
		break;
	}
	*alimp = alim;
	if (uap->which == RLIMIT_RSS)
		u.u_procp->p_maxrss = alim.rlim_cur/NBPG;
}

D 17
getlimit()
E 17
I 17
getrlimit()
E 17
{
	register struct a {
		u_int	which;
		struct	rlimit *rlp;
	} *uap = (struct a *)u.u_ap;

	if (uap->which >= RLIM_NLIMITS) {
		u.u_error = EINVAL;
		return;
	}
D 20
	if (copyout((caddr_t)&u.u_rlimit[uap->which], uap->rlp,
E 20
I 20
D 23
	if (copyout((caddr_t)&u.u_rlimit[uap->which], (caddr_t)uap->rlp,
E 20
	    sizeof (struct rlimit))) {
		u.u_error = EFAULT;
		return;
	}
E 23
I 23
	u.u_error = copyout((caddr_t)&u.u_rlimit[uap->which], (caddr_t)uap->rlp,
	    sizeof (struct rlimit));
E 23
}

getrusage()
{
	register struct a {
		int	who;
		struct	rusage *rusage;
	} *uap = (struct a *)u.u_ap;
	register struct rusage *rup;

	switch (uap->who) {

	case RUSAGE_SELF:
		rup = &u.u_ru;
		break;

	case RUSAGE_CHILDREN:
		rup = &u.u_cru;
		break;

	default:
		u.u_error = EINVAL;
		return;
	}
D 20
	if (copyout((caddr_t)rup, uap->rusage, sizeof (struct rusage))) {
E 20
I 20
D 23
	if (copyout((caddr_t)rup, (caddr_t)uap->rusage,
	    sizeof (struct rusage))) {
E 20
		u.u_error = EFAULT;
		return;
	}
E 23
I 23
	u.u_error = copyout((caddr_t)rup, (caddr_t)uap->rusage,
	    sizeof (struct rusage));
E 23
}

ruadd(ru, ru2)
	register struct rusage *ru, *ru2;
{
D 19
	register int *ip, *ip2;
E 19
I 19
D 21
	register u_int *ip, *ip2;
E 21
I 21
	register long *ip, *ip2;
E 21
E 19
	register int i;

	timevaladd(&ru->ru_utime, &ru2->ru_utime);
	timevaladd(&ru->ru_stime, &ru2->ru_stime);
	if (ru->ru_maxrss < ru2->ru_maxrss)
		ru->ru_maxrss = ru2->ru_maxrss;
	ip = &ru->ru_first; ip2 = &ru2->ru_first;
	for (i = &ru->ru_last - &ru->ru_first; i > 0; i--)
		*ip++ += *ip2++;
}
D 27

E 16
I 6
D 17
struct	inode *acctp;
I 14
struct	inode *savacctp;
E 14

I 14
long	acctlow	= 2;		/* stop accounting when < 2% data space left */
long	accthigh = 4;		/* resume when space risen to > 4% */

E 14
E 6
/*
 * Perform process accounting functions.
 */
D 6

E 6
sysacct()
E 17
I 17
#ifndef NOCOMPAT
onice()
E 17
{
D 17
	register struct inode *ip;
E 17
	register struct a {
D 17
		char	*fname;
E 17
I 17
		int	niceness;
E 17
D 18
	} *uap;
E 18
I 18
	} *uap = (struct a *)u.u_ap;
	register struct proc *p = u.u_procp;
E 18

D 18
	uap = (struct a *)u.u_ap;
D 17
	if (suser()) {
I 14
		if (savacctp) {
			acctp = savacctp;
			savacctp = NULL;
		}
E 14
		if (uap->fname==NULL) {
D 7
			if (acctp) {
				plock(acctp);
				iput(acctp);
E 7
I 7
			if (ip = acctp) {
D 8
				plock(ip);
E 8
I 8
D 11
				ilock(ip);
E 8
				iput(ip);
E 11
I 11
				irele(ip);
E 11
E 7
				acctp = NULL;
			}
			return;
		}
D 13
		if (acctp) {
			u.u_error = EBUSY;
			return;
		}
E 13
D 9
		ip = namei(uchar, 0);
E 9
I 9
		ip = namei(uchar, 0, 1);
E 9
		if(ip == NULL)
			return;
		if((ip->i_mode & IFMT) != IFREG) {
			u.u_error = EACCES;
			iput(ip);
			return;
		}
I 13
		if (acctp && (acctp->i_number != ip->i_number ||
		    acctp->i_dev != ip->i_dev))
			irele(acctp);
E 13
		acctp = ip;
D 8
		prele(ip);
E 8
I 8
D 10
		irele(ip);
E 10
I 10
		iunlock(ip);
E 10
E 8
	}
E 17
I 17
	donice(u.u_procp, uap->niceness);
E 18
I 18
	donice(p, (p->p_nice-NZERO)+uap->niceness);
E 18
E 17
}
I 17
D 18
#endif
E 18
E 17

I 18
#include "../h/times.h"

E 18
I 6
D 17
struct	acct acctbuf;
E 6
/*
 * On exit, write a record on the accounting file.
 */
acct()
E 17
I 17
otimes()
E 17
{
I 18
	register struct a {
		struct	tms *tmsb;
	} *uap = (struct a *)u.u_ap;
	struct tms atms;
E 18
D 17
	register i;
	register struct inode *ip;
	off_t siz;
I 6
	register struct acct *ap = &acctbuf;
E 17
E 6

I 14
D 17
	if (savacctp && savacctp->i_fs->fs_cstotal.cs_nbfree >
	    accthigh * savacctp->i_fs->fs_dsize / 100) {
		acctp = savacctp;
		savacctp = NULL;
		printf("Accounting resumed\n");
	}
E 14
	if ((ip=acctp)==NULL)
		return;
I 14
	if (acctp->i_fs->fs_cstotal.cs_nbfree <
	    acctlow * acctp->i_fs->fs_dsize / 100) {
		savacctp = acctp;
		acctp = NULL;
		printf("Accounting suspended\n");
		return;
	}
E 14
D 8
	plock(ip);
E 8
I 8
	ilock(ip);
E 8
D 6
	for (i=0; i<sizeof(acctbuf.ac_comm); i++)
		acctbuf.ac_comm[i] = u.u_comm[i];
D 5
	acctbuf.ac_utime = compress(u.u_vm.vm_utime);
	acctbuf.ac_stime = compress(u.u_vm.vm_stime);
	acctbuf.ac_etime = compress(time - u.u_start);
E 5
I 5
	acctbuf.ac_utime = compress((long)u.u_vm.vm_utime);
	acctbuf.ac_stime = compress((long)u.u_vm.vm_stime);
	acctbuf.ac_etime = compress((long)(time - u.u_start));
E 5
	acctbuf.ac_btime = u.u_start;
	acctbuf.ac_uid = u.u_ruid;
	acctbuf.ac_gid = u.u_rgid;
	acctbuf.ac_mem = 0;
E 6
I 6
	for (i=0; i<sizeof(ap->ac_comm); i++)
		ap->ac_comm[i] = u.u_comm[i];
D 16
	ap->ac_utime = compress((long)u.u_vm.vm_utime);
	ap->ac_stime = compress((long)u.u_vm.vm_stime);
E 16
I 16
	ap->ac_utime = compress((long)u.u_ru.ru_utime.tv_sec);
	ap->ac_stime = compress((long)u.u_ru.ru_stime.tv_sec);
E 16
	ap->ac_etime = compress((long)(time - u.u_start));
	ap->ac_btime = u.u_start;
	ap->ac_uid = u.u_ruid;
	ap->ac_gid = u.u_rgid;
	ap->ac_mem = 0;
E 6
D 2
	acctbuf.ac_io = 0;
E 2
I 2
D 16
	if (i = u.u_vm.vm_utime + u.u_vm.vm_stime)
D 6
		acctbuf.ac_mem = (u.u_vm.vm_ixrss + u.u_vm.vm_idsrss) / i;
D 5
	acctbuf.ac_io = compress(u.u_vm.vm_inblk + u.u_vm.vm_oublk);
E 5
I 5
	acctbuf.ac_io = compress((long)(u.u_vm.vm_inblk + u.u_vm.vm_oublk));
E 5
E 2
	acctbuf.ac_tty = u.u_ttyd;
	acctbuf.ac_flag = u.u_acflag;
E 6
I 6
		ap->ac_mem = (u.u_vm.vm_ixrss + u.u_vm.vm_idsrss) / i;
	ap->ac_io = compress((long)(u.u_vm.vm_inblk + u.u_vm.vm_oublk));
E 16
I 16
	if (i = u.u_ru.ru_utime.tv_sec + u.u_ru.ru_stime.tv_sec)
		ap->ac_mem =
		    (u.u_ru.ru_ixrss + u.u_ru.ru_idrss + u.u_ru.ru_isrss) / i;
	ap->ac_io = compress((long)(u.u_ru.ru_inblock + u.u_ru.ru_oublock));
E 16
D 13
	ap->ac_tty = u.u_ttyd;
E 13
I 13
	if (u.u_ttyp)
		ap->ac_tty = u.u_ttyd;
	else
		ap->ac_tty = NODEV;
E 13
	ap->ac_flag = u.u_acflag;
E 6
	siz = ip->i_size;
D 15
	u.u_offset = siz;
D 6
	u.u_base = (caddr_t)&acctbuf;
E 6
I 6
	u.u_base = (caddr_t)ap;
E 6
	u.u_count = sizeof(acctbuf);
	u.u_segflg = 1;
	u.u_error = 0;
	writei(ip);
	if(u.u_error)
E 15
I 15
	u.u_error =
	    rdwri(UIO_WRITE, ip, (caddr_t)ap, sizeof (acctbuf), siz,
		1, (int *)0);
	if (u.u_error)
E 15
		ip->i_size = siz;
D 8
	prele(ip);
E 8
I 8
D 10
	irele(ip);
E 10
I 10
	iunlock(ip);
E 17
I 17
D 18
	/* XXX */
E 18
I 18
	atms.tms_utime = scale60(&u.u_ru.ru_utime);
	atms.tms_stime = scale60(&u.u_ru.ru_stime);
	atms.tms_cutime = scale60(&u.u_cru.ru_utime);
	atms.tms_cstime = scale60(&u.u_cru.ru_stime);
D 20
	if (copyout((caddr_t)&atms, uap->tmsb, sizeof (atms))) {
E 20
I 20
D 23
	if (copyout((caddr_t)&atms, (caddr_t)uap->tmsb, sizeof (atms))) {
E 20
		u.u_error = EFAULT;
		return;
	}
E 23
I 23
	u.u_error = copyout((caddr_t)&atms, (caddr_t)uap->tmsb, sizeof (atms));
E 23
E 18
E 17
E 10
E 8
}

I 18
scale60(tvp)
	register struct timeval *tvp;
{

	return (tvp->tv_sec * 60 + tvp->tv_usec / 16667);
}

D 22
#include <vtimes.h>
E 22
I 22
#include "../h/vtimes.h"
E 22

E 18
D 17
/*
 * Produce a pseudo-floating point representation
 * with 3 bits base-8 exponent, 13 bits fraction.
 */
compress(t)
D 5
register time_t t;
E 5
I 5
register long t;
E 17
I 17
ovtimes()
E 17
E 5
{
I 18
	register struct a {
		struct	vtimes *par;
		struct	vtimes *chi;
	} *uap = (struct a *)u.u_ap;
	struct vtimes avt;
E 18
D 17
	register exp = 0, round = 0;
E 17

D 17
	while (t >= 8192) {
		exp++;
		round = t&04;
		t >>= 3;
	}
	if (round) {
		t++;
		if (t >= 8192) {
			t >>= 3;
			exp++;
		}
	}
	return((exp<<13) + t);
E 17
I 17
D 18
	/* XXX */
E 18
I 18
	if (uap->par) {
		getvtimes(&u.u_ru, &avt);
D 23
		if (copyout((caddr_t)&avt, (caddr_t)uap->par, sizeof (avt))) {
			u.u_error = EFAULT;
E 23
I 23
		u.u_error = copyout((caddr_t)&avt, (caddr_t)uap->par,
			sizeof (avt));
		if (u.u_error)
E 23
			return;
D 23
		}
E 23
	}
	if (uap->chi) {
		getvtimes(&u.u_cru, &avt);
D 23
		if (copyout((caddr_t)&avt, (caddr_t)uap->chi, sizeof (avt))) {
			u.u_error = EFAULT;
E 23
I 23
		u.u_error = copyout((caddr_t)&avt, (caddr_t)uap->chi,
			sizeof (avt));
		if (u.u_error)
E 23
			return;
D 23
		}
E 23
	}
E 18
E 17
I 14
}

I 18
getvtimes(aru, avt)
	register struct rusage *aru;
	register struct vtimes *avt;
{

	avt->vm_utime = scale60(&aru->ru_utime);
	avt->vm_stime = scale60(&aru->ru_stime);
	avt->vm_idsrss = ((aru->ru_idrss+aru->ru_isrss) / hz) * 60;
	avt->vm_ixrss = aru->ru_ixrss / hz * 60;
	avt->vm_maxrss = aru->ru_maxrss;
	avt->vm_majflt = aru->ru_majflt;
	avt->vm_minflt = aru->ru_minflt;
	avt->vm_nswap = aru->ru_nswap;
	avt->vm_inblk = aru->ru_inblock;
	avt->vm_oublk = aru->ru_oublock;
}

E 18
D 16
vtimes()
E 16
I 16
D 17
#ifndef NOCOMPAT
onice()
E 17
I 17
ovlimit()
E 17
E 16
{
D 17
	register struct a {
D 16
		struct	vtimes *par_vm;
		struct	vtimes *ch_vm;
	} *uap = (struct a *)u.u_ap;
E 16
I 16
		int	niceness;
	} *uap;
E 17
E 16

I 18
	u.u_error = EACCES;
E 18
D 16
	if (uap->par_vm == 0)
		goto onlych;
	if (copyout((caddr_t)&u.u_vm, (caddr_t)uap->par_vm,
	    sizeof(struct vtimes)) < 0)
		u.u_error = EFAULT;
onlych:
	if (uap->ch_vm == 0)
		return;
	if (copyout((caddr_t)&u.u_cvm, (caddr_t)uap->ch_vm,
	    sizeof(struct vtimes)) < 0)
		u.u_error = EFAULT;
E 16
I 16
D 17
	uap = (struct a *)u.u_ap;
	donice(u.u_procp, uap->niceness);
E 17
E 16
}
E 27
D 16

vmsadd(vp, wp)
	register struct vtimes *vp, *wp;
{

	vp->vm_utime += wp->vm_utime;
	vp->vm_stime += wp->vm_stime;
	vp->vm_nswap += wp->vm_nswap;
	vp->vm_idsrss += wp->vm_idsrss;
	vp->vm_ixrss += wp->vm_ixrss;
	if (vp->vm_maxrss < wp->vm_maxrss)
		vp->vm_maxrss = wp->vm_maxrss;
	vp->vm_majflt += wp->vm_majflt;
	vp->vm_minflt += wp->vm_minflt;
	vp->vm_inblk += wp->vm_inblk;
	vp->vm_oublk += wp->vm_oublk;
E 14
D 7
}

/*
 * lock user into core as much
 * as possible. swapping may still
 * occur if core grows.
 */
syslock()
{
	register struct proc *p;
	register struct a {
		int	flag;
	} *uap;

	uap = (struct a *)u.u_ap;
	if(suser()) {
		p = u.u_procp;
		p->p_flag &= ~SULOCK;
		if(uap->flag)
			p->p_flag |= SULOCK;
	}
E 7
}
E 16
I 16
D 17
#endif
E 17
E 16
E 1
