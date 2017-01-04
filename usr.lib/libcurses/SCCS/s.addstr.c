h07711
s 00010/00005/00026
d D 5.4 88/06/30 17:21:12 bostic 6 5
c install approved copyright notice
e
s 00010/00004/00021
d D 5.3 88/06/08 13:56:43 bostic 5 4
c written by Ken Arnold; add Berkeley specific header
e
s 00002/00005/00023
d D 5.2 87/06/24 14:17:14 minshall 4 3
c Add 'addbytes.c', plus some cleanup by K. Bostic in Makefile.
e
s 00010/00001/00018
d D 5.1 85/06/07 11:25:00 dist 3 2
c Add copyright
e
s 00001/00001/00018
d D 1.2 85/05/01 16:34:37 bloom 2 1
c fix sccs ids
e
s 00019/00000/00000
d D 1.1 81/01/26 17:02:35 arnold 1 0
c date and time created 81/01/26 17:02:35 by arnold
e
u
U
t
T
I 3
/*
D 4
 * Copyright (c) 1980 Regents of the University of California.
E 4
I 4
D 5
 * Copyright (c) 1980-1987 Regents of the University of California.
E 4
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

E 3
I 1
# include	"curses.ext"

/*
 *	This routine adds a string starting at (_cury,_curx)
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
waddstr(win,str)
reg WINDOW	*win; 
reg char	*str;
{
# ifdef DEBUG
	fprintf(outf, "WADDSTR(\"%s\")\n", str);
# endif
D 4
	while (*str)
		if (waddch(win, *str++) == ERR)
			return ERR;
	return OK;
E 4
I 4
	return waddbytes(win, str, strlen(str));
E 4
}
E 1
