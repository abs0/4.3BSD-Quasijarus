h12858
s 00014/00002/00023
d D 5.1 85/05/30 19:41:09 mckusick 2 1
c Add copyright
e
s 00025/00000/00000
d D 4.1 82/12/24 13:07:52 sam 1 0
c date and time created 82/12/24 13:07:52 by sam
e
u
U
t
T
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 2
I 1
#ifndef lint
D 2
static char sccsid[] = "%W% %G%";
#endif
E 2
I 2
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 2

#include <stdio.h>
#define MAX ' '

char new[MAX], old[MAX];

main ()
{
	register int i, j;
	old[0] = '\0';
	while (fgets(&new[0], MAX, stdin) != NULL) {
		for (i=0; i<MAX && old[i]==new[i]; i++);
		if (i >= MAX) {
			fprintf(stderr, "long word\n");
			exit(1);
		}
		putc(i, stdout);
		for (j=0; (old[j]=new[j]) != '\n'; j++);
		old[j] = '\0';
		fputs(&old[i], stdout);
	}
}
E 1
