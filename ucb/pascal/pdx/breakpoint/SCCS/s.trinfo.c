h45056
s 00008/00000/00192
d D 5.2 87/04/07 15:52:31 mckusick 4 3
c port to tahoe by Nir peleg of CCI
e
s 00008/00002/00184
d D 5.1 85/06/05 17:00:12 dist 3 2
c Add copyright
e
s 00100/00096/00086
d D 1.2 82/02/11 23:51:54 linton 2 1
c modifications for centralizing the printing of a source line 
c and file
e
s 00182/00000/00000
d D 1.1 82/01/18 19:20:04 linton 1 0
c date and time created 82/01/18 19:20:04 by linton
e
u
U
t
T
I 1
D 3
/* Copyright (c) 1982 Regents of the University of California */
E 3
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 3

D 3
static char sccsid[] = "%Z%%M% %I% %G%";
E 3
I 3
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 3

/*
 * Trace information management.
 *
 * The trace information is a list of variables that are being
 * traced or whose value changing should cause a stop.
 */

#include "defs.h"
#include "breakpoint.h"
#include "process.h"
#include "machine.h"
#include "sym.h"
#include "tree.h"
#include "source.h"
#include "object.h"
#include "tree/tree.rep"
I 4
#include "process/process.rep"
#include "process/pxinfo.h"
E 4

/*
 * When tracing variables we keep a copy of their most recent value
 * and compare it to the current one each time a breakpoint occurs.
 * MAXTRSIZE is the maximum size variable we allow.
 */

#define MAXTRSIZE 512

/*
 * The tracing structure is a list of information about all the
 * variables that are being traced.
 */

typedef struct trinfo {
D 2
	TRTYPE trtype;
	ADDRESS traddr;
	SYM *trblock;
	NODE *trvar;
	NODE *trcond;
	char *trvalue;
	struct trinfo *trnext;
E 2
I 2
    TRTYPE trtype;
    ADDRESS traddr;
    SYM *trblock;
    NODE *trvar;
    NODE *trcond;
    char *trvalue;
    struct trinfo *trnext;
E 2
} TRINFO;

LOCAL TRINFO *trhead;

/*
 * add a variable to be traced
 */

addvar(trtype, node, cond)
TRTYPE trtype;
NODE *node;
NODE *cond;
{
D 2
	register TRINFO *tp;
E 2
I 2
    register TRINFO *tp;
E 2

D 2
	tp = alloc(1, TRINFO);
	tp->trtype = trtype;
	tp->traddr = (ADDRESS) -1;
	tp->trblock = curfunc;
	tp->trvar = node;
	tp->trcond = cond;
	tp->trvalue = NIL;
	tp->trnext = trhead;
	trhead = tp;
E 2
I 2
    tp = alloc(1, TRINFO);
    tp->trtype = trtype;
    tp->traddr = (ADDRESS) -1;
    tp->trblock = curfunc;
    tp->trvar = node;
    tp->trcond = cond;
    tp->trvalue = NIL;
    tp->trnext = trhead;
    trhead = tp;
E 2
}

/*
 * remove a variable from the trace list
 */

