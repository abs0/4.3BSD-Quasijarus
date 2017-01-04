h36434
s 00010/00005/00248
d D 5.3 88/06/18 19:55:12 bostic 11 10
c install approved copyright notice
e
s 00009/00003/00244
d D 5.2 88/03/09 12:30:05 bostic 10 9
c written by David Riggle and Edward Wang; add Berkeley specific copyright
e
s 00005/00005/00242
d D 5.1 85/05/29 15:58:10 dist 9 8
c Add copyright
e
s 00006/00000/00241
d D 2.5 85/04/23 21:46:25 edward 8 7
c copyright message
e
s 00004/00004/00237
d D 2.4 84/02/03 15:41:41 edward 7 6
c portside() is left handed
e
s 00015/00041/00226
d D 2.3 83/12/17 12:38:16 edward 6 5
c new grapple and foul data structure.
e
s 00003/00003/00264
d D 2.2 83/11/01 17:34:23 edward 5 4
c clean{foul,grapple}()
e
s 00000/00000/00267
d D 2.1 83/10/31 13:43:19 edward 4 3
c new version
e
s 00003/00001/00264
d D 1.3 83/10/28 22:47:54 edward 3 2
c no more 'crew demoralized'
e
s 00177/00196/00088
d D 1.2 83/07/20 17:18:45 edward 2 1
c 
e
s 00284/00000/00000
d D 1.1 83/03/17 21:08:59 leres 1 0
c date and time created 83/03/17 21:08:59 by leres
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
D 2
#define EXPLODE 5
E 2
I 2

E 2
#include "externs.h"

