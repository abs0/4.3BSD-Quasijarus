h54010
s 00010/00003/00069
d D 5.1 85/06/05 15:54:14 dist 4 3
c Add copyright
e
s 00000/00000/00072
d D 2.1 84/02/08 20:22:23 aoki 3 2
c synchronizing at version 2
e
s 00001/00001/00071
d D 1.2 81/03/07 17:36:17 mckusic 2 1
c merge in onyx changes
e
s 00072/00000/00000
d D 1.1 81/03/02 21:29:14 peter 1 0
c date and time created 81/03/02 21:29:14 by peter
e
u
U
t
T
I 1
D 4
static	char *sccsid = "%W% (Berkeley) %G%";
/* Copyright (c) 1979 Regents of the University of California */
#
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 4
/*
 * pxp - Pascal execution profiler
 *
 * Bill Joy UCB
 * Version 1.2 January 1979
 */

#include "0.h"
#include "tree.h"

D 2
STATIC	int varcnt -1;
E 2
I 2
STATIC	int varcnt = -1;
E 2
/*
 * Var declaration part
 */
varbeg(l, vline)
	int l, vline;
{

	line = l;
	if (nodecl)
		printoff();
	puthedr();
	putcm();
	ppnl();
	indent();
	ppkw("var");
	ppgoin(DECL);
	varcnt = 0;
	setline(vline);
}

var(vline, vidl, vtype)
	int vline;
	register int *vidl;
	int *vtype;
{

	if (varcnt)
		putcm();
	setline(vline);
	ppitem();
	if (vidl != NIL)
		for (;;) {
			ppid(vidl[1]);
			vidl = vidl[2];
			if (vidl == NIL)
				break;
			ppsep(", ");
		}
	else
		ppid("{identifier list}");
	ppsep(":");
	gtype(vtype);
	ppsep(";");
	setinfo(vline);
	putcml();
	varcnt++;
}

varend()
{

	if (varcnt == -1)
		return;
	if (varcnt == 0)
		ppid("{variable decls}");
	ppgoout(DECL);
	varcnt = -1;
}
E 1
