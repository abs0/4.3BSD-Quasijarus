h43242
s 00001/00001/00283
d D 5.4 88/01/03 00:13:02 bostic 14 13
c const is reserved for ANSI C
e
s 00002/00002/00282
d D 5.3 87/09/30 09:15:58 mckusick 13 12
c add second (currently unused except by pxp) argument
e
s 00000/00001/00284
d D 5.2 85/06/21 12:45:07 mckusick 12 11
c copyright botch
e
s 00007/00002/00278
d D 5.1 85/06/05 14:00:06 dist 11 10
c Add copyright
e
s 00000/00000/00280
d D 2.2 85/03/15 22:06:48 mckusick 10 8
i 9
c merge dbx mods
e
s 00005/00000/00264
d D 1.5.1.1 85/03/15 22:06:10 mckusick 9 5
c mods for dbx (from linton)
e
s 00000/00000/00275
d D 2.1 84/02/08 20:41:11 aoki 8 7
c synchronize to version 2
e
s 00000/00000/00275
d D 1.7 83/09/19 06:57:49 thien 7 6
c Restoring to unlinted version
e
s 00053/00042/00222
d D 1.6 83/08/19 04:55:56 thien 6 5
c The changes were made to allow successful linting
e
s 00017/00005/00247
d D 1.5 82/08/29 14:04:20 peter 5 4
c once-only error messages for multiple/out-of-order declarations.
e
s 00001/00001/00251
d D 1.4 80/09/04 23:09:33 peter 4 3
c N_PC stabs with subtypes
e
s 00018/00020/00234
d D 1.3 80/09/02 22:05:32 peter 3 2
c interleaved declaration parts
e
s 00003/00002/00251
d D 1.2 80/08/31 17:30:50 peter 2 1
c stabs for separate compilation type checking
e
s 00253/00000/00000
d D 1.1 80/08/27 19:54:46 peter 1 0
c date and time created 80/08/27 19:54:46 by peter
e
u
U
f b 
t
T
I 1
D 11
/* Copyright (c) 1979 Regents of the University of California */
E 11
I 11
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 11

I 6
#ifndef lint
E 6
D 11
static	char sccsid[] = "%Z%%M% %I% %G%";
E 11
I 11
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 11
I 6
D 12
#endif
E 12
E 6

#include "whoami.h"
#include "0.h"
#include "tree.h"
I 6
#include "tree_ty.h"
E 6

/*
 * Const enters the definitions
 * of the constant declaration
 * part into the namelist.
 */
#ifndef PI1
D 5
constbeg()
E 5
I 5
D 6
constbeg( lineofyconst , r )
E 6
I 6
D 13
constbeg( lineofyconst )
E 6
    int	lineofyconst;
E 13
I 13
constbeg( lineofyconst , linenum )
    int	lineofyconst, linenum;
E 13
E 5
{
I 5
    static bool	const_order = FALSE;
    static bool	const_seen = FALSE;
E 5

/*
D 3
 * PC allows for multiple declaration
E 3
I 3
 * this allows for multiple declaration
E 3
 * parts, unless the "standard" option
 * has been specified.
 * If a routine segment is being compiled,
 * do level one processing.
 */

	if (!progseen)
		level1();
I 5
	line = lineofyconst;
E 5
D 3
#    ifdef PC
    	if (opt('s')) {
		if (parts & (TPRT|VPRT)) {
			standard();
			error("Constant declarations must precede type and variable declarations");
		}
		if (parts & CPRT) {
			standard();
			error("All constants must be declared in one const part");
		}
        }
#    endif PC
#    ifdef OBJ
	if (parts & (TPRT|VPRT))
		error("Constant declarations must precede type and variable declarations");
	if (parts & CPRT)
		error("All constants must be declared in one const part");
#    endif OBJ
	parts |= CPRT;
E 3
I 3
	if (parts[ cbn ] & (TPRT|VPRT|RPRT)) {
	    if ( opt( 's' ) ) {
		standard();
I 5
		error("Constant declarations should precede type, var and routine declarations");
E 5
	    } else {
D 5
		warning();
E 5
I 5
		if ( !const_order ) {
		    const_order = TRUE;
		    warning();
		    error("Constant declarations should precede type, var and routine declarations");
		}
E 5
	    }
D 5
	    error("Constant declarations should precede type, var and routine declarations");
E 5
	}
	if (parts[ cbn ] & CPRT) {
	    if ( opt( 's' ) ) {
		standard();
I 5
		error("All constants should be declared in one const part");
E 5
	    } else {
D 5
		warning();
E 5
I 5
		if ( !const_seen ) {
		    const_seen = TRUE;
		    warning();
		    error("All constants should be declared in one const part");
		}
E 5
	    }
D 5
	    error("All constants should be declared in one const part");
E 5
	}
	parts[ cbn ] |= CPRT;
E 3
}
#endif PI1

