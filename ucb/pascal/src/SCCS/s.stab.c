h26919
s 00003/00003/00863
d D 5.3 88/01/03 00:15:29 bostic 19 18
c const is a reserved word in ANSI C
e
s 00002/00002/00864
d D 5.2 85/10/23 18:30:18 mckusick 18 17
c fix for array of array (from torek@gyre.umd.edu)
e
s 00007/00003/00859
d D 5.1 85/06/05 14:54:13 dist 17 16
c Add copyright
e
s 00002/00003/00860
d D 2.3 85/03/15 22:57:53 mckusick 16 14
i 15
c merge dbx from linton
e
s 00560/00055/00316
d D 1.9.1.1 85/03/15 22:46:46 mckusick 15 9
c new dbx from linton
e
s 00001/00000/00356
d D 2.2 85/02/28 17:04:23 mckusick 14 13
c add missing line
e
s 00000/00000/00356
d D 2.1 84/02/08 20:50:10 aoki 13 12
c synchronize to version 2
e
s 00002/00001/00354
d D 1.11 84/02/07 13:35:56 mckusick 12 11
c lint
e
s 00011/00022/00344
d D 1.10 84/02/06 20:23:15 mckusick 11 9
i 10
c merge lint by thien
e
s 00030/00045/00281
d D 1.8.1.1 84/02/04 20:31:22 mckusick 10 8
c lint (by thien)
e
s 00090/00045/00281
d D 1.9 83/07/26 09:46:54 peter 9 8
c using checksum on include files and flag day indicators on source files.
e
s 00001/00000/00325
d D 1.8 83/02/01 20:00:31 peter 8 7
c header file moves as we port to the mc68000.
e
s 00008/00008/00317
d D 1.7 82/08/27 00:28:58 mckusick 7 6
c convert namelist structure to use unions
e
s 00003/00005/00322
d D 1.6 81/03/24 17:53:25 peter 6 5
c add sextname() to make up long external names for things.
e
s 00026/00012/00301
d D 1.5 81/01/15 13:24:42 peter 5 4
c get sdb stabs into the right places.  use nm -ap for details.
e
s 00001/00001/00312
d D 1.4 80/11/17 20:02:50 peter 4 3
c fix so that local variables are accessible from sdb
e
s 00034/00040/00279
d D 1.3 80/09/04 23:09:58 peter 3 2
c N_PC stabs with subtypes
e
s 00117/00188/00202
d D 1.2 80/08/31 17:31:20 peter 2 1
c stabs for separate compilation type checking
e
s 00390/00000/00000
d D 1.1 80/08/27 19:56:22 peter 1 0
c date and time created 80/08/27 19:56:22 by peter
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
D 17
/* Copyright (c) 1980 Regents of the University of California */
E 17
I 17
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 17
E 2

I 10
#ifndef lint
E 10
I 2
D 17
static	char sccsid[] = "%Z%%M% %I% %G%";
I 10
#endif
E 17
I 17
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 17
E 10

E 2
    /*
D 2
     *	procedures to put out sdb symbol table information
     *	    these use the new .stabs, .stabn, and .stabd directives
E 2
I 2
D 15
     *	procedures to put out sdb symbol table information.
E 15
I 15
     *	Procedures to put out symbol table information
E 15
     *	and stabs for separate compilation type checking.
D 15
     *	these use the new .stabs, .stabn, and .stabd directives
E 15
I 15
     *	These use the .stabs, .stabn, and .stabd directives.
E 15
E 2
     */

D 2
static	char sccsid[] = "%Z%%M% %I% %G%";

E 2
#include	"whoami.h"
#ifdef	PC
    /*	and the rest of the file */
#   include	"0.h"
I 8
#   include	"objfmt.h"
I 9
#   include	"yy.h"
E 9
E 8
#   include	<stab.h>

D 2
    /*
     *	here's that ugly name length limit of 8 characters
     *	until someone fixes sdb.
     */
#define	SNAMELENGTH	8
#define	SNAMEFORMAT	"%.*s"
E 2
D 3
/*
 *  the file "p.a.out" has an additional symbol definition for "a.out.h"
 *	that is used by the separate compilation facility --
 *	eventually, "a.out.h" must be updated to include this 
 */
E 3
I 3
    /*
     *  additional symbol definition for <stab.h>
     *	that is used by the separate compilation facility --
     *	eventually, <stab.h> should be updated to include this 
     */
E 3

D 3
#   include	"p.a.out.h"
E 3
I 3
#   include	"pstab.h"
E 3
#   include	"pc.h"

I 15

#define private static

int oldway = 0;

E 15
    /*
I 2
     *	absolute value: line numbers are negative if error recovery.
     */
#define	ABS( x )	( x < 0 ? -x : x )
I 12
long checksum();
E 12

I 15
/*
 * Generate information about variables.
 */

stabgvar (p, length, line)
struct nl *p;
int length, line;
{
    putprintf("	.stabs	\"%s\",0x%x,0,0x%x,0x%x",
	0, p->symbol, N_PC, N_PGVAR, ABS(line)
    );
    if (oldway != 0) {
	oldstabgvar(p->symbol, p2type(p->type), 0, length, line);
    } else if (opt('g')) {
	putprintf("\t.stabs\t\"%s:G", 1, p->symbol);
	gentype(p->type);
	putprintf("\",0x%x,0,0x%x,0", 0, N_GSYM, length);
    }
}

stablvar (p, offset, length)
struct nl *p;
int offset, length;
{
    int level;

    level = (p->nl_block & 037);
    if (oldway != 0) {
	oldstablvar(p->symbol, p2type(p->type), level, offset, length);
    } else if (opt('g')) {
	putprintf("\t.stabs\t\"%s:", 1, p->symbol);
	gentype(p->type);
	putprintf("\",0x%x,0,0x%x,0x%x", 0, N_LSYM, length, offset);
    }
}

E 15
    /*
E 2
D 5
     *	variables
E 5
I 5
     *	global variables
E 5
     */
