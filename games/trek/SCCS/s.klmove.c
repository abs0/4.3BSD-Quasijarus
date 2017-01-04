h05884
s 00010/00005/00156
d D 5.3 88/06/18 15:07:50 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00152
d D 5.2 88/05/05 18:34:09 bostic 4 3
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00148
d D 5.1 86/01/29 16:36:17 mckusick 3 2
c add copyright
e
s 00010/00010/00139
d D 4.2 83/05/27 00:34:11 layer 2 1
c finished conversion to 4.1c
e
s 00149/00000/00000
d D 4.1 83/03/23 15:00:05 mckusick 1 0
c date and time created 83/03/23 15:00:05 by mckusick
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
**  Move Klingons Around
**
**	This is a largely incomprehensible block of code that moves
**	Klingons around in a quadrant.  It was written in a very
**	"program as you go" fashion, and is a prime candidate for
**	rewriting.
**
**	The flag `fl' is zero before an attack, one after an attack,
**	and two if you are leaving a quadrant.  This serves to
**	change the probability and distance that it moves.
**
**	Basically, what it will try to do is to move a certain number
**	of steps either toward you or away from you.  It will avoid
**	stars whenever possible.  Nextx and nexty are the next
**	sector to move to on a per-Klingon basis; they are roughly
**	equivalent to Ship.sectx and Ship.secty for the starship.  Lookx and
**	looky are the sector that you are going to look at to see
**	if you can move their.  Dx and dy are the increment.  Fudgex
**	and fudgey are the things you change around to change your
**	course around stars.
*/

klmove(fl)
int	fl;
{
	int			n;
	register struct kling	*k;
	double			dx, dy;
	int			nextx, nexty;
	register int		lookx, looky;
	int			motion;
	int			fudgex, fudgey;
	int			qx, qy;
	double			bigger;
	int			i;

#	ifdef xTRACE
	if (Trace)
		printf("klmove: fl = %d, Etc.nkling = %d\n", fl, Etc.nkling);
#	endif
	for (n = 0; n < Etc.nkling; k && n++)
	{
		k = &Etc.klingon[n];
		i = 100;
		if (fl)
			i = 100.0 * k->power / Param.klingpwr;
		if (ranf(i) >= Param.moveprob[2 * Move.newquad + fl])
			continue;
		/* compute distance to move */
		motion = ranf(75) - 25;
D 2
		motion =* k->avgdist * Param.movefac[2 * Move.newquad + fl];
E 2
I 2
		motion *= k->avgdist * Param.movefac[2 * Move.newquad + fl];
E 2
		/* compute direction */
		dx = Ship.sectx - k->x + ranf(3) - 1;
		dy = Ship.secty - k->y + ranf(3) - 1;
		bigger = dx;
		if (dy > bigger)
			bigger = dy;
		if (bigger == 0.0)
			bigger = 1.0;
		dx = dx / bigger + 0.5;
		dy = dy / bigger + 0.5;
		if (motion < 0)
		{
			motion = -motion;
			dx = -dx;
			dy = -dy;
		}
		fudgex = fudgey = 1;
		/* try to move the klingon */
		nextx = k->x;
		nexty = k->y;
		for (; motion > 0; motion--)
		{
			lookx = nextx + dx;
			looky = nexty + dy;
			if (lookx < 0 || lookx >= NSECTS || looky < 0 || looky >= NSECTS)
			{
				/* new quadrant */
				qx = Ship.quadx;
				qy = Ship.quady;
				if (lookx < 0)
D 2
					qx =- 1;
E 2
I 2
					qx -= 1;
E 2
				else
					if (lookx >= NSECTS)
D 2
						qx =+ 1;
E 2
I 2
						qx += 1;
E 2
				if (looky < 0)
D 2
					qy =- 1;
E 2
I 2
					qy -= 1;
E 2
				else
					if (looky >= NSECTS)
D 2
						qy =+ 1;
E 2
I 2
						qy += 1;
E 2
				if (qx < 0 || qx >= NQUADS || qy < 0 || qy >= NQUADS ||
						Quad[qx][qy].stars < 0 || Quad[qx][qy].klings > MAXKLQUAD - 1)
					break;
				if (!damaged(SRSCAN))
				{
					printf("Klingon at %d,%d escapes to quadrant %d,%d\n",
						k->x, k->y, qx, qy);
					motion = Quad[qx][qy].scanned;
					if (motion >= 0 && motion < 1000)
D 2
						Quad[qx][qy].scanned =+ 100;
E 2
I 2
						Quad[qx][qy].scanned += 100;
E 2
					motion = Quad[Ship.quadx][Ship.quady].scanned;
					if (motion >= 0 && motion < 1000)
D 2
						Quad[Ship.quadx][Ship.quady].scanned =- 100;
E 2
I 2
						Quad[Ship.quadx][Ship.quady].scanned -= 100;
E 2
				}
				Sect[k->x][k->y] = EMPTY;
D 2
				Quad[qx][qy].klings =+ 1;
				Etc.nkling =- 1;
E 2
I 2
				Quad[qx][qy].klings += 1;
				Etc.nkling -= 1;
E 2
				bmove(&Etc.klingon[Etc.nkling], k, sizeof *k);
D 2
				Quad[Ship.quadx][Ship.quady].klings =- 1;
E 2
I 2
				Quad[Ship.quadx][Ship.quady].klings -= 1;
E 2
				k = 0;
				break;
			}
			if (Sect[lookx][looky] != EMPTY)
			{
				lookx = nextx + fudgex;
				if (lookx < 0 || lookx >= NSECTS)
					lookx = nextx + dx;
				if (Sect[lookx][looky] != EMPTY)
				{
					fudgex = -fudgex;
					looky = nexty + fudgey;
					if (looky < 0 || looky >= NSECTS || Sect[lookx][looky] != EMPTY)
					{
						fudgey = -fudgey;
						break;
					}
				}
			}
			nextx = lookx;
			nexty = looky;
		}
		if (k && (k->x != nextx || k->y != nexty))
		{
			if (!damaged(SRSCAN))
				printf("Klingon at %d,%d moves to %d,%d\n",
					k->x, k->y, nextx, nexty);
			Sect[k->x][k->y] = EMPTY;
			Sect[k->x = nextx][k->y = nexty] = KLINGON;
		}
	}
	compkldist(0);
}
E 1
