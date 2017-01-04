h36288
s 00001/00001/00257
d D 7.1 86/06/05 00:03:39 mckusick 28 27
c 4.3BSD release version
e
s 00001/00001/00257
d D 6.8 86/02/23 23:09:00 karels 27 26
c lint
e
s 00003/00003/00255
d D 6.7 86/02/20 15:25:16 karels 26 25
c use gid_t consistently
e
s 00001/00001/00257
d D 6.6 85/12/19 14:37:24 karels 25 24
c maintain p_uid with u.u_uid
e
s 00007/00001/00251
d D 6.5 85/06/08 14:37:01 mckusick 24 23
c Add copyright
e
s 00000/00001/00252
d D 6.4 85/03/19 20:48:44 mckusick 23 22
c eliminate extraneous include of conf.h
e
s 00023/00015/00230
d D 6.3 85/03/18 15:18:53 karels 22 21
c add gid_t for groups; copy u.u_groups to int array for copyin/out
e
s 00014/00014/00231
d D 6.2 84/08/29 20:19:56 bloom 21 20
c Change to includes.  no more ../h
e
s 00000/00000/00245
d D 6.1 83/07/29 06:33:30 sam 20 19
c 4.2 distribution
e
s 00000/00077/00245
d D 5.17 83/05/27 12:46:57 sam 19 18
c merge of bill's code plus lint (plus, of course, cleanup of bill's bugs)
e
s 00028/00002/00294
d D 5.16 83/03/31 13:46:40 sam 18 17
c add NOGROUP identifier; add groupmember function; tighten group 
c lookup loop to stop at first NOGROUP entry
e
s 00003/00007/00293
d D 5.15 83/02/20 14:52:57 sam 17 14
c fix incompatibility between access and setgid
e
s 00004/00008/00292
d R 5.15 83/02/16 18:19:05 sam 16 14
c fix access and problems with setgid and saccess
e
s 00006/00006/00294
d R 5.15 83/02/10 18:41:46 sam 15 14
c groups set members are shorts, not ints; hz no longer in systm.h
e
s 00006/00008/00294
d D 5.14 82/12/28 23:46:46 sam 14 13
c copyin & copyout now return EFAULT and all callers uniformly 
c return (or ignore) this value
e
s 00002/00001/00300
d D 5.13 82/12/17 11:44:18 sam 13 12
c sun merge
e
s 00006/00008/00295
d D 5.12 82/11/22 16:59:08 sam 12 11
c doing it wrong -- p_uid
e
s 00071/00002/00232
d D 5.11 82/11/13 22:50:14 sam 11 10
c merge of 4.1b and 4.1c
e
s 00000/00000/00234
d D 5.10 82/10/20 02:57:56 root 10 9
c lint
e
s 00002/00002/00232
d D 5.9 82/10/17 21:49:03 root 9 8
c more lint
e
s 00000/00001/00234
d D 5.8 82/10/10 15:07:54 root 8 7
c split header files over to vax directories
e
s 00000/00002/00235
d D 5.7 82/09/12 01:57:02 root 7 6
c drop printfs
e
s 00003/00002/00234
d D 5.6 82/09/06 22:49:04 root 6 5
c 
e
s 00001/00001/00235
d D 5.5 82/08/24 23:24:17 root 5 4
c nit bug
e
s 00057/00031/00179
d D 5.4 82/08/24 15:04:57 root 4 3
c new groups stuff
e
s 00144/00008/00066
d D 5.3 82/07/24 18:09:55 root 3 2
c merge with calder
e
s 00007/00000/00067
d D 5.2 82/07/22 13:22:57 kre 2 1
c disc quotas / mush
e
s 00067/00000/00000
d D 5.1 82/07/15 20:11:02 root 1 0
c date and time created 82/07/15 20:11:02 by root
e
u
U
f b 
t
T
I 1
D 24
/*	%M%	%I%	%E%	*/
E 24
I 24
/*
D 28
 * Copyright (c) 1982 Regents of the University of California.
E 28
I 28
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 28
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 24

/*
D 3
 * System calls related to protection
E 3
I 3
 * System calls related to processes and protection
E 3
 */

I 13
#include "../machine/reg.h"

E 13
I 3
D 4
/* NEED ALLOCATION AND PROTECTION MECHANISM FOR PROCESS GROUPS */

