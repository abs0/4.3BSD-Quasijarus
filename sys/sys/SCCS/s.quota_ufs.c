h62557
s 00010/00005/00238
d D 7.4 88/06/29 17:20:18 bostic 12 11
c install approved copyright notice
e
s 00008/00002/00235
d D 7.3 88/05/20 12:29:41 bostic 11 10
c add Berkeley specific header
e
s 00001/00001/00236
d D 7.2 87/06/26 19:58:04 mckusick 10 9
c m_bufp => m_fs
e
s 00001/00001/00236
d D 7.1 86/06/05 00:06:19 mckusick 9 8
c 4.3BSD release version
e
s 00002/00001/00235
d D 6.6 86/02/23 23:10:02 karels 8 7
c lint
e
s 00013/00000/00223
d D 6.5 86/01/29 14:09:34 mckusick 7 6
c no longer require login to reset quota when out of warnings (from ghg)
e
s 00007/00001/00216
d D 6.4 85/06/08 14:40:46 mckusick 6 5
c Add copyright
e
s 00010/00010/00207
d D 6.3 84/08/29 20:21:20 bloom 5 4
c Change to includes.  no more ../h
e
s 00000/00001/00217
d D 6.2 84/07/08 16:19:31 mckusick 4 3
c rework `namei' interface to eliminate global variables
e
s 00000/00000/00218
d D 6.1 83/07/29 06:35:39 sam 3 2
c 4.2 distribution
e
s 00068/00058/00150
d D 4.2 83/05/21 23:19:32 sam 2 1
c cleanup
e
s 00208/00000/00000
d D 4.1 83/05/21 15:50:34 sam 1 0
c date and time created 83/05/21 15:50:34 by sam
e
u
U
t
T
I 1
D 6
/*	%M%	%I%	%E%	*/
E 6
I 6
/*
D 9
 * Copyright (c) 1982 Regents of the University of California.
E 9
I 9
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 9
D 11
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 11
I 11
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 12
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 12
I 12
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
E 12
E 11
 *
 *	%W% (Berkeley) %G%
 */
E 6

#ifdef QUOTA
/*
D 2
 * Quotas: routines used in checking limits on file system usage.
E 2
I 2
 * MELBOURNE QUOTAS
 *
 * Routines used in checking limits on file system usage.
E 2
 */
D 5
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
E 5
I 5
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
E 5
D 4
#include "../h/nami.h"
E 4

/*
 * Find the dquot structure that should
 * be used in checking i/o on inode ip.
 */
struct dquot *
inoquota(ip)
	register struct inode *ip;
{
	register struct quota *q;
	register struct dquot **dqq;
	register struct mount *mp;
D 2
	register i;
E 2
I 2
	int index;
E 2

 top:
D 2
	if ((q = qfind(ip->i_uid)) == NOQUOT) {
E 2
I 2
	q = qfind(ip->i_uid);
	if (q == NOQUOTA) {
E 2
		for (mp = mount; mp < &mount[NMOUNT]; mp++)
D 10
			if (mp->m_bufp && mp->m_dev == ip->i_dev)
E 10
I 10
			if (mp->m_fs && mp->m_dev == ip->i_dev)
E 10
				return (discquota(ip->i_uid, mp->m_qinod));
		panic("inoquota");
	}

	/*
	 * We have a quota struct in core (most likely our own) that
	 * belongs to the same user as the inode
	 */
D 2
	if (q->q_flg & Q_NDQ)
		return(NODQUOT);
	if (q->q_flg & Q_LOCK) {
		q->q_flg |= Q_WANT;
		sleep((caddr_t) q, PINOD+1);
E 2
I 2
	if (q->q_flags & Q_NDQ)
		return (NODQUOT);
	if (q->q_flags & Q_LOCK) {
		q->q_flags |= Q_WANT;
		sleep((caddr_t)q, PINOD+1);
E 2
		goto top;		/* might just have been freed */
	}
D 2
	i = getfsx(ip->i_dev);
	dqq = &q->q_dq[i];
E 2
I 2
	index = getfsx(ip->i_dev);
	dqq = &q->q_dq[index];
E 2
	if (*dqq == LOSTDQUOT) {
D 2
		q->q_flg |= Q_LOCK;
		*dqq = discquota(q->q_uid, mount[i].m_qinod);
E 2
I 2
		q->q_flags |= Q_LOCK;
		*dqq = discquota(q->q_uid, mount[index].m_qinod);
E 2
		if (*dqq != NODQUOT)
			(*dqq)->dq_own = q;
D 2
		if (q->q_flg & Q_WANT)
			wakeup((caddr_t) q);
		q->q_flg &= ~(Q_LOCK|Q_WANT);
E 2
I 2
		if (q->q_flags & Q_WANT)
			wakeup((caddr_t)q);
		q->q_flags &= ~(Q_LOCK | Q_WANT);
E 2
	}
	if (*dqq != NODQUOT)
		(*dqq)->dq_cnt++;
	return (*dqq);
}

/*
 * Update disc usage, and take corrective action.
 */
D 2
chkdq(ip, chg, f)
E 2
I 2
chkdq(ip, change, force)
E 2
	register struct inode *ip;
D 2
	register long chg;			/* +/- num blocks alloc/free */
E 2
I 2
	long change;
	int force;
E 2
{
	register struct dquot *dq;

D 2
	if (chg == 0)
E 2
I 2
	if (change == 0)
E 2
		return (0);
	dq = ip->i_dquot;
	if (dq == NODQUOT)
		return (0);
D 2
	if (dq->dq_quot == 0)
E 2
I 2
	if (dq->dq_bsoftlimit == 0)
E 2
		return (0);
D 2
	dq->dq_flg |= DQ_MOD;
	if (chg < 0) {
		if ((int)dq->dq_blks + chg >= 0)
			dq->dq_blks += chg;
E 2
I 2
	dq->dq_flags |= DQ_MOD;
I 7
	/*
	 * reset warnings if below disk quota.
	 */
        if (dq->dq_bwarn == 0 && dq->dq_bsoftlimit &&
	    (dq->dq_curblocks + change) < dq->dq_bsoftlimit) {
		dq->dq_bwarn = MAX_DQ_WARN;
		if (dq->dq_own == u.u_quota) {
			uprintf("\nUNDER DISC QUOTA: (%s) by %d Kbytes\n",
				ip->i_fs->fs_fsmnt,
				dbtob(dq->dq_bsoftlimit -
				(dq->dq_curblocks + change)) / 1024);
		}
	}
E 7
	if (change < 0) {
		if ((int)dq->dq_curblocks + change >= 0)
			dq->dq_curblocks += change;
E 2
		else
D 2
			dq->dq_blks = 0;
		dq->dq_flg &= ~DQ_BLKS;
E 2
I 2
			dq->dq_curblocks = 0;
		dq->dq_flags &= ~DQ_BLKS;
E 2
		return (0);
	}

	/*
	 * If user is over quota, or has run out of warnings, then
	 * disallow space allocation (except su's are never stopped).
	 */
	if (u.u_uid == 0)
D 2
		f = 1;
	if (!f && dq->dq_dwarn == 0) {
		if (!(dq->dq_flg & DQ_BLKS) && dq->dq_own == u.u_quota) {
		     uprintf("\nOVER DISC QUOTA: (%s) NO MORE DISC SPACE\n"
			, getfs(dq->dq_dev)->fs_fsmnt);
		     dq->dq_flg |= DQ_BLKS;
E 2
I 2
		force = 1;
	if (!force && dq->dq_bwarn == 0) {
		if ((dq->dq_flags & DQ_BLKS) == 0 && dq->dq_own == u.u_quota) {
		     uprintf("\nOVER DISC QUOTA: (%s) NO MORE DISC SPACE\n",
			ip->i_fs->fs_fsmnt);
		     dq->dq_flags |= DQ_BLKS;
E 2
		}
		return (EDQUOT);
	}
D 2
	if (dq->dq_blks < dq->dq_quot) {
		if ((dq->dq_blks += chg) < dq->dq_quot)
E 2
I 2
	if (dq->dq_curblocks < dq->dq_bsoftlimit) {
		dq->dq_curblocks += change;
		if (dq->dq_curblocks < dq->dq_bsoftlimit)
E 2
			return (0);
		if (dq->dq_own == u.u_quota)
			uprintf("\nWARNING: disc quota (%s) exceeded\n",
D 2
			    getfs(dq->dq_dev)->fs_fsmnt);
E 2
I 2
			   ip->i_fs->fs_fsmnt);
E 2
		return (0);
	}
D 2
	if (!f && dq->dq_blim && dq->dq_blks+chg >= dq->dq_blim) {
		if (!(dq->dq_flg & DQ_BLKS) && dq->dq_own == u.u_quota) {
			uprintf("\nDISC LIMIT REACHED (%s) - WRITE FAILED\n"
			    , getfs(dq->dq_dev)->fs_fsmnt);
			dq->dq_flg |= DQ_BLKS;
E 2
I 2
	if (!force && dq->dq_bhardlimit &&
	    dq->dq_curblocks + change >= dq->dq_bhardlimit) {
		if ((dq->dq_flags & DQ_BLKS) == 0 && dq->dq_own == u.u_quota) {
			uprintf("\nDISC LIMIT REACHED (%s) - WRITE FAILED\n",
			   ip->i_fs->fs_fsmnt);
			dq->dq_flags |= DQ_BLKS;
E 2
		}
		return (EDQUOT);
	}
	/*
	 * User is over quota, but not over limit
	 * or is over limit, but we have been told
	 * there is nothing we can do.
	 */
D 2
	dq->dq_blks += chg;
E 2
I 2
	dq->dq_curblocks += change;
E 2
	return (0);
}

/*
 * Check the inode limit, applying corrective action.
 */
D 2
chkiq(dev, ip, uid, f)
	register dev_t dev;
E 2
I 2
chkiq(dev, ip, uid, force)
	dev_t dev;
I 8
	uid_t uid;
E 8
E 2
	register struct inode *ip;
I 2
D 8
	int uid, force;
E 8
I 8
	int force;
E 8
E 2
{
	register struct dquot *dq;
	register struct quota *q;

	if (ip == NULL)	{		/* allocation */
D 2
		if ((q = qfind(uid)) != NOQUOT)
E 2
I 2
		q = qfind(uid);
		if (q != NOQUOTA)
E 2
			dq = dqp(q, dev);
		else
			dq = discquota(uid, mount[getfsx(dev)].m_qinod);
	} else {			/* free */
		dq = ip->i_dquot;
		if (dq != NODQUOT)
			dq->dq_cnt++;
	}
	if (dq == NODQUOT)
		return (0);
D 2
	if (dq->dq_iq == 0) {
E 2
I 2
	if (dq->dq_isoftlimit == 0) {
E 2
		dqrele(dq);
		return (0);
	}
D 2
	dq->dq_flg |= DQ_MOD;
E 2
I 2
	dq->dq_flags |= DQ_MOD;
E 2
	if (ip) {			/* a free */
D 2
		if (dq->dq_inod)
			dq->dq_inod--;
		dq->dq_flg &= ~DQ_INODS;
E 2
I 2
		if (dq->dq_curinodes)
			dq->dq_curinodes--;
		dq->dq_flags &= ~DQ_INODS;
E 2
		dqrele(dq);
		return (0);
	}

	/*
	 * The following shouldn't be necessary, as if u.u_uid == 0
	 * then dq == NODQUOT & we wouldn't get here at all, but
	 * then again, its not going to harm anything ...
	 */
	if (u.u_uid == 0)		/* su's musn't be stopped */
D 2
		f = 1;
	if (!f && dq->dq_iwarn == 0) {
		if (!(dq->dq_flg & DQ_INODS) && dq->dq_own == u.u_quota) {
E 2
I 2
		force = 1;
	if (!force && dq->dq_iwarn == 0) {
		if ((dq->dq_flags & DQ_INODS) == 0 && dq->dq_own == u.u_quota) {
E 2
			uprintf("\nOVER FILE QUOTA - NO MORE FILES (%s)\n",
			    getfs(dq->dq_dev)->fs_fsmnt);
D 2
			dq->dq_flg |= DQ_INODS;
E 2
I 2
			dq->dq_flags |= DQ_INODS;
E 2
		}
		dqrele(dq);
		return (EDQUOT);
	}
D 2
	if (dq->dq_inod < dq->dq_iq) {
		if (++dq->dq_inod >= dq->dq_iq && dq->dq_own == u.u_quota)
E 2
I 2
	if (dq->dq_curinodes < dq->dq_isoftlimit) {
		if (++dq->dq_curinodes >= dq->dq_isoftlimit &&
		    dq->dq_own == u.u_quota)
E 2
			uprintf("\nWARNING - too many files (%s)\n",
			    getfs(dq->dq_dev)->fs_fsmnt);
		dqrele(dq);
		return (0);
	}
D 2
	if (!f && dq->dq_ilim && dq->dq_inod+1 >= dq->dq_ilim) {
		if (!(dq->dq_flg & DQ_INODS) && dq->dq_own == u.u_quota) {
E 2
I 2
	if (!force && dq->dq_ihardlimit &&
	    dq->dq_curinodes + 1 >= dq->dq_ihardlimit) {
		if ((dq->dq_flags & DQ_INODS) == 0 && dq->dq_own == u.u_quota) {
E 2
		     uprintf("\nFILE LIMIT REACHED - CREATE FAILED (%s)\n",
			getfs(dq->dq_dev)->fs_fsmnt);
D 2
		     dq->dq_flg |= DQ_INODS;
E 2
I 2
		     dq->dq_flags |= DQ_INODS;
E 2
		}
		dqrele(dq);
		return (EDQUOT);
	}
	/*
	 * Over quota but not at limit;
	 * or over limit, but we aren't
	 * allowed to stop it.
	 */
D 2
	dq->dq_inod++;
E 2
I 2
	dq->dq_curinodes++;
E 2
	dqrele(dq);
	return (0);
}
#endif
E 1
