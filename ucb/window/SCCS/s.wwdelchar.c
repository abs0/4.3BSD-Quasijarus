h21663
s 00010/00005/00096
d D 3.13 88/06/29 21:37:45 bostic 13 12
c install approved copyright notice
e
s 00013/00007/00088
d D 3.12 88/02/21 13:38:10 bostic 12 11
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00089
d D 3.11 85/04/24 16:17:23 edward 11 10
c copyright messages
e
s 00001/00001/00088
d D 3.10 84/05/23 01:59:09 edward 10 9
c new sccs id
e
s 00001/00001/00088
d D 3.9 83/12/02 22:46:06 edward 9 8
c WWU_MAJOR, clreol in wwupdate(), and more optimizations.
e
s 00021/00021/00068
d D 3.8 83/12/02 14:16:00 edward 8 7
c Changed loop structures
e
s 00010/00012/00079
d D 3.7 83/11/23 16:37:07 edward 7 6
c New cover scheme
e
s 00017/00021/00074
d D 3.6 83/09/15 10:10:24 edward 6 5
c Now uses screen address for all buffers.
e
s 00032/00017/00063
d D 3.5 83/09/14 14:16:46 edward 5 4
c Off screen windows!!!!!!
e
s 00006/00001/00074
d D 3.4 83/08/16 12:55:39 edward 4 3
c wwtouched added
e
s 00001/00000/00074
d D 3.3 83/08/15 18:15:27 edward 3 2
c tt cleanup
e
s 00065/00002/00009
d D 3.2 83/08/11 17:25:04 edward 2 1
i
c last few day's work
e
s 00011/00000/00000
d D 3.1 83/08/09 18:40:18 edward 1 0
c date and time created 83/08/09 18:40:18 by edward
e
u
U
t
T
I 1
D 12
#ifndef lint
D 10
static	char *sccsid = "%W% %E%";
E 10
I 10
static char sccsid[] = "%W% %G%";
E 10
#endif

E 12
I 11
/*
D 12
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 12
I 12
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 13
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 13
I 13
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
E 13
E 12
 */
I 12

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 12

E 11
#include "ww.h"
I 3
#include "tt.h"
E 3

