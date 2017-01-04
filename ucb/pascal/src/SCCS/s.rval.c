h17963
s 00038/00000/01210
d D 5.2 87/04/07 15:47:03 mckusick 26 25
c code generator work around from CCI
e
s 00007/00003/01203
d D 5.1 85/06/05 14:49:47 dist 25 24
c Add copyright
e
s 00079/00079/01127
d D 2.3 85/03/20 15:05:22 ralph 24 23
c changes from donn@utah-cs for common header file for pcc
e
s 00046/00024/01160
d D 2.2 84/04/02 13:43:54 peter 23 22
c determine type of empty sets:  get type of right-hand-side
c and use that type to determine the type of the left-hand-side
c before generating any code.  this way if the right-hand-side is the empty set
c the type of the left-hand-side can override it.  if the right-hand-side isn't
c the empty set then its type will become the type for an empty set on the left.
e
s 00000/00000/01184
d D 2.1 84/02/08 20:45:49 aoki 22 21
c synchronize to version 2
e
s 00001/00001/01183
d D 1.20 84/02/05 13:57:28 peter 21 20
c replaced missing `#' for `#ifndef lint'.
e
s 00013/00026/01171
d D 1.19 84/02/04 20:03:54 mckusick 20 18
i 19
c merge lint by thien
e
s 00276/00248/00927
d D 1.16.1.1 84/02/04 18:57:41 mckusick 19 16
c lint (by thien)
e
s 00009/00028/01149
d D 1.18 83/11/11 16:44:55 mckusick 18 17
c must examine both sides of a set expression to determine its type
c cannot special case intset as it is just one of several sets of subranges
e
s 00002/00000/01175
d D 1.17 83/10/30 17:15:49 peter 17 16
c shouldn't be able to compare different pointer types.
e
s 00001/00000/01174
d D 1.16 83/02/28 17:16:26 peter 16 15
c clean up temporary allocation, moving everything relevant to
c tmps.c and (new) tmps.h.  correctly emit LBRAC lines.  allocate registers
c from high to low.  put in data structures for multiple types of registers.
e
s 00008/00003/01166
d D 1.15 83/02/01 22:02:11 peter 15 14
c fix unary minus so it works for both integers and reals.
e
s 00044/00048/01125
d D 1.14 83/01/17 13:57:43 mckusick 14 13
c put in explicit scalar converts (sconv's) to make less code-generator dependent.
e
s 00012/00000/01161
d D 1.13 82/01/16 14:19:53 peter 13 12
c be more paranoid about errors from recursive calls to rvalue().
e
s 00011/00009/01150
d D 1.12 81/06/01 15:39:25 peter 12 11
c add storage classes to namelist, and use them.
e
s 00009/00000/01150
d D 1.11 81/03/30 11:38:47 peter 11 10
c < and > are non-standard on sets.
e
s 00003/00012/01147
d D 1.10 81/03/11 23:43:18 mckusic 10 9
c centralize temporary allocation in tmps.c
e
s 00001/00001/01158
d D 1.9 81/03/09 14:27:46 mckusic 9 8
c fix constant string length calc for putCONG
e
s 00023/00015/01136
d D 1.8 81/03/08 19:27:35 mckusic 8 7
c merge in onyx changes
e
s 00002/00001/01149
d D 1.7 81/01/02 13:07:42 peter 7 6
c fix bracketing around scalar convert for comparison
e
s 00001/00001/01149
d D 1.6 80/12/12 15:54:42 peter 6 5
c output set pairs in same order for px and pc so can use libpc
e
s 00010/00005/01140
d D 1.5 80/10/28 21:10:59 peter 5 4
c add warnings for extensions to language
e
s 00063/00053/01082
d D 1.4 80/10/19 18:33:08 peter 4 3
c guess that [] is intset if no other context information.
e
s 00001/00001/01134
d D 1.3 80/10/16 21:59:15 peter 3 2
c undefined type is spelled P2UNDEF not P2UNDEFINED.
e
s 00002/00000/01133
d D 1.2 80/10/03 01:09:33 peter 2 1
c Implement formal functions and procedures
e
s 01133/00000/00000
d D 1.1 80/08/27 19:56:18 peter 1 0
c date and time created 80/08/27 19:56:18 by peter
e
u
U
f b 
t
T
I 1
D 25
/* Copyright (c) 1979 Regents of the University of California */
E 25
I 25
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 25

I 19
D 21
ifndef lint
E 21
I 21
#ifndef lint
E 21
E 19
D 8
static	char sccsid[] = "%Z%%M% %I% %G%";
E 8
I 8
D 25
static char sccsid[] = "%Z%%M% %I% %G%";
I 19
#endif
E 25
I 25
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 25
E 19
E 8

#include "whoami.h"
#include "0.h"
#include "tree.h"
#include "opcode.h"
#include "objfmt.h"
#ifdef PC
#   include	"pc.h"
D 24
#   include "pcops.h"
E 24
I 24
#   include <pcc.h>
E 24
#endif PC
I 16
#include "tmps.h"
I 19
#include "tree_ty.h"
E 19
E 16

extern	char *opnames[];
D 4
bool	inempty = FALSE;
E 4

I 5
    /* line number of the last record comparison warning */
short reccompline = 0;
I 11
    /* line number of the last non-standard set comparison */
short nssetline = 0;
E 11

E 5
#ifdef PC
    char	*relts[] =  {
				"_RELEQ" , "_RELNE" ,
				"_RELTLT" , "_RELTGT" ,
				"_RELTLE" , "_RELTGE"
			    };
    char	*relss[] =  {
				"_RELEQ" , "_RELNE" ,
				"_RELSLT" , "_RELSGT" ,
				"_RELSLE" , "_RELSGE"
			    };
    long	relops[] =  {	
D 24
				P2EQ , P2NE ,
				P2LT , P2GT ,
				P2LE , P2GE 
E 24
I 24
				PCC_EQ , PCC_NE ,
				PCC_LT , PCC_GT ,
				PCC_LE , PCC_GE 
E 24
			    };
D 24
    long	mathop[] =  {	P2MUL , P2PLUS , P2MINUS };
E 24
I 24
    long	mathop[] =  {	PCC_MUL , PCC_PLUS , PCC_MINUS };
E 24
    char	*setop[] =  {	"_MULT" , "_ADDT" , "_SUBT" };
#endif PC
/*
 * Rvalue - an expression.
 *
 * Contype is the type that the caller would prefer, nand is important
D 23
 * if constant sets or constant strings are involved, the latter
 * because of string padding.
E 23
I 23
 * if constant strings are involved, because of string padding.
E 23
 * required is a flag whether an lvalue or an rvalue is required.
 * only VARs and structured things can have gt their lvalue this way.
 */
I 19
/*ARGSUSED*/
E 19
struct nl *
rvalue(r, contype , required )
D 19
	int *r;
E 19
I 19
	struct tnode *r;
E 19
	struct nl *contype;
	int	required;
{
	register struct nl *p, *p1;
	register struct nl *q;
D 19
	int c, c1, *rt, w, g;
E 19
I 19
	int c, c1, w;
#ifdef OBJ
	int g;
#endif
	struct tnode *rt;
E 19
	char *cp, *cp1, *opname;
	long l;
D 19
	double f;
E 19
I 19
	union
	{
	    long plong[2];
	    double pdouble;
	}f;
E 19
	extern int	flagwas;
	struct csetstr	csetd;
#	ifdef PC
	    struct nl	*rettype;
	    long	ctype;
D 12
	    long	tempoff;
E 12
I 12
	    struct nl	*tempnlp;
E 12
#	endif PC

D 19
	if (r == NIL)
		return (NIL);
E 19
I 19
	if (r == TR_NIL)
		return (NLNIL);
E 19
	if (nowexp(r))
D 19
		return (NIL);
E 19
I 19
		return (NLNIL);
E 19
	/*
	 * Pick up the name of the operation
	 * for future error messages.
	 */
D 19
	if (r[0] <= T_IN)
		opname = opnames[r[0]];
E 19
I 19
	if (r->tag <= T_IN)
		opname = opnames[r->tag];
E 19

	/*
	 * The root of the tree tells us what sort of expression we have.
	 */
D 19
	switch (r[0]) {
E 19
I 19
	switch (r->tag) {
E 19

	/*
	 * The constant nil
	 */
	case T_NIL:
#		ifdef OBJ
D 19
		    put(2, O_CON2, 0);
E 19
I 19
		    (void) put(2, O_CON2, 0);
E 19
#		endif OBJ
#		ifdef PC
D 3
		    putleaf( P2ICON , 0 , 0 , P2PTR|P2UNDEFINED , 0 );
E 3
I 3
D 19
		    putleaf( P2ICON , 0 , 0 , P2PTR|P2UNDEF , 0 );
E 19
I 19
D 24
		    putleaf( P2ICON , 0 , 0 , P2PTR|P2UNDEF , (char *) 0 );
E 24
I 24
		    putleaf( PCC_ICON , 0 , 0 , PCCTM_PTR|PCCT_UNDEF , (char *) 0 );
E 24
E 19
E 3
#		endif PC
		return (nl+TNIL);

	/*
	 * Function call with arguments.
	 */
	case T_FCALL:
#	    ifdef OBJ
		return (funccod(r));
#	    endif OBJ
#	    ifdef PC
		return (pcfunccod( r ));
#	    endif PC

	case T_VAR:
D 19
		p = lookup(r[2]);
		if (p == NIL || p->class == BADUSE)
			return (NIL);
E 19
I 19
		p = lookup(r->var_node.cptr);
		if (p == NLNIL || p->class == BADUSE)
			return (NLNIL);
E 19
		switch (p->class) {
		    case VAR:
			    /*
			     * If a variable is
			     * qualified then get
			     * the rvalue by a
			     * lvalue and an ind.
			     */
D 19
			    if (r[3] != NIL)
E 19
I 19
			    if (r->var_node.qual != TR_NIL)
E 19
				    goto ind;
			    q = p->type;
			    if (q == NIL)
D 19
				    return (NIL);
E 19
I 19
				    return (NLNIL);
E 19
#			    ifdef OBJ
				w = width(q);
				switch (w) {
				    case 8:
D 8
					put(2, O_RV8 | bn << 8+INDX, p->value[0]);
E 8
I 8
D 19
					put(2, O_RV8 | bn << 8+INDX,
E 19
I 19
					(void) put(2, O_RV8 | bn << 8+INDX,
E 19
						(int)p->value[0]);
E 8
					break;
				    case 4:
D 8
					put(2, O_RV4 | bn << 8+INDX, p->value[0]);
E 8
I 8
D 19
					put(2, O_RV4 | bn << 8+INDX,
E 19
I 19
					(void) put(2, O_RV4 | bn << 8+INDX,
E 19
						(int)p->value[0]);
E 8
					break;
				    case 2:
D 8
					put(2, O_RV2 | bn << 8+INDX, p->value[0]);
E 8
I 8
D 19
					put(2, O_RV2 | bn << 8+INDX,
E 19
I 19
					(void) put(2, O_RV2 | bn << 8+INDX,
E 19
						(int)p->value[0]);
E 8
					break;
				    case 1:
D 8
					put(2, O_RV1 | bn << 8+INDX, p->value[0]);
E 8
I 8
D 19
					put(2, O_RV1 | bn << 8+INDX,
E 19
I 19
					(void) put(2, O_RV1 | bn << 8+INDX,
E 19
						(int)p->value[0]);
E 8
					break;
				    default:
D 8
					put(3, O_RV | bn << 8+INDX, p->value[0], w);
E 8
I 8
D 19
					put(3, O_RV | bn << 8+INDX,
E 19
I 19
					(void) put(3, O_RV | bn << 8+INDX,
E 19
						(int)p->value[0], w);
E 8
				}
#			   endif OBJ
#			   ifdef PC
				if ( required == RREQ ) {
D 12
				    putRV( p -> symbol , bn , p -> value[0]
					    , p2type( q ) );
E 12
I 12
				    putRV( p -> symbol , bn , p -> value[0] ,
					    p -> extra_flags , p2type( q ) );
E 12
				} else {
D 12
				    putLV( p -> symbol , bn , p -> value[0]
					    , p2type( q ) );
E 12
I 12
				    putLV( p -> symbol , bn , p -> value[0] ,
					    p -> extra_flags , p2type( q ) );
E 12
				}
#			   endif PC
			   return (q);

		    case WITHPTR:
		    case REF:
			    /*
			     * A lvalue for these
			     * is actually what one
			     * might consider a rvalue.
			     */
ind:
			    q = lvalue(r, NOFLAGS , LREQ );
			    if (q == NIL)
D 19
				    return (NIL);
E 19
I 19
				    return (NLNIL);
E 19
#			    ifdef OBJ
				w = width(q);
				switch (w) {
				    case 8:
D 19
					    put(1, O_IND8);
E 19
I 19
					    (void) put(1, O_IND8);
E 19
					    break;
				    case 4:
D 19
					    put(1, O_IND4);
E 19
I 19
					    (void) put(1, O_IND4);
E 19
					    break;
				    case 2:
D 19
					    put(1, O_IND2);
E 19
I 19
					    (void) put(1, O_IND2);
E 19
					    break;
				    case 1:
D 19
					    put(1, O_IND1);
E 19
I 19
					    (void) put(1, O_IND1);
E 19
					    break;
				    default:
D 19
					    put(2, O_IND, w);
E 19
I 19
					    (void) put(2, O_IND, w);
E 19
				}
#			    endif OBJ
#			    ifdef PC
				if ( required == RREQ ) {
D 24
				    putop( P2UNARY P2MUL , p2type( q ) );
E 24
I 24
				    putop( PCCOM_UNARY PCC_MUL , p2type( q ) );
E 24
				}
#			    endif PC
			    return (q);

		    case CONST:
D 19
			    if (r[3] != NIL) {
				error("%s is a constant and cannot be qualified", r[2]);
				return (NIL);
E 19
I 19
			    if (r->var_node.qual != TR_NIL) {
				error("%s is a constant and cannot be qualified", r->var_node.cptr);
				return (NLNIL);
E 19
			    }
			    q = p->type;
D 19
			    if (q == NIL)
				    return (NIL);
E 19
I 19
			    if (q == NLNIL)
				    return (NLNIL);
E 19
			    if (q == nl+TSTR) {
				    /*
				     * Find the size of the string
				     * constant if needed.
				     */
D 19
				    cp = p->ptr[0];
E 19
I 19
				    cp = (char *) p->ptr[0];
E 19
cstrng:
				    cp1 = cp;
				    for (c = 0; *cp++; c++)
					    continue;
I 8
				    w = c;
E 8
				    if (contype != NIL && !opt('s')) {
					    if (width(contype) < c && classify(contype) == TSTR) {
						    error("Constant string too long");
D 19
						    return (NIL);
E 19
I 19
						    return (NLNIL);
E 19
					    }
D 8
					    c = width(contype);
E 8
I 8
					    w = width(contype);
E 8
				    }
#				    ifdef OBJ
D 8
					put( 2 + (sizeof(char *)/sizeof(short))
						, O_CONG, c, cp1);
E 8
I 8
D 19
					put(2, O_CONG, w);
E 19
I 19
					(void) put(2, O_CONG, w);
E 19
					putstr(cp1, w - c);
E 8
#				    endif OBJ
#				    ifdef PC
D 9
					putCONG( cp1 , c , required );
E 9
I 9
					putCONG( cp1 , w , required );
E 9
#				    endif PC
				    /*
				     * Define the string temporarily
				     * so later people can know its
				     * width.
				     * cleaned out by stat.
				     */
D 8
				    q = defnl(0, STR, 0, c);
E 8
I 8
D 19
				    q = defnl(0, STR, 0, w);
E 19
I 19
				    q = defnl((char *) 0, STR, NLNIL, w);
E 19
E 8
				    q->type = q;
				    return (q);
			    }
			    if (q == nl+T1CHAR) {
#				    ifdef OBJ
D 8
					put(2, O_CONC, p->value[0]);
E 8
I 8
D 19
					put(2, O_CONC, (int)p->value[0]);
E 19
I 19
					(void) put(2, O_CONC, (int)p->value[0]);
E 19
E 8
#				    endif OBJ
#				    ifdef PC
D 24
					putleaf( P2ICON , p -> value[0] , 0
D 19
						, P2CHAR , 0 );
E 19
I 19
						, P2CHAR , (char *) 0 );
E 24
I 24
					putleaf( PCC_ICON , p -> value[0] , 0
						, PCCT_CHAR , (char *) 0 );
E 24
E 19
#				    endif PC
				    return (q);
			    }
			    /*
			     * Every other kind of constant here
			     */
			    switch (width(q)) {
			    case 8:
#ifndef DEBUG
#				    ifdef OBJ
D 19
					put(2, O_CON8, p->real);
E 19
I 19
					(void) put(2, O_CON8, p->real);
E 19
#				    endif OBJ
#				    ifdef PC
					putCON8( p -> real );
#				    endif PC
#else
				    if (hp21mx) {
D 19
					    f = p->real;
					    conv(&f);
					    l = f.plong;
					    put(2, O_CON4, l);
E 19
I 19
					    f.pdouble = p->real;
					    conv((int *) (&f.pdouble));
					    l = f.plong[1];
					    (void) put(2, O_CON4, l);
E 19
				    } else
#					    ifdef OBJ
D 19
						put(2, O_CON8, p->real);
E 19
I 19
						(void) put(2, O_CON8, p->real);
E 19
#					    endif OBJ
#					    ifdef PC
						putCON8( p -> real );
#					    endif PC
#endif
				    break;
			    case 4:
#				    ifdef OBJ
D 19
					put(2, O_CON4, p->range[0]);
E 19
I 19
					(void) put(2, O_CON4, p->range[0]);
E 19
#				    endif OBJ
#				    ifdef PC
D 19
					putleaf( P2ICON , p -> range[0] , 0
						, P2INT , 0 );
E 19
I 19
D 24
					putleaf( P2ICON , (int) p->range[0] , 0
						, P2INT , (char *) 0 );
E 24
I 24
					putleaf( PCC_ICON , (int) p->range[0] , 0
						, PCCT_INT , (char *) 0 );
E 24
E 19
#				    endif PC
				    break;
			    case 2:
#				    ifdef OBJ
D 8
					put(2, O_CON2, ( short ) p->range[0]);
E 8
I 8
D 19
					put(2, O_CON2, (short)p->range[0]);
E 19
I 19
					(void) put(2, O_CON2, (short)p->range[0]);
E 19
E 8
#				    endif OBJ
#				    ifdef PC
D 14
					    /*
					     * make short constants ints
					     */
E 14
D 24
					putleaf( P2ICON , (short) p -> range[0]
D 14
						, 0 , P2INT , 0 );
E 14
I 14
D 19
						, 0 , P2SHORT , 0 );
E 19
I 19
						, 0 , P2SHORT , (char *) 0 );
E 24
I 24
					putleaf( PCC_ICON , (short) p -> range[0]
						, 0 , PCCT_SHORT , (char *) 0 );
E 24
E 19
E 14
#				    endif PC
				    break;
			    case 1:
#				    ifdef OBJ
D 19
					put(2, O_CON1, p->value[0]);
E 19
I 19
					(void) put(2, O_CON1, p->value[0]);
E 19
#				    endif OBJ
#				    ifdef PC
D 14
					    /*
					     * make char constants ints
					     */
E 14
D 24
					putleaf( P2ICON , p -> value[0] , 0
D 14
						, P2INT , 0 );
E 14
I 14
D 19
						, P2CHAR , 0 );
E 19
I 19
						, P2CHAR , (char *) 0 );
E 24
I 24
					putleaf( PCC_ICON , p -> value[0] , 0
						, PCCT_CHAR , (char *) 0 );
E 24
E 19
E 14
#				    endif PC
				    break;
			    default:
				    panic("rval");
			    }
			    return (q);

		    case FUNC:
I 2
		    case FFUNC:
E 2
			    /*
			     * Function call with no arguments.
			     */
D 19
			    if (r[3]) {
E 19
I 19
			    if (r->var_node.qual != TR_NIL) {
E 19
				    error("Can't qualify a function result value");
D 19
				    return (NIL);
E 19
I 19
				    return (NLNIL);
E 19
			    }
#			    ifdef OBJ
D 19
				return (funccod((int *) r));
E 19
I 19
				return (funccod(r));
E 19
#			    endif OBJ
#			    ifdef PC
				return (pcfunccod( r ));
#			    endif PC

		    case TYPE:
			    error("Type names (e.g. %s) allowed only in declarations", p->symbol);
D 19
			    return (NIL);
E 19
I 19
			    return (NLNIL);
E 19

		    case PROC:
I 2
		    case FPROC:
E 2
			    error("Procedure %s found where expression required", p->symbol);
D 19
			    return (NIL);
E 19
I 19
			    return (NLNIL);
E 19
		    default:
			    panic("rvid");
		}
	/*
	 * Constant sets
	 */
	case T_CSET:
#		ifdef OBJ
		    if ( precset( r , contype , &csetd ) ) {
			if ( csetd.csettype == NIL ) {
D 19
			    return NIL;
E 19
I 19
			    return (NLNIL);
E 19
			}
			postcset( r , &csetd );
		    } else {
D 8
			put( 2, O_PUSH, -width(csetd.csettype));
E 8
I 8
D 19
			put( 2, O_PUSH, -lwidth(csetd.csettype));
E 19
I 19
			(void) put( 2, O_PUSH, -lwidth(csetd.csettype));
E 19
E 8
			postcset( r , &csetd );
			setran( ( csetd.csettype ) -> type );
D 19
			put( 2, O_CON24, set.uprbp);
			put( 2, O_CON24, set.lwrb);
D 6
			put( 2, O_CTTOT, 5 + csetd.singcnt + 2 * csetd.paircnt);
E 6
I 6
D 8
			put( 2, O_CTTOT, 4 + csetd.singcnt + 2 * csetd.paircnt);
E 8
I 8
			put( 2, O_CTTOT,
E 19
I 19
			(void) put( 2, O_CON24, set.uprbp);
			(void) put( 2, O_CON24, set.lwrb);
			(void) put( 2, O_CTTOT,
E 19
				(int)(4 + csetd.singcnt + 2 * csetd.paircnt));
E 8
E 6
		    }
		    return csetd.csettype;
#		endif OBJ
#		ifdef PC
		    if ( precset( r , contype , &csetd ) ) {
			if ( csetd.csettype == NIL ) {
D 19
			    return NIL;
E 19
I 19
			    return (NLNIL);
E 19
			}
			postcset( r , &csetd );
		    } else {
D 24
			putleaf( P2ICON , 0 , 0
				, ADDTYPE( P2FTN | P2INT , P2PTR )
E 24
I 24
			putleaf( PCC_ICON , 0 , 0
				, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 24
				, "_CTTOT" );
			/*
			 *	allocate a temporary and use it
			 */
D 10
			sizes[ cbn ].om_off -= lwidth( csetd.csettype );
			tempoff = sizes[ cbn ].om_off;
			putlbracket( ftnno , -tempoff );
			if ( tempoff < sizes[ cbn ].om_max ) {
			    sizes[ cbn ].om_max = tempoff;
			}
E 10
I 10
D 12
			tempoff = tmpalloc(lwidth(csetd.csettype),
E 12
I 12
			tempnlp = tmpalloc(lwidth(csetd.csettype),
E 12
				csetd.csettype, NOREG);
E 10
D 12
			putLV( 0 , cbn , tempoff , P2PTR|P2STRTY );
E 12
I 12
D 19
			putLV( 0 , cbn , tempnlp -> value[ NL_OFFS ] ,
E 19
I 19
			putLV( (char *) 0 , cbn , tempnlp -> value[ NL_OFFS ] ,
E 19
D 24
				tempnlp -> extra_flags , P2PTR|P2STRTY );
E 24
I 24
				tempnlp -> extra_flags , PCCTM_PTR|PCCT_STRTY );
E 24
E 12
			setran( ( csetd.csettype ) -> type );
D 19
			putleaf( P2ICON , set.lwrb , 0 , P2INT , 0 );
E 19
I 19
D 24
			putleaf( P2ICON , set.lwrb , 0 , P2INT , (char *) 0 );
E 19
			putop( P2LISTOP , P2INT );
D 19
			putleaf( P2ICON , set.uprbp , 0 , P2INT , 0 );
E 19
I 19
			putleaf( P2ICON , set.uprbp , 0 , P2INT , (char *) 0 );
E 19
			putop( P2LISTOP , P2INT );
E 24
I 24
			putleaf( PCC_ICON , set.lwrb , 0 , PCCT_INT , (char *) 0 );
			putop( PCC_CM , PCCT_INT );
			putleaf( PCC_ICON , set.uprbp , 0 , PCCT_INT , (char *) 0 );
			putop( PCC_CM , PCCT_INT );
E 24
			postcset( r , &csetd );
D 24
			putop( P2CALL , P2INT );
E 24
I 24
			putop( PCC_CALL , PCCT_INT );
E 24
		    }
		    return csetd.csettype;
#		endif PC

	/*
	 * Unary plus and minus
	 */
	case T_PLUS:
	case T_MINUS:
D 19
		q = rvalue(r[2], NIL , RREQ );
		if (q == NIL)
			return (NIL);
E 19
I 19
		q = rvalue(r->un_expr.expr, NLNIL , RREQ );
		if (q == NLNIL)
			return (NLNIL);
E 19
		if (isnta(q, "id")) {
			error("Operand of %s must be integer or real, not %s", opname, nameof(q));
D 19
			return (NIL);
E 19
I 19
			return (NLNIL);
E 19
		}
D 19
		if (r[0] == T_MINUS) {
E 19
I 19
		if (r->tag == T_MINUS) {
E 19
#		    ifdef OBJ
D 19
			put(1, O_NEG2 + (width(q) >> 2));
E 19
I 19
			(void) put(1, O_NEG2 + (width(q) >> 2));
E 19
I 15
			return (isa(q, "d") ? q : nl+T4INT);
E 15
#		    endif OBJ
#		    ifdef PC
D 14
			putop( P2UNARY P2MINUS , p2type( q ) );
E 14
I 14
D 15
			sconv(p2type(q), P2INT);
			putop( P2UNARY P2MINUS , P2INT );
E 15
I 15
			if (isa(q, "i")) {
D 24
			    sconv(p2type(q), P2INT);
			    putop( P2UNARY P2MINUS, P2INT);
E 24
I 24
			    sconv(p2type(q), PCCT_INT);
			    putop( PCCOM_UNARY PCC_MINUS, PCCT_INT);
E 24
			    return nl+T4INT;
			}
D 24
			putop( P2UNARY P2MINUS, P2DOUBLE);
E 24
I 24
			putop( PCCOM_UNARY PCC_MINUS, PCCT_DOUBLE);
E 24
			return nl+TDOUBLE;
E 15
E 14
#		    endif PC
D 15
		    return (isa(q, "d") ? q : nl+T4INT);
E 15
		}
		return (q);

	case T_NOT:
D 19
		q = rvalue(r[2], NIL , RREQ );
		if (q == NIL)
			return (NIL);
E 19
I 19
		q = rvalue(r->un_expr.expr, NLNIL , RREQ );
		if (q == NLNIL)
			return (NLNIL);
E 19
		if (isnta(q, "b")) {
			error("not must operate on a Boolean, not %s", nameof(q));
D 19
			return (NIL);
E 19
I 19
			return (NLNIL);
E 19
		}
#		ifdef OBJ
D 19
		    put(1, O_NOT);
E 19
I 19
		    (void) put(1, O_NOT);
E 19
#		endif OBJ
#		ifdef PC
D 14
		    putop( P2NOT , P2INT );
E 14
I 14
D 24
		    sconv(p2type(q), P2INT);
		    putop( P2NOT , P2INT);
		    sconv(P2INT, p2type(q));
E 24
I 24
		    sconv(p2type(q), PCCT_INT);
		    putop( PCC_NOT , PCCT_INT);
		    sconv(PCCT_INT, p2type(q));
E 24
E 14
#		endif PC
		return (nl+T1BOOL);

	case T_AND:
	case T_OR:
D 19
		p = rvalue(r[2], NIL , RREQ );
E 19
I 19
		p = rvalue(r->expr_node.lhs, NLNIL , RREQ );
E 19
I 14
#		ifdef PC
D 24
		    sconv(p2type(p),P2INT);
E 24
I 24
		    sconv(p2type(p),PCCT_INT);
E 24
#		endif PC
E 14
D 19
		p1 = rvalue(r[3], NIL , RREQ );
E 19
I 19
		p1 = rvalue(r->expr_node.rhs, NLNIL , RREQ );
E 19
I 14
#		ifdef PC
D 24
		    sconv(p2type(p1),P2INT);
E 24
I 24
		    sconv(p2type(p1),PCCT_INT);
E 24
#		endif PC
E 14
D 19
		if (p == NIL || p1 == NIL)
			return (NIL);
E 19
I 19
		if (p == NLNIL || p1 == NLNIL)
			return (NLNIL);
E 19
		if (isnta(p, "b")) {
			error("Left operand of %s must be Boolean, not %s", opname, nameof(p));
D 19
			return (NIL);
E 19
I 19
			return (NLNIL);
E 19
		}
		if (isnta(p1, "b")) {
			error("Right operand of %s must be Boolean, not %s", opname, nameof(p1));
D 19
			return (NIL);
E 19
I 19
			return (NLNIL);
E 19
		}
#		ifdef OBJ
D 19
		    put(1, r[0] == T_AND ? O_AND : O_OR);
E 19
I 19
		    (void) put(1, r->tag == T_AND ? O_AND : O_OR);
E 19
#		endif OBJ
#		ifdef PC
			/*
			 * note the use of & and | rather than && and ||
			 * to force evaluation of all the expressions.
			 */
D 19
		    putop( r[ 0 ] == T_AND ? P2AND : P2OR , P2INT );
E 19
I 19
D 24
		    putop( r->tag == T_AND ? P2AND : P2OR , P2INT );
E 19
I 14
		    sconv(P2INT, p2type(p));
E 24
I 24
		    putop( r->tag == T_AND ? PCC_AND : PCC_OR , PCCT_INT );
		    sconv(PCCT_INT, p2type(p));
E 24
E 14
#		endif PC
		return (nl+T1BOOL);

	case T_DIVD:
#		ifdef OBJ
D 19
		    p = rvalue(r[2], NIL , RREQ );
		    p1 = rvalue(r[3], NIL , RREQ );
E 19
I 19
		    p = rvalue(r->expr_node.lhs, NLNIL , RREQ );
		    p1 = rvalue(r->expr_node.rhs, NLNIL , RREQ );
E 19
#		endif OBJ
#		ifdef PC
			/*
			 *	force these to be doubles for the divide
			 */
D 19
		    p = rvalue( r[ 2 ] , NIL , RREQ );
E 19
I 19
		    p = rvalue( r->expr_node.lhs , NLNIL , RREQ );
E 19
D 14
		    if ( isnta( p , "d" ) ) {
			putop( P2SCONV , P2DOUBLE );
		    }
E 14
I 14
D 24
		    sconv(p2type(p), P2DOUBLE);
E 24
I 24
		    sconv(p2type(p), PCCT_DOUBLE);
E 24
E 14
D 19
		    p1 = rvalue( r[ 3 ] , NIL , RREQ );
E 19
I 19
		    p1 = rvalue( r->expr_node.rhs , NLNIL , RREQ );
E 19
D 14
		    if ( isnta( p1 , "d" ) ) {
			putop( P2SCONV , P2DOUBLE );
		    }
E 14
I 14
D 24
		    sconv(p2type(p1), P2DOUBLE);
E 24
I 24
		    sconv(p2type(p1), PCCT_DOUBLE);
E 24
E 14
#		endif PC
D 19
		if (p == NIL || p1 == NIL)
			return (NIL);
E 19
I 19
		if (p == NLNIL || p1 == NLNIL)
			return (NLNIL);
E 19
		if (isnta(p, "id")) {
			error("Left operand of / must be integer or real, not %s", nameof(p));
D 19
			return (NIL);
E 19
I 19
			return (NLNIL);
E 19
		}
		if (isnta(p1, "id")) {
			error("Right operand of / must be integer or real, not %s", nameof(p1));
D 19
			return (NIL);
E 19
I 19
			return (NLNIL);
E 19
		}
#		ifdef OBJ
D 19
		    return gen(NIL, r[0], width(p), width(p1));
E 19
I 19
		    return gen(NIL, r->tag, width(p), width(p1));
E 19
#		endif OBJ
#		ifdef PC
D 24
		    putop( P2DIV , P2DOUBLE );
E 24
I 24
		    putop( PCC_DIV , PCCT_DOUBLE );
E 24
		    return nl + TDOUBLE;
#		endif PC

	case T_MULT:
	case T_ADD:
	case T_SUB:
#		ifdef OBJ
		    /*
D 4
		     * If the context hasn't told us
		     * the type and a constant set is
		     * present on the left we need to infer
		     * the type from the right if possible
		     * before generating left side code.
E 4
I 4
D 23
		     * If the context hasn't told us the type
		     * and a constant set is present
		     * we need to infer the type 
		     * before generating code.
E 23
I 23
		     * get the type of the right hand side.
		     * if it turns out to be a set,
		     * use that type when getting
		     * the type of the left hand side.
		     * and then use the type of the left hand side
		     * when generating code.
		     * this will correctly decide the type of any
		     * empty sets in the tree, since if the empty set 
		     * is on the left hand side it will inherit
		     * the type of the right hand side,
		     * and if it's on the right hand side, its type (intset)
		     * will be overridden by the type of the left hand side.
		     * this is an awful lot of tree traversing, 
		     * but it works.
E 23
E 4
		     */
D 4
		    if (contype == NIL && (rt = r[2]) != NIL && rt[1] == SAWCON) {
E 4
I 4
D 20
		    if ( contype == NIL ) {
E 20
I 20
D 23
		    if ( contype == NLNIL ) {
E 20
E 4
			    codeoff();
D 4
			    contype = rvalue(r[3], NIL , RREQ );
E 4
I 4
D 19
			    contype = rvalue( r[3] , NIL , RREQ );
E 19
I 19
			    contype = rvalue( r->expr_node.rhs , NLNIL , RREQ );
E 19
E 4
			    codeon();
D 4
			    if (contype == NIL)
				    return (NIL);
E 4
I 4
D 18
D 19
			    if ( contype == lookup( intset ) -> type ) {
E 19
I 19
D 20
			    if ( contype == lookup((char *) intset ) -> type ) {
E 19
				codeoff();
D 19
				contype = rvalue( r[2] , NIL , RREQ );
E 19
I 19
				contype = rvalue( r->expr_node.lhs , NLNIL ,
									RREQ );
E 20
E 19
				codeon();
			    }
E 18
E 4
		    }
D 4
		    p = rvalue(r[2], contype , RREQ );
		    p1 = rvalue(r[3], p , RREQ );
		    if (p == NIL || p1 == NIL)
			    return (NIL);
E 4
I 4
D 20
		    if ( contype == NIL ) {
E 20
I 20
		    if ( contype == NLNIL ) {
E 23
I 23
		    codeoff();
		    p1 = rvalue( r->expr_node.rhs , NLNIL , RREQ );
		    codeon();
		    if ( p1 == NLNIL ) {
E 23
E 20
D 19
			return NIL;
E 19
I 19
			return NLNIL;
E 19
		    }
I 23
		    if (isa(p1, "t")) {
			codeoff();
			contype = rvalue(r->expr_node.lhs, p1, RREQ);
			codeon();
			if (contype == NLNIL) {
			    return NLNIL;
			}
		    }
E 23
D 19
		    p = rvalue( r[2] , contype , RREQ );
		    p1 = rvalue( r[3] , p , RREQ );
E 19
I 19
		    p = rvalue( r->expr_node.lhs , contype , RREQ );
		    p1 = rvalue( r->expr_node.rhs , p , RREQ );
E 19
D 20
		    if ( p == NIL || p1 == NIL )
E 20
I 20
		    if ( p == NLNIL || p1 == NLNIL )
E 20
D 19
			    return NIL;
E 19
I 19
			    return NLNIL;
E 19
E 4
		    if (isa(p, "id") && isa(p1, "id"))
D 19
			return (gen(NIL, r[0], width(p), width(p1)));
E 19
I 19
			return (gen(NIL, r->tag, width(p), width(p1)));
E 19
		    if (isa(p, "t") && isa(p1, "t")) {
			    if (p != p1) {
				    error("Set types of operands of %s must be identical", opname);
D 19
				    return (NIL);
E 19
I 19
				    return (NLNIL);
E 19
			    }
D 19
			    gen(TSET, r[0], width(p), 0);
E 19
I 19
			    (void) gen(TSET, r->tag, width(p), 0);
E 19
			    return (p);
		    }
#		endif OBJ
#		ifdef PC
			/*
			 * the second pass can't do
			 *	long op double  or  double op long
D 23
			 * so we have to know the type of both operands
			 * also, it gets tricky for sets, which are done
			 * by function calls.
E 23
I 23
			 * so we have to know the type of both operands.
			 * also, see the note for obj above on determining
			 * the type of empty sets.
E 23
			 */
		    codeoff();
D 19
		    p1 = rvalue( r[ 3 ] , contype , RREQ );
E 19
I 19
D 23
		    p1 = rvalue( r->expr_node.rhs , contype , RREQ );
E 23
I 23
		    p1 = rvalue(r->expr_node.rhs, NLNIL, RREQ);
E 23
E 19
		    codeon();
		    if ( isa( p1 , "id" ) ) {
D 19
			p = rvalue( r[ 2 ] , contype , RREQ );
E 19
I 19
			p = rvalue( r->expr_node.lhs , contype , RREQ );
E 19
D 20
			if ( ( p == NIL ) || ( p1 == NIL ) ) {
E 20
I 20
			if ( ( p == NLNIL ) || ( p1 == NLNIL ) ) {
E 20
D 19
			    return NIL;
E 19
I 19
			    return NLNIL;
E 19
			}
D 14
			if ( isa( p , "i" ) && isa( p1 , "d" ) ) {
			    putop( P2SCONV , P2DOUBLE );
			}
E 14
I 14
D 19
			tuac(p, p1, &rettype, &ctype);
E 14
			p1 = rvalue( r[ 3 ] , contype , RREQ );
D 14
			if ( isa( p , "d" ) && isa( p1 , "i" ) ) {
			    putop( P2SCONV , P2DOUBLE );
			}
E 14
I 14
			tuac(p1, p, &rettype, &ctype);
E 19
I 19
			tuac(p, p1, &rettype, (int *) (&ctype));
			p1 = rvalue( r->expr_node.rhs , contype , RREQ );
			tuac(p1, p, &rettype, (int *) (&ctype));
E 19
E 14
			if ( isa( p , "id" ) ) {
D 14
			    if ( isa( p , "d" ) || isa( p1 , "d" ) ) {
				ctype = P2DOUBLE;
				rettype = nl + TDOUBLE;
			    } else {
				ctype = P2INT;
				rettype = nl + T4INT;
			    }
E 14
D 19
			    putop( mathop[ r[0] - T_MULT ] , ctype );
E 19
I 19
			    putop( (int) mathop[r->tag - T_MULT], (int) ctype);
E 19
			    return rettype;
			}
		    }
		    if ( isa( p1 , "t" ) ) {
D 24
			putleaf( P2ICON , 0 , 0
			    , ADDTYPE( ADDTYPE( P2PTR | P2STRTY , P2FTN )
					, P2PTR )
E 24
I 24
			putleaf( PCC_ICON , 0 , 0
			    , PCCM_ADDTYPE( PCCM_ADDTYPE( PCCTM_PTR | PCCT_STRTY , PCCTM_FTN )
					, PCCTM_PTR )
E 24
D 19
			    , setop[ r[0] - T_MULT ] );
E 19
I 19
			    , setop[ r->tag - T_MULT ] );
I 23
			codeoff();
			contype = rvalue( r->expr_node.lhs, p1 , LREQ );
			codeon();
E 23
E 19
D 4
			/*
			 *	allocate a temporary and use it
			 */
			sizes[ cbn ].om_off -= lwidth( p1 );
E 4
I 4
D 20
			if ( contype == NIL ) {
D 18
			    contype = p1;
D 19
			    if ( contype == lookup( intset ) -> type ) {
E 19
I 19
			    if ( contype == lookup((char *) intset ) -> type ) {
E 19
				codeoff();
D 19
				contype = rvalue( r[2] , NIL , LREQ );
E 19
I 19
				contype = rvalue( r->expr_node.lhs, NLNIL ,
									LREQ );
E 20
I 20
			if ( contype == NLNIL ) {
E 20
E 19
				codeon();
			    }
E 18
I 18
D 23
			    codeoff();
D 20
			    contype = rvalue( r[2] , p1 , LREQ );
E 20
I 20
			    contype = rvalue( r->expr_node.lhs, p1 , LREQ );
E 20
			    codeon();
E 18
			}
D 20
			if ( contype == NIL ) {
E 20
I 20
			if ( contype == NLNIL ) {
E 23
E 20
D 19
			    return NIL;
E 19
I 19
			    return NLNIL;
E 19
			}
			    /*
			     *	allocate a temporary and use it
			     */
D 10
			sizes[ cbn ].om_off -= lwidth( contype );
E 4
			tempoff = sizes[ cbn ].om_off;
			putlbracket( ftnno , -tempoff );
			if ( tempoff < sizes[ cbn ].om_max ) {
			    sizes[ cbn ].om_max = tempoff;
			}
E 10
I 10
D 12
			tempoff = tmpalloc(lwidth(contype), contype, NOREG);
E 10
			putLV( 0 , cbn , tempoff , P2PTR|P2STRTY );
E 12
I 12
			tempnlp = tmpalloc(lwidth(contype), contype, NOREG);
D 19
			putLV( 0 , cbn , tempnlp -> value[ NL_OFFS ] ,
E 19
I 19
			putLV((char *) 0 , cbn , tempnlp -> value[ NL_OFFS ] ,
E 19
D 24
				tempnlp -> extra_flags , P2PTR|P2STRTY );
E 24
I 24
				tempnlp -> extra_flags , PCCTM_PTR|PCCT_STRTY );
E 24
E 12
D 4
			p = rvalue( r[2] , p1 , LREQ );
E 4
I 4
D 19
			p = rvalue( r[2] , contype , LREQ );
E 19
I 19
			p = rvalue( r->expr_node.lhs , contype , LREQ );
E 19
E 4
			if ( isa( p , "t" ) ) {
D 24
			    putop( P2LISTOP , P2INT );
E 24
I 24
			    putop( PCC_CM , PCCT_INT );
E 24
D 20
			    if ( p == NIL || p1 == NIL ) {
E 20
I 20
			    if ( p == NLNIL || p1 == NLNIL ) {
E 20
D 19
				return NIL;
E 19
I 19
				return NLNIL;
E 19
			    }
D 19
			    p1 = rvalue( r[3] , p , LREQ );
E 19
I 19
			    p1 = rvalue( r->expr_node.rhs , p , LREQ );
E 19
			    if ( p != p1 ) {
				error("Set types of operands of %s must be identical", opname);
D 19
				return NIL;
E 19
I 19
				return NLNIL;
E 19
			    }
D 24
			    putop( P2LISTOP , P2INT );
D 19
			    putleaf( P2ICON , lwidth( p1 ) / sizeof( long ) , 0
				    , P2INT , 0 );
E 19
I 19
			    putleaf( P2ICON , (int) (lwidth(p1)) / sizeof( long ) , 0
				    , P2INT , (char *) 0 );
E 19
			    putop( P2LISTOP , P2INT );
			    putop( P2CALL , P2PTR | P2STRTY );
E 24
I 24
			    putop( PCC_CM , PCCT_INT );
			    putleaf( PCC_ICON , (int) (lwidth(p1)) / sizeof( long ) , 0
				    , PCCT_INT , (char *) 0 );
			    putop( PCC_CM , PCCT_INT );
			    putop( PCC_CALL , PCCTM_PTR | PCCT_STRTY );
E 24
			    return p;
			}
		    }
		    if ( isnta( p1 , "idt" ) ) {
			    /*
			     *	find type of left operand for error message.
			     */
D 19
			p = rvalue( r[2] , contype , RREQ );
E 19
I 19
			p = rvalue( r->expr_node.lhs , contype , RREQ );
E 19
		    }
			/*
			 *	don't give spurious error messages.
			 */
D 20
		    if ( p == NIL || p1 == NIL ) {
E 20
I 20
		    if ( p == NLNIL || p1 == NLNIL ) {
E 20
D 19
			return NIL;
E 19
I 19
			return NLNIL;
E 19
		    }
#		endif PC
		if (isnta(p, "idt")) {
			error("Left operand of %s must be integer, real or set, not %s", opname, nameof(p));
D 19
			return (NIL);
E 19
I 19
			return (NLNIL);
E 19
		}
		if (isnta(p1, "idt")) {
			error("Right operand of %s must be integer, real or set, not %s", opname, nameof(p1));
D 19
			return (NIL);
E 19
I 19
			return (NLNIL);
E 19
		}
		error("Cannot mix sets with integers and reals as operands of %s", opname);
D 19
		return (NIL);
E 19
I 19
		return (NLNIL);
E 19

	case T_MOD:
	case T_DIV:
D 19
		p = rvalue(r[2], NIL , RREQ );
E 19
I 19
		p = rvalue(r->expr_node.lhs, NLNIL , RREQ );
E 19
I 14
#		ifdef PC
D 24
		    sconv(p2type(p), P2INT);
E 24
I 24
		    sconv(p2type(p), PCCT_INT);
I 26
#		ifdef tahoe
		    /* prepare for ediv workaround, see below. */
		    if (r->tag == T_MOD) {
			(void) rvalue(r->expr_node.lhs, NLNIL, RREQ);
			sconv(p2type(p), PCCT_INT);
		    }
#		endif tahoe
E 26
E 24
#		endif PC
E 14
D 19
		p1 = rvalue(r[3], NIL , RREQ );
E 19
I 19
		p1 = rvalue(r->expr_node.rhs, NLNIL , RREQ );
E 19
I 14
#		ifdef PC
D 24
		    sconv(p2type(p1), P2INT);
E 24
I 24
		    sconv(p2type(p1), PCCT_INT);
E 24
#		endif PC
E 14
D 20
		if (p == NIL || p1 == NIL)
E 20
I 20
		if (p == NLNIL || p1 == NLNIL)
E 20
D 19
			return (NIL);
E 19
I 19
			return (NLNIL);
E 19
		if (isnta(p, "i")) {
			error("Left operand of %s must be integer, not %s", opname, nameof(p));
D 19
			return (NIL);
E 19
I 19
			return (NLNIL);
E 19
		}
		if (isnta(p1, "i")) {
			error("Right operand of %s must be integer, not %s", opname, nameof(p1));
D 19
			return (NIL);
E 19
I 19
			return (NLNIL);
E 19
		}
#		ifdef OBJ
D 19
		    return (gen(NIL, r[0], width(p), width(p1)));
E 19
I 19
		    return (gen(NIL, r->tag, width(p), width(p1)));
E 19
#		endif OBJ
#		ifdef PC
I 26
#		ifndef tahoe
E 26
D 19
		    putop( r[ 0 ] == T_DIV ? P2DIV : P2MOD , P2INT );
E 19
I 19
D 24
		    putop( r->tag == T_DIV ? P2DIV : P2MOD , P2INT );
E 24
I 24
		    putop( r->tag == T_DIV ? PCC_DIV : PCC_MOD , PCCT_INT );
E 24
E 19
		    return ( nl + T4INT );
I 26
#		else tahoe
		    putop( PCC_DIV , PCCT_INT );
		    if (r->tag == T_MOD) {
		    /*
		     * avoid f1 bug: PCC_MOD would generate an 'ediv',
		     * which would reuire too many registers to evaluate
		     * things like
		     * var i:boolean;j:integer; i := (j+1) = (j mod 2);
		     * so, instead of
		     *                PCC_MOD
		     *		        / \
		     *	               p   p1
		     * we put
		     *                  PCC_MINUS
		     *                    /   \
		     *			 p   PCC_MUL               
		     *			      /   \
		     *			  PCC_DIV  p1
		     *                      / \
		     *                     p  p1
		     *
		     * we already have put p, p, p1, PCC_DIV. and now...
		     */
			    rvalue(r->expr_node.rhs, NLNIL , RREQ );
			    sconv(p2type(p1), PCCT_INT);
			    putop( PCC_MUL, PCCT_INT );
			    putop( PCC_MINUS, PCCT_INT );
		    }
		    return ( nl + T4INT );
#		endif tahoe
E 26
#		endif PC

	case T_EQ:
	case T_NE:
	case T_LT:
	case T_GT:
	case T_LE:
	case T_GE:
		/*
		 * Since there can be no, a priori, knowledge
		 * of the context type should a constant string
		 * or set arise, we must poke around to find such
		 * a type if possible.  Since constant strings can
		 * always masquerade as identifiers, this is always
		 * necessary.
I 23
		 * see the note in the obj section of case T_MULT above
		 * for the determination of the base type of empty sets.
E 23
		 */
		codeoff();
D 19
		p1 = rvalue(r[3], NIL , RREQ );
E 19
I 19
		p1 = rvalue(r->expr_node.rhs, NLNIL , RREQ );
E 19
		codeon();
D 19
		if (p1 == NIL)
			return (NIL);
E 19
I 19
		if (p1 == NLNIL)
			return (NLNIL);
E 19
		contype = p1;
#		ifdef OBJ
D 4
		    if (p1 == nl+TSET || p1->class == STR) {
E 4
I 4
		    if (p1->class == STR) {
E 4
			    /*
			     * For constant strings we want
			     * the longest type so as to be
			     * able to do padding (more importantly
			     * avoiding truncation). For clarity,
			     * we get this length here.
			     */
			    codeoff();
D 19
			    p = rvalue(r[2], NIL , RREQ );
E 19
I 19
			    p = rvalue(r->expr_node.lhs, NLNIL , RREQ );
E 19
			    codeon();
D 19
			    if (p == NIL)
				    return (NIL);
E 19
I 19
			    if (p == NLNIL)
				    return (NLNIL);
E 19
D 4
			    if (p1 == nl+TSET || width(p) > width(p1))
E 4
I 4
			    if (width(p) > width(p1))
E 4
				    contype = p;
I 4
D 18
		    } else if ( isa( p1 , "t" ) ) {
D 19
			if ( contype == lookup( intset ) -> type ) {
E 19
I 19
D 20
			if ( contype == lookup((char *) intset ) -> type ) {
E 19
			    codeoff();
D 19
			    contype = rvalue( r[2] , NIL , RREQ );
E 19
I 19
			    contype = rvalue( r->expr_node.lhs , NLNIL , RREQ );
E 19
			    codeon();
			    if ( contype == NIL ) {
D 19
				return NIL;
E 19
I 19
				return NLNIL;
E 20
E 19
			    }
			}
E 18
E 4
		    }
I 23
		    if (isa(p1, "t")) {
			codeoff();
			contype = rvalue(r->expr_node.lhs, p1, RREQ);
			codeon();
			if (contype == NLNIL) {
			    return NLNIL;
			}
		    }
E 23
		    /*
		     * Now we generate code for
		     * the operands of the relational
		     * operation.
		     */
D 19
		    p = rvalue(r[2], contype , RREQ );
		    if (p == NIL)
			    return (NIL);
		    p1 = rvalue(r[3], p , RREQ );
		    if (p1 == NIL)
			    return (NIL);
E 19
I 19
		    p = rvalue(r->expr_node.lhs, contype , RREQ );
		    if (p == NLNIL)
			    return (NLNIL);
		    p1 = rvalue(r->expr_node.rhs, p , RREQ );
		    if (p1 == NLNIL)
			    return (NLNIL);
E 19
#		endif OBJ
#		ifdef PC
		    c1 = classify( p1 );
		    if ( c1 == TSET || c1 == TSTR || c1 == TREC ) {
D 24
			putleaf( P2ICON , 0 , 0
				, ADDTYPE( P2FTN | P2INT , P2PTR )
E 24
I 24
			putleaf( PCC_ICON , 0 , 0
				, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 24
D 19
				, c1 == TSET  ? relts[ r[0] - T_EQ ]
					      : relss[ r[0] - T_EQ ] );
E 19
I 19
				, c1 == TSET  ? relts[ r->tag - T_EQ ]
					      : relss[ r->tag - T_EQ ] );
E 19
			    /*
			     *	for [] and strings, comparisons are done on
			     *	the maximum width of the two sides.
			     *	for other sets, we have to ask the left side
			     *	what type it is based on the type of the right.
			     *	(this matters for intsets).
			     */
D 4
			if ( p1 == nl + TSET || c1 == TSTR ) {
E 4
I 4
			if ( c1 == TSTR ) {
E 4
			    codeoff();
D 19
			    p = rvalue( r[ 2 ] , NIL , LREQ );
E 19
I 19
			    p = rvalue( r->expr_node.lhs , NLNIL , LREQ );
E 19
			    codeon();
D 4
			    if (   p1 == nl + TSET
				|| lwidth( p ) > lwidth( p1 ) ) {
E 4
I 4
D 19
			    if ( p == NIL ) {
				return NIL;
E 19
I 19
			    if ( p == NLNIL ) {
				return NLNIL;
E 19
			    }
			    if ( lwidth( p ) > lwidth( p1 ) ) {
E 4
				contype = p;
			    }
I 4
			} else if ( c1 == TSET ) {
D 18
D 19
			    if ( contype == lookup( intset ) -> type ) {
E 19
I 19
D 20
			    if ( contype == lookup((char *) intset ) -> type ) {
E 19
				codeoff();
D 19
				p = rvalue( r[ 2 ] , NIL , LREQ );
E 19
I 19
				p = rvalue( r->expr_node.lhs , NLNIL , LREQ );
E 19
				codeon();
D 19
				if ( p == NIL ) {
				    return NIL;
E 19
I 19
				if ( p == NLNIL ) {
				    return NLNIL;
E 20
E 19
				}
				contype = p;
E 18
I 18
			    codeoff();
D 20
			    p = rvalue( r[ 2 ] , contype , LREQ );
E 20
I 20
D 23
			    p = rvalue( r->expr_node.lhs , contype , LREQ );
E 23
I 23
			    contype = rvalue(r->expr_node.lhs, p1, LREQ);
E 23
E 20
			    codeon();
D 20
			    if ( p == NIL ) {
				return NIL;
E 20
I 20
D 23
			    if ( p == NLNIL ) {
E 23
I 23
			    if (contype == NLNIL) {
E 23
				return NLNIL;
E 20
E 18
			    }
I 18
D 23
			    contype = p;
E 23
E 18
E 4
D 5
			} else {
D 4
			    codeoff();
			    p = rvalue( r[ 2 ] , contype , LREQ );
			    codeon();
E 4
			    contype = p;
			}
E 5
I 5
			} 
E 5
D 4
			if ( p == NIL ) {
			    return NIL;
			}
E 4
			    /*
			     *	put out the width of the comparison.
			     */
D 19
			putleaf( P2ICON , lwidth( contype ) , 0 , P2INT , 0 );
E 19
I 19
D 24
			putleaf(P2ICON, (int) lwidth(contype), 0, P2INT, (char *) 0);
E 24
I 24
			putleaf(PCC_ICON, (int) lwidth(contype), 0, PCCT_INT, (char *) 0);
E 24
E 19
			    /*
			     *	and the left hand side,
			     *	for sets, strings, records
			     */
D 19
			p = rvalue( r[ 2 ] , contype , LREQ );
I 13
			if ( p == NIL ) {
			    return NIL;
E 19
I 19
			p = rvalue( r->expr_node.lhs , contype , LREQ );
			if ( p == NLNIL ) {
			    return NLNIL;
E 19
			}
E 13
D 24
			putop( P2LISTOP , P2INT );
E 24
I 24
			putop( PCC_CM , PCCT_INT );
E 24
D 19
			p1 = rvalue( r[ 3 ] , p , LREQ );
I 13
			if ( p1 == NIL ) {
			    return NIL;
E 19
I 19
			p1 = rvalue( r->expr_node.rhs , p , LREQ );
			if ( p1 == NLNIL ) {
			    return NLNIL;
E 19
			}
E 13
D 24
			putop( P2LISTOP , P2INT );
			putop( P2CALL , P2INT );
E 24
I 24
			putop( PCC_CM , PCCT_INT );
			putop( PCC_CALL , PCCT_INT );
E 24
		    } else {
			    /*
			     *	the easy (scalar or error) case
			     */
D 19
			p = rvalue( r[ 2 ] , contype , RREQ );
			if ( p == NIL ) {
			    return NIL;
E 19
I 19
			p = rvalue( r->expr_node.lhs , contype , RREQ );
			if ( p == NLNIL ) {
			    return NLNIL;
E 19
I 7
			}
E 7
			    /*
			     * since the second pass can't do
			     *	long op double  or  double op long
			     * we may have to do some coercing.
			     */
D 7
			if ( isa( p , "i" ) && isa( p1 , "d" ) )
E 7
I 7
D 14
			if ( isa( p , "i" ) && isa( p1 , "d" ) ) {
E 7
			    putop( P2SCONV , P2DOUBLE );
			}
E 14
I 14
D 19
			tuac(p, p1, &rettype, &ctype);
E 14
			p1 = rvalue( r[ 3 ] , p , RREQ );
I 13
			if ( p1 == NIL ) {
			    return NIL;
E 19
I 19
			tuac(p, p1, &rettype, (int *) (&ctype));
			p1 = rvalue( r->expr_node.rhs , p , RREQ );
			if ( p1 == NLNIL ) {
			    return NLNIL;
E 19
			}
E 13
D 14
			if ( isa( p , "d" ) && isa( p1 , "i" ) )
			    putop( P2SCONV , P2DOUBLE );
E 14
I 14
D 19
			tuac(p1, p, &rettype, &ctype);
E 14
			putop( relops[ r[0] - T_EQ ] , P2INT );
E 19
I 19
			tuac(p1, p, &rettype, (int *) (&ctype));
D 24
			putop((int) relops[ r->tag - T_EQ ] , P2INT );
E 19
I 14
			sconv(P2INT, P2CHAR);
E 24
I 24
			putop((int) relops[ r->tag - T_EQ ] , PCCT_INT );
			sconv(PCCT_INT, PCCT_CHAR);
E 24
E 14
		    }
#		endif PC
		c = classify(p);
		c1 = classify(p1);
		if (nocomp(c) || nocomp(c1))
D 19
			return (NIL);
		g = NIL;
E 19
I 19
			return (NLNIL);
#		ifdef OBJ
		    g = NIL;
#		endif
E 19
		switch (c) {
			case TBOOL:
			case TCHAR:
				if (c != c1)
					goto clash;
				break;
			case TINT:
			case TDOUBLE:
				if (c1 != TINT && c1 != TDOUBLE)
					goto clash;
				break;
			case TSCAL:
				if (c1 != TSCAL)
					goto clash;
				if (scalar(p) != scalar(p1))
					goto nonident;
				break;
			case TSET:
				if (c1 != TSET)
					goto clash;
I 11
				if ( opt( 's' ) &&
D 19
				    ( ( r[0] == T_LT ) || ( r[0] == T_GT ) ) &&
E 19
I 19
				    ( ( r->tag == T_LT) || (r->tag == T_GT) ) &&
E 19
				    ( line != nssetline ) ) {
				    nssetline = line;
				    standard();
				    error("%s comparison on sets is non-standard" , opname );
				}
E 11
				if (p != p1)
					goto nonident;
D 19
				g = TSET;
E 19
I 19
#				ifdef OBJ
				    g = TSET;
#				endif
E 19
				break;
			case TREC:
				if ( c1 != TREC ) {
				    goto clash;
				}
				if ( p != p1 ) {
				    goto nonident;
				}
D 19
				if (r[0] != T_EQ && r[0] != T_NE) {
E 19
I 19
				if (r->tag != T_EQ && r->tag != T_NE) {
E 19
					error("%s not allowed on records - only allow = and <>" , opname );
D 19
					return (NIL);
E 19
I 19
					return (NLNIL);
E 19
				}
D 19
				g = TREC;
E 19
I 19
#				ifdef OBJ
				    g = TREC;
#				endif
E 19
				break;
			case TPTR:
			case TNIL:
				if (c1 != TPTR && c1 != TNIL)
					goto clash;
D 19
				if (r[0] != T_EQ && r[0] != T_NE) {
E 19
I 19
				if (r->tag != T_EQ && r->tag != T_NE) {
E 19
					error("%s not allowed on pointers - only allow = and <>" , opname );
D 19
					return (NIL);
E 19
I 19
					return (NLNIL);
E 19
				}
I 17
				if (p != nl+TNIL && p1 != nl+TNIL && p != p1)
					goto nonident;
E 17
				break;
			case TSTR:
				if (c1 != TSTR)
					goto clash;
				if (width(p) != width(p1)) {
					error("Strings not same length in %s comparison", opname);
D 19
					return (NIL);
E 19
I 19
					return (NLNIL);
E 19
				}
D 19
				g = TSTR;
E 19
I 19
#				ifdef OBJ
				    g = TSTR;
#				endif OBJ
E 19
				break;
			default:
				panic("rval2");
		}
#		ifdef OBJ
D 19
		    return (gen(g, r[0], width(p), width(p1)));
E 19
I 19
		    return (gen(g, r->tag, width(p), width(p1)));
E 19
#		endif OBJ
#		ifdef PC
		    return nl + TBOOL;
#		endif PC
clash:
		error("%ss and %ss cannot be compared - operator was %s", clnames[c], clnames[c1], opname);
D 19
		return (NIL);
E 19
I 19
		return (NLNIL);
E 19
nonident:
		error("%s types must be identical in comparisons - operator was %s", clnames[c1], opname);
D 19
		return (NIL);
E 19
I 19
		return (NLNIL);
E 19

	case T_IN:
D 19
	    rt = r[3];
E 19
I 19
	    rt = r->expr_node.rhs;
E 19
#	    ifdef OBJ
D 19
		if (rt != NIL && rt[0] == T_CSET) {
			precset( rt , NIL , &csetd );
E 19
I 19
		if (rt != TR_NIL && rt->tag == T_CSET) {
			(void) precset( rt , NLNIL , &csetd );
E 19
			p1 = csetd.csettype;
D 19
			if (p1 == NIL)
			    return NIL;
E 19
I 19
			if (p1 == NLNIL)
			    return NLNIL;
E 19
D 4
			if (p1 == nl+TSET) {
			    if ( !inempty ) {
				warning();
				error("... in [] makes little sense, since it is always false!");
				inempty = TRUE;
			    }
			    put(1, O_CON1, 0);
			    return (nl+T1BOOL);
			}
E 4
			postcset( rt, &csetd);
		    } else {
D 19
			p1 = stkrval(r[3], NIL , RREQ );
			rt = NIL;
E 19
I 19
			p1 = stkrval(r->expr_node.rhs, NLNIL , (long) RREQ );
			rt = TR_NIL;
E 19
		    }
#		endif OBJ
#		ifdef PC
D 19
		    if (rt != NIL && rt[0] == T_CSET) {
			if ( precset( rt , NIL , &csetd ) ) {
E 19
I 19
		    if (rt != TR_NIL && rt->tag == T_CSET) {
			if ( precset( rt , NLNIL , &csetd ) ) {
E 19
D 4
			    if ( csetd.csettype != nl + TSET ) {
				putleaf( P2ICON , 0 , 0
					, ADDTYPE( P2FTN | P2INT , P2PTR )
					, "_IN" );
			    }
E 4
I 4
D 24
			    putleaf( P2ICON , 0 , 0
				    , ADDTYPE( P2FTN | P2INT , P2PTR )
E 24
I 24
			    putleaf( PCC_ICON , 0 , 0
				    , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 24
				    , "_IN" );
E 4
			} else {
D 24
			    putleaf( P2ICON , 0 , 0
				    , ADDTYPE( P2FTN | P2INT , P2PTR )
E 24
I 24
			    putleaf( PCC_ICON , 0 , 0
				    , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 24
				    , "_INCT" );
			}
			p1 = csetd.csettype;
			if (p1 == NIL)
D 19
			    return NIL;
E 19
I 19
			    return NLNIL;
E 19
D 4
			if ( p1 == nl + TSET ) {
			    if ( !inempty ) {
				warning();
				error("... in [] makes little sense, since it is always false!");
				inempty = TRUE;
			    }
			    putleaf( P2ICON , 0 , 0 , P2INT , 0 );
			    return (nl+T1BOOL);
			}
E 4
		    } else {
D 24
			putleaf( P2ICON , 0 , 0
				, ADDTYPE( P2FTN | P2INT , P2PTR )
E 24
I 24
			putleaf( PCC_ICON , 0 , 0
				, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 24
				, "_IN" );
			codeoff();
D 19
			p1 = rvalue(r[3], NIL , LREQ );
E 19
I 19
			p1 = rvalue(r->expr_node.rhs, NLNIL , LREQ );
E 19
			codeon();
		    }
#		endif PC
D 19
		p = stkrval(r[2], NIL , RREQ );
E 19
I 19
		p = stkrval(r->expr_node.lhs, NLNIL , (long) RREQ );
E 19
		if (p == NIL || p1 == NIL)
D 19
			return (NIL);
		if (p1->class != SET) {
E 19
I 19
			return (NLNIL);
		if (p1->class != (char) SET) {
E 19
			error("Right operand of 'in' must be a set, not %s", nameof(p1));
D 19
			return (NIL);
E 19
I 19
			return (NLNIL);
E 19
		}
D 19
		if (incompat(p, p1->type, r[2])) {
E 19
I 19
		if (incompat(p, p1->type, r->expr_node.lhs)) {
E 19
			cerror("Index type clashed with set component type for 'in'");
D 19
			return (NIL);
E 19
I 19
			return (NLNIL);
E 19
		}
		setran(p1->type);
#		ifdef OBJ
D 19
		    if (rt == NIL || csetd.comptime)
			    put(4, O_IN, width(p1), set.lwrb, set.uprbp);
E 19
I 19
		    if (rt == TR_NIL || csetd.comptime)
			    (void) put(4, O_IN, width(p1), set.lwrb, set.uprbp);
E 19
		    else
D 8
			    put(2, O_INCT, 3 + csetd.singcnt + 2*csetd.paircnt);
E 8
I 8
D 19
			    put(2, O_INCT,
E 19
I 19
			    (void) put(2, O_INCT,
E 19
				(int)(3 + csetd.singcnt + 2*csetd.paircnt));
E 8
#		endif OBJ
#		ifdef PC
D 19
		    if ( rt == NIL || rt[0] != T_CSET ) {
			putleaf( P2ICON , set.lwrb , 0 , P2INT , 0 );
E 19
I 19
		    if ( rt == TR_NIL || rt->tag != T_CSET ) {
D 24
			putleaf( P2ICON , set.lwrb , 0 , P2INT , (char *) 0 );
E 19
			putop( P2LISTOP , P2INT );
D 19
			putleaf( P2ICON , set.uprbp , 0 , P2INT , 0 );
E 19
I 19
			putleaf( P2ICON , set.uprbp , 0 , P2INT , (char *) 0 );
E 19
			putop( P2LISTOP , P2INT );
E 24
I 24
			putleaf( PCC_ICON , set.lwrb , 0 , PCCT_INT , (char *) 0 );
			putop( PCC_CM , PCCT_INT );
			putleaf( PCC_ICON , set.uprbp , 0 , PCCT_INT , (char *) 0 );
			putop( PCC_CM , PCCT_INT );
E 24
D 19
			p1 = rvalue( r[3] , NIL , LREQ );
I 13
			if ( p1 == NIL ) {
			    return NIL;
E 19
I 19
			p1 = rvalue( r->expr_node.rhs , NLNIL , LREQ );
			if ( p1 == NLNIL ) {
			    return NLNIL;
E 19
			}
E 13
D 24
			putop( P2LISTOP , P2INT );
E 24
I 24
			putop( PCC_CM , PCCT_INT );
E 24
		    } else if ( csetd.comptime ) {
D 19
			putleaf( P2ICON , set.lwrb , 0 , P2INT , 0 );
E 19
I 19
D 24
			putleaf( P2ICON , set.lwrb , 0 , P2INT , (char *) 0 );
E 19
			putop( P2LISTOP , P2INT );
D 19
			putleaf( P2ICON , set.uprbp , 0 , P2INT , 0 );
E 19
I 19
			putleaf( P2ICON , set.uprbp , 0 , P2INT , (char *) 0 );
E 19
			putop( P2LISTOP , P2INT );
E 24
I 24
			putleaf( PCC_ICON , set.lwrb , 0 , PCCT_INT , (char *) 0 );
			putop( PCC_CM , PCCT_INT );
			putleaf( PCC_ICON , set.uprbp , 0 , PCCT_INT , (char *) 0 );
			putop( PCC_CM , PCCT_INT );
E 24
D 19
			postcset( r[3] , &csetd );
E 19
I 19
			postcset( r->expr_node.rhs , &csetd );
E 19
D 24
			putop( P2LISTOP , P2INT );
E 24
I 24
			putop( PCC_CM , PCCT_INT );
E 24
		    } else {
D 19
			postcset( r[3] , &csetd );
E 19
I 19
			postcset( r->expr_node.rhs , &csetd );
E 19
		    }
D 24
		    putop( P2CALL , P2INT );
I 14
		    sconv(P2INT, P2CHAR);
E 24
I 24
		    putop( PCC_CALL , PCCT_INT );
		    sconv(PCCT_INT, PCCT_CHAR);
E 24
E 14
#		endif PC
		return (nl+T1BOOL);
	default:
D 19
		if (r[2] == NIL)
			return (NIL);
		switch (r[0]) {
E 19
I 19
		if (r->expr_node.lhs == TR_NIL)
			return (NLNIL);
		switch (r->tag) {
E 19
		default:
			panic("rval3");


		/*
		 * An octal number
		 */
		case T_BINT:
D 19
			f = a8tol(r[2]);
E 19
I 19
			f.pdouble = a8tol(r->const_node.cptr);
E 19
			goto conint;
	
		/*
		 * A decimal number
		 */
		case T_INT:
D 19
			f = atof(r[2]);
E 19
I 19
			f.pdouble = atof(r->const_node.cptr);
E 19
conint:
D 19
			if (f > MAXINT || f < MININT) {
E 19
I 19
			if (f.pdouble > MAXINT || f.pdouble < MININT) {
E 19
				error("Constant too large for this implementation");
D 19
				return (NIL);
E 19
I 19
				return (NLNIL);
E 19
			}
D 19
			l = f;
E 19
I 19
			l = f.pdouble;
E 19
D 14
			if (bytes(l, l) <= 2) {
#				ifdef OBJ
				    put(2, O_CON2, ( short ) l);
#				endif OBJ
#				ifdef PC
				        /*
					 * short constants are ints
					 */
				    putleaf( P2ICON , l , 0 , P2INT , 0 );
#				endif PC
				return (nl+T2INT);
			}
E 14
#			ifdef OBJ
I 14
			    if (bytes(l, l) <= 2) {
D 19
				    put(2, O_CON2, ( short ) l);
E 19
I 19
				    (void) put(2, O_CON2, ( short ) l);
E 19
				    return (nl+T2INT);
			    }
E 14
D 19
			    put(2, O_CON4, l); 
E 19
I 19
			    (void) put(2, O_CON4, l); 
E 19
I 14
			    return (nl+T4INT);
E 14
#			endif OBJ
#			ifdef PC
D 14
			    putleaf( P2ICON , l , 0 , P2INT , 0 );
E 14
I 14
			    switch (bytes(l, l)) {
				case 1:
D 19
				    putleaf(P2ICON, l, 0, P2CHAR, 0);
E 19
I 19
D 24
				    putleaf(P2ICON, (int) l, 0, P2CHAR, 
E 24
I 24
				    putleaf(PCC_ICON, (int) l, 0, PCCT_CHAR, 
E 24
						(char *) 0);
E 19
				    return nl+T1INT;
				case 2:
D 19
				    putleaf(P2ICON, l, 0, P2SHORT, 0);
E 19
I 19
D 24
				    putleaf(P2ICON, (int) l, 0, P2SHORT, 
E 24
I 24
				    putleaf(PCC_ICON, (int) l, 0, PCCT_SHORT, 
E 24
						(char *) 0);
E 19
				    return nl+T2INT;
				case 4:
D 19
				    putleaf(P2ICON, l, 0, P2INT, 0);
E 19
I 19
D 24
				    putleaf(P2ICON, (int) l, 0, P2INT,
E 24
I 24
				    putleaf(PCC_ICON, (int) l, 0, PCCT_INT,
E 24
						(char *) 0);
E 19
				    return nl+T4INT;
			    }
E 14
#			endif PC
D 14
			return (nl+T4INT);
E 14
	
		/*
		 * A floating point number
		 */
		case T_FINT:
#			ifdef OBJ
D 19
			    put(2, O_CON8, atof(r[2]));
E 19
I 19
			    (void) put(2, O_CON8, atof(r->const_node.cptr));
E 19
#			endif OBJ
#			ifdef PC
D 19
			    putCON8( atof( r[2] ) );
E 19
I 19
			    putCON8( atof( r->const_node.cptr ) );
E 19
#			endif PC
			return (nl+TDOUBLE);
	
		/*
		 * Constant strings.  Note that constant characters
		 * are constant strings of length one; there is
		 * no constant string of length one.
		 */
		case T_STRNG:
D 19
			cp = r[2];
E 19
I 19
			cp = r->const_node.cptr;
E 19
			if (cp[1] == 0) {
#				ifdef OBJ
D 19
				    put(2, O_CONC, cp[0]);
E 19
I 19
				    (void) put(2, O_CONC, cp[0]);
E 19
#				endif OBJ
#				ifdef PC
D 19
				    putleaf( P2ICON , cp[0] , 0 , P2CHAR , 0 );
E 19
I 19
D 24
				    putleaf( P2ICON , cp[0] , 0 , P2CHAR ,
E 24
I 24
				    putleaf( PCC_ICON , cp[0] , 0 , PCCT_CHAR ,
E 24
						(char *) 0 );
E 19
#				endif PC
				return (nl+T1CHAR);
			}
			goto cstrng;
		}
	
	}
}

/*
 * Can a class appear
 * in a comparison ?
 */
nocomp(c)
	int c;
{

	switch (c) {
		case TREC:
D 5
			if ( opt( 's' ) ) {
			    standard();
E 5
I 5
			if ( line != reccompline ) {
			    reccompline = line;
			    warning();
			    if ( opt( 's' ) ) {
				standard();
			    }
E 5
			    error("record comparison is non-standard");
			}
			break;
		case TFILE:
		case TARY:
			error("%ss may not participate in comparisons", clnames[c]);
			return (1);
	}
	return (NIL);
}

    /*
     *	this is sort of like gconst, except it works on expression trees
     *	rather than declaration trees, and doesn't give error messages for
     *	non-constant things.
     *	as a side effect this fills in the con structure that gconst uses.
     *	this returns TRUE or FALSE.
     */
I 19

bool 
E 19
constval(r)
D 19
	register int *r;
E 19
I 19
	register struct tnode *r;
E 19
{
	register struct nl *np;
D 19
	register *cn;
E 19
I 19
	register struct tnode *cn;
E 19
	char *cp;
	int negd, sgnd;
	long ci;

	con.ctype = NIL;
	cn = r;
	negd = sgnd = 0;
loop:
	    /*
	     *	cn[2] is nil if error recovery generated a T_STRNG
	     */
D 19
	if (cn == NIL || cn[2] == NIL)
E 19
I 19
	if (cn == TR_NIL || cn->expr_node.lhs == TR_NIL)
E 19
		return FALSE;
D 19
	switch (cn[0]) {
E 19
I 19
	switch (cn->tag) {
E 19
		default:
			return FALSE;
		case T_MINUS:
			negd = 1 - negd;
			/* and fall through */
		case T_PLUS:
			sgnd++;
D 19
			cn = cn[2];
E 19
I 19
			cn = cn->un_expr.expr;
E 19
			goto loop;
		case T_NIL:
			con.cpval = NIL;
			con.cival = 0;
			con.crval = con.cival;
			con.ctype = nl + TNIL;
			break;
		case T_VAR:
D 19
			np = lookup(cn[2]);
			if (np == NIL || np->class != CONST) {
E 19
I 19
			np = lookup(cn->var_node.cptr);
			if (np == NLNIL || np->class != CONST) {
E 19
				return FALSE;
			}
D 19
			if ( cn[3] != NIL ) {
E 19
I 19
			if ( cn->var_node.qual != TR_NIL ) {
E 19
				return FALSE;
			}
			con.ctype = np->type;
			switch (classify(np->type)) {
				case TINT:
					con.crval = np->range[0];
					break;
				case TDOUBLE:
					con.crval = np->real;
					break;
				case TBOOL:
				case TCHAR:
				case TSCAL:
					con.cival = np->value[0];
					con.crval = con.cival;
					break;
				case TSTR:
D 19
					con.cpval = np->ptr[0];
E 19
I 19
					con.cpval = (char *) np->ptr[0];
E 19
					break;
				default:
					con.ctype = NIL;
					return FALSE;
			}
			break;
		case T_BINT:
D 19
			con.crval = a8tol(cn[2]);
E 19
I 19
			con.crval = a8tol(cn->const_node.cptr);
E 19
			goto restcon;
		case T_INT:
D 19
			con.crval = atof(cn[2]);
E 19
I 19
			con.crval = atof(cn->const_node.cptr);
E 19
			if (con.crval > MAXINT || con.crval < MININT) {
				derror("Constant too large for this implementation");
				con.crval = 0;
			}
restcon:
			ci = con.crval;
#ifndef PI0
			if (bytes(ci, ci) <= 2)
				con.ctype = nl+T2INT;
			else	
#endif
				con.ctype = nl+T4INT;
			break;
		case T_FINT:
			con.ctype = nl+TDOUBLE;
D 19
			con.crval = atof(cn[2]);
E 19
I 19
			con.crval = atof(cn->const_node.cptr);
E 19
			break;
		case T_STRNG:
D 19
			cp = cn[2];
E 19
I 19
			cp = cn->const_node.cptr;
E 19
			if (cp[1] == 0) {
				con.ctype = nl+T1CHAR;
				con.cival = cp[0];
				con.crval = con.cival;
				break;
			}
			con.ctype = nl+TSTR;
			con.cpval = cp;
			break;
	}
	if (sgnd) {
		if (isnta(con.ctype, "id")) {
			derror("%s constants cannot be signed", nameof(con.ctype));
			return FALSE;
		} else if (negd)
			con.crval = -con.crval;
	}
	return TRUE;
}
E 1
