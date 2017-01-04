h32144
s 00026/00000/00221
d D 5.2 86/11/11 21:06:42 mckusick 19 17
c add tahoe support
e
s 00001/00001/00220
d R 5.2 85/09/18 23:55:55 mckusick 18 17
c size grew to 2560
e
s 00007/00003/00214
d D 5.1 85/06/05 15:45:21 dist 17 16
c Add copyright
e
s 00000/00000/00217
d D 2.1 84/02/08 20:49:39 aoki 16 15
c synchronize to version 2
e
s 00000/00000/00217
d D 1.15 83/09/19 07:08:27 thien 15 14
c changing to unlinted source
e
s 00006/00001/00211
d D 1.14 83/08/19 05:07:04 thien 14 13
c Changed for linting
e
s 00008/00000/00204
d D 1.13 83/04/08 14:55:24 mckusick 13 12
c add START so px_header will work on the mc68000
e
s 00001/00001/00203
d D 1.12 83/02/03 17:10:12 mckusick 12 11
c px_header gets ever larger...
e
s 00165/00044/00039
d D 1.11 83/02/01 20:28:39 peter 11 10
c port to the mc68000.
c things move into objfmt.h as we discover they are machine dependent.
e
s 00001/00001/00082
d D 1.10 82/11/10 14:56:11 mckusick 10 9
c get rid of GOTO and replace it with setjmp/longjmp
e
s 00000/00020/00083
d D 1.9 82/03/31 15:50:23 peter 9 8
c moving things to config.h
e
s 00001/00001/00102
d D 1.8 82/02/01 14:59:48 mckusic 8 7
c fix npx_header to be px_header
e
s 00004/00002/00099
d D 1.7 82/02/01 13:56:44 mckusic 7 6
c merge pdx into the Pascal system
e
s 00004/00000/00097
d D 1.6 81/03/10 00:46:10 mckusic 6 5
c onyx optimizations
e
s 00015/00005/00082
d D 1.5 81/03/06 22:49:47 mckusic 5 4
c merge in onyx changes
e
s 00001/00001/00086
d D 1.4 81/01/08 13:52:36 mckusic 4 3
c update INDX to reflect "raw" display
e
s 00001/00002/00086
d D 1.3 81/01/06 17:16:24 mckusic 3 2
c modify to allow use of px written in `C' and the use of libpc
e
s 00002/00002/00086
d D 1.2 80/10/04 09:55:43 peter 2 1
c px_header is in /usr/lib and px is in /usr/ucb
e
s 00088/00000/00000
d D 1.1 80/08/27 19:54:13 peter 1 0
c date and time created 80/08/27 19:54:13 by peter
e
u
U
t
T
I 1
D 17
/* Copyright (c) 1979 Regents of the University of California */

D 5
/* static	char sccsid[] = "%Z%%M% %I% %G%"; */
E 5
I 5
/* static char sccsid[] = "%Z%%M% %I% %G%"; */
E 17
I 17
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 17
E 5

I 11
/*
 * The size of the display.
 */
#define DSPLYSZ 20

/*
 *	The structure of the runtime display
 */
E 11
#ifdef OBJ
I 11
struct dispsave {
	char *locvars;		/* pointer to local variables */
	struct blockmark *stp;	/* pointer to local stack frame */
};
E 11
	/*
I 11
	 * The following union allows fast access to
	 * precomputed display entries
	 */
union display {
	struct dispsave frame[DSPLYSZ];
	char *raw[2*DSPLYSZ];
} display;
#endif OBJ
#ifdef PC
#ifdef vax
	/*
	 *	the display is made up of saved AP's and FP's.
	 *	FP's are used to find locals,
	 *	and AP's are used to find parameters.
	 *	FP and AP are untyped pointers,
	 *	but are used throughout as (char *).
	 *	the display is used by adding AP_OFFSET or FP_OFFSET to the 
	 *	address of the approriate display entry.
	 */
    struct dispsave {
	char	*savedAP;
	char	*savedFP;
    } display[ DSPLYSZ ];

#   define	AP_OFFSET	( 0 )
#   define	FP_OFFSET	( sizeof (char *) )
#endif vax
#ifdef mc68000
	/*
	 *	the display is just the saved a6.
	 *	arguments are at positive offsets,
	 *	locals are at negative offsets.
	 *	there are no offsets within the saved display structure.
	 */
    struct dispsave {
	char	*saveda6;
    } display[ DSPLYSZ ];

#   define	AP_OFFSET	(0)
#   define	FP_OFFSET	(0)
#endif mc68000
I 19
#ifdef tahoe
	/*
	 *	the display is just the saved FP.
	 *	arguments are at positive offsets,
	 *	locals are at negative offsets.
	 *	there are no offsets within the saved display structure.
	 */
    struct dispsave {
	char	*savedFP;
    } display[ DSPLYSZ ];

#   define	AP_OFFSET	0
#   define	FP_OFFSET	0
#endif tahoe
E 19
#endif PC

    /*
     *	the structure below describes the block mark used by the architecture.
     *	this is the space used by the machine between the arguments and the
     *	whatever is used to point to the arguments.
     */
#ifdef OBJ
struct blockmark {
	char *tos;		/* pointer to top of stack frame */
	struct iorec *file;	/* pointer to active file name */
	struct hdr {
		long framesze;	/* number of bytes of local vars */
		long nargs;	/* number of bytes of arguments */
		long tests;	/* TRUE => perform runtime tests */
		short offset;	/* offset of procedure in source file */
		char name[1];	/* name of active procedure */
	} *entry;
	struct dispsave odisp;	/* previous display value for this level */
	struct dispsave *dp;	/* pointer to active display entry */
	char *pc;		/* previous location counter */
	long lino;		/* previous line number */
};
#endif OBJ
#ifdef PC
#ifdef vax
	/*
	 *	since we have the ap pointing to the number of args:
	 */
    struct blockmark {
        long	nargs;
    };
#endif vax
#ifdef mc68000
	/*
	 *	there's the saved pc (from the jsr)
	 *	and the saved a6 (from the link a6).
	 */
    struct blockmark {
	char	*savedpc;
	char	*saveda6;
    };
#endif mc68000
I 19
#ifdef tahoe
	/*
	 *	since we have the fp pointing to its predecessor
	 */
    struct blockmark {
	long	savedfp;
    };
#endif tahoe
E 19
#endif PC

    /*
     *	formal routine structure:
     */
struct formalrtn {
	long		(*fentryaddr)();	/* formal entry point */
	long		fbn;			/* block number of function */
	struct dispsave	fdisp[ DSPLYSZ ];	/* saved at first passing */
D 14
} frtn;
E 14
I 14
};
#ifndef PC
#ifndef OBJ
struct formalrtn	frtn;
#endif
#endif
E 14

#define	FENTRYOFFSET	0
#define FBNOFFSET	( FENTRYOFFSET + sizeof frtn.fentryaddr )
#define	FDISPOFFSET	( FBNOFFSET + sizeof frtn.fbn )

#ifdef OBJ
	/*
E 11
	 *	the creation time, the size and the magic number of the obj file
	 */
    struct pxhdr {
D 5
	    int	maketime;
	    int	objsize;
E 5
I 5
	    long	maketime;
	    long	objsize;
I 7
	    long	symtabsize;
E 7
E 5
	    short	magicnum;
    };

I 13
/*
 *	START defines the beginning of the text space.
 *	This should be the defined external label "start",
 *	however there is no way to access externals from C
 *	whose names do not begin with an "_".
 */
E 13
I 11
#ifdef vax
E 11
D 7
#   define	HEADER_BYTES	1024		/* the size of px_header */
D 2
#   define PX_HEADER "/usr/lib/npx_header"	/* px_header's name */
#   define PX_INTRP "/usr/new/px"		/* the interpreter's name */
E 2
I 2
#   define PX_HEADER "/usr/lib/px_header"	/* px_header's name */
E 7
I 7
D 12
#   define HEADER_BYTES	1536			/* the size of px_header */
E 12
I 12
#   define HEADER_BYTES	2048			/* the size of px_header */
I 13
#   define START 0x0				/* beginning of text */
E 13
E 12
I 11
#endif vax
I 19
#ifdef tahoe
#   define HEADER_BYTES	2048			/* the size of px_header */
#   define START 0x0				/* beginning of text */
#endif tahoe
E 19
#ifdef mc68000
#   define HEADER_BYTES	3072			/* the size of px_header */
I 13
#   define START 0x8000				/* beginning of text */
E 13
#endif mc68000
E 11
D 8
#   define PX_HEADER "/usr/lib/npx_header"	/* px_header's name */
E 8
I 8
D 9
#   define PX_HEADER "/usr/lib/px_header"	/* px_header's name */
E 8
E 7
I 5
#   define PI_COMP "/usr/ucb/pi"		/* the compiler's name */
E 5
#   define PX_INTRP "/usr/ucb/px"		/* the interpreter's name */
I 7
#   define PX_DEBUG "/usr/ucb/pdx"		/* the debugger's name */
E 9
E 7
I 3
D 4
#   define INDX 0				/* amt to shift display index */
E 4
I 4
#   define INDX 1				/* amt to shift display index */
E 4
E 3
E 2
#endif OBJ
D 9

    /*
     *	the file of error messages created by mkstr
     */
#ifdef OBJ
#   define	ERR_STRNGS	"/usr/lib/pi2.0strings"
#   define	ERR_PATHLEN	9
I 5
#   define	HOW_STRNGS	"/usr/lib/how_pi\0"
#   define	HOW_PATHLEN	9
E 5
#endif OBJ
#ifdef PC
#   define	ERR_STRNGS	"/usr/lib/pc2.0strings"
#   define	ERR_PATHLEN	9
I 5
#   define	HOW_STRNGS	"/usr/lib/how_pc\0"
#   define	HOW_PATHLEN	9
E 5
#endif PC
E 9

	    /*
	     *	these are because of varying sizes of pointers
	     */
D 11
#ifdef VAX
E 11
I 11
#ifdef ADDR16
#	define PTR_AS O_AS2
#	define PTR_RV O_RV2
#	define PTR_IND O_IND2
#	define PTR_CON O_CON2
#	define PTR_DUP O_SDUP2
#	define CON_INT O_CON2
#	define INT_TYP (nl + T2INT)
#	define PTR_DCL char *
#	define TOOMUCH 50000
#	define SHORTADDR 65536
#	define MAXSET 65536		/* maximum set size */
#endif ADDR16
#ifdef ADDR32
E 11
D 3
#	define INDX 2				/* log2 of sizeof( * ) */
E 3
#	define PTR_AS O_AS4
#	define PTR_RV O_RV4
#	define PTR_IND O_IND4
I 5
#	define PTR_CON O_CON4
#	define PTR_DUP O_SDUP4
I 6
#	define CON_INT O_CON24
#	define INT_TYP (nl + T4INT)
E 6
E 5
#	define PTR_DCL unsigned long		/* for pointer variables */
#	define SHORTADDR 32768			/* maximum short address */
#	define TOOMUCH 65536			/* maximum variable size */
#	define MAXSET 65536			/* maximum set size */
D 11
	    /*
	     * Offsets due to the structure of the runtime stack.
	     * DPOFF1	is the amount of fixed storage in each block allocated
	     * 		as local variables for the runtime system.
	     *		since locals are allocated negative offsets,
	     *		-DPOFF1 is the last used implicit local offset.
	     * DPOFF2	is the size of the block mark.
	     *		since arguments are allocated positive offsets,
	     *		DPOFF2 is the end of the implicit arguments.
	     *		for obj, the first argument has the highest offset
	     *		from the stackpointer.  and the block mark is an
	     *		implicit last parameter.
	     *		for pc, the first argument has the lowest offset
	     *		from the argumentpointer.  and the block mark is an
	     *		implicit first parameter.
	     */
E 11
I 11
#endif ADDR32
	/*
	 * Offsets due to the structure of the runtime stack.
	 * DPOFF1	is the amount of fixed storage in each block allocated
	 * 		as local variables for the runtime system.
	 *		since locals are allocated negative offsets,
	 *		-DPOFF1 is the last used implicit local offset.
	 * DPOFF2	is the size of the block mark.
	 *		since arguments are allocated positive offsets,
	 *		DPOFF2 is the end of the implicit arguments.
	 *		for obj, the first argument has the highest offset
	 *		from the stackpointer.  and the block mark is an
	 *		implicit last parameter.
	 *		for pc, the first argument has the lowest offset
	 *		from the argumentpointer.  and the block mark is an
	 *		implicit first parameter.
	 */
E 11
#	ifdef OBJ
D 11
#	    define DPOFF1		0
#	    define DPOFF2		32
#	    define INPUT_OFF		-8	/* offset of `input' */
#	    define OUTPUT_OFF		-4	/* offset of `output' */
E 11
I 11
#	    ifdef ADDR32
#		define MAGICNUM 0403	/* obj magic number */
#		define DPOFF1		0
#		define DPOFF2		(sizeof (struct blockmark))
#		define INPUT_OFF	-8	/* offset of `input' */
#		define OUTPUT_OFF	-4	/* offset of `output' */
#	    endif ADDR32
#	    ifdef ADDR16
#		define MAGICNUM 0404
#		define DPOFF1		0
#		define DPOFF2		(sizeof (struct blockmark))
#		define INPUT_OFF	-2
#		define OUTPUT_OFF	-4
#	    endif ADDR16
E 11
#	endif OBJ
#	ifdef	PC
D 10
#	    define DPOFF1	( sizeof rtlocs - sizeof rtlocs.unwind )
E 10
I 10
D 11
#	    define DPOFF1	( sizeof rtlocs )
E 10
#	    define DPOFF2	( sizeof (long) )
E 11
I 11
#	    define DPOFF1	( sizeof (struct rtlocals) )
#	    define DPOFF2	( sizeof (struct blockmark) )
E 11
#	    define INPUT_OFF	0
#	    define OUTPUT_OFF	0
#	endif PC
D 11
#	define MAGICNUM 0403			/* obj magic number */
#endif VAX

#ifdef PDP11
D 3
#	define INDX 1
E 3
#	define PTR_AS O_AS2
#	define PTR_RV O_RV2
#	define PTR_IND O_IND2
I 5
#	define PTR_CON O_CON2
#	define PTR_DUP O_SDUP2
I 6
#	define CON_INT O_CON2
#	define INT_TYP (nl + T2INT)
E 6
E 5
#	define PTR_DCL char *
#	define TOOMUCH 50000
#	define SHORTADDR 65536
D 5
#	define MAXSET 65536			/* maximum set size */
#	define DPOFF2 16
E 5
I 5
#	define MAXSET 65536		/* maximum set size */
#	define DPOFF1 0
#	define DPOFF2 18		/* sizeof(struct stack) */
E 5
#	define INPUT_OFF -2
#	define OUTPUT_OFF -4
#	define MAGICNUM 0404
#endif PDP11
E 11
E 1
