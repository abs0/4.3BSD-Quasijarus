h34412
s 00010/00005/00284
d D 5.3 88/06/18 19:55:27 bostic 19 18
c install approved copyright notice
e
s 00008/00002/00281
d D 5.2 88/03/09 12:24:13 bostic 18 17
c written by David Riggle and Edward Wang; add Berkeley specific copyright
e
s 00005/00007/00278
d D 5.1 85/05/29 16:13:02 dist 17 16
c Add copyright
e
s 00007/00000/00278
d D 2.7 85/04/23 21:47:06 edward 16 15
c copyright message
e
s 00003/00002/00275
d D 2.6 85/04/22 01:48:27 edward 15 14
c -b flag for no bells
e
s 00017/00001/00260
d D 2.5 85/03/04 18:06:48 edward 14 13
c more cleanup; sail, driver, sail.log merged into single program
e
s 00003/00000/00258
d D 2.4 84/02/23 16:04:10 edward 13 12
c W_DDEAD and NLOG added, hasdriver moved here form player.h
e
s 00029/00020/00229
d D 2.3 83/12/17 12:38:39 edward 12 11
c new grapple and foul data structure.
e
s 00001/00001/00248
d D 2.2 83/11/03 12:53:01 edward 11 10
c use -10 for sterncolour
e
s 00000/00000/00249
d D 2.1 83/10/31 13:43:53 edward 10 9
c new version
e
s 00007/00003/00242
d D 1.9 83/10/28 22:49:12 edward 9 8
c the startrek scenario
e
s 00001/00001/00244
d D 1.8 83/10/14 22:47:11 edward 8 7
c last remnant of old Signal() scheme
e
s 00009/00009/00236
d D 1.7 83/10/10 20:10:14 edward 7 6
c got rid of unnecessary variables
e
s 00060/00064/00185
d D 1.6 83/10/05 11:43:55 edward 6 5
c changed sizes of things and reformated globals.c
e
s 00189/00062/00060
d D 1.5 83/07/20 17:21:34 edward 5 4
c 
e
s 00027/00024/00095
d D 1.4 83/05/20 19:09:09 edward 4 3
c moved driver to /usr/games/lib and merged externs.h and globals.c
e
s 00000/00000/00119
d D 1.3 83/05/20 17:43:35 root 3 2
c merge
e
s 00001/00001/00118
d D 1.2 83/05/19 22:56:09 leres 2 1
c NUMOFSCENES is 31, not 32
e
s 00119/00000/00000
d D 1.1 83/03/17 21:16:32 leres 1 0
c date and time created 83/03/17 21:16:32 by leres
e
u
U
t
T
I 1
/*
I 16
D 17
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
 */

/*
E 16
D 5
 * sccsid = "%W% %E%";
E 5
I 5
 * %W% %E%
E 17
I 17
 * Copyright (c) 1983 Regents of the University of California.
D 18
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 18
I 18
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 19
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 19
I 19
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
E 19
E 18
 *
 *	%W% (Berkeley) %G%
E 17
E 5
 */
I 16

E 16
#include <stdio.h>
#include <signal.h>
#include <ctype.h>
I 14
#include <setjmp.h>
E 14
#include "machdep.h"

I 14
	/* program mode */
int mode;
jmp_buf restart;
#define MODE_PLAYER	1
#define MODE_DRIVER	2
#define MODE_LOGGER	3

	/* command line flags */
char debug;				/* -D */
D 15
char randomize;				/* -x */
char longfmt;				/* -l */
E 15
I 15
char randomize;				/* -x, give first available ship */
char longfmt;				/* -l, print score in long format */
char nobells;				/* -b, don't ring bell before Signal */
E 15

	/* other initial modes */
char issetuid;				/* running setuid */

