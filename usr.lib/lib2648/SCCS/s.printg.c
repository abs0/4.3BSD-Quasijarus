h04485
s 00009/00001/00032
d D 5.1 85/04/26 12:30:24 dist 2 1
c Add copyright
e
s 00033/00000/00000
d D 4.1 83/03/09 16:23:07 ralph 1 0
c date and time created 83/03/09 16:23:07 by ralph
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

printg()
{
	int oldvid = _video;
	int c, c2;

	if (oldvid==INVERSE)
		togvid();
	sync();
	escseq(NONE);
	outstr("\33&p4d5u0C");
	outchar('\21');	/* test handshaking fix */

	/*
	 * The terminal sometimes sends back S<cr> or F<cr>.
	 * Ignore them.
	 */
	fflush(stdout);
	c = getchar();
	if (c=='F' || c=='S') {
		c2 = getchar();
		if (c2 != '\r' && c2 != '\n')
			ungetc(c2, stdin);
	} else {
		ungetc(c, stdin);
	}

	if (oldvid==INVERSE)
		togvid();
}
E 1