D 14
const(cline, cid, cdecl)
E 14
I 14
constant(cline, cid, cdecl)
E 14
	int cline;
	register char *cid;
D 6
	register int *cdecl;
E 6
I 6
	register struct tnode *cdecl;
E 6
{
	register struct nl *np;

#ifdef PI0
	send(REVCNST, cline, cid, cdecl);
#endif
	line = cline;
	gconst(cdecl);
	np = enter(defnl(cid, CONST, con.ctype, con.cival));
#ifndef PI0
	np->nl_flags |= NMOD;
#endif

#ifdef PC
D 2
	if (cbn == 1)
		stabcname( cid );
E 2
I 2
	if (cbn == 1) {
D 4
	    stabcname( cid , line );
E 4
I 4
	    stabgconst( cid , line );
E 4
	}
E 2
#endif PC

#	ifdef PTREE
	    {
		pPointer	Const = ConstDecl( cid , cdecl );
		pPointer	*Consts;

		pSeize( PorFHeader[ nesting ] );
		Consts = &( pDEF( PorFHeader[ nesting ] ).PorFConsts );
		*Consts = ListAppend( *Consts , Const );
		pRelease( PorFHeader[ nesting ] );
	    }
#	endif
	if (con.ctype == NIL)
		return;
	if ( con.ctype == nl + TSTR )
D 6
		np->ptr[0] = con.cpval;
E 6
I 6
		np->ptr[0] = (struct nl *) con.cpval;
E 6
	if (isa(con.ctype, "i"))
		np->range[0] = con.crval;
	else if (isa(con.ctype, "d"))
		np->real = con.crval;
I 9
#       ifdef PC
	    if (cbn == 1 && con.ctype != NIL) {
		    stabconst(np);
	    }
#       endif
E 9
}

#ifndef PI0
#ifndef PI1
constend()
{

}
#endif
#endif

/*
 * Gconst extracts
 * a constant declaration
 * from the tree for it.
 * only types of constants
 * are integer, reals, strings
 * and scalars, the first two
 * being possibly signed.
 */
D 6
gconst(r)
	int *r;
E 6
I 6
gconst(c_node)
	struct tnode *c_node;
