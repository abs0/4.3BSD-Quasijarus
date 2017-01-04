h53288
s 00010/00005/00435
d D 5.3 88/06/18 19:55:15 bostic 28 27
c install approved copyright notice
e
s 00009/00003/00431
d D 5.2 88/03/09 12:30:07 bostic 27 26
c written by David Riggle and Edward Wang; add Berkeley specific copyright
e
s 00005/00005/00429
d D 5.1 85/05/29 15:59:15 dist 26 25
c Add copyright
e
s 00032/00034/00402
d D 2.14 85/04/26 12:13:54 edward 25 24
c return some value from dr_main() (mostly for lint)
e
s 00001/00001/00435
d D 2.13 85/04/25 20:58:30 edward 24 23
c lint
e
s 00006/00000/00430
d D 2.12 85/04/23 21:46:35 edward 23 22
c copyright message
e
s 00002/00077/00428
d D 2.11 85/03/04 18:06:57 edward 22 21
c more cleanup; sail, driver, sail.log merged into single program
e
s 00004/00001/00501
d D 2.10 84/03/08 00:33:03 edward 21 20
c forgot to use strncpy() for captain's name
e
s 00003/00000/00499
d D 2.9 84/02/28 15:46:04 edward 20 19
c setruid(geteuid())
e
s 00028/00003/00471
d D 2.8 84/02/23 15:55:23 edward 19 18
c log best score, and deal with errors in Sync().
e
s 00001/00001/00473
d D 2.7 84/01/27 15:01:28 edward 18 16
c portability
e
s 00001/00000/00474
d R 2.7 84/01/19 15:18:48 edward 17 16
c setuid(getuid()) after opening sync file
e
s 00013/00012/00461
d D 2.6 83/12/17 12:38:02 edward 16 15
c new grapple and foul data structure.
e
s 00003/00005/00470
d D 2.5 83/12/12 14:10:15 edward 15 14
c bug in ungrappling
e
s 00009/00008/00466
d D 2.4 83/11/08 16:22:25 edward 14 13
c resolve() bug
e
s 00001/00000/00473
d D 2.3 83/11/02 13:22:30 edward 13 12
c ignore SIGTSTP
e
s 00001/00007/00472
d D 2.2 83/11/01 17:34:01 edward 12 11
c sleep first so we don't start at turn 1.
e
s 00000/00000/00479
d D 2.1 83/10/31 13:43:08 edward 11 10
c new version
e
s 00013/00014/00466
d D 1.9 83/10/31 11:50:56 edward 10 9
c Fixed boarding bug.
e
s 00005/00001/00475
d D 1.8 83/10/28 22:47:05 edward 9 8
c no more defensive boarding
e
s 00008/00007/00468
d D 1.7 83/10/28 21:13:56 edward 8 6
c reload bug
e
s 00000/00007/00468
d R 1.7 83/10/14 22:47:03 edward 7 6
c last remnant of old Signal() scheme
e
s 00007/00000/00468
d D 1.6 83/10/14 20:52:32 edward 6 5
c dummy signal, needs more thought.
e
s 00069/00073/00399
d D 1.5 83/10/10 20:09:43 edward 5 4
c got rid of unnecessary variables
e
s 00335/00351/00137
d D 1.4 83/07/20 17:17:24 edward 4 3
c 
e
s 00008/00008/00480
d D 1.3 83/05/20 21:37:02 root 3 2
c check after fopen()
e
s 00005/00003/00483
d D 1.2 83/05/20 17:42:02 root 2 1
c merge
e
s 00486/00000/00000
d D 1.1 83/03/17 21:09:05 leres 1 0
c date and time created 83/03/17 21:09:05 by leres
e
u
U
t
T
I 23
/*
D 26
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 26
I 26
 * Copyright (c) 1983 Regents of the University of California.
D 27
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 27
I 27
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 28
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 28
I 28
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
E 28
E 27
E 26
 */

E 23
I 1
#ifndef lint
D 26
static	char *sccsid = "%W% %E%";
#endif
E 26
I 26
static char sccsid[] = "%W% (Berkeley) %G%";
D 27
#endif not lint
E 27
I 27
#endif /* not lint */
E 27
E 26
I 2

E 2
D 4
#include "externs.h"
#include <sys/types.h>
E 4
I 4
#include "driver.h"
E 4
D 3
#include <sys/stat.h>
E 3

