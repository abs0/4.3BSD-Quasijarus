h55517
s 00005/00001/00275
d D 5.2 86/01/10 16:30:38 donn 10 9
c If $unsafeassign is set, override typechecking for assign commands.
c Lhs and rhs must still have the same size.
e
s 00008/00002/00268
d D 5.1 85/05/31 09:56:08 dist 9 8
c Add copyright
e
s 00058/00000/00212
d D 1.7 85/03/01 20:19:04 linton 8 7
c update to version 3.0
e
s 00001/00003/00211
d D 1.6 84/06/23 11:39:38 sam 7 5
i 6
c merge linton branch delta trail
e
s 00038/00008/00176
d D 1.5.1.1 84/06/23 10:44:49 sam 6 5
c branch delta of linton changes from net.sources
e
s 00001/00001/00183
d D 1.5 83/08/10 05:44:38 linton 5 4
c removed unnecessary complaint about "stopi <address>"
e
s 00000/00002/00184
d D 1.4 83/07/08 00:42:33 linton 4 3
c fixed problem with "stop at <line> if <cond>"
e
s 00001/00001/00185
d D 1.3 82/12/20 22:35:56 linton 3 2
c fixed tracing functions
e
s 00001/00001/00185
d D 1.2 82/12/15 04:19:43 linton 2 1
c fixed @(#) stuff
e
s 00186/00000/00000
d D 1.1 82/12/15 04:07:15 linton 1 0
c date and time created 82/12/15 04:07:15 by linton
e
u
U
f b 
t
T
I 1
D 9
/* Copyright (c) 1982 Regents of the University of California */
E 9
I 9
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 9

D 2
static char sccsid[] = "@(#)%Z%%M% %I% %G%";
E 2
I 2
D 6
static char sccsid[] = "%Z%%M% %I% %G%";
E 6
I 6
D 7
static char sccsid[] = "@(#)check.c 1.5 8/10/83";
E 6
E 2

I 6
static char rcsid[] = "$Header: check.c,v 1.3 84/03/27 10:19:54 linton Exp $";
E 7
I 7
D 9
static	char sccsid[] = "%W% (Berkeley) %G%";
E 9
I 9
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 9
E 7

I 8
static char rcsid[] = "$Header: check.c,v 1.5 84/12/26 10:38:35 linton Exp $";

E 8
E 6
/*
 * Check a tree for semantic correctness.
 */

#include "defs.h"
#include "tree.h"
#include "operators.h"
#include "events.h"
#include "symbols.h"
#include "scanner.h"
#include "source.h"
#include "object.h"
#include "mappings.h"
#include "process.h"
I 8
#include <signal.h>
E 8

#ifndef public
#endif

/*
 * Check that the nodes in a tree have the correct arguments
 * in order to be evaluated.  Basically the error checking here
 * frees the evaluation routines from worrying about anything
 * except dynamic errors, e.g. subscript out of range.
 */

public check(p)
register Node p;
{
I 8
    Node p1, p2;
E 8
    Address addr;
    Symbol f;

    checkref(p);
    switch (p->op) {
I 8
	case O_ASSIGN:
	    p1 = p->value.arg[0];
	    p2 = p->value.arg[1];
D 10
	    if (not compatible(p1->nodetype, p2->nodetype)) {
E 10
I 10
	    if (varIsSet("$unsafeassign")) {
		if (size(p1->nodetype) != size(p2->nodetype)) {
		    error("incompatible sizes");
		}
	    } else if (not compatible(p1->nodetype, p2->nodetype)) {
E 10
		error("incompatible types");
	    }
	    break;

	case O_CATCH:
	case O_IGNORE:
	    if (p->value.lcon < 0 or p->value.lcon > NSIG) {
		error("invalid signal number");
	    }
	    break;

	case O_CONT:
	    if (p->value.lcon != DEFSIG and (
		p->value.lcon < 0 or p->value.lcon > NSIG)
	    ) {
		error("invalid signal number");
	    }
	    break;

	case O_DUMP:
	    if (p->value.arg[0] != nil) {
		if (p->value.arg[0]->op == O_SYM) {
		    f = p->value.arg[0]->value.sym;
		    if (not isblock(f)) {
			error("\"%s\" is not a block", symname(f));
		    }
		} else {
		    beginerrmsg();
		    fprintf(stderr, "expected a symbol, found \"");
		    prtree(stderr, p->value.arg[0]);
		    fprintf(stderr, "\"");
		    enderrmsg();
		}
	    }
	    break;

E 8
	case O_LIST:
	    if (p->value.arg[0]->op == O_SYM) {
		f = p->value.arg[0]->value.sym;
		if (not isblock(f) or ismodule(f)) {
		    error("\"%s\" is not a procedure or function", symname(f));
		}
		addr = firstline(f);
		if (addr == NOADDR) {
		    error("\"%s\" is empty", symname(f));
		}
	    }
	    break;

	case O_TRACE:
	case O_TRACEI:
	    chktrace(p);
	    break;

	case O_STOP:
	case O_STOPI:
	    chkstop(p);
	    break;

I 8
	case O_CALLPROC:
E 8
I 6
	case O_CALL:
	    if (not isroutine(p->value.arg[0]->nodetype)) {
		beginerrmsg();
		fprintf(stderr, "\"");
		prtree(stderr, p->value.arg[0]);
		fprintf(stderr, "\" not call-able");
		enderrmsg();
	    }
	    break;

I 8
	case O_WHEREIS:
	    if (p->value.arg[0]->op == O_SYM and
	      p->value.arg[0]->value.sym == nil) {
		error("symbol not defined");
	    }
	    break;

E 8
E 6
	default:
	    break;
    }
}

/*
 * Check arguments to a trace command.
 */

private chktrace(p)
Node p;
{
    Node exp, place, cond;

    exp = p->value.arg[0];
    place = p->value.arg[1];
    cond = p->value.arg[2];
    if (exp == nil) {
	chkblock(place);
    } else if (exp->op == O_LCON or exp->op == O_QLINE) {
	if (place != nil) {
	    error("unexpected \"at\" or \"in\"");
	}
	if (p->op == O_TRACE) {
	    chkline(exp);
	} else {
	    chkaddr(exp);
	}
    } else if (place != nil and (place->op == O_QLINE or place->op == O_LCON)) {
	if (p->op == O_TRACE) {
	    chkline(place);
	} else {
	    chkaddr(place);
	}
    } else {
D 3
	if (exp->op != O_RVAL and exp->op != O_SYM) {
E 3
I 3
	if (exp->op != O_RVAL and exp->op != O_SYM and exp->op != O_CALL) {
E 3
	    error("can't trace expressions");
	}
	chkblock(place);
    }
}

/*
 * Check arguments to a stop command.
 */

private chkstop(p)
Node p;
{
    Node exp, place, cond;

    exp = p->value.arg[0];
    place = p->value.arg[1];
    cond = p->value.arg[2];
    if (exp != nil) {
D 5
	if (exp->op != O_RVAL and exp->op != O_SYM) {
E 5
I 5
	if (exp->op != O_RVAL and exp->op != O_SYM and exp->op != O_LCON) {
E 5
	    beginerrmsg();
	    fprintf(stderr, "expected variable, found ");
	    prtree(stderr, exp);
	    enderrmsg();
	}
	chkblock(place);
D 4
    } else if (cond != nil) {
	chkblock(place);
E 4
D 6
    } else if (place->op == O_SYM) {
	chkblock(place);
    } else {
	if (p->op == O_STOP) {
	    chkline(place);
E 6
I 6
    } else if (place != nil) {
	if (place->op == O_SYM) {
	    chkblock(place);
E 6
	} else {
D 6
	    chkaddr(place);
E 6
I 6
	    if (p->op == O_STOP) {
		chkline(place);
	    } else {
		chkaddr(place);
	    }
E 6
	}
    }
}

/*
 * Check to see that the given node specifies some subprogram.
 * Nil is ok since that means the entire program.
 */

private chkblock(b)
Node b;
{
I 6
    Symbol p, outer;

E 6
    if (b != nil) {
	if (b->op != O_SYM) {
	    beginerrmsg();
	    fprintf(stderr, "expected subprogram, found ");
	    prtree(stderr, b);
	    enderrmsg();
D 6
	} else if (not isblock(b->value.sym) or ismodule(b->value.sym)) {
E 6
I 6
	} else if (ismodule(b->value.sym)) {
	    outer = b->value.sym;
	    while (outer != nil) {
		find(p, outer->name) where p->block == outer endfind(p);
		if (p == nil) {
		    outer = nil;
		    error("\"%s\" is not a subprogram", symname(b->value.sym));
		} else if (ismodule(p)) {
		    outer = p;
		} else {
		    outer = nil;
		    b->value.sym = p;
		}
	    }
I 8
	} else if (
	    b->value.sym->class == VAR and
	    b->value.sym->name == b->value.sym->block->name and
	    b->value.sym->block->class == FUNC
	) {
	    b->value.sym = b->value.sym->block;
E 8
	} else if (not isblock(b->value.sym)) {
E 6
	    error("\"%s\" is not a subprogram", symname(b->value.sym));
	}
    }
}

/*
 * Check to make sure a node corresponds to a source line.
 */

private chkline(p)
Node p;
{
    if (p == nil) {
	error("missing line");
    } else if (p->op != O_QLINE and p->op != O_LCON) {
	error("expected source line number, found \"%t\"", p);
    }
}

/*
 * Check to make sure a node corresponds to an address.
 */

private chkaddr(p)
Node p;
{
    if (p == nil) {
	error("missing address");
    } else if (p->op != O_LCON and p->op != O_QLINE) {
	beginerrmsg();
	fprintf(stderr, "expected address, found \"");
	prtree(stderr, p);
	fprintf(stderr, "\"");
	enderrmsg();
    }
}
E 1
