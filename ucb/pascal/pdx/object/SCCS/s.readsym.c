h52423
s 00003/00005/00203
d D 5.2 87/04/07 15:54:37 mckusick 5 4
c port to tahoe by Nir peleg of CCI
e
s 00008/00003/00200
d D 5.1 85/06/06 11:33:07 dist 4 3
c Add copyright
e
s 00102/00102/00101
d D 1.3 82/05/19 17:45:20 linton 3 2
c fixed problem with file lineindex pointing after last line table entry
e
s 00003/00002/00200
d D 1.2 82/01/19 01:36:05 linton 2 1
c replaced use of SIZELOC and BASEADDR with info in "objfmt.h"
e
s 00202/00000/00000
d D 1.1 82/01/18 19:20:42 linton 1 0
c date and time created 82/01/18 19:20:42 by linton
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
 * SYM representation dependent routines for reading in the
 * symbol information from the object file.
 */

#include "defs.h"
#include "sym.h"
#include "symtab.h"
#include "object.h"
I 2
#include "objfmt.h"
E 2
#include "process.h"
#include "sym/classes.h"
#include "objsym.rep"
#include "sym/sym.rep"

LOCAL SYM *findblock();
LOCAL SYM *enterblock();
LOCAL SYM *findfunc();

/*
 * Read the information on a symbol from the object file, return a
 * SYM with the info.
 */

