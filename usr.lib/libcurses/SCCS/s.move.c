h58644
s 00010/00005/00032
d D 5.4 88/06/30 17:21:47 bostic 5 4
c install approved copyright notice
e
s 00010/00004/00027
d D 5.3 88/06/08 13:57:24 bostic 4 3
c written by Ken Arnold; add Berkeley specific header
e
s 00002/00000/00029
d D 5.2 85/10/08 18:13:59 bloom 3 2
c check the position for negative values
e
s 00010/00001/00019
d D 5.1 85/06/07 11:35:49 dist 2 1
c Add copyright
e
s 00020/00000/00000
d D 1.1 83/03/27 16:12:36 arnold 1 0
c date and time created 83/03/27 16:12:36 by arnold
e
u
U
t
T
I 2
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

E 2
I 1
# include	"curses.ext"

/*
 *	This routine moves the cursor to the given point
 *
D 2
 * %W% (Berkeley) %G%
E 2
 */
wmove(win, y, x)
reg WINDOW	*win;
reg int		y, x; {

# ifdef DEBUG
	fprintf(outf, "MOVE to (%d, %d)\n", y, x);
# endif
I 3
	if (x < 0 || y < 0)
		return ERR;
E 3
	if (x >= win->_maxx || y >= win->_maxy)
		return ERR;
	win->_curx = x;
	win->_cury = y;
	return OK;
}
E 1
