h61607
s 00000/00000/00020
d D 5.3 85/06/05 10:07:10 dist 4 3
c Add copyright
e
s 00009/00002/00011
d D 5.2 85/04/30 16:05:45 dist 3 2
c add copyright
e
s 00001/00001/00012
d D 5.1 85/04/30 15:47:45 dist 2 1
c add copyright
e
s 00013/00000/00000
d D 4.1 83/11/11 15:12:08 ralph 1 0
c date and time created 83/11/11 15:12:08 by ralph
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
static char sccsid[] = "@(#)box.c	4.1 (Berkeley) 11/11/83";
E 2
#endif
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 3

box(x0, y0, x1, y1)
{
	move(x0, y0);
	cont(x0, y1);
	cont(x1, y1);
	cont(x1, y0);
	cont(x0, y0);
	move(x1, y1);
}
E 1
