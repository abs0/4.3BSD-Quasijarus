h34527
s 00010/00005/00282
d D 5.3 88/06/18 19:47:23 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00278
d D 5.2 88/02/16 11:16:40 bostic 4 3
c authored by Alan Char; add Berkeley specific header
e
s 00009/00001/00272
d D 5.1 85/05/29 11:38:00 dist 3 2
c Add copyright
e
s 00000/00000/00273
d D 4.1 82/05/11 15:02:40 rrh 2 1
c bringing to release 4.1
e
s 00273/00000/00000
d D 1.1 82/05/11 14:54:16 rrh 1 0
c date and time created 82/05/11 14:54:16 by rrh
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

char	*help2[] = {
	"   Enter moves as <s>-<f> or <s>/<r> where <s> is the starting",
	"position, <f> is the finishing position, and <r> is the roll.",
	"Remember, each die roll must be moved separately.",
	0
};

struct state	{
	char	ch;
	int	fcode;
	int	newst;
};

struct state	atmata[] = {

	'R', 1, 0,	'?', 7, 0,	'Q', 0, -3,	'B', 8, 25,
	'9', 2, 25,	'8', 2, 25,	'7', 2, 25,	'6', 2, 25,
	'5', 2, 25,	'4', 2, 25,	'3', 2, 25,	'2', 2, 19,
	'1', 2, 15,	'0', 2, 25,	'.', 0, 0,	'9', 2, 25,
	'8', 2, 25,	'7', 2, 25,	'6', 2, 25,	'5', 2, 25,

	'4', 2, 25,	'3', 2, 25,	'2', 2, 25,	'1', 2, 25,
	'0', 2, 25,	'/', 0, 32,	'-', 0, 39,	'.', 0, 0,
	'/', 5, 32,	' ', 6, 3,	',', 6, 3,	'\n', 0, -1,
	'6', 3, 28,	'5', 3, 28,	'4', 3, 28,	'3', 3, 28,
	'2', 3, 28,	'1', 3, 28,	'.', 0, 0,	'H', 9, 61,

	'9', 4, 61,	'8', 4, 61,	'7', 4, 61,	'6', 4, 61,
	'5', 4, 61,	'4', 4, 61,	'3', 4, 61,	'2', 4, 53,
	'1', 4, 51,	'0', 4, 61,	'.', 0, 0,	'9', 4, 61,
	'8', 4, 61,	'7', 4, 61,	'6', 4, 61,	'5', 4, 61,
	'4', 4, 61,	'3', 4, 61,	'2', 4, 61,	'1', 4, 61,

	'0', 4, 61,	' ', 6, 3,	',', 6, 3,	'-', 5, 39,
	'\n', 0, -1,	'.', 0, 0
};

checkmove (ist)

int	ist;

{
	register int	j, n;
	register char	c;
	char		a;

domove:
	if (ist == 0)  {
		if (tflag)
			curmove (curr,32);
		else
			writel ("\t\t");
		writel ("Move:  ");
	}
	ist = mvl = ncin = 0;
	for (j = 0; j < 5; j++)
		p[j] = g[j] = -1;

dochar:
	c = readc();

	if (c == 'S')  {
		raflag = 0;
		save (1);
		if (tflag)  {
			curmove (cturn == -1? 18: 19,39);
			ist = -1;
			goto domove;
		} else  {
			proll ();
			ist = 0;
			goto domove;
		}
	}

	if (c == tty.sg_erase && ncin > 0)  {
		if (tflag)
			curmove (curr,curc-1);
		else  {
			if (tty.sg_erase == '\010')
				writel ("\010 \010");
			else
				writec (cin[ncin-1]);
		}
		ncin--;
		n = rsetbrd();
		if (n == 0)  {
			n = -1;
			if (tflag)
				refresh();
		}
		if ((ist = n) > 0)
			goto dochar;
		goto domove;
	}

	if (c == tty.sg_kill && ncin > 0)  {
		if (tflag)  {
			refresh();
			curmove (curr,39);
			ist = -1;
			goto domove;
		} else  if (tty.sg_erase == '\010')  {
			for (j = 0; j < ncin; j++)
				writel ("\010 \010");
			ist = -1;
			goto domove;
		} else  {
			writec ('\\');
			writec ('\n');
			proll ();
			ist = 0;
			goto domove;
		}
	}

	n = dotable(c,ist);
	if (n >= 0)  {
		cin[ncin++] = c;
		if (n > 2)
		if ((! tflag) || c != '\n')
			writec (c);
		ist = n;
		if (n)
			goto dochar;
		else
			goto domove;
	}

	if (n == -1 && mvl >= mvlim)
		return(0);
	if (n == -1 && mvl < mvlim-1)
		return(-4);

	if (n == -6)  {
		if (! tflag)  {
			if (movokay(mvl+1))  {
				wrboard();
				movback (mvl+1);
			}
			proll ();
			writel ("\t\tMove:  ");
			for (j = 0; j < ncin;)
				writec (cin[j++]);
		} else  {
			if (movokay(mvl+1))  {
				refresh();
				movback (mvl+1);
			} else
				curmove (cturn == -1? 18:19,ncin+39);
		}
		ist = n = rsetbrd();
		goto dochar;
	}

	if (n != -5)
		return(n);
	writec ('\007');
	goto dochar;
}

dotable (c,i)
char		c;
register int	i;

{
	register int	a, j;
	int		test;

	test = (c == 'R');

	while ( (a = atmata[i].ch) != '.')  {
		if (a == c || (test && a == '\n'))  {
			switch  (atmata[i].fcode)  {

			case 1:
				wrboard();
				if (tflag)  {
					curmove (cturn == -1? 18: 19,0);
					proll ();
					writel ("\t\t");
				} else
					proll ();
				break;

			case 2:
				if (p[mvl] == -1)
					p[mvl] = c-'0';
				else
					p[mvl] = p[mvl]*10+c-'0';
				break;

			case 3:
				if (g[mvl] != -1)  {
					if (mvl < mvlim)
						mvl++;
					p[mvl] = p[mvl-1];
				}
				g[mvl] = p[mvl]+cturn*(c-'0');
				if (g[mvl] < 0)
					g[mvl] = 0;
				if (g[mvl] > 25)
					g[mvl] = 25;
				break;

			case 4:
				if (g[mvl] == -1)
					g[mvl] = c-'0';
				else
					g[mvl] = g[mvl]*10+c-'0';
				break;

			case 5:
				if (mvl < mvlim)
					mvl++;
				p[mvl] = g[mvl-1];
				break;

			case 6:
				if (mvl < mvlim)
					mvl++;
				break;

			case 7:
				if (tflag)
					curmove (20,0);
				else
					writec ('\n');
				text (help2);
				if (tflag)  {
					curmove (cturn == -1? 18: 19,39);
				} else  {
					writec ('\n');
					proll();
					writel ("\t\tMove:  ");
				}
				break;

			case 8:
				p[mvl] = bar;
				break;

			case 9:
				g[mvl] = home;
			}

			if (! test || a != '\n')
				return (atmata[i].newst);
			else
				return (-6);
		}

		i++;
	}

	return (-5);
}

rsetbrd ()  {
	register int	i, j, n;

	n = 0;
	mvl = 0;
	for (i = 0; i < 4; i++)
		p[i] = g[i] = -1;
	for (j = 0; j < ncin; j++)
		n = dotable (cin[j],n);
	return (n);
}
E 1