I 10
/*ARGSUSED*/
E 10
D 2
stabvar( name , type , level , offset , length )
E 2
I 2
D 5
stabvar( name , type , level , offset , length , line )
E 5
I 5
D 15
stabgvar( name , type , offset , length , line )
E 15
I 15
oldstabgvar( name , type , offset , length , line )
E 15
E 5
E 2
    char	*name;
    int		type;
D 5
    int		level;
E 5
    int		offset;
    int		length;
I 2
    int		line;
E 2
    {
D 2
	char	*nullchar;
	char	*cp;
E 2
D 15

D 2
	/* for separate compilation */

	if ((level == 1) && (strcmp(name, DISPLAYNAME) != 0)) {
		nullchar = name;
		while ( *nullchar ) {
	    		nullchar ++;
		}
		for ( cp = name ; cp < nullchar ; cp += SNAMELENGTH ) {
		    putprintf( "	.stabs	\"" , 1 );
		    putprintf( SNAMEFORMAT , 1 , SNAMELENGTH , cp );
	    	    putprintf( "\",0%o,0,0,0" , 0 , N_PGVAR , 0 );
		}
		if ( cp == nullchar ) {
		/*
		 * then the name was exactly a multiple of SNAMELENGTH long,
		 * and i have to put out a null to terminate it.
		 */
	    	putprintf( "	.stabn	0%o,0,0,0" , 0
			, N_PGVAR, 0 );
		}
E 2
I 2
	    /*
	     *	for separate compilation
	     */
D 5
	if ( level == 1 ) {
D 3
	    putprintf( "	.stabs	\"" , 1 );
	    putprintf( NAMEFORMAT , 1 , name );
	    putprintf( "\",0x%x,0,0,0x%x" , 0 , N_PGVAR , ABS( line ) );
E 3
I 3
	    putprintf( "	.stabs	\"%s\",0x%x,0,0x%x,0x%x" , 0 
			, name , N_PC , N_PGVAR , ABS( line ) );
E 3
E 2
    	}
E 5
I 5
	putprintf( "	.stabs	\"%s\",0x%x,0,0x%x,0x%x" , 0 
D 10
		    , name , N_PC , N_PGVAR , ABS( line ) );
E 10
I 10
		    , (int) name , N_PC , N_PGVAR , ABS( line ) );
E 10
E 5
D 2

	/* for sdb */
E 2
I 2
	    /*
	     *	for sdb
	     */
E 15
E 2
	if ( ! opt('g') ) {
		return;
	}
	putprintf( "	.stabs	\"" , 1 );
D 10
	putprintf( NAMEFORMAT , 1 , name );
E 10
I 10
	putprintf( NAMEFORMAT , 1 , (int) name );
E 10
D 5
	if ( level == 1 ) {
D 2
		putprintf( "\",0%o,0,0%o,0" , 0 , N_GSYM , type );
E 2
I 2
		putprintf( "\",0x%x,0,0x%x,0" , 0 , N_GSYM , type );
E 2
	} else {
D 2
		putprintf( "\",0%o,0,0%o,%d" , 0
				, N_LSYM , type , offset);
E 2
I 2
D 4
		putprintf( "\",0x%x,0,0x%x,0x%x" , 0 , N_LSYM , type , offset );
E 4
I 4
		putprintf( "\",0x%x,0,0x%x,0x%x" , 0 , N_LSYM , type , -offset );
E 4
E 2
	}
E 5
I 5
	putprintf( "\",0x%x,0,0x%x,0" , 0 , N_GSYM , type );
E 5
	putprintf( "	.stabs	\"" , 1 );
D 10
	putprintf( NAMEFORMAT , 1 , name );
E 10
I 10
	putprintf( NAMEFORMAT , 1 , (int) name );
E 10
D 2
	putprintf( "\",0%o,0,0,0%o" , 0 , N_LENG , length );
E 2
I 2
	putprintf( "\",0x%x,0,0,0x%x" , 0 , N_LENG , length );
I 5
}
E 5
E 2

I 5
    /*
     *	local variables
     */
I 10
/*ARGSUSED*/
E 10
D 15
stablvar( name , type , level , offset , length )
E 15
I 15
oldstablvar( name , type , level , offset , length )
E 15
    char	*name;
    int		type;
    int		level;
    int		offset;
    int		length;
    {

	if ( ! opt('g') ) {
		return;
	}
	putprintf( "	.stabs	\"" , 1 );
D 10
	putprintf( NAMEFORMAT , 1 , name );
E 10
I 10
	putprintf( NAMEFORMAT , 1 , (int) name );
E 10
	putprintf( "\",0x%x,0,0x%x,0x%x" , 0 , N_LSYM , type , -offset );
	putprintf( "	.stabs	\"" , 1 );
D 10
	putprintf( NAMEFORMAT , 1 , name );
E 10
I 10
	putprintf( NAMEFORMAT , 1 , (int) name );
E 10
	putprintf( "\",0x%x,0,0,0x%x" , 0 , N_LENG , length );
E 5
}


I 15
stabparam (p, offset, length)
struct nl *p;
int offset, length;
{
    if (oldway != 0) {
	oldstabparam(p->symbol, p2type(p->type), offset, length);
    } else if (opt('g')) {
	putprintf("\t.stabs\t\"%s:", 1, p->symbol);
	if (p->class == REF) {
	    putprintf("v", 1);
	} else {
	    putprintf("p", 1);
	}
	gentype((p->class == FPROC || p->class ==FFUNC) ? p : p->type);
	putprintf("\",0x%x,0,0x%x,0x%x", 0, N_PSYM, length, offset);
    }
}

E 15
    /*
     *	parameters
     */
D 15
stabparam( name , type , offset , length )
E 15
I 15
oldstabparam( name , type , offset , length )
E 15
    char	*name;
    int		type;
    int		offset;
    int		length;
    {
	
	if ( ! opt('g') ) {
		return;
	}
	putprintf( "	.stabs	\"" , 1 );
D 10
	putprintf( NAMEFORMAT , 1 , name );
E 10
I 10
	putprintf( NAMEFORMAT , 1 , (int) name );
E 10
D 2
	putprintf( "\",0%o,0,0%o,%d" , 0 , N_PSYM , type , offset );
E 2
I 2
	putprintf( "\",0x%x,0,0x%x,0x%x" , 0 , N_PSYM , type , offset );
E 2
	putprintf( "	.stabs	\"" , 1 );
D 10
	putprintf( NAMEFORMAT , 1 , name );
E 10
I 10
	putprintf( NAMEFORMAT , 1 , (int) name );
E 10
D 2
	putprintf( "\",0%o,0,0,0%o" , 0 , N_LENG , length );
E 2
I 2
	putprintf( "\",0x%x,0,0,0x%x" , 0 , N_LENG , length );
E 2
    }

    /*
     *	fields
     */
