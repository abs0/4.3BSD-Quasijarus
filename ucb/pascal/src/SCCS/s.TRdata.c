h30410
s 00007/00003/00207
d D 5.1 85/06/04 11:34:06 dist 5 4
c Add copyright
e
s 00000/00000/00210
d D 2.1 84/02/08 20:40:51 aoki 4 3
c synchronize to version 2
e
s 00000/00000/00210
d D 1.3 83/09/19 06:57:29 thien 3 2
c Restoring to unlinted version
e
s 00009/00003/00201
d D 1.2 83/08/19 04:55:01 thien 2 1
c The changes were made to allow successful linting
e
s 00204/00000/00000
d D 1.1 80/08/27 19:54:36 peter 1 0
c date and time created 80/08/27 19:54:36 by peter
e
u
U
t
T
I 1
D 5
/* Copyright (c) 1979 Regents of the University of California */
E 5
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 5

I 2
#ifndef lint
E 2
D 5
static	char sccsid[] = "%Z%%M% %I% %G%";
I 2
#endif
E 5
I 5
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 5
E 2

#include "whoami.h"
#include "0.h"
#ifdef	PI1
#ifdef	DEBUG
D 2
char	*trnames[]
E 2
I 2
char	*trnames[] =
E 2
{
	0,
	"MINUS",
	"MOD",
	"DIV",
	"DIVD",
	"MULT",
	"ADD",
	"SUB",
	"EQ",
	"NE",
	"LT",
	"GT",
	"LE",
	"GE",
	"NOT",
	"AND",
	"OR",
	"ASGN",
	"PLUS",
	"IN",
	"LISTPP",
	"PDEC",
	"FDEC",
	"PVAL",
	"PVAR",
	"PFUNC",
	"PPROC",
	"NIL",
	"STRNG",
	"CSTRNG",
	"PLUSC",
	"MINUSC",
	"ID",
	"INT",
	"FINT",
	"CINT",
	"CFINT",
	"TYPTR",
	"TYPACK",
	"TYSCAL",
	"TYRANG",
	"TYARY",
	"TYFILE",
	"TYSET",
	"TYREC",
	"TYFIELD",
	"TYVARPT",
	"TYVARNT",
	"CSTAT",
	"BLOCK",
	"BSTL",
	"LABEL",
	"PCALL",
	"FCALL",
	"CASE",
	"WITH",
	"WHILE",
	"REPEAT",
	"FORU",
	"FORD",
	"GOTO",
	"IF",
	"ASRT",
	"CSET",
	"RANG",
	"VAR",
	"ARGL",
	"ARY",
	"FIELD",
	"PTR",
	"WEXP",
	"PROG",
	"BINT",
	"CBINT",
	"IFEL",
	"IFX",
	"TYID",
	"COPSTR",
	"BOTTLE",
	"RFIELD",
	"FLDLST",
	"LAST"
};
#endif
#endif

D 2
char	*trdesc[]
E 2
I 2
#ifndef PC
#ifndef OBJ
char	*trdesc[] =
E 2
{
	0,
	"dp",
	"dpp",
	"dpp",
	"dpp",
	"dpp",
	"dpp",
	"dpp",
	"dpp",
	"dpp",
	"dpp",
	"dpp",
	"dpp",
	"dpp",
	"dp",
	"dpp",
	"dpp",
	"npp",
	"dp",
	"dpp",
	"pp",
	"n\"pp",
	"n\"pp",
	"pp",
	"pp",
	"pp",
	"p",
	"d",
	"dp",
	"p",
	"p",
	"p",
	"p",
	"dp",
	"dp",
	"p",
	"p",
	"np",
	"np",
	"np",
	"npp",
	"npp",
	"np",
	"np",
	"np",
	"pp",
	"nppp",
	"npp",
	"npp",
	"np",
	"np",
	"n\"p",
	"n\"p",
	"n\"p",
	"npp",
	"npp",
	"npp",
	"npp",
	"nppp",
	"nppp",
	"n\"",
	"nppp",
	"np",
	"dp",
	"pp",
	"n\"p",
	"p",
	"p",
	"pp",
	"",
	"ppp",
	"n\"pp",
	"dp",
	"p",
	"nppp",
	"nppp",
	"np",
	"s",
	"nnnnn",
	"npp",
	"npp",
	"x"
};
D 2
char	*opnames[]
E 2
I 2
#endif
#endif
char	*opnames[] =
E 2
{
	0,
	"unary -",
	"mod",
	"div",
	"/",
	"*",
	"+",
	"-",
	"=",
	"<>",
	"<",
	">",
	"<=",
	">=",
	"not",
	"and",
	"or",
	":=",
	"unary +",
	"in"
};
E 1