E 14
D 2
#define NUMOFSCENES 32
E 2
I 2
D 4
#define NUMOFSCENES 31
E 4
I 4
D 5
#define NUMOFSCENES 32
E 5
I 5
#define die()		((rand() >> 3) % 6 + 1)
#define sqr(a)		((a) * (a))
#define abs(a)		((a) > 0 ? (a) : -(a))
#define min(a,b)	((a) < (b) ? (a) : (b))
E 5
E 4
E 2

D 5
#define die() (((rand() >> 6) % 6) + 1)
#define fouled(a) Fouled(a, 342)
#define grappled(a) Fouled(a, 382)
#define grapple(a,b) Grapple(a,b,382)
#define foul(a,b) Grapple(a,b,342)
#define sqr(a) ((a) * (a))
#define abs(a) ((a) > 0 ? (a) : -(a))
#define min(a,b) ((a) < (b) ? (a) : (b))
E 5
I 5
D 12
#define grappled(a)	Snagged(a, 1)
#define fouled(a)	Snagged(a, 0)
#define snagged(a)	(Snagged(a, 0) || Snagged(a, 1))
#define grappled2(a,b)	Snagged2(a, b, 1, 0)
#define fouled2(a,b)	Snagged2(a, b, 0, 0)
#define snagged2(a,b)	(Snagged2(a, b, 0, 0) || Snagged2(a, b, 1, 0))
#define Xgrappled2(a,b)	Snagged2(a, b, 1, 1)
#define Xfouled2(a,b)	Snagged2(a, b, 0, 1)
#define Xsnagged2(a,b)	(Snagged2(a, b, 0, 1) || Snagged2(a, b, 1, 1))
E 12
I 12
#define grappled(a)	((a)->file->ngrap)
#define fouled(a)	((a)->file->nfoul)
#define snagged(a)	(grappled(a) + fouled(a))
E 12
E 5

I 12
#define grappled2(a, b)	((a)->file->grap[(b)->file->index].sn_count)
#define fouled2(a, b)	((a)->file->foul[(b)->file->index].sn_count)
#define snagged2(a, b)	(grappled2(a, b) + fouled2(a, b))

#define Xgrappled2(a, b) ((a)->file->grap[(b)->file->index].sn_turn < turn-1 ? grappled2(a, b) : 0)
#define Xfouled2(a, b)	((a)->file->foul[(b)->file->index].sn_turn < turn-1 ? fouled2(a, b) : 0)
#define Xsnagged2(a, b)	(Xgrappled2(a, b) + Xfouled2(a, b))

#define cleangrapple(a, b, c)	Cleansnag(a, b, c, 1)
#define cleanfoul(a, b, c)	Cleansnag(a, b, c, 2)
#define cleansnag(a, b, c)	Cleansnag(a, b, c, 3)

E 12
D 5
#define GRAPE   1
#define CHAIN   2
#define ROUND   3
#define DOUBLE  4
E 5
I 5
D 11
#define sterncolour(sp)	((sp)->file->stern+'0'-((sp)->file->captured?16:0))
E 11
I 11
#define sterncolour(sp)	((sp)->file->stern+'0'-((sp)->file->captured?10:0))
E 11
#define sternrow(sp)	((sp)->file->row + dr[(sp)->file->dir])
#define sterncol(sp)	((sp)->file->col + dc[(sp)->file->dir])
E 5

D 5
#define HULL    0
#define RIGGING 1
E 5
I 5
#define capship(sp)	((sp)->file->captured?(sp)->file->captured:(sp))
E 5

D 5
#define SPECS	32
#define FILES	64
#define SCENARIO	128
E 5
I 5
#define readyname(r)	((r) & R_LOADING ? '*' : ((r) & R_INITIAL ? '!' : ' '))
E 5

I 5
/* loadL and loadR, should match loadname[] */
#define L_EMPTY		0		/* should be 0, don't change */
#define L_GRAPE		1
#define L_CHAIN		2
#define L_ROUND		3
#define L_DOUBLE	4
#define L_EXPLODE	5

/*
 * readyL and readyR, these are bits, except R_EMPTY
 */
