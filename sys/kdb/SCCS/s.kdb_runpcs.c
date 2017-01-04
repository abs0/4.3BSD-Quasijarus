h42088
s 00017/00014/00141
d D 7.3 86/12/15 20:26:52 sam 3 2
c lint
e
s 00011/00011/00144
d D 7.2 86/11/23 13:36:05 sam 2 1
c move machine dependencies to ../machine/kdbparam.h
e
s 00155/00000/00000
d D 7.1 86/11/20 12:22:07 sam 1 0
c date and time created 86/11/20 12:22:07 by sam
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
/*
 * Copyright (c) 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 3

#include "../kdb/defs.h"

char	*lp;

/* breakpoints */
BKPTR	bkpthead;

char	lastc;

long	dot;
int	adrflg;
long	loopcnt;
ADDR	userpc = 1;

runpcs(runmode, execsig)
{
	register BKPTR bkpt;

	if (adrflg)
		userpc = dot;
	if (execsig == 0)
		printf("kdb: running\n");
	if (runmode==SINGLE) {
		/*
		 * To single step, delete the
		 * breakpoints and invoke the
		 * hardware single step in the
		 * main loop.
		 */
		delbp();
		reset(SINGLE);
	}
	/*
	 * If we're currently at a breakpoint,
	 * restore the instruction and single
	 * step before continuing.  Otherwise,
	 * we can just set our breakpoints and
	 * continue.
	 */
	if (bkpt = scanbkpt(userpc)) {
D 3
		execbkpt(bkpt, execsig);
E 3
I 3
		execbkpt(bkpt);
E 3
		/*NOTREACHED*/
	}
	setbp();
	reset(CONTIN);
}

static	int execbkptf;

/*
 * Continue execution after a trap.
 *
 * If tracetrap is nonzero, we've entered here because of a
 * trace trap.  If we're skipping a breakpoint (execbkptf),
 * or this is the next iteration of a breakpoint, continue.
 * If this is the next iteration of a single step, do the
 * next step.  Otherwise return 1 if we stopped because
 * of a breakpoint,
 */
D 3
nextpcs(tracetrap, execsig)
	int tracetrap, execsig;
E 3
I 3
nextpcs(tracetrap)
	int tracetrap;
E 3
{
	register BKPTR bkpt;
	short rc;

D 2
	pcb.pcb_psl &= ~TBIT;
E 2
I 2
	clrsstep();			/* clear hardware single step */
E 2
	delbp();
	if (execbkptf) {
		execbkptf = 0;
		runpcs(CONTIN, 1);
		/*NOTREACHED*/
	}
	if (!tracetrap && (bkpt = scanbkpt(userpc))) {
		/*
		 * Stopped at a breakpoint,
		 * execute any command.
		 */
		dot = bkpt->loc;
		if (bkpt->flag == BKPTEXEC ||
		    ((bkpt->flag = BKPTEXEC) && bkpt->comm[0] != EOR &&
		    command(bkpt->comm, ':') && --bkpt->count)) {
			loopcnt++;
D 3
			execbkpt(bkpt, execsig);
			execsig = 0;
E 3
I 3
			execbkpt(bkpt);
E 3
		} else {
			bkpt->count = bkpt->initcnt;
			rc = 1;
		}
D 3
	} else {
		execsig = 0;
E 3
I 3
	} else
E 3
		rc = 0;
D 3
	}
E 3
	if (--loopcnt > 0)
		runpcs(rc ? CONTIN : SINGLE, 1);
	return (rc);
}

#define BPOUT 0
#define BPIN 1
static	int bpstate = BPOUT;

D 3
execbkpt(bkptr,execsig)
E 3
I 3
execbkpt(bkptr)
E 3
	BKPTR	bkptr;
{

	delbp();
D 2
	bkptr->flag=BKPTSET;
E 2
I 2
	bkptr->flag = BKPTSET;
E 2
	execbkptf++;
	reset(SINGLE);
}

BKPTR
scanbkpt(addr)
	ADDR addr;
{
	register BKPTR	bkptr;

D 2
	for (bkptr=bkpthead; bkptr; bkptr=bkptr->nxtbkpt)
		if (bkptr->flag && bkptr->loc==addr)
E 2
I 2
	for (bkptr = bkpthead; bkptr; bkptr = bkptr->nxtbkpt)
		if (bkptr->flag && bkptr->loc == addr)
E 2
			break;
	return (bkptr);
}

delbp()
{
D 3
	register ADDR a;
E 3
I 3
	register off_t a;
E 3
	register BKPTR bkptr;

D 2
	if (bpstate==BPOUT)
E 2
I 2
	if (bpstate == BPOUT)
E 2
		return;
D 2
	for (bkptr=bkpthead; bkptr; bkptr=bkptr->nxtbkpt)
E 2
I 2
	for (bkptr = bkpthead; bkptr; bkptr = bkptr->nxtbkpt)
E 2
		if (bkptr->flag) {
D 2
			a=bkptr->loc;
E 2
I 2
			a = bkptr->loc;
E 2
D 3
			put(a, ISP, bkptr->ins);
E 3
I 3
			put((off_t)a, ISP, (long)bkptr->ins);
E 3
		}
D 2
	bpstate=BPOUT;
E 2
I 2
	bpstate = BPOUT;
E 2
}

setbp()
{
D 3
	register ADDR a;
E 3
I 3
	register off_t a;
E 3
	register BKPTR bkptr;

D 2
	if (bpstate==BPIN)
E 2
I 2
	if (bpstate == BPIN)
E 2
		return;
D 2
	for (bkptr=bkpthead; bkptr; bkptr=bkptr->nxtbkpt)
E 2
I 2
	for (bkptr = bkpthead; bkptr; bkptr = bkptr->nxtbkpt)
E 2
		if (bkptr->flag) {
			a = bkptr->loc;
			bkptr->ins = get(a, ISP);
D 3
			put(a, ISP, SETBP(bkptr->ins));
E 3
I 3
			put(a, ISP, (long)SETBP(bkptr->ins));
E 3
		}
D 2
	bpstate=BPIN;
E 2
I 2
	bpstate = BPIN;
E 2
}
E 1
