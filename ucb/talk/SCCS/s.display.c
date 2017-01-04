h63263
s 00010/00005/00163
d D 5.3 88/06/29 20:22:16 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00159
d D 5.2 88/05/20 12:36:59 bostic 4 3
c add Berkeley specific header
e
s 00007/00001/00155
d D 5.1 85/06/06 09:17:18 dist 3 2
c Add copyright
e
s 00123/00137/00033
d D 1.2 84/04/11 15:13:36 karels 2 1
c reformatting; convert daemon for inetd; add keywords
e
s 00170/00000/00000
d D 1.1 84/04/11 15:02:48 karels 1 0
c date and time created 84/04/11 15:02:48 by karels
e
u
U
t
T
I 3
/*
 * Copyright (c) 1983 Regents of the University of California.
D 4
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
I 4
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

E 3
I 1
D 2
/* $Header: display.c 1.2 83/04/23 02:09:33 moore Exp $ */
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif
E 3
I 3
D 4
#endif not lint
E 4
I 4
#endif /* not lint */
E 4
E 3
E 2

D 2
/* The window 'manager', initializes curses and handles the actual
E 2
I 2
/*
 * The window 'manager', initializes curses and handles the actual
E 2
 * displaying of text
 */
D 2

E 2
#include "talk.h"

D 2
xwin_t my_win;
xwin_t his_win;
WINDOW *line_win;
E 2
I 2
xwin_t	my_win;
xwin_t	his_win;
WINDOW	*line_win;
E 2

D 2
int curses_initialized = 0;
E 2
I 2
int	curses_initialized = 0;
E 2

D 2
    /* max HAS to be a function, it is called with
     * a argument of the form --foo at least once.
     */

E 2
I 2
/*
 * max HAS to be a function, it is called with
 * a argument of the form --foo at least once.
 */
E 2
max(a,b)
D 2
int a, b;
E 2
I 2
	int a, b;
E 2
{
D 2
    if (a > b) {
	return(a);
    } else {
	return(b);
    }
E 2
I 2

	return (a > b ? a : b);
E 2
}

/*
 * Display some text on somebody's window, processing some control
 * characters while we are at it.
 */
D 2

E 2
display(win, text, size)
D 2
register xwin_t *win;
register char *text;
int size;
E 2
I 2
	register xwin_t *win;
	register char *text;
	int size;
