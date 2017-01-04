h22376
s 00010/00005/00036
d D 3.16 88/06/29 21:35:38 bostic 25 24
c install approved copyright notice
e
s 00013/00007/00028
d D 3.15 88/02/21 13:36:41 bostic 24 23
c written by Edward Wang; attach Berkeley specific copyright
e
s 00000/00031/00035
d D 3.14 87/05/18 12:20:29 edward 23 22
c added keepopen and smooth flags, added + and - window selections
e
s 00006/00000/00060
d D 3.13 85/04/24 16:13:23 edward 22 21
c copyright messages
e
s 00001/00001/00059
d D 3.12 84/05/23 01:57:06 edward 21 20
c new sccs id
e
s 00000/00037/00060
d D 3.11 84/04/07 00:02:54 edward 20 19
c c_list and c_variable removed
e
s 00004/00004/00093
d D 3.10 84/03/03 22:44:48 edward 19 18
c interrupt driven input
e
s 00004/00004/00093
d D 3.9 84/01/13 17:15:58 edward 18 17
c lint
e
s 00014/00031/00083
d D 3.8 84/01/13 11:54:39 edward 17 16
c {open,close}{i,}win() moved to win.c
e
s 00001/00001/00113
d D 3.7 84/01/11 17:05:57 edward 16 15
c closewin() should use str_free() for ww_label
e
s 00039/00000/00075
d D 3.6 83/12/06 12:52:13 edward 15 14
c 'v' command
e
s 00011/00005/00064
d D 3.5 83/11/30 11:55:32 edward 14 13
c lastselwin, and restructured some code
e
s 00003/00005/00066
d D 3.4 83/11/22 19:51:15 edward 13 12
c use str_cpy for label
e
s 00001/00001/00070
d D 3.3 83/08/22 14:41:57 edward 12 11
c close all special case added to l_close()
e
s 00001/00001/00070
d D 3.2 83/08/15 17:01:16 edward 11 10
c bug in c_close()
e
s 00000/00000/00071
d D 3.1 83/08/11 17:22:06 edward 10 8
i 9
c last few day's work
e
s 00024/00058/00047
d D 2.1.1.1 83/08/09 18:35:25 edward 9 8
c mile stone
e
s 00000/00000/00105
d D 2.1 83/07/30 13:26:03 edward 8 7
c prepare for major change
e
s 00002/00000/00103
d D 1.7 83/07/28 18:41:39 edward 7 6
c warning message gone
e
s 00004/00000/00099
d D 1.6 83/07/28 18:32:15 edward 6 5
c terse mode and some new commands.
c also, the : business.
e
s 00044/00024/00055
d D 1.5 83/07/28 16:01:03 edward 5 4
c user label, and new doclose()
e
s 00025/00000/00054
d D 1.4 83/07/28 13:10:29 edward 4 3
c changable escape character.
e
s 00016/00011/00038
d D 1.3 83/07/22 17:09:57 edward 3 2
c scrolling.
c uses Wscreensize() to get screen size.
c More intelligent framing.
c etc.
e
s 00006/00001/00043
d D 1.2 83/07/19 20:08:02 edward 2 1
c today's work
e
s 00044/00000/00000
d D 1.1 83/07/18 21:05:14 edward 1 0
c date and time created 83/07/18 21:05:14 by edward
e
u
U
f b 
t
T
I 1
D 24
#ifndef lint
D 21
static	char *sccsid = "%W% %E%";
E 21
I 21
static char sccsid[] = "%W% %G%";
E 21
#endif

E 24
I 22
/*
D 24
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 24
I 24
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 25
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 25
I 25
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
E 25
E 24
 */
I 24

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 24

E 22
#include "defs.h"
I 15
D 20
#include "value.h"
#include "var.h"
E 20
E 15
I 13
#include "string.h"
I 15
D 20

D 17
#define VLINE (wwnrow - 3)
static vlineno;
static struct ww *vw;

