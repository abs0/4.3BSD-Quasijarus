h55348
s 00010/00005/00387
d D 3.33 88/06/29 21:36:03 bostic 35 34
c install approved copyright notice
e
s 00013/00007/00379
d D 3.32 88/02/21 13:37:00 bostic 34 33
c written by Edward Wang; attach Berkeley specific copyright
e
s 00030/00003/00356
d D 3.31 87/05/18 12:20:32 edward 33 32
c added keepopen and smooth flags, added + and - window selections
e
s 00006/00000/00353
d D 3.30 85/04/24 16:15:45 edward 32 31
c copyright messages
e
s 00001/00001/00352
d D 3.29 85/04/19 17:42:45 edward 31 30
c make default for l_debug() consistent with others
e
s 00012/00011/00341
d D 3.28 85/04/03 21:19:50 edward 30 28
c removed compatibility with old window, and some clean up
e
s 00012/00011/00341
d R 3.28 85/04/03 20:38:58 edward 29 28
c removed some compatibility with old window, and some clean up
e
s 00002/00031/00350
d D 3.27 84/11/20 23:39:54 edward 28 26
c we don't flush typeahead any more
e
s 00002/00031/00350
d R 3.27 84/11/20 23:17:58 edward 27 26
c lint
e
s 00052/00024/00329
d D 3.26 84/07/12 13:38:42 edward 26 25
c new ARG_LIST flag for commands
e
s 00008/00003/00345
d D 3.25 84/06/05 17:08:19 edward 25 24
c mapnl option to window
e
s 00001/00001/00347
d D 3.24 84/05/23 01:58:24 edward 24 23
c new sccs id
e
s 00001/00000/00347
d D 3.23 84/05/06 17:54:09 edward 23 22
c alias macros
e
s 00051/00007/00296
d D 3.22 84/04/08 19:23:24 edward 22 21
c new options to "window": shell, pty, frame
c and stuff to support them
e
s 00005/00001/00298
d D 3.21 84/04/08 12:08:40 edward 21 20
c control character expansion in wwwrite()
c calling of wwupdate() in wwwrite() dependent of ww_noupdate
c control character handling macros in char.h
e
s 00006/00003/00293
d D 3.20 84/04/06 23:16:29 edward 20 19
c shouldn't declare unused arguments registers
e
s 00021/00022/00275
d D 3.19 84/04/06 21:35:12 edward 19 18
c "C" removed, varargs added for "write" and "close"
e
s 00001/00025/00296
d D 3.18 84/04/05 00:56:49 edward 18 17
c no more background windows.
e
s 00001/00006/00320
d D 3.17 84/04/05 00:32:05 edward 17 16
c -c flag, incmd, setcmd(), setterse() added
e
s 00048/00001/00278
d D 3.16 84/03/29 00:03:09 edward 16 15
c foreground and background windows
e
s 00065/00073/00214
d D 3.15 84/03/23 18:16:51 edward 15 14
c compile with -R
e
s 00001/00001/00286
d D 3.14 84/01/13 17:16:11 edward 14 13
c lint
e
s 00027/00000/00260
d D 3.13 84/01/12 11:45:59 edward 13 12
c l_unset() added
e
s 00013/00000/00247
d D 3.12 84/01/11 17:28:40 edward 12 11
c l_debug() added
e
s 00008/00008/00239
d D 3.11 83/12/09 12:25:13 edward 11 10
c make l_window() accept "*" again
e
s 00018/00002/00229
d D 3.10 83/12/06 12:56:06 edward 10 9
c 'cursormodes' command added
e
s 00003/00014/00228
d D 3.9 83/11/30 11:55:45 edward 9 8
c lastselwin, and restructured some code
e
s 00004/00006/00238
d D 3.8 83/11/23 16:30:34 edward 8 7
c l_terse and l_select
e
s 00173/00056/00071
d D 3.7 83/11/22 19:57:48 edward 7 6
c new parser
e
s 00002/00008/00125
d D 3.6 83/08/26 16:26:27 edward 6 5
c error reporting
e
s 00014/00023/00119
d D 3.5 83/08/25 17:57:16 edward 5 4
c added user setable buffer size.
e
s 00004/00000/00138
d D 3.4 83/08/22 14:42:10 edward 4 3
c close all special case added to l_close()
e
s 00022/00000/00116
d D 3.3 83/08/12 11:47:05 edward 3 2
c close command
e
s 00000/00000/00116
d D 3.2 83/08/11 17:23:47 edward 2 1
i
c last few day's work
e
s 00116/00000/00000
d D 3.1 83/08/09 18:37:44 edward 1 0
c date and time created 83/08/09 18:37:44 by edward
e
u
U
t
T
I 1
D 34
#ifndef lint
D 24
static	char *sccsid = "%W% %E%";
E 24
I 24
static char sccsid[] = "%W% %G%";
E 24
#endif

