h11818
s 00010/00005/00106
d D 5.3 88/06/18 19:47:26 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00102
d D 5.2 88/02/16 11:16:46 bostic 4 3
c authored by Alan Char; add Berkeley specific header
e
s 00009/00001/00096
d D 5.1 85/05/29 11:38:46 dist 3 2
c Add copyright
e
s 00000/00000/00097
d D 4.1 82/05/11 15:02:47 rrh 2 1
c bringing to release 4.1
e
s 00097/00000/00000
d D 1.1 82/05/11 14:54:25 rrh 1 0
c date and time created 82/05/11 14:54:25 by rrh
e
u
U
t
T
I 1
D 3
static char sccsid[] = "	%M%	%I%	%E%	";
E 3
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
D 4
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
I 4
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 5
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 5
I 5
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
E 5
E 4
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif not lint
E 4
I 4
#endif /* not lint */
E 4
E 3

#include "back.h"

char *instr[] = {
    "    If you did not notice by now, this program reacts to things as",
    "soon as you type them, without waiting for a newline.  This means that",
    "the special characters RUBOUT, ESC, and CONTROL-D, will not perform",
    "their special functions during most of this program.  The program",
    "should usually stop when a RUBOUT is typed, but occasionally it will",
    "ignore RUBOUTs until it is waiting for input.\n",
    "    These instructions are presented in small chunks designed not to",
    "roll off the top of your screen.  When the characters '-->' are print-",
    "ed, no more data will be printed until a space or newline is typed.",
    "In this way, you can finish one section before continuing to another.",
    "Like this:",
    "",
    "    The two sides are colored 'red' and 'white.' The computer may play",
    "one side, or if there are two players, the computer can merely act as",
    "a gamekeeper, letting the players make the moves.  Once you tell the",
    "computer what color(s) you want to play, the decision remains in ef-",
    "fect until you quit the program, even if you play more than one game,",
    "since the program keeps a running score.\n",
    "    The program will prompt for a move in one of two ways.  If the",
    "player has the opportunity to double, then merely his color will be",
    "typed out.  The player can now do one of several things.  He can dou-",
    "ble by typing a 'd', he can roll by typing a space (' ') or newline,",
    "or if he is not sure, he can reprint the board by typing a 'r'.\n",
    "    If the player cannot double, his roll will be thrust in front of",
    "him, followed by the request 'Move:', asking for a move but not giving",
    "him the chance to double.  He can still ask for the board by typing",
    "'r'.  In either of these two states, the player can quit by typing 'q'",
    "or save the game by typing 's'.  In either case, the player will be",
    "asked to verify, in case there was some error.  The program then ends",
    "immediately, after first saving the file if so requested.",
    "",
    "    A player can move one of his men using two forms of input.  The",
    "first form is <s>-<f>, where <s> is the starting position, and <f> is",
    "the finishing position of the player's man.  For example, if white",
    "wanted to move a piece from position 13 to position 8, his move could",
    "be entered as 13-8.  The second form is <s>/<r> where <s> is the",
    "starting position, an <r> is the roll actually made.  Hence, white",
    "could have entered as 13/5 instead of 13-8.\n",
    "    A player must move each roll of the dice separately.  For example,",
    "if a player rolled 4 3, and wanted to move from 13 to 6, he could",
    "enter it as 13/4,9/3 or 13/3,10/4 or 13-10,10-6 or 13-9,9-6, but not",
    "13-6.  The last two entries can be shortened to 13-10-6 and 13-9-6.",
    "If you want to move more than one piece from the same position, such",
    "as 13-10,13-9, you can abbreviate this using the <s>/<r> format as by",
    "entering more than one <r>, or 13/34.  A player can use both forms for",
    "the same roll, e.g. 13/3,13-9, and separates individual moves by ei-",
    "ther a comma or a space.  The letter 'b' represents the bar, and the",
    "letter 'h' represents a player's home.  You could also enter the",
    "number that would be in the position of the bar, 25 or 0 as appropri-",
    "ate.  Use a newline at the end of your moves for a turn.",
    "",
    "    As you type in your move, if a character does not make sense under",
    "the above constrictions, a bell will sound instead of the character,",
    "and it will be ignored.  You may kill lines and erase characters as",
    "you would normally, but don't be surprised if they look different than",
    "usual.  Also, if you have entered one or more of your rolls, and you",
    "wish to see what the move looks like so far, type a 'r' to see what it",
    "looks like.  This cannot be done in the middle of a move (e.g., after",
    "a '-' or '/').  After the printing board, the program will go back to",
    "inputting your move and you can backspace or kill just as if you had",
    "just typed in your input.\n",
    "    Now you should be ready to begin the game.  Good luck!",
    "",
    0};


text (t)
char	**t;

{
	register int	i;
	register char	*s, *a;

	fixtty (noech);
	while (*t != 0)  {
		s = a = *t;
		for (i = 0; *a != '\0'; i--)
			a++;
		if (i)  {
			writel (s);
			writec ('\n');
		} else  {
			writel ("-->");
			fixtty (raw);
			while ((i = readc()) != ' ' && i != '\n');
			fixtty (noech);
			clear();
		}
		t++;
	}
	fixtty (raw);
}
E 1
