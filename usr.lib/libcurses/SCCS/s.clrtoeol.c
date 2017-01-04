h47549
s 00010/00005/00045
d D 5.3 88/06/30 17:21:18 bostic 7 6
c install approved copyright notice
e
s 00010/00004/00040
d D 5.2 88/06/08 13:56:48 bostic 6 5
c written by Ken Arnold; add Berkeley specific header
e
s 00010/00001/00034
d D 5.1 85/06/07 11:26:38 dist 5 4
c Add copyright
e
s 00002/00007/00033
d D 1.3 85/05/01 16:43:59 bloom 4 2
c new version from arnold
e
s 00002/00007/00033
d R 1.3 85/05/01 16:42:36 bloom 3 2
c 
e
s 00000/00002/00040
d D 1.2 81/03/05 19:12:42 arnold 2 1
c eliminate unecessary return
e
s 00042/00000/00000
d D 1.1 81/01/26 17:02:40 arnold 1 0
c date and time created 81/01/26 17:02:40 by arnold
e
u
U
t
T
I 5
/*
D 6
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
 * Copyright (c) 1981 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
E 6
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 6
#endif not lint
E 6
I 6
#endif /* not lint */
E 6

E 5
I 1
# include	"curses.ext"

/*
 *	This routine clears up to the end of line
 *
D 4
 * %G% (Berkeley) %W%
E 4
I 4
D 5
 * %W% (Berkeley) %G%
E 5
E 4
 */
wclrtoeol(win)
reg WINDOW	*win; {

	reg char	*sp, *end;
	reg int		y, x;
	reg char	*maxx;
	reg int		minx;

	y = win->_cury;
	x = win->_curx;
	end = &win->_y[y][win->_maxx];
	minx = _NOCHANGE;
	maxx = &win->_y[y][x];
	for (sp = maxx; sp < end; sp++)
		if (*sp != ' ') {
			maxx = sp;
			if (minx == _NOCHANGE)
				minx = sp - win->_y[y];
			*sp = ' ';
		}
	/*
	 * update firstch and lastch for the line
	 */
I 4
	touchline(win, y, win->_curx, win->_maxx - 1);
E 4
# ifdef DEBUG
	fprintf(outf, "CLRTOEOL: minx = %d, maxx = %d, firstch = %d, lastch = %d\n", minx, maxx - win->_y[y], win->_firstch[y], win->_lastch[y]);
# endif
D 4
	if (minx != _NOCHANGE) {
		if (win->_firstch[y] > minx || win->_firstch[y] == _NOCHANGE)
			win->_firstch[y] = minx;
		if (win->_lastch[y] < maxx - win->_y[y])
			win->_lastch[y] = maxx - win->_y[y];
	}
E 4
D 2

	return OK;
E 2
}
E 1
