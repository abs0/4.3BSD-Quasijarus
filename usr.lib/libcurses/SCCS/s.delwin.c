h13841
s 00010/00005/00053
d D 5.3 88/06/30 17:21:32 bostic 9 8
c install approved copyright notice
e
s 00010/00004/00048
d D 5.2 88/06/08 13:57:03 bostic 8 7
c written by Ken Arnold; add Berkeley specific header
e
s 00010/00001/00042
d D 5.1 85/06/07 11:30:21 dist 7 6
c Add copyright
e
s 00007/00007/00036
d D 1.6 85/05/01 17:05:13 bloom 6 5
c new version from arnold
e
s 00015/00000/00028
d D 1.5 83/04/06 18:38:47 arnold 5 4
c handle deleting subwindows
e
s 00000/00000/00028
d D 1.4 83/04/06 18:31:12 arnold 4 3
c try to deal with subwindow deletion
e
s 00010/00002/00018
d D 1.3 83/04/06 18:30:42 arnold 3 2
c try to deal with subwindows
e
s 00002/00000/00018
d D 1.2 83/03/27 15:09:50 arnold 2 1
c 
e
s 00018/00000/00000
d D 1.1 81/01/26 17:02:50 arnold 1 0
c date and time created 81/01/26 17:02:50 by arnold
e
u
U
t
T
I 7
/*
D 8
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
I 8
 * Copyright (c) 1981 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
E 8
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 8
#endif not lint
E 8
I 8
#endif /* not lint */
E 8

E 7
I 1
# include	"curses.ext"

/*
 *	This routine deletes a window and releases it back to the system.
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
delwin(win)
reg WINDOW	*win; {

D 3
	reg int	i;
E 3
I 3
	reg int		i;
	reg WINDOW	*wp, *np;
E 3

D 3
	if (!(win->_flags & _SUBWIN))
E 3
I 3
	if (win->_orig == NULL) {
I 5
		/*
		 * If we are the original window, delete the space for
		 * all the subwindows, and the array of space as well.
		 */
E 5
E 3
		for (i = 0; i < win->_maxy && win->_y[i]; i++)
D 6
			cfree(win->_y[i]);
E 6
I 6
			free(win->_y[i]);
		free(win->_firstch);
		free(win->_lastch);
E 6
I 3
		wp = win->_nextp;
		while (wp != win) {
			np = wp->_nextp;
			delwin(wp);
			wp = np;
		}
I 5
	}
	else {
		/*
D 6
		 * If we are a subwindow, take ourself out of the
E 6
I 6
		 * If we are a subwindow, take ourselves out of the
E 6
		 * list.  NOTE: if we are a subwindow, the minimum list
		 * is orig followed by this subwindow, so there are
		 * always at least two windows in the list.
		 */
		for (wp = win->_nextp; wp->_nextp != win; wp = wp->_nextp)
			continue;
		wp->_nextp = win->_nextp;
E 5
	}
E 3
D 6
	cfree(win->_y);
I 2
	cfree(win->_firstch);
	cfree(win->_lastch);
E 2
	cfree(win);
E 6
I 6
	free(win->_y);
	free(win);
E 6
}
E 1
