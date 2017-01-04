h49713
s 00009/00001/00019
d D 5.1 85/04/26 12:47:32 dist 2 1
c Add copyright
e
s 00020/00000/00000
d D 4.1 83/03/09 16:23:28 ralph 1 0
c date and time created 83/03/09 16:23:28 by ralph
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

#include "2648.h"

vidnorm()
{
	_video = NORMAL;
}

vidinv()
{
	_video = INVERSE;
}

togvid()
{
	_video = (_video==NORMAL) ? INVERSE : NORMAL;
	escseq(ESCM);
	outstr("3a1b0 0 719 359e");
}
E 1
