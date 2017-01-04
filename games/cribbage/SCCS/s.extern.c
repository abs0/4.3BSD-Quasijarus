h63813
s 00010/00005/00041
d D 5.3 88/06/18 14:39:29 bostic 6 5
c install approved copyright notice
e
s 00009/00003/00037
d D 5.2 88/03/10 16:31:49 bostic 5 4
c add Berkeley specific header, Ken Arnold says written @ Berkeley
e
s 00010/00001/00030
d D 5.1 85/05/30 19:44:55 mckusick 4 3
c Add copyright
e
s 00001/00000/00030
d D 1.3 83/05/19 12:22:36 arnold 3 2
c add sccs keywords
e
s 00022/00022/00008
d D 1.2 83/05/01 15:31:16 arnold 2 1
c make a scrolling region for cribbage
e
s 00030/00000/00000
d D 1.1 83/05/01 13:31:13 arnold 1 0
c date and time created 83/05/01 13:31:13 by arnold
e
u
U
t
T
I 3
D 4
static char *sccsid = "%W% (Berkeley) %G%";
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
E 3
I 1
# include	<curses.h>
# include	"deck.h"
# include	"cribbage.h"

D 2
bool		iwon		= FALSE;	/* if comp won last game */
bool		explain		= FALSE;	/* player mistakes explained */
bool		rflag		= FALSE;	/* if all cuts random */
bool		quiet		= FALSE;	/* if suppress random mess */
bool		Hasread		= TRUE;		/* if has read msg */
E 2
I 2
bool	explain		= FALSE;	/* player mistakes explained */
bool	iwon		= FALSE;	/* if comp won last game */
bool	quiet		= FALSE;	/* if suppress random mess */
bool	rflag		= FALSE;	/* if all cuts random */
E 2

D 2
char		expl[128];			/* explanation */
E 2
I 2
char	expl[128];			/* explanation */
E 2

D 2
int		knownum		= 0;		/* number of cards we know */
int		pscore		= 0;		/* player score in this game */
int		cscore		= 0;		/* comp score in this game */
int		pgames		= 0;		/* number games player won */
int		cgames		= 0;		/* number games comp won */
int		gamecount	= 0;		/* number games played */
int		glimit		= LGAME;	/* game playe to glimit */
E 2
I 2
int	cgames		= 0;		/* number games comp won */
int	cscore		= 0;		/* comp score in this game */
int	gamecount	= 0;		/* number games played */
int	glimit		= LGAME;	/* game playe to glimit */
int	knownum		= 0;		/* number of cards we know */
int	pgames		= 0;		/* number games player won */
int	pscore		= 0;		/* player score in this game */
E 2

D 2
CARD		deck[CARDS];			/* a deck */
CARD		phand[FULLHAND];		/* player's hand */
CARD		chand[FULLHAND];		/* computer's hand */
CARD		crib[CINHAND];			/* the crib */
CARD		turnover;			/* the starter */
CARD		known[CARDS];			/* cards we have seen */
E 2
I 2
CARD	chand[FULLHAND];		/* computer's hand */
CARD	crib[CINHAND];			/* the crib */
CARD	deck[CARDS];			/* a deck */
CARD	known[CARDS];			/* cards we have seen */
CARD	phand[FULLHAND];		/* player's hand */
CARD	turnover;			/* the starter */
E 2

D 2
WINDOW		*Playwin;			/* player's hand window */
WINDOW		*Tablewin;			/* table window */
WINDOW		*Compwin;			/* computer's hand window */
E 2
I 2
WINDOW	*Compwin;			/* computer's hand window */
WINDOW	*Msgwin;			/* messages for the player */
WINDOW	*Playwin;			/* player's hand window */
WINDOW	*Tablewin;			/* table window */
E 2
E 1
