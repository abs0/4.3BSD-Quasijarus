h57981
s 00010/00005/00089
d D 5.4 88/06/18 20:04:47 bostic 4 3
c install approved copyright notice
e
s 00009/00003/00085
d D 5.3 88/03/09 11:18:44 bostic 3 2
c Written by Ken Arnold; add Berkeley specific copyright
e
s 00002/00000/00086
d D 5.2 85/09/23 13:19:04 mckusick 2 1
c initialization bug (from muller@nprdc.arpa)
e
s 00086/00000/00000
d D 5.1 85/05/30 18:35:28 mckusick 1 0
c date and time created 85/05/30 18:35:28 by mckusick
e
u
U
t
T
I 1
/*
 * Copyright (c) 1980 Regents of the University of California.
D 3
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
I 3
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 4
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 4
I 4
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
E 4
E 3
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif not lint
E 3
I 3
#endif /* not lint */
E 3

# include	"robots.h"

/*
 * play_level:
 *	Let the player play the current level
 */
play_level()
{
	register COORD	*cp;
	register int	y, x, bonus;

	move(My_pos.y, My_pos.x);
	addch(PLAYER);
	refresh();
	for (cp = Robots; cp < &Robots[MAXROBOTS]; cp++) {
I 2
		if (cp->y < 0)
			continue;
E 2
		move(cp->y, cp->x);
		addch(ROBOT);
	}
	refresh();
# ifdef DEBUG
	standout();
	move(Min.y, Min.x);
	addch(inch());
	move(Max.y, Max.x);
	addch(inch());
	standend();
# endif DEBUG
	setjmp(End_move);
	flush_in();
	while (!Dead && Num_robots > 0) {
		move(My_pos.y, My_pos.x);
		if (!jumping())
			refresh();
		get_move();
		if (Real_time)
			alarm(0);
		if (Field[My_pos.y][My_pos.x] != 0)
			Dead = TRUE;
		if (!Dead)
			move_robots(FALSE);
		if (Was_bonus) {
			move(Y_PROMPT, X_PROMPT);
			clrtoeol();
			move(Y_PROMPT + 1, X_PROMPT);
			clrtoeol();
			Was_bonus = FALSE;
		}
	}

	/*
	 * if the player didn't die, add on the possible bonuses
	 */

	if (!Dead) {
		Was_bonus = FALSE;

		if (Level == Start_level && Start_level > 1) {
			move(Y_PROMPT, X_PROMPT);
			printw("Advance bonus: %d", S_BONUS);
			refresh();
			add_score(S_BONUS);
			Was_bonus = TRUE;
		}

		if (Wait_bonus != 0) {
			if (!Was_bonus)
				move(Y_PROMPT, X_PROMPT);
			else
				move(Y_PROMPT + 1, X_PROMPT);
			printw("Wait bonus: %d", Wait_bonus);
			refresh();
			add_score(Wait_bonus);
			Was_bonus = TRUE;
		}
	}
}
E 1
