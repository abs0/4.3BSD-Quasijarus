h10227
s 00010/00001/00034
d D 5.1 85/04/26 12:57:09 dist 2 1
c Add copyright
e
s 00035/00000/00000
d D 4.1 83/03/09 16:22:30 ralph 1 0
c date and time created 83/03/09 16:22:30 by ralph
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
 * display a message, str, starting at (x, y).
 */

#include "2648.h"

dispmsg(str, x, y, maxlen)
char *str;
int x, y;
{
	int oldx, oldy;
	int oldcuron;
	int oldquiet;
	extern int QUIET;

	oldx = _curx; oldy = _cury;
	oldcuron = _cursoron;
	zoomout();
	areaclear(y, x, y+8, x+6*maxlen);
	setset();
	curon();
	movecurs(x, y);
	texton();
	oldquiet = QUIET;
	QUIET = 0;
	outstr(str);
	if (oldquiet)
		outstr("\r\n");
	QUIET = oldquiet;
	textoff();
	movecurs(oldx, oldy);
	if (oldcuron == 0)
		curoff();
}
E 1
