h51190
s 00004/00004/00018
d D 5.2 88/01/03 00:33:28 bostic 4 3
c neither K&R or ANSI C allow untyped function declarations
e
s 00007/00003/00015
d D 5.1 85/06/06 16:13:50 dist 3 2
c Add copyright
e
s 00001/00001/00017
d D 1.2 82/01/18 22:15:23 linton 2 1
c sccsid
e
s 00018/00000/00000
d D 1.1 82/01/18 19:02:57 linton 1 0
c date and time created 82/01/18 19:02:57 by linton
e
u
U
t
T
I 1
D 3
/* Copyright (c) 1982 Regents of the University of California */

D 2
static char sccsid[] = "%Z%%M% %I% %G%";
E 2
I 2
/* static char sccsid[] = "%Z%%M% %I% %G%"; */
E 3
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 3
E 2

/*
 * Public definitions for symbol table.
 */

SYMTAB *symtab;

SYMTAB *st_creat();		/* create a symbol table */
D 4
st_destroy();			/* destroy a symbol table, i.e. free storage */
E 4
I 4
int st_destroy();		/* destroy a symbol table, i.e. free storage */
E 4
SYM *st_insert();		/* insert a symbol */
SYM *st_lookup();		/* lookup a symbol */
D 4
dumpvars();			/* dump the symbols of a function */
print_alias();			/* print out currently active aliases */
enter_alias();			/* create a new name for a command */
E 4
I 4
int dumpvars();			/* dump the symbols of a function */
int print_alias();		/* print out currently active aliases */
int enter_alias();		/* create a new name for a command */
E 4
SYM *findtype();		/* search symbol table for a type name */
E 1
