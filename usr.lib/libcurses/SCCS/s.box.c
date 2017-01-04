h22831
s 00010/00005/00039
d D 5.3 88/06/30 17:21:13 bostic 6 5
c install approved copyright notice
e
s 00010/00004/00034
d D 5.2 88/06/08 13:56:45 bostic 5 4
c written by Ken Arnold; add Berkeley specific header
e
s 00010/00001/00028
d D 5.1 85/06/07 11:25:29 dist 4 3
c Add copyright
e
s 00001/00001/00028
d D 1.3 85/05/01 16:34:42 bloom 3 2
c fix sccs ids
e
s 00001/00001/00028
d D 1.2 82/02/16 16:01:41 arnold 2 1
c should include curses.ext, not curses.h
e
s 00029/00000/00000
d D 1.1 81/01/26 17:02:36 arnold 1 0
c date and time created 81/01/26 17:02:36 by arnold
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
D 2
# include	"curses.h"
E 2
I 2
# include	"curses.ext"
E 2

/*
 *	This routine draws a box around the given window with "vert"
 * as the vertical delimiting char, and "hor", as the horizontal one.
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
box(win, vert, hor)
reg WINDOW	*win;
char		vert, hor; {

	reg int		i;
	reg int		endy, endx;
	reg char	*fp, *lp;

	endx = win->_maxx;
	endy = win->_maxy - 1;
	fp = win->_y[0];
	lp = win->_y[endy];
	for (i = 0; i < endx; i++)
		fp[i] = lp[i] = hor;
	endx--;
	for (i = 0; i <= endy; i++)
		win->_y[i][0] = (win->_y[i][endx] = vert);
	if (!win->_scroll && (win->_flags&_SCROLLWIN))
		fp[0] = fp[endx] = lp[0] = lp[endx] = ' ';
	touchwin(win);
}
E 1
