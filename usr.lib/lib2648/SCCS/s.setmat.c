h09267
s 00010/00001/00027
d D 5.1 85/04/26 12:42:05 dist 2 1
c Add copyright
e
s 00028/00000/00000
d D 4.1 83/03/09 16:23:19 ralph 1 0
c date and time created 83/03/09 16:23:19 by ralph
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
 * setmat: set the value in m[r, c] to nval.
 */

#include "bit.h"

setmat(m, rows, cols, r, c, nval)
bitmat m;
int rows, cols, r, c, nval;
{
	register int offset, thisbit;

	if (r<0 || c<0 || r>=rows || c>=cols) {
#ifdef TRACE
		if (trace)
			fprintf(trace, "setmat range error: (%d, %d) <- %d in a (%d, %d) matrix %x\n", r, c, nval, rows, cols, m);
#endif

		return;
	}
	offset = r*((cols+7)>>3) + (c>>3);
	thisbit = 0x80 >> (c&7);
	if (nval)
		m[offset] |= thisbit;
	else
		m[offset] &= ~thisbit;
}
E 1
