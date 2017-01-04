h10410
s 00010/00005/00052
d D 5.5 88/06/30 17:21:54 bostic 11 10
c install approved copyright notice
e
s 00010/00004/00047
d D 5.4 88/06/08 13:57:33 bostic 10 9
c written by Ken Arnold; add Berkeley specific header
e
s 00000/00006/00051
d D 5.3 87/09/14 15:44:10 bostic 9 8
c overlay, not overwrite; bug report 4.3BSD/usr.lib/51, tahoe/usr.lib/2
e
s 00008/00007/00049
d D 5.2 86/02/12 19:24:25 bloom 8 7
c it was really broken (from muller@nprdc.arpa)
e
s 00010/00001/00046
d D 5.1 85/06/07 11:38:39 dist 7 6
c Add copyright
e
s 00024/00011/00023
d D 1.6 85/05/01 17:27:16 bloom 6 5
c new version from arnold
e
s 00001/00001/00033
d D 1.5 84/07/10 00:07:13 mckusick 5 4
c last line botched (fix from Mike Laman, NCR Torrey Pines)
e
s 00001/00001/00033
d D 1.4 82/11/05 17:12:02 arnold 4 3
c fix bug with max() macro
e
s 00005/00010/00029
d D 1.3 82/02/16 17:09:42 arnold 3 2
c check boundary conditions properly
e
s 00001/00001/00038
d D 1.2 82/02/16 17:06:09 arnold 2 1
c include curses.ext, not curses.h
e
s 00039/00000/00000
d D 1.1 81/01/26 17:03:06 arnold 1 0
c date and time created 81/01/26 17:03:06 by arnold
e
u
U
t
T
I 7
/*
D 10
 * Copyright (c) 1980 Regents of the University of California.
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

E 7
I 1
D 2
# include	"curses.h"
E 2
I 2
# include	"curses.ext"
E 2
# include	<ctype.h>

# define	min(a,b)	(a < b ? a : b)
D 4
# define	max(a,b)	(a < b ? a : b)
E 4
I 4
# define	max(a,b)	(a > b ? a : b)
E 4

/*
 *	This routine writes win1 on win2 non-destructively.
 *
D 6
 * %G% (Berkeley) %W%
E 6
I 6
D 7
 * %W% (Berkeley) %G%
E 7
E 6
 */
overlay(win1, win2)
reg WINDOW	*win1, *win2; {

	reg char	*sp, *end;
D 3
	reg int		x, y, endy, endx, starty, startx, y_top,
			y_bot, x_left, x_right;
E 3
I 3
	reg int		x, y, endy, endx, starty, startx;
I 8
	reg int 	y1,y2;
E 8
E 3

# ifdef DEBUG
	fprintf(outf, "OVERLAY(%0.2o, %0.2o);\n", win1, win2);
# endif
D 3
	y_top = max(win1->_begy, win2->_begy);
	y_bot = min(win1->_maxy, win2->_maxy);
	x_left = max(win1->_begx, win2->_begx);
	x_right = min(win1->_maxx, win2->_maxx);
	starty = y_top - win1->_begy;
	startx = x_left - win1->_begx;
	endy = y_bot - win1->_begy;
	endx = x_right - win1->_begx;
E 3
I 3
D 6
	starty = max(win1->_begy, win2->_begy) - win1->_begy;
	startx = max(win1->_begx, win2->_begx) - win1->_begx;
	endy = min(win1->_maxy, win2->_maxy) - win1->_begy - 1;
	endx = min(win1->_maxx, win2->_maxx) - win1->_begx - 1;
E 3
D 5
	for (y = starty; y < endy; y++) {
E 5
I 5
	for (y = starty; y <= endy; y++) {
E 5
		end = &win1->_y[y][endx];
		x = startx + win1->_begx;
		for (sp = &win1->_y[y][startx]; sp <= end; sp++) {
			if (!isspace(*sp))
				mvwaddch(win2, y + win1->_begy, x, *sp);
E 6
I 6
	starty = max(win1->_begy, win2->_begy);
	startx = max(win1->_begx, win2->_begx);
	endy = min(win1->_maxy + win1->_begy, win2->_maxy + win2->_begx);
	endx = min(win1->_maxx + win1->_begx, win2->_maxx + win2->_begx);
# ifdef DEBUG
	fprintf(outf, "OVERLAY:from (%d,%d) to (%d,%d)\n", starty, startx, endy, endx);
# endif
	if (starty >= endy || startx >= endx)
		return;
D 9
	x = endx - startx;
	for (y = starty; y < endy; y++) {
		bcopy(&win1->_y[y - win1->_begy][startx - win1->_begx],
		      &win2->_y[y - win2->_begy][startx - win2->_begx], x);
		touchline(win2, y, startx - win2->_begx, endx - win2->_begx);
	}
E 9
D 8
	for (y = starty; y < endy; y++) {
		end = &win1->_y[y - win1->_begy][endx - win1->_begx];
E 8
I 8
	y1 = starty - win1->_begy;
	y2 = starty - win2->_begy;
	for (y = starty; y < endy; y++, y1++, y2++) {
		end = &win1->_y[y1][endx - win1->_begx];
E 8
		x = startx - win2->_begx;
D 8
		for (sp = &win1->_y[y][startx - win1->_begx]; sp < end; sp++) {
			if (!isspace(*sp)) {
				waddch(win2, y - win2->_begy, x);
				waddch(win2, *sp);
			}
E 8
I 8
		for (sp = &win1->_y[y1][startx - win1->_begx]; sp < end; sp++) {
			if (!isspace(*sp))
				mvwaddch(win2, y2, x, *sp);
E 8
E 6
			x++;
		}
	}
}
E 1
