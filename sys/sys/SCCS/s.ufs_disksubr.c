h19366
s 00001/00001/00344
d D 7.11 88/09/23 13:59:45 tef 19 18
c print proper track# and sector# on errors
e
s 00004/00001/00341
d D 7.10 88/06/11 18:54:40 karels 18 17
c "correct" disk block units on tahoe
e
s 00007/00003/00335
d D 7.9 88/06/04 17:06:17 karels 17 16
c why not, print cyl/trk/sect on disk errors
e
s 00050/00001/00288
d D 7.8 88/05/27 16:42:50 karels 16 15
c new diskerr routine, replacing harderr
e
s 00001/00001/00288
d D 7.7 88/05/24 19:26:11 mckusick 15 14
c lint
e
s 00023/00012/00266
d D 7.6 88/04/24 20:43:19 karels 14 13
c keep cksum up to date, support variable offset (now need to have
c existing label to update)
e
s 00094/00001/00184
d D 7.5 87/11/01 12:56:43 karels 13 12
c add setdisklabel, writedisklabel to check and rewrite labels
e
s 00015/00008/00170
d D 7.4 87/08/23 18:24:57 karels 12 11
c look for disk label at any reasonable offset
e
s 00053/00000/00125
d D 7.3 87/04/01 21:09:34 karels 11 10
c add generalized code to read disk label
e
s 00021/00004/00104
d D 7.2 87/02/19 17:29:40 karels 10 9
c dkcksum
e
s 00001/00001/00107
d D 7.1 86/06/05 00:12:29 mckusick 9 8
c 4.3BSD release version
e
s 00007/00001/00101
d D 6.3 85/06/08 14:51:07 mckusick 8 7
c Add copyright
e
s 00003/00003/00099
d D 6.2 84/08/29 20:25:51 bloom 7 6
c Change to includes.  no more ../h
e
s 00000/00000/00102
d D 6.1 83/07/29 06:41:55 sam 6 5
c 4.2 distribution
e
s 00001/00001/00101
d D 4.3 81/03/09 01:52:46 wnj 5 4
c %G% -> %E%
e
s 00076/00019/00026
d D 4.2 81/02/23 20:14:25 wnj 4 3
c new sorter
e
s 00000/00000/00045
d D 4.1 80/11/09 16:52:17 bill 3 2
c stamp for 4bsd
e
s 00001/00001/00044
d D 3.2 80/06/07 02:45:12 bill 2 1
c %H%->%G%
e
s 00045/00000/00000
d D 3.1 80/04/09 16:03:07 bill 1 0
c date and time created 80/04/09 16:03:07 by bill
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
D 5
/*	%M%	%I%	%G%	*/
E 5
I 5
D 8
/*	%M%	%I%	%E%	*/
E 8
I 8
/*
D 9
 * Copyright (c) 1982 Regents of the University of California.
E 9
I 9
D 16
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 16
I 16
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 16
E 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 8
E 5
E 2

I 10
#include "param.h"
#include "systm.h"
#include "buf.h"
#include "disklabel.h"
I 16
#include "syslog.h"
E 16

I 11
#include "dir.h"
#include "user.h"

E 11
E 10
/*
D 4
 * generalized seek sort for disk
E 4
I 4
 * Seek sort for disks.  We depend on the driver
 * which calls us using b_resid as the current cylinder number.
 *
 * The argument dp structure holds a b_actf activity chain pointer
 * on which we keep two queues, sorted in ascending cylinder order.
 * The first queue holds those requests which are positioned after
 * the current cylinder (in the first request); the second holds
 * requests which came in after their cylinder number was passed.
 * Thus we implement a one way scan, retracting after reaching the
 * end of the drive to the first request on the second queue,
 * at which time it becomes the first queue.
 *
 * A one-way scan is natural because of the way UNIX read-ahead
 * blocks are allocated.
E 4
 */

D 7
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/buf.h"
E 7
I 7
D 10
#include "param.h"
#include "systm.h"
#include "buf.h"
E 7

E 10
#define	b_cylin	b_resid

disksort(dp, bp)
D 4
register struct buf *dp, *bp;
E 4
I 4
	register struct buf *dp, *bp;
