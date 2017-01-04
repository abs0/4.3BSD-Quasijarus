h41314
s 00001/00000/00836
d D 5.2 85/06/20 17:18:22 mckusick 32 31
c get rid of unwanted macro from param.h
e
s 00007/00003/00829
d D 5.1 85/06/05 15:39:10 dist 31 30
c Add copyright
e
s 00002/00002/00830
d D 2.2 85/05/13 15:02:29 mckusick 30 29
c up the table sizes; should eliminate these static tables!
e
s 00000/00000/00832
d D 2.1 84/02/08 20:49:26 aoki 29 28
c synchronize to version 2
e
s 00002/00000/00830
d D 1.24 84/02/08 20:04:39 aoki 28 27
c add function declarations.
e
s 00003/00000/00827
d D 1.23 84/02/08 00:50:52 mckusick 27 26
c merge in conformant array code by Carol Nishizak
e
s 00000/00000/00827
d D 1.22 83/09/19 07:08:10 thien 26 25
c changing to unlinted source
e
s 00059/00011/00768
d D 1.21 83/08/19 05:06:39 thien 25 24
c Changed for linting
e
s 00000/00021/00779
d D 1.20 83/02/28 17:20:22 peter 24 23
c clean up temporary allocation, moving everything relevant to
c tmps.c and (new) tmps.h.  correctly emit LBRAC lines.  allocate registers
c from high to low.  put in data structures for multiple types of registers.
e
s 00000/00003/00800
d D 1.19 83/02/03 12:04:27 mckusick 23 22
c pTree.h include goes away to restore sanity
e
s 00008/00034/00795
d D 1.18 83/02/01 20:24:07 peter 22 21
c fix up some things while porting.
c moving things from 0.h to other .h files.
e
s 00014/00005/00815
d D 1.17 82/11/11 19:39:56 mckusick 21 20
c optimize display save/restore and setjmp() to be done only when needed.
e
s 00027/00015/00793
d D 1.16 82/10/19 20:41:58 peter 20 19
c c style alignment of variants within records.
e
s 00023/00045/00785
d D 1.15 82/08/26 18:47:14 mckusick 19 18
c convert namelist structure to use unions
e
s 00001/00000/00829
d D 1.14 82/03/29 15:28:50 peter 18 16
c add continuation() for continuation error messages not using cerror().
e
s 00001/00002/00827
d R 1.14 81/06/07 22:46:30 mckusic 17 16
c put display save area back into formal routine structure
e
s 00015/00011/00814
d D 1.13 81/06/01 12:52:39 peter 16 15
c add storage classes to namelist, and use them.
e
s 00004/00013/00821
d D 1.12 81/04/17 15:13:02 peter 15 14
c clean up forop.c
e
s 00028/00000/00806
d D 1.11 81/04/01 21:50:42 peter 14 13
c dynamically allocate display save areas before formal calls
e
s 00018/00002/00788
d D 1.10 81/03/26 17:27:41 peter 13 12
c fix up for variables in temporaries.
e
s 00003/00000/00787
d D 1.9 81/03/20 14:23:52 peter 12 11
c use cgenflg consistently; take out )#'s on pi code.
e
s 00008/00005/00779
d D 1.8 81/03/18 18:39:48 mckusic 11 7
c mods for new formal routine syntax
e
s 00007/00005/00779
d R 1.8 81/03/18 18:00:54 mckusic 10 7
c mods for new formal routine syntax
e
s 00003/00000/00784
d R 1.8 81/03/18 17:33:16 mckusic 9 7
c mods for new formal routine syntax
e
s 00002/00000/00784
d R 1.8 81/03/18 12:26:55 mckusic 8 7
c mods for new formal routine syntax
e
s 00003/00000/00781
d D 1.7 81/03/16 23:12:49 mckusic 7 6
c add fcompat(), parnam(), and tmpalloc() defs
e
s 00009/00000/00772
d D 1.6 81/03/16 18:12:04 mckusic 6 5
c add temporary register allocation
e
s 00010/00001/00762
d D 1.5 81/03/11 23:35:31 mckusic 5 4
c centralize temporary allocation in tmps.c
e
s 00020/00011/00743
d D 1.4 81/03/08 19:20:17 mckusic 4 3
c merge in onyx changes
e
s 00002/00000/00752
d D 1.3 80/10/03 01:07:10 peter 3 2
c Implement formal functions and procedures
e
s 00007/00006/00745
d D 1.2 80/09/02 22:05:20 peter 2 1
c interleaved declaration parts
e
s 00751/00000/00000
d D 1.1 80/08/27 19:54:05 peter 1 0
c date and time created 80/08/27 19:54:05 by peter
e
u
U
t
T
I 1
D 31
/* Copyright (c) 1979 Regents of the University of California */

