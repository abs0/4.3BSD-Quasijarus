h05520
s 00010/00005/00290
d D 5.3 88/06/29 19:23:02 bostic 6 5
c install approved copyright notice
e
s 00009/00003/00286
d D 5.2 88/05/05 17:50:06 bostic 5 4
c add Berkeley specific header; written by K. McKusick and P. Kessler
e
s 00008/00002/00281
d D 5.1 85/06/04 13:26:50 dist 4 3
c Add copyright
e
s 00003/00003/00280
d D 1.3 83/01/15 12:47:33 peter 3 2
c catch detached strongly-connected components.
c [this is only part of a change that is needed
c to make dfn() do the real tarjan algorithm.]
e
s 00001/00001/00282
d D 1.2 81/10/20 15:49:37 peter 2 1
c name change to confuse to innocent/
e
s 00283/00000/00000
d D 1.1 81/10/15 13:46:45 peter 1 0
c date and time created 81/10/15 13:46:45 by peter
e
u
U
t
T
I 4
/*
 * Copyright (c) 1983 Regents of the University of California.
D 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 6
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 6
I 6
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 6
E 5
 */

E 4
I 1
#ifndef lint
D 4
    static	char *sccsid = "%W% (Berkeley) %G%";
#endif lint
E 4
I 4
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif not lint
E 5
I 5
#endif /* not lint */
E 5
E 4

#include <stdio.h>
D 2
#include "dprof.h"
E 2
I 2
#include "gprof.h"
E 2

#define	DFN_DEPTH	100
struct dfnstruct {
    nltype	*nlentryp;
    int		cycletop;
};
typedef struct dfnstruct	dfntype;

dfntype	dfn_stack[ DFN_DEPTH ];
int	dfn_depth = 0;

D 3
int	dfn_counter = 0;
E 3
I 3
int	dfn_counter = DFN_NAN;
E 3

    /*
     *	given this parent, depth first number its children.
     */
dfn( parentp )
    nltype	*parentp;
{
    arctype	*arcp;

#   ifdef DEBUG
	if ( debug & DFNDEBUG ) {
	    printf( "[dfn] dfn(" );
	    printname( parentp );
	    printf( ")\n" );
	}
#   endif DEBUG
	/*
	 *	if we're already numbered, no need to look any furthur.
	 */
    if ( dfn_numbered( parentp ) ) {
	return;
    }
	/*
	 *	if we're already busy, must be a cycle
	 */
    if ( dfn_busy( parentp ) ) {
	dfn_findcycle( parentp );
	return;
    }
	/*
	 *	visit yourself before your children
	 */
    dfn_pre_visit( parentp );
	/*
	 *	visit children
	 */
    for ( arcp = parentp -> children ; arcp ; arcp = arcp -> arc_childlist ) {
	    dfn( arcp -> arc_childp );
    }
	/*
	 *	visit yourself after your children
	 */
    dfn_post_visit( parentp );
}

    /*
     *	push a parent onto the stack and mark it busy
     */
dfn_pre_visit( parentp )
    nltype	*parentp;
{

    dfn_depth += 1;
    if ( dfn_depth >= DFN_DEPTH ) {
	fprintf( stderr , "[dfn] out of my depth (dfn_stack overflow)\n" );
	exit( 1 );
    }
    dfn_stack[ dfn_depth ].nlentryp = parentp;
    dfn_stack[ dfn_depth ].cycletop = dfn_depth;
    parentp -> toporder = DFN_BUSY;
#   ifdef DEBUG
	if ( debug & DFNDEBUG ) {
	    printf( "[dfn_pre_visit]\t\t%d:" , dfn_depth );
	    printname( parentp );
	    printf( "\n" );
	}
#   endif DEBUG
}

    /*
     *	are we already numbered?
     */
bool
dfn_numbered( childp )
    nltype	*childp;
{
    
D 3
    return ( childp -> toporder != 0 && childp -> toporder != DFN_BUSY );
E 3
I 3
    return ( childp -> toporder != DFN_NAN && childp -> toporder != DFN_BUSY );
E 3
}

    /*
     *	are we already busy?
     */
