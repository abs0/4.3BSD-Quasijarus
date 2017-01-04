h52847
s 00028/00000/00000
d D 6.1 86/08/29 15:06:19 sklower 1 0
c date and time created 86/08/29 15:06:19 by sklower
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
 *	Cont plots a line between (curx, cury) and (x, y).
 *
 *	Results:	None.
 *	Side Effects:	As above.
 *---------------------------------------------------------
 */
cont(x, y)
int x, y;
{
    startvector();
    curx = x;
    cury = y;
    outcurxy();
}
E 1
