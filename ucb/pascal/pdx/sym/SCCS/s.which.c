h48519
s 00008/00002/00095
d D 5.1 85/06/06 11:59:50 dist 2 1
c Add copyright
e
s 00097/00000/00000
d D 1.1 82/01/18 19:21:23 linton 1 0
c date and time created 82/01/18 19:21:23 by linton
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
 * Routines to distinguish symbols of the same name.
 */

#include "defs.h"
#include "sym.h"
#include "classes.h"
#include "symtab.h"
#include "mappings.h"
#include "machine.h"
#include "sym.rep"

/*
 * Figure out the "current" symbol being referred to,
 * this is either the active one or the most visible from the
 * current scope.
 *
 * Fields are purposely ignored; these can be gotten to via "findclass".
 */

SYM *which(s)
SYM *s;
{
	register SYM *p, *t, *f;

	if (s == program || isbuiltin(s)) {
		return(s);
	}
	if (!isactive(program)) {
		f = program;
	} else {
		f = whatblock(pc);
		if (f == NIL) {
			panic("no block for addr 0x%x", pc);
		}
	}
	for (p = f; p != NIL; p = p->func) {
		if ((t = findsym(s, p)) != NIL) {
			break;
		}
	}
	if (t == NIL) {
		error("\"%s\" is not known in \"%s\"", s->symbol, f->symbol);
	}
	return(t);
}

/*
 * Find a (non-field) symbol with name s->symbol belonging to block f.
 *
 * Parameters to the main program are purposely "not found" because
 * pi gives them no type.
 */

SYM *findsym(s, f)
SYM *s;
SYM *f;
{
	register SYM *t;

	if (!isblock(f)) {
		error("%s is not a block", f->symbol);
	}
	for (t = s; t != NIL; t = t->next_sym) {
		if (t->func == f && !(f == program && isparam(t)) &&
		  t->class != FIELD && streq(t->symbol, s->symbol)) {
			break;
		}
	}
	return(t);
}

/*
 * Find the symbol which is has the same name and scope as the
 * given symbol but is of the given field.  Return NIL if there is none.
 */

SYM *findclass(s, cl)
SYM *s;
char cl;
{
	register SYM *t;

	if (s->class == cl) {
		return(s);
	}
	t = st_lookup(symtab, s->symbol);
	while (t != NIL && (t->class != cl || t->func != s->func ||
	  !streq(s->symbol, t->symbol))) {
		t = t->next_sym;
	}
	return(t);
}
E 1
