h65168
s 00010/00005/00059
d D 3.10 88/06/29 21:38:18 bostic 10 9
c install approved copyright notice
e
s 00003/00001/00061
d D 3.9 88/03/08 10:10:47 edward 9 8
c fix for bug report from rad@tekgen.csc.tek.com
e
s 00013/00007/00049
d D 3.8 88/02/21 13:38:31 bostic 8 7
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00050
d D 3.7 85/04/24 16:16:10 edward 7 6
c copyright messages
e
s 00001/00001/00049
d D 3.6 84/05/23 01:58:35 edward 6 5
c new sccs id
e
s 00013/00012/00037
d D 3.5 83/09/15 10:09:39 edward 5 4
c Now uses screen address for all buffers.
e
s 00006/00006/00043
d D 3.4 83/09/14 14:16:02 edward 4 3
c Off screen windows!!!!!!
e
s 00014/00006/00035
d D 3.3 83/08/18 16:22:30 edward 3 2
c bug with improper redraw
e
s 00021/00100/00020
d D 3.2 83/08/11 17:24:08 edward 2 1
i
c last few day's work
e
s 00120/00000/00000
d D 3.1 83/08/09 18:36:03 edward 1 0
c date and time created 83/08/09 18:36:03 by edward
e
u
U
t
T
I 1
D 8
#ifndef lint
D 6
static	char *sccsid = "%W% %E%";
E 6
I 6
static char sccsid[] = "%W% %G%";
E 6
#endif

E 8
I 7
/*
D 8
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 8
I 8
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 10
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
I 10
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
E 10
E 8
 */
I 8

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 8

E 7
#include "ww.h"

