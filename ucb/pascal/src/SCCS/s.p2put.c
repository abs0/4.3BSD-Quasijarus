h46831
s 00006/00006/00753
d D 5.4 86/11/12 10:20:47 mckusick 22 21
c add CCI (tahoe) support
e
s 00000/00011/00759
d D 5.3 85/06/21 16:31:44 mckusick 21 20
c botched copyright
e
s 00010/00000/00760
d D 5.2 85/06/18 18:03:39 mckusick 20 19
c Add copyright
e
s 00009/00004/00751
d D 5.1 85/06/05 14:37:14 dist 19 18
c Add copyright
e
s 00152/00187/00603
d D 2.2 85/03/20 15:02:39 ralph 18 17
c changes from donn@utah-cs for common header file for pcc
e
s 00000/00000/00790
d D 2.1 84/02/08 20:51:55 aoki 17 16
c synchronize to version 2
e
s 00001/00000/00789
d D 1.16 84/02/08 00:51:53 mckusick 16 15
c merge in conformant array code by Carol Nishizak
e
s 00023/00031/00766
d D 1.15 84/02/07 13:34:09 mckusick 15 14
c lint (by thien)
e
s 00004/00003/00793
d D 1.14 83/09/05 18:52:31 peter 14 13
c allocate temporaries to registers in the mc68000.
e
s 00027/00018/00769
d D 1.13 83/02/28 17:16:55 peter 13 12
c clean up temporary allocation, moving everything relevant to
c tmps.c and (new) tmps.h.  correctly emit LBRAC lines.  allocate registers
c from high to low.  put in data structures for multiple types of registers.
e
s 00021/00007/00766
d D 1.12 83/02/01 20:10:16 peter 12 11
c port to the mc68000.
c special notes:  watch how doubles are done in putCON8()
c 	note that leftbrackets are now aligned to stack alignment.
e
s 00013/00000/00760
d D 1.11 82/11/11 19:40:40 mckusick 11 10
c optimize display save/restore and setjmp() to be done only when needed.
e
s 00012/00012/00748
d D 1.10 82/08/27 00:28:45 mckusick 10 9
c convert namelist structure to use unions
e
s 00039/00032/00721
d D 1.9 81/06/01 15:37:28 peter 9 8
c add storage classes to namelist, and use them.
e
s 00007/00002/00746
d D 1.8 81/04/21 15:05:22 peter 8 7
c clean up for loop code
e
s 00001/00001/00747
d D 1.7 81/03/25 18:39:31 peter 7 6
c fix some bugs in temporary replacement of for loop indicies
e
s 00009/00009/00739
d D 1.6 81/03/20 14:26:03 peter 6 5
c use cgenflg consistently; take out )#'s on pi code.
e
s 00043/00038/00705
d D 1.5 81/03/16 18:12:36 mckusic 5 4
c add temporary register allocation
e
s 00007/00006/00736
d D 1.4 81/02/17 18:24:08 peter 4 3
c fix FFUNC/FPROC p2type; also -k formats for types
e
s 00019/00018/00723
d D 1.3 80/10/16 22:09:25 peter 3 2
c undefined type is spelled P2UNDEF not P2UNDEFINED.
e
s 00007/00000/00734
d D 1.2 80/10/03 01:08:21 peter 2 1
c Implement formal functions and procedures
e
s 00734/00000/00000
d D 1.1 80/08/27 19:55:31 peter 1 0
c date and time created 80/08/27 19:55:31 by peter
e
u
U
t
T
I 1
D 19
/* Copyright (c) 1979 Regents of the University of California */
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
I 20
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

D 21
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
E 20
E 15
D 19
static	char sccsid[] = "%Z%%M% %I% %G%";
I 15
#endif
E 15

E 19
I 19
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint
E 21
E 19
    /*
     *	functions to help pi put out
     *	polish postfix binary portable c compiler intermediate code
     *	thereby becoming the portable pascal compiler
     */

#include	"whoami.h"
#ifdef PC
#include	"0.h"
I 12
#include	"objfmt.h"
E 12
D 18
#include	"pcops.h"
E 18
I 18
#include	<pcc.h>
E 18
#include	"pc.h"
I 12
#include	"align.h"
I 13
#include	"tmps.h"
E 13
E 12
D 18

    /*
     *	mash into f77's format
     *	lovely, isn't it?
     */
#define		TOF77( fop,val,rest )	( ( ( (rest) & 0177777 ) << 16 ) \
					| ( ( (val) & 0377 ) << 8 )	 \
					| ( (fop) & 0377 ) )
E 18

    /*
     *	emits an ftext operator and a string to the pcstream
     */
puttext( string )
    char	*string;
    {
	int	length = str4len( string );

D 6
	if ( cgenflg )
E 6
I 6
	if ( !CGENNING )
E 6
	    return;
D 18
	p2word( TOF77( P2FTEXT , length , 0 ) );
E 18
I 18
	p2word( PCCM_TRIPLE( PCCF_FTEXT , length , 0 ) );
E 18
#	ifdef DEBUG
	    if ( opt( 'k' ) ) {
D 18
		fprintf( stdout , "P2FTEXT | %3d | 0	" , length );
E 18
I 18
		fprintf( stdout , "PCCF_FTEXT | %3d | 0	" , length );
E 18
	    }
#	endif
	p2string( string );
    }

int
str4len( string )
    char	*string;
    {
	
	return ( ( strlen( string ) + 3 ) / 4 );
    }

    /*
     *	put formatted text into a buffer for printing to the pcstream.
     *	a call to putpflush actually puts out the text.
     *	none of arg1 .. arg5 need be present.
     *	and you can add more if you need them.
     */
D 15
    /* VARARGS */
