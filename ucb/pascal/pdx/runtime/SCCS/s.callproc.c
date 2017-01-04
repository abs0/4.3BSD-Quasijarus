h06046
s 00053/00002/00242
d D 5.2 87/04/07 15:55:50 mckusick 4 3
c port to tahoe by Nir peleg of CCI
e
s 00008/00003/00236
d D 5.1 85/06/06 11:47:15 dist 3 2
c Add copyright
e
s 00001/00001/00238
d D 1.2 82/02/02 13:50:20 linton 2 1
c argument processing is done before preparing to change 
c environments so that an error in the arguments doesn't leave pdx 
c in a weird state
e
s 00239/00000/00000
d D 1.1 82/01/18 19:21:01 linton 1 0
c date and time created 82/01/18 19:21:01 by linton
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
I 4

E 4
E 3
/*
 * Evaluate a call to a procedure.
 *
 * This file is a botch as far as modularity is concerned.
 */

#include "defs.h"
#include "runtime.h"
#include "sym.h"
#include "tree.h"
#include "breakpoint.h"
#include "machine.h"
#include "process.h"
#include "source.h"
#include "frame.rep"
#include "sym/classes.h"
#include "sym/sym.rep"
#include "tree/tree.rep"
#include "process/process.rep"
#include "process/pxinfo.h"

LOCAL ADDRESS retaddr;
I 4
#ifdef tahoe
BOOLEAN didret;
#endif
E 4

/*
 * Controlling logic of procedure calling.
 * Calling a procedure before ever executing the program must
 * be special cased.
 */

callproc(procnode, arglist)
NODE *procnode;
NODE *arglist;
{
D 4
	SYM *proc;
E 4
I 4
	register SYM *proc;
#ifdef tahoe
	register int tmpsp, tmptmp;
	extern BOOLEAN shouldrestart;
E 4

I 4
	if (shouldrestart) {
		initstart();
	}
#endif
E 4
	if (pc == 0) {
		curline = firstline(program);
		setbp(curline);
		resume();
		unsetbp(curline);
	}
	proc = procnode->nameval;
	if (!isblock(proc)) {
		error("\"%s\" is not a procedure or function", proc->symbol);
	}
I 4
#ifdef tahoe
	doret(process);
	tmpsp = process->sp;
#endif
E 4
D 2
	pushenv(proc->symvalue.funcv.codeloc);
E 2
	pushargs(proc, arglist);
I 4
#ifdef tahoe
	tmptmp = tmpsp;
	tmpsp = process->sp;
	process->sp = tmptmp;
#endif
E 4
I 2
	pushenv(proc->symvalue.funcv.codeloc);
I 4
#ifdef tahoe
	process->sp = tmpsp;
#endif
E 4
E 2
	pushframe(proc->blkno);
	execute(proc);
	/* NOTREACHED */
}

/*
 * Push the arguments on the process' stack.  We do this by first
 * evaluating them on the "eval" stack, then copying into the process'
 * space.
 */

LOCAL pushargs(proc, arglist)
SYM *proc;
NODE *arglist;
{
	STACK *savesp;
	int args_size;

	savesp = sp;
I 4
#ifdef tahoe
	/*
	 * evalargs hopefully keeps stack aligned, so we won't bother
	 * aligning it afterwards, neither will we align process->sp
	 * after subtracting args_size.
	 */
#endif
E 4
	evalargs(proc->symbol, proc->chain, arglist);
	args_size = sp - savesp;
	process->sp -= args_size;
	dwrite(savesp, process->sp, args_size);
	sp = savesp;
}

/*
 * Evaluate arguments right-to-left because the eval stack
 * grows up, px's stack grows down.
 */

