h17648
s 00010/00005/00112
d D 3.17 88/06/29 21:37:31 bostic 17 16
c install approved copyright notice
e
s 00013/00007/00104
d D 3.16 88/02/21 13:38:05 bostic 16 15
c written by Edward Wang; attach Berkeley specific copyright
e
s 00012/00016/00099
d D 3.15 87/05/18 12:11:18 edward 15 14
c use \n at bottom to scroll entire screen,
c use clear to eos to clear entire screen
e
s 00006/00000/00109
d D 3.14 85/04/24 16:16:19 edward 14 13
c copyright messages
e
s 00001/00001/00108
d D 3.13 84/05/23 01:58:40 edward 13 12
c new sccs id
e
s 00036/00013/00073
d D 3.12 84/01/06 15:48:38 edward 12 11
c more correct clear line algorithm
e
s 00011/00013/00075
d D 3.11 83/12/02 22:45:39 edward 11 10
c WWU_MAJOR, clreol in wwupdate(), and more optimizations.
e
s 00007/00008/00081
d D 3.10 83/12/02 14:15:18 edward 10 9
c Changed loop structures
e
s 00017/00027/00072
d D 3.9 83/09/15 10:09:49 edward 9 8
c Now uses screen address for all buffers.
e
s 00052/00026/00047
d D 3.8 83/09/14 14:16:16 edward 8 7
c Off screen windows!!!!!!
e
s 00001/00001/00072
d D 3.7 83/08/18 15:06:33 edward 7 6
c small bug with ww_buf[line] (instead of row)
e
s 00001/00002/00072
d D 3.6 83/08/17 17:22:53 edward 6 5
c fixed bug with covered windows
e
s 00003/00000/00071
d D 3.5 83/08/16 12:55:13 edward 5 4
c wwtouched added
e
s 00001/00000/00070
d D 3.4 83/08/15 18:15:02 edward 4 3
c tt cleanup
e
s 00001/00001/00069
d D 3.3 83/08/15 17:06:50 edward 3 2
c didn't clear wwos correctly.
e
s 00009/00002/00061
d D 3.2 83/08/11 17:24:20 edward 2 1
i
c last few day's work
e
s 00063/00000/00000
d D 3.1 83/08/09 18:37:47 edward 1 0
c date and time created 83/08/09 18:37:47 by edward
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
I 4
#include "tt.h"
E 4

I 2
D 9
wwclreol(w, line, col)
struct ww *w;
{
	wwclreol1(w, line, col, 0);
}

E 9
E 2
/*
 * Clear w to the end of line.
 * If cleared is true, then the screen line has already been cleared
 * previously.
 */
