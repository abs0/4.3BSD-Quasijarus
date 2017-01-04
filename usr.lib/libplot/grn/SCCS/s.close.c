h51501
s 00028/00000/00000
d D 6.1 86/08/29 15:06:18 sklower 1 0
c date and time created 86/08/29 15:06:18 by sklower
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
 *	Closepl ends the gremlin file
 *
 *	Results:	None.
 *
 *	Side Effects:
 *---------------------------------------------------------
 */
closepl()
{
    if (!ingrnfile) return;
    endvector();
    printf("-1\n");
    ingrnfile = 0;
}
E 1
