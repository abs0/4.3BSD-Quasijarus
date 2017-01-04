h01667
s 00009/00002/00016
d D 5.2 85/04/30 16:15:19 dist 3 2
c add copyright
e
s 00001/00001/00017
d D 5.1 85/04/30 15:43:50 dist 2 1
c add copyright
e
s 00018/00000/00000
d D 4.1 83/11/10 11:01:56 ralph 1 0
c date and time created 83/11/10 11:01:56 by ralph
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
static char sccsid[] = "@(#)line.c	4.1 (Berkeley) 11/10/83";
E 2
#endif
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 3

#include "bg.h"

line(x0,y0,x1,y1)
int x0,y0,x1,y1;
{
	if(scaleX(x0)==currentx && scaleY(y0)==currenty)
		cont(x1,y1);
	else if(scaleX(x1)==currentx && scaleY(y1)==currenty)
		cont(x0,y0);
	else{
		move(x0,y0);
		cont(x1,y1);
	}
}
E 1
