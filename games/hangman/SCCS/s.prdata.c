h35426
s 00011/00006/00031
d D 5.2 88/06/18 14:44:40 bostic 2 1
c install approved copyright notice
e
s 00037/00000/00000
d D 5.1 87/12/22 13:08:09 bostic 1 0
c date and time created 87/12/22 13:08:09 by bostic
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
 * prdata:
 *	Print out the current guesses
 */
prdata()
{
	register bool	*bp;

	move(GUESSY, GUESSX + sizeof "Guessed: ");
	bp = Guessed;
	while (bp < &Guessed[26])
		if (*bp++)
			addch((bp - Guessed) + 'a' - 1);
	clrtoeol();
	mvprintw(NUMBERY, NUMBERX + sizeof "Word #:          ", "%d", Wordnum);
	mvprintw(AVGY, AVGX + sizeof       "Current Average: ", "%.3f",
				(Average * (Wordnum - 1) + Errors) / Wordnum);
	mvprintw(AVGY + 1, AVGX + sizeof   "Overall Average: ", "%.3f", Average);
}
E 1
