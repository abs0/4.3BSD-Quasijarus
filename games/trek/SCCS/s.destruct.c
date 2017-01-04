h01964
s 00010/00005/00084
d D 5.4 88/06/18 15:07:24 bostic 7 6
c install approved copyright notice
e
s 00001/00001/00088
d D 5.3 88/06/12 12:09:51 bostic 6 5
c remove non-printable characters
e
s 00009/00003/00080
d D 5.2 88/05/05 18:33:34 bostic 5 4
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00076
d D 5.1 85/05/30 08:51:41 dist 4 3
c Add copyright
e
s 00001/00001/00076
d D 4.3 83/05/27 00:33:34 layer 3 2
c finished conversion to 4.1c
e
s 00002/00002/00075
d D 4.2 83/05/09 21:54:18 layer 2 1
c conversion of source code to 4.1c BSD
e
s 00077/00000/00000
d D 4.1 83/03/23 14:58:53 mckusick 1 0
c date and time created 83/03/23 14:58:53 by mckusick
e
u
U
t
T
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
D 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
E 5
 */

E 4
I 1
#ifndef lint
D 4
static char sccsid[] = "%W%	(Berkeley)	%G%";
E 4
I 4
static char sccsid[] = "%W% (Berkeley) %G%";
E 4
D 5
#endif not lint
E 5
I 5
#endif /* not lint */
E 5

# include	"trek.h"

/*
**  Self Destruct Sequence
**
**	The computer starts up the self destruct sequence.  Obviously,
**	if the computer is out nothing can happen.  You get a countdown
**	and a request for password.  This must match the password that
**	you entered at the start of the game.
**
**	You get to destroy things when you blow up; hence, it is
**	possible to win the game by destructing if you take the last
**	Klingon with you.
**
**	By the way, the \032 in the message is a ^Z, which is because
**	the terminal in my office is an ADM-3, which uses that char-
**	acter to clear the screen.  I also stick in a \014 (form feed)
**	because that clears some other screens.
**
**	Uses trace flag 41
*/

destruct()
{
	char		checkpass[15];
	register int	i, j;
D 3
	float		zap;
E 3
I 3
	double		zap;
E 3

	if (damaged(COMPUTER))
		return (out(COMPUTER));
D 6
	printf("\n --- WORKING ---\n");
E 6
I 6
	printf("\n\07 --- WORKING ---\07\n");
E 6
	sleep(3);
	/* output the count 10 9 8 7 6 */
	for (i = 10; i > 5; i--)
	{
		for (j = 10;  j > i; j--)
			printf("   ");
		printf("%d\n", i);
		sleep(1);
	}
	/* check for password on new line only */
	skiptonl(0);
	getstrpar("Enter password verification", checkpass, 14, 0);
	sleep(2);
	if (!sequal(checkpass, Game.passwd))
		return (printf("Self destruct sequence aborted\n"));
	printf("Password verified; self destruct sequence continues:\n");
	sleep(2);
	/* output count 5 4 3 2 1 0 */
	for (i = 5; i >= 0; i--)
	{
		sleep(1);
		for (j = 5; j > i; j--)
			printf("   ");
		printf("%d\n", i);
	}
	sleep(2);
	printf("\032\014***** %s destroyed *****\n", Ship.shipname);
	Game.killed = 1;
	/* let's see what we can blow up!!!! */
	zap = 20.0 * Ship.energy;
D 2
	Game.deaths =+ Ship.crew;
E 2
I 2
	Game.deaths += Ship.crew;
E 2
	for (i = 0; i < Etc.nkling; )
	{
		if (Etc.klingon[i].power * Etc.klingon[i].dist <= zap)
			killk(Etc.klingon[i].x, Etc.klingon[i].y);
		else
D 2
			i =+ 1;
E 2
I 2
			i++;
E 2
	}
	/* if we didn't kill the last Klingon (detected by killk), */
	/* then we lose.... */
	lose(L_DSTRCT);
}
E 1
