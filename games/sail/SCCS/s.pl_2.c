h64777
s 00010/00005/00128
d D 5.3 88/06/18 19:55:49 bostic 15 14
c install approved copyright notice
e
s 00009/00003/00124
d D 5.2 88/03/09 12:30:31 bostic 14 13
c written by David Riggle and Edward Wang; add Berkeley specific copyright
e
s 00005/00005/00122
d D 5.1 85/05/29 16:08:26 dist 13 12
c Add copyright
e
s 00006/00000/00121
d D 2.4 85/04/23 21:50:49 edward 12 11
c copyright message
e
s 00014/00000/00107
d D 2.3 83/12/09 13:29:45 edward 11 10
c turn window bigger, and block alarm when refreshing
e
s 00001/00000/00106
d D 2.2 83/11/08 15:40:34 edward 10 9
c show state of 'S' command
e
s 00000/00000/00106
d D 2.1 83/10/31 13:45:12 edward 9 8
c new version
e
s 00078/00343/00028
d D 1.8 83/10/28 19:23:16 edward 8 7
c rearranged player and screen stuff
e
s 00001/00001/00370
d D 1.7 83/10/14 23:08:20 edward 7 6
c lint
e
s 00031/00034/00340
d D 1.6 83/10/14 22:44:10 edward 6 5
c tricky input routines
e
s 00004/00004/00370
d D 1.5 83/10/10 20:11:10 edward 5 4
c got rid of unnecessary variables
e
s 00001/00001/00373
d D 1.4 83/10/05 11:45:17 edward 4 3
c changed sizes of things and reformated globals.c
e
s 00272/00674/00102
d D 1.3 83/07/20 17:26:15 edward 3 2
c 
e
s 00003/00001/00773
d D 1.2 83/05/20 17:44:24 root 2 1
c merge
e
s 00774/00000/00000
d D 1.1 83/03/17 21:11:55 leres 1 0
c date and time created 83/03/17 21:11:55 by leres
e
u
U
t
T
I 12
/*
D 13
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 13
I 13
 * Copyright (c) 1983 Regents of the University of California.
D 14
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 14
I 14
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 15
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 15
I 15
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
E 15
E 14
E 13
 */

E 12
I 1
#ifndef lint
D 13
static	char *sccsid = "%W% %E%";
#endif
E 13
I 13
static char sccsid[] = "%W% (Berkeley) %G%";
D 14
#endif not lint
E 14
I 14
#endif /* not lint */
E 14
E 13
I 2

E 2
#include "player.h"

D 6
#define turnfirst(buf)  (*buf == 'r' || *buf == 'l')
E 6
I 6
D 8
#define turnfirst(x) (*x == 'r' || *x == 'l')
E 6

lost()
E 8
I 8
play()
E 8
{
D 3
	if (scene[game].ship[player].file -> struck)
		leave(0);
	if (scene[game].ship[player].file -> captured > -1)
		leave(1);
E 3
I 3
D 8
	if (mf->struck)
		leave(LEAVE_QUIT);
	if (mf->captured != 0)
		leave(LEAVE_CAPTURED);
E 3
	if (windspeed == 7)
D 3
		leave(3);
	if(scene[game].ship[player].file -> FS && (!specs[scene[game].ship[player].shipnum].rig1 || windspeed == 6))
		Write(FILES + player, 0, 230, 0);
E 3
I 3
		leave(LEAVE_HURRICAN);
	if (mf->FS && (!mc->rig1 || windspeed == 6))
		Write(W_FS, ms, 0, 0, 0, 0, 0);
E 3
}
E 8
I 8
	register struct ship *sp;
E 8

D 3

