h21008
s 00010/00005/00201
d D 5.3 88/06/18 15:07:48 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00197
d D 5.2 88/05/05 18:34:06 bostic 4 3
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00193
d D 5.1 86/01/29 16:36:07 mckusick 3 2
c add copyright
e
s 00015/00014/00179
d D 4.2 83/05/27 00:34:05 layer 2 1
c finished conversion to 4.1c
e
s 00193/00000/00000
d D 4.1 83/03/23 14:59:58 mckusick 1 0
c date and time created 83/03/23 14:59:58 by mckusick
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
**  KILL KILL KILL !!!
**
**	This file handles the killing off of almost anything.
*/

/*
**  Handle a Klingon's death
**
**	The Klingon at the sector given by the parameters is killed
**	and removed from the Klingon list.  Notice that it is not
**	removed from the event list; this is done later, when the
**	the event is to be caught.  Also, the time left is recomputed,
**	and the game is won if that was the last klingon.
*/

killk(ix, iy)
int	ix, iy;
{
	register int		i, j;

	printf("   *** Klingon at %d,%d destroyed ***\n", ix, iy);

	/* remove the scoundrel */
D 2
	Now.klings =- 1;
E 2
I 2
	Now.klings -= 1;
E 2
	Sect[ix][iy] = EMPTY;
D 2
	Quad[Ship.quadx][Ship.quady].klings =- 1;
E 2
I 2
	Quad[Ship.quadx][Ship.quady].klings -= 1;
E 2
	/* %%% IS THIS SAFE???? %%% */
D 2
	Quad[Ship.quadx][Ship.quady].scanned =- 100;
	Game.killk =+ 1;
E 2
I 2
	Quad[Ship.quadx][Ship.quady].scanned -= 100;
	Game.killk += 1;
E 2

	/* find the Klingon in the Klingon list */
	for (i = 0; i < Etc.nkling; i++)
		if (ix == Etc.klingon[i].x && iy == Etc.klingon[i].y)
		{
			/* purge him from the list */
D 2
			Etc.nkling =- 1;
E 2
I 2
			Etc.nkling -= 1;
E 2
			for (; i < Etc.nkling; i++)
				bmove(&Etc.klingon[i+1], &Etc.klingon[i], sizeof Etc.klingon[i]);
			break;
		}

	/* find out if that was the last one */
	if (Now.klings <= 0)
		win();

	/* recompute time left */
	Now.time = Now.resource / Now.klings;
	return;
}


/*
**  handle a starbase's death
*/

killb(qx, qy)
int	qx, qy;
{
	register struct quad	*q;
	register struct xy	*b;

	q = &Quad[qx][qy];

	if (q->bases <= 0)
		return;
	if (!damaged(SSRADIO))
		/* then update starchart */
		if (q->scanned < 1000)
D 2
			q->scanned =- 10;
E 2
I 2
			q->scanned -= 10;
E 2
		else
			if (q->scanned > 1000)
				q->scanned = -1;
	q->bases = 0;
D 2
	Now.bases =- 1;
E 2
I 2
	Now.bases -= 1;
E 2
	for (b = Now.base; ; b++)
		if (qx == b->x && qy == b->y)
			break;
	bmove(&Now.base[Now.bases], b, sizeof *b);
	if (qx == Ship.quadx && qy == Ship.quady)
	{
		Sect[Etc.starbase.x][Etc.starbase.y] = EMPTY;
		if (Ship.cond == DOCKED)
			undock();
		printf("Starbase at %d,%d destroyed\n", Etc.starbase.x, Etc.starbase.y);
	}
	else
	{
		if (!damaged(SSRADIO))
		{
			printf("Uhura: Starfleet command reports that the starbase in\n");
			printf("   quadrant %d,%d has been destroyed\n", qx, qy);
		}
		else
			schedule(E_KATSB | E_GHOST, 1e50, qx, qy, 0);
	}
}


/**
 **	kill an inhabited starsystem
 **/

kills(x, y, f)
int	x, y;	/* quad coords if f == 0, else sector coords */
int	f;	/* f != 0 -- this quad;  f < 0 -- Enterprise's fault */
{
	register struct quad	*q;
	register struct event	*e;
	register char		*name;
I 2
	char			*systemname();
E 2

	if (f)
	{
		/* current quadrant */
		q = &Quad[Ship.quadx][Ship.quady];
		Sect[x][y] = EMPTY;
		name = systemname(q);
		if (name == 0)
			return;
		printf("Inhabited starsystem %s at %d,%d destroyed\n",
			name, x, y);
		if (f < 0)
D 2
			Game.killinhab =+ 1;
E 2
I 2
			Game.killinhab += 1;
E 2
	}
	else
	{
		/* different quadrant */
		q = &Quad[x][y];
	}
D 2
	if (q->systemname & Q_DISTRESSED)
E 2
I 2
	if (q->qsystemname & Q_DISTRESSED)
E 2
	{
		/* distressed starsystem */
D 2
		e = &Event[q->systemname & Q_SYSTEM];
E 2
I 2
		e = &Event[q->qsystemname & Q_SYSTEM];
E 2
		printf("Distress call for %s invalidated\n",
			Systemname[e->systemname]);
		unschedule(e);
	}
D 2
	q->systemname = 0;
	q->stars =- 1;
E 2
I 2
	q->qsystemname = 0;
	q->stars -= 1;
E 2
}


/**
 **	"kill" a distress call
 **/

killd(x, y, f)
int	x, y;		/* quadrant coordinates */
int	f;		/* set if user is to be informed */
{
	register struct event	*e;
	register int		i;
	register struct quad	*q;

	q = &Quad[x][y];
	for (i = 0; i < MAXEVENTS; i++)
	{
		e = &Event[i];
		if (e->x != x || e->y != y)
			continue;
		switch (e->evcode)
		{
		  case E_KDESB:
			if (f)
			{
				printf("Distress call for starbase in %d,%d nullified\n",
					x, y);
				unschedule(e);
			}
			break;

		  case E_ENSLV:
		  case E_REPRO:
			if (f)
			{
				printf("Distress call for %s in quadrant %d,%d nullified\n",
					Systemname[e->systemname], x, y);
D 2
				q->systemname = e->systemname;
E 2
I 2
				q->qsystemname = e->systemname;
E 2
				unschedule(e);
			}
			else
			{
D 2
				e->evcode =| E_GHOST;
E 2
I 2
				e->evcode |= E_GHOST;
E 2
			}
		}
	}
}
E 1
