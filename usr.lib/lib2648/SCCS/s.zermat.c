h52997
s 00010/00001/00016
d D 5.1 85/04/26 12:48:05 dist 2 1
c Add comments
e
s 00017/00000/00000
d D 4.1 83/03/09 16:23:30 ralph 1 0
c date and time created 83/03/09 16:23:30 by ralph
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
 * zermat: set a matrix to all zeros
 */

#include "bit.h"

zermat(m, rows, cols)
bitmat m;
int rows, cols;
{
	register int size = ((cols + 7) >> 3) * rows;
	register char *p;

	for (p = &m[size]; p>=m; )
		*--p = 0;
}
E 1
