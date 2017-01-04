h01172
s 00004/00004/00510
d D 5.3 86/11/12 10:29:00 mckusick 16 15
c replace `even' and `leven' with explicit rounding
e
s 00002/00004/00512
d D 5.2 85/07/26 16:14:15 mckusick 15 14
c null pointer checks (from ralph)
e
s 00007/00003/00509
d D 5.1 85/06/05 14:14:26 dist 14 13
c Add copyright
e
s 00000/00001/00512
d D 2.3 85/03/20 15:01:09 ralph 13 12
c changes from donn@utah-cs for common header file for pcc
e
s 00004/00010/00509
d D 2.2 85/02/28 18:02:10 mckusick 12 11
c fix undefined variable introduced by linting
e
s 00000/00000/00519
d D 2.1 84/02/08 20:47:22 aoki 11 10
c synchronize to version 2
e
s 00047/00007/00472
d D 1.9 84/02/08 00:46:15 mckusick 10 9
c merge in conformant array code by Carol Nishizak
e
s 00000/00000/00479
d D 1.8 83/09/19 06:58:28 thien 9 8
c Restoring to unlinted version
e
s 00103/00079/00376
d D 1.7 83/08/19 04:57:08 thien 8 7
c The changes were made to allow successful linting
e
s 00009/00003/00446
d D 1.6 83/02/01 20:13:24 peter 7 6
c parameters are aligned to stack aligned,
c but if not on a low-end machine, their addresses are a little weird.
e
s 00002/00002/00447
d D 1.5 82/08/26 18:48:08 mckusick 6 5
c convert namelist structure to use unions
e
s 00006/00001/00443
d D 1.4 82/07/29 14:51:05 peter 5 4
c check that resolution is the same kind as the forward/external.
e
s 00006/00000/00438
d D 1.3 81/06/01 15:40:49 peter 4 3
c add storage classes to namelist, and use them.
e
s 00193/00116/00245
d D 1.2 81/03/18 22:23:34 mckusic 3 1
c mods for new formal routine syntax
e
s 00194/00116/00245
d R 1.2 81/03/18 21:18:26 mckusic 2 1
c mods for new formal routine syntax
e
s 00361/00000/00000
d D 1.1 81/03/11 14:10:26 mckusick 1 0
c date and time created 81/03/11 14:10:26 by mckusick
e
u
U
t
T
I 1
D 14
/* Copyright (c) 1979 Regents of the University of California */
E 14
I 14
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 14

I 8
#ifndef lint
E 8
D 14
static char sccsid[] = "%Z%%M% %I% %G%";
I 8
#endif
E 14
I 14
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 14
E 8

#include "whoami.h"
#include "0.h"
#include "tree.h"
#include "opcode.h"
#include "objfmt.h"
#include "align.h"
I 8
#include "tree_ty.h"
E 8

/*
 * this array keeps the pxp counters associated with
 * functions and procedures, so that they can be output
 * when their bodies are encountered
 */
int	bodycnts[ DSPLYSZ ];

#ifdef PC
#   include "pc.h"
D 13
#   include "pcops.h"
E 13
#endif PC

#ifdef OBJ
int	cntpatch;
int	nfppatch;
#endif OBJ

/*
 * Funchdr inserts
 * declaration of a the
 * prog/proc/func into the
 * namelist. It also handles
 * the arguments and puts out
 * a transfer which defines
 * the entry point of a procedure.
 */

struct nl *
funchdr(r)
D 8
	int *r;
E 8
I 8
	struct tnode *r;
