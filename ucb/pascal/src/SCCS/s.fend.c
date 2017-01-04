h48501
s 00001/00001/01123
d D 5.4 87/01/12 21:21:16 mckusick 35 34
c fix missing \n in mcount preamble
e
s 00132/00003/00992
d D 5.3 86/11/12 10:31:33 mckusick 34 33
c add CCI (tahoe) support
e
s 00002/00001/00993
d D 5.2 86/11/12 10:29:10 mckusick 33 32
c replace `even' and `leven' with explicit rounding
e
s 00007/00003/00987
d D 5.1 85/06/05 14:13:23 dist 32 31
c Add copyright
e
s 00075/00076/00915
d D 2.3 85/03/20 15:00:18 ralph 31 30
c changes from donn@utah-cs for common header file for pcc
e
s 00013/00019/00978
d D 2.2 85/03/15 22:25:25 mckusick 30 28
i 29
c merge in dbx changes
e
s 00015/00013/00963
d D 1.22.1.1 85/03/15 22:10:04 mckusick 29 24
c dbx mods from linton
e
s 00000/00000/00990
d D 2.1 84/02/08 20:49:11 aoki 28 27
c synchronize to version 2
e
s 00003/00003/00987
d D 1.25 84/02/08 11:46:43 aoki 27 26
c lint
e
s 00000/00000/00990
d D 1.24 83/09/19 06:58:16 thien 26 25
c Restoring to unlinted version
e
s 00098/00084/00892
d D 1.23 83/08/19 04:56:43 thien 25 24
c The changes were made to allow successful linting
e
s 00011/00006/00965
d D 1.22 83/04/06 22:12:21 peter 24 23
c it says in my description of the ir that STASG's have the type
c pointer to structure.  this makes a difference for the FORCE in fend.c
c on the mc68000.
e
s 00002/00001/00969
d D 1.21 83/02/28 17:19:50 peter 23 22
c clean up temporary allocation, moving everything relevant to
c tmps.c and (new) tmps.h.  correctly emit LBRAC lines.  allocate registers
c from high to low.  put in data structures for multiple types of registers.
e
s 00005/00000/00965
d D 1.20 83/02/03 12:25:56 peter 22 21
c forgot register save mask for _program for the vax while porting to the 68000.
e
s 00001/00001/00964
d D 1.19 83/02/03 11:12:04 peter 21 20
c typo introduced during port to mc68000.
e
s 00495/00210/00470
d D 1.18 83/02/01 22:05:37 peter 20 19
c separate machine-dependent parts to machine-specific routines
c for code for main, prologues, entry, exit, epilogue, and formal entry points.
e
s 00001/00001/00679
d D 1.17 82/11/12 19:08:18 mckusick 19 18
c arguments to blkclr are reversed to be compatable with bzero
e
s 00014/00004/00666
d D 1.16 82/11/12 10:52:27 mckusick 18 17
c force setjmp and display save/restore for program statement
c if there is a label declaration as there may be a non-local goto to it.
e
s 00047/00036/00623
d D 1.15 82/11/11 19:40:23 mckusick 17 16
c optimize display save/restore and setjmp() to be done only when needed.
e
s 00015/00011/00644
d D 1.14 82/11/10 14:56:33 mckusick 16 15
c get rid of GOTO and replace it with setjmp/longjmp
e
s 00011/00010/00644
d D 1.13 82/08/29 14:07:31 peter 15 14
c allowing no files list in program statement.
e
s 00003/00003/00651
d D 1.12 82/08/26 18:47:48 mckusick 14 13
c convert namelist structure to use unions
e
s 00002/00001/00652
d D 1.11 82/08/02 11:35:06 peter 13 12
c someone forgot to pass an argument to PCEXIT() for exit().
e
s 00012/00001/00641
d D 1.10 82/02/02 23:52:38 mckusic 12 11
c add underflow checking, and intelligent SIGFPE errors if opt('t')
e
s 00009/00000/00633
d D 1.9 82/02/02 12:57:03 linton 11 9
c merge pdx into the Pascal system
e
s 00000/00005/00628
d R 1.9 81/06/08 13:03:22 mckusic 10 9
c put display save area back into formal routine structure
e
s 00019/00013/00614
d D 1.8 81/06/01 15:40:33 peter 9 8
c add storage classes to namelist, and use them.
e
s 00005/00002/00622
d D 1.7 81/05/04 15:10:22 peter 8 7
c fix so that /lib/c2 does not break profiling
e
s 00021/00000/00603
d D 1.6 81/04/01 21:52:06 peter 7 6
c dynamically allocate display save areas before formal calls
e
s 00003/00003/00600
d D 1.5 81/03/25 18:37:47 peter 6 4
c correct errors on delta 1.4
e
s 00002/00002/00601
d R 1.5 81/03/25 18:11:11 peter 5 4
c add sextname() to make up long external names for things.
e
s 00033/00012/00570
d D 1.4 81/03/24 17:51:55 peter 4 3
c add sextname() to make up long external names for things.
e
s 00009/00024/00573
d D 1.3 81/03/18 21:18:35 mckusic 3 2
c mods for new formal routine syntax
e
s 00007/00005/00590
d D 1.2 81/03/16 18:13:02 mckusic 2 1
c add temporary register allocation
e
s 00595/00000/00000
d D 1.1 81/03/11 14:10:48 mckusick 1 0
c date and time created 81/03/11 14:10:48 by mckusick
e
u
U
f b 
t
T
I 1
D 32
/* Copyright (c) 1979 Regents of the University of California */
E 32
I 32
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 32

I 25
#ifndef lint
E 25
D 32
static char sccsid[] = "%Z%%M% %I% %G%";
I 25
#endif
E 32
I 32
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 32
E 25

#include "whoami.h"
#include "0.h"
#include "tree.h"
#include "opcode.h"
#include "objfmt.h"
#include "align.h"
I 23
#include "tmps.h"
E 23

/*
 * this array keeps the pxp counters associated with
 * functions and procedures, so that they can be output
 * when their bodies are encountered
 */
int	bodycnts[ DSPLYSZ ];

#ifdef PC
#   include "pc.h"
D 31
#   include "pcops.h"
E 31
I 31
#   include <pcc.h>
E 31
#endif PC

#ifdef OBJ
int	cntpatch;
int	nfppatch;
#endif OBJ

I 25
#include "tree_ty.h"

E 25
struct	nl *Fp;
int	pnumcnt;
/*
 * Funcend is called to
 * finish a block by generating
 * the code for the statements.
 * It then looks for unresolved declarations
 * of labels, procedures and functions,
 * and cleans up the name list.
 * For the program, it checks the
 * semantics of the program
 * statement (yuchh).
 */
funcend(fp, bundle, endline)
	struct nl *fp;
D 25
	int *bundle;
E 25
I 25
	struct tnode *bundle;
