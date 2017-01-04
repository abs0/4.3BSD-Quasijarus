h57228
s 00008/00003/00385
d D 5.1 85/06/05 14:41:17 dist 12 11
c Add copyright
e
s 00015/00015/00373
d D 2.2 85/03/20 15:03:45 ralph 11 10
c changes from donn@utah-cs for common header file for pcc
e
s 00000/00000/00388
d D 2.1 84/02/08 20:46:08 aoki 10 9
c synchronize to version 2
e
s 00013/00000/00375
d D 1.9 84/02/08 20:11:29 aoki 9 8
c generate errors for too few subscripts and suppress
c any subsequent errors due to subscripting mistakes.
e
s 00025/00006/00350
d D 1.8 84/02/08 00:40:49 mckusick 8 7
c merge in conformant array code by Carol Nishizak
e
s 00001/00002/00355
d D 1.7 84/02/07 13:36:18 mckusick 7 6
c lint
e
s 00000/00000/00357
d D 1.6 83/09/19 06:59:39 thien 6 5
c Restoring to unlinted version
e
s 00060/00053/00297
d D 1.5 83/08/19 04:59:48 thien 5 4
c The changes were made to allow successful linting
e
s 00012/00008/00338
d D 1.4 81/06/01 15:38:29 peter 4 3
c add storage classes to namelist, and use them.
e
s 00001/00001/00345
d D 1.3 81/04/21 15:06:17 peter 3 2
c clean up for loop code
e
s 00011/00005/00335
d D 1.2 81/03/26 17:31:39 peter 2 1
c be more clever about getting rvalues to avoid lvalues of registers.
e
s 00340/00000/00000
d D 1.1 80/08/27 19:55:46 peter 1 0
c date and time created 80/08/27 19:55:46 by peter
e
u
U
t
T
I 1
D 12
/* Copyright (c) 1979 Regents of the University of California */
E 12
I 12
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 12

I 5
#ifndef lint
E 5
D 12
static	char sccsid[] = "%Z%%M% %I% %G%";
I 5
#endif
E 12
I 12
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 12
E 5

#include "whoami.h"
#include "0.h"
#include "tree.h"
#include "opcode.h"
#include "objfmt.h"
I 5
#include "tree_ty.h"
E 5
#ifdef PC
	/*
	 *	and the rest of the file
	 */
#   include	"pc.h"
D 11
#   include	"pcops.h"
E 11
I 11
#   include	<pcc.h>
E 11

extern	int flagwas;
/*
 * pclvalue computes the address
 * of a qualified name and
 * leaves it on the stack.
 * for pc, it can be asked for either an lvalue or an rvalue.
 * the semantics are the same, only the code is different.
 * for putting out calls to check for nil and fnil,
 * we have to traverse the list of qualifications twice:
 * once to put out the calls and once to put out the address to be checked.
 */
struct nl *
D 5
pclvalue( r , modflag , required )
	int	*r;
E 5
I 5
pclvalue( var , modflag , required )
	struct tnode	*var;
