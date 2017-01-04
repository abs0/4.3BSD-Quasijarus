h61909
s 00010/00005/00100
d D 3.16 88/06/29 21:38:16 bostic 16 15
c install approved copyright notice
e
s 00013/00007/00092
d D 3.15 88/02/21 13:38:29 bostic 15 14
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00093
d D 3.14 85/04/24 16:16:59 edward 14 13
c copyright messages
e
s 00001/00001/00092
d D 3.13 84/05/23 01:58:56 edward 13 12
c new sccs id
e
s 00001/00001/00092
d D 3.12 83/12/02 22:45:46 edward 12 11
c WWU_MAJOR, clreol in wwupdate(), and more optimizations.
e
s 00021/00022/00072
d D 3.11 83/12/02 14:15:41 edward 11 10
c Changed loop structures
e
s 00010/00012/00084
d D 3.10 83/11/23 16:36:47 edward 10 9
c New cover scheme
e
s 00004/00004/00092
d D 3.9 83/09/15 12:23:33 edward 9 8
c reworked tt stuff
e
s 00017/00021/00079
d D 3.8 83/09/15 10:10:12 edward 8 7
c Now uses screen address for all buffers.
e
s 00032/00018/00068
d D 3.7 83/09/14 14:16:34 edward 7 6
c Off screen windows!!!!!!
e
s 00002/00001/00084
d D 3.6 83/08/17 17:41:15 edward 6 5
c better wrap around handling.
e
s 00001/00001/00084
d D 3.5 83/08/17 16:43:07 edward 5 4
c check tt_setinsert != 0 before using it
e
s 00006/00001/00079
d D 3.4 83/08/16 12:55:21 edward 4 3
c wwtouched added
e
s 00001/00000/00079
d D 3.3 83/08/15 18:15:18 edward 3 2
c tt cleanup
e
s 00065/00027/00014
d D 3.2 83/08/11 17:24:42 edward 2 1
i
c last few day's work
e
s 00041/00000/00000
d D 3.1 83/08/09 18:37:52 edward 1 0
c date and time created 83/08/09 18:37:52 by edward
e
u
U
t
T
I 1
D 15
#ifndef lint
D 13
static	char *sccsid = "%W% %E%";
E 13
I 13
static char sccsid[] = "%W% %G%";
E 13
#endif

E 15
I 14
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

E 14
#include "ww.h"
I 3
#include "tt.h"
E 3