E 25
	int endline;
{
	register struct nl *p;
	register int i, b;
D 25
	int var, inp, out, *blk;
E 25
I 25
	int inp, out;
	struct tnode *blk;
E 25
	bool chkref;
	struct nl *iop;
	char *cp;
	extern int cntstat;
#	ifdef PC
I 2
D 4
	    int	savlabel = getlab();
E 2
	    int	toplabel = getlab();
	    int	botlabel = getlab();
E 4
I 4
D 20
	    int		savlabel = getlab();
	    int		toplabel = getlab();
D 17
	    int		botlabel = getlab();
E 17
I 8
	    int		proflabel = getlab();
I 16
	    int		skip = getlab();
E 16
E 8
	    char	extname[ BUFSIZ ];
E 20
I 20
	    struct entry_exit_cookie	eecookie;
E 20
E 4
#	endif PC
I 25
#	ifndef PC
	int var;
#	endif PC
E 25

	cntstat = 0;
/*
 *	yyoutline();
 */
	if (program != NIL)
		line = program->value[3];
D 25
	blk = bundle[2];
E 25
I 25
	blk = bundle->stmnt_blck.stmnt_list;
E 25
	if (fp == NIL) {
		cbn--;
#		ifdef PTREE
		    nesting--;
#		endif PTREE
		return;
	}
#ifdef OBJ
	/*
D 34
	 * Patch the branch to the
	 * entry point of the function
E 34
I 34
	 * Patch the branch to the entry point of the function.
	 * Assure alignment of O_BEG structure.
E 34
	 */
I 34
	if (((int)lc & 02) == 0)
		word(0);
E 34
D 14
	patch4(fp->entloc);
E 14
I 14
D 25
	patch4(fp->value[NL_ENTLOC]);
E 25
I 25
	patch4((PTR_DCL) fp->value[NL_ENTLOC]);
E 25
E 14
	/*
	 * Put out the block entrance code and the block name.
	 * HDRSZE is the number of bytes of info in the static
	 * BEG data area exclusive of the proc name. It is
	 * currently defined as:
	/*	struct hdr {
	/*		long framesze;	/* number of bytes of local vars */
	/*		long nargs;	/* number of bytes of arguments */
	/*		bool tests;	/* TRUE => perform runtime tests */
	/*		short offset;	/* offset of procedure in source file */
	/*		char name[1];	/* name of active procedure */
	/*	};
	 */
#	define HDRSZE (2 * sizeof(long) + sizeof(short) + sizeof(bool))
	var = put(2, ((lenstr(fp->symbol,0) + HDRSZE) << 8)
		| (cbn == 1 && opt('p') == 0 ? O_NODUMP: O_BEG), (long)0);
	    /*
	     *  output the number of bytes of arguments
	     *  this is only checked on formal calls.
	     */
D 25
	put(2, O_CASE4, cbn == 1 ? (long)0 : (long)(fp->value[NL_OFFS]-DPOFF2));
E 25
I 25
	(void) put(2, O_CASE4, cbn == 1 ? (long)0 : (long)(fp->value[NL_OFFS]-DPOFF2));
E 25
	    /*
	     *	Output the runtime test mode for the routine
	     */
D 25
	put(2, sizeof(bool) == 2 ? O_CASE2 : O_CASE4, opt('t') ? TRUE : FALSE);
E 25
I 25
	(void) put(2, sizeof(bool) == 2 ? O_CASE2 : O_CASE4, opt('t') ? TRUE : FALSE);
E 25
	    /*
	     *	Output line number and routine name
	     */
D 25
	put(2, O_CASE2, bundle[1]);
E 25
I 25
	(void) put(2, O_CASE2, bundle->stmnt_blck.line_no);
E 25
	putstr(fp->symbol, 0);
#endif OBJ
#ifdef PC
	/*
	 * put out the procedure entry code
	 */
I 20
	eecookie.nlp = fp;
E 20
	if ( fp -> class == PROG ) {
I 18
		/*
		 *	If there is a label declaration in the main routine
		 *	then there may be a non-local goto to it that does
		 *	not appear in this module. We have to assume that
		 *	such a reference may occur and generate code to
		 *	prepare for it.
		 */
	    if ( parts[ cbn ] & LPRT ) {
		parts[ cbn ] |= ( NONLOCALVAR | NONLOCALGOTO );
	    }
E 18
D 20
	    putprintf( "	.text" , 0 );
	    putprintf( "	.align	1" , 0 );
	    putprintf( "	.globl	_main" , 0 );
	    putprintf( "_main:" , 0 );
	    putprintf( "	.word	0" , 0 );
D 12
	    putprintf( "	calls	$0,_PCSTART" , 0 );
E 12
I 12
	    if ( opt ( 't' ) ) {
	        putprintf( "	pushl	$1" , 0 );
	    } else {
	        putprintf( "	pushl	$0" , 0 );
	    }
	    putprintf( "	calls	$1,_PCSTART" , 0 );
E 12
	    putprintf( "	movl	4(ap),__argc" , 0 );
	    putprintf( "	movl	8(ap),__argv" , 0 );
	    putprintf( "	calls	$0,_program" , 0 );
D 13
	    putprintf( "	calls	$0,_PCEXIT" , 0 );
E 13
I 13
	    putprintf( "	pushl	$0" , 0 );
	    putprintf( "	calls	$1,_PCEXIT" , 0 );
E 20
I 20
	    codeformain();
E 20
E 13
D 14
	    ftnno = fp -> entloc;
E 14
I 14
	    ftnno = fp -> value[NL_ENTLOC];
E 14
D 20
	    putprintf( "	.text" , 0 );
	    putprintf( "	.align	1" , 0 );
	    putprintf( "	.globl	_program" , 0 );
	    putprintf( "_program:" , 0 );
E 20
I 20
	    prog_prologue(&eecookie);
E 20
D 25
D 29
	    stabfunc( "program" , fp -> class , bundle[1] , 0 );
E 29
I 29
D 30
	    stabline(bundle[1]);
	    stabfunc(fp, "program", bundle[1] , 0 );
E 29
E 25
I 25
	    stabfunc( "program" , fp -> class ,
		bundle->stmnt_blck.line_no , (long) 0 );
E 30
I 30
	    stabline(bundle->stmnt_blck.line_no);
	    stabfunc(fp, "program", bundle->stmnt_blck.line_no , (long) 0 );
E 30
E 25
	} else {
D 14
	    ftnno = fp -> entloc;
E 14
I 14
	    ftnno = fp -> value[NL_ENTLOC];
E 14
D 20
	    putprintf( "	.text" , 0 );
	    putprintf( "	.align	1" , 0 );
D 4
	    putprintf( "	.globl	" , 1 );
	    for ( i = 1 ; i < cbn ; i++ ) {
		putprintf( EXTFORMAT , 1 , enclosing[ i ] );
	    }
	    putprintf( "" , 0 );
	    for ( i = 1 ; i < cbn ; i++ ) {
		putprintf( EXTFORMAT , 1 , enclosing[ i ] );
	    }
	    putprintf( ":" , 0 );
E 4
I 4
D 6
	    sextname( extname , fp -> symbol , cbn );
E 6
I 6
	    sextname( extname , fp -> symbol , cbn - 1 );
I 7
	    putprintf( "	.globl	%s%s" , 0 , FORMALPREFIX , extname );
E 7
E 6
	    putprintf( "	.globl	%s" , 0 , extname );
	    putprintf( "%s:" , 0 , extname );
E 20
I 20
	    fp_prologue(&eecookie);
E 20
E 4
D 25
D 29
	    stabfunc( fp -> symbol , fp -> class , bundle[1] , cbn - 1 );
E 29
I 29
D 30
	    stabline(bundle[1]);
	    stabfunc(fp, fp->symbol, bundle[1], cbn - 1);
E 29
E 25
I 25
	    stabfunc( fp -> symbol , fp -> class , 
		bundle->stmnt_blck.line_no , (long) (cbn - 1) );
E 30
I 30
	    stabline(bundle->stmnt_blck.line_no);
	    stabfunc(fp, fp->symbol, bundle->stmnt_blck.line_no,
		(long)(cbn - 1));
E 30
E 25
	    for ( p = fp -> chain ; p != NIL ; p = p -> chain ) {
D 29
		stabparam( p -> symbol , p2type( p -> type )
D 25
			    , p -> value[ NL_OFFS ] , lwidth( p -> type ) );
E 29
I 29
D 30
		stabparam(p, p->value[NL_OFFS], lwidth(p->type));
E 29
E 25
I 25
			    , p -> value[ NL_OFFS ] ,
				 (int) lwidth( p -> type ) );
E 30
I 30
		stabparam( p , p -> value[ NL_OFFS ] , (int) lwidth(p->type));
E 30
E 25
	    }
	    if ( fp -> class == FUNC ) {
		    /*
		     *	stab the function variable
		     */
		p = fp -> ptr[ NL_FVAR ];
D 29
		stablvar( p -> symbol , p2type( p -> type ) , cbn 
D 25
			, p -> value[ NL_OFFS ] , lwidth( p -> type ) );
E 29
I 29
D 30
		stablvar(p, p->value[NL_OFFS], lwidth(p->type));
E 29
E 25
I 25
			, p -> value[ NL_OFFS ] , (int) lwidth( p -> type ) );
E 30
I 30
		stablvar( p , p -> value[ NL_OFFS ] , (int) lwidth( p -> type));
E 30
E 25
	    }
		/*
		 *	stab local variables
		 *	rummage down hash chain links.
		 */
	    for ( i = 0 ; i <= 077 ; i++ ) {
		for ( p = disptab[ i ] ; p != NIL ; p = p->nl_next) {
		    if ( ( p -> nl_block & 037 ) != cbn ) {
			break;
		    }
		    /*
D 29
		     *	stab local variables
		     *	that's named variables, but not params
E 29
I 29
		     *	stab locals (not parameters)
E 29
		     */
D 29
		    if (   ( p -> symbol != NIL ) 
			&& ( p -> class == VAR )
			&& ( p -> value[ NL_OFFS ] < 0 ) ) {
			stablvar( p -> symbol , p2type( p -> type ) , cbn 
D 25
			    , p -> value[ NL_OFFS ] , lwidth( p -> type ) );
E 29
I 29
D 30
		    if (p->symbol != NIL) {
			if (p->class == VAR && p->value[NL_OFFS] < 0) {
			    stablvar(p, p->value[NL_OFFS], lwidth(p->type));
			} else if (p->class == CONST) {
			    stabconst(p);
E 30
I 30
		    if ( p -> symbol != NIL ) {
			if ( p -> class == VAR && p -> value[ NL_OFFS ] < 0 ) {
			    stablvar( p , p -> value[ NL_OFFS ] ,
				(int) lwidth( p -> type ) );
			} else if ( p -> class == CONST ) {
			    stabconst( p );
E 30
			}
E 29
E 25
I 25
D 30
			    , p -> value[ NL_OFFS ] , (int) lwidth( p -> type ) );
E 30
E 25
		    }
		}
	    }
	}
	stablbrac( cbn );
	    /*
D 20
	     *	register save mask
	     */
D 2
	if ( opt( 't' ) ) {
	    putprintf( "	.word	0x%x" , 0 , RUNCHECK | RSAVEMASK );
	} else {
	    putprintf( "	.word	0x%x" , 0 , RSAVEMASK );
	}
E 2
I 2
	putprintf( "	.word	" , 1 );
        putprintf( PREFIXFORMAT , 0 , LABELPREFIX , savlabel );
E 2
D 17
	putjbr( botlabel );
E 17
	putlab( toplabel );
I 17
	putprintf( "	subl2	$LF%d,sp" , 0 , ftnno );
E 17
	if ( profflag ) {
		/*
		 *	call mcount for profiling
		 */
D 8
	    putprintf( "	moval	1f,r0" , 0 );
E 8
I 8
	    putprintf( "	moval	" , 1 );
	    putprintf( PREFIXFORMAT , 1 , LABELPREFIX , proflabel );
	    putprintf( ",r0" , 0 );
E 8
	    putprintf( "	jsb	mcount" , 0 );
	    putprintf( "	.data" , 0 );
	    putprintf( "	.align	2" , 0 );
D 8
	    putprintf( "1:" , 0 );
E 8
I 8
	    putlab( proflabel );
E 8
	    putprintf( "	.long	0" , 0 );
	    putprintf( "	.text" , 0 );
	}
	    /*
D 16
	     *	set up unwind exception vector.
	     */
	putprintf( "	moval	%s,%d(%s)" , 0
		, UNWINDNAME , UNWINDOFFSET , P2FPNAME );
	    /*
	     *	save address of display entry, for unwind.
	     */
	putprintf( "	moval	%s+%d,%d(%s)" , 0
		, DISPLAYNAME , cbn * sizeof(struct dispsave)
		, DPTROFFSET , P2FPNAME );
	    /*
E 16
D 17
	     *	save old display 
E 17
I 17
D 18
	     *	if there are nested procedures we must save the display.
E 18
I 18
	     *	if there are nested procedures that access our variables
	     *	we must save the display.
E 18
E 17
	     */
D 17
	putprintf( "	movq	%s+%d,%d(%s)" , 0
		, DISPLAYNAME , cbn * sizeof(struct dispsave)
		, DSAVEOFFSET , P2FPNAME );
E 17
I 17
	if ( parts[ cbn ] & NONLOCALVAR ) {
		/*
		 *	save old display 
		 */
	    putprintf( "	movq	%s+%d,%d(%s)" , 0
		    , DISPLAYNAME , cbn * sizeof(struct dispsave)
		    , DSAVEOFFSET , P2FPNAME );
		/*
		 *	set up new display by saving AP and FP in appropriate
		 *	slot in display structure.
		 */
	    putprintf( "	movq	%s,%s+%d" , 0
		    , P2APNAME , DISPLAYNAME , cbn * sizeof(struct dispsave) );
	}
E 17
	    /*
D 17
	     *	set up new display by saving AP and FP in appropriate
	     *	slot in display structure.
	     */
	putprintf( "	movq	%s,%s+%d" , 0
		, P2APNAME , DISPLAYNAME , cbn * sizeof(struct dispsave) );
I 12
	    /*
E 17
	     *	set underflow checking if runtime tests
	     */
	if ( opt( 't' ) ) {
	    putprintf( "	bispsw	$0xe0" , 0 );
	}
E 12
	    /*
E 20
	     *	ask second pass to allocate known locals
	     */
D 23
	putlbracket( ftnno , -sizes[ cbn ].om_max );
E 23
I 23
	putlbracket(ftnno, &sizes[cbn]);
E 23
D 20
	    /*
	     *	and zero them if checking is on
	     *	by calling blkclr( bytes of locals , starting local address );
	     */
D 3
	if ( opt( 't' ) ) {
	    if ( ( -sizes[ cbn ].om_max ) > DPOFF1 ) {
		putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
			, "_blkclr" );
		putleaf( P2ICON ,  ( -sizes[ cbn ].om_max ) - DPOFF1
			, 0 , P2INT , 0 );
		putLV( 0 , cbn , sizes[ cbn ].om_max , P2CHAR );
		putop( P2LISTOP , P2INT );
		putop( P2CALL , P2INT );
		putdot( filename , line );
	    }
		/*
		 *  check number of longs of arguments
		 *  this can only be wrong for formal calls.
		 */
	    if ( fp -> class != PROG ) {
		    putleaf( P2ICON , 0 , 0 , ADDTYPE( P2PTR , P2FTN | P2INT ) ,
			    "_NARGCHK" );
		    putleaf( P2ICON ,
			(fp->value[NL_OFFS] - DPOFF2) / sizeof(long) ,
			0 , P2INT , 0 );
		    putop( P2CALL , P2INT );
		    putdot( filename , line );
	    }
E 3
I 3
	if ( opt( 't' ) && ( -sizes[ cbn ].om_max ) > DPOFF1 ) {
	    putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
		    , "_blkclr" );
I 19
	    putLV( 0 , cbn , sizes[ cbn ].om_max , NLOCAL , P2CHAR );
E 19
	    putleaf( P2ICON ,  ( -sizes[ cbn ].om_max ) - DPOFF1
		    , 0 , P2INT , 0 );
D 9
	    putLV( 0 , cbn , sizes[ cbn ].om_max , P2CHAR );
E 9
I 9
D 19
	    putLV( 0 , cbn , sizes[ cbn ].om_max , NLOCAL , P2CHAR );
E 19
E 9
	    putop( P2LISTOP , P2INT );
	    putop( P2CALL , P2INT );
	    putdot( filename , line );
E 3
	}
