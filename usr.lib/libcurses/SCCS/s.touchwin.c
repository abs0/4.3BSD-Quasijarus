h14897
s 00010/00005/00057
d D 5.3 88/06/30 17:22:08 bostic 6 5
c install approved copyright notice
e
s 00010/00004/00052
d D 5.2 88/06/08 13:57:50 bostic 5 4
c written by Ken Arnold; add Berkeley specific header
e
s 00010/00001/00046
d D 5.1 85/06/07 11:43:19 dist 4 3
c Add copyright
e
s 00032/00019/00015
d D 1.3 85/05/01 17:36:51 bloom 3 2
c new version from arnold
e
s 00015/00000/00019
d D 1.2 83/05/09 20:35:28 arnold 2 1
c integrate subwindows fully into all parts of curses
e
s 00019/00000/00000
d D 1.1 81/01/26 17:03:16 arnold 1 0
c date and time created 81/01/26 17:03:16 by arnold
e
u
U
t
T
I 4
/*
D 5
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
 * Copyright (c) 1981 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 6
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 6
I 6
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
E 6
E 5
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif not lint
E 5
I 5
#endif /* not lint */
E 5

E 4
I 1
# include	"curses.ext"

/*
 * make it look like the whole window has been changed.
 *
D 3
 * %G% (Berkeley) %W%
E 3
I 3
D 4
 * %W% (Berkeley) %G%
E 4
E 3
 */
touchwin(win)
D 3
reg WINDOW	*win;
E 3
I 3
register WINDOW	*win;
E 3
{
I 2
D 3
	reg WINDOW	*wp;
E 3
I 3
	register int	y, maxy;
E 3

D 3
	do_touch(win);
	for (wp = win->_nextp; wp != win; wp = wp->_nextp)
		do_touch(wp);
E 3
I 3
# ifdef	DEBUG
	fprintf(outf, "TOUCHWIN(%0.2o)\n", win);
# endif
	maxy = win->_maxy;
	for (y = 0; y < maxy; y++)
		touchline(win, y, 0, win->_maxx - 1);
E 3
}

/*
D 3
 * do_touch:
 *	Touch the window
E 3
I 3
 * touch a given line
E 3
 */
D 3
static
do_touch(win)
reg WINDOW	*win; {

E 2
	reg int		y, maxy, maxx;

	maxy = win->_maxy;
	maxx = win->_maxx - 1;
	for (y = 0; y < maxy; y++) {
		win->_firstch[y] = 0;
		win->_lastch[y] = maxx;
E 3
I 3
touchline(win, y, sx, ex)
register WINDOW	*win;
register int	y, sx, ex;
{
# ifdef DEBUG
	fprintf(outf, "TOUCHLINE(%0.2o, %d, %d, %d)\n", win, y, sx, ex);
	fprintf(outf, "TOUCHLINE:first = %d, last = %d\n", win->_firstch[y], win->_lastch[y]);
# endif
	sx += win->_ch_off;
	ex += win->_ch_off;
	if (win->_firstch[y] == _NOCHANGE) {
		win->_firstch[y] = sx;
		win->_lastch[y] = ex;
E 3
	}
I 3
	else {
		if (win->_firstch[y] > sx)
			win->_firstch[y] = sx;
		if (win->_lastch[y] < ex)
			win->_lastch[y] = ex;
	}
# ifdef	DEBUG
	fprintf(outf, "TOUCHLINE:first = %d, last = %d\n", win->_firstch[y], win->_lastch[y]);
# endif
E 3
}
E 1
