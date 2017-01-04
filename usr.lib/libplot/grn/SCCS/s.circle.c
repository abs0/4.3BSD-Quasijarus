h02941
s 00039/00000/00000
d D 6.1 86/08/29 15:06:17 sklower 1 0
c date and time created 86/08/29 15:06:17 by sklower
e
u
U
t
T
I 1
/*
 * Copyright (c) 1980, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint


#include "grnplot.h"

/*---------------------------------------------------------
 *	Circle draws a circle.
 *
 *	Results:	None.
 *
 *	Side Effects:
 *	A circle of radius r is drawn at (x,y).
 *	The current position is set to (x,y);
 *---------------------------------------------------------
 */
circle(x, y, r)
int x, y, r;
{
	if (!ingrnfile) erase();
	endvector();
	printf("ARC\n");
	outxy(x,y);
	outxy(x+r,y);
	outxy(x,y+r);
	outxy(x,y-r);
	outxy(x+r,y);
	outxy(x-r,y);
	printf("*\n%d 0\n0\n",linestyle);
	curx=x;
	cury=y;
}
E 1
