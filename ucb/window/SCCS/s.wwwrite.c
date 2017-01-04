h55027
s 00010/00005/00259
d D 3.28 88/06/29 21:39:03 bostic 36 35
c install approved copyright notice
e
s 00013/00007/00251
d D 3.27 88/02/21 13:39:04 bostic 35 34
c written by Edward Wang; attach Berkeley specific copyright
e
s 00003/00003/00255
d D 3.26 88/01/03 00:56:15 bostic 34 33
c fix ctrl macro for ANSI C
e
s 00012/00012/00246
d D 3.25 87/05/18 12:20:24 edward 33 32
c added keepopen and smooth flags, added + and - window selections
e
s 00011/00005/00247
d D 3.24 86/08/05 00:17:20 edward 32 31
c delay calling wwupdate1() until cursor moved off this line
c or a insert/delete line
e
s 00011/00016/00241
d D 3.23 86/08/04 14:16:19 edward 31 29
c WWM_USR and WWM_DIM added, termcap strings XS and XE added,
c display mode escape sequences changed
e
s 00006/00000/00257
d R 3.23 86/05/02 13:35:33 edward 30 29
c added WWM_USR (user mode) and XS and XE termcap strings
e
s 00006/00000/00251
d D 3.22 85/04/24 16:12:39 edward 29 28
c copyright messages
e
s 00001/00001/00250
d D 3.21 84/05/23 01:56:48 edward 28 27
c new sccs id
e
s 00003/00000/00248
d D 3.20 84/04/09 23:29:08 edward 27 26
c lint
e
s 00048/00012/00200
d D 3.19 84/04/08 12:08:10 edward 26 25
c control character expansion in wwwrite()
c calling of wwupdate() in wwwrite() dependent of ww_noupdate
c control character handling macros in char.h
e
s 00045/00042/00167
d D 3.18 84/03/03 22:43:27 edward 25 24
c interrupt driven input
e
s 00002/00001/00207
d D 3.17 84/01/16 15:24:23 edward 24 23
c return the number of chars written.
e
s 00006/00000/00202
d D 3.16 84/01/11 16:29:22 edward 23 22
c make graphics mode available to user
e
s 00004/00002/00198
d D 3.15 83/12/06 12:25:42 edward 22 21
c check for negatives in cursor address sequence
e
s 00014/00029/00186
d D 3.14 83/12/02 22:44:53 edward 21 20
c WWU_MAJOR, clreol in wwupdate(), and more optimizations.
e
s 00014/00006/00201
d D 3.13 83/09/15 13:27:46 edward 20 19
c inline expand some function calls
e
s 00001/00000/00206
d D 3.12 83/09/15 10:49:27 edward 19 18
c Forgot to fix ww_buf after ^[E.
e
s 00061/00055/00145
d D 3.11 83/09/15 10:08:53 edward 18 17
c Now uses screen address for all buffers.
e
s 00054/00044/00146
d D 3.10 83/09/14 14:14:40 edward 17 16
c Off screen windows!!!!!!
e
s 00001/00004/00189
d D 3.9 83/08/26 16:25:08 edward 16 15
c error reporting
e
s 00003/00003/00190
d D 3.8 83/08/23 19:33:10 edward 15 14
c didn't do it right
e
s 00002/00001/00191
d D 3.7 83/08/23 18:58:06 edward 14 13
c didn't use ww_modes when inserting char
e
s 00005/00000/00187
d D 3.6 83/08/19 15:04:54 edward 13 12
c fake cursor
e
s 00016/00004/00171
d D 3.5 83/08/18 15:29:22 edward 12 11
c scrolling has come
e
s 00015/00002/00160
d D 3.4 83/08/17 14:51:37 edward 11 10
c ww_availmodes and stuff
e
s 00044/00022/00118
d D 3.3 83/08/16 17:07:01 edward 10 9
c smart wwrite:  copy in chunks.
e
s 00001/00003/00139
d D 3.2 83/08/16 12:54:36 edward 9 8
c wwtouched added
e
s 00024/00014/00118
d D 3.1 83/08/11 17:21:43 edward 8 6
i 7
c last few day's work
e
s 00052/00031/00080
d D 2.1.1.1 83/08/09 18:35:00 edward 7 6
c mile stone
e
s 00000/00000/00111
d D 2.1 83/07/30 13:27:22 edward 6 5
c prepare for major change
e
s 00004/00002/00107
d D 1.5 83/07/27 14:33:19 edward 5 4
c io statistics
e
s 00002/00002/00107
d D 1.4 83/07/22 17:09:11 edward 4 3
c scrolling.
c uses Wscreensize() to get screen size.
c More intelligent framing.
c etc.
e
s 00000/00000/00109
d D 1.3 83/07/19 20:07:54 edward 3 2
c today's work
e
s 00004/00012/00105
d D 1.2 83/07/18 21:03:45 edward 2 1
c multiple window
e
s 00117/00000/00000
d D 1.1 83/07/17 15:19:05 edward 1 0
c date and time created 83/07/17 15:19:05 by edward
e
u
U
f b 
t
T
I 1
D 35
#ifndef lint
D 28
static	char *sccsid = "%W% %E%";
E 28
I 28
static char sccsid[] = "%W% %G%";
E 28
#endif

E 35
I 29
/*
D 35
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 35
I 35
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 36
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 36
I 36
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
E 36
E 35
 */
I 35

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 35

E 29
#include "ww.h"
I 25
#include "tt.h"
I 26
#include "char.h"
E 26
E 25

I 33
#define UPDATE() \
	if (!w->ww_noupdate && w->ww_cur.r >= 0 && w->ww_cur.r < wwnrow && \
	    wwtouched[w->ww_cur.r]) \
		wwupdate1(w->ww_cur.r, w->ww_cur.r + 1)

E 33
I 26
/*
 * To support control character expansion, we save the old
 * p and q values in r and s, and point p at the beginning
 * of the expanded string, and q at some safe place beyond it
 * (p + 10).  At strategic points in the loops, we check
 * for (r && !*p) and restore the saved values back into
 * p and q.  Essentially, we implement a stack of depth 2,
 * to avoid recursion, which might be a better idea.
 */
E 26
D 5
int wwnwrite = 0;
E 5
I 5
D 9
int wwnwrite;
int wwnwritec;
E 5

E 9
wwwrite(w, p, n)
register struct ww *w;
register char *p;
D 10
register n;
E 10
I 10
int n;
E 10
{
D 10
	register char c;
E 10
I 10
D 17
	char c;
E 10
I 7
D 16
	int oldn = n;
E 16
I 13
	char hascursor = 0;
E 17
I 17
	char hascursor;
I 24
D 25
	int saven = n;
E 25
I 25
	char *savep = p;
	char *q = p + n;
I 26
	char *r = 0;
	char *s;
E 26
E 25
E 24
E 17
E 13
E 7

I 27
#ifdef lint
	s = 0;			/* define it before possible use */
#endif
E 27
D 7
	if (w == 0 || w->ww_win == 0)
E 7
I 7
D 16
	if (w == 0)
E 7
		return -1;
E 16
D 5
	wwnwrite += n;
E 5
I 5
D 25
	wwnwrite++;
	wwnwritec += n;
E 25
I 13
	if (hascursor = w->ww_hascursor)
		wwcursor(w, 0);
E 13
E 5
D 7
	while (n-- > 0) {
E 7
I 7
D 17
	while (--n >= 0) {
E 7
		c = *p++ & 0x7f;
		switch (w->ww_wstate) {
		case 0:
I 8
D 10
			asm("_wwwrite1:");
E 8
			if (c >= ' ' && c < 0x7f) {
I 7
				register i, j, cc;
E 10
I 10
			if (!ISCTRL(c)) {
				int i, j;
				register union ww_char *bp;
				union ww_char *bq;
E 17
I 17
D 25
	while (n > 0) {
E 25
I 25
	while (p < q && !w->ww_stopped && (!wwinterrupt() || w->ww_nointr)) {
E 25
D 26
		if (w->ww_wstate == 0 && !ISCTRL(*p)) {
E 26
I 26
		if (r && !*p) {
			p = r;
			q = s;
			r = 0;
			continue;
		}
D 33
		if (w->ww_wstate == 0 && (isprt(*p)
		    || w->ww_unctrl && isunctrl(*p))) {
E 33
I 33
		if (w->ww_wstate == 0 &&
		    (isprt(*p) || w->ww_unctrl && isunctrl(*p))) {
E 33
E 26
			register i;
D 18
			int crow, ccol;
E 18
			register union ww_char *bp;
D 25
			union ww_char *bq;
E 25
I 18
D 21
			int col;
E 21
I 21
			int col, col1;
E 21
E 18

D 21
			if (w->ww_insert) {
E 21
I 21
			if (w->ww_insert) {	/* this is very slow */
E 21
D 25
				n--;
E 25
I 25
				if (*p == '\t') {
					p++;
					w->ww_cur.c += 8 -
						(w->ww_cur.c - w->ww_w.l & 7);
					goto chklf;
				}
I 26
				if (!isprt(*p)) {
					r = p + 1;
					s = q;
					p = unctrl(*p);
					q = p + 10;
				}
E 26
E 25
D 18
				wwinschar(w, w->ww_scroll + w->ww_cur.r,
					w->ww_cur.c,
E 18
I 18
				wwinschar(w, w->ww_cur.r, w->ww_cur.c,
E 18
					*p++ | w->ww_modes << WWC_MSHIFT);
				goto right;
			}

D 18
			bp = bq = &w->ww_buf[w->ww_scroll+w->ww_cur.r]
				[w->ww_cur.c];
			if ((i = w->ww_w.nc - w->ww_cur.c) > n)
E 18
I 18
D 25
			bp = bq = &w->ww_buf[w->ww_cur.r][w->ww_cur.c];
			if ((i = w->ww_b.r - w->ww_cur.c) > n)
E 18
				i = n;
			while (--i >= 0 && !ISCTRL(*p))
				bp++->c_w = *p++ | w->ww_modes << WWC_MSHIFT;
E 25
I 25
			bp = &w->ww_buf[w->ww_cur.r][w->ww_cur.c];
			i = w->ww_cur.c;
D 26
			while (i < w->ww_w.r && p < q && !ISCTRL(*p))
				if (*p == '\t') {
E 26
I 26
			while (i < w->ww_w.r && p < q)
				if (!*p && r) {
					p = r;
					q = s;
					r = 0;
				} else if (*p == '\t') {
E 26
					register tmp = 8 - (i - w->ww_w.l & 7);
					p++;
					i += tmp;
					bp += tmp;
D 26
				} else {
E 26
I 26
				} else if (isprt(*p)) {
E 26
					bp++->c_w = *p++
						| w->ww_modes << WWC_MSHIFT;
					i++;
D 26
				}
E 25
I 18

E 26
I 26
				} else if (w->ww_unctrl && isunctrl(*p)) {
					r = p + 1;
					s = q;
					p = unctrl(*p);
					q = p + 10;
				} else
					break;
E 26
E 18
D 25
			i = bp - bq;
			n -= i;
E 25
I 18
D 21
			col = w->ww_cur.c;
E 21
I 21
			col = MAX(w->ww_cur.c, w->ww_i.l);
E 21
D 25
			w->ww_cur.c += i;
E 18
D 21
			bp = bq;
D 18

			crow = wwcurrow(w);
			ccol = wwcurcol(w);
			if (ccol < w->ww_i.l) {
				bp += w->ww_i.l - ccol;
				ccol = w->ww_i.l;
E 18
I 18
			if (col < w->ww_i.l) {
				/* use col as a temporary */
				col = w->ww_i.l - col;
				bp += col;
				i -= col;
				col = w->ww_i.l;
E 18
			}
D 18
			w->ww_cur.c += i;
			if (crow >= w->ww_i.t && crow < w->ww_i.b) {
E 18
I 18
			if (i > w->ww_i.r - col)
				i = w->ww_i.r - col;
E 21
I 21
			col1 = MIN(w->ww_cur.c, w->ww_i.r);
E 21

E 25
I 25
			col1 = MIN(i, w->ww_i.r);
			w->ww_cur.c = i;
E 25
D 26
			if (w->ww_cur.r >= w->ww_i.t && w->ww_cur.r < w->ww_i.b)
			{
E 26
I 26
			if (w->ww_cur.r >= w->ww_i.t
			    && w->ww_cur.r < w->ww_i.b) {
E 26
E 18
E 17
D 21
				register union ww_char *ns;
				register char *smap;
				register char *win;
				char *touched;
E 21
I 21
				register union ww_char *ns = wwns[w->ww_cur.r];
				register char *smap = &wwsmap[w->ww_cur.r][col];
				register char *win = w->ww_win[w->ww_cur.r];
D 25
				char touched = wwtouched[w->ww_cur.r];
E 25
I 25
				int nchanged = 0;
E 25
E 21
E 10

I 14
D 15
				c |= w->ww_modes << WWC_MSHIFT;
E 15
E 14
E 7
D 10
				if (w->ww_insert)
E 10
I 10
D 17
				if (w->ww_insert) {
E 10
D 7
					Winschars(w->ww_win, 1);
				Wputc(c, w->ww_win);
E 7
I 7
D 8
					wwinschar(w, 1);
				cc = w->ww_buf[w->ww_scroll + w->ww_cur.r]
					[w->ww_cur.c].c_w = c;
				i = wwcurrow(w);
				j = wwcurcol(w);
				if (wwsmap[i][j] == w->ww_index) {
					cc = wwns[i][j].c_w = cc
						^ w->ww_win[w->ww_cur.r]
						[w->ww_cur.c] << WWC_MSHIFT;
E 8
I 8
					wwinschar(w, w->ww_scroll + w->ww_cur.r,
D 15
						w->ww_cur.c, c);
E 15
I 15
						w->ww_cur.c,
						c | w->ww_modes << WWC_MSHIFT);
E 15
D 10
				else {
					cc = w->ww_buf[w->ww_scroll
						+ w->ww_cur.r]
						[w->ww_cur.c].c_w = c;
					i = wwcurrow(w);
					j = wwcurcol(w);
					if (wwsmap[i][j] == w->ww_index) {
I 9
						wwtouched[i] = 1;
E 9
						cc = wwns[i][j].c_w = cc
							^ w->ww_win[w->ww_cur.r]
							[w->ww_cur.c]
							<< WWC_MSHIFT;
E 10
I 10
					goto right;
				}
				i = w->ww_w.nc - w->ww_cur.c - 1;
				bp = bq = &w->ww_buf[w->ww_scroll+w->ww_cur.r]
					[w->ww_cur.c];
D 11
				bp++->c_w = c;
E 11
I 11
D 14
				bp++->c_w = c | w->ww_modes << WWC_MSHIFT;
E 14
I 14
D 15
				bp++->c_w = c;
E 15
I 15
				bp++->c_w = c | w->ww_modes << WWC_MSHIFT;
E 15
E 14
E 11
				while (n > 0 && --i >= 0 && !ISCTRL(*p)) {
					n--;
D 11
					bp++->c_w = *p++;
E 11
I 11
					bp++->c_w = *p++ & 0x7f
						| w->ww_modes << WWC_MSHIFT;
E 11
				}
				win = &w->ww_win[w->ww_cur.r][w->ww_cur.c];
				i = wwcurrow(w);
				j = wwcurcol(w);
				smap = &wwsmap[i][j];
				ns = &wwns[i][j];
				touched = &wwtouched[i];
				j = i = bp - bq;
				bp = bq;
				while (--i >= 0) {
E 17
I 17
D 18
				win = &w->ww_win[w->ww_cur.r][ccol - w->ww_w.l];
				smap = &wwsmap[crow][ccol];
				ns = &wwns[crow][ccol];
				touched = &wwtouched[crow];
				if (i > w->ww_i.r - ccol)
					i = w->ww_i.r - ccol;
E 18
I 18
D 21
				win = &w->ww_win[w->ww_cur.r][col];
				smap = &wwsmap[w->ww_cur.r][col];
				ns = &wwns[w->ww_cur.r][col];
				touched = &wwtouched[w->ww_cur.r];
E 18
				while (--i >= 0)
E 21
I 21
				bp = w->ww_buf[w->ww_cur.r];
				for (i = col; i < col1; i++)
E 21
E 17
					if (*smap++ == w->ww_index) {
D 21
						*touched = 1;
						ns++->c_w = bp++->c_w
							^ *win++ << WWC_MSHIFT;
					} else {
						ns++;
						bp++;
						win++;
E 21
I 21
D 25
						touched |= WWU_TOUCHED;
E 25
I 25
						nchanged++;
E 25
						ns[i].c_w = bp[i].c_w
							^ win[i] << WWC_MSHIFT;
E 21
E 10
					}
I 21
D 25
				wwtouched[w->ww_cur.r] = touched;
E 25
I 25
D 32
				if (nchanged > 0) {
E 32
I 32
				if (nchanged > 0)
E 32
					wwtouched[w->ww_cur.r] |= WWU_TOUCHED;
D 26
					wwupdate1(w->ww_cur.r, w->ww_cur.r + 1);
E 26
I 26
D 32
					if (!w->ww_noupdate)
						wwupdate1(w->ww_cur.r,
							w->ww_cur.r + 1);
E 26
				}
E 32
E 25
E 21
E 8
D 17
				}
D 10
		right:
				if (++w->ww_cur.c >= w->ww_w.nc) {
E 10
I 10
				if ((w->ww_cur.c += j) >= w->ww_w.nc) {
E 10
					w->ww_cur.c = 0;
					goto lf;
				}
E 7
				break;
E 17
			}
I 8
D 10
			asm("_wwwrite2:");
E 10
E 8
D 17
			switch (c) {
E 17
I 17
D 18
			if (w->ww_cur.c >= w->ww_w.nc) {
				w->ww_cur.c = 0;
E 18
I 18
D 25
			if (w->ww_cur.c >= w->ww_w.r) {
				w->ww_cur.c = w->ww_w.l;
E 18
				goto lf;
			}
			continue;
		}
		n--;
		switch (w->ww_wstate) {
E 25
I 25
D 31
			
E 31
		chklf:
			if (w->ww_cur.c >= w->ww_w.r)
				goto crlf;
		} else switch (w->ww_wstate) {
E 25
		case 0:
			switch (*p++) {
E 17
			case '\n':
D 7
				Wputc(c, w->ww_win);
				if (w->ww_refresh)
					Wrefresh(1);
E 7
I 7
				if (w->ww_mapnl)
I 25
		crlf:
E 25
D 18
					w->ww_cur.c = 0;
E 18
I 18
					w->ww_cur.c = w->ww_w.l;
E 18
		lf:
I 32
D 33
				if (!w->ww_noupdate && wwtouched[w->ww_cur.r])
					wwupdate1(w->ww_cur.r, w->ww_cur.r + 1);
E 33
I 33
				UPDATE();
E 33
E 32
D 18
				if (++w->ww_cur.r >= w->ww_w.nr) {
					w->ww_cur.r = w->ww_w.nr - 1;
D 12
					wwdelline(w, 0);
E 12
I 12
					if (w->ww_scroll + w->ww_w.nr
					    < w->ww_nline)
E 18
I 18
				if (++w->ww_cur.r >= w->ww_w.b) {
					w->ww_cur.r = w->ww_w.b - 1;
D 20
					if (w->ww_w.b < w->ww_b.b)
E 18
						wwscroll(w, 1);
					else
E 20
I 20
					if (w->ww_w.b < w->ww_b.b) {
						(void) wwscroll1(w, w->ww_i.t,
							w->ww_i.b, 1, 0);
						w->ww_buf++;
						w->ww_b.t--;
						w->ww_b.b--;
					} else
E 20
D 18
						wwdelline(w, 0);
E 18
I 18
						wwdelline(w, w->ww_b.t);
E 18
E 12
				}
E 7
				break;
D 25
			case '\t':
I 7
D 18
				w->ww_cur.c |= 7;
D 10
				goto right;
E 10
I 10
		right:
				if (++w->ww_cur.c >= w->ww_w.nc) {
					w->ww_cur.c = 0;
E 18
I 18
				w->ww_cur.c +=
					8 - (w->ww_cur.c - w->ww_w.l & 7);
				if (w->ww_cur.c >= w->ww_w.r) {
					w->ww_cur.c = w->ww_w.l;
E 18
					goto lf;
				}
E 10
				break;
E 25
E 7
			case '\b':
I 7
D 12
				if (--w->ww_cur.c < 0)
					w->ww_cur.c = 0;
E 12
I 12
D 18
				if (--w->ww_cur.c < 0) {
					w->ww_cur.c = w->ww_w.nc - 1;
E 18
I 18
				if (--w->ww_cur.c < w->ww_w.l) {
					w->ww_cur.c = w->ww_w.r - 1;
E 18
					goto up;
				}
E 12
				break;
E 7
			case '\r':
I 7
D 18
				w->ww_cur.c = 0;
E 18
I 18
				w->ww_cur.c = w->ww_w.l;
E 18
				break;
E 7
D 26
			case CTRL(g):
D 7
				Wputc(c, w->ww_win);
E 7
I 7
D 25
				wwbell();
E 25
I 25
				ttputc(CTRL(g));
E 26
I 26
D 34
			case ctrl(g):
				ttputc(ctrl(g));
E 34
I 34
			case ctrl('g'):
				ttputc(ctrl('g'));
E 34
E 26
E 25
E 7
				break;
D 26
			case CTRL([):
E 26
I 26
D 34
			case ctrl([):
E 34
I 34
			case ctrl('['):
E 34
E 26
				w->ww_wstate = 1;
				break;
			}
			break;
		case 1:
			w->ww_wstate = 0;
D 17
			switch (c) {
E 17
I 17
			switch (*p++) {
E 17
			case '@':
				w->ww_insert = 1;
				break;
			case 'A':
D 7
				Wcurup(w->ww_win, 1);
E 7
I 7
D 12
				if (--w->ww_cur.r < 0)
E 12
I 12
		up:
I 32
D 33
				if (!w->ww_noupdate && wwtouched[w->ww_cur.r])
					wwupdate1(w->ww_cur.r, w->ww_cur.r + 1);
E 33
I 33
				UPDATE();
E 33
E 32
D 18
				if (--w->ww_cur.r < 0) {
E 12
					w->ww_cur.r = 0;
I 12
					if (w->ww_scroll > 0)
E 18
I 18
				if (--w->ww_cur.r < w->ww_w.t) {
					w->ww_cur.r = w->ww_w.t;
D 20
					if (w->ww_w.t > w->ww_b.t)
E 18
						wwscroll(w, -1);
					else
E 20
I 20
					if (w->ww_w.t > w->ww_b.t) {
						(void) wwscroll1(w, w->ww_i.t,
							w->ww_i.b, -1, 0);
						w->ww_buf--;
						w->ww_b.t++;
						w->ww_b.b++;
					} else
E 20
D 18
						wwinsline(w, 0);
E 18
I 18
						wwinsline(w, w->ww_b.t);
E 18
				}
E 12
E 7
				break;
			case 'B':
D 7
				Wcurdown(w->ww_win, 1);
				break;
E 7
I 7
				goto lf;
E 7
			case 'C':
D 7
				Wcurright(w->ww_win, 1);
				break;
E 7
I 7
D 18
				goto right;
E 18
I 18
		right:
D 25
				if (++w->ww_cur.c >= w->ww_w.r) {
					w->ww_cur.c = w->ww_w.l;
					goto lf;
				}
				break;
E 25
I 25
				w->ww_cur.c++;
				goto chklf;
E 25
E 18
E 7
			case 'E':
I 19
				w->ww_buf -= w->ww_w.t - w->ww_b.t;
E 19
I 8
D 18
				w->ww_scroll = 0;
E 8
D 7
				WWcursor(w->ww_win, 0, 0);
				Wclear(w->ww_win, 2);
				/* always refresh */
				Wrefresh(1);
E 7
I 7
				w->ww_cur.c = w->ww_cur.r = 0;
D 8
				wwclreos(w);
E 8
I 8
				wwclreos(w, 0, 0);
E 18
I 18
				w->ww_b.t = w->ww_w.t;
				w->ww_b.b = w->ww_b.t + w->ww_b.nr;
				w->ww_cur.r = w->ww_w.t;
				w->ww_cur.c = w->ww_w.l;
				wwclreos(w, w->ww_w.t, w->ww_w.l);
E 18
E 8
E 7
				break;
			case 'H':
I 32
D 33
				if (!w->ww_noupdate && wwtouched[w->ww_cur.r])
					wwupdate1(w->ww_cur.r, w->ww_cur.r + 1);
E 33
I 33
				UPDATE();
E 33
E 32
D 7
				WWcursor(w->ww_win, 0, 0);
E 7
I 7
D 18
				w->ww_cur.c = w->ww_cur.r = 0;
E 18
I 18
				w->ww_cur.r = w->ww_w.t;
				w->ww_cur.c = w->ww_w.l;
E 18
E 7
				break;
			case 'J':
D 7
				Wclear(w->ww_win, 0);
E 7
I 7
D 8
				wwclreos(w);
E 8
I 8
D 18
				wwclreos(w, w->ww_scroll + w->ww_cur.r,
					w->ww_cur.c);
E 18
I 18
				wwclreos(w, w->ww_cur.r, w->ww_cur.c);
E 18
E 8
E 7
				break;
			case 'K':
D 7
				Wclearline(w->ww_win, 0);
E 7
I 7
D 18
				wwclreol(w, w->ww_scroll + w->ww_cur.r,
D 8
					w->ww_cur.c, 0);
E 8
I 8
					w->ww_cur.c);
E 18
I 18
				wwclreol(w, w->ww_cur.r, w->ww_cur.c);
E 18
E 8
E 7
				break;
			case 'L':
I 32
D 33
				if (!w->ww_noupdate && wwtouched[w->ww_cur.r])
					wwupdate1(w->ww_cur.r, w->ww_cur.r + 1);
E 33
I 33
				UPDATE();
E 33
E 32
D 7
				Winslines(w->ww_win, 1);
				if (w->ww_refresh)
					Wrefresh(1);
E 7
I 7
D 8
				wwinsline(w);
E 8
I 8
D 18
				wwinsline(w, w->ww_scroll + w->ww_cur.r);
E 18
I 18
				wwinsline(w, w->ww_cur.r);
E 18
E 8
E 7
				break;
			case 'M':
D 7
				Wdellines(w->ww_win, 1);
				if (w->ww_refresh)
					Wrefresh(1);
E 7
I 7
D 18
				wwdelline(w, w->ww_scroll + w->ww_cur.r);
E 18
I 18
				wwdelline(w, w->ww_cur.r);
E 18
E 7
				break;
			case 'N':
D 7
				Wdelchars(w->ww_win, 1);
E 7
I 7
D 8
				wwdelchar(w);
E 8
I 8
D 18
				wwdelchar(w, w->ww_scroll + w->ww_cur.r,
					w->ww_cur.c);
E 18
I 18
				wwdelchar(w, w->ww_cur.r, w->ww_cur.c);
E 18
E 8
E 7
				break;
			case 'O':
				w->ww_insert = 0;
				break;
			case 'Y':
I 32
D 33
				if (!w->ww_noupdate && wwtouched[w->ww_cur.r])
					wwupdate1(w->ww_cur.r, w->ww_cur.r + 1);
E 33
I 33
				UPDATE();
E 33
E 32
				w->ww_wstate = 2;
I 11
				break;
D 31
			case 'p':
				w->ww_modes |= WWM_REV;
E 31
I 31
			case 's':
				w->ww_wstate = 4;
E 31
				break;
D 31
			case 'q':
				w->ww_modes &= ~WWM_REV;
				break;
E 31
			case 'r':
D 31
				w->ww_modes |= WWM_UL;
E 31
I 31
				w->ww_wstate = 5;
E 31
				break;
D 31
			case 's':
				w->ww_modes &= ~WWM_UL;
E 11
				break;
I 23
			case 'F':
				w->ww_modes |= WWM_GRP;
				break;
			case 'G':
				w->ww_modes &= ~WWM_GRP;
				break;
E 31
E 23
			}
			break;
		case 2:
D 2
			w->ww_newrow = (c - ' ') % w->ww_nrow;
E 2
I 2
D 4
			WWcursor(w->ww_win, (c - ' ') % w->ww_inrow,
E 4
I 4
D 7
			WWcursor(w->ww_win, (c - ' ') % w->ww_i.nrow,
E 4
				w->ww_win->w_cursor.col);
E 7
I 7
D 17
			w->ww_cur.r = (c - ' ') % w->ww_w.nr;
E 17
I 17
D 18
			w->ww_cur.r = (*p++ - ' ') % w->ww_w.nr;
E 17
E 7
E 2
			w->ww_wstate++;
E 18
I 18
D 22
			w->ww_cur.r = w->ww_w.t + (*p++ - ' ') % w->ww_w.nr;
E 22
I 22
			w->ww_cur.r = w->ww_w.t +
				(unsigned)(*p++ - ' ') % w->ww_w.nr;
E 22
			w->ww_wstate = 3;
E 18
			break;
		case 3:
D 2
			WWcursor(w->ww_win, w->ww_newrow,
				(c - ' ') % w->ww_ncol);
E 2
I 2
D 7
			WWcursor(w->ww_win, w->ww_win->w_cursor.row,
D 4
				(c - ' ') % w->ww_incol);
E 4
I 4
				(c - ' ') % w->ww_i.ncol);
E 7
I 7
D 17
			w->ww_cur.c = (c - ' ') % w->ww_w.nc;
E 17
I 17
D 18
			w->ww_cur.c = (*p++ - ' ') % w->ww_w.nc;
E 18
I 18
D 22
			w->ww_cur.c = w->ww_w.l + (*p++ - ' ') % w->ww_w.nc;
E 22
I 22
			w->ww_cur.c = w->ww_w.l +
				(unsigned)(*p++ - ' ') % w->ww_w.nc;
I 31
			w->ww_wstate = 0;
			break;
		case 4:
			w->ww_modes |= *p++ & wwavailmodes;
			w->ww_wstate = 0;
			break;
		case 5:
			w->ww_modes &= ~*p++;
E 31
E 22
E 18
E 17
E 7
E 4
E 2
			w->ww_wstate = 0;
			break;
		}
	}
I 13
	if (hascursor)
		wwcursor(w, 1);
E 13
I 7
D 16
	return oldn - n;
E 16
I 16
D 24
	return 0;
E 24
I 24
D 25
	return saven;
E 25
I 25
	wwnwwr++;
	wwnwwra += n;
	n = p - savep;
	wwnwwrc += n;
	return n;
E 25
E 24
E 16
E 7
D 2
}

wwflush()
{
	register Win *w = curwin->ww_win;

	WRCurRow = WCurRow(w);
	WRCurCol = WCurCol(w);
	Wrefresh(1);
E 2
}
E 1
