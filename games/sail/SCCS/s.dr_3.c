h04139
s 00010/00005/00320
d D 5.3 88/06/18 19:55:19 bostic 20 19
c install approved copyright notice
e
s 00009/00003/00316
d D 5.2 88/03/09 12:30:12 bostic 19 18
c written by David Riggle and Edward Wang; add Berkeley specific copyright
e
s 00005/00005/00314
d D 5.1 85/05/29 16:00:25 dist 18 17
c Add copyright
e
s 00006/00000/00313
d D 2.7 85/04/23 21:46:49 edward 17 16
c copyright message
e
s 00001/00001/00312
d D 2.6 84/04/28 14:32:35 edward 16 15
c fixed drifting in calm sea bug
e
s 00005/00005/00308
d D 2.5 84/01/19 16:03:20 edward 15 14
c wrong args to WRITE(OBP)
e
s 00021/00029/00292
d D 2.4 83/12/17 12:38:30 edward 14 13
c new grapple and foul data structure.
e
s 00081/00100/00240
d D 2.3 83/12/12 14:39:50 edward 13 12
c moveall() reworked.
e
s 00001/00017/00339
d D 2.2 83/11/01 17:34:52 edward 12 11
c push gone.
e
s 00000/00000/00356
d D 2.1 83/10/31 13:43:39 edward 11 10
c new version
e
s 00015/00008/00341
d D 1.6 83/10/14 20:53:39 edward 10 9
c collision bug fix
e
s 00004/00005/00345
d D 1.5 83/10/10 20:10:05 edward 9 8
c got rid of unnecessary variables
e
s 00268/00216/00082
d D 1.4 83/07/20 17:20:32 edward 8 7
c 
e
s 00002/00001/00296
d D 1.3 83/05/20 17:42:24 root 7 6
c merge
e
s 00006/00003/00291
d D 1.2 83/05/19 22:32:11 leres 6 1
c Fun and games; assembler doesn't like ta or af to be registers in
c moveall().
e
s 00005/00001/00293
d R 1.2 83/05/19 22:22:12 leres 5 1
c Assembler doesn't like at or af to be register in moveall()
e
s 00005/00001/00293
d R 1.2 83/05/19 22:18:07 leres 4 1
c Assembler doesn't like ta to be a register in moveall()
e
s 00006/00002/00292
d R 1.2 83/05/19 22:14:09 leres 3 1
c Assembler doesn't like to to be a register in moveall()
e
s 00002/00001/00293
d R 1.2 83/05/19 22:02:18 leres 2 1
c Assembler doesn't like ta to be a regiester in moveall()
e
s 00294/00000/00000
d D 1.1 83/03/17 21:09:12 leres 1 0
c date and time created 83/03/17 21:09:12 by leres
e
u
U
t
T
I 17
/*
D 18
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 18
I 18
 * Copyright (c) 1983 Regents of the University of California.
D 19
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 19
I 19
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 20
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 20
I 20
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
E 20
E 19
E 18
 */

E 17
I 1
#ifndef lint
D 18
static	char *sccsid = "%W% %E%";
#endif
E 18
I 18
static char sccsid[] = "%W% (Berkeley) %G%";
D 19
#endif not lint
E 19
I 19
#endif /* not lint */
E 19
E 18
D 8
#include "externs.h"
E 8

D 8
extern int dtab[];
E 8
I 8
#include "driver.h"
E 8

