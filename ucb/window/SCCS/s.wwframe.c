h38175
s 00010/00005/00220
d D 3.18 88/06/29 21:38:08 bostic 23 22
c install approved copyright notice
e
s 00013/00007/00212
d D 3.17 88/02/21 13:38:23 bostic 22 21
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00213
d D 3.16 85/04/24 16:13:37 edward 21 20
c copyright messages
e
s 00001/00001/00212
d D 3.15 84/11/20 23:38:19 edward 20 19
c fixed sysline window bug (unframed foreground window)
e
s 00001/00001/00212
d D 3.14 84/05/23 01:57:11 edward 19 18
c new sccs id
e
s 00001/00001/00212
d D 3.13 83/12/17 15:38:23 edward 18 17
c WWM_GRP added
e
s 00001/00001/00212
d D 3.12 83/12/02 22:45:13 edward 17 16
c WWU_MAJOR, clreol in wwupdate(), and more optimizations.
e
s 00009/00008/00204
d D 3.11 83/11/23 16:35:34 edward 16 15
c New cover scheme
e
s 00017/00025/00195
d D 3.10 83/09/15 10:09:04 edward 15 14
c Now uses screen address for all buffers.
e
s 00010/00010/00210
d D 3.9 83/09/14 14:14:55 edward 14 13
c Off screen windows!!!!!!
e
s 00028/00008/00192
d D 3.8 83/08/23 18:17:19 edward 13 12
c bounds checking for wwsmap
e
s 00015/00017/00185
d D 3.7 83/08/19 17:32:44 edward 12 11
c moved fmap into struct ww and added WWO_FRAME to allocate it.
e
s 00041/00036/00161
d D 3.6 83/08/19 12:22:44 edward 11 10
c made wwframeok() a macro and wwframec() a little more efficient.
e
s 00013/00023/00184
d D 3.5 83/08/18 17:17:56 edward 10 9
c the box
e
s 00003/00001/00204
d D 3.4 83/08/16 12:54:42 edward 9 8
c wwtouched added
e
s 00001/00000/00204
d D 3.3 83/08/15 18:14:31 edward 8 7
c tt cleanup
e
s 00158/00094/00046
d D 3.2 83/08/12 18:33:21 edward 7 6
c faster and better frames
e
s 00000/00000/00140
d D 3.1 83/08/11 17:22:20 edward 6 4
i 5
c last few day's work
e
s 00104/00194/00036
d D 2.1.1.1 83/08/09 18:35:38 edward 5 4
c mile stone
e
s 00000/00000/00230
d D 2.1 83/07/30 13:26:46 edward 4 3
c prepare for major change
e
s 00142/00080/00088
d D 1.3 83/07/22 17:10:27 edward 3 2
c scrolling.
c uses Wscreensize() to get screen size.
c More intelligent framing.
c etc.
e
s 00000/00000/00168
d D 1.2 83/07/19 20:08:09 edward 2 1
c today's work
e
s 00168/00000/00000
d D 1.1 83/07/18 21:05:17 edward 1 0
c date and time created 83/07/18 21:05:17 by edward
e
u
U
f b 
t
T
I 1
D 22
#ifndef lint
D 19
static	char *sccsid = "%W% %E%";
E 19
I 19
static char sccsid[] = "%W% %G%";
E 19
#endif

E 22
I 21
/*
D 22
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 22
I 22
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 23
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 23
I 23
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
E 23
E 22
 */
I 22

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 22

E 21
#include "ww.h"
I 8
#include "tt.h"
E 8

I 11
#define frameok(w, r, c) (w1 = wwindex[wwsmap[r][c]], \
D 20
	!w1->ww_hasframe || w1->ww_order > (w)->ww_order)
E 20
I 20
	w1->ww_fmap || w1->ww_order > (w)->ww_order)
E 20

E 11
I 3
D 5
#define TOP	0
#define BOTTOM	1
#define LEFT	2
#define RIGHT	3
E 5
I 5
D 7
char **wwfmap;
#define U 1
#define R 2
#define D 4
#define L 8
E 5

