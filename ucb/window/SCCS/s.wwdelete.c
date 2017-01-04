h30580
s 00010/00005/00114
d D 3.16 88/06/29 21:37:48 bostic 16 15
c install approved copyright notice
e
s 00013/00007/00106
d D 3.15 88/02/21 13:38:12 bostic 15 14
c written by Edward Wang; attach Berkeley specific copyright
e
s 00001/00001/00112
d D 3.14 88/01/03 00:55:44 bostic 14 13
c really union declaration, not struct; fix for ANSI C
e
s 00006/00000/00107
d D 3.13 85/04/24 16:15:39 edward 13 12
c copyright messages
e
s 00001/00001/00106
d D 3.12 84/05/23 01:58:21 edward 12 11
c new sccs id
e
s 00012/00005/00095
d D 3.11 83/12/02 22:45:33 edward 11 10
c WWU_MAJOR, clreol in wwupdate(), and more optimizations.
e
s 00017/00003/00083
d D 3.10 83/11/29 10:52:26 edward 10 9
c forgot about transparency in wwdelete1()
e
s 00028/00020/00058
d D 3.9 83/11/28 17:14:34 edward 9 8
c New cover algorithm, and new loop structure.
e
s 00049/00003/00029
d D 3.8 83/11/28 16:24:33 edward 8 7
c Use recursive delete1() for fast wwdelete()
e
s 00002/00020/00030
d D 3.7 83/11/23 17:31:34 edward 7 6
c merge common code into wwuncover.
e
s 00027/00043/00023
d D 3.6 83/11/23 16:36:18 edward 6 5
c New cover scheme
e
s 00004/00006/00062
d D 3.5 83/09/15 10:09:30 edward 5 4
c Now uses screen address for all buffers.
e
s 00015/00009/00053
d D 3.4 83/09/14 14:15:48 edward 4 3
c Off screen windows!!!!!!
e
s 00033/00023/00029
d D 3.3 83/08/16 12:55:04 edward 3 2
c wwtouched added
e
s 00000/00000/00052
d D 3.2 83/08/11 17:23:44 edward 2 1
i
c last few day's work
e
s 00052/00000/00000
d D 3.1 83/08/09 18:35:13 edward 1 0
c date and time created 83/08/09 18:35:13 by edward
e
u
U
t
T
I 1
D 15
#ifndef lint
D 12
static	char *sccsid = "%W% %E%";
E 12
I 12
static char sccsid[] = "%W% %G%";
E 12
#endif

E 15
I 13
/*
D 15
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 15
I 15
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 16
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 16
I 16
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
E 16
E 15
 */
I 15

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 15

E 13
#include "ww.h"

/*
 * Pull w free from the cover list.
 */
