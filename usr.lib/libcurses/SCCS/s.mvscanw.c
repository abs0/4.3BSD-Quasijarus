h20034
s 00010/00005/00035
d D 5.3 88/06/30 17:21:50 bostic 6 5
c install approved copyright notice
e
s 00010/00004/00030
d D 5.2 88/06/08 13:57:28 bostic 5 4
c written by Ken Arnold; add Berkeley specific header
e
s 00010/00001/00024
d D 5.1 85/06/07 11:36:45 dist 4 3
c Add copyright
e
s 00001/00001/00024
d D 1.3 85/05/01 17:24:18 bloom 3 2
c fix sccs id
e
s 00002/00002/00023
d D 1.2 83/05/17 11:27:02 arnold 2 1
c the function name is _sscans(), not _sscanw().
e
s 00025/00000/00000
d D 1.1 81/01/26 17:03:02 arnold 1 0
c date and time created 81/01/26 17:03:02 by arnold
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
 * implement the mvscanw commands.  Due to the variable number of
 * arguments, they cannot be macros.  Another sigh....
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

mvscanw(y, x, fmt, args)
reg int		y, x;
char		*fmt;
int		args; {

D 2
	return move(y, x) == OK ? _sscanw(stdscr, fmt, &args) : ERR;
E 2
I 2
	return move(y, x) == OK ? _sscans(stdscr, fmt, &args) : ERR;
E 2
}

mvwscanw(win, y, x, fmt, args)
reg WINDOW	*win;
reg int		y, x;
char		*fmt;
int		args; {

D 2
	return wmove(win, y, x) == OK ? _sscanw(win, fmt, &args) : ERR;
E 2
I 2
	return wmove(win, y, x) == OK ? _sscans(win, fmt, &args) : ERR;
E 2
}
E 1
