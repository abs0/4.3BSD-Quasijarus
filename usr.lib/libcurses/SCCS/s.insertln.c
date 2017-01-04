h20240
s 00010/00005/00048
d D 5.3 88/06/30 17:21:44 bostic 8 7
c install approved copyright notice
e
s 00010/00004/00043
d D 5.2 88/06/08 13:57:20 bostic 7 6
c written by Ken Arnold; add Berkeley specific header
e
s 00010/00001/00037
d D 5.1 85/06/07 11:35:08 dist 6 5
c Add copyright
e
s 00019/00017/00019
d D 1.5 85/05/01 17:19:25 bloom 5 4
c newversion form arnold
e
s 00009/00000/00027
d D 1.4 81/04/17 00:44:35 arnold 4 3
c make it return ERR for illegal scroll type things
e
s 00002/00001/00025
d D 1.3 81/04/16 23:28:28 arnold 3 2
c fix stupid bugs so they WORK!
e
s 00000/00001/00026
d D 1.2 81/03/05 19:16:49 arnold 2 1
c eliminate unnecessary return
e
s 00027/00000/00000
d D 1.1 81/01/26 17:02:57 arnold 1 0
c date and time created 81/01/26 17:02:57 by arnold
e
u
U
t
T
I 6
/*
D 7
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * Copyright (c) 1981 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
E 7
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 7
#endif not lint
E 7
I 7
#endif /* not lint */
E 7

E 6
I 1
# include	"curses.ext"

/*
 *	This routine performs an insert-line on the window, leaving
 * (_cury,_curx) unchanged.
 *
D 5
 * %G% (Berkeley) %W%
E 5
I 5
D 6
 * %W% (Berkeley) %G%
E 6
E 5
 */
winsertln(win)
reg WINDOW	*win; {

	reg char	*temp;
	reg int		y;
	reg char	*end;
I 5
	reg int		x;
E 5

D 3
	temp = win->_y[win->_cury];
E 3
I 3
D 5
	temp = win->_y[win->_maxy-1];
E 3
	win->_firstch[win->_cury] = 0;
	win->_lastch[win->_cury] = win->_maxx - 1;
E 5
I 5
#ifdef	DEBUG
	fprintf(outf, "INSERTLN(%0.2o)\n", win);
#endif
	if (win->_orig == NULL)
		temp = win->_y[win->_maxy - 1];
E 5
	for (y = win->_maxy - 1; y > win->_cury; --y) {
D 5
		win->_y[y] = win->_y[y-1];
		win->_firstch[y] = 0;
		win->_lastch[y] = win->_maxx - 1;
E 5
I 5
		if (win->_orig == NULL)
			win->_y[y] = win->_y[y - 1];
		else
			bcopy(win->_y[y - 1], win->_y[y], win->_maxx);
		touchline(win, y, 0, win->_maxx - 1);
E 5
	}
I 5
	if (win->_orig == NULL)
		win->_y[y] = temp;
	else
		temp = win->_y[y];
E 5
	for (end = &temp[win->_maxx]; temp < end; )
		*temp++ = ' ';
I 3
D 5
	win->_y[win->_cury] = temp - win->_maxx;
I 4
	if (win->_cury == LINES - 1 && win->_y[LINES-1][COLS-1] != ' ')
		if (win->_scroll) {
			wrefresh(win);
			scroll(win);
			win->_cury--;
		}
		else
			return ERR;
	return OK;
E 5
I 5
	touchline(win, y, 0, win->_maxx - 1);
	if (win->_orig == NULL)
		_id_subwins(win);
E 5
E 4
E 3
D 2
	return OK;
E 2
}
E 1
