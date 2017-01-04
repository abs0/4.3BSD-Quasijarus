h51848
s 00003/00003/00440
d D 5.2 87/04/07 15:46:36 mckusick 18 17
c pdx now works
e
s 00012/00005/00431
d D 5.1 85/06/05 14:32:32 dist 17 16
c Add copyright
e
s 00005/00000/00431
d D 2.3 85/03/20 14:18:34 mckusick 16 15
c generate appropriate Fatal error message
e
s 00000/00000/00431
d D 2.2 85/03/15 22:28:43 mckusick 15 13
i 14
c merge dbx from linton
e
s 00007/00001/00413
d D 1.9.1.1 85/03/15 22:28:03 mckusick 14 10
c new dbx from linton
e
s 00000/00000/00425
d D 2.1 84/02/08 20:46:18 aoki 13 12
c synchronize to version 2
e
s 00000/00000/00425
d D 1.11 83/09/19 06:59:04 thien 12 11
c Restoring to unlinted version
e
s 00023/00012/00402
d D 1.10 83/08/19 04:58:34 thien 11 10
c The changes were made to allow successful linting
e
s 00003/00000/00411
d D 1.9 83/06/10 16:57:36 mckusick 10 9
c when -J flag specified, generate long displacement jump tables
e
s 00005/00001/00406
d D 1.8 83/04/08 16:46:50 mckusick 9 8
c turn off "-g" (for pdx) in pi by default, since not yet implemented
e
s 00010/00025/00397
d D 1.7 82/03/31 15:51:28 peter 8 7
c using the new config.h.
e
s 00001/00001/00421
d D 1.6 82/03/30 18:35:54 peter 7 6
c pc0 should output to .pc0 files by default (i always wanted to change this).
e
s 00012/00001/00410
d D 1.5 82/02/02 12:56:47 linton 6 5
c merge pdx into the Pascal system
e
s 00005/00005/00406
d D 1.4 81/03/09 12:27:05 mckusic 5 4
c fix bool type errors
e
s 00011/00011/00400
d D 1.3 81/03/08 19:26:14 mckusic 4 3
c merge in onyx changes
e
s 00002/00000/00409
d D 1.2 81/02/20 10:31:42 peter 3 1
c put in static copyright string, findable by ``sccs what''
e
s 00002/00000/00409
d R 1.2 81/01/15 13:51:55 peter 2 1
c put in static copyright string.
e
s 00409/00000/000p0
d D 1.1 80/08/27 19:55:20 peter 1 0
c date and time created 80/08/27 19:55:20 by peter
e
u
U
f b 
t
T
I 1
D 17
/* Copyright (c) 1979 Regents of the University of California */
E 17
I 17
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 17
I 4

I 11
#ifndef lint
E 11
E 4
I 3
D 17
static	char copyright[] =
	    "%Z%Copyright (c) 1979 Regents of the University of California";
E 17
I 17
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint
E 17
E 3

D 4
static	char sccsid[] = "%Z%%M% %I% %G%";
E 4
I 4
D 17
static char sccsid[] = "%Z%%M% %I% %G%";
I 11
#endif
E 17
I 17
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 17
E 11
E 4

#include "whoami.h"
#include "0.h"
I 11
#include "tree_ty.h"		/* must be included for yy.h */
E 11
#include "yy.h"
#include <signal.h>
#include "objfmt.h"
I 8
#include "config.h"
E 8

/*
 * This version of pi has been in use at Berkeley since May 1977
D 4
 * and is very stable, except for the syntactic error recovery which
 * has just been written.  Please report any problems with the error
E 4
I 4
 * and is very stable. Please report any problems with the error
E 4
 * recovery to the second author at the address given in the file
 * READ_ME.  The second author takes full responsibility for any bugs
 * in the syntactic error recovery.
 */

char	piusage[]	= "pi [ -blnpstuw ] [ -i file ... ] name.p";
D 11
char	pixusage[]	= "pix [ -blnpstuw ] [ -i file ... ] name.p [ arg ... ]";
char	pcusage[]	= "pc [ options ] [ -o file ] [ -i file ... ] name.p";
E 11

char	*usageis	= piusage;

D 8
char	*errfile = ERR_STRNGS;

E 8
#ifdef OBJ
D 11
    char	*obj	= "obj";
E 11
I 11

char	pixusage[]	= "pix [ -blnpstuw ] [ -i file ... ] name.p [ arg ... ]";
char	*obj	= "obj";

E 11
#endif OBJ
I 11

