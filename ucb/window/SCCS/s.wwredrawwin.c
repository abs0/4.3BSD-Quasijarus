h11736
s 00010/00005/00046
d D 3.13 88/06/29 21:38:42 bostic 13 12
c install approved copyright notice
e
s 00013/00007/00038
d D 3.12 88/02/21 13:38:50 bostic 12 11
c written by Edward Wang; attach Berkeley specific copyright
e
s 00005/00003/00040
d D 3.11 87/10/01 22:47:35 edward 11 10
c don't set touched unless actually different
e
s 00006/00000/00037
d D 3.10 85/04/24 16:17:55 edward 10 9
c copyright messages
e
s 00001/00001/00036
d D 3.9 84/05/23 01:59:22 edward 9 8
c new sccs id
e
s 00008/00004/00029
d D 3.8 83/12/02 22:46:16 edward 8 7
c WWU_MAJOR, clreol in wwupdate(), and more optimizations.
e
s 00012/00013/00021
d D 3.7 83/12/02 14:16:20 edward 7 6
c Changed loop structures
e
s 00000/00006/00034
d D 3.6 83/09/15 13:27:52 edward 6 5
c inline expand some function calls
e
s 00008/00009/00032
d D 3.5 83/09/15 10:10:41 edward 5 4
c Now uses screen address for all buffers.
e
s 00011/00010/00030
d D 3.4 83/09/14 14:17:14 edward 4 3
c Off screen windows!!!!!!
e
s 00000/00002/00040
d D 3.3 83/08/18 15:29:53 edward 3 2
c scrolling has come
e
s 00008/00002/00034
d D 3.2 83/08/16 12:55:50 edward 2 1
c wwtouched added
e
s 00036/00000/00000
d D 3.1 83/08/12 15:14:50 edward 1 0
c date and time created 83/08/12 15:14:50 by edward
e
u
U
t
T
I 1
D 12
#ifndef lint
D 9
static	char *sccsid = "%W% %E%";
E 9
I 9
static char sccsid[] = "%W% %G%";
E 9
#endif

E 12
I 10
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

E 10
#include "ww.h"

I 2
D 3
/*			nobody calls it
E 3
E 2
D 6
wwredrawwin(w)
register struct ww *w;
{
D 4
	wwredrawwin1(w, 0, w->ww_w.nr - 1, w->ww_scroll);
E 4
I 4
D 5
	wwredrawwin1(w, w->ww_i.t - w->ww_w.t, w->ww_i.b - w->ww_w.t,
		w->ww_scroll);
E 5
I 5
	wwredrawwin1(w, w->ww_i.t, w->ww_i.b, 0);
E 5
E 4
}
I 2
D 3
*/
E 3
E 2

E 6
D 4
wwredrawwin1(w, srow, erow, offset)
E 4
I 4
D 5
wwredrawwin1(w, row1, row2, scroll)
E 5
I 5
wwredrawwin1(w, row1, row2, offset)
E 5
E 4
register struct ww *w;
D 4
int srow, erow, offset;
E 4
I 4
D 5
int row1, row2, scroll;
E 5
I 5
int row1, row2, offset;
E 5
E 4
{
D 7
	int i;
	register j;
E 7
I 7
	int row;
	register col;
E 7
	register char *smap;
	register union ww_char *buf;
	register char *win;
	register union ww_char *ns;
I 11
	int x;
E 11
I 2
D 8
	char *touched;
E 8
I 8
	int nchanged;
E 8
E 2

D 2
	for (i = srow; i <= erow; i++) {
E 2
I 2
D 4
	touched = &wwtouched[srow + w->ww_w.t];
	for (i = srow; i <= erow; i++, touched++) {
E 2
		ns = &wwns[i + w->ww_w.t][w->ww_w.l];
		smap = &wwsmap[i + w->ww_w.t][w->ww_w.l];
		buf = w->ww_buf[offset + i];
		win = w->ww_win[i];
		for (j = w->ww_w.nc; --j >= 0;)
E 4
I 4
D 5
	touched = &wwtouched[row1 + w->ww_w.t];
E 5
I 5
D 8
	touched = &wwtouched[row1];
E 5
D 7
	for (i = row1; i < row2; i++, touched++) {
D 5
		ns = &wwns[i + w->ww_w.t][w->ww_i.l];
		smap = &wwsmap[i + w->ww_w.t][w->ww_i.l];
		buf = &w->ww_buf[scroll + i][w->ww_i.l - w->ww_w.l];
		win = &w->ww_win[i][w->ww_i.l - w->ww_w.l];
E 5
I 5
		ns = &wwns[i][w->ww_i.l];
		smap = &wwsmap[i][w->ww_i.l];
		buf = &w->ww_buf[i + offset][w->ww_i.l];
		win = &w->ww_win[i][w->ww_i.l];
E 5
		for (j = w->ww_i.nc; --j >= 0;)
E 4
			if (*smap++ != w->ww_index)
				win++, ns++, buf++;
D 2
			else
E 2
I 2
			else {
E 7
I 7
	for (row = row1; row < row2; row++, touched++) {
E 8
I 8
	for (row = row1; row < row2; row++) {
E 8
		col = w->ww_i.l;
		ns = wwns[row];
		smap = &wwsmap[row][col];
		buf = w->ww_buf[row + offset];
		win = w->ww_win[row];
I 8
		nchanged = 0;
E 8
		for (; col < w->ww_i.r; col++)
D 11
			if (*smap++ == w->ww_index) {
E 11
I 11
			if (*smap++ == w->ww_index &&
			    ns[col].c_w !=
			    (x = buf[col].c_w ^ win[col] << WWC_MSHIFT)) {
E 11
E 7
D 8
				*touched = 1;
E 8
I 8
				nchanged++;
E 8
E 2
D 7
				ns++->c_w = buf++->c_w
					^ *win++ << WWC_MSHIFT;
E 7
I 7
D 11
				ns[col].c_w =
					buf[col].c_w ^ win[col] << WWC_MSHIFT;
E 11
I 11
				ns[col].c_w = x;
E 11
E 7
I 2
			}
I 8
		if (nchanged > 4)
			wwtouched[row] |= WWU_MAJOR|WWU_TOUCHED;
		else if (nchanged > 0)
			wwtouched[row] |= WWU_TOUCHED;
E 8
E 2
	}
}
E 1
