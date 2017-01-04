h46812
s 00007/00001/00015
d D 5.1 85/05/07 11:50:30 dist 2 1
c Add copyright notice
e
s 00016/00000/00000
d D 4.1 83/11/10 16:04:05 ralph 1 0
c date and time created 83/11/10 16:04:05 by ralph
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

#include "gigi.h"

circle (xc,yc,r)
int xc,yc,r;
{
	if(r < 1){
		point(xc, yc);
		return;
	}
	move(xc, yc);
	printf("C[%d]", r);
}
E 1