I 16
	    /*
D 17
	     *  set up goto vector in case of non-local goto to this frame
E 17
I 17
D 18
	     *  set up goto vector if potential non-local goto to this frame
E 18
I 18
	     *  set up goto vector if non-local goto to this frame
E 18
E 17
	     */
D 17
	putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
		, "_setjmp" );
	putLV( 0 , cbn , GOTOENVOFFSET , NLOCAL , P2PTR|P2STRTY );
	putop( P2CALL , P2INT );
	putleaf( P2ICON , 0 , 0 , P2INT , 0 );
	putop( P2NE , P2INT );
	putleaf( P2ICON , skip , 0 , P2INT , 0 );
	putop( P2CBRANCH , P2INT );
	putdot( filename , line );
	putprintf( "	jmp	(r0)" , 0 );
	putlab(skip);
E 17
I 17
D 18
	if ( ( cbn < 2 && ( parts[ cbn ] & LPRT ) ) ||
	    ( parts[ cbn ] & NONLOCALGOTO ) != 0 ) {
E 18
I 18
	if ( parts[ cbn ] & NONLOCALGOTO ) {
E 18
	    putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
		    , "_setjmp" );
	    putLV( 0 , cbn , GOTOENVOFFSET , NLOCAL , P2PTR|P2STRTY );
	    putop( P2CALL , P2INT );
	    putleaf( P2ICON , 0 , 0 , P2INT , 0 );
	    putop( P2NE , P2INT );
	    putleaf( P2ICON , skip , 0 , P2INT , 0 );
	    putop( P2CBRANCH , P2INT );
	    putdot( filename , line );
		/*
		 *	on non-local goto, setjmp returns with address to
		 *	be branched to.
		 */
	    putprintf( "	jmp	(r0)" , 0 );
	    putlab(skip);
	}
E 20
I 20
	fp_entrycode(&eecookie);
E 20
E 17
E 16
#endif PC
	if ( monflg ) {
		if ( fp -> value[ NL_CNTR ] != 0 ) {
			inccnt( fp -> value [ NL_CNTR ] );
		}
		inccnt( bodycnts[ fp -> nl_block & 037 ] );
	}
	if (fp->class == PROG) {
		/*
		 * The glorious buffers option.
		 *          0 = don't buffer output
		 *          1 = line buffer output
		 *          2 = 512 byte buffer output
		 */
#		ifdef OBJ
		    if (opt('b') != 1)
D 25
			    put(1, O_BUFF | opt('b') << 8);
E 25
I 25
			    (void) put(1, O_BUFF | opt('b') << 8);
E 25
#		endif OBJ
#		ifdef PC
		    if ( opt( 'b' ) != 1 ) {
D 31
			putleaf( P2ICON , 0 , 0
				, ADDTYPE( P2FTN | P2INT , P2PTR ) , "_BUFF" );
D 25
			putleaf( P2ICON , opt( 'b' ) , 0 , P2INT , 0 );
E 25
I 25
			putleaf( P2ICON , opt( 'b' ) , 0 , P2INT , (char *) 0 );
E 25
			putop( P2CALL , P2INT );
E 31
I 31
			putleaf( PCC_ICON , 0 , 0
				, PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR ) , "_BUFF" );
			putleaf( PCC_ICON , opt( 'b' ) , 0 , PCCT_INT , (char *) 0 );
			putop( PCC_CALL , PCCT_INT );
E 31
			putdot( filename , line );
		    }
#		endif PC
I 15
		inp = 0;
