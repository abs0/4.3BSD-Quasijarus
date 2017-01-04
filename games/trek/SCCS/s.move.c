h31812
s 00010/00005/00204
d D 5.3 88/06/18 15:07:57 bostic 6 5
c install approved copyright notice
e
s 00009/00003/00200
d D 5.2 88/05/05 18:34:18 bostic 5 4
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00196
d D 5.1 85/05/30 08:59:43 dist 4 3
c Add copyright
e
s 00007/00007/00190
d D 4.3 83/05/27 00:34:25 layer 3 2
c finished conversion to 4.1c
e
s 00008/00008/00189
d D 4.2 83/05/09 21:55:00 layer 2 1
c conversion of source code to 4.1c BSD
e
s 00197/00000/00000
d D 4.1 83/03/23 15:00:26 mckusick 1 0
c date and time created 83/03/23 15:00:26 by mckusick
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
**  Move Under Warp or Impulse Power
**
**	`Ramflag' is set if we are to be allowed to ram stars,
**	Klingons, etc.  This is passed from warp(), which gets it from
**	either play() or ram().  Course is the course (0 -> 360) at
**	which we want to move.  `Speed' is the speed we
**	want to go, and `time' is the expected time.  It
**	can get cut short if a long range tractor beam is to occur.  We
**	cut short the move so that the user doesn't get docked time and
**	energy for distance which he didn't travel.
**
**	We check the course through the current quadrant to see that he
**	doesn't run into anything.  After that, though, space sort of
**	bends around him.  Note that this puts us in the awkward posi-
**	tion of being able to be dropped into a sector which is com-
**	pletely surrounded by stars.  Oh Well.
**
**	If the SINS (Space Inertial Navigation System) is out, we ran-
**	domize the course accordingly before ever starting to move.
**	We will still move in a straight line.
**
**	Note that if your computer is out, you ram things anyway.  In
**	other words, if your computer and sins are both out, you're in
**	potentially very bad shape.
**
**	Klingons get a chance to zap you as you leave the quadrant.
**	By the way, they also try to follow you (heh heh).
**
**	Return value is the actual amount of time used.
**
**
**	Uses trace flag 4.
*/

D 3
float move(ramflag, course, time, speed)
E 3
I 3
double move(ramflag, course, time, speed)
E 3
int	ramflag;
int	course;
D 3
float	time;
float	speed;
E 3
I 3
double	time;
double	speed;
E 3
{
	double			angle;
D 3
	float			x, y, dx, dy;
E 3
I 3
	double			x, y, dx, dy;
E 3
	register int		ix, iy;
	double			bigger;
	int			n;
	register int		i;
D 3
	float			dist;
	float			sectsize;
E 3
I 3
	double			dist;
	double			sectsize;
E 3
	double			xn;
D 3
	float			evtime;
E 3
I 3
	double			evtime;
E 3

#	ifdef xTRACE
	if (Trace)
		printf("move: ramflag %d course %d time %.2f speed %.2f\n",
			ramflag, course, time, speed);
#	endif
	sectsize = NSECTS;
	/* initialize delta factors for move */
	angle = course * 0.0174532925;
	if (damaged(SINS))
D 2
		angle =+ Param.navigcrud[1] * (franf() - 0.5);
E 2
I 2
		angle += Param.navigcrud[1] * (franf() - 0.5);
E 2
	else
		if (Ship.sinsbad)
D 2
			angle =+ Param.navigcrud[0] * (franf() - 0.5);
E 2
I 2
			angle += Param.navigcrud[0] * (franf() - 0.5);
E 2
	dx = -cos(angle);
	dy = sin(angle);
	bigger = fabs(dx);
	dist = fabs(dy);
	if (dist > bigger)
		bigger = dist;
D 2
	dx =/ bigger;
	dy =/ bigger;
E 2
I 2
	dx /= bigger;
	dy /= bigger;
E 2

	/* check for long range tractor beams */
	/****  TEMPORARY CODE == DEBUGGING  ****/
	evtime = Now.eventptr[E_LRTB]->date - Now.date;
#	ifdef xTRACE
	if (Trace)
		printf("E.ep = %u, ->evcode = %d, ->date = %.2f, evtime = %.2f\n",
			Now.eventptr[E_LRTB], Now.eventptr[E_LRTB]->evcode,
			Now.eventptr[E_LRTB]->date, evtime);
#	endif
	if (time > evtime && Etc.nkling < 3)
	{
		/* then we got a LRTB */
D 2
		evtime =+ 0.005;
E 2
I 2
		evtime += 0.005;
E 2
		time = evtime;
	}
	else
		evtime = -1.0e50;
	dist = time * speed;

	/* move within quadrant */
	Sect[Ship.sectx][Ship.secty] = EMPTY;
	x = Ship.sectx + 0.5;
	y = Ship.secty + 0.5;
	xn = NSECTS * dist * bigger;
	n = xn + 0.5;
#	ifdef xTRACE
	if (Trace)
		printf("dx = %.2f, dy = %.2f, xn = %.2f, n = %d\n", dx, dy, xn, n);
#	endif
	Move.free = 0;

	for (i = 0; i < n; i++)
	{
D 2
		ix = (x =+ dx);
		iy = (y =+ dy);
E 2
I 2
		ix = (x += dx);
		iy = (y += dy);
E 2
#		ifdef xTRACE
		if (Trace)
			printf("ix = %d, x = %.2f, iy = %d, y = %.2f\n", ix, x, iy, y);
#		endif
		if (x < 0.0 || y < 0.0 || x >= sectsize || y >= sectsize)
		{
			/* enter new quadrant */
			dx = Ship.quadx * NSECTS + Ship.sectx + dx * xn;
			dy = Ship.quady * NSECTS + Ship.secty + dy * xn;
			if (dx < 0.0)
				ix = -1;
			else
				ix = dx + 0.5;
			if (dy < 0.0)
				iy = -1;
			else
				iy = dy + 0.5;
#			ifdef xTRACE
			if (Trace)
				printf("New quad: ix = %d, iy = %d\n", ix, iy);
#			endif
			Ship.sectx = x;
			Ship.secty = y;
			compkldist(0);
			Move.newquad = 2;
			attack(0);
			checkcond();
			Ship.quadx = ix / NSECTS;
			Ship.quady = iy / NSECTS;
			Ship.sectx = ix % NSECTS;
			Ship.secty = iy % NSECTS;
			if (ix < 0 || Ship.quadx >= NQUADS || iy < 0 || Ship.quady >= NQUADS)
				if (!damaged(COMPUTER))
				{
					dumpme(0);
				}
				else
					lose(L_NEGENB);
			initquad(0);
			n = 0;
			break;
		}
		if (Sect[ix][iy] != EMPTY)
		{
			/* we just hit something */
			if (!damaged(COMPUTER) && ramflag <= 0)
			{
				ix = x - dx;
				iy = y - dy;
				printf("Computer reports navigation error; %s stopped at %d,%d\n",
					Ship.shipname, ix, iy);
D 2
				Ship.energy =- Param.stopengy * speed;
E 2
I 2
				Ship.energy -= Param.stopengy * speed;
E 2
				break;
			}
			/* test for a black hole */
			if (Sect[ix][iy] == HOLE)
			{
				/* get dumped elsewhere in the galaxy */
				dumpme(1);
				initquad(0);
				n = 0;
				break;
			}
			ram(ix, iy);
			break;
		}
	}
	if (n > 0)
	{
		dx = Ship.sectx - ix;
		dy = Ship.secty - iy;
		dist = sqrt(dx * dx + dy * dy) / NSECTS;
		time = dist / speed;
		if (evtime > time)
			time = evtime;		/* spring the LRTB trap */
		Ship.sectx = ix;
		Ship.secty = iy;
	}
	Sect[Ship.sectx][Ship.secty] = Ship.ship;
	compkldist(0);
	return (time);
}
E 1
