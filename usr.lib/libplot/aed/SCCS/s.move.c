h02414
s 00009/00002/00017
d D 5.2 85/04/30 16:06:09 dist 3 2
c add copyright
e
s 00001/00001/00018
d D 5.1 85/04/30 15:48:06 dist 2 1
c add copyright
e
s 00019/00000/00000
d D 4.1 83/11/11 15:12:36 ralph 1 0
c date and time created 83/11/11 15:12:36 by ralph
e
u
U
t
T
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 3
I 1
#ifndef lint
D 2
static char sccsid[] = "%W% (Berkeley) %G%";
E 2
I 2
D 3
static char sccsid[] = "@(#)move.c	4.1 (Berkeley) 11/11/83";
E 2
#endif
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 3

#include "aed.h"

/*---------------------------------------------------------
 *	This routine moves the current point to (x,y).
 *
 *	Results:	None.
 *	Side Effects:	As above.
 *---------------------------------------------------------
 */
move(x, y)
int x, y;
{
    curx = x;
    cury = y;
}
E 1
