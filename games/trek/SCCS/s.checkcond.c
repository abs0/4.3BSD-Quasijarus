h22137
s 00010/00005/00078
d D 5.3 88/06/18 15:07:14 bostic 4 3
c install approved copyright notice
e
s 00009/00003/00074
d D 5.2 88/05/05 18:33:20 bostic 3 2
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00070
d D 5.1 85/05/30 08:49:26 dist 2 1
c Add copyright
e
s 00071/00000/00000
d D 4.1 83/03/23 14:58:23 mckusick 1 0
c date and time created 83/03/23 14:58:23 by mckusick
e
u
U
t
T
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
D 3
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
I 3
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 4
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 4
I 4
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
E 4
E 3
 */

E 2
I 1
#ifndef lint
D 2
static char sccsid[] = "%W%	(Berkeley)	%G%";
E 2
I 2
static char sccsid[] = "%W% (Berkeley) %G%";
E 2
D 3
#endif not lint
E 3
I 3
#endif /* not lint */
E 3

# include	"trek.h"

/*
**  Check for Condition After a Move
**
**	Various ship conditions are checked.  First we check
**	to see if we have already lost the game, due to running
**	out of life support reserves, running out of energy,
**	or running out of crew members.  The check for running
**	out of time is in events().
**
**	If we are in automatic override mode (Etc.nkling < 0), we
**	don't want to do anything else, lest we call autover
**	recursively.
**
**	In the normal case, if there is a supernova, we call
**	autover() to help us escape.  If after calling autover()
**	we are still in the grips of a supernova, we get burnt
**	up.
**
**	If there are no Klingons in this quadrant, we nullify any
**	distress calls which might exist.
**
**	We then set the condition code, based on the energy level
**	and battle conditions.
*/

checkcond()
{
	register int		i, j;

	/* see if we are still alive and well */
	if (Ship.reserves < 0.0)
		lose(L_NOLIFE);
	if (Ship.energy <= 0)
		lose(L_NOENGY);
	if (Ship.crew <= 0)
		lose(L_NOCREW);
	/* if in auto override mode, ignore the rest */
	if (Etc.nkling < 0)
		return;
	/* call in automatic override if appropriate */
	if (Quad[Ship.quadx][Ship.quady].stars < 0)
		autover();
	if (Quad[Ship.quadx][Ship.quady].stars < 0)
		lose(L_SNOVA);
	/* nullify distress call if appropriate */
	if (Etc.nkling <= 0)
		killd(Ship.quadx, Ship.quady, 1);

	/* set condition code */
	if (Ship.cond == DOCKED)
		return;

	if (Etc.nkling > 0)
	{
		Ship.cond = RED;
		return;
	}
	if (Ship.energy < Param.energylow)
	{
		Ship.cond = YELLOW;
		return;
	}
	Ship.cond = GREEN;
	return;
}
E 1
