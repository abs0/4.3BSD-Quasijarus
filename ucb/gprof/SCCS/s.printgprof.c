h37235
s 00010/00005/00691
d D 5.5 88/06/29 19:23:19 bostic 21 20
c install approved copyright notice
e
s 00009/00003/00687
d D 5.4 88/05/05 17:50:19 bostic 20 19
c add Berkeley specific header; written by K. McKusick and P. Kessler
e
s 00001/00001/00689
d D 5.3 88/01/02 23:48:15 bostic 19 18
c declare timecmp for ANSI C
e
s 00002/00002/00688
d D 5.2 87/04/06 12:06:36 bostic 18 17
c printf format/argument mismatch
e
s 00008/00002/00682
d D 5.1 85/06/04 13:29:48 dist 17 16
c Add copyright
e
s 00085/00042/00599
d D 1.15 84/08/07 11:32:34 mckusick 16 15
c add alphabetical index printing routine; minor format changes;
c add ms/call to flat profile listing
e
s 00006/00006/00635
d D 1.14 83/03/30 20:37:52 peter 15 13
c don't reference through nil pointers, since that doesn't work on a 68000.
e
s 00006/00006/00635
d R 1.14 83/03/30 20:33:34 peter 14 13
c changes by richard tuck from sun.
e
s 00004/00006/00637
d D 1.13 83/01/15 13:14:33 peter 13 12
c make the names of the blurb files more reasonable;
c and distribute them less around the code.
e
s 00010/00010/00633
d D 1.12 83/01/11 15:05:29 peter 12 11
c sampling frequency changes from a constant to a variable.
e
s 00020/00003/00623
d D 1.11 82/06/19 09:18:00 peter 11 10
c what to do if there's no time accumulated.
e
s 00024/00017/00602
d D 1.10 82/06/18 20:21:42 peter 10 9
c -e -E -f and -F flags, this time for sure.
e
s 00016/00004/00603
d D 1.9 82/06/14 18:08:25 peter 9 8
c -f and -e flags.
e
s 00009/00009/00598
d D 1.8 82/06/08 11:29:15 peter 8 7
c cycle headers have their own namelist.
e
s 00000/00003/00607
d D 1.7 81/11/12 15:07:58 mckusic 7 6
c put blurb in /usr/lib
e
s 00048/00004/00562
d D 1.6 81/11/10 23:02:56 peter 6 5
c fine tune some of the sorting.
e
s 00033/00004/00533
d D 1.5 81/11/10 21:05:31 peter 5 4
c add the -b option to print a blurb about the listings.
e
s 00005/00006/00532
d D 1.4 81/11/09 14:12:30 peter 4 3
c print cycle indication before index.
e
s 00241/00027/00297
d D 1.3 81/11/06 17:43:01 peter 3 2
c totally changed printing formats.
e
s 00002/00002/00322
d D 1.2 81/10/20 15:50:02 peter 2 1
c name change to confuse to innocent/
e
s 00324/00000/00000
d D 1.1 81/10/15 13:47:22 peter 1 0
c date and time created 81/10/15 13:47:22 by peter
e
u
U
t
T
I 17
/*
 * Copyright (c) 1983 Regents of the University of California.
D 20
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 20
I 20
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 21
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 21
I 21
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
E 21
E 20
 */

E 17
I 1
#ifndef lint
D 17
    static	char *sccsid = "%W% (Berkeley) %G%";
#endif lint
E 17
I 17
static char sccsid[] = "%W% (Berkeley) %G%";
D 20
#endif not lint
E 20
I 20
#endif /* not lint */
E 20
E 17

D 2
#include "dprof.h"
E 2
I 2
#include "gprof.h"
E 2

I 3
printprof()
{
    register nltype	*np;
    nltype		**sortednlp;
D 19
    int			index;
E 19
I 19
    int			index, timecmp();
E 19

I 5
D 9
    printf( "\ngranularity: each sample hit covers %d byte(s)" , (long) scale );
E 9
I 9
D 16
    printf( "\ngranularity: each sample hit covers %d byte(s)" ,
	    (long) scale * sizeof(UNIT) );
E 9
D 11
    printf( " for %.2f%% of %.2f seconds\n\n" , 100.0/totime , totime / HZ );
E 11
I 11
    if ( totime > 0.0 ) {
	printf( " for %.2f%% of %.2f seconds\n\n" ,
D 12
		100.0/totime , totime / HZ );
E 12
I 12
		100.0/totime , totime / hz );
E 12
    } else {
	printf( " no time accumulated\n\n" );
	    /*
	     *	this doesn't hurt sinc eall the numerators will be zero.
	     */
	totime = 1.0;
    }
E 16
E 11
E 5
    actime = 0.0;
