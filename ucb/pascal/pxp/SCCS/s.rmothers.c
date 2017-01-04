h42278
s 00010/00002/00182
d D 5.1 85/06/05 15:50:44 dist 5 4
c Add copyright
e
s 00000/00000/00184
d D 2.1 84/02/08 20:23:58 aoki 4 3
c synchronizing at version 2
e
s 00009/00002/00175
d D 1.3 83/07/26 11:12:41 peter 3 2
c empty others clauses cause else clauses with null statement.
e
s 00003/00000/00174
d D 1.2 83/06/01 17:18:56 peter 2 1
c check for empty others clause.
e
s 00174/00000/00000
d D 1.1 83/05/12 13:44:15 peter 1 0
c date and time created 83/05/12 13:44:15 by peter
e
u
U
t
T
I 1
D 5
static	char *sccsid = "%W% (Berkeley) %G%";
/* Copyright (c) 1983 Regents of the University of California */
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
#ifdef RMOTHERS
    /* and the rest of the file */

#include "0.h"
#include "tree.h"

    /*
     *	translate extended case statements to pascal (for tex).
     *	don knuth should know better.  enough said.
     *		... peter 5/4/83
     *
     *	extended case statements have the form:
     *	    case expresion of
     *		label1,label2,...: statement1;
     *		...
     *		others: otherstatement
     *		end
     *	which i am going to translate to:
     *	    if expression in [ label1,label2,...] then
     *		case expression of
     *		    label1,label2,...: statement1;
     *		    ...
     *		    end
     *	    else otherstatement
     *	which has the effect that the expression will be evaluated twice.
     *	i've looked very briefly at all cases in tex and
     *	they seem to be variables or pure functions.
     *	for simplicity i'm assuming that the others is the last labeled
     *	statement, and that no other labels appear with the label others.
     *	this appears correct from the tex82 documentation.
     */

    /*
     *	given a case statement tree and the address of an others pointer,
     *	amputate the others statement from the case statement tree
     *	and hang it on the the others pointer.
     *
     *	Case statement
     *	r	[0]	T_CASE
     *		[1]	lineof "case"
     *		[2]	expression
     *		[3]	list of cased statements:
     *			cstat	[0]	T_CSTAT
     *				[1]	lineof ":"
     *				[2]	list of constant labels
     *				[3]	statement
     */
needscaseguard(r, otherspp)
    int	*r;
    int	**otherspp;
{
    int	*statlistp;
    int	*cutpointer;
    int	*lstatementp;
    int	*lablistp;
    int	*label;
    int	hasothers;

    *otherspp = NIL;
    hasothers = 0;
    if (!rmothers) {
	return hasothers;
    }
    for (cutpointer = &r[3], statlistp = r[3];
	 statlistp != NIL;
	 cutpointer = &statlistp[2], statlistp = statlistp[2]) {
	lstatementp = statlistp[1];
	if (lstatementp == NIL)
	    continue;
	lablistp = lstatementp[2];
	if (lablistp != NIL) {
	    label = lablistp[1];
		/* only look at the first label */
	    if (label != NIL &&
		label[0] == T_ID && !strcmp(label[1],"others")) {
		    hasothers = 1;
		    *otherspp = lstatementp[3];
		    *cutpointer = NIL;
		    if (statlistp[2] != NIL) {
			panic("others not last case");
		    }
		    if (lablistp[2] != NIL) {
			panic("others not only case label");
		    }
	    }
	}
    }
    return hasothers;
}

precaseguard(r)
    int	*r;
{
    int	*statlistp;
    int	*cutpointer;
    int	*lstatementp;
    int	*lablistp;
    int	*label;
    int	hadsome;
    int	counter;

    if (!rmothers) {
	return;
    }
    ppkw("if");
    ppspac();
    rvalue(r[2], NIL);
    ppspac();
    ppkw("in");
    ppgoin(DECL);
    ppnl();
    indent();
    ppsep("[");
    hadsome = 0;
    counter = 0;
    for (statlistp = r[3]; statlistp != NIL; statlistp = statlistp[2]) {
	lstatementp = statlistp[1];
	if (lstatementp == NIL)
	    continue;
	for (lablistp = lstatementp[2];lablistp != NIL;lablistp = lablistp[2]) {
	    label = lablistp[1];
	    if (hadsome) {
		if (counter < 8) {
		    ppsep(", ");
		} else {
		    ppsep(",");
		    ppnl();
		    indent();
		    ppspac();
		    counter = 0;
		}
	    } else {
		hadsome = 1;
	    }
	    gconst(label);
	    counter += 1;
	}
    }
    ppsep("]");
    ppspac();
    ppkw("then");
    ppgoout(DECL);
    ppgoin(STAT);
    ppnl();
    indent();
}

    /*
     *	given an others statement, hang it on the else branch of the guard.
     */
postcaseguard(othersp)
    int	*othersp;
{
    if (!rmothers) {
	return;
    }
    ppgoout(STAT);
    ppnl();
    indent();
I 3
    ppkw("else");
    ppgoin(STAT);
E 3
I 2
    if (othersp == NIL) {
I 3
	    /*
	     *	this will print a call to the routine ``null''.
	     *	but it has to be checked first, or we will indirect through
	     *	NIL to check the statement type.
	     */
	statement(NIL);
	ppgoout(STAT);
E 3
	return;
    }
E 2
D 3
    ppkw("else");
    ppgoin(STAT);
E 3
    if (othersp[0] == T_BLOCK) {
	ppnl();
	indent();
	ppstbl1(othersp, STAT);
	ppstbl2();
    } else {
	statement(othersp);
    }
    ppgoout(STAT);
}
#endif RMOTHERS
E 1
