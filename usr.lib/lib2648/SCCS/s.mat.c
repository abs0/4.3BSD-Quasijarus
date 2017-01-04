h63773
s 00010/00001/00019
d D 5.1 85/04/30 12:17:04 dist 2 1
c Add copyright
e
s 00020/00000/00000
d D 4.1 83/03/09 16:22:51 ralph 1 0
c date and time created 83/03/09 16:22:51 by ralph
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
 * mat: retrieve the value in m[r, c].
 * rows and cols are the size of the matrix in all these routines.
 */

#include "bit.h"

int
mat(m, rows, cols, r, c)
register bitmat m;
register int c;
int rows, cols, r;
{
	register int thisbyte;

	thisbyte = m[r*((cols+7)>>3) + (c>>3)] & 0xff;
	thisbyte &= 0x80 >> (c&7);
	return (thisbyte != 0);
}
E 1
