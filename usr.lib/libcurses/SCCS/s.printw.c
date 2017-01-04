h65237
s 00010/00005/00044
d D 5.4 88/06/30 17:21:58 bostic 6 5
c install approved copyright notice
e
s 00010/00004/00039
d D 5.3 88/06/08 13:57:37 bostic 5 4
c written by Ken Arnold; add Berkeley specific header
e
s 00005/00023/00038
d D 5.2 88/06/08 12:50:18 bostic 4 3
c use vsprintf, instead of rolling our own
e
s 00010/00001/00051
d D 5.1 85/06/07 11:39:50 dist 3 2
c Add copyright
e
s 00001/00001/00051
d D 1.2 85/05/01 17:28:29 bloom 2 1
c fix sccs id
e
s 00052/00000/00000
d D 1.1 81/01/26 17:03:08 arnold 1 0
c date and time created 81/01/26 17:03:08 by arnold
e
u
U
t
T
I 1
/*
I 3
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

/*
E 3
 * printw and friends
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

# include	"curses.ext"

/*
 *	This routine implements a printf on the standard screen.
 */
printw(fmt, args)
char	*fmt;
int	args; {

D 4
	return _sprintw(stdscr, fmt, &args);
E 4
I 4
	char	buf[512];

	(void) vsprintf(buf, fmt, &args);
	return waddstr(stdscr, buf);
E 4
}

/*
 *	This routine implements a printf on the given window.
 */
wprintw(win, fmt, args)
WINDOW	*win;
char	*fmt;
int	args; {

D 4
	return _sprintw(win, fmt, &args);
}
/*
 *	This routine actually executes the printf and adds it to the window
 *
 *	This is really a modified version of "sprintf".  As such,
 * it assumes that sprintf interfaces with the other printf functions
 * in a certain way.  If this is not how your system works, you
 * will have to modify this routine to use the interface that your
 * "sprintf" uses.
 */
_sprintw(win, fmt, args)
WINDOW	*win;
char	*fmt;
int	*args; {

	FILE	junk;
E 4
	char	buf[512];

D 4
	junk._flag = _IOWRT + _IOSTRG;
	junk._ptr = buf;
	junk._cnt = 32767;
	_doprnt(fmt, args, &junk);
	putc('\0', &junk);
E 4
I 4
	(void) vsprintf(buf, fmt, &args);
E 4
	return waddstr(win, buf);
}
E 1