D 4
/* static	char sccsid[] = "%Z%%M% %I% %G%"; */
E 4
I 4
/* static char sccsid[] = "%Z%%M% %I% %G%"; */
E 31
I 31
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 31
E 4

#define DEBUG
I 4
#define CONSETS
E 4
#define	CHAR
#define	STATIC
#define hp21mx 0

#include	<stdio.h>
#include	<sys/types.h>
I 32
#undef roundup
E 32

D 4
#define		bool	short
#define		TRUE	1
#define		FALSE	0
E 4
I 4
typedef enum {FALSE, TRUE} bool;
E 4

/*
 * Option flags
 *
 * The following options are recognized in the text of the program
 * and also on the command line:
 *
 *	b	block buffer the file output
 *
 *	i	make a listing of the procedures and functions in
 *		the following include files
 *
 *	l	make a listing of the program
 *
 *	n	place each include file on a new page with a header
 *
 *	p	disable post mortem and statement limit counting
 *
 *	t	disable run-time tests
 *
 *	u	card image mode; only first 72 chars of input count
 *
 *	w	suppress special diagnostic warnings
 *
 *	z	generate counters for an execution profile
 */
#ifdef DEBUG
bool	fulltrace, errtrace, testtrace, yyunique;
#endif DEBUG

/*
 * Each option has a stack of 17 option values, with opts giving
 * the current, top value, and optstk the value beneath it.
 * One refers to option `l' as, e.g., opt('l') in the text for clarity.
 */
char	opts[ 'z' - 'A' + 1];
short	optstk[ 'z' - 'A' + 1];

#define opt(c) opts[c-'A']

/*
 * Monflg is set when we are generating
 * a pxp profile.  this is set by the -z command line option.
 */
bool	monflg;

    /*
     *	profflag is set when we are generating a prof profile.
     *	this is set by the -p command line option.
     */
I 25
#ifdef PC
E 25
bool	profflag;
I 25
#endif
E 25


/*
 * NOTES ON THE DYNAMIC NATURE OF THE DATA STRUCTURES
 *
 * Pi uses expandable tables for
 * its namelist (symbol table), string table
 * hash table, and parse tree space.  The following
 * definitions specify the size of the increments
 * for these items in fundamental units so that
 * each uses approximately 1024 bytes.
 */

#define	STRINC	1024		/* string space increment */
D 30
#define	TRINC	512		/* tree space increment */
E 30
I 30
#define	TRINC	1024		/* tree space increment */
E 30
#define	HASHINC	509		/* hash table size in words, each increment */
#define	NLINC	56		/* namelist increment size in nl structs */

/*
 * The initial sizes of the structures.
 * These should be large enough to compile
 * an "average" sized program so as to minimize
 * storage requests.
 * On a small system or and 11/34 or 11/40
 * these numbers can be trimmed to make the
 * compiler smaller.
 */
#define	ITREE	2000
#define	INL	200
#define	IHASH	509

/*
 * The following limits on hash and tree tables currently
 * allow approximately 1200 symbols and 20k words of tree
 * space.  The fundamental limit of 64k total data space
 * should be exceeded well before these are full.
 */
/*
 * TABLE_MULTIPLIER is for uniformly increasing the sizes of the tables
 */
I 4
D 22
#ifdef VAX
E 22
I 22
#ifdef ADDR32
E 22
E 4
#define TABLE_MULTIPLIER	8
I 4
D 22
#else
E 22
I 22
#endif ADDR32
#ifdef ADDR16
E 22
#define TABLE_MULTIPLIER	1
D 22
#endif VAX
E 22
I 22
#endif ADDR16
E 22
E 4
#define	MAXHASH	(4 * TABLE_MULTIPLIER)
#define	MAXNL	(12 * TABLE_MULTIPLIER)
D 30
#define	MAXTREE	(30 * TABLE_MULTIPLIER)
E 30
I 30
#define	MAXTREE	(40 * TABLE_MULTIPLIER)
E 30
/*
 * MAXDEPTH is the depth of the parse stack.
 * STACK_MULTIPLIER is for increasing its size.
 */
