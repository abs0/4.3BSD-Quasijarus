h04402
s 00010/00005/00208
d D 5.4 88/06/27 17:34:09 bostic 6 5
c install approved copyright notice
e
s 00009/00003/00204
d D 5.3 88/05/23 20:18:32 bostic 5 4
c added Berkeley specific header
e
s 00002/00002/00205
d D 5.2 86/03/09 19:53:05 donn 4 3
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00198
d D 5.1 85/06/05 12:30:25 mckusick 3 2
c Add copyright
e
s 00181/00103/00018
d D 4.2 83/03/09 00:50:33 mckusick 2 1
c Earl Cohen's faster version of qsort
e
s 00121/00000/00000
d D 4.1 80/12/21 16:39:59 wnj 1 0
c date and time created 80/12/21 16:39:59 by wnj
e
u
U
t
T
I 1
D 3
/* %W% (Berkeley) %G% */
E 3
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
D 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 6
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 6
I 6
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
E 6
E 5
 */

D 4
#ifndef lint
E 4
I 4
#if defined(LIBC_SCCS) && !defined(lint)
E 4
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif not lint
E 4
I 4
D 5
#endif LIBC_SCCS and not lint
E 5
I 5
#endif /* LIBC_SCCS and not lint */
E 5
E 4
E 3

D 2
static int	(*qscmp)();
static int	qses;
E 2
I 2
/*
 * qsort.c:
 * Our own version of the system qsort routine which is faster by an average
 * of 25%, with lows and highs of 10% and 50%.
 * The THRESHold below is the insertion sort threshold, and has been adjusted
 * for records of size 48 bytes.
 * The MTHREShold is where we stop finding a better median.
 */
E 2

D 2
qsort(a, n, es, fc)
char *a;
unsigned n;
int es;
int (*fc)();
{
	qscmp = fc;
	qses = es;
	qs1(a, a+n*es);
}
E 2
I 2
#define		THRESH		4		/* threshold for insertion */
#define		MTHRESH		6		/* threshold for median */
E 2

