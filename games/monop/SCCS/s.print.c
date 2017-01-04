h23349
s 00011/00006/00165
d D 5.3 88/06/18 14:55:02 bostic 3 2
c install approved copyright notice
e
s 00004/00003/00167
d D 5.2 88/01/02 20:59:19 bostic 2 1
c John Gilmore's changes for ANSI C and general cleanup
e
s 00170/00000/00000
d D 5.1 88/01/02 20:53:30 bostic 1 0
c date and time created 88/01/02 20:53:30 by bostic
e
u
U
t
T
I 1
/*
D 3
 * Copyright (c) 1987 Regents of the University of California.
E 3
I 3
 * Copyright (c) 1980 Regents of the University of California.
E 3
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
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

# include	"monop.ext"

static char	buf[80],		/* output buffer		*/
		*header	= "Name      Own      Price Mg # Rent";

/*
 *	This routine prints out the current board
 */
printboard() {

	reg int	i;

	printf("%s\t%s\n", header, header);
	for (i = 0; i < N_SQRS/2; i++) {
		printsq(i, FALSE);
		putchar('\t');
		printsq(i+N_SQRS/2, TRUE);
	}
}
/*
 *	This routine lists where each player is.
 */
where() {

	reg int	i;
	char	*bsp;

	printf("%s Player\n", header);
	for (i = 0; i < num_play; i++) {
		printsq(play[i].loc, FALSE);
		printf(" %s (%d)", play[i].name, i+1);
		if (cur_p == &play[i])
			printf(" *");
		putchar('\n');
	}
}
/*
 *	This routine prints out an individual square
 */
printsq(sqn, eoln)
int		sqn;
reg bool	eoln; {

	reg int		rnt;
	reg PROP	*pp;
	reg SQUARE	*sqp;
	int		i;

	sqp = &board[sqn];
	printf("%-10.10s", sqp->name);
D 2
	if (sqn == JAIL)
		goto spec;
E 2
	switch (sqp->type) {
	  case SAFE:
	  case CC:
	  case CHANCE:
D 2
	  case SPEC:
E 2
I 2
	  case INC_TAX:
	  case GOTO_J:
	  case LUX_TAX:
	  case IN_JAIL:
E 2
spec:
		if (!eoln)
			printf("                        ");
		break;
	  case PRPTY:
		pp = sqp->desc;
		if (sqp->owner < 0) {
			printf(" - %-8.8s %3d", pp->mon_desc->name, sqp->cost);
			if (!eoln)
				printf("         ");
			break;
		}
		printf(" %d %-8.8s %3d", sqp->owner+1, pp->mon_desc->name,
			sqp->cost);
		printmorg(sqp);
		if (pp->monop) {
			if (pp->houses < 5)
				if (pp->houses > 0)
					printf("%d %4d", pp->houses,
						pp->rent[pp->houses]);
				else
					printf("0 %4d", pp->rent[0] * 2);
			else
				printf("H %4d", pp->rent[5]);
		}
		else
			printf("  %4d", pp->rent[0]);
		break;
	  case UTIL:
		if (sqp->owner < 0) {
			printf(" -          150");
			if (!eoln)
				printf("         ");
			break;
		}
		printf(" %d          150", sqp->owner+1);
		printmorg(sqp);
		printf("%d", play[sqp->owner].num_util);
		if (!eoln)
			printf("    ");
		break;
	  case RR:
		if (sqp->owner < 0) {
			printf(" - Railroad 200");
			if (!eoln)
				printf("         ");
			break;
		}
		printf(" %d Railroad 200", sqp->owner+1);
		printmorg(sqp);
		rnt = 25;
		rnt <<= play[sqp->owner].num_rr - 1;
		printf("%d %4d", play[sqp->owner].num_rr, 25 << (play[sqp->owner].num_rr - 1));
		break;
	}
	if (eoln)
		putchar('\n');
}
/*
 *	This routine prints out the mortgage flag.
 */
printmorg(sqp)
reg SQUARE	*sqp; {

	if (sqp->desc->morg)
		printf(" * ");
	else
		printf("   ");
}
/*
 *	This routine lists the holdings of the player given
 */
printhold(pl)
reg int	pl; {

	reg OWN		*op;
	reg PLAY	*pp;
	char		*bsp;

	pp = &play[pl];
	printf("%s's (%d) holdings (Total worth: $%d):\n", name_list[pl], pl+1,
		pp->money + prop_worth(pp));
	printf("\t$%d", pp->money);
	if (pp->num_gojf) {
		printf(", %d get-out-of-jail-free card", pp->num_gojf);
		if (pp->num_gojf > 1)
			putchar('s');
	}
	putchar('\n');
	if (pp->own_list) {
		printf("\t%s\n", header);
		for (op = pp->own_list; op; op = op->next) {
			putchar('\t');
			printsq(sqnum(op->sqr), TRUE);
		}
	}
}
E 1
