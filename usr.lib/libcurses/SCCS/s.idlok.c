h43909
s 00010/00005/00028
d D 5.3 88/06/30 17:21:41 bostic 4 3
c install approved copyright notice
e
s 00010/00004/00023
d D 5.2 88/06/08 13:57:15 bostic 3 2
c written by Ken Arnold; add Berkeley specific header
e
s 00010/00001/00017
d D 5.1 85/06/07 11:33:53 dist 2 1
c Add copyright
e
s 00018/00000/00000
d D 1.1 85/05/01 17:13:53 bloom 1 0
c date and time created 85/05/01 17:13:53 by bloom
e
u
U
t
T
I 2
/*
D 3
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
I 3
 * Copyright (c) 1981 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 4
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 4
I 4
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
E 4
E 3
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif not lint
E 3
I 3
#endif /* not lint */
E 3

E 2
I 1
# include	"curses.ext"

/*
 * idlok:
 *	Turn on and off using insert/deleteln sequences for the given
 *	window.
 *
D 2
 * %W% (Berkeley) %G%
E 2
 */
idlok(win, bf)
register WINDOW	*win;
bool		bf;
{
	if (bf)
		win->_flags |= _IDLINE;
	else
		win->_flags &= ~_IDLINE;
}
E 1