D 2
table(rig, shot, hittable, onship, fromship, roll)
int rig, shot, hittable, onship, fromship, roll;
E 2
I 2
table(rig, shot, hittable, on, from, roll)
struct ship *on, *from;
int rig, shot, hittable, roll;
E 2
{
	register int hhits = 0, chits = 0, ghits = 0, rhits = 0;
	int Ghit = 0, Hhit = 0, Rhit = 0, Chit = 0;
	int guns, car, pc, hull;
	int crew[3];
	register int n;
	int rigg[4];
D 2
	char message[60];
	struct shipspecs *ptr;
	struct File *ptr1;
E 2
I 2
	char *message;
	struct Tables *tp;
E 2

D 2
	ptr = &specs[scene[game].ship[onship].shipnum];
	ptr1 = scene[game].ship[onship].file;
	pc = ptr1 -> pcrew;
	hull = ptr -> hull;
	crew[0] = ptr -> crew1;
	crew[1] = ptr -> crew2;
	crew[2] = ptr -> crew3;
	rigg[0] = ptr -> rig1;
	rigg[1] = ptr -> rig2;
	rigg[2] = ptr -> rig3;
	rigg[3] = ptr -> rig4;
	if (shot == GRAPE)
E 2
I 2
	pc = on->file->pcrew;
	hull = on->specs->hull;
	crew[0] = on->specs->crew1;
	crew[1] = on->specs->crew2;
	crew[2] = on->specs->crew3;
	rigg[0] = on->specs->rig1;
	rigg[1] = on->specs->rig2;
	rigg[2] = on->specs->rig3;
	rigg[3] = on->specs->rig4;
	if (shot == L_GRAPE)
E 2
		Chit = chits = hittable;
	else {
D 2
		Chit = chits = rig ? RigTable[hittable][roll-1].C : HullTable[hittable][roll-1].C;
		Rhit = rhits = rig ? RigTable[hittable][roll-1].R : HullTable[hittable][roll-1].R;
		Hhit = hhits = rig ? RigTable[hittable][roll-1].H : HullTable[hittable][roll-1].H;
		Ghit = ghits = rig ? RigTable[hittable][roll-1].G : HullTable[hittable][roll-1].G;
		if (ptr1 -> FS)
E 2
I 2
		tp = &(rig ? RigTable : HullTable)[hittable][roll-1];
		Chit = chits = tp->C;
		Rhit = rhits = tp->R;
		Hhit = hhits = tp->H;
		Ghit = ghits = tp->G;
		if (on->file->FS)
E 2
			rhits *= 2;
D 2
		if (shot == CHAIN){
E 2
I 2
		if (shot == L_CHAIN) {
E 2
			Ghit = ghits = 0;
			Hhit = hhits = 0;
		}
	}
D 2
	if (ptr1 -> captured > -1){
		pc -= (chits + 1)/2;
E 2
I 2
	if (on->file->captured != 0) {
		pc -= (chits + 1) / 2;
E 2
		chits /= 2;
	}
D 2
	for (n=0; n < 3; n++)
		if (chits > crew[n]){
E 2
I 2
	for (n = 0; n < 3; n++)
		if (chits > crew[n]) {
E 2
			chits -= crew[n];
			crew[n] = 0;
D 2
		}
		else {
E 2
I 2
		} else {
E 2
			crew[n] -= chits;
			chits = 0;
		}
D 2
	for (n=0; n < 3; n++)
E 2
I 2
	for (n = 0; n < 3; n++)
E 2
		if (rhits > rigg[n]){
			rhits -= rigg[n];
			rigg[n] = 0;
D 2
		}
		else {
E 2
I 2
		} else {
E 2
			rigg[n] -= rhits;
			rhits = 0;
		}
D 2
	if (rigg[3] != -1 && rhits > rigg[3]){
E 2
I 2
	if (rigg[3] != -1 && rhits > rigg[3]) {
E 2
		rhits -= rigg[3];
		rigg[3] = 0;
D 2
	} else if (rigg[3] != -1){
E 2
I 2
	} else if (rigg[3] != -1) {
E 2
		rigg[3] -= rhits;
	}
	if (rig && !rigg[2] && (!rigg[3] || rigg[3] == -1))
D 2
		makesignal("dismasted!", 0, onship);
	if (portside(fromship, onship, 0)){
		guns = ptr -> gunL;
		car = ptr -> carL;
E 2
I 2
		makesignal(on, "dismasted!", (struct ship *)0);
	if (portside(from, on, 0)) {
D 7
		guns = on->specs->gunL;
		car = on->specs->carL;
E 2
	} else {
E 7
D 2
		guns = ptr -> gunR;
		car = ptr -> carR;
E 2
I 2
		guns = on->specs->gunR;
		car = on->specs->carR;
I 7
	} else {
		guns = on->specs->gunL;
		car = on->specs->carL;
E 7
E 2
	}
D 2
	if (ghits > car){
E 2
I 2
	if (ghits > car) {
E 2
		ghits -= car;
		car = 0;
D 2
	}
	else {
E 2
I 2
	} else {
E 2
		car -= ghits;
		ghits = 0;
	}
	if (ghits > guns){
		ghits -= guns;
		guns = 0;
D 2
	}
	else {
E 2
I 2
	} else {
E 2
		guns -= ghits;
		ghits = 0;
	}
	hull -= ghits;
D 2
	if (portside(fromship, onship, 0) && Ghit){
		Write(SPECS + onship, 0, 20, guns);
		Write(SPECS + onship, 0, 24, car);
	}
	else if (Ghit){
		Write(SPECS + onship, 0, 22, guns);
		Write(SPECS + onship, 0, 26, car);
	}
E 2
I 2
	if (Ghit)
D 7
		Write(portside(from, on, 0) ? W_GUNL : W_GUNR,
E 7
I 7
		Write(portside(from, on, 0) ? W_GUNR : W_GUNL,
E 7
			on, 0, guns, car, 0, 0);
E 2
	hull -= hhits;
	hull = hull < 0 ? 0 : hull;
D 2
	if (ptr1 -> captured > -1 && Chit){
		Write(FILES + onship, 0, 70, pc);
	}
E 2
I 2
	if (on->file->captured != 0 && Chit)
		Write(W_PCREW, on, 0, pc, 0, 0, 0);
E 2
	if (Hhit)
D 2
		Write(SPECS + onship, 0, 10, hull);
E 2
I 2
		Write(W_HULL, on, 0, hull, 0, 0, 0);
E 2
	if (Chit)
D 2
		for (n=0; n < 3; n++)
			Write(SPECS + onship, 0, 14 + 2*n, crew[n]);
E 2
I 2
		Write(W_CREW, on, 0, crew[0], crew[1], crew[2], 0);
E 2
	if (Rhit)
D 2
		for (n=0; n < 4; n++)
			Write(SPECS + onship, 0, 28 + 2*n, rigg[n]);
	switch(shot){
		case ROUND:
			strcpy(message, "firing round");
E 2
I 2
		Write(W_RIGG, on, 0, rigg[0], rigg[1], rigg[2], rigg[3]);
	switch (shot) {
	case L_ROUND:
		message = "firing round shot on %s (%c%c)";
		break;
	case L_GRAPE:
		message = "firing grape shot on %s (%c%c)";
		break;
	case L_CHAIN:
		message = "firing chain shot on %s (%c%c)";
		break;
	case L_DOUBLE:
		message = "firing double shot on %s (%c%c)";
		break;
	case L_EXPLODE:
		message = "exploding shot on %s (%c%c)";
	}
	makesignal(from, message, on);
	if (roll == 6 && rig) {
		switch(Rhit) {
		case 0:
			message = "fore topsail sheets parted";
E 2
			break;
D 2
		case GRAPE:
			strcpy(message, "firing grape");
E 2
I 2
		case 1:
			message = "mizzen shrouds parted";
E 2
			break;
D 2
		case CHAIN:
			strcpy(message, "firing chain");
E 2
I 2
		case 2:
			message = "main topsail yard shot away";
E 2
			break;
D 2
		case DOUBLE:
			strcpy(message, "firing double");
E 2
I 2
		case 4:
			message = "fore topmast and foremast shrouds shot away";
E 2
			break;
D 2
		case EXPLODE:
			strcpy(message, "exploding");
	}
	strcat(message, " shot on %s (%c%c)");
	makesignal(message, onship, fromship);
	if (roll == 6 && rig){
		switch(Rhit){
			case 0:
				strcpy(message, "fore topsail sheets parted");
				break;
			case 1:
				strcpy(message, "mizzen shrouds parted");
				break;
			case 2:
				strcpy(message, "main topsail yard shot away");
				break;
			case 4:
				strcpy(message, "fore topmast and foremast shrouds shot away");
				break;
			case 5:
				strcpy(message, "mizzen mast and yard shot through");
				break;
			case 6:
				strcpy(message, "foremast and spritsail yard shattered");
				break;
			case 7:
				strcpy(message, "main topmast and mizzen mast shattered");
				break;
E 2
I 2
		case 5:
			message = "mizzen mast and yard shot through";
			break;
		case 6:
			message = "foremast and spritsail yard shattered";
			break;
		case 7:
			message = "main topmast and mizzen mast shattered";
			break;
E 2
		}
D 2
		makesignal(message, 0, onship);
	}
	else if (roll == 6) {
		switch(Hhit){
			case 0:
				strcpy(message, "anchor cables severed");
				break;
			case 1:
				strcpy(message, "two anchor stocks shot away");
				break;
			case 2:
				strcpy(message, "quarterdeck bulwarks damaged");
				break;
			case 3:
				strcpy(message, "three gun ports shot away");
				break;
			case 4:
				strcpy(message, "four guns dismounted");
				break;
			case 5:
				strcpy(message, "rudder cables shot through");
				Write(SPECS + onship, 0, 4, 0);
				break;
			case 6:
				strcpy(message, "shot holes below the water line");
				break;
E 2
I 2
		makesignal(on, message, (struct ship *)0);
	} else if (roll == 6) {
		switch (Hhit) {
		case 0:
			message = "anchor cables severed";
			break;
		case 1:
			message = "two anchor stocks shot away";
			break;
		case 2:
			message = "quarterdeck bulwarks damaged";
			break;
		case 3:
			message = "three gun ports shot away";
			break;
		case 4:
			message = "four guns dismounted";
			break;
		case 5:
			message = "rudder cables shot through";
			Write(W_TA, on, 0, 0, 0, 0, 0);
			break;
		case 6:
			message = "shot holes below the water line";
			break;
E 2
		}
D 2
		makesignal(message, 0, onship);
E 2
I 2
		makesignal(on, message, (struct ship *)0);
E 2
	}
D 2
	if ((Chit > 1 && ptr1 -> readyL <= -30000 && ptr1 -> readyR <= -30000) || Chit == 4){
		ptr -> qual--;
		if (ptr -> qual <= 0){
			makesignal("crew mutinying!", 0, onship);
			ptr -> qual = 5;
			Write(FILES + onship, 0, 68, onship);
E 2
I 2
D 3
	if (Chit > 1 && on->file->readyL&R_INITIAL && on->file->readyR&R_INITIAL || Chit == 4) {
E 3
I 3
	/*
	if (Chit > 1 && on->file->readyL&R_INITIAL && on->file->readyR&R_INITIAL) {
E 3
		on->specs->qual--;
		if (on->specs->qual <= 0) {
			makesignal(on, "crew mutinying!", (struct ship *)0);
			on->specs->qual = 5;
D 6
			Write(W_CAPTURED, on, 0, on-SHIP(0), 0, 0, 0);
E 6
I 6
			Write(W_CAPTURED, on, 0, on->file->index, 0, 0, 0);
E 6
E 2
		} else 
D 2
			makesignal("crew demoralized", 0, onship);
		Write(SPECS + onship, 0, 12, ptr -> qual);
E 2
I 2
			makesignal(on, "crew demoralized", (struct ship *)0);
		Write(W_QUAL, on, 0, on->specs->qual, 0, 0, 0);
E 2
	}
I 3
	*/
E 3
	if (!hull)
D 2
		strike(onship, fromship);
E 2
I 2
		strike(on, from);
E 2
}

D 2

cleanfoul(fromship, toship, offset)
int fromship, toship, offset;
E 2
I 2
D 6
cleanfoul(from, to, which)
E 6
I 6
Cleansnag(from, to, all, flag)
E 6
register struct ship *from, *to;
D 6
int which;
E 6
I 6
char all, flag;
E 6
E 2
{
D 2
	register int n = -1;
E 2
I 2
D 6
	register int n;
	register struct snag *s = to->file->fouls;
E 2

D 2
	Write(FILES + fromship, 0, 84 + offset*4, 0);
	do {
		n++;
	} while ((!scene[game].ship[toship].file -> fouls[n].turnfoul || scene[game].ship[toship].file -> fouls[n].toship != fromship) && n < 10);
	if (n < 10)
		Write(FILES + toship, 0, 84 + 4*n, 0);
	if (!grapple(fromship, toship) && !foul(fromship,toship)){
		if (!fouled(fromship) && !grappled(fromship)){
			unboard(fromship,fromship, 1);		/* defense */
			unboard(fromship,fromship, 0);		/* defense */
E 2
I 2
	Write(W_FOUL, from, 0, which, 0, 0, 0);
D 5
	for (n = 0; n < NSHIP && (s->turnfoul || s->toship != from); n++, s++)
E 5
I 5
	for (n = 0; n < NSHIP && (!s->turnfoul || s->toship != from); n++, s++)
E 5
		;
	if (n < NSHIP)
		Write(W_FOUL, to, 0, n, 0, 0, 0);
	if (!snagged2(from, to)) {
		if (!fouled(from) && !grappled(from)) {
			unboard(from, from, 1);		/* defense */
			unboard(from, from, 0);		/* defense */
E 2
		} else
D 2
			unboard(fromship,toship, 0);		/* defense */
		if (!fouled(toship) && !grappled(toship)){	/* defense */
			unboard(toship,toship, 1);
			unboard(toship,toship, 0);
E 2
I 2
			unboard(from, to, 0);		/* defense */
		if (!fouled(to) && !grappled(to)) {	/* defense */
			unboard(to, to, 1);
			unboard(to, to, 0);
E 2
		} else
D 2
			unboard(toship, fromship, 0);			/* offense */
E 2
I 2
			unboard(to, from, 0);		/* offense */
E 6
I 6
	if (flag & 1) {
		Write(W_UNGRAP, from, 0, to->file->index, all, 0, 0);
		Write(W_UNGRAP, to, 0, from->file->index, all, 0, 0);
E 6
E 2
	}
D 6
}

D 2

cleangrapple(fromship, toship, offset)
int fromship, toship, offset;
E 2
I 2
cleangrapple(from, to, which)
register struct ship *from, *to;
int which;
E 2
{
D 2
	register int n = -1;
E 2
I 2
	register int n;
	register struct snag *s = to->file->grapples;
E 2

D 2
	Write(FILES + fromship, 0, 124 + offset*4, 0);
	do {
		n++;
	} while ((!scene[game].ship[toship].file -> grapples[n].turnfoul || scene[game].ship[toship].file -> grapples[n].toship != fromship) && n < 10);
	if (n < 10)
		Write(FILES + toship, 0, 124 + 4*n, 0);
	if (!grapple(fromship, toship) && !foul(fromship,toship)){
		if (!fouled(fromship) && !grappled(fromship)){
			unboard(fromship,fromship, 1);		/* defense */
			unboard(fromship,fromship, 0);		/* defense */
E 2
I 2
	Write(W_GRAP, from, 0, which, 0, 0, 0);
D 5
	for (n = 0; n < NSHIP && (s->turnfoul || s->toship != from); n++, s++)
E 5
I 5
	for (n = 0; n < NSHIP && (!s->turnfoul || s->toship != from); n++, s++)
E 5
		;
	if (n < NSHIP)
D 5
		Write(W_FOUL, to, 0, n, 0, 0, 0);
E 5
I 5
		Write(W_GRAP, to, 0, n, 0, 0, 0);
E 6
I 6
	if (flag & 2) {
		Write(W_UNFOUL, from, 0, to->file->index, all, 0, 0);
		Write(W_UNFOUL, to, 0, from->file->index, all, 0, 0);
	}
E 6
E 5
	if (!snagged2(from, to)) {
D 6
		if (!fouled(from) && !grappled(from)) {
E 6
I 6
		if (!snagged(from)) {
E 6
			unboard(from, from, 1);		/* defense */
			unboard(from, from, 0);		/* defense */
E 2
		} else
D 2
			unboard(fromship,toship, 0);		/* defense */
		if (!fouled(toship) && !grappled(toship)){	/* defense */
			unboard(toship,toship, 1);
			unboard(toship,toship, 0);
E 2
I 2
D 6
			unboard(from, to, 0);		/* defense */
		if (!fouled(to) && !grappled(to)) {	/* defense */
			unboard(to, to, 1);
			unboard(to, to, 0);
E 6
I 6
			unboard(from, to, 0);		/* offense */
		if (!snagged(to)) {
			unboard(to, to, 1);		/* defense */
			unboard(to, to, 0);		/* defense */
E 6
E 2
		} else
D 2
			unboard(toship, fromship, 0);			/* offense */
E 2
I 2
			unboard(to, from, 0);		/* offense */
E 2
	}
}

D 2

strike(shipnum, fromship)
int shipnum, fromship;
E 2
I 2
strike(ship, from)
register struct ship *ship, *from;
E 2
{
	int points;

D 2
	if (!scene[game].ship[shipnum].file -> struck){
		Write(FILES + shipnum, 0, 66, 1);
		points = specs[scene[game].ship[shipnum].shipnum].pts + scene[game].ship[fromship].file -> points;
		Write(FILES + fromship, 0, 20, points);
		unboard(shipnum, shipnum, 0);		/* all offense */
		unboard(shipnum, shipnum, 1);		/* all defense */
		switch(die()){

			case 3:
			case 4:		/* ship may sink */
				Write(FILES + shipnum, 0, 234, 1);
				break;
			case 5:
			case 6:		/* ship may explode */
				Write(FILES + shipnum, 0, 232, 1);
				break;
		}
		Write(FILES + shipnum, 1, 164, "striking her colours!");
E 2
I 2
	if (ship->file->struck)
		return;
	Write(W_STRUCK, ship, 0, 1, 0, 0, 0);
	points = ship->specs->pts + from->file->points;
	Write(W_POINTS, from, 0, points, 0, 0, 0);
	unboard(ship, ship, 0);		/* all offense */
	unboard(ship, ship, 1);		/* all defense */
	switch (die()) {
	case 3:
	case 4:		/* ship may sink */
		Write(W_SINK, ship, 0, 1, 0, 0, 0);
		break;
	case 5:
	case 6:		/* ship may explode */
		Write(W_EXPLODE, ship, 0, 1, 0, 0, 0);
		break;
E 2
	}
I 2
	Write(W_SIGNAL, ship, 1, (int) "striking her colours!", 0, 0, 0);
E 2
}
D 2


E 2
E 1
