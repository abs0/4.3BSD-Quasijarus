h59497
s 00008/00002/00222
d D 5.1 85/06/05 15:53:27 dist 5 4
c Add copyright
e
s 00000/00000/00224
d D 2.1 84/02/08 20:23:12 aoki 4 3
c synchronizing at version 2
e
s 00022/00002/00202
d D 1.3 84/02/08 20:14:09 aoki 3 2
c merge conformant arrays (by Carol Nishizaki)
e
s 00001/00001/00203
d D 1.2 81/03/07 17:36:04 mckusic 2 1
c merge in onyx changes
e
s 00204/00000/00000
d D 1.1 81/03/02 21:29:12 peter 1 0
c date and time created 81/03/02 21:29:12 by peter
e
u
U
t
T
I 1
D 3
static	char *sccsid = "%W% (Berkeley) %G%";
E 3
D 5
/* Copyright (c) 1979 Regents of the University of California */
E 5
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 5
D 3
#
E 3
I 3

D 5
static	char *sccsid = "%W% (Berkeley) %G%";
E 5
I 5
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 5

E 3
/*
 * pxp - Pascal execution profiler
 *
 * Bill Joy UCB
 * Version 1.2 January 1979
 */

#include "0.h"
#include "tree.h"

D 2
STATIC	int typecnt -1;
E 2
I 2
STATIC	int typecnt = -1;
E 2
/*
 * Type declaration part
 */
typebeg(l, tline)
	int l, tline;
{

	line = l;
	if (nodecl)
		printoff();
	puthedr();
	putcm();
	ppnl();
	indent();
	ppkw("type");
	ppgoin(DECL);
	typecnt = 0;
	setline(tline);
}

type(tline, tid, tdecl)
	int tline;
	char *tid;
	int *tdecl;
{

	if (typecnt)
		putcm();
	setline(tline);
	ppitem();
	ppid(tid);
	ppsep(" =");
	gtype(tdecl);
	ppsep(";");
	setinfo(tline);
	putcml();
	typecnt++;
}

typeend()
{

	if (typecnt == -1)
		return;
	if (typecnt == 0)
		ppid("{type decls}");
	ppgoout(DECL);
	typecnt = -1;
}

/*
 * A single type declaration
 */
gtype(r)
	register int *r;
{

	if (r == NIL) {
		ppid("{type}");
		return;
	}
	if (r[0] != T_ID && r[0] != T_TYPACK)
		setline(r[1]);
	switch (r[0]) {
		default:
			panic("type");
		case T_ID:
			ppspac();
			ppid(r[1]);
			return;
		case T_TYID:
			ppspac();
			ppid(r[2]);
			break;
		case T_TYSCAL:
			ppspac();
			tyscal(r);
			break;
I 3
		case T_TYCRANG:
			ppspac();
			tycrang(r);
			break;
E 3
		case T_TYRANG:
			ppspac();
			tyrang(r);
			break;
		case T_TYPTR:
			ppspac();
			ppop("^");
			gtype(r[2]);
			break;
		case T_TYPACK:
			ppspac();
			ppkw("packed");
			gtype(r[2]);
			break;
I 3
		case T_TYCARY:
E 3
		case T_TYARY:
			ppspac();
			tyary(r);
			break;
		case T_TYREC:
			ppspac();
			tyrec(r[2], NIL);
			break;
		case T_TYFILE:
			ppspac();
			ppkw("file");
			ppspac();
			ppkw("of");
			gtype(r[2]);
			break;
		case T_TYSET:
			ppspac();
			ppkw("set");
			ppspac();
			ppkw("of");
			gtype(r[2]);
			break;
	}
	setline(r[1]);
	putcml();
}

/*
 * Scalar type declaration
 */
tyscal(r)
	register int *r;
{
	register int i;

	ppsep("(");
	r = r[2];
	if (r != NIL) {
		i = 0;
		ppgoin(DECL);
		for (;;) {
			ppid(r[1]);
			r = r[2];
			if (r == NIL)
				break;
			ppsep(", ");
			i++;
			if (i == 7) {
				ppitem();
				i = 0;
			}
		}
		ppgoout(DECL);
	} else
		ppid("{constant list}");
	ppsep(")");
I 3
}

/*
 * Conformant array subrange.
 */
tycrang(r)
	register int *r;
{

	ppid(r[2]);
	ppsep("..");
	ppid(r[3]);
	ppsep(":");
	gtype(r[4]);
E 3
}

/*
 * Subrange type declaration
 */
tyrang(r)
	register int *r;
{

	gconst(r[2]);
	ppsep("..");
	gconst(r[3]);
}

/*
 * Array type declaration
 */
tyary(r)
	register int *r;
{
	register int *tl;

	ppkw("array");
	ppspac();
	ppsep("[");
	tl = r[2];
	if (tl != NIL) {
		ppunspac();
		for (;;) {
			gtype(tl[1]);
			tl = tl[2];
			if (tl == NIL)
				break;
			ppsep(",");
		}
	} else
		ppid("{subscr list}");
	ppsep("]");
	ppspac();
	ppkw("of");
	gtype(r[3]);
}
E 1
