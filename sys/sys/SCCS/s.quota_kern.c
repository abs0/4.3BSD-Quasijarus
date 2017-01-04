h26996
s 00010/00005/00711
d D 7.4 88/06/29 17:15:10 bostic 14 13
c install approved copyright notice
e
s 00008/00002/00708
d D 7.3 88/05/20 12:29:34 bostic 13 12
c add Berkeley specific header
e
s 00005/00005/00705
d D 7.2 87/06/21 15:30:39 mckusick 12 11
c geteblk => malloc, so m_bufp => m_fs as it should be
e
s 00001/00001/00709
d D 7.1 86/06/05 00:05:39 mckusick 11 10
c 4.3BSD release version
e
s 00006/00004/00704
d D 6.7 86/02/23 23:09:34 karels 10 9
c lint
e
s 00007/00001/00701
d D 6.6 85/06/08 14:39:50 mckusick 9 8
c Add copyright
e
s 00002/00002/00700
d D 6.5 85/03/13 20:04:48 mckusick 8 7
c hash with power of two to save modulo
e
s 00010/00010/00692
d D 6.4 84/08/29 20:20:57 bloom 7 6
c Change to includes.  no more ../h
e
s 00007/00003/00695
d D 6.3 84/07/08 16:15:00 mckusick 6 5
c rework `namei' interface to eliminate global variables
e
s 00005/00005/00693
d D 6.2 84/07/04 13:20:46 mckusick 5 4
c save time, use ILOCK and IUNLOCK to avoid call overhead
e
s 00000/00000/00698
d D 6.1 83/07/29 06:35:00 sam 4 3
c 4.2 distribution
e
s 00011/00006/00687
d D 4.3 83/05/28 19:13:18 sam 3 2
c didn't set dq_own on opendq
e
s 00090/00108/00603
d D 4.2 83/05/21 23:19:03 sam 2 1
c cleanup
e
s 00711/00000/00000
d D 4.1 83/05/21 15:50:26 sam 1 0
c date and time created 83/05/21 15:50:26 by sam
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

#ifdef QUOTA
/*
D 2
 * Quotas: code pertaining to management of
 * the in-core data structures.
E 2
I 2
 * MELBOURNE QUOTAS
 *
 * Code pertaining to management of the in-core data structures.
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
D 2
 * quota cache - hash chain headers
E 2
I 2
 * Quota cache - hash chain headers.
E 2
 */
D 8
#define	NQHASH		29		/* a small prime */
#define	QHASH(uid)	((unsigned)(uid) % NQHASH)
E 8
I 8
#define	NQHASH		32	/* small power of two */
#define	QHASH(uid)	((unsigned)(uid) & (NQHASH-1))
E 8

struct	qhash	{
	struct	qhash	*qh_forw;	/* MUST be first */
	struct	qhash	*qh_back;	/* MUST be second */
};

struct	qhash	qhash[NQHASH];

/*
D 2
 * quota free list
E 2
I 2
 * Quota free list.
E 2
 */
struct	quota	*qfreelist, **qfreetail;
typedef	struct quota *Qptr;

/*
D 2
 * dquot cache - hash chain headers
E 2
I 2
 * Dquot cache - hash chain headers.
E 2
 */
D 2

E 2
#define	NDQHASH		51		/* a smallish prime */
D 2
#define	DQHASH(uid, dev)	((unsigned)(((int)(dev)*4) + (uid)) % NDQHASH)
E 2
I 2
#define	DQHASH(uid, dev) \
	((unsigned)(((int)(dev) * 4) + (uid)) % NDQHASH)
E 2

struct	dqhead	{
	struct	dqhead	*dqh_forw;	/* MUST be first */
	struct	dqhead	*dqh_back;	/* MUST be second */
};

struct	dqhead	dqhead[NDQHASH];

/*
D 2
 * dquot free list
E 2
I 2
 * Dquot free list.
E 2
 */
struct	dquot	*dqfreel, **dqback;

typedef	struct dquot *DQptr;

/*
 * Initialize quota caches.
 */
qtinit()
{
	register i;
	register struct quota *q = quota;
	register struct qhash *qh = qhash;
	register struct dquot *dq = dquot;
	register struct dqhead *dh = dqhead;

	/*
	 * First the cache of structures assigned users.
	 */
	for (i = NQHASH; --i >= 0; qh++)
		qh->qh_forw = qh->qh_back = qh;
	qfreelist = q;
	qfreetail = &q->q_freef;
	q->q_freeb = &qfreelist;
	q->q_forw = q;
	q->q_back = q;
	for (i = nquota; --i > 0; ) {
		++q;
		q->q_forw = q;
		q->q_back = q;
		*qfreetail = q;
		q->q_freeb = qfreetail;
		qfreetail = &q->q_freef;
	}
D 2
	q->q_freef = NOQUOT;
E 2
I 2
	q->q_freef = NOQUOTA;
E 2
	/*
	 * Next, the cache between the in-core structures
	 * and the per-filesystem quota files on disk.
	 */
	for (i = NDQHASH; --i >= 0; dh++)
		dh->dqh_forw = dh->dqh_back = dh;
	dqfreel = dq;
	dqback = &dq->dq_freef;
	dq->dq_freeb = &dqfreel;
	dq->dq_forw = dq;
	dq->dq_back = dq;
	for (i = ndquot; --i > 0; ) {
		++dq;
		dq->dq_forw = dq;
		dq->dq_back = dq;
		*dqback = dq;
		dq->dq_freeb = dqback;
		dqback = &dq->dq_freef;
	}
	dq->dq_freef = NODQUOT;
}

/*
 * Find an incore quota structure for a particular uid,
D 2
 * or make one.  If nord is non-zero, just the lookup is performed.
E 2
I 2
 * or make one.  If lookuponly is non-zero, just the lookup is performed.
E 2
 * If nodq is non-zero, the dquot structures are left uninitialized.
 */
struct quota *
D 2
getquota(uid, nord, nodq)
E 2
I 2
getquota(uid, lookuponly, nodq)
E 2
D 10
	register uid;
E 10
I 10
	register uid_t uid;
E 10
I 2
	int lookuponly, nodq;
E 2
{
D 2
	register struct quota *q;	/* MUST be r10 */
	register struct qhash *qh;	/* MUST be r9 */
E 2
I 2
	register struct quota *q;
	register struct qhash *qh;
E 2
	register struct dquot **dqq;
	register struct mount *mp;
	register struct quota *qq;

	/*
	 * Fast check to see if an existing structure
	 * can be reused with just a reference count change.
	 */
D 2
	if ((q = u.u_quota) != NOQUOT && q->q_uid == uid)
E 2
I 2
	q = u.u_quota;
	if (q != NOQUOTA && q->q_uid == uid)
E 2
		goto quick;
	/*
	 * Search the quota chache for a hit.
	 */
	qh = &qhash[QHASH(uid)];
	for (q = (Qptr)qh->qh_forw; q != (Qptr)qh; q = q->q_forw) {
		if (q->q_uid == uid) {
			if (q->q_cnt == 0) {
I 2
				if (lookuponly)
					return (NOQUOTA);
E 2
				/*
D 2
				 * If quota isn't in use, & we don't want a
				 * new one, then just forget it
E 2
I 2
				 * Take it off the free list.
E 2
				 */
D 2
				if (nord)
					return (NOQUOT);
				/*
				 * Otherwise take it off the free list
				 */
				if ((qq = q->q_freef) != NOQUOT)
E 2
I 2
				if ((qq = q->q_freef) != NOQUOTA)
E 2
					qq->q_freeb = q->q_freeb;
				else
					qfreetail = q->q_freeb;
				*q->q_freeb = qq;

				/*
				 * Recover any lost dquot structs.
				 */
				if (!nodq)
				for (dqq = q->q_dq, mp = mount;
				    dqq < &q->q_dq[NMOUNT]; dqq++, mp++)
D 12
					if (*dqq == LOSTDQUOT && mp->m_bufp) {
E 12
I 12
					if (*dqq == LOSTDQUOT && mp->m_fs) {
E 12
						*dqq = discquota(uid,
							      mp->m_qinod);
						if (*dqq != NODQUOT)
							(*dqq)->dq_own = q;
					}
			}
  quick:
			q->q_cnt++;
D 2
			while (q->q_flg & Q_LOCK) {
				q->q_flg |= Q_WANT;
				sleep((char *) q, PINOD+1);
E 2
I 2
			while (q->q_flags & Q_LOCK) {
				q->q_flags |= Q_WANT;
				sleep((caddr_t) q, PINOD+1);
E 2
			}
			if (q->q_cnt == 1)
D 2
				q->q_flg |= Q_NEW|nodq;
E 2
I 2
				q->q_flags |= Q_NEW | nodq;
E 2
			return (q);
		}
	}
D 2

	if (nord)			/* if we are not setting quota */
		return (NOQUOT);
E 2
I 2
	if (lookuponly)
		return (NOQUOTA);
E 2
	/*
	 * Take the quota that is at the head of the free list
	 * (the longest unused quota).
	 */
D 2
	if ((q = qfreelist) == NOQUOT) {
E 2
I 2
	q = qfreelist;
	if (q == NOQUOTA) {
E 2
		tablefull("quota");
		u.u_error = EUSERS;
		q = quota;		/* the su's slot - we must have one */
		q->q_cnt++;
D 2
		return(q);
E 2
I 2
		return (q);
E 2
	}
	/*
	 * There is one - it is free no longer.
	 */
D 2
	if ((qq = q->q_freef) != NOQUOT)
E 2
I 2
	qq = q->q_freef;
	if (qq != NOQUOTA)
E 2
		qq->q_freeb = &qfreelist;
	qfreelist = qq;
	/*
	 * Now we are about to change this from one user to another
	 * Must take this off hash chain for old user immediately, in
	 * case some other process claims it before we are done.
	 * We must then put it on the hash chain for the new user,
	 * to make sure that we don't make two quota structs for one uid.
	 * (the quota struct will then be locked till we are done).
	 */
D 2
#ifdef lint
	/* verify this is correct later */
E 2
	remque(q);
D 2
	insque(qh, q);
#else
	{ asm("remque	(r10),r0"); }
	{ asm("insque	(r10),(r9)"); }
#endif
E 2
I 2
	insque(q, qh);
E 2
	q->q_uid = uid;
D 2
	q->q_flg = Q_LOCK;
E 2
I 2
	q->q_flags = Q_LOCK;
E 2
	q->q_cnt++;			/* q->q_cnt = 1; */
	/*
	 * Next, before filling in info for the new owning user,
	 * we must get rid of any dquot structs that we own.
	 */
	for (mp = mount, dqq = q->q_dq; mp < &mount[NMOUNT]; mp++, dqq++)
		if (*dqq != NODQUOT && *dqq != LOSTDQUOT) {
D 2
			(*dqq)->dq_own = NOQUOT;
E 2
I 2
			(*dqq)->dq_own = NOQUOTA;
E 2
			putdq(mp, *dqq, 1);
		}
	for (mp = mount, dqq = q->q_dq; dqq < &q->q_dq[NMOUNT]; mp++, dqq++)
D 12
		if (!nodq && mp->m_bufp) {
E 12
I 12
		if (!nodq && mp->m_fs) {
E 12
			*dqq = discquota(uid, mp->m_qinod);
			if (*dqq != NODQUOT) {
				if ((*dqq)->dq_uid != uid)
					panic("got bad quota uid");
				(*dqq)->dq_own = q;
			}
		} else
			*dqq = NODQUOT;
D 2
	if (q->q_flg & Q_WANT)
		wakeup((char *) q);
	q->q_flg = Q_NEW|nodq;
E 2
I 2
	if (q->q_flags & Q_WANT)
		wakeup((caddr_t)q);
	q->q_flags = Q_NEW | nodq;
E 2
	return (q);
}

/*
D 2
 * Delete a quota, wake up anyone waiting.
E 2
I 2
 * Delete a quota, wakeup anyone waiting.
E 2
 */
delquota(q)
	register struct quota *q;
{
	register struct dquot **dqq;
	register struct mount *mp;

 top:
	if (q->q_cnt != 1) {
		q->q_cnt--;
		return;
	}
D 2
	if (q->q_flg & Q_LOCK) {
		q->q_flg |= Q_WANT;
		sleep((char *)q, PINOD+2);
E 2
I 2
	if (q->q_flags & Q_LOCK) {
		q->q_flags |= Q_WANT;
		sleep((caddr_t)q, PINOD+2);
E 2
		/*
		 * Just so we don't sync dquots if not needed;
		 * 'if' would be 'while' if this was deleted.
		 */
		goto top;
	}

	/*
	 * If we own dquot structs, sync them to disc, but don't release
	 * them - we might be recalled from the LRU chain.
	 * As we will sit on the free list while we are waiting for that,
	 * if dquot structs run out, ours will be taken away.
	 */
D 2
	q->q_flg = Q_LOCK;
	if (!(q->q_flg & Q_NDQ)) {
		for (mp = mount, dqq = q->q_dq; dqq < &q->q_dq[NMOUNT];
		    dqq++, mp++) {
E 2
I 2
	q->q_flags = Q_LOCK;
	if ((q->q_flags & Q_NDQ) == 0) {
		mp = mount;
		for (dqq = q->q_dq; dqq < &q->q_dq[NMOUNT]; dqq++, mp++)
E 2
D 12
			if (mp->m_bufp)
E 12
I 12
			if (mp->m_fs)
E 12
				putdq(mp, *dqq, 0);
D 2
		}
E 2
	}
D 2
	if (q->q_flg & Q_WANT)
		wakeup((char *) q);
E 2
I 2
	if (q->q_flags & Q_WANT)
		wakeup((caddr_t)q);
E 2

	/*
	 * This test looks unnecessary, but someone might have claimed this
	 * quota while we have been getting rid of the dquot info
	 */
	if (--q->q_cnt == 0) {		/* now able to be reallocated */
D 2
		if (qfreelist != NOQUOT) {
E 2
I 2
		if (qfreelist != NOQUOTA) {
E 2
			*qfreetail = q;
			q->q_freeb = qfreetail;
		} else {
			qfreelist = q;
			q->q_freeb = &qfreelist;
		}
D 2
		q->q_freef = NOQUOT;
E 2
I 2
		q->q_freef = NOQUOTA;
E 2
		qfreetail = &q->q_freef;
D 2
		q->q_flg = 0;
E 2
I 2
		q->q_flags = 0;
E 2
	} else
D 2
		q->q_flg &= ~(Q_LOCK|Q_WANT);
E 2
I 2
		q->q_flags &= ~(Q_LOCK|Q_WANT);
E 2
}

/*
 * Obtain the user's on-disk quota limit
 * from the file specified.
 */
struct dquot *
discquota(uid, ip)
I 10
	uid_t uid;
E 10
	register struct inode *ip;
{
D 2
	register struct dquot *dq;	/* MUST be r10 */
E 2
I 2
	register struct dquot *dq;
E 2
	register struct dqhead *dh;
	register struct dquot *dp;
	int fail;

	if (ip == NULL)
		return (NODQUOT);
	/*
	 * Check the cache first.
	 */
	dh = &dqhead[DQHASH(uid, ip->i_dev)];
	for (dq = (DQptr)dh->dqh_forw; dq != (DQptr)dh; dq = dq->dq_forw) {
		if (dq->dq_uid != uid || dq->dq_dev != ip->i_dev)
			continue;
		/*
		 * Cache hit with no references.  Take
		 * the structure off the free list.
		 */
		if (dq->dq_cnt++ == 0) {
D 2
			if ((dp = dq->dq_freef) != NODQUOT)
E 2
I 2
			dp = dq->dq_freef;
			if (dp != NODQUOT)
E 2
				dp->dq_freeb = dq->dq_freeb;
			else
				dqback = dq->dq_freeb;
			*dq->dq_freeb = dp;
D 2
			dq->dq_own = NOQUOT;
E 2
I 2
			dq->dq_own = NOQUOTA;
E 2
		}
		/*
		 * We do this test after the previous one so that
		 * the dquot will be moved to the end of the free
		 * list - frequently accessed ones ought to hang around.
		 */
D 2
		if (dq->dq_iq == 0 && dq->dq_quot == 0) {
E 2
I 2
		if (dq->dq_isoftlimit == 0 && dq->dq_bsoftlimit == 0) {
E 2
			dqrele(dq);
			return (NODQUOT);
		}
		return (dq);
	}
	/*
	 * Not in cache, allocate a new one and
	 * bring info in off disk.
	 */
D 2
	if ((dq = dqalloc(uid, ip->i_dev)) == NODQUOT)
E 2
I 2
	dq = dqalloc(uid, ip->i_dev);
	if (dq == NODQUOT)
E 2
		return (dq);
D 2
	dq->dq_flg = DQ_LOCK;
E 2
I 2
	dq->dq_flags = DQ_LOCK;
E 2
D 5
	ilock(ip);
E 5
I 5
	ILOCK(ip);
E 5
	fail = rdwri(UIO_READ, ip, (caddr_t)&dq->dq_dqb, sizeof (struct dqblk),
D 10
	    uid * sizeof (struct dqblk), 1, (int *)0);
E 10
I 10
	    (off_t)uid * sizeof (struct dqblk), 1, (int *)0);
E 10
D 5
	iunlock(ip);
E 5
I 5
	IUNLOCK(ip);
E 5
D 2
	if (dq->dq_flg & DQ_WANT)
E 2
I 2
	if (dq->dq_flags & DQ_WANT)
E 2
		wakeup((caddr_t)dq);
D 2
	dq->dq_flg = 0;
E 2
I 2
	dq->dq_flags = 0;
E 2
	/*
	 * I/O error in reading quota file, release
	 * quota structure and reflect problem to caller.
	 */
	if (fail) {
D 2
#ifdef lint
		/* verify this is correct later */
E 2
		remque(dq);
D 2
#else
		{ asm("remque	(r10),r0"); }
#endif
E 2
		dq->dq_forw = dq;	/* on a private, unfindable hash list */
		dq->dq_back = dq;
		/* dqrele() (just below) will put dquot back on free list */
	}
	/* no quota exists */
D 2
	if (fail || dq->dq_iq == 0 && dq->dq_quot == 0) {
E 2
I 2
	if (fail || dq->dq_isoftlimit == 0 && dq->dq_bsoftlimit == 0) {
E 2
		dqrele(dq);
		return (NODQUOT);
	}
	return (dq);
}

/*
 * Allocate a dquot structure.  If there are
 * no free slots in the cache, flush LRU entry from
 * the cache to the appropriate quota file on disk.
 */
struct dquot *
dqalloc(uid, dev)
I 10
	uid_t uid;
E 10
	dev_t dev;
{
D 2
	register struct dquot *dq;	/* MUST be r11 */
	register struct dqhead *dh;	/* MUST be r10 */
E 2
I 2
	register struct dquot *dq;
	register struct dqhead *dh;
E 2
	register struct dquot *dp;
	register struct quota *q;
	register struct mount *mp;
	static struct dqblk zdqb = { 0 };

 top:
	/*
	 * Locate inode of quota file for
	 * indicated file system in case i/o
	 * is necessary in claiming an entry.
	 */
	for (mp = mount; mp < &mount[NMOUNT]; mp++) {
D 12
		if (mp->m_dev == dev && mp->m_bufp) {
E 12
I 12
		if (mp->m_dev == dev && mp->m_fs) {
E 12
			if (mp->m_qinod == NULL) {
				u.u_error = EINVAL;
				return (NODQUOT);
			}
			break;
		}
	}
	if (mp >= &mount[NMOUNT]) {
		u.u_error = EINVAL;
		return (NODQUOT);
	}
	/*
	 * Check free list.  If table is full, pull entries
	 * off the quota free list and flush any associated
	 * dquot references until something frees up on the
	 * dquot free list.
	 */
D 2
	if ((dq = dqfreel) == NODQUOT && (q = qfreelist) != NOQUOT) {
E 2
I 2
	if ((dq = dqfreel) == NODQUOT && (q = qfreelist) != NOQUOTA) {
E 2

		do {
			register struct dquot **dqq;
			register struct mount *mountp = mount;

			dqq = q->q_dq;
			while (dqq < &q->q_dq[NMOUNT]) {
				if ((dq = *dqq) != NODQUOT &&
				    dq != LOSTDQUOT) {
					/*
					 * Mark entry as "lost" due to
					 * scavenging operation.
					 */
					if (dq->dq_cnt == 1) {
						*dqq = LOSTDQUOT;
						putdq(mountp, dq, 1);
						goto top;
					}
				}
				mountp++;
				dqq++;
			}
			q = q->q_freef;
D 2
		} while ((dq = dqfreel) == NODQUOT && q != NOQUOT);
E 2
I 2
		} while ((dq = dqfreel) == NODQUOT && q != NOQUOTA);
E 2
	}
	if (dq == NODQUOT) {
		tablefull("dquot");
		u.u_error = EUSERS;
		return (dq);
	}
	/*
	 * This shouldn't happen, as we sync
	 * dquot before freeing it up.
	 */
D 2
	if (dq->dq_flg & DQ_MOD)
E 2
I 2
	if (dq->dq_flags & DQ_MOD)
E 2
		panic("discquota");

	/*
	 * Now take the dquot off the free list,
	 */
D 2
	if ((dp = dq->dq_freef) != NODQUOT)
E 2
I 2
	dp = dq->dq_freef;
	if (dp != NODQUOT)
E 2
		dp->dq_freeb = &dqfreel;
	dqfreel = dp;
	/*
	 * and off the hash chain it was on, & onto the new one.
	 */
	dh = &dqhead[DQHASH(uid, dev)];
D 2
#ifdef lint
	/* verify this is correct sometime later */
E 2
	remque(dq);
D 2
	insque(dh, dq);
#else
	{ asm("remque	(r11),r0"); }
	{ asm("insque	(r11),(r10)"); }
#endif
E 2
I 2
	insque(dq, dh);
E 2
	dq->dq_cnt = 1;
D 2
	dq->dq_flg = 0;
E 2
I 2
	dq->dq_flags = 0;
E 2
	dq->dq_uid = uid;
	dq->dq_dev = dev;
	dq->dq_dqb = zdqb;
D 2
	dq->dq_own = NOQUOT;
E 2
I 2
	dq->dq_own = NOQUOTA;
E 2
	return (dq);
}

/*
 * dqrele - layman's interface to putdq.
 */
dqrele(dq)
	register struct dquot *dq;
{
	register struct mount *mp;

	if (dq == NODQUOT || dq == LOSTDQUOT)
		return;
	if (dq->dq_cnt > 1) {
		dq->dq_cnt--;
		return;
	}
	/*
	 * I/O required, find appropriate file system
	 * to sync the quota information to.
	 */
	for (mp = mount; mp < &mount[NMOUNT]; mp++)
D 12
		if (mp->m_bufp && mp->m_dev == dq->dq_dev) {
E 12
I 12
		if (mp->m_fs && mp->m_dev == dq->dq_dev) {
E 12
			putdq(mp, dq, 1);
			return;
		}
	panic("dqrele");
}

/*
 * Update the disc quota in the quota file.
 */
putdq(mp, dq, free)
	register struct mount *mp;
	register struct dquot *dq;
{
	register struct inode *ip;

	if (dq == NODQUOT || dq == LOSTDQUOT)
		return;
	if (free && dq->dq_cnt > 1) {
		dq->dq_cnt--;
		return;
	}
	/*
	 * Disk quota not modified, just discard
	 * or return (having adjusted the reference
	 * count), as indicated by the "free" param.
	 */
D 2
	if (!(dq->dq_flg & DQ_MOD)) {
E 2
I 2
	if ((dq->dq_flags & DQ_MOD) == 0) {
E 2
		if (free) {
			dq->dq_cnt = 0;
 release:
			if (dqfreel != NODQUOT) {
				*dqback = dq;
				dq->dq_freeb = dqback;
			} else {
				dqfreel = dq;
				dq->dq_freeb = &dqfreel;
			}
			dq->dq_freef = NODQUOT;
			dqback = &dq->dq_freef;
		}
		return;
	}
	/*
	 * Quota modified, write back to disk.
	 */
D 2
	while (dq->dq_flg & DQ_LOCK) {
		dq->dq_flg |= DQ_WANT;
		sleep((char *)dq, PINOD+2);
E 2
I 2
	while (dq->dq_flags & DQ_LOCK) {
		dq->dq_flags |= DQ_WANT;
		sleep((caddr_t)dq, PINOD+2);
E 2
		/* someone could sneak in and grab it */
		if (free && dq->dq_cnt > 1) {
			dq->dq_cnt--;
			return;
		}
	}
D 2
	dq->dq_flg |= DQ_LOCK;
E 2
I 2
	dq->dq_flags |= DQ_LOCK;
E 2
	if ((ip = mp->m_qinod) == NULL)
		panic("lost quota file");
D 5
	ilock(ip);
E 5
I 5
	ILOCK(ip);
E 5
	(void) rdwri(UIO_WRITE, ip, (caddr_t)&dq->dq_dqb, sizeof (struct dqblk),
D 10
	    dq->dq_uid * sizeof (struct dqblk), 1, (int *)0);
E 10
I 10
	    (off_t)dq->dq_uid * sizeof (struct dqblk), 1, (int *)0);
E 10
D 5
	iunlock(ip);
E 5
I 5
	IUNLOCK(ip);
E 5
D 2
	if (dq->dq_flg & DQ_WANT)
		wakeup((char *)dq);
	dq->dq_flg &= ~(DQ_MOD|DQ_LOCK|DQ_WANT);
E 2
I 2
	if (dq->dq_flags & DQ_WANT)
		wakeup((caddr_t)dq);
	dq->dq_flags &= ~(DQ_MOD|DQ_LOCK|DQ_WANT);
E 2
	if (free && --dq->dq_cnt == 0)
		goto release;
}

/*
 * See if there is a quota struct in core for user 'uid'.
 */
struct quota *
qfind(uid)
D 10
	register int uid;
E 10
I 10
	register uid_t uid;
E 10
{
	register struct quota *q;
	register struct qhash *qh;

	/* 
	 * Check common cases first: asking for own quota,
	 * or that of the super user (has reserved slot 0
	 * in the table).
	 */
D 2
	if ((q = u.u_quota) != NOQUOT && q->q_uid == uid)
E 2
I 2
	q = u.u_quota;
	if (q != NOQUOTA && q->q_uid == uid)
E 2
		return (q);
	if (uid == 0)		/* the second most likely case */
		return (quota);
	/*
	 * Search cache.
	 */
	qh = &qhash[QHASH(uid)];
	for (q = (Qptr)qh->qh_forw; q != (Qptr)qh; q = q->q_forw)
		if (q->q_uid == uid)
			return (q);
D 2
	return (NOQUOT);
E 2
I 2
	return (NOQUOTA);
E 2
}

/*
 * Set the quota file up for a particular file system.
 * Called as the result of a setquota system call.
 */
D 6
opendq(mp)
E 6
I 6
opendq(mp, fname)
E 6
	register struct mount *mp;
I 6
	caddr_t fname;
E 6
{
	register struct inode *ip;
	register struct quota *q;
D 3
	register i;
E 3
I 3
	struct dquot *dq;
I 6
	register struct nameidata *ndp = &u.u_nd;
E 6
	int i;
E 3

	if (mp->m_qinod)
		closedq(mp);
D 2
	if ((ip = namei(uchar, LOOKUP, 1)) == NULL)
E 2
I 2
D 6
	ip = namei(uchar, LOOKUP, 1);
E 6
I 6
	ndp->ni_nameiop = LOOKUP | FOLLOW;
	ndp->ni_segflg = UIO_USERSPACE;
	ndp->ni_dirp = fname;
	ip = namei(ndp);
E 6
	if (ip == NULL)
E 2
		return;
D 5
	iunlock(ip);
E 5
I 5
	IUNLOCK(ip);
E 5
	if (ip->i_dev != mp->m_dev) {
		u.u_error = EACCES;
		return;
	}
	if ((ip->i_mode & IFMT) != IFREG) {
		u.u_error = EACCES;
		return;
	}
	/*
	 * Flush in-core references to any previous
	 * quota file for this file system.
	 */
	mp->m_qinod = ip;
D 3
	i = mp-mount;
E 3
I 3
	i = mp - mount;
E 3
	for (q = quota; q < quotaNQUOTA; q++)
D 2
		if (!(q->q_flg&Q_NDQ)) {
E 2
I 2
		if ((q->q_flags & Q_NDQ) == 0) {
E 2
D 3
			if (q->q_cnt) {
E 3
I 3
			if (q->q_cnt == 0)
				q->q_dq[i] = LOSTDQUOT;
			else {
E 3
				q->q_cnt++;	/* cannot be released */
D 3
				q->q_dq[i] = discquota(q->q_uid, ip);
E 3
I 3
				dq = discquota(q->q_uid, ip);
				q->q_dq[i] = dq;
				if (dq != NODQUOT)
					dq->dq_own = q;
E 3
				delquota(q);
D 3
			} else
				q->q_dq[i] = LOSTDQUOT;
E 3
I 3
			}
E 3
		}
}

/*
 * Close off disc quotas for a file system.
 */
closedq(mp)
	register struct mount *mp;
{
D 2
	register struct dquot *dq;		/* known to be r10 */
	register i = mp-mount;
E 2
I 2
	register struct dquot *dq;
	register i = mp - mount;
E 2
	register struct quota *q;
	register struct inode *ip;

	if (mp->m_qinod == NULL)
		return;
	/*
	 * Search inode table, delete any references
	 * to quota file being closed.
	 */
	for (ip = inode; ip < inodeNINODE; ip++)
		if (ip->i_dev == mp->m_dev) {
			dq = ip->i_dquot;
			ip->i_dquot = NODQUOT;
			putdq(mp, dq, 1);
		}
	/*
	 * Search quota table, flush any pending
	 * quota info to disk and also delete
	 * references to closing quota file.
	 */
	for (q = quota; q < quotaNQUOTA; q++) {
D 2
		if (!(q->q_flg&Q_NDQ)) {
E 2
I 2
		if ((q->q_flags & Q_NDQ) == 0) {
E 2
			if (q->q_cnt) {
				q->q_cnt++;
				putdq(mp, q->q_dq[i], 1);
				delquota(q);
			} else
				putdq(mp, q->q_dq[i], 1);
		}
		q->q_dq[i] = NODQUOT;
	}

	/*
	 * Move all dquot's that used to refer to this quota
	 * file of into the never-never (they will eventually
	 * fall off the head of the free list and be re-used).
	 */
	for (dq = dquot; dq < dquotNDQUOT; dq++)
		if (dq->dq_dev == mp->m_dev) {
			if (dq->dq_cnt)
				panic("closedq: stray dquot");
D 2
#ifdef lint
			/* verify this is correct later */
E 2
			remque(dq);
D 2
#else
			{ asm("remque (r10),r0"); }
#endif
E 2
			dq->dq_forw = dq;
			dq->dq_back = dq;
			dq->dq_dev = NODEV;
		}
	irele(mp->m_qinod);
	mp->m_qinod = NULL;
}
#endif
E 1