E 15
		out = 0;
		for (p = fp->chain; p != NIL; p = p->chain) {
D 15
			if (strcmp(p->symbol, "input") == 0) {
E 15
I 15
D 25
			if (strcmp(p->symbol, input->symbol) == 0) {
E 25
I 25
			if (pstrcmp(p->symbol, input->symbol) == 0) {
E 25
E 15
				inp++;
				continue;
			}
D 15
			if (strcmp(p->symbol, "output") == 0) {
E 15
I 15
D 25
			if (strcmp(p->symbol, output->symbol) == 0) {
E 25
I 25
			if (pstrcmp(p->symbol, output->symbol) == 0) {
E 25
E 15
				out++;
				continue;
			}
			iop = lookup1(p->symbol);
			if (iop == NIL || bn != cbn) {
				error("File %s listed in program statement but not declared", p->symbol);
				continue;
			}
			if (iop->class != VAR) {
				error("File %s listed in program statement but declared as a %s", p->symbol, classes[iop->class]);
				continue;
			}
			if (iop->type == NIL)
				continue;
			if (iop->type->class != FILET) {
				error("File %s listed in program statement but defined as %s",
					p->symbol, nameof(iop->type));
				continue;
			}
#			ifdef OBJ
D 25
			    put(2, O_CON24, text(iop->type) ? 0 : width(iop->type->type));
E 25
I 25
			    (void) put(2, O_CON24, text(iop->type) ? 0 : width(iop->type->type));
E 25
			    i = lenstr(p->symbol,0);
D 25
			    put(2, O_CON24, i);
			    put(2, O_LVCON, i);
E 25
I 25
			    (void) put(2, O_CON24, i);
			    (void) put(2, O_LVCON, i);
E 25
			    putstr(p->symbol, 0);
D 25
			    put(2, O_LV | bn<<8+INDX, (int)iop->value[NL_OFFS]);
			    put(1, O_DEFNAME);
E 25
I 25
			    (void) put(2, O_LV | bn<<8+INDX, (int)iop->value[NL_OFFS]);
			    (void) put(1, O_DEFNAME);
E 25
#			endif OBJ
#			ifdef PC
D 31
			    putleaf( P2ICON , 0 , 0
				    , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
			    putleaf( PCC_ICON , 0 , 0
				    , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
				    , "_DEFNAME" );
D 9
			    putLV( p -> symbol , bn , iop -> value[NL_OFFS]
				    , p2type( iop ) );
E 9
I 9
			    putLV( p -> symbol , bn , iop -> value[NL_OFFS] ,
				    iop -> extra_flags , p2type( iop ) );
E 9
			    putCONG( p -> symbol , strlen( p -> symbol )
				    , LREQ );
D 31
			    putop( P2LISTOP , P2INT );
			    putleaf( P2ICON , strlen( p -> symbol )
D 25
				    , 0 , P2INT , 0 );
E 25
I 25
				    , 0 , P2INT , (char *) 0 );
E 25
			    putop( P2LISTOP , P2INT );
			    putleaf( P2ICON
E 31
I 31
			    putop( PCC_CM , PCCT_INT );
			    putleaf( PCC_ICON , strlen( p -> symbol )
				    , 0 , PCCT_INT , (char *) 0 );
			    putop( PCC_CM , PCCT_INT );
			    putleaf( PCC_ICON
E 31
				, text(iop->type) ? 0 : width(iop->type->type)
D 25
				, 0 , P2INT , 0 );
E 25
I 25
D 31
				, 0 , P2INT , (char *) 0 );
E 25
			    putop( P2LISTOP , P2INT );
			    putop( P2CALL , P2INT );
E 31
I 31
				, 0 , PCCT_INT , (char *) 0 );
			    putop( PCC_CM , PCCT_INT );
			    putop( PCC_CALL , PCCT_INT );
E 31
			    putdot( filename , line );
#			endif PC
		}
D 15
		if (out == 0 && fp->chain != NIL) {
			recovered();
			error("The file output must appear in the program statement file list");
		}
E 15
	}
	/*
	 * Process the prog/proc/func body
	 */
D 25
	noreach = 0;
	line = bundle[1];
E 25
I 25
	noreach = FALSE;
	line = bundle->stmnt_blck.line_no;
E 25
	statlist(blk);
#	ifdef PTREE
	    {
		pPointer Body = tCopy( blk );

		pDEF( PorFHeader[ nesting -- ] ).PorFBody = Body;
	    }
#	endif PTREE
#	ifdef OBJ
D 25
	    if (cbn== 1 && monflg != 0) {
		    patchfil(cntpatch - 2, (long)cnts, 2);
		    patchfil(nfppatch - 2, (long)pfcnt, 2);
E 25
I 25
	    if (cbn== 1 && monflg != FALSE) {
		    patchfil((PTR_DCL) (cntpatch - 2), (long)cnts, 2);
		    patchfil((PTR_DCL) (nfppatch - 2), (long)pfcnt, 2);
E 25
	    }
#	endif OBJ
#	ifdef PC
	    if ( fp -> class == PROG && monflg ) {
D 31
		putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
		putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
			, "_PMFLUSH" );
D 25
		putleaf( P2ICON , cnts , 0 , P2INT , 0 );
		putleaf( P2ICON , pfcnt , 0 , P2INT , 0 );
E 25
I 25
D 31
		putleaf( P2ICON , cnts , 0 , P2INT , (char *) 0 );
		putleaf( P2ICON , pfcnt , 0 , P2INT , (char *) 0 );
E 25
		putop( P2LISTOP , P2INT );
D 9
		putLV( PCPCOUNT , 0 , 0 , P2INT );
E 9
I 9
		putLV( PCPCOUNT , 0 , 0 , NGLOBAL , P2INT );
E 9
		putop( P2LISTOP , P2INT );
		putop( P2CALL , P2INT );
E 31
I 31
		putleaf( PCC_ICON , cnts , 0 , PCCT_INT , (char *) 0 );
		putleaf( PCC_ICON , pfcnt , 0 , PCCT_INT , (char *) 0 );
		putop( PCC_CM , PCCT_INT );
		putLV( PCPCOUNT , 0 , 0 , NGLOBAL , PCCT_INT );
		putop( PCC_CM , PCCT_INT );
		putop( PCC_CALL , PCCT_INT );
E 31
		putdot( filename , line );
	    }
#	endif PC
D 15
	if (fp->class == PROG && inp == 0 && (input->nl_flags & (NUSED|NMOD)) != 0) {
		recovered();
		error("Input is used but not defined in the program statement");
	}
E 15
	/*
	 * Clean up the symbol table displays and check for unresolves
	 */
	line = endline;
I 15
	if (fp->class == PROG && inp == 0 && (input->nl_flags & (NUSED|NMOD)) != 0) {
		recovered();
		error("Input is used but not defined in the program statement");
	}
	if (fp->class == PROG && out == 0 && (output->nl_flags & (NUSED|NMOD)) != 0) {
		recovered();
		error("Output is used but not defined in the program statement");
	}
E 15
	b = cbn;
	Fp = fp;
D 25
	chkref = syneflg == errcnt[cbn] && opt('w') == 0;
E 25
I 25
	chkref = (syneflg == errcnt[cbn] && opt('w') == 0)?TRUE:FALSE;
E 25
	for (i = 0; i <= 077; i++) {
		for (p = disptab[i]; p != NIL && (p->nl_block & 037) == b; p = p->nl_next) {
			/*
			 * Check for variables defined
			 * but not referenced 
			 */
			if (chkref && p->symbol != NIL)
			switch (p->class) {
				case FIELD:
					/*
					 * If the corresponding record is
					 * unused, we shouldn't complain about
					 * the fields.
					 */
				default:
					if ((p->nl_flags & (NUSED|NMOD)) == 0) {
						warning();
						nerror("%s %s is neither used nor set", classes[p->class], p->symbol);
						break;
					}
					/*
					 * If a var parameter is either
					 * modified or used that is enough.
					 */
					if (p->class == REF)
						continue;
#					ifdef OBJ
					    if ((p->nl_flags & NUSED) == 0) {
						warning();
						nerror("%s %s is never used", classes[p->class], p->symbol);
						break;
					    }
#					endif OBJ
#					ifdef PC
D 9
					    if (((p->nl_flags & NUSED) == 0) && ((p->ext_flags & NEXTERN) == 0)) {
E 9
I 9
					    if (((p->nl_flags & NUSED) == 0) && ((p->extra_flags & NEXTERN) == 0)) {
E 9
						warning();
						nerror("%s %s is never used", classes[p->class], p->symbol);
						break;
					    }
#					endif PC
					if ((p->nl_flags & NMOD) == 0) {
						warning();
						nerror("%s %s is used but never set", classes[p->class], p->symbol);
						break;
					}
				case LABEL:
				case FVAR:
				case BADUSE:
					break;
			}
			switch (p->class) {
				case BADUSE:
					cp = "s";
D 25
					if (p->chain->ud_next == NIL)
E 25
I 25
					/* This used to say ud_next
					   that is not a member of nl so
					   i changed it to nl_next,
					   which may be wrong */
					if (p->chain->nl_next == NIL)
E 25
						cp++;
					eholdnl();
					if (p->value[NL_KINDS] & ISUNDEF)
						nerror("%s undefined on line%s", p->symbol, cp);
					else
						nerror("%s improperly used on line%s", p->symbol, cp);
					pnumcnt = 10;
D 25
					pnums(p->chain);
E 25
I 25
					pnums((struct udinfo *) p->chain);
E 25
					pchr('\n');
					break;

				case FUNC:
				case PROC:
#					ifdef OBJ
					    if ((p->nl_flags & NFORWD))
						nerror("Unresolved forward declaration of %s %s", classes[p->class], p->symbol);
#					endif OBJ
#					ifdef PC
D 9
					    if ((p->nl_flags & NFORWD) && ((p->ext_flags & NEXTERN) == 0))
E 9
I 9
					    if ((p->nl_flags & NFORWD) && ((p->extra_flags & NEXTERN) == 0))
E 9
						nerror("Unresolved forward declaration of %s %s", classes[p->class], p->symbol);
#					endif PC
					break;

				case LABEL:
					if (p->nl_flags & NFORWD)
						nerror("label %s was declared but not defined", p->symbol);
					break;
				case FVAR:
					if ((p->nl_flags & NMOD) == 0)
						nerror("No assignment to the function variable");
					break;
			}
		}
		/*
		 * Pop this symbol
		 * table slot
		 */
		disptab[i] = p;
	}

#	ifdef OBJ
D 25
	    put(1, O_END);
E 25
I 25
	    (void) put(1, O_END);
E 25
#	endif OBJ
#	ifdef PC
D 20
		/*
		 *	if there were file variables declared at this level
D 17
		 *	call pclose( &__disply[ cbn ] ) to clean them up.
E 17
I 17
		 *	call PCLOSE( ap ) to clean them up.
E 17
		 */
	    if ( dfiles[ cbn ] ) {
		putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
			, "_PCLOSE" );
D 9
		putRV( DISPLAYNAME , 0 , cbn * sizeof( struct dispsave )
			, P2PTR | P2CHAR );
E 9
I 9
D 17
		putRV( DISPLAYNAME , 0 , cbn * sizeof( struct dispsave ) ,
			NGLOBAL , P2PTR | P2CHAR );
E 17
I 17
		putleaf( P2REG , 0 , P2AP , ADDTYPE( P2CHAR , P2PTR ) , 0 );
E 17
E 9
		putop( P2CALL , P2INT );
		putdot( filename , line );
E 20
I 20
	    fp_exitcode(&eecookie);
	    stabrbrac(cbn);
	    putrbracket(ftnno);
	    fp_epilogue(&eecookie);
	    if (fp -> class != PROG) {
		fp_formalentry(&eecookie);
E 20
	    }
		/*
D 20
		 *	if this is a function,
		 *	the function variable is the return value.
		 *	if it's a scalar valued function, return scalar,
		 *	else, return a pointer to the structure value.
		 */
	    if ( fp -> class == FUNC ) {
		struct nl	*fvar = fp -> ptr[ NL_FVAR ];
		long		fvartype = p2type( fvar -> type );
		long		label;
		char		labelname[ BUFSIZ ];

		switch ( classify( fvar -> type ) ) {
		    case TBOOL:
		    case TCHAR:
		    case TINT:
		    case TSCAL:
		    case TDOUBLE:
		    case TPTR:
D 9
			putRV( fvar -> symbol , ( fvar -> nl_block ) & 037
				, fvar -> value[ NL_OFFS ] , fvartype );
E 9
I 9
			putRV( fvar -> symbol , ( fvar -> nl_block ) & 037 ,
				fvar -> value[ NL_OFFS ] ,
				fvar -> extra_flags ,
				fvartype );
E 9
			break;
		    default:
			label = getlab();
			sprintf( labelname , PREFIXFORMAT ,
				LABELPREFIX , label );
			putprintf( "	.data" , 0 );
			putprintf( "	.lcomm	%s,%d" , 0 ,
				    labelname , lwidth( fvar -> type ) );
			putprintf( "	.text" , 0 );
			putleaf( P2NAME , 0 , 0 , fvartype , labelname );
D 9
			putLV( fvar -> symbol , ( fvar -> nl_block ) & 037
				, fvar -> value[ NL_OFFS ] , fvartype );
E 9
I 9
			putLV( fvar -> symbol , ( fvar -> nl_block ) & 037 ,
				fvar -> value[ NL_OFFS ] ,
				fvar -> extra_flags ,
				fvartype );
E 9
			putstrop( P2STASG , fvartype , lwidth( fvar -> type ) ,
				align( fvar -> type ) );
			putdot( filename , line );
			putleaf( P2ICON , 0 , 0 , fvartype , labelname );
			break;
		}
		putop( P2FORCE , fvartype );
		putdot( filename , line );
	    }
		/*
D 17
		 *	restore old display entry from save area
E 17
I 17
		 *	if there are nested procedures we must save the display.
E 17
		 */
D 17

	    putprintf( "	movq	%d(%s),%s+%d" , 0
		, DSAVEOFFSET , P2FPNAME
		, DISPLAYNAME , cbn * sizeof(struct dispsave) );
E 17
I 17
	    if ( parts[ cbn ] & NONLOCALVAR ) {
		    /*
		     *	restore old display entry from save area
		     */
		putprintf( "	movq	%d(%s),%s+%d" , 0
		    , DSAVEOFFSET , P2FPNAME
		    , DISPLAYNAME , cbn * sizeof(struct dispsave) );
	    }
E 17
	    stabrbrac( cbn );
	    putprintf( "	ret" , 0 );
		/*
		 *	let the second pass allocate locals
I 2
		 * 	and registers
E 2
		 */
I 2
	    putprintf( "	.set	" , 1 );	
	    putprintf( PREFIXFORMAT , 1 , LABELPREFIX , savlabel );
	    putprintf( ", 0x%x" , 0 , savmask() );
E 2
D 17
	    putlab( botlabel );
	    putprintf( "	subl2	$LF%d,sp" , 0 , ftnno );
E 17
	    putrbracket( ftnno );
D 17
	    putjbr( toplabel );
E 17
I 7
		/*
		 *  put down the entry point for formal calls
		 *  the arguments for FCALL have been passed to us
		 *  as hidden parameters after the regular arguments.
		 */
	    if ( fp -> class != PROG ) {
		putprintf( "%s%s:" , 0 , FORMALPREFIX , extname );
		putprintf( "	.word	" , 1 );
		putprintf( PREFIXFORMAT , 0 , LABELPREFIX , savlabel );
		putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR ) ,
			"_FCALL" );
		putRV( 0 , cbn ,
		    fp -> value[ NL_OFFS ] + sizeof( struct formalrtn * ) ,
I 9
		    NPARAM ,
E 9
		    P2PTR | P2STRTY );
D 9
		putRV( 0 , cbn , fp -> value[ NL_OFFS ] , P2PTR|P2STRTY );
E 9
I 9
		putRV( 0 , cbn , fp -> value[ NL_OFFS ] ,
			NPARAM , P2PTR|P2STRTY );
E 9
		putop( P2LISTOP , P2INT );
		putop( P2CALL , P2INT );
		putdot( filename , line );
D 17
		putjbr( botlabel );
E 17
I 17
		putjbr( toplabel );
E 17
	    }
E 7
		/*
E 20
		 *	declare pcp counters, if any
		 */
	    if ( monflg && fp -> class == PROG ) {
		putprintf( "	.data" , 0 );
I 20
D 31
		aligndot(P2INT);
E 31
I 31
		aligndot(PCCT_INT);
E 31
E 20
		putprintf( "	.comm	" , 1 );
		putprintf( PCPCOUNT , 1 );
		putprintf( ",%d" , 0 , ( cnts + 1 ) * sizeof (long) );
		putprintf( "	.text" , 0 );
	    }
#	endif PC
#ifdef DEBUG
D 25
	dumpnl(fp->ptr[2], fp->symbol);
E 25
I 25
	dumpnl(fp->ptr[2], (int) fp->symbol);
E 25
#endif
I 11

#ifdef OBJ
	/*
	 * save the namelist for the debugger pdx
	 */

D 25
	savenl(fp->ptr[2], fp->symbol);
E 25
I 25
	savenl(fp->ptr[2], (int) fp->symbol);
E 25
#endif

E 11
	/*
	 * Restore the
	 * (virtual) name list
	 * position
	 */
	nlfree(fp->ptr[2]);
	/*
	 * Proc/func has been
	 * resolved
	 */
	fp->nl_flags &= ~NFORWD;
	/*
	 * Patch the beg
	 * of the proc/func to
	 * the proper variable size
	 */
	if (Fp == NIL)
		elineon();
#	ifdef OBJ
D 20
	    patchfil(var, (long)(-sizes[cbn].om_max), 2);
E 20
I 20
D 25
	    patchfil(var, leven(-sizes[cbn].om_max), 2);
E 25
I 25
D 33
	    patchfil((PTR_DCL) var, leven(-sizes[cbn].om_max), 2);
E 33
I 33
	    patchfil((PTR_DCL) var,
		roundup(-sizes[cbn].om_max, (long) A_STACK), 2);
E 33
E 25
E 20
#	endif OBJ
	cbn--;
	if (inpflist(fp->symbol)) {
		opop('l');
	}
}
I 4