I 4
D 22
#ifdef VAX
E 22
I 22
#ifdef ADDR32
E 22
E 4
#define	STACK_MULTIPLIER	8
I 4
D 22
#else
E 22
I 22
#endif ADDR32
#ifdef ADDR16
E 22
#define	STACK_MULTIPLIER	1
D 22
#endif VAX
E 22
I 22
#endif ADDR16
E 22
E 4
#define	MAXDEPTH ( 150 * STACK_MULTIPLIER )

/*
 * ERROR RELATED DEFINITIONS
 */

/*
 * Exit statuses to pexit
 *
 * AOK
 * ERRS		Compilation errors inhibit obj productin
 * NOSTART	Errors before we ever got started
 * DIED		We ran out of memory or some such
 */
#define	AOK	0
#define	ERRS	1
#define	NOSTART	2
#define	DIED	3

bool	Recovery;

D 25
#define	eholdnl()	Eholdnl = 1
#define	nocascade()	Enocascade = 1
E 25
I 25
#define	eholdnl()	Eholdnl = TRUE
#define	nocascade()	Enocascade = TRUE
E 25

bool	Eholdnl, Enocascade;


/*
 * The flag eflg is set whenever we have a hard error.
 * The character in errpfx will precede the next error message.
 * When cgenflg is set code generation is suppressed.
 * This happens whenver we have an error (i.e. if eflg is set)
 * and when we are walking the tree to determine types only.
 */
bool	eflg;
char	errpfx;

#define	setpfx(x)	errpfx = x

#define	standard()	setpfx('s')
#define	warning()	setpfx('w')
#define	recovered()	setpfx('e')
I 18
#define	continuation()	setpfx(' ')
E 18

D 4
bool	cgenflg;
E 4
I 4
int	cgenflg;
E 4


/*
 * The flag syneflg is used to suppress the diagnostics of the form
 *	E 10 a, defined in someprocedure, is neither used nor set
 * when there were syntax errors in "someprocedure".
 * In this case, it is likely that these warinings would be spurious.
 */
bool	syneflg;

/*
 * The compiler keeps its error messages in a file.
 * The variable efil is the unit number on which
 * this file is open for reading of error message text.
 * Similarly, the file ofil is the unit of the file
 * "obj" where we write the interpreter code.
 */
short	efil;
I 25

#ifdef OBJ
E 25
short	ofil;
I 25

E 25
short	obuf[518];
I 25
#endif
E 25

D 4
#define	elineoff()	Enoline++
#define	elineon()	Enoline = 0

E 4
bool	Enoline;
I 4
#define	elineoff()	Enoline = TRUE
#define	elineon()	Enoline = FALSE

E 4

/*
 * SYMBOL TABLE STRUCTURE DEFINITIONS
 *
 * The symbol table is henceforth referred to as the "namelist".
 * It consists of a number of structures of the form "nl" below.
 * These are contained in a number of segments of the symbol
 * table which are dynamically allocated as needed.
 * The major namelist manipulation routines are contained in the
 * file "nl.c".
 *
 * The major components of a namelist entry are the "symbol", giving
 * a pointer into the string table for the string associated with this
 * entry and the "class" which tells which of the (currently 19)
 * possible types of structure this is.
 *
 * Many of the classes use the "type" field for a pointer to the type
 * which the entry has.
 *
 * Other pieces of information in more than one class include the block
 * in which the symbol is defined, flags indicating whether the symbol
 * has been used and whether it has been assigned to, etc.
 *
 * A more complete discussion of the features of the namelist is impossible
 * here as it would be too voluminous.  Refer to the "PI 1.0 Implementation
 * Notes" for more details.
 */

/*
 * The basic namelist structure.
D 19
 * There are also two other variants, defining the real
 * field as longs or integers given below.
E 19
I 19
 * There is a union of data types defining the stored information
 * as pointers, integers, longs, or a double.
E 19
 *
 * The array disptab defines the hash header for the symbol table.
 * Symbols are hashed based on the low 6 bits of their pointer into
 * the string table; see the routines in the file "lookup.c" and also "fdec.c"
 * especially "funcend".
 */
I 5
D 19
extern struct	nl *Fp;
E 19
extern int	pnumcnt;

