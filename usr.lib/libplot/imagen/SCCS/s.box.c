h37808
s 00019/00000/00000
d D 5.1 85/09/21 15:05:47 sam 1 0
c date and time created 85/09/21 15:05:47 by sam
e
u
U
t
T
I 1
/*
 * Copyright (c) 1985 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

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
