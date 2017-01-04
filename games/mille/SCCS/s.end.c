h43734
s 00010/00005/00122
d D 5.3 88/06/18 19:38:19 bostic 3 2
c install approved copyright notice
e
s 00009/00003/00118
d D 5.2 87/12/29 17:10:07 bostic 2 1
c Berkeley header
e
s 00121/00000/00000
d D 5.1 86/11/26 13:34:19 bostic 1 0
c date and time created 86/11/26 13:34:19 by bostic
e
u
U
t
T
I 1
/*
 * Copyright (c) 1982 Regents of the University of California.
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

# include	"mille.h"

/*
 * @(#)end.c	1.1 (Berkeley) 4/1/82
 */

/*
 *	print out the score as if it was final, and add the totals for
 * the end-of-games points to the user who deserves it (if any).
 */
finalscore(pp)
reg PLAY	*pp; {

	reg int		temp, tot, num;

	if (pp->was_finished == Finished)
		return;

	pp->was_finished = Finished;
	num = pp - Player;
	temp = num * 6 + 21 + 1;
	for (tot = 5; tot <= 9; tot++)
		mvaddstr(tot, temp, "  0");
	if (pp->mileage == End) {
		mvaddstr(5, temp, "40");
		tot = SC_TRIP;
		if (pp->nummiles[C_200] == 0) {
			mvaddstr(6, temp, "30");
			tot = SC_TRIP + SC_SAFE;
		}
		if (Topcard <= Deck) {
			mvaddstr(7, temp, "30");
			tot += SC_DELAY;
		}
		if (End == 1000) {
			mvaddstr(8, temp, "20");
			tot += SC_EXTENSION;
		}
		if (Player[other(num)].mileage == 0) {
			mvaddstr(9, temp, "50");
			tot += SC_SHUT_OUT;
		}
		pp->total += tot;
		pp->hand_tot += tot;
	}
}

# ifdef EXTRAP
static int	Last_tot[2];	/* last tot used for extrapolate	*/

/*
 *	print out the score as if it was final, and add the totals for
 * the end-of-games points to the user who deserves it (if any).
 */
extrapolate(pp)
reg PLAY	*pp; {

	reg int		x, num, tot, count;

	num = pp - Player;
	tot += SC_TRIP + SC_DELAY + SC_EXT;
	x = num * 6 + 21 + 3;
	for (tot = 5; tot <= 9; tot++)
		mvaddch(tot, x, '0');
	x -= 2;
	pp = &Player[other(num)];
	for (count = 0, tot = 0; tot < NUM_SAFE; tot++)
		if (pp->safety[tot] != S_PLAYED)
			count += SC_SAFE;
	mvprintw(3, x, "%3d", count);
	tot += count;
	if (count == 400) {
		mvaddstr(4, x, "30");
		tot += SC_ALL_SAFE;
	}
	pp = &Player[num];
	for (count = 0, tot = 0; tot < NUM_SAFE; tot++)
		if (pp->safety[tot] != S_PLAYED)
			count += SC_COUP / 10;
	mvprintw(4, x - 1, "%3d", count);
	tot += count;
	tot += 1000 - pp->mileage;
	mvaddstr(5, x, "40");
	mvaddstr(7, x, "30");
	mvaddstr(8, x, "20");
	if (pp->nummiles[C_200] == 0) {
		mvaddstr(6, x, "30");
		tot = SC_TRIP + SC_SAFE;
	}
	if (Player[other(num)].mileage == 0) {
		mvaddstr(9, x, "50");
		tot += SC_SHUT_OUT;
	}
	pp->total += tot;
	pp->hand_tot += tot;
	Last_tot[num] = tot;
}

undoex() {

	reg PLAY	*pp;
	reg int		i;

	i = 0;
	for (pp = Player; pp < &Player[2]; pp++) {
		pp->total -= Last_tot[i];
		pp->hand_tot -= Last_tot[i++];
	}
}
# endif

E 1
