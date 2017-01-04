h09110
s 00010/00005/00019
d D 3.6 88/06/29 21:38:37 bostic 13 12
c install approved copyright notice
e
s 00013/00007/00011
d D 3.5 88/02/21 13:38:46 bostic 12 11
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00012
d D 3.4 85/04/24 16:11:21 edward 11 10
c copyright messages
e
s 00001/00001/00011
d D 3.3 84/05/23 01:56:26 edward 10 9
c new sccs id
e
s 00001/00001/00011
d D 3.2 84/03/03 22:41:55 edward 9 8
c interrupt driven input
e
s 00000/00000/00012
d D 3.1 83/08/11 17:21:21 edward 8 6
i 7
c last few day's work
e
s 00000/00000/00012
d D 2.1.1.1 83/08/09 18:34:25 edward 7 6
c mile stone
e
s 00000/00000/00012
d D 2.1 83/07/30 13:27:10 edward 6 5
c prepare for major change
e
s 00000/00000/00012
d D 1.5 83/07/22 17:08:11 edward 5 4
c scrolling.
c uses Wscreensize() to get screen size.
c More intelligent framing.
c etc.
e
s 00000/00000/00012
d D 1.4 83/07/19 20:07:41 edward 4 3
c today's work
e
s 00000/00000/00012
d D 1.3 83/07/18 21:03:11 edward 3 2
c multiple window
e
s 00003/00098/00009
d D 1.2 83/07/17 15:42:25 edward 2 1
c 
e
s 00107/00000/00000
d D 1.1 83/07/12 17:21:04 edward 1 0
c date and time created 83/07/12 17:21:04 by edward
e
u
U
f b 
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

wwputc(c, w)
D 2
	register char c;
	register struct ww *w;
E 2
I 2
char c;
struct ww *w;
E 2
{
D 2
	char clearline = 0;

	if (w == 0 || w->ww_win == 0)
		return -1;
	w->ww_touched = 1;
	c &= 0x7f;
	switch (w->ww_wstate) {
	case 0:
		if (c >= ' ' && c < 0x7f) {
			mvwaddch(w->ww_win, w->ww_y, w->ww_x, c);
			getyx(w->ww_win, w->ww_y, w->ww_x);
			break;
		}
		switch (c) {
		case CTRL(g):
			/* ??? */
			break;
		case CTRL([):
			w->ww_wstate++;
			break;
		case CTRL(z):
			w->ww_y = w->ww_x = 0;
			wclear(w->ww_win);
			break;
		case '\r':
			w->ww_x = 0;
			break;
		case '\n':
			w->ww_y++;
			clearline++;
			break;
		case '\t':
			w->ww_x += 8 - w->ww_x % 8;
			break;
		case '\b':
			if (--w->ww_x < 0)
				w->ww_x = 0;
			break;
		case CTRL(l):
			w->ww_x++;
			break;
		case CTRL(k):
			if (--w->ww_y < 0)
				w->ww_y = 0;
			break;
		}
		break;
	case 1:
		switch (c) {
		case '=':
			w->ww_wstate++;
			break;
		default:
			w->ww_wstate = 0;
		}
		break;
	case 2:
		w->ww_y = (c - ' ') % w->ww_nrow;
		w->ww_wstate++;
		break;
	case 3:
		w->ww_x = (c - ' ') % w->ww_ncol;
		w->ww_wstate = 0;
		break;
	}
	if (w->ww_x >= w->ww_ncol) {
		w->ww_x = 0;
		w->ww_y++;
		clearline++;
	}
	if (w->ww_y >= w->ww_nrow)
		w->ww_y = 0;
	if (clearline) {
		wmove(w->ww_win, w->ww_y, w->ww_x);
		wclrtoeol(w->ww_win);
	}
}

wwflush(w)
register struct ww *w;
{
	wmove(w->ww_win, w->ww_y, w->ww_x);
	wrefresh(w->ww_win);
	w->ww_touched = 0;
}

wwflushall()
{
	register struct ww *w;

	for (w = _wwhead; w; w = w->ww_next)
		if (w != _wwcurrent && w->ww_touched) {
			wrefresh(w->ww_win);
			w->ww_touched = 0;
		}
	wwflush(_wwcurrent);
E 2
I 2
D 9
	return wwwrite(w, &c, sizeof c);
E 9
I 9
	(void) wwwrite(w, &c, sizeof c);
E 9
E 2
}
E 1