#ifdef PC
    /*
     *	construct the long name of a function based on it's static nesting.
     *	into a caller-supplied buffer (that should be about BUFSIZ big).
     */
sextname( buffer , name , level )
    char	buffer[];
    char	*name;
    int		level;
{
    char	*starthere;
    int	i;

    starthere = &buffer[0];
    for ( i = 1 ; i < level ; i++ ) {
	sprintf( starthere , EXTFORMAT , enclosing[ i ] );
	starthere += strlen( enclosing[ i ] ) + 1;
    }
D 6
    sprintf( starthere , EXTFORMAT , p -> symbol );
    starthere += strlen( p -> symbol ) + 1;
E 6
I 6
    sprintf( starthere , EXTFORMAT , name );
    starthere += strlen( name ) + 1;
E 6
    if ( starthere >= &buffer[ BUFSIZ ] ) {
	panic( "sextname" );
    }
}
I 20

    /*
     *	code for main()
     */
#ifdef vax

codeformain()
{
    putprintf("	.text" , 0 );
    putprintf("	.align	1" , 0 );
    putprintf("	.globl	_main" , 0 );
    putprintf("_main:" , 0 );
    putprintf("	.word	0" , 0 );
    if ( opt ( 't' ) ) {
	putprintf("	pushl	$1" , 0 );
    } else {
	putprintf("	pushl	$0" , 0 );
    }
    putprintf("	calls	$1,_PCSTART" , 0 );
    putprintf("	movl	4(ap),__argc" , 0 );
    putprintf("	movl	8(ap),__argv" , 0 );
    putprintf("	calls	$0,_program" , 0 );
    putprintf("	pushl	$0" , 0 );
    putprintf("	calls	$1,_PCEXIT" , 0 );
}
I 34
#endif vax
E 34

I 34
#ifdef tahoe
codeformain()
{
    putprintf("	.text" , 0 );
    putprintf("	.align	1" , 0 );
    putprintf("	.globl	_main" , 0 );
    putprintf("_main:" , 0 );
    putprintf("	.word	0" , 0 );
    if ( opt ( 't' ) ) {
	putprintf("	pushl	$1" , 0 );
    } else {
	putprintf("	pushl	$0" , 0 );
    }
    putprintf("	callf	$8,_PCSTART" , 0 );
    putprintf("	movl	4(fp),__argc" , 0 );
    putprintf("	movl	8(fp),__argv" , 0 );
    putprintf("	callf	$4,_program" , 0 );
    putprintf("	pushl	$0" , 0 );
    putprintf("	callf	$8,_PCEXIT" , 0 );
}
#endif tahoe

E 34
    /*
     *	prologue for the program.
     *	different because it
     *		doesn't have formal entry point
     */
I 34
#if defined(vax) || defined(tahoe) 
E 34
prog_prologue(eecookiep)
    struct entry_exit_cookie	*eecookiep;
{
    putprintf("	.text" , 0 );
    putprintf("	.align	1" , 0 );
    putprintf("	.globl	_program" , 0 );
    putprintf("_program:" , 0 );
I 22
	/*
	 *	register save mask
	 */
D 25
    eecookiep -> savlabel = getlab();
    putprintf("	.word	%s%d", 0, SAVE_MASK_LABEL , eecookiep -> savlabel );
E 25
I 25
    eecookiep -> savlabel = (int) getlab();
    putprintf("	.word	%s%d", 0, (int) SAVE_MASK_LABEL , eecookiep -> savlabel );
E 25
E 22
}

fp_prologue(eecookiep)
    struct entry_exit_cookie	*eecookiep;
{
D 25
    int		ftnno = eecookiep -> nlp -> value[NL_ENTLOC];
E 25

    sextname( eecookiep -> extname, eecookiep -> nlp -> symbol , cbn - 1 );
    putprintf( "	.text" , 0 );
    putprintf( "	.align	1" , 0 );
D 25
    putprintf( "	.globl	%s%s", 0, FORMALPREFIX, eecookiep -> extname );
    putprintf( "	.globl	%s" , 0 , eecookiep -> extname );
    putprintf( "%s:" , 0 , eecookiep -> extname );
E 25
I 25
    putprintf( "	.globl	%s%s", 0, (int) FORMALPREFIX, (int) eecookiep -> extname );
    putprintf( "	.globl	%s" , 0 , (int) eecookiep -> extname );
    putprintf( "%s:" , 0 , (int) eecookiep -> extname );
E 25
	/*
	 *	register save mask
	 */
D 25
    eecookiep -> savlabel = getlab();
    putprintf("	.word	%s%d", 0, SAVE_MASK_LABEL , eecookiep -> savlabel );
E 25
I 25
    eecookiep -> savlabel = (int) getlab();
    putprintf("	.word	%s%d", 0, (int) SAVE_MASK_LABEL , eecookiep -> savlabel );
E 25
}
I 34
#endif vax || tahoe
E 34

    /*
     *	code before any user code.
     *	or code that is machine dependent.
     */
I 34
#ifdef vax
E 34
fp_entrycode(eecookiep)
    struct entry_exit_cookie	*eecookiep;
{
D 21
    int	ftnno = eecookiep -> nlp -> nl_value[ENTLOC];
E 21
I 21
    int	ftnno = eecookiep -> nlp -> value[NL_ENTLOC];
E 21
D 25
    int	proflabel = getlab();
    int	setjmp0 = getlab();
E 25
I 25
    int	proflabel = (int) getlab();
    int	setjmp0 = (int) getlab();
E 25

