h17611
s 00003/00003/00509
d D 7.3 88/01/26 22:10:16 mckusick 39 37
c use new definition of ENDIAN
e
s 00000/00000/00512
d R 7.3 88/01/26 22:09:01 mckusick 38 37
c reuse of ENDIAN
e
s 00004/00005/00508
d D 7.2 86/11/03 12:00:35 karels 37 36
c merge in tahoe support
e
s 00001/00001/00512
d D 7.1 86/06/05 00:10:26 mckusick 36 35
c 4.3BSD release version
e
s 00040/00027/00473
d D 6.11 86/02/20 15:58:57 karels 35 34
c cleanups from Sam: format, spl's, ptrace defs
e
s 00007/00001/00493
d D 6.10 85/06/08 14:47:32 mckusick 34 33
c Add copyright
e
s 00000/00001/00494
d D 6.9 85/03/19 20:49:05 mckusick 33 32
c eliminate extraneous include of conf.h
e
s 00001/00000/00494
d D 6.8 84/12/21 13:57:37 bloom 32 31
c include ioctl.h
e
s 00136/00067/00358
d D 6.7 84/12/20 14:38:54 karels 31 30
c more bcopies (from Peter Collinson)
e
s 00010/00010/00415
d D 6.6 84/11/15 14:59:04 sam 30 29
c I'm so fastidious (clean up after tef)
e
s 00027/00023/00398
d D 6.5 84/11/15 01:41:52 tef 29 28
c Oh yea, right.  Now put in the code changes to correspond to
c to the last delta's comment.
e
s 00000/00000/00421
d D 6.4 84/11/15 01:13:08 tef 28 27
c Move output chars from buffer to clist(s) with bcopy for efficiency.
e
s 00006/00006/00415
d D 6.3 84/08/29 20:24:44 bloom 27 26
c Change to includes.  no more ../h
e
s 00000/00002/00421
d D 6.2 84/07/29 18:39:02 sam 26 25
c q_to_b now used by pty routines
e
s 00000/00000/00423
d D 6.1 83/07/29 06:39:59 sam 25 24
c 4.2 distribution
e
s 00016/00015/00407
d D 4.20 83/05/27 12:48:54 sam 24 23
c merge of bill's code plus lint (plus, of course, cleanup of bill's bugs)
e
s 00001/00005/00421
d D 4.19 83/02/06 16:53:45 eric 23 22
c delete unnecessary "neg q flush" message from ndflush
e
s 00028/00019/00398
d D 4.18 82/12/17 11:47:42 sam 22 21
c sun merge
e
s 00003/00000/00414
d D 4.17 82/11/13 22:51:53 sam 21 20
c merge of 4.1b and 4.1c
e
s 00002/00005/00412
d D 4.16 82/10/31 01:02:21 root 20 19
c drop conditionals on NDMC
e
s 00001/00001/00416
d D 4.15 82/03/14 14:26:10 root 19 18
c #if 0 -> #if notdef
e
s 00002/00003/00415
d D 4.14 82/02/08 23:23:54 root 18 17
c getw and putw needed by if_dmc.c
e
s 00004/00000/00414
d D 4.13 81/11/20 14:43:23 wnj 17 16
c more lint
e
s 00000/00000/00414
d D 4.12 81/10/11 13:02:29 wnj 16 15
c first bootable version
e
s 00008/00008/00406
d D 4.11 81/04/17 17:54:23 wnj 15 14
c remove spurious high ipl's
e
s 00001/00001/00413
d D 4.10 81/03/09 01:48:11 wnj 14 13
c lint and a few minor fixed
e
s 00002/00027/00412
d D 4.9 81/03/09 00:33:08 wnj 13 12
c lint
e
s 00000/00104/00439
d D 4.8 81/03/03 11:07:37 wnj 12 11
c drop unused routines
e
s 00001/00033/00542
d D 4.7 81/02/26 23:56:47 wnj 11 10
c use header file; cinit to main()
e
s 00000/00001/00575
d D 4.6 81/02/26 01:24:19 wnj 10 9
c get rid of #include "tr.h"
e
s 00001/00001/00575
d D 4.5 81/02/01 18:01:28 wnj 9 8
c UCBIPC crud
e
s 00001/00000/00575
d D 4.4 80/12/20 01:14:01 wnj 8 7
c #include "tr.h"
e
s 00002/00000/00573
d D 4.3 80/12/16 16:02:48 wnj 7 6
c add back sccs id stuff
e
s 00215/00045/00358
d D 4.2 80/12/16 15:58:22 wnj 6 5
c comet changes
e
s 00000/00000/00403
d D 4.1 80/11/09 17:32:25 bill 5 4
c minor fixups to restart stuff; version 4.1 for distrib
e
s 00001/00001/00402
d D 3.4 80/06/07 02:46:57 bill 4 3
c %H%->%G%
e
s 00085/00005/00318
d D 3.3 80/05/15 17:00:29 bill 3 2
c new primitives for new tty
e
s 00002/00002/00321
d D 3.2 80/05/08 10:22:32 bill 2 1
c VOID=>void
e
s 00323/00000/00000
d D 3.1 80/04/09 16:03:56 bill 1 0
c date and time created 80/04/09 16:03:56 by bill
e
u
U
t
T
I 7
D 14
/*	%M%	%I%	%G%	*/
E 14
I 14
D 34
/*	%M%	%I%	%E%	*/
E 34
I 34
/*
D 36
 * Copyright (c) 1982 Regents of the University of California.
E 36
I 36
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 36
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 34
E 14

E 7
I 1
D 4
/*	%M%	%I%	%H%	*/
E 4
I 4
D 6
/*	%M%	%I%	%G%	*/
E 4

