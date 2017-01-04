h24038
s 00010/00005/00039
d D 5.3 88/06/18 19:47:08 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00035
d D 5.2 88/02/16 11:16:24 bostic 4 3
c authored by Alan Char; add Berkeley specific header
e
s 00009/00001/00029
d D 5.1 85/05/29 11:33:39 dist 3 2
c Add copyright
e
s 00000/00000/00030
d D 4.1 82/05/11 15:02:05 rrh 2 1
c bringing to release 4.1
e
s 00030/00000/00000
d D 1.1 82/05/11 14:53:35 rrh 1 0
c date and time created 82/05/11 14:53:35 by rrh
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

#include <sgtty.h>

/*
 * variable initialization.
 */

				/* name of executable object programs */
char	EXEC[] = "/usr/games/backgammon";
char	TEACH[] = "/usr/games/teachgammon";

int	pnum	= 2;		/* color of player:
					-1 = white
					 1 = red
					 0 = both
					 2 = not yet init'ed */
int	acnt	= 0;		/* length of args */
int	aflag	= 1;		/* flag to ask for rules or instructions */
int	bflag	= 0;		/* flag for automatic board printing */
int	cflag	= 0;		/* case conversion flag */
int	hflag	= 1;		/* flag for cleaning screen */
int	mflag	= 0;		/* backgammon flag */
int	raflag	= 0;		/* 'roll again' flag for recovered game */
int	rflag	= 0;		/* recovered game flag */
int	tflag	= 0;		/* cursor addressing flag */
int	iroll	= 0;		/* special flag for inputting rolls */
int	rfl	= 0;

char	*color[] = {"White","Red","white","red"};
E 1
