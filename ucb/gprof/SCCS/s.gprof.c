h56599
s 00010/00005/00679
d D 5.5 88/06/29 19:23:06 bostic 29 28
c install approved copyright notice
e
s 00010/00004/00674
d D 5.4 88/05/05 17:50:09 bostic 28 27
c add Berkeley specific header; written by K. McKusick and P. Kessler
e
s 00010/00009/00668
d D 5.3 88/01/02 23:48:03 bostic 27 26
c malloc doesn't return an unsigned; UNIT is now unsigned by definition;
c define valcmp for ANSI C
e
s 00010/00000/00667
d D 5.2 87/04/27 17:30:47 mckusick 26 25
c add -k to allow selective deletion of arcs
e
s 00014/00002/00653
d D 5.1 85/06/04 13:27:45 dist 25 24
c Add copyright
e
s 00012/00003/00643
d D 1.24 84/08/07 11:30:27 mckusick 24 23
c clean up semantics of doarcs() to calculate indicies;
c reorder output; add alphabetical index; add ms/call to flat profile
e
s 00006/00001/00640
d D 1.23 84/01/30 16:38:32 peter 23 22
c if you can't find the hertz rate, report time in ticks, not seconds.
e
s 00002/00001/00639
d D 1.22 83/05/11 20:21:34 mckusick 22 21
c make -b flag default to on
e
s 00055/00018/00585
d D 1.21 83/03/31 13:14:15 mckusick 21 20
c sun changes; account for entry masks
e
s 00043/00012/00560
d D 1.20 83/03/10 17:30:21 mckusick 20 19
c take vax mask word into account
e
s 00004/00000/00568
d D 1.19 83/01/11 15:05:47 peter 19 18
c sampling frequency changes from a constant to a variable.
e
s 00001/00001/00567
d D 1.18 82/06/21 11:57:45 mckusick 18 17
c fix per peter's bug
e
s 00002/00002/00566
d D 1.17 82/06/21 00:34:22 mckusick 17 16
c remove N^2 algorithm in sample distribution routine
e
s 00002/00002/00566
d D 1.16 82/06/19 20:21:31 mckusick 16 15
c fix unsigned conversion in calculating lowpc and highpc
e
s 00012/00000/00556
d D 1.15 82/06/19 13:27:18 peter 15 14
c debugging stuff for the gmon.out header.
e
s 00000/00004/00556
d D 1.14 82/06/19 09:17:54 peter 14 13
c what to do if there's no time accumulated.
e
s 00024/00005/00536
d D 1.13 82/06/18 20:21:59 peter 13 12
c -e -E -f and -F flags, this time for sure.
e
s 00030/00011/00511
d D 1.12 82/06/14 18:08:37 peter 12 11
c -f and -e flags.
e
s 00032/00034/00490
d D 1.11 82/06/08 11:28:58 peter 11 10
c cycle headers have their own namelist.
e
s 00005/00004/00519
d D 1.10 81/11/25 12:28:13 mckusic 10 9
c fix debugging printfs for asgnsamples().
e
s 00086/00007/00437
d D 1.9 81/11/11 21:53:18 mckusic 9 8
c add the -s option to summarize multiple runs
e
s 00003/00001/00441
d D 1.8 81/11/10 21:05:08 peter 8 7
c add the -b option to print a blurb about the listings.
e
s 00003/00003/00439
d D 1.7 81/11/10 14:48:51 peter 7 6
c -a now means omit static functions, and default is show them.
e
s 00041/00004/00401
d D 1.6 81/11/10 12:20:32 peter 6 5
c adding -a flag to find statically declared functions;
c and simultaneously throwing out pascal labels.
e
s 00007/00004/00398
d D 1.5 81/11/09 13:58:55 peter 5 4
c lint.
e
s 00003/00095/00399
d D 1.4 81/11/06 17:28:45 peter 4 3
c printing routines move to printgprof.c; 
c stash low and high pc for range check in findcalls(); 
c addresses should print in hex.
e
s 00031/00030/00463
d D 1.3 81/11/02 14:30:56 peter 3 2
c gather and use static call graph from a.out file.
e
s 00005/00005/00488
d D 1.2 81/10/20 15:50:22 peter 2 1
c name change to confuse to innocent/
e
s 00493/00000/00000
d D 1.1 81/10/15 13:46:49 peter 1 0
c date and time created 81/10/15 13:46:49 by peter
e
u
U
t
T
I 25
/*
 * Copyright (c) 1983 Regents of the University of California.
D 28
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 28
I 28
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 29
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 29
I 29
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
E 29
E 28
 */

E 25
I 1
#ifndef lint
D 25
    static	char *sccsid = "%W% (Berkeley) %G%";
