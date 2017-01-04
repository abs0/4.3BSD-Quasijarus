h17269
s 00009/00003/00013
d D 5.1 85/06/05 14:36:19 dist 5 4
c Add copyright
e
s 00000/00000/00016
d D 2.1 84/02/08 20:41:58 aoki 4 3
c synchronize to version 2
e
s 00000/00000/00016
d D 1.3 83/09/19 06:59:16 thien 3 2
c Restoring to unlinted version
e
s 00002/00000/00014
d D 1.2 83/08/19 04:59:00 thien 2 1
c The changes were made to allow successful linting
e
s 00014/00000/00000
d D 1.1 80/08/27 19:55:29 peter 1 0
c date and time created 80/08/27 19:55:29 by peter
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
	register int i;

	for (i = 0;  i < 256;  i++)
		if (otext[i])
			printf("#define O_%s %04o\n", otext[i]+1, i);
	exit(0);
}
E 1
