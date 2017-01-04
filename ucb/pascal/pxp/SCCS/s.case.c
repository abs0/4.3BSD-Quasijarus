h43357
s 00010/00003/00110
d D 5.1 85/06/05 15:45:14 dist 4 3
c Add copyright
e
s 00000/00000/00113
d D 2.1 84/02/08 20:21:52 aoki 3 2
c synchronizing at version 2
e
s 00027/00000/00086
d D 1.2 83/05/12 13:51:51 peter 2 1
c hooks for rmothers.
e
s 00086/00000/00000
d D 1.1 81/03/02 21:27:57 peter 1 0
c date and time created 81/03/02 21:27:57 by peter
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

/*
 * Case statement
I 2
 *	r	[0]	T_CASE
 *		[1]	lineof "case"
 *		[2]	expression
 *		[3]	list of cased statements:
 *			cstat	[0]	T_CSTAT
 *				[1]	lineof ":"
 *				[2]	list of constant labels
 *				[3]	statement
E 2
 */
caseop(r)
	int *r;
{
	register *cl, *cs, i;
	struct pxcnt scnt;
I 2
#	ifdef RMOTHERS
	    int *othersp;		/* tree where others is, or NIL */
	    int hasothers;		/* 1 if others found, else 0 */
#	endif RMOTHERS
E 2

I 2
#	ifdef RMOTHERS
	    if (rmothers) {
		hasothers = needscaseguard(r,&othersp);
		if (hasothers) {
		    precaseguard(r);
		}
	    }
#	endif RMOTHERS
E 2
	savecnt(&scnt);
	ppkw("case");
	ppspac();
	rvalue(r[2], NIL);
	ppspac();
	ppkw("of");
	for (cl = r[3]; cl != NIL;) {
		cs = cl[1];
		if (cs == NIL)
			continue;
		baroff();
		ppgoin(DECL);
		setline(cs[1]);
		ppnl();
		indent();
		ppbra(NIL);
		cs = cs[2];
		if (cs != NIL) {
			i = 0;
			for (;;) {
				gconst(cs[1]);
				cs = cs[2];
				if (cs == NIL)
					break;
				i++;
				if (i == 7) {
					ppsep(",");
					ppitem();
					i = 0;
				} else
					ppsep(", ");
			}
		} else
			ppid("{case label list}");
		ppket(":");
		cs = cl[1];
		cs = cs[3];
		getcnt();
		ppgoin(STAT);
		if (cs != NIL && cs[0] == T_BLOCK) {
			ppnl();
			indent();
			baron();
			ppstbl1(cs, STAT);
			baroff();
			ppstbl2();
			baron();
		} else {
			baron();
			statement(cs);
		}
		ppgoout(STAT);
		ppgoout(DECL);
		cl = cl[2];
		if (cl == NIL)
			break;
		ppsep(";");
	}
	if (rescnt(&scnt))
		getcnt();
	ppnl();
	indent();
	ppkw("end");
I 2
#	ifdef RMOTHERS
	    if (rmothers) {
		if (hasothers) {
		    postcaseguard(othersp);
		}
	    }
#	endif RMOTHERS
E 2
}
E 1
