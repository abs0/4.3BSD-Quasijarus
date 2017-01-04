h49813
s 00002/00002/00051
d D 7.1 86/06/05 01:52:20 mckusick 4 3
c 4.3BSD release version
e
s 00015/00001/00038
d D 6.2 85/06/08 12:17:46 mckusick 3 2
c Add copyright
e
s 00000/00000/00039
d D 6.1 83/07/29 07:44:24 sam 2 1
c 4.2 distribution
e
s 00039/00000/00000
d D 4.1 83/02/16 22:06:49 sam 1 0
c date and time created 83/02/16 22:06:49 by sam
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
/*
D 4
 * Copyright (c) 1980 Regents of the University of California.
E 4
I 4
 * Copyright (c) 1980, 1986 Regents of the University of California.
E 4
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
char copyright[] =
D 4
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
E 4
I 4
"%Z% Copyright (c) 1980, 1986 Regents of the University of California.\n\
E 4
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 3

#include "../h/param.h"
#include "../h/fs.h"

char bootimage[BBSIZE];

main(argc, argv)
	int argc;
	char *argv[];
{
	int fd;

	if (argc != 4) {
		printf("Usage: installboot bootblock bootprog device\n");
		exit(1);
	}
	fd = open(argv[1], 0);
	if (fd < 0) {
		perror(argv[1]);
		exit(1);
	}
	read(fd, bootimage, DEV_BSIZE);
	close(fd);
	fd = open(argv[2], 0);
	if (fd < 0) {
		perror(argv[2]);
		exit(1);
	}
	read(fd, &bootimage[DEV_BSIZE], BBSIZE - DEV_BSIZE);
	close(fd);
	fd = open(argv[3], 1);
	if (fd < 0) {
		perror(argv[3]);
		exit(1);
	}
	write(fd, bootimage, BBSIZE);
	close(fd);
}
E 1
