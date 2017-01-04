h60915
s 00010/00005/00053
d D 3.15 88/06/29 21:38:35 bostic 15 14
c install approved copyright notice
e
s 00013/00007/00045
d D 3.14 88/02/21 13:38:45 bostic 14 13
c written by Edward Wang; attach Berkeley specific copyright
e
s 00004/00015/00048
d D 3.13 87/05/26 22:51:51 edward 13 12
c don't allocate ptys backwards anymore
e
s 00001/00001/00062
d D 3.12 86/08/05 01:24:48 edward 12 11
c lint
e
s 00006/00000/00057
d D 3.11 85/04/24 16:16:47 edward 11 10
c copyright messages
e
s 00001/00001/00056
d D 3.10 84/05/23 01:58:51 edward 10 9
c new sccs id
e
s 00004/00004/00053
d D 3.9 84/05/16 03:53:54 edward 9 8
c stupid bug
e
s 00012/00002/00045
d D 3.8 84/04/15 16:49:46 edward 8 7
c backward allocation
e
s 00001/00001/00046
d D 3.7 84/03/02 13:27:27 edward 7 6
c lint
e
s 00005/00000/00042
d D 3.6 84/01/16 15:26:19 edward 6 5
c new io scheme
e
s 00021/00015/00021
d D 3.5 83/12/08 18:21:23 edward 5 4
c Check if we can open the tty end too.
c because sometimes they are left with funny uid and modes.
e
s 00003/00007/00033
d D 3.4 83/12/01 13:43:55 edward 4 3
c pty hanging bug
e
s 00001/00000/00039
d D 3.3 83/08/26 16:26:36 edward 3 2
c error reporting
e
s 00000/00000/00039
d D 3.2 83/08/11 17:24:48 edward 2 1
i
c last few day's work
e
s 00039/00000/00000
d D 3.1 83/08/09 18:37:53 edward 1 0
c date and time created 83/08/09 18:37:53 by edward
e
u
U
t
T
I 1
D 14
#ifndef lint
D 10
static	char *sccsid = "%W% %E%";
E 10
I 10
static char sccsid[] = "%W% %G%";
E 10
#endif

E 14
I 11
/*
D 14
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 14
I 14
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 15
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 15
I 15
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
E 15
E 14
 */
I 14

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 14

E 11
#include "ww.h"

I 8
D 13
/*
 * To satisfy Chris, we allocate pty's backwards, and if
 * there are more than the ptyp's (i.e. the ptyq's)
 * on the machine, we don't use the p's.
 */
E 13
E 8
wwgetpty(w)
D 5
	register struct ww *w;
E 5
I 5
register struct ww *w;
E 5
{
D 13
	register char c;
D 5
	register char *line;
E 5
	register int i;
E 13
I 13
	register char c, *p;
E 13
D 5
#define PTY "/dev/ptyXX"
E 5
I 5
	int tty;
I 6
	int on = 1;
I 8
D 9
	int count = -1;
E 9
I 9
D 13
	char hasq = 0;
E 13
E 9
E 8
E 6
#define PTY "/dev/XtyXX"
#define _PT	5
#define _PQRS	8
#define _0_9	9
E 5

I 5
	(void) strcpy(w->ww_ttyname, PTY);
E 5
D 8
	for (c = 'p'; c <= 's'; c++) {
E 8
I 8
D 13
	for (c = 's'; c >= 'p'; c--) {
E 13
I 13
	for (c = 'p'; c <= 'u'; c++) {
E 13
E 8
D 5
		line = PTY;
		line[sizeof PTY - 6] = 'p';
		line[sizeof PTY - 3] = c;
		line[sizeof PTY - 2] = '0';
		if (access(line, 0) < 0)
E 5
I 5
		w->ww_ttyname[_PT] = 'p';
		w->ww_ttyname[_PQRS] = c;
		w->ww_ttyname[_0_9] = '0';
		if (access(w->ww_ttyname, 0) < 0)
I 8
D 13
			continue;
D 9
		if (count < 0 && (count = c - 'p' - 1) == 0)
			count = 1;
		if (--count < 0)
E 9
I 9
		if (c != 'p')
			hasq = 1;
		else if (hasq)
E 13
E 9
E 8
E 5
			break;
D 8
		for (i = 0; i < 16; i++) {
E 8
I 8
D 13
		for (i = 15; i >= 0; i--) {
E 13
I 13
		for (p = "0123456789abcdef"; *p; p++) {
E 13
E 8
D 5
			line[sizeof PTY - 6] = 'p';
			line[sizeof PTY - 2] = "0123456789abcdef"[i];
			w->ww_pty = open(line, 2);
			if (w->ww_pty >= 0) {
				line[sizeof PTY - 6] = 't';
D 4
				w->ww_tty = open(line, 2);
				if (w->ww_tty >= 0)
					goto good;
				(void) close(w->ww_pty);
E 4
I 4
				(void) strcpy(w->ww_ttyname, line);
				return 0;
E 5
I 5
			w->ww_ttyname[_PT] = 'p';
D 13
			w->ww_ttyname[_0_9] = "0123456789abcdef"[i];
E 13
I 13
			w->ww_ttyname[_0_9] = *p;
E 13
			if ((w->ww_pty = open(w->ww_ttyname, 2)) < 0)
				continue;
			w->ww_ttyname[_PT] = 't';
			if ((tty = open(w->ww_ttyname, 2)) < 0) {
				(void) close(w->ww_pty);
				continue;
E 5
E 4
			}
I 5
			(void) close(tty);
I 6
D 7
			if (ioctl(w->ww_pty, (int)TIOCPKT, &on) < 0) {
E 7
I 7
D 12
			if (ioctl(w->ww_pty, (int)TIOCPKT, (char *)&on) < 0) {
E 12
I 12
			if (ioctl(w->ww_pty, TIOCPKT, (char *)&on) < 0) {
E 12
E 7
				(void) close(w->ww_pty);
				continue;
			}
E 6
			return 0;
E 5
		}
	}
I 4
	w->ww_pty = -1;
E 4
I 3
	wwerrno = WWE_NOPTY;
E 3
	return -1;
D 4
good:
	(void) strcpy(w->ww_ttyname, line);
	return 0;
E 4
}
E 1