E 5
D 23
#ifdef PTREE
#   include	"pTree.h"
#endif PTREE
E 23
struct	nl {
	char	*symbol;
D 19
	char	class, nl_flags;
#ifdef PC
D 16
	char	ext_flags;	/* an extra flag is used for externals */
E 16
I 16
	char	extra_flags;	/* for where things are */
E 16
#endif PC
E 19
I 19
	char	info[4];
E 19
	struct	nl *type;
	struct	nl *chain, *nl_next;
D 11
	int	*ptr[4];
#ifdef PI
	int	entloc;
#endif PI
E 11
I 11
D 19
	int	value[5];
E 19
I 19
	union {
D 25
		int	*un_ptr[5];
		int	un_value[5];
		long	un_range[2];
		double	un_real;
E 25
I 25
		struct nl *un_ptr[5];
		int	   un_value[5];
		long	   un_range[2];
		double	   un_real;
I 27
		struct nl  *un_nptr[5];	/* Points to conformant array bounds */
E 27
E 25
	} nl_un;
E 19
E 11
#	ifdef PTREE
	    pPointer	inTree;
#	endif PTREE
D 19
} *nlp, *disptab[077+1];
E 19
I 19
};
E 19

D 19
extern struct nl nl[INL];
E 19
I 19
D 20
#define class info[0]
#define nl_flags info[1]
#define nl_block info[1]
#define extra_flags info[2]
E 20
I 20
#define class		info[0]
#define nl_flags	info[1]
#define nl_block	info[1]
#define extra_flags	info[2]
#define align_info	info[3]
E 20
E 19

D 19
struct {
	char	*symbol;
	char	class, nl_flags;
#ifdef PC
D 16
	char	ext_flags;
E 16
I 16
	char	extra_flags;
E 16
#endif
	struct	nl *type;
	struct	nl *chain, *nl_next;
	double	real;
};
E 19
I 19
D 20
#define range nl_un.un_range
#define value nl_un.un_value
#define ptr nl_un.un_ptr
#define real nl_un.un_real
E 20
I 20
#define range	nl_un.un_range
#define value	nl_un.un_value
#define ptr	nl_un.un_ptr
#define real	nl_un.un_real
I 27
#define nptr	nl_un.un_nptr	
E 27
E 20
E 19

D 19
struct {
	char	*symbol;
	char	class, nl_block;
#ifdef PC
D 16
	char	ext_flags;
E 16
I 16
	char	extra_flags;
E 16
#endif
	struct	nl *type;
	struct	nl *chain, *nl_next;
	long	range[2];
};
E 19
I 19
extern struct nl *nlp, *disptab[077+1], *Fp;
extern struct nl nl[INL];
E 19

D 19
struct {
	char	*symbol;
	char	class, nl_flags;
#ifdef PC
D 16
	char	ext_flags;
E 16
I 16
	char	extra_flags;
E 16
#endif
	struct	nl *type;
	struct	nl *chain, *nl_next;
D 4
	long	value[4];
E 4
I 4
D 11
	int	value[5];
E 11
I 11
	int	*ptr[4];
#ifdef PI
	int	entloc;
#endif PI
E 11
E 4
};
E 19
D 13

E 13
I 13

E 13
/*
 * NL FLAGS BITS
 *
 * Definitions of the usage of the bits in
 * the nl_flags byte. Note that the low 5 bits of the
 * byte are the "nl_block" and that some classes make use
 * of this byte as a "width".
 *
 * The only non-obvious bit definition here is "NFILES"
 * which records whether a structure contains any files.
 * Such structures are not allowed to be dynamically allocated.
 */
I 13

#define	BLOCKNO( flag )	( flag & 037 )
#define NLFLAGS( flag ) ( flag &~ 037 )

E 13
#define	NUSED	0100
#define	NMOD	0040
#define	NFORWD	0200
#define	NFILES	0200
D 13

E 13
#ifdef PC
#define NEXTERN 0001	/* flag used to mark external funcs and procs */
D 16
#endif
E 16
I 16
#define	NLOCAL	0002	/* variable is a local */
#define	NPARAM	0004	/* variable is a parameter */
#define	NGLOBAL	0010	/* variable is a global */
#define	NREGVAR	0020	/* or'ed in if variable is in a register */
I 21
#define NNLOCAL 0040	/* named local variable, not used in symbol table */
E 21
#endif PC
E 16
I 13

D 15
    /*
     *	magic values for forvar -> value[ NL_FORV ]
     *	value[ NL_FORV ] stores in its low byte
     *	the nl_flags byte of the loop variable.
     *	the top byte is another bunch of flags
     *	FORBOUND 	means it is a loop variable
     *	LOOPVAR		means it is a loop variable but it is not yet allocated
     *	TEMPBOUND	means it is a loop variable and it is in a temporary.
     */