D 10
stabfield( name , type , offset , length )
    char	*name;
    int		type;
    int		offset;
    int		length;
    {
	
	if ( ! opt('g') ) {
		return;
	}
	putprintf( "	.stabs	\"" , 1 );
	putprintf( NAMEFORMAT , 1 , name );
D 2
	putprintf( "\",0%o,0,0%o,%d" , 0 , N_SSYM , type , offset );
E 2
I 2
	putprintf( "\",0x%x,0,0x%x,0x%x" , 0 , N_SSYM , type , offset );
E 2
	putprintf( "	.stabs	\"" , 1 );
	putprintf( NAMEFORMAT , 1 , name );
D 2
	putprintf( "\",0%o,0,0,0%o" , 0 , N_LENG , length );
E 2
I 2
	putprintf( "\",0x%x,0,0,0x%x" , 0 , N_LENG , length );
E 2
    }
E 10

    /*
     *	left brackets
I 15
     *  (dbx handles module-2 without these, so we won't use them either)
E 15
     */
stablbrac( level )
    int	level;
    {

D 15
	if ( ! opt('g') ) {
E 15
I 15
	if ( ! opt('g') || oldway == 0 ) {
E 15
		return;
	}
D 2
	putprintf( "	.stabd	0%o,0,%d" , 0 , N_LBRAC , level );
E 2
I 2
	putprintf( "	.stabd	0x%x,0,0x%x" , 0 , N_LBRAC , level );
E 2
    }

    /*
     *	right brackets
     */
stabrbrac( level )
    int	level;
    {

D 15
	if ( ! opt('g') ) {
E 15
I 15
	if ( ! opt('g') || oldway == 0 ) {
E 15
		return;
	}
D 2
	putprintf( "	.stabd	0%o,0,%d" , 0 , N_RBRAC , level );
E 2
I 2
	putprintf( "	.stabd	0x%x,0,0x%x" , 0 , N_RBRAC , level );
E 2
    }

I 15
stabfunc (p, name, line, level)
struct nl *p;
char *name;
int line, level;
{
    char extname[BUFSIZ],nestspec[BUFSIZ];
    
    if ( level == 1 ) {
	if (p->class == FUNC) {
	    putprintf("	.stabs	\"%s\",0x%x,0,0x%x,0x%x" ,
		0 , name , N_PC , N_PGFUNC , ABS( line )
	    );
	} else if (p->class == PROC) {
	    putprintf("	.stabs	\"%s\",0x%x,0,0x%x,0x%x" ,
		0 , name , N_PC , N_PGPROC , ABS( line )
	    );
	}
    }
    if (oldway != 0) {
	oldstabfunc(name, p->class, line, level);
    } else if (opt('g')) {
	putprintf("\t.stabs\t\"%s:", 1, name);
	if (p->class == FUNC) {
	    putprintf("F", 1);
	    gentype(p->type);
	    putprintf(",", 1);
	} else {
	    putprintf("P,", 1);
	}
	sextname(extname, name, level);  /* set extname to entry label */
	putprintf("%s,", 1, &(extname[1])); /* remove initial underbar */
	snestspec(nestspec, level);
	putprintf("%s\",0x%x,0,0,%s", 0, nestspec, N_FUN, extname);
    }
}

E 15
    /*
I 15
     * construct the colon-separated static nesting string into a
     * caller-supplied buffer
     */
private snestspec(buffer, level)
    char buffer[];
    int level;
{
    char *starthere;
    int i;
    
    if (level <= 1) {
	buffer[0] = '\0';
    } else {
	starthere = &buffer[0];
	for ( i = 1 ; i < level ; i++ ) {
	    sprintf(starthere, "%s:", enclosing[i]);
	    starthere += strlen(enclosing[i]) + 1;
	}
D 18
	*starthere-- = '\0'; /* remove last colon */
E 18
I 18
	*--starthere = '\0'; /* remove last colon */
E 18
	if (starthere >= &buffer[BUFSIZ-1]) {
	    panic("snestspec");
	}
    }
}

    /*
E 15
     *	functions
     */
D 2
stabfunc( name , line , level )
E 2
I 2
D 7
stabfunc( name , class , line , level )
E 7
I 7
D 15
stabfunc( name , typeclass , line , level )
E 15
I 15
oldstabfunc( name , typeclass , line , level )
E 15
E 7
E 2
    char	*name;
I 2
D 7
    int		class;
E 7
I 7
    int		typeclass;
E 7
E 2
    int		line;
    long	level;
    {
I 2
D 10
	int	type;
	long	i;
E 10
I 6
	char	extname[ BUFSIZ ];
E 6
E 2

D 2
	char	*nullchar;
	char	*cp;
	int	i;

	/*
	 *	for separate compilation
	 */
	nullchar = name;
	while ( *nullchar ) {
	    	nullchar ++;
	}
	for ( cp = name ; cp < nullchar ; cp += SNAMELENGTH ) {
E 2
I 2
	    /*
D 15
	     *	for separate compilation
	     */
	if ( level == 1 ) {
D 7
	    if ( class == FUNC ) {
E 7
I 7
	    if ( typeclass == FUNC ) {
E 7
E 2
D 3
		putprintf( "	.stabs	\"" , 1 );
D 2
		putprintf( SNAMEFORMAT , 1 , SNAMELENGTH , cp );
	    	putprintf( "\",0%o,0,0,0" , 0 , N_PFUN , 0 );
E 2
I 2
		putprintf( NAMEFORMAT , 1 , name );
		putprintf( "\",0x%x,0,0,0x%x" , 0 , N_PGFUN , ABS( line ) );
E 3
I 3
		putprintf( "	.stabs	\"%s\",0x%x,0,0x%x,0x%x" , 0 
D 10
			    , name , N_PC , N_PGFUNC , ABS( line ) );
E 10
I 10
			    , (int) name , N_PC , N_PGFUNC , ABS( line ) );
E 10
E 3
D 7
	    } else if ( class == PROC ) {
E 7
I 7
	    } else if ( typeclass == PROC ) {
E 7
D 3
		putprintf( "	.stabs	\"" , 1 );
		putprintf( NAMEFORMAT , 1 , name );
		putprintf( "\",0x%x,0,0,0x%x" , 0 , N_PGPRC , ABS( line ) );
E 3
I 3
		putprintf( "	.stabs	\"%s\",0x%x,0,0x%x,0x%x" , 0 
D 10
			    , name , N_PC , N_PGPROC , ABS( line ) );
E 10
I 10
			    , (int) name , N_PC , N_PGPROC , ABS( line ) );
E 10
E 3
	    }
E 2
	}
D 2
	if ( cp == nullchar ) {
	putprintf( "	.stabn	0%o,0,0,0" , 0 , N_PFUN, 0 );
	}

	/* for sdb */
E 2
I 2
	    /*
E 15
	     *	for sdb
	     */
E 2
	if ( ! opt('g') ) {
		return;
	}
	putprintf( "	.stabs	\"" , 1 );
D 10
	putprintf( NAMEFORMAT , 1 , name );
D 2
	putprintf( "\",0%o,0,%d," , 1 , N_FUN , line );
E 2
I 2
D 6
	putprintf( "\",0x%x,0,0x%x," , 1 , N_FUN , line );
E 2
	for ( i = 1 ; i < level ; i++ ) {
	    putprintf( EXTFORMAT , 1 , enclosing[ i ] );
	}
	putprintf( EXTFORMAT , 0 , name );
E 6
I 6
	sextname( extname , name , level );
	putprintf( "\",0x%x,0,0x%x,%s" , 0 , N_FUN , line , extname );
E 10
I 10
	putprintf( NAMEFORMAT , 1 , (int) name );
	sextname( extname , name , (int) level );
	putprintf( "\",0x%x,0,0x%x,%s" , 0 , N_FUN , line , (int) extname );
E 10
E 6
    }

    /*
     *	source line numbers
     */
stabline( line )
    int	line;
    {
	if ( ! opt('g') ) {
		return;
	}
D 2
	if ( line < 0 ) {
		/*
		 *	line numbers get to be negative if there was an error.
		 */
	    line = -line;
	}
	
	putprintf( "	.stabd	0%o,0,%d" , 0 , N_SLINE , line );
E 2
I 2
	putprintf( "	.stabd	0x%x,0,0x%x" , 0 , N_SLINE , ABS( line ) );
E 2
    }

    /*
D 15
     *	source files
E 15
I 15
     *	source files get none or more of these:
     *  one as they are entered,
     *  and one every time they are returned to from nested #includes
E 15
     */
D 9
stabsource( filename )
E 9
I 9
D 15
stabsource(filename)
E 15
I 15
stabsource(filename, firsttime)
E 15
E 9
    char	*filename;
I 15
    bool	firsttime;
E 15
D 9
    {
D 2
	int	label = getlab();
	char	*nullchar;
	char	*cp;
E 2
I 2
	int	label;
E 2
	
D 2
	nullchar = filename;
	while ( *nullchar ) {
    		nullchar ++;
	}
	for ( cp = filename ; cp < nullchar ; cp += SNAMELENGTH ) {
	    putprintf( "	.stabs	\"" , 1 );
	    putprintf( SNAMEFORMAT , 1 , SNAMELENGTH , cp );
    	    putprintf( "\",0%o,0,0,0" , 0 , N_PSO , 0 );
	}
	if ( cp == nullchar ) {
	/*
	 * then the name was exactly a multiple of SNAMELENGTH long,
	 */
    	putprintf( "	.stabn	0%o,0,0,0" , 0 , N_PSO, 0 );
	}

	/* for sdb */
E 2
I 2
	    /*
	     *	for separate compilation
	     */
D 3
	putprintf( "	.stabs	\"" , 1 );
	putprintf( NAMEFORMAT , 1 , filename );
	putprintf( "\",0x%x,0,0,0" , 0 , N_PSO );
E 3
I 3
	putprintf( "	.stabs	\"%s\",0x%x,0,0x%x,0" , 0 
D 10
		    , filename , N_PC , N_PSO );
E 10
I 10
D 11
		    , (int) filename , N_PC , N_PSO );
E 10
E 3
	    /*
	     *	for sdb
	     */
E 2
	if ( ! opt('g') ) {
		return;
	}
I 2
D 10
	label = getlab();
E 10
I 10
	label = (int) getlab();
E 10
E 2
	putprintf( "	.stabs	\"" , 1 );
D 10
	putprintf( NAMEFORMAT , 1 , filename );
E 10
I 10
	putprintf( NAMEFORMAT , 1 , (int) filename );
E 10
D 2
	putprintf( "\",0%o,0,0," , 1 , N_SO );
E 2
I 2
	putprintf( "\",0x%x,0,0," , 1 , N_SO );
E 2
D 10
	putprintf( PREFIXFORMAT , 0 , LLABELPREFIX , label );
	putprintf( PREFIXFORMAT , 1 , LLABELPREFIX , label );
E 10
I 10
	putprintf( PREFIXFORMAT , 0 , (int) LLABELPREFIX , label );
	putprintf( PREFIXFORMAT , 1 , (int) LLABELPREFIX , label );
E 11
E 10
	putprintf( ":" , 0 );
E 9
I 9
{
    int		label;
    
	/*
	 *	for separate compilation
	 */
    putprintf("	.stabs	\"%s\",0x%x,0,0x%x,0x%x", 0,
D 11
	    filename, N_PC, N_PSO, N_FLAGCHECKSUM);
E 11
I 11
	    (int) filename, N_PC, N_PSO, N_FLAGCHECKSUM);
E 11
	/*
D 15
	 *	for sdb
E 15
I 15
	 *	for debugger
E 15
	 */
    if ( ! opt('g') ) {
	    return;
E 9
    }
I 9
D 11
D 15
    label = getlab();
E 11
I 11
    label = (int) getlab();
E 11
    putprintf( "	.stabs	\"" , 1 );
D 11
    putprintf( NAMEFORMAT , 1 , filename );
E 11
I 11
    putprintf( NAMEFORMAT , 1 , (int) filename );
E 11
    putprintf( "\",0x%x,0,0," , 1 , N_SO );
D 11
    putprintf( PREFIXFORMAT , 0 , LLABELPREFIX , label );
    putprintf( PREFIXFORMAT , 1 , LLABELPREFIX , label );
E 11
I 11
    putprintf( PREFIXFORMAT , 0 , (int) LLABELPREFIX , label );
    putprintf( PREFIXFORMAT , 1 , (int) LLABELPREFIX , label );
E 11
    putprintf( ":" , 0 );
E 15
I 15
    if (oldway != 0) {
D 16
	label = getlab();
E 16
I 16
	label = (int) getlab();
E 16
	putprintf( "	.stabs	\"" , 1 );
	putprintf( NAMEFORMAT , 1 , filename );
	putprintf( "\",0x%x,0,0," , 1 , N_SO );
	putprintf( PREFIXFORMAT , 0 , LLABELPREFIX , label );
	putprintf( PREFIXFORMAT , 1 , LLABELPREFIX , label );
	putprintf( ":" , 0 );
    } else {
	if (firsttime) {
	    putprintf( "	.stabs	\"" , 1 );
	    putprintf( NAMEFORMAT , 1 , filename );
	    putprintf( "\",0x%x,0,0,0" , 0 , N_SO );
	}
    }
E 15
}
E 9

    /*
     *	included files get one or more of these:
     *	one as they are entered by a #include,
D 9
     *	and one every time they are returned to by nested #includes
E 9
I 9
     *	and one every time they are returned to from nested #includes.
E 9
     */
D 9
stabinclude( filename )
E 9
I 9
stabinclude(filename, firsttime)
E 9
    char	*filename;
D 9
    {
D 2
	int	label = getlab();
	char	*nullchar;
	char	*cp;
E 2
I 2
	int	label;
E 2
	
D 2
	nullchar = filename;
	while ( *nullchar ) {
    		nullchar ++;
	}
	for ( cp = filename ; cp < nullchar ; cp += SNAMELENGTH ) {
	    putprintf( "	.stabs	\"" , 1 );
	    putprintf( SNAMEFORMAT , 1 , SNAMELENGTH , cp );
    	    putprintf( "\",0%o,0,0,0" , 0 , N_PSOL , 0 );
	}
	if ( cp == nullchar ) {
	/*
	 * then the name was exactly a multiple of SNAMELENGTH long,
	 */
    	putprintf( "	.stabn	0%o,0,0,0" , 0 , N_PSOL, 0 );
	}

	/* for sdb */
E 2
I 2
D 3
	putprintf( "	.stabs	\"" , 1 );
	putprintf( NAMEFORMAT , 1 , filename );
	putprintf( "\",0x%x,0,0,0" , 0 , N_PSOL );
E 3
	    /*
I 3
	     *	for separate compilation
	     */
	putprintf( "	.stabs	\"%s\",0x%x,0,0x%x,0" , 0 
D 10
		    , filename , N_PC , N_PSOL );
E 10
I 10
D 11
		    , (int) filename , N_PC , N_PSOL );
E 10
	    /*
E 3
	     *	for sdb
	     */
E 2
	if ( ! opt('g') ) {
		return;
	}
I 2
D 10
	label = getlab();
E 10
I 10
	label = (int) getlab();
E 10
E 2
	putprintf( "	.stabs	\"" , 1 );
D 10
	putprintf( NAMEFORMAT , 1 , filename );
E 10
I 10
	putprintf( NAMEFORMAT , 1 , (int) filename );
E 10
D 2
	putprintf( "\",0%o,0,0," , 1 , N_SOL );
E 2
I 2
	putprintf( "\",0x%x,0,0," , 1 , N_SOL );
E 2
D 10
	putprintf( PREFIXFORMAT , 0 , LLABELPREFIX , label );
	putprintf( PREFIXFORMAT , 1 , LLABELPREFIX , label );
E 10
I 10
	putprintf( PREFIXFORMAT , 0 , (int) LLABELPREFIX , label );
	putprintf( PREFIXFORMAT , 1 , (int) LLABELPREFIX , label );
E 11
E 10
	putprintf( ":" , 0 );
E 9
I 9
    bool	firsttime;
{
D 11
    int	label;
E 11
I 11
    int		label;
E 11
    long	check;
    
	/*
	 *	for separate compilation
	 */
    if (firsttime) {
	check = checksum(filename);
    } else {
	check = N_FLAGCHECKSUM;
E 9
    }
I 9
    putprintf("	.stabs	\"%s\",0x%x,0,0x%x,0x%x", 0,
D 11
	    filename, N_PC, N_PSOL, check);
E 11
I 11
	    (int) filename, N_PC, N_PSOL, check);
E 11
	/*
	 *	for sdb
	 */
    if ( ! opt('g') ) {
	    return;
    }
D 11
D 15
    label = getlab();
    putprintf( "	.stabs	\"" , 1 );
    putprintf( NAMEFORMAT , 1 , filename );
E 11
I 11
    label = (int) getlab();
I 14
    putprintf( "	.stabs	\"" , 1 );
E 14
    putprintf( NAMEFORMAT , 1 , (int) filename );
E 11
    putprintf( "\",0x%x,0,0," , 1 , N_SOL );
D 11
    putprintf( PREFIXFORMAT , 0 , LLABELPREFIX , label );
    putprintf( PREFIXFORMAT , 1 , LLABELPREFIX , label );
E 11
I 11
    putprintf( PREFIXFORMAT , 0 , (int) LLABELPREFIX , label );
    putprintf( PREFIXFORMAT , 1 , (int) LLABELPREFIX , label );
E 11
    putprintf( ":" , 0 );
E 15
I 15
    if (oldway != 0) {
D 16
	label = getlab();
E 16
I 16
	label = (int) getlab();
E 16
	putprintf( "	.stabs	\"" , 1 );
	putprintf( NAMEFORMAT , 1 , filename );
	putprintf( "\",0x%x,0,0," , 1 , N_SOL );
	putprintf( PREFIXFORMAT , 0 , LLABELPREFIX , label );
	putprintf( PREFIXFORMAT , 1 , LLABELPREFIX , label );
	putprintf( ":" , 0 );
    }
E 15
}
E 9

