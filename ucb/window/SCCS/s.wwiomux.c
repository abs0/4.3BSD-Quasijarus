h25029
s 00010/00005/00152
d D 3.19 88/06/29 21:38:21 bostic 26 25
c install approved copyright notice
e
s 00017/00004/00140
d D 3.18 88/03/16 19:46:09 edward 25 24
c defensive code against clearing of ASYNC by wall
e
s 00013/00007/00131
d D 3.17 88/02/21 13:38:33 bostic 24 23
c written by Edward Wang; attach Berkeley specific copyright
e
s 00093/00084/00045
d D 3.16 87/06/08 02:28:13 edward 23 22
c interrupt mechanism reworked, make SIGCHLD interrupt also
e
s 00006/00005/00123
d D 3.15 85/09/19 14:10:13 edward 22 21
c use fd_set for select
e
s 00006/00000/00122
d D 3.14 85/04/24 16:19:19 edward 21 20
c copyright messages
e
s 00002/00001/00120
d D 3.13 85/03/13 19:50:14 edward 20 19
c don't select on ptys with full buffers
e
s 00002/00001/00119
d D 3.12 85/02/27 17:08:23 edward 19 18
c read on closed socketpair returns eof
e
s 00001/00001/00119
d D 3.11 84/05/23 01:59:53 edward 18 17
c new sccs id
e
s 00047/00042/00073
d D 3.10 84/04/08 19:23:38 edward 17 16
c new options to "window": shell, pty, frame
c and stuff to support them
e
s 00015/00018/00100
d D 3.9 84/03/06 13:49:03 edward 16 15
c should check ww_ob always
e
s 00044/00033/00074
d D 3.8 84/03/03 22:47:43 edward 15 14
c interrupt driven input
e
s 00097/00024/00010
d D 3.7 84/01/16 15:26:28 edward 14 13
c new io scheme
e
s 00001/00001/00033
d D 3.6 84/01/13 17:15:53 edward 13 12
c lint
e
s 00005/00006/00029
d D 3.5 83/12/01 13:43:44 edward 12 11
c pty hanging bug
e
s 00005/00001/00030
d D 3.4 83/10/27 13:23:13 edward 11 10
c bug with closed tty line
e
s 00003/00003/00028
d D 3.3 83/08/26 17:19:30 edward 10 9
c bug with wwforce hanging
e
s 00003/00001/00028
d D 3.2 83/08/26 16:22:55 edward 9 8
c error reporting
e
s 00000/00000/00029
d D 3.1 83/08/11 17:21:02 edward 8 6
i 7
c last few day's work
e
s 00011/00013/00018
d D 2.1.1.1 83/08/09 18:33:46 edward 7 6
c mile stone
e
s 00000/00000/00031
d D 2.1 83/07/30 13:26:41 edward 6 5
c prepare for major change
e
s 00000/00000/00031
d D 1.5 83/07/22 17:07:11 edward 5 4
c scrolling.
c uses Wscreensize() to get screen size.
c More intelligent framing.
c etc.
e
s 00003/00001/00028
d D 1.4 83/07/19 20:07:28 edward 4 3
c today's work
e
s 00002/00001/00027
d D 1.3 83/07/18 21:02:21 edward 3 2
c multiple window
e
s 00004/00005/00024
d D 1.2 83/07/17 15:42:05 edward 2 1
c 
e
s 00029/00000/00000
d D 1.1 83/07/12 17:20:48 edward 1 0
c date and time created 83/07/12 17:20:48 by edward
e
u
U
f b 
t
T
I 1
D 24
#ifndef lint
D 18
static	char *sccsid = "%W% %E%";
E 18
I 18
static char sccsid[] = "%W% %G%";
E 18
#endif

E 24
I 21
/*
D 24
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 24
I 24
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
E 24
 */
I 24

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 24

E 21
#include "ww.h"
I 14
#include <sys/time.h>
I 22
#include <sys/types.h>
I 25
#include <fcntl.h>
E 25
E 22
E 14

