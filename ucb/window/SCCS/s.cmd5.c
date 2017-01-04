h41682
s 00010/00005/00100
d D 3.16 88/06/29 21:35:44 bostic 26 25
c install approved copyright notice
e
s 00013/00007/00092
d D 3.15 88/02/21 13:36:45 bostic 25 24
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00093
d D 3.14 85/04/24 16:14:20 edward 24 23
c copyright messages
e
s 00004/00002/00089
d D 3.13 85/03/01 17:40:37 edward 23 22
c changing window size and new WINSZ ioctl
e
s 00001/00001/00090
d D 3.12 84/05/23 01:57:48 edward 22 21
c new sccs id
e
s 00001/00001/00090
d D 3.11 84/04/08 12:34:37 edward 21 20
c set ww_mapnl for cmdwin
e
s 00001/00001/00090
d D 3.10 84/03/03 22:45:16 edward 20 19
c interrupt driven input
e
s 00002/00002/00089
d D 3.9 84/01/16 15:26:04 edward 19 18
c new io scheme
e
s 00006/00005/00085
d D 3.8 83/11/29 11:30:11 edward 18 17
c getpos() cleanup
e
s 00011/00001/00079
d D 3.7 83/09/15 17:11:15 edward 17 16
c The 'M' command and rearranged debugging commands ('&')
e
s 00012/00015/00068
d D 3.6 83/09/15 10:09:15 edward 16 15
c Now uses screen address for all buffers.
e
s 00040/00007/00043
d D 3.5 83/09/14 14:15:16 edward 15 14
c Off screen windows!!!!!!
e
s 00000/00001/00050
d D 3.4 83/09/01 12:59:24 edward 14 13
c lint
e
s 00048/00000/00003
d D 3.3 83/08/31 19:51:12 edward 13 12
c moving windows
e
s 00000/00020/00003
d D 3.2 83/08/18 15:30:17 edward 12 11
c scrolling has come
e
s 00000/00000/00023
d D 3.1 83/08/11 17:22:50 edward 11 9
i 10
c last few day's work
e
s 00013/00254/00010
d D 2.1.1.1 83/08/09 18:35:56 edward 10 9
c mile stone
e
s 00000/00000/00264
d D 2.1 83/07/30 13:26:10 edward 9 8
c prepare for major change
e
s 00032/00016/00232
d D 1.8 83/07/30 13:08:06 edward 8 7
c the write command and some bug fixes in dolongcmd() and makeargv().
e
s 00016/00001/00232
d D 1.7 83/07/29 17:12:46 edward 7 6
c the source command
e
s 00092/00113/00141
d D 1.6 83/07/28 18:32:26 edward 6 5
c terse mode and some new commands.
c also, the : business.
e
s 00111/00033/00143
d D 1.5 83/07/28 15:56:43 edward 5 4
c makeargv now knows about "'s.
c Also, the s_label() added.
e
s 00105/00074/00071
d D 1.4 83/07/28 13:09:06 edward 4 3
c new dosource()
e
s 00001/00000/00144
d D 1.3 83/07/22 18:05:07 edward 3 2
c dosource didn't close the file.
e
s 00002/00002/00142
d D 1.2 83/07/22 17:11:14 edward 2 1
c scrolling.
c uses Wscreensize() to get screen size.
c More intelligent framing.
c etc.
e
s 00144/00000/00000
d D 1.1 83/07/20 19:32:21 edward 1 0
c date and time created 83/07/20 19:32:21 by edward
e
u
U
f b 
t
T
I 1
D 25
#ifndef lint
D 22
static	char *sccsid = "%W% %E%";
E 22
I 22
static char sccsid[] = "%W% %G%";
E 22
#endif
I 13

E 25
I 24
/*
D 25
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 25
I 25
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 26
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 26
I 26
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
E 26
E 25
 */
I 25

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 25

E 24
#include "defs.h"

/*
 * Window movement.
 */
I 17

