h04316
s 00010/00005/00170
d D 5.3 88/06/18 19:55:58 bostic 9 8
c install approved copyright notice
e
s 00009/00003/00166
d D 5.2 88/03/09 12:30:39 bostic 8 7
c written by David Riggle and Edward Wang; add Berkeley specific copyright
e
s 00005/00005/00164
d D 5.1 85/05/29 16:10:01 dist 7 6
c Add copyright
e
s 00006/00000/00163
d D 2.4 85/04/23 21:52:49 edward 6 5
c copyright message
e
s 00047/00033/00116
d D 2.3 84/02/23 16:02:57 edward 5 4
c Repair algorithm fixed.
e
s 00004/00000/00145
d D 2.2 83/12/09 13:31:56 edward 4 3
c turn window bigger, and block alarm when refreshing
e
s 00000/00000/00145
d D 2.1 83/10/31 13:46:31 edward 3 2
c new version
e
s 00007/00002/00138
d D 1.2 83/10/28 22:51:24 edward 2 1
c update display after change
e
s 00140/00000/00000
d D 1.1 83/10/28 19:24:36 edward 1 0
c date and time created 83/10/28 19:24:36 by edward
e
u
U
t
T
I 6
/*
D 7
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 7
I 7
 * Copyright (c) 1983 Regents of the University of California.
D 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
I 8
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
E 8
E 7
 */

E 6
I 1
#ifndef lint
D 7
static	char *sccsid = "%W% %E%";
#endif
E 7
I 7
static char sccsid[] = "%W% (Berkeley) %G%";
D 8
#endif not lint
E 8
I 8
#endif /* not lint */
E 8
E 7

#include "player.h"

repair()
{
	char c;
D 5
	char *repairs;
	struct shipspecs *ptr;
E 5
I 5
	register char *repairs;
	register struct shipspecs *ptr = mc;
	register int count;
E 5

I 5
#define FIX(x, m) (m - ptr->x > count \
	? (ptr->x += count, count = 0) : (count -= m - ptr->x, ptr->x = m))

E 5
	if (repaired || loaded || fired || changed || turned()) {
		Signal("No hands free to repair", (struct ship *)0);
		return;
	}
D 5
	ptr = mc;
E 5
	c = sgetch("Repair (hull, guns, rigging)? ", (struct ship *)0, 1);
	switch (c) {
		case 'h':
			repairs = &mf->RH;
			break;
		case 'g':
			repairs = &mf->RG;
			break;
		case 'r':
			repairs = &mf->RR;
			break;
		default:
			Signal("Avast heaving!", (struct ship *)0);
			return;
	}
D 5
	repaired = 1;
E 5
	if (++*repairs >= 3) {
I 5
		count = 2;
E 5
D 2
		*repairs = 0;
E 2
		switch (c) {
D 5
		case 'h':
			if (ptr->hull < ptr->guns/4)
				Write(W_HULL, ms, 0,
					ptr->hull + 2, 0, 0, 0);
			else
				c = 0;
E 5
I 5
		case 'h': {
			int max = ptr->guns/4;
			if (ptr->hull < max) {
				FIX(hull, max);
				Write(W_HULL, ms, 0, ptr->hull, 0, 0, 0);
			}
E 5
			break;
I 5
			}
E 5
		case 'g':
			if (ptr->gunL < ptr->gunR) {
D 5
				if (ptr->gunL + ptr->carL < ptr->guns/5)
					Write(W_GUNL, ms, 0,
						ptr->gunL + 2, ptr->carL, 0, 0);
				else
					c = 0;
			} else
				if (ptr->gunR + ptr->carR < ptr->guns/5)
					Write(W_GUNR, ms, 0,
						ptr->gunR + 2, ptr->carR, 0, 0);
				else
					c = 0;
E 5
I 5
				int max = ptr->guns/5 - ptr->carL;
				if (ptr->gunL < max) {
					FIX(gunL, max);
					Write(W_GUNL, ms, 0, ptr->gunL,
						ptr->carL, 0, 0);
				}
			} else {
				int max = ptr->guns/5 - ptr->carR;
				if (ptr->gunR < max) {
					FIX(gunR, max);
					Write(W_GUNR, ms, 0, ptr->gunR,
						ptr->carR, 0, 0);
				}
			}
E 5
			break;
		case 'r':
D 5
			if (!ptr->rig4)
				Write(W_RIG4, ms, 0,
					ptr->rig4 + 2, 0, 0, 0);
			else if (!ptr->rig3)
				Write(W_RIG3, ms, 0, 2, 0, 0, 0);
			else if (!ptr->rig2)
				Write(W_RIG2, ms, 0, 2, 0, 0, 0);
			else if (ptr->rig1 < 4)
				Write(W_RIG1, ms, 0, 2, 0, 0, 0);
			else
				c = 0;
E 5
I 5
#define X 2
			if (ptr->rig4 >= 0 && ptr->rig4 < X) {
				FIX(rig4, X);
				Write(W_RIG4, ms, 0, ptr->rig4, 0, 0, 0);
			}
			if (count && ptr->rig3 < X) {
				FIX(rig3, X);
				Write(W_RIG3, ms, 0, ptr->rig3, 0, 0, 0);
			}
			if (count && ptr->rig2 < X) {
				FIX(rig2, X);
				Write(W_RIG2, ms, 0, ptr->rig2, 0, 0, 0);
			}
			if (count && ptr->rig1 < X) {
				FIX(rig1, X);
				Write(W_RIG1, ms, 0, ptr->rig1, 0, 0, 0);
			}
E 5
			break;
		}
D 2
		if (!c)
E 2
I 2
D 5
		if (!c) {
E 5
I 5
		if (count == 2) {
E 5
E 2
			Signal("Repairs completed.", (struct ship *)0);
I 2
			*repairs = 2;
		} else {
			*repairs = 0;
I 4
			blockalarm();
E 4
			draw_stat();
I 4
			unblockalarm();
E 4
		}
E 2
	}
I 4
	blockalarm();
E 4
I 2
	draw_slot();
I 4
	unblockalarm();
I 5
	repaired = 1;
E 5
E 4
E 2
}

turned()
{
	register char *p;

	for (p = movebuf; *p; p++)
		if (*p == 'r' || *p == 'l')
			return 1;
	return 0;
}

loadplayer()
{
	char c;
	register loadL, loadR, ready, load;

	if (!mc->crew3) {
		Signal("Out of crew", (struct ship *)0);
		return;
	}
	loadL = mf->loadL;
	loadR = mf->loadR;
	if (!loadL && !loadR) {
		c = sgetch("Load which broadside (left or right)? ",
			(struct ship *)0, 1);
		if (c == 'r')
			loadL = 1;
		else
			loadR = 1;
	}
	if (!loadL && loadR || loadL && !loadR) {
		c = sgetch("Reload with (round, double, chain, grape)? ",
			(struct ship *)0, 1);
		switch (c) {
		case 'r':
			load = L_ROUND;
			ready = 0;
			break;
		case 'd':
			load = L_DOUBLE;
			ready = R_DOUBLE;
			break;
		case 'c':
			load = L_CHAIN;
			ready = 0;
			break;
		case 'g':
			load = L_GRAPE;
			ready = 0;
			break;
		default:
			Signal("Broadside not loaded.",
				(struct ship *)0);
			return;
		}
		if (!loadR) {
			mf->loadR = load;
			mf->readyR = ready|R_LOADING;
		} else {
			mf->loadL = load;
			mf->readyL = ready|R_LOADING;
		}
		loaded = 1;
	}
}
E 1
