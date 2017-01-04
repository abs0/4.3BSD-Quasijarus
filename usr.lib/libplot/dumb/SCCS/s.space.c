h45854
s 00007/00001/00013
d D 5.1 85/05/07 11:40:15 dist 2 1
c Add copyright notice
e
s 00014/00000/00000
d D 4.1 83/11/10 11:55:07 ralph 1 0
c date and time created 83/11/10 11:55:07 by ralph
e
u
U
t
T
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 2
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 2
#endif
E 2
I 2
#endif not lint
E 2

#include "dumb.h"

space(x0, y0, x1, y1)
	int x0, y0, x1, y1;
{
	minX = x0;
	rangeX = x1 -x0;
	minY = y0;
	rangeY = y1 - y0;
}
E 1