E 6
D 27
#include "../h/param.h"
D 6
#include "../h/tty.h"
E 6
#include "../h/systm.h"
#include "../h/conf.h"
#include "../h/buf.h"
I 6
#include "../h/tty.h"
I 11
#include "../h/clist.h"
E 27
I 27
#include "param.h"
#include "systm.h"
D 33
#include "conf.h"
E 33
#include "buf.h"
I 32
#include "ioctl.h"
E 32
#include "tty.h"
#include "clist.h"
E 27
E 11
I 8
D 10
#include "tr.h"
E 10
E 8
E 6

D 11
struct cblock {
D 6
	struct cblock *c_next;
E 6
I 6
	struct	cblock *c_next;
E 6
	char	c_info[CBSIZE];
};

D 6
struct	cblock	cfree[NCLIST];
I 3
int	cbad;
E 3
struct	cblock	*cfreelist;
E 6
I 6
struct	cblock cfree[NCLIST];
struct	cblock *cfreelist;
E 6

I 6
int	cfreecount;
E 11
char	cwaiting;

E 6
/*
 * Character list get/put
 */
getc(p)
D 24
register struct clist *p;
E 24
I 24
	register struct clist *p;
E 24
{
	register struct cblock *bp;
	register int c, s;

D 15
	s = spl6();
E 15
I 15
D 31
	s = spl5();
E 31
I 31
	s = spltty();
E 31
E 15
	if (p->c_cc <= 0) {
		c = -1;
		p->c_cc = 0;
		p->c_cf = p->c_cl = NULL;
	} else {
		c = *p->c_cf++ & 0377;
		if (--p->c_cc<=0) {
			bp = (struct cblock *)(p->c_cf-1);
D 35
			bp = (struct cblock *) ((int)bp & ~CROUND);
E 35
I 35
			bp = (struct cblock *)((int)bp & ~CROUND);
E 35
			p->c_cf = NULL;
			p->c_cl = NULL;
			bp->c_next = cfreelist;
			cfreelist = bp;
I 6
			cfreecount += CBSIZE;
			if (cwaiting) {
				wakeup(&cwaiting);
				cwaiting = 0;
			}
E 6
		} else if (((int)p->c_cf & CROUND) == 0){
			bp = (struct cblock *)(p->c_cf);
			bp--;
			p->c_cf = bp->c_next->c_info;
			bp->c_next = cfreelist;
			cfreelist = bp;
I 6
			cfreecount += CBSIZE;
			if (cwaiting) {
				wakeup(&cwaiting);
				cwaiting = 0;
			}
E 6
		}
	}
	splx(s);
D 35
	return(c);
E 35
I 35
	return (c);
E 35
}

I 24
D 26
#ifdef notdef
E 26
E 24
I 17
D 19
#if 0
E 19
I 19
D 22
#if notdef
E 22
E 19
E 17
I 6
D 12
#if HAVTR > 0
trgetc(p)
register struct clist *p;
{
	register struct cblock *bp;
	register int c, s;

	if (p->c_cc <= 0) {
		c = -1;
		p->c_cc = 0;
		p->c_cf = NULL;
	} else {
		c = *p->c_cf++ & 0377;
		if (--p->c_cc<=0) {
			p->c_cf = NULL;
		} else if (((int)p->c_cf & CROUND) == 0) {
			bp = (struct cblock *)(p->c_cf);
			bp--;
			p->c_cf = bp->c_next->c_info;
		}
	}
	return(c);
}
#endif

