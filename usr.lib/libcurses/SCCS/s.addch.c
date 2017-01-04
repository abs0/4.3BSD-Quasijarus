h04165
s 00010/00005/00023
d D 5.4 88/06/30 17:21:11 bostic 11 10
c install approved copyright notice
e
s 00010/00004/00018
d D 5.3 88/06/08 13:56:42 bostic 10 9
c written by Ken Arnold; add Berkeley specific header
e
s 00003/00086/00019
d D 5.2 87/06/24 14:17:15 minshall 9 8
c Add 'addbytes.c', plus some cleanup by K. Bostic in Makefile.
e
s 00010/00001/00095
d D 5.1 85/06/07 11:24:18 dist 8 7
c Add copyright
e
s 00017/00022/00079
d D 1.7 85/05/23 15:42:59 bloom 7 6
c bug fix from arnold
e
s 00003/00003/00098
d D 1.6 85/05/01 16:32:03 bloom 6 5
c new version from arnold
e
s 00011/00008/00090
d D 1.5 83/05/19 12:10:20 arnold 5 4
c set_ch should check for out-of-bounds indices
e
s 00028/00008/00070
d D 1.4 83/05/09 20:35:33 arnold 4 3
c integrate subwindows fully into all parts of curses
e
s 00005/00007/00073
d D 1.3 81/03/05 18:54:16 arnold 3 2
c fix bug that caused a stop before the end of the screen
e
s 00001/00002/00079
d D 1.2 81/02/09 17:45:56 arnold 2 1
c fix tab problem
e
s 00081/00000/00000
d D 1.1 81/01/26 17:02:34 arnold 1 0
c date and time created 81/01/26 17:02:34 by arnold
e
u
U
t
T
I 8
/*
D 9
 * Copyright (c) 1980 Regents of the University of California.
E 9
I 9
D 10
 * Copyright (c) 1980-1987 Regents of the University of California.
E 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
I 10
 * Copyright (c) 1981 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 11
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 11
I 11
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
E 11
E 10
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 10
#endif not lint
E 10
I 10
#endif /* not lint */
E 10

E 8
I 1
# include	"curses.ext"

/*
 *	This routine adds the character to the current position
 *
D 5
 * %G% (Berkeley) %W%
E 5
I 5
D 8
 * %W% (Berkeley) %G%
E 8
E 5
 */
waddch(win, c)
D 9
reg WINDOW	*win;
E 9
I 9
WINDOW	*win;
E 9
char		c;
{
D 9
	reg int		x, y;
I 4
	reg WINDOW	*wp;
I 7
	reg int		newx;
E 7
E 4

	x = win->_curx;
	y = win->_cury;
# ifdef FULLDEBUG
	fprintf(outf, "ADDCH('%c') at (%d, %d)\n", c, y, x);
# endif
D 7
	if (y >= win->_maxy || x >= win->_maxx || y < 0 || x < 0)
		return ERR;
E 7
	switch (c) {
	  case '\t':
D 7
	  {
		reg int		newx;

E 7
D 2
		--x;
		for (newx = x + (8 - (x & 07)) + 1; x <= newx; x++)
E 2
I 2
		for (newx = x + (8 - (x & 07)); x < newx; x++)
E 2
			if (waddch(win, ' ') == ERR)
				return ERR;
		return OK;
D 7
	  }
E 7
I 4

E 4
	  default:
# ifdef FULLDEBUG
		fprintf(outf, "ADDCH: 1: y = %d, x = %d, firstch = %d, lastch = %d\n", y, x, win->_firstch[y], win->_lastch[y]);
# endif
		if (win->_flags & _STANDOUT)
			c |= _STANDOUT;
D 4
		if (win->_y[y][x] != c) {
			if (win->_firstch[y] == _NOCHANGE)
				win->_firstch[y] = win->_lastch[y] = x;
			else if (x < win->_firstch[y])
				win->_firstch[y] = x;
			else if (x > win->_lastch[y])
				win->_lastch[y] = x;
		}
E 4
I 4
D 5
		set_ch(win, y, x, c);
E 5
I 5
D 7
		set_ch(win, y, x, c, NULL);
E 5
		for (wp = win->_nextp; wp != win; wp = wp->_nextp)
D 5
			set_ch(wp, y, x, c);
E 5
I 5
			set_ch(wp, y, x, c, win);
E 7
I 7
		set_ch(win, y, x, c);
E 7
E 5
E 4
		win->_y[y][x++] = c;
		if (x >= win->_maxx) {
D 3
newline:
E 3
			x = 0;
D 3
nonewline:
			if (++y + 1 == win->_maxy)
E 3
I 3
newline:
			if (++y >= win->_maxy)
E 3
				if (win->_scroll) {
D 7
					wrefresh(win);
E 7
					scroll(win);
					--y;
				}
				else
					return ERR;
		}
# ifdef FULLDEBUG
		fprintf(outf, "ADDCH: 2: y = %d, x = %d, firstch = %d, lastch = %d\n", y, x, win->_firstch[y], win->_lastch[y]);
# endif
		break;
	  case '\n':
		wclrtoeol(win);
D 3
		if (NONL)
			goto nonewline;
		else
			goto newline;
E 3
I 3
		if (!NONL)
			x = 0;
		goto newline;
E 3
	  case '\r':
		x = 0;
		break;
	  case '\b':
		if (--x < 0)
			x = 0;
		break;
	}
	win->_curx = x;
	win->_cury = y;
	return OK;
I 4
}

