h61923
s 00007/00001/00028
d D 5.1 85/06/07 23:15:18 kre 2 1
c Add copyright
e
s 00029/00000/00000
d D 1.1 81/02/19 18:12:38 dlw 1 0
c date and time created 81/02/19 18:12:38 by dlw
e
u
U
t
T
I 1
/*
D 2
char id_fork[] = "%W%";
E 2
I 2
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 2
 *
I 2
 *	%W%	%G%
 */

/*
E 2
 * fork a copy of this process
 *
 * calling sequence:
 *	integer fork
 *	ierror = fork()
 * where:
 *	ierror will be	- child pid if parent and successful
 *			- 0 if child
 *			- -errno if unsuccessful
 */

#include	"../libI77/fiodefs.h"

extern int errno;

long fork_()
{
	long i;

	for (i = 0; i < MXUNIT; i++)
		flush_(&i);
	i = (long)fork();
	if (i < 0)
		return((long)(-errno));
	return(i);
}
E 1