E 12
E 6
/*
 * copy clist to buffer.
 * return number of bytes moved.
 */
q_to_b(q, cp, cc)
D 22
register struct clist *q;
register char *cp;
E 22
I 22
	register struct clist *q;
	register char *cp;
E 22
{
	register struct cblock *bp;
	register int s;
I 31
	register nc;
E 31
	char *acp;

	if (cc <= 0)
D 35
		return(0);
E 35
I 35
		return (0);
E 35
D 15
	s = spl6();
E 15
I 15
D 31
	s = spl5();
E 31
I 31
	s = spltty();
E 31
E 15
	if (q->c_cc <= 0) {
		q->c_cc = 0;
		q->c_cf = q->c_cl = NULL;
I 6
		splx(s);
E 6
D 35
		return(0);
E 35
I 35
		return (0);
E 35
	}
	acp = cp;
D 31
	cc++;
E 31

D 31
	while (--cc) {
		*cp++ = *q->c_cf++;
		if (--q->c_cc <= 0) {
			bp = (struct cblock *)(q->c_cf-1);
E 31
I 31
	while (cc) {
D 35
		nc = sizeof(struct cblock) - ((int)q->c_cf & CROUND);
E 35
I 35
		nc = sizeof (struct cblock) - ((int)q->c_cf & CROUND);
E 35
		nc = MIN(nc, cc);
		nc = MIN(nc, q->c_cc);
		(void) bcopy(q->c_cf, cp, (unsigned)nc);
		q->c_cf += nc;
		q->c_cc -= nc;
		cc -= nc;
		cp += nc;
		if (q->c_cc <= 0) {
			bp = (struct cblock *)(q->c_cf - 1);
E 31
			bp = (struct cblock *)((int)bp & ~CROUND);
			q->c_cf = q->c_cl = NULL;
			bp->c_next = cfreelist;
			cfreelist = bp;
I 6
			cfreecount += CBSIZE;
			if (cwaiting) {
				wakeup(&cwaiting);
				cwaiting = 0;
			}
E 6
			break;
		}
		if (((int)q->c_cf & CROUND) == 0) {
			bp = (struct cblock *)(q->c_cf);
			bp--;
			q->c_cf = bp->c_next->c_info;
			bp->c_next = cfreelist;
			cfreelist = bp;
I 6
			cfreecount += CBSIZE;
			if (cwaiting) {
				wakeup(&cwaiting);
				cwaiting = 0;
			}
E 6
		}
	}
	splx(s);
D 35
	return(cp-acp);
E 35
I 35
	return (cp-acp);
E 35
}
I 24
D 26
#endif
E 26
E 24
I 17
D 22
#endif
E 22
E 17

I 6
D 12
#if HAVTR > 0
E 12
E 6
D 3

E 3
/*
I 6
D 12
 * Traverse a clist copying its contents to a buffer.
 * q->cc and q->cf are updated with the current position
 * in the list, but bytes are not released to the freelist.
 */
trq_to_b(q, cp, cc)
register struct clist *q;
register char *cp;
register cc;
{
	register struct cblock *bp;
	char *acp;

	if (cc <= 0)
		return(0);
	if (q->c_cc <= 0)
		return(0);

	acp = cp;
	cc++;
	while (--cc) {
		*cp++ = *q->c_cf++;
		if (((int)q->c_cf & CROUND) == 0) {
			bp = (struct cblock *)(q->c_cf);
			bp--;
			q->c_cf = bp->c_next->c_info;
		}
		if (--q->c_cc <= 0)
			break;
	}
	return(cp-acp);
}
#endif


/*
E 12
E 6
 * Return count of contiguous characters
 * in clist starting at q->c_cf.
 * Stop counting if flag&character is non-null.
 */
ndqb(q, flag)
D 22
register struct clist *q;
E 22
I 22
	register struct clist *q;
E 22
{
D 22
register cc;
int s;
E 22
I 22
	register cc;
	int s;
E 22

D 15
	s = spl6();
E 15
I 15
D 31
	s = spl5();
E 31
I 31
	s = spltty();
E 31
E 15
	if (q->c_cc <= 0) {
		cc = -q->c_cc;
		goto out;
	}
	cc = ((int)q->c_cf + CBSIZE) & ~CROUND;
	cc -= (int)q->c_cf;
	if (q->c_cc < cc)
		cc = q->c_cc;
	if (flag) {
		register char *p, *end;

		p = q->c_cf;
		end = p;
		end += cc;
		while (p < end) {
			if (*p & flag) {
D 6
				cc = (int)p - (int)q->c_cf;
E 6
I 6
				cc = (int)p;
				cc -= (int)q->c_cf;
E 6
				break;
			}
			p++;
		}
	}
out:
	splx(s);
D 35
	return(cc);
E 35
I 35
	return (cc);
E 35
}

I 6
D 35


E 35
E 6
D 3


E 3
/*
D 6
 * Update clist to show that cc characters
 * were removed.  It is assumed that cc < CBSIZE.
E 6
I 6
 * Flush cc bytes from q.
E 6
 */
ndflush(q, cc)
D 24
register struct clist *q;
register cc;
E 24
I 24
	register struct clist *q;
	register cc;
E 24
{
I 6
D 24
register struct cblock *bp;
char *end;
int rem;
E 6
register s;
E 24
I 24
	register struct cblock *bp;
	char *end;
	int rem, s;
E 24

D 6
	if (cc == 0)
		return;
E 6
D 15
	s = spl6();
E 15
I 15
D 31
	s = spl5();
E 31
I 31
	s = spltty();
E 31
E 15
D 23
	if (q->c_cc < 0) {
D 6
		if (q->c_cf != NULL) {
			q->c_cc += cc;
			q->c_cf += cc;
			goto out;
		}
		q->c_cc = 0;
E 6
I 6
		printf("neg q flush\n");
E 6
		goto out;
	}
	if (q->c_cc == 0) {
E 23
I 23
D 35
	if (q->c_cc <= 0) {
E 35
I 35
	if (q->c_cc <= 0)
E 35
E 23
		goto out;
D 35
	}
E 35
I 3
D 6
	if (cc > CBSIZE || cc <= 0) {
		cbad++;
		goto out;
	}
E 3
	q->c_cc -= cc;
	q->c_cf += cc;
	if (((int)q->c_cf & CROUND) == 0) {
		register struct cblock *bp;

		bp = (struct cblock *)(q->c_cf) -1;
		if (bp->c_next) {
E 6
I 6
	while (cc>0 && q->c_cc) {
		bp = (struct cblock *)((int)q->c_cf & ~CROUND);
		if ((int)bp == (((int)q->c_cl-1) & ~CROUND)) {
			end = q->c_cl;
		} else {
			end = (char *)((int)bp + sizeof (struct cblock));
		}
		rem = end - q->c_cf;
		if (cc >= rem) {
			cc -= rem;
			q->c_cc -= rem;
E 6
			q->c_cf = bp->c_next->c_info;
I 6
			bp->c_next = cfreelist;
			cfreelist = bp;
			cfreecount += CBSIZE;
			if (cwaiting) {
				wakeup(&cwaiting);
				cwaiting = 0;
			}
E 6
		} else {
D 6
			q->c_cf = q->c_cl = NULL;
E 6
I 6
			q->c_cc -= cc;
			q->c_cf += cc;
			if (q->c_cc <= 0) {
				bp->c_next = cfreelist;
				cfreelist = bp;
				cfreecount += CBSIZE;
				if (cwaiting) {
					wakeup(&cwaiting);
					cwaiting = 0;
				}
			}
			break;
E 6
		}
D 6
		bp->c_next = cfreelist;
		cfreelist = bp;
	} else
	if (q->c_cc == 0) {
		register struct cblock *bp;
		q->c_cf = (char *)((int)q->c_cf & ~CROUND);
		bp = (struct cblock *)(q->c_cf);
		bp->c_next = cfreelist;
		cfreelist = bp;
E 6
I 6
	}
	if (q->c_cc <= 0) {
E 6
		q->c_cf = q->c_cl = NULL;
I 6
		q->c_cc = 0;
E 6
	}
out:
	splx(s);
}
I 3

D 6
/*
 * Put character c in queue p.
 */
E 6
I 6

E 6
E 3
putc(c, p)
D 24
register struct clist *p;
E 24
I 24
	register struct clist *p;
E 24
{
	register struct cblock *bp;
	register char *cp;
	register s;

D 15
	s = spl6();
E 15
I 15
D 31
	s = spl5();
E 31
I 31
	s = spltty();
E 31
E 15
	if ((cp = p->c_cl) == NULL || p->c_cc < 0 ) {
		if ((bp = cfreelist) == NULL) {
			splx(s);
D 35
			return(-1);
E 35
I 35
			return (-1);
E 35
		}
		cfreelist = bp->c_next;
I 6
		cfreecount -= CBSIZE;
E 6
		bp->c_next = NULL;
		p->c_cf = cp = bp->c_info;
	} else if (((int)cp & CROUND) == 0) {
		bp = (struct cblock *)cp - 1;
		if ((bp->c_next = cfreelist) == NULL) {
			splx(s);
D 35
			return(-1);
E 35
I 35
			return (-1);
E 35
		}
		bp = bp->c_next;
		cfreelist = bp->c_next;
I 6
		cfreecount -= CBSIZE;
E 6
		bp->c_next = NULL;
		cp = bp->c_info;
	}
	*cp++ = c;
	p->c_cc++;
	p->c_cl = cp;
	splx(s);
D 35
	return(0);
E 35
I 35
	return (0);
E 35
}

I 6
D 35


E 35
E 6
D 3


E 3
/*
 * copy buffer to clist.
 * return number of bytes not transfered.
 */
b_to_q(cp, cc, q)
D 24
register char *cp;
struct clist *q;
register int cc;
E 24
I 24
	register char *cp;
	struct clist *q;
	register int cc;
E 24
{
	register char *cq;
	register struct cblock *bp;
D 31
	register s, acc;
E 31
I 31
	register s, nc;
	int acc;
E 31

	if (cc <= 0)
D 30
		return(0);
D 29
	acc = cc;
E 29
I 6

E 30
I 30
D 31
		return (0);
E 30
D 29

E 6
D 15
	s = spl6();
E 15
I 15
	s = spl5();
E 15
	if ((cq = q->c_cl) == NULL || q->c_cc < 0) {
		if ((bp = cfreelist) == NULL) 
			goto out;
		cfreelist = bp->c_next;
I 6
		cfreecount -= CBSIZE;
E 6
		bp->c_next = NULL;
		q->c_cf = cq = bp->c_info;
	}

	while (cc) {
E 29
I 29
	while (cc > 0) {
		s = spl6();
		if ((cq = q->c_cl) == NULL || q->c_cc < 0) {
			if ((bp = cfreelist) == NULL) {
				splx(s);
				break;
			}
			q->c_cf = cq = bp->c_info;
			goto middle;
		}
E 31
I 31
D 35
		return(0);
E 35
I 35
		return (0);
E 35
	acc = cc;
	s = spltty();
	if ((cq = q->c_cl) == NULL || q->c_cc < 0) {
		if ((bp = cfreelist) == NULL) 
			goto out;
		cfreelist = bp->c_next;
		cfreecount -= CBSIZE;
		bp->c_next = NULL;
		q->c_cf = cq = bp->c_info;
	}

	while (cc) {
E 31
E 29
		if (((int)cq & CROUND) == 0) {
D 29
			bp = (struct cblock *) cq - 1;
			if ((bp->c_next = cfreelist) == NULL) 
				goto out;
E 29
I 29
D 30
			bp = &((struct cblock *) cq)[-1];
E 30
I 30
D 31
			bp = &((struct cblock *)cq)[-1];
E 30
			if ((bp->c_next = cfreelist) == NULL) {
				splx(s);
				break;
			}
E 31
I 31
D 35
			bp = (struct cblock *) cq - 1;
E 35
I 35
			bp = (struct cblock *)cq - 1;
E 35
			if ((bp->c_next = cfreelist) == NULL) 
				goto out;
E 31
E 29
			bp = bp->c_next;
I 29
D 31
			cq = bp->c_info;
D 30
		middle:
E 30
I 30
	middle:
E 31
E 30
E 29
			cfreelist = bp->c_next;
I 6
			cfreecount -= CBSIZE;
E 6
			bp->c_next = NULL;
D 29
			cq = bp->c_info;
E 29
I 29
D 30
			acc = MIN (cc, CBSIZE);
E 30
I 30
D 31
			acc = MIN(cc, CBSIZE);
		} else {
			acc = (char *)((int)&cq[CBSIZE] &~ CROUND) - cq;
			if (acc > cc)
				acc = cc;
E 31
I 31
			cq = bp->c_info;
E 31
E 30
E 29
		}
D 29
		*cq++ = *cp++;
		cc--;
E 29
I 29
D 30
		else if ((acc = (char *) ((int) &cq[CBSIZE] & ~CROUND) - cq)
			      > cc)
			acc = cc;
		bcopy ((caddr_t)cp, cq, acc);
E 30
I 30
D 31
		bcopy((caddr_t)cp, cq, acc);
E 30
		q->c_cl = &cq[acc];
		q->c_cc += acc;
		splx(s);
		cp += acc;
		cc -= acc;
E 31
I 31
D 35
		nc = MIN(cc, sizeof(struct cblock) - ((int)cq & CROUND));
E 35
I 35
		nc = MIN(cc, sizeof (struct cblock) - ((int)cq & CROUND));
E 35
		(void) bcopy(cp, cq, (unsigned)nc);
		cp += nc;
		cq += nc;
		cc -= nc;
E 31
E 29
	}
I 31
out:
	q->c_cl = cq;
	q->c_cc += acc - cc;
	splx(s);
E 31
D 29
out:
	q->c_cl = cq;
	q->c_cc += acc-cc;
	splx(s);
E 29
D 30
	return(cc);
E 30
I 30
	return (cc);
E 30
I 3
}

I 6
D 13
char *
wb_to_q(cp, cc, q)
register char *cp;
register struct clist *q;
register cc;
{
char *f;
register s;

	s = spl6();
	while (cc > cfreecount) {
		cwaiting = 1;
		sleep(&cwaiting, TTOPRI);
	}
	if (q->c_cc==0) {
		b_to_q(cp, cc, q);
		f = q->c_cf;
	} else {
		(void) putc(*cp++, q);
		f = q->c_cl;
		f--;
		b_to_q(cp, --cc, q);
	}
	splx(s);
	return(f);
}

E 13
D 9
#ifdef notdef
E 9
I 9
D 12
#ifdef UCBIPC
E 9
char *
nb_to_q(cp, cc, q)
register char *cp;
register struct clist *q;
register cc;
{
char *f;
register s;

	s = spl6();
	if (cc > cfreecount) {
		f = NULL;
		goto out;
	}
	if (q->c_cc==0) {
		b_to_q(cp, cc, q);
		f = q->c_cf;
	} else {
		(void) putc(*cp++, q);
		f = q->c_cl;
		f--;
		b_to_q(cp, --cc, q);
	}
out:
	splx(s);
	return(f);
}
#endif

E 12
E 6
/*
 * Given a non-NULL pointter into the list (like c_cf which
 * always points to a real character if non-NULL) return the pointer
 * to the next character in the list or return NULL if no more chars.
 *
 * Callers must not allow getc's to happen between nextc's so that the
 * pointer becomes invalid.  Note that interrupts are NOT masked.
 */
char *
nextc(p, cp)
D 24
register struct clist *p;
register char *cp;
E 24
I 24
	register struct clist *p;
	register char *cp;
E 24
{

	if (p->c_cc && ++cp != p->c_cl) {
		if (((int)cp & CROUND) == 0)
			return (((struct cblock *)cp)[-1].c_next->c_info);
		return (cp);
	}
	return (0);
}

/*
 * Remove the last character in the list and return it.
 */
unputc(p)
D 24
register struct clist *p;
E 24
I 24
	register struct clist *p;
E 24
{
	register struct cblock *bp;
	register int c, s;
	struct cblock *obp;

D 15
	s = spl6();
E 15
I 15
D 31
	s = spl5();
E 31
I 31
	s = spltty();
E 31
E 15
	if (p->c_cc <= 0)
		c = -1;
	else {
		c = *--p->c_cl;
		if (--p->c_cc <= 0) {
			bp = (struct cblock *)p->c_cl;
			bp = (struct cblock *)((int)bp & ~CROUND);
			p->c_cl = p->c_cf = NULL;
			bp->c_next = cfreelist;
			cfreelist = bp;
I 6
			cfreecount += CBSIZE;
E 6
		} else if (((int)p->c_cl & CROUND) == sizeof(bp->c_next)) {
			p->c_cl = (char *)((int)p->c_cl & ~CROUND);
			bp = (struct cblock *)p->c_cf;
			bp = (struct cblock *)((int)bp & ~CROUND);
			while (bp->c_next != (struct cblock *)p->c_cl)
				bp = bp->c_next;
			obp = bp;
			p->c_cl = (char *)(bp + 1);
			bp = bp->c_next;
			bp->c_next = cfreelist;
			cfreelist = bp;
I 6
			cfreecount += CBSIZE;
E 6
			obp->c_next = NULL;
		}
	}
	splx(s);
	return (c);
}

/*
 * Put the chars in the from que
 * on the end of the to que.
D 31
 *
 * SHOULD JUST USE q_to_b AND THEN b_to_q HERE.
E 31
 */
catq(from, to)
D 24
struct clist *from, *to;
E 24
I 24
	struct clist *from, *to;
E 24
{
D 31
	register c;
E 31
I 31
	char bbuf[CBSIZE*4];
	register s, c;
E 31

D 31
	while ((c = getc(from)) >= 0)
		(void) putc(c, to);
E 31
I 31
	s = spltty();
	if (to->c_cc == 0) {
		*to = *from;
		from->c_cc = 0;
		from->c_cf = NULL;
		from->c_cl = NULL;
		splx(s);
		return;
	}
	splx(s);
	while (from->c_cc > 0) {
		c = q_to_b(from, bbuf, sizeof bbuf);
		(void) b_to_q(bbuf, c, to);
	}
E 31
E 3
}
D 11

/*
 * Initialize clist by freeing all character blocks, then count
 * number of character devices. (Once-only routine)
 */
cinit()
{
	register int ccp;
	register struct cblock *cp;
	register struct cdevsw *cdp;

	ccp = (int)cfree;
	ccp = (ccp+CROUND) & ~CROUND;
D 6
	for(cp=(struct cblock *)ccp; cp <= &cfree[NCLIST-1]; cp++) {
E 6
I 6
	for(cp=(struct cblock *)ccp; cp < &cfree[NCLIST-1]; cp++) {
E 6
		cp->c_next = cfreelist;
		cfreelist = cp;
I 6
		cfreecount += CBSIZE;
E 6
	}
	ccp = 0;
	for(cdp = cdevsw; cdp->d_open; cdp++)
		ccp++;
	nchrdev = ccp;
}

E 11
I 6

I 31
#ifdef unneeded
E 31
I 21
D 22
#include "dmc.h"
#ifdef NDMC > 0
E 22
E 21
I 18
D 20
#include "dmc.h"
#if NDMC > 0
E 20
E 18
E 6
/*
D 22
 * integer (2-byte) get/put
E 22
I 22
D 35
 * Integer (short) get/put
E 22
 * using clists
E 35
I 35
 * Integer (short) get/put using clists.
D 37
 * Note dependency on byte order.
E 37
E 35
 */
I 22
D 31
typedef	short word_t;
union chword {
	word_t	word;
	struct {
		char	Ch[sizeof (word_t)];
	} Cha;
#define	ch	Cha.Ch
};
E 31
I 31
typedef	u_short word_t;
E 31

E 22
I 13
D 18
#ifdef unneeded
E 18
E 13
D 6
/*
E 6
getw(p)
D 20
register struct clist *p;
E 20
I 20
	register struct clist *p;
E 20
{
D 22
	register int s;
E 22
I 22
D 31
	register int i;
	union chword x;
E 31
I 31
	register int s, c;
	register struct cblock *bp;
E 31
E 22

D 22
	if (p->c_cc <= 1)
		return(-1);
	s = getc(p);
	return(s | (getc(p)<<8));
E 22
I 22
D 31
	if (p->c_cc < sizeof (word_t))
		return (-1);
	for (i = 0; i < sizeof (word_t); i++)
		x.ch[i] = getc(p);
	return (x.word);
E 31
I 31
	if (p->c_cc <= 1)
		return(-1);
	if (p->c_cc & 01) {
		c = getc(p);
D 35
		return(c | (getc(p)<<8));
E 35
I 35
D 37
#if defined(vax)
E 37
I 37
D 39
#if ENDIAN == LITTLE
E 39
I 39
#if BYTE_ORDER == LITTLE_ENDIAN
E 39
E 37
		return (c | (getc(p)<<8));
#else
		return (getc(p) | (c<<8));
#endif
E 35
	}
	s = spltty();
I 35
D 37
#if defined(vax)
E 35
	c = *((word_t *)p->c_cf);
E 37
I 37
D 39
#if ENDIAN == LITTLE
E 39
I 39
#if BYTE_ORDER == LITTLE_ENDIAN
E 39
	c = (((u_char *)p->c_cf)[0] << 8) | ((u_char *)p->c_cf)[1];
E 37
D 35
	p->c_cf += sizeof(word_t);
	p->c_cc -= sizeof(word_t);
E 35
I 35
#else
	c = (((u_char *)p->c_cf)[1] << 8) | ((u_char *)p->c_cf)[0];
#endif
	p->c_cf += sizeof (word_t);
	p->c_cc -= sizeof (word_t);
E 35
	if (p->c_cc <= 0) {
		bp = (struct cblock *)(p->c_cf-1);
D 35
		bp = (struct cblock *) ((int)bp & ~CROUND);
E 35
I 35
		bp = (struct cblock *)((int)bp & ~CROUND);
E 35
		p->c_cf = NULL;
		p->c_cl = NULL;
		bp->c_next = cfreelist;
		cfreelist = bp;
		cfreecount += CBSIZE;
		if (cwaiting) {
			wakeup(&cwaiting);
			cwaiting = 0;
		}
	} else if (((int)p->c_cf & CROUND) == 0) {
		bp = (struct cblock *)(p->c_cf);
		bp--;
		p->c_cf = bp->c_next->c_info;
		bp->c_next = cfreelist;
		cfreelist = bp;
		cfreecount += CBSIZE;
		if (cwaiting) {
			wakeup(&cwaiting);
			cwaiting = 0;
		}
	}
	splx(s);
	return (c);
E 31
E 22
}
I 13
D 18
#endif
E 18
E 13
D 6
*/
E 6
I 6
D 12

#if HAVTR > 0
trgetw(p)
register struct clist *p;
{
	register int w;

	if (p->c_cc <=1)
		return(-1);
	w = trgetc(p);
	return(w | (trgetc(p)<<8));
}
#endif
E 12
E 6

I 17
D 18
#if 0
E 18
E 17
putw(c, p)
D 20
register struct clist *p;
E 20
I 20
	register struct clist *p;
I 31
	word_t c;
E 31
E 20
{
	register s;
I 22
D 31
	register int i;
	union chword x;
E 31
I 31
	register struct cblock *bp;
	register char *cp;
E 31
E 22

D 15
	s = spl6();
E 15
I 15
D 31
	s = spl5();
E 31
I 31
	s = spltty();
E 31
E 15
	if (cfreelist==NULL) {
		splx(s);
		return(-1);
	}
D 2
	VOID putc(c, p);
	VOID putc(c>>8, p);
E 2
I 2
D 22
	(void) putc(c, p);
	(void) putc(c>>8, p);
E 22
I 22
D 31
	x.word = c;
	for (i = 0; i < sizeof (word_t); i++)
		(void) putc(x.ch[i], p);
E 31
I 31
	if (p->c_cc & 01) {
I 35
D 37
#if defined(vax)
E 37
I 37
D 39
#if ENDIAN == LITTLE
E 39
I 39
#if BYTE_ORDER == LITTLE_ENDIAN
E 39
E 37
E 35
		(void) putc(c, p);
		(void) putc(c>>8, p);
I 35
#else
		(void) putc(c>>8, p);
		(void) putc(c, p);
#endif
E 35
	} else {
		if ((cp = p->c_cl) == NULL || p->c_cc < 0 ) {
			if ((bp = cfreelist) == NULL) {
				splx(s);
				return (-1);
			}
			cfreelist = bp->c_next;
			cfreecount -= CBSIZE;
			bp->c_next = NULL;
			p->c_cf = cp = bp->c_info;
		} else if (((int)cp & CROUND) == 0) {
			bp = (struct cblock *)cp - 1;
			if ((bp->c_next = cfreelist) == NULL) {
				splx(s);
				return (-1);
			}
			bp = bp->c_next;
			cfreelist = bp->c_next;
			cfreecount -= CBSIZE;
			bp->c_next = NULL;
			cp = bp->c_info;
		}
I 35
#if defined(vax)
E 35
		*(word_t *)cp = c;
D 35
		p->c_cl = cp + sizeof(word_t);
		p->c_cc += sizeof(word_t);
E 35
I 35
#else
		((u_char *)cp)[0] = c>>8;
		((u_char *)cp)[1] = c;
#endif
		p->c_cl = cp + sizeof (word_t);
		p->c_cc += sizeof (word_t);
E 35
	}
E 31
E 22
E 2
	splx(s);
D 22
	return(0);
E 22
I 22
	return (0);
E 22
}
I 31
#endif unneeded
E 31
I 21
D 22
#endif
E 22
E 21
I 17
D 20
#endif
E 20
E 17
E 1
