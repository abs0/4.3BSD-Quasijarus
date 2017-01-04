h62568
s 00010/00005/00359
d D 7.4 88/06/29 17:20:15 bostic 14 13
c install approved copyright notice
e
s 00008/00002/00356
d D 7.3 88/05/20 12:29:39 bostic 13 12
c add Berkeley specific header
e
s 00002/00002/00356
d D 7.2 87/06/26 19:58:02 mckusick 12 11
c m_bufp => m_fs
e
s 00001/00001/00357
d D 7.1 86/06/05 00:06:06 mckusick 11 10
c 4.3BSD release version
e
s 00004/00003/00354
d D 6.7 86/02/23 23:09:52 karels 10 9
c lint
e
s 00007/00001/00350
d D 6.6 85/06/08 14:40:27 mckusick 9 8
c Add copyright
e
s 00015/00015/00336
d D 6.5 85/05/24 15:22:32 mckusick 8 7
c return EINVAL if quotas are not compiled;
c return ESRCH in all cases where system does not have a quota for the user;
c return ENODEV instead of EINVAL if the device is not a mounted file system
e
s 00010/00010/00341
d D 6.4 84/08/29 20:21:13 bloom 7 6
c Change to includes.  no more ../h
e
s 00002/00004/00349
d D 6.3 84/07/08 16:19:09 mckusick 6 5
c rework `namei' interface to eliminate global variables
e
s 00001/00001/00352
d D 6.2 84/06/20 15:57:17 kre 5 4
c don't set quotas on free inodes (in setdlim())
e
s 00000/00000/00353
d D 6.1 83/07/29 06:35:26 sam 4 3
c 4.2 distribution
e
s 00000/00003/00353
d D 4.3 83/06/16 15:44:15 sam 3 2
c sys calls are noops w/o quotas
e
s 00262/00195/00094
d D 4.2 83/05/21 23:19:23 sam 2 1
c cleanup
e
s 00289/00000/00000
d D 4.1 83/05/21 15:50:32 sam 1 0
c date and time created 83/05/21 15:50:32 by sam
e
u
U
t
T
I 1
D 9
/*	%M%	%I%	%E%	*/
E 9
I 9
/*
D 11
 * Copyright (c) 1982 Regents of the University of California.
E 11
I 11
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 11
D 13
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 13
I 13
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 14
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 14
I 14
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 14
E 13
 *
 *	%W% (Berkeley) %G%
 */
E 9

/*
D 2
 * Quotas: system calls.
E 2
I 2
 * MELBOURNE QUOTAS
 *
 * System calls.
E 2
 */
D 7
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/proc.h"
#include "../h/inode.h"
#include "../h/quota.h"
#include "../h/mount.h"
#include "../h/fs.h"
#include "../h/uio.h"
E 7
I 7
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "proc.h"
#include "inode.h"
#include "quota.h"
#include "mount.h"
#include "fs.h"
#include "uio.h"
E 7
D 6
#include "../h/nami.h"
E 6

/*
 * The sys call that tells the system about a quota file.
 */
setquota()
{
	register struct a {
		char	*fblk;
		char	*fname;
	} *uap = (struct a *)u.u_ap;
	register struct mount *mp;
	dev_t dev;

D 8
#ifdef QUOTA
E 8
I 8
#ifndef QUOTA
	u.u_error = EINVAL;
	return;
#else
E 8
D 6
	u.u_error = getmdev(&dev);
E 6
I 6
	u.u_error = getmdev(&dev, uap->fblk);
E 6
	if (u.u_error)
		return;
D 6
	u.u_dirp = (caddr_t) uap->fname;
E 6
D 2

E 2
	for (mp = mount; mp < &mount[NMOUNT]; mp++)
D 12
		if (mp->m_bufp && mp->m_dev == dev) {
E 12
I 12
		if (mp->m_fs && mp->m_dev == dev) {
E 12
			if (uap->fname == NULL)
				closedq(mp);
			else
D 6
				opendq(mp);
E 6
I 6
				opendq(mp, (caddr_t)uap->fname);
E 6
			return;
		}
#endif
D 3
	u.u_error = EINVAL;
E 3
}

/*
 * Sys call to allow users to find out
 * their current position wrt quota's
 * and to allow super users to alter it.
 */
qquota()
{
	register struct a {
		int	cmd;
		int	uid;
		int	arg;
		caddr_t	addr;
	} *uap = (struct a *)u.u_ap;
D 8
#ifdef QUOTA
E 8
	register struct quota *q;
D 2
	register uid;
	register struct dquot *dq;
	struct dqblk newlim;
	dlim_t usage[2];
	int f;
E 2

I 8
#ifndef QUOTA
	u.u_error = EINVAL;
	return;
#else
E 8
D 2
	if ((uid = uap->uid) < 0)
		uid = u.u_ruid;
	else if (uid != u.u_ruid && uid != u.u_quota->q_uid && !suser())
E 2
I 2
	if (uap->uid < 0)
		uap->uid = u.u_ruid;
	if (uap->uid != u.u_ruid && uap->uid != u.u_quota->q_uid && !suser())
E 2
		return;
D 2

	f = 0;
	switch (uap->cmd) {
	case Q_SYNC:
	case Q_SETUID:		/* the getquota must be done, but differently */
		break;

	case Q_DOWARN:
		f = 1;
		/* FALL THROUGH */
	default:
		q = getquota(uid, f, 0);
		if (q == NOQUOT) {		/* only where f == 1 */
E 2
I 2
	if (uap->cmd != Q_SYNC && uap->cmd != Q_SETUID) {
D 10
		q = getquota(uap->uid, uap->cmd == Q_DOWARN, 0);
E 10
I 10
		q = getquota((uid_t)uap->uid, uap->cmd == Q_DOWARN, 0);
E 10
		if (q == NOQUOTA) {
E 2
			u.u_error = ESRCH;
			return;
		}
D 2
		if (u.u_error) {
			delquota(q);
			return;
		}
		break;
E 2
I 2
		if (u.u_error)
			goto bad;
E 2
	}
D 2

E 2
	switch (uap->cmd) {

D 2
	default:
		u.u_error = EINVAL;
		break;

E 2
	case Q_SETDLIM:
D 2
	{
		register struct inode *ip;
		register struct dquot *odq;

		if (!suser())
			break;
		f = getfsx(uap->arg);
		if (f < 0 || f >= NMOUNT) {
			u.u_error = EINVAL;
			break;
		}
		if ((dq = dqp(q, uap->arg)) == NODQUOT) {
			if ((dq = dqalloc(q->q_uid, uap->arg)) == NODQUOT)
				break;
			dq->dq_cnt++;
			dq->dq_own = q;
			q->q_dq[f] = dq;
			odq = NODQUOT;
		} else
			odq = dq;

		if (dq->dq_uid != q->q_uid)
			panic("SETDLIM bad uid");
		while (dq->dq_flg & DQ_LOCK) {
printf("qquota: SETDLIM, locked, sleeping...\n");
			dq->dq_flg |= DQ_WANT;
			sleep((caddr_t)dq, PINOD+1);
		}

		u.u_error = copyin(uap->addr, (caddr_t)&newlim,
			sizeof(struct dqblk));
		if (u.u_error) {
			if (dq != odq) {
				q->q_dq[f] = odq;
				dq->dq_cnt--;
			}
			dqrele(dq);
			break;
		}
		bcopy((caddr_t)&newlim, (caddr_t)&dq->dq_dqb,
		    sizeof(struct dqblk));
		
		dq->dq_flg |= DQ_MOD;

		dqrele(dq);
		if (dq->dq_iq == 0 && dq->dq_quot == 0) {
			q->q_dq[f] = NODQUOT;
			dq->dq_own = NOQUOT;
			dqrele(dq);
			if (dq->dq_cnt == 0)	/* no files open using quota */
				break;		/* this is just for speed */
			dq = NODQUOT;
		}
		if (dq != odq) {
			for (ip = inode; ip < inodeNINODE; ip++)
				if (ip->i_uid == q->q_uid &&
				    ip->i_dev == uap->arg) {
					if (dq == NODQUOT)
						dqrele(ip->i_dquot);
					else
						dq->dq_cnt++;
					ip->i_dquot = dq;
				}
		}
E 2
I 2
		u.u_error = setdlim(q, (dev_t)uap->arg, uap->addr);
E 2
		break;
D 2
	}
E 2

	case Q_GETDLIM:
D 2
		if ((dq = dqp(q, uap->arg)) == NODQUOT) {
			u.u_r.r_val1 = 1;
			break;
		}
		u.u_error = copyout((caddr_t)&dq->dq_dqb, uap->addr,
		    sizeof(struct dqblk));
		dqrele(dq);
E 2
I 2
		u.u_error = getdlim(q, (dev_t)uap->arg, uap->addr);
E 2
		break;

	case Q_SETDUSE:
D 2
		if (!suser())
			break;
		if ((dq = dqp(q, uap->arg)) == NODQUOT) {
			u.u_r.r_val1 = 1;
			break;
		}
		while (dq->dq_flg & DQ_LOCK) {
printf("qquota: SETDUSE: locked, sleeping...\n");
			dq->dq_flg |= DQ_WANT;
			sleep((caddr_t)dq, PINOD+1);
		}
		if (dq->dq_uid != q->q_uid)
			panic("SETDUSE bad uid");
		u.u_error = copyin(uap->addr, (caddr_t)usage,
			2*sizeof(dlim_t));
		if (u.u_error) {
			dqrele(dq);
			break;
		}
		dq->dq_inod = usage[0];
		dq->dq_blks = usage[1];
		if (dq->dq_inod < dq->dq_iq)
			dq->dq_iwarn = MAX_IQ_WARN;
		if (dq->dq_blks < dq->dq_quot)
			dq->dq_dwarn = MAX_DQ_WARN;
		dq->dq_flg &= ~(DQ_INODS|DQ_BLKS);
		dq->dq_flg |= DQ_MOD;
		dqrele(dq);
E 2
I 2
		u.u_error = setduse(q, (dev_t)uap->arg, uap->addr);
E 2
		break;

	case Q_SETWARN:
D 2
		if (!suser())
			break;
		if ((dq = dqp(q, uap->arg)) == NODQUOT) {
			u.u_r.r_val1 = 1;
			break;
		}
		while (dq->dq_flg & DQ_LOCK) {
			dq->dq_flg |= DQ_WANT;
			sleep((caddr_t)dq, PINOD+1);
		}
		if (dq->dq_uid != q->q_uid)
			panic("SETWARN bad uid");
		u.u_error = copyin(uap->addr, (caddr_t)usage,
			2*sizeof(dlim_t));
		if (u.u_error) {
			dqrele(dq);
			break;
		}
		dq->dq_iwarn = usage[0];
		dq->dq_dwarn = usage[1];
		dq->dq_flg &= ~(DQ_INODS|DQ_BLKS);
		dq->dq_flg |= DQ_MOD;
		dqrele(dq);
E 2
I 2
		u.u_error = setwarn(q, (dev_t)uap->arg, uap->addr);
E 2
		break;

	case Q_DOWARN:
D 2
		if (!suser() || u.u_ttyp == NULL)
			break;
		if (uap->arg != NODEV) {
			if ((dq = dqp(q, uap->arg)) != NODQUOT) {
				qwarn(dq);
				dqrele(dq);
			}
		} else {
			register struct dquot **dqq;

			for (dqq = q->q_dq; dqq < &q->q_dq[NMOUNT]; dqq++)
				if ((dq = *dqq) != NODQUOT && dq != LOSTDQUOT)
					qwarn(dq);
		}
E 2
I 2
		u.u_error = dowarn(q, (dev_t)uap->arg);
E 2
		break;
	
	case Q_SYNC:
D 2
	    {
		register struct mount *mp;
		register i;

		if (!suser())
			return;
		for (mp = mount, i = 0; mp < &mount[NMOUNT]; mp++, i++)
			if (mp->m_bufp && mp->m_qinod &&
			    (uap->arg == NODEV || uap->arg == mp->m_dev)) {
				for (q = quota; q < quotaNQUOTA; q++)
					if (q->q_cnt) {
						q->q_cnt++;
						putdq(mp, q->q_dq[i], 0);
						delquota(q);
					}
			}
E 2
I 2
		u.u_error = qsync((dev_t)uap->arg);
E 2
		return;
D 2
	    }
E 2

	case Q_SETUID:
D 2
		if (uid == u.u_quota->q_uid)
			return;
		if (!suser())
			return;
		q = getquota(uid, 0, uap->arg ? Q_NDQ : 0);
		qclean();
		qstart(q);
		return;				/* no delquota of q */
E 2
I 2
D 10
		u.u_error = qsetuid(uap->uid, uap->arg);
E 10
I 10
		u.u_error = qsetuid((uid_t)uap->uid, uap->arg);
E 10
		return;
E 2

I 2
	default:
		u.u_error = EINVAL;
		break;
E 2
	}
I 2
bad:
E 2
	delquota(q);
D 3
#else
	u.u_error = EINVAL;
E 3
#endif
}
I 2

#ifdef QUOTA
/*
 * Q_SETDLIM - assign an entire dqblk structure.
 */
setdlim(q, dev, addr)
	register struct quota *q;
	dev_t dev;
	caddr_t addr;
{
	register struct inode *ip;
	register struct dquot *dq, *odq;
	struct dqblk newlim;
	int index, error = 0;

	if (!suser())
		return (u.u_error);			/* XXX */
	index = getfsx(dev);
	if (index < 0 || index >= NMOUNT)
D 8
		return (EINVAL);
E 8
I 8
		return (ENODEV);
E 8
	dq = dqp(q, dev);
	if (dq == NODQUOT) {
		dq = dqalloc(q->q_uid, dev);
		if (dq == NODQUOT)
			return (error);
		dq->dq_cnt++;
		dq->dq_own = q;
		q->q_dq[index] = dq;
		odq = NODQUOT;
	} else
		odq = dq;

	if (dq->dq_uid != q->q_uid)
		panic("setdlim");
	while (dq->dq_flags & DQ_LOCK) {
		dq->dq_flags |= DQ_WANT;
		sleep((caddr_t)dq, PINOD+1);
	}
	error = copyin(addr, (caddr_t)&newlim, sizeof (struct dqblk));
	if (error) {
		if (dq != odq) {
			q->q_dq[index] = odq;
			dq->dq_cnt--;
		}
		dqrele(dq);
		return (error);
	}
	dq->dq_dqb = newlim;
	dq->dq_flags |= DQ_MOD;
	dqrele(dq);
	if (dq->dq_isoftlimit == 0 && dq->dq_bsoftlimit == 0) {
		q->q_dq[index] = NODQUOT;
		dq->dq_own = NOQUOTA;
		dqrele(dq);
		if (dq->dq_cnt == 0)	/* no files open using quota */
			return (error);
		dq = NODQUOT;
	}
	if (dq == odq)
		return (error);
	for (ip = inode; ip < inodeNINODE; ip++)
D 5
		if (ip->i_uid == q->q_uid && ip->i_dev == dev) {
E 5
I 5
		if (ip->i_uid == q->q_uid && ip->i_dev == dev && ip->i_mode) {
E 5
			if (dq == NODQUOT)
				dqrele(ip->i_dquot);
			else
				dq->dq_cnt++;
			ip->i_dquot = dq;
		}
	return (error);
}

/*
 * Q_GETDLIM - return current values in a dqblk structure.
 */
getdlim(q, dev, addr)
	struct quota *q;
	dev_t dev;
	caddr_t addr;
{
	register struct dquot *dq;
	int error;

	dq = dqp(q, dev);
D 8
	if (dq == NODQUOT) {
		u.u_r.r_val1 = 1;
		return (0);
	}
E 8
I 8
	if (dq == NODQUOT)
		return (ESRCH);
E 8
	error = copyout((caddr_t)&dq->dq_dqb, addr, sizeof (struct dqblk));
	dqrele(dq);
	return (error);
}

/*
 * Q_SETDUSE - set current inode and disc block totals.
 * Resets warnings and associated flags.
 */
setduse(q, dev, addr)
	register struct quota *q;
	dev_t dev;
	caddr_t addr;
{
	register struct dquot *dq;
	struct dqusage usage;
	int error = 0;

	if (!suser())
		return (u.u_error);
	dq = dqp(q, dev);
D 8
	if (dq == NODQUOT) {
		u.u_r.r_val1 = 1;
		return (error);
	}
E 8
I 8
	if (dq == NODQUOT)
		return (ESRCH);
E 8
	while (dq->dq_flags & DQ_LOCK) {
		dq->dq_flags |= DQ_WANT;
		sleep((caddr_t)dq, PINOD+1);
	}
	if (dq->dq_uid != q->q_uid)
		panic("setduse");
	error = copyin(addr, (caddr_t)&usage, sizeof (usage));
	if (error == 0) {
		dq->dq_curinodes = usage.du_curinodes;
		dq->dq_curblocks = usage.du_curblocks;
		if (dq->dq_curinodes < dq->dq_isoftlimit)
			dq->dq_iwarn = MAX_IQ_WARN;
		if (dq->dq_curblocks < dq->dq_bsoftlimit)
			dq->dq_bwarn = MAX_DQ_WARN;
		dq->dq_flags &= ~(DQ_INODS | DQ_BLKS);
		dq->dq_flags |= DQ_MOD;
	}
	dqrele(dq);
	return (error);
}

/*
 * Q_SETWARN - set warning counters.
 */
setwarn(q, dev, addr)
	register struct quota *q;
	dev_t dev;
	caddr_t addr;
{
	register struct dquot *dq;
	int error = 0;
	struct dqwarn warn;

	if (!suser())
		return (u.u_error);			/* XXX */
	dq = dqp(q, dev);
D 8
	if (dq == NODQUOT) {
		u.u_r.r_val1 = 1;
		return (error);
	}
E 8
I 8
	if (dq == NODQUOT)
		return (ESRCH);
E 8
	while (dq->dq_flags & DQ_LOCK) {
		dq->dq_flags |= DQ_WANT;
		sleep((caddr_t)dq, PINOD+1);
	}
	if (dq->dq_uid != q->q_uid)
		panic("setwarn");
	error = copyin(addr, (caddr_t)&warn, sizeof (warn));
	if (error == 0) {
		dq->dq_iwarn = warn.dw_iwarn;
		dq->dq_bwarn = warn.dw_bwarn;
		dq->dq_flags &= ~(DQ_INODS | DQ_BLKS);
		dq->dq_flags |= DQ_MOD;
	}
	dqrele(dq);
	return (error);
}

/*
 * Q_DOWARN - force warning(s) to user(s).
 */
dowarn(q, dev)
	register struct quota *q;
	dev_t dev;
{
	register struct dquot *dq, **dqq;

	if (!suser() || u.u_ttyp == NULL)
		return (u.u_error);			/* XXX */
	if (dev != NODEV) {
		dq = dqp(q, dev);
		if (dq != NODQUOT) {
			qwarn(dq);
			dqrele(dq);
		}
		return (0);
	}
	for (dqq = q->q_dq; dqq < &q->q_dq[NMOUNT]; dqq++) {
		dq = *dqq;
		if (dq != NODQUOT && dq != LOSTDQUOT)
			qwarn(dq);
	}
	return (0);
}

/*
 * Q_SYNC - sync quota files to disc.
 */
qsync(dev)
	dev_t dev;
{
	register struct quota *q;
	register struct mount *mp;
	register index;

	if (!suser())
		return (u.u_error);			/* XXX */
	for (mp = mount, index = 0; mp < &mount[NMOUNT]; mp++, index++)
D 12
		if (mp->m_bufp && mp->m_qinod &&
E 12
I 12
		if (mp->m_fs && mp->m_qinod &&
E 12
		    (dev == NODEV || dev == mp->m_dev)) {
			for (q = quota; q < quotaNQUOTA; q++)
				if (q->q_cnt) {
					q->q_cnt++;
					putdq(mp, q->q_dq[index], 0);
					delquota(q);
				}
		}
	return (0);
}

/*
 * Q_SETUID - change quota to a particular uid.
 */
qsetuid(uid, noquota)
D 10
	int uid, noquota;
E 10
I 10
	uid_t uid;
	int noquota;
E 10
{
	register struct quota *q;

	if (uid == u.u_quota->q_uid)
		return (0);
	if (!suser())
		return (u.u_error);			/* XXX */
	q = getquota(uid, 0, noquota ? Q_NDQ : 0);
	qclean();
	qstart(q);
	return (0);
}
#endif
E 2
E 1
