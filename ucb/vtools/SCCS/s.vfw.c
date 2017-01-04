h06754
s 00007/00001/00032
d D 5.1 85/05/15 11:33:19 dist 3 2
c Add copyright notice
e
s 00004/00001/00029
d D 4.2 83/07/16 23:48:56 sam 2 1
c add useful sccs id's
e
s 00030/00000/00000
d D 4.1 83/04/29 11:33:10 ralph 1 0
c date and time created 83/04/29 11:33:10 by ralph
e
u
U
t
T
I 3
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 3
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif
E 3
I 3
#endif not lint
E 3

E 2
/*
 * Quick hack to see the values in a troff width table.
 */

#include <stdio.h>

main(argc,argv)
char **argv;
{
	FILE *f;
	int c;
	int i;

	if (argc != 2) {
		printf("usage: vfw ftX\n");
		exit(1);
	}
	f = fopen(argv[1], "r");
	if (f == NULL) {
		printf("Can't open %s\n", argv[1]);
		exit(1);
	}
	fseek(f, 32L, 0);
	for (i=0; !feof(f); i++) {
		c = getc(f);
		printf("%d\t%d\n", i, c&255);
	}
	exit(0);
}
E 1
