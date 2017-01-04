h14710
s 00037/00000/00000
d D 6.1 86/08/29 15:06:27 sklower 1 0
c date and time created 86/08/29 15:06:27 by sklower
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
 *	Space sets up the world-to-screen transformation so
 *	that the rectangular area described by (x0, y0) and
 *	(x1, y1) will all be on-screen.
 *
 *	Results:	None.
 *
 *	Side Effects:
 *	Our own variables scale, xbot, and ybot are changed.
 *---------------------------------------------------------
 */
space(x0, y0, x1, y1)
int x0, y0, x1, y1;
{
    double xscale=0.0, yscale=0.0;
    if (x1>x0)
	    xscale = GRXMAX/(double)(x1-x0);
    if (y1>y0)
	    yscale = GRYMAX/(double)(y1-y0);
    scale = (xscale > yscale && yscale > 0)? yscale : xscale;
    if (scale == 0.0) scale == 1.0;
    xbot = x0;
    ybot = y0;
}
E 1
