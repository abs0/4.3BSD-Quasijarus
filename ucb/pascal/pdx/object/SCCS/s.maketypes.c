h42326
s 00008/00002/00044
d D 5.1 85/06/06 11:30:19 dist 2 1
c Add copyright
e
s 00046/00000/00000
d D 1.1 82/01/18 19:20:38 linton 1 0
c date and time created 82/01/18 19:20:38 by linton
e
u
U
t
T
I 1
D 2
/* Copyright (c) 1982 Regents of the University of California */
E 2
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 2

D 2
static char sccsid[] = "%Z%%M% %I% %G%";
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 2

/*
 * make symbols
 */

#include "defs.h"
#include "sym.h"
#include "symtab.h"
#include "sym/btypes.h"
#include "sym/classes.h"
#include "sym/sym.rep"

/*
 * point the basic types in the right direction
 */

maketypes()
{
	t_int = st_lookup(symtab, "integer")->type;
	t_real = st_lookup(symtab, "real")->type;
	t_char = st_lookup(symtab, "char")->type;
	t_boolean = st_lookup(symtab, "boolean")->type;
	if (t_int==NIL || t_real==NIL || t_char==NIL || t_boolean==NIL) {
		panic("basic types are missing from namelist");
	}
}

/*
 * enter a keyword in the given table
 */

make_keyword(table, name, tnum)
SYMTAB *table;
char *name;
int tnum;
{
	register SYM *s;

	s = st_insert(table, name);
	s->class = BADUSE;
	s->blkno = 0;
	s->symvalue.token.toknum = tnum;
}
E 1