E 4
E 3
D 21
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
D 13
#include "../h/reg.h"
E 13
#include "../h/inode.h"
#include "../h/proc.h"
D 6
#include "../h/clock.h"
E 6
D 8
#include "../h/mtpr.h"
E 8
#include "../h/timeb.h"
#include "../h/times.h"
#include "../h/reboot.h"
#include "../h/fs.h"
#include "../h/conf.h"
#include "../h/buf.h"
#include "../h/mount.h"
I 2
#include "../h/quota.h"
E 21
I 21
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "inode.h"
#include "proc.h"
#include "timeb.h"
#include "times.h"
#include "reboot.h"
#include "fs.h"
D 23
#include "conf.h"
E 23
#include "buf.h"
#include "mount.h"
#include "quota.h"
E 21
E 2

I 3
getpid()
{

	u.u_r.r_val1 = u.u_procp->p_pid;
	u.u_r.r_val2 = u.u_procp->p_ppid;
}

getpgrp()
{
	register struct a {
		int	pid;
	} *uap = (struct a *)u.u_ap;
	register struct proc *p;

	if (uap->pid == 0)
		uap->pid = u.u_procp->p_pid;
	p = pfind(uap->pid);
	if (p == 0) {
		u.u_error = ESRCH;
		return;
	}
	u.u_r.r_val1 = p->p_pgrp;
}

E 3
getuid()
{

	u.u_r.r_val1 = u.u_ruid;
	u.u_r.r_val2 = u.u_uid;
}

I 3
getgid()
{

	u.u_r.r_val1 = u.u_rgid;
	u.u_r.r_val2 = u.u_gid;
}

