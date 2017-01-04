h40004
s 00010/00005/00040
d D 5.4 88/06/30 17:21:16 bostic 6 5
c install approved copyright notice
e
s 00010/00004/00035
d D 5.3 88/06/08 13:56:47 bostic 5 4
c written by Ken Arnold; add Berkeley specific header
e
s 00001/00001/00038
d D 5.2 85/10/24 12:22:10 bloom 4 3
c should clear to end of first line
e
s 00010/00001/00029
d D 5.1 85/06/07 11:26:14 dist 3 2
c Add copyright
e
s 00003/00009/00027
d D 1.2 85/05/01 16:44:04 bloom 2 1
c new version from arnold
e
s 00036/00000/00000
d D 1.1 81/01/26 17:02:39 arnold 1 0
c date and time created 81/01/26 17:02:39 by arnold
e
u
U
t
T
I 3
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

E 3
I 1
# include	"curses.ext"

/*
 *	This routine erases everything on the window.
 *
D 2
 * %G% (Berkeley) %W%
E 2
I 2
D 3
 * %W% (Berkeley) %G%
E 3
E 2
 */
wclrtobot(win)
reg WINDOW	*win; {

	reg int		y;
	reg char	*sp, *end, *maxx;
	reg int		startx, minx;

	startx = win->_curx;
	for (y = win->_cury; y < win->_maxy; y++) {
		minx = _NOCHANGE;
		end = &win->_y[y][win->_maxx];
		for (sp = &win->_y[y][startx]; sp < end; sp++)
			if (*sp != ' ') {
				maxx = sp;
				if (minx == _NOCHANGE)
					minx = sp - win->_y[y];
				*sp = ' ';
			}
D 2
		if (minx != _NOCHANGE) {
			if (win->_firstch[y] > minx
			     || win->_firstch[y] == _NOCHANGE)
				win->_firstch[y] = minx;
			if (win->_lastch[y] < maxx - win->_y[y])
				win->_lastch[y] = maxx - win->_y[y];
		}
E 2
I 2
		if (minx != _NOCHANGE)
D 4
			touchline(win, y, minx, maxx - &win->_y[y][startx]);
E 4
I 4
			touchline(win, y, minx, maxx - &win->_y[y][0]);
E 4
E 2
		startx = 0;
	}
D 2
	win->_curx = win->_cury = 0;
E 2
}
E 1
