h65245
s 00010/00005/00254
d D 3.20 88/06/29 21:38:46 bostic 23 22
c install approved copyright notice
e
s 00062/00039/00197
d D 3.19 88/05/11 18:04:21 edward 22 21
c scrolling region, suggestion from Ray Moody (ray@j.cc.purdue.edu)
e
s 00002/00001/00234
d D 3.18 88/02/22 22:47:45 edward 21 20
c fixed bug introduced last time (compare again nvismax/2 not nvismax)
e
s 00013/00007/00222
d D 3.17 88/02/21 13:38:53 bostic 20 19
c written by Edward Wang; attach Berkeley specific copyright
e
s 00037/00035/00192
d D 3.16 88/02/11 23:24:34 edward 19 18
c use hardware scroll for full screen windows even if no insert/delete line,
c really a bug fix
e
s 00009/00002/00218
d D 3.15 87/10/02 00:30:05 edward 18 16
c bug fix: set touched when insert and delete are used to scroll
c a non-full width window.  also, fixed some setting and non-setting
c of WWU_MAJOR.
e
s 00009/00002/00218
d R 3.15 87/10/01 22:52:13 edward 17 16
c bug fix: set lines to touched if used insert to scroll a non-full width
c window. also, changed some WWU_TOUCHED to WWU_MAJOR as well.
e
s 00019/00007/00201
d D 3.14 87/05/18 12:11:23 edward 16 15
c use \n at bottom to scroll entire screen,
c use clear to eos to clear entire screen
e
s 00006/00000/00202
d D 3.13 85/04/24 16:17:41 edward 15 14
c copyright messages
e
s 00001/00001/00201
d D 3.12 84/05/23 01:59:18 edward 14 13
c new sccs id
e
s 00004/00004/00198
d D 3.11 83/12/02 22:46:10 edward 13 12
c WWU_MAJOR, clreol in wwupdate(), and more optimizations.
e
s 00038/00041/00164
d D 3.10 83/09/15 10:10:30 edward 12 11
c Now uses screen address for all buffers.
e
s 00047/00047/00158
d D 3.9 83/09/14 14:16:54 edward 11 10
c Off screen windows!!!!!!
e
s 00006/00002/00199
d D 3.8 83/08/24 18:14:35 edward 10 9
c check tt_retain in scrollling up, instead of down (for hp2621)
e
s 00001/00001/00200
d D 3.7 83/08/24 17:46:28 edward 9 8
c knows about the bd flag now
e
s 00014/00002/00187
d D 3.6 83/08/22 12:19:02 edward 8 7
c bug in setting wwtouched with dumb terminals
e
s 00001/00001/00188
d D 3.5 83/08/22 11:44:49 edward 7 6
c lint
e
s 00058/00030/00131
d D 3.4 83/08/18 15:29:44 edward 6 5
c scrolling has come
e
s 00040/00015/00121
d D 3.3 83/08/16 12:55:45 edward 5 4
c wwtouched added
e
s 00001/00000/00135
d D 3.2 83/08/15 18:15:31 edward 4 3
c tt cleanup
e
s 00000/00000/00135
d D 3.1 83/08/12 15:13:55 edward 3 2
c created with wrong version number
e
s 00000/00001/00135
d D 1.2 83/08/12 11:41:54 edward 2 1
c lint
e
s 00136/00000/00000
d D 1.1 83/08/11 17:21:55 edward 1 0
c date and time created 83/08/11 17:21:55 by edward
e
u
U
t
T
I 1
D 20
#ifndef lint
D 14
static	char *sccsid = "%W% %E%";
E 14
I 14
static char sccsid[] = "%W% %G%";
E 14
#endif

E 20
I 15
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
E 20
 */
I 20

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 20

E 15
#include "ww.h"
I 4
#include "tt.h"
E 4

