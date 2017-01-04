h38644
s 00010/00005/00228
d D 5.3 88/06/18 19:55:57 bostic 11 10
c install approved copyright notice
e
s 00009/00003/00224
d D 5.2 88/03/09 12:30:37 bostic 10 9
c written by David Riggle and Edward Wang; add Berkeley specific copyright
e
s 00005/00005/00222
d D 5.1 85/05/29 16:09:40 dist 9 8
c Add copyright
e
s 00006/00000/00221
d D 2.6 85/04/23 21:52:06 edward 8 7
c copyright message
e
s 00002/00002/00219
d D 2.5 83/12/21 12:56:26 edward 7 6
c dave's bug
e
s 00002/00000/00219
d D 2.4 83/12/17 13:18:55 edward 6 5
c some more blockalarm()s
e
s 00002/00002/00217
d D 2.3 83/12/17 12:39:27 edward 5 4
c new grapple and foul data structure.
e
s 00002/00000/00217
d D 2.2 83/12/09 13:31:43 edward 4 3
c turn window bigger, and block alarm when refreshing
e
s 00000/00000/00217
d D 2.1 83/10/31 13:46:26 edward 3 2
c new version
e
s 00001/00004/00216
d D 1.2 83/10/28 22:51:07 edward 2 1
c update display after change
e
s 00220/00000/00000
d D 1.1 83/10/28 19:24:34 edward 1 0
c date and time created 83/10/28 19:24:34 by edward
e
u
U
t
T
I 8
/*
D 9
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 9
I 9
 * Copyright (c) 1983 Regents of the University of California.
D 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
I 10
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 11
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 11
I 11
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
E 11
E 10
E 9
 */

E 8
I 1
#ifndef lint
D 9
static	char *sccsid = "%W% %E%";
#endif
E 9
I 9
static char sccsid[] = "%W% (Berkeley) %G%";
D 10
#endif not lint
E 10
I 10
#endif /* not lint */
E 10
E 9

#include "player.h"

#define turnfirst(x) (*x == 'r' || *x == 'l')

acceptmove()
{
	int ta;
	int ma;
	char af;
	int moved = 0;
	int vma, dir;
	char prompt[60];
	char buf[60], last = '\0';
	register char *p;

	if (!mc->crew3 || snagged(ms) || !windspeed) {
		Signal("Unable to move", (struct ship *)0);
		return;
	}
D 2
	if (*movebuf) {
		Signal("Already moved.", (struct ship *)0);
		return;
	}
E 2

	ta = maxturns(ms, &af);
	ma = maxmove(ms, mf->dir, 0);
	(void) sprintf(prompt, "move (%d,%c%d): ", ma, af ? '\'' : ' ', ta);
	sgetstr(prompt, buf, sizeof buf);
	dir = mf->dir;
	vma = ma;
	for (p = buf; *p; p++)
		switch (*p) {
		case 'l':
			dir -= 2;
		case 'r':
			if (++dir == 0)
				dir = 8;
			else if (dir == 9)
				dir = 1;
			if (last == 't') {
				Signal("Ship can't turn that fast.",
					(struct ship *)0);
				*p-- = '\0';
			}
			last = 't';
			ma--;
			ta--;
			vma = min(ma, maxmove(ms, dir, 0));
			if (ta < 0 && moved || vma < 0 && moved)
				*p-- = '\0';
			break;
		case 'b':
			ma--;
			vma--;
			last = 'b';
			if (ta < 0 && moved || vma < 0 && moved)
				*p-- = '\0';
			break;
		case '0':
		case 'd':
			*p-- = '\0';
			break;
		case '\n':
			*p-- = '\0';
			break;
		case '1': case '2': case '3': case '4':
		case '5': case '6': case '7':
			if (last == '0') {
				Signal("Can't move that fast.",
					(struct ship *)0);
				*p-- = '\0';
			}
			last = '0';
			moved = 1;
			ma -= *p - '0';
			vma -= *p - '0';
			if (ta < 0 && moved || vma < 0 && moved)
				*p-- = '\0';
			break;
		default:
			if (!isspace(*p)) {
				Signal("Input error.", (struct ship *)0);
				*p-- = '\0';
			}
		}
	if (ta < 0 && moved || vma < 0 && moved
	    || af && turnfirst(buf) && moved) {
		Signal("Movement error.", (struct ship *)0);
		if (ta < 0 && moved) {
			if (mf->FS == 1) {
				Write(W_FS, ms, 0, 0, 0, 0, 0);
				Signal("No hands to set full sails.",
					(struct ship *)0);
			}
		} else if (ma >= 0)
			buf[1] = '\0';
	}
	if (af && !moved) {
		if (mf->FS == 1) {
			Write(W_FS, ms, 0, 0, 0, 0, 0);
			Signal("No hands to set full sails.",
				(struct ship *)0);
		}
	}
	if (*buf)
		(void) strcpy(movebuf, buf);
	else
		(void) strcpy(movebuf, "d");
D 5
	Write(W_LAST, ms, 1, (int)movebuf, 0, 0, 0);
E 5
I 5
	Write(W_MOVE, ms, 1, (int)movebuf, 0, 0, 0);
E 5
	Signal("Helm: %s.", (struct ship *)0, movebuf);
}

