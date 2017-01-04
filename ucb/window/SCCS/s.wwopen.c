h63829
s 00010/00005/00167
d D 3.25 88/06/29 21:38:30 bostic 33 32
c install approved copyright notice
e
s 00013/00007/00159
d D 3.24 88/02/21 13:38:40 bostic 32 31
c written by Edward Wang; attach Berkeley specific copyright
e
s 00001/00001/00165
d D 3.23 86/08/05 01:24:31 edward 31 30
c lint
e
s 00004/00001/00162
d D 3.22 86/08/05 00:16:03 edward 30 29
c make sure unavailable mode bits are not set,
c so wwupdate1() doesn't have to mask them out.
e
s 00006/00000/00157
d D 3.21 85/04/24 16:11:09 edward 29 28
c copyright messages
e
s 00001/00001/00156
d D 3.20 85/04/03 22:20:31 edward 28 27
c lint, and others
e
s 00012/00002/00145
d D 3.19 85/03/01 17:40:51 edward 27 26
c changing window size and new WINSZ ioctl
e
s 00001/00001/00146
d D 3.18 84/11/20 23:39:46 edward 26 25
c we don't flush typeahead any more
e
s 00001/00001/00146
d D 3.17 84/05/23 01:56:22 edward 25 24
c new sccs id
e
s 00022/00003/00125
d D 3.16 84/04/08 19:22:31 edward 24 23
c new options to "window": shell, pty, frame
c and stuff to support them
e
s 00006/00000/00122
d D 3.15 84/01/16 15:25:03 edward 23 22
c new io scheme
e
s 00002/00005/00120
d D 3.14 83/12/01 13:43:20 edward 22 21
c pty hanging bug
e
s 00000/00010/00125
d D 3.13 83/11/23 16:34:41 edward 21 20
c New cover scheme
e
s 00036/00019/00099
d D 3.12 83/09/15 10:08:32 edward 20 19
c Now uses screen address for all buffers.
e
s 00013/00009/00105
d D 3.11 83/09/14 14:13:58 edward 19 18
c Off screen windows!!!!!!
e
s 00006/00005/00108
d D 3.10 83/08/26 17:22:15 edward 18 17
c pty closing bug (don't set ww_haspty until it actually does).
e
s 00002/00000/00111
d D 3.9 83/08/26 16:46:13 edward 17 16
c forgot to free ww_fmap after an error
e
s 00018/00015/00093
d D 3.8 83/08/26 16:23:36 edward 16 15
c error reporting
e
s 00016/00016/00092
d D 3.7 83/08/23 18:16:41 edward 15 14
c don't set wwindex[] until very end.
c also rearranged the order of things a bit.
e
s 00002/00000/00106
d D 3.6 83/08/22 16:05:58 edward 14 13
c forgot to check size <= 0
e
s 00001/00001/00105
d D 3.5 83/08/22 15:58:35 edward 13 12
c > instead of >=
e
s 00002/00000/00104
d D 3.4 83/08/22 15:35:52 edward 12 11
c bounds checking in wwopen()
e
s 00009/00000/00095
d D 3.3 83/08/19 17:32:32 edward 11 10
c moved fmap into struct ww and added WWO_FRAME to allocate it.
e
s 00004/00004/00091
d D 3.2 83/08/19 12:20:39 edward 10 9
c wwfree changed
e
s 00000/00000/00095
d D 3.1 83/08/11 17:21:17 edward 9 7
i 8
c last few day's work
e
s 00070/00067/00025
d D 2.1.1.1 83/08/09 18:34:16 edward 8 7
c mile stone
e
s 00000/00000/00092
d D 2.1 83/07/30 13:27:01 edward 7 6
c prepare for major change
e
s 00001/00001/00091
d D 1.6 83/07/29 18:22:07 edward 6 5
c wwwintty added, and turn off XTABS for the ptys.
e
s 00008/00006/00084
d D 1.5 83/07/22 17:07:54 edward 5 4
c scrolling.
c uses Wscreensize() to get screen size.
c More intelligent framing.
c etc.
e
s 00003/00002/00087
d D 1.4 83/07/19 20:07:38 edward 4 3
c today's work
e
s 00020/00008/00069
d D 1.3 83/07/18 21:03:00 edward 3 2
c multiple window
e
s 00012/00043/00065
d D 1.2 83/07/17 15:42:18 edward 2 1
c 
e
s 00108/00000/00000
d D 1.1 83/07/12 17:20:59 edward 1 0
c date and time created 83/07/12 17:20:59 by edward
e
u
U
f b 
t
T
I 1
D 32
#ifndef lint
D 25
static	char *sccsid = "%W% %E%";
E 25
I 25
static char sccsid[] = "%W% %G%";
E 25
#endif

E 32
I 29
/*
D 32
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 32
I 32
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 33
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 33
I 33
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
E 33
E 32
 */
I 32

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 32

E 29
#include "ww.h"
I 24
#include <sys/types.h>
#include <sys/socket.h>
E 24
D 8
#include <sys/types.h>
#include <sys/stat.h>
E 8

D 2
extern int _wwiflag;
struct ww *_wwhead = 0;

E 2
struct ww *
D 2
wwopen(nrow, ncol, row, col)
E 2
I 2
D 3
wwopen(id, nrow, ncol, row, col)
E 3
I 3
D 4
wwopen(flag, id, nrow, ncol, row, col)
E 4
I 4
D 8
wwopen(mode, id, nrow, ncol, row, col)
E 8
I 8
wwopen(flags, nrow, ncol, row, col, nline)
E 8
E 4
E 3
E 2
{
D 2
	register struct ww *w;
E 2
I 2
D 18
	register struct ww *w = 0;
E 18
I 18
	register struct ww *w;
E 18
I 8
	register i, j;
	char m;
	short nvis;
E 8
E 2

I 14
D 15
	if (nrow <= 0 || ncol <= 0)
		return 0;
E 14
I 12
D 13
	if (row < 0 || row + nrow >= wwnrow || col < 0 || col + ncol >= wwncol)
E 13
I 13
	if (row < 0 || row + nrow > wwnrow || col < 0 || col + ncol > wwncol)
E 13
		return 0;
E 15
I 15
	w = (struct ww *)calloc(sizeof (struct ww), 1);
D 16
	if (w == 0)
E 16
I 16
	if (w == 0) {
		wwerrno = WWE_NOMEM;
E 16
		goto bad;
I 16
	}
I 22
	w->ww_pty = -1;
I 24
	w->ww_socket = -1;
E 24
E 22
E 16

E 15
E 12
D 8
	w = (struct ww *)calloc(sizeof (struct ww), 1);
E 8
I 8
	for (i = 0; i < NWW && wwindex[i] != 0; i++)
		;
D 16
	if (i >= NWW)
E 16
I 16
	if (i >= NWW) {
		wwerrno = WWE_TOOMANY;
E 16
D 15
		return 0;
	wwindex[i] = w = (struct ww *)calloc(sizeof (struct ww), 1);
E 8
	if (w == 0)
E 15
		goto bad;
I 16
	}
E 16
D 2
	if (wwgettchars(w) < 0)
		goto bad;
E 2
D 3
	if (wwgetpty(w) < 0)
E 3
I 3
D 8
	w->ww_pty = w->ww_tty = -1;
D 4
	switch (flag) {
E 4
I 4
	switch (mode) {
E 4
	case WW_PTY:
E 8
I 8
	w->ww_index = i;
D 15
	w->ww_pty = w->ww_tty = -1;	/* closing by mistake is still safe */
	if (flags & WWO_PTY) {
		w->ww_haspty = 1;
E 8
		if (wwgetpty(w) < 0)
			goto bad;
D 6
		if (wwsettty(w->ww_pty, &wwoldtty) < 0)
E 6
I 6
		if (wwsettty(w->ww_pty, &wwwintty) < 0)
E 6
			goto bad;
D 8
		break;
	case WW_SOCKET:
		break;
	case WW_NONE:
		break;
	default:
E 3
		goto bad;
E 8
D 2
	if (!_wwiflag)
		wwinit();
	if ((w->ww_win = newwin(nrow, ncol, row, col)) == 0)
E 2
I 2
D 3
	if (wwsettty(w->ww_pty, &wwoldtty) < 0)
E 2
		goto bad;
E 3
I 3
	}
E 15
E 3
I 2
D 5
	if ((w->ww_win = Wopen(id, col, row, ncol, nrow, ncol, nrow)) == 0)
E 5
I 5
D 8
	if ((w->ww_win = Wopen(id, col, row, ncol, nrow, ncol, 48)) == 0)
E 8
I 8

I 20
	if (nline < nrow)
		nline = nrow;

E 20
I 15
D 16
	if (nrow <= 0 || ncol <= 0)
E 16
I 16
D 19
	if ((w->ww_w.nr = nrow) <= 0
	    || (w->ww_w.nc = ncol) <= 0
	    || (w->ww_w.l = col) < 0
	    || (w->ww_w.r = col + ncol) > wwncol
	    || (w->ww_w.t = row) < 0
	    || (w->ww_w.b = row + nrow) > wwnrow) {
		wwerrno = WWE_SIZE;
E 16
		goto bad;
E 15
D 16
	if ((w->ww_w.l = col) < 0)
E 8
E 5
		goto bad;
D 8
	Woncursor(w->ww_win, 0);		/* don't show cursor */
I 4
	w->ww_mode = mode;
E 4
E 2
D 3
	w->ww_col = col;
	w->ww_row = row;
	w->ww_ncol = ncol;
	w->ww_nrow = nrow;
E 3
I 3
	w->ww_ident = id;
D 5
	w->ww_icol = w->ww_col = col;
	w->ww_irow = w->ww_row = row;
	w->ww_incol = w->ww_ncol = ncol;
	w->ww_inrow = w->ww_nrow = nrow;
E 5
I 5
	w->ww_w.col = w->ww_i.col = w->ww_o.col = col;
	w->ww_w.row = w->ww_i.row = w->ww_o.row = row;
	w->ww_w.ncol = w->ww_i.ncol = w->ww_o.ncol = ncol;
	w->ww_w.nrow = w->ww_i.nrow = w->ww_o.nrow = nrow;
E 5
E 3
D 2
	w->ww_next = _wwhead;
E 2
I 2
	w->ww_next = wwhead;
E 2
	w->ww_state = WW_INITIAL;
D 2
	_wwhead = w;
E 2
I 2
	wwhead = w;
E 8
I 8
	if ((w->ww_w.r = col + ncol) > wwncol)
		goto bad;
	if ((w->ww_w.t = row) < 0)
		goto bad;
	if ((w->ww_w.b = row + nrow) > wwnrow)
		goto bad;
	w->ww_w.nc = ncol;
	w->ww_w.nr = nrow;
E 16
I 16
	}
E 19
I 19
	w->ww_w.t = row;
	w->ww_w.b = row + nrow;
	w->ww_w.l = col;
	w->ww_w.r = col + ncol;
	w->ww_w.nr = nrow;
	w->ww_w.nc = ncol;
I 20

	w->ww_b.t = row;
	w->ww_b.b = row + nline;
	w->ww_b.l = col;
	w->ww_b.r = col + ncol;
	w->ww_b.nr = nline;
	w->ww_b.nc = ncol;

E 20
	w->ww_i.t = MAX(w->ww_w.t, 0);
	w->ww_i.b = MIN(w->ww_w.b, wwnrow);
	w->ww_i.l = MAX(w->ww_w.l, 0);
	w->ww_i.r = MIN(w->ww_w.r, wwncol);
	w->ww_i.nr = w->ww_i.b - w->ww_i.t;
	w->ww_i.nc = w->ww_i.r - w->ww_i.l;

E 19
E 16
D 20
	w->ww_nline = MAX(nline, w->ww_w.nr);
E 20
I 20
	w->ww_cur.r = w->ww_w.t;
	w->ww_cur.c = w->ww_w.l;
E 20

I 15
D 18
	w->ww_pty = w->ww_tty = -1;	/* closing by mistake is still safe */
E 18
	if (flags & WWO_PTY) {
I 27
		struct winsize winsize;

E 27
D 18
		w->ww_haspty = 1;
E 18
		if (wwgetpty(w) < 0)
			goto bad;
I 18
D 22
		w->ww_haspty = 1;
E 22
E 18
D 26
		if (wwsettty(w->ww_pty, &wwwintty) < 0)
E 26
I 26
		if (wwsettty(w->ww_pty, &wwwintty, (struct ww_tty *)0) < 0)
E 26
			goto bad;
I 27
		winsize.ws_row = nrow;
		winsize.ws_col = ncol;
		winsize.ws_xpixel = winsize.ws_ypixel = 0;
D 28
		if (ioctl(w->ww_pty, TIOCSWINSZ, (char *)&winsize) < 0) {
E 28
I 28
D 31
		if (ioctl(w->ww_pty, (int)TIOCSWINSZ, (char *)&winsize) < 0) {
E 31
I 31
		if (ioctl(w->ww_pty, TIOCSWINSZ, (char *)&winsize) < 0) {
E 31
E 28
			wwerrno = WWE_SYS;
			goto bad;
		}
E 27
I 23
D 24
		if ((w->ww_ob = malloc(512)) == 0)
E 24
I 24
		w->ww_ispty = 1;
	} else if (flags & WWO_SOCKET) {
		int d[2];
		if (socketpair(AF_UNIX, SOCK_STREAM, PF_UNSPEC, d) < 0) {
			wwerrno = WWE_SYS;
E 24
			goto bad;
I 24
		}
		w->ww_pty = d[0];
		w->ww_socket = d[1];
	}
	if (flags & (WWO_PTY|WWO_SOCKET)) {
		if ((w->ww_ob = malloc(512)) == 0) {
			wwerrno = WWE_NOMEM;
			goto bad;
		}
E 24
		w->ww_obe = w->ww_ob + 512;
D 24
		w->ww_obp = w->ww_ob;
E 24
I 24
		w->ww_obp = w->ww_obq = w->ww_ob;
E 24
E 23
	}

E 15
D 20
	w->ww_win = wwalloc(w->ww_w.nr, w->ww_w.nc, sizeof (char));
E 20
I 20
	w->ww_win = wwalloc(w->ww_w.t, w->ww_w.l,
		w->ww_w.nr, w->ww_w.nc, sizeof (char));
E 20
	if (w->ww_win == 0)
		goto bad;
	m = 0;
	if (flags & WWO_GLASS)
		m |= WWM_GLS;
	if (flags & WWO_REVERSE)
D 30
		m |= WWM_REV;
E 30
I 30
		if (wwavailmodes & WWM_REV)
			m |= WWM_REV;
		else
			flags &= ~WWO_REVERSE;
E 30
D 20
	for (i = 0; i < w->ww_w.nr; i++)
		for (j = 0; j < w->ww_w.nc; j++)
E 20
I 20
	for (i = w->ww_w.t; i < w->ww_w.b; i++)
		for (j = w->ww_w.l; j < w->ww_w.r; j++)
E 20
			w->ww_win[i][j] = m;
D 21
	
D 20
	w->ww_cov = wwalloc(w->ww_w.nr, w->ww_w.nc, sizeof (char));
E 20
I 20
	w->ww_cov = wwalloc(w->ww_w.t, w->ww_w.l,
		w->ww_w.nr, w->ww_w.nc, sizeof (char));
E 20
	if (w->ww_cov == 0)
		goto bad;
D 20
	for (i = 0; i < w->ww_w.nr; i++)
		for (j = 0; j < w->ww_w.nc; j++)
E 20
I 20
	for (i = w->ww_w.t; i < w->ww_w.b; i++)
		for (j = w->ww_w.l; j < w->ww_w.r; j++)
E 20
			w->ww_cov[i][j] = WWX_NOBODY;
E 21
I 11

	if (flags & WWO_FRAME) {
D 20
		w->ww_fmap = wwalloc(w->ww_w.nr, w->ww_w.nc, sizeof (char));
E 20
I 20
		w->ww_fmap = wwalloc(w->ww_w.t, w->ww_w.l,
			w->ww_w.nr, w->ww_w.nc, sizeof (char));
E 20
		if (w->ww_fmap == 0)
D 16
			goto bad;
E 16
I 16
D 27
			wwerrno = WWE_NOMEM;
E 27
I 27
			goto bad;
E 27
E 16
D 20
		for (i = 0; i < wwnrow; i++)
			for (j = 0; j < wwncol; j++)
E 20
I 20
		for (i = w->ww_w.t; i < w->ww_w.b; i++)
			for (j = w->ww_w.l; j < w->ww_w.r; j++)
E 20
				w->ww_fmap[i][j] = 0;
	}
E 11
D 27
	
E 27
I 27

E 27
	w->ww_buf = (union ww_char **)
D 20
		wwalloc(w->ww_nline, w->ww_w.nc, sizeof (union ww_char));
E 20
I 20
		wwalloc(w->ww_b.t, w->ww_b.l,
			w->ww_b.nr, w->ww_b.nc, sizeof (union ww_char));
E 20
	if (w->ww_buf == 0)
		goto bad;
D 20
	for (i = 0; i < w->ww_nline; i++)
		for (j = 0; j < w->ww_w.nc; j++)
E 20
I 20
	for (i = w->ww_b.t; i < w->ww_b.b; i++)
		for (j = w->ww_b.l; j < w->ww_b.r; j++)
E 20
			w->ww_buf[i][j].c_w = ' ';

	w->ww_nvis = (short *)malloc((unsigned) w->ww_w.nr * sizeof (short));
D 16
	if (w->ww_nvis == 0)
E 16
I 16
	if (w->ww_nvis == 0) {
		wwerrno = WWE_NOMEM;
E 16
		goto bad;
I 16
	}
I 20
	w->ww_nvis -= w->ww_w.t;
E 20
E 16
	nvis = m ? 0 : w->ww_w.nc;
D 20
	for (i = 0; i < w->ww_w.nr; i++)
E 20
I 20
	for (i = w->ww_w.t; i < w->ww_w.b; i++)
E 20
		w->ww_nvis[i] = nvis;

	w->ww_state = WWS_INITIAL;
I 27
	w->ww_oflags = flags;
E 27
E 8
E 2
D 15
	return w;
E 15
I 15
	return wwindex[w->ww_index] = w;
E 15
bad:
D 2
	if (w != 0)
E 2
I 2
	if (w != 0) {
D 8
		close(w->ww_tty);
		close(w->ww_pty);
E 8
I 8
		if (w->ww_win != 0)
D 10
			wwfree(w->ww_win, nrow);
E 10
I 10
D 20
			wwfree(w->ww_win);
E 20
I 20
			wwfree(w->ww_win, w->ww_w.t);
E 20
E 10
D 21
		if (w->ww_cov != 0)
D 10
			wwfree(w->ww_cov, nrow);
E 10
I 10
D 20
			wwfree(w->ww_cov);
E 20
I 20
			wwfree(w->ww_cov, w->ww_w.t);
E 21
E 20
I 17
		if (w->ww_fmap != 0)
D 20
			wwfree(w->ww_fmap);
E 20
I 20
			wwfree(w->ww_fmap, w->ww_w.t);
E 20
E 17
E 10
		if (w->ww_buf != 0)
D 10
			wwfree((char **)w->ww_buf, w->ww_nline);
E 10
I 10
D 20
			wwfree((char **)w->ww_buf);
E 20
I 20
			wwfree((char **)w->ww_buf, w->ww_b.t);
E 20
E 10
		if (w->ww_nvis != 0)
D 20
			free((char *)w->ww_nvis);
E 20
I 20
			free((char *)(w->ww_nvis + w->ww_w.t));
I 23
		if (w->ww_ob != 0)
			free(w->ww_ob);
E 23
E 20
D 18
		(void) close(w->ww_tty);
		(void) close(w->ww_pty);
E 18
I 18
D 22
		if (w->ww_haspty) {
			(void) close(w->ww_tty);
			(void) close(w->ww_pty);
		}
E 22
I 22
D 24
		(void) close(w->ww_pty);
E 24
I 24
		if (w->ww_pty >= 0)
			(void) close(w->ww_pty);
		if (w->ww_socket >= 0)
			(void) close(w->ww_socket);
E 24
E 22
E 18
E 8
E 2
D 10
		cfree((char *)w);
E 10
I 10
		free((char *)w);
E 10
I 2
	}
E 2
	return 0;
D 8
}

D 2
wwgettchars(w)
	register struct ww *w;
{
	if (ioctl(0, TIOCGETP, &w->ww_sgttyb) < 0)
		return -1;
	if (ioctl(0, TIOCGETC, &w->ww_tchars) < 0)
		return -1;
	if (ioctl(0, TIOCGLTC, &w->ww_ltchars) < 0)
		return -1;
	if (ioctl(0, TIOCLGET, &w->ww_lmode) < 0)
		return -1;
	if (ioctl(0, TIOCGETD, &w->ww_ldisc) < 0)
		return -1;
	if (ioctl(0, TIOCGPGRP, &w->ww_pgrp) < 0)
		return -1;
	return 0;
}

E 2
wwgetpty(w)
	register struct ww *w;
{
	register char c;
	register char *line;
	register int i;
D 5
#define PTY "/dev/XtyXX"
E 5
I 5
#define PTY "/dev/ptyXX"
E 5

	for (c = 'p'; c <= 's'; c++) {
		struct stat stb;

		line = PTY;
		line[sizeof PTY - 6] = 'p';
		line[sizeof PTY - 3] = c;
		line[sizeof PTY - 2] = '0';
		if (stat(line, &stb) < 0)
			break;
		for (i = 0; i < 16; i++) {
I 5
			line[sizeof PTY - 6] = 'p';
E 5
			line[sizeof PTY - 2] = "0123456789abcdef"[i];
			w->ww_pty = open(line, 2);
			if (w->ww_pty >= 0) {
				line[sizeof PTY - 6] = 't';
				w->ww_tty = open(line, 2);
				if (w->ww_tty >= 0)
					goto good;
				close(w->ww_pty);
			}
		}
	}
	return -1;
good:
I 5
	strcpy(w->ww_ttyname, line);
E 5
D 2
	if (ioctl(w->ww_pty, TIOCSETP, &w->ww_sgttyb) < 0)
		goto bad;
	if (ioctl(w->ww_pty, TIOCSETC, &w->ww_tchars) < 0)
		goto bad;
	if (ioctl(w->ww_pty, TIOCSLTC, &w->ww_ltchars) < 0)
		goto bad;
	if (ioctl(w->ww_pty, TIOCLSET, &w->ww_lmode) < 0)
		goto bad;
	if (ioctl(w->ww_pty, TIOCSETD, &w->ww_ldisc) < 0)
		goto bad;
	if (ioctl(w->ww_pty, TIOCSPGRP, &w->ww_pgrp) < 0)
		goto bad;
E 2
	return 0;
bad:
	close(w->ww_pty);
	close(w->ww_tty);
	return -1;
E 8
}
E 1
