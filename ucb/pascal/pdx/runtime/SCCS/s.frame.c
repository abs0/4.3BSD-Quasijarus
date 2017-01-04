h40113
s 00001/00000/00179
d D 5.2 87/04/07 15:55:52 mckusick 3 2
c port to tahoe by Nir peleg of CCI
e
s 00008/00002/00171
d D 5.1 85/06/06 11:48:43 dist 2 1
c Add copyright
e
s 00173/00000/00000
d D 1.1 82/01/18 19:21:04 linton 1 0
c date and time created 82/01/18 19:21:04 by linton
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
 * Activation record handling.
 *
 * The routines curframe and nextframe cheat by using a global copy
 * of the display.  This means there can't be multiple instances of
 * them active at the same time and nextframe won't work in arbitrary cases.
 *
 * This could be solved by putting the display copy into the FRAME structure,
 * but I didn't feel like doing this.  The idea is that they be used
 * in looping through all frames, if I had generators I would use them.
 */

#include "defs.h"
#include "runtime.h"
#include "machine.h"
#include "process.h"
#include "sym.h"
#include "object.h"
#include "mappings.h"
#include "process/pxinfo.h"
#include "frame.rep"
I 3
#include "process/process.rep"
E 3

/*
 * Return a pointer to the current activation record.
 * Return NIL if currently in the main program.
 * The storage is static.
 */

#define MAXDEPTH 7
#define dispblk(dp)		((dp - DISPLAY) / 2)

LOCAL ADDRESS *display[MAXDEPTH];
LOCAL int dispindex;

FRAME *curframe()
{
	static FRAME frame;
	FRAME *frp;
	ADDRESS *dp, *disp;
	int i;

	frp = &frame;
	dp = curdp();
	disp = contents(dp);
	if (dispblk(dp) <= MAINBLK) {
		return NIL;
	} else {
		getframe(frp, disp);
		for (i = 1; i < MAXDEPTH; i++) {
			display[i] = dispval(i);
		}
		dispindex = dispblk(dp);
		return frp;
	}
}

/*
 * Return a pointer to the next activation record up the stack.
 * Return NIL if there is none.
 * Writes over space pointed to by given argument.
 */

FRAME *nextframe(frp)
FRAME *frp;
{
	ADDRESS *fp;

	if (dispblk(frp->save_dp) <= MAINBLK) {
		return(NIL);
	} else {
		display[dispindex] = frp->save_disp;
		dispindex = dispblk(frp->save_dp);
		fp = display[dispindex];
		getframe(frp, fp);
		return(frp);
	}
}

/*
 * Return the frame associated with the given function.
 */

FRAME *findframe(f)
SYM *f;
{
	static FRAME frame;
	FRAME *frp, *prevfrp;

	frame.save_dp = curdp();
	frame.save_disp = contents(frame.save_dp);
	prevfrp = &frame;
	for (frp = curframe(); frp != NIL; frp = nextframe(frp)) {
		if (whatblock(entry(frp)) == f) {
			return frp;
		}
		*prevfrp = *frp;
	}
	if (f == program) {
		return prevfrp;
	} else {
		return NIL;
	}
}

/*
 * Get the activation record associated with the given display pointer.
 */

LOCAL getframe(frp, disp)
FRAME *frp;
ADDRESS *disp;
{
	if (disp == NIL) {
		panic("bad disp in getframe");
	}
	dread(frp, disp, sizeof(FRAME));
	frp->save_pc -= ENDOFF;
}

/*
 * Return the address of the display in the px process for the given block.
 */

ADDRESS *dispval(b)
int b;
{
	ADDRESS *r;

	dread(&r, (ADDRESS) (DISPLAY + 2*b), sizeof(r));
	return r;
}

/*
 * Return the current display pointer.
 */

ADDRESS *curdp()
{
	ADDRESS *r;

	dread(&r, (ADDRESS) DP, sizeof(r));
	return r;
}

/*
 * Return the contents of the given display pointer.
 */

ADDRESS *contents(dp)
ADDRESS *dp;
{
	ADDRESS *r;

	dread(&r, (ADDRESS) dp, sizeof(r));
	return r;
}

/*
 * Return the px stack address associated with a given frame pointer.
 * Actually, to confuse the issue we want the stack address of the
 * frame one up from the given one.
 */

ADDRESS stkaddr(frp, b)
FRAME *frp;
int b;
{
	return (ADDRESS) display[b];
}
E 1
