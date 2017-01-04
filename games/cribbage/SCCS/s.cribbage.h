h58582
s 00010/00005/00035
d D 5.3 88/06/18 14:39:23 bostic 8 7
c install approved copyright notice
e
s 00008/00002/00032
d D 5.2 88/03/10 16:30:12 bostic 7 6
c add Berkeley specific header, Ken Arnold says written @ Berkeley
e
s 00007/00001/00027
d D 5.1 85/05/30 19:46:58 mckusick 6 5
c Add copyright
e
s 00002/00000/00026
d D 1.4 83/05/19 12:22:05 arnold 5 4
c add sccs keywords
e
s 00000/00001/00026
d D 1.3 83/05/01 15:31:11 arnold 4 2
c make a scrolling region for cribbage
e
s 00021/00024/00003
d R 1.3 82/08/28 17:06:17 arnold 3 2
c reformatting and obvious optimization
e
s 00003/00001/00024
d D 1.2 82/08/24 18:34:00 arnold 2 1
c first "working" visual version
e
s 00025/00000/00000
d D 1.1 82/08/11 16:35:55 arnold 1 0
c date and time created 82/08/11 16:35:55 by arnold
e
u
U
t
T
I 5
D 6
/* %W% (Berkeley) %G% */
E 6
I 6
/*
 * Copyright (c) 1980 Regents of the University of California.
D 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
E 7
 *
 *	%W% (Berkeley) %G%
 */
E 6

E 5
I 1
D 2

E 2
extern  CARD		deck[ CARDS ];		/* a deck */
extern  CARD		phand[ FULLHAND ];	/* player's hand */
extern  CARD		chand[ FULLHAND ];	/* computer's hand */
extern  CARD		crib[ CINHAND ];	/* the crib */
extern  CARD		turnover;		/* the starter */

extern  CARD		known[ CARDS ];		/* cards we have seen */
extern  int		knownum;		/* # of cards we know */

extern  int		pscore;			/* player's score */
extern  int		cscore;			/* comp's score */
extern  int		glimit;			/* points to win game */

extern  int		pgames;			/* player's games won */
extern  int		cgames;			/* comp's games won */
extern  int		gamecount;		/* # games played */
I 2
extern	int		Lastscore[2];		/* previous score for each */
E 2

extern  BOOLEAN		iwon;			/* if comp won last */
extern  BOOLEAN		explain;		/* player mistakes explained */
extern  BOOLEAN		rflag;			/* if all cuts random */
extern  BOOLEAN		quiet;			/* if suppress random mess */
I 2
D 4
extern  BOOLEAN		Hasread;		/* has had chance to read msg */
E 4
extern	BOOLEAN		playing;		/* currently playing game */
E 2

extern  char		expl[];			/* string for explanation */

E 1
