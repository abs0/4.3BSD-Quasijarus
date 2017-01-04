h54617
s 00027/00000/00000
d D 6.1 86/08/29 15:06:23 sklower 1 0
c date and time created 86/08/29 15:06:23 by sklower
e
u
U
t
T
I 1
/*
 * Copyright (c) 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

#include "grnplot.h"

/*---------------------------------------------------------
 *	Line draws a line between two points.
 *
 *	Results:	None.
 *
 *	Side Effects:
 *	A line is drawn on the screen between (x1, y1) and (x2, y2).
 *---------------------------------------------------------
 */
line(x1, y1, x2, y2)
int x1, y1, x2, y2;
{
	move(x1,y1);
	cont(x2,y2);
}
E 1
