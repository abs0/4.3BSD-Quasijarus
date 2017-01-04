h42870
s 00010/00005/01683
d D 5.8 88/06/18 19:49:12 bostic 20 19
c install approved copyright notice
e
s 00011/00005/01677
d D 5.7 88/05/06 10:36:05 bostic 19 18
c add Berkeley header
e
s 00068/00051/01614
d D 5.6 88/03/26 12:52:25 mckusick 18 17
c add betting information for current set of hands
e
s 00053/00024/01612
d D 5.5 86/07/21 11:22:51 mckusick 17 16
c add return field to betting info; sync out score file more often
e
s 00006/00007/01630
d D 5.4 86/01/13 14:53:00 mckusick 16 15
c Fix bug when moving tableau pile to empty slot (don't allow it).
c Streamline quit sequence. (from thomas@utah-cs)
e
s 00004/00000/01633
d D 5.3 85/07/05 14:01:56 mckusick 15 14
c notify when hand is empty
e
s 00006/00002/01627
d D 5.2 85/07/04 17:09:12 mckusick 14 12
c maximum of ``maxtimecharge == 3'' penalty between moves;
c always allow user to pause before exiting game
e
s 00007/00002/01627
d R 5.2 85/07/04 16:41:39 mckusick 13 12
c maximum of ``maxtimecharge == 3'' penalty between moves;
c always allow user to pause before exitting game
e
s 00014/00002/01615
d D 5.1 85/05/29 11:18:42 dist 12 11
c Add copyright
e
s 00003/00000/01614
d D 4.10 84/08/30 20:35:46 mckusick 11 10
c fix bug in tableau to tableau move
e
s 00000/00004/01614
d D 4.9 83/06/25 22:36:01 sam 10 9
c apply "real" fix????
e
s 00002/00000/01616
d D 4.8 83/06/25 02:53:18 sam 9 8
c fix ^Z
e
s 00008/00006/01608
d D 4.7 83/05/12 23:35:19 mckusick 8 6
c update betting information just before writting it out
e
s 00008/00007/01607
d R 4.7 83/05/12 21:29:28 mckusick 7 6
c remember to update the betting information before writting it out
e
s 00087/00049/01527
d D 4.6 83/05/10 23:30:10 mckusick 6 5
c clean up comments; reset thinking time before each game
e
s 00044/00026/01532
d D 4.5 83/05/10 01:11:08 mckusick 5 4
c give incentive to purchase information; charge for connect time!
e
s 00438/00097/01120
d D 4.4 83/05/09 22:00:16 mckusick 4 3
c add betting capability
e
s 00021/00008/01196
d D 4.3 83/03/13 02:07:26 eric 3 2
c put red cards in standout
e
s 00074/00015/01130
d D 4.2 83/03/13 01:19:50 mckusick 2 1
c add ability to toggle the instructions
e
s 01145/00000/00000
d D 4.1 82/10/24 18:25:54 mckusick 1 0
c date and time created 82/10/24 18:25:54 by mckusick
e
u
U
t
T
I 1
D 12
/* Copyright (c) 1982 Regents of the University of California */
E 12
I 12
/*
D 19
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 19
I 19
 * Copyright (c) 1980 Regents of the University of California.
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
 */
E 12

D 12
static char sccsid[] = "%Z%%M% %I% %G%";
E 12
I 12
#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
D 19
#endif not lint
E 19
I 19
#endif /* not lint */
E 19

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 19
#endif not lint
E 19
I 19
#endif /* not lint */
E 19
E 12

/*
 * The canfield program
 *
 * Authors:
 *	Originally written: Steve Levine
 *	Converted to use curses and debugged: Steve Feldman
 *	Card counting: Kirk McKusick and Mikey Olson
I 2
 *	User interface cleanups: Eric Allman and Kirk McKusick
I 4
 *	Betting by Kirk McKusick
E 4
E 2
 */

#include <curses.h>
#include <ctype.h>
#include <signal.h>
I 5
#include <sys/types.h>
E 5

#define	decksize	52
#define originrow	0
#define origincol	0
#define	basecol		1
#define	boxcol		42
#define	tboxrow		2
D 2
#define	bboxrow		16
E 2
I 2
#define	bboxrow		17
E 2
#define	movecol		43
D 2
#define	moverow		15
E 2
I 2
#define	moverow		16
E 2
#define	msgcol		43
D 2
#define	msgrow		14
E 2
I 2
#define	msgrow		15
E 2
#define	titlecol	30
#define	titlerow	0
#define	sidecol		1
#define	ottlrow		6
#define	foundcol	11
#define	foundrow	3
#define	stockcol	2
#define	stockrow	8
#define	fttlcol		10
#define	fttlrow		1
#define	taloncol	2
#define	talonrow	13
#define	tabrow		8
#define ctoprow		21
#define cbotrow		23
#define cinitcol	14
#define cheightcol	1
#define cwidthcol	4
#define handstatrow	21
#define handstatcol	7
#define talonstatrow	22
#define talonstatcol	7
#define stockstatrow	23
#define stockstatcol	7
#define	Ace		1
#define	Jack		11
#define	Queen		12
#define	King		13
#define	atabcol		11
#define	btabcol		18
#define	ctabcol		25
#define	dtabcol		32

#define	spades		's'
#define	clubs		'c'
#define	hearts		'h'
#define	diamonds	'd'
#define	black		'b'
#define	red		'r'

#define stk		1
#define	tal		2
#define tab		3
#define INCRHAND(row, col) {\
	row -= cheightcol;\
	if (row < ctoprow) {\
		row = cbotrow;\
		col += cwidthcol;\
	}\
}
#define DECRHAND(row, col) {\
	row += cheightcol;\
	if (row > cbotrow) {\
		row = ctoprow;\
		col -= cwidthcol;\
	}\
}


struct cardtype {
	char suit;
	char color;
	bool visible;
I 4
	bool paid;
E 4
	int rank;
	struct cardtype *next;
};

#define	NIL	((struct cardtype *) -1)

struct cardtype *deck[decksize];
struct cardtype cards[decksize];
struct cardtype *bottom[4], *found[4], *tableau[4];
struct cardtype *talon, *hand, *stock, *basecard;
int length[4];
int cardsoff, base, cinhand, taloncnt, stockcnt, timesthru;
char suitmap[4] = {spades, clubs, hearts, diamonds};
char colormap[4] = {black, black, red, red};
char pilemap[4] = {atabcol, btabcol, ctabcol, dtabcol};
char srcpile, destpile;
int mtforigin, tempbase;
int coldcol, cnewcol, coldrow, cnewrow;
bool errmsg, done;
D 2
bool mtfdone, Cflag = FALSE;
E 2
I 2
D 4
bool mtfdone, Cflag = FALSE, Iflag = TRUE;
E 4
I 4
bool mtfdone, Cflag = FALSE;
#define INSTRUCTIONBOX	1
#define BETTINGBOX	2
#define NOBOX		3
int status = INSTRUCTIONBOX;
I 17
int uid;
E 17
E 4
E 2

I 4
/*
 * Basic betting costs
 */
#define costofhand		13
#define costofinspection	13
#define costofgame		26
#define costofrunthroughhand	 5
#define costofinformation	 1
I 5
#define secondsperdollar	60
I 14
#define maxtimecharge		 3
E 14
E 5
#define valuepercardup	 	 5
/*
 * Variables associated with betting 
 */
struct betinfo {
	long	hand;		/* cost of dealing hand */
	long	inspection;	/* cost of inspecting hand */
	long	game;		/* cost of buying game */
	long	runs;		/* cost of running through hands */
	long	information;	/* cost of information */
D 5
	long	costs;		/* total costs */
E 5
I 5
	long	thinktime;	/* cost of thinking time */
E 5
	long	wins;		/* total winnings */
	long	worth;		/* net worth after costs */
};
D 18
struct betinfo this, total;
E 18
I 18
struct betinfo this, game, total;
E 18
bool startedgame = FALSE, infullgame = FALSE;
I 5
time_t acctstart;
E 5
int dbfd = -1;
E 4

D 4

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
E 4
I 4
/*
E 4
 * The following procedures print the board onto the screen using the
 * addressible cursor. The end of these procedures will also be
 * separated from the rest of the program.
I 4
 *
 * procedure to set the move command box
E 4
 */
