h38485
s 00010/00005/00084
d D 5.3 88/06/18 20:04:50 bostic 3 2
c install approved copyright notice
e
s 00008/00002/00081
d D 5.2 88/03/09 11:18:48 bostic 2 1
c Written by Ken Arnold; add Berkeley specific copyright
e
s 00083/00000/00000
d D 5.1 85/05/30 18:36:31 mckusick 1 0
c date and time created 85/05/30 18:36:31 by mckusick
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
 *
 *	%W% (Berkeley) %G%
 */

# include	<curses.h>
# include	<setjmp.h>

/*
 * miscellaneous constants
 */

# define	Y_FIELDSIZE	23
# define	X_FIELDSIZE	60
# define	Y_SIZE		24
# define	X_SIZE		80
# define	MAXLEVELS	4
# define	MAXROBOTS	(MAXLEVELS * 10)
# define	ROB_SCORE	10
# define	S_BONUS		(60 * ROB_SCORE)
# define	Y_SCORE		21
# define	X_SCORE		(X_FIELDSIZE + 9)
# define	Y_PROMPT	(Y_FIELDSIZE - 1)
# define	X_PROMPT	(X_FIELDSIZE + 2)
# define	MAXSCORES	(Y_SIZE - 2)
# define	MAXNAME		16
# define	MS_NAME		"Ten"
# define	SCOREFILE	"/usr/games/lib/robots_roll"

/*
 * characters on screen
 */

# define	ROBOT	'+'
# define	HEAP	'*'
# define	PLAYER	'@'

/*
 * pseudo functions
 */

# undef		CTRL
# define	CTRL(X)	('X' - 'A' + 1)

/*
 * type definitions
 */

typedef struct {
	int	y, x;
} COORD;

/*
 * global variables
 */

extern bool	Dead, Full_clear, Jump, Newscore, Real_time, Running,
		Teleport, Waiting, Was_bonus;

#ifdef	FANCY
extern bool	Pattern_roll, Stand_still;
#endif

extern char	Cnt_move, Field[Y_FIELDSIZE][X_FIELDSIZE], *Next_move,
		*Move_list, Run_ch;

extern int	Count, Level, Num_robots, Num_scores, Score,
		Start_level, Wait_bonus;

extern COORD	Max, Min, My_pos, Robots[];

extern jmp_buf	End_move;

/*
 * functions types
 */

int	quit(), cmp_sc(), move_robots();

COORD	*rnd_pos();
E 1
