h24881
s 00010/00005/00342
d D 3.20 88/06/29 21:37:08 bostic 21 20
c install approved copyright notice
e
s 00013/00007/00334
d D 3.19 88/02/21 13:37:52 bostic 20 19
c written by Edward Wang; attach Berkeley specific copyright
e
s 00001/00001/00340
d D 3.18 88/01/03 00:56:10 bostic 19 18
c fix ctrl macro for ANSI C
e
s 00057/00014/00284
d D 3.17 87/05/18 12:20:35 edward 18 17
c added keepopen and smooth flags, added + and - window selections
e
s 00002/00002/00296
d D 3.16 86/08/05 01:24:58 edward 17 16
c lint
e
s 00001/00001/00297
d D 3.15 86/08/04 14:18:39 edward 16 15
c display mode escape sequences changed
e
s 00006/00000/00292
d D 3.14 85/04/24 16:22:49 edward 15 14
c copyright messages
e
s 00016/00002/00276
d D 3.13 85/04/03 22:20:47 edward 14 13
c lint, and others
e
s 00016/00000/00262
d D 3.12 85/03/13 20:01:13 edward 13 12
c handle ^S and ^Q (the commands) better
e
s 00001/00002/00261
d D 3.11 85/03/01 17:40:31 edward 12 10
c changing window size and new WINSZ ioctl
e
s 00001/00002/00261
d R 3.11 85/03/01 17:35:49 edward 11 10
c ww_altpos now called ww_alt (with size)
e
s 00000/00002/00263
d D 3.10 84/06/05 17:08:34 edward 10 9
c mapnl option to window
e
s 00001/00001/00264
d D 3.9 84/05/23 02:00:51 edward 9 8
c new sccs id
e
s 00011/00006/00254
d D 3.8 84/04/08 19:23:43 edward 8 7
c new options to "window": shell, pty, frame
c and stuff to support them
e
s 00011/00001/00249
d D 3.7 84/04/08 12:08:45 edward 7 6
c control character expansion in wwwrite()
c calling of wwupdate() in wwwrite() dependent of ww_noupdate
c control character handling macros in char.h
e
s 00010/00003/00240
d D 3.6 84/04/07 15:27:52 edward 6 5
c fixed moving foreground windows back to normal bug
e
s 00019/00060/00224
d D 3.5 84/04/05 00:56:55 edward 5 4
c no more background windows.
e
s 00142/00004/00142
d D 3.4 84/03/29 00:03:14 edward 4 3
c foreground and background windows
e
s 00007/00005/00139
d D 3.3 84/03/03 22:47:55 edward 3 2
c interrupt driven input
e
s 00003/00003/00141
d D 3.2 84/01/16 15:26:32 edward 2 1
c new io scheme
e
s 00144/00000/00000
d D 3.1 84/01/13 11:54:01 edward 1 0
c date and time created 84/01/13 11:54:01 by edward
e
u
U
t
T
I 1
D 20
#ifndef lint
D 9
static	char *sccsid = "%W% %E%";
E 9
I 9
static char sccsid[] = "%W% %G%";
E 9
#endif

E 20
I 15
/*
D 20
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 20
I 20
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 21
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 21
I 21
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
E 21
E 20
 */
I 20

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 20

E 15
#include "defs.h"
I 7
#include "char.h"
E 7

/*
D 4
 * Routines for opening and closing windows
E 4
I 4
 * Higher level routines for dealing with windows.
 *
 * There are two types of windows: user window, and information window.
 * User windows are the ones with a pty and shell.  Information windows
 * are for displaying error messages, and other information.
 *
D 5
 * The windows are stacked in overlapping order and divided into
 * three groups: foreground, normal, and background.  Information
 * windows are always foreground.  User windows can be anywhere.
 * Addwin() adds a window to one of the three groups.
E 5
I 5
 * The windows are doubly linked in overlapping order and divided into
 * two groups: foreground and normal.  Information
 * windows are always foreground.  User windows can be either.
 * Addwin() adds a window to the list at the top of one of the two groups.
E 5
 * Deletewin() deletes a window.  Front() moves a window to the front
D 5
 * of its group.  Wwadd() and wwdelete() should never be called
E 5
I 5
 * of its group.  Wwopen(), wwadd(), and wwdelete() should never be called
E 5
 * directly.
E 4
 */

