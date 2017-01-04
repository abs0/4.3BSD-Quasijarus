h15131
s 00009/00002/00025
d D 5.2 85/04/30 16:05:47 dist 3 2
c add copyright
e
s 00001/00001/00026
d D 5.1 85/04/30 15:47:47 dist 2 1
c add copyright
e
s 00027/00000/00000
d D 4.1 83/11/11 15:12:11 ralph 1 0
c date and time created 83/11/11 15:12:11 by ralph
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
static char sccsid[] = "@(#)circle.c	4.1 (Berkeley) 11/11/83";
E 2
#endif
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 3

#include "aed.h"

/*---------------------------------------------------------
 *	Circle draws a circle.
 *
 *	Results:	None.
 *
 *	Side Effects:
 *	A circle of radius r is drawn at (x,y).
 *---------------------------------------------------------
 */
circle(x, y, r)
int x, y, r;
{
    char buf[3];
    setcolor("01");
    putc('Q', stdout);
    outxy20(x, y);
    putc('O', stdout);
    chex((r*scale)>>12, buf, 2);
    fputs(buf, stdout);
    (void) fflush(stdout);
}
E 1
