h57465
s 00010/00005/00156
d D 3.33 88/06/29 21:36:11 bostic 45 44
c install approved copyright notice
e
s 00013/00007/00148
d D 3.32 88/02/21 13:37:08 bostic 44 43
c written by Edward Wang; attach Berkeley specific copyright
e
s 00002/00001/00153
d D 3.31 87/05/18 12:07:29 edward 43 42
c don't use reverse video for command line when <= 2400 baud
e
s 00000/00002/00154
d D 3.30 85/08/14 21:51:33 edward 42 41
c don't do unnecessary set modes and cursor motion
e
s 00006/00000/00150
d D 3.29 85/04/24 16:10:40 edward 41 40
c copyright messages
e
s 00002/00002/00148
d D 3.28 85/01/18 11:06:09 edward 40 39
c we have to initialize escapec before processing arguments
e
s 00001/00001/00149
d D 3.27 84/11/20 23:39:18 edward 39 38
c we don't flush typeahead any more
e
s 00001/00001/00149
d D 3.26 84/05/23 01:56:07 edward 38 37
c new sccs id
e
s 00001/00001/00149
d D 3.25 84/05/06 17:53:17 edward 37 36
c alias macros
e
s 00004/00005/00146
d D 3.24 84/04/16 20:28:29 edward 36 35
c 4.1a, 4.1c compatibility removed, local.h added
e
s 00018/00006/00133
d D 3.23 84/04/08 19:22:24 edward 35 34
c new options to "window": shell, pty, frame
c and stuff to support them
e
s 00001/00000/00138
d D 3.22 84/04/08 12:34:12 edward 34 33
c set ww_mapnl for cmdwin
e
s 00003/00001/00135
d D 3.21 84/04/08 12:07:38 edward 33 32
c control character expansion in wwwrite()
c calling of wwupdate() in wwwrite() dependent of ww_noupdate
c control character handling macros in char.h
e
s 00001/00001/00135
d D 3.20 84/04/06 23:11:09 edward 32 31
c lint
e
s 00000/00001/00136
d D 3.19 84/04/05 00:56:39 edward 31 30
c no more background windows.
e
s 00019/00014/00118
d D 3.18 84/04/05 00:31:19 edward 30 29
c -c flag, incmd, setcmd(), setterse() added
e
s 00002/00000/00130
d D 3.17 84/03/29 00:02:52 edward 29 28
c foreground and background windows
e
s 00002/00003/00128
d D 3.16 84/03/23 18:16:09 edward 28 27
c compile with -R
e
s 00007/00008/00124
d D 3.15 84/03/03 22:41:20 edward 27 26
c interrupt driven input
e
s 00001/00000/00131
d D 3.14 83/12/06 12:50:33 edward 26 25
c predefined variables
e
s 00004/00000/00127
d D 3.13 83/11/02 11:04:45 edward 25 24
c flags for different machines.
e
s 00001/00001/00126
d D 3.12 83/09/19 10:29:56 edward 24 23
c -D is now a toggle
e
s 00000/00001/00127
d D 3.11 83/09/14 19:00:47 edward 23 22
c lint
e
s 00010/00057/00118
d D 3.10 83/09/02 12:58:25 edward 22 21
c separated mloop() and now quits when window dies
e
s 00006/00007/00169
d D 3.9 83/09/01 18:34:23 edward 21 20
c Got rid of 'curwin'.
c and now knows about dead processes.
e
s 00002/00003/00174
d D 3.8 83/08/26 17:19:35 edward 20 19
c bug with wwforce hanging
e
s 00010/00002/00167
d D 3.7 83/08/26 13:12:38 edward 19 18
c -x flag
e
s 00001/00000/00168
d D 3.6 83/08/25 17:56:54 edward 18 17
c added user setable buffer size.
e
s 00002/00001/00166
d D 3.5 83/08/19 17:32:21 edward 17 16
c moved fmap into struct ww and added WWO_FRAME to allocate it.
e
s 00001/00003/00166
d D 3.4 83/08/19 15:03:58 edward 16 15
c fake cursor
e
s 00005/00000/00164
d D 3.3 83/08/18 17:17:45 edward 15 14
c the box
e
s 00009/00005/00155
d D 3.2 83/08/17 12:56:30 edward 14 13
c -d flag (debug now -D)
e
s 00002/00001/00158
d D 3.1 83/08/11 17:20:48 edward 13 11
i 12
c last few day's work
e
s 00043/00029/00116
d D 2.1.1.1 83/08/09 18:33:33 edward 12 11
c mile stone
e
s 00000/00000/00145
d D 2.1 83/07/30 13:26:25 edward 11 10
c prepare for major change
e
s 00003/00001/00142
d D 1.10 83/07/29 18:21:09 edward 10 9
c forgot to turn the window cursor off on startup.
e
s 00032/00006/00111
d D 1.9 83/07/29 17:07:27 edward 9 8
c fixed argv bug and more flags
c also turn off ^\ except with -d or a.out.
e
s 00031/00002/00086
d D 1.8 83/07/28 13:04:48 edward 8 7
c argv handling and changable escape character
e
s 00007/00001/00081
d D 1.7 83/07/27 14:33:04 edward 7 6
c io statistics
e
s 00002/00002/00080
d D 1.6 83/07/22 17:06:37 edward 6 5
c scrolling.
c uses Wscreensize() to get screen size.
c More intelligent framing.
c etc.
e
s 00008/00004/00074
d D 1.5 83/07/20 19:30:30 edward 5 4
c Startup configuration stuff, and misc.
e
s 00032/00020/00046
d D 1.4 83/07/19 20:07:21 edward 4 3
c today's work
e
s 00037/00181/00029
d D 1.3 83/07/18 21:01:48 edward 3 2
c multiple window
e
s 00168/00043/00042
d D 1.2 83/07/17 15:41:52 edward 2 1
c 
e
s 00085/00000/00000
d D 1.1 83/07/12 17:20:36 edward 1 0
c date and time created 83/07/12 17:20:36 by edward
e
u
U
f b 
t
T
I 1
D 44
#ifndef lint
D 38
static	char *sccsid = "%W% %E%";
E 38
I 38
static char sccsid[] = "%W% %G%";
E 38
#endif