/*
 * Open a user window.
 */
struct ww *
D 8
openwin(id, row, col, nrow, ncol, nline, label)
E 8
I 8
openwin(id, row, col, nrow, ncol, nline, label, haspty, hasframe, shf, sh)
E 8
char *label;
I 8
char haspty, hasframe;
char *shf, **sh;
E 8
{
	register struct ww *w;

	if (id < 0 && (id = findid()) < 0)
		return 0;
	if (row + nrow <= 0 || row > wwnrow - 1
	    || col + ncol <= 0 || col > wwncol - 1) {
		error("Illegal window position.");
		return 0;
	}
D 8
	if ((w = wwopen(WWO_PTY, nrow, ncol, row, col, nline)) == 0) {
		error("%s.", wwerror());
E 8
I 8
	w = wwopen(haspty ? WWO_PTY : WWO_SOCKET, nrow, ncol, row, col, nline);
	if (w == 0) {
		error("Can't open window: %s.", wwerror());
E 8
		return 0;
	}
	w->ww_id = id;
	window[id] = w;
D 8
	w->ww_hasframe = 1;
E 8
I 8
	w->ww_hasframe = hasframe;
E 8
D 12
	w->ww_altpos.r = 1;
	w->ww_altpos.c = 0;
E 12
I 12
	w->ww_alt = w->ww_w;
E 12
I 8
D 10
	if (!haspty)
		w->ww_mapnl = 1;
E 10
E 8
	if (label != 0 && setlabel(w, label) < 0)
		error("No memory for label.");
	wwcursor(w, 1);
I 6
	/*
	 * We have to do this little maneuver to make sure
	 * addwin() puts w at the top, so we don't waste an
	 * insert and delete operation.
	 */
	setselwin((struct ww *)0);
E 6
D 4
	wwadd(w, framewin);
E 4
I 4
D 5
	addwin(w, 1);
E 5
I 5
	addwin(w, 0);
E 5
E 4
D 6
	selwin = w;
	reframe();
E 6
I 6
	setselwin(w);
E 6
	wwupdate();
	wwflush();
D 8
	if (wwspawn(w, shell, shellname, (char *)0) < 0) {
E 8
I 8
	if (wwspawn(w, shf, sh) < 0) {
		error("Can't execute %s: %s.", shf, wwerror());
E 8
D 18
		c_close(w);
E 18
I 18
		closewin(w);
E 18
D 8
		error("%s: %s.", shell, wwerror());
E 8
		return 0;
	}
	return w;
}

findid()
{
	register i;

	for (i = 0; i < NWINDOW && window[i] != 0; i++)
		;
	if (i >= NWINDOW) {
		error("Too many windows.");
		return -1;
	}
	return i;
}

I 18
struct ww *
findselwin()
{
	register struct ww *w, *s = 0;
	register i;

	for (i = 0; i < NWINDOW; i++)
		if ((w = window[i]) != 0 && w != selwin &&
		    (s == 0 ||
		     !isfg(w) && (w->ww_order < s->ww_order || isfg(s))))
			s = w;
	return s;
}

E 18
/*
D 18
 * Close a user window.
I 4
 * May leave selwin == 0.
E 18
I 18
 * Close a user window.  Close all if w == 0.
E 18
E 4
 */
closewin(w)
register struct ww *w;
{
D 18
	if (w == selwin)
		selwin = 0;
	if (w == lastselwin)
		lastselwin = 0;
	if (w->ww_id >= 0 && w->ww_id < NWINDOW)
		window[w->ww_id] = 0;
	if (w->ww_label)
		str_free(w->ww_label);
D 4
	wwdelete(w);
E 4
I 4
	deletewin(w);
E 4
	wwclose(w);
E 18
I 18
	char didit = 0;
	register i;

	if (w != 0) {
		closewin1(w);
		didit++;
	} else
		for (i = 0; i < NWINDOW; i++) {
			if ((w = window[i]) == 0)
				continue;
			closewin1(w);
			didit++;
		}
	if (didit) {
		if (selwin == 0)
			if (lastselwin != 0) {
				setselwin(lastselwin);
				lastselwin = 0;
			} else if (w = findselwin())
				setselwin(w);
		if (lastselwin == 0 && selwin)
			if (w = findselwin())
				lastselwin = w;
		reframe();
	}
E 18
}

/*
 * Open an information (display) window.
 */
struct ww *
openiwin(nrow, label)
char *label;
{
	register struct ww *w;

	if ((w = wwopen(0, nrow, wwncol, 2, 0, 0)) == 0)
		return 0;
	w->ww_mapnl = 1;
	w->ww_hasframe = 1;
I 3
	w->ww_nointr = 1;
I 7
	w->ww_noupdate = 1;
	w->ww_unctrl = 1;
E 7
E 3
	w->ww_id = -1;
	w->ww_center = 1;
	(void) setlabel(w, label);
D 4
	wwadd(w, framewin);
E 4
I 4
D 5
	addwin(w, 0);
E 5
I 5
	addwin(w, 1);
E 5
E 4
	reframe();
I 3
	wwupdate();
E 3
	return w;
}

/*
 * Close an information window.
 */
closeiwin(w)
struct ww *w;
{
D 18
	closewin(w);
E 18
I 18
	closewin1(w);
E 18
	reframe();
I 18
}

closewin1(w)
register struct ww *w;
{
	if (w == selwin)
		selwin = 0;
	if (w == lastselwin)
		lastselwin = 0;
	if (w->ww_id >= 0 && w->ww_id < NWINDOW)
		window[w->ww_id] = 0;
	if (w->ww_label)
		str_free(w->ww_label);
	deletewin(w);
	wwclose(w);
E 18
I 4
}

/*
D 5
 * Set the current window.
 */
setselwin(w)
struct ww *w;
{
	if (selwin == w)
		return;
	lastselwin = selwin;
	front(selwin = w, 1);
}

/*
E 5
 * Move the window to the top of its group.
D 5
 * Don't do it, if already fully visible.
E 5
I 5
 * Don't do it if already fully visible.
E 5
 * Wwvisible() doesn't work for tinted windows.
 * But anything to make it faster.
 * Always reframe() if doreframe is true.
 */
front(w, doreframe)
register struct ww *w;
char doreframe;
{
D 5
	if (isfg(w)) {
		if (w->ww_back != framewin && !wwvisible(w)) {
			deletewin(w);
			addwin(w, 0);
			doreframe = 1;
		}
	} else if (isbg(w)) {
		if (w != bgwin && !wwvisible(w)) {
			deletewin(w);
			addwin(w, 3);
			doreframe = 1;
		}
	} else {
		if (w->ww_back != fgwin && !wwvisible(w)) {
			deletewin(w);
			addwin(w, 1);
			doreframe = 1;
		}
E 5
I 5
	if (w->ww_back != (isfg(w) ? framewin : fgwin) && !wwvisible(w)) {
		deletewin(w);
		addwin(w, isfg(w));
		doreframe = 1;
E 5
	}
	if (doreframe)
		reframe();
}

/*
D 5
 * Add a window at one of four places.
E 5
I 5
 * Add a window at the top of normal windows or foreground windows.
I 6
 * For normal windows, we put it behind the current window.
E 6
E 5
 */
D 5
addwin(w, where)
E 5
I 5
addwin(w, fg)
E 5
register struct ww *w;
I 5
char fg;
E 5
{
D 5
	switch (where) {
	case 0:		/* top of foreground windows */
E 5
I 5
	if (fg) {
E 5
		wwadd(w, framewin);
		if (fgwin == framewin)
			fgwin = w;
D 5
		break;
	case 1:		/* top of normal windows */
E 5
I 5
	} else
E 5
D 6
		wwadd(w, fgwin);
E 6
I 6
		wwadd(w, selwin != 0 && selwin != w && !isfg(selwin)
				? selwin : fgwin);
E 6
D 5
		break;
	case 2:		/* bottom of normal windows */
		wwadd(w, bgwin->ww_back);
		break;
	case 3:		/* top of background windows */
		wwadd(w, bgwin->ww_back);
		bgwin = w;
		break;
	}
E 5
}

/*
 * Delete a window.
 */
deletewin(w)
register struct ww *w;
{
D 5
	if (isfg(w)) {
		if (fgwin == w)
			fgwin = w->ww_back;
	} else if (isbg(w)) {
		if (bgwin == w)
			bgwin = w->ww_forw;
	}
E 5
I 5
	if (fgwin == w)
		fgwin = w->ww_back;
E 5
	wwdelete(w);
}

reframe()
{
	register struct ww *w;

	wwunframe(framewin);
	for (w = wwhead.ww_back; w != &wwhead; w = w->ww_back)
		if (w->ww_hasframe) {
			wwframe(w, framewin);
			labelwin(w);
		}
}

labelwin(w)
register struct ww *w;
{
	int mode = w == selwin ? WWM_REV : 0;

	if (!w->ww_hasframe)
		return;
	if (w->ww_id >= 0) {
		char buf[2];

		buf[0] = w->ww_id + '1';
		buf[1] = 0;
		wwlabel(w, framewin, 1, buf, mode);
	}
	if (w->ww_label) {
		int col;

		if (w->ww_center) {
			col = (w->ww_w.nc - strlen(w->ww_label)) / 2;
			col = MAX(3, col);
		} else
			col = 3;
		wwlabel(w, framewin, col, w->ww_label, mode);
	}
E 4
}

I 13
stopwin(w)
	register struct ww *w;
{
	w->ww_stopped = 1;
	if (w->ww_pty >= 0 && w->ww_ispty)
D 14
		(void) ioctl(w->ww_pty, TIOCSTOP, (char *)0);
E 14
I 14
D 17
		(void) ioctl(w->ww_pty, (int)TIOCSTOP, (char *)0);
E 17
I 17
		(void) ioctl(w->ww_pty, TIOCSTOP, (char *)0);
E 17
E 14
}

startwin(w)
	register struct ww *w;
{
	w->ww_stopped = 0;
	if (w->ww_pty >= 0 && w->ww_ispty)
D 14
		(void) ioctl(w->ww_pty, TIOCSTART, (char *)0);
E 14
I 14
D 17
		(void) ioctl(w->ww_pty, (int)TIOCSTART, (char *)0);
E 17
I 17
		(void) ioctl(w->ww_pty, TIOCSTART, (char *)0);
E 17
}

sizewin(w, nrow, ncol)
register struct ww *w;
{
	struct ww *back = w->ww_back;

	w->ww_alt.nr = w->ww_w.nr;
	w->ww_alt.nc = w->ww_w.nc;
	wwdelete(w);
	if (wwsize(w, nrow, ncol) < 0)
		error("Can't resize window: %s.", wwerror());
	wwadd(w, back);
	reframe();
E 14
}

E 13
waitnl(w)
struct ww *w;
{
	(void) waitnl1(w, "[Type any key to continue]");
}

D 3
more(w, alway)
E 3
I 3
more(w, always)
E 3
register struct ww *w;
D 3
char alway;
E 3
I 3
char always;
E 3
{
	int c;
I 7
	char uc = w->ww_unctrl;
E 7

D 3
	if (!alway && w->ww_cur.r < w->ww_w.b - 2)
E 3
I 3
	if (!always && w->ww_cur.r < w->ww_w.b - 2)
E 3
		return 0;
	c = waitnl1(w, "[Type escape to abort, any other key to continue]");
I 7
	w->ww_unctrl = 0;
E 7
D 3
	(void) wwputs("\033E", w);
E 3
I 3
	wwputs("\033E", w);
E 3
D 7
	return c == CTRL([) ? 2 : 1;
E 7
I 7
	w->ww_unctrl = uc;
D 19
	return c == ctrl([) ? 2 : 1;
E 19
I 19
	return c == ctrl('[') ? 2 : 1;
E 19
E 7
}

waitnl1(w, prompt)
register struct ww *w;
char *prompt;
{
I 7
	char uc = w->ww_unctrl;

	w->ww_unctrl = 0;
E 7
	front(w, 0);
D 3
	(void) wwprintf(w, "\033Y%c%c\033p%s\033q ",
E 3
I 3
D 16
	wwprintf(w, "\033Y%c%c\033p%s\033q ",
E 16
I 16
	wwprintf(w, "\033Y%c%c\033sA%s\033rA ",
E 16
E 3
		w->ww_w.nr - 1 + ' ', ' ', prompt);	/* print on last line */
	wwcurtowin(w);
D 2
	while (bpeekc() < 0)
		bread();
	return bgetc();
E 2
I 2
	while (wwpeekc() < 0)
		wwiomux();
I 7
	w->ww_unctrl = uc;
E 7
	return wwgetc();
E 2
}
E 1
