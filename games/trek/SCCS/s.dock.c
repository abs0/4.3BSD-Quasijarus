h14815
s 00010/00005/00118
d D 5.3 88/06/18 15:07:25 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00114
d D 5.2 88/05/05 18:33:36 bostic 4 3
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00110
d D 5.1 85/05/30 08:51:57 dist 3 2
c Add copyright
e
s 00001/00001/00110
d D 4.2 83/05/09 21:54:22 layer 2 1
c conversion of source code to 4.1c BSD
e
s 00111/00000/00000
d D 4.1 83/03/23 14:58:58 mckusick 1 0
c date and time created 83/03/23 14:58:58 by mckusick
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
**  DOCK TO STARBASE
**
**	The starship is docked to a starbase.  For this to work you
**	must be adjacent to a starbase.
**
**	You get your supplies replenished and your captives are
**	disembarked.  Note that your score is updated now, not when
**	you actually take the captives.
**
**	Any repairs that need to be done are rescheduled to take
**	place sooner.  This provides for the faster repairs when you
**	are docked.
*/

dock()
{
	register int		i, j;
	int			ok;
	register struct event	*e;

	if (Ship.cond == DOCKED)
		return (printf("Chekov: But captain, we are already docked\n"));
	/* check for ok to dock, i.e., adjacent to a starbase */
	ok = 0;
	for (i = Ship.sectx - 1; i <= Ship.sectx + 1 && !ok; i++)
	{
		if (i < 0 || i >= NSECTS)
			continue;
		for (j = Ship.secty - 1; j <= Ship.secty + 1; j++)
		{
			if (j  < 0 || j >= NSECTS)
				continue;
			if (Sect[i][j] == BASE)
			{
				ok++;
				break;
			}
		}
	}
	if (!ok)
		return (printf("Chekov: But captain, we are not adjacent to a starbase.\n"));

	/* restore resources */
	Ship.energy = Param.energy;
	Ship.torped = Param.torped;
	Ship.shield = Param.shield;
	Ship.crew = Param.crew;
D 2
	Game.captives =+ Param.brigfree - Ship.brigfree;
E 2
I 2
	Game.captives += Param.brigfree - Ship.brigfree;
E 2
	Ship.brigfree = Param.brigfree;

	/* reset ship's defenses */
	Ship.shldup = 0;
	Ship.cloaked = 0;
	Ship.cond = DOCKED;
	Ship.reserves = Param.reserves;

	/* recalibrate space inertial navigation system */
	Ship.sinsbad = 0;

	/* output any saved radio messages */
	dumpssradio();

	/* reschedule any device repairs */
	for (i = 0; i < MAXEVENTS; i++)
	{
		e = &Event[i];
		if (e->evcode != E_FIXDV)
			continue;
		reschedule(e, (e->date - Now.date) * Param.dockfac);
	}
	return;
}


/*
**  LEAVE A STARBASE
**
**	This is the inverse of dock().  The main function it performs
**	is to reschedule any damages so that they will take longer.
*/

undock()
{
	register struct event	*e;
	register int		i;

	if (Ship.cond != DOCKED)
	{
		printf("Sulu: Pardon me captain, but we are not docked.\n");
		return;
	}
	Ship.cond = GREEN;
	Move.free = 0;

	/* reschedule device repair times (again) */
	for (i = 0; i < MAXEVENTS; i++)
	{
		e = &Event[i];
		if (e->evcode != E_FIXDV)
			continue;
		reschedule(e, (e->date - Now.date) / Param.dockfac);
	}
	return;
}
E 1
