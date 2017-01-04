h00677
s 00008/00001/00021
d D 5.1 85/04/30 16:16:47 dist 2 1
c add copyright
e
s 00022/00000/00000
d D 4.1 83/11/10 11:00:17 ralph 1 0
c date and time created 83/11/10 11:00:17 by ralph
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
 * Displays plot files on a bbn bitgraph terminal.
 */

#include <stdio.h>
#include <math.h>

#define ESC	033
#define PI	3.141592659

/* The graphics address range is 0..XMAX, 0..YMAX. */
#define XMAX	768
#define YMAX	1024
#define scaleX(xi)	((int) ((xi - lowx)*scale +0.5))
#define scaleY(yi)	((int) ((yi - lowy)*scale +0.5))

extern int currentx;
extern int currenty;
extern double lowx;
extern double lowy;
extern double scale;
E 1
