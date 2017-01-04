h55917
s 00010/00005/00031
d D 3.15 88/06/29 21:37:29 bostic 21 20
c install approved copyright notice
e
s 00013/00007/00023
d D 3.14 88/02/21 13:38:03 bostic 20 19
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00024
d D 3.13 85/04/24 16:13:33 edward 19 18
c copyright messages
e
s 00001/00001/00023
d D 3.12 85/03/01 17:33:56 edward 18 17
c BUG--should be ww_b not ww_w in wwfree(w->ww_buf, ...)
e
s 00001/00001/00023
d D 3.11 84/05/23 01:57:09 edward 17 16
c new sccs id
e
s 00004/00001/00020
d D 3.10 84/04/08 19:23:07 edward 16 15
c new options to "window": shell, pty, frame
c and stuff to support them
e
s 00002/00000/00019
d D 3.9 84/03/02 17:52:10 edward 15 14
c Forgot to free ww_ob.
e
s 00000/00002/00019
d D 3.8 83/12/06 15:25:33 edward 14 13
c don't bother killing the proc, since ptcclose does it
e
s 00001/00004/00020
d D 3.7 83/12/01 13:43:49 edward 13 12
c pty hanging bug
e
s 00000/00001/00024
d D 3.6 83/11/23 16:35:25 edward 12 11
c New cover scheme
e
s 00005/00005/00020
d D 3.5 83/09/15 10:09:02 edward 11 10
c Now uses screen address for all buffers.
e
s 00005/00002/00020
d D 3.4 83/08/26 17:29:26 edward 10 9
c check ww_haspty before closing ww_pty and ww_tty.
e
s 00002/00000/00020
d D 3.3 83/08/23 18:19:17 edward 9 7
c free ww_fmap if any
e
s 00002/00000/00020
d R 3.3 83/08/23 18:12:10 edward 8 7
c free ww_fmap if anyway
e
s 00003/00003/00017
d D 3.2 83/08/19 12:20:44 edward 7 6
c wwfree changed
e
s 00000/00000/00020
d D 3.1 83/08/11 17:22:15 edward 6 4
i 5
c last few day's work
e
s 00009/00016/00011
d D 2.1.1.1 83/08/09 18:35:35 edward 5 4
c mile stone
e
s 00000/00000/00027
d D 2.1 83/07/30 13:26:36 edward 4 3
c prepare for major change
e
s 00000/00000/00027
d D 1.3 83/07/22 17:10:17 edward 3 2
c scrolling.
c uses Wscreensize() to get screen size.
c More intelligent framing.
c etc.
e
s 00000/00000/00027
d D 1.2 83/07/19 20:08:08 edward 2 1
c today's work
e
s 00027/00000/00000
d D 1.1 83/07/18 21:05:16 edward 1 0
c date and time created 83/07/18 21:05:16 by edward
e
u
U
f b 
t
T
I 1
D 20
#ifndef lint
D 17
static	char *sccsid = "%W% %E%";
E 17
I 17
static char sccsid[] = "%W% %G%";
E 17
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
#include <signal.h>

wwclose(w)
register struct ww *w;
{
D 5
	register struct ww **p;

	for (p = &wwhead; *p && *p != w; p = &(*p)->ww_next)
		;
	if (*p == 0)
		return -1;
	*p = w->ww_next;
	if (curwin == w)
		curwin = wwhead;
	if (w->ww_state == WW_HASPROC)
		kill(w->ww_pid, SIGHUP);
	close(w->ww_tty);
	close(w->ww_pty);
	Wclose(w->ww_win);
	cfree(w);
	return 0;
E 5
I 5
	wwindex[w->ww_index] = 0;
D 14
	if (w->ww_state == WWS_HASPROC)
		(void) kill(w->ww_pid, SIGHUP);
E 14
D 10
	(void) close(w->ww_tty);
	(void) close(w->ww_pty);
E 10
I 10
D 13
	if (w->ww_haspty) {
		(void) close(w->ww_tty);
		(void) close(w->ww_pty);
	}
E 13
I 13
D 16
	(void) close(w->ww_pty);
E 16
I 16
	if (w->ww_pty >= 0)
		(void) close(w->ww_pty);
	if (w->ww_socket >= 0)
		(void) close(w->ww_socket);
E 16
E 13
E 10
D 7
	wwfree((char **)w->ww_win, w->ww_w.nr);
	wwfree((char **)w->ww_cov, w->ww_w.nr);
	wwfree((char **)w->ww_buf, w->ww_nline);
E 7
I 7
D 11
	wwfree((char **)w->ww_win);
	wwfree((char **)w->ww_cov);
	wwfree((char **)w->ww_buf);
E 11
I 11
	wwfree((char **)w->ww_win, w->ww_w.t);
D 12
	wwfree((char **)w->ww_cov, w->ww_w.t);
E 12
D 18
	wwfree((char **)w->ww_buf, w->ww_w.t);
E 18
I 18
	wwfree((char **)w->ww_buf, w->ww_b.t);
E 18
E 11
I 9
	if (w->ww_fmap != 0)
D 11
		wwfree((char **)w->ww_fmap);
I 10
	free((char *)w->ww_nvis);
E 11
I 11
		wwfree((char **)w->ww_fmap, w->ww_w.t);
	free((char *)(w->ww_nvis + w->ww_w.t));
I 15
	if (w->ww_ob != 0)
		free(w->ww_ob);
E 15
E 11
E 10
E 9
E 7
	free((char *)w);
E 5
}
E 1