#define	LOOPVAR		00400
#define	TEMPBOUND	01000
#define	FORBOUND	( LOOPVAR | TEMPBOUND )
E 15
I 15
/*
 * used to mark value[ NL_FORV ] for loop variables
 */
#define	FORVAR		1
E 15
E 13

/*
 * Definition of the commonly used "value" fields.
 * The most important one is NL_OFFS which gives
 * the offset of a variable in its stack mark.
 */
#define NL_OFFS	0

#define	NL_CNTR	1
I 11
#define NL_NLSTRT 2
#define	NL_LINENO 3
E 11
#define	NL_FVAR	3
I 11
D 19
#define	NL_FCHAIN 4
E 19
I 19
#define	NL_ENTLOC 4	/* FUNC, PROC - entry point */
#define	NL_FCHAIN 4	/* FFUNC, FPROC - ptr to formals */
E 19
E 11

#define NL_GOLEV 2
#define NL_GOLINE 3
#define NL_FORV 1
I 6
D 15
#define NL_SOFFS 4
E 15
E 6

D 20
#define	NL_FLDSZ 1
#define	NL_VARNT 2
#define	NL_VTOREC 2
#define	NL_TAG	3
E 20
I 20
    /*
     *	nlp -> nl_un.un_ptr[] subscripts for records
     *	NL_FIELDLIST	the chain of fixed fields of a record, in order.
     *			the fields are also chained through ptr[NL_FIELDLIST].
     *			this does not include the tag, or fields of variants.
     *	NL_VARNT	pointer to the variants of a record,
     *			these are then chained through the .chain field.
     *	NL_VTOREC	pointer from a VARNT to the RECORD that is the variant.
     *	NL_TAG		pointer from a RECORD to the tagfield
     *			if there are any variants.
     *	align_info	the alignment of a RECORD is in info[3].
     */
#define	NL_FIELDLIST	1
#define	NL_VARNT	2
#define	NL_VTOREC	2
#define	NL_TAG		3
/* and align_info is info[3].  #defined above */
E 20

D 4
#define	NL_ELABEL	3
E 4
I 4
D 19
#define	NL_ELABEL	4
E 19
I 19
#define	NL_ELABEL 4	/* SCAL - ptr to definition of enums */
E 19
E 4

/*
 * For BADUSE nl structures, NL_KINDS is a bit vector
 * indicating the kinds of illegal usages complained about
 * so far.  For kind of bad use "kind", "1 << kind" is set.
 * The low bit is reserved as ISUNDEF to indicate whether
 * this identifier is totally undefined.
 */
#define	NL_KINDS	0

#define	ISUNDEF		1
I 6

D 16
/*
 * Variables may reside on the stack as formals or as locals,
 * or as register temporaries
 */
E 16
I 16
    /*
     *	variables come in three flavors: globals, parameters, locals;
     *	they can also hide in registers, but that's a different flag
     */
E 16
#define PARAMVAR	1
#define LOCALVAR	2
D 16
#define REGVAR		3
E 16
I 16
#define	GLOBALVAR	3
I 21
#define	NAMEDLOCALVAR	4
E 21
E 16
E 6

/*
 * NAMELIST CLASSES
 *
 * The following are the namelist classes.
 * Different classes make use of the value fields
 * of the namelist in different ways.
 *
 * The namelist should be redesigned by providing
 * a number of structure definitions with one corresponding
 * to each namelist class, ala a variant record in Pascal.
 */
#define	BADUSE	0
#define	CONST	1
#define	TYPE	2
#define	VAR	3
#define	ARRAY	4
#define	PTRFILE	5
#define	RECORD	6
#define	FIELD	7
#define	PROC	8
#define	FUNC	9
#define	FVAR	10
#define	REF	11
#define	PTR	12
#define	FILET	13
#define	SET	14
#define	RANGE	15
#define	LABEL	16
#define	WITHPTR 17
#define	SCAL	18
#define	STR	19
#define	PROG	20
#define	IMPROPER 21
#define	VARNT	22
I 3
#define	FPROC	23
#define	FFUNC	24
I 27
#define CRANGE	25
E 27
E 3

/*
 * Clnames points to an array of names for the
 * namelist classes.
 */
char	**clnames;

/*
 * PRE-DEFINED NAMELIST OFFSETS
 *
 * The following are the namelist offsets for the
 * primitive types. The ones which are negative
 * don't actually exist, but are generated and tested
 * internally. These definitions are sensitive to the
 * initializations in nl.c.
 */
