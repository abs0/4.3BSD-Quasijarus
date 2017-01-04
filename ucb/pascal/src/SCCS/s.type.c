h24047
s 00007/00003/00446
d D 5.1 85/06/05 15:03:39 dist 17 16
c Add copyright
e
s 00002/00004/00447
d D 2.2 85/03/15 22:41:29 mckusick 16 14
i 15
c merge dbx from linton
e
s 00010/00003/00398
d D 1.8.1.1 85/03/15 22:38:45 mckusick 15 8
c new dbx from linton
e
s 00000/00000/00442
d D 2.1 84/02/08 20:45:40 aoki 14 13
c synchronize to version 2
e
s 00004/00003/00438
d D 1.13 84/02/08 20:05:29 aoki 13 12
c lint
e
s 00040/00007/00401
d D 1.12 84/02/08 00:39:56 mckusick 12 11
c merge in conformant array code by Carol Nishizak
e
s 00002/00002/00406
d D 1.11 84/02/04 17:28:38 thien 11 10
c lint
e
s 00000/00000/00408
d D 1.10 83/09/19 07:01:32 thien 10 9
c Restoring to unlinted version
e
s 00070/00063/00338
d D 1.9 83/08/19 05:03:34 thien 9 8
c The changes were made to allow successful linting
e
s 00017/00005/00384
d D 1.8 82/08/29 14:04:26 peter 8 7
c once-only error messages for multiple/out-of-order declarations.
e
s 00000/00004/00389
d D 1.7 82/08/27 01:10:38 mckusick 7 6
c remove restriction on files in dynamic structures
e
s 00005/00004/00388
d D 1.6 81/03/08 19:28:54 mckusic 6 5
c merge in onyx changes
e
s 00004/00000/00388
d D 1.5 80/11/17 20:00:18 peter 5 4
c eliminate 65k restriction
e
s 00001/00001/00387
d D 1.4 80/09/04 23:10:26 peter 4 3
c N_PC stabs with subtypes
e
s 00016/00018/00372
d D 1.3 80/09/02 22:06:11 peter 3 2
c interleaved declaration parts
e
s 00003/00002/00387
d D 1.2 80/08/31 17:31:35 peter 2 1
c stabs for separate compilation type checking
e
s 00389/00000/00000
d D 1.1 80/08/27 19:56:49 peter 1 0
c date and time created 80/08/27 19:56:49 by peter
e
u
U
f b 
t
T
I 1
D 17
/* Copyright (c) 1979 Regents of the University of California */
E 17
I 17
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 17

I 9
#ifndef lint
E 9
D 6
static	char sccsid[] = "%Z%%M% %I% %G%";
E 6
I 6
D 17
static char sccsid[] = "%Z%%M% %I% %G%";
I 9
#endif
E 17
I 17
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 17
E 9
E 6

#include "whoami.h"
#include "0.h"
#include "tree.h"
#include "objfmt.h"
I 9
#include "tree_ty.h"
E 9

/*
 * Type declaration part
 */
I 9
/*ARGSUSED*/
E 9
D 8
typebeg()
E 8
I 8
typebeg( lineofytype , r )
    int	lineofytype;
