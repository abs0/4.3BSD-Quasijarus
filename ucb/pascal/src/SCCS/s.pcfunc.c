h27860
s 00007/00003/00384
d D 5.1 85/06/05 14:40:16 dist 21 20
c Add copyright
e
s 00067/00067/00320
d D 2.2 85/03/20 15:03:20 ralph 20 19
c changes from donn@utah-cs for common header file for pcc
e
s 00000/00000/00387
d D 2.1 84/02/08 20:52:21 aoki 19 16
c synchronize to version 2
e
s 00000/00000/00387
d R 1.16 83/10/12 10:02:45 thien 18 17
c 
e
s 00000/00000/00387
d R 1.15 83/09/19 06:59:32 thien 17 16
c Restoring to unlinted version
e
s 00084/00078/00303
d D 1.14 83/08/19 04:59:35 thien 16 15
c The changes were made to allow successful linting
e
s 00001/00000/00380
d D 1.13 83/02/28 17:16:17 peter 15 14
c clean up temporary allocation, moving everything relevant to
c tmps.c and (new) tmps.h.  correctly emit LBRAC lines.  allocate registers
c from high to low.  put in data structures for multiple types of registers.
e
s 00014/00005/00366
d D 1.12 83/02/01 21:56:51 peter 14 13
c missing sconv's and calls to stkrval() instead of rvalue().
e
s 00000/00000/00371
d D 1.11 83/01/17 14:19:59 peter 13 10
i 12 11
c merge 1.10 and 1.9.1.
e
s 00003/00002/00371
d D 1.9.1.2 83/01/17 14:18:16 peter 12 11
c port to the mc68000.
e
s 00000/00000/00373
d D 1.9.1.1 83/01/17 14:17:10 peter 11 9
c branch-place-holder
e
s 00003/00006/00367
d D 1.10 83/01/17 14:04:26 peter 10 9
c put in explicit scalar converts (sconv's) to make less code-generator dependent.
e
s 00009/00002/00364
d D 1.9 82/12/06 18:28:42 peter 9 8
c ord() shouldn't be allowed on pointers.
e
s 00003/00002/00363
d D 1.8 82/04/27 15:44:26 mckusick 8 7
c be sure to get range values for SUCC and PRED
e
s 00004/00004/00361
d D 1.7 82/02/08 19:31:43 mckusic 7 6
c add runtime checking routines for sin, cos, atan, and exp
e
s 00009/00006/00356
d D 1.6 81/06/01 15:38:12 peter 6 5
c add storage classes to namelist, and use them.
e
s 00000/00003/00362
d D 1.5 81/03/26 17:29:56 peter 5 4
c fix allocation of temporaries for sqr().
e
s 00005/00007/00360
d D 1.4 81/03/11 23:37:46 mckusic 4 3
c centralize temporary allocation in tmps.c
e
s 00009/00020/00358
d D 1.3 80/10/19 18:32:54 peter 3 2
c guess that [] is intset if no other context information.
e
s 00001/00001/00377
d D 1.2 80/10/03 01:08:30 peter 2 1
c Implement formal functions and procedures
e
s 00378/00000/00000
d D 1.1 80/08/27 19:55:41 peter 1 0
c date and time created 80/08/27 19:55:41 by peter
e
u
U
f b 
t
T
I 1
D 21
/* Copyright (c) 1979 Regents of the University of California */
E 21
I 21
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 21

I 16
#ifndef lint
E 16
D 21
static	char sccsid[] = "%Z%%M% %I% %G%";
I 16
#endif
E 21
I 21
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 21
E 16

#include "whoami.h"
#ifdef PC
    /*
     *	and to the end of the file
     */
#include "0.h"
#include "tree.h"
I 12
#include "objfmt.h"
E 12
#include "opcode.h"
D 12
#include	"pc.h"
#include	"pcops.h"
E 12
I 12
#include "pc.h"
D 20
#include "pcops.h"
E 20
I 20
#include <pcc.h>
E 20
I 15
#include "tmps.h"
I 16
#include "tree_ty.h"
E 16
E 15
E 12

D 3
bool cardempty = FALSE;

E 3
/*
 * Funccod generates code for
 * built in function calls and calls
 * call to generate calls to user
 * defined functions and procedures.
 */
I 16
struct nl *
E 16
pcfunccod( r )
D 16
	int	 *r;
E 16
I 16
	struct tnode	 *r; /* T_FCALL */
E 16
{
	struct nl *p;
	register struct nl *p1;
D 16
	register int *al;
E 16
I 16
	register struct tnode *al;
E 16
	register op;
D 16
	int argc, *argv;
	int tr[2], tr2[4];
E 16
I 16
	int argc;
	struct tnode *argv;
	struct tnode tr, tr2;
E 16
	char		*funcname;
D 6
	long		tempoff;
E 6
I 6
	struct nl	*tempnlp;
E 6
	long		temptype;
	struct nl	*rettype;
I 4
D 5
	struct tmps soffset;
E 5
E 4

	/*
	 * Verify that the given name
	 * is defined and the name of
	 * a function.
	 */
D 16
	p = lookup(r[2]);
	if (p == NIL) {
		rvlist(r[3]);
		return (NIL);
E 16
I 16
	p = lookup(r->pcall_node.proc_id);
	if (p == NLNIL) {
		rvlist(r->pcall_node.arg);
		return (NLNIL);
E 16
	}
D 2
	if (p->class != FUNC) {
E 2
I 2
	if (p->class != FUNC && p->class != FFUNC) {
E 2
		error("%s is not a function", p->symbol);
D 16
		rvlist(r[3]);
		return (NIL);
E 16
I 16
		rvlist(r->pcall_node.arg);
		return (NLNIL);
E 16
	}
D 16
	argv = r[3];
E 16
I 16
	argv = r->pcall_node.arg;
E 16
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
D 16
	for (al = argv; al != NIL; al = al[2])
E 16
I 16
	for (al = argv; al != TR_NIL; al = al->list_node.next)
E 16
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
	if ( op == O_ARGC ) {
D 20
	    putleaf( P2NAME , 0 , 0 , P2INT , "__argc" );
E 20
I 20
	    putleaf( PCC_NAME , 0 , 0 , PCCT_INT , "__argc" );
E 20
	    return nl + T4INT;
	}
	switch (op) {
		/*
		 * Parameterless functions
		 */
		case O_CLCK:
			funcname = "_CLCK";
			goto noargs;
		case O_SCLCK:
			funcname = "_SCLCK";
			goto noargs;
noargs:
			if (argc != 0) {
				error("%s takes no arguments", p->symbol);
				rvlist(argv);
D 16
				return (NIL);
E 16
I 16
				return (NLNIL);
E 16
			}
D 20
			putleaf( P2ICON , 0 , 0
				, ADDTYPE( P2FTN | P2INT , P2PTR )
E 20
I 20
			putleaf( PCC_ICON , 0 , 0
				, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 20
				, funcname );
D 20
			putop( P2UNARY P2CALL , P2INT );
E 20
I 20
			putop( PCCOM_UNARY PCC_CALL , PCCT_INT );
E 20
			return (nl+T4INT);
		case O_WCLCK:
			if (argc != 0) {
				error("%s takes no arguments", p->symbol);
				rvlist(argv);
D 16
				return (NIL);
E 16
I 16
				return (NLNIL);
E 16
			}
D 20
			putleaf( P2ICON , 0 , 0
				, ADDTYPE( P2FTN | P2INT , P2PTR )
E 20
I 20
			putleaf( PCC_ICON , 0 , 0
				, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 20
				, "_time" );
D 16
			putleaf( P2ICON , 0 , 0 , P2INT , 0 );
E 16
I 16
D 20
			putleaf( P2ICON , 0 , 0 , P2INT , (char *) 0 );
E 16
			putop( P2CALL , P2INT );
E 20
I 20
			putleaf( PCC_ICON , 0 , 0 , PCCT_INT , (char *) 0 );
			putop( PCC_CALL , PCCT_INT );
E 20
			return (nl+T4INT);
		case O_EOF:
		case O_EOLN:
			if (argc == 0) {
D 16
				argv = tr;
				tr[1] = tr2;
				tr2[0] = T_VAR;
				tr2[2] = input->symbol;
				tr2[1] = tr2[3] = NIL;
E 16
I 16
				argv = &(tr);
				tr.list_node.list = &(tr2);
				tr2.tag = T_VAR;
				tr2.var_node.cptr = input->symbol;
				tr2.var_node.line_no = NIL;
				tr2.var_node.qual = TR_NIL;
E 16
				argc = 1;
			} else if (argc != 1) {
				error("%s takes either zero or one argument", p->symbol);
				rvlist(argv);
D 16
				return (NIL);
E 16
I 16
				return (NLNIL);
E 16
			}
		}
	/*
	 * All other functions take
	 * exactly one argument.
	 */
	if (argc != 1) {
		error("%s takes exactly one argument", p->symbol);
		rvlist(argv);
D 16
		return (NIL);
E 16
I 16
		return (NLNIL);
E 16
	}
	/*
	 * find out the type of the argument
	 */
	codeoff();
D 16
	p1 = stkrval((int *) argv[1], NLNIL , RREQ );
E 16
I 16
	p1 = stkrval( argv->list_node.list, NLNIL , (long) RREQ );
E 16
	codeon();
D 16
	if (p1 == NIL)
		return (NIL);
E 16
I 16
	if (p1 == NLNIL)
		return (NLNIL);
E 16
	/*
	 * figure out the return type and the funtion name
	 */
	switch (op) {
I 16
	    case 0:
			error("%s is an unimplemented 6000-3.4 extension", p->symbol);
	    default:
			panic("func1");
E 16
	    case O_EXP:
D 7
		    funcname = "_exp";
E 7
I 7
		    funcname = opt('t') ? "_EXP" : "_exp";
E 7
		    goto mathfunc;
	    case O_SIN:
D 7
		    funcname = "_sin";
E 7
I 7
		    funcname = opt('t') ? "_SIN" : "_sin";
E 7
		    goto mathfunc;
	    case O_COS:
D 7
		    funcname = "_cos";
E 7
I 7
		    funcname = opt('t') ? "_COS" : "_cos";
E 7
		    goto mathfunc;
	    case O_ATAN:
D 7
		    funcname = "_atan";
E 7
I 7
		    funcname = opt('t') ? "_ATAN" : "_atan";
E 7
		    goto mathfunc;
	    case O_LN:
		    funcname = opt('t') ? "_LN" : "_log";
		    goto mathfunc;
	    case O_SQRT:
		    funcname = opt('t') ? "_SQRT" : "_sqrt";
		    goto mathfunc;
	    case O_RANDOM:
		    funcname = "_RANDOM";
		    goto mathfunc;
mathfunc:
		    if (isnta(p1, "id")) {
			    error("%s's argument must be integer or real, not %s", p->symbol, nameof(p1));
D 16
			    return (NIL);
E 16
I 16
			    return (NLNIL);
E 16
		    }
D 20
		    putleaf( P2ICON , 0 , 0
			    , ADDTYPE( P2FTN | P2DOUBLE , P2PTR ) , funcname );
E 20
I 20
		    putleaf( PCC_ICON , 0 , 0
			    , PCCM_ADDTYPE( PCCTM_FTN | PCCT_DOUBLE , PCCTM_PTR ) , funcname );
E 20
D 16
		    p1 = stkrval( (int *) argv[1] , NLNIL , RREQ );
E 16
I 16
		    p1 = stkrval(  argv->list_node.list , NLNIL , (long) RREQ );
E 16
D 10
		    if ( isa( p1 , "i" ) ) {
			putop( P2SCONV , P2DOUBLE );
		    }
E 10
I 10
D 20
		    sconv(p2type(p1), P2DOUBLE);
E 10
		    putop( P2CALL , P2DOUBLE );
E 20
I 20
		    sconv(p2type(p1), PCCT_DOUBLE);
		    putop( PCC_CALL , PCCT_DOUBLE );
E 20
		    return nl + TDOUBLE;
	    case O_EXPO:
		    if (isnta( p1 , "id" ) ) {
			    error("%s's argument must be integer or real, not %s", p->symbol, nameof(p1));
			    return NIL;
		    }
D 20
		    putleaf( P2ICON , 0 , 0
			    , ADDTYPE( P2FTN | P2INT , P2PTR ) , "_EXPO" );
E 20
I 20
		    putleaf( PCC_ICON , 0 , 0
			    , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR ) , "_EXPO" );
E 20
D 16
		    p1 = stkrval( (int *) argv[1] , NLNIL , RREQ );
E 16
I 16
		    p1 = stkrval( argv->list_node.list , NLNIL , (long) RREQ );
E 16
D 10
		    if ( isa( p1 , "i" ) ) {
			putop( P2SCONV , P2DOUBLE );
		    }
E 10
I 10
D 20
		    sconv(p2type(p1), P2DOUBLE);
E 10
		    putop( P2CALL , P2INT );
E 20
I 20
		    sconv(p2type(p1), PCCT_DOUBLE);
		    putop( PCC_CALL , PCCT_INT );
E 20
		    return ( nl + T4INT );
	    case O_UNDEF:
		    if ( isnta( p1 , "id" ) ) {
			    error("%s's argument must be integer or real, not %s", p->symbol, nameof(p1));
D 16
			    return NIL;
E 16
I 16
			    return NLNIL;
E 16
		    }
D 16
		    p1 = stkrval( (int *) argv[1] , NLNIL , RREQ );
D 14
		    putleaf( P2ICON , 0 , 0 , P2INT , 0 );
		    putop( P2COMOP , P2INT );
E 14
I 14
		    putleaf( P2ICON , 0 , 0 , P2CHAR , 0 );
E 16
I 16
		    p1 = stkrval( argv->list_node.list , NLNIL , (long) RREQ );
D 20
		    putleaf( P2ICON , 0 , 0 , P2CHAR , (char *) 0 );
E 16
		    putop( P2COMOP , P2CHAR );
E 20
I 20
		    putleaf( PCC_ICON , 0 , 0 , PCCT_CHAR , (char *) 0 );
		    putop( PCC_COMOP , PCCT_CHAR );
E 20
E 14
		    return ( nl + TBOOL );
	    case O_SEED:
		    if (isnta(p1, "i")) {
			    error("seed's argument must be an integer, not %s", nameof(p1));
D 16
			    return (NIL);
E 16
I 16
			    return (NLNIL);
E 16
		    }
D 20
		    putleaf( P2ICON , 0 , 0
			    , ADDTYPE( P2FTN | P2INT , P2PTR ) , "_SEED" );
E 20
I 20
		    putleaf( PCC_ICON , 0 , 0
			    , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR ) , "_SEED" );
E 20
D 16
		    p1 = stkrval( (int *) argv[1] , NLNIL , RREQ );
E 16
I 16
		    p1 = stkrval( argv->list_node.list , NLNIL , (long) RREQ );
E 16
D 20
		    putop( P2CALL , P2INT );
E 20
I 20
		    putop( PCC_CALL , PCCT_INT );
E 20
		    return nl + T4INT;
	    case O_ROUND:
	    case O_TRUNC:
		    if ( isnta( p1 , "d" ) ) {
			    error("%s's argument must be a real, not %s", p->symbol, nameof(p1));
D 16
			    return (NIL);
E 16
I 16
			    return (NLNIL);
E 16
		    }
D 20
		    putleaf( P2ICON , 0 , 0
			    , ADDTYPE( P2FTN | P2INT , P2PTR )
E 20
I 20
		    putleaf( PCC_ICON , 0 , 0
			    , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 20
			    , op == O_ROUND ? "_ROUND" : "_TRUNC" );
D 16
		    p1 = stkrval( (int *) argv[1] , NLNIL , RREQ );
E 16
I 16
		    p1 = stkrval( argv->list_node.list , NLNIL , (long) RREQ );
E 16
D 20
		    putop( P2CALL , P2INT );
E 20
I 20
		    putop( PCC_CALL , PCCT_INT );
E 20
		    return nl + T4INT;
	    case O_ABS2:
			if ( isa( p1 , "d" ) ) {
D 20
			    putleaf( P2ICON , 0 , 0
				, ADDTYPE( P2FTN | P2DOUBLE , P2PTR )
E 20
I 20
			    putleaf( PCC_ICON , 0 , 0
				, PCCM_ADDTYPE( PCCTM_FTN | PCCT_DOUBLE , PCCTM_PTR )
E 20
				, "_fabs" );
D 16
			    p1 = stkrval( (int *) argv[1] , NLNIL , RREQ );
E 16
I 16
			    p1 = stkrval( argv->list_node.list , NLNIL ,(long) RREQ );
E 16
D 20
			    putop( P2CALL , P2DOUBLE );
E 20
I 20
			    putop( PCC_CALL , PCCT_DOUBLE );
E 20
			    return nl + TDOUBLE;
			}
			if ( isa( p1 , "i" ) ) {
D 20
			    putleaf( P2ICON , 0 , 0
				, ADDTYPE( P2FTN | P2INT , P2PTR ) , "_abs" );
E 20
I 20
			    putleaf( PCC_ICON , 0 , 0
				, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR ) , "_abs" );
E 20
D 16
			    p1 = stkrval( (int *) argv[1] , NLNIL , RREQ );
E 16
I 16
			    p1 = stkrval( argv->list_node.list , NLNIL , (long) RREQ );
E 16
D 20
			    putop( P2CALL , P2INT );
E 20
I 20
			    putop( PCC_CALL , PCCT_INT );
E 20
			    return nl + T4INT;
			}
			error("%s's argument must be an integer or real, not %s", p->symbol, nameof(p1));
D 16
			return NIL;
E 16
I 16
			return NLNIL;
E 16
	    case O_SQR2:
I 4
D 5
			soffset = sizes[cbn].curtmps;
E 5
E 4
			if ( isa( p1 , "d" ) ) {
D 20
			    temptype = P2DOUBLE;
E 20
I 20
			    temptype = PCCT_DOUBLE;
E 20
			    rettype = nl + TDOUBLE;
D 4
			    sizes[ cbn ].om_off -= sizeof( double );
E 4
I 4
D 6
			    tempoff = tmpalloc(sizeof(double), rettype, REGOK);
E 6
I 6
D 16
			    tempnlp = tmpalloc(sizeof(double), rettype, REGOK);
E 16
I 16
			    tempnlp = tmpalloc((long) (sizeof(double)), rettype, REGOK);
E 16
E 6
E 4
			} else if ( isa( p1 , "i" ) ) {
D 20
			    temptype = P2INT;
E 20
I 20
			    temptype = PCCT_INT;
E 20
			    rettype = nl + T4INT;
D 4
			    sizes[ cbn ].om_off -= sizeof( long );
E 4
I 4
D 6
			    tempoff = tmpalloc(sizeof(long), rettype, REGOK);
E 6
I 6
D 16
			    tempnlp = tmpalloc(sizeof(long), rettype, REGOK);
E 16
I 16
			    tempnlp = tmpalloc((long) (sizeof(long)), rettype, REGOK);
E 16
E 6
E 4
			} else {
			    error("%s's argument must be an integer or real, not %s", p->symbol, nameof(p1));
D 16
			    return NIL;
E 16
I 16
			    return NLNIL;
E 16
			}
D 4
			tempoff = sizes[ cbn ].om_off;
			if ( tempoff < sizes[ cbn ].om_max ) {
			    sizes[ cbn ].om_max = tempoff;
			}
			putlbracket( ftnno , -tempoff );
E 4
D 6
			putRV( 0 , cbn , tempoff , temptype , 0 );
E 6
I 6
D 16
			putRV( 0 , cbn , tempnlp -> value[ NL_OFFS ] ,
				tempnlp -> extra_flags , temptype , 0 );
E 6
			p1 = rvalue( (int *) argv[1] , NLNIL , RREQ );
I 10
			sconv(p2type(p1), temptype);
E 10
			putop( P2ASSIGN , temptype );
D 6
			putRV( 0 , cbn , tempoff , temptype , 0 );
			putRV( 0 , cbn , tempoff , temptype , 0 );
E 6
I 6
			putRV( 0 , cbn , tempnlp -> value[ NL_OFFS ] ,
				tempnlp -> extra_flags , temptype , 0 );
			putRV( 0 , cbn , tempnlp -> value[ NL_OFFS ] ,
				tempnlp -> extra_flags , temptype , 0 );
E 6
			putop( P2MUL , temptype );
			putop( P2COMOP , temptype );
E 16
I 16
			putRV( (char *) 0 , cbn , tempnlp -> value[ NL_OFFS ] ,
				tempnlp -> extra_flags , (char) temptype  );
			p1 = rvalue( argv->list_node.list , NLNIL , RREQ );
			sconv(p2type(p1), (int) temptype);
D 20
			putop( P2ASSIGN , (int) temptype );
E 20
I 20
			putop( PCC_ASSIGN , (int) temptype );
E 20
			putRV((char *) 0 , cbn , tempnlp -> value[ NL_OFFS ] ,
				tempnlp -> extra_flags , (char) temptype );
			putRV((char *) 0 , cbn , tempnlp -> value[ NL_OFFS ] ,
				tempnlp -> extra_flags , (char) temptype );
D 20
			putop( P2MUL , (int) temptype );
			putop( P2COMOP , (int) temptype );
E 20
I 20
			putop( PCC_MUL , (int) temptype );
			putop( PCC_COMOP , (int) temptype );
E 20
E 16
I 4
D 5
			tmpfree(&soffset);
E 5
E 4
			return rettype;
	    case O_ORD2:
D 16
			p1 = stkrval( (int *) argv[1] , NLNIL , RREQ );
E 16
I 16
			p1 = stkrval( argv->list_node.list , NLNIL , (long) RREQ );
E 16
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
D 16
			return (NIL);
E 16
I 16
			return (NLNIL);
E 16
	    case O_SUCC2:
	    case O_PRED2:
			if (isa(p1, "d")) {
				error("%s is forbidden for reals", p->symbol);
D 16
				return (NIL);
E 16
I 16
				return (NLNIL);
E 16
			}
			if ( isnta( p1 , "bcsi" ) ) {
			    error("%s's argument must be of scalar type, not %s", p->symbol, nameof(p1));
D 16
			    return NIL;
E 16
I 16
			    return NLNIL;
E 16
			}
			if ( opt( 't' ) ) {
D 20
			    putleaf( P2ICON , 0 , 0
				    , ADDTYPE( P2FTN | P2INT , P2PTR )
E 20
I 20
			    putleaf( PCC_ICON , 0 , 0
				    , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 20
				    , op == O_SUCC2 ? "_SUCC" : "_PRED" );
D 16
			    p1 = stkrval( (int *) argv[1] , NLNIL , RREQ );
E 16
I 16
			    p1 = stkrval( argv->list_node.list , NLNIL , (long) RREQ );
E 16
D 8
			    putleaf( P2ICON , p1 -> range[0] , 0 , P2INT , 0 );
E 8
I 8
			    tempnlp = p1 -> class == TYPE ? p1 -> type : p1;
D 16
			    putleaf( P2ICON, tempnlp -> range[0], 0, P2INT, 0 );
E 16
I 16
D 20
			    putleaf( P2ICON, (int) tempnlp -> range[0], 0, P2INT, (char *) 0 );
E 16
E 8
			    putop( P2LISTOP , P2INT );
D 8
			    putleaf( P2ICON , p1 -> range[1] , 0 , P2INT , 0 );
E 8
I 8
D 16
			    putleaf( P2ICON, tempnlp -> range[1], 0, P2INT, 0 );
E 16
I 16
			    putleaf( P2ICON, (int) tempnlp -> range[1], 0, P2INT, (char *) 0 );
E 16
E 8
			    putop( P2LISTOP , P2INT );
			    putop( P2CALL , P2INT );
I 14
			    sconv(P2INT, p2type(p1));
E 20
I 20
			    putleaf( PCC_ICON, (int) tempnlp -> range[0], 0, PCCT_INT, (char *) 0 );
			    putop( PCC_CM , PCCT_INT );
			    putleaf( PCC_ICON, (int) tempnlp -> range[1], 0, PCCT_INT, (char *) 0 );
			    putop( PCC_CM , PCCT_INT );
			    putop( PCC_CALL , PCCT_INT );
			    sconv(PCCT_INT, p2type(p1));
E 20
E 14
			} else {
D 14
			    p1 = rvalue( argv[1] , NIL , RREQ );
E 14
I 14
D 16
			    p1 = stkrval( (int *) argv[1] , NLNIL , RREQ );
E 14
			    putleaf( P2ICON , 1 , 0 , P2INT , 0 );
E 16
I 16
			    p1 = stkrval( argv->list_node.list , NLNIL , (long) RREQ );
D 20
			    putleaf( P2ICON , 1 , 0 , P2INT , (char *) 0 );
E 16
			    putop( op == O_SUCC2 ? P2PLUS : P2MINUS , P2INT );
I 14
			    sconv(P2INT, p2type(p1));
E 20
I 20
			    putleaf( PCC_ICON , 1 , 0 , PCCT_INT , (char *) 0 );
			    putop( op == O_SUCC2 ? PCC_PLUS : PCC_MINUS , PCCT_INT );
			    sconv(PCCT_INT, p2type(p1));
E 20
E 14
			}
			if ( isa( p1 , "bcs" ) ) {
			    return p1;
			} else {
			    return nl + T4INT;
			}
	    case O_ODD2:
			if (isnta(p1, "i")) {
				error("odd's argument must be an integer, not %s", nameof(p1));
D 16
				return (NIL);
E 16
I 16
				return (NLNIL);
E 16
			}
D 14
			p1 = rvalue( (int *) argv[1] , NLNIL , RREQ );
E 14
I 14
D 16
			p1 = stkrval( (int *) argv[1] , NLNIL , RREQ );
E 16
I 16
			p1 = stkrval( argv->list_node.list , NLNIL , (long) RREQ );
E 16
			    /*
			     *	THIS IS MACHINE-DEPENDENT!!!
			     */
E 14
D 16
			putleaf( P2ICON , 1 , 0 , P2INT , 0 );
E 16
I 16
D 20
			putleaf( P2ICON , 1 , 0 , P2INT , (char *) 0 );
E 16
			putop( P2AND , P2INT );
I 14
			sconv(P2INT, P2CHAR);
E 20
I 20
			putleaf( PCC_ICON , 1 , 0 , PCCT_INT , (char *) 0 );
			putop( PCC_AND , PCCT_INT );
			sconv(PCCT_INT, PCCT_CHAR);
E 20
E 14
			return nl + TBOOL;
	    case O_CHR2:
			if (isnta(p1, "i")) {
				error("chr's argument must be an integer, not %s", nameof(p1));
D 16
				return (NIL);
E 16
I 16
				return (NLNIL);
E 16
			}
			if (opt('t')) {
D 20
			    putleaf( P2ICON , 0 , 0
				, ADDTYPE( P2FTN | P2CHAR , P2PTR ) , "_CHR" );
E 20
I 20
			    putleaf( PCC_ICON , 0 , 0
				, PCCM_ADDTYPE( PCCTM_FTN | PCCT_CHAR , PCCTM_PTR ) , "_CHR" );
E 20
D 16
			    p1 = stkrval( (int *) argv[1] , NLNIL , RREQ );
E 16
I 16
			    p1 = stkrval( argv->list_node.list , NLNIL , (long) RREQ );
E 16
D 20
			    putop( P2CALL , P2CHAR );
E 20
I 20
			    putop( PCC_CALL , PCCT_CHAR );
E 20
			} else {
D 16
			    p1 = stkrval( (int *) argv[1] , NLNIL , RREQ );
E 16
I 16
			    p1 = stkrval( argv->list_node.list , NLNIL , (long) RREQ );
E 16
I 14
D 20
			    sconv(P2INT, P2CHAR);
E 20
I 20
			    sconv(PCCT_INT, PCCT_CHAR);
E 20
E 14
			}
			return nl + TCHAR;
	    case O_CARD:
D 3
			if ( p1 != nl + TSET ) {
			    if (isnta(p1, "t")) {
				error("Argument to card must be a set, not %s", nameof(p1));
				return (NIL);
			    }
			    putleaf( P2ICON , 0 , 0
				, ADDTYPE( P2FTN | P2INT , P2PTR ) , "_CARD" );
			    p1 = stkrval( (int *) argv[1] , NLNIL , LREQ );
			    putleaf( P2ICON , lwidth( p1 ) , 0 , P2INT , 0 );
			    putop( P2LISTOP , P2INT );
			    putop( P2CALL , P2INT );
			} else {
			    if ( !cardempty ) {
				warning();
				error("Cardinality of the empty set is 0." );
				cardempty = TRUE;
			    }
			    putleaf( P2ICON , 0 , 0 , P2INT , 0 );
E 3
I 3
			if (isnta(p1, "t")) {
			    error("Argument to card must be a set, not %s", nameof(p1));
D 16
			    return (NIL);
E 16
I 16
			    return (NLNIL);
E 16
E 3
			}
I 3
D 20
			putleaf( P2ICON , 0 , 0
			    , ADDTYPE( P2FTN | P2INT , P2PTR ) , "_CARD" );
E 20
I 20
			putleaf( PCC_ICON , 0 , 0
			    , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR ) , "_CARD" );
E 20
D 16
			p1 = stkrval( (int *) argv[1] , NLNIL , LREQ );
			putleaf( P2ICON , lwidth( p1 ) , 0 , P2INT , 0 );
E 16
I 16
			p1 = stkrval( argv->list_node.list , NLNIL , (long) LREQ );
D 20
			putleaf( P2ICON , (int) lwidth( p1 ) , 0 , P2INT , (char *) 0 );
E 16
			putop( P2LISTOP , P2INT );
			putop( P2CALL , P2INT );
E 20
I 20
			putleaf( PCC_ICON , (int) lwidth( p1 ) , 0 , PCCT_INT , (char *) 0 );
			putop( PCC_CM , PCCT_INT );
			putop( PCC_CALL , PCCT_INT );
E 20
E 3
D 14
			return nl + T2INT;
E 14
I 14
			return nl + T4INT;
E 14
	    case O_EOLN:
			if (!text(p1)) {
				error("Argument to eoln must be a text file, not %s", nameof(p1));
D 16
				return (NIL);
E 16
I 16
				return (NLNIL);
E 16
			}
D 20
			putleaf( P2ICON , 0 , 0
			    , ADDTYPE( P2FTN | P2INT , P2PTR ) , "_TEOLN" );
E 20
I 20
			putleaf( PCC_ICON , 0 , 0
			    , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR ) , "_TEOLN" );
E 20
D 16
			p1 = stklval( (int *) argv[1] , NOFLAGS );
E 16
I 16
			p1 = stklval( argv->list_node.list , NOFLAGS );
E 16
D 20
			putop( P2CALL , P2INT );
I 14
			sconv(P2INT, P2CHAR);
E 20
I 20
			putop( PCC_CALL , PCCT_INT );
			sconv(PCCT_INT, PCCT_CHAR);
E 20
E 14
			return nl + TBOOL;
	    case O_EOF:
			if (p1->class != FILET) {
				error("Argument to eof must be file, not %s", nameof(p1));
D 16
				return (NIL);
E 16
I 16
				return (NLNIL);
E 16
			}
D 20
			putleaf( P2ICON , 0 , 0
			    , ADDTYPE( P2FTN | P2INT , P2PTR ) , "_TEOF" );
E 20
I 20
			putleaf( PCC_ICON , 0 , 0
			    , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR ) , "_TEOF" );
E 20
D 16
			p1 = stklval( (int *) argv[1] , NOFLAGS );
E 16
I 16
			p1 = stklval( argv->list_node.list , NOFLAGS );
E 16
D 20
			putop( P2CALL , P2INT );
I 14
			sconv(P2INT, P2CHAR);
E 20
I 20
			putop( PCC_CALL , PCCT_INT );
			sconv(PCCT_INT, PCCT_CHAR);
E 20
E 14
			return nl + TBOOL;
D 16
	    case 0:
			error("%s is an unimplemented 6000-3.4 extension", p->symbol);
	    default:
			panic("func1");
E 16
	}
}
#endif PC
E 1
