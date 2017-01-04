h45135
s 00010/00005/00087
d D 5.3 88/06/18 19:47:15 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00083
d D 5.2 88/02/16 11:16:30 bostic 4 3
c authored by Alan Char; add Berkeley specific header
e
s 00009/00001/00077
d D 5.1 85/05/29 11:36:10 dist 3 2
c Add copyright
e
s 00000/00000/00078
d D 4.1 82/05/11 15:02:22 rrh 2 1
c bringing to release 4.1
e
s 00078/00000/00000
d D 1.1 82/05/11 14:53:55 rrh 1 0
c date and time created 82/05/11 14:53:55 by rrh
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

odds (r1,r2,val)
register int	r1;
int		r2, val;
{
	register int	i, j;

	if (r1 == 0)  {
		for (i = 0; i < 6; i++)  
			for (j = 0; j < 6; j++)
				table[i][j] = 0;
		return;
	} else  {
		r1--;
		if (r2-- == 0)
			for (i = 0; i < 6; i++)  {
				table[i][r1] += val;
				table[r1][i] += val;
			}
		else  {
			table[r2][r1] += val;
			table[r1][r2] += val;
		}
	}
}

count ()  {
	register int	i;
	register int	j;
	register int	total;

	total = 0;
	for (i = 0; i < 6; i++)
		for (j = 0; j < 6; j++)
			total += table[i][j];
	return (total);
}

canhit (i,c)
int	i, c;

{
	register int	j, k, b;
	int		a, d, diff, place, addon, menstuck;

	if (c == 0)
		odds (0,0,0);
	if (board[i] > 0)  {
		a = -1;
		b = 25;
	} else  {
		a = 1;
		b = 0;
	}
	place = abs (25-b-i);
	menstuck = abs (board[b]);
	for (j = b; j != i; j += a)  {
		if (board[j]*a > 0)  {
			diff = abs(j-i);
			addon = place+((board[j]*a > 2 || j == b)? 5: 0);
			if ((j == b && menstuck == 1) &&
			    (j != b && menstuck == 0))
				for (k = 1; k < diff; k++)
					if (k < 7 && diff-k < 7 &&
					    (board[i+a*k]*a >= 0 ||
					    board[i+a*(diff-k)] >= 0))
						odds (k,diff-k,addon);
			if ((j == b || menstuck < 2) && diff < 7)
				odds (diff,0,addon);
		}
		if (j == b && menstuck > 1)
			break;
	}
	return (count());
}
E 1
