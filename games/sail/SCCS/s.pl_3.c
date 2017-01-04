h47428
s 00010/00005/00246
d D 5.3 88/06/18 19:55:53 bostic 13 12
c install approved copyright notice
e
s 00009/00003/00242
d D 5.2 88/03/09 12:30:33 bostic 12 11
c written by David Riggle and Edward Wang; add Berkeley specific copyright
e
s 00005/00005/00240
d D 5.1 85/05/29 16:08:51 dist 11 10
c Add copyright
e
s 00006/00000/00239
d D 2.4 85/04/23 21:51:22 edward 10 9
c copyright message
e
s 00019/00036/00220
d D 2.3 83/12/17 12:39:14 edward 9 8
c new grapple and foul data structure.
e
s 00002/00000/00254
d D 2.2 83/12/09 13:31:27 edward 8 7
c turn window bigger, and block alarm when refreshing
e
s 00000/00000/00254
d D 2.1 83/10/31 13:45:45 edward 7 6
c new version
e
s 00001/00000/00253
d D 1.6 83/10/28 22:50:57 edward 6 5
c update display after change
e
s 00000/00055/00253
d D 1.5 83/10/28 19:23:27 edward 5 4
c rearranged player and screen stuff
e
s 00014/00020/00294
d D 1.4 83/10/14 22:44:20 edward 4 3
c tricky input routines
e
s 00008/00006/00306
d D 1.3 83/10/14 20:57:14 edward 3 2
c lookup() bug, and grappling sunk ships.
e
s 00001/00001/00311
d D 1.2 83/10/10 20:11:22 edward 2 1
c got rid of unnecessary variables
e
s 00312/00000/00000
d D 1.1 83/07/20 18:17:37 edward 1 0
c date and time created 83/07/20 18:17:37 by edward
e
u
U
t
T
I 10
/*
D 11
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 11
I 11
 * Copyright (c) 1983 Regents of the University of California.
D 12
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 12
I 12
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 13
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 13
I 13
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
E 13
E 12
E 11
 */

E 10
I 1
#ifndef lint
D 11
static	char *sccsid = "%W% %E%";
#endif
E 11
I 11
static char sccsid[] = "%W% (Berkeley) %G%";
D 12
#endif not lint
E 12
I 12
#endif /* not lint */
E 12
E 11

#include "player.h"

