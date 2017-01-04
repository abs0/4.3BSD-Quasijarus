h05076
s 00002/00002/00025
d D 5.2 85/06/06 19:09:44 mckusick 4 2
c fix botched copyright
e
s 00042/00002/00025
d R 5.2 85/04/30 16:06:03 dist 3 2
c add copyright
e
s 00001/00001/00026
d D 5.1 85/04/30 15:48:01 dist 2 1
c add copyright
e
s 00027/00000/00000
d D 4.1 83/11/11 15:12:30 ralph 1 0
c date and time created 83/11/11 15:12:30 by ralph
e
u
U
t
T
I 1
#ifndef lint
D 2
static char sccsid[] = "%W% (Berkeley) %G%";
E 2
I 2
D 4
static char sccsid[] = "@(#)line.c	4.1 (Berkeley) 11/11/83";
E 2
#endif
E 4
I 4
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 4

#include "aed.h"

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
    setcolor("01");
    putc('Q', stdout);
    outxy20(x1, y1);
    putc('A', stdout);
    outxy20(x2, y2);
    (void) fflush(stdout);
    curx = x2;
    cury = y2;
}
E 1
