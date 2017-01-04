h46861
s 00007/00001/00014
d D 5.1 85/05/07 11:39:43 dist 2 1
c Add copyright notice
e
s 00015/00000/00000
d D 4.1 83/11/10 11:52:52 ralph 1 0
c date and time created 83/11/10 11:52:52 by ralph
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

cont(x, y)
	int x,y;
{
	int x1, y1;
	x1 = x;
	y1 = y;
	scale(x1, y1);
	dda_line('*', currentx, currenty, x, y);
}
E 1
