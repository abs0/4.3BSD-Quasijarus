h21735
s 00010/00005/00207
d D 3.31 88/06/29 21:38:13 bostic 41 40
c install approved copyright notice
e
s 00030/00003/00182
d D 3.30 88/06/21 17:30:18 edward 40 39
c made the window termcap more terminal specific (al, dl, dc, etc.)
e
s 00001/00001/00184
d D 3.29 88/03/19 04:31:45 edward 39 38
c bug fix: use WWT_TERM to set the environment variable
e
s 00013/00007/00172
d D 3.28 88/02/21 13:38:27 bostic 38 37
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00018/00173
d D 3.27 87/10/01 22:46:03 edward 37 36
c use setenv() to set up environment, WINDOW_ID added (from mips!dce)
e
s 00000/00001/00191
d D 3.26 86/05/01 18:17:36 edward 36 35
c get rid of unnecessary declaration "int i"
e
s 00000/00002/00192
d D 3.25 85/09/19 14:09:51 edward 35 34
c no more select kludge
e
s 00006/00000/00188
d D 3.24 85/04/24 16:10:56 edward 34 33
c copyright messages
e
s 00002/00000/00186
d D 3.23 85/04/22 01:38:29 edward 33 32
c select kludge
e
s 00002/00003/00184
d D 3.22 84/11/20 23:39:33 edward 32 31
c we don't flush typeahead any more
e
s 00001/00001/00186
d D 3.21 84/11/19 16:49:09 edward 31 30
c forgot to initialize 'termcap'
e
s 00001/00001/00186
d D 3.20 84/05/23 01:56:16 edward 30 29
c new sccs id
e
s 00010/00010/00177
d D 3.19 84/05/16 04:18:10 edward 29 28
c ignore SIGPIPE
e
s 00004/00008/00183
d D 3.18 84/04/16 20:28:38 edward 28 27
c 4.1a, 4.1c compatibility removed, local.h added
e
s 00001/00000/00190
d D 3.17 84/04/08 12:07:44 edward 27 26
c control character expansion in wwwrite()
c calling of wwupdate() in wwwrite() dependent of ww_noupdate
c control character handling macros in char.h
e
s 00062/00029/00128
d D 3.16 84/03/23 18:16:15 edward 26 25
c compile with -R
e
s 00012/00004/00145
d D 3.15 84/03/03 22:41:41 edward 25 24
c interrupt driven input
e
s 00006/00000/00143
d D 3.14 84/01/16 15:24:58 edward 24 23
c new io scheme
e
s 00000/00001/00143
d D 3.13 83/12/17 12:39:22 edward 23 22
c got rid of pgrp in struct ww_tty
e
s 00000/00000/00144
d D 3.12 83/12/02 22:44:42 edward 22 21
c WWU_MAJOR, clreol in wwupdate(), and more optimizations.
e
s 00005/00000/00139
d D 3.11 83/11/02 11:05:18 edward 21 20
c flags for different machines.
e
s 00003/00003/00136
d D 3.10 83/09/15 10:06:47 edward 20 19
c Now uses screen address for all buffers.
e
s 00009/00003/00130
d D 3.9 83/08/26 16:23:24 edward 19 18
c error reporting
e
s 00000/00005/00133
d D 3.8 83/08/19 17:32:27 edward 18 17
c moved fmap into struct ww and added WWO_FRAME to allocate it.
e
s 00005/00000/00133
d D 3.7 83/08/19 15:04:08 edward 17 16
c fake cursor
e
s 00001/00000/00132
d D 3.6 83/08/17 17:40:47 edward 16 15
c better wrap around handling.
e
s 00001/00000/00131
d D 3.5 83/08/17 14:50:56 edward 15 14
c ww_availmodes and stuff
e
s 00010/00000/00121
d D 3.4 83/08/16 12:54:20 edward 14 13
c wwtouched added
e
s 00002/00002/00119
d D 3.3 83/08/15 18:14:13 edward 13 12
c tt cleanup
e
s 00006/00000/00115
d D 3.2 83/08/12 18:33:04 edward 12 11
c faster and better frames
e
s 00002/00000/00113
d D 3.1 83/08/11 17:21:09 edward 11 9
i 10
c last few day's work
e
s 00048/00030/00065
d D 2.1.1.1 83/08/09 18:33:59 edward 10 9
c mile stone
e
s 00000/00000/00095
d D 2.1 83/07/30 13:26:52 edward 9 8
c prepare for major change
e
s 00003/00000/00092
d D 1.8 83/07/29 18:22:03 edward 8 7
c wwwintty added, and turn off XTABS for the ptys.
e
s 00007/00005/00085
d D 1.7 83/07/29 17:08:43 edward 7 6
c turn off ^\ and unctrl the new termcap entry.
e
s 00046/00000/00044
d D 1.6 83/07/26 14:02:01 edward 6 5
c Function keys passed on to the windows.
e
s 00002/00000/00042
d D 1.5 83/07/22 17:07:33 edward 5 4
c scrolling.
c uses Wscreensize() to get screen size.
c More intelligent framing.
c etc.
e
s 00002/00000/00040
d D 1.4 83/07/19 20:07:33 edward 4 3
c today's work
e
s 00002/00002/00038
d D 1.3 83/07/18 21:02:38 edward 3 2
c multiple window
e
s 00030/00005/00010
d D 1.2 83/07/17 15:42:10 edward 2 1
c 
e
s 00015/00000/00000
d D 1.1 83/07/12 17:20:53 edward 1 0
c date and time created 83/07/12 17:20:53 by edward
e
u
U
f b 
t
T
I 1
D 38
#ifndef lint
D 30
static	char *sccsid = "%W% %E%";
E 30
I 30
static char sccsid[] = "%W% %G%";
E 30
#endif