delvar(trtype, node, cond)
TRTYPE trtype;
NODE *node;
NODE *cond;
{
D 2
	register TRINFO *tp, *last;
E 2
I 2
    register TRINFO *tp, *last;
E 2

D 2
	last = NIL;
	for (tp = trhead; tp != NIL; tp = tp->trnext) {
		if (tp->trtype == trtype &&
		    tr_equal(tp->trvar, node) &&
		    tr_equal(tp->trcond, cond)) {
			break;
		}
E 2
I 2
    last = NIL;
    for (tp = trhead; tp != NIL; tp = tp->trnext) {
	if (tp->trtype == trtype &&
	    tr_equal(tp->trvar, node) &&
	    tr_equal(tp->trcond, cond)) {
	    break;
E 2
	}
D 2
	if (tp == NIL) {
		trerror("can't delete term %t", node);
	}
	if (last == NIL) {
		trhead = tp->trnext;
	} else {
		last->trnext = tp->trnext;
	}
	if (tp->trvalue != NIL) {
		free(tp->trvalue);
	}
	free(tp);
E 2
I 2
    }
    if (tp == NIL) {
	trerror("can't delete term %t", node);
    }
    if (last == NIL) {
	trhead = tp->trnext;
    } else {
	last->trnext = tp->trnext;
    }
    if (tp->trvalue != NIL) {
	free(tp->trvalue);
    }
    free(tp);
E 2
}

/*
 * Print out any news about variables in the list whose
 * values have changed.
 */

prvarnews()
{
D 2
	register TRINFO *tp;
	register NODE *p;
	register int n;
	SYM *s;
	char buff[MAXTRSIZE];
	static LINENO prevline;
E 2
I 2
    register TRINFO *tp;
    register NODE *p;
    register int n;
    SYM *s;
    char buff[MAXTRSIZE];
    static LINENO prevline;
E 2

D 2
	for (tp = trhead; tp != NIL; tp = tp->trnext) {
		if (tp->trcond != NIL && !cond(tp->trcond)) {
			continue;
		}
		s = curfunc;
		while (s != NIL && s != tp->trblock) {
			s = container(s);
		}
		if (s == NIL) {
			continue;
		}
		p = tp->trvar;
		if (tp->traddr == (ADDRESS) -1) {
			tp->traddr = lval(p->left);
		}
		n = size(p->nodetype);
		dread(buff, tp->traddr, n);
		if (tp->trvalue == NIL) {
			tp->trvalue = alloc(n, char);
			mov(buff, tp->trvalue, n);
			mov(buff, sp, n);
			sp += n;
			if (tp->trtype == TRPRINT) {
				printf("initially (at line %d):\t", curline);
				prtree(p);
				printf(" = ");
				printval(p->nodetype);
				putchar('\n');
			}
		} else if (cmp(tp->trvalue, buff, n) != 0) {
			mov(buff, tp->trvalue, n);
			mov(buff, sp, n);
			sp += n;
			printf("after line %d:\t", prevline);
			prtree(p);
			printf(" = ");
			printval(p->nodetype);
			putchar('\n');
			if (tp->trtype == TRSTOP) {
				isstopped = TRUE;
				getsrcinfo();
				printstatus();
			}
		}
E 2
I 2
    for (tp = trhead; tp != NIL; tp = tp->trnext) {
	if (tp->trcond != NIL && !cond(tp->trcond)) {
	    continue;
E 2
	}
D 2
	prevline = curline;
E 2
I 2
	s = curfunc;
	while (s != NIL && s != tp->trblock) {
	    s = container(s);
	}
	if (s == NIL) {
	    continue;
	}
	p = tp->trvar;
	if (tp->traddr == (ADDRESS) -1) {
	    tp->traddr = lval(p->left);
	}
	n = size(p->nodetype);
	dread(buff, tp->traddr, n);
	if (tp->trvalue == NIL) {
	    tp->trvalue = alloc(n, char);
	    mov(buff, tp->trvalue, n);
	    mov(buff, sp, n);
	    sp += n;
I 4
#ifdef tahoe
	    alignstack();
#endif
E 4
	    if (tp->trtype == TRPRINT) {
		printf("initially (at ");
		printwhere(curline, srcfilename(pc));
		printf("):\t");
		prtree(p);
		printf(" = ");
		printval(p->nodetype);
		putchar('\n');
	    }
	} else if (cmp(tp->trvalue, buff, n) != 0) {
	    mov(buff, tp->trvalue, n);
	    mov(buff, sp, n);
	    sp += n;
I 4
#ifdef tahoe
	    alignstack();
#endif
E 4
	    printf("after ");
	    printwhere(prevline, srcfilename(pc));
	    printf(":\t");
	    prtree(p);
	    printf(" = ");
	    printval(p->nodetype);
	    putchar('\n');
	    if (tp->trtype == TRSTOP) {
		isstopped = TRUE;
		curline = srcline(pc);
		printstatus();
	    }
	}
    }
    prevline = curline;
E 2
}

/*
 * Free the table.  Note that trvar and trcond fields are not freed,
 * this is because they are the same as in the breakpoint table and
 * are freed by the bpfree routine.
 */

trfree()
{
D 2
	register TRINFO *tp, *next;
E 2
I 2
    register TRINFO *tp, *next;
E 2

D 2
	for (tp = trhead; tp != NIL; tp = next) {
		next = tp->trnext;
		if (tp->trvalue != NIL) {
			free(tp->trvalue);
		}
		free(tp);
E 2
I 2
    for (tp = trhead; tp != NIL; tp = next) {
	next = tp->trnext;
	if (tp->trvalue != NIL) {
	    free(tp->trvalue);
E 2
	}
D 2
	trhead = NIL;
E 2
I 2
	free(tp);
    }
    trhead = NIL;
E 2
}
E 1