D 4
/* procedure to set the move command box */
E 4
movebox()
{
I 2
D 4
	    printtopinstructions();
	    move(moverow, boxcol);
	    printw("|                          |");
	    move(msgrow, boxcol);
	    printw("|                          |");
	    printbottominstructions();
	    refresh();
E 4
I 4
	switch (status) {
	case BETTINGBOX:
		printtopbettingbox();
		break;
	case NOBOX:
		clearabovemovebox();
		break;
	case INSTRUCTIONBOX:
		printtopinstructions();
		break;
	}
	move(moverow, boxcol);
D 18
	printw("|                          |");
E 18
I 18
	printw("|                                  |");
E 18
	move(msgrow, boxcol);
D 18
	printw("|                          |");
E 18
I 18
	printw("|                                  |");
E 18
	switch (status) {
	case BETTINGBOX:
		printbottombettingbox();
		break;
	case NOBOX:
		clearbelowmovebox();
		break;
	case INSTRUCTIONBOX:
		printbottominstructions();
		break;
	}
	refresh();
E 4
}

/*
 * print directions above move box
 */
printtopinstructions()
{
E 2
	    move(tboxrow, boxcol);
D 18
	    printw("*--------------------------*");
E 18
I 18
	    printw("*----------------------------------*");
E 18
	    move(tboxrow + 1, boxcol);
D 18
	    printw("|         MOVES            |");
E 18
I 18
	    printw("|         MOVES                    |");
E 18
	    move(tboxrow + 2, boxcol);
D 18
	    printw("|s# = stock to tableau     |");
E 18
I 18
	    printw("|s# = stock to tableau             |");
E 18
	    move(tboxrow + 3, boxcol);
D 18
	    printw("|sf = stock to foundation  |");
E 18
I 18
	    printw("|sf = stock to foundation          |");
E 18
	    move(tboxrow + 4, boxcol);
D 18
	    printw("|t# = talon to tableau     |");
E 18
I 18
	    printw("|t# = talon to tableau             |");
E 18
	    move(tboxrow + 5, boxcol);
D 18
	    printw("|tf = talon to foundation  |");
E 18
I 18
	    printw("|tf = talon to foundation          |");
E 18
	    move(tboxrow + 6, boxcol);
D 18
	    printw("|## = tableau to tableau   |");
E 18
I 18
	    printw("|## = tableau to tableau           |");
E 18
	    move(tboxrow + 7, boxcol);
D 18
	    printw("|#f = tableau to foundation|");
E 18
I 18
	    printw("|#f = tableau to foundation        |");
E 18
	    move(tboxrow + 8, boxcol);
D 18
	    printw("|ht = hand to talon        |");
E 18
I 18
	    printw("|ht = hand to talon                |");
E 18
	    move(tboxrow + 9, boxcol);
D 18
	    printw("|c = toggle card counting  |");
E 18
I 18
	    printw("|c = toggle card counting          |");
E 18
	    move(tboxrow + 10, boxcol);
D 2
	    printw("|q = quit to end the game  |");
E 2
I 2
D 4
	    printw("|i = toggle instructions   |");
E 4
I 4
D 18
	    printw("|b = present betting info  |");
E 18
I 18
	    printw("|b = present betting information   |");
E 18
E 4
E 2
	    move(tboxrow + 11, boxcol);
I 2
D 18
	    printw("|q = quit to end the game  |");
E 18
I 18
	    printw("|q = quit to end the game          |");
E 18
	    move(tboxrow + 12, boxcol);
E 2
D 18
	    printw("|==========================|");
E 18
I 18
	    printw("|==================================|");
E 18
D 2
	    move(moverow, boxcol);
	    printw("|                          |");
	    move(msgrow, boxcol);
	    printw("|                          |");
E 2
I 2
}

/*
D 4
 * clear directions above move box
E 4
I 4
 * Print the betting box.
E 4
 */
D 4
cleartopinstructions()
E 4
I 4
printtopbettingbox()
E 4
{
I 4
D 5
	    int i;
E 5

D 5
	    for (i = 0; i <= 1; i++) {
		    move(tboxrow + i, boxcol);
		    printw("                            ");
	    }
	    move(tboxrow + 2, boxcol);
E 5
I 5
	    move(tboxrow, boxcol);
D 17
	    printw("                            ");
	    move(tboxrow + 1, boxcol);
E 17
E 5
D 18
	    printw("*--------------------------*");
E 18
I 18
	    printw("*----------------------------------*");
E 18
D 5
	    move(tboxrow + 3, boxcol);
E 5
I 5
D 17
	    move(tboxrow + 2, boxcol);
E 17
I 17
	    move(tboxrow + 1, boxcol);
E 17
E 5
D 18
	    printw("|Costs        Hand   Total |");
E 18
I 18
	    printw("|Costs        Hand   Game    Total |");
E 18
D 5
	    move(tboxrow + 4, boxcol);
E 5
I 5
D 17
	    move(tboxrow + 3, boxcol);
E 17
I 17
	    move(tboxrow + 2, boxcol);
E 17
E 5
D 18
	    printw("| Hands                    |");
E 18
I 18
	    printw("| Hands                            |");
E 18
D 5
	    move(tboxrow + 5, boxcol);
E 5
I 5
D 17
	    move(tboxrow + 4, boxcol);
E 17
I 17
	    move(tboxrow + 3, boxcol);
E 17
E 5
D 18
	    printw("| Inspections              |");
E 18
I 18
	    printw("| Inspections                      |");
E 18
D 5
	    move(tboxrow + 6, boxcol);
E 5
I 5
D 17
	    move(tboxrow + 5, boxcol);
E 17
I 17
	    move(tboxrow + 4, boxcol);
E 17
E 5
D 18
	    printw("| Games                    |");
E 18
I 18
	    printw("| Games                            |");
E 18
D 5
	    move(tboxrow + 7, boxcol);
E 5
I 5
D 17
	    move(tboxrow + 6, boxcol);
E 17
I 17
	    move(tboxrow + 5, boxcol);
E 17
E 5
D 18
	    printw("| Runs                     |");
E 18
I 18
	    printw("| Runs                             |");
E 18
D 5
	    move(tboxrow + 8, boxcol);
E 5
I 5
D 17
	    move(tboxrow + 7, boxcol);
E 17
I 17
	    move(tboxrow + 6, boxcol);
E 17
E 5
D 18
	    printw("| Information              |");
E 18
I 18
	    printw("| Information                      |");
E 18
I 5
D 17
	    move(tboxrow + 8, boxcol);
E 17
I 17
	    move(tboxrow + 7, boxcol);
E 17
D 18
	    printw("| Think time               |");
E 18
I 18
	    printw("| Think time                       |");
E 18
E 5
D 17
	    move(tboxrow + 9, boxcol);
E 17
I 17
	    move(tboxrow + 8, boxcol);
E 17
D 18
	    printw("|Total Costs               |");
E 18
I 18
	    printw("|Total Costs                       |");
E 18
D 17
	    move(tboxrow + 10, boxcol);
E 17
I 17
	    move(tboxrow + 9, boxcol);
E 17
D 18
	    printw("|Winnings                  |");
E 18
I 18
	    printw("|Winnings                          |");
E 18
D 17
	    move(tboxrow + 11, boxcol);
E 17
I 17
	    move(tboxrow + 10, boxcol);
E 17
D 18
	    printw("|Net Worth                 |");
E 18
I 18
	    printw("|Net Worth                         |");
E 18
I 17
	    move(tboxrow + 11, boxcol);
D 18
	    printw("|Return                    |");
E 18
I 18
	    printw("|Return                            |");
E 18
E 17
	    move(tboxrow + 12, boxcol);
D 18
	    printw("|==========================|");
E 18
I 18
	    printw("|==================================|");
E 18
}

/*
 * clear info above move box
 */
clearabovemovebox()
{
E 4
	int i;

	for (i = 0; i <= 11; i++) {
		move(tboxrow + i, boxcol);
D 18
		printw("                            ");
E 18
I 18
		printw("                                    ");
E 18
	}
	move(tboxrow + 12, boxcol);
D 18
	printw("*--------------------------*");
E 18
I 18
	printw("*----------------------------------*");
E 18
}

/*
 * print instructions below move box
 */
