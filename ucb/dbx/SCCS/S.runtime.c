h03332
s 00001/00001/01081
d D 5.3 87/04/06 12:03:25 bostic 17 16
c printf format/argument mismatch
e
s 00027/00001/01055
d D 5.2 86/01/10 14:14:25 donn 16 15
c When the variable $unsafecall is set, override the standard checking
c of actual vs. formal argument types in the call command.
e
s 00008/00002/01048
d D 5.1 85/05/31 10:15:31 dist 15 14
c Add copyright
e
s 00293/00121/00757
d D 1.13 85/03/01 20:29:59 linton 14 13
c update to version 3.0
e
s 00001/00001/00877
d D 1.12 84/10/13 18:36:29 sam 13 12
c eliminate extraneous parameter
e
s 00001/00019/00877
d D 1.11 84/06/23 11:43:20 sam 12 10
i 11
c merge linton branch delta trail
e
s 00271/00054/00608
d D 1.9.1.1 84/06/23 10:49:46 sam 11 9
c branch delta of linton changes from net.sources
e
s 00023/00018/00644
d D 1.10 83/12/30 14:37:52 sam 10 9
c fix findframe, it had been skipping a stack frame for each scope 
c block instead of checking to see if a stack frame existed for the block
e
s 00002/00002/00660
d D 1.9 83/08/14 20:38:00 sam 9 8
c updated for revision to signals
e
s 00010/00004/00652
d D 1.8 83/08/10 04:58:06 linton 8 7
c modified traceback to deal with "inline" functions, i.e. blocks 
c which contain variables but do not have a separate activation record
e
s 00025/00020/00631
d D 1.7 83/07/15 14:47:39 linton 7 6
c changed the offset for finding the calling address of a signal handler 
c to reflect new 4.2 stuff'
e
s 00037/00002/00614
d D 1.6 83/05/18 21:00:56 csvaf 6 5
c added code to recognize non-standard frames put on user stack 
c by the kernel when interrupts are trapped
e
s 00001/00001/00615
d D 1.5 83/04/25 20:20:00 linton 5 4
c fixed problem with line number of top stack frame
e
s 00018/00006/00598
d D 1.4 83/04/08 01:18:30 linton 4 3
c fixed a very annoying bug, the routine "findframe" occasionally 
c hung because it used the wrong test for the last frame.  The correct test 
c involves checking if the saved frame pointer is 0 OR the saved pc belongs 
c to the "program", i.e. the start-up routine.
e
s 00002/00002/00602
d D 1.3 82/12/18 23:27:45 linton 3 2
c uses srcline(pc - 1) rather than srcline(pc) since pc is address 
c of next instruction
e
s 00001/00001/00603
d D 1.2 82/12/15 04:21:55 linton 2 1
c fixed @(#) stuff
e
s 00604/00000/00000
d D 1.1 82/12/15 04:08:35 linton 1 0
c date and time created 82/12/15 04:08:35 by linton
e
u
U
f b 
t
T
I 6
D 14

E 14
E 6
I 1
D 15
/* Copyright (c) 1982 Regents of the University of California */
E 15
I 15
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 15

D 2
static char sccsid[] = "@(#)%Z%%M% %I% %G%";
E 2
I 2
D 11
static char sccsid[] = "%Z%%M% %I% %G%";
E 11
I 11
D 12
static char sccsid[] = "@(#)runtime.c 1.8 8/10/83";
E 12
I 12
D 15
static	char sccsid[] = "%W% (Berkeley) %G%";
E 15
I 15
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 15
E 12
E 11
E 2

I 14
static char rcsid[] = "$Header: runtime.c,v 1.5 84/12/26 10:41:52 linton Exp $";

E 14
I 11
D 12
static char rcsid[] = "$Header: runtime.c,v 1.3 84/03/27 10:23:40 linton Exp $";

E 12
E 11
/*
 * Runtime organization dependent routines, mostly dealing with
 * activation records.
 */

#include "defs.h"
#include "runtime.h"
#include "process.h"
#include "machine.h"
#include "events.h"
#include "mappings.h"
#include "symbols.h"
#include "tree.h"
#include "eval.h"
#include "operators.h"
#include "object.h"
I 6
#include <sys/param.h>
E 6

#ifndef public
typedef struct Frame *Frame;

#include "machine.h"
#endif

#define NSAVEREG 12

struct Frame {
D 14
    Integer condition_handler;
    Integer mask;
E 14
I 14
    integer condition_handler;
    integer mask;
E 14
    Address save_ap;		/* argument pointer */
    Address save_fp;		/* frame pointer */
    Address save_pc;		/* program counter */
    Word save_reg[NSAVEREG];	/* not necessarily there */
};

I 11
private Frame curframe = nil;
private struct Frame curframerec;
E 11
private Boolean walkingstack = false;

I 11
#define frameeq(f1, f2) ((f1)->save_fp == (f2)->save_fp)

I 14
#define isstackaddr(addr) \
    (((addr) < 0x80000000) and ((addr) > 0x80000000 - 0x200 * UPAGES))

typedef struct {
    Node callnode;
    Node cmdnode;
    boolean isfunc;
} CallEnv;

private CallEnv endproc;

E 14
E 11
/*
 * Set a frame to the current activation record.
 */

private getcurframe(frp)
D 14
register Frame frp;
E 14
I 14
Frame frp;
E 14
{
    register int i;

    checkref(frp);
    frp->mask = reg(NREG);
    frp->save_ap = reg(ARGP);
    frp->save_fp = reg(FRP);
D 5
    frp->save_pc = reg(PROGCTR);
E 5
I 5
D 14
    frp->save_pc = reg(PROGCTR) + 1;
E 14
I 14
    frp->save_pc = reg(PROGCTR);
E 14
E 5
    for (i = 0; i < NSAVEREG; i++) {
	frp->save_reg[i] = reg(i);
    }
}

/*
I 14
 * Get the saved registers from one frame to another
 * given mask specifying which registers were actually saved.
 */

#define bis(b, n) ((b & (1 << (n))) != 0)

private getsaveregs (newfrp, frp, mask)
Frame newfrp, frp;
integer mask;
{
    integer i, j;

    j = 0;
    for (i = 0; i < NSAVEREG; i++) {
	if (bis(mask, i)) {
	    newfrp->save_reg[i] = frp->save_reg[j];
	    ++j;
	}
    }
}

/*
E 14
 * Return a pointer to the next activation record up the stack.
 * Return nil if there is none.
 * Writes over space pointed to by given argument.
 */

D 14
#define bis(b, n) ((b & (1 << (n))) != 0)

E 14
private Frame nextframe(frp)
Frame frp;
{
D 14
    register Frame newfrp;
E 14
I 14
    Frame newfrp;
E 14
    struct Frame frame;
D 14
    register Integer i, j, mask;
E 14
I 14
    integer mask;
E 14
I 6
    Address prev_frame, callpc; 
D 7
    private Integer ntramp=0;
E 7
I 7
D 14
    static Integer ntramp = 0;
E 14
I 14
    static integer ntramp = 0;
E 14
E 7
E 6

    newfrp = frp;
D 6
    dread(&frame, newfrp->save_fp, sizeof(struct Frame));
E 6
I 6
    prev_frame = frp->save_fp;

D 7
/*  The check for interrupt generated frames is taken from adb with only
 *  partial understanding : say you're in sub and on a sigxxx siggsub
 *  gets control and dies; the stack does NOT look like main, sub, sigsub.
E 7
I 7
/*
 *  The check for interrupt generated frames is taken from adb with only
 *  partial understanding.  If you're in "sub" and on a sigxxx "sigsub"
 *  gets control, then the stack does NOT look like <main, sub, sigsub>.
E 7
 *
 *  As best I can make out it looks like:
D 7
 *   main (machine check exception block + sub) sysframe  sigsub.
 *  ie when the sig occurs push an exception block on the user stack
 *  and a frame for the routine in which it occured then push another
 *  frame corresponding to a call from the kernel to sigsub.
E 7
 *
I 7
 *     <main, (machine check exception block + sub), sysframe, sigsub>.
 *
 *  When the signal occurs an exception block and a frame for the routine
 *  in which it occured are pushed on the user stack.  Then another frame
 *  is pushed corresponding to a call from the kernel to sigsub.
 *
E 7
 *  The addr in sub at which the exception occured is not in sub.save_pc
D 7
 *  but in the machine check exception block. It can be referenced as
 *  sub.save_reg[11].
E 7
I 7
 *  but in the machine check exception block.  It is at the magic address
D 9
 *  fp + 76.
E 9
I 9
 *  fp + 84.
E 9
E 7
 *
 *  The current approach ignores the sys_frame (what adb reports as sigtramp)
D 7
 *  and takes the pc for sub from the exception block. This
 *  allows where to report: main sub sigsub, which seems reasonable
E 7
I 7
 *  and takes the pc for sub from the exception block.  This allows the
 *  "where" command to report <main, sub, sigsub>, which seems reasonable.
E 7
 */
D 7
    nextf: dread(&frame, prev_frame , sizeof(struct Frame));
    if(ntramp == 1 ) callpc = (Address) frame.save_reg[11];
    else callpc=frame.save_pc;
E 7

I 7
nextf:
    dread(&frame, prev_frame, sizeof(struct Frame));
    if (ntramp == 1) {
D 9
	dread(&callpc, prev_frame + 76, sizeof(callpc));
E 9
I 9
	dread(&callpc, prev_frame + 84, sizeof(callpc));
E 9
    } else {
	callpc = frame.save_pc;
    }
E 7
E 6
D 14
    if (frame.save_fp == nil) {
E 14
I 14
    if (frame.save_fp == nil or frame.save_pc == (Address) -1) {
E 14
	newfrp = nil;
D 6
    } else {
E 6
I 6
D 7
    }
      else if (callpc > 0x80000000 - 0x200 * UPAGES ) {
E 7
I 7
D 14
    } else if (callpc > 0x80000000 - 0x200 * UPAGES ) {
E 7
	 ntramp++;
	 prev_frame = frame.save_fp;
	 goto nextf;
E 14
I 14
    } else if (isstackaddr(callpc)) {
	ntramp++;
	prev_frame = frame.save_fp;
	goto nextf;
E 14
D 7
	}
      else {
E 7
I 7
    } else {
E 7
	frame.save_pc = callpc;
D 7
        ntramp=0;
E 7
I 7
        ntramp = 0;
E 7
E 6
	mask = ((frame.mask >> 16) & 0x0fff);
D 14
	j = 0;
	for (i = 0; i < NSAVEREG; i++) {
	    if (bis(mask, i)) {
		newfrp->save_reg[i] = frame.save_reg[j];
		++j;
	    }
	}
E 14
I 14
	getsaveregs(newfrp, &frame, mask);
E 14
	newfrp->condition_handler = frame.condition_handler;
	newfrp->mask = mask;
	newfrp->save_ap = frame.save_ap;
	newfrp->save_fp = frame.save_fp;
	newfrp->save_pc = frame.save_pc;
    }
    return newfrp;
}

/*
I 11
 * Get the current frame information in the given Frame and store the
 * associated function in the given value-result parameter.
 */

private getcurfunc (frp, fp)
Frame frp;
Symbol *fp;
{
    getcurframe(frp);
    *fp = whatblock(frp->save_pc);
}

/*
 * Return the frame associated with the next function up the call stack, or
 * nil if there is none.  The function is returned in a value-result parameter.
 * For "inline" functions the statically outer function and same frame
 * are returned.
 */

D 14
private Frame nextfunc (frp, fp)
E 14
I 14
public Frame nextfunc (frp, fp)
E 14
Frame frp;
Symbol *fp;
{
    Symbol t;
    Frame nfrp;

    t = *fp;
    checkref(t);
    if (isinline(t)) {
	t = container(t);
	nfrp = frp;
    } else {
	nfrp = nextframe(frp);
	if (nfrp == nil) {
	    t = nil;
	} else {
	    t = whatblock(nfrp->save_pc);
	}
    }
    *fp = t;
    return nfrp;
}

/*
E 11
 * Return the frame associated with the given function.
 * If the function is nil, return the most recently activated frame.
 *
 * Static allocation for the frame.
 */

public Frame findframe(f)
Symbol f;
{
D 14
    register Frame frp;
E 14
I 14
    Frame frp;
E 14
    static struct Frame frame;
I 4
    Symbol p;
I 14
    Boolean done;
E 14
D 10
    Boolean done;
E 10
E 4

    frp = &frame;
    getcurframe(frp);
D 10
    if (f != nil) {
D 4
	while (frp != nil and whatblock(frp->save_pc) != f) {
	    frp = nextframe(frp);
	}
E 4
I 4
D 11
	done = false;
	do {
E 11
I 11
D 12
	if (f == curfunc and curframe != nil) {
	    *frp = *curframe;
	} else {
	    done = false;
E 11
	    p = whatblock(frp->save_pc);
D 11
	    if (p == f) {
		done = true;
	    } else if (p == program) {
		done = true;
		frp = nil;
	    } else {
		frp = nextframe(frp);
		if (frp == nil) {
E 11
I 11
	    do {
		if (p == f) {
E 11
		    done = true;
I 11
		} else if (p == program) {
		    done = true;
		    frp = nil;
		} else {
		    frp = nextfunc(frp, &p);
		    if (frp == nil) {
			done = true;
		    }
E 11
		}
D 11
	    }
	} while (not done);
E 11
I 11
	    } while (not done);
	}
E 12
E 11
E 10
I 10
D 14
    if (f == nil)
	return (frp);
    /*
     * Starting at the current stack frame,
     * walk backwards looking for a symbol
     * match.  Beware of local blocks which
     * have a back pointer but no stack frame.
     */
    p = whatblock(frp->save_pc);
    while (p != f) {
	if (p == program) {
	    frp = nil;
	    break;
E 14
I 14
    if (f != nil) {
	if (f == curfunc and curframe != nil) {
	    *frp = *curframe;
	} else {
	    done = false;
	    p = whatblock(frp->save_pc);
	    do {
		if (p == f) {
		    done = true;
		} else if (p == program) {
		    done = true;
		    frp = nil;
		} else {
		    frp = nextfunc(frp, &p);
		    if (frp == nil) {
			done = true;
		    }
		}
	    } while (not done);
E 14
	}
D 14
	if (isinline(p)) {
	    p = container(p);
	    continue;
E 14
I 14
    }
    return frp;
}

/*
 * Set the registers according to the given frame pointer.
 */

public getnewregs (addr)
Address addr;
{
    struct Frame frame;
    integer i, j, mask;

    dread(&frame, addr, sizeof(frame));
    setreg(ARGP, frame.save_ap);
    setreg(FRP, frame.save_fp);
    setreg(PROGCTR, frame.save_pc);
    mask = ((frame.mask >> 16) & 0x0fff);
    j = 0;
    for (i = 0; i < NSAVEREG; i++) {
	if (bis(mask, i)) {
	    setreg(i, frame.save_reg[j]);
	    ++j;
E 14
	}
D 14
	frp = nextframe(frp);
	if (frp == nil)
	   break;
	p = whatblock(frp->save_pc);
E 14
E 10
E 4
    }
D 10
    return frp;
E 10
I 10
D 14
    return (frp);
E 14
I 14
    pc = frame.save_pc;
    setcurfunc(whatblock(pc));
E 14
E 10
}

/*
 * Find the return address of the current procedure/function.
 */

public Address return_addr()
{
    Frame frp;
    Address addr;
    struct Frame frame;

    frp = &frame;
    getcurframe(frp);
    frp = nextframe(frp);
    if (frp == nil) {
	addr = 0;
    } else {
	addr = frp->save_pc;
    }
    return addr;
}

/*
 * Push the value associated with the current function.
 */

public pushretval(len, isindirect)
D 14
Integer len;
Boolean isindirect;
E 14
I 14
integer len;
boolean isindirect;
E 14
{
    Word r0;

    r0 = reg(0);
    if (isindirect) {
	rpush((Address) r0, len);
    } else {
	switch (len) {
	    case sizeof(char):
		push(char, r0);
		break;

	    case sizeof(short):
		push(short, r0);
		break;

	    default:
		if (len == sizeof(Word)) {
		    push(Word, r0);
		} else if (len == 2*sizeof(Word)) {
		    push(Word, r0);
		    push(Word, reg(1));
		} else {
D 14
		    panic("not indirect in pushretval?");
E 14
I 14
		    error("[internal error: bad size %d in pushretval]", len);
E 14
		}
		break;
	}
    }
}

/*
 * Return the base address for locals in the given frame.
 */

public Address locals_base(frp)
D 14
register Frame frp;
E 14
I 14
Frame frp;
E 14
{
    return (frp == nil) ? reg(FRP) : frp->save_fp;
}

/*
 * Return the base address for arguments in the given frame.
 */

public Address args_base(frp)
D 14
register Frame frp;
E 14
I 14
Frame frp;
E 14
{
    return (frp == nil) ? reg(ARGP) : frp->save_ap;
}

/*
 * Return saved register n from the given frame.
 */

public Word savereg(n, frp)
D 14
register Integer n;
register Frame frp;
E 14
I 14
integer n;
Frame frp;
E 14
{
D 14
    register Word w;
E 14
I 14
    Word w;
E 14

    if (frp == nil) {
	w = reg(n);
    } else {
	switch (n) {
	    case ARGP:
		w = frp->save_ap;
		break;

	    case FRP:
		w = frp->save_fp;
		break;

	    case STKP:
		w = reg(STKP);
		break;

	    case PROGCTR:
		w = frp->save_pc;
		break;

	    default:
		assert(n >= 0 and n < NSAVEREG);
		w = frp->save_reg[n];
		break;
	}
    }
    return w;
}

/*
 * Return the nth argument to the current procedure.
 */

public Word argn(n, frp)
D 14
Integer n;
E 14
I 14
integer n;
E 14
Frame frp;
{
    Word w;

    dread(&w, args_base(frp) + (n * sizeof(Word)), sizeof(w));
    return w;
}

/*
D 14
 * Calculate the entry address for a procedure or function parameter,
 * given the address of the descriptor.
E 14
I 14
 * Print a list of currently active blocks starting with most recent.
E 14
 */

D 14
public Address fparamaddr(a)
Address a;
E 14
I 14
public wherecmd()
E 14
{
D 14
    Address r;

    dread(&r, a, sizeof(r));
    return r;
E 14
I 14
    walkstack(false);
E 14
}

/*
D 14
 * Print a list of currently active blocks starting with most recent.
E 14
I 14
 * Print the variables in the given frame or the current one if nil.
E 14
 */

D 14
public wherecmd()
E 14
I 14
public dump (func)
Symbol func;
E 14
{
D 14
    walkstack(false);
E 14
I 14
    Symbol f;
    Frame frp;

    if (func == nil) {
	f = curfunc;
	if (curframe != nil) {
	    frp = curframe;
	} else {
	    frp = findframe(f);
	}
    } else {
	f = func;
	frp = findframe(f);
    }
    showaggrs = true;
    printcallinfo(f, frp);
    dumpvars(f, frp);
E 14
}

/*
D 14
 * Dump the world to the given file.
 * Like "where", but variables are dumped also.
E 14
I 14
 * Dump all values.
E 14
 */

D 14
public dump()
E 14
I 14
public dumpall ()
E 14
{
    walkstack(true);
}

/*
 * Walk the stack of active procedures printing information
 * about each active procedure.
 */

D 4
#define lastfunc(f)     (f == program)

E 4
private walkstack(dumpvariables)
Boolean dumpvariables;
{
D 14
    register Frame frp;
D 11
    register Symbol f;
E 11
    register Boolean save;
    register Lineno line;
E 14
I 14
    Frame frp;
    boolean save;
E 14
I 11
    Symbol f;
E 11
    struct Frame frame;

D 14
    if (notstarted(process)) {
E 14
I 14
    if (notstarted(process) or isfinished(process)) {
E 14
	error("program is not active");
    } else {
	save = walkingstack;
	walkingstack = true;
I 14
	showaggrs = dumpvariables;
E 14
	frp = &frame;
D 11
	getcurframe(frp);
	f = whatblock(frp->save_pc);
E 11
I 11
	getcurfunc(frp, &f);
E 11
D 14
	do {
	    printf("%s", symname(f));
D 8
	    printparams(f, frp);
E 8
I 8
	    if (not isinline(f)) {
		printparams(f, frp);
	    }
E 8
D 3
	    line = srcline(frp->save_pc);
E 3
I 3
	    line = srcline(frp->save_pc - 1);
E 3
	    if (line != 0) {
		printf(", line %d", line);
D 3
		printf(" in \"%s\"\n", srcfilename(frp->save_pc));
E 3
I 3
		printf(" in \"%s\"\n", srcfilename(frp->save_pc - 1));
E 3
	    } else {
		printf(" at 0x%x\n", frp->save_pc);
	    }
E 14
I 14
	for (;;) {
	    printcallinfo(f, frp);
E 14
	    if (dumpvariables) {
		dumpvars(f, frp);
		putchar('\n');
	    }
D 8
	    frp = nextframe(frp);
	    if (frp != nil) {
		f = whatblock(frp->save_pc);
E 8
I 8
D 11
	    if (isinline(f)) {
		f = container(f);
	    } else {
		frp = nextframe(frp);
		if (frp != nil) {
		    f = whatblock(frp->save_pc);
		}
E 8
	    }
E 11
I 11
	    frp = nextfunc(frp, &f);
E 11
D 4
	} while (frp != nil and not lastfunc(f));
E 4
I 4
D 14
	} while (frp != nil and f != program);
E 14
I 14
	    if (frp == nil or f == program) {
		break;
	    }
	}
E 14
E 4
	if (dumpvariables) {
	    printf("in \"%s\":\n", symname(program));
	    dumpvars(program, nil);
	    putchar('\n');
	}
	walkingstack = save;
    }
}

/*
I 14
 * Print out the information about a call, i.e.,
 * routine name, parameter values, and source location.
 */

private printcallinfo (f, frp)
Symbol f;
Frame frp;
{
    Lineno line;
    Address savepc;

    savepc = frp->save_pc;
    if (frp->save_fp != reg(FRP)) {
	savepc -= 1;
    }
    printname(stdout, f);
    if (not isinline(f)) {
	printparams(f, frp);
    }
    line = srcline(savepc);
    if (line != 0) {
	printf(", line %d", line);
	printf(" in \"%s\"\n", srcfilename(savepc));
    } else {
	printf(" at 0x%x\n", savepc);
    }
}

/*
E 14
I 11
 * Set the current function to the given symbol.
 * We must adjust "curframe" so that subsequent operations are
 * not confused; for simplicity we simply clear it.
 */

public setcurfunc (f)
Symbol f;
{
    curfunc = f;
    curframe = nil;
}

/*
I 14
 * Return the frame for the current function.
 * The space for the frame is allocated statically.
 */

public Frame curfuncframe ()
{
    static struct Frame frame;
    Frame frp;

    if (curframe == nil) {
	frp = findframe(curfunc);
	curframe = &curframerec;
	*curframe = *frp;
    } else {
	frp = &frame;
	*frp = *curframe;
    }
    return frp;
}

/*
E 14
 * Set curfunc to be N up/down the stack from its current value.
 */

public up (n)
integer n;
{
    integer i;
    Symbol f;
    Frame frp;
    boolean done;

    if (not isactive(program)) {
	error("program is not active");
    } else if (curfunc == nil) {
	error("no current function");
    } else {
	i = 0;
	f = curfunc;
D 14
	if (curframe != nil) {
	    frp = curframe;
	} else {
	    frp = findframe(f);
	}
E 14
I 14
	frp = curfuncframe();
E 14
	done = false;
	do {
	    if (frp == nil) {
		done = true;
		error("not that many levels");
	    } else if (i >= n) {
		done = true;
		curfunc = f;
		curframe = &curframerec;
		*curframe = *frp;
I 14
		showaggrs = false;
		printcallinfo(curfunc, curframe);
E 14
	    } else if (f == program) {
		done = true;
		error("not that many levels");
	    } else {
		frp = nextfunc(frp, &f);
	    }
	    ++i;
	} while (not done);
    }
}

public down (n)
integer n;
{
    integer i, depth;
D 14
    register Frame frp;
E 14
I 14
    Frame frp, curfrp;
E 14
    Symbol f;
    struct Frame frame;

    if (not isactive(program)) {
	error("program is not active");
    } else if (curfunc == nil) {
	error("no current function");
    } else {
	depth = 0;
	frp = &frame;
	getcurfunc(frp, &f);
	if (curframe == nil) {
I 14
	    curfrp = findframe(curfunc);
E 14
	    curframe = &curframerec;
D 14
	    *curframe = *(findframe(curfunc));
E 14
I 14
	    *curframe = *curfrp;
E 14
	}
	while ((f != curfunc or !frameeq(frp, curframe)) and f != nil) {
	    frp = nextfunc(frp, &f);
	    ++depth;
	}
	if (f == nil or n > depth) {
	    error("not that many levels");
	} else {
	    depth -= n;
	    frp = &frame;
	    getcurfunc(frp, &f);
	    for (i = 0; i < depth; i++) {
		frp = nextfunc(frp, &f);
		assert(frp != nil);
	    }
	    curfunc = f;
	    *curframe = *frp;
I 14
	    showaggrs = false;
	    printcallinfo(curfunc, curframe);
E 14
	}
    }
}

/*
E 11
 * Find the entry point of a procedure or function.
 */

D 14
public findbeginning(f)
E 14
I 14
public findbeginning (f)
E 14
Symbol f;
{
D 11
    f->symvalue.funcv.beginaddr += 2;
E 11
I 11
    if (isinternal(f)) {
	f->symvalue.funcv.beginaddr += 15;
    } else {
	f->symvalue.funcv.beginaddr += 2;
    }
E 11
}

/*
 * Return the address corresponding to the first line in a function.
 */

public Address firstline(f)
Symbol f;
{
    Address addr;

    addr = codeloc(f);
    while (linelookup(addr) == 0 and addr < objsize) {
	++addr;
    }
    if (addr == objsize) {
	addr = -1;
    }
    return addr;
}

/*
 * Catcher drops strike three ...
 */

public runtofirst()
{
    Address addr;

    addr = pc;
    while (linelookup(addr) == 0 and addr < objsize) {
	++addr;
    }
    if (addr < objsize) {
	stepto(addr);
    }
}

/*
 * Return the address corresponding to the end of the program.
 *
 * We look for the entry to "exit".
 */

public Address lastaddr()
{
D 14
    register Symbol s;
E 14
I 14
    Symbol s;
E 14

    s = lookup(identname("exit", true));
    if (s == nil) {
	panic("can't find exit");
    }
    return codeloc(s);
}

/*
 * Decide if the given function is currently active.
 *
 * We avoid calls to "findframe" during a stack trace for efficiency.
 * Presumably information evaluated while walking the stack is active.
 */

public Boolean isactive(f)
Symbol f;
{
D 14
    register Boolean b;
E 14
I 14
    Boolean b;
E 14

    if (isfinished(process)) {
	b = false;
    } else {
	if (walkingstack or f == program or
	  (ismodule(f) and isactive(container(f)))) {
	    b = true;
	} else {
	    b = (Boolean) (findframe(f) != nil);
	}
    }
    return b;
}

/*
 * Evaluate a call to a procedure.
 */

D 14
public callproc(procnode, arglist)
Node procnode;
Node arglist;
E 14
I 14
public callproc(exprnode, isfunc)
Node exprnode;
boolean isfunc;
E 14
{
I 14
    Node procnode, arglist;
E 14
    Symbol proc;
D 14
    Integer argc;
E 14
I 14
    integer argc;
E 14

I 14
    procnode = exprnode->value.arg[0];
    arglist = exprnode->value.arg[1];
E 14
    if (procnode->op != O_SYM) {
	beginerrmsg();
	fprintf(stderr, "can't call \"");
	prtree(stderr, procnode);
	fprintf(stderr, "\"");
	enderrmsg();
    }
    assert(procnode->op == O_SYM);
    proc = procnode->value.sym;
    if (not isblock(proc)) {
	error("\"%s\" is not a procedure or function", symname(proc));
    }
I 14
    endproc.isfunc = isfunc;
    endproc.callnode = exprnode;
    endproc.cmdnode = topnode;
E 14
    pushenv();
    pc = codeloc(proc);
    argc = pushargs(proc, arglist);
    beginproc(proc, argc);
D 14
    isstopped = true;
    event_once(build(O_EQ, build(O_SYM, pcsym), build(O_SYM, retaddrsym)),
	buildcmdlist(build(O_PROCRTN, proc)));
D 11
    cont();
E 11
I 11
    cont(0);
E 14
I 14
    event_once(
	build(O_EQ, build(O_SYM, pcsym), build(O_SYM, retaddrsym)),
	buildcmdlist(build(O_PROCRTN, proc))
    );
    isstopped = false;
    if (not bpact()) {
	isstopped = true;
	cont(0);
    }
    /*
     * bpact() won't return true, it will call printstatus() and go back
     * to command input if a breakpoint is found.
     */
E 14
E 11
    /* NOTREACHED */
}

/*
 * Push the arguments on the process' stack.  We do this by first
 * evaluating them on the "eval" stack, then copying into the process'
 * space.
 */

D 14
private Integer pushargs(proc, arglist)
E 14
I 14
private integer pushargs(proc, arglist)
E 14
Symbol proc;
Node arglist;
{
    Stack *savesp;
    int argc, args_size;

    savesp = sp;
D 16
    argc = evalargs(proc, arglist);
E 16
I 16
    if (varIsSet("$unsafecall")) {
	argc = unsafe_evalargs(proc, arglist);
    } else {
	argc = evalargs(proc, arglist);
    }
E 16
    args_size = sp - savesp;
    setreg(STKP, reg(STKP) - args_size);
    dwrite(savesp, reg(STKP), args_size);
    sp = savesp;
    return argc;
}

/*
D 11
 * Evaluate arguments left-to-right.
E 11
I 11
 * Check to see if an expression is correct for a given parameter.
 * If the given parameter is false, don't worry about type inconsistencies.
 *
 * Return whether or not it is ok.
E 11
 */

I 11
private boolean chkparam (actual, formal, chk)
Node actual;
Symbol formal;
boolean chk;
{
    boolean b;

    b = true;
    if (chk) {
	if (formal == nil) {
	    beginerrmsg();
	    fprintf(stderr, "too many parameters");
	    b = false;
	} else if (not compatible(formal->type, actual->nodetype)) {
	    beginerrmsg();
	    fprintf(stderr, "type mismatch for %s", symname(formal));
	    b = false;
	}
    }
D 14
    if (b and formal != nil and isvarparam(formal) and
	not isopenarray(formal->type) and actual->op != O_RVAL)
    {
E 14
I 14
    if (b and formal != nil and
	isvarparam(formal) and not isopenarray(formal->type) and
	not (
	    actual->op == O_RVAL or actual->nodetype == t_addr or
	    (
		actual->op == O_TYPERENAME and
		(
		    actual->value.arg[0]->op == O_RVAL or
		    actual->value.arg[0]->nodetype == t_addr
		)
	    )
	)
    ) {
E 14
	beginerrmsg();
	fprintf(stderr, "expected variable, found \"");
	prtree(stderr, actual);
	fprintf(stderr, "\"");
	b = false;
    }
    return b;
}

/*
 * Pass an expression to a particular parameter.
 *
 * Normally we pass either the address or value, but in some cases
 * (such as C strings) we want to copy the value onto the stack and
 * pass its address.
I 14
 *
 * Another special case raised by strings is the possibility that
 * the actual parameter will be larger than the formal, even with
 * appropriate type-checking.  This occurs because we assume during
 * evaluation that strings are null-terminated, whereas some languages,
 * notably Pascal, do not work under that assumption.
E 14
 */

private passparam (actual, formal)
Node actual;
Symbol formal;
{
    boolean b;
    Address addr;
    Stack *savesp;
D 14
    integer paramsize;
E 14
I 14
    integer actsize, formsize;
E 14

D 14
    if (isvarparam(formal) and not isopenarray(formal->type)) {
E 14
I 14
    if (formal != nil and isvarparam(formal) and
	(not isopenarray(formal->type))
    ) {
E 14
	addr = lval(actual->value.arg[0]);
	push(Address, addr);
    } else if (passaddr(formal, actual->nodetype)) {
	savesp = sp;
	eval(actual);
D 14
	paramsize = sp - savesp;
	setreg(STKP, reg(STKP) - paramsize);
	dwrite(savesp, reg(STKP), paramsize);
E 14
I 14
	actsize = sp - savesp;
	setreg(STKP,
	    reg(STKP) - ((actsize + sizeof(Word) - 1) & ~(sizeof(Word) - 1))
	);
	dwrite(savesp, reg(STKP), actsize);
E 14
	sp = savesp;
	push(Address, reg(STKP));
	if (formal != nil and isopenarray(formal->type)) {
D 14
	    push(integer, paramsize div size(formal->type->type));
E 14
I 14
	    push(integer, actsize div size(formal->type->type));
E 14
	}
I 14
    } else if (formal != nil) {
	formsize = size(formal);
	savesp = sp;
	eval(actual);
	actsize = sp - savesp;
	if (actsize > formsize) {
	    sp -= (actsize - formsize);
	}
E 14
    } else {
	eval(actual);
    }
}

/*
 * Evaluate an argument list left-to-right.
 */

E 11
D 14
private Integer evalargs(proc, arglist)
E 14
I 14
private integer evalargs(proc, arglist)
E 14
Symbol proc;
Node arglist;
{
D 11
    Node p, exp;
    Symbol arg;
E 11
I 11
    Node p, actual;
    Symbol formal;
E 11
    Stack *savesp;
D 11
    Address addr;
E 11
D 14
    Integer count;
E 14
I 14
    integer count;
E 14
I 11
    boolean chk;
E 11

    savesp = sp;
    count = 0;
D 11
    arg = proc->chain;
E 11
I 11
    formal = proc->chain;
    chk = (boolean) (not nosource(proc));
E 11
    for (p = arglist; p != nil; p = p->value.arg[1]) {
D 11
	if (p->op != O_COMMA) {
	    panic("evalargs: arglist missing comma");
	}
	if (arg == nil) {
E 11
I 11
	assert(p->op == O_COMMA);
	actual = p->value.arg[0];
	if (not chkparam(actual, formal, chk)) {
	    fprintf(stderr, " in call to %s", symname(proc));
E 11
	    sp = savesp;
D 11
	    error("too many parameters to %s", symname(proc));
E 11
I 11
	    enderrmsg();
E 11
	}
D 11
	exp = p->value.arg[0];
	if (not compatible(arg->type, exp->nodetype)) {
	    sp = savesp;
	    error("expression for parameter %s is of wrong type", symname(arg));
E 11
I 11
	passparam(actual, formal);
	if (formal != nil) {
	    formal = formal->chain;
E 11
	}
D 11
	if (arg->class == REF) {
	    if (exp->op != O_RVAL) {
		sp = savesp;
		error("variable expected for parameter \"%s\"", symname(arg));
	    }
	    addr = lval(exp->value.arg[0]);
	    push(Address, addr);
	} else {
	    eval(exp);
	}
	arg = arg->chain;
E 11
	++count;
    }
D 11
    if (arg != nil) {
	sp = savesp;
	error("not enough parameters to %s", symname(proc));
E 11
I 11
    if (chk) {
	if (formal != nil) {
	    sp = savesp;
	    error("not enough parameters to %s", symname(proc));
	}
I 16
    }
    return count;
}

/*
 * Evaluate an argument list without concern for matching the formal
 * parameters of a function in type or quantity.  Useful for functions
 * like C's printf().
 */

private integer unsafe_evalargs(proc, arglist)
Symbol proc;
Node arglist;
{
    Node p;
    Integer count;

    count = 0;
    for (p = arglist; p != nil; p = p->value.arg[1]) {
	assert(p->op == O_COMMA);
	eval(p->value.arg[0]);
	++count;
E 16
E 11
    }
    return count;
}

public procreturn(f)
Symbol f;
{
I 14
    integer retvalsize;
    Node tmp;
    char *copy;

E 14
    flushoutput();
D 14
    putchar('\n');
    printname(stdout, f);
D 13
    printf(" returns successfully\n", symname(f));
E 13
I 13
    printf(" returns successfully\n");
E 14
E 13
    popenv();
I 14
    if (endproc.isfunc) {
	retvalsize = size(f->type);
	if (retvalsize > sizeof(long)) {
	    pushretval(retvalsize, true);
	    copy = newarr(char, retvalsize);
	    popn(retvalsize, copy);
	    tmp = build(O_SCON, copy);
	} else {
	    tmp = build(O_LCON, (long) (reg(0)));
	}
	tmp->nodetype = f->type;
	tfree(endproc.callnode);
	*(endproc.callnode) = *(tmp);
	dispose(tmp);
	eval(endproc.cmdnode);
    } else {
	putchar('\n');
	printname(stdout, f);
D 17
	printf(" returns successfully\n", symname(f));
E 17
I 17
	printf("%s returns successfully\n", symname(f));
E 17
    }
E 14
    erecover();
}

/*
 * Push the current environment.
 */

private pushenv()
{
    push(Address, pc);
    push(Lineno, curline);
    push(String, cursource);
    push(Boolean, isstopped);
    push(Symbol, curfunc);
I 11
    push(Frame, curframe);
    push(struct Frame, curframerec);
I 14
    push(CallEnv, endproc);
E 14
E 11
    push(Word, reg(PROGCTR));
    push(Word, reg(STKP));
}

/*
 * Pop back to the real world.
 */

public popenv()
{
D 14
    register String filename;
E 14
I 14
    String filename;
E 14

    setreg(STKP, pop(Word));
    setreg(PROGCTR, pop(Word));
I 14
    endproc = pop(CallEnv);
E 14
I 11
    curframerec = pop(struct Frame);
    curframe = pop(Frame);
E 11
    curfunc = pop(Symbol);
    isstopped = pop(Boolean);
    filename = pop(String);
    curline = pop(Lineno);
    pc = pop(Address);
    setsource(filename);
}

/*
 * Flush the debuggee's standard output.
 *
 * This is VERY dependent on the use of stdio.
 */

public flushoutput()
{
D 14
    register Symbol p, iob;
    register Stack *savesp;
E 14
I 14
    Symbol p, iob;
    Stack *savesp;
E 14

    p = lookup(identname("fflush", true));
    while (p != nil and not isblock(p)) {
	p = p->next_sym;
    }
    if (p != nil) {
	iob = lookup(identname("_iob", true));
	if (iob != nil) {
	    pushenv();
	    pc = codeloc(p);
	    savesp = sp;
	    push(long, address(iob, nil) + sizeof(struct _iobuf));
	    setreg(STKP, reg(STKP) - sizeof(long));
	    dwrite(savesp, reg(STKP), sizeof(long));
	    sp = savesp;
	    beginproc(p, 1);
	    stepto(return_addr());
	    popenv();
	}
    }
}
E 1
