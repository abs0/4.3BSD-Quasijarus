h29703
s 00010/00005/00131
d D 5.3 88/06/18 15:07:02 bostic 6 5
c install approved copyright notice
e
s 00009/00003/00127
d D 5.2 88/05/05 18:33:05 bostic 5 4
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00123
d D 5.1 85/05/30 08:47:44 dist 4 3
c Add copyright
e
s 00002/00002/00122
d D 4.3 83/05/27 00:33:03 layer 3 2
c finished conversion to 4.1c
e
s 00003/00003/00121
d D 4.2 83/05/09 21:53:53 layer 2 1
c conversion of source code to 4.1c BSD
e
s 00124/00000/00000
d D 4.1 83/03/23 14:57:56 mckusick 1 0
c date and time created 83/03/23 14:57:56 by mckusick
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
**  Abandon Ship
**
**	The ship is abandoned.  If your current ship is the Faire
**	Queene, or if your shuttlecraft is dead, you're out of
**	luck.  You need the shuttlecraft in order for the captain
**	(that's you!!) to escape.
**
**	Your crew can beam to an inhabited starsystem in the
**	quadrant, if there is one and if the transporter is working.
**	If there is no inhabited starsystem, or if the transporter
**	is out, they are left to die in outer space.
**
**	These currently just count as regular deaths, but they
**	should count very heavily against you.
**
**	If there are no starbases left, you are captured by the
**	Klingons, who torture you mercilessly.  However, if there
**	is at least one starbase, you are returned to the
**	Federation in a prisoner of war exchange.  Of course, this
**	can't happen unless you have taken some prisoners.
**
**	Uses trace flag 40
*/

abandon()
{
	register struct quad	*q;
	register int		i;
	int			j;
	register struct event	*e;

	if (Ship.ship == QUEENE)
		return (printf("You may not abandon ye Faire Queene\n"));
	if (Ship.cond != DOCKED)
	{
		if (damaged(SHUTTLE))
			return (out(SHUTTLE));
		printf("Officers escape in shuttlecraft\n");
		/* decide on fate of crew */
		q = &Quad[Ship.quadx][Ship.quady];
D 3
		if (q->systemname == 0 || damaged(XPORTER))
E 3
I 3
		if (q->qsystemname == 0 || damaged(XPORTER))
E 3
		{
			printf("Entire crew of %d left to die in outer space\n",
				Ship.crew);
D 2
			Game.deaths =+ Ship.crew;
E 2
I 2
			Game.deaths += Ship.crew;
E 2
		}
		else
		{
			printf("Crew beams down to planet %s\n", systemname(q));
		}
	}
	/* see if you can be exchanged */
	if (Now.bases == 0 || Game.captives < 20 * Game.skill)
		lose(L_CAPTURED);
	/* re-outfit new ship */
	printf("You are hereby put in charge of an antiquated but still\n");
	printf("  functional ship, the Fairie Queene.\n");
	Ship.ship = QUEENE;
	Ship.shipname = "Fairie Queene";
	Param.energy = Ship.energy = 3000;
	Param.torped = Ship.torped = 6;
	Param.shield = Ship.shield = 1250;
	Ship.shldup = 0;
	Ship.cloaked = 0;
	Ship.warp = 5.0;
	Ship.warp2 = 25.0;
	Ship.warp3 = 125.0;
	Ship.cond = GREEN;
	/* clear out damages on old ship */
	for (i = 0; i < MAXEVENTS; i++)
	{
		e = &Event[i];
		if (e->evcode != E_FIXDV)
			continue;
		unschedule(e);
	}
	/* get rid of some devices and redistribute probabilities */
	i = Param.damprob[SHUTTLE] + Param.damprob[CLOAK];
	Param.damprob[SHUTTLE] = Param.damprob[CLOAK] = 0;
	while (i > 0)
		for (j = 0; j < NDEV; j++)
		{
			if (Param.damprob[j] != 0)
			{
D 2
				Param.damprob[j] =+ 1;
				i =- 1;
E 2
I 2
				Param.damprob[j] += 1;
D 3
				i -= 1;
E 3
I 3
				i--;
E 3
E 2
				if (i <= 0)
					break;
			}
		}
	/* pick a starbase to restart at */
	i = ranf(Now.bases);
	Ship.quadx = Now.base[i].x;
	Ship.quady = Now.base[i].y;
	/* setup that quadrant */
	while (1)
	{
		initquad(1);
		Sect[Ship.sectx][Ship.secty] = EMPTY;
		for (i = 0; i < 5; i++)
		{
			Ship.sectx = Etc.starbase.x + ranf(3) - 1;
			if (Ship.sectx < 0 || Ship.sectx >= NSECTS)
				continue;
			Ship.secty = Etc.starbase.y + ranf(3) - 1;
			if (Ship.secty < 0 || Ship.secty >= NSECTS)
				continue;
			if (Sect[Ship.sectx][Ship.secty] == EMPTY)
			{
				Sect[Ship.sectx][Ship.secty] = QUEENE;
				dock();
				compkldist(0);
				return;
			}
		}
	}
}
E 1
