h45346
s 00008/00003/00250
d D 5.1 85/06/05 14:17:49 dist 15 14
c Add copyright
e
s 00000/00000/00253
d D 2.1 84/02/08 20:52:50 aoki 14 13
c synchronize to version 2
e
s 00000/00000/00253
d D 1.12 83/10/11 06:34:27 thien 13 11
c fixes for lint
e
s 00000/00000/00253
d R 1.12 83/10/09 18:18:09 thien 12 11
c 
e
s 00000/00000/00253
d D 1.11 83/09/19 06:58:39 thien 11 10
c Restoring to unlinted version
e
s 00059/00054/00194
d D 1.10 83/08/19 04:57:46 thien 10 9
c The changes were made to allow successful linting
e
s 00009/00002/00239
d D 1.9 82/12/06 18:28:35 peter 9 8
c ord() shouldn't be allowed on pointers.
e
s 00008/00004/00233
d D 1.8 82/04/27 15:44:11 mckusick 8 7
c be sure to get range values for SUCC and PRED
e
s 00019/00016/00218
d D 1.7 81/03/08 19:25:41 mckusic 7 6
c merge in onyx changes
e
s 00001/00001/00233
d D 1.6 81/02/19 11:20:36 peter 6 5
c since stkrval pushs longs in spite of returned type, use ITOD.
e
s 00013/00012/00221
d D 1.5 81/01/10 17:00:13 mckusic 5 4
c convert to "fp", "ap" type display; fix SUCC and PRED
e
s 00004/00001/00229
d D 1.4 81/01/06 17:15:35 mckusic 4 3
c modify to allow use of px written in `C' and the use of libpc
e
s 00004/00015/00226
d D 1.3 80/10/19 18:32:44 peter 3 2
c guess that [] is intset if no other context information.
e
s 00001/00001/00240
d D 1.2 80/10/03 01:08:09 peter 2 1
c Implement formal functions and procedures
e
s 00241/00000/00000
d D 1.1 80/08/27 19:55:07 peter 1 0
c date and time created 80/08/27 19:55:07 by peter
e
u
U
t
T
I 1
D 15
/* Copyright (c) 1979 Regents of the University of California */
E 15
I 15
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 15

I 10
#ifndef lint
E 10
D 7
static	char sccsid[] = "%Z%%M% %I% %G%";
E 7
I 7
D 15
static char sccsid[] = "%Z%%M% %I% %G%";
I 10
#endif
E 15
I 15
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 15
E 10
E 7

#include "whoami.h"
#ifdef OBJ
    /*
     *	the rest of the file
     */
#include "0.h"
#include "tree.h"
#include "opcode.h"
I 10
#include "tree_ty.h"
E 10

D 3
bool cardempty = FALSE;

E 3
/*
 * Funccod generates code for
 * built in function calls and calls
 * call to generate calls to user
 * defined functions and procedures.
 */
D 10
funccod(r)
	int *r;
E 10
I 10
struct nl
*funccod(r)
	struct tnode *r;
E 10
{
	struct nl *p;
	register struct nl *p1;
I 8
	struct nl *tempnlp;
E 8
D 10
	register int *al;
E 10
I 10
	register struct tnode *al;
E 10
	register op;
D 10
	int argc, *argv;
	int tr[2], tr2[4];
E 10
I 10
	int argc;
	struct tnode *argv, tr, tr2;
E 10

	/*
	 * Verify that the given name
	 * is defined and the name of
	 * a function.
	 */
D 10
	p = lookup(r[2]);
	if (p == NIL) {
		rvlist(r[3]);
		return (NIL);
E 10
I 10
	p = lookup(r->pcall_node.proc_id);
	if (p == NLNIL) {
		rvlist(r->pcall_node.arg);
		return (NLNIL);
E 10
	}
D 2
	if (p->class != FUNC) {
E 2
I 2
	if (p->class != FUNC && p->class != FFUNC) {
E 2
		error("%s is not a function", p->symbol);
D 10
		rvlist(r[3]);
		return (NIL);
E 10
I 10
		rvlist(r->pcall_node.arg);
		return (NLNIL);
E 10
	}
D 10
	argv = r[3];
E 10
I 10
	argv = r->pcall_node.arg;
E 10
	/*
	 * Call handles user defined
	 * procedures and functions
	 */
	if (bn != 0)
		return (call(p, argv, FUNC, bn));
	/*
	 * Count the arguments
	 */
	argc = 0;
D 10
	for (al = argv; al != NIL; al = al[2])
E 10
I 10
	for (al = argv; al != TR_NIL; al = al->list_node.next)
E 10
		argc++;
	/*
	 * Built-in functions have
	 * their interpreter opcode
	 * associated with them.
	 */
	op = p->value[0] &~ NSTAND;
	if (opt('s') && (p->value[0] & NSTAND)) {
		standard();
		error("%s is a nonstandard function", p->symbol);
	}
	switch (op) {
		/*
		 * Parameterless functions
		 */
		case O_CLCK:
		case O_SCLCK:
		case O_WCLCK:
		case O_ARGC:
			if (argc != 0) {
				error("%s takes no arguments", p->symbol);
				rvlist(argv);
D 10
				return (NIL);
E 10
I 10
				return (NLNIL);
E 10
			}
D 7
			put1(op);
E 7
I 7
D 10
			put(1, op);
E 10
I 10
			(void) put(1, op);
E 10
E 7
			return (nl+T4INT);
		case O_EOF:
		case O_EOLN:
			if (argc == 0) {
D 10
				argv = tr;
				tr[1] = tr2;
				tr2[0] = T_VAR;
				tr2[2] = input->symbol;
				tr2[1] = tr2[3] = NIL;
E 10
I 10
				argv = (&tr);
				tr.list_node.list = (&tr2);
				tr2.tag = T_VAR;
				tr2.var_node.cptr = input->symbol;
				tr2.var_node.line_no = NIL;
				tr2.var_node.qual = TR_NIL;
E 10
				argc = 1;
			} else if (argc != 1) {
				error("%s takes either zero or one argument", p->symbol);
				rvlist(argv);
D 10
				return (NIL);
E 10
I 10
				return (NLNIL);
E 10
			}
		}
	/*
	 * All other functions take
	 * exactly one argument.
	 */
	if (argc != 1) {
		error("%s takes exactly one argument", p->symbol);
		rvlist(argv);
D 10
		return (NIL);
E 10
I 10
		return (NLNIL);
E 10
	}
	/*
	 * Evaluate the argmument
	 */
D 4
	p1 = stkrval((int *) argv[1], NLNIL , RREQ );
E 4
I 4
	if (op == O_EOF || op == O_EOLN)
D 10
		p1 = stklval((int *) argv[1], NLNIL , LREQ );
E 10
I 10
		p1 = stklval(argv->list_node.list, NIL );
E 10
	else
D 10
		p1 = stkrval((int *) argv[1], NLNIL , RREQ );
E 4
	if (p1 == NIL)
		return (NIL);
E 10
I 10
		p1 = stkrval(argv->list_node.list, NLNIL , (long) RREQ );
	if (p1 == NLNIL)
		return (NLNIL);
E 10
	switch (op) {
I 10
		case 0:
			error("%s is an unimplemented 6000-3.4 extension", p->symbol);
		default:
			panic("func1");
E 10
		case O_EXP:
		case O_SIN:
		case O_COS:
		case O_ATAN:
		case O_LN:
		case O_SQRT:
		case O_RANDOM:
		case O_EXPO:
		case O_UNDEF:
			if (isa(p1, "i"))
D 6
				convert(p1, nl+TDOUBLE);
E 6
I 6
				convert( nl+T4INT , nl+TDOUBLE);
E 6
			else if (isnta(p1, "d")) {
				error("%s's argument must be integer or real, not %s", p->symbol, nameof(p1));
D 10
				return (NIL);
E 10
I 10
				return (NLNIL);
E 10
			}
D 7
			put1(op);
E 7
I 7
D 10
			put(1, op);
E 10
I 10
			(void) put(1, op);
E 10
E 7
			if (op == O_UNDEF)
				return (nl+TBOOL);
			else if (op == O_EXPO)
				return (nl+T4INT);
			else
				return (nl+TDOUBLE);
		case O_SEED:
			if (isnta(p1, "i")) {
				error("seed's argument must be an integer, not %s", nameof(p1));
D 10
				return (NIL);
E 10
I 10
				return (NLNIL);
E 10
			}
D 7
			put1(op);
E 7
I 7
D 10
			put(1, op);
E 10
I 10
			(void) put(1, op);
E 10
E 7
			return (nl+T4INT);
		case O_ROUND:
		case O_TRUNC:
			if (isnta(p1, "d"))  {
				error("%s's argument must be a real, not %s", p->symbol, nameof(p1));
D 10
				return (NIL);
E 10
I 10
				return (NLNIL);
E 10
			}
D 7
			put1(op);
E 7
I 7
D 10
			put(1, op);
E 10
I 10
			(void) put(1, op);
E 10
E 7
			return (nl+T4INT);
		case O_ABS2:
		case O_SQR2:
			if (isa(p1, "d")) {
D 7
				put1(op + O_ABS8-O_ABS2);
E 7
I 7
D 10
				put(1, op + O_ABS8-O_ABS2);
E 10
I 10
				(void) put(1, op + O_ABS8-O_ABS2);
E 10
E 7
				return (nl+TDOUBLE);
			}
			if (isa(p1, "i")) {
D 7
				put1(op + (width(p1) >> 2));
E 7
I 7
D 10
				put(1, op + (width(p1) >> 2));
E 10
I 10
				(void) put(1, op + (width(p1) >> 2));
E 10
E 7
				return (nl+T4INT);
			}
			error("%s's argument must be an integer or real, not %s", p->symbol, nameof(p1));
D 10
			return (NIL);
E 10
I 10
			return (NLNIL);
E 10
		case O_ORD2:
D 9
			if (isa(p1, "bcis") || classify(p1) == TPTR) {
E 9
I 9
			if (isa(p1, "bcis")) {
E 9
				return (nl+T4INT);
			}
D 9
			error("ord's argument must be of scalar type or a pointer, not %s", nameof(p1));
E 9
I 9
			if (classify(p1) == TPTR) {
			    if (!opt('s')) {
				return (nl+T4INT);
			    }
			    standard();
			}
			error("ord's argument must be of scalar type, not %s",
				nameof(p1));
E 9
D 10
			return (NIL);
E 10
I 10
			return (NLNIL);
E 10
		case O_SUCC2:
		case O_PRED2:
D 5
			if (isa(p1, "bcs")) {
				put1(op);
				return (p1);
E 5
I 5
			if (isa(p1, "d")) {
				error("%s is forbidden for reals", p->symbol);
D 10
				return (NIL);
E 10
I 10
				return (NLNIL);
E 10
E 5
			}
I 5
			if ( isnta( p1 , "bcsi" ) ) {
				error("%s's argument must be of scalar type, not %s", p->symbol, nameof(p1));
				return NIL;
			}
I 8
			tempnlp = p1 -> class == TYPE ? p1 -> type : p1;
E 8
E 5
			if (isa(p1, "i")) {
D 7
				if (width(p1) <= 2)
E 7
I 7
				if (width(p1) <= 2) {
E 7
D 5
					op += O_PRED24-O_PRED2;
E 5
I 5
					op += O_PRED24 - O_PRED2;
E 5
D 7
				else
E 7
I 7
D 8
					put(3, op, (int)p1->range[0],
						(int)p1->range[1]);
E 8
I 8
D 10
					put(3, op, (int)tempnlp->range[0],
E 10
I 10
					(void) put(3, op, (int)tempnlp->range[0],
E 10
						(int)tempnlp->range[1]);
E 8
				} else {
E 7
					op++;
D 5
				put1(op);
				return (nl+T4INT);
E 5
I 5
D 7
				put(3, op, p1->range[0], p1->range[1]);
E 7
I 7
D 8
					put(3, op, p1->range[0], p1->range[1]);
E 8
I 8
D 10
					put(3, op, tempnlp->range[0],
E 10
I 10
					(void) put(3, op, tempnlp->range[0],
E 10
						tempnlp->range[1]);
E 8
				}
E 7
				return nl + T4INT;
			} else {
D 7
				put(3, op, p1->range[0], p1->range[1]);
E 7
I 7
D 8
				put(3, op, (int)p1->range[0], (int)p1->range[1]);
E 8
I 8
D 10
				put(3, op, (int)tempnlp->range[0],
E 10
I 10
				(void) put(3, op, (int)tempnlp->range[0],
E 10
					(int)tempnlp->range[1]);
E 8
E 7
				return p1;
E 5
			}
D 5
			if (isa(p1, "id")) {
				error("%s is forbidden for reals", p->symbol);
				return (NIL);
			}
			error("%s's argument must be of scalar type, not %s", p->symbol, nameof(p1));
			return (NIL);
E 5
		case O_ODD2:
			if (isnta(p1, "i")) {
				error("odd's argument must be an integer, not %s", nameof(p1));
D 10
				return (NIL);
E 10
I 10
				return (NLNIL);
E 10
			}
D 7
			put1(op + (width(p1) >> 2));
E 7
I 7
D 10
			put(1, op + (width(p1) >> 2));
E 10
I 10
			(void) put(1, op + (width(p1) >> 2));
E 10
E 7
			return (nl+TBOOL);
		case O_CHR2:
			if (isnta(p1, "i")) {
				error("chr's argument must be an integer, not %s", nameof(p1));
D 10
				return (NIL);
E 10
I 10
				return (NLNIL);
E 10
			}
D 7
			put1(op + (width(p1) >> 2));
E 7
I 7
D 10
			put(1, op + (width(p1) >> 2));
E 10
I 10
			(void) put(1, op + (width(p1) >> 2));
E 10
E 7
			return (nl+TCHAR);
		case O_CARD:
D 3
			if ( p1 != nl + TSET ) {
			    if (isnta(p1, "t")) {
				error("Argument to card must be a set, not %s", nameof(p1));
				return (NIL);
			    }
			    put2(O_CARD, width(p1));
			} else {
			    if ( !cardempty ) {
				warning();
				error("Cardinality of the empty set is 0." );
				cardempty = TRUE;
			    }
			    put(1, O_CON1, 0);
E 3
I 3
			if (isnta(p1, "t")) {
			    error("Argument to card must be a set, not %s", nameof(p1));
D 10
			    return (NIL);
E 10
I 10
			    return (NLNIL);
E 10
E 3
			}
I 3
D 7
			put2(O_CARD, width(p1));
E 7
I 7
D 10
			put(2, O_CARD, width(p1));
E 10
I 10
			(void) put(2, O_CARD, width(p1));
E 10
E 7
E 3
			return (nl+T2INT);
		case O_EOLN:
			if (!text(p1)) {
				error("Argument to eoln must be a text file, not %s", nameof(p1));
D 10
				return (NIL);
E 10
I 10
				return (NLNIL);
E 10
			}
D 7
			put1(op);
E 7
I 7
D 10
			put(1, op);
E 10
I 10
			(void) put(1, op);
E 10
E 7
			return (nl+TBOOL);
		case O_EOF:
			if (p1->class != FILET) {
				error("Argument to eof must be file, not %s", nameof(p1));
D 10
				return (NIL);
E 10
I 10
				return (NLNIL);
E 10
			}
D 7
			put1(op);
E 7
I 7
D 10
			put(1, op);
E 10
I 10
			(void) put(1, op);
E 10
E 7
			return (nl+TBOOL);
D 10
		case 0:
			error("%s is an unimplemented 6000-3.4 extension", p->symbol);
		default:
			panic("func1");
E 10
	}
}
#endif OBJ
E 1