#define R_EMPTY		0		/* not loaded and not loading */
#define R_LOADING	1		/* loading */
#define R_DOUBLE	2		/* loading double */
#define R_LOADED	4		/* loaded */
#define R_INITIAL	8		/* loaded initial */

#define HULL		0
#define RIGGING		1

#define W_CAPTAIN	1
#define W_CAPTURED	2
#define W_CLASS		3
#define W_CREW		4
#define W_DBP		5
#define W_DRIFT		6
#define W_EXPLODE	7
#define W_FILE		8
#define W_FOUL		9
#define W_GUNL		10
#define W_GUNR		11
#define W_HULL		12
D 12
#define W_LAST		13
E 12
I 12
#define W_MOVE		13
E 12
#define W_OBP		14
#define W_PCREW		15
D 7
#define W_PEOPLE	16
E 7
I 7
D 12
/* 16 */
E 12
I 12
#define W_UNFOUL	16
E 12
E 7
#define W_POINTS	17
#define W_QUAL		18
D 12
/* 19 */
E 12
I 12
#define W_UNGRAP	19
E 12
#define W_RIGG		20
D 12
#define W_SHIPCOL	21
#define W_SHIPDIR	22
#define W_SHIPROW	23
E 12
I 12
#define W_COL		21
#define W_DIR		22
#define W_ROW		23
E 12
#define W_SIGNAL	24
#define W_SINK		25
#define W_STRUCK	26
#define W_TA		27
D 7
#define W_TIME		28
E 7
I 7
#define W_ALIVE		28
E 7
#define W_TURN		29
#define W_WIND		30
#define W_FS		31
#define W_GRAP		32
#define W_RIG1		33
#define W_RIG2		34
#define W_RIG3		35
#define W_RIG4		36
I 7
#define W_BEGIN		37
#define W_END		38
I 13
#define W_DDEAD		39
E 13
E 7

I 13
#define NLOG 10
E 13
E 5
struct logs {
D 5
    char fname[20];
    int uid, fshipnum, fgamenum, netpoints;
E 5
I 5
	char l_name[20];
	int l_uid;
	int l_shipnum;
	int l_gamenum;
	int l_netpoints;
E 5
};

