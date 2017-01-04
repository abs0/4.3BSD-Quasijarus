h54019
s 00008/00004/00432
d D 5.1 85/06/05 14:16:18 dist 24 23
c Add copyright
e
s 00033/00033/00403
d D 2.2 85/03/20 15:01:32 ralph 23 22
c changes from donn@utah-cs for common header file for pcc
e
s 00000/00000/00436
d D 2.1 84/02/08 20:52:38 aoki 22 21
c synchronize to version 2
e
s 00001/00001/00435
d D 1.19 83/10/11 06:41:20 thien 21 19
c fixes for lint
e
s 00000/00000/00436
d R 1.19 83/10/11 06:40:04 thien 20 19
c 
e
s 00000/00000/00436
d D 1.18 83/09/19 06:48:12 thien 19 18
c 
e
s 00103/00094/00333
d D 1.17 83/08/19 04:57:28 thien 18 17
c The changes were made to allow successful linting
e
s 00001/00000/00426
d D 1.16 83/02/28 17:19:17 peter 17 16
c clean up temporary allocation, moving everything relevant to
c tmps.c and (new) tmps.h.  correctly emit LBRAC lines.  allocate registers
c from high to low.  put in data structures for multiple types of registers.
e
s 00002/00002/00424
d D 1.15 83/02/09 21:46:59 mckusick 16 15
c do not copy the old block number to the shadow var, just the flags
e
s 00161/00100/00265
d D 1.14 83/02/09 14:14:02 peter 15 14
c conform to the standard with respect to types of expressions.
c change the FOR opcode generated for px,
c since rangechecking is now hoisted out of the loop.
e
s 00054/00040/00311
d D 1.13 83/02/01 21:46:59 peter 14 13
c the shadow of the index variable must be the same type as the
c index variable (for high-end addressed machines, like the 68000).
e
s 00005/00002/00346
d D 1.12 83/01/17 13:57:23 mckusick 13 12
c put in explicit scalar converts (sconv's) to make less code-generator dependent.
e
s 00003/00000/00345
d D 1.11 82/02/16 19:12:54 mckusic 12 11
c retain MOD and USE flags; inherit index type to temporary
e
s 00006/00026/00339
d D 1.10 82/02/13 13:28:37 mckusic 11 10
c must update "class" field of shadow variables
e
s 00059/00031/00306
d D 1.9 81/06/01 15:40:19 peter 10 9
c add storage classes to namelist, and use them.
e
s 00002/00002/00335
d D 1.8 81/04/28 17:42:49 mckusic 9 8
c increment at bottom of loop is done in base type (integer).
e
s 00043/00038/00294
d D 1.7 81/04/21 15:06:40 peter 8 7
c clean up for loop code
e
s 00027/00008/00305
d D 1.6 81/03/26 17:28:02 peter 7 5
c fix up for variables in temporaries.
e
s 00033/00017/00296
d R 1.6 81/03/25 18:39:08 peter 6 5
c fix some bugs in temporary replacement of for loop indicies
e
s 00045/00022/00268
d D 1.5 81/03/16 18:12:52 mckusic 5 4
c add temporary register allocation
e
s 00002/00017/00288
d D 1.4 81/03/11 23:45:31 mckusic 4 3
c centralize temporary allocation in tmps.c
e
s 00011/00006/00294
d D 1.3 81/03/08 19:29:23 mckusic 3 2
c merge in onyx changes
e
s 00001/00000/00299
d D 1.2 81/02/24 15:42:54 peter 2 1
c count statements at top of for loops
e
s 00299/00000/00000
d D 1.1 81/01/16 18:06:20 mckusick 1 0
c date and time created 81/01/16 18:06:20 by mckusick
e
u
U
t
T
I 24
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 24
I 18

E 18
I 1
D 24
/* Copyright (c) 1979 Regents of the University of California */

E 24
D 3
static	char sccsid[] = "%Z%%M% %I% %G%";
E 3
I 3
D 18
static char sccsid[] = "%Z%%M% %I% %G%";
E 18
I 18
#ifndef lint
D 21
static char sccsid[] = "@(#)forop.c 1.16 2/28/83";
E 21
I 21
D 24
static char sccsid[] = "%W%	(Berkeley)	%E%";
E 21
#endif
E 24
I 24
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 24
E 18
E 3

#include	"whoami.h"
#include	"0.h"
#include	"opcode.h"
#include	"tree.h"
#include	"objfmt.h"
#ifdef PC
#    include	"pc.h"
D 23
#    include	"pcops.h"
E 23
I 23
#    include	<pcc.h>
E 23
#endif PC
I 17
#include	"tmps.h"
I 18
#include	"tree_ty.h"
E 18
E 17
I 7

E 7
    /*
D 15
     *	forop for pc:
     *	    this evaluates the initial and termination expressions,
     *	    checks them to see if the loop executes at all, and then
     *	    does the assignment and the loop.
E 15
I 15
     *	for-statements.
     *
     *	the relevant quote from the standard:  6.8.3.9:
     *	``The control-variable shall be an entire-variable whose identifier
     *	is declared in the variable-declaration-part of the block closest-
     *	containing the for-statement.  The control-variable shall possess
     *	an ordinal-type, and the initial-value and the final-value shall be
     *	of a type compatible with this type.  The statement of a for-statement
     *	shall not contain an assigning-reference to the control-variable
     *	of the for-statement.  The value of the final-value shall be 
     *	assignment-compatible with the control-variable when the initial-value
     *	is assigned to the control-variable.  After a for-statement is
     *	executed (other than being left by a goto-statement leading out of it)
     *	the control-variable shall be undefined.  Apart from the restrictions
     *	imposed by these requirements, the for-statement
     *		for v := e1 to e2 do body
     *	shall be equivalent to
     *		begin
     *		    temp1 := e1;
     *		    temp2 := e2;
     *		    if temp1 <= temp2 then begin
     *			v := temp1;
     *			body;
     *			while v <> temp2 do begin
     *			    v := succ(v);
     *			    body;
     *			end
     *		    end
     *		end
     *	where temp1 and temp2 denote auxiliary variables that the program
     *	does not otherwise contain, and that possess the type possessed by
     *	the variable v if that type is not a subrange-type;  otherwise the
     *	host type possessed by the variable v.''
     *
     *	The Berkeley Pascal systems try to do all that without duplicating
     *	the body, and shadowing the control-variable in (possibly) a
     *	register variable.
     *
E 15
     *	arg here looks like:
     *	arg[0]	T_FORU or T_FORD
     *	   [1]	lineof "for"
     *	   [2]	[0]	T_ASGN
     *		[1]	lineof ":="
     *		[2]	[0]	T_VAR
     *			[1]	lineof id
     *			[2]	char * to id
     *			[3]	qualifications
     *		[3]	initial expression
     *	  [3]	termination expression
     *	  [4]	statement
     */
D 18
forop( arg )
    int	*arg;
E 18
I 18
forop( tree_node)
    struct tnode	*tree_node;
E 18
    {
D 18
	int		*lhs;
E 18
I 18
	struct tnode	*lhs;
	VAR_NODE	*lhs_node;
	FOR_NODE	*f_node;
E 18
	struct nl	*forvar;
	struct nl	*fortype;
I 14
#ifdef PC
D 15
	int		forctype;	/* p2type(fortype) */
E 15
I 15
	int		forp2type;
E 15
#endif PC
	int		forwidth;
E 14
D 10
	int		forctype;
E 10
D 18
	int		*init;
E 18
I 18
	struct tnode	*init_node;
E 18
	struct nl	*inittype;
D 10
	int		initoff;
E 10
I 10
	struct nl	*initnlp;	/* initial value namelist entry */
E 10
I 7
D 15
	char		forflags;
E 15
E 7
D 18
	int		*term;
E 18
I 18
	struct tnode	*term_node;
E 18
	struct nl	*termtype;
D 10
	int		termoff;
E 10
I 10
	struct nl	*termnlp;	/* termination value namelist entry */
I 15
	struct nl	*shadownlp;	/* namelist entry for the shadow */
E 15
E 10
D 18
	int		*stat;
E 18
I 18
	struct tnode	*stat_node;
E 18
	int		goc;		/* saved gocnt */
	int		again;		/* label at the top of the loop */
	int		after;		/* label after the end of the loop */
I 8
D 11
	bool		shadowed;	/* shadowing for var in temporary? */
	long		s_offset;	/* saved offset of real for variable */
	long		s_flags;	/* saved flags of real for variable */
	long		s_forv;		/* saved NL_FORV of the for variable */
I 10
#	ifdef PC
	    char	s_extra_flags;	/* saved extra_flags of the for var */
#	endif PC
E 11
I 11
D 15
	struct nl	shadow_nl;	/* saved namelist entry for loop var */
E 15
I 15
	struct nl	saved_nl;	/* saved namelist entry for loop var */
E 15
E 11
E 10
E 8

	goc = gocnt;
D 18
	forvar = NIL;
I 8
D 11
	shadowed = FALSE;
E 11
E 8
	if ( arg == NIL ) {
E 18
I 18
	forvar = NLNIL;
	if ( tree_node == TR_NIL ) { 
E 18
	    goto byebye;
	}
D 18
	if ( arg[2] == NIL ) {
E 18
I 18
	f_node = &(tree_node->for_node);
	if ( f_node->init_asg == TR_NIL ) {
E 18
	    goto byebye;
	}
D 18
	line = arg[1];
E 18
I 18
	line = f_node->line_no;
E 18
	putline();
D 18
	lhs = ( (int *) arg[2] )[2];
	init = ( (int *) arg[2] )[3];
	term = arg[3];
	stat = arg[4];
D 5
	if ( lhs[3] != NIL ) {
	    error("For variable must be unqualified");
E 5
I 5
	if (lhs == NIL) {
E 18
I 18
	lhs = f_node->init_asg->asg_node.lhs_var;
	init_node = f_node->init_asg->asg_node.rhs_expr;
	term_node = f_node->term_expr;
	stat_node = f_node->for_stmnt;
	if (lhs == TR_NIL) {
E 18
nogood:
I 8
	    if (forvar != NIL) {
		forvar->value[ NL_FORV ] = FORVAR;
	    }
E 8
E 5
D 18
	    rvalue( init , NIL , RREQ );
	    rvalue( term , NIL , RREQ );
	    statement( stat );
E 18
I 18
	    (void) rvalue( init_node , NLNIL , RREQ ); 
	    (void) rvalue( term_node , NLNIL , RREQ );
	    statement( stat_node );
E 18
	    goto byebye;
	}
I 18
	else lhs_node = &(lhs->var_node);
E 18
	    /*
	     * and this marks the variable as used!!!
	     */
D 18
	forvar = lookup( lhs[2] );
E 18
I 18
	forvar = lookup( lhs_node->cptr );
E 18
	if ( forvar == NIL ) {
D 5
	    rvalue( init , NIL , RREQ );
	    rvalue( term , NIL , RREQ );
	    statement( stat );
	    goto byebye;
E 5
I 5
	    goto nogood;
E 5
	}
I 8
D 11
	s_forv = forvar -> value[ NL_FORV ];
E 11
I 11
D 15
	shadow_nl = *forvar;
E 15
I 15
	saved_nl = *forvar;
E 15
E 11
E 8
I 5
D 18
	if ( lhs[3] != NIL ) {
E 18
I 18
	if ( lhs_node->qual != TR_NIL ) {
E 18
	    error("For variable %s must be unqualified", forvar->symbol);
	    goto nogood;
	}
	if (forvar->class == WITHPTR) {
D 18
	    error("For variable %s cannot be an element of a record", lhs[2]);
E 18
I 18
	    error("For variable %s cannot be an element of a record", 
			lhs_node->cptr);
E 18
	    goto nogood;
	}
D 10
	if (opt('s') &&
	    (bn != cbn || whereis(forvar->value[NL_OFFS]) == PARAMVAR)) {
E 10
I 10
	if ( opt('s') &&
	    ( ( bn != cbn ) ||
#ifdef OBJ
D 15
		( whereis( bn , forvar->value[NL_OFFS] , 0 ) == PARAMVAR )
E 15
I 15
D 18
		(whereis(bn, forvar->value[NL_OFFS], 0) == PARAMVAR)
E 18
I 18
		(whereis(forvar->value[NL_OFFS], 0) == PARAMVAR)
E 18
E 15
#endif OBJ
#ifdef PC
D 15
		( whereis( bn , forvar->value[NL_OFFS] , forvar -> extra_flags )
E 15
I 15
D 18
		(whereis(bn, forvar->value[NL_OFFS], forvar->extra_flags)
E 18
I 18
		(whereis(forvar->value[NL_OFFS], forvar->extra_flags)
E 18
E 15
		    == PARAMVAR )
#endif PC
	    ) ) {
E 10
	    standard();
	    error("For variable %s must be declared in the block in which it is used", forvar->symbol);
	}
E 5
	    /*
	     * find out the type of the loop variable
	     */
	codeoff();
	fortype = lvalue( lhs , MOD , RREQ );
	codeon();
D 8
	    /*
	     * mark the forvar so we can't change it during the loop
	     */
I 5
D 7
	if (forvar->value[NL_FORV]) {
E 7
I 7
	if ( forvar->value[ NL_FORV ] & FORBOUND ) {
E 7
	    error("Can't modify the for variable %s in the range of the loop", forvar->symbol);
	    forvar = NIL;
	    goto nogood;
	}
E 5
D 7
	forvar -> value[ NL_FORV ] = 1;
E 7
I 7
	forvar -> value[ NL_FORV ] |= LOOPVAR;
E 8
E 7
D 18
	if ( fortype == NIL ) {
E 18
I 18
	if ( fortype == NLNIL ) {
E 18
D 5
	    rvalue( init , NIL , RREQ );
	    rvalue( term , NIL , RREQ );
	    statement( stat );
	    goto byebye;
E 5
I 5
	    goto nogood;
E 5
	}
	if ( isnta( fortype , "bcis" ) ) {
D 5
	    error("For variables cannot be %ss" , nameof( fortype ) );
	    rvalue( init , NIL , RREQ );
	    rvalue( term , NIL , RREQ );
	    statement( stat );
	    goto byebye;
E 5
I 5
	    error("For variable %s cannot be %ss", forvar->symbol, nameof( fortype ) );
	    goto nogood;
E 5
	}
I 8
	if ( forvar->value[ NL_FORV ] & FORVAR ) {
	    error("Can't modify the for variable %s in the range of the loop", forvar->symbol);
D 18
	    forvar = NIL;
E 18
I 18
	    forvar = NLNIL;
E 18
	    goto nogood;
	}
I 15
	forwidth = lwidth(fortype);
#	ifdef PC
	    forp2type = p2type(fortype);
#	endif PC
E 15
E 8
	    /*
D 15
	     * allocate space for the initial and termination expressions
I 7
D 8
	     * save the old offset of this variable in NL_SOFFS
	     * save the old flags (and block) in NL_FORV
	     * and mark the variable as being a for-variable in a temporary
	     * set the new offset to be the offset of the initial temp
	     * set the flags/block to be the old flags and the current block
E 8
I 8
	     * the initial is tentatively placed in a register as it will
	     * shadow the for loop variable in the body of the loop.
E 15
I 15
	     *	allocate temporaries for the initial and final expressions
	     *	and maybe a register to shadow the for variable.
E 15
E 8
E 7
	     */
D 4
	sizes[cbn].om_off -= sizeof( long );
	initoff = sizes[cbn].om_off;
	sizes[cbn].om_off -= sizeof( long );
	termoff = sizes[cbn].om_off;
	if ( sizes[cbn].om_off < sizes[cbn].om_max ) {
	    sizes[cbn].om_max = sizes[cbn].om_off;
	}
E 4
I 4
D 10
	initoff = tmpalloc(sizeof(long), nl+T4INT, REGOK);
I 5
D 8
	forvar -> value[ NL_SOFFS ] = forvar -> value[ NL_OFFS ];
I 7
	forvar -> value[ NL_FORV ] = TEMPBOUND | forvar -> nl_flags;
E 7
	forvar -> value[ NL_OFFS ] = initoff;
D 7
	forvar -> value[ NL_FORV ] = 3;
E 7
I 7
	forflags = NLFLAGS( forvar -> nl_flags ) + cbn;
	forvar -> nl_flags = forflags;
E 7
E 5
	termoff = tmpalloc(sizeof(long), nl+T4INT, REGOK);
E 8
I 8
	termoff = tmpalloc(sizeof(long), nl+T4INT, NOREG);
E 10
I 10
D 14
	initnlp = tmpalloc(sizeof(long), nl+T4INT, REGOK);
	termnlp = tmpalloc(sizeof(long), nl+T4INT, NOREG);
E 14
I 14
D 15
	forwidth = lwidth(fortype);
	initnlp = tmpalloc(forwidth, fortype, REGOK);
	termnlp = tmpalloc(forwidth, fortype, NOREG);
E 15
I 15
D 18
	initnlp = tmpalloc(sizeof(long), nl+T4INT, NOREG);
	termnlp = tmpalloc(sizeof(long), nl+T4INT, NOREG);
	shadownlp = tmpalloc(forwidth, fortype, REGOK);
E 18
I 18
	initnlp = tmpalloc((long) sizeof(long), nl+T4INT, NOREG);
	termnlp = tmpalloc((long) sizeof(long), nl+T4INT, NOREG);
	shadownlp = tmpalloc((long) forwidth, fortype, REGOK);
E 18
E 15
E 14
E 10
E 8
E 4
#	ifdef PC
I 14
D 15
	    forctype = p2type(fortype);
E 15
E 14
D 4
	    putlbracket( ftnno , -sizes[cbn].om_off );
E 4
		/*
		 * compute and save the initial expression
		 */
D 10
	    forctype = p2type( fortype );
	    putRV( 0 , cbn , initoff , forctype );
E 10
I 10
D 18
	    putRV( 0 , cbn , initnlp -> value[ NL_OFFS ] ,
E 18
I 18
	    putRV((char *) 0 , cbn , initnlp -> value[ NL_OFFS ] ,
E 18
D 14
		    initnlp -> extra_flags , P2INT );
E 14
I 14
D 15
		    initnlp -> extra_flags , forctype );
	    if ( opt( 't' ) ) {
		precheck( fortype , "_RANG4" , "_RSNG4" );
	    }
E 15
I 15
D 23
		    initnlp -> extra_flags , P2INT );
E 23
I 23
		    initnlp -> extra_flags , PCCT_INT );
E 23
E 15
E 14
E 10
#	endif PC
#	ifdef OBJ
D 10
	    put(2, O_LV | cbn<<8+INDX, initoff);
E 10
I 10
D 18
	    put(2, O_LV | cbn<<8+INDX, initnlp -> value[ NL_OFFS ] );
E 18
I 18
	    (void) put(2, O_LV | cbn<<8+INDX, initnlp -> value[ NL_OFFS ] );
E 18
E 10
#	endif OBJ
D 18
	inittype = rvalue( init , fortype , RREQ );
	if ( incompat( inittype , fortype , init ) ) {
E 18
I 18
	inittype = rvalue( init_node , fortype , RREQ );
	if ( incompat( inittype , fortype , init_node ) ) {
E 18
	    cerror("Type of initial expression clashed with index type in 'for' statement");
I 8
D 18
	    if (forvar != NIL) {
E 18
I 18
	    if (forvar != NLNIL) {
E 18
		forvar->value[ NL_FORV ] = FORVAR;
	    }
E 8
D 18
	    rvalue( term , NIL , RREQ );
	    statement( stat );
E 18
I 18
	    (void) rvalue( term_node , NLNIL , RREQ );
	    statement( stat_node );
E 18
	    goto byebye;
	}
#	ifdef PC
I 13
D 14
	    sconv(p2type(inittype), P2INT);
E 13
D 10
	    putop( P2ASSIGN , forctype );
E 10
I 10
	    putop( P2ASSIGN , P2INT );
E 14
I 14
D 15
	    if ( opt( 't' ) ) {
		postcheck(fortype, inittype);
	    }
	    sconv(p2type(inittype), forctype);
	    putop( P2ASSIGN , forctype );
E 15
I 15
D 23
	    sconv(p2type(inittype), P2INT);
	    putop( P2ASSIGN , P2INT );
E 23
I 23
	    sconv(p2type(inittype), PCCT_INT);
	    putop( PCC_ASSIGN , PCCT_INT );
E 23
E 15
E 14
E 10
	    putdot( filename , line );
		/*
		 * compute and save the termination expression
		 */
D 10
	    putRV( 0 , cbn , termoff , forctype );
E 10
I 10
D 18
	    putRV( 0 , cbn , termnlp -> value[ NL_OFFS ] ,
E 18
I 18
	    putRV((char *) 0 , cbn , termnlp -> value[ NL_OFFS ] ,
E 18
D 14
		    termnlp -> extra_flags , P2INT );
E 14
I 14
D 15
		    termnlp -> extra_flags , forctype );
	    if ( opt( 't' ) ) {
		precheck( fortype , "_RANG4" , "_RSNG4" );
	    }
E 15
I 15
D 23
		    termnlp -> extra_flags , P2INT );
E 23
I 23
		    termnlp -> extra_flags , PCCT_INT );
E 23
E 15
E 14
E 10
#	endif PC
#	ifdef OBJ
D 3
	    put(1, width(inittype) <= 2 ? O_AS24 : O_AS4);
E 3
I 3
D 14
	    gen(O_AS2, O_AS2, sizeof(long), width(inittype));
E 14
I 14
D 15
	    rangechk(fortype, inittype);
	    gen(O_AS2, O_AS2, forwidth, lwidth(inittype));
E 15
I 15
D 18
	    gen(O_AS2, O_AS2, sizeof(long), width(inittype));
E 18
I 18
	    (void) gen(O_AS2, O_AS2, sizeof(long), width(inittype));
E 18
E 15
E 14
E 3
		/*
		 * compute and save the termination expression
		 */
D 10
	    put(2, O_LV | cbn<<8+INDX, termoff);
E 10
I 10
D 18
	    put(2, O_LV | cbn<<8+INDX, termnlp -> value[ NL_OFFS ] );
E 18
I 18
	    (void) put(2, O_LV | cbn<<8+INDX, termnlp -> value[ NL_OFFS ] );
E 18
E 10
#	endif OBJ
D 18
	termtype = rvalue( term , fortype , RREQ );
	if ( incompat( termtype , fortype , term ) ) {
E 18
I 18
	termtype = rvalue( term_node , fortype , RREQ );
	if ( incompat( termtype , fortype , term_node ) ) {
E 18
	    cerror("Type of limit expression clashed with index type in 'for' statement");
I 8
D 18
	    if (forvar != NIL) {
E 18
I 18
	    if (forvar != NLNIL) {
E 18
		forvar->value[ NL_FORV ] = FORVAR;
	    }
E 8
D 18
	    statement( stat );
E 18
I 18
	    statement( stat_node );
E 18
	    goto byebye;
	}
#	ifdef PC
I 13
D 14
	    sconv(p2type(termtype), P2INT);
E 13
D 10
	    putop( P2ASSIGN , forctype );
E 10
I 10
	    putop( P2ASSIGN , P2INT );
E 14
I 14
D 15
	    if ( opt( 't' ) ) {
		postcheck(fortype, termtype);
	    }
	    sconv(p2type(termtype), forctype);
	    putop( P2ASSIGN , forctype );
E 15
I 15
D 23
	    sconv(p2type(termtype), P2INT);
	    putop( P2ASSIGN , P2INT );
E 23
I 23
	    sconv(p2type(termtype), PCCT_INT);
	    putop( PCC_ASSIGN , PCCT_INT );
E 23
E 15
E 14
E 10
	    putdot( filename , line );
		/*
		 * we can skip the loop altogether if !( init <= term )
		 */
D 18
	    after = getlab();
D 10
	    putRV( 0 , cbn , initoff , forctype );
	    putRV( 0 , cbn , termoff , forctype );
	    putop( ( arg[0] == T_FORU ? P2LE : P2GE ) , forctype );
E 10
I 10
	    putRV( 0 , cbn , initnlp -> value[ NL_OFFS ] ,
E 18
I 18
	    after = (int) getlab();
	    putRV((char *) 0 , cbn , initnlp -> value[ NL_OFFS ] ,
E 18
D 14
		    initnlp -> extra_flags , P2INT );
E 14
I 14
D 15
		    initnlp -> extra_flags , forctype );
E 15
I 15
D 23
		    initnlp -> extra_flags , P2INT );
E 23
I 23
		    initnlp -> extra_flags , PCCT_INT );
E 23
E 15
E 14
D 18
	    putRV( 0 , cbn , termnlp -> value[ NL_OFFS ] ,
E 18
I 18
	    putRV((char *) 0 , cbn , termnlp -> value[ NL_OFFS ] ,
E 18
D 14
		    termnlp -> extra_flags , P2INT );
	    putop( ( arg[0] == T_FORU ? P2LE : P2GE ) , P2INT );
E 14
I 14
D 15
		    termnlp -> extra_flags , forctype );
	    putop( ( arg[0] == T_FORU ? P2LE : P2GE ) , forctype );
E 15
I 15
D 23
		    termnlp -> extra_flags , P2INT );
D 18
	    putop( ( arg[0] == T_FORU ? P2LE : P2GE ) , P2INT );
E 15
E 14
E 10
	    putleaf( P2ICON , after , 0 , P2INT , 0 );
E 18
I 18
	    putop( ( tree_node->tag == T_FORU ? P2LE : P2GE ) , P2INT );
	    putleaf( P2ICON , after , 0 , P2INT, (char *) 0 );
E 18
	    putop( P2CBRANCH , P2INT );
E 23
I 23
		    termnlp -> extra_flags , PCCT_INT );
	    putop( ( tree_node->tag == T_FORU ? PCC_LE : PCC_GE ) , PCCT_INT );
	    putleaf( PCC_ICON , after , 0 , PCCT_INT, (char *) 0 );
	    putop( PCC_CBRANCH , PCCT_INT );
E 23
	    putdot( filename , line );
		/*
I 15
		 * okay, so we have to execute the loop body,
		 * but first, if checking is on,
		 * check that the termination expression
		 * is assignment compatible with the control-variable.
		 */
	    if (opt('t')) {
		precheck(fortype, "_RANG4", "_RSNG4");
D 18
		putRV(0, cbn, termnlp -> value[NL_OFFS],
E 18
I 18
		putRV((char *) 0, cbn, termnlp -> value[NL_OFFS],
E 18
D 23
		    termnlp -> extra_flags, P2INT);
E 23
I 23
		    termnlp -> extra_flags, PCCT_INT);
E 23
		postcheck(fortype, nl+T4INT);
		putdot(filename, line);
	    }
		/*
		 * assign the initial expression to the shadow
		 * checking the assignment if necessary.
		 */
D 18
	    putRV(0, cbn, shadownlp -> value[NL_OFFS],
E 18
I 18
	    putRV((char *) 0, cbn, shadownlp -> value[NL_OFFS],
E 18
		shadownlp -> extra_flags, forp2type);
	    if (opt('t')) {
		precheck(fortype, "_RANG4", "_RSNG4");
D 18
		putRV(0, cbn, initnlp -> value[NL_OFFS],
E 18
I 18
		putRV((char *) 0, cbn, initnlp -> value[NL_OFFS],
E 18
D 23
		    initnlp -> extra_flags, P2INT);
E 23
I 23
		    initnlp -> extra_flags, PCCT_INT);
E 23
		postcheck(fortype, nl+T4INT);
	    } else {
D 18
		putRV(0, cbn, initnlp -> value[NL_OFFS],
E 18
I 18
		putRV((char *) 0, cbn, initnlp -> value[NL_OFFS],
E 18
D 23
		    initnlp -> extra_flags, P2INT);
E 23
I 23
		    initnlp -> extra_flags, PCCT_INT);
E 23
	    }
D 23
	    sconv(P2INT, forp2type);
	    putop(P2ASSIGN, forp2type);
E 23
I 23
	    sconv(PCCT_INT, forp2type);
	    putop(PCC_ASSIGN, forp2type);
E 23
	    putdot(filename, line);
		/*
E 15
I 5
		 * put down the label at the top of the loop
		 */
D 18
	    again = getlab();
	    putlab( again );
E 18
I 18
	    again = (int) getlab();
	    (void) putlab((char *) again );
E 18
		/*
E 5
D 15
		 * okay, then we have to execute the body, but first,
		 * assign the initial expression to the for variable.
		 * see the note in asgnop1 about why this is an rvalue.
E 15
I 15
		 * each time through the loop
		 * assign the shadow to the for variable.
E 15
		 */
I 5
D 8
	    forvar -> value[ NL_OFFS ] = forvar -> value[ NL_SOFFS ];
E 5
D 7
	    rvalue( lhs , NIL , RREQ );
E 7
I 7
	    forflags |= forvar -> nl_flags;
	    forvar -> nl_flags = (char) forvar -> value[ NL_FORV ] &~ FORBOUND;
E 8
D 15
	    lvalue( lhs , NOUSE , RREQ );
E 7
I 5
D 8
	    forvar -> value[ NL_OFFS ] = initoff;
I 7
	    forvar -> nl_flags = forflags;
E 8
E 7
E 5
D 14
	    if ( opt( 't' ) ) {
		precheck( fortype , "_RANG4" , "_RSNG4" );
	    }
E 14
D 10
	    putRV( 0 , cbn , initoff , forctype );
E 10
I 10
	    putRV( 0 , cbn , initnlp -> value[ NL_OFFS ] ,
D 14
		    initnlp -> extra_flags , P2INT );
E 10
	    if ( opt( 't' ) ) {
D 13
		postcheck( fortype );
E 13
I 13
		postcheck(fortype, nl+T4INT);
E 13
	    }
I 13
	    sconv(P2INT, p2type(fortype));
E 14
I 14
		    initnlp -> extra_flags , forctype );
E 14
E 13
D 10
	    putop( P2ASSIGN , forctype );
E 10
I 10
	    putop( P2ASSIGN , p2type( fortype ) );
E 10
	    putdot( filename , line );
E 15
I 15
D 18
	    lvalue(lhs, NOUSE, RREQ);
	    putRV(0, cbn, shadownlp -> value[NL_OFFS],
E 18
I 18
	    (void) lvalue(lhs, NOUSE, RREQ);
	    putRV((char *) 0, cbn, shadownlp -> value[NL_OFFS],
E 18
		    shadownlp -> extra_flags, forp2type);
D 23
	    putop(P2ASSIGN, forp2type);
E 23
I 23
	    putop(PCC_ASSIGN, forp2type);
E 23
	    putdot(filename, line);
E 15
#	endif PC
#	ifdef OBJ
D 3
	    put(1, width(termtype) <= 2 ? O_AS24 : O_AS4);
E 3
I 3
D 14
	    gen(O_AS2, O_AS2, sizeof(long), width(termtype));
E 14
I 14
D 15
	    rangechk(fortype, termtype);
	    gen(O_AS2, O_AS2, forwidth, lwidth(termtype));
E 15
I 15
D 18
	    gen(O_AS2, O_AS2, sizeof(long), width(termtype));
E 18
I 18
	    (void) gen(O_AS2, O_AS2, sizeof(long), width(termtype));
E 18
E 15
E 14
E 3
		/*
		 * we can skip the loop altogether if !( init <= term )
		 */
D 10
	    put(2, O_RV4 | cbn<<8+INDX, initoff);
	    put(2, O_RV4 | cbn<<8+INDX, termoff);
E 10
I 10
D 14
	    put(2, O_RV4 | cbn<<8+INDX, initnlp -> value[ NL_OFFS ] );
	    put(2, O_RV4 | cbn<<8+INDX, termnlp -> value[ NL_OFFS ] );
E 10
	    gen(NIL, arg[0] == T_FORU ? T_LE : T_GE, sizeof(long),
			sizeof(long));
E 14
I 14
D 15
	    stackRV(initnlp);
	    stackRV(termnlp);
	    gen(NIL, arg[0] == T_FORU ? T_LE : T_GE, lwidth(nl+T4INT),
			lwidth(nl+T4INT));
E 15
I 15
D 18
	    put(2, O_RV4 | cbn<<8+INDX, initnlp -> value[ NL_OFFS ] );
	    put(2, O_RV4 | cbn<<8+INDX, termnlp -> value[ NL_OFFS ] );
	    gen(NIL, arg[0] == T_FORU ? T_LE : T_GE, sizeof(long),
E 18
I 18
	    (void) put(2, O_RV4 | cbn<<8+INDX, initnlp -> value[ NL_OFFS ] );
	    (void) put(2, O_RV4 | cbn<<8+INDX, termnlp -> value[ NL_OFFS ] );
	    (void) gen(NIL, tree_node->tag == T_FORU ? T_LE : T_GE, sizeof(long),
E 18
			sizeof(long));
E 15
E 14
D 18
	    after = getlab();
	    put(2, O_IF, after);
E 18
I 18
	    after = (int) getlab();
	    (void) put(2, O_IF, after);
E 18
		/*
I 15
		 * okay, so we have to execute the loop body,
		 * but first, if checking is on,
		 * check that the termination expression
		 * is assignment compatible with the control-variable.
		 */
	    if (opt('t')) {
D 18
		put(2, O_LV | cbn<<8+INDX, shadownlp -> value[ NL_OFFS ] );
		put(2, O_RV4 | cbn<<8+INDX, termnlp -> value[ NL_OFFS ] );
E 18
I 18
		(void) put(2, O_LV | cbn<<8+INDX, shadownlp -> value[ NL_OFFS ] );
		(void) put(2, O_RV4 | cbn<<8+INDX, termnlp -> value[ NL_OFFS ] );
E 18
		rangechk(fortype, nl+T4INT);
D 18
		gen(O_AS2, O_AS2, forwidth, sizeof(long));
E 18
I 18
		(void) gen(O_AS2, O_AS2, forwidth, sizeof(long));
E 18
	    }
		/*
		 * assign the initial expression to the shadow
		 * checking the assignment if necessary.
		 */
D 18
	    put(2, O_LV | cbn<<8+INDX, shadownlp -> value[ NL_OFFS ] );
	    put(2, O_RV4 | cbn<<8+INDX, initnlp -> value[ NL_OFFS ] );
E 18
I 18
	    (void) put(2, O_LV | cbn<<8+INDX, shadownlp -> value[ NL_OFFS ] );
	    (void) put(2, O_RV4 | cbn<<8+INDX, initnlp -> value[ NL_OFFS ] );
E 18
	    rangechk(fortype, nl+T4INT);
D 18
	    gen(O_AS2, O_AS2, forwidth, sizeof(long));
E 18
I 18
	    (void) gen(O_AS2, O_AS2, forwidth, sizeof(long));
E 18
		/*
E 15
I 5
		 * put down the label at the top of the loop
		 */
D 18
	    again = getlab();
	    putlab( again );
E 18
I 18
	    again = (int) getlab();
	    (void) putlab( (char *) again );
E 18
		/*
E 5
D 15
		 * okay, then we have to execute the body, but first,
		 * assign the initial expression to the for variable.
E 15
I 15
		 * each time through the loop
		 * assign the shadow to the for variable.
E 15
		 */
I 5
D 8
	    forvar -> value[ NL_OFFS ] = forvar -> value[ NL_SOFFS ];
I 7
	    forflags |= forvar -> nl_flags;
	    forvar -> nl_flags = (char) forvar -> value[ NL_FORV ] &~ FORBOUND;
E 8
E 7
E 5
D 15
	    lvalue( lhs , NOUSE , LREQ );
I 7
D 8
	    forvar -> value[ NL_OFFS ] = initoff;
	    forvar -> nl_flags = forflags;
E 8
E 7
D 10
	    put(2, O_RV4 | cbn<<8+INDX, initoff);
E 10
I 10
D 14
	    put(2, O_RV4 | cbn<<8+INDX, initnlp -> value[ NL_OFFS ] );
E 10
	    rangechk(fortype, nl+T4INT);
D 3
	    put(1, width(fortype) <= 2 ? O_AS42 : O_AS4);
E 3
I 3
	    gen(O_AS2, O_AS2, width(fortype), sizeof(long));
E 14
I 14
	    stackRV(initnlp);
	    gen(O_AS2, O_AS2, forwidth, lwidth(nl+T4INT));
E 15
I 15
D 18
	    lvalue(lhs, NOUSE, RREQ);
	    stackRV(shadownlp);
	    gen(O_AS2, O_AS2, forwidth, sizeof(long));
E 18
I 18
	    (void) lvalue(lhs, NOUSE, RREQ);
	    (void) stackRV(shadownlp);
	    (void) gen(O_AS2, O_AS2, forwidth, sizeof(long));
E 18
E 15
E 14
I 5
D 7
	    forvar -> value[ NL_OFFS ] = initoff;
E 7
E 5
E 3
#	endif OBJ
D 5
	/*
	 * put down the label at the top of the loop
	 */
	again = getlab();
	putlab( again );
	putcnt();
E 5
	    /*
I 8
	     *	shadowing the real for variable
D 15
	     *	with the initail expression temporary:
	     *	save the real for variable's offset, flags
	     *	(including nl_block).
	     *	replace them with the initial expression's offset,
	     *	and mark it as being a for variable.
E 15
I 15
	     *	with the shadow temporary:
	     *	save the real for variable flags (including nl_block).
	     *	replace them with the shadow's offset,
	     *	and mark the for variable as being a for variable.
E 15
	     */
I 12
D 15
	shadow_nl.nl_flags = forvar -> nl_flags;
E 12
D 11
	shadowed = TRUE;
	s_offset = forvar -> value[ NL_OFFS ];
	s_flags = forvar -> nl_flags;
D 10
	forvar -> value[ NL_OFFS ] = initoff;
E 10
I 10
	forvar -> value[ NL_OFFS ] = initnlp -> value[ NL_OFFS ];
E 10
	forvar -> nl_flags = cbn;
E 11
I 11
	*forvar = *initnlp;
	forvar -> symbol = shadow_nl.symbol;
	forvar -> nl_next = shadow_nl.nl_next;
E 15
I 15
D 16
	shadownlp -> nl_flags = forvar -> nl_flags;
E 16
I 16
	shadownlp -> nl_flags |= NLFLAGS(forvar -> nl_flags);
E 16
	*forvar = *shadownlp;
	forvar -> symbol = saved_nl.symbol;
	forvar -> nl_next = saved_nl.nl_next;
	forvar -> type = saved_nl.type;
E 15
I 12
D 14
	forvar -> type = shadow_nl.type;
E 14
E 12
E 11
	forvar -> value[ NL_FORV ] = FORVAR;
I 10
D 11
#	ifdef PC
	    s_extra_flags = forvar -> extra_flags;
	    forvar -> extra_flags = initnlp -> extra_flags;
#	endif PC
E 11
E 10
	    /*
E 8
	     * and don't forget ...
	     */
D 5
	statement( arg[ 4 ] );
E 5
I 5
	putcnt();
D 18
	statement( stat );
E 18
I 18
	statement( stat_node );
E 18
E 5
	    /*
	     * wasn't that fun?  do we get to do it again?
	     *	we don't do it again if ( !( forvar < limit ) )
	     *	pretend we were doing this at the top of the loop
	     */
D 18
	line = arg[ 1 ];
E 18
I 18
	line = f_node->line_no;
E 18
#	ifdef PC
	    if ( opt( 'p' ) ) {
		if ( opt('t') ) {
D 23
		    putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
E 23
I 23
		    putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 23
			    , "_LINO" );
D 23
		    putop( P2UNARY P2CALL , P2INT );
E 23
I 23
		    putop( PCCOM_UNARY PCC_CALL , PCCT_INT );
E 23
		    putdot( filename , line );
		} else {
D 10
		    putRV( STMTCOUNT , 0 , 0 , P2INT );
E 10
I 10
D 23
		    putRV( STMTCOUNT , 0 , 0 , NGLOBAL , P2INT );
E 10
D 18
		    putleaf( P2ICON , 1 , 0 , P2INT , 0 );
E 18
I 18
		    putleaf( P2ICON , 1 , 0 , P2INT , (char *) 0 );
E 18
		    putop( P2ASG P2PLUS , P2INT );
E 23
I 23
		    putRV( STMTCOUNT , 0 , 0 , NGLOBAL , PCCT_INT );
		    putleaf( PCC_ICON , 1 , 0 , PCCT_INT , (char *) 0 );
		    putop( PCCOM_ASG PCC_PLUS , PCCT_INT );
E 23
		    putdot( filename , line );
		}
	    }
D 10
	    rvalue( lhs , NIL , RREQ );
	    putRV( 0 , cbn , termoff , forctype );
	    putop( ( arg[ 0 ] == T_FORU ? P2LT : P2GT ) , forctype );
E 10
I 10
D 18
	    /*rvalue( lhs , NIL , RREQ );*/
D 15
	    putRV( 0 , cbn , initnlp -> value[ NL_OFFS ] ,
D 14
		    initnlp -> extra_flags , P2INT );
E 14
I 14
		    initnlp -> extra_flags , forctype );
E 15
I 15
	    putRV( 0 , cbn , shadownlp -> value[ NL_OFFS ] ,
E 18
I 18
	    /*rvalue( lhs_node , NIL , RREQ );*/
	    putRV( (char *) 0 , cbn , shadownlp -> value[ NL_OFFS ] ,
E 18
		    shadownlp -> extra_flags , forp2type );
D 23
	    sconv(forp2type, P2INT);
E 23
I 23
	    sconv(forp2type, PCCT_INT);
E 23
E 15
E 14
D 18
	    putRV( 0 , cbn , termnlp -> value[ NL_OFFS ] ,
E 18
I 18
	    putRV( (char *) 0 , cbn , termnlp -> value[ NL_OFFS ] ,
E 18
D 14
		    termnlp -> extra_flags , P2INT );
E 14
I 14
D 15
		    termnlp -> extra_flags , forctype );
E 15
I 15
D 23
		    termnlp -> extra_flags , P2INT );
E 15
E 14
D 18
	    putop( ( arg[ 0 ] == T_FORU ? P2LT : P2GT ) , P2INT );
E 10
	    putleaf( P2ICON , after , 0 , P2INT , 0 );
E 18
I 18
	    putop( ( tree_node->tag == T_FORU ? P2LT : P2GT ) , P2INT );
	    putleaf( P2ICON , after , 0 , P2INT , (char *) 0 );
E 18
	    putop( P2CBRANCH , P2INT );
E 23
I 23
		    termnlp -> extra_flags , PCCT_INT );
	    putop( ( tree_node->tag == T_FORU ? PCC_LT : PCC_GT ) , PCCT_INT );
	    putleaf( PCC_ICON , after , 0 , PCCT_INT , (char *) 0 );
	    putop( PCC_CBRANCH , PCCT_INT );
E 23
	    putdot( filename , line );
		/*
		 * okay, so we have to do it again,
		 * but first, increment the for variable.
D 15
		 * there it is again, an rvalue on the lhs of an assignment.
E 15
I 15
		 * no need to rangecheck it, since we checked the
		 * termination value before we started.
E 15
		 */
D 7
	    rvalue( lhs , NIL , RREQ );
E 7
I 7
D 10
	    lvalue( lhs , MOD , RREQ );
E 10
I 10
	    /*lvalue( lhs , MOD , RREQ );*/
D 15
	    putRV( 0 , cbn , initnlp -> value[ NL_OFFS ] ,
D 14
		    initnlp -> extra_flags , P2INT );
E 14
I 14
		    initnlp -> extra_flags , forctype );
E 14
E 10
E 7
	    if ( opt( 't' ) ) {
		precheck( fortype , "_RANG4" , "_RSNG4" );
	    }
E 15
I 15
D 18
	    putRV( 0 , cbn , shadownlp -> value[ NL_OFFS ] ,
E 18
I 18
	    putRV( (char *) 0 , cbn , shadownlp -> value[ NL_OFFS ] ,
E 18
		    shadownlp -> extra_flags , forp2type );
E 15
D 10
	    rvalue( lhs , NIL , RREQ );
E 10
I 10
D 18
	    /*rvalue( lhs , NIL , RREQ );*/
D 15
	    putRV( 0 , cbn , initnlp -> value[ NL_OFFS ] ,
D 14
		    initnlp -> extra_flags , P2INT );
E 14
I 14
		    initnlp -> extra_flags , forctype );
	    sconv(forctype, P2INT);
E 15
I 15
	    putRV( 0 , cbn , shadownlp -> value[ NL_OFFS ] ,
E 18
I 18
	    /*rvalue( lhs_node , NIL , RREQ );*/
	    putRV( (char *) 0 , cbn , shadownlp -> value[ NL_OFFS ] ,
E 18
		    shadownlp -> extra_flags , forp2type );
D 23
	    sconv(forp2type, P2INT);
E 15
E 14
E 10
D 9
	    putleaf( P2ICON , 1 , 0 , forctype , 0 );
	    putop( ( arg[0] == T_FORU ? P2PLUS : P2MINUS ) , forctype );
E 9
I 9
D 18
	    putleaf( P2ICON , 1 , 0 , P2INT , 0 );
	    putop( ( arg[0] == T_FORU ? P2PLUS : P2MINUS ) , P2INT );
E 18
I 18
	    putleaf( P2ICON , 1 , 0 , P2INT , (char *) 0 );
	    putop( ( tree_node->tag == T_FORU ? P2PLUS : P2MINUS ) , P2INT );
E 18
E 9
D 15
	    if ( opt( 't' ) ) {
D 13
		postcheck( fortype );
E 13
I 13
		postcheck(fortype, nl+T4INT);
E 13
	    }
D 10
	    putop( P2ASSIGN , forctype );
E 10
I 10
D 14
	    putop( P2ASSIGN , P2INT );
E 14
I 14
	    sconv(P2INT, forctype);
	    putop( P2ASSIGN , forctype );
E 15
I 15
	    sconv(P2INT, forp2type);
	    putop( P2ASSIGN , forp2type );
E 23
I 23
	    sconv(forp2type, PCCT_INT);
	    putleaf( PCC_ICON , 1 , 0 , PCCT_INT , (char *) 0 );
	    putop( ( tree_node->tag == T_FORU ? PCC_PLUS : PCC_MINUS ) , PCCT_INT );
	    sconv(PCCT_INT, forp2type);
	    putop( PCC_ASSIGN , forp2type );
E 23
E 15
E 14
E 10
	    putdot( filename , line );
		/*
		 * and do it all again
		 */
D 18
	    putjbr( again );
E 18
I 18
	    putjbr( (long) again );
E 18
		/*
		 * and here we are
		 */
D 18
	    putlab( after );
E 18
I 18
	    (void) putlab( (char *) after );
E 18
D 4
		/*
		 * deallocate the initial and limit variables
		 */
	    sizes[cbn].om_off += 2 * ( sizeof( long ) );
	    putlbracket( ftnno , -sizes[cbn].om_off );
E 4
#	endif PC
#	ifdef OBJ
		/*
		 * okay, so we have to do it again.
		 * Luckily we have a magic opcode which increments the
		 * index variable, checks the limit falling through if
D 15
		 * it has been reached, else range checking the result
		 * updating the index variable, and returning to the top
		 * of the loop.
E 15
I 15
		 * it has been reached, else updating the index variable,
		 * and returning to the top of the loop.
E 15
		 */
I 2
	    putline();
E 2
D 10
	    put(2, O_RV4 | cbn<<8+INDX, termoff);
E 10
I 10
D 14
	    put(2, O_RV4 | cbn<<8+INDX, termnlp -> value[ NL_OFFS ] );
E 10
	    lvalue(lhs, MOD, LREQ);
D 3
	    put(4, (arg[0] == T_FORU ? O_FOR1U : O_FOR1D) + (width(fortype)>>1),
		    fortype->range[0], fortype->range[1], again);
E 3
I 3
	    if (width(fortype) <= 2)
		    put(4, (arg[0] == T_FORU ? O_FOR1U : O_FOR1D) +
			    (width(fortype)>>1), (int)fortype->range[0],
			    (int)fortype->range[1], again);
E 14
I 14
D 15
	    stackRV(termnlp);
	    put(2, O_LV | cbn<<8+INDX, initnlp -> value[ NL_OFFS ] );
	    if (forwidth <= 2)
		    put(4,
			(arg[0] == T_FORU ? O_FOR1U : O_FOR1D) + (forwidth>>1),
			(int)fortype->range[0], (int)fortype->range[1], again);
E 14
	    else
		    put(4, (arg[0] == T_FORU ? O_FOR4U : O_FOR4D),
			    fortype->range[0], fortype->range[1], again);
E 15
I 15
D 18
	    put(2, O_RV4 | cbn<<8+INDX, termnlp -> value[ NL_OFFS ] );
	    put(2, O_LV | cbn<<8+INDX, shadownlp -> value[ NL_OFFS ] );
	    put(2, (arg[0] == T_FORU ? O_FOR1U : O_FOR1D) + (forwidth >> 1),
E 18
I 18
	    (void) put(2, O_RV4 | cbn<<8+INDX, termnlp -> value[ NL_OFFS ] );
	    (void) put(2, O_LV | cbn<<8+INDX, shadownlp -> value[ NL_OFFS ] );
	    (void) put(2, (tree_node->tag == T_FORU ? O_FOR1U : O_FOR1D) + (forwidth >> 1),
E 18
		    again);
E 15
E 3
		/*
		 * and here we are
		 */
D 18
	    patch( after );
E 18
I 18
	    patch( (PTR_DCL) after );
E 18
D 4
		/*
		 * deallocate the initial and limit variables
		 */
	    sizes[cbn].om_off += 2 * ( sizeof( long ) );
E 4
#	endif OBJ
I 14
D 15
	/* and fall through */
E 15
E 14
byebye:
D 18
	noreach = 0;
D 8
	if ( forvar != NIL ) {
I 5
D 7
	    if (forvar -> value[ NL_FORV ] > 1)
E 7
I 7
	    if (forvar -> value[ NL_FORV ] & TEMPBOUND ) {
E 7
		forvar -> value[ NL_OFFS ] = forvar -> value[ NL_SOFFS ];
E 5
D 7
	    forvar -> value[ NL_FORV ] = 0;
E 7
I 7
		forvar -> nl_flags =
			    (char)  ( ( forvar -> value[ NL_FORV ] &~ FORBOUND )
				    | NLFLAGS( forvar -> nl_flags ) );
	    }
	    forvar -> value[ NL_FORV ] = NIL;
E 8
I 8
	if (forvar != NIL) {
E 18
I 18
	noreach = FALSE;
	if (forvar != NLNIL) {
E 18
I 12
D 15
	    shadow_nl.nl_flags |= forvar -> nl_flags & (NUSED|NMOD);
E 12
D 11
	    forvar -> value[ NL_FORV ] = s_forv;
	}
	if ( shadowed ) {
	    forvar -> value[ NL_OFFS ] = s_offset;
	    forvar -> nl_flags = s_flags;
I 10
#	    ifdef PC
		forvar -> extra_flags = s_extra_flags;
#	    endif PC
E 11
I 11
	    *forvar = shadow_nl;
E 15
I 15
D 16
	    saved_nl.nl_flags |= forvar -> nl_flags & (NUSED|NMOD);
E 16
I 16
	    saved_nl.nl_flags |= NLFLAGS(forvar -> nl_flags) & (NUSED|NMOD);
E 16
	    *forvar = saved_nl;
E 15
E 11
E 10
E 8
E 7
	}
	if ( goc != gocnt ) {
	    putcnt();
	}
    }
E 1
