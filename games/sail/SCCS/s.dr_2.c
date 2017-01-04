h45642
s 00010/00005/00249
d D 5.3 88/06/18 19:55:18 bostic 16 15
c install approved copyright notice
e
s 00009/00003/00245
d D 5.2 88/03/09 12:30:10 bostic 15 14
c written by David Riggle and Edward Wang; add Berkeley specific copyright
e
s 00005/00005/00243
d D 5.1 85/05/29 15:59:51 dist 14 13
c Add copyright
e
s 00006/00000/00242
d D 2.7 85/04/23 21:46:16 edward 13 12
c copyright message
e
s 00001/00003/00241
d D 2.6 84/04/28 14:32:26 edward 12 11
c fixed drifting in calm sea bug
e
s 00003/00007/00241
d D 2.5 84/01/19 16:02:56 edward 11 10
c Write(CAPTURED) after using it.
e
s 00004/00015/00244
d D 2.4 83/12/17 12:38:22 edward 10 9
c new grapple and foul data structure.
e
s 00005/00003/00254
d D 2.3 83/12/13 11:11:48 edward 9 8
c fixed explode
e
s 00001/00031/00256
d D 2.2 83/12/12 14:14:49 edward 8 7
c no more moveship(), plus small bug in killing a ship in check().
e
s 00000/00000/00287
d D 2.1 83/10/31 13:43:33 edward 7 6
c new version
e
s 00002/00002/00285
d D 1.6 83/10/27 12:57:43 edward 6 5
c fixed drift problem
e
s 00012/00001/00275
d D 1.5 83/10/14 23:07:36 edward 5 4
c lint
e
s 00010/00006/00266
d D 1.4 83/10/10 20:09:56 edward 4 3
c got rid of unnecessary variables
e
s 00006/00003/00266
d D 1.3 83/10/05 11:43:39 edward 3 2
c changed sizes of things and reformated globals.c
e
s 00201/00207/00068
d D 1.2 83/07/20 17:19:46 edward 2 1
c 
e
s 00275/00000/00000
d D 1.1 83/03/17 21:09:09 leres 1 0
c date and time created 83/03/17 21:09:09 by leres
e
u
U
t
T
I 13
/*
D 14
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 14
I 14
 * Copyright (c) 1983 Regents of the University of California.
D 15
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 15
I 15
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 16
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 16
I 16
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
E 16
E 15
E 14
 */

E 13
I 1
#ifndef lint
D 14
static	char *sccsid = "%W% %E%";
#endif
E 14
I 14
static char sccsid[] = "%W% (Berkeley) %G%";
D 15
#endif not lint
E 15
I 15
#endif /* not lint */
E 15
E 14
D 2
#define EXPLODE 5
#include "externs.h"
E 2

D 2
#define couldwin(from, to)	(specs[scene[game].ship[from].shipnum].crew2 > specs[scene[game].ship[to].shipnum].crew2 * 1.5)
E 2
I 2
#include "driver.h"
E 2

I 2
#define couldwin(f,t) (f->specs->crew2 > t->specs->crew2 * 1.5)