I 9
    /*
     *	anyone know a good checksum for ascii files?
     *	this does a rotate-left and then exclusive-or's in the character.
     *	also, it avoids returning checksums of 0.
     *	The rotate is implemented by shifting and adding back the
     *	sign bit when negative.
     */
long
checksum(filename)
    char	*filename;
{
    FILE		*filep;
    register int	input;
    register long	check;

    filep = fopen(filename, "r");
    if (filep == NULL) {
	perror(filename);
	pexit(DIED);
    }
    check = 0;
    while ((input = getc(filep)) != EOF) {
	if (check < 0) {
	    check <<= 1;
	    check += 1;
	} else {
	    check <<= 1;
	}
	check ^= input;
    }
D 12
    fclose(filep);
E 12
I 12
    (void) fclose(filep);
E 12
    if ((unsigned) check <= N_FLAGCHECKSUM) {
	return N_FLAGCHECKSUM + 1;
    } else {
	return check;
    }
}
E 9

/*
 * global Pascal symbols :
 *   labels, types, constants, and external procedure and function names:
 *   These are used by the separate compilation facility
 *   to be able to check for disjoint header files.
D 2
 *   New symbol codes : (N_PGVAR, N_PFUN defined above),
 *   N_PGLAB, N_PGCON, N_PGTYP  
 *   and N_PEFUN are defined for these additional global Pascal	
 *   symbols in p.a.out.h so that 
 *   they can be ignored by "sdb".  The only information
 *   put out for constants and types is their names.
 *   For labels, the integer label is put out. For external functions
 *   and procedures, the name of the function or procedure is put out.
E 2
 */

