h23299
s 00002/00002/00471
d D 5.4 86/11/12 10:30:02 mckusick 27 26
c add CCI (tahoe) support
e
s 00000/00021/00473
d D 5.3 86/11/12 10:28:58 mckusick 26 25
c replace `even' and `leven' with explicit rounding
e
s 00001/00001/00493
d D 5.2 85/07/26 16:15:00 mckusick 25 24
c null pointer checks (from ralph)
e
s 00007/00003/00487
d D 5.1 85/06/05 15:04:24 dist 24 23
c Add copyright
e
s 00000/00001/00490
d D 2.3 85/03/20 15:07:55 ralph 23 22
c changes from donn@utah-cs for common header file for pcc
e
s 00001/00003/00490
d D 2.2 85/03/15 22:35:45 mckusick 22 20
i 21
c merge dbx from linton
e
s 00001/00001/00468
d D 1.16.1.1 85/03/15 22:32:19 mckusick 21 16
c new dbx from linton
e
s 00000/00000/00492
d D 2.1 84/02/08 20:47:12 aoki 20 19
c synchronize to version 2
e
s 00010/00000/00482
d D 1.19 84/02/08 00:45:11 mckusick 19 18
c merge in conformant array code by Carol Nishizak
e
s 00000/00002/00482
d D 1.18 83/09/19 07:01:37 thien 18 17
c Restoring to unlinted version
e
s 00032/00017/00452
d D 1.17 83/08/19 05:03:45 thien 17 16
c The changes were made to allow successful linting
e
s 00009/00008/00460
d D 1.16 83/04/01 22:59:45 mckusick 16 15
c alignment of arrays is at least A_STRUCT;
c sets are bulit up by sizeof(long) bytes
e
s 00001/00000/00467
d D 1.15 83/02/28 17:19:37 peter 15 14
c clean up temporary allocation, moving everything relevant to
c tmps.c and (new) tmps.h.  correctly emit LBRAC lines.  allocate registers
c from high to low.  put in data structures for multiple types of registers.
e
s 00041/00022/00426
d D 1.14 83/02/01 21:40:41 peter 14 13
c strings are aligned as structs since we sometimes treat them that way.
c part of the port to the 68000.
e
s 00003/00019/00445
d D 1.13 82/10/19 20:42:18 peter 13 12
c c style alignment of variants within records.
e
s 00017/00005/00447
d D 1.12 82/08/29 14:04:31 peter 12 11
c once-only error messages for multiple/out-of-order declarations.
e
s 00001/00001/00451
d D 1.11 81/07/23 14:47:57 mckusic 11 10
c align temporaries
e
s 00026/00004/00426
d D 1.10 81/07/08 14:17:37 peter 10 9
c replace evening of all variables with selective alignments as needed
e
s 00005/00001/00425
d D 1.9 81/06/01 15:40:11 peter 9 8
c add storage classes to namelist, and use them.
e
s 00003/00003/00423
d D 1.8 81/03/12 11:49:44 mckusic 8 7
c "fix" syntax errors
e
s 00008/00006/00418
d D 1.7 81/03/11 23:44:47 mckusic 7 6
c centralize temporary allocation in tmps.c
e
s 00018/00009/00406
d D 1.6 81/03/08 19:29:09 mckusic 6 5
c merge in onyx changes
e
s 00001/00001/00414
d D 1.5 81/01/15 13:25:01 peter 5 4
c get sdb stabs into the right places.  use nm -ap for details.
e
s 00002/00008/00413
d D 1.4 81/01/06 17:18:08 mckusic 4 3
c modify to allow use of px written in `C' and the use of libpc
e
s 00018/00014/00403
d D 1.3 80/09/02 22:06:21 peter 3 2
c interleaved declaration parts
e
s 00001/00001/00416
d D 1.2 80/08/31 17:31:44 peter 2 1
c stabs for separate compilation type checking
e
s 00417/00000/00000
d D 1.1 80/08/27 19:56:51 peter 1 0
c date and time created 80/08/27 19:56:51 by peter
e
u
U
f b 
t
T
I 1
D 24
/* Copyright (c) 1979 Regents of the University of California */
E 24
I 24
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 24

I 17
#ifndef lint
E 17
D 6
static	char sccsid[] = "%Z%%M% %I% %G%";
E 6
I 6
D 24
static char sccsid[] = "%Z%%M% %I% %G%";
I 17
#endif
E 24
I 24
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 24
E 17
E 6

#include "whoami.h"
#include "0.h"
I 14
#include "objfmt.h"
E 14
#include "align.h"
I 4
#include "iorec.h"
E 4
#ifdef PC
#   include	"pc.h"
D 23
#   include	"pcops.h"
E 23
D 4
#   include	"iorec.h"
E 4
#endif PC
I 15
#include "tmps.h"
I 17
#include "tree_ty.h"
E 17
E 15

/*
 * Declare variables of a var part.  DPOFF1 is
 * the local variable storage for all prog/proc/func
 * modules aside from the block mark.  The total size
 * of all the local variables is entered into the
 * size array.
 */
I 17
/*ARGSUSED*/
E 17
D 12
varbeg()
E 12
I 12
varbeg( lineofyvar , r )
    int	lineofyvar;
E 12
{
I 12
    static bool	var_order = FALSE;
    static bool	var_seen = FALSE;
E 12

D 3
/* PC allows for multiple declaration
E 3
I 3
/* this allows for multiple declaration
E 3
 * parts except when the "standard"
 * option has been specified.
 * If routine segment is being compiled,
 * do level one processing.
 */

#ifndef PI1
D 3
if (!progseen)
	level1();
#ifdef PC
    if (opt('s')) {
	if (parts & VPRT){
E 3
I 3
	if (!progseen)
		level1();
I 12
	line = lineofyvar;
E 12
	if ( parts[ cbn ] & RPRT ) {
	    if ( opt( 's' ) ) {
E 3
		standard();
I 12
		error("Variable declarations should precede routine declarations");
E 12
D 3
		error("All variables must be declared in one var part");
E 3
I 3
	    } else {
D 12
		warning();
E 12
I 12
		if ( !var_order ) {
		    var_order = TRUE;
		    warning();
		    error("Variable declarations should precede routine declarations");
		}
E 12
	    }
D 12
	    error("Variable declarations should precede routine declarations");
E 12
E 3
	}
D 3
    }
#else
	if (parts & VPRT)
		error("All variables must be declared in one var part");
#endif PC

	parts |= VPRT;
E 3
I 3
	if ( parts[ cbn ] & VPRT ) {
	    if ( opt( 's' ) ) {
		standard();
I 12
		error("All variables should be declared in one var part");
E 12
	    } else {
D 12
		warning();
E 12
I 12
		if ( !var_seen ) {
		    var_seen = TRUE;
		    warning();
		    error("All variables should be declared in one var part");
		}
E 12
	    }
D 12
	    error("All variables should be declared in one var part");
E 12
	}
	parts[ cbn ] |= VPRT;
E 3
#endif
    /*
     *  #ifndef PI0
D 7
     *      sizes[cbn].om_max = sizes[cbn].om_off = -DPOFF1;
E 7
I 7
     *      sizes[cbn].om_max = sizes[cbn].curtmps.om_off = -DPOFF1;
E 7
     *  #endif
     */
	forechain = NIL;
#ifdef PI0
	send(REVVBEG);
#endif
}

var(vline, vidl, vtype)
#ifdef PI0
D 17
	int vline, *vidl, *vtype;
E 17
I 17
	int vline;
	struct tnode *vidl, *vtype;
E 17
{
	register struct nl *np;
D 17
	register int *vl;
E 17
I 17
	register struct tnode *vl;
E 17

	np = gtype(vtype);
	line = vline;
D 17
	for (vl = vidl; vl != NIL; vl = vl[2]) {
E 17
I 17
	/* why is this here? */
	for (vl = vidl; vl != TR_NIL; vl = vl->list_node.next) {
E 17
		}
	}
	send(REVVAR, vline, vidl, vtype);
}
#else
	int vline;
D 17
	register int *vidl;
	int *vtype;
E 17
I 17
	register struct tnode *vidl;
	struct tnode *vtype;
E 17
{
	register struct nl *np;
	register struct om *op;
	long w;
	int o2;
D 17
	int *ovidl = vidl;
E 17
I 17
#ifdef PC
E 17
I 9
	struct nl	*vp;
I 17
#endif
E 17
E 9

	np = gtype(vtype);
	line = vline;
D 10
	    /*
	     * widths are evened out
	     */
	w = (lwidth(np) + 1) &~ 1;
E 10
I 10
	w = lwidth(np);
E 10
	op = &sizes[cbn];
D 17
	for (; vidl != NIL; vidl = vidl[2]) {
E 17
I 17
	for (; vidl != TR_NIL; vidl = vidl->list_node.next) {
E 17
#		ifdef OBJ
D 6
		    op -> om_off = roundup( op -> om_off - w , align( np ) );
E 6
I 6
D 7
		    op->om_off = roundup((int)(op->om_off-w), (long)align(np));
E 6
		    o2 = op -> om_off;
E 7
I 7
D 8
		    op->curtmp.om_off =
			roundup((int)(op->curtmp.om_off-w), (long)align(np));
		    o2 = op -> curtmp.om_off;
E 8
I 8
		    op->curtmps.om_off =
			roundup((int)(op->curtmps.om_off-w), (long)align(np));
		    o2 = op -> curtmps.om_off;
E 8
E 7
#		endif OBJ
#		ifdef PC
		    if ( cbn == 1 ) {
				/*
				 * global variables are not accessed off the fp
				 * but rather by their names.
				 */
			    o2 = 0;
		    } else {
				/*
				 * locals are aligned, too.
				 */
D 6
			    op -> om_off = roundup( op -> om_off - w
							, align( np ) );
E 6
I 6
D 7
			    op->om_off = roundup((int)(op->om_off - w),
E 7
I 7
			    op->curtmps.om_off =
				roundup((int)(op->curtmps.om_off - w),
E 7
				(long)align(np));
E 6
D 7
			    o2 = op -> om_off;
E 7
I 7
			    o2 = op -> curtmps.om_off;
E 7
		    }
#		endif PC
D 9
		enter(defnl(vidl[1], VAR, np, o2));
E 9
I 9
D 17
		vp = enter(defnl(vidl[1], VAR, np, o2));
E 17
I 17
#		ifdef PC
		vp = enter(defnl((char *) vidl->list_node.list, VAR, np, o2));
#		else
		(void) enter(defnl((char *) vidl->list_node.list, VAR, np, o2));
#		endif
E 17
E 9
D 25
		if ( np -> nl_flags & NFILES ) {
E 25
I 25
		if ( np != NLNIL && (np -> nl_flags & NFILES) ) {
E 25
		    dfiles[ cbn ] = TRUE;
		}
#		ifdef PC
		    if ( cbn == 1 ) {
			putprintf( "	.data" , 0 );
I 10
D 14
			putprintf( "	.align	%d" , 0 , dotalign(align(np)));
E 14
I 14
			aligndot(align(np));
E 14
E 10
			putprintf( "	.comm	" , 1 );
D 17
			putprintf( EXTFORMAT , 1 , vidl[1] );
			putprintf( ",%d" , 0 , w );
E 17
I 17
			putprintf( EXTFORMAT , 1 , (int) vidl->list_node.list );
			putprintf( ",%d" , 0 , (int) w );
E 17
			putprintf( "	.text" , 0 );
I 5
D 17
D 21
			stabgvar( vidl[1] , p2type( np ) , o2 , w , line );
E 21
I 21
D 22
			stabgvar(vp, w, line);
E 21
E 17
I 17
			stabgvar((char *) vidl->list_node.list , p2type( np ) ,
				o2 , (int) w , line );
E 22
I 22
			stabgvar( vp , w , line );
E 22
E 17
I 9
			vp -> extra_flags |= NGLOBAL;
		    } else {
			vp -> extra_flags |= NLOCAL;
E 9
E 5
		    }
D 2
		    stabvar( vidl[1] , p2type( np ) , cbn , o2 , w );
E 2
I 2
D 5
		    stabvar( vidl[1] , p2type( np ) , cbn , o2 , w , line );
E 5
E 2
#		endif PC
	}
#	ifdef PTREE
	    {
		pPointer	*Vars;
		pPointer	Var = VarDecl( ovidl , vtype );

		pSeize( PorFHeader[ nesting ] );
		Vars = &( pDEF( PorFHeader[ nesting ] ).PorFVars );
		*Vars = ListAppend( *Vars , Var );
		pRelease( PorFHeader[ nesting ] );
	    }
#	endif
}
#endif

varend()
{

	foredecl();
#ifndef PI0
D 7
	sizes[cbn].om_max = sizes[cbn].om_off;
E 7
I 7
	sizes[cbn].om_max = sizes[cbn].curtmps.om_off;
E 7
#else
	send(REVVEND);
#endif
}

/*
D 26
 * Evening
 */
I 17
D 18
#ifndef PC
E 18
E 17
I 6
long
leven(w)
	register long w;
{
	if (w < 0)
		return (w & 0xfffffffe);
	return ((w+1) & 0xfffffffe);
}
I 17
D 18
#endif
E 18
E 17

I 17
#ifndef PC
E 17
int
E 6
even(w)
	register int w;
{
D 6
	if (w < 0)
		return (w & ~1);
	return ((w+1) & ~1);
E 6
I 6
	return leven((long)w);
E 6
}
I 17
#endif
E 17

/*
E 26
 * Find the width of a type in bytes.
 */
width(np)
	struct nl *np;
{

	return (lwidth(np));
}

long
lwidth(np)
	struct nl *np;
{
	register struct nl *p;
D 17
	long w;
E 17

	p = np;
	if (p == NIL)
		return (0);
loop:
	switch (p->class) {
I 17
		default:
			panic("wclass");
E 17
		case TYPE:
			switch (nloff(p)) {
				case TNIL:
					return (2);
				case TSTR:
				case TSET:
					panic("width");
				default:
					p = p->type;
					goto loop;
			}
		case ARRAY:
			return (aryconst(p, 0));
		case PTR:
			return ( sizeof ( int * ) );
		case FILET:
D 4
#			ifdef OBJ
			    return ( sizeof ( int * ) );
#			endif OBJ
#			ifdef PC
			    return ( sizeof(struct iorec)
				    + lwidth( p -> type ) );
#			endif PC
E 4
I 4
			return ( sizeof(struct iorec) + lwidth( p -> type ) );
I 19
		case CRANGE:
			p = p->type;
			goto loop;
E 19
E 4
		case RANGE:
			if (p->type == nl+TDOUBLE)
#ifdef DEBUG
				return (hp21mx ? 4 : 8);
#else
				return (8);
#endif
		case SCAL:
			return (bytes(p->range[0], p->range[1]));
		case SET:
			setran(p->type);
I 16
			/*
			 * Sets are some multiple of longs
			 */
E 16
D 6
			return roundup( ( set.uprbp >> 3 ) + 1 , A_SET );
E 6
I 6
			return roundup((int)((set.uprbp >> 3) + 1),
D 16
				(long)(A_SET));
E 16
I 16
				(long)(sizeof(long)));
E 16
E 6
		case STR:
		case RECORD:
			return ( p->value[NL_OFFS] );
D 17
		default:
			panic("wclass");
E 17
	}
}

    /*
     *	round up x to a multiple of y
     *	for computing offsets of aligned things.
     *	y had better be positive.
     *	rounding is in the direction of x.
     */
long
roundup( x , y )
D 6
    long		x;
E 6
I 6
    int			x;
E 6
    register long	y;
    {
	
	if ( y == 0 ) {
D 11
	    return 0;
E 11
I 11
	    return x;
E 11
	}
	if ( x >= 0 ) {
		return ( ( ( x + ( y - 1 ) ) / y ) * y );
	} else {
		return ( ( ( x - ( y - 1 ) ) / y ) * y );
	}
    }

    /*
     *	alignment of an object using the c alignment scheme
     */
int
align( np )
    struct nl	*np;
    {
	register struct nl *p;
I 16
	long elementalign;
E 16

	p = np;
	if ( p == NIL ) {
	    return 0;
	}
alignit:
	switch ( p -> class ) {
I 17
	    default:
		    panic( "align" );
E 17
	    case TYPE:
		    switch ( nloff( p ) ) {
			case TNIL:
				return A_POINT;
			case TSTR:
D 14
				return A_CHAR;
E 14
I 14
				return A_STRUCT;
E 14
			case TSET:
				return A_SET;
			default:
				p = p -> type;
				goto alignit;
		    }
	    case ARRAY:
			/*
D 14
			 * arrays are aligned as their component types
E 14
I 14
D 16
			 * strings are structures, since they can get
E 16
I 16
			 * arrays are structures, since they can get
E 16
			 * assigned form/to as structure assignments.
D 16
			 * other arrays are aligned as their component types
E 16
I 16
			 * preserve internal alignment if it is greater.
E 16
E 14
			 */
I 14
D 16
		    if ( p -> type == nl+T1CHAR ) {
			return A_STRUCT;
		    }
E 14
		    p = p -> type;
		    goto alignit;
E 16
I 16
		    elementalign = align(p -> type);
		    return elementalign > A_STRUCT ? elementalign : A_STRUCT;
E 16
	    case PTR:
		    return A_POINT;
	    case FILET:
		    return A_FILET;
I 19
	    case CRANGE:
E 19
	    case RANGE:
		    if ( p -> type == nl+TDOUBLE ) {
			return A_DOUBLE;
		    }
		    /* else, fall through */
	    case SCAL:
		    switch ( bytes( p -> range[0] , p -> range[1] ) ) {
			case 4:
			    return A_LONG;
			case 2:
			    return A_SHORT;
			case 1:
			    return A_CHAR;
			default:
			    panic( "align: scal" );
		    }
	    case SET:
		    return A_SET;
	    case STR:
D 14
		    return A_CHAR;
E 14
I 14
			/*
			 * arrays of chars are structs
			 */
		    return A_STRUCT;
E 14
	    case RECORD:
			/*
D 13
			 * follow chain through all fields in record,
			 * taking max of alignments of types of fields.
			 * short circuit out if i reach the maximum alignment.
			 * this is pretty likely, as A_MAX is only 4.
E 13
I 13
			 * the alignment of a record is in its align_info field
			 * why don't we use this for the rest of the namelist?
E 13
			 */
D 13
		    {
			register long recalign;
			register long fieldalign;
			
			recalign = A_MIN;
			p = p -> chain;
			while ( ( p != NIL ) && ( recalign < A_MAX ) ) {
			    fieldalign = align( p -> type );
			    if ( fieldalign > recalign ) {
				recalign = fieldalign;
			    }
			    p = p -> chain;
			}
			return recalign;
		    }
E 13
I 13
		    return p -> align_info;
E 13
D 17
	    default:
		    panic( "align" );
E 17
	}
    }
I 10

I 14
#ifdef PC
E 14
    /*
D 14
     *	given an alignment, return power of two for .align pseudo-op
E 14
I 14
     *	output an alignment pseudo-op.
E 14
     */
D 14
dotalign( alignment )
E 14
I 14
aligndot(alignment)
E 14
    int	alignment;
I 14
D 27
#ifdef vax
E 27
I 27
#if defined(vax) || defined(tahoe)
E 27
E 14
{
D 14
    
    switch ( alignment ) {
	case A_CHAR:		/*
				 * also
				 *	A_STRUCT
				 */
		return 0;
	case A_SHORT:
		return 1;
	case A_LONG:		/*
				 * also
				 *	A_POINT, A_INT, A_FLOAT, A_DOUBLE,
				 *	A_STACK, A_FILET, A_SET
				 */
		return 2;
E 14
I 14
    switch (alignment) {
	case 1:
	    return;
	case 2:
	    putprintf("	.align 1", 0);
	    return;
	default:
	case 4:
	    putprintf("	.align 2", 0);
	    return;
E 14
    }
}
E 10
D 14

E 14
I 14
D 27
#endif vax
E 27
I 27
#endif vax || tahoe
E 27
#ifdef mc68000
{
    switch (alignment) {
	case 1:
	    return;
	default:
	    putprintf("	.even", 0);
	    return;
    }
}
#endif mc68000
#endif PC
    
E 14
/*
 * Return the width of an element
 * of a n time subscripted np.
 */
long aryconst(np, n)
	struct nl *np;
	int n;
{
	register struct nl *p;
	long s, d;

	if ((p = np) == NIL)
		return (NIL);
	if (p->class != ARRAY)
		panic("ary");
I 19
	/*
	 * If it is a conformant array, we cannot find the width from
	 * the type.
	 */
	if (p->chain->class == CRANGE)
		return (NIL);
E 19
	s = lwidth(p->type);
	/*
	 * Arrays of anything but characters are word aligned.
	 */
	if (s & 1)
		if (s != 1)
			s++;
	/*
	 * Skip the first n subscripts
	 */
	while (n >= 0) {
		p = p->chain;
		n--;
	}
	/*
	 * Sum across remaining subscripts.
	 */
	while (p != NIL) {
		if (p->class != RANGE && p->class != SCAL)
			panic("aryran");
		d = p->range[1] - p->range[0] + 1;
		s *= d;
		p = p->chain;
	}
	return (s);
}

/*
 * Find the lower bound of a set, and also its size in bits.
 */
setran(q)
	struct nl *q;
{
	register lb, ub;
	register struct nl *p;

	p = q;
	if (p == NIL)
D 17
		return (NIL);
E 17
I 17
		return;
E 17
	lb = p->range[0];
	ub = p->range[1];
	if (p->class != RANGE && p->class != SCAL)
		panic("setran");
	set.lwrb = lb;
	/* set.(upperbound prime) = number of bits - 1; */
	set.uprbp = ub-lb;
}

/*
 * Return the number of bytes required to hold an arithmetic quantity
 */
bytes(lb, ub)
	long lb, ub;
{

#ifndef DEBUG
	if (lb < -32768 || ub > 32767)
		return (4);
	else if (lb < -128 || ub > 127)
		return (2);
#else
	if (!hp21mx && (lb < -32768 || ub > 32767))
		return (4);
	if (lb < -128 || ub > 127)
		return (2);
#endif
	else
		return (1);
}
E 1