E 2
thinkofgrapples()
{
D 2
	register int n, l, friendly;
E 2
I 2
	register struct ship *sp, *sq;
	char friendly;
E 2

D 2
	for (n=0; n < scene[game].vessels; n++){
		if (!scene[game].ship[n].file -> captain[0] && pos[n].dir){
			for (l=0; l < scene[game].vessels; l++){
				if ((friendly = scene[game].ship[l].file -> captured) < 0)
					friendly = scene[game].ship[n].nationality == scene[game].ship[l].nationality;
				else
					friendly = scene[game].ship[n].nationality == scene[game].ship[friendly].nationality;
				if (!friendly){
					if (range(n,l) == 1 && !scene[game].ship[n].file -> struck && scene[game].ship[n].file -> captured < 0){
						if (grapple(n,l))
							if (toughmelee(n,l,0,0))
								ungrap(n, l);
							else
								grap(n, l);
						else if (couldwin(n,l)){
							grap(n, l);
							loadwith[n] = GRAPE;
						}
					}
E 2
I 2
	foreachship(sp) {
		if (sp->file->captain[0] || sp->file->dir == 0)
			continue;
		foreachship(sq) {
			friendly = sp->nationality == capship(sq)->nationality;
			if (!friendly) {
				if (sp->file->struck || sp->file->captured != 0)
					continue;
				if (range(sp, sq) != 1)
					continue;
				if (grappled2(sp, sq))
					if (toughmelee(sp, sq, 0, 0))
						ungrap(sp, sq);
					else
						grap(sp, sq);
				else if (couldwin(sp, sq)) {
					grap(sp, sq);
					sp->file->loadwith = L_GRAPE;
E 2
				}
D 2
				else
					ungrap(n,l);
			}
E 2
I 2
			} else
				ungrap(sp, sq);
E 2
		}
	}
}

D 2

E 2
checkup()
{
D 2
	register int k, n, explode, sink;
E 2
I 2
D 10
	register int k;
E 10
	register struct ship *sp, *sq;
	register char explode, sink;
E 2

I 4
D 8
	/*
E 4
	readpos();
I 4
	*/
E 8
E 4
D 2
	for (n=0; n < scene[game].vessels; n++){
		explode = scene[game].ship[n].file -> explode;
		sink = scene[game].ship[n].file -> sink;
		if (die() >= 5 && (explode == 1 || sink == 1)){
			explode = 2;
			if (sink != 1)
				Write(FILES + n, 0, 232, explode);
			else
				Write(FILES + n, 0, 234, explode);
			pos[n].dir = 0;	/* hopefully enough to kill ship */
			Write(n, 0, 10, 0);
			if (fouled(n) || grappled(n)){
				for (k=0; k < 10; k++){
					if (scene[game].ship[n].file -> fouls[k].turnfoul)
						cleanfoul(n,scene[game].ship[n].file -> fouls[k].toship,k);
				}
				for (k=0; k < 10; k++){
					if (scene[game].ship[n].file -> grapples[k].turnfoul)
						cleangrapple(n,scene[game].ship[n].file -> grapples[k].toship,k);
				}
E 2
I 2
	foreachship(sp) {
I 9
		if (sp->file->dir == 0)
			continue;
E 9
		explode = sp->file->explode;
		sink = sp->file->sink;
D 9
		if (die() < 5)
			continue;
E 9
		if (explode != 1 && sink != 1)
			continue;
D 9
		Write(sink ? W_SINK : W_EXPLODE, sp, 0, 2, 0, 0, 0);
E 9
I 9
		if (die() < 5)
			continue;
		Write(sink == 1 ? W_SINK : W_EXPLODE, sp, 0, 2, 0, 0, 0);
E 9
D 8
		sp->file->dir = 0;	/* hopefully enough to kill ship */
		/* Write(n, 0, 10, 0); XXX */
		Write(W_CLASS, sp, 0, 0, 0, 0, 0);
E 8
I 8
D 10
		Write(W_SHIPDIR, sp, 0, 0, 0, 0, 0);
E 8
		if (fouled(sp) || grappled(sp)) {
			for (k = 0; k < NSHIP; k++) {
				if (sp->file->fouls[k].turnfoul)
					cleanfoul(sp,
						sp->file->fouls[k].toship, k);
E 2
			}
D 2
			if (sink != 1){
				makesignal("exploding!", 0, n);
				for (k=0; k < scene[game].vessels; k++)
					if (k != n && pos[k].dir && range(n,k) < 4)
						table(RIGGING, EXPLODE, specs[scene[game].ship[n].shipnum].guns/13, k, n, 6);
E 2
I 2
			for (k = 0; k < NSHIP; k++) {
				if (sp->file->grapples[k].turnfoul)
					cleangrapple(sp,
						sp->file->grapples[k].toship,
						k);
E 2
			}
D 2
			else {
				makesignal("sinking!", 0, n);
			}
E 2
		}
E 10
I 10
		Write(W_DIR, sp, 0, 0, 0, 0, 0);
		if (snagged(sp))
			foreachship(sq)
				cleansnag(sp, sq, 1);
E 10
I 2
		if (sink != 1) {
			makesignal(sp, "exploding!", (struct ship *)0);
			foreachship(sq) {
				if (sp != sq && sq->file->dir && range(sp, sq) < 4)
					table(RIGGING, L_EXPLODE, sp->specs->guns/13, sq, sp, 6);
			}
		} else
			makesignal(sp, "sinking!", (struct ship *)0);
E 2
	}
}

prizecheck()
{
D 2
	register int n, captured, pc, prisoners, points;
	struct shipspecs *ptr;
	struct File *ptr1;
E 2
I 2
	register struct ship *sp;
D 11
	register int prisoners, points;
E 11
E 2

D 2
	for (n=0; n < scene[game].vessels; n++){
		ptr1 = scene[game].ship[n].file;
		if ((captured = ptr1 -> captured) > -1 && !scene[game].ship[n].file -> struck && pos[n].dir){
			ptr = &specs[scene[game].ship[n].shipnum];
			points = scene[game].ship[captured].file -> points;
			prisoners = ptr -> crew1 + ptr -> crew2 + ptr -> crew3;
			if (prisoners > ptr1 -> pcrew * 6){
				Write(FILES + n, 0, 68,-1);
				points -= 2 * ptr -> pts;
				Write(FILES + n, 1, 164, "prize crew overthrown");
				Write(FILES + captured, 0, 20, points);
			}
E 2
I 2
	foreachship(sp) {
		if (sp->file->captured == 0)
			continue;
		if (sp->file->struck || sp->file->dir == 0)
			continue;
D 11
		prisoners = sp->specs->crew1 + sp->specs->crew2 + sp->specs->crew3;
		if (prisoners > sp->file->pcrew * 6) {
			Write(W_CAPTURED, sp, 0, -1, 0, 0, 0);
E 11
I 11
		if (sp->specs->crew1 + sp->specs->crew2 + sp->specs->crew3 > sp->file->pcrew * 6) {
E 11
			Write(W_SIGNAL, sp, 1,
				(int)"prize crew overthrown", 0, 0, 0);
D 11
			points = sp->file->captured->file->points
				- 2 * sp->specs->pts;
			Write(W_POINTS, sp->file->captured, 0, points, 0, 0, 0);
E 11
I 11
			Write(W_POINTS, sp->file->captured, 0, sp->file->captured->file->points - 2 * sp->specs->pts, 0, 0, 0);
			Write(W_CAPTURED, sp, 0, -1, 0, 0, 0);
E 11
E 2
		}
	}
}

D 2
char strend(str)
E 2
I 2
strend(str)
E 2
char *str;
{
D 2
	register int n;
E 2
I 2
	register char *p;
E 2

D 2
	for (n=0; *(str+n); n++);
	return( n ? *(str + n -1) : 0);
E 2
I 2
	for (p = str; *p; p++)
		;
	return p == str ? 0 : p[-1];
E 2
}

D 2

closeon(fromship, toship, command, ta, ma, af)
int fromship, toship, ma, ta, af;
char command[10];
E 2
I 2
closeon(from, to, command, ta, ma, af)
register struct ship *from, *to;
char command[];
int ma, ta, af;
E 2
{
	int high;
	char temp[10];

	temp[0] = command[0] = '\0';
	high = -30000;
D 2
	try(command, temp, ma, ta, af, ma, pos[fromship].dir, fromship, toship, &high, 0);
E 2
I 2
	try(command, temp, ma, ta, af, ma, from->file->dir, from, to, &high, 0);
E 2
}

D 2
int dtab[8] = {0,1,1,2,3,4,4,5};	/* diagonal distances in x==y */
E 2
I 2
int dtab[] = {0,1,1,2,3,4,4,5};		/* diagonal distances in x==y */
E 2

D 2
score(movement,shipnum, toship, permanent, onlytemp)
int shipnum, toship, permanent, onlytemp;
char movement[10];
E 2
I 2
score(movement, ship, to, onlytemp)
char movement[];
register struct ship *ship, *to;
char onlytemp;
E 2
{
D 2
	int drift, row, col, dir, n, dist, total, ran;
	int dr = 0, dc = 0;
E 2
I 2
D 3
	int drift, row, col, dir, total, ran;
E 3
I 3
	char drift;
	int row, col, dir, total, ran;
E 3
	register struct File *fp = ship->file;
E 2

D 2
	if (dir = pos[shipnum].dir){
		row = pos[shipnum].row;
		col = pos[shipnum].col;
		for (n=0; movement[n]; n++)
			switch(movement[n]){
				case 'r':
					if ((++pos[shipnum].dir) == 9)
						pos[shipnum].dir = 1;
					break;
				case 'l':
					if (!(--pos[shipnum].dir))
						pos[shipnum].dir = 8;
					break;
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
					drdc(&dr, &dc, pos[shipnum].dir);
					if (!(pos[shipnum].dir % 2))
						dist = dtab[movement[n] - '0'];
					else
						dist = movement[n] - '0';
					pos[shipnum].row -= dr * dist;
					pos[shipnum].col -= dc * dist;
					dr = dc = 0;
					break;
			}
		drift = scene[game].ship[shipnum].file -> drift;
		if (!windspeed) drift = 1;
		if (row == pos[shipnum].row && col == pos[shipnum].col){
			drift++;
			if (drift > 2){
				drdc(&dr, &dc, winddir);
				dist = 1 - ((specs[scene[game].ship[shipnum].shipnum].class < 3 || fouled(shipnum) || grappled(shipnum)) && turn % 2);
				pos[shipnum].row -= dr * dist;
				pos[shipnum].col -= dc * dist;
				if (permanent)
					strcat(movement, "d");
			}
E 2
I 2
	if ((dir = fp->dir) == 0)
		return 0;
	row = fp->row;
	col = fp->col;
	drift = fp->drift;
	move(movement, ship, &fp->dir, &fp->row, &fp->col, &drift);
	if (!*movement)
		(void) strcpy(movement, "d");

	ran = range(ship, to);
	total = -50 * ran;
	if (ran < 4 && gunsbear(ship, to))
		total += 60;
	if ((ran = portside(ship, to, 1) - fp->dir) == 4 || ran == -4)
		total = -30000;

	if (!onlytemp) {
		fp->row = row;
		fp->col = col;
		fp->dir = dir;
	}
	return total;
D 8
}

moveship(ship, movement)
struct ship *ship;
char *movement;
{
D 3
	int drift;
E 3
I 3
D 4
	char drift;
E 4
E 3
	register struct File *fp = ship->file;
I 4
D 5
	int drift = fp->drift;
E 5
I 5
	char drift = fp->drift;
E 5
	int row = fp->row;
	int col = fp->col;
	int dir = fp->dir;
E 4

	if (fp->dir == 0)
		return;
D 4
	drift = fp->drift;
E 4
	move(movement, ship, &fp->dir, &fp->row, &fp->col, &drift);
	if (drift > 2 || *movement == 0)
		(void) strcat(movement, "d");
D 4
	if (drift != fp->drift)
E 4
I 4
	if (fp->drift != drift)
E 4
		Write(W_DRIFT, ship, 0, drift, 0, 0, 0);
D 4
	if (fp->row != ship->shiprow)
E 4
I 4
	if (fp->row != row)
E 4
		Write(W_SHIPROW, ship, 0, fp->row, 0, 0, 0);
D 4
	if (fp->col != ship->shipcol)
E 4
I 4
	if (fp->col != col)
E 4
		Write(W_SHIPCOL, ship, 0, fp->col, 0, 0, 0);
D 4
	if (fp->dir != ship->shipdir)
E 4
I 4
	if (fp->dir != dir)
E 4
		Write(W_SHIPDIR, ship, 0, fp->dir, 0, 0, 0);
E 8
}

move(p, ship, dir, row, col, drift)
register char *p;
register struct ship *ship;
D 3
register int *dir, *row, *col, *drift;
E 3
I 3
register char *dir;
register short *row, *col;
register char *drift;
E 3
{
	int dist;
	char moved = 0;

	for (; *p; p++) {
		switch (*p) {
		case 'r':
			if (++*dir == 9)
				*dir = 1;
			break;
		case 'l':
			if (--*dir == 0)
				*dir = 8;
			break;
		case '1': case '2': case '3': case '4':
		case '5': case '6': case '7':
			moved++;
			if (*dir % 2 == 0)
				dist = dtab[*p - '0'];
			else
				dist = *p - '0';
			*row -= dr[*dir] * dist;
			*col -= dc[*dir] * dist;
			break;
E 2
		}
D 2
		else
			drift = 0;
		ran = range(shipnum, toship);
		total = -50*ran;
		if (ran < 4 && gunsbear(shipnum, toship))
			total += 60;
		if ((ran = portside(shipnum, toship, 1) - pos[shipnum].dir) == 4 || ran == -4)
			total = -30000;
		if (!*movement) strcpy(movement, "d");
		if (permanent){
			if (drift != scene[game].ship[shipnum].file -> drift)
				Write(FILES + shipnum, 0, 82, drift);
			if (pos[shipnum].row != scene[game].ship[shipnum].shiprow)
				Write(shipnum, 0, 6, pos[shipnum].row);
			if (pos[shipnum].col != scene[game].ship[shipnum].shipcol)
				Write(shipnum, 0, 8, pos[shipnum].col);
			if (pos[shipnum].dir != scene[game].ship[shipnum].shipdir)
				Write(shipnum, 0, 10, pos[shipnum].dir);
		}
		if (!onlytemp){
			pos[shipnum].row = row;
			pos[shipnum].col = col;
			pos[shipnum].dir = dir;
		}
		return(total);
E 2
	}
D 2
	return(0);
E 2
I 2
D 12
	if (!windspeed)
		*drift = 1;
E 12
	if (!moved) {
D 12
		if (++*drift > 2) {
E 12
I 12
		if (windspeed != 0 && ++*drift > 2) {
E 12
			if (ship->specs->class >= 3 && !snagged(ship)
D 6
			    || turn % 2 == 0) {
E 6
I 6
			    || (turn & 1) == 0) {
E 6
				*row -= dr[winddir];
				*col -= dc[winddir];
			}
		}
	} else
D 6
		drift = 0;
E 6
I 6
		*drift = 0;
E 6
E 2
}

D 2
try(command, temp,ma, ta, af, vma, dir, shipnum, toship, high, rakeme)
int ma, ta, af, shipnum, toship, *high, rakeme;
char command[10], temp[10];
E 2
I 2
try(command, temp, ma, ta, af, vma, dir, f, t, high, rakeme)
register struct ship *f, *t;
int ma, ta, af, *high, rakeme;
char command[], temp[];
E 2
{
	register int new, n;
	char st[4];
I 2
#define rakeyou (gunsbear(f, t) && !gunsbear(t, f))
E 2

	if ((n = strend(temp)) < '1' || n > '9')
D 2
		for(n = 1; vma - n >= 0; n++){
			sprintf(st, "%d", n);
			strcat(temp, st);
			new = score(temp, shipnum, toship, 0, rakeme);
			if (new > *high && (!rakeme || (gunsbear(shipnum, toship) && !gunsbear(toship, shipnum)))){
E 2
I 2
		for (n = 1; vma - n >= 0; n++) {
			(void) sprintf(st, "%d", n);
			(void) strcat(temp, st);
			new = score(temp, f, t, rakeme);
			if (new > *high && (!rakeme || rakeyou)) {
E 2
				*high = new;
D 2
				strcpy(command, temp);
E 2
I 2
				(void) strcpy(command, temp);
E 2
			}
D 2
			try(command, temp, ma-n, ta, af, vma-n, dir, shipnum, toship, high, rakeme);
E 2
I 2
			try(command, temp, ma-n, ta, af, vma-n,
				dir, f, t, high, rakeme);
E 2
			rmend(temp);
		}
D 2
	if ((ma > 0 && ta > 0 && (n = strend(temp)) != 'l' && n != 'r') || !lengthof(temp)){
		strcat(temp, "r");
		new = score(temp, shipnum, toship, 0, rakeme);
		if (new > *high && (!rakeme || (gunsbear(shipnum, toship) && !gunsbear(toship, shipnum)))){
E 2
I 2
	if (ma > 0 && ta > 0 && (n = strend(temp)) != 'l' && n != 'r' || !strlen(temp)) {
		(void) strcat(temp, "r");
		new = score(temp, f, t, rakeme);
		if (new > *high && (!rakeme || gunsbear(f, t) && !gunsbear(t, f))) {
E 2
			*high = new;
D 2
			strcpy(command, temp);
E 2
I 2
			(void) strcpy(command, temp);
E 2
		}
D 2
		try(command, temp, ma-1, ta-1, af, (min(ma-1,maxmove(shipnum, (dir == 8 ? 1 : dir+1), 0))), (dir == 8 ? 1 : dir+1),shipnum,toship,high,rakeme);
E 2
I 2
		try(command, temp, ma-1, ta-1, af, min(ma-1, maxmove(f, (dir == 8 ? 1 : dir+1), 0)), (dir == 8 ? 1 : dir+1),f,t,high,rakeme);
E 2
		rmend(temp);
	}
D 2
	if ((ma > 0 && ta > 0 && (n = strend(temp)) != 'l' && n != 'r') || !lengthof(temp)){
		strcat(temp, "l");
		new = score(temp, shipnum, toship, 0, rakeme);
		if (new > *high && (!rakeme || (gunsbear(shipnum, toship) && !gunsbear(toship, shipnum)))){
E 2
I 2
	if ((ma > 0 && ta > 0 && (n = strend(temp)) != 'l' && n != 'r') || !strlen(temp)){
		(void) strcat(temp, "l");
		new = score(temp, f, t, rakeme);
		if (new > *high && (!rakeme || (gunsbear(f, t) && !gunsbear(t, f)))){
E 2
			*high = new;
D 2
			strcpy(command, temp);
E 2
I 2
			(void) strcpy(command, temp);
E 2
		}
D 2
		try(command, temp, ma-1, ta-1, af, (min(ma-1,maxmove(shipnum, (dir-1 ? dir-1 : 8), 0))), (dir-1 ? dir -1 : 8), shipnum, toship, high, rakeme);
E 2
I 2
		try(command, temp, ma-1, ta-1, af, (min(ma-1,maxmove(f, (dir-1 ? dir-1 : 8), 0))), (dir-1 ? dir -1 : 8), f, t, high, rakeme);
E 2
		rmend(temp);
	}
I 5
}

rmend(str)
char *str;
{
	register char *p;

	for (p = str; *p; p++)
		;
	if (p != str)
		*--p = 0;
E 5
}
D 2


closestenemy(fromship, side, anyship) /*returns the NUMBER of the closest ship*/
int fromship; 
char side, anyship;
{
	register int n, olddist = 30000, ident, captured;
	register int dist, eclosest = 30000;

	if ((ident = scene[game].ship[fromship].file -> captured) < 0)
		ident = fromship;
	for (n=0; n < scene[game].vessels; n++){
		if ((captured = scene[game].ship[n].file -> captured) < 0)
			captured = n;
		if (n != fromship && pos[n].dir && (scene[game].ship[ident].nationality != scene[game].ship[captured].nationality || anyship)){
			if (!side || gunsbear(fromship, n) == side){
				dist = range(fromship, n);
				if (dist < olddist){
					eclosest = n;
					olddist = dist;
				}
			}
		}
	}
	return(eclosest);
}

choke()
{
}

E 2
E 1
