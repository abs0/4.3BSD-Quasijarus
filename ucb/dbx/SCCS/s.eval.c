h26394
s 00031/00035/01351
d D 5.5 88/01/12 00:29:14 donn 21 20
c merge in latest Linton version
e
s 00001/00008/01385
d D 5.4 86/02/23 16:16:52 sam 20 18
c turn typerename operation into a call so it can be machine-dependent
e
s 00001/00008/01385
d R 5.4 86/02/22 23:07:53 sam 19 18
c O_TYPERENAME depends on byte ordering, make it machine dependent
e
s 00001/00001/01392
d D 5.3 85/06/21 17:50:58 mckusick 18 17
c cleanup after jim...
e
s 00011/00001/01382
d D 5.2 85/06/18 18:33:57 bloom 17 16
c change gripes for no maintainer
e
s 00008/00002/01375
d D 5.1 85/05/31 09:57:33 dist 16 15
c Add copyright
e
s 00272/00176/01105
d D 1.15 85/03/01 20:21:17 linton 15 14
c update to version 3.0
e
s 00042/00002/01239
d D 1.14 84/08/12 15:12:52 sam 14 13
c handle signal lists (with names) for ignore and catch
e
s 00001/00001/01240
d D 1.13 84/08/12 13:21:54 sam 13 12
c add real aliases; rewrite lexical scanner
e
s 00001/00003/01240
d D 1.12 84/06/23 11:40:11 sam 12 11
i
c merge linton branch delta trail
e
s 00102/00039/01141
d D 1.11 84/06/23 10:45:37 sam 11 10
c branch delta of linton changes from net.sources
e
s 00002/00000/01178
d D 1.10 83/08/17 05:27:50 linton 10 9
c added a flag for forcing the current location to be displayed 
c as an instruction, fixes problem with "stepi" on a program with source 
c line information
e
s 00025/00052/01153
d D 1.9 83/08/10 06:15:10 linton 9 8
c took out edit() and put it in "source.c" so that it can use 
c the sourcepath, modified "gripe" a little to handle interrupts better, 
c and did a little cleaning
e
s 00028/00020/01177
d D 1.8 83/07/08 00:43:12 linton 8 7
c fixed problem with the "cond" function popping a "Boolean" 
c instead of a "Boolrep"
e
s 00024/00003/01173
d D 1.7 83/05/18 19:30:15 csvaf 7 6
c changes to which whereis and STACKSIZE for fortran support
c  evaluation of DEBUG command
e
s 00042/00016/01134
d D 1.6 83/04/08 01:27:23 linton 6 5
c fixed a problem with the "func" command, changed it so that 
c only the most recent event is reported after a trace/stop instead of an 
c entire status, changed the usage of the "cont" to reflect the added ability 
c to pass a signal on to the debuggee
e
s 00014/00005/01136
d D 1.5 83/03/30 02:26:08 linton 5 4
c fixed "trace <line number>"
e
s 00013/00001/01128
d D 1.4 83/02/20 17:56:07 linton 4 3
c added type-rename operator and option to examine operator
e
s 00004/00001/01125
d D 1.3 82/12/20 22:36:04 linton 3 2
c fixed tracing functions
e
s 00001/00001/01125
d D 1.2 82/12/15 04:19:52 linton 2 1
c fixed @(#) stuff
e
s 01126/00000/00000
d D 1.1 82/12/15 04:07:22 linton 1 0
c date and time created 82/12/15 04:07:22 by linton
e
u
U
f b 
t
T
I 1
D 16
/* Copyright (c) 1982 Regents of the University of California */
E 16
I 16
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 16

D 2
static char sccsid[] = "@(#)%Z%%M% %I% %G%";
E 2
I 2
D 11
static char sccsid[] = "%Z%%M% %I% %G%";
E 11
I 11
D 12
static char sccsid[] = "@(#)eval.c 1.10 8/17/83";
E 11
E 2

I 11
static char rcsid[] = "$Header: eval.c,v 1.3 84/03/27 10:20:23 linton Exp $";
E 12
I 12
D 16
static	char sccsid[] = "%W% (Berkeley) %G%";
E 16
I 16
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 16
E 12

I 15
D 21
static char rcsid[] = "$Header: eval.c,v 1.5 84/12/26 10:39:08 linton Exp $";
E 21
I 21
static char rcsid[] = "$Header: eval.c,v 1.2 87/03/25 19:48:33 donn Exp $";
E 21

E 15
E 11
/*
 * Tree evaluation.
 */

#include "defs.h"
#include "tree.h"
#include "operators.h"
I 15
#include "debug.h"
E 15
#include "eval.h"
#include "events.h"
#include "symbols.h"
#include "scanner.h"
#include "source.h"
#include "object.h"
#include "mappings.h"
#include "process.h"
I 11
#include "runtime.h"
E 11
#include "machine.h"
#include <signal.h>

#ifndef public

#include "machine.h"

D 7
#define STACKSIZE 2000
E 7
I 7
#define STACKSIZE 20000
E 7

typedef Char Stack;

#define push(type, value) { \
    ((type *) (sp += sizeof(type)))[-1] = (value); \
}

#define pop(type) ( \
    (*((type *) (sp -= sizeof(type)))) \
)

I 11
#define popn(n, dest) { \
    sp -= n; \
    bcopy(sp, dest, n); \
}

E 11
#define alignstack() { \
    sp = (Stack *) (( ((int) sp) + sizeof(int) - 1)&~(sizeof(int) - 1)); \
}

#endif

public Stack stack[STACKSIZE];
public Stack *sp = &stack[0];
I 10
public Boolean useInstLoc = false;
E 10

#define chksp() \
{ \
    if (sp < &stack[0]) { \
	panic("stack underflow"); \
    } \
}

#define poparg(n, r, fr) { \
    eval(p->value.arg[n]); \
    if (isreal(p->op)) { \
D 11
	fr = pop(double); \
E 11
I 11
	if (size(p->value.arg[n]->nodetype) == sizeof(float)) { \
	    fr = pop(float); \
	} else { \
	    fr = pop(double); \
	} \
E 11
    } else if (isint(p->op)) { \
	r = popsmall(p->value.arg[n]->nodetype); \
    } \
}

#define Boolrep char	/* underlying representation type for booleans */

/*
I 15
 * Command-level evaluation.
 */

public Node topnode;

public topeval (p)
Node p;
{
    if (traceeval) {
	fprintf(stderr, "topeval(");
	prtree(stderr, p);
	fprintf(stderr, ")\n");
	fflush(stderr);
    }
    topnode = p;
    eval(p);
}

/*
E 15
 * Evaluate a parse tree leaving the value on the top of the stack.
 */

