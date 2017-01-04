h61835
s 00010/00005/00024
d D 5.3 88/06/30 17:21:15 bostic 5 4
c install approved copyright notice
e
s 00010/00004/00019
d D 5.2 88/06/08 13:56:46 bostic 4 3
c written by Ken Arnold; add Berkeley specific header
e
s 00010/00001/00013
d D 5.1 85/06/07 11:25:54 dist 3 2
c Add copyright
e
s 00001/00010/00013
d D 1.2 85/05/01 16:39:33 bloom 2 1
c new version from arnold
e
s 00023/00000/00000
d D 1.1 81/01/26 17:02:37 arnold 1 0
c date and time created 81/01/26 17:02:37 by arnold
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
 *	This routine clears the window.
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
wclear(win)
reg WINDOW	*win; {

D 2
	if (win == curscr) {
# ifdef DEBUG
		fprintf(outf,"WCLEAR: win == curscr\n");
		fprintf(outf,"WCLEAR: curscr = %d\n",curscr);
		fprintf(outf,"WCLEAR: stdscr = %d\n",stdscr);
# endif
		clear();
		return refresh();
	}
E 2
	werase(win);
	win->_clear = TRUE;
	return OK;
}
E 1
