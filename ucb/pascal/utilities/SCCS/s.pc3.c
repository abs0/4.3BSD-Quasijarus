h23693
s 00014/00003/00878
d D 5.1 85/06/05 16:27:54 dist 14 13
c Add copyright
e
s 00049/00051/00832
d D 1.13 83/07/26 10:01:01 peter 13 12
c using checksums for include files and flag days for source files.
e
s 00004/00003/00879
d D 1.12 83/07/02 00:40:58 sam 12 11
c include fixes
e
s 00000/00001/00882
d D 1.11 83/06/02 17:52:59 sam 11 10
c purge pagsiz.h
e
s 00067/00054/00816
d D 1.10 82/12/06 18:24:53 peter 10 9
c really chain symbol and string tables.
e
s 00081/00007/00789
d D 1.9 82/07/29 19:16:55 peter 9 8
c protect against conflicts with library routines and data.
e
s 00053/00020/00743
d D 1.8 82/07/29 17:05:26 peter 8 7
c add -w flag to suppress warning messages; reclassify some 
c warnings as errors.
e
s 00047/00022/00716
d D 1.7 82/07/26 17:23:17 peter 7 6
c external procedure/function errors use a different error message.
e
s 00001/00001/00737
d D 1.6 80/09/09 15:31:32 peter 6 5
c copied pstab.h to .../pc3 from .../pc0
e
s 00041/00053/00697
d D 1.5 80/09/04 23:12:28 peter 5 4
c N_PC stabs with subtypes
e
s 00001/00001/00749
d D 1.4 80/09/02 15:33:21 peter 4 3
c change program name to pc
e
s 00026/00034/00724
d D 1.3 80/09/02 15:29:17 peter 3 2
c cleaned up checksymbol switch
e
s 00001/00004/00757
d D 1.2 80/09/02 14:11:19 peter 2 1
c make mtime use stat to avoid opening files
e
s 00761/00000/00000
d D 1.1 80/08/31 17:20:04 peter 1 0
c date and time created 80/08/31 17:20:04 by peter
e
u
U
t
T
I 14
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 14
I 12
#ifndef lint
D 14
static	char sccsid[] = "%W% (Berkeley) %G%";
#endif
E 12
I 1
    /* Copyright (c) 1980 Regents of the University of California */
E 14
I 14
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 14

D 12
static	char sccsid[] = "%Z%%M% %I% %G%";

E 12
    /*
     *	     Pc3 is a pass in the Berkeley Pascal compilation
     *	process that is performed just prior to linking Pascal
     *	object files.  Its purpose is to enforce the rules of
     *	separate compilation for Berkeley Pascal.  Pc3 is called
     *	with the same argument list of object files that is sent to
     *	the loader.  These checks are performed by pc3 by examining
     *	the symbol tables of the object files:
D 13
     *	(1)  All source and included files must be "up-to-date" with
     *	     the object files of which they are components.
E 13
I 13
     *	(1)  All .o files must be up to date with respect to the
     *	     runtime libraries.
E 13
     *	(2)  Each global Pascal symbol (label, constant, type,
     *	     variable, procedure, or function name) must be uniquely
     *	     declared, i.e. declared in only one included file or
     *	     source file.
     *	(3)  Each external function (or procedure) may be resolved
     *	     at most once in a source file which included the
     *	     external declaration of the function.
     *	
     *	     The symbol table of each object file is scanned and
     *	each global Pascal symbol is placed in a hashed symbol
     *	table.  The Pascal compiler has been modified to emit all
     *	Pascal global symbols to the object file symbol table.  The
     *	information stored in the symbol table for each such symbol
     *	is:
     *	
     *	   - the name of the symbol;
D 5
     *	   - a type specifier;
E 5
I 5
     *	   - a subtype descriptor;
E 5
D 13
     *	   - for file symbols, their last modify time;
E 13
     *	   - the file which logically contains the declaration of
D 13
     *	     the symbol (not an include file);
     *	   - the file which textually contains the declaration of
     *	     the symbol (possibly an include file);
     *	   - the line number at which the symbol is declared;
     *	   - the file which contains the resolution of the symbol.
     *	   - the line number at which the symbol is resolved;
E 13
I 13
     *	     the symbol or which caused the inclusion of an include file.
     *	   - for included files:
     *		- a checksum;
     *	   - for symbols:
     *	   	- the file which textually contains the declaration of
     *	   	  the symbol (possibly an include file);
     *	   	- the line number at which the symbol is declared;
     *	   	- the file which contains the resolution of the symbol.
     *	   	- the line number at which the symbol is resolved;
E 13
     *	
     *	     If a symbol has been previously entered into the symbol
     *	table, a check is made that the current declaration is of
     *	the same type and from the same include file as the previous
     *	one.  Except for files and functions and procedures, it is
     *	an error for a symbol declaration to be encountered more
     *	than once, unless the re-declarations come from the same
     *	included file as the original.
     *	
     *	     As an include file symbol is encountered in a source
     *	file, the symbol table entry of each symbol declared in that
     *	include file is modified to reflect its new logical
     *	inclusion in the source file.  File symbols are also
     *	encountered as an included file ends, signaling the
     *	continuation of the enclosing file.
     *	
     *	     Functions and procedures which have been declared
     *	external may be resolved by declarations from source files
     *	which included the external declaration of the function.
     *	Functions and procedures may be resolved at most once across
     *	a set of object files.  The loader will complain if a
     *	function is not resolved at least once.
     */

D 4
char	program[] = "pc3";
E 4
I 4
char	program[] = "pc";
E 4

