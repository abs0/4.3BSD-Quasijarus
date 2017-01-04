h33375
s 00010/00003/00135
d D 5.1 85/06/05 15:50:14 dist 3 2
c Add copyright
e
s 00000/00000/00138
d D 2.1 84/02/08 20:22:49 aoki 2 1
c synchronizing at version 2
e
s 00138/00000/00000
d D 1.1 81/03/02 21:28:55 peter 1 0
c date and time created 81/03/02 21:28:55 by peter
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

tyrec(r, p0)
	int *r, p0;
{

	if (r != NIL)
		setinfo(r[1]);
	if (p0 == NIL) {
		ppgoin(DECL);
		ppnl();
		indent();
		ppkw("record");
		ppspac();
	} else {
		ppspac();
		ppbra("(");
	}
	ppgoin(DECL);
	if (r) {
		field(r[2], r[3]);
		variant(r[3]);
	}
	if (r != NIL)
		setinfo(r[1]);
	putcml();
	ppgoout(DECL);
	if (p0 == NIL) {
		ppnl();
		indent();
		ppkw("end");
		ppgoout(DECL);
	} else {
		ppitem();
		ppket(")");
	}
}

field(r, v)
	int *r, *v;
{
	register int *fp, *tp, *ip;

	fp = r;
	if (fp != NIL)
		for (;;) {
			tp = fp[1];
			if (tp != NIL) {
				setline(tp[1]);
				ip = tp[2];
				ppitem();
				if (ip != NIL)
					for (;;) {
						ppid(ip[1]);
						ip = ip[2];
						if (ip == NIL)
							break;
						ppsep(", ");
					}
				else
					ppid("{field id list}");
				ppsep(":");
				gtype(tp[3]);
				setinfo(tp[1]);
				putcm();
			}
			fp = fp[2];
			if (fp == NIL)
				break;
			ppsep(";");
		}
	if (v != NIL && r != NIL)
		ppsep(";");
}

variant(r)
	register int *r;
{
	register int *v, *vc;

	if (r == NIL)
		return;
	setline(r[1]);
	ppitem();
	ppkw("case");
	v = r[2];
	if (v != NIL) {
		ppspac();
		ppid(v);
		ppsep(":");
	}
	gtype(r[3]);
	ppspac();
	ppkw("of");
	for (vc = r[4]; vc != NIL;) {
		v = vc[1];
		if (v == NIL)
			continue;
		ppgoin(DECL);
		setline(v[1]);
		ppnl();
		indent();
		ppbra(NIL);
		v = v[2];
		if (v != NIL) {
			for (;;) {
				gconst(v[1]);
				v = v[2];
				if (v == NIL)
					break;
				ppsep(", ");
			}
		} else
			ppid("{case label list}");
		ppket(":");
		v = vc[1];
		tyrec(v[3], 1);
		setinfo(v[1]);
		putcml();
		ppgoout(DECL);
		vc = vc[2];
		if (vc == NIL)
			break;
		ppsep(";");
	}
	setinfo(r[1]);
	putcm();
}
E 1
