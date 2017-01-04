h54457
s 00010/00001/00021
d D 5.1 85/04/26 12:52:07 dist 2 1
c Add copyright
e
s 00022/00000/00000
d D 4.1 83/03/09 16:22:13 ralph 1 0
c date and time created 83/03/09 16:22:13 by ralph
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 2
/*
 * position the alphanumeric cursor to (x, y).
 */

#include "2648.h"

agoto(x, y)
int x, y;
{
	char mes[20];
	sprintf(mes, "\33*dE\33&a%dr%dC", x, y);
	outstr(mes);
}

/*
 * lower left corner of screen.
 */
lowleft()
{
	outstr("\33F");
}
E 1
