h13712
s 00032/00000/00000
d D 6.1 86/08/29 15:06:21 sklower 1 0
c date and time created 86/08/29 15:06:21 by sklower
e
u
U
t
T
I 1
/*
 * Copyright (c) 1980, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 *	modified to grnplot by Brad Rubenstein 8/29/86
 */

/*
 * Given a plot file, produces a grn file
 */

#include <stdio.h>

extern curx, cury;		/* Current screen position */
extern int xbot, ybot;		/* Coordinates of screen lower-left corner */
extern double scale;		/* The number of pixels per 2**12 units
				 * of world coordinates.
				 */
extern int linestyle;
extern int invector, ingrnfile;

#define FONTSIZE 1
#define FONTSTYLE 1
#define DEFAULTLINE 5
#define POINTSTRING "."

/* The following variables describe the screen. */

#define GRXMAX	512	/* Maximum x-coordinate of screen */
#define GRYMAX	512	/* Maximum y-coordinate of screen */
E 1
