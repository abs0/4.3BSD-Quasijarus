h39834
s 00008/00002/00075
d D 5.1 85/06/06 15:56:52 dist 4 3
c Add copyright
e
s 00001/00001/00076
d D 1.3 83/02/14 23:28:02 linton 3 2
c changed INDEX operator to handle multiple subscript arrays correctly
e
s 00002/00001/00075
d D 1.2 82/01/18 23:35:03 linton 2 1
c gripe
e
s 00076/00000/00000
d D 1.1 82/01/18 19:21:28 linton 1 0
c date and time created 82/01/18 19:21:28 by linton
e
u
U
t
T
I 1
D 4
/* Copyright (c) 1982 Regents of the University of California */
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 4

D 4
static char sccsid[] = "%Z%%M% %I% %G%";
E 4
I 4
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 4

/*
D 2
 * operator information structure
E 2
I 2
 * Operator information structure.
E 2
 */

#include "defs.h"
#include "opinfo.h"

OPINFO opinfo[] ={
/* O_NOP */		0,		0,
/* O_NAME */		LEAF,		0,
/* O_QNAME */		LEAF,		"$",
/* O_LCON */		LEAF,		0,
/* O_FCON */		LEAF,		0,
/* O_SCON */		LEAF,		0,
D 3
/* O_INDEX */		BINARY,		0,
E 3
I 3
/* O_INDEX */		UNARY,		0,
E 3
/* O_INDIR */		UNARY,		"^",
/* O_RVAL */		UNARY,		0,
/* O_COMMA */		BINARY,		",",
/* O_ITOF */		UNARY|INTOP,	0,
/* O_ADD */		BINARY|INTOP,	"+",
/* O_ADDF */		BINARY|REALOP,	"+",
/* O_SUB */		BINARY|INTOP,	"-",
/* O_SUBF */		BINARY|REALOP,	"-",
/* O_NEG */		UNARY|INTOP,	"-",
/* O_NEGF */		UNARY|REALOP,	"-",
/* O_MUL */		BINARY|INTOP,	"*",
/* O_MULF */		BINARY|REALOP,	"*",
/* O_DIVF */		BINARY|REALOP,	"/",
/* O_DIV */		BINARY|INTOP,	" div ",
/* O_MOD */		BINARY|INTOP,	" mod ",
/* O_AND */		BINARY|INTOP,	" and ",
/* O_OR */		BINARY|INTOP,	" or ",
/* O_LT */		BINARY|INTOP,	" < ",
/* O_LTF */		BINARY|REALOP,	" < ",
/* O_LE */		BINARY|INTOP,	" <= ",
/* O_LEF */		BINARY|REALOP,	" <= ",
/* O_GT */		BINARY|INTOP,	" > ",
/* O_GTF */		BINARY|REALOP,	" > ",
/* O_GE */		BINARY|INTOP,	" >= ",
/* O_GEF */		BINARY|REALOP,	" >= ",
/* O_EQ */		BINARY|INTOP,	" = ",
/* O_EQF */		BINARY|REALOP,	" = ",
/* O_NE */		BINARY|INTOP,	" <> ",
/* O_NEF */		BINARY|REALOP,	" <> ",
/* O_ASSIGN */		BINARY,		" := ",
/* O_CHFILE */		0,		NIL,
/* O_CONT */		0,		NIL,
/* O_LIST */		0,		NIL,
/* O_NEXT */		0,		NIL,
/* O_PRINT */		0,		NIL,
/* O_STEP */		0,		NIL,
/* O_WHATIS */		0,		NIL,
/* O_WHERE */		0,		NIL,
/* O_XI */			0,		NIL,
/* O_XD */			0,		NIL,
/* O_CALL */		0,		NIL,
/* O_EDIT */		0,		NIL,
/* O_DUMP */		0,		NIL,
/* O_HELP */		0,		NIL,
/* O_REMAKE */		0,		NIL,
/* O_RUN */		0,		NIL,
/* O_SOURCE */		0,		NIL,
/* O_STATUS */		0,		NIL,
/* O_TRACE */		0,		NIL,
/* O_TRACEI */		0,		NIL,
/* O_STOP */		0,		NIL,
/* O_STOPI */		0,		NIL,
/* O_DELETE */		0,		NIL,
/* O_WHICH */		0,		NIL,
/* O_QLINE */		LEAF,		NIL,
/* O_ALIAS */		LEAF,		NIL,
I 2
/* O_GRIPE */		0,		NIL,
E 2
};
E 1
