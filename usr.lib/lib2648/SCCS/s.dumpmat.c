h29210
s 00009/00001/00030
d D 5.1 85/04/30 12:12:43 dist 3 2
c Add copyright
e
s 00001/00000/00030
d D 4.2 83/06/10 23:09:04 sam 2 1
c missing endif
e
s 00030/00000/00000
d D 4.1 83/03/09 16:22:35 ralph 1 0
c date and time created 83/03/09 16:22:35 by ralph
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
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 3

#include "bit.h"

#ifdef TRACE
/*
 * dumpmat: debugging dumpmat of a window or other bit matrix.
 * msg is a handy label, m is the matrix, rows, cols is the size of the matrix.
 */
dumpmat(msg, m, rows, cols)
char *msg;
bitmat m;
int rows, cols;
{
	register int r, c;
	int r1, r2, c1, c2;

	if (trace == NULL)
		return;
	fprintf(trace, "\ndumpmat %s, m=%x, rows=%d, cols=%d\n", msg, m, rows, cols);
	minmax(m, rows, cols, &r1, &c1, &r2, &c2);
	fprintf(trace, "r1=%d, r2=%d, c1=%d, c2=%d\n", r1, r2, c1, c2);
	for (r=r1; r<=r2; r++) {
		fprintf(trace, "%2d ", r);
		for (c=c1; c<=c2; c++)
			fprintf(trace, "%c", mat(m, rows, cols, r, c, 5) ? 'X' : '.');
		fprintf(trace, "\n");
	}
	fprintf(trace, "\n");
}
I 2
#endif
E 2
E 1
