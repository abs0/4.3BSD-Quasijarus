h20599
s 00010/00005/00101
d D 5.3 88/06/18 19:46:57 bostic 6 5
c install approved copyright notice
e
s 00008/00003/00098
d D 5.2 88/02/16 11:16:16 bostic 5 4
c authored by Alan Char; add Berkeley specific header
e
s 00006/00001/00095
d D 5.1 85/05/29 11:42:47 dist 4 3
c Add copyright
e
s 00001/00001/00095
d D 4.2 82/11/22 16:10:53 mckusick 3 2
c upgrade srand and rand to srandom and random (pdp11 dependent)
e
s 00000/00000/00096
d D 4.1 82/05/11 15:01:31 rrh 2 1
c bringing to release 4.1
e
s 00096/00000/00000
d D 1.1 82/05/11 14:54:50 rrh 1 0
c date and time created 82/05/11 14:54:50 by rrh
e
u
U
t
T
I 4
D 5

E 5
E 4
I 1
/*
D 4
 *	%M%	%I%	%E%
E 4
I 4
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
 *
 *	%W% (Berkeley) %G%
E 4
 */

#include <sgtty.h>

D 3
#define rnum(r)	(rand(0)/(32767/r+1))
E 3
I 3
#define rnum(r)	(random()%r)
E 3
#define D0	dice[0]
#define D1	dice[1]
#define swap	{D0 ^= D1; D1 ^= D0; D0 ^= D1; d0 = 1-d0;}

/*
 *
 * Some numerical conventions:
 *
 *	Arrays have white's value in [0], red in [1].
 *	Numeric values which are one color or the other use
 *	-1 for white, 1 for red.
 *	Hence, white will be negative values, red positive one.
 *	This makes a lot of sense since white is going in decending
 *	order around the board, and red is ascending.
 *
 */

char	EXEC[];			/* object for main program */
char	TEACH[];		/* object for tutorial program */

int	pnum;			/* color of player:
					-1 = white
					 1 = red
					 0 = both
					 2 = not yet init'ed */
char	args[100];		/* args passed to teachgammon and back */
int	acnt;			/* length of args */
int	aflag;			/* flag to ask for rules or instructions */
int	bflag;			/* flag for automatic board printing */
int	cflag;			/* case conversion flag */
int	hflag;			/* flag for cleaning screen */
int	mflag;			/* backgammon flag */
int	raflag;			/* 'roll again' flag for recovered game */
int	rflag;			/* recovered game flag */
int	tflag;			/* cursor addressing flag */
int	rfl;			/* saved value of rflag */
int	iroll;			/* special flag for inputting rolls */
int	board[26];		/* board:  negative values are white,
				   positive are red */
int	dice[2];		/* value of dice */
int	mvlim;			/* 'move limit':  max. number of moves */
int	mvl;			/* working copy of mvlim */
int	p[5];			/* starting position of moves */
int	g[5];			/* ending position of moves (goals) */
int	h[4];			/* flag for each move if a man was hit */
int	cturn;			/* whose turn it currently is:
					-1 = white
					 1 = red
					 0 = just quitted
					-2 = white just lost
					 2 = red just lost */
int	d0;			/* flag if dice have been reversed from
				   original position */
int	table[6][6];		/* odds table for possible rolls */
int	rscore;			/* red's score */
int	wscore;			/* white's score */
int	gvalue;			/* value of game (64 max.) */
int	dlast;			/* who doubled last (0 = neither) */
int	bar;			/* position of bar for current player */
int	home;			/* position of home for current player */
int	off[2];			/* number of men off board */
int	*offptr;		/* pointer to off for current player */
int	*offopp;		/* pointer to off for opponent */
int	in[2];			/* number of men in inner table */
int	*inptr;			/* pointer to in for current player */
int	*inopp;			/* pointer to in for opponent */

int	ncin;			/* number of characters in cin */
char	cin[100];		/* input line of current move
				   (used for reconstructing input after
				   a backspace) */

char	*color[];
				/* colors as strings */
char	**colorptr;		/* color of current player */
char	**Colorptr;		/* color of current player, capitalized */
int	colen;			/* length of color of current player */

struct sgttyb	tty;		/* tty information buffer */
int		old;		/* original tty status */
int		noech;		/* original tty status without echo */
int		raw;		/* raw tty status, no echo */

int	curr;			/* row position of cursor */
int	curc;			/* column position of cursor */
int	begscr;			/* 'beginning' of screen
				   (not including board) */

int	getout();		/* function to exit backgammon cleanly */
E 1
