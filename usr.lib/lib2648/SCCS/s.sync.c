h18383
s 00010/00001/00033
d D 5.1 85/04/26 12:43:07 dist 2 1
c Add copyright
e
s 00034/00000/00000
d D 4.1 83/03/09 16:23:21 ralph 1 0
c date and time created 83/03/09 16:23:21 by ralph
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
 * Make the screen & screen mode look like what it's supposed to.
 *
 * There are two basic things to do here, put the _pen
 * in the right place, and make the line drawing mode be right.
 * We don't sync the cursor here, only when there's user input & it's on.
 */

#include "2648.h"

sync()
{
	if (_supx != _penx || _supy != _peny) {
		escseq(ESCP);
		outchar('a');
		motion(_supx, _supy);
	}
	if (_supsmode != _actsmode) {
		escseq(ESCM);
		switch (_actsmode = _supsmode) {
		case MX:
			outchar('3');
			break;
		case MC:
			outchar('1');
			break;
		case MS:
			outchar('2');
			break;
		}
		outchar('a');
	}
}
E 1
