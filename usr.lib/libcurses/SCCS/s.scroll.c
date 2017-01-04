h17930
s 00010/00005/00043
d D 5.3 88/06/30 17:22:04 bostic 9 8
c install approved copyright notice
e
s 00010/00004/00038
d D 5.2 88/06/08 13:57:45 bostic 8 7
c written by Ken Arnold; add Berkeley specific header
e
s 00010/00001/00032
d D 5.1 85/06/07 11:41:57 dist 7 6
c Add copyright
e
s 00012/00020/00021
d D 1.6 85/05/23 15:41:56 bloom 6 5
c bug fix from arnold
e
s 00002/00002/00039
d D 1.5 85/05/01 17:34:07 bloom 5 4
c new version from arnold
e
s 00006/00003/00035
d D 1.4 84/07/20 11:48:00 mckusick 4 3
c fix gratuitous extra line of scrolling (from sdcsvax!laman)
e
s 00004/00003/00034
d D 1.3 83/06/01 14:04:42 arnold 3 2
c copy the last line to the next to last, too
e
s 00001/00001/00036
d D 1.2 81/05/11 17:38:10 arnold 2 1
c fix an off-by-one error
e
s 00037/00000/00000
d D 1.1 81/01/26 17:03:13 arnold 1 0
c date and time created 81/01/26 17:03:13 by arnold
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
 *	This routine scrolls the window up a line.
 *
D 5
 * %G% (Berkeley) %W%
E 5
I 5
D 7
 * %W% (Berkeley) %G%
E 7
E 5
 */
scroll(win)
D 6
reg WINDOW	*win; {
E 6
I 6
register  WINDOW	*win;
{
	register int	oy, ox;
E 6

D 6
	reg char	*sp;
	reg int		i;
	reg char	*temp;
E 6
I 6
# ifdef DEBUG
	fprintf(outf, "SCROLL(%0.2o)\n", win);
# endif
E 6

	if (!win->_scroll)
		return ERR;
D 6
	temp = win->_y[0];
D 2
	for (i = 0; i < win->_maxy - 1; i++)
E 2
I 2
D 3
	for (i = 0; i < win->_maxy - 2; i++)
E 2
		win->_y[i] = win->_y[i+1];
	for (sp = temp; sp - temp < win->_maxx; )
E 3
I 3
	for (i = 1; i < win->_maxy; i++)
		win->_y[i - 1] = win->_y[i];
	for (sp = temp; sp < &temp[win->_maxx]; )
E 3
		*sp++ = ' ';
	win->_y[win->_maxy - 1] = temp;
E 6
I 6

	getyx(win, oy, ox);
	wmove(win, 0, 0);
	wdeleteln(win);
	wmove(win, oy, ox);

E 6
D 4
	win->_cury--;
E 4
	if (win == curscr) {
D 5
		putchar('\n');
E 5
I 5
		_putchar('\n');
E 5
		if (!NONL)
			win->_curx = 0;
# ifdef DEBUG
		fprintf(outf, "SCROLL: win == curscr\n");
I 4
D 6
		fflush(outf);
E 6
E 4
# endif
D 4
	}
E 4
I 4
D 6
	} else {
		if(win->_cury-- <= 0)
			win->_cury = 0;
E 4
# ifdef DEBUG
D 4
	else
E 4
		fprintf(outf, "SCROLL: win [0%o] != curscr [0%o]\n",win,curscr);
I 4
		fflush(outf);
E 4
# endif
E 6
I 4
	}
E 4
I 3
D 6
	touchwin(win);
E 3
	return OK;
E 6
}
E 1
