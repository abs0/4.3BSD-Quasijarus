h29788
s 00010/00005/00056
d D 3.13 88/06/29 21:38:52 bostic 21 20
c install approved copyright notice
e
s 00013/00007/00048
d D 3.12 88/02/21 13:38:56 bostic 20 19
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00049
d D 3.11 85/04/24 16:19:09 edward 19 18
c copyright messages
e
s 00001/00001/00048
d D 3.10 84/05/23 01:59:50 edward 18 17
c new sccs id
e
s 00004/00005/00045
d D 3.9 84/04/16 20:29:13 edward 17 16
c 4.1a, 4.1c compatibility removed, local.h added
e
s 00022/00016/00028
d D 3.8 84/04/08 19:23:35 edward 16 15
c new options to "window": shell, pty, frame
c and stuff to support them
e
s 00004/00004/00040
d D 3.7 84/01/13 17:16:30 edward 15 14
c lint
e
s 00021/00007/00023
d D 3.6 83/12/01 13:44:09 edward 14 13
c pty hanging bug
e
s 00011/00005/00019
d D 3.5 83/11/29 12:54:28 edward 13 12
c vfork
e
s 00000/00001/00024
d D 3.4 83/10/19 10:36:54 edward 12 11
c no more need for moncontrol(0).
e
s 00001/00000/00024
d D 3.3 83/08/26 16:23:06 edward 11 10
c error reporting
e
s 00000/00044/00024
d D 3.2 83/08/17 14:50:49 edward 10 9
c ww_availmodes and stuff
e
s 00001/00000/00067
d D 3.1 83/08/11 17:21:05 edward 9 7
i 8
c last few day's work
e
s 00013/00017/00054
d D 2.1.1.1 83/08/09 18:33:51 edward 8 7
c mile stone
e
s 00000/00000/00071
d D 2.1 83/07/30 13:26:43 edward 7 6
c prepare for major change
e
s 00004/00001/00067
d D 1.6 83/07/26 14:02:15 edward 6 5
c Function keys passed on to the windows.
e
s 00003/00003/00065
d D 1.5 83/07/22 17:07:16 edward 5 4
c scrolling.
c uses Wscreensize() to get screen size.
c More intelligent framing.
c etc.
e
s 00003/00001/00065
d D 1.4 83/07/19 20:07:31 edward 4 3
c today's work
e
s 00011/00004/00055
d D 1.3 83/07/18 21:02:32 edward 3 2
c multiple window
e
s 00039/00000/00020
d D 1.2 83/07/17 15:42:08 edward 2 1
c 
e
s 00020/00000/00000
d D 1.1 83/07/12 17:20:51 edward 1 0
c date and time created 83/07/12 17:20:51 by edward
e
u
U
f b 
t
T
I 1
D 20
#ifndef lint
D 18
static	char *sccsid = "%W% %E%";
E 18
I 18
static char sccsid[] = "%W% %G%";
E 18
#endif

E 20
I 19
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

E 19
#include "ww.h"
I 14
D 17
#include <signal.h>
E 17
I 17
#include <sys/signal.h>
E 17
E 14

I 14
/*
 * There is a dead lock with vfork and closing of pseudo-ports.
D 16
 * So we have to be sneaky.
E 16
I 16
 * So we have to be sneaky about error reporting.
E 16
 */
E 14
I 4
D 8
extern int _wwdtablesize;
I 6
extern char _wwtermcap[];
E 6