E 6
{
	register struct nl *np;
D 6
	register *cn;
E 6
I 6
	register struct tnode *cn;
E 6
	char *cp;
	int negd, sgnd;
	long ci;

	con.ctype = NIL;
D 6
	cn = r;
E 6
I 6
	cn = c_node;
E 6
	negd = sgnd = 0;
loop:
D 6
	if (cn == NIL || cn[1] == NIL)
		return (NIL);
	switch (cn[0]) {
E 6
I 6
	if (cn == TR_NIL || cn->sign_const.number == TR_NIL)
		return;
	switch (cn->tag) {
E 6
		default:
			panic("gconst");
		case T_MINUSC:
			negd = 1 - negd;
		case T_PLUSC:
			sgnd++;
D 6
			cn = cn[1];
E 6
I 6
			cn = cn->sign_const.number;
E 6
			goto loop;
		case T_ID:
D 6
			np = lookup(cn[1]);
			if (np == NIL)
E 6
I 6
			np = lookup(cn->char_const.cptr);
			if (np == NLNIL)
E 6
				return;
			if (np->class != CONST) {
D 6
				derror("%s is a %s, not a constant as required", cn[1], classes[np->class]);
E 6
I 6
				derror("%s is a %s, not a constant as required", cn->char_const.cptr, classes[np->class]);
E 6
				return;
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
D 6
					con.cpval = np->ptr[0];
E 6
I 6
					con.cpval = (char *) np->ptr[0];
E 6
					break;
				case NIL:
					con.ctype = NIL;
					return;
				default:
					panic("gconst2");
			}
			break;
		case T_CBINT:
D 6
			con.crval = a8tol(cn[1]);
E 6
I 6
			con.crval = a8tol(cn->char_const.cptr);
E 6
			goto restcon;
		case T_CINT:
D 6
			con.crval = atof(cn[1]);
E 6
I 6
			con.crval = atof(cn->char_const.cptr);
E 6
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
		case T_CFINT:
			con.ctype = nl+TDOUBLE;
D 6
			con.crval = atof(cn[1]);
E 6
I 6
			con.crval = atof(cn->char_const.cptr);
E 6
			break;
		case T_CSTRNG:
D 6
			cp = cn[1];
E 6
I 6
			cp = cn->char_const.cptr;
E 6
			if (cp[1] == 0) {
				con.ctype = nl+T1CHAR;
				con.cival = cp[0];
				con.crval = con.cival;
				break;
			}
			con.ctype = nl+TSTR;
			con.cpval = savestr(cp);
			break;
	}
	if (sgnd) {
D 6
		if (isnta(con.ctype, "id"))
			derror("%s constants cannot be signed", nameof(con.ctype));
E 6
I 6
		if (isnta((struct nl *) con.ctype, "id"))
			derror("%s constants cannot be signed",
				nameof((struct nl *) con.ctype));
E 6
		else {
			if (negd)
				con.crval = -con.crval;
			ci = con.crval;
		}
	}
}

#ifndef PI0
D 6
isconst(r)
	register int *r;
E 6
I 6
isconst(cn)
	register struct tnode *cn;
E 6
{

D 6
	if (r == NIL)
E 6
I 6
	if (cn == TR_NIL)
E 6
		return (1);
D 6
	switch (r[0]) {
E 6
I 6
	switch (cn->tag) {
E 6
		case T_MINUS:
D 6
			r[0] = T_MINUSC;
			r[1] = r[2];
			return (isconst(r[1]));
E 6
I 6
			cn->tag = T_MINUSC;
			cn->sign_const.number = 
					 cn->un_expr.expr;
			return (isconst(cn->sign_const.number));
E 6
		case T_PLUS:
D 6
			r[0] = T_PLUSC;
			r[1] = r[2];
			return (isconst(r[1]));
E 6
I 6
			cn->tag = T_PLUSC;
			cn->sign_const.number = 
					 cn->un_expr.expr;
			return (isconst(cn->sign_const.number));
E 6
		case T_VAR:
D 6
			if (r[3] != NIL)
E 6
I 6
			if (cn->var_node.qual != TR_NIL)
E 6
				return (0);
D 6
			r[0] = T_ID;
			r[1] = r[2];
E 6
I 6
			cn->tag = T_ID;
			cn->char_const.cptr = 
					cn->var_node.cptr;
E 6
			return (1);
		case T_BINT:
D 6
			r[0] = T_CBINT;
			r[1] = r[2];
E 6
I 6
			cn->tag = T_CBINT;
			cn->char_const.cptr = 
				cn->const_node.cptr;
E 6
			return (1);
		case T_INT:
D 6
			r[0] = T_CINT;
			r[1] = r[2];
E 6
I 6
			cn->tag = T_CINT;
			cn->char_const.cptr = 
				cn->const_node.cptr;
E 6
			return (1);
		case T_FINT:
D 6
			r[0] = T_CFINT;
			r[1] = r[2];
E 6
I 6
			cn->tag = T_CFINT;
			cn->char_const.cptr = 
				cn->const_node.cptr;
E 6
			return (1);
		case T_STRNG:
D 6
			r[0] = T_CSTRNG;
			r[1] = r[2];
E 6
I 6
			cn->tag = T_CSTRNG;
			cn->char_const.cptr = 
				cn->const_node.cptr;
E 6
			return (1);
	}
	return (0);
}
#endif
E 1
