h04324
s 00010/00005/00264
d D 3.38 88/06/29 21:35:29 bostic 49 48
c install approved copyright notice
e
s 00144/00145/00125
d D 3.37 88/04/25 22:07:22 edward 48 47
c fixed type-ahead after getting out of command mode bug
e
s 00013/00007/00257
d D 3.36 88/02/21 13:36:35 bostic 47 46
c written by Edward Wang; attach Berkeley specific copyright
e
s 00021/00021/00243
d D 3.35 88/01/03 00:56:05 bostic 46 45
c fix ctrl macro for ANSI C
e
s 00007/00005/00257
d D 3.34 87/05/18 12:20:22 edward 45 44
c added keepopen and smooth flags, added + and - window selections
e
s 00006/00000/00256
d D 3.33 85/04/24 16:11:53 edward 44 43
c copyright messages
e
s 00002/00019/00254
d D 3.32 85/03/13 20:01:35 edward 43 42
c handle ^S and ^Q (the commands) better
e
s 00028/00006/00245
d D 3.31 85/03/01 17:35:01 edward 42 41
c new commands s and S.  also better way to stop window output
e
s 00001/00001/00250
d D 3.30 84/05/23 01:56:35 edward 41 40
c new sccs id
e
s 00002/00002/00249
d D 3.29 84/04/08 19:22:42 edward 40 39
c new options to "window": shell, pty, frame
c and stuff to support them
e
s 00002/00002/00249
d D 3.28 84/04/08 12:34:17 edward 39 38
c set ww_mapnl for cmdwin
e
s 00024/00023/00227
d D 3.27 84/04/08 12:07:59 edward 38 37
c control character expansion in wwwrite()
c calling of wwupdate() in wwwrite() dependent of ww_noupdate
c control character handling macros in char.h
e
s 00004/00008/00246
d D 3.26 84/04/07 15:28:23 edward 37 36
c 'v' and 'L' left.
e
s 00000/00003/00254
d D 3.25 84/04/06 21:35:00 edward 36 35
c "C" removed, varargs added for "write" and "close"
e
s 00000/00015/00257
d D 3.24 84/04/05 17:31:54 edward 35 34
c "s," "t," and "T" moved to long commands (iostat, time).
c "S" removed.
e
s 00053/00016/00219
d D 3.23 84/04/05 00:31:28 edward 34 33
c -c flag, incmd, setcmd(), setterse() added
e
s 00000/00060/00235
d D 3.22 84/03/29 00:02:57 edward 33 32
c foreground and background windows
e
s 00011/00011/00284
d D 3.21 84/03/03 22:42:31 edward 32 31
c interrupt driven input
e
s 00005/00005/00290
d D 3.20 84/01/16 15:25:17 edward 31 30
c new io scheme
e
s 00002/00000/00293
d D 3.19 83/12/09 14:30:05 edward 30 29
c don't do if setselwin(selwin)
e
s 00003/00000/00290
d D 3.18 83/12/06 12:52:01 edward 29 28
c 'v' command
e
s 00004/00003/00286
d D 3.17 83/12/02 23:38:42 edward 28 27
c front() must reframe() when called from setselwin()
e
s 00011/00006/00278
d D 3.16 83/11/30 11:55:09 edward 27 26
c lastselwin, and restructured some code
e
s 00004/00010/00280
d D 3.15 83/11/23 16:35:06 edward 26 25
c New cover scheme
e
s 00002/00000/00288
d D 3.14 83/11/02 11:06:20 edward 25 24
c flags for different machines.
e
s 00014/00027/00274
d D 3.13 83/09/15 17:10:58 edward 24 23
c The 'M' command and rearranged debugging commands ('&')
e
s 00001/00001/00300
d D 3.12 83/09/15 10:08:48 edward 23 22
c Now uses screen address for all buffers.
e
s 00012/00003/00289
d D 3.11 83/09/02 12:58:56 edward 22 21
c use wwvisible() to see if we need wwmoveup().
e
s 00181/00168/00111
d D 3.10 83/09/01 18:34:38 edward 21 20
c Got rid of 'curwin'.
c and now knows about dead processes.
e
s 00004/00000/00275
d D 3.9 83/08/31 19:51:01 edward 20 19
c moving windows
e
s 00002/00002/00273
d D 3.8 83/08/26 16:24:19 edward 19 18
c error reporting
e
s 00025/00013/00250
d D 3.7 83/08/26 13:15:42 edward 18 17
c use wwmoveup() to move windows to the front.
e
s 00002/00002/00261
d D 3.6 83/08/23 15:12:17 edward 17 16
c selwin didn't insert to top if oldselwin == 0
e
s 00036/00026/00227
d D 3.5 83/08/22 13:07:00 edward 16 15
c organized debugging commands
e
s 00002/00014/00251
d D 3.4 83/08/19 15:04:28 edward 15 14
c fake cursor
e
s 00012/00006/00253
d D 3.3 83/08/18 15:29:13 edward 14 13
c scrolling has come
e
s 00010/00003/00249
d D 3.2 83/08/17 17:13:45 edward 13 12
c ^S and ^Q commands
e
s 00000/00000/00252
d D 3.1 83/08/11 17:21:29 edward 12 10
i 11
c last few day's work
e
s 00098/00074/00154
d D 2.1.1.1 83/08/09 18:34:37 edward 11 10
c mile stone
e
s 00000/00000/00228
d D 2.1 83/07/30 13:25:50 edward 10 9
c prepare for major change
e
s 00003/00001/00225
d D 1.9 83/07/28 18:35:07 edward 9 8
c terse mode fix.
e
s 00034/00012/00192
d D 1.8 83/07/28 18:31:51 edward 8 7
c terse mode and some new commands.
c also, the : business.
e
s 00030/00022/00174
d D 1.7 83/07/28 16:00:01 edward 7 6
c user label, and some new commands.
e
s 00021/00010/00175
d D 1.6 83/07/28 13:12:31 edward 6 5
c changeable escape and terse flag
e
s 00003/00000/00182
d D 1.5 83/07/22 18:08:25 edward 5 4
c dostat() added
e
s 00043/00004/00139
d D 1.4 83/07/22 17:08:35 edward 4 3
c scrolling.
c uses Wscreensize() to get screen size.
c More intelligent framing.
c etc.
e
s 00008/00006/00135
d D 1.3 83/07/20 19:30:46 edward 3 2
c Startup configuration stuff, and misc.
e
s 00006/00007/00135
d D 1.2 83/07/19 20:07:45 edward 2 1
c today's work
e
s 00142/00000/00000
d D 1.1 83/07/18 21:05:10 edward 1 0
c date and time created 83/07/18 21:05:10 by edward
e
u
U
f b 
t
T
I 1
D 47
#ifndef lint
D 41
static	char *sccsid = "%W% %E%";
E 41
I 41
static char sccsid[] = "%W% %G%";
E 41
#endif