printbottominstructions()
{
E 2
	    move(bboxrow, boxcol);
D 2
	    printw("|Replace the # with the    |");
E 2
I 2
D 18
	    printw("|Replace # with the number |");
E 18
I 18
	    printw("|Replace # with the number of the  |");
E 18
E 2
	    move(bboxrow + 1, boxcol);
D 2
	    printw("|number of the tableau you |");
E 2
I 2
D 18
	    printw("|of the tableau you want.  |");
E 18
I 18
	    printw("|tableau you want.                 |");
E 18
E 2
	    move(bboxrow + 2, boxcol);
D 2
	    printw("|want, 1, 2, 3, or 4.      |");
	    move(bboxrow + 3, boxcol);
E 2
D 18
	    printw("*--------------------------*");
E 18
I 18
	    printw("*----------------------------------*");
E 18
D 2
	    refresh();
E 2
}

D 2
/* procedure to put the board on the screen using addressable cursor */
E 2
I 2
/*
D 4
 * clear directions below move box
E 4
I 4
 * print betting information below move box
E 4
 */
D 4
clearbottominstructions()
E 4
I 4
printbottombettingbox()
E 4
{
I 4
	    move(bboxrow, boxcol);
D 18
	    printw("|x = toggle information box|");
E 18
I 18
	    printw("|x = toggle information box        |");
E 18
	    move(bboxrow + 1, boxcol);
D 18
	    printw("|i = list instructions     |");
E 18
I 18
	    printw("|i = list playing instructions     |");
E 18
	    move(bboxrow + 2, boxcol);
D 18
	    printw("*--------------------------*");
E 18
I 18
	    printw("*----------------------------------*");
E 18
}

/*
 * clear info below move box
 */
clearbelowmovebox()
{
E 4
	int i;

	move(bboxrow, boxcol);
D 18
	printw("*--------------------------*");
E 18
I 18
	printw("*----------------------------------*");
E 18
	for (i = 1; i <= 2; i++) {
		move(bboxrow + i, boxcol);
D 18
		printw("                            ");
E 18
I 18
		printw("                                    ");
E 18
	}
}

/*
 * procedure to put the board on the screen using addressable cursor
 */
E 2
makeboard()
{
	clear();
	refresh();
	move(titlerow, titlecol);
	printw("=-> CANFIELD <-=");
	move(fttlrow, fttlcol);
	printw("foundation");
	move(foundrow - 1, fttlcol);
	printw("=---=  =---=  =---=  =---=");
	move(foundrow, fttlcol);
	printw("|   |  |   |  |   |  |   |");
	move(foundrow + 1, fttlcol);
	printw("=---=  =---=  =---=  =---=");
	move(ottlrow, sidecol);
	printw("stock     tableau");
	move(stockrow - 1, sidecol);
	printw("=---=");
	move(stockrow, sidecol);
	printw("|   |");
	move(stockrow + 1, sidecol);
	printw("=---=");
	move(talonrow - 2, sidecol);
	printw("talon");
	move(talonrow - 1, sidecol);
	printw("=---=");
	move(talonrow, sidecol);
	printw("|   |");
	move(talonrow + 1, sidecol);
	printw("=---=");
	move(tabrow - 1, atabcol);
	printw("-1-    -2-    -3-    -4-");
	movebox();
}
D 6
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
E 6

D 6
/* clean up the board for another game */
E 6
I 6
/*
 * clean up the board for another game
 */
E 6
cleanupboard()
{
	int cnt, row, col;
	struct cardtype *ptr;

	if (Cflag) {
		clearstat();
		for(ptr = stock, row = stockrow;
		    ptr != NIL;
		    ptr = ptr->next, row++) {
			move(row, sidecol);
			printw("     ");
		}
		move(row, sidecol);
		printw("     ");
		move(stockrow + 1, sidecol);
		printw("=---=");
		move(talonrow - 2, sidecol);
		printw("talon");
		move(talonrow - 1, sidecol);
		printw("=---=");
		move(talonrow + 1, sidecol);
		printw("=---=");
	}
	move(stockrow, sidecol);
	printw("|   |");
	move(talonrow, sidecol);
	printw("|   |");
	move(foundrow, fttlcol);
	printw("|   |  |   |  |   |  |   |");
	for (cnt = 0; cnt < 4; cnt++) {
		switch(cnt) {
		case 0:
			col = atabcol;
			break;
		case 1:
			col = btabcol;
			break;
		case 2:
			col = ctabcol;
			break;
		case 3:
			col = dtabcol;
			break;
		}
		for(ptr = tableau[cnt], row = tabrow;
		    ptr != NIL;
		    ptr = ptr->next, row++)
			removecard(col, row);
	}
}

D 6
/* procedure to create a deck of cards */
E 6
I 6
/*
 * procedure to create a deck of cards
 */
E 6
initdeck(deck)
D 6
struct cardtype *deck[];
E 6
I 6
	struct cardtype *deck[];
E 6
{
	int i;
	int scnt;
	char s;
	int r;

	i = 0;
	for (scnt=0; scnt<4; scnt++) {
		s = suitmap[scnt];
		for (r=Ace; r<=King; r++) {
			deck[i] = &cards[i];
			cards[i].rank = r;
			cards[i].suit = s;
			cards[i].color = colormap[scnt];
			cards[i].next = NIL;
			i++;
		}
	}
}

D 6
/* procedure to shuffle the deck */
E 6
I 6
/*
 * procedure to shuffle the deck
 */
E 6
shuffle(deck)
D 6
struct cardtype *deck[];
E 6
I 6
	struct cardtype *deck[];
E 6
{
	int i,j;
	struct cardtype *temp;

D 4
	for (i=0; i<decksize; i++)
E 4
I 4
	for (i=0; i<decksize; i++) {
E 4
		deck[i]->visible = FALSE;
I 4
		deck[i]->paid = FALSE;
	}
E 4
	for (i = decksize-1; i>=0; i--) {
D 4
		j = rand() % decksize;
E 4
I 4
		j = random() % decksize;
E 4
		if (i != j) {
			temp = deck[i];
			deck[i] = deck[j];
			deck[j] = temp;
		}
	}
}

D 6
/* procedure to remove the card from the board */
E 6
I 6
/*
 * procedure to remove the card from the board
 */
E 6
removecard(a, b)
{
	move(b, a);
	printw("   ");
}

D 6
/* procedure to print the cards on the board */
E 6
I 6
/*
 * procedure to print the cards on the board
 */
E 6
D 3
printrank(a, b, cp)
E 3
I 3
printrank(a, b, cp, inverse)
E 3
D 6
struct cardtype *cp;
I 3
bool inverse;
E 6
I 6
	struct cardtype *cp;
	bool inverse;
E 6
E 3
{
	move(b, a);
I 3
	if (cp->rank != 10)
		addch(' ');
	if (inverse)
		standout();
E 3
	switch (cp->rank) {
		case 2: case 3: case 4: case 5: case 6: case 7:
		case 8: case 9: case 10:
D 3
			printw("%2d", cp->rank);
E 3
I 3
			printw("%d", cp->rank);
E 3
			break;
		case Ace:
D 3
			printw(" A");
E 3
I 3
			addch('A');
E 3
			break;
		case Jack:
D 3
			printw(" J");
E 3
I 3
			addch('J');
E 3
			break;
		case Queen:
D 3
			printw(" Q");
E 3
I 3
			addch('Q');
E 3
			break;
		case King:
D 3
			printw(" K");
E 3
I 3
			addch('K');
E 3
	}
I 3
	if (inverse)
		standend();
E 3
}

I 6
/*
 * procedure to print out a card
 */
E 6
printcard(a, b, cp)
D 6
int a,b;
struct cardtype *cp;
E 6
I 6
	int a,b;
	struct cardtype *cp;
E 6
{
	if (cp == NIL)
		removecard(a, b);
	else if (cp->visible == FALSE) {
		move(b, a);
		printw(" ? ");
	} else {
D 3
		printrank(a, b, cp);
E 3
I 3
		bool inverse = (cp->suit == 'd' || cp->suit == 'h');

		printrank(a, b, cp, inverse);
		if (inverse)
			standout();
E 3
		addch(cp->suit);
I 3
		if (inverse)
			standend();
E 3
	}
}

/*
 * procedure to move the top card from one location to the top 
 * of another location. The pointers always point to the top
 * of the piles.
 */
transit(source, dest)
D 6
struct cardtype **source, **dest;
E 6
I 6
	struct cardtype **source, **dest;
E 6
{
	struct cardtype *temp;
	
	temp = *source;
	*source = (*source)->next;
	temp->next = *dest;
	*dest = temp;
}

/*
 * Procedure to set the cards on the foundation base when available.
 * Note that it is only called on a foundation pile at the beginning of
 * the game, so the pile will have exactly one card in it.
 */