E 11
#ifdef PC
D 7
    char	*pcname = "pc.pc1";
E 7
I 7
D 11
    char	*pcname = "pc.pc0";
E 11
I 11

char	*pcname = "pc.pc0";
char	pcusage[]	= "pc [ options ] [ -o file ] [ -i file ... ] name.p";
FILE	*pcstream = NULL;

E 11
E 7
#endif PC
#ifdef PTREE
    char	*pTreeName = "pi.pTree";
#endif PTREE

D 8
/*
 * Be careful changing errfile and howfile.
 * There are the "magic" constants 9 and 15 immediately below.
 * errfile is now defined by ERR_STRNGS, in objfmt.h,
 * and its leading path name length is ERR_PATHLEN long.
 * this for executing out of the current directory if running as `a.something'.
 */
#ifdef OBJ
D 4
char	*howfile	= "/usr/lib/how_pi\0";
E 4
I 4
char	*howfile	= HOW_STRNGS;
E 4
#endif OBJ
#ifdef PC
D 4
char	*howfile	= "/usr/lib/how_pc";
E 4
I 4
char	*howfile	= HOW_STRNGS;
E 4
#endif PC

E 8
int	onintr();

extern	char *lastname;

FILE	*ibuf;
D 11
FILE	*pcstream = NULL;
E 11

/*
 * these are made real variables
 * so they can be changed
 * if you are compiling on a smaller machine
 */
double	MAXINT	=  2147483647.;
double	MININT	= -2147483648.;

/*
 * Main program for pi.
 * Process options, then call yymain
 * to do all the real work.
 */