I 5
D 22
main(argc, argv)
int argc;
char **argv;
{
	register int n;
	register struct ship *sp;
	int nat[NNATION];

	if (argc != 2)
		exit(1);
	(void) signal(SIGINT, SIG_IGN);
	(void) signal(SIGQUIT, SIG_IGN);
I 13
	(void) signal(SIGTSTP, SIG_IGN);
E 13
	(void) srand(getpid());
I 20
	(void) setruid(geteuid());
E 20
	/* ;;; add code here to check the game number. */
	game = atoi(argv[1]);
	cc = &scene[game];
D 18
	ls = &cc->ship[cc->vessels];
E 18
I 18
	ls = SHIP(cc->vessels);
E 18
	if (sync_open() < 0) {
		perror("driver: syncfile");
		exit(1);
	}
	for (n = 0; n < NNATION; n++)
		nat[n] = 0;
	foreachship(sp) {
		sp->file = (struct File *) calloc(1, sizeof (struct File));
		if (sp == NULL) {
			(void) printf("driver: OUT OF MEMORY\n");
D 19
			exit(0);
E 19
I 19
			exit(1);
E 19
		}
I 16
		sp->file->index = sp - SHIP(0);
E 16
		sp->file->loadL = L_ROUND;
		sp->file->loadR = L_ROUND;
		sp->file->readyR = R_LOADED|R_INITIAL;
		sp->file->readyL = R_LOADED|R_INITIAL;
		sp->file->stern = nat[sp->nationality]++;
		sp->file->dir = sp->shipdir;
		sp->file->row = sp->shiprow;
		sp->file->col = sp->shipcol;
	}
	windspeed = cc->windspeed;
	winddir = cc->winddir;
	for (;;) {
I 12
		sleep(7);
E 12
D 19
		Sync();
E 19
I 19
		if (Sync() < 0) {
			sync_close(1);
			exit(1);
		}
E 19
		next();
		unfoul();
		checkup();
		prizecheck();
		moveall();
D 12
		/*
		readpos();
		*/
E 12
		thinkofgrapples();
		boardcomp();
		compcombat();
D 12
		/*
		readpos();
		*/
E 12
		resolve();
		reload();
		checksails();
D 19
		Sync();
E 19
I 19
		if (Sync() < 0) {
			sync_close(1);
			exit(1);
		}
E 19
D 12
		sleep(7);
E 12
	}
}

E 22
E 5
D 4
#define couldwin(from, to)	(specs[scene[game].ship[from].shipnum].crew2 > specs[scene[game].ship[to].shipnum].crew2 * 1.5)

