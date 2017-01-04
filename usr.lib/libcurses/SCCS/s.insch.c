h39616
s 00010/00005/00042
d D 5.3 88/06/30 17:21:43 bostic 6 5
c install approved copyright notice
e
s 00010/00004/00037
d D 5.2 88/06/08 13:57:18 bostic 5 4
c written by Ken Arnold; add Berkeley specific header
e
s 00010/00001/00031
d D 5.1 85/06/07 11:34:43 dist 4 3
c Add copyright
e
s 00001/00004/00031
d D 1.3 85/05/01 17:18:12 bloom 3 2
c new version from arnold
e
s 00001/00003/00034
d D 1.2 81/04/17 00:45:32 arnold 2 1
c don't erase the last character when returning ERR
e
s 00037/00000/00000
d D 1.1 81/04/17 00:26:16 arnold 1 0
c date and time created 81/04/17 00:26:16 by arnold
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
 *	This routine performs an insert-char on the line, leaving
 * (_cury,_curx) unchanged.
 *
D 4
 * %W% (Berkeley) %G%
E 4
 */
winsch(win, c)
reg WINDOW	*win;
char		c; {

	reg char	*temp1, *temp2;
	reg char	*end;

	end = &win->_y[win->_cury][win->_curx];
	temp1 = &win->_y[win->_cury][win->_maxx - 1];
	temp2 = temp1 - 1;
	while (temp1 > end)
		*temp1-- = *temp2--;
	*temp1 = c;
D 3
	win->_lastch[win->_cury] = win->_maxx - 1;
	if (win->_firstch[win->_cury] == _NOCHANGE ||
	    win->_firstch[win->_cury] > win->_curx)
		win->_firstch[win->_cury] = win->_curx;
E 3
I 3
	touchline(win, win->_cury, win->_curx, win->_maxx - 1);
E 3
	if (win->_cury == LINES - 1 && win->_y[LINES-1][COLS-1] != ' ')
		if (win->_scroll) {
			wrefresh(win);
			scroll(win);
			win->_cury--;
		}
D 2
		else {
			win->_y[LINES-1][COLS-1] = ' ';
E 2
I 2
		else
E 2
			return ERR;
D 2
		}
E 2
	return OK;
}
E 1
