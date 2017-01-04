h38431
s 00010/00005/00031
d D 3.11 88/06/29 21:37:56 bostic 18 17
c install approved copyright notice
e
s 00005/00000/00031
d D 3.10 88/05/11 18:04:10 edward 17 16
c scrolling region, suggestion from Ray Moody (ray@j.cc.purdue.edu)
e
s 00013/00007/00018
d D 3.9 88/02/21 13:38:17 bostic 16 15
c written by Edward Wang; attach Berkeley specific copyright
e
s 00005/00000/00020
d D 3.8 85/08/14 21:51:39 edward 15 14
c don't do unnecessary set modes and cursor motion
e
s 00006/00000/00014
d D 3.7 85/04/24 16:10:53 edward 14 13
c copyright messages
e
s 00001/00001/00013
d D 3.6 84/11/20 23:39:24 edward 13 12
c we don't flush typeahead any more
e
s 00001/00001/00013
d D 3.5 84/05/23 01:56:14 edward 12 11
c new sccs id
e
s 00001/00001/00013
d D 3.4 84/03/03 22:41:36 edward 11 10
c interrupt driven input
e
s 00001/00001/00013
d D 3.3 83/08/15 18:46:11 edward 10 9
c lint
e
s 00002/00001/00012
d D 3.2 83/08/15 18:14:10 edward 9 8
c tt cleanup
e
s 00001/00000/00012
d D 3.1 83/08/11 17:20:58 edward 8 6
i 7
c last few day's work
e
s 00003/00002/00009
d D 2.1.1.1 83/08/09 18:33:44 edward 7 6
c mile stone
e
s 00000/00000/00011
d D 2.1 83/07/30 13:26:39 edward 6 5
c prepare for major change
e
s 00000/00000/00011
d D 1.5 83/07/22 17:07:00 edward 5 4
c scrolling.
c uses Wscreensize() to get screen size.
c More intelligent framing.
c etc.
e
s 00000/00000/00011
d D 1.4 83/07/19 20:07:27 edward 4 3
c today's work
e
s 00000/00000/00011
d D 1.3 83/07/18 21:02:13 edward 3 2
c multiple window
e
s 00002/00001/00009
d D 1.2 83/07/17 15:42:01 edward 2 1
c 
e
s 00010/00000/00000
d D 1.1 83/07/12 17:20:42 edward 1 0
c date and time created 83/07/12 17:20:42 by edward
e
u
U
f b 
t
T
I 1
D 16
#ifndef lint
D 12
static	char *sccsid = "%W% %E%";
E 12
I 12
static char sccsid[] = "%W% %G%";
E 12
#endif

E 16
I 14
/*
D 16
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 16
I 16
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 18
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 18
I 18
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
E 18
E 16
 */
I 16

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 16

E 14
#include "ww.h"
I 9
#include "tt.h"
E 9

wwend()
{
I 15
	wwupdate();
I 17
	if (tt.tt_scroll_top != 0 || tt.tt_scroll_bot != tt.tt_nrow - 1)
		/* tt.tt_setscroll is known to be defined */
		(*tt.tt_setscroll)(0, tt.tt_nrow - 1);
E 17
	if (tt.tt_insert)
		(*tt.tt_setinsert)(0);
	if (tt.tt_modes)
		(*tt.tt_setmodes)(0);
I 17
	if (tt.tt_scroll_down)
		(*tt.tt_scroll_down)();
E 17
E 15
D 2
	endwin();
E 2
I 2
D 7
	Wcleanup();
	wwsettty(0, &wwoldtty);
E 7
I 7
	(*tt.tt_move)(tt.tt_nrow - 1, 0);
D 9
	(*tt.tt_cleanup)();
E 9
I 9
	(*tt.tt_end)();
E 9
I 8
D 10
	fflush(stdout);
E 10
I 10
D 11
	(void) fflush(stdout);
E 11
I 11
	ttflush();
E 11
E 10
E 8
D 13
	(void) wwsettty(0, &wwoldtty);
E 13
I 13
	(void) wwsettty(0, &wwoldtty, &wwnewtty);
E 13
E 7
E 2
}
E 1
