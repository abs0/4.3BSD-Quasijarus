h39526
s 00010/00005/00555
d D 5.5 88/06/29 19:22:58 bostic 20 19
c install approved copyright notice
e
s 00009/00003/00551
d D 5.4 88/05/05 17:50:02 bostic 19 18
c add Berkeley specific header; written by K. McKusick and P. Kessler
e
s 00001/00001/00553
d D 5.3 86/01/07 00:04:56 sam 18 17
c everyone wants to rename calls to callf (or similar), make it just findcall
e
s 00000/00000/00554
d D 5.2 85/06/04 15:24:47 dist 17 16
c Add copyright
e
s 00008/00002/00546
d D 5.1 85/06/04 13:23:19 dist 16 15
c Add copyright
e
s 00022/00002/00526
d D 1.15 84/08/07 11:25:22 mckusick 15 14
c sort entries and assign indicies so that all listings can show them
e
s 00020/00006/00508
d D 1.14 83/07/26 14:58:26 peter 14 13
c protect against floating exceptions for arcs added by -c (static arcs).
e
s 00006/00005/00508
d D 1.13 83/01/15 12:47:49 peter 13 12
c catch detached strongly-connected components.
c [this is only part of a change that is needed
c to make dfn() do the real tarjan algorithm.]
e
s 00005/00002/00508
d D 1.12 82/10/26 14:51:38 peter 12 11
c when propagating fractions, don't count yourself as a parent.
e
s 00000/00002/00510
d D 1.11 82/06/21 11:46:05 peter 11 10
c removing lint.
e
s 00001/00001/00511
d D 1.10 82/06/20 16:22:53 peter 10 9
c cycles have names of 0, not "",  according to printgprof.
e
s 00024/00014/00488
d D 1.9 82/06/20 14:58:46 peter 9 8
c have to count outside parents of cycles before propagating fractions.
e
s 00178/00155/00324
d D 1.8 82/06/18 20:21:16 peter 8 7
c -e -E -f and -F flags, this time for sure.
e
s 00167/00021/00312
d D 1.7 82/06/14 18:08:10 peter 7 6
c -f and -e flags.
e
s 00091/00076/00242
d D 1.6 82/06/08 11:28:48 peter 6 5
c cycle headers have their own namelist.
e
s 00000/00026/00318
d D 1.5 81/11/10 23:03:52 peter 5 4
c fine tune some of the sorting.
e
s 00002/00002/00342
d D 1.4 81/11/06 17:24:49 peter 4 3
c since times are stored in arcs, calloc instead of malloc them.
e
s 00050/00000/00294
d D 1.3 81/11/02 14:31:31 peter 3 2
c gather and use static call graph from a.out file.
e
s 00002/00002/00292
d D 1.2 81/10/20 15:49:49 peter 2 1
c name change to confuse to innocent/
e
s 00294/00000/00000
d D 1.1 81/10/15 13:46:39 peter 1 0
c date and time created 81/10/15 13:46:39 by peter
e
u
U
t
T
I 16
/*
 * Copyright (c) 1983 Regents of the University of California.
D 19
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 19
I 19
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 20
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 20
I 20
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
E 20
E 19
 */

E 16
I 1
#ifndef lint
D 16
    static	char *sccsid = "%W% (Berkeley) %G%";
#endif lint
E 16
I 16
static char sccsid[] = "%W% (Berkeley) %G%";
D 19
#endif not lint
E 19
I 19
#endif /* not lint */
E 19
E 16

D 2
#include "dprof.h"
E 2
I 2
#include "gprof.h"
E 2

I 3
    /*
     *	add (or just increment) an arc
     */
addarc( parentp , childp , count )
    nltype	*parentp;
    nltype	*childp;
    long	count;
{
D 4
    arctype		*malloc();
E 4
I 4
    arctype		*calloc();
E 4
    arctype		*arcp;

#   ifdef DEBUG
	if ( debug & TALLYDEBUG ) {
	    printf( "[addarc] %d arcs from %s to %s\n" ,
		    count , parentp -> name , childp -> name );
	}
#   endif DEBUG
    arcp = arclookup( parentp , childp );
    if ( arcp != 0 ) {
	    /*
	     *	a hit:  just increment the count.
	     */
#	ifdef DEBUG
	    if ( debug & TALLYDEBUG ) {
		printf( "[tally] hit %d += %d\n" ,
			arcp -> arc_count , count );
	    }
#	endif DEBUG
	arcp -> arc_count += count;
	return;
    }
D 4
    arcp = malloc( sizeof *arcp );
E 4
I 4
    arcp = calloc( 1 , sizeof *arcp );
E 4
    arcp -> arc_parentp = parentp;
    arcp -> arc_childp = childp;
    arcp -> arc_count = count;
	/*
	 *	prepend this child to the children of this parent
	 */
    arcp -> arc_childlist = parentp -> children;
    parentp -> children = arcp;
	/*
	 *	prepend this parent to the parents of this child
	 */
    arcp -> arc_parentlist = childp -> parents;
    childp -> parents = arcp;
}

