h01379
s 00010/00005/00107
d D 5.3 88/06/18 19:55:42 bostic 32 31
c install approved copyright notice
e
s 00009/00003/00103
d D 5.2 88/03/09 12:30:28 bostic 31 30
c written by David Riggle and Edward Wang; add Berkeley specific copyright
e
s 00005/00005/00101
d D 5.1 85/05/29 16:07:35 dist 30 29
c Add copyright
e
s 00006/00000/00100
d D 2.10 85/04/23 21:49:40 edward 29 28
c copyright message
e
s 00000/00240/00100
d D 2.9 85/03/04 18:06:26 edward 28 27
c more cleanup; sail, driver, sail.log merged into single program
e
s 00002/00003/00338
d D 2.8 84/12/12 16:50:25 edward 27 26
c infinite loop in child()
e
s 00028/00053/00313
d D 2.7 84/02/23 16:01:28 edward 26 25
c check errors from Sync(), score logging now done by log(),
c check curses error and screen size with SCREENTEST().
e
s 00002/00002/00364
d D 2.6 84/01/27 15:01:47 edward 25 23
c portability
e
s 00001/00000/00366
d R 2.6 84/01/19 15:19:09 edward 24 23
c setuid(getuid()) after opening sync file
e
s 00002/00002/00364
d D 2.5 83/12/17 12:38:58 edward 23 22
c new grapple and foul data structure.
e
s 00002/00000/00364
d D 2.4 83/12/09 13:28:20 edward 22 21
c turn window bigger, and block alarm when refreshing
e
s 00083/00064/00281
d D 2.3 83/11/02 13:42:57 edward 21 20
c ^C bug fixed?
e
s 00014/00013/00331
d D 2.2 83/11/01 17:35:33 edward 20 19
c try to remove file after a ^C, doesn't really work. later...
e
s 00000/00000/00344
d D 2.1 83/10/31 13:44:48 edward 19 18
c new version
e
s 00009/00013/00335
d D 1.15 83/10/28 21:14:54 edward 18 17
c multiple driver locations, and initial pos bug.
e
s 00012/00115/00336
d D 1.14 83/10/28 19:22:57 edward 17 16
c rearranged player and screen stuff
e
s 00001/00002/00450
d D 1.13 83/10/14 23:07:43 edward 16 15
c lint
e
s 00003/00002/00449
d D 1.12 83/10/14 22:43:51 edward 15 14
c tricky input routines
e
s 00002/00002/00449
d D 1.11 83/10/14 20:54:29 edward 14 13
c don't eyeball yourself.
c plus no more signalflags
e
s 00071/00077/00380
d D 1.10 83/10/10 20:10:43 edward 13 12
c got rid of unnecessary variables
e
s 00339/00678/00118
d D 1.9 83/07/20 17:24:43 edward 12 11
c 
e
s 00026/00003/00770
d D 1.8 83/05/20 21:28:44 root 11 10
c catch SIGCHLD
e
s 00000/00000/00773
d D 1.7 83/05/20 19:09:40 edward 10 9
c moved driver to /usr/games/lib and merged externs.h and globals.c
e
s 00012/00005/00761
d D 1.6 83/05/20 17:55:53 root 9 8
c debugging flag -D
e
s 00665/00697/00101
d D 1.5 83/05/20 17:43:40 root 8 7
c merge
e
s 00002/00001/00796
d D 1.4 83/05/19 22:03:08 leres 7 5
c Assembler doesn't like ta to be a register in main()
e
s 00002/00001/00796
d R 1.4 83/05/19 21:26:01 leres 6 5
c Assembler doesn't like the int ta in main() to be a register
e
s 00003/00000/00794
d D 1.3 83/03/19 13:54:54 leres 5 3
c Added version command
e
s 00003/00000/00794
d R 1.3 83/03/19 13:53:22 leres 4 3
c Added version command
e
s 00009/00004/00785
d D 1.2 83/03/18 15:09:00 leres 3 1
c Added conditional for setuid running of player and driver; if we
c are going to run setuid, then we can make the tmp file mode 600...
e
s 00007/00002/00787
d R 1.2 83/03/18 14:33:23 leres 2 1
c Added conditional for running player and driver setuid;
c If it is desired to run setuid, umask is set to 077, else 011 to
c prevent pirates from fooling with the tmp file.
e
s 00789/00000/00000
d D 1.1 83/03/17 21:10:03 leres 1 0
c date and time created 83/03/17 21:10:03 by leres
e
u
U
t
T
I 29
/*
D 30
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 30
I 30
 * Copyright (c) 1983 Regents of the University of California.
D 31
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 31
I 31
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 32
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 32
I 32
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
E 32
E 31
E 30
 */

E 29
I 1
#ifndef lint
D 30
static	char *sccsid = "%W% %E%";
#endif
E 30
I 30
static char sccsid[] = "%W% (Berkeley) %G%";
D 31
#endif not lint
E 31
I 31
#endif /* not lint */
E 31
E 30
I 8

E 8
#include "player.h"
#include <sys/types.h>
I 12
D 13
#include <wait.h>
E 13
I 13
#include <sys/wait.h>
E 13
E 12
D 8
#include <sys/stat.h>
E 8

D 12
WINDOW *view,*slot;
D 8
/* int devestate; */
E 8
I 8
char done_curses = 0;
E 12
I 12
D 28
int choke(), child();
E 12
E 8

I 21
D 26
static char hasdriver;

E 26
E 21
I 15
D 16
char isplayer = 1;

