h13298
s 00010/00005/00040
d D 3.9 88/06/29 21:37:25 bostic 16 15
c install approved copyright notice
e
s 00013/00007/00032
d D 3.8 88/02/21 13:38:02 bostic 15 14
c written by Edward Wang; attach Berkeley specific copyright
e
s 00005/00000/00034
d D 3.7 87/06/08 02:28:04 edward 14 13
c interrupt mechanism reworked, make SIGCHLD interrupt also
e
s 00001/00000/00033
d D 3.6 87/05/08 11:01:47 sam 13 12
c types.h needed on a vax
e
s 00006/00000/00027
d D 3.5 85/04/24 16:10:49 edward 12 11
c copyright messages
e
s 00001/00001/00026
d D 3.4 84/05/23 01:56:12 edward 11 10
c new sccs id
e
s 00004/00000/00023
d D 3.3 83/12/01 13:43:17 edward 10 9
c pty hanging bug
e
s 00000/00008/00023
d D 3.2 83/09/01 18:34:34 edward 9 8
c Got rid of 'curwin'.
c and now knows about dead processes.
e
s 00000/00000/00031
d D 3.1 83/08/11 17:20:55 edward 8 6
i 7
c last few day's work
e
s 00009/00008/00022
d D 2.1.1.1 83/08/09 18:33:38 edward 7 6
c mile stone
e
s 00000/00000/00030
d D 2.1 83/07/30 13:26:34 edward 6 5
c prepare for major change
e
s 00000/00000/00030
d D 1.5 83/07/22 17:06:52 edward 5 4
c scrolling.
c uses Wscreensize() to get screen size.
c More intelligent framing.
c etc.
e
s 00000/00000/00030
d D 1.4 83/07/19 20:07:25 edward 4 3
c today's work
e
s 00005/00001/00025
d D 1.3 83/07/18 21:02:03 edward 3 2
c multiple window
e
s 00005/00014/00021
d D 1.2 83/07/17 15:41:57 edward 2 1
c 
e
s 00035/00000/00000
d D 1.1 83/07/12 17:20:39 edward 1 0
c date and time created 83/07/12 17:20:39 by edward
e
u
U
f b 
t
T
I 1
D 15
#ifndef lint
D 11
static	char *sccsid = "%W% %E%";
E 11
I 11
static char sccsid[] = "%W% %G%";
E 11
#endif

E 15
I 12
/*
D 15
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 15
I 15
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 16
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 16
I 16
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
E 16
E 15
 */
I 15

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 15

E 12
#include "ww.h"
I 13
#include <sys/types.h>
E 13
#include <sys/wait.h>

wwchild()
{
I 10
	extern errno;
	int olderrno;
E 10
D 7
	register struct ww *wp;
E 7
I 7
	register struct ww **wp;
E 7
	union wait w;
	int pid;
I 14
	char collected = 0;
E 14
D 2
	/*
	char buf[100];
	*/
E 2

I 10
	olderrno = errno;
E 10
D 7
	while ((pid = wait3(&w, WNOHANG|WUNTRACED, 0)) > 0) {
D 2
		for (wp = _wwhead; wp; wp = wp->ww_next) {
E 2
I 2
		for (wp = wwhead; wp; wp = wp->ww_next) {
E 2
			if (wp->ww_pid == pid) {
				wp->ww_state = WW_DEAD;
E 7
I 7
	while ((pid = wait3(&w, WNOHANG|WUNTRACED, (struct rusage *)0)) > 0) {
		for (wp = wwindex; wp < &wwindex[NWW]; wp++) {
			if (*wp && (*wp)->ww_state == WWS_HASPROC
			    && (*wp)->ww_pid == pid) {
				(*wp)->ww_state = WWS_DEAD;
I 14
				collected = 1;
E 14
E 7
D 2
				/*
				(void) sprintf(buf, "\r\n%d: Died\r\n", pid);
				wwputstr(buf);
				*/
E 2
I 2
D 3
				(void) wwprintf(curwin,
E 3
I 3
D 9
				/*
D 7
				wwprintf(curwin,
E 7
I 7
				(void) wwprintf(curwin,
E 7
E 3
					"\r\n%d: Died\r\n", pid);
I 3
				*/
E 9
E 3
E 2
				break;
			}
		}
I 3
D 9
		/*
E 3
D 2
		/*
		if (wp == 0) {
			(void) sprintf(buf, "\r\n%d: No such child\r\n", pid);
			wwputstr(buf);
		}
		*/
E 2
I 2
D 7
		if (wp == 0)
			wwprintf(curwin, "\r\n%d: No such child\r\n", pid);
E 7
I 7
		if (wp >= &wwindex[NWW])
			(void) wwprintf(curwin, "\r\n%d: No such child\r\n", pid);
E 7
I 3
		*/
E 9
E 3
E 2
	}
I 10
	errno = olderrno;
I 14
	/* jump out of wwiomux when somebody dies */
	if (collected)
		wwsetintr();
E 14
E 10
}
E 1
