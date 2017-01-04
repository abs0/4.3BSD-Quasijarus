h49412
s 00012/00012/00050
d D 5.3 88/01/03 00:33:26 bostic 6 5
c neither K&R or ANSI C allow untyped function declarations
e
s 00001/00001/00061
d D 5.2 87/04/07 15:51:38 mckusick 5 4
c port for tahoe from Nir peleg of CCI
e
s 00007/00003/00055
d D 5.1 85/06/06 16:11:51 dist 4 3
c Add copyright
e
s 00001/00000/00057
d D 1.3 82/02/17 18:49:53 linton 3 2
c added isvariable procedure
e
s 00001/00001/00056
d D 1.2 82/01/18 22:15:19 linton 2 1
c sccsid
e
s 00057/00000/00000
d D 1.1 82/01/18 19:02:53 linton 1 0
c date and time created 82/01/18 19:02:53 by linton
e
u
U
t
T
I 1
D 4
/* Copyright (c) 1982 Regents of the University of California */

D 2
static char sccsid[] = "%Z%%M% %I% %G%";
E 2
I 2
/* static char sccsid[] = "%Z%%M% %I% %G%"; */
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 4
E 2

/*
 * This header file declares the variables and routines that
 * are defined within the "sym" subdirectory and that can be
 * accessed from outside.
 */

SYM *program;

/*
 * attributes
 */

char *name();			/* symbol string name */
char *classname();		/* class name of a symbol */
int toknum();			/* token number of reserved word */
int tokval();			/* associated token value */
int size();			/* size in bytes of a type */
SYM *rtype();			/* the reduced type, i.e. no type names */
SYM *container();		/* symbol (block) that contains given symbol */
ADDRESS codeloc();		/* address of the beginning of a function */

/*
 * predicates
 */

BOOLEAN isblock();		/* test if a symbol is a block name */
BOOLEAN isbuiltin();		/* test if a symbol is a builtin type */
BOOLEAN isparam();		/* test if a symbol is a parameter */
BOOLEAN isvarparam();		/* test if a symbol is a var parameter */
I 3
BOOLEAN isvariable();		/* test if a symbol is a variable */
E 3
BOOLEAN isambiguous();		/* test if a symbol name is not unique */
BOOLEAN compatible();		/* test to see if two types are compatible */
BOOLEAN should_print();		/* test if a symbol should be printed */

SYM *readsym();			/* read in a symbol from object file */
SYM *which();			/* find the appropriate symbol of given name */
SYM *findsym();			/* find a symbol for a given block */
SYM *findclass();		/* find symbol with given class */
NODE *dot();			/* construct a tree for the dot operator */
NODE *subscript();		/* construct a tree for subscripting */
SYM *treetype();		/* return the type of a tree, checking also */
D 5
evalindex();			/* evaluate a subscript index */
E 5
I 5
long evalindex();		/* evaluate a subscript index */
E 5
D 6
unmkstring();			/* free a constant string type */
chkboolean();			/* check if a tree is boolean-valued */
printdecl();			/* print out a symbol's declaration */
printparams();			/* print out values of a fn's parameters */
printentry();			/* note entrance of a block */
printexit();			/* note exiting from a block */
printcall();			/* note call of a function */
printval();			/* print an eval result */
printv();			/* print the name and value of a variable */
printwhich();			/* print the full "path" of an identifier */
maketypes();			/* initialize basic types */
make_keyword();			/* create a keyword in a given symbol table */
E 6
I 6
int unmkstring();		/* free a constant string type */
int chkboolean();		/* check if a tree is boolean-valued */
int printdecl();		/* print out a symbol's declaration */
int printparams();		/* print out values of a fn's parameters */
int printentry();		/* note entrance of a block */
int printexit();		/* note exiting from a block */
int printcall();		/* note call of a function */
int printval();			/* print an eval result */
int printv();			/* print the name and value of a variable */
int printwhich();		/* print the full "path" of an identifier */
int maketypes();		/* initialize basic types */
int make_keyword();		/* create a keyword in a given symbol table */
E 6
E 1
