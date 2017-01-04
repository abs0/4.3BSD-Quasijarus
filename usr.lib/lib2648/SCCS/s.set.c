h51053
s 00010/00001/00020
d D 5.1 85/04/26 12:35:10 dist 2 1
c Add copyright
e
s 00021/00000/00000
d D 4.1 83/03/09 16:23:16 ralph 1 0
c date and time created 83/03/09 16:23:16 by ralph
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
 * Routines to set line type.
 */

#include "2648.h"

setxor()
{
	_supsmode = MX;
}

setclear()
{
	_supsmode = _video==INVERSE ? MS : MC;
}

setset()
{
	_supsmode = _video==INVERSE ? MC : MS;
}
E 1
