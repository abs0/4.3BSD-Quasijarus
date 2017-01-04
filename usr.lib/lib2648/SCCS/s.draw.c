h60708
s 00010/00001/00020
d D 5.1 85/04/26 12:59:21 dist 2 1
c Add copyright
e
s 00021/00000/00000
d D 4.1 83/03/09 16:22:31 ralph 1 0
c date and time created 83/03/09 16:22:31 by ralph
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
 * draw a line from the current place to (x,y).  Such lines are
 * supposed to be horizontal, and are affected by the current mode.
 */

#include "2648.h"

draw(x, y)
{
#ifdef TRACE
	if (trace) {
		fprintf(trace, "draw(%d,%d)\n", x, y);
	}
#endif
	sync();
	escseq(ESCP);
	motion(x, y);
	_supx = x;
	_supy = y;
}
E 1
