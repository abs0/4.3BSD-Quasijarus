h60022
s 00010/00005/00057
d D 5.3 88/06/27 16:33:38 bostic 3 2
c install approved copyright notice
e
s 00006/00002/00056
d D 5.2 88/02/08 16:09:32 bostic 2 1
c make ppt handle args, so it and bcd work the same way
e
s 00058/00000/00000
d D 5.1 88/02/08 14:02:00 bostic 1 0
c date and time created 88/02/08 14:02:00 by bostic
e
u
U
t
T
I 1
/*
 * Copyright (c) 1988 Regents of the University of California.
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
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 3
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1988 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

#include <stdio.h>

void	putppt();

D 2
/*ARGSUSED*/
E 2
main(argc, argv)
	int argc;
	char **argv;
{
	register int c;
I 2
	register char *p;
E 2

	(void) puts("___________");
D 2
	while ((c = getchar()) != EOF)
E 2
I 2
	if (argc > 1)
		while (p = *++argv)
			for (; *p; ++p)
				putppt((int)*p);
	else while ((c = getchar()) != EOF)
E 2
		putppt(c);
	(void) puts("___________");
	exit(0);
}

static void
putppt(c)
	register int c;
{
	register int i;

	(void) putchar('|');
	for (i = 7; i >= 0; i--) {
		if (i == 2)
			(void) putchar('.');	/* feed hole */
		if ((c&(1<<i)) != 0)
			(void) putchar('o');
		else
			(void) putchar(' ');
	}
	(void) putchar('|');
	(void) putchar('\n');
}
E 1