E 8
E 4
D 13
wwfork(wp)
E 13
I 13
D 16
/*VARARGS3*/
wwspawn(wp, file, argv0)
E 16
I 16
wwspawn(wp, file, argv)
E 16
E 13
register struct ww *wp;
I 13
D 16
char *file, *argv0;
E 16
I 16
char *file;
char **argv;
E 16
E 13
{
I 14
D 16
	extern int errno;
	extern char *sys_errlist[];
E 16
E 14
D 13
	switch (wp->ww_pid = fork()) {
E 13
I 13
	int pid;
I 16
	int ret;
	char erred = 0;
I 17
	int s;
E 17
E 16

I 14
D 15
	sighold(SIGCHLD);
E 15
I 15
D 17
	(void) sighold(SIGCHLD);
E 17
I 17
	s = sigblock(sigmask(SIGCHLD));
E 17
E 15
E 14
	switch (pid = vfork()) {
E 13
	case -1:
I 11
		wwerrno = WWE_SYS;
I 14
D 15
		sigrelse(SIGCHLD);
E 15
I 15
D 16
		(void) sigrelse(SIGCHLD);
E 15
E 14
E 11
		return -1;
E 16
I 16
		ret = -1;
		break;
E 16
	case 0:
I 9
D 12
		moncontrol(0);
E 12
E 9
D 8
		wp->ww_state = WW_INCHILD;
E 8
I 8
D 13
		wp->ww_state = WWS_INCHILD;
E 13
E 8
I 2
D 16
		wwenviron(wp);
I 14
		errno = 0;
E 14
E 2
D 13
		return 0;
E 13
I 13
		execv(file, &argv0);
E 16
I 16
		if (wwenviron(wp) >= 0)
			execvp(file, argv);
		erred = 1;
E 16
D 14
		perror(file);
		exit(1);
E 14
I 14
		_exit(1);
E 14
E 13
	default:
I 13
D 14
		wp->ww_pid = pid;
E 13
D 8
		wp->ww_state = WW_HASPROC;
I 3
		close(wp->ww_tty);
E 8
I 8
		wp->ww_state = WWS_HASPROC;
		(void) close(wp->ww_tty);
E 8
		wp->ww_tty = -1;
E 3
D 13
		return wp->ww_pid;
E 13
I 13
		return pid;
E 14
I 14
D 16
		if (errno != 0) {
E 16
I 16
		if (erred) {
E 16
			wwerrno = WWE_SYS;
D 15
			sigrelse(SIGCHLD);
E 15
I 15
D 16
			(void) sigrelse(SIGCHLD);
E 15
			return -1;
E 16
I 16
			ret = -1;
E 16
		} else {
			wp->ww_pid = pid;
			wp->ww_state = WWS_HASPROC;
D 15
			sigrelse(SIGCHLD);
E 15
I 15
D 16
			(void) sigrelse(SIGCHLD);
E 15
			return pid;
E 16
I 16
			ret = pid;
E 16
		}
E 14
E 13
	}
I 16
D 17
	(void) sigrelse(SIGCHLD);
	/*
E 17
I 17
	(void) sigsetmask(s);
E 17
	if (wp->ww_socket >= 0) {
		(void) close(wp->ww_socket);
		wp->ww_socket = -1;
	}
D 17
	*/
E 17
	return ret;
E 16
I 2
}
D 10

D 3
#define TERM "TERM=window"
#define TERMCAP "TERMCAP=WW|window|window package:\
E 3
I 3
#define TERM	"TERM=window"
#define TERMCAP	"TERMCAP=WW|window|window package:\
E 3
	:cr=^M:nl=^J:bl=^G:\
	:al=\\EL:am:le=^H:bs:cd=\\EJ:ce=\\EK:cl=\\EE:cm=\\EY%%+ %%+ :\
D 3
	:co#%d:dc=\\EN:dl=\\EM:do=\\EB:ei=\\EO:ho=\\EH:im=\\E@:li#%d:mi:\
E 3
I 3
	:co#%d:dc=\\EN:dl=\\EM:do=\\EB:ei=\\EO:ho=\\EH:li#%d:im=\\E@:mi:\
E 3
	:nd=\\EC:ta=^I:pt:up=\\EA:"
static char *env[100];
D 6
static char buf[sizeof TERMCAP + 10];
E 6
I 6
static char buf[1024];
E 6
extern char **environ;
I 6
D 8
extern char _wwkeys[];
E 8
E 6

wwenviron(wp)
register struct ww *wp;
{
	register i;
	register char **p, **q;
	char **termcap = 0;

D 8
	dup2(wp->ww_tty, 0);
	dup2(wp->ww_tty, 1);
	dup2(wp->ww_tty, 2);
D 4
	for (i = getdtablesize() - 1; i > 2; i--)
E 4
I 4
	for (i = _wwdtablesize - 1; i > 2; i--)
E 4
		close(i);
E 8
I 8
	(void) dup2(wp->ww_tty, 0);
	(void) dup2(wp->ww_tty, 1);
	(void) dup2(wp->ww_tty, 2);
	for (i = wwdtablesize - 1; i > 2; i--)
		(void) close(i);
E 8
I 3
D 5
	/*
E 5
I 5

E 5
	i = open("/dev/tty");
D 8
	ioctl(i, TIOCNOTTY, 0);
	close(i);
D 5
	*/
E 5
I 5
	open(wp->ww_ttyname, 0);
E 8
I 8
	(void) ioctl(i, (int)TIOCNOTTY, (char *)0);
	(void) close(i);
	(void) open(wp->ww_ttyname, 0);
E 8
E 5
E 3

	for (p = environ, q = env; *p; p++, q++) {
		if (strncmp(*p, "TERM=", 5) == 0)
			*q = TERM;
		else if (strncmp(*p, "TERMCAP=", 8) == 0)
			termcap = q;
		else
			*q = *p;
	}
	if (termcap == 0)
		termcap = q++;
	*q = 0;
D 3
	*termcap = sprintf(buf, TERMCAP, wp->ww_ncol, wp->ww_nrow);
E 3
I 3
D 5
	*termcap = sprintf(buf, TERMCAP, wp->ww_incol, wp->ww_inrow);
E 5
I 5
D 8
	*termcap = sprintf(buf, TERMCAP, wp->ww_i.ncol, wp->ww_i.nrow);
I 6
	strcat(buf, _wwkeys);
E 8
I 8
	*termcap = sprintf(buf, TERMCAP, wp->ww_w.nc, wp->ww_w.nr);
	(void) strcat(buf, wwkeys);
E 8
E 6
E 5
E 3
	environ = env;
E 2
}
E 10
E 1