#endif lint
E 25
I 25
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
D 28
#endif not lint
E 28
I 28
#endif /* not lint */
E 28

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 28
#endif not lint
E 28
I 28
#endif /* not lint */
E 28
E 25

D 2
#include "dprof.h"
E 2
I 2
#include "gprof.h"
E 2

I 11
char	*whoami = "gprof";

I 12
D 13
char	*defaultes[] = { "mcount" , "__mcleanup" , 0 };
E 13
I 13
    /*
     *	things which get -E excluded by default.
     */
char	*defaultEs[] = { "mcount" , "__mcleanup" , 0 };
E 13

E 12
E 11
main(argc, argv)
D 12
	int argc;
	char **argv;
E 12
I 12
    int argc;
    char **argv;
E 12
{
I 12
    char	**sp;
I 24
    nltype	**timesortnlp;
E 24
E 12

    --argc;
    argv++;
    debug = 0;
I 22
    bflag = TRUE;
E 22
    while ( *argv != 0 && **argv == '-' ) {
	(*argv)++;
D 9
	if ( **argv == 'd' ) {
E 9
I 9
	switch ( **argv ) {
I 12
	case 'a':
	    aflag = TRUE;
	    break;
	case 'b':
D 22
	    bflag = TRUE;
E 22
I 22
	    bflag = FALSE;
E 22
	    break;
	case 'c':
	    cflag = TRUE;
	    break;
E 12
	case 'd':
I 12
	    dflag = TRUE;
E 12
E 9
	    (*argv)++;
	    debug |= atoi( *argv );
	    debug |= ANYDEBUG;
#	    ifdef DEBUG
D 21
		printf( "[main] debug = %d\n" , debug );
E 21
I 21
		printf("[main] debug = %d\n", debug);
#	    else not DEBUG
		printf("%s: -d ignored\n", whoami);
E 21
#	    endif DEBUG
D 6
	} else if ( **argv == 'z' ) {
	    zflg++;
E 6
I 6
D 9
	} else if ( **argv == 'a' ) {
E 9
I 9
	    break;
I 13
	case 'E':
	    ++argv;
	    addlist( Elist , *argv );
	    Eflag = TRUE;
	    addlist( elist , *argv );
	    eflag = TRUE;
	    break;
E 13
D 12
	case 'a':
E 9
	    aflag++;
E 12
I 12
	case 'e':
I 13
	    addlist( elist , *++argv );
E 13
	    eflag = TRUE;
D 13
	    addelist( *++argv );
E 13
E 12
I 8
D 9
	} else if ( **argv == 'b' ) {
E 9
I 9
	    break;
I 13
	case 'F':
	    ++argv;
	    addlist( Flist , *argv );
	    Fflag = TRUE;
	    addlist( flist , *argv );
	    fflag = TRUE;
	    break;
E 13
D 12
	case 'b':
E 9
	    bflag++;
E 12
I 12
	case 'f':
I 13
	    addlist( flist , *++argv );
E 13
	    fflag = TRUE;
D 13
	    addflist( *++argv );
E 13
E 12
E 8
E 6
I 3
D 9
	} else if ( **argv == 'c' ) {
E 9
I 9
	    break;
I 26
	case 'k':
	    addlist( kfromlist , *++argv );
	    addlist( ktolist , *++argv );
	    kflag = TRUE;
	    break;
E 26
D 12
	case 'c':
E 9
	    cflag++;
I 6
D 9
	} else if ( **argv == 'z' ) {
E 9
I 9
	    break;
E 12
	case 's':
D 12
	    sflag++;
E 12
I 12
	    sflag = TRUE;
E 12
	    break;
	case 'z':
E 9
D 8
	    zflg++;
E 8
I 8
D 12
	    zflag++;
E 12
I 12
	    zflag = TRUE;
E 12
I 9
	    break;
E 9
E 8
E 6
E 3
	}
	argv++;
    }
    if ( *argv != 0 ) {
	a_outname  = *argv;
	argv++;
    } else {
	a_outname  = A_OUTNAME;
    }
    if ( *argv != 0 ) {
D 2
	dmonname = *argv;
E 2
I 2
	gmonname = *argv;
E 2
	argv++;
    } else {
D 2
	dmonname = DMONNAME;
E 2
I 2
	gmonname = GMONNAME;
I 12
    }
	/*
	 *	turn off default functions
	 */
D 13
    for ( sp = &defaultes[0] ; *sp ; sp++ ) {
E 13
I 13
    for ( sp = &defaultEs[0] ; *sp ; sp++ ) {
	Eflag = TRUE;
	addlist( Elist , *sp );
E 13
	eflag = TRUE;
D 13
	addelist( *sp );
E 13
I 13
	addlist( elist , *sp );
E 13
E 12
E 2
    }
	/*
I 19
D 23
	 *	how long is a clock tick?
E 23
I 23
	 *	how many ticks per second?
	 *	if we can't tell, report time in ticks.
E 23
	 */
    hz = hertz();
I 23
    if (hz == 0) {
	hz = 1;
	fprintf(stderr, "time is in ticks, not seconds\n");
    }
E 23
	/*
E 19
	 *	get information about a.out file.
	 */
    getnfile();
	/*
	 *	get information about mon.out file(s).
	 */
D 2
    getpfile( dmonname );
E 2
I 2
D 9
    getpfile( gmonname );
E 9
I 9
    do	{
	getpfile( gmonname );
	if ( *argv != 0 ) {
	    gmonname = *argv;
	}
D 11
    } while ( sflag && *argv++ != 0 );
E 11
I 11
    } while ( *argv++ != 0 );
E 11
E 9
E 2
	/*
I 9
	 *	dump out a gmon.sum file if requested
	 */
D 11
	if ( sflag ) {
	    dumpsum( GMONSUM );
	}
E 11
I 11
    if ( sflag ) {
	dumpsum( GMONSUM );
    }
E 11
	/*
E 9
	 *	assign samples to procedures
	 */
    asgnsamples();
	/*
D 24
	 *	print the usual profile
E 24
I 24
	 *	assemble the dynamic profile
E 24
	 */
I 24
    timesortnlp = doarcs();
	/*
	 *	print the dynamic profile
	 */
    printgprof( timesortnlp );	
	/*
	 *	print the flat profile
	 */
E 24
    printprof();	
	/*
D 24
	 *	assemble and print the dynamic profile
E 24
I 24
	 *	print the index
E 24
	 */
D 24
    doarcs();
E 24
I 24
    printindex();	
E 24
    done();
}

D 4
printprof()
{
    register nltype	*np;
    nltype		**sortednlp;
    int			index;

    actime = 0.0;
    putprofheader();
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
	putprofline( np , 1 );
    }
    actime = 0.0;
    printf( "\ngranularity: each sample hit covers %.1f bytes" , scale );
    printf( " for %.2f%% of %.2f seconds\n" , 100.0/totime , totime / HZ );
}

