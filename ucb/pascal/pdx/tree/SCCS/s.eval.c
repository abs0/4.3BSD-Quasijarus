h01938
s 00018/00003/00532
d D 5.2 87/04/07 15:57:57 mckusick 12 11
c port to tahoe by Nir peleg of CCI
e
s 00008/00002/00527
d D 5.1 85/06/06 15:55:46 dist 11 10
c Add copyright
e
s 00003/00003/00526
d D 1.10 83/02/14 23:28:38 linton 10 9
c changed the way the INDEX operator is evaluated to better
e
s 00012/00001/00517
d D 1.9 83/02/08 17:59:32 linton 9 8
c 
e
s 00008/00001/00510
d D 1.8 82/05/19 20:35:44 linton 8 7
c added error handling for the "file" command
e
s 00018/00016/00493
d D 1.7 82/03/09 02:03:13 linton 7 6
c internal booleans, some long vs. int cleanup for 11/70's
e
s 00007/00001/00502
d D 1.6 82/03/08 19:34:23 linton 6 5
c changed evaluation of LIST operator so that it did a 
c "skimsource" of the associated source file before printing the lines
e
s 00003/00003/00500
d D 1.5 82/03/08 18:58:05 linton 5 4
c fixed evaluation of expressions containing small values 
c (i.e. stored in less than a word)
e
s 00008/00004/00495
d D 1.4 82/02/17 18:54:02 linton 4 3
c the NAME operator now checks to make sure its operand is a variable
e
s 00367/00339/00132
d D 1.3 82/02/13 17:18:18 linton 3 2
c reorganized the way small ( < a long ) elements are manipulated 
c on the evaluation stack
e
s 00034/00003/00437
d D 1.2 82/01/18 23:34:55 linton 2 1
c gripe
e
s 00440/00000/00000
d D 1.1 82/01/18 19:21:37 linton 1 0
c date and time created 82/01/18 19:21:37 by linton
e
u
U
t
T
I 1
D 11
/* Copyright (c) 1982 Regents of the University of California */
E 11
I 11
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 11

D 11
static char sccsid[] = "%Z%%M% %I% %G%";
E 11
I 11
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 11

/*
D 2
 * parse tree evaluation
E 2
I 2
 * Parse tree evaluation.
E 2
 */

#include "defs.h"
#include "tree.h"
#include "sym.h"
#include "process.h"
#include "source.h"
#include "mappings.h"
#include "breakpoint.h"
#include "machine.h"
#include "tree.rep"
I 12
#include "process/process.rep"
#include "process/pxinfo.h"
E 12

I 7
#define Boolean char	/* underlying representation type for booleans */

E 7
/*
 * Evaluate a parse tree using a stack; value is left at top.
 */

I 2
#define STACKSIZE 2000

STACK stack[STACKSIZE];
E 2
STACK *sp = &stack[0];

