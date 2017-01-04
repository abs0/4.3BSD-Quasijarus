h01303
s 00010/00005/00437
d D 5.3 88/06/18 15:07:32 bostic 6 5
c install approved copyright notice
e
s 00009/00003/00433
d D 5.2 88/05/05 18:33:46 bostic 5 4
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00429
d D 5.1 85/05/30 08:53:08 dist 4 3
c Add copyright
e
s 00001/00001/00429
d D 4.3 84/03/28 18:35:39 mckusick 3 2
c value instead of var reference to `bmove'
e
s 00023/00023/00407
d D 4.2 83/05/27 00:33:38 layer 2 1
c finished conversion to 4.1c
e
s 00430/00000/00000
d D 4.1 83/03/23 14:59:19 mckusick 1 0
c date and time created 83/03/23 14:59:19 by mckusick
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
**  CAUSE TIME TO ELAPSE
**
**	This routine does a hell of a lot.  It elapses time, eats up
**	energy, regenerates energy, processes any events that occur,
**	and so on.
*/


events(warp)
int	warp;		/* set if called in a time warp */
{
	register int		i;
	int			j;
	struct kling		*k;
	double			rtime;
	double			xdate;
	double			idate;
D 2
	struct event		*ev;
E 2
I 2
	struct event		*ev, *xsched(), *schedule();
E 2
	int			ix, iy;
	register struct quad	*q;
	register struct event	*e;
	int			evnum;
	int			restcancel;

	/* if nothing happened, just allow for any Klingons killed */
	if (Move.time <= 0.0)
	{
		Now.time = Now.resource / Now.klings;
		return (0);
	}

	/* indicate that the cloaking device is now working */
	Ship.cloakgood = 1;

	/* idate is the initial date */
	idate = Now.date;

	/* schedule attacks if resting too long */
	if (Move.time > 0.5 && Move.resting)
		schedule(E_ATTACK, 0.5, 0, 0, 0);

	/* scan the event list */
	while (1)
	{
		restcancel = 0;
		evnum = -1;
		/* xdate is the date of the current event */
		xdate = idate + Move.time;

		/* find the first event that has happened */
		for (i = 0; i < MAXEVENTS; i++)
		{
			e = &Event[i];
			if (e->evcode == 0 || (e->evcode & E_GHOST))
				continue;
			if (e->date < xdate)
			{
				xdate = e->date;
				ev = e;
				evnum = i;
			}
		}
		e = ev;

		/* find the time between events */
		rtime = xdate - Now.date;

		/* decrement the magic "Federation Resources" pseudo-variable */
D 2
		Now.resource =- Now.klings * rtime;
E 2
I 2
		Now.resource -= Now.klings * rtime;
E 2
		/* and recompute the time left */
		Now.time = Now.resource / Now.klings;

		/* move us up to the next date */
		Now.date = xdate;

		/* check for out of time */
		if (Now.time <= 0.0)
			lose(L_NOTIME);
#		ifdef xTRACE
		if (evnum >= 0 && Trace)
			printf("xdate = %.2f, evcode %d params %d %d %d\n",
				xdate, e->evcode, e->x, e->y, e->systemname);
#		endif

		/* if evnum < 0, no events occurred  */
		if (evnum < 0)
			break;

		/* otherwise one did.  Find out what it is */
		switch (e->evcode & E_EVENT)
		{

		  case E_SNOVA:			/* supernova */
			/* cause the supernova to happen */
			snova(-1);
			/* and schedule the next one */
			xresched(e, E_SNOVA, 1);
			break;

		  case E_LRTB:			/* long range tractor beam */
			/* schedule the next one */
			xresched(e, E_LRTB, Now.klings);
			/* LRTB cannot occur if we are docked */
			if (Ship.cond != DOCKED)
			{
				/* pick a new quadrant */
				i = ranf(Now.klings) + 1;
				for (ix = 0; ix < NQUADS; ix++)
				{
					for (iy = 0; iy < NQUADS; iy++)
					{
						q = &Quad[ix][iy];
						if (q->stars >= 0)
D 2
							if ((i =- q->klings) <= 0)
E 2
I 2
							if ((i -= q->klings) <= 0)
E 2
								break;
					}
					if (i <= 0)
						break;
				}

				/* test for LRTB to same quadrant */
				if (Ship.quadx == ix && Ship.quady == iy)
					break;

				/* nope, dump him in the new quadrant */
				Ship.quadx = ix;
				Ship.quady = iy;
				printf("\n%s caught in long range tractor beam\n", Ship.shipname);
				printf("*** Pulled to quadrant %d,%d\n", Ship.quadx, Ship.quady);
				Ship.sectx = ranf(NSECTS);
				Ship.secty = ranf(NSECTS);
				initquad(0);
				/* truncate the move time */
				Move.time = xdate - idate;
			}
			break;

		  case E_KATSB:			/* Klingon attacks starbase */
			/* if out of bases, forget it */
			if (Now.bases <= 0)
			{
				unschedule(e);
				break;
			}

			/* check for starbase and Klingons in same quadrant */
			for (i = 0; i < Now.bases; i++)
			{
				ix = Now.base[i].x;
				iy = Now.base[i].y;
				/* see if a Klingon exists in this quadrant */
				q = &Quad[ix][iy];
				if (q->klings <= 0)
					continue;

				/* see if already distressed */
				for (j = 0; j < MAXEVENTS; j++)
				{
					e = &Event[j];
					if ((e->evcode & E_EVENT) != E_KDESB)
						continue;
					if (e->x == ix && e->y == iy)
						break;
				}
				if (j < MAXEVENTS)
					continue;

				/* got a potential attack */
				break;
			}
			e = ev;
			if (i >= Now.bases)
			{
				/* not now; wait a while and see if some Klingons move in */
				reschedule(e, 0.5 + 3.0 * franf());
				break;
			}
			/* schedule a new attack, and a destruction of the base */
			xresched(e, E_KATSB, 1);
			e = xsched(E_KDESB, 1, ix, iy, 0);

			/* report it if we can */
			if (!damaged(SSRADIO))
			{
				printf("\nUhura:  Captain, we have recieved a distress signal\n");
				printf("  from the starbase in quadrant %d,%d.\n",
					ix, iy);
				restcancel++;
			}
			else
				/* SSRADIO out, make it so we can't see the distress call */
				/* but it's still there!!! */
D 2
				e->evcode =| E_HIDDEN;
E 2
I 2
				e->evcode |= E_HIDDEN;
E 2
			break;

		  case E_KDESB:			/* Klingon destroys starbase */
			unschedule(e);
			q = &Quad[e->x][e->y];
			/* if the base has mysteriously gone away, or if the Klingon
			   got tired and went home, ignore this event */
			if (q->bases <=0 || q->klings <= 0)
				break;
			/* are we in the same quadrant? */
			if (e->x == Ship.quadx && e->y == Ship.quady)
			{
				/* yep, kill one in this quadrant */
				printf("\nSpock: ");
				killb(Ship.quadx, Ship.quady);
			}
			else
				/* kill one in some other quadrant */
				killb(e->x, e->y);
			break;

		  case E_ISSUE:		/* issue a distress call */
			xresched(e, E_ISSUE, 1);
			/* if we already have too many, throw this one away */
			if (Ship.distressed >= MAXDISTR)
				break;
			/* try a whole bunch of times to find something suitable */
			for (i = 0; i < 100; i++)
			{
				ix = ranf(NQUADS);
				iy = ranf(NQUADS);
				q = &Quad[ix][iy];
				/* need a quadrant which is not the current one,
				   which has some stars which are inhabited and
				   not already under attack, which is not
				   supernova'ed, and which has some Klingons in it */
				if (!((ix == Ship.quadx && iy == Ship.quady) || q->stars < 0 ||
D 2
				    (q->systemname & Q_DISTRESSED) ||
				    (q->systemname & Q_SYSTEM) == 0 || q->klings <= 0))
E 2
I 2
				    (q->qsystemname & Q_DISTRESSED) ||
				    (q->qsystemname & Q_SYSTEM) == 0 || q->klings <= 0))
E 2
					break;
			}
			if (i >= 100)
				/* can't seem to find one; ignore this call */
				break;

			/* got one!!  Schedule its enslavement */
D 2
			Ship.distressed =+ 1;
			e = xsched(E_ENSLV, 1, ix, iy, q->systemname);
			q->systemname = (e - Event) | Q_DISTRESSED;
E 2
I 2
			Ship.distressed++;
			e = xsched(E_ENSLV, 1, ix, iy, q->qsystemname);
			q->qsystemname = (e - Event) | Q_DISTRESSED;
E 2

			/* tell the captain about it if we can */
			if (!damaged(SSRADIO))
			{
				printf("\nUhura: Captain, starsystem %s in quadrant %d,%d is under attack\n",
					Systemname[e->systemname], ix, iy);
				restcancel++;
			}
			else
				/* if we can't tell him, make it invisible */
D 2
				e->evcode =| E_HIDDEN;
E 2
I 2
				e->evcode |= E_HIDDEN;
E 2
			break;

		  case E_ENSLV:		/* starsystem is enslaved */
			unschedule(e);
			/* see if current distress call still active */
			q = &Quad[e->x][e->y];
			if (q->klings <= 0)
			{
				/* no Klingons, clean up */
				/* restore the system name */
D 2
				q->systemname = e->systemname;
E 2
I 2
				q->qsystemname = e->systemname;
E 2
				break;
			}

			/* play stork and schedule the first baby */
			e = schedule(E_REPRO, Param.eventdly[E_REPRO] * franf(), e->x, e->y, e->systemname);

			/* report the disaster if we can */
			if (!damaged(SSRADIO))
			{
				printf("\nUhura:  We've lost contact with starsystem %s\n",
					Systemname[e->systemname]);
				printf("  in quadrant %d,%d.\n",
					e->x, e->y);
			}
			else
D 2
				e->evcode =| E_HIDDEN;
E 2
I 2
				e->evcode |= E_HIDDEN;
E 2
			break;

		  case E_REPRO:		/* Klingon reproduces */
			/* see if distress call is still active */
			q = &Quad[e->x][e->y];
			if (q->klings <= 0)
			{
				unschedule(e);
D 2
				q->systemname = e->systemname;
E 2
I 2
				q->qsystemname = e->systemname;
E 2
				break;
			}
			xresched(e, E_REPRO, 1);
			/* reproduce one Klingon */
			ix = e->x;
			iy = e->y;
			if (Now.klings == 127)
				break;		/* full right now */
			if (q->klings >= MAXKLQUAD)
			{
				/* this quadrant not ok, pick an adjacent one */
				for (i = ix - 1; i <= ix + 1; i++)
				{
					if (i < 0 || i >= NQUADS)
						continue;
					for (j = iy - 1; j <= iy + 1; j++)
					{
						if (j < 0 || j >= NQUADS)
							continue;
						q = &Quad[i][j];
						/* check for this quad ok (not full & no snova) */
						if (q->klings >= MAXKLQUAD || q->stars < 0)
							continue;
						break;
					}
					if (j <= iy + 1)
						break;
				}
				if (j > iy + 1)
					/* cannot create another yet */
					break;
				ix = i;
				iy = j;
			}
			/* deliver the child */
D 2
			q->klings =+ 1;
			Now.klings =+ 1;
E 2
I 2
			q->klings++;
			Now.klings++;
E 2
			if (ix == Ship.quadx && iy == Ship.quady)
			{
				/* we must position Klingon */
				sector(&ix, &iy);
				Sect[ix][iy] = KLINGON;
				k = &Etc.klingon[Etc.nkling++];
				k->x = ix;
				k->y = iy;
				k->power = Param.klingpwr;
				k->srndreq = 0;
				compkldist(Etc.klingon[0].dist == Etc.klingon[0].avgdist ? 0 : 1);
			}

			/* recompute time left */
			Now.time = Now.resource / Now.klings;
			break;

		  case E_SNAP:		/* take a snapshot of the galaxy */
			xresched(e, E_SNAP, 1);
D 2
			i = Etc.snapshot;
			i = bmove(&Quad, i, sizeof Quad);
			i = bmove(&Event, i, sizeof Event);
			i = bmove(&Now, i, sizeof Now);
E 2
I 2
			i = (int) Etc.snapshot;
			i = bmove(Quad, i, sizeof (Quad));
			i = bmove(Event, i, sizeof (Event));
D 3
			i = bmove(Now, i, sizeof (Now));
E 3
I 3
			i = bmove(&Now, i, sizeof (Now));
E 3
E 2
			Game.snap = 1;
			break;

		  case E_ATTACK:	/* Klingons attack during rest period */
			if (!Move.resting)
			{
				unschedule(e);
				break;
			}
			attack(1);
			reschedule(e, 0.5);
			break;

		  case E_FIXDV:
			i = e->systemname;
			unschedule(e);

			/* de-damage the device */
			printf("%s reports repair work on the %s finished.\n",
				Device[i].person, Device[i].name);

			/* handle special processing upon fix */
			switch (i)
			{

			  case LIFESUP:
				Ship.reserves = Param.reserves;
				break;

			  case SINS:
				if (Ship.cond == DOCKED)
					break;
				printf("Spock has tried to recalibrate your Space Internal Navigation System,\n");
				printf("  but he has no standard base to calibrate to.  Suggest you get\n");
				printf("  to a starbase immediately so that you can properly recalibrate.\n");
				Ship.sinsbad = 1;
				break;

			  case SSRADIO:
				restcancel = dumpssradio();
				break;
			}
			break;

		  default:
			break;
		}

		if (restcancel && Move.resting && getynpar("Spock: Shall we cancel our rest period"))
			Move.time = xdate - idate;

	}

	/* unschedule an attack during a rest period */
	if (e = Now.eventptr[E_ATTACK])
		unschedule(e);

	if (!warp)
	{
		/* eat up energy if cloaked */
		if (Ship.cloaked)
D 2
			Ship.energy =- Param.cloakenergy * Move.time;
E 2
I 2
			Ship.energy -= Param.cloakenergy * Move.time;
E 2

		/* regenerate resources */
		rtime = 1.0 - exp(-Param.regenfac * Move.time);
D 2
		Ship.shield =+ (Param.shield - Ship.shield) * rtime;
		Ship.energy =+ (Param.energy - Ship.energy) * rtime;
E 2
I 2
		Ship.shield += (Param.shield - Ship.shield) * rtime;
		Ship.energy += (Param.energy - Ship.energy) * rtime;
E 2

		/* decrement life support reserves */
		if (damaged(LIFESUP) && Ship.cond != DOCKED)
D 2
			Ship.reserves =- Move.time;
E 2
I 2
			Ship.reserves -= Move.time;
E 2
	}
	return (0);
}
E 1