/*
 * set_ch:
 *	Set the first and last change flags for this window.
 */
static
D 5
set_ch(win, y, x, ch)
E 5
I 5
D 7
set_ch(win, y, x, ch, orig)
E 7
I 7
set_ch(win, y, x, ch)
E 7
E 5
reg WINDOW	*win;
D 5
int		y, x; {
E 5
I 5
int		y, x;
D 7
WINDOW		*orig; {
E 5

D 5
	if (win->_orig != NULL) {
		y += win->_begy - win->_orig->_begy;
		x += win->_begx - win->_orig->_begx;
E 5
I 5
	if (orig != NULL) {
		y -= win->_begy - orig->_begy;
		x -= win->_begx - orig->_begx;
E 5
	}
I 5
	if (y < 0 || y >= win->_maxy || x < 0 || x >= win->_maxx)
		return;
E 7
I 7
{
# ifdef	FULLDEBUG
	fprintf(outf, "SET_CH(%0.2o, %d, %d)\n", win, y, x);
# endif
E 7
E 5
	if (win->_y[y][x] != ch) {
I 7
		x += win->_ch_off;
E 7
		if (win->_firstch[y] == _NOCHANGE)
D 6
			win->_firstch[y] = win->_lastch[y] = x;
E 6
I 6
D 7
			win->_firstch[y] = win->_lastch[y] = x + win->_ch_off;
E 7
I 7
			win->_firstch[y] = win->_lastch[y] = x;
E 7
E 6
		else if (x < win->_firstch[y])
D 6
			win->_firstch[y] = x;
E 6
I 6
D 7
			win->_firstch[y] = x + win->_ch_off;
E 7
I 7
			win->_firstch[y] = x;
E 7
E 6
		else if (x > win->_lastch[y])
D 6
			win->_lastch[y] = x;
E 6
I 6
D 7
			win->_lastch[y] = x + win->_ch_off;
E 7
I 7
			win->_lastch[y] = x;
# ifdef FULLDEBUG
		fprintf(outf, "SET_CH: change gives f/l: %d/%d [%d/%d]\n",
			win->_firstch[y], win->_lastch[y],
			win->_firstch[y] - win->_ch_off,
			win->_lastch[y] - win->_ch_off);
# endif
E 7
E 6
	}
E 9
I 9
    return waddbytes(win, &c, 1);
E 9
E 4
}
E 1
