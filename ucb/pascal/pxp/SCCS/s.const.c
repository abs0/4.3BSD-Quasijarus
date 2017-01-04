h29255
s 00001/00001/00114
d D 5.2 88/01/03 00:21:12 bostic 5 4
c const is a reserved word in ANSI C
e
s 00010/00003/00105
d D 5.1 85/06/05 15:45:39 dist 4 3
c Add copyright
e
s 00000/00000/00108
d D 2.1 84/02/08 20:22:13 aoki 3 2
c synchronizing at version 2
e
s 00001/00001/00107
d D 1.2 81/03/07 17:34:42 mckusic 2 1
c merge in onyx changes
e
s 00108/00000/00000
d D 1.1 81/03/02 21:27:59 peter 1 0
c date and time created 81/03/02 21:27:59 by peter
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
STATIC	int constcnt -1;
E 2
I 2
STATIC	int constcnt = -1;
E 2

/*
 * The const declaration part
 */
constbeg(l, cline)
	int l, cline;
{

	line = l;
	if (nodecl)
		printoff();
	puthedr();
	putcm();
	ppnl();
	indent();
	ppkw("const");
	ppgoin(DECL);
	constcnt = 0;
	setline(cline);
}

D 5
const(cline, cid, cdecl)
E 5
I 5
constant(cline, cid, cdecl)
E 5
	int cline;
	char *cid;
	int *cdecl;
{

	if (constcnt)
		putcm();
	setline(cline);
	ppitem();
	ppid(cid);
	ppsep(" = ");
	gconst(cdecl);
	ppsep(";");
	constcnt++;
	setinfo(cline);
	putcml();
}

constend()
{

	if (constcnt == -1)
		return;
	if (nodecl)
		return;
	if (constcnt == 0)
		ppid("{const decls}");
	ppgoout(DECL);
	constcnt = -1;
}

/*
 * A constant in an expression
 * or a declaration.
 */
gconst(r)
	int *r;
{
	register *cn;

	cn = r;
loop:
	if (cn == NIL) {
		ppid("{constant}");
		return;
	}
	switch (cn[0]) {
		default:
			panic("gconst");
		case T_PLUSC:
			ppop("+");
			cn = cn[1];
			goto loop;
		case T_MINUSC:
			ppop("-");
			cn = cn[1];
			goto loop;
		case T_ID:
			ppid(cn[1]);
			return;
		case T_CBINT:
		case T_CINT:
		case T_CFINT:
			ppnumb(cn[1]);
			if (cn[0] == T_CBINT)
				ppsep("b");
			return;
		case T_CSTRNG:
			ppstr(cn[1]);
			return;
	}
}
E 1
