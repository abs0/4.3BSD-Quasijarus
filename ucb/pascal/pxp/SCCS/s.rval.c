h48120
s 00010/00003/00167
d D 5.1 85/06/05 15:51:50 dist 4 3
c Add copyright
e
s 00032/00002/00138
d D 2.2 84/04/02 13:50:27 peter 3 2
c fix incorrect parenthesization of signed expressions;
c choose not to parenthesize nested not operators;
c add comments describing other parenthesization choices.
e
s 00000/00000/00140
d D 2.1 84/02/08 20:23:03 aoki 2 1
c synchronizing at version 2
e
s 00140/00000/00000
d D 1.1 81/03/02 21:28:57 peter 1 0
c date and time created 81/03/02 21:28:57 by peter
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

extern	char *opnames[];

#define alph(c)		((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
/*
 * Rvalue reformats an expression.
 * Par is a flag indicating that the expression
 * should be parenthesized if it is non-atomic.
 */
rvalue(r, par)
	register int *r;
	int par;
{
	register int *al;
	register char *opname;

	if (r == NIL) {
		ppid("{expr}");
		return;
	}
	if (r[0] <= T_IN)
		opname = opnames[r[0]];
	switch (r[0]) {
		case T_BINT:
		case T_INT:
		case T_FINT:
			ppnumb(r[2]);
			if (r[0] == T_BINT)
				ppsep("b");
			return;
		case T_NIL:
			ppkw("nil");
			return;
		case T_FCALL:
			funccod(r);
			return;
		case T_VAR:
			lvalue(r);
			return;
		case T_CSET:
			cset(r);
			return;
		case T_STRNG:
			ppstr(r[2]);
			return;
	}
	if (par)
		ppbra("(");
	switch (r[0]) {
		default:
			panic("rval");
		case T_PLUS:
		case T_MINUS:
I 3
			/*
			 * if child is relational (bogus) or adding operator,
			 * parenthesize child.
			 * this has the unaesthetic property that
			 * --i prints as -(-i), but is needed to catch
			 * -(a+b) which must print as -(a+b), not as -a+b.
			 * otherwise child has higher precedence
			 * and need not be parenthesized.
			 */
E 3
			ppop(r[0] == T_PLUS ? "+" : "-");
			al = r[2];
D 3
			rvalue(r[2], prec(al) > prec(r) || full);
E 3
I 3
			rvalue(r[2], prec(al) <= prec(r) || full);
E 3
			break;
		case T_NOT:
I 3
			/*
			 * if child is of lesser precedence
			 * (i.e. not another not operator)
			 * parenthesize it.
			 * nested not operators need not be parenthesized
			 * because it's a prefix operator.
			 */
E 3
			ppkw(opname);
			ppspac();
D 3
			rvalue(r[2], 1);
E 3
I 3
			al = r[2];
			rvalue(r[2], prec(al) < prec(r) || full);
E 3
			break;
		case T_EQ:
		case T_NE:
		case T_GE:
		case T_LE:
		case T_GT:
		case T_LT:
I 3
			/*
			 * make the aesthetic choice to
			 * fully parenthesize relational expressions,
			 * in spite of left to right associativity.
			 * note: there are no operators with lower precedence.
			 */
E 3
			al = r[2];
			rvalue(al, prec(al) <= prec(r) || full);
			goto rest;
		case T_AND:
		case T_OR:
		case T_MULT:
		case T_ADD:
		case T_SUB:
		case T_DIVD:
		case T_MOD:
		case T_DIV:
		case T_IN:
I 3
			/*
			 * need not parenthesize left child
			 * if it has equal precedence,
			 * due to left to right associativity.
			 * right child needs to be parenthesized
			 * if it has equal (or lesser) precedence.
			 */
E 3
			al = r[2];
			rvalue(al, prec(al) < prec(r) || full);
rest:
			ppspac();
			if (alph(opname[0]))
				ppkw(opname);
			else
				ppop(opname);
			ppspac();
			al = r[3];
			rvalue(al, prec(al) <= prec(r) || full);
			break;
	}
	if (par)
		ppket(")");
}

/*
 * Prec returns the precedence of an operator,
 * with larger numbers indicating stronger binding.
 * This is used to determine when parenthesization
 * is needed on subexpressions.
 */
prec(r)
	register int *r;
{

	if (r == NIL)
		return;
	switch (r[0]) {
		case T_NOT:
			return (3);
		case T_MULT:
		case T_DIVD:
		case T_DIV:
		case T_MOD:
		case T_AND:
			return (2);
		case T_ADD:
		case T_SUB:
		case T_OR:
		case T_PLUS:
		case T_MINUS:
			return (1);
		default:
			return (0);
	}
}
E 1