wwdelete(w)
register struct ww *w;
{
I 4
D 6
	if (w->ww_forw == 0 || w->ww_back == 0)
		return;				/* sanity */
E 6
I 6
D 9
	register struct ww *wp;
	register i, j;
E 9
I 9
	register i;
E 9
E 6

E 4
D 3
	register i;
E 3
I 3
D 6
	{
D 4
		register i = w->ww_w.t;
E 4
I 4
		register i = w->ww_i.t;
E 4
		register char *touched = &wwtouched[i];
E 6
I 6
D 9
	for (i = w->ww_i.t; i < w->ww_i.b; i++)
E 9
I 9
	for (i = w->ww_i.t; i < w->ww_i.b; i++) {
		register j;
		register char *smap = wwsmap[i];
D 14
		register struct ww_char *ns = wwns[i];
E 14
I 14
		register union ww_char *ns = wwns[i];
E 14
D 11
		register char *touched = &wwtouched[i];
E 11
I 11
		register int nchanged = 0;
E 11

E 9
		for (j = w->ww_i.l; j < w->ww_i.r; j++)
D 9
			if (wwsmap[i][j] == w->ww_index) {
				wwsmap[i][j] = WWX_NOBODY;
				wwns[i][j].c_w = ' ';
				wwtouched[i] = 1;
E 9
I 9
			if (smap[j] == w->ww_index) {
				smap[j] = WWX_NOBODY;
				ns[j].c_w = ' ';
D 11
				*touched = 1;
E 11
I 11
				nchanged++;
E 11
E 9
			}
I 11
		if (nchanged > 4)
			wwtouched[i] |= WWU_MAJOR|WWU_TOUCHED;
		else if (nchanged > 0)
			wwtouched[i] |= WWU_TOUCHED;
E 11
I 9
	}
E 9
D 7
	for (wp = w->ww_forw; wp != &wwhead; wp = wp->ww_forw) {
		int i1, i2, j1, j2;
E 7
E 6
E 3

I 7
D 8
	for (wp = w->ww_forw; wp != &wwhead; wp = wp->ww_forw) {
E 8
I 8
D 9
	for (wp = w->ww_forw; wp != &wwhead; wp = wp->ww_forw)
E 8
E 7
D 3
	for (i = w->ww_w.t; i < w->ww_w.b; i++) {
		register int j = w->ww_w.l;
		register char *smap = &wwsmap[i][j];
		register union ww_char *ns = &wwns[i][j];
		for (j = w->ww_w.nc; --j >= 0;) {
			if (*smap == w->ww_index) {
				*smap++ = WWX_NOBODY;
				ns++->c_w = ' ';
			} else {
				smap++;
				ns++;
E 3
I 3
D 4
		for (; i < w->ww_w.b; i++, touched++) {
			register int j = w->ww_w.l;
E 4
I 4
D 6
		for (; i < w->ww_i.b; i++, touched++) {
			register int j = w->ww_i.l;
E 4
			register char *smap = &wwsmap[i][j];
			register union ww_char *ns = &wwns[i][j];

D 4
			for (j = w->ww_w.nc; --j >= 0;) {
E 4
I 4
			for (j = w->ww_i.nc; --j >= 0;) {
E 4
				if (*smap == w->ww_index) {
					*touched = 1;
					*smap++ = WWX_NOBODY;
					ns++->c_w = ' ';
				} else {
					smap++;
					ns++;
E 6
I 6
		w->ww_order--;
E 9
I 9
	{
		register struct ww *wp;
E 9
D 7
		i1 = MAX(w->ww_i.t, wp->ww_i.t);
		i2 = MIN(w->ww_i.b, wp->ww_i.b);
		j1 = MAX(w->ww_i.l, wp->ww_i.l);
		j2 = MIN(w->ww_i.r, wp->ww_i.r);
		for (i = i1; i < i2; i++) {
			for (j = j1; j < j2; j++) {
				if (wwsmap[i][j] != WWX_NOBODY)
					continue;
				if ((wp->ww_win[i][j] & WWM_GLS) == 0) {
					wwsmap[i][j] = wp->ww_index;
					wwns[i][j].c_w = wp->ww_buf[i][j].c_w ^
						wp->ww_win[i][j] << WWC_MSHIFT;
					wwtouched[i] = 1;
					if (wp->ww_win[i][j] == 0)
						wp->ww_nvis[i]++;
E 6
				}
E 3
			}
		}
E 7
I 7
D 8
		wwuncover(w, wp);
E 7
	}
E 8
D 6
	{
		register struct ww *wp;
E 6
I 3

I 8
D 9
	if ((wp = w->ww_forw) != &wwhead)
		wwdelete1(wp, w->ww_i.t, w->ww_i.b, w->ww_i.l, w->ww_i.r);
E 9
I 9
		for (wp = w->ww_forw; wp != &wwhead; wp = wp->ww_forw)
			wp->ww_order--;
	}
E 9

I 9
	if (w->ww_forw != &wwhead)
		wwdelete1(w->ww_forw,
			w->ww_i.t, w->ww_i.b, w->ww_i.l, w->ww_i.r);

E 9
E 8
E 3
D 6
		for (wp = w->ww_forw; wp != &wwhead; wp = wp->ww_forw) {
			wp->ww_order--;
			wwuncover(w, wp);
		}
	}
D 3
	for (i = 0; i < w->ww_w.nr; i++) {
		register j;
		register char *win = w->ww_win[i];
		register char *cov = w->ww_cov[i];
		for (j = w->ww_w.nc; --j >= 0;) {
			if (*win != 0) {
				if ((*win++ &= ~WWM_COV) == 0)
					w->ww_nvis[i]++;
			} else
				win++;
			*cov++ = WWX_NOBODY;
E 3
I 3
	{
		register i;

D 4
		for (i = 0; i < w->ww_w.nr; i++) {
E 4
I 4
		for (i = w->ww_i.t; i < w->ww_i.b; i++) {
E 4
D 5
			register j;
D 4
			register char *win = w->ww_win[i];
			register char *cov = w->ww_cov[i];
			for (j = w->ww_w.nc; --j >= 0;) {
E 4
I 4
			register char *win = &w->ww_win[i - w->ww_w.t]
					[w->ww_i.l - w->ww_w.l];
			register char *cov = &w->ww_cov[i - w->ww_w.t]
					[w->ww_i.l - w->ww_w.l];
E 5
I 5
			register j = w->ww_i.l;
			register char *win = &w->ww_win[i][j];
			register char *cov = &w->ww_cov[i][j];
E 5

			for (j = w->ww_i.nc; --j >= 0;) {
E 4
				if (*win != 0) {
					if ((*win++ &= ~WWM_COV) == 0)
D 4
						w->ww_nvis[i]++;
E 4
I 4
D 5
						w->ww_nvis[i - w->ww_w.t]++;
E 5
I 5
						w->ww_nvis[i]++;
E 5
E 4
				} else
					win++;
				*cov++ = WWX_NOBODY;
			}
E 3
		}
	}
E 6
	w->ww_back->ww_forw = w->ww_forw;
	w->ww_forw->ww_back = w->ww_back;
	w->ww_forw = w->ww_back = 0;
I 8
}

wwdelete1(w, t, b, l, r)
register struct ww *w;
{
	int i;
	int tt, bb, ll, rr;
I 10
	char hasglass;
E 10

I 10
again:
	hasglass = 0;
E 10
	tt = MAX(t, w->ww_i.t);
	bb = MIN(b, w->ww_i.b);
	ll = MAX(l, w->ww_i.l);
	rr = MIN(r, w->ww_i.r);
I 10
	if (tt >= bb || ll >= rr) {
		if ((w = w->ww_forw) == &wwhead)
			return;
		goto again;
	}
E 10
	for (i = tt; i < bb; i++) {
D 9
		register j = ll;
E 9
I 9
		register j;
E 9
		register char *smap = wwsmap[i];
		register union ww_char *ns = wwns[i];
		register char *win = w->ww_win[i];
		register union ww_char *buf = w->ww_buf[i];
		int nvis = w->ww_nvis[i];
D 11
		char touched = wwtouched[i];
E 11
I 11
		int nchanged = 0;
E 11

		for (j = ll; j < rr; j++) {
D 9
			if (smap[j] != WWX_NOBODY)
E 9
I 9
D 10
			if (smap[j] != WWX_NOBODY || win[j] & WWM_GLS)
E 10
I 10
			if (smap[j] != WWX_NOBODY)
E 10
E 9
				continue;
I 10
			if (win[j] & WWM_GLS) {
				hasglass = 1;
				continue;
			}
E 10
D 9
			if ((win[j] & WWM_GLS) == 0) {
				smap[j] = w->ww_index;
				ns[j].c_w = buf[j].c_w ^ win[j] << WWC_MSHIFT;
				touched = 1;
				if (win[j] == 0)
					nvis++;
			}
E 9
I 9
			smap[j] = w->ww_index;
			ns[j].c_w = buf[j].c_w ^ win[j] << WWC_MSHIFT;
D 11
			touched = 1;
E 11
I 11
			nchanged++;
E 11
			if (win[j] == 0)
				nvis++;
E 9
		}
D 11
		wwtouched[i] = touched;
E 11
I 11
		if (nchanged > 4)
			wwtouched[i] |= WWU_MAJOR|WWU_TOUCHED;
		else if (nchanged > 0)
			wwtouched[i] |= WWU_TOUCHED;
E 11
		w->ww_nvis[i] = nvis;
	}
	if ((w = w->ww_forw) == &wwhead)
		return;
I 10
	if (hasglass)
		goto again;
E 10
	if (tt > t)
		wwdelete1(w, t, tt, l, r);
	if (bb < b)
		wwdelete1(w, bb, b, l, r);
	if (ll > l)
D 10
		wwdelete1(w, t, b, l, ll);
E 10
I 10
		wwdelete1(w, tt, bb, l, ll);
E 10
	if (rr < r)
D 10
		wwdelete1(w, t, b, rr, r);
E 10
I 10
		wwdelete1(w, tt, bb, rr, r);
E 10
E 8
}
E 1