E 17
c_variable()
{
I 17
	register struct ww *w;
E 17
	int printvar();

D 17
	if ((vw = openiwin(VLINE, "Variables")) == 0) {
E 17
I 17
	if ((w = openiwin(wwnrow - 3, "Variables")) == 0) {
E 17
		error("Can't open variable window: %s.", wwerror());
		return;
	}
D 17
	vlineno = 0;
	var_walk(printvar);
	waitnl(vw);
	closeiwin(vw);
E 17
I 17
	if (var_walk(printvar, (int)w) >= 0)
		waitnl(w);
	closeiwin(w);
E 17
}

D 17
printvar(r)
E 17
I 17
printvar(w, r)
register struct ww *w;
E 17
register struct var *r;
{
D 17
	if (vlineno >= VLINE - 2)
		waitnl(vw);
	wwprintf(vw, "%16s\t", r->r_name);
E 17
I 17
	if (more(w, 0) == 2)
		return -1;
D 18
	wwprintf(w, "%16s\t", r->r_name);
E 18
I 18
D 19
	(void) wwprintf(w, "%16s\t", r->r_name);
E 19
I 19
	wwprintf(w, "%16s\t", r->r_name);
E 19
E 18
E 17
	switch (r->r_val.v_type) {
	case V_STR:
D 17
		wwprintf(vw, "%s\n", r->r_val.v_str);
E 17
I 17
D 18
		wwprintf(w, "%s\n", r->r_val.v_str);
E 18
I 18
D 19
		(void) wwprintf(w, "%s\n", r->r_val.v_str);
E 19
I 19
		wwprintf(w, "%s\n", r->r_val.v_str);
E 19
E 18
E 17
		break;
	case V_NUM:
D 17
		wwprintf(vw, "%d\n", r->r_val.v_num);
E 17
I 17
D 18
		wwprintf(w, "%d\n", r->r_val.v_num);
E 18
I 18
D 19
		(void) wwprintf(w, "%d\n", r->r_val.v_num);
E 19
I 19
		wwprintf(w, "%d\n", r->r_val.v_num);
E 19
E 18
E 17
		break;
	case V_ERR:
D 17
		wwprintf(vw, "ERR\n");
E 17
I 17
D 18
		wwprintf(w, "ERROR\n");
E 18
I 18
D 19
		(void) wwprintf(w, "ERROR\n");
E 19
I 19
		wwprintf(w, "ERROR\n");
E 19
E 18
E 17
		break;
	}
I 17
	return 0;
E 17
}
E 20
E 15
E 13

D 9
struct ww *getwin();
struct ww *openwin();
char *strtime();

D 3
doclose(c)
E 3
I 3
D 5
doclose(flag, w)
E 5
I 5
doclose(w)
E 9
I 9
D 23
c_close(w)
E 9
E 5
register struct ww *w;
E 3
{
D 3
	register struct ww *w;
E 3
I 3
	char didit = 0;
I 5
D 9
	struct ww *w1;
E 9
I 9
	register i;
E 9
E 5
E 3

D 3
	switch (c) {
	case 'c':
		if ((w = getwin()) == 0)
E 3
I 3
D 5
	switch (flag) {
	case CLOSE_ONE:
		if (w == 0)
E 3
			break;
E 5
I 5
	if (w != 0) {
E 5
D 9
		if (w == selwin)
			setselwin(0);
		wwclose(w);
E 9
I 9
		closewin(w);
E 9
I 3
		didit++;
E 3
D 5
		break;
D 3
	case 'C':
	case 'Z':
E 3
I 3
	case CLOSE_DEAD:
	case CLOSE_ALL:
E 5
I 5
	} else {
E 5
E 3
D 9
		for (w = wwhead; w;) {
D 5
			if (w != cmdwin
D 3
			    && (w->ww_state == WW_DEAD || c == 'Z')) {
E 3
I 3
			    && (w->ww_state == WW_DEAD || flag == CLOSE_ALL)) {
E 3
				struct ww *w1;
				w = (w1 = w)->ww_next;
				if (w1 == selwin)
					setselwin(0);
D 2
				wwclose(w1);
E 2
I 2
				if (w->ww_state == WW_HASPROC && w->ww_pid == 0)
				{
					wwprintf(cmdwin, "%d: pid == 0.  ",
						w->ww_ident);
D 3
				} else
E 3
I 3
				} else {
E 3
					wwclose(w1);
I 3
					didit++;
				}
E 3
E 2
			} else
E 5
I 5
			if (w == cmdwin) {
E 5
				w = w->ww_next;
E 9
I 9
		for (i = 0; i < NWINDOW; i++) {
			if ((w = window[i]) == 0)
E 9
I 5
				continue;
D 9
			}
			w = (w1 = w)->ww_next;
			if (w1 == selwin)
				setselwin(0);
			if (w->ww_state == WW_HASPROC && w->ww_pid == 0) {
				wwprintf(cmdwin, "%d: pid == 0.  ",
					w->ww_ident);
			} else {
				wwclose(w1);
				didit++;
			}
E 9
I 9
D 12
			closewin(w);		/* GROT */
E 12
I 12
			closewin(w);
E 12
			didit++;
E 9
E 5
		}
D 5
		break;
E 5
	}
	if (selwin == 0) {
D 3
		for (w = wwhead; w && w == cmdwin;
		     w = w->ww_next)
E 3
I 3
D 9
		for (w = wwhead; w && w == cmdwin; w = w->ww_next)
E 9
I 9
D 11
		for (i = 0; i < NWINDOW && window[i] != 0; i++)
E 11
I 11
D 14
		for (i = 0; i < NWINDOW && window[i] == 0; i++)
E 11
E 9
E 3
			;
D 9
		setselwin(w);
E 9
I 9
		if (i < NWINDOW)
			setselwin(window[i]);
E 14
I 14
		if (lastselwin != 0)
			setselwin(lastselwin);
		else {
			for (i = 0; i < NWINDOW && window[i] == 0; i++)
				;
			if (i < NWINDOW)
				setselwin(window[i]);
		}
E 14
E 9
	}
I 3
	if (didit)
		reframe();
E 3
D 17
}
I 4

I 6
D 9
/*
E 6
doescape()
E 9
I 9
closewin(w)
register struct ww *w;
E 9
{
D 9
	char buf[2];

	wwputs("New escape character? ", cmdwin);
	wwsetcursor(WCurRow(cmdwin->ww_win), WCurCol(cmdwin->ww_win));
	while ((*buf = bgetc()) < 0)
		bread();
	buf[1] = 0;
	setescape(buf);
	wwputs("\r\n", cmdwin);
E 9
I 9
	if (w == selwin)
D 14
		setselwin((struct ww *)0);
E 14
I 14
		selwin = 0;
	if (w == lastselwin)
		lastselwin = 0;
E 14
	if (w->ww_id >= 0 && w->ww_id < NWINDOW)
		window[w->ww_id] = 0;
	if (w->ww_label)
D 16
		free(w->ww_label);
E 16
I 16
		str_free(w->ww_label);
E 16
	wwdelete(w);
	wwclose(w);
E 17
E 9
}
I 6
D 9
*/
E 9
E 6

E 23
setescape(esc)
register char *esc;
{
	if (*esc == '^') {
		if (esc[1] != 0)
			escapec = esc[1] & 0x1f;
		else
			escapec = '^';
	} else
		escapec = *esc;
I 5
}

I 6
D 9
/*
E 6
dolabel()
{
	register struct ww *w;
	char buf[30];
	char *malloc();

	if ((w = getwin()) == 0)
		return;
	wwprintf(cmdwin, "Label for window %d? ", w->ww_ident);
	bgets(buf, sizeof buf, cmdwin);
	setlabel(w, buf);
	wwputs("\r\n", cmdwin);
}
I 6
*/
E 6

E 9
setlabel(w, label)
register struct ww *w;
char *label;
{
I 7
D 13
	char *malloc();

E 13
E 7
	if (w->ww_label != 0)
D 13
		free(w->ww_label);
D 9
	w->ww_label = malloc(strlen(label) + 1);
	strcpy(w->ww_label, label);
	wwunframe(w);		/* cover up the old label */
	wwframe(w);
	labelwin(w);
E 9
I 9
	if ((w->ww_label = malloc((unsigned)strlen(label) + 1)) == 0)
E 13
I 13
		str_free(w->ww_label);
	if ((w->ww_label = str_cpy(label)) == 0)
E 13
		return -1;
D 13
	(void) strcpy(w->ww_label, label);
E 13
	return 0;
E 9
E 5
}
E 4
E 1
