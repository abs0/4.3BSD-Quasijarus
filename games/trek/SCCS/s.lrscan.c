h06632
s 00010/00005/00081
d D 5.3 88/06/18 15:07:53 bostic 4 3
c install approved copyright notice
e
s 00009/00003/00077
d D 5.2 88/05/05 18:34:13 bostic 3 2
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00073
d D 5.1 85/05/30 08:56:19 dist 2 1
c Add copyright
e
s 00074/00000/00000
d D 4.1 83/03/23 15:00:16 mckusick 1 0
c date and time created 83/03/23 15:00:16 by mckusick
e
u
U
t
T
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
D 3
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
I 3
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 4
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 4
I 4
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
E 4
E 3
 */

E 2
I 1
#ifndef lint
D 2
static char sccsid[] = "%W%	(Berkeley)	%G%";
E 2
I 2
static char sccsid[] = "%W% (Berkeley) %G%";
E 2
D 3
#endif not lint
E 3
I 3
#endif /* not lint */
E 3

# include	"trek.h"

/*
**  LONG RANGE OF SCANNERS
**
**	A summary of the quadrants that surround you is printed.  The
**	hundreds digit is the number of Klingons in the quadrant,
**	the tens digit is the number of starbases, and the units digit
**	is the number of stars.  If the printout is "///" it means
**	that that quadrant is rendered uninhabitable by a supernova.
**	It also updates the "scanned" field of the quadrants it scans,
**	for future use by the "chart" option of the computer.
*/

lrscan()
{
	register int			i, j;
	register struct quad		*q;

	if (check_out(LRSCAN))
	{
		return;
	}
	printf("Long range scan for quadrant %d,%d\n\n", Ship.quadx, Ship.quady);

	/* print the header on top */
	for (j = Ship.quady - 1; j <= Ship.quady + 1; j++)
	{
		if (j < 0 || j >= NQUADS)
			printf("      ");
		else
			printf("     %1d", j);
	}

	/* scan the quadrants */
	for (i = Ship.quadx - 1; i <= Ship.quadx + 1; i++)
	{
		printf("\n  -------------------\n");
		if (i < 0 || i >= NQUADS)
		{
			/* negative energy barrier */
			printf("  !  *  !  *  !  *  !");
			continue;
		}

		/* print the left hand margin */
		printf("%1d !", i);
		for (j = Ship.quady - 1; j <= Ship.quady + 1; j++)
		{
			if (j < 0 || j >= NQUADS)
			{
				/* negative energy barrier again */
				printf("  *  !");
				continue;
			}
			q = &Quad[i][j];
			if (q->stars < 0)
			{
				/* supernova */
				printf(" /// !");
				q->scanned = 1000;
				continue;
			}
			q->scanned = q->klings * 100 + q->bases * 10 + q->stars;
			printf(" %3d !", q->scanned);
		}
	}
	printf("\n  -------------------\n");
	return;
}
E 1
