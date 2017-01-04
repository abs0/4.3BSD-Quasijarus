h44664
s 00016/00001/00050
d D 5.1 85/05/31 09:39:30 dist 3 2
c Add copyright
e
s 00001/00000/00050
d D 4.2 81/11/08 13:19:24 root 2 1
c return reasonable exit status
e
s 00050/00000/00000
d D 4.1 80/10/16 06:07:06 root 1 0
c date and time created 80/10/16 06:07:06 by root
e
u
U
t
T
I 1
D 3
static	char *sccsid = "%W% (Berkeley) %G%";
E 3
I 3
/*
 * Copyright (c) 1980, 1988 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980, 1988 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 3
#include <stdio.h>

/*
 * what
 */

char	*infile = "Standard input";

main(argc, argv)
	int argc;
	char *argv[];
{

	argc--, argv++;
	do {
		if (argc > 0) {
			if (freopen(argv[0], "r", stdin) == NULL) {
				perror(argv[0]);
				exit(1);
			}
			infile = argv[0];
			printf("%s\n", infile);
			argc--, argv++;
		}
		fseek(stdin, (long) 0, 0);
		find();
	} while (argc > 0);
I 2
	exit(0);
E 2
}

find()
{
	static char buf[BUFSIZ];
	register char *cp;
	register int c, cc;
	register char *pat;

contin:
	while ((c = getchar()) != EOF)
		if (c == '@') {
			for (pat = "(#)"; *pat; pat++)
				if ((c = getchar()) != *pat)
					goto contin;
			putchar('\t');
			while ((c = getchar()) != EOF && c && c != '"' &&
			    c != '>' && c != '\n')
				putchar(c);
			putchar('\n');
		}
}
E 1