E 3
D 8
acceptmove(ma, ta, af)
int ma, ta, af;
{
D 3
	register int n;
E 3
	int moved = 0;
D 3
	int full, vma, dir, ch;
E 3
I 3
	int vma, dir;
I 6
	char prompt[60];
E 6
E 3
	char buf[60], last = '\0';
I 3
	register char *p;
E 3

D 3
	if (scroll >= 22) scroll = 18;
	move(scroll++, 0);
	clearline();
	printw("move (%d,%c%d): ", ma, (af ? '\'' : ' '), ta);
	refresh();
	n = 0;
	while((ch = getch()) != '\n'){
		if (ch != EOF){
			buf[n++] = ch;
			addch(ch);
			refresh();
		}
		if(ch == '' && n > 1)
			n -= 2;
E 3
I 3
	if (*movebuf) {
		Signal("Already moved.", (struct ship *)0);
		return;
E 3
	}
D 3
	buf[n] = '\0';
	buf[9] = '\0';
	dir = pos[player].dir;
E 3
I 3
D 6
	Signal("move (%d,%c%d): ", (struct ship *)0, ma, af ? '\'' : ' ', ta);
	sgetstr(buf, sizeof buf);
	buf[sizeof movebuf - 1] = '\0';
E 6
I 6
D 7
	sprintf(prompt, "move (%d,%c%d): ", ma, af ? '\'' : ' ', ta);
E 7
I 7
	(void) sprintf(prompt, "move (%d,%c%d): ", ma, af ? '\'' : ' ', ta);
E 7
	sgetstr(prompt, buf, sizeof buf);
E 6
	dir = mf->dir;
E 3
	vma = ma;
D 3
	for (n = 0; buf[n]; n++)
		if (!(buf[n] == 'r' || buf[n] == '\n' || buf[n] == 'l' || (buf[n] == '0' && !n) || isdigit(buf[n]) || buf[n] == 'b' || (buf[n] == 'd' && !n))){
			if (isspace(buf[n])){
				strcpy(buf+n, buf+n+1);
				n--;
			} else {
				Signal("Syntax error.",0,0);
				buf[n--] = '\0';
E 3
I 3
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
E 3
			}
D 3
		}
		else
			switch(buf[n]){
				case 'l':
					dir -= 2;
				case 'r':
					dir++;
					if (!dir) dir = 8;
					if (dir == 9) dir = 1;
					if (last == 't'){
						Signal("Error; ship can't turn that fast.", 0, 0);
						buf[n--] = '\0';
					}
					last = 't';
					ma--;
					ta--;
					vma = min(ma, maxmove(player, dir, 0));
					if (ta < 0 && moved || vma < 0 && moved)
						buf[n--] = '\0';
					break;

				case 'b':
					ma--;
					vma--;
					last = 'b';
					if (ta < 0 && moved || vma < 0 && moved)
						buf[n--] = '\0';
					break;

				case '0':
				case 'd':
					buf[n--] = '\0';
					break;

				case '\n':
					buf[n] = '\0';
					break;

				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
					if (last == '0'){
						Signal("Error; value out of range.", 0, 0);
						buf[n--] = '\0';
					}
					last = '0';
					moved = 1;
					ma -= buf[n] - '0';
					vma -= buf[n] - '0';
					if (ta < 0 && moved || vma < 0 && moved)
						buf[n--] = '\0';
					break;

			} /* end switch and else and for */
	if (ta < 0 && moved || vma < 0 && moved || af && turnfirst(buf) && moved){
		Signal("Movement error.", 0, 0);
		if (ta < 0 && moved){
			if (scene[game].ship[player].file -> FS == 1){
				Write(FILES + player, 0, 230, 0);
				Signal("No hands to set full sails.", 0, 0);
E 3
I 3
			last = 't';
			ma--;
			ta--;
			vma = min(ma, maxmove(ms, dir, 0));
			if (ta < 0 && moved || vma < 0 && moved)
				*p-- = '\0';
E 8
I 8
	for (;;) {
		switch (sgetch("~\b", (struct ship *)0, 0)) {
		case 'm':
			acceptmove();
E 8
			break;
D 8
		case 'b':
			ma--;
			vma--;
			last = 'b';
			if (ta < 0 && moved || vma < 0 && moved)
				*p-- = '\0';
E 8
I 8
		case 's':
			acceptsignal();
E 8
			break;
D 8
		case '0':
		case 'd':
			*p-- = '\0';
E 8
I 8
		case 'g':
			grapungrap();
E 8
			break;
D 8
		case '\n':
			*p-- = '\0';
E 8
I 8
		case 'u':
			unfoulplayer();
E 8
			break;
D 8
		case '1': case '2': case '3': case '4':
		case '5': case '6': case '7':
			if (last == '0') {
				Signal("Can't move that fast.",
					(struct ship *)0);
				*p-- = '\0';
E 3
			}
I 3
			last = '0';
			moved = 1;
			ma -= *p - '0';
			vma -= *p - '0';
			if (ta < 0 && moved || vma < 0 && moved)
				*p-- = '\0';
E 8
I 8
		case 'v':
			Signal("%s", (struct ship *)0, version);
E 8
			break;
D 8
		default:
			if (!isspace(*p)) {
				Signal("Input error.", (struct ship *)0);
				*p-- = '\0';
			}
E 3
		}
D 3
		else if (ma >= 0)
E 3
I 3
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
E 3
			buf[1] = '\0';
	}
D 3
	if (af && !moved){
		if (scene[game].ship[player].file -> FS == 1){
			Write(FILES + player, 0, 230, 0);
			Signal("No hands to set full sails.", 0, 0);
E 3
I 3
	if (af && !moved) {
		if (mf->FS == 1) {
			Write(W_FS, ms, 0, 0, 0, 0, 0);
			Signal("No hands to set full sails.",
				(struct ship *)0);
E 3
		}
	}
D 3
	strcpy(movebuf, buf);
	if (!*movebuf) strcpy(movebuf, "d");
	Write(FILES + player, 1, 72, movebuf);
	Signal("Helm: %s.", -1, movebuf);
E 3
I 3
	if (*buf)
		(void) strcpy(movebuf, buf);
	else
		(void) strcpy(movebuf, "d");
	Write(W_LAST, ms, 1, (int)movebuf, 0, 0, 0);
	Signal("Helm: %s.", (struct ship *)0, movebuf);
E 3
}

D 3
boarding()
E 3
I 3
doboarding()
E 3
{
I 3
	register struct ship *sp;
E 3
D 2
	register int n, crew[3];
E 2
I 2
	register int n;
	int crew[3];
E 2
D 3
	int captured, men = 0;
	struct shipspecs *ptr;
E 3
I 3
	int men = 0;
I 6
	char c;
E 6
E 3

D 3
	ptr = &specs[scene[game].ship[player].shipnum];
	crew[0] = ptr -> crew1;
	crew[1] = ptr -> crew2;
	crew[2] = ptr -> crew3;
	for(n=0; n < 3; n++){
		if (scene[game].ship[player].file -> OBP[n].turnsent)
			    men += scene[game].ship[player].file -> OBP[n].turnsent;
E 3
I 3
	crew[0] = mc->crew1;
	crew[1] = mc->crew2;
	crew[2] = mc->crew3;
D 5
	for (n=0; n < 3; n++) {
E 5
I 5
	for (n = 0; n < NBP; n++) {
E 5
		if (mf->OBP[n].turnsent)
			    men += mf->OBP[n].turnsent;
E 3
	}
D 3
	for(n=0; n < 3; n++){
		if (scene[game].ship[player].file -> DBP[n].turnsent)
			    men += scene[game].ship[player].file -> DBP[n].turnsent;
E 3
I 3
D 5
	for (n=0; n < 3; n++) {
E 5
I 5
	for (n = 0; n < NBP; n++) {
E 5
		if (mf->DBP[n].turnsent)
			    men += mf->DBP[n].turnsent;
E 3
	}
D 3
	if (men){
E 3
I 3
	if (men) {
E 3
		crew[0] = men/100 ? 0 : crew[0] != 0;
		crew[1] = (men%100)/10 ? 0 : crew[1] != 0;
		crew[2] = men%10 ? 0 : crew[2] != 0;
	} else {
		crew[0] = crew[0] != 0;
		crew[1] = crew[1] != 0;
		crew[2] = crew[2] != 0;
	}
D 3
	for (n=0; n < scene[game].vessels; n++){
		if ((captured = scene[game].ship[n].file -> captured) < 0)
			captured = n;
		if (n != player && pos[n].dir && range(player, n) <= 1 && scene[game].ship[player].nationality != scene[game].ship[captured].nationality){
			if (meleeing(player, n) && crew[2]){
				Signal("How many more to board the %s (%c%c)? ",n,0);
				parties(crew, n, 200);
			}
			else if ((foul(player, n) || grapple(player, n)) && crew[2]){
				Signal("Crew sections to board the %s (%c%c) (3 max) ?", n, 0);
				parties(crew, n, 200);
			}
E 3
I 3
	foreachship(sp) {
D 5
		if (sp == ms || sp->file->dir == 0 || range(ms, sp) > 0)
E 5
I 5
		if (sp == ms || sp->file->dir == 0 || range(ms, sp) > 1)
E 5
			continue;
		if (ms->nationality == capship(sp)->nationality)
			continue;
		if (meleeing(ms, sp) && crew[2]) {
D 6
			Signal("How many more to board the %s (%c%c)? ", sp);
			parties(crew, sp, 0);
E 6
I 6
			c = sgetch("How many more to board the %s (%c%c)? ",
				sp, 1);
			parties(crew, sp, 0, c);
E 6
D 5
		} else if (grappled2(ms, sp) && crew[2]) {
E 5
I 5
		} else if ((fouled2(ms, sp) || grappled2(ms, sp)) && crew[2]) {
E 5
D 6
			Signal("Crew sections to board the %s (%c%c) (3 max) ?",
				sp);
			parties(crew, sp, 0);
E 6
I 6
			c = sgetch("Crew sections to board the %s (%c%c) (3 max) ?", sp, 1);
			parties(crew, sp, 0, c);
E 6
E 3
		}
	}
D 3
	if (crew[2]){
		Signal("How many sections to repel boarders? ", 0, 0);
		parties(crew, player, 260);
E 3
I 3
	if (crew[2]) {
D 6
		Signal("How many sections to repel boarders? ",
			(struct ship *)0);
		parties(crew, ms, 1);
E 6
I 6
		c = sgetch("How many sections to repel boarders? ",
			(struct ship *)0, 1);
		parties(crew, ms, 1, c);
E 6
E 3
	}
}

D 3
parties(crew, n, offset)
int crew[3], n, offset;
E 3
I 3
D 6
parties(crew, to, isdefense)
E 6
I 6
parties(crew, to, isdefense, buf)
E 6
register struct ship *to;
int crew[3];
char isdefense;
I 6
char buf;
E 6
E 3
{
	register int k, j, men; 
D 3
	struct BP * ptr;
	int  buf;
E 3
I 3
	struct BP *ptr;
D 6
	int buf;
E 6
E 3
	int temp[3];

D 3
	for (k=0; k < 3; k++)
E 3
I 3
	for (k = 0; k < 3; k++)
E 3
		temp[k] = crew[k];
D 3
	while((buf = getch()) == EOF);
	addch(buf);
	if (isdigit(buf)){
		ptr = offset == 200 ? scene[game].ship[player].file -> OBP : scene[game].ship[player].file -> DBP ; 
		for (j = 0; j < 3 && ptr[j].turnsent; j++);
		if (!ptr[j].turnsent && buf > '0'){
E 3
I 3
D 6
	buf = sgetch(1);
E 6
	if (isdigit(buf)) {
		ptr = isdefense ? to->file->DBP : to->file->OBP; 
		for (j = 0; j < NBP && ptr[j].turnsent; j++)
			;
		if (!ptr[j].turnsent && buf > '0') {
E 3
			men = 0;
D 3
			for (k=0; k < 3 && buf > '0'; k++){
				men += crew[k]*power(10, 2-k);
E 3
I 3
			for (k=0; k < 3 && buf > '0'; k++) {
				men += crew[k] * power(10, 2-k);
E 3
				crew[k] = 0;
D 3
				if (men) buf -= 1;
E 3
I 3
				if (men)
					buf -= 1;
E 3
			}
			if (buf > '0')
D 3
				Signal("Sending all crew sections.", 0, 0);
			Write(FILES + player, 0, 30 + (offset > 200)*18 + 6*j, turn);
			Write(FILES + player, 0, 30 + (offset > 200)*18 + 6*j + 2, n);
			Write(FILES + player, 0, 30 + (offset > 200)*18 + 6*j + 4, men);
			switch(offset){
				case 200:
					wmove(slot, 0, 0);
					for (k=0; k < 3; k++)
						if (temp[k] && !crew[k])
							waddch(slot, k + '1');
						else
							wmove(slot, 0, 1 + k);
					wmove(slot, 1, 0);
					waddstr(slot, "OBP");
					makesignal("boarding the %s (%c%c)", n, player);
					break;
				case 260:
					wmove(slot, 2, 0);
					for (k=0; k < 3; k++)
						if (temp[k] && !crew[k])
							waddch(slot, k + '1');
						else
							wmove(slot, 2, 1 + k);
					wmove(slot, 3, 0);
					waddstr(slot, "DBP");
					makesignal("repelling boarders", 0, player);
					break;
E 3
I 3
				Signal("Sending all crew sections.",
					(struct ship *)0);
			Write(isdefense ? W_DBP : W_OBP, ms, 0,
				j, turn, to-SHIP(0), men);
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
E 3
			}
D 3
			wrefresh(slot);
		}
		else
			Signal("Sending no crew sections.", 0, 0);
E 3
I 3
			(void) wrefresh(slot_w);
		} else
			Signal("Sending no crew sections.", (struct ship *)0);
E 3
	}
}

power(base, exp)
int base, exp;
{
D 3
	switch(exp){
E 3
I 3
	switch (exp) {
E 3
		case 0:
D 3
			return(1);
E 3
I 3
			return 1;
E 3
		case 1:
D 3
			return(base);
E 3
I 3
			return base;
E 3
		case 2:
D 3
			return(base * base);
E 3
I 3
			return base * base;
E 3
	}
D 3
	return(0);
E 3
I 3
	return 0;
E 3
}

repair()
{
D 6
	int buf;
E 6
I 6
	char c;
E 6
D 4
	int *repairs;
E 4
I 4
	char *repairs;
E 4
	struct shipspecs *ptr;

D 3
	if (!repaired && !loaded && !fired && !changed && !turned()){
		ptr = &specs[scene[game].ship[player].shipnum];
		Signal("Repair (hull, guns, rigging)? ", 0, 0);
		while((buf = getch()) == EOF);
		addch(buf);
		switch(buf){
			case 'h':
				repairs = &scene[game].ship[player].file -> RH;
				break;
			case 'g':
				repairs = &scene[game].ship[player].file -> RG;
				break;
			case 'r':
				repairs = &scene[game].ship[player].file -> RR;
				break;
			default:
				Signal("Avast heaving!", 0, 0);
				return;
E 3
I 3
	if (repaired || loaded || fired || changed || turned()) {
		Signal("No hands free to repair", (struct ship *)0);
		return;
	}
	ptr = mc;
D 6
	Signal("Repair (hull, guns, rigging)? ", (struct ship *)0);
	buf = sgetch(1);
	switch (buf) {
E 6
I 6
	c = sgetch("Repair (hull, guns, rigging)? ", (struct ship *)0, 1);
	switch (c) {
E 6
		case 'h':
			repairs = &mf->RH;
E 8
I 8
		case 'b':
			acceptboard();
E 8
			break;
D 8
		case 'g':
			repairs = &mf->RG;
E 8
I 8
		case 'f':
			acceptcombat();
E 8
			break;
I 8
		case 'l':
			loadplayer();
			break;
		case 'c':
			changesail();
			break;
E 8
		case 'r':
D 8
			repairs = &mf->RR;
E 8
I 8
			repair();
E 8
			break;
D 8
		default:
			Signal("Avast heaving!", (struct ship *)0);
			return;
	}
	repaired = 1;
	if (++*repairs >= 3) {
		*repairs = 0;
D 6
		switch (buf) {
E 6
I 6
		switch (c) {
E 6
		case 'h':
			if (ptr->hull < ptr->guns/4)
				Write(W_HULL, ms, 0,
					ptr->hull + 2, 0, 0, 0);
			else
D 6
				buf = 0;
E 6
I 6
				c = 0;
E 8
I 8
		case 'B':
			Signal("'Hands to stations!'", (struct ship *)0);
			unboard(ms, ms, 1);	/* cancel DBP's */
			unboard(ms, ms, 0);	/* cancel offense */
E 8
E 6
			break;
D 8
		case 'g':
			if (ptr->gunL < ptr->gunR) {
				if (ptr->gunL + ptr->carL < ptr->guns/5)
					Write(W_GUNL, ms, 0,
						ptr->gunL + 2, ptr->carL, 0, 0);
				else
D 6
					buf = 0;
E 6
I 6
					c = 0;
E 6
			} else
				if (ptr->gunR + ptr->carR < ptr->guns/5)
					Write(W_GUNR, ms, 0,
						ptr->gunR + 2, ptr->carR, 0, 0);
				else
D 6
					buf = 0;
E 6
I 6
					c = 0;
E 8
I 8
		case '\f':
			centerview();
I 11
			blockalarm();
E 11
			draw_board();
			draw_screen();
I 11
			unblockalarm();
E 11
E 8
E 6
			break;
D 8
		case 'r':
			if (!ptr->rig4)
				Write(W_RIG4, ms, 0,
					ptr->rig4 + 2, 0, 0, 0);
			else if (!ptr->rig3)
				Write(W_RIG3, ms, 0, 2, 0, 0, 0);
			else if (!ptr->rig2)
				Write(W_RIG2, ms, 0, 2, 0, 0, 0);
			else if (ptr->rig1 < 4)
				Write(W_RIG1, ms, 0, 2, 0, 0, 0);
E 8
I 8
		case 'L':
			mf->loadL = L_EMPTY;
			mf->loadR = L_EMPTY;
			mf->readyL = R_EMPTY;
			mf->readyR = R_EMPTY;
			Signal("Broadsides unloaded", (struct ship *)0);
			break;
		case 'q':
			Signal("Type 'Q' to quit", (struct ship *)0);
			break;
		case 'Q':
			leave(LEAVE_QUIT);
			break;
		case 'I':
			foreachship(sp)
				if (sp != ms)
					eyeball(sp);
			break;
		case 'i':
			if ((sp = closestenemy(ms, 0, 1)) == 0)
				Signal("No more ships left.");
E 8
			else
D 6
				buf = 0;
E 6
I 6
D 8
				c = 0;
E 8
I 8
				eyeball(sp);
E 8
E 6
			break;
E 3
D 8
		}
D 3
		repaired = 1;
		*repairs += 1;
		if (*repairs >= 3){
			*repairs = 0;
		}
		if (!*repairs){
			switch(buf){
				case 'h':
					if (ptr -> hull < ptr -> guns/4)
						Write(SPECS + player, 0, 10, ptr -> hull + 2);
					else buf = 0;
					break;
				case 'g':
					if (ptr -> gunL < ptr -> gunR){
						if (ptr -> gunL + ptr -> carL < ptr -> guns/5)
							Write(SPECS + player, 0, 20, ptr -> gunL + 2);
						else buf = 0;
					} else
						if (ptr -> gunR + ptr -> carR < ptr -> guns/5)
							Write(SPECS + player, 0, 22, ptr -> gunR + 2);
						else buf = 0;
					break;
				case 'r':
					if (!ptr -> rig4)
						Write(SPECS + player, 0, 34, ptr -> rig4 + 2);
					else if (!ptr -> rig3)
						Write(SPECS + player, 0, 32, 2);
					else if (!ptr -> rig2)
						Write(SPECS + player, 0, 30, 2);
					else if (ptr -> rig1 < 4)
						Write(SPECS + player, 0, 28, 2);
					else buf = 0;
					break;
			}
			if (!buf)
				Signal("Repairs completed.", 0, 0);
		}
E 3
I 3
D 6
		if (!buf)
E 6
I 6
		if (!c)
E 6
			Signal("Repairs completed.", (struct ship *)0);
E 3
	}
D 3
	else
		Signal("No hands free to repair",0,0);
E 3
}

turned()
{
D 3
	register int n;
E 3
I 3
	register char *p;
E 3

D 3
	for (n=0; movebuf[n]; n++)
		if (movebuf[n] == 'r' || movebuf[n] == 'l')
			return(1);
	return(0);
E 3
I 3
	for (p = movebuf; *p; p++)
		if (*p == 'r' || *p == 'l')
			return 1;
	return 0;
E 3
}

loadplayer()
{
D 6
	int buf;
E 6
I 6
	char c;
E 6
D 3
	int loadL, loadR, ready, load, *Ready, *Load;
E 3
I 3
	register loadL, loadR, ready, load;
E 3

D 3
	if (!specs[scene[game].ship[player].shipnum].crew3){
		Signal("out of crew",0,0);
		return(0);
E 3
I 3
	if (!mc->crew3) {
		Signal("Out of crew", (struct ship *)0);
		return;
E 3
	}
D 3
	Load = &scene[game].ship[player].file -> loadL;
	Ready = &scene[game].ship[player].file -> readyL;
	loadL = *Load;
	loadR = *(Load + 1);
	if (!loadL && !loadR){
		Signal("Load which broadside (left or right)? ", 0, 0);
		while((buf = getch()) == EOF);
		addch(buf);
E 3
I 3
	loadL = mf->loadL;
	loadR = mf->loadR;
	if (!loadL && !loadR) {
D 6
		Signal("Load which broadside (left or right)? ",
			(struct ship *)0);
		buf = sgetch(1);
E 3
		if (buf == 'r')
E 6
I 6
		c = sgetch("Load which broadside (left or right)? ",
			(struct ship *)0, 1);
		if (c == 'r')
E 6
			loadL = 1;
		else
			loadR = 1;
	}
D 3
	if ((!loadL && loadR || loadL && !loadR)){
		Signal("Reload with (round, double, chain, grape)? ", 0, 0);
		while((buf = getch()) == EOF);
		addch(buf);
		switch(buf){
			case 'r':
				load = ROUND;
				ready = 1;
				break;
			case 'd':
				load = DOUBLE;
				ready = 2;
				break;
			case 'c':
				load = CHAIN;
				ready = 1;
				break;
			case 'g':
				load = GRAPE;
				ready = 1;
				break;
			default:
				Signal("Broadside not loaded.", 0, 0);
				return;
		}
		if (!loadR){
			*(Load + 1) = load;
			*(Ready + 1) = ready;
		}
		else {
			*Load = load;
			*Ready = ready;
		}
		loaded = 1;
	}
}

changesail()
{
	int buf;
	int rig, full;

	rig = specs[scene[game].ship[player].shipnum].rig1;
	full = scene[game].ship[player].file -> FS;
	if ((windspeed == 6) || (windspeed == 5 && specs[scene[game].ship[player].shipnum].class > 4))
		rig = 0;
	if (specs[scene[game].ship[player].shipnum].crew3 && rig){
		if (!full){
			Signal("Increase to Full sails? ", 0, 0);
			while((buf = getch()) == EOF);
			addch(buf);
			if (buf == 'y'){
				changed = 1;
				Write(FILES + player, 0, 230, 1);
			}
		}
		else {
			Signal("Reduce to Battle sails? ", 0, 0);
			while((buf = getch()) == EOF);
			addch(buf);
			if (buf == 'y'){
				Write(FILES + player, 0, 230, 0);
				changed = 1;
			}
		}
	}
	else if (!rig)
		Signal("Sails rent to pieces",0,0);
}


signalflags()
{
	register int n;

	for(n=0; n < scene[game].vessels; n++){
		if (*scene[game].ship[n].file -> signal){
			putchar('\7');
			Signal("%s (%c%c): %s",n,scene[game].ship[n].file -> signal);
			*scene[game].ship[n].file -> signal = '\0';
		}
	}
}

iplotships()		/* new turn; also plot-ships */
{
	repaired = loaded = fired = changed = 0;
	plotships();
}


plotships()			/* uses ken's package */
{
	register int n;
	char ch;
	int sternr,sternc;

	getyx(stdscr, ylast, xlast);
	screen();
	readpos();
	werase(view);
	if (pos[player].row < viewrow + 5)
		viewrow = pos[player].row - ROWSINVIEW + 5;
	else if (pos[player].row > viewrow + ROWSINVIEW - 5)
		viewrow = pos[player].row - 5;
	if (pos[player].col < viewcol + 10)
		viewcol = pos[player].col - COLSINVIEW + 10;
	else if (pos[player].col > viewcol + COLSINVIEW - 10)
		viewcol = pos[player].col - 10;
	for (n=0; n < scene[game].vessels; n++)
		if (pos[n].dir && pos[n].row > viewrow && pos[n].row < viewrow + ROWSINVIEW && pos[n].col > viewcol && pos[n].col < viewcol + COLSINVIEW){
			wmove(view, pos[n].row - viewrow, pos[n].col - viewcol);
			waddch(view, colours(n));
			ch = sterncolor(n, &sternr, &sternc);
			wmove(view, sternr - viewrow, sternc - viewcol);
			waddch(view, ch);
		}
	wrefresh(view);
	move(ylast, xlast);
	refresh();
}

acceptsignal()
{
	int ch;
	char buf[60];
	register int n;

	if(scroll == 23) scroll = 18;
	Signal("Message? ",0,0);
	buf[0] = 34;
	n = 1;
	while((ch = getch()) != '\n'){
		if (ch != EOF){
			buf[n++] = ch;
			addch(ch);
			refresh();
		}
		if (ch == '' && n > 1)
			n -= 2;
	}
	buf[n] = 34;
	buf[n+1] = '\0';
	buf[59] = '\0';
	Write(FILES + player, 1, 164, buf);
}


board()
{
	register int n;
	char *name;
	int class, junk;

	clear();
	werase(view);
	werase(slot);
	move(1,0);
	for (n=0; n < 80; n++)
		addch('-');
	move(17,0);
	for (n=0; n < 80; n++)
		addch('-');
	for (n=2; n < 17; n++){
		mvaddch(n, 0,'|');
		mvaddch(n, 79, '|');
	}
	mvaddch(1,0,'+');
	mvaddch(17,0,'+');
	mvaddch(1,79,'+');
	mvaddch(17,79,'+');
	wmove(view, 2, 27);
	waddstr(view, "Wooden Ships & Iron Men");
	wmove(view, 4, (77 - lengthof(scene[game].name))/2);
	waddstr(view, scene[game].name);
	refresh();
	wrefresh(view);
	switch((class = specs[scene[game].ship[player].shipnum].class)){
		case 2:
		case 1:
			name = "SOL";
E 3
I 3
	if (!loadL && loadR || loadL && !loadR) {
D 6
		Signal("Reload with (round, double, chain, grape)? ",
			(struct ship *)0);
		buf = sgetch(1);
		switch (buf) {
E 6
I 6
		c = sgetch("Reload with (round, double, chain, grape)? ",
			(struct ship *)0, 1);
		switch (c) {
E 6
		case 'r':
			load = L_ROUND;
			ready = 0;
E 8
I 8
		case 'C':
			centerview();
I 11
			blockalarm();
E 11
			draw_view();
I 11
			unblockalarm();
E 11
E 8
E 3
			break;
D 3
		case 3:
		case 4:
			name = "Frigate";
E 3
I 3
D 8
		case 'd':
			load = L_DOUBLE;
			ready = R_DOUBLE;
E 8
I 8
		case 'U':
			upview();
I 11
			blockalarm();
E 11
			draw_view();
I 11
			unblockalarm();
E 11
E 8
E 3
			break;
D 3
		case 5:
		case 6:
			name = "Sloop";
E 3
I 3
D 8
		case 'c':
			load = L_CHAIN;
			ready = 0;
E 8
I 8
		case 'D':
		case 'N':
			downview();
I 11
			blockalarm();
E 11
			draw_view();
I 11
			unblockalarm();
E 11
E 8
E 3
			break;
D 3
	}
	move(0,0);
	printw("Class %d %s (%d guns) '%s' (%c%c)", class, name, specs[scene[game].ship[player].shipnum].guns, scene[game].ship[player].shipname, colours(player), sterncolor(player, &junk, &junk));
}

clearline()
{
	register int n;

	move(scroll-1, 0);
	for (n=0; n < 59; n++)
		addch(' ');
	move(scroll-1, 0);
}



Signal(fmt, shipnum, string)
int shipnum;
char *fmt, *string;
{
	int junk;

	move(scroll++, 0);
	clearline();
	if (scroll > 23) scroll = 18;
	if (shipnum == -1)
		printw(fmt, string);
	else if (*string == '*')
		printw(fmt, "computer", '0','0', string);
	else
		printw(fmt, scene[game].ship[shipnum].shipname, colours(shipnum), sterncolor(shipnum, &junk, &junk), string);
	refresh();
}

char *quality(shipnum)
int shipnum;
{
	switch(specs[scene[game].ship[shipnum].shipnum].qual){

		case 5:
			return("elite");
		case 4:
			return("crack");
		case 3:
			return("mundane");
		case 2:
			return("green");
		case 1:
			return("mutinous");
	}
}

char *info(ship, final)
int ship;
char *final;
{
	sprintf(final, "%d gun \0", specs[scene[game].ship[ship].shipnum].guns);
	switch(specs[scene[game].ship[ship].shipnum].class){
		case 1:
		case 2:
			strcat(final, "Ship of the Line");
E 3
I 3
D 8
		case 'g':
			load = L_GRAPE;
			ready = 0;
E 8
I 8
		case 'H':
			leftview();
I 11
			blockalarm();
E 11
			draw_view();
I 11
			unblockalarm();
E 11
E 8
E 3
			break;
D 3
		case 3:
			strcat(final, "Frigate");
			break;
		case 4:
			strcat(final, "Corvette");
			break;
		case 5:
			strcat(final, "Sloop");
			break;
		case 6:
			strcat(final, "Brig");
			break;
E 3
I 3
D 8
		default:
			Signal("Broadside not loaded.",
				(struct ship *)0);
			return;
E 8
I 8
		case 'J':
			rightview();
I 11
			blockalarm();
E 11
			draw_view();
I 11
			unblockalarm();
E 11
			break;
		case 'F':
			lookout();
			break;
		case 'S':
			dont_adjust = !dont_adjust;
I 11
			blockalarm();
E 11
I 10
			draw_turn();
I 11
			unblockalarm();
E 11
E 10
			break;
E 8
		}
D 8
		if (!loadR) {
			mf->loadR = load;
			mf->readyR = ready|R_LOADING;
		} else {
			mf->loadL = load;
			mf->readyL = ready|R_LOADING;
		}
		loaded = 1;
E 8
E 3
	}
D 3
	return(final);
E 3
}
D 3

screen()
{
	int class;
	register int n;
	int dr = 0, dc = 0;
	struct shipspecs *data;
	struct File *ptr;

	scene[game].ship[player].file -> readyL--;
	scene[game].ship[player].file -> readyR--;
	movebuf[0] = '\0';
	sync();
	if (turn % 50 == 0)
		Write(SCENARIO, 0, 10, 1);	/* still playing */
	windspeed = scene[game].windspeed;
	winddir = scene[game].winddir;
	turn = scene[game].turn;
	move(0, 47);
	ptr = scene[game].ship[player].file;
	data = &specs[scene[game].ship[player].shipnum];
	if (ptr -> FS == 1)
		Write(FILES + player, 0, 230, 2);
	printw("Points:%3d Fouls:%2d  Grapples:%2d",ptr -> points, fouled(player), grappled(player));
	move(17, 36);
	printw("Turn %d", turn);
	move(18, 59);
	printw("Load  %c%c %c%c", symbol(ptr -> loadL), iinitial(ptr -> readyL), symbol(ptr -> loadR), iinitial(ptr -> readyR));
	move(19, 59);
	printw("Hull %2d", data -> hull);
	move(20, 59);
	printw("Crew %2d %2d %2d", data -> crew1, data -> crew2, data -> crew3);
	move(21, 59);
	printw("Guns %2d %2d", data -> gunL, data -> gunR);
	move(22, 59);
	printw("Carr %2d %2d", data -> carR, data -> carL);
	move(23, 59);
	printw("Rigg %d %d %d ", data -> rig1, data -> rig2, data -> rig3);
	if (data -> rig4 < 0)
		addch('-');
	else
		printw("%d", data -> rig4);
	move(18, 74);
	printw("0 %d(%d)", maxmove(player, winddir + 3, -1), maxmove(player, winddir + 3, 1));
	move(19, 73);
	addstr("\\|/");
	move(20, 73);
	printw("-^-%d(%d)", maxmove(player, winddir + 2, -1), maxmove(player, winddir + 2, 1));
	move(21, 73);
	addstr("/|\\");
	move(22, 74);
	printw("| %d(%d)", maxmove(player, winddir + 1, -1), maxmove(player, winddir + 1, 1));
	move(23, 73);
	printw("%d(%d)", maxmove(player, winddir, -1), maxmove(player, winddir, 1));
	refresh();
	if (!boarders(player, 0)){
		wmove(slot, 0, 0);
		waddstr(slot, "   ");
		wmove(slot, 1, 0);
		waddstr(slot, "   ");
	} else {
		wmove(slot, 1, 0);
		waddstr(slot, "OBP");
	}
	if (!boarders(player, 1)){
		wmove(slot, 2, 0);
		waddstr(slot, "   ");
		wmove(slot, 3, 0);
		waddstr(slot, "   ");
	} else {
		wmove(slot, 3, 0);
		waddstr(slot, "DBP");
	}
	wmove(slot, 12, 0);
	if (n = scene[game].ship[player].file -> RH)
		wprintw(slot, "%dRH", n);
	else
		waddstr(slot, "   ");
	wmove(slot, 13, 0);
	if (n = scene[game].ship[player].file -> RG)
		wprintw(slot, "%dRG", n);
	else
		waddstr(slot, "   ");
	wmove(slot, 14, 0);
	if (n = scene[game].ship[player].file -> RR)
		wprintw(slot, "%dRR", n);
	else
		waddstr(slot, "   ");
	wmove(slot, 7, 1);
	wprintw(slot,"%d", windspeed);
	drdc(&dr, &dc, winddir);
	wmove(slot, 7, 0); waddch(slot, ' ');
	wmove(slot, 7, 2); waddch(slot, ' ');
	wmove(slot, 6, 0); waddch(slot, ' ');
	wmove(slot, 6, 1); waddch(slot, ' ');
	wmove(slot, 6, 2); waddch(slot, ' ');
	wmove(slot, 8, 0); waddch(slot, ' ');
	wmove(slot, 8, 1); waddch(slot, ' ');
	wmove(slot, 8, 2); waddch(slot, ' ');
	wmove(slot, (7 - dr), (1 - dc));
	switch(winddir){
		case 1:
		case 5:
			waddch(slot, '|');
			break;
		case 2:
		case 6:
			waddch(slot, '/');
			break;
		case 3:
		case 7:
			waddch(slot, '-');
			break;
		case 4:
		case 8:
			waddch(slot, '\\');
			break;
	}
	wmove(slot, (7 + dr), (1 + dc));
	waddch(slot, '+');
	wrefresh(slot);
	signal(SIGALRM, iplotships);	/* new turn and plot-ships */
	alarm(7);
}

extern char iinitial(ready)
int ready;
{
	if (ready <= -30000)
		return('!');
	if (ready > 0)
		return('*');
	return(' ');
}

char symbol(number)
int number;
{
	switch(number){
		case GRAPE:
			return('G');
		case ROUND:
			return('R');
		case DOUBLE:
			return('D');
		case CHAIN:
			return('C');
	}
	return('-');
}

E 3
E 1