E 34
I 32
/*
D 34
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 34
I 34
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 35
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 35
I 35
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
E 35
E 34
 */
I 34

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 34

E 32
#include "defs.h"
I 7
#include "string.h"
#include "value.h"
#include "lcmd.h"
I 23
#include "var.h"
E 23
E 7

D 5
struct ww *openwin();
struct ww *idtowin();

E 5
D 7
l_window()
E 7
I 7
struct lcmd_arg arg_window[] = {
D 11
	{ "row",	1,	ARG_NUM },
	{ "column",	1,	ARG_NUM },
	{ "nrows",	2,	ARG_NUM },
	{ "ncols",	2,	ARG_NUM },
E 11
I 11
D 26
	{ "row",	1,	ARG_ANY },
	{ "column",	1,	ARG_ANY },
	{ "nrows",	2,	ARG_ANY },
	{ "ncols",	2,	ARG_ANY },
E 26
I 26
	{ "row",	1,	ARG_NUM },
	{ "column",	1,	ARG_NUM },
	{ "nrows",	2,	ARG_NUM },
	{ "ncols",	2,	ARG_NUM },
E 26
E 11
	{ "nlines",	2,	ARG_NUM },
	{ "label",	1,	ARG_STR },
I 22
D 26
	{ "shell",	1,	ARG_STR },
E 26
	{ "pty",	1,	ARG_ANY },
	{ "frame",	1,	ARG_ANY },
I 25
	{ "mapnl",	1,	ARG_ANY },
I 33
	{ "keepopen",	1,	ARG_ANY },
	{ "smooth",	1,	ARG_ANY },
E 33
I 26
D 28
	{ "shell",	1,	ARG_ANY|ARG_LIST },
E 28
I 28
	{ "shell",	1,	ARG_STR|ARG_LIST },
E 28
E 26
E 25
E 22
D 15
	{ 0,		0,	0 }
E 15
I 15
	0
E 15
};

