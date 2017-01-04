h18540
s 00056/00000/00146
d D 5.2 86/11/12 09:53:50 mckusick 12 11
c add CCI (tahoe) support
e
s 00007/00003/00139
d D 5.1 85/06/05 15:46:48 dist 11 10
c Add copyright
e
s 00000/00000/00142
d D 2.1 84/02/08 20:51:03 aoki 10 9
c synchronize to version 2
e
s 00006/00002/00136
d D 1.9 83/09/05 18:51:37 peter 9 8
c give offsets for mapping multiple register types to registers.
e
s 00002/00002/00136
d D 1.8 83/02/28 17:16:07 peter 8 7
c clean up temporary allocation, moving everything relevant to
c tmps.c and (new) tmps.h.  correctly emit LBRAC lines.  allocate registers
c from high to low.  put in data structures for multiple types of registers.
e
s 00060/00008/00078
d D 1.7 83/02/01 20:27:27 peter 7 6
c pc constants for the mc68000.
e
s 00005/00006/00081
d D 1.6 82/11/10 14:56:04 mckusick 6 5
c get rid of GOTO and replace it with setjmp/longjmp
e
s 00000/00006/00087
d D 1.5 82/02/02 15:50:30 mckusic 5 4
c convert ECASE to call on CASERNG
e
s 00002/00000/00091
d D 1.4 81/11/13 17:37:43 peter 4 3
c make labels look different from function names.
e
s 00002/00011/00089
d D 1.3 81/04/01 21:51:58 peter 3 2
c dynamically allocate display save areas before formal calls
e
s 00000/00004/00100
d D 1.2 80/10/14 22:48:44 peter 2 1
c labels with fully qualified names
e
s 00104/00000/00000
d D 1.1 80/08/27 19:54:22 peter 1 0
c date and time created 80/08/27 19:54:22 by peter
e
u
U
t
T
I 1
D 11
/* Copyright (c) 1979 Regents of the University of California */

/* static	char sccsid[] = "%Z%%M% %I% %G%"; */
E 11
I 11
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 11

I 6
#include <setjmp.h>

E 6
    /*
D 7
     *		random constants for pc
E 7
I 7
     *	random constants for pc
E 7
     */
    
    /*
     *	the name of the display.
D 3
     *	the display is made up of saved AP's and FP's.
     *	FP's are used to find locals, and AP's are used to find parameters.
     *	FP and AP are untyped pointers, but are used throughout as (char *).
     *	the display is used by adding AP_OFFSET or FP_OFFSET to the 
     *	address of the approriate display entry.
E 3
     */
#define	DISPLAYNAME	"__disply"
D 3
struct dispsave {
    char	*savedAP;
    char	*savedFP;
};
#define	AP_OFFSET	( 0 )
#define FP_OFFSET	( sizeof(char *) )
E 3

    /*
     *	the structure below describes the locals used by the run time system.
     *	at function entry, at least this much space is allocated,
     *	and the following information is filled in:
     *	the address of a routine to close the current frame for unwinding,
     *	a pointer to the display entry for the current static level and
     *	the previous contents of the display for this static level.
     *	the curfile location is used to point to the currently active file,
     *	and is filled in as io is initiated.
     *	one of these structures is allocated on the (negatively growing) stack.
     *	at function entry, fp is set to point to the last field of the struct,
     *	thus the offsets of the fields are as indicated below.
     */
I 12
#ifdef vax
E 12
struct rtlocals {
I 6
    jmp_buf		gotoenv;
E 6
    struct iorec	*curfile;
    struct dispsave	dsave;
D 6
    struct dispsave	*dptr;
    int			(*unwind)();
E 6
} rtlocs;
I 12
#endif vax

#ifdef tahoe
struct rtlocals {
    jmp_buf		gotoenv;
    struct iorec	*curfile;
    struct dispsave	dsave;
    long		savedregs[9];
} rtlocs;
#endif tahoe

#ifdef mc68000
struct rtlocals {
    jmp_buf		gotoenv;
    struct iorec	*curfile;
    struct dispsave	dsave;
} rtlocs;
#endif mc68000

E 12
D 6
#define	CURFILEOFFSET	( ( -sizeof rtlocs ) + sizeof rtlocs.unwind )
E 6
I 6
#define	GOTOENVOFFSET	( -sizeof rtlocs )
#define	CURFILEOFFSET	( GOTOENVOFFSET + sizeof rtlocs.gotoenv )
E 6
#define	DSAVEOFFSET	( CURFILEOFFSET + sizeof rtlocs.curfile )
D 6
#define	DPTROFFSET	( DSAVEOFFSET + sizeof rtlocs.dsave )
#define	UNWINDOFFSET	( DPTROFFSET + sizeof rtlocs.dptr )
#define	UNWINDNAME	"_UNWIND"
E 6

    /*
D 7
     *	the register save mask for saving no registers
E 7
I 7
     *	this is a cookie used to communicate between the
     *	routine entry code and the routine exit code.
     *	mostly it's for labels shared between the two.
E 7
     */