D 6

E 6
fndbase(cp, column, row)
D 6
struct cardtype **cp;
E 6
I 6
	struct cardtype **cp;
E 6
{
	bool nomore;

	if (*cp != NIL)
		do {
			if ((*cp)->rank == basecard->rank) {
				base++;
				printcard(pilemap[base], foundrow, *cp);
				if (*cp == tableau[0])
					length[0] = length[0] - 1;
				if (*cp == tableau[1])
					length[1] = length[1] - 1;
				if (*cp == tableau[2])
					length[2] = length[2] - 1;
				if (*cp == tableau[3])
					length[3] = length[3] - 1;
				transit(cp, &found[base]);
				if (cp == &talon)
					usedtalon();
				if (cp == &stock)
					usedstock();
				if (*cp != NIL) {
					printcard(column, row, *cp);
					nomore = FALSE;
				} else {
					removecard(column, row);
					nomore = TRUE;
				}
				cardsoff++;
I 4
				if (infullgame) {
					this.wins += valuepercardup;
I 18
					game.wins += valuepercardup;
E 18
					total.wins += valuepercardup;
				}
E 4
			} else 
				nomore = TRUE;
	} while (nomore == FALSE);
}

D 4
/* procedure to initialize the things necessary for the game */
E 4
I 4
/*
 * procedure to initialize the things necessary for the game
 */
E 4
initgame()
{
	register i;

D 4
	for (i=0; i<18; i++)
E 4
I 4
	for (i=0; i<18; i++) {
E 4
		deck[i]->visible = TRUE;
I 4
		deck[i]->paid = TRUE;
	}
E 4
	stockcnt = 13;
	stock = deck[12];
	for (i=12; i>=1; i--)
		deck[i]->next = deck[i - 1];
	deck[0]->next = NIL;
	found[0] = deck[13];
	deck[13]->next = NIL;
	for (i=1; i<4; i++)
		found[i] = NIL;
	basecard = found[0];
	for (i=14; i<18; i++) {
		tableau[i - 14] = deck[i];
		deck[i]->next = NIL;
	}
	for (i=0; i<4; i++) {
		bottom[i] = tableau[i];
		length[i] = tabrow;
	}
	hand = deck[18];
	for (i=18; i<decksize-1; i++)
		deck[i]->next = deck[i + 1];
	deck[decksize-1]->next = NIL;
	talon = NIL;
	base = 0;
	cinhand = 34;
	taloncnt = 0;
	timesthru = 0;
	cardsoff = 1;
	coldrow = ctoprow;
	coldcol = cinitcol;
	cnewrow = ctoprow;
	cnewcol = cinitcol + cwidthcol;
}

D 6
/* procedure to print the beginning cards and to start each game */
E 6
I 6
/*
 * procedure to print the beginning cards and to start each game
 */
E 6
startgame()
{
	register int j;

	shuffle(deck);
	initgame();
I 4
	this.hand = costofhand;
I 18
	game.hand += costofhand;
E 18
	total.hand += costofhand;
	this.inspection = 0;
	this.game = 0;
	this.runs = 0;
	this.information = 0;
	this.wins = 0;
I 6
	this.thinktime = 0;
E 6
	infullgame = FALSE;
	startedgame = FALSE;
E 4
	printcard(foundcol, foundrow, found[0]);
	printcard(stockcol, stockrow, stock);
	printcard(atabcol, tabrow, tableau[0]);
	printcard(btabcol, tabrow, tableau[1]);
	printcard(ctabcol, tabrow, tableau[2]);
	printcard(dtabcol, tabrow, tableau[3]);
	printcard(taloncol, talonrow, talon);
	move(foundrow - 2, basecol);
	printw("Base");
	move(foundrow - 1, basecol);
	printw("Rank");
D 3
	printrank(basecol, foundrow, found[0]);
E 3
I 3
	printrank(basecol, foundrow, found[0], 0);
E 3
	for (j=0; j<=3; j++)
		fndbase(&tableau[j], pilemap[j], tabrow);
	fndbase(&stock, stockcol, stockrow);
	showstat();	/* show card counting info to cheaters */
I 4
	movetotalon();
	updatebettinginfo();
E 4
}

D 6

/* procedure to clear the message printed from an error */
E 6
I 6
/*
 * procedure to clear the message printed from an error
 */
E 6
clearmsg()
{
	int i;

	if (errmsg == TRUE) {
		errmsg = FALSE;
		move(msgrow, msgcol);
		for (i=0; i<25; i++)
			addch(' ');
		refresh();
	}
}

D 6
/* procedure to print an error message if the move is not listed */
E 6
I 6
/*
 * procedure to print an error message if the move is not listed
 */
E 6
dumberror()
{
	errmsg = TRUE;
	move(msgrow, msgcol);
	printw("Not a proper move       ");
}

D 6
/* procedure to print an error message if the move is not possible */
E 6
I 6
/*
 * procedure to print an error message if the move is not possible
 */
E 6
destinerror()
{
	errmsg = TRUE;
	move(msgrow, msgcol);
	printw("Error: Can't move there");
}

D 6
/* function to see if the source has cards in it */
E 6
I 6
/*
 * function to see if the source has cards in it
 */
E 6
bool
notempty(cp)
struct cardtype *cp;
{
	if (cp == NIL) {
		errmsg = TRUE;
		move(msgrow, msgcol);
		printw("Error: no cards to move");
		return (FALSE);
	} else 
		return (TRUE);
}

D 6

/* function to see if the rank of one card is less than another */

E 6
I 6
/*
 * function to see if the rank of one card is less than another
 */
E 6
bool
ranklower(cp1, cp2)
D 6
struct cardtype *cp1, *cp2;
E 6
I 6
	struct cardtype *cp1, *cp2;
E 6
{
	if (cp2->rank == Ace) 
		if (cp1->rank == King)
			return (TRUE);
		else 
			return (FALSE);
	else if (cp1->rank + 1 == cp2->rank)
		return (TRUE);
	else 
		return (FALSE);
}

D 6
/* function to check the cardcolor for moving to a tableau */
E 6
I 6
/*
 * function to check the cardcolor for moving to a tableau
 */
E 6
bool
diffcolor(cp1, cp2)
D 6
struct cardtype *cp1, *cp2;
E 6
I 6
	struct cardtype *cp1, *cp2;
E 6
{
	if (cp1->color == cp2->color)
		return (FALSE);
	else 
		return (TRUE);
}

D 6
/* function to see if the card can move to the tableau */
E 6
I 6
/*
 * function to see if the card can move to the tableau
 */
E 6
bool
tabok(cp, des)
D 6
struct cardtype *cp;
E 6
I 6
	struct cardtype *cp;
E 6
{
	if ((cp == stock) && (tableau[des] == NIL))
		return (TRUE);
	else if (tableau[des] == NIL)
D 16
		if (stock == NIL)
E 16
I 16
		if (stock == NIL && 
		    cp != bottom[0] && cp != bottom[1] && 
		    cp != bottom[2] && cp != bottom[3])
E 16
			return (TRUE);
		else 
			return (FALSE);
	else if (ranklower(cp, tableau[des]) && diffcolor(cp, tableau[des]))
		return (TRUE);
	else 
		return (FALSE);
}

D 4

/* procedure to turn the cards onto the talon from the deck */
E 4
I 4
/*
 * procedure to turn the cards onto the talon from the deck
 */