#define	TFIRST -7
#define	TFILE  -7
#define	TREC   -6
#define	TARY   -5
#define	TSCAL  -4
#define	TPTR   -3
#define	TSET   -2
#define	TSTR   -1
#define	NIL	0
#define	TBOOL	1
#define	TCHAR	2
#define	TINT	3
#define	TDOUBLE	4
#define	TNIL	5
#define	T1INT	6
#define	T2INT	7
#define	T4INT	8
#define	T1CHAR	9
#define	T1BOOL	10
#define	T8REAL	11
#define TLAST	11

/*
 * SEMANTIC DEFINITIONS
 */

/*
 * NOCON and SAWCON are flags in the tree telling whether
 * a constant set is part of an expression.
I 12
 *	these are no longer used,
 *	since we now do constant sets at compile time.
E 12
 */
#define NOCON	0
#define SAWCON	1

/*
 * The variable cbn gives the current block number,
 * the variable bn is set as a side effect of a call to
 * lookup, and is the block number of the variable which
 * was found.
 */
short	bn, cbn;

/*
 * The variable line is the current semantic
 * line and is set in stat.c from the numbers
 * embedded in statement type tree nodes.
 */
short	line;

/*
 * The size of the display
 * which defines the maximum nesting
 * of procedures and functions allowed.
 * Because of the flags in the current namelist
 * this must be no greater than 32.
 */
#define	DSPLYSZ 20
D 22

I 14
    /*
     *	the display is made up of saved AP's and FP's.
     *	FP's are used to find locals, and AP's are used to find parameters.
     *	FP and AP are untyped pointers, but are used throughout as (char *).
     *	the display is used by adding AP_OFFSET or FP_OFFSET to the 
     *	address of the approriate display entry.
     */
struct dispsave {
    char	*savedAP;
    char	*savedFP;
} display[ DSPLYSZ ];

#define	AP_OFFSET	( 0 )
#define FP_OFFSET	( sizeof(char *) )

    /*
     *	formal routine structure:
     */
struct formalrtn {
	long		(*fentryaddr)();	/* formal entry point */
	long		fbn;			/* block number of function */
	struct dispsave	fdisp[ DSPLYSZ ];	/* saved at first passing */
} frtn;

#define	FENTRYOFFSET	0
#define FBNOFFSET	( FENTRYOFFSET + sizeof frtn.fentryaddr )
#define	FDISPOFFSET	( FBNOFFSET + sizeof frtn.fbn )
E 22

E 14
D 24
/*
 * The following structure is used
 * to keep track of the amount of variable
 * storage required by each block.
 * "Max" is the high water mark, "off"
 * the current need. Temporaries for "for"
 * loops and "with" statements are allocated
 * in the local variable area and these
 * numbers are thereby changed if necessary.
 */
struct om {
D 5
	long	om_off;
E 5
	long	om_max;
I 5
	long	reg_max;
	struct tmps {
		long	om_off;
		long	reg_off;
	} curtmps;
E 5
} sizes[DSPLYSZ];
I 5
#define NOREG 0
#define REGOK 1
E 5

E 24
    /*
     *	the following structure records whether a level declares
     *	any variables which are (or contain) files.
     *	this so that the runtime routines for file cleanup can be invoked.
     */
bool	dfiles[ DSPLYSZ ];

/*
 * Structure recording information about a constant
 * declaration.  It is actually the return value from
 * the routine "gconst", but since C doesn't support
 * record valued functions, this is more convenient.
 */
struct {
	struct nl	*ctype;
	short		cival;
	double		crval;
D 25
	int		*cpval;
E 25
I 25
	char		*cpval;	/* note used to be int * */
E 25
} con;

/*
 * The set structure records the lower bound
 * and upper bound with the lower bound normalized
 * to zero when working with a set. It is set by
 * the routine setran in var.c.
 */
struct {
	short	lwrb, uprbp;
} set;

    /*
     *	structures of this kind are filled in by precset and used by postcset
     *	to indicate things about constant sets.
     */
struct csetstr {
    struct nl	*csettype;
    long	paircnt;
    long	singcnt;
    bool	comptime;
};
/*
 * The following flags are passed on calls to lvalue
 * to indicate how the reference is to affect the usage
 * information for the variable being referenced.
 * MOD is used to set the NMOD flag in the namelist
 * entry for the variable, ASGN permits diagnostics
 * to be formed when a for variable is assigned to in
 * the range of the loop.
 */