E 4
unfoul()
{
D 4
	char name;
	register int n, k, ship;
	int ident, captured;
	struct File *ptr;
E 4
I 4
D 16
	register int k;
E 16
	register struct ship *sp;
	struct ship *to;
	register int nat;
I 16
	register i;
E 16
E 4

D 4
	for (n=0; n < scene[game].vessels; n++){
		ptr = scene[game].ship[n].file;
		if (!ptr -> captain[0]){
			for(k=0; k < 10; k++){
				if (ptr -> fouls[k].turnfoul){
					if ((ident = ptr -> captured) < 0)
						ident = n;
					ship = ptr -> fouls[k].toship;
					if ((captured = scene[game].ship[ship].file -> captured) < 0)
						captured = ship;
					if (scene[game].ship[ident].nationality == scene[game].ship[ship].nationality || toughmelee(n, ship, 0, 0))
						if (die() <= 2){
							cleanfoul(n, ship, k);
						}
				}
			}
E 4
I 4
	foreachship(sp) {
		if (sp->file->captain[0])
			continue;
		nat = capship(sp)->nationality;
D 16
		for (k = 0; k < NSHIP; k++) {
			if (sp->file->fouls[k].turnfoul == 0)
E 16
I 16
		foreachship(to) {
D 22
			if (nat != capship(to)->nationality
			    && !toughmelee(sp, to, 0, 0))
E 22
I 22
			if (nat != capship(to)->nationality &&
			    !toughmelee(sp, to, 0, 0))
E 22
E 16
				continue;
D 16
			to = sp->file->fouls[k].toship;
D 15
			if (nat != capship(to)->nationality)
				continue;
			if (!toughmelee(sp, to, 0, 0))
				continue;
			if (die() <= 2)
E 15
I 15
			if ((nat == capship(to)->nationality ||
			     toughmelee(sp, to, 0, 0)) &&
			    die() <= 2)
E 15
				cleanfoul(sp, to, k);
E 16
I 16
			for (i = fouled2(sp, to); --i >= 0;)
				if (die() <= 2)
					cleanfoul(sp, to, 0);
E 16
E 4
		}
	}
}

D 4


E 4
boardcomp()
{
D 2
	register int n, k, l, crew[3], men = 0, captured;
E 2
I 2
D 4
	register int n, k, l, men = 0, captured;
E 4
	int crew[3];
E 2
D 4
	struct shipspecs *ptr;
	struct File *ptr1;
E 4
I 4
	register struct ship *sp, *sq;
E 4

D 4
	for (n = 0; n < scene[game].vessels; n++){
		ptr = &specs[scene[game].ship[n].shipnum];
		ptr1 = scene[game].ship[n].file;
		if (!ptr1 -> captain[0] && (fouled(n) || grappled(n)) && pos[n].dir && !ptr1 -> struck && ptr1 -> captured < 0){
			crew[0] = ptr -> crew1 != 0;
			crew[1] = ptr -> crew2 != 0;
			crew[2] = ptr -> crew3 != 0;
			for (l=0; l < scene[game].vessels; l++)
				if (foul(n+100,l) || grapple(n+100,l)){
					if (!meleeing(n,l)){
						if ((captured = scene[game].ship[l].file -> captured) < 0) 
							captured = l;
						if (pos[l].dir && scene[game].ship[n].nationality != scene[game].ship[captured].nationality){
							switch(specs[scene[game].ship[n].shipnum].class - specs[scene[game].ship[l].shipnum].class){
								case -3:
								case -4:
								case -5:
									if (crew[0]){
										send(n, l, crew[0]*100, 200);		/* OBP */
										crew[0] = 0;
									}
									else if (crew[1]){
										send(n, l, crew[1]*10, 200);		/* OBP */
										crew[1] = 0;
									}
									break;
								case -2:
									if (crew[0] || crew[1]){
										send(n, l, crew[0]*100+crew[1]*10, 200);	/* OBP */
										crew[0] = crew[1] = 0;
									}
									break;
								case -1:
								case 0:
								case 1:
									if (crew[0]){
										send(n, l, crew[0]*100+crew[1]*10, 200);	/* OBP */
										crew[0] = crew[1] = 0;
									}
									break;
								case 2:
								case 3:
								case 4:
								case 5:
									send(n, l, crew[0]*100+crew[1]*10+crew[2], 200);	/* OBP */
									crew[0] = crew[1] = crew[2] = 0;
									break;
							}
						}
					}
E 4
I 4
	foreachship(sp) {
		if (*sp->file->captain)
			continue;
D 16
		if (!fouled(sp) && !grappled(sp))
			continue;
E 16
		if (sp->file->dir == 0)
			continue;
		if (sp->file->struck || sp->file->captured != 0)
			continue;
I 16
		if (!snagged(sp))
			continue;
E 16
		crew[0] = sp->specs->crew1 != 0;
		crew[1] = sp->specs->crew2 != 0;
		crew[2] = sp->specs->crew3 != 0;
		foreachship(sq) {
			if (!Xsnagged2(sp, sq))
				continue;
			if (meleeing(sp, sq))
				continue;
			if (!sq->file->dir
				|| sp->nationality == capship(sq)->nationality)
				continue;
			switch (sp->specs->class - sq->specs->class) {
			case -3: case -4: case -5:
				if (crew[0]) {
					/* OBP */
					sendbp(sp, sq, crew[0]*100, 0);
					crew[0] = 0;
				} else if (crew[1]){
					/* OBP */
					sendbp(sp, sq, crew[1]*10, 0);
					crew[1] = 0;
E 4
				}
I 4
				break;
			case -2:
				if (crew[0] || crew[1]) {
					/* OBP */
					sendbp(sp, sq, crew[0]*100+crew[1]*10,
						0);
					crew[0] = crew[1] = 0;
				}
				break;
			case -1: case 0: case 1:
				if (crew[0]) {
					/* OBP */
					sendbp(sp, sq, crew[0]*100+crew[1]*10,
						0);
					crew[0] = crew[1] = 0;
				}
				break;
			case 2: case 3: case 4: case 5:
				/* OBP */
				sendbp(sp, sq, crew[0]*100+crew[1]*10+crew[2],
					0);
				crew[0] = crew[1] = crew[2] = 0;
				break;
E 4
			}
I 4
		}
E 4
	}
}

D 4

E 4
fightitout(from, to, key)
D 4
int from, to, key;
E 4
I 4
struct ship *from, *to;
int key;
E 4
{
D 4
	int crewfrom[3], crewto[3], menfrom, mento, fromcap, tocap;
E 4
I 4
	struct ship *fromcap, *tocap;
	int crewfrom[3], crewto[3], menfrom, mento;
E 4
	int pcto, pcfrom, fromstrength, strengthto, frominjured, toinjured;
D 4
	int index, totalfrom = 0, totalto = 0, topoints, frompoints, struck;
	int junk, count;
	struct File *ptr;
	struct shipspecs *ptr1;
E 4
I 4
	int topoints;
	int index, totalfrom = 0, totalto = 0;
	int count;
E 4
	char message[60];

D 4
	ptr = scene[game].ship[from].file;
	ptr1 = &specs[scene[game].ship[from].shipnum];
	menfrom = mensent(from, to, crewfrom, &fromcap, &pcfrom, &frompoints, key);
	mento = mensent(to, from, crewto, &tocap, &pcto, &topoints, 0);
	if (fromcap < 0)
E 4
I 4
	menfrom = mensent(from, to, crewfrom, &fromcap, &pcfrom, key);
	mento = mensent(to, from, crewto, &tocap, &pcto, 0);
	if (fromcap == 0)
E 4
		fromcap = from;
D 4
	if (tocap < 0)
E 4
I 4
	if (tocap == 0)
E 4
		tocap = to;
I 10
D 16
	if (key) { 
E 16
I 16
	if (key) {
E 16
		if (!menfrom) {		 /* if crew surprised */
			if (fromcap == from)
				menfrom = from->specs->crew1
					+ from->specs->crew2
					+ from->specs->crew3;
			else
				menfrom = from->file->pcrew;
		} else {
			menfrom *= 2;	/* DBP's fight at an advantage */
		}
	}
E 10
D 4
	fromstrength = menfrom * specs[scene[game].ship[fromcap].shipnum].qual;
	strengthto = mento * specs[scene[game].ship[tocap].shipnum].qual;
	if (key && !menfrom){
E 4
I 4
	fromstrength = menfrom * fromcap->specs->qual;
	strengthto = mento * tocap->specs->qual;
I 9
D 10
	/*
	 * Don't have surprised crews fight at a disadvantage 
	 *
E 9
	if (key && !menfrom) {
E 4
		if (fromcap == from)
D 4
			menfrom = ptr1 -> crew1 + ptr1 -> crew2 + ptr1 -> crew3;
E 4
I 4
			menfrom = from->specs->crew1
				+ from->specs->crew2 + from->specs->crew3;
E 4
		else
D 4
			menfrom = ptr -> pcrew;
E 4
I 4
			menfrom = from->file->pcrew;
E 4
		fromstrength = -1;
		strengthto *= 2;
	}
I 9
	*/
E 10
E 9
D 4
	for (count = 0; (!(fromstrength >= strengthto * 3 || strengthto >= fromstrength * 3) || fromstrength == -1) && count < 4;count++){
E 4
I 4
	for (count = 0;
	     (fromstrength < strengthto * 3 && strengthto < fromstrength * 3
	      || fromstrength == -1) && count < 4;
	     count++) {
E 4
		index = fromstrength/10;
		if (index > 8)
			index = 8;
		toinjured = MT[index][2 - die() / 3];
		totalto += toinjured;
		index = strengthto/10;
		if (index > 8)
			index = 8;
		frominjured = MT[index][2 - die() / 3];
		totalfrom += frominjured;
		menfrom -= frominjured;
		mento -= toinjured;
D 4
		fromstrength = menfrom * specs[scene[game].ship[fromcap].shipnum].qual;
		strengthto = mento * specs[scene[game].ship[tocap].shipnum].qual;
E 4
I 4
		fromstrength = menfrom * fromcap->specs->qual;
		strengthto = mento * tocap->specs->qual;
E 4
	}
D 4
	if (fromstrength >= strengthto * 3 || count == 4){
E 4
I 4
	if (fromstrength >= strengthto * 3 || count == 4) {
E 4
		unboard(to, from, 0);
		subtract(from, totalfrom, crewfrom, fromcap, pcfrom);
		subtract(to, totalto, crewto, tocap, pcto);
D 4
		makesignal("boarders from %s repelled", to, from);
		sprintf(message, "killed in melee: %d.  %s: %d", totalto, scene[game].ship[from].shipname, totalfrom);
		Write(FILES + to, 1, 164, message);
E 4
I 4
		makesignal(from, "boarders from %s repelled", to);
		(void) sprintf(message, "killed in melee: %d.  %s: %d",
			totalto, from->shipname, totalfrom);
		Write(W_SIGNAL, to, 1, (int) message, 0, 0, 0);
E 4
		if (key)
D 4
			return(1);
	}
	else if (strengthto >= fromstrength * 3){
E 4
I 4
			return 1;
	} else if (strengthto >= fromstrength * 3) {
E 4
		unboard(from, to, 0);
		subtract(from, totalfrom, crewfrom, fromcap, pcfrom);
		subtract(to, totalto, crewto, tocap, pcto);
D 4
		if (key){
E 4
I 4
		if (key) {
E 4
			if (fromcap != from)
D 4
/* Write(FILES + fromcap, 0, 20, scene[game].ship[fromcap].file -> points - (2 - ptr -> struck)*ptr1 -> points); */ /* original line... */
E 4
I 4
				Write(W_POINTS, fromcap, 0,
					fromcap->file->points -
						from->file->struck
						? from->specs->pts
						: 2 * from->specs->pts,
					0, 0, 0);
E 4

D 4
Write(FILES + fromcap, 0, 20,
(scene[game].ship[fromcap].file -> points) -
(2 - (ptr -> struck))*(ptr1 -> pts)
/* (2 - (ptr -> struck))*(ptr1 -> points) */
);

E 4
/* ptr1 points to the shipspec for the ship that was just unboarded.
   I guess that what is going on here is that the pointer is multiplied
   or something. */

D 4
			Write(FILES + from, 0, 68, to);
			topoints = 2*ptr1 -> pts + scene[game].ship[to].file -> points;
			if (ptr -> struck)
				topoints -= ptr1 -> pts;
			Write(FILES + to, 0, 20, topoints);
E 4
I 4
D 16
			Write(W_CAPTURED, from, 0, to-SHIP(0), 0, 0, 0);
E 16
I 16
			Write(W_CAPTURED, from, 0, to->file->index, 0, 0, 0);
E 16
			topoints = 2 * from->specs->pts + to->file->points;
			if (from->file->struck)
				topoints -= from->specs->pts;
			Write(W_POINTS, to, 0, topoints, 0, 0, 0);
E 4
			mento = crewto[0] ? crewto[0] : crewto[1];
D 4
			if (mento){
E 4
I 4
			if (mento) {
E 4
				subtract(to, mento, crewto, tocap, pcto);
D 4
				subtract(from, -mento, crewfrom, to, 0);
E 4
I 4
				subtract(from, - mento, crewfrom, to, 0);
E 4
			}
D 4
			sprintf(message, "captured by the %s!",scene[game].ship[to].shipname);
			Write(FILES + from, 1, 164, message);
			sprintf(message, "killed in melee: %d.  %s: %d", totalto, scene[game].ship[from].shipname, totalfrom);
			Write(FILES + to, 1, 164, message);
E 4
I 4
			(void) sprintf(message, "captured by the %s!",
				to->shipname);
			Write(W_SIGNAL, from, 1, (int) message, 0, 0, 0);
			(void) sprintf(message, "killed in melee: %d.  %s: %d",
				totalto, from->shipname, totalfrom);
			Write(W_SIGNAL, to, 1, (int) message, 0, 0, 0);
E 4
			mento = 0;
D 4
			return(0);
E 4
I 4
			return 0;
E 4
		}
	}
D 4
	return(0);
}		/* end of fightitout */
E 4
I 4
	return 0;
}
E 4

D 4

E 4
resolve()
{
D 4
	register int n, l, k, thwart;
E 4
I 4
	int thwart;
	register struct ship *sp, *sq;
E 4

D 4
	for (n=0; n < scene[game].vessels; n++){
E 4
I 4
	foreachship(sp) {
E 4
D 9
		thwart = 2;
E 9
D 4
		if (pos[n].dir){
			for (l=n+1; l < scene[game].vessels; l++){
				if (pos[l].dir && meleeing(n,l) && meleeing(l,n)){	/* offense */
					fightitout(n,l,0);
				}
			}
			for (l=0; l < scene[game].vessels; l++){ /* defense */
				if (pos[l].dir && meleeing(l,n)){
					thwart = fightitout(n,l,1);
				}
				if (!thwart)
					break;
			}
			if (!thwart){
				for (k=0; k < scene[game].vessels; k++){
					if (pos[k].dir && meleeing(k,n)){
						unboard(k,n,0);
					}
					unboard(n,k,0);
				}
				unboard(n,n,1);
			}
			if (thwart == 2)
				unboard(n,n,1);
E 4
I 4
		if (sp->file->dir == 0)
			continue;
I 9
D 14
		thwart = 2;
E 14
E 9
D 10
		foreachship(sq)
E 10
I 10
		for (sq = sp + 1; sq < ls; sq++)
E 10
			if (sq->file->dir && meleeing(sp, sq) && meleeing(sq, sp))
				(void) fightitout(sp, sq, 0);
I 14
		thwart = 2;
E 14
		foreachship(sq) {
			if (sq->file->dir && meleeing(sq, sp))
				thwart = fightitout(sp, sq, 1);
			if (!thwart)
				break;
E 4
		}
I 4
D 14
		foreachship(sq) {
			if (sq->file->dir && meleeing(sq, sp))
				unboard(sq, sp, 0);
			unboard(sp, sq, 0);
		}
		unboard(sp, sp, 1);
		if (thwart == 2)
E 14
I 14
		if (!thwart) {
			foreachship(sq) {
				if (sq->file->dir && meleeing(sq, sp))
					unboard(sq, sp, 0);
				unboard(sp, sq, 0);
			}
			unboard(sp, sp, 1);
		} else if (thwart == 2)
E 14
			unboard(sp, sp, 1);
E 4
	}
}

D 4

E 4
compcombat()
{
I 4
	register n;
	register struct ship *sp;
	struct ship *closest;
E 4
	int crew[3], men = 0, target, temp;
D 4
	int n, r, guns[2], load[2], car[2], roll[2];
	int ready[2], index, rakehim, sternrake;
	int shootat[2], hit[2], closest[2], ship;
	struct shipspecs *ptr;
	struct File *ptr1;
E 4
I 4
D 8
	int r, guns, load, car;
	int ready, index, rakehim, sternrake;
E 8
I 8
	int r, guns, ready, load, car;
	int index, rakehim, sternrake;
E 8
	int shootat, hit;
E 4

D 4
	for (ship = 0; ship < scene[game].vessels; ship++){
		ptr = &specs[scene[game].ship[ship].shipnum];
		ptr1 = scene[game].ship[ship].file;
		if (!ptr1 -> captain[0] && pos[ship].dir){
			crew[0] = ptr -> crew1;
			crew[1] = ptr -> crew2;
			crew[2] = ptr -> crew3;
			ready[0] = ptr1 -> readyL;
			ready[1] = ptr1 -> readyR;
			guns[0] = ptr -> gunL;
			guns[1] = ptr -> gunR;
			car[0] = ptr -> carL;
			car[1] = ptr -> carR;
			for (n = 0; n < 3; n++){
				if (ptr1 -> OBP[n].turnsent)
					men += ptr1 -> OBP[n].mensent;
E 4
I 4
	foreachship(sp) {
		if (sp->file->captain[0] || sp->file->dir == 0)
			continue;
		crew[0] = sp->specs->crew1;
		crew[1] = sp->specs->crew2;
		crew[2] = sp->specs->crew3;
		for (n = 0; n < 3; n++) {
			if (sp->file->OBP[n].turnsent)
				men += sp->file->OBP[n].mensent;
		}
		for (n = 0; n < 3; n++) {
			if (sp->file->DBP[n].turnsent)
				men += sp->file->DBP[n].mensent;
		}
		if (men){
			crew[0] = men/100 ? 0 : crew[0] != 0;
			crew[1] = (men%100)/10 ? 0 : crew[1] != 0;
			crew[2] = men%10 ? 0 : crew[2] != 0;
		}
		for (r = 0; r < 2; r++) {
			if (!crew[2])
				continue;
			if (sp->file->struck)
				continue;
			if (r) {
				ready = sp->file->readyR;
				guns = sp->specs->gunR;
				car = sp->specs->carR;
			} else {
				ready = sp->file->readyL;
				guns = sp->specs->gunL;
				car = sp->specs->carL;
E 4
			}
D 4
			for (n = 0; n < 3; n++){
				if (ptr1 -> DBP[n].turnsent)
					men += ptr1 -> DBP[n].mensent;
			}
			if (men){
				crew[0] = men/100 ? 0 : crew[0] != 0;
				crew[1] = (men%100)/10 ? 0 : crew[1] != 0;
				crew[2] = men%10 ? 0 : crew[2] != 0;
			}
			for (r = 0; r < 2; r++){
				if ((guns[r] || car[r]) && crew[2] && ready[r] <= 0 && !ptr1 -> struck && ((closest[r] = closestenemy(ship, (r ? 'r' : 'l'), 0)) != 30000) && range(closest[r], ship) <= range(ship, closestenemy(ship, (r ? 'r' : 'l'), 1))){
					if ((target = range(ship, closest[r])) <= 10 && !scene[game].ship[closest[r]].file -> struck && (guns[r] || (car[r] && target < 3))){
						load[r] = ROUND;
						if (target == 1 && loadwith[ship] == GRAPE)
							load[r] = GRAPE;
						if (target <= 3 && scene[game].ship[closest[r]].file -> FS)
							load[r] = CHAIN;
						if (target == 1 && load[r] != GRAPE)
							load[r] = DOUBLE;
						if (load[r] > CHAIN && target < 6){
							shootat[r] = HULL;
						}
						else {
							shootat[r] = RIGGING;
						}
						rakehim = gunsbear(ship, closest[r]) && !gunsbear(closest[r], ship);
						temp = portside(closest[r], ship, 1) - pos[closest[r]].dir + 1;
						if (temp < 1)
							temp += 8;
						if (temp > 8)
							temp -= 8;
						sternrake = temp > 4 && temp < 6;
						index = guns[r];
						if (target < 3){
							index += car[r];
						}
						index = (index - 1)/3;
						index = index > 8 ? 8 : index;
						if (!rakehim){
							hit[r] = HDT[index][target-1];
						}
						else {
							hit[r] = HDTrake[index][target-1];
						}
						if (rakehim && sternrake){
							hit[r]++;
						}
						hit[r] += QUAL[index][ptr1 -> captured < 0 ? ptr -> qual-1 : specs[scene[game].ship[ptr1 -> captured].shipnum].qual -1];
						for (n=0; n < 3 && ptr1 -> captured < 0; n++)
							if (!crew[n]){
								if (index <= 5)
									hit[r]--;
								else
									hit[r] -= 2;
							}
						if (ready[r] <= -30000){
							if (index <= 3)
								hit[r]++;
							else
								hit[r] += 2;
						}
						if (ptr1 -> captured > -1){
							if (index <= 1)
								hit[r]--;
							else
								hit[r] -= 2;
						}
						hit[r] += AMMO[index][load[r] - 1];
						if (((temp = ptr -> class) >= 5 || temp == 1) && windspeed == 5)
							hit[r]--;
						if (windspeed == 6 && temp == 4)
							hit[r] -= 2;
						if (windspeed == 6 && temp <= 3)
							hit[r]--;
						if (hit[r] >= 0){
							if (load[r] != GRAPE)
								hit[r] = hit[r] > 10 ? 10 : hit[r];
							roll[r] = die();
							table(shootat[r], load[r], hit[r], closest[r], ship, roll[r]);
						}
						load[r] = 0;
						if (!r)
							ptr1 -> readyL = 0;
						else
							ptr1 -> readyR = 0;
					}
				}
E 4
I 4
			if (!guns && !car)
				continue;
			if ((ready & R_LOADED) == 0)
				continue;
			closest = closestenemy(sp, r ? 'r' : 'l', 0);
			if (closest == 0)
				continue;
			if (range(closest, sp) > range(sp, closestenemy(sp, r ? 'r' : 'l', 1)))
				continue;
			if (closest->file->struck)
				continue;
			target = range(sp, closest);
			if (target > 10)
				continue;
			if (!guns && target >= 3)
				continue;
			load = L_ROUND;
			if (target == 1 && sp->file->loadwith == L_GRAPE)
				load = L_GRAPE;
			if (target <= 3 && closest->file->FS)
				load = L_CHAIN;
			if (target == 1 && load != L_GRAPE)
				load = L_DOUBLE;
			if (load > L_CHAIN && target < 6)
				shootat = HULL;
			else
				shootat = RIGGING;
			rakehim = gunsbear(sp, closest)
				&& !gunsbear(closest, sp);
			temp = portside(closest, sp, 1)
				- closest->file->dir + 1;
			if (temp < 1)
				temp += 8;
			if (temp > 8)
				temp -= 8;
			sternrake = temp > 4 && temp < 6;
			index = guns;
			if (target < 3)
				index += car;
			index = (index - 1) / 3;
			index = index > 8 ? 8 : index;
			if (!rakehim)
				hit = HDT[index][target-1];
			else
				hit = HDTrake[index][target-1];
			if (rakehim && sternrake)
				hit++;
			hit += QUAL[index][capship(sp)->specs->qual - 1];
			for (n = 0; n < 3 && sp->file->captured == 0; n++)
				if (!crew[n])
					if (index <= 5)
						hit--;
					else
						hit -= 2;
D 8
			if (ready & R_INITIAL)
E 8
I 8
			if (ready & R_INITIAL) {
				if (!r)
					sp->file->readyL &= ~R_INITIAL;
				else
					sp->file->readyR &= ~R_INITIAL;
E 8
				if (index <= 3)
					hit++;
E 4
				else
D 4
					load[r] = 0;
E 4
I 4
					hit += 2;
I 8
			}
E 8
			if (sp->file->captured != 0)
				if (index <= 1)
					hit--;
				else
					hit -= 2;
			hit += AMMO[index][load - 1];
			temp = sp->specs->class;
			if ((temp >= 5 || temp == 1) && windspeed == 5)
				hit--;
			if (windspeed == 6 && temp == 4)
				hit -= 2;
			if (windspeed == 6 && temp <= 3)
				hit--;
			if (hit >= 0) {
				if (load != L_GRAPE)
					hit = hit > 10 ? 10 : hit;
				table(shootat, load, hit, closest, sp, die());
E 4
			}
I 4
D 8
			if (!r)
				sp->file->readyL = R_EMPTY;
			else
				sp->file->readyR = R_EMPTY;
E 8
E 4
		}
	}
}

next()
{
D 4
	char string[25];
	int vec[3];

	turn++;
	if (turn % 55 == 0)
		if (scene[game].time)
			scene[game].time = 0;
E 4
I 4
	if (++turn % 55 == 0)
D 5
		if (cc->time)
			cc->time = 0;
E 5
I 5
		if (alive)
			alive = 0;
E 5
E 4
		else
D 4
			scene[game].people = 0;		/* die if no one */
	if (scene[game].people <= 0 || windspeed == 7){
		fclose(syncfile);
		sprintf(string, "/tmp/.%d", game);
E 4
I 4
D 5
			cc->people = 0;		/* die if no one */
	if (cc->people <= 0 || windspeed == 7) {
		char string[25];

		(void) fclose(syncfile);
		(void) sprintf(string, "/tmp/.%d", game);
E 4
		if (unlink(string) == -1)
			perror(string);
E 5
I 5
			people = 0;
	if (people <= 0 || windspeed == 7) {
I 19
		register struct ship *s;
		struct ship *bestship;
		float net, best = 0.0;
		foreachship(s) {
			if (*s->file->captain)
				continue;
			net = (float)s->file->points / s->specs->pts;
			if (net > best) {
				best = net;
				bestship = s;
			}
		}
		if (best > 0.0) {
			char *p = getenv("WOTD");
			if (p == 0)
				p = "Driver";
I 20
			if (islower(*p))
				*p = toupper(*p);
E 20
D 21
			strcpy(bestship->file->captain, p);
E 21
I 21
D 24
			strncpy(bestship->file->captain, p,
E 24
I 24
			(void) strncpy(bestship->file->captain, p,
E 24
				sizeof bestship->file->captain);
			bestship->file->captain
				[sizeof bestship->file->captain - 1] = 0;
E 21
			log(bestship);
		}
E 19
D 25
		sync_close(1);
E 5
		exit(0);
E 25
I 25
		return -1;
E 25
	}
D 4
	Write(SCENARIO, 0, 6, turn);
	if (turn % 7 == 0){
		if (die() >= scene[game].windchange || !windspeed){
			switch(die()){
				case 1:
					winddir = 1;
					break;
				case 2:
					break;
				case 3:
					winddir++;
					break;
				case 4:
					winddir--;
					break;
				case 5:
					winddir += 2;
					break;
				case 6:
					winddir -= 2;
					break;
E 4
I 4
	Write(W_TURN, SHIP(0), 0, turn, 0, 0, 0);
D 25
	if (turn % 7 == 0) {
		if (die() >= cc->windchange || !windspeed) {
E 25
I 25
	if (turn % 7 == 0 && (die() >= cc->windchange || !windspeed)) {
		switch (die()) {
		case 1:
			winddir = 1;
			break;
		case 2:
			break;
		case 3:
			winddir++;
			break;
		case 4:
			winddir--;
			break;
		case 5:
			winddir += 2;
			break;
		case 6:
			winddir -= 2;
			break;
		}
		if (winddir > 8)
			winddir -= 8;
		if (winddir < 1)
			winddir += 8;
		if (windspeed)
E 25
			switch (die()) {
			case 1:
D 25
				winddir = 1;
				break;
E 25
			case 2:
I 25
				windspeed--;
E 25
				break;
D 25
			case 3:
				winddir++;
				break;
			case 4:
				winddir--;
				break;
E 25
			case 5:
D 25
				winddir += 2;
				break;
E 25
			case 6:
D 25
				winddir -= 2;
E 25
I 25
				windspeed++;
E 25
				break;
E 4
			}
D 25
			if (winddir > 8)
				winddir -= 8;
			if (winddir < 1)
				winddir += 8;
D 4
			Write(SCENARIO, 0, 0, winddir);
E 4
			if (windspeed)
D 4
				switch(die()){
					case 1:
					case 2:
						windspeed--;
						break;
					case 5:
					case 6:
						windspeed++;
						break;
E 4
I 4
				switch (die()) {
				case 1:
				case 2:
					windspeed--;
					break;
				case 5:
				case 6:
					windspeed++;
					break;
E 4
				}
			else
				windspeed++;
D 4
			Write(SCENARIO, 0, 2, windspeed);
		} 
/*		if (!MIGHTYCAPTAIN){
			gldav(vec);
			if ((vec[2] >> 8) > 9)
			{
				makesignal("*Load getting high, brace yourselves.", 0, 0);
			}
			if ((vec[2] >> 8) > 12)
			{
				makesignal("*Load average is blowing a gale!", 0, 0);
				Write(SCENARIO, 0, 2, 7);
			}
		} */
E 4
I 4
			Write(W_WIND, SHIP(0), 0, winddir, windspeed, 0, 0);
		}
E 25
I 25
		else
			windspeed++;
		Write(W_WIND, SHIP(0), 0, winddir, windspeed, 0, 0);
E 25
E 4
D 5
	}
}

main(argc, argv)
int argc;
char **argv;
{
D 4
	register int n, k;
E 4
I 4
	register int n;
E 4
	char file[25];
D 3
	struct stat Stat;
E 3
D 4
	int uid;
E 4
I 4
	register struct ship *sp;
	int nat[NNATION];
E 4

D 2
	signal(SIGHUP, SIG_IGN);
	signal(SIGINT, SIG_IGN);
E 2
I 2
D 3
	signal(1,1);
	signal(2,1);
E 2
/*	uid = geteuid(); */
/*	MIGHTYCAPTAIN = uid == MASTER || uid == SERVANT1 || uid == SERVANT2 || uid == SERVANT3; */
E 3
I 3
D 4
	signal(SIGHUP, SIG_IGN);
	signal(SIGINT, SIG_IGN);
E 3
	srand(getpid());
E 4
I 4
	if (argc != 2)
		exit(1);
	(void) signal(SIGINT, SIG_IGN);
	(void) signal(SIGQUIT, SIG_IGN);
	(void) srand(getpid());
E 4
	/* ;;; add code here to check the game number. */
D 4
	sprintf(file, "/tmp/.%s",argv[1]);
E 4
I 4
	(void) sprintf(file, "/tmp/.%s", argv[1]);
E 4
D 3
	for (n = 0; stat(file,&Stat) < 0 && n < 20; n++)
E 3
I 3
	for (n = 0; access(file, 0) < 0 && n < 20; n++)
E 3
		sleep(5);
	syncfile = fopen(file, "r+");
I 3
	if (syncfile == NULL) {
		perror(file);
		exit(1);
	}
E 3
D 4
	sscanf(argv[1], "%d", &game);
	for (n=0; n < scene[game].vessels; n++){
		nation[scene[game].ship[n].nationality + 1] = n + 1;
		if ((scene[game].ship[n].file = (struct File *) calloc(1, sizeof(struct File))) == NULL){
			printf("OUT OF MEMORY\n");
E 4
I 4
	game = atoi(argv[1]);
	cc = &scene[game];
	ls = &cc->ship[cc->vessels];
	for (n = 0; n < NNATION; n++)
		nat[n] = 0;
	foreachship(sp) {
		sp->file = (struct File *) calloc(1, sizeof (struct File));
		if (sp == NULL) {
			(void) printf("driver: OUT OF MEMORY\n");
E 4
			exit(0);
		}
D 4
		scene[game].ship[n].file -> captured = -1;
E 4
I 4
		sp->file->loadL = L_ROUND;
		sp->file->loadR = L_ROUND;
		sp->file->readyR = R_LOADED|R_INITIAL;
		sp->file->readyL = R_LOADED|R_INITIAL;
		sp->file->stern = nat[sp->nationality]++;
E 4
	}
D 4
	for (n = 0; n < scene[game].vessels; n++){	/* initial loads */
		scene[game].ship[n].file -> loadL = ROUND;
		scene[game].ship[n].file -> loadR = ROUND;
		scene[game].ship[n].file -> readyR = -30000;
		scene[game].ship[n].file -> readyL = -30000;
	}
	if (!nation[2])
		nation[2] = nation[1];
	if (!nation[3])
		nation[3] = nation[2];
	sync();
D 3
	for(;;){
E 3
I 3
	for(;;) {
E 3
		windspeed = scene[game].windspeed;
		winddir = scene[game].winddir;
		turn = scene[game].turn;
E 4
I 4
	for (;;) {
		Sync();
		windspeed = cc->windspeed;
		winddir = cc->winddir;
		turn = cc->turn;
E 4
		next();
		unfoul();
		checkup();
		prizecheck();
		moveall();
		readpos();
		thinkofgrapples();
		boardcomp();
		compcombat();
		readpos();
		resolve();
		reload();
		checksails();
D 4
		sync();
E 4
I 4
		Sync();
E 4
		sleep(7);
E 5
D 4
		sync();
E 4
	}
I 25
	return 0;
E 25
D 22
}
I 6

I 16
/*ARGSUSED*/
E 16
/*VARARGS2*/
Signal(fmt, ship, a, b, c)
char *fmt;
struct ship *ship;
{
E 22
}
E 6
E 1
