h18960
s 00010/00005/00129
d D 5.3 88/06/18 19:47:32 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00125
d D 5.2 88/02/16 11:16:53 bostic 4 3
c authored by Alan Char; add Berkeley specific header
e
s 00009/00001/00119
d D 5.1 85/05/29 11:40:26 dist 3 2
c Add copyright
e
s 00000/00000/00120
d D 4.1 82/05/11 15:02:59 rrh 2 1
c bringing to release 4.1
e
s 00120/00000/00000
d D 1.1 82/05/11 14:54:44 rrh 1 0
c date and time created 82/05/11 14:54:44 by rrh
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

#include "back.h"
#include "tutor.h"

extern int	maxmoves;
extern char	*finis[];

extern struct situatn	test[];

static char	better[] = "That is a legal move, but there is a better one.\n";

tutor ()  {
	register int	i, j;

	i = 0;
	begscr = 18;
	cturn = -1;
	home = 0;
	bar = 25;
	inptr = &in[0];
	inopp = &in[1];
	offptr = &off[0];
	offopp = &off[1];
	Colorptr = &color[0];
	colorptr = &color[2];
	colen = 5;
	wrboard();

	while (1)  {
		if (! brdeq(test[i].brd,board))  {
			if (tflag && curr == 23)
				curmove (18,0);
			writel (better);
			nexturn();
			movback (mvlim);
			if (tflag)  {
				refresh();
				clrest ();
			}
			if ((! tflag) || curr == 19)  {
				proll();
				writec ('\t');
			}
			else
				curmove (curr > 19? curr-2: curr+4,25);
			getmove();
			if (cturn == 0)
				leave();
			continue;
		}
		if (tflag)
			curmove (18,0);
		text (*test[i].com);
		if (! tflag)
			writec ('\n');
		if (i == maxmoves)
			break;
		D0 = test[i].roll1;
		D1 = test[i].roll2;
		d0 = 0;
		mvlim = 0;
		for (j = 0; j < 4; j++)  {
			if (test[i].mp[j] == test[i].mg[j])
				break;
			p[j] = test[i].mp[j];
			g[j] = test[i].mg[j];
			mvlim++;
		}
		if (mvlim)
			for (j = 0; j < mvlim; j++)
				if (makmove(j))
					writel ("AARGH!!!\n");
		if (tflag)
			refresh();
		nexturn();
		D0 = test[i].new1;
		D1 = test[i].new2;
		d0 = 0;
		i++;
		mvlim = movallow();
		if (mvlim)  {
			if (tflag)
				clrest();
			proll();
			writec('\t');
			getmove();
			if (tflag)
				refresh();
			if (cturn == 0)
				leave();
		}
	}
	leave();
}

clrest ()  {
	register int	r, c, j;

	r = curr;
	c = curc;
	for (j = r+1; j < 24; j++)  {
		curmove (j,0);
		cline();
	}
	curmove (r,c);
}

brdeq (b1,b2)
register int  *b1, *b2;

{
	register int  *e;

	e = b1+26;
	while (b1 < e)
		if (*b1++ != *b2++)
			return(0);
	return(1);
}
E 1