#define	NOFLAGS	0
#define	MOD	01
#define	ASGN	02
#define	NOUSE	04

    /*
     *	the following flags are passed to lvalue and rvalue
     *	to tell them whether an lvalue or rvalue is required.
     *	the semantics checking is done according to the function called,
     *	but for pc, lvalue may put out an rvalue by indirecting afterwards,
     *	and rvalue may stop short of putting out the indirection.
     */
#define	LREQ	01
#define	RREQ	02

double	MAXINT;
double	MININT;

/*
 * Variables for generation of profile information.
 * Monflg is set when we want to generate a profile.
 * Gocnt record the total number of goto's and
 * cnts records the current counter for generating
 * COUNT operators.
 */
short	gocnt;
short	cnts;

/*
 * Most routines call "incompat" rather than asking "!compat"
 * for historical reasons.
 */
#define incompat 	!compat

/*
 * Parts records which declaration parts have been seen.
D 2
 * The grammar allows the "const" "type" and "var"
E 2
I 2
 * The grammar allows the "label" "const" "type" "var" and routine
E 2
 * parts to be repeated and to be in any order, so that
 * they can be detected semantically to give better
 * error diagnostics.
I 21
 *
 * The flag NONLOCALVAR indicates that a non-local var has actually
 * been used hence the display must be saved; NONLOCALGOTO indicates
 * that a non-local goto has been done hence that a setjmp must be done.
E 21
 */
D 2
short	parts;
E 2
I 2
int	parts[ DSPLYSZ ];
E 2

D 2
#define	LPRT	01
#define	CPRT	02
#define	TPRT	04
#define	VPRT	08
E 2
I 2
D 21
#define	LPRT	1
#define	CPRT	2
#define	TPRT	4
#define	VPRT	8
#define	RPRT	16
E 21
I 21
#define	LPRT		0x0001
#define	CPRT		0x0002
#define	TPRT		0x0004
#define	VPRT		0x0008
#define	RPRT		0x0010

#define	NONLOCALVAR	0x0020
#define	NONLOCALGOTO	0x0040
E 21
E 2

/*
 * Flags for the "you used / instead of div" diagnostic
 */
bool	divchk;
bool	divflg;

D 4
short	errcnt[DSPLYSZ];
E 4
I 4
bool	errcnt[DSPLYSZ];
E 4

/*
 * Forechain links those types which are
 *	^ sometype
 * so that they can be evaluated later, permitting
 * circular, recursive list structures to be defined.
 */
struct	nl *forechain;

/*
 * Withlist links all the records which are currently
 * opened scopes because of with statements.
 */
struct	nl *withlist;

struct	nl *intset;
struct	nl *input, *output;
struct	nl *program;

/* progseen flag used by PC to determine if
 * a routine segment is being compiled (and
 * therefore no program statement seen)
 */
bool	progseen;


/*
 * STRUCTURED STATEMENT GOTO CHECKING
 *
 * The variable level keeps track of the current
 * "structured statement level" when processing the statement
 * body of blocks.  This is used in the detection of goto's into
 * structured statements in a block.
 *
 * Each label's namelist entry contains two pieces of information
 * related to this check. The first `NL_GOLEV' either contains
 * the level at which the label was declared, `NOTYET' if the label
 * has not yet been declared, or `DEAD' if the label is dead, i.e.
 * if we have exited the level in which the label was defined.
 *
 * When we discover a "goto" statement, if the label has not
 * been defined yet, then we record the current level and the current line
 * for a later error check.  If the label has been already become "DEAD"
 * then a reference to it is an error.  Now the compiler maintains,
 * for each block, a linked list of the labels headed by "gotos[bn]".
 * When we exit a structured level, we perform the routine
 * ungoto in stat.c. It notices labels whose definition levels have been
 * exited and makes them be dead. For labels which have not yet been
 * defined, ungoto will maintain NL_GOLEV as the minimum structured level
 * since the first usage of the label. It is not hard to see that the label
 * must eventually be declared at this level or an outer level to this
 * one or a goto into a structured statement will exist.
 */
short	level;
struct	nl *gotos[DSPLYSZ];

#define	NOTYET	10000
#define	DEAD	10000

/*
 * Noreach is true when the next statement will
 * be unreachable unless something happens along
 * (like exiting a looping construct) to save
 * the day.
 */
bool	noreach;

/*
 * UNDEFINED VARIABLE REFERENCE STRUCTURES
 */
struct	udinfo {
	int	ud_line;
	struct	udinfo *ud_next;
	char	nullch;
};

/*
 * CODE GENERATION DEFINITIONS
 */

/*
 * NSTAND is or'ed onto the abstract machine opcode
 * for non-standard built-in procedures and functions.
 */
