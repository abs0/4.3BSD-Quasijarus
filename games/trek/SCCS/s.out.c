h42830
s 00010/00005/00030
d D 5.3 88/06/18 15:08:01 bostic 4 3
c install approved copyright notice
e
s 00009/00003/00026
d D 5.2 88/05/05 18:34:23 bostic 3 2
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00022
d D 5.1 85/05/30 09:01:03 dist 2 1
c Add copyright
e
s 00023/00000/00000
d D 4.1 83/03/23 15:00:36 mckusick 1 0
c date and time created 83/03/23 15:00:36 by mckusick
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
**  Announce Device Out
*/

out(dev)
int	dev;
{
	register struct device	*d;

	d = &Device[dev];
	printf("%s reports %s ", d->person, d->name);
	if (d->name[length(d->name) - 1] == 's')
		printf("are");
	else
		printf("is");
	printf(" damaged\n");
}
E 1
