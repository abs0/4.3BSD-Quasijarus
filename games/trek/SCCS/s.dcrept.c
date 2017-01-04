h07112
s 00010/00005/00073
d D 5.3 88/06/18 15:07:22 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00069
d D 5.2 88/05/05 18:33:32 bostic 4 3
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00065
d D 5.1 85/05/30 08:51:24 dist 3 2
c Add copyright
e
s 00002/00002/00064
d D 4.2 83/05/27 00:33:30 layer 2 1
c finished conversion to 4.1c
e
s 00066/00000/00000
d D 4.1 83/03/23 14:58:49 mckusick 1 0
c date and time created 83/03/23 14:58:49 by mckusick
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
**  damage control report
**
**	Print damages and time to fix.  This is taken from the event
**	list.  A couple of factors are set up, based on whether or not
**	we are docked.  (One of these factors will always be 1.0.)
**	The event list is then scanned for damage fix events, the
**	time until they occur is determined, and printed out.  The
**	magic number DAMFAC is used to tell how much faster you can
**	fix things if you are docked.
*/

dcrept()
{
	register int		i, f;
D 2
	float			x;
	float			m1, m2;
E 2
I 2
	double			x;
	double			m1, m2;
E 2
	register struct event	*e;

	/* set up the magic factors to output the time till fixed */
	if (Ship.cond == DOCKED)
	{
		m1 = 1.0 / Param.dockfac;
		m2 = 1.0;
	}
	else
	{
		m1 = 1.0;
		m2 = Param.dockfac;
	}
	printf("Damage control report:\n");
	f = 1;

	/* scan for damages */
	for (i = 0; i < MAXEVENTS; i++)
	{
		e = &Event[i];
		if (e->evcode != E_FIXDV)
			continue;

		/* output the title first time */
		if (f)
		{
			printf("\t\t\t  repair times\n");
			printf("device\t\t\tin flight  docked\n");
			f = 0;
		}

		/* compute time till fixed, then adjust by the magic factors */
		x = e->date - Now.date;
		printf("%-24s%7.2f  %7.2f\n",
			Device[e->systemname].name, x * m1 + 0.005, x * m2 + 0.005);

		/* do a little consistancy checking */
	}

	/* if everything was ok, reassure the nervous captain */
	if (f)
		printf("All devices functional\n");
}
E 1
