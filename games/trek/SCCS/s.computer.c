h65327
s 00010/00005/00317
d D 4.6 88/06/18 15:07:17 bostic 6 5
c install approved copyright notice
e
s 00009/00003/00313
d D 4.5 88/05/05 18:33:24 bostic 5 4
c written by Eric Allman; add Berkeley header
e
s 00001/00001/00315
d D 4.4 87/10/07 07:55:12 bostic 4 3
c this is wrong anyway, but cast it to get rid of the error message
e
s 00007/00001/00309
d D 4.3 86/01/29 16:23:59 mckusick 3 2
c add copyright
e
s 00019/00019/00291
d D 4.2 83/05/27 00:33:18 layer 2 1
c finished conversion to 4.1c
e
s 00310/00000/00000
d D 4.1 83/03/23 14:58:33 mckusick 1 0
c date and time created 83/03/23 14:58:33 by mckusick
e
u
U
t
T
I 3
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

E 3
I 1
#ifndef lint
D 3
static char sccsid[] = "%W%	(Berkeley)	%G%";
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
E 3
D 5
#endif not lint
E 5
I 5
#endif /* not lint */
E 5

# include	"trek.h"
# include	"getpar.h"
D 2

E 2
I 2
# include	<stdio.h>
E 2
/*
**  On-Board Computer
**
**	A computer request is fetched from the captain.  The requests
**	are:
**
**	chart -- print a star chart of the known galaxy.  This includes
**		every quadrant that has ever had a long range or
**		a short range scan done of it, plus the location of
**		all starbases.  This is of course updated by any sub-
**		space radio broadcasts (unless the radio is out).
**		The format is the same as that of a long range scan
**		except that ".1." indicates that a starbase exists
**		but we know nothing else.
**
**	trajectory -- gives the course and distance to every know
**		Klingon in the quadrant.  Obviously this fails if the
**		short range scanners are out.
**
**	course -- gives a course computation from whereever you are
**		to any specified location.  If the course begins
**		with a slash, the current quadrant is taken.
**		Otherwise the input is quadrant and sector coordi-
**		nates of the target sector.
**
**	move -- identical to course, except that the move is performed.
**
**	score -- prints out the current score.
**
**	pheff -- "PHaser EFFectiveness" at a given distance.  Tells
**		you how much stuff you need to make it work.
**
**	warpcost -- Gives you the cost in time and units to move for
**		a given distance under a given warp speed.
**
**	impcost -- Same for the impulse engines.
**
**	distresslist -- Gives a list of the currently known starsystems
**		or starbases which are distressed, together with their
**		quadrant coordinates.
**
**	If a command is terminated with a semicolon, you remain in
**	the computer; otherwise, you escape immediately to the main
**	command processor.
*/

D 2
struct cvntab	Cputab[]
E 2
I 2
struct cvntab	Cputab[] =
E 2
{
D 2
	"ch",			"art",			1,		0,
	"t",			"rajectory",		2,		0,
	"c",			"ourse",		3,		0,
	"m",			"ove",			3,		1,
	"s",			"core",			4,		0,
	"p",			"heff",			5,		0,
	"w",			"arpcost",		6,		0,
	"i",			"mpcost",		7,		0,
	"d",			"istresslist",		8,		0,
E 2
I 2
	"ch",			"art",			(int (*)())1,		0,
	"t",			"rajectory",		(int (*)())2,		0,
	"c",			"ourse",		(int (*)())3,		0,
	"m",			"ove",			(int (*)())3,		1,
	"s",			"core",			(int (*)())4,		0,
	"p",			"heff",			(int (*)())5,		0,
	"w",			"arpcost",		(int (*)())6,		0,
	"i",			"mpcost",		(int (*)())7,		0,
	"d",			"istresslist",		(int (*)())8,		0,
E 2
	0
};

