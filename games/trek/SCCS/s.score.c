h45302
s 00010/00005/00078
d D 5.3 88/06/18 15:08:15 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00074
d D 5.2 88/05/05 18:34:38 bostic 4 3
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00070
d D 5.1 85/05/30 09:03:21 dist 3 2
c Add copyright
e
s 00012/00012/00059
d D 4.2 83/05/09 21:55:14 layer 2 1
c conversion of source code to 4.1c BSD
e
s 00071/00000/00000
d D 4.1 83/03/23 15:01:14 mckusick 1 0
c date and time created 83/03/23 15:01:14 by mckusick
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

/*
**  PRINT OUT THE CURRENT SCORE
*/

long score()
{
	register int		u;
	register int		t;
	long			s;
	double			r;
	extern struct cvntab	Skitab[];

	printf("\n*** Your score:\n");
	s = t = Param.klingpwr / 4 * (u = Game.killk);
	if (t != 0)
		printf("%d Klingons killed\t\t\t%6d\n", u, t);
	r = Now.date - Param.date;
	if (r < 1.0)
		r = 1.0;
	r = Game.killk / r;
D 2
	s =+ (t = 400 * r);
E 2
I 2
	s += (t = 400 * r);
E 2
	if (t != 0)
		printf("Kill rate %.2f Klingons/stardate  \t%6d\n", r, t);
	r = Now.klings;
D 2
	r =/ Game.killk + 1;
	s =+ (t = -400 * r);
E 2
I 2
	r /= Game.killk + 1;
	s += (t = -400 * r);
E 2
	if (t != 0)
		printf("Penalty for %d klingons remaining\t%6d\n", Now.klings, t);
	if (Move.endgame > 0)
	{
D 2
		s =+ (t = 100 * (u = Game.skill));
E 2
I 2
		s += (t = 100 * (u = Game.skill));
E 2
		printf("Bonus for winning a %s%s game\t\t%6d\n", Skitab[u - 1].abrev, Skitab[u - 1].full, t);
	}
	if (Game.killed)
	{
D 2
		s =- 500;
E 2
I 2
		s -= 500;
E 2
		printf("Penalty for getting killed\t\t  -500\n");
	}
D 2
	s =+ (t = -100 * (u = Game.killb));
E 2
I 2
	s += (t = -100 * (u = Game.killb));
E 2
	if (t != 0)
		printf("%d starbases killed\t\t\t%6d\n", u, t);
D 2
	s =+ (t = -100 * (u = Game.helps));
E 2
I 2
	s += (t = -100 * (u = Game.helps));
E 2
	if (t != 0)
		printf("%d calls for help\t\t\t%6d\n", u, t);
D 2
	s =+ (t = -5 * (u = Game.kills));
E 2
I 2
	s += (t = -5 * (u = Game.kills));
E 2
	if (t != 0)
		printf("%d stars destroyed\t\t\t%6d\n", u, t);
D 2
	s =+ (t = -150 * (u = Game.killinhab));
E 2
I 2
	s += (t = -150 * (u = Game.killinhab));
E 2
	if (t != 0)
		printf("%d inhabited starsystems destroyed\t%6d\n", u, t);
	if (Ship.ship != ENTERPRISE)
	{
D 2
		s =- 200;
E 2
I 2
		s -= 200;
E 2
		printf("penalty for abandoning ship\t\t  -200\n");
	}
D 2
	s =+ (t = 3 * (u = Game.captives));
E 2
I 2
	s += (t = 3 * (u = Game.captives));
E 2
	if (t != 0)
		printf("%d Klingons captured\t\t\t%6d\n", u, t);
D 2
	s =+ (t = -(u = Game.deaths));
E 2
I 2
	s += (t = -(u = Game.deaths));
E 2
	if (t != 0)
		printf("%d casualties\t\t\t\t%6d\n", u, t);
	printf("\n***  TOTAL\t\t\t%14ld\n", s);
	return (s);
}
E 1