moveall()		/* move all comp ships */
{
D 6
	register int n, k, l, m, ta, ma, af, closest, weakest[5];
E 6
I 6
D 7
	register int n, k, l, m, ma, closest, weakest[5];
E 7
I 7
D 8
	register int n, k, l, m, ma, closest;
	int weakest[5];
E 7
	int ta, af, jj;
E 6
	char command[10], clast[20][10];
	int row[20], col[20], dir[20], r1, r2, c1, c2, d1, d2;
	struct File *ptr;
E 8
I 8
	register struct ship *sp, *sq;		/* r11, r10 */
	register int n;				/* r9 */
D 13
	struct ship *closest;
	register int k, l, m, ma;		/* r8, r7, r6, */
D 9
	int ta, af;
E 9
I 9
	int ta;
	char af;
E 9
	int row[NSHIP], col[NSHIP], dir[NSHIP], r1, r2, c1, c2, d1, d2;
	char clast[NSHIP][sizeof SHIP(0)->file->last];
E 13
I 13
D 14
	register int k, l, m;			/* r8, r7, r6, */
E 14
I 14
	register int k, l;			/* r8, r7 */
E 14
	int row[NSHIP], col[NSHIP], dir[NSHIP], drift[NSHIP];
	char moved[NSHIP];
E 13
E 8

D 8
	for (n=0; n < scene[game].vessels; n++){
		ptr = scene[game].ship[n].file;
		if (!ptr -> captain[0] && scene[game].ship[n].shipdir){
				
			if (!ptr -> struck && windspeed && !grappled(n) && !fouled(n) && specs[scene[game].ship[n].shipnum].crew3){
				ta = maxturns(n);
D 6
				af = ta & 0100000;
				ta &= 077777;
E 6
I 6
				jj = 0100000;
				af = ta & jj;
				jj = 077777;
				ta = ta & jj;
E 6
				ma = maxmove(n, pos[n].dir, 0);
				closest = closestenemy(n, 0, 0);
				if (closest == 30000) 
					command[0] = '\0';
				else
					closeon(n, closest, command, ta, ma, af);
			}
E 8
I 8
	/*
	 * first try to create moves for OUR ships
	 */
	foreachship(sp) {
I 13
		struct ship *closest;
		int ma, ta;
		char af;

E 13
D 9
		if (sp->file->captain[0] || sp->shipdir == 0)
E 9
I 9
		if (sp->file->captain[0] || sp->file->dir == 0)
E 9
			continue;
		if (!sp->file->struck && windspeed && !snagged(sp)
		    && sp->specs->crew3) {
D 9
			ta = maxturns(sp);
			af = ta & 0100000;
			ta &= 077777;
E 9
I 9
			ta = maxturns(sp, &af);
E 9
			ma = maxmove(sp, sp->file->dir, 0);
			closest = closestenemy(sp, 0, 0);
			if (closest == 0)
D 14
				*sp->file->last = '\0';
E 14
I 14
				*sp->file->movebuf = '\0';
E 14
E 8
			else
D 8
				command[0] = '\0';
			strcpy(ptr -> last, command);
		}
E 8
I 8
D 14
				closeon(sp, closest, sp->file->last,
E 14
I 14
				closeon(sp, closest, sp->file->movebuf,
E 14
					ta, ma, af);
		} else
D 14
			*sp->file->last = '\0';
E 14
I 14
			*sp->file->movebuf = '\0';
E 14
I 10
D 13
		/*
		makesignal(sp, "move (%d): %s", 0, turn, sp->file->last);
		*/
E 13
E 10
E 8
	}
D 8
	for (n=0; n < scene[game].vessels; n++){
		strcpy(clast[n], scene[game].ship[n].file -> last);
		if (fouled(n) || grappled(n))
E 8
I 8
	/*
	 * Then execute the moves for ALL ships (dead ones too),
D 13
	 * saving old positions in row[], col[], dir[],
	 * and the moves in clase[][].
	 * The new positions are written out.
E 13
I 13
	 * checking for collisions and snags at each step.
	 * The old positions are saved in row[], col[], dir[].
	 * At the end, we compare and write out the changes.
E 13
	 */
	n = 0;
	foreachship(sp) {
		if (snagged(sp))
E 8
D 13
			clast[n][0] = '\0';
E 13
I 13
D 14
			strcpy(sp->file->last, "d");
E 14
I 14
			(void) strcpy(sp->file->movebuf, "d");
E 14
E 13
D 8
		row[n] = pos[n].row;
		col[n] = pos[n].col;
		dir[n] = pos[n].dir;
		score(clast[n],n, 0, 1, 0);
E 8
I 8
		else
D 13
			(void) strcpy(clast[n], sp->file->last);
E 13
I 13
D 14
			if (*sp->file->last != 'd')
				strcat(sp->file->last, "d");
E 14
I 14
			if (*sp->file->movebuf != 'd')
				(void) strcat(sp->file->movebuf, "d");
E 14
E 13
		row[n] = sp->file->row;
		col[n] = sp->file->col;
		dir[n] = sp->file->dir;
D 13
		moveship(sp, clast[n]);
E 13
I 13
		drift[n] = sp->file->drift;
		moved[n] = 0;
E 13
		n++;
E 8
	}
D 8
	for (k=0; stillmoving(clast, k); k++){
		for (n=0; n < scene[game].vessels; n++){
E 8
I 8
	/*
	 * Now resolve collisions.
	 * This is the tough part.
	 */
D 13
	for (k = 0; stillmoving(clast, k); k++) {
E 13
I 13
	for (k = 0; stillmoving(k); k++) {
E 13
		/*
		 * Step once.
D 13
		 * And propagate the nulls at the end of clast[].
E 13
I 13
D 14
		 * And propagate the nulls at the end of sp->file->last.
E 14
I 14
		 * And propagate the nulls at the end of sp->file->movebuf.
E 14
E 13
		 */
		n = 0;
		foreachship(sp) {
E 8
D 13
			if (dir[n])
D 8
				step(clast[n][k], n, row, col, dir);
E 8
I 8
				step(clast[n][k], sp, row+n, col+n, dir+n);
E 8
			if (!clast[n][k])
				clast[n][k+1] = '\0';
E 13
I 13
D 14
			if (!sp->file->last[k])
				sp->file->last[k+1] = '\0';
E 14
I 14
			if (!sp->file->movebuf[k])
				sp->file->movebuf[k+1] = '\0';
E 14
			else if (sp->file->dir)
D 14
				step(sp->file->last[k], sp, &moved[n]);
E 14
I 14
				step(sp->file->movebuf[k], sp, &moved[n]);
E 14
E 13
I 8
			n++;
E 8
		}
D 8
		for (n=0; n < scene[game].vessels; n++){
			if ((d1 = pos[n].dir) && !isolated(n)){
				r1 = pos[n].row;
				c1 = pos[n].col;
				pos[n].dir = dir[n];
				pos[n].row = row[n];
				pos[n].col = col[n];
				for (l=0; l < scene[game].vessels; l++){
					if (d2 = pos[l].dir && l != n){
						r2 = pos[l].row;
						c2 = pos[l].col;
						pos[l].dir = dir[l];
						pos[l].row = row[l];
						pos[l].col = col[l];
						if ((foul(n,l) || grapple(n,l)) && push(n,l) && range(n,l) > 1){
							Write(l,0,6,pos[n].row-1);
							if (pos[n].dir == 1 || pos[n].dir == 5)
								Write(l,0,8,pos[n].col-1);
							else
								Write(l,0,8,pos[n].col);
							Write(l,0,10,pos[n].dir);
						}
						if (!range(n,l) && !foul(n,l) && push(n,l)){
							makesignal("collision with %s (%c%c)", l, n);
							if (die() < 4){
								makesignal("fouled with %s (%c%c)", l, n);
								for (m=0;scene[game].ship[n].file -> fouls[m].turnfoul && m < 10; m++);
								if (m < 10){
									Write(FILES + n, 0, 84 + m*4, turn);
									Write(FILES + n, 0, 84 + m*4 + 2, l);
								}
								for (m=0;scene[game].ship[l].file -> fouls[m].turnfoul && m < 10; m++);
								if (m < 10){
									Write(FILES + l, 0, 84 + m*4, turn);
									Write(FILES + l, 0, 84 + m*4 + 2, n);
								}
							}
							clast[n][k+1] = '\0';
							pos[n].row = r2;
							pos[n].col = c2;
							pos[n].dir = d2;
							score(clast[n],n,n,1,0);
							Write(l,0,6,pos[n].row-1);
							if (pos[n].dir == 1 || pos[n].dir == 5)
								Write(l,0,8,pos[n].col-1);
							else
								Write(l,0,8,pos[n].col);
							Write(l,0,10,pos[n].dir);
							Write(FILES + l, 0, 82, 0);
							Write(FILES + n, 0, 82, 0);
						}
						else {
							pos[l].row = r2;
							pos[l].col = c2;
							pos[l].dir = d2;
						}
E 8
I 8
		/*
		 * The real stuff.
		 */
		n = 0;
		foreachship(sp) {
D 13
			if ((d1 = sp->file->dir) == 0 || isolated(sp))
E 13
I 13
			if (sp->file->dir == 0 || isolated(sp))
E 13
D 10
				continue;
E 10
I 10
				goto cont1;
E 10
D 13
			r1 = sp->file->row;
			c1 = sp->file->col;
			sp->file->dir = dir[n];
			sp->file->row = row[n];
			sp->file->col = col[n];
E 13
			l = 0;
			foreachship(sq) {
I 13
				char snap = 0;

E 13
D 10
				if ((d2 = sq->file->dir) == 0 || sp == sq)
					continue;
E 10
I 10
				if (sp == sq)
					goto cont2;
D 13
				if ((d2 = sq->file->dir) == 0)
E 13
I 13
				if (sq->file->dir == 0)
E 13
					goto cont2;
E 10
D 13
				r2 = sq->file->row;
				c2 = sq->file->col;
				sq->file->dir = dir[l];
				sq->file->row = row[l];
				sq->file->col = col[l];
D 10
				if (grappled2(sp, sq)
E 10
I 10
				if (snagged2(sp, sq)
E 10
				    && push(sp, sq) && range(sp, sq) > 1) {
					Write(W_SHIPROW, sq, 0,
						sp->file->row - 1, 0, 0, 0);
					if (sp->file->dir == 1
D 12
					    || sp->file->dir == 5) /* XXX */
E 12
I 12
					    || sp->file->dir == 5)
E 12
						Write(W_SHIPCOL, sq, 0,
							sp->file->col - 1,
							0, 0, 0);
					else
						Write(W_SHIPCOL, sq, 0,
							sp->file->col, 0, 0, 0);
					Write(W_SHIPDIR, sq, 0,
						sp->file->dir, 0, 0, 0);
				}
				if (!range(sp, sq) && !fouled2(sp, sq)
				    && push(sp, sq)) {
E 13
I 13
				if (!push(sp, sq))
					goto cont2;
				if (snagged2(sp, sq) && range(sp, sq) > 1)
					snap++;
				if (!range(sp, sq) && !fouled2(sp, sq)) {
E 13
					makesignal(sp,
						"collision with %s (%c%c)", sq);
					if (die() < 4) {
						makesignal(sp,
							"fouled with %s (%c%c)",
							sq);
D 14
						for (m = 0; m < NSHIP && sp->file->fouls[m].turnfoul; m++)
							;
						if (m < NSHIP)
							Write(W_FOUL, sp, 0,
								m, turn, l, 0);
						for (m = 0; m < NSHIP && sq->file->fouls[m].turnfoul; m++)
							;
						if (m < NSHIP)
							Write(W_FOUL, sq, 0,
								m, turn, n, 0);
E 14
I 14
						Write(W_FOUL, sp, 0, l, 0, 0, 0);
						Write(W_FOUL, sq, 0, n, 0, 0, 0);
E 14
E 8
					}
I 8
D 13
					clast[n][k+1] = '\0';
					sp->file->row = r2;
					sp->file->col = c2;
					sp->file->dir = d2;
					moveship(sp, clast[n]);
					Write(W_SHIPROW, sq, 0,
						sp->file->row-1, 0, 0, 0);
E 13
I 13
					snap++;
				}
				if (snap) {
D 14
					sp->file->last[k + 1] = 0;
					sq->file->last[k + 1] = 0;
E 14
I 14
					sp->file->movebuf[k + 1] = 0;
					sq->file->movebuf[k + 1] = 0;
E 14
					sq->file->row = sp->file->row - 1;
E 13
					if (sp->file->dir == 1
					    || sp->file->dir == 5)
D 13
						Write(W_SHIPCOL, sq, 0,
							sp->file->col-1, 0, 0, 0);
E 13
I 13
						sq->file->col =
							sp->file->col - 1;
E 13
					else
D 13
						Write(W_SHIPCOL, sq, 0,
							sp->file->col, 0, 0, 0);
					Write(W_SHIPDIR, sq, 0,
						sp->file->dir, 0, 0, 0);
					Write(W_DRIFT, sq, 0, 0, 0, 0, 0);
					Write(W_DRIFT, sp, 0, 0, 0, 0, 0);
D 10
				} else {
					sq->file->row = r2;
					sq->file->col = c2;
					sq->file->dir = d2;
E 10
I 10
					goto cont2;
E 13
I 13
						sq->file->col = sp->file->col;
					sq->file->dir = sp->file->dir;
E 13
E 10
E 8
				}
I 10
D 13
				sq->file->row = r2;
				sq->file->col = c2;
				sq->file->dir = d2;
E 13
			cont2:
E 10
D 8
				pos[n].row = r1;
				pos[n].col = c1;
				pos[n].dir = d1;
E 8
I 8
				l++;
E 8
			}
I 8
D 13
			sp->file->row = r1;
			sp->file->col = c1;
			sp->file->dir = d1;
E 13
I 10
		cont1:
E 10
			n++;
E 8
		}
	}
D 8
	for(n=0; n < scene[game].vessels; n++)
		scene[game].ship[n].file -> last[0] = NULL;
E 8
I 8
	/*
D 13
	 * Clear old moves.
E 13
I 13
	 * Clear old moves.  And write out new pos.
E 13
	 */
D 13
	foreachship(sp)
		sp->file->last[0] = 0;
E 13
I 13
	n = 0;
	foreachship(sp) {
		if (sp->file->dir != 0) {
D 14
			*sp->file->last = 0;
E 14
I 14
			*sp->file->movebuf = 0;
E 14
			if (row[n] != sp->file->row)
D 14
				Write(W_SHIPROW, sp, 0, sp->file->row, 0, 0, 0);
E 14
I 14
				Write(W_ROW, sp, 0, sp->file->row, 0, 0, 0);
E 14
			if (col[n] != sp->file->col)
D 14
				Write(W_SHIPCOL, sp, 0, sp->file->col, 0, 0, 0);
E 14
I 14
				Write(W_COL, sp, 0, sp->file->col, 0, 0, 0);
E 14
			if (dir[n] != sp->file->dir)
D 14
				Write(W_SHIPDIR, sp, 0, sp->file->dir, 0, 0, 0);
E 14
I 14
				Write(W_DIR, sp, 0, sp->file->dir, 0, 0, 0);
E 14
			if (drift[n] != sp->file->drift)
				Write(W_DRIFT, sp, 0, sp->file->drift, 0, 0, 0);
		}
		n++;
	}
E 13
E 8
}

D 13
stillmoving(last, k)
D 8
register char last[20][10];
E 8
I 8
char last[][sizeof SHIP(0)->file->last];	/* how's that for portability */
E 13
I 13
stillmoving(k)
E 13
E 8
register int k;
{
D 8
	register int n;
E 8
I 8
	register struct ship *sp;
D 13
	register char (*p)[sizeof *last];	/* and this? */
E 13
E 8

D 8
	for (n=0; n < scene[game].vessels; n++)
		if (last[n][k]) return(1);
	return(0);
E 8
I 8
D 13
	p = last;
	foreachship(sp) {
		if ((*p)[k])
E 13
I 13
	foreachship(sp)
D 14
		if (sp->file->last[k])
E 14
I 14
		if (sp->file->movebuf[k])
E 14
E 13
			return 1;
D 13
		p++;
	}
E 13
	return 0;
E 8
}

isolated(ship)
D 8
register int ship;
E 8
I 8
register struct ship *ship;
E 8
{
D 8
	register int n;
E 8
I 8
	register struct ship *sp;
E 8

D 8
	for (n=0; n < scene[game].vessels; n++)
		if (ship != n && range(ship, n) <= 10)
			return(0);
		return(1);
E 8
I 8
	foreachship(sp) {
		if (ship != sp && range(ship, sp) <= 10)
			return 0;
	}
	return 1;
E 8
}

I 8
D 12
/* XXX */
E 12
E 8
push(from, to)
D 8
register int from, to;
E 8
I 8
register struct ship *from, *to;
E 8
{
D 12
	int bow1r, bow1c, bow2r, bow2c, stern1r, stern1c, stern2r, stern2c;
E 12
	register int bs, sb;

D 8
	stern1r = bow1r = pos[from].row;
	stern1c = bow1c = pos[from].col;
	stern2r = bow2r = pos[to].row;
	stern2c = bow2c = pos[to].col;
	drdc(&stern2r, &stern2c, pos[to].dir);
E 8
I 8
D 12
	stern1r = bow1r = from->file->row;
	stern1c = bow1c = from->file->col;
	stern2r = bow2r = to->file->row;
	stern2c = bow2c = to->file->col;
	stern2r += dr[to->file->dir];
	stern2c += dc[to->file->dir];
E 8
	bs = bow1r - stern2r + bow1c - stern2c;
	sb = stern1r - bow2r + stern1c - bow2c;
	if (!bs)
D 8
		return(1);
	drdc(&stern1r, &stern1c, pos[from].dir);
E 8
I 8
		return 1;
	stern1r += dr[from->file->dir];
	stern1c += dc[from->file->dir];
E 8
	if(!sb)
D 8
		return(0);
	if ((sb = specs[scene[game].ship[to].shipnum].class) > (bs = specs[scene[game].ship[from].shipnum].class))
		return(1);
E 8
I 8
		return 0;
E 12
D 13
	sb = to->specs->class;
	bs = from->specs->class;
E 13
I 13
	sb = to->specs->guns;
	bs = from->specs->guns;
E 13
	if (sb > bs)
		return 1;
E 8
	if (sb < bs)
D 8
		return(0);
	return(from < to);
E 8
I 8
		return 0;
	return from < to;
E 8
}

D 8
step(com, shipnum, row, col, dir)
int shipnum, row[20], col[20], dir[20];
E 8
I 8
D 13
step(com, ship, row, col, dir)
register struct ship *ship;
register int *row, *col, *dir;
E 13
I 13
step(com, sp, moved)
E 13
E 8
char com;
I 13
register struct ship *sp;
char *moved;
E 13
{
D 8
	int dr = 0, dc = 0;
E 8
	register int dist;

D 8
	switch(com){

		case 'r':
			if (++dir[shipnum] == 9)
				dir[shipnum] = 1;
			break;
		case 'l':
			if (!--dir[shipnum])
				dir[shipnum] = 8;
			break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
			drdc(&dr, &dc, dir[shipnum]);
			if (!(dir[shipnum] % 2))
				dist = dtab[com - '0'];
			else
				dist = com - '0';
			row[shipnum] -= dr * dist;
			col[shipnum] -= dc * dist;
			dr = dc = 0;
			break;
		case 'b':
			break;
		case 'd':
			drdc(&dr, &dc, winddir);
			dist = 1 - ((specs[scene[game].ship[shipnum].shipnum].class < 3 || fouled(shipnum) || grappled(shipnum)) && turn % 2);
			row[shipnum] -= dr * dist;
			col[shipnum] -= dc * dist;
			break;
E 8
I 8
	switch (com) {
	case 'r':
D 13
		if (++*dir == 9)
			*dir = 1;
E 13
I 13
		if (++sp->file->dir == 9)
			sp->file->dir = 1;
E 13
		break;
	case 'l':
D 13
		if (--*dir == 0)
			*dir = 8;
E 13
I 13
		if (--sp->file->dir == 0)
			sp->file->dir = 8;
E 13
		break;
D 15
	case '0': case '1': case '2': case '3':
	case '4': case '5': case '6': case '7':
E 15
I 15
		case '0': case '1': case '2': case '3':
		case '4': case '5': case '6': case '7':
E 15
D 13
		if (*dir % 2 == 0)
E 13
I 13
		if (sp->file->dir % 2 == 0)
E 13
			dist = dtab[com - '0'];
		else
			dist = com - '0';
D 13
		*row -= dr[*dir] * dist;
		*col -= dc[*dir] * dist;
E 13
I 13
		sp->file->row -= dr[sp->file->dir] * dist;
		sp->file->col -= dc[sp->file->dir] * dist;
		*moved = 1;
E 13
		break;
	case 'b':
		break;
	case 'd':
D 13
		if (ship->specs->class >= 3 && !snagged(ship)
		    || turn % 2 == 0) {
			*row -= dr[winddir];
			*col -= dc[winddir];
		}
E 13
I 13
		if (!*moved) {
D 16
			if (++sp->file->drift > 2 &&
E 16
I 16
			if (windspeed != 0 && ++sp->file->drift > 2 &&
E 16
			    (sp->specs->class >= 3 && !snagged(sp)
			     || (turn & 1) == 0)) {
				sp->file->row -= dr[winddir];
				sp->file->col -= dc[winddir];
			}
		} else
			sp->file->drift = 0;
E 13
		break;
E 8
	}
}

D 8
send(from, to, sections, offset)
int from, to, sections, offset;
E 8
I 8
sendbp(from, to, sections, isdefense)
register struct ship *from, *to;
int sections;
char isdefense;
E 8
{
	int n;
D 8
	struct BP *ptr;
E 8
I 8
	register struct BP *bp;
E 8

D 8
	ptr = offset == 200 ? scene[game].ship[from].file -> OBP : scene[game].ship[from].file -> DBP;
	for (n=0; n<3 && ptr[n].turnsent; n++);
	if (n < 3 && sections){
		Write(FILES + from, 0, 30 + (offset > 200)*18 + 6*n, turn);
		Write(FILES + from, 0, 30 + (offset > 200)*18 + 6*n + 2, to);
		Write(FILES + from, 0, 30 + (offset > 200)*18 + 6*n + 4, sections);
		if (offset == 200)
			makesignal("boarding the %s (%c%c)", to, from);
E 8
I 8
	bp = isdefense ? from->file->DBP : from->file->OBP;
D 15
	for (n = 0; n < 3 && bp[n].turnsent; n++)
E 15
I 15
	for (n = 0; n < NBP && bp[n].turnsent; n++)
E 15
		;
D 15
	if (n < 3 && sections) {
E 15
I 15
	if (n < NBP && sections) {
E 15
		Write(isdefense ? W_DBP : W_OBP, from, 0,
D 14
			turn, to-SHIP(0), sections, 0);
E 14
I 14
D 15
			turn, to->file->index, sections, 0);
E 15
I 15
			n, turn, to->file->index, sections);
E 15
E 14
		if (isdefense)
			makesignal(from, "repelling boarders",
				(struct ship *)0);
E 8
		else
D 8
			makesignal("repelling boarders", 0, from);
E 8
I 8
			makesignal(from, "boarding the %s (%c%c)", to);
E 8
	}
}

D 8
toughmelee(shipnum, toship, defense, count)
int shipnum, toship, defense, count;
E 8
I 8
toughmelee(ship, to, isdefense, count)
register struct ship *ship, *to;
int isdefense, count;
E 8
{
D 8
	int n, OBP = 0, DBP = 0, obp = 0, dbp = 0;
E 8
I 8
	register struct BP *bp;
	register obp = 0;
	int n, OBP = 0, DBP = 0, dbp = 0;
E 8
	int qual;
D 8
	struct BP *ptr1;
	struct shipspecs *ptr;
E 8

D 8
	ptr = &specs[scene[game].ship[shipnum].shipnum];
	ptr1 = defense ? scene[game].ship[shipnum].file -> DBP : scene[game].ship[shipnum].file -> OBP ;
	qual = ptr -> qual;
	for (n=0; n < 3; n++){
		if (ptr1[n].turnsent && (toship == ptr1[n].toship || defense)){
			obp += ptr1[n].mensent / 100 ? ptr -> crew1 * qual : 0;
			obp += (ptr1[n].mensent % 100)/10 ? ptr -> crew2 * qual : 0;
			obp += ptr1[n].mensent % 10 ? ptr -> crew3 * qual : 0;
E 8
I 8
	qual = ship->specs->qual;
	bp = isdefense ? ship->file->DBP : ship->file->OBP;
	for (n = 0; n < NBP; n++, bp++) {
		if (bp->turnsent && (to == bp->toship || isdefense)) {
			obp += bp->mensent / 100
				? ship->specs->crew1 * qual : 0;
			obp += (bp->mensent % 100)/10
				? ship->specs->crew2 * qual : 0;
			obp += bp->mensent % 10
				? ship->specs->crew3 * qual : 0;
E 8
		}
	}
D 8
	if (count || defense)
		return(obp);
	OBP = toughmelee(toship, shipnum, 0, count + 1);
	dbp = toughmelee(shipnum, toship, 1, count + 1);
	DBP = toughmelee(toship, shipnum, 1, count + 1);
E 8
I 8
	if (count || isdefense)
		return obp;
	OBP = toughmelee(to, ship, 0, count + 1);
	dbp = toughmelee(ship, to, 1, count + 1);
	DBP = toughmelee(to, ship, 1, count + 1);
E 8
	if (OBP > obp + 10 || OBP + DBP >= obp + dbp + 10)
D 8
		return(1);
E 8
I 8
		return 1;
E 8
	else
D 8
		return(0);
E 8
I 8
		return 0;
E 8
}

reload()
{
D 8
	register int n;
E 8
I 8
	register struct ship *sp;
E 8

D 8
	for (n=0; n < scene[game].vessels; n++)
		loadwith[n] = 0;
E 8
I 8
	foreachship(sp) {
		sp->file->loadwith = 0;
	}
E 8
}

checksails()
{
D 8
	register int n, rig, full; 
	struct shipspecs *ptr;
	int close;
E 8
I 8
	register struct ship *sp;
	register int rig, full; 
	struct ship *close;
E 8

D 8
	for (n=0; n < scene[game].vessels; n++){
		ptr = &specs[scene[game].ship[n].shipnum];
		rig = ptr -> rig1;
		if (windspeed == 6 || (windspeed == 5 && ptr -> class > 4))
E 8
I 8
	foreachship(sp) {
		if (sp->file->captain[0] != 0)
			continue;
		rig = sp->specs->rig1;
		if (windspeed == 6 || windspeed == 5 && sp->specs->class > 4)
E 8
			rig = 0;
D 8
		if (!scene[game].ship[n].file -> captain[0]){
			if (rig && ptr -> crew3) {
				close = closestenemy(n,0,0);
				if (close != 30000) {
					if (range(n, close) > 9)
						full = 1;
					else
						full = 0;
				} else 
E 8
I 8
		if (rig && sp->specs->crew3) {
			close = closestenemy(sp, 0, 0);
			if (close != 0) {
				if (range(sp, close) > 9)
					full = 1;
				else
E 8
					full = 0;
D 8
			} else
E 8
I 8
			} else 
E 8
				full = 0;
D 8
			if ((scene[game].ship[n].file -> FS != 0) != full)
				Write(FILES + n, 0, 230, full);
		}
E 8
I 8
		} else
			full = 0;
		if ((sp->file->FS != 0) != full)
			Write(W_FS, sp, 0, full, 0, 0, 0);
E 8
	}
}
E 1
