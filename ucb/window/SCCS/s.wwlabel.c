h50035
s 00010/00005/00067
d D 3.15 88/06/29 21:38:24 bostic 21 20
c install approved copyright notice
e
s 00013/00007/00059
d D 3.14 88/02/21 13:38:35 bostic 20 19
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00060
d D 3.13 85/04/24 16:14:11 edward 19 18
c copyright messages
e
s 00001/00001/00059
d D 3.12 84/05/23 01:57:17 edward 18 17
c new sccs id
e
s 00001/00000/00059
d D 3.11 84/04/08 12:08:26 edward 17 16
c control character expansion in wwwrite()
c calling of wwupdate() in wwwrite() dependent of ww_noupdate
c control character handling macros in char.h
e
s 00001/00001/00058
d D 3.10 83/12/02 22:45:21 edward 16 15
c WWU_MAJOR, clreol in wwupdate(), and more optimizations.
e
s 00028/00034/00031
d D 3.9 83/12/02 14:15:05 edward 15 14
c Changed loop structures
e
s 00005/00003/00060
d D 3.8 83/11/23 16:35:49 edward 14 13
c New cover scheme
e
s 00005/00009/00058
d D 3.7 83/09/15 10:09:10 edward 13 12
c Now uses screen address for all buffers.
e
s 00002/00004/00065
d D 3.6 83/08/26 16:25:59 edward 12 11
c error reporting
e
s 00014/00007/00055
d D 3.5 83/08/19 17:32:55 edward 11 10
c moved fmap into struct ww and added WWO_FRAME to allocate it.
e
s 00001/00001/00061
d D 3.4 83/08/18 15:07:44 edward 10 9
c bug with using the wrong ww_scroll
e
s 00003/00000/00059
d D 3.3 83/08/16 12:54:50 edward 9 8
c wwtouched added
e
s 00009/00011/00050
d D 3.2 83/08/12 18:33:27 edward 8 7
c faster and better frames
e
s 00000/00000/00061
d D 3.1 83/08/11 17:22:27 edward 7 5
i 6
c last few day's work
e
s 00049/00009/00012
d D 2.1.1.1 83/08/09 18:35:46 edward 6 5
c mile stone
e
s 00000/00000/00021
d D 2.1 83/07/30 13:26:56 edward 5 4
c prepare for major change
e
s 00008/00013/00013
d D 1.4 83/07/28 13:06:42 edward 4 3
c can specify starting column, and expand control characters
e
s 00004/00004/00022
d D 1.3 83/07/22 17:10:55 edward 3 2
c scrolling.
c uses Wscreensize() to get screen size.
c More intelligent framing.
c etc.
e
s 00000/00000/00026
d D 1.2 83/07/19 20:08:11 edward 2 1
c today's work
e
s 00026/00000/00000
d D 1.1 83/07/18 21:05:18 edward 1 0
c date and time created 83/07/18 21:05:18 by edward
e
u
U
f b 
t
T
I 1
D 20
#ifndef lint
D 18
static	char *sccsid = "%W% %E%";
E 18
I 18
static char sccsid[] = "%W% %G%";
E 18
#endif

E 20
I 19
/*
D 20
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 20
I 20
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 21
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 21
I 21
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
E 21
E 20
 */
I 20

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 20

E 19
#include "ww.h"
I 17
#include "char.h"
E 17

D 4
wwlabel(w, l, mode)
E 4
I 4
D 6
wwlabel(w, where, l, mode)
E 6
I 6
D 8
char **wwfmap;
#define U 1
#define R 2
#define D 4
#define L 8

E 8
/*
 * Label window w on f,
 * at 1 line above w and 'where' columns from it's left edge.
 * Gross, but it works.
 */
