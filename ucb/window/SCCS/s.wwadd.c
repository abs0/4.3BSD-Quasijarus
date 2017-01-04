h61572
s 00010/00005/00061
d D 3.11 88/06/29 21:37:17 bostic 11 10
c install approved copyright notice
e
s 00013/00007/00053
d D 3.10 88/02/21 13:37:58 bostic 10 9
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00054
d D 3.9 85/04/24 16:15:31 edward 9 8
c copyright messages
e
s 00001/00001/00053
d D 3.8 84/05/23 01:58:19 edward 8 7
c new sccs id
e
s 00018/00018/00036
d D 3.7 83/12/02 22:45:29 edward 7 6
c WWU_MAJOR, clreol in wwupdate(), and more optimizations.
e
s 00032/00037/00022
d D 3.6 83/11/23 16:36:09 edward 6 5
c New cover scheme
e
s 00006/00009/00053
d D 3.5 83/09/15 10:09:26 edward 5 4
c Now uses screen address for all buffers.
e
s 00013/00009/00049
d D 3.4 83/09/14 14:15:35 edward 4 3
c Off screen windows!!!!!!
e
s 00006/00004/00052
d D 3.3 83/08/16 12:54:58 edward 3 2
c wwtouched added
e
s 00000/00000/00056
d D 3.2 83/08/11 17:23:35 edward 2 1
i
c last few day's work
e
s 00056/00000/00000
d D 3.1 83/08/09 18:35:14 edward 1 0
c date and time created 83/08/09 18:35:14 by edward
e
u
U
t
T
I 1
D 10
#ifndef lint
D 8
static	char *sccsid = "%W% %E%";
E 8
I 8
static char sccsid[] = "%W% %G%";
E 8
#endif

E 10
I 9
/*
D 10
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 10
I 10
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 11
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 11
I 11
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
E 11
E 10
 */
I 10

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 10

E 9
#include "ww.h"

/*
D 6
 * Stick w1 behind w2
 * W1 should have an empty ww_cov map.
E 6
I 6
 * Stick w1 behind w2.
E 6
 */
wwadd(w1, w2)
D 6
register struct ww *w1, *w2;
E 6
I 6
register struct ww *w1;
struct ww *w2;
E 6
{
D 6
	if (w1->ww_forw != 0 || w1->ww_back != 0)
D 4
		abort();
E 4
I 4
		return;				/* sanity */
E 6
I 6
D 7
	register struct ww *w;
E 7
	register i;
I 7
	register struct ww *w;
E 7
E 6

E 4
	w1->ww_order = w2->ww_order + 1;
	w1->ww_back = w2;
	w1->ww_forw = w2->ww_forw;
	w2->ww_forw->ww_back = w1;
	w2->ww_forw = w1;
I 4

E 4
D 6
	{
		register struct ww *wp;
E 6
I 6
	for (w = w1->ww_forw; w != &wwhead; w = w->ww_forw)
		w->ww_order++;
	for (i = w1->ww_i.t; i < w1->ww_i.b; i++) {
D 7
		register j = w1->ww_i.l;
		register char *smap = &wwsmap[i][j];
		register char *win = &w1->ww_win[i][j];
E 7
I 7
		register j;
		register char *smap = wwsmap[i];
		register char *win = w1->ww_win[i];
		union ww_char *ns = wwns[i];
		union ww_char *buf = w1->ww_buf[i];
E 7
		int nvis = 0;
I 7
		int nchanged = 0;
E 7
E 6

D 6
		for (wp = w2; wp != &wwhead; wp = wp->ww_back)
			wwcover(wp, w1);
		for (wp = w1->ww_forw; wp != &wwhead; wp = wp->ww_forw) {
			wp->ww_order++;
			wwcover(w1, wp);
		}
	}
	{
D 3
		int i;
E 3
I 3
D 4
		int i = w1->ww_w.t;
E 4
I 4
		int i = w1->ww_i.t;
E 4
		char *touched = &wwtouched[i];
E 3

D 3
		for (i = w1->ww_w.t; i < w1->ww_w.b; i++) {
			int j;
E 3
I 3
D 4
		for (; i < w1->ww_w.b; i++, touched++) {
			int j = w1->ww_w.nc;
E 3
			register char *win = w1->ww_win[i - w1->ww_w.t];
			register char *smap = &wwsmap[i][w1->ww_w.l];
			register union ww_char *ns = &wwns[i][w1->ww_w.l];
			register union ww_char *buf = w1->ww_buf[w1->ww_scroll
							+ i - w1->ww_w.t];
E 4
I 4
		for (; i < w1->ww_i.b; i++, touched++) {
D 5
			int j = w1->ww_i.nc;
			register char *win = &w1->ww_win[i - w1->ww_w.t]
					[w1->ww_i.l - w1->ww_w.l];
			register char *smap = &wwsmap[i][w1->ww_i.l];
			register union ww_char *ns = &wwns[i][w1->ww_i.l];
			register union ww_char *buf
				= &w1->ww_buf[w1->ww_scroll + i - w1->ww_w.t]
					[w1->ww_i.l - w1->ww_w.l];
E 5
I 5
			int j = w1->ww_i.l;
			register char *win = &w1->ww_win[i][j];
			register char *smap = &wwsmap[i][j];
			register union ww_char *ns = &wwns[i][j];
			register union ww_char *buf = &w1->ww_buf[i][j];
E 5
E 4

D 3
			for (j = w1->ww_w.nc; --j >= 0;) {
E 3
I 3
D 5
			while (--j >= 0) {
E 5
I 5
			for (; j < w1->ww_i.r; j++) {
E 5
E 3
				if ((*win & (WWM_GLS|WWM_COV)) == 0) {
I 3
					*touched = 1;
E 3
					*smap++ = w1->ww_index;
					ns++->c_w = buf++->c_w
						^ *win++ << WWC_MSHIFT;
				} else {
					smap++;
					ns++;
					win++;
					buf++;
				}
E 6
I 6
		for (j = w1->ww_i.l; j < w1->ww_i.r; j++) {
D 7
			w = wwindex[*smap];
			if (w1->ww_order > w->ww_order) {
				win++;
				smap++;
E 7
I 7
			w = wwindex[smap[j]];
			if (w1->ww_order > w->ww_order)
E 7
				continue;
E 6
D 7
			}
I 6
			if (*win & WWM_GLS) {
				win++;
				smap++;
E 7
I 7
			if (win[j] & WWM_GLS)
E 7
				continue;
D 7
			}
E 7
			if (w != &wwnobody && w->ww_win[i][j] == 0)
				w->ww_nvis[i]--;
D 7
			*smap++ = w1->ww_index;
			if (*win == 0)
E 7
I 7
			smap[j] = w1->ww_index;
			if (win[j] == 0)
E 7
				nvis++;
D 7
			wwns[i][j].c_w = w1->ww_buf[i][j].c_w ^
				*win++ << WWC_MSHIFT;
			wwtouched[i] = 1;
E 7
I 7
			ns[j].c_w = buf[j].c_w ^ win[j] << WWC_MSHIFT;
			nchanged++;
E 7
E 6
		}
I 7
		if (nchanged > 4)
			wwtouched[i] |= WWU_MAJOR|WWU_TOUCHED;
		else if (nchanged > 0)
			wwtouched[i] |= WWU_TOUCHED;
E 7
I 6
		w1->ww_nvis[i] = nvis;
E 6
	}
}
E 1
