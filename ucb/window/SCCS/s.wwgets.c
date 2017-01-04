h63372
s 00010/00005/00062
d D 3.12 88/06/29 21:38:11 bostic 20 19
c install approved copyright notice
e
s 00013/00007/00054
d D 3.11 88/02/21 13:38:25 bostic 19 18
c written by Edward Wang; attach Berkeley specific copyright
e
s 00001/00001/00060
d D 3.10 88/01/03 00:56:12 bostic 18 17
c fix ctrl macro for ANSI C
e
s 00006/00000/00055
d D 3.9 85/04/24 16:12:52 edward 17 16
c copyright messages
e
s 00001/00001/00054
d D 3.8 84/05/23 01:56:53 edward 16 15
c new sccs id
e
s 00001/00001/00054
d D 3.7 84/04/09 23:29:24 edward 15 14
c lint
e
s 00003/00002/00052
d D 3.6 84/04/08 19:22:54 edward 14 13
c new options to "window": shell, pty, frame
c and stuff to support them
e
s 00004/00003/00050
d D 3.5 84/04/08 12:08:16 edward 13 12
c control character expansion in wwwrite()
c calling of wwupdate() in wwwrite() dependent of ww_noupdate
c control character handling macros in char.h
e
s 00004/00004/00049
d D 3.4 84/03/03 22:43:49 edward 12 11
c interrupt driven input
e
s 00005/00037/00048
d D 3.3 84/01/16 15:25:46 edward 11 10
c new io scheme
e
s 00002/00003/00083
d D 3.2 83/08/26 17:19:43 edward 10 9
c bug with wwforce hanging
e
s 00000/00000/00086
d D 3.1 83/08/11 17:22:11 edward 9 7
i 8
c last few day's work
e
s 00006/00005/00080
d D 2.1.1.1 83/08/09 18:35:30 edward 8 7
c mile stone
e
s 00000/00000/00085
d D 2.1 83/07/30 13:26:22 edward 7 6
c prepare for major change
e
s 00028/00018/00057
d D 1.6 83/07/28 15:51:37 edward 6 5
c didn't work, but does now.
e
s 00037/00000/00038
d D 1.5 83/07/28 13:09:41 edward 5 4
c bgets()
e
s 00007/00001/00031
d D 1.4 83/07/27 14:33:41 edward 4 3
c io statistics
e
s 00000/00000/00032
d D 1.3 83/07/22 17:10:07 edward 3 2
c scrolling.
c uses Wscreensize() to get screen size.
c More intelligent framing.
c etc.
e
s 00018/00009/00014
d D 1.2 83/07/19 20:08:06 edward 2 1
c today's work
e
s 00023/00000/00000
d D 1.1 83/07/18 21:05:15 edward 1 0
c date and time created 83/07/18 21:05:15 by edward
e
u
U
f b 
t
T
I 1
D 19
#ifndef lint
D 16
static	char *sccsid = "%W% %E%";
E 16
I 16
static char sccsid[] = "%W% %G%";
E 16
#endif

E 19
I 17
/*
D 19
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 19
I 19
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
E 19
 */
I 19

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 19

E 17
D 11
#include "defs.h"
E 11
I 11
#include "ww.h"
I 13
#include "char.h"
E 13
E 11

D 11
char *ibufp = ibuf;

bread()
{
	register n;
I 2
	register char *p;
E 2
	int imask;

D 2
	imask = 1 << 0;
	wwforce(&imask);
	if ((imask & 1<<0) == 0)
		return;
	if (ibufc == 0)
		ibufp = ibuf;
	n = read(0, ibufp + ibufc, ibuf + sizeof ibuf - ibufp - ibufc);
	if (n > 0)
		ibufc += n;
E 2
I 2
	while (ibufc == 0) {
I 8
		wwupdate();
E 8
		wwflush();
D 10
		imask = 1 << 0;
		while (wwforce(&imask) < 0)
E 10
I 10
		while (imask = 1, wwforce(&imask) < 0)
E 10
			;
D 10
		if ((imask & 1 << 0) == 0)
E 10
I 10
		if ((imask & 1) == 0)
E 10
			continue;
		if (ibufc == 0) {
			p = ibufp = ibuf;
			n = sizeof ibuf;
		} else {
			p = ibufp + ibufc;
			n = (ibuf + sizeof ibuf) - p;
		}
D 4
		if ((n = read(0, p, n)) > 0)
E 4
I 4
		if ((n = read(0, p, n)) > 0) {
E 4
			ibufc += n;
I 4
			nreadc += n;
		} else if (n == 0)
			nreadz++;
		else
			nreade++;
		nread++;
E 4
	}
E 2
}
I 5