	/*
	 *	top of code;  destination of jump from formal entry code.
	 */
D 25
    eecookiep -> toplabel = getlab();
    putlab( eecookiep -> toplabel );
    putprintf("	subl2	$%s%d,sp" , 0 , FRAME_SIZE_LABEL, ftnno );
E 25
I 25
    eecookiep -> toplabel = (int) getlab();
    (void) putlab( (char *) eecookiep -> toplabel );
    putprintf("	subl2	$%s%d,sp" , 0 , (int) FRAME_SIZE_LABEL, ftnno );
E 25
    if ( profflag ) {
	    /*
	     *	call mcount for profiling
	     */
	putprintf( "	moval	" , 1 );
D 25
	putprintf( PREFIXFORMAT , 1 , LABELPREFIX , proflabel );
E 25
I 25
	putprintf( PREFIXFORMAT , 1 , (int) LABELPREFIX , proflabel );
E 25
	putprintf( ",r0" , 0 );
	putprintf( "	jsb	mcount" , 0 );
	putprintf( "	.data" , 0 );
	putprintf( "	.align	2" , 0 );
D 25
	putlab( proflabel );
E 25
I 25
	(void) putlab( (char *) proflabel );
E 25
	putprintf( "	.long	0" , 0 );
	putprintf( "	.text" , 0 );
    }
	/*
	 *	if there are nested procedures that access our variables
	 *	we must save the display.
	 */
    if ( parts[ cbn ] & NONLOCALVAR ) {
	    /*
	     *	save old display 
	     */
	putprintf( "	movq	%s+%d,%d(%s)" , 0
D 25
		, DISPLAYNAME , cbn * sizeof(struct dispsave)
		, DSAVEOFFSET , P2FPNAME );
E 25
I 25
		, (int) DISPLAYNAME , cbn * sizeof(struct dispsave)
		, DSAVEOFFSET , (int) P2FPNAME );
E 25
	    /*
	     *	set up new display by saving AP and FP in appropriate
	     *	slot in display structure.
	     */
	putprintf( "	movq	%s,%s+%d" , 0
D 25
		, P2APNAME , DISPLAYNAME , cbn * sizeof(struct dispsave) );
E 25
I 25
		, (int) P2APNAME , (int) DISPLAYNAME , cbn * sizeof(struct dispsave) );
E 25
    }
	/*
	 *	set underflow checking if runtime tests
	 */
    if ( opt( 't' ) ) {
	putprintf( "	bispsw	$0xe0" , 0 );
    }
	/*
	 *	zero local variables if checking is on
	 *	by calling blkclr( bytes of locals , starting local address );
	 */
    if ( opt( 't' ) && ( -sizes[ cbn ].om_max ) > DPOFF1 ) {
D 31
	putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
	putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
		, "_blkclr" );
D 25
	putLV( 0 , cbn , sizes[ cbn ].om_max , NLOCAL , P2CHAR );
	putleaf( P2ICON ,  ( -sizes[ cbn ].om_max ) - DPOFF1
		, 0 , P2INT , 0 );
E 25
I 25
D 31
	putLV((char *) 0 , cbn , (int) sizes[ cbn ].om_max , NLOCAL , P2CHAR );
	putleaf( P2ICON ,  (int) (( -sizes[ cbn ].om_max ) - DPOFF1)
		, 0 , P2INT ,(char *) 0 );
E 25
	putop( P2LISTOP , P2INT );
	putop( P2CALL , P2INT );
E 31
I 31
	putLV((char *) 0 , cbn , (int) sizes[ cbn ].om_max , NLOCAL , PCCT_CHAR );
	putleaf( PCC_ICON ,  (int) (( -sizes[ cbn ].om_max ) - DPOFF1)
		, 0 , PCCT_INT ,(char *) 0 );
	putop( PCC_CM , PCCT_INT );
	putop( PCC_CALL , PCCT_INT );
E 31
	putdot( filename , line );
    }
	/*
	 *  set up goto vector if non-local goto to this frame
	 */
    if ( parts[ cbn ] & NONLOCALGOTO ) {
D 31
	putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
	putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
		, "_setjmp" );
D 25
	putLV( 0 , cbn , GOTOENVOFFSET , NLOCAL , P2PTR|P2STRTY );
E 25
I 25
D 31
	putLV( (char *) 0 , cbn , GOTOENVOFFSET , NLOCAL , P2PTR|P2STRTY );
E 25
	putop( P2CALL , P2INT );
D 25
	putleaf( P2ICON , 0 , 0 , P2INT , 0 );
E 25
I 25
	putleaf( P2ICON , 0 , 0 , P2INT , (char *) 0 );
E 25
	putop( P2NE , P2INT );
D 25
	putleaf( P2ICON , setjmp0 , 0 , P2INT , 0 );
E 25
I 25
	putleaf( P2ICON , setjmp0 , 0 , P2INT , (char *) 0 );
E 25
	putop( P2CBRANCH , P2INT );
E 31
I 31
	putLV( (char *) 0 , cbn , GOTOENVOFFSET , NLOCAL , PCCTM_PTR|PCCT_STRTY );
	putop( PCC_CALL , PCCT_INT );
	putleaf( PCC_ICON , 0 , 0 , PCCT_INT , (char *) 0 );
	putop( PCC_NE , PCCT_INT );
	putleaf( PCC_ICON , setjmp0 , 0 , PCCT_INT , (char *) 0 );
	putop( PCC_CBRANCH , PCCT_INT );
E 31
	putdot( filename , line );
	    /*
	     *	on non-local goto, setjmp returns with address to
	     *	be branched to.
	     */
	putprintf( "	jmp	(r0)" , 0 );
D 25
	putlab(setjmp0);
E 25
I 25
	(void) putlab((char *) setjmp0);
E 25
    }
}
I 34
#endif vax
E 34

I 34
#ifdef tahoe
fp_entrycode(eecookiep)
    struct entry_exit_cookie	*eecookiep;
{
    int	ftnno = eecookiep -> nlp -> value[NL_ENTLOC];
    int	proflabel = (int) getlab();
    int	setjmp0 = (int) getlab();

	/*
	 *	top of code;  destination of jump from formal entry code.
	 */
    eecookiep -> toplabel = (int) getlab();
    (void) putlab( (char *) eecookiep -> toplabel );
    putprintf("	subl3	$%s%d,fp,sp" , 0 , (int) FRAME_SIZE_LABEL, ftnno );
    if ( profflag ) {
	    /*
	     *	call mcount for profiling
	     */
	putprintf( "	pushal	" , 1 );
D 35
	putprintf( PREFIXFORMAT , 1 , (int) LABELPREFIX , proflabel, 0 );
E 35
I 35
	putprintf( PREFIXFORMAT , 0 , (int) LABELPREFIX , proflabel );
E 35
	putprintf( "	callf	$8,mcount" , 0 );
	putprintf( "	.data" , 0 );
	putprintf( "	.align	2" , 0 );
	(void) putlab( (char *) proflabel );
	putprintf( "	.long	0" , 0 );
	putprintf( "	.text" , 0 );
    }
	/*
	 *	if there are nested procedures that access our variables
	 *	we must save the display.
	 */
    if ( parts[ cbn ] & NONLOCALVAR ) {
	    /*
	     *	save old display 
	     */
	putprintf( "	movl	%s+%d,%d(%s)" , 0
		, (int) DISPLAYNAME , cbn * sizeof(struct dispsave)
		, DSAVEOFFSET , (int) P2FPNAME );
	    /*
	     *	set up new display by saving FP in appropriate
	     *	slot in display structure.
	     */
	putprintf( "	movl	%s,%s+%d" , 0
		, (int) P2FPNAME , (int) DISPLAYNAME , cbn * sizeof(struct dispsave) );
    }
	/*
	 *	set underflow checking if runtime tests
	 */
    if ( opt( 't' ) ) {
	putprintf( "	bicpsw	$0x20" , 0 );
    }
	/*
	 *	zero local variables if checking is on
	 *	by calling blkclr( bytes of locals , starting local address );
	 */
    if ( opt( 't' ) && ( -sizes[ cbn ].om_max ) > DPOFF1 ) {
	putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
		, "_blkclr" );
	putLV((char *) 0 , cbn , (int) sizes[ cbn ].om_max , NLOCAL , PCCT_CHAR );
	putleaf( PCC_ICON ,  (int) (( -sizes[ cbn ].om_max ) - DPOFF1)
		, 0 , PCCT_INT ,(char *) 0 );
	putop( PCC_CM , PCCT_INT );
	putop( PCC_CALL , PCCT_INT );
	putdot( filename , line );
    }
	/*
	 *  set up goto vector if non-local goto to this frame
	 */
    if ( parts[ cbn ] & NONLOCALGOTO ) {
	putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
		, "_setjmp" );
	putLV( (char *) 0 , cbn , GOTOENVOFFSET , NLOCAL , PCCTM_PTR|PCCT_STRTY );
	putop( PCC_CALL , PCCT_INT );
	putleaf( PCC_ICON , 0 , 0 , PCCT_INT , (char *) 0 );
	putop( PCC_NE , PCCT_INT );
	putleaf( PCC_ICON , setjmp0 , 0 , PCCT_INT , (char *) 0 );
	putop( PCC_CBRANCH , PCCT_INT );
	putdot( filename , line );
	    /*
	     *	on non-local goto, setjmp returns with address to
	     *	be branched to.
	     */
	putprintf( "	jmp	(r0)" , 0 );
	(void) putlab((char *) setjmp0);
    }
}
#endif tahoe

