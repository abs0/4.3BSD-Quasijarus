h07401
s 00008/00001/00025
d D 5.1 85/05/07 11:42:49 dist 2 1
c Add copyright notice
e
s 00026/00000/00000
d D 4.1 83/11/10 16:30:26 ralph 1 0
c date and time created 83/11/10 16:30:26 by ralph
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
 *
 *	%W% (Berkeley) %G%
 */

E 2
/*
 * Displays plot files on a gigi "graphics" terminal.
 */

#include <stdio.h>
#include <math.h>

#define ESC	033
#define PI	3.141592659

/*
 * The graphics address range is 0..XMAX, YMAX..0 where (0, YMAX) is the
 * lower left corner.
 */
#define XMAX	767
#define YMAX	479
#define xsc(xi)	((int) ((xi -lowx)*scalex +0.5))
#define ysc(yi)	((int) (YMAX - (yi - lowy)*scaley +0.5))

extern int currentx;
extern int currenty;
extern double lowx;
extern double lowy;
extern double scalex;
extern double scaley;
E 1