bool
dfn_busy( childp )
    nltype	*childp;
{

D 3
    if ( childp -> toporder == 0 ) {
E 3
I 3
    if ( childp -> toporder == DFN_NAN ) {
E 3
	return FALSE;
    }
    return TRUE;
}

    /*
     *	MISSING: an explanation
     */
dfn_findcycle( childp )
    nltype	*childp;
{
    int		cycletop;
    nltype	*cycleheadp;
    nltype	*tailp;
    int		index;

    for ( cycletop = dfn_depth ; cycletop > 0 ; cycletop -= 1 ) {
	cycleheadp = dfn_stack[ cycletop ].nlentryp;
	if ( childp == cycleheadp ) {
	    break;
	}
	if ( childp -> cyclehead != childp &&
	    childp -> cyclehead == cycleheadp ) {
	    break;
	}
    }
    if ( cycletop <= 0 ) {
	fprintf( stderr , "[dfn_findcycle] couldn't find head of cycle\n" );
	exit( 1 );
    }
#   ifdef DEBUG
	if ( debug & DFNDEBUG ) {
	    printf( "[dfn_findcycle] dfn_depth %d cycletop %d " ,
		    dfn_depth , cycletop  );
	    printname( cycleheadp );
	    printf( "\n" );
	}
#   endif DEBUG
    if ( cycletop == dfn_depth ) {
	    /*
	     *	this is previous function, e.g. this calls itself
	     *	sort of boring
	     */
	dfn_self_cycle( childp );
    } else {
	    /*
	     *	glom intervening functions that aren't already
	     *	glommed into this cycle.
	     *	things have been glommed when their cyclehead field
	     *	points to the head of the cycle they are glommed into.
	     */
	for ( tailp = cycleheadp ; tailp -> cnext ; tailp = tailp -> cnext ) {
	    /* void: chase down to tail of things already glommed */
#	    ifdef DEBUG
		if ( debug & DFNDEBUG ) {
		    printf( "[dfn_findcycle] tail " );
		    printname( tailp );
		    printf( "\n" );
		}
#	    endif DEBUG
	}
	    /*
	     *	if what we think is the top of the cycle
	     *	has a cyclehead field, then it's not really the
	     *	head of the cycle, which is really what we want
	     */	
	if ( cycleheadp -> cyclehead != cycleheadp ) {
	    cycleheadp = cycleheadp -> cyclehead;
#	    ifdef DEBUG
		if ( debug & DFNDEBUG ) {
		    printf( "[dfn_findcycle] new cyclehead " );
		    printname( cycleheadp );
		    printf( "\n" );
		}
#	    endif DEBUG
	}
	for ( index = cycletop + 1 ; index <= dfn_depth ; index += 1 ) {
	    childp = dfn_stack[ index ].nlentryp;
	    if ( childp -> cyclehead == childp ) {
		    /*
		     *	not yet glommed anywhere, glom it
		     *	and fix any children it has glommed
		     */
		tailp -> cnext = childp;
		childp -> cyclehead = cycleheadp;
#		ifdef DEBUG
		    if ( debug & DFNDEBUG ) {
			printf( "[dfn_findcycle] glomming " );
			printname( childp );
			printf( " onto " );
			printname( cycleheadp );
			printf( "\n" );
		    }
#		endif DEBUG
		for ( tailp = childp ; tailp->cnext ; tailp = tailp->cnext ) {
		    tailp -> cnext -> cyclehead = cycleheadp;
#		    ifdef DEBUG
			if ( debug & DFNDEBUG ) {
			    printf( "[dfn_findcycle] and its tail " );
			    printname( tailp -> cnext );
			    printf( " onto " );
			    printname( cycleheadp );
			    printf( "\n" );
			}
#		    endif DEBUG
		}
	    } else if ( childp -> cyclehead != cycleheadp /* firewall */ ) {
		fprintf( stderr ,
			"[dfn_busy] glommed, but not to cyclehead\n" );
	    }
	}
    }
}

    /*
     *	deal with self-cycles
     *	for lint: ARGSUSED
     */
dfn_self_cycle( parentp )
    nltype	*parentp;
{
	/*
	 *	since we are taking out self-cycles elsewhere
	 *	no need for the special case, here.
	 */
#   ifdef DEBUG
	if ( debug & DFNDEBUG ) {
	    printf( "[dfn_self_cycle] " );
	    printname( parentp );
	    printf( "\n" );
	}
#   endif DEBUG
}

    /*
     *	visit a node after all its children
     *	[MISSING: an explanation]
     *	and pop it off the stack
     */
dfn_post_visit( parentp )
    nltype	*parentp;
{
    nltype	*memberp;

#   ifdef DEBUG
	if ( debug & DFNDEBUG ) {
	    printf( "[dfn_post_visit]\t%d: " , dfn_depth );
	    printname( parentp );
	    printf( "\n" );
	}
#   endif DEBUG
	/*
	 *	number functions and things in their cycles
	 *	unless the function is itself part of a cycle
	 */
    if ( parentp -> cyclehead == parentp ) {
	dfn_counter += 1;
	for ( memberp = parentp ; memberp ; memberp = memberp -> cnext ) {
	    memberp -> toporder = dfn_counter;
#	    ifdef DEBUG
		if ( debug & DFNDEBUG ) {
		    printf( "[dfn_post_visit]\t\tmember " );
		    printname( memberp );
		    printf( " -> toporder = %d\n" , dfn_counter );
		}
#	    endif DEBUG
	}
    } else {
#	ifdef DEBUG
	    if ( debug & DFNDEBUG ) {
		printf( "[dfn_post_visit]\t\tis part of a cycle\n" );
	    }
#	endif DEBUG
    }
    dfn_depth -= 1;
}
E 1