#include <sys/types.h>
I 12
#include <sys/stat.h>
E 12
#include <ar.h>
#include <stdio.h>
#include <ctype.h>
#include <a.out.h>
#include <stab.h>
D 11
#include <pagsiz.h>
E 11
D 12
#include <stat.h>
E 12
D 5
#include "/usr/src/new/pc0/p.a.out.h"
E 5
I 5
D 6
#include "/usr/src/new/pc0/pstab.h"
E 6
I 6
#include "pstab.h"
E 6
E 5
#include "pc3.h"

D 8
int	errors = 0;
E 8
I 8
int	errors = NONE;
BOOL	wflag = FALSE;	
E 8

    /*
     *	check each of the argument .o files (or archives of .o files).
     */
main( argc , argv )
    int		argc;
    char	**argv;
    {
	struct fileinfo	ofile;

D 3
	argc--;
	argv++;
	while ( argc-- ) {
E 3
I 3
D 8
	while ( ++argv , --argc ) {
E 8
I 8
	for ( argv++ ; *argv != 0 && **argv == '-' ; argv++ ) {
	    (*argv)++;
	    switch ( **argv ) {
		default:
		    error( FATAL , "pc3: bad flag -%c\n" , **argv );
		case 'w':
		    wflag = TRUE;
		    break;
	    }
	}
	for ( /* void */ ; *argv != 0 ; argv++ ) {
E 8
E 3
#	    ifdef DEBUG
		fprintf( stderr , "[main] *argv = %s\n" , *argv );
#	    endif DEBUG
	    ofile.name = *argv;
	    checkfile( &ofile );
D 3
	    argv++;
E 3
	}
	exit( errors );
    }

    /*
     *	check the namelist of a file, or all namelists of an archive.
     */
checkfile( ofilep )
    struct fileinfo	*ofilep;
    {
	union {
	    char	mag_armag[ SARMAG + 1 ];
	    struct exec	mag_exec;
	}		mag_un;
	int		red;
	struct stat	filestat;

	ofilep -> file = fopen( ofilep -> name , "r" );
	if ( ofilep -> file == NULL ) {
D 8
	    error( WARNING , "cannot open: %s" , ofilep -> name );
E 8
I 8
	    error( ERROR , "cannot open: %s" , ofilep -> name );
E 8
	    return;
	}
	fstat( fileno( ofilep -> file ) , &filestat );
D 13
	ofilep -> modtime = filestat.st_mtime;
E 13
	red = fread( (char *) &mag_un , 1 , sizeof mag_un , ofilep -> file );
	if ( red != sizeof mag_un ) {
D 8
	    error( WARNING , "cannot read header: %s" , ofilep -> name );
E 8
I 8
	    error( ERROR , "cannot read header: %s" , ofilep -> name );
E 8
	    return;
	}
	if ( mag_un.mag_exec.a_magic == OARMAG ) {
	    error( WARNING , "old archive: %s" , ofilep -> name );
	    return;
	}
	if ( strncmp( mag_un.mag_armag , ARMAG , SARMAG ) == 0 ) {
		/* archive, iterate through elements */
#	    ifdef DEBUG
		fprintf( stderr , "[checkfile] archive %s\n" , ofilep -> name );
#	    endif DEBUG
	    ofilep -> nextoffset = SARMAG;
	    while ( nextelement( ofilep ) ) {
		checknl( ofilep );
	    }
	} else if ( N_BADMAG( mag_un.mag_exec ) ) {
		/* not a file.o */
D 8
	    error( WARNING , "bad format: %s" , ofilep -> name );
E 8
I 8
	    error( ERROR , "bad format: %s" , ofilep -> name );
E 8
	    return;
	} else {
		/* a file.o */
#	    ifdef DEBUG
		fprintf( stderr , "[checkfile] .o file %s\n" , ofilep -> name );
#	    endif DEBUG
	    fseek( ofilep -> file , 0L , 0 );
	    ofilep -> nextoffset = filestat.st_size;
	    checknl( ofilep );
	}
	fclose( ofilep -> file );
    }

    /*
     *	check the namelist of this file for conflicts with
     *	previously entered symbols.
     */
checknl( ofilep )
    register struct fileinfo	*ofilep;
    {
    
	long			red;
D 3
	struct exec		aexec;
E 3
I 3
	struct exec		oexec;
E 3
	off_t			symoff;
	long			numsyms;
	register struct nlist	*nlp;
	register char		*stringp;
	long			strsize;
	long			sym;

D 3
	red = fread( (char *) &aexec , 1 , sizeof aexec , ofilep -> file );
	if ( red != sizeof aexec ) {
E 3
I 3
	red = fread( (char *) &oexec , 1 , sizeof oexec , ofilep -> file );
	if ( red != sizeof oexec ) {
E 3
D 8
	    error( WARNING , "error reading struct exec: %s"
E 8
I 8
	    error( ERROR , "error reading struct exec: %s"
E 8
		    , ofilep -> name );
	    return;
	}
D 3
	if ( N_BADMAG( aexec ) ) {
E 3
I 3
	if ( N_BADMAG( oexec ) ) {
E 3
	    return;
	}
D 3
	symoff = N_SYMOFF( aexec ) - sizeof aexec;
E 3
I 3
	symoff = N_SYMOFF( oexec ) - sizeof oexec;
E 3
	fseek( ofilep -> file , symoff , 1 );
D 3
	numsyms = aexec.a_syms / sizeof ( struct nlist );
E 3
I 3
	numsyms = oexec.a_syms / sizeof ( struct nlist );
E 3
	if ( numsyms == 0 ) {
	    error( WARNING , "no name list: %s" , ofilep -> name );
	    return;
	}
	nlp = (struct nlist *) calloc( numsyms , sizeof ( struct nlist ) );
	if ( nlp == 0 ) {
	    error( FATAL , "no room for %d nlists" , numsyms );
	}
	red = fread( ( char * ) nlp , numsyms , sizeof ( struct nlist )
		    , ofilep -> file );
	if (   ftell( ofilep -> file ) + sizeof ( off_t )
	    >= ofilep -> nextoffset ) {
	    error( WARNING , "no string table (old format .o?)"
		    , ofilep -> name );
	    return;
	}
	red = fread( (char *) &strsize , sizeof strsize , 1
		    , ofilep -> file );
	if ( red != 1 ) {
	    error( WARNING , "no string table (old format .o?)"
		    , ofilep -> name );
	    return;
	}
	stringp  = ( char * ) malloc( strsize );
	if ( stringp == 0 ) {
	    error( FATAL , "no room for %d bytes of strings" , strsize );
	}
	red = fread( stringp + sizeof strsize
		    , strsize - sizeof ( strsize ) , 1 , ofilep -> file );
	if ( red != 1 ) {
	    error( WARNING , "error reading string table: %s"
		    , ofilep -> name );
	}
#	ifdef DEBUG
	    fprintf( stderr , "[checknl] %s: %d symbols\n"
		    , ofilep -> name , numsyms );
#	endif DEBUG
	for ( sym = 0 ; sym < numsyms ; sym++) {
	    if ( nlp[ sym ].n_un.n_strx ) {
		nlp[ sym ].n_un.n_name = stringp + nlp[ sym ].n_un.n_strx;
	    } else {
		nlp[ sym ].n_un.n_name = "";
	    }
	    checksymbol( &nlp[ sym ] , ofilep );
	}
	if ( nlp ) {
	    free( nlp );
	}
	if ( stringp ) {
	    free( stringp );
	}
    }

    /*
     *	check a symbol.
     *	look it up in the hashed symbol table,
     *	entering it if necessary.
     *	this maintains a state of which .p and .i files
     *	it is currently in the midst from the nlist entries
     *	for source and included files.
     *	if we are inside a .p but not a .i, pfilep == ifilep.
     */
checksymbol( nlp , ofilep )
    struct nlist	*nlp;
    struct fileinfo	*ofilep;
    {
	static struct symbol	*pfilep = NIL;
	static struct symbol	*ifilep = NIL;
	register struct symbol	*symbolp;
I 9
	int			errtype;
E 9

#	ifdef DEBUG
	    if ( pfilep && ifilep ) {
		fprintf( stderr , "[checksymbol] pfile %s ifile %s\n"
			, pfilep -> name , ifilep -> name );
	    }
D 5
	    fprintf( stderr , "[checksymbol] ->name %s ->n_type %x (%s)\n"
		    , nlp -> n_un.n_name , nlp -> n_type
		    , classify( nlp -> n_type ) );
E 5
I 5
	    fprintf( stderr , "[checksymbol] ->name %s ->n_desc %x (%s)\n"
		    , nlp -> n_un.n_name , nlp -> n_desc
		    , classify( nlp -> n_desc ) );
E 5
#	endif DEBUG
D 5
	switch ( nlp -> n_type ) {
	    case N_PGLAB:
	    case N_PGCON:
	    case N_PGTYP:
	    case N_PGVAR:
	    case N_PGFUN:
	    case N_PGPRC:
	    case N_PEFUN:
	    case N_PEPRC:
	    case N_PSO:
	    case N_PSOL:
		    symbolp = entersymbol( nlp -> n_un.n_name );
		    break;
	    default:
			/* don't care about the others */
		    return;
E 5
I 5
	if ( nlp -> n_type != N_PC ) {
		/* don't care about the others */
	    return;
E 5
	}
I 5
	symbolp = entersymbol( nlp -> n_un.n_name );
E 5
	if ( symbolp -> lookup == NEW ) {
#	    ifdef DEBUG
		fprintf( stderr , "[checksymbol] ->name %s is NEW\n"
			, symbolp -> name );
#	    endif DEBUG
D 5
	    symbolp -> type = nlp -> n_type;
	    switch ( symbolp -> type ) {
		case N_PGLAB:
		case N_PGCON:
		case N_PGTYP:
E 5
I 5
	    symbolp -> desc = nlp -> n_desc;
I 13
	    symbolp -> fromp = pfilep;
E 13
	    switch ( symbolp -> desc ) {
I 7
		default:
			error( FATAL , "panic: [checksymbol] NEW" );
E 7
		case N_PGLABEL:
		case N_PGCONST:
		case N_PGTYPE:
E 5
		case N_PGVAR:
D 5
		case N_PGFUN:
		case N_PGPRC:
E 5
I 5
		case N_PGFUNC:
		case N_PGPROC:
I 9
		case N_PLDATA:
		case N_PLTEXT:
E 9
E 5
D 3
			/* and fall through */
E 3
I 3
			symbolp -> sym_un.sym_str.rfilep = ifilep;
			symbolp -> sym_un.sym_str.rline = nlp -> n_value;
D 13
			symbolp -> sym_un.sym_str.fromp = pfilep;
E 13
			symbolp -> sym_un.sym_str.fromi = ifilep;
			symbolp -> sym_un.sym_str.iline = nlp -> n_value;
			return;
E 3
D 5
		case N_PEFUN:
		case N_PEPRC:
E 5
I 5
		case N_PEFUNC:
		case N_PEPROC:
E 5
I 3
			symbolp -> sym_un.sym_str.rfilep = NIL;
			symbolp -> sym_un.sym_str.rline = 0;
			    /*
			     *	functions can only be declared external
			     *	in included files.
			     */
			if ( pfilep == ifilep ) {
			    error( WARNING
				    , "%s, line %d: %s %s must be declared in included file"
				    , pfilep -> name , nlp -> n_value
D 5
				    , classify( symbolp -> type )
E 5
I 5
				    , classify( symbolp -> desc )
E 5
				    , symbolp -> name );
			}
E 3
D 13
			symbolp -> sym_un.sym_str.fromp = pfilep;
E 13
			symbolp -> sym_un.sym_str.fromi = ifilep;
			symbolp -> sym_un.sym_str.iline = nlp -> n_value;
D 3
			if (  symbolp -> type != N_PEFUN
			   && symbolp -> type != N_PEPRC ) {
			    symbolp -> sym_un.sym_str.rfilep = ifilep;
			    symbolp -> sym_un.sym_str.rline = nlp -> n_value;
			} else {
			    symbolp -> sym_un.sym_str.rfilep = NIL;
			    symbolp -> sym_un.sym_str.rline = 0;
				/*
				 *	functions can only be declared external
				 *	in included files.
				 */
			    if ( pfilep == ifilep ) {
				error( WARNING
					, "%s, line %d: %s %s must be declared in included file"
					, pfilep -> name , nlp -> n_value
					, classify( symbolp -> type )
					, symbolp -> name );
			    }
			}
E 3
			return;
		case N_PSO:
I 13
			if ( nlp -> n_value < N_FLAGCHECKSUM ) {
			    error( WARNING,
				"%s is out of date and should be recompiled",
				ofilep -> name );
			}
E 13
			pfilep = symbolp;
D 13
			/* and fall through */
E 13
I 13
			ifilep = symbolp;
			symbolp -> sym_un.checksum = N_FLAGCHECKSUM;
			return;
E 13
		case N_PSOL:
			ifilep = symbolp;
D 13
			symbolp -> sym_un.modtime = mtime( symbolp -> name );
			if ( symbolp -> sym_un.modtime > ofilep -> modtime ) {
			    error( WARNING , "%s is out of date with %s"
				    , ofilep -> name , symbolp -> name );
			}
E 13
I 13
			symbolp -> sym_un.checksum = nlp -> n_value;
E 13
			return;
	    }
	} else {
#	    ifdef DEBUG
		fprintf( stderr , "[checksymbol] ->name %s is OLD\n"
			, symbolp -> name );
#	    endif DEBUG
I 9
	    errtype = ERROR;
E 9
D 5
	    switch ( symbolp -> type ) {
E 5
I 5
	    switch ( symbolp -> desc ) {
I 7
		default:
			error( FATAL , "panic [checksymbol] OLD" );
I 13
			return;
E 13
E 7
E 5
		case N_PSO:
			    /*
			     *	finding a file again means you are back
			     *	in it after finishing an include file.
			     */
I 13
			if ( symbolp -> desc != nlp -> n_desc ) {
			    error( FATAL , "panic [checksymbol] PSO" );
			    return;
			}
E 13
			pfilep = symbolp;
D 13
			/* and fall through */
E 13
I 13
			ifilep = symbolp;
			return;
E 13
		case N_PSOL:
			    /*
			     *	include files can be seen more than once,
D 13
			     *	but they still have to be timechecked.
			     *	(this will complain twice for out of date
			     *	include files which include other files.
			     *	sigh.)
E 13
I 13
			     *	but their checksums are checked if they are
			     *	greater than N_FLAGCHECKSUM.
			     *	PSOL's are seen with checksums as the
			     *	include file is entered, and with
			     *	N_FLAGCHECKSUM as we are back in an
			     *	included file from a nested include.
E 13
			     */
D 13
			ifilep = symbolp;
			if ( symbolp -> sym_un.modtime > ofilep -> modtime ) {
			    error( WARNING , "%s is out of date with %s"
				    , ofilep -> name , symbolp -> name );
E 13
I 13
			if ( symbolp -> desc != nlp -> n_desc ) {
			    error( FATAL , "panic [checksymbol] PSOL" );
			    return;
E 13
			}
I 13
			if ((unsigned) symbolp->sym_un.checksum > N_FLAGCHECKSUM
			   && (unsigned) nlp -> n_value > N_FLAGCHECKSUM
			   && symbolp -> sym_un.checksum != nlp -> n_value ) {
			    error( ERROR,
			    "%s included in %s differs from %s included in %s",
				symbolp -> name, pfilep -> name,
				symbolp -> name, symbolp -> fromp -> name );
			}
			ifilep = symbolp;
E 13
			return;
D 5
		case N_PEFUN:
		case N_PEPRC:
E 5
I 5
		case N_PEFUNC:
		case N_PEPROC:
E 5
			    /*
D 7
			     *	we may see any number of external declarations,
			     *	but they all have to come
			     *	from the same include file.
E 7
I 7
			     *	this might be the resolution of the external
			     *	has to match func/proc of external
			     *	and has to have included external
			     *	and has to not have been previously resolved.
E 7
			     */
D 5
			if (   nlp -> n_type == N_PEFUN
			    || nlp -> n_type == N_PEPRC ) {
E 5
I 5
D 7
			if (   nlp -> n_desc == N_PEFUNC
			    || nlp -> n_desc == N_PEPROC ) {
E 5
			    goto included;
E 7
I 7
			if (  (  ( symbolp -> desc == N_PEFUNC
			         && nlp -> n_desc == N_PGFUNC )
			      || ( symbolp -> desc == N_PEPROC
				 && nlp -> n_desc == N_PGPROC ) )
D 13
			   && ( symbolp -> sym_un.sym_str.fromp == pfilep )
E 13
I 13
			   && ( symbolp -> fromp == pfilep )
E 13
			   && ( symbolp -> sym_un.sym_str.rfilep == NIL ) ) {
				/*
				 *	resolve external
				 */
#			    ifdef DEBUG
				fprintf( stderr , "[checksymbol] resolving external\n" );
#			    endif DEBUG
			    symbolp -> sym_un.sym_str.rfilep = ifilep;
			    symbolp -> sym_un.sym_str.rline = nlp -> n_value;
			    return;
E 7
			}
			    /*
D 7
			     *	an external function can be resolved by
			     *	the resolution of the function
			     *	if the resolving file
			     *	included the external declaration.
E 7
I 7
			     *	otherwise, it might be another external,
			     *	which is okay if it's
			     *	the same type and from the same include file
E 7
			     */
D 5
			if (    (  symbolp -> type == N_PEFUN
				&& nlp -> n_type != N_PGFUN )
			    ||  (  symbolp -> type == N_PEPRC
				&& nlp -> n_type != N_PGPRC )
E 5
I 5
D 7
			if (    (  symbolp -> desc == N_PEFUNC
				&& nlp -> n_desc != N_PGFUNC )
			    ||  (  symbolp -> desc == N_PEPROC
				&& nlp -> n_desc != N_PGPROC )
E 5
			    || symbolp -> sym_un.sym_str.fromp != pfilep ) {
			    break;
E 7
I 7
			if (  (  ( symbolp -> desc == N_PEFUNC
			         && nlp -> n_desc == N_PEFUNC )
			      || ( symbolp -> desc == N_PEPROC
				 && nlp -> n_desc == N_PEPROC ) )
			   && ( symbolp -> sym_un.sym_str.fromi == ifilep ) ) {
				/*
				 *	just another pretty external
				 *	make it look like it comes from here.
				 */
#			    ifdef DEBUG
				fprintf( stderr , "[checksymbol] just another pretty external\n" );
#			    endif DEBUG
D 13
			    symbolp -> sym_un.sym_str.fromp = pfilep;
E 13
I 13
			    symbolp -> fromp = pfilep;
E 13
			    return;
E 7
			}
			    /*
D 7
			     *	an external function can only be resolved once.
E 7
I 7
			     *	something is wrong
I 8
			     *	if it's not resolved, use the header file
			     *	otherwise, it's just a regular error
E 8
E 7
			     */
D 7
			if ( symbolp -> sym_un.sym_str.rfilep != NIL ) {
			    break;
			}
			symbolp -> sym_un.sym_str.rfilep = ifilep;
			symbolp -> sym_un.sym_str.rline = nlp -> n_value;
E 7
I 7
D 8
			error( WARNING ,
E 8
I 8
			if ( symbolp -> sym_un.sym_str.rfilep == NIL ) {
			    error( ERROR ,
E 8
D 9
			    "%s, line %d: %s already defined (%s, line %d)." ,
E 9
I 9
		    "%s, line %d: %s is already defined\n\t(%s, line %d)." ,
E 9
D 8
			    ifilep -> name , nlp -> n_value , 
			    nlp -> n_un.n_name , 
			    symbolp -> sym_un.sym_str.fromi -> name ,
			    symbolp -> sym_un.sym_str.iline );
E 7
			return;
E 8
I 8
				ifilep -> name , nlp -> n_value , 
				nlp -> n_un.n_name , 
				symbolp -> sym_un.sym_str.fromi -> name ,
				symbolp -> sym_un.sym_str.iline );
			    return;
			}
			break;
E 8
D 5
		case N_PGFUN:
		case N_PGPRC:
E 5
I 5
		case N_PGFUNC:
		case N_PGPROC:
E 5
			    /*
			     *	functions may not be seen more than once.
			     *	the loader will complain about
			     *	`multiply defined', but we can, too.
			     */
			break;
D 5
		case N_PGLAB:
		case N_PGCON:
		case N_PGTYP:
E 5
I 5
		case N_PGLABEL:
		case N_PGCONST:
		case N_PGTYPE:
E 5
		case N_PGVAR:
			    /*
			     *	labels, constants, types, variables
			     *	and external declarations
			     *	may be seen as many times as they want,
			     *	as long as they come from the same include file.
			     *	make it look like they come from this .p file.
			     */
included:
D 5
			if (  nlp -> n_type != symbolp -> type
E 5
I 5
			if (  nlp -> n_desc != symbolp -> desc
E 5
			   || symbolp -> sym_un.sym_str.fromi != ifilep ) {
			    break;
			}
D 13
			symbolp -> sym_un.sym_str.fromp = pfilep;
E 13
I 13
			symbolp -> fromp = pfilep;
E 13
			return;
I 9
		case N_PLDATA:
		case N_PLTEXT:
			switch ( nlp -> n_desc ) {
			    default:
				error( FATAL , "pc3: unknown stab 0x%x"
					, nlp -> n_desc );
				return;
			    case N_PSO:
			    case N_PSOL:
			    case N_PGCONST:
			    case N_PGTYPE:
				/* these won't conflict with library */
				return;
			    case N_PGLABEL:
			    case N_PGVAR:
			    case N_PGFUNC:
			    case N_PGPROC:
			    case N_PEFUNC:
			    case N_PEPROC:
			    case N_PLDATA:
			    case N_PLTEXT:
				errtype = WARNING;
				break;
			}
			break;
E 9
	    }
		/*
		 *	this is the breaks
		 */
D 8
	    error( WARNING , "%s, line %d: %s already defined (%s, line %d)."
E 8
I 8
D 9
	    error( ERROR , "%s, line %d: %s already defined (%s, line %d)."
E 8
		    , ifilep -> name , nlp -> n_value , nlp -> n_un.n_name
		    , symbolp -> sym_un.sym_str.rfilep -> name
		    , symbolp -> sym_un.sym_str.rline );
E 9
I 9
	    error( errtype
		, "%s, line %d: %s %s is already defined\n\t%s%s (%s, line %d)."
		, ifilep -> name
		, nlp -> n_value
		, classify( nlp -> n_desc )
		, nlp -> n_un.n_name
		, ( symbolp -> desc == nlp -> n_desc ? "" : " as " )
		, ( symbolp -> desc == nlp -> n_desc
			? "" : article( symbolp -> desc ) )
		, symbolp -> sym_un.sym_str.rfilep -> name
		, symbolp -> sym_un.sym_str.rline );
E 9
	}
    }

    /*
     *	quadratically hashed symbol table.
     *	things are never deleted from the hash symbol table.
     *	as more hash table is needed,
     *	a new one is alloc'ed and chained to the end.
     *	search is by rehashing within each table,
     *	traversing chains to next table if unsuccessful.
     */
D 3

E 3
struct symbol *
entersymbol( name )
    char	*name;
    {
D 10
	static struct symboltableinfo	*symboltable = NIL;
E 10
I 10
	static struct symboltableinfo	symboltable;
E 10
	char				*enteredname;
	long				hashindex;
	register struct symboltableinfo	*tablep;
	register struct symbol		**herep;
	register struct symbol		**limitp;
	register long			increment;

	enteredname = enterstring( name );
	hashindex = SHORT_ABS( ( long ) enteredname ) % SYMBOLPRIME;
D 10
	for ( tablep = symboltable ; /*return*/ ; tablep = tablep -> chain ) {
E 10
I 10
	for ( tablep = &symboltable ; /*return*/ ; tablep = tablep -> chain ) {
E 10
	    if ( tablep == NIL ) {
D 10
#		ifdef DEBUG
		    fprintf( stderr , "[entersymbol] calloc\n" );
#		endif DEBUG
		tablep = ( struct symboltableinfo * )
			    calloc( sizeof ( struct symboltableinfo ) , 1 );
		if ( tablep == NIL ) {
E 10
I 10
#		ifdef SPACEDEBUG
		    fprintf( stderr ,
			    "[entersymbol] calloc'ing table for %d symbols\n" , 
			    SYMBOLPRIME );
#		endif SPACEDEBUG
		for ( tablep = &symboltable
		    ; tablep->chain != NIL
		    ; tablep = tablep->chain ) {
			continue;
		}
		tablep->chain = ( struct symboltableinfo * )
			    calloc( 1 , sizeof ( struct symboltableinfo ) );
		if ( tablep->chain == NIL ) {
E 10
		    error( FATAL , "ran out of memory (entersymbol)" );
		}
D 10
		if ( symboltable == NIL ) {
		    symboltable = tablep;
		}
E 10
I 10
		tablep = tablep->chain;
E 10
	    }
	    herep = &( tablep -> entry[ hashindex ] );
	    limitp = &( tablep -> entry[ SYMBOLPRIME ] );
	    increment = 1;
	    do {
D 10
#		ifdef DEBUG
		    fprintf( stderr , "[entersymbol] increment %d\n" 
			    , increment );
#		endif DEBUG
E 10
		if ( *herep == NIL ) {
			/* empty */
D 10
		    if ( tablep -> used > ( ( SYMBOLPRIME / 3 ) * 4 ) ) {
E 10
I 10
		    if ( tablep -> used > ( ( SYMBOLPRIME / 4 ) * 3 ) ) {
E 10
			    /* too full, break for next table */
			break;
		    }
		    tablep -> used++;
		    *herep = symbolalloc();
		    ( *herep ) -> name = enteredname;
		    ( *herep ) -> lookup = NEW;
D 10
#		    ifdef DEBUG
			fprintf( stderr , "[entersymbol] name %s NEW\n"
				, enteredname );
#		    endif DEBUG
E 10
I 10
#		    ifdef HASHDEBUG
			fprintf( stderr ,
				"[entersymbol] name %s NEW after %d\n" ,
				enteredname , increment / 2 );
#		    endif HASHDEBUG
E 10
		    return *herep;
		}
		    /* a find? */
		if ( ( *herep ) -> name == enteredname ) {
		    ( *herep ) -> lookup = OLD;
D 10
#		    ifdef DEBUG
			fprintf( stderr , "[entersymbol] name %s OLD\n"
				, enteredname );
#		    endif DEBUG
E 10
I 10
#		    ifdef HASHDEBUG
			fprintf( stderr , "[entersymbol] name %s OLD at %d\n" ,
				enteredname , increment / 2 );
#		    endif HASHDEBUG
E 10
		    return *herep;
		}
		herep += increment;
		if ( herep >= limitp ) {
		    herep -= SYMBOLPRIME;
		}
		increment += 2;
	    } while ( increment < SYMBOLPRIME );
I 10
#	    ifdef HASHDEBUG
		fprintf( stderr , "[entersymbol] next symboltable\n" );
#	    endif HASHDEBUG
E 10
	}
    }

    /*
     *	allocate a symbol from the dynamically allocated symbol table.
     */
D 3

E 3
struct symbol *
symbolalloc()
    {
	static struct symbol	*nextsymbol = NIL;
	static long		symbolsleft = 0;
	struct symbol		*newsymbol;

	if ( symbolsleft <= 0 ) {
D 10
#	    ifdef DEBUG
		fprintf( stderr , "[symbolalloc] malloc\n" );
#	    endif DEBUG
E 10
I 10
#	    ifdef SPACEDEBUG
		fprintf( stderr ,
			"[symbolalloc] malloc space for %d symbols\n" ,
			SYMBOLALLOC / sizeof( struct symbol ) );
#	    endif SPACEDEBUG
E 10
	    nextsymbol = ( struct symbol * ) malloc( SYMBOLALLOC );
	    if ( nextsymbol == 0 ) {
		error( FATAL , "ran out of memory (symbolalloc)" );
	    }
	    symbolsleft = SYMBOLALLOC / sizeof( struct symbol );
	}
	newsymbol = nextsymbol;
	nextsymbol++;
	symbolsleft--;
	return newsymbol;
    }

    /*
     *	hash a string based on all of its characters.
     */
long
hashstring( string )
    char	*string;
    {
	register char	*cp;
	register long	value;

	value = 0;
	for ( cp = string ; *cp ; cp++ ) {
	    value = ( value * 2 ) + *cp;
	}
	return value;
    }

    /*
     *	quadratically hashed string table.
     *	things are never deleted from the hash string table.
     *	as more hash table is needed,
     *	a new one is alloc'ed and chained to the end.
     *	search is by rehashing within each table,
     *	traversing chains to next table if unsuccessful.
     */
D 3

E 3
char *
enterstring( string )
    char	*string;
    {
D 10
	static struct stringtableinfo	*stringtable = NIL;
E 10
I 10
	static struct stringtableinfo	stringtable;
E 10
	long				hashindex;
	register struct stringtableinfo	*tablep;
	register char			**herep;
	register char			**limitp;
	register long			increment;

	hashindex = SHORT_ABS( hashstring( string ) ) % STRINGPRIME;
D 10
	for ( tablep = stringtable ; /*return*/ ; tablep = tablep -> chain ) {
E 10
I 10
	for ( tablep = &stringtable ; /*return*/ ; tablep = tablep -> chain ) {
E 10
	    if ( tablep == NIL ) {
D 10
#		ifdef DEBUG
		    fprintf( stderr , "[enterstring] calloc\n" );
#		endif DEBUG
		tablep = ( struct stringtableinfo * )
			    calloc( sizeof ( struct stringtableinfo ) , 1 );
		if ( tablep == NIL ) {
E 10
I 10
#		ifdef SPACEDEBUG
		    fprintf( stderr ,
			    "[enterstring] calloc space for %d strings\n" ,
			    STRINGPRIME );
#		endif SPACEDEBUG
		for ( tablep = &stringtable
		    ; tablep->chain != NIL
		    ; tablep = tablep->chain ) {
			continue;
		}
		tablep->chain = ( struct stringtableinfo * )
			    calloc( 1 , sizeof ( struct stringtableinfo ) );
		if ( tablep->chain == NIL ) {
E 10
		    error( FATAL , "ran out of memory (enterstring)" );
		}
D 10
		if ( stringtable == NIL ) {
		    stringtable = tablep;
		}
E 10
I 10
		tablep = tablep->chain;
E 10
	    }
	    herep = &( tablep -> entry[ hashindex ] );
	    limitp = &( tablep -> entry[ STRINGPRIME ] );
	    increment = 1;
	    do {
D 10
#		ifdef DEBUG
		    fprintf( stderr , "[enterstring] increment %d\n" 
			    , increment );
#		endif DEBUG
E 10
		if ( *herep == NIL ) {
			/* empty */
D 10
		    if ( tablep -> used > ( ( STRINGPRIME / 3 ) * 4 ) ) {
E 10
I 10
		    if ( tablep -> used > ( ( STRINGPRIME / 4 ) * 3 ) ) {
E 10
			    /* too full, break for next table */
			break;
		    }
		    tablep -> used++;
		    *herep = charalloc( strlen( string ) );
		    strcpy( *herep , string );
D 10
#		    ifdef DEBUG
			fprintf( stderr , "[enterstring] string %s copied\n"
				, *herep );
#		    endif DEBUG
E 10
I 10
#		    ifdef HASHDEBUG
			fprintf( stderr ,
				"[enterstring] string %s copied after %d\n" , 
				*herep , increment / 2 );
#		    endif HASHDEBUG
E 10
		    return *herep;
		}
		    /* quick, check the first chars and then the rest */
		if ( **herep == *string && strcmp( *herep , string ) == 0 ) {
D 10
#		    ifdef DEBUG
			fprintf( stderr , "[enterstring] string %s found\n"
				, *herep );
#		    endif DEBUG
E 10
I 10
#		    ifdef HASHDEBUG
			fprintf( stderr ,
				"[enterstring] string %s found after %d\n" ,
				*herep , increment / 2 );
#		    endif HASHDEBUG
E 10
		    return *herep;
		}
		herep += increment;
		if ( herep >= limitp ) {
		    herep -= STRINGPRIME;
		}
		increment += 2;
	    } while ( increment < STRINGPRIME );
I 10
#	    ifdef HASHDEBUG
		fprintf( stderr , "[enterstring] next stringtable\n" );
#	    endif HASHDEBUG
E 10
	}
    }

    /*
     *	copy a string to the dynamically allocated character table.
     */
D 3

E 3
char *
charalloc( length )
    register long	length;
    {
	static char	*nextchar = NIL;
	static long	charsleft = 0;
	register long	lengthplus1 = length + 1;
	register long	askfor;
	char		*newstring;

	if ( charsleft < lengthplus1 ) {
	    askfor = lengthplus1 > CHARALLOC ? lengthplus1 : CHARALLOC;
D 10
#	    ifdef DEBUG
		fprintf( stderr , "[charalloc] malloc( %d )\n" 
E 10
I 10
#	    ifdef SPACEDEBUG
		fprintf( stderr , "[charalloc] malloc space for %d chars\n" 
E 10
			, askfor );
D 10
#	    endif DEBUG
E 10
I 10
#	    endif SPACEDEBUG
E 10
	    nextchar = ( char * ) malloc( askfor );
	    if ( nextchar == 0 ) {
		error( FATAL , "no room for %d characters" , askfor );
	    }
	    charsleft = askfor;
	}
	newstring = nextchar;
	nextchar += lengthplus1;
	charsleft -= lengthplus1;
	return newstring;
    }

    /*
     *	read an archive header for the next element
     *	and find the offset of the one after this. 
     */
BOOL
nextelement( ofilep )
    struct fileinfo	*ofilep;
    {
	register char	*cp;
	register long	red;
	register off_t	arsize;
	struct ar_hdr	archdr;

	fseek( ofilep -> file , ofilep -> nextoffset , 0 );
	red = fread( (char *) &archdr , 1 , sizeof archdr , ofilep -> file );
	if ( red != sizeof archdr ) {
	    return FALSE;
	}
	    /* null terminate the blank-padded name */
	cp = &archdr.ar_name[ ( sizeof archdr.ar_name ) - 1 ];
	*cp = '\0';
	while ( *--cp == ' ' ) {
	    *cp = '\0';
	}
	    /* set up the address of the beginning of next element */
	arsize = atol( archdr.ar_size );
	    /* archive elements are aligned on 0 mod 2 boundaries */
	if ( arsize & 1 ) {
	    arsize += 1;
	}
	ofilep -> nextoffset = ftell( ofilep -> file ) + arsize;
	    /* say we had one */
	return TRUE;
    }

    /*
     *	variable number of arguments to error, like printf.
     */
D 8
error( fatal , message , arg1 , arg2 , arg3 , arg4 , arg5 , arg6 )
    int		fatal;
E 8
I 8
D 9
error( type , message , arg1 , arg2 , arg3 , arg4 , arg5 , arg6 )
E 9
I 9
error( type , message , arg1 , arg2 , arg3 , arg4 , arg5 , arg6 , arg7 , arg8 )
E 9
    int		type;
E 8
    char	*message;
    {
I 8
	errors = type > errors ? type : errors;
	if ( wflag && type == WARNING ) {
	    return;
	}
E 8
	fprintf( stderr , "%s: " , program );
D 8
	fprintf( stderr , message , arg1 , arg2 , arg3 , arg4 , arg5 , arg6 );
E 8
I 8
	switch ( type ) {
	    case WARNING:
		    fprintf( stderr , "Warning: " );
		    break;
	    case ERROR:
		    fprintf( stderr , "Error: " );
		    break;
	    case FATAL:
		    fprintf( stderr , "Fatal: " );
		    break;
	    default:
		    fprintf( stderr , "Ooops: " );
		    break;
	}
D 9
	fprintf( stderr , message , arg1,arg2,arg3,arg4,arg5,arg6 );
E 9
I 9
	fprintf( stderr , message , arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8 );
E 9
E 8
	fprintf( stderr , "\n" );
D 8
	if ( fatal == FATAL ) {
	    exit( 2 );
E 8
I 8
	if ( type == FATAL ) {
	    exit( FATAL );
E 8
	}
D 8
	errors = 1;
E 8
D 13
    }

    /*
     *	find the last modify time of a file.
     *	on error, return the current time.
     */
time_t
mtime( filename )
    char	*filename;
    {
D 2
	int		file;
E 2
	struct stat	filestat;

#	ifdef DEBUG
	    fprintf( stderr , "[mtime] filename %s\n"
		    , filename );
#	endif DEBUG
D 2
	file = open( filename , 0 );
	if ( file == -1 ) {
E 2
I 2
	if ( stat( filename , &filestat ) != 0 ) {
E 2
D 8
	    error( WARNING , "%s: cannot open" , filename );
E 8
I 8
	    error( WARNING , "%s: cannot stat" , filename );
E 8
	    return ( (time_t) time( 0 ) );
	}
D 2
	fstat( file , &filestat );
E 2
	return filestat.st_mtime;
E 13
    }

char *
classify( type )
    unsigned char	type;
    {
	switch ( type ) {
	    case N_PSO:
		return "source file";
	    case N_PSOL:
		return "include file";
D 5
	    case N_PGLAB:
E 5
I 5
	    case N_PGLABEL:
E 5
		return "label";
D 5
	    case N_PGCON:
E 5
I 5
	    case N_PGCONST:
E 5
		return "constant";
D 5
	    case N_PGTYP:
E 5
I 5
	    case N_PGTYPE:
E 5
		return "type";
	    case N_PGVAR:
		return "variable";
D 5
	    case N_PGFUN:
E 5
I 5
	    case N_PGFUNC:
E 5
		return "function";
D 5
	    case N_PGPRC:
E 5
I 5
	    case N_PGPROC:
E 5
		return "procedure";
D 5
	    case N_PEFUN:
E 5
I 5
	    case N_PEFUNC:
E 5
		return "external function";
D 5
	    case N_PEPRC:
E 5
I 5
	    case N_PEPROC:
E 5
		return "external procedure";
I 9
	    case N_PLDATA:
		return "library variable";
	    case N_PLTEXT:
		return "library routine";
E 9
	    default:
		return "unknown symbol";
I 9
	}
    }

char *
article( type )
    unsigned char	type;
    {
	switch ( type ) {
	    case N_PSO:
		return "a source file";
	    case N_PSOL:
		return "an include file";
	    case N_PGLABEL:
		return "a label";
	    case N_PGCONST:
		return "a constant";
	    case N_PGTYPE:
		return "a type";
	    case N_PGVAR:
		return "a variable";
	    case N_PGFUNC:
		return "a function";
	    case N_PGPROC:
		return "a procedure";
	    case N_PEFUNC:
		return "an external function";
	    case N_PEPROC:
		return "an external procedure";
	    case N_PLDATA:
		return "a library variable";
	    case N_PLTEXT:
		return "a library routine";
	    default:
		return "an unknown symbol";
E 9
	}
    }
E 1
