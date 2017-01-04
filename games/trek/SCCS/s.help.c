h59195
s 00010/00005/00131
d D 5.3 88/06/18 15:07:43 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00127
d D 5.2 88/05/05 18:33:59 bostic 4 3
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00123
d D 5.1 85/05/30 08:54:21 dist 3 2
c Add copyright
e
s 00002/00002/00122
d D 4.2 83/05/09 21:54:39 layer 2 1
c conversion of source code to 4.1c BSD
e
s 00124/00000/00000
d D 4.1 83/03/23 14:59:42 mckusick 1 0
c date and time created 83/03/23 14:59:42 by mckusick
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
**  call starbase for help
**
**	First, the closest starbase is selected.  If there is a
**	a starbase in your own quadrant, you are in good shape.
**	This distance takes quadrant distances into account only.
**
**	A magic number is computed based on the distance which acts
**	as the probability that you will be rematerialized.  You
**	get three tries.
**
**	When it is determined that you should be able to be remater-
**	ialized (i.e., when the probability thing mentioned above
**	comes up positive), you are put into that quadrant (anywhere).
**	Then, we try to see if there is a spot adjacent to the star-
**	base.  If not, you can't be rematerialized!!!  Otherwise,
**	it drops you there.  It only tries five times to find a spot
**	to drop you.  After that, it's your problem.
*/

D 2
char	*Cntvect[3]
E 2
I 2
char	*Cntvect[3] =
E 2
{"first", "second", "third"};

help()
{
	register int		i;
	double			dist, x;
	register int		dx, dy;
	int			j, l;

	/* check to see if calling for help is reasonable ... */
	if (Ship.cond == DOCKED)
		return (printf("Uhura: But Captain, we're already docked\n"));

	/* or possible */
	if (damaged(SSRADIO))
		return (out(SSRADIO));
	if (Now.bases <= 0)
		return (printf("Uhura: I'm not getting any response from starbase\n"));

	/* tut tut, there goes the score */
D 2
	Game.helps =+ 1;
E 2
I 2
	Game.helps += 1;
E 2

	/* find the closest base */
	dist = 1e50;
	if (Quad[Ship.quadx][Ship.quady].bases <= 0)
	{
		/* there isn't one in this quadrant */
		for (i = 0; i < Now.bases; i++)
		{
			/* compute distance */
			dx = Now.base[i].x - Ship.quadx;
			dy = Now.base[i].y - Ship.quady;
			x = dx * dx + dy * dy;
			x = sqrt(x);

			/* see if better than what we already have */
			if (x < dist)
			{
				dist = x;
				l = i;
			}
		}

		/* go to that quadrant */
		Ship.quadx = Now.base[l].x;
		Ship.quady = Now.base[l].y;
		initquad(1);
	}
	else
	{
		dist = 0.0;
	}

	/* dematerialize the Enterprise */
	Sect[Ship.sectx][Ship.secty] = EMPTY;
	printf("Starbase in %d,%d responds\n", Ship.quadx, Ship.quady);

	/* this next thing acts as a probability that it will work */
	x = pow(1.0 - pow(0.94, dist), 0.3333333);

	/* attempt to rematerialize */
	for (i = 0; i < 3; i++)
	{
		sleep(2);
		printf("%s attempt to rematerialize ", Cntvect[i]);
		if (franf() > x)
		{
			/* ok, that's good.  let's see if we can set her down */
			for (j = 0; j < 5; j++)
			{
				dx = Etc.starbase.x + ranf(3) - 1;
				if (dx < 0 || dx >= NSECTS)
					continue;
				dy = Etc.starbase.y + ranf(3) - 1;
				if (dy < 0 || dy >= NSECTS || Sect[dx][dy] != EMPTY)
					continue;
				break;
			}
			if (j < 5)
			{
				/* found an empty spot */
				printf("succeeds\n");
				Ship.sectx = dx;
				Ship.secty = dy;
				Sect[dx][dy] = Ship.ship;
				dock();
				compkldist(0);
				return;
			}
			/* the starbase must have been surrounded */
		}
		printf("fails\n");
	}

	/* one, two, three strikes, you're out */
	lose(L_NOHELP);
}
E 1
