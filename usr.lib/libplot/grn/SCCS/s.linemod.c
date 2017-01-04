h17791
s 00038/00000/00000
d D 6.1 86/08/29 15:06:24 sklower 1 0
c date and time created 86/08/29 15:06:24 by sklower
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
 *	Linemod sets the current line drawing style.
 *
 *	Results:	None.
 *
 *	Side Effects:
 *	The line style is set based on string s which
 *	must be one of "dotted", "solid", "longdashed", "shortdashed",
 *	or "dotdashed".  If s isn't recognized, then "solid" is used.
 *---------------------------------------------------------
 */
linemod(s)
char *s;
{
    endvector();
    if (strcmp(s, "dotted") == 0)
	linestyle = 1;
    else if (strcmp(s, "longdashed") == 0)
	linestyle = 4;
    else if (strcmp(s, "shortdashed") == 0)
	linestyle = 4;
    else if (strcmp(s, "dotdashed") == 0)
	linestyle = 2;
    else linestyle = DEFAULTLINE;
}
E 1
