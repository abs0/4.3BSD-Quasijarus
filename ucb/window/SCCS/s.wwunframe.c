h08498
s 00010/00005/00049
d D 3.17 88/06/29 21:38:59 bostic 17 16
c install approved copyright notice
e
s 00013/00007/00041
d D 3.16 88/02/21 13:39:00 bostic 16 15
c written by Edward Wang; attach Berkeley specific copyright
e
s 00001/00001/00047
d D 3.15 88/01/03 00:55:43 bostic 15 14
c really union declaration, not struct; fix for ANSI C
e
s 00006/00000/00042
d D 3.14 85/04/24 16:17:05 edward 14 13
c copyright messages
e
s 00001/00001/00041
d D 3.13 84/05/23 01:58:59 edward 13 12
c new sccs id
e
s 00006/00003/00036
d D 3.12 83/12/02 22:45:53 edward 12 11
c WWU_MAJOR, clreol in wwupdate(), and more optimizations.
e
s 00020/00024/00019
d D 3.11 83/11/28 17:14:38 edward 11 10
c New cover algorithm, and new loop structure.
e
s 00015/00031/00028
d D 3.10 83/11/23 17:31:45 edward 10 9
c merge common code into wwuncover.
e
s 00022/00002/00037
d D 3.9 83/11/23 16:37:02 edward 9 8
c New cover scheme
e
s 00005/00004/00034
d D 3.8 83/09/15 10:10:16 edward 8 7
c Now uses screen address for all buffers.
e
s 00003/00009/00035
d D 3.7 83/08/19 17:33:01 edward 7 6
c moved fmap into struct ww and added WWO_FRAME to allocate it.
e
s 00009/00001/00035
d D 3.6 83/08/18 17:18:08 edward 6 5
c the box
e
s 00000/00002/00036
d D 3.5 83/08/16 13:08:25 edward 5 4
c wwfmap == 0 anachronism
e
s 00001/00000/00037
d D 3.4 83/08/16 12:55:27 edward 4 3
c wwtouched added
e
s 00000/00002/00037
d D 3.3 83/08/12 18:33:32 edward 3 2
c faster and better frames
e
s 00000/00000/00039
d D 3.2 83/08/11 17:24:52 edward 2 1
i
c last few day's work
e
s 00039/00000/00000
d D 3.1 83/08/09 18:37:54 edward 1 0
c date and time created 83/08/09 18:37:54 by edward
e
u
U
t
T
I 1
D 16
#ifndef lint
D 13
static	char *sccsid = "%W% %E%";
E 13
I 13
static char sccsid[] = "%W% %G%";
E 13
#endif

E 16
I 14
/*
D 16
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 16
I 16
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 17
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 17
I 17
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
E 17
E 16
 */
I 16

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 16

E 14
#include "ww.h"

D 3
char **wwfmap;

E 3
wwunframe(w)
register struct ww *w;
{
I 6
D 7
	wwunframe1(w, 1);
}

wwunframe1(w, dofmap)
register struct ww *w;
char dofmap;
{
E 7
E 6
D 10
	register i, j;
	register char *win;
	register char *fmap;
	register struct ww *wp;
E 10
I 10
D 11
	register i;
E 11
I 11
	int i;
E 11
E 10

D 5
	if (wwfmap == 0)
		return;
E 5
D 8
	for (i = w->ww_w.t; i < w->ww_w.b; i++) {
		win = w->ww_win[i - w->ww_w.t];
E 8
I 8
	for (i = w->ww_i.t; i < w->ww_i.b; i++) {
D 10
		j = w->ww_i.l;
		win = &w->ww_win[i][j];
E 8
D 7
		fmap = wwfmap[i];
E 7
I 7
		if (w->ww_fmap)
D 8
			fmap = w->ww_fmap[i];
E 7
		for (j = w->ww_w.l; j < w->ww_w.r; j++) {
E 8
I 8
			fmap = &w->ww_fmap[i][j];
E 10
I 10
D 11
		register j = w->ww_i.l;
		register char *win = &w->ww_win[i][j];
		register char *fmap = w->ww_fmap ? &w->ww_fmap[i][j] : 0;
		register char *smap = &wwsmap[i][j];
E 11
I 11
		register j;
		register char *win = w->ww_win[i];
		register char *fmap = w->ww_fmap ? w->ww_fmap[i] : 0;
		register char *smap = wwsmap[i];
D 15
		register struct ww_char *ns = wwns[i];
E 15
I 15
		register union ww_char *ns = wwns[i];
E 15
D 12
		char touched = wwtouched[i];
E 12
I 12
		int nchanged = 0;
E 12
E 11

E 10
D 11
		for (; j < w->ww_i.r; j++) {
E 8
			if (*win & WWM_GLS) {
				win++;
				fmap++;
I 10
				smap++;
E 11
I 11
		for (j = w->ww_i.l; j < w->ww_i.r; j++) {
			if (win[j] & WWM_GLS)
E 11
E 10
				continue;
I 11
			win[j] |= WWM_GLS;
			if (fmap != 0)
				fmap[j] = 0;
			if (smap[j] == w->ww_index) {
				smap[j] = WWX_NOBODY;
				ns[j].c_w = ' ';
D 12
				touched = 1;
E 12
I 12
				nchanged++;
E 12
E 11
			}
D 11
			*win++ |= WWM_GLS;
D 6
			*fmap++ = 0;
E 6
I 6
D 7
			if (dofmap)
E 7
I 7
D 10
			if (w->ww_fmap)
E 10
I 10
			if (w->ww_fmap != 0)
E 10
E 7
				*fmap++ = 0;
E 6
D 10
			if (wwsmap[i][j] == w->ww_index) {
				wwsmap[i][j] = WWX_NOBODY;
E 10
I 10
			if (*smap == w->ww_index) {
				*smap = WWX_NOBODY;
E 10
				wwns[i][j].c_w = ' ';
I 4
				wwtouched[i] = 1;
E 4
			}
I 10
			smap++;
E 11
E 10
		}
I 11
D 12
		wwtouched[i] = touched;
E 12
I 12
		if (nchanged > 4)
			wwtouched[i] |= WWU_MAJOR|WWU_TOUCHED;
		else if (nchanged > 0)
			wwtouched[i] |= WWU_TOUCHED;
E 12
E 11
		w->ww_nvis[i] = 0;
	}
D 9
	for (wp = w->ww_forw; wp != &wwhead; wp = wp->ww_forw)
		wwuncover(w, wp);
E 9
I 9
D 10
	for (wp = w->ww_forw; wp != &wwhead; wp = wp->ww_forw) {
		int i1, i2, j1, j2;
E 10
I 10
D 11
	{
		register struct ww *wp;
E 11
E 10

D 10
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
				}
			}
		}
E 10
I 10
D 11
		for (wp = w->ww_forw; wp != &wwhead; wp = wp->ww_forw)
			wwuncover(w, wp);
E 10
	}
E 11
I 11
	if (w->ww_forw != &wwhead)
		wwdelete1(w->ww_forw,
			w->ww_i.t, w->ww_i.b, w->ww_i.l, w->ww_i.r);
E 11
E 9
}
E 1