D 4
getgrp()
E 4
I 4
getgroups()
E 4
{
	register struct	a {
I 4
D 9
		int	gidsetsize;
E 9
I 9
		u_int	gidsetsize;
E 9
E 4
		int	*gidset;
	} *uap = (struct a *)u.u_ap;
I 4
D 22
	register int *gp;
E 22
I 22
	register gid_t *gp;
	register int *lp;
	int groups[NGROUPS];
E 22
E 4

D 4
	if (copyout((caddr_t)u.u_grps, (caddr_t)uap->gidset,
	    sizeof (u.u_grps))) {
E 4
I 4
	for (gp = &u.u_groups[NGROUPS]; gp > u.u_groups; gp--)
D 22
		if (gp[-1] >= 0)
E 22
I 22
		if (gp[-1] != NOGROUP)
E 22
			break;
	if (uap->gidsetsize < gp - u.u_groups) {
		u.u_error = EINVAL;
		return;
	}
	uap->gidsetsize = gp - u.u_groups;
D 14
	if (copyout((caddr_t)u.u_groups, (caddr_t)uap->gidset,
	    uap->gidsetsize * sizeof (u.u_groups[0]))) {
E 4
		u.u_error = EFAULT;
E 14
I 14
D 22
	u.u_error = copyout((caddr_t)u.u_groups, (caddr_t)uap->gidset,
	    uap->gidsetsize * sizeof (u.u_groups[0]));
E 22
I 22
	for (lp = groups, gp = u.u_groups; lp < &groups[uap->gidsetsize]; )
		*lp++ = *gp++;
	u.u_error = copyout((caddr_t)groups, (caddr_t)uap->gidset,
	    uap->gidsetsize * sizeof (groups[0]));
E 22
	if (u.u_error)
E 14
		return;
D 14
	}
E 14
I 4
	u.u_r.r_val1 = uap->gidsetsize;
E 4
}

setpgrp()
{
	register struct proc *p;
	register struct a {
		int	pid;
		int	pgrp;
	} *uap = (struct a *)u.u_ap;

	if (uap->pid == 0)
		uap->pid = u.u_procp->p_pid;
	p = pfind(uap->pid);
	if (p == 0) {
		u.u_error = ESRCH;
		return;
	}
I 4
/* need better control mechanisms for process groups */
E 4
	if (p->p_uid != u.u_uid && u.u_uid && !inferior(p)) {
		u.u_error = EPERM;
		return;
	}
	p->p_pgrp = uap->pgrp;
}

E 3
D 11
setuid()
E 11
I 11
setreuid()
E 11
{
I 11
	struct a {
		int	ruid;
		int	euid;
	} *uap;
	register int ruid, euid;

	uap = (struct a *)u.u_ap;
	ruid = uap->ruid;
	if (ruid == -1)
		ruid = u.u_ruid;
	if (u.u_ruid != ruid && u.u_uid != ruid && !suser())
		return;
	euid = uap->euid;
	if (euid == -1)
		euid = u.u_uid;
	if (u.u_ruid != euid && u.u_uid != euid && !suser())
		return;
	/*
	 * Everything's okay, do it.
	 */
D 12
	if (ruid != u.u_ruid) {
E 12
#ifdef QUOTA
D 12
		if (u.u_quota->q_uid != ruid) {
			qclean();
			qstart(getquota(ruid, 0, 0));
		}
#endif
		u.u_procp->p_uid = ruid;
		u.u_ruid = ruid;
E 12
I 12
	if (u.u_quota->q_uid != ruid) {
		qclean();
D 27
		qstart(getquota(ruid, 0, 0));
E 27
I 27
		qstart(getquota((uid_t)ruid, 0, 0));
E 27
E 12
	}
I 12
#endif
D 25
	u.u_procp->p_uid = ruid;
E 25
I 25
	u.u_procp->p_uid = euid;
E 25
	u.u_ruid = ruid;
E 12
	u.u_uid = euid;
}

D 19
#ifndef NOCOMPAT
osetuid()
{
E 11
	register uid;
	register struct a {
		int	uid;
	} *uap;

	uap = (struct a *)u.u_ap;
	uid = uap->uid;
	if (u.u_ruid == uid || u.u_uid == uid || suser()) {
I 2
#ifdef QUOTA
		if (u.u_quota->q_uid != uid) {
			qclean();
			qstart(getquota(uid, 0, 0));
		}
#endif
E 2
		u.u_uid = uid;
		u.u_procp->p_uid = uid;
		u.u_ruid = uid;
	}
}
I 11
#endif
E 11

E 19
D 3
getgid()
{

	u.u_r.r_val1 = u.u_rgid;
	u.u_r.r_val2 = u.u_gid;
}

E 3
D 11
setgid()
E 11
I 11
setregid()
{
	register struct a {
		int	rgid;
		int	egid;
	} *uap;
	register int rgid, egid;

	uap = (struct a *)u.u_ap;
	rgid = uap->rgid;
	if (rgid == -1)
		rgid = u.u_rgid;
	if (u.u_rgid != rgid && u.u_gid != rgid && !suser())
		return;
	egid = uap->egid;
	if (egid == -1)
		egid = u.u_gid;
	if (u.u_rgid != egid && u.u_gid != egid && !suser())
		return;
	if (u.u_rgid != rgid) {
		leavegroup(u.u_rgid);
D 17
		(void) entergroup(u.u_rgid);
E 17
I 17
D 26
		(void) entergroup(rgid);
E 26
I 26
		(void) entergroup((gid_t)rgid);
E 26
E 17
		u.u_rgid = rgid;
	}
D 17
	if (u.u_gid != egid) {
		leavegroup(u.u_gid);
		(void) entergroup(egid);
		u.u_gid = egid;
	}
E 17
I 17
	u.u_gid = egid;
E 17
}

D 19
#ifndef NOCOMPAT
osetgid()
E 11
{
	register gid;
	register struct a {
		int	gid;
	} *uap;

	uap = (struct a *)u.u_ap;
	gid = uap->gid;
	if (u.u_rgid == gid || u.u_gid == gid || suser()) {
I 4
D 17
		leavegroup(u.u_gid); leavegroup(u.u_rgid);
E 17
I 17
		leavegroup(u.u_rgid);
E 17
		(void) entergroup(gid);
E 4
		u.u_gid = gid;
		u.u_rgid = gid;
	}
}
I 3

E 19
D 4
setgrp()
E 4
I 4
setgroups()
E 4
{
	register struct	a {
I 4
D 9
		int	gidsetsize;
E 9
I 9
		u_int	gidsetsize;
E 9
E 4
		int	*gidset;
	} *uap = (struct a *)u.u_ap;
I 4
D 22
	register int *gp;
E 22
I 22
	register gid_t *gp;
	register int *lp;
	int groups[NGROUPS];
E 22
E 4

D 6
	if (suser())
E 6
I 6
D 7
printf("gidsetsize %d, gidset %x\n", uap->gidsetsize, uap->gidset);
E 7
	if (!suser())
E 6
		return;
D 4
	if (copyin((caddr_t)uap->gidset, (caddr_t)u.u_grps,
	    sizeof (u.u_grps))) {
		u.u_error = EFAULT;
E 4
I 4
	if (uap->gidsetsize > sizeof (u.u_groups) / sizeof (u.u_groups[0])) {
		u.u_error = EINVAL;
E 4
		return;
	}
D 4
}

/* BEGIN DEFUNCT */
osetgrp()
{
	register struct	a {
		int *ngrps;
		int *ogrps;
	} *uap = (struct a *)u.u_ap;
	int thegroups[NGRPS/(sizeof(int)*8)];

	if (uap->ogrps && copyout((caddr_t)u.u_grps, (caddr_t)uap->ogrps,
	    sizeof (thegroups))) {
E 4
I 4
D 14
	if (copyin((caddr_t)uap->gidset, (caddr_t)u.u_groups,
	    uap->gidsetsize * sizeof (u.u_groups[0]))) {
E 4
		u.u_error = EFAULT;
E 14
I 14
D 22
	u.u_error = copyin((caddr_t)uap->gidset, (caddr_t)u.u_groups,
	    uap->gidsetsize * sizeof (u.u_groups[0]));
E 22
I 22
	u.u_error = copyin((caddr_t)uap->gidset, (caddr_t)groups,
	    uap->gidsetsize * sizeof (groups[0]));
E 22
	if (u.u_error)
E 14
		return;
D 14
	}
E 14
I 6
D 7
printf("copied in %d %d ... \n", u.u_groups[0], u.u_groups[1]);
E 7
E 6
D 4
	if (uap->ngrps == 0)
		return;
	if (copyin((caddr_t)uap->ngrps, (caddr_t)thegroups,
	    sizeof (thegroups))) {
		u.u_error = EFAULT;
		return;
	}
	if (suser())
		bcopy((caddr_t)thegroups, (caddr_t)u.u_grps, sizeof (u.u_grps));
E 4
I 4
D 22
	for (gp = &u.u_groups[uap->gidsetsize]; gp < &u.u_groups[NGROUPS]; gp++)
E 22
I 22
	for (lp = groups, gp = u.u_groups; lp < &groups[uap->gidsetsize]; )
		*gp++ = *lp++;
	for ( ; gp < &u.u_groups[NGROUPS]; gp++)
E 22
D 18
		*gp = -1;
E 18
I 18
		*gp = NOGROUP;
E 18
E 4
}
D 19

/*
 * Pid of zero implies current process.
 * Pgrp -1 is getpgrp system call returning
 * current process group.
 */
osetpgrp()
{
	register struct proc *p;
	register struct a {
		int	pid;
		int	pgrp;
	} *uap;

	uap = (struct a *)u.u_ap;
	if (uap->pid == 0)
		p = u.u_procp;
	else {
		p = pfind(uap->pid);
		if (p == 0) {
			u.u_error = ESRCH;
			return;
		}
	}
	if (uap->pgrp <= 0) {
		u.u_r.r_val1 = p->p_pgrp;
		return;
	}
	if (p->p_uid != u.u_uid && u.u_uid && !inferior(p)) {
		u.u_error = EPERM;
		return;
	}
	p->p_pgrp = uap->pgrp;
}
/* END DEFUNCT */
E 19
I 4

I 18
/*
 * Group utility functions.
 */

/*
 * Delete gid from the group set.
 */
E 18
leavegroup(gid)
D 26
	int gid;
E 26
I 26
	gid_t gid;
E 26
{
D 22
	register int *gp;
E 22
I 22
	register gid_t *gp;
E 22

	for (gp = u.u_groups; gp < &u.u_groups[NGROUPS]; gp++)
		if (*gp == gid)
			goto found;
	return;
found:
	for (; gp < &u.u_groups[NGROUPS-1]; gp++)
		*gp = *(gp+1);
D 5
	*gp = 0;
E 5
I 5
D 18
	*gp = -1;
E 18
I 18
	*gp = NOGROUP;
E 18
E 5
}

I 18
/*
 * Add gid to the group set.
 */
E 18
entergroup(gid)
D 26
	int gid;
E 26
I 26
	gid_t gid;
E 26
{
D 22
	register int *gp;
E 22
I 22
	register gid_t *gp;
E 22

D 22
	for (gp = u.u_groups; gp < &u.u_groups[NGROUPS]; gp++)
E 22
I 22
	for (gp = u.u_groups; gp < &u.u_groups[NGROUPS]; gp++) {
E 22
		if (*gp == gid)
			return (0);
D 22
	for (gp = u.u_groups; gp < &u.u_groups[NGROUPS]; gp++)
		if (*gp < 0) {
E 22
I 22
		if (*gp == NOGROUP) {
E 22
			*gp = gid;
			return (0);
		}
I 22
	}
E 22
	return (-1);
I 18
}

/*
 * Check if gid is a member of the group set.
 */
groupmember(gid)
D 22
	int gid;
E 22
I 22
	gid_t gid;
E 22
{
D 22
	register int *gp;
E 22
I 22
	register gid_t *gp;
E 22

	if (u.u_gid == gid)
		return (1);
	for (gp = u.u_groups; gp < &u.u_groups[NGROUPS] && *gp != NOGROUP; gp++)
		if (*gp == gid)
			return (1);
	return (0);
E 18
}
E 4
E 3
E 1