D 2
/* global constants */
stabcname( name )
    char *name;

E 2
I 2
    /*
     *	global labels
     */
D 3
stabglab( label , line )
E 3
I 3
stabglabel( label , line )
E 3
    char	*label;
    int		line;
E 2
    {
D 2
	char	*nullchar;
	char	*cp;
E 2

D 2
	nullchar = name;
	while ( *nullchar ) {
    		nullchar ++;
	}
	for ( cp = name ; cp < nullchar ; cp += SNAMELENGTH ) {
	    putprintf( "	.stabs	\"" , 1 );
	    putprintf( SNAMEFORMAT , 1 , SNAMELENGTH , cp );
    	    putprintf( "\",0%o,0,0,0" , 0 , N_PGCON , 0 );
	}
	if ( cp == nullchar ) {
    	putprintf( "	.stabn	0%o,0,0,0" , 0 , N_PGCON, 0 );
	}

E 2
I 2
D 3
	putprintf( "	.stabs	\"" , 1 );
	putprintf( PREFIXFORMAT , 1 , PLABELPREFIX , label );
	putprintf( "\",0x%x,0,0,0x%x" , 0 , N_PGLAB , ABS( line ) );
E 3
I 3
	putprintf( "	.stabs	\"%s\",0x%x,0,0x%x,0x%x" , 0 
D 10
		    , label , N_PC , N_PGLABEL , ABS( line ) );
E 10
I 10
		    , (int) label , N_PC , N_PGLABEL , ABS( line ) );
