h29916
s 00010/00005/00075
d D 5.4 88/06/18 15:08:07 bostic 6 5
c install approved copyright notice
e
s 00001/00001/00079
d D 5.3 88/06/12 12:12:13 bostic 5 4
c remove non-printable characters
e
s 00009/00003/00071
d D 5.2 88/05/05 18:34:31 bostic 4 3
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00067
d D 5.1 85/05/30 09:01:48 dist 3 2
c Add copyright
e
s 00003/00003/00065
d D 4.2 83/05/09 21:55:11 layer 2 1
c conversion of source code to 4.1c BSD
e
s 00068/00000/00000
d D 4.1 83/03/23 15:00:52 mckusick 1 0
c date and time created 83/03/23 15:00:52 by mckusick
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
**  RAM SOME OBJECT
**
**	You have run into some sort of object.  It may be a Klingon,
**	a star, or a starbase.  If you run into a star, you are really
**	stupid, because there is no hope for you.
**
**	If you run into something else, you destroy that object.  You
**	also rack up incredible damages.
*/

ram(ix, iy)
int	ix, iy;
{
	register int		i;
	register char		c;

D 5
	printf("RED ALERT: collision imminent\n");
E 5
I 5
	printf("\07RED ALERT\07: collision imminent\n");
E 5
	c = Sect[ix][iy];
	switch (c)
	{

	  case KLINGON:
		printf("%s rams Klingon at %d,%d\n", Ship.shipname, ix, iy);
		killk(ix, iy);
		break;

	  case STAR:
	  case INHABIT:
		printf("Yeoman Rand: Captain, isn't it getting hot in here?\n");
		sleep(2);
		printf("Spock: Hull temperature approaching 550 Degrees Kelvin.\n");
		lose(L_STAR);

	  case BASE:
		printf("You ran into the starbase at %d,%d\n", ix, iy);
		killb(Ship.quadx, Ship.quady);
		/* don't penalize the captain if it wasn't his fault */
		if (!damaged(SINS))
D 2
			Game.killb =+ 1;
E 2
I 2
			Game.killb += 1;
E 2
		break;
	}
	sleep(2);
	printf("%s heavily damaged\n", Ship.shipname);

	/* select the number of deaths to occur */
	i = 10 + ranf(20 * Game.skill);
D 2
	Game.deaths =+ i;
	Ship.crew =- i;
E 2
I 2
	Game.deaths += i;
	Ship.crew -= i;
E 2
	printf("McCoy: Take it easy Jim; we had %d casualties.\n", i);

	/* damage devices with an 80% probability */
	for (i = 0; i < NDEV; i++)
	{
		if (ranf(100) < 20)
			continue;
		damage(i, (2.5 * (franf() + franf()) + 1.0) * Param.damfac[i]);
	}

	/* no chance that your shields remained up in all that */
	Ship.shldup = 0;
}
E 1
