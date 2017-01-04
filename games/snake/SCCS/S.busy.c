h46465
s 00001/00001/00063
d D 5.2 87/06/03 17:15:59 bostic 3 2
c can't init a union
e
s 00007/00001/00057
d D 5.1 85/05/30 08:44:04 dist 2 1
c Add copyright
e
s 00058/00000/00000
d D 4.1 83/07/04 12:48:23 sam 1 0
c date and time created 83/07/04 12:48:23 by sam
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
static char sccsid[] = "%W% (Berkeley) %G%";
D 2
#endif
E 2
I 2
#endif not lint
E 2

/*
 * busy: print an indication of how busy the system is for games.
 */
#ifndef MAX
# define MAX 30
#endif

#include <stdio.h>
main(argc, argv)
char **argv;
{
	double la[3];
	double max;

	loadav(la);
	max = la[0];
	if (la[1] > max) max = la[1];
	if (la[2] > max) max = la[2];
	if (argc > 1)
		printf("1=%g, 5=%g, 15=%g, max=%g\n", la[0], la[1], la[2], max);
	if (max > MAX)
		printf("100\n");	/* incredibly high, no games allowed */
	else
		printf("0\n");
	exit(0);
}

#include <sys/types.h>
D 3
#include <a.out.h>
E 3
I 3
#include <nlist.h>
E 3

struct	nlist nl[] = {
	{ "_avenrun" },
	{ 0 },
};

loadav(avenrun)
double	*avenrun;
{
	register int i;
	int	kmem;

	if ((kmem = open("/dev/kmem", 0)) < 0) {
		fprintf(stderr, "No kmem\n");
		exit(1);
	}
	nlist("/vmunix", nl);
	if (nl[0].n_type==0) {
		fprintf(stderr, "No namelist\n");
		exit(1);
	}

	lseek(kmem, (long)nl[0].n_value, 0);
	read(kmem, avenrun, 3*sizeof(*avenrun));
}
E 1