E 44
I 41
/*
D 44
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 44
I 44
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 45
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 45
I 45
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
E 45
E 44
 */
I 44

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 44

E 41
D 3
#include "ww.h"
#include <signal.h>
I 2
#include <sys/time.h>
#include <sys/resource.h>
E 3
I 3
#include "defs.h"
I 27
#include <sys/signal.h>
#include <stdio.h>
I 35
#include "string.h"
E 35
I 33
#include "char.h"
I 36
#include "local.h"
E 36
E 33
E 27
E 3
E 2

D 2
struct ww *w1, *w2;
E 2
I 2
D 3
#define ESCAPE CTRL(p)
E 2

I 2
int nread = 0;
struct timeval starttime;
struct timezone timezone;

E 3
E 2
D 8
main()
E 8
I 8
D 9
char escapec = CTRL(l);
E 9
I 9
D 27
char escapec = CTRL(p);
E 27
I 18
D 28
int nbufline = 48;			/* compatible */
I 27
char escapec = CTRL(p);	
E 27
E 18
E 9

E 28
D 9
#define next(a) (**(a) ? *(a) : (*++(a) ? *(a) : (char *)usage()))
E 9
I 9
#define next(a) (*++*(a) ? *(a) : (*++(a) ? *(a) : (char *)usage()))
E 9

