h07818
s 00010/00005/00049
d D 5.3 88/06/18 20:04:37 bostic 3 2
c install approved copyright notice
e
s 00009/00003/00045
d D 5.2 88/03/09 11:18:34 bostic 2 1
c Written by Ken Arnold; add Berkeley specific copyright
e
s 00048/00000/00000
d D 5.1 85/05/30 18:33:23 mckusick 1 0
c date and time created 85/05/30 18:33:23 by mckusick
e
u
U
t
T
I 1
/*
 * Copyright (c) 1980 Regents of the University of California.
D 2
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 2
I 2
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 3
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 3
I 3
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
E 3
E 2
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 2
#endif not lint
E 2
I 2
#endif /* not lint */
E 2

# include	"robots.h"

bool	Dead;			/* Player is now dead */
bool	Full_clear = TRUE;	/* Lots of junk for init_field to clear */
bool	Jump = FALSE;		/* Jump while running, counting, or waiting */
bool	Newscore;		/* There was a new score added */
#ifdef	FANCY
bool	Pattern_roll = FALSE;	/* Auto play for YHBJNLUK pattern */
#endif
bool	Real_time = FALSE;	/* Play in real time? */
bool	Running = FALSE;	/* Currently in the middle of a run */
#ifdef	FANCY
bool	Stand_still = FALSE;	/* Auto play for standing still pattern */
#endif
bool	Teleport = FALSE;	/* Teleport automatically when player must */
bool	Waiting;		/* Player is waiting for end */
bool	Was_bonus = FALSE;	/* Was a bonus last level */

char	Cnt_move;		/* Command which has preceded the count */
char	Field[Y_FIELDSIZE][X_FIELDSIZE];	/* the playing field itslef */
char	*Next_move;		/* Next move to be used in the pattern */
char	*Move_list = "YHBJNLUK";/* List of moves in the pattern */
char	Run_ch;			/* Character for the direction we are running */

int	Count = 0;		/* Command count */
int	Level;			/* Current level */
int	Num_robots;		/* Number of robots left */
int	Num_scores;		/* Number of scores posted */
int	Score;			/* Current score */
int	Start_level = 1;	/* Level on which to start */
int	Wait_bonus;		/* bonus for waiting */

COORD	Max;			/* Max area robots take up */
COORD	Min;			/* Min area robots take up */
COORD	My_pos;			/* Player's current position */
COORD	Robots[MAXROBOTS];	/* Robots' current positions */

jmp_buf	End_move;		/* Jump to on Real_time */
E 1