I 7
    /*
     *	the code below topologically sorts the graph (collapsing cycles),
     *	and propagates time bottom up and flags top down.
     */

    /*
     *	the topologically sorted name list pointers
     */
nltype	**topsortnlp;

E 7
E 3
topcmp( npp1 , npp2 )
    nltype	**npp1;
    nltype	**npp2;
{
    return (*npp1) -> toporder - (*npp2) -> toporder;
}

I 15
nltype **
E 15
D 5
    /*
     *	sort by decreasing total time (time+childtime)
     *	if times are equal, but one is a cycle header,
     *	say that's first (e.g. less)
     */
int
totalcmp( npp1 , npp2 )
    nltype	**npp1;
    nltype	**npp2;
{
    register nltype	*np1 = *npp1;
    register nltype	*np2 = *npp2;
    double		diff;

    diff =    ( np1 -> time + np1 -> childtime )
	    - ( np2 -> time + np2 -> childtime );
    if ( diff < 0.0 )
	    return 1;
    if ( diff > 0.0 )
	    return -1;
    if ( np1 -> name == 0 && np1 -> cycleno != 0 ) 
	return -1;
    if ( np2 -> name == 0 && np1 -> cycleno != 0 )
	return 1;
    return 0;
}
E 5
D 7

E 7
doarcs()
{
D 15
    nltype	*parentp;
E 15
I 15
    nltype	*parentp, **timesortnlp;
E 15
    arctype	*arcp;
D 7
    nltype	**topsortnlp;
E 7
    long	index;
D 6
    nltype	*childp;
    double	share;
E 6

	/*
	 *	initialize various things:
	 *	    zero out child times.
	 *	    count self-recursive calls.
	 *	    indicate that nothing is on cycles.
	 */
    for ( parentp = nl ; parentp < npe ; parentp++ ) {
	parentp -> childtime = 0.0;
	arcp = arclookup( parentp , parentp );
	if ( arcp != 0 ) {
	    parentp -> ncall -= arcp -> arc_count;
	    parentp -> selfcalls = arcp -> arc_count;
	} else {
	    parentp -> selfcalls = 0;
I 3
	}
I 8
	parentp -> propfraction = 0.0;
	parentp -> propself = 0.0;
	parentp -> propchild = 0.0;
E 8
D 7
	if ( cflag ) {
	    findcalls( parentp , parentp -> value , (parentp+1) -> value );
E 3
	}
E 7
I 7
	parentp -> printflag = FALSE;
E 7
D 13
	parentp -> toporder = 0;
E 13
I 13
	parentp -> toporder = DFN_NAN;
E 13
	parentp -> cycleno = 0;
	parentp -> cyclehead = parentp;
	parentp -> cnext = 0;
I 7
	if ( cflag ) {
D 18
	    findcalls( parentp , parentp -> value , (parentp+1) -> value );
E 18
I 18
	    findcall( parentp , parentp -> value , (parentp+1) -> value );
E 18
	}
E 7
    }
	/*
I 7
D 8
	 *	time for functions which print is accumulated here.
	 */
    printtime = 0.0;
	/*
E 8
E 7
	 *	topologically order things
D 13
	 *	from each of the roots of the call graph
E 13
I 13
	 *	if any node is unnumbered,
	 *	    number it and any of its descendents.
E 13
	 */
    for ( parentp = nl ; parentp < npe ; parentp++ ) {
D 13
	if ( parentp -> parents == 0 ) {
E 13
I 13
	if ( parentp -> toporder == DFN_NAN ) {
E 13
	    dfn( parentp );
	}
    }
	/*
	 *	link together nodes on the same cycle
	 */
    cyclelink();
	/*
	 *	Sort the symbol table in reverse topological order
	 */
    topsortnlp = (nltype **) calloc( nname , sizeof(nltype *) );
    if ( topsortnlp == (nltype **) 0 ) {
	fprintf( stderr , "[doarcs] ran out of memory for topo sorting\n" );
    }
    for ( index = 0 ; index < nname ; index += 1 ) {
	topsortnlp[ index ] = &nl[ index ];
    }
    qsort( topsortnlp , nname , sizeof(nltype *) , topcmp );
#   ifdef DEBUG
	if ( debug & DFNDEBUG ) {
	    printf( "[doarcs] topological sort listing\n" );
	    for ( index = 0 ; index < nname ; index += 1 ) {
		printf( "[doarcs] " );
		printf( "%d:" , topsortnlp[ index ] -> toporder );
		printname( topsortnlp[ index ] );
		printf( "\n" );
	    }
	}
#   endif DEBUG
	/*
D 8
	 *	starting from the topological bottom, 
D 7
	 *	propogate children times
E 7
I 7
	 *	propogate children times up to parents.
E 7
	 */
I 7
    dotime();
	/*
E 8
	 *	starting from the topological top,
	 *	propagate print flags to children.
I 8
	 *	also, calculate propagation fractions.
	 *	this happens before time propagation
	 *	since time propagation uses the fractions.
E 8
	 */
    doflags();
I 8
	/*
	 *	starting from the topological bottom, 
	 *	propogate children times up to parents.
	 */
    dotime();
E 8
D 15
    printgprof();
E 15
I 15
	/*
	 *	Now, sort by propself + propchild.
	 *	sorting both the regular function names
	 *	and cycle headers.
	 */
    timesortnlp = (nltype **) calloc( nname + ncycle , sizeof(nltype *) );
    if ( timesortnlp == (nltype **) 0 ) {
	fprintf( stderr , "%s: ran out of memory for sorting\n" , whoami );
    }
    for ( index = 0 ; index < nname ; index++ ) {
	timesortnlp[index] = &nl[index];
    }
    for ( index = 1 ; index <= ncycle ; index++ ) {
	timesortnlp[nname+index-1] = &cyclenl[index];
    }
    qsort( timesortnlp , nname + ncycle , sizeof(nltype *) , totalcmp );
    for ( index = 0 ; index < nname + ncycle ; index++ ) {
	timesortnlp[ index ] -> index = index + 1;
    }
    return( timesortnlp );
E 15
}

dotime()
{
    int	index;

    cycletime();
E 7
    for ( index = 0 ; index < nname ; index += 1 ) {
D 6
	parentp = topsortnlp[ index ];
	for ( arcp = parentp->children ; arcp ; arcp = arcp->arc_childlist ) {
	    childp = arcp -> arc_childp;
E 6
I 6
D 7
	propagate( topsortnlp[ index ] );
E 7
I 7
	timepropagate( topsortnlp[ index ] );
E 7
    }
D 7
    printgprof();
E 7
}

D 7
propagate( parentp )
E 7
I 7
timepropagate( parentp )
E 7
    nltype	*parentp;
{
    arctype	*arcp;
    nltype	*childp;
    double	share;
I 8
    double	propshare;
E 8

I 8
    if ( parentp -> propfraction == 0.0 ) {
	return;
    }
E 8
	/*
	 *	gather time from children of this parent.
	 */
D 7
    for ( arcp = parentp->children ; arcp ; arcp = arcp->arc_childlist ) {
E 7
I 7
    for ( arcp = parentp -> children ; arcp ; arcp = arcp -> arc_childlist ) {
E 7
	childp = arcp -> arc_childp;
D 8
#	ifdef DEBUG
	    if ( debug & ARCDEBUG ) {
		printf( "[propagate] " );
		printname( parentp );
		printf( " calls " );
		printname( childp );
		printf( " %d (%d) times\n" ,
			arcp -> arc_count , childp -> ncall );
	    }
#	endif DEBUG
E 8
	if ( arcp -> arc_count == 0 ) {
	    continue;
	}
D 8
	if ( childp -> ncall == 0 ) {
E 8
I 8
	if ( childp == parentp ) {
E 8
	    continue;
	}
D 8
	if ( childp == parentp ) {
E 8
I 8
	if ( childp -> propfraction == 0.0 ) {
E 8
	    continue;
	}
	if ( childp -> cyclehead != childp ) {
	    if ( parentp -> cycleno == childp -> cycleno ) {
		continue;
	    }
E 6
D 8
#	    ifdef DEBUG
		if ( debug & ARCDEBUG ) {
D 6
			printf( "[doarcs] " );
			printname( parentp );
			printf( " calls " );
			printname( childp );
			printf( " %d (%d) times\n" ,
				arcp -> arc_count , childp -> ncall );
E 6
I 6
		    printf( "[propagate]\t it's a call into cycle %d\n" ,
			    childp -> cycleno );
E 6
		}
#	    endif DEBUG
E 8
D 6
	    if ( arcp -> arc_count == 0 ) {
		continue;
E 6
I 6
	    if ( parentp -> toporder <= childp -> toporder ) {
		fprintf( stderr , "[propagate] toporder botches\n" );
E 6
	    }
D 6
	    if ( childp -> ncall == 0 ) {
E 6
I 6
	    childp = childp -> cyclehead;
	} else {
	    if ( parentp -> toporder <= childp -> toporder ) {
		fprintf( stderr , "[propagate] toporder botches\n" );
E 6
		continue;
	    }
D 6
	    if ( childp == parentp ) {
		continue;
E 6
I 6
	}
I 8
	if ( childp -> ncall == 0 ) {
	    continue;
	}
E 8
	    /*
	     *	distribute time for this arc
	     */
D 8
	arcp -> arc_time = childp -> time *
			    ( ( (double) arcp -> arc_count ) /
			    ( (double) childp -> ncall ) );
	arcp -> arc_childtime = childp -> childtime *
			    ( ( (double) arcp -> arc_count ) /
			    ( (double) childp -> ncall ) );
E 8
I 8
	arcp -> arc_time = childp -> time
			        * ( ( (double) arcp -> arc_count ) /
				    ( (double) childp -> ncall ) );
	arcp -> arc_childtime = childp -> childtime
			        * ( ( (double) arcp -> arc_count ) /
				    ( (double) childp -> ncall ) );
E 8
	share = arcp -> arc_time + arcp -> arc_childtime;
D 8
#	ifdef DEBUG
	    if ( debug & ARCDEBUG ) {
		printf( "[propagate]\t " );
		printname( childp );
		printf( " time %8.2f + childtime %8.2f\n" ,
		    childp -> time , childp -> childtime );
		printf( "[propagate]\t this is %d arcs of the %d calls\n",
		    arcp -> arc_count , childp -> ncall );
		printf( "[propagate]\t so this gives %8.2f+%8.2f to %s\n" ,
		    arcp -> arc_time , arcp -> arc_childtime ,
		    parentp -> name );
E 6
	    }
D 6
	    if ( childp -> cyclehead != childp ) {
		if ( parentp -> cycleno == childp -> cycleno ) {
		    continue;
		}
#		ifdef DEBUG
		    if ( debug & ARCDEBUG ) {
			printf( "[doarcs]\t it's a call into cycle %d\n" ,
				childp -> cycleno );
		    }
#		endif DEBUG
		if ( parentp -> toporder <= childp -> toporder ) {
		    fprintf( stderr , "[doarcs] toporder botches\n" );
		}
		childp = childp -> cyclehead;
	    } else {
		if ( parentp -> toporder <= childp -> toporder ) {
		    fprintf( stderr , "[doarcs] toporder botches\n" );
		    continue;
		}
	    }
		/*
		 *	distribute time for this arc
		 */
	    arcp -> arc_time = childp -> time *
				( ( (double) arcp -> arc_count ) /
				( (double) childp -> ncall ) );
	    arcp -> arc_childtime = childp -> childtime *
				( ( (double) arcp -> arc_count ) /
				( (double) childp -> ncall ) );
	    share = arcp -> arc_time + arcp -> arc_childtime;
E 6
I 6
#	endif DEBUG
E 8
	parentp -> childtime += share;
	    /*
D 8
	     *	add this share to the cycle header, if any
E 8
I 8
	     *	( 1 - propfraction ) gets lost along the way
E 8
	     */
I 8
	propshare = parentp -> propfraction * share;
	    /*
	     *	fix things for printing
	     */
	parentp -> propchild += propshare;
	arcp -> arc_time *= parentp -> propfraction;
	arcp -> arc_childtime *= parentp -> propfraction;
	    /*
	     *	add this share to the parent's cycle header, if any.
	     */
E 8
	if ( parentp -> cyclehead != parentp ) {
E 6
D 8
#	    ifdef DEBUG
		if ( debug & ARCDEBUG ) {
D 6
		    printf( "[doarcs]\t " );
		    printname( childp );
		    printf( " time %8.2f + childtime %8.2f\n" ,
			childp -> time , childp -> childtime );
		    printf( "[doarcs]\t this is %d arcs of the %d calls\n",
			arcp -> arc_count , childp -> ncall );
		    printf( "[doarcs]\t so this gives %8.2f+%8.2f to %s\n" ,
			arcp -> arc_time , arcp -> arc_childtime ,
			parentp -> name );
E 6
I 6
		    printf( "[propagate]\t and to cycle %d\n" ,
			    parentp -> cycleno );
E 6
		}
#	    endif DEBUG
E 8
D 6
	    parentp -> childtime += share;
		/*
		 *	add this share to the cycle header, if any
		 */
	    if ( parentp -> cyclehead != parentp ) {
#		ifdef DEBUG
		    if ( debug & ARCDEBUG ) {
			printf( "[doarcs]\t and to cycle %d\n" ,
				parentp -> cycleno );
		    }
#		endif DEBUG
		parentp -> cyclehead -> childtime += share;
	    }
E 6
I 6
	    parentp -> cyclehead -> childtime += share;
I 8
	    parentp -> cyclehead -> propchild += propshare;
E 8
E 6
	}
I 8
#	ifdef DEBUG
	    if ( debug & PROPDEBUG ) {
		printf( "[dotime] child \t" );
		printname( childp );
		printf( " with %f %f %d/%d\n" ,
			childp -> time , childp -> childtime ,
			arcp -> arc_count , childp -> ncall );
		printf( "[dotime] parent\t" );
		printname( parentp );
		printf( "\n[dotime] share %f\n" , share );
	    }
#	endif DEBUG
E 8
    }
D 2
    printdprof();
E 2
I 2
D 6
    printgprof();
E 6
E 2
}

cyclelink()
{
    register nltype	*nlp;
D 7
    register nltype	*parentp;
    register nltype	*childp;
E 7
    register nltype	*cyclenlp;
    int			cycle;
D 7
    arctype		*arcp;
    long		ncall;
    double		time;
    long		callsamong;
E 7
I 7
    nltype		*memberp;
I 9
    arctype		*arcp;
E 9
E 7

	/*
	 *	Count the number of cycles, and initialze the cycle lists
	 */
D 6
    cyclemax = 0;
E 6
I 6
    ncycle = 0;
E 6
    for ( nlp = nl ; nlp < npe ; nlp++ ) {
	    /*
	     *	this is how you find unattached cycles
	     */
	if ( nlp -> cyclehead == nlp && nlp -> cnext != 0 ) {
D 6
	    cyclemax += 1;
E 6
I 6
	    ncycle += 1;
E 6
	}
    }
D 6
    if ( cyclemax > ncycles ) {
	fprintf( stderr , "prof: %d cycles in %d names exceeds %f%%\n" ,
		cyclemax , nname , CYCLEFRACTION * 100.0 );
	exit( 1 );
E 6
I 6
	/*
	 *	cyclenl is indexed by cycle number:
	 *	i.e. it is origin 1, not origin 0.
	 */
    cyclenl = (nltype *) calloc( ncycle + 1 , sizeof( nltype ) );
    if ( cyclenl == 0 ) {
	fprintf( stderr , "%s: No room for %d bytes of cycle headers\n" ,
		whoami , ( ncycle + 1 ) * sizeof( nltype ) );
	done();
E 6
    }
	/*
	 *	now link cycles to true cycleheads,
	 *	number them, accumulate the data for the cycle
	 */
    cycle = 0;
    for ( nlp = nl ; nlp < npe ; nlp++ ) {
D 13
	if ( nlp -> cyclehead != nlp || nlp -> cnext == 0 ) {
E 13
I 13
	if ( !( nlp -> cyclehead == nlp && nlp -> cnext != 0 ) ) {
E 13
	    continue;
	}
	cycle += 1;
D 6
	cyclenlp = &nl[nname+cycle];
E 6
I 6
	cyclenlp = &cyclenl[cycle];
E 6
D 8
	cyclenlp -> cycleno = cycle;
	cyclenlp -> cyclehead = cyclenlp;
	cyclenlp -> cnext = nlp;
E 8
I 8
D 10
        cyclenlp -> name = "";		/* the name */
E 10
I 10
        cyclenlp -> name = 0;		/* the name */
E 10
        cyclenlp -> value = 0;		/* the pc entry point */
        cyclenlp -> time = 0.0;		/* ticks in this routine */
        cyclenlp -> childtime = 0.0;	/* cumulative ticks in children */
	cyclenlp -> ncall = 0;		/* how many times called */
	cyclenlp -> selfcalls = 0;	/* how many calls to self */
	cyclenlp -> propfraction = 0.0;	/* what % of time propagates */
	cyclenlp -> propself = 0.0;	/* how much self time propagates */
	cyclenlp -> propchild = 0.0;	/* how much child time propagates */
	cyclenlp -> printflag = TRUE;	/* should this be printed? */
	cyclenlp -> index = 0;		/* index in the graph list */
D 13
	cyclenlp -> toporder = 0;	/* graph call chain top-sort order */
E 13
I 13
	cyclenlp -> toporder = DFN_NAN;	/* graph call chain top-sort order */
E 13
	cyclenlp -> cycleno = cycle;	/* internal number of cycle on */
	cyclenlp -> cyclehead = cyclenlp;	/* pointer to head of cycle */
	cyclenlp -> cnext = nlp;	/* pointer to next member of cycle */
	cyclenlp -> parents = 0;	/* list of caller arcs */
	cyclenlp -> children = 0;	/* list of callee arcs */
E 8
#	ifdef DEBUG
	    if ( debug & CYCLEDEBUG ) {
		printf( "[cyclelink] " );
		printname( nlp );
		printf( " is the head of cycle %d\n" , cycle );
	    }
#	endif DEBUG
I 9
	    /*
	     *	link members to cycle header
	     */
E 9
I 7
	for ( memberp = nlp ; memberp ; memberp = memberp -> cnext ) { 
	    memberp -> cycleno = cycle;
	    memberp -> cyclehead = cyclenlp;
	}
I 9
	    /*
	     *	count calls from outside the cycle
	     *	and those among cycle members
	     */
	for ( memberp = nlp ; memberp ; memberp = memberp -> cnext ) {
	    for ( arcp=memberp->parents ; arcp ; arcp=arcp->arc_parentlist ) {
		if ( arcp -> arc_parentp == memberp ) {
		    continue;
		}
		if ( arcp -> arc_parentp -> cycleno == cycle ) {
		    cyclenlp -> selfcalls += arcp -> arc_count;
		} else {
		    cyclenlp -> ncall += arcp -> arc_count;
		}
	    }
	}
E 9
    }
}

cycletime()
{
    int			cycle;
    nltype		*cyclenlp;
D 8
    nltype		*parentp;
E 8
    nltype		*childp;
D 11
    arctype		*arcp;
D 8
    long		ncall;
    double		time;
    long		callsamong;
E 8
I 8
    nltype		*parentp;
E 11
E 8

    for ( cycle = 1 ; cycle <= ncycle ; cycle += 1 ) {
	cyclenlp = &cyclenl[ cycle ];
E 7
D 8
	    /*
	     *	n-squaredly (in the size of the cycle)
	     *	find all the call within the cycle 
	     *	(including self-recursive calls)
	     *	and remove them, thus making the cycle into
	     *	`node' with calls only from the outside.
	     *	note: that this doesn't deal with
	     *	self-recursive calls outside cycles (sigh).
	     */
	callsamong = 0;
D 7
	for ( parentp = nlp ; parentp ; parentp = parentp -> cnext ) {
	    parentp -> cycleno = cycle;
	    parentp -> cyclehead = cyclenlp;
	    for ( childp = nlp ; childp ; childp = childp -> cnext ) {
E 7
I 7
	for ( parentp = cyclenlp->cnext; parentp; parentp = parentp->cnext ) {
	    for ( childp = cyclenlp->cnext; childp; childp = childp -> cnext ) {
E 8
I 8
	for ( childp = cyclenlp -> cnext ; childp ; childp = childp -> cnext ) {
	    if ( childp -> propfraction == 0.0 ) {
		    /*
		     * all members have the same propfraction except those
		     *	that were excluded with -E
		     */
		continue;
	    }
	    cyclenlp -> time += childp -> time;
D 9
	    for ( arcp=childp->parents ; arcp ; arcp=arcp->arc_parentlist ) {
		parentp = arcp -> arc_parentp;
E 8
E 7
		if ( parentp == childp ) {
		    continue;
		}
D 8
		arcp = arclookup( parentp , childp );
		if ( arcp != 0 ) {
		    callsamong += arcp -> arc_count;
#		    ifdef DEBUG
			if ( debug & CYCLEDEBUG ) {
			    printf("[cyclelink] %s calls sibling %s %d times\n",
				parentp -> name , childp -> name ,
				arcp -> arc_count );
			}
#		    endif DEBUG
E 8
I 8
		if ( parentp -> cyclehead == cyclenlp ) {
		    cyclenlp -> selfcalls += arcp -> arc_count;
		} else {
		    cyclenlp -> ncall += arcp -> arc_count;
E 8
		}
	    }
E 9
	}
D 8
	    /*
	     *	collect calls and time around the cycle,
	     *	and save it in the cycle header.
	     */
	ncall = -callsamong;
	time = 0.0;
D 7
	for ( parentp = nlp ; parentp ; parentp = parentp -> cnext ) {
E 7
I 7
	for ( parentp = cyclenlp->cnext; parentp; parentp = parentp->cnext ) {
E 7
	    ncall += parentp -> ncall;
	    time += parentp -> time;
	}
#	ifdef DEBUG
	    if ( debug & CYCLEDEBUG ) {
		printf( "[cyclelink] cycle %d %f ticks in %d (%d) calls\n" ,
			cycle , time , ncall , callsamong );
	    }
#	endif DEBUG
	cyclenlp -> ncall = ncall;
	cyclenlp -> selfcalls = callsamong;
	cyclenlp -> time = time;
	cyclenlp -> childtime = 0.0;
E 8
I 8
	cyclenlp -> propself = cyclenlp -> propfraction * cyclenlp -> time;
E 8
I 7
    }
}

    /*
     *	in one top to bottom pass over the topologically sorted namelist
D 8
     *	set the print flags and sum up the time that will be shown in the
     *	graph profile.
E 8
I 8
     *	propagate:
     *		printflag as the union of parents' printflags
     *		propfraction as the sum of fractional parents' propfractions
     *	and while we're here, sum time for functions.
E 8
     */
doflags()
{
    int		index;
    nltype	*childp;
    nltype	*oldhead;

    oldhead = 0;
    for ( index = nname-1 ; index >= 0 ; index -= 1 ) {
	childp = topsortnlp[ index ];
	    /*
	     *	if we haven't done this function or cycle,
D 8
	     *	calculate its printflag.
E 8
I 8
	     *	inherit things from parent.
E 8
	     *	this way, we are linear in the number of arcs
	     *	since we do all members of a cycle (and the cycle itself)
	     *	as we hit the first member of the cycle.
	     */
	if ( childp -> cyclehead != oldhead ) {
	    oldhead = childp -> cyclehead;
D 8
	    parentprint( childp );
E 8
I 8
	    inheritflags( childp );
E 8
	}
I 8
#	ifdef DEBUG
	    if ( debug & PROPDEBUG ) {
		printf( "[doflags] " );
		printname( childp );
		printf( " inherits printflag %d and propfraction %f\n" ,
			childp -> printflag , childp -> propfraction );
	    }
#	endif DEBUG
E 8
	if ( ! childp -> printflag ) {
		/*
D 8
		 *	-f function says print the sucker
		 *	-e function says don't print it (leave it non-printing)
		 *	no -f's at all says print everything
E 8
I 8
		 *	printflag is off
		 *	it gets turned on by
		 *	being on -f list,
		 *	or there not being any -f list and not being on -e list.
E 8
		 */
D 8
	    if ( fflag && onflist( childp -> name ) ) {
E 8
I 8
	    if (   onlist( flist , childp -> name )
		|| ( !fflag && !onlist( elist , childp -> name ) ) ) {
E 8
		childp -> printflag = TRUE;
D 8
		printtime += childp -> time + childp -> childtime;
		continue;
E 8
	    }
D 8
	    if ( eflag && onelist( childp -> name ) ) {
		continue;
E 8
I 8
	} else {
		/*
		 *	this function has printing parents:
		 *	maybe someone wants to shut it up
		 *	by putting it on -e list.  (but favor -f over -e)
		 */
	    if (  ( !onlist( flist , childp -> name ) )
		&& onlist( elist , childp -> name ) ) {
		childp -> printflag = FALSE;
E 8
	    }
D 8
	    if ( !fflag ) {
		childp -> printflag = TRUE;
		printtime += childp -> time + childp -> childtime;
		continue;
E 8
I 8
	}
	if ( childp -> propfraction == 0.0 ) {
		/*
		 *	no parents to pass time to.
		 *	collect time from children if
		 *	its on -F list,
		 *	or there isn't any -F list and its not on -E list.
		 */
	    if ( onlist( Flist , childp -> name )
		|| ( !Fflag && !onlist( Elist , childp -> name ) ) ) {
		    childp -> propfraction = 1.0;
E 8
	    }
D 8
	    continue;
E 8
I 8
	} else {
		/*
		 *	it has parents to pass time to, 
		 *	but maybe someone wants to shut it up
		 *	by puttting it on -E list.  (but favor -F over -E)
		 */
	    if (  !onlist( Flist , childp -> name )
		&& onlist( Elist , childp -> name ) ) {
		childp -> propfraction = 0.0;
	    }
E 8
	}
D 8
	    /*
	     *	this function has printing parents:
	     *	maybe someone wants to shut it up.
	     */
	if ( eflag && onelist( childp -> name ) ) {
	    childp -> printflag = FALSE;
	    continue;
	}
E 8
I 8
	childp -> propself = childp -> time * childp -> propfraction;
	printtime += childp -> propself;
#	ifdef DEBUG
	    if ( debug & PROPDEBUG ) {
		printf( "[doflags] " );
		printname( childp );
		printf( " ends up with printflag %d and propfraction %f\n" ,
			childp -> printflag , childp -> propfraction );
D 12
		printf( "time %f propself %f\n" ,
			childp -> time , childp -> propself );
E 12
I 12
		printf( "time %f propself %f printtime %f\n" ,
			childp -> time , childp -> propself , printtime );
E 12
	    }
#	endif DEBUG
E 8
    }
}

    /*
     *	check if any parent of this child
     *	(or outside parents of this cycle)
     *	have their print flags on and set the 
     *	print flag of the child (cycle) appropriately.
I 8
     *	similarly, deal with propagation fractions from parents.
E 8
     */
D 8
parentprint( childp )
E 8
I 8
inheritflags( childp )
E 8
    nltype	*childp;
{
    nltype	*headp;
D 8
    nltype	*memp;
E 8
    arctype	*arcp;
I 8
    nltype	*parentp;
    nltype	*memp;
E 8

    headp = childp -> cyclehead;
    if ( childp == headp ) {
	    /*
	     *	just a regular child, check its parents
	     */
D 8
	for ( arcp = childp->parents ; arcp ; arcp = arcp->arc_parentlist ) {
	    if ( arcp -> arc_parentp -> printflag ) {
		childp -> printflag = TRUE;
		break;
	    }
E 8
I 8
	childp -> printflag = FALSE;
	childp -> propfraction = 0.0;
	for (arcp = childp -> parents ; arcp ; arcp = arcp -> arc_parentlist) {
	    parentp = arcp -> arc_parentp;
I 12
	    if ( childp == parentp ) {
		continue;
	    }
E 12
	    childp -> printflag |= parentp -> printflag;
D 14
	    childp -> propfraction += parentp -> propfraction
					* ( ( (double) arcp -> arc_count )
D 9
					  / ( (double) childp -> ncall) );
E 9
I 9
					  / ( (double) childp -> ncall ) );
E 14
I 14
		/*
		 *	if the child was never actually called
		 *	(e.g. this arc is static (and all others are, too))
		 *	no time propagates along this arc.
		 */
	    if ( childp -> ncall ) {
		childp -> propfraction += parentp -> propfraction
					    * ( ( (double) arcp -> arc_count )
					      / ( (double) childp -> ncall ) );
	    }
E 14
E 9
E 8
	}
D 8
	return;
    }
	/*
	 *	its a member of a cycle, look at all parents from 
	 *	outside the cycle
	 */
    for ( memp = headp -> cnext ; memp ; memp = memp -> cnext ) {
	for ( arcp = memp -> parents ; arcp ; arcp = arcp -> arc_parentlist ) {
	    if ( arcp -> arc_parentp -> cyclehead == headp ) {
		continue;
E 8
I 8
    } else {
	    /*
	     *	its a member of a cycle, look at all parents from 
	     *	outside the cycle
	     */
	headp -> printflag = FALSE;
	headp -> propfraction = 0.0;
	for ( memp = headp -> cnext ; memp ; memp = memp -> cnext ) {
	    for (arcp = memp->parents ; arcp ; arcp = arcp->arc_parentlist) {
		if ( arcp -> arc_parentp -> cyclehead == headp ) {
		    continue;
		}
		parentp = arcp -> arc_parentp;
		headp -> printflag |= parentp -> printflag;
D 9
		headp -> propfraction += parentp -> propfraction *
					(arcp -> arc_count / headp -> ncall);
E 9
I 9
D 14
		headp -> propfraction += parentp -> propfraction
					* ( ( (double) arcp -> arc_count )
					  / ( (double) headp -> ncall ) );
E 14
I 14
		    /*
		     *	if the cycle was never actually called
		     *	(e.g. this arc is static (and all others are, too))
		     *	no time propagates along this arc.
		     */
		if ( headp -> ncall ) {
		    headp -> propfraction += parentp -> propfraction
					    * ( ( (double) arcp -> arc_count )
					      / ( (double) headp -> ncall ) );
		}
E 14
E 9
E 8
	    }
D 8
	    if ( arcp -> arc_parentp -> printflag ) {
		goto set;
	    }
E 8
	}
D 8
    }
    return;
	/*
	 *	the cycle has a printing parent:  set the cycle
	 */
set:
    for ( memp = headp ; memp ; memp = memp -> cnext ) {
	memp -> printflag = TRUE;
E 8
I 8
	for ( memp = headp ; memp ; memp = memp -> cnext ) {
	    memp -> printflag = headp -> printflag;
	    memp -> propfraction = headp -> propfraction;
	}
E 8
E 7
    }
}
E 1