E 38
I 34
/*
D 38
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 38
I 38
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 41
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 41
I 41
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
E 41
E 38
 */
I 38

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 38

E 34
#include "ww.h"
I 13
#include "tt.h"
I 25
#include <sys/signal.h>
#include <fcntl.h>
I 27
#include "char.h"
E 27
E 25
E 13

D 2
int _wwiflag = 0;
E 2
I 2
D 10
struct ww_tty wwoldtty;
I 8
struct ww_tty wwwintty;
E 8
struct ww_tty wwnewtty = {
	{ 0, 0, -1, -1, 0 },
	{ -1, -1, -1, -1, -1, -1 },
	{ -1, -1, -1, -1, -1, -1 },
	0, 0, 0
};
I 4
int _wwdtablesize;
I 6
char _wwtermcap[1024];
char _wwkeys[512];
static char *kp = _wwkeys;
E 6
I 5
int wwncol, wwnrow;
E 10
I 10
D 26
static char *kp = wwkeys;
I 11
D 25
extern char _sobuf[];
E 25
E 11
E 10
E 5
E 4
E 2

E 26
wwinit()
{
D 2
	if (_wwiflag)
		return;
	_wwiflag++;
	initscr();
E 2
I 2
D 10
	static char done = 0;
E 10
I 10
	register i, j;
E 10
I 6
D 26
	int kn;
E 26
I 26
	char *kp;
D 37
	register char **p, **q;
D 31
	char **env, **termcap;
E 31
I 31
	char **env, **termcap = 0;
E 31
	extern char **environ;
E 37
I 28
	int s;
E 28
E 26
E 6

I 11
D 25
	setbuf(stdout, _sobuf);
E 25
I 21
D 28
#ifndef O_4_1A
E 28
E 21
E 11
D 10
	if (done)
		return 0;
	done++;
I 4
	_wwdtablesize = getdtablesize();
E 10
I 10
	wwdtablesize = getdtablesize();
I 33
D 35
	if (wwdtablesize > 32)				/* XXX */
		wwdtablesize = 32;
E 35
E 33
I 21
D 28
#else
#include <sys/param.h>
	wwdtablesize = NOFILE;
#endif
E 28
I 26
	wwhead.ww_forw = &wwhead;
	wwhead.ww_back = &wwhead;
E 26
I 25

I 28
	s = sigblock(sigmask(SIGIO));
E 28
	if (signal(SIGIO, wwrint) == BADSIG)
		return -1;
D 28
	(void) sighold(SIGIO);
E 28

E 25
E 21
E 10
E 4
	if (wwgettty(0, &wwoldtty) < 0)
		return -1;
I 8
	wwwintty = wwoldtty;
	wwwintty.ww_sgttyb.sg_flags &= ~XTABS;
E 8
D 26
	wwnewtty.ww_sgttyb.sg_flags = wwoldtty.ww_sgttyb.sg_flags;
	wwnewtty.ww_sgttyb.sg_ispeed = wwoldtty.ww_sgttyb.sg_ispeed;
	wwnewtty.ww_sgttyb.sg_ospeed = wwoldtty.ww_sgttyb.sg_ospeed;
	wwnewtty.ww_lmode = wwoldtty.ww_lmode;
D 23
	wwnewtty.ww_pgrp = wwoldtty.ww_pgrp;
E 23
	wwnewtty.ww_ldisc = wwoldtty.ww_ldisc;
E 26
I 26
	wwnewtty.ww_sgttyb = wwoldtty.ww_sgttyb;
	wwnewtty.ww_sgttyb.sg_erase = -1;
	wwnewtty.ww_sgttyb.sg_kill = -1;
E 26
	wwnewtty.ww_sgttyb.sg_flags |= CBREAK;
D 3
	wwnewtty.ww_sgttyb.sg_flags &= ~ECHO;
E 3
I 3
	wwnewtty.ww_sgttyb.sg_flags &= ~(ECHO|CRMOD);
E 3
D 26
	wwnewtty.ww_lmode |= LLITOUT;
I 25
	wwnewtty.ww_fflags |= FASYNC;
E 26
I 26
	wwnewtty.ww_tchars.t_intrc = -1;
	wwnewtty.ww_tchars.t_quitc = -1;
	wwnewtty.ww_tchars.t_startc = -1;
	wwnewtty.ww_tchars.t_stopc = -1;
	wwnewtty.ww_tchars.t_eofc = -1;
	wwnewtty.ww_tchars.t_brkc = -1;
	wwnewtty.ww_ltchars.t_suspc = -1;
	wwnewtty.ww_ltchars.t_dsuspc = -1;
	wwnewtty.ww_ltchars.t_rprntc = -1;
	wwnewtty.ww_ltchars.t_flushc = -1;
	wwnewtty.ww_ltchars.t_werasc = -1;
	wwnewtty.ww_ltchars.t_lnextc = -1;
	wwnewtty.ww_lmode = wwoldtty.ww_lmode | LLITOUT;
	wwnewtty.ww_ldisc = wwoldtty.ww_ldisc;
	wwnewtty.ww_fflags = wwoldtty.ww_fflags | FASYNC;
D 32

E 26
E 25
D 7
	wwnewtty.ww_tchars.t_quitc = wwoldtty.ww_tchars.t_quitc;
E 7
	if (wwsettty(0, &wwnewtty) < 0)
E 32
I 32
	if (wwsettty(0, &wwnewtty, &wwoldtty) < 0)
E 32
D 10
		return -1;
D 3
	if (Winit(&wwnewtty.ww_sgttyb, 1) != 0)
E 3
I 3
	if (Winit(2, 1) != 0)
E 3
		return -1;
	WSetRealCursor = 1;
I 5
	Wscreensize(&wwnrow, &wwncol);
E 10
I 10
		goto bad;
E 10
I 6

D 10
	if (tgetent(_wwtermcap, getenv("TERM")) != 1)
		return -1;
E 10
I 10
D 19
	if ((wwterm = getenv("TERM")) == 0)
E 19
I 19
	if ((wwterm = getenv("TERM")) == 0) {
		wwerrno = WWE_BADTERM;
E 19
		goto bad;
D 19
	if (tgetent(wwtermcap, wwterm) != 1)
E 19
I 19
	}
	if (tgetent(wwtermcap, wwterm) != 1) {
		wwerrno = WWE_BADTERM;
E 19
		goto bad;
I 19
	}
E 19
	wwbaud = wwbaudmap[wwoldtty.ww_sgttyb.sg_ospeed];

	if (ttinit() < 0)
		goto bad;
	wwnrow = tt.tt_nrow;
	wwncol = tt.tt_ncol;
I 15
	wwavailmodes = tt.tt_availmodes;
I 16
	wwwrap = tt.tt_wrap;
E 16
E 15
D 13
	(*tt.tt_reset)();
	(*tt.tt_clreos)();
E 13
I 13
	(*tt.tt_init)();
E 13

I 17
	if (wwavailmodes & WWM_REV)
		wwcursormodes = WWM_REV | wwavailmodes & WWM_BLK;
	else if (wwavailmodes & WWM_UL)
		wwcursormodes = WWM_UL;

I 24
	if ((wwib = malloc((unsigned) 512)) == 0)
		goto bad;
	wwibe = wwib + 512;
D 25
	wwibp = wwib;
	wwibc = 0;
E 25
I 25
	wwibq = wwibp = wwib;
E 25

E 24
E 17
D 20
	if ((wwsmap = wwalloc(wwnrow, wwncol, sizeof (char))) == 0)
E 20
I 20
	if ((wwsmap = wwalloc(0, 0, wwnrow, wwncol, sizeof (char))) == 0)
E 20
		goto bad;
	for (i = 0; i < wwnrow; i++)
		for (j = 0; j < wwncol; j++)
			wwsmap[i][j] = WWX_NOBODY;
I 12
D 18
	if ((wwfmap = wwalloc(wwnrow, wwncol, sizeof (char))) == 0)
		goto bad;
	for (i = 0; i < wwnrow; i++)
		for (j = 0; j < wwncol; j++)
			wwfmap[i][j] = 0;
E 18

E 12
	wwos = (union ww_char **)
D 20
		wwalloc(wwnrow, wwncol, sizeof (union ww_char));
E 20
I 20
		wwalloc(0, 0, wwnrow, wwncol, sizeof (union ww_char));
E 20
	if (wwos == 0)
		goto bad;
	for (i = 0; i < wwnrow; i++)
		for (j = 0; j < wwncol; j++)
			wwos[i][j].c_w = ' ';
	wwns = (union ww_char **)
D 20
		wwalloc(wwnrow, wwncol, sizeof (union ww_char));
E 20
I 20
		wwalloc(0, 0, wwnrow, wwncol, sizeof (union ww_char));
E 20
	if (wwns == 0)
		goto bad;
	for (i = 0; i < wwnrow; i++)
		for (j = 0; j < wwncol; j++)
			wwns[i][j].c_w = ' ';

I 14
	wwtouched = malloc((unsigned) wwnrow);
D 19
	if (wwtouched == 0)
E 19
I 19
	if (wwtouched == 0) {
		wwerrno = WWE_NOMEM;
E 19
		goto bad;
I 19
	}
E 19
	for (i = 0; i < wwnrow; i++)
		wwtouched[i] = 0;

E 14
	wwindex[WWX_NOBODY] = &wwnobody;
	wwnobody.ww_order = NWW;

E 10
D 26
	addcap("kb");
	addcap("ku");
	addcap("kd");
	addcap("kl");
	addcap("kr");
	addcap("kh");
	if ((kn = tgetnum("kn")) >= 0) {
		char cap[5];
E 26
I 26
D 40
	kp = wwkeys;
E 40
I 40
	kp = wwwintermcap;
	if (wwavailmodes & WWM_REV)
		wwaddcap1(WWT_REV, &kp);
	if (wwavailmodes & WWM_BLK)
		wwaddcap1(WWT_BLK, &kp);
	if (wwavailmodes & WWM_UL)
		wwaddcap1(WWT_UL, &kp);
	if (wwavailmodes & WWM_GRP)
		wwaddcap1(WWT_GRP, &kp);
	if (wwavailmodes & WWM_DIM)
		wwaddcap1(WWT_DIM, &kp);
	if (wwavailmodes & WWM_USR)
		wwaddcap1(WWT_USR, &kp);
	if (tt.tt_insline && tt.tt_delline || tt.tt_setscroll)
		wwaddcap1(WWT_ALDL, &kp);
	if (tt.tt_hasinsert)
		wwaddcap1(WWT_IMEI, &kp);
	if (tt.tt_delchar)
		wwaddcap1(WWT_DC, &kp);
E 40
D 29
	addcap("kb", &kp);
	addcap("ku", &kp);
	addcap("kd", &kp);
	addcap("kl", &kp);
	addcap("kr", &kp);
	addcap("kh", &kp);
E 29
I 29
	wwaddcap("kb", &kp);
	wwaddcap("ku", &kp);
	wwaddcap("kd", &kp);
	wwaddcap("kl", &kp);
	wwaddcap("kr", &kp);
	wwaddcap("kh", &kp);
E 29
	if ((j = tgetnum("kn")) >= 0) {
		char cap[32];
E 26
D 36
		int i;
E 36

D 10
		sprintf(kp, "kn#%d:", kn);
E 10
I 10
D 26
		(void) sprintf(kp, "kn#%d:", kn);
E 26
I 26
		(void) sprintf(kp, "kn#%d:", j);
E 26
E 10
		for (; *kp; kp++)
			;
D 26
		for (i = 1; i <= kn; i++) {
E 26
I 26
		for (i = 1; i <= j; i++) {
E 26
D 10
			sprintf(cap, "k%d", i);
E 10
I 10
			(void) sprintf(cap, "k%d", i);
E 10
D 26
			addcap(cap);
E 26
I 26
D 29
			addcap(cap, &kp);
E 29
I 29
			wwaddcap(cap, &kp);
E 29
E 26
			cap[0] = 'l';
D 26
			addcap(cap);
E 26
I 26
D 29
			addcap(cap, &kp);
E 29
I 29
			wwaddcap(cap, &kp);
E 29
E 26
		}
	}
I 26
D 37
	for (i = 0, p = environ; *p++; i++)
		;
	if ((env = (char **)malloc((unsigned)(i + 3) * sizeof (char *))) == 0)
		goto bad;
	for (p = environ, q = env; *p; p++, q++) {
		if (strncmp(*p, "TERM=", 5) == 0)
			*q = WWT_TERM;
		else if (strncmp(*p, "TERMCAP=", 8) == 0)
			termcap = q;
		else
			*q = *p;
	}
	*(termcap ? termcap : q++) = wwwintermcap;
	*q = 0;
	environ = env;
E 37
I 37
	/*
	 * It's ok to do this here even if setenv() is destructive
	 * since tt_init() has already made its own copy of it and
	 * wwterm now points to the copy.
	 */
D 39
	(void) setenv("TERM", "window", 1);
E 39
I 39
	(void) setenv("TERM", WWT_TERM, 1);
E 39
E 37

I 29
	(void) signal(SIGPIPE, SIG_IGN);
E 29
E 26
I 25
D 28
	(void) sigrelse(SIGIO);
E 28
I 28
	(void) sigsetmask(s);
E 28
E 25
E 6
E 5
	return 0;
I 10
bad:
I 14
	/*
	 * Don't bother to free storage.  We're supposed
	 * to exit when wwinit fails anyway.
	 */
E 14
D 32
	(void) wwsettty(0, &wwoldtty);
E 32
I 32
	(void) wwsettty(0, &wwoldtty, &wwnewtty);
E 32
I 25
	(void) signal(SIGIO, SIG_DFL);
D 28
	(void) sigrelse(SIGIO);
E 28
I 28
	(void) sigsetmask(s);
E 28
E 25
	return -1;
E 10
I 6
}

I 10
D 29
static
E 10
D 26
addcap(cap)
E 26
I 26
addcap(cap, kp)
E 29
I 29
wwaddcap(cap, kp)
E 29
E 26
D 40
register char *cap;
I 26
register char **kp;
E 40
I 40
	register char *cap;
	register char **kp;
E 40
E 26
{
D 10
	static char tbuf[512];
	static char *tp = tbuf;
E 10
I 10
	char tbuf[512];
	char *tp = tbuf;
E 10
D 7
	register char *str;
E 7
I 7
	register char *str, *p;
E 7
D 10
	char *tgetstr();
E 10

	if ((str = tgetstr(cap, &tp)) != 0) {
D 26
		while (*kp++ = *cap++)
E 26
I 26
		while (*(*kp)++ = *cap++)
E 26
			;
D 26
		kp[-1] = '=';
E 26
I 26
		(*kp)[-1] = '=';
E 26
D 7
		while (*kp++ = *str++)
			;
		kp[-1] = ':';
E 7
I 7
		while (*str) {
D 26
			for (p = unctrl(*str++); *kp++ = *p++;)
E 26
I 26
			for (p = unctrl(*str++); *(*kp)++ = *p++;)
E 26
				;
D 26
			kp--;
E 26
I 26
			(*kp)--;
E 26
		}
D 26
		*kp++ = ':';
E 7
		*kp = 0;
E 26
I 26
		*(*kp)++ = ':';
		**kp = 0;
E 26
	}
I 40
}

wwaddcap1(cap, kp)
	register char *cap;
	register char **kp;
{
	while (*(*kp)++ = *cap++)
		;
	(*kp)--;
E 40
E 6
E 2
}
E 1