#if defined(vax) || defined(tahoe)
E 34
fp_exitcode(eecookiep)
    struct entry_exit_cookie	*eecookiep;
{
	/*
	 *	if there were file variables declared at this level
	 *	call PCLOSE( ap ) to clean them up.
	 */
    if ( dfiles[ cbn ] ) {
D 31
	putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
	putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
		, "_PCLOSE" );
D 25
	putleaf( P2REG , 0 , P2AP , ADDTYPE( P2CHAR , P2PTR ) , 0 );
E 25
I 25
D 31
	putleaf( P2REG , 0 , P2AP , ADDTYPE( P2CHAR , P2PTR ) , (char *) 0 );
E 25
	putop( P2CALL , P2INT );
E 31
I 31
	putleaf( PCC_REG , 0 , P2AP , PCCM_ADDTYPE( PCCT_CHAR , PCCTM_PTR ) , (char *) 0 );
	putop( PCC_CALL , PCCT_INT );
E 31
	putdot( filename , line );
    }
	/*
	 *	if this is a function,
	 *	the function variable is the return value.
	 *	if it's a scalar valued function, return scalar,
	 *	else, return a pointer to the structure value.
	 */
    if ( eecookiep-> nlp -> class == FUNC ) {
	struct nl	*fvar = eecookiep-> nlp -> ptr[ NL_FVAR ];
	long		fvartype = p2type( fvar -> type );
	long		label;
	char		labelname[ BUFSIZ ];

	switch ( classify( fvar -> type ) ) {
	    case TBOOL:
	    case TCHAR:
	    case TINT:
	    case TSCAL:
	    case TDOUBLE:
	    case TPTR:
		putRV( fvar -> symbol , ( fvar -> nl_block ) & 037 ,
			fvar -> value[ NL_OFFS ] ,
			fvar -> extra_flags ,
D 25
			fvartype );
I 24
		putop( P2FORCE , fvartype );
E 25
I 25
			(int) fvartype );
D 31
		putop( P2FORCE , (int) fvartype );
E 31
I 31
		putop( PCC_FORCE , (int) fvartype );
E 31
E 25
E 24
		break;
	    default:
D 25
		label = getlab();
E 25
I 25
		label = (int) getlab();
E 25
		sprintf( labelname , PREFIXFORMAT , LABELPREFIX , label );
		putprintf( "	.data" , 0 );
		aligndot(A_STRUCT);
		putprintf( "	.lcomm	%s,%d" , 0 ,
D 25
			    labelname , lwidth( fvar -> type ) );
E 25
I 25
			    (int) labelname , (int) lwidth( fvar -> type ) );
E 25
		putprintf( "	.text" , 0 );
D 25
		putleaf( P2NAME , 0 , 0 , fvartype , labelname );
E 25
I 25
D 31
		putleaf( P2NAME , 0 , 0 , (int) fvartype , labelname );
E 31
I 31
		putleaf( PCC_NAME , 0 , 0 , (int) fvartype , labelname );
E 31
E 25
		putLV( fvar -> symbol , ( fvar -> nl_block ) & 037 ,
			fvar -> value[ NL_OFFS ] ,
			fvar -> extra_flags ,
D 25
			fvartype );
D 24
		putstrop( P2STASG , fvartype , lwidth( fvar -> type ) ,
E 24
I 24
		putstrop( P2STASG , ADDTYPE(fvartype, P2PTR) ,
			lwidth( fvar -> type ) ,
E 25
I 25
			(int) fvartype );
D 31
		putstrop( P2STASG , (int) ADDTYPE(fvartype, P2PTR) ,
E 31
I 31
		putstrop( PCC_STASG , (int) PCCM_ADDTYPE(fvartype, PCCTM_PTR) ,
E 31
			(int) lwidth( fvar -> type ) ,
E 25
E 24
			align( fvar -> type ) );
		putdot( filename , line );
D 24
		putleaf( P2ICON , 0 , 0 , fvartype , labelname );
E 24
I 24
D 25
		putleaf( P2ICON , 0 , 0 , ADDTYPE(fvartype, P2PTR), labelname );
		putop( P2FORCE , ADDTYPE(fvartype, P2PTR) );
E 25
I 25
D 31
		putleaf( P2ICON , 0 , 0 , (int) ADDTYPE(fvartype, P2PTR), labelname );
		putop( P2FORCE , (int) ADDTYPE(fvartype, P2PTR) );
E 31
I 31
		putleaf( PCC_ICON , 0 , 0 , (int) PCCM_ADDTYPE(fvartype, PCCTM_PTR), labelname );
		putop( PCC_FORCE , (int) PCCM_ADDTYPE(fvartype, PCCTM_PTR) );
E 31
E 25
E 24
		break;
	}
D 24
	putop( P2FORCE , fvartype );
E 24
	putdot( filename , line );
    }
	/*
	 *	if there are nested procedures we must save the display.
	 */
    if ( parts[ cbn ] & NONLOCALVAR ) {
	    /*
	     *	restore old display entry from save area
	     */
I 34
#ifdef vax
E 34
	putprintf( "	movq	%d(%s),%s+%d" , 0
D 25
	    , DSAVEOFFSET , P2FPNAME
	    , DISPLAYNAME , cbn * sizeof(struct dispsave) );
E 25
I 25
	    , DSAVEOFFSET , (int) P2FPNAME
	    , (int) DISPLAYNAME , cbn * sizeof(struct dispsave) );
I 34
#endif
#ifdef tahoe
	putprintf( "	movl	%d(%s),%s+%d" , 0
	    , DSAVEOFFSET , (int) P2FPNAME
	    , (int) DISPLAYNAME , cbn * sizeof(struct dispsave) );
#endif
E 34
E 25
    }
}
I 34
#endif vax || tahoe
E 34

I 34
#if defined(vax) || defined(tahoe)
E 34
fp_epilogue(eecookiep)
    struct entry_exit_cookie	*eecookiep;
{
I 29
    stabline(line);
E 29
    putprintf("	ret" , 0 );
	/*
	 *	set the register save mask.
	 */
    putprintf("	.set	%s%d,0x%x", 0,
D 25
		SAVE_MASK_LABEL, eecookiep -> savlabel, savmask());
E 25
I 25
		(int) SAVE_MASK_LABEL, eecookiep -> savlabel, savmask());
E 25
}
I 34
#endif vax || tahoe
E 34

I 34
#if defined(vax) || defined(tahoe)
E 34
fp_formalentry(eecookiep)
    struct entry_exit_cookie	*eecookiep;
{

I 24
    putprintf("	.align 1", 0);
E 24
D 25
    putprintf("%s%s:" , 0 , FORMALPREFIX , eecookiep -> extname );
    putprintf("	.word	%s%d", 0, SAVE_MASK_LABEL, eecookiep -> savlabel );
E 25
I 25
    putprintf("%s%s:" , 0 , (int) FORMALPREFIX , (int) eecookiep -> extname );
    putprintf("	.word	%s%d", 0, (int) SAVE_MASK_LABEL, eecookiep -> savlabel );
E 25
D 31
    putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR ) , "_FCALL" );
E 31
I 31
    putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR ) , "_FCALL" );
E 31
D 25
    putRV( 0 , cbn ,
E 25
I 25
    putRV((char *) 0 , cbn ,
E 25
	eecookiep -> nlp -> value[ NL_OFFS ] + sizeof( struct formalrtn * ) ,
D 31
	NPARAM , P2PTR | P2STRTY );
D 25
    putRV(0, cbn, eecookiep -> nlp -> value[NL_OFFS], NPARAM, P2PTR|P2STRTY);
E 25
I 25
    putRV((char *) 0, cbn, eecookiep -> nlp -> value[NL_OFFS], NPARAM, P2PTR|P2STRTY);
E 25
    putop( P2LISTOP , P2INT );
    putop( P2CALL , P2INT );
E 31
I 31
	NPARAM , PCCTM_PTR | PCCT_STRTY );
    putRV((char *) 0, cbn, eecookiep -> nlp -> value[NL_OFFS], NPARAM, PCCTM_PTR|PCCT_STRTY);
    putop( PCC_CM , PCCT_INT );
    putop( PCC_CALL , PCCT_INT );
E 31
    putdot( filename , line );
D 25
    putjbr( eecookiep -> toplabel );
E 25
I 25
    putjbr( (long) eecookiep -> toplabel );
E 25
}
D 34
#endif vax
E 34
I 34
#endif vax || tahoe
E 34

#ifdef mc68000

codeformain()
{
    putprintf("	.text", 0);
    putprintf("	.globl	_main", 0);
    putprintf("_main:", 0);
    putprintf("	link	%s,#0", 0, P2FPNAME);
    if (opt('t')) {
	putprintf("	pea	1", 0);
    } else {
	putprintf("	pea	0", 0);
    }
    putprintf("	jbsr	_PCSTART", 0);
    putprintf("	addql	#4,sp", 0);
    putprintf("	movl	%s@(8),__argc", 0, P2FPNAME);
    putprintf("	movl	%s@(12),__argv", 0, P2FPNAME);
    putprintf("	jbsr	_program", 0);
    putprintf("	pea	0", 0);
    putprintf("	jbsr	_PCEXIT", 0);
}

prog_prologue(eecookiep)
    struct entry_exit_cookie	*eecookiep;
{
    int	ftnno = eecookiep -> nlp -> value[NL_ENTLOC];

    putprintf("	.text", 0);
    putprintf("	.globl	_program", 0);
    putprintf("_program:", 0);
    putprintf("	link	%s,#0", 0, P2FPNAME);
    putprintf("	addl	#-%s%d,sp", 0, FRAME_SIZE_LABEL, ftnno);
	/* touch new end of stack, to break more stack space */
    putprintf("	tstb	sp@(-%s%d)", 0, PAGE_BREAK_LABEL, ftnno);
    putprintf("	moveml	#%s%d,sp@", 0, SAVE_MASK_LABEL, ftnno);
}

fp_prologue(eecookiep)
    struct entry_exit_cookie	*eecookiep;
{
    int		ftnno = eecookiep -> nlp -> value[NL_ENTLOC];

    sextname(eecookiep -> extname, eecookiep -> nlp -> symbol, cbn - 1);
    putprintf("	.text", 0);
    putprintf("	.globl	%s%s", 0, FORMALPREFIX, eecookiep -> extname);
    putprintf("	.globl	%s", 0, eecookiep -> extname);
    putprintf("%s:", 0, eecookiep -> extname);
    putprintf("	link	%s,#0", 0, P2FPNAME);
    putprintf("	addl	#-%s%d,sp", 0, FRAME_SIZE_LABEL, ftnno);
	/* touch new end of stack, to break more stack space */
    putprintf("	tstb	sp@(-%s%d)", 0, PAGE_BREAK_LABEL, ftnno);
    putprintf("	moveml	#%s%d,sp@", 0, SAVE_MASK_LABEL, ftnno);
}