acceptcombat()
{
	int men = 0;
	int target, temp;
	int n, r;
	int index, rakehim, sternrake;
	int hhits = 0, ghits = 0, rhits = 0, chits = 0;
	int crew[3];
	int load;
	int guns, car, ready, shootat, hit;
	int roll;
	struct ship *closest;

	crew[0] = mc->crew1;
	crew[1] = mc->crew2;
	crew[2] = mc->crew3;
	for (n = 0; n < 3; n++) {
		if (mf->OBP[n].turnsent)
			men += mf->OBP[n].mensent;
	}
	for (n = 0; n < 3; n++) {
		if (mf->DBP[n].turnsent)
			men += mf->DBP[n].mensent;
	}
	if (men) {
		crew[0] = men/100 ? 0 : crew[0] != 0;
		crew[1] = (men%100)/10 ? 0 : crew[1] != 0;
		crew[2] = men%10 ? 0 : crew[2] != 0;
	}
	for (r = 0; r < 2; r++) {
		if (r) {
			ready = mf->readyR;
			load = mf->loadR;
			guns = mc->gunR;
			car = mc->carR;
		} else {
			ready = mf->readyL;
			load = mf->loadL;
			guns = mc->gunL;
			car = mc->carL;
		}
		if (!guns && !car || load == L_EMPTY || (ready & R_LOADED) == 0)
			goto cant;
		if (mf->struck || !crew[2])
			goto cant;
		closest = closestenemy(ms, (r ? 'r' : 'l'), 1);
		if (closest == 0)
			goto cant;
		if (closest->file->struck)
			goto cant;
		target = range(ms, closest);
		if (target > rangeofshot[load] || !guns && target >= 3)
			goto cant;
		Signal("%s (%c%c) within range of %s broadside.",
			closest, r ? "right" : "left");
		if (load > L_CHAIN && target < 6) {
D 4
			Signal("Aim for hull or rigging? ", (struct ship *)0);
			switch (sgetch(1)) {
E 4
I 4
			switch (sgetch("Aim for hull or rigging? ",
				(struct ship *)0, 1)) {
E 4
			case 'r':
				shootat = RIGGING;
				break;
			case 'h':
				shootat = HULL;
				break;
			default:
				shootat = -1;
				Signal("'Avast there! Hold your fire.'",
					(struct ship *)0);
			}
		} else {
D 4
			Signal("Fire? ", (struct ship *)0);
			if (sgetch(1) == 'n') {
E 4
I 4
			if (sgetch("Fire? ", (struct ship *)0, 1) == 'n') {
E 4
				shootat = -1;
				Signal("Belay that! Hold your fire.",
					(struct ship *)0);
			} else
				shootat = RIGGING;
		}
		if (shootat == -1)
			continue;
		fired = 1;
		rakehim = gunsbear(ms, closest) && !gunsbear(closest, ms);
		temp = portside(closest, ms, 1) - closest->file->dir + 1;
		if (temp < 1)
			temp += 8;
		else if (temp > 8)
			temp -= 8;
		sternrake = temp > 4 && temp < 6;
		if (rakehim)
			if (!sternrake)
				Signal("Raking the %s!", closest);
			else
				Signal("Stern Rake! %s splintering!", closest);
		index = guns;
		if (target < 3)
			index += car;
		index = (index - 1)/3;
		index = index > 8 ? 8 : index;
		if (!rakehim)
			hit = HDT[index][target-1];
		else
			hit = HDTrake[index][target-1];
		if (rakehim && sternrake)
			hit++;
		hit += QUAL[index][mc->qual-1];
		for (n = 0; n < 3 && mf->captured == 0; n++)
			if (!crew[n])
				if (index <= 5)
					hit--;
				else
					hit -= 2;
		if (ready & R_INITIAL)
			if (index <= 3)
				hit++;
			else
				hit += 2;
		if (mf->captured != 0)
			if (index <= 1)
				hit--;
			else
				hit -= 2;
		hit += AMMO[index][load - 1];
		if (((temp = mc->class) >= 5 || temp == 1) && windspeed == 5)
			hit--;
		if (windspeed == 6 && temp == 4)
			hit -= 2;
		if (windspeed == 6 && temp <= 3)
			hit--;
		if (hit >= 0) {
			roll = die();
			if (load == L_GRAPE)
				chits = hit;
			else {
				struct Tables *t;
				if (hit > 10)
					hit = 10;
				t = &(shootat == RIGGING ? RigTable : HullTable)
					[hit][roll-1];
				chits = t->C;
				rhits = t->R;
				hhits = t->H;
				ghits = t->G;
				if (closest->file->FS)
					rhits *= 2;
				if (load == L_CHAIN) {
					ghits = 0;
					hhits = 0;
				}
			}
			table(shootat, load, hit, closest, ms, roll);
		}
D 4
		Scroll2();
		(void) wprintw(scroll_w, "Damage inflicted on the %s:",
			closest->shipname);
		Scroll();
		(void) wprintw(scroll_w,
			"\t%d HULL, %d GUNS, %d CREW, %d RIGGING",
			hhits, ghits, chits, rhits);
E 4
I 4
		Signal("Damage inflicted on the %s:",
			(struct ship *)0, closest->shipname);
		Signal("\t%d HULL, %d GUNS, %d CREW, %d RIGGING",
			(struct ship *)0, hhits, ghits, chits, rhits);
E 4
		if (!r) {
			mf->loadL = L_EMPTY;
			mf->readyL = R_EMPTY;
		} else {
			mf->loadR = L_EMPTY;
			mf->readyR = R_EMPTY;
		}
		continue;
	cant:
		Signal("Unable to fire %s broadside",
			(struct ship *)0, r ? "right" : "left");
	}
I 8
	blockalarm();
E 8
I 6
	draw_stat();
I 8
	unblockalarm();
E 8
E 6
}

grapungrap()
{
	register struct ship *sp;
D 9
	register int n, k;
	register struct snag *p;
I 3
	int r;
E 9
I 9
	register int i;
E 9
E 3

D 9
	n = -1;
E 9
	foreachship(sp) {
D 9
		n++;
		if (sp == ms)
E 9
I 9
		if (sp == ms || sp->file->dir == 0)
E 9
			continue;
D 3
		if (range(ms, sp) > 1 && !grappled2(ms, sp))
E 3
I 3
D 9
		r = range(ms, sp);
D 4
		if (r < 0 || r > 1 && !grappled2(ms, sp))
E 4
I 4
		if ((r < 0 || r > 1) && !grappled2(ms, sp))
E 9
I 9
		if (range(ms, sp) > 1 && !grappled2(ms, sp))
E 9
E 4
E 3
			continue;
D 4
		Signal("Attempt to grapple or ungrapple %s (%c%c): ", sp);
		switch (sgetch(1)) {
E 4
I 4
		switch (sgetch("Attempt to grapple or ungrapple %s (%c%c): ",
			sp, 1)) {
E 4
		case 'g':
			if (die() < 3
			    || ms->nationality == capship(sp)->nationality) {
D 9
				for (k = 0, p = mf->grapples;
				     k < NSHIP && p->turnfoul; k++, p++)
					;		/* XXX */
				if (k < NSHIP)
					Write(W_GRAP, ms, 0, k, turn, n, 0);
				for (k = 0, p = sp->file->grapples;
				     k < NSHIP && p->turnfoul; k++, p++)
					;		/* XXX */
				if (k < NSHIP)
					Write(W_GRAP, sp, 0,
						k, turn, player, 0);
E 9
I 9
				Write(W_GRAP, ms, 0, sp->file->index, 0, 0, 0);
				Write(W_GRAP, sp, 0, player, 0, 0, 0);
E 9
				Signal("Attempt succeeds!", (struct ship *)0);
				makesignal(ms, "grappled with %s (%c%c)", sp);
			} else
				Signal("Attempt fails.", (struct ship *)0);
			break;
		case 'u':
D 9
			for (k = 0; k < NSHIP; k++) {
				if (!mf->grapples[k].turnfoul)
					continue;
				if (sp != mf->grapples[k].toship)
					continue;
				if (die() < 3 || ms->nationality
				    == capship(sp)->nationality) {
					cleangrapple(ms, sp, k);
E 9
I 9
			for (i = grappled2(ms, sp); --i >= 0;) {
				if (ms->nationality
					== capship(sp)->nationality
				    || die() < 3) {
					cleangrapple(ms, sp, 0);
E 9
					Signal("Attempt succeeds!",
						(struct ship *)0);
					makesignal(ms,
						"ungrappling with %s (%c%c)",
						sp);
				} else
					Signal("Attempt fails.",
						(struct ship *)0);
			}
I 9
			break;
E 9
		}
	}
}

unfoulplayer()
{
D 9
	register struct snag *s = mf->fouls;
E 9
	register struct ship *to;
D 9
	int n;
E 9
I 9
	register i;
E 9

D 9
	for (n = 0; n < NSHIP; n++, s++) {
		if (s->turnfoul == 0)
E 9
I 9
	foreachship(to) {
		if (fouled2(ms, to) == 0)
E 9
			continue;
D 9
		to = s->toship;
D 4
		Signal("Attempt to unfoul with the %s (%c%c)? ", to);
		if (sgetch(1) == 'y') {
E 4
I 4
		if (sgetch("Attempt to unfoul with the %s (%c%c)? ", to, 1)
		    == 'y') {
E 4
			if (die() < 3) {
				cleanfoul(ms, to, n);
E 9
I 9
		if (sgetch("Attempt to unfoul with the %s (%c%c)? ", to, 1) != 'y')
			continue;
		for (i = fouled2(ms, to); --i >= 0;) {
			if (die() <= 2) {
				cleanfoul(ms, to, 0);
E 9
D 4
				Signal("Attempt succeeds!",
					(struct ship *)0);
E 4
I 4
				Signal("Attempt succeeds!", (struct ship *)0);
E 4
				makesignal(ms, "Unfouling %s (%c%c)", to);
			} else
				Signal("Attempt fails.", (struct ship *)0);
		}
	}
}
D 5

lookout()
{
	register struct ship *sp;
	char buf[3];
	register char c;

D 4
	Signal("What ship? ", (struct ship *)0);
	sgetstr(buf, sizeof buf);
E 4
I 4
	sgetstr("What ship? ", buf, sizeof buf);
E 4
	foreachship(sp) {
		c = *countryname[sp->nationality];
		if ((c == *buf || tolower(c) == *buf || colours(sp) == *buf)
		    && (sp->file->stern == buf[1] || sterncolour(sp) == buf[1]))
D 3
			break;
E 3
I 3
		{
			eyeball(sp);
			return;
		}
E 3
	}
D 3
	if (sp)
		eyeball(sp);
	else
		Signal("No such ship.", (struct ship *)0);
E 3
I 3
	Signal("No such ship.", (struct ship *)0);
E 3
}

char *
saywhat(sp, flag)
register struct ship *sp;
char flag;
{
	if (sp->file->captain[0])
		return sp->file->captain;
	else if (sp->file->struck)
		return "(struck)";
	else if (sp->file->captured != 0)
		return "(captured)";
	else if (flag)
		return "(available)";
	else
		return "(computer)";
}

eyeball(ship)
register struct ship *ship;
{
	int i;

	if (ship == 0)
		Signal("No more ships left.", (struct ship *)0);
D 2
	else if (ship->shipdir) {
E 2
I 2
	else if (ship->file->dir != 0) {
E 2
		Signal("Sail ho! (range %d, %s)",
			(struct ship *)0, range(ms, ship), saywhat(ship, 0));
		i = portside(ms, ship, 1) - mf->dir;
		if (i <= 0)
			i += 8;
		Signal("%s (%c%c) %s %s %s.",
			ship, countryname[ship->nationality],
			classname[ship->specs->class], directionname[i]);
	}
}
E 5
E 1
