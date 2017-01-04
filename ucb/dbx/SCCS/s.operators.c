h31572
s 00008/00002/00219
d D 5.1 85/05/31 10:12:01 dist 11 10
c Add copyright
e
s 00022/00011/00199
d D 1.9 85/03/01 20:26:58 linton 10 9
c update to version 3.0
e
s 00001/00001/00209
d D 1.8 84/08/18 11:04:28 sam 9 8
c correct comment
e
s 00002/00002/00208
d D 1.7 84/08/12 13:22:17 sam 8 7
c add real aliases; rewrite lexical scanner
e
s 00001/00003/00209
d D 1.6 84/06/23 11:42:15 sam 7 5
i 6
c merge linton branch delta trail
e
s 00012/00002/00198
d D 1.4.1.1 84/06/23 10:48:23 sam 6 4
c branch delta of linton changes from net.sources
e
s 00002/00000/00200
d D 1.5 84/06/23 10:39:54 sam 5 4
c add re pattern search of source code
e
s 00002/00000/00198
d D 1.4 83/05/18 19:54:13 csvaf 4 3
c added DEBUG operator
e
s 00003/00000/00195
d D 1.3 83/02/20 15:32:43 linton 3 2
c added type-rename operator
e
s 00001/00001/00194
d D 1.2 82/12/15 04:21:21 linton 2 1
c fixed @(#) stuff
e
s 00195/00000/00000
d D 1.1 82/12/15 04:08:16 linton 1 0
c date and time created 82/12/15 04:08:16 by linton
e
u
U
f b 
t
T
I 1
D 11
/* Copyright (c) 1982 Regents of the University of California */
E 11
I 11
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 11

D 2
static char sccsid[] = "@(#)%Z%%M% %I% %G%";
E 2
I 2
D 6
static char sccsid[] = "%Z%%M% %I% %G%";
E 6
I 6
D 7
static char sccsid[] = "@(#)operators.c 1.4 5/18/83";
E 6
E 2

I 6
static char rcsid[] = "$Header: operators.c,v 1.3 84/03/27 10:22:38 linton Exp $";
E 7
I 7
D 11
static	char sccsid[] = "%W% (Berkeley) %G%";
E 11
I 11
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 11
E 7

I 10
static char rcsid[] = "$Header: operators.c,v 1.5 84/12/26 10:41:01 linton Exp $";

E 10
E 6
/*
 * Tree node classes.
 */

#include "defs.h"
#include "operators.h"

#ifndef public
typedef struct {
    char numargs;
    char opflags;
    String opstring;
} Opinfo;

typedef enum {
    O_NOP,
D 10
    O_NAME, O_SYM, O_LCON, O_FCON, O_SCON,
E 10
I 10
    O_NAME, O_SYM, O_LCON, O_CCON, O_FCON, O_SCON,
E 10
    O_RVAL, O_INDEX, O_INDIR, O_DOT,
    O_COMMA,

    O_ITOF, O_ADD, O_ADDF, O_SUB, O_SUBF, O_NEG, O_NEGF,
    O_MUL, O_MULF, O_DIVF, O_DIV, O_MOD,

    O_AND, O_OR,

    O_LT, O_LTF, O_LE, O_LEF, O_GT, O_GTF, O_GE, O_GEF,
    O_EQ, O_EQF, O_NE, O_NEF,

    O_ALIAS,		/* rename a command */
    O_ASSIGN,		/* assign a value to a program variable */
    O_CALL,		/* call a procedure in the program */
    O_CATCH,		/* catch a signal before program does */
    O_CHFILE,		/* change (or print) the current source file */
    O_CONT,		/* continue execution */
I 4
    O_DEBUG,		/* invoke a dbx internal debugging routine */
E 4
    O_DELETE,		/* remove a trace/stop */
    O_DUMP,		/* dump out variables */
    O_EDIT,		/* edit a file (or function) */
    O_FUNC,		/* set the current function */
    O_GRIPE,		/* send mail to debugger support person */
    O_HELP,		/* print a synopsis of debugger commands */
    O_IGNORE,		/* let program catch signal */
    O_LIST,		/* list source lines */
    O_PRINT,		/* print the values of a list of expressions */
    O_PSYM,		/* print symbol information */
    O_RUN,		/* start up program */
I 5
D 10
    O_SEARCH,		/* regular expression search of source file */
E 10
E 5
    O_SKIP,		/* skip the current line */
    O_SOURCE,		/* read commands from a file */
    O_STATUS,		/* display currently active trace/stop's */
    O_STEP,		/* execute a single line */
    O_STOP,		/* stop on an event */
    O_STOPI,		/* stop on an event at an instruction boundary */
    O_TRACE,		/* trace something on an event */
    O_TRACEI,		/* trace at the instruction level */
    O_WHATIS,		/* print the declaration of a variable */
    O_WHERE,		/* print a stack trace */
    O_WHEREIS,		/* print all the symbols with the given name */
    O_WHICH,		/* print out full qualification of a symbol */
    O_EXAMINE,		/* examine program instructions/data */

    O_ADDEVENT,		/* add an event */
    O_ENDX,		/* end of program reached */
    O_IF,		/* if first arg is true, do commands in second arg */
    O_ONCE,		/* add a "one-time" event, delete when first reached */
    O_PRINTCALL,	/* print out the current procedure and its arguments */
    O_PRINTIFCHANGED,	/* print the value of the argument if it has changed */
    O_PRINTRTN,		/* print out the routine and value that just returned */
    O_PRINTSRCPOS,	/* print out the current source position */
D 10
    O_PROCRTN,		/* CALLPROC completed */
E 10
I 10
    O_PROCRTN,		/* call completed */
E 10
    O_QLINE,		/* filename, line number */
    O_STOPIFCHANGED,	/* stop if the value of the argument has changed */
    O_STOPX,		/* stop execution */
    O_TRACEON,		/* begin tracing source line, variable, or all lines */
    O_TRACEOFF,		/* end tracing source line, variable, or all lines */

I 3
    O_TYPERENAME,	/* state the type of an expression */
I 6
    O_RERUN,		/* re-run program with the same arguments as before */
    O_RETURN,		/* continue execution until procedure returns */
    O_UP,		/* move current function up the call stack */
    O_DOWN,		/* move current function down the call stack */
I 10
    O_CALLPROC,		/* call command */
    O_SEARCH,		/* regular expression pattern search through source */
    O_SET,		/* set a debugger variable */
    O_UNSET,		/* unset a debugger variable */
    O_UNALIAS,		/* remove an alias */
E 10
E 6

E 3
    O_LASTOP
} Operator;

/*
 * Operator flags and predicates.
 */

#define null 0
#define LEAF 01
#define UNARY 02
#define BINARY 04
#define BOOL 010
#define REALOP 020
#define INTOP 040

#define isbitset(a, m)	((a&m) == m)
#define isleaf(o)	isbitset(opinfo[ord(o)].opflags, LEAF)
#define isunary(o)	isbitset(opinfo[ord(o)].opflags, UNARY)
#define isbinary(o)	isbitset(opinfo[ord(o)].opflags, BINARY)
#define isreal(o)	isbitset(opinfo[ord(o)].opflags, REALOP)
#define isint(o)	isbitset(opinfo[ord(o)].opflags, INTOP)
#define isboolean(o)	isbitset(opinfo[ord(o)].opflags, BOOL)

#define degree(o)	(opinfo[ord(o)].opflags&(LEAF|UNARY|BINARY))
#define nargs(o)	(opinfo[ord(o)].numargs)

#endif

/*
 * Operator information structure.
 */

public Opinfo opinfo[] ={
/* O_NOP */		0,	null,		0,
/* O_NAME */		-1,	LEAF,		0,
/* O_SYM */		-1,	LEAF,		0,
/* O_LCON */		-1,	LEAF,		0,
I 10
/* O_CCON */		-1,	LEAF,		0,
E 10
/* O_FCON */		-1,	LEAF,		0,
/* O_SCON */		-1,	LEAF,		0,
/* O_RVAL */		1,	UNARY,		0,
D 10
/* O_INDEX */		2,	BINARY,		0,
E 10
I 10
/* O_INDEX */		2,	null,		0,
E 10
/* O_INDIR */		1,	UNARY,		"^",
/* O_DOT */		2,	null,		".",
D 10
/* O_COMMA */		2,	BINARY,		",",
E 10
I 10
/* O_COMMA */		2,	null,		",",
E 10
/* O_ITOF */		1,	UNARY|INTOP,	0,
/* O_ADD */		2,	BINARY|INTOP,	"+",
/* O_ADDF */		2,	BINARY|REALOP,	"+",
/* O_SUB */		2,	BINARY|INTOP,	"-",
/* O_SUBF */		2,	BINARY|REALOP,	"-",
/* O_NEG */		1,	UNARY|INTOP,	"-",
/* O_NEGF */		1,	UNARY|REALOP,	"-",
/* O_MUL */		2,	BINARY|INTOP,	"*",
/* O_MULF */		2,	BINARY|REALOP,	"*",
/* O_DIVF */		2,	BINARY|REALOP,	"/",
/* O_DIV */		2,	BINARY|INTOP,	" div ",
/* O_MOD */		2,	BINARY|INTOP,	" mod ",
/* O_AND */		2,	BINARY|INTOP,	" and ",
/* O_OR */		2,	BINARY|INTOP,	" or ",
/* O_LT */		2,	BINARY|INTOP,	" < ",
/* O_LTF */		2,	BINARY|REALOP,	" < ",
/* O_LE */		2,	BINARY|INTOP,	" <= ",
/* O_LEF */		2,	BINARY|REALOP,	" <= ",
/* O_GT */		2,	BINARY|INTOP,	" > ",
/* O_GTF */		2,	BINARY|REALOP,	" > ",
/* O_GE */		2,	BINARY|INTOP,	" >= ",
/* O_GEF */		2,	BINARY|REALOP,	" >= ",
/* O_EQ */		2,	BINARY|INTOP,	" = ",
/* O_EQF */		2,	BINARY|REALOP,	" = ",
/* O_NE */		2,	BINARY|INTOP,	" <> ",
/* O_NEF */		2,	BINARY|REALOP,	" <> ",

/* O_ALIAS */		2,	null,		"alias",
D 10
/* O_ASSIGN */		2,	BINARY,		" := ",
E 10
I 10
/* O_ASSIGN */		2,	null,		" := ",
E 10
/* O_CALL */		2,	null,		"call",
D 8
/* O_CATCH */		0,	null,		"catch",
E 8
I 8
D 10
/* O_CATCH */		1,	null,		"catch",
E 10
I 10
/* O_CATCH */		0,	null,		"catch",
E 10
E 8
/* O_CHFILE */		0,	null,		"file",
/* O_CONT */		0,	null,		"cont",
I 4
/* O_DEBUG */		0,	null,		"debug",
E 4
D 6
/* O_DELETE */		0,	null,		"delete",
E 6
I 6
/* O_DELETE */		1,	null,		"delete",
E 6
D 10
/* O_DUMP */		0,	null,		"dump",
E 10
I 10
/* O_DUMP */		1,	null,		"dump",
E 10
/* O_EDIT */		0,	null,		"edit",
/* O_FUNC */		1,	null,		"func",
/* O_GRIPE */		0,	null,		"gripe",
/* O_HELP */		0,	null,		"help",
D 8
/* O_IGNORE */		0,	null,		"ignore",
E 8
I 8
D 10
/* O_IGNORE */		1,	null,		"ignore",
E 10
I 10
/* O_IGNORE */		0,	null,		"ignore",
E 10
E 8
/* O_LIST */		2,	null,		"list",
/* O_PRINT */		1,	null,		"print",
/* O_PSYM */		1,	null,		"psym",
/* O_RUN */		0,	null,		"run",
I 5
D 10
/* O_SEARCH */		2,	null,		"search",
E 10
E 5
/* O_SKIP */		0,	null,		"skip",
/* O_SOURCE */		0,	null,		"source",
/* O_STATUS */		0,	null,		"status",
/* O_STEP */		0,	null,		"step",
/* O_STOP */		3,	null,		"stop",
/* O_STOPI */		3,	null,		"stopi",
/* O_TRACE */		3,	null,		"trace",
/* O_TRACEI */		3,	null,		"tracei",
/* O_WHATIS */		1,	null,		"whatis",
/* O_WHERE */		0,	null,		"where",
/* O_WHEREIS */		1,	null,		"whereis",
/* O_WHICH */		1,	null,		"which",
/* O_EXAMINE */		0,	null,		"examine",

/* O_ADDEVENT */	0,	null,		"when",
/* O_ENDX */		0,	null,		nil,
/* O_IF */		0,	null,		"if",
/* O_ONCE */		0,	null,		"once",
/* O_PRINTCALL */	1,	null,		"printcall",
/* O_PRINTIFCHANGED */	1,	null,		"printifchanged",
/* O_PRINTRTN */	1,	null,		"printrtn",
/* O_PRINTSRCPOS */	1,	null,		"printsrcpos",
/* O_PROCRTN */		1,	null,		"procrtn",
/* O_QLINE */		2,	null,		nil,
/* O_STOPIFCHANGED */	1,	null,		"stopifchanged",
/* O_STOPX */		0,	null,		"stop",
/* O_TRACEON */		1,	null,		"traceon",
/* O_TRACEOFF */	1,	null,		"traceoff",
I 3
D 9
/* O_TYPERENAME */	2,	UNARY,		"traceoff",
E 9
I 9
D 10
/* O_TYPERENAME */	2,	UNARY,		"typerename",
E 10
I 10
/* O_TYPERENAME */	2,	UNARY,		"type rename",
E 10
E 9
I 6
/* O_RERUN */		0,	null,		"rerun",
/* O_RETURN */		1,	null,		"return",
/* O_UP */		1,	UNARY,		"up",
/* O_DOWN */		1,	UNARY,		"down",
I 10
/* O_CALLPROC */	2,	null,		"call",
/* O_SEARCH */		2,	null,		"search",
/* O_SET */		2,	null,		"set",
/* O_UNSET */		1,	null,		"unset",
/* O_UNALIAS */		1,	null,		"unalias",
E 10
E 6
E 3
};
E 1
