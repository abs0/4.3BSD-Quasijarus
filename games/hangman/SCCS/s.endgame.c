h42618
s 00011/00006/00046
d D 5.2 88/06/18 14:44:32 bostic 2 1
c install approved copyright notice
e
s 00052/00000/00000
d D 5.1 87/12/22 13:08:05 bostic 1 0
c date and time created 87/12/22 13:08:05 by bostic
e
u
U
t
T
I 1
/*
D 2
 * Copyright (c) 1987 Regents of the University of California.
E 2
I 2
 * Copyright (c) 1983 Regents of the University of California.
E 2
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 2
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 2
I 2
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
E 2
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

# include	"hangman.h"

/*
 * endgame:
 *	Do what's necessary at the end of the game
 */
endgame()
{
	register char	ch;

	prman();
	if (Errors >= MAXERRS)
		Errors = MAXERRS + 2;
	prword();
	prdata();
	move(MESGY, MESGX);
	if (Errors > MAXERRS)
		printw("Sorry, the word was \"%s\"\n", Word);
	else
		printw("You got it!\n");

	for (;;) {
		mvaddstr(MESGY + 1, MESGX, "Another word? ");
		leaveok(stdscr, FALSE);
		refresh();
		if ((ch = readch()) == 'n')
			die();
		else if (ch == 'y')
			break;
		mvaddstr(MESGY + 2, MESGX, "Please type 'y' or 'n'");
	}

	leaveok(stdscr, TRUE);
	move(MESGY, MESGX);
	addstr("\n\n\n");
}
E 1
