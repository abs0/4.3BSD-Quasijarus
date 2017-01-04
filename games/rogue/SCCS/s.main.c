h07575
s 00043/00000/00000
d D 5.1 87/11/25 15:24:43 bostic 1 0
c from Tim Stoehr
e
u
U
t
T
I 1
/*
 * main.c
 *
 * This source herein may be modified and/or distributed by anybody who
 * so desires, with the following restrictions:
 *    1.)  No portion of this notice shall be removed.
 *    2.)  Credit shall not be taken for the creation of this source.
 *    3.)  This code is not to be traded, sold, or used for personal
 *         gain or profit.
 *
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

#include "rogue.h"

extern short party_room;

main(argc, argv)
int argc;
char *argv[];
{
	if (init(argc, argv)) {		/* restored game */
		goto PL;
	}

	for (;;) {
		clear_level();
		make_level();
		put_objects();
		put_stairs();
		add_traps();
		put_mons();
		put_player(party_room);
		print_stats(STAT_ALL);
PL:		
		play_level();
		free_stuff(&level_objects);
		free_stuff(&level_monsters);
	}
}
E 1
