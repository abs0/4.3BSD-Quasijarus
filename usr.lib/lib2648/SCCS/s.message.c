h46898
s 00010/00001/00011
d D 5.1 85/04/30 12:17:30 dist 2 1
c Add copyright
e
s 00012/00000/00000
d D 4.1 83/03/09 16:22:53 ralph 1 0
c date and time created 83/03/09 16:22:53 by ralph
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
 * message: print str on the screen in the message area.
 */

#include "2648.h"

message(str)
char *str;
{
	dispmsg(str, 4, 4, 100);
}
E 1
