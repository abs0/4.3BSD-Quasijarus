h27159
s 00010/00005/00056
d D 3.20 88/06/29 21:38:01 bostic 21 20
c install approved copyright notice
e
s 00002/00009/00059
d D 3.19 88/06/21 17:30:16 edward 20 19
c made the window termcap more terminal specific (al, dl, dc, etc.)
e
s 00013/00007/00055
d D 3.18 88/02/21 13:38:19 bostic 19 18
c written by Edward Wang; attach Berkeley specific copyright
e
s 00010/00001/00052
d D 3.17 87/10/01 22:46:01 edward 18 17
c use setenv() to set up environment, WINDOW_ID added (from mips!dce)
e
s 00002/00000/00051
d D 3.16 87/05/26 22:52:18 edward 17 16
c sigsetmask(0) as well as unignore signals
e
s 00002/00002/00049
d D 3.15 86/08/05 01:24:53 edward 16 15
c lint
e
s 00004/00001/00047
d D 3.14 86/08/04 14:16:45 edward 15 13
c WWM_USR and WWM_DIM added, termcap strings XS and XE added,
c display mode escape sequences changed
e
s 00002/00001/00047
d R 3.14 86/05/02 13:36:21 edward 14 13
c added WWM_USR (user mode) and XS and XE termcap strings
e
s 00006/00000/00042
d D 3.13 85/04/24 16:18:04 edward 13 12
c copyright messages
e
s 00002/00001/00040
d D 3.12 84/06/02 17:41:41 edward 12 11
c set SIGPIPE back before exec
e
s 00001/00001/00040
d D 3.11 84/05/23 01:59:24 edward 11 10
c new sccs id
e
s 00010/00011/00031
d D 3.10 84/04/08 19:23:32 edward 10 9
c new options to "window": shell, pty, frame
c and stuff to support them
e
s 00001/00031/00041
d D 3.9 84/03/23 18:17:13 edward 9 8
c compile with -R
e
s 00001/00001/00071
d D 3.8 84/01/13 17:16:24 edward 8 7
c lint
e
s 00006/00007/00066
d D 3.7 84/01/11 16:29:29 edward 7 6
c make graphics mode available to user
e
s 00004/00000/00069
d D 3.6 83/12/03 00:11:59 edward 6 5
c change to new pgrp and set the tty accordingly.
e
s 00011/00016/00058
d D 3.5 83/12/01 13:44:02 edward 5 4
c pty hanging bug
e
s 00029/00023/00045
d D 3.4 83/11/29 12:53:39 edward 4 3
c vfork
e
s 00019/00005/00049
d D 3.3 83/08/31 19:03:39 edward 3 2
c open(/dev/tty) called with only one argument
e
s 00002/00001/00052
d D 3.2 83/08/18 15:27:47 edward 2 1
c da and db flags now needed with scrolling
c and new WWT_TERMCAP scheme
e
s 00053/00000/00000
d D 3.1 83/08/17 14:52:46 edward 1 0
c date and time created 83/08/17 14:52:46 by edward
e
u
U
t
T
I 1
D 19
#ifndef lint
D 11
static	char *sccsid = "%W% %E%";
E 11
I 11
static char sccsid[] = "%W% %G%";
E 11
#endif

E 19
I 13
/*
D 19
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 19
I 19
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
E 19
 */
I 19

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 19

E 13
#include "ww.h"
I 12
#include <sys/signal.h>
E 12

D 4
extern char **environ;

E 4
I 3
/*
 * Set up the environment of this process to run in window 'wp'.
D 5
 * Can't report errors in any intelligent way, so don't.
E 5
I 5
D 10
 * Can't report errors in any intelligent way, because the parent
 * hangs in vfork() until we die, but we can't die until output
 * drains (i.e. deadlock).  So don't say anything.
E 10
E 5
 */
