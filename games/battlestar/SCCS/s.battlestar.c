h65236
s 00010/00005/00065
d D 5.2 88/06/19 14:10:45 bostic 5 4
c install approved copyright notice
e
s 00017/00005/00053
d D 5.1 88/05/08 15:49:10 bostic 4 3
c add Berkeley header; yank to 5.1
e
s 00013/00000/00045
d D 1.3 85/04/24 15:29:32 edward 3 2
c copyright messages
e
s 00001/00002/00044
d D 1.2 84/11/28 18:29:59 edward 2 1
c Dave's changes
e
s 00046/00000/00000
d D 1.1 84/11/18 18:58:52 edward 1 0
c date and time created 84/11/18 18:58:52 by edward
e
u
U
t
T
I 3
/*
D 4
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 4
I 4
 * Copyright (c) 1983 Regents of the University of California.
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

E 3
I 1
#ifndef lint
D 4
static char sccsid[] = "%W% %G%";
#endif
E 4
I 4
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 4
I 3

/*
 * Battlestar - a stellar-tropical adventure game
 *
 * Originally written by His Lordship, Admiral David W. Horatio Riggle,
 * on the Cory PDP-11/70, University of California, Berkeley.
 */
E 3

#include "externs.h"

main(argc,argv)
int  argc;
char **argv;
{
	char mainbuf[LINELENGTH];
	char *next;

	initialize(argc < 2 || strcmp(argv[1], "-r"));
start:
	news();
D 2
	if (!beenthere[position])
		beenthere[position] = 1;
E 2
I 2
	beenthere[position]++;
E 2
	if (notes[LAUNCHED])
		crash();		/* decrements fuel & crash */
	if (matchlight) {
		puts("Your match splutters out.");
		matchlight = 0;
	}
	if (!notes[CANTSEE] || testbit(inven,LAMPON) ||
	    testbit(location[position].objects, LAMPON)) {
		writedes();
		printobjs();
	} else
		puts("It's too dark to see anything in here!");
	whichway(location[position]);
run:
	next = getcom(mainbuf, sizeof mainbuf, ">-: ",
		"Please type in something.");
	for (wordcount = 0; next && wordcount < 20; wordcount++)
		next = getword(next, words[wordcount], -1);
	parse();
	switch (cypher()) {
		case -1:
			goto run;
		case 0:
			goto start;
		default:
			exit();
	}
}
E 1
