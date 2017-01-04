h58074
s 00008/00003/00166
d D 5.1 85/06/06 11:54:03 dist 5 4
c Add copyright
e
s 00034/00025/00135
d D 1.4 82/04/23 12:12:41 linton 4 3
c reworked compatible to fix a bug dealing with var parameters
e
s 00062/00051/00098
d D 1.3 82/02/17 18:52:55 linton 3 2
c added isvariable procedure
e
s 00005/00001/00144
d D 1.2 82/01/19 00:09:07 linton 2 1
c assigning to strings, large expressions
e
s 00145/00000/00000
d D 1.1 82/01/18 19:21:16 linton 1 0
c date and time created 82/01/18 19:21:16 by linton
e
u
U
t
T
I 1
D 5
/* Copyright (c) 1982 Regents of the University of California */
E 5
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 5

D 5
static char sccsid[] = "%Z%%M% %I% %G%";

E 5
I 5
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 5
/*
 * The basic tests on a symbol.
 */

#include "defs.h"
#include "sym.h"
#include "symtab.h"
I 2
#include "btypes.h"
E 2
#include "classes.h"
#include "sym.rep"

/*
 * Test if a symbol is a parameter.  This is true if there
 * is a cycle from s->func to s via chain pointers.
 */

BOOLEAN isparam(s)
SYM *s;
{
D 3
	register SYM *t;
E 3
I 3
    register SYM *t;
E 3

D 3
	for (t = s->func; t != NIL; t = t->chain) {
		if (t == s) {
			return(TRUE);
		}
E 3
I 3
    for (t = s->func; t != NIL; t = t->chain) {
	if (t == s) {
	    return(TRUE);
E 3
	}
D 3
	return(FALSE);
E 3
I 3
    }
    return(FALSE);
E 3
}

/*
 * Test if a symbol is a var parameter, i.e. has class REF.
 */

BOOLEAN isvarparam(s)
SYM *s;
{
D 3
	return (BOOLEAN) s->class == REF;
E 3
I 3
    return (BOOLEAN) s->class == REF;
E 3
}

/*
I 3
 * Test if a symbol is a variable (actually any addressible quantity
 * with do).
 */

BOOLEAN isvariable(s)
SYM *s;
{
    return s->class == VAR || s->class == FVAR || s->class == REF;
}

/*
E 3
 * Test if a symbol is a block, e.g. function, procedure, or the
 * main program.
 */

BOOLEAN isblock(s)
register SYM *s;
{
D 3
	return(s->class == FUNC || s->class == PROC || s->class == PROG);
E 3
I 3
    return(s->class == FUNC || s->class == PROC || s->class == PROG);
E 3
}

/*
 * Test if a symbol is builtin, that is, a predefined type or
 * reserved word.
 */

BOOLEAN isbuiltin(s)
SYM *s;
{
D 3
	return(s->blkno == 0 && s->class != PROG && s->class != VAR);
E 3
I 3
    return(s->blkno == 0 && s->class != PROG && s->class != VAR);
E 3
}

/*
 * Compatible tests if two types are compatible.  The issue
 * is complicated a bit by ranges.
 *
 * Integers and reals are not compatible since they cannot always be mixed.
 */

BOOLEAN compatible(t1, t2)
register SYM *t1, *t2;
{
D 3
	if (t1 == t2) {
		return(TRUE);
E 3
I 3
D 4
    if (t1 == t2) {
	return(TRUE);
E 4
I 4
    register BOOLEAN b;

    if (isvariable(t1)) {
	t1 = t1->type;
E 4
    }
D 4
    t1 = rtype(t1);
    t2 = rtype(t2);
    if (t1->type == t2->type) {
	if (t1->class == RANGE && t2->class == RANGE) {
	    return TRUE;
E 4
I 4
    if (isvariable(t2)) {
	t2 = t2->type;
    }
    if (t1 == t2) {
	b = TRUE;
    } else {
	t1 = rtype(t1);
	t2 = rtype(t2);
	if (t1->type == t2->type) {
	    if (t1->class == RANGE && t2->class == RANGE) {
		b = TRUE;
	    } else if ((t1->class == SCAL || t1->class == CONST) &&
	      (t2->class == SCAL || t2->class == CONST)) {
		b = TRUE;
	    } else if (t1->type == t_char &&
	      t1->class == ARRAY && t2->class == ARRAY) {
		b = TRUE;
	    } else {
		b = FALSE;
	    }
    /*
     * A kludge here for "nil".  Should be handled better.
     * Opens a pandora's box for integer/pointer compatibility.
     */
	} else if ((t1->class == RANGE && t2->class == PTR) ||
	  (t2->class == RANGE && t1->class == PTR)) {
	    b = TRUE;
	} else {
	    b = FALSE;
E 4
E 3
	}
D 3
	t1 = rtype(t1);
	t2 = rtype(t2);
	if (t1->type == t2->type) {
		if (t1->class == RANGE && t2->class == RANGE) {
			return TRUE;
		}
		if ((t1->class == SCAL || t1->class == CONST) &&
		  (t2->class == SCAL || t2->class == CONST)) {
			return TRUE;
		}
I 2
		if (t1->type == t_char && t1->class == ARRAY && t2->class == ARRAY) {
			return TRUE;
		}
E 3
I 3
D 4
	if ((t1->class == SCAL || t1->class == CONST) &&
	  (t2->class == SCAL || t2->class == CONST)) {
	    return TRUE;
E 3
E 2
	}
I 3
	if (t1->type == t_char && t1->class == ARRAY && t2->class == ARRAY) {
	    return TRUE;
	}
E 4
    }
E 3
D 4
/*
 * A kludge here for "nil".  Should be handled better.
 * Opens a pandora's box for integer/pointer compatibility.
 */
D 3
	if (t1->class == RANGE && t2->class == PTR) {
		return TRUE;
	}
	if (t2->class == RANGE && t1->class == PTR) {
		return TRUE;
	}
	return(FALSE);
E 3
I 3
    if (t1->class == RANGE && t2->class == PTR) {
	return TRUE;
    }
    if (t2->class == RANGE && t1->class == PTR) {
	return TRUE;
    }
    return(FALSE);
E 4
I 4
    return b;
E 4
E 3
}

/*
 * Predicate to test if a symbol should be printed.  We don't print
 * files, for example, simply because there's no good way to do it.
 * The symbol must be within the given function.
 */

BOOLEAN should_print(s, f)
SYM *s;
SYM *f;
{
D 3
	SYM *t;
E 3
I 3
    SYM *t;
E 3

D 3
	if (s->func != f || (s->class != VAR && s->class != FVAR)) {
		return(FALSE);
	} else if (s->chain != NIL) {
		return(FALSE);
E 3
I 3
    if (s->func != f || (s->class != VAR && s->class != FVAR)) {
	return(FALSE);
    } else if (s->chain != NIL) {
	return(FALSE);
    } else {
	t = rtype(s->type);
	if (t == NIL || t->class == FILET || t->class == SET) {
	    return(FALSE);
E 3
	} else {
D 3
		t = rtype(s->type);
D 2
		if (t == NIL || t->class == FILET) {
E 2
I 2
		if (t == NIL || t->class == FILET || t->class == SET) {
E 2
			return(FALSE);
		} else {
			return(TRUE);
		}
E 3
I 3
	    return(TRUE);
E 3
	}
I 3
    }
E 3
}

/*
 * Test if the name of a symbol is uniquely defined or not.
 */

BOOLEAN isambiguous(s)
SYM *s;
{
D 3
	SYM *t;
E 3
I 3
    SYM *t;
E 3

D 3
	t = st_lookup(symtab, s->symbol);
	if (t == NIL) {
		panic("symbol name vanished");
	}
	while (t != NIL && (s == t || !streq(t->symbol, s->symbol))) {
		t = t->next_sym;
	}
	return t != NIL;
E 3
I 3
    t = st_lookup(symtab, s->symbol);
    if (t == NIL) {
	panic("symbol name vanished");
    }
    while (t != NIL && (s == t || !streq(t->symbol, s->symbol))) {
	t = t->next_sym;
    }
    return t != NIL;
E 3
}
E 1
