h07121
s 00011/00006/00059
d D 5.2 88/06/18 14:55:14 bostic 2 1
c install approved copyright notice
e
s 00065/00000/00000
d D 5.1 88/01/02 20:53:32 bostic 1 0
c date and time created 88/01/02 20:53:32 by bostic
e
u
U
t
T
I 1
/*
D 2
 * Copyright (c) 1987 Regents of the University of California.
E 2
I 2
 * Copyright (c) 1980 Regents of the University of California.
E 2
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 2
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 2
I 2
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
E 2
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

# include	"monop.ext"

static char	*perc[]	= {
	"10%", "ten percent", "%", "$200", "200", 0
	};

inc_tax() {			/* collect income tax			*/

	reg int	worth, com_num;

	com_num = getinp("Do you wish to lose 10%% of your total worth or $200? ", perc);
	worth = cur_p->money + prop_worth(cur_p);
	printf("You were worth $%d", worth);
	worth /= 10;
	if (com_num > 2) {
		if (worth < 200)
			printf(".  Good try, but not quite.\n");
		else if (worth > 200)
			lucky(".\nGood guess.  ");
		cur_p->money -= 200;
	}
	else {
		printf(", so you pay $%d", worth);
		if (worth > 200)
			printf("  OUCH!!!!.\n");
		else if (worth < 200)
			lucky("\nGood guess.  ");
		cur_p->money -= worth;
	}
	if (worth == 200)
		lucky("\nIt makes no difference!  ");
}
goto_jail() {			/* move player to jail			*/

	cur_p->loc = JAIL;
}
lux_tax() {			/* landing on luxury tax		*/

	printf("You lose $75\n");
	cur_p->money -= 75;
}
cc() {				/* draw community chest card		*/

	get_card(&CC_D);
}
chance() {			/* draw chance card			*/

	get_card(&CH_D);
}
E 1
