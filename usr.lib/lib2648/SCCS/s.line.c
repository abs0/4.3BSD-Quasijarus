h00263
s 00010/00001/00024
d D 5.1 85/04/30 12:16:33 dist 2 1
c Add copyright
e
s 00025/00000/00000
d D 4.1 83/03/09 16:22:49 ralph 1 0
c date and time created 83/03/09 16:22:49 by ralph
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
 * line: draw a line from point 1 to point 2.
 */

#include "2648.h"

line(x1, y1, x2, y2)
int x1, y1, x2, y2;
{
#ifdef TRACE
	if (trace)
		fprintf(trace, "line((%d, %d), (%d, %d)),", x1, y1, x2, y2);
#endif
	if (x1==_penx && y1==_peny) {
		/*
		 * Get around a bug in the HP terminal where one point
		 * lines don't get drawn more than once.
		 */
		move(x1, y1+1);
		sync();
	}
	move(x1, y1);
	draw(x2, y2);
}
E 1
