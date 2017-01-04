h28736
s 00010/00005/00038
d D 3.12 88/06/29 21:38:27 bostic 22 21
c install approved copyright notice
e
s 00013/00007/00030
d D 3.11 88/02/21 13:38:37 bostic 21 20
c written by Edward Wang; attach Berkeley specific copyright
e
s 00001/00001/00036
d D 3.10 88/01/03 00:56:13 bostic 20 19
c fix ctrl macro for ANSI C
e
s 00006/00000/00031
d D 3.9 85/04/24 16:11:05 edward 19 18
c copyright messages
e
s 00001/00001/00030
d D 3.8 84/05/23 01:56:20 edward 18 17
c new sccs id
e
s 00007/00000/00024
d D 3.7 84/04/09 23:31:24 edward 17 15
c wwbell() added
e
s 00007/00000/00024
d R 3.7 84/04/09 23:29:03 edward 16 15
c lint
e
s 00000/00025/00024
d D 3.6 84/04/08 12:07:49 edward 15 14
c control character expansion in wwwrite()
c calling of wwupdate() in wwwrite() dependent of ww_noupdate
c control character handling macros in char.h
e
s 00001/00001/00048
d D 3.5 83/12/02 23:32:14 edward 14 13
c wwvisible never worked.
e
s 00002/00001/00047
d D 3.4 83/11/28 17:34:11 edward 13 12
c fixed sign bit problem in unctrl()
e
s 00007/00004/00041
d D 3.3 83/09/15 10:07:07 edward 12 11
c Now uses screen address for all buffers.
e
s 00016/00000/00029
d D 3.2 83/09/02 12:58:52 edward 11 10
c use wwvisible() to see if we need wwmoveup().
e
s 00000/00000/00029
d D 3.1 83/08/11 17:21:14 edward 10 8
i 9
c last few day's work
e
s 00000/00031/00029
d D 2.1.1.1 83/08/09 18:34:08 edward 9 8
c mile stone
e
s 00000/00000/00060
d D 2.1 83/07/30 13:26:58 edward 8 7
c prepare for major change
e
s 00024/00000/00036
d D 1.7 83/07/28 13:05:32 edward 7 6
c unctrl
e
s 00000/00000/00036
d D 1.6 83/07/22 17:07:46 edward 6 5
c scrolling.
c uses Wscreensize() to get screen size.
c More intelligent framing.
c etc.
e
s 00001/00001/00035
d D 1.5 83/07/20 19:30:40 edward 5 4
c Startup configuration stuff, and misc.
e
s 00000/00000/00036
d D 1.4 83/07/19 20:07:36 edward 4 3
c today's work
e
s 00012/00000/00024
d D 1.3 83/07/18 21:02:54 edward 3 2
c multiple window
e
s 00004/00003/00020
d D 1.2 83/07/17 15:42:14 edward 2 1
c 
e
s 00023/00000/00000
d D 1.1 83/07/12 17:20:56 edward 1 0
c date and time created 83/07/12 17:20:56 by edward
e
u
U
f b 
t
T
I 1
D 21
#ifndef lint
D 18
static	char *sccsid = "%W% %E%";
E 18
I 18
static char sccsid[] = "%W% %G%";
E 18
#endif

E 21
I 19
/*
D 21
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 21
I 21
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 22
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 22
I 22
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
E 22
E 21
 */
I 21

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 21

E 19
#include "ww.h"
I 17
#include "tt.h"
#include "char.h"
E 17

I 11
/*
D 12
 * Sufficient but necessary test for total visibility.
E 12
I 12
 * Sufficient but not necessary test for total visibility.
E 12
 */
wwvisible(w)
register struct ww *w;
{
	register i;
	register nvis = 0;

D 12
	for (i = 0; i < w->ww_w.nr; i++)
E 12
I 12
	for (i = w->ww_i.t; i < w->ww_i.b; i++)
E 12
		nvis += w->ww_nvis[i];
D 12
	if (w->ww_hascursor && wwsmap[wwcurrow(w)][wwcurcol(w)] == w->ww_index)
E 12
I 12
	if (w->ww_hascursor
D 14
	    && w->ww_cur.r >= w->ww_i.b && w->ww_cur.r < w->ww_i.t
E 14
I 14
	    && w->ww_cur.r >= w->ww_i.t && w->ww_cur.r < w->ww_i.b
E 14
	    && w->ww_cur.c >= w->ww_i.l && w->ww_cur.c < w->ww_i.r
	    && wwsmap[w->ww_cur.r][w->ww_cur.c] == w->ww_index)
E 12
		nvis++;
D 12
	return nvis == w->ww_w.nr * w->ww_w.nc;
E 12
I 12
	return nvis == w->ww_i.nr * w->ww_i.nc;
I 17
}

wwbell()
{
D 20
	ttputc(ctrl(g));
E 20
I 20
	ttputc(ctrl('g'));
E 20
E 17
E 12
}
D 15

E 11
D 2
struct ww *_wwcurrent = 0;
E 2
I 2
D 9
struct ww *wwhead = 0;
struct ww *curwin = 0;
E 2

D 5
wwsetcurrent(wp)
E 5
I 5
wwsetcurwin(wp)
E 5
register struct ww *wp;
{
D 2
	_wwcurrent = wp;
E 2
I 2
	curwin = wp;
I 3
	Wfront(wp->ww_win);
E 3
E 2
}

wwhaschildren()
{
	register struct ww *wp;

D 2
	for (wp = _wwhead; wp; wp = wp->ww_next)
E 2
I 2
	for (wp = wwhead; wp; wp = wp->ww_next)
E 2
		if (wp->ww_state == WW_HASPROC)
			return 1;
	return 0;
I 3
}

struct ww *
wwfind(id)
register id;
{
	register struct ww *w;

	for (w = wwhead; w && w->ww_ident != id; w = w->ww_next)
		;
	return w;
E 3
}
I 7

E 9
char *
unctrl(c)
D 13
register char c;
E 13
I 13
register c;
E 13
{
	static char buf[5];
	register char *p = buf;

I 13
	c = (unsigned)(unsigned char)c;
E 13
	if (c == DEL) {
		*p++ = '^';
		*p++ = '?';
	} else if (c < ' ') {
		*p++ = '^';
		*p++ = c + '@';
	} else if (c > DEL) {
		*p++ = '\\';
		*p++ = (c >> 6 & 3) + '0';
		*p++ = (c >> 3 & 7) + '0';
		*p++ = (c & 7) + '0';
	} else
		*p++ = c;
	*p = 0;
	return buf;
}
E 15
E 7
E 1