#define	NSTAND	0400

#define	codeon()	cgenflg++
#define	codeoff()	--cgenflg
I 12
#define	CGENNING	( cgenflg >= 0 )
E 12

/*
 * Codeline is the last lino output in the code generator.
 * It used to be used to suppress LINO operators but no
 * more since we now count statements.
 * Lc is the intepreter code location counter.
 *
short	codeline;
 */
I 25
#ifdef OBJ
E 25
char	*lc;
I 25
#endif
E 25


/*
 * Routines which need types
 * other than "integer" to be
 * assumed by the compiler.
 */
double		atof();
long		lwidth();
I 4
long		leven();
E 4
long		aryconst();
long		a8tol();
I 4
long		roundup();
I 7
D 16
long		tmpalloc();
E 16
I 16
struct nl 	*tmpalloc();
E 16
E 7
E 4
struct nl 	*lookup();
double		atof();
D 25
int		*tree();
E 25
int		*hash();
char		*alloc();
D 25
int		*calloc();
E 25
I 25
int		*pcalloc();
E 25
char		*savestr();
I 25
char 		*esavestr();
E 25
I 7
char		*parnam();
I 25
char		*malloc();
char		*getlab();
char		*getnext();
char		*skipbl();
char		*nameof();
char 		*pstrcpy();
char		*myctime();
char		*putlab();
E 25
bool		fcompat();
I 25
bool 		constval();
bool		precset();
bool		nilfnil();
struct nl	*funccod();
struct nl	*pcfunccod();
E 25
E 7
struct nl	*lookup1();
struct nl	*hdefnl();
struct nl	*defnl();
I 25
struct nl	*flvalue();
struct nl	*plist();
E 25
struct nl	*enter();
struct nl	*nlcopy();
D 20
struct nl	*tyrecl();
E 20
I 20
struct nl	*tyrec();
E 20
struct nl	*tyary();
I 25
struct nl	*tyrang();
struct nl	*tyscal();
E 25
D 20
struct nl	*fields();
struct nl	*variants();
E 20
struct nl	*deffld();
I 25
struct nl	*stklval();
struct nl	*scalar();
struct nl	*gen();
struct nl	*stkrval();
struct nl	*funcext();
struct nl	*funchdr();
struct nl	*funcbody();
struct nl 	*yybaduse();
struct nl	*stackRV();
E 25
struct nl	*defvnt();
struct nl	*tyrec1();
struct nl	*reclook();
struct nl	*asgnop1();
I 28
struct nl	*pcasgconf();
E 28
struct nl	*gtype();
struct nl	*call();
struct nl	*lvalue();
I 25
struct nl	*pclvalue();
E 25
struct nl	*rvalue();
struct nl	*cset();
I 28
struct nl	*tycrang();
E 28
I 25
struct tnode	*newlist();
struct tnode	*addlist();
struct tnode	*fixlist();
struct tnode	*setupvar();
struct tnode	*setuptyrec();
struct tnode	*setupfield();
struct tnode	*tree();
struct tnode	*tree1();
struct tnode	*tree2();
struct tnode	*tree3();
struct tnode	*tree4();
struct tnode	*tree5();
E 25

/*
 * type cast NIL to keep lint happy (which is not so bad)
 */
#define		NLNIL	( (struct nl *) NIL )
I 25
#define		TR_NIL	( (struct tnode *) NIL)
E 25

/*
 * Funny structures to use
 * pointers in wild and wooly ways
 */
D 25
struct {
E 25
I 25
struct cstruct{
E 25
	char	pchar;
};
struct {
	short	pint;
	short	pint2;
};
D 25
struct {
E 25
I 25
struct lstruct {
E 25
	long	plong;
};
struct {
	double	pdouble;
};

#define	OCT	1
#define	HEX	2

/*
 * MAIN PROGRAM VARIABLES, MISCELLANY
 */

/*
 * Variables forming a data base referencing
 * the command line arguments with the "i" option, e.g.
 * in "pi -i scanner.i compiler.p".
 */
char	**pflist;
short	pflstc;
short	pfcnt;

char	*filename;		/* current source file name */
long	tvec;
extern char	*snark;		/* SNARK */
extern char	*classes[ ];	/* maps namelist classes to string names */

#define	derror error

#ifdef	PC

    /*
     *	the current function number, for [ lines
     */
    int	ftnno;

    /*
     *	the pc output stream
     */
    FILE *pcstream;

#endif PC
E 1