E 3
wwenviron(wp)
register struct ww *wp;
{
I 4
D 9
	static char **termcap = 0;
	static char *tbuf;
E 9
E 4
	register i;
I 6
	int pgrp = getpid();
I 18
	char buf[1024];
E 18
E 6
D 4
	register char **p, **q;
	char **termcap = 0;
	char **env;
	char *tbuf;
E 4

D 5
	(void) dup2(wp->ww_tty, 0);
	(void) dup2(wp->ww_tty, 1);
	(void) dup2(wp->ww_tty, 2);
	for (i = wwdtablesize - 1; i > 2; i--)
		(void) close(i);

E 5
D 3
	i = open("/dev/tty");
	(void) ioctl(i, (int)TIOCNOTTY, (char *)0);
E 3
I 3
D 10
	i = open("/dev/tty", 0);
D 5
	if (i < 0) {
		perror("/dev/tty");
E 5
I 5
	if (i < 0)
E 5
		return;
E 10
I 10
	if ((i = open("/dev/tty", 0)) < 0)
		goto bad;
E 10
D 5
	}
	if (ioctl(i, (int)TIOCNOTTY, (char *)0) < 0) {
		perror("ioctl(TIOCNOTTY)");
E 5
I 5
D 16
	if (ioctl(i, (int)TIOCNOTTY, (char *)0) < 0)
E 16
I 16
	if (ioctl(i, TIOCNOTTY, (char *)0) < 0)
E 16
E 5
D 10
		return;
E 10
I 10
		goto bad;
E 10
D 5
	}
E 5
E 3
	(void) close(i);
D 3
	(void) open(wp->ww_ttyname, 0);
E 3
I 3
D 5
	if (open(wp->ww_ttyname, 0) < 0) {
		perror(wp->ww_ttyname);
E 5
I 5
D 10
	if ((i = open(wp->ww_ttyname, 2)) < 0)
E 5
		return;
E 10
I 10
	if ((i = wp->ww_socket) < 0 && (i = open(wp->ww_ttyname, 2)) < 0)
		goto bad;
E 10
D 5
	}
E 5
I 5
	(void) dup2(i, 0);
	(void) dup2(i, 1);
	(void) dup2(i, 2);
	for (i = wwdtablesize - 1; i > 2; i--)
		(void) close(i);
I 6
D 8
	if (ioctl(0, (int)TIOCSPGRP, &pgrp) < 0)
E 8
I 8
D 10
	if (ioctl(0, (int)TIOCSPGRP, (char *)&pgrp) < 0)
E 8
		return;
E 10
I 10
D 16
	(void) ioctl(0, (int)TIOCSPGRP, (char *)&pgrp);
E 16
I 16
	(void) ioctl(0, TIOCSPGRP, (char *)&pgrp);
E 16
E 10
	(void) setpgrp(pgrp, pgrp);
I 17
	/* SIGPIPE is the only one we ignore */
E 17
E 6
E 5
E 3
D 12

E 12
I 12
	(void) signal(SIGPIPE, SIG_DFL);
I 17
	(void) sigsetmask(0);
E 17
E 12
D 4
	for (i = 0, p = environ; *p; p++, i++)
		;
	if ((env = (char **)malloc((unsigned)(i + 3) * sizeof (char *))) == 0)
D 3
		return;			/* can't report error */
E 3
I 3
		return;
E 3
	if ((tbuf = malloc((unsigned) 1024)) == 0)
D 3
		return;			/* can't report error */
E 3
I 3
		return;
E 3
	for (p = environ, q = env; *p; p++, q++) {
		if (strncmp(*p, "TERM=", 5) == 0)
			*q = WWT_TERM;
		else if (strncmp(*p, "TERMCAP=", 8) == 0)
			termcap = q;
		else
			*q = *p;
E 4
I 4
D 9
	/*
	 * Do this only once if vfork().
	 */
	if (termcap == 0) {
		extern char **environ;
		static char **env;
		register char **p, **q;

		for (i = 0, p = environ; *p; p++, i++)
			;
		env = (char **)malloc((unsigned)(i + 3) * sizeof (char *));
		if (env == 0)
			return;
		if ((tbuf = malloc((unsigned) 1024)) == 0)
			return;
		for (p = environ, q = env; *p; p++, q++) {
			if (strncmp(*p, "TERM=", 5) == 0)
				*q = WWT_TERM;
			else if (strncmp(*p, "TERMCAP=", 8) == 0)
				termcap = q;
			else
				*q = *p;
		}
		if (termcap == 0)
			termcap = q++;
		*q = 0;
		environ = env;
E 4
	}
D 4
	if (termcap == 0)
		termcap = q++;
	*q = 0;
E 4
D 2
	*termcap = sprintf(tbuf, WWT_TERMCAP, wp->ww_w.nc, wp->ww_w.nr);
E 2
I 2
D 7
	*termcap = sprintf(tbuf, "TERMCAP=%sco#%d:li#%d:",
		WWT_TERMCAP, wp->ww_w.nc, wp->ww_w.nr);
E 2
	if (wwavailmodes & WWM_REV)
		(void) strcat(tbuf, WWT_REV);
	if (wwavailmodes & WWM_UL)
		(void) strcat(tbuf, WWT_UL);
	(void) strcat(tbuf, wwkeys);
E 7
I 7
	*termcap = sprintf(tbuf, "TERMCAP=%sco#%d:li#%d:%s%s%s%s",
E 9
I 9
D 15
	(void) sprintf(wwwintermcap, "TERMCAP=%sco#%d:li#%d:%s%s%s%s",
E 15
I 15
D 18
	(void) sprintf(wwwintermcap, "TERMCAP=%sco#%d:li#%d:%s%s%s%s%s%s%s",
E 18
I 18
	/*
	 * Two conditions that make destructive setenv ok:
	 * 1. setenv() copies the string,
	 * 2. we've already called tgetent which copies the termcap entry.
	 */
D 20
	(void) sprintf(buf, "%sco#%d:li#%d:%s%s%s%s%s%s%s",
E 18
E 15
E 9
		WWT_TERMCAP, wp->ww_w.nc, wp->ww_w.nr,
		wwavailmodes & WWM_REV ? WWT_REV : "",
I 15
		wwavailmodes & WWM_BLK ? WWT_BLK : "",
E 15
		wwavailmodes & WWM_UL ? WWT_UL : "",
		wwavailmodes & WWM_GRP ? WWT_GRP : "",
I 15
		wwavailmodes & WWM_DIM ? WWT_DIM : "",
		wwavailmodes & WWM_USR ? WWT_USR : "",
E 15
		wwkeys);
E 20
I 20
	(void) sprintf(buf, "%sco#%d:li#%d:%s",
		WWT_TERMCAP, wp->ww_w.nc, wp->ww_w.nr, wwwintermcap);
E 20
I 18
	(void) setenv("TERMCAP", buf, 1);
	(void) sprintf(buf, "%d", wp->ww_id + 1);
	(void) setenv("WINDOW_ID", buf, 1);
E 18
I 10
	return 0;
bad:
	wwerrno = WWE_SYS;
	return -1;
E 10
E 7
D 4
	environ = env;
E 4
}
E 1