E 10
E 3
E 2
    }

D 2
/* global types */
stabtname( name )
    char *name;

E 2
I 2
    /*
     *	global constants
     */
D 3
stabcname( name , line )
    char	*name;
E 3
I 3
D 19
stabgconst( const , line )
    char	*const;
E 19
I 19
stabgconst( constant , line )
    char	*constant;
E 19
E 3
    int		line;
E 2
    {
D 2
	char	*nullchar;
	char	*cp;
E 2

D 2
	nullchar = name;
	while ( *nullchar ) {
    		nullchar ++;
	}
	for ( cp = name ; cp < nullchar ; cp += SNAMELENGTH ) {
	    putprintf( "	.stabs	\"" , 1 );
	    putprintf( SNAMEFORMAT , 1 , SNAMELENGTH , cp );
    	    putprintf( "\",0%o,0,0,0" , 0 , N_PGTYP , 0 );
	}
	if ( cp == nullchar ) {
    	putprintf( "	.stabn	0%o,0,0,0" , 0 , N_PGTYP, 0 );
	}
E 2
I 2
D 3
	putprintf( "	.stabs	\"" , 1 );
	putprintf( NAMEFORMAT , 1 , name );
	putprintf( "\",0x%x,0,0,0x%x" , 0 , N_PGCON , ABS( line ) );
E 3
I 3
	    putprintf( "	.stabs	\"%s\",0x%x,0,0x%x,0x%x" , 0 
D 10
			, const , N_PC , N_PGCONST , ABS( line ) );
E 10
I 10
D 19
			, (int) const , N_PC , N_PGCONST , ABS( line ) );
E 19
I 19
			, (int) constant , N_PC , N_PGCONST , ABS( line ) );
E 19
E 10
E 3
E 2
    }

D 2
/* global labels */
stabglab( label )
    int label;

E 2
I 2
D 15
    /*
     *	global types
     */
D 3
stabtname( name , line )
    char	*name;
E 3
I 3
stabgtype( type , line )
    char	*type;
E 3
    int		line;
