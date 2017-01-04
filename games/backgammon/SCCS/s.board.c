h45159
s 00010/00005/00150
d D 5.3 88/06/18 19:46:58 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00146
d D 5.2 88/02/16 11:16:18 bostic 4 3
c authored by Alan Char; add Berkeley specific header
e
s 00009/00001/00140
d D 5.1 85/05/29 11:30:47 dist 3 2
c Add copyright
e
s 00000/00000/00141
d D 4.1 82/05/11 15:01:39 rrh 2 1
c bringing to release 4.1
e
s 00141/00000/00000
d D 1.1 82/05/11 14:53:03 rrh 1 0
c date and time created 82/05/11 14:53:03 by rrh
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

static int	i, j, k;
static char	ln[60];

wrboard ()  {
	register int	l;
	static char	bl[] =
		"|                       |   |                       |\n";
	static char	sv[] =
		"|                       |   |                       |    \n";

	fixtty (noech);
	clear();

	if (tflag)  {
		fboard();
		goto lastline;
	}

	writel ("_____________________________________________________\n");
	writel (bl);
	strcpy (ln,bl);
	for (j = 1; j < 50; j += 4) {
		k = j/4+(j > 24? 12: 13);
		ln[j+1] = k%10+'0';
		ln[j] = k/10+'0';
		if (j == 21)
			j += 4;
	}
	writel (ln);
	for (i = 0; i < 5; i++) {
		strcpy (ln,sv);
		for (j = 1; j < 50; j += 4) {
			k = j/4+(j > 24? 12: 13);
			wrbsub ();
			if (j == 21)
				j += 4;
		}
		if (-board[25] > i)
			ln[26] = 'w';
		if (-board[25] > i+5)
			ln[25] = 'w';
		if (-board[25] > i+10)
			ln[27] = 'w';
		l = 53;
		if (off[1] > i || (off[1] < 0 && off[1]+15 > i))  {
			ln[54] = 'r';
			l = 55;
		}
		if (off[1] > i+5 || (off[1] < 0 && off[1]+15 > i+5))  {
			ln[55] = 'r';
			l = 56;
		}
		if (off[1] > i+10 || (off[1] < 0 && off[1]+15 > i+10))  {
			ln[56] = 'r';
			l = 57;
		}
		ln[l++] = '\n';
		ln[l] = '\0';
		writel (ln);
	}
	strcpy (ln,bl);
	ln[25] = 'B';
	ln[26] = 'A';
	ln[27] = 'R';
	writel (ln);
	strcpy (ln,sv);
	for (i = 4; i > -1; i--) {
		for (j = 1; j < 50; j += 4) {
			k = ((j > 24? 53: 49)-j)/4;
			wrbsub();
			if (j == 21)
				j += 4;
		}
		if (board[0] > i)
			ln[26] = 'r';
		if (board[0] > i+5)
			ln[25] = 'r';
		if (board[0] > i+10)
			ln[27] = 'r';
		l = 53;
		if (off[0] > i || (off[0] < 0 && off[0]+15 > i))  {
			ln[54] = 'w';
			l = 55;
		}
		if (off[0] > i+5 || (off[0] < 0 && off[0]+15 > i+5))  {
			ln[55] = 'w';
			l = 56;
		}
		if (off[0] > i+10 || (off[0] < 0 && off[0]+15 > i+10))  {
			ln[56] = 'w';
			l = 57;
		}
		ln[l++] = '\n';
		ln[l] = '\0';
		writel (ln);
	}
	strcpy (ln,bl);
	for (j = 1; j < 50; j += 4) {
		k = ((j > 24? 53: 49)-j)/4;
		ln[j+1] = k%10+'0';
		if (k > 9)
			ln[j] = k/10+'0';
		if (j == 21)
			j += 4;
	}
	writel (ln);
	writel ("|_______________________|___|_______________________|\n");

lastline:
	gwrite ();
	if (tflag)
		curmove (18,0);
	else  {
		writec ('\n');
		writec ('\n');
	}
	fixtty(raw);
}

wrbsub () {
	register int	m;
	register char	d;

	if (board[k] > 0)  {
		m = board[k];
		d = 'r';
	} else {
		m = -board[k];
		d = 'w';
	}
	if (m>i)
		ln[j+1] = d;
	if (m>i+5)
		ln[j] = d;
	if (m>i+10)
		ln[j+2] = d;
}
E 1
