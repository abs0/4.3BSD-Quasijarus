h01069
s 00010/00005/00048
d D 5.3 88/06/30 17:21:30 bostic 8 7
c install approved copyright notice
e
s 00010/00004/00043
d D 5.2 88/06/08 13:57:01 bostic 7 6
c written by Ken Arnold; add Berkeley specific header
e
s 00010/00001/00037
d D 5.1 85/06/07 11:29:32 dist 6 5
c Add copyright
e
s 00020/00007/00018
d D 1.5 85/05/01 16:58:59 bloom 5 4
c new version from arnold
e
s 00001/00001/00024
d D 1.4 81/05/11 17:32:30 arnold 4 3
c fix an off-by-one error
e
s 00001/00001/00024
d D 1.3 81/04/16 23:28:32 arnold 3 2
c fix stupid bugs so they WORK!
e
s 00000/00001/00025
d D 1.2 81/03/05 19:15:39 arnold 2 1
c eliminate unnecessary return
e
s 00026/00000/00000
d D 1.1 81/01/26 17:02:49 arnold 1 0
c date and time created 81/01/26 17:02:49 by arnold
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
 *	This routine deletes a line from the screen.  It leaves
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
wdeleteln(win)
D 5
reg WINDOW	*win; {

E 5
I 5
reg WINDOW	*win;
{
E 5
	reg char	*temp;
	reg int		y;
	reg char	*end;
I 5
	reg int		x;
E 5

I 5
# ifdef DEBUG
	fprintf(outf, "DELETELN(%0.2o)\n", win);
# endif
E 5
	temp = win->_y[win->_cury];
D 4
	for (y = win->_cury; y < win->_maxy; y++) {
E 4
I 4
	for (y = win->_cury; y < win->_maxy - 1; y++) {
E 4
D 5
		win->_y[y] = win->_y[y+1];
		win->_firstch[y] = 0;
		win->_lastch[y] = win->_maxx - 1;
E 5
I 5
		if (win->_orig == NULL)
			win->_y[y] = win->_y[y + 1];
		else
			bcopy(win->_y[y + 1], win->_y[y], win->_maxx);
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
D 3
	win->_y[win->_maxy-1] = temp;
E 3
I 3
D 5
	win->_y[win->_maxy-1] = temp - win->_maxx;
E 5
I 5
	touchline(win, win->_cury, 0, win->_maxx - 1);
	if (win->_orig == NULL)
		_id_subwins(win);
	return OK;
E 5
E 3
D 2
	return OK;
E 2
}
E 1
