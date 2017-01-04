h20733
s 00003/00003/00048
d D 5.3 88/01/03 00:33:29 bostic 7 6
c neither K&R or ANSI C allow untyped function declarations
e
s 00006/00000/00045
d D 5.2 87/04/07 15:51:43 mckusick 6 5
c port for tahoe from Nir peleg of CCI
e
s 00007/00003/00038
d D 5.1 85/06/06 16:14:14 dist 5 4
c Add copyright
e
s 00001/00000/00040
d D 1.4 82/02/13 17:23:45 linton 4 3
c added routine "popsmall"
e
s 00001/00002/00039
d D 1.3 82/01/18 23:38:25 linton 3 2
c STACKSIZE
e
s 00001/00001/00040
d D 1.2 82/01/18 22:15:25 linton 2 1
c sccsid
e
s 00041/00000/00000
d D 1.1 82/01/18 19:03:02 linton 1 0
c date and time created 82/01/18 19:03:02 by linton
e
u
U
t
T
I 1
D 5
/* Copyright (c) 1982 Regents of the University of California */

D 2
static char sccsid[] = "%Z%%M% %I% %G%";
E 2
I 2
/* static char sccsid[] = "%Z%%M% %I% %G%"; */
E 5
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 5
E 2

/*
 * This file contains the declarations of the variables and routines
 * within the "tree" subdirectory that are accessible from outside.
 */

#include "tree/opinfo.h"

/*
 * Evaluation stack manipulation macros.  These are publically
 * available because "eval" leaves it's result on the stack.
 *
 * These macros allow one to operate on stacks of arbitrary types
 * (including a stack of different typed objects).
 *
 * Sadly, underflow and overflow are not checked for.
 */

typedef char STACK;

D 3
#define STACKSIZE 1024
E 3
#define WMASK			(sizeof(int) - 1)

I 6
#ifdef tahoe
#define push(type, value)	((*(type *)sp) = value, sp += (sizeof(type) + WMASK) & ~WMASK, value)
#define	pop(type)		(sp -= (sizeof(type) + WMASK) & ~WMASK, (*((type *) sp)))
#else
E 6
#define push(type, value)	((type *) (sp += sizeof(type)))[-1] = (value)
#define pop(type)		(*((type *) (sp -= sizeof(type))))
I 6
#endif
E 6
#define alignstack()		sp = (char *) (( ((int) sp) + WMASK)&~WMASK)
I 6
#define downalignstack()	sp = (char *) (( ((int) sp))&~WMASK)
E 6

D 3
STACK stack[STACKSIZE];
E 3
I 3
STACK stack[];
E 3
STACK *sp;

NODE *build();		/* create a node in the parse tree */
D 7
prtree();		/* print a tree in source form */
eval();			/* evaluate a tree, leaving value on stack */
E 7
I 7
int prtree();		/* print a tree in source form */
int eval();		/* evaluate a tree, leaving value on stack */
E 7
I 4
long popsmall();	/* pop a small item from the stack given its type */
E 4
D 7
tfree();		/* release storage for a tree */
E 7
I 7
int tfree();		/* release storage for a tree */
E 7
BOOLEAN tr_equal();	/* test if two trees are structurally equivalent */
BOOLEAN cond();		/* evaluate a node for a conditional */
ADDRESS lval();		/* return the object address of a node */
BOOLEAN isredirected();	/* TRUE if output is being redirected */
E 1
