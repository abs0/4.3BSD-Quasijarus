h63496
s 00008/00002/00336
d D 5.1 85/06/05 15:58:05 dist 9 8
c Add copyright
e
s 00002/00002/00336
d D 2.3 85/05/13 15:06:39 mckusick 8 7
c increase static table sizes; we should eliminate these static tables!
e
s 00009/00002/00329
d D 2.2 85/01/09 18:18:45 mckusick 7 6
c changes to work with `linted' code
e
s 00000/00000/00331
d D 2.1 84/02/08 20:21:17 aoki 6 5
c synchronizing at version 2
e
s 00022/00003/00309
d D 1.5 83/05/31 18:40:45 peter 5 4
c bigger machines get to have bigger tables.
e
s 00011/00000/00301
d D 1.4 83/05/12 13:53:08 peter 4 3
c -O option for rmothers.
e
s 00001/00000/00300
d D 1.3 83/02/06 13:17:38 mckusick 3 2
c add continuation() output mode
e
s 00002/00000/00298
d D 1.2 83/02/05 17:28:23 mckusick 2 1
c add bool type for compatability with ../src
e
s 00298/00000/00000
d D 1.1 81/03/02 21:27:47 peter 1 0
c date and time created 81/03/02 21:27:47 by peter
e
u
U
t
T
I 1
D 9
/* static	char *sccsid = "%W% (Berkeley) %G%";*/
/* Copyright (c) 1979 Regents of the University of California */
E 9
I 9
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

E 9
/* #define DEBUG */
#define	CHAR
#define	STATIC
/*
 * pxp - Pascal execution profiler
 *
 * Bill Joy
 * University of California, Berkeley (UCB)
 * Version 1.1 February 1978
 */

/*
 * Option flags
 *
 * The following options are recognized on the command line by pxp.
 * Only the u, w, and z options here have effect in comments in the
 * program; the others are command line only, and unrelated
 * to the options with the same designations in comments.
 *
 *	a	Print all routines in a profile; normally, routines
 *		which have never been executed have their bodies suppressed.
 *
 *	c	Extract profile data from the file core, or the file
 *		named after the last argument rather than the file 'pmon.out'.
 *		Must be used with z to have an effect.
 *
 *	d	Suppress declarations
 *
 *	f	Fully parenthesize expressions.
 *
 *	j	Left justify all procedures and functions rather than
 *		indenting them.
 *
 *	n	Eject a new page in the listing as each 'include' file
 *		is incorporated into the profile.
 *
 *	o	Put output prettyprint in first argument file
 *
 *	p	Pretty print a main program without processing
 *		the include statements.
 *
 *	t	Print a table summarizing procedure and function call counts.
 *
 *	u	Card image mode; only the first 72 chars on a line count.
 *
 *	w	Suppress certain warning diagnostics.
 *
 *	z	Generate an execution profile of the program.
 *		May also be followed by a list of procedure and function
 *		names mixed, if desired, with include file names.
 *		Only these procedures and functions, and the contents
 *		of the specified include files will then be profiled.
 *
 *  [23456789]	Use the specified number of spaces for the basic
 *		indenting unit in the program.
 *
 *	_	Underline keywords in the output.
I 4
 *
 *	O	remove `others'.  if an `others' label is found in a
 *		case statement the case statement (minus the others case)
 *		is printed as a guarded case statement, and the others case
 *		is the else branch of the guard.  this transformation
 *		causes the case selector to be evaluated twice, a lose
 *		if the selector has side-effects.  this option is only
 *		available if pxp is compiled with RMOTHERS defined.
E 4
 */

char	all, core, nodecl, full, justify, pmain, stripcomm, table, underline;
char	profile, onefile;
I 4
#ifdef RMOTHERS
char	rmothers;
#endif RMOTHERS
E 4
char	*firstname, *stdoutn;
#ifdef DEBUG
char	fulltrace, errtrace, testtrace, yyunique, typetest;
#endif
int	unit;

/*
 * The flag nojunk means that header lines
 * of procedures and functions are to be suppressed
 * when the z option is off.
 * It is the default when command line z option
 * control is specified.
 *
 * The flag noinclude indicates that include statements are not
 * to be processed since we are pretty-printing the contents
 * of a single file.
 *
 * The flag bracket indicates that the source code should be
 * bracketed with lines of the form
 *	program x(output);
 * and
 *	begin end.
 * so that an include will pretty print without syntax errors.
 */
char	nojunk, noinclude, bracket;

/*
 * IMPORTANT NOTE
 *
 * Many of the following globals are shared by pi and pxp.
 * For more discussion of these see the available documentation
 * on the structure of pi.
 */

/*
 * Each option has a stack of 17 option values, with opts giving
 * the current, top value, and optstk the value beneath it.
 * One refers to option `l' as, e.g., opt('l') in the text for clarity.
 */
char	opts[26];
int	optstk[26];

#define opt(c) opts[c-'a']

/*
 * NOTES ON THE DYNAMIC NATURE OF THE DATA STRUCTURES
 *
 * Pxp uses expandable tables for its string table
 * hash table, and parse tree space.  The following
 * definitions specify the size of the increments
 * for these items in fundamental units so that
 * each uses approximately 1024 bytes.
 */