E 8
{
	register struct nl *p;
D 8
	register *il, **rl;
D 3
	int *rll;
	struct nl *cp, *dp, *sp;
	int w, s, o, *pp;
E 3
I 3
	struct nl *cp, *dp;
	int s, o, *pp;
E 8
I 8
	register struct tnode *rl;
	struct nl *cp, *dp, *temp;
	int o;
E 8
E 3

D 8
	if (inpflist(r[2])) {
E 8
I 8
	if (inpflist(r->p_dec.id_ptr)) {
E 8
		opush('l');
		yyretrieve();	/* kludge */
	}
	pfcnt++;
	parts[ cbn ] |= RPRT;
D 8
	line = r[1];
	if (r[3] == NIL && (p=lookup1(r[2])) != NIL && bn == cbn) {
E 8
I 8
	line = r->p_dec.line_no;
	if (r->p_dec.param_list == TR_NIL &&
		(p=lookup1(r->p_dec.id_ptr)) != NIL && bn == cbn) {
E 8
		/*
		 * Symbol already defined
		 * in this block. it is either
		 * a redeclared symbol (error)
		 * a forward declaration,
		 * or an external declaration.
I 5
		 * check that forwards are of the right kind:
		 *     if this fails, we are trying to redefine it
		 *     and enter() will complain.
E 5
		 */
D 5
		if ((p->class == FUNC || p->class == PROC) && (p->nl_flags & NFORWD) != 0) {
E 5
I 5
		if (  ( ( p->nl_flags & NFORWD ) != 0 )
D 8
		   && (  ( p->class == FUNC && r[0] == T_FDEC )
		      || ( p->class == PROC && r[0] == T_PDEC ) ) ) {
E 8
I 8
		   && (  ( p->class == FUNC && r->tag == T_FDEC )
		      || ( p->class == PROC && r->tag == T_PDEC ) ) ) {
E 8
E 5
			/*
			 * Grammar doesnt forbid
			 * types on a resolution
			 * of a forward function
			 * declaration.
			 */
D 8
			if (p->class == FUNC && r[4])
E 8
I 8
			if (p->class == FUNC && r->p_dec.type)
E 8
				error("Function type should be given only in forward declaration");
			/*
			 * get another counter for the actual
			 */
			if ( monflg ) {
			    bodycnts[ cbn ] = getcnt();
			}
#			ifdef PC
			    enclosing[ cbn ] = p -> symbol;
#			endif PC
#			ifdef PTREE
				/*
				 *	mark this proc/func as forward
				 *	in the pTree.
				 */
			    pDEF( p -> inTree ).PorFForward = TRUE;
#			endif PTREE
			return (p);
		}
	}

	/* if a routine segment is being compiled,
	 * do level one processing.
	 */

D 8
	 if ((r[0] != T_PROG) && (!progseen))
E 8
I 8
	 if ((r->tag != T_PROG) && (!progseen))
E 8
		level1();


	/*
	 * Declare the prog/proc/func
	 */
D 8
	switch (r[0]) {
E 8
I 8
	switch (r->tag) {
E 8
	    case T_PROG:
		    progseen = TRUE;
		    if (opt('z'))
			    monflg = TRUE;
D 8
		    program = p = defnl(r[2], PROG, 0, 0);
		    p->value[3] = r[1];
E 8
I 8
		    program = p = defnl(r->p_dec.id_ptr, PROG, NLNIL, 0);
		    p->value[3] = r->p_dec.line_no;
E 8
		    break;
	    case T_PDEC:
D 8
		    if (r[4] != NIL)
E 8
I 8
		    if (r->p_dec.type != TR_NIL)
E 8
			    error("Procedures do not have types, only functions do");
D 8
		    p = enter(defnl(r[2], PROC, 0, 0));
E 8
I 8
		    p = enter(defnl(r->p_dec.id_ptr, PROC, NLNIL, 0));
E 8
		    p->nl_flags |= NMOD;
#		    ifdef PC
D 8
			enclosing[ cbn ] = r[2];
E 8
I 8
			enclosing[ cbn ] = r->p_dec.id_ptr;
E 8
I 4
			p -> extra_flags |= NGLOBAL;
E 4
#		    endif PC
		    break;
	    case T_FDEC:
D 8
		    il = r[4];
		    if (il == NIL)
E 8
I 8
		    {
			register struct tnode *il;
		    il = r->p_dec.type;
D 12
		    if (il == TR_NIL)
E 12
I 12
		    if (il == TR_NIL) {
			    temp = NLNIL;
E 12
E 8
			    error("Function type must be specified");
D 8
		    else if (il[0] != T_TYID) {
			    il = NIL;
E 8
I 8
D 12
		    else if (il->tag != T_TYID) {
E 12
I 12
		    } else if (il->tag != T_TYID) {
E 12
			    temp = NLNIL;
E 8
			    error("Function type can be specified only by using a type identifier");
		    } else
D 8
			    il = gtype(il);
		    p = enter(defnl(r[2], FUNC, il, NIL));
E 8
I 8
			    temp = gtype(il);
		    }
D 12
		    {
			register struct nl *il;

		    il = temp;
		    p = enter(defnl(r->p_dec.id_ptr, FUNC, il, NIL));

		    }

E 12
I 12
		    p = enter(defnl(r->p_dec.id_ptr, FUNC, temp, NIL));
E 12
E 8
		    p->nl_flags |= NMOD;
		    /*
		     * An arbitrary restriction
		     */
		    switch (o = classify(p->type)) {
			    case TFILE:
			    case TARY:
			    case TREC:
			    case TSET:
			    case TSTR:
				    warning();
				    if (opt('s')) {
					    standard();
				    }
				    error("Functions should not return %ss", clnames[o]);
		    }
#		    ifdef PC
D 8
			enclosing[ cbn ] = r[2];
E 8
I 8
			enclosing[ cbn ] = r->p_dec.id_ptr;
E 8
I 4
			p -> extra_flags |= NGLOBAL;
E 4
#		    endif PC
		    break;
	    default:
		    panic("funchdr");
	}
D 8
	if (r[0] != T_PROG) {
E 8
I 8
	if (r->tag != T_PROG) {
E 8
		/*
		 * Mark this proc/func as
		 * being forward declared
		 */
		p->nl_flags |= NFORWD;
		/*
		 * Enter the parameters
		 * in the next block for
		 * the time being
		 */
		if (++cbn >= DSPLYSZ) {
			error("Procedure/function nesting too deep");
			pexit(ERRS);
		}
		/*
		 * For functions, the function variable
		 */
		if (p->class == FUNC) {
#			ifdef OBJ
D 8
			    cp = defnl(r[2], FVAR, p->type, 0);
E 8
I 8
			    cp = defnl(r->p_dec.id_ptr, FVAR, p->type, 0);
E 8
#			endif OBJ
#			ifdef PC
				/*
				 * fvars used to be allocated and deallocated
				 * by the caller right before the arguments.
				 * the offset of the fvar was kept in
				 * value[NL_OFFS] of function (very wierd,
				 * but see asgnop).
				 * now, they are locals to the function
				 * with the offset kept in the fvar.
				 */

D 8
			    cp = defnl(r[2], FVAR, p->type,
E 8
I 8
			    cp = defnl(r->p_dec.id_ptr, FVAR, p->type,
E 8
D 3
				    -(roundup((int)(DPOFF1+lwidth(p->type)),
					(long)align(p->type))));
E 3
I 3
D 16
				(int)-leven(roundup(
E 16
I 16
				(int)-roundup(roundup(
E 16
			            (int)(DPOFF1+lwidth(p->type)),
D 16
				    (long)align(p->type))));
E 16
I 16
				    (long)align(p->type))), (long) A_STACK);
E 16
I 4
			    cp -> extra_flags |= NLOCAL;
E 4
E 3
#			endif PC
			cp->chain = p;
			p->ptr[NL_FVAR] = cp;
		}
		/*
		 * Enter the parameters
		 * and compute total size
		 */
D 3
		cp = sp = p;

#		ifdef OBJ
		    o = 0;
#		endif OBJ
#		ifdef PC
			/*
			 * parameters used to be allocated backwards,
			 * then fixed.  for pc, they are allocated correctly.
			 * also, they are aligned.
			 */
		o = DPOFF2;
#		endif PC
		for (rl = r[3]; rl != NIL; rl = rl[2]) {
			p = NIL;
			if (rl[1] == NIL)
				continue;
			/*
			 * Parametric procedures
			 * don't have types !?!
			 */
			if (rl[1][0] != T_PPROC) {
				rll = rl[1][2];
				if (rll[0] != T_TYID) {
					error("Types for arguments can be specified only by using type identifiers");
					p = NIL;
				} else
					p = gtype(rll);
			}
			for (il = rl[1][1]; il != NIL; il = il[2]) {
				switch (rl[1][0]) {
				    default:
					    panic("funchdr2");
				    case T_PVAL:
					    if (p != NIL) {
						    if (p->class == FILET)
							    error("Files cannot be passed by value");
						    else if (p->nl_flags & NFILES)
							    error("Files cannot be a component of %ss passed by value",
								    nameof(p));
					    }
#					    ifdef OBJ
						w = width(p);
						o -= even(w);
#						ifdef DEC11
						    dp = defnl(il[1], VAR, p, o);
#						else
						    dp = defnl(il[1], VAR, p,
							(w < 2) ? o + 1 : o);
#						endif DEC11
#					    endif OBJ
#					    ifdef PC
						dp = defnl( il[1] , VAR , p 
							, o = roundup( o , (long)A_STACK ) );
						o += width( p );
#					    endif PC
					    dp->nl_flags |= NMOD;
					    break;
				    case T_PVAR:
#					    ifdef OBJ
						dp = defnl(il[1], REF, p, o -= sizeof ( int * ) );
#					    endif OBJ
#					    ifdef PC
						dp = defnl( il[1] , REF , p
							, o = roundup( o , (long)A_STACK ) );
						o += sizeof(char *);
#					    endif PC
					    break;
				    case T_PFUNC:
#					    ifdef OBJ
						dp = defnl(il[1], FFUNC, p, o -= sizeof ( int * ) );
#					    endif OBJ
#					    ifdef PC
						dp = defnl( il[1] , FFUNC , p
							, o = roundup( o , (long)A_STACK ) );
						o += sizeof(char *);
#					    endif PC
					    dp -> nl_flags |= NMOD;
					    break;
				    case T_PPROC:
#					    ifdef OBJ
						dp = defnl(il[1], FPROC, p, o -= sizeof ( int * ) );
#					    endif OBJ
#					    ifdef PC
						dp = defnl( il[1] , FPROC , p
							, o = roundup( o , (long)A_STACK ) );
						o += sizeof(char *);
#					    endif PC
					    dp -> nl_flags |= NMOD;
					    break;
				    }
				if (dp != NIL) {
					cp->chain = dp;
					cp = dp;
				}
			}
		}
E 3
I 3
D 8
	        p->value[NL_OFFS] = params(p, r[3]);
E 8
I 8
	        p->value[NL_OFFS] = params(p, r->p_dec.param_list);
E 8
		/*
		 * because NL_LINENO field in the function 
		 * namelist entry has been used (as have all
		 * the other fields), the line number is
		 * stored in the NL_LINENO field of its fvar.
		 */
		if (p->class == FUNC)
D 8
		    p->ptr[NL_FVAR]->value[NL_LINENO] = r[1];
E 8
I 8
		    p->ptr[NL_FVAR]->value[NL_LINENO] = r->p_dec.line_no;
E 8
		else
D 8
		    p->value[NL_LINENO] = r[1];
E 8
I 8
		    p->value[NL_LINENO] = r->p_dec.line_no;
E 8
E 3
		cbn--;
D 3
		p = sp;
#		ifdef OBJ
		    p->value[NL_OFFS] = -o+DPOFF2;
			/*
			 * Correct the naivete (naievity)
			 * of our above code to
			 * calculate offsets
			 */
		    for (il = p->chain; il != NIL; il = il->chain)
			    il->value[NL_OFFS] += p->value[NL_OFFS];
#		endif OBJ
#		ifdef PC
		    p -> value[ NL_OFFS ] = roundup( o , (long)A_STACK );
#		endif PC
E 3
	} else { 
		/*
		 * The wonderful
		 * program statement!
		 */
#		ifdef OBJ
		    if (monflg) {
D 8
			    put(1, O_PXPBUF);
E 8
I 8
			    (void) put(1, O_PXPBUF);
E 8
			    cntpatch = put(2, O_CASE4, (long)0);
			    nfppatch = put(2, O_CASE4, (long)0);
		    }
#		endif OBJ
		cp = p;
D 8
		for (rl = r[3]; rl; rl = rl[2]) {
			if (rl[1] == NIL)
E 8
I 8
		for (rl = r->p_dec.param_list; rl; rl = rl->list_node.next) {
			if (rl->list_node.list == TR_NIL)
E 8
				continue;
D 8
			dp = defnl(rl[1], VAR, 0, 0);
E 8
I 8
			dp = defnl((char *) rl->list_node.list, VAR, NLNIL, 0);
E 8
			cp->chain = dp;
			cp = dp;
		}
	}
	/*
	 * Define a branch at
	 * the "entry point" of
	 * the prog/proc/func.
	 */
D 6
	p->entloc = getlab();
E 6
I 6
D 8
	p->value[NL_ENTLOC] = getlab();
E 8
I 8
	p->value[NL_ENTLOC] = (int) getlab();
E 8
E 6
	if (monflg) {
		bodycnts[ cbn ] = getcnt();
		p->value[ NL_CNTR ] = 0;
	}
#	ifdef OBJ
D 6
	    put(2, O_TRA4, (long)p->entloc);
E 6
I 6
D 8
	    put(2, O_TRA4, (long)p->value[NL_ENTLOC]);
E 8
I 8
	    (void) put(2, O_TRA4, (long)p->value[NL_ENTLOC]);
E 8
E 6
#	endif OBJ
#	ifdef PTREE
	    {
		pPointer	PF = tCopy( r );

		pSeize( PorFHeader[ nesting ] );
D 8
		if ( r[0] != T_PROG ) {
E 8
I 8
		if ( r->tag != T_PROG ) {
E 8
			pPointer	*PFs;

			PFs = &( pDEF( PorFHeader[ nesting ] ).PorFPFs );
			*PFs = ListAppend( *PFs , PF );
		} else {
			pDEF( PorFHeader[ nesting ] ).GlobProg = PF;
		}
		pRelease( PorFHeader[ nesting ] );
	    }
#	endif PTREE
	return (p);
I 3
}

	/*
	 * deal with the parameter declaration for a routine.
	 * p is the namelist entry of the routine.
	 * formalist is the parse tree for the parameter declaration.
	 * formalist	[0]	T_LISTPP
	 *		[1]	pointer to a formal
	 *		[2]	pointer to next formal
	 * for by-value or by-reference formals, the formal is
	 * formal	[0]	T_PVAL or T_PVAR
	 *		[1]	pointer to id_list
	 *		[2]	pointer to type (error if not typeid)
	 * for function and procedure formals, the formal is
	 * formal	[0]	T_PFUNC or T_PPROC
	 *		[1]	pointer to id_list (error if more than one)
	 *		[2]	pointer to type (error if not typeid, or proc)
	 *		[3]	pointer to formalist for this routine.
	 */
fparams(p, formal)
	register struct nl *p;
D 8
	int *formal;
E 8
I 8
	struct tnode *formal;		/* T_PFUNC or T_PPROC */
E 8
{
D 8
	params(p, formal[3]);
	p -> value[ NL_LINENO ] = formal[4];
E 8
I 8
	(void) params(p, formal->pfunc_node.param_list);
	p -> value[ NL_LINENO ] = formal->pfunc_node.line_no;
E 8
	p -> ptr[ NL_FCHAIN ] = p -> chain;
	p -> chain = NIL;
}

params(p, formalist)
	register struct nl *p;
D 8
	int *formalist;
E 8
I 8
	struct tnode *formalist;	/* T_LISTPP */
E 8
{
	struct nl *chainp, *savedp;
	struct nl *dp;
D 8
	register int **formalp;		/* an element of the formal list */
	register int *formal;		/* a formal */
	int *typ, *idlist;
E 8
I 8
	register struct tnode *formalp;	/* an element of the formal list */
	register struct tnode *formal;	/* a formal */
D 10
	struct tnode *typ, *idlist;
E 10
I 10
	struct tnode *r, *s, *t, *typ, *idlist;
E 10
E 8
	int w, o;

	/*
	 * Enter the parameters
	 * and compute total size
	 */
	chainp = savedp = p;

#	ifdef OBJ
	    o = 0;
#	endif OBJ
#	ifdef PC
		/*
		 * parameters used to be allocated backwards,
		 * then fixed.  for pc, they are allocated correctly.
		 * also, they are aligned.
		 */
	    o = DPOFF2;
#	endif PC
D 8
	for (formalp = formalist; formalp != NIL; formalp = formalp[2]) {
		p = NIL;
		formal = formalp[1];
		if (formal == NIL)
E 8
I 8
	for (formalp = formalist; formalp != TR_NIL;
			formalp = formalp->list_node.next) {
D 15
		p = NLNIL;
E 15
		formal = formalp->list_node.list;
		if (formal == TR_NIL)
E 8
			continue;
		/*
		 * Parametric procedures
		 * don't have types !?!
		 */
D 8
		typ = formal[2];
		if ( typ == NIL ) {
		    if ( formal[0] != T_PPROC ) {
E 8
I 8
		typ = formal->pfunc_node.type;
I 15
		p = NLNIL;
E 15
		if ( typ == TR_NIL ) {
		    if ( formal->tag != T_PPROC ) {
E 8
			error("Types must be specified for arguments");
D 8
			p = NIL;
E 8
I 8
D 15
			p = NLNIL;
E 15
E 8
		    }
		} else {
D 8
		    if ( formal[0] == T_PPROC ) {
E 8
I 8
		    if ( formal->tag == T_PPROC ) {
E 8
			error("Procedures cannot have types");
D 8
			p = NIL;
E 8
I 8
D 15
			p = NLNIL;
E 15
E 8
		    } else {
D 8
			if (typ[0] != T_TYID) {
E 8
I 8
D 10
			if (typ->tag != T_TYID) {
E 8
				error("Types for arguments can be specified only by using type identifiers");
D 8
				p = NIL;
E 8
I 8
				p = NLNIL;
E 8
			} else {
				p = gtype(typ);
			}
E 10
I 10
			p = gtype(typ);
E 10
		    }
		}
D 8
		for (idlist = formal[1]; idlist != NIL; idlist = idlist[2]) {
			switch (formal[0]) {
E 8
I 8
		for (idlist = formal->param.id_list; idlist != TR_NIL;
				idlist = idlist->list_node.next) {
			switch (formal->tag) {
E 8
			    default:
				    panic("funchdr2");
			    case T_PVAL:
D 8
				    if (p != NIL) {
E 8
I 8
				    if (p != NLNIL) {
E 8
					    if (p->class == FILET)
						    error("Files cannot be passed by value");
					    else if (p->nl_flags & NFILES)
						    error("Files cannot be a component of %ss passed by value",
							    nameof(p));
				    }
#				    ifdef OBJ
					w = lwidth(p);
D 16
					o -= even(w);
E 16
I 16
					o -= roundup(w, (long) A_STACK);
E 16
#					ifdef DEC11
D 8
					    dp = defnl(idlist[1], VAR, p, o);
E 8
I 8
					    dp = defnl((char *) idlist->list_node.list,
								VAR, p, o);
E 8
#					else
D 8
					    dp = defnl(idlist[1], VAR, p,
						(w < 2) ? o + 1 : o);
E 8
I 8
					    dp = defnl((char *) idlist->list_node.list,
						    VAR,p, (w < 2) ? o + 1 : o);
E 8
#					endif DEC11
#				    endif OBJ
#				    ifdef PC
D 7
					dp = defnl( idlist[1] , VAR , p 
						, o = roundup( o , (long)A_STACK ) );
					o += lwidth( p );
E 7
I 7
D 8
					o = roundup(o, A_STACK);
E 8
I 8
					o = roundup(o, (long) A_STACK);
E 8
					w = lwidth(p);
#					ifndef DEC11
					    if (w <= sizeof(int)) {
						o += sizeof(int) - w;
					    }
#					endif not DEC11
D 8
					dp = defnl(idlist[1], VAR, p, o);
E 8
I 8
					dp = defnl((char *) idlist->list_node.list,VAR,
							p, o);
E 8
					o += w;
E 7
#				    endif PC
				    dp->nl_flags |= NMOD;
				    break;
			    case T_PVAR:
#				    ifdef OBJ
D 8
					dp = defnl(idlist[1], REF, p, o -= sizeof ( int * ) );
E 8
I 8
					dp = defnl((char *) idlist->list_node.list, REF,
						    p, o -= sizeof ( int * ) );
E 8
#				    endif OBJ
#				    ifdef PC
D 8
					dp = defnl( idlist[1] , REF , p
						, o = roundup( o , (long)A_STACK ) );
E 8
I 8
					dp = defnl( (char *) idlist->list_node.list, REF,
						    p , 
					    o = roundup( o , (long)A_STACK ) );
E 8
					o += sizeof(char *);
#				    endif PC
				    break;
			    case T_PFUNC:
D 8
				    if (idlist[2] != NIL) {
E 8
I 8
				    if (idlist->list_node.next != TR_NIL) {
E 8
					error("Each function argument must be declared separately");
D 8
					idlist[2] = NIL;
E 8
I 8
					idlist->list_node.next = TR_NIL;
E 8
				    }
#				    ifdef OBJ
D 8
					dp = defnl(idlist[1], FFUNC, p, o -= sizeof ( int * ) );
E 8
I 8
					dp = defnl((char *) idlist->list_node.list,FFUNC,
						p, o -= sizeof ( int * ) );
E 8
#				    endif OBJ
#				    ifdef PC
D 8
					dp = defnl( idlist[1] , FFUNC , p
						, o = roundup( o , (long)A_STACK ) );
E 8
I 8
					dp = defnl( (char *) idlist->list_node.list , 
						FFUNC , p ,
						o = roundup( o , (long)A_STACK ) );
E 8
					o += sizeof(char *);
#				    endif PC
				    dp -> nl_flags |= NMOD;
				    fparams(dp, formal);
				    break;
			    case T_PPROC:
D 8
				    if (idlist[2] != NIL) {
E 8
I 8
				    if (idlist->list_node.next != TR_NIL) {
E 8
					error("Each procedure argument must be declared separately");
D 8
					idlist[2] = NIL;
E 8
I 8
					idlist->list_node.next = TR_NIL;
E 8
				    }
#				    ifdef OBJ
D 8
					dp = defnl(idlist[1], FPROC, p, o -= sizeof ( int * ) );
E 8
I 8
					dp = defnl((char *) idlist->list_node.list,
					    FPROC, p, o -= sizeof ( int * ) );
E 8
#				    endif OBJ
#				    ifdef PC
D 8
					dp = defnl( idlist[1] , FPROC , p
						, o = roundup( o , (long)A_STACK ) );
E 8
I 8
					dp = defnl( (char *) idlist->list_node.list ,
						FPROC , p,
						o = roundup( o , (long)A_STACK ) );
E 8
					o += sizeof(char *);
#				    endif PC
				    dp -> nl_flags |= NMOD;
				    fparams(dp, formal);
				    break;
			    }
D 8
			if (dp != NIL) {
E 8
I 8
			if (dp != NLNIL) {
E 8
I 4
#				ifdef PC
				    dp -> extra_flags |= NPARAM;
#				endif PC
E 4
				chainp->chain = dp;
				chainp = dp;
			}
I 10
		}
D 15
		if (typ->tag == T_TYCARY) {
E 15
I 15
		if (typ != TR_NIL && typ->tag == T_TYCARY) {
E 15
#		    ifdef OBJ
D 16
			w = -even(lwidth(p->chain));
E 16
I 16
			w = -roundup(lwidth(p->chain), (long) A_STACK);
E 16
#			ifndef DEC11
			    w = (w > -2)? w + 1 : w;
#			endif
#		    endif OBJ
#		    ifdef PC
			w = lwidth(p->chain);
			o = roundup(o, (long)A_STACK);
#		    endif PC
		    /*
		     * Allocate space for upper and
		     * lower bounds and width.
		     */
		    for (s=typ; s->tag == T_TYCARY; s = s->ary_ty.type) {
			for (r=s->ary_ty.type_list; r != TR_NIL;
						r = r->list_node.next) {
			    t = r->list_node.list;
			    p = p->chain;
#			    ifdef OBJ
				o += w;
#			    endif OBJ
			    chainp->chain = defnl(t->crang_ty.lwb_var,
								VAR, p, o);
			    chainp = chainp->chain;
			    chainp->nl_flags |= (NMOD | NUSED);
			    p->nptr[0] = chainp;
			    o += w;
			    chainp->chain = defnl(t->crang_ty.upb_var,
								VAR, p, o);
			    chainp = chainp->chain;
			    chainp->nl_flags |= (NMOD | NUSED);
			    p->nptr[1] = chainp;
			    o += w;
			    chainp->chain  = defnl(0, VAR, p, o);
			    chainp = chainp->chain;
			    chainp->nl_flags |= (NMOD | NUSED);
			    p->nptr[2] = chainp;
#			    ifdef PC
				o += w;
#			    endif PC
			}
		    }
E 10
		}
	}
	p = savedp;
#	ifdef OBJ
		/*
		 * Correct the naivete (naivety)
		 * of our above code to
		 * calculate offsets
		 */
D 8
	    for (dp = p->chain; dp != NIL; dp = dp->chain)
E 8
I 8
	    for (dp = p->chain; dp != NLNIL; dp = dp->chain)
E 8
		    dp->value[NL_OFFS] += -o + DPOFF2;
	    return (-o + DPOFF2);
#	endif OBJ
#	ifdef PC
	    return roundup( o , (long)A_STACK );
#	endif PC
E 3
}
E 1
