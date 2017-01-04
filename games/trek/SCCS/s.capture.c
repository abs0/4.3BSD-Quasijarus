h00085
s 00010/00005/00102
d D 5.3 88/06/18 15:07:08 bostic 6 5
c install approved copyright notice
e
s 00009/00003/00098
d D 5.2 88/05/05 18:33:13 bostic 5 4
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00094
d D 5.1 85/05/30 08:48:45 dist 4 3
c Add copyright
e
s 00003/00003/00092
d D 4.3 83/05/27 00:33:11 layer 3 2
c finished conversion to 4.1c
e
s 00004/00004/00091
d D 4.2 83/05/09 21:54:09 layer 2 1
c conversion of source code to 4.1c BSD
e
s 00095/00000/00000
d D 4.1 83/03/23 14:58:14 mckusick 1 0
c date and time created 83/03/23 14:58:14 by mckusick
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
**  Ask a Klingon To Surrender
**
**	(Fat chance)
**
**	The Subspace Radio is needed to ask a Klingon if he will kindly
**	surrender.  A random Klingon from the ones in the quadrant is
**	chosen.
**
**	The Klingon is requested to surrender.  The probability of this
**	is a function of that Klingon's remaining power, our power,
**	etc.
*/

capture()
{
	register int		i;
	register struct kling	*k;
D 3
	float			x;
E 3
I 3
	double			x;
E 3
	extern struct kling	*selectklingon();

	/* check for not cloaked */
	if (Ship.cloaked)
	{
		printf("Ship-ship communications out when cloaked\n");
		return;
	}
	if (damaged(SSRADIO))
		return (out(SSRADIO));
	/* find out if there are any at all */
	if (Etc.nkling <= 0)
	{
		printf("Uhura: Getting no response, sir\n");
		return;
	}

	/* if there is more than one Klingon, find out which one */
	k = selectklingon();
	Move.free = 0;
	Move.time = 0.05;

	/* check out that Klingon */
	k->srndreq++;
	x = Param.klingpwr;
D 2
	x =* Ship.energy;
	x =/ k->power * Etc.nkling;
	x =* Param.srndrprob;
E 2
I 2
	x *= Ship.energy;
	x /= k->power * Etc.nkling;
	x *= Param.srndrprob;
E 2
	i = x;
#	ifdef xTRACE
	if (Trace)
		printf("Prob = %d (%.4f)\n", i, x);
#	endif
	if (i > ranf(100))
	{
		/* guess what, he surrendered!!! */
		printf("Klingon at %d,%d surrenders\n", k->x, k->y);
		i = ranf(Param.klingcrew);
D 3
		printf("%d klingons commit suicide rather than be taken captive\n",
			Param.klingcrew - i);
E 3
I 3
		if ( i > 0 )
			printf("%d klingons commit suicide rather than be taken captive\n", Param.klingcrew - i);
E 3
		if (i > Ship.brigfree)
			i = Ship.brigfree;
D 2
		Ship.brigfree =- i;
E 2
I 2
		Ship.brigfree -= i;
E 2
		printf("%d captives taken\n", i);
		killk(k->x, k->y);
		return;
	}

	/* big surprise, he refuses to surrender */
	printf("Fat chance, captain\n");
	return;
}


/*
**  SELECT A KLINGON
**
**	Cruddy, just takes one at random.  Should ask the captain.
*/

struct kling	*selectklingon()
{
	register int		i;

	if (Etc.nkling < 2)
		i = 0;
	else
		i = ranf(Etc.nkling);
	return (&Etc.klingon[i]);
}
E 1
