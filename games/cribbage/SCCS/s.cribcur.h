h45515
s 00010/00005/00031
d D 5.3 88/06/18 14:39:26 bostic 9 8
c install approved copyright notice
e
s 00008/00002/00028
d D 5.2 88/03/10 16:30:14 bostic 8 7
c add Berkeley specific header, Ken Arnold says written @ Berkeley
e
s 00007/00001/00023
d D 5.1 85/05/30 19:47:16 mckusick 7 6
c Add copyright
e
s 00002/00000/00022
d D 1.5 83/05/19 12:22:15 arnold 6 5
c add sccs keywords
e
s 00006/00005/00016
d D 1.4 83/05/07 14:07:02 arnold 5 4
c add a scrolling region
e
s 00007/00003/00014
d D 1.3 83/05/01 15:31:14 arnold 4 3
c make a scrolling region for cribbage
e
s 00011/00010/00006
d D 1.2 83/05/01 13:26:17 arnold 3 1
c swap the board and the cards on the screen
e
s 00007/00003/00013
d R 1.2 82/08/28 17:06:55 arnold 2 1
c reformatting and obvious optimization
e
s 00016/00000/00000
d D 1.1 82/08/28 12:39:53 arnold 1 0
c date and time created 82/08/28 12:39:53 by arnold
e
u
U
t
T
I 6
D 7
/* %W% (Berkeley) %G% */
E 7
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
D 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
I 8
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
E 8
 *
 *	%W% (Berkeley) %G%
 */
E 7

E 6
I 1
D 3
# define	PLAY_Y	15	/* starting pos for player's hand window */
# define	PLAY_X	12
# define	TABLE_Y	21	/* starting pos for table window */
# define	TABLE_X	14
# define	COMP_Y	15	/* starting pos for computer's hand window */
# define	COMP_X	12
# define	SCORE_Y	 0	/* starting pos for scoring board */
# define	SCORE_X	39
# define	CRIB_Y	17	/* position of crib (cut card) */
# define	CRIB_X	(PLAY_X + TABLE_X)
E 3
I 3
# define	PLAY_Y		15	/* size of player's hand window */
# define	PLAY_X		12
# define	TABLE_Y		21	/* size of table window */
# define	TABLE_X		14
# define	COMP_Y		15	/* size of computer's hand window */
# define	COMP_X		12
D 5
# define	SCORE_Y	 	0	/* starting position of scoring board */
# define	SCORE_X		0
D 4
# define	SCORE_SZ	41	/* X size of score board */
E 4
I 4
# define	Y_SCORE_SZ	11	/* X size of score board */
E 5
I 5
# define	Y_SCORE_SZ	9	/* Y size of score board */
E 5
# define	X_SCORE_SZ	41	/* X size of score board */
I 5
# define	SCORE_Y		0	/* starting position of scoring board */
# define	SCORE_X	 	(PLAY_X + TABLE_X + COMP_X)
E 5
E 4
# define	CRIB_Y		17	/* position of crib (cut card) */
D 4
# define	CRIB_X		(PLAY_X + TABLE_X + SCORE_SZ)
E 4
I 4
D 5
# define	CRIB_X		(PLAY_X + TABLE_X + X_SCORE_SZ)
E 5
I 5
# define	CRIB_X		(PLAY_X + TABLE_X)
E 5
# define	MSG_Y		(LINES - (Y_SCORE_SZ + 1))
D 5
# define	MSG_X		X_SCORE_SZ
E 5
I 5
# define	MSG_X		(COLS - SCORE_X - 1)
# define	Y_MSG_START	(Y_SCORE_SZ + 1)
E 5
E 4
E 3

# define	PEG	'*'	/* what a peg looks like on the board */

I 4
extern	WINDOW		*Compwin;		/* computer's hand window */
extern	WINDOW		*Msgwin;		/* message window */
E 4
extern	WINDOW		*Playwin;		/* player's hand window */
extern	WINDOW		*Tablewin;		/* table window */
D 4
extern	WINDOW		*Compwin;		/* computer's hand window */
E 4
E 1