bgets(buf, n, w)
E 11
I 11
wwgets(buf, n, w)
E 11
char *buf;
int n;
register struct ww *w;
{
	register char *p = buf;
	register char c;
I 14
	char uc = w->ww_unctrl;
E 14

I 14
	w->ww_unctrl = 0;
E 14
	for (;;) {
D 8
		wwsetcursor(WCurRow(w->ww_win), WCurCol(w->ww_win));
E 8
I 8
		wwcurtowin(w);
E 8
D 6
		while ((c = bpeekc()) < 0)
E 6
I 6
D 11
		while ((c = bgetc()) < 0)
E 6
			bread();
E 11
I 11
		while ((c = wwgetc()) < 0)
			wwiomux();
E 11
D 6
		switch (c) {
		case '\b':
			if (p > buf) {
				wwputs("\b \b", w);
				p--;
				if (ISCTRL(*p))
					wwputs("\b \b", w);
			} else
E 6
I 6
		if (c == wwoldtty.ww_sgttyb.sg_erase) {
			if (p > buf)
				rub(*--p, w);
D 14
			else
E 6
D 8
				Ding();
E 8
I 8
D 12
				wwbell();
E 12
I 12
D 13
				wwputc(CTRL(g), w);
E 13
I 13
				wwputc(ctrl(g), w);
E 14
E 13
E 12
E 8
I 6
		} else if (c == wwoldtty.ww_sgttyb.sg_kill) {
			while (p > buf)
				rub(*--p, w);
		} else if (c == wwoldtty.ww_ltchars.t_werasc) {
			while (--p >= buf && (*p == ' ' || *p == '\t'))
				rub(*p, w);
			while (p >= buf && *p != ' ' && *p != '\t')
				rub(*p--, w);
			p++;
		} else if (c == '\r' || c == '\n') {
E 6
			break;
D 6
		case '\r':
		case '\n':
			*p = 0;
			return;
		default:
E 6
I 6
		} else {
E 6
			if (p >= buf + n - 1)
D 8
				Ding();
E 8
I 8
D 12
				wwbell();
E 12
I 12
D 13
				wwputc(CTRL(g), w);
E 13
I 13
D 18
				wwputc(ctrl(g), w);
E 18
I 18
				wwputc(ctrl('g'), w);
E 18
E 13
E 12
E 8
D 6
			else {
				*p++ = c;
				wwputs(unctrl(*p), w);
			}
E 6
I 6
			else
D 8
				wwputs(unctrl(*p++ = c), w);
E 8
I 8
D 12
				(void) wwputs(unctrl(*p++ = c), w);
E 12
I 12
				wwputs(unctrl(*p++ = c), w);
E 12
E 8
E 6
		}
	}
I 6
	*p = 0;
I 14
	w->ww_unctrl = uc;
E 14
}

I 11
static
E 11
rub(c, w)
struct ww *w;
{
	register i;

	for (i = strlen(unctrl(c)); --i >= 0;)
D 8
		wwputs("\b \b", w);
E 8
I 8
D 12
		(void) wwputs("\b \b", w);
E 12
I 12
D 13
		wwputs("\b \b", w);
E 13
I 13
D 15
		wwwrite(w, "\b \b", 3);
E 15
I 15
		(void) wwwrite(w, "\b \b", 3);
E 15
E 13
E 12
E 8
E 6
}
E 5
E 1