D 4
extern struct BP {
E 4
I 4
struct BP {
E 4
D 5
	int turnsent, toship, mensent;
E 5
I 5
D 6
	int turnsent;
E 6
I 6
	short turnsent;
E 6
	struct ship *toship;
D 6
	int mensent;
E 6
I 6
	short mensent;
E 6
E 5
};

D 4
extern struct snag {
E 4
I 4
struct snag {
E 4
D 5
	int turnfoul, toship;
E 5
I 5
D 6
	int turnfoul;
E 6
I 6
D 12
	short turnfoul;
E 6
	struct ship *toship;
E 12
I 12
	short sn_count;
	short sn_turn;
E 12
E 5
};

D 5
typedef struct {
	int row, col, dir;
} postype;
D 4
extern postype pos[20];
E 4
I 4
postype pos[20];
E 5
I 5
D 9
#define NSCENE	31
E 9
I 9
#define NSCENE	nscene
E 9
#define NSHIP	10
#define NBP	3
E 5
E 4

I 5
D 9
#define NNATION	5
E 9
I 9
#define NNATION	8
E 9
#define N_A	0
#define N_B	1
#define N_S	2
#define N_F	3
#define N_J	4
I 9
#define N_D	5
#define N_K	6
#define N_O	7
E 9

E 5
D 4
extern struct File {
E 4
I 4
struct File {
I 12
	int index;
E 12
E 4
D 5
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
E 5
I 5
	char captain[20];		/* 0 */
D 6
	int points;			/* 20 */
	int loadL;			/* 22 */
	int loadR;			/* 24 */
	int readyL;			/* 26 */
	int readyR;			/* 28 */
E 6
I 6
	short points;			/* 20 */
	char loadL;			/* 22 */
	char loadR;			/* 24 */
	char readyL;			/* 26 */
	char readyR;			/* 28 */
E 6
	struct BP OBP[NBP];		/* 30 */
	struct BP DBP[NBP];		/* 48 */
D 6
	int struck;			/* 66 */
E 6
I 6
	char struck;			/* 66 */
E 6
	struct ship *captured;		/* 68 */
D 6
	int pcrew;			/* 70 */
E 6
I 6
	short pcrew;			/* 70 */
E 6
D 12
	char last[10];			/* 72 */
E 12
I 12
	char movebuf[10];		/* 72 */
E 12
D 6
	int drift;			/* 82 */
E 6
I 6
	char drift;			/* 82 */
E 6
D 12
	struct snag fouls[NSHIP];	/* 84 */
	struct snag grapples[NSHIP];	/* 124 */
E 12
I 12
	short nfoul;
	short ngrap;
	struct snag foul[NSHIP];	/* 84 */
	struct snag grap[NSHIP];	/* 124 */
E 12
D 8
	char signal[60];		/* 164 */
E 8
D 6
	int RH;				/* 224 */
	int RG;				/* 226 */
	int RR;				/* 228 */
	int FS;				/* 230 */
	int explode;			/* 232 */
	int sink;			/* 234 */
	int dir;
	int col;
	int row;
	int loadwith;
	int stern;
E 6
I 6
	char RH;			/* 224 */
	char RG;			/* 226 */
	char RR;			/* 228 */
	char FS;			/* 230 */
	char explode;			/* 232 */
	char sink;			/* 234 */
	char dir;
	short col;
	short row;
	char loadwith;
	char stern;
E 6
E 5
};

D 5
typedef struct {
	char *shipname;
	int shipnum, nationality;
	int shiprow, shipcol, shipdir;
	struct File *file;
} ships;
E 5
I 5
struct ship {
	char *shipname;			/* 0 */
	struct shipspecs *specs;	/* 2 */
D 6
	int nationality;		/* 4 */
	int shiprow;			/* 6 */
	int shipcol;			/* 8 */
	int shipdir;			/* 10 */
E 6
I 6
	char nationality;		/* 4 */
	short shiprow;			/* 6 */
	short shipcol;			/* 8 */
	char shipdir;			/* 10 */
E 6
	struct File *file;		/* 12 */
};
E 5

struct scenario {
D 5
	int winddir, windspeed, windchange;
	int turn, people, time, vessels;
	char *name;
	ships ship[10];
E 5
I 5
D 6
	int winddir;			/* 0 */
	int windspeed;			/* 2 */
	int windchange;			/* 4 */
	int turn;			/* 6 */
	int people;			/* 8 */
	int time;			/* 10 */
	int vessels;			/* 12 */
E 6
I 6
	char winddir;			/* 0 */
	char windspeed;			/* 2 */
	char windchange;		/* 4 */
D 7
	short turn;			/* 6 */
	char people;			/* 8 */
	char time;			/* 10 */
E 7
	char vessels;			/* 12 */
E 6
	char *name;			/* 14 */
	struct ship ship[NSHIP];	/* 16 */
E 5
};
D 4
extern struct scenario scene[NUMOFSCENES];
E 4
I 4
D 5
struct scenario scene[NUMOFSCENES];
E 5
I 5
D 9
struct scenario scene[NSCENE];
E 9
I 9
struct scenario scene[];
int nscene;
E 9
E 5
E 4

struct shipspecs {
D 5
	int bs, fs, ta, guns, class, hull, qual, crew1,
		crew2, crew3, gunL, gunR, carL, carR,
		rig1, rig2, rig3, rig4, pts;
E 5
I 5
D 6
	int bs;
	int fs;
	int ta;
	int guns;
	int class;
	int hull;
	int qual;
	int crew1;
	int crew2;
	int crew3;
	int gunL;
	int gunR;
	int carL;
	int carR;
	int rig1;
	int rig2;
	int rig3;
	int rig4;
	int pts;
E 6
I 6
	char bs;
	char fs;
	char ta;
	short guns;
	char class;
	char hull;
	char qual;
	char crew1;
	char crew2;
	char crew3;
	char gunL;
	char gunR;
	char carL;
	char carR;
	char rig1;
	char rig2;
	char rig3;
	char rig4;
	short pts;
E 6
E 5
};
D 4
extern struct shipspecs specs[];
E 4
I 4
struct shipspecs specs[];
E 4

I 5
struct scenario *cc;		/* the current scenario */
struct ship *ls;		/* &cc->ship[cc->vessels] */

#define SHIP(s)		(&cc->ship[s])
#define foreachship(sp)	for ((sp) = cc->ship; (sp) < ls; (sp)++)

E 5
D 4
extern struct windeffects {
E 4
I 4
struct windeffects {
E 4
D 6
	int A, B, C, D;
E 6
I 6
	char A, B, C, D;
E 6
D 4
} WET[7][6];
extern struct Tables {
E 4
I 4
};
struct windeffects WET[7][6];

struct Tables {
E 4
D 6
	int H, G, C, R;
E 6
I 6
	char H, G, C, R;
E 6
D 4
} RigTable[11][6];
extern struct Tables HullTable[11][6];
E 4
I 4
};
struct Tables RigTable[11][6];
struct Tables HullTable[11][6];
E 4

D 4
extern int AMMO[9][4];
E 4
I 4
D 6
int AMMO[9][4];
E 6
I 6
char AMMO[9][4];
char HDT[9][10];
char HDTrake[9][10];
char QUAL[9][5];
char MT[9][3];
E 6
E 4

D 4
extern int HDT[9][10];
E 4
I 4
D 6
int HDT[9][10];
E 4

D 4
extern int HDTrake[9][10];
E 4
I 4
int HDTrake[9][10];
E 4

D 4
extern int QUAL[9][5];
E 4
I 4
int QUAL[9][5];
E 4

D 4
extern int MT[9][3];
E 4
I 4
int MT[9][3];
E 4

E 6
D 4
extern int loaded, fired, changed, repaired, buffercount, xlast, ylast;
extern long lastsync;
extern int winddir, windspeed, turn, viewrow, viewcol;
extern int player, nation[5], scroll, game;
extern int MIGHTYCAPTAIN;
extern char Outbuf[BUFSIZE], movebuf[10], loadwith[20];
extern FILE *syncfile;
E 4
I 4
D 5
int loaded, fired, changed, repaired, buffercount, xlast, ylast;
E 5
I 5
char *countryname[];
char *classname[];
char *directionname[];
char *qualname[];
char loadname[];

D 6
int rangeofshot[];
E 6
I 6
char rangeofshot[];
E 6

char dr[], dc[];

E 5
D 7
long lastsync;
D 5
int winddir, windspeed, turn, viewrow, viewcol;
int player, nation[5], scroll, game;
int MIGHTYCAPTAIN;
char Outbuf[BUFSIZE], movebuf[10], loadwith[20];
E 5
I 5
int winddir, windspeed, turn;
E 7
I 7
int winddir;
int windspeed;
int turn;
E 7
int game;
D 7
char Outbuf[BUFSIZE];
E 5
FILE *syncfile;
E 7
I 7
int alive;
int people;
I 8
D 14
char isplayer;
E 14
I 13
char hasdriver;
E 13
E 8
E 7
E 4

D 5
char colours();
char gunsbear();
E 5
char *info();
D 5
char iinitial();
E 5
char *quality();
D 5
char sterncolor();
char strend();
char symbol();
E 5
double arctan();
I 5
char *saywhat();
struct ship *closestenemy();

char *calloc();
I 14
char *rindex();
E 14
char *strcpy();
char *strcat();
char *strncpy();
char *getenv();
char *gets();
E 5
E 1