E 2
{
D 2
    register int i;
    char cch;
E 2
I 2
	register int i;
	char cch;
E 2

D 2
    for (i = 0; i < size; i++) {
E 2
I 2
	for (i = 0; i < size; i++) {
		if (*text == '\n') {
			xscroll(win, 0);
			text++;
			continue;
		}
		/* erase character */
		if (*text == win->cerase) {
			wmove(win->x_win, win->x_line, max(--win->x_col, 0));
			getyx(win->x_win, win->x_line, win->x_col);
			waddch(win->x_win, ' ');
			wmove(win->x_win, win->x_line, win->x_col);
			getyx(win->x_win, win->x_line, win->x_col);
			text++;
			continue;
		}
		/*
		 * On word erase search backwards until we find
		 * the beginning of a word or the beginning of
		 * the line.
		 */
		if (*text == win->werase) {
			int endcol, xcol, i, c;
E 2

D 2
	if (*text == '\n') {
	    xscroll(win, 0);
	    text++;
	    continue;
E 2
I 2
			endcol = win->x_col;
			xcol = endcol - 1;
			while (xcol >= 0) {
				c = readwin(win->x_win, win->x_line, xcol);
				if (c != ' ')
					break;
				xcol--;
			}
			while (xcol >= 0) {
				c = readwin(win->x_win, win->x_line, xcol);
				if (c == ' ')
					break;
				xcol--;
			}
			wmove(win->x_win, win->x_line, xcol + 1);
			for (i = xcol + 1; i < endcol; i++)
				waddch(win->x_win, ' ');
			wmove(win->x_win, win->x_line, xcol + 1);
			getyx(win->x_win, win->x_line, win->x_col);
			continue;
		}
		/* line kill */
		if (*text == win->kill) {
			wmove(win->x_win, win->x_line, 0);
			wclrtoeol(win->x_win);
			getyx(win->x_win, win->x_line, win->x_col);
			text++;
			continue;
		}
		if (*text == '\f') {
			if (win == &my_win)
				wrefresh(curscr);
			text++;
			continue;
		}
		if (win->x_col == COLS-1) {
			/* check for wraparound */
			xscroll(win, 0);
		}
		if (*text < ' ' && *text != '\t') {
			waddch(win->x_win, '^');
			getyx(win->x_win, win->x_line, win->x_col);
			if (win->x_col == COLS-1) /* check for wraparound */
				xscroll(win, 0);
			cch = (*text & 63) + 64;
			waddch(win->x_win, cch);
		} else
			waddch(win->x_win, *text);
		getyx(win->x_win, win->x_line, win->x_col);
		text++;
E 2
	}
D 2

	    /* erase character */

	if (*text == win->cerase) {
	    wmove(win->x_win, win->x_line, max(--win->x_col, 0));
	    getyx(win->x_win, win->x_line, win->x_col);
	    waddch(win->x_win, ' ');
	    wmove(win->x_win, win->x_line, win->x_col);
	    getyx(win->x_win, win->x_line, win->x_col);
	    text++;
	    continue;
	}
	/*
	 * On word erase search backwards until we find
	 * the beginning of a word or the beginning of
	 * the line.
	 */
	if (*text == win->werase) {
	    int endcol, xcol, i, c;

	    endcol = win->x_col;
	    xcol = endcol - 1;
	    while (xcol >= 0) {
		c = readwin(win->x_win, win->x_line, xcol);
		if (c != ' ')
			break;
		xcol--;
	    }
	    while (xcol >= 0) {
		c = readwin(win->x_win, win->x_line, xcol);
		if (c == ' ')
			break;
		xcol--;
	    }
	    wmove(win->x_win, win->x_line, xcol + 1);
	    for (i = xcol + 1; i < endcol; i++)
		waddch(win->x_win, ' ');
	    wmove(win->x_win, win->x_line, xcol + 1);
	    getyx(win->x_win, win->x_line, win->x_col);
	    continue;
	}
	    /* line kill */
	if (*text == win->kill) {
	    wmove(win->x_win, win->x_line, 0);
	    wclrtoeol(win->x_win);
	    getyx(win->x_win, win->x_line, win->x_col);
	    text++;
	    continue;
	}
	if (*text == '\f') {
	    if (win == &my_win)
		wrefresh(curscr);
	    text++;
	    continue;
	}

	if (win->x_col == COLS-1) {
		/* check for wraparound */
	    xscroll(win, 0);
	}

	if (*text < ' ' && *text != '\t') {
	    waddch(win->x_win, '^');
	    getyx(win->x_win, win->x_line, win->x_col);

	    if (win->x_col == COLS-1) {
		    /* check for wraparound */
		xscroll(win, 0);
	    }

	    cch = (*text & 63) + 64;
	    waddch(win->x_win, cch);
	} else {
	    waddch(win->x_win, *text);
	}

	getyx(win->x_win, win->x_line, win->x_col);
	text++;

    }
wrefresh(win->x_win);
E 2
I 2
	wrefresh(win->x_win);
E 2
}

/*
D 2
* Read the character at the indicated position in win
*/
E 2
I 2
 * Read the character at the indicated position in win
 */
E 2
readwin(win, line, col)
D 2
WINDOW *win;
E 2
I 2
	WINDOW *win;
E 2
{
D 2
int oldline, oldcol;
register int c;
E 2
I 2
	int oldline, oldcol;
	register int c;
E 2

D 2
getyx(win, oldline, oldcol);
wmove(win, line, col);
c = winch(win);
wmove(win, oldline, oldcol);
return(c);
E 2
I 2
	getyx(win, oldline, oldcol);
	wmove(win, line, col);
	c = winch(win);
	wmove(win, oldline, oldcol);
	return (c);
E 2
}

/*
D 2
* Scroll a window, blanking out the line following the current line
* so that the current position is obvious
*/

E 2
I 2
 * Scroll a window, blanking out the line following the current line
 * so that the current position is obvious
 */
E 2
xscroll(win, flag)
D 2
register xwin_t *win;
int flag;
E 2
I 2
	register xwin_t *win;
	int flag;
E 2
{
D 2
    if (flag == -1) {
	wmove(win->x_win, 0, 0);
	win->x_line = 0;
E 2
I 2

	if (flag == -1) {
		wmove(win->x_win, 0, 0);
		win->x_line = 0;
		win->x_col = 0;
		return;
	}
	win->x_line = (win->x_line + 1) % win->x_nlines;
E 2
	win->x_col = 0;
D 2
	return;
    }
    win->x_line = (win->x_line + 1) % win->x_nlines;
    win->x_col = 0;
    wmove(win->x_win, win->x_line, win->x_col);
    wclrtoeol(win->x_win);
    wmove(win->x_win, (win->x_line + 1) % win->x_nlines, win->x_col);
    wclrtoeol(win->x_win);
    wmove(win->x_win, win->x_line, win->x_col);
E 2
I 2
	wmove(win->x_win, win->x_line, win->x_col);
	wclrtoeol(win->x_win);
	wmove(win->x_win, (win->x_line + 1) % win->x_nlines, win->x_col);
	wclrtoeol(win->x_win);
	wmove(win->x_win, win->x_line, win->x_col);
E 2
}
E 1