D 5
wwinsline(w, line)
E 5
I 5
wwinsline(w, row)
E 5
register struct ww *w;
D 5
int line;
E 5
I 5
int row;
E 5
{
	register i;
D 2
	int j;
	int row = line - w->ww_scroll;
	int srow = MAX(row, 0) + w->ww_w.t;
	int startrow, endrow;
	int nvis;
	int nvismax;
	int deleted = 0;
E 2
I 2
	register union ww_char **cpp, **cqq;
D 3
	union ww_char *tmp;
E 3
I 3
	register union ww_char *cp;
E 3
D 4
	int srow, erow;
E 4
I 4
D 5
	int row11, row2;
E 5
I 5
	int row1, row2;
E 5
E 4
	char deleted;
I 3
	int visible;
E 3
E 2

	/*
D 2
	 * Fix the buffer.
	 * But leave clearing the first line for wwclreol().
E 2
I 2
	 * Scroll first.
E 2
	 */
D 2
	{
		register union ww_char *tmp;
		register union ww_char **cpp, **cqq;
		cpp = &w->ww_buf[w->ww_nline];
		cqq = cpp - 1;
		tmp = *cqq;
		for (i = w->ww_nline - line - 1; --i >= 0;)
			*--cpp = *--cqq;
		*cqq = tmp;
	}
E 2
I 2
D 3
	if ((srow = line - w->ww_scroll) < 0)
E 3
I 3
D 4
	if ((srow = line - w->ww_scroll) < 0) {
E 3
		srow = 0;
E 4
I 4
D 5
	if ((row11 = line - w->ww_scroll) < w->ww_i.t - w->ww_w.t) {
		row11 = 0;
E 5
I 5
	if ((row1 = row) < w->ww_i.t) {
		row1 = w->ww_i.t;
E 5
E 4
I 3
		visible = 0;
	} else
		visible = 1;
E 3
D 4
	if ((erow = w->ww_nline - w->ww_scroll - 1) >= w->ww_w.nr)
		erow = w->ww_w.nr - 1;
D 3
	deleted = wwscroll1(w, srow, erow, -1, 1);
E 3
I 3
	deleted = wwscroll1(w, srow, erow, -1, visible);
E 4
I 4
D 5
	if ((row2 = w->ww_nline - w->ww_scroll) > w->ww_i.b - w->ww_w.t)
		row2 = w->ww_i.b - w->ww_w.t;
	deleted = wwscroll1(w, row11, row2, -1, visible);
E 5
I 5
	if ((row2 = w->ww_b.b) > w->ww_i.b) {
		row2 = w->ww_i.b;
	}
	deleted = wwscroll1(w, row1, row2, -1, visible);
E 5
E 4
E 3

E 2
	/*
D 2
	 * See how many lines on the screen are affected.
E 2
I 2
	 * Fix the buffer.
	 * But leave clearing the last line for wwclreol().
E 2
	 */
D 2
	for (i = MAX(0, row); i < w->ww_w.nr && w->ww_nvis[i] == 0; i++)
		;
	if ((startrow = i + w->ww_w.t) == w->ww_w.b) {
		endrow = startrow - 1;
		goto out;
	}
	for (i = w->ww_w.nr - 1; i > 0 && w->ww_nvis[i] == 0; i--)
		;
	if ((endrow = i + w->ww_w.t) == startrow)
		goto out;		/* just one line is easy */
	/*
	 * See how much of this window is visible.
	 */
	nvismax = wwncol * (endrow - startrow + 1);
	nvis = 0;
	for (i = startrow; i <= endrow; i++)
		nvis += w->ww_nvis[i];
	/*
	 * If it's a good idea to use delete and insert line
	 * and the terminal can, then do it.
	 */
	if (endrow > startrow && nvis > nvismax / 2
	    && tt.tt_delline && tt.tt_insline) {
		register union ww_char *tmp;
		register union ww_char **cpp, **cqq;
E 2
I 2
D 5
	cpp = &w->ww_buf[w->ww_nline];
E 5
I 5
	cpp = &w->ww_buf[w->ww_b.b];
E 5
	cqq = cpp - 1;
D 3
	tmp = *cqq;
E 3
I 3
	cp = *cqq;
E 3
D 5
	for (i = w->ww_nline - line - 1; --i >= 0;)
E 5
I 5
	for (i = w->ww_b.b - row; --i > 0;)
E 5
		*--cpp = *--cqq;
D 3
	*cqq = tmp;
E 3
I 3
	*cqq = cp;
E 3
E 2

D 2
		(*tt.tt_move)(startrow, 0);
		(*tt.tt_delline)();
		if (endrow != wwnrow - 1) {
			(*tt.tt_move)(endrow, 0);
			(*tt.tt_insline)();
		}
		/*
		 * Fix up the old screen.
		 */
		cpp = &wwos[startrow];
		cqq = cpp + 1;
		tmp = *cpp;
		for (i = endrow - startrow; --i >= 0;)
			*cpp++ = *cqq++;
		*cpp = tmp;
		for (i = wwncol; --i >= 0;)
			tmp++->c_w = ' ';
		deleted++;
	}
E 2
	/*
D 2
	 * Fix the new screen.
E 2
I 2
	 * Now clear the last line.
E 2
	 */
D 2
	if (endrow > startrow && nvis == nvismax) {
		register union ww_char *tmp;
		register union ww_char **cpp, **cqq;

		cpp = &wwns[startrow];
		cqq = cpp + 1;
		tmp = *cpp;
		for (i = endrow - startrow; --i >= 0;)
			*cpp++ = *cqq;
		*cpp = tmp;
		i = startrow - 1;
	} else {
out:
		/* wwclreol() will do the last line */
		if ((i = endrow) == w->ww_nline - w->ww_scroll + w->ww_w.t - 1)
			i--;
	}
	for (; i >= srow; i--) {
		register char *smap;
		register union ww_char *buf;
		register char *win;
		register union ww_char *ns;

		ns = &wwns[i][w->ww_w.l];
		smap = &wwsmap[i][w->ww_w.l];
		buf = w->ww_buf[w->ww_scroll + i - w->ww_w.t];
		win = w->ww_win[i - w->ww_w.t];
		for (j = w->ww_w.nc; --j >= 0;)
			if (*smap++ != w->ww_index)
				win++, ns++, buf++;
			else
				ns++->c_w = buf++->c_w
					^ *win++ << WWC_MSHIFT;
	}
	wwclreol(w, w->ww_nline - 1, 0, deleted);
E 2
I 2
D 3
	wwclreol1(w, line, 0, deleted);
E 3
I 3
	if (visible)
D 5
		wwclreol1(w, line, 0, deleted);
E 5
I 5
		wwclreol1(w, row, w->ww_b.l, deleted);
E 5
D 9
	else
E 9
I 9
	else {
		cp += w->ww_b.l;
E 9
D 5
		for (i = w->ww_w.nc; --i >= 0;)
E 5
I 5
		for (i = w->ww_b.nc; --i >= 0;)
E 5
			cp++->c_w = ' ';
I 9
	}
E 9
E 3
E 2
}
E 1
