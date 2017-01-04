h23270
s 00054/00000/00000
d D 6.1 86/08/29 15:06:28 sklower 1 0
c date and time created 86/08/29 15:06:28 by sklower
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


#include "grnplot.h"


/*---------------------------------------------------------
 *	This local routine outputs an x-y coordinate pair in the standard
 *	format required by the grn file.
 *
 *	Results:	None.
 *	
 *	Side Effects:
 *
 *	Errors:		None.
 *---------------------------------------------------------
 */
outxy(x, y)
int x, y;			/* The coordinates to be output.  Note:
				 * these are world coordinates, not screen
				 * ones.  We scale in this routine.
				 */
{
    printf("%.2f %.2f\n", (x - xbot)*scale,(y - ybot)*scale);
}

outcurxy()
{
	outxy(curx,cury);
}

startvector()
{
	if (!ingrnfile) erase();
	if (invector) return;
	invector = 1;
	printf("VECTOR\n");
	outcurxy();
}

endvector()
{
	if (!invector) return;
	invector = 0;
	printf("*\n%d 0\n0\n",linestyle);
}
E 1
