h38942
s 00010/00005/00221
d D 5.3 88/06/18 15:08:29 bostic 6 5
c install approved copyright notice
e
s 00009/00003/00217
d D 5.2 88/05/05 18:34:54 bostic 5 4
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00213
d D 5.1 86/01/29 16:37:28 mckusick 4 3
c add copyright
e
s 00002/00001/00212
d D 4.3 83/05/27 00:34:57 layer 3 2
c finished conversion to 4.1c
e
s 00011/00011/00202
d D 4.2 83/05/09 21:55:23 layer 2 1
c conversion of source code to 4.1c BSD
e
s 00213/00000/00000
d D 4.1 83/03/23 15:01:54 mckusick 1 0
c date and time created 83/03/23 15:01:54 by mckusick
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

I 3
# include	<stdio.h>
E 3
# include	"trek.h"

/*
**  PHOTON TORPEDO CONTROL
**
**	Either one or three photon torpedoes are fired.  If three
**	are fired, it is called a "burst" and you also specify
**	a spread angle.
**
**	Torpedoes are never 100% accurate.  There is always a random
**	cludge factor in their course which is increased if you have
**	your shields up.  Hence, you will find that they are more
**	accurate at close range.  However, they have the advantage that
**	at long range they don't lose any of their power as phasers
**	do, i.e., a hit is a hit is a hit, by any other name.
**
**	When the course spreads too much, you get a misfire, and the
**	course is randomized even more.  You also have the chance that
**	the misfire damages your torpedo tubes.
*/


torped()
{
	register int		ix, iy;
	double			x, y, dx, dy;
	double			angle;
	int			course, course2;
	register int		k;
	double			bigger;
	double			sectsize;
	int			burst;
	int			n;

	if (Ship.cloaked)
	{
		return (printf("Federation regulations do not permit attack while cloaked.\n"));
	}
	if (check_out(TORPED))
		return;
	if (Ship.torped <= 0)
	{
		return (printf("All photon torpedos expended\n"));
	}

	/* get the course */
	course = getintpar("Torpedo course");
	if (course < 0 || course > 360)
		return;
	burst = -1;

	/* need at least three torpedoes for a burst */
	if (Ship.torped < 3)
	{
		printf("No-burst mode selected\n");
		burst = 0;
	}
	else
	{
		/* see if the user wants one */
		if (!testnl())
		{
D 3
			k = ungetc(cgetc(0), 0);
E 3
I 3
			k = ungetc(cgetc(0), stdin);
E 3
			if (k >= '0' && k <= '9')
				burst = 1;
		}
	}
	if (burst < 0)
	{
		burst = getynpar("Do you want a burst");
	}
	if (burst)
	{
		burst = getintpar("burst angle");
		if (burst <= 0)
			return;
		if (burst > 15)
			return (printf("Maximum burst angle is 15 degrees\n"));
	}
	sectsize = NSECTS;
	n = -1;
	if (burst)
	{
		n = 1;
D 2
		course =- burst;
E 2
I 2
		course -= burst;
E 2
	}
	for (; n && n <= 3; n++)
	{
		/* select a nice random course */
		course2 = course + randcourse(n);
		angle = course2 * 0.0174532925;			/* convert to radians */
		dx = -cos(angle);
		dy =  sin(angle);
		bigger = fabs(dx);
		x = fabs(dy);
		if (x > bigger)
			bigger = x;
D 2
		dx =/ bigger;
		dy =/ bigger;
E 2
I 2
		dx /= bigger;
		dy /= bigger;
E 2
		x = Ship.sectx + 0.5;
		y = Ship.secty + 0.5;
		if (Ship.cond != DOCKED)
D 2
			Ship.torped =- 1;
E 2
I 2
			Ship.torped -= 1;
E 2
		printf("Torpedo track");
		if (n > 0)
			printf(", torpedo number %d", n);
		printf(":\n%6.1f\t%4.1f\n", x, y);
		while (1)
		{
D 2
			ix = x =+ dx;
			iy = y =+ dy;
E 2
I 2
			ix = x += dx;
			iy = y += dy;
E 2
			if (x < 0.0 || x >= sectsize || y < 0.0 || y >= sectsize)
			{
				printf("Torpedo missed\n");
				break;
			}
			printf("%6.1f\t%4.1f\n", x, y);
			switch (Sect[ix][iy])
			{
			  case EMPTY:
				continue;
	
			  case HOLE:
				printf("Torpedo disappears into a black hole\n");
				break;

			  case KLINGON:
				for (k = 0; k < Etc.nkling; k++)
				{
					if (Etc.klingon[k].x != ix || Etc.klingon[k].y != iy)
						continue;
D 2
					Etc.klingon[k].power =- 500 + ranf(501);
E 2
I 2
					Etc.klingon[k].power -= 500 + ranf(501);
E 2
					if (Etc.klingon[k].power > 0)
					{
						printf("*** Hit on Klingon at %d,%d: extensive damages\n",
							ix, iy);
						break;
					}
					killk(ix, iy);
					break;
				}
				break;
	
			  case STAR:
				nova(ix, iy);
				break;
	
			  case INHABIT:
				kills(ix, iy, -1);
				break;
	
			  case BASE:
				killb(Ship.quadx, Ship.quady);
D 2
				Game.killb =+ 1;
E 2
I 2
				Game.killb += 1;
E 2
				break;
			  default:
				printf("Unknown object %c at %d,%d destroyed\n",
					Sect[ix][iy], ix, iy);
				Sect[ix][iy] = EMPTY;
				break;
			}
			break;
		}
		if (damaged(TORPED) || Quad[Ship.quadx][Ship.quady].stars < 0)
			break;
D 2
		course =+ burst;
E 2
I 2
		course += burst;
E 2
	}
	Move.free = 0;
}


/*
**  RANDOMIZE COURSE
**
**	This routine randomizes the course for torpedo number 'n'.
**	Other things handled by this routine are misfires, damages
**	to the tubes, etc.
*/

randcourse(n)
int	n;
{
	double			r;
	register int		d;

	d = ((franf() + franf()) - 1.0) * 20;
	if (abs(d) > 12)
	{
		printf("Photon tubes misfire");
		if (n < 0)
			printf("\n");
		else
			printf(" on torpedo %d\n", n);
		if (ranf(2))
		{
			damage(TORPED, 0.2 * abs(d) * (franf() + 1.0));
		}
D 2
		d =* 1.0 + 2.0 * franf();
E 2
I 2
		d *= 1.0 + 2.0 * franf();
E 2
	}
	if (Ship.shldup || Ship.cond == DOCKED)
	{
		r = Ship.shield;
		r = 1.0 + r / Param.shield;
		if (Ship.cond == DOCKED)
			r = 2.0;
D 2
		d =* r;
E 2
I 2
		d *= r;
E 2
	}
	return (d);
}
E 1
