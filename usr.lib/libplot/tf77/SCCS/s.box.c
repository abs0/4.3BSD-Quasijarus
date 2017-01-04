h52847
s 00006/00001/00014
d D 5.2 85/06/08 11:07:21 mckusick 3 2
c from berkman
e
s 00008/00001/00007
d D 5.1 85/06/07 09:26:47 dist 2 1
c Add copyright
e
s 00008/00000/00000
d D 1.1 85/01/02 20:29:37 jak 1 0
c date and time created 85/01/02 20:29:37 by jak
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
box_(x0, y0, x1, y1)
int *x0, *y0, *x1, *y1;
{
D 3
	box(*x0, *y0, *x1, *y1);
E 3
I 3
	move(*x0, *y0);
	cont(*x0, *y1);
	cont(*x1, *y1);
	cont(*x1, *y0);
	cont(*x0, *y0);
	move(*x1, *y1);
E 3
}
E 1