I 16
    printf( "\f\n" );
E 16
    flatprofheader();
	/*
	 *	Sort the symbol table in by time
	 */
    sortednlp = (nltype **) calloc( nname , sizeof(nltype *) );
    if ( sortednlp == (nltype **) 0 ) {
	fprintf( stderr , "[printprof] ran out of memory for time sorting\n" );
    }
    for ( index = 0 ; index < nname ; index += 1 ) {
	sortednlp[ index ] = &nl[ index ];
    }
    qsort( sortednlp , nname , sizeof(nltype *) , timecmp );
    for ( index = 0 ; index < nname ; index += 1 ) {
	np = sortednlp[ index ];
	flatprofline( np );
    }
    actime = 0.0;
I 16
    cfree( sortednlp );
E 16
D 5
    printf( "\ngranularity: each sample hit covers %.1f bytes" , scale );
    printf( " for %.2f%% of %.2f seconds\n" , 100.0/totime , totime / HZ );
E 5
}

timecmp( npp1 , npp2 )
    nltype **npp1, **npp2;
{
D 6
    double d;
E 6
I 6
    double	timediff;
    long	calldiff;
E 6

D 6
    d = (*npp2) -> time - (*npp1) -> time;
    if ( d > 0.0 )
E 6
I 6
    timediff = (*npp2) -> time - (*npp1) -> time;
    if ( timediff > 0.0 )
E 6
	return 1 ;
D 6
    if ( d < 0.0 )
E 6
I 6
    if ( timediff < 0.0 )
E 6
	return -1;
I 6
    calldiff = (*npp2) -> ncall - (*npp1) -> ncall;
    if ( calldiff > 0 )
	return 1;
    if ( calldiff < 0 )
	return -1;
E 6
    return( strcmp( (*npp1) -> name , (*npp2) -> name ) );
}

    /*
     *	header for flatprofline
     */
flatprofheader()
{
    
I 5
    if ( bflag ) {
D 13
	printblurb( "flat.blurb" );
E 13
I 13
	printblurb( FLAT_BLURB );
E 13
    }
E 5
D 16
    printf( "%5.5s %7.7s %7.7s %7.7s %-8.8s\n" ,
	    "%time" , "cumsecs" , "seconds" , "calls" , "name" );
E 16
I 16
    printf( "\ngranularity: each sample hit covers %d byte(s)" ,
	    (long) scale * sizeof(UNIT) );
    if ( totime > 0.0 ) {
	printf( " for %.2f%% of %.2f seconds\n\n" ,
		100.0/totime , totime / hz );
    } else {
	printf( " no time accumulated\n\n" );
	    /*
	     *	this doesn't hurt sinc eall the numerators will be zero.
	     */
	totime = 1.0;
    }
    printf( "%5.5s %10.10s %8.8s %8.8s %8.8s %8.8s  %-8.8s\n" ,
	    "%  " , "cumulative" , "self  " , "" , "self  " , "total " , "" );
    printf( "%5.5s %10.10s %8.8s %8.8s %8.8s %8.8s  %-8.8s\n" ,
	    "time" , "seconds " , "seconds" , "calls" ,
	    "ms/call" , "ms/call" , "name" );
E 16
}

flatprofline( np )
    register nltype	*np;
{

D 5
    if ( zflg == 0 && np -> ncall == 0 && np -> time == 0 ) {
E 5
I 5
    if ( zflag == 0 && np -> ncall == 0 && np -> time == 0 ) {
E 5
	return;
    }
    actime += np -> time;
D 16
    printf( "%5.1f %7.2f %7.2f" ,
E 16
I 16
    printf( "%5.1f %10.2f %8.2f" ,
E 16
D 12
	100 * np -> time / totime , actime / HZ , np -> time / HZ );
E 12
I 12
	100 * np -> time / totime , actime / hz , np -> time / hz );
E 12
    if ( np -> ncall != 0 ) {
D 16
	printf( " %7d" , np -> ncall );
E 16
I 16
	printf( " %8d %8.2f %8.2f  " , np -> ncall ,
	    1000 * np -> time / hz / np -> ncall ,
	    1000 * ( np -> time + np -> childtime ) / hz / np -> ncall );
E 16
    } else {
D 16
	printf( " %7.7s" , "" );
E 16
I 16
	printf( " %8.8s %8.8s %8.8s  " , "" , "" , "" );
E 16
    }
D 16
    printf( " %s\n" , np -> name );
E 16
I 16
    printname( np );
    printf( "\n" );
E 16
}

gprofheader()
{
I 5

    if ( bflag ) {
D 13
	printblurb( "callg.blurb" );
E 13
I 13
	printblurb( CALLG_BLURB );
E 13
    }
I 9
    printf( "\ngranularity: each sample hit covers %d byte(s)" ,
	    (long) scale * sizeof(UNIT) );
D 11
    printf( " for %.2f%% of %.2f seconds\n\n" ,
	    100.0/printtime , printtime / HZ );
E 11
I 11
    if ( printtime > 0.0 ) {
	printf( " for %.2f%% of %.2f seconds\n\n" ,
D 12
		100.0/printtime , printtime / HZ );
E 12
I 12
		100.0/printtime , printtime / hz );
E 12
    } else {
	printf( " no time propagated\n\n" );
	    /*
	     *	this doesn't hurt, since all the numerators will be 0.0
	     */
	printtime = 1.0;
    }
E 11
E 9
E 5
    printf( "%6.6s %5.5s %7.7s %11.11s %7.7s/%-7.7s     %-8.8s\n" ,
D 18
	"" , "" , "" , "" , "called" , "total" , "parents" , "" );
E 18
I 18
	"" , "" , "" , "" , "called" , "total" , "parents");