E 7
E 3
D 5
wwframe(w)
register struct ww *w;
E 5
I 5
wwframe(w, wframe)
D 7
register struct ww *w, *wframe;
E 7
I 7
register struct ww *w;
struct ww *wframe;
E 7
E 5
{
D 7
	register i;
D 3
	char noleft = 0;
	char noright = 0;
	char notop = 0;
	char nobot = 0;
E 3
I 3
	char noleft, noright, notop, nobot;
E 7
I 7
	register r, c;
	char a1, a2, a3;
	char b1, b2, b3;
	register char *smap;
	register code;
I 11
	register struct ww *w1;
E 11
E 7
E 3
D 5
	char ulc, top, urc, left, right, llc, bottom, lrc;
I 3
	struct ww_dim oldsize;
	Pos bstart;
E 5
E 3

D 3
	w->ww_incol = w->ww_ncol;
	w->ww_inrow = w->ww_nrow;
	w->ww_icol = w->ww_col;
	w->ww_irow = w->ww_row;
E 3
I 3
D 5
	oldsize = w->ww_w;
	w->ww_w = w->ww_i = w->ww_o;
E 5
I 5
D 7
	if (wwfmap == 0
	    && (wwfmap = wwalloc(wwnrow, wwncol, sizeof (char))) == 0)
		return -1;
	noleft = w->ww_w.l == 0;
	noright = w->ww_w.r >= wwncol;
	notop = w->ww_w.t == 0;
	nobot = w->ww_w.b >= wwnrow;
E 7
I 7
	if (w->ww_w.t > 0) {
		r = w->ww_w.t - 1;
D 14
		c = w->ww_w.l - 1;
E 14
I 14
		c = w->ww_i.l - 1;
E 14
		smap = &wwsmap[r + 1][c + 1];
		a1 = 0;
		a2 = 0;
		b1 = 0;
D 11
		b2 = wwframeok(w, r, c);
E 11
I 11
		b2 = c < 0 || frameok(w, r, c);
E 11
E 7
E 5
E 3

D 3
	if (w->ww_col == 0)
		noleft++;
E 3
I 3
D 5
	if (w->ww_o.col == 0)
		noleft = 1;
	else {
		noleft = 0;
		w->ww_i.ncol--;
		w->ww_i.col++;
	}
E 3
	/*
D 3
	if (w->ww_row == 0)
E 3
I 3
	if (w->ww_o.row == 0)
E 3
		notop++;
I 3
	else
E 3
	*/
D 3
	if (w->ww_col + w->ww_ncol == WCols)
		noright++;
	if (w->ww_row + w->ww_nrow == WRows)
		nobot++;
E 3
I 3
	{
		notop = 0;
		w->ww_i.nrow--;
		w->ww_i.row++;
	}
	if (w->ww_o.col + w->ww_o.ncol == wwncol) {
		noright = 1;
E 3
	/*
D 3
	else if (wwcheckframe(w->ww_row + w->ww_nrow,
			w->ww_col, w->ww_col + w->ww_ncol - 1, wwhead))
		nobot++;
	else if (wwcheckframe(w->ww_row + w->ww_nrow - 1,
			w->ww_col, w->ww_col + w->ww_ncol - 1, wwhead)) {
		nobot++;
		ww
E 3
I 3
	} else if (wwcheckframe(LEFT, w->ww_o.col + w->ww_o.ncol - 1,
			w->ww_o.row, w->ww_o.row + w->ww_o.nrow - 1, wwhead)) {
		noright = 1;
		w->ww_w.ncol--;
		w->ww_i.ncol--;
	} else if (wwcheckframe(LEFT, w->ww_o.col + w->ww_o.ncol,
			w->ww_o.row, w->ww_o.row + w->ww_o.nrow - 1, wwhead)) {
		XXXXX
		w->ww_w.ncol--;
	*/
	} else {
		noright = 0;
		w->ww_i.ncol--;
E 3
	}
I 3
	if (w->ww_o.row + w->ww_o.nrow == wwnrow) {
		nobot = 1;
	} else if (wwcheckframe(TOP, w->ww_o.row + w->ww_o.nrow - 1,
			w->ww_o.col, w->ww_o.col + w->ww_o.ncol - 1, wwhead)) {
		nobot = 1;
		w->ww_w.nrow--;
		w->ww_i.nrow--;
	/*
	} else if (wwcheckframe(TOP, w->ww_o.row + w->ww_o.nrow,
			w->ww_o.col, w->ww_o.col + w->ww_o.ncol - 1, wwhead)) {
		XXXXX
		ww->ww_i.nrow--;
E 3
	*/
I 3
	} else {
		nobot = 0;
		w->ww_i.nrow--;
	}

	if (oldsize.nrow != w->ww_w.nrow || oldsize.ncol != w->ww_w.ncol) {
		bstart = w->ww_win->w_bstart;
		if (Wsize(w->ww_win, w->ww_w.ncol, w->ww_w.nrow) != 0) {
			wwprintf(w, "wwframe: Wsize(%d, %d) failed.\r\n",
				w->ww_w.ncol, w->ww_w.nrow);
			return -1;
		}
		w->ww_win->w_bstart = bstart;
	}
	Wsetmargins(w->ww_win, noleft ? 0 : 1, notop ? 0 : 1,
		w->ww_i.ncol, w->ww_i.nrow);
	/* scroll to the old position */

E 3
	Wgetframe(&ulc, &top, &urc, &left, &right, &llc, &bottom, &lrc);

E 5
D 7
	if (!notop) {
D 5
		Wauxcursor(w->ww_win, 0, 0);
		if (noleft)
			Waputc(top, 0, w->ww_win);
		else
			Waputc(ulc, 0, w->ww_win);
D 3
		for (i = w->ww_ncol - 2; i > 0; i--)
E 3
I 3
		for (i = w->ww_o.ncol - 2; i > 0; i--)
E 3
			Waputc(top, 0, w->ww_win);
		if (noright)
			Waputc(top, 0, w->ww_win);
		else
			Waputc(urc, 0, w->ww_win);
E 5
I 5
		for (i = w->ww_w.l; i < w->ww_w.r; i++)
			wwframex(w, w->ww_w.t, i, wframe);
E 7
I 7
D 14
		for (; c < w->ww_w.r; c++) {
E 14
I 14
		for (; c < w->ww_i.r; c++) {
E 14
D 13
			a3 = w->ww_index == *smap++;
D 11
			b3 = wwframeok(w, r, c + 1);
E 11
I 11
			b3 = c + 1 >= wwncol || frameok(w, r, c + 1);
E 13
I 13
			if (c + 1 >= wwncol) {
				a3 = 1;
				b3 = 1;
			} else {
				a3 = w->ww_index == *smap++;
				b3 = frameok(w, r, c + 1);
			}
E 13
E 11
			if (b2) {
				code = 0;
				if ((a1 || a2) && b1)
					code |= WWF_L;
				if ((a2 || a3) && b3)
					code |= WWF_R;
				if (code)
D 10
					wwframec(r, c, wframe, code|WWF_TOP);
E 10
I 10
D 12
					wwframec(wframe, r, c, code|WWF_TOP, 1);
E 12
I 12
					wwframec(wframe, r, c, code|WWF_TOP);
E 12
E 10
			}
			a1 = a2;
			a2 = a3;
			b1 = b2;
			b2 = b3;
		}
		if ((a1 || a2) && b1 && b2)
D 10
			wwframec(r, c, wframe, WWF_L|WWF_TOP);
E 10
I 10
D 12
			wwframec(wframe, r, c, WWF_L|WWF_TOP, 1);
E 12
I 12
			wwframec(wframe, r, c, WWF_L|WWF_TOP);
E 12
E 10
E 7
E 5
D 3
		w->ww_irow++;
		w->ww_inrow--;
E 3
	}

D 7
	if (!nobot) {
D 3
		Wauxcursor(w->ww_win, w->ww_nrow - 1, 0);
E 3
I 3
D 5
		Wauxcursor(w->ww_win, w->ww_o.nrow - 1, 0);
E 3
		if (noleft)
			Waputc(bottom, 0, w->ww_win);
		else
			Waputc(llc, 0, w->ww_win);
D 3
		for (i = w->ww_ncol - 2; i > 0; i--)
E 3
I 3
		for (i = w->ww_o.ncol - 2; i > 0; i--)
E 3
			Waputc(bottom, 0, w->ww_win);
		if (noright)
			Waputc(bottom, 0, w->ww_win);
		else
			Waputc(lrc, 0, w->ww_win);
E 5
I 5
		for (i = w->ww_w.l; i < w->ww_w.r; i++)
			wwframex(w, w->ww_w.b - 1, i, wframe);
E 5
D 3
		w->ww_inrow--;
E 3
	}
E 7
I 7
	if (w->ww_w.b < wwnrow) {
		r = w->ww_w.b;
D 14
		c = w->ww_w.l - 1;
E 14
I 14
		c = w->ww_i.l - 1;
E 14
		smap = &wwsmap[r - 1][c + 1];
		a1 = 0;
		a2 = 0;
		b1 = 0;
D 11
		b2 = wwframeok(w, r, c);
E 11
I 11
		b2 = c < 0 || frameok(w, r, c);
E 11
E 7

D 7
	if (!noleft) {
D 5
		Wauxcursor(w->ww_win, 0, 0);
		if (notop)
			Waputc(left, 0, w->ww_win);
		else
			Waputc(ulc, 0, w->ww_win);
D 3
		for (i = 1; i < w->ww_nrow - 1; i++) {
E 3
I 3
		for (i = 1; i < w->ww_o.nrow - 1; i++) {
E 3
			Wauxcursor(w->ww_win, i, 0);
			Waputc(left, 0, w->ww_win);
		}
D 3
		Wauxcursor(w->ww_win, w->ww_nrow - 1, 0);
E 3
I 3
		Wauxcursor(w->ww_win, w->ww_o.nrow - 1, 0);
E 3
		if (nobot)
			Waputc(left, 0, w->ww_win);
		else
			Waputc(llc, 0, w->ww_win);
E 5
I 5
		for (i = w->ww_w.t; i < w->ww_w.b; i++)
			wwframex(w, i, w->ww_w.l, wframe);
E 7
I 7
D 14
		for (; c < w->ww_w.r; c++) {
E 14
I 14
		for (; c < w->ww_i.r; c++) {
E 14
D 13
			a3 = w->ww_index == *smap++;
D 11
			b3 = wwframeok(w, r, c + 1);
E 11
I 11
			b3 = c + 1 >= wwncol || frameok(w, r, c + 1);
E 13
I 13
			if (c + 1 >= wwncol) {
				a3 = 1;
				b3 = 1;
			} else {
				a3 = w->ww_index == *smap++;
				b3 = frameok(w, r, c + 1);
			}
E 13
E 11
			if (b2) {
				code = 0;
				if ((a1 || a2) && b1)
					code |= WWF_L;
				if ((a2 || a3) && b3)
					code |= WWF_R;
				if (code)
D 10
					wwframec(r, c, wframe, code);
E 10
I 10
D 12
					wwframec(wframe, r, c, code, 1);
E 12
I 12
					wwframec(wframe, r, c, code);
E 12
E 10
			}
			a1 = a2;
			a2 = a3;
			b1 = b2;
			b2 = b3;
		}
		if ((a1 || a2) && b1 && b2)
D 10
			wwframec(r, c, wframe, WWF_L);
E 10
I 10
D 12
			wwframec(wframe, r, c, WWF_L, 1);
E 12
I 12
			wwframec(wframe, r, c, WWF_L);
E 12
E 10
E 7
E 5
D 3
		w->ww_icol++;
		w->ww_incol--;
E 3
	}

D 7
	if (!noright) {
D 3
		Wauxcursor(w->ww_win, 0, w->ww_ncol - 1);
E 3
I 3
D 5
		Wauxcursor(w->ww_win, 0, w->ww_o.ncol - 1);
E 3
		if (notop)
			Waputc(right, 0, w->ww_win);
		else
			Waputc(urc, 0, w->ww_win);
D 3
		for (i = 1; i < w->ww_nrow - 1; i++) {
			Wauxcursor(w->ww_win, i, w->ww_ncol - 1);
E 3
I 3
		for (i = 1; i < w->ww_o.nrow - 1; i++) {
			Wauxcursor(w->ww_win, i, w->ww_o.ncol - 1);
E 3
			Waputc(left, 0, w->ww_win);
		}
D 3
		Wauxcursor(w->ww_win, w->ww_nrow - 1, w->ww_ncol - 1);
E 3
I 3
		Wauxcursor(w->ww_win, w->ww_o.nrow - 1, w->ww_o.ncol - 1);
E 3
		if (nobot)
			Waputc(right, 0, w->ww_win);
		else
			Waputc(lrc, 0, w->ww_win);
E 5
I 5
		for (i = w->ww_w.t; i < w->ww_w.b; i++)
			wwframex(w, i, w->ww_w.r - 1, wframe);
E 7
I 7
	if (w->ww_w.l > 0) {
D 14
		r = w->ww_w.t - 1;
E 14
I 14
		r = w->ww_i.t - 1;
E 14
		c = w->ww_w.l - 1;
		a1 = 0;
		a2 = 0;
		b1 = 0;
D 11
		b2 = wwframeok(w, r, c);
E 11
I 11
		b2 = r < 0 || frameok(w, r, c);
E 11

D 14
		for (; r < w->ww_w.b; r++) {
E 14
I 14
		for (; r < w->ww_i.b; r++) {
E 14
D 13
			a3 = w->ww_index == wwsmap[r + 1][c + 1];
D 11
			b3 = wwframeok(w, r + 1, c);
E 11
I 11
			b3 = r + 1 >= wwnrow || frameok(w, r + 1, c);
E 13
I 13
			if (r + 1 >= wwnrow) {
				a3 = 1;
				b3 = 1;
			} else {
				a3 = w->ww_index == wwsmap[r + 1][c + 1];
				b3 = frameok(w, r + 1, c);
			}
E 13
E 11
			if (b2) {
				code = 0;
				if ((a1 || a2) && b1)
					code |= WWF_U;
				if ((a2 || a3) && b3)
					code |= WWF_D;
				if (code)
D 10
					wwframec(r, c, wframe, code);
E 10
I 10
D 12
					wwframec(wframe, r, c, code, 1);
E 12
I 12
					wwframec(wframe, r, c, code);
E 12
E 10
			}
			a1 = a2;
			a2 = a3;
			b1 = b2;
			b2 = b3;
		}
		if ((a1 || a2) && b1 && b2)
D 10
			wwframec(r, c, wframe, WWF_U);
E 10
I 10
D 12
			wwframec(wframe, r, c, WWF_U, 1);
E 12
I 12
			wwframec(wframe, r, c, WWF_U);
E 12
E 10
E 7
E 5
D 3
		w->ww_incol--;
E 3
	}
D 5

D 3
	Wsetmargins(w->ww_win, noleft ? 0 : 1, notop ? 0 : 1,
		w->ww_incol, w->ww_inrow);
E 3
I 3
	return 0;
E 5
E 3
D 7
}
E 7

D 3
wwunframe(w)
E 3
I 3
D 5
wwcheckframe(flag, x, a, b, w)
E 3
register struct ww *w;
E 5
I 5
D 7
wwframex(w, r, c, wframe)
register struct ww *w, *wframe;
register r, c;
E 5
{
D 3
	register i;
E 3
I 3
D 5
	int xx, aa, bb;
E 5
I 5
	char ul, top, ur, right, lr, bottom, ll, left;
E 7
I 7
	if (w->ww_w.r < wwncol) {
D 14
		r = w->ww_w.t - 1;
E 14
I 14
		r = w->ww_i.t - 1;
E 14
		c = w->ww_w.r;
		a1 = 0;
		a2 = 0;
		b1 = 0;
D 11
		b2 = wwframeok(w, r, c);
E 11
I 11
		b2 = r < 0 || frameok(w, r, c);
E 11
E 7
E 5
E 3

D 3
	w->ww_incol = w->ww_ncol;
	w->ww_inrow = w->ww_nrow;
	w->ww_icol = w->ww_col;
	w->ww_irow = w->ww_row;

	Wauxcursor(w->ww_win, 0, 0);
	for (i = w->ww_ncol; i > 0; i--)
		Waputc(' ', WBUF, w->ww_win);

	Wauxcursor(w->ww_win, w->ww_nrow - 1, 0);
	for (i = w->ww_ncol; i > 0; i--)
		Waputc(' ', WBUF, w->ww_win);

	for (i = 1; i < w->ww_nrow - 1; i++) {
		Wauxcursor(w->ww_win, i, 0);
		Waputc(' ', WBUF, w->ww_win);
		Wauxcursor(w->ww_win, i, w->ww_ncol - 1);
		Waputc(' ', WBUF, w->ww_win);
E 3
I 3
D 5
	if (a >= b)
		return 1;
	for (; w; w = w->ww_next) {
		switch (flag) {
		case TOP:
			xx = w->ww_o.row;
			aa = w->ww_o.col;
			bb = w->ww_o.col + w->ww_o.ncol - 1;
			break;
		case BOTTOM:
			xx = w->ww_o.row + w->ww_o.nrow - 1;
			aa = w->ww_o.col;
			bb = w->ww_o.col + w->ww_o.ncol - 1;
			break;
		case LEFT:
			xx = w->ww_o.col;
			aa = w->ww_o.row;
			bb = w->ww_o.row + w->ww_o.nrow - 1;
			break;
		case RIGHT:
			xx = w->ww_o.col + w->ww_o.ncol - 1;
			aa = w->ww_o.row;
			bb = w->ww_o.row + w->ww_o.nrow - 1;
			break;
		}
		if (xx != x || aa > b || bb < a)
			continue;
		return wwcheckframe(flag, x, a, aa, w->ww_next)
			&& wwcheckframe(flag, x, bb, b, w->ww_next);
E 5
I 5
D 7
	if (w->ww_index != wwsmap[r][c])
		return;
	ul = wwframeok(w, r - 1, c - 1);
	top = wwframeok(w, r - 1, c);
	ur = wwframeok(w, r - 1, c + 1);
	right = wwframeok(w, r, c + 1);
	lr = wwframeok(w, r + 1, c + 1);
	bottom = wwframeok(w, r + 1, c);
	ll = wwframeok(w, r + 1, c - 1);
	left = wwframeok(w, r, c - 1);
	if (top && ul) {
		wwframec(r - 1, c - 1, wframe, R);
		wwframec(r - 1, c, wframe, L);
E 7
I 7
D 14
		for (; r < w->ww_w.b; r++) {
E 14
I 14
		for (; r < w->ww_i.b; r++) {
E 14
D 13
			a3 = w->ww_index == wwsmap[r + 1][c - 1];
D 11
			b3 = wwframeok(w, r + 1, c);
E 11
I 11
			b3 = r + 1 >= wwnrow || frameok(w, r + 1, c);
E 13
I 13
			if (r + 1 >= wwnrow) {
				a3 = 1;
				b3 = 1;
			} else {
				a3 = w->ww_index == wwsmap[r + 1][c - 1];
				b3 = frameok(w, r + 1, c);
			}
E 13
E 11
			if (b2) {
				code = 0;
				if ((a1 || a2) && b1)
					code |= WWF_U;
				if ((a2 || a3) && b3)
					code |= WWF_D;
				if (code)
D 10
					wwframec(r, c, wframe, code);
E 10
I 10
D 12
					wwframec(wframe, r, c, code, 1);
E 12
I 12
					wwframec(wframe, r, c, code);
E 12
E 10
			}
			a1 = a2;
			a2 = a3;
			b1 = b2;
			b2 = b3;
		}
		if ((a1 || a2) && b1 && b2)
D 10
			wwframec(r, c, wframe, WWF_U);
E 10
I 10
D 12
			wwframec(wframe, r, c, WWF_U, 1);
E 12
I 12
			wwframec(wframe, r, c, WWF_U);
E 12
E 10
E 7
E 5
E 3
	}
D 3
	Wsetmargins(w->ww_win, 0, 0, w->ww_ncol, w->ww_nrow);
E 3
I 3
D 5
	return 0;
E 5
I 5
D 7
	if (top && ur) {
		wwframec(r - 1, c, wframe, R);
		wwframec(r - 1, c + 1, wframe, L);
	}
	if (right && ur) {
		wwframec(r - 1, c + 1, wframe, D);
		wwframec(r, c + 1, wframe, U);
	}
	if (right && lr) {
		wwframec(r, c + 1, wframe, D);
		wwframec(r + 1, c + 1, wframe, U);
	}
	if (bottom && lr) {
		wwframec(r + 1, c + 1, wframe, L);
		wwframec(r + 1, c, wframe, R);
	}
	if (bottom && ll) {
		wwframec(r + 1, c, wframe, L);
		wwframec(r + 1, c - 1, wframe, R);
	}
	if (left && ll) {
		wwframec(r + 1, c - 1, wframe, U);
		wwframec(r, c - 1, wframe, D);
	}
	if (left && ul) {
		wwframec(r, c - 1, wframe, U);
		wwframec(r - 1, c - 1, wframe, D);
	}
E 7
E 5
E 3
}

D 3
wwcheckbottom(w)
E 3
I 3
D 5
wwunframe(w)
E 5
I 5
D 11
wwframeok(w, r, c)
E 5
E 3
D 7
register struct ww *w;
E 7
I 7
struct ww *w;
register r, c;
E 7
{
D 3
	return wwcheckframe(w->ww_row + w->ww_nrow,
		w->ww_col, w->ww_col + w->ww_ncol - 1, wwhead);
}
E 3
I 3
D 5
	char hasbot, hastop, hasright, hasleft;
	register i;
E 5
I 5
	register struct ww *w1;
E 5
E 3

D 3
wwcheckframe(row, l, r, w)
register struct ww *w;
{
	int rr;
E 3
I 3
D 5
	hastop = w->ww_o.row < w->ww_i.row;
	hasbot = w->ww_o.row + w->ww_o.nrow > w->ww_i.row + w->ww_i.nrow;
	hasleft = w->ww_o.col < w->ww_i.col;
	hasright = w->ww_o.col + w->ww_o.ncol > w->ww_i.col + w->ww_i.ncol;
E 5
I 5
	if (r < 0 || r >= wwnrow || c < 0 || c >= wwncol)
		return 1;
	w1 = wwindex[wwsmap[r][c]];
D 7
	if (w1->ww_hasframe && w1->ww_order <= w->ww_order)
		return 0;
	return 1;
E 7
I 7
	return !w1->ww_hasframe || w1->ww_order > w->ww_order;
E 7
}
E 5
E 3

E 11
D 3
	if (l >= r)
		return 1;
	for (; w; w = w->ww_next) {
		if (w->ww_row != row)
			continue;
		if (w->ww_col > r)
			continue;
		if ((rr = w->ww_col + w->ww_ncol) <= l)
			continue;
		return wwcheckframe(row, l, w->ww_col - 1, w->ww_next)
			&& wwcheckframe(row, rr, r, w->ww_next);
E 3
I 3
D 5
	if (hastop) {
		Wauxcursor(w->ww_win, 0, 0);
		for (i = 0; i < w->ww_o.ncol; i++)
			Waputc(' ', WBUF, w->ww_win);
E 3
	}
D 3
	return 0;
E 3
I 3
	if (hasbot) {
		Wauxcursor(w->ww_win, w->ww_o.nrow - 1, 0);
		for (i = 0; i < w->ww_o.ncol; i++)
			Waputc(' ', WBUF, w->ww_win);
	}
	if (hasleft)
		for (i = 0; i < w->ww_o.nrow; i++) {
			Wauxcursor(w->ww_win, i, 0);
			Waputc(' ', WBUF, w->ww_win);
E 5
I 5
D 10
wwframec(rr, cc, f, code)
E 10
I 10
D 12
wwframec(f, rr, cc, code, dofmap)
E 12
I 12
D 15
wwframec(f, rr, cc, code)
E 15
I 15
wwframec(f, r, c, code)
E 15
E 12
E 10
register struct ww *f;
D 15
register rr, cc;
E 15
I 15
register r, c;
E 15
I 7
D 11
int code;
E 11
I 11
char code;
E 11
I 10
D 12
char dofmap;
E 12
E 10
E 7
{
I 12
D 15
	register r, c;
E 15
E 12
D 7
	register struct ww *w2;
E 7
D 11
	register r, c;
E 11
I 11
	char oldcode;
I 16
	register char *smap;
E 16
E 11

D 10
	if (rr < 0 || rr >= wwnrow || cc < 0 || cc >= wwncol)
E 10
I 10
D 14
	if (rr < f->ww_w.t || rr >= f->ww_w.b
	    || cc < f->ww_w.l || cc >= f->ww_w.r)
E 14
I 14
D 15
	if (rr < f->ww_i.t || rr >= f->ww_i.b
	    || cc < f->ww_i.l || cc >= f->ww_i.r)
E 15
I 15
	if (r < f->ww_i.t || r >= f->ww_i.b || c < f->ww_i.l || c >= f->ww_i.r)
E 15
E 14
E 10
		return;
I 16

	smap = &wwsmap[r][c];

E 16
D 7
	w2 = wwindex[wwsmap[rr][cc]];
	if (w2->ww_order > f->ww_order) {
		if (w2 != &wwnobody) {
			r = rr - w2->ww_w.t;
			c = cc - w2->ww_w.l;
			if ((w2->ww_win[r][c] |= WWM_COV) == WWM_COV)
				w2->ww_nvis[r]--;
			w2->ww_cov[r][c] = f->ww_index;
E 7
I 7
	{
		register struct ww *w;
I 11
D 12
		register r, c;
E 12

E 11
D 15
		w = wwindex[wwsmap[rr][cc]];
E 15
I 15
D 16
		w = wwindex[wwsmap[r][c]];
E 16
I 16
		w = wwindex[*smap];
E 16
E 15
		if (w->ww_order > f->ww_order) {
D 16
			if (w != &wwnobody) {
D 15
				r = rr - w->ww_w.t;
				c = cc - w->ww_w.l;
E 15
				if ((w->ww_win[r][c] |= WWM_COV) == WWM_COV)
					w->ww_nvis[r]--;
				w->ww_cov[r][c] = f->ww_index;
			}
D 15
			wwsmap[rr][cc] = f->ww_index;
E 15
I 15
			wwsmap[r][c] = f->ww_index;
E 16
I 16
			if (w != &wwnobody && w->ww_win[r][c] == 0)
				w->ww_nvis[r]--;
			*smap = f->ww_index;
E 16
E 15
E 7
E 5
		}
D 5
	if (hasright)
		for (i = 0; i < w->ww_o.nrow; i++) {
			Wauxcursor(w->ww_win, i, w->ww_o.ncol - 1);
			Waputc(' ', WBUF, w->ww_win);
		}
	w->ww_i.row = w->ww_o.row;
	w->ww_i.nrow = w->ww_o.nrow;
	w->ww_i.col = w->ww_o.col;
	w->ww_i.ncol = w->ww_o.ncol;
	Wsetmargins(w->ww_win, 0, 0, w->ww_o.ncol, w->ww_o.nrow);
E 5
I 5
D 7
		wwsmap[rr][cc] = f->ww_index;
E 7
	}
D 7
	code = wwfmap[rr][cc] |= code;
E 7
I 7
D 10
	{
E 10
I 10
D 12
	if (dofmap) {
E 12
I 12

D 15
	r = rr - f->ww_w.t;
	c = cc - f->ww_w.l;
E 15
	if (f->ww_fmap != 0) {
E 12
E 10
		register char *fmap;
I 11

E 11
D 12
		fmap = &wwfmap[rr][cc];
E 12
I 12
		fmap = &f->ww_fmap[r][c];
E 12
I 11
		oldcode = *fmap;
E 11
		*fmap |= code;
		if (code & WWF_TOP)
			*fmap &= ~WWF_LABEL;
D 11
		code = *(unsigned char *)fmap;
	}
E 7
	r = rr - f->ww_w.t;
	c = cc - f->ww_w.l;
	if (f->ww_win[r][c] == WWM_GLS)
		f->ww_nvis[r]++;
	f->ww_win[r][c] &= ~WWM_GLS;
D 7
	f->ww_buf[f->ww_scroll + r][c].c_w = tt.tt_frame[code] & WWC_CMASK;
	if (wwsmap[rr][cc] == f->ww_index)
		wwns[rr][cc].c_w = tt.tt_frame[code] & WWC_CMASK;
E 7
I 7
	if ((code & WWF_LABEL) == 0) {
		register tmp;
E 11
I 11
		code = *fmap;
	} else
		oldcode = 0;
	{
D 12
		register r, c;
E 11

D 11
		tmp = tt.tt_frame[code & WWF_MASK] & WWC_CMASK;
		f->ww_buf[f->ww_scroll + r][c].c_w = tmp;
D 9
		if (wwsmap[rr][cc] == f->ww_index)
E 9
I 9
		if (wwsmap[rr][cc] == f->ww_index) {
			wwtouched[rr] = 1;
E 9
			wwns[rr][cc].c_w = tmp;
E 11
I 11
		r = rr - f->ww_w.t;
		c = cc - f->ww_w.l;
E 12
D 15
		{
			register char *win = &f->ww_win[r][c];
E 15
I 15
		register char *win = &f->ww_win[r][c];
E 15

D 15
			if (*win == WWM_GLS)
				f->ww_nvis[r]++;
			*win &= ~WWM_GLS;
		}
		if (oldcode != code && (code & WWF_LABEL) == 0) {
			register short frame;
E 15
I 15
D 16
		if (*win == WWM_GLS)
E 16
I 16
		if (*win == WWM_GLS && *smap == f->ww_index)
E 16
			f->ww_nvis[r]++;
		*win &= ~WWM_GLS;
	}
	if (oldcode != code && (code & WWF_LABEL) == 0) {
		register short frame;
E 15

D 15
			frame = tt.tt_frame[code & WWF_MASK] & WWC_CMASK;
			f->ww_buf[f->ww_scroll + r][c].c_w = frame;
			if (wwsmap[rr][cc] == f->ww_index) {
				wwtouched[rr] = 1;
				wwns[rr][cc].c_w = frame;
			}
E 15
I 15
D 18
		frame = tt.tt_frame[code & WWF_MASK] & WWC_CMASK;
E 18
I 18
		frame = tt.tt_frame[code & WWF_MASK];
E 18
		f->ww_buf[r][c].c_w = frame;
		if (wwsmap[r][c] == f->ww_index) {
D 17
			wwtouched[r] = 1;
E 17
I 17
			wwtouched[r] |= WWU_TOUCHED;
E 17
			wwns[r][c].c_w = frame;
E 15
E 11
I 9
		}
E 9
	}
E 7
E 5
E 3
}
I 7
D 10

/*
wwckns()
{
	register i, j;

	for (i = 0; i < wwnrow; i++)
		for (j = 0; j < wwncol; j++)
			if ((wwns[i][j].c_c & 0x7f) < ' ')
				abort();
}
*/
E 10
E 7
E 1