E 5
	int	modflag;
	int	required;
{
	register struct nl	*p;
D 5
	register		*c, *co;
E 5
I 5
	register struct tnode 	*c, *co;
E 5
	int			f, o;
D 5
	int			tr[2], trp[3];
	struct nl		*firstp;
	struct nl		*lastp;
E 5
I 5
	struct tnode		l_node, tr;
	VAR_NODE		*v_node;
	LIST_NODE		*tr_ptr;
D 7
	struct nl		*firstp, *lastp;
E 7
I 7
D 8
	struct nl		*firstp;
E 8
I 8
	struct nl		*firstp, *lastp;
E 8
E 7
E 5
	char			*firstsymbol;
I 4
	char			firstextra_flags;
E 4
	int			firstbn;
I 8
	int			s;
E 8

D 5
	if ( r == NIL ) {
		return NIL;
E 5
I 5
	if ( var == TR_NIL ) {
		return NLNIL;
E 5
	}
D 5
	if ( nowexp( r ) ) {
		return NIL;
E 5
I 5
	if ( nowexp( var ) ) {
		return NLNIL;
E 5
	}
D 5
	if ( r[0] != T_VAR ) {
E 5
I 5
	if ( var->tag != T_VAR ) {
E 5
		error("Variable required");	/* Pass mesgs down from pt of call ? */
D 5
		return NIL;
E 5
I 5
		return NLNIL;
E 5
	}
D 5
	firstp = p = lookup( r[2] );
	if ( p == NIL ) {
		return NIL;
E 5
I 5
	v_node = &(var->var_node);
	firstp = p = lookup( v_node->cptr );
	if ( p == NLNIL ) {
		return NLNIL;
E 5
	}
	firstsymbol = p -> symbol;
	firstbn = bn;
I 4
	firstextra_flags = p -> extra_flags;
E 4
D 5
	c = r[3];
E 5
I 5
	c = v_node->qual;
E 5
	if ( ( modflag & NOUSE ) && ! lptr( c ) ) {
		p -> nl_flags = flagwas;
	}
	if ( modflag & MOD ) {
		p -> nl_flags |= NMOD;
	}
	/*
	 * Only possibilities for p -> class here
	 * are the named classes, i.e. CONST, TYPE
	 * VAR, PROC, FUNC, REF, or a WITHPTR.
	 */
I 5
	 tr_ptr = &(l_node.list_node);
E 5
	if ( p -> class == WITHPTR ) {
		/*
		 * Construct the tree implied by
		 * the with statement
		 */
D 5
	    trp[0] = T_LISTPP;
	    trp[1] = tr;
	    trp[2] = r[3];
	    tr[0] = T_FIELD;
	    tr[1] = r[2];
	    c = trp;
E 5
I 5
	    l_node.tag = T_LISTPP;
	    tr_ptr->list = &(tr);
	    tr_ptr->next = v_node->qual;
	    tr.tag = T_FIELD;
	    tr.field_node.id_ptr = v_node->cptr;
	    c = &(l_node);
E 5
	}
	    /*
	     *	this not only puts out the names of functions to call
	     *	but also does all the semantic checking of the qualifications.
	     */
D 5
	if ( ! nilfnil( p , c , modflag , firstp , r[2] ) ) {
	    return NIL;
E 5
I 5
	if ( ! nilfnil( p , c , modflag , firstp , v_node->cptr ) ) {
	    return NLNIL;
E 5
	}
	switch (p -> class) {
		case WITHPTR:
		case REF:
			/*
			 * Obtain the indirect word
			 * of the WITHPTR or REF
			 * as the base of our lvalue
			 */
D 4
			putRV( firstsymbol , firstbn , p -> value[ 0 ]
				    , p2type( p ) );
E 4
I 4
			putRV( firstsymbol , firstbn , p -> value[ 0 ] ,
				firstextra_flags , p2type( p ) );
E 4
			firstsymbol = 0;
			f = 0;		/* have an lv on stack */
			o = 0;
			break;
		case VAR:
D 8
			f = 1;		/* no lv on stack yet */
			o = p -> value[0];
E 8
I 8
			if (p->type->class != CRANGE) {
				f = 1;		/* no lv on stack yet */
				o = p -> value[0];
			} else {
				error("Conformant array bound %s found where variable required", p->symbol);
				return(NIL);
			}
E 8
			break;
		default:
			error("%s %s found where variable required", classes[p -> class], p -> symbol);
D 5
			return (NIL);
E 5
I 5
			return (NLNIL);
E 5
	}
	/*
	 * Loop and handle each
	 * qualification on the name
	 */
D 2
	if ( c == NIL && ( modflag & ASGN ) && p -> value[ NL_FORV ] ) {
E 2
I 2
	if ( c == NIL &&
	    ( modflag & ASGN ) &&
D 3
	    ( p -> value[ NL_FORV ] & FORBOUND ) ) {
E 3
I 3
	    ( p -> value[ NL_FORV ] & FORVAR ) ) {
E 3
E 2
		error("Can't modify the for variable %s in the range of the loop", p -> symbol);
D 5
		return (NIL);
E 5
I 5
		return (NLNIL);
E 5
	}
I 8
	s = 0;
E 8
D 5
	for ( ; c != NIL ; c = c[2] ) {
		co = c[1];
		if ( co == NIL ) {
			return NIL;
E 5
I 5
	for ( ; c != TR_NIL ; c = c->list_node.next ) {
		co = c->list_node.list;
		if ( co == TR_NIL ) {
			return NLNIL;
E 5
		}
I 8
		lastp = p;
E 8
D 7
		lastp = p;
E 7
		p = p -> type;
D 5
		if ( p == NIL ) {
			return NIL;
E 5
I 5
		if ( p == NLNIL ) {
			return NLNIL;
E 5
		}
I 9
		/*
		 * If we haven't seen enough subscripts, and the next
		 * qualification isn't array reference, then it's an error.
		 */
		if (s && co->tag != T_ARY) {
			error("Too few subscripts (%d given, %d required)",
				s, p->value[0]);
		}
E 9
D 5
		switch ( co[0] ) {
E 5
I 5
		switch ( co->tag ) {
E 5
			case T_PTR:
				/*
				 * Pointer qualification.
				 */
				if ( f ) {
D 4
					putLV( firstsymbol , firstbn , o
					       , p2type( p ) );
E 4
I 4
					putLV( firstsymbol , firstbn , o ,
					    firstextra_flags , p2type( p ) );
E 4
					firstsymbol = 0;
				} else {
					if (o) {
D 11
					    putleaf( P2ICON , o , 0 , P2INT
E 11
I 11
					    putleaf( PCC_ICON , o , 0 , PCCT_INT
E 11
D 5
						    , 0 );
E 5
I 5
						    , (char *) 0 );
E 5
D 11
					    putop( P2PLUS , P2PTR | P2CHAR );
E 11
I 11
					    putop( PCC_PLUS , PCCTM_PTR | PCCT_CHAR );
E 11
					}
				}
				    /*
				     * Pointer cannot be
				     * nil and file cannot
				     * be at end-of-file.
				     * the appropriate function name is 
				     * already out there from nilfnil.
				     */
				if ( p -> class == PTR ) {
					/*
					 * this is the indirection from
					 * the address of the pointer 
					 * to the pointer itself.
					 * kirk sez:
					 * fnil doesn't want this.
					 * and does it itself for files
					 * since only it knows where the
					 * actual window is.
					 * but i have to do this for
					 * regular pointers.
					 */
D 11
				    putop( P2UNARY P2MUL , p2type( p ) );
E 11
I 11
				    putop( PCCOM_UNARY PCC_MUL , p2type( p ) );
E 11
				    if ( opt( 't' ) ) {
D 11
					putop( P2CALL , P2INT );
E 11
I 11
					putop( PCC_CALL , PCCT_INT );
E 11
				    }
				} else {
D 11
				    putop( P2CALL , P2INT );
E 11
I 11
				    putop( PCC_CALL , PCCT_INT );
E 11
				}
				f = o = 0;
				continue;
			case T_ARGL:
			case T_ARY:
				if ( f ) {
D 4
					putLV( firstsymbol , firstbn , o
						, p2type( p ) );
E 4
I 4
					putLV( firstsymbol , firstbn , o ,
					    firstextra_flags , p2type( p ) );
E 4
					firstsymbol = 0;
				} else {
					if (o) {
D 11
					    putleaf( P2ICON , o , 0 , P2INT
E 11
I 11
					    putleaf( PCC_ICON , o , 0 , PCCT_INT
E 11
D 5
						    , 0 );
E 5
I 5
						    , (char *) 0 );
E 5
D 11
					    putop( P2PLUS , P2INT );
E 11
I 11
					    putop( PCC_PLUS , PCCT_INT );
E 11
					}
				}
D 5
				arycod( p , co[1] );
E 5
I 5
D 8
				(void) arycod( p , co->ary_node.expr_list );
E 8
I 8
				s = arycod( p , co->ary_node.expr_list, s);
				if (s == p->value[0]) {
					s = 0;
				} else {
					p = lastp;
				}
E 8
E 5
				f = o = 0;
				continue;
			case T_FIELD:
				/*
				 * Field names are just
				 * an offset with some 
				 * semantic checking.
				 */
D 5
				p = reclook(p, co[1]);
E 5
I 5
				p = reclook(p, co->field_node.id_ptr);
E 5
				o += p -> value[0];
				continue;
			default:
				panic("lval2");
		}
I 9
	}
	if (s) {
		error("Too few subscripts (%d given, %d required)",
			s, p->type->value[0]);
		return NLNIL;
E 9
	}
	if (f) {
D 2
		putLV( firstsymbol , firstbn , o , p2type( p -> type ) );
E 2
I 2
		if ( required == LREQ ) {
D 4
		    putLV( firstsymbol , firstbn , o , p2type( p -> type ) );
E 4
I 4
		    putLV( firstsymbol , firstbn , o ,
			    firstextra_flags , p2type( p -> type ) );
E 4
		} else {
D 4
		    putRV( firstsymbol , firstbn , o , p2type( p -> type ) );
E 4
I 4
		    putRV( firstsymbol , firstbn , o ,
			    firstextra_flags , p2type( p -> type ) );
E 4
		}
E 2
	} else {
		if (o) {
D 5
		    putleaf( P2ICON , o , 0 , P2INT , 0 );
E 5
I 5
D 11
		    putleaf( P2ICON , o , 0 , P2INT , (char *) 0 );
E 5
		    putop( P2PLUS , P2INT );
E 11
I 11
		    putleaf( PCC_ICON , o , 0 , PCCT_INT , (char *) 0 );
		    putop( PCC_PLUS , PCCT_INT );
E 11
		}
D 2
	}
	if ( required == RREQ ) {
	    putop( P2UNARY P2MUL , p2type( p -> type ) );
E 2
I 2
		if ( required == RREQ ) {
D 11
		    putop( P2UNARY P2MUL , p2type( p -> type ) );
E 11
I 11
		    putop( PCCOM_UNARY PCC_MUL , p2type( p -> type ) );
E 11
		}
E 2
	}
	return ( p -> type );
}

    /*
     *	this recursively follows done a list of qualifications
     *	and puts out the beginnings of calls to fnil for files
     *	or nil for pointers (if checking is on) on the way back.
     *	this returns true or false.
     */
I 5
bool
E 5
nilfnil( p , c , modflag , firstp , r2 )
D 5
    struct nl	*p;
    int		*c;
E 5
I 5
    struct nl	 *p;
    struct tnode *c;
E 5
    int		modflag;
    struct nl	*firstp;
    char	*r2;		/* no, not r2-d2 */
    {
D 5
	int		*co;
E 5
I 5
	struct tnode 	*co;
E 5
	struct nl	*lastp;
	int		t;
I 8
	static int	s = 0;
E 8

D 5
	if ( c == NIL ) {
E 5
I 5
	if ( c == TR_NIL ) {
E 5
	    return TRUE;
	}
D 5
	co = (int *) ( c[1] );
	if ( co == NIL ) {
E 5
I 5
	co = ( c->list_node.list );
	if ( co == TR_NIL ) {
E 5
		return FALSE;
	}
	lastp = p;
	p = p -> type;
D 5
	if ( p == NIL ) {
E 5
I 5
	if ( p == NLNIL ) {
E 5
		return FALSE;
	}
D 5
	switch ( co[0] ) {
E 5
I 5
	switch ( co->tag ) {
E 5
	    case T_PTR:
		    /*
		     * Pointer qualification.
		     */
		    lastp -> nl_flags |= NUSED;
		    if ( p -> class != PTR && p -> class != FILET) {
			    error("^ allowed only on files and pointers, not on %ss", nameof(p));
			    goto bad;
		    }
		    break;
	    case T_ARGL:
		    if ( p -> class != ARRAY ) {
			    if ( lastp == firstp ) {
				    error("%s is a %s, not a function", r2, classes[firstp -> class]);
			    } else {
				    error("Illegal function qualificiation");
			    }
			    return FALSE;
		    }
		    recovered();
		    error("Pascal uses [] for subscripting, not ()");
		    /* and fall through */
	    case T_ARY:
		    if ( p -> class != ARRAY ) {
			    error("Subscripting allowed only on arrays, not on %ss", nameof(p));
			    goto bad;
		    }
		    codeoff();
D 5
		    t = arycod( p , co[1] );
E 5
I 5
D 8
		    t = arycod( p , co->ary_node.expr_list );
E 8
I 8
		    s = arycod( p , co->ary_node.expr_list , s );
E 8
E 5
		    codeon();
D 8
		    switch ( t ) {
E 8
I 8
		    switch ( s ) {
E 8
			    case 0:
				    return FALSE;
			    case -1:
				    goto bad;
I 8
		    }
		    if (s == p->value[0]) {
			    s = 0;
		    } else {
			    p = lastp;
E 8
		    }
		    break;
	    case T_FIELD:
		    /*
		     * Field names are just
		     * an offset with some 
		     * semantic checking.
		     */
		    if ( p -> class != RECORD ) {
			    error(". allowed only on records, not on %ss", nameof(p));
			    goto bad;
		    }
D 5
		    if ( co[1] == NIL ) {
E 5
I 5
		    if ( co->field_node.id_ptr == NIL ) {
E 5
			    return FALSE;
		    }
D 5
		    p = reclook( p , co[1] );
E 5
I 5
		    p = reclook( p , co->field_node.id_ptr );
E 5
		    if ( p == NIL ) {
D 5
			    error("%s is not a field in this record", co[1]);
E 5
I 5
			    error("%s is not a field in this record", co->field_node.id_ptr);
E 5
			    goto bad;
		    }
		    if ( modflag & MOD ) {
			    p -> nl_flags |= NMOD;
		    }
D 5
		    if ( ( modflag & NOUSE ) == 0 || lptr( c[2] ) ) {
E 5
I 5
		    if ((modflag & NOUSE) == 0 || lptr(c->field_node.other )) {
E 5
			    p -> nl_flags |= NUSED;
		    }
		    break;
	    default:
		    panic("nilfnil");
	}
	    /*
	     *	recursive call, check the rest of the qualifications.
	     */
D 5
	if ( ! nilfnil( p , c[2] , modflag , firstp , r2 ) ) {
E 5
I 5
	if ( ! nilfnil( p , c->list_node.next , modflag , firstp , r2 ) ) {
E 5
	    return FALSE;
	}
	    /*
	     *	the point of all this.
	     */
D 5
	if ( co[0] == T_PTR ) {
E 5
I 5
	if ( co->tag == T_PTR ) {
E 5
	    if ( p -> class == PTR ) {
		    if ( opt( 't' ) ) {
D 11
			putleaf( P2ICON , 0 , 0
			    , ADDTYPE( P2FTN | P2INT , P2PTR )
E 11
I 11
			putleaf( PCC_ICON , 0 , 0
			    , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 11
			    , "_NIL" );
		    }
	    } else {
D 11
		    putleaf( P2ICON , 0 , 0
			, ADDTYPE( P2FTN | P2INT , P2PTR )
E 11
I 11
		    putleaf( PCC_ICON , 0 , 0
			, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 11
			, "_FNIL" );
	    }
	}
	return TRUE;
bad:
	cerror("Error occurred on qualification of %s", r2);
	return FALSE;
    }
#endif PC
E 1