D 2
wwinschar(w, n)
E 2
I 2
D 8
wwinschar(w, line, col, c)
E 8
I 8
wwinschar(w, row, col, c)
E 8
E 2
register struct ww *w;
D 2
register n;
E 2
I 2
short c;
E 2
{
D 2
	register i, j;
	int col, row;
E 2
I 2
	register i;
D 8
	int row = line - w->ww_scroll;
I 7
	int srow = row + w->ww_w.t;
	int scol = col + w->ww_w.l;
E 8
E 7
	int nvis;
E 2

I 7
	/*
	 * First, shift the line.
	 */
E 7
D 2
	col = w->ww_cur.c + w->ww_w.l;
	row = w->ww_cur.r + w->ww_w.t;
	for (i = col; i < wwncol;) {
		for (j = i; j < wwncol && wwsmap[row][j] == w->ww_index; j++)
			;
		if (j > i) {
			if (j <= i + n) {
				if (j == wwncol) {
					(*tt.tt_clreol)(w);
				} else {
					(*tt.tt_blank)(j);
					(*tt.tt_move)(row, col);
				}
E 2
I 2
	{
		register union ww_char *p, *q;

D 8
		p = &w->ww_buf[line][w->ww_w.nc];
E 8
I 8
		p = &w->ww_buf[row][w->ww_b.r];
E 8
		q = p - 1;
D 8
		for (i = w->ww_w.nc - col - 1; --i >= 0;)
E 8
I 8
		for (i = w->ww_b.r - col; --i > 0;)
E 8
			*--p = *--q;
		q->c_w = c;
	}
D 7
	if (row < 0 || row >= w->ww_w.nr)
E 7
I 7

	/*
	 * If can't see it, just return.
	 */
D 8
	if (srow < w->ww_i.t || srow >= w->ww_i.b
	    || w->ww_i.r <= 0 || w->ww_i.r <= scol)
E 8
I 8
	if (row < w->ww_i.t || row >= w->ww_i.b
	    || w->ww_i.r <= 0 || w->ww_i.r <= col)
E 8
E 7
		return;
I 7

D 8
	if (scol < w->ww_i.l)
		scol = w->ww_i.l;
	col = scol - w->ww_w.l;
E 8
I 8
	if (col < w->ww_i.l)
		col = w->ww_i.l;
E 8

	/*
	 * Now find out how much is actually changed, and fix wwns.
	 */
E 7
	{
		register union ww_char *buf;
		register char *win;
		register union ww_char *ns;
		register char *smap;
I 4
D 11
		char *touched;
E 11
I 11
		char touched;
E 11
E 4

		nvis = 0;
D 7
		smap = &wwsmap[row + w->ww_w.t][col + w->ww_w.l];
		for (i = w->ww_w.nc - col; i > 0; i--)
			if (*smap == w->ww_index)
				break;
			else {
				smap++;
				col++;
			}
E 7
I 7
D 8
		smap = &wwsmap[srow][scol];
		for (i = w->ww_i.r - scol; i > 0 && *smap++ != w->ww_index; i--)
			col++, scol++;
E 8
I 8
		smap = &wwsmap[row][col];
D 11
		for (i = w->ww_i.r - col; i > 0 && *smap++ != w->ww_index; i--)
			col++;
E 8
E 7
		if (i <= 0)
E 11
I 11
		for (i = col; i < w->ww_i.r && *smap++ != w->ww_index; i++)
			;
		if (i >= w->ww_i.r)
E 11
			return;
D 8
		buf = &w->ww_buf[line][col];
E 8
I 8
D 11
		buf = &w->ww_buf[row][col];
E 8
		win = &w->ww_win[row][col];
D 7
		ns = &wwns[row + w->ww_w.t][col + w->ww_w.l];
I 4
		touched = &wwtouched[row + w->ww_w.t];
E 7
I 7
D 8
		ns = &wwns[srow][scol];
		touched = &wwtouched[srow];
E 8
I 8
		ns = &wwns[row][col];
I 10
		smap = &wwsmap[row][col];
E 10
		touched = &wwtouched[row];
E 8
E 7
E 4
		c = buf->c_w ^ *win << WWC_MSHIFT;
D 10
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
					*touched = 1;
E 4
					ns++->c_w = buf++->c_w
						^ *win++ << WWC_MSHIFT;
I 4
				}
E 4
E 2
			} else {
E 10
I 10
		for (; --i >= 0;)
			if (*smap++ != w->ww_index) {
				ns++;
				buf++;
				win++;
			} else if (*win) {
				ns++->c_w = buf++->c_w ^ *win++ << WWC_MSHIFT;
E 10
I 4
				*touched = 1;
I 10
			} else {
E 10
E 4
D 2
				if (j < wwncol) {
					(*tt.tt_move)(row, j - n);
					(*tt.tt_delchar)(n);
					(*tt.tt_move)(row, col);
				}
				(*tt.tt_setinsert)(1);
				(*tt.tt_blank)(n);
E 2
I 2
				*ns++ = *buf++;
				win++;
E 11
I 11
		col = i;
		buf = w->ww_buf[row];
		win = w->ww_win[row];
		ns = wwns[row];
		smap = &wwsmap[row][i];
		touched = wwtouched[row];
		for (; i < w->ww_i.r; i++) {
			if (*smap++ != w->ww_index)
				continue;
D 12
			touched = 1;
E 12
I 12
			touched |= WWU_TOUCHED;
E 12
			if (win[i])
				ns[i].c_w =
					buf[i].c_w ^ win[i] << WWC_MSHIFT;
			else {
E 11
				nvis++;
I 10
D 11
				*touched = 1;
E 11
I 11
				ns[i] = buf[i];
E 11
E 10
E 2
			}
I 11
		}
		wwtouched[row] = touched;
E 11
D 10
		}
E 10
D 2
		for (i = j; i < wwncol && wwsmap[row][i] != w->ww_index; i++)
			;
E 2
	}
D 2
	(*tt.tt_setinsert)(0);
E 2
I 2
D 7
	col += w->ww_w.l;
	row += w->ww_w.t;
D 5
	if (nvis > (wwncol - col) / 2) {
E 5
I 5
D 6
	if (tt.tt_setinsert != 0 && nvis > (wwncol - col) / 2) {
E 6
I 6
	if (tt.tt_setinsert != 0 && nvis > (wwncol - col) / 2
	    && col != wwncol - 1) {
E 7
I 7

	/*
	 * Can/Should we use delete character?
	 */
D 8
	if (tt.tt_setinsert != 0 && nvis > (wwncol - scol) / 2) {
E 8
I 8
D 9
	if (tt.tt_setinsert != 0 && nvis > (wwncol - col) / 2) {
E 9
I 9
	if (tt.tt_hasinsert && nvis > (wwncol - col) / 2) {
E 9
E 8
E 7
E 6
E 5
		register union ww_char *p, *q;

D 9
		(*tt.tt_setinsert)(1);
E 9
I 9
		tt.tt_ninsert = 1;
		tt.tt_nmodes = c >> WWC_MSHIFT & tt.tt_availmodes;
E 9
D 7
		(*tt.tt_move)(row, col);
E 7
I 7
D 8
		(*tt.tt_move)(srow, scol);
E 8
I 8
		(*tt.tt_move)(row, col);
E 8
E 7
D 9
		(*tt.tt_setmodes)(c >> WWC_MSHIFT);
E 9
		(*tt.tt_putc)(c & WWC_CMASK);
D 9
		(*tt.tt_setinsert)(0);
E 9
I 9
		tt.tt_ninsert = 0;
E 9

D 7
		p = &wwos[row][wwncol];
E 7
I 7
D 8
		p = &wwos[srow][wwncol];
E 8
I 8
		p = &wwos[row][wwncol];
E 8
E 7
		q = p - 1;
D 7
		for (i = wwncol - col - 1; --i >= 0;)
E 7
I 7
D 8
		for (i = wwncol - scol; --i > 0;)
E 8
I 8
		for (i = wwncol - col; --i > 0;)
E 8
E 7
			*--p = *--q;
		q->c_w = c;
	}
E 2
}
E 1
