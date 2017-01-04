h16408
s 00009/00002/00020
d D 5.2 85/04/30 16:05:50 dist 3 2
c add copyright
e
s 00001/00001/00021
d D 5.1 85/04/30 15:47:50 dist 2 1
c add copyright
e
s 00022/00000/00000
d D 4.1 83/11/11 15:12:14 ralph 1 0
c date and time created 83/11/11 15:12:14 by ralph
e
u
U
t
T
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 3
I 1
#ifndef lint
D 2
static char sccsid[] = "%W% (Berkeley) %G%";
E 2
I 2
D 3
static char sccsid[] = "@(#)close.c	4.1 (Berkeley) 11/11/83";
E 2
#endif
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 3

#include "aed.h"

/*---------------------------------------------------------
 *	Closepl does whatever is necessary to reset the characteristics
 *	of the AED512 after the program is finished.
 *
 *	Results:	None.
 *
 *	Side Effects:
 *	The graphics display modes are reset.
 *---------------------------------------------------------
 */
closepl()
{
    fputs("Q00204\6", stdout);
    (void) fflush(stdout);
    (void) stty(fileno(stdout), &sgttyb);
}
E 1
