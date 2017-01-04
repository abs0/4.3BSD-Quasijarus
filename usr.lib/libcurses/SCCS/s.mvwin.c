h27790
s 00010/00005/00052
d D 5.3 88/06/30 17:21:51 bostic 5 4
c install approved copyright notice
e
s 00010/00004/00047
d D 5.2 88/06/08 13:57:30 bostic 4 3
c written by Ken Arnold; add Berkeley specific header
e
s 00010/00001/00041
d D 5.1 85/06/07 11:37:11 dist 3 2
c Add copyright
e
s 00026/00003/00016
d D 1.2 85/05/01 17:27:04 bloom 2 1
c new version from arnold
e
s 00019/00000/00000
d D 1.1 81/01/26 17:03:03 arnold 1 0
c date and time created 81/01/26 17:03:03 by arnold
e
u
U
t
T
I 3
/*
D 4
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
I 4
 * Copyright (c) 1981 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 5
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 5
I 5
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
E 5
E 4
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif not lint
E 4
I 4
#endif /* not lint */
E 4

E 3
I 1
# include	"curses.ext"

/*
 * relocate the starting position of a window
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

mvwin(win, by, bx)
reg WINDOW	*win;
reg int		by, bx; {

I 2
	register WINDOW	*orig;
	register int	dy, dx;

E 2
	if (by + win->_maxy > LINES || bx + win->_maxx > COLS)
		return ERR;
D 2
	win->_begy = by;
	win->_begx = bx;
E 2
I 2
	dy = by - win->_begy;
	dx = bx - win->_begx;
	orig = win->_orig;
	if (orig == NULL) {
		orig = win;
		do {
			win->_begy += dy;
			win->_begx += dx;
			_swflags_(win);
			win = win->_nextp;
		} while (win != orig);
	}
	else {
		if (by < orig->_begy || win->_maxy + dy > orig->_maxy)
			return ERR;
		if (bx < orig->_begx || win->_maxx + dx > orig->_maxx)
			return ERR;
		win->_begy = by;
		win->_begx = bx;
		_swflags_(win);
		_set_subwin_(orig, win);
	}
E 2
	touchwin(win);
	return OK;
}
E 1