putprofline( np , cumflag )
    register nltype	*np;
    int			cumflag;
{
    double	time;
    long	calls = np -> ncall + np -> selfcalls;

    if ( zflg == 0 && calls == 0 && np -> time == 0 && np -> childtime == 0 ) {
	return;
    }
    if ( cumflag ) {
	time = (np->time + np->childtime) / totime;
	actime += np->time;
	if ( np -> index != 0 ) {
	    printf( "[%d]" , np -> index );
	}
	printf( "\t%5.1f %7.1f" , 100 * time , actime / HZ );
    } else {
	printf( "\t%5.5s %7.7s" , "" , "" );
    }
    printf( " %7.1f", np -> time / HZ );
    if ( np -> childtime != 0.0 ) {
	printf( " %7.1f" , np -> childtime / HZ );
    } else {
	printf( " %7.7s" , "" );
    }
    if ( calls != 0 ) {
	printf( " %7d" , np -> ncall );
	if ( np -> selfcalls != 0 ) {
	    printf( "+%-7d  " , np -> selfcalls );
	} else {
	    printf( " %7.7s  " , "" );
	}
    } else {
	printf( " %7.7s %7.7s  " , "" , "" );
    }
    if ( ! cumflag ) {
	printf( "    " );
    }
    printname( np );
    printf( "\n" );
}

    /*
     *	header for putprofline
     */
putprofheader()
{
    
    printf( "\n\t%5.5s %7.7s %-7.7s %-7.7s %7.7s %7.7s %5.5s\n" ,
	    "%time" , "cumsecs" , "  self" , " child" , "ncall" , "" , "name" );
}

E 4
D 11
/*
 * Set up string and symbol tables from a.out.
I 3
 *	and optionally the text space.
E 3
 * On return symbol table is sorted by value.
 */
E 11
I 11
    /*
     * Set up string and symbol tables from a.out.
     *	and optionally the text space.
     * On return symbol table is sorted by value.
     */
E 11
getnfile()
{
    FILE	*nfile;
I 27
    int		valcmp();
E 27

    nfile = fopen( a_outname ,"r");
    if (nfile == NULL) {
	perror( a_outname );
	done();
    }
    fread(&xbuf, 1, sizeof(xbuf), nfile);
    if (N_BADMAG(xbuf)) {
D 11
	fprintf(stderr, "%s: bad format\n", a_outname );
E 11
I 11
	fprintf(stderr, "%s: %s: bad format\n", whoami , a_outname );
E 11
	done();
    }
    getstrtab(nfile);
    getsymtab(nfile);
I 3
    gettextspace( nfile );
E 3
    qsort(nl, nname, sizeof(nltype), valcmp);
    fclose(nfile);
#   ifdef DEBUG
	if ( debug & AOUTDEBUG ) {
	    register int j;

	    for (j = 0; j < nname; j++){
		printf("[getnfile] 0X%08x\t%s\n", nl[j].value, nl[j].name);
	    }
	}
#   endif DEBUG
}