wwlabel(w, f, where, l, mode)
E 6
E 4
D 8
register struct ww *w;
E 8
I 8
struct ww *w;
E 8
D 6
register char *l;
E 6
I 6
struct ww *f;
char *l;
E 6
{
D 6
	register i;
E 6
I 6
D 15
	int i;
E 15
I 15
	int row;
E 15
	register j;
E 6
I 4
D 15
	register char *p;
E 15
I 15
	int jj;
E 15
E 4
D 6
	char ulc, top, urc, left, right, llc, bottom, lrc;
E 6
I 6
	register char *win;
	register union ww_char *buf;
	register union ww_char *ns;
D 8
	char *fmap;
E 8
I 8
	register char *fmap;
I 14
D 15
	char *smap;
E 14
I 9
	char *touched;
E 15
I 15
	register char *smap;
	char touched;
	char *p;
E 15
E 9
E 8
E 6
D 4
	char framed;
E 4

D 3
	if (!(framed = w->ww_inrow < w->ww_nrow)) {
E 3
I 3
D 4
	if (!(framed = w->ww_i.nrow < w->ww_o.nrow)) {
E 3
		Wgetframe(&ulc, &top, &urc, &left, &right, &llc, &bottom, &lrc);
D 3
		w->ww_inrow--;
		w->ww_irow++;
E 3
I 3
		w->ww_i.nrow--;
		w->ww_i.row++;
E 3
	}
	Wauxcursor(w->ww_win, 0, 1);
D 3
	for (i = w->ww_ncol - 2; i > 0 && *l; i--, l++)
E 3
I 3
	for (i = w->ww_o.ncol - 2; i > 0 && *l; i--, l++)
E 3
		Waputc(*l, mode, w->ww_win);
	if (!framed)
		for (; i > 0; i--)
			Waputc(top, 0, w->ww_win);
E 4
I 4
D 6
	if (w->ww_i.nrow == w->ww_w.nrow)	/* not framed */
E 6
I 6
D 11
	if ((i = w->ww_w.t - 1 - f->ww_w.t) < 0)
E 11
I 11
	if (f->ww_fmap == 0)
E 11
E 6
D 12
		return -1;
E 12
I 12
		return;
E 12
D 6
	Wauxcursor(w->ww_win, 0, where);
	for (i = w->ww_o.ncol - where - 1; i > 0 && *l; l++)
		for (p = unctrl(*l); *p; p++, i--)
			Waputc(*p, mode, w->ww_win);
E 6
I 6
D 11
	j = w->ww_w.l + where;
	j = MAX(j, f->ww_w.l);
	win = &f->ww_win[i][j - f->ww_w.l];
D 10
	buf = &f->ww_buf[w->ww_scroll + i][j - f->ww_w.l];
E 10
I 10
	buf = &f->ww_buf[f->ww_scroll + i][j - f->ww_w.l];
E 11
I 11

D 13
	i = w->ww_w.t - 1 - f->ww_w.t;
	if (i < 0)
E 13
I 13
D 15
	i = w->ww_w.t - 1;
	if (i < f->ww_i.t || i >= f->ww_i.b)
E 15
I 15
	row = w->ww_w.t - 1;
	if (row < f->ww_i.t || row >= f->ww_i.b)
E 15
E 13
D 12
		return -1;
E 12
I 12
		return;
E 12
D 13
	j = w->ww_w.l + where - f->ww_w.l;
	if (j < 0)
		j = 0;
E 13
I 13
D 15
	j = w->ww_i.l + where;
E 13
	win = &f->ww_win[i][j];
D 13
	buf = &f->ww_buf[f->ww_scroll + i][j];
E 13
I 13
	buf = &f->ww_buf[i][j];
E 13
	fmap = &f->ww_fmap[i][j];
E 15
I 15
	win = f->ww_win[row];
	buf = f->ww_buf[row];
	fmap = f->ww_fmap[row];
	ns = wwns[row];
	smap = wwsmap[row];
	touched = wwtouched[row];
	mode <<= WWC_MSHIFT;
E 15

E 11
E 10
D 13
	i += f->ww_w.t;
I 11
	j += f->ww_w.l;
E 13
E 11
D 15
	ns = &wwns[i][j];
I 14
	smap = &wwsmap[i][j];
E 14
D 11
	fmap = &wwfmap[i][j];
E 11
I 9
	touched = &wwtouched[i];
E 9
D 11
	j = MIN(w->ww_w.r, f->ww_w.r) - j;
E 11

I 11
D 13
	j = MIN(w->ww_w.r, f->ww_w.r) - j;
E 13
I 13
	j = MIN(w->ww_i.r, f->ww_i.r) - j;
E 13
E 11
	for (; j > 0 && *l;)
D 8
		for (p = unctrl(*l++); j > 0 && *p; j--, fmap++) {
E 8
I 8
		for (p = unctrl(*l++); j > 0 && *p; j--) {
E 15
I 15
	jj = MIN(w->ww_i.r, f->ww_i.r);
	j = w->ww_i.l + where;
	while (j < jj && *l)
		for (p = unctrl(*l++); j < jj && *p; j++, p++) {
E 15
E 8
			/* can't label if not already framed */
D 8
			if (*win & WWM_GLS || (*fmap & (U|D)) == (U|D)) {
E 8
I 8
D 14
			if (*win & WWM_GLS) {
E 14
I 14
D 15
			if (*win++ & WWM_GLS) {
E 14
E 8
				p++;
				buf++;
				ns++;
D 14
				win++;
E 14
I 8
				fmap++;
E 8
D 14
			} else if (*win & WWM_COV) {
E 14
I 14
				smap++;
			} else if (*smap++ != f->ww_index) {
E 14
				buf++->c_w = mode << WWC_MSHIFT | *p++;
I 8
				*fmap++ |= WWF_LABEL;
E 8
				ns++;
				win++;
D 8
			} else
E 8
I 8
			} else {
I 9
				*touched = 1;
E 9
E 8
				ns++->c_w = (buf++->c_w
					= mode << WWC_MSHIFT | *p++)
						^ *win++ << WWC_MSHIFT;
I 8
				*fmap++ |= WWF_LABEL;
E 15
I 15
			if (win[j] & WWM_GLS)
				continue;
			if (smap[j] != f->ww_index)
				buf[j].c_w = mode | *p;
			else {
				ns[j].c_w = (buf[j].c_w = mode | *p)
						^ win[j] << WWC_MSHIFT;
D 16
				touched = 1;
E 16
I 16
				touched |= WWU_TOUCHED;
E 16
E 15
			}
I 15
			fmap[j] |= WWF_LABEL;
E 15
E 8
		}
I 15
	wwtouched[row] = touched;
E 15
D 12

	return 0;
E 12
E 6
E 4
}
E 1
