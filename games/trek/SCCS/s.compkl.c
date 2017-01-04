h02860
s 00010/00005/00086
d D 5.3 88/06/18 15:07:16 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00082
d D 5.2 88/05/05 18:33:22 bostic 4 3
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00078
d D 5.1 85/05/30 08:49:39 dist 3 2
c Add copyright
e
s 00000/00001/00079
d D 4.2 83/05/27 00:33:15 layer 2 1
c finished conversion to 4.1c
e
s 00080/00000/00000
d D 4.1 83/03/23 14:58:28 mckusick 1 0
c date and time created 83/03/23 14:58:28 by mckusick
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
**  compute klingon distances
**
**	The klingon list has the distances for all klingons recomputed
**	and sorted.  The parameter is a Boolean flag which is set if
**	we have just entered a new quadrant.
**
**	This routine is used every time the Enterprise or the Klingons
**	move.
*/

compkldist(f)
int	f;		/* set if new quadrant */
{
	register int		i, dx, dy;
	double			d;
	double			temp;

	if (Etc.nkling == 0)
		return;
	for (i = 0; i < Etc.nkling; i++)
	{
		/* compute distance to the Klingon */
		dx = Ship.sectx - Etc.klingon[i].x;
		dy = Ship.secty - Etc.klingon[i].y;
		d = dx * dx + dy * dy;
		d = sqrt(d);

		/* compute average of new and old distances to Klingon */
		if (!f)
		{
			temp = Etc.klingon[i].dist;
			Etc.klingon[i].avgdist = 0.5 * (temp + d);
		}
		else
		{
			/* new quadrant: average is current */
			Etc.klingon[i].avgdist = d;
		}
		Etc.klingon[i].dist = d;
	}

	/* leave them sorted */
	sortkl();
}


/*
**  sort klingons
**
**	bubble sort on ascending distance
*/

sortkl()
{
	struct kling		t;
	register int		f, i, m;

	m = Etc.nkling - 1;
	f = 1;
	while (f)
	{
		f = 0;
		for (i = 0; i < m; i++)
			if (Etc.klingon[i].dist > Etc.klingon[i+1].dist)
			{
				bmove(&Etc.klingon[i], &t, sizeof t);
				bmove(&Etc.klingon[i+1], &Etc.klingon[i], sizeof t);
				bmove(&t, &Etc.klingon[i+1], sizeof t);
				f = 1;
			}
	}
D 2
	return;
E 2
}
E 1
