h63326
s 00010/00001/00022
d D 5.1 85/04/30 12:13:22 dist 2 1
c Add copyright
e
s 00023/00000/00000
d D 4.1 83/03/09 16:22:37 ralph 1 0
c date and time created 83/03/09 16:22:37 by ralph
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 2
/*
 * emptyrow: returns true if row r of m is all zeros.
 *
 * Note that we assume the garbage at the end of the
 * row is all zeros.
 */

#include "bit.h"

emptyrow(m, rows, cols, r)
bitmat m;
int rows, cols, r;
{
	char *top, *bot;

	bot = &m[r*((cols+7)>>3)];
	top = bot + ((cols-1) >> 3);
	while (bot <= top)
		if (*bot++)
			return(0);
	return (1);
}
E 1
