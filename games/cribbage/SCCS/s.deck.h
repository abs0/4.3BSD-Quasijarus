h38903
s 00010/00005/00059
d D 5.3 88/06/18 14:39:28 bostic 7 6
c install approved copyright notice
e
s 00008/00002/00056
d D 5.2 88/03/10 16:30:15 bostic 6 5
c add Berkeley specific header, Ken Arnold says written @ Berkeley
e
s 00007/00001/00051
d D 5.1 85/05/30 19:47:34 mckusick 5 4
c Add copyright
e
s 00001/00000/00051
d D 1.3 83/05/19 12:22:09 arnold 4 2
c add sccs keywords
e
s 00035/00036/00015
d R 1.3 82/08/28 17:06:21 arnold 3 2
c reformatting and obvious optimization
e
s 00005/00002/00046
d D 1.2 82/08/24 18:34:04 arnold 2 1
c first "working" visual version
e
s 00048/00000/00000
d D 1.1 82/08/11 16:35:57 arnold 1 0
c date and time created 82/08/11 16:35:57 by arnold
e
u
U
t
T
I 4
D 5
/* %W% (Berkeley) %G% */
E 5
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
D 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
E 6
 *
 *	%W% (Berkeley) %G%
 */
E 5
E 4
I 1

/*
 * define structure of a deck of cards and other related things
 */


#define		CARDS		52		/* number cards in deck */
#define		RANKS		13		/* number ranks in deck */
#define		SUITS		4		/* number suits in deck */

#define		CINHAND		4		/* # cards in cribbage hand */
#define		FULLHAND	6		/* # cards in dealt hand */

#define		LGAME		121		/* number points in a game */
#define		SGAME		61		/* # points in a short game */

#define		SPADES		0		/* value of each suit */
#define		HEARTS		1
#define		DIAMONDS	2
#define		CLUBS		3

#define		ACE		0		/* value of each rank */
#define		TWO		1
#define		THREE		2
#define		FOUR		3
#define		FIVE		4
#define		SIX		5
#define		SEVEN		6
#define		EIGHT		7
#define		NINE		8
#define		TEN		9
#define		JACK		10
#define		QUEEN		11
#define		KING		12
I 2
#define		EMPTY		13
E 2

#define		VAL(c)		( (c) < 9 ? (c)+1 : 10 )    /* val of rank */


D 2
#define		TRUE		1
#define		FALSE		0
E 2
I 2
#ifndef TRUE
#	define		TRUE		1
#	define		FALSE		0
#endif
E 2

typedef		struct  {
			int		rank;
			int		suit;
		}		CARD;

typedef		char		BOOLEAN;

E 1
