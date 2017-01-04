h50697
s 00010/00005/00066
d D 3.14 88/06/29 21:35:57 bostic 18 17
c install approved copyright notice
e
s 00013/00007/00058
d D 3.13 88/02/21 13:36:55 bostic 17 16
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00059
d D 3.12 85/04/24 16:14:41 edward 16 15
c copyright messages
e
s 00001/00001/00058
d D 3.11 84/05/23 01:57:56 edward 15 14
c new sccs id
e
s 00012/00009/00047
d D 3.10 84/05/06 17:53:42 edward 14 13
c alias macros
e
s 00001/00001/00055
d D 3.9 84/04/08 19:23:10 edward 13 12
c new options to "window": shell, pty, frame
c and stuff to support them
e
s 00002/00001/00054
d D 3.8 84/04/08 12:08:32 edward 12 11
c control character expansion in wwwrite()
c calling of wwupdate() in wwwrite() dependent of ww_noupdate
c control character handling macros in char.h
e
s 00007/00007/00048
d D 3.7 84/03/03 22:45:51 edward 11 10
c interrupt driven input
e
s 00008/00004/00047
d D 3.6 84/01/13 11:09:08 edward 10 9
c more() and waitnl() reworked.
e
s 00001/00004/00050
d D 3.5 84/01/12 12:04:41 edward 9 8
c error() now calls more()
e
s 00013/00013/00041
d D 3.4 83/12/07 14:14:12 edward 8 7
c error window cleanup
e
s 00021/00034/00033
d D 3.3 83/11/22 19:57:39 edward 7 6
c new parser
e
s 00001/00001/00066
d D 3.2 83/08/16 12:31:28 edward 6 5
c error windows are now auto \r\n
e
s 00000/00000/00067
d D 3.1 83/08/11 17:23:04 edward 5 3
i 4
c last few day's work
e
s 00012/00018/00055
d D 2.1.1.1 83/08/09 18:36:13 edward 4 3
c mile stone
e
s 00000/00000/00073
d D 2.1 83/07/30 13:26:19 edward 3 2
c prepare for major change
e
s 00005/00001/00068
d D 1.2 83/07/29 17:13:57 edward 2 1
c malloc space for the filename.
e
s 00069/00000/00000
d D 1.1 83/07/28 18:50:06 edward 1 0
c date and time created 83/07/28 18:50:06 by edward
e
u
U
f b 
t
T
I 1
D 17
#ifndef lint
D 15
static	char *sccsid = "%W% %E%";
E 15
I 15
static char sccsid[] = "%W% %G%";
E 15
#endif

E 17
I 16
/*
D 17
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 17
I 17
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
E 17
 */
I 17

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 17

E 16
#include "defs.h"
I 7
#include "value.h"
#include "context.h"
I 12
#include "char.h"
E 12
E 7

D 4
struct ww *openwin();

extern int lineno;			/* line number in source file */

E 4
D 7
static char *filename;			/* source file name */
static struct ww *errwin;		/* window for error reporting */
static int errlineno;			/* lineno in errwin */
static char baderror;			/* can't open the error window */

E 7
D 4
#define ERRLINES 10			/* number of lines in errwin */
E 4
I 4
#define ERRLINES 10			/* number of lines for errwin */
E 4

