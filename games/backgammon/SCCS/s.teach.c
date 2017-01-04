h58022
s 00010/00005/00140
d D 5.5 88/06/18 19:47:24 bostic 7 6
c install approved copyright notice
e
s 00015/00003/00130
d D 5.4 88/02/16 11:16:44 bostic 6 5
c authored by Alan Char; add Berkeley specific header
e
s 00001/00001/00132
d D 5.3 87/12/26 13:21:05 bostic 5 4
c fix typo for ANSI C
e
s 00000/00001/00133
d D 5.2 87/03/17 18:13:19 lepreau 4 3
c remove unused zero-length arrays (new compiler rejects them)
e
s 00009/00001/00125
d D 5.1 85/05/29 11:38:19 dist 3 2
c Add copyright
e
s 00000/00000/00126
d D 4.1 82/05/11 15:02:44 rrh 2 1
c bringing to release 4.1
e
s 00126/00000/00000
d D 1.1 82/05/11 14:54:22 rrh 1 0
c date and time created 82/05/11 14:54:22 by rrh
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
 */

#ifndef lint
I 6
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
E 6
static char sccsid[] = "%W% (Berkeley) %G%";
D 6
#endif not lint
E 6
I 6
#endif /* not lint */
E 6
E 3

#include "back.h"

char	*hello[];
char	*list[];
char	*intro1[];
char	*intro2[];
char	*moves[];
char	*remove[];
char	*hits[];
char	*endgame[];
char	*doubl[];
char	*stragy[];
char	*prog[];
char	*lastch[];

extern char	ospeed;			/* tty output speed for termlib */

char *helpm[] = {
	"\nEnter a space or newline to roll, or",
	"     b   to display the board",
	"     d   to double",
	"     q   to quit\n",
	0
};

char *contin[] = {
	"",
	0
};

main (argc,argv)
int	argc;
char	**argv;

{
D 4
	register char	*s, *ts[];
E 4
	register int	i;

	signal (2,getout);
	if (gtty (0,&tty) == -1)			/* get old tty mode */
		errexit ("teachgammon(gtty)");
	old = tty.sg_flags;
#ifdef V7
	raw = ((noech = old & ~ECHO) | CBREAK);		/* set up modes */
#else
	raw = ((noech = old & ~ECHO) | RAW);		/* set up modes */
#endif
D 5
	ospeed = old.sg_ospeed;				/* for termlib */
E 5
I 5
	ospeed = tty.sg_ospeed;				/* for termlib */
E 5
	tflag = getcaps (getenv ("TERM"));
#ifdef V7
	while (*++argv != 0)
#else
	while (*++argv != -1)
#endif
		getarg (&argv);
	if (tflag)  {
		noech &= ~(CRMOD|XTABS);
		raw &= ~(CRMOD|XTABS);
		clear();
	}
	text (hello);
	text (list);
	i = text (contin);
	if (i == 0)
		i = 2;
	init();
	while (i)
		switch (i)  {
		
		case 1:
			leave();
		
		case 2:
			if (i = text(intro1))
				break;
			wrboard();
			if (i = text(intro2))
				break;
		
		case 3:
			if (i = text(moves))
				break;
		
		case 4:
			if (i = text(remove))
				break;
		
		case 5:
			if (i = text(hits))
				break;
		
		case 6:
			if (i = text(endgame))
				break;
		
		case 7:
			if (i = text(doubl))
				break;
		
		case 8:
			if (i = text(stragy))
				break;
		
		case 9:
			if (i = text(prog))
				break;
		
		case 10:
			if (i = text(lastch))
				break;
		}
	tutor();
}

leave()  {
	if (tflag)
		clear();
	else
		writec ('\n');
	fixtty(old);
	execl (EXEC,"backgammon",args,"n",0);
	writel ("Help! Backgammon program is missing\007!!\n");
	exit (-1);
}
E 1
