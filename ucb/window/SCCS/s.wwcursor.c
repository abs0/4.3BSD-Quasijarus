h01781
s 00010/00005/00063
d D 3.10 88/06/29 21:37:39 bostic 10 9
c install approved copyright notice
e
s 00013/00007/00055
d D 3.9 88/02/21 13:38:07 bostic 9 8
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00056
d D 3.8 85/04/24 16:18:11 edward 8 7
c copyright messages
e
s 00001/00001/00055
d D 3.7 84/05/23 01:59:27 edward 7 6
c new sccs id
e
s 00020/00000/00036
d D 3.6 83/12/06 12:57:25 edward 6 5
c wwsetcursormodes() added
e
s 00001/00001/00035
d D 3.5 83/12/02 22:46:20 edward 5 4
c WWU_MAJOR, clreol in wwupdate(), and more optimizations.
e
s 00004/00004/00032
d D 3.4 83/11/23 16:37:15 edward 4 3
c New cover scheme
e
s 00005/00008/00031
d D 3.3 83/09/15 10:10:46 edward 3 2
c Now uses screen address for all buffers.
e
s 00009/00006/00030
d D 3.2 83/09/14 14:17:22 edward 2 1
c Off screen windows!!!!!!
e
s 00036/00000/00000
d D 3.1 83/08/19 15:05:34 edward 1 0
c date and time created 83/08/19 15:05:34 by edward
e
u
U
t
T
I 1
D 9
#ifndef lint
D 7
static	char *sccsid = "%W% %E%";
E 7
I 7
static char sccsid[] = "%W% %G%";
E 7
#endif

E 9
I 8
/*
D 9
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 9
I 9
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
E 9
 */
I 9

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 9

E 8
#include "ww.h"

wwcursor(w, on)
register struct ww *w;
{
	register char *win;
D 3
	register r, c;
E 3

	if (on) {
		if (w->ww_hascursor)
			return;
		w->ww_hascursor = 1;
	} else {
		if (!w->ww_hascursor)
			return;
		w->ww_hascursor = 0;
	}
	if (wwcursormodes != 0) {
		win = &w->ww_win[w->ww_cur.r][w->ww_cur.c];
D 4
		if (*win == 0)
			w->ww_nvis[w->ww_cur.r]--;
		else if (*win == wwcursormodes)
			w->ww_nvis[w->ww_cur.r]++;
E 4
		*win ^= wwcursormodes;
D 2
	}
	r = wwcurrow(w);
	c = wwcurcol(w);
	if (wwsmap[r][c] == w->ww_index) {
		wwns[r][c].c_m ^= wwcursormodes;
		wwtouched[r] = 1;
E 2
I 2
D 3
		r = wwcurrow(w);
		c = wwcurcol(w);
		if (r < w->ww_i.t || r >= w->ww_i.b
		    || c < w->ww_i.l || c >= w->ww_i.r)
E 3
I 3
		if (w->ww_cur.r < w->ww_i.t || w->ww_cur.r >= w->ww_i.b
		    || w->ww_cur.c < w->ww_i.l || w->ww_cur.c >= w->ww_i.r)
E 3
			return;
D 3
		if (wwsmap[r][c] == w->ww_index) {
			wwns[r][c].c_m ^= wwcursormodes;
			wwtouched[r] = 1;
E 3
I 3
		if (wwsmap[w->ww_cur.r][w->ww_cur.c] == w->ww_index) {
I 4
			if (*win == 0)
				w->ww_nvis[w->ww_cur.r]++;
			else if (*win == wwcursormodes)
				w->ww_nvis[w->ww_cur.r]--;
E 4
			wwns[w->ww_cur.r][w->ww_cur.c].c_m ^= wwcursormodes;
D 5
			wwtouched[w->ww_cur.r] = 1;
E 5
I 5
			wwtouched[w->ww_cur.r] |= WWU_TOUCHED;
E 5
E 3
		}
E 2
	}
}
I 6

wwsetcursormodes(new)
register new;
{
	register i;
	register struct ww *w;
	register old = wwcursormodes;

	new &= wwavailmodes;
	if (new == wwcursormodes)
		return;
	for (i = 0; i < NWW; i++)
		if (wwindex[i] != 0 && (w = wwindex[i])->ww_hascursor) {
			wwcursor(w, 0);
			wwcursormodes = new;
			wwcursor(w, 1);
			wwcursormodes = old;
		}
	wwcursormodes = new;
}
E 6
E 1
