h04106
s 00010/00005/00167
d D 5.3 88/06/18 19:47:30 bostic 6 5
c install approved copyright notice
e
s 00009/00003/00163
d D 5.2 88/02/16 11:16:50 bostic 5 4
c authored by Alan Char; add Berkeley specific header
e
s 00009/00001/00157
d D 5.1 85/05/29 11:40:00 dist 4 3
c Add copyright
e
s 00002/00000/00156
d D 4.2 82/10/24 22:19:30 mckusick 3 2
c fix syntaxerrors
e
s 00000/00000/00156
d D 4.1 82/05/11 15:02:55 rrh 2 1
c bringing to release 4.1
e
s 00156/00000/00000
d D 1.1 82/05/11 14:54:38 rrh 1 0
c date and time created 82/05/11 14:54:38 by rrh
e
u
U
t
T
I 1
D 4
static char sccsid[] = "	%M%	%I%	%E%	";
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
D 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 6
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 6
I 6
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
E 6
E 5
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif not lint
E 5
I 5
#endif /* not lint */
E 5
E 4

#include "back.h"

I 3
char *prompt, *list, *opts;

E 3
char	*doubl[] = {
    "\nDoubling:",
    "\n   If a player thinks he is in a good position, he may double the",
    "value of the game.  However, his opponent may not accept the pro-",
    "posal and forfeit the game before the price gets too high.  A",
    "player must double before he rolls, and once his double has been",
    "accepted, he cannot double again, until his opponent has doubled.",
    "Thus, unless the game swings back and forth in advantage between",
    "the two players a great deal, the value of the game should be",
    "low.  At any rate, the value of the game will never go above 64,",
    "or six doubles.  However, if a player wins a backgammon at 64",
    "points, he wins 192 points!",
    "",
    0};

char	*stragy[] = {
    "\nStrategy:",
    "\n   Some general hints when playing:  Try not to leave men open",
    "unless absolutely necessary.  Also, it is good to make as many",
    "points as possible.  Often, two men from different positions can",
    "be brought together to form a new point.  Although walls (six",
    "points in a row) are difficult to form, many points nestled close-",
    "ly together produce a formidable barrier.  Also, while it is good",
    "to move back men forward, doing so lessens the opportunity for you",
    "to hit men.  Finally, remember that once the two player's have",
    "passed each other on the board, there is no chance of either team",
    "being hit, so the game reduces to a race off the board.  Addi-",
    "tional hints on strategy are presented in the practice game.",
    "",
    0};

char	*prog[] = {
   "\nThe Program and How It Works:",
   "\n   A general rule of thumb is when you don't know what to do,",
   "type a question mark, and you should get some help.  When it is",
   "your turn, only your color will be printed out, with nothing",
   "after it.  You may double by typing a 'd', but if you type a",
   "space or newline, you will get your roll.  (Remember, you must",
   "double before you roll.)  Also, typing a 'r' will reprint the",
   "board, and a 'q' will quit the game.  The program will type",
   "'Move:' when it wants your move, and you may indicate each die's",
   "move with <s>-<f>, where <s> is the starting position and <f> is",
   "the finishing position, or <s>/<r> where <r> is the roll made.",
   "<s>-<f1>-<f2> is short for <s>-<f1>,<f1>-<f2> and <s>/<r1><r2> is",
   "short for <s>/<r1>,<s>/<r2>.  Moves may be separated by a comma",
   "or a space.",
   "",
   "\n   While typing, any input which does not make sense will not be",
   "echoed, and a bell will sound instead.  Also, backspacing and",
   "killing lines will echo differently than normal.  You may examine",
   "the board by typing a 'r' if you have made a partial move, or be-",
   "fore you type a newline, to see what the board looks like.  You",
   "must end your move with a newline.  If you cannot double, your",
   "roll will always be printed, and you will not be given the oppor-",
   "tunity to double.  Home and bar are represented by the appropri-",
   "ate number, 0 or 25 as the case may be, or by the letters 'h' or",
   "'b' as appropriate.  You may also type 'r' or 'q' when the program",
   "types 'Move:', which has the same effect as above.  Finally, you",
   "will get to decide if you want to play red or white (or both if you",
   "want to play a friend) at the beginning of the session, and you",
   "will not get to change your mind later, since the computer keeps",
   "score.",
   "",
   0};

char	*lastch[] = {
   "\nTutorial (Practice Game):",
   "\n   This tutorial, for simplicity's sake, will let you play one",
   "predetermined game.  All the rolls have been pre-arranged, and",
   "only one response will let you advance to the next move.",
   "Although a given roll will may have several legal moves, the tu-",
   "torial will only accept one (not including the same moves in a",
   "different order), claiming that that move is 'best.'  Obviously,",
   "a subjective statement.  At any rate, be patient with it and have",
   "fun learning about backgammon.  Also, to speed things up a lit-",
   "tle, doubling will not take place in the tutorial, so you will",
   "never get that opportunity, and quitting only leaves the tutori-",
   "al, not the game.  You will still be able to play backgammon",
   "after quitting.",
   "\n   This is your last chance to look over the rules before the tu-",
   "torial starts.",
   "",
   0};

text (txt)
char	**txt;

{
	char	**begin;
	char	*a;
	char	b;
	char	*c;
	int	i;

	fixtty (noech);
	begin = txt;
	while (*txt)  {
		a = *(txt++);
		if (*a != '\0')  {
			c = a;
			for (i = 0; *(c++) != '\0'; i--);
			writel (a);
			writec ('\n');
		} else  {
			fixtty (raw);
			writel (prompt);
			for (;;)  {
				if ((b = readc()) == '?')  {
					if (tflag)  {
						if (begscr)  {
							curmove (18,0);
							clend();
						} else
							clear();
					} else
						writec ('\n');
					text (list);
					writel (prompt);
					continue;
				}
				i = 0;
				if (b == '\n')
					break;
				while (i < 11)  {
					if (b == opts[i])
						break;
					i++;
				}
				if (i == 11)
					writec ('\007');
				else
					break;
			}
			if (tflag)  {
				if (begscr)  {
					curmove (18,0);
					clend();
				} else
					clear();
			} else
				writec ('\n');
			if (i)
				return(i);
			fixtty (noech);
			if (tflag)
				curmove (curr,0);
			begin = txt;
		}
	}
	fixtty (raw);
	return (0);
}
E 1
