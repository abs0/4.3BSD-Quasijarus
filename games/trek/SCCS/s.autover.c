h08090
s 00010/00005/00051
d D 5.4 88/06/18 15:07:06 bostic 6 5
c install approved copyright notice
e
s 00001/00001/00055
d D 5.3 88/06/12 12:08:59 bostic 5 4
c remove non-printable characters
e
s 00009/00003/00047
d D 5.2 88/05/05 18:33:12 bostic 4 3
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00043
d D 5.1 85/05/30 08:48:27 dist 3 2
c Add copyright
e
s 00001/00001/00043
d D 4.2 83/05/27 00:33:08 layer 2 1
c finished conversion to 4.1c
e
s 00044/00000/00000
d D 4.1 83/03/23 14:58:10 mckusick 1 0
c date and time created 83/03/23 14:58:10 by mckusick
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
**  Automatic Override
**
**	If we should be so unlucky as to be caught in a quadrant
**	with a supernova in it, this routine is called.  It is
**	called from checkcond().
**
**	It sets you to a random warp (guaranteed to be over 6.0)
**	and starts sending you off "somewhere" (whereever that is).
**
**	Please note that it is VERY important that you reset your
**	warp speed after the automatic override is called.  The new
**	warp factor does not stay in effect for just this routine.
**
**	This routine will never try to send you more than sqrt(2)
**	quadrants, since that is all that is needed.
*/

autover()
{
D 2
	float			dist;
E 2
I 2
	double			dist;
E 2
	register int		course;

D 5
	printf("RED ALERT:  The %s is in a supernova quadrant\n", Ship.shipname);
E 5
I 5
	printf("\07RED ALERT:  The %s is in a supernova quadrant\n", Ship.shipname);
E 5
	printf("***  Emergency override attempts to hurl %s to safety\n", Ship.shipname);
	/* let's get our ass out of here */
	Ship.warp = 6.0 + 2.0 * franf();
	Ship.warp2 = Ship.warp * Ship.warp;
	Ship.warp3 = Ship.warp2 * Ship.warp;
	dist = 0.75 * Ship.energy / (Ship.warp3 * (Ship.shldup + 1));
	if (dist > 1.4142)
		dist = 1.4142;
	course = ranf(360);
	Etc.nkling = -1;
	Ship.cond = RED;
	warp(-1, course, dist);
	attack(0);
}
E 1
