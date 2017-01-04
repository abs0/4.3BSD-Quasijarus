h27414
s 00010/00005/00156
d D 5.3 88/06/18 15:08:37 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00152
d D 5.2 88/05/05 18:35:04 bostic 4 3
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00148
d D 5.1 86/01/29 16:37:56 mckusick 3 2
c add copyright
e
s 00014/00014/00135
d D 4.2 83/05/27 00:35:06 layer 2 1
c finished conversion to 4.1c
e
s 00149/00000/00000
d D 4.1 83/03/23 15:02:13 mckusick 1 0
c date and time created 83/03/23 15:02:13 by mckusick
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
**  MOVE UNDER WARP POWER
**
**	This is both the "move" and the "ram" commands, differing
**	only in the flag 'fl'.  It is also used for automatic
**	emergency override mode, when 'fl' is < 0 and 'c' and 'd'
**	are the course and distance to be moved.  If 'fl' >= 0,
**	the course and distance are asked of the captain.
**
**	The guts of this routine are in the routine move(), which
**	is shared with impulse().  Also, the working part of this
**	routine is very small; the rest is to handle the slight chance
**	that you may be moving at some riduculous speed.  In that
**	case, there is code to handle time warps, etc.
*/

warp(fl, c, d)
int	fl, c;
double	d;
{
	int			course;
D 2
	float			power;
	float			dist;
	float			time;
	float			speed;
E 2
I 2
	double			power;
	double			dist;
	double			time;
	double			speed;
E 2
	double			frac;
	register int		percent;
	register int		i;
D 2
	extern float		move();
E 2
I 2
	extern double		move();
E 2

	if (Ship.cond == DOCKED)
		return (printf("%s is docked\n", Ship.shipname));
	if (damaged(WARP))
	{
		return (out(WARP));
	}
	if (fl < 0)
	{
		course = c;
		dist = d;
	}
	else
		if (getcodi(&course, &dist))
			return;

	/* check to see that we are not using an absurd amount of power */
	power = (dist + 0.05) * Ship.warp3;
	percent = 100 * power / Ship.energy + 0.5;
	if (percent >= 85)
	{
		printf("Scotty: That would consume %d%% of our remaining energy.\n",
			percent);
		if (!getynpar("Are you sure that is wise"))
			return;
	}

	/* compute the speed we will move at, and the time it will take */
	speed = Ship.warp2 / Param.warptime;
	time = dist / speed;

	/* check to see that that value is not ridiculous */
	percent = 100 * time / Now.time + 0.5;
	if (percent >= 85)
	{
		printf("Spock: That would take %d%% of our remaining time.\n",
			percent);
		if (!getynpar("Are you sure that is wise"))
			return;
	}

	/* compute how far we will go if we get damages */
	if (Ship.warp > 6.0 && ranf(100) < 20 + 15 * (Ship.warp - 6.0))
	{
		frac = franf();
D 2
		dist =* frac;
		time =* frac;
E 2
I 2
		dist *= frac;
		time *= frac;
E 2
		damage(WARP, (frac + 1.0) * Ship.warp * (franf() + 0.25) * 0.20);
	}

	/* do the move */
	Move.time = move(fl, course, time, speed);

	/* see how far we actually went, and decrement energy appropriately */
	dist = Move.time * speed;
D 2
	Ship.energy =- dist * Ship.warp3 * (Ship.shldup + 1);
E 2
I 2
	Ship.energy -= dist * Ship.warp3 * (Ship.shldup + 1);
E 2

	/* test for bizarre events */
	if (Ship.warp <= 9.0)
		return;
	printf("\n\n  ___ Speed exceeding warp nine ___\n\n");
	sleep(2);
	printf("Ship's safety systems malfunction\n");
	sleep(2);
	printf("Crew experiencing extreme sensory distortion\n");
	sleep(4);
	if (ranf(100) >= 100 * dist)
	{
		return (printf("Equilibrium restored -- all systems normal\n"));
	}

	/* select a bizzare thing to happen to us */
	percent = ranf(100);
	if (percent < 70)
	{
		/* time warp */
		if (percent < 35 || !Game.snap)
		{
			/* positive time warp */
			time = (Ship.warp - 8.0) * dist * (franf() + 1.0);
D 2
			Now.date =+ time;
E 2
I 2
			Now.date += time;
E 2
			printf("Positive time portal entered -- it is now Stardate %.2f\n",
				Now.date);
			for (i = 0; i < MAXEVENTS; i++)
			{
				percent = Event[i].evcode;
				if (percent == E_FIXDV || percent == E_LRTB)
D 2
					Event[i].date =+ time;
E 2
I 2
					Event[i].date += time;
E 2
			}
			return;
		}

		/* s/he got lucky: a negative time portal */
		time = Now.date;
D 2
		i = Etc.snapshot;
		bmove(i, &Quad, sizeof Quad);
		bmove(i =+ sizeof Quad, &Event, sizeof Event);
		bmove(i =+ sizeof Event, &Now, sizeof Now);
E 2
I 2
		i = (int) Etc.snapshot;
		bmove(i, Quad, sizeof Quad);
		bmove(i += sizeof Quad, Event, sizeof Event);
		bmove(i += sizeof Event, &Now, sizeof Now);
E 2
		printf("Negative time portal entered -- it is now Stardate %.2f\n",
			Now.date);
		for (i = 0; i < MAXEVENTS; i++)
			if (Event[i].evcode == E_FIXDV)
				reschedule(&Event[i], Event[i].date - time);
		return;
	}

	/* test for just a lot of damage */
	if (percent < 80)
		lose(L_TOOFAST);
	printf("Equilibrium restored -- extreme damage occured to ship systems\n");
	for (i = 0; i < NDEV; i++)
		damage(i, (3.0 * (franf() + franf()) + 1.0) * Param.damfac[i]);
	Ship.shldup = 0;
}
E 1
