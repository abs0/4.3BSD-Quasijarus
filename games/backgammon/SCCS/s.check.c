h07828
s 00010/00005/00132
d D 5.3 88/06/18 19:47:00 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00128
d D 5.2 88/02/16 11:16:19 bostic 4 3
c authored by Alan Char; add Berkeley specific header
e
s 00009/00001/00122
d D 5.1 85/05/29 11:31:13 dist 3 2
c Add copyright
e
s 00000/00000/00123
d D 4.1 82/05/11 15:01:43 rrh 2 1
c bringing to release 4.1
e
s 00123/00000/00000
d D 1.1 82/05/11 14:53:08 rrh 1 0
c date and time created 82/05/11 14:53:08 by rrh
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

getmove ()  {
	register int	i, c;

	c = 0;
	for (;;)  {
		i = checkmove(c);

		switch (i)  {
		case -1:
			if (movokay(mvlim))  {
				if (tflag)
					curmove (20,0);
				else
					writec ('\n');
				for (i = 0; i < mvlim; i++)
					if (h[i])
						wrhit(g[i]);
				nexturn();
				if (*offopp == 15)
					cturn *= -2;
				if (tflag && pnum)
					bflag = pnum;
				return;
			}

		case -4:
		case 0:
			if (tflag)
				refresh();
			if (i != 0 && i != -4)
				break;
			if (tflag)
				curmove (20,0);
			else
				writec ('\n');
			writel (*Colorptr);
			if (i == -4)
				writel (" must make ");
			else
				writel (" can only make ");
			writec (mvlim+'0');
			writel (" move");
			if (mvlim > 1)
				writec ('s');
			writec ('.');
			writec ('\n');
			break;

		case -3:
			if (quit())
				return;
		}

		if (! tflag)
			proll ();
		else  {
			curmove (cturn == -1? 18: 19,39);
			cline ();
			c = -1;
		}
	}
}

movokay (mv)
register int	mv;

{
	register int	i, m;

	if (d0)
		swap;

	for (i = 0; i < mv; i++)  {

		if (p[i] == g[i])  {
			moverr (i);
			curmove (20,0);
			writel ("Attempt to move to same location.\n");
			return (0);
		}

		if (cturn*(g[i]-p[i]) < 0)  {
			moverr (i);
			curmove (20,0);
			writel ("Backwards move.\n");
			return (0);
		}

		if (abs(board[bar]) && p[i] != bar)  {
			moverr (i);
			curmove (20,0);
			writel ("Men still on bar.\n");
			return (0);
		}

		if ( (m = makmove(i)) )  {
			moverr (i);
			switch (m)  {

			case 1:
				writel ("Move not rolled.\n");
				break;

			case 2:
				writel ("Bad starting position.\n");
				break;

			case 3:
				writel ("Destination occupied.\n");
				break;

			case 4:
				writel ("Can't remove men yet.\n");
			}
			return (0);
		}
	}
	return (1);
}
E 1