main(argc, argv)
	int argc;
	char *argv[];
{
	register char *cp;
	register c;
I 11
	FILE *fopen();
	extern char *myctime();
	extern long lseek();
E 11
	int i;

	if (argv[0][0] == 'a')
D 4
		errfile += ERR_PATHLEN , howfile += 9;
E 4
I 4
D 8
		errfile += ERR_PATHLEN , howfile += HOW_PATHLEN;
E 8
I 8
		err_file += err_pathlen , how_file += how_pathlen;
E 8
E 4
#	ifdef OBJ
	    if (argv[0][0] == '-' && argv[0][1] == 'o') {
		    obj = &argv[0][2];
		    usageis = pixusage;
D 4
		    howfile[15] = 'x';
E 4
I 4
D 8
		    howfile[HOW_PATHLEN+6] = 'x';
E 8
I 8
		    how_file[strlen(how_file)] = 'x';
E 8
E 4
		    ofil = 3;
	    } else {
		    ofil = creat(obj, 0755);
		    if (ofil < 0) {
			    perror(obj);
			    pexit(NOSTART);
		    }
	    }
#	endif OBJ
	argv++, argc--;
	if (argc == 0) {
		i = fork();
		if (i == -1)
			goto usage;
		if (i == 0) {
D 8
			execl("/bin/cat", "cat", howfile, 0);
E 8
I 8
			execl("/bin/cat", "cat", how_file, 0);
E 8
			goto usage;
		}
		while (wait(&i) != -1)
			continue;
		pexit(NOSTART);
	}
#	ifdef OBJ
D 6
	    opt('p') = opt('t') = opt('b') = 1;
E 6
I 6
D 9
	    opt('g') = opt('p') = opt('t') = opt('b') = 1;
E 9
I 9
	    opt('p') = opt('t') = opt('b') = 1;
D 18
#ifdef vax
	    /* pdx is currently supported only on the vax */
E 18
I 18
#if defined(vax) || defined(tahoe)
	    /* pdx is currently supported on the vax and the tahoe */
E 18
	    opt('g') = 1;
D 18
#endif vax
E 18
I 18
#endif
E 18
E 9
E 6
	    while (argc > 0) {
		    cp = argv[0];
		    if (*cp++ != '-')
			    break;
		    while (c = *cp++) switch (c) {
#ifdef DEBUG
			    case 'k':
			    case 'r':
			    case 'y':
				    togopt(c);
				    continue;
			    case 'K':
				    yycosts();
				    pexit(NOSTART);
			    case 'A':
D 4
				    testtrace++;
E 4
I 4
				    testtrace = TRUE;
E 4
			    case 'F':
D 4
				    fulltrace++;
E 4
I 4
				    fulltrace = TRUE;
E 4
			    case 'E':
D 4
				    errtrace++;
E 4
I 4
				    errtrace = TRUE;
E 4
				    opt('r')++;
				    continue;
			    case 'U':
D 11
				    yyunique = 0;
E 11
I 11
				    yyunique = FALSE;
E 11
				    continue;
#endif
			    case 'b':
				    opt('b') = 2;
				    continue;
			    case 'i':
				    pflist = argv + 1;
				    pflstc = 0;
				    while (argc > 1) {
					    if (dotted(argv[1], 'p'))
						    break;
					    pflstc++, argc--, argv++;
				    }
				    if (pflstc == 0)
					    goto usage;
				    continue;
I 6
			    case 'g':
E 6
			    case 'l':
			    case 'n':
			    case 'p':
			    case 's':
			    case 't':
			    case 'u':
			    case 'w':
				    togopt(c);
				    continue;
			    case 'z':
D 4
				    monflg++;
E 4
I 4
				    monflg = TRUE;
E 4
				    continue;
I 14
			    case 'L':
				    togopt( 'L' );
				    continue;
E 14
			    default:
    usage:
				    Perror( "Usage", usageis);
				    pexit(NOSTART);
		    }
		    argc--, argv++;
	    }
#	endif OBJ
#	ifdef PC
	    opt( 'b' ) = 1;
	    opt( 'g' ) = 0;
	    opt( 't' ) = 0;
	    opt( 'p' ) = 0;
	    usageis = pcusage;
	    while ( argc > 0 ) {
		cp = argv[0];
		if ( *cp++ != '-' ) {
		    break;
		}
		c = *cp++;
		switch( c ) {
#ifdef DEBUG
		    case 'k':
		    case 'r':
		    case 'y':
			    togopt(c);
			    break;
		    case 'K':
			    yycosts();
			    pexit(NOSTART);
		    case 'A':
D 5
			    testtrace++;
E 5
I 5
			    testtrace = TRUE;
E 5
			    /* and fall through */
		    case 'F':
D 5
			    fulltrace++;
E 5
I 5
			    fulltrace = TRUE;
E 5
			    /* and fall through */
		    case 'E':
D 5
			    errtrace++;
E 5
I 5
			    errtrace = TRUE;
E 5
			    opt('r')++;
			    break;
		    case 'U':
D 11
			    yyunique = 0;
E 11
I 11
			    yyunique = FALSE;
E 11
			    break;
#endif
		    case 'b':
			    opt('b') = 2;
			    break;
		    case 'i':
			    pflist = argv + 1;
			    pflstc = 0;
			    while (argc > 1) {
				    if (dotted(argv[1], 'p'))
					    break;
				    pflstc++, argc--, argv++;
			    }
			    if (pflstc == 0)
				    goto usage;
			    break;
			/*
			 *	output file for the first pass
			 */
		    case 'o':
			    if ( argc < 2 ) {
				goto usage;
			    }
			    argv++;
			    argc--;
			    pcname = argv[0];
			    break;	
I 10
		    case 'J':
			    togopt( 'J' );
			    break;
E 10
		    case 'C':
				/*
				 * since -t is an ld switch, use -C
				 * to turn on tests
				 */
			    togopt( 't' );
			    break;
		    case 'g':
				/*
				 *	sdb symbol table
				 */
			    togopt( 'g' );
			    break;
		    case 'l':
		    case 's':
		    case 'u':
		    case 'w':
			    togopt(c);
			    break;
		    case 'p':
				/*
				 *	-p on the command line means profile
				 */
D 5
			    profflag++;
E 5
I 5
			    profflag = TRUE;
E 5
			    break;
		    case 'z':
D 5
			    monflg++;
E 5
I 5
			    monflg = TRUE;
E 5
			    break;
I 14
		    case 'L':
			    togopt( 'L' );
			    break;
E 14
		    default:
usage:
			    Perror( "Usage", usageis);
			    pexit(NOSTART);
		}
		argc--;
		argv++;
	    }
#	endif PC
	if (argc != 1)
		goto usage;
D 8
	efil = open ( errfile, 0 );
E 8
I 8
	efil = open ( err_file, 0 );
E 8
	if ( efil < 0 )
D 8
		perror(errfile), pexit(NOSTART);
E 8
I 8
		perror(err_file), pexit(NOSTART);
E 8
	filename = argv[0];
	if (!dotted(filename, 'p')) {
		Perror(filename, "Name must end in '.p'");
		pexit(NOSTART);
	}
	close(0);
	if ( ( ibuf = fopen( filename , "r" ) ) == NULL )
		perror(filename), pexit(NOSTART);
	ibp = ibuf;
#	ifdef PC
	    if ( ( pcstream = fopen( pcname , "w" ) ) == NULL ) {
		perror( pcname );
		pexit( NOSTART );
	    }
D 14
	    stabsource( filename );
E 14
I 14
	    stabsource( filename, TRUE );
E 14
#	endif PC
#	ifdef PTREE
#	    define	MAXpPAGES	16
	    if ( ! pCreate( pTreeName , MAXpPAGES ) ) {
		perror( pTreeName );
		pexit( NOSTART );
	    }
#	endif PTREE
	if ( signal( SIGINT , SIG_IGN ) != SIG_IGN )
D 11
		signal( SIGINT , onintr );
E 11
I 11
		(void) signal( SIGINT , onintr );
E 11
	if (opt('l')) {
		opt('n')++;
		yysetfile(filename);
		opt('n')--;
	}
	yymain();
	/* No return */
}