D 12
/*ARGUSED*/
E 12
I 12
/*ARGSUSED*/
E 12
main(argc, argv)
char **argv;
E 8
{
D 23
	register n;
E 23
	register char *p;
I 9
D 14
	char fast = 0;
E 14
I 14
	char fflag = 0;
	char dflag = 0;
I 19
	char xflag = 0;
I 30
	char *cmd = 0;
	char tflag = 0;
E 30
I 25
D 27
#ifndef O_4_1A
E 25
E 19
E 14
E 9
I 2
D 3
	struct ww *w1, *w2;
E 3
E 2
D 12
	int wwchild();
E 12
D 22
	int imask;
E 22
I 9
D 12
	char *rindex();
	char *getenv();
E 12
I 12
	struct timezone timezone;
I 25
#endif
E 27
E 25
E 12
E 9
D 3
	char buf[512];
	char escape = 0;
I 2
	char c;
	struct rusage rusage;
E 3
E 2

I 40
	nbufline = NLINE;
	escapec = ESCAPEC;	
E 40
I 9
	if (p = rindex(*argv, '/'))
		p++;
	else
		p = *argv;
	debug = strcmp(p, "a.out") == 0;
E 9
I 8
	while (*++argv) {
		if (**argv == '-') {
			switch (*++*argv) {
I 9
			case 'f':
D 14
				fast++;
E 14
I 14
				fflag++;
E 14
				break;
I 30
			case 'c':
				if (cmd != 0) {
					(void) fprintf(stderr,
						"Only one -c allowed.\n");
					(void) usage();
				}
				cmd = next(argv);
				break;
E 30
E 9
			case 'e':
				setescape(next(argv));
				break;
			case 't':
D 30
				terse++;
E 30
I 30
				tflag++;
E 30
				break;
I 9
			case 'd':
I 14
				dflag++;
				break;
			case 'D':
E 14
D 24
				debug++;
E 24
I 24
				debug = !debug;
E 24
				break;
I 19
			case 'x':
				xflag++;
				break;
E 19
E 9
			default:
D 12
				usage();
E 12
I 12
				(void) usage();
E 12
			}
		} else
D 12
			usage();
E 12
I 12
			(void) usage();
E 12
	}
I 28
D 36
	nbufline = 48;				/* compatible */
D 33
	escapec = CTRL(p);	
E 33
I 33
	escapec = ctrl(p);	
E 36
I 36
D 40
	nbufline = NLINE;
	escapec = ESCAPEC;	
E 40
E 36
E 33
E 28
I 9
D 35
	if ((shell = getenv("SHELL")) == 0)
		shell = "/bin/csh";
	if (shellname = rindex(shell, '/'))
		shellname++;
E 35
I 35
	if ((p = getenv("SHELL")) == 0)
D 36
		p = "/bin/csh";
E 36
I 36
		p = SHELL;
E 36
	if ((shellfile = str_cpy(p)) == 0)
		nomem();
	if (p = rindex(shellfile, '/'))
		p++;
E 35
	else
D 35
		shellname = shell;
E 35
I 35
		p = shellfile;
	shell[0] = p;
	shell[1] = 0;
E 35
I 25
D 36
#ifndef O_4_1A
E 36
E 25
E 9
E 8
I 3
D 12
	gettimeofday(&starttime, &timezone);
E 12
I 12
D 27
	(void) gettimeofday(&starttime, &timezone);
E 27
I 27
	(void) gettimeofday(&starttime, (struct timezone *)0);
E 27
I 25
D 36
#endif
E 36
E 25
E 12
E 3
D 2
	w1 = wwopen(12, 80, 0, 0);
	w2 = wwopen(12, 80, 12, 0);
E 2
I 2
	if (wwinit() < 0) {
D 12
		fflush(stdout);
		fprintf("Can't do windows on this terminal.\n");
E 12
I 12
D 27
		(void) fflush(stdout);
E 27
D 22
		(void) fprintf(stderr, "Can't do windows on this terminal.\n");
E 22
I 22
		(void) fprintf(stderr, "%s.\n", wwerror());
E 22
E 12
		exit(1);
	}
I 9
D 19
	if (debug) {
E 19
I 19
	if (debug)
E 19
		wwnewtty.ww_tchars.t_quitc = wwoldtty.ww_tchars.t_quitc;
D 12
		wwsettty(0, &wwnewtty);
E 12
I 12
D 19
		(void) wwsettty(0, &wwnewtty);
E 19
I 19
	if (xflag) {
		wwnewtty.ww_tchars.t_stopc = wwoldtty.ww_tchars.t_stopc;
		wwnewtty.ww_tchars.t_startc = wwoldtty.ww_tchars.t_startc;
E 19
E 12
	}
I 19
	if (debug || xflag)
D 39
		(void) wwsettty(0, &wwnewtty);
E 39
I 39
		(void) wwsettty(0, &wwnewtty, &wwoldtty);
E 39
E 19
E 9
D 3
	n = WRows / 2;
	if ((w1 = wwopen(1, n, WCols, 0, 0)) == 0
	    || (w2 = wwopen(2, WRows - n, WCols, n, 0)) == 0) {
E 3
I 3
D 5
	if ((cmdwin = wwopen(1, 0, 1, WCols, 0, 0)) == 0) {
E 5
I 5
D 6
	if ((cmdwin = wwopen(WW_NONE, 0, 1, WCols, 0, 0)) == 0) {
E 6
I 6
D 12
	if ((cmdwin = wwopen(WW_NONE, 0, 1, wwncol, 0, 0)) == 0) {
E 6
E 5
E 3
		fflush(stdout);
D 3
		fprintf(stderr, "Can't open windows.\n");
E 3
I 3
		fprintf(stderr, "Can't open command window.\r\n");
E 12
I 12

D 43
	if ((cmdwin = wwopen(WWO_REVERSE, 1, wwncol, 0, 0, 0)) == 0) {
E 43
I 43
	if ((cmdwin = wwopen(wwbaud > 2400 ? WWO_REVERSE : 0, 1, wwncol,
			     0, 0, 0)) == 0) {
E 43
		(void) wwflush();
D 22
		(void) fprintf(stderr, "Can't open command window.\r\n");
E 22
I 22
		(void) fprintf(stderr, "%s.\r\n", wwerror());
E 22
E 12
E 3
		goto bad;
	}
I 34
	cmdwin->ww_mapnl = 1;
E 34
I 27
	cmdwin->ww_nointr = 1;
I 33
	cmdwin->ww_noupdate = 1;
I 35
	cmdwin->ww_unctrl = 1;
E 35
E 33
E 27
I 8
D 12
	if (terse)
		Whide(cmdwin->ww_win);
E 8
E 2
D 3
	wwsetcurrent(w1);
E 3
I 3
D 5
	wwsetcurrent(cmdwin);
	for (n = 0; n < WCols; n++)
E 5
I 5
	wwsetcurwin(cmdwin);
D 6
	for (n = 0; n < WCols; n++)			/* XXX */
E 6
I 6
	for (n = 0; n < wwncol; n++)			/* XXX */
E 6
E 5
		Waputc(0, WINVERSE|WBUF, cmdwin->ww_win);
E 12
I 12
D 17
	if ((framewin = wwopen(WWO_GLASS, wwnrow, wwncol, 0, 0, 0)) == 0) {
E 17
I 17
	if ((framewin = wwopen(WWO_GLASS|WWO_FRAME, wwnrow, wwncol, 0, 0, 0))
	    == 0) {
E 17
		(void) wwflush();
D 22
		(void) fprintf(stderr, "Can't open frame window.\r\n");
E 22
I 22
		(void) fprintf(stderr, "%s.\r\n", wwerror());
E 22
		goto bad;
	}
	wwadd(framewin, &wwhead);
I 15
	if ((boxwin = wwopen(WWO_GLASS, wwnrow, wwncol, 0, 0, 0)) == 0) {
		(void) wwflush();
D 22
		(void) fprintf(stderr, "Can't open box window.\r\n");
E 22
I 22
		(void) fprintf(stderr, "%s.\r\n", wwerror());
E 22
		goto bad;
	}
I 29
	fgwin = framewin;
D 31
	bgwin = &wwhead;
E 31
E 29
E 15

D 21
	curwin = cmdwin;
E 21
	wwupdate();
E 12
	wwflush();
E 3
D 2
	noecho();
	crmode();
E 2
	(void) signal(SIGCHLD, wwchild);
I 26
	setvars();
E 26
I 5
D 9
	if (doconfig() < 0)
		dodefault();
	if (selwin != 0)
		wwsetcurwin(selwin);
E 9
I 9
D 14
	if (!fast) {
E 14
I 14
D 22
	if (!fflag) {
E 22
I 22
D 30
	if (fflag)
D 27
		incmd = 1;
E 27
I 27
		wwcurwin = 0;
E 27
	else {
E 22
E 14
I 12
		if (!terse)
			wwadd(cmdwin, &wwhead);
E 30
I 30

	setterse(tflag);
	setcmd(1);
	if (cmd != 0)
D 32
		dolongcmd(cmd);
E 32
I 32
D 37
		(void) dolongcmd(cmd);
E 37
I 37
		(void) dolongcmd(cmd, (struct value *)0, 0);
E 37
E 32
	if (!fflag) {
E 30
E 12
D 14
		if (doconfig() < 0)
E 14
I 14
		if (dflag || doconfig() < 0)
E 14
			dodefault();
D 10
		if (selwin != 0)
E 10
I 10
D 30
		if (selwin != 0) {
E 10
D 12
			wwsetcurwin(selwin);
E 12
I 12
D 21
			curwin = selwin;
E 21
I 21
D 27
			incmd = 0;
E 27
I 27
			wwcurwin = selwin;
E 27
E 21
D 16
			/*
E 12
I 10
			Woncursor(selwin->ww_win, 0);
I 12
			*/
E 16
I 16
			wwcursor(selwin, 0);
E 16
E 12
		}
I 12
		if (!terse) {
			wwdelete(cmdwin);
			reframe();
		}
E 30
I 30
		if (selwin != 0)
			setcmd(0);
E 30
E 12
E 10
	}
E 9
E 5
D 3
	switch (wwfork(w1)) {
	case -1:
		perror("wwfork");
		goto bad;
	case 0:
D 2
		wwexecl(w1, "/bin/csh", "csh", 0);
		perror("wwexecl(w1)");
		goto bad;
E 2
I 2
		execl("/bin/csh", "csh", 0);
		perror("execl(/bin/csh)");
		exit(1);
E 2
	}
	switch (wwfork(w2)) {
	case -1:
		perror("wwfork");
		goto bad;
	case 0:
D 2
		wwexecl(w2, "/bin/csh", "csh", 0);
		perror("wwexecl(w2)");
		goto bad;
E 2
I 2
		execl("/bin/csh", "csh", 0);
		perror("execl(/bin/csh)");
		exit(1);
E 2
	}
I 2
	gettimeofday(&starttime, &timezone);
	wwputstr("Type ^P? for help.\r\n");
E 2
	for (;;) {
D 2
		wwflushall();
E 2
I 2
		wwflush();
E 2
		if (!wwhaschildren())
			break;
D 2
		imask = 1<<0;
		while (wwforce(&imask) < 0)
E 2
I 2
		while (imask = 1<<0, wwforce(&imask) < 0)
E 2
			;
D 2
		if (imask & 1<<0) {
			n = read(0, buf, sizeof buf);
			for (p = buf; n-- > 0; p++) {
				*p &= 0x7f;
				if (escape) {
					escape = 0;
					switch (*p) {
					case '\\':
						write(_wwcurrent->ww_pty, p, 1);
						break;
					case '1':
						wwsetcurrent(w1);
						break;
					case '2':
						wwsetcurrent(w2);
						break;
					default:
						write(_wwcurrent->ww_pty,
							"\\", 1);
						write(_wwcurrent->ww_pty, p, 1);
					}
				} else {
					if (*p == '\\')
						escape++;
					else
						write(_wwcurrent->ww_pty, p, 1);
				}
E 2
I 2
		if ((imask & 1<<0) == 0)
E 3
I 3
D 22
	while (!quit) {
D 21
		if (curwin == cmdwin) {
E 21
I 21
		if (incmd) {
E 21
			docmd();
E 3
			continue;
D 3
		n = read(0, buf, sizeof buf);
		for (p = buf; n-- > 0; p++) {
			nread++;
			*p &= 0x7f;
			if (!escape) {
				if (*p == ESCAPE)
					escape++;
				else
					write(curwin->ww_pty, p, 1);
E 3
I 3
		}
I 4
		/*
		 * Loop until we get some keyboard input.
		 */
E 4
		while (ibufc == 0) {
D 12
			wwsetcursor(WCurRow(curwin->ww_win),
				WCurCol(curwin->ww_win));
E 12
I 12
D 21
			wwcurtowin(curwin);
E 21
I 21
			wwcurtowin(selwin);
E 21
			wwupdate();
E 12
			wwflush();
D 4
			imask = 1<<0;
			wwforce(&imask);
			if ((imask & 1<<0) == 0)
E 4
I 4
D 20
			imask = 1 << 0;
			while (wwforce(&imask) < 0)
E 20
I 20
			while (imask = 1, wwforce(&imask) < 0)
E 20
				;
D 20
			if ((imask & 1 << 0) == 0)
E 20
I 20
			if ((imask & 1) == 0)
E 20
E 4
E 3
				continue;
E 2
D 3
			}
I 2
			escape = 0;
			switch (*p) {
			case ESCAPE:
				write(curwin->ww_pty, p, 1);
				break;
			case '1':
				wwsetcurrent(w1);
				break;
			case '2':
				wwsetcurrent(w2);
				break;
			case CTRL(z):
				wwsuspend();
				break;
			case '.':
				goto out;
			/*
			case CTRL(\\):
				wwend();
				kill(getpid(), SIGILL);
				break;
			*/
			case CTRL(l):
				ScreenGarbaged = 1;
				break;
			case 'r':
				curwin->ww_refresh = 0;
				break;
			case 'R':
				curwin->ww_refresh = 1;
				break;
			case 's':
				wwprintf(curwin, "\r\nread: %d, write: %d\r\n",
					nread, wwnwrite);
				break;
			case 't':
				printrusage(curwin, RUSAGE_SELF);
				break;
			case 'T':
				printrusage(curwin, RUSAGE_CHILDREN);
				break;
			case '?':
				help();
				break;
			default:
				c = ESCAPE;
				write(curwin->ww_pty, &c, 1);
				write(curwin->ww_pty, p, 1);
			}
E 3
I 3
D 4
			if (ibufc == 0)
				ibufp = ibuf;
			p = ibufp + ibufc;
			n = read(0, p, ibuf + sizeof ibuf - p);
			if (n > 0)
				ibufc = n;
E 4
I 4
			/* NOTE: ibufc == 0 */
			ibufp = ibuf;
D 7
			if ((ibufc = read(0, ibuf, sizeof ibuf)) < 0)
E 7
I 7
			if ((ibufc = read(0, ibuf, sizeof ibuf)) < 0) {
E 7
				ibufc = 0;
I 7
				nreade++;
			} else if (ibufc == 0)
				nreadz++;
			else
				nreadc += ibufc;
			nread++;
E 7
E 4
E 3
E 2
		}
I 3
D 4
		for (p = ibufp, n = ibufc; n-- > 0 && *p != ESCAPE; p++)
			;
		if ((n = p - ibufp) > 0) {
			write(curwin->ww_pty, ibufp, n);
			ibufp = p;
			ibufc -= n;
		}
		if (*p == ESCAPE) {
			ibufp++;
			ibufc--;
			wwsetcurrent(cmdwin);
E 4
I 4
		/*
D 12
		 * Weird loop.  Copy the buffer to the pty stopping
		 * on the escape character in a hopefully efficient
		 * way.
E 12
I 12
		 * Weird loop.  Copy the buffer to the pty
		 * and stopping on the escape character
		 * in a hopefully efficient way.
E 12
		 * Probably a good thing to make ibufc == 1 a special
		 * case.
		 */
		for (p = ibufp, n = ibufc;;) {
			if (--n < 0) {
D 12
				write(curwin->ww_pty, ibufp, ibufc);
E 12
I 12
D 21
				(void) write(curwin->ww_pty, ibufp, ibufc);
E 21
I 21
				(void) write(selwin->ww_pty, ibufp, ibufc);
E 21
E 12
				ibufp = ibuf;
				ibufc = 0;
				break;
D 8
			} else if (*p++ == ESCAPE) {
E 8
I 8
			} else if (*p++ == escapec) {
E 8
				if ((n = p - ibufp) > 1)
D 12
					write(curwin->ww_pty, ibufp, n - 1);
E 12
I 12
D 21
					(void) write(curwin->ww_pty,
E 21
I 21
					(void) write(selwin->ww_pty,
E 21
						ibufp, n - 1);
E 12
				ibufp = p;
				ibufc -= n;
D 5
				wwsetcurrent(cmdwin);
E 5
I 5
D 12
				wwsetcurwin(cmdwin);
E 12
I 12
D 21
				curwin = cmdwin;
E 21
I 21
				incmd = 1;
E 21
E 12
E 5
				break;
			}
E 4
		}
E 3
	}
E 22
I 22

	mloop();

E 22
I 12
D 42
	wwupdate();
	wwflush();
E 42
E 12
I 2
D 3
out:
E 3
E 2
bad:
D 2
	echo();
	nocrmode();
E 2
	wwend();
	return 0;
I 8
}

usage()
{
D 12
	fprintf(stderr, "window: [-e escape] [-t]\n");
	exit(1);
E 12
I 12
D 14
	(void) fprintf(stderr, "window: [-e escape] [-t] [-f]\n");
E 14
I 14
D 35
	(void) fprintf(stderr, "window: [-e escape-char] [-t] [-f] [-d]\n");
E 35
I 35
	(void) fprintf(stderr, "Usage: window [-e escape-char] [-c command] [-t] [-f] [-d]\n");
E 35
E 14
D 13
	return exit(1);			/* for lint */
E 13
I 13
	exit(1);
	return 0;			/* for lint */
I 35
}

nomem()
{
	(void) fprintf(stderr, "Out of memory.\n");
	exit(1);
E 35
E 13
E 12
E 8
I 2
D 3
}

help()
{
	wwputstr("\r\n");
	wwputstr("^P1   goto top window\r\n");
	wwputstr("^P2   goto bottom window\r\n");
	wwputstr("^PR   force refresh after every newline\r\n");
	wwputstr("^Pr   don't refresh every line\r\n");
	wwputstr("^Ps   print io statistics\r\n");
	wwputstr("^Pt   print resource usage of this program\r\n");
	wwputstr("^PT   print resource usage of children\r\n");
	wwputstr("^P^L  redraw screen\r\n");
	wwputstr("^P^Z  suspend\r\n");
	wwputstr("^P.   quit\r\n");
}

printrusage(w, flag)
register struct ww *w;
{
	struct rusage rusage;
	struct timeval timeval;
	char *strtime();

	gettimeofday(&timeval, &timezone);
	timeval.tv_sec -= starttime.tv_sec;
	if ((timeval.tv_usec -= starttime.tv_usec) < 0) {
		timeval.tv_sec--;
		timeval.tv_usec += 1000000;
	}
	getrusage(flag, &rusage);

	wwprintf(w, "\r\ntime\t\tutime\tstime\tmaxrss\tixrss\tidrss\tisrss\r\n");
	wwprintf(w, "%-16s", strtime(&timeval));
	wwprintf(w, "%-8s", strtime(&rusage.ru_utime));
	wwprintf(w, "%-8s", strtime(&rusage.ru_stime));
	wwprintf(w, "%D\t%D\t%D\t%D\r\n",
		rusage.ru_maxrss, rusage.ru_ixrss,
		rusage.ru_idrss, rusage.ru_isrss);
	wwprintf(w, "minflt\tmajflt\tnswap\tinblk\toublk\tmsgsnd\tmsgrcv\tnsigs\tnvcsw\tnivcsw\r\n");
	wwprintf(w, "%D\%D\t%D\t%D\t%D\t%D\t%D\t%D\t%D\t%D\t%D\r\n",
		rusage.ru_minflt, rusage.ru_majflt, rusage.ru_nswap,
		rusage.ru_inblock, rusage.ru_oublock,
		rusage.ru_msgsnd, rusage.ru_msgrcv, rusage.ru_nsignals,
		rusage.ru_nvcsw, rusage.ru_nivcsw);
}

char *
strtime(t)
register struct timeval *t;
{
	char fill = 0;
	static char buf[20];
	register char *p = buf;

	if (t->tv_sec > 60*60) {
		sprintf(p, "%D:", t->tv_sec / 60*60);
		while (*p++)
			;
		p--;
		t->tv_sec %= 60*60;
		fill++;
	}
	if (t->tv_sec > 60) {
		sprintf(p, fill ? "%02D:" : "%D:", t->tv_sec / 60, ':');
		while (*p++)
			;
		p--;
		t->tv_sec %= 60;
		fill++;
	}
	sprintf(p, fill ? "%02D.%02d" : "%D.%02D",
		t->tv_sec, t->tv_usec / 10000);
	return buf;
E 3
E 2
}
E 1