E 2
    {
E 15
I 15
/*
 * Generate symbolic information about a constant.
 */
E 15

D 3
	putprintf( "	.stabs	\"" , 1 );
D 2
	putprintf( PREFIXFORMAT , 1 , PLABELPREFIX , label );
	putprintf( "\",0%o,0,0,0" , 0 , N_PGLAB , 0 );
E 2
I 2
	putprintf( NAMEFORMAT , 1 , name );
	putprintf( "\",0x%x,0,0,0x%x" , 0 , N_PGTYP , ABS( line ) );
E 3
I 3
D 15
	    putprintf( "	.stabs	\"%s\",0x%x,0,0x%x,0x%x" , 0 
D 10
			, type , N_PC , N_PGTYPE , ABS( line ) );
E 15
I 15
stabconst (c)
struct nl *c;
{
    if (opt('g') && oldway == 0) {
	putprintf("\t.stabs\t\"%s:c=", 1, c->symbol);
	if (c->type == nl + TSTR) {
	    putprintf("s'%s'", 1, c->ptr[0]);
	} else if (c->type == nl + T1CHAR) {
	    putprintf("c%d", 1, c->range[0]);
	} else if (isa(c->type, "i")) {
	    putprintf("i%d", 1, c->range[0]);
	} else if (isa(c->type, "d")) {
	    putprintf("r%g", 1, c->real);
	} else {
	    putprintf("e", 1);
	    gentype(c->type);
	    putprintf(",%d", 1, c->range[0]);
	}
	putprintf("\",0x%x,0,0x%x,0x%x", 0, N_LSYM, 0, 0);
E 15
E 10
I 10
D 16
			, (int) type , N_PC , N_PGTYPE , ABS( line ) );
E 16
E 10
E 3
E 2
    }
I 15
}
E 15

I 15
stabgtype (name, type, line)
char *name;
struct nl *type;
int line;
{
    putprintf("	.stabs	\"%s\",0x%x,0,0x%x,0x%x" ,
	0, name, N_PC , N_PGTYPE, ABS(line)
    );
    if (oldway == 0) {
	stabltype(name, type);
    }
}
E 15

I 15
stabltype (name, type)
char *name;
struct nl *type;
{
    if (opt('g')) {
	putprintf("\t.stabs\t\"%s:t", 1, name);
	gentype(type);
	putprintf("\",0x%x,0,0,0", 0, N_LSYM);
    }
}

E 15
D 2
/* external functions and procedures */	
stabefunc( name , line )
    char *name;
    int line;
E 2
I 2
    /*
     *	external functions and procedures
     */	
D 7
stabefunc( name , class , line )
E 7
I 7
stabefunc( name , typeclass , line )
E 7
    char	*name;
D 7
    int		class;
E 7
I 7
    int		typeclass;
E 7
    int		line;
