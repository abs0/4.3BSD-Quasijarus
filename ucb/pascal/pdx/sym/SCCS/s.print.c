h56836
s 00003/00001/00153
d D 5.2 87/04/07 15:56:36 mckusick 4 3
c port to tahoe by Nir peleg of CCI
e
s 00008/00003/00146
d D 5.1 85/06/06 11:54:46 dist 3 2
c Add copyright
e
s 00007/00005/00142
d D 1.2 82/01/19 00:09:12 linton 2 1
c assigning to strings, large expressions
e
s 00147/00000/00000
d D 1.1 82/01/18 19:21:11 linton 1 0
c date and time created 82/01/18 19:21:11 by linton
e
u
U
t
T
I 1
D 3
/* Copyright (c) 1982 Regents of the University of California */
E 3
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 3

D 3
static char sccsid[] = "%Z%%M% %I% %G%";

E 3
I 3
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 3
/*
 * Routines to print out symbols.
 */

#include "defs.h"
#include "sym.h"
#include "process.h"
#include "tree.h"
#include "runtime.h"
#include "classes.h"
#include "sym.rep"
#include "process/process.rep"

/*
 * Note the entry of the given block, unless it's the main program.
 */

printentry(s)
SYM *s;
{
	if (s != program) {
		printf("\nentering %s %s\n", classname(s), s->symbol);
	}
}

/*
 * Note the exit of the given block
 */

printexit(s)
SYM *s;
{
	if (s != program) {
		printf("leaving %s %s\n\n", classname(s), s->symbol);
	}
}

/*
 * Note the call of s from t.
 */

printcall(s, t)
SYM *s, *t;
{
	printf("calling %s", s->symbol);
	printparams(s, NIL);
	printf(" from %s %s\n", classname(t), t->symbol);
}

/*
 * Note the return from s.  If s is a function, print the value
 * it is returning.  This is somewhat painful, since the function
 * has actually just returned.
 */

printrtn(s)
SYM *s;
{
D 4
	register SYM *t;
E 4
	register int len;

	printf("returning ");
	if (s->class == FUNC) {
		len = size(s->type);
		dread(sp, process->sp, len);
		sp += len;
I 4
#ifdef tahoe
		alignstack();
#endif
E 4
		printval(s->type);
		putchar(' ');
	}
	printf("from %s\n", s->symbol);
}

/*
 * Print the values of the parameters of the given procedure or function.
 * The frame distinguishes recursive instances of a procedure.
 */

printparams(f, frame)
SYM *f;
FRAME *frame;
{
	SYM *param;

	for (param = f->chain; param != NIL; param = param->chain) {
		if (param == f->chain) {
			printf("(");
		}
		printv(param, frame);
		if (param->chain != NIL) {
			printf(", ");
		} else {
			printf(")");
		}
	}
}

/*
 * Print the name and value of a variable.
 */

printv(s, frame)
SYM *s;
FRAME *frame;
{
	ADDRESS addr;
	int len;

	if (s->class == REF) {
		dread(&addr, address(s, frame), sizeof(ADDRESS));
		len = size(s->type);
	} else {
		addr = address(s, frame);
		len = size(s);
	}
D 2
	dread(sp, addr, len);
	sp += len;
E 2
	printf("%s = ", s->symbol);
D 2
	if (s->class == REF || s->class == VAR) {
		printval(s->type);
E 2
I 2
	if (!rpush(addr, len)) {
		printf("*** expression too large ***");
E 2
	} else {
D 2
		printval(s);
E 2
I 2
		if (s->class == REF || s->class == VAR) {
			printval(s->type);
		} else {
			printval(s);
		}
E 2
	}
}

/*
 * Print the fully specified variable that is described by the given identifer.
 */

printwhich(s)
SYM *s;
{
	printouter(s->func);
	printf("%s", s->symbol);
}

LOCAL printouter(s)
SYM *s;
{
	if (s->func != NIL) {
		printouter(s->func);
	}
	printf("%s.", s->symbol);
}
E 1
