h52281
s 00027/00000/00000
d D 6.1 86/08/29 15:06:16 sklower 1 0
c date and time created 86/08/29 15:06:16 by sklower
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


arc(x,y,x0,y0,x1,y1)
{
	extern double atan2();

	if (!ingrnfile) erase();
	endvector();
	printf("ARC\n");
	outxy(x,y);
	outxy(x0,y0);
	outxy(x1,y1);
	printf("*\n%d %d\n0\n",linestyle,(int) (atan2(x1-x,y1-y)-atan2(x0-x,y0-y)));
	curx =x;
	cury =y;
}
E 1
