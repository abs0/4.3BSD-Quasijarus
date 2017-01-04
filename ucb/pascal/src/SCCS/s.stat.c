h36804
s 00007/00003/00695
d D 5.1 85/06/05 14:55:32 dist 19 18
c Add copyright
e
s 00029/00029/00669
d D 2.2 85/03/20 15:06:46 ralph 18 17
c changes from donn@utah-cs for common header file for pcc
e
s 00000/00000/00698
d D 2.1 84/02/08 20:47:32 aoki 17 16
c synchronize to version 2
e
s 00107/00086/00591
d D 1.15 84/02/08 20:06:30 aoki 16 15
c clean up conformant array assignments.
e
s 00066/00002/00611
d D 1.14 84/02/08 00:47:11 mckusick 15 14
c merge in conformant array code by Carol Nishizak
e
s 00001/00002/00612
d D 1.13 84/02/06 20:23:01 mckusick 14 12
i 13
c merge lint by thien
e
s 00134/00138/00474
d D 1.11.1.1 84/02/04 20:26:33 mckusick 13 11
c lint (by thien)
e
s 00006/00001/00611
d D 1.12 83/09/05 18:49:10 peter 12 11
c use nl+TPTR as type of temporary so it goes in an address register.
e
s 00002/00002/00610
d D 1.11 83/04/06 22:10:45 peter 11 10
c it says in my description of the ir that STASG's have the type
c pointer to structure.  this makes a difference for the FORCE in fend.c
c on the mc68000.
e
s 00001/00000/00611
d D 1.10 83/02/28 17:17:23 peter 10 9
c clean up temporary allocation, moving everything relevant to
c tmps.c and (new) tmps.h.  correctly emit LBRAC lines.  allocate registers
c from high to low.  put in data structures for multiple types of registers.
e
s 00003/00004/00608
d D 1.9 83/01/17 13:57:07 mckusick 9 8
c put in explicit scalar converts (sconv's) to make less code-generator dependent.
e
s 00039/00024/00573
d D 1.8 82/10/21 17:21:13 peter 8 7
c to correct the ir to the code generator,
c if the lefthandside is a double and the righthandside isn't, cast it.
e
s 00000/00040/00597
d D 1.7 82/08/27 00:34:32 mckusick 7 6
c convert "assert" from being a reserved word to being a non-standard procedure
e
s 00006/00000/00631
d D 1.6 82/02/02 12:56:54 linton 6 5
c merge pdx into the Pascal system
e
s 00013/00009/00618
d D 1.5 81/06/01 15:40:00 peter 5 4
c add storage classes to namelist, and use them.
e
s 00004/00018/00623
d D 1.4 81/03/11 23:44:17 mckusic 4 3
c centralize temporary allocation in tmps.c
e
s 00027/00015/00614
d D 1.3 81/03/08 19:28:13 mckusic 3 2
c merge in onyx changes
e
s 00001/00124/00628
d D 1.2 81/01/16 18:01:52 mckusic 2 1
c convert pi for loop construct to look like pc for loop
e
s 00752/00000/00000
d D 1.1 80/08/27 19:56:26 peter 1 0
c date and time created 80/08/27 19:56:26 by peter
e
u
U
f b 
t
T
I 1
D 19
/* Copyright (c) 1979 Regents of the University of California */
E 19
I 19
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 19

I 13
#ifndef lint
E 13
D 3
static	char sccsid[] = "%Z%%M% %I% %G%";
E 3
I 3
D 19
static char sccsid[] = "%Z%%M% %I% %G%";
I 13
#endif
E 19
I 19
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 19
E 13
E 3

#include "whoami.h"
#include "0.h"
#include "tree.h"
#include "objfmt.h"
#ifdef PC
D 18
#   include "pcops.h"
E 18
I 18
#   include <pcc.h>
E 18
#   include "pc.h"
#endif PC
I 10
#include "tmps.h"
E 10

int cntstat;
short cnts = 3;
#include "opcode.h"
I 13
#include "tree_ty.h"
E 13

/*
 * Statement list
 */
statlist(r)
D 13
	int *r;
E 13
I 13
	struct tnode *r;
E 13
{
D 13
	register *sl;
E 13
I 13
	register struct tnode *sl;
E 13

D 13
	for (sl=r; sl != NIL; sl=sl[2])
		statement(sl[1]);
E 13
I 13
	for (sl=r; sl != TR_NIL; sl=sl->list_node.next)
		statement(sl->list_node.list);
E 13
}

/*
 * Statement
 */
statement(r)
D 13
	int *r;
E 13
I 13
	struct tnode *r;
E 13
{
D 13
	register *s;
E 13
I 13
	register struct tnode *tree_node;
E 13
	register struct nl *snlp;
D 4
	long	soffset;
E 4
I 4
	struct tmps soffset;
E 4

D 13
	s = r;
E 13
I 13
	tree_node = r;
E 13
	snlp = nlp;
D 4
	soffset = sizes[ cbn ].om_off;
E 4
I 4
	soffset = sizes[cbn].curtmps;
E 4
top:
	if (cntstat) {
		cntstat = 0;
		putcnt();
	}
D 13
	if (s == NIL)
E 13
I 13
	if (tree_node == TR_NIL)
E 13
		return;
D 13
	line = s[1];
	if (s[0] == T_LABEL) {
		labeled(s[2]);
		s = s[3];
		noreach = 0;
E 13
I 13
	line = tree_node->lined.line_no; 
	if (tree_node->tag == T_LABEL) {
		labeled(tree_node->label_node.lbl_ptr);
		tree_node = tree_node->label_node.stmnt;
		noreach = FALSE;
E 13
		cntstat = 1;
		goto top;
	}
	if (noreach) {
D 13
		noreach = 0;
E 13
I 13
		noreach = FALSE;
E 13
		warning();
		error("Unreachable statement");
	}
D 13
	switch (s[0]) {
E 13
I 13
	switch (tree_node->tag) {
E 13
		case T_PCALL:
			putline();
#			ifdef OBJ
D 13
			    proc(s);
E 13
I 13
			    proc(tree_node);
E 13
#			endif OBJ
#			ifdef PC
D 13
			    pcproc( s );
E 13
I 13
			    pcproc( tree_node );
E 13
#			endif PC
			break;
		case T_ASGN:
			putline();
D 13
			asgnop(s);
E 13
I 13
			asgnop(&(tree_node->asg_node));
E 13
			break;
		case T_GOTO:
			putline();
D 13
			gotoop(s[2]);
			noreach = 1;
E 13
I 13
			gotoop(tree_node->goto_node.lbl_ptr);
			noreach = TRUE;
E 13
			cntstat = 1;
			break;
		default:
			level++;
D 13
			switch (s[0]) {
E 13
I 13
			switch (tree_node->tag) {
E 13
				default:
					panic("stat");
				case T_IF:
				case T_IFEL:
D 13
					ifop(s);
E 13
I 13
					ifop(&(tree_node->if_node));
E 13
					break;
				case T_WHILE:
D 13
					whilop(s);
					noreach = 0;
E 13
I 13
					whilop(&(tree_node->whi_cas));
					noreach = FALSE;
E 13
					break;
				case T_REPEAT:
D 13
					repop(s);
E 13
I 13
					repop(&(tree_node->repeat));
E 13
					break;
				case T_FORU:
				case T_FORD:
D 2
#					ifdef OBJ
					    forop(s);
#					endif OBJ
#					ifdef PC
					    pcforop( s );
#					endif PC
E 2
I 2
D 13
				        forop(s);
E 2
					noreach = 0;
E 13
I 13
				        forop(tree_node);
					noreach = FALSE;
E 13
					break;
				case T_BLOCK:
D 13
					statlist(s[2]);
E 13
I 13
					statlist(tree_node->stmnt_blck.stmnt_list);
E 13
					break;
				case T_CASE:
					putline();
#					ifdef OBJ
D 13
					    caseop(s);
E 13
I 13
					    caseop(&(tree_node->whi_cas));
E 13
#					endif OBJ
#					ifdef PC
D 13
					    pccaseop( s );
E 13
I 13
					    pccaseop(&(tree_node->whi_cas));
E 13
#					endif PC
					break;
				case T_WITH:
D 13
					withop(s);
E 13
I 13
					withop(&(tree_node->with_node));
E 13
					break;
D 7
				case T_ASRT:
					putline();
					asrtop(s);
					break;
E 7
			}
			--level;
			if (gotos[cbn])
				ungoto();
			break;
	}
	/*
	 * Free the temporary name list entries defined in
	 * expressions, e.g. STRs, and WITHPTRs from withs.
	 */
	nlfree(snlp);
	    /*
	     *	free any temporaries allocated for this statement
	     *	these come from strings and sets.
	     */
D 4
	if ( soffset != sizes[ cbn ].om_off ) {
	    sizes[ cbn ].om_off = soffset;
#	    ifdef PC
		putlbracket( ftnno , -sizes[cbn].om_off );
#	    endif PC
	}
E 4
I 4
	tmpfree(&soffset);
E 4
}

ungoto()
{
	register struct nl *p;

D 13
	for (p = gotos[cbn]; p != NIL; p = p->chain)
E 13
I 13
	for (p = gotos[cbn]; p != NLNIL; p = p->chain)
E 13
		if ((p->nl_flags & NFORWD) != 0) {
			if (p->value[NL_GOLEV] != NOTYET)
				if (p->value[NL_GOLEV] > level)
					p->value[NL_GOLEV] = level;
		} else
			if (p->value[NL_GOLEV] != DEAD)
				if (p->value[NL_GOLEV] > level)
					p->value[NL_GOLEV] = DEAD;
}

putcnt()
{

D 13
	if (monflg == 0) {
E 13
I 13
	if (monflg == FALSE) {
E 13
		return;
	}
	inccnt( getcnt() );
}

int
getcnt()
    {
	
	return ++cnts;
    }

inccnt( counter )
    int	counter;
    {

#	ifdef OBJ
D 3
	    put2(O_COUNT, counter );
E 3
I 3
D 13
	    put(2, O_COUNT, counter );
E 13
I 13
	    (void) put(2, O_COUNT, counter );
E 13
E 3
#	endif OBJ
#	ifdef PC
D 5
	    putRV( PCPCOUNT , 0 , counter * sizeof (long) , P2INT );
E 5
I 5
D 18
	    putRV( PCPCOUNT , 0 , counter * sizeof (long) , NGLOBAL , P2INT );
E 5
D 13
	    putleaf( P2ICON , 1 , 0 , P2INT , 0 );
E 13
I 13
	    putleaf( P2ICON , 1 , 0 , P2INT , (char *) 0 );
E 13
	    putop( P2ASG P2PLUS , P2INT );
E 18
I 18
	    putRV( PCPCOUNT , 0 , counter * sizeof (long) , NGLOBAL , PCCT_INT );
	    putleaf( PCC_ICON , 1 , 0 , PCCT_INT , (char *) 0 );
	    putop( PCCOM_ASG PCC_PLUS , PCCT_INT );
E 18
	    putdot( filename , line );
#	endif PC
    }

putline()
{

#	ifdef OBJ
	    if (opt('p') != 0)
D 3
		    put2(O_LINO, line);
E 3
I 3
D 13
		    put(2, O_LINO, line);
E 13
I 13
		    (void) put(2, O_LINO, line);
E 13
I 6

	    /*
	     * put out line number information for pdx
	     */
	    lineno(line);

E 6
E 3
#	endif OBJ
#	ifdef PC
	    static lastline;

	    if ( line != lastline ) {
		stabline( line );
		lastline = line;
	    }
	    if ( opt( 'p' ) ) {
		if ( opt('t') ) {
D 18
		    putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
E 18
I 18
		    putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 18
			    , "_LINO" );
D 18
		    putop( P2UNARY P2CALL , P2INT );
E 18
I 18
		    putop( PCCOM_UNARY PCC_CALL , PCCT_INT );
E 18
		    putdot( filename , line );
		} else {
D 5
		    putRV( STMTCOUNT , 0 , 0 , P2INT );
E 5
I 5
D 18
		    putRV( STMTCOUNT , 0 , 0 , NGLOBAL , P2INT );
E 5
D 13
		    putleaf( P2ICON , 1 , 0 , P2INT , 0 );
E 13
I 13
		    putleaf( P2ICON , 1 , 0 , P2INT , (char *) 0 );
E 13
		    putop( P2ASG P2PLUS , P2INT );
E 18
I 18
		    putRV( STMTCOUNT , 0 , 0 , NGLOBAL , PCCT_INT );
		    putleaf( PCC_ICON , 1 , 0 , PCCT_INT , (char *) 0 );
		    putop( PCCOM_ASG PCC_PLUS , PCCT_INT );
E 18
		    putdot( filename , line );
		}
	    }
#	endif PC
}

/*
 * With varlist do stat
 *
 * With statement requires an extra word
 * in automatic storage for each level of withing.
 * These indirect pointers are initialized here, and
 * the scoping effect of the with statement occurs
 * because lookup examines the field names of the records
 * associated with the WITHPTRs on the withlist.
 */
withop(s)
D 13
	int *s;
E 13
I 13
	WITH_NODE *s;
E 13
{
D 13
	register *p;
E 13
I 13
	register struct tnode *p;
E 13
	register struct nl *r;
D 5
	int i;
E 5
I 5
	struct nl	*tempnlp;
E 5
D 13
	int *swl;
E 13
I 13
	struct nl *swl;
E 13
D 4
	long soffset;
E 4

	putline();
	swl = withlist;
D 4
	soffset = sizes[cbn].om_off;
E 4
D 13
	for (p = s[2]; p != NIL; p = p[2]) {
D 4
		i = sizes[cbn].om_off -= sizeof ( int * );
		if (sizes[cbn].om_off < sizes[cbn].om_max)
			sizes[cbn].om_max = sizes[cbn].om_off;
E 4
I 4
D 5
		i = tmpalloc(sizeof(int *), INT_TYP, REGOK);
E 5
I 5
D 12
		tempnlp = tmpalloc(sizeof(int *), INT_TYP, REGOK);
E 13
I 13
	for (p = s->var_list; p != TR_NIL; p = p->list_node.next) {
D 14
		tempnlp = tmpalloc((long) (sizeof(int *)), INT_TYP, REGOK);
E 14
I 14
		tempnlp = tmpalloc((long) (sizeof(int *)), nl+TPTR, REGOK);
E 14
E 13
E 12
I 12
		    /*
		     *	no one uses the allocated temporary namelist entry,
		     *	since we have to use it before we know its type;
		     *	but we use its runtime location for the with pointer.
		     */
D 14
		tempnlp = tmpalloc(sizeof(int *), nl + TPTR, REGOK);
E 14
E 12
E 5
E 4
#		ifdef OBJ
D 3
		    put2(O_LV | cbn <<8+INDX, i );
E 3
I 3
D 5
		    put(2, O_LV | cbn <<8+INDX, i );
E 5
I 5
D 13
		    put(2, O_LV | cbn <<8+INDX, tempnlp -> value[ NL_OFFS ] );
E 13
I 13
		    (void) put(2, O_LV | cbn <<8+INDX, tempnlp -> value[ NL_OFFS ] );
E 13
E 5
E 3
#		endif OBJ
#		ifdef PC
D 4
		    putlbracket( ftnno , -sizes[cbn].om_off );
E 4
D 5
		    putRV( 0 , cbn , i , P2PTR|P2STRTY );
E 5
I 5
D 13
		    putRV( 0 , cbn , tempnlp -> value[ NL_OFFS ] ,
E 13
I 13
		    putRV( (char *) 0 , cbn , tempnlp -> value[ NL_OFFS ] ,
E 13
D 18
			    tempnlp -> extra_flags , P2PTR|P2STRTY );
E 18
I 18
			    tempnlp -> extra_flags , PCCTM_PTR|PCCT_STRTY );
E 18
E 5
#		endif PC
D 13
		r = lvalue(p[1], MOD , LREQ );
		if (r == NIL)
E 13
I 13
		r = lvalue(p->list_node.list, MOD , LREQ );
		if (r == NLNIL)
E 13
			continue;
		if (r->class != RECORD) {
			error("Variable in with statement refers to %s, not to a record", nameof(r));
			continue;
		}
D 5
		r = defnl(0, WITHPTR, r, i);
E 5
I 5
D 13
		r = defnl(0, WITHPTR, r, tempnlp -> value[ NL_OFFS ] );
E 13
I 13
		r = defnl((char *) 0, WITHPTR, r, tempnlp -> value[ NL_OFFS ] );
E 13
#		ifdef PC
		    r -> extra_flags |= tempnlp -> extra_flags;
#		endif PC
E 5
		r->nl_next = withlist;
		withlist = r;
#		ifdef OBJ
D 13
		    put(1, PTR_AS);
E 13
I 13
		    (void) put(1, PTR_AS);
E 13
#		endif OBJ
#		ifdef PC
D 18
		    putop( P2ASSIGN , P2PTR|P2STRTY );
E 18
I 18
		    putop( PCC_ASSIGN , PCCTM_PTR|PCCT_STRTY );
E 18
		    putdot( filename , line );
#		endif PC
	}
D 13
	statement(s[3]);
E 13
I 13
	statement(s->stmnt);
E 13
D 4
	sizes[cbn].om_off = soffset;
#	ifdef PC
	    putlbracket( ftnno , -sizes[cbn].om_off );
#	endif PC
E 4
	withlist = swl;
}

extern	flagwas;
/*
 * var := expr
 */
asgnop(r)
D 13
	int *r;
E 13
I 13
	ASG_NODE *r;
E 13
{
	register struct nl *p;
D 13
	register *av;
E 13
I 13
	register struct tnode *av;
E 13

D 13
	if (r == NIL)
		return (NIL);
E 13
	/*
	 * Asgnop's only function is
	 * to handle function variable
	 * assignments.  All other assignment
	 * stuff is handled by asgnop1.
	 * the if below checks for unqualified lefthandside:
	 * necessary for fvars.
	 */
D 13
	av = r[2];
	if (av != NIL && av[0] == T_VAR && av[3] == NIL) {
		p = lookup1(av[2]);
		if (p != NIL)
E 13
I 13
	av = r->lhs_var;
	if (av != TR_NIL && av->tag == T_VAR && av->var_node.qual == TR_NIL) {
		p = lookup1(av->var_node.cptr);
		if (p != NLNIL)
E 13
			p->nl_flags = flagwas;
D 13
		if (p != NIL && p->class == FVAR) {
E 13
I 13
		if (p != NLNIL && p->class == FVAR) {
E 13
			/*
			 * Give asgnop1 the func
			 * which is the chain of
			 * the FVAR.
			 */
			p->nl_flags |= NUSED|NMOD;
			p = p->chain;
D 13
			if (p == NIL) {
				rvalue(r[3], NIL , RREQ );
E 13
I 13
			if (p == NLNIL) {
				p = rvalue(r->rhs_expr, NLNIL , RREQ );
E 13
				return;
			}
#			ifdef OBJ
D 3
			    put2(O_LV | bn << 8+INDX, p->value[NL_OFFS]);
E 3
I 3
D 13
			    put(2, O_LV | bn << 8+INDX, (int)p->value[NL_OFFS]);
E 13
I 13
			    (void) put(2, O_LV | bn << 8+INDX, (int)p->value[NL_OFFS]);
E 13
E 3
			    if (isa(p->type, "i") && width(p->type) == 1)
D 13
				    asgnop1(r, nl+T2INT);
E 13
I 13
				    (void) asgnop1(r, nl+T2INT);
E 13
			    else
D 13
				    asgnop1(r, p->type);
E 13
I 13
				    (void) asgnop1(r, p->type);
E 13
#			endif OBJ
#			ifdef PC
				/*
				 * this should be the lvalue of the fvar,
				 * but since the second pass knows to use
				 * the address of the left operand of an
				 * assignment, what i want here is an rvalue.
				 * see note in funchdr about fvar allocation.
				 */
			    p = p -> ptr[ NL_FVAR ];
D 5
			    putRV( p -> symbol , bn , p -> value[ NL_OFFS ]
					, p2type( p -> type ) );
E 5
I 5
			    putRV( p -> symbol , bn , p -> value[ NL_OFFS ] ,
				    p -> extra_flags , p2type( p -> type ) );
E 5
D 13
			    asgnop1( r , p -> type );
E 13
I 13
			    (void) asgnop1( r , p -> type );
E 13
#			endif PC
			return;
		}
	}
D 13
	asgnop1(r, NIL);
E 13
I 13
	(void) asgnop1(r, NLNIL);
E 13
}

/*
 * Asgnop1 handles all assignments.
 * If p is not nil then we are assigning
 * to a function variable, otherwise
 * we look the variable up ourselves.
 */
struct nl *
asgnop1(r, p)
D 13
	int *r;
E 13
I 13
	ASG_NODE *r;
E 13
	register struct nl *p;
{
	register struct nl *p1;
I 16
	int	clas;
E 16
I 13
#ifdef OBJ
E 13
I 3
	int w;
I 13
D 16
#endif
E 16
I 16
#endif OBJ
E 16
E 13
E 3

I 16
#ifdef OBJ
E 16
D 13
	if (r == NIL)
		return (NIL);
	if (p == NIL) {
E 13
I 13
	if (p == NLNIL) {
E 13
D 16
#	    ifdef OBJ
D 13
		p = lvalue(r[2], MOD|ASGN|NOUSE , LREQ );
E 13
I 13
		p = lvalue(r->lhs_var, MOD|ASGN|NOUSE , LREQ );
E 13
I 3
		w = width(p);
E 3
#	    endif OBJ
#	    ifdef PC
I 15
		/* check for conformant array type */
		codeoff();
		p = rvalue(r->lhs_var, MOD|ASGN|NOUSE, LREQ);
		codeon();
		if ((classify(p) == TARY || classify(p) == TSTR)
		    && p->chain->class == CRANGE) {
		    putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR)
			    , "_blkcpy" );
		    /* find total size */
		    /* upper bound */
		    p1 = p->chain->nptr[1];
		    putRV(p1->symbol, (p1->nl_block & 037), p1->value[0],
			p1->extra_flags, p2type( p1 ) );
		    /* minus lower bound */
		    p1 = p->chain->nptr[0];
		    putRV(p1->symbol, (p1->nl_block & 037), p1->value[0],
			p1->extra_flags, p2type( p1 ) );
		    putop( P2MINUS, P2INT );
		    /* add one */
		    putleaf(P2ICON, 1, 0, P2INT, 0);
		    putop( P2PLUS, P2INT );
		    /* and multiply by the width */
		    p1 = p->chain->nptr[2];
		    putRV(p1->symbol, (p1->nl_block & 037), p1->value[0],
			p1->extra_flags, p2type( p1 ) );
		    putop( P2MUL , P2INT );
		    p = lvalue( r->lhs_var , MOD|ASGN|NOUSE , RREQ );
		    putop(P2LISTOP, P2INT);
		} else {
E 15
		    /*
		     * since the second pass knows that it should reference
		     * the lefthandside of asignments, what i need here is
		     * an rvalue.
		     */
D 13
		p = lvalue( r[2] , MOD|ASGN|NOUSE , RREQ );
E 13
I 13
D 15
		p = lvalue( r->lhs_var , MOD|ASGN|NOUSE , RREQ );
E 15
I 15
		    p = lvalue( r->lhs_var , MOD|ASGN|NOUSE , RREQ );
		}
E 15
E 13
#	    endif PC
E 16
I 16
	    p = lvalue(r->lhs_var, MOD|ASGN|NOUSE , LREQ );
E 16
D 13
	    if ( p == NIL ) {
		rvalue( r[3] , NIL , RREQ );
		return NIL;
E 13
I 13
	    if ( p == NLNIL ) {
		(void) rvalue( r->rhs_expr , NLNIL , RREQ );
		return NLNIL;
E 13
	    }
D 16
	}
#	ifdef OBJ
E 16
I 16
	    w = width(p);
	} else {
E 16
I 3
	    /*
	     * assigning to the return value, which is at least
	     * of width two since it resides on the stack
	     */
D 16
	    else {
		w = width(p);
		if (w < 2)
		    w = 2;
E 16
I 16
	    w = width(p);
	    if (w < 2)
		w = 2;
	}
	clas = classify(p);
	if ((clas == TARY || clas == TSTR) && p->chain->class == CRANGE) {
	    p1 = lvalue(r->rhs_expr, p , LREQ ); /* SHOULD THIS BE rvalue? */
	} else {
	    p1 = rvalue(r->rhs_expr, p , RREQ );
	}
#   endif OBJ
#   ifdef PC
	if (p == NLNIL) {
	    /* check for conformant array type */
	    codeoff();
	    p = rvalue(r->lhs_var, MOD|ASGN|NOUSE, LREQ);
	    codeon();
	    if (p == NLNIL) {
		(void) rvalue(r->rhs_expr, NLNIL, RREQ);
		return NLNIL;
E 16
	    }
E 3
D 13
	    p1 = rvalue(r[3], p , RREQ );
E 13
I 13
D 15
	    p1 = rvalue(r->rhs_expr, p , RREQ );
E 15
I 15
D 16
	    if ((classify(p) == TARY || classify(p) == TSTR)
		&& p->chain->class == CRANGE) {
		p1 = lvalue(r->rhs_expr, p , LREQ );
E 16
I 16
	    clas = classify(p);
	    if ((clas == TARY || clas == TSTR) && p->chain->class == CRANGE) {
		return pcasgconf(r, p);
E 16
	    } else {
D 16
		p1 = rvalue(r->rhs_expr, p , RREQ );
	    }
E 15
E 13
#	endif OBJ
#	ifdef PC
E 16
		/*
D 16
		 *	if this is a scalar assignment,
		 *	    then i want to rvalue the righthandside.
		 *	if this is a structure assignment,
		 *	    then i want an lvalue to the righthandside.
		 *  that's what the intermediate form sez.
E 16
I 16
		 * since the second pass knows that it should reference
		 * the lefthandside of asignments, what i need here is
		 * an rvalue.
E 16
		 */
D 16
	    switch ( classify( p ) ) {
		case TINT:
		case TCHAR:
		case TBOOL:
		case TSCAL:
		    precheck( p , "_RANG4" , "_RSNG4" );
		case TDOUBLE:
		case TPTR:
D 13
		    p1 = rvalue( r[3] , p , RREQ );
E 13
I 13
		    p1 = rvalue( r->rhs_expr , p , RREQ );
E 13
		    break;
		default:
D 13
		    p1 = rvalue( r[3] , p , LREQ );
E 13
I 13
		    p1 = rvalue( r->rhs_expr , p , LREQ );
E 13
		    break;
E 16
I 16
		p = lvalue( r->lhs_var , MOD|ASGN|NOUSE , RREQ );
E 16
	    }
I 16
	    if ( p == NLNIL ) {
		(void) rvalue( r->rhs_expr , NLNIL , RREQ );
		return NLNIL;
	    }
	}
	    /*
	     *	if this is a scalar assignment,
	     *	    then i want to rvalue the righthandside.
	     *	if this is a structure assignment,
	     *	    then i want an lvalue to the righthandside.
	     *  that's what the intermediate form sez.
	     */
	switch ( classify( p ) ) {
	    case TINT:
	    case TCHAR:
	    case TBOOL:
	    case TSCAL:
		precheck( p , "_RANG4" , "_RSNG4" );
		/* and fall through */
	    case TDOUBLE:
	    case TPTR:
		p1 = rvalue( r->rhs_expr , p , RREQ );
		break;
	    default:
		p1 = rvalue( r->rhs_expr , p , LREQ );
		break;
	}
E 16
#	endif PC
D 13
	if (p1 == NIL)
		return (NIL);
	if (incompat(p1, p, r[3])) {
E 13
I 13
	if (p1 == NLNIL)
		return (NLNIL);
	if (incompat(p1, p, r->rhs_expr)) {
E 13
		cerror("Type of expression clashed with type of variable in assignment");
D 13
		return (NIL);
E 13
I 13
		return (NLNIL);
E 13
	}
D 8
	switch (classify(p)) {
		case TINT:
		case TBOOL:
		case TCHAR:
		case TSCAL:
#			ifdef OBJ
E 8
I 8
#	ifdef OBJ
	    switch (classify(p)) {
		    case TINT:
		    case TBOOL:
		    case TCHAR:
		    case TSCAL:
E 8
			    rangechk(p, p1);
D 8
#			endif OBJ
#			ifdef PC
			    postcheck( p );
#			endif PC
		case TDOUBLE:
		case TPTR:
#			ifdef OBJ
E 8
D 3
			    gen(O_AS2, O_AS2, width(p), width(p1));
E 3
I 3
D 13
			    gen(O_AS2, O_AS2, w, width(p1));
E 13
I 13
			    (void) gen(O_AS2, O_AS2, w, width(p1));
E 13
E 3
D 8
#			endif OBJ
#			ifdef PC
E 8
I 8
			    break;
		    case TDOUBLE:
		    case TPTR:
D 13
			    gen(O_AS2, O_AS2, w, width(p1));
E 13
I 13
			    (void) gen(O_AS2, O_AS2, w, width(p1));
E 13
			    break;
I 15
		    case TARY:
		    case TSTR:
			    if (p->chain->class == CRANGE) {
				/* conformant array assignment */
				p1 = p->chain;
				w = width(p1->type);
				putcbnds(p1, 1);
				putcbnds(p1, 0);
				gen(NIL, T_SUB, w, w);
				put(2, w > 2? O_CON24: O_CON2, 1);
				gen(NIL, T_ADD, w, w);
				putcbnds(p1, 2);
				gen(NIL, T_MULT, w, w);
				put(1, O_VAS);
				break;
			    }
			    /* else fall through */
E 15
		    default:
D 13
			    put(2, O_AS, w);
E 13
I 13
			    (void) put(2, O_AS, w);
E 13
			    break;
	    }
#	endif OBJ
#	ifdef PC
	    switch (classify(p)) {
		    case TINT:
		    case TBOOL:
		    case TCHAR:
		    case TSCAL:
D 9
			    postcheck( p );
E 9
I 9
			    postcheck(p, p1);
			    sconv(p2type(p1), p2type(p));
E 9
E 8
D 18
			    putop( P2ASSIGN , p2type( p ) );
E 18
I 18
			    putop( PCC_ASSIGN , p2type( p ) );
E 18
			    putdot( filename , line );
D 8
#			endif PC
			break;
		default:
#			ifdef OBJ
D 3
			    put2(O_AS, width(p));
E 3
I 3
			    put(2, O_AS, w);
E 3
#			endif OBJ
#			ifdef PC
E 8
I 8
			    break;
		    case TPTR:
D 18
			    putop( P2ASSIGN , p2type( p ) );
E 18
I 18
			    putop( PCC_ASSIGN , p2type( p ) );
E 18
			    putdot( filename , line );
			    break;
		    case TDOUBLE:
D 9
			    if (isnta(p1,"d")) {
				putop( P2SCONV , P2DOUBLE );
			    }
E 9
I 9
			    sconv(p2type(p1), p2type(p));
E 9
D 18
			    putop( P2ASSIGN , p2type( p ) );
E 18
I 18
			    putop( PCC_ASSIGN , p2type( p ) );
E 18
			    putdot( filename , line );
			    break;
I 15
D 16
		    case TARY:
		    case TSTR:
			    /* handle conformant array assignment with
			     * library call.
			     */
			    if (p->chain->class == CRANGE) {
				putop(P2LISTOP, P2INT);
				putop(P2CALL, P2INT);
				putdot( filename , line);
				break;
			    }
			    /* else fall through */
E 16
E 15
		    default:
E 8
D 11
			    putstrop( P2STASG , p2type( p )
					, lwidth( p ) , align( p ) );
E 11
I 11
D 18
			    putstrop(P2STASG, ADDTYPE(p2type(p), P2PTR),
E 18
I 18
			    putstrop(PCC_STASG, PCCM_ADDTYPE(p2type(p), PCCTM_PTR),
E 18
D 13
					lwidth(p), align(p));
E 13
I 13
					(int) lwidth(p), align(p));
E 13
E 11
			    putdot( filename , line );
D 8
#			endif PC
	}
E 8
I 8
			    break;
	    }
#	endif PC
E 8
	return (p);	/* Used by for statement */
}
I 16

#ifdef PC
/*
 * assignment to conformant arrays.  Since these are variable length,
 *	we use blkcpy() to perform the assignment.
 *	blkcpy(rhs, lhs, (upper - lower + 1) * width)
 */
struct nl *
pcasgconf(r, p)
	register ASG_NODE *r;
	struct nl *p;
{
	struct nl *p1;

	if (r == (ASG_NODE *) TR_NIL || p == NLNIL)
		return NLNIL;
D 18
	putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR) , "_blkcpy" );
E 18
I 18
	putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR) , "_blkcpy" );
E 18
	p1 = rvalue( r->rhs_expr , p , LREQ );
	if (p1 == NLNIL)
		return NLNIL;
	p = lvalue( r->lhs_var , MOD|ASGN|NOUSE , LREQ );
	if (p == NLNIL)
		return NLNIL;
D 18
	putop(P2LISTOP, P2INT);
E 18
I 18
	putop(PCC_CM, PCCT_INT);
E 18
		/* upper bound */
	p1 = p->chain->nptr[1];
	putRV(p1->symbol, (p1->nl_block & 037), p1->value[0],
	    p1->extra_flags, p2type( p1 ) );
		/* minus lower bound */
	p1 = p->chain->nptr[0];
	putRV(p1->symbol, (p1->nl_block & 037), p1->value[0],
	    p1->extra_flags, p2type( p1 ) );
D 18
	putop( P2MINUS, P2INT );
E 18
I 18
	putop( PCC_MINUS, PCCT_INT );
E 18
		/* add one */
D 18
	putleaf(P2ICON, 1, 0, P2INT, 0);
	putop( P2PLUS, P2INT );
E 18
I 18
	putleaf(PCC_ICON, 1, 0, PCCT_INT, 0);
	putop( PCC_PLUS, PCCT_INT );
E 18
		/* and multiply by the width */
	p1 = p->chain->nptr[2];
	putRV(p1->symbol, (p1->nl_block & 037), p1->value[0],
	    p1->extra_flags, p2type( p1 ) );
D 18
	putop( P2MUL , P2INT );
	putop(P2LISTOP, P2INT);
	putop(P2CALL, P2INT);
E 18
I 18
	putop( PCC_MUL , PCCT_INT );
	putop(PCC_CM, PCCT_INT);
	putop(PCC_CALL, PCCT_INT);
E 18
	putdot( filename , line);
	return p;
}
#endif PC
E 16
D 2

#ifdef OBJ
/*
 * for var := expr [down]to expr do stat
 */
forop(r)
	int *r;
{
	register struct nl *t1, *t2;
	int l1, l2, l3;
	long soffset;
	register op;
	struct nl *p;
	int *rr, goc, i;

	p = NIL;
	goc = gocnt;
	if (r == NIL)
		goto aloha;
	putline();
	/*
	 * Start with assignment
	 * of initial value to for variable
	 */
	t1 = asgnop1(r[2], NIL);
	if (t1 == NIL) {
		rvalue(r[3], NIL , RREQ );
		statement(r[4]);
		goto aloha;
	}
	rr = r[2];		/* Assignment */
	rr = rr[2];		/* Lhs variable */
	if (rr[3] != NIL) {
		error("For variable must be unqualified");
		rvalue(r[3], NIL , RREQ );
		statement(r[4]);
		goto aloha;
	}
	p = lookup(rr[2]);
	p->value[NL_FORV] = 1;
	if (isnta(t1, "bcis")) {
		error("For variables cannot be %ss", nameof(t1));
		statement(r[4]);
		goto aloha;
	}
	/*
	 * Allocate automatic
	 * space for limit variable
	 */
	sizes[cbn].om_off -= 4;
	if (sizes[cbn].om_off < sizes[cbn].om_max)
		sizes[cbn].om_max = sizes[cbn].om_off;
	i = sizes[cbn].om_off;
	/*
	 * Initialize the limit variable
	 */
	put2(O_LV | cbn<<8+INDX, i);
	t2 = rvalue(r[3], NIL , RREQ );
	if (incompat(t2, t1, r[3])) {
		cerror("Limit type clashed with index type in 'for' statement");
		statement(r[4]);
		goto aloha;
	}
	put1(width(t2) <= 2 ? O_AS24 : O_AS4);
	/*
	 * See if we can skip the loop altogether
	 */
	rr = r[2];
	if (rr != NIL)
		rvalue(rr[2], NIL , RREQ );
	put2(O_RV4 | cbn<<8+INDX, i);
	gen(NIL, r[0] == T_FORU ? T_LE : T_GE, width(t1), 4);
	/*
	 * L1 will be patched to skip the body of the loop.
	 * L2 marks the top of the loop when we go around.
	 */
	put2(O_IF, (l1 = getlab()));
	putlab(l2 = getlab());
	putcnt();
	statement(r[4]);
	/*
	 * now we see if we get to go again
	 */
	if (opt('t') == 0) {
		/*
		 * Easy if we dont have to test
		 */
		put2(O_RV4 | cbn<<8+INDX, i);
		if (rr != NIL)
			lvalue(rr[2], MOD , RREQ );
		put2((r[0] == T_FORU ? O_FOR1U : O_FOR1D) + (width(t1) >> 1), l2);
	} else {
		line = r[1];
		putline();
		if (rr != NIL)
			rvalue(rr[2], NIL , RREQ );
		put2(O_RV4 | cbn << 8+INDX, i);
		gen(NIL, (r[0] == T_FORU ? T_LT : T_GT), width(t1), 4);
		l3 = put2(O_IF, getlab());
		lvalue((int *) rr[2], MOD , RREQ );
		rvalue(rr[2], NIL , RREQ );
		put2(O_CON2, 1);
		t2 = gen(NIL, r[0] == T_FORU ? T_ADD: T_SUB, width(t1), 2);
		rangechk(t1, t2);	/* The point of all this */
		gen(O_AS2, O_AS2, width(t1), width(t2));
		put2(O_TRA, l2);
		patch(l3);
	}
	sizes[cbn].om_off += 4;
	patch(l1);
aloha:
	noreach = 0;
	if (p != NIL)
		p->value[NL_FORV] = 0;
	if (goc != gocnt)
		putcnt();
}
#endif OBJ
E 2

/*
 * if expr then stat [ else stat ]
 */
D 13
ifop(r)
	int *r;
E 13
I 13
ifop(if_n)
	IF_NODE *if_n;
E 13
{
	register struct nl *p;
	register l1, l2;	/* l1 is start of else, l2 is end of else */
D 3
	int nr, goc;
E 3
I 3
	int goc;
	bool nr;
E 3

	goc = gocnt;
D 13
	if (r == NIL)
		return;
E 13
	putline();
D 13
	p = rvalue(r[2], NIL , RREQ );
E 13
I 13
	p = rvalue(if_n->cond_expr, NLNIL , RREQ );
E 13
	if (p == NIL) {
D 13
		statement(r[3]);
		noreach = 0;
		statement(r[4]);
		noreach = 0;
E 13
I 13
		statement(if_n->then_stmnt);
		noreach = FALSE;
		statement(if_n->else_stmnt);
		noreach = FALSE;
E 13
		return;
	}
	if (isnta(p, "b")) {
		error("Type of expression in if statement must be Boolean, not %s", nameof(p));
D 13
		statement(r[3]);
		noreach = 0;
		statement(r[4]);
		noreach = 0;
E 13
I 13
		statement(if_n->then_stmnt);
		noreach = FALSE;
		statement(if_n->else_stmnt);
		noreach = FALSE;
E 13
		return;
	}
#	ifdef OBJ
D 3
	    l1 = put2(O_IF, getlab());
E 3
I 3
	    l1 = put(2, O_IF, getlab());
E 3
#	endif OBJ
#	ifdef PC
D 13
	    l1 = getlab();
	    putleaf( P2ICON , l1 , 0 , P2INT , 0 );
E 13
I 13
	    l1 = (int) getlab();
D 18
	    putleaf( P2ICON , l1 , 0 , P2INT , (char *) 0 );
E 13
	    putop( P2CBRANCH , P2INT );
E 18
I 18
	    putleaf( PCC_ICON , l1 , 0 , PCCT_INT , (char *) 0 );
	    putop( PCC_CBRANCH , PCCT_INT );
E 18
	    putdot( filename , line );
#	endif PC
	putcnt();
D 13
	statement(r[3]);
E 13
I 13
	statement(if_n->then_stmnt);
E 13
	nr = noreach;
D 13
	if (r[4] != NIL) {
E 13
I 13
	if (if_n->else_stmnt != TR_NIL) {
E 13
		/*
		 * else stat
		 */
		--level;
		ungoto();
		++level;
#		ifdef OBJ
D 3
		    l2 = put2(O_TRA, getlab());
E 3
I 3
		    l2 = put(2, O_TRA, getlab());
E 3
#		endif OBJ
#		ifdef PC
D 13
		    l2 = getlab();
		    putjbr( l2 );
E 13
I 13
		    l2 = (int) getlab();
		    putjbr( (long) l2 );
E 13
#		endif PC
D 13
		patch(l1);
		noreach = 0;
		statement(r[4]);
D 3
		noreach &= nr;
E 3
I 3
		noreach = (noreach && nr);
E 13
I 13
		patch((PTR_DCL)l1);
		noreach = FALSE;
		statement(if_n->else_stmnt);
		noreach = (noreach && nr)?TRUE:FALSE;
E 13
E 3
		l1 = l2;
	} else
D 13
		noreach = 0;
	patch(l1);
E 13
I 13
		noreach = FALSE;
	patch((PTR_DCL)l1);
E 13
	if (goc != gocnt)
		putcnt();
}

/*
 * while expr do stat
 */
D 13
whilop(r)
	int *r;
E 13
I 13
whilop(w_node)
	WHI_CAS *w_node;
E 13
{
	register struct nl *p;
D 13
	register l1, l2;
E 13
I 13
	register char *l1, *l2;
E 13
	int goc;

	goc = gocnt;
D 13
	if (r == NIL)
		return;
	putlab(l1 = getlab());
E 13
I 13
	l1 = getlab();
	(void) putlab(l1);
E 13
	putline();
D 13
	p = rvalue(r[2], NIL , RREQ );
	if (p == NIL) {
		statement(r[3]);
		noreach = 0;
E 13
I 13
	p = rvalue(w_node->expr, NLNIL , RREQ );
	if (p == NLNIL) {
		statement(w_node->stmnt_list);
		noreach = FALSE;
E 13
		return;
	}
	if (isnta(p, "b")) {
		error("Type of expression in while statement must be Boolean, not %s", nameof(p));
D 13
		statement(r[3]);
		noreach = 0;
E 13
I 13
		statement(w_node->stmnt_list);
		noreach = FALSE;
E 13
		return;
	}
	l2 = getlab();
#	ifdef OBJ
D 3
	    put2(O_IF, l2);
E 3
I 3
D 13
	    put(2, O_IF, l2);
E 13
I 13
	    (void) put(2, O_IF, l2);
E 13
E 3
#	endif OBJ
#	ifdef PC
D 13
	    putleaf( P2ICON , l2 , 0 , P2INT , 0 );
E 13
I 13
D 18
	    putleaf( P2ICON , (int) l2 , 0 , P2INT , (char *) 0 );
E 13
	    putop( P2CBRANCH , P2INT );
E 18
I 18
	    putleaf( PCC_ICON , (int) l2 , 0 , PCCT_INT , (char *) 0 );
	    putop( PCC_CBRANCH , PCCT_INT );
E 18
	    putdot( filename , line );
#	endif PC
	putcnt();
D 13
	statement(r[3]);
E 13
I 13
	statement(w_node->stmnt_list);
E 13
#	ifdef OBJ
D 3
	    put2(O_TRA, l1);
E 3
I 3
D 13
	    put(2, O_TRA, l1);
E 13
I 13
	    (void) put(2, O_TRA, l1);
E 13
E 3
#	endif OBJ
#	ifdef PC
D 13
	    putjbr( l1 );
E 13
I 13
	    putjbr( (long) l1 );
E 13
#	endif PC
D 13
	patch(l2);
E 13
I 13
	patch((PTR_DCL) l2);
E 13
	if (goc != gocnt)
		putcnt();
}

/*
 * repeat stat* until expr
 */
repop(r)
D 13
	int *r;
E 13
I 13
	REPEAT *r;
E 13
{
	register struct nl *p;
	register l;
	int goc;

	goc = gocnt;
D 13
	if (r == NIL)
		return;
	l = putlab(getlab());
E 13
I 13
	l = (int) putlab(getlab());
E 13
	putcnt();
D 13
	statlist(r[2]);
	line = r[1];
	p = rvalue(r[3], NIL , RREQ );
	if (p == NIL)
E 13
I 13
	statlist(r->stmnt_list);
	line = r->line_no;
	p = rvalue(r->term_expr, NLNIL , RREQ );
	if (p == NLNIL)
E 13
		return;
	if (isnta(p,"b")) {
		error("Until expression type must be Boolean, not %s, in repeat statement", nameof(p));
		return;
	}
#	ifdef OBJ
D 3
	    put2(O_IF, l);
E 3
I 3
D 13
	    put(2, O_IF, l);
E 13
I 13
	    (void) put(2, O_IF, l);
E 13
E 3
#	endif OBJ
#	ifdef PC
D 13
	    putleaf( P2ICON , l , 0 , P2INT , 0 );
E 13
I 13
D 18
	    putleaf( P2ICON , l , 0 , P2INT , (char *) 0 );
E 13
	    putop( P2CBRANCH , P2INT );
E 18
I 18
	    putleaf( PCC_ICON , l , 0 , PCCT_INT , (char *) 0 );
	    putop( PCC_CBRANCH , PCCT_INT );
E 18
	    putdot( filename , line );
#	endif PC
	if (goc != gocnt)
		putcnt();
D 7
}

/*
 * assert expr
 */
asrtop(r)
	register int *r;
{
	register struct nl *q;

	if (opt('s')) {
		standard();
		error("Assert statement is non-standard");
	}
	if (!opt('t'))
		return;
	r = r[2];
#	ifdef OBJ
	    q = rvalue((int *) r, NLNIL , RREQ );
#	endif OBJ
#	ifdef PC
	    putleaf( P2ICON , 0 , 0
		    , ADDTYPE( P2FTN | P2INT , P2PTR ) , "_ASRT" );
	    q = stkrval( r , NLNIL , RREQ );
#	endif PC
	if (q == NIL)
		return;
	if (isnta(q, "b"))
		error("Assert expression must be Boolean, not %ss", nameof(q));
#	ifdef OBJ
D 3
	    put1(O_ASRT);
E 3
I 3
	    put(1, O_ASRT);
E 3
#	endif OBJ
#	ifdef PC
	    putop( P2CALL , P2INT );
	    putdot( filename , line );
#	endif PC
E 7
}
E 1
