h52660
s 00010/00005/00054
d D 5.3 88/06/18 15:07:44 bostic 6 5
c install approved copyright notice
e
s 00009/00003/00050
d D 5.2 88/05/05 18:34:02 bostic 5 4
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00046
d D 5.1 85/05/30 08:54:38 dist 4 3
c Add copyright
e
s 00002/00002/00045
d D 4.3 83/05/27 00:33:57 layer 3 2
c finished conversion to 4.1c
e
s 00001/00001/00046
d D 4.2 83/05/09 21:54:47 layer 2 1
c conversion of source code to 4.1c BSD
e
s 00047/00000/00000
d D 4.1 83/03/23 14:59:47 mckusick 1 0
c date and time created 83/03/23 14:59:47 by mckusick
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

/**
 **	move under impulse power
 **/

impulse()
{
	int			course;
	register int		power;
D 3
	float			dist, time;
E 3
I 3
	double			dist, time;
E 3
	register int		percent;
D 3
	extern float		move();
E 3
I 3
	extern double		move();
E 3

	if (Ship.cond == DOCKED)
		return (printf("Scotty: Sorry captain, but we are still docked.\n"));
	if (damaged(IMPULSE))
		return (out(IMPULSE));
	if (getcodi(&course, &dist))
		return;
	power = 20 + 100 * dist;
	percent = 100 * power / Ship.energy + 0.5;
	if (percent >= 85)
	{
		printf("Scotty: That would consume %d%% of our remaining energy.\n",
			percent);
		if (!getynpar("Are you sure that is wise"))
			return;
		printf("Aye aye, sir\n");
	}
	time = dist / 0.095;
	percent = 100 * time / Now.time + 0.5;
	if (percent >= 85)
	{
		printf("Spock: That would take %d%% of our remaining time.\n",
			percent);
		if (!getynpar("Are you sure that is wise"))
			return;
		printf("(He's finally gone mad)\n");
	}
	Move.time = move(0, course, time, 0.095);
D 2
	Ship.energy =- 20 + 100 * Move.time * 0.095;
E 2
I 2
	Ship.energy -= 20 + 100 * Move.time * 0.095;
E 2
}
E 1