acceptboard()
{
	register struct ship *sp;
	register int n;
	int crew[3];
	int men = 0;
	char c;

	crew[0] = mc->crew1;
	crew[1] = mc->crew2;
	crew[2] = mc->crew3;
	for (n = 0; n < NBP; n++) {
		if (mf->OBP[n].turnsent)
D 7
			    men += mf->OBP[n].turnsent;
E 7
I 7
			    men += mf->OBP[n].mensent;
E 7
	}
	for (n = 0; n < NBP; n++) {
		if (mf->DBP[n].turnsent)
D 7
			    men += mf->DBP[n].turnsent;
E 7
I 7
			    men += mf->DBP[n].mensent;
E 7
	}
	if (men) {
		crew[0] = men/100 ? 0 : crew[0] != 0;
		crew[1] = (men%100)/10 ? 0 : crew[1] != 0;
		crew[2] = men%10 ? 0 : crew[2] != 0;
	} else {
		crew[0] = crew[0] != 0;
		crew[1] = crew[1] != 0;
		crew[2] = crew[2] != 0;
	}
	foreachship(sp) {
		if (sp == ms || sp->file->dir == 0 || range(ms, sp) > 1)
			continue;
		if (ms->nationality == capship(sp)->nationality)
			continue;
		if (meleeing(ms, sp) && crew[2]) {
			c = sgetch("How many more to board the %s (%c%c)? ",
				sp, 1);
			parties(crew, sp, 0, c);
		} else if ((fouled2(ms, sp) || grappled2(ms, sp)) && crew[2]) {
			c = sgetch("Crew sections to board the %s (%c%c) (3 max) ?", sp, 1);
			parties(crew, sp, 0, c);
		}
	}
	if (crew[2]) {
		c = sgetch("How many sections to repel boarders? ",
			(struct ship *)0, 1);
		parties(crew, ms, 1, c);
	}
I 4
	blockalarm();
E 4
I 2
	draw_slot();
I 4
	unblockalarm();
E 4
E 2
}

parties(crew, to, isdefense, buf)
register struct ship *to;
int crew[3];
char isdefense;
char buf;
{
	register int k, j, men; 
	struct BP *ptr;
	int temp[3];

	for (k = 0; k < 3; k++)
		temp[k] = crew[k];
	if (isdigit(buf)) {
		ptr = isdefense ? to->file->DBP : to->file->OBP; 
		for (j = 0; j < NBP && ptr[j].turnsent; j++)
			;
		if (!ptr[j].turnsent && buf > '0') {
			men = 0;
			for (k = 0; k < 3 && buf > '0'; k++) {
				men += crew[k]
					* (k == 0 ? 100 : (k == 1 ? 10 : 1));
				crew[k] = 0;
				if (men)
					buf--;
			}
			if (buf > '0')
				Signal("Sending all crew sections.",
					(struct ship *)0);
			Write(isdefense ? W_DBP : W_OBP, ms, 0,
D 5
				j, turn, to-SHIP(0), men);
E 5
I 5
				j, turn, to->file->index, men);
E 5
			if (isdefense) {
				(void) wmove(slot_w, 2, 0);
				for (k=0; k < NBP; k++)
					if (temp[k] && !crew[k])
						(void) waddch(slot_w, k + '1');
					else
						(void) wmove(slot_w, 2, 1 + k);
				(void) mvwaddstr(slot_w, 3, 0, "DBP");
				makesignal(ms, "repelling boarders",
					(struct ship *)0);
			} else {
				(void) wmove(slot_w, 0, 0);
				for (k=0; k < NBP; k++)
					if (temp[k] && !crew[k])
						(void) waddch(slot_w, k + '1');
					else
						(void) wmove(slot_w, 0, 1 + k);
				(void) mvwaddstr(slot_w, 1, 0, "OBP");
				makesignal(ms, "boarding the %s (%c%c)", to);
			}
I 6
			blockalarm();
E 6
			(void) wrefresh(slot_w);
I 6
			unblockalarm();
E 6
		} else
			Signal("Sending no crew sections.", (struct ship *)0);
	}
}
E 1
