h34835
s 00010/00003/00069
d D 5.1 85/06/05 15:47:37 dist 3 2
c Add copyright
e
s 00000/00000/00072
d D 2.1 84/02/08 20:21:45 aoki 2 1
c synchronizing at version 2
e
s 00072/00000/00000
d D 1.1 81/03/02 21:28:17 peter 1 0
c date and time created 81/03/02 21:28:17 by peter
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

/*
 * Label declaration part
 */
label(r, l)
	int *r, l;
{
	register *ll;

	if (nodecl)
		printoff();
	puthedr();
	setline(l);
	ppnl();
	indent();
	ppkw("label");
	ppgoin(DECL);
	ppnl();
	indent();
	ppbra(NIL);
	ll = r;
	if (ll != NIL)
		for (;;) {
			pplab(ll[1]);
			ll = ll[2];
			if (ll == NIL)
				break;
			ppsep(", ");
		}
	else
		ppid("{label list}");
	ppket(";");
	putcml();
	ppgoout(DECL);
}

/*
 * Goto statement
 */
gotoop(s)
	char *s;
{

	gocnt++;
	ppkw("goto");
	ppspac();
	pplab(s);
}

/*
 * A label on a statement
 */
labeled(s)
	char *s;
{

	linopr();
	indentlab();
	pplab(s);
	ppsep(":");
}
E 1
