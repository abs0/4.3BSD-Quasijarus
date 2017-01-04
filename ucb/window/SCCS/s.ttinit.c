h04216
s 00010/00005/00086
d D 3.20 88/06/29 21:36:48 bostic 20 19
c install approved copyright notice
e
s 00002/00000/00089
d D 3.19 88/05/11 18:04:14 edward 19 18
c scrolling region, suggestion from Ray Moody (ray@j.cc.purdue.edu)
e
s 00013/00007/00076
d D 3.18 88/02/21 13:37:39 bostic 18 17
c written by Edward Wang; attach Berkeley specific copyright
e
s 00005/00000/00078
d D 3.17 87/10/04 18:07:52 edward 17 16
c added Wyse 60 and 75 support (from mips!dce)
e
s 00001/00001/00077
d D 3.16 86/08/05 01:24:43 edward 16 15
c lint
e
s 00002/00000/00076
d D 3.15 86/08/04 15:16:05 edward 15 14
c ttzentec.c added
e
s 00006/00000/00070
d D 3.14 85/04/24 16:15:15 edward 14 13
c copyright messages
e
s 00002/00002/00068
d D 3.13 85/04/03 22:20:40 edward 13 12
c lint, and others
e
s 00002/00000/00068
d D 3.12 85/03/01 18:04:41 edward 12 11
c tvi925 added (from David Barto)
e
s 00018/00000/00050
d D 3.11 85/03/01 17:40:27 edward 11 10
c changing window size and new WINSZ ioctl
e
s 00001/00001/00049
d D 3.10 84/05/23 01:58:08 edward 10 9
c new sccs id
e
s 00002/00000/00048
d D 3.9 84/03/23 18:16:39 edward 9 8
c compile with -R
e
s 00006/00000/00042
d D 3.8 84/03/03 22:46:18 edward 8 7
c interrupt driven input
e
s 00000/00000/00042
d D 3.7 83/12/17 15:38:31 edward 7 6
c WWM_GRP added
e
s 00008/00002/00034
d D 3.6 83/08/26 16:26:22 edward 6 5
c error reporting
e
s 00001/00001/00035
d D 3.5 83/08/15 18:46:14 edward 5 4
c lint
e
s 00002/00003/00034
d D 3.4 83/08/15 18:14:37 edward 4 3
c tt cleanup
e
s 00018/00000/00019
d D 3.3 83/08/15 17:41:57 edward 3 2
c use the terminal's standard name.
e
s 00000/00000/00019
d D 3.2 83/08/11 17:23:09 edward 2 1
i
c last few day's work
e
s 00019/00000/00000
d D 3.1 83/08/09 18:35:16 edward 1 0
c date and time created 83/08/09 18:35:16 by edward
e
u
U
t
T
I 1
D 18
#ifndef lint
D 10
static	char *sccsid = "%W% %E%";
E 10
I 10
static char sccsid[] = "%W% %G%";
E 10
#endif

E 18
I 14
/*
D 18
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 18
I 18
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 20
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 20
I 20
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
E 20
E 18
 */
I 18

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 18

E 14
#include "ww.h"
I 4
#include "tt.h"
E 4

I 11
int tt_h19();
int tt_h29();
int tt_f100();
I 12
int tt_tvi925();
I 17
int tt_wyse75();
int tt_wyse60();
E 17
I 15
int tt_zentec();
E 15
E 12
int tt_generic();
struct tt_tab tt_tab[] = {
	{ "h19",	3, tt_h19 },
	{ "h29",	3, tt_h29 },
	{ "f100",	4, tt_f100 },
I 12
	{ "tvi925",	6, tt_tvi925 },
I 17
	{ "wyse75",	6, tt_wyse75 },
	{ "wyse60",	6, tt_wyse60 },
	{ "w60",	3, tt_wyse60 },
E 17
I 15
	{ "zentec",	6, tt_zentec },
E 15
E 12
	{ "generic",	0, tt_generic },
	0
};

E 11
ttinit()
{
	register struct tt_tab *tp;
I 3
	register char *p, *q;
	register char *t;
I 11
	struct winsize winsize;
E 11
E 3

I 9
	tt_strp = tt_strings;

E 9
I 3
	/*
I 8
	 * Set output buffer size to about 1 second of output time.
	 */
	tt_obp = tt_ob;
	tt_obe = tt_ob + MIN(wwbaud/10, sizeof tt_ob);

	/*
E 8
	 * Use the standard name of the terminal (i.e. the second
	 * name in termcap).
	 */
	for (p = wwtermcap; *p && *p != '|' && *p != ':'; p++)
		;
	if (*p == '|')
		p++;
	for (q = p; *q && *q != '|' && *q != ':'; q++)
		;
D 5
	if (q != p && (t = malloc(q - p + 1)) != 0) {
E 5
I 5
	if (q != p && (t = malloc((unsigned) (q - p + 1))) != 0) {
E 5
		wwterm = t;
		while (p < q)
			*t++ = *p++;
		*t = 0;
	}
E 3
	for (tp = tt_tab; tp->tt_name != 0; tp++)
		if (strncmp(tp->tt_name, wwterm, tp->tt_len) == 0)
			break;
D 6
	if (tp->tt_name == 0)
E 6
I 6
	if (tp->tt_name == 0) {
		wwerrno = WWE_BADTERM;
E 6
		return -1;
D 4
	if ((*tp->tt_func)() < 0)
		return -1;
	return (*tt.tt_init)();
E 4
I 4
D 6
	return (*tp->tt_func)();
E 6
I 6
	}
	if ((*tp->tt_func)() < 0) {
		wwerrno = WWE_CANTDO;
		return -1;
I 11
	}
I 19
	tt.tt_scroll_top = 0;
	tt.tt_scroll_bot = tt.tt_nrow - 1;
E 19
D 13
	if (ioctl(0, TIOCGWINSZ, (char *)&winsize) >= 0 && winsize.ws_row != 0
	    && winsize.ws_col != 0) {
E 13
I 13
D 16
	if (ioctl(0, (int)TIOCGWINSZ, (char *)&winsize) >= 0 &&
E 16
I 16
	if (ioctl(0, TIOCGWINSZ, (char *)&winsize) >= 0 &&
E 16
	    winsize.ws_row != 0 && winsize.ws_col != 0) {
E 13
		tt.tt_nrow = winsize.ws_row;
		tt.tt_ncol = winsize.ws_col;
E 11
	}
	return 0;
E 6
E 4
}
E 1
