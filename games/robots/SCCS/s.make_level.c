h15582
s 00010/00005/00063
d D 5.3 88/06/18 20:04:42 bostic 3 2
c install approved copyright notice
e
s 00009/00003/00059
d D 5.2 88/03/09 11:18:39 bostic 2 1
c Written by Ken Arnold; add Berkeley specific copyright
e
s 00062/00000/00000
d D 5.1 85/05/30 18:34:28 mckusick 1 0
c date and time created 85/05/30 18:34:28 by mckusick
e
u
U
t
T
I 1
/*
 * Copyright (c) 1980 Regents of the University of California.
D 2
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 2
I 2
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 3
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 3
I 3
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
E 3
E 2
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 2
#endif not lint
E 2
I 2
#endif /* not lint */
E 2

# include	"robots.h"

/*
 * make_level:
 *	Make the current level
 */
make_level()
{
	register int	i;
	register COORD	*cp;
	register WINDOW	*wp;
	register int	x, *endp;

	reset_count();
	for (i = 1; i < Y_FIELDSIZE; i++)
		for (x = 1; x < X_FIELDSIZE; x++)
			if (Field[i][x] != 0)
				mvaddch(i, x, ' ');
	if (My_pos.y > 0)
		mvaddch(My_pos.y, My_pos.x, ' ');

	Waiting = FALSE;
	Wait_bonus = 0;
	leaveok(stdscr, FALSE);
	for (cp = Robots; cp < &Robots[MAXROBOTS]; cp++)
		cp->y = -1;
	My_pos.y = -1;

	bzero(Field, sizeof Field);
	Min.y = Y_FIELDSIZE;
	Min.x = X_FIELDSIZE;
	Max.y = 0;
	Max.x = 0;
	if ((i = Level * 10) > MAXROBOTS)
		i = MAXROBOTS;
	Num_robots = i;
	while (i-- > 0) {
		cp = rnd_pos();
		Robots[i] = *cp;
		Field[cp->y][cp->x]++;
		if (cp->y < Min.y)
			Min.y = cp->y;
		if (cp->x < Min.x)
			Min.x = cp->x;
		if (cp->y > Max.y)
			Max.y = cp->y;
		if (cp->x > Max.x)
			Max.x = cp->x;
	}
	My_pos = *rnd_pos();
	refresh();
}
E 1
