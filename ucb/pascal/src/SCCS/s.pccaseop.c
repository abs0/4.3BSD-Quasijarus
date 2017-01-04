h50347
s 00042/00010/00445
d D 5.2 86/11/12 10:17:11 mckusick 23 22
c add CCI (tahoe) support
e
s 00008/00003/00447
d D 5.1 85/06/05 14:39:20 dist 22 21
c Add copyright
e
s 00009/00009/00441
d D 2.3 85/03/20 15:03:01 ralph 21 20
c changes from donn@utah-cs for common header file for pcc
e
s 00002/00002/00448
d D 2.2 84/11/26 17:53:25 mckusick 20 19
c use UNIX syntax, not VAX syntax (from chris@maryland)
e
s 00000/00000/00450
d D 2.1 84/02/08 20:46:59 aoki 19 18
c synchronize to version 2
e
s 00000/00000/00450
d D 1.14 84/02/04 20:05:54 mckusick 18 16
i 17
c merge lint by thien
e
s 00091/00083/00359
d D 1.12.1.1 84/02/04 20:02:26 mckusick 17 15
c lint (by thien)
e
s 00001/00001/00441
d D 1.13 83/10/13 17:31:48 harrison 16 15
c format error raised havoc with binary searched cases
e
s 00073/00021/00369
d D 1.12 83/06/10 17:00:44 mckusick 15 13
c when -J flag specified, generate long displacement jump tables
e
s 00073/00021/00369
d R 1.12 83/06/10 16:57:43 mckusick 14 13
c when -J flag specified, generate long displacement jump tables
e
s 00001/00000/00389
d D 1.11 83/02/28 17:16:46 peter 13 12
c clean up temporary allocation, moving everything relevant to
c tmps.c and (new) tmps.h.  correctly emit LBRAC lines.  allocate registers
c from high to low.  put in data structures for multiple types of registers.
e
s 00000/00000/00389
d D 1.10 83/01/17 14:23:21 peter 12 9
i 11 10
c merge 1.9 and 1.8.1.
e
s 00064/00015/00324
d D 1.8.1.2 83/01/17 14:21:49 peter 11 10
c port to the mc68000.
e
s 00000/00000/00339
d D 1.8.1.1 83/01/17 14:20:57 peter 10 8
c branch-place-holder
e
s 00001/00000/00339
d D 1.9 83/01/17 14:04:44 peter 9 8
c put in explicit scalar converts (sconv's) to make less code-generator dependent.
e
s 00001/00003/00338
d D 1.8 82/02/02 15:52:45 mckusic 8 7
c convert ECASE to call on CASERNG
e
s 00006/00004/00335
d D 1.7 81/06/01 15:37:59 peter 7 6
c add storage classes to namelist, and use them.
e
s 00011/00004/00328
d D 1.6 81/04/30 16:35:04 peter 6 5
c save expression in temporary for use in error message (for robert).
e
s 00001/00001/00331
d D 1.5 81/03/09 12:27:33 mckusic 5 4
c fix bool type errors
e
s 00008/00002/00324
d D 1.4 80/10/09 00:00:41 peter 4 3
c if duplicate labels, don't generate switch code.
e
s 00001/00001/00325
d D 1.3 80/09/29 18:34:47 peter 3 2
c since gtr is more likely than eql, check it first.
e
s 00283/00161/00043
d D 1.2 80/09/27 20:10:27 peter 2 1
c three different kinds of switches
e
s 00204/00000/00000
d D 1.1 80/08/27 19:55:35 peter 1 0
c date and time created 80/08/27 19:55:35 by peter
e
u
U
f b 
t
T
I 1
D 2
/* Copyright (c) 1979 Regents of the University of California */
E 2
I 2
D 22
/* Copyright (c) 1980 Regents of the University of California */
E 22
I 22
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 22
E 2

I 17
#ifndef lint
E 17
D 15
static	char sccsid[] = "%Z%%M% %I% %G%";
E 15
I 15
D 22
static char sccsid[] = "%Z%%M% %I% %G%";
I 17
#endif
E 22
I 22
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 22
E 17
E 15

#include "whoami.h"
#ifdef PC
    /*
     *	and the rest of the file
     */
#include "0.h"
#include "tree.h"
#include "objfmt.h"
D 21
#include "pcops.h"
E 21
I 21
#include <pcc.h>
E 21
#include "pc.h"
I 13
#include "tmps.h"
I 17
#include "tree_ty.h"
E 17
E 13
I 2

E 2
    /*
I 2
     *	structure for a case: 
     *	    its constant label, line number (for errors), and location label.
     */
struct ct {
    long	cconst;
    int		cline;
    int		clabel;
};

    /*
D 21
     *	the P2FORCE operator puts its operand into a register.
E 21
I 21
     *	the PCC_FORCE operator puts its operand into a register.
E 21
     *	these to keep from thinking of it as r0 all over.
     */
D 11
#define	FORCENAME	"r0"
E 11
I 11
D 23
#ifdef vax
E 23
I 23
#if defined(vax) || defined(tahoe)
E 23
#   define	FORCENAME	"r0"
D 23
#endif vax
E 23
I 23
#endif vax || tahoe
E 23
#ifdef mc68000
#   define	FORCENAME	"d0"
I 15
#   define	ADDRTEMP	"a0"
E 15
#endif mc68000
E 11
D 6
#define	FORCENUMBER	0
E 6

    /*
     *	given a tree for a case statement, generate code for it.
     *	this computes the expression into a register,
     *	puts down the code for each of the cases,
     *	and then decides how to do the case switching.
E 2
     *	tcase	[0]	T_CASE
     *		[1]	lineof "case"
     *		[2]	expression
D 2
     *		[3]	list of cased statements
E 2
I 2
     *		[3]	list of cased statements:
E 2
     *			cstat	[0]	T_CSTAT
     *				[1]	lineof ":"
D 2
     *				[2]	constant list
E 2
I 2
     *				[2]	list of constant labels
E 2
     *				[3]	statement
     */
D 2

struct ct {
    long	clong;
    int		cline;
};

E 2
pccaseop( tcase )
D 17
    int	*tcase;
E 17
I 17
    WHI_CAS *tcase;
E 17
D 2
    {
	struct nl	*exprtype;
	struct nl	*rangetype;
	long		low;
	long		high;
	long		exproff;
	long		exprctype;
	long		count;
	long		*cstatlp;
	long		*cstatp;
	struct ct	*ctab;
	long		endlabel;
	long		nextlabel;
	long		firsttime;
	long		*casep;
	long		i;
	long		nr;
	long		goc;
E 2
I 2
{
    struct nl	*exprtype;
I 6
D 7
    int		exproff;
E 7
I 7
    struct nl	*exprnlp;
E 7
E 6
    struct nl	*rangetype;
    long	low;
    long	high;
    long	exprctype;
D 17
    long	swlabel;
    long	endlabel;
    long	label;
    long	count;
    long	*cstatlp;
    long	*cstatp;
    long	*casep;
E 17
I 17
    char 	*swlabel;
    char	*endlabel;
    char	*label;
    int		count;
    struct tnode *cstatlp;
    struct tnode *cstatp;
    struct tnode *casep;
E 17
    struct ct	*ctab;
    struct ct	*ctp;
D 17
    long	i;
    long	nr;
E 17
I 17
    bool	nr;
E 17
    long	goc;
    int		casecmp();
I 4
    bool	dupcases;
E 4
E 2

D 2
	goc = gocnt;
	    /*
	     *	find out the type of the case expression
	     */
	line = tcase[1];
	codeoff();
	exprtype = rvalue( (int *) tcase[2] , NIL  , RREQ );
	codeon();
	if ( exprtype != NIL ) {
	    if ( isnta( exprtype , "bcsi" ) ) {
		error("Case selectors cannot be %ss" , nameof( exprtype ) );
E 2
I 2
    goc = gocnt;
	/*
	 *  find out the type of the case expression
	 *  even if the expression has errors (exprtype == NIL), continue.
	 */
D 17
    line = tcase[1];
E 17
I 17
    line = tcase->line_no;
E 17
I 6
    codeoff();
E 6
D 17
    exprtype = rvalue( (int *) tcase[2] , NIL  , RREQ );
E 17
I 17
    exprtype = rvalue( tcase->expr , NLNIL  , RREQ );
E 17
I 6
    codeon();
E 6
D 17
    if ( exprtype != NIL ) {
E 17
I 17
    if ( exprtype != NLNIL ) {
E 17
	if ( isnta( exprtype , "bcsi" ) ) {
	    error("Case selectors cannot be %ss" , nameof( exprtype ) );
D 17
	    exprtype = NIL;
E 17
I 17
	    exprtype = NLNIL;
E 17
	} else {
	    if ( exprtype -> class != RANGE ) {
		rangetype = exprtype -> type;
	    } else {
		rangetype = exprtype;
	    }
D 17
	    if ( rangetype == NIL ) {
E 2
		exprtype = NIL;
E 17
I 17
	    if ( rangetype == NLNIL ) {
		exprtype = NLNIL;
E 17
	    } else {
D 2
		if ( exprtype -> class != RANGE ) {
		    rangetype = exprtype -> type;
		} else {
		    rangetype = exprtype;
		}
		if ( rangetype == NIL ) {
		    exprtype = NIL;
		} else {
		    low = rangetype -> range[0];
		    high = rangetype -> range[1];
		}
E 2
I 2
		low = rangetype -> range[0];
		high = rangetype -> range[1];
E 2
	    }
	}
D 2
	if ( exprtype != NIL ) {
		/*
		 * allocate temporary for case expression
		 */
	    sizes[cbn].om_off -= sizeof( long );
	    exproff = sizes[cbn].om_off;
	    putlbracket( ftnno , -sizes[cbn].om_off );
	    if ( sizes[cbn].om_off < sizes[cbn].om_max ) {
		sizes[cbn].om_max = sizes[cbn].om_off;
	    }
		/*
		 * compute and save the expression
		 */
	    exprctype = p2type( exprtype );
	    putRV( 0 , cbn , exproff , P2INT );
	    rvalue( (int *) tcase[2] , NIL  , RREQ );
	    putop( P2ASSIGN , exprctype );
	    putdot( filename , line );
	}
E 2
I 2
    }
D 17
    if ( exprtype != NIL ) {
E 17
I 17
    if ( exprtype != NLNIL ) {
E 17
E 2
	    /*
D 2
	     *	count the number of cases
	     *	and allocate table for cases and lines
E 2
I 2
D 6
	     *	put expression into a register
E 6
I 6
	     *	compute and save the case expression.
	     *	also, put expression into a register
E 6
	     *	save its c-type and jump to the code to do the switch.
E 2
	     */
I 6
	exprctype = p2type( exprtype );
D 7
	exproff = tmpalloc( sizeof (long) , nl + T4INT , NOREG );
	putRV( 0 , cbn , exproff , P2INT );
E 7
I 7
D 17
	exprnlp = tmpalloc( sizeof (long) , nl + T4INT , NOREG );
	putRV( 0 , cbn , exprnlp -> value[ NL_OFFS ] ,
E 17
I 17
	exprnlp = tmpalloc( (long) (sizeof (long)), nl + T4INT , NOREG );
	putRV((char *) 0 , cbn , exprnlp -> value[ NL_OFFS ] ,
E 17
D 21
			exprnlp -> extra_flags , P2INT );
E 21
I 21
			exprnlp -> extra_flags , PCCT_INT );
E 21
E 7
D 17
	(void) rvalue( (int *) tcase[2] , NIL , RREQ );
I 9
	sconv(exprctype, P2INT);
E 17
I 17
	(void) rvalue( tcase->expr , NLNIL , RREQ );
D 21
	sconv((int) exprctype, (int) P2INT);
E 17
E 9
	putop( P2ASSIGN , P2INT );
E 6
D 2
	count = 0;
	for ( cstatlp = tcase[3] ; cstatlp != NIL ; cstatlp = cstatlp[2] ) {
	    cstatp = cstatlp[1];
	    if ( cstatp == NIL ) {
		continue;
	    }
	    for ( casep = cstatp[2] ; casep != NIL ; casep = casep[2] ) {
		count++;
	    }
E 2
I 2
	putop( P2FORCE , P2INT );
E 21
I 21
	sconv((int) exprctype, (int) PCCT_INT);
	putop( PCC_ASSIGN , PCCT_INT );
	putop( PCC_FORCE , PCCT_INT );
E 21
	putdot( filename , line );
D 6
	exprctype = p2type( exprtype );
E 6
	swlabel = getlab();
D 17
	putjbr( swlabel );
E 17
I 17
	putjbr( (long) swlabel );
E 17
    }
	/*
	 *  count the number of cases
	 *  and allocate table for cases, lines, and labels
	 *  default case goes in ctab[0].
	 */
    count = 1;
D 17
    for ( cstatlp = tcase[3] ; cstatlp != NIL ; cstatlp = cstatlp[2] ) {
	cstatp = cstatlp[1];
	if ( cstatp == NIL ) {
E 17
I 17
    for ( cstatlp = tcase->stmnt_list ; cstatlp != TR_NIL ;
		cstatlp = cstatlp->list_node.next ) {
	cstatp = cstatlp->list_node.list;
	if ( cstatp == TR_NIL ) {
E 17
	    continue;
E 2
	}
D 2
	ctab = (struct ct *) malloc( count * sizeof( struct ct ) );
	if ( ctab == (struct ct *) -1 ) {
	    error("Ran out of memory (case)");
	    pexit( DIED );
E 2
I 2
D 17
	for ( casep = cstatp[2] ; casep != NIL ; casep = casep[2] ) {
E 17
I 17
	for ( casep = cstatp->c_stmnt.const_list ; casep != TR_NIL ;
			casep = casep->list_node.next ) {
E 17
	    count++;
E 2
	}
D 2
	    /*
	     * generate code for each case
	     */
	endlabel = getlab();
	nextlabel = getlab();
	count = 0;
	nr = 1;
	for ( cstatlp = tcase[3] ; cstatlp != NIL ; cstatlp = cstatlp[2] ) {
	    cstatp = cstatlp[1];
	    if ( cstatp == NIL ) {
E 2
I 2
    }
	/*
	 */
    ctab = (struct ct *) malloc( count * sizeof( struct ct ) );
    if ( ctab == (struct ct *) 0 ) {
	error("Ran out of memory (case)");
	pexit( DIED );
    }
	/*
	 *  pick up default label and label for after case statement.
	 */
D 17
    ctab[0].clabel = getlab();
E 17
I 17
    ctab[0].clabel = (int) getlab();
E 17
    endlabel = getlab();
	/*
	 *  generate code for each case
	 *  filling in ctab for each.
	 *  nr is for error if no case falls out bottom.
	 */
D 17
    nr = 1;
E 17
I 17
    nr = TRUE;;
E 17
    count = 0;
D 17
    for ( cstatlp = tcase[3] ; cstatlp != NIL ; cstatlp = cstatlp[2] ) {
	cstatp = cstatlp[1];
	if ( cstatp == NIL ) {
E 17
I 17
    for ( cstatlp = tcase->stmnt_list ; cstatlp != TR_NIL ;
		cstatlp = cstatlp->list_node.next ) {
	cstatp = cstatlp->list_node.list;
	if ( cstatp == TR_NIL ) {
E 17
	    continue;
	}
D 17
	line = cstatp[1];
E 17
I 17
	line = cstatp->c_stmnt.line_no;
E 17
	label = getlab();
D 17
	for ( casep = cstatp[2] ; casep != NIL ; casep = casep[2] ) {
	    gconst( casep[1] );
	    if( exprtype == NIL || con.ctype == NIL ) {
E 17
I 17
	for ( casep = cstatp->c_stmnt.const_list ; casep != TR_NIL ;
			casep = casep->list_node.next ) {
	    gconst( casep->list_node.list );
	    if( exprtype == NLNIL || con.ctype == NIL ) {
E 17
E 2
		continue;
	    }
D 2
	    line = cstatp[1];
	    putlab( nextlabel );
	    nextlabel = getlab();
		/*
		 * if it's not any of these, then go to next
		 */
	    firsttime = 1;
	    for ( casep = cstatp[2] ; casep != NIL ; casep = casep[2] ) {
		gconst( casep[1] );
		if( exprtype == NIL || con.ctype == NIL ) {
		    continue;
		}
		if ( incompat( con.ctype , exprtype , NIL ) ) {
		    cerror("Case label type clashed with case selector expression type");
		    continue;
		}
		if ( con.crval < low || con.crval > high ) {
		    error("Case label out of range");
		    continue;
		}
		ctab[ count ].clong = con.crval;
		ctab[ count ].cline = line;
		    /*
		     *	check for duplicates
		     */
		for ( i = 0 ; i < count ; i++ ) {
		    if ( ctab[ i ].clong == con.crval ) {
			error("Multiply defined label in case, lines %d and %d"
				, ctab[ i ].cline , line );
		    }
		}
		putRV( 0 , cbn , exproff , exprctype , 0 );
		putleaf( P2ICON , ctab[ count ].clong , 0 , exprctype , 0 );
		putop( P2EQ , exprctype );
		if ( ! firsttime ) {
			/*
			 * note the use of !! to get short circuiting
			 */
		    putop( P2OROR , P2CHAR );
		}
		firsttime = 0;
E 2
I 2
D 17
	    if ( incompat( con.ctype , exprtype , NIL ) ) {
E 17
I 17
	    if ( incompat( con.ctype , exprtype , TR_NIL ) ) {
E 17
		cerror("Case label type clashed with case selector expression type");
		continue;
E 2
	    }
D 2
	    putleaf( P2ICON , nextlabel , 0 , P2INT , 0 );
	    putop( P2CBRANCH , P2INT );
	    putdot( filename , line );
		/*
		 * if we get here, we must be in this case
		 */
	    putcnt();
	    level++;
	    statement( cstatp[3] );
	    nr &= noreach;
	    noreach = 0;
	    putjbr( endlabel );
	    level--;
	    if (gotos[cbn]) {
		    ungoto();
E 2
I 2
	    if ( con.crval < low || con.crval > high ) {
		error("Case label out of range");
		continue;
E 2
	    }
I 2
	    count++;
	    ctab[ count ].cconst = con.crval;
	    ctab[ count ].cline = line;
D 17
	    ctab[ count ].clabel = label;
E 17
I 17
	    ctab[ count ].clabel = (int) label;
E 17
E 2
	}
	    /*
D 2
	     *	default action is to call error
E 2
I 2
	     *	put out the statement
E 2
	     */
D 2
	putlab( nextlabel );
	putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR ) , "_ERROR" );
	putleaf( P2ICON , ECASE , 0 , P2INT , 0 );
	putRV( 0 , cbn , exproff , P2INT );
	putop( P2LISTOP , P2INT );
	putop( P2CALL , P2INT );
	putdot( filename , line );
	putlab( endlabel );
	noreach = nr;
	if ( goc != gocnt ) {
		putcnt();
E 2
I 2
D 17
	putlab( label );
E 17
I 17
	(void) putlab( label );
E 17
	putcnt();
	level++;
D 17
	statement( cstatp[3] );
D 5
	nr &= noreach;
E 5
I 5
	nr = (nr && noreach);
E 5
	noreach = 0;
E 17
I 17
	statement( cstatp->c_stmnt.stmnt );
	nr = (nr && noreach)?TRUE:FALSE;
	noreach = FALSE;
E 17
	level--;
	if (gotos[cbn]) {
		ungoto();
E 2
	}
I 2
D 17
	putjbr( endlabel );
E 17
I 17
	putjbr( (long) endlabel );
E 17
E 2
    }
I 4
    noreach = nr;
E 4
I 2
	/*
	 *	default action is to call error
	 */
D 17
    putlab( ctab[0].clabel );
E 17
I 17
    (void) putlab( (char *) ctab[0].clabel );
E 17
D 8
    putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR ) , "_ERROR" );
    putleaf( P2ICON , ECASE , 0 , P2INT , 0 );
E 8
I 8
D 21
    putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR ) , "_CASERNG" );
E 21
I 21
    putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR ) , "_CASERNG" );
E 21
E 8
D 6
    putleaf( P2REG , FORCENUMBER , 0 , P2INT , 0 );
E 6
I 6
D 7
    putRV( 0 , cbn , exproff , P2INT );
E 7
I 7
D 17
    putRV( 0 , cbn , exprnlp -> value[ NL_OFFS ] ,
E 17
I 17
    putRV((char *) 0 , cbn , exprnlp -> value[ NL_OFFS ] ,
E 17
D 21
		    exprnlp -> extra_flags , P2INT );
E 7
E 6
D 8
    putop( P2LISTOP , P2INT );
E 8
    putop( P2CALL , P2INT );
E 21
I 21
		    exprnlp -> extra_flags , PCCT_INT );
    putop( PCC_CALL , PCCT_INT );
E 21
    putdot( filename , line );
	/*
	 *  sort the cases
	 */
    qsort( &ctab[1] , count , sizeof (struct ct) , casecmp );
	/*
	 *  check for duplicates
	 */
I 4
    dupcases = FALSE;
E 4
    for ( ctp = &ctab[1] ; ctp < &ctab[ count ] ; ctp++ ) {
	if ( ctp[0].cconst == ctp[1].cconst ) {
D 4
	    error("Muliply defined label in case, lines %d and %d" ,
E 4
I 4
	    error("Multiply defined label in case, lines %d and %d" ,
E 4
D 17
		    ctp[0].cline , ctp[1].cline );
E 17
I 17
		    (char *) ctp[0].cline , (char *) ctp[1].cline );
E 17
I 4
	    dupcases = TRUE;
E 4
	}
    }
I 4
    if ( dupcases ) {
	return;
    }
E 4
	/*
	 *  choose a switch algorithm and implement it:
	 *	direct switch	>= 1/3 full and >= 4 cases.
	 *	binary switch	not direct switch and > 8 cases.
	 *	ifthenelse	not direct or binary switch.
	 */
D 17
    putlab( swlabel );
E 17
I 17
    (void) putlab( swlabel );
E 17
    if ( ctab[ count ].cconst - ctab[1].cconst < 3 * count && count >= 4 ) {
	directsw( ctab , count );
    } else if ( count > 8 ) {
	binarysw( ctab , count );
    } else {
	itesw( ctab , count );
    }
D 17
    putlab( endlabel );
E 17
I 17
    (void) putlab( endlabel );
E 17
D 4
    noreach = nr;
E 4
    if ( goc != gocnt ) {
	    putcnt();
    }
}
E 2

I 2
    /*
     *	direct switch
     */
directsw( ctab , count )
    struct ct	*ctab;
    int		count;
{
D 17
    int		fromlabel = getlab();
E 17
I 17
    int		fromlabel = (int) getlab();
E 17
    long	i;
    long	j;

D 11
    putprintf( "	casel	%s,$%d,$%d" , 0 , FORCENAME ,
	    ctab[1].cconst , ctab[ count ].cconst - ctab[1].cconst );
E 11
I 11
#   ifdef vax
D 15
	putprintf("	casel	%s,$%d,$%d" , 0 , FORCENAME ,
		ctab[1].cconst , ctab[ count ].cconst - ctab[1].cconst );
#   endif vax
#   ifdef mc68000
E 15
I 15
	if (opt('J')) {
E 15
	    /*
D 15
	     *	subl	to make d0 a 0-origin byte offset.
E 15
I 15
	     *	We have a table of absolute addresses.
	     *
	     *	subl2	to make r0 a 0-origin byte offset.
E 15
	     *	cmpl	check against upper limit.
D 15
	     *	bhi	error if out of bounds.
	     *	addw	to make d0 a 0-origin word offset.
	     *	movw	pick up a jump-table entry
E 15
I 15
D 20
	     *	blssu	error if out of bounds.
E 20
I 20
	     *	jlssu	error if out of bounds.
E 20
	     *	ashl	to make r0 a 0-origin long offset,
E 15
	     *	jmp	and indirect through it.
	     */
I 15
D 17
	    putprintf("	subl2	$%d,%s", 0, ctab[1].cconst, FORCENAME);
E 17
I 17
	    putprintf("	subl2	$%d,%s", 0, (int) ctab[1].cconst, (int) FORCENAME);
E 17
	    putprintf("	cmpl	$%d,%s", 0,
D 17
		    ctab[count].cconst - ctab[1].cconst, FORCENAME);
	    putprintf("	blssu	%s%d", 0, LABELPREFIX, ctab[0].clabel);
	    putprintf("	ashl	$2,%s,%s", 0, FORCENAME, FORCENAME);
E 17
I 17
			(int) (ctab[count].cconst - ctab[1].cconst),
			(int) FORCENAME);
D 20
	    putprintf("	blssu	%s%d", 0, (int) LABELPREFIX, ctab[0].clabel);
E 20
I 20
	    putprintf("	jlssu	%s%d", 0, (int) LABELPREFIX, ctab[0].clabel);
E 20
	    putprintf("	ashl	$2,%s,%s", 0, (int) FORCENAME, (int) FORCENAME);
E 17
	    putprintf("	jmp	*%s%d(%s)", 0,
D 17
		    LABELPREFIX, fromlabel, FORCENAME);
E 17
I 17
		    (int) LABELPREFIX, fromlabel, (int) FORCENAME);
E 17
	} else {
	    /*
	     *	We can use the VAX casel instruction with a table
	     *	of short relative offsets.
	     */
D 17
	    putprintf("	casel	%s,$%d,$%d" , 0 , FORCENAME ,
		    ctab[1].cconst , ctab[ count ].cconst - ctab[1].cconst );
E 17
I 17
	    putprintf("	casel	%s,$%d,$%d" , 0 , (int) FORCENAME ,
		    (int) ctab[1].cconst ,
		    (int) (ctab[ count ].cconst - ctab[1].cconst ));
E 17
	}
#   endif vax
I 23

#   ifdef tahoe
	if (opt('J')) {
	    /*
	     *	We have a table of absolute addresses.
	     *
	     *	subl2	to make r0 a 0-origin byte offset.
	     *	cmpl	check against upper limit.
	     *	jlssu	error if out of bounds.
	     *	shal	to make r0 a 0-origin long offset,
	     *	jmp	and indirect through it.
	     */
	    putprintf("	subl2	$%d,%s", 0, (int) ctab[1].cconst, (int) FORCENAME);
	    putprintf("	cmpl	$%d,%s", 0,
			(int) (ctab[count].cconst - ctab[1].cconst),
			(int) FORCENAME);
	    putprintf("	jlssu	%s%d", 0, (int) LABELPREFIX, ctab[0].clabel);
	    putprintf("	shal	$2,%s,%s", 0, (int) FORCENAME, (int) FORCENAME);
	    putprintf("	jmp	*%s%d(%s)", 0,
		    (int) LABELPREFIX, fromlabel, (int) FORCENAME);
	} else {
	    /*
	     *	We can use the TAHOE casel instruction with a table
	     *	of short relative offsets.
	     */
	    putprintf("	casel	%s,$%d,$%d" , 0 , (int) FORCENAME ,
		    (int) ctab[1].cconst ,
		    (int) (ctab[ count ].cconst - ctab[1].cconst ));
	    putprintf("	.align 1", 0);
	}
#   endif tahoe

E 23
#   ifdef mc68000
	/*
	 *	subl	to make d0 a 0-origin byte offset.
	 *	cmpl	check against upper limit.
	 *	bhi	error if out of bounds.
	 */
E 15
	putprintf("	subl	#%d,%s", 0, ctab[1].cconst, FORCENAME);
	putprintf("	cmpl	#%d,%s", 0,
		ctab[count].cconst - ctab[1].cconst, FORCENAME);
	putprintf("	bhi	%s%d", 0, LABELPREFIX, ctab[0].clabel);
D 15
	putprintf("	addw	%s,%s", 0, FORCENAME, FORCENAME);
	putprintf("	movw	pc@(6,%s:w),%s", 0, FORCENAME, FORCENAME);
	putprintf("	jmp	pc@(2,%s:w)", 0, FORCENAME);
E 15
I 15
	if (opt('J')) {
	    /*
	     *	We have a table of absolute addresses.
	     *
	     *	asll	to make d0 a 0-origin long offset.
	     *	movl	pick up a jump-table entry
	     *	jmp	and indirect through it.
	     */
	    putprintf("	asll	#2,%s", 0, FORCENAME, FORCENAME);
	    putprintf("	movl	pc@(4,%s:l),%s", 0, FORCENAME, ADDRTEMP);
	    putprintf("	jmp	%s@", 0, ADDRTEMP);
	} else {
	    /*
	     *	We have a table of relative addresses.
	     *
	     *	addw	to make d0 a 0-origin word offset.
	     *	movw	pick up a jump-table entry
	     *	jmp	and indirect through it.
	     */
	    putprintf("	addw	%s,%s", 0, FORCENAME, FORCENAME);
	    putprintf("	movw	pc@(6,%s:w),%s", 0, FORCENAME, FORCENAME);
	    putprintf("	jmp	pc@(2,%s:w)", 0, FORCENAME);
	}
E 15
#   endif mc68000
E 11
D 17
    putlab( fromlabel );
E 17
I 17
    (void) putlab( (char *) fromlabel );
E 17
    i = 1;
    j = ctab[1].cconst;
    while ( i <= count ) {
	if ( j == ctab[ i ].cconst ) {
D 15
	    putprintf( "	.word	" , 1 );
	    putprintf( PREFIXFORMAT , 1 , LABELPREFIX , ctab[ i ].clabel );
	    putprintf( "-" , 1 );
	    putprintf( PREFIXFORMAT , 0 , LABELPREFIX , fromlabel );
E 15
I 15
	    if (opt('J')) {
		putprintf( "	.long	" , 1 );
D 17
		putprintf( PREFIXFORMAT , 0 , LABELPREFIX , ctab[ i ].clabel );
E 17
I 17
		putprintf( PREFIXFORMAT , 0 , (int) LABELPREFIX , ctab[ i ].clabel );
E 17
	    } else {
		putprintf( "	.word	" , 1 );
D 17
		putprintf( PREFIXFORMAT , 1 , LABELPREFIX , ctab[ i ].clabel );
E 17
I 17
		putprintf( PREFIXFORMAT , 1 , (int) LABELPREFIX , ctab[ i ].clabel );
E 17
		putprintf( "-" , 1 );
D 17
		putprintf( PREFIXFORMAT , 0 , LABELPREFIX , fromlabel );
E 17
I 17
		putprintf( PREFIXFORMAT , 0 , (int) LABELPREFIX , fromlabel );
E 17
	    }
E 15
	    i++;
	} else {
D 15
	    putprintf( "	.word	" , 1 );
	    putprintf( PREFIXFORMAT , 1 , LABELPREFIX , ctab[ 0 ].clabel );
	    putprintf( "-" , 1 );
	    putprintf( PREFIXFORMAT , 0 , LABELPREFIX , fromlabel );
E 15
I 15
	    if (opt('J')) {
		putprintf( "	.long	" , 1 );
D 17
		putprintf( PREFIXFORMAT , 0 , LABELPREFIX , ctab[ 0 ].clabel );
E 17
I 17
		putprintf( PREFIXFORMAT , 0 , (int) LABELPREFIX , ctab[ 0 ].clabel );
E 17
	    } else {
		putprintf( "	.word	" , 1 );
D 17
		putprintf( PREFIXFORMAT , 1 , LABELPREFIX , ctab[ 0 ].clabel );
E 17
I 17
		putprintf( PREFIXFORMAT , 1 , (int) LABELPREFIX , ctab[ 0 ].clabel );
E 17
		putprintf( "-" , 1 );
D 17
		putprintf( PREFIXFORMAT , 0 , LABELPREFIX , fromlabel );
E 17
I 17
		putprintf( PREFIXFORMAT , 0 , (int) LABELPREFIX , fromlabel );
E 17
	    }
E 15
	}
	j++;
    }
D 11
    putjbr( ctab[0].clabel );
E 11
I 11
D 23
#   ifdef vax
E 23
I 23
#   if defined(vax) || defined(tahoe)
E 23
	    /*
	     *	execution continues here if value not in range of case.
	     */
D 15
	putjbr( ctab[0].clabel );
E 15
I 15
	if (!opt('J'))
D 17
	    putjbr( ctab[0].clabel );
E 17
I 17
	    putjbr( (long) ctab[0].clabel );
E 17
E 15
D 23
#   endif vax
E 23
I 23
#   endif vax || tahoe
E 23
E 11
}

    /*
     *	binary switch
     *	special case out default label and start recursion.
     */
binarysw( ctab , count )
    struct ct	*ctab;
    int		count;
{
    
    bsrecur( ctab[0].clabel , &ctab[0] , count );
}

    /*
     *	recursive log( count ) search.
     */
bsrecur( deflabel , ctab , count )
    int		deflabel;
    struct ct	*ctab;
    int		count;
{

    if ( count <= 0 ) {
D 11
	putprintf( "	jbr	L%d" , 0 , deflabel );
E 11
I 11
D 17
	putjbr(deflabel);
E 17
I 17
	putjbr((long) deflabel);
E 17
E 11
	return;
    } else if ( count == 1 ) {
D 11
	putprintf( "	cmpl	%s,$%d" , 0 , FORCENAME , ctab[1].cconst );
	putprintf( "	jeql	L%d" , 0 , ctab[1].clabel );
	putprintf( "	jbr	L%d" , 0 , deflabel );
E 11
I 11
D 23
#	ifdef vax
E 23
I 23
#	if defined(vax) || defined(tahoe)
E 23
D 17
	    putprintf("	cmpl	%s,$%d", 0, FORCENAME, ctab[1].cconst);
	    putprintf("	jeql	%s%d", 0, LABELPREFIX, ctab[1].clabel);
	    putjbr(deflabel);
E 17
I 17
	    putprintf("	cmpl	%s,$%d", 0, (int) FORCENAME, (int) ctab[1].cconst);
	    putprintf("	jeql	%s%d", 0, (int) LABELPREFIX, ctab[1].clabel);
	    putjbr((long) deflabel);
E 17
D 23
#	endif vax
E 23
I 23
#	endif vax || tahoe
E 23
#	ifdef mc68000
D 17
	    putprintf("	cmpl	#%d,%s", 0, ctab[1].cconst, FORCENAME);
D 16
	    putprintf("	jeq	L%d", 0, LABELPREFIX, ctab[1].clabel);
E 16
I 16
	    putprintf("	jeq	%s%d", 0, LABELPREFIX, ctab[1].clabel);
E 16
	    putjbr(deflabel);
E 17
I 17
	    putprintf("	cmpl	#%d,%s", 0, ctab[1].cconst, (int) FORCENAME);
	    putprintf("	jeq	L%d", 0, (int) LABELPREFIX, ctab[1].clabel);
	    putjbr((long) deflabel);
E 17
#	endif mc68000
E 11
	return;
    } else {
	int	half = ( count + 1 ) / 2;
D 17
	int	gtrlabel = getlab();
E 17
I 17
	int	gtrlabel = (int) getlab();
E 17

D 11
	putprintf( "	cmpl	%s,$%d" , 0 , FORCENAME , ctab[ half ].cconst );
D 3
	putprintf( "	jeql	L%d" , 0 , ctab[ half ].clabel );
E 3
	putprintf( "	jgtr	L%d" , 0 , gtrlabel );
I 3
	putprintf( "	jeql	L%d" , 0 , ctab[ half ].clabel );
E 11
I 11
D 23
#	ifdef vax
E 23
I 23
#	if defined(vax) || defined(tahoe)
E 23
D 17
	    putprintf("	cmpl	%s,$%d", 0, FORCENAME, ctab[half].cconst);
	    putprintf("	jgtr	%s%d", 0, LABELPREFIX, gtrlabel);
	    putprintf("	jeql	%s%d", 0, LABELPREFIX, ctab[half].clabel);
E 17
I 17
	    putprintf("	cmpl	%s,$%d", 0, (int) FORCENAME, (int) ctab[half].cconst);
	    putprintf("	jgtr	%s%d", 0, (int) LABELPREFIX, gtrlabel);
	    putprintf("	jeql	%s%d", 0, (int) LABELPREFIX, ctab[half].clabel);
E 17
D 23
#	endif vax
E 23
I 23
#	endif vax || tahoe
E 23
#	ifdef mc68000
D 17
	    putprintf("	cmpl	#%d,%s", 0, ctab[half].cconst, FORCENAME);
	    putprintf("	jgt	%s%d", 0, LABELPREFIX, gtrlabel);
	    putprintf("	jeq	%s%d", 0, LABELPREFIX, ctab[half].clabel);
E 17
I 17
	    putprintf("	cmpl	#%d,%s", 0, (int) ctab[half].cconst, (int) FORCENAME);
	    putprintf("	jgt	%s%d", 0, (int) LABELPREFIX, gtrlabel);
	    putprintf("	jeq	%s%d", 0, (int) LABELPREFIX, ctab[half].clabel);
E 17
#	endif mc68000
E 11
E 3
	bsrecur( deflabel , &ctab[0] , half - 1 );
D 11
	putprintf( "L%d:" , 0 , gtrlabel );
E 11
I 11
D 17
	putlab(gtrlabel);
E 17
I 17
	(void) putlab((char *) gtrlabel);
E 17
E 11
	bsrecur( deflabel , &ctab[ half ] , count - half );
	return;
    }
}

itesw( ctab , count )
    struct ct	*ctab;
    int		count;
{
    int	i;

    for ( i = 1 ; i <= count ; i++ ) {
D 11
	putprintf( "	cmpl	%s,$%d" , 0 , FORCENAME , ctab[ i ].cconst );
	putprintf( "	jeql	L%d" , 0 , ctab[ i ].clabel );
E 11
I 11
D 23
#	ifdef vax
E 23
I 23
#	if defined(vax) || defined(tahoe)
E 23
D 17
	    putprintf("	cmpl	%s,$%d", 0, FORCENAME, ctab[i].cconst);
	    putprintf("	jeql	%s%d", 0, LABELPREFIX, ctab[i].clabel);
E 17
I 17
	    putprintf("	cmpl	%s,$%d", 0, (int) FORCENAME, (int) ctab[i].cconst);
	    putprintf("	jeql	%s%d", 0, (int) LABELPREFIX, ctab[i].clabel);
E 17
D 23
#	endif vax
E 23
I 23
#	endif vax || tahoe
E 23
#	ifdef mc68000
D 17
	    putprintf("	cmpl	#%d,%s", 0, ctab[i].cconst, FORCENAME);
	    putprintf("	jeq	%s%d", 0, LABELPREFIX, ctab[i].clabel);
E 17
I 17
	    putprintf("	cmpl	#%d,%s", 0, (int) ctab[i].cconst, (int) FORCENAME);
	    putprintf("	jeq	%s%d", 0, (int) LABELPREFIX, ctab[i].clabel);
E 17
#	endif mc68000
E 11
    }
D 11
    putprintf( "	jbr	L%d" , 0 , ctab[0].clabel );
E 11
I 11
D 17
    putjbr(ctab[0].clabel);
E 17
I 17
    putjbr((long) ctab[0].clabel);
E 17
E 11
    return;
}
int
casecmp( this , that )
    struct ct 	*this;
    struct ct 	*that;
{
    if ( this -> cconst < that -> cconst ) {
	return -1;
    } else if ( this -> cconst > that -> cconst ) {
	return 1;
    } else {
	return 0;
    }
}
E 2
#endif PC
E 1
