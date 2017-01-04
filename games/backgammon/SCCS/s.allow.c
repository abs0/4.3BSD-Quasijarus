h30369
s 00010/00005/00083
d D 5.3 88/06/18 19:46:55 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00079
d D 5.2 88/02/16 11:16:14 bostic 4 3
c authored by Alan Char; add Berkeley specific header
e
s 00009/00001/00073
d D 5.1 85/05/29 11:29:28 dist 3 2
c Add copyright
e
s 00000/00000/00074
d D 4.1 82/05/11 15:01:28 rrh 2 1
c bringing to release 4.1
e
s 00074/00000/00000
d D 1.1 82/05/11 14:52:58 rrh 1 0
c date and time created 82/05/11 14:52:58 by rrh
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

movallow ()  {

	register int	i, m, iold;
	int		r;

	if (d0)
		swap;
	m = (D0 == D1? 4: 2);
	for (i = 0; i < 4; i++)
		p[i] = bar;
	i = iold = 0;
	while (i < m)  {
		if (*offptr == 15)
			break;
		h[i] = 0;
		if (board[bar])  {
			if (i == 1 || m == 4)
				g[i] = bar+cturn*D1;
			else
				g[i] = bar+cturn*D0;
			if (r = makmove(i))  {
				if (d0 || m == 4)
					break;
				swap;
				movback (i);
				if (i > iold)
					iold = i;
				for (i = 0; i < 4; i++)
					p[i] = bar;
				i = 0;
			} else
				i++;
			continue;
		}
		if ((p[i] += cturn) == home)  {
			if (i > iold)
				iold = i;
			if (m == 2 && i)  {
				movback(i);
				p[i--] = bar;
				if (p[i] != bar)
					continue;
				else
					break;
			}
			if (d0 || m == 4)
				break;
			swap;
			movback (i);
			for (i = 0; i < 4; i++)
				p[i] = bar;
			i = 0;
			continue;
		}
		if (i == 1 || m == 4)
			g[i] = p[i]+cturn*D1;
		else
			g[i] = p[i]+cturn*D0;
		if (g[i]*cturn > home)  {
			if (*offptr >= 0)
				g[i] = home;
			else
				continue;
		}
		if (board[p[i]]*cturn > 0 && (r = makmove(i)) == 0)
			i++;
	}
	movback (i);
	return (iold > i? iold: i);
}
E 1