E 18
    printf( "%-6.6s %5.5s %7.7s %11.11s %7.7s+%-7.7s %-8.8s\t%5.5s\n" ,
	"index" , "%time" , "self" , "descendents" ,
	"called" , "self" , "name" , "index" );
    printf( "%6.6s %5.5s %7.7s %11.11s %7.7s/%-7.7s     %-8.8s\n" ,
D 18
	"" , "" , "" , "" , "called" , "total" , "children" , "" );
E 18
I 18
	"" , "" , "" , "" , "called" , "total" , "children");
E 18
    printf( "\n" );
}

gprofline( np )
    register nltype	*np;
{
    char	kirkbuffer[ BUFSIZ ];

    sprintf( kirkbuffer , "[%d]" , np -> index );
    printf( "%-6.6s %5.1f %7.2f %11.2f" ,
	    kirkbuffer ,
D 9
	    100 * ( np -> time + np -> childtime ) / totime ,
E 9
I 9
D 10
	    100 * ( np -> time + np -> childtime ) / printtime ,
E 9
	    np -> time / HZ ,
	    np -> childtime / HZ );
E 10
I 10
	    100 * ( np -> propself + np -> propchild ) / printtime ,
D 12
	    np -> propself / HZ ,
	    np -> propchild / HZ );
E 12
I 12
	    np -> propself / hz ,
	    np -> propchild / hz );
E 12
E 10
    if ( ( np -> ncall + np -> selfcalls ) != 0 ) {
	printf( " %7d" , np -> ncall );
	if ( np -> selfcalls != 0 ) {
	    printf( "+%-7d " , np -> selfcalls );
	} else {
	    printf( " %7.7s " , "" );
	}
    } else {
	printf( " %7.7s %7.7s " , "" , "" );
    }
    printname( np );
    printf( "\n" );
}

