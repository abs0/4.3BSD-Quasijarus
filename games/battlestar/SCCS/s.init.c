h37624
s 00010/00005/00103
d D 5.2 88/06/19 14:11:18 bostic 5 4
c install approved copyright notice
e
s 00011/00005/00097
d D 5.1 88/05/08 15:49:44 bostic 4 3
c add Berkeley header; yank to 5.1
e
s 00006/00000/00096
d D 1.3 85/04/24 15:31:10 edward 3 2
c copyright messages
e
s 00011/00007/00085
d D 1.2 84/11/28 18:30:31 edward 2 1
c Dave's changes
e
s 00092/00000/00000
d D 1.1 84/11/18 18:59:05 edward 1 0
c date and time created 84/11/18 18:59:05 by edward
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
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 4

#include "externs.h"
#include <pwd.h>

initialize(startup)
	char startup;
{
	register struct objs *p;
	int die();

	puts("Version 4.2, fall 1984.");
	puts("First Adventure game written by His Lordship, the honorable");
	puts("Admiral D.W. Riggle\n");
	srand(getpid());
	getutmp(uname);
	wiz = wizard(uname);
	wordinit();
	if (startup) {
		location = dayfile;
		direction = NORTH;
		time = 0;
		snooze = CYCLE * 1.5;
		position = 22;
		setbit(wear, PAJAMAS);
		fuel = TANKFULL;
		torps = TORPEDOES;
		for (p = dayobjs; p->room != 0; p++)
			setbit(location[p->room].objects, p->obj);
	} else
		restore();
	signal(SIGINT, die);
}

getutmp(uname)
	char *uname;
{
	struct passwd *ptr;

	ptr = getpwuid(getuid());
	strcpy(uname, ptr ? ptr->pw_name : "");
}

D 2
char *list[] = {
E 2
I 2
char *list[] = {	/* hereditary wizards */
E 2
	"riggle",
	"chris",
D 2
	"caro",
E 2
	"edward",
D 2
	"chin",
	"ervin-tr",
E 2
	"comay",
D 2
	"conde",
E 2
I 2
	"yee",
	"dmr",
	"ken",
E 2
	0
};

D 2
char *badguys[] = 0;
E 2
I 2
char *badguys[] = {
	"wnj",
	"root",
	"ted",
	0
};
E 2

wizard(uname)
	char *uname;
{
	char flag;

	if (flag = checkout(uname))
		printf("You are the Great wizard %s.\n", uname);
	return flag;
}

checkout(uname)
	register char *uname;
{
	register char **ptr;

	for (ptr = list; *ptr; ptr++)
		if (strcmp(*ptr, uname) == 0)
			return 1;
	for (ptr = badguys; *ptr; ptr++)
		if (strcmp(*ptr, uname) == 0) {
			printf("You are the Poor anti-wizard %s.  Good Luck!\n",
				uname);
			CUMBER = 3;
D 2
			WEIGHT = 9;	/* that'l get him */
E 2
I 2
			WEIGHT = 9;	/* that'll get him! */
E 2
			clock = 10;
			setbit(location[7].objects, WOODSMAN);	/* viper room */
			setbit(location[20].objects, WOODSMAN);	/* laser " */
			setbit(location[13].objects, DARK);	/* amulet " */
			setbit(location[8].objects, ELF);	/* closet */
			return 0;	/* anything else, Chris? */
		}
	return 0;
}
E 1
