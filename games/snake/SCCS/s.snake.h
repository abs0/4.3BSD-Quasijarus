h21086
s 00010/00005/00053
d D 5.4 88/06/18 19:30:53 bostic 5 4
c install approved copyright notice
e
s 00003/00000/00055
d D 5.3 88/04/20 12:36:48 bostic 4 3
c same() used too much, make it a macro
e
s 00008/00002/00047
d D 5.2 88/03/09 11:29:53 bostic 3 2
c add Berkeley specific header
e
s 00007/00001/00042
d D 5.1 85/05/30 08:46:11 dist 2 1
c Add copyright
e
s 00043/00000/00000
d D 4.1 83/07/04 12:48:47 sam 1 0
c date and time created 83/07/04 12:48:47 by sam
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
D 3
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
I 3
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
E 3
 *
 *	%W% (Berkeley) %G%
 */
E 2

# include <stdio.h>
# include <assert.h>
# include <sys/types.h>
# include <sgtty.h>
# include <signal.h>
# include <math.h>

#define ESC	'\033'

struct tbuffer {
	long t[4];
} tbuffer;

char	*CL, *UP, *DO, *ND, *BS,
	*HO, *CM,
	*TA, *LL,
	*KL, *KR, *KU, *KD,
	*TI, *TE, *KS, *KE;
int	LINES, COLUMNS;	/* physical screen size. */
int	lcnt, ccnt;	/* user's idea of screen size */
char	xBC, PC;
int	AM, BW;
char	tbuf[1024], tcapbuf[128];
char	*tgetstr(), *tgoto();
int	Klength;	/* length of KX strings */
int	chunk;		/* amount of money given at a time */
#ifdef	debug
#define	cashvalue	(loot-penalty)/25
#else
#define cashvalue	chunk*(loot-penalty)/25
#endif

struct point {
	int col, line;
};
struct point cursor;
struct sgttyb orig, new;
#ifdef TIOCLGET
struct ltchars olttyc, nlttyc;
#endif
struct point *point();
I 4

#define	same(s1, s2)	((s1)->line == (s2)->line && (s1)->col == (s2)->col)

E 4
E 1