D 2
static qs1(a, l)
char *a, *l;
{
	register char *i, *j;
	register es;
	char **k;
	char *lp, *hp;
	int c;
	unsigned n;
E 2
I 2
static  int		(*qcmp)();		/* the comparison routine */
static  int		qsz;			/* size of each record */
static  int		thresh;			/* THRESHold in chars */
static  int		mthresh;		/* MTHRESHold in chars */
E 2

I 2
/*
 * qsort:
 * First, set up some global parameters for qst to share.  Then, quicksort
 * with qst(), and then a cleanup insertion sort ourselves.  Sound simple?
 * It's not...
 */
E 2

D 2
	es = qses;
E 2
I 2
qsort(base, n, size, compar)
	char	*base;
	int	n;
	int	size;
	int	(*compar)();
{
	register char c, *i, *j, *lo, *hi;
	char *min, *max;
E 2

D 2
start:
	if((n=l-a) <= es)
E 2
I 2
	if (n <= 1)
E 2
		return;
D 2
	n = es * (n / (2*es));
	hp = lp = a+n;
	i = a;
	j = l-es;
	for(;;) {
		if(i < lp) {
			if((c = (*qscmp)(i, lp)) == 0) {
				qsexc(i, lp -= es);
				continue;
			}
			if(c < 0) {
				i += es;
				continue;
			}
E 2
I 2
	qsz = size;
	qcmp = compar;
	thresh = qsz * THRESH;
	mthresh = qsz * MTHRESH;
	max = base + n * qsz;
	if (n >= THRESH) {
		qst(base, max);
		hi = base + thresh;
	} else {
		hi = max;
	}
	/*
	 * First put smallest element, which must be in the first THRESH, in
	 * the first position as a sentinel.  This is done just by searching
	 * the first THRESH elements (or the first n if n < THRESH), finding
	 * the min, and swapping it into the first position.
	 */
	for (j = lo = base; (lo += qsz) < hi; )
		if (qcmp(j, lo) > 0)
			j = lo;
	if (j != base) {
		/* swap j into place */
		for (i = base, hi = base + qsz; i < hi; ) {
			c = *j;
			*j++ = *i;
			*i++ = c;
E 2
		}
D 2

loop:
		if(j > hp) {
			if((c = (*qscmp)(hp, j)) == 0) {
				qsexc(hp += es, j);
				goto loop;
E 2
I 2
	}
	/*
	 * With our sentinel in place, we now run the following hyper-fast
	 * insertion sort.  For each remaining element, min, from [1] to [n-1],
	 * set hi to the index of the element AFTER which this one goes.
	 * Then, do the standard insertion sort shift on a character at a time
	 * basis for each element in the frob.
	 */
	for (min = base; (hi = min += qsz) < max; ) {
		while (qcmp(hi -= qsz, min) > 0)
			/* void */;
		if ((hi += qsz) != min) {
			for (lo = min + qsz; --lo >= min; ) {
				c = *lo;
				for (i = j = lo; (j -= qsz) >= hi; i = j)
					*i = *j;
				*i = c;
E 2
			}
D 2
			if(c > 0) {
				if(i == lp) {
					qstexc(i, hp += es, j);
					i = lp += es;
					goto loop;
				}
				qsexc(i, j);
				j -= es;
				i += es;
				continue;
			}
			j -= es;
			goto loop;
E 2
		}
D 2


		if(i == lp) {
			if(lp-a >= l-hp) {
				qs1(hp+es, l);
				l = lp;
			} else {
				qs1(a, lp);
				a = hp+es;
			}
			goto start;
		}


		qstexc(j, lp -= es, i);
		j = hp -= es;
E 2
	}
}

D 2
static qsexc(i, j)
char *i, *j;
{
	register char *ri, *rj, c;
	int n;
E 2
I 2
/*
 * qst:
 * Do a quicksort
 * First, find the median element, and put that one in the first place as the
 * discriminator.  (This "median" is just the median of the first, last and
 * middle elements).  (Using this median instead of the first element is a big
 * win).  Then, the usual partitioning/swapping, followed by moving the
 * discriminator into the right place.  Then, figure out the sizes of the two
 * partions, do the smaller one recursively and the larger one via a repeat of
 * this code.  Stopping when there are less than THRESH elements in a partition
 * and cleaning up with an insertion sort (in our caller) is a huge win.
 * All data swaps are done in-line, which is space-losing but time-saving.
 * (And there are only three places where this is done).
 */
E 2

D 2
	n = qses;
	ri = i;
	rj = j;
	do {
		c = *ri;
		*ri++ = *rj;
		*rj++ = c;
	} while(--n);
}

static qstexc(i, j, k)
char *i, *j, *k;
E 2
I 2
static
qst(base, max)
	char *base, *max;
E 2
{
D 2
	register char *ri, *rj, *rk;
	int c;
	int n;
E 2
I 2
	register char c, *i, *j, *jj;
	register int ii;
	char *mid, *tmp;
	int lo, hi;
E 2

D 2
	n = qses;
	ri = i;
	rj = j;
	rk = k;
	do {
		c = *ri;
		*ri++ = *rk;
		*rk++ = *rj;
		*rj++ = c;
	} while(--n);
E 2
I 2
	/*
	 * At the top here, lo is the number of characters of elements in the
	 * current partition.  (Which should be max - base).
	 * Find the median of the first, last, and middle element and make
	 * that the middle element.  Set j to largest of first and middle.
	 * If max is larger than that guy, then it's that guy, else compare
	 * max with loser of first and take larger.  Things are set up to
	 * prefer the middle, then the first in case of ties.
	 */
	lo = max - base;		/* number of elements as chars */
	do	{
		mid = i = base + qsz * ((lo / qsz) >> 1);
		if (lo >= mthresh) {
			j = (qcmp((jj = base), i) > 0 ? jj : i);
			if (qcmp(j, (tmp = max - qsz)) > 0) {
				/* switch to first loser */
				j = (j == jj ? i : jj);
				if (qcmp(j, tmp) < 0)
					j = tmp;
			}
			if (j != i) {
				ii = qsz;
				do	{
					c = *i;
					*i++ = *j;
					*j++ = c;
				} while (--ii);
			}
		}
		/*
		 * Semi-standard quicksort partitioning/swapping
		 */
		for (i = base, j = max - qsz; ; ) {
			while (i < mid && qcmp(i, mid) <= 0)
				i += qsz;
			while (j > mid) {
				if (qcmp(mid, j) <= 0) {
					j -= qsz;
					continue;
				}
				tmp = i + qsz;	/* value of i after swap */
				if (i == mid) {
					/* j <-> mid, new mid is j */
					mid = jj = j;
				} else {
					/* i <-> j */
					jj = j;
					j -= qsz;
				}
				goto swap;
			}
			if (i == mid) {
				break;
			} else {
				/* i <-> mid, new mid is i */
				jj = mid;
				tmp = mid = i;	/* value of i after swap */
				j -= qsz;
			}
		swap:
			ii = qsz;
			do	{
				c = *i;
				*i++ = *jj;
				*jj++ = c;
			} while (--ii);
			i = tmp;
		}
		/*
		 * Look at sizes of the two partitions, do the smaller
		 * one first by recursion, then do the larger one by
		 * making sure lo is its size, base and max are update
		 * correctly, and branching back.  But only repeat
		 * (recursively or by branching) if the partition is
		 * of at least size THRESH.
		 */
		i = (j = mid) + qsz;
		if ((lo = j - base) <= (hi = max - i)) {
			if (lo >= thresh)
				qst(base, j);
			base = i;
			lo = hi;
		} else {
			if (hi >= thresh)
				qst(i, max);
			max = j;
		}
	} while (lo >= thresh);
E 2
}
E 1
