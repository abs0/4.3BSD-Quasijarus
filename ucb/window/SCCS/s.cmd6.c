h38479
s 00010/00005/00081
d D 3.15 88/06/29 21:35:47 bostic 17 16
c install approved copyright notice
e
s 00013/00007/00073
d D 3.14 88/02/21 13:36:47 bostic 16 15
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00074
d D 3.13 85/04/24 16:15:11 edward 15 14
c copyright messages
e
s 00001/00001/00073
d D 3.12 84/05/23 01:58:06 edward 14 13
c new sccs id
e
s 00001/00001/00073
d D 3.11 84/04/08 19:23:17 edward 13 12
c new options to "window": shell, pty, frame
c and stuff to support them
e
s 00001/00001/00073
d D 3.10 84/04/08 12:34:41 edward 12 11
c set ww_mapnl for cmdwin
e
s 00002/00001/00072
d D 3.9 84/04/08 12:08:37 edward 11 10
c control character expansion in wwwrite()
c calling of wwupdate() in wwwrite() dependent of ww_noupdate
c control character handling macros in char.h
e
s 00004/00004/00069
d D 3.8 84/03/03 22:46:10 edward 10 9
c interrupt driven input
e
s 00003/00003/00070
d D 3.7 84/01/16 15:26:14 edward 9 8
c new io scheme
e
s 00003/00001/00070
d D 3.6 84/01/13 11:09:12 edward 8 7
c more() and waitnl() reworked.
e
s 00004/00002/00067
d D 3.5 84/01/12 12:04:29 edward 7 6
c arguments to more() changed
e
s 00027/00001/00042
d D 3.4 84/01/11 17:08:57 edward 6 5
c debug_str() added
e
s 00001/00005/00042
d D 3.3 83/11/23 16:36:05 edward 5 4
c New cover scheme
e
s 00047/00000/00000
d D 3.2 83/09/15 17:11:21 edward 4 3
c The 'M' command and rearranged debugging commands ('&')
e
s 00000/00023/00000
d D 3.1 83/08/09 18:45:32 edward 3 2
i
c 
e
s 00000/00000/00023
d D 2.1 83/07/30 13:26:16 edward 2 1
c prepare for major change
e
s 00023/00000/00000
d D 1.1 83/07/22 17:07:04 edward 1 0
c date and time created 83/07/22 17:07:04 by edward
e
u
U
f b 
t
T
I 4
D 16
#ifndef lint
D 14
static	char *sccsid = "%W% %E%";
E 14
I 14
static char sccsid[] = "%W% %G%";
E 14
#endif

E 16
I 15
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
D 17
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 17
I 17
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
E 17
E 16
 */
I 16

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 16

E 15
#include "defs.h"
I 6
#include "string.h"
I 11
#include "char.h"
E 11
E 6

/*
 * Debugging commands.
 */

c_debug()
{
	register struct ww *w;

	if (!terse)
D 5
		(void) wwputs("[m(smap), n(ns), o(os), v(nvis), w(win), c(cov)]? ", cmdwin);
E 5
I 5
D 6
		(void) wwputs("[m(smap), n(ns), o(os), v(nvis), w(win)]? ", cmdwin);
E 6
I 6
D 10
		(void) wwputs("[m(smap) n(ns) o(os) s(string) v(nvis) w(win)]? ", cmdwin);
E 10
I 10
		wwputs("[m(smap) n(ns) o(os) s(string) v(nvis) w(win)]? ", cmdwin);
E 10
E 6
E 5
	wwcurtowin(cmdwin);
D 9
	while (bpeekc() < 0)
		bread();
E 9
I 9
	while (wwpeekc() < 0)
		wwiomux();
E 9
	if (!terse)
D 10
		(void) wwputs("\r\n", cmdwin);
E 10
I 10
D 12
		wwputs("\r\n", cmdwin);
E 12
I 12
		wwputc('\n', cmdwin);
E 12
E 10
D 9
	switch (bgetc()) {
E 9
I 9
	switch (wwgetc()) {
E 9
	case 'm':
		wwdumpsmap();
		break;
	case 'n':
		wwdumpns();
		break;
	case 'o':
		wwdumpos();
		break;
I 6
	case 's':
		debug_str();
		break;
E 6
	case 'v':
		if ((w = getwin()) != 0)
			wwdumpnvis(w);
D 5
		break;
	case 'c':
		if ((w = getwin()) != 0)
			wwdumpcov(w);
E 5
		break;
	case 'w':
		if ((w = getwin()) != 0)
			wwdumpwin(w);
		break;
	default:
D 10
		wwbell();
E 10
I 10
D 11
		wwputc(CTRL(g), cmdwin);
E 11
I 11
D 13
		wwputc(ctrl(g), cmdwin);
E 13
I 13
		wwbell();
E 13
E 11
E 10
	}
}
I 6

#ifdef STR_DEBUG
debug_str()
{
	register struct ww *w;
	struct string *s;

	if ((w = openiwin(wwnrow - 3, "Allocated Strings")) == 0) {
		error("Can't open string window: %s.", wwerror());
		return;
	}
D 7
	for (s = str_head.s_forw; s != &str_head; s = s->s_forw)
		more(w, "(0x%x)\t\"%s\"\n", s->s_data, s->s_data);
E 7
I 7
	for (s = str_head.s_forw; s != &str_head; s = s->s_forw) {
D 8
		more(w);
E 8
I 8
		if (more(w, 0) == 2)
			goto out;
E 8
D 10
		(void) wwprintf(w, "(0x%x)\t\"%s\"\n", s->s_data, s->s_data);
E 10
I 10
		wwprintf(w, "(0x%x)\t\"%s\"\n", s->s_data, s->s_data);
E 10
	}
E 7
	waitnl(w);
I 8
out:
E 8
	closeiwin(w);
}
#else
debug_str()
{
	error("No string debugging.");
}
#endif
E 6
E 4
I 1
D 3
#ifndef lint
static	char *sccsid = "%W% %E%";
#endif

#include "defs.h"

struct ww *openwin();
struct ww *doopen();

doscroll(dir)
int dir;
{
	register Win *W = selwin->ww_win;
	register brow = W->w_bstart.row;

	brow += dir * selwin->ww_i.nrow / 2;
	if (brow < 0)
		brow = 0;
	else if (brow + selwin->ww_w.nrow > W->w_textbuf->b_nrows)
		brow = W->w_textbuf->b_nrows - selwin->ww_w.nrow;
	if (brow != W->w_bstart.row)
		Wrelscroll(W, brow - W->w_bstart.row, 0, 1);
}
E 3
E 1