LOCAL evalargs(procname, arg, explist)
char *procname;
SYM *arg;
NODE *explist;
{
	NODE *exp;
	STACK *savesp;
	ADDRESS addr;

	if (arg == NIL) {
		if (explist != NIL) {
			error("too many parameters to \"%s\"", procname);
		}
	} else if (explist == NIL) {
		error("not enough parameters to \"%s\"", procname);
	} else {
		if (explist->op != O_COMMA) {
			panic("evalargs: arglist missing comma");
		}
		savesp = sp;
		evalargs(procname, arg->chain, explist->right);
		exp = explist->left;
		if (!compatible(arg->type, exp->nodetype)) {
			sp = savesp;
			trerror("%t is not the same type as parameter \"%s\"",
				exp, arg->symbol);
		}
		if (arg->class == REF) {
			if (exp->op != O_RVAL) {
				sp = savesp;
				error("variable expected for parameter \"%s\"", arg->symbol);
			}
			addr = lval(exp->left);
			push(ADDRESS, addr);
		} else {
			eval(exp);
		}
	}
}

/*
 * Simulate a CALL instruction by pushing the appropriate
 * stack frame information.
 *
D 4
 * Massage register 10 appropriately since it contains the
E 4
I 4
 * Massage register 10 or 11 appropriately since it contains the
E 4
 * stack frame pointer.
 */

LOCAL pushframe(b)
int b;
{
	ADDRESS *newdp;
	FRAME callframe;

	retaddr = program->symvalue.funcv.codeloc;

/*
 * This stuff is set by the callee, just here to take up space.
 */
	callframe.stackref = 0;
	callframe.file = 0;
	callframe.blockp = 0;
	callframe.save_loc = NIL;
	callframe.save_disp = NIL;

/*
 * This is the useful stuff.
 */
	callframe.save_dp = curdp();
	callframe.save_pc = retaddr + ENDOFF;
	callframe.save_lino = 0;
	newdp = DISPLAY + (2 * b);
	dwrite(&newdp, DP, sizeof(newdp));
	process->sp -= sizeof(callframe);
	dwrite(&callframe, process->sp, sizeof(callframe));
I 4
#ifdef tahoe
	process->reg[11] = process->sp;
#else
E 4
	process->reg[10] = process->sp;
I 4
#endif
E 4
}

/*
 * Execute the procedure.  This routine does NOT return because it
 * calls "cont", which doesn't return.  We set a CALLPROC breakpoint
 * at "retaddr", the address where the called routine will return.
 *
 * The action for a CALLPROC is to call "procreturn" where we restore
 * the environment.
 */

LOCAL execute(f)
SYM *f;
{
	isstopped = TRUE;
	addbp(retaddr, CALLPROC, f, NIL, NIL, 0);
	cont();
	/* NOTREACHED */
}

procreturn(f)
SYM *f;
{
	int len;

I 4
#ifdef tahoe
	doret(process);
#endif
E 4
	printf("%s returns ", f->symbol);
	if (f->class == FUNC) {
		len = size(f->type);
		dread(sp, process->sp, len);
I 4
#ifdef tahoe
		len = (len + 3) & ~3;
#endif
E 4
		sp += len;
		printval(f->type);
		putchar('\n');
	} else {
		printf("successfully\n");
	}
	popenv();
}

/*
 * Push the current environment.
 *
 * This involves both saving pdx and interpreter values.
 * LOOPADDR is the address of the main interpreter loop.
 */

LOCAL pushenv(newpc)
ADDRESS newpc;
{
I 4
#ifdef tahoe
	/* this should be done somewhere else, but... */
	INTFP = process->fp;
#endif
E 4
	push(ADDRESS, pc);
	push(LINENO, curline);
	push(char *, cursource);
	push(BOOLEAN, isstopped);
	push(SYM *, curfunc);
	push(WORD, process->pc);
	push(WORD, process->sp);
	process->pc = LOOPADDR;
	pc = newpc;
I 4
#ifdef tahoe
	process->reg[12] = pc + ENDOFF;
#else
E 4
	process->reg[11] = pc + ENDOFF;
I 4
#endif
E 4
}

/*
 * Pop back to the real world.
 */

popenv()
{
	register PROCESS *p;
	char *filename;

	p = process;
	p->sp = pop(WORD);
	p->pc = pop(WORD);
	curfunc = pop(SYM *);
	isstopped = pop(BOOLEAN);
	filename = pop(char *);
	curline = pop(LINENO);
	pc = pop(ADDRESS);
I 4
#ifdef tahoe
	p->reg[12] = pc + 1 + ENDOFF;
#endif
E 4
	if (filename != cursource) {
		skimsource(filename);
	}
}
E 1
