h47934
s 00016/00001/00109
d D 5.1 85/05/31 09:11:00 dist 4 3
c Add copyright
e
s 00000/00002/00110
d D 4.3 84/09/17 10:45:59 ralph 3 2
c don't call setbuf.
e
s 00001/00001/00111
d D 4.2 81/02/07 16:32:29 kre 2 1
c fix per kre
e
s 00112/00000/00000
d D 4.1 80/10/01 17:26:29 bill 1 0
c date and time created 80/10/01 17:26:29 by bill
e
u
U
t
T
I 1
D 4
static char *sccsid = "%W% (Berkeley) %G%";
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 4
#include <stdio.h>
/*
 * expand - expand tabs to equivalent spaces
 */
D 3
char	obuf[BUFSIZ];
E 3
int	nstops;
int	tabstops[100];

main(argc, argv)
	int argc;
	char *argv[];
{
	register int c, column;
	register int n;

D 3
	setbuf(stdout, obuf);
E 3
	argc--, argv++;
	do {
		while (argc > 0 && argv[0][0] == '-') {
			getstops(argv[0]);
			argc--, argv++;
		}
		if (argc > 0) {
			if (freopen(argv[0], "r", stdin) == NULL) {
				perror(argv[0]);
				exit(1);
			}
			argc--, argv++;
		}
		column = 0;
		for (;;) {
			c = getc(stdin);
			if (c == -1)
				break;
			switch (c) {

			case '\t':
				if (nstops == 0) {
					do {
						putchar(' ');
						column++;
					} while (column & 07);
					continue;
				}
				if (nstops == 1) {
					do {
						putchar(' ');
						column++;
					} while (((column - 1) % tabstops[0]) != (tabstops[0] - 1));
					continue;
				}
				for (n = 0; n < nstops; n++)
					if (tabstops[n] > column)
						break;
				if (n == nstops) {
					putchar(' ');
					column++;
					continue;
				}
				while (column < tabstops[n]) {
					putchar(' ');
					column++;
				}
				continue;

			case '\b':
				if (column)
					column--;
				putchar('\b');
				continue;

			default:
				putchar(c);
				column++;
				continue;

			case '\n':
				putchar(c);
				column = 0;
				continue;
			}
		}
	} while (argc > 0);
	exit(0);
}

getstops(cp)
	register char *cp;
{
	register int i;

	nstops = 0;
	cp++;
	for (;;) {
		i = 0;
		while (*cp >= '0' && *cp <= '9')
			i = i * 10 + *cp++ - '0';
		if (i <= 0 || i > 256) {
bad:
			fprintf(stderr, "Bad tab stop spec\n");
			exit(1);
		}
D 2
		if (nstops > 0 && i <= tabstops[nstops])
E 2
I 2
		if (nstops > 0 && i <= tabstops[nstops-1])
E 2
			goto bad;
		tabstops[nstops++] = i;
		if (*cp == 0)
			break;
		if (*cp++ != ',')
			goto bad;
	}
}
E 1