computer()
{
	int			ix, iy;
	register int		i, j;
	int			numout;
	int			tqx, tqy;
	struct cvntab		*r;
	int			cost;
	int			course;
D 2
	float			dist, time;
	float			warpfact;
E 2
I 2
	double			dist, time;
	double			warpfact;
E 2
	struct quad		*q;
	register struct event	*e;

	if (check_out(COMPUTER))
		return;
	while (1)
	{
		r = getcodpar("\nRequest", Cputab);
D 4
		switch (r->value)
E 4
I 4
		switch ((int)r->value)
E 4
		{

		  case 1:			/* star chart */
			printf("Computer record of galaxy for all long range sensor scans\n\n");
			printf("  ");
			/* print top header */
			for (i = 0; i < NQUADS; i++)
				printf("-%d- ", i);
			printf("\n");
			for (i = 0; i < NQUADS; i++)
			{
				printf("%d ", i);
				for (j = 0; j < NQUADS; j++)
				{
					if (i == Ship.quadx && j == Ship.quady)
					{
						printf("$$$ ");
						continue;
					}
					q = &Quad[i][j];
					/* 1000 or 1001 is special case */
					if (q->scanned >= 1000)
						if (q->scanned > 1000)
							printf(".1. ");
						else
							printf("/// ");
					else
						if (q->scanned < 0)
							printf("... ");
						else
							printf("%3d ", q->scanned);
				}
				printf("%d\n", i);
			}
			printf("  ");
			/* print bottom footer */
			for (i = 0; i < NQUADS; i++)
				printf("-%d- ", i);
			printf("\n");
			break;

		  case 2:			/* trajectory */
			if (check_out(SRSCAN))
			{
				break;
			}
			if (Etc.nkling <= 0)
			{
				printf("No Klingons in this quadrant\n");
				break;
			}
			/* for each Klingon, give the course & distance */
			for (i = 0; i < Etc.nkling; i++)
			{
				printf("Klingon at %d,%d", Etc.klingon[i].x, Etc.klingon[i].y);
				course = kalc(Ship.quadx, Ship.quady, Etc.klingon[i].x, Etc.klingon[i].y, &dist);
				prkalc(course, dist);
			}
			break;

		  case 3:			/* course calculation */
			if (readdelim('/'))
			{
				tqx = Ship.quadx;
				tqy = Ship.quady;
			}
			else
			{
				ix = getintpar("Quadrant");
				if (ix < 0 || ix >= NSECTS)
					break;
				iy = getintpar("q-y");
				if (iy < 0 || iy >= NSECTS)
					break;
				tqx = ix;
				tqy = iy;
			}
			ix = getintpar("Sector");
			if (ix < 0 || ix >= NSECTS)
				break;
			iy = getintpar("s-y");
			if (iy < 0 || iy >= NSECTS)
				break;
			course = kalc(tqx, tqy, ix, iy, &dist);
			if (r->value2)
			{
				warp(-1, course, dist);
				break;
			}
			printf("%d,%d/%d,%d to %d,%d/%d,%d",
				Ship.quadx, Ship.quady, Ship.sectx, Ship.secty, tqx, tqy, ix, iy);
			prkalc(course, dist);
			break;

		  case 4:			/* score */
			score();
			break;

		  case 5:			/* phaser effectiveness */
			dist = getfltpar("range");
			if (dist < 0.0)
				break;
D 2
			dist =* 10.0;
E 2
I 2
			dist *= 10.0;
E 2
			cost = pow(0.90, dist) * 98.0 + 0.5;
			printf("Phasers are %d%% effective at that range\n", cost);
			break;

		  case 6:			/* warp cost (time/energy) */
			dist = getfltpar("distance");
			if (dist < 0.0)
				break;
			warpfact = getfltpar("warp factor");
			if (warpfact <= 0.0)
				warpfact = Ship.warp;
			cost = (dist + 0.05) * warpfact * warpfact * warpfact;
			time = Param.warptime * dist / (warpfact * warpfact);
			printf("Warp %.2f distance %.2f cost %.2f stardates %d (%d w/ shlds up) units\n",
				warpfact, dist, time, cost, cost + cost);
			break;

		  case 7:			/* impulse cost */
			dist = getfltpar("distance");
			if (dist < 0.0)
				break;
			cost = 20 + 100 * dist;
			time = dist / 0.095;
			printf("Distance %.2f cost %.2f stardates %d units\n",
				dist, time, cost);
			break;

		  case 8:			/* distresslist */
			j = 1;
			printf("\n");
			/* scan the event list */
			for (i = 0; i < MAXEVENTS; i++)
			{
				e = &Event[i];
				/* ignore hidden entries */
				if (e->evcode & E_HIDDEN)
					continue;
				switch (e->evcode & E_EVENT)
				{

				  case E_KDESB:
					printf("Klingon is attacking starbase in quadrant %d,%d\n",
						e->x, e->y);
					j = 0;
					break;

				  case E_ENSLV:
				  case E_REPRO:
					printf("Starsystem %s in quadrant %d,%d is distressed\n",
						systemname(e), e->x, e->y);
					j = 0;
					break;
				}
			}
			if (j)
				printf("No known distress calls are active\n");
			break;

		}

		/* skip to next semicolon or newline.  Semicolon
		 * means get new computer request; newline means
		 * exit computer mode. */
		while ((i = cgetc(0)) != ';')
		{
			if (i == '\0')
				exit(1);
			if (i == '\n')
			{
D 2
				ungetc(i, 0);
E 2
I 2
				ungetc(i, stdin);
E 2
				return;
			}
		}
	}
}


/*
**  Course Calculation
**
**	Computes and outputs the course and distance from position
**	sqx,sqy/ssx,ssy to tqx,tqy/tsx,tsy.
*/

kalc(tqx, tqy, tsx, tsy, dist)
int	tqx;
int	tqy;
int	tsx;
int	tsy;
D 2
float	*dist;
E 2
I 2
double	*dist;
E 2
{
	double			dx, dy;
D 2
	float			quadsize;
E 2
I 2
	double			quadsize;
E 2
	double			angle;
	register int		course;

	/* normalize to quadrant distances */
	quadsize = NSECTS;
	dx = (Ship.quadx + Ship.sectx / quadsize) - (tqx + tsx / quadsize);
	dy = (tqy + tsy / quadsize) - (Ship.quady + Ship.secty / quadsize);

	/* get the angle */
	angle = atan2(dy, dx);
	/* make it 0 -> 2 pi */
	if (angle < 0.0)
D 2
		angle =+ 6.283185307;
E 2
I 2
		angle += 6.283185307;
E 2
	/* convert from radians to degrees */
	course = angle * 57.29577951 + 0.5;
	dx = dx * dx + dy * dy;
	*dist = sqrt(dx);
	return (course);
}


prkalc(course, dist)
int	course;
D 2
float	dist;
E 2
I 2
double	dist;
E 2
{
	printf(": course %d  dist %.3f\n", course, dist);
}
E 1
