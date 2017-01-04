h64110
s 00010/00001/00018
d D 5.1 85/04/26 12:55:10 dist 2 1
c Add copyright
e
s 00019/00000/00000
d D 4.1 83/03/09 16:22:23 ralph 1 0
c date and time created 83/03/09 16:22:23 by ralph
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
 * Copy from msrc to mdest.
 * This is done as it is because it would be much slower to do it
 * a bit at a time.
 */

#include "bit.h"

bitcopy(mdest, msrc, rows, cols)
bitmat mdest, msrc;
int rows, cols;
{
	register int size = ((cols + 7) >> 3) * rows;
	register char *p, *q;

	for (p = &mdest[size], q = &msrc[size]; p>=mdest; )
		*--p = *--q;
}
E 1