D 2
wwdelchar(w)
E 2
I 2
D 6
wwdelchar(w, line, col)
E 6
I 6
wwdelchar(w, row, col)
E 6
E 2
register struct ww *w;
{
D 2
	w = w;
E 2
I 2
	register i;
D 6
	int row = line - w->ww_scroll;
I 5
	int srow = row + w->ww_w.t;
	int scol = col + w->ww_w.l;
E 6
E 5
	int nvis;

I 5
	/*
	 * First, shift the line.
	 */
E 5
	{
		register union ww_char *p, *q;

D 6
		p = &w->ww_buf[line][col];
E 6
I 6
		p = &w->ww_buf[row][col];
E 6
		q = p + 1;
D 6
		for (i = w->ww_w.nc - col - 1; --i >= 0;)
E 6
I 6
		for (i = w->ww_b.r - col; --i > 0;)
E 6
			*p++ = *q++;
		p->c_w = ' ';
	}
D 5
	if (row < 0 || row >= w->ww_w.nr)
E 5
I 5

	/*
	 * If can't see it, just return.
	 */
D 6
	if (srow < w->ww_i.t || srow >= w->ww_i.b
	    || w->ww_i.r <= 0 || w->ww_i.r <= scol)
E 6
I 6
	if (row < w->ww_i.t || row >= w->ww_i.b
	    || w->ww_i.r <= 0 || w->ww_i.r <= col)
E 6
E 5
		return;
I 5

D 6
	if (scol < w->ww_i.l)
		scol = w->ww_i.l;
	col = scol - w->ww_w.l;
E 6
I 6
	if (col < w->ww_i.l)
		col = w->ww_i.l;
E 6

	/*
	 * Now find out how much is actually changed, and fix wwns.
	 */
E 5
	{
		register union ww_char *buf;
		register char *win;
		register union ww_char *ns;
		register char *smap;
I 4
D 8
		char *touched;
E 8
I 8
		char touched;
E 8
E 4

		nvis = 0;
D 5
		smap = &wwsmap[row + w->ww_w.t][col + w->ww_w.l];
		for (i = w->ww_w.nc - col; i > 0; i--)
			if (*smap == w->ww_index)
				break;
			else {
				smap++;
				col++;
			}
E 5
I 5
D 6
		smap = &wwsmap[srow][scol];
		for (i = w->ww_i.r - scol; i > 0 && *smap++ != w->ww_index; i--)
			col++, scol++;
E 6
I 6
		smap = &wwsmap[row][col];
D 8
		for (i = w->ww_i.r - col; i > 0 && *smap++ != w->ww_index; i--)
			col++;
E 6
E 5
		if (i <= 0)
E 8
I 8
		for (i = col; i < w->ww_i.r && *smap++ != w->ww_index; i++)
			;
		if (i >= w->ww_i.r)
E 8
			return;
D 6
		buf = &w->ww_buf[line][col];
E 6
I 6
D 8
		buf = &w->ww_buf[row][col];
E 6
		win = &w->ww_win[row][col];
D 5
		ns = &wwns[row + w->ww_w.t][col + w->ww_w.l];
I 4
		touched = &wwtouched[row + w->ww_w.t];
E 5
I 5
D 6
		ns = &wwns[srow][scol];
		touched = &wwtouched[srow];
E 6
I 6
		ns = &wwns[row][col];
I 7
		smap = &wwsmap[row][col];
E 7
		touched = &wwtouched[row];
E 6
E 5
E 4
D 7
		for (; --i >= 0;) {
			if (*win) {
				if ((*win & (WWM_COV|WWM_GLS)) != 0) {
					ns++;
					buf++;
D 4
				} else
E 4
I 4
				} else {
E 4
					ns++->c_w = buf++->c_w
						^ *win++ << WWC_MSHIFT;
I 4
					*touched = 1;
				}
E 4
			} else {
E 7
I 7
		for (; --i >= 0;)
			if (*smap++ != w->ww_index) {
				ns++;
				buf++;
				win++;
			} else if (*win) {
				ns++->c_w = buf++->c_w ^ *win++ << WWC_MSHIFT;
E 7
I 4
				*touched = 1;
I 7
			} else {
E 7
E 4
				*ns++ = *buf++;
				win++;
E 8
I 8
		col = i;
		buf = w->ww_buf[row];
		win = w->ww_win[row];
		ns = wwns[row];
		smap = &wwsmap[row][i];
		touched = wwtouched[row];
		for (; i < w->ww_i.r; i++) {
			if (*smap++ != w->ww_index)
				continue;
D 9
			touched = 1;
E 9
I 9
			touched |= WWU_TOUCHED;
E 9
			if (win[i])
				ns[i].c_w =
					buf[i].c_w ^ win[i] << WWC_MSHIFT;
			else {
E 8
				nvis++;
I 7
D 8
				*touched = 1;
E 8
I 8
				ns[i] = buf[i];
E 8
E 7
			}
I 8
		}
		wwtouched[row] = touched;
E 8
D 7
		}
E 7
	}
D 5
	col += w->ww_w.l;
	row += w->ww_w.t;
	if (nvis > (wwncol - col) / 2) {
E 5
I 5

	/*
	 * Can/Should we use delete character?
	 */
D 6
	if (tt.tt_delchar != 0 && nvis > (wwncol - scol) / 2) {
E 6
I 6
	if (tt.tt_delchar != 0 && nvis > (wwncol - col) / 2) {
E 6
E 5
		register union ww_char *p, *q;

D 5
		(*tt.tt_move)(row, col);
E 5
I 5
D 6
		(*tt.tt_move)(srow, scol);
E 6
I 6
		(*tt.tt_move)(row, col);
E 6
E 5
		(*tt.tt_delchar)();

D 5
		p = &wwos[row][col];
E 5
I 5
D 6
		p = &wwos[srow][scol];
E 6
I 6
		p = &wwos[row][col];
E 6
E 5
		q = p + 1;
D 5
		for (i = wwncol - col - 1; --i >= 0;)
E 5
I 5
D 6
		for (i = wwncol - scol; --i > 0;)
E 6
I 6
		for (i = wwncol - col; --i > 0;)
E 6
E 5
			*p++ = *q++;
		p->c_w = ' ';
	}
E 2
}
E 1
