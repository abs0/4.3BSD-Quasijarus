h11089
s 00010/00005/00041
d D 5.3 88/06/18 15:08:27 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00037
d D 5.2 88/05/05 18:34:52 bostic 4 3
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00033
d D 5.1 86/01/29 16:37:22 mckusick 3 2
c add copyright
e
s 00002/00002/00032
d D 4.2 83/05/27 00:34:54 layer 2 1
c finished conversion to 4.1c
e
s 00034/00000/00000
d D 4.1 83/03/23 15:01:49 mckusick 1 0
c date and time created 83/03/23 15:01:49 by mckusick
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
**  RETRIEVE THE STARSYSTEM NAME
**
**	Very straightforward, this routine just gets the starsystem
**	name.  It returns zero if none in the specified quadrant
**	(which, by the way, is passed it).
**
**	This routine knows all about such things as distressed
**	starsystems, etc.
*/

char *systemname(q1)
struct quad	*q1;
{
	register struct quad	*q;
	register int		i;

	q = q1;

D 2
	i = q->systemname;
E 2
I 2
	i = q->qsystemname;
E 2
	if (i & Q_DISTRESSED)
		i = Event[i & Q_SYSTEM].systemname;

D 2
	i =& Q_SYSTEM;
E 2
I 2
	i &= Q_SYSTEM;
E 2
	if (i == 0)
		return (0);
	return (Systemname[i]);
}
E 1
