h33432
s 00009/00003/00021
d D 5.1 85/06/05 14:43:36 dist 5 4
c Add copyright
e
s 00000/00000/00024
d D 2.1 84/02/08 20:42:29 aoki 4 3
c synchronize to version 2
e
s 00000/00000/00024
d D 1.3 83/09/19 07:00:00 thien 3 2
c Restoring to unlinted version
e
s 00002/00000/00022
d D 1.2 83/08/19 05:00:38 thien 2 1
c The changes were made to allow successful linting
e
s 00022/00000/00000
d D 1.1 80/08/27 19:55:59 peter 1 0
c date and time created 80/08/27 19:55:59 by peter
e
u
U
t
T
I 1
D 5
/* Copyright (c) 1979 Regents of the University of California */
E 5
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 5

I 2
#ifndef lint
E 2
D 5
static	char sccsid[] = "%Z%%M% %I% %G%";
I 2
#endif
E 5
I 5
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint
E 5
E 2

#include "OPnames.h"

main()  {
	register int j, k;

	for(j = 0;  j < 32;  j++) {
		for (k = 0;  k < 256;  k += 32)
			if (otext[j+k])
				printf("%03o%cO_%s\t", j+k, *otext[j+k], otext[j+k]+1);
			else
				printf("%03o\t\t", j+k);
		putchar('\n');
		if ((j+1)%8 == 0)
			putchar('\n');
	}
	printf("Starred opcodes are used internally in Pi and are never generated.\n");
	exit(0);
}
E 1
