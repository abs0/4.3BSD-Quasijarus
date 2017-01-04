h29098
s 00010/00005/00050
d D 3.13 88/06/29 21:36:13 bostic 13 12
c install approved copyright notice
e
s 00002/00001/00053
d D 3.12 88/04/29 16:23:15 edward 12 11
c fixed startup hanging bug (calling wwrint without masking SIGIO)
e
s 00014/00015/00040
d D 3.11 88/04/25 22:07:26 edward 11 10
c fixed type-ahead after getting out of command mode bug
e
s 00013/00007/00042
d D 3.10 88/02/21 13:37:10 bostic 10 9
c written by Edward Wang; attach Berkeley specific copyright
e
s 00002/00000/00047
d D 3.9 87/05/18 12:20:34 edward 9 8
c added keepopen and smooth flags, added + and - window selections
e
s 00006/00000/00041
d D 3.8 85/04/24 16:18:28 edward 8 7
c copyright messages
e
s 00004/00002/00037
d D 3.7 85/03/13 20:01:25 edward 7 6
c handle ^S and ^Q (the commands) better
e
s 00001/00000/00038
d D 3.6 84/11/20 23:40:22 edward 6 5
c we don't flush typeahead any more
e
s 00001/00001/00037
d D 3.5 84/05/23 01:59:34 edward 5 4
c new sccs id
e
s 00003/00003/00035
d D 3.4 84/04/05 00:32:09 edward 4 3
c -c flag, incmd, setcmd(), setterse() added
e
s 00023/00035/00015
d D 3.3 84/03/03 22:47:37 edward 3 2
c interrupt driven input
e
s 00010/00030/00040
d D 3.2 84/01/16 15:26:24 edward 2 1
c new io scheme
e
s 00070/00000/00000
d D 3.1 83/09/02 12:57:42 edward 1 0
c date and time created 83/09/02 12:57:42 by edward
e
u
U
t
T
I 1
D 10
#ifndef lint
D 5
static	char *sccsid = "%W% %E%";
E 5
I 5
static char sccsid[] = "%W% %G%";
E 5
#endif

E 10
I 8
/*
D 10
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 10
I 10
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 13
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 13
I 13
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
E 13
E 10
 */
I 10

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 10

E 8
#include "defs.h"
I 12
#include <sys/signal.h>
E 12

mloop()
{
I 6
D 12
	wwrint();		/* catch typeahead before we set ASYNC */
E 12
I 12
	kill(getpid(), SIGIO);	/* catch typeahead before ASYNC was set */
E 12
E 6
D 3
	register n;
	register char *p;
	int imask;

E 3
	while (!quit) {
D 3
		if (!incmd && selwin->ww_state != WWS_HASPROC) {
			incmd = 1;
			error("Process died.");
		}
		if (incmd) {
E 3
I 3
D 4
		if (wwcurwin == 0) {
E 4
I 4
		if (incmd) {
E 4
E 3
			docmd();
D 3
			continue;
		}
D 2
		/*
		 * Loop until we get some keyboard input.
		 */
		while (ibufc == 0) {
E 2
I 2
		while (wwibc == 0) {
E 2
			wwcurtowin(selwin);
E 3
I 3
		} else if (wwcurwin->ww_state != WWS_HASPROC) {
I 9
			if (!wwcurwin->ww_keepopen)
				closewin(wwcurwin);
E 9
D 4
			wwcurwin = 0;
E 4
I 4
			setcmd(1);
E 4
			if (wwpeekc() == escapec)
				(void) wwgetc();
			error("Process died.");
		} else {
I 7
			register struct ww *w = wwcurwin;
E 7
			register char *p;
			register n;

E 3
D 2
			wwupdate();
			wwflush();
			while (imask = 1, wwforce(&imask) < 0)
				;
			if ((imask & 1) == 0)
				continue;
			/* NOTE: ibufc == 0 */
			ibufp = ibuf;
			/* may block */
			if ((ibufc = read(0, ibuf, sizeof ibuf)) < 0) {
				ibufc = 0;
				nreade++;
			} else if (ibufc == 0)
				nreadz++;
			else
				nreadc += ibufc;
			nread++;
E 2
I 2
D 11
			wwiomux();
E 2
D 3
		}
		/*
		 * Weird loop.  Copy the buffer to the pty
		 * and stopping on the escape character
		 * in a hopefully efficient way.
D 2
		 * Probably a good thing to make ibufc == 1 a special
E 2
I 2
		 * Probably a good thing to make wwibc == 1 a special
E 2
		 * case.
		 */
D 2
		for (p = ibufp, n = ibufc;;) {
E 2
I 2
		for (p = wwibp, n = wwibc;;) {
E 2
			if (--n < 0) {
D 2
				(void) write(selwin->ww_pty, ibufp, ibufc);
				ibufp = ibuf;
				ibufc = 0;
E 2
I 2
				(void) write(selwin->ww_pty, wwibp, wwibc);
				wwibc = 0;
E 2
				break;
			}
			if (*p++ == escapec) {
D 2
				if ((n = p - ibufp) > 1)
E 2
I 2
				if ((n = p - wwibp) > 1)
E 2
					(void) write(selwin->ww_pty,
D 2
						ibufp, n - 1);
				ibufp = p;
				ibufc -= n;
E 2
I 2
						wwibp, n - 1);
				wwibp = p;
				wwibc -= n;
E 2
				incmd = 1;
				break;
E 3
I 3
			if (wwibp < wwibq) {
				for (p = wwibp; p < wwibq && *p != escapec;
				     p++)
					;
				if ((n = p - wwibp) > 0) {
D 7
					(void) write(wwcurwin->ww_pty,
						wwibp, n);
E 7
I 7
					if (!w->ww_ispty && w->ww_stopped)
						startwin(w);
					(void) write(w->ww_pty, wwibp, n);
E 7
					wwibp = p;
				}
				if (wwpeekc() == escapec) {
D 4
					wwcurwin = 0;
E 4
					(void) wwgetc();
I 4
					setcmd(1);
E 4
				}
E 11
I 11
			if (wwibp >= wwibq)
				wwiomux();
			for (p = wwibp; p < wwibq && *p != escapec;
			     p++)
				;
			if ((n = p - wwibp) > 0) {
				if (!w->ww_ispty && w->ww_stopped)
					startwin(w);
				(void) write(w->ww_pty, wwibp, n);
				wwibp = p;
			}
			if (wwpeekc() == escapec) {
				(void) wwgetc();
				setcmd(1);
E 11
E 3
			}
		}
	}
}
E 1
