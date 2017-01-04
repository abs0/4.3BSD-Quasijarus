h49681
s 00010/00005/00027
d D 3.16 88/06/29 21:35:41 bostic 23 22
c install approved copyright notice
e
s 00013/00007/00019
d D 3.15 88/02/21 13:36:43 bostic 22 21
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00020
d D 3.14 85/04/24 16:14:15 edward 21 20
c copyright messages
e
s 00001/00001/00019
d D 3.13 84/05/23 01:57:20 edward 20 19
c new sccs id
e
s 00001/00001/00019
d D 3.12 84/05/06 17:53:30 edward 19 18
c alias macros
e
s 00001/00001/00019
d D 3.11 84/04/08 12:34:34 edward 18 17
c set ww_mapnl for cmdwin
e
s 00000/00051/00020
d D 3.10 84/04/05 17:33:10 edward 17 16
c "s," "t," and "T" moved to long commands (iostat, time).
c "S" removed.
e
s 00004/00006/00067
d D 3.9 84/04/05 00:32:01 edward 16 15
c -c flag, incmd, setcmd(), setterse() added
e
s 00005/00005/00068
d D 3.8 84/03/03 22:45:02 edward 15 14
c interrupt driven input
e
s 00003/00003/00070
d D 3.7 84/01/16 15:26:01 edward 14 13
c new io scheme
e
s 00001/00001/00072
d D 3.6 83/12/02 23:38:27 edward 13 12
c front() must reframe() when called from setselwin()
e
s 00001/00003/00072
d D 3.5 83/11/30 11:55:36 edward 12 11
c lastselwin, and restructured some code
e
s 00002/00001/00073
d D 3.4 83/11/22 19:51:59 edward 11 10
c check error from dolongcmd
e
s 00001/00001/00073
d D 3.3 83/08/22 14:04:51 edward 10 9
c wrong cursor position in c_show
e
s 00002/00000/00072
d D 3.2 83/08/18 18:33:42 edward 9 8
c move the cursor in c_colon
e
s 00000/00000/00072
d D 3.1 83/08/11 17:22:43 edward 8 6
i 7
c last few day's work
e
s 00028/00027/00044
d D 2.1.1.1 83/08/09 18:35:52 edward 7 6
c mile stone
e
s 00000/00000/00071
d D 2.1 83/07/30 13:26:07 edward 6 5
c prepare for major change
e
s 00003/00001/00068
d D 1.5 83/07/28 18:37:04 edward 5 4
c terse fix
e
s 00025/00006/00044
d D 1.4 83/07/28 18:32:21 edward 4 3
c terse mode and some new commands.
c also, the : business.
e
s 00001/00001/00049
d D 1.3 83/07/22 17:11:09 edward 3 2
c scrolling.
c uses Wscreensize() to get screen size.
c More intelligent framing.
c etc.
e
s 00005/00004/00045
d D 1.2 83/07/20 19:31:21 edward 2 1
c Startup configuration stuff, and misc.
e
s 00049/00000/00000
d D 1.1 83/07/19 20:08:56 edward 1 0
c date and time created 83/07/19 20:08:56 by edward
e
u
U
f b 
t
T
I 1
D 22
#ifndef lint
D 20
static	char *sccsid = "%W% %E%";
E 20
I 20
static char sccsid[] = "%W% %G%";
E 20
#endif

E 22
I 21
/*
D 22
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 22
I 22
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 23
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 23
I 23
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
E 23
E 22
 */
I 22

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 22

E 21
#include "defs.h"

D 7
struct ww *getwin();
struct ww *openwin();
char *strtime();