pchr(c)
	char c;
{

	putc ( c , stdout );
}

I 16
#ifdef PC
char	ugh[]	= "Fatal error in pc\n";
#endif
#ifdef OBJ
E 16
char	ugh[]	= "Fatal error in pi\n";
I 16
#endif
E 16
/*
 * Exit from the Pascal system.
 * We throw in an ungraceful termination
 * message if c > 1 indicating a severe
 * error such as running out of memory
 * or an internal inconsistency.
 */
pexit(c)
	int c;
{

	if (opt('l') && c != DIED && c != NOSTART)
		while (getline() != -1)
			continue;
	yyflush();
	switch (c) {
		case DIED:
			write(2, ugh, sizeof ugh);
		case NOSTART:
		case ERRS:
#			ifdef OBJ
			    if (ofil > 0)
				    unlink(obj);
I 6
			/*
			 * remove symbol table temp files
			 */
			    removenlfile();

E 6
#			endif OBJ
#			ifdef PC
			    if ( pcstream != NULL ) {
				unlink( pcname );
			    }
#			endif PC
			break;
		case AOK:
#			ifdef OBJ
			    pflush();
I 6
			/*
			 * copy symbol table temp files to obj file
			 */
			    copynlfile();

E 6
#			endif OBJ
#			ifdef PC
			    puteof();
#			endif PC
			break;
	}
	/*
	 *	this to gather statistics on programs being compiled
	 *	taken 20 june 79 	... peter
	 *
	 *  if (fork() == 0) {
	 *  	char *cp = "-0";
	 *  	cp[1] += c;
	 *  	execl("/usr/lib/gather", "gather", cp, filename, 0);
	 *  	exit(1);
	 *  }
	 */
#	ifdef PTREE
	    pFinish();
#	endif
	exit(c);
}

onintr()
{

D 11
	signal( SIGINT , SIG_IGN );
E 11
I 11
	(void) signal( SIGINT , SIG_IGN );
E 11
	pexit(NOSTART);
}

/*
 * Get an error message from the error message file
 */
geterr(seekpt, buf)
	int seekpt;
	char *buf;
{

D 11
	lseek(efil, (long) seekpt, 0);
E 11
I 11
	(void) lseek(efil, (long) seekpt, 0);
E 11
	if (read(efil, buf, 256) <= 0)
D 8
		perror(errfile), pexit(DIED);
E 8
I 8
		perror(err_file), pexit(DIED);
E 8
}

header()
{
D 8
	extern char version[];
E 8
I 8
	extern char *version;
E 8
	static char anyheaders;

	gettime( filename );
	if (anyheaders && opt('n'))
		putc( '\f' , stdout );
	anyheaders++;
#	ifdef OBJ
D 8
	    printf("Berkeley Pascal PI -- Version 2.0 (%s)\n\n%s  %s\n\n",
E 8
I 8
	    printf("Berkeley Pascal PI -- Version %s\n\n%s  %s\n\n",
E 8
D 11
		    version, myctime(&tvec), filename);
E 11
I 11
		    version, myctime((int *) (&tvec)), filename);
E 11
#	endif OBJ
#	ifdef PC
D 8
	    printf("Berkeley Pascal PC -- Version 2.0 (%s)\n\n%s  %s\n\n",
E 8
I 8
	    printf("Berkeley Pascal PC -- Version %s\n\n%s  %s\n\n",
E 8
D 11
		    version, myctime(&tvec), filename);
E 11
I 11
		    version, myctime((int *) (&tvec)), filename);
E 11
#	endif PC
}
E 1