I 6
wwscroll(w, n)
register struct ww *w;
D 12
register n;
E 12
I 12
int n;
E 12
{
D 12
	int dir;
	register scroll;
E 12
I 12
	register dir;
	register top;
E 12

	if (n == 0)
		return;
	dir = n < 0 ? -1 : 1;
D 12
	scroll = w->ww_scroll + n;
	if (scroll < 0)
		scroll = 0;
	else if (scroll > w->ww_nline - w->ww_w.nr)
		scroll = w->ww_nline - w->ww_w.nr;
	n = abs(scroll - w->ww_scroll);
E 12
I 12
	top = w->ww_b.t - n;
	if (top > w->ww_w.t)
		top = w->ww_w.t;
	else if (top + w->ww_b.nr < w->ww_w.b)
		top = w->ww_w.b - w->ww_b.nr;
	n = abs(top - w->ww_b.t);
E 12
D 11
	if (n < w->ww_w.nr) {
E 11
I 11
	if (n < w->ww_i.nr) {
E 11
		while (--n >= 0) {
D 7
			wwscroll1(w, 0, w->ww_w.nr - 1, dir, 0);
E 7
I 7
D 11
			(void) wwscroll1(w, 0, w->ww_w.nr - 1, dir, 0);
E 11
I 11
D 12
			(void) wwscroll1(w, w->ww_i.t - w->ww_w.t,
				w->ww_i.b - w->ww_w.t, dir, 0);
E 11
E 7
			w->ww_scroll += dir;
E 12
I 12
			(void) wwscroll1(w, w->ww_i.t, w->ww_i.b, dir, 0);
			w->ww_buf += dir;
			w->ww_b.t -= dir;
			w->ww_b.b -= dir;
E 12
		}
	} else {
D 12
		w->ww_scroll = scroll;
E 12
I 12
		w->ww_buf -= top - w->ww_b.t;
		w->ww_b.t = top;
		w->ww_b.b = top + w->ww_b.nr;
E 12
		wwredrawwin(w);
	}
}

E 6
/*
D 6
 * Scroll down one line, starting at 'line'.
E 6
I 6
D 11
 * Scroll one line, between 'srow' and 'erow', in direction 'dir'.
E 11
I 11
 * Scroll one line, between 'row1' and 'row2', in direction 'dir'.
E 11
E 6
 * Don't adjust ww_scroll.
I 6
 * And don't redraw 'leaveit' lines.
E 6
 */
D 11
wwscroll1(w, srow, erow, dir, leaveit)
E 11
I 11
wwscroll1(w, row1, row2, dir, leaveit)
E 11
register struct ww *w;
D 11
int srow, erow, dir;
E 11
I 11
int row1, row2, dir;
E 11
D 6
char leaveit;
E 6
I 6
int leaveit;
E 6
{
	register i;
D 2
	int j;
E 2
D 6
	int startrow, endrow;
E 6
I 6
D 11
	int srow1, erow1;
E 11
I 11
	int row1x, row2x;
E 11
E 6
	int nvis;
	int nvismax;
D 22
	int deleted = 0;
E 22
I 22
	int scrolled = 0;
	int (*scroll_func)();
E 22

	/*
	 * See how many lines on the screen are affected.
D 11
	 * And calculate srow, erow, and left at the same time.
E 11
I 11
	 * And calculate row1x, row2x, and left at the same time.
E 11
	 */
D 11
	for (i = srow; i <= erow && w->ww_nvis[i] == 0; i++)
E 11
I 11
	for (i = row1; i < row2 && w->ww_nvis[i] == 0; i++)
E 11
		;
D 6
	if ((startrow = i) > erow) {
E 6
I 6
D 11
	if ((srow1 = i) > erow) {
E 6
		/* can't do any fancy stuff */
D 6
		endrow = startrow - 1;
E 6
I 6
		erow1 = srow1 - 1;
E 11
I 11
	if (i >= row2)			/* can't do any fancy stuff */
E 11
E 6
		goto out;
D 11
	}
	for (i = erow; i >= srow && w->ww_nvis[i] == 0; i--)
E 11
I 11
	row1x = i;
	for (i = row2 - 1; i >= row1 && w->ww_nvis[i] == 0; i--)
E 11
		;
D 6
	if ((endrow = i) == startrow)
E 6
I 6
D 11
	if ((erow1 = i) == srow1)
E 11
I 11
	if (i <= row1x)
E 11
E 6
		goto out;		/* just one line is easy */
I 11
	row2x = i + 1;
E 11

	/*
	 * See how much of this window is visible.
	 */
D 6
	nvismax = wwncol * (endrow - startrow + 1);
E 6
I 6
D 11
	nvismax = wwncol * (erow1 - srow1 + 1);
E 11
I 11
	nvismax = wwncol * (row2x - row1x);
E 11
E 6
	nvis = 0;
D 6
	for (i = startrow; i <= endrow; i++)
E 6
I 6
D 11
	for (i = srow1; i <= erow1; i++)
E 11
I 11
	for (i = row1x; i < row2x; i++)
E 11
E 6
		nvis += w->ww_nvis[i];

	/*
D 19
	 * If it's a good idea to use delete and insert line
	 * and the terminal can, then do it.
E 19
I 19
	 * If it's a good idea to scroll and the terminal can, then do it.
I 22
	 * We handle retain (da and db) by putting the burden on scrolling up,
	 * which is the less common operation.  It must ensure that
	 * text is not pushed below the screen, so scrolling down doesn't
	 * have to worry about it.
E 22
E 19
	 */
D 19
	if (nvis > nvismax / 2 && tt.tt_delline && tt.tt_insline) {
		register union ww_char *tmp;
		register union ww_char **cpp, **cqq;

E 19
I 19
D 21
	if (nvis < nvismax) {
E 21
I 21
D 22
	if (nvis < nvismax / 2) {
		/* not worth it */
E 21
	} else if (!tt.tt_noscroll && row1x == 0 && row2x == wwnrow && dir > 0)
	{
E 19
I 10
		/*
I 19
		 * We're going to assume that a line feed at the
		 * bottom of the screen will cause a scroll, unless
		 * "ns" is set.  This should work at least 99%
		 * of the time.  At any rate, vi seems to do it.
		 */
		if (tt.tt_row != wwnrow - 1)
			(*tt.tt_move)(wwnrow - 1, 0);
		ttputc('\n');
		deleted++;
	} else if (tt.tt_delline && tt.tt_insline) {
		/*
E 19
D 16
		 * Don't worry about retain when scrolling down.
		 * But do worry when scrolling up.  For hp2621.
E 16
I 16
		 * Don't worry about retain when scrolling down,
		 * but do worry when scrolling up, for hp2621.
E 16
		 */
E 10
		if (dir > 0) {
D 6
			(*tt.tt_move)(startrow + w->ww_w.t, 0);
E 6
I 6
D 11
			(*tt.tt_move)(srow1 + w->ww_w.t, 0);
E 11
I 11
D 12
			(*tt.tt_move)(row1x + w->ww_w.t, 0);
E 12
I 12
D 16
			(*tt.tt_move)(row1x, 0);
E 12
E 11
E 6
			(*tt.tt_delline)();
D 6
			if (endrow + w->ww_w.t != wwnrow - 1) {
				(*tt.tt_move)(endrow + w->ww_w.t, 0);
E 6
I 6
D 9
			if (erow1 + w->ww_w.t != wwnrow - 1) {
E 9
I 9
D 10
			if (tt.tt_retain || erow1 + w->ww_w.t != wwnrow - 1) {
E 10
I 10
D 11
			if (erow1 + w->ww_w.t != wwnrow - 1) {
E 10
E 9
				(*tt.tt_move)(erow1 + w->ww_w.t, 0);
E 11
I 11
D 12
			if (row2x + w->ww_w.t < wwnrow) {
				(*tt.tt_move)(row2x + w->ww_w.t - 1, 0);
E 12
I 12
			if (row2x < wwnrow) {
				(*tt.tt_move)(row2x - 1, 0);
E 12
E 11
E 6
				(*tt.tt_insline)();
E 16
I 16
D 19
			/*
			 * We're going to assume that a line feed at the
			 * bottom of the screen will cause a scroll, unless
			 * "ns" is set.  This should work at least 99%
			 * of the time.  At any rate, vi seems to do it.
			 */
			if (tt.tt_noscroll || row1x != 0 || row2x != wwnrow) {
				(*tt.tt_move)(row1x, 0);
E 19
I 19
			(*tt.tt_move)(row1x, 0);
			(*tt.tt_delline)();
			if (row2x < wwnrow) {
				(*tt.tt_move)(row2x - 1, 0);
				(*tt.tt_insline)();
			}
		} else {
			if (tt.tt_retain || row2x != wwnrow) {
				(*tt.tt_move)(row2x - 1, 0);
E 19
				(*tt.tt_delline)();
D 19
				if (row2x < wwnrow) {
					(*tt.tt_move)(row2x - 1, 0);
					(*tt.tt_insline)();
				}
			} else {
				if (tt.tt_row != wwnrow - 1)
					(*tt.tt_move)(wwnrow - 1, 0);
				ttputc('\n');
E 19
E 16
			}
D 19
			/*
			 * Fix up the old screen.
			 */
E 19
I 19
			(*tt.tt_move)(row1x, 0);
E 22
I 22
	if (nvis < nvismax / 2)
		goto no_scroll;		/* not worth it */
	/*
	 * Try scrolling region (or scrolling the whole screen) first.
	 * Can we assume "sr" doesn't push text below the screen
	 * so we don't have to worry about retain below?
	 * What about scrolling down with a newline?  It probably does
	 * push text above (with da).  Scrolling up would then have
	 * to take care of that.
	 * It's easy to be fool proof, but that slows things down.
	 * The current solution is to disallow tt_scroll_up if da or db is true
	 * but cs (scrolling region) is not.  Again, we sacrifice scrolling
	 * up in favor of scrolling down.  The idea is having scrolling regions
	 * probably means we can scroll (even the whole screen) with impunity.
	 * This lets us work efficiently on simple terminals (use newline
	 * on the bottom to scroll), on any terminal without retain, and
	 * on vt100 style scrolling regions (I think).
	 */
	if (scroll_func = dir > 0 ? tt.tt_scroll_down : tt.tt_scroll_up) {
		if (tt.tt_scroll_top != row1x || tt.tt_scroll_bot != row2x - 1)
			if (tt.tt_setscroll == 0)
				scroll_func = 0;
			else
				(*tt.tt_setscroll)(row1x, row2x - 1);
		if (scroll_func) {
			(*scroll_func)();
			goto did_scroll;
		}
	}
	/*
	 * Try insert/delete line.
	 * Don't worry about retain when scrolling down,
	 * but do worry when scrolling up, for hp2621.
	 */
	if (tt.tt_delline == 0 || tt.tt_insline == 0)
		goto no_scroll;
	if (dir > 0) {
		(*tt.tt_move)(row1x, 0);
		(*tt.tt_delline)();
		if (row2x < wwnrow) {
			(*tt.tt_move)(row2x - 1, 0);
E 22
			(*tt.tt_insline)();
		}
D 22
		deleted++;
E 22
I 22
	} else {
		if (tt.tt_retain || row2x != wwnrow) {
			(*tt.tt_move)(row2x - 1, 0);
			(*tt.tt_delline)();
		}
		(*tt.tt_move)(row1x, 0);
		(*tt.tt_insline)();
E 22
	}
I 22
did_scroll:
	scrolled = 1;
E 22
	/*
	 * Fix up the old screen.
	 */
D 22
	if (deleted) {
E 22
I 22
	{
E 22
		register union ww_char *tmp;
		register union ww_char **cpp, **cqq;

		if (dir > 0) {
E 19
D 6
			cpp = &wwos[startrow + w->ww_w.t];
E 6
I 6
D 11
			cpp = &wwos[srow1 + w->ww_w.t];
E 11
I 11
D 12
			cpp = &wwos[row1x + w->ww_w.t];
E 12
I 12
			cpp = &wwos[row1x];
E 12
E 11
E 6
			cqq = cpp + 1;
			tmp = *cpp;
D 6
			for (i = endrow - startrow; --i >= 0;)
E 6
I 6
D 11
			for (i = erow1 - srow1; --i >= 0;)
E 11
I 11
			for (i = row2x - row1x; --i > 0;)
E 11
E 6
				*cpp++ = *cqq++;
			*cpp = tmp;
D 12
			for (i = wwncol; --i >= 0;)
				tmp++->c_w = ' ';
E 12
		} else {
D 6
			if (endrow + w->ww_w.t != wwnrow - 1) {
				(*tt.tt_move)(endrow + w->ww_w.t, 0);
E 6
I 6
D 10
			if (erow1 + w->ww_w.t != wwnrow - 1) {
E 10
I 10
D 11
			if (tt.tt_retain || erow1 + w->ww_w.t != wwnrow - 1) {
E 10
				(*tt.tt_move)(erow1 + w->ww_w.t, 0);
E 11
I 11
D 12
			if (tt.tt_retain || row2x + w->ww_w.t != wwnrow) {
				(*tt.tt_move)(row2x + w->ww_w.t - 1, 0);
E 12
I 12
D 19
			if (tt.tt_retain || row2x != wwnrow) {
				(*tt.tt_move)(row2x - 1, 0);
E 12
E 11
E 6
				(*tt.tt_delline)();
			}
D 6
			(*tt.tt_move)(startrow + w->ww_w.t, 0);
E 6
I 6
D 11
			(*tt.tt_move)(srow1 + w->ww_w.t, 0);
E 11
I 11
D 12
			(*tt.tt_move)(row1x + w->ww_w.t, 0);
E 12
I 12
			(*tt.tt_move)(row1x, 0);
E 12
E 11
E 6
			(*tt.tt_insline)();
			/*
			 * Fix up the old screen.
			 */
E 19
D 6
			cqq = &wwos[endrow + w->ww_w.t];
E 6
I 6
D 11
			cqq = &wwos[erow1 + w->ww_w.t];
E 6
			cpp = cqq + 1;
E 11
I 11
D 12
			cpp = &wwos[row2x + w->ww_w.t];
E 12
I 12
			cpp = &wwos[row2x];
E 12
			cqq = cpp - 1;
E 11
			tmp = *cqq;
D 6
			for (i = endrow - startrow; --i >= 0;)
E 6
I 6
D 11
			for (i = erow1 - srow1; --i >= 0;)
E 11
I 11
			for (i = row2x - row1x; --i > 0;)
E 11
E 6
				*--cpp = *--cqq;
			*cqq = tmp;
D 12
			for (i = wwncol; --i >= 0;)
				tmp++->c_w = ' ';
E 12
		}
I 12
		for (i = wwncol; --i >= 0;)
			tmp++->c_w = ' ';
E 12
D 19
		deleted++;
E 19
	}

I 22
no_scroll:
E 22
	/*
	 * Fix the new screen.
	 */
	if (nvis == nvismax) {
		/*
		 * Can shift whole lines.
		 */
D 5
		register union ww_char *tmp;
		register union ww_char **cpp, **cqq;

E 5
		if (dir > 0) {
D 5
			cpp = &wwns[startrow + w->ww_w.t];
			cqq = cpp + 1;
			tmp = *cpp;
			for (i = endrow - startrow; --i >= 0;)
				*cpp++ = *cqq++;
			*cpp = tmp;
E 5
I 5
			{
				register union ww_char *tmp;
				register union ww_char **cpp, **cqq;

D 6
				cpp = &wwns[startrow + w->ww_w.t];
E 6
I 6
D 11
				cpp = &wwns[srow1 + w->ww_w.t];
E 11
I 11
D 12
				cpp = &wwns[row1x + w->ww_w.t];
E 12
I 12
				cpp = &wwns[row1x];
E 12
E 11
E 6
				cqq = cpp + 1;
				tmp = *cpp;
D 6
				for (i = endrow - startrow; --i >= 0;)
E 6
I 6
D 11
				for (i = erow1 - srow1; --i >= 0;)
E 11
I 11
				for (i = row2x - row1x; --i > 0;)
E 11
E 6
					*cpp++ = *cqq++;
				*cpp = tmp;
			}
D 8
			{
E 8
I 8
D 22
			if (deleted) {
E 22
I 22
			if (scrolled) {
E 22
E 8
				register char *p, *q;

D 6
				p = &wwtouched[startrow + w->ww_w.t];
E 6
I 6
D 11
				p = &wwtouched[srow1 + w->ww_w.t];
E 11
I 11
D 12
				p = &wwtouched[row1x + w->ww_w.t];
E 12
I 12
				p = &wwtouched[row1x];
E 12
E 11
E 6
				q = p + 1;
D 6
				for (i = endrow - startrow; --i >= 0;)
E 6
I 6
D 11
				for (i = erow1 - srow1; --i >= 0;)
E 11
I 11
				for (i = row2x - row1x; --i > 0;)
E 11
E 6
					*p++ = *q++;
D 13
				*p = 1;
E 13
I 13
				*p |= WWU_TOUCHED;
E 13
I 8
			} else {
				register char *p;

D 11
				p = &wwtouched[srow1 + w->ww_w.t];
				for (i = erow1 - srow1 + 1; --i >= 0;)
E 11
I 11
D 12
				p = &wwtouched[row1x + w->ww_w.t];
E 12
I 12
				p = &wwtouched[row1x];
E 12
				for (i = row2x - row1x; --i >= 0;)
E 11
D 13
					*p++ = 1;
E 13
I 13
					*p++ |= WWU_MAJOR|WWU_TOUCHED;
E 13
E 8
			}
E 5
D 6
			wwredrawwin1(w, srow, startrow - 1, w->ww_scroll + dir);
			wwredrawwin1(w, endrow + 1, erow - leaveit,
E 6
I 6
D 11
			wwredrawwin1(w, srow, srow1 - 1, w->ww_scroll + dir);
			wwredrawwin1(w, erow1, erow - leaveit,
E 11
I 11
D 12
			wwredrawwin1(w, row1, row1x, w->ww_scroll + dir);
			wwredrawwin1(w, row2x - 1, row2 - leaveit,
E 11
E 6
				w->ww_scroll + dir);
E 12
I 12
			wwredrawwin1(w, row1, row1x, dir);
			wwredrawwin1(w, row2x - 1, row2 - leaveit, dir);
E 12
		} else {
D 5
			cqq = &wwns[endrow + w->ww_w.t];
			cpp = cqq + 1;
			tmp = *cqq;
			for (i = endrow - startrow; --i >= 0;)
				*--cpp = *--cqq;
			*cqq = tmp;
E 5
I 5
			{
				register union ww_char *tmp;
				register union ww_char **cpp, **cqq;

D 6
				cqq = &wwns[endrow + w->ww_w.t];
E 6
I 6
D 11
				cqq = &wwns[erow1 + w->ww_w.t];
E 6
				cpp = cqq + 1;
E 11
I 11
D 12
				cpp = &wwns[row2x + w->ww_w.t];
E 12
I 12
				cpp = &wwns[row2x];
E 12
				cqq = cpp - 1;
E 11
				tmp = *cqq;
D 6
				for (i = endrow - startrow; --i >= 0;)
E 6
I 6
D 11
				for (i = erow1 - srow1; --i >= 0;)
E 11
I 11
				for (i = row2x - row1x; --i > 0;)
E 11
E 6
					*--cpp = *--cqq;
				*cqq = tmp;
			}
D 8
			{
E 8
I 8
D 22
			if (deleted) {
E 22
I 22
			if (scrolled) {
E 22
E 8
				register char *p, *q;

D 6
				q = &wwtouched[endrow + w->ww_w.t];
E 6
I 6
D 11
				q = &wwtouched[erow1 + w->ww_w.t];
E 6
				p = q + 1;
D 6
				for (i = endrow - startrow; --i >= 0;)
E 6
I 6
				for (i = erow1 - srow1; --i >= 0;)
E 11
I 11
D 12
				p = &wwtouched[row2x + w->ww_w.t];
E 12
I 12
				p = &wwtouched[row2x];
E 12
				q = p - 1;
				for (i = row2x - row1x; --i > 0;)
E 11
E 6
					*--p = *--q;
D 13
				*q = 1;
E 13
I 13
D 18
				*q |= WWU_MAJOR|WWU_TOUCHED;
E 18
I 18
				*q |= WWU_TOUCHED;
E 18
E 13
I 8
			} else {
				register char *p;

D 11
				p = &wwtouched[srow1 + w->ww_w.t];
				for (i = erow1 - srow1 + 1; --i >= 0;)
E 11
I 11
D 12
				p = &wwtouched[row1x + w->ww_w.t];
E 12
I 12
				p = &wwtouched[row1x];
E 12
				for (i = row2x - row1x; --i >= 0;)
E 11
D 13
					*p++ = 1;
E 13
I 13
D 18
					*p++ |= WWU_TOUCHED;
E 18
I 18
					*p++ |= WWU_MAJOR|WWU_TOUCHED;
E 18
E 13
E 8
			}
E 5
D 6
			wwredrawwin1(w, srow + leaveit, startrow - 1,
E 6
I 6
D 11
			wwredrawwin1(w, srow + leaveit, srow1,
E 11
I 11
D 12
			wwredrawwin1(w, row1 + leaveit, row1x - 1,
E 11
E 6
				w->ww_scroll + dir);
D 6
			wwredrawwin1(w, endrow + 1, erow, w->ww_scroll + dir);
E 6
I 6
D 11
			wwredrawwin1(w, erow1 + 1, erow, w->ww_scroll + dir);
E 11
I 11
			wwredrawwin1(w, row2x, row2, w->ww_scroll + dir);
E 12
I 12
			wwredrawwin1(w, row1 + leaveit, row1x + 1, dir);
			wwredrawwin1(w, row2x, row2, dir);
E 12
E 11
E 6
		}
	} else {
I 18
D 22
		if (deleted) {
E 22
I 22
		if (scrolled) {
E 22
			register char *p;

			p = &wwtouched[row1x];
			for (i = row2x - row1x; --i >= 0;)
				*p++ |= WWU_MAJOR|WWU_TOUCHED;
		}
E 18
out:
		if (dir > 0)
D 11
			wwredrawwin1(w, srow, erow - leaveit,
E 11
I 11
D 12
			wwredrawwin1(w, row1, row2 - leaveit,
E 11
				w->ww_scroll + dir);
E 12
I 12
			wwredrawwin1(w, row1, row2 - leaveit, dir);
E 12
		else
D 11
			wwredrawwin1(w, srow + leaveit, erow,
E 11
I 11
D 12
			wwredrawwin1(w, row1 + leaveit, row2,
E 11
				w->ww_scroll + dir);
E 12
I 12
			wwredrawwin1(w, row1 + leaveit, row2, dir);
E 12
	}
D 22
	return deleted;
E 22
I 22
	return scrolled;
E 22
}
E 1
