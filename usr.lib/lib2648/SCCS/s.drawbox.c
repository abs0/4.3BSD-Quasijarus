h00274
s 00010/00001/00021
d D 5.1 85/04/30 12:11:58 dist 2 1
c Add copyright
e
s 00022/00000/00000
d D 4.1 83/03/09 16:22:33 ralph 1 0
c date and time created 83/03/09 16:22:33 by ralph
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
 * Draw a box around a window.  The lower left corner of the box is at (r, c).
 * Color is 1 for drawing a box, 0 for erasing.
 * The box is nrow by ncol.
 */

#include "2648.h"

drawbox(r, c, color, nrow, ncol)
int r, c, color, nrow, ncol;
{
	if (color)
		setset();
	else
		setclear();
	move(c, r);
	draw(c+ncol-1, r);
	draw(c+ncol-1, r+nrow-1);
	draw(c, r+nrow-1);
	draw(c, r);
}
E 1
