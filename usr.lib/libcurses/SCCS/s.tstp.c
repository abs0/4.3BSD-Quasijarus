h33328
s 00010/00005/00046
d D 5.3 88/06/30 17:22:10 bostic 8 7
c install approved copyright notice
e
s 00010/00004/00041
d D 5.2 88/06/08 13:57:52 bostic 7 6
c written by Ken Arnold; add Berkeley specific header
e
s 00010/00000/00035
d D 5.1 85/06/07 08:17:23 dist 6 5
c Add copyright
e
s 00001/00001/00034
d D 1.4 85/05/01 17:37:29 bloom 5 4
c fix sccs id
e
s 00006/00000/00029
d D 1.3 83/06/25 22:34:26 sam 4 2
c fix for new signals
e
s 00006/00000/00029
d R 1.3 83/06/21 23:26:14 sam 3 2
c signal not reset on handler entrance
e
s 00003/00003/00026
d D 1.2 83/05/09 20:31:06 arnold 2 1
c stop complaint about "no symbols" on non-tstp machines
e
s 00029/00000/00000
d D 1.1 81/03/06 00:09:01 arnold 1 0
c date and time created 81/03/06 00:09:01 by arnold
e
u
U
t
T
I 6
/*
D 7
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * Copyright (c) 1981 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
E 7
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 7
#endif not lint
E 7
I 7
#endif /* not lint */
E 7

E 6
I 1
# include	<signal.h>

D 2
# ifdef SIGTSTP

E 2
# include	"curses.ext"

/*
 * handle stop and start signals
 *
D 5
 * %G% (Berkeley) %W%
E 5
I 5
 * %W% (Berkeley) %G%
E 5
 */
tstp() {

I 2
# ifdef SIGTSTP

E 2
	SGTTY	tty;
I 4
	int	omask;
E 4
# ifdef DEBUG
	if (outf)
		fflush(outf);
# endif
	tty = _tty;
	mvcur(0, COLS - 1, LINES - 1, 0);
	endwin();
	fflush(stdout);
I 4
	/* reset signal handler so kill below stops us */
	signal(SIGTSTP, SIG_DFL);
#define	mask(s)	(1 << ((s)-1))
	omask = sigsetmask(sigblock(0) &~ mask(SIGTSTP));
E 4
	kill(0, SIGTSTP);
I 4
	sigblock(mask(SIGTSTP));
E 4
	signal(SIGTSTP, tstp);
	_tty = tty;
	stty(_tty_ch, &_tty);
	wrefresh(curscr);
I 2
# endif	SIGTSTP
E 2
}
D 2
# endif
E 2
E 1
