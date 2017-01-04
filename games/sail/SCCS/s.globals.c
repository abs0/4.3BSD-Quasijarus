h19876
s 00010/00005/00481
d D 5.3 88/06/18 19:55:30 bostic 13 12
c install approved copyright notice
e
s 00009/00003/00477
d D 5.2 88/03/09 12:30:19 bostic 12 11
c written by David Riggle and Edward Wang; add Berkeley specific copyright
e
s 00005/00006/00475
d D 5.1 85/05/29 16:02:54 dist 11 10
c Add copyright
e
s 00006/00000/00475
d D 2.2 85/04/23 21:48:40 edward 10 9
c copyright message
e
s 00000/00000/00475
d D 2.1 83/10/31 13:44:09 edward 9 8
c new version
e
s 00008/00008/00467
d D 1.8 83/10/31 11:52:14 edward 8 7
c Twiddled guns and rigging on Star Trek scenario
e
s 00026/00016/00449
d D 1.7 83/10/28 22:49:34 edward 7 6
c star trek
e
s 00032/00036/00433
d D 1.6 83/10/10 20:10:24 edward 6 5
c got rid of unnecessary variables
e
s 00289/00303/00180
d D 1.5 83/10/05 11:44:11 edward 5 4
c changed sizes of things and reformated globals.c
e
s 00203/00141/00280
d D 1.4 83/07/20 17:22:19 edward 4 3
c 
e
s 00004/00054/00417
d D 1.3 83/05/20 19:09:15 edward 3 2
c moved driver to /usr/games/lib and merged externs.h and globals.c
e
s 00007/00007/00464
d D 1.2 83/05/20 17:42:45 root 2 1
c merge
e
s 00471/00000/00000
d D 1.1 83/03/17 21:09:22 leres 1 0
c date and time created 83/03/17 21:09:22 by leres
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
I 5
D 11
/*LINTLIBRARY*/
E 11
E 5
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
I 5

E 5
D 4
#include <stdio.h>
E 4
I 3
#include "externs.h"
E 3

D 3
#define NUMOFSCENES 32

#define BUFSIZE 2024

struct snag {
	int turnfoul, toship;
};

struct BP {
	int turnsent, toship, mensent;
};

typedef struct {
	int row, col, dir;
} postype;
postype pos[20];

struct File {
	char captain[20];
	int points;
	int loadL, loadR, readyL, readyR;
	struct BP OBP[3], DBP[3];
	int struck, captured, pcrew;
	char last[10];
	int drift;
	struct snag fouls[10], grapples[10];
	char signal[60];
	int RH, RG, RR, FS, explode, sink;
};

typedef struct {
	char *shipname;
	int shipnum, nationality;
	int shiprow, shipcol, shipdir;
	struct File *file;
} ships;

struct scenario {
	int winddir, windspeed, windchange;
	int turn, people, time, vessels;
	char *name;
	ships ship[10];
};