D 7
#define	RSAVEMASK	( 0 )
E 7
I 7
#ifdef vax
struct entry_exit_cookie {
    struct nl	*nlp;
    char	extname[BUFSIZ];
    int		toplabel;
    int		savlabel;
};
#define	FRAME_SIZE_LABEL	"LF"
#define	SAVE_MASK_LABEL		"L"
#endif vax
E 7

I 12
#ifdef tahoe
struct entry_exit_cookie {
    struct nl	*nlp;
    char	extname[BUFSIZ];
    int		toplabel;
    int		savlabel;
};
#define	FRAME_SIZE_LABEL	"LF"
#define	SAVE_MASK_LABEL		"L"
#endif tahoe

E 12
D 7
    /*
     *	runtime check mask for divide check and integer overflow
     */
#define	RUNCHECK	( ( 1 << 15 ) | ( 1 << 14 ) )
E 7
I 7
#ifdef mc68000
struct entry_exit_cookie {
    struct nl	*nlp;
    char	extname[BUFSIZ];
    int		toplabel;
};
#define	FRAME_SIZE_LABEL	"LF"
#define	PAGE_BREAK_LABEL	"LP"
#define	SAVE_MASK_LABEL		"LS"
#endif mc68000
E 7

    /*
     *	formats for various names
     *	    NAMEFORMAT		arbitrary length strings.
     *	    EXTFORMAT		for externals, a preceding underscore.
I 4
     *	    LABELFORMAT		for label names, a preceding dollar-sign.
E 4
     *	    PREFIXFORMAT	used to print made up names with prefixes.
     *	    LABELPREFIX		with getlab() makes up label names.
     *	    LLABELPREFIX	with getlab() makes up sdb labels.
I 3
     *	    FORMALPREFIX	prefix for EXTFORMAT for formal entry points.
E 3
D 2
     *	    PLABELPREFIX	with atol(symbol) makes up global pascal labels.
     *	    GLABELPREFIX	with getlab() makes up nested label names
E 2
     *	a typical use might be to print out a name with a preceeding underscore
     *	with putprintf( EXTFORMAT , 0 , name );
     */
#define	NAMEFORMAT	"%s"
#define	EXTFORMAT	"_%s"
I 4
#define	LABELFORMAT	"$%s"
E 4
#define	PREFIXFORMAT	"%s%d"
#define	LABELPREFIX	"L"
#define	LLABELPREFIX	"LL"
I 3
#define	FORMALPREFIX	"__"
E 3
D 2
#define	PLABELPREFIX	"P"
#define	GLABELPREFIX	"G"
E 2

    /*
     *	the name of the statement counter
     */
#define	STMTCOUNT	"__stcnt"

    /*
     *	the name of the pcp counters
     */
#define	PCPCOUNT	"__pcpcount"

    /*
     *	a vector of pointer to enclosing functions for fully qualified names.
     */
char	*enclosing[ DSPLYSZ ];

I 7
#ifdef vax
E 7
    /*
I 7
     *	the runtime framepointer and argumentpointer registers
     */
#   define	P2FP		13
#   define	P2FPNAME	"fp"
#   define	P2AP		12
#   define	P2APNAME	"ap"

    /*
     *	the register save mask for saving no registers
     */
#   define	RSAVEMASK	( 0 )

    /*
     *	runtime check mask for divide check and integer overflow
     */
#   define	RUNCHECK	( ( 1 << 15 ) | ( 1 << 14 ) )
I 8

E 8
    /*
E 7
     *	and of course ...
     */
D 7
#define	BITSPERBYTE	8
E 7
I 7
#   define	BITSPERBYTE	8
D 8

E 8
#endif vax
I 12

#ifdef tahoe
    /*
     *	the runtime framepointer and argumentpointer registers
     */
#   define	P2FP		13
#   define	P2FPNAME	"fp"
#   define	P2AP		13
#   define	P2APNAME	"fp"

    /*
     *	the register save mask for saving no registers
     */
#   define	RSAVEMASK	( 0 )

    /*
     *	divide check and integer overflow don't exist in the save mask
     */
#   define	RUNCHECK	( 0 )

    /*
     *	and of course ...
     */
#   define	BITSPERBYTE	8
#endif tahoe
E 12

#ifdef mc68000
    /*
D 8
     *	this magic numbers lifted from pcc/mac2defs
E 8
I 8
     *	these magic numbers lifted from pcc/mac2defs
I 9
     *	the offsets are for mapping data and address register numbers
     *	to linear register numbers.  e.g. d2 ==> r2, and a2 ==> r10.
E 9
E 8
     */
D 9
#   define	P2FP		14
E 9
I 9
#   define	DATA_REG_OFFSET	0
#   define	ADDR_REG_OFFSET 8
E 9
#   define	P2FPNAME	"a6"
D 9
#   define	P2AP		14
E 9
I 9
#   define	P2FP		(ADDR_REG_OFFSET + 6)
E 9
#   define	P2APNAME	"a6"
I 9
#   define	P2AP		(ADDR_REG_OFFSET + 6)
E 9

    /*
     *	and still ...
     */
#   define	BITSPERBYTE	8
#endif mc68000
E 7
D 5

    /*
     *	error number for case label not found (ECASE)
     *	stolen from ~mckusick/px/lib/h01errs.h
     */
#define	ECASE		5
E 5
E 1