#define	STRINC	1024		/* string space increment */
D 8
#define	TRINC	512		/* tree space increment */
E 8
I 8
#define	TRINC	1024		/* tree space increment */
E 8
#define	HASHINC	509		/* hash table size in words, each increment */

/*
 * The initial sizes of the structures.
 * These should be large enough to profile
 * an "average" sized program so as to minimize
 * storage requests.
 * On a small system or and 11/34 or 11/40
 * these numbers can be trimmed to make the
 * profiler smaller.
 */
#define	ITREE	2000
#define	IHASH	509

/*
 * The following limits on hash and tree tables currently
 * allow approximately 1200 symbols and 20k words of tree
 * space.  The fundamental limit of 64k total data space
 * should be exceeded well before these are full.
 */
D 5
#define	MAXHASH	4
#define	MAXTREE	30
#define	MAXDEPTH 150
E 5
I 5
/*
 * TABLE_MULTIPLIER is for uniformly increasing the sizes of the tables
 */
#ifdef ADDR32
#define TABLE_MULTIPLIER	8
#endif ADDR32
#ifdef ADDR16
#define TABLE_MULTIPLIER	1
#endif ADDR16
#define	MAXHASH	(4 * TABLE_MULTIPLIER)
D 8
#define	MAXTREE	(30 * TABLE_MULTIPLIER)
E 8
I 8
#define	MAXTREE	(40 * TABLE_MULTIPLIER)
E 8
/*
 * MAXDEPTH is the depth of the parse stack.
 * STACK_MULTIPLIER is for increasing its size.
 */
#ifdef ADDR32
#define	STACK_MULTIPLIER	8
#endif ADDR32
#ifdef ADDR16
#define	STACK_MULTIPLIER	1
#endif ADDR16
#define	MAXDEPTH ( 150 * STACK_MULTIPLIER )
E 5

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

char	Recovery;
/*
 * The flag eflg is set whenever we have a hard error.
 * The character in errpfx will precede the next error message.
 */
int	eflg;
char	errpfx;

#define	setpfx(x)	errpfx = x

#define	standard()	setpfx('s')
#define	warning()	setpfx('w')
#define	recovered()	setpfx('e')
#define	quit()		setpfx('Q')
I 3
#define	continuation()	setpfx(' ')
E 3

/*
 * SEMANTIC DEFINITIONS
 */

#define	NIL	0

/*
 * NOCON and SAWCON are flags in the tree telling whether
 * a constant set is part of an expression.
 */
#define	NOCON	0
#define	SAWCON	1

/*
 * The variable cbn gives the current block number.
 * The variable lastbn gives the block number before
 * it last changed and is used to know that we were
 * in a nested procedure so that we can print
 *	begin { solve }
 * when solve has nested procedures or functions in it.
 */
int	cbn, lastbn;

/*
 * The variable line is the current semantic
 * line and is set in stat.c from the numbers
 * embedded in statement type tree nodes.
 */
int	line;

/*
 * The size of the display
 * which defines the maximum nesting
 * of procedures and functions allowed.
 */
#define	DSPLYSZ 20

/*
 * Routines which need types
 * other than "integer" to be
 * assumed by the compiler.
 */
D 7
int	*tree();
E 7
I 7
struct tnode	*tree();
char		*skipbl();
E 7
int	*hash();
char	*alloc();
long	cntof();
long	nowcnt();

/*
I 7
 *	type cast nils to keep lint happy.
 */
#define	TR_NIL	((struct tnode *) NIL)

/*
E 7
 * Funny structures to use
 * pointers in wild and wooly ways
 */
D 7
struct {
E 7
I 7
struct cstruct {
E 7
	char	pchar;
};
struct {
	int	pint;
	int	pint2;
};
struct {
	long	plong;
};
struct {
	double	pdouble;
};

#define	OCT	1
#define	HEX	2

/*
 * MAIN PROGRAM GLOBALS, MISCELLANY
 */

/*
 * Variables forming a data base referencing
 * the command line arguments with the "z" option.
 */
char	**pflist;
int	pflstc;
int	pfcnt;

char	*filename;		/* current source file name */
char	*lastname;		/* last file name printed */
long	tvec;			/* mod time of the source file */
long	ptvec;			/* time profiled */
char	printed;		/* current file has been printed */
char	hadsome;		/* had some output */

/*
 * PROFILING AND FORMATTING DEFINITIONS
 */

/*
 * The basic counter information recording structure.
 * This is global only because people outside
 * the cluster in pmon.c need to know its size.
 */
struct pxcnt {
	long	ntimes;		/* the count this structure is all about */
	int	counter;	/* a unique counter number for us */
	int	gos;		/* global goto count when we hatched */
	int	printed;	/* are we considered to have been printed? */
} pfcnts[DSPLYSZ];

/*
 * The pieces we divide the output line indents into:
 *	line#  PRFN  label:   STAT  999.---|  DECL   text
 */
#define	STAT	0
#define	DECL	1
#define	PRFN	2

/*
 * Gocnt records the total number of goto's and
 * cnts records the current counter for generating
 * COUNT operators.
 */
int	gocnt;
int	cnts;

#include <stdio.h>
I 7
#include <sys/types.h>
E 7

I 2
typedef enum {FALSE, TRUE} bool;

E 2
#undef putchar
E 1
