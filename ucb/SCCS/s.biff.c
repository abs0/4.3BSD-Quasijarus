h44094
s 00015/00002/00044
d D 5.1 85/05/31 09:07:07 dist 3 2
c Add copyright
e
s 00003/00001/00043
d D 4.2 83/07/02 00:54:22 sam 2 1
c include fixes
e
s 00044/00000/00000
d D 4.1 80/10/18 23:36:40 bill 1 0
c date and time created 80/10/18 23:36:40 by bill
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
I 2
#ifndef lint
E 2
I 1
D 3
static char *sccsid ="%W% (Berkeley) %G%";
I 2
#endif
E 3
I 3
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 3
E 2
/*
 * biff
 */

#include <sys/types.h>
D 2
#include <stat.h>
E 2
I 2
#include <sys/stat.h>
E 2
#include <stdio.h>

char	*ttyname();

main(argc, argv)
	int argc;
	char **argv;
{
	char *cp = ttyname(2);
	struct stat stb;

	argc--, argv++;
	if (cp == 0)
		fprintf(stderr, "Where are you?\n"), exit(1);
	if (stat(cp, &stb) < 0)
		perror(cp), exit(1);
	if (argc == 0) {
		printf("is %s\n", stb.st_mode&0100 ? "y" : "n");
		exit((stb.st_mode&0100) ? 0 : 1);
	}
	switch (argv[0][0]) {

	case 'y':
		if (chmod(cp, stb.st_mode|0100) < 0)
			perror(cp);
		break;

	case 'n':
		if (chmod(cp, stb.st_mode&~0100) < 0)
			perror(cp);
		break;

	default:
		fprintf(stderr, "usage: biff [y] [n]\n");
	}
	exit((stb.st_mode&0100) ? 0 : 1);
}
E 1
