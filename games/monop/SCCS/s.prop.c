h20457
s 00011/00006/00184
d D 5.5 88/06/18 14:55:04 bostic 5 4
c install approved copyright notice
e
s 00005/00003/00185
d D 5.4 88/01/02 20:59:21 bostic 4 3
c John Gilmore's changes for ANSI C and general cleanup
e
s 00013/00001/00175
d D 5.3 88/01/02 20:51:28 bostic 3 2
c add Berkeley header
e
s 00001/00001/00175
d D 5.2 87/10/22 11:37:55 bostic 2 1
c ANSI C; sprintf now returns an int.
e
s 00176/00000/00000
d D 5.1 87/10/22 11:37:41 bostic 1 0
c date and time created 87/10/22 11:37:41 by bostic
e
u
U
t
T
I 3
/*
D 5
 * Copyright (c) 1987 Regents of the University of California.
E 5
I 5
 * Copyright (c) 1980 Regents of the University of California.
E 5
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
 */

E 3
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif not lint
E 3
I 3
#endif /* not lint */
E 3

# include	"monop.ext"

I 4
extern char *calloc();

E 4
/*
 *	This routine deals with buying property, setting all the
 * appropriate flags.
 */
buy(player, sqrp)
reg int		player;
reg SQUARE	*sqrp; {

	trading = FALSE;
	sqrp->owner = player;
	add_list(player, &(play[player].own_list), cur_p->loc);
}
/*
 *	This routine adds an item to the list.
 */
add_list(plr, head, op_sqr)
int	plr;
OWN	**head;
int	op_sqr; {

	reg int	val;
	reg OWN	*tp, *last_tp;
	MON	*mp;
	OWN	*op;

D 4
	op = calloc(1, sizeof (OWN));
E 4
I 4
	op = (OWN *)calloc(1, sizeof (OWN));
E 4
	op->sqr = &board[op_sqr];
	val = value(op->sqr);
	last_tp = NULL;
	for (tp = *head; tp && value(tp->sqr) < val; tp = tp->next)
		if (val == value(tp->sqr)) {
			cfree(op);
			return;
		}
		else
			last_tp = tp;
	op->next = tp;
	if (last_tp != NULL)
		last_tp->next = op;
	else
		*head = op;
	if (!trading)
		set_ownlist(plr);
}
/*
 *	This routine deletes property from the list.
 */
del_list(plr, head, op_sqr)
int	plr;
OWN	**head;
shrt	op_sqr; {

	reg int	i;
	reg OWN	*op, *last_op;

	switch (board[op_sqr].type) {
	  case PRPTY:
		board[op_sqr].desc->mon_desc->num_own--;
		break;
	  case RR:
		play[plr].num_rr--;
		break;
	  case UTIL:
		play[plr].num_util--;
		break;
	}
	last_op = NULL;
	for (op = *head; op; op = op->next)
		if (op->sqr == &board[op_sqr])
			break;
		else
			last_op = op;
	if (last_op == NULL)
		*head = op->next;
	else {
		last_op->next = op->next;
		cfree(op);
	}
}
/*
 *	This routine calculates the value for sorting of the
 * given square.
 */
value(sqp)
reg SQUARE	*sqp; {

	reg int	sqr;

	sqr = sqnum(sqp);
	switch (sqp->type) {
	  case SAFE:
		return 0;
D 4
	  case SPEC:
E 4
I 4
	  default:		/* Specials, etc */
E 4
		return 1;
	  case UTIL:
		if (sqr == 12)
			return 2;
		else
			return 3;
	  case RR:
		return 4 + sqr/10;
	  case PRPTY:
D 4
		return 8 + (PROP *)(sqp->desc) - prop;
E 4
I 4
		return 8 + (sqp->desc) - prop;
E 4
	}
}
/*
 *	This routine accepts bids for the current peice
 * of property.
 */
bid() {

	static bool	in[MAX_PL];
	reg int		i, num_in, cur_max;
	char		buf[80];
	int		cur_bid;

	printf("\nSo it goes up for auction.  Type your bid after your name\n");
	for (i = 0; i < num_play; i++)
		in[i] = TRUE;
	i = -1;
	cur_max = 0;
	num_in = num_play;
	while (num_in > 1 || (cur_max == 0 && num_in > 0)) {
		i = ++i % num_play;
		if (in[i]) {
			do {
D 2
				sprintf(buf, "%s: ", name_list[i]);
E 2
I 2
				(void)sprintf(buf, "%s: ", name_list[i]);
E 2
				cur_bid = get_int(buf);
				if (cur_bid == 0) {
					in[i] = FALSE;
					if (--num_in == 0)
						break;
				}
				else if (cur_bid <= cur_max) {
					printf("You must bid higher than %d to stay in\n", cur_max);
					printf("(bid of 0 drops you out)\n");
				}
			} while (cur_bid != 0 && cur_bid <= cur_max);
			cur_max = (cur_bid ? cur_bid : cur_max);
		}
	}
	if (cur_max != 0) {
		while (!in[i])
			i = ++i % num_play;
		printf("It goes to %s (%d) for $%d\n",play[i].name,i+1,cur_max);
		buy(i, &board[cur_p->loc]);
		play[i].money -= cur_max;
	}
	else
		printf("Nobody seems to want it, so we'll leave it for later\n");
}
/*
 *	This routine calculates the value of the property
 * of given player.
 */
prop_worth(plp)
reg PLAY	*plp; {

	reg OWN	*op;
	reg int	worth;

	worth = 0;
	for (op = plp->own_list; op; op = op->next) {
		if (op->sqr->type == PRPTY && op->sqr->desc->monop)
			worth += op->sqr->desc->mon_desc->h_cost * 50 *
			    op->sqr->desc->houses;
		worth += op->sqr->cost;
	}
	return worth;
}
E 1
