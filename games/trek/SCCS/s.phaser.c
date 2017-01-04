h38078
s 00010/00005/00343
d D 5.3 88/06/18 15:08:03 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00339
d D 5.2 88/05/05 18:34:25 bostic 4 3
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00335
d D 5.1 86/01/29 16:36:41 mckusick 3 2
c add copyright
e
s 00022/00022/00314
d D 4.2 83/05/27 14:57:56 layer 2 1
c git rid of compiler warns
e
s 00336/00000/00000
d D 4.1 83/03/23 15:00:42 mckusick 1 0
c date and time created 83/03/23 15:00:42 by mckusick
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
# include	"getpar.h"

/* factors for phaser hits; see description below */

# define	ALPHA		3.0		/* spread */
# define	BETA		3.0		/* franf() */
# define	GAMMA		0.30		/* cos(angle) */
# define	EPSILON		150.0		/* dist ** 2 */
# define	OMEGA		10.596		/* overall scaling factor */

/* OMEGA ~= 100 * (ALPHA + 1) * (BETA + 1) / (EPSILON + 1) */

/*
**  Phaser Control
**
**	There are up to NBANKS phaser banks which may be fired
**	simultaneously.  There are two modes, "manual" and
**	"automatic".  In manual mode, you specify exactly which
**	direction you want each bank to be aimed, the number
**	of units to fire, and the spread angle.  In automatic
**	mode, you give only the total number of units to fire.
**
**	The spread is specified as a number between zero and
**	one, with zero being minimum spread and one being maximum
**	spread.  You  will normally want zero spread, unless your
**	short range scanners are out, in which case you probably
**	don't know exactly where the Klingons are.  In that case,
**	you really don't have any choice except to specify a
**	fairly large spread.
**
**	Phasers spread slightly, even if you specify zero spread.
**
**	Uses trace flag 30
*/

D 2
struct cvntab	Matab[]
E 2
I 2
struct cvntab	Matab[] =
E 2
{
D 2
	"m",		"anual",		1,		0,
E 2
I 2
	"m",		"anual",		(int (*)())1,		0,
E 2
	"a",		"utomatic",		0,		0,
	0
};

struct banks
{
	int	units;
D 2
	float	angle;
	float	spread;
E 2
I 2
	double	angle;
	double	spread;
E 2
};



