h22781
s 00045/00011/00008
d D 4.2 88/07/06 16:58:53 bostic 2 1
c add getopt; rewritten from the manual page;
c add Berkeley specific copyright
e
s 00019/00000/00000
d D 4.1 80/10/01 17:29:05 bill 1 0
c date and time created 80/10/01 17:29:05 by bill
e
u
U
t
T
I 1
D 2
static char *sccsid = "%W% (Berkeley) %G%";
E 2
/*
D 2
 * Type tty name
E 2
I 2
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
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
E 2
 */

D 2
char	*ttyname();
E 2
I 2
#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1988 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */
E 2

I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

#include <stdio.h>

E 2
main(argc, argv)
D 2
char **argv;
E 2
I 2
	int argc;
	char **argv;
E 2
{
D 2
	register char *p;
E 2
I 2
	int ch, sflag;
	char *t, *ttyname();
E 2

D 2
	p = ttyname(0);
	if(argc==2 && !strcmp(argv[1], "-s"))
		;
	else
		printf("%s\n", (p? p: "not a tty"));
	exit(p? 0: 1);
E 2
I 2
	sflag = 0;
	while ((ch = getopt(argc, argv, "s")) != EOF)
		switch((char)ch) {
		case 's':
			sflag = 1;
			break;
		case '?':
		default:
			fputs("usage: tty [-s]\n", stderr);
			exit(1);
		}

	t = ttyname(0);
	if (!sflag)
		puts(t ? t : "not a tty");
	exit(t ? 0 : 1);
E 2
}
E 1