E 15
I 15
/* VARARGS */
E 15
putprintf( format , incomplete , arg1 , arg2 , arg3 , arg4 , arg5 )
    char	*format;
    int		incomplete;
    {
	static char	ppbuffer[ BUFSIZ ];
	static char	*ppbufp = ppbuffer;

D 6
	if ( cgenflg )
E 6
I 6
	if ( !CGENNING )
E 6
	    return;
	sprintf( ppbufp , format , arg1 , arg2 , arg3 , arg4 , arg5 );
	ppbufp = &( ppbuffer[ strlen( ppbuffer ) ] );
	if ( ppbufp >= &( ppbuffer[ BUFSIZ ] ) )
	    panic( "putprintf" );
	if ( ! incomplete ) {
	    puttext( ppbuffer );
	    ppbufp = ppbuffer;
	}
    }

    /*
     *	emit a left bracket operator to pcstream
     *	with function number, the maximum temp register, and total local bytes
D 13
     *	until i figure out how to use them, regs 0 .. 11 are free.
     *	one idea for one reg is to save the display pointer on block entry
E 13
     */
D 13
putlbracket( ftnno , localbytes )
    int	ftnno;
    int	localbytes;
    {
#	define	MAXTP2REG	11
E 13
I 13
putlbracket(ftnno, sizesp)
    int		ftnno;
    struct om	*sizesp;
{
    int	maxtempreg;	
    int	alignedframesize;
E 13

D 13
	p2word( TOF77( P2FLBRAC , MAXTP2REG , ftnno ) );
D 12
	p2word( BITSPERBYTE * localbytes );
E 12
I 12
	p2word( roundup(BITSPERBYTE * localbytes, BITSPERBYTE * A_STACK));
E 12
#	ifdef DEBUG
	    if ( opt( 'k' ) ) {
		fprintf( stdout
			, "P2FLBRAC | %3d | %d	" , MAXTP2REG , ftnno );
		fprintf( stdout , "%d\n"
			, BITSPERBYTE * localbytes );
	    }
#	endif
    }
E 13
I 13
D 22
#   ifdef vax
E 22
I 22
#   if defined(vax) || defined(tahoe)
E 22
	maxtempreg = sizesp->curtmps.next_avail[REG_GENERAL];
D 22
#   endif vax
E 22
I 22
#   endif vax || tahoe
E 22
#   ifdef mc68000
	    /*
D 14
	     *	this is a5 and d7 mashed together.
E 14
I 14
	     *	this is how /lib/f1 wants it.
E 14
	     */
D 14
	maxtempreg = (5 << 4) | (7);
E 14
I 14
	maxtempreg =	(sizesp->curtmps.next_avail[REG_ADDR] << 4)
		      | (sizesp->curtmps.next_avail[REG_DATA]);
E 14
#   endif mc68000
D 15
    alignedframesize =
	roundup(BITSPERBYTE * -sizesp->curtmps.om_off, BITSPERBYTE * A_STACK);
E 15
I 15
    alignedframesize = roundup((int)(BITSPERBYTE * -sizesp->curtmps.om_off),
	(long)(BITSPERBYTE * A_STACK));
E 15
D 18
    p2word( TOF77( P2FLBRAC , maxtempreg , ftnno ) );
E 18
I 18
    p2word( PCCM_TRIPLE( PCCF_FLBRAC , maxtempreg , ftnno ) );
E 18
    p2word(alignedframesize);
#   ifdef DEBUG
	if ( opt( 'k' ) ) {
D 18
	    fprintf(stdout, "P2FLBRAC | %3d | %d	%d\n",
E 18
I 18
	    fprintf(stdout, "PCCF_FLBRAC | %3d | %d	%d\n",
E 18
		maxtempreg, ftnno, alignedframesize);
	}
#   endif
}
E 13

    /*
     *	emit a right bracket operator
D 14
     *	which for the binary (fortran) interface
E 14
I 14
     *	which for the binary interface
E 14
     *	forces the stack allocate and register mask
     */
putrbracket( ftnno )
    int	ftnno;
    {

D 18
	p2word( TOF77( P2FRBRAC , 0 , ftnno ) );
E 18
I 18
	p2word( PCCM_TRIPLE( PCCF_FRBRAC , 0 , ftnno ) );
E 18
#	ifdef DEBUG
	    if ( opt( 'k' ) ) {
D 18
		fprintf( stdout , "P2FRBRAC |   0 | %d\n" , ftnno );
E 18
I 18
		fprintf( stdout , "PCCF_FRBRAC |   0 | %d\n" , ftnno );
E 18
	    }
#	endif
    }

    /*
     *	emit an eof operator
     */
puteof()
    {
	
D 18
	p2word( P2FEOF );
E 18
I 18
	p2word( PCCF_FEOF );
E 18
#	ifdef DEBUG
	    if ( opt( 'k' ) ) {
D 18
		fprintf( stdout , "P2FEOF\n" );
E 18
I 18
		fprintf( stdout , "PCCF_FEOF\n" );
E 18
	    }
#	endif
    }

    /*
     *	emit a dot operator,
     *	with a source file line number and name
     *	if line is negative, there was an error on that line, but who cares?
     */
putdot( filename , line )
    char	*filename;
    int		line;
    {
	int	length = str4len( filename );

	if ( line < 0 ) {
	    line = -line;
	}
D 18
	p2word( TOF77( P2FEXPR , length , line ) );
E 18
I 18
	p2word( PCCM_TRIPLE( PCCF_FEXPR , length , line ) );
E 18
#	ifdef DEBUG
	    if ( opt( 'k' ) ) {
D 18
		fprintf( stdout , "P2FEXPR | %3d | %d	" , length , line );
E 18
I 18
		fprintf( stdout , "PCCF_FEXPR | %3d | %d	" , length , line );
E 18
	    }
#	endif
	p2string( filename );
    }

    /*
     *	put out a leaf node
     */
putleaf( op , lval , rval , type , name )
    int		op;
    int		lval;
    int		rval;
    int		type;
    char	*name;
    {
D 6
	if ( cgenflg )
E 6
I 6
	if ( !CGENNING )
E 6
	    return;
	switch ( op ) {
	    default:
		panic( "[putleaf]" );
D 18
	    case P2ICON:
		p2word( TOF77( P2ICON , name != NIL , type ) );
E 18
I 18
	    case PCC_ICON:
		p2word( PCCM_TRIPLE( PCC_ICON , name != NIL , type ) );
E 18
		p2word( lval );
#		ifdef DEBUG
		    if ( opt( 'k' ) ) {
D 4
			fprintf( stdout , "P2ICON | %3d | %d	" 
E 4
I 4
D 18
			fprintf( stdout , "P2ICON | %3d | 0x%x	" 
E 18
I 18
			fprintf( stdout , "PCC_ICON | %3d | 0x%x	" 
E 18
E 4
			       , name != NIL , type );
			fprintf( stdout , "%d\n" , lval );
		    }
#		endif
		if ( name )
		    p2name( name );
		break;
D 18
	    case P2NAME:
		p2word( TOF77( P2NAME , lval != 0 , type ) );
E 18
I 18
	    case PCC_NAME:
		p2word( PCCM_TRIPLE( PCC_NAME , lval != 0 , type ) );
E 18
		if ( lval ) 
		    p2word( lval );
#		ifdef DEBUG
		    if ( opt( 'k' ) ) {
D 4
			fprintf( stdout , "P2NAME | %3d | %d	" 
E 4
I 4
D 18
			fprintf( stdout , "P2NAME | %3d | 0x%x	" 
E 18
I 18
			fprintf( stdout , "PCC_NAME | %3d | 0x%x	" 
E 18
E 4
			       , lval != 0 , type );
			if ( lval )
			    fprintf( stdout , "%d	" , lval );
		    }
#		endif
		p2name( name );
		break;
D 18
	    case P2REG:
		p2word( TOF77( P2REG , rval , type ) );
E 18
I 18
	    case PCC_REG:
		p2word( PCCM_TRIPLE( PCC_REG , rval , type ) );
E 18
#		ifdef DEBUG
		    if ( opt( 'k' ) ) {
D 4
			fprintf( stdout , "P2REG | %3d | %d\n" , rval , type );
E 4
I 4
D 18
			fprintf( stdout , "P2REG | %3d | 0x%x\n" ,
E 18
I 18
			fprintf( stdout , "PCC_REG | %3d | 0x%x\n" ,
E 18
				rval , type );
E 4
		    }
#		endif
		break;
	}
    }

    /*
     *	rvalues are just lvalues with indirection, except
D 9
     *	special case for named globals, whose names are their rvalues
E 9
I 9
     *	special cases for registers and for named globals,
     *	whose names are their rvalues.
E 9
     */
D 9
putRV( name , level , offset , type )
E 9
I 9
D 10
putRV( name , level , offset , extra_flags , type )
E 10
I 10
putRV( name , level , offset , other_flags , type )
E 10
E 9
    char	*name;
    int		level;
    int		offset;
I 9
D 10
    char	extra_flags;
E 10
I 10
    char	other_flags;
E 10
E 9
    int		type;
    {
	char	extname[ BUFSIZ ];
	char	*printname;
I 8
D 15
	int	regnumber;
E 15
E 8

D 6
	if ( cgenflg )
E 6
I 6
	if ( !CGENNING )
E 6
	    return;
I 5
D 7
	if (level == cbn && whereis(offset) == REGVAR) {
E 7
I 7
D 9
	if (whereis(offset) == REGVAR) {
E 7
D 8
	    putleaf( P2REG , 0 , (-offset) >> 1 , type , 0 );
E 8
I 8
	    regnumber = ( - offset ) >> 1;
	    if ( ( regnumber < 0 ) || ( regnumber > P2FP ) ) {
		panic( "putRV regnumber" );
E 9
I 9
D 10
	if ( extra_flags & NREGVAR ) {
E 10
I 10
	if ( other_flags & NREGVAR ) {
E 10
	    if ( ( offset < 0 ) || ( offset > P2FP ) ) {
		panic( "putRV regvar" );
E 9
	    }
D 9
	    putleaf( P2REG , 0 , regnumber , type , 0 );
E 9
I 9
D 15
	    putleaf( P2REG , 0 , offset , type , 0 );
E 15
I 15
D 18
	    putleaf( P2REG , 0 , offset , type , (char *) 0 );
E 18
I 18
	    putleaf( PCC_REG , 0 , offset , type , (char *) 0 );
E 18
E 15
E 9
E 8
	    return;
	}
E 5
D 9
	if ( ( level <= 1 ) && ( name != 0 ) ) {
	    if ( name[0] != '_' ) {
		    sprintf( extname , EXTFORMAT , name );
		    printname = extname;
E 9
I 9
D 10
	if ( whereis( level , offset , extra_flags ) == GLOBALVAR ) {
E 10
I 10
D 15
	if ( whereis( level , offset , other_flags ) == GLOBALVAR ) {
E 15
I 15
	if ( whereis( offset , other_flags ) == GLOBALVAR ) {
E 15
E 10
	    if ( name != 0 ) {
		if ( name[0] != '_' ) {
			sprintf( extname , EXTFORMAT , name );
			printname = extname;
		} else {
			printname = name;
		}
D 18
		putleaf( P2NAME , offset , 0 , type , printname );
E 18
I 18
		putleaf( PCC_NAME , offset , 0 , type , printname );
E 18
		return;
E 9
	    } else {
D 9
		    printname = name;
E 9
I 9
		panic( "putRV no name" );
E 9
	    }
D 9
	    putleaf( P2NAME , offset , 0 , type , printname );
	    return;
E 9
	}
D 9
	putLV( name , level , offset , type );
E 9
I 9
D 10
	putLV( name , level , offset , extra_flags , type );
E 10
I 10
	putLV( name , level , offset , other_flags , type );
E 10
E 9
D 18
	putop( P2UNARY P2MUL , type );
E 18
I 18
	putop( PCCOM_UNARY PCC_MUL , type );
E 18
    }

    /*
     *	put out an lvalue 
     *	given a level and offset
     *	special case for
     *	    named globals, whose lvalues are just their names as constants.
D 9
     *	    negative offsets, that are offsets from the frame pointer.
I 5
     *	    odd negative numbers are register variables.
E 5
     *	    positive offsets, that are offsets from argument pointer.
E 9
     */
D 9
putLV( name , level , offset , type )
E 9
I 9
D 10
putLV( name , level , offset , extra_flags , type )
E 10
I 10
putLV( name , level , offset , other_flags , type )
E 10
E 9
    char	*name;
    int		level;
    int		offset;
I 9
D 10
    char	extra_flags;
E 10
I 10
    char	other_flags;
E 10
E 9
    int		type;
D 5
    {
	char		extname[ BUFSIZ ];
	char		*printname;
E 5
I 5
{
    char		extname[ BUFSIZ ];
    char		*printname;
E 5

D 5
	if ( cgenflg )
	    return;
	if ( ( level <= 1 ) && ( name != 0 ) ) {
	    if ( name[0] != '_' ) {
		    sprintf( extname , EXTFORMAT , name );
		    printname = extname;
	    } else {
		    printname = name;
	    }
	    putleaf( P2ICON , offset , 0 , ADDTYPE( type , P2PTR )
		    , printname );
	    return;
	}
	if ( level == cbn ) {
		if ( offset < 0 ) {
		    putleaf( P2REG , 0 , P2FP , ADDTYPE( type , P2PTR ) , 0 );
		} else {
		    putleaf( P2REG , 0 , P2AP , ADDTYPE( type , P2PTR ) , 0 );
		}
E 5
I 5
D 6
    if ( cgenflg )
E 6
I 6
    if ( !CGENNING )
E 6
	return;
D 9
    if ( ( level <= 1 ) && ( name != 0 ) ) {
	if ( name[0] != '_' ) {
		sprintf( extname , EXTFORMAT , name );
		printname = extname;
E 5
	} else {
D 5
		if ( offset < 0 ) {
			putleaf( P2NAME
			    , ( level * sizeof(struct dispsave) ) + FP_OFFSET
			    , 0 , P2PTR | P2CHAR , DISPLAYNAME );
		} else {
			putleaf( P2NAME
			    , ( level * sizeof(struct dispsave) ) + AP_OFFSET
			    , 0 , P2PTR | P2CHAR , DISPLAYNAME );
		}
E 5
I 5
		printname = name;
E 5
	}
D 5
	if ( offset < 0 ) {
		putleaf( P2ICON , -offset , 0 , P2INT , 0 );
		putop( P2MINUS , P2PTR | P2CHAR );
	} else {
		putleaf( P2ICON , offset , 0 , P2INT , 0 );
		putop( P2PLUS , P2PTR | P2CHAR );
	}
E 5
I 5
	putleaf( P2ICON , offset , 0 , ADDTYPE( type , P2PTR )
		, printname );
E 5
	return;
E 9
I 9
D 10
    if ( extra_flags & NREGVAR ) {
E 10
I 10
    if ( other_flags & NREGVAR ) {
E 10
	panic( "putLV regvar" );
E 9
    }
I 5
D 9
    switch(whereis(offset)) {
E 9
I 9
D 10
    switch ( whereis( level , offset , extra_flags ) ) {
E 10
I 10
D 15
    switch ( whereis( level , offset , other_flags ) ) {
E 15
I 15
    switch ( whereis( offset , other_flags ) ) {
E 15
E 10
	case GLOBALVAR:
	    if ( ( name != 0 ) ) {
		if ( name[0] != '_' ) {
			sprintf( extname , EXTFORMAT , name );
			printname = extname;
		} else {
			printname = name;
		}
D 18
		putleaf( P2ICON , offset , 0 , ADDTYPE( type , P2PTR )
E 18
I 18
		putleaf( PCC_ICON , offset , 0 , PCCM_ADDTYPE( type , PCCTM_PTR )
E 18
			, printname );
		return;
	    } else {
		panic( "putLV no name" );
	    }
E 9
	case PARAMVAR:
	    if ( level == cbn ) {
D 15
		putleaf( P2REG , 0 , P2AP , ADDTYPE( type , P2PTR ) , 0 );
E 15
I 15
D 18
		putleaf( P2REG, 0, P2AP, ADDTYPE( type , P2PTR ), (char *) 0 );
E 18
I 18
		putleaf( PCC_REG, 0, P2AP, PCCM_ADDTYPE( type , PCCTM_PTR ), (char *) 0 );
E 18
E 15
	    } else {
D 18
		putleaf( P2NAME , (level * sizeof(struct dispsave)) + AP_OFFSET
		    , 0 , P2PTR | P2CHAR , DISPLAYNAME );
E 18
I 18
		putleaf( PCC_NAME , (level * sizeof(struct dispsave)) + AP_OFFSET
		    , 0 , PCCTM_PTR | PCCT_CHAR , DISPLAYNAME );
E 18
I 11
		parts[ level ] |= NONLOCALVAR;
E 11
	    }
D 15
	    putleaf( P2ICON , offset , 0 , P2INT , 0 );
E 15
I 15
D 18
	    putleaf( P2ICON , offset , 0 , P2INT , (char *) 0 );
E 15
	    putop( P2PLUS , P2PTR | P2CHAR );
E 18
I 18
	    putleaf( PCC_ICON , offset , 0 , PCCT_INT , (char *) 0 );
	    putop( PCC_PLUS , PCCTM_PTR | PCCT_CHAR );
E 18
	    break;
	case LOCALVAR:
	    if ( level == cbn ) {
D 15
		putleaf( P2REG , 0 , P2FP , ADDTYPE( type , P2PTR ) , 0 );
E 15
I 15
D 18
		putleaf( P2REG, 0, P2FP, ADDTYPE( type , P2PTR ), (char *) 0 );
E 18
I 18
		putleaf( PCC_REG, 0, P2FP, PCCM_ADDTYPE( type , PCCTM_PTR ), (char *) 0 );
E 18
E 15
	    } else {
D 18
		putleaf( P2NAME , (level * sizeof(struct dispsave)) + FP_OFFSET
		    , 0 , P2PTR | P2CHAR , DISPLAYNAME );
E 18
I 18
		putleaf( PCC_NAME , (level * sizeof(struct dispsave)) + FP_OFFSET
		    , 0 , PCCTM_PTR | PCCT_CHAR , DISPLAYNAME );
E 18
I 11
		parts[ level ] |= NONLOCALVAR;
E 11
	    }
D 15
	    putleaf( P2ICON , -offset , 0 , P2INT , 0 );
E 15
I 15
D 18
	    putleaf( P2ICON , -offset , 0 , P2INT , (char *) 0 );
E 15
I 11
	    putop( P2MINUS , P2PTR | P2CHAR );
E 18
I 18
	    putleaf( PCC_ICON , -offset , 0 , PCCT_INT , (char *) 0 );
	    putop( PCC_MINUS , PCCTM_PTR | PCCT_CHAR );
E 18
	    break;
	case NAMEDLOCALVAR:
	    if ( level == cbn ) {
D 15
		putleaf( P2REG , 0 , P2FP , ADDTYPE( type , P2PTR ) , 0 );
E 15
I 15
D 18
		putleaf( P2REG, 0, P2FP, ADDTYPE( type , P2PTR ), (char *) 0 );
E 18
I 18
		putleaf( PCC_REG, 0, P2FP, PCCM_ADDTYPE( type , PCCTM_PTR ), (char *) 0 );
E 18
E 15
	    } else {
D 18
		putleaf( P2NAME , (level * sizeof(struct dispsave)) + FP_OFFSET
		    , 0 , P2PTR | P2CHAR , DISPLAYNAME );
E 18
I 18
		putleaf( PCC_NAME , (level * sizeof(struct dispsave)) + FP_OFFSET
		    , 0 , PCCTM_PTR | PCCT_CHAR , DISPLAYNAME );
E 18
		parts[ level ] |= NONLOCALVAR;
	    }
D 18
	    putleaf( P2ICON , 0 , 0 , P2INT , name );
E 11
	    putop( P2MINUS , P2PTR | P2CHAR );
E 18
I 18
	    putleaf( PCC_ICON , 0 , 0 , PCCT_INT , name );
	    putop( PCC_MINUS , PCCTM_PTR | PCCT_CHAR );
E 18
	    break;
D 9
	case REGVAR:
D 8
	    panic("lval of reg");
E 8
I 8
	    panic("putLV regvar");
E 9
E 8
    }
    return;
}
E 5

    /*
     *	put out a floating point constant leaf node
     *	the constant is declared in aligned data space
D 18
     *	and a P2NAME leaf put out for it
E 18
I 18
     *	and a PCC_NAME leaf put out for it
E 18
     */
D 10
putCON8( value )
    double	value;
E 10
I 10
putCON8( val )
    double	val;
E 10
    {
D 15
	int	label;
E 15
I 15
	char	*label;
E 15
	char	name[ BUFSIZ ];

D 6
	if ( cgenflg )
E 6
I 6
	if ( !CGENNING )
E 6
	    return;
D 12
	putprintf( "	.data" , 0 );
	putprintf( "	.align 2" , 0 );
E 12
	label = getlab();
I 12
	putprintf( "	.data" , 0 );
	aligndot(A_DOUBLE);
E 12
D 15
	putlab( label );
E 15
I 15
	(void) putlab( label );
E 15
D 10
	putprintf( "	.double 0d%.20e" , 0 , value );
E 10
I 10
D 12
	putprintf( "	.double 0d%.20e" , 0 , val );
E 12
I 12
D 22
#	ifdef vax
E 22
I 22
#	if defined(vax) || defined(tahoe)
E 22
	    putprintf( "	.double 0d%.20e" , 0 , val );
D 22
#	endif vax
E 22
I 22
#	endif vax || tahoe
E 22
#	ifdef mc68000
	    putprintf( "	.long 	0x%x,0x%x", 0, val);
#	endif mc68000
E 12
E 10
	putprintf( "	.text" , 0 );
	sprintf( name , PREFIXFORMAT , LABELPREFIX , label );
D 18
	putleaf( P2NAME , 0 , 0 , P2DOUBLE , name );
E 18
I 18
	putleaf( PCC_NAME , 0 , 0 , PCCT_DOUBLE , name );
E 18
    }

	/*
	 * put out either an lvalue or an rvalue for a constant string.
	 * an lvalue (for assignment rhs's) is the name as a constant, 
	 * an rvalue (for parameters) is just the name.
	 */
putCONG( string , length , required )
    char	*string;
    int		length;
    int		required;
    {
	char	name[ BUFSIZ ];
D 15
	int	label;
E 15
I 15
	char	*label;
E 15
	char	*cp;
	int	pad;
	int	others;

D 6
	if ( cgenflg )
E 6
I 6
	if ( !CGENNING )
E 6
	    return;
	putprintf( "	.data" , 0 );
I 12
	aligndot(A_STRUCT);
E 12
	label = getlab();
D 15
	putlab( label );
E 15
I 15
	(void) putlab( label );
E 15
	cp = string;
	while ( *cp ) {
	    putprintf( "	.byte	0%o" , 1 , *cp ++ );
	    for ( others = 2 ; ( others <= 8 ) && *cp ; others ++ ) {
		putprintf( ",0%o" , 1 , *cp++ );
	    }
	    putprintf( "" , 0 );
	}
	pad = length - strlen( string );
	while ( pad-- > 0 ) {
	    putprintf( "	.byte	0%o" , 1 , ' ' );
	    for ( others = 2 ; ( others <= 8 ) && ( pad-- > 0 ) ; others++ ) {
		putprintf( ",0%o" , 1 , ' ' );
	    }
	    putprintf( "" , 0 );
	}
	putprintf( "	.byte	0" , 0 );
	putprintf( "	.text"  , 0 );
	sprintf( name , PREFIXFORMAT , LABELPREFIX , label );
	if ( required == RREQ ) {
D 18
	    putleaf( P2NAME , 0 , 0 , P2ARY | P2CHAR , name );
E 18
I 18
	    putleaf( PCC_NAME , 0 , 0 , PCCTM_ARY | PCCT_CHAR , name );
E 18
	} else {
D 18
	    putleaf( P2ICON , 0 , 0 , P2PTR | P2CHAR , name );
E 18
I 18
	    putleaf( PCC_ICON , 0 , 0 , PCCTM_PTR | PCCT_CHAR , name );
E 18
	}
    }

    /*
     *	map a pascal type to a c type
     *	this would be tail recursive, but i unfolded it into a for (;;).
     *	this is sort of like isa and lwidth
     *	a note on the types used by the portable c compiler:
     *	    they are divided into a basic type (char, short, int, long, etc.)
     *	    and qualifications on those basic types (pointer, function, array).
     *	    the basic type is kept in the low 4 bits of the type descriptor,
     *	    and the qualifications are arranged in two bit chunks, with the
     *	    most significant on the right,
     *	    and the least significant on the left
     *		e.g. int *foo();
     *			(a function returning a pointer to an integer)
     *		is stored as
     *		    <ptr><ftn><int>
     *	so, we build types recursively
I 3
     *	also, we know that /lib/f1 can only deal with 6 qualifications
     *	so we stop the recursion there.  this stops infinite type recursion
     *	through mutually recursive pointer types.
E 3
     */
I 3
#define	MAXQUALS	6
E 3
int
p2type( np )
I 15
    struct nl	*np;
E 15
D 3
    struct nl *np;
E 3
I 3
{

    return typerecur( np , 0 );
}
typerecur( np , quals )
    struct nl	*np;
    int		quals;
E 3
    {
	
D 3
	if ( np == NIL )
	    return P2UNDEFINED;
E 3
I 3
	if ( np == NIL || quals > MAXQUALS ) {
D 18
	    return P2UNDEF;
E 18
I 18
	    return PCCT_UNDEF;
E 18
	}
E 3
	switch ( np -> class ) {
	    case SCAL :
	    case RANGE :
I 16
	    case CRANGE :
E 16
		if ( np -> type == ( nl + TDOUBLE ) ) {
D 18
		    return P2DOUBLE;
E 18
I 18
		    return PCCT_DOUBLE;
E 18
		}
		switch ( bytes( np -> range[0] , np -> range[1] ) ) {
		    case 1:
D 18
			return P2CHAR;
E 18
I 18
			return PCCT_CHAR;
E 18
		    case 2:
D 18
			return P2SHORT;
E 18
I 18
			return PCCT_SHORT;
E 18
		    case 4:
D 18
			return P2INT;
E 18
I 18
			return PCCT_INT;
E 18
		    default:
			panic( "p2type int" );
I 15
			/* NOTREACHED */
E 15
		}
	    case STR :
D 18
		return ( P2ARY | P2CHAR );
E 18
I 18
		return ( PCCTM_ARY | PCCT_CHAR );
E 18
D 3
		/*
		return P2STRTY;
		*/
E 3
	    case RECORD :
	    case SET :
D 18
		return P2STRTY;
E 18
I 18
		return PCCT_STRTY;
E 18
	    case FILET :
D 18
		return ( P2PTR | P2STRTY );
E 18
I 18
		return ( PCCTM_PTR | PCCT_STRTY );
E 18
	    case CONST :
	    case VAR :
	    case FIELD :
		return p2type( np -> type );
	    case TYPE :
		switch ( nloff( np ) ) {
		    case TNIL :
D 3
			return ( P2PTR | P2UNDEFINED );
E 3
I 3
D 18
			return ( P2PTR | P2UNDEF );
E 18
I 18
			return ( PCCTM_PTR | PCCT_UNDEF );
E 18
E 3
		    case TSTR :
D 18
			return ( P2ARY | P2CHAR );
E 18
I 18
			return ( PCCTM_ARY | PCCT_CHAR );
E 18
D 3
			/*
			return P2STRTY;
			*/
E 3
		    case TSET :
D 18
			return P2STRTY;
E 18
I 18
			return PCCT_STRTY;
E 18
		    default :
			return ( p2type( np -> type ) );
		}
	    case REF:
	    case WITHPTR:
	    case PTR :
D 3
		return ADDTYPE( p2type( np -> type ) , P2PTR );
E 3
I 3
D 18
		return ADDTYPE( typerecur( np -> type , quals + 1 ) , P2PTR );
E 18
I 18
		return PCCM_ADDTYPE( typerecur( np -> type , quals + 1 ) , PCCTM_PTR );
E 18
E 3
	    case ARRAY :
D 3
		return ADDTYPE( p2type( np -> type ) , P2ARY );
		/*
		return P2STRTY;
		*/
E 3
I 3
D 18
		return ADDTYPE( typerecur( np -> type , quals + 1 ) , P2ARY );
E 18
I 18
		return PCCM_ADDTYPE( typerecur( np -> type , quals + 1 ) , PCCTM_ARY );
E 18
E 3
	    case FUNC :
		    /*
		     * functions are really pointers to functions
		     * which return their underlying type.
		     */
D 3
		return ADDTYPE( ADDTYPE( p2type( np -> type ) , P2FTN )
				, P2PTR );
E 3
I 3
D 18
		return ADDTYPE( ADDTYPE( typerecur( np -> type , quals + 2 ) ,
					P2FTN ) , P2PTR );
E 18
I 18
		return PCCM_ADDTYPE( PCCM_ADDTYPE( typerecur( np -> type , quals + 2 ) ,
					PCCTM_FTN ) , PCCTM_PTR );
E 18
E 3
	    case PROC :
		    /*
		     * procedures are pointers to functions 
		     * which return integers (whether you look at them or not)
		     */
D 18
		return ADDTYPE( ADDTYPE( P2INT , P2FTN ) , P2PTR );
E 18
I 18
		return PCCM_ADDTYPE( PCCM_ADDTYPE( PCCT_INT , PCCTM_FTN ) , PCCTM_PTR );
E 18
I 2
	    case FFUNC :
	    case FPROC :
		    /*
		     *	formal procedures and functions are pointers
		     *	to structures which describe their environment.
		     */
D 4
		return ADDTYPE( P2PTR , P2STRTY );
E 4
I 4
D 18
		return ( P2PTR | P2STRTY );
E 18
I 18
		return ( PCCTM_PTR | PCCT_STRTY );
E 18
E 4
E 2
	    default :
D 3
		fprintf( stderr , "[p2type] np -> class %d\n" , np -> class );
E 3
		panic( "p2type" );
I 15
		/* NOTREACHED */
E 15
	}
    }

    /*
D 15
     *	add a most significant type modifier to a type
     */
long
addtype( underlying , mtype )
    long	underlying;
    long	mtype;
    {
	return ( ( ( underlying & ~P2BASETYPE ) << P2TYPESHIFT )
	       | mtype
	       | ( underlying & P2BASETYPE ) );
    }

    /*
E 15
     *	put a typed operator to the pcstream
     */
putop( op , type )
    int		op;
    int		type;
    {
D 18
	extern char	*p2opnames[];
E 18
I 18
	extern char	*p2opname();
E 18
	
D 6
	if ( cgenflg )
E 6
I 6
	if ( !CGENNING )
E 6
	    return;
D 18
	p2word( TOF77( op , 0 , type ) );
E 18
I 18
	p2word( PCCM_TRIPLE( op , 0 , type ) );
E 18
#	ifdef DEBUG
	    if ( opt( 'k' ) ) {
D 4
		fprintf( stdout , "%s (%d) |   0 | %d\n"
E 4
I 4
		fprintf( stdout , "%s (%d) |   0 | 0x%x\n"
E 4
D 18
			, p2opnames[ op ] , op , type );
E 18
I 18
			, p2opname( op ) , op , type );
E 18
	    }
#	endif
    }

    /*
     *	put out a structure operator (STASG, STARG, STCALL, UNARY STCALL )
     *	which looks just like a regular operator, only the size and
     *	alignment go in the next consecutive words
     */
putstrop( op , type , size , alignment )
    int	op;
    int	type;
    int	size;
    int	alignment;
    {
D 18
	extern char	*p2opnames[];
E 18
I 18
	extern char	*p2opname();
E 18
	
D 6
	if ( cgenflg )
E 6
I 6
	if ( !CGENNING )
E 6
	    return;
D 18
	p2word( TOF77( op , 0 , type ) );
E 18
I 18
	p2word( PCCM_TRIPLE( op , 0 , type ) );
E 18
	p2word( size );
	p2word( alignment );
#	ifdef DEBUG
	    if ( opt( 'k' ) ) {
D 4
		fprintf( stdout , "%s (%d) |   0 | %d	%d %d\n"
E 4
I 4
		fprintf( stdout , "%s (%d) |   0 | 0x%x	%d %d\n"
E 4
D 18
			, p2opnames[ op ] , op , type , size , alignment );
E 18
I 18
			, p2opname( op ) , op , type , size , alignment );
E 18
	    }
#	endif
    }

    /*
     *	the string names of p2ops
     */
D 18
char	*p2opnames[] = {
	"",
	"P2UNDEFINED",		/* 1 */
	"P2NAME",		/* 2 */
	"P2STRING",		/* 3 */
	"P2ICON",		/* 4 */
	"P2FCON",		/* 5 */
	"P2PLUS",		/* 6 */
	"",
	"P2MINUS",		/* 8		also unary == P2NEG */
	"",
	"P2NEG",
	"P2MUL",		/* 11		also unary == P2INDIRECT */
	"",
	"P2INDIRECT",
	"P2AND",		/* 14		also unary == P2ADDROF */
	"",
	"P2ADDROF",
	"P2OR",			/* 17 */
	"",
	"P2ER",			/* 19 */
	"",
	"P2QUEST",		/* 21 */
	"P2COLON",		/* 22 */
	"P2ANDAND",		/* 23 */
	"P2OROR",		/* 24 */
	"",			/* 25 */
	"",			/* 26 */
	"",			/* 27 */
	"",			/* 28 */
	"",			/* 29 */
	"",			/* 30 */
	"",			/* 31 */
	"",			/* 32 */
	"",			/* 33 */
	"",			/* 34 */
	"",			/* 35 */
	"",			/* 36 */
	"",			/* 37 */
	"",			/* 38 */
	"",			/* 39 */
	"",			/* 40 */
	"",			/* 41 */
	"",			/* 42 */
	"",			/* 43 */
	"",			/* 44 */
	"",			/* 45 */
	"",			/* 46 */
	"",			/* 47 */
	"",			/* 48 */
	"",			/* 49 */
	"",			/* 50 */
	"",			/* 51 */
	"",			/* 52 */
	"",			/* 53 */
	"",			/* 54 */
	"",			/* 55 */
	"P2LISTOP",		/* 56 */
	"",
	"P2ASSIGN",		/* 58 */
	"P2COMOP",		/* 59 */
	"P2DIV",		/* 60 */
	"",
	"P2MOD",		/* 62 */
	"",
	"P2LS",			/* 64 */
	"",
	"P2RS",			/* 66 */
	"",
	"P2DOT",		/* 68 */
	"P2STREF",		/* 69 */
	"P2CALL",		/* 70		also unary */
	"",
	"P2UNARYCALL",
	"P2FORTCALL",		/* 73		also unary */
	"",
	"P2UNARYFORTCALL",
	"P2NOT",		/* 76 */
	"P2COMPL",		/* 77 */
	"P2INCR",		/* 78 */
	"P2DECR",		/* 79 */
	"P2EQ",			/* 80 */
	"P2NE",			/* 81 */
	"P2LE",			/* 82 */
	"P2LT",			/* 83 */
	"P2GE",			/* 84 */
	"P2GT",			/* 85 */
	"P2ULE",		/* 86 */
	"P2ULT",		/* 87 */
	"P2UGE",		/* 88 */
	"P2UGT",		/* 89 */
	"P2SETBIT",		/* 90 */
	"P2TESTBIT",		/* 91 */
	"P2RESETBIT",		/* 92 */
	"P2ARS",		/* 93 */
	"P2REG",		/* 94 */
	"P2OREG",		/* 95 */
	"P2CCODES",		/* 96 */
	"P2FREE",		/* 97 */
	"P2STASG",		/* 98 */
	"P2STARG",		/* 99 */
	"P2STCALL",		/* 100		also unary */
	"",
	"P2UNARYSTCALL",
	"P2FLD",		/* 103 */
	"P2SCONV",		/* 104 */
	"P2PCONV",		/* 105 */
	"P2PMCONV",		/* 106 */
	"P2PVCONV",		/* 107 */
	"P2FORCE",		/* 108 */
	"P2CBRANCH",		/* 109 */
	"P2INIT",		/* 110 */
	"P2CAST",		/* 111 */
E 18
I 18

struct p2op {
    int op;
    char *name;
};

static struct p2op	p2opnames[] = {
	PCC_ERROR, "PCC_ERROR",
	PCC_NAME, "PCC_NAME",
	PCC_STRING, "PCC_STRING",
	PCC_ICON, "PCC_ICON",
	PCC_FCON, "PCC_FCON",
	PCC_PLUS, "PCC_PLUS",
	PCC_MINUS, "PCC_MINUS",
	PCC_UMINUS, "PCC_UMINUS",
	PCC_MUL, "PCC_MUL",
	PCC_DEREF, "PCC_DEREF",
	PCC_AND, "PCC_AND",
	PCC_ADDROF, "PCC_ADDROF",
	PCC_OR, "PCC_OR",
	PCC_ER, "PCC_ER",
	PCC_QUEST, "PCC_QUEST",
	PCC_COLON, "PCC_COLON",
	PCC_ANDAND, "PCC_ANDAND",
	PCC_OROR, "PCC_OROR",
	PCC_CM, "PCC_CM",
	PCC_ASSIGN, "PCC_ASSIGN",
	PCC_COMOP, "PCC_COMOP",
	PCC_DIV, "PCC_DIV",
	PCC_MOD, "PCC_MOD",
	PCC_LS, "PCC_LS",
	PCC_RS, "PCC_RS",
	PCC_DOT, "PCC_DOT",
	PCC_STREF, "PCC_STREF",
	PCC_CALL, "PCC_CALL",
	PCC_UCALL, "PCC_UCALL",
	PCC_FORTCALL, "PCC_FORTCALL",
	PCC_UFORTCALL, "PCC_UFORTCALL",
	PCC_NOT, "PCC_NOT",
	PCC_COMPL, "PCC_COMPL",
	PCC_INCR, "PCC_INCR",
	PCC_DECR, "PCC_DECR",
	PCC_EQ, "PCC_EQ",
	PCC_NE, "PCC_NE",
	PCC_LE, "PCC_LE",
	PCC_LT, "PCC_LT",
	PCC_GE, "PCC_GE",
	PCC_GT, "PCC_GT",
	PCC_ULE, "PCC_ULE",
	PCC_ULT, "PCC_ULT",
	PCC_UGE, "PCC_UGE",
	PCC_UGT, "PCC_UGT",
	PCC_REG, "PCC_REG",
	PCC_OREG, "PCC_OREG",
	PCC_CCODES, "PCC_CCODES",
	PCC_FREE, "PCC_FREE",
	PCC_STASG, "PCC_STASG",
	PCC_STARG, "PCC_STARG",
	PCC_STCALL, "PCC_STCALL",
	PCC_USTCALL, "PCC_USTCALL",
	PCC_FLD, "PCC_FLD",
	PCC_SCONV, "PCC_SCONV",
	PCC_PCONV, "PCC_PCONV",
	PCC_PMCONV, "PCC_PMCONV",
	PCC_PVCONV, "PCC_PVCONV",
	PCC_FORCE, "PCC_FORCE",
	PCC_CBRANCH, "PCC_CBRANCH",
	PCC_INIT, "PCC_INIT",
	PCC_CAST, "PCC_CAST",
	-1, ""
E 18
    };
I 18

char *
p2opname( op )
    register int	op;
    {
	static char		*p2map[PCC_MAXOP+1];
	static bool		mapready = FALSE;
	register struct p2op	*pp;

	if ( mapready == FALSE ) {
	    for ( pp = p2opnames; pp->op >= 0; pp++ )
		p2map[ pp->op ] = pp->name;
	    mapready = TRUE;
	}
	return ( p2map[ op ] ? p2map[ op ] : "unknown" );
    }
E 18

    /*
     *	low level routines
     */

    /*
     *	puts a long word on the pcstream
     */
p2word( word )
D 15
    long	word;
E 15
I 15
    int		word;
E 15
    {

	putw( word , pcstream );
    }

    /*
     *	put a length 0 mod 4 null padded string onto the pcstream
     */
p2string( string )
    char	*string;
    {
	int	slen = strlen( string );
	int	wlen = ( slen + 3 ) / 4;
	int	plen = ( wlen * 4 ) - slen;
	char	*cp;
	int	p;

	for ( cp = string ; *cp ; cp++ )
	    putc( *cp , pcstream );
	for ( p = 1 ; p <= plen ; p++ )
	    putc( '\0' , pcstream );
#	ifdef DEBUG
	    if ( opt( 'k' ) ) {
		fprintf( stdout , "\"%s" , string );
		for ( p = 1 ; p <= plen ; p++ )
		    fprintf( stdout , "\\0" );
		fprintf( stdout , "\"\n" );
	    }
#	endif
    }

    /*
     *	puts a name on the pcstream
     */
p2name( name )
    char	*name;
    {
	int	pad;

	fprintf( pcstream , NAMEFORMAT , name );
	pad = strlen( name ) % sizeof (long);
	for ( ; pad < sizeof (long) ; pad++ ) {
	    putc( '\0' , pcstream );
	}
#	ifdef DEBUG
	    if ( opt( 'k' ) ) {
		fprintf( stdout , NAMEFORMAT , name );
		pad = strlen( name ) % sizeof (long);
		for ( ; pad < sizeof (long) ; pad++ ) {
		    fprintf( stdout , "\\0" );
		}
		fprintf( stdout , "\n" );
	    }
#	endif
    }
    
    /*
     *	put out a jump to a label
     */
putjbr( label )
    long	label;
    {

	printjbr( LABELPREFIX , label );
    }

    /*
     *	put out a jump to any kind of label
     */
printjbr( prefix , label )
    char	*prefix;
    long	label;
    {

D 12
	putprintf( "	jbr	" , 1 );
	putprintf( PREFIXFORMAT , 0 , prefix , label );
E 12
I 12
D 22
#	ifdef vax
E 22
I 22
#	if defined(vax) || defined(tahoe)
E 22
	    putprintf( "	jbr	" , 1 );
	    putprintf( PREFIXFORMAT , 0 , prefix , label );
D 22
#	endif vax
E 22
I 22
#	endif vax || tahoe
E 22
#	ifdef mc68000
	    putprintf( "	jra	" , 1 );
	    putprintf( PREFIXFORMAT , 0 , prefix , label );
#	endif mc68000
E 12
    }

    /*
     *	another version of put to catch calls to put
     */
D 15
put( arg1 , arg2 )
E 15
I 15
/* VARARGS */
put()
E 15
    {

D 12
	putprintf( "#	PUT CALLED!: arg1 = %d arg2 = 0%o" , 0 , arg1 , arg2 );
E 12
I 12
	panic("put()");
E 12
    }

#endif PC
E 1
