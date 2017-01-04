h54205
s 00010/00005/00062
d D 5.3 88/06/18 15:07:29 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00058
d D 5.2 88/05/05 18:33:41 bostic 4 3
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00054
d D 5.1 85/05/30 08:52:33 dist 3 2
c Add copyright
e
s 00002/00002/00053
d D 4.2 83/05/09 21:54:29 layer 2 1
c conversion of source code to 4.1c BSD
e
s 00055/00000/00000
d D 4.1 83/03/23 14:59:09 mckusick 1 0
c date and time created 83/03/23 14:59:09 by mckusick
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
**  Dump the starship somewhere in the galaxy
**
**	Parameter is zero if bounce off of negative energy barrier,
**	one if through a black hole
**
**	Note that the quadrant is NOT initialized here.  This must
**	be done from the calling routine.
**
**	Repair of devices must be deferred.
*/

dumpme(flag)
int	flag;
{
	register int		f;
	double			x;
	register struct event	*e;
	register int		i;

	f = flag;
	Ship.quadx = ranf(NQUADS);
	Ship.quady = ranf(NQUADS);
	Ship.sectx = ranf(NSECTS);
	Ship.secty = ranf(NSECTS);
D 2
	x =+ 1.5 * franf();
	Move.time =+ x;
E 2
I 2
	x += 1.5 * franf();
	Move.time += x;
E 2
	if (f)
	{
		printf("%s falls into a black hole.\n", Ship.shipname);
	}
	else
	{
		printf("Computer applies full reverse power to avoid hitting the\n");
		printf("   negative energy barrier.  A space warp was entered.\n");
	}
	/* bump repair dates forward */
	for (i = 0; i < MAXEVENTS; i++)
	{
		e = &Event[i];
		if (e->evcode != E_FIXDV)
			continue;
		reschedule(e, (e->date - Now.date) + x);
	}
	events(1);
	printf("You are now in quadrant %d,%d.  It is stardate %.2f\n",
		Ship.quadx, Ship.quady, Now.date);
	Move.time = 0;
}
E 1
