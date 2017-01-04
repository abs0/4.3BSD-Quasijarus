h22230
s 00000/00000/00027
d D 5.2 85/06/05 10:06:38 dist 3 2
c Add copyright
e
s 00008/00001/00019
d D 5.1 85/04/30 16:08:04 dist 2 1
c add copyright
e
s 00020/00000/00000
d D 4.1 83/11/11 15:12:01 ralph 1 0
c date and time created 83/11/11 15:12:01 by ralph
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
 * Displays plot files on an AED512 graphics terminal.
 */

#include <stdio.h>
#include <sgtty.h>

extern char dbuf[BUFSIZ];	/* Used to buffer display characters */
extern struct sgttyb sgttyb;	/* Used to save terminal control bits */
extern curx, cury;		/* Current screen position */
extern int xbot, ybot;		/* Coordinates of screen lower-left corner */
extern int scale;		/* The number of pixels per 2**12 units
				 * of world coordinates.
				 */

/* The following variables describe the screen. */

#define GRXMAX	511	/* Maximum x-coordinate of screen */
#define GRYMAX	482	/* Maximum y-coordinate of screen */
E 1
