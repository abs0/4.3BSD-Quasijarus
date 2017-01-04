h15090
s 00008/00003/00272
d D 5.1 85/06/05 14:10:08 dist 28 27
c Add copyright
e
s 00001/00001/00274
d D 2.2 85/03/20 14:59:58 ralph 27 26
c changes from donn@utah-cs for common header file for pcc
e
s 00000/00000/00275
d D 2.1 84/02/08 20:48:39 aoki 26 25
c synchronize to version 2
e
s 00000/00000/00275
d D 1.25 83/09/19 06:58:07 thien 25 24
c Restoring to unlinted version
e
s 00013/00008/00262
d D 1.24 83/08/19 04:56:31 thien 24 23
c The changes were made to allow successful linting
e
s 00005/00014/00265
d D 1.23 83/02/28 17:18:56 peter 23 22
c clean up temporary allocation, moving everything relevant to
c tmps.c and (new) tmps.h.  correctly emit LBRAC lines.  allocate registers
c from high to low.  put in data structures for multiple types of registers.
e
s 00004/00000/00275
d D 1.22 82/08/12 00:11:03 mckusick 22 21
c complain in segend() when trying to compile with -z (ie for pxp counters).
e
s 00010/00003/00265
d D 1.21 82/08/11 23:08:59 mckusick 21 20
c add "pxp" counter to external routines, in case they are locally resolved.
e
s 00019/00007/00249
d D 1.20 81/06/01 15:35:36 peter 20 19
c add storage classes to namelist, and use them.
e
s 00002/00001/00254
d D 1.19 81/03/23 18:37:49 mckusic 19 18
c check for syntax error before panicing
e
s 00006/00002/00249
d D 1.18 81/03/16 18:12:23 mckusic 18 17
c add temporary register allocation
e
s 00004/00004/00247
d D 1.17 81/03/11 23:36:56 mckusic 17 16
c centralize temporary allocation in tmps.c
e
s 00001/00904/00250
d D 1.16 81/03/11 14:11:39 mckusic 16 15
c break out funchdr and funcend
e
s 00001/00001/01153
d D 1.15 81/03/08 19:43:35 mckusic 15 14
c put back id keywords which inadvertently got lost...
e
s 00036/00031/01118
d D 1.14 81/03/08 19:24:52 mckusic 14 13
c merge in onyx changes
e
s 00012/00002/01137
d D 1.13 81/01/24 16:20:46 mckusic 13 12
c change name size count to entire header size count
e
s 00010/00000/01129
d D 1.12 81/01/16 18:47:51 mckusic 12 11
c allow runtime tests to be dynamically changed at routine entry/exit
e
s 00035/00015/01094
d D 1.11 81/01/15 13:23:22 peter 11 10
c get sdb stabs into the right places.  use nm -ap for details.
e
s 00002/00002/01107
d D 1.10 81/01/13 15:07:03 mckusic 10 9
c change ``ZFRAME'' to ``blkclr''
e
s 00001/00001/01108
d D 1.9 81/01/10 16:59:45 mckusic 9 8
c convert to "fp", "ap" type display; fix SUCC and PRED
e
s 00005/00006/01104
d D 1.8 81/01/06 17:14:10 mckusic 8 7
c modify to allow use of px written in `C' and the use of libpc
e
s 00002/00001/01108
d D 1.7 80/10/28 21:10:09 peter 7 6
c add warnings for extensions to language
e
s 00001/00001/01108
d D 1.6 80/10/27 12:34:36 peter 6 5
c round up size of arguments for NARGCHK call.
e
s 00003/00002/01106
d D 1.5 80/10/10 13:42:20 peter 5 4
c non-scalar function returns from static area
e
s 00065/00014/01043
d D 1.4 80/10/03 01:07:37 peter 4 3
c Implement formal functions and procedures
e
s 00006/00002/01051
d D 1.3 80/09/02 22:05:37 peter 3 2
c interleaved declaration parts
e
s 00006/00005/01047
d D 1.2 80/08/31 17:30:56 peter 2 1
c stabs for separate compilation type checking
e
s 01052/00000/00000
d D 1.1 80/08/27 19:55:01 peter 1 0
c date and time created 80/08/27 19:55:01 by peter
e
u
U
t
T
I 1
D 28
/* Copyright (c) 1979 Regents of the University of California */
E 28
I 28
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 28

I 24
#ifndef lint
E 24
D 14
static	char sccsid[] = "%Z%%M% %I% %G%";
E 14
I 14
D 15
static	char sccsid[] = "@(#)fdec.c 1.13 1/24/81";
E 15
I 15
D 28
static char sccsid[] = "%Z%%M% %I% %G%";
I 24
#endif
E 28
I 28
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 28
E 24
E 15
E 14

#include "whoami.h"
#include "0.h"
#include "tree.h"
#include "opcode.h"
#include "objfmt.h"
#include "align.h"
I 23
#include "tmps.h"
E 23

/*
 * this array keeps the pxp counters associated with
 * functions and procedures, so that they can be output
 * when their bodies are encountered
 */
int	bodycnts[ DSPLYSZ ];

#ifdef PC
#   include "pc.h"
D 27
#   include "pcops.h"
E 27
I 27
#   include <pcc.h>
E 27
#endif PC

#ifdef OBJ
int	cntpatch;
int	nfppatch;
#endif OBJ

D 16
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
	int *r;
{
	register struct nl *p;
	register *il, **rl;
	int *rll;
	struct nl *cp, *dp, *sp;
D 14
	int s, o, *pp;
E 14
I 14
	int w, s, o, *pp;
E 14

	if (inpflist(r[2])) {
		opush('l');
		yyretrieve();	/* kludge */
	}
	pfcnt++;
I 3
	parts[ cbn ] |= RPRT;
E 3
	line = r[1];
	if (r[3] == NIL && (p=lookup1(r[2])) != NIL && bn == cbn) {
		/*
		 * Symbol already defined
		 * in this block. it is either
		 * a redeclared symbol (error)
		 * a forward declaration,
		 * or an external declaration.
		 */
		if ((p->class == FUNC || p->class == PROC) && (p->nl_flags & NFORWD) != 0) {
			/*
			 * Grammar doesnt forbid
			 * types on a resolution
			 * of a forward function
			 * declaration.
			 */
			if (p->class == FUNC && r[4])
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

	 if ((r[0] != T_PROG) && (!progseen))
		level1();


	/*
	 * Declare the prog/proc/func
	 */
	switch (r[0]) {
	    case T_PROG:
D 14
		    progseen++;
E 14
I 14
		    progseen = TRUE;
E 14
		    if (opt('z'))
D 14
			    monflg++;
E 14
I 14
			    monflg = TRUE;
E 14
		    program = p = defnl(r[2], PROG, 0, 0);
		    p->value[3] = r[1];
		    break;
	    case T_PDEC:
		    if (r[4] != NIL)
			    error("Procedures do not have types, only functions do");
		    p = enter(defnl(r[2], PROC, 0, 0));
		    p->nl_flags |= NMOD;
#		    ifdef PC
			enclosing[ cbn ] = r[2];
#		    endif PC
		    break;
	    case T_FDEC:
		    il = r[4];
		    if (il == NIL)
			    error("Function type must be specified");
		    else if (il[0] != T_TYID) {
			    il = NIL;
			    error("Function type can be specified only by using a type identifier");
		    } else
			    il = gtype(il);
		    p = enter(defnl(r[2], FUNC, il, NIL));
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
I 7
				    warning();
E 7
D 4
				    warning();
				    if (opt('s'))
E 4
I 4
				    if (opt('s')) {
E 4
					    standard();
D 4
				    error("Functions should not return %ss", clnames[o]);
E 4
I 4
D 7
					    error("Functions should not return %ss", clnames[o]);
E 7
				    }
I 7
				    error("Functions should not return %ss", clnames[o]);
E 7
E 4
		    }
#		    ifdef PC
			enclosing[ cbn ] = r[2];
#		    endif PC
		    break;
	    default:
		    panic("funchdr");
	}
	if (r[0] != T_PROG) {
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
			    cp = defnl(r[2], FVAR, p->type, 0);
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

D 14
			    cp = defnl( r[2] , FVAR , p -> type
				      , -( roundup( DPOFF1+width( p -> type )
						  , align( p -> type ) ) ) );
E 14
I 14
			    cp = defnl(r[2], FVAR, p->type,
				    -(roundup((int)(DPOFF1+lwidth(p->type)),
					(long)align(p->type))));
E 14
#			endif PC
			cp->chain = p;
			p->ptr[NL_FVAR] = cp;
		}
		/*
		 * Enter the parameters
		 * and compute total size
		 */
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
D 14
						dp = defnl(il[1], VAR, p, o -= even(width(p)));
E 14
I 14
						w = width(p);
						o -= even(w);
#						ifdef DEC11
						    dp = defnl(il[1], VAR, p, o);
#						else
						    dp = defnl(il[1], VAR, p,
							(w < 2) ? o + 1 : o);
#						endif DEC11
E 14
#					    endif OBJ
#					    ifdef PC
						dp = defnl( il[1] , VAR , p 
D 14
							, o = roundup( o , A_STACK ) );
E 14
I 14
							, o = roundup( o , (long)A_STACK ) );
E 14
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
D 14
							, o = roundup( o , A_STACK ) );
E 14
I 14
							, o = roundup( o , (long)A_STACK ) );
E 14
						o += sizeof(char *);
#					    endif PC
					    break;
				    case T_PFUNC:
I 4
#					    ifdef OBJ
						dp = defnl(il[1], FFUNC, p, o -= sizeof ( int * ) );
#					    endif OBJ
#					    ifdef PC
						dp = defnl( il[1] , FFUNC , p
D 14
							, o = roundup( o , A_STACK ) );
E 14
I 14
							, o = roundup( o , (long)A_STACK ) );
E 14
						o += sizeof(char *);
#					    endif PC
					    dp -> nl_flags |= NMOD;
					    break;
E 4
				    case T_PPROC:
D 4
					    error("Procedure/function parameters not implemented");
					    continue;
E 4
I 4
#					    ifdef OBJ
						dp = defnl(il[1], FPROC, p, o -= sizeof ( int * ) );
#					    endif OBJ
#					    ifdef PC
						dp = defnl( il[1] , FPROC , p
D 14
							, o = roundup( o , A_STACK ) );
E 14
I 14
							, o = roundup( o , (long)A_STACK ) );
E 14
						o += sizeof(char *);
#					    endif PC
					    dp -> nl_flags |= NMOD;
					    break;
E 4
				    }
				if (dp != NIL) {
					cp->chain = dp;
					cp = dp;
				}
			}
		}
		cbn--;
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
D 6
		    p -> value[ NL_OFFS ] = o;
E 6
I 6
D 14
		    p -> value[ NL_OFFS ] = roundup( o , A_STACK );
E 14
I 14
		    p -> value[ NL_OFFS ] = roundup( o , (long)A_STACK );
E 14
E 6
#		endif PC
	} else { 
		/*
		 * The wonderful
		 * program statement!
		 */
#		ifdef OBJ
		    if (monflg) {
			    put(1, O_PXPBUF);
D 14
			    cntpatch = put(2, O_CASE4, 0);
			    nfppatch = put(2, O_CASE4, 0);
E 14
I 14
			    cntpatch = put(2, O_CASE4, (long)0);
			    nfppatch = put(2, O_CASE4, (long)0);
E 14
		    }
#		endif OBJ
		cp = p;
		for (rl = r[3]; rl; rl = rl[2]) {
			if (rl[1] == NIL)
				continue;
			dp = defnl(rl[1], VAR, 0, 0);
			cp->chain = dp;
			cp = dp;
		}
	}
	/*
	 * Define a branch at
	 * the "entry point" of
	 * the prog/proc/func.
	 */
	p->entloc = getlab();
	if (monflg) {
		bodycnts[ cbn ] = getcnt();
		p->value[ NL_CNTR ] = 0;
	}
#	ifdef OBJ
D 14
	    put(2, O_TRA4, p->entloc);
E 14
I 14
	    put(2, O_TRA4, (long)p->entloc);
E 14
#	endif OBJ
#	ifdef PTREE
	    {
		pPointer	PF = tCopy( r );

		pSeize( PorFHeader[ nesting ] );
		if ( r[0] != T_PROG ) {
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
}

funcfwd(fp)
E 16
I 16
funcfwd(fp)
E 16
	struct nl *fp;
{

	    /*
	     *	save the counter for this function
	     */
	if ( monflg ) {
	    fp -> value[ NL_CNTR ] = bodycnts[ cbn ];
	}
D 24
	return (fp);
E 24
}

/*
 * Funcext marks the procedure or
 * function external in the symbol
 * table. Funcext should only be
 * called if PC, and is an error
 * otherwise.
 */

I 24
struct nl *
E 24
funcext(fp)
	struct nl *fp;
{

I 21
#ifdef OBJ
	error("Procedures or functions cannot be declared external.");
#endif OBJ

E 21
#ifdef PC
I 21
	    /*
	     *	save the counter for this function
	     */
	if ( monflg ) {
	    fp -> value[ NL_CNTR ] = bodycnts[ cbn ];
	}
E 21
 	if (opt('s')) {
		standard();
		error("External procedures and functions are not standard");
	} else {
		if (cbn == 1) {
D 20
			fp->ext_flags |= NEXTERN;
E 20
I 20
			fp->extra_flags |= NEXTERN;
E 20
D 2
			stabefunc( fp -> symbol , line);
E 2
I 2
			stabefunc( fp -> symbol , fp -> class , line );
E 2
		}
		else
			error("External procedures and functions can only be declared at the outermost level.");
	}
#endif PC
D 21
#ifdef OBJ
	error("Procedures or functions cannot be declared external.");
#endif OBJ
E 21

	return(fp);
}

/*
 * Funcbody is called
 * when the actual (resolved)
 * declaration of a procedure is
 * encountered. It puts the names
 * of the (function) and parameters
 * into the symbol table.
 */
I 24
struct nl *
E 24
funcbody(fp)
	struct nl *fp;
{
D 24
	register struct nl *q, *p;
E 24
I 24
	register struct nl *q;
E 24
I 20
D 23
	struct nl	*functemp;
E 23
E 20

	cbn++;
	if (cbn >= DSPLYSZ) {
		error("Too many levels of function/procedure nesting");
		pexit(ERRS);
	}
D 17
	sizes[cbn].om_max = sizes[cbn].om_off = -DPOFF1;
E 17
I 17
D 23
	sizes[cbn].om_max = sizes[cbn].curtmps.om_off = -DPOFF1;
I 18
	sizes[cbn].reg_max = -1;
	sizes[cbn].curtmps.reg_off = 0;
E 23
I 23
	tmpinit(cbn);
E 23
E 18
E 17
	gotos[cbn] = NIL;
	errcnt[cbn] = syneflg;
D 3
	parts = NIL;
E 3
I 3
	parts[ cbn ] = NIL;
E 3
	dfiles[ cbn ] = FALSE;
	if (fp == NIL)
		return (NIL);
	/*
	 * Save the virtual name
	 * list stack pointer so
	 * the space can be freed
	 * later (funcend).
	 */
	fp->ptr[2] = nlp;
D 11
#	ifdef PC
	    if ( fp -> class != PROG ) {
D 2
		stabfunc( fp -> symbol , line , cbn - 1 );
E 2
I 2
		stabfunc( fp -> symbol , fp -> class , line , cbn - 1 );
E 2
	    } else {
D 2
		stabfunc( "program" , line , 0 );
E 2
I 2
		stabfunc( "program" , fp -> class , line , 0 );
E 2
	    }
#	endif PC
E 11
	if (fp->class != PROG) {
		for (q = fp->chain; q != NIL; q = q->chain) {
D 24
			enter(q);
E 24
I 24
			(void) enter(q);
E 24
I 20
#			ifdef PC
			    q -> extra_flags |= NPARAM;
#			endif PC
E 20
D 11
#			ifdef PC
			    stabparam( q -> symbol , p2type( q -> type )
					, q -> value[ NL_OFFS ]
					, lwidth( q -> type ) );
#			endif PC
E 11
		}
	}
	if (fp->class == FUNC) {
		/*
		 * For functions, enter the fvar
		 */
D 24
		enter(fp->ptr[NL_FVAR]);
E 24
I 24
		(void) enter(fp->ptr[NL_FVAR]);
E 24
#		ifdef PC
		    q = fp -> ptr[ NL_FVAR ];
D 17
		    sizes[cbn].om_off -= lwidth( q -> type );
		    sizes[cbn].om_max = sizes[cbn].om_off;
E 17
I 17
D 18
		    sizes[cbn].curtmps.om_off -= lwidth( q -> type );
		    sizes[cbn].om_max = sizes[cbn].curtmps.om_off;
E 18
I 18
D 19
		    if (q -> ptr[ NL_OFFS ] != tmpalloc(leven(roundup(
E 19
I 19
D 20
		    if (q -> type != NIL &&
			q -> ptr[ NL_OFFS ] != tmpalloc(leven(roundup(
E 19
			    (int)lwidth(q -> type), (long)align(q -> type))),
			q -> type, NOREG))
E 20
I 20
		    if (q -> type != NIL ) {
D 23
			functemp = tmpalloc(
					leven(
					    roundup(
						(int)lwidth(q -> type),
						(long)align(q -> type))),
					q -> type, NOREG);
			if ( q -> ptr[NL_OFFS] != functemp->value[NL_OFFS] )
E 20
			    panic("func var");
E 23
I 23
			sizes[cbn].curtmps.om_off = q -> value[NL_OFFS];
			sizes[cbn].om_max = q -> value[NL_OFFS];
E 23
I 20
		    }
D 23
		    q -> extra_flags |= functemp -> extra_flags;
E 23
E 20
E 18
E 17
D 2
		    stabvar( q -> symbol , p2type( q -> type )
			    , q -> value[ NL_OFFS ] , lwidth( q -> type ) );
E 2
I 2
D 11
		    stabvar( q -> symbol , p2type( q -> type ) , cbn 
			    , q -> value[ NL_OFFS ] , lwidth( q -> type )
			    , line );
E 11
E 2
#		endif PC
	}
#	ifdef PTREE
		/*
		 *	pick up the pointer to porf declaration
		 */
	    PorFHeader[ ++nesting ] = fp -> inTree;
#	endif PTREE
	return (fp);
}
D 16

struct	nl *Fp;
int	pnumcnt;
/*
 * Funcend is called to
 * finish a block by generating
 * the code for the statements.
 * It then looks for unresolved declarations
 * of labels, procedures and functions,
 * and cleans up the name list.
 * For the program, it checks the
 * semantics of the program
 * statement (yuchh).
 */
funcend(fp, bundle, endline)
	struct nl *fp;
	int *bundle;
	int endline;
{
	register struct nl *p;
	register int i, b;
D 14
	int var, inp, out, chkref, *blk;
E 14
I 14
	int var, inp, out, *blk;
	bool chkref;
E 14
	struct nl *iop;
	char *cp;
	extern int cntstat;
#	ifdef PC
	    int	toplabel = getlab();
	    int	botlabel = getlab();
#	endif PC

	cntstat = 0;
/*
 *	yyoutline();
 */
	if (program != NIL)
		line = program->value[3];
	blk = bundle[2];
	if (fp == NIL) {
		cbn--;
#		ifdef PTREE
		    nesting--;
#		endif PTREE
		return;
	}
#ifdef OBJ
	/*
	 * Patch the branch to the
	 * entry point of the function
	 */
	patch4(fp->entloc);
	/*
	 * Put out the block entrance code and the block name.
D 13
	 * the CONG is overlaid by a patch later!
E 13
I 13
	 * HDRSZE is the number of bytes of info in the static
	 * BEG data area exclusive of the proc name. It is
	 * currently defined as:
	/*	struct hdr {
	/*		long framesze;	/* number of bytes of local vars */
	/*		long nargs;	/* number of bytes of arguments */
D 14
	/*		short tests;	/* TRUE => perform runtime tests */
E 14
I 14
	/*		bool tests;	/* TRUE => perform runtime tests */
E 14
	/*		short offset;	/* offset of procedure in source file */
	/*		char name[1];	/* name of active procedure */
	/*	};
E 13
	 */
D 13
	var = put(2, (lenstr(fp->symbol,0) << 8)
E 13
I 13
D 14
#	define HDRSZE 12
	var = put(2, (lenstr(fp->symbol,0) + HDRSZE << 8)
E 13
			| (cbn == 1 && opt('p') == 0 ? O_NODUMP: O_BEG), 0);
E 14
I 14
#	define HDRSZE (2 * sizeof(long) + sizeof(short) + sizeof(bool))
	var = put(2, ((lenstr(fp->symbol,0) + HDRSZE) << 8)
		| (cbn == 1 && opt('p') == 0 ? O_NODUMP: O_BEG), (long)0);
E 14
I 4
	    /*
	     *  output the number of bytes of arguments
	     *  this is only checked on formal calls.
	     */
D 14
	put(2, O_CASE4, cbn == 1 ? 0 : fp->value[NL_OFFS]-DPOFF2);
E 14
I 14
	put(2, O_CASE4, cbn == 1 ? (long)0 : (long)(fp->value[NL_OFFS]-DPOFF2));
E 14
I 12
	    /*
	     *	Output the runtime test mode for the routine
	     */
D 14
	if (opt('t'))
		put(2, O_CASE2, TRUE);
	else
		put(2, O_CASE2, FALSE);
E 14
I 14
	put(2, sizeof(bool) == 2 ? O_CASE2 : O_CASE4, opt('t') ? TRUE : FALSE);
E 14
	    /*
	     *	Output line number and routine name
	     */
E 12
E 4
	put(2, O_CASE2, bundle[1]);
	putstr(fp->symbol, 0);
#endif OBJ
#ifdef PC
	/*
	 * put out the procedure entry code
	 */
	if ( fp -> class == PROG ) {
	    putprintf( "	.text" , 0 );
	    putprintf( "	.align	1" , 0 );
	    putprintf( "	.globl	_main" , 0 );
	    putprintf( "_main:" , 0 );
	    putprintf( "	.word	0" , 0 );
	    putprintf( "	calls	$0,_PCSTART" , 0 );
	    putprintf( "	movl	4(ap),__argc" , 0 );
	    putprintf( "	movl	8(ap),__argv" , 0 );
	    putprintf( "	calls	$0,_program" , 0 );
	    putprintf( "	calls	$0,_PCEXIT" , 0 );
	    ftnno = fp -> entloc;
	    putprintf( "	.text" , 0 );
	    putprintf( "	.align	1" , 0 );
	    putprintf( "	.globl	_program" , 0 );
	    putprintf( "_program:" , 0 );
I 11
	    stabfunc( "program" , fp -> class , bundle[1] , 0 );
E 11
	} else {
	    ftnno = fp -> entloc;
	    putprintf( "	.text" , 0 );
	    putprintf( "	.align	1" , 0 );
	    putprintf( "	.globl	" , 1 );
	    for ( i = 1 ; i < cbn ; i++ ) {
		putprintf( EXTFORMAT , 1 , enclosing[ i ] );
	    }
	    putprintf( "" , 0 );
	    for ( i = 1 ; i < cbn ; i++ ) {
		putprintf( EXTFORMAT , 1 , enclosing[ i ] );
	    }
	    putprintf( ":" , 0 );
I 11
	    stabfunc( fp -> symbol , fp -> class , bundle[1] , cbn - 1 );
	    for ( p = fp -> chain ; p != NIL ; p = p -> chain ) {
		stabparam( p -> symbol , p2type( p -> type )
			    , p -> value[ NL_OFFS ] , lwidth( p -> type ) );
	    }
	    if ( fp -> class == FUNC ) {
		    /*
		     *	stab the function variable
		     */
		p = fp -> ptr[ NL_FVAR ];
		stablvar( p -> symbol , p2type( p -> type ) , cbn 
			, p -> value[ NL_OFFS ] , lwidth( p -> type ) );
	    }
		/*
		 *	stab local variables
		 *	rummage down hash chain links.
		 */
	    for ( i = 0 ; i <= 077 ; i++ ) {
		for ( p = disptab[ i ] ; p != NIL ; p = p->nl_next) {
		    if ( ( p -> nl_block & 037 ) != cbn ) {
			break;
		    }
		    /*
		     *	stab local variables
		     *	that's named variables, but not params
		     */
		    if (   ( p -> symbol != NIL ) 
			&& ( p -> class == VAR )
			&& ( p -> value[ NL_OFFS ] < 0 ) ) {
			stablvar( p -> symbol , p2type( p -> type ) , cbn 
			    , p -> value[ NL_OFFS ] , lwidth( p -> type ) );
		    }
		}
	    }
E 11
	}
	stablbrac( cbn );
	    /*
	     *	register save mask
	     */
	if ( opt( 't' ) ) {
	    putprintf( "	.word	0x%x" , 0 , RUNCHECK | RSAVEMASK );
	} else {
	    putprintf( "	.word	0x%x" , 0 , RSAVEMASK );
	}
	putjbr( botlabel );
	putlab( toplabel );
	if ( profflag ) {
		/*
		 *	call mcount for profiling
		 */
	    putprintf( "	moval	1f,r0" , 0 );
	    putprintf( "	jsb	mcount" , 0 );
	    putprintf( "	.data" , 0 );
	    putprintf( "	.align	2" , 0 );
	    putprintf( "1:" , 0 );
	    putprintf( "	.long	0" , 0 );
	    putprintf( "	.text" , 0 );
	}
	    /*
	     *	set up unwind exception vector.
	     */
	putprintf( "	moval	%s,%d(%s)" , 0
		, UNWINDNAME , UNWINDOFFSET , P2FPNAME );
	    /*
	     *	save address of display entry, for unwind.
	     */
	putprintf( "	moval	%s+%d,%d(%s)" , 0
		, DISPLAYNAME , cbn * sizeof(struct dispsave)
		, DPTROFFSET , P2FPNAME );
	    /*
	     *	save old display 
	     */
	putprintf( "	movq	%s+%d,%d(%s)" , 0
		, DISPLAYNAME , cbn * sizeof(struct dispsave)
		, DSAVEOFFSET , P2FPNAME );
	    /*
	     *	set up new display by saving AP and FP in appropriate
	     *	slot in display structure.
	     */
	putprintf( "	movq	%s,%s+%d" , 0
		, P2APNAME , DISPLAYNAME , cbn * sizeof(struct dispsave) );
	    /*
	     *	ask second pass to allocate known locals
	     */
	putlbracket( ftnno , -sizes[ cbn ].om_max );
	    /*
	     *	and zero them if checking is on
D 10
	     *	by calling zframe( bytes of locals , highest local address );
E 10
I 10
	     *	by calling blkclr( bytes of locals , starting local address );
E 10
	     */
D 4
	if ( opt( 't' ) && ( -sizes[ cbn ].om_max ) > DPOFF1 ) {
	    putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
		    , "_ZFRAME" );
	    putleaf( P2ICON ,  ( -sizes[ cbn ].om_max ) - DPOFF1
		    , 0 , P2INT , 0 );
	    putLV( 0 , cbn , sizes[ cbn ].om_max , P2CHAR );
	    putop( P2LISTOP , P2INT );
	    putop( P2CALL , P2INT );
	    putdot( filename , line );
E 4
I 4
	if ( opt( 't' ) ) {
	    if ( ( -sizes[ cbn ].om_max ) > DPOFF1 ) {
		putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
D 10
			, "_ZFRAME" );
E 10
I 10
			, "_blkclr" );
E 10
		putleaf( P2ICON ,  ( -sizes[ cbn ].om_max ) - DPOFF1
			, 0 , P2INT , 0 );
		putLV( 0 , cbn , sizes[ cbn ].om_max , P2CHAR );
		putop( P2LISTOP , P2INT );
		putop( P2CALL , P2INT );
		putdot( filename , line );
	    }
		/*
		 *  check number of longs of arguments
		 *  this can only be wrong for formal calls.
		 */
	    if ( fp -> class != PROG ) {
		    putleaf( P2ICON , 0 , 0 , ADDTYPE( P2PTR , P2FTN | P2INT ) ,
			    "_NARGCHK" );
		    putleaf( P2ICON ,
			(fp->value[NL_OFFS] - DPOFF2) / sizeof(long) ,
			0 , P2INT , 0 );
		    putop( P2CALL , P2INT );
		    putdot( filename , line );
	    }
E 4
	}
#endif PC
	if ( monflg ) {
		if ( fp -> value[ NL_CNTR ] != 0 ) {
			inccnt( fp -> value [ NL_CNTR ] );
		}
		inccnt( bodycnts[ fp -> nl_block & 037 ] );
	}
	if (fp->class == PROG) {
		/*
		 * The glorious buffers option.
		 *          0 = don't buffer output
		 *          1 = line buffer output
		 *          2 = 512 byte buffer output
		 */
#		ifdef OBJ
		    if (opt('b') != 1)
			    put(1, O_BUFF | opt('b') << 8);
#		endif OBJ
#		ifdef PC
		    if ( opt( 'b' ) != 1 ) {
			putleaf( P2ICON , 0 , 0
				, ADDTYPE( P2FTN | P2INT , P2PTR ) , "_BUFF" );
			putleaf( P2ICON , opt( 'b' ) , 0 , P2INT , 0 );
			putop( P2CALL , P2INT );
			putdot( filename , line );
		    }
#		endif PC
		out = 0;
		for (p = fp->chain; p != NIL; p = p->chain) {
			if (strcmp(p->symbol, "input") == 0) {
				inp++;
				continue;
			}
			if (strcmp(p->symbol, "output") == 0) {
				out++;
				continue;
			}
			iop = lookup1(p->symbol);
			if (iop == NIL || bn != cbn) {
				error("File %s listed in program statement but not declared", p->symbol);
				continue;
			}
			if (iop->class != VAR) {
				error("File %s listed in program statement but declared as a %s", p->symbol, classes[iop->class]);
				continue;
			}
			if (iop->type == NIL)
				continue;
			if (iop->type->class != FILET) {
				error("File %s listed in program statement but defined as %s",
					p->symbol, nameof(iop->type));
				continue;
			}
#			ifdef OBJ
D 8
			    put(2, O_LV | bn << 8+INDX, iop->value[NL_OFFS]);
E 8
I 8
			    put(2, O_CON24, text(iop->type) ? 0 : width(iop->type->type));
E 8
			    i = lenstr(p->symbol,0);
I 8
			    put(2, O_CON24, i);
E 8
			    put(2, O_LVCON, i);
			    putstr(p->symbol, 0);
D 8
			    do {
				i--;
			    } while (p->symbol+i == 0);
			    put(2, O_CON24, i+1);
			    put(2, O_CON24, text(iop->type) ? 0 : width(iop->type->type));
E 8
I 8
D 14
			    put(2, O_LV | bn << 8+INDX, iop->value[NL_OFFS]);
E 14
I 14
			    put(2, O_LV | bn<<8+INDX, (int)iop->value[NL_OFFS]);
E 14
E 8
			    put(1, O_DEFNAME);
#			endif OBJ
#			ifdef PC
			    putleaf( P2ICON , 0 , 0
				    , ADDTYPE( P2FTN | P2INT , P2PTR )
				    , "_DEFNAME" );
			    putLV( p -> symbol , bn , iop -> value[NL_OFFS]
				    , p2type( iop ) );
			    putCONG( p -> symbol , strlen( p -> symbol )
				    , LREQ );
			    putop( P2LISTOP , P2INT );
			    putleaf( P2ICON , strlen( p -> symbol )
				    , 0 , P2INT , 0 );
			    putop( P2LISTOP , P2INT );
			    putleaf( P2ICON
				, text(iop->type) ? 0 : width(iop->type->type)
				, 0 , P2INT , 0 );
			    putop( P2LISTOP , P2INT );
			    putop( P2CALL , P2INT );
			    putdot( filename , line );
#			endif PC
		}
		if (out == 0 && fp->chain != NIL) {
			recovered();
			error("The file output must appear in the program statement file list");
		}
	}
	/*
	 * Process the prog/proc/func body
	 */
	noreach = 0;
	line = bundle[1];
	statlist(blk);
#	ifdef PTREE
	    {
		pPointer Body = tCopy( blk );

		pDEF( PorFHeader[ nesting -- ] ).PorFBody = Body;
	    }
#	endif PTREE
#	ifdef OBJ
	    if (cbn== 1 && monflg != 0) {
D 14
		    patchfil(cntpatch - 2, cnts, 2);
		    patchfil(nfppatch - 2, pfcnt, 2);
E 14
I 14
		    patchfil(cntpatch - 2, (long)cnts, 2);
		    patchfil(nfppatch - 2, (long)pfcnt, 2);
E 14
	    }
#	endif OBJ
#	ifdef PC
	    if ( fp -> class == PROG && monflg ) {
		putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
			, "_PMFLUSH" );
		putleaf( P2ICON , cnts , 0 , P2INT , 0 );
		putleaf( P2ICON , pfcnt , 0 , P2INT , 0 );
I 8
		putop( P2LISTOP , P2INT );
		putLV( PCPCOUNT , 0 , 0 , P2INT );
E 8
		putop( P2LISTOP , P2INT );
		putop( P2CALL , P2INT );
		putdot( filename , line );
	    }
#	endif PC
	if (fp->class == PROG && inp == 0 && (input->nl_flags & (NUSED|NMOD)) != 0) {
		recovered();
		error("Input is used but not defined in the program statement");
	}
	/*
	 * Clean up the symbol table displays and check for unresolves
	 */
	line = endline;
	b = cbn;
	Fp = fp;
	chkref = syneflg == errcnt[cbn] && opt('w') == 0;
	for (i = 0; i <= 077; i++) {
		for (p = disptab[i]; p != NIL && (p->nl_block & 037) == b; p = p->nl_next) {
			/*
			 * Check for variables defined
			 * but not referenced 
			 */
			if (chkref && p->symbol != NIL)
			switch (p->class) {
				case FIELD:
					/*
					 * If the corresponding record is
					 * unused, we shouldn't complain about
					 * the fields.
					 */
				default:
					if ((p->nl_flags & (NUSED|NMOD)) == 0) {
						warning();
						nerror("%s %s is neither used nor set", classes[p->class], p->symbol);
						break;
					}
					/*
					 * If a var parameter is either
					 * modified or used that is enough.
					 */
					if (p->class == REF)
						continue;
#					ifdef OBJ
					    if ((p->nl_flags & NUSED) == 0) {
						warning();
						nerror("%s %s is never used", classes[p->class], p->symbol);
						break;
					    }
#					endif OBJ
#					ifdef PC
					    if (((p->nl_flags & NUSED) == 0) && ((p->ext_flags & NEXTERN) == 0)) {
						warning();
						nerror("%s %s is never used", classes[p->class], p->symbol);
						break;
					    }
#					endif PC
					if ((p->nl_flags & NMOD) == 0) {
						warning();
						nerror("%s %s is used but never set", classes[p->class], p->symbol);
						break;
					}
				case LABEL:
				case FVAR:
				case BADUSE:
					break;
			}
			switch (p->class) {
				case BADUSE:
					cp = "s";
					if (p->chain->ud_next == NIL)
						cp++;
					eholdnl();
					if (p->value[NL_KINDS] & ISUNDEF)
						nerror("%s undefined on line%s", p->symbol, cp);
					else
						nerror("%s improperly used on line%s", p->symbol, cp);
					pnumcnt = 10;
					pnums(p->chain);
					pchr('\n');
					break;

				case FUNC:
				case PROC:
#					ifdef OBJ
					    if ((p->nl_flags & NFORWD))
						nerror("Unresolved forward declaration of %s %s", classes[p->class], p->symbol);
#					endif OBJ
#					ifdef PC
					    if ((p->nl_flags & NFORWD) && ((p->ext_flags & NEXTERN) == 0))
						nerror("Unresolved forward declaration of %s %s", classes[p->class], p->symbol);
#					endif PC
					break;

				case LABEL:
					if (p->nl_flags & NFORWD)
						nerror("label %s was declared but not defined", p->symbol);
					break;
				case FVAR:
					if ((p->nl_flags & NMOD) == 0)
						nerror("No assignment to the function variable");
					break;
			}
		}
		/*
		 * Pop this symbol
		 * table slot
		 */
		disptab[i] = p;
	}

#	ifdef OBJ
	    put(1, O_END);
#	endif OBJ
#	ifdef PC
		/*
		 *	if there were file variables declared at this level
		 *	call pclose( &__disply[ cbn ] ) to clean them up.
		 */
	    if ( dfiles[ cbn ] ) {
		putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
			, "_PCLOSE" );
		putRV( DISPLAYNAME , 0 , cbn * sizeof( struct dispsave )
			, P2PTR | P2CHAR );
		putop( P2CALL , P2INT );
		putdot( filename , line );
	    }
		/*
		 *	if this is a function,
		 *	the function variable is the return value.
		 *	if it's a scalar valued function, return scalar,
		 *	else, return a pointer to the structure value.
		 */
	    if ( fp -> class == FUNC ) {
		struct nl	*fvar = fp -> ptr[ NL_FVAR ];
		long		fvartype = p2type( fvar -> type );
I 4
		long		label;
		char		labelname[ BUFSIZ ];
E 4

		switch ( classify( fvar -> type ) ) {
		    case TBOOL:
		    case TCHAR:
		    case TINT:
		    case TSCAL:
		    case TDOUBLE:
		    case TPTR:
			putRV( fvar -> symbol , ( fvar -> nl_block ) & 037
				, fvar -> value[ NL_OFFS ] , fvartype );
			break;
		    default:
I 4
			label = getlab();
			sprintf( labelname , PREFIXFORMAT ,
				LABELPREFIX , label );
			putprintf( "	.data" , 0 );
			putprintf( "	.lcomm	%s,%d" , 0 ,
				    labelname , lwidth( fvar -> type ) );
			putprintf( "	.text" , 0 );
D 5
			putRV( labelname , 0 , 0 , fvartype );
E 5
I 5
			putleaf( P2NAME , 0 , 0 , fvartype , labelname );
E 5
E 4
			putLV( fvar -> symbol , ( fvar -> nl_block ) & 037
				, fvar -> value[ NL_OFFS ] , fvartype );
I 4
			putstrop( P2STASG , fvartype , lwidth( fvar -> type ) ,
				align( fvar -> type ) );
D 5
			putLV( labelname , 0 , 0 , fvartype );
E 5
I 5
			putdot( filename , line );
			putleaf( P2ICON , 0 , 0 , fvartype , labelname );
E 5
E 4
			break;
		}
		putop( P2FORCE , fvartype );
		putdot( filename , line );
	    }
		/*
		 *	restore old display entry from save area
		 */

	    putprintf( "	movq	%d(%s),%s+%d" , 0
		, DSAVEOFFSET , P2FPNAME
		, DISPLAYNAME , cbn * sizeof(struct dispsave) );
	    stabrbrac( cbn );
	    putprintf( "	ret" , 0 );
		/*
		 *	let the second pass allocate locals
		 */
	    putlab( botlabel );
	    putprintf( "	subl2	$LF%d,sp" , 0 , ftnno );
	    putrbracket( ftnno );
	    putjbr( toplabel );
		/*
		 *	declare pcp counters, if any
		 */
	    if ( monflg && fp -> class == PROG ) {
		putprintf( "	.data" , 0 );
		putprintf( "	.comm	" , 1 );
		putprintf( PCPCOUNT , 1 );
		putprintf( ",%d" , 0 , ( cnts + 1 ) * sizeof (long) );
		putprintf( "	.text" , 0 );
	    }
#	endif PC
#ifdef DEBUG
	dumpnl(fp->ptr[2], fp->symbol);
#endif
	/*
	 * Restore the
	 * (virtual) name list
	 * position
	 */
	nlfree(fp->ptr[2]);
	/*
	 * Proc/func has been
	 * resolved
	 */
	fp->nl_flags &= ~NFORWD;
	/*
	 * Patch the beg
	 * of the proc/func to
	 * the proper variable size
	 */
	if (Fp == NIL)
		elineon();
#	ifdef OBJ
D 9
	    patchfil(var, sizes[cbn].om_max, 2);
E 9
I 9
D 14
	    patchfil(var, -sizes[cbn].om_max, 2);
E 14
I 14
	    patchfil(var, (long)(-sizes[cbn].om_max), 2);
E 14
E 9
#	endif OBJ
	cbn--;
	if (inpflist(fp->symbol)) {
		opop('l');
	}
}

E 16

/*
 * Segend is called to check for
 * unresolved variables, funcs and
 * procs, and deliver unresolved and
 * baduse error diagnostics at the
 * end of a routine segment (a separately
 * compiled segment that is not the 
 * main program) for PC. This
 * routine should only be called
 * by PC (not standard).
 */
 segend()
 {
I 24
#ifdef PC
E 24
	register struct nl *p;
	register int i,b;
	char *cp;

D 24
#ifdef PC
E 24
I 22
	if ( monflg ) {
	    error("Only the module containing the \"program\" statement");
	    cerror("can be profiled with ``pxp''.\n");
	}
E 22
	if (opt('s')) {
		standard();
		error("Separately compiled routine segments are not standard.");
	} else {
		b = cbn;
		for (i=0; i<077; i++) {
			for (p = disptab[i]; p != NIL && (p->nl_block & 037) == b; p = p->nl_next) {
			switch (p->class) {
				case BADUSE:
D 24
					cp = 's';
					if (p->chain->ud_next == NIL)
E 24
I 24
					cp = "s";
					if (((struct udinfo *) (p->chain))->ud_next == NIL)
E 24
						cp++;
					eholdnl();
					if (p->value[NL_KINDS] & ISUNDEF)
						nerror("%s undefined on line%s", p->symbol, cp);
					else
						nerror("%s improperly used on line%s", p->symbol, cp);
					pnumcnt = 10;
D 24
					pnums(p->chain);
E 24
I 24
					pnums((struct udinfo *) (p->chain));
E 24
					pchr('\n');
					break;
				
				case FUNC:
				case PROC:
D 20
					if ((p->nl_flags & NFORWD) && ((p->ext_flags & NEXTERN) == 0))
E 20
I 20
					if ((p->nl_flags & NFORWD) &&
					    ((p->extra_flags & NEXTERN) == 0))
E 20
						nerror("Unresolved forward declaration of %s %s", classes[p->class], p->symbol);
					break;

				case FVAR:
D 20
					if (((p->nl_flags & NMOD) == 0) && ((p->chain->ext_flags & NEXTERN) == 0))
E 20
I 20
					if (((p->nl_flags & NMOD) == 0) &&
					    ((p->chain->extra_flags & NEXTERN) == 0))
E 20
						nerror("No assignment to the function variable");
					break;
			    }
			   }
			   disptab[i] = p;
		    }
	}
#endif PC
#ifdef OBJ
	error("Missing program statement and program body");
#endif OBJ

}


/*
 * Level1 does level one processing for
 * separately compiled routine segments
 */
level1()
{

#	ifdef OBJ
	    error("Missing program statement");
#	endif OBJ
#	ifdef PC
	    if (opt('s')) {
		    standard();
		    error("Missing program statement");
	    }
#	endif PC

	cbn++;
D 17
	sizes[cbn].om_max = sizes[cbn].om_off = -DPOFF1;
E 17
I 17
D 23
	sizes[cbn].om_max = sizes[cbn].curtmps.om_off = -DPOFF1;
E 23
I 23
	tmpinit(cbn);
E 23
E 17
D 3
	parts = NIL;
E 3
I 3
	gotos[cbn] = NIL;
	errcnt[cbn] = syneflg;
	parts[ cbn ] = NIL;
	dfiles[ cbn ] = FALSE;
E 3
D 14
	progseen++;
E 14
I 14
	progseen = TRUE;
E 14
}



pnums(p)
	struct udinfo *p;
{

	if (p->ud_next != NIL)
		pnums(p->ud_next);
	if (pnumcnt == 0) {
		printf("\n\t");
		pnumcnt = 20;
	}
	pnumcnt--;
	printf(" %d", p->ud_line);
}

I 24
/*VARARGS*/
E 24
nerror(a1, a2, a3)
I 24
    char *a1,*a2,*a3;
E 24
{

	if (Fp != NIL) {
		yySsync();
#ifndef PI1
		if (opt('l'))
			yyoutline();
#endif
		yysetfile(filename);
		printf("In %s %s:\n", classes[Fp->class], Fp->symbol);
		Fp = NIL;
		elineoff();
	}
	error(a1, a2, a3);
}
E 1