phaser()
{
	register int		i;
	int			j;
	register struct kling	*k;
	double			dx, dy;
	double			anglefactor, distfactor;
	register struct banks	*b;
	int			manual, flag, extra;
	int			hit;
	double			tot;
	int			n;
	int			hitreqd[NBANKS];
	struct banks		bank[NBANKS];
	struct cvntab		*ptr;

	if (Ship.cond == DOCKED)
		return(printf("Phasers cannot fire through starbase shields\n"));
	if (damaged(PHASER))
		return (out(PHASER));
	if (Ship.shldup)
		return (printf("Sulu: Captain, we cannot fire through shields.\n"));
	if (Ship.cloaked)
	{
		printf("Sulu: Captain, surely you must realize that we cannot fire\n");
		printf("  phasers with the cloaking device up.\n");
		return;
	}

	/* decide if we want manual or automatic mode */
	manual = 0;
	if (testnl())
	{
		if (damaged(COMPUTER))
		{
			printf(Device[COMPUTER].name);
			manual++;
		}
		else
			if (damaged(SRSCAN))
			{
				printf(Device[SRSCAN].name);
				manual++;
			}
		if (manual)
			printf(" damaged, manual mode selected\n");
	}

	if (!manual)
	{
		ptr = getcodpar("Manual or automatic", Matab);
D 2
		manual = ptr->value;
E 2
I 2
		manual = (int) ptr->value;
E 2
	}
	if (!manual && damaged(COMPUTER))
	{
		printf("Computer damaged, manual selected\n");
		skiptonl(0);
		manual++;
	}

	/* initialize the bank[] array */
	flag = 1;
	for (i = 0; i < NBANKS; i++)
		bank[i].units = 0;
	if (manual)
	{
		/* collect manual mode statistics */
		while (flag)
		{
			printf("%d units available\n", Ship.energy);
			extra = 0;
			flag = 0;
			for (i = 0; i < NBANKS; i++)
			{
				b = &bank[i];
				printf("\nBank %d:\n", i);
				hit = getintpar("units");
				if (hit < 0)
					return;
				if (hit == 0)
					break;
D 2
				extra =+ hit;
E 2
I 2
				extra += hit;
E 2
				if (extra > Ship.energy)
				{
					printf("available energy exceeded.  ");
					skiptonl(0);
					flag++;
					break;
				}
				b->units = hit;
				hit = getintpar("course");
				if (hit < 0 || hit > 360)
					return;
				b->angle = hit * 0.0174532925;
				b->spread = getfltpar("spread");
				if (b->spread < 0 || b->spread > 1)
					return;
			}
D 2
			Ship.energy =- extra;
E 2
I 2
			Ship.energy -= extra;
E 2
		}
		extra = 0;
	}
	else
	{
		/* automatic distribution of power */
		if (Etc.nkling <= 0)
			return (printf("Sulu: But there are no Klingons in this quadrant\n"));
		printf("Phasers locked on target.  ");
		while (flag)
		{
			printf("%d units available\n", Ship.energy);
			hit = getintpar("Units to fire");
			if (hit <= 0)
				return;
			if (hit > Ship.energy)
			{
				printf("available energy exceeded.  ");
				skiptonl(0);
				continue;
			}
			flag = 0;
D 2
			Ship.energy =- hit;
E 2
I 2
			Ship.energy -= hit;
E 2
			extra = hit;
			n = Etc.nkling;
			if (n > NBANKS)
				n = NBANKS;
			tot = n * (n + 1) / 2;
			for (i = 0; i < n; i++)
			{
				k = &Etc.klingon[i];
				b = &bank[i];
				distfactor = k->dist;
				anglefactor = ALPHA * BETA * OMEGA / (distfactor * distfactor + EPSILON);
D 2
				anglefactor =* GAMMA;
E 2
I 2
				anglefactor *= GAMMA;
E 2
				distfactor = k->power;
D 2
				distfactor =/ anglefactor;
E 2
I 2
				distfactor /= anglefactor;
E 2
				hitreqd[i] = distfactor + 0.5;
				dx = Ship.sectx - k->x;
				dy = k->y - Ship.secty;
				b->angle = atan2(dy, dx);
				b->spread = 0.0;
				b->units = ((n - i) / tot) * extra;
#				ifdef xTRACE
				if (Trace)
				{
					printf("b%d hr%d u%d df%.2f af%.2f\n",
						i, hitreqd[i], b->units,
						distfactor, anglefactor);
				}
#				endif
D 2
				extra =- b->units;
E 2
I 2
				extra -= b->units;
E 2
				hit = b->units - hitreqd[i];
				if (hit > 0)
				{
D 2
					extra =+ hit;
					b->units =- hit;
E 2
I 2
					extra += hit;
					b->units -= hit;
E 2
				}
			}

			/* give out any extra energy we might have around */
			if (extra > 0)
			{
				for (i = 0; i < n; i++)
				{
					b = &bank[i];
					hit = hitreqd[i] - b->units;
					if (hit <= 0)
						continue;
					if (hit >= extra)
					{
D 2
						b->units =+ extra;
E 2
I 2
						b->units += extra;
E 2
						extra = 0;
						break;
					}
					b->units = hitreqd[i];
D 2
					extra =- hit;
E 2
I 2
					extra -= hit;
E 2
				}
				if (extra > 0)
					printf("%d units overkill\n", extra);
			}
		}
	}

#	ifdef xTRACE
	if (Trace)
	{
		for (i = 0; i < NBANKS; i++)
		{
			b = &bank[i];
			printf("b%d u%d", i, b->units);
			if (b->units > 0)
				printf(" a%.2f s%.2f\n", b->angle, b->spread);
			else
				printf("\n");
		}
	}
#	endif

	/* actually fire the shots */
	Move.free = 0;
	for (i = 0; i < NBANKS; i++)
	{
		b = &bank[i];
		if (b->units <= 0)
		{
			continue;
		}
		printf("\nPhaser bank %d fires:\n", i);
		n = Etc.nkling;
		k = Etc.klingon;
		for (j = 0; j < n; j++)
		{
			if (b->units <= 0)
				break;
			/*
			** The formula for hit is as follows:
			**
			**  zap = OMEGA * [(sigma + ALPHA) * (rho + BETA)]
			**	/ (dist ** 2 + EPSILON)]
			**	* [cos(delta * sigma) + GAMMA]
			**	* hit
			**
			** where sigma is the spread factor,
			** rho is a random number (0 -> 1),
			** GAMMA is a crud factor for angle (essentially
			**	cruds up the spread factor),
			** delta is the difference in radians between the
			**	angle you are shooting at and the actual
			**	angle of the klingon,
			** ALPHA scales down the significance of sigma,
			** BETA scales down the significance of rho,
			** OMEGA is the magic number which makes everything
			**	up to "* hit" between zero and one,
			** dist is the distance to the klingon
			** hit is the number of units in the bank, and
			** zap is the amount of the actual hit.
			**
			** Everything up through dist squared should maximize
			** at 1.0, so that the distance factor is never
			** greater than one.  Conveniently, cos() is
			** never greater than one, but the same restric-
			** tion applies.
			*/
			distfactor = BETA + franf();
D 2
			distfactor =* ALPHA + b->spread;
			distfactor =* OMEGA;
E 2
I 2
			distfactor *= ALPHA + b->spread;
			distfactor *= OMEGA;
E 2
			anglefactor = k->dist;
D 2
			distfactor =/ anglefactor * anglefactor + EPSILON;
			distfactor =* b->units;
E 2
I 2
			distfactor /= anglefactor * anglefactor + EPSILON;
			distfactor *= b->units;
E 2
			dx = Ship.sectx - k->x;
			dy = k->y - Ship.secty;
			anglefactor = atan2(dy, dx) - b->angle;
			anglefactor = cos((anglefactor * b->spread) + GAMMA);
			if (anglefactor < 0.0)
			{
				k++;
				continue;
			}
			hit = anglefactor * distfactor + 0.5;
D 2
			k->power =- hit;
E 2
I 2
			k->power -= hit;
E 2
			printf("%d unit hit on Klingon", hit);
			if (!damaged(SRSCAN))
				printf(" at %d,%d", k->x, k->y);
			printf("\n");
D 2
			b->units =- hit;
E 2
I 2
			b->units -= hit;
E 2
			if (k->power <= 0)
			{
				killk(k->x, k->y);
				continue;
			}
			k++;
		}
	}

	/* compute overkill */
	for (i = 0; i < NBANKS; i++)
D 2
		extra =+ bank[i].units;
E 2
I 2
		extra += bank[i].units;
E 2
	if (extra > 0)
		printf("\n%d units expended on empty space\n", extra);
}
E 1
