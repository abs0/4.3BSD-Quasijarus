h15796
s 00010/00003/00038
d D 5.1 85/06/05 15:45:57 dist 3 2
c Add copyright
e
s 00000/00000/00041
d D 2.1 84/02/08 20:22:27 aoki 2 1
c synchronizing at version 2
e
s 00041/00000/00000
d D 1.1 81/03/02 21:28:00 peter 1 0
c date and time created 81/03/02 21:28:00 by peter
e
u
U
t
T
I 1
D 3
static	char *sccsid = "%W% (Berkeley) %G%";
/* Copyright (c) 1979 Regents of the University of California */
#
E 3
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 3
/*
 * pxp - Pascal execution profiler
 *
 * Bill Joy UCB
 * Version 1.2 January 1979
 */

#include "0.h"
#include "tree.h"

/*
 * Constant sets
 */
cset(r)
int *r;
{
	register *e, *el;

	ppbra("[");
	el = r[2];
	if (el != NIL)
		for (;;) {
			e = el[1];
			el = el[2];
			if (e == NIL)
				continue;
			if (e[0] == T_RANG) {
				rvalue(e[1], NIL);
				ppsep("..");
				rvalue(e[2], NIL);
			} else
				rvalue(e, NIL);
			if (el == NIL)
				break;
			ppsep(", ");
		}
	ppket("]");
}
E 1
