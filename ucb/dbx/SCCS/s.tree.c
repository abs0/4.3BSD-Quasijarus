h50065
s 00002/00001/00621
d D 5.3 88/01/12 01:28:18 donn 12 11
c merge in latest Linton version
e
s 00001/00001/00621
d D 5.2 87/04/06 12:04:38 bostic 11 10
c printf format/argument mismatch
e
s 00008/00002/00614
d D 5.1 85/05/31 10:19:36 dist 10 9
c Add copyright
e
s 00104/00127/00512
d D 1.8 85/03/01 20:32:43 linton 9 8
c update to version 3.0
e
s 00000/00004/00639
d D 1.7 84/08/12 15:14:25 sam 8 7
c handle signal lists (with names) for ignore and catch
e
s 00001/00003/00642
d D 1.6 84/06/23 11:44:15 sam 7 5
i 6
c merge linton branch delta trail
e
s 00004/00004/00641
d D 1.5.1.1 84/06/23 10:51:02 sam 6 5
c branch delta of linton changes from net.sources
e
s 00012/00002/00633
d D 1.5 83/08/10 06:15:52 linton 5 4
c changed printing out of tracing commands -- still not very satisfactory
e
s 00005/00000/00630
d D 1.4 83/05/18 21:54:11 csvaf 4 3
c added DEBUG operator
e
s 00001/00000/00629
d D 1.3 83/04/08 00:58:29 linton 3 2
c added an argument to the continue command to allow a signal to be 
c passed to the debuggee process
e
s 00001/00001/00628
d D 1.2 82/12/15 04:22:34 linton 2 1
c fixed @(#) stuff
e
s 00629/00000/00000
d D 1.1 82/12/15 04:08:53 linton 1 0
c date and time created 82/12/15 04:08:53 by linton
e
u
U
f b 
t
T
I 1
D 10
/* Copyright (c) 1982 Regents of the University of California */
E 10
I 10
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 10

D 2
static char sccsid[] = "@(#)%Z%%M% %I% %G%";
E 2
I 2
D 6
static char sccsid[] = "%Z%%M% %I% %G%";
E 6
I 6
D 7
static char sccsid[] = "@(#)tree.c 1.5 8/10/83";
E 6
E 2

I 6
static char rcsid[] = "$Header: tree.c,v 1.3 84/03/27 10:24:40 linton Exp $";
E 7
I 7
D 10
static	char sccsid[] = "%W% (Berkeley) %G%";
E 10
I 10
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 10
E 7

I 9
D 12
static char rcsid[] = "$Header: tree.c,v 1.5 84/12/26 10:42:55 linton Exp $";
E 12
I 12
static char rcsid[] = "$Header: tree.c,v 1.3 87/07/08 21:38:59 donn Exp $";
E 12

E 9
E 6
/*
 * Parse tree management.
 */

#include "defs.h"
#include "tree.h"
#include "operators.h"
I 9
#include "debug.h"
E 9
#include "eval.h"
#include "events.h"
#include "symbols.h"
#include "scanner.h"
#include "source.h"
#include "object.h"
#include "mappings.h"
#include "process.h"
#include "machine.h"

#ifndef public
#include "lists.h"

typedef struct Node *Node;
typedef Node Command;
typedef List Cmdlist;

#include "operators.h"
#include "symbols.h"
#include "events.h"

#define MAXNARGS 5

struct Node {
    Operator op;
    Symbol nodetype;
    union treevalue {
	Symbol sym;
	Name name;
	long lcon;
	double fcon;
	String scon;
	Node arg[MAXNARGS];
	struct {
	    Node cond;
	    Cmdlist actions;
	} event;
	struct {
	    Boolean inst;
	    Event event;
	    Cmdlist actions;
	} trace;
	struct {
	    Boolean source;
	    Boolean skipcalls;
	} step;
	struct {
	    String mode;
	    Node beginaddr;
	    Node endaddr;
	    Integer count;
	} examine;
    } value;
};

#define evalcmd(cmd) eval(cmd)
#define cmdlist_append(cmd, cl) list_append(list_item(cmd), nil, cl)

#endif

typedef char *Arglist;

#define nextarg(type)  ((type *) (ap += sizeof(type)))[-1]

/*
 * Build a tree.
 */

/* VARARGS1 */
public Node build(op, args)
Operator op;
{
    register Node p, q;
    register Arglist ap;
    Integer i;

    p = new(Node);
    p->op = op;
    p->nodetype = nil;
    ap = (Arglist) &args;
    switch (op) {
	case O_NAME:
	    p->value.name = nextarg(Name);
	    break;

	case O_SYM:
	case O_PRINTCALL:
	case O_PRINTRTN:
	case O_PROCRTN:
	    p->value.sym = nextarg(Symbol);
	    break;

I 4
	case O_DEBUG:
E 4
	case O_LCON:
I 9
	case O_CCON:
E 9
I 3
	case O_CONT:
I 9
	case O_CATCH:
	case O_IGNORE:
E 9
E 3
D 6
	case O_DELETE:
E 6
D 8
	case O_CATCH:
	case O_IGNORE:
E 8
	case O_TRACEOFF:
	    p->value.lcon = nextarg(long);
	    break;

	case O_FCON:
	    p->value.fcon = nextarg(double);
	    break;

	case O_SCON:
	case O_CHFILE:
	case O_EDIT:
	case O_SOURCE:
	    p->value.scon = nextarg(String);
	    break;

	case O_RVAL:
D 9
	    q = nextarg(Node);
	    if (q->op == O_CALL) {
		*p = *q;
		dispose(q);
	    } else {
		p->value.arg[0] = q;
	    }
E 9
I 9
	case O_INDIR:
	    p->value.arg[0] = nextarg(Node);
E 9
	    break;

D 9
	case O_INDIR:
E 9
I 9
	case O_CALL:
E 9
	    q = nextarg(Node);
D 9
	    if (q != nil and q->op == O_RVAL) {
E 9
I 9
	    if (q->op == O_SYM and
		(q->value.sym->class == TYPE or q->value.sym->class == TAG)
	    ) {
		p->op = O_TYPERENAME;
		p->value.arg[0] = nextarg(Node);
		p->value.arg[1] = q;
		q = p->value.arg[0];
		if (q->value.arg[1] != nil) {
		    error("too many arguments to type rename");
		}
E 9
		p->value.arg[0] = q->value.arg[0];
D 9
		dispose(q);
E 9
	    } else {
		p->value.arg[0] = q;
I 9
		p->value.arg[1] = nextarg(Node);
E 9
	    }
	    break;

	case O_ADDEVENT:
	case O_ONCE:
	case O_IF:
	    p->value.event.cond = nextarg(Node);
	    p->value.event.actions = nextarg(Cmdlist);
	    break;

	case O_TRACEON:
	    p->value.trace.inst = nextarg(Boolean);
	    p->value.trace.event = nil;
	    p->value.trace.actions = nextarg(Cmdlist);
	    break;

	case O_STEP:
	    p->value.step.source = nextarg(Boolean);
	    p->value.step.skipcalls = nextarg(Boolean);
	    break;

	case O_EXAMINE:
	    p->value.examine.mode = nextarg(String);
	    p->value.examine.beginaddr = nextarg(Node);
	    p->value.examine.endaddr = nextarg(Node);
	    p->value.examine.count = nextarg(Integer);
	    break;

	default:
	    for (i = 0; i < nargs(op); i++) {
		p->value.arg[i] = nextarg(Node);
	    }
	    break;
    }
    check(p);
    assigntypes(p);
I 4
D 9
    if(debug_flag[5]) {     
  	fprintf(stderr," built %s node %d with arg0 %d arg1 %d \n",
  	        showoperator(p->op), p, p->value.arg[0],p->value.arg[1]);
E 9
I 9
    if (tracetree) {     
	printf("built %s node 0x%x with arg[0] 0x%x arg[1] 0x%x\n",
	    opname(p->op), p, p->value.arg[0], p->value.arg[1]);
	fflush(stdout);
E 9
    }
E 4
    return p;
}

/*
D 9
 * Create a command list from a single command.
E 9
I 9
 * Strip away indirection from a node, thus returning a node for
 * interpreting the expression as an lvalue.
E 9
 */

D 9
public Cmdlist buildcmdlist(cmd)
Command cmd;
E 9
I 9
public Node unrval (exp)
Node exp;
E 9
{
D 9
    Cmdlist cmdlist;
E 9
I 9
    Node p;
    Symbol t;
E 9

D 9
    cmdlist = list_alloc();
    cmdlist_append(cmd, cmdlist);
    return cmdlist;
E 9
I 9
    if (exp->op == O_RVAL) {
	p = exp->value.arg[0];
	dispose(exp);
    } else if (exp->op == O_INDIR) {
	p = exp->value.arg[0];
	if (p->op == O_RVAL) {
	    p->op = O_INDIR;
	    p->nodetype = exp->nodetype;
	}
	dispose(exp);
    } else {
	p = exp;
    }
    return p;
E 9
}

/*
I 9
 * Create a node for renaming a node to a pointer type.
 */

public Node renameptr (p, t)
Node p;
Node t;
{
    t->nodetype = newSymbol(nil, 0, PTR, t->nodetype, nil);
    p = build(O_TYPERENAME, p, t);
}

/*
E 9
 * Return the tree for a unary ampersand operator.
 */

public Node amper(p)
Node p;
{
    Node r;

    checkref(p);
    switch (p->op) {
	case O_RVAL:
I 9
	case O_INDIR:
E 9
	    r = p->value.arg[0];
I 9
	    r->nodetype = t_addr;
	    dispose(p);
E 9
	    break;

D 9
	case O_CALL:
	    r = build(O_LCON, codeloc(p->value.arg[0]->value.sym));
	    tfree(p);
E 9
I 9
	case O_TYPERENAME:
	    r = p;
	    r->nodetype = newSymbol(nil, 0, PTR, r->nodetype, nil);
I 12
	    r->nodetype->language = p->nodetype->language;
E 12
E 9
	    break;

	case O_SYM:
	    if (isblock(p->value.sym)) {
		r = build(O_LCON, codeloc(p->value.sym));
	    } else {
		r = build(O_LCON, address(p->value.sym, nil));
	    }
D 9
	    tfree(p);
E 9
I 9
	    r->nodetype = t_addr;
	    dispose(p);
E 9
	    break;

	case O_DOT:
	    r = p;
I 9
	    r->nodetype = t_addr;
E 9
	    break;

D 9
	case O_INDIR:
	    r = p->value.arg[0];
	    dispose(p);
	    break;

E 9
	default:
	    beginerrmsg();
D 9
	    fprintf(stderr, "expected variable, found ");
E 9
I 9
	    fprintf(stderr, "expected variable, found \"");
E 9
	    prtree(stderr, p);
I 9
	    fprintf(stderr, "\"");
E 9
	    tfree(p);
	    enderrmsg();
	    /* NOTREACHED */
    }
D 9
    r->nodetype = t_int;
E 9
    return r;
}

/*
 * Create a "concrete" version of a node.
 * This is necessary when the type of the node contains
 * an unresolved type reference.
 */

public Node concrete(p)
Node p;
{
    findtype(p->nodetype);
    return build(O_INDIR, p);
}

/*
I 9
 * Create a command list from a single command.
 */

public Cmdlist buildcmdlist(cmd)
Command cmd;
{
    Cmdlist cmdlist;

    cmdlist = list_alloc();
    cmdlist_append(cmd, cmdlist);
    return cmdlist;
}

/*
E 9
 * Print out a command.
 */

public printcmd(f, cmd)
File f;
Command cmd;
{
    register Integer i;
    register Command c;
    register Node p;

    switch (cmd->op) {
	case O_PRINTIFCHANGED:
	case O_PRINTSRCPOS:
	case O_STOPIFCHANGED:
	case O_TRACEON:
	    break;

	case O_STEP:
	    if (cmd->value.step.skipcalls) {
		fprintf(f, "next");
	    } else {
		fprintf(f, "step");
	    }
	    if (not cmd->value.step.source) {
		fprintf(f, "i");
	    }
	    break;

	default:
	    fprintf(f, "%s", opinfo[ord(cmd->op)].opstring);
	    if (nargs(cmd->op) != 0) {
		fprintf(f, " ");
	    }
	    break;
    }
    switch (cmd->op) {
	case O_PRINTCALL:
	case O_PRINTRTN:
	case O_PROCRTN:
	    fprintf(f, "%s", symname(cmd->value.sym));
	    break;

	case O_PRINTSRCPOS:
	    p = cmd->value.arg[0];
	    if (p != nil and p->op != O_QLINE) {
		printf("trace ");
		prtree(f, p);
	    }
	    break;

	case O_CHFILE:
	case O_EDIT:
	case O_SOURCE:
	    fprintf(f, "%s", cmd->value.scon);
	    break;

I 9
	case O_CATCH:
	case O_IGNORE:
E 9
D 6
	case O_DELETE:
E 6
D 8
	case O_CATCH:
	case O_IGNORE:
E 8
	case O_TRACEOFF:
	    fprintf(f, "%d", cmd->value.lcon);
	    break;

	case O_ADDEVENT:
	case O_ONCE:
	case O_IF:
	    fprintf(f, " ");
	    prtree(f, cmd->value.event.cond);
	    fprintf(f, " { ");
	    foreach (Command, c, cmd->value.event.actions)
		printcmd(f, c);
		if (not list_islast()) {
		    fprintf(f, ";");
		}
	    endfor
D 11
	    fprintf(f, " }", opinfo[ord(cmd->op)].opstring);
E 11
I 11
	    fprintf(f, "%s }", opinfo[ord(cmd->op)].opstring);
E 11
	    break;

	case O_TRACEON:
	    print_tracestop(f, cmd);
	    break;

	case O_EXAMINE:
	    prtree(f, cmd->value.examine.beginaddr);
	    if (cmd->value.examine.endaddr != nil) {
		fprintf(f, ",");
		prtree(f, cmd->value.examine.endaddr);
	    }
	    fprintf(f, "/");
	    if (cmd->value.examine.count > 1) {
		fprintf(f, "%d", cmd->value.examine.count);
	    }
	    fprintf("%s", cmd->value.examine.mode);
	    break;

	default:
	    if (nargs(cmd->op) != 0) {
		i = 0;
		for (;;) {
		    prtree(f, cmd->value.arg[i]);
		    ++i;
		if (i >= nargs(cmd->op)) break;
		    fprintf(f, " ");
		}
	    }
	    break;
    }
}

/*
 * Print out a trace/stop command name.
 */

I 5
#define fprintI(f, b) { if (b) fprintf(f, "i"); }

E 5
private print_tracestop(f, cmd)
File f;
Command cmd;
{
    register Command c, ifcmd, stopcmd;
    Boolean done;

    done = false;
    ifcmd = list_element(Command, list_head(cmd->value.trace.actions));
    checkref(ifcmd);
    if (ifcmd->op == O_IF) {
	stopcmd = list_element(Command, list_head(ifcmd->value.event.actions));
	checkref(stopcmd);
	if (stopcmd->op == O_STOPX) {
D 5
	    fprintf(f, "%s if ", cmd->value.trace.inst ? "stopi" : "stop");
E 5
I 5
	    fprintf(f, "stop");
	    fprintI(f, cmd->value.trace.inst);
	    fprintf(f, " if ");
E 5
	    prtree(f, ifcmd->value.event.cond);
	    done = true;
	}
I 5
    } else if (ifcmd->op == O_STOPIFCHANGED) {
	fprintf(f, "stop");
	fprintI(f, cmd->value.trace.inst);
	fprintf(f, " ");
	prtree(f, ifcmd->value.arg[0]);
	done = true;
E 5
    }
    if (not done) {
	fprintf(f, "%s ", cmd->value.trace.inst ? "tracei" : "trace");
	foreach (Command, c, cmd->value.trace.actions)
	    printcmd(f, c);
	    if (not list_islast()) {
		fprintf(f, ";");
	    }
	endfor
    }
}

/*
D 5
 * Print a tree back out in Pascal form.
E 5
I 5
 * Print out a tree.
E 5
 */

public prtree(f, p)
File f;
register Node p;
{
    register Node q;
    Operator op;

    if (p != nil) {
	op = p->op;
	if (ord(op) > ord(O_LASTOP)) {
	    panic("bad op %d in prtree", p->op);
	}
	switch (op) {
	    case O_NAME:
		fprintf(f, "%s", ident(p->value.name));
		break;

	    case O_SYM:
		printname(f, p->value.sym);
		break;

	    case O_QLINE:
		if (nlhdr.nfiles > 1) {
		    prtree(f, p->value.arg[0]);
		    fprintf(f, ":");
		}
		prtree(f, p->value.arg[1]);
		break;

	    case O_LCON:
D 9
		if (compatible(p->nodetype, t_char)) {
		    fprintf(f, "'%c'", p->value.lcon);
		} else {
		    fprintf(f, "%d", p->value.lcon);
		}
E 9
I 9
		fprintf(f, "%d", p->value.lcon);
E 9
		break;

I 9
	    case O_CCON:
		fprintf(f, "'%c'", p->value.lcon);
		break;

E 9
	    case O_FCON:
		fprintf(f, "%g", p->value.fcon);
		break;

	    case O_SCON:
		fprintf(f, "\"%s\"", p->value.scon);
		break;

	    case O_INDEX:
		prtree(f, p->value.arg[0]);
		fprintf(f, "[");
		prtree(f, p->value.arg[1]);
		fprintf(f, "]");
		break;

	    case O_COMMA:
		prtree(f, p->value.arg[0]);
		if (p->value.arg[1] != nil) {
		    fprintf(f, ", ");
		    prtree(f, p->value.arg[1]);
		}
		break;

	    case O_RVAL:
D 9
		if (p->value.arg[0]->op == O_SYM) {
		    printname(f, p->value.arg[0]->value.sym);
		} else {
		    prtree(f, p->value.arg[0]);
		}
		break;

E 9
	    case O_ITOF:
		prtree(f, p->value.arg[0]);
		break;

	    case O_CALL:
		prtree(f, p->value.arg[0]);
		if (p->value.arg[1]!= nil) {
		    fprintf(f, "(");
		    prtree(f, p->value.arg[1]);
		    fprintf(f, ")");
		}
		break;

	    case O_INDIR:
D 9
		q = p->value.arg[0];
		if (isvarparam(q->nodetype)) {
		    prtree(f, q);
		} else {
		    if (q->op == O_SYM or q->op == O_LCON or q->op == O_DOT) {
			prtree(f, q);
			fprintf(f, "^");
		    } else {
			fprintf(f, "*(");
			prtree(f, q);
			fprintf(f, ")");
		    }
		}
E 9
I 9
		prtree(f, p->value.arg[0]);
		fprintf(f, "^");
E 9
		break;

	    case O_DOT:
D 9
		q = p->value.arg[0];
		if (q->op == O_INDIR) {
		    prtree(f, q->value.arg[0]);
		} else {
		    prtree(f, q);
		}
E 9
I 9
		prtree(f, p->value.arg[0]);
E 9
		fprintf(f, ".%s", symname(p->value.arg[1]->value.sym));
		break;

I 9
	    case O_TYPERENAME:
		prtree(f, p->value.arg[1]);
		fprintf(f, "(");
		prtree(f, p->value.arg[0]);
		fprintf(f, ")");
		break;

E 9
	    default:
		switch (degree(op)) {
		    case BINARY:
			prtree(f, p->value.arg[0]);
			fprintf(f, "%s", opinfo[ord(op)].opstring);
			prtree(f, p->value.arg[1]);
			break;

		    case UNARY:
			fprintf(f, "%s", opinfo[ord(op)].opstring);
			prtree(f, p->value.arg[0]);
			break;

		    default:
D 9
			error("internal error: bad op %d in prtree", op);
E 9
I 9
			if (opinfo[ord(op)].opstring == nil) {
			    fprintf(f, "[op %d]", ord(op));
			} else {
			    fprintf(f, "%s", opinfo[ord(op)].opstring);
			}
			break;
E 9
		}
		break;
	}
    }
}

/*
 * Free storage associated with a tree.
 */

public tfree(p)
Node p;
{
    Integer i;

    if (p == nil) {
	return;
    }
    switch (p->op) {
	case O_QLINE:
	    dispose(p->value.arg[0]->value.scon);
	    dispose(p->value.arg[0]);
	    tfree(p->value.arg[1]);
	    break;

	case O_SCON:
	    unmkstring(p->nodetype);
	    dispose(p->nodetype);
	    dispose(p->value.scon);
	    break;

	default:
	    for (i = 0; i < nargs(p->op); i++) {
		tfree(p->value.arg[i]);
	    }
	    break;
    }
    dispose(p);
D 9
}

/*
D 6
 * A recursive tree search routine to test if two trees * are equivalent.
E 6
I 6
 * A recursive tree search routine to test if two trees are equivalent.
E 6
 */

public Boolean tr_equal(t1, t2)
register Node t1;
register Node t2;
{
    register Boolean b;

    if (t1 == nil and t2 == nil) {
	b = true;
    } else if (t1 == nil or t2 == nil) {
	b = false;
    } else if (t1->op != t2->op or degree(t1->op) != degree(t2->op)) {
	b = false;
    } else {
	switch (degree(t1->op)) {
	    case LEAF:
		switch (t1->op) {
		    case O_NAME:
			b = (Boolean) (t1->value.name == t2->value.name);
			break;

		    case O_SYM:
			b = (Boolean) (t1->value.sym == t2->value.sym);
			break;

		    case O_LCON:
			b = (Boolean) (t1->value.lcon == t2->value.lcon);
			break;

		    case O_FCON:
			b = (Boolean) (t1->value.fcon == t2->value.fcon);
			break;

		    case O_SCON:
			b = (Boolean) (t1->value.scon == t2->value.scon);
			break;

		    default:
			panic("tr_equal: leaf %d\n", t1->op);
		}
		/*NOTREACHED*/

	    case BINARY:
		if (not tr_equal(t1->value.arg[0], t2->value.arg[0])) {
		    b = false;
		} else {
		    b = tr_equal(t1->value.arg[1], t2->value.arg[1]);
		}
		break;

	    case UNARY:
		b = tr_equal(t1->value.arg[0], t2->value.arg[0]);
		break;

	    default:
		panic("tr_equal: bad degree for op %d\n", t1->op);
	}
    }
    return b;
E 9
}
E 1
