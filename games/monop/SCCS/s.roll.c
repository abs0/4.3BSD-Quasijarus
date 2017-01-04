h01343
s 00011/00006/00047
d D 5.4 88/06/18 14:55:10 bostic 4 3
c install approved copyright notice
e
s 00009/00003/00044
d D 5.3 88/01/02 20:51:30 bostic 3 2
c add Berkeley header
e
s 00001/00001/00046
d D 5.2 87/09/26 19:07:23 bostic 2 1
c roll on tahoe same way roll on vax
e
s 00047/00000/00000
d D 5.1 87/09/26 19:04:45 bostic 1 0
c date and time created 87/09/26 19:04:45 by bostic
e
u
U
t
T
I 1
/*
D 4
 * Copyright (c) 1987 Regents of the University of California.
E 4
I 4
 * Copyright (c) 1980 Regents of the University of California.
E 4
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

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif not lint
E 3
I 3
#endif /* not lint */
E 3

/*
 *	This routine rolls ndie nside-sided dice.
 */

# define	reg	register

D 2
# ifndef vax
E 2
I 2
# if !defined(vax) && !defined(tahoe)
E 2
# define	MAXRAND	32767L

roll(ndie, nsides)
int	ndie, nsides; {

	reg long	tot;
	reg unsigned	n, r;

	tot = 0;
	n = ndie;
	while (n--)
		tot += rand();
	return (int) ((tot * (long) nsides) / ((long) MAXRAND + 1)) + ndie;
}

# else

roll(ndie, nsides)
reg int	ndie, nsides; {

	reg int		tot, r;
	reg double	num_sides;

	num_sides = nsides;
	tot = 0;
	while (ndie--)
		tot += (r = rand()) * (num_sides / 017777777777) + 1;
	return tot;
}
# endif
E 1
