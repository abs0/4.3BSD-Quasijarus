h42654
s 00010/00005/00031
d D 5.3 88/06/18 15:08:09 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00027
d D 5.2 88/05/05 18:34:33 bostic 4 3
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00023
d D 5.1 85/05/30 09:02:07 dist 3 2
c Add copyright
e
s 00002/00000/00022
d D 4.2 83/05/27 00:34:36 layer 2 1
c finished conversion to 4.1c
e
s 00022/00000/00000
d D 4.1 83/03/23 15:00:57 mckusick 1 0
c date and time created 83/03/23 15:00:57 by mckusick
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

I 2
# include	<stdio.h>

E 2
ranf(max)
int	max;
{
	register int	t;

	if (max <= 0)
		return (0);
	t = rand() >> 5;
	return (t % max);
}


double franf()
{
	double		t;
	t = rand() & 077777;
	return (t / 32767.0);
}
E 1
