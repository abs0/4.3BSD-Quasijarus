h42697
s 00004/00002/00659
d D 5.3 86/11/12 10:29:03 mckusick 40 39
c replace `even' and `leven' with explicit rounding
e
s 00001/00001/00660
d D 5.2 85/07/26 16:13:26 mckusick 39 38
c null pointer checks (from ralph)
e
s 00007/00003/00654
d D 5.1 85/06/04 11:38:16 dist 38 37
c Add copyright
e
s 00001/00001/00656
d D 2.3 85/04/16 18:29:03 mckusick 37 36
c must check for NIL pointer
e
s 00051/00051/00606
d D 2.2 85/03/20 14:58:26 ralph 36 35
c changes from donn@utah-cs for common header file for pcc
e
s 00000/00000/00657
d D 2.1 84/02/08 20:47:44 aoki 35 34
c synchronize to version 2
e
s 00099/00003/00558
d D 1.27 84/02/08 00:48:30 mckusick 34 32
c merge in conformant array code by Carol Nishizak
e
s 00000/00000/00561
d R 1.27 83/10/09 18:06:01 thien 33 32
c 
e
s 00000/00000/00561
d D 1.26 83/09/19 06:57:32 thien 32 31
c Restoring to unlinted version
e
s 00103/00078/00458
d D 1.25 83/08/19 04:55:12 thien 31 30
c The changes were made to allow successful linting
e
s 00015/00002/00521
d D 1.24 83/06/03 14:14:14 peter 30 29
c fix the type of the address of a formal call etnry address.
e
s 00002/00002/00521
d D 1.23 83/04/06 22:10:55 peter 29 28
c it says in my description of the ir that STASG's have the type
c pointer to structure.  this makes a difference for the FORCE in fend.c
c on the mc68000.
e
s 00001/00000/00522
d D 1.22 83/02/28 17:17:43 peter 28 27
c clean up temporary allocation, moving everything relevant to
c tmps.c and (new) tmps.h.  correctly emit LBRAC lines.  allocate registers
c from high to low.  put in data structures for multiple types of registers.
e
s 00001/00001/00521
d D 1.21 83/02/01 21:48:57 peter 27 26
c postcheck() takes struct nl *'s, not p2types.
e
s 00007/00007/00515
d D 1.20 83/01/17 13:58:23 mckusick 26 25
c put in explicit scalar converts (sconv's) to make less code-generator dependent.
e
s 00001/00001/00521
d D 1.19 82/08/26 18:47:32 mckusick 25 24
c convert namelist structure to use unions
e
s 00020/00003/00502
d D 1.18 81/07/15 14:58:25 mckusic 24 22
c rmdel -r1.16
e
s 00020/00003/00502
d R 1.18 81/07/15 13:21:04 mckusic 23 22
c rmdel -r1.16
e
s 00033/00012/00472
d D 1.17 81/06/12 16:51:26 peter 22 21
c copy formal descriptor to a local (so it's addressable) for FRTN.
e
s 00000/00017/00484
d D 1.16 81/06/08 13:04:41 mckusic 21 20
c put display save area back into formal routine structure
e
s 00001/00001/00500
d D 1.15 81/06/03 15:28:37 peter 20 19
c formal functions need not be at the current level; just a bug.
e
s 00024/00015/00477
d D 1.14 81/06/01 15:35:04 peter 19 18
c add storage classes to namelist, and use them.
e
s 00051/00013/00441
d D 1.13 81/04/01 21:51:19 peter 18 17
c dynamically allocate display save areas before formal calls
e
s 00002/00002/00452
d D 1.12 81/03/26 17:29:02 peter 17 16
c also check that for variables are not passed as var parameters.
e
s 00004/00022/00450
d D 1.11 81/03/24 17:51:02 peter 16 15
c add sextname() to make up long external names for things.
e
s 00003/00000/00469
d D 1.10 81/03/24 14:34:05 peter 15 14
c if call() detects errors, notify caller.
e
s 00004/00004/00465
d D 1.9 81/03/23 18:24:58 mckusic 14 12
c change cbn to psbn for routine level
e
s 00002/00002/00467
d R 1.9 81/03/23 15:12:55 mckusic 13 12
c cbn should be psbn
e
s 00217/00192/00252
d D 1.8 81/03/18 21:17:23 mckusic 12 11
c mods for new formal routine syntax
e
s 00001/00005/00443
d D 1.7 81/03/11 23:36:23 mckusic 11 10
c centralize temporary allocation in tmps.c
e
s 00000/00000/00448
d D 1.6 81/03/08 16:17:00 mckusic 10 8
i 9
c merge in 1.4.1.1 (onyx changes)
e
s 00008/00008/00392
d D 1.4.1.1 81/03/08 16:13:27 mckusic 9 7
c merge in onyx changes
e
s 00119/00071/00329
d D 1.5 81/02/17 18:26:33 peter 8 7
c fix formal calls to save result; general cleanup.
e
s 00002/00001/00398
d D 1.4 81/01/10 16:59:36 mckusic 7 6
c convert to "fp", "ap" type display; fix SUCC and PRED
e
s 00265/00116/00134
d D 1.3 80/10/03 01:07:26 peter 6 5
c Implement formal functions and procedures
e
s 00004/00003/00246
d D 1.2 80/08/29 17:01:06 peter 5 1
c float integer actual to real formal
e
s 00002/00001/00248
d R 1.4 80/08/29 16:54:42 peter 4 3
c is formal's type double? not formal itself double (never happens)
e
s 00003/00003/00246
d R 1.3 80/08/29 16:12:16 peter 3 2
c move float-actual code to proper case
e
s 00003/00003/00246
d R 1.2 80/08/28 15:56:45 peter 2 1
c float integer actual to real formal
e
s 00249/00000/00000
d D 1.1 80/08/27 19:54:40 peter 1 0
c date and time created 80/08/27 19:54:40 by peter
e
u
U
f b 
t
T
I 1
D 38
/* Copyright (c) 1979 Regents of the University of California */
E 38
I 38
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 38

I 31
#ifndef lint
E 31
D 38
static	char sccsid[] = "%Z%%M% %I% %G%";
I 31
#endif
E 38
I 38
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 38
E 31

#include "whoami.h"
#include "0.h"
#include "tree.h"
#include "opcode.h"
#include "objfmt.h"
I 40
#include "align.h"
E 40
#ifdef PC
#   include "pc.h"
D 36
#   include "pcops.h"
E 36
I 36
#   include <pcc.h>
E 36
#endif PC
I 28
#include "tmps.h"
I 31
#include "tree_ty.h"
E 31
E 28

I 6
D 8
bool	slenflag = 0;
bool	floatflag = 0;
E 8
I 8
D 16
short	slenline = 0;
short	floatline = 0;
E 8

E 16
E 6
/*
 * Call generates code for calls to
 * user defined procedures and functions
 * and is called by proc and funccod.
 * P is the result of the lookup
 * of the procedure/function symbol,
 * and porf is PROC or FUNC.
 * Psbn is the block number of p.
I 8
 *
 *	the idea here is that regular scalar functions are just called,
 *	while structure functions and formal functions have their results
 *	stored in a temporary after the call.
 *	structure functions do this because they return pointers
 *	to static results, so we copy the static
 *	and return a pointer to the copy.
 *	formal functions do this because we have to save the result
 *	around a call to the runtime routine which restores the display,
 *	so we can't just leave the result lying around in registers.
I 22
 *	formal calls save the address of the descriptor in a local
 *	temporary, so it can be addressed for the call which restores
 *	the display (FRTN).
E 22
I 18
 *	calls to formal parameters pass the formal as a hidden argument 
 *	to a special entry point for the formal call.
 *	[this is somewhat dependent on the way arguments are addressed.]
E 18
 *	so PROCs and scalar FUNCs look like
 *		p(...args...)
 *	structure FUNCs look like
 *		(temp = p(...args...),&temp)
 *	formal FPROCs look like
D 18
 *		((FCALL( p ))(...args...),FRTN( p ))
E 18
I 18
D 22
 *		( p -> entryaddr )(...args...,p),FRTN( p ))
E 22
I 22
D 24
 *		( t=p,( t -> entryaddr )(...args...,t),FRTN( t ))
E 24
I 24
 *		( t=p,( t -> entryaddr )(...args...,t,s),FRTN(t,s))
E 24
E 22
E 18
 *	formal scalar FFUNCs look like
D 18
 *		(temp = (FCALL( p ))(...args...),FRTN( p ),temp)
E 18
I 18
D 22
 *		(temp = ( p -> entryaddr )(...args...,p),FRTN( p ),temp)
E 22
I 22
D 24
 *		( t=p,temp=( t -> entryaddr )(...args...,t),FRTN( t ),temp)
E 24
I 24
 *		( t=p,temp=( t -> entryaddr )(...args...,t,s),FRTN(t,s),temp)
E 24
E 22
E 18
 *	formal structure FFUNCs look like
D 18
 *		(temp = (FCALL( p ))(...args...),FRTN( p ),&temp)
E 18
I 18
D 22
 *		(temp = ( p -> entryaddr )(...args...,p),FRTN( p ),&temp)
E 22
I 22
D 24
 *		(t=p,temp = ( t -> entryaddr )(...args...,t),FRTN( t ),&temp)
E 24
I 24
 *		(t=p,temp = ( t -> entryaddr )(...args...,t,s),FRTN(t,s),&temp)
E 24
E 22
E 18
E 8
 */
struct nl *
D 31
call(p, argv, porf, psbn)
E 31
I 31
call(p, argv_node, porf, psbn)
E 31
	struct nl *p;
D 31
	int *argv, porf, psbn;
E 31
I 31
	struct tnode	*argv_node;	/* list node */
	int porf, psbn;
E 31
{
D 34
	register struct nl *p1, *q;
E 34
I 34
	register struct nl *p1, *q, *p2;
	register struct nl *ptype, *ctype;
E 34
D 31
	int *r;
I 8
	struct nl	*p_type_class = classify( p -> type );
E 31
I 31
	struct tnode *rnode;
I 34
	int i, j, d;
E 34
E 31
E 8
D 12

I 6
#	ifdef OBJ
	    int		cnt;
#	endif OBJ
E 12
I 12
	bool chk = TRUE;
I 24
 	struct nl	*savedispnp;	/* temporary to hold saved display */
E 24
I 18
D 19
	long	savedisp;	/* temporary to hold saved display */
E 19
I 19
D 21
	struct nl	*savedispnp;	/* temporary to hold saved display */
E 21
E 19
E 18
E 12
E 6
#	ifdef PC
D 8
	    long	temp;
	    int		firsttime;
	    int		rettype;
E 8
I 8
D 31
	    long	p_p2type = p2type( p );
E 31
I 31
	    int		p_type_class = classify( p -> type );
E 31
	    long	p_type_p2type = p2type( p -> type );
	    bool	noarguments;
D 31
	    long	calltype;	/* type of the call */
E 31
		/*
		 *	these get used if temporaries and structures are used
		 */
D 19
	    long	tempoffset;
E 19
I 19
	    struct nl	*tempnlp;
E 19
	    long	temptype;	/* type of the temporary */
	    long	p_type_width;
	    long	p_type_align;
I 16
	    char	extname[ BUFSIZ ];
I 22
	    struct nl	*tempdescrp;
E 22
D 18

E 18
E 16
E 8
#	endif PC

I 24
         if (p->class == FFUNC || p->class == FPROC) {
 	    /*
 	     * allocate space to save the display for formal calls
 	     */
D 31
	    savedispnp = tmpalloc( sizeof display , NIL , NOREG );
E 31
I 31
	    savedispnp = tmpalloc( (long) sizeof display , NLNIL , NOREG );
E 31
 	}
E 24
I 18
D 21
        if (p->class == FFUNC || p->class == FPROC) {
	    /*
	     * allocate space to save the display for formal calls
	     */
D 19
	    savedisp = tmpalloc( sizeof display , NIL , NOREG );
E 19
I 19
	    savedispnp = tmpalloc( sizeof display , NIL , NOREG );
E 19
	}
E 21
E 18
#	ifdef OBJ
I 6
D 18
	    if (p->class == FFUNC || p->class == FPROC)
E 18
I 18
	    if (p->class == FFUNC || p->class == FPROC) {
I 24
D 31
 		put(2, O_LV | cbn << 8 + INDX ,
E 31
I 31
 		(void) put(2, O_LV | cbn << 8 + INDX ,
E 31
 			(int) savedispnp -> value[ NL_OFFS ] );
E 24
D 19
		put(2, O_LV | cbn << 8 + INDX , (int) savedisp );
E 19
I 19
D 21
		put(2, O_LV | cbn << 8 + INDX ,
			(int) savedispnp -> value[ NL_OFFS ] );
E 21
E 19
E 18
D 9
		put(2, PTR_RV | cbn << 8+INDX, p->value[NL_OFFS]);
E 9
I 9
D 14
		put(2, PTR_RV | cbn << 8+INDX, (int)p->value[NL_OFFS]);
E 14
I 14
D 31
		put(2, PTR_RV | psbn << 8+INDX, (int)p->value[NL_OFFS]);
E 31
I 31
		(void) put(2, PTR_RV | psbn << 8+INDX, (int)p->value[NL_OFFS]);
E 31
E 14
E 9
E 6
D 18
	    if (porf == FUNC)
E 18
I 18
	    }
	    if (porf == FUNC) {
E 18
		    /*
		     * Push some space
		     * for the function return type
		     */
D 9
		    put2(O_PUSH, even(-width(p->type)));
E 9
I 9
D 31
		    put(2, O_PUSH, leven(-lwidth(p->type)));
E 31
I 31
D 40
		    (void) put(2, O_PUSH, leven(-lwidth(p->type)));
E 40
I 40
		    (void) put(2, O_PUSH,
			-roundup(lwidth(p->type), (long) A_STACK));
E 40
E 31
I 18
	    }
E 18
E 9
#	endif OBJ
#	ifdef PC
I 8
		/*
I 22
		 *	if this is a formal call,
		 *	stash the address of the descriptor
		 *	in a temporary so we can find it
		 *	after the FCALL for the call to FRTN
		 */
	    if ( p -> class == FFUNC || p -> class == FPROC ) {
D 31
		tempdescrp = tmpalloc(sizeof( struct formalrtn *) , NIL ,
					REGOK );
		putRV( 0 , cbn , tempdescrp -> value[ NL_OFFS ] ,
E 31
I 31
		tempdescrp = tmpalloc((long) (sizeof( struct formalrtn *)),
					NLNIL, REGOK );
		putRV((char *) 0 , cbn , tempdescrp -> value[ NL_OFFS ] ,
E 31
D 36
			tempdescrp -> extra_flags , P2PTR|P2STRTY );
E 36
I 36
			tempdescrp -> extra_flags , PCCTM_PTR|PCCT_STRTY );
E 36
D 31
		putRV( 0 , psbn , p -> value[ NL_OFFS ] ,
E 31
I 31
		putRV((char *) 0 , psbn , p -> value[ NL_OFFS ] ,
E 31
D 36
			p -> extra_flags , P2PTR|P2STRTY );
		putop( P2ASSIGN , P2PTR | P2STRTY );
E 36
I 36
			p -> extra_flags , PCCTM_PTR|PCCT_STRTY );
		putop( PCC_ASSIGN , PCCTM_PTR | PCCT_STRTY );
E 36
	    }
		/*
E 22
		 *	if we have to store a temporary,
		 *	temptype will be its type,
D 36
		 *	otherwise, it's P2UNDEF.
E 36
I 36
		 *	otherwise, it's PCCT_UNDEF.
E 36
		 */
D 36
	    temptype = P2UNDEF;
E 36
I 36
	    temptype = PCCT_UNDEF;
E 36
D 31
	    calltype = P2INT;
E 31
E 8
	    if ( porf == FUNC ) {
D 8
		switch( classify( p -> type ) ) {
E 8
I 8
		p_type_width = width( p -> type );
		switch( p_type_class ) {
E 8
		    case TSTR:
		    case TSET:
		    case TREC:
		    case TFILE:
		    case TARY:
D 8
			temp = sizes[ cbn ].om_off -= width( p -> type );
			putlbracket( ftnno , -sizes[cbn].om_off );
			if (sizes[cbn].om_off < sizes[cbn].om_max) {
				sizes[cbn].om_max = sizes[cbn].om_off;
E 8
I 8
D 31
			calltype = temptype = P2STRTY;
E 31
I 31
D 36
			temptype = P2STRTY;
E 36
I 36
			temptype = PCCT_STRTY;
E 36
E 31
			p_type_align = align( p -> type );
			break;
		    default:
			if ( p -> class == FFUNC ) {
D 31
			    calltype = temptype = p2type( p -> type );
E 31
I 31
			    temptype = p2type( p -> type );
E 31
E 8
			}
D 8
			putRV( 0 , cbn , temp , P2STRTY );
E 8
I 8
			break;
E 8
		}
I 8
D 36
		if ( temptype != P2UNDEF ) {
E 36
I 36
		if ( temptype != PCCT_UNDEF ) {
E 36
D 11
		    tempoffset = sizes[ cbn ].om_off -= p_type_width;
		    putlbracket( ftnno , -tempoffset );
		    if ( tempoffset < sizes[cbn].om_max) {
			    sizes[cbn].om_max = tempoffset;
		    }
E 11
I 11
D 19
		    tempoffset = tmpalloc(p_type_width, p -> type, NOREG);
E 19
I 19
		    tempnlp = tmpalloc(p_type_width, p -> type, NOREG);
E 19
E 11
			/*
			 *	temp
			 *	for (temp = ...
			 */
D 19
		    putRV( 0 , cbn , tempoffset , temptype );
E 19
I 19
D 31
		    putRV( 0 , cbn , tempnlp -> value[ NL_OFFS ] ,
			    tempnlp -> extra_flags , temptype );
E 31
I 31
		    putRV((char *) 0 , cbn , tempnlp -> value[ NL_OFFS ] ,
			    tempnlp -> extra_flags , (int) temptype );
E 31
E 19
		}
E 8
	    }
D 6
	    {
		char	extname[ BUFSIZ ];
		char	*starthere;
		int	funcbn;
		int	i;
E 6
I 6
	    switch ( p -> class ) {
		case FUNC:
		case PROC:
I 8
			/*
			 *	... p( ...
			 */
E 8
D 16
		    {
			char	extname[ BUFSIZ ];
			char	*starthere;
			int	funcbn;
			int	i;
E 6

D 6
		starthere = &extname[0];
		funcbn = p -> nl_block & 037;
		for ( i = 1 ; i < funcbn ; i++ ) {
		    sprintf( starthere , EXTFORMAT , enclosing[ i ] );
		    starthere += strlen( enclosing[ i ] ) + 1;
		}
		sprintf( starthere , EXTFORMAT , p -> symbol );
		starthere += strlen( p -> symbol ) + 1;
		if ( starthere >= &extname[ BUFSIZ ] ) {
		    panic( "call namelength" );
		}
		putleaf( P2ICON , 0 , 0 , p2type( p ) , extname );
E 6
I 6
			starthere = &extname[0];
			funcbn = p -> nl_block & 037;
			for ( i = 1 ; i < funcbn ; i++ ) {
			    sprintf( starthere , EXTFORMAT , enclosing[ i ] );
			    starthere += strlen( enclosing[ i ] ) + 1;
			}
			sprintf( starthere , EXTFORMAT , p -> symbol );
			starthere += strlen( p -> symbol ) + 1;
			if ( starthere >= &extname[ BUFSIZ ] ) {
			    panic( "call namelength" );
			}
			putleaf( P2ICON , 0 , 0 , p2type( p ) , extname );
		    }
E 16
I 16
D 17
		    sextname( extname , p -> symbol , p -> nl_block & 037 );
E 17
I 17
		    sextname( extname , p -> symbol , BLOCKNO(p -> nl_block) );
E 17
D 36
		    putleaf( P2ICON , 0 , 0 , p2type( p ) , extname );
E 36
I 36
		    putleaf( PCC_ICON , 0 , 0 , p2type( p ) , extname );
E 36
E 16
		    break;
		case FFUNC:
		case FPROC:
I 22

E 22
			    /*
D 8
			     *	start one of these:
			     *	FRTN( frtn , ( *FCALL( frtn ) )(...args...) )
E 8
I 8
D 18
			     *	... (FCALL( p ))( ...
E 18
I 18
D 22
			     *	... ( p -> entryaddr )( ...
E 22
I 22
			     *	... ( t -> entryaddr )( ...
E 22
E 18
E 8
			     */
I 30
			    /* 	the descriptor */
E 30
D 8
			putleaf( P2ICON , 0 , 0 , p2type( p ) , "_FRTN" );
			putRV( 0 , cbn , p -> value[NL_OFFS] , P2PTR|P2STRTY );
E 8
D 18
		    	putleaf( P2ICON , 0 , 0
D 8
			    , ADDTYPE( P2PTR , ADDTYPE( P2FTN , p2type( p ) ) )
E 8
I 8
			    , ADDTYPE( ADDTYPE( p_p2type , P2FTN ) , P2PTR )
E 8
			    , "_FCALL" );
D 14
			putRV( 0 , cbn , p -> value[NL_OFFS] , P2PTR|P2STRTY );
E 14
I 14
			putRV( 0 , psbn , p -> value[NL_OFFS] , P2PTR|P2STRTY );
E 14
D 8
			putop( P2CALL , p2type( p ) );
E 8
I 8
			putop( P2CALL , p_p2type );
E 18
I 18
D 19
			putRV( 0 , psbn , ( p -> value[NL_OFFS] ) ,
				P2PTR | P2STRTY );
E 19
I 19
D 22
			putRV( 0 , psbn , p -> value[ NL_OFFS ] ,
				p -> extra_flags , P2PTR | P2STRTY );
E 22
I 22
D 31
			putRV( 0 , cbn , tempdescrp -> value[ NL_OFFS ] ,
E 31
I 31
			putRV((char *) 0 , cbn , tempdescrp -> value[ NL_OFFS ] ,
E 31
D 36
				tempdescrp -> extra_flags , P2PTR | P2STRTY );
E 36
I 36
				tempdescrp -> extra_flags , PCCTM_PTR | PCCT_STRTY );
E 36
I 30
			    /*	the entry address within the descriptor */
E 30
E 22
E 19
			if ( FENTRYOFFSET != 0 ) {
D 31
			    putleaf( P2ICON , FENTRYOFFSET , 0 , P2INT , 0 );
E 31
I 31
D 36
			    putleaf( P2ICON , FENTRYOFFSET , 0 , P2INT , 
E 36
I 36
			    putleaf( PCC_ICON , FENTRYOFFSET , 0 , PCCT_INT , 
E 36
						(char *) 0 );
E 31
D 36
			    putop( P2PLUS , 
				ADDTYPE(
				    ADDTYPE( ADDTYPE( p2type( p ) , P2FTN ) ,
					    P2PTR ) ,
					P2PTR ) );
E 36
I 36
			    putop( PCC_PLUS , 
				PCCM_ADDTYPE(
				    PCCM_ADDTYPE( PCCM_ADDTYPE( p2type( p ) , PCCTM_FTN ) ,
					    PCCTM_PTR ) ,
					PCCTM_PTR ) );
E 36
			}
D 30
			putop( P2UNARY P2MUL ,
			    ADDTYPE( ADDTYPE( p2type( p ) , P2FTN ) , P2PTR ) );
E 30
I 30
			    /*
			     *	indirect to fetch the formal entry address
			     *	with the result type of the routine.
			     */
			if (p -> class == FFUNC) {
D 36
			    putop( P2UNARY P2MUL ,
				ADDTYPE(ADDTYPE(p2type(p -> type), P2FTN),
					P2PTR));
E 36
I 36
			    putop( PCCOM_UNARY PCC_MUL ,
				PCCM_ADDTYPE(PCCM_ADDTYPE(p2type(p -> type), PCCTM_FTN),
					PCCTM_PTR));
E 36
			} else {
				/* procedures are int returning functions */
D 36
			    putop( P2UNARY P2MUL ,
				ADDTYPE(ADDTYPE(P2INT, P2FTN), P2PTR));
E 36
I 36
			    putop( PCCOM_UNARY PCC_MUL ,
				PCCM_ADDTYPE(PCCM_ADDTYPE(PCCT_INT, PCCTM_FTN), PCCTM_PTR));
E 36
			}
E 30
E 18
E 8
			break;
		default:
			panic("call class");
E 6
	    }
D 8
	    firsttime = TRUE;
E 8
I 8
	    noarguments = TRUE;
E 8
#	endif PC
	/*
	 * Loop and process each of
	 * arguments to the proc/func.
I 8
	 *	... ( ... args ... ) ...
E 8
	 */
I 34
	ptype = NIL;
E 34
D 6
	for (p1 = p->chain; p1 != NIL; p1 = p1->chain) {
	    if (argv == NIL) {
		    error("Not enough arguments to %s", p->symbol);
		    return (NIL);
	    }
	    switch (p1->class) {
		case REF:
			/*
			 * Var parameter
			 */
			r = argv[1];
			if (r != NIL && r[0] != T_VAR) {
				error("Expression given (variable required) for var parameter %s of %s", p1->symbol, p->symbol);
				break;
			}
			q = lvalue( (int *) argv[1], MOD , LREQ );
			if (q == NIL)
				break;
			if (q != p1->type) {
				error("Parameter type not identical to type of var parameter %s of %s", p1->symbol, p->symbol);
				break;
			}
			break;
		case VAR:
			/*
			 * Value parameter
			 */
E 6
I 6
D 12
	if ( p -> class == FUNC || p -> class == PROC ) {
	    for (p1 = p->chain; p1 != NIL; p1 = p1->chain) {
		if (argv == NIL) {
			error("Not enough arguments to %s", p->symbol);
			return (NIL);
		}
		switch (p1->class) {
		    case REF:
			    /*
			     * Var parameter
			     */
			    r = argv[1];
			    if (r != NIL && r[0] != T_VAR) {
				    error("Expression given (variable required) for var parameter %s of %s", p1->symbol, p->symbol);
				    break;
			    }
			    q = lvalue( (int *) argv[1], MOD , LREQ );
			    if (q == NIL)
				    break;
			    if (q != p1->type) {
				    error("Parameter type not identical to type of var parameter %s of %s", p1->symbol, p->symbol);
				    break;
			    }
			    break;
		    case VAR:
			    /*
			     * Value parameter
			     */
E 12
I 12
D 31
	for (p1 = plist(p); p1 != NIL; p1 = p1->chain) {
	    if (argv == NIL) {
E 31
I 31
	for (p1 = plist(p); p1 != NLNIL; p1 = p1->chain) {
	    if (argv_node == TR_NIL) {
E 31
		    error("Not enough arguments to %s", p->symbol);
D 31
		    return (NIL);
E 31
I 31
		    return (NLNIL);
E 31
	    }
	    switch (p1->class) {
		case REF:
			/*
			 * Var parameter
			 */
D 31
			r = argv[1];
			if (r != NIL && r[0] != T_VAR) {
E 31
I 31
			rnode = argv_node->list_node.list;
			if (rnode != TR_NIL && rnode->tag != T_VAR) {
E 31
				error("Expression given (variable required) for var parameter %s of %s", p1->symbol, p->symbol);
I 15
				chk = FALSE;
E 15
				break;
			}
D 17
			q = lvalue( (int *) argv[1], MOD , LREQ );
E 17
I 17
D 31
			q = lvalue( (int *) argv[1], MOD | ASGN , LREQ );
E 31
I 31
			q = lvalue( argv_node->list_node.list,
					MOD | ASGN , LREQ );
E 31
E 17
			if (q == NIL) {
				chk = FALSE;
				break;
			}
D 34
			if (q != p1->type) {
E 34
I 34
			p2 = p1->type;
D 37
			if (p2->chain->class != CRANGE) {
E 37
I 37
D 39
			if (p2 == NLNIL || p2->chain->class != CRANGE) {
E 39
I 39
			if (p2 == NLNIL || p2->chain == NLNIL || p2->chain->class != CRANGE) {
E 39
E 37
			    if (q != p2) {
E 34
				error("Parameter type not identical to type of var parameter %s of %s", p1->symbol, p->symbol);
I 15
				chk = FALSE;
E 15
D 34
				break;
E 34
I 34
			    }
			    break;
			} else {
			    /* conformant array */
			    if (p1 == ptype) {
				if (q != ctype) {
				    error("Conformant array parameters in the same specification must be the same type.");
				    goto conf_err;
				}
			    } else {
				if (classify(q) != TARY && classify(q) != TSTR) {
				    error("Array type required for var parameter %s of %s",p1->symbol,p->symbol);
				    goto conf_err;
				}
				/* check base type of array */
				if (p2->type != q->type) {
				    error("Base type of array not identical to that of conformant array parameter %s of %s", p1->symbol, p->symbol);
				    goto conf_err;
				}
				if (p2->value[0] != q->value[0]) {
				    error("Subscript number mismatch on conformant array parameter %s of %s", p1->symbol, p->symbol);
				    /* Don't process array bounds & width */
conf_err:			    if (p1->chain->type->class == CRANGE) {
					d = p1->value[0];
					for (i = 1; i <= d; i++) {
					    /* for each subscript, pass by
					     * bounds and width
					     */
					    p1 = p1->chain->chain->chain;
					}
				    }
				    ptype = ctype = NLNIL;
				    chk = FALSE;
				    break;
				}
				/*
				 * Save array type for all parameters with same
				 * specification.
				 */
				ctype = q;
				ptype = p2;
				/*
				 * If at end of conformant array list,
				 * get bounds.
				 */
				if (p1->chain->type->class == CRANGE) {
				    /* check each subscript, put on stack */
				    d = ptype->value[0];
				    q = ctype;
				    for (i = 1; i <= d; i++) {
					p1 = p1->chain;
					q = q->chain;
					if (incompat(q, p1->type, TR_NIL)){
					    error("Subscript type not conformable with parameter %s of %s", p1->symbol, p->symbol);
					    chk = FALSE;
					    break;
					}
					/* Put lower and upper bound & width */
#					ifdef OBJ
					if (q->type->class == CRANGE) {
					    putcbnds(q->type);
					} else {
					    put(2, width(p1->type) <= 2 ? O_CON2
						: O_CON4, q->range[0]);
					    put(2, width(p1->type) <= 2 ? O_CON2
						: O_CON4, q->range[1]);
					    put(2, width(p1->type) <= 2 ? O_CON2
						: O_CON4, aryconst(ctype,i));
					}
#					endif OBJ
#					ifdef PC
					if (q->type->class == CRANGE) {
					    for (j = 1; j <= 3; j++) {
						p2 = p->nptr[j];
						putRV(p2->symbol, (p2->nl_block
						    & 037), p2->value[0],
						    p2->extra_flags,p2type(p2));
D 36
						putop(P2LISTOP, P2INT);
E 36
I 36
						putop(PCC_CM, PCCT_INT);
E 36
					    }
					} else {
D 36
					    putleaf(P2ICON, q->range[0], 0,P2INT,0);
					    putop( P2LISTOP , P2INT );
					    putleaf(P2ICON, q->range[1], 0,P2INT,0);
					    putop( P2LISTOP , P2INT );
					    putleaf(P2ICON,aryconst(ctype,i),0,P2INT,0);
					    putop( P2LISTOP , P2INT );
E 36
I 36
					    putleaf(PCC_ICON, q->range[0], 0,PCCT_INT,0);
					    putop( PCC_CM , PCCT_INT );
					    putleaf(PCC_ICON, q->range[1], 0,PCCT_INT,0);
					    putop( PCC_CM , PCCT_INT );
					    putleaf(PCC_ICON,aryconst(ctype,i),0,PCCT_INT,0);
					    putop( PCC_CM , PCCT_INT );
E 36
					}
#					endif PC
					p1 = p1->chain->chain;
				    }
				}
			    }
E 34
			}
			break;
		case VAR:
			/*
			 * Value parameter
			 */
E 12
E 6
#			ifdef OBJ
D 6
			    q = rvalue(argv[1], p1->type , RREQ );
E 6
I 6
D 12
				q = rvalue(argv[1], p1->type , RREQ );
E 12
I 12
D 31
			    q = rvalue(argv[1], p1->type , RREQ );
E 31
I 31
			    q = rvalue(argv_node->list_node.list,
					p1->type , RREQ );
E 31
E 12
E 6
#			endif OBJ
#			ifdef PC
D 6
				/*
				 * structure arguments require lvalues,
				 * scalars use rvalue.
				 */
			    switch( classify( p1 -> type ) ) {
				case TFILE:
				case TARY:
				case TREC:
				case TSET:
				case TSTR:
				    q = rvalue( argv[1] , p1 -> type , LREQ );
E 6
I 6
D 12
				    /*
				     * structure arguments require lvalues,
				     * scalars use rvalue.
				     */
				switch( classify( p1 -> type ) ) {
				    case TFILE:
				    case TARY:
				    case TREC:
				    case TSET:
				    case TSTR:
					q = rvalue( argv[1] , p1 -> type , LREQ );
					break;
				    case TINT:
				    case TSCAL:
				    case TBOOL:
				    case TCHAR:
					precheck( p1 -> type , "_RANG4" , "_RSNG4" );
					q = rvalue( argv[1] , p1 -> type , RREQ );
					postcheck( p1 -> type );
					break;
				    default:
					q = rvalue( argv[1] , p1 -> type , RREQ );
					if (  isa( p1 -> type  , "d" )
					   && isa( q , "i" ) ) {
					    putop( P2SCONV , P2DOUBLE );
					}
					break;
				}
#			endif PC
			    if (q == NIL)
E 12
I 12
				/*
				 * structure arguments require lvalues,
				 * scalars use rvalue.
				 */
			    switch( classify( p1 -> type ) ) {
				case TFILE:
				case TARY:
				case TREC:
				case TSET:
				case TSTR:
D 26
				    q = rvalue( argv[1] , p1 -> type , LREQ );
E 26
I 26
D 31
				    q = stkrval( argv[1] , p1 -> type , LREQ );
E 31
I 31
				q = stkrval(argv_node->list_node.list,
						p1 -> type , (long) LREQ );
E 31
E 26
E 12
E 6
				    break;
D 6
				case TINT:
				case TSCAL:
				case TBOOL:
				case TCHAR:
				    precheck( p1 -> type , "_RANG4" , "_RSNG4" );
				    q = rvalue( argv[1] , p1 -> type , RREQ );
				    postcheck( p1 -> type );
E 6
I 6
D 12
			    if (incompat(q, p1->type, argv[1])) {
				    cerror("Expression type clashed with type of value parameter %s of %s", p1->symbol, p->symbol);
E 12
I 12
				case TINT:
				case TSCAL:
				case TBOOL:
				case TCHAR:
				    precheck( p1 -> type , "_RANG4" , "_RSNG4" );
D 26
				    q = rvalue( argv[1] , p1 -> type , RREQ );
				    postcheck( p1 -> type );
E 26
I 26
D 31
				    q = stkrval( argv[1] , p1 -> type , RREQ );
E 31
I 31
				q = stkrval(argv_node->list_node.list,
						p1 -> type , (long) RREQ );
E 31
D 27
				    postcheck(p1 -> type, P2INT);
E 27
I 27
				    postcheck(p1 -> type, nl+T4INT);
E 27
E 26
E 12
E 6
				    break;
I 26
				case TDOUBLE:
D 31
				    q = stkrval( argv[1] , p1 -> type , RREQ );
E 31
I 31
				q = stkrval(argv_node->list_node.list,
						p1 -> type , (long) RREQ );
E 31
D 36
				    sconv(p2type(q), P2DOUBLE);
E 36
I 36
				    sconv(p2type(q), PCCT_DOUBLE);
E 36
				    break;
E 26
I 12
				default:
D 31
				    q = rvalue( argv[1] , p1 -> type , RREQ );
E 31
I 31
				    q = rvalue(argv_node->list_node.list,
						p1 -> type , RREQ );
E 31
D 26
				    if (  isa( p1 -> type  , "d" )
				       && isa( q , "i" ) ) {
					putop( P2SCONV , P2DOUBLE );
				    }
E 26
				    break;
E 12
D 5
					/*
					 * and fall through
					 */
E 5
D 6
				default:
				    q = rvalue( argv[1] , p1 -> type , RREQ );
I 5
				    if (  isa( p1 -> type  , "d" )
				       && isa( q , "i" ) ) {
					putop( P2SCONV , P2DOUBLE );
				    }
E 5
				    break;
E 6
			    }
I 12
#			endif PC
			if (q == NIL) {
				chk = FALSE;
				break;
			}
D 31
			if (incompat(q, p1->type, argv[1])) {
E 31
I 31
			if (incompat(q, p1->type,
				argv_node->list_node.list)) {
E 31
				cerror("Expression type clashed with type of value parameter %s of %s", p1->symbol, p->symbol);
I 15
				chk = FALSE;
E 15
				break;
			}
E 12
D 6
#			endif PC
			if (q == NIL)
				break;
			if (incompat(q, p1->type, argv[1])) {
				cerror("Expression type clashed with type of value parameter %s of %s", p1->symbol, p->symbol);
				break;
			}
E 6
#			ifdef OBJ
D 6
			    if (isa(p1->type, "bcsi"))
				    rangechk(p1->type, q);
			    if (q->class != STR)
				    convert(q, p1->type);
E 6
I 6
D 12
				if (isa(p1->type, "bcsi"))
					rangechk(p1->type, q);
				if (q->class != STR)
					convert(q, p1->type);
E 12
I 12
			    if (isa(p1->type, "bcsi"))
				    rangechk(p1->type, q);
			    if (q->class != STR)
				    convert(q, p1->type);
E 12
E 6
#			endif OBJ
#			ifdef PC
D 6
			    switch( classify( p1 -> type ) ) {
				case TFILE:
				case TARY:
				case TREC:
				case TSET:
				case TSTR:
					putstrop( P2STARG
					    , p2type( p1 -> type )
					    , lwidth( p1 -> type )
					    , align( p1 -> type ) );
			    }
E 6
I 6
D 12
				switch( classify( p1 -> type ) ) {
				    case TFILE:
				    case TARY:
				    case TREC:
				    case TSET:
				    case TSTR:
					    putstrop( P2STARG
						, p2type( p1 -> type )
						, lwidth( p1 -> type )
						, align( p1 -> type ) );
				}
E 6
#			endif PC
D 6
			break;
		default:
			panic("call");
	    }
#	    ifdef PC
		    /*
		     *	if this is the nth (>1) argument,
		     *	hang it on the left linear list of arguments
		     */
		if ( firsttime ) {
			firsttime = FALSE;
		} else {
			putop( P2LISTOP , P2INT );
E 6
I 6
			    break;
		    case FFUNC:
			    /*
			     * function parameter
			     */
			    q = flvalue( (int *) argv[1] , FFUNC );
			    if (q == NIL)
				    break;
			    if (q != p1->type) {
				    error("Function type not identical to type of function parameter %s of %s", p1->symbol, p->symbol);
				    break;
E 12
I 12
			    switch( classify( p1 -> type ) ) {
				case TFILE:
				case TARY:
				case TREC:
				case TSET:
				case TSTR:
D 36
					putstrop( P2STARG
E 36
I 36
					putstrop( PCC_STARG
E 36
					    , p2type( p1 -> type )
D 31
					    , lwidth( p1 -> type )
E 31
I 31
					    , (int) lwidth( p1 -> type )
E 31
					    , align( p1 -> type ) );
E 12
			    }
D 12
			    break;
		    case FPROC:
			    /*
			     * procedure parameter
			     */
			    q = flvalue( (int *) argv[1] , FPROC );
			    if (q != NIL) {
				    error("Procedure parameter %s of %s cannot have a type", p1->symbol, p->symbol);
			    }
			    break;
		    default:
			    panic("call");
E 6
		}
I 6
#	    ifdef PC
E 12
I 12
#			endif PC
			break;
		case FFUNC:
E 12
			/*
D 12
			 *	if this is the nth (>1) argument,
			 *	hang it on the left linear list of arguments
E 12
I 12
			 * function parameter
E 12
			 */
D 8
		    if ( firsttime ) {
			    firsttime = FALSE;
E 8
I 8
D 12
		    if ( noarguments ) {
			    noarguments = FALSE;
E 8
		    } else {
			    putop( P2LISTOP , P2INT );
		    }
E 6
#	    endif PC
D 6
	    argv = argv[2];
E 6
I 6
		argv = argv[2];
	    }
	    if (argv != NIL) {
		    error("Too many arguments to %s", p->symbol);
		    rvlist(argv);
		    return (NIL);
	    }
	} else if ( p -> class == FFUNC || p -> class == FPROC ) {
		/*
		 *	formal routines can only have by-value parameters.
		 *	this will lose for integer actuals passed to real
		 *	formals, and strings which people want blank padded.
		 */
#	    ifdef OBJ
		cnt = 0;
#	    endif OBJ
	    for ( ; argv != NIL ; argv = argv[2] ) {
#		ifdef OBJ
		    q = rvalue(argv[1], NIL, RREQ );
D 9
		    cnt += even(lwidth(q));
E 9
I 9
		    cnt += leven(lwidth(q));
E 9
#		endif OBJ
#		ifdef PC
E 12
I 12
D 31
			q = flvalue( (int *) argv[1] , p1 );
			chk = (chk && fcompat(q, p1));
E 31
I 31
			q = flvalue(argv_node->list_node.list, p1 );
			/*chk = (chk && fcompat(q, p1));*/
			if ((chk) && (fcompat(q, p1)))
			    chk = TRUE;
			else
			    chk = FALSE;
E 31
			break;
		case FPROC:
E 12
			/*
D 12
			 * structure arguments require lvalues,
			 * scalars use rvalue.
E 12
I 12
			 * procedure parameter
E 12
			 */
D 12
		    codeoff();
		    p1 = rvalue( argv[1] , NIL , RREQ );
		    codeon();
		    switch( classify( p1 ) ) {
			case TSTR:
D 8
			    if ( p1 -> class == STR && slenflag == 0 ) {
				if ( opt( 's' ) ) {
				    standard();
				} else {
				    warning();
				}
E 8
I 8
			    if ( p1 -> class == STR && slenline != line ) {
				slenline = line;
				( opt( 's' ) ? (standard()): (warning()) );
E 8
				error("Implementation can't construct equal length strings");
D 8
				slenflag++;
E 8
			    }
			    /* and fall through */
			case TFILE:
			case TARY:
			case TREC:
			case TSET:
			    q = rvalue( argv[1] , p1 , LREQ );
			    break;
			case TINT:
D 8
			    if ( floatflag == 0 ) {
				if ( opt( 's' ) ) {
				    standard();
				} else {
				    warning();
				}
E 8
I 8
			    if ( floatline != line ) {
				floatline = line;
				( opt( 's' ) ? (standard()) : (warning()) );
E 8
				error("Implementation can't coerice integer to real");
D 8
				floatflag++;
E 8
			    }
			    /* and fall through */
			case TSCAL:
			case TBOOL:
			case TCHAR:
			default:
			    q = rvalue( argv[1] , p1 , RREQ );
			    break;
		    }
		    switch( classify( p1 ) ) {
			case TFILE:
			case TARY:
			case TREC:
			case TSET:
			case TSTR:
				putstrop( P2STARG , p2type( p1 ) ,
				    lwidth( p1 ) , align( p1 ) );
		    }
			/*
			 *	if this is the nth (>1) argument,
			 *	hang it on the left linear list of arguments
			 */
D 8
		    if ( firsttime ) {
			    firsttime = FALSE;
E 8
I 8
		    if ( noarguments ) {
			    noarguments = FALSE;
E 8
		    } else {
			    putop( P2LISTOP , P2INT );
		    }
#		endif PC
E 12
I 12
D 31
			q = flvalue( (int *) argv[1] , p1 );
			chk = (chk && fcompat(q, p1));
E 31
I 31
			q = flvalue(argv_node->list_node.list, p1 );
			/* chk = (chk && fcompat(q, p1)); */
			if ((chk) && (fcompat(q, p1)))
			    chk = TRUE;
			else chk = FALSE;
E 31
			break;
		default:
			panic("call");
E 12
	    }
D 12
	} else {
	    panic("call class");
E 12
I 12
#	    ifdef PC
		    /*
		     *	if this is the nth (>1) argument,
		     *	hang it on the left linear list of arguments
		     */
		if ( noarguments ) {
			noarguments = FALSE;
		} else {
D 36
			putop( P2LISTOP , P2INT );
E 36
I 36
			putop( PCC_CM , PCCT_INT );
E 36
		}
#	    endif PC
D 31
	    argv = argv[2];
E 31
I 31
	    argv_node = argv_node->list_node.next;
E 31
E 12
E 6
	}
I 12
D 31
	if (argv != NIL) {
E 31
I 31
	if (argv_node != TR_NIL) {
E 31
		error("Too many arguments to %s", p->symbol);
D 31
		rvlist(argv);
		return (NIL);
E 31
I 31
		rvlist(argv_node);
		return (NLNIL);
E 31
	}
	if (chk == FALSE)
D 31
		return NIL;
E 31
I 31
		return NLNIL;
E 31
E 12
D 6
	if (argv != NIL) {
		error("Too many arguments to %s", p->symbol);
		rvlist(argv);
		return (NIL);
	}
E 6
#	ifdef OBJ
D 6
	    put2(O_CALL | psbn << 8+INDX, p->entloc);
	    put2(O_POP, p->value[NL_OFFS]-DPOFF2);
E 6
I 6
	    if ( p -> class == FFUNC || p -> class == FPROC ) {
D 9
		put(2, PTR_RV | cbn << 8+INDX, p->value[NL_OFFS]);
		put(2, O_FCALL, cnt);
		put(2, O_FRTN, even(lwidth(p->type)));
E 9
I 9
D 14
		put(2, PTR_RV | cbn << 8+INDX, (int)p->value[NL_OFFS]);
E 14
I 14
D 31
		put(2, PTR_RV | psbn << 8+INDX, (int)p->value[NL_OFFS]);
I 24
 		put(2, O_LV | cbn << 8 + INDX ,
E 31
I 31
		(void) put(2, PTR_RV | psbn << 8+INDX, (int)p->value[NL_OFFS]);
 		(void) put(2, O_LV | cbn << 8 + INDX ,
E 31
 			(int) savedispnp -> value[ NL_OFFS ] );
E 24
I 18
D 19
		put(2, O_LV | cbn << 8 + INDX , (int) savedisp );
E 19
I 19
D 21
		put(2, O_LV | cbn << 8 + INDX ,
			(int) savedispnp -> value[ NL_OFFS ] );
E 21
E 19
E 18
E 14
D 12
		put(2, O_FCALL, (long)cnt);
E 12
I 12
D 31
		put(1, O_FCALL);
E 12
		put(2, O_FRTN, even(width(p->type)));
E 31
I 31
		(void) put(1, O_FCALL);
D 40
		(void) put(2, O_FRTN, even(width(p->type)));
E 40
I 40
		(void) put(2, O_FRTN, roundup(width(p->type), (long) A_STACK));
E 40
E 31
E 9
	    } else {
D 7
		put2(O_CALL | psbn << 8+INDX, p->entloc);
E 7
I 7
D 9
		/* put(2, O_CALL | psbn << 8+INDX, p->entloc); */
		put(2, O_CALL | psbn << 8, p->entloc);
E 9
I 9
D 12
		/* put(2, O_CALL | psbn << 8+INDX, (long)p->entloc); */
E 12
D 25
		put(2, O_CALL | psbn << 8, (long)p->entloc);
E 25
I 25
D 31
		put(2, O_CALL | psbn << 8, (long)p->value[NL_ENTLOC]);
E 31
I 31
		(void) put(2, O_CALL | psbn << 8, (long)p->value[NL_ENTLOC]);
E 31
E 25
E 9
E 7
	    }
E 6
#	endif OBJ
#	ifdef PC
I 8
		/*
I 18
		 *	for formal calls: add the hidden argument
		 *	which is the formal struct describing the
		 *	environment of the routine.
		 *	and the argument which is the address of the
		 *	space into which to save the display.
		 */
	    if ( p -> class == FFUNC || p -> class == FPROC ) {
D 19
		putRV( 0 , cbn , p -> value[ NL_OFFS ] , P2PTR|P2STRTY );
E 19
I 19
D 20
		putRV( 0 , cbn , p -> value[ NL_OFFS ] ,
E 20
I 20
D 22
		putRV( 0 , psbn , p -> value[ NL_OFFS ] ,
E 20
			p -> extra_flags , P2PTR|P2STRTY );
E 22
I 22
D 31
		putRV( 0 , cbn , tempdescrp -> value[ NL_OFFS ] ,
E 31
I 31
		putRV((char *) 0 , cbn , tempdescrp -> value[ NL_OFFS ] ,
E 31
D 36
			tempdescrp -> extra_flags , P2PTR|P2STRTY );
E 36
I 36
			tempdescrp -> extra_flags , PCCTM_PTR|PCCT_STRTY );
E 36
E 22
E 19
		if ( !noarguments ) {
D 36
		    putop( P2LISTOP , P2INT );
E 36
I 36
		    putop( PCC_CM , PCCT_INT );
E 36
		}
		noarguments = FALSE;
I 24
D 31
 		putLV( 0 , cbn , savedispnp -> value[ NL_OFFS ] ,
E 31
I 31
 		putLV((char *) 0 , cbn , savedispnp -> value[ NL_OFFS ] ,
E 31
D 36
 			savedispnp -> extra_flags , P2PTR | P2STRTY );
 		putop( P2LISTOP , P2INT );
E 36
I 36
 			savedispnp -> extra_flags , PCCTM_PTR | PCCT_STRTY );
 		putop( PCC_CM , PCCT_INT );
E 36
E 24
D 19
		putLV( 0 , cbn , savedisp , P2PTR | P2STRTY );
E 19
I 19
D 21
		putLV( 0 , cbn , savedispnp -> value[ NL_OFFS ] ,
			savedispnp -> extra_flags , P2PTR | P2STRTY );
E 19
		putop( P2LISTOP , P2INT );
E 21
	    }
		/*
E 18
		 *	do the actual call:
		 *	    either	... p( ... ) ...
D 18
		 *	    or		... ( ...() )( ... ) ...
E 18
I 18
D 22
		 *	    or		... ( p -> entryaddr )( ... ) ...
E 22
I 22
		 *	    or		... ( t -> entryaddr )( ... ) ...
E 22
E 18
		 *	and maybe an assignment.
		 */
E 8
	    if ( porf == FUNC ) {
D 8
		rettype = p2type( p -> type );
		switch ( classify( p -> type ) ) {
E 8
I 8
		switch ( p_type_class ) {
E 8
		    case TBOOL:
		    case TCHAR:
		    case TINT:
		    case TSCAL:
		    case TDOUBLE:
		    case TPTR:
D 6
			if ( p -> chain == NIL ) {
E 6
I 6
D 8
			if ( firsttime ) {
E 6
				putop( P2UNARY P2CALL , rettype );
			} else {
				putop( P2CALL , rettype );
E 8
I 8
D 36
			putop( ( noarguments ? P2UNARY P2CALL : P2CALL ) ,
E 36
I 36
			putop( ( noarguments ? PCCOM_UNARY PCC_CALL : PCC_CALL ) ,
E 36
D 31
				p_type_p2type );
E 31
I 31
				(int) p_type_p2type );
E 31
			if ( p -> class == FFUNC ) {
D 31
			    putop( P2ASSIGN , p_type_p2type );
E 31
I 31
D 36
			    putop( P2ASSIGN , (int) p_type_p2type );
E 36
I 36
			    putop( PCC_ASSIGN , (int) p_type_p2type );
E 36
E 31
E 8
			}
I 6
D 8
			if (p -> class == FFUNC || p -> class == FPROC ) {
			    putop( P2LISTOP , P2INT );
			    putop( P2CALL , rettype );
			}
E 8
E 6
			break;
		    default:
D 6
			if ( p -> chain == NIL ) {
E 6
I 6
D 8
			if ( firsttime ) {
E 6
				putstrop( P2UNARY P2STCALL
					, ADDTYPE( rettype , P2PTR )
					, lwidth( p -> type )
					, align( p -> type ) );
			} else {
				putstrop( P2STCALL
					, ADDTYPE( rettype , P2PTR )
					, lwidth( p -> type )
					, align( p -> type ) );
			}
I 6
			if (p -> class == FFUNC || p -> class == FPROC ) {
			    putop( P2LISTOP , P2INT );
			    putop( P2CALL , ADDTYPE( rettype , P2PTR ) );
			}
E 6
			putstrop( P2STASG , rettype , lwidth( p -> type )
E 8
I 8
D 36
			putstrop( ( noarguments ? P2UNARY P2STCALL : P2STCALL ),
D 31
				ADDTYPE( p_type_p2type , P2PTR ) ,
				p_type_width , p_type_align );
D 29
			putstrop( P2STASG , p_type_p2type , lwidth( p -> type )
E 8
				, align( p -> type ) );
E 29
I 29
			putstrop(P2STASG, ADDTYPE(p_type_p2type, P2PTR),
				lwidth(p -> type), align(p -> type));
E 31
I 31
				(int) ADDTYPE( p_type_p2type , P2PTR ) ,
E 36
I 36
			putstrop( ( noarguments ? PCCOM_UNARY PCC_STCALL : PCC_STCALL ),
				(int) PCCM_ADDTYPE( p_type_p2type , PCCTM_PTR ) ,
E 36
				(int) p_type_width ,(int) p_type_align );
D 36
			putstrop(P2STASG, (int) ADDTYPE(p_type_p2type, P2PTR),
E 36
I 36
			putstrop(PCC_STASG, (int) PCCM_ADDTYPE(p_type_p2type, PCCTM_PTR),
E 36
				(int) lwidth(p -> type), align(p -> type));
E 31
E 29
D 8
			putLV( 0 , cbn , temp , rettype );
			putop( P2COMOP , P2INT );
E 8
			break;
		}
	    } else {
D 6
		if ( p -> chain == NIL ) {
E 6
I 6
D 8
		if ( firsttime ) {
E 6
			putop( P2UNARY P2CALL , P2INT );
E 8
I 8
D 36
		putop( ( noarguments ? P2UNARY P2CALL : P2CALL ) , P2INT );
E 36
I 36
		putop( ( noarguments ? PCCOM_UNARY PCC_CALL : PCC_CALL ) , PCCT_INT );
E 36
	    }
		/*
D 22
		 *	... , FRTN( p ) ...
E 22
I 22
		 *	( t=p , ... , FRTN( t ) ...
E 22
		 */
	    if ( p -> class == FFUNC || p -> class == FPROC ) {
I 22
D 36
		putop( P2COMOP , P2INT );
E 22
		putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR ) ,
E 36
I 36
		putop( PCC_COMOP , PCCT_INT );
		putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR ) ,
E 36
			"_FRTN" );
D 14
		putRV( 0 , cbn , p -> value[ NL_OFFS ] , P2PTR | P2STRTY );
E 14
I 14
D 19
		putRV( 0 , psbn , p -> value[ NL_OFFS ] , P2PTR | P2STRTY );
I 18
		putLV( 0 , cbn , savedisp , P2PTR | P2STRTY );
E 19
I 19
D 22
		putRV( 0 , psbn , p -> value[ NL_OFFS ] ,
			p -> extra_flags , P2PTR | P2STRTY );
E 22
I 22
D 31
		putRV( 0 , cbn , tempdescrp -> value[ NL_OFFS ] ,
E 31
I 31
		putRV((char *) 0 , cbn , tempdescrp -> value[ NL_OFFS ] ,
E 31
D 36
			tempdescrp -> extra_flags , P2PTR | P2STRTY );
E 36
I 36
			tempdescrp -> extra_flags , PCCTM_PTR | PCCT_STRTY );
E 36
I 24
D 31
 		putLV( 0 , cbn , savedispnp -> value[ NL_OFFS ] ,
E 31
I 31
 		putLV((char *) 0 , cbn , savedispnp -> value[ NL_OFFS ] ,
E 31
D 36
 			savedispnp -> extra_flags , P2PTR | P2STRTY );
 		putop( P2LISTOP , P2INT );
E 24
E 22
D 21
		putLV( 0 , cbn , savedispnp -> value[ NL_OFFS ] ,
			savedispnp -> extra_flags , P2PTR | P2STRTY );
E 19
		putop( P2LISTOP , P2INT );
E 21
E 18
E 14
		putop( P2CALL , P2INT );
		putop( P2COMOP , P2INT );
E 36
I 36
 			savedispnp -> extra_flags , PCCTM_PTR | PCCT_STRTY );
 		putop( PCC_CM , PCCT_INT );
		putop( PCC_CALL , PCCT_INT );
		putop( PCC_COMOP , PCCT_INT );
E 36
	    }
		/*
		 *	if required:
		 *	either	... , temp )
		 *	or	... , &temp )
		 */
D 36
	    if ( porf == FUNC && temptype != P2UNDEF ) {
		if ( temptype != P2STRTY ) {
E 36
I 36
	    if ( porf == FUNC && temptype != PCCT_UNDEF ) {
		if ( temptype != PCCT_STRTY ) {
E 36
D 19
		    putRV( 0 , cbn , tempoffset , p_type_p2type );
E 19
I 19
D 31
		    putRV( 0 , cbn , tempnlp -> value[ NL_OFFS ] ,
			    tempnlp -> extra_flags , p_type_p2type );
E 31
I 31
		    putRV((char *) 0 , cbn , tempnlp -> value[ NL_OFFS ] ,
			    tempnlp -> extra_flags , (int) p_type_p2type );
E 31
E 19
E 8
		} else {
D 8
			putop( P2CALL , P2INT );
E 8
I 8
D 19
		    putLV( 0 , cbn , tempoffset , p_type_p2type );
E 19
I 19
D 31
		    putLV( 0 , cbn , tempnlp -> value[ NL_OFFS ] ,
			    tempnlp -> extra_flags , p_type_p2type );
E 31
I 31
		    putLV((char *) 0 , cbn , tempnlp -> value[ NL_OFFS ] ,
			    tempnlp -> extra_flags , (int) p_type_p2type );
E 31
E 19
E 8
I 6
		}
D 8
		if (p -> class == FFUNC || p -> class == FPROC ) {
		    putop( P2LISTOP , P2INT );
		    putop( P2CALL , P2INT );
E 6
		}
E 8
I 8
D 36
		putop( P2COMOP , P2INT );
E 36
I 36
		putop( PCC_COMOP , PCCT_INT );
E 36
	    }
	    if ( porf == PROC ) {
E 8
		putdot( filename , line );
	    }
#	endif PC
	return (p->type);
}

rvlist(al)
D 31
	register int *al;
E 31
I 31
	register struct tnode *al;
E 31
{

D 31
	for (; al != NIL; al = al[2])
		rvalue( (int *) al[1], NLNIL , RREQ );
E 31
I 31
	for (; al != TR_NIL; al = al->list_node.next)
		(void) rvalue( al->list_node.list, NLNIL , RREQ );
E 31
I 12
}

    /*
     *	check that two function/procedure namelist entries are compatible
     */
bool
fcompat( formal , actual )
    struct nl	*formal;
    struct nl	*actual;
{
    register struct nl	*f_chain;
    register struct nl	*a_chain;
I 31
    extern struct nl	*plist();
E 31
    bool compat = TRUE;

D 31
    if ( formal == NIL || actual == NIL ) {
E 31
I 31
    if ( formal == NLNIL || actual == NLNIL ) {
E 31
	return FALSE;
    }
    for (a_chain = plist(actual), f_chain = plist(formal);
D 31
         f_chain != NIL;
E 31
I 31
         f_chain != NLNIL;
E 31
	 f_chain = f_chain->chain, a_chain = a_chain->chain) {
	if (a_chain == NIL) {
	    error("%s %s declared on line %d has more arguments than",
		parnam(formal->class), formal->symbol,
D 31
		linenum(formal));
E 31
I 31
		(char *) linenum(formal));
E 31
	    cerror("%s %s declared on line %d",
		parnam(actual->class), actual->symbol,
D 31
		linenum(actual));
E 31
I 31
		(char *) linenum(actual));
E 31
	    return FALSE;
	}
	if ( a_chain -> class != f_chain -> class ) {
	    error("%s parameter %s of %s declared on line %d is not identical",
		parnam(f_chain->class), f_chain->symbol,
D 31
		formal->symbol, linenum(formal));
E 31
I 31
		formal->symbol, (char *) linenum(formal));
E 31
	    cerror("with %s parameter %s of %s declared on line %d",
		parnam(a_chain->class), a_chain->symbol,
D 31
		actual->symbol, linenum(actual));
E 31
I 31
		actual->symbol, (char *) linenum(actual));
E 31
	    compat = FALSE;
	} else if (a_chain->class == FFUNC || a_chain->class == FPROC) {
D 31
	    compat = (compat && fcompat(f_chain, a_chain));
E 31
I 31
	    /*compat = (compat && fcompat(f_chain, a_chain));*/
	    if ((compat) && (fcompat(f_chain, a_chain)))
		compat = TRUE;
	    else compat = FALSE;
E 31
	}
	if ((a_chain->class != FPROC && f_chain->class != FPROC) &&
	    (a_chain->type != f_chain->type)) {
	    error("Type of %s parameter %s of %s declared on line %d is not identical",
		parnam(f_chain->class), f_chain->symbol,
D 31
		formal->symbol, linenum(formal));
E 31
I 31
		formal->symbol, (char *) linenum(formal));
E 31
	    cerror("to type of %s parameter %s of %s declared on line %d",
		parnam(a_chain->class), a_chain->symbol,
D 31
		actual->symbol, linenum(actual));
E 31
I 31
		actual->symbol, (char *) linenum(actual));
E 31
	    compat = FALSE;
	}
    }
    if (a_chain != NIL) {
	error("%s %s declared on line %d has fewer arguments than",
	    parnam(formal->class), formal->symbol,
D 31
	    linenum(formal));
E 31
I 31
	    (char *) linenum(formal));
E 31
	cerror("%s %s declared on line %d",
	    parnam(actual->class), actual->symbol,
D 31
	    linenum(actual));
E 31
I 31
	    (char *) linenum(actual));
E 31
	return FALSE;
    }
    return compat;
}

char *
parnam(nltype)
    int nltype;
{
    switch(nltype) {
	case REF:
	    return "var";
	case VAR:
	    return "value";
	case FUNC:
	case FFUNC:
	    return "function";
	case PROC:
	case FPROC:
	    return "procedure";
	default:
	    return "SNARK";
    }
}

D 31
plist(p)
E 31
I 31
struct nl *plist(p)
E 31
    struct nl *p;
{
    switch (p->class) {
	case FFUNC:
	case FPROC:
	    return p->ptr[ NL_FCHAIN ];
	case PROC:
	case FUNC:
	    return p->chain;
	default:
D 31
	    panic("plist");
E 31
I 31
	    {
		panic("plist");
		return(NLNIL); /* this is here only so lint won't complain
				  panic actually aborts */
	    }

E 31
    }
}

linenum(p)
    struct nl *p;
{
    if (p->class == FUNC)
	return p->ptr[NL_FVAR]->value[NL_LINENO];
    return p->value[NL_LINENO];
E 12
}
E 1
