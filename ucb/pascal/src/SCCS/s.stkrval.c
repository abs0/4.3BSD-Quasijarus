h11694
s 00003/00001/00434
d D 5.2 86/11/12 10:29:15 mckusick 13 12
c replace `even' and `leven' with explicit rounding
e
s 00007/00003/00428
d D 5.1 85/06/05 14:58:40 dist 12 11
c Add copyright
e
s 00012/00012/00419
d D 2.2 85/03/20 15:07:32 ralph 11 10
c changes from donn@utah-cs for common header file for pcc
e
s 00000/00000/00431
d D 2.1 84/02/08 20:50:50 aoki 10 9
c synchronize to version 2
e
s 00000/00000/00431
d D 1.9 83/09/19 07:01:07 thien 9 8
c Restoring to unlinted version
e
s 00093/00082/00338
d D 1.8 83/08/19 05:02:56 thien 8 7
c The changes were made to allow successful linting
e
s 00006/00006/00414
d D 1.7 83/02/09 17:37:08 peter 7 6
c save in the namelist the padded length of the string.
c and make this code look like the code in rvalue().
e
s 00037/00023/00383
d D 1.6 83/01/22 00:48:45 mckusick 6 5
c break out stackRV() as a general function
e
s 00023/00004/00383
d D 1.5 83/01/17 13:56:36 mckusick 5 4
c put in explicit scalar converts (sconv's) to make less code-generator dependent.
e
s 00015/00010/00372
d D 1.4 81/03/08 19:28:30 mckusic 4 3
c merge in onyx changes
e
s 00002/00000/00380
d D 1.3 80/10/03 01:09:49 peter 3 2
c Implement formal functions and procedures
e
s 00003/00002/00377
d D 1.2 80/09/24 18:57:26 peter 2 1
c constant sets don't have to (and can't) have their widths cast
e
s 00379/00000/00000
d D 1.1 80/08/27 19:56:36 peter 1 0
c date and time created 80/08/27 19:56:36 by peter
e
u
U
t
T
I 1
D 12
/* Copyright (c) 1979 Regents of the University of California */
E 12
I 12
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 12

I 8
#ifndef lint
E 8
D 4
static	char sccsid[] = "%Z%%M% %I% %G%";
E 4
I 4
D 12
static char sccsid[] = "%Z%%M% %I% %G%";
I 8
#endif
E 12
I 12
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 12
E 8
E 4

#include "whoami.h"
#include "0.h"
#include "tree.h"
#include "opcode.h"
#include "objfmt.h"
I 13
#include "align.h"
E 13
#ifdef PC
D 11
#   include "pcops.h"
E 11
I 11
#   include <pcc.h>
E 11
#endif PC
I 8
#include "tree_ty.h"
E 8

/*
 * stkrval Rvalue - an expression, and coerce it to be a stack quantity.
 *
 * Contype is the type that the caller would prefer, nand is important
 * if constant sets or constant strings are involved, the latter
 * because of string padding.
 */
/*
 * for the obj version, this is a copy of rvalue hacked to use fancy new
 * push-onto-stack-and-convert opcodes.
 * for the pc version, i just call rvalue and convert if i have to,
 * based on the return type of rvalue.
 */
struct nl *
stkrval(r, contype , required )
D 8
	register int *r;
E 8
I 8
	register struct tnode *r;
