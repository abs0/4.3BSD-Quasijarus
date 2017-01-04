h55217
s 00010/00005/00056
d D 5.4 88/06/18 15:07:51 bostic 6 5
c install approved copyright notice
e
s 00001/00001/00060
d D 5.3 88/06/12 12:11:25 bostic 5 4
c remove non-printable characters
e
s 00009/00003/00052
d D 5.2 88/05/05 18:34:11 bostic 4 3
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00048
d D 5.1 86/01/29 16:36:24 mckusick 3 2
c add copyright
e
s 00001/00001/00048
d D 4.2 83/05/27 00:34:16 layer 2 1
c finished conversion to 4.1c
e
s 00049/00000/00000
d D 4.1 83/03/23 15:00:11 mckusick 1 0
c date and time created 83/03/23 15:00:11 by mckusick
e
u
U
t
T
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
D 4
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
I 4
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 6
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 6
I 6
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
E 6
E 4
 */

E 3
I 1
#ifndef lint
D 3
static char sccsid[] = "%W%	(Berkeley)	%G%";
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
E 3
D 4
#endif not lint
E 4
I 4
#endif /* not lint */
E 4

# include	"trek.h"

/*
**  PRINT OUT LOSER MESSAGES
**
**	The messages are printed out, the score is computed and
**	printed, and the game is restarted.  Oh yeh, any special
**	actions which need be taken are taken.
*/

D 2
char	*Losemsg[]
E 2
I 2
char	*Losemsg[] =
E 2
{
	"You ran out of time",
	"You ran out of energy",
	"You have been destroyed",
	"You ran into the negative energy barrier",
	"You destroyed yourself by nova'ing that star",
	"You have been caught in a supernova",
	"You just suffocated in outer space",
	"You could not be rematerialized",
D 5
	"\n\032\014 *** Ship's hull has imploded ***",
E 5
I 5
	"\n\032\014 ***\07 Ship's hull has imploded\07 ***",
E 5
	"You have burned up in a star",
	"Well, you destroyed yourself, but it didn't do any good",
	"You have been captured by Klingons and mercilessly tortured",
	"Your last crew member died",
};

lose(why)
int	why;
{
	Game.killed = 1;
	sleep(1);
	printf("\n%s\n", Losemsg[why - 1]);
	switch (why)
	{

	  case L_NOTIME:
		Game.killed = 0;
		break;
	}
	Move.endgame = -1;
	score();
	skiptonl(0);
	reset();
}
E 1