E 17
c_move(w)
register struct ww *w;
{
	int col, row;
I 15
	int mincol, minrow;
	int maxcol, maxrow;
	int curcol, currow;
E 15
D 14
	int tmp;
E 14
D 17
	struct ww *back = w->ww_back;
E 17

I 23
	if (!terse)
		wwputs("New window position: ", cmdwin);
E 23
	col = w->ww_w.l;
	row = w->ww_w.t;
	wwadd(boxwin, framewin->ww_back);
	for (;;) {
		wwbox(boxwin, row - 1, col - 1, w->ww_w.nr + 2, w->ww_w.nc + 2);
D 15
		wwsetcursor(row, col);
E 15
I 15
		getminmax(row, w->ww_w.nr, 1, wwnrow,
			&currow, &minrow, &maxrow);
		getminmax(col, w->ww_w.nc, 0, wwncol,
			&curcol, &mincol, &maxcol);
		wwsetcursor(currow, curcol);
E 15
D 19
		while (bpeekc() < 0)
			bread();
E 19
I 19
		while (wwpeekc() < 0)
			wwiomux();
E 19
D 18
		wwunbox(boxwin);
E 18
D 15
		switch (getpos(&row, &col, 1, 0,
			wwnrow - w->ww_w.nr, wwncol - w->ww_w.nc)) {
E 15
I 15
		switch (getpos(&row, &col, minrow, mincol, maxrow, maxcol)) {
E 15
D 18
		case -1:
E 18
I 18
		case 3:
			wwunbox(boxwin);
E 18
			wwdelete(boxwin);
D 18
			if (!terse)
				(void) wwputs("\r\nCancelled.  ", cmdwin);
E 18
			return;
D 18
		case 1:
E 18
I 18
		case 2:
			wwunbox(boxwin);
E 18
			break;
I 18
		case 1:
			wwunbox(boxwin);
E 18
		case 0:
			continue;
		}
		break;
	}
	wwdelete(boxwin);
	if (!terse)
D 20
		(void) wwputs("\r\n", cmdwin);
E 20
I 20
D 21
		wwputs("\r\n", cmdwin);
E 21
I 21
		wwputc('\n', cmdwin);
E 21
E 20
	wwcurtowin(cmdwin);
I 17
	movewin(w, row, col);
}

movewin(w, row, col)
register struct ww *w;
{
	struct ww *back = w->ww_back;

D 23
	w->ww_altpos.r = w->ww_w.t;
	w->ww_altpos.c = w->ww_w.l;
E 23
I 23
	w->ww_alt.t = w->ww_w.t;
	w->ww_alt.l = w->ww_w.l;
E 23
E 17
	wwdelete(w);
D 15
	w->ww_w.t = row;
	w->ww_w.l = col;
	w->ww_w.b = row + w->ww_w.nr;
	w->ww_w.r = col + w->ww_w.nc;
E 15
I 15
	wwmove(w, row, col);
E 15
	wwadd(w, back);
	reframe();
I 15
}

/*
 * Weird stufff, don't ask.
 */
getminmax(x, n, a, b, curx, minx, maxx)
register x, n, a, b;
int *curx, *minx, *maxx;
{
D 16
	if (x < a) {
E 16
I 16
	if (x < 0)
E 16
		*curx = x + n - 1;
D 16
		*minx = 1 - n;
		*maxx = a;
	} else if (x == a) {
E 16
I 16
	else
E 16
		*curx = x;
I 16

	if (x <= a)
E 16
		*minx = 1 - n;
D 16
		*maxx = b - n;
	} else if (x < b - n) {
		*curx = x;
E 16
I 16
	else if (x <= b - n)
E 16
		*minx = a;
D 16
		*maxx = b - n;
	} else if (x == b - n) {
		*curx = x;
		*minx = a;
		*maxx = b - 1;
	} else {
		*curx = x;
E 16
I 16
	else
E 16
		*minx = b - n;
I 16

	if (x >= b - n)
E 16
		*maxx = b - 1;
D 16
	}
E 16
I 16
	else if (x >= a)
		*maxx = b - n;
	else
		*maxx = a;
E 16
E 15
}
E 13
D 12

#include "defs.h"
D 5
#include <ctype.h>
E 5

D 6
struct ww *openwin();
E 6
D 10
struct ww *doopen();
I 5
struct ww *idtowin();
E 5

D 6
static char *sourcefilename;
static int lineno;			/* current line number in source file */
E 6
I 6
int lineno;				/* current line number in source file */
E 6
static char *argv[100];			/* one line broken up into words */
static int argc;
I 7
static char insource;
E 7
D 6
static struct ww *errwin;		/* window for error reporting */
static int errlineno;			/* lineno in errwin */
I 4
static char baderrwin;			/* can't open errwin */
E 6
E 4

I 4
int s_window();
int s_select();
int s_escape();
I 5
int s_label();
I 6
int s_terse();
int s_refresh();
I 7
int s_source();
I 8
int s_write();
E 8
E 7

E 6
E 5
struct scmd {
	char *s_name;			/* name of command */
D 8
	int s_len;			/* number of characters to check */
E 8
I 8
	int s_lmin;			/* minimum length to check */
	int s_lmax;			/* maximum length to check */
E 8
	int s_amin;			/* minimum argument */
	int s_amax;			/* maximum argument */
	int (*s_func)();		/* the function */
};
static struct scmd scmd[] = {
D 8
	"window",	1, 4, 4, s_window,
	"%",		1, 0, 0, s_select,
	"escape",	1, 1, 1, s_escape,
I 5
	"label",	1, 2, 2, s_label,
I 6
	"terse",	1, 0, 1, s_terse,
	"refresh",	1, 1, 2, s_refresh,
I 7
	"source",	1, 1, 1, s_source,
E 8
I 8
	"%",		1, 1, 0, 0, s_select,
	"escape",	1, 0, 1, 1, s_escape,
	"label",	1, 0, 2, 2, s_label,
	"refresh",	1, 0, 1, 2, s_refresh,
	"source",	1, 0, 1, 1, s_source,
	"terse",	1, 0, 0, 1, s_terse,
	"window",	1, 0, 4, 4, s_window,
	"write",	2, 0, 2, 2, s_write,
E 8
E 7
E 6
E 5
	0
};

E 4
dosource(filename)
char *filename;
E 10
I 10
/*
c_scroll(dir)
int dir;
E 10
{
D 10
	register FILE *f;
D 4
	register char **pp;
E 4
	char buf[BUFSIZ];
E 10
I 10
	register brow = selwin->ww_scroll;
E 10
D 4
	int id, row, col, nrow, ncol;
	struct ww *w;
E 4
I 4
D 5
	register struct scmd *sp;
E 5
E 4

D 10
	if ((f = fopen(filename, "r")) == 0)
D 4
		return -1;
E 4
I 4
D 7
		return;
E 7
I 7
		return -1;
	insource++;
E 7
E 4
D 5
	sourcefilename = filename;
	for (lineno = 1; fgets(buf, sizeof buf, f) != 0; lineno++) {
D 4
		if (*buf == '#')
			continue;
		breakup(buf);
E 4
I 4
		makeargv(buf);
E 4
		if (argc == 0)
			continue;
D 4
		pp = argv;
		switch (**pp++) {
		case 'w':
			if ((id = findid()) < 0) {
				if (error("Too many windows.") < 0)
					goto bad;
				break;
			}
			if (argc < 5) {
				if (error("Syntax error.") < 0)
					goto bad;
				break;
			}
			if (**pp == '*')
				row = 0;
E 4
I 4
		for (sp = scmd; sp->s_name; sp++)
			if (sp->s_len > 0) {
				if (strncmp(*argv, sp->s_name, sp->s_len) == 0)
					break;
			} else
				if (strncmp(*argv, sp->s_name) == 0)
					break;
		if (sp->s_name) {
			if (sp->s_amin > argc - 1)
				error("Too few arguments.");
			else if (sp->s_amax < argc - 1)
				error("Too many arguments.");
E 4
			else
D 4
				row = atoi(*pp);
			if (**++pp == '*')
				col = 0;
			else
				col = atoi(*pp);
			if (**++pp == '*')
D 2
				nrow = WRows - row;
E 2
I 2
				nrow = wwnrow - row;
E 2
			else
				nrow = atoi(*pp);
			if (**++pp == '*')
D 2
				ncol = WCols - col;
E 2
I 2
				ncol = wwncol - col;
E 2
			else
				ncol = atoi(*pp);
			w = doopen(id, nrow, ncol, row, col);
			if (w == 0) {
				if (error("Can't open window: row %d col %d, %d rows %d cols.", row, col, nrow, ncol) < 0)
					goto bad;
				break;
			}
			break;
		case '%':
			id = atoi(*pp);
			if (id < 1 || id > 9 || (w = wwfind(id)) == 0) {
				if (error("%d: No such window.", id) < 0)
					goto bad;
				break;
			}
			setselwin(w);
			break;
		default:
			if (error("%s: Unknown command.", *argv) < 0)
				goto bad;
		}
E 4
I 4
				(*sp->s_func)();
		} else
			error("%s: Unknown command.", *argv);
E 4
	}
E 5
I 5
	beginerror(filename);
	for (lineno = 1; fgets(buf, sizeof buf, f) != 0; lineno++)
D 6
		doline(buf);
E 6
I 6
		dolongcmd(buf);
E 6
E 5
D 4
	if (errwin != 0) {
		waitnl(errwin);
		closewin(errwin);
		errwin = 0;
	}
bad:
I 3
	fclose(f);
E 4
I 4
	enderror();
I 7
	insource = 0;
E 7
E 4
E 3
	return 0;
}

I 5
D 6
doline(line)
E 6
I 6
dolongcmd(line)
E 6
char *line;
{
	register struct scmd *sp;
I 8
	register len;
E 8

	makeargv(line);
	if (argc == 0)
		return;
D 8
	for (sp = scmd; sp->s_name; sp++)
		if (sp->s_len > 0) {
			if (strncmp(*argv, sp->s_name, sp->s_len) == 0)
				break;
		} else
			if (strncmp(*argv, sp->s_name) == 0)
				break;
E 8
I 8
	for (sp = scmd; sp->s_name; sp++) {
		len = strlen(*argv);
		if (len < sp->s_lmin)
			continue;
		if (!strncmp(*argv, sp->s_name, sp->s_lmax ? sp->s_lmax : len))
			break;
E 10
I 10
	brow += dir * selwin->ww_w.nrow / 2;
	if (brow < 0)
		brow = 0;
	else if (brow + selwin->ww_w.nrow > selwin->ww_nline)
		brow = selwin->ww_nline - selwin->ww_w.nrow;
	if (brow != selwin->ww_scroll) {
		selwin->ww_scroll = brow;
		wwredrawwin(selwin);
E 10
	}
E 8
D 10
	if (sp->s_name) {
		if (sp->s_amin > argc - 1)
			error("Too few arguments.");
		else if (sp->s_amax < argc - 1)
			error("Too many arguments.");
		else
			(*sp->s_func)();
	} else
		error("%s: Unknown command.", *argv);
E 10
}
D 10

E 5
D 4
static
breakup(p)
E 4
I 4
D 6
s_window()
{
	register char **pp = argv;
	register struct ww *w;
	int col, row, ncol, nrow, id;

	if ((id = findid()) < 0) {
		error("Too many windows.");
		return;
	}
	if (**++pp == '*')
		row = 0;
	else
		row = atoi(*pp);
	if (**++pp == '*')
		col = 0;
	else
		col = atoi(*pp);
	if (**++pp == '*')
		nrow = wwnrow - row;
	else
		nrow = atoi(*pp);
	if (**++pp == '*')
		ncol = wwncol - col;
	else
		ncol = atoi(*pp);
	w = doopen(id, nrow, ncol, row, col);
	if (w == 0)
		error("Can't open window: row %d col %d, %d rows %d cols.",
			row, col, nrow, ncol);
}

s_select()
{
D 5
	register int id;
	register struct ww *w;
E 5
I 5
	struct ww *w;
E 5

D 5
	id = atoi(*argv + 1);
	if (id < 1 || id > 9 || (w = wwfind(id)) == 0)
		error("%d: No such window.", id);
	else
		setselwin(w);
E 5
I 5
	if ((w = idtowin(*argv + 1)) == 0)
		return;
	setselwin(w);
E 5
}

s_escape()
{
	setescape(argv[1]);
}

I 5
s_label()
{
	struct ww *w;

	if ((w = idtowin(argv[1])) == 0)
		return;
	setlabel(w, argv[2]);
}

struct ww *
idtowin(idstr)
char *idstr;
{
	int id;
	struct ww *w = 0;

	id = atoi(idstr);
	if (id < 1 || id > 9 || (w = wwfind(id)) == 0)
		error("%d: No such window.", id);
	return w;
}

E 6
E 5
makeargv(p)
E 4
register char *p;
{
	static char buf[BUFSIZ];
	register char *q = buf, **pp = argv;
I 5
	char quote = 0, escape = 0;
	int i;
E 5

D 4
	for (; *p && *p != '\n' && (*p == ' ' || *p == '\t'); p++)
E 4
I 4
	for (; *p == ' ' || *p == '\t'; p++)
E 4
		;
D 4
	while (*p && *p != '\n' && pp < &argv[sizeof argv/sizeof *argv - 1]) {
E 4
I 4
	while (*p && *p != '\n' && *p != '#'
	       && pp < &argv[sizeof argv/sizeof *argv - 1]) {
E 4
		*pp++ = q;
D 4
		if (isalnum(*p)) {
			while (*p && *p != '\n' && *p != ' ' && *p != '\t')
				*q++ = *p++;
		} else
E 4
I 4
D 5
		while (*p && *p != '\n' && *p != ' ' && *p != '\t')
E 4
			*q++ = *p++;
E 5
I 5
		while (*p && *p != '\n') {
			if (escape) {
				switch (*p) {
				case 'n':
					*q++ = '\n';
I 8
					p++;
E 8
					break;
				case 'r':
					*q++ = '\r';
I 8
					p++;
E 8
					break;
				case '0': case '1': case '2': case '3':
				case '4': case '5': case '6': case '7':
					*q = 0;
					for (i = 3; --i >= 0
					     && *p >= '0' && *p <= '9';)
						*q = *q << 3 | *p++ - '0';
					q++;
					break;
				default:
					*q++ = *p++;
					break;
				}
				escape = 0;
			} else if (*p == '\\') {
D 8
				escape == 1;
E 8
I 8
				escape = 1;
				p++;
E 8
			} else if (quote) {
				if (*p == quote) {
					quote = 0;
					p++;
				} else
					*q++ = *p++;
			} else {
				if (*p == '"' || *p == '\'')
					quote = *p++;
				else if (*p == ' ' || *p == '\t')
					break;
				else
					*q++ = *p++;
			}
		}
E 5
		*q++ = 0;
D 4
		for (; *p && *p != '\n' && (*p == ' ' || *p == '\t'); p++)
E 4
I 4
		for (; *p == ' ' || *p == '\t'; p++)
E 4
			;
	}
	*pp = 0;
	argc = pp - argv;
}

D 6
/*VARARGS1*/
static
error(fmt, a, b, c, d, e, f, g, h)
char *fmt;
E 6
I 6
s_window()
E 6
{
I 5
D 6
	if (sourcefilename == 0) {
		wwprintf(cmdwin, fmt, a, b, c, d, e, f, g, h);
		wwprintf(cmdwin, ".  ");
E 6
I 6
	register char **pp = argv;
	register struct ww *w;
	int col, row, ncol, nrow, id;

	if ((id = findid()) < 0) {
		error("Too many windows.");
E 6
		return;
	}
E 5
D 6
#define ERRLINES 10
D 4
	if (errwin == 0) {
E 4
I 4
	if (errwin == 0 && !baderrwin) {
E 4
		char buf[512];
E 6
I 6
	if (**++pp == '*')
		row = 0;
	else
		row = atoi(*pp);
	if (**++pp == '*')
		col = 0;
	else
		col = atoi(*pp);
	if (**++pp == '*')
		nrow = wwnrow - row;
	else
		nrow = atoi(*pp);
	if (**++pp == '*')
		ncol = wwncol - col;
	else
		ncol = atoi(*pp);
	w = doopen(id, nrow, ncol, row, col);
	if (w == 0)
		error("Can't open window: row %d col %d, %d rows %d cols.",
			row, col, nrow, ncol);
}
E 6

D 6
		(void) sprintf(buf, "Errors from %s", sourcefilename);
		if ((errwin = openwin(ERRLINES, buf)) == 0) {
			wwprintf(cmdwin, "Can't open error window.  ");
D 4
			return -1;
E 4
I 4
			baderrwin++;
			return;
E 4
		}
		errlineno = 0;
	}
	if (errlineno++ > ERRLINES - 4) {
		waitnl(errwin);
		wwprintf(errwin, "\r\n");
		errlineno = 0;
	}
	wwprintf(errwin, "line %d: ", lineno);
	wwprintf(errwin, fmt, a, b, c, d, e, f, g, h);
	wwprintf(errwin, "\r\n");
E 6
I 6
s_select()
{
	struct ww *w;

	if ((w = idtowin(*argv + 1)) == 0)
		return;
	setselwin(w);
E 6
D 4
	return 0;
E 4
I 4
}

I 5
D 6
beginerror(filename)
char *filename;
E 6
I 6
s_escape()
E 6
{
D 6
	sourcefilename = filename;
E 6
I 6
	setescape(argv[1]);
E 6
}

E 5
D 6
enderror()
E 6
I 6
s_label()
E 6
{
D 6
	if (errwin != 0) {
		waitnl(errwin);
		closewin(errwin);
		errwin = 0;
	} else
		baderrwin = 0;
I 5
	sourcefilename = 0;
E 6
I 6
	struct ww *w;

	if ((w = idtowin(argv[1])) == 0)
		return;
	setlabel(w, argv[2]);
}

s_terse()
{
	if (argc < 2)
		terse = 1;
	else if (strcmp(argv[1], "off") == 0)
		terse = 0;
	else
		terse = 1;
	if (terse)
		Whide(cmdwin->ww_win);
	else
		Wunhide(cmdwin->ww_win);
}

s_refresh()
{
	struct ww *w;

	if ((w = idtowin(argv[1])) == 0)
		return;
	if (argc < 3)
		w->ww_refresh = 1;
	else if (strcmp(argv[2], "off") == 0)
		w->ww_refresh = 0;
	else
		w->ww_refresh = 1;
I 7
}

s_source()
{
	if (insource) {
		error("Recursive source.");
		return;
	}
	if (dosource(argv[1]) < 0)
		error("Can't open %s.", argv[1]);
I 8
}

s_write()
{
	struct ww *w;

	if ((w = idtowin(argv[1])) == 0)
		return;
	write(w->ww_pty, argv[2], strlen(argv[2]));
E 8
E 7
}

struct ww *
idtowin(idstr)
char *idstr;
{
	int id;
	struct ww *w = 0;

	id = atoi(idstr);
	if (id < 1 || id > 9 || (w = wwfind(id)) == 0)
		error("%d: No such window.", id);
	return w;
E 6
E 5
E 4
}
E 10
I 10
*/
E 12
E 10
E 1
