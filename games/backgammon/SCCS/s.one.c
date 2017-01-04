h32833
s 00010/00005/00143
d D 5.3 88/06/18 19:47:17 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00139
d D 5.2 88/02/16 11:16:32 bostic 4 3
c authored by Alan Char; add Berkeley specific header
e
s 00009/00001/00133
d D 5.1 85/05/29 11:36:34 dist 3 2
c Add copyright
e
s 00000/00000/00134
d D 4.1 82/05/11 15:02:25 rrh 2 1
c bringing to release 4.1
e
s 00134/00000/00000
d D 1.1 82/05/11 14:53:58 rrh 1 0
c date and time created 82/05/11 14:53:58 by rrh
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

makmove (i)
register int	i;
 
{
	register int	n, d;
	int		max;

	d = d0;
	n = abs(g[i]-p[i]);
	max = (*offptr < 0? 7: last());
	if (board[p[i]]*cturn <= 0)
		return (checkd(d)+2);
	if (g[i] != home && board[g[i]]*cturn < -1)
		return (checkd(d)+3);
	if (i || D0 == D1)  {
		if (n == max? D1 < n: D1 != n)
			return (checkd(d)+1);
	} else  {
		if (n == max? D0 < n && D1 < n: D0 != n && D1 != n)
			return (checkd(d)+1);
		if (n == max? D0 < n: D0 != n)  {
			if (d0)
				return (checkd(d)+1);
			swap;
		}
	}
	if (g[i] == home && *offptr < 0)
		return (checkd(d)+4);
	h[i] = 0;
	board[p[i]] -= cturn;
	if (g[i] != home)  {
		if (board[g[i]] == -cturn)  {
			board[home] -= cturn;
			board[g[i]] = 0;
			h[i] = 1;
			if (abs(bar-g[i]) < 7)  {
				(*inopp)--;
				if (*offopp >= 0)
					*offopp -= 15;
			}
		}
		board[g[i]] += cturn;
		if (abs(home-g[i]) < 7 && abs(home-p[i]) > 6)  {
			(*inptr)++;
			if (*inptr+*offptr == 0)
				*offptr += 15;
		}
	} else {
		(*offptr)++;
		(*inptr)--;
	}
	return (0);
}

moverr (i)
register int	i;

{
	register int	j;

	if (tflag)
		curmove (20,0);
	else
		writec ('\n');
	writel ("Error:  ");
	for (j = 0; j <= i; j++)  {
		wrint (p[j]);
		writec ('-');
		wrint (g[j]);
		if (j < i)
			writec (',');
	}
	writel ("... ");
	movback (i);
}


checkd (d)
register int	d;

{
	if (d0 != d)
		swap;
	return (0);
}

last ()  {
	register int	i;

	for (i = home-6*cturn; i != home; i += cturn)
		if (board[i]*cturn > 0)
			return (abs(home-i));
}

movback (i)
register int	i;

{
	register int	j;

	for (j = i-1; j >= 0; j--)
		backone(j);
}

backone (i)
register int	i;

{
	board[p[i]] += cturn;
	if (g[i] != home)  {
		board[g[i]] -= cturn;
		if (abs(g[i]-home) < 7 && abs(p[i]-home) > 6)  {
			(*inptr)--;
			if (*inptr+*offptr < 15 && *offptr >= 0)
				*offptr -= 15;
		}
	} else  {
		(*offptr)--;
		(*inptr)++;
	}
	if (h[i])  {
		board[home] += cturn;
		board[g[i]] = -cturn;
		if (abs(bar-g[i]) < 7)  {
			(*inopp)++;
			if (*inopp+*offopp == 0)
				*offopp += 15;
		}
	}
}
E 1