D 15
l_window(v)
register struct value *v;
E 15
I 15
l_window(v, a)
D 26
register struct value *v, *a;
E 26
I 26
struct value *v;
register struct value *a;
E 26
E 15
E 7
{
I 25
D 26
	register struct ww *w;
E 26
I 26
	struct ww *w;
E 26
E 25
D 7
	register char **pp = argv;
E 7
I 7
D 15
	register struct lcmd_arg *a = arg_window;
E 15
E 7
D 6
	register struct ww *w;
E 6
D 5
	int col, row, ncol, nrow, id;
E 5
I 5
	int col, row, ncol, nrow, id, nline;
I 7
	char *label;
I 22
D 25
	char haspty, hasframe;
E 25
I 25
D 33
	char haspty, hasframe, mapnl;
E 33
I 33
	char haspty, hasframe, mapnl, keepopen, smooth;
E 33
E 25
	char *shf, **sh;
	char *argv[sizeof shell / sizeof *shell];
I 26
	register char **pp;
E 26
E 22
E 7
E 5

D 6
	if ((id = findid()) < 0) {
		error("Too many windows.");
E 6
I 6
	if ((id = findid()) < 0)
E 6
		return;
D 6
	}
E 6
D 5
	if (**++pp == '*')
		row = 1;
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
	w = openwin(id, nrow, ncol, row, col);
E 5
I 5
D 7
	row = **++pp == '*' ? 1 : atoi(*pp);
	col = **++pp == '*' ? 0 : atoi(*pp);
	nrow = **++pp == '*' ? wwnrow - row : atoi(*pp);
	ncol = **++pp == '*' ? wwncol - col : atoi(*pp);
	nline = *++pp == 0 ? nbufline : atoi(*pp);
D 6
	w = openwin(id, row, col, nrow, ncol, nline);
E 5
	if (w == 0)
D 5
		error("Can't open window: row %d col %d, %d rows %d cols.",
			row, col, nrow, ncol);
E 5
I 5
		error("Can't open window: row %d col %d, %d rows %d cols %d lines.",
			row, col, nrow, ncol, nline);
E 6
I 6
	(void) openwin(id, row, col, nrow, ncol, nline);
E 7
I 7
D 11
	row = a->arg_vtype == V_ERR ? 1 : a->arg_num;
	col = (++a)->arg_vtype == V_ERR ? 0 : a->arg_num;
	nrow = (++a)->arg_vtype == V_ERR ? wwnrow - row : a->arg_num;
	ncol = (++a)->arg_vtype == V_ERR ? wwncol - col : a->arg_num;
E 11
I 11
D 15
	row = a->arg_vtype != V_NUM ? 1 : a->arg_num;
	col = (++a)->arg_vtype != V_NUM ? 0 : a->arg_num;
	nrow = (++a)->arg_vtype != V_NUM ? wwnrow - row : a->arg_num;
	ncol = (++a)->arg_vtype != V_NUM ? wwncol - col : a->arg_num;
E 11
	nline = (++a)->arg_vtype == V_ERR ? nbufline : a->arg_num;
	label =  (++a)->arg_vtype == V_ERR ? 0 : a->arg_str;
E 15
I 15
D 22
	row = a->v_type != V_NUM ? 1 : a->v_num;
	col = (++a)->v_type != V_NUM ? 0 : a->v_num;
	nrow = (++a)->v_type != V_NUM ? wwnrow - row : a->v_num;
	ncol = (++a)->v_type != V_NUM ? wwncol - col : a->v_num;
	nline = (++a)->v_type == V_ERR ? nbufline : a->v_num;
	label =  (++a)->v_type == V_ERR ? 0 : a->v_str;
E 15
	if (openwin(id, row, col, nrow, ncol, nline, label) == 0)
E 22
I 22
D 26
	row = a[0].v_type != V_NUM ? 1 : a[0].v_num;
	col = a[1].v_type != V_NUM ? 0 : a[1].v_num;
	nrow = a[2].v_type != V_NUM ? wwnrow - row : a[2].v_num;
	ncol = a[3].v_type != V_NUM ? wwncol - col : a[3].v_num;
	nline = a[4].v_type == V_ERR ? nbufline : a[4].v_num;
	label =  a[5].v_type == V_ERR ? 0 : a[5].v_str;
	if (a[6].v_type == V_STR) {
		if (mkargv(a[6].v_str, argv, sizeof argv / sizeof *argv) < 0)
			return;
		sh = argv;
		shf = *argv;
E 26
I 26
	row = a->v_type == V_ERR ? 1 : a->v_num;
	a++;
	col = a->v_type == V_ERR ? 0 : a->v_num;
	a++;
	nrow = a->v_type == V_ERR ? wwnrow - row : a->v_num;
	a++;
	ncol = a->v_type == V_ERR ? wwncol - col : a->v_num;
	a++;
	nline = a->v_type == V_ERR ? nbufline : a->v_num;
	a++;
	label = a->v_type == V_ERR ? 0 : a->v_str;
	if ((haspty = vtobool(++a, 1, -1)) < 0)
		return;
	if ((hasframe = vtobool(++a, 1, -1)) < 0)
		return;
	if ((mapnl = vtobool(++a, !haspty, -1)) < 0)
		return;
I 33
	if ((keepopen = vtobool(++a, 0, -1)) < 0)
		return;
	if ((smooth = vtobool(++a, 1, -1)) < 0)
		return;
E 33
	if ((++a)->v_type != V_ERR) {
		for (pp = argv; a->v_type != V_ERR &&
D 28
		     pp < &argv[sizeof argv/sizeof *argv-1]; pp++, a++) {
			if (a->v_type == V_NUM && p_convstr(a->v_num) < 0) {
				p_memerror();
				return;
			}
E 28
I 28
		     pp < &argv[sizeof argv/sizeof *argv-1]; pp++, a++)
E 28
			*pp = a->v_str;
D 28
		}
E 28
		*pp = 0;
		shf = *(sh = argv);
		if (*sh = rindex(shf, '/'))
			(*sh)++;
		else
			*sh = shf;
E 26
	} else {
		sh = shell;
		shf = shellfile;
	}
D 26
	if ((haspty = vtobool(a + 7, 1, -1)) < 0)
E 22
		return;
I 22
	if ((hasframe = vtobool(a + 8, 1, -1)) < 0)
		return;
D 25
	if (openwin(id, row, col, nrow, ncol, nline, label,
			haspty, hasframe, shf, sh) == 0)
E 25
I 25
	if ((mapnl = vtobool(a + 9, !haspty, -1)) < 0)
E 25
		return;
E 26
I 25
	if ((w = openwin(id, row, col, nrow, ncol, nline, label, haspty,
	    hasframe, shf, sh)) == 0)
		return;
	w->ww_mapnl = mapnl;
I 33
	w->ww_keepopen = keepopen;
	w->ww_noupdate = !smooth;
E 33
E 25
E 22
	v->v_type = V_NUM;
D 10
	v->v_num = id;
E 10
I 10
	v->v_num = id + 1;
E 10
E 7
E 6
}