E 4
{
	register struct buf *ap;
D 4
	struct buf *tp;
E 4

I 4
	/*
	 * If nothing on the activity queue, then
	 * we become the only thing.
	 */
E 4
	ap = dp->b_actf;
	if(ap == NULL) {
		dp->b_actf = bp;
		dp->b_actl = bp;
		bp->av_forw = NULL;
		return;
	}
D 4
	tp = NULL;
	for(; ap != NULL; ap = ap->av_forw) {
		if ((bp->b_flags&B_READ) && (ap->b_flags&B_READ) == 0) {
			if (tp == NULL)
				tp = ap;
			break;
E 4
I 4
	/*
	 * If we lie after the first (currently active)
	 * request, then we must locate the second request list
	 * and add ourselves to it.
	 */
	if (bp->b_cylin < ap->b_cylin) {
		while (ap->av_forw) {
			/*
			 * Check for an ``inversion'' in the
			 * normally ascending cylinder numbers,
			 * indicating the start of the second request list.
			 */
			if (ap->av_forw->b_cylin < ap->b_cylin) {
				/*
				 * Search the second request list
				 * for the first request at a larger
				 * cylinder number.  We go before that;
				 * if there is no such request, we go at end.
				 */
				do {
					if (bp->b_cylin < ap->av_forw->b_cylin)
						goto insert;
I 13
					if (bp->b_cylin == ap->av_forw->b_cylin &&
					    bp->b_blkno < ap->av_forw->b_blkno)
						goto insert;
E 13
					ap = ap->av_forw;
				} while (ap->av_forw);
				goto insert;		/* after last */
			}
			ap = ap->av_forw;
E 4
		}
D 4
		if ((bp->b_flags&B_READ) == 0 && (ap->b_flags&B_READ))
			continue;
		if(ap->b_cylin <= bp->b_cylin)
			if(tp == NULL || ap->b_cylin >= tp->b_cylin)
				tp = ap;
E 4
I 4
		/*
		 * No inversions... we will go after the last, and
		 * be the first request in the second request list.
		 */
		goto insert;
E 4
	}
D 4
	if(tp == NULL)
		tp = dp->b_actl;
	bp->av_forw = tp->av_forw;
	tp->av_forw = bp;
	if(tp == dp->b_actl)
E 4
I 4
	/*
	 * Request is at/after the current request...
	 * sort in the first request list.
	 */
	while (ap->av_forw) {
		/*
		 * We want to go after the current request
		 * if there is an inversion after it (i.e. it is
		 * the end of the first request list), or if
		 * the next request is a larger cylinder than our request.
		 */
		if (ap->av_forw->b_cylin < ap->b_cylin ||
D 13
		    bp->b_cylin < ap->av_forw->b_cylin)
E 13
I 13
		    bp->b_cylin < ap->av_forw->b_cylin ||
		    (bp->b_cylin == ap->av_forw->b_cylin &&
		    bp->b_blkno < ap->av_forw->b_blkno))
E 13
			goto insert;
		ap = ap->av_forw;
	}
	/*
	 * Neither a second list nor a larger
	 * request... we go at the end of the first list,
	 * which is the same as the end of the whole schebang.
	 */
insert:
	bp->av_forw = ap->av_forw;
	ap->av_forw = bp;
	if (ap == dp->b_actl)
E 4
		dp->b_actl = bp;
I 11
}

/*
 * Attempt to read a disk label from a device
 * using the indicated stategy routine.
 * The label must be partly set up before this:
 * secpercyl and anything required in the strategy routine
 * (e.g., sector size) must be filled in before calling us.
 * Returns null on success and an error string on failure.
 */
char *
readdisklabel(dev, strat, lp)
	dev_t dev;
	int (*strat)();
	register struct disklabel *lp;
{
	register struct buf *bp;
	struct disklabel *dlp;
	char *msg = NULL;

	if (lp->d_secperunit == 0)
		lp->d_secperunit = 0x1fffffff;
	lp->d_npartitions = 1;
	if (lp->d_partitions[0].p_size == 0)
		lp->d_partitions[0].p_size = 0x1fffffff;
	lp->d_partitions[0].p_offset = 0;

D 12
	bp = geteblk(DEV_BSIZE);		/* max sector size */
E 12
I 12
D 14
	bp = geteblk(lp->d_secsize);
E 14
I 14
	bp = geteblk((int)lp->d_secsize);
E 14
E 12
	bp->b_dev = dev;
	bp->b_blkno = LABELSECTOR;
D 12
	bp->b_bcount = DEV_BSIZE;
E 12
I 12
	bp->b_bcount = lp->d_secsize;
E 12
	bp->b_flags = B_BUSY | B_READ;
	bp->b_cylin = LABELSECTOR / lp->d_secpercyl;
	(*strat)(bp);
	biowait(bp);
	if (bp->b_flags & B_ERROR) {
		u.u_error = 0;		/* XXX */
		msg = "I/O error";
D 12
	} else {
		dlp = (struct disklabel *)(bp->b_un.b_addr + LABELOFFSET);
		if (dlp->d_magic != DISKMAGIC || dlp->d_magic2 != DISKMAGIC)
			msg = "no disk label";
		else if (dkcksum(dlp) != 0)
E 12
I 12
	} else for (dlp = (struct disklabel *)bp->b_un.b_addr;
	    dlp <= (struct disklabel *)(bp->b_un.b_addr+DEV_BSIZE-sizeof(*dlp));
	    dlp = (struct disklabel *)((char *)dlp + sizeof(long))) {
		if (dlp->d_magic != DISKMAGIC || dlp->d_magic2 != DISKMAGIC) {
			if (msg == NULL)
				msg = "no disk label";
		} else if (dkcksum(dlp) != 0)
E 12
			msg = "disk label corrupted";
D 12
		else
E 12
I 12
		else {
E 12
			*lp = *dlp;
I 12
			msg = NULL;
			break;
		}
E 12
	}
I 12
	if (lp->d_npartitions > MAXPARTITIONS)
		lp->d_npartitions = MAXPARTITIONS;
E 12
	bp->b_flags = B_INVAL | B_AGE;
	brelse(bp);
	return (msg);
I 13
}

/*
 * Check new disk label for sensibility
 * before setting it.
 */
setdisklabel(olp, nlp, openmask)
	register struct disklabel *olp, *nlp;
	u_long openmask;
{
	register i;
	register struct partition *opp, *npp;

	if (nlp->d_magic != DISKMAGIC || nlp->d_magic2 != DISKMAGIC ||
	    dkcksum(nlp) != 0)
		return (EINVAL);
D 15
	while ((i = ffs(openmask)) != 0) {
E 15
I 15
	while ((i = ffs((long)openmask)) != 0) {
E 15
		i--;
		openmask &= ~(1 << i);
		if (nlp->d_npartitions <= i)
			return (EBUSY);
		opp = &olp->d_partitions[i];
		npp = &nlp->d_partitions[i];
		if (npp->p_offset != opp->p_offset || npp->p_size < opp->p_size)
			return (EBUSY);
		/*
		 * Copy internally-set partition information
		 * if new label doesn't include it.		XXX
		 */
		if (npp->p_fstype == FS_UNUSED && opp->p_fstype != FS_UNUSED) {
			npp->p_fstype = opp->p_fstype;
			npp->p_fsize = opp->p_fsize;
			npp->p_frag = opp->p_frag;
			npp->p_cpg = opp->p_cpg;
		}
	}
I 14
 	nlp->d_checksum = 0;
 	nlp->d_checksum = dkcksum(nlp);
E 14
	*olp = *nlp;
	return (0);
}

/* encoding of disk minor numbers, should be elsewhere... */
#define dkunit(dev)		(minor(dev) >> 3)
#define dkpart(dev)		(minor(dev) & 07)
#define dkminor(unit, part)	(((unit) << 3) | (part))

/*
 * Write disk label back to device after modification.
 */
writedisklabel(dev, strat, lp)
	dev_t dev;
	int (*strat)();
	register struct disklabel *lp;
{
	struct buf *bp;
	struct disklabel *dlp;
	int labelpart;
	int error = 0;

	labelpart = dkpart(dev);
	if (lp->d_partitions[labelpart].p_offset != 0) {
		if (lp->d_partitions[0].p_offset != 0)
			return (EXDEV);			/* not quite right */
		labelpart = 0;
	}
D 14
	bp = geteblk(lp->d_secsize);
E 14
I 14
	bp = geteblk((int)lp->d_secsize);
E 14
	bp->b_dev = makedev(major(dev), dkminor(dkunit(dev), labelpart));
	bp->b_blkno = LABELSECTOR;
	bp->b_bcount = lp->d_secsize;
	bp->b_flags = B_READ;
	(*strat)(bp);
	biowait(bp);
	if (bp->b_flags & B_ERROR) {
		error = u.u_error;		/* XXX */
		u.u_error = 0;
D 14
		goto bad;
E 14
I 14
		goto done;
E 14
	}
D 14
	dlp = (struct disklabel *)(bp->b_un.b_addr + LABELOFFSET);
	*dlp = *lp;
	bp->b_flags = B_WRITE;
	(*strat)(bp); biowait(bp);
	biowait(bp);
	if (bp->b_flags & B_ERROR) {
		error = u.u_error;		/* XXX */
		u.u_error = 0;
E 14
I 14
	for (dlp = (struct disklabel *)bp->b_un.b_addr;
	    dlp <= (struct disklabel *)
	      (bp->b_un.b_addr + lp->d_secsize - sizeof(*dlp));
	    dlp = (struct disklabel *)((char *)dlp + sizeof(long))) {
		if (dlp->d_magic == DISKMAGIC && dlp->d_magic2 == DISKMAGIC &&
		    dkcksum(dlp) == 0) {
			*dlp = *lp;
			bp->b_flags = B_WRITE;
			(*strat)(bp);
			biowait(bp);
			if (bp->b_flags & B_ERROR) {
				error = u.u_error;		/* XXX */
				u.u_error = 0;
			}
			goto done;
		}
E 14
	}
D 14
bad:
E 14
I 14
	error = ESRCH;
done:
E 14
	brelse(bp);
	return (error);
E 13
E 11
I 10
}

/*
 * Compute checksum for disk label.
 */
dkcksum(lp)
	register struct disklabel *lp;
{
	register u_short *start, *end;
	register u_short sum = 0;

	start = (u_short *)lp;
	end = (u_short *)&lp->d_partitions[lp->d_npartitions];
	while (start < end)
		sum ^= *start++;
	return (sum);
I 16
}

/*
 * Disk error is the preface to plaintive error messages
 * about failing disk transfers.  It prints messages of the form
D 17
 *	"hp0g: hard error reading fsbn 12345 of 12344-12347 (hp0 bn 812345)"
E 17
I 17

hp0g: hard error reading fsbn 12345 of 12344-12347 (hp0 bn %d cn %d tn %d sn %d)

E 17
 * if the offset of the error in the transfer and a disk label
 * are both available.  blkdone should be -1 if the position of the error
 * is unknown; the disklabel pointer may be null from drivers that have not
 * been converted to use them.  The message is printed with printf
 * if pri is LOG_PRINTF, otherwise it uses log at the specified priority.
 * The message should be completed (with at least a newline) with printf
 * or addlog, respectively.  There is no trailing space.
 */
diskerr(bp, dname, what, pri, blkdone, lp)
	register struct buf *bp;
	char *dname, *what;
	int pri, blkdone;
	register struct disklabel *lp;
{
	int unit = dkunit(bp->b_dev), part = dkpart(bp->b_dev);
	register int (*pr)(), sn;
	char partname = 'a' + part;
	extern printf(), addlog();

	if (pri != LOG_PRINTF) {
		log(pri, "");
		pr = addlog;
	} else
		pr = printf;
	(*pr)("%s%d%c: %s %sing fsbn ", dname, unit, partname, what,
	    bp->b_flags & B_READ ? "read" : "writ");
	sn = bp->b_blkno;
	if (bp->b_bcount <= DEV_BSIZE)
		(*pr)("%d", sn);
	else {
		if (blkdone >= 0) {
			sn += blkdone;
			(*pr)("%d of ", sn);
		}
		(*pr)("%d-%d", bp->b_blkno,
		    bp->b_blkno + (bp->b_bcount - 1) / DEV_BSIZE);
	}
D 18
	if (lp && (blkdone >= 0 || bp->b_bcount <= DEV_BSIZE)) {
E 18
I 18
	if (lp && (blkdone >= 0 || bp->b_bcount <= lp->d_secsize)) {
#ifdef tahoe
		sn *= DEV_BSIZE / lp->d_secsize;		/* XXX */
#endif
E 18
		sn += lp->d_partitions[part].p_offset;
D 17
		(*pr)(" (%s%d bn %d) ", dname, unit, sn);
		/* could log cyl/trk/sect */
E 17
I 17
		(*pr)(" (%s%d bn %d; cn %d", dname, unit, sn,
		    sn / lp->d_secpercyl);
		sn %= lp->d_secpercyl;
D 19
		(*pr)(" tn %d sn %d)", sn / lp->d_ntracks, sn % lp->d_ntracks);
E 19
I 19
		(*pr)(" tn %d sn %d)", sn / lp->d_nsectors, sn % lp->d_nsectors);
E 19
E 17
	}
E 16
E 10
}
E 1
