h48540
s 00010/00005/00071
d D 5.3 88/06/30 17:21:42 bostic 10 9
c install approved copyright notice
e
s 00010/00004/00066
d D 5.2 88/06/08 13:57:17 bostic 9 8
c written by Ken Arnold; add Berkeley specific header
e
s 00010/00001/00060
d D 5.1 85/06/07 11:34:20 dist 8 7
c Add copyright
e
s 00003/00008/00058
d D 1.6 85/05/23 15:42:40 bloom 7 6
c only look at stdin, stdout and stderr
e
s 00003/00002/00063
d D 1.5 85/05/01 18:39:52 bloom 6 5
c use getdtablesize() instead of defined NOFILE
e
s 00003/00002/00062
d D 1.4 85/05/01 17:18:07 bloom 5 3
c new version from arnold
e
s 00003/00002/00062
d R 1.4 85/05/01 17:15:55 bloom 4 3
c fix sccs id
e
s 00011/00004/00053
d D 1.3 83/05/19 12:10:43 arnold 3 2
c check more than one channel for tty
e
s 00006/00001/00051
d D 1.2 81/03/06 00:15:52 arnold 2 1
c add handling of ^Z (tstp) signal
e
s 00052/00000/00000
d D 1.1 81/01/26 17:02:56 arnold 1 0
c date and time created 81/01/26 17:02:56 by arnold
e
u
U
t
T
I 8
/*
D 9
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 9
I 9
 * Copyright (c) 1981 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 10
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
I 10
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
E 10
E 9
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 9
#endif not lint
E 9
I 9
#endif /* not lint */
E 9

E 8
I 1
# include	"curses.ext"
I 2
# include	<signal.h>
I 3
D 6
# include	<sys/param.h>
E 6
E 3
E 2

extern char	*getenv();

/*
 *	This routine initializes the current and standard screen.
 *
D 5
 * %G% (Berkeley) %W%
E 5
I 5
D 8
 * %W% (Berkeley) %G%
E 8
E 5
 */
WINDOW *
initscr() {

	reg char	*sp;
I 2
	int		tstp();
I 6
	int 		nfd;
E 6
E 2

# ifdef DEBUG
	fprintf(outf, "INITSCR()\n");
# endif
D 3
	if (!My_term && isatty(2)) {
		_tty_ch = 2;
E 3
I 3
	if (My_term)
		setterm(Def_term);
	else {
D 7
		if (isatty(2))
			_tty_ch = 2;
		else {
D 6
			for (_tty_ch = 0; _tty_ch < NOFILE; _tty_ch++)
E 6
I 6
			nfd = getdtablesize();
			for (_tty_ch = 0; _tty_ch < nfd; _tty_ch++)
E 6
				if (isatty(_tty_ch))
					break;
		}
E 7
I 7
		for (_tty_ch = 0; _tty_ch < nfd; _tty_ch++)
			if (isatty(_tty_ch))
				break;
E 7
E 3
		gettmode();
		if ((sp = getenv("TERM")) == NULL)
			sp = Def_term;
		setterm(sp);
# ifdef DEBUG
		fprintf(outf, "INITSCR: term = %s\n", sp);
# endif
	}
D 3
	else
		setterm(Def_term);
E 3
	_puts(TI);
	_puts(VS);
I 2
# ifdef SIGTSTP
	signal(SIGTSTP, tstp);
# endif
E 2
	if (curscr != NULL) {
# ifdef DEBUG
		fprintf(outf, "INITSCR: curscr = 0%o\n", curscr);
# endif
		delwin(curscr);
	}
# ifdef DEBUG
	fprintf(outf, "LINES = %d, COLS = %d\n", LINES, COLS);
# endif
D 2
	if ((curscr=newwin(LINES, COLS, 0, 0)) == ERR)
E 2
I 2
	if ((curscr = newwin(LINES, COLS, 0, 0)) == ERR)
E 2
		return ERR;
D 5
	curscr->_clear = TRUE;
E 5
I 5
	clearok(curscr, TRUE);
	curscr->_flags &= ~_FULLLINE;
E 5
	if (stdscr != NULL) {
# ifdef DEBUG
		fprintf(outf, "INITSCR: stdscr = 0%o\n", stdscr);
# endif
		delwin(stdscr);
	}
	stdscr = newwin(LINES, COLS, 0, 0);
	return stdscr;
}
E 1