/*VARARGS1*/
error(fmt, a, b, c, d, e, f, g, h)
char *fmt;
{
I 14
	register struct context *x;
E 14
I 8
	register struct ww *w;

E 8
D 7
	if (filename == 0) {
E 7
I 7
D 14
	if (cx.x_type != X_FILE) {
E 14
I 14
	for (x = &cx; x != 0 && x->x_type != X_FILE; x = x->x_link)
		;
	if (x == 0) {
E 14
E 7
		if (terse)
D 4
			Ding();
E 4
I 4
D 11
			wwbell();
E 11
I 11
D 12
			wwputc(CTRL(g), cmdwin);
E 12
I 12
D 13
			wwputc(ctrl(g), cmdwin);
E 13
I 13
			wwbell();
E 13
E 12
E 11
E 4
		else {
D 4
			wwprintf(cmdwin, fmt, a, b, c, d, e, f, g, h);
			wwputs("  ", cmdwin);
E 4
I 4
D 11
			(void) wwprintf(cmdwin, fmt, a, b, c, d, e, f, g, h);
			(void) wwputs("  ", cmdwin);
E 11
I 11
			wwprintf(cmdwin, fmt, a, b, c, d, e, f, g, h);
			wwputs("  ", cmdwin);
E 11
E 4
		}
		return;
	}
D 7
	if (baderror)
E 7
I 7
D 8
	if (cx.x_baderr)
E 8
I 8
D 10
	if (cx.x_noerrwin)
E 10
I 10
D 14
	if (cx.x_noerr)
E 14
I 14
	if (x->x_noerr)
E 14
E 10
E 8
E 7
		return;
D 7
	if (errwin == 0) {
E 7
I 7
D 8
	if (cx.x_errwin == 0) {
E 8
I 8
D 14
	if ((w = cx.x_errwin) == 0) {
E 14
I 14
	if ((w = x->x_errwin) == 0) {
E 14
E 8
E 7
		char buf[512];

D 7
		(void) sprintf(buf, "Errors from %s", filename);
D 4
		if ((errwin = openwin(ERRLINES, buf)) == 0) {
			wwprintf(cmdwin, "Can't open error window.  ");
E 4
I 4
		if ((errwin = openiwin(ERRLINES, buf)) == 0) {
E 7
I 7
D 14
		(void) sprintf(buf, "Errors from %s", cx.x_filename);
D 8
		if ((cx.x_errwin = openiwin(ERRLINES, buf)) == 0) {
E 7
			(void) wwprintf(cmdwin, "Can't open error window.  ");
E 4
D 7
			baderror++;
E 7
I 7
			cx.x_baderr = 1;
E 8
I 8
		if ((w = cx.x_errwin = openiwin(ERRLINES, buf)) == 0) {
E 14
I 14
		(void) sprintf(buf, "Errors from %s", x->x_filename);
		if ((w = x->x_errwin = openiwin(ERRLINES, buf)) == 0) {
E 14
D 11
			(void) wwputs("Can't open error window.  ", cmdwin);
E 11
I 11
			wwputs("Can't open error window.  ", cmdwin);
E 11
D 10
			cx.x_noerrwin = 1;
E 10
I 10
D 14
			cx.x_noerr = 1;
E 14
I 14
			x->x_noerr = 1;
E 14
E 10
E 8
E 7
			return;
		}
D 7
		errlineno = 0;
E 7
I 7
D 8
		cx.x_errlineno = 0;
E 8
E 7
	}
D 7
	if (errlineno++ > ERRLINES - 4) {
		waitnl(errwin);
		errlineno = 0;
E 7
I 7
D 8
	if (cx.x_errlineno++ > ERRLINES - 4) {
		waitnl(cx.x_errwin);
		cx.x_errlineno = 0;
E 8
I 8
D 9
	if (w->ww_cur.r >= w->ww_w.b - 2) {
		waitnl(w);
		(void) wwputs("\033E", w);
E 8
E 7
	}
E 9
I 9
D 10
	more(w);
E 10
I 10
	if (more(w, 0) == 2) {
D 14
		cx.x_noerr = 1;
E 14
I 14
		x->x_noerr = 1;
E 14
		return;
	}
E 10
E 9
D 7
	if (lineno != 0)
D 4
		wwprintf(errwin, "line %d: ", lineno);
	wwprintf(errwin, fmt, a, b, c, d, e, f, g, h);
	wwprintf(errwin, "\r\n");
E 4
I 4
		(void) wwprintf(errwin, "line %d: ", lineno);
	(void) wwprintf(errwin, fmt, a, b, c, d, e, f, g, h);
D 6
	(void) wwprintf(errwin, "\r\n");
E 6
I 6
	(void) wwprintf(errwin, "\n");
E 7
I 7
D 8
	if (cx.x_lineno != 0)
		(void) wwprintf(cx.x_errwin, "line %d: ", cx.x_lineno);
	(void) wwprintf(cx.x_errwin, fmt, a, b, c, d, e, f, g, h);
	(void) wwprintf(cx.x_errwin, "\n");
E 8
I 8
D 11
	(void) wwprintf(w, "line %d: ", cx.x_lineno);
	(void) wwprintf(w, fmt, a, b, c, d, e, f, g, h);
	(void) wwputc('\n', w);
E 11
I 11
D 14
	wwprintf(w, "line %d: ", cx.x_lineno);
E 14
I 14
	wwprintf(w, "line %d: ", x->x_lineno);
E 14
	wwprintf(w, fmt, a, b, c, d, e, f, g, h);
	wwputc('\n', w);
E 11
E 8
E 7
E 6
E 4
}

D 7
beginerror(fn)
char *fn;
E 7
I 7
err_end()
E 7
{
D 2
	filename = fn;
E 2
I 2
D 4
	char *malloc();

	filename = malloc(strlen(fn) + 1);
	strcpy(filename, fn);
E 4
I 4
D 7
	filename = malloc((unsigned) strlen(fn) + 1);
	(void) strcpy(filename, fn);
E 4
E 2
}

enderror()
{
	if (errwin != 0) {
		waitnl(errwin);
D 4
		closewin(errwin);
E 4
I 4
		closeiwin(errwin);
E 4
		errwin = 0;
E 7
I 7
D 14
	if (cx.x_errwin != 0) {
E 14
I 14
	if (cx.x_type == X_FILE && cx.x_errwin != 0) {
E 14
D 10
		waitnl(cx.x_errwin);
E 10
I 10
		if (!cx.x_noerr)
			waitnl(cx.x_errwin);
E 10
		closeiwin(cx.x_errwin);
		cx.x_errwin = 0;
E 7
	}
D 7
	baderror = 0;
I 2
	free(filename);
E 2
	filename = 0;
E 7
}
E 1
