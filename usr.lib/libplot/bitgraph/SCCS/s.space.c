h01148
s 00009/00002/00014
d D 5.2 85/04/30 16:15:38 dist 3 2
c add copyright
e
s 00001/00001/00015
d D 5.1 85/04/30 15:44:07 dist 2 1
c add copyright
e
s 00016/00000/00000
d D 4.1 83/11/10 11:03:28 ralph 1 0
c date and time created 83/11/10 11:03:28 by ralph
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
static char sccsid[] = "@(#)space.c	4.1 (Berkeley) 11/10/83";
E 2
#endif
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 3

#include "bg.h"

space(x0,y0,x1,y1)
int x0,y0,x1,y1;
{
	double scalex, scaley;
	lowx = x0;
	lowy = y0;
	scalex = XMAX/(double)(x1-lowx);
	scaley = YMAX/(double)(y1-lowy);
	scale = scalex < scaley ? scalex : scaley;
}
E 1
