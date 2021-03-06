h23408
s 00010/00001/00036
d D 5.1 85/04/30 12:18:02 dist 2 1
c Add copyright
e
s 00037/00000/00000
d D 4.1 83/03/09 16:22:55 ralph 1 0
c date and time created 83/03/09 16:22:55 by ralph
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
 * minmax: find the 4 edges of the glyph within a window.
 */

#include "bit.h"

minmax(g, nrow, ncol, rmin, cmin, rmax, cmax)
bitmat g;
int nrow, ncol;
int *rmin, *cmin, *rmax, *cmax;
{
	register int i, j;
	register int r1, r2, c1, c2;
	int ar1, ar2, ac1, ac2;

	aminmax(g, nrow, ncol, &ar1, &ac1, &ar2, &ac2);
#ifdef TRACE
	if (trace)
		fprintf(trace, "aminmax returns %d, %d, %d, %d\n", ar1, ac1, ar2, ac2);
#endif
	r1 = nrow; c1 = ncol; r2 = c2 = 0;
	for (i=ar1; i<=ar2; i++)
		for (j=ac1; j<=ac2; j++)
			if (mat(g, nrow, ncol, i, j, 8)) {
				r1 = min(r1, i);
				r2 = max(r2, i);
				c1 = min(c1, j);
				c2 = max(c2, j);
			}
	if (r2 < r1) {
		/* empty glyph! */
		r1 = c1 = r2 = c2 = 1;
	}
	*rmin = r1; *rmax = r2;
	*cmin = c1; *cmax = c2;
}
E 1