E 16
E 15
D 12
acceptcombat()
E 12
I 12
/*ARGSUSED*/
main(argc, argv)
int argc;
char **argv;
E 12
{
D 8
    int crew[3], men = 0, rangeofshot, target, temp;
    int n, r, guns[2], load[2], car[2], roll[2];
    int ready[2], index, rakehim, sternrake;
    int shootat[2], /*power,*/ hit[2], closest[2], ship;
    int hhits = 0, ghits = 0, rhits = 0, chits = 0;
    int buf;
    struct shipspecs *ptr;
    struct File *ptr1;
E 8
I 8
D 12
	int crew[3], men = 0, rangeofshot, target, temp;
	int n, r, guns[2], load[2], car[2], roll[2];
	int ready[2], index, rakehim, sternrake;
	int shootat[2], hit[2], closest[2], ship;
	int hhits = 0, ghits = 0, rhits = 0, chits = 0;
	int buf;
	struct shipspecs *ptr;
	struct File *ptr1;
E 12
I 12
D 17
	register struct ship *sp;
D 13
	int aheadfirst, ma;
E 13
	int ta;
I 13
	char aheadfirst;
	int ma;
E 17
E 13
	char nodrive = 0, randomize = 0, debug = 0;
D 17
	char *badstring();
E 17
	extern char _sobuf[];
E 12
E 8

D 8
    ptr = &specs[scene[game].ship[player].shipnum];
    ptr1 = scene[game].ship[player].file;
    crew[0] = ptr -> crew1;
    crew[1] = ptr -> crew2;
    crew[2] = ptr -> crew3;
    ready[0] = ptr1 -> readyL;
    ready[1] = ptr1 -> readyR;
    load[0] = ptr1 -> loadL;
    load[1] = ptr1 -> loadR;
    guns[0] = ptr -> gunL;
    guns[1] = ptr -> gunR;
    car[0] = ptr -> carL;
    car[1] = ptr -> carR;
    for (n = 0; n < 3; n++){
	if (ptr1 -> OBP[n].turnsent)
	    men += ptr1 -> OBP[n].mensent;
    }
    for (n = 0; n < 3; n++){
	if (ptr1 -> DBP[n].turnsent)
	    men += ptr1 -> DBP[n].mensent;
    }
    if (men) {
	crew[0] = men/100 ? 0 : crew[0] != 0;
	crew[1] = (men%100)/10 ? 0 : crew[1] != 0;
	crew[2] = men%10 ? 0 : crew[2] != 0;
    }
    for (r = 0; r < 2; r++) {
	if ((guns[r] || car[r]) && crew[2] && load[r] &&
	  ready[r] <= 0 && !ptr1 -> struck &&
	  ((closest[r] = closestenemy(player, (r ? 'r' : 'l'), 1)) != 30000)) {
		switch(load[r]) {
		    case GRAPE:
			rangeofshot = 1;
			break;
		    case CHAIN:
			rangeofshot = 3;
			break;
		    case DOUBLE:
			rangeofshot = 1;
			break;
		    case ROUND:
			rangeofshot = 10;
			break;
		}
/*		if (power)
		    rangeofshot = 20; */
		if ((target = range(player, closest[r])) <= rangeofshot &&
		  !scene[game].ship[closest[r]].file -> struck &&
		  (guns[r] || (car[r] && target < 3))) {
		    Signal("%s (%c%c) within range of %s broadside.", closest[r], (r?"right":"left"));
		    if (load[r] > CHAIN && target < 6) {
			Signal("Aim for hull or rigging? ", -1, 0);
			while ((buf = getch()) == EOF);
			    addch(buf);
			if(buf == 'r')
			    shootat[r] = RIGGING;
			else if (buf == 'h')
			    shootat[r] = HULL;
			else {
			    shootat[r] = -1;
			    Signal("'Avast there! Hold your fire.'", -1, 0);
E 8
I 8
D 12
	ptr = &specs[scene[game].ship[player].shipnum];
	ptr1 = scene[game].ship[player].file;
	crew[0] = ptr -> crew1;
	crew[1] = ptr -> crew2;
	crew[2] = ptr -> crew3;
	ready[0] = ptr1 -> readyL;
	ready[1] = ptr1 -> readyR;
	load[0] = ptr1 -> loadL;
	load[1] = ptr1 -> loadR;
	guns[0] = ptr -> gunL;
	guns[1] = ptr -> gunR;
	car[0] = ptr -> carL;
	car[1] = ptr -> carR;
	for (n = 0; n < 3; n++) {
		if (ptr1 -> OBP[n].turnsent)
			men += ptr1 -> OBP[n].mensent;
	}
	for (n = 0; n < 3; n++) {
		if (ptr1 -> DBP[n].turnsent)
			men += ptr1 -> DBP[n].mensent;
	}
	if (men) {
		crew[0] = men/100 ? 0 : crew[0] != 0;
		crew[1] = (men%100)/10 ? 0 : crew[1] != 0;
		crew[2] = men%10 ? 0 : crew[2] != 0;
	}
	for (r = 0; r < 2; r++) {
		if ((guns[r] || car[r]) && crew[2] && load[r] && ready[r] <= 0 && !ptr1 -> struck && ((closest[r] = closestenemy(player, (r ? 'r' : 'l'), 1)) != 30000)) {
			switch(load[r]) {
			case GRAPE:
				rangeofshot = 1;
				break;
			case CHAIN:
				rangeofshot = 3;
				break;
			case DOUBLE:
				rangeofshot = 1;
				break;
			case ROUND:
				rangeofshot = 10;
				break;
E 8
			}
D 8
		    } else {
			shootat[r] = RIGGING;
			Signal("Fire? ", -1, 0);
			while((buf = getch()) == EOF);
			    addch(buf);
			if (buf == 'n') {
			    shootat[r] = -1;
			    Signal("Belay that! Hold your fire.", -1, 0);
			}
		    }
		    if (shootat[r] != -1) {
			fired = 1;
			rakehim = gunsbear(player, closest[r]) && !gunsbear(closest[r], player);
			temp = portside(closest[r], player, 1) - pos[closest[r]].dir + 1;
			if (temp < 1)
			    temp += 8;
			if (temp > 8)
			    temp -= 8;
			sternrake = temp > 4 && temp < 6;
/*			if (power) {
			    sternrake = 1;
			    rakehim = 1;
			    } */
			if (rakehim && !sternrake)
			    Signal("Raking the %s!", closest[r], 0);
			else if (rakehim && sternrake)
			    Signal("Stern Rake! %s splintering!", closest[r], 0);
			index = guns[r];
			if (target < 3)
			    index += car[r];
			index = (index - 1)/3;
			index = index > 8 ? 8 : index;
			if (!rakehim)
			    hit[r] = HDT[index][target-1];
			else
			    hit[r] = HDTrake[index][target-1];
			if (rakehim && sternrake)
			    hit[r]++;
			hit[r] += QUAL[index][ptr -> qual-1];
			for (n=0; n < 3 && ptr1 -> captured < 0; n++)
			    if (!crew[n])
				if (index <= 5)
				    hit[r]--;
				else
				    hit[r] -= 2;
			if (ready[r] <= -30000)
			    if (index <= 3)
				hit[r]++;
			    else
				hit[r] += 2;
			if (ptr1 -> captured > -1)
			    if (index <= 1)
				hit[r]--;
			    else
				hit[r] -= 2;
			hit[r] += AMMO[index][load[r] - 1];
			if (((temp = ptr -> class) >= 5 || temp == 1) && windspeed == 5)
			    hit[r]--;
			if (windspeed == 6 && temp == 4)
			    hit[r] -= 2;
			if (windspeed == 6 && temp <= 3)
			    hit[r]--;
			if (hit[r] >= 0) {
			    roll[r] = die();
			    if (load[r] == GRAPE)
				chits = hit[r];
			    else {
				hit[r] = hit[r] > 10 ? 10 : hit[r];
				chits = shootat[r] ? RigTable[hit[r]][roll[r]-1].C : HullTable[hit[r]][roll[r]-1].C;
				rhits = shootat[r] ? RigTable[hit[r]][roll[r]-1].R : HullTable[hit[r]][roll[r]-1].R;
/*				if (devestate && power) {
				hhits = 10;
				devestate = 0;
E 8
I 8
			if ((target = range(player, closest[r])) <= rangeofshot && !scene[game].ship[closest[r]].file -> struck && (guns[r] || (car[r] && target < 3))) {
				Signal("%s (%c%c) within range of %s broadside.", closest[r], (r?"right":"left"));
				if (load[r] > CHAIN && target < 6) {
					Signal("Aim for hull or rigging? ", -1, 0);
					while ((buf = getch()) == EOF);
					addch(buf);
					if(buf == 'r')
						shootat[r] = RIGGING;
					else if (buf == 'h')
						shootat[r] = HULL;
					else {
						shootat[r] = -1;
						Signal("'Avast there! Hold your fire.'", -1, 0);
					}
				} else {
					shootat[r] = RIGGING;
					Signal("Fire? ", -1, 0);
					while ((buf = getch()) == EOF);
					addch(buf);
					if (buf == 'n') {
						shootat[r] = -1;
						Signal("Belay that! Hold your fire.", -1, 0);
					}
E 8
				}
D 8
			    else */
				hhits = shootat[r] ? RigTable[hit[r]][roll[r]-1].H : HullTable[hit[r]][roll[r]-1].H;
				ghits = shootat[r] ? RigTable[hit[r]][roll[r]-1].G : HullTable[hit[r]][roll[r]-1].G;
				if (scene[game].ship[closest[r]].file -> FS)
				    rhits *= 2;
				if (load[r] == CHAIN) {
				    ghits = 0;
				    hhits = 0;
E 8
I 8
				if (shootat[r] != -1) {
					fired = 1;
					rakehim = gunsbear(player, closest[r]) && !gunsbear(closest[r], player);
					temp = portside(closest[r], player, 1) - pos[closest[r]].dir + 1;
					if (temp < 1)
						temp += 8;
					if (temp > 8)
						temp -= 8;
					sternrake = temp > 4 && temp < 6;
					if (rakehim && !sternrake)
						Signal("Raking the %s!", closest[r], 0);
					else if (rakehim && sternrake)
						Signal("Stern Rake! %s splintering!", closest[r], 0);
					index = guns[r];
					if (target < 3)
						index += car[r];
					index = (index - 1)/3;
					index = index > 8 ? 8 : index;
					if (!rakehim)
						hit[r] = HDT[index][target-1];
					else
						hit[r] = HDTrake[index][target-1];
					if (rakehim && sternrake)
						hit[r]++;
					hit[r] += QUAL[index][ptr -> qual-1];
					for (n=0; n < 3 && ptr1 -> captured < 0; n++)
						if (!crew[n])
							if (index <= 5)
								hit[r]--;
							else
								hit[r] -= 2;
					if (ready[r] <= -30000)
						if (index <= 3)
							hit[r]++;
						else
							hit[r] += 2;
					if (ptr1 -> captured > -1)
						if (index <= 1)
							hit[r]--;
						else
							hit[r] -= 2;
					hit[r] += AMMO[index][load[r] - 1];
					if (((temp = ptr -> class) >= 5 || temp == 1) && windspeed == 5)
						hit[r]--;
					if (windspeed == 6 && temp == 4)
						hit[r] -= 2;
					if (windspeed == 6 && temp <= 3)
						hit[r]--;
					if (hit[r] >= 0) {
						roll[r] = die();
						if (load[r] == GRAPE)
							chits = hit[r];
						else {
							struct Tables *t;
							hit[r] = hit[r] > 10 ? 10 : hit[r];
							t = &(shootat[r] ? RigTable : HullTable)[hit[r]][roll[r]-1];
							chits = t->C;
							rhits = t->R;
							hhits = t->H;
							ghits = t->G;
							if (scene[game].ship[closest[r]].file -> FS)
								rhits *= 2;
							if (load[r] == CHAIN) {
								ghits = 0;
								hhits = 0;
							}
						}
						table(shootat[r], load[r], hit[r], closest[r], player, roll[r]);
					}
					scroll = 18;
					move(scroll++, 0);
					clearline();
					printw("Damage inflicted on the %s:", scene[game].ship[closest[r]].shipname);
					move(scroll++, 0);
					clearline();
					printw("\t%d HULL, %d GUNS, %d CREW, %d RIGGING", hhits, ghits, chits, rhits);
					load[r] = 0;
					if (!r) {
						ptr1 -> loadL = 0;
						ptr1 -> readyL = 0;
					} else {
						ptr1 -> loadR = 0;
						ptr1 -> readyR = 0;
					}
E 8
				}
D 8
			    }
/*			    if (power)
				table(shootat[r], load[r], 10, closest[r], player, 6);
			    else */
				table(shootat[r], load[r], hit[r], closest[r], player, roll[r]);
			}
			scroll = 18;
			move(scroll++, 0);
			clearline();
			printw("Damage inflicted on the %s:", scene[game].ship[closest[r]].shipname);
			move(scroll++, 0);
			clearline();
			printw("\t%d HULL, %d GUNS, %d CREW, %d RIGGING", hhits, ghits, chits, rhits);
			load[r] = 0;
			if (!r) {
			    ptr1 -> loadL = 0;
			    ptr1 -> readyL = 0;
E 8
			} else {
D 8
			    ptr1 -> loadR = 0;
			    ptr1 -> readyR = 0;
E 8
I 8
				load[r] = 0;
				Signal("Unable to fire %s broadside", -1, (r?"right":"left"));
E 8
			}
D 8
		    }
		} else {
		    load[r] = 0;
		    Signal("Unable to fire %s broadside", -1, (r?"right":"left"));
		}
	    } else
		Signal("Unable to fire %s broadside", -1, (r?"right":"left"));
E 8
I 8
		} else
			Signal("Unable to fire %s broadside", -1, (r?"right":"left"));
E 8
	}
}
E 12
I 12
	setbuf(stdout, _sobuf);
I 16
	isplayer = 1;
E 16
E 12

D 12
leave(conditions)
int conditions;
{
D 8
    FILE *fp;
    int people;
    float net;
    char * capn;
    char message[60];
    register int n;
    struct logs log[10], temp;
E 8
I 8
	FILE *fp;
	int people;
	float net;
	char * capn;
	char message[60];
	register int n;
	struct logs log[10], temp;
E 8

D 8
    signal(SIGHUP, SIG_IGN);
    signal(SIGINT, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    signal(SIGALRM, SIG_IGN);
E 8
I 8
	signal(SIGHUP, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGALRM, SIG_IGN);
I 11
	signal(SIGCHLD, SIG_IGN);
E 11
E 8

D 8
    if (conditions != -1) {
	capn = scene[game].ship[player].file -> captain;
	sprintf(message,"Captain %s relinquishing.",capn);
	Write(FILES + player, 1, 164, message);
	
	if (fp = fopen(LOGFILE, "r+")) {
	    net = (float) (scene[game].ship[player].file -> points) / specs[scene[game].ship[player].shipnum].pts;
	    people = getw(fp);
	    n = fread(log, sizeof(struct logs), 10, fp);
	    for (; n < 10; n++)
		log[n].fname[0] = log[n].uid = log[n].fshipnum = log[n].fgamenum = log[n].netpoints = 0;
	    rewind(fp);
	    if(people < 0)
		putw(1, fp);
	    else
		putw(people+1, fp);
	    for (n=0; n < 10; n++)
		if (net > (float) log[n].netpoints / specs[scene[log[n].fgamenum].ship[log[n].fshipnum].shipnum].pts) {
		    fwrite(log, sizeof(struct logs), n, fp);
		    strcpy(temp.fname, capn);
		    temp.uid = getuid();
		    temp.fshipnum = player;
		    temp.fgamenum = game;
		    temp.netpoints = scene[game].ship[player].file -> points;
		    fwrite(&temp, sizeof(struct logs), 1, fp);
		    fwrite(log + n, sizeof(struct logs), 9 - n, fp);
		    break;
E 8
I 8
	if (conditions != -1) {
		capn = scene[game].ship[player].file -> captain;
		sprintf(message,"Captain %s relinquishing.",capn);
		Write(FILES + player, 1, 164, message);

		if (fp = fopen(LOGFILE, "r+")) {
			net = (float) (scene[game].ship[player].file -> points) / specs[scene[game].ship[player].shipnum].pts;
			people = getw(fp);
			n = fread(log, sizeof(struct logs), 10, fp);
			for (; n < 10; n++)
				log[n].fname[0] = log[n].uid = log[n].fshipnum = log[n].fgamenum = log[n].netpoints = 0;
			rewind(fp);
			if(people < 0)
				putw(1, fp);
			else
				putw(people+1, fp);
			for (n=0; n < 10; n++)
				if (net > (float) log[n].netpoints / specs[scene[log[n].fgamenum].ship[log[n].fshipnum].shipnum].pts) {
					fwrite(log, sizeof(struct logs), n, fp);
					strcpy(temp.fname, capn);
					temp.uid = getuid();
					temp.fshipnum = player;
					temp.fgamenum = game;
					temp.netpoints = scene[game].ship[player].file -> points;
					fwrite(&temp, sizeof(struct logs), 1, fp);
					fwrite(log + n, sizeof(struct logs), 9 - n, fp);
					break;
				}
			fclose(fp);
E 12
I 12
	while (*++argv && **argv == '-')
		switch (*++*argv) {
		case 'd':
			nodrive = 1;
			break;
		case 'D':
			debug++;
			break;
		case 'x':
			randomize = 1;
			break;
		default:
			printf("Unknown flag '%s'\n",*argv);
			break;
E 12
E 8
		}
D 8
		fclose(fp);
	    }
	    Write(FILES + player, 1, 0, " ");
	    Write(SCENARIO, 0, 8, scene[game].people - 1);
	    screen();
	    fclose(syncfile);
	    Signal("It looks like you've had it!", -1, 0);
	    if (conditions == 1)
		Signal("Your ship was captured.", -1, 0);
	    if (conditions == 2)
		Signal("No more enemies.", -1, 0);
	    if (conditions == 3)
		Signal("Hurricane!  All ships destroyed.", -1, 0);
	    move(0, LINES-1);
	    scroll = LINES;
	    clearline();
	    refresh();
E 8
I 8
D 12
		Write(FILES + player, 1, 0, " ");
		Write(SCENARIO, 0, 8, scene[game].people - 1);
		if (done_curses) {
E 12
I 12
	if (*argv)
		game = atoi(*argv);
	else
		game = -1;
	initialize(nodrive, randomize, debug);
	Signal("Aye aye, Sir", (struct ship *)0);
D 17
	for (;;) {
D 15
		prompt();
		switch (sgetch(0)) {
E 15
I 15
		switch (sgetch("~\b", (struct ship *)0, 0)) {
E 15
		case 'm':
			if (mc->crew3 && !snagged(ms)
			    && windspeed != 0) {
D 13
				ta = maxturns(ms);
				aheadfirst = ta & 0100000;
E 13
I 13
				ta = maxturns(ms, &aheadfirst);
E 13
				ma = maxmove(ms, mf->dir, 0);
D 13
				ta &= 077777;
E 13
				acceptmove(ma, ta, aheadfirst);
			} else
				Signal("Unable to move", (struct ship *)0);
			break;
		case 's':
			acceptsignal();
			break;
		case 'g':
			grapungrap();
			break;
		case 'u':
			unfoulplayer();
			break;
		case 'v':
			Signal("%s", (struct ship *)0, version);
			break;
		case 'b':
			doboarding();
			break;
		case 'f':
			acceptcombat();
			break;
		case 'l':
			loadplayer();
			break;
		case 'c':
			changesail();
			break;
		case 'r':
			repair();
			break;
		case 'B':
			Signal("'Hands to stations!'", (struct ship *)0);
			unboard(ms, ms, 1);	/* cancel DBP's */
			unboard(ms, ms, 0);	/* cancel offense */
			break;
		case '\f':
			centerview();
			board();
E 12
			screen();
D 12
			Signal("It looks like you've had it!", -1, 0);
			if (conditions == 1)
				Signal("Your ship was captured.", -1, 0);
D 11
			if (conditions == 2)
E 11
I 11
			else if (conditions == 2)
E 11
				Signal("No more enemies.", -1, 0);
D 11
			if (conditions == 3)
E 11
I 11
			else if (conditions == 3)
E 11
				Signal("Hurricane!  All ships destroyed.",
D 11
				-1, 0);
E 11
I 11
					-1, 0);
			else if (conditions == 4)
				Signal("The driver died.", -1, 0);
E 11
			move(0, LINES-1);
			scroll = LINES;
			clearline();
			refresh();
I 11
		} else {
			if (conditions == 4)
				printf("The driver died.\n");
E 12
I 12
			break;
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
D 14
				eyeball(sp);
E 14
I 14
				if (sp != ms)
					eyeball(sp);
E 14
			break;
		case 'i':
			eyeball(closestenemy(ms, 0, 1));
			break;
		case 'C':
			centerview();
			draw_view();
			break;
		case 'U':
			upview();
			draw_view();
			break;
		case 'D':
		case 'N':
			downview();
			draw_view();
			break;
		case 'H':
			leftview();
			draw_view();
			break;
		case 'J':
			rightview();
			draw_view();
			break;
		case 'F':
			lookout();
			break;
		case 'S':
			dont_adjust = !dont_adjust;
			break;
E 12
E 11
		}
D 12
		fclose(syncfile);
E 12
I 12
D 14
		signalflags();
E 14
		lost();
E 12
E 8
	}
E 17
I 17
	play();
E 17
D 8
    nocrmode();
    echo();
    endwin();
    exit(0);
E 8
I 8
D 12
	if (done_curses) {
		nocrmode();
		echo();
		endwin();
	}
	exit(0);
E 12
E 8
}

D 12
choke()
{
D 8
    leave(0);
E 8
I 8
	leave(0);
E 8
}

I 11
#include <wait.h>

child()
{
	union wait status;
	int pid;

	signal(SIGCHLD, SIG_IGN);
	do {
		pid = wait3(&status, WNOHANG|WUNTRACED, 0);
		if (pid < 0 || pid > 0 && !WIFSTOPPED(status))
			leave(4);
	} while (pid != 0);
	signal(SIGCHLD, child);
}

E 11
grapungrap()
{
D 8
    register int n, k, l, number, captured;
    int buf;
E 8
I 8
	register int n, k, l, number, captured;
	int buf;
E 8

D 8
    for (n=0; n < scene[game].vessels ; n++) {
	if (n != player && (range(player, n) <= 1 || grapple(player, n))) {
	    if ((captured = scene[game].ship[n].file -> captured) < 0)
		captured = n;
	    Signal("Attempt to grapple or ungrapple %s (%c%c): ", n, 0);
	    while((buf = getch()) == EOF);
		addch(buf);
	    if (buf == 'g') {
		number = die() < 3;
		if (!number && scene[game].ship[player].nationality == scene[game].ship[captured].nationality)
		    number = 1;
		if (number) {
		    for (l=0; l < 10 && scene[game].ship[player].file -> grapples[l].turnfoul; l++);
			if (!scene[game].ship[player].file -> grapples[l].turnfoul) {
			    Write(FILES + player, 0, 124 + l*4, turn);
			    Write(FILES + player, 0, 124 + l*4 + 2, n);
E 8
I 8
	for (n=0; n < scene[game].vessels ; n++) {
		if (n != player && (range(player, n) <= 1 || grapple(player, n))) {
			if ((captured = scene[game].ship[n].file -> captured) < 0)
				captured = n;
			Signal("Attempt to grapple or ungrapple %s (%c%c): ", n, 0);
			while ((buf = getch()) == EOF);
			addch(buf);
			if (buf == 'g') {
				number = die() < 3;
				if (!number && scene[game].ship[player].nationality == scene[game].ship[captured].nationality)
					number = 1;
				if (number) {
					for (l=0; l < 10 && scene[game].ship[player].file -> grapples[l].turnfoul; l++);
					if (!scene[game].ship[player].file -> grapples[l].turnfoul) {
						Write(FILES + player, 0, 124 + l*4, turn);
						Write(FILES + player, 0, 124 + l*4 + 2, n);
					}
					for (l=0; l < 10 && scene[game].ship[n].file -> grapples[l].turnfoul; l++);
					if (!scene[game].ship[n].file -> grapples[l].turnfoul) {
						Write(FILES + n, 0, 124 + l*4, turn);
						Write(FILES + n, 0, 124 + l*4 + 2, player);
					}
				}
				if (number) {
					Signal("Attempt succeeds!", 0, 0);
					makesignal("grappled with %s (%c%c)", n, player);
				} else
					Signal("Attempt fails.", 0, 0);
E 8
			}
D 8
			for (l=0; l < 10 && scene[game].ship[n].file -> grapples[l].turnfoul; l++);
			    if (!scene[game].ship[n].file -> grapples[l].turnfoul) {
				Write(FILES + n, 0, 124 + l*4, turn);
				Write(FILES + n, 0, 124 + l*4 + 2, player);
			    }
		    }
		    if (number) {
			Signal("Attempt succeeds!", 0, 0);
			makesignal("grappled with %s (%c%c)", n, player);
		    } else
			Signal("Attempt fails.", 0, 0);
		}
		if (buf == 'u'){ for (k=0; k < 10; k++) {
		    if (scene[game].ship[player].file -> grapples[k].turnfoul && n == scene[game].ship[player].file -> grapples[k].toship) {
			if (die() < 3 || scene[game].ship[player].nationality == scene[game].ship[captured].nationality) {
			    cleangrapple(player, n, k);
				Signal("Attempt succeeds!", 0, 0);
				makesignal("ungrappling with %s (%c%c)", n, player);
			    } else
				Signal("Attempt fails.", 0, 0);
E 8
I 8
			if (buf == 'u') {
				for (k=0; k < 10; k++) {
					if (scene[game].ship[player].file -> grapples[k].turnfoul && n == scene[game].ship[player].file -> grapples[k].toship) {
						if (die() < 3 || scene[game].ship[player].nationality == scene[game].ship[captured].nationality) {
							cleangrapple(player, n, k);
							Signal("Attempt succeeds!", 0, 0);
							makesignal("ungrappling with %s (%c%c)", n, player);
						} else
							Signal("Attempt fails.", 0, 0);
					}
				}
E 8
			}
D 8
		    }
E 8
		}
D 8
	    }
E 8
	}
}

unfoulplayer()
{
D 8
    register int n, toship;
    int buf;
E 8
I 8
	register int n, toship;
	int buf;
E 8

D 8
    for (n=0; n < 10; n++) {
	if (scene[game].ship[player].file -> fouls[n].turnfoul) {
	    Signal("Attempt to unfoul with the %s (%c%c)? ", (toship = scene[game].ship[player].file -> fouls[n].toship), 0);
	    while((buf = getch()) == EOF);
		addch(buf);
	    if (buf == 'y' && die() < 3) {
		cleanfoul(player, toship, n);
		Signal("Attempt succeeds!", 0, 0);
		makesignal("unfouling %s (%c%c)", toship, player);
	    } else if (buf == 'y')
		Signal("Attempt fails.", 0, 0);
E 8
I 8
	for (n=0; n < 10; n++) {
		if (scene[game].ship[player].file -> fouls[n].turnfoul) {
			Signal("Attempt to unfoul with the %s (%c%c)? ", (toship = scene[game].ship[player].file -> fouls[n].toship), 0);
			while ((buf = getch()) == EOF);
			addch(buf);
			if (buf == 'y' && die() < 3) {
				cleanfoul(player, toship, n);
				Signal("Attempt succeeds!", 0, 0);
				makesignal("unfouling %s (%c%c)", toship, player);
			} else if (buf == 'y')
				Signal("Attempt fails.", 0, 0);
		}
E 8
	}
D 8
    }
E 8
}

E 12
D 9
initialize(nodriver, randomize)
char randomize, nodriver;
E 9
I 9
initialize(nodriver, randomize, debug)
char randomize, nodriver, debug;
E 9
{
D 8
    char comm[80], num[5], file[25], capn;
    char message[60];
    int load = ROUND, ready = -30000;
    int people = 0;
D 3
    int pid;
E 3
I 3
    int pid, omask;
E 3
    register int n;
    register int k;
    struct stat Stat;
    char *nameptr;
E 8
I 8
D 12
	char comm[80], file[25], capn;
E 12
I 12
	register struct File *fp;
	register struct ship *sp;
D 13
	char captain[80], file[25];
E 13
I 13
	char captain[80];
E 13
E 12
	char message[60];
D 12
	int load = ROUND, ready = -30000;
E 12
I 12
	int load;
E 12
D 13
	int people = 0;
E 13
I 13
D 21
	int active;
E 21
E 13
D 12
	int pid;
E 12
	register int n;
D 12
	register int k;
E 12
	char *nameptr;
I 12
	int nat[NNATION];
E 12
E 8

I 26
	if (!SCREENTEST()) {
		printf("Can't sail on this terminal.\n");
		exit(1);
	}

E 26
D 8
    srand(pid = getpid());
D 3
    umask(0111);
E 3
    initscr();
    view = newwin(ROWSINVIEW, COLSINVIEW, 2, 1);
    slot = newwin(ROWSINVIEW, 3, 2, 1+COLSINVIEW);
E 8
I 8
D 12
	srand(pid = getpid());
E 12
I 12
	(void) srand(getpid());
E 12
E 8

D 8
    if (game < 0) {
	puts("Choose a scenario:\n");
	puts("\n\tNUMBER\tSHIPS\tIN PLAY\tTITLE");
	for (n=0; n < NUMOFSCENES; n++) {
	    sprintf(file, "/tmp/.%d", n);
	    printf("\t%d):\t%d", n, scene[n].vessels);
	    if (stat(file, &Stat) >= 0)
		printf("\tYES");
	    else
		printf("\tno");
	    printf("\t%s\n", scene[n].name);
	}
E 8
I 8
	if (game < 0) {
D 12
		puts("Choose a scenario:\n");
		puts("\n\tNUMBER\tSHIPS\tIN PLAY\tTITLE");
		for (n=0; n < NUMOFSCENES; n++) {
			sprintf(file, "/tmp/.%d", n);
E 12
I 12
		(void) puts("Choose a scenario:\n");
		(void) puts("\n\tNUMBER\tSHIPS\tIN PLAY\tTITLE");
		for (n = 0; n < NSCENE; n++) {
E 12
D 13
			printf("\t%d):\t%d", n, scene[n].vessels);
I 12
			(void) sprintf(file, "/tmp/.%d", n);
E 12
			if (access(file, 0) >= 0)
				printf("\tYES");
			else
				printf("\tno");
			printf("\t%s\n", scene[n].name);
E 13
I 13
			/* ( */
			printf("\t%d):\t%d\t%s\t%s\n", n, scene[n].vessels,
				sync_exists(n) ? "YES" : "no",
				scene[n].name);
E 13
		}
E 8
reprint:
D 8
	printf("\nScenario number? ");
	scanf("%d", &game);
	while (getchar() != '\n');
    }
    if (game < 0 || game >= NUMOFSCENES) {
	puts("Very funny.");
	endwin();
	exit(1);
    }
    sprintf(file, "/tmp/.%d", game);
D 3
    if (stat(file, &Stat) < 0 )
E 3
I 3
    if (stat(file, &Stat) < 0 ) {
E 8
I 8
		printf("\nScenario number? ");
D 12
		fflush(stdout);
		scanf("%d", &game);
		while (getchar() != '\n');
E 12
I 12
		(void) fflush(stdout);
		(void) scanf("%d", &game);
		while (getchar() != '\n')
			;
E 12
	}
D 12
	if (game < 0 || game >= NUMOFSCENES) {
		puts("Very funny.");
E 12
I 12
	if (game < 0 || game >= NSCENE) {
		(void) puts("Very funny.");
E 12
		exit(1);
	}
D 12
	sprintf(file, "/tmp/.%d", game);
E 12
I 12
	cc = &scene[game];
D 25
	ls = cc->ship + cc->vessels;
E 25
I 25
	ls = SHIP(cc->vessels);
E 25

I 20
D 21
	(void) signal(SIGHUP, choke);
	(void) signal(SIGINT, choke);
	(void) signal(SIGQUIT, choke);

E 20
D 13
	(void) sprintf(file, "/tmp/.%d", game);
E 12
	if (access(file, 0) < 0) {
		int omask;
E 8
#ifdef SETUID
D 8
	omask = umask(077);
E 8
I 8
		omask = umask(077);
E 8
#else
D 8
	omask = umask(011);
E 8
I 8
		omask = umask(011);
E 8
#endif
E 3
D 8
	syncfile = fopen(file, "w+");
D 3
    else {
E 3
I 3
	umask(omask);
    } else {
E 3
	syncfile = fopen(file, "r+");
	people = 1;
    }
    lastsync = 0;
    for (n=0; n < scene[game].vessels; n++) {
	nation[scene[game].ship[n].nationality + 1] = n + 1;
	if ((scene[game].ship[n].file =  (struct File *) calloc(1, sizeof(struct File))) == NULL) {
	    puts("OUT OF MEMORY");
	    endwin();
	    exit(0);
E 8
I 8
		syncfile = fopen(file, "w+");
D 12
		umask(omask);
E 12
I 12
		(void) umask(omask);
E 12
	} else {
		syncfile = fopen(file, "r+");
		people = 1;
E 13
I 13
	active = sync_exists(game);
	if (sync_open() < 0) {
		perror("sail: syncfile");
		exit(1);
E 13
E 8
	}
D 8
	scene[game].ship[n].file -> captured = -1;
    }
    if (!nation[2])
	nation[2] = nation[1];
    if (!nation[3])
	nation[3] = nation[2];
    if (people > 0) {
	puts("Synchronizing with the other players...");
	fflush(stdout);
	sync();
	capn = 1;
	for (n=0; n < scene[game].vessels && capn; n++) {
	    capn = scene[game].ship[n].file -> captain[0];
	    if (scene[game].ship[n].file -> struck || scene[game].ship[n].file -> captured > -1)
E 8
I 8
D 13
	lastsync = 0;
E 13
D 12
	for (n=0; n < scene[game].vessels; n++) {
		nation[scene[game].ship[n].nationality + 1] = n + 1;
		if ((scene[game].ship[n].file =  (struct File *) calloc(1, sizeof(struct File))) == NULL) {
			puts("OUT OF MEMORY");
E 12
I 12

E 21
	for (n = 0; n < NNATION; n++)
		nat[n] = 0;
	foreachship(sp) {
		sp->file = (struct File *) calloc(1, sizeof (struct File));
		if (sp->file == NULL) {
			(void) puts("OUT OF MEMORY");
E 12
			exit(0);
		}
I 23
		sp->file->index = sp - SHIP(0);
E 23
D 12
		scene[game].ship[n].file -> captured = -1;
E 12
I 12
		sp->file->stern = nat[sp->nationality]++;
I 18
		sp->file->dir = sp->shipdir;
		sp->file->row = sp->shiprow;
		sp->file->col = sp->shipcol;
E 18
E 12
	}
I 18
	windspeed = cc->windspeed;
	winddir = cc->winddir;
E 18
D 12
	if (!nation[2])
		nation[2] = nation[1];
	if (!nation[3])
		nation[3] = nation[2];
E 12
D 13
	if (people > 0) {
E 13
I 13

D 21
	if (active) {
E 21
I 21
	(void) signal(SIGHUP, choke);
	(void) signal(SIGINT, choke);
D 27
	(void) signal(SIGQUIT, choke);
E 27

	hasdriver = sync_exists(game);
	if (sync_open() < 0) {
		perror("sail: syncfile");
		exit(1);
	}

	if (hasdriver) {
E 21
E 13
D 12
		puts("Synchronizing with the other players...");
		fflush(stdout);
		sync();
E 8
		capn = 1;
I 8
		for (n=0; n < scene[game].vessels && capn; n++) {
			capn = scene[game].ship[n].file -> captain[0];
			if (scene[game].ship[n].file -> struck || scene[game].ship[n].file -> captured > -1)
				capn = 1;
E 12
I 12
		(void) puts("Synchronizing with the other players...");
		(void) fflush(stdout);
D 26
		Sync();
E 26
I 26
		if (Sync() < 0)
			leave(LEAVE_SYNC);
E 26
D 13
		foreachship(sp) {
			if (sp->file->captain[0]
			    || sp->file->struck || sp->file->captured != 0)
E 13
I 13
	}
	for (;;) {
		foreachship(sp)
			if (sp->file->captain[0] == 0 && !sp->file->struck
			    && sp->file->captured == 0)
E 13
				break;
E 12
D 13
		}
E 13
D 12
		if (!capn)
			player = n-1;
		else {
			puts("All ships taken in that scenario.");
			for (n=0; n < scene[game].vessels; n++)
				free(scene[game].ship[n].file);
E 12
I 12
		if (sp >= ls) {
			(void) puts("All ships taken in that scenario.");
			foreachship(sp)
				free((char *)sp->file);
I 13
			sync_close(0);
E 13
E 12
			people = 0;
D 12
			for (n=0; n < 5; n++)
				nation[n] = 0;
			fclose(syncfile);
E 12
I 12
D 13
			(void) fclose(syncfile);
E 13
E 12
			goto reprint;
		}
I 12
D 13
		player = sp - cc->ship;
E 12
	} else
		player = 0;
I 12

E 12
	while (randomize) {
D 12
		static char *color[] =
			{ "(American)", "(British)", "(Spanish)", "(French)" };
		puts(scene[game].name);
		putchar('\n');
		for (n=0; n < scene[game].vessels; n++) {
			printf("  %2d:  %-10s %-15s  (%-2d pts)   ",
				n,
				color[scene[game].ship[n].nationality],
				scene[game].ship[n].shipname,
				specs[scene[game].ship[n].shipnum].pts);
			if(scene[game].ship[n].file -> captain[0])
				puts(scene[game].ship[n].file -> captain);
			else if (scene[game].ship[n].file -> struck)
				puts("(struck)");
			else if(scene[game].ship[n].file -> captured > -1)
				puts("(captured)");
			else
				puts("(available)");
E 12
I 12
		printf("%s\n\n", cc->name);
		foreachship(sp) {
			printf("  %2d:  %-10s %-15s  (%-2d pts)   %s\n",
				sp - SHIP(0),
				countryname[sp->nationality],
				sp->shipname,
				sp->specs->pts,
				saywhat(sp, 1));
E 12
		}
D 12
		putchar('\n');
		printf("Which ship do you want (0-%d)? ",scene[game].vessels-1);
		fflush(stdout);
		if (scanf("%d",&player) != 1 || player < 0 || player >= scene[game].vessels) {
			while (getchar() != '\n');
			puts("Say what?");
E 12
I 12
		printf("\nWhich ship do you want (0-%d)? ", cc->vessels-1);
		(void) fflush(stdout);
		if (scanf("%d", &player) != 1 || player < 0
		    || player >= cc->vessels) {
			while (getchar() != '\n')
				;
			(void) puts("Say what?");
E 13
I 13
D 20
		if (!randomize) {
E 20
I 20
		if (randomize) {
E 20
D 25
			player = sp - cc->ship;
E 25
I 25
			player = sp - SHIP(0);
E 25
E 13
E 12
		} else {
D 12
			while (getchar() != '\n');
			sync();
			if (scene[game].ship[player].file -> captain[0] || scene[game].ship[player].file -> struck || scene[game].ship[player].file -> captured > -1)
				puts("Sorry, that ship is taken.");
E 12
I 12
D 13
			while (getchar() != '\n')
				;
			Sync();
			fp = SHIP(player)->file;
			if (fp->captain[0] || fp->struck || fp->captured != 0)
				(void) puts("Sorry, that ship is taken.");
E 12
			else
				break;
E 13
I 13
			printf("%s\n\n", cc->name);
			foreachship(sp)
				printf("  %2d:  %-10s %-15s  (%-2d pts)   %s\n",
D 23
					sp - SHIP(0),
E 23
I 23
					sp->file->index,
E 23
					countryname[sp->nationality],
					sp->shipname,
					sp->specs->pts,
					saywhat(sp, 1));
			printf("\nWhich ship (0-%d)? ", cc->vessels-1);
			(void) fflush(stdout);
			if (scanf("%d", &player) != 1 || player < 0
			    || player >= cc->vessels) {
				while (getchar() != '\n')
					;
				(void) puts("Say what?");
				player = -1;
			} else
				while (getchar() != '\n')
					;
E 13
		}
I 13
		if (player < 0)
			continue;
D 26
		Sync();
E 26
I 26
		if (Sync() < 0)
			leave(LEAVE_SYNC);
E 26
		fp = SHIP(player)->file;
		if (fp->captain[0] || fp->struck || fp->captured != 0)
			(void) puts("That ship is taken.");
		else
			break;
E 13
E 8
	}
D 8
	if (!capn)
	    player = n-1;
E 8
I 8

D 12
	signal(SIGHUP, choke);
	signal(SIGINT, choke);
	signal(SIGQUIT, choke);
I 11
	signal(SIGCHLD, child);
E 12
I 12
	ms = SHIP(player);
	mf = ms->file;
	mc = ms->specs;
E 12
E 11

D 12
	Write(FILES + player, 1, 0, "begin");  /* he now exists */
E 12
I 12
D 20
	(void) signal(SIGHUP, choke);
	(void) signal(SIGINT, choke);
	(void) signal(SIGQUIT, choke);
E 20
D 21
	(void) signal(SIGCHLD, child);

E 21
D 13
	Write(W_CAPTAIN, ms, 1, (int) "begin", 0, 0, 0);
E 12
	if (people)
D 12
		Write(SCENARIO, 0, 8, scene[game].people + 1);
	sync();
	printf("Your ship is the %s, a %s (%s crew).\n", scene[game].ship[player].shipname, info(player, message), quality(player));
	if ((nameptr = (char *) getenv("NAME")) && *nameptr)
		strcpy(comm,nameptr);
E 12
I 12
		Write(W_PEOPLE, SHIP(0), 0, cc->people + 1, 0, 0, 0);
E 13
I 13
	Write(W_BEGIN, ms, 0, 0, 0, 0, 0);
E 13
D 26
	Sync();
E 26
I 26
	if (Sync() < 0)
		leave(LEAVE_SYNC);
E 26
I 21

	(void) signal(SIGCHLD, child);
	if (!hasdriver && !nodriver) {
		char num[10];
		(void) sprintf(num, "%d", game);
		switch (fork()) {
		case 0:
			execl(DRIVER1, DRIVERNAME, num, 0);
			execl(DRIVER2, DRIVERNAME, num, 0);
			execl(DRIVER3, DRIVERNAME, num, 0);
			perror(DRIVERNAME);
			exit(1);
			break;
		case -1:
			perror("fork");
D 26
			leave(LEAVE_QUIT);
E 26
I 26
			leave(LEAVE_FORK);
E 26
			break;
		default:
			hasdriver++;
		}
	}

E 21
	printf("Your ship is the %s, a %d gun %s (%s crew).\n",
		ms->shipname, mc->guns, classname[mc->class],
		qualname[mc->qual]);
	if ((nameptr = (char *) getenv("SAILNAME")) && *nameptr)
		(void) strncpy(captain, nameptr, sizeof captain);
E 12
E 8
	else {
D 8
	    puts("All ships taken in that scenario.");
	    for (n=0; n < scene[game].vessels; n++)
		free(scene[game].ship[n].file);
	    people = 0;
	    for (n=0; n < 5; n++)
		nation[n] = 0;
	    goto reprint;
E 8
I 8
D 12
		fputs("Your name, Captain? ", stdout);
		fflush(stdout);
		gets(comm);
		if (!*comm) strcpy(comm, "no name");
E 12
I 12
		(void) printf("Your name, Captain? ");
		(void) fflush(stdout);
		(void) gets(captain);
		if (!*captain)
			(void) strcpy(captain, "no name");
E 12
E 8
	}
D 8
    } else
	player = 0;
    while (randomize) {
	static char *color[] =
	    { "(American)", "(British)", "(Spanish)", "(French)" };

	puts(scene[game].name);
	putchar('\n');
	for (n=0; n < scene[game].vessels; n++) {
	    printf("  %2d:  %-10s %-15s  (%-2d pts)   ", n,
	      color[scene[game].ship[n].nationality],
	      scene[game].ship[n].shipname,
	      specs[scene[game].ship[n].shipnum].pts);
	    if(scene[game].ship[n].file -> captain[0])
		puts(scene[game].ship[n].file -> captain);
	    else if (scene[game].ship[n].file -> struck)
		puts("(struck)");
	    else if(scene[game].ship[n].file -> captured > -1)
		puts("(captured)");
	    else
		puts("(available)");
E 8
I 8
D 12
	comm[19] = '\0';
	for (k=0; k < 2; k++) {
		printf("\nInitial broadside %s (grape, chain, round, double): ", (k ? "right" : "left"));
		fflush(stdout);
		scanf("%s", file);
		switch(*file) {
E 12
I 12
	captain[sizeof captain - 1] = '\0';
I 13
	Write(W_CAPTAIN, ms, 1, (int)captain, 0, 0, 0);
E 13
	for (n = 0; n < 2; n++) {
I 13
		char buf[10];

E 13
		printf("\nInitial broadside %s (grape, chain, round, double): ",
			n ? "right" : "left");
		(void) fflush(stdout);
D 13
		(void) scanf("%s", file);
		switch (*file) {
E 13
I 13
		(void) scanf("%s", buf);
		switch (*buf) {
E 13
E 12
		case 'g':
D 12
			load = GRAPE;
E 12
I 12
			load = L_GRAPE;
E 12
			break;
		case 'c':
D 12
			load = CHAIN;
E 12
I 12
			load = L_CHAIN;
E 12
			break;
		case 'r':
D 12
			load = ROUND;
E 12
I 12
			load = L_ROUND;
E 12
			break;
		case 'd':
D 12
			load = DOUBLE;
E 12
I 12
			load = L_DOUBLE;
E 12
			break;
I 12
		default:
			load = L_ROUND;
E 12
		}
D 12
		if (k) {
			scene[game].ship[player].file -> loadR = load;
			scene[game].ship[player].file -> readyR = ready;
E 12
I 12
		if (n) {
			mf->loadR = load;
			mf->readyR = R_LOADED|R_INITIAL;
E 12
		} else {
D 12
			scene[game].ship[player].file -> loadL = load;
			scene[game].ship[player].file -> readyL = ready;
E 12
I 12
			mf->loadL = load;
			mf->readyL = R_LOADED|R_INITIAL;
E 12
		}
E 8
	}
D 8
	putchar('\n');
	printf("Which ship do you want (0-%d)? ",scene[game].vessels-1);
	if (scanf("%d",&player) != 1 || player < 0 || player >= scene[game].vessels) {
	    while (getchar() != '\n');
		puts("Say what?");
	} else {
	    while (getchar() != '\n');
	    sync();
	    if (scene[game].ship[player].file -> captain[0] || scene[game].ship[player].file -> struck || scene[game].ship[player].file -> captured > -1)
		puts("Sorry, that ship is taken.");
	    else
		break;
E 8
I 8
D 12
	Write(FILES + player, 1, 0, comm);
E 12
I 12
D 13
	Write(W_CAPTAIN, ms, 1, (int)captain, 0, 0, 0);
E 12
	if (!people && !nodriver) {
E 13
I 13
D 21
	if (!active && !nodriver) {
E 13
		char num[10];
D 12
		sprintf(num, "%d", game);
E 12
I 12
		(void) sprintf(num, "%d", game);
E 12
		if (!fork()) {
D 9
			execl(DRIVER, DRIVERNAME, num, 0);
E 9
I 9
D 18
			if (debug)
				execl(DEBUGDRIVER, DRIVERNAME, num, 0);
			else
				execl(DRIVER, DRIVERNAME, num, 0);
E 9
			perror(DRIVER);
E 18
I 18
			execl(DRIVER1, DRIVERNAME, num, 0);
			execl(DRIVER2, DRIVERNAME, num, 0);
			execl(DRIVER3, DRIVERNAME, num, 0);
			perror(DRIVERNAME);
E 18
D 12
			kill(pid, SIGKILL);
E 12
			exit(1);
		}
E 8
	}
E 21
D 8
    }
    signal(2, choke);
    signal(1, choke);
    Write(FILES + player, 1, 0, "begin");  /* he now exits */
    if(people)
	Write(SCENARIO, 0, 8, scene[game].people + 1);
    sync();
    printf("Your ship is the %s, a %s (%s crew).\n", scene[game].ship[player].shipname, info(player, message), quality(player));
    if ((nameptr = (char *) getenv("NAME")) && *nameptr)
	strcpy(comm,nameptr);
    else {
	fputs("Your name, Captain? ", stdout);
	gets(comm);
	if (!*comm) strcpy(comm, "no name");
    }
    comm[19] = '\0';
    for (k=0; k < 2; k++) {
	printf("\nInitial broadside %s (grape, chain, round, double): ", (k ? "right" : "left"));
	scanf("%s", file);
	switch(*file) {
	    case 'g':
		load = GRAPE;
		break;
	    case 'c':
		load = CHAIN;
		break;
	    case 'r':
		load = ROUND;
		break;
	    case 'd':
		load = DOUBLE;
		break;
	}
	if (k) {
	    scene[game].ship[player].file -> loadR = load;
	    scene[game].ship[player].file -> readyR = ready;
	} else {
	    scene[game].ship[player].file -> loadL = load;
	    scene[game].ship[player].file -> readyL = ready;
	}
    }
    Write(FILES + player, 1, 0, comm);
    if (!people && !nodriver) {
	sprintf(num, "%d", game);
	if (!fork()) {
	    execl(DRIVER, DRIVERNAME, num, 0);
	    perror(DRIVER);
	    kill(pid,9);
	    exit(1);
	}
    }
    board();
    sprintf(message, "Captain %s assuming command",comm);
    Write(FILES + player, 1, 164, message);
    windspeed = scene[game].windspeed;
    winddir = scene[game].winddir;
    turn = scene[game].turn;
    iplotships();	/* new turn */
E 8
I 8
D 18

I 13
	foreachship(sp) {
		sp->file->dir = sp->shipdir;
		sp->file->row = sp->shiprow;
		sp->file->col = sp->shipcol;
	}
	windspeed = cc->windspeed;
	winddir = cc->winddir;
E 18

E 13
D 12
	initscr();
	view = newwin(ROWSINVIEW, COLSINVIEW, 2, 1);
	slot = newwin(ROWSINVIEW, 3, 2, 1+COLSINVIEW);
	done_curses++;
	noecho();
	crmode();
E 12
I 12
	initscreen();
I 22
D 26
	blockalarm();
E 26
E 22
E 12
D 21

E 21
D 17
	board();
E 17
I 17
	draw_board();
I 22
D 26
	unblockalarm();
E 26
E 22
E 17
D 12
	sprintf(message, "Captain %s assuming command",comm);
	Write(FILES + player, 1, 164, message);
	windspeed = scene[game].windspeed;
	winddir = scene[game].winddir;
	turn = scene[game].turn;
E 12
I 12
	(void) sprintf(message, "Captain %s assuming command", captain);
	Write(W_SIGNAL, ms, 1, (int)message, 0, 0, 0);
E 12
D 21

E 21
D 12
	iplotships();	/* new turn */
E 12
I 12
	newturn();
E 12
E 8
}

E 28
I 21
/*
 * If we get here before a ship is chosen, then ms == 0 and
 * we don't want to update the score file, or do any Write's either.
 * We can assume the sync file is already created and may need
 * to be removed.
I 26
 * Of course, we don't do any more Sync()'s if we got here
 * because of a Sync() failure.
E 26
 */
E 21
D 8
/* 
E 8
I 8
D 12
/*
E 8
 * Returns the NUMBER of the closest ship
 */
D 8
closestenemy(fromship, side, anyship) 
int fromship; 
E 8
I 8
closestenemy(fromship, side, anyship)
int fromship;
E 8
char side, anyship;
E 12
I 12
leave(conditions)
int conditions;
E 12
{
D 8
    register int n, olddist = 30000, ident, captured;
    register int dist, eclosest = 30000;
E 8
I 8
D 12
	register int n, olddist = 30000, ident, captured;
	register int dist, eclosest = 30000;
E 12
I 12
D 26
	FILE *fp;
D 20
	int people;
E 20
I 20
	int persons;
E 20
	float net;
D 13
	char * capn;
E 13
D 23
	char message[60];
E 23
	register int n;
	struct logs log[10], temp;
E 12
E 8

E 26
D 8
    if ((ident = scene[game].ship[fromship].file -> captured) < 0)
	ident = fromship;
    for (n=0; n < scene[game].vessels; n++) {
	if ((captured = scene[game].ship[n].file -> captured) < 0)
	    captured = n;
	if (n != fromship && pos[n].dir && (scene[game].ship[ident].nationality != scene[game].ship[captured].nationality || anyship)) {
	    if (!side || gunsbear(fromship, n) == side) {
		dist = range(fromship, n);
		if (dist < olddist){
		    eclosest = n;
		    olddist = dist;
E 8
I 8
D 12
	if ((ident = scene[game].ship[fromship].file -> captured) < 0)
		ident = fromship;
	for (n=0; n < scene[game].vessels; n++) {
		if ((captured = scene[game].ship[n].file -> captured) < 0)
			captured = n;
		if (n != fromship && pos[n].dir && (scene[game].ship[ident].nationality != scene[game].ship[captured].nationality || anyship)) {
			if (!side || gunsbear(fromship, n) == side) {
				dist = range(fromship, n);
				if (dist < olddist) {
					eclosest = n;
					olddist = dist;
				}
			}
E 8
		}
D 8
	    }
E 8
	}
D 8
    }
    if (!side && olddist == 30000)
	leave(2);
    return(eclosest);
E 8
I 8
	if (!side && olddist == 30000)
		leave(2);
	return(eclosest);
E 8
}
E 12
I 12
	(void) signal(SIGHUP, SIG_IGN);
	(void) signal(SIGINT, SIG_IGN);
	(void) signal(SIGQUIT, SIG_IGN);
	(void) signal(SIGALRM, SIG_IGN);
	(void) signal(SIGCHLD, SIG_IGN);
E 12

D 8
finalexit()
{
    endwin();
    nocrmode();
    echo();
    exit(1);
}

E 8
D 12
main(argc, argv)
int argc;
char ** argv;
{
D 7
    register int crew, aheadfirst, ta, ma, n;
E 7
I 7
D 8
    register int crew, aheadfirst, ma, n;
    int ta;
E 7
    char message[60], ch;
    int uid;
    char nodrive = 0, randomize = 0, *badstring();
E 8
I 8
	register int crew, aheadfirst, ma, n;
	int ta;
	char message[60], ch;
	int uid;
D 9
	char nodrive = 0, randomize = 0, *badstring();
E 9
I 9
	char nodrive = 0, randomize = 0, debug = 0;
	char *badstring();
E 9
	extern char _sobuf[];
E 12
I 12
D 21
	if (conditions != -1) {
E 21
I 21
	if (done_curses) {
		Signal("It looks like you've had it!",
			(struct ship *)0);
		switch (conditions) {
		case LEAVE_QUIT:
			break;
		case LEAVE_CAPTURED:
			Signal("Your ship was captured.",
				(struct ship *)0);
			break;
		case LEAVE_HURRICAN:
			Signal("Hurricane!  All ships destroyed.",
				(struct ship *)0);
			break;
		case LEAVE_DRIVER:
D 26
			/* don't clear 'hasdriver' here */
E 26
			Signal("The driver died.", (struct ship *)0);
			break;
I 26
		case LEAVE_SYNC:
			Signal("Synchronization error.", (struct ship *)0);
			break;
E 26
		default:
			Signal("A funny thing happened (%d).",
				(struct ship *)0, conditions);
		}
	} else {
		switch (conditions) {
		case LEAVE_QUIT:
			break;
		case LEAVE_DRIVER:
			printf("The driver died.\n");
			break;
		case LEAVE_FORK:
D 26
			hasdriver = 0;
			printf("Can't fork.\n");
E 26
I 26
			perror("fork");
E 26
			break;
I 26
		case LEAVE_SYNC:
			printf("Synchronization error\n.");
			break;
E 26
		default:
			printf("A funny thing happened (%d).\n",
				conditions);
		}
	}

	if (ms != 0) {
E 21
D 13
		capn = mf->captain;
		(void) sprintf(message,"Captain %s relinquishing.",capn);
E 13
I 13
D 20
		(void) sprintf(message,"Captain %s relinquishing.",
			mf->captain);
E 13
		Write(W_SIGNAL, ms, 1, (int)message, 0, 0, 0);
I 13
		Write(W_END, ms, 0, 0, 0, 0, 0);
E 13
E 12
E 8

E 20
D 8
    signal(SIGINT, finalexit);
    signal(SIGQUIT, finalexit);
    signal(SIGHUP, finalexit);
    
    if (timetoplay() != 0 && gooduid(uid) != 0)
	{
	printf("Sorry Captain, but since you are not an Admiral and this is\n");
	printf("a weekday between %s, you are not permitted to\n",badstring());
	printf("sail.  Come back again some time when the harbor is open.\n");
	exit(1);
E 8
I 8
D 12
	setbuf(stdout, _sobuf);
	if (timetoplay() != 0 && gooduid(uid) != 0) {
		printf("Sorry Captain, but since you are not an Admiral and this is\n");
		printf("a weekday between %s, you are not permitted to\n",badstring());
		printf("sail.  Come back again some time when the harbor is open.\n");
		exit(1);
E 8
	}

D 8
    while (*++argv && **argv == '-')
	switch (*++*argv)
	    {
	    case 'd':
		nodrive = 1;
		break;
	    case 'x':
		randomize = 1;
		break;
	    default:
		printf("Unknown flag '%s'\n",*argv);
		break;
	    }
    if (*argv)
	game = atoi(*argv);
    else
	game = -1;
    initialize(nodrive, randomize);
    noecho();
    crmode();
    Signal("Aye aye, Sir", 0, 0);
    for(;;)
	{
	move(scroll++,0);
	clearline();
	addch('~');
	move(--scroll,0);
	refresh();
	ch = getch();	
	switch(ch)
	    {
	    case 'm':
		crew = specs[scene[game].ship[player].shipnum].crew3;
		/* for (n=0; n < 3; n++)
		    {
		    if (ptr -> OBP[n].turnsent && ptr -> OBP[n].mensent % 10)
		    crew = 0;
		    }
		for (n=0; n < 3; n++)
		    {
		    if (ptr -> DBP[n].turnsent && ptr -> DBP[n].mensent % 10)
		    crew = 0;
		    } */
		if (crew && !grappled(player) && !fouled(player) && windspeed)
		    {
		    ta = maxturns(player);
		    aheadfirst = ta & 0100000;
		    ma = maxmove(player, pos[player].dir, 0);
		    ta &= 077777;
		    acceptmove(ma, ta, aheadfirst);
		    }
		else
		    Signal("Unable to move", 0, 0);
		break;
	    case 's':
		acceptsignal();
		break;
	    case 'g':
		grapungrap();
		break;
	    case 'u':
		unfoulplayer();
		break;
I 5
	    case 'v':
		version();
		break;
E 5
	    case 'b':
		boarding();
		break;
/*	    case '[':
		devestate = 1;
		acceptcombat();
		break; */
	    case 'f':
		acceptcombat();
		break;
	    case 'l':
		loadplayer();
		break;
	    case 'c':
		changesail();
		break;
	    case 'r':
		repair();
		break;
	    case 'B':
		Signal("'Hands to stations!'", 0, 0);
		unboard(player, player, 1);	/* cancel DBP's */
		unboard(player, player, 0);	/* cancel offense */
		break;
	    case '\f':
		signal(SIGALRM, SIG_IGN);
		viewrow = pos[player].row - ROWSINVIEW / 2;
		viewcol = pos[player].col - COLSINVIEW / 2;
		board();
		plotships(); /* don't create new turn */
		break;
	    case 'L':
		scene[game].ship[player].file -> loadL = 0;
		scene[game].ship[player].file -> loadR = 0;
		scene[game].ship[player].file -> readyL = 0;
		scene[game].ship[player].file -> readyR = 0;
		Signal("Broadsides unloaded", 0, 0);
		break;
	    case 'q':
		Signal("Type 'Q' to quit", 0, 0);
		break;
	    case 'Q':
		leave(0);
		break;
	    case 'I':
		for (n = 0; n < scene[game].vessels; n++)
		    eyeball(player, n);
		break;
	    case 'i':
		n = closestenemy(player, 0, 1);
		eyeball(player, n);
		break;
	    }
	signalflags();
	lost();
E 8
I 8
	while (*++argv && **argv == '-')
		switch (*++*argv) {
		case 'd':
			nodrive = 1;
			break;
I 9
		case 'D':
			debug++;
			break;
E 9
		case 'x':
			randomize = 1;
			break;
		default:
			printf("Unknown flag '%s'\n",*argv);
			break;
E 12
I 12
D 26
		if (fp = fopen(LOGFILE, "r+")) {
			net = (float)mf->points / mc->pts;
D 20
			people = getw(fp);
E 20
I 20
			persons = getw(fp);
E 20
			n = fread((char *)log, sizeof(struct logs), 10, fp);
			for (; n < 10; n++)
				log[n].l_name[0]
					= log[n].l_uid
					= log[n].l_shipnum
					= log[n].l_gamenum
					= log[n].l_netpoints = 0;
			rewind(fp);
D 20
			if (people < 0)
E 20
I 20
			if (persons < 0)
E 20
				(void) putw(1, fp);
			else
D 20
				(void) putw(people + 1, fp);
E 20
I 20
				(void) putw(persons + 1, fp);
E 20
			for (n = 0; n < 10; n++)
				if (net > (float) log[n].l_netpoints / scene[log[n].l_gamenum].ship[log[n].l_shipnum].specs->pts) {
					(void) fwrite((char *)log,
						sizeof (struct logs), n, fp);
D 13
					(void) strcpy(temp.l_name, capn);
E 13
I 13
					(void) strcpy(temp.l_name, mf->captain);
E 13
					temp.l_uid = getuid();
					temp.l_shipnum = player;
					temp.l_gamenum = game;
					temp.l_netpoints = mf->points;
					(void) fwrite((char *)&temp,
						sizeof temp, 1, fp);
					(void) fwrite((char *)&log[n],
						sizeof (struct logs), 9-n, fp);
					break;
				}
			(void) fclose(fp);
E 26
I 26
		log(ms);
		if (conditions != LEAVE_SYNC) {
			makesignal(ms, "Captain %s relinquishing.",
				(struct ship *)0, mf->captain);
			Write(W_END, ms, 0, 0, 0, 0, 0);
			(void) Sync();
E 26
E 12
		}
D 12
	if (*argv)
		game = atoi(*argv);
	else
		game = -1;
D 9
	initialize(nodrive, randomize);
E 9
I 9
	initialize(nodrive, randomize, debug);
E 9
	Signal("Aye aye, Sir", 0, 0);
	for(;;) {
		move(scroll++,0);
		clearline();
		addch('~');
		move(--scroll,0);
		refresh();
		ch = getch();
		switch(ch) {
		case 'm':
			crew = specs[scene[game].ship[player].shipnum].crew3;
			if (crew && !grappled(player) && !fouled(player) && windspeed) {
				ta = maxturns(player);
				aheadfirst = ta & 0100000;
				ma = maxmove(player, pos[player].dir, 0);
				ta &= 077777;
				acceptmove(ma, ta, aheadfirst);
			} else
				Signal("Unable to move", 0, 0);
			break;
		case 's':
			acceptsignal();
			break;
		case 'g':
			grapungrap();
			break;
		case 'u':
			unfoulplayer();
			break;
		case 'v':
			version();
			break;
		case 'b':
			boarding();
			break;
		case 'f':
			acceptcombat();
			break;
		case 'l':
			loadplayer();
			break;
		case 'c':
			changesail();
			break;
		case 'r':
			repair();
			break;
		case 'B':
			Signal("'Hands to stations!'", 0, 0);
			unboard(player, player, 1);	/* cancel DBP's */
			unboard(player, player, 0);	/* cancel offense */
			break;
		case '\f':
			signal(SIGALRM, SIG_IGN);
			viewrow = pos[player].row - ROWSINVIEW / 2;
			viewcol = pos[player].col - COLSINVIEW / 2;
			board();
			plotships(); /* don't create new turn */
			break;
		case 'L':
			scene[game].ship[player].file -> loadL = 0;
			scene[game].ship[player].file -> loadR = 0;
			scene[game].ship[player].file -> readyL = 0;
			scene[game].ship[player].file -> readyR = 0;
			Signal("Broadsides unloaded", 0, 0);
			break;
		case 'q':
			Signal("Type 'Q' to quit", 0, 0);
			break;
		case 'Q':
			leave(0);
			break;
		case 'I':
			for (n = 0; n < scene[game].vessels; n++)
				eyeball(player, n);
			break;
		case 'i':
			n = closestenemy(player, 0, 1);
			eyeball(player, n);
			break;
E 12
I 12
D 13
		Write(W_CAPTAIN, ms, 1, (int)" ", 0, 0, 0);
		Write(W_PEOPLE, SHIP(0), 0, cc->people - 1, 0, 0, 0);
E 13
D 21
		if (done_curses) {
D 17
			screen();
E 17
			Signal("It looks like you've had it!",
				(struct ship *)0);
			switch (conditions) {
			case LEAVE_QUIT:
				break;
			case LEAVE_CAPTURED:
				Signal("Your ship was captured.",
					(struct ship *)0);
				break;
			case LEAVE_HURRICAN:
				Signal("Hurricane!  All ships destroyed.",
					(struct ship *)0);
				break;
			case LEAVE_DRIVER:
				Signal("The driver died.", (struct ship *)0);
				break;
			default:
				Signal("A funny thing happened (%d).",
					(struct ship *)0, conditions);
			}
		} else {
D 17
			if (conditions == LEAVE_DRIVER)
E 17
I 17
			switch (conditions) {
			case LEAVE_QUIT:
				break;
			case LEAVE_DRIVER:
E 17
				printf("The driver died.\n");
D 17
			else
				printf("leave: unknown code %d\n", conditions);
E 17
I 17
				break;
			default:
				printf("A funny thing happened (%d).\n",
					conditions);
			}
E 17
E 12
		}
I 20
		(void) sprintf(message,"Captain %s relinquishing.",
E 21
I 21
D 26
		makesignal(ms, "Captain %s relinquishing.", (struct ship *)0,
E 21
			mf->captain);
D 21
		Write(W_SIGNAL, ms, 1, (int)message, 0, 0, 0);
E 21
		Write(W_END, ms, 0, 0, 0, 0, 0);
E 20
D 12
		signalflags();
		lost();
E 12
I 12
D 13
		(void) fclose(syncfile);
E 13
I 13
		Sync();
E 26
I 20
D 21
		sync_close(people == 0);
E 21
E 20
E 13
E 12
E 8
	}
I 21
	sync_close(!hasdriver);
E 21
I 12
D 17
	if (done_curses) {
		lastline();
		nocrmode();
		echo();
		endwin();
	}
E 17
I 17
	cleanupscreen();
E 17
	exit(0);
E 12
D 8
    }
E 8
I 8
}
E 8

D 12
char *saywhat(n)
int n;
E 12
I 12
choke()
E 12
{
D 12
	if(scene[game].ship[n].file -> captain[0])
		return(scene[game].ship[n].file -> captain);
	else if (scene[game].ship[n].file -> struck)
		return("(struck)");
	else if(scene[game].ship[n].file -> captured > -1)
		return("(captured)");
	else
		return("(computer)");
E 12
I 12
	leave(LEAVE_QUIT);
E 12
}

D 12
eyeball(player, n)
int player, n;
E 12
I 12
child()
E 12
{
D 8
    char message[80];
    register i;
E 8
I 8
D 12
	char message[80];
	register i;
E 12
I 12
	union wait status;
	int pid;
E 12
E 8

D 8
    if (scene[game].ship[n].shipdir){
	sprintf(message, "%d, %s", range(player, n), saywhat(n));
	Signal("Sail ho! (range %s)", -1, message);
	switch(scene[game].ship[n].nationality)
	    {
	    case 0:
		strcpy(message, "American ");
		break;
	    case 1:
		strcpy(message, "British ");
		break;
	    case 2:
		strcpy(message, "Spanish ");
		break;
	    case 3:
		strcpy(message, "French ");
		break;
	    default:
		strcpy(message, "Gremlin ");
		break;
	    }
	switch(specs[scene[game].ship[n].shipnum].class)
	    {
	    case 1:
	    case 2:
		strcat(message, "Ship of the Line ");
		break;
	    case 3:
	    case 4:
		strcat(message, "Frigate ");
		break;
	    case 5:
	    case 6:
		strcat(message, "Sloop ");
		break;
	    }
	switch(portside(player, n, 1) - pos[player].dir)
	    {
	    case -7:
	    case 1:
		strcat(message, "off the starboard bow.");
		break;
	    case -6:
	    case 2:
		strcat(message, "off the starboard beam.");
		break;
	    case -5:
	    case 3:
		strcat(message, "off the starboard quarter.");
		break;
	    case -4:
	    case 4:
		strcat(message, "dead astern.");
		break;
	    case -3:
	    case 5:
		strcat(message, "off the port quarter.");
		break;
	    case -2:
	    case 6:
		strcat(message, "off the port beam.");
		break;
	    case -1:
	    case 7:
		strcat(message, "off the port bow.");
		break;
	    case 0:
		strcat(message, "dead ahead.");
		break;
	    }
	Signal(message, 0, 0);
    }
E 8
I 8
D 12
	if (scene[game].ship[n].shipdir) {
		sprintf(message, "%d, %s", range(player, n), saywhat(n));
		Signal("Sail ho! (range %s)", -1, message);
		switch(scene[game].ship[n].nationality) {
		case 0:
			strcpy(message, "American ");
			break;
		case 1:
			strcpy(message, "British ");
			break;
		case 2:
			strcpy(message, "Spanish ");
			break;
		case 3:
			strcpy(message, "French ");
			break;
		default:
			strcpy(message, "Gremlin ");
			break;
		}
		switch(specs[scene[game].ship[n].shipnum].class) {
		case 1:
		case 2:
			strcat(message, "Ship of the Line ");
			break;
		case 3:
		case 4:
			strcat(message, "Frigate ");
			break;
		case 5:
		case 6:
			strcat(message, "Sloop ");
			break;
		}
		switch(portside(player, n, 1) - pos[player].dir) {
		case -7:
		case 1:
			strcat(message, "off the starboard bow.");
			break;
		case -6:
		case 2:
			strcat(message, "off the starboard beam.");
			break;
		case -5:
		case 3:
			strcat(message, "off the starboard quarter.");
			break;
		case -4:
		case 4:
			strcat(message, "dead astern.");
			break;
		case -3:
		case 5:
			strcat(message, "off the port quarter.");
			break;
		case -2:
		case 6:
			strcat(message, "off the port beam.");
			break;
		case -1:
		case 7:
			strcat(message, "off the port bow.");
			break;
		case 0:
			strcat(message, "dead ahead.");
			break;
		}
		Signal(message, 0, 0);
	}
E 12
I 12
	(void) signal(SIGCHLD, SIG_IGN);
	do {
D 27
		pid = wait3(&status, WNOHANG|WUNTRACED, (struct rusage *)0);
E 27
I 27
		pid = wait3(&status, WNOHANG, (struct rusage *)0);
E 27
		if (pid < 0 || pid > 0 && !WIFSTOPPED(status))
D 26
			leave(LEAVE_DRIVER);
E 26
I 26
			hasdriver = 0;
E 26
D 27
	} while (pid != 0);
E 27
I 27
	} while (pid > 0);
E 27
	(void) signal(SIGCHLD, child);
E 12
E 8
}
E 1
