h40076
s 00007/00003/00105
d D 5.1 85/06/05 14:15:20 dist 19 18
c Add copyright
e
s 00009/00009/00099
d D 2.2 85/03/20 15:01:24 ralph 18 17
c changes from donn@utah-cs for common header file for pcc
e
s 00000/00000/00108
d D 2.1 84/02/08 20:50:43 aoki 17 16
c synchronize to version 2
e
s 00000/00000/00108
d D 1.15 83/09/19 06:58:34 thien 16 15
c Restoring to unlinted version
e
s 00023/00020/00085
d D 1.14 83/08/19 04:57:22 thien 15 14
c The changes were made to allow successful linting
e
s 00001/00000/00104
d D 1.13 83/02/28 17:16:11 peter 14 13
c clean up temporary allocation, moving everything relevant to
c tmps.c and (new) tmps.h.  correctly emit LBRAC lines.  allocate registers
c from high to low.  put in data structures for multiple types of registers.
e
s 00001/00001/00103
d D 1.12 82/08/26 18:48:24 mckusick 13 12
c convert namelist structure to use unions
e
s 00001/00002/00103
d D 1.11 81/07/23 14:49:04 mckusic 12 10
c align temporaries
e
s 00002/00001/00104
d R 1.11 81/06/08 13:06:40 mckusic 11 10
c put display save area back into formal routine structure
e
s 00007/00004/00098
d D 1.10 81/06/01 15:36:20 peter 10 9
c add storage classes to namelist, and use them.
e
s 00006/00019/00096
d D 1.9 81/04/01 21:51:45 peter 9 8
c dynamically allocate display save areas before formal calls
e
s 00005/00017/00110
d D 1.8 81/03/24 17:52:45 peter 8 7
c add sextname() to make up long external names for things.
e
s 00002/00002/00125
d D 1.7 81/03/18 21:17:45 mckusic 7 6
c mods for new formal routine syntax
e
s 00002/00009/00125
d D 1.6 81/03/11 23:37:30 mckusic 6 5
c centralize temporary allocation in tmps.c
e
s 00005/00005/00129
d D 1.5 81/03/08 19:25:35 mckusic 5 4
c merge in onyx changes
e
s 00002/00001/00132
d D 1.4 81/01/10 17:00:05 mckusic 4 3
c convert to "fp", "ap" type display; fix SUCC and PRED
e
s 00003/00003/00130
d D 1.3 81/01/06 17:15:13 mckusic 3 2
c modify to allow use of px written in `C' and the use of libpc
e
s 00039/00027/00094
d D 1.2 80/10/03 01:10:10 peter 2 1
c Implement formal functions and procedures
e
s 00121/00000/00000
d D 1.1 80/09/24 19:26:29 peter 1 0
c date and time created 80/09/24 19:26:29 by peter
e
u
U
t
T
I 1
D 19
/* Copyright (c) 1980 Regents of the University of California */
E 19
I 19
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 19

I 15
#ifndef lint
E 15
D 5
static	char sccsid[] = "%Z%%M% %I% %G%";
E 5
I 5
D 19
static char sccsid[] = "%Z%%M% %I% %G%";
I 15
#endif
E 19
I 19
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 19
E 15
E 5

#include "whoami.h"
#include "0.h"
#include "tree.h"
#include "opcode.h"
#include "objfmt.h"
I 15
#include "tree_ty.h"
E 15
#ifdef PC
#   include "pc.h"
D 18
#   include "pcops.h"
E 18
I 18
#   include <pcc.h>
E 18
#endif PC
I 14
#include "tmps.h"
E 14
I 2
D 9
#ifdef OBJ
/*
D 3
 * define the display structure for purposes of allocating
 * a temporary
E 3
I 3
 * runtime display structure
E 3
 */
struct dispsave {
D 3
	char	*ptr;
E 3
I 3
	char *locvars;		/* pointer to local variables */
	struct stack *stp;	/* pointer to local stack frame */
E 3
};
#endif OBJ
E 9
E 2

    /*
     *	flvalue generates the code to either pass on a formal routine,
     *	or construct the structure which is the environment for passing.
     *	it tells the difference by looking at the tree it's given.
     */
struct nl *
D 2
flvalue( r )
    int	*r;
E 2
I 2
flvalue( r , formalp )
D 15
    int		*r;
E 15
I 15
    struct tnode *r; 	/* T_VAR */
E 15
    struct nl	*formalp;
E 2
    {
	struct nl	*p;
D 10
	long		tempoff;
E 10
I 10
	struct nl	*tempnlp;
E 10
I 2
	char		*typename;
I 8
#ifdef PC
	char		extname[ BUFSIZ ];
#endif PC
E 8
E 2

D 15
	if ( r == NIL ) {
	    return NIL;
E 15
I 15
	if ( r == TR_NIL ) {
	    return NLNIL;
E 15
	}
I 2
	typename = formalp -> class == FFUNC ? "function":"procedure";
D 15
	if ( r[0] != T_VAR ) {
E 15
I 15
	if ( r->tag != T_VAR ) {
E 15
	    error("Expression given, %s required for %s parameter %s" ,
		    typename , typename , formalp -> symbol );
D 15
	    return NIL;
E 15
I 15
	    return NLNIL;
E 15
	}
E 2
D 15
	p = lookup(r[2]);
	if (p == NIL) {
D 2
		return NIL;
E 2
I 2
	    return NIL;
E 15
I 15
	p = lookup(r->var_node.cptr);
	if (p == NLNIL) {
	    return NLNIL;
E 15
E 2
	}
D 2
	switch ( r[0] ) {
	    case T_FFUNC:
E 2
I 2
	switch ( p -> class ) {
	    case FFUNC:
	    case FPROC:
E 2
D 15
		    if ( r[3] != NIL ) {
E 15
I 15
		    if ( r->var_node.qual != TR_NIL ) {
E 15
D 2
			error("Formal function %s cannot be qualified" ,
				p -> symbol );
E 2
I 2
			error("Formal %s %s cannot be qualified" ,
				typename , p -> symbol );
E 2
D 15
			return NIL;
E 15
I 15
			return NLNIL;
E 15
		    }
D 2
		    goto froutine;
	    case T_FPROC:
		    if ( r[3] != NIL ) {
			error("Formal procedure %s cannot be qualified" ,
				p -> symbol );
			return NIL;
		    }
	    froutine:
E 2
#		    ifdef OBJ
D 5
			put( 2 , PTR_RV | bn << 8+INDX , p -> value[NL_OFFS] );
E 5
I 5
D 15
			put(2, PTR_RV | bn << 8+INDX, (int)p->value[NL_OFFS]);
E 15
I 15
			(void) put(2, PTR_RV | bn << 8+INDX, (int)p->value[NL_OFFS]);
E 15
E 5
#		    endif OBJ
#		    ifdef PC
			putRV( p -> symbol , bn , p -> value[ NL_OFFS ] , 
I 10
				p -> extra_flags ,
E 10
				p2type( p ) );
#		    endif PC
D 7
		    return p -> type;
E 7
I 7
		    return p;
E 7
D 2
	    case T_FUNC:
E 2
I 2
	    case FUNC:
	    case PROC:
E 2
D 15
		    if ( r[3] != NIL ) {
E 15
I 15
		    if ( r->var_node.qual != TR_NIL ) {
E 15
D 2
			error("Function %s cannot be qualified" , p -> symbol );
E 2
I 2
			error("%s %s cannot be qualified" , typename ,
				p -> symbol );
E 2
D 15
			return NIL;
E 15
I 15
			return NLNIL;
E 15
		    }
D 2
		    goto routine;
	    case T_PROC:
		    if ( r[3] != NIL ) {
			error("Procedure %s cannot be qualified", p -> symbol );
E 2
I 2
		    if (bn == 0) {
			error("Built-in %s %s cannot be passed as a parameter" ,
				typename , p -> symbol );
E 2
D 15
			return NIL;
E 15
I 15
			return NLNIL;
E 15
		    }
D 2
	    routine:
E 2
			/*
D 9
			 *	formal routine structure:
			 *
			 *	struct formalrtn {
			 *		long		(*entryaddr)();
			 *		long		cbn;
			 *		struct dispsave	disp[2*MAXLVL];
			 *	};
E 9
I 9
			 *	allocate space for the thunk
E 9
			 */
D 2
		    sizes[ cbn ].om_off -=	  sizeof (long (*()))
E 2
I 2
D 6
		    sizes[ cbn ].om_off -=	  sizeof (long (*)())
E 2
						+ sizeof (long)
						+ 2*bn*sizeof (struct dispsave);
		    tempoff = sizes[ cbn ].om_off;
		    if ( sizes[ cbn ].om_off < sizes[ cbn ].om_max ) {
			sizes[ cbn ].om_max = tempoff;
		    }
E 6
I 6
D 9
		    tempoff = tmpalloc(sizeof (long (*)()) + sizeof (long)
			+ 2*bn*sizeof (struct dispsave), nl+TSTR, NOREG);
E 9
I 9
D 10
		    tempoff = tmpalloc( sizeof ( struct formalrtn ) ,
E 10
I 10
D 12
		    tempnlp = tmpalloc( sizeof ( struct formalrtn ) ,
E 10
				nl+TSTR, NOREG);
E 12
I 12
D 15
		    tempnlp = tmpalloc(sizeof(struct formalrtn), NIL, NOREG);
E 15
I 15
		    tempnlp = tmpalloc((long) (sizeof(struct formalrtn)), NLNIL, NOREG);
E 15
E 12
E 9
E 6
#		    ifdef OBJ
D 2
			put( 2 , PTR_LV | cbn << 8 + INDX , tempoff );
E 2
I 2
D 5
			put( 2 , O_LV | cbn << 8 + INDX , tempoff );
E 2
D 4
			put( 2 , O_FSAV | bn << 8 + INDX , p -> entloc );
E 4
I 4
			/* put( 2 , O_FSAV | bn << 8 + INDX , p -> entloc ); */
			put( 2 , O_FSAV | bn << 8 , p -> entloc );
E 5
I 5
D 10
			put(2 , O_LV | cbn << 8 + INDX , (int)tempoff );
E 10
I 10
D 15
			put(2 , O_LV | cbn << 8 + INDX ,
E 15
I 15
			(void) put(2 , O_LV | cbn << 8 + INDX ,
E 15
				(int)tempnlp -> value[ NL_OFFS ] );
E 10
D 6
			/* put(2, O_FSAV | bn << 8 + INDX, (long)p->entloc); */
E 6
D 13
			put(2, O_FSAV | bn << 8, (long)p->entloc);
E 13
I 13
D 15
			put(2, O_FSAV | bn << 8, (long)p->value[NL_ENTLOC]);
E 15
I 15
			(void) put(2, O_FSAV | bn << 8, (long)p->value[NL_ENTLOC]);
E 15
E 13
E 5
E 4
#		    endif OBJ
#		    ifdef PC
D 6
			putlbracket( ftnno , -tempoff );
E 6
D 18
			putleaf( P2ICON , 0 , 0 ,
D 2
			    ADDTYPE( P2PTR , ADDTYPE( P2FTN , P2PTR|P2STR ) ) ,
E 2
I 2
			    ADDTYPE( P2PTR , ADDTYPE( P2FTN , P2PTR|P2STRTY ) ) ,
E 18
I 18
			putleaf( PCC_ICON , 0 , 0 ,
			    PCCM_ADDTYPE( PCCTM_PTR , PCCM_ADDTYPE( PCCTM_FTN , PCCTM_PTR|PCCT_STRTY ) ) ,
E 18
E 2
			    "_FSAV" );
D 8
			{
			    char	extname[ BUFSIZ ];
			    char	*starthere;
			    int		i;

			    starthere = &extname[0];
			    for ( i = 1 ; i < bn ; i++ ) {
				sprintf( starthere , EXTFORMAT , enclosing[ i ] );
				starthere += strlen( enclosing[ i ] ) + 1;
			    }
			    sprintf( starthere , EXTFORMAT , p -> symbol );
			    starthere += strlen( p -> symbol ) + 1;
			    if ( starthere >= &extname[ BUFSIZ ] ) {
				panic( "flvalue namelength" );
			    }
			    putleaf( P2ICON , 0 , 0 , p2type( p ) , extname );
			}
E 8
I 8
D 9
			sextname( extname , p -> symbol , bn );
E 9
I 9
			sprintf( extname , "%s" , FORMALPREFIX );
			sextname( &extname[ strlen( extname ) ] ,
				    p -> symbol , bn );
E 9
D 18
			putleaf( P2ICON , 0 , 0 , p2type( p ) , extname );
E 8
D 15
			putleaf( P2ICON , bn , 0 , P2INT , 0 );
E 15
I 15
			putleaf( P2ICON , bn , 0 , P2INT , (char *) 0 );
E 15
			putop( P2LISTOP , P2INT );
E 18
I 18
			putleaf( PCC_ICON , 0 , 0 , p2type( p ) , extname );
			putleaf( PCC_ICON , bn , 0 , PCCT_INT , (char *) 0 );
			putop( PCC_CM , PCCT_INT );
E 18
D 2
			putLV( 0 , cbn , tempoff , P2STR );
E 2
I 2
D 10
			putLV( 0 , cbn , tempoff , P2STRTY );
E 10
I 10
D 15
			putLV( 0 , cbn , tempnlp -> value[NL_OFFS] ,
E 15
I 15
			putLV( (char *) 0 , cbn , tempnlp -> value[NL_OFFS] ,
E 15
D 18
				tempnlp -> extra_flags , P2STRTY );
E 10
E 2
			putop( P2LISTOP , P2INT );
			putop( P2CALL , P2PTR | P2STRTY );
E 18
I 18
				tempnlp -> extra_flags , PCCT_STRTY );
			putop( PCC_CM , PCCT_INT );
			putop( PCC_CALL , PCCTM_PTR | PCCT_STRTY );
E 18
#		    endif PC
D 7
		    return p -> type;
E 7
I 7
		    return p;
E 7
	    default:
D 2
		    panic("flvalue");
E 2
I 2
		    error("Variable given, %s required for %s parameter %s" ,
			    typename , typename , formalp -> symbol );
D 15
		    return NIL;
E 15
I 15
		    return NLNIL;
E 15
E 2
	}
    }
E 1