E 3
D 2
printdprof()
E 2
I 2
D 16
printgprof()
E 2
{
E 16
I 16
printgprof(timesortnlp)
E 16
    nltype	**timesortnlp;
I 16
{
E 16
    int		index;
    nltype	*parentp;
D 4
    nltype	*childp;
E 4

	/*
D 10
	 *	Now, sort by time + childtime.
E 10
I 10
D 16
	 *	Now, sort by propself + propchild.
E 10
D 8
	 *	include the cycle headers hiding out past nl[nname].
I 3
	 *	don't include the dummy hiding at nl[nname].
E 8
I 8
	 *	sorting both the regular function names
	 *	and cycle headers.
E 16
I 16
	 *	Print out the structured profiling list
E 16
E 8
E 3
	 */
D 3
    timesortnlp = (nltype **) calloc( nname+1+cyclemax , sizeof(nltype *) );
E 3
I 3
D 8
    timesortnlp = (nltype **) calloc( nname + cyclemax , sizeof(nltype *) );
E 8
I 8
D 16
    timesortnlp = (nltype **) calloc( nname + ncycle , sizeof(nltype *) );
E 8
E 3
    if ( timesortnlp == (nltype **) 0 ) {
D 8
	fprintf( stderr , "[doarcs] ran out of memory for sorting\n" );
E 8
I 8
	fprintf( stderr , "%s: ran out of memory for sorting\n" , whoami );
E 8
    }
D 3
    for ( index = 0 ; index < nname+1+cyclemax ; index++ ) {
E 3
I 3
    for ( index = 0 ; index < nname ; index++ ) {
E 3
	timesortnlp[index] = &nl[index];
    }
D 3
    qsort( timesortnlp , nname+1+cyclemax , sizeof(nltype *) , totalcmp );
    for ( index = 0 ; index < nname+1+cyclemax ; index++ ) {
E 3
I 3
D 8
    for ( index = 1 ; index <= cyclemax ; index++ ) {
	timesortnlp[(nname-1)+index] = &nl[nname+index];
E 8
I 8
    for ( index = 1 ; index <= ncycle ; index++ ) {
	timesortnlp[nname+index-1] = &cyclenl[index];
E 8
    }
D 8
    qsort( timesortnlp , nname + cyclemax , sizeof(nltype *) , totalcmp );
    for ( index = 0 ; index < nname + cyclemax ; index++ ) {
E 8
I 8
    qsort( timesortnlp , nname + ncycle , sizeof(nltype *) , totalcmp );
    for ( index = 0 ; index < nname + ncycle ; index++ ) {
E 8
E 3
	timesortnlp[ index ] -> index = index + 1;
    }
	/*
	 *	Now, print out the structured profiling list
	 */
D 3
    actime = 0.0;
    printf( "\f" );
    putprofheader();
    for ( index = 0 ; index < nname + 1 + cyclemax ; index ++ ) {
E 3
I 3
    printf( "\f\n" );
E 16
    gprofheader();
D 8
    for ( index = 0 ; index < nname + cyclemax ; index ++ ) {
E 8
I 8
    for ( index = 0 ; index < nname + ncycle ; index ++ ) {
E 8
E 3
	parentp = timesortnlp[ index ];
D 5
	if ( zflg == 0 &&
E 5
I 5
	if ( zflag == 0 &&
E 5
	     parentp -> ncall == 0 &&
	     parentp -> selfcalls == 0 &&
D 10
	     parentp -> time == 0 &&
	     parentp -> childtime == 0 ) {
E 10
I 10
	     parentp -> propself == 0 &&
	     parentp -> propchild == 0 ) {
E 10
	    continue;
	}
I 9
	if ( ! parentp -> printflag ) {
	    continue;
	}
E 9
	if ( parentp -> name == 0 && parentp -> cycleno != 0 ) {
		/*
		 *	cycle header
		 */
D 3
	    putprofline( parentp , 0 );
	    for ( childp = parentp->cnext ; childp ; childp = childp->cnext ) {
		putprofline( childp , 0 );
	    }
E 3
I 3
	    printcycle( parentp );
	    printmembers( parentp );
E 3
	} else {
	    printparents( parentp );
D 3
	    putprofline( parentp , 1 );
E 3
I 3
	    gprofline( parentp );
E 3
	    printchildren( parentp );
	}
	printf( "\n" );
I 3
	printf( "-----------------------------------------------\n" );
	printf( "\n" );
E 3
    }
I 16
    cfree( timesortnlp );
E 16
I 6
}

    /*
D 10
     *	sort by decreasing total time (time+childtime)
E 10
I 10
     *	sort by decreasing propagated time
E 10
     *	if times are equal, but one is a cycle header,
     *		say that's first (e.g. less, i.e. -1).
     *	if one's name doesn't have an underscore and the other does,
     *		say the one is first.
     *	all else being equal, sort by names.
     */
int
totalcmp( npp1 , npp2 )
    nltype	**npp1;
    nltype	**npp2;
{
    register nltype	*np1 = *npp1;
    register nltype	*np2 = *npp2;
    double		diff;

D 10
    diff =    ( np1 -> time + np1 -> childtime )
	    - ( np2 -> time + np2 -> childtime );
E 10
I 10
    diff =    ( np1 -> propself + np1 -> propchild )
	    - ( np2 -> propself + np2 -> propchild );
E 10
    if ( diff < 0.0 )
	    return 1;
    if ( diff > 0.0 )
	    return -1;
    if ( np1 -> name == 0 && np1 -> cycleno != 0 ) 
	return -1;
    if ( np2 -> name == 0 && np2 -> cycleno != 0 )
	return 1;
    if ( np1 -> name == 0 )
	return -1;
    if ( np2 -> name == 0 )
	return 1;
    if ( *(np1 -> name) != '_' && *(np2 -> name) == '_' )
	return -1;
    if ( *(np1 -> name) == '_' && *(np2 -> name) != '_' )
	return 1;
I 10
    if ( np1 -> ncall > np2 -> ncall )
	return -1;
    if ( np1 -> ncall < np2 -> ncall ) 
	return 1;
E 10
    return strcmp( np1 -> name , np2 -> name );
E 6
D 3
    actime = 0.0;
E 3
}

printparents( childp )
    nltype	*childp;
{
    nltype	*parentp;
    arctype	*arcp;
    nltype	*cycleheadp;

    if ( childp -> cyclehead != 0 ) {
	cycleheadp = childp -> cyclehead;
    } else {
	cycleheadp = childp;
    }
    if ( childp -> parents == 0 ) {
D 3
	printf( "\t%5.5s %7.7s %7.7s %7.7s %7.7s %7.7s      <spontaneous>\n" ,
E 3
I 3
	printf( "%6.6s %5.5s %7.7s %11.11s %7.7s %7.7s     <spontaneous>\n" ,
E 3
		"" , "" , "" , "" , "" , "" );
	return;
    }
    sortparents( childp );
    for ( arcp = childp -> parents ; arcp ; arcp = arcp -> arc_parentlist ) {
	parentp = arcp -> arc_parentp;
	if ( childp == parentp ||
	     ( childp->cycleno != 0 && parentp->cycleno == childp->cycleno ) ) {
		/*
D 3
		 *	selfcall or call amoung siblings
E 3
I 3
		 *	selfcall or call among siblings
E 3
		 */
D 3
	    printf( "\t%5.5s %7.7s %7.7s %7.7s %7d %7.7s      " ,
E 3
I 3
	    printf( "%6.6s %5.5s %7.7s %11.11s %7d %7.7s     " ,
E 3
		    "" , "" , "" , "" ,
		    arcp -> arc_count , "" );
	    printname( parentp );
	    printf( "\n" );
	} else {
		/*
		 *	regular parent of child
		 */
D 3
	    printf( "\t%5.5s %7.7s %7.1f %7.1f %7d/%-7d      " , "" , "" ,
E 3
I 3
	    printf( "%6.6s %5.5s %7.2f %11.2f %7d/%-7d     " ,
		    "" , "" ,
E 3
D 12
		    arcp -> arc_time / HZ , arcp -> arc_childtime / HZ ,
E 12
I 12
		    arcp -> arc_time / hz , arcp -> arc_childtime / hz ,
E 12
		    arcp -> arc_count , cycleheadp -> ncall );
	    printname( parentp );
	    printf( "\n" );
	}
    }
}

printchildren( parentp )
    nltype	*parentp;
{
    nltype	*childp;
    arctype	*arcp;

    sortchildren( parentp );
    arcp = parentp -> children;
    for ( arcp = parentp -> children ; arcp ; arcp = arcp -> arc_childlist ) {
	childp = arcp -> arc_childp;
	if ( childp == parentp ||
	    ( childp->cycleno != 0 && childp->cycleno == parentp->cycleno ) ) {
		/*
		 *	self call or call to sibling
		 */
D 3
	    printf( "\t%5.5s %7.7s %7.7s %7.7s %7d %7.7s      " ,
		    "" , "" , "" , "" ,
		    arcp -> arc_count , "" );
E 3
I 3
	    printf( "%6.6s %5.5s %7.7s %11.11s %7d %7.7s     " ,
		    "" , "" , "" , "" , arcp -> arc_count , "" );
E 3
	    printname( childp );
	    printf( "\n" );
	} else {
		/*
		 *	regular child of parent
		 */
D 3
	    printf( "\t%5.5s %7.7s %7.1f %7.1f %7d/%-7d      " , "" , "" ,
E 3
I 3
	    printf( "%6.6s %5.5s %7.2f %11.2f %7d/%-7d     " ,
		    "" , "" ,
E 3
D 12
		    arcp -> arc_time / HZ , arcp -> arc_childtime / HZ ,
E 12
I 12
		    arcp -> arc_time / hz , arcp -> arc_childtime / hz ,
E 12
		    arcp -> arc_count , childp -> cyclehead -> ncall );
	    printname( childp );
	    printf( "\n" );
	}
    }
}

printname( selfp )
    nltype	*selfp;
{

    if ( selfp -> name != 0 ) {
D 3
	printf( "%s\t" , selfp -> name );
	if ( selfp -> index != 0 ) {
	    printf( "[%d] " , selfp -> index );
	}
E 3
I 3
	printf( "%s" , selfp -> name );
E 3
#	ifdef DEBUG
	    if ( debug & DFNDEBUG ) {
		printf( "{%d} " , selfp -> toporder );
	    }
I 10
	    if ( debug & PROPDEBUG ) {
		printf( "%5.2f%% " , selfp -> propfraction );
	    }
E 10
#	endif DEBUG
    }
I 3
D 4
    if ( selfp -> index != 0 ) {
	printf( "\t[%d]" , selfp -> index );
    }
E 4
E 3
    if ( selfp -> cycleno != 0 ) {
D 3
	printf( "<cycle %d>" , selfp -> cycleno );
E 3
I 3
D 4
	printf( " <cycle %d>" , selfp -> cycleno );
E 4
I 4
D 16
	printf( "\t<cycle %d>" , selfp -> cycleno );
E 16
I 16
	printf( " <cycle %d>" , selfp -> cycleno );
E 16
E 4
E 3
    }
I 4
    if ( selfp -> index != 0 ) {
D 9
	printf( " [%d]" , selfp -> index );
E 9
I 9
	if ( selfp -> printflag ) {
	    printf( " [%d]" , selfp -> index );
	} else {
	    printf( " (%d)" , selfp -> index );
	}
E 9
    }
E 4
}

sortchildren( parentp )
    nltype	*parentp;
{
    arctype	*arcp;
    arctype	*detachedp;
    arctype	sorted;
    arctype	*prevp;

	/*
	 *	unlink children from parent,
	 *	then insertion sort back on to sorted's children.
	 *	    *arcp	the arc you have detached and are inserting.
	 *	    *detachedp	the rest of the arcs to be sorted.
	 *	    sorted	arc list onto which you insertion sort.
	 *	    *prevp	arc before the arc you are comparing.
	 */
    sorted.arc_childlist = 0;
D 15
    for (   arcp = parentp -> children , detachedp = arcp -> arc_childlist ;
E 15
I 15
    for (  (arcp = parentp -> children)&&(detachedp = arcp -> arc_childlist);
E 15
	    arcp ;
D 15
	    arcp = detachedp , detachedp = detachedp -> arc_childlist ) {
E 15
I 15
	   (arcp = detachedp)&&(detachedp = detachedp -> arc_childlist)) {
E 15
	    /*
	     *	consider *arcp as disconnected
	     *	insert it into sorted
	     */
	for (   prevp = &sorted ;
		prevp -> arc_childlist ;
		prevp = prevp -> arc_childlist ) {
	    if ( arccmp( arcp , prevp -> arc_childlist ) != LESSTHAN ) {
		break;
	    }
	}
	arcp -> arc_childlist = prevp -> arc_childlist;
	prevp -> arc_childlist = arcp;
    }
	/*
	 *	reattach sorted children to parent
	 */
    parentp -> children = sorted.arc_childlist;
}

sortparents( childp )
    nltype	*childp;
{
    arctype	*arcp;
    arctype	*detachedp;
    arctype	sorted;
    arctype	*prevp;

	/*
	 *	unlink parents from child,
	 *	then insertion sort back on to sorted's parents.
	 *	    *arcp	the arc you have detached and are inserting.
	 *	    *detachedp	the rest of the arcs to be sorted.
	 *	    sorted	arc list onto which you insertion sort.
	 *	    *prevp	arc before the arc you are comparing.
	 */
    sorted.arc_parentlist = 0;
D 15
    for (   arcp = childp -> parents , detachedp = arcp -> arc_parentlist ;
E 15
I 15
    for (  (arcp = childp -> parents)&&(detachedp = arcp -> arc_parentlist);
E 15
	    arcp ;
D 15
	    arcp = detachedp , detachedp = detachedp -> arc_parentlist ) {
E 15
I 15
	   (arcp = detachedp)&&(detachedp = detachedp -> arc_parentlist)) {
E 15
	    /*
	     *	consider *arcp as disconnected
	     *	insert it into sorted
	     */
	for (   prevp = &sorted ;
		prevp -> arc_parentlist ;
		prevp = prevp -> arc_parentlist ) {
	    if ( arccmp( arcp , prevp -> arc_parentlist ) != GREATERTHAN ) {
		break;
	    }
	}
	arcp -> arc_parentlist = prevp -> arc_parentlist;
	prevp -> arc_parentlist = arcp;
    }
	/*
	 *	reattach sorted arcs to child
	 */
    childp -> parents = sorted.arc_parentlist;
}

I 3
    /*
     *	print a cycle header
     */
printcycle( cyclep )
    nltype	*cyclep;
{
    char	kirkbuffer[ BUFSIZ ];

    sprintf( kirkbuffer , "[%d]" , cyclep -> index );
    printf( "%-6.6s %5.1f %7.2f %11.2f %7d" ,
	    kirkbuffer ,
D 9
	    100 * ( cyclep -> time + cyclep -> childtime ) / totime ,
E 9
I 9
D 10
	    100 * ( cyclep -> time + cyclep -> childtime ) / printtime ,
E 9
	    cyclep -> time / HZ ,
	    cyclep -> childtime / HZ ,
E 10
I 10
	    100 * ( cyclep -> propself + cyclep -> propchild ) / printtime ,
D 12
	    cyclep -> propself / HZ ,
	    cyclep -> propchild / HZ ,
E 12
I 12
	    cyclep -> propself / hz ,
	    cyclep -> propchild / hz ,
E 12
E 10
	    cyclep -> ncall );
    if ( cyclep -> selfcalls != 0 ) {
	printf( "+%-7d" , cyclep -> selfcalls );
    } else {
	printf( " %7.7s" , "" );
    }
    printf( " <cycle %d as a whole>\t[%d]\n" ,
	    cyclep -> cycleno , cyclep -> index );
}

    /*
     *	print the members of a cycle
     */
printmembers( cyclep )
    nltype	*cyclep;
{
    nltype	*memberp;

    sortmembers( cyclep );
    for ( memberp = cyclep -> cnext ; memberp ; memberp = memberp -> cnext ) {
	printf( "%6.6s %5.5s %7.2f %11.2f %7d" , 
D 10
		"" , "" , memberp -> time / HZ , memberp -> childtime / HZ ,
E 10
I 10
D 12
		"" , "" , memberp -> propself / HZ , memberp -> propchild / HZ ,
E 12
I 12
		"" , "" , memberp -> propself / hz , memberp -> propchild / hz ,
E 12
E 10
		memberp -> ncall );
	if ( memberp -> selfcalls != 0 ) {
	    printf( "+%-7d" , memberp -> selfcalls );
	} else {
	    printf( " %7.7s" , "" );
	}
	printf( "     " );
	printname( memberp );
	printf( "\n" );
    }
}

    /*
     *	sort members of a cycle
     */
sortmembers( cyclep )
    nltype	*cyclep;
{
    nltype	*todo;
    nltype	*doing;
    nltype	*prev;

	/*
	 *	detach cycle members from cyclehead,
	 *	and insertion sort them back on.
	 */
    todo = cyclep -> cnext;
    cyclep -> cnext = 0;
D 15
    for (   doing = todo , todo = doing -> cnext ;
E 15
I 15
    for (  (doing = todo)&&(todo = doing -> cnext);
E 15
	    doing ;
D 15
	    doing = todo , todo = doing -> cnext ) {
E 15
I 15
	   (doing = todo )&&(todo = doing -> cnext )){
E 15
	for ( prev = cyclep ; prev -> cnext ; prev = prev -> cnext ) {
	    if ( membercmp( doing , prev -> cnext ) == GREATERTHAN ) {
		break;
	    }
	}
	doing -> cnext = prev -> cnext;
	prev -> cnext = doing;
    }
}

    /*
D 10
     *	major sort is on time + childtime,
E 10
I 10
     *	major sort is on propself + propchild,
E 10
     *	next is sort on ncalls + selfcalls.
     */
D 4
long
E 4
I 4
int
E 4
membercmp( this , that )
    nltype	*this;
    nltype	*that;
{
D 10
    double	thistime = this -> time + this -> childtime;
    double	thattime = that -> time + that -> childtime;
E 10
I 10
    double	thistime = this -> propself + this -> propchild;
    double	thattime = that -> propself + that -> propchild;
E 10
    long	thiscalls = this -> ncall + this -> selfcalls;
    long	thatcalls = that -> ncall + that -> selfcalls;

    if ( thistime > thattime ) {
	return GREATERTHAN;
    }
    if ( thistime < thattime ) {
	return LESSTHAN;
    }
    if ( thiscalls > thatcalls ) {
	return GREATERTHAN;
    }
    if ( thiscalls < thatcalls ) {
	return LESSTHAN;
    }
    return EQUALTO;
}
E 3
    /*
     *	compare two arcs to/from the same child/parent.
     *	- if one arc is a self arc, it's least.
     *	- if one arc is within a cycle, it's less than.
     *	- if both arcs are within a cycle, compare arc counts.
     *	- if neither arc is within a cycle, compare with
D 10
     *		time + childtime as major key
E 10
I 10
     *		arc_time + arc_childtime as major key
E 10
     *		arc count as minor key
     */
int
arccmp( thisp , thatp )
    arctype	*thisp;
    arctype	*thatp;
{
    nltype	*thisparentp = thisp -> arc_parentp;
    nltype	*thischildp = thisp -> arc_childp;
    nltype	*thatparentp = thatp -> arc_parentp;
    nltype	*thatchildp = thatp -> arc_childp;
    double	thistime;
    double	thattime;

#   ifdef DEBUG
	if ( debug & TIMEDEBUG ) {
	    printf( "[arccmp] " );
	    printname( thisparentp );
	    printf( " calls " );
	    printname ( thischildp );
	    printf( " %f + %f %d/%d\n" ,
		    thisp -> arc_time , thisp -> arc_childtime ,
		    thisp -> arc_count , thischildp -> ncall );
	    printf( "[arccmp] " );
	    printname( thatparentp );
	    printf( " calls " );
	    printname( thatchildp );
	    printf( " %f + %f %d/%d\n" ,
		    thatp -> arc_time , thatp -> arc_childtime ,
		    thatp -> arc_count , thatchildp -> ncall );
	    printf( "\n" );
	}
#   endif DEBUG
    if ( thisparentp == thischildp ) {
	    /* this is a self call */
	return LESSTHAN;
    }
    if ( thatparentp == thatchildp ) {
	    /* that is a self call */
	return GREATERTHAN;
    }
    if ( thisparentp -> cycleno != 0 && thischildp -> cycleno != 0 &&
	thisparentp -> cycleno == thischildp -> cycleno ) {
	    /* this is a call within a cycle */
	if ( thatparentp -> cycleno != 0 && thatchildp -> cycleno != 0 &&
	    thatparentp -> cycleno == thatchildp -> cycleno ) {
		/* that is a call within the cycle, too */
	    if ( thisp -> arc_count < thatp -> arc_count ) {
		return LESSTHAN;
	    }
	    if ( thisp -> arc_count > thatp -> arc_count ) {
		return GREATERTHAN;
	    }
	    return EQUALTO;
	} else {
		/* that isn't a call within the cycle */
	    return LESSTHAN;
	}
    } else {
	    /* this isn't a call within a cycle */
	if ( thatparentp -> cycleno != 0 && thatchildp -> cycleno != 0 &&
	    thatparentp -> cycleno == thatchildp -> cycleno ) {
		/* that is a call within a cycle */
	    return GREATERTHAN;
	} else {
		/* neither is a call within a cycle */
	    thistime = thisp -> arc_time + thisp -> arc_childtime;
	    thattime = thatp -> arc_time + thatp -> arc_childtime;
	    if ( thistime < thattime )
		return LESSTHAN;
	    if ( thistime > thattime )
		return GREATERTHAN;
	    if ( thisp -> arc_count < thatp -> arc_count )
		return LESSTHAN;
	    if ( thisp -> arc_count > thatp -> arc_count )
		return GREATERTHAN;
	    return EQUALTO;
	}
    }
I 5
}

printblurb( blurbname )
    char	*blurbname;
{
D 13
    char	pathname[ BUFSIZ ];
E 13
    FILE	*blurbfile;
    int		input;

D 7
#   ifndef BLURBLIB
#	define BLURBLIB	"./"
#   endif not BLURBLIB
E 7
D 13
    sprintf( pathname , "%s%s" , BLURBLIB , blurbname );
    blurbfile = fopen( pathname , "r" );
E 13
I 13
    blurbfile = fopen( blurbname , "r" );
E 13
    if ( blurbfile == NULL ) {
D 13
	perror( pathname );
E 13
I 13
	perror( blurbname );
E 13
	return;
    }
    while ( ( input = getc( blurbfile ) ) != EOF ) {
	putchar( input );
    }
    fclose( blurbfile );
I 16
}

int
namecmp( npp1 , npp2 )
    nltype **npp1, **npp2;
{
    return( strcmp( (*npp1) -> name , (*npp2) -> name ) );
}

printindex()
{
    nltype		**namesortnlp;
    register nltype	*nlp;
    int			index, nnames, todo, i, j;
    char		peterbuffer[ BUFSIZ ];

	/*
	 *	Now, sort regular function name alphbetically
	 *	to create an index.
	 */
    namesortnlp = (nltype **) calloc( nname + ncycle , sizeof(nltype *) );
    if ( namesortnlp == (nltype **) 0 ) {
	fprintf( stderr , "%s: ran out of memory for sorting\n" , whoami );
    }
    for ( index = 0 , nnames = 0 ; index < nname ; index++ ) {
	if ( zflag == 0 && nl[index].ncall == 0 && nl[index].time == 0 )
		continue;
	namesortnlp[nnames++] = &nl[index];
    }
    qsort( namesortnlp , nnames , sizeof(nltype *) , namecmp );
    for ( index = 1 , todo = nnames ; index <= ncycle ; index++ ) {
	namesortnlp[todo++] = &cyclenl[index];
    }
    printf( "\f\nIndex by function name\n\n" );
    index = ( todo + 2 ) / 3;
    for ( i = 0; i < index ; i++ ) {
	for ( j = i; j < todo ; j += index ) {
	    nlp = namesortnlp[ j ];
	    if ( nlp -> printflag ) {
		sprintf( peterbuffer , "[%d]" , nlp -> index );
	    } else {
		sprintf( peterbuffer , "(%d)" , nlp -> index );
	    }
	    if ( j < nnames ) {
		printf( "%6.6s %-19.19s" , peterbuffer , nlp -> name );
	    } else {
		printf( "%6.6s " , peterbuffer );
		sprintf( peterbuffer , "<cycle %d>" , nlp -> cycleno );
		printf( "%-19.19s" , peterbuffer );
	    }
	}
	printf( "\n" );
    }
    cfree( namesortnlp );
E 16
E 5
}
E 1