E 8
{
I 8
    static bool	type_order = FALSE;
    static bool	type_seen = FALSE;
E 8

/*
D 3
 * PC allows for multiple
E 3
I 3
 * this allows for multiple
E 3
 * declaration parts unless
 * standard option has been
 * specified.
 * If routine segment is being
 * compiled, do level one processing.
 */

#ifndef PI1
D 3
if (!progseen)
	level1();
#ifdef PC
   if (opt('s')) {
	if (parts & VPRT) {
E 3
I 3
	if (!progseen)
		level1();
I 8
	line = lineofytype;
E 8
	if ( parts[ cbn ] & ( VPRT | RPRT ) ) {
	    if ( opt( 's' ) ) {
E 3
		standard();
I 8
		error("Type declarations should precede var and routine declarations");
E 8
D 3
		error("Type declarations must precede var declarations");
E 3
I 3
	    } else {
D 8
		warning();
E 8
I 8
		if ( !type_order ) {
		    type_order = TRUE;
		    warning();
		    error("Type declarations should precede var and routine declarations");
		}
E 8
	    }
D 8
	    error("Type declarations should precede var and routine declarations");
E 8
E 3
	}
D 3
	if (parts & TPRT) {
E 3
I 3
	if (parts[ cbn ] & TPRT) {
	    if ( opt( 's' ) ) {
E 3
		standard();
I 8
		error("All types should be declared in one type part");
E 8
D 3
		error("All types must be declared in one type part");
E 3
I 3
	    } else {
D 8
		warning();
E 8
I 8
		if ( !type_seen ) {
		    type_seen = TRUE;
		    warning();
		    error("All types should be declared in one type part");
		}
E 8
	    }
D 8
	    error("All types should be declared in one type part");
E 8
E 3
	}
D 3
   }
#endif PC
#ifdef OBJ
	if (parts & VPRT)
		error("Type declarations must precede var declarations");
	if (parts & TPRT)
		error("All types must be declared in one type part");
#endif OBJ
	parts |= TPRT;
E 3
I 3
	parts[ cbn ] |= TPRT;
E 3
#endif
	/*
	 * Forechain is the head of a list of types that
	 * might be self referential.  We chain them up and
	 * process them later.
	 */
	forechain = NIL;
#ifdef PI0
	send(REVTBEG);
#endif
}

type(tline, tid, tdecl)
	int tline;
	char *tid;
D 9
	register int *tdecl;
E 9
I 9
	register struct tnode *tdecl;
E 9
{
	register struct nl *np;
I 15
	struct nl *tnp;
E 15

	np = gtype(tdecl);
	line = tline;
I 15
	tnp = defnl(tid, TYPE, np, 0);
E 15
#ifndef PI0
D 11
D 15
	enter(defnl(tid, TYPE, np, 0))->nl_flags |= NMOD;
E 15
I 15
D 16
	enter(tnp)->nl_flags |= NMOD;
E 15
E 11
I 11
	enter(defnl(tid, TYPE, np, 0))->nl_flags |= (char) NMOD;
E 16
I 16
	enter(tnp)->nl_flags |= (char) NMOD;
E 16
E 11
#else
D 9
D 15
	enter(defnl(tid, TYPE, np, 0));
E 15
I 15
D 16
	enter(tnp);
E 15
E 9
I 9
	(void) enter(defnl(tid, TYPE, np, 0));
E 16
I 16
	(void) enter(tnp);
E 16
E 9
	send(REVTYPE, tline, tid, tdecl);
#endif

#ifdef PC
D 2
	if (cbn == 1)
		stabtname( tid );
E 2
I 2
	if (cbn == 1) {
D 4
	    stabtname( tid , line );
E 4
I 4
D 15
	    stabgtype( tid , line );
E 15
I 15
	    stabgtype(tid, np, line);
	} else {
	    stabltype(tid, np);
E 15
E 4
	}
E 2
#endif PC

#	ifdef PTREE
	    {
		pPointer Type = TypeDecl( tid , tdecl );
		pPointer *Types;

		pSeize( PorFHeader[ nesting ] );
		Types = &( pDEF( PorFHeader[ nesting ] ).PorFTypes );
		*Types = ListAppend( *Types , Type );
		pRelease( PorFHeader[ nesting ] );
	    }
#	endif
}

typeend()
{

#ifdef PI0
	send(REVTEND);
#endif
	foredecl();
}

/*
 * Return a type pointer (into the namelist)
 * from a parse tree for a type, building
 * namelist entries as needed.
 */
struct nl *
gtype(r)
D 9
	register int *r;
E 9
I 9
	register struct tnode *r;
E 9
{
	register struct nl *np;
D 9
	register char *cp;
E 9
D 6
	register int oline, w;
E 6
I 6
	register int oline;
I 9
#ifdef OBJ
E 9
	long w;
I 9
#endif
E 9
E 6

D 9
	if (r == NIL)
		return (NIL);
E 9
I 9
	if (r == TR_NIL)
		return (NLNIL);
E 9
	oline = line;
D 9
	if (r[0] != T_ID)
		oline = line = r[1];
	switch (r[0]) {
E 9
I 9
	if (r->tag != T_ID)
		oline = line = r->lined.line_no;
	switch (r->tag) {
E 9
		default:
			panic("type");
		case T_TYID:
D 11
			r++;
E 11
I 11
			r = (struct tnode *) (&(r->tyid_node.line_no));
E 11
		case T_ID:
D 9
			np = lookup(r[1]);
			if (np == NIL)
E 9
I 9
			np = lookup(r->char_const.cptr);
			if (np == NLNIL)
E 9
				break;
			if (np->class != TYPE) {
#ifndef PI1
D 9
				error("%s is a %s, not a type as required", r[1], classes[np->class]);
E 9
I 9
				error("%s is a %s, not a type as required", r->char_const.cptr, classes[np->class]);
E 9
#endif
D 9
				np = NIL;
E 9
I 9
				np = NLNIL;
E 9
				break;
			}
			np = np->type;
			break;
		case T_TYSCAL:
			np = tyscal(r);
			break;
I 12
		case T_TYCRANG:
			np = tycrang(r);
			break;
E 12
		case T_TYRANG:
			np = tyrang(r);
			break;
		case T_TYPTR:
D 9
			np = defnl(0, PTR, 0, 0 );
			np -> ptr[0] = r[2];
E 9
I 9
			np = defnl((char *) 0, PTR, NLNIL, 0 );
			np -> ptr[0] = ((struct nl *) r->ptr_ty.id_node);
E 9
			np->nl_next = forechain;
			forechain = np;
			break;
		case T_TYPACK:
D 9
			np = gtype(r[2]);
E 9
I 9
			np = gtype(r->comp_ty.type);
E 9
			break;
I 12
		case T_TYCARY:
E 12
		case T_TYARY:
			np = tyary(r);
			break;
		case T_TYREC:
D 9
			np = tyrec(r[2], 0);
E 9
I 9
			np = tyrec(r->comp_ty.type, 0);
E 9
#			ifdef PTREE
				/*
				 * mung T_TYREC[3] to point to the record
				 * for RecTCopy
				 */
D 9
			    r[3] = np;
E 9
I 9
			    r->comp_ty.nl_entry = np;
E 9
#			endif
			break;
		case T_TYFILE:
D 9
			np = gtype(r[2]);
			if (np == NIL)
E 9
I 9
			np = gtype(r->comp_ty.type);
			if (np == NLNIL)
E 9
				break;
#ifndef PI1
			if (np->nl_flags & NFILES)
				error("Files cannot be members of files");
#endif
D 9
			np = defnl(0, FILET, np, 0);
E 9
I 9
			np = defnl((char *) 0, FILET, np, 0);
E 9
			np->nl_flags |= NFILES;
			break;
		case T_TYSET:
D 9
			np = gtype(r[2]);
			if (np == NIL)
E 9
I 9
			np = gtype(r->comp_ty.type);
			if (np == NLNIL)
E 9
				break;
			if (np->type == nl+TDOUBLE) {
#ifndef PI1
				error("Set of real is not allowed");
#endif
D 9
				np = NIL;
E 9
I 9
				np = NLNIL;
E 9
				break;
			}
			if (np->class != RANGE && np->class != SCAL) {
#ifndef PI1
				error("Set type must be range or scalar, not %s", nameof(np));
#endif
D 9
				np = NIL;
E 9
I 9
				np = NLNIL;
E 9
				break;
			}
#ifndef PI1
			if (width(np) > 2)
				error("Implementation restriction: sets must be indexed by 16 bit quantities");
#endif
D 9
			np = defnl(0, SET, np, 0);
E 9
I 9
			np = defnl((char *) 0, SET, np, 0);
E 9
			break;
	}
	line = oline;
D 9
	w = lwidth(np);
E 9
I 5
#ifndef PC
I 9
	w = lwidth(np);
E 9
E 5
	if (w >= TOOMUCH) {
D 6
		error("Storage requirement of %s exceeds the implementation limit of %d by %d bytes",
			nameof(np), TOOMUCH-1, w-TOOMUCH+1);
E 6
I 6
		error("Storage requirement of %s exceeds the implementation limit of %D by %D bytes",
D 9
			nameof(np), (long)(TOOMUCH-1), (long)(w-TOOMUCH+1));
E 6
		np = NIL;
E 9
I 9
			nameof(np), (char *) (long)(TOOMUCH-1), (char *) (long)(w-TOOMUCH+1));
		np = NLNIL;
E 9
	}
I 5
#endif
E 5
	return (np);
}

/*
 * Scalar (enumerated) types
 */
I 9
struct nl *
E 9
tyscal(r)
D 9
	int *r;
E 9
I 9
	struct tnode *r;	/* T_TYSCAL */
E 9
{
	register struct nl *np, *op, *zp;
D 9
	register *v;
E 9
I 9
	register struct tnode *v;
E 9
	int i;

D 9
	np = defnl(0, SCAL, 0, 0);
E 9
I 9
	np = defnl((char *) 0, SCAL, NLNIL, 0);
E 9
	np->type = np;
D 9
	v = r[2];
	if (v == NIL)
		return (NIL);
E 9
I 9
	v = r->comp_ty.type;
	if (v == TR_NIL)
		return (NLNIL);
E 9
	i = -1;
	zp = np;
D 9
	for (; v != NIL; v = v[2]) {
		op = enter(defnl(v[1], CONST, np, ++i));
E 9
I 9
	for (; v != TR_NIL; v = v->list_node.next) {
		op = enter(defnl((char *) v->list_node.list, CONST, np, ++i));
E 9
#ifndef PI0
		op->nl_flags |= NMOD;
#endif
		op->value[1] = i;
		zp->chain = op;
		zp = op;
	}
	np->range[1] = i;
	return (np);
}

/*
I 12
 * Declare a subrange for conformant arrays.
 */
I 13
struct nl *
E 13
tycrang(r)
D 13
	register int *r;
E 13
I 13
	register struct tnode *r;
E 13
{
	register struct nl *p, *op, *tp;

	tp = gtype(r->crang_ty.type);
D 13
	if ( tp == NIL )
		return (NIL);
E 13
I 13
	if ( tp == NLNIL )
		return (NLNIL);
E 13
	/*
	 * Just make a new type -- the lower and upper bounds must be
	 * set by params().
	 */
	p = defnl ( 0, CRANGE, tp, 0 );
	return(p);
}

/*
E 12
 * Declare a subrange.
 */
I 9
struct nl *
E 9
tyrang(r)
D 9
	register int *r;
E 9
I 9
	register struct tnode *r;  /* T_TYRANG */
E 9
{
	register struct nl *lp, *hp;
	double high;
	int c, c1;

D 9
	gconst(r[3]);
E 9
I 9
	gconst(r->rang_ty.const2);
E 9
	hp = con.ctype;
	high = con.crval;
D 9
	gconst(r[2]);
E 9
I 9
	gconst(r->rang_ty.const1);
E 9
	lp = con.ctype;
D 9
	if (lp == NIL || hp == NIL)
		return (NIL);
E 9
I 9
	if (lp == NLNIL || hp == NLNIL)
		return (NLNIL);
E 9
	if (norange(lp) || norange(hp))
D 9
		return (NIL);
E 9
I 9
		return (NLNIL);
E 9
	c = classify(lp);
	c1 = classify(hp);
	if (c != c1) {
#ifndef PI1
		error("Can't mix %ss and %ss in subranges", nameof(lp), nameof(hp));
#endif
D 9
		return (NIL);
E 9
I 9
		return (NLNIL);
E 9
	}
	if (c == TSCAL && scalar(lp) != scalar(hp)) {
#ifndef PI1
		error("Scalar types must be identical in subranges");
#endif
D 9
		return (NIL);
E 9
I 9
		return (NLNIL);
E 9
	}
	if (con.crval > high) {
#ifndef PI1
		error("Range lower bound exceeds upper bound");
#endif
D 9
		return (NIL);
E 9
I 9
		return (NLNIL);
E 9
	}
D 9
	lp = defnl(0, RANGE, hp->type, 0);
E 9
I 9
	lp = defnl((char *) 0, RANGE, hp->type, 0);
E 9
	lp->range[0] = con.crval;
	lp->range[1] = high;
	return (lp);
}

norange(p)
	register struct nl *p;
{
	if (isa(p, "d")) {
#ifndef PI1
		error("Subrange of real is not allowed");
#endif
		return (1);
	}
	if (isnta(p, "bcsi")) {
#ifndef PI1
		error("Subrange bounds must be Boolean, character, integer or scalar, not %s", nameof(p));
#endif
		return (1);
	}
	return (0);
}

/*
 * Declare arrays and chain together the dimension specification
 */
struct nl *
tyary(r)
D 9
	int *r;
E 9
I 9
	struct tnode *r;
E 9
{
	struct nl *np;
D 9
	register *tl;
E 9
I 9
D 12
	register struct tnode *tl;
E 12
I 12
	register struct tnode *tl, *s;
E 12
E 9
	register struct nl *tp, *ltp;
D 12
	int i;
E 12
I 12
	int i, n;
E 12

D 9
	tp = gtype(r[3]);
	if (tp == NIL)
		return (NIL);
	np = defnl(0, ARRAY, tp, 0);
E 9
I 9
D 12
	tp = gtype(r->ary_ty.type);
E 12
I 12
	s = r;
	/* Count the dimensions */
	for (n = 0; s->tag == T_TYARY || s->tag == T_TYCARY;
					s = s->ary_ty.type, n++)
		/* NULL STATEMENT */;
	tp = gtype(s);
E 12
	if (tp == NLNIL)
		return (NLNIL);
	np = defnl((char *) 0, ARRAY, tp, 0);
E 9
	np->nl_flags |= (tp->nl_flags) & NFILES;
	ltp = np;
	i = 0;
D 9
	for (tl = r[2]; tl != NIL; tl = tl[2]) {
		tp = gtype(tl[1]);
		if (tp == NIL) {
			np = NIL;
E 9
I 9
D 12
	for (tl = r->ary_ty.type_list; tl != TR_NIL; tl = tl->list_node.next) {
E 12
I 12
	for (s = r; s->tag == T_TYARY || s->tag == T_TYCARY;
					s = s->ary_ty.type) {
	    for (tl = s->ary_ty.type_list; tl != TR_NIL; tl=tl->list_node.next){
E 12
		tp = gtype(tl->list_node.list);
		if (tp == NLNIL) {
			np = NLNIL;
E 9
			continue;
		}
D 12
		if (tp->class == RANGE && tp->type == nl+TDOUBLE) {
E 12
I 12
		if ((tp->class == RANGE || tp->class == CRANGE) &&
		    tp->type == nl+TDOUBLE) {
E 12
#ifndef PI1
			error("Index type for arrays cannot be real");
#endif
D 9
			np = NIL;
E 9
I 9
			np = NLNIL;
E 9
			continue;
		}
D 12
		if (tp->class != RANGE && tp->class != SCAL) {
E 12
I 12
		if (tp->class != RANGE && tp->class != SCAL && tp->class !=CRANGE){
E 12
#ifndef PI1
			error("Array index type is a %s, not a range or scalar as required", classes[tp->class]);
#endif
D 9
			np = NIL;
E 9
I 9
			np = NLNIL;
E 9
			continue;
		}
I 5
#ifndef PC
E 5
		if (tp->class == RANGE && bytes(tp->range[0], tp->range[1]) > 2) {
#ifndef PI1
			error("Value of dimension specifier too large or small for this implementation");
#endif
			continue;
		}
I 5
#endif
E 5
D 12
		tp = nlcopy(tp);
E 12
I 12
		if (tp->class != CRANGE)
			tp = nlcopy(tp);
E 12
		i++;
		ltp->chain = tp;
		ltp = tp;
I 12
	    }
E 12
	}
D 9
	if (np != NIL)
E 9
I 9
	if (np != NLNIL)
E 9
		np->value[0] = i;
	return (np);
}

/*
 * Delayed processing for pointers to
 * allow self-referential and mutually
 * recursive pointer constructs.
 */
foredecl()
{
D 9
	register struct nl *p, *q;
E 9
I 9
	register struct nl *p;
E 9

D 9
	for (p = forechain; p != NIL; p = p->nl_next) {
E 9
I 9
	for (p = forechain; p != NLNIL; p = p->nl_next) {
E 9
		if (p->class == PTR && p -> ptr[0] != 0)
		{
D 9
			p->type = gtype(p -> ptr[0]);
E 9
I 9
			p->type = gtype((struct tnode *) p -> ptr[0]);
E 9
D 7
#ifndef PI1
			if (p->type != NIL && ( ( p->type )->nl_flags & NFILES))
				error("Files cannot be members of dynamic structures");
#endif
E 7
#			ifdef PTREE
			{
			    if ( pUSE( p -> inTree ).PtrTType == pNIL ) {
				pPointer	PtrTo = tCopy( p -> ptr[0] );

				pDEF( p -> inTree ).PtrTType = PtrTo;
			    }
			}
I 15
#			endif
#			ifdef PC
			    fixfwdtype(p);
E 15
#			endif
			p -> ptr[0] = 0;
		}
	}
}
E 1