D 4
doquery()
E 4
I 4
doshow()
E 7
I 7
D 17
c_show()
E 7
E 4
{
	register i;
	register struct ww *w = 0;
	char done_it = 0;

D 7
	for (i = 1; i < 10; i++) {
		if ((w = wwfind(i)) == 0)
E 7
I 7
	for (i = 0; i < NWINDOW; i++) {
		if ((w = window[i]) == 0)
E 7
			continue;
		done_it++;
D 2
		wwsetcurrent(w);
E 2
I 2
D 7
		wwsetcurwin(w);
E 2
D 3
		wwsetcursor(w->ww_row, w->ww_col + 1);
E 3
I 3
		wwsetcursor(w->ww_o.row, w->ww_o.col + 1);
E 7
I 7
		if (!terse && cmdwin->ww_order < framewin->ww_order) {
			wwdelete(cmdwin);
			wwadd(cmdwin, framewin);
		}
D 12
		wwdelete(w);
		wwadd(w, framewin);
		reframe();
E 12
I 12
D 13
		front(w);
E 13
I 13
		front(w, 0);
E 13
E 12
D 10
		wwsetcursor(w->ww_w.t - 1, w->ww_w.l + 2);
E 10
I 10
		wwsetcursor(w->ww_w.t - 1, w->ww_w.l + 1);
E 10
E 7
E 3
		for (;;) {
D 14
			switch (bgetc()) {
E 14
I 14
			switch (wwgetc()) {
E 14
			case '\r':
			case '\n':
				break;
			case CTRL([):
				setselwin(w);
D 2
				return;
E 2
I 2
				goto out;
E 2
			case -1:
D 14
				bread();
E 14
I 14
				wwiomux();
E 14
				continue;
			default:
D 4
				wwputs("\rType return to continue, escape to select.", cmdwin);
E 4
I 4
D 7
				if (terse)
					Ding();
				else
					wwputs("\rType return to continue, escape to select.", cmdwin);
E 4
D 2
				wwsetcurrent(cmdwin);
E 2
I 2
				wwsetcurwin(cmdwin);
E 2
				Ding();
E 7
I 7
D 15
				wwbell();
E 15
I 15
				wwputc(CTRL(g), cmdwin);
E 15
				if (!terse) {
D 15
					(void) wwputs("\rType return to continue, escape to select.", cmdwin);
E 15
I 15
					wwputs("\rType return to continue, escape to select.", cmdwin);
E 15
					wwdelete(cmdwin);
					wwadd(cmdwin, &wwhead);
				}
E 7
				continue;
			}
			break;
		}
	}
I 2
out:
E 2
D 4
	if (!done_it)
		wwputs("No windows.  ", cmdwin);
	else {
E 4
I 4
	if (!done_it) {
D 5
		if (!terse)
E 5
I 5
D 7
		if (terse)
			Ding();
		else
E 5
			wwputs("No windows.  ", cmdwin);
E 7
I 7
		error("No windows.");
E 7
	} else {
E 4
D 2
		wwsetcurrent(cmdwin);
E 2
I 2
D 7
		wwsetcurwin(cmdwin);
E 2
D 4
		wwputs("\r\n", cmdwin);
E 4
I 4
		if (!terse)
			wwputs("\r\n", cmdwin);
E 7
I 7
		if (!terse) {
			wwdelete(cmdwin);
			wwadd(cmdwin, &wwhead);
D 15
			(void) wwputs("\r\n", cmdwin);
E 15
I 15
			wwputs("\r\n", cmdwin);
E 15
		}
E 7
E 4
	}
I 4
}

E 17
D 7
docolon()
E 7
I 7
c_colon()
E 7
{
I 16
	char oldterse = terse;
E 16
	char buf[512];

D 16
	if (terse)
D 7
		Wunhide(cmdwin->ww_win);
	wwputc(':', cmdwin);
E 7
I 7
		wwadd(cmdwin, &wwhead);
E 16
I 16
	setterse(0);
E 16
D 15
	(void) wwputc(':', cmdwin);
E 15
I 15
	wwputc(':', cmdwin);
E 15
E 7
D 14
	bgets(buf, wwncol - 3, cmdwin);
E 14
I 14
	wwgets(buf, wwncol - 3, cmdwin);
E 14
D 7
	wwputs("\r\n", cmdwin);
E 7
I 7
D 15
	(void) wwputs("\r\n", cmdwin);
E 15
I 15
D 18
	wwputs("\r\n", cmdwin);
E 18
I 18
	wwputc('\n', cmdwin);
E 18
E 15
E 7
D 16
	if (terse)
D 7
		Whide(cmdwin->ww_win);
E 7
I 7
		wwdelete(cmdwin);
I 9
	else
		wwcurtowin(cmdwin);
E 16
I 16
	wwcurtowin(cmdwin);
	setterse(oldterse);
E 16
E 9
E 7
D 11
	dolongcmd(buf);
E 11
I 11
D 19
	if (dolongcmd(buf) < 0)
E 19
I 19
	if (dolongcmd(buf, (struct value *)0, 0) < 0)
E 19
		error("Out of memory.");
E 11
E 4
}
E 1
