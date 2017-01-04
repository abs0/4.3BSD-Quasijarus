h39607
s 00010/00005/00023
d D 3.6 88/06/29 21:38:39 bostic 13 12
c install approved copyright notice
e
s 00013/00007/00015
d D 3.5 88/02/21 13:38:48 bostic 12 11
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00016
d D 3.4 85/04/24 16:11:27 edward 11 10
c copyright messages
e
s 00001/00001/00015
d D 3.3 84/05/23 01:56:28 edward 10 9
c new sccs id
e
s 00001/00001/00015
d D 3.2 84/03/03 22:42:01 edward 9 8
c interrupt driven input
e
s 00000/00000/00016
d D 3.1 83/08/11 17:21:23 edward 8 6
i 7
c last few day's work
e
s 00001/00001/00015
d D 2.1.1.1 83/08/09 18:34:28 edward 7 6
c mile stone
e
s 00000/00000/00016
d D 2.1 83/07/30 13:27:13 edward 6 5
c prepare for major change
e
s 00000/00000/00016
d D 1.5 83/07/22 17:08:18 edward 5 4
c scrolling.
c uses Wscreensize() to get screen size.
c More intelligent framing.
c etc.
e
s 00000/00000/00016
d D 1.4 83/07/19 20:07:42 edward 4 3
c today's work
e
s 00000/00000/00016
d D 1.3 83/07/18 21:03:21 edward 3 2
c multiple window
e
s 00007/00004/00009
d D 1.2 83/07/17 15:42:30 edward 2 1
c 
e
s 00013/00000/00000
d D 1.1 83/07/12 17:21:06 edward 1 0
c date and time created 83/07/12 17:21:06 by edward
e
u
U
f b 
t
T
I 1
D 12
#ifndef lint
D 10
static	char *sccsid = "%W% %E%";
E 10
I 10
static char sccsid[] = "%W% %G%";
E 10
#endif

E 12
I 11
/*
D 12
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 12
I 12
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 13
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 13
I 13
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
E 13
E 12
 */
I 12

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 12

E 11
#include "ww.h"

wwputs(s, w)
D 2
	register char *s;
	register struct ww *w;
E 2
I 2
register char *s;
struct ww *w;
E 2
{
D 2
	while (*s)
		wwputc(*s++, w);
E 2
I 2
	register char *p = s;

	while (*p++)
		;
D 7
	wwwrite(w, s, p - s - 1);
E 7
I 7
D 9
	return wwwrite(w, s, p - s - 1);
E 9
I 9
	(void) wwwrite(w, s, p - s - 1);
E 9
E 7
E 2
}
E 1
