h21130
s 00010/00005/00147
d D 5.3 88/06/18 15:08:13 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00143
d D 5.2 88/05/05 18:34:36 bostic 4 3
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00139
d D 5.1 85/05/30 09:02:50 dist 3 2
c Add copyright
e
s 00004/00004/00136
d D 4.2 83/05/27 00:34:42 layer 2 1
c finished conversion to 4.1c
e
s 00140/00000/00000
d D 4.1 83/03/23 15:01:09 mckusick 1 0
c date and time created 83/03/23 15:01:09 by mckusick
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
**  SCHEDULE AN EVENT
**
**	An event of type 'type' is scheduled for time NOW + 'offset'
**	into the first available slot.  'x', 'y', and 'z' are
**	considered the attributes for this event.
**
**	The address of the slot is returned.
*/

struct event *schedule(type, offset, x, y, z)
int	type;
D 2
float	offset;
E 2
I 2
double	offset;
E 2
char	x, y;
char	z;
{
	register struct event	*e;
	register int		i;
D 2
	float			date;
E 2
I 2
	double			date;
E 2

	date = Now.date + offset;
	for (i = 0; i < MAXEVENTS; i++)
	{
		e = &Event[i];
		if (e->evcode)
			continue;
		/* got a slot */
#		ifdef xTRACE
		if (Trace)
			printf("schedule: type %d @ %.2f slot %d parm %d %d %d\n",
				type, date, i, x, y, z);
#		endif
		e->evcode = type;
		e->date = date;
		e->x = x;
		e->y = y;
		e->systemname = z;
		Now.eventptr[type] = e;
		return (e);
	}
	syserr("Cannot schedule event %d parm %d %d %d", type, x, y, z);
}


/*
**  RESCHEDULE AN EVENT
**
**	The event pointed to by 'e' is rescheduled to the current
**	time plus 'offset'.
*/

reschedule(e1, offset)
struct event	*e1;
D 2
float		offset;
E 2
I 2
double		offset;
E 2
{
D 2
	float			date;
E 2
I 2
	double			date;
E 2
	register struct event	*e;

	e = e1;

	date = Now.date + offset;
	e->date = date;
#	ifdef xTRACE
	if (Trace)
		printf("reschedule: type %d parm %d %d %d @ %.2f\n",
			e->evcode, e->x, e->y, e->systemname, date);
#	endif
	return;
}


/*
**  UNSCHEDULE AN EVENT
**
**	The event at slot 'e' is deleted.
*/

unschedule(e1)
struct event	*e1;
{
	register struct event	*e;

	e = e1;

#	ifdef xTRACE
	if (Trace)
		printf("unschedule: type %d @ %.2f parm %d %d %d\n",
			e->evcode, e->date, e->x, e->y, e->systemname);
#	endif
	Now.eventptr[e->evcode & E_EVENT] = 0;
	e->date = 1e50;
	e->evcode = 0;
	return;
}


/*
**  Abreviated schedule routine
**
**	Parameters are the event index and a factor for the time
**	figure.
*/

struct event *xsched(ev1, factor, x, y, z)
int	ev1;
int	factor;
int	x, y, z;
{
	register int	ev;

	ev = ev1;
	return (schedule(ev, -Param.eventdly[ev] * Param.time * log(franf()) / factor, x, y, z));
}


/*
**  Simplified reschedule routine
**
**	Parameters are the event index, the initial date, and the
**	division factor.  Look at the code to see what really happens.
*/

xresched(e1, ev1, factor)
struct event	*e1;
int		ev1;
int		factor;
{
	register int		ev;
	register struct event	*e;

	ev = ev1;
	e = e1;
	reschedule(e, -Param.eventdly[ev] * Param.time * log(franf()) / factor);
}
E 1
