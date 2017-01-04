h33104
s 00010/00005/00043
d D 5.3 88/06/30 17:21:34 bostic 6 5
c install approved copyright notice
e
s 00010/00004/00038
d D 5.2 88/06/08 13:57:06 bostic 5 4
c written by Ken Arnold; add Berkeley specific header
e
s 00010/00001/00032
d D 5.1 85/06/07 11:31:17 dist 4 3
c Add copyright
e
s 00003/00008/00030
d D 1.3 85/05/01 17:08:42 bloom 3 2
c new version from arnold
e
s 00003/00000/00035
d D 1.2 81/01/27 12:29:20 arnold 2 1
c add debug messages
e
s 00035/00000/00000
d D 1.1 81/01/26 17:02:53 arnold 1 0
c date and time created 81/01/26 17:02:53 by arnold
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
 *	This routine erases everything on the window.
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
werase(win)
reg WINDOW	*win; {

	reg int		y;
	reg char	*sp, *end, *start, *maxx;
	reg int		minx;

I 2
# ifdef DEBUG
	fprintf(outf, "WERASE(%0.2o)\n", win);
# endif
E 2
	for (y = 0; y < win->_maxy; y++) {
		minx = _NOCHANGE;
		start = win->_y[y];
		end = &start[win->_maxx];
		for (sp = start; sp < end; sp++)
			if (*sp != ' ') {
				maxx = sp;
				if (minx == _NOCHANGE)
					minx = sp - start;
				*sp = ' ';
			}
D 3
		if (minx != _NOCHANGE) {
			if (win->_firstch[y] > minx
			     || win->_firstch[y] == _NOCHANGE)
				win->_firstch[y] = minx;
			if (win->_lastch[y] < maxx - win->_y[y])
				win->_lastch[y] = maxx - win->_y[y];
		}
E 3
I 3
		if (minx != _NOCHANGE)
			touchline(win, y, minx, maxx - win->_y[y]);
E 3
	}
	win->_curx = win->_cury = 0;
}
E 1
