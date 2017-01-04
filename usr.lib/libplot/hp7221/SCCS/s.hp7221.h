h16710
s 00007/00001/00027
d D 5.1 85/05/07 12:17:45 dist 2 1
c Add copyright notice
e
s 00028/00000/00000
d D 4.1 83/11/10 14:43:23 ralph 1 0
c date and time created 83/11/10 14:43:23 by ralph
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
/*
I 2
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 *
 *
E 2
 * Displays plot files on an HP7221 plotter.
 * Cloned from bgplot.c and gigiplot.c by Jim Kleckner
 * Thu Jun 30 13:35:04 PDT 1983
 *  Requires a handshaking program such as hp7221cat to get
 *  the plotter open and ready.
 */

#include <stdio.h>
#include <math.h>

#define ESC	033
#define PI	3.141592659
#define ENDOFSTRING 03

/* The graphics address range is 0..XMAX, 0..YMAX. */
#define XMAX	1800
#define YMAX	1800

#define scaleX(xi)	((int) ((xi - lowx)*scale +0.5))
#define scaleY(yi)	((int) ((yi - lowy)*scale +0.5))

extern int currentx;
extern int currenty;
extern double lowx;
extern double lowy;
extern double scale;
E 1
