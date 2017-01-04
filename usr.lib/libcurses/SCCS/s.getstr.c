h14310
s 00010/00005/00030
d D 5.3 88/06/30 17:21:38 bostic 8 7
c install approved copyright notice
e
s 00010/00004/00025
d D 5.2 88/06/08 13:57:11 bostic 7 6
c written by Ken Arnold; add Berkeley specific header
e
s 00010/00001/00019
d D 5.1 85/06/07 11:32:52 dist 6 5
c Add copyright
e
s 00001/00001/00019
d D 1.5 85/05/01 17:11:32 bloom 5 4
c fix sccs id
e
s 00001/00001/00019
d D 1.4 83/06/21 14:29:49 arnold 4 3
c delete a spurious semicolon at the end of a while
e
s 00001/00001/00019
d D 1.3 81/04/29 15:27:28 arnold 3 2
c fix a stupid typo
e
s 00004/00002/00016
d D 1.2 81/04/10 13:02:21 arnold 2 1
c fix bug in EOF check
e
s 00018/00000/00000
d D 1.1 81/01/26 17:02:55 arnold 1 0
c date and time created 81/01/26 17:02:55 by arnold
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
 *	This routine gets a string starting at (_cury,_curx)
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
wgetstr(win,str)
reg WINDOW	*win; 
reg char	*str; {

D 4
	while ((*str = wgetch(win)) != ERR && *str != '\n');
E 4
I 4
	while ((*str = wgetch(win)) != ERR && *str != '\n')
E 4
		str++;
D 2
	*str = '\0';
	if (*str == ERR)
E 2
I 2
	if (*str == ERR) {
E 2
D 3
		return ERR;
E 3
I 2
		*str = '\0';
I 3
		return ERR;
E 3
	}
	*str = '\0';
E 2
	return OK;
}
E 1