public eval(p)
register Node p;
{
    long r0, r1;
    double fr0, fr1;
    Address addr;
    long i, n;
    int len;
D 15
    Symbol s, f;
E 15
I 15
    Symbol s;
E 15
    Node n1, n2;
D 15
    Boolean b;
E 15
I 15
    boolean b;
E 15
    File file;
I 15
    String str;
E 15

    checkref(p);
I 7
D 8
    if(debug_flag[2]) {
                     fprintf(stderr," evaluating %s \n",showoperator(p->op));
E 8
I 8
D 15
    if (debug_flag[2]) {
	fprintf(stderr," evaluating %s \n",showoperator(p->op));
E 15
I 15
    if (traceeval) {
	fprintf(stderr, "begin eval %s\n", opname(p->op));
E 15
E 8
    }
E 7
    switch (degree(p->op)) {
	case BINARY:
	    poparg(1, r1, fr1);
	    poparg(0, r0, fr0);
	    break;

	case UNARY:
	    poparg(0, r0, fr0);
	    break;

	default:
	    /* do nothing */;
    }
    switch (p->op) {
	case O_SYM:
	    s = p->value.sym;
	    if (s == retaddrsym) {
		push(long, return_addr());
D 15
	    } else {
		if (isvariable(s)) {
		    if (s != program and not isactive(container(s))) {
			error("\"%s\" is not active", symname(s));
		    }
		    push(long, address(s, nil));
		} else if (isblock(s)) {
		    push(Symbol, s);
E 15
I 15
	    } else if (isvariable(s)) {
		if (s != program and not isactive(container(s))) {
		    error("\"%s\" is not active", symname(s));
		}
		if (isvarparam(s) and not isopenarray(s)) {
		    rpush(address(s, nil), sizeof(Address));
E 15
		} else {
D 15
		    error("can't evaluate a %s", classname(s));
E 15
I 15
		    push(Address, address(s, nil));
E 15
		}
I 15
	    } else if (isblock(s)) {
		push(Symbol, s);
	    } else if (isconst(s)) {
		eval(constval(s));
	    } else {
		error("can't evaluate a %s", classname(s));
E 15
	    }
	    break;

	case O_LCON:
I 15
	case O_CCON:
E 15
	    r0 = p->value.lcon;
	    pushsmall(p->nodetype, r0);
	    break;

	case O_FCON:
	    push(double, p->value.fcon);
	    break;

	case O_SCON:
	    len = size(p->nodetype);
	    mov(p->value.scon, sp, len);
	    sp += len;
	    break;

	case O_INDEX:
D 15
	    n = pop(long);
	    i = evalindex(p->value.arg[0]->nodetype,
		popsmall(p->value.arg[1]->nodetype));
	    push(long, n + i*size(p->nodetype));
E 15
I 15
	    s = p->value.arg[0]->nodetype;
	    p->value.arg[0]->nodetype = t_addr;
	    eval(p->value.arg[0]);
	    p->value.arg[0]->nodetype = s;
	    n = pop(Address);
	    eval(p->value.arg[1]);
	    evalindex(s, n, popsmall(p->value.arg[1]->nodetype));
E 15
	    break;

	case O_DOT:
	    s = p->value.arg[1]->value.sym;
D 15
	    n = lval(p->value.arg[0]);
E 15
I 15
	    eval(p->value.arg[0]);
	    n = pop(long);
E 15
	    push(long, n + (s->symvalue.field.offset div 8));
	    break;

	/*
	 * Get the value of the expression addressed by the top of the stack.
	 * Push the result back on the stack.
	 */

	case O_INDIR:
	case O_RVAL:
	    addr = pop(long);
	    if (addr == 0) {
		error("reference through nil pointer");
	    }
D 15
	    if (p->op == O_INDIR) {
		len = sizeof(long);
	    } else {
		len = size(p->nodetype);
	    }
E 15
I 15
	    len = size(p->nodetype);
E 15
	    rpush(addr, len);
I 7
D 11
	addr = pop(long);
        push(long, addr);
E 11
E 7
	    break;

I 4
D 21
	/*
D 15
	 * Effectively, we want to pop n bytes off for the evaluated subtree
	 * and push len bytes on for the new type of the same tree.
	 */
E 15
I 15
	 * Move the stack pointer so that the top of the stack has
	 * something corresponding to the size of the current node type.
	 * If this new type is bigger than the subtree (len > 0),
	 * then the stack is padded with nulls.  If it's smaller,
	 * the stack is just dropped by the appropriate amount.
	 */
E 21
E 15
	case O_TYPERENAME:
D 15
	    n = size(p->value.arg[0]->nodetype);
	    len = size(p->nodetype);
	    sp = sp - n + len;
E 15
I 15
D 20
	    len = size(p->nodetype) - size(p->value.arg[0]->nodetype);
	    if (len > 0) {
		for (n = 0; n < len; n++) {
		    *sp++ = '\0';
		}
	    } else if (len < 0) {
		sp += len;
	    }
E 20
I 20
D 21
	    typerename(size(p->value.arg[0]->nodetype), size(p->nodetype));
E 21
I 21
	    loophole(size(p->value.arg[0]->nodetype), size(p->nodetype));
E 21
E 20
E 15
	    break;

E 4
	case O_COMMA:
I 15
	    eval(p->value.arg[0]);
	    if (p->value.arg[1] != nil) {
		eval(p->value.arg[1]);
	    }
E 15
	    break;

	case O_ITOF:
	    push(double, (double) r0);
	    break;

	case O_ADD:
	    push(long, r0+r1);
	    break;

	case O_ADDF:
	    push(double, fr0+fr1);
	    break;

	case O_SUB:
	    push(long, r0-r1);
	    break;

	case O_SUBF:
	    push(double, fr0-fr1);
	    break;

	case O_NEG:
	    push(long, -r0);
	    break;

	case O_NEGF:
	    push(double, -fr0);
	    break;

	case O_MUL:
	    push(long, r0*r1);
	    break;

	case O_MULF:
	    push(double, fr0*fr1);
	    break;

	case O_DIVF:
	    if (fr1 == 0) {
		error("error: division by 0");
	    }
	    push(double, fr0 / fr1);
	    break;

	case O_DIV:
	    if (r1 == 0) {
		error("error: div by 0");
	    }
	    push(long, r0 div r1);
	    break;

	case O_MOD:
	    if (r1 == 0) {
		error("error: mod by 0");
	    }
	    push(long, r0 mod r1);
	    break;

	case O_LT:
	    push(Boolrep, r0 < r1);
	    break;

	case O_LTF:
	    push(Boolrep, fr0 < fr1);
	    break;

	case O_LE:
	    push(Boolrep, r0 <= r1);
	    break;

	case O_LEF:
	    push(Boolrep, fr0 <= fr1);
	    break;

	case O_GT:
	    push(Boolrep, r0 > r1);
	    break;

	case O_GTF:
	    push(Boolrep, fr0 > fr1);
	    break;

	case O_EQ:
	    push(Boolrep, r0 == r1);
	    break;

	case O_EQF:
	    push(Boolrep, fr0 == fr1);
	    break;

	case O_NE:
	    push(Boolrep, r0 != r1);
	    break;

	case O_NEF:
	    push(Boolrep, fr0 != fr1);
	    break;

	case O_AND:
	    push(Boolrep, r0 and r1);
	    break;

	case O_OR:
	    push(Boolrep, r0 or r1);
	    break;

	case O_ASSIGN:
	    assign(p->value.arg[0], p->value.arg[1]);
	    break;

	case O_CHFILE:
	    if (p->value.scon == nil) {
		printf("%s\n", cursource);
	    } else {
		file = opensource(p->value.scon);
		if (file == nil) {
		    error("can't read \"%s\"", p->value.scon);
		} else {
		    fclose(file);
		    setsource(p->value.scon);
		}
	    }
	    break;

	case O_CONT:
D 6
	    cont();
E 6
I 6
	    cont(p->value.lcon);
E 6
	    printnews();
	    break;

	case O_LIST:
D 15
	    if (p->value.arg[0]->op == O_SYM) {
		f = p->value.arg[0]->value.sym;
		addr = firstline(f);
		if (addr == NOADDR) {
		    error("no source lines for \"%s\"", symname(f));
		}
		setsource(srcfilename(addr));
		r0 = srcline(addr) - 5;
		r1 = r0 + 10;
		if (r0 < 1) {
		    r0 = 1;
		}
	    } else {
		eval(p->value.arg[0]);
		r0 = pop(long);
		eval(p->value.arg[1]);
		r1 = pop(long);
	    }
	    printlines((Lineno) r0, (Lineno) r1);
E 15
I 15
	    list(p);
E 15
	    break;

	case O_FUNC:
D 15
	    if (p->value.arg[0] == nil) {
		printname(stdout, curfunc);
		putchar('\n');
	    } else {
D 6
		curfunc = p->value.arg[0]->value.sym;
I 5
		if (isblock(curfunc) and not ismodule(curfunc)) {
		    error("%s is not a procedure or function",
			symname(curfunc));
E 6
I 6
		s = p->value.arg[0]->value.sym;
D 11
		find(f, s->name) where
		    f->class == FUNC or f->class == PROC
		endfind(f);
		if (f == nil) {
		    error("%s is not a procedure or function", symname(s));
E 11
I 11
		if (isroutine(s)) {
		    setcurfunc(s);
		} else {
		    find(f, s->name) where isroutine(f) endfind(f);
		    if (f == nil) {
			error("%s is not a procedure or function", symname(s));
		    }
		    setcurfunc(f);
E 11
E 6
		}
I 6
D 11
		curfunc = f;
E 11
E 6
E 5
		addr = codeloc(curfunc);
		if (addr != NOADDR) {
		    setsource(srcfilename(addr));
		    cursrcline = srcline(addr) - 5;
		    if (cursrcline < 1) {
			cursrcline = 1;
		    }
		}
	    }
E 15
I 15
	    func(p->value.arg[0]);
E 15
	    break;

	case O_EXAMINE:
	    eval(p->value.examine.beginaddr);
	    r0 = pop(long);
	    if (p->value.examine.endaddr == nil) {
		n = p->value.examine.count;
D 4
		if (streq(p->value.examine.mode, "i")) {
E 4
I 4
		if (n == 0) {
		    printvalue(r0, p->value.examine.mode);
		} else if (streq(p->value.examine.mode, "i")) {
E 4
		    printninst(n, (Address) r0);
		} else {
		    printndata(n, (Address) r0, p->value.examine.mode);
		}
	    } else {
		eval(p->value.examine.endaddr);
		r1 = pop(long);
		if (streq(p->value.examine.mode, "i")) {
		    printinst((Address)r0, (Address)r1);
		} else {
		    printdata((Address)r0, (Address)r1, p->value.examine.mode);
		}
	    }
	    break;

	case O_PRINT:
	    for (n1 = p->value.arg[0]; n1 != nil; n1 = n1->value.arg[1]) {
		eval(n1->value.arg[0]);
		printval(n1->value.arg[0]->nodetype);
		putchar(' ');
	    }
	    putchar('\n');
	    break;

	case O_PSYM:
	    if (p->value.arg[0]->op == O_SYM) {
		psym(p->value.arg[0]->value.sym);
	    } else {
		psym(p->value.arg[0]->nodetype);
	    }
	    break;

	case O_QLINE:
	    eval(p->value.arg[1]);
	    break;

	case O_STEP:
	    b = inst_tracing;
	    inst_tracing = (Boolean) (not p->value.step.source);
	    if (p->value.step.skipcalls) {
		next();
	    } else {
		stepc();
	    }
	    inst_tracing = b;
I 10
	    useInstLoc = (Boolean) (not p->value.step.source);
E 10
	    printnews();
	    break;

	case O_WHATIS:
	    if (p->value.arg[0]->op == O_SYM) {
		printdecl(p->value.arg[0]->value.sym);
	    } else {
		printdecl(p->value.arg[0]->nodetype);
	    }
	    break;

	case O_WHERE:
	    wherecmd();
	    break;

	case O_WHEREIS:
D 7
	    printwhereis(stdout, p->value.arg[0]->value.sym);
E 7
I 7
	    if (p->value.arg[0]->op == O_SYM) {
D 15
		printwhereis(stdout,p->value.arg[0]->value.sym);
E 15
I 15
		printwhereis(stdout, p->value.arg[0]->value.sym);
E 15
	    } else {
D 15
		printwhereis(stdout,p->value.arg[0]->nodetype);
E 15
I 15
		printwhereis(stdout, p->value.arg[0]->nodetype);
E 15
	    }
E 7
	    break;

	case O_WHICH:
D 7
	    printwhich(stdout, p->value.arg[0]->value.sym);
E 7
I 7
	    if (p->value.arg[0]->op == O_SYM) {
D 15
		printwhich(stdout,p->value.arg[0]->value.sym);
E 15
I 15
		printwhich(stdout, p->value.arg[0]->value.sym);
E 15
	    } else {
D 15
		printwhich(stdout,p->value.arg[0]->nodetype);
E 15
I 15
		printwhich(stdout, p->value.arg[0]->nodetype);
E 15
	    }
E 7
	    putchar('\n');
	    break;

	case O_ALIAS:
	    n1 = p->value.arg[0];
	    n2 = p->value.arg[1];
D 15
	    if (n1 == nil) {
		print_alias(nil);
	    } else if (n2 == nil) {
		print_alias(n1->value.name);
E 15
I 15
	    if (n2 == nil) {
		if (n1 == nil) {
		    alias(nil, nil, nil);
		} else {
		    alias(n1->value.name, nil, nil);
		}
	    } else if (n2->op == O_NAME) {
		str = ident(n2->value.name);
		alias(n1->value.name, nil, strdup(str));
E 15
	    } else {
D 13
		enter_alias(n1->value.name, n2->value.name);
E 13
I 13
D 15
		enter_alias(n1->value.name, n2);
E 15
I 15
		if (n1->op == O_COMMA) {
		    alias(
			n1->value.arg[0]->value.name,
			(List) n1->value.arg[1],
			n2->value.scon
		    );
		} else {
		    alias(n1->value.name, nil, n2->value.scon);
		}
E 15
E 13
	    }
	    break;

I 15
	case O_UNALIAS:
	    unalias(p->value.arg[0]->value.name);
	    break;

	case O_CALLPROC:
	    callproc(p, false);
	    break;

E 15
	case O_CALL:
D 15
	    callproc(p->value.arg[0], p->value.arg[1]);
E 15
I 15
	    callproc(p, true);
E 15
	    break;

	case O_CATCH:
D 14
	    psigtrace(process, p->value.lcon, true);
E 14
I 14
D 15
	    catchsigs(p->value.arg[0]);
E 15
I 15
	    if (p->value.lcon == 0) {
		printsigscaught(process);
	    } else {
		psigtrace(process, p->value.lcon, true);
	    }
E 15
E 14
	    break;

	case O_EDIT:
	    edit(p->value.scon);
	    break;

I 7
        case O_DEBUG:
            debug(p);
	    break;

I 11
	case O_DOWN:
	    checkref(p->value.arg[0]);
	    assert(p->value.arg[0]->op == O_LCON);
	    down(p->value.arg[0]->value.lcon);
	    break;

E 11
E 7
	case O_DUMP:
D 15
	    dump();
E 15
I 15
	    if (p->value.arg[0] == nil) {
		dumpall();
	    } else {
		s = p->value.arg[0]->value.sym;
		if (s == curfunc) {
		    dump(nil);
		} else {
		    dump(s);
		}
	    }
E 15
	    break;

	case O_GRIPE:
	    gripe();
	    break;

	case O_HELP:
	    help();
	    break;

	case O_IGNORE:
D 14
	    psigtrace(process, p->value.lcon, false);
E 14
I 14
D 15
	    ignoresigs(p->value.arg[0]);
E 15
I 15
	    if (p->value.lcon == 0) {
		printsigsignored(process);
	    } else {
		psigtrace(process, p->value.lcon, false);
	    }
E 15
E 14
	    break;

I 11
	case O_RETURN:
	    if (p->value.arg[0] == nil) {
		rtnfunc(nil);
	    } else {
		assert(p->value.arg[0]->op == O_SYM);
		rtnfunc(p->value.arg[0]->value.sym);
	    }
	    break;

E 11
	case O_RUN:
	    run();
	    break;

I 15
	case O_SET:
	    set(p->value.arg[0], p->value.arg[1]);
	    break;

	case O_SEARCH:
	    search(p->value.arg[0]->value.lcon, p->value.arg[1]->value.scon);
	    break;

E 15
	case O_SOURCE:
	    setinput(p->value.scon);
	    break;

	case O_STATUS:
	    status();
	    break;

	case O_TRACE:
	case O_TRACEI:
	    trace(p);
D 6
	    if (isstdin()) {
		status();
	    }
E 6
	    break;

	case O_STOP:
	case O_STOPI:
	    stop(p);
D 6
	    if (isstdin()) {
		status();
	    }
E 6
	    break;

I 15
	case O_UNSET:
	    undefvar(p->value.arg[0]->value.name);
	    break;

E 15
I 11
	case O_UP:
	    checkref(p->value.arg[0]);
	    assert(p->value.arg[0]->op == O_LCON);
	    up(p->value.arg[0]->value.lcon);
	    break;

E 11
	case O_ADDEVENT:
	    addevent(p->value.event.cond, p->value.event.actions);
	    break;

	case O_DELETE:
D 11
	    delevent((unsigned int) p->value.lcon);
E 11
I 11
	    n1 = p->value.arg[0];
	    while (n1->op == O_COMMA) {
		n2 = n1->value.arg[0];
		assert(n2->op == O_LCON);
		if (not delevent((unsigned int) n2->value.lcon)) {
		    error("unknown event %ld", n2->value.lcon);
		}
		n1 = n1->value.arg[1];
	    }
	    assert(n1->op == O_LCON);
	    if (not delevent((unsigned int) n1->value.lcon)) {
		error("unknown event %ld", n1->value.lcon);
	    }
E 11
	    break;

	case O_ENDX:
	    endprogram();
	    break;

	case O_IF:
	    if (cond(p->value.event.cond)) {
		evalcmdlist(p->value.event.actions);
	    }
	    break;

	case O_ONCE:
	    event_once(p->value.event.cond, p->value.event.actions);
	    break;

	case O_PRINTCALL:
	    printcall(p->value.sym, whatblock(return_addr()));
	    break;

	case O_PRINTIFCHANGED:
	    printifchanged(p->value.arg[0]);
	    break;

	case O_PRINTRTN:
	    printrtn(p->value.sym);
	    break;

	case O_PRINTSRCPOS:
	    getsrcpos();
	    if (p->value.arg[0] == nil) {
		printsrcpos();
		putchar('\n');
		printlines(curline, curline);
	    } else if (p->value.arg[0]->op == O_QLINE) {
		if (p->value.arg[0]->value.arg[1]->value.lcon == 0) {
		    printf("tracei: ");
		    printinst(pc, pc);
		} else {
D 15
		    printf("trace:  ");
		    printlines(curline, curline);
E 15
I 15
		    if (canReadSource()) {
			printf("trace:  ");
			printlines(curline, curline);
		    }
E 15
		}
	    } else {
		printsrcpos();
		printf(": ");
		eval(p->value.arg[0]);
		prtree(stdout, p->value.arg[0]);
		printf(" = ");
		printval(p->value.arg[0]->nodetype);
		putchar('\n');
	    }
	    break;

	case O_PROCRTN:
	    procreturn(p->value.sym);
	    break;

	case O_STOPIFCHANGED:
	    stopifchanged(p->value.arg[0]);
	    break;

	case O_STOPX:
	    isstopped = true;
	    break;

	case O_TRACEON:
	    traceon(p->value.trace.inst, p->value.trace.event,
		p->value.trace.actions);
	    break;

	case O_TRACEOFF:
	    traceoff(p->value.lcon);
	    break;

	default:
	    panic("eval: bad op %d", p->op);
    }
I 7
D 15
 if(debug_flag[2]) { 
	fprintf(stderr," evaluated %s \n",showoperator(p->op));
 }
           
E 15
I 15
    if (traceeval) { 
	fprintf(stderr, "end eval %s\n", opname(p->op));
    }
E 15
E 7
}

/*
 * Evaluate a list of commands.
 */

public evalcmdlist(cl)
Cmdlist cl;
{
    Command c;

    foreach (Command, c, cl)
	evalcmd(c);
    endfor
}

/*
 * Push "len" bytes onto the expression stack from address "addr"
 * in the process.  If there isn't room on the stack, print an error message.
 */

public rpush(addr, len)
Address addr;
int len;
{
    if (not canpush(len)) {
	error("expression too large to evaluate");
    } else {
	chksp();
	dread(sp, addr, len);
	sp += len;
    }
}

/*
 * Check if the stack has n bytes available.
 */

public Boolean canpush(n)
Integer n;
{
    return (Boolean) (sp + n < &stack[STACKSIZE]);
}

/*
 * Push a small scalar of the given type onto the stack.
 */

public pushsmall(t, v)
Symbol t;
long v;
{
    register Integer s;

    s = size(t);
    switch (s) {
	case sizeof(char):
	    push(char, v);
	    break;

	case sizeof(short):
	    push(short, v);
	    break;

	case sizeof(long):
	    push(long, v);
	    break;

	default:
	    panic("bad size %d in popsmall", s);
    }
}

/*
 * Pop an item of the given type which is assumed to be no larger
 * than a long and return it expanded into a long.
 */

public long popsmall(t)
Symbol t;
{
I 15
    register integer n;
E 15
    long r;

D 15
    switch (size(t)) {
	case sizeof(char):
E 15
I 15
    n = size(t);
    if (n == sizeof(char)) {
	if (t->class == RANGE and t->symvalue.rangev.lower >= 0) {
	    r = (long) pop(unsigned char);
	} else {
E 15
	    r = (long) pop(char);
D 15
	    break;

	case sizeof(short):
E 15
I 15
	}
    } else if (n == sizeof(short)) {
	if (t->class == RANGE and t->symvalue.rangev.lower >= 0) {
	    r = (long) pop(unsigned short);
	} else {
E 15
	    r = (long) pop(short);
D 15
	    break;

	case sizeof(long):
	    r = pop(long);
	    break;

	default:
	    panic("popsmall: size is %d", size(t));
E 15
I 15
	}
    } else if (n == sizeof(long)) {
	r = pop(long);
    } else {
	error("[internal error: size %d in popsmall]", n);
E 15
    }
    return r;
}

/*
 * Evaluate a conditional expression.
 */

public Boolean cond(p)
Node p;
{
D 21
    register Boolean b;
E 21
I 21
    Boolean b;
    int i;
E 21

    if (p == nil) {
	b = true;
    } else {
	eval(p);
D 8
	b = pop(Boolean);
E 8
I 8
D 21
	b = (Boolean) pop(Boolrep);
E 21
I 21
	i = pop(Boolrep);
	b = (Boolean) i;
E 21
E 8
    }
    return b;
}

/*
 * Return the address corresponding to a given tree.
 */

public Address lval(p)
Node p;
{
    if (p->op == O_RVAL) {
	eval(p->value.arg[0]);
    } else {
	eval(p);
    }
    return (Address) (pop(long));
}

/*
 * Process a trace command, translating into the appropriate events
 * and associated actions.
 */

public trace(p)
Node p;
{
    Node exp, place, cond;
    Node left;

    exp = p->value.arg[0];
    place = p->value.arg[1];
    cond = p->value.arg[2];
    if (exp == nil) {
	traceall(p->op, place, cond);
D 5
    } else if (exp->op == O_QLINE) {
E 5
I 5
    } else if (exp->op == O_QLINE or exp->op == O_LCON) {
E 5
	traceinst(p->op, exp, cond);
    } else if (place != nil and place->op == O_QLINE) {
	traceat(p->op, exp, place, cond);
    } else {
D 3
	left = (exp->op == O_RVAL) ? exp->value.arg[0] : exp;
E 3
I 3
	left = exp;
	if (left->op == O_RVAL or left->op == O_CALL) {
	    left = left->value.arg[0];
	}
E 3
	if (left->op == O_SYM and isblock(left->value.sym)) {
	    traceproc(p->op, left->value.sym, place, cond);
	} else {
	    tracedata(p->op, exp, place, cond);
	}
    }
}

/*
 * Set a breakpoint that will turn on tracing.
 */

private traceall(op, place, cond)
Operator op;
Node place;
Node cond;
{
    Symbol s;
    Node event;
    Command action;

    if (place == nil) {
	s = program;
    } else {
	s = place->value.sym;
    }
    event = build(O_EQ, build(O_SYM, procsym), build(O_SYM, s));
    action = build(O_PRINTSRCPOS,
	build(O_QLINE, nil, build(O_LCON, (op == O_TRACE) ? 1 : 0)));
    if (cond != nil) {
	action = build(O_IF, cond, buildcmdlist(action));
    }
    action = build(O_TRACEON, (op == O_TRACEI), buildcmdlist(action));
    action->value.trace.event = addevent(event, buildcmdlist(action));
I 6
    if (isstdin()) {
	printevent(action->value.trace.event);
    }
E 6
}

/*
 * Set up the appropriate breakpoint for tracing an instruction.
 */

private traceinst(op, exp, cond)
Operator op;
Node exp;
Node cond;
{
D 5
    Node event;
E 5
I 5
    Node event, wh;
E 5
    Command action;
I 6
    Event e;
E 6

I 5
    if (exp->op == O_LCON) {
D 15
	wh = build(O_QLINE, build(O_SCON, cursource), exp);
E 15
I 15
	wh = build(O_QLINE, build(O_SCON, strdup(cursource)), exp);
E 15
    } else {
	wh = exp;
    }
E 5
    if (op == O_TRACEI) {
D 5
	event = build(O_EQ, build(O_SYM, pcsym), exp);
E 5
I 5
	event = build(O_EQ, build(O_SYM, pcsym), wh);
E 5
    } else {
D 5
	event = build(O_EQ, build(O_SYM, linesym), exp);
E 5
I 5
	event = build(O_EQ, build(O_SYM, linesym), wh);
E 5
    }
D 5
    action = build(O_PRINTSRCPOS, exp);
E 5
I 5
    action = build(O_PRINTSRCPOS, wh);
E 5
    if (cond) {
	action = build(O_IF, cond, buildcmdlist(action));
    }
D 6
    addevent(event, buildcmdlist(action));
E 6
I 6
    e = addevent(event, buildcmdlist(action));
    if (isstdin()) {
	printevent(e);
    }
E 6
}

/*
 * Set a breakpoint to print an expression at a given line or address.
 */

private traceat(op, exp, place, cond)
Operator op;
Node exp;
Node place;
Node cond;
{
    Node event;
    Command action;
I 6
    Event e;
E 6

    if (op == O_TRACEI) {
	event = build(O_EQ, build(O_SYM, pcsym), place);
    } else {
	event = build(O_EQ, build(O_SYM, linesym), place);
    }
    action = build(O_PRINTSRCPOS, exp);
    if (cond != nil) {
	action = build(O_IF, cond, buildcmdlist(action));
    }
D 6
    addevent(event, buildcmdlist(action));
E 6
I 6
    e = addevent(event, buildcmdlist(action));
    if (isstdin()) {
	printevent(e);
    }
E 6
}

/*
 * Construct event for tracing a procedure.
 *
 * What we want here is
 *
 * 	when $proc = p do
 *	    if <condition> then
 *	        printcall;
 *	        once $pc = $retaddr do
 *	            printrtn;
 *	        end;
 *	    end if;
 *	end;
 *
 * Note that "once" is like "when" except that the event
 * deletes itself as part of its associated action.
 */

private traceproc(op, p, place, cond)
Operator op;
Symbol p;
Node place;
Node cond;
{
    Node event;
    Command action;
    Cmdlist actionlist;
I 6
    Event e;
E 6

    action = build(O_PRINTCALL, p);
    actionlist = list_alloc();
    cmdlist_append(action, actionlist);
    event = build(O_EQ, build(O_SYM, pcsym), build(O_SYM, retaddrsym));
    action = build(O_ONCE, event, buildcmdlist(build(O_PRINTRTN, p)));
    cmdlist_append(action, actionlist);
    if (cond != nil) {
	actionlist = buildcmdlist(build(O_IF, cond, actionlist));
    }
    event = build(O_EQ, build(O_SYM, procsym), build(O_SYM, p));
D 6
    addevent(event, actionlist);
E 6
I 6
    e = addevent(event, actionlist);
    if (isstdin()) {
	printevent(e);
    }
E 6
}

/*
 * Set up breakpoint for tracing data.
 */

private tracedata(op, exp, place, cond)
Operator op;
Node exp;
Node place;
Node cond;
{
    Symbol p;
    Node event;
    Command action;

I 21
    if (size(exp->nodetype) > MAXTRSIZE) {
	error("expression too large to trace (limit is %d bytes)", MAXTRSIZE);
    }
E 21
    p = (place == nil) ? tcontainer(exp) : place->value.sym;
    if (p == nil) {
	p = program;
    }
    action = build(O_PRINTIFCHANGED, exp);
    if (cond != nil) {
	action = build(O_IF, cond, buildcmdlist(action));
    }
    action = build(O_TRACEON, (op == O_TRACEI), buildcmdlist(action));
    event = build(O_EQ, build(O_SYM, procsym), build(O_SYM, p));
    action->value.trace.event = addevent(event, buildcmdlist(action));
I 6
    if (isstdin()) {
	printevent(action->value.trace.event);
    }
E 6
}

/*
 * Setting and unsetting of stops.
 */

public stop(p)
Node p;
{
D 8
    Node exp, place, cond;
E 8
I 8
    Node exp, place, cond, t;
E 8
    Symbol s;
    Command action;
I 6
    Event e;
E 6

    exp = p->value.arg[0];
    place = p->value.arg[1];
    cond = p->value.arg[2];
    if (exp != nil) {
	stopvar(p->op, exp, place, cond);
D 8
    } else if (cond != nil) {
	s = (place == nil) ? program : place->value.sym;
	action = build(O_IF, cond, buildcmdlist(build(O_STOPX)));
	action = build(O_TRACEON, (p->op == O_STOPI), buildcmdlist(action));
	cond = build(O_EQ, build(O_SYM, procsym), build(O_SYM, s));
	action->value.trace.event = addevent(cond, buildcmdlist(action));
    } else if (place->op == O_SYM) {
	s = place->value.sym;
	cond = build(O_EQ, build(O_SYM, procsym), build(O_SYM, s));
D 6
	addevent(cond, buildcmdlist(build(O_STOPX)));
E 6
I 6
	e = addevent(cond, buildcmdlist(build(O_STOPX)));
	if (isstdin()) {
	    printevent(e);
	}
E 8
E 6
    } else {
D 8
	stopinst(p->op, place, cond);
E 8
I 8
	action = build(O_STOPX);
	if (cond != nil) {
	    action = build(O_IF, cond, buildcmdlist(action));
	}
D 11
	if (place != nil and place->op == O_SYM) {
	    s = place->value.sym;
E 11
I 11
	if (place == nil or place->op == O_SYM) {
	    if (place == nil) {
		s = program;
	    } else {
		s = place->value.sym;
	    }
E 11
	    t = build(O_EQ, build(O_SYM, procsym), build(O_SYM, s));
	    if (cond != nil) {
		action = build(O_TRACEON, (p->op == O_STOPI),
		    buildcmdlist(action));
		e = addevent(t, buildcmdlist(action));
		action->value.trace.event = e;
	    } else {
		e = addevent(t, buildcmdlist(action));
	    }
	    if (isstdin()) {
		printevent(e);
	    }
	} else {
	    stopinst(p->op, place, cond, action);
	}
E 8
    }
}

D 8
private stopinst(op, place, cond)
E 8
I 8
private stopinst(op, place, cond, action)
E 8
Operator op;
Node place;
Node cond;
I 8
Command action;
E 8
{
    Node event;
I 6
    Event e;
E 6

    if (op == O_STOP) {
	event = build(O_EQ, build(O_SYM, linesym), place);
    } else {
	event = build(O_EQ, build(O_SYM, pcsym), place);
    }
D 6
    addevent(event, buildcmdlist(build(O_STOPX)));
E 6
I 6
D 8
    e = addevent(event, buildcmdlist(build(O_STOPX)));
E 8
I 8
    e = addevent(event, buildcmdlist(action));
E 8
    if (isstdin()) {
	printevent(e);
    }
E 6
}

/*
 * Implement stopping on assignment to a variable by adding it to
 * the variable list.
 */

private stopvar(op, exp, place, cond)
Operator op;
Node exp;
Node place;
Node cond;
{
    Symbol p;
    Node event;
    Command action;

I 21
    if (size(exp->nodetype) > MAXTRSIZE) {
	error("expression too large to trace (limit is %d bytes)", MAXTRSIZE);
    }
E 21
D 9
    p = (place == nil) ? tcontainer(exp) : place->value.sym;
    if (p == nil) {
	p = program;
E 9
I 9
    if (place == nil) {
	if (exp->op == O_LCON) {
	    p = program;
	} else {
	    p = tcontainer(exp);
	    if (p == nil) {
		p = program;
	    }
	}
    } else {
	p = place->value.sym;
E 9
    }
D 9
    action = build(O_IF, cond, buildcmdlist(build(O_STOPIFCHANGED, exp)));
E 9
I 9
    action = build(O_STOPIFCHANGED, exp);
    if (cond != nil) {
	action = build(O_IF, cond, buildcmdlist(action));
    }
E 9
    action = build(O_TRACEON, (op == O_STOPI), buildcmdlist(action));
    event = build(O_EQ, build(O_SYM, procsym), build(O_SYM, p));
    action->value.trace.event = addevent(event, buildcmdlist(action));
I 6
    if (isstdin()) {
	printevent(action->value.trace.event);
    }
E 6
}

/*
 * Assign the value of an expression to a variable (or term).
 */

public assign(var, exp)
Node var;
Node exp;
{
    Address addr;
D 11
    int varsize;
E 11
I 11
    integer varsize, expsize;
E 11
    char cvalue;
    short svalue;
    long lvalue;
I 11
    float fvalue;
E 11

D 15
    if (not compatible(var->nodetype, exp->nodetype)) {
	error("incompatible types");
    }
    addr = lval(var);
D 11
    eval(exp);
E 11
    varsize = size(var->nodetype);
D 11
    if (varsize < sizeof(long)) {
	lvalue = pop(long);
	switch (varsize) {
	    case sizeof(char):
		cvalue = lvalue;
		dwrite(&cvalue, addr, varsize);
		break;
E 11
I 11
    expsize = size(exp->nodetype);
    eval(exp);
    if (varsize == sizeof(float) and expsize == sizeof(double)) {
	fvalue = (float) pop(double);
	dwrite(&fvalue, addr, sizeof(fvalue));
E 15
I 15
    if (var->op == O_SYM and regnum(var->value.sym) != -1) {
	eval(exp);
	setreg(regnum(var->value.sym), pop(Address));
E 15
    } else {
D 15
	if (varsize < sizeof(long)) {
	    lvalue = 0;
	    popn(expsize, &lvalue);
	    switch (varsize) {
		case sizeof(char):
E 15
I 15
	addr = lval(var);
	varsize = size(var->nodetype);
	expsize = size(exp->nodetype);
	eval(exp);
	if (varsize == sizeof(float) and expsize == sizeof(double)) {
	    fvalue = (float) pop(double);
	    dwrite(&fvalue, addr, sizeof(fvalue));
	} else {
	    if (varsize < sizeof(long)) {
		lvalue = 0;
		popn(expsize, &lvalue);
		if (varsize == sizeof(char)) {
E 15
		    cvalue = lvalue;
		    dwrite(&cvalue, addr, sizeof(cvalue));
D 15
		    break;
E 11

D 11
	    case sizeof(short):
		svalue = lvalue;
		dwrite(&svalue, addr, varsize);
		break;
E 11
I 11
		case sizeof(short):
E 15
I 15
		} else if (varsize == sizeof(short)) {
E 15
		    svalue = lvalue;
		    dwrite(&svalue, addr, sizeof(svalue));
D 15
		    break;
E 11

D 11
	    default:
		panic("bad size %d", varsize);
E 11
I 11
		default:
		    panic("bad size %d", varsize);
E 15
I 15
		} else {
		    error("[internal error: bad size %d in assign]", varsize);
		}
	    } else {
		if (expsize <= varsize) {
		    sp -= expsize;
		    dwrite(sp, addr, expsize);
		} else {
		    sp -= expsize;
		    dwrite(sp, addr, varsize);
		}
E 15
	    }
I 15
	}
    }
}

/*
 * Set a debugger variable.
 */

private set (var, exp)
Node var, exp;
{
    Symbol t;

    if (var == nil) {
	defvar(nil, nil);
    } else if (exp == nil) {
	defvar(var->value.name, nil);
    } else if (var->value.name == identname("$frame", true)) {
	t = exp->nodetype;
	if (not compatible(t, t_int) and not compatible(t, t_addr)) {
	    error("$frame must be an address");
	}
	eval(exp);
	getnewregs(pop(Address));
    } else {
	defvar(var->value.name, unrval(exp));
    }
}

/*
 * Execute a list command.
 */

private list (p)
Node p;
{
    Symbol f;
    Address addr;
    Lineno line, l1, l2;

    if (p->value.arg[0]->op == O_SYM) {
	f = p->value.arg[0]->value.sym;
	addr = firstline(f);
	if (addr == NOADDR) {
	    error("no source lines for \"%s\"", symname(f));
	}
	setsource(srcfilename(addr));
	line = srcline(addr);
	getsrcwindow(line, &l1, &l2);
    } else {
	eval(p->value.arg[0]);
	l1 = (Lineno) (pop(long));
	eval(p->value.arg[1]);
	l2 = (Lineno) (pop(long));
    }
    printlines(l1, l2);
}

/*
 * Execute a func command.
 */

private func (p)
Node p;
{
    Symbol s, f;
    Address addr;

    if (p == nil) {
	printname(stdout, curfunc);
	putchar('\n');
    } else {
	s = p->value.sym;
	if (isroutine(s)) {
	    setcurfunc(s);
E 15
	} else {
D 15
	    if (expsize <= varsize) {
		sp -= expsize;
		dwrite(sp, addr, expsize);
	    } else {
		sp -= expsize;
		dwrite(sp, addr, varsize);
E 15
I 15
	    find(f, s->name) where isroutine(f) endfind(f);
	    if (f == nil) {
		error("%s is not a procedure or function", symname(s));
E 15
	    }
I 15
	    setcurfunc(f);
E 15
E 11
	}
I 15
	addr = codeloc(curfunc);
	if (addr != NOADDR) {
	    setsource(srcfilename(addr));
	    cursrcline = srcline(addr);
	}
E 15
D 11
    } else {
	sp -= varsize;
	dwrite(sp, addr, varsize);
E 11
    }
}

D 9
#define DEF_EDITOR  "vi"

E 9
/*
D 9
 * Invoke an editor on the given file.  Which editor to use might change
 * installation to installation.  For now, we use "vi".  In any event,
 * the environment variable "EDITOR" overrides any default.
 */

public edit(filename)
String filename;
{
    extern String getenv();
    String ed, src;
    File f;
    Symbol s;
    Address addr;
    char buff[10];

    ed = getenv("EDITOR");
    if (ed == nil) {
	ed = DEF_EDITOR;
    }
    if (filename == nil) {
	call(ed, stdin, stdout, cursource, nil);
    } else {
	f = fopen(filename, "r");
	if (f == nil) {
	    s = which(identname(filename, true));
	    if (not isblock(s)) {
		error("can't read \"%s\"", filename);
	    }
	    addr = firstline(s);
	    if (addr == NOADDR) {
		error("no source for \"%s\"", filename);
	    }
	    src = srcfilename(addr);
	    sprintf(buff, "+%d", srcline(addr));
	    call(ed, stdin, stdout, buff, src, nil);
	} else {
	    fclose(f);
	    call(ed, stdin, stdout, filename, nil);
	}
    }
}

/*
E 9
D 15
 * Send some nasty mail to the current support person.
E 15
I 15
 * Send a message to the current support person.
E 15
 */

I 17
D 18
ifdef MAINTAINER
E 18
I 18
D 21
#ifdef MAINTAINER
E 18
static char maintainer[] = MAINTAINER;
#else
static char maintainer[] = "";
#endif

E 21
E 17
public gripe()
{
    typedef Operation();
    Operation *old;
I 9
    int pid, status;
E 9
D 11

E 11
I 11
    extern int versionNumber;
    char subject[100];
E 11
D 9
    char *maintainer = "linton@ucbarpa";
E 9
I 9
D 15
    char *maintainer = "linton@berkeley";
E 15
E 9

I 17
D 21
    if (maintainer[0] == '\0') {
	puts("Gripes not supported at this site.  Sorry.");
	return;
    }
E 17
    puts("Type control-D to end your message.  Be sure to include");
    puts("your name and the name of the file you are debugging.");
    putchar('\n');
    old = signal(SIGINT, SIG_DFL);
D 9
    call("Mail", stdin, stdout, maintainer, nil);
E 9
I 9
D 11
    pid = back("Mail", stdin, stdout, "-s", "dbx gripe", maintainer, nil);
E 11
I 11
D 15
    sprintf(subject, "dbx (version %d) gripe", versionNumber);
    pid = back("Mail", stdin, stdout, "-s", subject, maintainer, nil);
E 15
I 15
    sprintf(subject, "dbx (version 3.%d) gripe", versionNumber);
D 17
    pid = back("Mail", stdin, stdout, "-s", subject, MAINTAINER, nil);
E 17
I 17
    pid = back("Mail", stdin, stdout, "-s", subject, maintainer, nil);
E 17
E 15
E 11
    signal(SIGINT, SIG_IGN);
    pwait(pid, &status);
E 9
    signal(SIGINT, old);
D 9
    puts("Thank you.");
E 9
I 9
    if (status == 0) {
	puts("Thank you.");
    } else {
	puts("\nMail not sent.");
    }
E 21
I 21
#   ifdef MAINTAINER
	puts("Type control-D to end your message.  Be sure to include");
	puts("your name and the name of the file you are debugging.");
	putchar('\n');
	old = signal(SIGINT, SIG_DFL);
	sprintf(subject, "dbx (version 3.%d) gripe", versionNumber);
	pid = back("Mail", stdin, stdout, "-s", subject, MAINTAINER, nil);
	signal(SIGINT, SIG_IGN);
	pwait(pid, &status);
	signal(SIGINT, old);
	if (status == 0) {
	    puts("Thank you.");
	} else {
	    puts("\nMail not sent.");
	}
#   else
	puts("Sorry, no dbx maintainer available to gripe to.");
	puts("Try contacting your system manager.");
#   endif
E 21
E 9
}

/*
 * Give the user some help.
 */

public help()
{
    puts("run                    - begin execution of the program");
I 11
    puts("print <exp>            - print the value of the expression");
    puts("where                  - print currently active procedures");
    puts("stop at <line>         - suspend execution at the line");
    puts("stop in <proc>         - suspend execution when <proc> is called");
E 11
    puts("cont                   - continue execution");
    puts("step                   - single step one line");
    puts("next                   - step to next line (skip over calls)");
    puts("trace <line#>          - trace execution of the line");
    puts("trace <proc>           - trace calls to the procedure");
    puts("trace <var>            - trace changes to the variable");
    puts("trace <exp> at <line#> - print <exp> when <line> is reached");
D 11
    puts("stop at <line>         - suspend execution at the line");
    puts("stop in <proc>         - suspend execution when <proc> is called");
E 11
    puts("status                 - print trace/stop's in effect");
    puts("delete <number>        - remove trace or stop of given number");
D 11
    puts("call <proc>            - call the procedure");
    puts("where                  - print currently active procedures");
    puts("print <exp>            - print the value of the expression");
E 11
I 11
    puts("call <proc>            - call a procedure in program");
E 11
    puts("whatis <name>          - print the declaration of the name");
    puts("list <line>, <line>    - list source lines");
D 11
    puts("edit <proc>            - edit file containing <proc>");
E 11
    puts("gripe                  - send mail to the person in charge of dbx");
    puts("quit                   - exit dbx");
I 14
D 15
}

/*
 * Mark one or more signals to be
 * intercepted by the debugger.
 */
private catchsigs(p)
register Node p;
{

    if (p == nil) {
	printsigscaught(process);
	return;
    }
    while (p != nil) {
	eval(p->value.arg[0]);
	psigtrace(process, popsmall(p->value.arg[0]->nodetype), true);
	p = p->value.arg[1];
    }
}

/*
 * Mark one or more signals to
 * be ignored by the debugger
 * (and automatically passed through
 * to the running process).
 */
private ignoresigs(p)
register Node p;
{

    if (p == nil) {
	printsigsignored(process);
	return;
    }
    while (p != nil) {
	eval(p->value.arg[0]);
	psigtrace(process, popsmall(p->value.arg[0]->nodetype), false);
	p = p->value.arg[1];
    }
E 15
E 14
}

/*
 * Divert output to the given file name.
 * Cannot redirect to an existing file.
 */

private int so_fd;
private Boolean notstdout;

public setout(filename)
String filename;
{
    File f;

    f = fopen(filename, "r");
    if (f != nil) {
	fclose(f);
	error("%s: file already exists", filename);
    } else {
	so_fd = dup(1);
	close(1);
	if (creat(filename, 0666) == nil) {
	    unsetout();
	    error("can't create %s", filename);
	}
	notstdout = true;
    }
}

/*
 * Revert output to standard output.
 */

public unsetout()
{
    fflush(stdout);
    close(1);
    if (dup(so_fd) != 1) {
	panic("standard out dup failed");
    }
    close(so_fd);
    notstdout = false;
}

/*
 * Determine is standard output is currently being redirected
 * to a file (as far as we know).
 */

public Boolean isredirected()
{
    return notstdout;
}
E 1