E 47
I 44
/*
D 47
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 47
I 47
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 49
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 49
I 49
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
E 49
E 47
 */
I 47

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 47

E 44
#include "defs.h"
I 38
#include "char.h"
E 38

D 18
struct ww *getwin();
D 6
struct ww *openwin();
char *strtime();
E 6

E 18
docmd()
{
	register char c;
	register struct ww *w;
I 34
	char out = 0;
E 34
D 6
	char buf;
E 6

D 8
top:
E 8
D 6
	Wunhide(cmdwin->ww_win);
E 6
I 6
D 34
	if (!terse)
D 11
		Wunhide(cmdwin->ww_win);
E 11
I 11
		wwadd(cmdwin, &wwhead);
D 15
	/*
E 15
E 11
E 6
I 4
	if (selwin != 0)
D 15
		Woncursor(selwin->ww_win, 1);
I 11
	*/
E 15
I 15
		wwcursor(selwin, 1);
E 34
E 15
E 11
I 8
D 21
top:
E 8
E 4
	while ((c = bgetc()) >= 0) {
D 8
		wwputs("\r\n", cmdwin);
E 8
I 8
		if (!terse)
D 11
			wwputs("\r\n", cmdwin);
E 11
I 11
			(void) wwputs("\r\n", cmdwin);
E 11
E 8
		switch (c) {
I 6
		default:
			if (c == escapec)
				goto foo;
			break;
E 6
D 8
		case 'r':
		case 'R':
E 8
I 4
		case 'h': case 'j': case 'k': case 'l':
I 14
		case CTRL(y):
		case CTRL(e):
E 14
		case CTRL(u):
		case CTRL(d):
		case CTRL(b):
		case CTRL(f):
I 13
		case CTRL(s):
		case CTRL(q):
E 13
E 4
		case CTRL([):
D 6
		case ESCAPE:
E 6
I 6
		foo:
E 6
			if (selwin == 0) {
D 8
				wwputs("No window.  ", cmdwin);
E 8
I 8
D 9
				if (!terse)
E 9
I 9
D 11
				if (terse)
					Ding();
				else
E 9
					wwputs("No window.  ", cmdwin);
E 11
I 11
				error("No window.");
E 11
E 8
				continue;
			}
		}
		switch (c) {
		case '1': case '2': case '3': case '4': case '5':
		case '6': case '7': case '8': case '9':
D 11
			if ((w = wwfind(c - '0')) == 0) {
				Ding();
E 11
I 11
			if ((w = window[c - '1']) == 0) {
				wwbell();
E 21
I 21
D 48
	for (;;) {
D 31
		while ((c = bgetc()) >= 0) {
E 31
I 31
		while ((c = wwgetc()) >= 0) {
E 31
			if (!terse)
D 32
				(void) wwputs("\r\n", cmdwin);
E 32
I 32
D 39
				wwputs("\r\n", cmdwin);
E 39
I 39
				wwputc('\n', cmdwin);
E 39
E 32
			switch (c) {
			default:
D 45
				if (c == escapec)
					goto foo;
E 21
E 11
				break;
E 45
I 45
				if (c != escapec)
					break;
E 45
I 21
			case 'h': case 'j': case 'k': case 'l':
D 38
			case CTRL(y):
			case CTRL(e):
			case CTRL(u):
			case CTRL(d):
			case CTRL(b):
			case CTRL(f):
			case CTRL(s):
			case CTRL(q):
			case CTRL([):
E 38
I 38
D 46
			case ctrl(y):
			case ctrl(e):
			case ctrl(u):
			case ctrl(d):
			case ctrl(b):
			case ctrl(f):
			case ctrl(s):
			case ctrl(q):
			case ctrl([):
E 46
I 46
			case ctrl('y'):
			case ctrl('e'):
			case ctrl('u'):
			case ctrl('d'):
			case ctrl('b'):
			case ctrl('f'):
			case ctrl('s'):
			case ctrl('q'):
			case ctrl('['):
E 46
E 38
D 45
			foo:
E 45
				if (selwin == 0) {
					error("No window.");
					continue;
				}
E 48
I 48
	while (!out && !quit) {
		if ((c = wwgetc()) < 0) {
			if (terse)
				wwsetcursor(0, 0);
			else {
				wwputs("Command: ", cmdwin);
				wwcurtowin(cmdwin);
E 48
E 21
			}
D 21
			setselwin(w);
			goto out;
		case '%':
D 7
			if ((w = getwin()) == 0)
				break;
			setselwin(w);
E 7
I 7
			if ((w = getwin()) != 0)
E 21
I 21
D 48
			switch (c) {
			case '1': case '2': case '3': case '4': case '5':
			case '6': case '7': case '8': case '9':
				if ((w = window[c - '1']) == 0) {
D 27
					wwbell();
E 27
I 27
					error("%c: No such window.", c);
E 27
					break;
				}
E 21
				setselwin(w);
E 7
D 21
			break;
		case 'c':
I 4
D 7
			doclose(CLOSE_ONE, getwin());
E 7
I 7
			if ((w = getwin()) != 0)
D 11
				doclose(w);
E 11
I 11
				c_close(w);
E 11
E 7
			break;
E 4
		case 'C':
I 4
D 7
			doclose(CLOSE_DEAD, (struct ww *)0);
E 7
I 7
D 11
			doclose((struct ww *)0);
E 11
I 11
			c_close((struct ww *)0);
E 11
E 7
			break;
E 4
D 13
		case 'Z':
D 4
			doclose(c);
E 4
I 4
D 7
			doclose(CLOSE_ALL, (struct ww *)0);
E 7
I 7
D 8
			wwputs("Command Z is now C.  ", cmdwin);
E 8
I 8
D 11
			if (terse)
				Ding();
			else
				wwputs("Command Z is now C.  ", cmdwin);
E 11
I 11
			error("Command Z is now C.");
E 11
E 8
E 7
E 4
			break;
E 13
		case 'w':
D 11
			dowindow();
E 11
I 11
			c_window();
E 11
			break;
I 20
		case 'm':
			if ((w = getwin()) != 0)
				c_move(w);
			break;
E 20
I 2
D 7
		case 'Q':
			doquery();
E 7
I 7
		case 'S':
D 11
			doshow();
E 11
I 11
			c_show();
E 11
E 7
			break;
I 8
		case 'L':
D 11
			dolist();
E 11
I 11
			c_list();
E 11
			break;
D 11
		/*
E 8
I 6
		case 'e':
			doescape();
E 11
I 11
D 16
		case 's':
			c_stat();
E 11
			break;
I 7
D 11
		case 'L':
			dolabel();
E 11
I 11
		case 'M':
			wwdumpsmap();
E 11
			break;
E 7
E 6
E 2
D 11
		case 'r':
			selwin->ww_refresh = 0;
E 11
I 11
		case 'V':
			if ((w = getwin()) != 0)
				wwdumpnvis(w);
E 11
			break;
D 11
		case 'R':
			selwin->ww_refresh = 1;
E 11
I 11
		case 'D':
			if ((w = getwin()) != 0)
				wwdumpcov(w);
E 11
			break;
I 8
D 11
		*/
E 8
I 5
		case 's':
			dostat();
E 11
I 11
		case 'W':
			if ((w = getwin()) != 0)
				wwdumpwin(w);
E 11
			break;
E 5
		case 't':
D 11
			dotime(RUSAGE_SELF);
E 11
I 11
			c_time(RUSAGE_SELF);
E 11
			break;
		case 'T':
D 11
			dotime(RUSAGE_CHILDREN);
E 11
I 11
			c_time(RUSAGE_CHILDREN);
E 11
			break;
E 16
I 7
		case ':':
D 11
			docolon();
E 11
I 11
			c_colon();
E 11
			break;
E 7
I 4
		case 'h':
D 11
			Wcurleft(selwin->ww_win, 1);
E 11
I 11
			(void) wwwrite(selwin, "\b", 1);
E 11
			break;
		case 'j':
D 11
			Wcurdown(selwin->ww_win, 1);
E 11
I 11
			(void) wwwrite(selwin, "\n", 1);
E 11
			break;
		case 'k':
D 11
			Wcurup(selwin->ww_win, 1);
E 11
I 11
			(void) wwwrite(selwin, "\033A", 2);
E 11
			break;
		case 'l':
D 11
			Wcurright(selwin->ww_win, 1);
E 11
I 11
			(void) wwwrite(selwin, "\033C", 2);
E 11
			break;
I 11
D 14
		/*
E 14
I 14
		case CTRL(e):
			wwscroll(selwin, 1);
			break;
		case CTRL(y):
			wwscroll(selwin, -1);
			break;
E 14
E 11
		case CTRL(d):
D 11
			doscroll(1);
E 11
I 11
D 14
			c_scroll(1);
E 14
I 14
			wwscroll(selwin, selwin->ww_w.nr / 2);
E 14
E 11
			break;
		case CTRL(u):
D 11
			doscroll(-1);
E 11
I 11
D 14
			c_scroll(-1);
E 14
I 14
			wwscroll(selwin, - selwin->ww_w.nr / 2);
E 14
E 11
			break;
		case CTRL(f):
D 11
			doscroll(2);
E 11
I 11
D 14
			c_scroll(2);
E 14
I 14
			wwscroll(selwin, selwin->ww_w.nr);
E 14
E 11
			break;
		case CTRL(b):
D 11
			doscroll(-2);
E 11
I 11
D 14
			c_scroll(-2);
E 14
I 14
			wwscroll(selwin, - selwin->ww_w.nr);
E 14
E 11
			break;
I 11
D 14
		*/
E 14
I 13
		case CTRL(s):
			(void) write(selwin->ww_pty,
				&wwwintty.ww_tchars.t_stopc, 1);
			break;
		case CTRL(q):
			(void) write(selwin->ww_pty,
				&wwwintty.ww_tchars.t_startc, 1);
			break;
E 13
E 11
E 4
		case CTRL(l):
D 11
			ScreenGarbaged = 1;
E 11
I 11
			wwredraw();
E 11
			break;
		case '?':
D 11
			dohelp();
E 11
I 11
			c_help();
E 11
			break;
D 6
		case ESCAPE:
			buf = ESCAPE;
			write(selwin->ww_pty, &buf, 1);
E 6
		case CTRL([):
			goto out;
		case CTRL(z):
			wwsuspend();
			break;
D 8
		case '.':
E 8
I 8
		case 'q':
E 8
D 3
			quit++;
			goto out;
E 3
I 3
D 11
			doquit();
E 11
I 11
			c_quit();
E 11
			if (quit)
				goto out;
			break;
I 8
D 16
		case '.':
D 11
			if (terse)
				Ding();
			else
				wwputs("Use q to quit.  ", cmdwin);
E 11
I 11
			error("Use q to quit.");
E 16
I 16
		/* undocumented commands */
		case 's':
			c_stat();
E 16
E 11
			break;
I 16
		case 't':
			c_time(RUSAGE_SELF);
			break;
		case 'T':
			c_time(RUSAGE_CHILDREN);
			break;
		/* debugging commands */
		case 'M':
			if (!debug)
				goto badcmd;
			wwdumpsmap();
			break;
		case 'V':
			if (!debug)
				goto badcmd;
			if ((w = getwin()) != 0)
				wwdumpnvis(w);
			break;
		case 'D':
			if (!debug)
				goto badcmd;
			if ((w = getwin()) != 0)
				wwdumpcov(w);
			break;
		case 'W':
			if (!debug)
				goto badcmd;
			if ((w = getwin()) != 0)
				wwdumpwin(w);
			break;
E 16
E 8
E 3
		default:
I 16
		badcmd:
E 16
I 6
			if (c == escapec) {
D 11
				write(selwin->ww_pty, &escapec, 1);
E 11
I 11
				(void) write(selwin->ww_pty, &escapec, 1);
E 11
				goto out;
E 21
I 21
				if (checkproc(selwin) >= 0)
D 32
					incmd = 0;
E 32
I 32
D 34
					 wwcurwin = selwin;
E 34
I 34
					 out = 1;
E 48
I 48
			do
				wwiomux();
			while ((c = wwgetc()) < 0);
		}
		if (!terse)
			wwputc('\n', cmdwin);
		switch (c) {
		default:
			if (c != escapec)
E 48
E 34
E 32
				break;
D 48
			case '%':
				if ((w = getwin()) != 0)
					setselwin(w);
E 48
I 48
		case 'h': case 'j': case 'k': case 'l':
		case ctrl('y'):
		case ctrl('e'):
		case ctrl('u'):
		case ctrl('d'):
		case ctrl('b'):
		case ctrl('f'):
		case ctrl('s'):
		case ctrl('q'):
		case ctrl('['):
			if (selwin == 0) {
				error("No window.");
				continue;
			}
		}
		switch (c) {
		case '1': case '2': case '3': case '4': case '5':
		case '6': case '7': case '8': case '9':
			if ((w = window[c - '1']) == 0) {
				error("%c: No such window.", c);
E 48
				break;
I 27
D 38
			case CTRL(^):
E 38
I 38
D 46
			case ctrl(^):
E 46
I 46
D 48
			case ctrl('^'):
E 46
E 38
				if (lastselwin != 0) {
					setselwin(lastselwin);
					if (checkproc(selwin) >= 0)
D 32
						incmd = 0;
E 32
I 32
D 34
						wwcurwin = selwin;
E 34
I 34
						out = 1;
E 34
E 32
				} else
					error("No previous window.");
				break;
E 27
			case 'c':
				if ((w = getwin()) != 0)
D 45
					c_close(w);
E 45
I 45
					closewin(w);
E 45
				break;
D 36
			case 'C':
				c_close((struct ww *)0);
				break;
E 36
			case 'w':
				c_window();
				break;
			case 'm':
				if ((w = getwin()) != 0)
					c_move(w);
				break;
I 24
			case 'M':
				if ((w = getwin()) != 0)
D 42
					movewin(w, w->ww_altpos.r,
						w->ww_altpos.c);
E 42
I 42
					movewin(w, w->ww_alt.t, w->ww_alt.l);
E 42
				break;
I 42
			case 's':
				if ((w = getwin()) != 0)
					c_size(w);
				break;
			case 'S':
				if ((w = getwin()) != 0)
					sizewin(w, w->ww_alt.nr, w->ww_alt.nc);
				break;
E 42
E 24
D 35
			case 'S':
				c_show();
				break;
E 35
D 37
			case 'L':
				c_list();
				break;
I 29
			case 'v':
				c_variable();
				break;
E 37
E 29
			case ':':
				c_colon();
				break;
			case 'h':
				(void) wwwrite(selwin, "\b", 1);
				break;
			case 'j':
				(void) wwwrite(selwin, "\n", 1);
				break;
			case 'k':
				(void) wwwrite(selwin, "\033A", 2);
				break;
			case 'l':
				(void) wwwrite(selwin, "\033C", 2);
				break;
D 38
			case CTRL(e):
E 38
I 38
D 46
			case ctrl(e):
E 46
I 46
			case ctrl('e'):
E 46
E 38
				wwscroll(selwin, 1);
				break;
D 38
			case CTRL(y):
E 38
I 38
D 46
			case ctrl(y):
E 46
I 46
			case ctrl('y'):
E 46
E 38
				wwscroll(selwin, -1);
				break;
D 38
			case CTRL(d):
E 38
I 38
D 46
			case ctrl(d):
E 46
I 46
			case ctrl('d'):
E 46
E 38
				wwscroll(selwin, selwin->ww_w.nr / 2);
				break;
D 38
			case CTRL(u):
E 38
I 38
D 46
			case ctrl(u):
E 46
I 46
			case ctrl('u'):
E 46
E 38
				wwscroll(selwin, - selwin->ww_w.nr / 2);
				break;
D 38
			case CTRL(f):
E 38
I 38
D 46
			case ctrl(f):
E 46
I 46
			case ctrl('f'):
E 46
E 38
				wwscroll(selwin, selwin->ww_w.nr);
				break;
D 38
			case CTRL(b):
E 38
I 38
D 46
			case ctrl(b):
E 46
I 46
			case ctrl('b'):
E 46
E 38
				wwscroll(selwin, - selwin->ww_w.nr);
				break;
D 38
			case CTRL(s):
E 38
I 38
D 46
			case ctrl(s):
E 46
I 46
			case ctrl('s'):
E 46
E 38
D 42
				(void) write(selwin->ww_pty,
					&wwwintty.ww_tchars.t_stopc, 1);
E 42
I 42
D 43
				if (selwin->ww_pty < 0)
					break;
				if (selwin->ww_ispty) {
					(void) ioctl(selwin->ww_pty, TIOCSTOP,
						(char *)0);
					selwin->ww_stopped = 1;
				} else
					(void) write(selwin->ww_pty,
						&wwwintty.ww_tchars.t_stopc, 1);
E 43
I 43
				stopwin(selwin);
E 43
E 42
				break;
D 38
			case CTRL(q):
E 38
I 38
D 46
			case ctrl(q):
E 46
I 46
			case ctrl('q'):
E 46
E 38
D 42
				(void) write(selwin->ww_pty,
					&wwwintty.ww_tchars.t_startc, 1);
E 42
I 42
D 43
				if (selwin->ww_pty < 0)
					break;
				if (selwin->ww_ispty) {
					(void) ioctl(selwin->ww_pty, TIOCSTART,
						(char *)0);
					selwin->ww_stopped = 0;
				} else
					(void) write(selwin->ww_pty,
						&wwwintty.ww_tchars.t_startc,
						1);
E 43
I 43
				startwin(selwin);
E 43
E 42
				break;
D 38
			case CTRL(l):
E 38
I 38
D 46
			case ctrl(l):
E 46
I 46
			case ctrl('l'):
E 46
E 38
				wwredraw();
				break;
			case '?':
				c_help();
				break;
D 38
			case CTRL([):
E 38
I 38
D 46
			case ctrl([):
E 46
I 46
			case ctrl('['):
E 48
I 48
			}
			setselwin(w);
			if (checkproc(selwin) >= 0)
				 out = 1;
			break;
		case '%':
			if ((w = getwin()) != 0)
				setselwin(w);
			break;
		case ctrl('^'):
			if (lastselwin != 0) {
				setselwin(lastselwin);
E 48
E 46
E 38
				if (checkproc(selwin) >= 0)
D 32
					incmd = 0;
E 32
I 32
D 34
					wwcurwin = selwin;
E 34
I 34
					out = 1;
I 48
			} else
				error("No previous window.");
			break;
		case 'c':
			if ((w = getwin()) != 0)
				closewin(w);
			break;
		case 'w':
			c_window();
			break;
		case 'm':
			if ((w = getwin()) != 0)
				c_move(w);
			break;
		case 'M':
			if ((w = getwin()) != 0)
				movewin(w, w->ww_alt.t, w->ww_alt.l);
			break;
		case 's':
			if ((w = getwin()) != 0)
				c_size(w);
			break;
		case 'S':
			if ((w = getwin()) != 0)
				sizewin(w, w->ww_alt.nr, w->ww_alt.nc);
			break;
		case ':':
			c_colon();
			break;
		case 'h':
			(void) wwwrite(selwin, "\b", 1);
			break;
		case 'j':
			(void) wwwrite(selwin, "\n", 1);
			break;
		case 'k':
			(void) wwwrite(selwin, "\033A", 2);
			break;
		case 'l':
			(void) wwwrite(selwin, "\033C", 2);
			break;
		case ctrl('e'):
			wwscroll(selwin, 1);
			break;
		case ctrl('y'):
			wwscroll(selwin, -1);
			break;
		case ctrl('d'):
			wwscroll(selwin, selwin->ww_w.nr / 2);
			break;
		case ctrl('u'):
			wwscroll(selwin, - selwin->ww_w.nr / 2);
			break;
		case ctrl('f'):
			wwscroll(selwin, selwin->ww_w.nr);
			break;
		case ctrl('b'):
			wwscroll(selwin, - selwin->ww_w.nr);
			break;
		case ctrl('s'):
			stopwin(selwin);
			break;
		case ctrl('q'):
			startwin(selwin);
			break;
		case ctrl('l'):
			wwredraw();
			break;
		case '?':
			c_help();
			break;
		case ctrl('['):
			if (checkproc(selwin) >= 0)
				out = 1;
			break;
		case ctrl('z'):
			wwsuspend();
			break;
		case 'q':
			c_quit();
			break;
		/* debugging stuff */
		case '&':
			if (debug) {
				c_debug();
E 48
E 34
E 32
				break;
D 38
			case CTRL(z):
E 38
I 38
D 46
			case ctrl(z):
E 46
I 46
D 48
			case ctrl('z'):
E 46
E 38
				wwsuspend();
				break;
			case 'q':
				c_quit();
				break;
D 35
			/* undocumented commands */
			case 's':
				c_stat();
				break;
I 25
#ifndef O_4_1A
E 25
			case 't':
				c_time(RUSAGE_SELF);
				break;
			case 'T':
				c_time(RUSAGE_CHILDREN);
				break;
I 25
#endif
E 35
E 25
D 24
			/* debugging commands */
			case 'M':
				if (!debug)
					goto badcmd;
				wwdumpsmap();
				break;
			case 'V':
				if (!debug)
					goto badcmd;
				if ((w = getwin()) != 0)
					wwdumpnvis(w);
				break;
			case 'D':
				if (!debug)
					goto badcmd;
				if ((w = getwin()) != 0)
					wwdumpcov(w);
				break;
			case 'W':
				if (!debug)
					goto badcmd;
				if ((w = getwin()) != 0)
					wwdumpwin(w);
				break;
E 24
I 24
			/* debugging stuff */
			case '&':
				if (debug) {
					c_debug();
					break;
E 48
I 48
			}
		default:
			if (c == escapec) {
				if (checkproc(selwin) >= 0) {
					(void) write(selwin->ww_pty,
						&escapec, 1);
					out = 1;
E 48
				}
E 24
D 48
			default:
D 24
			badcmd:
E 24
				if (c == escapec) {
					if (checkproc(selwin) >= 0) {
						(void) write(selwin->ww_pty,
							&escapec, 1);
D 32
						incmd = 0;
E 32
I 32
D 34
						wwcurwin = selwin;
E 34
I 34
						out = 1;
E 34
E 32
					}
				} else {
					if (!terse)
D 32
						wwbell();
E 32
I 32
D 38
						wwputc(CTRL(g), cmdwin);
E 38
I 38
D 40
						wwputc(ctrl(g), cmdwin);
E 40
I 40
						wwbell();
E 40
E 38
E 32
					error("Type ? for help.");
				}
E 48
I 48
			} else {
				if (!terse)
					wwbell();
				error("Type ? for help.");
E 48
E 21
			}
E 6
D 11
			Ding();
E 11
D 2
			wwputs("Type ? for help.  ", cmdwin);
E 2
I 2
D 3
			wwprintf(cmdwin, "(%x) Type ? for help.  ", c);
E 3
I 3
D 8
			wwprintf(cmdwin, "Type ? for help.  ");
E 8
I 8
D 21
			if (!terse)
D 11
				wwprintf(cmdwin, "Type ? for help.  ");
E 11
I 11
				wwbell();
			error("Type ? for help.");
E 21
I 21
		}
D 32
		if (!incmd || quit)
E 32
I 32
D 34
		if (wwcurwin != 0 || quit)
E 34
I 34
D 48
		if (out || quit)
E 34
E 32
E 21
E 11
E 8
E 3
E 2
			break;
I 21
		if (terse)
			wwsetcursor(0, 0);
		else {
D 32
			(void) wwputs("Command: ", cmdwin);
E 32
I 32
			wwputs("Command: ", cmdwin);
E 32
			wwcurtowin(cmdwin);
E 21
		}
I 21
D 31
		while (bpeekc() < 0)
			bread();
E 31
I 31
		while (wwpeekc() < 0)
			wwiomux();
E 48
E 31
E 21
	}
D 8
	wwputs("Command: ", cmdwin);
	wwsetcursor(WCurRow(cmdwin->ww_win), WCurCol(cmdwin->ww_win));
E 8
I 8
D 21
	if (terse)
		wwsetcursor(0, 0);
	else {
		if (!terse)
D 11
			wwputs("Command: ", cmdwin);
		wwsetcursor(WCurRow(cmdwin->ww_win), WCurCol(cmdwin->ww_win));
E 11
I 11
			(void) wwputs("Command: ", cmdwin);
		wwsetcursor(wwcurrow(cmdwin), wwcurcol(cmdwin));
E 11
	}
E 8
D 2
	while (bpeekc() < 0) {
		wwflush();
E 2
I 2
	while (bpeekc() < 0)
E 2
		bread();
D 2
	}
E 2
	goto top;
out:
E 21
D 11
	if (!quit)
D 3
		wwsetcurrent(selwin);
E 3
I 3
		wwsetcurwin(selwin);
E 11
I 11
D 34
	if (!quit) {
D 21
		curwin = selwin;
E 21
		if (!terse) {
			wwdelete(cmdwin);
			reframe();
		}
D 21
	}
D 15
	/*
E 15
E 11
I 4
	if (selwin != 0)
E 21
D 15
		Woncursor(selwin->ww_win, 0);
E 4
E 3
D 6
	Whide(cmdwin->ww_win);
E 6
I 6
D 11
	if (!terse)
		Whide(cmdwin->ww_win);
E 11
I 11
	*/
E 15
I 15
		wwcursor(selwin, 0);
I 21
	}
E 34
I 34
	if (!quit)
		setcmd(0);
E 34
E 21
E 15
E 11
E 6
}

struct ww *
getwin()
{
	register int c;
D 7
	struct ww *w;
E 7
I 7
	struct ww *w = 0;
E 7

I 7
D 8
	wwputs("Which window? ", cmdwin);
E 8
I 8
	if (!terse)
D 11
		wwputs("Which window? ", cmdwin);
E 8
	wwsetcursor(WCurRow(cmdwin->ww_win), WCurCol(cmdwin->ww_win));
E 11
I 11
D 32
		(void) wwputs("Which window? ", cmdwin);
E 32
I 32
		wwputs("Which window? ", cmdwin);
E 32
D 23
	wwsetcursor(wwcurrow(cmdwin), wwcurcol(cmdwin));
E 23
I 23
	wwcurtowin(cmdwin);
E 23
E 11
E 7
D 2
	while ((c = bgetc()) < 0) {
		wwflush();
E 2
I 2
D 31
	while ((c = bgetc()) < 0)
E 2
		bread();
E 31
I 31
	while ((c = wwgetc()) < 0)
		wwiomux();
E 31
D 2
	}
E 2
D 7
	if (c < '1' || c > '9') {
E 7
I 7
D 11
	if (c < '1' || c > '9' || (w = wwfind(c - '0')) == 0)
E 7
		Ding();
E 11
I 11
	if (debug && c == 'c')
		w = cmdwin;
	else if (debug && c == 'f')
		w = framewin;
I 16
	else if (debug && c == 'b')
		w = boxwin;
E 16
	else if (c >= '1' && c < NWINDOW + '1')
		w = window[c - '1'];
I 45
	else if (c == '+')
		w = selwin;
	else if (c == '-')
		w = lastselwin;
E 45
	if (w == 0)
D 32
		wwbell();
E 32
I 32
D 38
		wwputc(CTRL(g), cmdwin);
E 38
I 38
D 40
		wwputc(ctrl(g), cmdwin);
E 40
I 40
		wwbell();
E 40
E 38
E 32
E 11
D 7
		return 0;
	}
	if ((w = wwfind(c - '0')) == 0)
		Ding();
E 7
I 7
D 8
	wwputs("\r\n", cmdwin);
E 8
I 8
	if (!terse)
D 11
		wwputs("\r\n", cmdwin);
E 11
I 11
D 32
		(void) wwputs("\r\n", cmdwin);
E 32
I 32
D 39
		wwputs("\r\n", cmdwin);
E 39
I 39
		wwputc('\n', cmdwin);
E 39
E 32
E 11
E 8
E 7
	return w;
I 21
}

checkproc(w)
struct ww *w;
{
	if (w->ww_state != WWS_HASPROC) {
		error("No process in window.");
		return -1;
	}
	return 0;
I 34
}

setcmd(new)
char new;
{
	if (new && !incmd) {
		if (!terse)
			wwadd(cmdwin, &wwhead);
		if (selwin != 0)
			wwcursor(selwin, 1);
		wwcurwin = 0;
	} else if (!new && incmd) {
		if (!terse) {
			wwdelete(cmdwin);
			reframe();
		}
		if (selwin != 0)
			wwcursor(selwin, 0);
		wwcurwin = selwin;
	}
	incmd = new;
}

setterse(new)
char new;
{
	if (incmd)
		if (new && !terse) {
			wwdelete(cmdwin);
			reframe();
		} else if (!new && terse)
			wwadd(cmdwin, &wwhead);
	terse = new;
}

/*
 * Set the current window.
 */
setselwin(w)
struct ww *w;
{
	if (selwin == w)
		return;
D 37
	lastselwin = selwin;
	front(selwin = w, 1);
E 37
I 37
	if (selwin != 0)
		lastselwin = selwin;
	if ((selwin = w) != 0)
		front(selwin, 1);
E 37
E 34
E 21
}
D 33

setselwin(w)
I 18
struct ww *w;
{
I 30
	if (selwin == w)
		return;
E 30
D 27
	if ((selwin = w) != 0)
		front(w);
E 27
I 27
	lastselwin = selwin;
D 28
	front(selwin = w);
E 28
I 28
	front(selwin = w, 1);
E 28
E 27
}

I 22
/*
D 27
 * This is all heuristic.
E 27
D 24
 * wwvisible() doesn't work for partially tinted windows.
 * and wwmoveup() doesn't work for transparent (completely or in part) windows.
E 24
I 24
 * wwvisible() doesn't work for tinted windows.
D 27
 * and wwmoveup() doesn't work for transparent windows
 * (completely or partially).
E 27
E 24
 * But anything to make it faster.
 */
E 22
D 28
front(w)
E 28
I 28
front(w, doreframe)
E 28
E 18
register struct ww *w;
{
D 4
	if (selwin)
E 4
I 4
D 7
	if (selwin) {
E 4
		labelwin(selwin, 0);
D 4
	selwin = w;
	if (w) {
E 4
I 4
		Woncursor(selwin->ww_win, 0);
	}
E 7
I 7
D 11
	struct ww *oldselwin = selwin;
E 11
I 11
D 18
	register struct ww *oldselwin = selwin;
E 18
I 18
D 26
	char moved = 0;
E 18
E 11

D 18
	if (w == oldselwin)
		return;
E 7
	if (selwin = w) {
E 4
D 7
		labelwin(w, WINVERSE);
E 7
I 7
D 11
		labelwin(w);
E 7
		/* bring it to the top just below cmdwin */
D 3
		wwsetcurrent(w);
		wwsetcurrent(cmdwin);
E 3
I 3
		wwsetcurwin(w);
		wwsetcurwin(cmdwin);
E 11
I 11
		wwdelete(w);
		/*
		 * Stick it in front of the old selected window,
D 17
		 * or behind everbody else.
E 17
I 17
		 * or behind the frame window.
E 17
		 */
D 17
		wwadd(w, (oldselwin ? oldselwin : &wwhead)->ww_back);
E 17
I 17
		wwadd(w, oldselwin ? oldselwin->ww_back : framewin);
E 18
I 18
D 22
	while (w->ww_back != framewin) {
		wwmoveup(w);
E 22
I 22
	if (wwvisible(w))
E 22
		moved = 1;
E 18
E 17
D 15
		/*
E 11
I 4
		Woncursor(w->ww_win, 1);
I 11
		*/
E 15
E 11
E 4
E 3
D 22
	}
E 22
I 22
	else
		while (w->ww_back != framewin) {
			wwmoveup(w);
			moved = 1;
		}
E 22
I 11
D 15
	/*
E 11
I 7
	if (oldselwin) {
D 11
		labelwin(oldselwin);
E 11
		Woncursor(oldselwin->ww_win, 0);
	}
I 11
	*/
E 15
D 18
	reframe();
E 18
I 18
	if (moved)
E 26
I 26
	if (!wwvisible(w) && w->ww_back != framewin) {
		wwdelete(w);
		wwadd(w, framewin);
E 26
		reframe();
I 26
D 28
	}
E 28
I 28
	} else if (doreframe)
		reframe();
E 28
E 26
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
E 18
E 11
E 7
}

D 7
labelwin(w, mode)
E 7
I 7
labelwin(w)
E 7
register struct ww *w;
{
D 11
	char buf[2];
I 7
	int mode = w == selwin ? WINVERSE : 0;
E 11
I 11
	int mode = w == selwin ? WWM_REV : 0;
E 11
E 7

D 11
	buf[0] = w->ww_ident + '0';
	buf[1] = 0;
D 6
	wwlabel(w, buf, mode);
E 6
I 6
	wwlabel(w, 1, buf, mode);
D 7
	/*
E 7
	if (w->ww_label)
		wwlabel(w, 3, w->ww_label, mode);
E 11
I 11
	if (w->ww_id >= 0) {
		char buf[2];

		buf[0] = w->ww_id + '1';
		buf[1] = 0;
D 19
		(void) wwlabel(w, framewin, 1, buf, mode);
E 19
I 19
		wwlabel(w, framewin, 1, buf, mode);
E 19
	}
	if (w->ww_label) {
		int col;

		if (w->ww_center) {
			col = (w->ww_w.nc - strlen(w->ww_label)) / 2;
			col = MAX(3, col);
		} else
			col = 3;
D 19
		(void) wwlabel(w, framewin, col, w->ww_label, mode);
E 19
I 19
		wwlabel(w, framewin, col, w->ww_label, mode);
E 19
	}
E 11
D 7
	*/
E 7
E 6
}
E 33
E 1
