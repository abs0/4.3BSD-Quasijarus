h40053
s 00010/00005/00069
d D 3.9 88/06/29 21:38:29 bostic 9 8
c install approved copyright notice
e
s 00013/00007/00061
d D 3.8 88/02/21 13:38:39 bostic 8 7
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00062
d D 3.7 85/04/24 16:18:15 edward 7 6
c copyright messages
e
s 00000/00003/00062
d D 3.6 85/04/03 22:20:43 edward 6 5
c lint, and others
e
s 00001/00001/00064
d D 3.5 84/05/23 01:59:29 edward 5 4
c new sccs id
e
s 00003/00005/00062
d D 3.4 83/11/23 16:37:22 edward 4 3
c New cover scheme
e
s 00010/00000/00057
d D 3.3 83/09/16 10:33:02 edward 3 2
c recalculate nvis after move
e
s 00034/00004/00023
d D 3.2 83/09/15 10:10:51 edward 2 1
c Now uses screen address for all buffers.
e
s 00027/00000/00000
d D 3.1 83/09/14 14:21:03 edward 1 0
c date and time created 83/09/14 14:21:03 by edward
e
u
U
t
T
I 1
D 8
#ifndef lint
D 5
static	char *sccsid = "%W% %E%";
E 5
I 5
static char sccsid[] = "%W% %G%";
E 5
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
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
E 8
 */
I 8

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 8

E 7
#include "ww.h"

/*
 * Move a window.  Should be unattached.
 */
wwmove(w, row, col)
register struct ww *w;
{
I 2
	register dr, dc;
	register i;

E 2
D 6
	if (w->ww_forw != 0 || w->ww_back != 0)
		return;				/* sanity */

E 6
D 2
	w->ww_w.t = row;
	w->ww_w.b = w->ww_w.t + w->ww_w.nr;
	w->ww_w.l = col;
	w->ww_w.r = w->ww_w.l + w->ww_w.nc;
E 2
I 2
	dr = row - w->ww_w.t;
	dc = col - w->ww_w.l;
E 2

I 2
	w->ww_w.t += dr;
	w->ww_w.b += dr;
	w->ww_w.l += dc;
	w->ww_w.r += dc;

	w->ww_b.t += dr;
	w->ww_b.b += dr;
	w->ww_b.l += dc;
	w->ww_b.r += dc;

E 2
	w->ww_i.t = MAX(w->ww_w.t, 0);
	w->ww_i.b = MIN(w->ww_w.b, wwnrow);
	w->ww_i.nr = w->ww_i.b - w->ww_i.t;
	w->ww_i.l = MAX(w->ww_w.l, 0);
	w->ww_i.r = MIN(w->ww_w.r, wwncol);
	w->ww_i.nc = w->ww_i.r - w->ww_i.l;
I 2

	w->ww_cur.r += dr;
	w->ww_cur.c += dc;

	w->ww_win -= dr;
	for (i = w->ww_w.t; i < w->ww_w.b; i++)
		w->ww_win[i] -= dc;
D 4
	w->ww_cov -= dr;
	for (i = w->ww_w.t; i < w->ww_w.b; i++)
		w->ww_cov[i] -= dc;
E 4
	if (w->ww_fmap != 0) {
		w->ww_fmap -= dr;
		for (i = w->ww_w.t; i < w->ww_w.b; i++)
			w->ww_fmap[i] -= dc;
	}
	w->ww_nvis -= dr;
I 3
	for (i = w->ww_i.t; i < w->ww_i.b; i++) {
		register j = w->ww_i.l;
		register char *win = &w->ww_win[i][j];
I 4
		register char *smap = &wwsmap[i][j];
E 4
		int nvis = 0;

D 4
		for (; j < w->ww_i.r; j++)
			if (*win++ == 0)
E 4
I 4
		for (; j < w->ww_i.r; j++, win++, smap++)
			if (*win == 0 && *smap == w->ww_index)
E 4
				nvis++;
		w->ww_nvis[i] = nvis;
	}
E 3
	w->ww_buf -= dr;
	for (i = w->ww_b.t; i < w->ww_b.b; i++)
		w->ww_buf[i] -= dc;
E 2
}
E 1
