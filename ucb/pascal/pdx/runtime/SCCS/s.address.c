h60673
s 00008/00002/00125
d D 5.1 85/06/06 11:46:44 dist 3 2
c Add copyright
e
s 00044/00041/00083
d D 1.2 82/03/08 19:33:18 linton 2 1
c changed "firstline" so that it gives up when it 
c reaches the end of the procedure
e
s 00124/00000/00000
d D 1.1 82/01/18 19:20:59 linton 1 0
c date and time created 82/01/18 19:20:59 by linton
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
 * Some machine and runtime dependent manipulation of a symbol.
 */

#include "defs.h"
#include "runtime.h"
#include "sym.h"
#include "machine.h"
#include "process.h"
#include "object.h"
#include "mappings.h"
#include "sym/classes.h"
#include "frame.rep"
#include "sym/sym.rep"

/*
 * Calculate the address of a symbol.
 * If frame is not NIL, then it is the frame associated with the
 * activation in which the symbol we're interested in is defined.
 */

ADDRESS address(s, frame)
register SYM *s;
FRAME *frame;
{
D 2
	SYM *f;
	FRAME *frp;
	ADDRESS r, *dp, *disp;
	short offs;
E 2
I 2
    SYM *f;
    FRAME *frp;
    ADDRESS r, *dp, *disp;
    short offs;
E 2

D 2
	f = s->func;
	if (s->class == FVAR) {
		offs = f->symvalue.offset;
E 2
I 2
    f = s->func;
    if (s->class == FVAR) {
	offs = f->symvalue.offset;
    } else {
	offs = s->symvalue.offset;
    }
    if (f == program) {
	r = (ADDRESS) dispval(MAINBLK) + offs;
    } else if (f == curfunc && frame == NIL) {
	dp = curdp();
	disp = contents(dp);
	r = (ADDRESS) disp + offs;
    } else {
	if (frame == NIL) {
	    frp = findframe(s->func);
	    if (frp == NIL) {
		panic("address: findframe returned NIL");
	    }
E 2
	} else {
D 2
		offs = s->symvalue.offset;
E 2
I 2
	    frp = frame;
E 2
	}
D 2
	if (f == program) {
		r = (ADDRESS) dispval(MAINBLK) + offs;
	} else if (f == curfunc && frame == NIL) {
		dp = curdp();
		disp = contents(dp);
		r = (ADDRESS) disp + offs;
	} else {
		if (frame == NIL) {
			frp = findframe(s->func);
			if (frp == NIL) {
				panic("address: findframe returned NIL");
			}
		} else {
			frp = frame;
		}
		r = stkaddr(frp, s->blkno) + offs;
	}
	return r;
E 2
I 2
	r = stkaddr(frp, s->blkno) + offs;
    }
    return r;
E 2
}

/*
 * The next three routines assume the procedure entry code is
 *
D 2
 *		f:	tra4	A
 *			...
 *		A:	beg
 *		B:	<code for first line>
E 2
I 2
 *      f:  tra4    A
 *          ...
 *      A:  beg
 *      B:  <code for first line>
E 2
 *
 * Pi gives f, we compute and store A with "findbeginning(f)",
 * (retrieved by "codeloc(f)"), B is computed by "firstline(f)".
 *
 * The procedure "runtofirst" assumes you're at A and want to step to B.
 * It should be changed to a nop if A is equal to B.
 */

/*
 * Find the beginning of a procedure or function.  This is a destructive
 * routine, it changes the value associated with the procedure symbol.
 * Should only be called once per symbol.
 */

findbeginning(f)
SYM *f;
{
D 2
	f->symvalue.funcv.codeloc = nextaddr(f->symvalue.funcv.codeloc, FALSE);
E 2
I 2
    f->symvalue.funcv.codeloc = nextaddr(f->symvalue.funcv.codeloc, FALSE);
E 2
}

/*
 * Find the object code associated with the first line of a block.
 */

ADDRESS firstline(f)
SYM *f;
{
D 2
	ADDRESS addr;
E 2
I 2
    ADDRESS addr;
E 2

D 2
	addr = codeloc(f);
	while (linelookup(addr) == 0) {
		addr = nextaddr(addr, FALSE);
E 2
I 2
    addr = codeloc(f);
    while (linelookup(addr) == 0) {
	if (isendofproc(addr)) {
	    return -1;
E 2
	}
D 2
	return(addr);
E 2
I 2
	addr = nextaddr(addr, FALSE);
    }
    return addr;
E 2
}

/*
 * Catcher drops strike three ...
 */

runtofirst()
{
D 2
	stepto(firstline(curfunc));
E 2
I 2
    stepto(firstline(curfunc));
E 2
}

/*
 * Calculate the address of the last line in the program.
 * This is assumed to be at the physical end.
 */

ADDRESS lastaddr()
{
D 2
	if (objsize == 0) {
		panic("lastaddr: objsize = 0!");
	}
	return(objsize - sizeof(short));
E 2
I 2
    if (objsize == 0) {
	panic("lastaddr: objsize = 0!");
    }
    return(objsize - sizeof(short));
E 2
}
E 1