E 4
movetotalon()
{
	int i, fin;

I 15
	if (cinhand <= 3 && cinhand > 0) {
		move(msgrow, msgcol);
		printw("Hand is now empty        ");
	}
E 15
	if (cinhand >= 3)
		fin = 3;
	else if (cinhand > 0)
		fin = cinhand;
	else if (talon != NIL) {
		timesthru++;
		errmsg = TRUE;
		move(msgrow, msgcol);
		if (timesthru != 4) {
			printw("Talon is now the new hand");
I 4
			this.runs += costofrunthroughhand;
I 18
			game.runs += costofrunthroughhand;
E 18
			total.runs += costofrunthroughhand;
E 4
			while (talon != NIL) {
				transit(&talon, &hand);
				cinhand++;
			}
			if (cinhand >= 3)
				fin = 3;
			else
				fin = cinhand;
			taloncnt = 0;
			coldrow = ctoprow;
			coldcol = cinitcol;
			cnewrow = ctoprow;
			cnewcol = cinitcol + cwidthcol;
			clearstat();
			showstat();
		} else {
			fin = 0;
			done = TRUE;
			printw("I believe you have lost");
			refresh();
			sleep(5);
		}
	} else {
		errmsg = TRUE;
		move(msgrow, msgcol);
		printw("Talon and hand are empty");
		fin = 0;
	}
	for (i=0; i<fin; i++) {
		transit(&hand, &talon);
		INCRHAND(cnewrow, cnewcol);
		INCRHAND(coldrow, coldcol);
		removecard(cnewcol, cnewrow);
		if (i == fin - 1)
			talon->visible = TRUE;
D 4
		if (Cflag)
E 4
I 4
		if (Cflag) {
			if (talon->paid == FALSE && talon->visible == TRUE) {
				this.information += costofinformation;
I 18
				game.information += costofinformation;
E 18
				total.information += costofinformation;
				talon->paid = TRUE;
			}
E 4
			printcard(coldcol, coldrow, talon);
I 4
		}
E 4
	}
	if (fin != 0) {
		printcard(taloncol, talonrow, talon);
		cinhand -= fin;
		taloncnt += fin;
		if (Cflag) {
			move(handstatrow, handstatcol);
			printw("%3d", cinhand);
			move(talonstatrow, talonstatcol);
			printw("%3d", taloncnt);
		}
		fndbase(&talon, taloncol, talonrow);
	}
}


D 4
/* procedure to print card counting info on screen */
E 4
I 4
/*
 * procedure to print card counting info on screen
 */
