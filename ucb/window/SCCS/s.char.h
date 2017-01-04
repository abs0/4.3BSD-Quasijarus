h30333
s 00010/00005/00032
d D 3.6 88/06/29 21:35:27 bostic 6 5
c install approved copyright notice
e
s 00011/00007/00026
d D 3.5 88/02/21 13:36:33 bostic 5 4
c written by Edward Wang; attach Berkeley specific copyright
e
s 00001/00001/00032
d D 3.4 88/01/03 00:56:03 bostic 4 3
c fix ctrl macro for ANSI C
e
s 00006/00000/00027
d D 3.3 85/04/24 16:24:00 edward 3 2
c copyright messages
e
s 00001/00001/00026
d D 3.2 84/05/23 02:01:11 edward 2 1
c new sccs id
e
s 00027/00000/00000
d D 3.1 84/04/08 12:23:13 edward 1 0
c date and time created 84/04/08 12:23:13 by edward
e
u
U
t
T
I 1
/*
D 2
 *	%W% %E%
E 2
I 2
D 5
 * %W% %G%
E 2
 */

/*
I 3
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 5
I 5
 * Copyright (c) 1983 Regents of the University of California.
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
 *
 *	%W% (Berkeley) %G%
E 5
 */

/*
E 3
 * Macros and things to deal with control characters.
 *
 * Unctrl() is just like the standard function, except we don't want
 * to include curses.
 * Isctrl() returns true for all characters less than space and
 * greater than or equal to delete.
 * Isprt() is tab and all characters not isctrl().  It's used
 * by wwwrite().
 * Isunctrl() includes all characters that should be expanded
 * using unctrl() by wwwrite() if ww_unctrl is set.
 */

char *_unctrl[];
char _cmap[];
D 4
#define ctrl(c)		('c' & 0x1f)
E 4
I 4
#define ctrl(c)		(c & 0x1f)
E 4
#define unctrl(c)	(_unctrl[(unsigned char) (c)])
#define _C		0x01
#define _P		0x02
#define _U		0x04
#define isctrl(c)	(_cmap[(unsigned char) (c)] & _C)
#define isprt(c)	(_cmap[(unsigned char) (c)] & _P)
#define isunctrl(c)	(_cmap[(unsigned char) (c)] & _U)
E 1
