h54173
s 00010/00005/00115
d D 5.3 88/06/18 15:07:59 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00111
d D 5.2 88/05/05 18:34:21 bostic 4 3
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00107
d D 5.1 85/05/30 09:00:38 dist 3 2
c Add copyright
e
s 00007/00007/00101
d D 4.2 83/05/09 21:55:06 layer 2 1
c conversion of source code to 4.1c BSD
e
s 00108/00000/00000
d D 4.1 83/03/23 15:00:31 mckusick 1 0
c date and time created 83/03/23 15:00:31 by mckusick
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
D 5
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 5
I 5
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
E 5
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
**  CAUSE A NOVA TO OCCUR
**
**	A nova occurs.  It is the result of having a star hit with
**	a photon torpedo.  There are several things which may happen.
**	The star may not be affected.  It may go nova.  It may turn
**	into a black hole.  Any (yummy) it may go supernova.
**
**	Stars that go nova cause stars which surround them to undergo
**	the same probabilistic process.  Klingons next to them are
**	destroyed.  And if the starship is next to it, it gets zapped.
**	If the zap is too much, it gets destroyed.
*/

nova(x, y)
int	x, y;
{
	register int		i, j;
	register int		se;

	if (Sect[x][y] != STAR || Quad[Ship.quadx][Ship.quady].stars < 0)
		return;
	if (ranf(100) < 15)
	{
		printf("Spock: Star at %d,%d failed to nova.\n", x, y);
		return;
	}
	if (ranf(100) < 5)
		return (snova(x, y));
	printf("Spock: Star at %d,%d gone nova\n", x, y);

	if (ranf(4) != 0)
		Sect[x][y] = EMPTY;
	else
	{
		Sect[x][y] = HOLE;
D 2
		Quad[Ship.quadx][Ship.quady].holes =+ 1;
E 2
I 2
		Quad[Ship.quadx][Ship.quady].holes += 1;
E 2
	}
D 2
	Quad[Ship.quadx][Ship.quady].stars =- 1;
	Game.kills =+ 1;
E 2
I 2
	Quad[Ship.quadx][Ship.quady].stars -= 1;
	Game.kills += 1;
E 2
	for (i = x - 1; i <= x + 1; i++)
	{
		if (i < 0 || i >= NSECTS)
			continue;
		for (j = y - 1; j <= y + 1; j++)
		{
			if (j < 0 || j >= NSECTS)
				continue;
			se = Sect[i][j];
			switch (se)
			{

			  case EMPTY:
			  case HOLE:
				break;

			  case KLINGON:
				killk(i, j);
				break;

			  case STAR:
				nova(i, j);
				break;

			  case INHABIT:
				kills(i, j, -1);
				break;

			  case BASE:
				killb(i, j);
D 2
				Game.killb =+ 1;
E 2
I 2
				Game.killb += 1;
E 2
				break;

			  case ENTERPRISE:
			  case QUEENE:
				se = 2000;
				if (Ship.shldup)
					if (Ship.shield >= se)
					{
D 2
						Ship.shield =- se;
E 2
I 2
						Ship.shield -= se;
E 2
						se = 0;
					}
					else
					{
D 2
						se =- Ship.shield;
E 2
I 2
						se -= Ship.shield;
E 2
						Ship.shield = 0;
					}
D 2
				Ship.energy =- se;
E 2
I 2
				Ship.energy -= se;
E 2
				if (Ship.energy <= 0)
					lose(L_SUICID);
				break;

			  default:
				printf("Unknown object %c at %d,%d destroyed\n",
					se, i, j);
				Sect[i][j] = EMPTY;
				break;
			}
		}
	}
	return;
}
E 1
