h48031
s 00010/00001/00010
d D 5.1 85/04/30 12:14:01 dist 2 1
c Add copyright
e
s 00011/00000/00000
d D 4.1 83/03/09 16:22:39 ralph 1 0
c date and time created 83/03/09 16:22:39 by ralph
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
 * error: default handling of errors.
 */

error(msg)
char *msg;
{
	message(msg);
	/* Maybe it would be nice to longjmp somewhere here */
}
E 1
