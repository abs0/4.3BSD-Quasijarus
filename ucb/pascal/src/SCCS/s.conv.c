h64018
s 00007/00003/00365
d D 5.1 85/06/05 14:02:23 dist 12 11
c Add copyright
e
s 00016/00016/00352
d D 2.2 85/03/20 14:59:26 ralph 11 10
c changes from donn@utah-cs for common header file for pcc
e
s 00000/00000/00368
d D 2.1 84/02/08 20:41:18 aoki 10 9
c synchronize to version 2
e
s 00019/00001/00349
d D 1.7 84/02/08 00:39:11 mckusick 9 8
c merge in conformant array code by Carol Nishizak
e
s 00000/00000/00350
d D 1.6 83/09/19 06:57:53 thien 8 7
c Restoring to unlinted version
e
s 00033/00021/00317
d D 1.5 83/08/19 04:56:04 thien 7 6
c The changes were made to allow successful linting
e
s 00000/00000/00338
d D 1.4 83/01/17 14:27:05 peter 6 3
i 5 4
c merge 1.3 and 1.2.1.
e
s 00002/00008/00332
d D 1.2.1.2 83/01/17 14:25:44 peter 5 4
c port to the mc68000 (cleaning up after ourselves).
e
s 00000/00000/00340
d D 1.2.1.1 83/01/17 14:24:01 peter 4 2
c branch-place-holder
e
s 00034/00030/00310
d D 1.3 83/01/17 14:05:07 peter 3 2
c put in explicit scalar converts (sconv's) to make less code-generator dependent.
e
s 00005/00005/00335
d D 1.2 81/03/08 19:24:08 mckusic 2 1
c merge in onyx changes
e
s 00340/00000/00000
d D 1.1 80/08/27 19:54:50 peter 1 0
c date and time created 80/08/27 19:54:50 by peter
e
u
U
f b 
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

I 7
#ifndef lint
E 7
D 2
static	char sccsid[] = "%Z%%M% %I% %G%";
E 2
I 2
D 12
static char sccsid[] = "%Z%%M% %I% %G%";
I 7
#endif
E 12
I 12
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 12
E 7
E 2

#include "whoami.h"
#ifdef PI
#include "0.h"
#include "opcode.h"
#ifdef PC
D 11
#   include	"pcops.h"
E 11
I 11
#   include	<pcc.h>
E 11
#endif PC
I 7
#include "tree_ty.h"
E 7

I 7
#ifndef PC
E 7
#ifndef PI0
/*
 * Convert a p1 into a p2.
 * Mostly used for different
 * length integers and "to real" conversions.
 */
convert(p1, p2)
	struct nl *p1, *p2;
{
D 7
	if (p1 == NIL || p2 == NIL)
E 7
I 7
	if (p1 == NLNIL || p2 == NLNIL)
E 7
		return;
	switch (width(p1) - width(p2)) {
		case -7:
		case -6:
D 2
			put1(O_STOD);
E 2
I 2
D 7
			put(1, O_STOD);
E 7
I 7
			(void) put(1, O_STOD);
E 7
E 2
			return;
		case -4:
D 2
			put1(O_ITOD);
E 2
I 2
D 7
			put(1, O_ITOD);
E 7
I 7
			(void) put(1, O_ITOD);
E 7
E 2
			return;
		case -3:
		case -2:
D 2
			put1(O_STOI);
E 2
I 2
D 7
			put(1, O_STOI);
E 7
I 7
			(void) put(1, O_STOI);
E 7
E 2
			return;
		case -1:
		case 0:
		case 1:
			return;
		case 2:
		case 3:
D 2
			put1(O_ITOS);
E 2
I 2
D 7
			put(1, O_ITOS);
E 7
I 7
			(void) put(1, O_ITOS);
E 7
E 2
			return;
		default:
			panic("convert");
	}
}
D 7
#endif
E 7
I 7
#endif 
#endif PC
E 7

/*
 * Compat tells whether
 * p1 and p2 are compatible
 * types for an assignment like
 * context, i.e. value parameters,
 * indicies for 'in', etc.
 */
compat(p1, p2, t)
	struct nl *p1, *p2;
I 7
	struct tnode *t;
E 7
{
	register c1, c2;

	c1 = classify(p1);
	if (c1 == NIL)
		return (NIL);
	c2 = classify(p2);
	if (c2 == NIL)
		return (NIL);
	switch (c1) {
		case TBOOL:
		case TCHAR:
			if (c1 == c2)
				return (1);
			break;
		case TINT:
			if (c2 == TINT)
				return (1);
		case TDOUBLE:
			if (c2 == TDOUBLE)
				return (1);
#ifndef PI0
D 7
			if (c2 == TINT && divflg == 0 && t != NIL ) {
				divchk= 1;
E 7
I 7
			if (c2 == TINT && divflg == FALSE && t != TR_NIL ) {
				divchk= TRUE;
E 7
				c1 = classify(rvalue(t, NLNIL , RREQ ));
D 7
				divchk = NIL;
E 7
I 7
				divchk = FALSE;
E 7
				if (c1 == TINT) {
					error("Type clash: real is incompatible with integer");
					cerror("This resulted because you used '/' which always returns real rather");
					cerror("than 'div' which divides integers and returns integers");
D 7
					divflg = 1;
E 7
I 7
					divflg = TRUE;
E 7
					return (NIL);
				}
			}
#endif
			break;
		case TSCAL:
			if (c2 != TSCAL)
				break;
			if (scalar(p1) != scalar(p2)) {
				derror("Type clash: non-identical scalar types");
				return (NIL);
			}
			return (1);
		case TSTR:
			if (c2 != TSTR)
				break;
			if (width(p1) != width(p2)) {
				derror("Type clash: unequal length strings");
				return (NIL);
			}
			return (1);
		case TNIL:
			if (c2 != TPTR)
				break;
			return (1);
		case TFILE:
			if (c1 != c2)
				break;
			derror("Type clash: files not allowed in this context");
			return (NIL);
		default:
			if (c1 != c2)
				break;
			if (p1 != p2) {
				derror("Type clash: non-identical %s types", clnames[c1]);
				return (NIL);
			}
			if (p1->nl_flags & NFILES) {
				derror("Type clash: %ss with file components not allowed in this context", clnames[c1]);
				return (NIL);
			}
			return (1);
	}
	derror("Type clash: %s is incompatible with %s", clnames[c1], clnames[c2]);
	return (NIL);
}

#ifndef PI0
I 7
#ifndef PC
E 7
/*
 * Rangechk generates code to
 * check if the type p on top
 * of the stack is in range for
 * assignment to a variable
 * of type q.
 */
rangechk(p, q)
	struct nl *p, *q;
{
	register struct nl *rp;
I 7
#ifdef OBJ
E 7
	register op;
	int wq, wrp;
I 7
#endif
E 7

	if (opt('t') == 0)
		return;
	rp = p;
	if (rp == NIL)
		return;
	if (q == NIL)
		return;
#	ifdef OBJ
	    /*
	     * When op is 1 we are checking length
	     * 4 numbers against length 2 bounds,
	     * and adding it to the opcode forces
	     * generation of appropriate tests.
	     */
	    op = 0;
	    wq = width(q);
	    wrp = width(rp);
	    op = wq != wrp && (wq == 4 || wrp == 4);
D 9
	    if (rp->class == TYPE)
E 9
I 9
	    if (rp->class == TYPE || rp->class == CRANGE)
E 9
		    rp = rp->type;
	    switch (rp->class) {
	    case RANGE:
		    if (rp->range[0] != 0) {
#    		    ifndef DEBUG
			    if (wrp <= 2)
D 7
				    put(3, O_RANG2+op, ( short ) rp->range[0],
E 7
I 7
				    (void) put(3, O_RANG2+op, ( short ) rp->range[0],
E 7
						     ( short ) rp->range[1]);
			    else if (rp != nl+T4INT)
D 7
				    put(3, O_RANG4+op, rp->range[0], rp->range[1] );
E 7
I 7
				    (void) put(3, O_RANG4+op, rp->range[0], rp->range[1] );
E 7
#    		    else
			    if (!hp21mx) {
				    if (wrp <= 2)
D 7
					    put(3, O_RANG2+op,( short ) rp->range[0],
E 7
I 7
					    (void) put(3, O_RANG2+op,( short ) rp->range[0],
E 7
							    ( short ) rp->range[1]);
				    else if (rp != nl+T4INT)
D 7
					    put(3, O_RANG4+op,rp->range[0],
E 7
I 7
					    (void) put(3, O_RANG4+op,rp->range[0],
E 7
							     rp->range[1]);
			    } else
				    if (rp != nl+T2INT && rp != nl+T4INT)
D 7
					    put(3, O_RANG2+op,( short ) rp->range[0],
E 7
I 7
					    (void) put(3, O_RANG2+op,( short ) rp->range[0],
E 7
							    ( short ) rp->range[1]);
#    		    endif
			break;
		    }
		    /*
		     * Range whose lower bounds are
		     * zero can be treated as scalars.
		     */
	    case SCAL:
		    if (wrp <= 2)
D 7
			    put(2, O_RSNG2+op, ( short ) rp->range[1]);
E 7
I 7
			    (void) put(2, O_RSNG2+op, ( short ) rp->range[1]);
E 7
		    else
D 7
			    put( 2 , O_RSNG4+op, rp->range[1]);
E 7
I 7
			    (void) put( 2 , O_RSNG4+op, rp->range[1]);
E 7
		    break;
	    default:
		    panic("rangechk");
	    }
#	endif OBJ
#	ifdef PC
		/*
D 5
		 * what i want to do is make this and some other stuff
		 * arguments to a function call, which will do the rangecheck,
		 * and return the value of the current expression, or abort
		 * if the rangecheck fails.
		 * probably i need one rangecheck routine to return each c-type
		 * of value.
		 * also, i haven't figured out what the `other stuff' is.
E 5
I 5
		 *	pc uses precheck() and postcheck().
E 5
		 */
D 5
	    putprintf( "#	call rangecheck" , 0 );
E 5
I 5
	    panic("rangechk()");
E 5
#	endif PC
}
#endif
#endif
I 7
#endif
E 7

#ifdef PC
    /*
     *	if type p requires a range check,
     *	    then put out the name of the checking function
     *	for the beginning of a function call which is completed by postcheck.
     *  (name1 is for a full check; name2 assumes a lower bound of zero)
     */
precheck( p , name1 , name2 )
    struct nl	*p;
    char	*name1 , *name2;
    {

	if ( opt( 't' ) == 0 ) {
	    return;
	}
	if ( p == NIL ) {
	    return;
	}
	if ( p -> class == TYPE ) {
	    p = p -> type;
	}
	switch ( p -> class ) {
I 9
	    case CRANGE:
D 11
		putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
E 11
I 11
		putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 11
			    , name1);
		break;
E 9
	    case RANGE:
		if ( p != nl + T4INT ) {
D 3
		    putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
			    , p -> range[0] != 0 ? name1 : name2 );
E 3
I 3
D 11
		    putleaf( P2ICON , 0 , 0 ,
			    ADDTYPE( P2FTN | P2INT , P2PTR ),
E 11
I 11
		    putleaf( PCC_ICON , 0 , 0 ,
			    PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR ),
E 11
			    p -> range[0] != 0 ? name1 : name2 );
E 3
		}
		break;
	    case SCAL:
		    /*
		     *	how could a scalar ever be out of range?
		     */
		break;
	    default:
		panic( "precheck" );
		break;
	}
    }

    /*
     *	if type p requires a range check,
     *	    then put out the rest of the arguments of to the checking function
     *	a call to which was started by precheck.
     *	the first argument is what is being rangechecked (put out by rvalue),
     *	the second argument is the lower bound of the range,
     *	the third argument is the upper bound of the range.
     */
D 3
postcheck( p )
    struct nl	*p;
    {
E 3
I 3
postcheck(need, have)
    struct nl	*need;
    struct nl	*have;
{
I 9
    struct nl	*p;
E 9
E 3

D 3
	if ( opt( 't' ) == 0 ) {
	    return;
	}
	if ( p == NIL ) {
	    return;
	}
	if ( p -> class == TYPE ) {
	    p = p -> type;
	}
	switch ( p -> class ) {
	    case RANGE:
		if ( p != nl + T4INT ) {
		    if (p -> range[0] != 0 ) {
			putleaf( P2ICON , p -> range[0] , 0 , P2INT , 0 );
			putop( P2LISTOP , P2INT );
		    }
		    putleaf( P2ICON , p -> range[1] , 0 , P2INT , 0 );
E 3
I 3
    if ( opt( 't' ) == 0 ) {
	return;
    }
    if ( need == NIL ) {
	return;
    }
    if ( need -> class == TYPE ) {
	need = need -> type;
    }
    switch ( need -> class ) {
	case RANGE:
	    if ( need != nl + T4INT ) {
D 11
		sconv(p2type(have), P2INT);
E 11
I 11
		sconv(p2type(have), PCCT_INT);
E 11
		if (need -> range[0] != 0 ) {
D 7
		    putleaf( P2ICON , need -> range[0] , 0 , P2INT , 0 );
E 7
I 7
D 11
		    putleaf( P2ICON , (int) need -> range[0] , 0 , P2INT ,
E 11
I 11
		    putleaf( PCC_ICON , (int) need -> range[0] , 0 , PCCT_INT ,
E 11
							(char *) 0 );
E 7
E 3
D 11
		    putop( P2LISTOP , P2INT );
E 11
I 11
		    putop( PCC_CM , PCCT_INT );
E 11
D 3
		    putop( P2CALL , P2INT );
E 3
		}
D 3
		break;
	    case SCAL:
		break;
	    default:
		panic( "postcheck" );
		break;
	}
E 3
I 3
D 7
		putleaf( P2ICON , need -> range[1] , 0 , P2INT , 0 );
E 7
I 7
D 11
		putleaf( P2ICON , (int) need -> range[1] , 0 , P2INT ,
E 11
I 11
		putleaf( PCC_ICON , (int) need -> range[1] , 0 , PCCT_INT ,
E 11
				(char *) 0 );
E 7
D 11
		putop( P2LISTOP , P2INT );
		putop( P2CALL , P2INT );
		sconv(P2INT, p2type(have));
E 11
I 11
		putop( PCC_CM , PCCT_INT );
		putop( PCC_CALL , PCCT_INT );
		sconv(PCCT_INT, p2type(have));
E 11
	    }
I 9
	    break;
	case CRANGE:
D 11
	    sconv(p2type(have), P2INT);
E 11
I 11
	    sconv(p2type(have), PCCT_INT);
E 11
	    p = need->nptr[0];
	    putRV(p->symbol, (p->nl_block & 037), p->value[0],
		    p->extra_flags, p2type( p ) );
D 11
	    putop( P2LISTOP , P2INT );
E 11
I 11
	    putop( PCC_CM , PCCT_INT );
E 11
	    p = need->nptr[1];
	    putRV(p->symbol, (p->nl_block & 037), p->value[0],
		    p->extra_flags, p2type( p ) );
D 11
	    putop( P2LISTOP , P2INT );
	    putop( P2CALL , P2INT );
	    sconv(P2INT, p2type(have));
E 11
I 11
	    putop( PCC_CM , PCCT_INT );
	    putop( PCC_CALL , PCCT_INT );
	    sconv(PCCT_INT, p2type(have));
E 11
E 9
	    break;
	case SCAL:
	    break;
	default:
	    panic( "postcheck" );
	    break;
E 3
    }
I 3
}
E 3
#endif PC

#ifdef DEBUG
conv(dub)
	int *dub;
{
	int newfp[2];
D 7
	double *dp = dub;
	long *lp = dub;
E 7
I 7
	double *dp = ((double *) dub);
	long *lp = ((long *) dub);
E 7
	register int exp;
	long mant;

	newfp[0] = dub[0] & 0100000;
	newfp[1] = 0;
	if (*dp == 0.0)
		goto ret;
	exp = ((dub[0] >> 7) & 0377) - 0200;
	if (exp < 0) {
		newfp[1] = 1;
		exp = -exp;
	}
	if (exp > 63)
		exp = 63;
	dub[0] &= ~0177600;
	dub[0] |= 0200;
	mant = *lp;
	mant <<= 8;
	if (newfp[0])
		mant = -mant;
	newfp[0] |= (mant >> 17) & 077777;
	newfp[1] |= (((int) (mant >> 1)) & 0177400) | (exp << 1);
ret:
	dub[0] = newfp[0];
	dub[1] = newfp[1];
}
#endif
E 1
