h46176
s 00010/00005/00046
d D 5.3 88/06/30 17:21:56 bostic 8 7
c install approved copyright notice
e
s 00010/00004/00041
d D 5.2 88/06/08 13:57:35 bostic 7 6
c written by Ken Arnold; add Berkeley specific header
e
s 00010/00001/00035
d D 5.1 85/06/07 11:39:19 dist 6 5
c Add copyright
e
s 00019/00014/00017
d D 1.4 85/05/01 17:27:20 bloom 5 4
c new version from arnold
e
s 00005/00002/00026
d D 1.3 83/03/27 15:09:48 arnold 4 2
c 
e
s 00002/00002/00026
d R 1.3 82/02/16 17:09:25 arnold 3 2
c check boundary conditions properly
e
s 00001/00001/00027
d D 1.2 82/02/16 17:06:13 arnold 2 1
c include curses.ext, not curses.h
e
s 00028/00000/00000
d D 1.1 81/01/26 17:03:07 arnold 1 0
c date and time created 81/01/26 17:03:07 by arnold
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
D 2
# include	"curses.h"
E 2
I 2
# include	"curses.ext"
I 5
# include	<ctype.h>
E 5
E 2

# define	min(a,b)	(a < b ? a : b)
I 5
# define	max(a,b)	(a > b ? a : b)
E 5

/*
 *	This routine writes win1 on win2 destructively.
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
overwrite(win1, win2)
reg WINDOW	*win1, *win2; {

D 4
	reg int		x, y, minx, miny, starty;
E 4
I 4
D 5
	reg int		x, y, minx, miny, startx, starty;
E 5
I 5
	reg char	*sp, *end;
	reg int		x, y, endy, endx, starty, startx;
E 5
E 4

# ifdef DEBUG
D 5
	fprintf(outf, "OVERWRITE(0%o, 0%o);\n", win1, win2);
E 5
I 5
	fprintf(outf, "OVERWRITE(%0.2o, %0.2o);\n", win1, win2);
E 5
# endif
D 5
	miny = min(win1->_maxy, win2->_maxy);
	minx = min(win1->_maxx, win2->_maxx);
E 5
I 5
	starty = max(win1->_begy, win2->_begy);
	startx = max(win1->_begx, win2->_begx);
	endy = min(win1->_maxy + win1->_begy, win2->_maxy + win2->_begx);
	endx = min(win1->_maxx + win1->_begx, win2->_maxx + win2->_begx);
	if (starty >= endy || startx >= endx)
		return;
E 5
# ifdef DEBUG
D 5
	fprintf(outf, "OVERWRITE:\tminx = %d,  miny = %d\n", minx, miny);
E 5
I 5
	fprintf(outf, "OVERWRITE:from (%d,%d) to (%d,%d)\n", starty, startx, endy, endx);
E 5
# endif
D 5
	starty = win1->_begy - win2->_begy;
I 4
	startx = win1->_begx - win2->_begx;
	if (startx < 0)
		startx = 0;
E 4
	for (y = 0; y < miny; y++)
D 4
		if (wmove(win2, y + starty, 0) != ERR)
E 4
I 4
		if (wmove(win2, y + starty, startx) != ERR)
E 4
			for (x = 0; x < minx; x++)
				waddch(win2, win1->_y[y][x]);
E 5
I 5
	x = endx - startx;
	for (y = starty; y < endy; y++) {
		bcopy(&win1->_y[y - win1->_begy][startx - win1->_begx],
		      &win2->_y[y - win2->_begy][startx - win2->_begx], x);
		touchline(win2, y, startx - win2->_begx, endx - win2->_begx);
	}
E 5
}
E 1