fp_entrycode(eecookiep)
    struct entry_exit_cookie	*eecookiep;
{
D 27
    int	proflabel = getlab();
    int	setjmp0 = getlab();
E 27
I 27
    char *proflabel = getlab();
    char *setjmp0 = getlab();
E 27

	/*
	 *	fill in the label cookie
	 */
    eecookiep -> toplabel = getlab();
D 25
    putlab(eecookiep -> toplabel);
E 25
I 25
    (void) putlab(eecookiep -> toplabel);
E 25
	/*
	 *	call mcount if we are profiling.
	 */
    if ( profflag ) {
	putprintf("	movl	#%s%d,a0", 0, LABELPREFIX,  proflabel);
	putprintf("	jsr	mcount", 0);
	putprintf("	.data", 0);
	putprintf("	.even", 0);
D 25
	putlab(proflabel);
E 25
I 25
	(void) putlab(proflabel);
E 25
	putprintf("	.long	0", 0);
	putprintf("	.text", 0);
    }
	/*
	 *	if there are nested procedures that access our variables
	 *	we must save the display
	 */
    if (parts[cbn] & NONLOCALVAR) {
	    /*
	     *	save the old display
	     */
	putprintf("	movl	%s+%d,%s@(%d)", 0,
		    DISPLAYNAME, cbn * sizeof(struct dispsave),
		    P2FPNAME, DSAVEOFFSET);
	    /*
	     *	set up the new display by saving the framepointer
	     *	in the display structure.
	     */
	putprintf("	movl	%s,%s+%d", 0,
		    P2FPNAME, DISPLAYNAME, cbn * sizeof(struct dispsave));
    }
	/*
	 *	zero local variables if checking is on
	 *	by calling blkclr( bytes of locals , starting local address );
	 */
    if ( opt( 't' ) && ( -sizes[ cbn ].om_max ) > DPOFF1 ) {
D 31
	putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
	putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
		, "_blkclr" );
D 31
	putLV( 0 , cbn , sizes[ cbn ].om_max , NLOCAL , P2CHAR );
	putleaf( P2ICON ,  ( -sizes[ cbn ].om_max ) - DPOFF1
		, 0 , P2INT , 0 );
	putop( P2LISTOP , P2INT );
	putop( P2CALL , P2INT );
E 31
I 31
	putLV( 0 , cbn , sizes[ cbn ].om_max , NLOCAL , PCCT_CHAR );
	putleaf( PCC_ICON ,  ( -sizes[ cbn ].om_max ) - DPOFF1
		, 0 , PCCT_INT , 0 );
	putop( PCC_CM , PCCT_INT );
	putop( PCC_CALL , PCCT_INT );
E 31
	putdot( filename , line );
    }
	/*
	 *  set up goto vector if non-local goto to this frame
	 */
    if ( parts[ cbn ] & NONLOCALGOTO ) {
D 31
	putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
	putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
		, "_setjmp" );
D 31
	putLV( 0 , cbn , GOTOENVOFFSET , NLOCAL , P2PTR|P2STRTY );
	putop( P2CALL , P2INT );
	putleaf( P2ICON , 0 , 0 , P2INT , 0 );
	putop( P2NE , P2INT );
	putleaf( P2ICON , setjmp0 , 0 , P2INT , 0 );
	putop( P2CBRANCH , P2INT );
E 31
I 31
	putLV( 0 , cbn , GOTOENVOFFSET , NLOCAL , PCCTM_PTR|PCCT_STRTY );
	putop( PCC_CALL , PCCT_INT );
	putleaf( PCC_ICON , 0 , 0 , PCCT_INT , 0 );
	putop( PCC_NE , PCCT_INT );
	putleaf( PCC_ICON , setjmp0 , 0 , PCCT_INT , 0 );
	putop( PCC_CBRANCH , PCCT_INT );
E 31
	putdot( filename , line );
	    /*
	     *	on non-local goto, setjmp returns with address to
	     *	be branched to.
	     */
	putprintf("	movl	d0,a0", 0);
	putprintf("	jmp	a0@", 0);
D 25
	putlab(setjmp0);
E 25
I 25
	(void) putlab(setjmp0);
E 25
    }
}

fp_exitcode(eecookiep)
    struct entry_exit_cookie	*eecookiep;
{
	/*
	 *	if there were file variables declared at this level
	 *	call PCLOSE( ap ) to clean them up.
	 */
    if ( dfiles[ cbn ] ) {
D 31
	putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR )
E 31
I 31
	putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR )
E 31
		, "_PCLOSE" );
D 31
	putleaf( P2REG , 0 , P2AP , ADDTYPE( P2CHAR , P2PTR ) , 0 );
	putop( P2CALL , P2INT );
E 31
I 31
	putleaf( PCC_REG , 0 , P2AP , PCCM_ADDTYPE( PCCT_CHAR , PCCTM_PTR ) , 0 );
	putop( PCC_CALL , PCCT_INT );
E 31
	putdot( filename , line );
    }
	/*
	 *	if this is a function,
	 *	the function variable is the return value.
	 *	if it's a scalar valued function, return scalar,
	 *	else, return a pointer to the structure value.
	 */
    if ( eecookiep -> nlp -> class == FUNC ) {
	struct nl	*fvar = eecookiep -> nlp -> ptr[ NL_FVAR ];
	long		fvartype = p2type( fvar -> type );
D 27
	long		label;
E 27
I 27
	char		*label;
E 27
	char		labelname[ BUFSIZ ];

	switch ( classify( fvar -> type ) ) {
	    case TBOOL:
	    case TCHAR:
	    case TINT:
	    case TSCAL:
	    case TDOUBLE:
	    case TPTR:
		putRV( fvar -> symbol , ( fvar -> nl_block ) & 037 ,
			fvar -> value[ NL_OFFS ] ,
			fvar -> extra_flags ,
			fvartype );
I 24
D 31
		putop( P2FORCE , fvartype );
E 31
I 31
		putop( PCC_FORCE , fvartype );
E 31
E 24
		break;
	    default:
		label = getlab();
		sprintf( labelname , PREFIXFORMAT , LABELPREFIX , label );
		putprintf("	.lcomm	%s,%d", 0,
			labelname, lwidth(fvar -> type));
D 31
		putleaf( P2NAME , 0 , 0 , fvartype , labelname );
E 31
I 31
		putleaf( PCC_NAME , 0 , 0 , fvartype , labelname );
E 31
		putLV( fvar -> symbol , ( fvar -> nl_block ) & 037 ,
			fvar -> value[ NL_OFFS ] ,
			fvar -> extra_flags ,
			fvartype );
D 24
		putstrop( P2STASG , fvartype , lwidth( fvar -> type ) ,
E 24
I 24
D 31
		putstrop( P2STASG , ADDTYPE(fvartype, P2PTR) ,
E 31
I 31
		putstrop( PCC_STASG , PCCM_ADDTYPE(fvartype, PCCTM_PTR) ,
E 31
			lwidth( fvar -> type ) ,
E 24
			align( fvar -> type ) );
		putdot( filename , line );
D 24
		putleaf( P2ICON , 0 , 0 , fvartype , labelname );
E 24
I 24
D 31
		putleaf( P2ICON , 0 , 0 , ADDTYPE(fvartype, P2PTR), labelname );
		putop( P2FORCE , ADDTYPE(fvartype, P2PTR) );
E 31
I 31
		putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE(fvartype, PCCTM_PTR), labelname );
		putop( PCC_FORCE , PCCM_ADDTYPE(fvartype, PCCTM_PTR) );
E 31
E 24
		break;
	}
D 24
	putop( P2FORCE , fvartype );
E 24
	putdot( filename , line );
    }
	/*
	 *	if we saved a display, we must restore it.
	 */
    if ( parts[ cbn ] & NONLOCALVAR ) {
	    /*
	     *	restore old display entry from save area
	     */
	putprintf("	movl	%s@(%d),%s+%d", 0,
		    P2FPNAME, DSAVEOFFSET,
		    DISPLAYNAME, cbn * sizeof(struct dispsave));
    }
}

fp_epilogue(eecookiep)
    struct entry_exit_cookie	*eecookiep;
{
    /*
     *	all done by the second pass.
     */
}

fp_formalentry(eecookiep)
    struct entry_exit_cookie	*eecookiep;
{
    putprintf( "%s%s:" , 0 , FORMALPREFIX , eecookiep -> extname );
    putprintf("	link	%s,#0", 0, P2FPNAME);
    putprintf("	addl	#-%s%d,sp", 0, FRAME_SIZE_LABEL, ftnno);
	/* touch new end of stack, to break more stack space */
    putprintf("	tstb	sp@(-%s%d)", 0, PAGE_BREAK_LABEL, ftnno);
    putprintf("	moveml	#%s%d,sp@", 0, SAVE_MASK_LABEL, ftnno);
D 31
    putleaf( P2ICON , 0 , 0 , ADDTYPE( P2FTN | P2INT , P2PTR ) , "_FCALL" );
E 31
I 31
    putleaf( PCC_ICON , 0 , 0 , PCCM_ADDTYPE( PCCTM_FTN | PCCT_INT , PCCTM_PTR ) , "_FCALL" );
E 31
    putRV( 0 , cbn ,
	eecookiep -> nlp -> value[ NL_OFFS ] + sizeof( struct formalrtn * ) ,
D 31
	NPARAM , P2PTR | P2STRTY );
    putRV(0, cbn, eecookiep -> nlp -> value[NL_OFFS], NPARAM, P2PTR|P2STRTY);
    putop( P2LISTOP , P2INT );
    putop( P2CALL , P2INT );
E 31
I 31
	NPARAM , PCCTM_PTR | PCCT_STRTY );
    putRV(0, cbn, eecookiep -> nlp -> value[NL_OFFS], NPARAM, PCCTM_PTR|PCCT_STRTY);
    putop( PCC_CM , PCCT_INT );
    putop( PCC_CALL , PCCT_INT );
E 31
    putdot( filename , line );
    putjbr( eecookiep -> toplabel );
}
#endif mc68000
E 20
#endif PC
I 29
D 31

E 31
E 29
E 4
E 1
