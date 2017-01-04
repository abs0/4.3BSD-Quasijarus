h56199
s 00028/00000/00000
d D 6.1 86/08/29 15:06:25 sklower 1 0
c date and time created 86/08/29 15:06:25 by sklower
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
 *	This routine moves the current point to (x,y).
 *
 *	Results:	None.
 *	Side Effects:	If current line, close it.
 *---------------------------------------------------------
 */
move(x, y)
int x, y;
{
	if (!ingrnfile) erase();
    if (invector) endvector();
    curx = x;
    cury = y;
}
E 1