D 2
wwclreol(w, line, col, cleared)
E 2
I 2
D 9
wwclreol1(w, line, col, cleared)
E 9
I 9
wwclreol1(w, row, col, cleared)
E 9
E 2
register struct ww *w;
D 2
int line;
E 2
I 2
D 9
int line, col;
E 9
I 9
int row, col;
E 9
char cleared;
E 2
{
	register i;
D 9
	int row = line - w->ww_scroll;
	int srow = w->ww_w.t + row;
	int scol = w->ww_w.l + col;
E 9
D 8
	register union ww_char *s, *buf;
	register char *smap, *win;
I 5
	char *touched;
E 8
E 5
D 12
	int nblank, ncleared;
E 12
I 12
D 15
	int gain;
E 15
E 12

D 8
	if (row < 0 || row >= w->ww_w.nr) {
		/* can't even see it, so just clear the buffer */
E 8
I 8
	/*
	 * Clear the buffer right off
	 */
	{
		register union ww_char *buf;

E 8
D 9
		buf = &w->ww_buf[line][col]; 
		for (i = w->ww_w.nc - col; --i >= 0;)
E 9
I 9
		buf = &w->ww_buf[row][col]; 
		for (i = w->ww_b.r - col; --i >= 0;)
E 9
			buf++->c_w = ' ';
D 8
		return;
E 8
	}
D 8
	smap = &wwsmap[srow][scol];
	s = &wwns[srow][scol];
I 5
	touched = &wwtouched[srow];
E 5
	win = &w->ww_win[row][col];
D 7
	buf = &w->ww_buf[row][col];
E 7
I 7
	buf = &w->ww_buf[line][col];
E 7
	ncleared = nblank = 0;
	for (i = w->ww_w.nc - col; --i >= 0;) {
I 6
		buf++->c_w = ' ';
E 6
		if (*smap++ != w->ww_index) {
			if (s++->c_w == ' ')
E 8
I 8

	/*
	 * If can't see it, just return.
	 */
D 9
	if (srow < w->ww_i.t || srow >= w->ww_i.b
	    || w->ww_i.r <= 0 || w->ww_i.r <= scol)
E 9
I 9
	if (row < w->ww_i.t || row >= w->ww_i.b
	    || w->ww_i.r <= 0 || w->ww_i.r <= col)
E 9
		return;

D 9
	if (scol < w->ww_i.l)
		scol = w->ww_i.l;
	col = scol - w->ww_w.l;
E 9
I 9
	if (col < w->ww_i.l)
		col = w->ww_i.l;
E 9

	/*
	 * Now find out how much is actually cleared, and fix wwns.
	 */
D 12
	{
E 12
I 12
	if (cleared) {
E 12
		register union ww_char *s;
		register char *smap, *win;
D 11
		register char *touched;
E 11

D 9
		smap = &wwsmap[srow][scol];
		s = &wwns[srow][scol];
		touched = &wwtouched[srow];
E 9
I 9
D 10
		smap = &wwsmap[row][col];
		s = &wwns[row][col];
E 10
I 10
		i = col;
		smap = &wwsmap[row][i];
I 12
		s = &wwns[row][i];
		win = &w->ww_win[row][i];
		for (i = w->ww_i.r - i; --i >= 0;) {
			if (*smap++ != w->ww_index)
				continue;
			s++->c_w = ' ' | *win++ << WWC_MSHIFT;
		}
	} else {
		register union ww_char *s;
		register char *smap, *win;
		int ntouched = 0;
I 15
		int gain = 0;
E 15

		i = col;
		smap = &wwsmap[row][i];
E 12
D 11
		s = &wwns[row][i];
E 11
I 11
		s = wwns[row];
E 11
		win = w->ww_win[row];
E 10
D 11
		touched = &wwtouched[row];
E 11
E 9
D 10
		win = &w->ww_win[row][col];
E 10
D 12
		ncleared = nblank = 0;

E 12
I 12
D 15
		gain = 0;
E 15
E 12
D 9
		for (i = w->ww_i.r - scol; --i >= 0;) {
E 9
I 9
D 10
		for (i = w->ww_i.r - col; --i >= 0;) {
E 10
I 10
		for (; i < w->ww_i.r; i++) {
E 10
E 9
			if (*smap++ != w->ww_index) {
D 11
				if (s++->c_w == ' ')
E 11
I 11
D 12
				if (s[i].c_w == ' ')
E 11
					nblank++;
E 12
I 12
				if (s[i].c_w != ' ')
					gain--;
E 12
D 10
				win++;
E 10
D 11
				continue;
			}
			ncleared++; 
			*touched = 1;
D 10
			if (*win == 0) {
E 10
I 10
			if (win[i] == 0) {
E 11
I 11
			} else if (win[i] == 0) {
E 11
E 10
E 8
D 12
				nblank++;
E 12
D 6
			buf++;
E 6
D 8
			win++;
			continue;
E 8
I 8
D 11
				s++->c_w = ' ';
E 11
I 11
				if (s[i].c_w != ' ') {
D 12
					ncleared++; 
E 12
I 12
					gain++;
					ntouched++;
E 12
					s[i].c_w = ' ';
				}
E 11
D 10
				win++;
E 10
D 12
			} else
D 10
				s++->c_w = ' ' | *win++ << WWC_MSHIFT;
E 10
I 10
D 11
				s++->c_w = ' ' | win[i] << WWC_MSHIFT;
E 11
I 11
				s[i].c_w = ' ' | win[i] << WWC_MSHIFT;
E 12
I 12
			} else {
				short c = ' ' | win[i] << WWC_MSHIFT;
				if (s[i].c_w == c)
					gain--;
				else {
					s[i].c_w = c;
					ntouched++;
				}
			}
E 12
E 11
E 10
E 8
		}
I 11
D 12
		if (ncleared > 0)
E 12
I 12
		s += i;
		for (i = wwncol - i; --i >= 0;)
			if (s++->c_w != ' ')
				gain--;
		if (ntouched > 0)
E 12
			wwtouched[row] |= WWU_TOUCHED;
E 11
D 8
		ncleared++; 
D 6
		buf++->c_w = ' ';
E 6
I 5
		*touched = 1;
E 5
		if (*win == 0) {
			nblank++;
			s++->c_w = ' ';
			win++;
		} else
			s++->c_w = ' ' | *win++ << WWC_MSHIFT;
E 8
D 15
	}
I 8

	/*
	 * Can/Should we use clear eol?
	 */
E 8
D 12
	if (!cleared && tt.tt_clreol != 0
D 9
	    && ncleared > wwncol - scol - nblank
	    && nblank > (wwncol - scol) / 2) {
E 9
I 9
D 11
	    && ncleared > wwncol - col - nblank
	    && nblank > (wwncol - col) / 2) {
E 11
I 11
	    && ncleared > wwncol - col - nblank + 4) {
E 12
I 12
	if (!cleared && tt.tt_clreol != 0 && gain > 4) {
E 12
E 11
E 9
I 8
		register union ww_char *s;

E 8
		/* clear to the end */
D 9
		(*tt.tt_move)(srow, scol);
E 9
I 9
		(*tt.tt_move)(row, col);
E 9
		(*tt.tt_clreol)();
D 9
		s = &wwos[srow][scol];
D 3
		for (i = w->ww_w.nc - col; --i >= 0;)
E 3
I 3
		for (i = wwncol - scol; --i >= 0;)
E 9
I 9
		s = &wwos[row][col];
		for (i = wwncol - col; --i >= 0;)
E 9
E 3
			s++->c_w = ' ';
E 15
I 15
		/*
		 * Can/should we use clear eol?
		 */
		if (tt.tt_clreol != 0 && gain > 4) {
			/* clear to the end */
			(*tt.tt_move)(row, col);
			(*tt.tt_clreol)();
			s = &wwos[row][col];
			for (i = wwncol - col; --i >= 0;)
				s++->c_w = ' ';
		}
E 15
	}
}
E 1
