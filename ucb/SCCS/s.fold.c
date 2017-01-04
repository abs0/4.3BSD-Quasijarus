h30590
s 00015/00004/00104
d D 5.2 88/06/29 21:50:42 bostic 5 4
c install approved copyright notice
e
s 00016/00001/00092
d D 5.1 85/05/31 09:13:04 dist 4 3
c Add copyright
e
s 00000/00002/00093
d D 4.3 84/09/17 10:46:23 ralph 3 2
c don't call setbuf.
e
s 00003/00003/00092
d D 4.2 83/02/09 15:15:50 sam 2 1
c silence warningsd
e
s 00095/00000/00000
d D 4.1 80/10/01 17:26:49 bill 1 0
c date and time created 80/10/01 17:26:49 by bill
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
D 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
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
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 5
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
D 5
#endif not lint
E 5
I 5
#endif /* not lint */
E 5

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif not lint
E 5
I 5
#endif /* not lint */
E 5

E 4
#include <stdio.h>
/*
 * fold - fold long lines for finite output devices
 *
 * Bill Joy UCB June 28, 1977
 */

int	fold =  80;

main(argc, argv)
	int argc;
	char *argv[];
{
	register c;
	FILE *f;
D 3
	char obuf[BUFSIZ];
E 3

	argc--, argv++;
D 3
	setbuf(stdout, obuf);
E 3
	if (argc > 0 && argv[0][0] == '-') {
		fold = 0;
		argv[0]++;
		while (*argv[0] >= '0' && *argv[0] <= '9')
D 2
			fold =* 10, fold =+ *argv[0]++ - '0';
E 2
I 2
			fold *= 10, fold += *argv[0]++ - '0';
E 2
		if (*argv[0]) {
			printf("Bad number for fold\n");
			exit(1);
		}
		argc--, argv++;
	}
	do {
		if (argc > 0) {
			if (freopen(argv[0], "r", stdin) == NULL) {
				perror(argv[0]);
				exit(1);
			}
			argc--, argv++;
		}
		for (;;) {
			c = getc(stdin);
			if (c == -1)
				break;
			putch(c);
		}
	} while (argc > 0);
	exit(0);
}

int	col;

putch(c)
	register c;
{
	register ncol;

	switch (c) {
		case '\n':
			ncol = 0;
			break;
		case '\t':
			ncol = (col + 8) &~ 7;
			break;
		case '\b':
			ncol = col ? col - 1 : 0;
			break;
		case '\r':
			ncol = 0;
			break;
		default:
			ncol = col + 1;
	}
	if (ncol > fold)
		putchar('\n'), col = 0;
	putchar(c);
	switch (c) {
		case '\n':
			col = 0;
			break;
		case '\t':
D 2
			col =+ 8;
			col =& ~7;
E 2
I 2
			col += 8;
			col &= ~7;
E 2
			break;
		case '\b':
			if (col)
				col--;
			break;
		case '\r':
			col = 0;
			break;
		default:
			col++;
			break;
	}
}
E 1