E 8
	struct nl *contype;
	long	required;
{
	register struct nl *p;
	register struct nl *q;
	register char *cp, *cp1;
	register int c, w;
D 8
	int **pt;
E 8
I 8
	struct tnode *pt;
E 8
	long l;
D 8
	double f;
E 8
I 8
	union
	{
		double pdouble;
		long   plong[2];
	}f;
E 8

D 8
	if (r == NIL)
		return (NIL);
E 8
I 8
	if (r == TR_NIL)
		return (NLNIL);
E 8
	if (nowexp(r))
D 8
		return (NIL);
E 8
I 8
		return (NLNIL);
E 8
	/*
	 * The root of the tree tells us what sort of expression we have.
	 */
D 8
	switch (r[0]) {
E 8
I 8
	switch (r->tag) {
E 8

	/*
	 * The constant nil
	 */
	case T_NIL:
#		ifdef OBJ
D 8
		    put(2, O_CON14, 0);
E 8
I 8
		    (void) put(2, O_CON14, 0);
E 8
#		endif OBJ
#		ifdef PC
D 8
		    putleaf( P2ICON , 0 , 0 , P2INT , 0 );
E 8
I 8
D 11
		    putleaf( P2ICON , 0 , 0 , P2INT , (char *) 0 );
E 11
I 11
		    putleaf( PCC_ICON , 0 , 0 , PCCT_INT , (char *) 0 );
E 11
E 8
#		endif PC
		return (nl+TNIL);

	case T_FCALL:
	case T_VAR:
D 8
		p = lookup(r[2]);
		if (p == NIL || p->class == BADUSE)
			return (NIL);
E 8
I 8
		p = lookup(r->var_node.cptr);
		if (p == NLNIL || p->class == BADUSE)
			return (NLNIL);
E 8
		switch (p->class) {
		case VAR:
			/*
D 4
			  if a variable is
E 4
I 4
			 * if a variable is
E 4
			 * qualified then get
			 * the rvalue by a
			 * stklval and an ind.
			 */
D 8
			if (r[3] != NIL)
E 8
I 8
			if (r->var_node.qual != TR_NIL)
E 8
				goto ind;
			q = p->type;
D 8
			if (q == NIL)
				return (NIL);
E 8
I 8
			if (q == NLNIL)
				return (NLNIL);
E 8
			if (classify(q) == TSTR)
				return(stklval(r, NOFLAGS));
#			ifdef OBJ
D 6
			    w = width(q);
			    switch (w) {
			    case 8:
D 4
				    put(2, O_RV8 | bn << 8+INDX, p->value[0]);
E 4
I 4
				    put(2, O_RV8 | bn << 8+INDX,
					(int)p->value[0]);
E 4
				    return(q);
			    case 4:
D 4
				    put(2, O_RV4 | bn << 8+INDX, p->value[0]);
E 4
I 4
				    put(2, O_RV4 | bn << 8+INDX,
					(int)p->value[0]);
E 4
				    return(q);
			    case 2:
D 4
				    put(2, O_RV24 | bn << 8+INDX, p->value[0]);
E 4
I 4
				    put(2, O_RV24 | bn << 8+INDX,
					(int)p->value[0]);
E 4
				    return(q);
			    case 1:
D 4
				    put(2, O_RV14 | bn << 8+INDX, p->value[0]);
E 4
I 4
				    put(2, O_RV14 | bn << 8+INDX,
					(int)p->value[0]);
E 4
				    return(q);
			    default:
D 4
				    put(3, O_RV | bn << 8+INDX, p->value[0], w);
E 4
I 4
				    put(3, O_RV | bn << 8+INDX,
					(int)p->value[0], w);
E 4
				    return(q);
			     }
E 6
I 6
				return (stackRV(p));
E 6
#			endif OBJ
#			ifdef PC
D 5
			     return rvalue( r , contype , required );
E 5
I 5
D 8
			    q = rvalue( r , contype , required );
E 8
I 8
			    q = rvalue( r , contype , (int) required );
E 8
			    if (isa(q, "sbci")) {
D 11
				sconv(p2type(q),P2INT);
E 11
I 11
				sconv(p2type(q),PCCT_INT);
E 11
			    }
			    return q;
E 5
#			endif PC

		case WITHPTR:
		case REF:
			/*
			 * A stklval for these
			 * is actually what one
			 * might consider a rvalue.
			 */
ind:
			q = stklval(r, NOFLAGS);
D 8
			if (q == NIL)
				return (NIL);
E 8
I 8
			if (q == NLNIL)
				return (NLNIL);
E 8
			if (classify(q) == TSTR)
				return(q);
#			ifdef OBJ
			    w = width(q);
			    switch (w) {
				    case 8:
D 8
					    put(1, O_IND8);
E 8
I 8
					    (void) put(1, O_IND8);
E 8
					    return(q);
				    case 4:
D 8
					    put(1, O_IND4);
E 8
I 8
					    (void) put(1, O_IND4);
E 8
					    return(q);
				    case 2:
D 8
					    put(1, O_IND24);
E 8
I 8
					    (void) put(1, O_IND24);
E 8
					    return(q);
				    case 1:
D 8
					    put(1, O_IND14);
E 8
I 8
					    (void) put(1, O_IND14);
E 8
					    return(q);
				    default:
D 8
					    put(2, O_IND, w);
E 8
I 8
					    (void) put(2, O_IND, w);
E 8
					    return(q);
			    }
#			endif OBJ
#			ifdef PC
			    if ( required == RREQ ) {
D 11
				putop( P2UNARY P2MUL , p2type( q ) );
E 11
I 11
				putop( PCCOM_UNARY PCC_MUL , p2type( q ) );
E 11
I 5
				if (isa(q,"sbci")) {
D 11
				    sconv(p2type(q),P2INT);
E 11
I 11
				    sconv(p2type(q),PCCT_INT);
E 11
				}
E 5
			    }
			    return q;
#			endif PC

		case CONST:
D 8
			if (r[3] != NIL) {
				error("%s is a constant and cannot be qualified", r[2]);
				return (NIL);
E 8
I 8
			if (r->var_node.qual != TR_NIL) {
				error("%s is a constant and cannot be qualified", r->var_node.cptr);
				return (NLNIL);
E 8
			}
			q = p->type;
D 8
			if (q == NIL)
				return (NIL);
E 8
I 8
			if (q == NLNIL)
				return (NLNIL);
E 8
			if (q == nl+TSTR) {
				/*
				 * Find the size of the string
				 * constant if needed.
				 */
D 8
				cp = p->ptr[0];
E 8
I 8
				cp = (char *) p->ptr[0];
E 8
cstrng:
				cp1 = cp;
				for (c = 0; *cp++; c++)
					continue;
D 7
				w = 0;
E 7
I 7
				w = c;
E 7
				if (contype != NIL && !opt('s')) {
					if (width(contype) < c && classify(contype) == TSTR) {
						error("Constant string too long");
D 8
						return (NIL);
E 8
I 8
						return (NLNIL);
E 8
					}
D 7
					w = width(contype) - c;
E 7
I 7
					w = width(contype);
E 7
				}
#				ifdef OBJ
D 7
				    put(2, O_LVCON, lenstr(cp1, w));
				    putstr(cp1, w);
E 7
I 7
D 8
				    put(2, O_LVCON, lenstr(cp1, w - c));
E 8
I 8
				    (void) put(2, O_LVCON, lenstr(cp1, w - c));
E 8
				    putstr(cp1, w - c);
E 7
#				endif OBJ
#				ifdef PC
D 7
				    putCONG( cp1 , c + w , LREQ );
E 7
I 7
				    putCONG( cp1 , w , LREQ );
E 7
#				endif PC
				/*
				 * Define the string temporarily
				 * so later people can know its
				 * width.
				 * cleaned out by stat.
				 */
D 7
				q = defnl(0, STR, 0, c);
E 7
I 7
D 8
				q = defnl(0, STR, 0, w);
E 8
I 8
				q = defnl((char *) 0, STR, NLNIL, w);
E 8
E 7
				q->type = q;
				return (q);
			}
			if (q == nl+T1CHAR) {
#			    ifdef OBJ
D 4
				put(2, O_CONC4, p->value[0]);
E 4
I 4
D 8
				put(2, O_CONC4, (int)p->value[0]);
E 8
I 8
				(void) put(2, O_CONC4, (int)p->value[0]);
E 8
E 4
#			    endif OBJ
#			    ifdef PC
D 5
				putleaf( P2ICON , p -> value[0] , 0 , P2CHAR , 0 );
E 5
I 5
D 8
				putleaf(P2ICON, p -> value[0], 0, P2INT, 0);
E 8
I 8
D 11
				putleaf(P2ICON, p -> value[0], 0, P2INT, 
E 11
I 11
				putleaf(PCC_ICON, p -> value[0], 0, PCCT_INT, 
E 11
						(char *) 0);
E 8
E 5
#			    endif PC
			    return(q);
			}
			/*
			 * Every other kind of constant here
			 */
#			ifdef OBJ
			    switch (width(q)) {
			    case 8:
#ifndef DEBUG
D 8
				    put(2, O_CON8, p->real);
E 8
I 8
				    (void) put(2, O_CON8, p->real);
E 8
				    return(q);
#else
				    if (hp21mx) {
D 8
					    f = p->real;
					    conv(&f);
					    l = f.plong;
					    put(2, O_CON4, l);
E 8
I 8
					    f.pdouble = p->real;
					    conv((int *) (&f.pdouble));
					    l = f.plong[1];
					    (void) put(2, O_CON4, l);
E 8
				    } else
D 8
					    put(2, O_CON8, p->real);
E 8
I 8
					    (void) put(2, O_CON8, p->real);
E 8
				    return(q);
#endif
			    case 4:
D 8
				    put(2, O_CON4, p->range[0]);
E 8
I 8
				    (void) put(2, O_CON4, p->range[0]);
E 8
				    return(q);
			    case 2:
D 8
				    put(2, O_CON24, (short)p->range[0]);
E 8
I 8
				    (void) put(2, O_CON24, (short)p->range[0]);
E 8
				    return(q);
			    case 1:
D 4
				    put(2, O_CON14, (short)p->range[0]);
E 4
I 4
D 8
				    put(2, O_CON14, p->value[0]);
E 8
I 8
				    (void) put(2, O_CON14, p->value[0]);
E 8
E 4
				    return(q);
			    default:
				    panic("stkrval");
			    }
#			endif OBJ
#			ifdef PC
D 5
			    return rvalue( r , contype , required );
E 5
I 5
D 8
			    q = rvalue( r , contype , required );
E 8
I 8
			    q = rvalue( r , contype , (int) required );
E 8
			    if (isa(q,"sbci")) {
D 11
				sconv(p2type(q),P2INT);
E 11
I 11
				sconv(p2type(q),PCCT_INT);
E 11
			    }
			    return q;
E 5
#			endif PC

		case FUNC:
I 3
		case FFUNC:
E 3
			/*
			 * Function call
			 */
D 8
			pt = (int **)r[3];
			if (pt != NIL) {
				switch (pt[1][0]) {
E 8
I 8
			pt = r->var_node.qual;
			if (pt != TR_NIL) {
				switch (pt->list_node.list->tag) {
E 8
				case T_PTR:
				case T_ARGL:
				case T_ARY:
				case T_FIELD:
					error("Can't qualify a function result value");
D 8
					return (NIL);
E 8
I 8
					return (NLNIL);
E 8
				}
			}
#			ifdef OBJ
			    q = p->type;
			    if (classify(q) == TSTR) {
				    c = width(q);
D 8
				    put(2, O_LVCON, even(c+1));
E 8
I 8
D 13
				    (void) put(2, O_LVCON, even(c+1));
E 13
I 13
				    (void) put(2, O_LVCON,
					roundup(c+1, (long) A_SHORT));
E 13
E 8
				    putstr("", c);
D 4
				    put(1, O_SDUP4);
E 4
I 4
D 8
				    put(1, PTR_DUP);
E 8
I 8
				    (void) put(1, PTR_DUP);
E 8
E 4
				    p = funccod(r);
D 8
				    put(2, O_AS, c);
E 8
I 8
				    (void) put(2, O_AS, c);
E 8
				    return(p);
			    }
			    p = funccod(r);
			    if (width(p) <= 2)
D 8
				    put(1, O_STOI);
E 8
I 8
				    (void) put(1, O_STOI);
E 8
#			endif OBJ
#			ifdef PC
			    p = pcfunccod( r );
I 5
			    if (isa(p,"sbci")) {
D 11
				sconv(p2type(p),P2INT);
E 11
I 11
				sconv(p2type(p),PCCT_INT);
E 11
			    }
E 5
#			endif PC
			return (p);

		case TYPE:
			error("Type names (e.g. %s) allowed only in declarations", p->symbol);
D 8
			return (NIL);
E 8
I 8
			return (NLNIL);
E 8

		case PROC:
I 3
		case FPROC:
E 3
			error("Procedure %s found where expression required", p->symbol);
D 8
			return (NIL);
E 8
I 8
			return (NLNIL);
E 8
		default:
			panic("stkrvid");
		}
D 2
	case T_CSET:
E 2
	case T_PLUS:
	case T_MINUS:
	case T_NOT:
	case T_AND:
	case T_OR:
	case T_DIVD:
	case T_MULT:
	case T_SUB:
	case T_ADD:
	case T_MOD:
	case T_DIV:
	case T_EQ:
	case T_NE:
	case T_GE:
	case T_LE:
	case T_GT:
	case T_LT:
	case T_IN:
D 8
		p = rvalue(r, contype , required );
E 8
I 8
		p = rvalue(r, contype , (int) required );
E 8
#		ifdef OBJ
		    if (width(p) <= 2)
D 8
			    put(1, O_STOI);
E 8
I 8
			    (void) put(1, O_STOI);
E 8
#		endif OBJ
I 5
#		ifdef PC
		    if (isa(p,"sbci")) {
D 11
			sconv(p2type(p),P2INT);
E 11
I 11
			sconv(p2type(p),PCCT_INT);
E 11
		    }
#		endif PC
E 5
		return (p);
D 2

E 2
I 2
	case T_CSET:
D 8
		p = rvalue(r, contype , required );
E 8
I 8
		p = rvalue(r, contype , (int) required );
E 8
		return (p);
E 2
	default:
D 8
		if (r[2] == NIL)
			return (NIL);
		switch (r[0]) {
E 8
I 8
		if (r->const_node.cptr == (char *) NIL)
			return (NLNIL);
		switch (r->tag) {
E 8
		default:
			panic("stkrval3");

		/*
		 * An octal number
		 */
		case T_BINT:
D 8
			f = a8tol(r[2]);
E 8
I 8
			f.pdouble = a8tol(r->const_node.cptr);
E 8
			goto conint;
	
		/*
		 * A decimal number
		 */
		case T_INT:
D 8
			f = atof(r[2]);
E 8
I 8
			f.pdouble = atof(r->const_node.cptr);
E 8
conint:
D 8
			if (f > MAXINT || f < MININT) {
E 8
I 8
			if (f.pdouble > MAXINT || f.pdouble < MININT) {
E 8
				error("Constant too large for this implementation");
D 8
				return (NIL);
E 8
I 8
				return (NLNIL);
E 8
			}
D 8
			l = f;
E 8
I 8
			l = f.pdouble;
E 8
			if (bytes(l, l) <= 2) {
#			    ifdef OBJ
D 8
				put(2, O_CON24, (short)l);
E 8
I 8
				(void) put(2, O_CON24, (short)l);
E 8
#			    endif OBJ
#			    ifdef PC
D 8
				putleaf( P2ICON , (short) l , 0 , P2INT , 0 );
E 8
I 8
D 11
				putleaf( P2ICON , (short) l , 0 , P2INT , 
E 11
I 11
				putleaf( PCC_ICON , (short) l , 0 , PCCT_INT , 
E 11
						(char *) 0 );
E 8
#			    endif PC
				return(nl+T4INT);
			}
#			ifdef OBJ
D 8
			    put(2, O_CON4, l); 
E 8
I 8
			    (void) put(2, O_CON4, l); 
E 8
#			endif OBJ
#			ifdef PC
D 8
			    putleaf( P2ICON , l , 0 , P2INT , 0 );
E 8
I 8
D 11
			    putleaf( P2ICON , (int) l , 0 , P2INT , (char *) 0 );
E 11
I 11
			    putleaf( PCC_ICON , (int) l , 0 , PCCT_INT , (char *) 0 );
E 11
E 8
#			endif PC
			return (nl+T4INT);
	
		/*
		 * A floating point number
		 */
		case T_FINT:
#		   	ifdef OBJ
D 8
			    put(2, O_CON8, atof(r[2]));
E 8
I 8
			    (void) put(2, O_CON8, atof(r->const_node.cptr));
E 8
#			endif OBJ
#			ifdef PC
D 8
			    putCON8( atof( r[2] ) );
E 8
I 8
			    putCON8( atof( r->const_node.cptr ) );
E 8
#			endif PC
			return (nl+TDOUBLE);
	
		/*
		 * Constant strings.  Note that constant characters
		 * are constant strings of length one; there is
		 * no constant string of length one.
		 */
		case T_STRNG:
D 8
			cp = r[2];
E 8
I 8
			cp = r->const_node.cptr;
E 8
			if (cp[1] == 0) {
#				ifdef OBJ
D 8
				    put(2, O_CONC4, cp[0]);
E 8
I 8
				    (void) put(2, O_CONC4, cp[0]);
E 8
#				endif OBJ
#				ifdef PC
D 5
				    putleaf( P2ICON , cp[0] , 0 , P2CHAR , 0 );
E 5
I 5
D 8
				    putleaf( P2ICON , cp[0] , 0 , P2INT , 0 );
E 8
I 8
D 11
				    putleaf( P2ICON , cp[0] , 0 , P2INT , 
E 11
I 11
				    putleaf( PCC_ICON , cp[0] , 0 , PCCT_INT , 
E 11
						(char *) 0 );
E 8
E 5
#				endif PC
				return(nl+T1CHAR);
			}
			goto cstrng;
		}
	
	}
}
I 6

#ifdef OBJ
/*
 * push a value onto the interpreter stack, longword aligned.
 */
D 8
stackRV(p)
E 8
I 8
struct nl 
*stackRV(p)
E 8
	struct nl *p;
{
	struct nl *q;
	int w, bn;

	q = p->type;
D 8
	if (q == NIL)
		return (NIL);
E 8
I 8
	if (q == NLNIL)
		return (NLNIL);
E 8
	bn = BLOCKNO(p->nl_block);
	w = width(q);
	switch (w) {
	case 8:
D 8
		put(2, O_RV8 | bn << 8+INDX, (int)p->value[0]);
E 8
I 8
		(void) put(2, O_RV8 | bn << 8+INDX, (int)p->value[0]);
E 8
		break;
	case 4:
D 8
		put(2, O_RV4 | bn << 8+INDX, (int)p->value[0]);
E 8
I 8
		(void) put(2, O_RV4 | bn << 8+INDX, (int)p->value[0]);
E 8
		break;
	case 2:
D 8
		put(2, O_RV24 | bn << 8+INDX, (int)p->value[0]);
E 8
I 8
		(void) put(2, O_RV24 | bn << 8+INDX, (int)p->value[0]);
E 8
		break;
	case 1:
D 8
		put(2, O_RV14 | bn << 8+INDX, (int)p->value[0]);
E 8
I 8
		(void) put(2, O_RV14 | bn << 8+INDX, (int)p->value[0]);
E 8
		break;
	default:
D 8
		put(3, O_RV | bn << 8+INDX, (int)p->value[0], w);
E 8
I 8
		(void) put(3, O_RV | bn << 8+INDX, (int)p->value[0], w);
E 8
		break;
	}
	return (q);
}
#endif OBJ
E 6
E 1