E 3
D 4
struct scenario scene[NUMOFSCENES] = {
E 4
I 4
struct scenario scene[] = {
	/*
	 * int winddir;
	 * int windspeed;
	 * int windchange;
D 6
	 * int turn;
	 * int people;
	 * int time;
E 6
	 * int vessels;
	 * char *name;
	 * struct ship ship[NSHIP];
	 */
E 4
D 6
	5, 3, 5, 0, 1, 0, 2, "Ranger vs. Drake",
E 6
I 6
	5, 3, 5, 2, "Ranger vs. Drake",
E 6
	{
D 4
		{ "Ranger",          0,  0, 7,  20, 4, 0 },
		{ "Drake",           1,  1, 7,  31, 5, 0 }
E 4
I 4
D 5
		{ "Ranger",		specs+0,  0, 7,  20, 4, 0 },
		{ "Drake",		specs+1,  1, 7,  31, 5, 0 }
E 5
I 5
		{ "Ranger",		specs+0,  N_A,  7, 20, 4, 0 },
		{ "Drake",		specs+1,  N_B,  7, 31, 5, 0 }
E 5
E 4
	},
D 4
	1, 3, 6, 0, 1,0, 2, "The Battle of Flamborough Head",
E 4
I 4
D 6
	1, 3, 6, 0, 1, 0, 2, "The Battle of Flamborough Head",
E 6
I 6
	1, 3, 6, 2, "The Battle of Flamborough Head",
E 6
E 4
	{
D 4
		{ "Bonhomme Rich",   2,  0, 13, 40, 2, 0 },
		{ "Serapis",         3,  1,  2, 42, 2, 0 }
E 4
I 4
D 5
		{ "Bonhomme Rich",	specs+2,  0, 13, 40, 2, 0 },
		{ "Serapis",		specs+3,  1,  2, 42, 2, 0 }
E 5
I 5
		{ "Bonhomme Rich",	specs+2,  N_A, 13, 40, 2, 0 },
		{ "Serapis",		specs+3,  N_B,  2, 42, 2, 0 }
E 5
E 4
	},
D 6
	5, 5, 5, 0, 1, 0, 10, "Arbuthnot and Des Touches",
E 6
I 6
	5, 5, 5, 10, "Arbuthnot and Des Touches",
E 6
	{
D 4
		{ "America",         4,  1,  7, 37, 4, 0 },
		{ "Befford",         5,  1,  5, 35, 4, 0 },
		{ "Adamant",         6,  1,  3, 33, 4, 0 },
		{ "London",          7,  1,  1, 31, 4, 0 },
		{ "Royal Oak",       8,  1, -1, 29, 4, 0 },
		{ "Neptune",         9,  3,  6, 44, 4, 0 },
		{ "Duc Bougogne",    10, 3,  8, 46, 4, 0 },
		{ "Conquerant",      48, 3, 10, 48, 4, 0 },
		{ "Provence",        11, 3, 12, 50, 4, 0 },
		{ "Romulus",         12, 3, 20, 58, 4, 0 }
E 4
I 4
D 5
		{ "America",		specs+4,  1,  7, 37, 4, 0 },
		{ "Befford",		specs+5,  1,  5, 35, 4, 0 },
		{ "Adamant",		specs+6,  1,  3, 33, 4, 0 },
		{ "London",		specs+7,  1,  1, 31, 4, 0 },
		{ "Royal Oak",		specs+8,  1, -1, 29, 4, 0 },
		{ "Neptune",		specs+9,  3,  6, 44, 4, 0 },
		{ "Duc Bougogne",	specs+10, 3,  8, 46, 4, 0 },
		{ "Conquerant",		specs+48, 3, 10, 48, 4, 0 },
		{ "Provence",		specs+11, 3, 12, 50, 4, 0 },
		{ "Romulus",		specs+12, 3, 20, 58, 4, 0 }
E 5
I 5
		{ "America",		specs+4,  N_B,  7, 37, 4, 0 },
		{ "Befford",		specs+5,  N_B,  5, 35, 4, 0 },
		{ "Adamant",		specs+6,  N_B,  3, 33, 4, 0 },
		{ "London",		specs+7,  N_B,  1, 31, 4, 0 },
		{ "Royal Oak",		specs+8,  N_B, -1, 29, 4, 0 },
		{ "Neptune",		specs+9,  N_F,  6, 44, 4, 0 },
		{ "Duc Bougogne",	specs+10, N_F,  8, 46, 4, 0 },
		{ "Conquerant",		specs+48, N_F, 10, 48, 4, 0 },
		{ "Provence",		specs+11, N_F, 12, 50, 4, 0 },
		{ "Romulus",		specs+12, N_F, 20, 58, 4, 0 }
E 5
E 4
	},
D 6
	1, 3, 5, 0, 1, 0, 10, "Suffren and Hughes",
E 6
I 6
	1, 3, 5, 10, "Suffren and Hughes",
E 6
	{
D 4
		{ "Monmouth",        52, 1, 9,  45, 2, 0 },
		{ "Hero",            5,  1, 13, 49, 2, 0 },
		{ "Isis",            6,  1, 12, 48, 2, 0 },
		{ "Superb",          50, 1, 10, 46, 2, 0 },
		{ "Burford",	   48, 1, 11, 47, 2, 0 },
		{ "Flamband",        13, 3, 7,  59, 4, 0 },
		{ "Annibal",	    9, 3, 4,  56, 4, 0 },
		{ "Severe",          11, 3, 2,  54, 4, 0 },
		{ "Brilliant",       49, 3, -1, 51, 4, 0 },
		{ "Sphinx",          51, 3, -5, 47, 4, 0 }
E 4
I 4
D 5
		{ "Monmouth",		specs+52, 1, 9,  45, 2, 0 },
		{ "Hero",		specs+5,  1, 13, 49, 2, 0 },
		{ "Isis",		specs+6,  1, 12, 48, 2, 0 },
		{ "Superb",		specs+50, 1, 10, 46, 2, 0 },
		{ "Burford",		specs+48, 1, 11, 47, 2, 0 },
		{ "Flamband",		specs+13, 3, 7,  59, 4, 0 },
		{ "Annibal",		specs+9, 3, 4,  56, 4, 0 },
		{ "Severe",		specs+11, 3, 2,  54, 4, 0 },
		{ "Brilliant",		specs+49, 3, -1, 51, 4, 0 },
		{ "Sphinx",		specs+51, 3, -5, 47, 4, 0 }
E 5
I 5
		{ "Monmouth",		specs+52, N_B,  9, 45, 2, 0 },
		{ "Hero",		specs+5,  N_B, 13, 49, 2, 0 },
		{ "Isis",		specs+6,  N_B, 12, 48, 2, 0 },
		{ "Superb",		specs+50, N_B, 10, 46, 2, 0 },
		{ "Burford",		specs+48, N_B, 11, 47, 2, 0 },
		{ "Flamband",		specs+13, N_F,  7, 59, 4, 0 },
		{ "Annibal",		specs+9,  N_F,  4, 56, 4, 0 },
		{ "Severe",		specs+11, N_F,  2, 54, 4, 0 },
		{ "Brilliant",		specs+49, N_F, -1, 51, 4, 0 },
		{ "Sphinx",		specs+51, N_F, -5, 47, 4, 0 }
E 5
E 4
	},
D 6
	1, 3, 4, 0, 1, 0, 2, "Nymphe vs. Cleopatre",
E 6
I 6
	1, 3, 4, 2, "Nymphe vs. Cleopatre",
E 6
	{
D 4
		{ "Nymphe",          14, 1, 13, 30, 2, 0 },
		{ "Cleopatre",       15, 3, 3,  41, 2, 0 }
E 4
I 4
D 5
		{ "Nymphe",		specs+14, 1, 13, 30, 2, 0 },
		{ "Cleopatre",		specs+15, 3, 3,  41, 2, 0 }
E 5
I 5
		{ "Nymphe",		specs+14, N_B, 13, 30, 2, 0 },
		{ "Cleopatre",		specs+15, N_F,  3, 41, 2, 0 }
E 5
E 4
	},
D 6
	1, 3, 5, 0, 1, 0, 2, "Mars vs. Hercule",
E 6
I 6
	1, 3, 5, 2, "Mars vs. Hercule",
E 6
	{
D 4
		{ "Mars",            16, 1, 13, 30, 2, 0 },
		{ "Hercule",         17, 3, 3,  41, 2, 0 }
E 4
I 4
D 5
		{ "Mars",		specs+16, 1, 13, 30, 2, 0 },
		{ "Hercule",		specs+17, 3, 3,  41, 2, 0 }
E 5
I 5
		{ "Mars",		specs+16, N_B, 13, 30, 2, 0 },
		{ "Hercule",		specs+17, N_F,  3, 41, 2, 0 }
E 5
E 4
	},
D 6
	5, 3, 5, 0, 1, 0, 2, "Ambuscade vs. Baionnaise",
E 6
I 6
	5, 3, 5, 2, "Ambuscade vs. Baionnaise",
E 6
	{
D 4
		{ "Ambuscade",       18, 1, 13, 30, 2, 0 },
		{ "Baionnaise",      19, 3, 3,  41, 2, 0 }
E 4
I 4
D 5
		{ "Ambuscade",		specs+18, 1, 13, 30, 2, 0 },
		{ "Baionnaise",		specs+19, 3, 3,  41, 2, 0 }
E 5
I 5
		{ "Ambuscade",		specs+18, N_B, 13, 30, 2, 0 },
		{ "Baionnaise",		specs+19, N_F,  3, 41, 2, 0 }
E 5
E 4
	},
D 6
	1, 5, 6, 0, 1, 0, 2, "Constellation vs. Insurgent",
E 6
I 6
	1, 5, 6, 2, "Constellation vs. Insurgent",
E 6
	{
D 4
		{ "Constellation",   20, 0, 9,  50, 8, 0 },
		{ "Insurgent",       22, 3, 4,  24, 2, 0 }
E 4
I 4
D 5
		{ "Constellation",	specs+20, 0, 9,  50, 8, 0 },
		{ "Insurgent",		specs+22, 3, 4,  24, 2, 0 }
E 5
I 5
		{ "Constellation",	specs+20, N_A,  9, 50, 8, 0 },
		{ "Insurgent",		specs+22, N_F,  4, 24, 2, 0 }
E 5
E 4
	},
D 6
	1, 3, 5, 0, 1, 0, 2, "Constellation vs. Vengeance",
E 6
I 6
	1, 3, 5, 2, "Constellation vs. Vengeance",
E 6
	{
D 4
		{ "Constellation",   20, 0, 12, 40, 2, 0 },
		{ "Vengeance",       21, 3, 1,  43, 2, 0 }
E 4
I 4
D 5
		{ "Constellation",	specs+20, 0, 12, 40, 2, 0 },
		{ "Vengeance",		specs+21, 3, 1,  43, 2, 0 }
E 5
I 5
		{ "Constellation",	specs+20, N_A, 12, 40, 2, 0 },
		{ "Vengeance",		specs+21, N_F,  1, 43, 2, 0 }
E 5
E 4
	},
D 6
	1, 3, 6, 0, 1, 0, 10, "The Battle of Lissa",
E 6
I 6
	1, 3, 6, 10, "The Battle of Lissa",
E 6
	{
D 4
		{ "Amphion",         23, 1, 8,  50, 4, 0 },
		{ "Active",          24, 1, 6,  48, 4, 0 },
		{ "Volage",          25, 1, 4,  46, 4, 0 },
		{ "Cerberus",        26, 1, 2,  44, 4, 0 },
		{ "Favorite",        27, 3, 9,  34, 2, 0 },
		{ "Flore",           21, 3, 13, 39, 2, 0 },
		{ "Danae",           64, 3, 15, 37, 2, 0 },
		{ "Bellona",         28, 3, 17, 35, 2, 0 },
		{ "Corona",          29, 3, 12, 31, 2, 0 },
		{ "Carolina",        30, 3, 15, 28, 2, 0 }
E 4
I 4
D 5
		{ "Amphion",		specs+23, 1, 8,  50, 4, 0 },
		{ "Active",		specs+24, 1, 6,  48, 4, 0 },
		{ "Volage",		specs+25, 1, 4,  46, 4, 0 },
		{ "Cerberus",		specs+26, 1, 2,  44, 4, 0 },
		{ "Favorite",		specs+27, 3, 9,  34, 2, 0 },
		{ "Flore",		specs+21, 3, 13, 39, 2, 0 },
		{ "Danae",		specs+64, 3, 15, 37, 2, 0 },
		{ "Bellona",		specs+28, 3, 17, 35, 2, 0 },
		{ "Corona",		specs+29, 3, 12, 31, 2, 0 },
		{ "Carolina",		specs+30, 3, 15, 28, 2, 0 }
E 5
I 5
		{ "Amphion",		specs+23, N_B,  8, 50, 4, 0 },
		{ "Active",		specs+24, N_B,  6, 48, 4, 0 },
		{ "Volage",		specs+25, N_B,  4, 46, 4, 0 },
		{ "Cerberus",		specs+26, N_B,  2, 44, 4, 0 },
		{ "Favorite",		specs+27, N_F,  9, 34, 2, 0 },
		{ "Flore",		specs+21, N_F, 13, 39, 2, 0 },
		{ "Danae",		specs+64, N_F, 15, 37, 2, 0 },
		{ "Bellona",		specs+28, N_F, 17, 35, 2, 0 },
		{ "Corona",		specs+29, N_F, 12, 31, 2, 0 },
		{ "Carolina",		specs+30, N_F, 15, 28, 2, 0 }
E 5
E 4
	},
D 6
	2, 5, 6, 0, 1, 0, 2, "Constitution vs. Guerriere",
E 6
I 6
	2, 5, 6, 2, "Constitution vs. Guerriere",
E 6
	{
D 4
		{ "Constitution",    31, 0, 7,  35, 1, 0 },
		{ "Guerriere",       32, 1, 7,  47, 4, 0 }
E 4
I 4
D 5
		{ "Constitution",	specs+31, 0, 7,  35, 1, 0 },
		{ "Guerriere",		specs+32, 1, 7,  47, 4, 0 }
E 5
I 5
		{ "Constitution",	specs+31, N_A,  7, 35, 1, 0 },
		{ "Guerriere",		specs+32, N_B,  7, 47, 4, 0 }
E 5
E 4
	},
D 6
	1, 3, 5, 0, 1, 0, 2, "United States vs. Macedonian",
E 6
I 6
	1, 3, 5, 2, "United States vs. Macedonian",
E 6
	{
D 4
		{ "United States",   33, 0, 1,  52, 6, 0 },
		{ "Macedonian",      34, 1, 14, 40, 1, 0 }
E 4
I 4
D 5
		{ "United States",	specs+33, 0, 1,  52, 6, 0 },
		{ "Macedonian",		specs+34, 1, 14, 40, 1, 0 }
E 5
I 5
		{ "United States",	specs+33, N_A,  1, 52, 6, 0 },
		{ "Macedonian",		specs+34, N_B, 14, 40, 1, 0 }
E 5
E 4
	},
D 6
	1, 3, 6, 0, 1, 0, 2, "Constitution vs. Java",
E 6
I 6
	1, 3, 6, 2, "Constitution vs. Java",
E 6
	{
D 4
		{ "Constitution",    31, 0, 1,  40, 2, 0 },
		{ "Java",            35, 1, 11, 40, 2, 0 }
E 4
I 4
D 5
		{ "Constitution",	specs+31, 0, 1,  40, 2, 0 },
		{ "Java",		specs+35, 1, 11, 40, 2, 0 }
E 5
I 5
		{ "Constitution",	specs+31, N_A,  1, 40, 2, 0 },
		{ "Java",		specs+35, N_B, 11, 40, 2, 0 }
E 5
E 4
	},
D 6
	1, 3, 5, 0, 1, 0, 2, "Chesapeake vs. Shannon",
E 6
I 6
	1, 3, 5, 2, "Chesapeake vs. Shannon",
E 6
	{
D 4
		{ "Chesapeake",      36, 0, 13, 40, 2, 0 },
		{ "Shannon",         37, 1, 1,  42, 2, 0 }
E 4
I 4
D 5
		{ "Chesapeake",		specs+36, 0, 13, 40, 2, 0 },
		{ "Shannon",		specs+37, 1, 1,  42, 2, 0 }
E 5
I 5
		{ "Chesapeake",		specs+36, N_A, 13, 40, 2, 0 },
		{ "Shannon",		specs+37, N_B,  1, 42, 2, 0 }
E 5
E 4
	},
D 6
	1, 1, 6, 0, 1, 0, 5, "The Battle of Lake Erie",
E 6
I 6
	1, 1, 6, 5, "The Battle of Lake Erie",
E 6
	{
D 4
		{ "Lawrence",        38, 0, 4,  55, 8, 0 },
		{ "Niagara",         42, 0, 7,  61, 8, 0 },
		{ "Lady Prevost",    39, 1, 4,  25, 2, 0,  },
		{ "Detroit",         40, 1, 7,  22, 2, 0 },
		{ "Q. Charlotte",    41, 1, 10, 19, 2, 0  }
E 4
I 4
D 5
		{ "Lawrence",		specs+38, 0, 4,  55, 8, 0 },
		{ "Niagara",		specs+42, 0, 7,  61, 8, 0 },
		{ "Lady Prevost",	specs+39, 1, 4,  25, 2, 0 },
		{ "Detroit",		specs+40, 1, 7,  22, 2, 0 },
		{ "Q. Charlotte",	specs+41, 1, 10, 19, 2, 0 }
E 5
I 5
		{ "Lawrence",		specs+38, N_A,  4, 55, 8, 0 },
		{ "Niagara",		specs+42, N_A,  7, 61, 8, 0 },
		{ "Lady Prevost",	specs+39, N_B,  4, 25, 2, 0 },
		{ "Detroit",		specs+40, N_B,  7, 22, 2, 0 },
		{ "Q. Charlotte",	specs+41, N_B, 10, 19, 2, 0 }
E 5
E 4
	},
D 6
	1, 1, 5, 0, 1, 0, 2, "Wasp vs. Reindeer",
E 6
I 6
	1, 1, 5, 2, "Wasp vs. Reindeer",
E 6
	{
D 4
		{ "Wasp",            42, 0, 3,  41, 2, 0 },
		{ "Reindeer",        43, 1, 10, 48, 2, 0 }
E 4
I 4
D 5
		{ "Wasp",		specs+42, 0, 3,  41, 2, 0 },
		{ "Reindeer",		specs+43, 1, 10, 48, 2, 0 }
E 5
I 5
		{ "Wasp",		specs+42, N_A,  3, 41, 2, 0 },
		{ "Reindeer",		specs+43, N_B, 10, 48, 2, 0 }
E 5
E 4
	},
D 6
	1, 2, 5, 0, 1, 0, 3, "Constitution vs. Cyane and Levant",
E 6
I 6
	1, 2, 5, 3, "Constitution vs. Cyane and Levant",
E 6
	{
D 4
		{ "Constitution",    31, 0, 10, 45, 2, 0 },
		{ "Cyane",           44, 1, 3,  37, 2, 0 },
		{ "Levant",          45, 1, 5,  35, 2, 0 }
E 4
I 4
D 5
		{ "Constitution",	specs+31, 0, 10, 45, 2, 0 },
		{ "Cyane",		specs+44, 1, 3,  37, 2, 0 },
		{ "Levant",		specs+45, 1, 5,  35, 2, 0 }
E 5
I 5
		{ "Constitution",	specs+31, N_A, 10, 45, 2, 0 },
		{ "Cyane",		specs+44, N_B,  3, 37, 2, 0 },
		{ "Levant",		specs+45, N_B,  5, 35, 2, 0 }
E 5
E 4
	},
D 6
	5, 5, 5, 0, 1, 0, 3, "Pellew vs. Droits de L'Homme",
E 6
I 6
	5, 5, 5, 3, "Pellew vs. Droits de L'Homme",
E 6
	{
D 4
		{ "Indefatigable",   46, 1, 12, 45, 6, 0 },
		{ "Amazon",          47, 1, 9,  48, 6, 0 },
		{ "Droits L'Hom",    48, 3, 3,  28, 5, 0 }
E 4
I 4
D 5
		{ "Indefatigable",	specs+46, 1, 12, 45, 6, 0 },
		{ "Amazon",		specs+47, 1, 9,  48, 6, 0 },
		{ "Droits L'Hom",	specs+48, 3, 3,  28, 5, 0 }
E 5
I 5
		{ "Indefatigable",	specs+46, N_B, 12, 45, 6, 0 },
		{ "Amazon",		specs+47, N_B,  9, 48, 6, 0 },
		{ "Droits L'Hom",	specs+48, N_F,  3, 28, 5, 0 }
E 5
E 4
	},
D 6
	2, 2, 3, 0, 1, 0, 10, "Algeciras",
E 6
I 6
	2, 2, 3, 10, "Algeciras",
E 6
	{
D 4
		{ "Caesar",          49, 1, 7,  70, 6, 0 },
		{ "Pompee",          50, 1, 5,  72, 6, 0 },
		{ "Spencer",         5,  1, 3,  74, 6, 0 },
		{ "Hannibal",        7,  1, 1,  76, 6, 0 },
		{ "Real-Carlos",     53, 2, 9,  20, 3, 0 },
		{ "San Fernando",    54, 2, 11, 16, 3, 0 },
		{ "Argonauta",       55, 2, 10, 14, 4, 0 },
		{ "San Augustine",   56, 2, 6,  22, 4, 0 },
		{ "Indomptable",     51, 3, 7,  23, 5, 0 },
		{ "Desaix",          52, 3, 7,  27, 7, 0 }
E 4
I 4
D 5
		{ "Caesar",		specs+49, 1, 7,  70, 6, 0 },
		{ "Pompee",		specs+50, 1, 5,  72, 6, 0 },
		{ "Spencer",		specs+5,  1, 3,  74, 6, 0 },
		{ "Hannibal",		specs+7,  1, 1,  76, 6, 0 },
		{ "Real-Carlos",	specs+53, 2, 9,  20, 3, 0 },
		{ "San Fernando",	specs+54, 2, 11, 16, 3, 0 },
		{ "Argonauta",		specs+55, 2, 10, 14, 4, 0 },
		{ "San Augustine",	specs+56, 2, 6,  22, 4, 0 },
		{ "Indomptable",	specs+51, 3, 7,  23, 5, 0 },
		{ "Desaix",		specs+52, 3, 7,  27, 7, 0 }
E 5
I 5
		{ "Caesar",		specs+49, N_B,  7, 70, 6, 0 },
		{ "Pompee",		specs+50, N_B,  5, 72, 6, 0 },
		{ "Spencer",		specs+5,  N_B,  3, 74, 6, 0 },
		{ "Hannibal",		specs+7,  N_B,  1, 76, 6, 0 },
		{ "Real-Carlos",	specs+53, N_S,  9, 20, 3, 0 },
		{ "San Fernando",	specs+54, N_S, 11, 16, 3, 0 },
		{ "Argonauta",		specs+55, N_S, 10, 14, 4, 0 },
		{ "San Augustine",	specs+56, N_S,  6, 22, 4, 0 },
		{ "Indomptable",	specs+51, N_F,  7, 23, 5, 0 },
		{ "Desaix",		specs+52, N_F,  7, 27, 7, 0 }
E 5
E 4
	},
D 6
	5, 3, 6, 0, 1, 0, 7, "Lake Champlain",
E 6
I 6
	5, 3, 6, 7, "Lake Champlain",
E 6
	{
D 4
		{ "Saratoga",        60, 0, 8,  10, 1, 0 },
		{ "Eagle",           61, 0, 9,  13, 2, 0 },
		{ "Ticonderoga",     62, 0, 12, 17, 3, 0 },
		{ "Preble",          63, 0, 14, 20, 2, 0 },
		{ "Confiance",       57, 1, 4,  70, 6, 0 },
		{ "Linnet",          58, 1, 7,  68, 6, 0 },
		{ "Chubb",           59, 1, 10, 65, 6, 0 }
E 4
I 4
D 5
		{ "Saratoga",		specs+60, 0, 8,  10, 1, 0 },
		{ "Eagle",		specs+61, 0, 9,  13, 2, 0 },
		{ "Ticonderoga",	specs+62, 0, 12, 17, 3, 0 },
		{ "Preble",		specs+63, 0, 14, 20, 2, 0 },
		{ "Confiance",		specs+57, 1, 4,  70, 6, 0 },
		{ "Linnet",		specs+58, 1, 7,  68, 6, 0 },
		{ "Chubb",		specs+59, 1, 10, 65, 6, 0 }
E 5
I 5
		{ "Saratoga",		specs+60, N_A,  8, 10, 1, 0 },
		{ "Eagle",		specs+61, N_A,  9, 13, 2, 0 },
		{ "Ticonderoga",	specs+62, N_A, 12, 17, 3, 0 },
		{ "Preble",		specs+63, N_A, 14, 20, 2, 0 },
		{ "Confiance",		specs+57, N_B,  4, 70, 6, 0 },
		{ "Linnet",		specs+58, N_B,  7, 68, 6, 0 },
		{ "Chubb",		specs+59, N_B, 10, 65, 6, 0 }
E 5
E 4
	},
D 6
	5, 3, 6, 0, 1, 0, 4, "Last Voyage of the USS President",
E 6
I 6
	5, 3, 6, 4, "Last Voyage of the USS President",
E 6
	{
D 4
		{ "President",       67, 0, 12, 42, 5, 0 },
		{ "Endymion",        64, 1, 5,  42, 5, 0 },
		{ "Pomone",          65, 1, 7,  82, 6, 0 },
		{ "Tenedos",         66, 1, 7,  -1, 4, 0 }
E 4
I 4
D 5
		{ "President",		specs+67, 0, 12, 42, 5, 0 },
		{ "Endymion",		specs+64, 1, 5,  42, 5, 0 },
		{ "Pomone",		specs+65, 1, 7,  82, 6, 0 },
		{ "Tenedos",		specs+66, 1, 7,  -1, 4, 0 }
E 5
I 5
		{ "President",		specs+67, N_A, 12, 42, 5, 0 },
		{ "Endymion",		specs+64, N_B,  5, 42, 5, 0 },
		{ "Pomone",		specs+65, N_B,  7, 82, 6, 0 },
		{ "Tenedos",		specs+66, N_B,  7, -1, 4, 0 }
E 5
E 4
	},
D 6
	7, 5, 5, 0, 1, 0, 2, "Hornblower and the Natividad",
E 6
I 6
	7, 5, 5, 2, "Hornblower and the Natividad",
E 6
	{
D 4
		{ "Lydia",           68, 1, 12, 40, 2, 0 },
		{ "Natividad",       69, 2, 2,  40, 4, 0 }
E 4
I 4
D 5
		{ "Lydia",		specs+68, 1, 12, 40, 2, 0 },
		{ "Natividad",		specs+69, 2, 2,  40, 4, 0 }
E 5
I 5
		{ "Lydia",		specs+68, N_B, 12, 40, 2, 0 },
		{ "Natividad",		specs+69, N_S,  2, 40, 4, 0 }
E 5
E 4
	},
D 6
	1, 3, 6, 0, 1, 0, 2, "Curse of the Flying Dutchman",
E 6
I 6
	1, 3, 6, 2, "Curse of the Flying Dutchman",
E 6
	{
D 4
		{ "Piece of Cake",   19, 2, 7,  40, 2, 0 },
		{ "Flying Dutchy",   71, 3, 7,  41, 1, 0 }
E 4
I 4
D 5
		{ "Piece of Cake",	specs+19, 2, 7,  40, 2, 0 },
		{ "Flying Dutchy",	specs+71, 3, 7,  41, 1, 0 }
E 5
I 5
		{ "Piece of Cake",	specs+19, N_S,  7, 40, 2, 0 },
		{ "Flying Dutchy",	specs+71, N_F,  7, 41, 1, 0 }
E 5
E 4
	},
D 6
	1, 4, 1, 0, 1, 0, 4, "The South Pacific",
E 6
I 6
	1, 4, 1, 4, "The South Pacific",
E 6
	{
D 4
		{ "USS Scurvy",      70, 0, 7,  40, 1, 0 },
		{ "HMS Tahiti",      71, 1, 12, 60, 1, 0 },
		{ "Australian",      18, 2, 5,  20, 8, 0 },
		{ "Bikini Atoll",    63, 3, 2,  60, 4, 0 }
E 4
I 4
D 5
		{ "USS Scurvy",		specs+70, 0, 7,  40, 1, 0 },
		{ "HMS Tahiti",		specs+71, 1, 12, 60, 1, 0 },
		{ "Australian",		specs+18, 2, 5,  20, 8, 0 },
		{ "Bikini Atoll",	specs+63, 3, 2,  60, 4, 0 }
E 5
I 5
		{ "USS Scurvy",		specs+70, N_A,  7, 40, 1, 0 },
		{ "HMS Tahiti",		specs+71, N_B, 12, 60, 1, 0 },
		{ "Australian",		specs+18, N_S,  5, 20, 8, 0 },
		{ "Bikini Atoll",	specs+63, N_F,  2, 60, 4, 0 }
E 5
E 4
	},
D 6
	7, 3, 6, 0, 1, 0, 5, "Hornblower and the battle of Rosas bay",
E 6
I 6
	7, 3, 6, 5, "Hornblower and the battle of Rosas bay",
E 6
	{
D 4
		{ "Sutherland",      5,  1, 13, 30, 2, 0 },
		{ "Turenne",         10, 3, 9,  35, 6, 0 },
		{ "Nightmare",       9,  3, 7,  37, 6, 0 },
		{ "Paris",           53, 3, 3,  45, 4, 0 },
		{ "Napolean",        56, 3, 1,  40, 6, 0 }
E 4
I 4
D 5
		{ "Sutherland",		specs+5,  1, 13, 30, 2, 0 },
		{ "Turenne",		specs+10, 3, 9,  35, 6, 0 },
		{ "Nightmare",		specs+9,  3, 7,  37, 6, 0 },
		{ "Paris",		specs+53, 3, 3,  45, 4, 0 },
		{ "Napolean",		specs+56, 3, 1,  40, 6, 0 }
E 5
I 5
		{ "Sutherland",		specs+5,  N_B, 13, 30, 2, 0 },
		{ "Turenne",		specs+10, N_F,  9, 35, 6, 0 },
		{ "Nightmare",		specs+9,  N_F,  7, 37, 6, 0 },
		{ "Paris",		specs+53, N_F,  3, 45, 4, 0 },
		{ "Napolean",		specs+56, N_F,  1, 40, 6, 0 }
E 5
E 4
	},
D 6
	6, 4, 7, 0, 1, 0, 5, "Cape Horn",
E 6
I 6
	6, 4, 7, 5, "Cape Horn",
E 6
	{
D 4
		{ "Concord",         51, 0, 3,  20, 4, 0 },
		{ "Berkeley",        7,  0, 5,  50, 5, 0 },
		{ "Thames",          71, 1, 10, 40, 1, 0 },
		{ "Madrid",          53, 2, 13, 60, 8, 0 },
		{ "Musket",          10, 3, 10, 60, 7, 0 }
E 4
I 4
D 5
		{ "Concord",		specs+51, 0, 3,  20, 4, 0 },
		{ "Berkeley",		specs+7,  0, 5,  50, 5, 0 },
		{ "Thames",		specs+71, 1, 10, 40, 1, 0 },
		{ "Madrid",		specs+53, 2, 13, 60, 8, 0 },
		{ "Musket",		specs+10, 3, 10, 60, 7, 0 }
E 5
I 5
		{ "Concord",		specs+51, N_A,  3, 20, 4, 0 },
		{ "Berkeley",		specs+7,  N_A,  5, 50, 5, 0 },
		{ "Thames",		specs+71, N_B, 10, 40, 1, 0 },
		{ "Madrid",		specs+53, N_S, 13, 60, 8, 0 },
		{ "Musket",		specs+10, N_F, 10, 60, 7, 0 }
E 5
E 4
	},
D 6
	8, 3, 7, 0, 1, 0, 3, "New Orleans",
E 6
I 6
	8, 3, 7, 3, "New Orleans",
E 6
	{
D 4
		{ "Alligator",       71, 0, 13,  5, 1, 0 },
		{ "Firefly",         50, 1, 10, 20, 8, 0 },
		{ "Cypress",         46, 1, 5,  10, 6, 0 }
E 4
I 4
D 5
		{ "Alligator",		specs+71, 0, 13,  5, 1, 0 },
		{ "Firefly",		specs+50, 1, 10, 20, 8, 0 },
		{ "Cypress",		specs+46, 1, 5,  10, 6, 0 }
E 5
I 5
		{ "Alligator",		specs+71, N_A, 13,  5, 1, 0 },
		{ "Firefly",		specs+50, N_B, 10, 20, 8, 0 },
		{ "Cypress",		specs+46, N_B,  5, 10, 6, 0 }
E 5
E 4
	},
D 6
	5, 3, 7, 0, 1, 0, 3, "Botany Bay",
E 6
I 6
	5, 3, 7, 3, "Botany Bay",
E 6
	{
D 4
		{ "Shark",           11, 1, 6,  15, 4, 0 },
		{ "Coral Snake",     31, 3, 3,  30, 6, 0 },
		{ "Sea Lion",        33, 3, 13, 50, 8, 0 }
E 4
I 4
D 5
		{ "Shark",		specs+11, 1, 6,  15, 4, 0 },
		{ "Coral Snake",	specs+31, 3, 3,  30, 6, 0 },
		{ "Sea Lion",		specs+33, 3, 13, 50, 8, 0 }
E 5
I 5
		{ "Shark",		specs+11, N_B,  6, 15, 4, 0 },
		{ "Coral Snake",	specs+31, N_F,  3, 30, 6, 0 },
		{ "Sea Lion",		specs+33, N_F, 13, 50, 8, 0 }
E 5
E 4
	},
D 6
	4, 3, 6, 0, 1, 0, 4, "Voyage to the Bottom of the Sea",
E 6
I 6
	4, 3, 6, 4, "Voyage to the Bottom of the Sea",
E 6
	{
D 4
		{ "Seaview",         71, 0, 6,  3,  3, 0 },
		{ "Flying Sub",      64, 0, 8,  3,  3, 0 },
		{ "Mermaid",         70, 1, 2,  5,  5, 0 },
		{ "Giant Squid",     53, 2, 10, 30, 8, 0 }
E 4
I 4
D 5
		{ "Seaview",		specs+71, 0, 6,  3,  3, 0 },
		{ "Flying Sub",		specs+64, 0, 8,  3,  3, 0 },
		{ "Mermaid",		specs+70, 1, 2,  5,  5, 0 },
		{ "Giant Squid",	specs+53, 2, 10, 30, 8, 0 }
E 5
I 5
		{ "Seaview",		specs+71, N_A,  6, 3,  3, 0 },
		{ "Flying Sub",		specs+64, N_A,  8, 3,  3, 0 },
		{ "Mermaid",		specs+70, N_B,  2, 5,  5, 0 },
		{ "Giant Squid",	specs+53, N_S, 10, 30, 8, 0 }
E 5
E 4
	},
D 6
	7, 3, 6, 0, 1, 0, 3, "Frigate Action",
E 6
I 6
	7, 3, 6, 3, "Frigate Action",
E 6
	{
D 4
		{ "Killdeer",        21, 0, 7,  20, 8, 0 },
		{ "Sandpiper",       27, 1, 5,  40, 8, 0 },
		{ "Curlew",          34, 2, 10, 60, 8, 0 }
E 4
I 4
D 5
		{ "Killdeer",		specs+21, 0, 7,  20, 8, 0 },
		{ "Sandpiper",		specs+27, 1, 5,  40, 8, 0 },
		{ "Curlew",		specs+34, 2, 10, 60, 8, 0 }
E 5
I 5
		{ "Killdeer",		specs+21, N_A,  7, 20, 8, 0 },
		{ "Sandpiper",		specs+27, N_B,  5, 40, 8, 0 },
		{ "Curlew",		specs+34, N_S, 10, 60, 8, 0 }
E 5
E 4
	},
D 6
	7, 2, 5, 0, 1, 0, 6, "The Battle of Midway",
E 6
I 6
	7, 2, 5, 6, "The Battle of Midway",
E 6
	{
D 4
		{ "Enterprise",      49, 0, 10, 70, 8, 0 },
		{ "Yorktown",        51, 0, 3,  70, 7, 0 },
		{ "Hornet",          52, 0, 6,  70, 7, 0 },
		{ "Akagi",           53, 3, 6,  10, 4, 0 },
		{ "Kaga",            54, 3, 4,  12, 4, 0 },
		{ "Soryu",           55, 3, 2,  14, 4, 0 }
E 4
I 4
		{ "Enterprise",		specs+49, N_A, 10, 70, 8, 0 },
D 5
		{ "Yorktown",		specs+51, N_A, 3,  70, 7, 0 },
		{ "Hornet",		specs+52, N_A, 6,  70, 7, 0 },
		{ "Akagi",		specs+53, N_J, 6,  10, 4, 0 },
		{ "Kaga",		specs+54, N_J, 4,  12, 4, 0 },
		{ "Soryu",		specs+55, N_J, 2,  14, 4, 0 }
E 5
I 5
		{ "Yorktown",		specs+51, N_A,  3, 70, 7, 0 },
		{ "Hornet",		specs+52, N_A,  6, 70, 7, 0 },
		{ "Akagi",		specs+53, N_J,  6, 10, 4, 0 },
		{ "Kaga",		specs+54, N_J,  4, 12, 4, 0 },
		{ "Soryu",		specs+55, N_J,  2, 14, 4, 0 }
E 5
E 4
	},
I 4
D 7
	/*
E 4
D 6
	4, 3, 4, 0, 1, 0, 8, "Star Trek",
E 6
I 6
	4, 3, 4, 8, "Star Trek",
E 7
I 7
	1, 3, 4, 8, "Star Trek",
E 7
E 6
	{
D 4
		{ "Enterprise",      72, 0, 20,  4, 2, 0 },
		{ "Yorktown",        72, 0, 19,  2, 2, 0 },
		{ "Reliant",         73, 0, 18,  3, 2, 0 },
		{ "Galileo",         74, 0, 20,  6, 2, 0 },
		{ "Kobayashi Maru",  75, 3, 31, 11, 5, 0 },
		{ "Klingon two",     75, 3, 31, 11, 5, 0 },
		{ "Klingon three",   75, 3, 31, 11, 5, 0 },
		{ "Blue Orion",      63, 2, 31, 11, 5, 0 }
E 4
I 4
D 5
		{ "Enterprise",		specs+72, 0, 20,  4, 2, 0 },
		{ "Yorktown",		specs+72, 0, 19,  2, 2, 0 },
		{ "Reliant",		specs+73, 0, 18,  3, 2, 0 },
		{ "Galileo",		specs+74, 0, 20,  6, 2, 0 },
		{ "Kobayashi Maru",	specs+75, 3, 31, 11, 5, 0 },
		{ "Klingon two",	specs+75, 3, 31, 11, 5, 0 },
		{ "Klingon three",	specs+75, 3, 31, 11, 5, 0 },
		{ "Blue Orion",		specs+63, 2, 31, 11, 5, 0 }
E 5
I 5
D 7
		{ "Enterprise",		specs+72, N_A, 20,  4, 2, 0 },
		{ "Yorktown",		specs+72, N_A, 19,  2, 2, 0 },
		{ "Reliant",		specs+73, N_A, 18,  3, 2, 0 },
		{ "Galileo",		specs+74, N_A, 20,  6, 2, 0 },
		{ "Kobayashi Maru",	specs+75, N_F, 31, 11, 5, 0 },
		{ "Klingon two",	specs+75, N_F, 31, 11, 5, 0 },
		{ "Klingon three",	specs+75, N_F, 31, 11, 5, 0 },
		{ "Blue Orion",		specs+63, N_S, 31, 11, 5, 0 }
E 7
I 7
		{ "Enterprise",		specs+76, N_D,-10, 60, 7, 0 },
		{ "Yorktown",		specs+77, N_D,  0, 70, 7, 0 },
		{ "Reliant",		specs+78, N_D, 10, 70, 7, 0 },
		{ "Galileo",		specs+79, N_D, 20, 60, 7, 0 },
		{ "Kobayashi Maru",	specs+80, N_K,  0,120, 7, 0 },
		{ "Klingon II",		specs+81, N_K, 10,120, 7, 0 },
		{ "Red Orion",		specs+82, N_O,  0,  0, 3, 0 },
		{ "Blue Orion",		specs+83, N_O, 10,  0, 3, 0 }
E 7
E 5
E 4
	}
I 4
D 7
	*/
E 7
E 4
};
I 7
int nscene = sizeof scene / sizeof (struct scenario);
E 7

D 6
/* happy */
E 6
D 3
struct shipspecs {
	int bs, fs, ta, guns, class, hull, qual, crew1, crew2, crew3, gunL, gunR, carL, carR, rig1, rig2, rig3, rig4, pts;
} specs[] = {
E 3
I 3
struct shipspecs specs[] = {
E 3
D 5
	4, 7, 3,  19, 5,  5, 4,  2,  2,  2,  2,  2, 0, 0,  4, 4, 4, 4,  7,
	4, 7, 3,  17, 5,  5, 4,  2,  2,  2,  0,  0, 4, 4,  3, 3, 3, 3,  6,
	3, 5, 2,  42, 4,  7, 4,  2,  2,  2,  2,  2, 0, 0,  5, 5, 5, -1, 11,
	4, 6, 3,  44, 3,  7, 4,  2,  2,  2,  3,  3, 0, 0,  5, 5, 5, 5,  12,
	3, 5, 2,  64, 2, 17, 4,  8,  6,  6, 12, 12, 2, 2,  7, 7, 7, -1, 20,
	3, 5, 2,  74, 2, 20, 4,  8,  8,  8, 16, 16, 2, 2,  7, 7, 7, -1, 26,
	3, 5, 2,  50, 2, 12, 4,  6,  4,  4,  8,  8, 2, 2,  6, 6, 6, -1, 17,
	3, 5, 1,  98, 1, 23, 4, 10, 10, 10, 18, 18, 2, 2,  8, 8, 8, -1, 28,
	3, 5, 2,  74, 2, 20, 4,  8,  8,  8, 16, 16, 2, 2,  7, 7, 7, -1, 26,
	3, 5, 2,  74, 2, 21, 3, 10, 10,  8, 20, 20, 0, 0,  7, 7, 7, -1, 24,
	3, 5, 1,  80, 1, 23, 3, 12, 12, 10, 22, 22, 0, 0,  7, 7, 7, -1, 27,
	3, 5, 2,  64, 2, 18, 3,  8,  8,  6, 12, 12, 0, 0,  7, 7, 7, -1, 18,
	3, 5, 2,  44, 2, 11, 3,  4,  4,  4,  6,  6, 2, 2,  5, 5, 5, -1, 10,
	3, 5, 2,  50, 2, 14, 3,  6,  6,  4,  8,  8, 0, 0,  6, 6, 6, -1, 14,
	4, 6, 3,  36, 3, 11, 4,  4,  4,  2,  4,  4, 2, 2,  5, 5, 5, 5,  11,
	4, 6, 3,  36, 3, 11, 3,  4,  4,  4,  4,  4, 2, 2,  5, 5, 5, 5,  10,
	3, 5, 2,  74, 2, 21, 4, 10,  8,  8, 18, 18, 2, 2,  7, 7, 7, -1, 26,
	3, 5, 2,  74, 2, 21, 3, 10, 10,  8, 20, 20, 2, 2,  7, 7, 7, -1, 23,
	4, 6, 3,  32, 3,  8, 3,  4,  2,  2,  4,  4, 2, 2,  5, 5, 5, 5,  9,
	4, 6, 3,  24, 4,  6, 3,  4,  4,  4,  2,  2, 0, 0,  4, 4, 4, 4,  9,
	4, 7, 3,  38, 4, 14, 5,  6,  4,  4,  4,  4, 6, 6,  5, 5, 5, 5,  17,
	4, 6, 3,  40, 3, 15, 3,  8,  6,  6,  6,  6, 4, 4,  5, 5, 5, 5,  15,
	4, 7, 3,  36, 4, 11, 3,  6,  6,  4,  4,  4, 2, 2,  5, 5, 5, 5,  11,
	4, 6, 3,  32, 3, 11, 5,  4,  4,  2,  4,  4, 2, 2,  5, 5, 5, 5,  13,
	4, 6, 3,  38, 3, 14, 5,  4,  4,  4,  6,  6, 4, 4,  5, 5, 5, 5,  18,
	4, 6, 3,  22, 3,  6, 5,  2,  2,  2,  0,  0, 8, 8,  4, 4, 4, 4,  11,
	4, 6, 3,  32, 3, 11, 5,  4,  4,  2,  4,  4, 2, 2,  5, 5, 5, 5,  13,
	4, 6, 3,  40, 3, 14, 3,  6,  6,  4,  6,  6, 4, 4,  5, 5, 5, 5,  15,
	4, 6, 3,  32, 3, 11, 2,  4,  4,  4,  4,  4, 0, 0,  5, 5, 5, 5,  9,
	4, 6, 3,  40, 3, 14, 2,  6,  6,  4,  6,  6, 4, 4,  5, 5, 5, 5,  12,
	4, 6, 3,  32, 3,  8, 2,  4,  4,  1,  2,  2, 0, 0,  4, 4, 4, 4,  7,
	4, 7, 3,  44, 4, 18, 5,  6,  6,  6,  8,  8, 6, 6,  6, 6, 6, 6,  24,
	4, 6, 3,  38, 3, 14, 4,  4,  4,  2,  6,  6, 4, 4,  5, 5, 5, 5,  15,
	4, 5, 3,  44, 3, 18, 5,  8,  6,  6,  8,  8, 8, 8,  6, 6, 6, 6,  24,
	4, 6, 3,  38, 3, 14, 4,  4,  4,  4,  6,  6, 4, 4,  5, 5, 5, 5,  16,
	4, 7, 3,  38, 4, 14, 4,  6,  6,  6,  6,  6, 6, 6,  5, 5, 5, 5,  19,
	4, 6, 3,  38, 3, 14, 3,  6,  6,  4,  6,  6, 6, 6,  5, 5, 5, 5,  14,
	4, 6, 3,  38, 3, 14, 5,  6,  4,  4,  6,  6, 6, 6,  5, 5, 5, 5,  17,
	4, 7, 3,  20, 5,  6, 4,  4,  2,  2,  0,  0, 6, 6,  4, 4, 4, 4,  9,
	4, 7, 3,  13, 6,  3, 4,  0,  2,  2,  0,  0, 2, 2,  2, 2, 2, 2,  5,
	4, 7, 3,  19, 5,  5, 4,  2,  2,  2,  2,  2, 0, 0,  4, 4, 4, 4,  7,
	4, 7, 3,  17, 5,  5, 4,  2,  2,  2,  2,  2, 0, 0,  3, 3, 3, 3,  6,
	4, 7, 3,  20, 5,  6, 5,  4,  2,  2,  0,  0, 6, 6,  4, 4, 4, 4,  12,
	4, 7, 3,  18, 5,  5, 5,  2,  2,  2,  0,  0, 6, 6,  4, 4, 4, 4,  9,
	4, 7, 3,  24, 5,  6, 4,  4,  2,  2,  0,  0,10,10,  4, 4, 4, 4,  11,
	4, 7, 3,  20, 5,  6, 4,  2,  2,  2,  0,  0, 8, 8,  4, 4, 4, 4,  10,
	4, 6, 3,  44, 3, 11, 5,  4,  4,  4,  4,  4, 2, 2,  5, 5, 5, 5,  14,
	4, 6, 3,  36, 3, 12, 4,  4,  4,  4,  6,  6, 2, 2,  5, 5, 5, 5,  14,
	3, 5, 2,  74, 2, 21, 3, 10,  8,  8, 20, 20, 2, 2,  4, 4, 7, -1, 24,
	3, 5, 2,  80, 2, 24, 4, 10,  8,  8, 20, 20, 2, 2,  8, 8, 8, -1, 31,
	3, 5, 2,  74, 2, 21, 4,  8,  8,  6, 16, 16, 4, 4,  7, 7, 7, -1, 27,
	3, 5, 2,  80, 2, 24, 3, 12, 12, 10, 22, 22, 2, 2,  7, 7, 7, -1, 27,
	3, 5, 2,  74, 2, 21, 3, 10, 10,  8, 20, 20, 2, 2,  7, 7, 7, -1, 24,
	3, 5, 1, 112, 1, 27, 2, 12, 12, 12, 24, 24, 0, 0,  9, 9, 9, -1, 27,
	3, 5, 1,  96, 1, 24, 2, 12, 12, 10, 20, 20, 0, 0,  8, 8, 8, -1, 24,
	3, 5, 2,  80, 2, 23, 2, 10, 10,  8, 20, 20, 0, 0,  7, 7, 7, -1, 23,
	3, 5, 2,  74, 2, 21, 2, 10,  8,  8, 16, 16, 4, 4,  7, 7, 7, -1, 20,
	4, 6, 3,  37, 3, 12, 4,  4,  4,  2,  6,  6, 4, 4,  5, 5, 5, 5,  14,
	4, 7, 3,  16, 5,  5, 5,  2,  2,  2,  0,  0, 4, 4,  4, 4, 4, 4,  10,
	4, 7, 3,  11, 6,  3, 4,  2,  2,  2,  0,  0, 2, 2,  2, 2, 2, 2,  5,
	4, 7, 3,  26, 5,  6, 4,  4,  2,  2,  2,  2, 6, 6,  4, 4, 4, 4,  12,
	4, 7, 3,  20, 5,  6, 4,  4,  2,  2,  0,  0, 6, 6,  4, 4, 4, 4,  11,
	4, 7, 3,  17, 5,  5, 4,  2,  2,  2,  0,  0, 6, 6,  4, 4, 4, 4,  9,
	4, 7, 3,   7, 6,  3, 4,  0,  2,  2,  0,  0, 2, 2,  2, 2, 2, 2,  4,
	4, 6, 3,  40, 3, 15, 4,  4,  4,  4,  8,  8, 6, 6,  5, 5, 5, 5,  17,
	4, 6, 3,  44, 3, 15, 4,  8,  8,  6, 10, 10, 2, 2,  6, 6, 6, 6,  20,
	4, 6, 3,  38, 3, 14, 4,  4,  4,  4,  6,  6, 6, 6,  5, 5, 5, 5,  15,
	4, 5, 3,  44, 3, 18, 5,  8,  6,  6,  8,  8, 8, 8,  6, 6, 6, 6,  24,
	4, 6, 3,  36, 3,  9, 5,  4,  4,  2,  4,  4, 2, 2,  5, 5, 5, 5,  13,
	3, 5, 2,  50, 2, 14, 2,  6,  6,  6,  8,  8, 0, 0,  6, 6, 6, -1, 14,
	3, 5, 1, 136, 1, 30, 1,  8, 14, 14, 28, 28, 0, 0,  9, 9, 9, -1, 27,
	3, 5, 1, 120, 1, 27, 5, 16, 14, 14, 28, 28, 2, 2,  9, 9, 9, -1, 43,
/*72*/  3, 5, 1, 120, 2, 21, 5, 15, 17, 15, 25, 25, 7, 7,  9, 9, 9, -1, 36,
/*73*/  3, 5, 1,  90, 3, 18, 4, 13, 15, 13, 20, 20, 6, 6,  5, 5, 5,  5, 28,
/*74*/  4, 7, 3,   6, 6,  3, 4,  2,  2,  2, 20, 20, 6, 6,  2, 2, 3,  3,  5,
/*75*/  3, 5, 1, 110, 2, 20, 4, 14, 15, 11, 26, 26, 8, 8,  7, 8, 9, -1, 34,

/*int bs, fs, ta, guns, class, hull, qual, crew1, crew2, crew3, gunL, gunR, carL, carR, rig1, rig2, rig3, rig4, pts*/
E 5
I 5
/*      bs fs ta guns   hull  crew1   crew3    gunR  carR   rig2  rig4 pts */
/*                 class   qual   crew2    gunL   carL   rig1  rig3        */
/*00*/	4, 7, 3,  19, 5,  5, 4,  2,  2,  2,  2,  2, 0, 0,  4, 4, 4,  4,  7,
/*01*/	4, 7, 3,  17, 5,  5, 4,  2,  2,  2,  0,  0, 4, 4,  3, 3, 3,  3,  6,
/*02*/	3, 5, 2,  42, 4,  7, 4,  2,  2,  2,  2,  2, 0, 0,  5, 5, 5, -1, 11,
/*03*/	4, 6, 3,  44, 3,  7, 4,  2,  2,  2,  3,  3, 0, 0,  5, 5, 5,  5, 12,
/*04*/	3, 5, 2,  64, 2, 17, 4,  8,  6,  6, 12, 12, 2, 2,  7, 7, 7, -1, 20,
/*05*/	3, 5, 2,  74, 2, 20, 4,  8,  8,  8, 16, 16, 2, 2,  7, 7, 7, -1, 26,
/*06*/	3, 5, 2,  50, 2, 12, 4,  6,  4,  4,  8,  8, 2, 2,  6, 6, 6, -1, 17,
/*07*/	3, 5, 1,  98, 1, 23, 4, 10, 10, 10, 18, 18, 2, 2,  8, 8, 8, -1, 28,
/*08*/	3, 5, 2,  74, 2, 20, 4,  8,  8,  8, 16, 16, 2, 2,  7, 7, 7, -1, 26,
/*09*/	3, 5, 2,  74, 2, 21, 3, 10, 10,  8, 20, 20, 0, 0,  7, 7, 7, -1, 24,
/*10*/	3, 5, 1,  80, 1, 23, 3, 12, 12, 10, 22, 22, 0, 0,  7, 7, 7, -1, 27,
/*11*/	3, 5, 2,  64, 2, 18, 3,  8,  8,  6, 12, 12, 0, 0,  7, 7, 7, -1, 18,
/*12*/	3, 5, 2,  44, 2, 11, 3,  4,  4,  4,  6,  6, 2, 2,  5, 5, 5, -1, 10,
/*13*/	3, 5, 2,  50, 2, 14, 3,  6,  6,  4,  8,  8, 0, 0,  6, 6, 6, -1, 14,
/*14*/	4, 6, 3,  36, 3, 11, 4,  4,  4,  2,  4,  4, 2, 2,  5, 5, 5,  5, 11,
/*15*/	4, 6, 3,  36, 3, 11, 3,  4,  4,  4,  4,  4, 2, 2,  5, 5, 5,  5, 10,
/*16*/	3, 5, 2,  74, 2, 21, 4, 10,  8,  8, 18, 18, 2, 2,  7, 7, 7, -1, 26,
/*17*/	3, 5, 2,  74, 2, 21, 3, 10, 10,  8, 20, 20, 2, 2,  7, 7, 7, -1, 23,
/*18*/	4, 6, 3,  32, 3,  8, 3,  4,  2,  2,  4,  4, 2, 2,  5, 5, 5,  5,  9,
/*19*/	4, 6, 3,  24, 4,  6, 3,  4,  4,  4,  2,  2, 0, 0,  4, 4, 4,  4,  9,
/*20*/	4, 7, 3,  38, 4, 14, 5,  6,  4,  4,  4,  4, 6, 6,  5, 5, 5,  5, 17,
/*21*/	4, 6, 3,  40, 3, 15, 3,  8,  6,  6,  6,  6, 4, 4,  5, 5, 5,  5, 15,
/*22*/	4, 7, 3,  36, 4, 11, 3,  6,  6,  4,  4,  4, 2, 2,  5, 5, 5,  5, 11,
/*23*/	4, 6, 3,  32, 3, 11, 5,  4,  4,  2,  4,  4, 2, 2,  5, 5, 5,  5, 13,
/*24*/	4, 6, 3,  38, 3, 14, 5,  4,  4,  4,  6,  6, 4, 4,  5, 5, 5,  5, 18,
/*25*/	4, 6, 3,  22, 3,  6, 5,  2,  2,  2,  0,  0, 8, 8,  4, 4, 4,  4, 11,
/*26*/	4, 6, 3,  32, 3, 11, 5,  4,  4,  2,  4,  4, 2, 2,  5, 5, 5,  5, 13,
/*27*/	4, 6, 3,  40, 3, 14, 3,  6,  6,  4,  6,  6, 4, 4,  5, 5, 5,  5, 15,
/*28*/	4, 6, 3,  32, 3, 11, 2,  4,  4,  4,  4,  4, 0, 0,  5, 5, 5,  5,  9,
/*29*/	4, 6, 3,  40, 3, 14, 2,  6,  6,  4,  6,  6, 4, 4,  5, 5, 5,  5, 12,
/*30*/	4, 6, 3,  32, 3,  8, 2,  4,  4,  1,  2,  2, 0, 0,  4, 4, 4,  4,  7,
/*31*/	4, 7, 3,  44, 4, 18, 5,  6,  6,  6,  8,  8, 6, 6,  6, 6, 6,  6, 24,
/*32*/	4, 6, 3,  38, 3, 14, 4,  4,  4,  2,  6,  6, 4, 4,  5, 5, 5,  5, 15,
/*33*/	4, 5, 3,  44, 3, 18, 5,  8,  6,  6,  8,  8, 8, 8,  6, 6, 6,  6, 24,
/*34*/	4, 6, 3,  38, 3, 14, 4,  4,  4,  4,  6,  6, 4, 4,  5, 5, 5,  5, 16,
/*35*/	4, 7, 3,  38, 4, 14, 4,  6,  6,  6,  6,  6, 6, 6,  5, 5, 5,  5, 19,
/*36*/	4, 6, 3,  38, 3, 14, 3,  6,  6,  4,  6,  6, 6, 6,  5, 5, 5,  5, 14,
/*37*/	4, 6, 3,  38, 3, 14, 5,  6,  4,  4,  6,  6, 6, 6,  5, 5, 5,  5, 17,
/*38*/	4, 7, 3,  20, 5,  6, 4,  4,  2,  2,  0,  0, 6, 6,  4, 4, 4,  4,  9,
/*39*/	4, 7, 3,  13, 6,  3, 4,  0,  2,  2,  0,  0, 2, 2,  2, 2, 2,  2,  5,
/*40*/	4, 7, 3,  19, 5,  5, 4,  2,  2,  2,  2,  2, 0, 0,  4, 4, 4,  4,  7,
/*41*/	4, 7, 3,  17, 5,  5, 4,  2,  2,  2,  2,  2, 0, 0,  3, 3, 3,  3,  6,
/*42*/	4, 7, 3,  20, 5,  6, 5,  4,  2,  2,  0,  0, 6, 6,  4, 4, 4,  4, 12,
/*43*/	4, 7, 3,  18, 5,  5, 5,  2,  2,  2,  0,  0, 6, 6,  4, 4, 4,  4,  9,
/*44*/	4, 7, 3,  24, 5,  6, 4,  4,  2,  2,  0,  0,10,10,  4, 4, 4,  4, 11,
/*45*/	4, 7, 3,  20, 5,  6, 4,  2,  2,  2,  0,  0, 8, 8,  4, 4, 4,  4, 10,
/*46*/	4, 6, 3,  44, 3, 11, 5,  4,  4,  4,  4,  4, 2, 2,  5, 5, 5,  5, 14,
/*47*/	4, 6, 3,  36, 3, 12, 4,  4,  4,  4,  6,  6, 2, 2,  5, 5, 5,  5, 14,
/*48*/	3, 5, 2,  74, 2, 21, 3, 10,  8,  8, 20, 20, 2, 2,  4, 4, 7, -1, 24,
/*49*/	3, 5, 2,  80, 2, 24, 4, 10,  8,  8, 20, 20, 2, 2,  8, 8, 8, -1, 31,
/*50*/	3, 5, 2,  74, 2, 21, 4,  8,  8,  6, 16, 16, 4, 4,  7, 7, 7, -1, 27,
/*51*/	3, 5, 2,  80, 2, 24, 3, 12, 12, 10, 22, 22, 2, 2,  7, 7, 7, -1, 27,
/*52*/	3, 5, 2,  74, 2, 21, 3, 10, 10,  8, 20, 20, 2, 2,  7, 7, 7, -1, 24,
/*53*/	3, 5, 1, 112, 1, 27, 2, 12, 12, 12, 24, 24, 0, 0,  9, 9, 9, -1, 27,
/*54*/	3, 5, 1,  96, 1, 24, 2, 12, 12, 10, 20, 20, 0, 0,  8, 8, 8, -1, 24,
/*55*/	3, 5, 2,  80, 2, 23, 2, 10, 10,  8, 20, 20, 0, 0,  7, 7, 7, -1, 23,
/*56*/	3, 5, 2,  74, 2, 21, 2, 10,  8,  8, 16, 16, 4, 4,  7, 7, 7, -1, 20,
/*57*/	4, 6, 3,  37, 3, 12, 4,  4,  4,  2,  6,  6, 4, 4,  5, 5, 5,  5, 14,
/*58*/	4, 7, 3,  16, 5,  5, 5,  2,  2,  2,  0,  0, 4, 4,  4, 4, 4,  4, 10,
/*59*/	4, 7, 3,  11, 6,  3, 4,  2,  2,  2,  0,  0, 2, 2,  2, 2, 2,  2,  5,
/*60*/	4, 7, 3,  26, 5,  6, 4,  4,  2,  2,  2,  2, 6, 6,  4, 4, 4,  4, 12,
/*61*/	4, 7, 3,  20, 5,  6, 4,  4,  2,  2,  0,  0, 6, 6,  4, 4, 4,  4, 11,
/*62*/	4, 7, 3,  17, 5,  5, 4,  2,  2,  2,  0,  0, 6, 6,  4, 4, 4,  4,  9,
/*63*/	4, 7, 3,   7, 6,  3, 4,  0,  2,  2,  0,  0, 2, 2,  2, 2, 2,  2,  4,
/*64*/	4, 6, 3,  40, 3, 15, 4,  4,  4,  4,  8,  8, 6, 6,  5, 5, 5,  5, 17,
/*65*/	4, 6, 3,  44, 3, 15, 4,  8,  8,  6, 10, 10, 2, 2,  6, 6, 6,  6, 20,
/*66*/	4, 6, 3,  38, 3, 14, 4,  4,  4,  4,  6,  6, 6, 6,  5, 5, 5,  5, 15,
/*67*/	4, 5, 3,  44, 3, 18, 5,  8,  6,  6,  8,  8, 8, 8,  6, 6, 6,  6, 24,
/*68*/	4, 6, 3,  36, 3,  9, 5,  4,  4,  2,  4,  4, 2, 2,  5, 5, 5,  5, 13,
/*69*/	3, 5, 2,  50, 2, 14, 2,  6,  6,  6,  8,  8, 0, 0,  6, 6, 6, -1, 14,
/*70*/	3, 5, 1, 136, 1, 30, 1,  8, 14, 14, 28, 28, 0, 0,  9, 9, 9, -1, 27,
/*71*/	3, 5, 1, 120, 1, 27, 5, 16, 14, 14, 28, 28, 2, 2,  9, 9, 9, -1, 43,
/*72*/	3, 5, 1, 120, 2, 21, 5, 15, 17, 15, 25, 25, 7, 7,  9, 9, 9, -1, 36,
/*73*/	3, 5, 1,  90, 3, 18, 4, 13, 15, 13, 20, 20, 6, 6,  5, 5, 5,  5, 28,
/*74*/	4, 7, 3,   6, 6,  3, 4,  2,  2,  2, 20, 20, 6, 6,  2, 2, 3,  3,  5,
/*75*/	3, 5, 1, 110, 2, 20, 4, 14, 15, 11, 26, 26, 8, 8,  7, 8, 9, -1, 34,
I 7
D 8
/*76*/	4, 7, 3, 136, 1, 99, 5, 36, 36, 36, 30, 30,10,10,  9, 9, 9,  9, 50,
/*77*/	4, 7, 3, 136, 1, 99, 5, 36, 36, 36, 30, 30,10,10,  9, 9, 9,  9, 50,
/*78*/	4, 7, 3, 136, 1, 99, 5, 36, 36, 36, 30, 30,10,10,  9, 9, 9,  9, 50,
/*79*/	4, 7, 3, 136, 1, 99, 5, 36, 36, 36, 30, 30,10,10,  9, 9, 9,  9, 50,
/*80*/	4, 7, 3, 136, 1, 99, 5, 36, 36, 36, 30, 30,10,10,  9, 9, 9,  9, 50,
/*81*/	4, 7, 3, 136, 1, 99, 5, 36, 36, 36, 30, 30,10,10,  9, 9, 9,  9, 50,
/*82*/	4, 7, 3, 136, 1, 99, 5, 36, 36, 36, 30, 30,10,10,  9, 9, 9,  9, 50,
/*83*/	4, 7, 3, 136, 1, 99, 5, 36, 36, 36, 30, 30,10,10,  9, 9, 9,  9, 50,
E 8
I 8
/*76*/	4, 7, 3, 450, 1, 99, 5, 50, 40, 40, 50, 50,25,25,  9, 9, 9, -1, 75,
/*77*/	4, 7, 3, 450, 1, 99, 5, 50, 40, 40, 50, 50,25,25,  9, 9, 9, -1, 75,
/*78*/	4, 7, 3, 450, 1, 99, 5, 50, 40, 40, 50, 50,25,25,  9, 9, 9, -1, 75,
/*79*/	4, 7, 3, 450, 1, 99, 5, 50, 40, 40, 50, 50,25,25,  9, 9, 9, -1, 75,
/*80*/	4, 7, 3, 450, 1, 99, 5, 50, 40, 40, 50, 50,25,25,  9, 9, 9, -1, 75,
/*81*/	4, 7, 3, 450, 1, 99, 5, 50, 40, 40, 50, 50,25,25,  9, 9, 9, -1, 75,
/*82*/	4, 7, 3, 450, 1, 99, 5, 50, 40, 40, 50, 50,25,25,  9, 9, 9, -1, 75,
/*83*/	4, 7, 3, 450, 1, 99, 5, 50, 40, 40, 50, 50,25,25,  9, 9, 9, -1, 75,
E 8
/*      bs fs ta guns   hull  crew1   crew3    gunR  carR   rig2  rig4 pts */
/*                 class   qual   crew2    gunL   carL   rig1  rig3        */
E 7
E 5
};

D 3
struct windeffects {
	int A, B, C, D;
} WET[7][6] = {
E 3
I 3
struct windeffects WET[7][6] = {
E 3
	{ {9,9,9,9}, {9,9,9,9}, {9,9,9,9}, {9,9,9,9}, {9,9,9,9}, {9,9,9,9} },
	{ {3,2,2,0}, {3,2,1,0}, {3,2,1,0}, {3,2,1,0}, {2,1,0,0}, {2,1,0,0} },
	{ {1,1,1,0}, {1,1,0,0}, {1,0,0,0}, {1,0,0,0}, {1,0,0,0}, {1,0,0,0} },
	{ {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} },
	{ {0,0,0,0}, {1,0,0,0}, {1,1,0,0}, {1,1,0,0}, {2,2,1,0}, {2,2,1,0} },
	{ {1,0,0,0}, {1,1,0,0}, {1,1,1,0}, {1,1,1,0}, {3,2,2,0}, {3,2,2,0} },
	{ {2,1,1,0}, {3,2,1,0}, {3,2,1,0}, {3,2,1,0}, {3,3,2,0}, {3,3,2,0} }
};
I 5

E 5
D 3
struct Tables {
	int H, G, C, R;
} RigTable[11][6] = {
E 3
I 3
struct Tables RigTable[11][6] = {
E 3
D 5
	 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,1, 0,0,1,0 , 
	 0,0,0,0, 0,0,0,0, 0,0,0,1, 0,0,1,0, 1,0,0,1, 0,1,1,1 ,
	 0,0,0,0, 0,0,0,1, 0,0,1,1, 0,1,0,1, 0,1,0,1, 1,0,1,2 ,
	 0,0,0,0, 0,0,1,1, 0,1,0,1, 0,0,0,2, 0,1,0,2, 1,0,1,2 ,
	 0,1,0,1, 1,0,0,1, 0,1,1,2, 0,1,0,2, 0,0,1,3, 1,0,1,4 ,
	 0,0,1,1, 0,1,0,2, 1,0,0,3, 0,1,1,3, 1,0,0,4, 1,1,1,4 ,
	 0,0,1,2, 0,1,1,2, 1,1,0,3, 0,1,0,4, 1,0,0,4, 1,0,1,5 ,
	 0,0,1,2, 0,1,0,3, 1,1,0,3, 1,0,2,4, 0,2,1,5, 2,1,0,5 ,
	 0,2,1,3, 1,0,0,3, 2,1,0,4, 0,1,1,4, 0,1,0,5, 1,0,2,6 ,
	 1,1,0,4, 1,0,1,4, 2,0,0,5, 0,2,1,5, 0,1,2,6, 0,2,0,7 ,
	 1,0,1,5, 0,2,0,6, 1,2,0,6, 1,1,1,6, 2,0,2,6, 1,1,2,7 ,
E 5
I 5
	{ {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,1}, {0,0,1,0} },
	{ {0,0,0,0}, {0,0,0,0}, {0,0,0,1}, {0,0,1,0}, {1,0,0,1}, {0,1,1,1} },
	{ {0,0,0,0}, {0,0,0,1}, {0,0,1,1}, {0,1,0,1}, {0,1,0,1}, {1,0,1,2} },
	{ {0,0,0,0}, {0,0,1,1}, {0,1,0,1}, {0,0,0,2}, {0,1,0,2}, {1,0,1,2} },
	{ {0,1,0,1}, {1,0,0,1}, {0,1,1,2}, {0,1,0,2}, {0,0,1,3}, {1,0,1,4} },
	{ {0,0,1,1}, {0,1,0,2}, {1,0,0,3}, {0,1,1,3}, {1,0,0,4}, {1,1,1,4} },
	{ {0,0,1,2}, {0,1,1,2}, {1,1,0,3}, {0,1,0,4}, {1,0,0,4}, {1,0,1,5} },
	{ {0,0,1,2}, {0,1,0,3}, {1,1,0,3}, {1,0,2,4}, {0,2,1,5}, {2,1,0,5} },
	{ {0,2,1,3}, {1,0,0,3}, {2,1,0,4}, {0,1,1,4}, {0,1,0,5}, {1,0,2,6} },
	{ {1,1,0,4}, {1,0,1,4}, {2,0,0,5}, {0,2,1,5}, {0,1,2,6}, {0,2,0,7} },
	{ {1,0,1,5}, {0,2,0,6}, {1,2,0,6}, {1,1,1,6}, {2,0,2,6}, {1,1,2,7} }
E 5
};
struct Tables HullTable[11][6] = {
D 5
	 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,0,0, 0,1,0,0 , 
	 0,0,0,0, 0,0,0,0, 0,1,0,0, 1,1,0,0, 1,0,1,0, 1,0,1,1 ,
	 0,1,0,0, 1,0,0,0, 1,1,0,0, 1,0,1,0, 1,0,1,1, 2,1,0,0 ,
	 0,1,1,0, 1,0,0,0, 1,1,1,0, 2,0,0,1, 2,0,1,0, 2,2,0,0 ,
	 0,1,1,0, 1,0,0,1, 2,1,0,1, 2,2,1,0, 3,0,1,0, 3,1,0,0 ,
	 1,1,1,0, 2,0,2,1, 2,1,1,0, 2,2,0,0, 3,1,0,1, 3,1,1,0 ,
	 1,2,2,0, 2,0,2,1, 2,1,0,1, 2,2,0,0, 3,1,1,0, 4,2,1,0 ,
	 2,1,1,0, 2,0,1,1, 3,2,2,0, 3,2,0,0, 4,2,1,0, 4,2,1,1 ,
	 2,1,2,0, 3,1,1,1, 3,2,2,0, 4,2,1,0, 4,1,0,2, 4,2,2,0 ,
	 2,3,1,0, 3,2,2,0, 3,2,2,1, 4,2,2,0, 4,1,0,3, 5,1,2,0 ,
	 2,2,4,0, 3,3,1,1, 4,2,1,1, 5,1,0,2, 5,1,2,1, 6,2,2,0 ,
E 5
I 5
	{ {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {1,0,0,0}, {0,1,0,0} },
	{ {0,0,0,0}, {0,0,0,0}, {0,1,0,0}, {1,1,0,0}, {1,0,1,0}, {1,0,1,1} },
	{ {0,1,0,0}, {1,0,0,0}, {1,1,0,0}, {1,0,1,0}, {1,0,1,1}, {2,1,0,0} },
	{ {0,1,1,0}, {1,0,0,0}, {1,1,1,0}, {2,0,0,1}, {2,0,1,0}, {2,2,0,0} },
	{ {0,1,1,0}, {1,0,0,1}, {2,1,0,1}, {2,2,1,0}, {3,0,1,0}, {3,1,0,0} },
	{ {1,1,1,0}, {2,0,2,1}, {2,1,1,0}, {2,2,0,0}, {3,1,0,1}, {3,1,1,0} },
	{ {1,2,2,0}, {2,0,2,1}, {2,1,0,1}, {2,2,0,0}, {3,1,1,0}, {4,2,1,0} },
	{ {2,1,1,0}, {2,0,1,1}, {3,2,2,0}, {3,2,0,0}, {4,2,1,0}, {4,2,1,1} },
	{ {2,1,2,0}, {3,1,1,1}, {3,2,2,0}, {4,2,1,0}, {4,1,0,2}, {4,2,2,0} },
	{ {2,3,1,0}, {3,2,2,0}, {3,2,2,1}, {4,2,2,0}, {4,1,0,3}, {5,1,2,0} },
	{ {2,2,4,0}, {3,3,1,1}, {4,2,1,1}, {5,1,0,2}, {5,1,2,1}, {6,2,2,0} },
E 5
};

D 5
int AMMO[9][4] = {
	{-1,1,0,1},
	{-1,1,0,1},
D 2
	{-2,1,0,1},
	{-2,1,0,2},
	{-3,2,0,2},
	{-3,2,0,2},
	{-4,2,0,2},
	{-4,2,0,3},
	{-4,2,0,3}
E 2
I 2
	{-1,1,0,1},
	{-1,1,0,2},
	{-1,2,0,2},
	{-2,2,0,2},
	{-2,2,0,2},
	{-2,2,0,3},
	{-2,2,0,3}
E 5
I 5
char AMMO[9][4] = {
	{ -1, 1, 0, 1 },
	{ -1, 1, 0, 1 },
	{ -1, 1, 0, 1 },
D 7
	{ -1, 1, 0, 2 },
	{ -1, 2, 0, 2 },
E 7
I 7
	{ -2, 1, 0, 2 },
E 7
	{ -2, 2, 0, 2 },
	{ -2, 2, 0, 2 },
D 7
	{ -2, 2, 0, 3 },
	{ -2, 2, 0, 3 }
E 7
I 7
	{ -3, 2, 0, 2 },
	{ -3, 2, 0, 3 },
	{ -3, 2, 0, 3 }
E 7
E 5
E 2
};
	
D 5
int HDT[9][10] = {
	{1,0,-1,-2,-3,-3,-4,-4,-4,-4},
	{1,1,0,-1,-2,-2,-3,-3,-3,-3},
	{2,1,0,-1,-2,-2,-3,-3,-3,-3},
	{2,2,1,0,-1,-1,-2,-2,-2,-2},
	{3,2,1,0,-1,-1,-2,-2,-2,-2},
	{3,3,2,1,0,0,-1,-1,-1,-1},
	{4,3,2,1,0,0,-1,-1,-1,-1},
	{4,4,3,2,1,1,0,0,0,0},
	{5,4,3,2,1,1,0,0,0,0}
E 5
I 5
char HDT[9][10] = {
	{ 1, 0,-1,-2,-3,-3,-4,-4,-4,-4 },
	{ 1, 1, 0,-1,-2,-2,-3,-3,-3,-3 },
	{ 2, 1, 0,-1,-2,-2,-3,-3,-3,-3 },
	{ 2, 2, 1, 0,-1,-1,-2,-2,-2,-2 },
	{ 3, 2, 1, 0,-1,-1,-2,-2,-2,-2 },
	{ 3, 3, 2, 1, 0, 0,-1,-1,-1,-1 },
	{ 4, 3, 2, 1, 0, 0,-1,-1,-1,-1 },
	{ 4, 4, 3, 2, 1, 1, 0, 0, 0, 0 },
	{ 5, 4, 3, 2, 1, 1, 0, 0, 0, 0 }
E 5
};

D 5
int HDTrake[9][10] = {
	{2,1,0,-1,-2,-2,-3,-3,-3,-3},
	{2,2,1,0,-1,-1,-2,-2,-2,-2},
	{3,2,1,0,-1,-1,-2,-2,-2,-2},
	{4,3,2,1,0,0,-1,-1,-1,-1},
	{5,4,3,2,1,1,0,0,0,0},
	{6,5,4,3,2,2,1,1,1,1},
	{7,6,5,4,3,3,2,2,2,2},
	{8,7,6,5,4,4,3,3,3,3},
	{9,8,7,6,5,5,4,4,4,4}
E 5
I 5
char HDTrake[9][10] = {
	{ 2, 1, 0,-1,-2,-2,-3,-3,-3,-3 },
	{ 2, 2, 1, 0,-1,-1,-2,-2,-2,-2 },
	{ 3, 2, 1, 0,-1,-1,-2,-2,-2,-2 },
	{ 4, 3, 2, 1, 0, 0,-1,-1,-1,-1 },
	{ 5, 4, 3, 2, 1, 1, 0, 0, 0, 0 },
	{ 6, 5, 4, 3, 2, 2, 1, 1, 1, 1 },
	{ 7, 6, 5, 4, 3, 3, 2, 2, 2, 2 },
	{ 8, 7, 6, 5, 4, 4, 3, 3, 3, 3 },
	{ 9, 8, 7, 6, 5, 5, 4, 4, 4, 4 }
E 5
};

D 5
int QUAL[9][5] = {
	{-1,0,0,1,1},
	{-1,0,0,1,1},
	{-1,0,0,1,2},
	{-1,0,0,1,2},
	{-1,0,0,2,2},
	{-1,-1,0,2,2},
	{-2,-1,0,2,2},
	{-2,-1,0,2,2},
	{-2,-1,0,2,3}
E 5
I 5
char QUAL[9][5] = {
	{ -1, 0, 0, 1, 1 },
	{ -1, 0, 0, 1, 1 },
	{ -1, 0, 0, 1, 2 },
	{ -1, 0, 0, 1, 2 },
	{ -1, 0, 0, 2, 2 },
	{ -1,-1, 0, 2, 2 },
	{ -2,-1, 0, 2, 2 },
	{ -2,-1, 0, 2, 2 },
	{ -2,-1, 0, 2, 3 }
E 5
};

D 5
int MT[9][3] = {
	{1,0,0},
	{1,1,0},
	{2,1,0},
	{2,1,1},
	{2,2,1},
	{3,2,1},
	{3,2,2},
	{4,3,2},
	{4,4,2}
E 5
I 5
char MT[9][3] = {
	{ 1, 0, 0 },
	{ 1, 1, 0 },
	{ 2, 1, 0 },
	{ 2, 1, 1 },
	{ 2, 2, 1 },
	{ 3, 2, 1 },
	{ 3, 2, 2 },
	{ 4, 3, 2 },
	{ 4, 4, 2 }
E 5
};

D 4
int loaded, fired, changed, repaired, buffercount, xlast, ylast;
long lastsync;
int winddir, windspeed, turn, viewrow, viewcol;
int player = -1, nation[5], scroll = 18, game;
int MIGHTYCAPTAIN;
char Outbuf[BUFSIZE], movebuf[10], loadwith[20];
FILE *syncfile;
E 4
I 4
D 5
int rangeofshot[] = {
E 5
I 5
char rangeofshot[] = {
E 5
	0,
	1,		/* grape */
	3,		/* chain */
	10,		/* round */
	1		/* double */
};

char *countryname[] = {
D 5
	"American",
	"British",
	"Spanish",
	"French",
	"Japanese"
E 5
I 5
D 7
	"American", "British", "Spanish", "French", "Japanese"
E 7
I 7
	"American", "British", "Spanish", "French", "Japanese",
	"Federation", "Klingon", "Orion"
E 7
E 5
};

char *classname[] = {
	"Drift wood",
	"Ship of the Line",
	"Ship of the Line",
	"Frigate",
	"Corvette",
	"Sloop",
	"Brig"
};

char *directionname[] = {
	"dead ahead",
	"off the starboard bow",
	"off the starboard beam",
	"off the starboard quarter",
	"dead astern",
	"off the port quarter",
	"off the port beam",
	"off the port bow",
	"dead ahead"
};

D 5
char *qualname[] = {
	"dead",
	"mutinous",
	"green",
	"mundane",
	"crack",
	"elite"
};
E 5
I 5
char *qualname[] = { "dead", "mutinous", "green", "mundane", "crack", "elite" };
E 5

D 5
char loadname[] = {
	'-', 'G', 'C', 'R', 'D', 'E'
};
E 5
I 5
char loadname[] = { '-', 'G', 'C', 'R', 'D', 'E' };
E 5

D 5
char dr[] = {
	0, 1, 1, 0, -1, -1, -1, 0, 1
};
char dc[] = {
	0, 0, -1, -1, -1, 0, 1, 1, 1
};
E 5
I 5
char dr[] = { 0, 1, 1, 0, -1, -1, -1, 0, 1 };
char dc[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
E 5
E 4
D 3

E 3
E 1
