h13767
s 00009/00001/00029
d D 5.1 85/04/26 12:53:42 dist 2 1
c Add copyright
e
s 00030/00000/00000
d D 4.1 83/03/09 16:22:19 ralph 1 0
c date and time created 83/03/09 16:22:19 by ralph
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

areaclear(rmin, cmin, rmax, cmax)
int rmin, cmin, rmax, cmax;
{
	int osm;
	char mes[20];
	register int i;

#ifdef TRACE
	if (trace)
		fprintf(trace, "areaclear(%d, %d, %d, %d)\n", rmin, cmin, rmax, cmax);
#endif
	osm = _supsmode;
	setclear();
	sync();
#ifdef notdef
	/* old kludge because I couldn't get area fill to work */
	for (i=rmax; i>=rmin; i--) {
		move(cmin, i);
		draw(cmax, i);
	}
#endif
	sprintf(mes, "%da1b%d %d %d %de", (_video==NORMAL) ? 1 : 2, cmin, rmin, cmax, rmax);
	escseq(ESCM);
	outstr(mes);
	_supsmode = osm;
}
E 1
