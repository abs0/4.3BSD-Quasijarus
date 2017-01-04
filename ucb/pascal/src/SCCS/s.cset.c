h50474
s 00007/00003/00464
d D 5.1 85/06/05 14:03:42 dist 13 12
c Add copyright
e
s 00009/00009/00458
d D 2.2 85/03/20 14:59:38 ralph 12 11
c changes from donn@utah-cs for common header file for pcc
e
s 00000/00000/00467
d D 2.1 84/02/08 20:49:47 aoki 11 10
c synchronize to version 2
e
s 00078/00075/00389
d D 1.8 84/02/04 17:28:58 thien 10 7
c lint
e
s 00000/00000/00476
d R 1.9 83/09/19 06:57:58 thien 9 8
c Restoring to unlinted version
e
s 00102/00090/00374
d R 1.8 83/08/19 04:56:13 thien 8 7
c The changes were made to allow successful linting
e
s 00009/00008/00455
d D 1.7 83/02/01 20:06:53 peter 7 6
c make the alignment of constant sets machine independent.
e
s 00001/00001/00462
d D 1.6 81/03/20 14:25:01 peter 6 5
c use cgenflg consistently; take out )#'s on pi code.
e
s 00001/00001/00462
d D 1.5 81/03/10 00:43:37 mckusic 5 4
c onyx optimizations
e
s 00083/00033/00380
d D 1.4 81/03/08 19:24:16 mckusic 4 3
c merge in onyx changes
e
s 00001/00001/00412
d D 1.3 80/12/12 15:53:58 peter 3 2
c output set pairs in same order for px and pc so can use libpc
e
s 00014/00005/00399
d D 1.2 80/10/19 18:32:34 peter 2 1
c guess that [] is intset if no other context information.
e
s 00404/00000/00000
d D 1.1 80/08/27 19:54:52 peter 1 0
c date and time created 80/08/27 19:54:52 by peter
e
u
U
t
T
I 1
D 13
/* Copyright (c) 1979 Regents of the University of California */
E 13
I 13
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 13

I 10
#ifndef lint
E 10
D 4
static	char sccsid[] = "%Z%%M% %I% %G%";
E 4
I 4
D 13
static char sccsid[] = "%Z%%M% %I% %G%";
I 10
#endif
E 13
I 13
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 13
E 10
E 4

#include "whoami.h"
#include "0.h"
#include "tree.h"
#include "opcode.h"
#include "objfmt.h"
I 10
#include "tree_ty.h"
E 10
I 4
#ifdef PC
E 4
#include "pc.h"
D 12
#include "pcops.h"
E 12
I 12
#include <pcc.h>
E 12
I 7
#include "align.h"
E 7
I 4
#endif PC
E 4

/*
I 4
 * CONSETS causes compile time constant sets to be constructed here.
 *
 * COMPSETSZE defines the maximum number of longs to be used in
 *	constant set construction
 */
#define CONSETS
#define COMPSETSZE 10

#define BITSPERBYTE 8
#define BITSPERLONG 32
#define LG2BITSBYTE 3
#define MSKBITSBYTE 0x07
#define LG2BITSLONG 5
#define MSKBITSLONG 0x1f

/*
E 4
 *	rummage through a `constant' set (i.e. anything within [ ]'s) tree
 *	and decide if this is a compile time constant set or a runtime set.
 *	this information is returned in a structure passed from the caller.
 *	while rummaging, this also reorders the tree so that all ranges
 *	preceed all singletons.
 */
bool
precset( r , settype , csetp )
D 10
	int		*r;
E 10
I 10
	struct tnode	*r;
E 10
	struct nl	*settype;
	struct csetstr	*csetp;
{
D 10
	register int		*e;
E 10
I 10
	register struct tnode	*e;
E 10
	register struct nl	*t;
	register struct nl	*exptype;
D 10
	register int		*el;
	register int		*pairp;
	register int		*singp;
	int			*ip;
E 10
I 10
	register struct tnode	*el;
	register struct tnode	*pairp;
	register struct tnode	*singp;
	struct tnode		*ip;
E 10
D 4
	long			lower;
	long			upper;
	long			rangeupper;
E 4
I 4
	int			lower;
	int			upper;
E 4
	bool			setofint;