SYM *readsym(fp)
FILE *fp;
{
D 3
	register SYM *s, *t;
	SYM cursym;
	static SYM *func;
E 3
I 3
    register SYM *s, *t;
    SYM cursym;
    static SYM *func;
E 3

D 3
	t = &cursym;
	getsym(fp, t);
	if (isblock(t)) {
#		if (isvaxpx)
			if (t->class == PROG) {
D 2
				t->symvalue.funcv.codeloc = BASEADDR;
E 2
I 2
				t->symvalue.funcv.codeloc = HEADER_BYTES;
E 2
			}
#		endif
		s = findblock(t);
		if (s->class == PROG) {
			program = s;
			s->func = NIL;
		} else {
			s->func = func;
		}
	} else if (t->class == BADUSE) {
		func = enterblock(t);
		return(func);
E 3
I 3
    t = &cursym;
    getsym(fp, t);
    if (isblock(t)) {
D 5
#       if (isvaxpx)
	    if (t->class == PROG) {
		t->symvalue.funcv.codeloc = HEADER_BYTES;
	    }
#       endif
E 5
I 5
	if (t->class == PROG) {
	    t->symvalue.funcv.codeloc = HEADER_BYTES;
	}
E 5
	s = findblock(t);
	if (s->class == PROG) {
	    program = s;
	    s->func = NIL;
E 3
	} else {
D 3
		s = st_insert(symtab, t->symbol);
		t->next_sym = s->next_sym;
		*s = *t;
		if (s->class == FVAR) {
			s->func = findfunc(s);
		} else {
			s->func = func;
		}
E 3
I 3
	    s->func = func;
E 3
	}
I 3
    } else if (t->class == BADUSE) {
	func = enterblock(t);
	return(func);
    } else {
	s = st_insert(symtab, t->symbol);
	t->next_sym = s->next_sym;
	*s = *t;
	if (s->class == FVAR) {
	    s->func = findfunc(s);
	} else {
	    s->func = func;
	}
    }
E 3

/*
 * This glitch is pi's fault.  It gives string constants
 * a type whose symbol number is -1.  For what reason, I know not.
 */
D 3
	if (s->type == (SYM *) -1) {
		s->type = NIL;
	} else {
		chkpatch(&s->type);
	}
	chkpatch(&s->chain);
	if (s->class == RECORD || s->class == VARNT) {
		chkpatch(&s->symvalue.varnt.vtorec);
		chkpatch(&s->symvalue.varnt.vtag);
	}
	if (isblock(s)) {
		fixparams(s);
	}
	return(s);
E 3
I 3
    if (s->type == (SYM *) -1) {
	s->type = NIL;
    } else {
	chkpatch(&s->type);
    }
    chkpatch(&s->chain);
    if (s->class == RECORD || s->class == VARNT) {
	chkpatch(&s->symvalue.varnt.vtorec);
	chkpatch(&s->symvalue.varnt.vtag);
    }
    if (isblock(s)) {
	fixparams(s);
    }
    return(s);
E 3
}

/*
 * Read the SYM information in the object file.
 */

LOCAL getsym(fp, t)
FILE *fp;
SYM *t;
{
D 3
	OBJSYM osym;
	register OBJSYM *o;
E 3
I 3
    OBJSYM osym;
    register OBJSYM *o;
E 3

D 3
	get(fp, osym);
	o = &osym;
	if (o->strindex == 0) {
		t->symbol = NIL;
	} else {
		t->symbol = &stringtab[o->strindex];
	}
	t->class = o->oclass;
	t->blkno = o->oblkno;
	t->type = (SYM *) o->typno;
	t->chain = (SYM *) o->chno;
	t->symvalue.rangev.lower = o->osymvalue.orangev.lower;
	t->symvalue.rangev.upper = o->osymvalue.orangev.upper;
	if (t->class == RECORD || t->class == VARNT) {
		t->symvalue.varnt.vtorec = (SYM *) o->osymvalue.ovarnt.vtorecno;
		t->symvalue.varnt.vtag = (SYM *) o->osymvalue.ovarnt.vtagno;
	}
E 3
I 3
    get(fp, osym);
    o = &osym;
    if (o->strindex == 0) {
	t->symbol = NIL;
    } else {
	t->symbol = &stringtab[o->strindex];
    }
    t->class = o->oclass;
    t->blkno = o->oblkno;
    t->type = (SYM *) o->typno;
    t->chain = (SYM *) o->chno;
    t->symvalue.rangev.lower = o->osymvalue.orangev.lower;
    t->symvalue.rangev.upper = o->osymvalue.orangev.upper;
    if (t->class == RECORD || t->class == VARNT) {
	t->symvalue.varnt.vtorec = (SYM *) o->osymvalue.ovarnt.vtorecno;
	t->symvalue.varnt.vtag = (SYM *) o->osymvalue.ovarnt.vtagno;
    }
E 3
}

/*
 * The symbol read in is a real block so we find it's entry,
 * copy the information, and return a pointer to it.
 */

LOCAL SYM *findblock(t)
SYM *t;
{
D 3
	SYM *s;
E 3
I 3
    SYM *s;
E 3

D 3
	s = st_lookup(symtab, t->symbol);
	while (s != NIL &&
	    (s->class != FUNC || s->type != NIL ||
	    strcmp(s->symbol, t->symbol) != 0)) {
		s = s->next_sym;
	}
	if (s == NIL) {
		panic("can't find %s", t->symbol);
	}
	t->next_sym = s->next_sym;
	*s = *t;
D 2
	s->symvalue.funcv.codeloc -= BASEADDR;
E 2
I 2
	s->symvalue.funcv.codeloc -= HEADER_BYTES;
E 2
	findbeginning(s);
	newfunc(s);
	return(s);
E 3
I 3
    s = st_lookup(symtab, t->symbol);
    while (s != NIL &&
	(s->class != FUNC || s->type != NIL ||
	strcmp(s->symbol, t->symbol) != 0)) {
	s = s->next_sym;
    }
    if (s == NIL) {
	panic("can't find %s", t->symbol);
    }
    t->next_sym = s->next_sym;
    *s = *t;
    s->symvalue.funcv.codeloc -= HEADER_BYTES;
    findbeginning(s);
    newfunc(s);
    return(s);
E 3
}

/*
 * Found a "fake" block symbol, enter it.
 */

LOCAL SYM *enterblock(t)
SYM *t;
{
D 3
	SYM *s;
E 3
I 3
    SYM *s;
E 3

D 3
	s = st_insert(symtab, t->symbol);
	t->next_sym = s->next_sym;
	*s = *t;
	backpatch();
	s->class = FUNC;
	s->type = NIL;
	return(s);
E 3
I 3
    s = st_insert(symtab, t->symbol);
    t->next_sym = s->next_sym;
    *s = *t;
    backpatch();
    s->class = FUNC;
    s->type = NIL;
    return(s);
E 3
}

/*
 * This kludge is brought to you by the pi symbol table.
 * Parameters appear with the function in which they reside,
 * messing up the way the "func" field is calculated.
 *
 * The assumption here is that parameters appear before the function.
 */

LOCAL fixparams(f)
SYM *f;
{
D 3
	register SYM *s;
E 3
I 3
    register SYM *s;
E 3

D 3
	for (s = f->chain; s != NIL; s = s->chain) {
		s->func = f;
	}
E 3
I 3
    for (s = f->chain; s != NIL; s = s->chain) {
	s->func = f;
    }
E 3
}

/*
 * Find the function entry associated with a function variable.
 * Function variables come out a bit strangely in the symbol table;
 * if we didn't do this here, a function variable would have a func
 * field that referred to the outer block.
 */

#define notfunc(f, fv) (\
D 3
	f->class != FUNC || f->type != NIL || \
	strcmp(f->symbol, fv->symbol) != 0 \
	)
E 3
I 3
    f->class != FUNC || f->type != NIL || \
    strcmp(f->symbol, fv->symbol) != 0 \
    )
E 3

LOCAL SYM *findfunc(fv)
SYM *fv;
{
D 3
	register SYM *t;
E 3
I 3
    register SYM *t;
E 3

D 3
	t = st_lookup(symtab, fv->symbol);
	while (t != NIL && notfunc(t, fv)) {
		t = t->next_sym;
	}
	if (t == NIL) {
		panic("no func for funcvar %s", fv->symbol);
	}
	return(t);
E 3
I 3
    t = st_lookup(symtab, fv->symbol);
    while (t != NIL && notfunc(t, fv)) {
	t = t->next_sym;
    }
    if (t == NIL) {
	panic("no func for funcvar %s", fv->symbol);
    }
    return(t);
E 3
}
E 1
