h57761
s 00010/00001/00016
d D 5.1 85/04/30 12:19:00 dist 2 1
c Add copyright
e
s 00017/00000/00000
d D 4.1 83/03/09 16:22:58 ralph 1 0
c date and time created 83/03/09 16:22:58 by ralph
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
 * move to (x, y).  Both the _pen and cursor are supposed to be moved.
 * We really just remember it for later, in case we move again.
 */

#include "2648.h"

move(x, y)
{
#ifdef TRACE
	if (trace)
		fprintf(trace, "\tmove(%d, %d), ", x, y);
#endif
	_supx = x;
	_supy = y;
}
E 1