	csetp -> csettype = NIL;
	csetp -> paircnt = 0;
	csetp -> singcnt = 0;
	csetp -> comptime = TRUE;
	setofint = FALSE;
	if ( settype != NIL ) {
	    if ( settype -> class == SET ) {
		    /*
		     *	the easy case, we are told the type of the set.
		     */
		exptype = settype -> type;
	    } else {
		    /*
		     *	we are told the type, but it's not a set
		     *	supposedly possible if someone tries
		     *	e.g string context [1,2] = 'abc'
		     */
		error("Constant set involved in non set context");
		return csetp -> comptime;
	    }
	} else {
		/*
		 * So far we have no indication
		 * of what the set type should be.
		 * We "look ahead" and try to infer
		 * The type of the constant set
		 * by evaluating one of its members.
		 */
D 10
	    e = r[2];
E 10
I 10
	    e = r->cset_node.el_list;
E 10
	    if (e == NIL) {
		    /*
D 2
		     *	tentative for []
E 2
I 2
		     *	tentative for [], return type of `intset'
E 2
		     */
D 2
		csetp -> csettype = nl + TSET;
E 2
I 2
D 10
		settype = lookup( intset );
E 10
I 10
		settype = lookup( (char *) intset );
E 10
		if ( settype == NIL ) {
		    panic( "empty set" );
		}
		settype = settype -> type;
		if ( settype == NIL ) {
		    return csetp -> comptime;
		}
		if ( isnta( settype , "t" ) ) {
		    error("Set default type \"intset\" is not a set");
		    return csetp -> comptime;
		}
		csetp -> csettype = settype;
I 4
D 5
		setran( settype );
E 5
I 5
		setran( settype -> type );
E 5
		if (((set.uprbp + 1) >> LG2BITSLONG) >= COMPSETSZE)
			csetp -> comptime = FALSE;
E 4
E 2
		return csetp -> comptime;
	    }
D 10
	    e = e[1];
E 10
I 10
	    e = e->list_node.list;
E 10
	    if (e == NIL) {
		return csetp -> comptime;
	    }
D 10
	    if (e[0] == T_RANG) {
		    e = e[1];
E 10
I 10
	    if (e->tag == T_RANG) {
		    e = e->rang.expr1;
E 10
	    }
	    codeoff();
D 10
	    t = rvalue(e, NIL , RREQ );
E 10
I 10
	    t = rvalue(e, NLNIL , RREQ );
E 10
	    codeon();
	    if (t == NIL) {
		return csetp -> comptime;
	    }
		/*
		 * The type of the set, settype, is
		 * deemed to be a set of the base type
		 * of t, which we call exptype.  If,
		 * however, this would involve a
		 * "set of integer", we cop out
		 * and use "intset"'s current scoped
		 * type instead.
		 */
	    if (isa(t, "r")) {
		    error("Sets may not have 'real' elements");
		    return csetp -> comptime;
	    }
	    if (isnta(t, "bcsi")) {
		    error("Set elements must be scalars, not %ss", nameof(t));
		    return csetp -> comptime;
	    }
	    if (isa(t, "i")) {
D 10
		    settype = lookup(intset);
E 10
I 10
		    settype = lookup((char *) intset);
E 10
		    if (settype == NIL)
			    panic("intset");
		    settype = settype->type;
		    if (settype == NIL)
			    return csetp -> comptime;
		    if (isnta(settype, "t")) {
			    error("Set default type \"intset\" is not a set");
			    return csetp -> comptime;
		    }
		    exptype = settype->type;
			/*
			 *	say we are doing an intset
			 *	but, if we get out of range errors for intset
			 *	we punt constructing the set at	compile time.
			 */
		    setofint = TRUE;
	    } else {
			exptype = t->type;
			if (exptype == NIL)
				return csetp -> comptime;
			if (exptype->class != RANGE)
				exptype = exptype->type;
D 10
			settype = defnl(0, SET, exptype, 0);
E 10
I 10
			settype = defnl((char *) 0, SET, exptype, 0);
E 10
	    }
	}
	csetp -> csettype = settype;
I 4
#	ifndef CONSETS
	    csetp -> comptime = FALSE;
#	endif CONSETS
E 4
	setran( exptype );
I 4
	if (((set.uprbp + 1) >> LG2BITSLONG) >= COMPSETSZE)
		csetp -> comptime = FALSE;
E 4
	lower = set.lwrb;
	upper = set.lwrb + set.uprbp;
	pairp = NIL;
	singp = NIL;
	codeoff();
D 10
	while ( el = r[2] ) {
		e = el[1];
E 10
I 10
	while ( el = r->cset_node.el_list ) {
		e = el->list_node.list;
E 10
		if (e == NIL) {
			    /*
			     *	don't hang this one anywhere.
			     */
			csetp -> csettype = NIL;
D 10
			r[2] = el[2];
E 10
I 10
			r->cset_node.el_list = el->list_node.next;
E 10
			continue;
		}
D 10
		if (e[0] == T_RANG) {
			if ( csetp -> comptime && constval( e[2] ) ) {
E 10
I 10
		if (e->tag == T_RANG) {
			if ( csetp -> comptime && constval( e->rang.expr2 ) ) {
E 10
I 4
#ifdef CONSETS
E 4
			    t = con.ctype;
D 4
			    if ( ((long)con.crval) < lower || ((long)con.crval) > upper ) {
E 4
I 4
			    if ( con.crval < lower || con.crval > upper ) {
E 4
				if ( setofint ) {
				    csetp -> comptime = FALSE;
				} else {
D 4
				    error("Range upper bound of %d out of set bounds" , ((long)con.crval) );
E 4
I 4
				    error("Range upper bound of %D out of set bounds" , ((long)con.crval) );
E 4
				    csetp -> csettype = NIL;
				}
			    }
D 4
			    rangeupper = ((long)con.crval);
E 4
I 4
#endif CONSETS
E 4
			} else {
			    csetp -> comptime = FALSE;
D 10
			    t = rvalue(e[2], NIL , RREQ );
E 10
I 10
			    t = rvalue(e->rang.expr2, NLNIL , RREQ );
E 10
			    if (t == NIL) {
D 10
				    rvalue(e[1], NIL , RREQ );
E 10
I 10
				    (void) rvalue(e->rang.expr1, NLNIL , RREQ );
E 10
				    goto pairhang;
			    }
			}
D 10
			if (incompat(t, exptype, e[2])) {
E 10
I 10
			if (incompat(t, exptype, e->rang.expr2)) {
E 10
				cerror("Upper bound of element type clashed with set type in constant set");
			}
D 10
			if ( csetp -> comptime && constval( e[1] ) ) {
E 10
I 10
			if ( csetp -> comptime && constval( e->rang.expr1 ) ) {
E 10
I 4
#ifdef CONSETS
E 4
			    t = con.ctype;
D 4
			    if ( ((long)con.crval) < lower || ((long)con.crval) > upper ) {
E 4
I 4
			    if ( con.crval < lower || con.crval > upper ) {
E 4
				if ( setofint ) {
				    csetp -> comptime = FALSE;
				} else {
D 4
				    error("Range lower bound of %d out of set bounds" , ((long)con.crval) );
E 4
I 4
				    error("Range lower bound of %D out of set bounds" , ((long)con.crval) );
E 4
				    csetp -> csettype = NIL;
				}
			    }
I 4
#endif CONSETS
E 4
			} else {
			    csetp -> comptime = FALSE;
D 10
			    t = rvalue(e[1], NIL , RREQ );
E 10
I 10
			    t = rvalue(e->rang.expr1, NLNIL , RREQ );
E 10
			    if (t == NIL) {
				    goto pairhang;
			    }
			}
D 10
			if (incompat(t, exptype, e[1])) {
E 10
I 10
			if (incompat(t, exptype, e->rang.expr1)) {
E 10
				cerror("Lower bound of element type clashed with set type in constant set");
			}
pairhang:
			    /*
			     *	remove this range from the tree list and 
			     *	hang it on the pairs list.
			     */
D 10
			ip = el[2];
			el[2] = pairp;
			pairp = r[2];
			r[2] = ip;
E 10
I 10
			ip = el->list_node.next;
			el->list_node.next = pairp;
			pairp = r->cset_node.el_list;
			r->cset_node.el_list = ip;
E 10
			csetp -> paircnt++;
		} else {
			if ( csetp -> comptime && constval( e ) ) {
I 4
#ifdef CONSETS
E 4
			    t = con.ctype;
D 4
			    if ( ((long)con.crval) < lower || ((long)con.crval) > upper ) {
E 4
I 4
			    if ( con.crval < lower || con.crval > upper ) {
E 4
				if ( setofint ) {
				    csetp -> comptime = FALSE;
				} else {
D 4
				    error("Value of %d out of set bounds" , ((long)con.crval) );
E 4
I 4
				    error("Value of %D out of set bounds" , ((long)con.crval) );
E 4
				    csetp -> csettype = NIL;
				}
			    }
I 4
#endif CONSETS
E 4
			} else {
			    csetp -> comptime = FALSE;
D 10
			    t = rvalue((int *) e, NLNIL , RREQ );
E 10
I 10
			    t = rvalue( e, NLNIL , RREQ );
E 10
			    if (t == NIL) {
				    goto singhang;
			    }
			}
			if (incompat(t, exptype, e)) {
				cerror("Element type clashed with set type in constant set");
			}
singhang:
			    /*
			     *	take this expression off the tree list and
			     *	hang it on the list of singletons.
			     */
D 10
			ip = el[2];
			el[2] = singp;
			singp = r[2];
			r[2] = ip;
E 10
I 10
			ip = el->list_node.next;
			el->list_node.next = singp;
			singp = r->cset_node.el_list;
			r->cset_node.el_list = ip;
E 10
			csetp -> singcnt++;
		}
	}
	codeon();
#	ifdef PC
	    if ( pairp != NIL ) {
D 10
		for ( el = pairp ; el[2] != NIL ; el = el[2] ) /* void */;
		el[2] = singp;
		r[2] = pairp;
E 10
I 10
		for ( el = pairp ; el->list_node.next != NIL ; el = el->list_node.next ) /* void */;
		el->list_node.next = singp;
		r->cset_node.el_list = pairp;
E 10
	    } else {
D 10
		r[2] = singp;
E 10
I 10
		r->cset_node.el_list = singp;
E 10
	    }
#	endif PC
#	ifdef OBJ
	    if ( singp != NIL ) {
D 10
		for ( el = singp ; el[2] != NIL ; el = el[2] ) /* void */;
		el[2] = pairp;
		r[2] = singp;
E 10
I 10
		for ( el = singp ; el->list_node.next != NIL ; el = el->list_node.next ) /* void */;
		el->list_node.next = pairp;
		r->cset_node.el_list = singp;
E 10
	    } else {
D 10
		r[2] = pairp;
E 10
I 10
		r->cset_node.el_list = pairp;
E 10
	    }
#	endif OBJ
	if ( csetp -> csettype == NIL ) {
	    csetp -> comptime = TRUE;
	}
	return csetp -> comptime;
}

D 4
#define	BITSPERLONG	( sizeof( long ) * BITSPERBYTE )
E 4
I 4
#ifdef CONSETS
E 4
    /*
     *	mask[i] has the low i bits turned off.
     */
long	mask[] = {	
I 4
#		ifdef DEC11
E 4
		    0xffffffff , 0xfffffffe , 0xfffffffc , 0xfffffff8 ,
		    0xfffffff0 , 0xffffffe0 , 0xffffffc0 , 0xffffff80 ,
		    0xffffff00 , 0xfffffe00 , 0xfffffc00 , 0xfffff800 ,
		    0xfffff000 , 0xffffe000 , 0xffffc000 , 0xffff8000 ,
		    0xffff0000 , 0xfffe0000 , 0xfffc0000 , 0xfff80000 ,
		    0xfff00000 , 0xffe00000 , 0xffc00000 , 0xff800000 ,
		    0xff000000 , 0xfe000000 , 0xfc000000 , 0xf8000000 ,
		    0xf0000000 , 0xe0000000 , 0xc0000000 , 0x80000000 ,
		    0x00000000
D 4
		 };
E 4
I 4
#		else
		    0xffffffff , 0xfeffffff , 0xfcffffff , 0xf8ffffff ,
		    0xf0ffffff , 0xe0ffffff , 0xc0ffffff , 0x80ffffff ,
		    0x00ffffff , 0x00feffff , 0x00fcffff , 0x00f8ffff ,
		    0x00f0ffff , 0x00e0ffff , 0x00c0ffff , 0x0080ffff ,
		    0x0000ffff , 0x0000feff , 0x0000fcff , 0x0000f8ff ,
		    0x0000f0ff , 0x0000e0ff , 0x0000c0ff , 0x000080ff ,
		    0x000000ff , 0x000000fe , 0x000000fc , 0x000000f8 ,
		    0x000000f0 , 0x000000e0 , 0x000000c0 , 0x00000080 ,
		    0x00000000
#		endif DEC11
	    };
E 4
    /*
     *	given a csetstr, either
     *	    put out a compile time constant set and an lvalue to it.
     *	or
     *	    put out rvalues for the singletons and the pairs
     *	    and counts of each.
     */
I 4
#endif CONSETS
E 4
postcset( r , csetp )
D 10
    int			*r;
E 10
I 10
    struct tnode	*r;
E 10
    struct csetstr	*csetp;
    {
D 10
	register int	*el;
	register int	*e;
E 10
I 10
	register struct tnode	*el;
	register struct tnode	*e;
E 10
	int		lower;
	int		upper;
	int		lowerdiv;
	int		lowermod;
	int		upperdiv;
	int		uppermod;
D 10
	int		label;
E 10
	long		*lp;
	long		*limit;
D 4
	long		tempset[ ( MAXSET / BITSPERLONG ) + 1 ];
E 4
I 4
	long		tempset[ COMPSETSZE ];
E 4
	long		temp;
D 4
	char		labelname[ BUFSIZ ];
E 4
I 4
	char		*cp;
#	ifdef PC
I 10
	    int		label;
E 10
	    char	labelname[ BUFSIZ ];
#	endif PC
E 4

	if ( csetp -> comptime ) {
I 4
#ifdef CONSETS
E 4
D 2
	    if ( csetp -> csettype == nl + TSET ) {
		return;
	    }
E 2
	    setran( ( csetp -> csettype ) -> type );
D 4
	    limit = &tempset[ ( set.uprbp / BITSPERLONG ) + 1 ];
E 4
I 4
	    limit = &tempset[ ( set.uprbp >> LG2BITSLONG ) + 1 ];
E 4
	    for ( lp = &tempset[0] ; lp < limit ; lp++ ) {
		*lp = 0;
	    }
D 10
	    for ( el = r[2] ; el != NIL ; el = el[2] ) {
		e = el[1];
		if ( e[0] == T_RANG ) {
		    constval( e[1] );
E 10
I 10
	    for ( el = r->cset_node.el_list ; el != NIL ; el = el->list_node.next ) {
		e = el->list_node.list;
		if ( e->tag == T_RANG ) {
		    (void) constval( e->rang.expr1 );
E 10
D 4
		    lower = (long) con.crval;
E 4
I 4
		    lower = con.crval;
E 4
D 10
		    constval( e[2] );
E 10
I 10
		    (void) constval( e->rang.expr2 );
E 10
D 4
		    upper = (long) con.crval;
E 4
I 4
		    upper = con.crval;
E 4
		    if ( upper < lower ) {
			continue;
		    }
D 4
		    lowerdiv = ( lower - set.lwrb ) / BITSPERLONG;
		    lowermod = ( lower - set.lwrb ) % BITSPERLONG;
		    upperdiv = ( upper - set.lwrb ) / BITSPERLONG;
		    uppermod = ( upper - set.lwrb ) % BITSPERLONG;
E 4
I 4
		    lowerdiv = ( lower - set.lwrb ) >> LG2BITSLONG;
		    lowermod = ( lower - set.lwrb ) & MSKBITSLONG;
		    upperdiv = ( upper - set.lwrb ) >> LG2BITSLONG;
		    uppermod = ( upper - set.lwrb ) & MSKBITSLONG;
E 4
		    temp = mask[ lowermod ];
		    if ( lowerdiv == upperdiv ) {
			temp &= ~mask[ uppermod + 1 ];
		    }
		    tempset[ lowerdiv ] |= temp;
		    limit = &tempset[ upperdiv-1 ];
		    for ( lp = &tempset[ lowerdiv+1 ] ; lp <= limit ; lp++ ) {
D 4
			*lp |= ~0;
E 4
I 4
			*lp |= 0xffffffff;
E 4
		    }
		    if ( lowerdiv != upperdiv ) {
			tempset[ upperdiv ] |= ~mask[ uppermod + 1 ];
		    }
		} else {
D 10
		    constval( e );
E 10
I 10
		    (void) constval( e );
E 10
D 4
		    lowerdiv = ( ((long)con.crval) - set.lwrb ) / BITSPERLONG;
		    lowermod = ( ((long)con.crval) - set.lwrb ) % BITSPERLONG;
		    tempset[ lowerdiv ] |= ( 1 << lowermod );
E 4
I 4
		    temp = con.crval - set.lwrb;
		    cp = (char *)tempset;
		    cp[temp >> LG2BITSBYTE] |= (1 << (temp & MSKBITSBYTE));
E 4
		}
	    }
D 6
	    if ( cgenflg )
E 6
I 6
	    if ( !CGENNING )
E 6
		return;
#	    ifdef PC
D 7
		putprintf( "	.data" , 0 );
		putprintf( "	.align 2" , 0 );
E 7
D 10
		label = getlab();
E 10
I 10
		label = (int) getlab();
E 10
I 7
		putprintf("	.data" , 0 );
		aligndot(A_SET);
E 7
D 10
		putlab( label );
E 10
I 10
		(void) putlab( (char *) label );
E 10
		lp = &( tempset[0] );
D 4
		limit = &tempset[ ( set.uprbp / BITSPERLONG ) + 1 ];
E 4
I 4
		limit = &tempset[ ( set.uprbp >> LG2BITSLONG ) + 1 ];
E 4
D 7
		while ( lp < limit ) {
		    putprintf( "	.long	0x%x" , 1 , *lp ++ );
		    for ( temp = 2 ; ( temp <= 8 ) && lp < limit ; temp ++ ) {
			putprintf( ",0x%x" , 1 , *lp++ );
E 7
I 7
		while (lp < limit) {
D 10
		    putprintf("	.long	0x%x", 1, *lp++);
E 10
I 10
		    putprintf("	.long	0x%x", 1, (int) (*lp++));
E 10
		    for (temp = 2 ; temp <= 8 && lp < limit ; temp++) {
D 10
			putprintf(",0x%x", 1, *lp++);
E 10
I 10
			putprintf(",0x%x", 1, (int) (*lp++));
E 10
E 7
		    }
D 7
		    putprintf( "" , 0 );
E 7
I 7
		    putprintf("", 0);
E 7
		}
D 7
		putprintf( "	.text" , 0 );
E 7
I 7
		putprintf("	.text", 0);
E 7
D 10
		sprintf( labelname , PREFIXFORMAT , LABELPREFIX , label );
E 10
I 10
		sprintf( labelname , PREFIXFORMAT , LABELPREFIX , (char *) label );
E 10
D 12
		putleaf( P2ICON , 0 , 0 , P2PTR | P2STRTY , labelname );
E 12
I 12
		putleaf( PCC_ICON , 0 , 0 , PCCTM_PTR | PCCT_STRTY , labelname );
E 12
#	    endif PC
#	    ifdef OBJ
D 4
		put( 2, O_CON, (set.uprbp / BITSPERLONG + 1) *
				 (BITSPERLONG / BITSPERBYTE));
E 4
I 4
D 10
		put(2, O_CON, (int)(((set.uprbp >> LG2BITSLONG) + 1) *
E 10
I 10
		(void) put(2, O_CON, (int)(((set.uprbp >> LG2BITSLONG) + 1) *
E 10
				 (BITSPERLONG >> LG2BITSBYTE)));
E 4
		lp = &( tempset[0] );
D 4
		limit = &tempset[ ( set.uprbp / BITSPERLONG ) + 1 ];
E 4
I 4
		limit = &tempset[ ( set.uprbp >> LG2BITSLONG ) + 1 ];
E 4
		while ( lp < limit ) {
D 4
		    put( 2, O_CASE4, *lp ++);
E 4
I 4
D 10
		    put(2, O_CASE4, *lp ++);
E 10
I 10
		    (void) put(2, O_CASE4, (int) (*lp ++));
E 10
E 4
		}
#	    endif OBJ
I 4
#else
		panic("const cset");
#endif CONSETS
E 4
	} else {
#	    ifdef PC
D 10
		putleaf( P2ICON , csetp -> paircnt , 0 , P2INT , 0 );
E 10
I 10
D 12
		putleaf( P2ICON , (int) csetp -> paircnt , 0 , P2INT , (char *) 0 );
E 10
		putop( P2LISTOP , P2INT );
D 10
		putleaf( P2ICON , csetp -> singcnt , 0 , P2INT , 0 );
E 10
I 10
		putleaf( P2ICON , (int) csetp -> singcnt , 0 , P2INT , (char *) 0 );
E 10
		putop( P2LISTOP , P2INT );
E 12
I 12
		putleaf( PCC_ICON , (int) csetp -> paircnt , 0 , PCCT_INT , (char *) 0 );
		putop( PCC_CM , PCCT_INT );
		putleaf( PCC_ICON , (int) csetp -> singcnt , 0 , PCCT_INT , (char *) 0 );
		putop( PCC_CM , PCCT_INT );
E 12
D 10
		for ( el = r[2] ; el != NIL ; el = el[2] ) {
		    e = el[1];
		    if ( e[0] == T_RANG ) {
			rvalue( e[2] , NIL , RREQ );
E 10
I 10
		for ( el = r->cset_node.el_list ; el != NIL ; el = el->list_node.next ) {
		    e = el->list_node.list;
		    if ( e->tag == T_RANG ) {
			(void) rvalue( e->rang.expr2 , NLNIL , RREQ );
E 10
D 12
			putop( P2LISTOP , P2INT );
E 12
I 12
			putop( PCC_CM , PCCT_INT );
E 12
D 10
			rvalue( e[1] , NIL , RREQ );
E 10
I 10
			(void) rvalue( e->rang.expr1 , NLNIL , RREQ );
E 10
D 12
			putop( P2LISTOP , P2INT );
E 12
I 12
			putop( PCC_CM , PCCT_INT );
E 12
		    } else {
D 10
			rvalue( e , NIL , RREQ );
E 10
I 10
			(void) rvalue( e , NLNIL , RREQ );
E 10
D 12
			putop( P2LISTOP , P2INT );
E 12
I 12
			putop( PCC_CM , PCCT_INT );
E 12
		    }
		}
#	    endif PC
#	    ifdef OBJ
D 10
		for ( el = r[2] ; el != NIL ; el = el[2] ) {
		    e = el[1];
		    if ( e[0] == T_RANG ) {
D 3
			stkrval( e[2] , NIL , RREQ );
E 3
			stkrval( e[1] , NIL , RREQ );
I 3
			stkrval( e[2] , NIL , RREQ );
E 10
I 10
		for ( el = r->cset_node.el_list ; el != NIL ; el = el->list_node.next ) {
		    e = el->list_node.list;
		    if ( e->tag == T_RANG ) {
			(void) stkrval( e->rang.expr1 , NLNIL , (long) RREQ );
			(void) stkrval( e->rang.expr2 , NLNIL , (long) RREQ );
E 10
E 3
		    } else {
D 10
			stkrval( e , NIL , RREQ );
E 10
I 10
			(void) stkrval( e , NLNIL , (long) RREQ );
E 10
		    }
		}
D 4
		put( 2 , O_CON24 , csetp -> singcnt );
		put( 2 , O_CON24 , csetp -> paircnt );
E 4
I 4
D 10
		put(2 , O_CON24 , (int)csetp -> singcnt );
		put(2 , O_CON24 , (int)csetp -> paircnt );
E 10
I 10
		(void) put(2 , O_CON24 , (int)csetp -> singcnt );
		(void) put(2 , O_CON24 , (int)csetp -> paircnt );
E 10
E 4
#	    endif OBJ
	}
}
E 1
