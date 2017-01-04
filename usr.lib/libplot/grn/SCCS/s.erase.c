h04296
s 00034/00000/00000
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
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint


#include "grnplot.h"

/*---------------------------------------------------------
 *	This routine erases the screen.
 *
 *	Results:	None.
 *	Side Effects:	A new grn file is begun
 *	but: it is concatentated to the old one.
 *---------------------------------------------------------
 */
erase()
{
	if (ingrnfile)
	{
		closepl();
		fputs("multiple grn files in output must be separated by hand!\n",stderr);
	}
    printf("sungremlinfile\n0.00 0.00\n");
    ingrnfile = 1;
    invector = 0;
    scale = 1;
    curx = cury = xbot = ybot = 0;
}
E 1