I 4
D 7
extern int _wwdtablesize;

E 7
E 4
D 14
wwforce(imask)
register int *imask;
E 14
I 14
/*
D 15
 * Multiple window IO handler.
E 15
I 15
 * Multiple window output handler.
 * The idea is to copy window outputs to the terminal, via the
 * display package.  We try to give the top most window highest
 * priority.  The only return condition is when there is keyboard
D 23
 * input, which is serviced asynchronously by wwrint().
E 23
I 23
 * input or when a child process dies which are serviced by signal
 * catchers (wwrint() and wwchild()).
E 23
 * When there's nothing to do, we sleep in a select().
 * This can be done better with interrupt driven io.  But that's
 * not supported on ptys, yet.
 * The history of this routine is interesting.
E 15
 */
wwiomux()
E 14
{
D 7
	register struct ww *w;
E 7
I 7
D 14
	register struct ww **w;
E 7
	char buf[512];
	register int n;
E 14
I 14
	register struct ww *w;
D 22
	int imask;
E 22
I 22
	fd_set imask;
E 22
D 15
	char dont_block;
	register char *p;
E 15
	register n;
I 15
	register char *p;
E 15
	char c;
D 25
	static struct timeval tv = { 0, 0 };
E 25
I 25
	struct timeval tv;
E 25
I 15
	char noblock;
E 15
E 14
D 2
	register char *p;
E 2

D 2
	for (w = _wwhead; w; w = w->ww_next)
E 2
I 2
D 7
	for (w = wwhead; w; w = w->ww_next)
E 2
D 3
		*imask |= 1 << w->ww_pty;
E 3
I 3
		if (w->ww_pty >= 0)
			*imask |= 1 << w->ww_pty;
E 3
D 4
	n = select(getdtablesize(), imask,
E 4
I 4
	n = select(_wwdtablesize, imask,
E 4
		(int *)0, (int *)0, (struct timeval *)0);
E 7
I 7
D 14
	for (w = wwindex; w < &wwindex[NWW]; w++)
D 12
		if (*w && (*w)->ww_haspty && (*w)->ww_pty >= 0)
E 12
I 12
		if (*w && (*w)->ww_pty >= 0)
E 12
			*imask |= 1 << (*w)->ww_pty;
I 10
	if (*imask == 0)
		return -1;
I 12
D 13
	fflush(stdout);
E 13
I 13
	(void) fflush(stdout);
E 13
E 12
E 10
	n = select(wwdtablesize, imask, (int *)0, (int *)0,
		(struct timeval *)0);
E 7
D 9
	if (n <= 0)
E 9
I 9
D 10
	if (n <= 0) {
		wwerrno = WWE_SYS;
E 10
I 10
	if (n <= 0)
E 10
E 9
		return -1;
I 9
D 10
	}
E 10
E 9
D 2
	for (w = _wwhead; w; w = w->ww_next) {
E 2
I 2
D 7
	for (w = wwhead; w; w = w->ww_next) {
E 2
		if (*imask & 1<<w->ww_pty) {
			n = read(w->ww_pty, buf, sizeof buf);
E 7
I 7
	for (w = wwindex; w < &wwindex[NWW]; w++)
D 12
		if (*w && (*w)->ww_haspty && (*w)->ww_pty >= 0
		    && *imask & 1 << (*w)->ww_pty) {
E 12
I 12
		if (*w && (*w)->ww_pty >= 0 && *imask & 1 << (*w)->ww_pty) {
E 12
			n = read((*w)->ww_pty, buf, sizeof buf);
E 7
D 2
			for (p = buf; n-- > 0; p++)
				wwputc(*p, w);
E 2
I 2
D 11
			if (n > 0)
E 11
I 11
			if (n < 0) {
D 12
				(*w)->ww_haspty = 0;
E 12
				(void) close((*w)->ww_pty);
D 12
				(void) close((*w)->ww_tty);
E 12
I 12
				(*w)->ww_pty = -1;
E 12
			} else if (n > 0)
E 11
D 7
				wwwrite(w, buf, n);
E 7
I 7
D 12
				(void) wwwrite((*w), buf, n);
E 12
I 12
				(void) wwwrite(*w, buf, n);
E 14
I 14
D 23
loop:
D 15
	imask = 1;
	dont_block = 0;
E 15
I 15
	if (wwinterrupt())
		return;

D 22
	imask = 0;
E 22
I 22
	FD_ZERO(&imask);
E 22
	noblock = 0;
E 15
	for (w = wwhead.ww_forw; w != &wwhead; w = w->ww_forw) {
		if (w->ww_pty < 0)
			continue;
D 15
		if (w->ww_obp + w->ww_obc < w->ww_obe)
			imask |= 1 << w->ww_pty;
		if (w->ww_obc != 0 && !w->ww_stopped)
			dont_block = 1;
E 15
I 15
D 20
		imask |= 1 << w->ww_pty;
E 20
I 20
		if (w->ww_obq < w->ww_obe)
D 22
			imask |= 1 << w->ww_pty;
E 22
I 22
			FD_SET(w->ww_pty, &imask);
E 22
E 20
D 17
		if (w->ww_obc > 0 && !w->ww_stopped)
E 17
I 17
		if (w->ww_obq > w->ww_obp && !w->ww_stopped)
E 17
			noblock = 1;
E 15
	}
D 15
	if (!dont_block) {
E 15
I 15

	if (!noblock) {
		if (wwcurwin != 0)
			wwcurtowin(wwcurwin);
E 15
		wwupdate();
		wwflush();
I 15
		if (setjmp(wwjmpbuf))
			return;
		wwsetjmp = 1;
E 23
I 23
	for (;;) {
E 23
		if (wwinterrupt()) {
D 23
			wwsetjmp = 0;
E 23
I 23
			wwclrintr();
E 23
			return;
		}
E 15
D 23
	}
	wwnselect++;
D 22
	n = select(wwdtablesize, &imask, (int *)0, (int *)0,
E 22
I 22
	n = select(wwdtablesize, &imask, (fd_set *)0, (fd_set *)0,
E 22
D 15
		dont_block ? &tv : (struct timeval *)0);
E 15
I 15
		noblock ? &tv : (struct timeval *)0);
	wwsetjmp = 0;
E 23

E 15
D 23
	if (n < 0)
		wwnselecte++;
D 15
	else if (imask & 1) {
		if (wwibc == 0)
			p = wwibp = wwib;
		else
			p = wwibp + wwibc;
		n = wwibe - p;
		wwnread++;
		if ((n = read(0, p, n)) > 0) {
			wwibc += n;
			wwnreadc += n;
		} else if (n == 0)
			wwnreadz++;
		else
			wwnreade++;
	} else if (imask != 0 || dont_block) {
E 15
I 15
D 16
	else if (n == 0)
		wwnselectz++;
E 16
D 17
	else {
E 15
D 16
		char first_time = 1;
D 15
		if (n == 0)
			wwnselectz++;
E 15
		for (w = wwhead.ww_forw; w != &wwhead; w = w->ww_forw) {
			if (w->ww_pty < 0)
				continue;
			if (imask & 1 << w->ww_pty) {
E 16
I 16
		if (n == 0)
			wwnselectz++;
		for (w = wwhead.ww_forw; w != &wwhead; w = w->ww_forw)
			if (w->ww_pty >= 0 && imask & 1 << w->ww_pty) {
E 16
				wwnwread++;
				p = w->ww_obp + w->ww_obc;
				if (p == w->ww_ob)
E 17
I 17
	else if (n == 0)
		wwnselectz++;
	else
E 23
I 23
		FD_ZERO(&imask);
		noblock = 0;
E 23
		for (w = wwhead.ww_forw; w != &wwhead; w = w->ww_forw) {
D 22
			if (w->ww_pty < 0 || (imask & 1 << w->ww_pty) == 0)
E 22
I 22
D 23
			if (w->ww_pty < 0 || !FD_ISSET(w->ww_pty, &imask))
E 23
I 23
			if (w->ww_pty < 0)
E 23
E 22
				continue;
D 23
			wwnwread++;
			p = w->ww_obq;
			if (w->ww_ispty) {
				if (p == w->ww_ob) {
E 17
					w->ww_obp++;
D 17
				else
E 17
I 17
					w->ww_obq++;
				} else
E 17
					p--;
				c = *p;
E 23
I 23
			if (w->ww_obq < w->ww_obe)
				FD_SET(w->ww_pty, &imask);
			if (w->ww_obq > w->ww_obp && !w->ww_stopped)
				noblock = 1;
		}

		if (!noblock) {
			if (wwcurwin != 0)
				wwcurtowin(wwcurwin);
			wwupdate();
			wwflush();
			setjmp(wwjmpbuf);
			wwsetjmp = 1;
			if (wwinterrupt()) {
				wwsetjmp = 0;
				wwclrintr();
				return;
E 23
D 17
				n = read(w->ww_pty, p, w->ww_obe - p);
				if (n < 0) {
					wwnwreade++;
					(void) close(w->ww_pty);
					w->ww_pty = -1;
					continue;
				} else if (n == 0) {
					wwnwreadz++;
				} else if (*p == TIOCPKT_DATA) {
I 15
					n--;
E 15
					wwnwreadd++;
D 15
					wwnwreadc += n - 1;
					w->ww_obc += n - 1;
E 15
I 15
					wwnwreadc += n;
					w->ww_obc += n;
E 15
				} else {
					wwnwreadp++;
					if (*p & TIOCPKT_STOP)
						w->ww_stopped = 1;
					if (*p & TIOCPKT_START)
						w->ww_stopped = 0;
					if (*p & TIOCPKT_FLUSHWRITE) {
I 15
						w->ww_stopped = 0;
E 15
						w->ww_obp = w->ww_ob;
						w->ww_obc = 0;
D 15
						w->ww_stopped = 0;
E 15
					}
E 17
I 17
			}
D 23
			n = read(w->ww_pty, p, w->ww_obe - p);
			if (n < 0) {
				wwnwreade++;
				(void) close(w->ww_pty);
				w->ww_pty = -1;
D 19
				continue;
E 19
			} else if (n == 0) {
				wwnwreadz++;
I 19
				(void) close(w->ww_pty);
				w->ww_pty = -1;
E 19
			} else if (!w->ww_ispty) {
				wwnwreadd++;
				wwnwreadc += n;
				w->ww_obq += n;
			} else if (*p == TIOCPKT_DATA) {
				n--;
				wwnwreadd++;
				wwnwreadc += n;
				w->ww_obq += n;
			} else {
				wwnwreadp++;
				if (*p & TIOCPKT_STOP)
					w->ww_stopped = 1;
				if (*p & TIOCPKT_START)
					w->ww_stopped = 0;
				if (*p & TIOCPKT_FLUSHWRITE) {
					w->ww_stopped = 0;
E 23
I 23
D 25
		}
E 25
I 25
			/*
			 * Defensive code.  If somebody else (for example,
			 * wall) clears the ASYNC flag on us, we will block
			 * forever.  So we need a finite timeout and set
			 * the flag again.  Anything more clever will probably
			 * need even more system calls.  (This is a bug
			 * in the kernel.)
			 * I don't like this one bit.
			 */
			fcntl(0, F_SETFL, wwnewtty.ww_fflags);
			tv.tv_sec = 30;
		} else
			tv.tv_sec = 0;
		tv.tv_usec = 0;
E 25
		wwnselect++;
D 25
		n = select(wwdtablesize, &imask, (fd_set *)0, (fd_set *)0,
			noblock ? &tv : (struct timeval *)0);
E 25
I 25
		n = select(wwdtablesize, &imask, (fd_set *)0, (fd_set *)0, &tv);
E 25
		wwsetjmp = 0;

		if (n < 0)
			wwnselecte++;
		else if (n == 0)
			wwnselectz++;
		else
			for (w = wwhead.ww_forw; w != &wwhead; w = w->ww_forw) {
				if (w->ww_pty < 0 ||
				    !FD_ISSET(w->ww_pty, &imask))
					continue;
				wwnwread++;
				p = w->ww_obq;
				if (w->ww_ispty) {
					if (p == w->ww_ob) {
						w->ww_obp++;
						w->ww_obq++;
					} else
						p--;
					c = *p;
				}
				n = read(w->ww_pty, p, w->ww_obe - p);
				if (n < 0) {
					wwnwreade++;
					(void) close(w->ww_pty);
					w->ww_pty = -1;
				} else if (n == 0) {
					wwnwreadz++;
					(void) close(w->ww_pty);
					w->ww_pty = -1;
				} else if (!w->ww_ispty) {
					wwnwreadd++;
					wwnwreadc += n;
					w->ww_obq += n;
				} else if (*p == TIOCPKT_DATA) {
					n--;
					wwnwreadd++;
					wwnwreadc += n;
					w->ww_obq += n;
				} else {
					wwnwreadp++;
					if (*p & TIOCPKT_STOP)
						w->ww_stopped = 1;
					if (*p & TIOCPKT_START)
						w->ww_stopped = 0;
					if (*p & TIOCPKT_FLUSHWRITE) {
						w->ww_stopped = 0;
						w->ww_obq = w->ww_obp =
							w->ww_ob;
					}
				}
				if (w->ww_ispty)
					*p = c;
			}
		for (w = wwhead.ww_forw; w != &wwhead; w = w->ww_forw)
			if (w->ww_pty >= 0 && w->ww_obq > w->ww_obp &&
			    !w->ww_stopped) {
				n = wwwrite(w, w->ww_obp,
					w->ww_obq - w->ww_obp);
				if ((w->ww_obp += n) == w->ww_obq)
E 23
					w->ww_obq = w->ww_obp = w->ww_ob;
I 23
				if (wwinterrupt()) {
					wwclrintr();
					return;
E 23
E 17
				}
I 23
				break;
E 23
D 17
				*p = c;
E 17
			}
D 16
			if (first_time && w->ww_obc != 0 && !w->ww_stopped) {
				first_time = 0;
D 15
				/* XXX */
				n = wwwrite(w, w->ww_obp, MIN(w->ww_obc, 50));
E 15
I 15
				n = wwwrite(w, w->ww_obp, w->ww_obc);
E 15
				if (w->ww_obc -= n)
					w->ww_obp += n;
				else
					w->ww_obp = w->ww_ob;
I 15
				if (wwinterrupt())
					return;
E 15
			}
E 14
E 12
E 7
E 2
		}
E 16
D 7
	}
E 7
D 14
	return 0;
E 14
I 14
D 17
	}
E 17
I 17
D 23
			if (w->ww_ispty)
				*p = c;
		}
E 17
I 16
	for (w = wwhead.ww_forw; w != &wwhead; w = w->ww_forw)
D 17
		if (w->ww_pty >= 0 && w->ww_obc != 0 && !w->ww_stopped) {
			n = wwwrite(w, w->ww_obp, w->ww_obc);
			if (w->ww_obc -= n)
				w->ww_obp += n;
			else
				w->ww_obp = w->ww_ob;
E 17
I 17
		if (w->ww_pty >= 0 && w->ww_obq > w->ww_obp && !w->ww_stopped) {
			n = wwwrite(w, w->ww_obp, w->ww_obq - w->ww_obp);
			if ((w->ww_obp += n) == w->ww_obq)
				w->ww_obq = w->ww_obp = w->ww_ob;
E 17
			if (wwinterrupt())
				return;
			break;
		}
E 16
I 15
	goto loop;
E 23
I 23
	}
E 23
E 15
E 14
}
E 1
