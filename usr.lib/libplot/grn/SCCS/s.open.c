h07809
s 00039/00000/00000
d D 6.1 86/08/29 15:06:25 sklower 1 0
c date and time created 86/08/29 15:06:25 by sklower
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
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint


/*
 * converts plot to grn
 */

#include "grnplot.h"

int curx, cury;		/* Current world position */
int xbot=0, ybot=0;	/* Coordinates of screen lower-left corner */
double scale=1;		/* The number of pixels per 2**12 units
			 * of world coordinates.
			 */
int linestyle = 5;
int	ingrnfile = 0;
int	invector = 0;


/*---------------------------------------------------------
 *	Openpl initializes the graphics display and clears its screen.
 *
 *	Results:	None.
 *
 *	Side Effects:
 *
 *	Errors:		None.
 *---------------------------------------------------------
 */
openpl()
{}
E 1