getstrtab(nfile)
    FILE	*nfile;
{

    fseek(nfile, (long)(N_SYMOFF(xbuf) + xbuf.a_syms), 0);
    if (fread(&ssiz, sizeof (ssiz), 1, nfile) == 0) {
D 11
	fprintf(stderr, "%s: no string table (old format?)\n", a_outname );
E 11
I 11
	fprintf(stderr, "%s: %s: no string table (old format?)\n" ,
		whoami , a_outname );
E 11
	done();
    }
    strtab = (char *)calloc(ssiz, 1);
    if (strtab == NULL) {
D 11
	fprintf(stderr, "%s: no room for %d bytes of string table",
		a_outname , ssiz);
E 11
I 11
	fprintf(stderr, "%s: %s: no room for %d bytes of string table",
		whoami , a_outname , ssiz);
E 11
	done();
    }
    if (fread(strtab+sizeof(ssiz), ssiz-sizeof(ssiz), 1, nfile) != 1) {
D 11
	fprintf(stderr, "%s: error reading string table\n", a_outname );
E 11
I 11
	fprintf(stderr, "%s: %s: error reading string table\n",
		whoami , a_outname );
E 11
	done();
    }
}

    /*
     * Read in symbol table
     */
getsymtab(nfile)
    FILE	*nfile;
{
    register long	i;
    int			askfor;
    struct nlist	nbuf;

    /* pass1 - count symbols */
    fseek(nfile, (long)N_SYMOFF(xbuf), 0);
    nname = 0;
    for (i = xbuf.a_syms; i > 0; i -= sizeof(struct nlist)) {
	fread(&nbuf, sizeof(nbuf), 1, nfile);
D 6
	if ( nbuf.n_type != N_TEXT+N_EXT ) {
E 6
I 6
	if ( ! funcsymbol( &nbuf ) ) {
E 6
	    continue;
	}
	nname++;
    }
    if (nname == 0) {
D 11
	fprintf(stderr, "%s: no symbols\n", a_outname );
E 11
I 11
	fprintf(stderr, "%s: %s: no symbols\n", whoami , a_outname );
E 11
	done();
    }
D 11
	/*
	 *	ask also for CYCLEFRACTION extra namelist entries for 
	 *	cycle entries.  these hide out at the end of the namelist
	 *	and aren't accessed unless the whole namelist (nname+ncycles)
	 *	is sorted and searched.
	 */
    ncycles = nname * CYCLEFRACTION;
    askfor = nname + 1 + ncycles;
E 11
I 11
    askfor = nname + 1;
E 11
    nl = (nltype *) calloc( askfor , sizeof(nltype) );
    if (nl == 0) {
D 11
	fprintf(stderr, "prof: No room for %d bytes of symbol table\n",
		askfor * sizeof(nltype) );
E 11
I 11
	fprintf(stderr, "%s: No room for %d bytes of symbol table\n",
		whoami, askfor * sizeof(nltype) );
E 11
	done();
    }

    /* pass2 - read symbols */
    fseek(nfile, (long)N_SYMOFF(xbuf), 0);
    npe = nl;
    nname = 0;
    for (i = xbuf.a_syms; i > 0; i -= sizeof(struct nlist)) {
	fread(&nbuf, sizeof(nbuf), 1, nfile);
D 6
	if ( nbuf.n_type != N_TEXT+N_EXT ) {
E 6
I 6
	if ( ! funcsymbol( &nbuf ) ) {
#	    ifdef DEBUG
		if ( debug & AOUTDEBUG ) {
		    printf( "[getsymtab] rejecting: 0x%x %s\n" ,
			    nbuf.n_type , strtab + nbuf.n_un.n_strx );
		}
#	    endif DEBUG
E 6
	    continue;
	}
	npe->value = nbuf.n_value;
	npe->name = strtab+nbuf.n_un.n_strx;
#	ifdef DEBUG
	    if ( debug & AOUTDEBUG ) {
		printf( "[getsymtab] %d %s 0x%08x\n" ,
			nname , npe -> name , npe -> value );
	    }
#	endif DEBUG
	npe++;
	nname++;
    }
    npe->value = -1;
D 21
    npe++;
E 21
}

    /*
I 3
     *	read in the text space of an a.out file
     */
gettextspace( nfile )
    FILE	*nfile;
{
D 27
    unsigned char	*malloc();
E 27
I 27
    char	*malloc();
E 27
    
    if ( cflag == 0 ) {
	return;
    }
D 27
    textspace = malloc( xbuf.a_text );
E 27
I 27
    textspace = (u_char *) malloc( xbuf.a_text );
E 27
    if ( textspace == 0 ) {
D 11
	fprintf( stderr , "gprof: ran out room for %d bytes of text space:  " );
	fprintf( stderr , "can't do -c\n" , xbuf.a_text );
E 11
I 11
	fprintf( stderr , "%s: ran out room for %d bytes of text space:  " ,
			whoami , xbuf.a_text );
	fprintf( stderr , "can't do -c\n" );
E 11
	return;
    }
    (void) fseek( nfile , N_TXTOFF( xbuf ) , 0 );
    if ( fread( textspace , 1 , xbuf.a_text , nfile ) != xbuf.a_text ) {
D 11
	fprintf( stderr , "couldn't read text space:  " );
	fprintf( stderr , "can't do -c\n" , xbuf.a_text );
E 11
I 11
	fprintf( stderr , "%s: couldn't read text space:  " , whoami );
	fprintf( stderr , "can't do -c\n" );
E 11
	free( textspace );
	textspace = 0;
	return;
    }
}
    /*
E 3
D 2
     *	information from a dmon.out file is in two parts:
E 2
I 2
     *	information from a gmon.out file is in two parts:
E 2
     *	an array of sampling hits within pc ranges,
     *	and the arcs.
     */
getpfile(filename)
    char *filename;
{
    FILE		*pfile;
    FILE		*openpfile();
    struct rawarc	arc;

    pfile = openpfile(filename);
    readsamples(pfile);
	/*
	 *	the rest of the file consists of
	 *	a bunch of <from,self,count> tuples.
	 */
    while ( fread( &arc , sizeof arc , 1 , pfile ) == 1 ) {
#	ifdef DEBUG
	    if ( debug & SAMPLEDEBUG ) {
D 4
		printf( "[getpfile] frompc %d selfpc %d count %d\n" ,
E 4
I 4
		printf( "[getpfile] frompc 0x%x selfpc 0x%x count %d\n" ,
E 4
			arc.raw_frompc , arc.raw_selfpc , arc.raw_count );
	    }
#	endif DEBUG
	    /*
	     *	add this arc
	     */
	tally( &arc );
    }
    fclose(pfile);
}

D 5
FILE *openpfile(filename)
E 5
I 5
FILE *
openpfile(filename)
E 5
    char *filename;
{
I 9
    struct hdr	tmp;
E 9
    FILE	*pfile;

    if((pfile = fopen(filename, "r")) == NULL) {
	perror(filename);
	done();
    }
D 9
    fread(&h, sizeof(struct hdr), 1, pfile);
E 9
I 9
    fread(&tmp, sizeof(struct hdr), 1, pfile);
    if ( s_highpc != 0 && ( tmp.lowpc != h.lowpc ||
	 tmp.highpc != h.highpc || tmp.ncnt != h.ncnt ) ) {
	fprintf(stderr, "%s: incompatible with first gmon file\n", filename);
	done();
    }
    h = tmp;
E 9
I 4
    s_lowpc = (unsigned long) h.lowpc;
    s_highpc = (unsigned long) h.highpc;
E 4
D 16
    lowpc = h.lowpc - (UNIT *)0;
    highpc = h.highpc - (UNIT *)0;
E 16
I 16
    lowpc = (unsigned long)h.lowpc / sizeof(UNIT);
    highpc = (unsigned long)h.highpc / sizeof(UNIT);
E 16
    sampbytes = h.ncnt - sizeof(struct hdr);
D 27
    nsamples = sampbytes / sizeof (unsigned UNIT);
E 27
I 27
    nsamples = sampbytes / sizeof (UNIT);
E 27
I 15
#   ifdef DEBUG
	if ( debug & SAMPLEDEBUG ) {
	    printf( "[openpfile] hdr.lowpc 0x%x hdr.highpc 0x%x hdr.ncnt %d\n",
		h.lowpc , h.highpc , h.ncnt );
	    printf( "[openpfile]   s_lowpc 0x%x   s_highpc 0x%x\n" ,
		s_lowpc , s_highpc );
	    printf( "[openpfile]     lowpc 0x%x     highpc 0x%x\n" ,
		lowpc , highpc );
	    printf( "[openpfile] sampbytes %d nsamples %d\n" ,
		sampbytes , nsamples );
	}
#   endif DEBUG
E 15
    return(pfile);
}

tally( rawp )
    struct rawarc	*rawp;
{
    nltype		*parentp;
    nltype		*childp;
D 3
    arctype		*arcp;
    arctype		*malloc();
E 3

    parentp = nllookup( rawp -> raw_frompc );
    childp = nllookup( rawp -> raw_selfpc );
I 26
    if ( kflag
	 && onlist( kfromlist , parentp -> name )
	 && onlist( ktolist , childp -> name ) ) {
	return;
    }
E 26
    childp -> ncall += rawp -> raw_count;
#   ifdef DEBUG
	if ( debug & TALLYDEBUG ) {
	    printf( "[tally] arc from %s to %s traversed %d times\n" ,
		    parentp -> name , childp -> name , rawp -> raw_count );
	}
#   endif DEBUG
D 3
    arcp = arclookup( parentp , childp );
    if ( arcp != 0 ) {
	    /*
	     *	a hit:  just increment the count.
	     */
#	ifdef DEBUG
	    if ( debug & TALLYDEBUG ) {
		printf( "[tally] hit %d += %d\n" ,
			arcp -> arc_count , rawp -> raw_count );
	    }
#	endif DEBUG
	arcp -> arc_count += rawp -> raw_count;
	return;
    }
    arcp = malloc( sizeof *arcp );
    arcp -> arc_parentp = parentp;
    arcp -> arc_childp = childp;
    arcp -> arc_count = rawp -> raw_count;
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
E 3
I 3
    addarc( parentp , childp , rawp -> raw_count );
I 9
}

/*
 * dump out the gmon.sum file
 */
dumpsum( sumfile )
    char *sumfile;
{
    register nltype *nlp;
    register arctype *arcp;
    struct rawarc arc;
    FILE *sfile;

    if ( ( sfile = fopen ( sumfile , "w" ) ) == NULL ) {
	perror( sumfile );
	done();
    }
    /*
     * dump the header; use the last header read in
     */
    if ( fwrite( &h , sizeof h , 1 , sfile ) != 1 ) {
	perror( sumfile );
	done();
    }
    /*
     * dump the samples
     */
D 27
    if (fwrite(samples, sizeof(unsigned UNIT), nsamples, sfile) != nsamples) {
E 27
I 27
    if (fwrite(samples, sizeof (UNIT), nsamples, sfile) != nsamples) {
E 27
	perror( sumfile );
	done();
    }
    /*
     * dump the normalized raw arc information
     */
D 21
    for ( nlp = nl ; nlp < npe - 1 ; nlp++ ) {
E 21
I 21
    for ( nlp = nl ; nlp < npe ; nlp++ ) {
E 21
	for ( arcp = nlp -> children ; arcp ; arcp = arcp -> arc_childlist ) {
	    arc.raw_frompc = arcp -> arc_parentp -> value;
	    arc.raw_selfpc = arcp -> arc_childp -> value;
	    arc.raw_count = arcp -> arc_count;
	    if ( fwrite ( &arc , sizeof arc , 1 , sfile ) != 1 ) {
		perror( sumfile );
		done();
	    }
#	    ifdef DEBUG
		if ( debug & SAMPLEDEBUG ) {
		    printf( "[dumpsum] frompc 0x%x selfpc 0x%x count %d\n" ,
			    arc.raw_frompc , arc.raw_selfpc , arc.raw_count );
		}
#	    endif DEBUG
	}
    }
    fclose( sfile );
E 9
E 3
}

valcmp(p1, p2)
    nltype *p1, *p2;
{
    if ( p1 -> value < p2 -> value ) {
	return LESSTHAN;
    }
    if ( p1 -> value > p2 -> value ) {
	return GREATERTHAN;
    }
    return EQUALTO;
}

readsamples(pfile)
    FILE	*pfile;
{
    register i;
D 27
    unsigned UNIT	sample;
E 27
I 27
    UNIT	sample;
E 27
    
    if (samples == 0) {
D 27
	samples = (unsigned UNIT *) calloc(sampbytes, sizeof (unsigned UNIT));
E 27
I 27
	samples = (UNIT *) calloc(sampbytes, sizeof (UNIT));
E 27
	if (samples == 0) {
D 11
	    fprintf( stderr , "prof: No room for %d sample pc's\n", 
		sampbytes / sizeof (unsigned UNIT));
E 11
I 11
	    fprintf( stderr , "%s: No room for %d sample pc's\n", 
D 27
		whoami , sampbytes / sizeof (unsigned UNIT));
E 27
I 27
		whoami , sampbytes / sizeof (UNIT));
E 27
E 11
	    done();
	}
    }
    for (i = 0; i < nsamples; i++) {
D 27
	fread(&sample, sizeof (unsigned UNIT), 1, pfile);
E 27
I 27
	fread(&sample, sizeof (UNIT), 1, pfile);
E 27
	if (feof(pfile))
		break;
	samples[i] += sample;
    }
    if (i != nsamples) {
	fprintf(stderr,
D 11
	    "prof: unexpected EOF after reading %d/%d samples\n",
		--i, nsamples);
E 11
I 11
	    "%s: unexpected EOF after reading %d/%d samples\n",
		whoami , --i , nsamples );
E 11
	done();
    }
}

/*
D 20
 * Assign samples to the procedures to which they belong.
E 20
I 20
 *	Assign samples to the procedures to which they belong.
 *
 *	There are three cases as to where pcl and pch can be
 *	with respect to the routine entry addresses svalue0 and svalue1
 *	as shown in the following diagram.  overlap computes the
 *	distance between the arrows, the fraction of the sample
 *	that is to be credited to the routine which starts at svalue0.
 *
 *	    svalue0                                         svalue1
 *	       |                                               |
 *	       v                                               v
 *
 *	       +-----------------------------------------------+
 *	       |					       |
 *	  |  ->|    |<-		->|         |<-		->|    |<-  |
 *	  |         |		  |         |		  |         |
 *	  +---------+		  +---------+		  +---------+
 *
 *	  ^         ^		  ^         ^		  ^         ^
 *	  |         |		  |         |		  |         |
 *	 pcl       pch		 pcl       pch		 pcl       pch
 *
 *	For the vax we assert that samples will never fall in the first
D 21
 *	two bytes of any routine, since that is the entry mask, thus we give
 *	ourselves a little room and use svalue0+2 when assigning samples.
 *	In conjunction with the alignment of routine addresses, this 
 *	should allow us to have one sample for every four bytes of text
 *	space and never have any overlap (the two end cases, above).
E 21
I 21
 *	two bytes of any routine, since that is the entry mask,
 *	thus we give call alignentries() to adjust the entry points if
 *	the entry mask falls in one bucket but the code for the routine
 *	doesn't start until the next bucket.  In conjunction with the
 *	alignment of routine addresses, this should allow us to have
 *	only one sample for every four bytes of text space and never
 *	have any overlap (the two end cases, above).
E 21
E 20
 */
asgnsamples()
{
    register int	j;
D 27
    unsigned UNIT	ccnt;
E 27
I 27
    UNIT		ccnt;
E 27
    double		time;
    unsigned long	pcl, pch;
    register int	i;
D 5
    int			overlap;
E 5
I 5
    unsigned long	overlap;
E 5
    unsigned long	svalue0, svalue1;

    /* read samples and assign to namelist symbols */
    scale = highpc - lowpc;
    scale /= nsamples;
I 21
    alignentries();
E 21
D 17
    for (i=0; i < nsamples; i++) {
E 17
I 17
D 18
    for (i = 0, j = 0; i < nsamples; i++) {
E 18
I 18
    for (i = 0, j = 1; i < nsamples; i++) {
E 18
E 17
	ccnt = samples[i];
	if (ccnt == 0)
		continue;
D 20
	pcl = lowpc + scale*i;
	pch = lowpc + scale*(i+1);
E 20
I 20
	pcl = lowpc + scale * i;
	pch = lowpc + scale * (i + 1);
E 20
	time = ccnt;
#	ifdef DEBUG
	    if ( debug & SAMPLEDEBUG ) {
D 10
		printf( "[asgnsamples] ccnt %d time %f totime %f\n" ,
			ccnt , time , totime );
E 10
I 10
		printf( "[asgnsamples] pcl 0x%x pch 0x%x ccnt %d\n" ,
			pcl , pch , ccnt );
E 10
	    }
#	endif DEBUG
	totime += time;
D 17
	for (j=0; j<nname; j++) {
E 17
I 17
	for (j = j - 1; j < nname; j++) {
E 17
D 21
	    svalue0 = nl[j].value / sizeof(UNIT);
	    svalue1 = nl[j+1].value / sizeof(UNIT);
E 21
I 21
	    svalue0 = nl[j].svalue;
	    svalue1 = nl[j+1].svalue;
		/*
		 *	if high end of tick is below entry address, 
		 *	go for next tick.
		 */
E 21
	    if (pch < svalue0)
		    break;
I 21
		/*
		 *	if low end of tick into next routine,
		 *	go for next routine.
		 */
E 21
	    if (pcl >= svalue1)
		    continue;
D 20
	    overlap=min(pch,svalue1) - max(pcl,svalue0);
	    if (overlap>0) {
E 20
I 20
D 21
#	    ifdef vax
	        overlap = min(pch, svalue1) - max(pcl, svalue0 + 2);
#	    else
	        overlap = min(pch, svalue1) - max(pcl, svalue0);
#	    endif vax
E 21
I 21
	    overlap = min(pch, svalue1) - max(pcl, svalue0);
E 21
	    if (overlap > 0) {
E 20
#		ifdef DEBUG
D 20
		    if ( debug & SAMPLEDEBUG ) {
D 10
			printf( "[asgnsamples] %s gets %f ticks\n" ,
				nl[j].name , overlap*time/scale );
E 10
I 10
			printf( "[asgnsamples] (0x%x-0x%x) %s gets %f ticks\n" ,
				svalue0 , svalue1 , nl[j].name , 
				overlap*time/scale );
E 20
I 20
		    if (debug & SAMPLEDEBUG) {
D 21
			printf("[asgnsamples] (0x%x-0x%x) %s gets %f ticks\n",
				svalue0, svalue1, nl[j].name, 
				overlap * time / scale);
E 21
I 21
			printf("[asgnsamples] (0x%x->0x%x-0x%x) %s gets %f ticks %d overlap\n",
				nl[j].value/sizeof(UNIT), svalue0, svalue1,
				nl[j].name, 
				overlap * time / scale, overlap);
E 21
E 20
E 10
		    }
#		endif DEBUG
D 20
		nl[j].time += overlap*time/scale;
E 20
I 20
		nl[j].time += overlap * time / scale;
E 20
	    }
	}
    }
#   ifdef DEBUG
D 20
	if ( debug & SAMPLEDEBUG ) {
	    printf( "[asgnsamples] totime %f\n" , totime );
E 20
I 20
	if (debug & SAMPLEDEBUG) {
	    printf("[asgnsamples] totime %f\n", totime);
E 20
	}
#   endif DEBUG
D 14
    if (totime==0.0) {
	fprintf( stderr , "No time accumulated\n" );
	totime=1.0;
    }
E 14
}


I 5
unsigned long
E 5
min(a, b)
D 5
    unsigned a,b;
E 5
I 5
    unsigned long a,b;
E 5
{
    if (a<b)
	return(a);
    return(b);
}

I 5
unsigned long
E 5
max(a, b)
D 5
    unsigned a,b;
E 5
I 5
    unsigned long a,b;
E 5
{
    if (a>b)
	return(a);
    return(b);
I 21
}

    /*
     *	calculate scaled entry point addresses (to save time in asgnsamples),
     *	and possibly push the scaled entry points over the entry mask,
     *	if it turns out that the entry point is in one bucket and the code
     *	for a routine is in the next bucket.
     */
alignentries()
{
    register struct nl	*nlp;
    unsigned long	bucket_of_entry;
    unsigned long	bucket_of_code;

    for (nlp = nl; nlp < npe; nlp++) {
	nlp -> svalue = nlp -> value / sizeof(UNIT);
	bucket_of_entry = (nlp->svalue - lowpc) / scale;
	bucket_of_code = (nlp->svalue + UNITS_TO_CODE - lowpc) / scale;
	if (bucket_of_entry < bucket_of_code) {
#	    ifdef DEBUG
		if (debug & SAMPLEDEBUG) {
		    printf("[alignentries] pushing svalue 0x%x to 0x%x\n",
			    nlp->svalue, nlp->svalue + UNITS_TO_CODE);
		}
#	    endif DEBUG
	    nlp->svalue += UNITS_TO_CODE;
	}
    }
E 21
I 6
}

bool
funcsymbol( nlistp )
    struct nlist	*nlistp;
{
    extern char	*strtab;	/* string table from a.out */
D 7
    extern int	aflag;		/* if static functions desired */
E 7
I 7
    extern int	aflag;		/* if static functions aren't desired */
E 7
    char	*name;

	/*
	 *	must be a text symbol,
D 7
	 *	and static text symbols qualify if aflag set.
E 7
I 7
	 *	and static text symbols don't qualify if aflag set.
E 7
	 */
    if ( ! (  ( nlistp -> n_type == ( N_TEXT | N_EXT ) )
D 7
	   || ( ( nlistp -> n_type == N_TEXT ) && aflag ) ) ) {
E 7
I 7
	   || ( ( nlistp -> n_type == N_TEXT ) && ( aflag == 0 ) ) ) ) {
E 7
	return FALSE;
    }
	/*
D 11
	 *	can't have any `funny characters in name,
E 11
I 11
	 *	can't have any `funny' characters in name,
E 11
	 *	where `funny' includes	`.', .o file names
	 *			and	`$', pascal labels.
	 */
    for ( name = strtab + nlistp -> n_un.n_strx ; *name ; name += 1 ) {
	if ( *name == '.' || *name == '$' ) {
	    return FALSE;
	}
    }
    return TRUE;
E 6
D 4
}

timecmp( npp1 , npp2 )
    nltype **npp1, **npp2;
{
    double d;

    d = (*npp2)->time - (*npp1)->time;
    if (d > 0.0)
	return(1);
    if (d < 0.0)
	return(-1);
    return(strcmp((*npp1)->name,(*npp2)->name));
E 4
}

done()
{

    exit(0);
}
E 1