E 2
    {
I 2
	int	type;
E 2

D 2
	char	*nullchar;
	char	*cp;

	nullchar = name;
	while ( *nullchar ) {
    		nullchar ++;
E 2
I 2
D 7
	if ( class == FUNC ) {
E 7
I 7
	if ( typeclass == FUNC ) {
E 7
D 3
	    type = N_PEFUN;
E 3
I 3
	    type = N_PEFUNC;
E 3
D 7
	} else if ( class == PROC ) {
E 7
I 7
	} else if ( typeclass == PROC ) {
E 7
D 3
	    type = N_PEPRC;
E 3
I 3
	    type = N_PEPROC;
E 3
	} else {
	    return;
E 2
	}
D 2
	for ( cp = name ; cp < nullchar ; cp += SNAMELENGTH ) {
	    putprintf( "	.stabs	\"" , 1 );
	    putprintf( SNAMEFORMAT , 1 , SNAMELENGTH , cp );
    	    putprintf( "\",0%o,0,0,0" , 0 , N_PEFUN , 0 );
	}
	if ( cp == nullchar ) {
    	putprintf( "	.stabn	0%o,0,0,0" , 0 , N_PEFUN, 0 );
	}
E 2
I 2
D 3
	putprintf( "	.stabs	\"" , 1 );
	putprintf( NAMEFORMAT , 1 , name );
	putprintf( "\",0x%x,0,0,0x%x" , 0 , type , ABS( line ) );
E 3
I 3
	putprintf( "	.stabs	\"%s\",0x%x,0,0x%x,0x%x" , 0 
D 10
		    , name , N_PC , type , ABS( line ) );
E 10
I 10
		    , (int) name , N_PC , type , ABS( line ) );
E 10
E 3
E 2
    }
I 15

/*
 * Generate type information encoded as a string for dbx.
 * The fwdptrnum field is used only when the type is a pointer
 * to a type that isn't known when it was entered.  When the
 * type field is filled for some such tptr, fixfwdtype should
 * be called to output an equivalencing type definition.
 */

typedef struct TypeDesc *TypeDesc;

struct TypeDesc {
    struct nl *tptr;
    int tnum;
    int fwdptrnum;
    TypeDesc chain;
};

#define TABLESIZE 2003

#define typehash(t) ( ( ((int) t) >> 2 ) % TABLESIZE )

private int tcount = 1;
private TypeDesc typetable[TABLESIZE];

private TypeDesc tdlookup (t)
struct nl *t;
{
    register TypeDesc td;

    td = typetable[typehash(t)];
    while (td != NIL && td->tptr != t) {
	td = td->chain;
    }
    return td;
}

private int typelookup (t)
struct nl *t;
{
    register TypeDesc td;
    int r;

    td = tdlookup(t);
    if (td == NIL) {
	r = 0;
    } else {
	r = td->tnum;
    }
    return r;
}

private int entertype (type)
struct nl *type;
{
    register TypeDesc td;
    register int i;

    td = (TypeDesc) malloc(sizeof(struct TypeDesc));
    td->tptr = type;
    td->tnum = tcount;
    td->fwdptrnum = 0;
    ++tcount;
    i = typehash(type);
    td->chain = typetable[i];
    typetable[i] = td;
    return td->tnum;
}

/*
 * The in_types table currently contains "boolean", "char", "integer",
 * "real" and "_nil".  (See nl.c for definition.)
 * The lookup call below will give the TYPE class nl entry for these
 * types.  In each case except _nil, the type field of that entry is a RANGE
 * class nl entry for the type.  Sometimes other symbol table entries
 * point to the TYPE entry (e.g., when there is a range over the base type),
 * and other entries point to the RANGE entry (e.g., for a variable of the
 * given type).  We don't really want to distinguish between these uses
 * in dbx, and since it appears that the RANGE entries are not reused if
 * a range happens to coincide, we will give the two the same identifying
 * dbx type number.
 */

private inittypes()
{
    int i;
    extern char *in_types[];
    struct nl *p;

    for (i = 0; in_types[i] != NIL; i++) {
	p = lookup(in_types[i]);
	if (p != NIL) {
	    entertype(p);
	    if (p->type != NIL) {
		--tcount; /* see comment above */
		entertype(p->type);
	    }
	}
    }
}

static genarray (t)
struct nl *t;
{
    register struct nl *p;

D 18
    putprintf("a", 1);
E 18
    for (p = t->chain; p != NIL; p = p->chain) {
I 18
	putprintf("a", 1);
E 18
	gentype(p);
	putprintf(";", 1);
    }
    gentype(t->type);
}

/*
 * Really we should walk through ptr[NL_FIELDLIST] for the fields,
 * and then do the variant tag and fields separately, but dbx
 * doesn't support this yet.
 * So, since all the fields of all the variants are on the chain,
 * we walk through that.  Except that this gives the fields in the
 * reverse order, so we want to print in reverse order.
 */

static genrecord (t)
struct nl *t;
{
    putprintf("s%d", 1, t->value[NL_OFFS]);
    if (t->chain != NIL) {
	genrecfield(t->chain, 1);
    }
    putprintf(";", 1);
}

static genrecfield (t, n)
struct nl *t;
int n;
{
    if (t->chain != NULL) {
	genrecfield(t->chain, n + 1);
	if (n % 2 == 0) {
	    gencontinue();
	}
    }
    putprintf("%s:", 1, t->symbol);
    gentype(t->type);
    putprintf(",%d,%d;", 1, 8*t->value[NL_OFFS], 8*lwidth(t->type));
}

static genvarnt (t)
struct nl *t;
{
    genrecord(t);
}

static genptr (t)
struct nl *t;
{
    register TypeDesc td;
    
    putprintf("*", 1);
    if (t->type != NIL) {
	gentype(t->type);
    } else {
	/*
	 * unresolved forward pointer: use tcount to represent what is
         * begin pointed to, to be defined later
	 */
	td = tdlookup(t);
	if (td == NIL) {
	    panic("nil ptr in stab.genptr");
	}
	td->fwdptrnum = tcount;
	putprintf("%d", 1, tcount);
	++tcount;
    }
}

/*
 * The type t is a pointer which has just had its type field filled.
 * We need to generate a type stab saying that the number saved
 * in t's fwdptrnum is the same as the t->type's number
 */

fixfwdtype (t)
struct nl *t;
{
    register TypeDesc td;
    
    if (opt('g') && oldway == 0) {
	td = tdlookup(t);
	if (td != NIL) {
	    putprintf("\t.stabs\t\":t%d=", 1, td->fwdptrnum);
	    gentype(t->type);
	    putprintf("\",0x%x,0,0,0", 0, N_LSYM);
	}
    }
}

static genenum (t)
struct nl *t;
{
    register struct nl *e;
    register int i;

    putprintf("e", 1);
    i = 1;
    e = t->chain;
    while (e != NULL) {
	if (i > 2) {
	    gencontinue();
	    i = 0;
	}
	putprintf("%s:%d,", 1, e->symbol, e->range[0]);
	e = e->chain;
	++i;
    }
    putprintf(";", 1);
}

static genset (t)
struct nl *t;
{
    putprintf("S", 1);
    gentype(t->type);
}

static genrange (t)
struct nl *t;
{
    putprintf("r", 1);
    gentype(t->type);
    putprintf(";%d;%d", 1, t->range[0], t->range[1]);
}

static genfparam (t)
struct nl *t;
{
    struct nl *p;
    int count;
    
    if (t->type != NULL) {
	putprintf("f", 1);
	gentype(t->type);
	putprintf(",", 1);
    } else {
	putprintf("p", 1);
    }
    count = 0;
    for (p = t->ptr[NL_FCHAIN]; p != NULL; p = p->chain) {
	++count;
    }
    putprintf("%d;", 1, count);
    for (p = t->ptr[NL_FCHAIN]; p != NULL; p = p->chain) {
	gentype(p->type);
	putprintf(",%d;", 1, p->class);
    }
}

static genfile (t)
struct nl *t;
{
    putprintf("d", 1);
    gentype(t->type);
}

static gentype (t)
struct nl *t;
{
    int id;

    if (tcount == 1) {
	inittypes();
    }
    id = typelookup(t);
    if (id != 0) {
	putprintf("%d", 1, id);
    } else if (t->class == SCAL && t->chain == NULL) {
	id = typelookup(t->type);
	if (id != 0) {
	    putprintf("%d", 1, id);
	} else {
	    genenum(t->type);
	}
    } else {
	id = entertype(t);
	putprintf("%d=", 1, id);
	switch (t->class) {
	    case TYPE:
		gentype(t->type);
		break;

	    case ARRAY:
		genarray(t);
		break;

	    case RECORD:
		genrecord(t);
		break;

	    case VARNT:
		genvarnt(t);
		break;

	    case REF:
		gentype(t->type);
		break;

	    case PTR:
		genptr(t);
		break;

	    case SET:
		genset(t);
		break;

	    case RANGE:
		genrange(t);
		break;

	    case SCAL:
		genenum(t);
		break;

	    case FPROC:
	    case FFUNC:
		genfparam(t);
		break;

	    case FILET:
	    case PTRFILE:
		genfile(t);
		break;

	    default:
		/* This shouldn't happen */
		/* Rather than bomb outright, let debugging go on */
		warning();
		error("Bad type class found in stab");
		putprintf("1", 1, t->class);
		break;
	}
    }
}

/*
 * Continue stab information in a namelist new entry.  This is necessary
 * to avoid overflowing putprintf's buffer.
 */

static gencontinue ()
{
    putprintf("?\",0x%x,0,0,0", 0, N_LSYM);
    putprintf("\t.stabs\t\"", 1);
}
E 15

#endif PC
D 2


E 2
E 1
