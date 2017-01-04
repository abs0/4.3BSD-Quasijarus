h45189
s 00010/00001/00012
d D 5.1 85/04/26 12:29:46 dist 2 1
c Add copyright
e
s 00013/00000/00000
d D 4.1 83/03/09 16:23:06 ralph 1 0
c date and time created 83/03/09 16:23:06 by ralph
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
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 2
/*
 * Low level output routines
 */

#include "2648.h"

outstr(str)
char *str;
{
	while (*str)
		outchar(*str++);
}
E 1