eval(p)
register NODE *p;
{
D 3
	long r0, r1;
	double fr0, fr1;
E 3
I 3
    long r0, r1;
    double fr0, fr1;
I 8
    FILE *fp;
E 8
E 3

D 3
	if (p == NULL) {
		return;
E 3
I 3
    if (p == NULL) {
	return;
    }
    switch(degree(p->op)) {
	case BINARY:
	    eval(p->right);
	    if (isreal(p->op)) {
		fr1 = pop(double);
	    } else if (isint(p->op)) {
D 5
		r1 = pop(long);
E 5
I 5
		r1 = popsmall(p->right->nodetype);
E 5
	    }
	    /* fall through */
	case UNARY:
	    eval(p->left);
	    if (isreal(p->op)) {
		fr0 = pop(double);
	    } else if (isint(p->op)) {
D 5
		r0 = pop(long);
E 5
I 5
		r0 = popsmall(p->left->nodetype);
E 5
	    }
	    break;

	default:
	    /* do nothing */;
E 3
	}
D 3
	switch(degree(p->op)) {
		case BINARY:
			eval(p->right);
			if (isreal(p->op)) {
				fr1 = pop(double);
			} else if (isint(p->op)) {
				r1 = pop(long);
			}
			/* fall through */
		case UNARY:
			eval(p->left);
			if (isreal(p->op)) {
				fr0 = pop(double);
			} else if (isint(p->op)) {
				r0 = pop(long);
			}
			break;
E 3
I 3
    switch(p->op) {
	case O_NAME: {
	    SYM *s, *f;
E 3

D 3
		default:
			/* do nothing */;
		}
	switch(p->op) {
		case O_NAME: {
			SYM *s, *f;
E 3
I 3
	    s = p->nameval;
D 4
	    f = container(s);
	    if (!isactive(f)) {
		error("\"%s\" is not active", name(f));
E 4
I 4
	    if (!isvariable(s)) {
		error("cannot evaluate a %s", classname(s));
	    } else {
		f = container(s);
		if (!isactive(f)) {
		    error("\"%s\" is not active", name(f));
		}
D 7
		push(int, address(s, NIL));
E 7
I 7
		push(long, address(s, NIL));
E 7
E 4
	    }
D 4
	    push(int, address(s, NIL));
E 4
	    break;
	}
E 3

D 3
			s = p->nameval;
			f = container(s);
			if (!isactive(f)) {
				error("\"%s\" is not active", name(f));
			}
			push(int, address(s, NIL));
			break;
		}
E 3
I 3
	case O_LCON:
	    switch (size(p->nodetype)) {
		case sizeof(char):
		    push(char, p->lconval);
		    break;
E 3

D 3
		case O_LCON:
			push(long, p->lconval);
			break;
E 3
I 3
		case sizeof(short):
		    push(short, p->lconval);
		    break;
E 3

D 3
		case O_FCON:
			push(double, p->fconval);
			break;
E 3
I 3
		case sizeof(long):
		    push(long, p->lconval);
		    break;
E 3

D 3
		case O_SCON: {
			int len;
E 3
I 3
		default:
		    panic("bad size %d for LCON", size(p->nodetype));
	    }
	    break;
E 3

D 3
			len = size(p->nodetype);
			mov(p->sconval, sp, len);
			sp += len;
			break;
		}
E 3
I 3
	case O_FCON:
	    push(double, p->fconval);
	    break;
E 3

D 3
		case O_INDEX: {
			int n;
			long i;
E 3
I 3
	case O_SCON: {
	    int len;
E 3

D 3
			n = pop(int);
			i = evalindex(p->left->nodetype);
			push(int, n + i*size(p->nodetype));
			break;
		}
E 3
I 3
	    len = size(p->nodetype);
	    mov(p->sconval, sp, len);
	    sp += len;
I 12
#ifdef tahoe
	    alignstack();
#endif tahoe
E 12
	    break;
	}
E 3

D 3
		case O_INDIR: {
			ADDRESS a;
E 3
I 3
	case O_INDEX: {
D 10
	    int n;
	    long i;
E 10
I 10
	    long n;	/* base address for array */
	    long i;	/* index - lower bound */
I 12
	    long evalindex();
E 12
E 10
E 3

D 3
			a = pop(ADDRESS);
			if (a == 0) {
				error("reference through nil pointer");
			}
			dread(sp, a, sizeof(ADDRESS));
			sp += sizeof(ADDRESS);
			break;
		}
E 3
I 3
D 7
	    n = pop(int);
E 7
I 7
	    n = pop(long);
E 7
D 10
	    i = evalindex(p->left->nodetype, popsmall(p->right->nodetype));
E 10
I 10
	    i = evalindex(p->left->nodetype, p->right);
E 10
D 7
	    push(int, n + i*size(p->nodetype));
E 7
I 7
	    push(long, n + i*size(p->nodetype));
E 7
	    break;
	}
E 3

D 3
		/*
		 * Get the value of the expression addressed by the top of the stack.
		 * Push the result back on the stack.  Never push less than a long.
		 */
E 3
I 3
	case O_INDIR: {
	    ADDRESS a;
E 3

D 3
		case O_RVAL: {
			ADDRESS addr, len;
			long i;
E 3
I 3
	    a = pop(ADDRESS);
	    if (a == 0) {
		error("reference through nil pointer");
	    }
	    dread(sp, a, sizeof(ADDRESS));
	    sp += sizeof(ADDRESS);
	    break;
	}
E 3

D 3
			addr = pop(int);
			if (addr == 0) {
				error("reference through nil pointer");
			}
			len = size(p->nodetype);
D 2
			dread(sp, addr, len);
			sp += len;
E 2
I 2
			if (!rpush(addr, len)) {
				error("expression too large to evaluate");
			}
E 2
			if (len < sizeof(long)) {
				switch (len) {
					case sizeof(char):
						i = pop(char);
						break;
E 3
I 3
	/*
	 * Get the value of the expression addressed by the top of the stack.
D 5
	 * Push the result back on the stack.  Never push less than a long.
E 5
I 5
	 * Push the result back on the stack.
E 5
	 */
E 3

D 3
					case sizeof(short):
						i = pop(short);
						break;
E 3
I 3
	case O_RVAL: {
	    ADDRESS addr, len;
D 12
	    long i;
E 12
E 3

D 3
					default:
						panic("bad size in RVAL");
				}
				push(long, i);
			}
			break;
		}
E 3
I 3
D 7
	    addr = pop(int);
E 7
I 7
	    addr = pop(long);
E 7
	    if (addr == 0) {
		error("reference through nil pointer");
	    }
	    len = size(p->nodetype);
	    if (!rpush(addr, len)) {
		error("expression too large to evaluate");
	    }
	    break;
	}
E 3

D 3
		case O_COMMA:
			break;
E 3
I 3
	case O_COMMA:
	    break;
E 3

D 3
		case O_ITOF:
			push(double, (double) r0);
			break;
E 3
I 3
	case O_ITOF:
	    push(double, (double) r0);
	    break;

	case O_ADD:
	    push(long, r0+r1);
	    break;
E 3

D 3
		case O_ADD:
			push(long, r0+r1);
			break;
E 3
I 3
	case O_ADDF:
	    push(double, fr0+fr1);
	    break;
E 3

D 3
		case O_ADDF:
			push(double, fr0+fr1);
			break;
E 3
I 3
	case O_SUB:
	    push(long, r0-r1);
	    break;
E 3

D 3
		case O_SUB:
			push(long, r0-r1);
			break;
E 3
I 3
	case O_SUBF:
	    push(double, fr0-fr1);
	    break;
E 3

D 3
		case O_SUBF:
			push(double, fr0-fr1);
			break;
E 3
I 3
	case O_NEG:
	    push(long, -r0);
	    break;
E 3

D 3
		case O_NEG:
			push(long, -r0);
			break;
E 3
I 3
	case O_NEGF:
	    push(double, -fr0);
	    break;
E 3

D 3
		case O_NEGF:
			push(double, -fr0);
			break;
E 3
I 3
	case O_MUL:
	    push(long, r0*r1);
	    break;
E 3

D 3
		case O_MUL:
			push(long, r0*r1);
			break;
E 3
I 3
	case O_MULF:
	    push(double, fr0*fr1);
	    break;
E 3

D 3
		case O_MULF:
			push(double, fr0*fr1);
			break;
E 3
I 3
	case O_DIVF:
	    if (fr1 == 0) {
		error("error: division by 0");
	    }
	    push(double, fr0/fr1);
	    break;
E 3

D 3
		case O_DIVF:
			if (fr1 == 0) {
				error("error: division by 0");
			}
			push(double, fr0/fr1);
			break;
E 3
I 3
	case O_DIV:
	    if (r1 == 0) {
		error("error: div by 0");
	    }
	    push(long, r0/r1);
	    break;
E 3

D 3
		case O_DIV:
			if (r1 == 0) {
				error("error: div by 0");
			}
			push(long, r0/r1);
			break;
E 3
I 3
	case O_MOD:
	    if (r1 == 0) {
		error("error: mod by 0");
	    }
	    push(long, r0%r1);
	    break;
E 3

D 3
		case O_MOD:
			if (r1 == 0) {
				error("error: mod by 0");
			}
			push(long, r0%r1);
			break;
E 3
I 3
	case O_LT:
D 7
	    push(BOOLEAN, r0 < r1);
E 7
I 7
	    push(Boolean, r0 < r1);
E 7
	    break;
E 3

D 3
		case O_LT:
			push(BOOLEAN, r0 < r1);
			break;
E 3
I 3
	case O_LTF:
D 7
	    push(BOOLEAN, fr0 < fr1);
E 7
I 7
	    push(Boolean, fr0 < fr1);
E 7
	    break;
E 3

D 3
		case O_LTF:
			push(BOOLEAN, fr0 < fr1);
			break;
E 3
I 3
	case O_LE:
D 7
	    push(BOOLEAN, r0 <= r1);
E 7
I 7
	    push(Boolean, r0 <= r1);
E 7
	    break;
E 3

D 3
		case O_LE:
			push(BOOLEAN, r0 <= r1);
			break;
E 3
I 3
	case O_LEF:
D 7
	    push(BOOLEAN, fr0 <= fr1);
E 7
I 7
	    push(Boolean, fr0 <= fr1);
E 7
	    break;
E 3

D 3
		case O_LEF:
			push(BOOLEAN, fr0 <= fr1);
			break;
E 3
I 3
	case O_GT:
D 7
	    push(BOOLEAN, r0 > r1);
E 7
I 7
	    push(Boolean, r0 > r1);
E 7
	    break;
E 3

D 3
		case O_GT:
			push(BOOLEAN, r0 > r1);
			break;
E 3
I 3
	case O_GTF:
D 7
	    push(BOOLEAN, fr0 > fr1);
E 7
I 7
	    push(Boolean, fr0 > fr1);
E 7
	    break;
E 3

D 3
		case O_GTF:
			push(BOOLEAN, fr0 > fr1);
			break;
E 3
I 3
	case O_EQ:
D 7
	    push(BOOLEAN, r0 == r1);
E 7
I 7
	    push(Boolean, r0 == r1);
E 7
	    break;
E 3

D 3
		case O_EQ:
			push(BOOLEAN, r0 == r1);
			break;
E 3
I 3
	case O_EQF:
D 7
	    push(BOOLEAN, fr0 == fr1);
E 7
I 7
	    push(Boolean, fr0 == fr1);
E 7
	    break;
E 3

D 3
		case O_EQF:
			push(BOOLEAN, fr0 == fr1);
			break;
E 3
I 3
	case O_NE:
D 7
	    push(BOOLEAN, r0 != r1);
E 7
I 7
	    push(Boolean, r0 != r1);
E 7
	    break;
E 3

D 3
		case O_NE:
			push(BOOLEAN, r0 != r1);
			break;
E 3
I 3
	case O_NEF:
D 7
	    push(BOOLEAN, fr0 != fr1);
E 7
I 7
	    push(Boolean, fr0 != fr1);
E 7
	    break;
E 3

D 3
		case O_NEF:
			push(BOOLEAN, fr0 != fr1);
			break;
E 3
I 3
	case O_AND:
D 7
	    push(BOOLEAN, r0 && r1);
E 7
I 7
	    push(Boolean, r0 && r1);
E 7
	    break;
E 3

D 3
		case O_AND:
			push(BOOLEAN, r0 && r1);
			break;
E 3
I 3
	case O_OR:
D 7
	    push(BOOLEAN, r0 || r1);
E 7
I 7
	    push(Boolean, r0 || r1);
E 7
	    break;
E 3

D 3
		case O_OR:
			push(BOOLEAN, r0 || r1);
			break;
E 3
I 3
	case O_ASSIGN:
	    assign(p->left, p->right);
	    break;
E 3

D 3
		case O_ASSIGN:
			assign(p->left, p->right);
			break;
E 3
I 3
	case O_CHFILE:
	    if (p->sconval == NIL) {
		printf("%s\n", cursource);
	    } else {
D 8
		skimsource(p->sconval);
E 8
I 8
		fp = fopen(p->sconval, "r");
		if (fp == NIL) {
		    error("can't read \"%s\"", p->sconval);
		} else {
		    fclose(fp);
		    skimsource(p->sconval);
		}
E 8
	    }
	    break;
E 3

D 3
		case O_CHFILE:
			if (p->sconval == NIL) {
				printf("%s\n", cursource);
			} else {
				skimsource(p->sconval);
			}
			break;
E 3
I 3
	case O_CONT:
	    cont();
	    printnews();
	    break;
E 3

D 3
		case O_CONT:
			cont();
			printnews();
			break;
E 3
I 3
	case O_LIST: {
	    SYM *b;
I 6
	    ADDRESS addr;
E 6
E 3

D 3
		case O_LIST: {
			SYM *b;

			if (p->left->op == O_NAME) {
				b = p->left->nameval;
				if (!isblock(b)) {
					error("\"%s\" is not a procedure or function", name(b));
				}
				r0 = srcline(firstline(b));
				r1 = r0 + 5;
				if (r1 > lastlinenum) {
					r1 = lastlinenum;
				}
				r0 = r0 - 5;
				if (r0 < 1) {
					r0 = 1;
				}
			} else {
				eval(p->left->right);
				eval(p->left->left);
				r0 = pop(long);
				r1 = pop(long);
			}
			printlines((LINENO) r0, (LINENO) r1);
			break;
E 3
I 3
	    if (p->left->op == O_NAME) {
		b = p->left->nameval;
		if (!isblock(b)) {
		    error("\"%s\" is not a procedure or function", name(b));
E 3
		}
I 3
D 6
		r0 = srcline(firstline(b));
E 6
I 6
		addr = firstline(b);
D 12
		if (addr == -1) {
E 12
I 12
		if ((int)addr == -1) {
E 12
		    error("\"%s\" is empty", name(b));
		}
		skimsource(srcfilename(addr));
		r0 = srcline(addr);
E 6
		r1 = r0 + 5;
		if (r1 > lastlinenum) {
		    r1 = lastlinenum;
		}
		r0 = r0 - 5;
		if (r0 < 1) {
		    r0 = 1;
		}
	    } else {
		eval(p->left->right);
		eval(p->left->left);
		r0 = pop(long);
		r1 = pop(long);
	    }
	    printlines((LINENO) r0, (LINENO) r1);
	    break;
	}
E 3

D 3
		case O_XI:
		case O_XD:
		{
			SYM *b;
E 3
I 3
	case O_XI:
	case O_XD:
	{
	    SYM *b;
E 3

D 3
			if (p->left->op == O_CALL) {
				b = p->left->left->nameval;
				r0 = codeloc(b);
				r1 = firstline(b);
			} else {
				eval(p->left->right);
				eval(p->left->left);
				r0 = pop(long);
				r1 = pop(long);
			}
			if (p->op == O_XI)  {
				printinst((ADDRESS) r0, (ADDRESS) r1);
			} else {
				printdata((ADDRESS) r0, (ADDRESS) r1);
			}
			break;
		}
E 3
I 3
	    if (p->left->op == O_CALL) {
		b = p->left->left->nameval;
		r0 = codeloc(b);
		r1 = firstline(b);
	    } else {
		eval(p->left->right);
		eval(p->left->left);
		r0 = pop(long);
		r1 = pop(long);
	    }
	    if (p->op == O_XI)  {
		printinst((ADDRESS) r0, (ADDRESS) r1);
	    } else {
		printdata((ADDRESS) r0, (ADDRESS) r1);
	    }
	    break;
	}
E 3

D 3
		case O_NEXT:
			next();
			printnews();
			break;
E 3
I 3
	case O_NEXT:
	    next();
	    printnews();
	    break;
E 3

D 3
		case O_PRINT: {
			NODE *o;
E 3
I 3
	case O_PRINT: {
	    NODE *o;
E 3

D 3
			for (o = p->left; o != NIL; o = o->right) {
				eval(o->left);
				printval(o->left->nodetype);
				putchar(' ');
			}
			putchar('\n');
			break;
		}
E 3
I 3
	    for (o = p->left; o != NIL; o = o->right) {
		eval(o->left);
		printval(o->left->nodetype);
		putchar(' ');
	    }
	    putchar('\n');
	    break;
	}
E 3

D 3
		case O_STEP:
			stepc();
			printnews();
			break;
E 3
I 3
	case O_STEP:
	    stepc();
	    printnews();
	    break;
E 3

D 3
		case O_WHATIS:
			if (p->left->op == O_NAME) {
				printdecl(p->left->nameval);
			} else {
				printdecl(p->left->nodetype);
			}
			break;
E 3
I 3
	case O_WHATIS:
	    if (p->left->op == O_NAME) {
		printdecl(p->left->nameval);
	    } else {
		printdecl(p->left->nodetype);
	    }
	    break;
E 3

D 3
		case O_WHICH:
			printwhich(p->nameval);
			putchar('\n');
			break;
E 3
I 3
	case O_WHICH:
	    printwhich(p->nameval);
	    putchar('\n');
	    break;
E 3

D 3
		case O_WHERE:
			where();
			break;
E 3
I 3
	case O_WHERE:
	    where();
	    break;
E 3

D 3
		case O_ALIAS:
			alias(p->left->sconval, p->right->sconval);
			break;
E 3
I 3
	case O_ALIAS:
	    alias(p->left->sconval, p->right->sconval);
	    break;
E 3

D 3
		case O_CALL:
			callproc(p->left, p->right);
			break;
E 3
I 3
	case O_CALL:
	    callproc(p->left, p->right);
	    break;
E 3

D 3
		case O_EDIT:
			edit(p->sconval);
			break;
E 3
I 3
	case O_EDIT:
	    edit(p->sconval);
	    break;
E 3

D 3
		case O_DUMP:
			dump();
			break;
E 3
I 3
	case O_DUMP:
	    dump();
	    break;
E 3

I 2
D 3
		case O_GRIPE:
			gripe();
			break;
E 3
I 3
	case O_GRIPE:
	    gripe();
	    break;
E 3

E 2
D 3
		case O_HELP:
			help();
			break;
E 3
I 3
	case O_HELP:
	    help();
	    break;
E 3

D 3
		case O_REMAKE:
			remake();
			break;
E 3
I 3
	case O_REMAKE:
	    remake();
	    break;
E 3

D 3
		case O_RUN:
			run();
			break;
E 3
I 3
	case O_RUN:
	    run();
	    break;
E 3

D 3
		case O_SOURCE:
			setinput(p->sconval);
			break;
E 3
I 3
	case O_SOURCE:
	    setinput(p->sconval);
	    break;
E 3

D 3
		case O_STATUS:
			status();
			break;
E 3
I 3
	case O_STATUS:
	    status();
	    break;
E 3

D 3
		case O_TRACE:
		case O_TRACEI:
			trace(p->op, p->what, p->where, p->cond);
			if (isstdin()) {
				status();
			}
			break;
E 3
I 3
	case O_TRACE:
	case O_TRACEI:
	    trace(p->op, p->what, p->where, p->cond);
	    if (isstdin()) {
		status();
	    }
	    break;
E 3

D 3
		case O_STOP:
		case O_STOPI:
			stop(p->op, p->what, p->where, p->cond);
			if (isstdin()) {
				status();
			}
			break;
E 3
I 3
	case O_STOP:
	case O_STOPI:
	    stop(p->op, p->what, p->where, p->cond);
	    if (isstdin()) {
		status();
	    }
	    break;
E 3

D 3
		case O_DELETE:
			eval(p->left);
			delbp((unsigned int) pop(long));
			break;
E 3
I 3
	case O_DELETE:
	    eval(p->left);
	    delbp((unsigned int) pop(long));
	    break;
E 3

D 3
		default:
			panic("eval: bad op %d", p->op);
	}
E 3
I 3
	default:
	    panic("eval: bad op %d", p->op);
    }
E 3
I 2
}

/*
 * Push "len" bytes onto the expression stack from address "addr"
 * in the process.  Normally TRUE is returned, however if there
 * isn't enough room on the stack, rpush returns FALSE.
D 3
 * 
E 3
 */

BOOLEAN rpush(addr, len)
ADDRESS addr;
int len;
{
D 3
	BOOLEAN success;
E 3
I 3
    BOOLEAN success;
I 12
#ifdef tahoe
    register char *savesp = sp;
#endif
E 12
E 3

D 3
	if (sp + len >= &stack[STACKSIZE]) {
		success = FALSE;
	} else {
		dread(sp, addr, len);
		sp += len;
		success = TRUE;
	}
	return success;
E 3
I 3
    if (sp + len >= &stack[STACKSIZE]) {
	success = FALSE;
    } else {
	dread(sp, addr, len);
	sp += len;
D 12
	success = TRUE;
E 12
I 12
#ifdef tahoe
        alignstack();
	if (sp >= &stack[STACKSIZE]) {
		success = FALSE;
		sp = savesp;
	} else
#endif
	    success = TRUE;
E 12
    }
    return success;
E 3
E 2
}

/*
I 3
 * Pop an item of the given type which is assumed to be no larger
 * than a long and return it expanded into a long.
 */

long popsmall(t)
SYM *t;
{
    long r;

    switch (size(t)) {
	case sizeof(char):
	    r = (long) pop(char);
	    break;

	case sizeof(short):
	    r = (long) pop(short);
	    break;

	case sizeof(long):
	    r = pop(long);
	    break;

I 9
	/*
	 * A bit of a kludge here.  If an array element is a record,
	 * the dot operation will be converted into an addition with
	 * the record operand having a type whose size may be larger
	 * than a word.  Now actually this is a pointer, but the subscript
	 * operation isn't aware of this, so it's just hacked here.
	 *
	 * The right thing to do is to make dot directly evaluated
	 * instead of changing it into addition.
	 */
E 9
	default:
D 9
	    panic("popsmall: size is %d", size(t));
E 9
I 9
	    r = pop(ADDRESS);
	    break;
E 9
    }
    return r;
}

/*
E 3
 * evaluate a conditional expression
 */

BOOLEAN cond(p)
NODE *p;
{
D 3
	if (p == NIL) {
		return(TRUE);
	}
	eval(p);
	return(pop(BOOLEAN));
E 3
I 3
    if (p == NIL) {
	return(TRUE);
    }
    eval(p);
    return(pop(BOOLEAN));
E 3
}

/*
 * Return the address corresponding to a given tree.
 */

ADDRESS lval(p)
NODE *p;
{
D 3
	eval(p);
	return(pop(ADDRESS));
E 3
I 3
    eval(p);
    return(pop(ADDRESS));
E 3
}
E 1
