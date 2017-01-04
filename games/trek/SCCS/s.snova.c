h34698
s 00010/00005/00132
d D 5.3 88/06/18 15:08:23 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00128
d D 5.2 88/05/05 18:34:48 bostic 4 3
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00124
d D 5.1 85/05/30 09:04:40 dist 3 2
c Add copyright
e
s 00004/00004/00121
d D 4.2 83/05/09 21:55:18 layer 2 1
c conversion of source code to 4.1c BSD
e
s 00125/00000/00000
d D 4.1 83/03/23 15:01:38 mckusick 1 0
c date and time created 83/03/23 15:01:38 by mckusick
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
**  CAUSE SUPERNOVA TO OCCUR
**
**	A supernova occurs.  If 'ix' < 0, a random quadrant is chosen;
**	otherwise, the current quadrant is taken, and (ix, iy) give
**	the sector quadrants of the star which is blowing up.
**
**	If the supernova turns out to be in the quadrant you are in,
**	you go into "emergency override mode", which tries to get you
**	out of the quadrant as fast as possible.  However, if you
**	don't have enough fuel, or if you by chance run into something,
**	or some such thing, you blow up anyway.  Oh yeh, if you are
**	within two sectors of the star, there is nothing that can
**	be done for you.
**
**	When a star has gone supernova, the quadrant becomes uninhab-
**	itable for the rest of eternity, i.e., the game.  If you ever
**	try stopping in such a quadrant, you will go into emergency
**	override mode.
*/

snova(x, y)
int	x, y;
{
	int			qx, qy;
	register int		ix, iy;
	int			f;
	int			dx, dy;
	int			n;
	register struct quad	*q;

	f = 0;
	ix = x;
	if (ix < 0)
	{
		/* choose a quadrant */
		while (1)
		{
			qx = ranf(NQUADS);
			qy = ranf(NQUADS);
			q = &Quad[qx][qy];
			if (q->stars > 0)
				break;
		}
		if (Ship.quadx == qx && Ship.quady == qy)
		{
			/* select a particular star */
			n = ranf(q->stars);
			for (ix = 0; ix < NSECTS; ix++)
			{
				for (iy = 0; iy < NSECTS; iy++)
					if (Sect[ix][iy] == STAR || Sect[ix][iy] == INHABIT)
D 2
						if ((n =- 1) <= 0)
E 2
I 2
						if ((n -= 1) <= 0)
E 2
							break;
				if (n <= 0)
					break;
			}
			f = 1;
		}
	}
	else
	{
		/* current quadrant */
		iy = y;
		qx = Ship.quadx;
		qy = Ship.quady;
		q = &Quad[qx][qy];
		f = 1;
	}
	if (f)
	{
		/* supernova is in same quadrant as Enterprise */
		printf("\nRED ALERT: supernova occuring at %d,%d\n", ix, iy);
		dx = ix - Ship.sectx;
		dy = iy - Ship.secty;
		if (dx * dx + dy * dy <= 2)
		{
			printf("***  Emergency override attem");
			sleep(1);
			printf("\n");
			lose(L_SNOVA);
		}
		q->scanned = 1000;
	}
	else
	{
		if (!damaged(SSRADIO))
		{
			q->scanned = 1000;
			printf("\nUhura: Captain, Starfleet Command reports a supernova\n");
			printf("  in quadrant %d,%d.  Caution is advised\n", qx, qy);
		}
	}

	/* clear out the supernova'ed quadrant */
	dx = q->klings;
	dy = q->stars;
D 2
	Now.klings =- dx;
E 2
I 2
	Now.klings -= dx;
E 2
	if (x >= 0)
	{
		/* Enterprise caused supernova */
D 2
		Game.kills =+ dy;
E 2
I 2
		Game.kills += dy;
E 2
		if (q->bases)
			killb(qx, qy, -1);
D 2
		Game.killk =+ dx;
E 2
I 2
		Game.killk += dx;
E 2
	}
	else
		if (q->bases)
			killb(qx, qy, 0);
	killd(qx, qy, (x >= 0));
	q->stars = -1;
	q->klings = 0;
	if (Now.klings <= 0)
	{
		printf("Lucky devil, that supernova destroyed the last klingon\n");
		win();
	}
	return;
}
E 1
