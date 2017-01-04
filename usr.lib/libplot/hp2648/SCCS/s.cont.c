h55881
s 00007/00001/00019
d D 5.1 85/05/07 12:07:15 dist 2 1
c Add copyright notice
e
s 00020/00000/00000
d D 4.1 83/11/10 14:12:55 ralph 1 0
c date and time created 83/11/10 14:12:55 by ralph
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

#include "hp2648.h"

cont(xi,yi)
int xi,yi;
{
	char xb1,xb2,yb1,yb2;
	itoa(xsc(xi),&xb1,&xb2);
	itoa(ysc(yi),&yb1,&yb2);
	buffready(4);
	putchar(xb2);
	putchar(xb1);
	putchar(yb2);
	putchar(yb1); 
	currentx = xsc(xi);
	currenty = ysc(yi);
}
E 1
