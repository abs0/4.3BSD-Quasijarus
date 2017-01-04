h58523
s 00003/00003/00276
d D 5.2 87/03/17 20:23:35 lepreau 6 5
c get rid of old-style asgop syntax
e
s 00010/00003/00269
d D 5.1 85/06/05 15:46:43 dist 5 4
c Add copyright
e
s 00000/00000/00272
d D 2.1 84/02/08 20:23:25 aoki 4 3
c synchronizing at version 2
e
s 00003/00001/00269
d D 1.3 82/08/12 00:09:41 mckusick 3 2
c only complain in segend when actually trying to profile
e
s 00034/00001/00236
d D 1.2 82/08/11 23:17:29 mckusick 2 1
c add grammar rules to handle separate compilation and parametric routines.
e
s 00237/00000/00000
d D 1.1 81/03/02 21:28:07 peter 1 0
c date and time created 81/03/02 21:28:07 by peter
e
u
U
t
T
I 1
D 2
static	char *sccsid = "%W% (Berkeley) %G%";
E 2
D 5
/* Copyright (c) 1979 Regents of the University of California */
#
I 2
static	char *sccsid = "%W% (Berkeley) %G%";
E 5
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 5
E 2
/*
 * pxp - Pascal execution profiler
 *
 * Bill Joy UCB
 * Version 1.2 January 1979
 */

#include "0.h"
#include "tree.h"

/*
 * Program, procedure or function "header", i.e.:
 *
 *	function sin: real;
 */
funchdr(r)
	int *r;
{
	register **rl, *il;

	if (inpflist(r[2])) {
D 6
		optstk['z'-'a'] =<< 1;
		optstk['z'-'a'] =| opts['z'-'a'];
E 6
I 6
		optstk['z'-'a'] <<= 1;
		optstk['z'-'a'] |= opts['z'-'a'];
E 6
		opts['z'-'a'] = 1;
	}
	cbn++;
	lastbn = cbn;
	getcnt();
	if (nojunk && !inpflist(r[2]))
		setprint();
	else
		printon();
	if (r[0] == T_PROG && noinclude && bracket)
		printoff();
	if (cbn > 1 && !justify)
		ppgoin(PRFN);
	puthedr();
	if (noblank(setline(r[1])))
		ppnl();
	cnttab(r[2], pfcnt++);
	ppnl();
	indent();
	switch (r[0]) {
		case T_PROG:
			ppkw("program");
			break;
		case T_PDEC:
			ppkw("procedure");
			break;
		case T_FDEC:
			ppkw("function");
			break;
		default:
			panic("funchdr");
	}
	ppspac();
	ppid(r[2]);
	if (r[0] != T_PROG) {
		rl = r[3];
		if (rl != NIL) {
			ppbra("(");
			for (;;) {
				if (rl[1] == NIL) {
					rl = rl[2];
					continue;
				}
				switch (rl[1][0]) {
					case T_PVAR:
						ppkw("var");
						ppspac();
						break;
					case T_PPROC:
						ppkw("procedure");
						ppspac();
						break;
					case T_PFUNC:
						ppkw("function");
						ppspac();
						break;
				}
				il = rl[1][1];
				if (il != NIL)
					for (;;) {
						ppid(il[1]);
						il = il[2];
						if (il == NIL)
							break;
						ppsep(", ");
					}
				else
					ppid("{identifier list}");
				if (rl[1][0] != T_PPROC) {
					ppsep(":");
					gtype(rl[1][2]);
				}
				rl = rl[2];
				if (rl == NIL)
					break;
				ppsep(";");
				ppspac();
			}
			ppket(")");
		}
		if (r[0] == T_FDEC && r[4] != NIL) {
			ppsep(":");
			gtype(r[4]);
		}
		ppsep(";");
	} else {
		rl = r[3];
		if (rl != NIL) {
			ppbra("(");
			for (;;) {
				ppid(rl[1]);
				rl = rl[2];
				if (rl == NIL)
					break;
				ppsep(", ");
			}
			ppket(")");
		}
		ppsep(";");
	}
fhout:
	setline(r[1]);
	putcml();
	savecnt(&pfcnts[cbn]);
	setprint();
	--cbn;
	if (cbn && !justify)
		ppgoout(PRFN);
	return (r[2]);
}

/*
 * Forward declaration i.e. the second line of
 *
 *	procedure fum(var i: integer);
 *	    forward;
 */
funcfwd(fp)
	char *fp;
{

	baroff();
	ppgoin(DECL);
	ppnl();
	indent();
	ppkw("forward");
	ppsep(";");
	ppgoout(DECL);
	baron();
	return (fp);
}

/*
 * The "body" of a procedure, function, or program declaration,
 * i.e. a non-forward definition encounter.
 */
funcbody(fp)
	char *fp;
{

	if (cbn && !justify)
		ppgoin(PRFN);
	cbn++;
	lastbn = cbn;
	return (fp);
}

/*
 * The guts of the procedure, function or program, i.e.
 * the part between the begin and the end.
 */
funcend(fp, bundle, binfo)
	char *fp;
	int *bundle, *binfo;
{
	int *blk;
	extern int cntstat;

	cntstat = 0;
	blk = bundle[2];
	rescnt(&pfcnts[cbn]);
	setprint();
	if (cbn == 1 && noinclude && bracket)
		printoff();
	if (lastbn > cbn)
		unprint();
	if (cbn == 1)
		puthedr();
	if (noblank(setline(bundle[1])) && lastbn > cbn)
		ppnl();
	ppnl();
	indent();
	ppkw("begin");
	setline(bundle[1]);
	if (putcml() == 0 && lastbn > cbn)
		ppsname(fp);
	ppgoin(DECL);
	statlist(blk);
	setinfo(bundle[1]);
	putcmp();
	ppgoout(DECL);
	ppnl();
	indent();
	ppkw("end");
	ppsep(cbn == 1 ? "." : ";");
	setinfo(binfo);
	if (putcml() == 0)
		ppsname(fp);
	cbn--;
	if (cbn && !justify)
		ppgoout(PRFN);
	if (inpflist(fp)) {
		opts['z'-'a'] = optstk['z'-'a'] & 1;
D 6
		optstk['z'-'a'] =>> 1;
E 6
I 6
		optstk['z'-'a'] >>= 1;
E 6
	}
	if (cbn == 0) {
		flushcm();
		printon();
		ppnl();
	}
}

ppsname(fp)
	char *fp;
{
	if (fp == NIL)
		return;
	ppsep(" { ");
	ppid(fp);
	ppsep(" }");
I 2
}

/*
 * Segend is called at the end of a routine segment (a separately
 * compiled segment that is not the main program). Since pxp only works
 * with a single pascal file, this routine should never be called.
 */
segend()
{

D 3
	error("Missing program statement and program body");
E 3
I 3
	if ( profile ) {
	    error("Missing program statement and program body");
	}
E 3
}

/*
 * External declaration i.e. the second line of
 *
 *	procedure fum(var i: integer);
 *	    external;
 */
struct nl *
funcext(fp)
	struct nl *fp;
{

	baroff();
	ppgoin(DECL);
	ppnl();
	indent();
	ppkw("external");
	ppsep(";");
	ppgoout(DECL);
	baron();
	return (fp);
E 2
}
E 1