E 4
showstat()
{
	int row, col;
	register struct cardtype *ptr;

D 4
	if (Cflag) {
		move(talonstatrow, talonstatcol - 7);
		printw("Talon: %3d", taloncnt);
		move(handstatrow, handstatcol - 7);
		printw("Hand:  %3d", cinhand);
		move(stockstatrow, stockstatcol - 7);
		printw("Stock: %3d", stockcnt);
		for ( row = coldrow, col = coldcol, ptr = talon;
		      ptr != NIL;
		      ptr = ptr->next ) {
			printcard(col, row, ptr);
			DECRHAND(row, col);
E 4
I 4
	if (!Cflag)
		return;
	move(talonstatrow, talonstatcol - 7);
	printw("Talon: %3d", taloncnt);
	move(handstatrow, handstatcol - 7);
	printw("Hand:  %3d", cinhand);
	move(stockstatrow, stockstatcol - 7);
	printw("Stock: %3d", stockcnt);
	for ( row = coldrow, col = coldcol, ptr = talon;
	      ptr != NIL;
	      ptr = ptr->next ) {
		if (ptr->paid == FALSE && ptr->visible == TRUE) {
			ptr->paid = TRUE;
			this.information += costofinformation;
I 18
			game.information += costofinformation;
E 18
			total.information += costofinformation;
E 4
		}
D 4
		for ( row = cnewrow, col = cnewcol, ptr = hand;
		      ptr != NIL;
		      ptr = ptr->next ) {
			INCRHAND(row, col);
			printcard(col, row, ptr);
E 4
I 4
		printcard(col, row, ptr);
		DECRHAND(row, col);
	}
	for ( row = cnewrow, col = cnewcol, ptr = hand;
	      ptr != NIL;
	      ptr = ptr->next ) {
		if (ptr->paid == FALSE && ptr->visible == TRUE) {
			ptr->paid = TRUE;
			this.information += costofinformation;
I 18
			game.information += costofinformation;
E 18
			total.information += costofinformation;
E 4
		}
I 4
		INCRHAND(row, col);
		printcard(col, row, ptr);
E 4
	}
}

D 4

/* procedure to clear card counting info from screen */
E 4
I 4
/*
 * procedure to clear card counting info from screen
 */
E 4
clearstat()
{
	int row;

	move(talonstatrow, talonstatcol - 7);
	printw("          ");
	move(handstatrow, handstatcol - 7);
	printw("          ");
	move(stockstatrow, stockstatcol - 7);
	printw("          ");
	for ( row = ctoprow ; row <= cbotrow ; row++ ) {
		move(row, cinitcol);
		printw("%56s", " ");
	}
}

D 6

E 6
D 4
/* procedure to update card counting base */
E 4
I 4
/*
 * procedure to update card counting base
 */
E 4
usedtalon()
{
	removecard(coldcol, coldrow);
	DECRHAND(coldrow, coldcol);
	if (talon != NIL && (talon->visible == FALSE)) {
		talon->visible = TRUE;
D 4
		if (Cflag)
E 4
I 4
		if (Cflag) {
			this.information += costofinformation;
I 18
			game.information += costofinformation;
E 18
			total.information += costofinformation;
			talon->paid = TRUE;
E 4
			printcard(coldcol, coldrow, talon);
I 4
		}
E 4
	}
	taloncnt--;
	if (Cflag) {
		move(talonstatrow, talonstatcol);
		printw("%3d", taloncnt);
	}
}

D 6

E 6
D 4
/* procedure to update stock card counting base */
E 4
I 4
/*
 * procedure to update stock card counting base
 */
E 4
usedstock()
{
	stockcnt--;
	if (Cflag) {
		move(stockstatrow, stockstatcol);
		printw("%3d", stockcnt);
	}
}

D 4

/* let 'em know how they lost! */
E 4
I 4
/*
 * let 'em know how they lost!
 */
E 4
showcards()
{
	register struct cardtype *ptr;
	int row;

D 14
	if (!Cflag)
E 14
I 14
	if (!Cflag || cardsoff == 52)
E 14
		return;
D 4
	for (ptr = talon; ptr != NIL; ptr = ptr->next)
E 4
I 4
	for (ptr = talon; ptr != NIL; ptr = ptr->next) {
E 4
		ptr->visible = TRUE;
D 4
	for (ptr = hand; ptr != NIL; ptr = ptr->next)
E 4
I 4
		ptr->paid = TRUE;
	}
	for (ptr = hand; ptr != NIL; ptr = ptr->next) {
E 4
		ptr->visible = TRUE;
I 4
		ptr->paid = TRUE;
	}
E 4
	showstat();
	move(stockrow + 1, sidecol);
	printw("     ");
	move(talonrow - 2, sidecol);
	printw("     ");
	move(talonrow - 1, sidecol);
	printw("     ");
	move(talonrow, sidecol);
	printw("     ");
	move(talonrow + 1, sidecol);
	printw("     ");
	for (ptr = stock, row = stockrow; ptr != NIL; ptr = ptr->next, row++) {
		move(row, stockcol - 1);
		printw("|   |");
		printcard(stockcol, row, ptr);
	}
	if (stock == NIL) {
		move(row, stockcol - 1);
		printw("|   |");
		row++;
	}
	move(handstatrow, handstatcol - 7);
	printw("          ");
	move(row, stockcol - 1);
	printw("=---=");
D 16
	getcmd(moverow, movecol, "Hit return to exit");
E 16
I 16
	if ( cardsoff == 52 )
		getcmd(moverow, movecol, "Hit return to exit");
E 16
}

I 4
/*
 * procedure to update the betting values
 */
updatebettinginfo()
{
D 5
	this.costs = this.hand + this.inspection +
		this.game + this.runs + this.information;
	total.costs = total.hand + total.inspection +
		total.game + total.runs + total.information;
	this.worth = this.wins - this.costs;
	total.worth = total.wins - total.costs;
E 5
I 5
D 18
	long thiscosts, totalcosts;
I 17
	double thisreturn, totalreturn;
E 18
I 18
	long thiscosts, gamecosts, totalcosts;
	double thisreturn, gamereturn, totalreturn;
E 18
E 17
	time_t now;
	register long dollars;

D 8
	thiscosts = this.hand + this.inspection + this.game +
		this.runs + this.information + this.thinktime;
	totalcosts = total.hand + total.inspection + total.game +
		total.runs + total.information + total.thinktime;
	this.worth = this.wins - thiscosts;
	total.worth = total.wins - totalcosts;
E 8
	time(&now);
	dollars = (now - acctstart) / secondsperdollar;
	if (dollars > 0) {
I 14
		acctstart += dollars * secondsperdollar;
		if (dollars > maxtimecharge)
			dollars = maxtimecharge;
E 14
		this.thinktime += dollars;
I 18
		game.thinktime += dollars;
E 18
		total.thinktime += dollars;
D 14
		acctstart += dollars * secondsperdollar;
E 14
	}
I 8
	thiscosts = this.hand + this.inspection + this.game +
		this.runs + this.information + this.thinktime;
I 18
	gamecosts = game.hand + game.inspection + game.game +
		game.runs + game.information + game.thinktime;
E 18
	totalcosts = total.hand + total.inspection + total.game +
		total.runs + total.information + total.thinktime;
	this.worth = this.wins - thiscosts;
I 18
	game.worth = game.wins - gamecosts;
E 18
	total.worth = total.wins - totalcosts;
I 17
	thisreturn = ((double)this.wins / (double)thiscosts - 1.0) * 100.0;
I 18
	gamereturn = ((double)game.wins / (double)gamecosts - 1.0) * 100.0;
E 18
	totalreturn = ((double)total.wins / (double)totalcosts - 1.0) * 100.0;
E 17
E 8
E 5
	if (status != BETTINGBOX)
		return;
D 5
	move(tboxrow + 4, boxcol + 13);
E 5
I 5
D 17
	move(tboxrow + 3, boxcol + 13);
E 17
I 17
	move(tboxrow + 2, boxcol + 13);
E 17
E 5
D 18
	printw("%4d%9d", this.hand, total.hand);
E 18
I 18
	printw("%4d%8d%9d", this.hand, game.hand, total.hand);
E 18
D 5
	move(tboxrow + 5, boxcol + 13);
E 5
I 5
D 17
	move(tboxrow + 4, boxcol + 13);
E 17
I 17
	move(tboxrow + 3, boxcol + 13);
E 17
E 5
D 18
	printw("%4d%9d", this.inspection, total.inspection);
E 18
I 18
	printw("%4d%8d%9d", this.inspection, game.inspection, total.inspection);
E 18
D 5
	move(tboxrow + 6, boxcol + 13);
E 5
I 5
D 17
	move(tboxrow + 5, boxcol + 13);
E 17
I 17
	move(tboxrow + 4, boxcol + 13);
E 17
E 5
D 18
	printw("%4d%9d", this.game, total.game);
E 18
I 18
	printw("%4d%8d%9d", this.game, game.game, total.game);
E 18
D 5
	move(tboxrow + 7, boxcol + 13);
E 5
I 5
D 17
	move(tboxrow + 6, boxcol + 13);
E 17
I 17
	move(tboxrow + 5, boxcol + 13);
E 17
E 5
D 18
	printw("%4d%9d", this.runs, total.runs);
E 18
I 18
	printw("%4d%8d%9d", this.runs, game.runs, total.runs);
E 18
D 5
	move(tboxrow + 8, boxcol + 13);
E 5
I 5
D 17
	move(tboxrow + 7, boxcol + 13);
E 17
I 17
	move(tboxrow + 6, boxcol + 13);
E 17
E 5
D 18
	printw("%4d%9d", this.information, total.information);
E 18
I 18
	printw("%4d%8d%9d", this.information, game.information,
		total.information);
E 18
I 5
D 17
	move(tboxrow + 8, boxcol + 13);
E 17
I 17
	move(tboxrow + 7, boxcol + 13);
E 17
D 18
	printw("%4d%9d", this.thinktime, total.thinktime);
E 18
I 18
	printw("%4d%8d%9d", this.thinktime, game.thinktime, total.thinktime);
E 18
E 5
D 17
	move(tboxrow + 9, boxcol + 13);
E 17
I 17
	move(tboxrow + 8, boxcol + 13);
E 17
D 5
	printw("%4d%9d", this.costs, total.costs);
E 5
I 5
D 18
	printw("%4d%9d", thiscosts, totalcosts);
E 18
I 18
	printw("%4d%8d%9d", thiscosts, gamecosts, totalcosts);
E 18
E 5
D 17
	move(tboxrow + 10, boxcol + 13);
E 17
I 17
	move(tboxrow + 9, boxcol + 13);
E 17
D 18
	printw("%4d%9d", this.wins, total.wins);
E 18
I 18
	printw("%4d%8d%9d", this.wins, game.wins, total.wins);
E 18
D 17
	move(tboxrow + 11, boxcol + 13);
E 17
I 17
	move(tboxrow + 10, boxcol + 13);
E 17
D 18
	printw("%4d%9d", this.worth, total.worth);
E 18
I 18
	printw("%4d%8d%9d", this.worth, game.worth, total.worth);
E 18
I 17
	move(tboxrow + 11, boxcol + 13);
D 18
	printw("%4.0f%%%8.1f%%", thisreturn, totalreturn);
E 18
I 18
	printw("%4.0f%%%7.1f%%%8.1f%%", thisreturn, gamereturn, totalreturn);
E 18
E 17
}
E 4

D 4
/* procedure to move a card from the stock or talon to the tableau */
E 4
I 4
/*
 * procedure to move a card from the stock or talon to the tableau
 */
E 4
simpletableau(cp, des)
struct cardtype **cp;
{
	int origin;

	if (notempty(*cp)) {
		if (tabok(*cp, des)) {
			if (*cp == stock)
				origin = stk;
			else
				origin = tal;
			if (tableau[des] == NIL)
				bottom[des] = *cp;
			transit(cp, &tableau[des]);
			length[des]++;
			printcard(pilemap[des], length[des], tableau[des]);
			timesthru = 0;
			if (origin == stk) {
				usedstock();
				printcard(stockcol, stockrow, stock);
			} else {
				usedtalon();
				printcard(taloncol, talonrow, talon);
			}
		} else 
			destinerror();
	}
}

D 6

E 6
I 6
/*
 * print the tableau
 */
E 6
tabprint(sour, des)
{
	int dlength, slength, i;
	struct cardtype *tempcard;

	for (i=tabrow; i<=length[sour]; i++)
		removecard(pilemap[sour], i);
	dlength = length[des] + 1;
	slength = length[sour];
	if (slength == tabrow)
		printcard(pilemap[des], dlength, tableau[sour]);
	else 
		while (slength != tabrow - 1) {
			tempcard = tableau[sour];
			for (i=1; i<=slength-tabrow; i++)
			    tempcard = tempcard->next;
			printcard(pilemap[des], dlength, tempcard);
			slength--;
			dlength++;
		}
}

D 6
/* procedure to move from the tableau to the tableau */
E 6
I 6
/*
 * procedure to move from the tableau to the tableau
 */
E 6
tabtotab(sour, des)
I 11
	register int sour, des;
E 11
{
	struct cardtype *temp;

	if (notempty(tableau[sour])) {
		if (tabok(bottom[sour], des)) {
			tabprint(sour, des);
			temp = bottom[sour];
			bottom[sour] = NIL;
I 11
			if (bottom[des] == NIL)
				bottom[des] = temp;
E 11
			temp->next = tableau[des];
			tableau[des] = tableau[sour];
			tableau[sour] = NIL;
			length[des] = length[des] + (length[sour] - (tabrow - 1));
			length[sour] = tabrow - 1;
			timesthru = 0;
		} else 
			destinerror();
	}
}

D 6

/* functions to see if the card can go onto the foundation */
E 6
I 6
/*
 * functions to see if the card can go onto the foundation
 */
E 6
bool
rankhigher(cp, let)
D 6
struct cardtype *cp;
E 6
I 6
	struct cardtype *cp;
E 6
{
	if (found[let]->rank == King)
		if (cp->rank == Ace)
			return(TRUE);
		else 
			return(FALSE);
	else if (cp->rank - 1 == found[let]->rank)
		return(TRUE);
	else 
		return(FALSE);
}

I 6
/*
 * function to determine if two cards are the same suit
 */
E 6
samesuit(cp, let)
D 6
struct cardtype *cp;
E 6
I 6
	struct cardtype *cp;
E 6
{
	if (cp->suit == found[let]->suit)
		return (TRUE);
	else 
		return (FALSE);
}

D 6
/* procedure to move a card to the correct foundation pile */

E 6
I 6
/*
 * procedure to move a card to the correct foundation pile
 */
E 6
movetofound(cp, source)
D 6
struct cardtype **cp;
E 6
I 6
	struct cardtype **cp;
E 6
{
	tempbase = 0;
	mtfdone = FALSE;
	if (notempty(*cp)) {
		do {
			if (found[tempbase] != NIL)
				if (rankhigher(*cp, tempbase)
				    && samesuit(*cp, tempbase)) {
					if (*cp == stock)
						mtforigin = stk;
					else if (*cp == talon)
						mtforigin = tal;
					else
						mtforigin = tab;
					transit(cp, &found[tempbase]);
					printcard(pilemap[tempbase],
						foundrow, found[tempbase]);
					timesthru = 0;
					if (mtforigin == stk) {
						usedstock();
						printcard(stockcol, stockrow, stock);
					} else if (mtforigin == tal) {
						usedtalon();
						printcard(taloncol, talonrow, talon);
					} else {
						removecard(pilemap[source], length[source]);
						length[source]--;
					}
					cardsoff++;
I 4
					if (infullgame) {
						this.wins += valuepercardup;
I 18
						game.wins += valuepercardup;
E 18
						total.wins += valuepercardup;
					}
E 4
					mtfdone = TRUE;
				} else
					tempbase++;
			else 
				tempbase++;
		} while ((tempbase != 4) && !mtfdone);
		if (!mtfdone)
			destinerror();
	}
}

D 6

/* procedure to get a command */

E 6
I 6
/*
 * procedure to get a command
 */
E 6
getcmd(row, col, cp)
	int row, col;
	char *cp;
{
	char cmd[2], ch;
	int i;

	i = 0;
	move(row, col);
	printw("%-24s", cp);
	col += 1 + strlen(cp);
	move(row, col);
	refresh();
	do {
		ch = getch() & 0177;
		if (ch >= 'A' && ch <= 'Z')
			ch += ('a' - 'A');
		if (ch == '\f') {
			wrefresh(curscr);
			refresh();
		} else if (i >= 2 && ch != _tty.sg_erase && ch != _tty.sg_kill) {
			if (ch != '\n' && ch != '\r' && ch != ' ')
				write(1, "\007", 1);
		} else if (ch == _tty.sg_erase && i > 0) {
			printw("\b \b");
			refresh();
			i--;
		} else if (ch == _tty.sg_kill && i > 0) {
			while (i > 0) {
				printw("\b \b");
				i--;
			}
			refresh();
		} else if (ch == '\032') {	/* Control-Z */
			suspend();
			move(row, col + i);
			refresh();
		} else if (isprint(ch)) {
			cmd[i++] = ch;
			addch(ch);
			refresh();
		}
	} while (ch != '\n' && ch != '\r' && ch != ' ');
	srcpile = cmd[0];
	destpile = cmd[1];
}

D 6
/* Suspend the game (shell escape if no process control on system) */

E 6
I 6
/*
 * Suspend the game (shell escape if no process control on system)
 */
E 6
suspend()
{
#ifndef SIGTSTP
	char *sh;
#endif

I 17
	updatebettinginfo();
E 17
	move(21, 0);
	refresh();
I 17
	if (dbfd != -1) {
		lseek(dbfd, uid * sizeof(struct betinfo), 0);
		write(dbfd, (char *)&total, sizeof(total));
	}
E 17
D 10
	endwin();
	fflush(stdout);
E 10
#ifdef SIGTSTP
	kill(getpid(), SIGTSTP);
#else
	sh = getenv("SHELL");
	if (sh == NULL)
		sh = "/bin/sh";
	system(sh);
#endif
	raw();
	noecho();
I 9
D 10
	wrefresh(curscr);
E 10
E 9
}

D 6
/* procedure to evaluate and make the specific moves */

E 6
I 6
/*
 * procedure to evaluate and make the specific moves
 */
E 6
movecard()
{
	int source, dest;
I 4
	char osrcpile, odestpile;
E 4

	done = FALSE;
	errmsg = FALSE;
	do {
I 4
		if (talon == NIL && hand != NIL)
			movetotalon();
E 4
		if (cardsoff == 52) {
			refresh();
			srcpile = 'q';
I 17
		} else if (!startedgame) {
			move(msgrow, msgcol);
			errmsg = TRUE;
			switch (34 - taloncnt - cinhand) {
			default:
				errmsg = FALSE;
				break;
			case 1:
				printw("One card used from talon  ");
				break;
			case 2:
				printw("Two cards used from talon ");
				break;
			case 3:
				printw(">3< cards used from talon ");
				break;
			}
			getcmd(moverow, movecol, "Move:");
E 17
		} else
			getcmd(moverow, movecol, "Move:");
		clearmsg();
		if (srcpile >= '1' && srcpile <= '4')
			source = (int) (srcpile - '1');
		if (destpile >= '1' && destpile <= '4')
			dest = (int) (destpile - '1');
I 4
		if (!startedgame &&
		    (srcpile == 't' || srcpile == 's' || srcpile == 'h' ||
		     srcpile == '1' || srcpile == '2' || srcpile == '3' ||
		     srcpile == '4')) {
			startedgame = TRUE;
			osrcpile = srcpile;
			odestpile = destpile;
			if (status != BETTINGBOX)
				srcpile = 'y';
			else do {
				getcmd(moverow, movecol, "Inspect game?");
			} while (srcpile != 'y' && srcpile != 'n');
			if (srcpile == 'n') {
				srcpile = 'q';
			} else {
				this.inspection += costofinspection;
I 18
				game.inspection += costofinspection;
E 18
				total.inspection += costofinspection;
				srcpile = osrcpile;
				destpile = odestpile;
			}
		}
E 4
		switch (srcpile) {
			case 't':
				if (destpile == 'f' || destpile == 'F')
					movetofound(&talon, source);
				else if (destpile >= '1' && destpile <= '4')
					simpletableau(&talon, dest);
				else
					dumberror();
				break;
			case 's':
				if (destpile == 'f' || destpile == 'F')
					movetofound(&stock, source);
				else if (destpile >= '1' && destpile <= '4')
					simpletableau(&stock, dest);
				else dumberror();
				break;
			case 'h':
D 4
				if (destpile == 't' || destpile == 'T')
E 4
I 4
				if (destpile != 't' && destpile != 'T') {
					dumberror();
					break;
				}
				if (infullgame) {
E 4
					movetotalon();
D 4
				else dumberror();
E 4
I 4
					break;
				}
				if (status == BETTINGBOX) {
					do {
						getcmd(moverow, movecol,
							"Buy game?");
					} while (srcpile != 'y' &&
						 srcpile != 'n');
					if (srcpile == 'n') {
						showcards();
						done = TRUE;
						break;
					}
				}
				infullgame = TRUE;
				this.wins += valuepercardup * cardsoff;
I 18
				game.wins += valuepercardup * cardsoff;
E 18
				total.wins += valuepercardup * cardsoff;
				this.game += costofgame;
I 18
				game.game += costofgame;
E 18
				total.game += costofgame;
				movetotalon();
E 4
				break;
			case 'q':
				showcards();
				done = TRUE;
I 2
				break;
I 4
			case 'b':
				printtopbettingbox();
				printbottombettingbox();
				status = BETTINGBOX;
				break;
			case 'x':
				clearabovemovebox();
				clearbelowmovebox();
				status = NOBOX;
				break;
E 4
			case 'i':
D 4
				Iflag = !Iflag;
				if (Iflag) {
					printtopinstructions();
					printbottominstructions();
				} else {
					cleartopinstructions();
					clearbottominstructions();
				}
E 4
I 4
				printtopinstructions();
				printbottominstructions();
				status = INSTRUCTIONBOX;
E 4
E 2
				break;
			case 'c':
				Cflag = !Cflag;
				if (Cflag)
					showstat();
				else
					clearstat();
				break;
			case '1': case '2': case '3': case '4':
				if (destpile == 'f' || destpile == 'F')
					movetofound(&tableau[source], source);
				else if (destpile >= '1' && destpile <= '4')
					tabtotab(source, dest);
				else dumberror();
				break;
			default:
				dumberror();
		}
		fndbase(&stock, stockcol, stockrow);
		fndbase(&talon, taloncol, talonrow);
I 4
		updatebettinginfo();
E 4
	} while (!done);
}

D 4
/* procedure to printout instructions */
E 4
I 4
char *basicinstructions[] = {
	"Here are brief instuctions to the game of Canfield:\n\n",
	"     If you have never played solitaire before, it is recom-\n",
	"mended  that  you  consult  a solitaire instruction book. In\n",
	"Canfield, tableau cards may be built on each other  downward\n",
	"in  alternate colors. An entire pile must be moved as a unit\n",
	"in building. Top cards of the piles are available to be able\n",
	"to be played on foundations, but never into empty spaces.\n\n",
	"     Spaces must be filled from the stock. The top  card  of\n",
	"the  stock  also is available to be played on foundations or\n",
	"built on tableau piles. After the stock  is  exhausted,  ta-\n",
	"bleau spaces may be filled from the talon and the player may\n",
	"keep them open until he wishes to use them.\n\n",
	"     Cards are dealt from the hand to the  talon  by  threes\n",
	"and  this  repeats until there are no more cards in the hand\n",
	"or the player quits. To have cards dealt onto the talon  the\n",
	"player  types  'ht'  for his move. Foundation base cards are\n",
	"also automatically moved to the foundation when they  become\n",
	"available.\n\n",
	"push any key when you are finished: ",
	0 };

char *bettinginstructions[] = {
	"     The rules for betting are  somewhat  less  strict  than\n",
	"those  used in the official version of the game. The initial\n",
	"deal costs $13. You may quit at this point  or  inspect  the\n",
	"game.  Inspection  costs  $13 and allows you to make as many\n",
	"moves as is possible without moving any cards from your hand\n",
	"to  the  talon.  (the initial deal places three cards on the\n",
	"talon; if all these cards are  used,  three  more  are  made\n",
	"available)  Finally, if the game seems interesting, you must\n",
	"pay the final installment of $26.  At  this  point  you  are\n",
	"credited  at the rate of $5 for each card on the foundation;\n",
	"as the game progresses you are credited  with  $5  for  each\n",
	"card  that is moved to the foundation.  Each run through the\n",
	"hand after the first costs $5.  The  card  counting  feature\n",
	"costs  $1  for  each unknown card that is identified. If the\n",
	"information is toggled on, you are only  charged  for  cards\n",
	"that  became  visible  since it was last turned on. Thus the\n",
D 5
	"maximum cost of information is $34.\n\n",
E 5
I 5
	"maximum cost of information is $34.  Playing time is charged\n",
	"at a rate of $1 per minute.\n\n",
E 5
	"push any key when you are finished: ",
	0 };

/*
 * procedure to printout instructions
 */
D 6

E 6
E 4
instruct()
{
I 4
	register char **cp;

E 4
	move(originrow, origincol);
	printw("This is the game of solitaire called Canfield.  Do\n");
	printw("you want instructions for the game?");
	do {
		getcmd(originrow + 3, origincol, "y or n?");
	} while (srcpile != 'y' && srcpile != 'n');
D 4
	if (srcpile == 'y') {
		clear();
		refresh();
		printw("Here are brief instuctions to the game of Canfield:\n");
		printw("\n");
		printw("     If you have never played solitaire before, it is recom-\n");
		printw("mended  that  you  consult  a solitaire instruction book. In\n");
		printw("Canfield, tableau cards may be built on each other  downward\n");
		printw("in  alternate colors. An entire pile must be moved as a unit\n");
		printw("in building. Top cards of the piles are available to be able\n");
		printw("to be played on foundations, but never into empty spaces.\n");
		printw("\n");
		printw("     Spaces must be filled from the stock. The top  card  of\n");
		printw("the  stock  also is available to be played on foundations or\n");
		printw("built on tableau piles. After the stock  is  exhausted,  ta-\n");
		printw("bleau spaces may be filled from the talon and the player may\n");
		printw("keep them open until he wishes to use them.\n");
		printw("\n");
		printw("     Cards are dealt from the hand to the  talon  by  threes\n");
		printw("and  this  repeats until there are no more cards in the hand\n");
		printw("or the player quits. To have cards dealt onto the talon  the\n");
		printw("player  types  'ht'  for his move. Foundation base cards are\n");
		printw("also automatically moved to the foundation when they  become\n");
		printw("available.\n\n");
		printw("push any key when you are finished: ");
		refresh();
		getch();
	}
E 4
I 4
	if (srcpile == 'n')
		return;
	clear();
	for (cp = basicinstructions; *cp != 0; cp++)
		printw(*cp);
	refresh();
	getch();
	clear();
	move(originrow, origincol);
	printw("Do you want instructions for betting?");
	do {
		getcmd(originrow + 2, origincol, "y or n?");
	} while (srcpile != 'y' && srcpile != 'n');
	if (srcpile == 'n')
		return;
	clear();
	for (cp = bettinginstructions; *cp != 0; cp++)
		printw(*cp);
	refresh();
	getch();
E 4
}

D 6
/* procedure to initialize the game */
E 6
I 6
/*
 * procedure to initialize the game
 */
E 6
initall()
D 4

E 4
{
D 4
	srand(getpid());
E 4
I 4
D 17
	int uid, i;
E 17
I 17
	int i;
E 17

	srandom(getpid());
I 5
	time(&acctstart);
E 5
E 4
	initdeck(deck);
I 4
	uid = getuid();
	if (uid < 0)
D 17
		return;
E 17
I 17
		uid = 0;
E 17
	dbfd = open("/usr/games/lib/cfscores", 2);
	if (dbfd < 0)
		return;
	i = lseek(dbfd, uid * sizeof(struct betinfo), 0);
	if (i < 0) {
		close(dbfd);
		dbfd = -1;
		return;
	}
	i = read(dbfd, (char *)&total, sizeof(total));
	if (i < 0) {
		close(dbfd);
		dbfd = -1;
		return;
	}
D 17
	lseek(dbfd, uid * sizeof(struct betinfo), 0);
E 17
E 4
}

D 4
/* procedure to end the game */
E 4
I 4
/*
 * procedure to end the game
 */
E 4
bool
finish()
{
	int row, col;

	if (cardsoff == 52) {
I 14
		getcmd(moverow, movecol, "Hit return to exit");
E 14
		clear();
		refresh();
		move(originrow, origincol);
		printw("CONGRATULATIONS!\n");
		printw("You won the game. That is a feat to be proud of.\n");
D 16
		move(originrow + 4, origincol);
		printw("Wish to play again?     ");
E 16
		row = originrow + 5;
		col = origincol;
	} else {
		move(msgrow, msgcol);
		printw("You got %d card", cardsoff);
		if (cardsoff > 1)
			printw("s");
		printw(" off    ");
D 16
		getcmd(moverow, movecol, "Hit return to continue");
E 16
		move(msgrow, msgcol);
D 16
		printw("Wish to play again?     ");
E 16
		row = moverow;
		col = movecol;
	}
	do {
D 16
		getcmd(row, col, "y or n?");
E 16
I 16
		getcmd(row, col, "Play again (y or n)?");
E 16
	} while (srcpile != 'y' && srcpile != 'n');
	errmsg = TRUE;
	clearmsg();
	if (srcpile == 'y')
		return (FALSE);
	else
		return (TRUE);
}

I 4
/*
 * Field an interrupt.
 */
askquit()
{
	move(msgrow, msgcol);
	printw("Really wish to quit?    ");
	do {
		getcmd(moverow, movecol, "y or n?");
	} while (srcpile != 'y' && srcpile != 'n');
	clearmsg();
	if (srcpile == 'y')
		cleanup();
	signal(SIGINT, askquit);
}

/*
 * procedure to clean up and exit
 */
cleanup()
{

I 5
	total.thinktime += 1;
I 8
	status = NOBOX;
	updatebettinginfo();
E 8
E 5
	if (dbfd != -1) {
I 17
		lseek(dbfd, uid * sizeof(struct betinfo), 0);
E 17
		write(dbfd, (char *)&total, sizeof(total));
		close(dbfd);
	}
	clear();
	move(22,0);
	refresh();
	endwin();
	exit(0);
	/* NOTREACHED */
}

I 6
/*
 * Can you tell that this used to be a Pascal program?
 */
E 6
E 4
main(argc, argv)
	int argc;
	char *argv[];
{
#ifdef MAXLOAD
	double vec[3];

	loadav(vec);
	if (vec[2] >= MAXLOAD) {
		puts("The system load is too high.  Try again later.");
		exit(0);
	}
#endif
I 4
	signal(SIGINT, askquit);
	signal(SIGHUP, cleanup);
	signal(SIGTERM, cleanup);
E 4
	initscr();
I 9
D 10
	signal(SIGTSTP, SIG_DFL);		/* avoid tstp in curses */
E 10
E 9
	raw();
	noecho();
	initall();
	instruct();
	makeboard();
	for (;;) {
		startgame();
		movecard();
		if (finish())
			break;
		if (cardsoff == 52)
			makeboard();
		else
			cleanupboard();
	}
D 4
	clear();
	move(22,0);
	refresh();
	endwin();
E 4
I 4
	cleanup();
	/* NOTREACHED */
E 4
}
E 1