D 7
l_buffer()
E 7
I 7
D 19
struct lcmd_arg arg_buffer[] = {
E 19
I 19
struct lcmd_arg arg_nline[] = {
E 19
	{ "nlines",	1,	ARG_NUM },
D 15
	{ 0,		0,	0 }
E 15
I 15
	0
E 15
};

D 15
l_buffer(v)
struct value *v;
E 15
I 15
D 19
l_buffer(v, a)
E 19
I 19
l_nline(v, a)
E 19
register struct value *v, *a;
E 15
E 7
{
D 7
	nbufline = atoi(argv[1]);
E 7
I 7
	v->v_num = nbufline;
	v->v_type = V_NUM;
D 15
	if (arg_buffer[0].arg_vtype != V_ERR)
		nbufline = arg_buffer[0].arg_num;
E 15
I 15
	if (a->v_type != V_ERR)
		nbufline = a->v_num;
E 15
E 7
E 5
}

I 33
struct lcmd_arg arg_smooth[] = {
	{ "window",	1,	ARG_NUM },
	{ "flag",	1,	ARG_ANY },
	0
};

l_smooth(v, a)
register struct value *v, *a;
{
	struct ww *w;

	v->v_type = V_NUM;
	v->v_num = 0;
	if ((w = vtowin(a++, selwin)) == 0)
		return;
	v->v_num = !w->ww_noupdate;
	w->ww_noupdate = !vtobool(a, v->v_num, v->v_num);
}

E 33
D 7
l_select()
E 7
I 7
struct lcmd_arg arg_select[] = {
	{ "window",	1,	ARG_NUM },
D 15
	{ 0,		0,	0 }
E 15
I 15
	0
E 15
};

D 15
l_select(v)
struct value *v;
E 15
I 15
l_select(v, a)
register struct value *v, *a;
E 15
E 7
{
	struct ww *w;

D 7
	if ((w = idtowin(*argv + 1)) == 0)
E 7
I 7
	v->v_type = V_NUM;
D 10
	v->v_num = selwin ? selwin->ww_id : -1;
E 10
I 10
	v->v_num = selwin ? selwin->ww_id + 1 : -1;
E 10
D 15
	if (arg_select[0].arg_vtype == V_ERR)
E 15
I 15
	if (a->v_type == V_ERR)
E 15
E 7
		return;
I 7
D 8
	if ((w = window[arg_select[0].arg_num]) == 0) {
		error("%d: No such window.", arg_select[0].arg_num);
E 8
I 8
D 15
	if ((w = vtowin(&arg_select[0].arg_val)) == 0)
E 15
I 15
D 30
	if ((w = vtowin(a)) == 0)
E 30
I 30
	if ((w = vtowin(a, (struct ww *)0)) == 0)
E 30
E 15
E 8
		return;
D 8
	}
E 8
E 7
	setselwin(w);
}

I 12
struct lcmd_arg arg_debug[] = {
	{ "flag",	1,	ARG_ANY },
D 19
	{ 0,		0,	0 }
E 19
I 19
	0
E 19
};

D 15
l_debug(v)
struct value *v;
E 15
I 15
l_debug(v, a)
register struct value *v, *a;
E 15
{
	v->v_type = V_NUM;
	v->v_num = debug;
D 15
	debug = vtobool(&arg_debug[0].arg_val, 1, debug);
E 15
I 15
D 31
	debug = vtobool(a, 1, debug);
E 31
I 31
	debug = vtobool(a, debug, debug);
E 31
E 15
}

E 12
D 7
l_escape()
E 7
I 7
struct lcmd_arg arg_escape[] = {
D 15
	{ "escapec",	1,	ARG_NUM },
	{ 0,		0,	0 }
E 15
I 15
	{ "escapec",	1,	ARG_STR },
	0
E 15
};

D 15
l_escape(v)
struct value *v;
E 15
I 15
l_escape(v, a)
register struct value *v, *a;
E 15
E 7
{
D 7
	setescape(argv[1]);
E 7
I 7
D 21
	if ((v->v_str = str_cpy(unctrl(escapec))) == 0) {
E 21
I 21
	char buf[2];

	buf[0] = escapec;
	buf[1] = 0;
	if ((v->v_str = str_cpy(buf)) == 0) {
E 21
		error("Out of memory.");
		return;
	}
	v->v_type = V_STR;
D 15
	if (arg_escape[0].arg_type != V_ERR)
		setescape(arg_escape[0].arg_str);
E 15
I 15
	if (a->v_type != V_ERR)
		setescape(a->v_str);
E 15
E 7
}

D 7
l_label()
E 7
I 7
struct lcmd_arg arg_label[] = {
	{ "window",	1,	ARG_NUM },
	{ "label",	1,	ARG_STR },
D 15
	{ 0,		0,	0 }
E 15
I 15
	0
E 15
};

/*ARGSUSED*/
D 15
l_label(v)
struct value *v;
E 15
I 15
l_label(v, a)
D 20
register struct value *v, *a;
E 20
I 20
struct value *v;
register struct value *a;
E 20
E 15
E 7
{
	struct ww *w;
I 7
D 15
	register struct lcmd_arg *a = arg_label;
E 15
E 7

D 7
	if ((w = idtowin(argv[1])) == 0)
E 7
I 7
D 15
	if ((w = vtowin(&a->arg_val)) == 0)
E 15
I 15
D 30
	if ((w = vtowin(a)) == 0)
E 30
I 30
	if ((w = vtowin(a, selwin)) == 0)
E 30
E 15
E 7
		return;
D 7
	if (setlabel(w, argv[2]) < 0)
E 7
I 7
D 15
	if ((++a)->arg_vtype != V_ERR && setlabel(w, a->arg_str) < 0)
E 15
I 15
	if ((++a)->v_type != V_ERR && setlabel(w, a->v_str) < 0)
E 15
E 7
		error("Out of memory.");
	reframe();
}

I 16
struct lcmd_arg arg_foreground[] = {
	{ "window",	1,	ARG_NUM },
	{ "flag",	1,	ARG_ANY },
	0
};

l_foreground(v, a)
register struct value *v, *a;
{
	struct ww *w;
	char flag;

D 30
	if ((w = vtowin(a)) == 0)
E 30
I 30
	if ((w = vtowin(a, selwin)) == 0)
E 30
		return;
	v->v_type = V_NUM;
	v->v_num = isfg(w);
D 30
	flag = vtobool(++a, 1, v->v_num);
E 30
I 30
	flag = vtobool(++a, v->v_num, v->v_num);
E 30
	if (flag == v->v_num)
		return;
	deletewin(w);
D 18
	addwin(w, flag ? 0 : 1);
	reframe();
}

struct lcmd_arg arg_background[] = {
	{ "window",	1,	ARG_NUM },
	{ "flag",	1,	ARG_ANY },
	0
};

l_background(v, a)
register struct value *v, *a;
{
	struct ww *w;
	char flag;

	if ((w = vtowin(a)) == 0)
		return;
	v->v_type = V_NUM;
	v->v_num = isbg(w);
	flag = vtobool(++a, 1, v->v_num);
	if (flag == v->v_num)
		return;
	deletewin(w);
	addwin(w, flag ? 3 : 2);
E 18
I 18
	addwin(w, flag);
E 18
	reframe();
}

E 16
D 7
l_terse()
{
	char oldterse = terse;
E 7
I 7
struct lcmd_arg arg_terse[] = {
D 8
	{ "flag",	1,	ARG_NUM },
E 8
I 8
	{ "flag",	1,	ARG_ANY },
E 8
D 15
	{ 0,		0,	0 }
E 15
I 15
	0
E 15
};
E 7

D 7
	if (argc < 2)
		terse = 1;
	else if (strcmp(argv[1], "off") == 0)
		terse = 0;
	else
		terse = 1;
	if (terse && !oldterse)
E 7
I 7
D 15
l_terse(v)
struct value *v;
E 15
I 15
l_terse(v, a)
register struct value *v, *a;
E 15
{
	v->v_type = V_NUM;
	v->v_num = terse;
D 15
	terse = vtobool(&arg_terse[0].arg_val, 1, terse);
E 15
I 15
D 17
	terse = vtobool(a, 1, terse);
E 15
	if (!terse && v->v_num)
E 7
D 8
		wwdelete(cmdwin);
D 7
	else if (!terse && oldterse)
E 7
I 7
	else if (!v->v_num && terse)
E 8
E 7
		wwadd(cmdwin, &wwhead);
I 8
	else if (!v->v_num && terse)
		wwdelete(cmdwin);
E 8
	reframe();
E 17
I 17
D 30
	setterse(vtobool(a, 1, terse));
E 30
I 30
	setterse(vtobool(a, terse, terse));
E 30
E 17
}

D 7
l_source()
E 7
I 7
struct lcmd_arg arg_source[] = {
	{ "filename",	1,	ARG_STR },
D 15
	{ 0,		0,	0 }
E 15
I 15
	0
E 15
};

D 16
/*ARGSUSED*/
E 16
D 15
l_source(v)
struct value *v;
E 15
I 15
l_source(v, a)
register struct value *v, *a;
E 15
E 7
{
D 7
	if (insource) {
		error("Recursive source.");
		return;
	}
	if (dosource(argv[1]) < 0)
		error("Can't open %s.", argv[1]);
E 7
I 7
D 15
	if (arg_source[0].arg_vtype != V_ERR
	    && dosource(arg_source[0].arg_str) < 0) {
		error("Can't open %s.", arg_source[0].arg_str);
E 15
I 15
	v->v_type = V_NUM;
	if (a->v_type != V_ERR && dosource(a->v_str) < 0) {
		error("Can't open %s.", a->v_str);
E 15
		v->v_num = -1;
	} else
		v->v_num = 0;
D 15
	v->v_type = V_NUM;
E 15
E 7
}

I 26
struct lcmd_arg arg_write[] = {
	{ "window",	1,	ARG_NUM },
	{ "",		0,	ARG_ANY|ARG_LIST },
	0
};

E 26
D 7
l_write()
E 7
I 7
D 19
struct lcmd_arg arg_write[] = {
	{ "window",	1,	ARG_NUM },
	{ "string",	1,	ARG_STR },
D 15
	{ 0,		0,	0 }
E 15
I 15
	0
E 15
};

E 19
/*ARGSUSED*/
D 15
l_write(v)
struct value *v;
E 15
I 15
l_write(v, a)
D 20
register struct value *v, *a;
E 20
I 20
struct value *v;
register struct value *a;
E 20
E 15
E 7
{
I 19
	char buf[20];
E 19
I 7
D 15
	register struct lcmd_arg *a = arg_write;
E 15
E 7
	struct ww *w;

D 7
	if ((w = idtowin(argv[1])) == 0)
E 7
I 7
D 15
	if ((w = vtowin(&a->arg_val)) == 0)
E 15
I 15
D 19
	if ((w = vtowin(a)) == 0)
E 19
I 19
D 30
	if ((w = vtowin(a++)) == 0)
E 30
I 30
	if ((w = vtowin(a++, selwin)) == 0)
E 30
E 19
E 15
E 7
		return;
D 7
	(void) write(w->ww_pty, argv[2], strlen(argv[2]));
E 7
I 7
D 19
	a++;
D 15
	(void) write(w->ww_pty, a->arg_str, strlen(a->arg_str));
E 15
I 15
	(void) write(w->ww_pty, a->v_str, strlen(a->v_str));
E 19
I 19
	while (a->v_type != V_ERR) {
		if (a->v_type == V_NUM) {
			(void) sprintf(buf, "%d", a->v_num);
			(void) write(w->ww_pty, buf, strlen(buf));
		} else
			(void) write(w->ww_pty, a->v_str, strlen(a->v_str));
		if ((++a)->v_type != V_ERR)
			(void) write(w->ww_pty, " ", 1);
	}
E 19
E 15
E 7
}
I 26

struct lcmd_arg arg_close[] = {
	{ "window",	1,	ARG_ANY|ARG_LIST },
	0
};
E 26

I 3
D 7
l_close()
E 7
I 7
D 19
struct lcmd_arg arg_close[] = {
	{ "window",	1,	ARG_NUM },
D 15
	{ 0,		0,	0 }
E 15
I 15
	0
E 15
};

E 19
/*ARGSUSED*/
D 15
l_close(v)
struct value *v;
E 15
I 15
l_close(v, a)
D 20
register struct value *v, *a;
E 20
I 20
struct value *v;
register struct value *a;
E 20
E 15
E 7
{
I 7
D 15
	register struct lcmd_arg *a = arg_close;
E 15
E 7
D 9
	register i;
E 9
D 7
	register struct ww *w;
	char didit = 0;
E 7
I 7
	struct ww *w;
E 7

I 4
D 7
	if (argc < 2) {
E 7
I 7
D 9
	if (a->arg_vtype == V_ERR) {
E 9
I 9
D 15
	if (a->arg_vtype == V_ERR)
E 15
I 15
D 19
	if (a->v_type == V_ERR)
E 19
I 19
D 30
	if (a->v_type == V_STR && str_match(a->v_str, "all", 1))
E 30
I 30
	if (a->v_type == V_STR && str_match(a->v_str, "all", 3))
E 30
E 19
E 15
E 9
E 7
D 33
		c_close((struct ww *)0);
E 33
I 33
		closewin((struct ww *)0);
E 33
D 9
		return;
	}
E 4
D 7
	for (i = 1; i < argc; i++) {
		if ((w = idtowin(argv[i])) == 0)
			continue;
		closewin(w);
		didit++;
	}
E 7
I 7
	if ((w = vtowin(&a->arg_val)) == 0)
		return;
	closewin(w);
E 7
	if (selwin == 0) {
		for (i = 0; i < NWINDOW && window[i] != 0; i++)
			;
		if (i < NWINDOW)
			setselwin(window[i]);
	}
D 7
	if (didit)
		reframe();
E 7
I 7
	reframe();
E 9
I 9
D 15
	else if ((w = vtowin(&a->arg_val)) != 0)
E 15
I 15
D 19
	else if ((w = vtowin(a)) != 0)
E 15
		c_close(w);
E 19
I 19
	else
		for (; a->v_type != V_ERR; a++)
D 30
			if ((w = vtowin(a)) != 0)
E 30
I 30
			if ((w = vtowin(a, (struct ww *)0)) != 0)
E 30
D 33
				c_close(w);
E 33
I 33
				closewin(w);
E 33
E 19
I 10
}

struct lcmd_arg arg_cursormodes[] = {
	{ "modes",	1,	ARG_NUM },
D 15
	{ 0,		0,	0 }
E 15
I 15
	0
E 15
};

D 15
l_cursormodes(v)
register struct value *v;
E 15
I 15
l_cursormodes(v, a)
register struct value *v, *a;
E 15
{
D 15
	register struct lcmd_arg *a = arg_cursormodes;
E 15

	v->v_type = V_NUM;
	v->v_num = wwcursormodes;
D 15
	if (a->arg_vtype != V_ERR)
		wwsetcursormodes(a->arg_num);
E 15
I 15
	if (a->v_type != V_ERR)
		wwsetcursormodes(a->v_num);
E 15
E 10
E 9
E 7
}

I 13
struct lcmd_arg arg_unset[] = {
	{ "variable",	1,	ARG_ANY },
D 15
	{ 0,		0,	0 }
E 15
I 15
	0
E 15
};

D 15
l_unset(v)
register struct value *v;
E 15
I 15
l_unset(v, a)
register struct value *v, *a;
E 15
{
D 15
	register struct lcmd_arg *a = arg_unset;

E 15
	v->v_type = V_NUM;
D 15
	switch (a->arg_vtype) {
E 15
I 15
	switch (a->v_type) {
E 15
	case V_ERR:
		v->v_num = -1;
		return;
	case V_NUM:
D 14
		if ((a->arg_str = str_cpy(a->arg_num)) == 0) {
E 14
I 14
D 15
		if ((a->arg_str = str_itoa(a->arg_num)) == 0) {
E 15
I 15
		if ((a->v_str = str_itoa(a->v_num)) == 0) {
E 15
E 14
			error("Out of memory.");
			v->v_num = -1;
			return;
		}
D 15
		a->arg_vtype = V_STR;
E 15
I 15
		a->v_type = V_STR;
E 15
		break;
	}
D 15
	v->v_num = var_unset(a->arg_str);
E 15
I 15
	v->v_num = var_unset(a->v_str);
E 15
}

E 13
E 3
struct ww *
D 7
idtowin(idstr)
char *idstr;
E 7
I 7
D 30
vtowin(v)
E 30
I 30
vtowin(v, w)
E 30
register struct value *v;
I 30
struct ww *w;
E 30
E 7
{
D 7
	register id;
E 7
D 30
	struct ww *w;

E 30
D 7
	id = atoi(idstr) - 1;
	if (id < 0 || id >= NWINDOW || (w = window[id]) == 0) {
		error("%d: No such window.", id + 1);
E 7
I 7
	switch (v->v_type) {
	case V_ERR:
I 30
		if (w != 0)
			return w;
E 30
D 19
		error("Window identifier required.");
E 19
I 19
		error("No window specified.");
E 19
E 7
		return 0;
I 7
	case V_STR:
D 19
		error("Number required for window identifier.");
E 19
I 19
		error("%s: No such window.", v->v_str);
E 19
		return 0;
E 7
	}
I 7
	if (v->v_num < 1 || v->v_num > NWINDOW
	    || (w = window[v->v_num - 1]) == 0) {
		error("%d: No such window.", v->v_num);
		return 0;
	}
E 7
	return w;
I 7
}

vtobool(v, def, err)
register struct value *v;
char def, err;
{
	switch (v->v_type) {
	case V_NUM:
		return v->v_num != 0;
	case V_STR:
		if (str_match(v->v_str, "true", 1)
		    || str_match(v->v_str, "on", 2)
		    || str_match(v->v_str, "yes", 1))
			return 1;
		else if (str_match(v->v_str, "false", 1)
		    || str_match(v->v_str, "off", 2)
		    || str_match(v->v_str, "no", 1))
			return 0;
		else {
			error("%s: Illegal boolean value.", v->v_str);
			return err;
		}
		/*NOTREACHED*/
	case V_ERR:
		return def;
	}
	/*NOTREACHED*/
I 22
D 28
}

mkargv(p, argv, n)
register char *p;
register char **argv;
register n;
{
	while (--n > 0) {
		for (; *p && (*p == ' ' || *p == '\t'); p++)
			;
		if (!*p)
			break;
		*argv++ = p;
		for (; *p && *p != ' ' && *p != '\t'; p++)
			;
		if (*p)
			*p++ = 0;
	}
	if (n == 0) {
		error("Too many shell arguments.");
		return -1;
	}
	*argv = 0;
	return 0;
E 28
E 22
E 7
}
E 1
