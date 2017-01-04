h63158
s 00071/00033/01442
d D 5.3 88/01/12 01:11:01 donn 21 20
c merge in latest Linton version
e
s 00029/00008/01446
d D 5.2 86/02/23 16:18:21 sam 20 19
c add new signals; move rloc to machine file; add pio buffer alignment 
c kludge for tahoe; make ARGP vax specific; move some include files to machine file
e
s 00008/00002/01446
d D 5.1 85/05/31 10:14:43 dist 19 18
c Add copyright
e
s 00192/00110/01256
d D 1.17 85/03/01 20:28:32 linton 18 17
c update to version 3.0
e
s 00014/00027/01352
d D 1.16 84/10/13 18:36:47 sam 17 16
c use global definitions from <ptrace.h>
e
s 00032/00026/01347
d D 1.15 84/08/12 15:13:23 sam 16 15
c handle signal lists (with names) for ignore and catch
e
s 00091/00000/01282
d D 1.14 84/08/12 13:22:21 sam 15 14
c add real aliases; rewrite lexical scanner
e
s 00001/00003/01281
d D 1.13 84/06/23 11:43:01 sam 14 12
i 13
c merge linton branch delta trail
e
s 00227/00054/01057
d D 1.12.1.1 84/06/23 10:49:15 sam 13 12
c branch delta of linton changes from net.sources
e
s 00037/00023/01074
d D 1.12 83/08/19 13:30:40 linton 12 11
c now reports when writing to the process' instruction space fails, 
c some stuff with signals is slightly cleaner, but there is a problem remaining 
c that has to do with intelligently "single-stepping" in the presence of 
c pending signals
e
s 00011/00004/01086
d D 1.11 83/08/07 18:31:42 linton 11 10
c added calls to "ptraced(pid)" and "unptraced(pid)" to make 
c pwait (in library.c) ignore spurious returns from wait -- this caused 
c a rather annoying bug to occur when doing a "sh" command
e
s 00001/00001/01089
d D 1.10 83/07/07 23:31:13 linton 10 9
c upped the maximum number of arguments on a command line to 100
e
s 00003/00000/01087
d D 1.9 83/05/17 23:01:49 linton 9 8
c now computes source position for a core dump so that things such as 
c pc are set appropriately
e
s 00044/00018/01043
d D 1.8 83/04/08 01:21:23 linton 8 7
c cont now takes an argument which is the signal that is passed 
c to the debuggee, and stepping in the main execution loop is now considerably 
c more efficient as it only single-steps to the next source line if the 
c situation calls for it
e
s 00004/00001/01057
d D 1.7 83/04/03 20:29:48 linton 7 6
c changed execvp to execv
e
s 00005/00002/01053
d D 1.6 83/03/30 01:46:33 linton 6 5
c now saves/restores process' tty state before/after execution
e
s 00008/00002/01047
d D 1.5 83/03/13 15:20:12 linton 5 4
c changed error handling for illegal addresses
e
s 00039/00018/01010
d D 1.4 83/02/20 17:52:45 linton 4 3
c now uses vfork instead for fork, also has central routine 
c for printing source location (which now includes current function)
e
s 00023/00024/01005
d D 1.3 82/12/18 23:30:09 linton 3 2
c changed <sys/reg.h> to <machine/reg.h> include
e
s 00001/00001/01028
d D 1.2 82/12/15 04:21:41 linton 2 1
c fixed @(#) stuff
e
s 01029/00000/00000
d D 1.1 82/12/15 04:08:29 linton 1 0
c date and time created 82/12/15 04:08:29 by linton
e
u
U
f b 
t
T
I 1
D 19
/* Copyright (c) 1982 Regents of the University of California */
E 19
I 19
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 19

D 2
static char sccsid[] = "@(#)%Z%%M% %I% %G%";
E 2
I 2
D 13
static char sccsid[] = "%Z%%M% %I% %G%";
E 13
I 13
D 14
static char sccsid[] = "@(#)process.c 1.12 8/19/83";
E 13
E 2

I 13
static char rcsid[] = "$Header: process.c,v 1.3 84/03/27 10:23:24 linton Exp $";
E 14
I 14
D 19
static	char sccsid[] = "%W% (Berkeley) %G%";
E 19
I 19
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 19
E 14

I 18
D 21
static char rcsid[] = "$Header: process.c,v 1.5 84/12/26 10:41:37 linton Exp $";
E 21
I 21
static char rcsid[] = "$Header: process.c,v 1.4 88/01/10 00:49:31 donn Exp $";
E 21

E 18
E 13
/*
 * Process management.
 *
 * This module contains the routines to manage the execution and
 * tracing of the debuggee process.
 */

#include "defs.h"
#include "process.h"
#include "machine.h"
#include "events.h"
#include "tree.h"
I 12
#include "eval.h"
E 12
#include "operators.h"
#include "source.h"
#include "object.h"
#include "mappings.h"
#include "main.h"
#include "coredump.h"
#include <signal.h>
#include <errno.h>
I 17
D 18
#include <ptrace.h>
E 18
E 17
D 20
#include <sys/param.h>
I 13
#include <sys/dir.h>
#include <sys/user.h>
E 13
D 3
#include <sys/reg.h>
E 3
I 3
#include <machine/reg.h>
E 20
E 3
#include <sys/stat.h>

#ifndef public

typedef struct Process *Process;

Process process;

I 12
#define DEFSIG -1

E 12
#include "machine.h"

#endif

#define NOTSTARTED 1
#define STOPPED 0177
#define FINISHED 0

/*
D 13
 * Cache-ing of instruction segment is done to reduce the number
 * of system calls.
E 13
I 13
 * A cache of the instruction segment is kept to reduce the number
 * of system calls.  Might be better just to read the entire
 * code space into memory.
E 13
 */

D 21
#define CSIZE 1003       /* size of instruction cache */
E 21
I 21
#define CACHESIZE 1003
E 21

typedef struct {
    Word addr;
    Word val;
} CacheWord;

/*
 * This structure holds the information we need from the user structure.
 */

struct Process {
    int pid;			/* process being traced */
D 6
    int mask;			/* ps */
    Word reg[NREG];		/* process's registers */
E 6
I 6
    int mask;			/* process status word */
    Word reg[NREG];		/* process' registers */
E 6
    Word oreg[NREG];		/* registers when process last stopped */
    short status;		/* either STOPPED or FINISHED */
    short signo;		/* signal that stopped process */
I 16
D 18
    short sigcode;		/* auxiliary signal info code */
E 18
I 18
    short sigcode;		/* extra signal information */
E 18
E 16
    int exitval;		/* return value from exit() */
    long sigset;		/* bit array of traced signals */
D 21
    CacheWord word[CSIZE];	/* text segment cache */
E 21
I 21
    CacheWord word[CACHESIZE];	/* text segment cache */
E 21
I 6
    Ttyinfo ttyinfo;		/* process' terminal characteristics */
I 13
    Address sigstatus;		/* process' handler for current signal */
E 13
E 6
};

/*
 * These definitions are for the arguments to "pio".
 */

typedef enum { PREAD, PWRITE } PioOp;
typedef enum { TEXTSEG, DATASEG } PioSeg;

private struct Process pbuf;

D 10
#define MAXNCMDARGS 10         /* maximum number of arguments to RUN */
E 10
I 10
D 18
#define MAXNCMDARGS 100         /* maximum number of arguments to RUN */
E 18
I 18
#define MAXNCMDARGS 1000         /* maximum number of arguments to RUN */
E 18
E 10

I 11
extern int errno;

E 11
private Boolean just_started;
private int argc;
private String argv[MAXNCMDARGS];
private String infile, outfile;

/*
 * Initialize process information.
 */

public process_init()
{
D 21
    register Integer i;
    Char buf[10];
E 21
I 21
    register integer i;
    char buf[10];
E 21

    process = &pbuf;
    process->status = (coredump) ? STOPPED : NOTSTARTED;
    setsigtrace();
D 21
    for (i = 0; i < NREG; i++) {
	sprintf(buf, "$r%d", i);
	defregname(identname(buf, false), i);
    }
I 20
#ifdef vax
E 20
    defregname(identname("$ap", true), ARGP);
I 20
#endif
E 21
I 21
#   if vax || tahoe
	for (i = 0; i < NREG; i++) {
	    sprintf(buf, "$r%d", i);
	    defregname(identname(buf, false), i);
	}
#	ifdef vax
	    defregname(identname("$ap", true), ARGP);
#	endif
#   else
#       ifdef mc68000
	    for (i = 0; i < 8; i++) {
		sprintf(buf, "$d%d", i);
		defregname(identname(buf, false), i);
		sprintf(buf, "$a%d", i);
		defregname(identname(buf, false), i + 8);
	    }
#       endif
#   endif
E 21
E 20
    defregname(identname("$fp", true), FRP);
    defregname(identname("$sp", true), STKP);
    defregname(identname("$pc", true), PROGCTR);
    if (coredump) {
	coredump_readin(process->mask, process->reg, process->signo);
I 9
	pc = process->reg[PROGCTR];
D 21
	getsrcpos();
E 21
E 9
    }
I 9
    arginit();
E 9
}

/*
 * Routines to get at process information from outside this module.
 */

public Word reg(n)
Integer n;
{
    register Word w;

    if (n == NREG) {
	w = process->mask;
    } else {
	w = process->reg[n];
    }
    return w;
}

public setreg(n, w)
Integer n;
Word w;
{
    process->reg[n] = w;
}

/*
 * Begin execution.
 *
 * We set a breakpoint at the end of the code so that the
 * process data doesn't disappear after the program terminates.
 */

private Boolean remade();

public start(argv, infile, outfile)
String argv[];
String infile, outfile;
{
    String pargv[4];
    Node cond;

    if (coredump) {
	coredump = false;
	fclose(corefile);
	coredump_close();
    }
    if (argv == nil) {
	argv = pargv;
	pargv[0] = objname;
	pargv[1] = nil;
    } else {
	argv[argc] = nil;
    }
I 18
    pstart(process, argv, infile, outfile);
E 18
    if (remade(objname)) {
	reinit(argv, infile, outfile);
    }
D 18
    pstart(process, argv, infile, outfile);
E 18
    if (process->status == STOPPED) {
D 21
	pc = 0;
E 21
I 21
	pc = CODESTART;
E 21
D 13
	curfunc = program;
E 13
I 13
	setcurfunc(program);
E 13
	if (objsize != 0) {
	    cond = build(O_EQ, build(O_SYM, pcsym), build(O_LCON, lastaddr()));
	    event_once(cond, buildcmdlist(build(O_ENDX)));
	}
    }
}

/*
 * Check to see if the object file has changed since the symbolic
 * information last was read.
 */

private time_t modtime;

private Boolean remade(filename)
String filename;
{
    struct stat s;
    Boolean b;

    stat(filename, &s);
    b = (Boolean) (modtime != 0 and modtime < s.st_mtime);
    modtime = s.st_mtime;
    return b;
}

/*
 * Set up what signals we want to trace.
 */

private setsigtrace()
{
    register Integer i;
    register Process p;

    p = process;
    for (i = 1; i <= NSIG; i++) {
	psigtrace(p, i, true);
    }
    psigtrace(p, SIGHUP, false);
    psigtrace(p, SIGKILL, false);
    psigtrace(p, SIGALRM, false);
D 21
    psigtrace(p, SIGTSTP, false);
    psigtrace(p, SIGCONT, false);
E 21
I 21
#   ifdef SIGTSTP
	psigtrace(p, SIGTSTP, false);
	psigtrace(p, SIGCONT, false);
#   endif
E 21
    psigtrace(p, SIGCHLD, false);
I 20
    psigtrace(p, SIGWINCH, false);
E 20
}

/*
 * Initialize the argument list.
 */

public arginit()
{
    infile = nil;
    outfile = nil;
    argv[0] = objname;
    argc = 1;
}

/*
 * Add an argument to the list for the debuggee.
 */

public newarg(arg)
String arg;
{
    if (argc >= MAXNCMDARGS) {
	error("too many arguments");
    }
    argv[argc++] = arg;
}

/*
 * Set the standard input for the debuggee.
 */

public inarg(filename)
String filename;
{
    if (infile != nil) {
	error("multiple input redirects");
    }
    infile = filename;
}

/*
 * Set the standard output for the debuggee.
 * Probably should check to avoid overwriting an existing file.
 */

public outarg(filename)
String filename;
{
    if (outfile != nil) {
	error("multiple output redirect");
    }
    outfile = filename;
}

/*
 * Start debuggee executing.
 */

public run()
{
    process->status = STOPPED;
    fixbps();
    curline = 0;
    start(argv, infile, outfile);
    just_started = true;
    isstopped = false;
D 12
    cont();
E 12
I 12
    cont(0);
E 12
}

/*
 * Continue execution wherever we left off.
 *
 * Note that this routine never returns.  Eventually bpact() will fail
 * and we'll call printstatus or step will call it.
 */

typedef int Intfunc();

private Intfunc *dbintr;
private intr();

D 18
#define succeeds    == true
#define fails       == false

E 18
D 8
public cont()
E 8
I 8
public cont(signo)
D 13
int signo;
E 13
I 13
integer signo;
E 13
E 8
{
I 13
    integer s;

E 13
    dbintr = signal(SIGINT, intr);
    if (just_started) {
	just_started = false;
    } else {
	if (not isstopped) {
	    error("can't continue execution");
	}
	isstopped = false;
D 8
	step();
E 8
I 8
	stepover();
E 8
    }
I 13
    s = signo;
E 13
    for (;;) {
	if (single_stepping) {
	    printnews();
	} else {
	    setallbps();
D 8
	    resume();
E 8
I 8
D 13
	    resume(signo);
E 13
I 13
	    resume(s);
E 13
E 8
	    unsetallbps();
I 13
	    s = DEFSIG;
E 13
D 18
	    if (bpact() fails) {
E 18
I 18
	    if (not isbperr() or not bpact()) {
E 18
		printstatus();
	    }
	}
D 8
	step();
E 8
I 8
	stepover();
E 8
    }
    /* NOTREACHED */
}

/*
D 18
 * This routine is called if we get an interrupt while "running" px
E 18
I 18
 * This routine is called if we get an interrupt while "running"
E 18
 * but actually in the debugger.  Could happen, for example, while
 * processing breakpoints.
 *
 * We basically just want to keep going; the assumption is
D 18
 * that when the process resumes it will get the interrupt
E 18
I 18
 * that when the process resumes it will get the interrupt,
E 18
 * which will then be handled.
 */

private intr()
{
    signal(SIGINT, intr);
}

public fixintr()
{
    signal(SIGINT, dbintr);
}

/*
 * Resume execution.
 */

D 8
public resume()
E 8
I 8
public resume(signo)
int signo;
E 8
{
    register Process p;

    p = process;
D 13
    if (traceexec) {
	printf("execution resumes at pc 0x%x\n", process->reg[PROGCTR]);
	fflush(stdout);
    }
E 13
D 8
    pcont(p);
E 8
I 8
    pcont(p, signo);
E 8
    pc = process->reg[PROGCTR];
D 13
    if (traceexec) {
	printf("execution stops at pc 0x%x on sig %d\n",
	    process->reg[PROGCTR], p->signo);
	fflush(stdout);
    }
E 13
I 7
    if (p->status != STOPPED) {
D 8
	error("program unexpectedly exited with %d", p->exitval);
E 8
I 8
	if (p->signo != 0) {
	    error("program terminated by signal %d", p->signo);
D 12
	} else {
E 12
I 12
	} else if (not runfirst) {
E 12
D 18
	    error("program unexpectedly exited with %d", p->exitval);
E 18
I 18
	    if (p->exitval == 0) {
		error("program exited");
	    } else {
		error("program exited with code %d", p->exitval);
	    }
E 18
	}
E 8
    }
E 7
}

/*
 * Continue execution up to the next source line.
 *
 * There are two ways to define the next source line depending on what
 * is desired when a procedure or function call is encountered.  Step
 * stops at the beginning of the procedure or call; next skips over it.
 */

/*
 * Stepc is what is called when the step command is given.
 * It has to play with the "isstopped" information.
 */

public stepc()
{
    if (not isstopped) {
	error("can't continue execution");
    }
    isstopped = false;
    dostep(false);
    isstopped = true;
}

public next()
{
I 13
    Address oldfrp, newfrp;

E 13
    if (not isstopped) {
	error("can't continue execution");
    }
    isstopped = false;
D 13
    dostep(true);
E 13
I 13
    oldfrp = reg(FRP);
    do {
	dostep(true);
	pc = reg(PROGCTR);
	newfrp = reg(FRP);
    } while (newfrp < oldfrp and newfrp != 0);
E 13
    isstopped = true;
}

D 8
public step()
E 8
I 8
/*
I 13
 * Continue execution until the current function returns, or,
 * if the given argument is non-nil, until execution returns to
 * somewhere within the given function.
 */

public rtnfunc (f)
Symbol f;
{
    Address addr;
    Symbol t;

    if (not isstopped) {
	error("can't continue execution");
    } else if (f != nil and not isactive(f)) {
	error("%s is not active", symname(f));
    } else {
	addr = return_addr();
	if (addr == nil) {
	    error("no place to return to");
	} else {
	    isstopped = false;
	    contto(addr);
	    if (f != nil) {
		for (;;) {
		    t = whatblock(pc);
		    addr = return_addr();
		if (t == f or addr == nil) break;
		    contto(addr);
		}
	    }
D 18
	    if (bpact() fails) {
E 18
I 18
	    if (not bpact()) {
E 18
		isstopped = true;
		printstatus();
	    }
	}
    }
}

/*
E 13
 * Single-step over the current machine instruction.
 *
 * If we're single-stepping by source line we want to step to the
 * next source line.  Otherwise we're going to continue so there's
 * no reason to do all the work necessary to single-step to the next
 * source line.
 */

D 13
private stepover()
E 13
I 13
public stepover()
E 13
E 8
{
D 8
    dostep(false);
E 8
I 8
    Boolean b;

I 13
    if (traceexec) {
	printf("!! stepping over 0x%x\n", process->reg[PROGCTR]);
    }
E 13
    if (single_stepping) {
	dostep(false);
    } else {
	b = inst_tracing;
	inst_tracing = true;
	dostep(false);
	inst_tracing = b;
    }
I 13
    if (traceexec) {
	printf("!! stepped over to 0x%x\n", process->reg[PROGCTR]);
    }
E 13
E 8
}

/*
D 18
 * Resume execution up to the given address.  It is assumed that
 * no breakpoints exist between the current address and the one
 * we're stepping to.  This saves us from setting all the breakpoints.
E 18
I 18
 * Resume execution up to the given address.  We can either ignore
 * breakpoints (stepto) or catch them (contto).
E 18
 */

public stepto(addr)
Address addr;
{
D 13
    setbp(addr);
D 8
    resume();
E 8
I 8
D 12
    resume(0);
E 12
I 12
    resume(DEFSIG);
E 12
E 8
    unsetbp(addr);
    if (not isbperr()) {
	printstatus();
E 13
I 13
    xto(addr, false);
}

private contto (addr)
Address addr;
{
    xto(addr, true);
}

private xto (addr, catchbps)
Address addr;
boolean catchbps;
{
    Address curpc;

    if (catchbps) {
	stepover();
E 13
    }
I 13
    curpc = process->reg[PROGCTR];
    if (addr != curpc) {
	if (traceexec) {
	    printf("!! stepping from 0x%x to 0x%x\n", curpc, addr);
	}
	if (catchbps) {
	    setallbps();
	}
	setbp(addr);
	resume(DEFSIG);
	unsetbp(addr);
	if (catchbps) {
	    unsetallbps();
	}
	if (not isbperr()) {
	    printstatus();
	}
    }
E 13
}

/*
 * Print the status of the process.
 * This routine does not return.
 */

D 21
public printstatus()
E 21
I 21
public printstatus ()
E 21
{
I 11
    int status;

E 11
D 3
    curfunc = whatblock(pc);
    if (process->signo == SIGINT) {
	isstopped = true;
	printerror();
    }
    if (isbperr() and isstopped) {
	printf("stopped ");
E 3
I 3
    if (process->status == FINISHED) {
	exit(0);
    } else {
I 21
	if (runfirst) {
	    fprintf(stderr, "\nEntering debugger ...\n");
	    printheading();
	    init();
	}
E 21
D 13
	curfunc = whatblock(pc);
E 13
I 13
	setcurfunc(whatblock(pc));
E 13
E 3
	getsrcpos();
D 3
	if (curline > 0) {
	    printsrcpos();
	    putchar('\n');
	    printlines(curline, curline);
E 3
I 3
	if (process->signo == SIGINT) {
	    isstopped = true;
	    printerror();
	} else if (isbperr() and isstopped) {
	    printf("stopped ");
I 4
	    printloc();
	    putchar('\n');
E 4
	    if (curline > 0) {
D 4
		printsrcpos();
		putchar('\n');
E 4
		printlines(curline, curline);
	    } else {
D 4
		printf("in ");
		printwhich(stdout, curfunc);
		printf(" at 0x%x\n", pc);
E 4
		printinst(pc, pc);
	    }
	    erecover();
E 3
	} else {
D 3
	    printf("in ");
	    printwhich(stdout, curfunc);
	    printf(" at 0x%x\n", pc);
	    printinst(pc, pc);
	}
	erecover();
    } else {
	fixbps();
	fixintr();
	if (process->status == FINISHED) {
	    exit(0);
	} else {
E 3
I 3
D 13
	    fixbps();
E 13
	    fixintr();
E 3
	    isstopped = true;
	    printerror();
	}
    }
}

/*
I 4
 * Print out the current location in the debuggee.
 */

public printloc()
{
    printf("in ");
    printname(stdout, curfunc);
    putchar(' ');
D 12
    if (curline > 0) {
E 12
I 12
    if (curline > 0 and not useInstLoc) {
E 12
	printsrcpos();
    } else {
I 12
	useInstLoc = false;
	curline = 0;
E 12
	printf("at 0x%x", pc);
    }
}

/*
E 4
 * Some functions for testing the state of the process.
 */

public Boolean notstarted(p)
Process p;
{
    return (Boolean) (p->status == NOTSTARTED);
}

public Boolean isfinished(p)
Process p;
{
    return (Boolean) (p->status == FINISHED);
}

/*
D 18
 * Return the signal number which stopped the process.
E 18
I 18
 * Predicate to test if the reason the process stopped was because
 * of a breakpoint.  If so, as a side effect clear the local copy of
 * signal handler associated with process.  We must do this so as to
 * not confuse future stepping or continuing by possibly concluding
 * the process should continue with a SIGTRAP handler.
E 18
 */

D 18
public Integer errnum(p)
E 18
I 18
public boolean isbperr()
{
    Process p;
    boolean b;

    p = process;
    if (p->status == STOPPED and p->signo == SIGTRAP) {
	b = true;
	p->sigstatus = 0;
    } else {
	b = false;
    }
    return b;
}

/*
 * Return the signal number that stopped the process.
 */

public integer errnum (p)
E 18
Process p;
{
    return p->signo;
}

I 16
D 18
public Integer errcode(p)
E 18
I 18
/*
 * Return the signal code associated with the signal.
 */

public integer errcode (p)
E 18
Process p;
{
    return p->sigcode;
}

E 16
/*
 * Return the termination code of the process.
 */

D 18
public Integer exitcode(p)
E 18
I 18
public integer exitcode (p)
E 18
Process p;
{
    return p->exitval;
}

/*
 * These routines are used to access the debuggee process from
 * outside this module.
 *
 * They invoke "pio" which eventually leads to a call to "ptrace".
D 5
 * The system generates an I/O error when a ptrace fails, we catch
 * that here and assume its due to a misguided address.
E 5
I 5
D 12
 * The system generates an I/O error when a ptrace fails, we assume
 * during a read/write to the process that such an error is due to
 * a misguided address and ignore it.
E 12
I 12
 * The system generates an I/O error when a ptrace fails.  During reads
 * these are ignored, during writes they are reported as an error, and
 * for anything else they cause a fatal error.
E 12
E 5
 */

extern Intfunc *onsyserr();

private badaddr;
D 12
private rwerr();
E 12
I 12
private read_err(), write_err();
E 12

/*
 * Read from the process' instruction area.
 */

public iread(buff, addr, nbytes)
char *buff;
Address addr;
int nbytes;
{
    Intfunc *f;

D 12
    f = onsyserr(EIO, rwerr);
E 12
I 12
    f = onsyserr(EIO, read_err);
E 12
    badaddr = addr;
    if (coredump) {
	coredump_readtext(buff, addr, nbytes);
    } else {
	pio(process, PREAD, TEXTSEG, buff, addr, nbytes);
    }
    onsyserr(EIO, f);
}

/* 
 * Write to the process' instruction area, usually in order to set
 * or unset a breakpoint.
 */

public iwrite(buff, addr, nbytes)
char *buff;
Address addr;
int nbytes;
{
    Intfunc *f;

    if (coredump) {
	error("no process to write to");
    }
D 12
    f = onsyserr(EIO, rwerr);
E 12
I 12
    f = onsyserr(EIO, write_err);
E 12
    badaddr = addr;
    pio(process, PWRITE, TEXTSEG, buff, addr, nbytes);
    onsyserr(EIO, f);
}

/*
 * Read for the process' data area.
 */

public dread(buff, addr, nbytes)
char *buff;
Address addr;
int nbytes;
{
    Intfunc *f;

D 12
    f = onsyserr(EIO, rwerr);
E 12
I 12
D 18
    f = onsyserr(EIO, read_err);
E 18
E 12
    badaddr = addr;
    if (coredump) {
I 18
	f = onsyserr(EFAULT, read_err);
E 18
	coredump_readdata(buff, addr, nbytes);
I 18
	onsyserr(EFAULT, f);
E 18
    } else {
I 18
	f = onsyserr(EIO, read_err);
E 18
	pio(process, PREAD, DATASEG, buff, addr, nbytes);
I 18
	onsyserr(EIO, f);
E 18
    }
D 18
    onsyserr(EIO, f);
E 18
}

/*
 * Write to the process' data area.
 */

public dwrite(buff, addr, nbytes)
char *buff;
Address addr;
int nbytes;
{
    Intfunc *f;

    if (coredump) {
	error("no process to write to");
    }
D 12
    f = onsyserr(EIO, rwerr);
E 12
I 12
    f = onsyserr(EIO, write_err);
E 12
    badaddr = addr;
    pio(process, PWRITE, DATASEG, buff, addr, nbytes);
    onsyserr(EIO, f);
}

/*
D 12
 * Error handler.
E 12
I 12
 * Trap for errors in reading or writing to a process.
 * The current approach is to "ignore" read errors and complain
 * bitterly about write errors.
E 12
 */

D 12
private rwerr()
E 12
I 12
private read_err()
E 12
{
I 5
    /*
D 12
     * Current response is to ignore the error and let the result
     * (-1) ripple back up to the process.
     *
E 5
    error("bad read/write process address 0x%x", badaddr);
E 12
I 12
     * Ignore.
E 12
I 5
     */
E 5
}

I 12
private write_err()
{
    error("can't write to process (address 0x%x)", badaddr);
}

E 12
/*
 * Ptrace interface.
 */

D 21
/*
 * This magic macro enables us to look at the process' registers
D 12
 * in its user structure.  Very gross.
E 12
I 12
 * in its user structure.
E 12
 */

#define regloc(reg)     (ctob(UPAGES) + ( sizeof(int) * (reg) ))

E 21
#define WMASK           (~(sizeof(Word) - 1))
D 21
#define cachehash(addr) ((unsigned) ((addr >> 2) % CSIZE))
E 21
I 21
#define cachehash(addr) ((unsigned) ((addr >> 2) % CACHESIZE))
E 21

#define FIRSTSIG        SIGINT
#define LASTSIG         SIGQUIT
#define ischild(pid)    ((pid) == 0)
D 17
#define traceme()       ptrace(0, 0, 0, 0)
E 17
I 17
D 18
#define traceme()       ptrace(PT_TRACE_ME, 0, 0, 0)
E 18
I 18
#define traceme()       ptrace(0, 0, 0, 0)
E 18
E 17
#define setrep(n)       (1 << ((n)-1))
#define istraced(p)     (p->sigset&setrep(p->signo))

/*
I 18
 * Ptrace options (specified in first argument).
 */

#define UREAD   3       /* read from process's user structure */
#define UWRITE  6       /* write to process's user structure */
#define IREAD   1       /* read from process's instruction space */
#define IWRITE  4       /* write to process's instruction space */
#define DREAD   2       /* read from process's data space */
#define DWRITE  5       /* write to process's data space */
#define CONT    7       /* continue stopped process */
#define SSTEP   9       /* continue for approximately one instruction */
#define PKILL   8       /* terminate the process */

I 21
#ifdef IRIS
#   define readreg(p, r)	ptrace(10, p->pid, r, 0)
#   define writereg(p, r, v)	ptrace(11, p->pid, r, v)
#else
#   define readreg(p, r)	ptrace(UREAD, p->pid, regloc(r), 0);
#   define writereg(p, r, v)	ptrace(UWRITE, p->pid, regloc(r), v);
#endif

E 21
/*
E 18
D 17
 * Ptrace options (specified in first argument).
 */

#define UREAD   3       /* read from process's user structure */
#define UWRITE  6       /* write to process's user structure */
#define IREAD   1       /* read from process's instruction space */
#define IWRITE  4       /* write to process's instruction space */
#define DREAD   2       /* read from process's data space */
#define DWRITE  5       /* write to process's data space */
#define CONT    7       /* continue stopped process */
#define SSTEP   9       /* continue for approximately one instruction */
#define PKILL   8       /* terminate the process */

/*
E 17
 * Start up a new process by forking and exec-ing the
 * given argument list, returning when the process is loaded
 * and ready to execute.  The PROCESS information (pointed to
 * by the first argument) is appropriately filled.
 *
 * If the given PROCESS structure is associated with an already running
 * process, we terminate it.
 */

/* VARARGS2 */
private pstart(p, argv, infile, outfile)
Process p;
String argv[];
String infile;
String outfile;
{
    int status;
I 11
D 13
    Fileid in, out;
E 13
E 11
D 4
    File in, out;
E 4

D 12
    if (p->pid != 0) {          	/* child already running? */
	ptrace(PKILL, p->pid, 0, 0);    /* ... kill it! */
E 12
I 12
D 13
    if (p->pid != 0) {			/* child already running? */
	ptrace(PKILL, p->pid, 0, 0);	/* ... kill it! */
E 12
I 11
	pwait(p->pid, &status);		/* wait for it to exit */
	unptraced(p->pid);
E 13
I 13
    if (p->pid != 0) {
	pterm(p);
I 18
	cacheflush(p);
E 18
E 13
E 11
    }
I 18
    fflush(stdout);
E 18
    psigtrace(p, SIGTRAP, true);
D 4
    if ((p->pid = fork()) == -1) {
E 4
I 4
D 11
    if ((p->pid = vfork()) == -1) {
E 11
I 11
D 21
    p->pid = vfork();
E 21
I 21
#   ifdef IRIS
	p->pid = fork();
#   else
	p->pid = vfork();
#   endif
E 21
    if (p->pid == -1) {
E 11
E 4
	panic("can't fork");
    }
    if (ischild(p->pid)) {
I 18
	nocatcherrs();
E 18
I 4
D 11
	Fileid in, out;

E 11
E 4
	traceme();
	if (infile != nil) {
D 4
	    in = fopen(infile, "r");
	    if (in == nil) {
		printf("can't read %s\n", infile);
		exit(1);
E 4
I 4
D 13
	    in = open(infile, 0);
	    if (in == -1) {
		write(2, "can't read ", 11);
		write(2, infile, strlen(infile));
		write(2, "\n", 1);
		_exit(1);
E 4
	    }
D 4
	    fswap(0, fileno(in));
E 4
I 4
	    fswap(0, in);
E 13
I 13
	    infrom(infile);
E 13
E 4
	}
	if (outfile != nil) {
D 4
	    out = fopen(outfile, "w");
	    if (out == nil) {
		printf("can't write %s\n", outfile);
		exit(1);
E 4
I 4
D 13
	    out = creat(outfile, 0666);
	    if (out == -1) {
		write(2, "can't write ", 12);
		write(2, outfile, strlen(outfile));
		write(2, "\n", 1);
		_exit(1);
E 4
	    }
D 4
	    fswap(1, fileno(out));
E 4
I 4
	    fswap(1, out);
E 13
I 13
	    outto(outfile);
E 13
E 4
	}
D 7
	execvp(argv[0], argv);
E 7
I 7
	execv(argv[0], argv);
E 7
D 4
	panic("can't exec %s", argv[0]);
E 4
I 4
D 18
	write(2, "can't exec ", 11);
	write(2, argv[0], strlen(argv[0]));
	write(2, "\n", 1);
E 18
	_exit(1);
E 4
    }
    pwait(p->pid, &status);
    getinfo(p, status);
    if (p->status != STOPPED) {
D 18
	error("program could not begin execution");
E 18
I 18
	beginerrmsg();
	fprintf(stderr, "warning: cannot execute %s\n", argv[0]);
    } else {
	ptraced(p->pid);
E 18
    }
I 11
D 18
    ptraced(p->pid);
E 18
E 11
}

/*
I 13
 * Terminate a ptrace'd process.
 */

public pterm (p)
Process p;
{
    integer status;

    if (p != nil and p->pid != 0) {
D 17
	ptrace(PKILL, p->pid, 0, 0);
E 17
I 17
D 18
	ptrace(PT_KILL, p->pid, 0, 0);
E 18
I 18
	ptrace(PKILL, p->pid, 0, 0);
E 18
E 17
	pwait(p->pid, &status);
	unptraced(p->pid);
    }
}

/*
E 13
D 8
 * Continue a stopped process.  The argument points to a PROCESS structure.
 * Before the process is restarted it's user area is modified according to
 * the values in the structure.  When this routine finishes,
E 8
I 8
 * Continue a stopped process.  The first argument points to a Process
 * structure.  Before the process is restarted it's user area is modified
 * according to the values in the structure.  When this routine finishes,
E 8
 * the structure has the new values from the process's user area.
 *
 * Pcont terminates when the process stops with a signal pending that
 * is being traced (via psigtrace), or when the process terminates.
 */

D 8
private pcont(p)
E 8
I 8
private pcont(p, signo)
E 8
Process p;
I 8
int signo;
E 8
{
D 13
    int status;
E 13
I 13
    int s, status;
E 13

    if (p->pid == 0) {
D 18
	error("program not active");
E 18
I 18
	error("program is not active");
E 18
    }
I 13
    s = signo;
E 13
    do {
D 8
	setinfo(p);
E 8
I 8
D 13
	setinfo(p, signo);
E 13
I 13
	setinfo(p, s);
	if (traceexec) {
	    printf("!! pcont from 0x%x with signal %d (%d)\n",
		p->reg[PROGCTR], s, p->signo);
	    fflush(stdout);
	}
E 13
E 8
	sigs_off();
D 17
	if (ptrace(CONT, p->pid, p->reg[PROGCTR], p->signo) < 0) {
E 17
I 17
D 18
	if (ptrace(PT_CONTINUE, p->pid, p->reg[PROGCTR], p->signo) < 0) {
E 18
I 18
	if (ptrace(CONT, p->pid, p->reg[PROGCTR], p->signo) < 0) {
E 18
E 17
D 11
	    panic("can't continue process");
E 11
I 11
	    panic("error %d trying to continue process", errno);
E 11
	}
	pwait(p->pid, &status);
	sigs_on();
	getinfo(p, status);
I 13
D 18
	if (traceexec and not istraced(p)) {
	    printf("!! ignored signal %d at 0x%x\n", p->signo, p->reg[PROGCTR]);
E 18
I 18
	if (p->status == STOPPED and traceexec and not istraced(p)) {
	    printf("!! ignored signal %d at 0x%x\n",
		p->signo, p->reg[PROGCTR]);
E 18
	    fflush(stdout);
	}
	s = p->signo;
E 13
    } while (p->status == STOPPED and not istraced(p));
I 13
    if (traceexec) {
	printf("!! pcont to 0x%x on signal %d\n", p->reg[PROGCTR], p->signo);
	fflush(stdout);
    }
E 13
}

/*
 * Single step as best ptrace can.
 */

D 13
public pstep(p)
E 13
I 13
public pstep(p, signo)
E 13
Process p;
I 13
integer signo;
E 13
{
D 18
    int status;
E 18
I 18
    int s, status;
E 18

D 8
    setinfo(p);
E 8
I 8
D 12
    setinfo(p, 0);
E 12
I 12
D 13
    setinfo(p, DEFSIG);
E 13
I 13
D 18
    setinfo(p, signo);
E 18
I 18
    s = signo;
    do {
	setinfo(p, s);
	if (traceexec) {
	    printf("!! pstep from 0x%x with signal %d (%d)\n",
		p->reg[PROGCTR], s, p->signo);
	    fflush(stdout);
	}
	sigs_off();
	if (ptrace(SSTEP, p->pid, p->reg[PROGCTR], p->signo) < 0) {
	    panic("error %d trying to step process", errno);
	}
	pwait(p->pid, &status);
	sigs_on();
	getinfo(p, status);
I 21
#	if mc68000 || m68000
	    if (p->status == STOPPED and p->signo == SIGTRAP) {
		p->reg[PROGCTR] += 2;
	    }
#	endif
E 21
	if (p->status == STOPPED and traceexec and not istraced(p)) {
	    printf("!! pstep ignored signal %d at 0x%x\n",
		p->signo, p->reg[PROGCTR]);
	    fflush(stdout);
	}
	s = p->signo;
    } while (p->status == STOPPED and not istraced(p));
E 18
    if (traceexec) {
D 18
	printf("!! pstep from pc 0x%x with signal %d (%d)\n",
	    p->reg[PROGCTR], signo, p->signo);
E 18
I 18
	printf("!! pstep to 0x%x on signal %d\n",
	    p->reg[PROGCTR], p->signo);
E 18
	fflush(stdout);
    }
E 13
E 12
E 8
D 18
    sigs_off();
D 13
    ptrace(SSTEP, p->pid, p->reg[PROGCTR], p->signo);
E 13
I 13
D 17
    if (ptrace(SSTEP, p->pid, p->reg[PROGCTR], p->signo) < 0) {
E 17
I 17
    if (ptrace(PT_STEP, p->pid, p->reg[PROGCTR], p->signo) < 0) {
E 17
	panic("error %d trying to step process", errno);
    }
E 13
    pwait(p->pid, &status);
    sigs_on();
    getinfo(p, status);
I 13
    if (traceexec) {
	printf("!! pstep to pc 0x%x on signal %d\n", p->reg[PROGCTR], p->signo);
	fflush(stdout);
    }
E 18
    if (p->status != STOPPED) {
D 18
	error("program unexpectedly exited with %d\n", p->exitval);
E 18
I 18
	if (p->exitval == 0) {
	    error("program exited\n");
	} else {
	    error("program exited with code %d\n", p->exitval);
	}
E 18
    }
E 13
}

/*
 * Return from execution when the given signal is pending.
 */

public psigtrace(p, sig, sw)
Process p;
int sig;
Boolean sw;
{
    if (sw) {
	p->sigset |= setrep(sig);
    } else {
	p->sigset &= ~setrep(sig);
    }
}

/*
 * Don't catch any signals.
 * Particularly useful when letting a process finish uninhibited.
 */

public unsetsigtraces(p)
Process p;
{
    p->sigset = 0;
}

/*
 * Turn off attention to signals not being caught.
 */

private Intfunc *sigfunc[NSIG];

private sigs_off()
{
    register int i;

    for (i = FIRSTSIG; i < LASTSIG; i++) {
	if (i != SIGKILL) {
	    sigfunc[i] = signal(i, SIG_IGN);
	}
    }
}

/*
 * Turn back on attention to signals.
 */

private sigs_on()
{
    register int i;

    for (i = FIRSTSIG; i < LASTSIG; i++) {
	if (i != SIGKILL) {
	    signal(i, sigfunc[i]);
	}
    }
}

/*
 * Get process information from user area.
 */

D 20
private int rloc[] ={
    R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, AP, FP, SP, PC
};

E 20
D 21
private getinfo(p, status)
E 21
I 21
private getinfo (p, status)
E 21
register Process p;
register int status;
{
    register int i;
I 13
    Address addr;
E 13

    p->signo = (status&0177);
    p->exitval = ((status >> 8)&0377);
    if (p->signo != STOPPED) {
	p->status = FINISHED;
I 12
	p->pid = 0;
I 13
	p->reg[PROGCTR] = 0;
E 13
E 12
    } else {
	p->status = p->signo;
	p->signo = p->exitval;
I 16
D 17
	p->sigcode = ptrace(UREAD, p->pid, &((struct user *)0)->u_code, 0);
E 17
I 17
D 18
	p->sigcode = ptrace(PT_READ_U, p->pid, &((struct user *)0)->u_code, 0);
E 18
I 18
D 21
	p->sigcode = ptrace(UREAD, p->pid, &((struct user *) 0)->u_code, 0);
E 21
E 18
E 17
E 16
	p->exitval = 0;
D 17
	p->mask = ptrace(UREAD, p->pid, regloc(PS), 0);
E 17
I 17
D 18
	p->mask = ptrace(PT_READ_U, p->pid, regloc(PS), 0);
E 18
I 18
D 21
	p->mask = ptrace(UREAD, p->pid, regloc(PS), 0);
E 21
I 21
#       ifdef IRIS
	    p->mask = readreg(p, RPS);
#       else
	    p->sigcode = ptrace(UREAD, p->pid, &((struct user *)0)->u_code, 0);
	    p->mask = readreg(p, PS);
#       endif
E 21
E 18
E 17
	for (i = 0; i < NREG; i++) {
D 17
	    p->reg[i] = ptrace(UREAD, p->pid, regloc(rloc[i]), 0);
E 17
I 17
D 18
	    p->reg[i] = ptrace(PT_READ_U, p->pid, regloc(rloc[i]), 0);
E 18
I 18
D 21
	    p->reg[i] = ptrace(UREAD, p->pid, regloc(rloc[i]), 0);
E 21
I 21
	    p->reg[i] = readreg(p, rloc[i]);
E 21
E 18
E 17
	    p->oreg[i] = p->reg[i];
	}
I 21
#       ifdef mc68000
	    if (p->status == STOPPED and p->signo == SIGTRAP and
		p->reg[PROGCTR] > CODESTART
	    ) {
		p->reg[PROGCTR] -= 2;
	    }
#       endif
E 21
I 6
	savetty(stdout, &(p->ttyinfo));
I 13
	addr = (Address) &(((struct user *) 0)->u_signal[p->signo]);
D 17
	p->sigstatus = (Address) ptrace(UREAD, p->pid, addr, 0);
E 17
I 17
D 18
	p->sigstatus = (Address) ptrace(PT_READ_U, p->pid, addr, 0);
E 18
I 18
	p->sigstatus = (Address) ptrace(UREAD, p->pid, addr, 0);
E 18
E 17
E 13
E 6
    }
}

/*
 * Set process's user area information from given process structure.
 */

D 8
private setinfo(p)
E 8
I 8
D 21
private setinfo(p, signo)
E 21
I 21
private setinfo (p, signo)
E 21
E 8
register Process p;
I 8
int signo;
E 8
{
    register int i;
    register int r;

D 12
    if (istraced(p)) {
E 12
I 12
    if (signo == DEFSIG) {
D 13
	if (istraced(p)) {
E 13
I 13
	if (istraced(p) and (p->sigstatus == 0 or p->sigstatus == 1)) {
E 13
	    p->signo = 0;
	}
    } else {
E 12
D 8
	p->signo = 0;
E 8
I 8
	p->signo = signo;
E 8
    }
    for (i = 0; i < NREG; i++) {
	if ((r = p->reg[i]) != p->oreg[i]) {
D 17
	    ptrace(UWRITE, p->pid, regloc(rloc[i]), r);
E 17
I 17
D 18
	    ptrace(PT_WRITE_U, p->pid, regloc(rloc[i]), r);
E 18
I 18
D 21
	    ptrace(UWRITE, p->pid, regloc(rloc[i]), r);
E 21
I 21
	    writereg(p, rloc[i], r);
E 21
E 18
E 17
	}
    }
I 6
    restoretty(stdout, &(p->ttyinfo));
E 6
}

/*
I 13
 * Return the address associated with the current signal.
 * (Plus two since the address points to the beginning of a procedure).
 */

public Address usignal (p)
Process p;
{
    Address r;

    r = p->sigstatus;
    if (r != 0 and r != 1) {
D 21
	r += 2;
E 21
I 21
	r += FUNCOFFSET;
E 21
    }
    return r;
}

/*
E 13
 * Structure for reading and writing by words, but dealing with bytes.
 */

typedef union {
    Word pword;
    Byte pbyte[sizeof(Word)];
} Pword;

/*
 * Read (write) from (to) the process' address space.
 * We must deal with ptrace's inability to look anywhere other
 * than at a word boundary.
 */

private Word fetch();
private store();

private pio(p, op, seg, buff, addr, nbytes)
Process p;
PioOp op;
PioSeg seg;
char *buff;
Address addr;
int nbytes;
{
    register int i;
    register Address newaddr;
    register char *cp;
    char *bufend;
    Pword w;
    Address wordaddr;
    int byteoff;

    if (p->status != STOPPED) {
	error("program is not active");
    }
    cp = buff;
    newaddr = addr;
    wordaddr = (newaddr&WMASK);
    if (wordaddr != newaddr) {
	w.pword = fetch(p, seg, wordaddr);
	for (i = newaddr - wordaddr; i < sizeof(Word) and nbytes > 0; i++) {
	    if (op == PREAD) {
		*cp++ = w.pbyte[i];
	    } else {
		w.pbyte[i] = *cp++;
	    }
	    nbytes--;
	}
	if (op == PWRITE) {
	    store(p, seg, wordaddr, w.pword);
	}
	newaddr = wordaddr + sizeof(Word);
    }
    byteoff = (nbytes&(~WMASK));
    nbytes -= byteoff;
    bufend = cp + nbytes;
I 20
#ifdef tahoe
    if (((int)cp)&WMASK) {
	/*
	 * Must copy a byte at a time, buffer not word addressable.
	 */
	while (cp < bufend) {
	    if (op == PREAD) {
		w.pword = fetch(p, seg, newaddr);
		for (i = 0; i < sizeof(Word); i++)
		    *cp++ = w.pbyte[i];
	    } else {
		for (i = 0; i < sizeof(Word); i++)
		    w.pbyte[i] = *cp++;
		store(p, seg, newaddr, w.pword);
	    }
	    newaddr += sizeof(Word);
	}
    } else {
    /*
     * Buffer, word aligned, act normally...
     */
#endif
E 20
    while (cp < bufend) {
	if (op == PREAD) {
	    *((Word *) cp) = fetch(p, seg, newaddr);
	} else {
	    store(p, seg, newaddr, *((Word *) cp));
	}
	cp += sizeof(Word);
	newaddr += sizeof(Word);
    }
I 20
#ifdef tahoe
    }
#endif
E 20
    if (byteoff > 0) {
	w.pword = fetch(p, seg, newaddr);
	for (i = 0; i < byteoff; i++) {
	    if (op == PREAD) {
		*cp++ = w.pbyte[i];
	    } else {
		w.pbyte[i] = *cp++;
	    }
	}
	if (op == PWRITE) {
	    store(p, seg, newaddr, w.pword);
	}
    }
}

/*
 * Get a word from a process at the given address.
 * The address is assumed to be on a word boundary.
 *
 * A simple cache scheme is used to avoid redundant ptrace calls
 * to the instruction space since it is assumed to be pure.
 *
 * It is necessary to use a write-through scheme so that
 * breakpoints right next to each other don't interfere.
 */

private Integer nfetchs, nreads, nwrites;

private Word fetch(p, seg, addr)
Process p;
PioSeg seg;
register int addr;
{
    register CacheWord *wp;
    register Word w;

    switch (seg) {
	case TEXTSEG:
	    ++nfetchs;
	    wp = &p->word[cachehash(addr)];
	    if (addr == 0 or wp->addr != addr) {
		++nreads;
D 17
		w = ptrace(IREAD, p->pid, addr, 0);
E 17
I 17
D 18
		w = ptrace(PT_READ_I, p->pid, addr, 0);
E 18
I 18
		w = ptrace(IREAD, p->pid, addr, 0);
E 18
E 17
		wp->addr = addr;
		wp->val = w;
	    } else {
		w = wp->val;
	    }
	    break;

	case DATASEG:
D 17
	    w = ptrace(DREAD, p->pid, addr, 0);
E 17
I 17
D 18
	    w = ptrace(PT_READ_D, p->pid, addr, 0);
E 18
I 18
	    w = ptrace(DREAD, p->pid, addr, 0);
E 18
E 17
	    break;

	default:
	    panic("fetch: bad seg %d", seg);
	    /* NOTREACHED */
    }
    return w;
}

/*
 * Put a word into the process' address space at the given address.
 * The address is assumed to be on a word boundary.
 */

private store(p, seg, addr, data)
Process p;
PioSeg seg;
int addr;
Word data;
{
    register CacheWord *wp;

    switch (seg) {
	case TEXTSEG:
	    ++nwrites;
	    wp = &p->word[cachehash(addr)];
	    wp->addr = addr;
	    wp->val = data;
D 17
	    ptrace(IWRITE, p->pid, addr, data);
E 17
I 17
D 18
	    ptrace(PT_WRITE_I, p->pid, addr, data);
E 18
I 18
	    ptrace(IWRITE, p->pid, addr, data);
E 18
E 17
	    break;

	case DATASEG:
D 17
	    ptrace(DWRITE, p->pid, addr, data);
E 17
I 17
D 18
	    ptrace(PT_WRITE_D, p->pid, addr, data);
E 18
I 18
	    ptrace(DWRITE, p->pid, addr, data);
E 18
E 17
	    break;

	default:
	    panic("store: bad seg %d", seg);
	    /* NOTREACHED */
    }
}

I 18
/*
 * Flush the instruction cache associated with a process.
 */

private cacheflush (p)
Process p;
{
    bzero(p->word, sizeof(p->word));
}

E 18
public printptraceinfo()
{
    printf("%d fetchs, %d reads, %d writes\n", nfetchs, nreads, nwrites);
}

/*
D 13
 * Swap file numbers so as to redirect standard input and output.
E 13
I 13
 * Redirect input.
 * Assuming this is called from a child, we should be careful to avoid
 * (possibly) shared standard I/O buffers.
E 13
 */

I 13
private infrom (filename)
String filename;
{
    Fileid in;

    in = open(filename, 0);
    if (in == -1) {
	write(2, "can't read ", 11);
	write(2, filename, strlen(filename));
	write(2, "\n", 1);
	_exit(1);
    }
    fswap(0, in);
}

/*
 * Redirect standard output.
 * Same assumptions as for "infrom" above.
 */

private outto (filename)
String filename;
{
    Fileid out;

    out = creat(filename, 0666);
    if (out == -1) {
	write(2, "can't write ", 12);
	write(2, filename, strlen(filename));
	write(2, "\n", 1);
	_exit(1);
    }
    fswap(1, out);
}

/*
 * Swap file numbers, useful for redirecting standard input or output.
 */

E 13
private fswap(oldfd, newfd)
D 13
int oldfd;
int newfd;
E 13
I 13
Fileid oldfd;
Fileid newfd;
E 13
{
    if (oldfd != newfd) {
	close(oldfd);
	dup(newfd);
	close(newfd);
    }
}
I 15

D 18
#define	bit(i)		(1 << ((i)-1))
E 18
/*
D 18
 * Signal manipulation routines.
E 18
I 18
 * Signal name manipulation.
E 18
 */
D 18
static String signames[NSIG] = {
	0,
	"HUP",
	"INT",
	"QUIT",
	"ILL",
	"TRAP",
	"IOT",
	"EMT",
	"FPE",
	"KILL",
	"BUS",
	"SEGV",
	"SYS",
	"PIPE",
	"ALRM",
	"TERM",
	0,
	"STOP",
	"TSTP",
	"CONT",
	"CHLD",
	"TTIN",
	"TTOU",
	"TINT",
	"XCPU",
	"XFSZ",
E 18
I 18

private String signames[NSIG] = {
    0,
    "HUP", "INT", "QUIT", "ILL", "TRAP",
    "IOT", "EMT", "FPE", "KILL", "BUS",
    "SEGV", "SYS", "PIPE", "ALRM", "TERM",
    0, "STOP", "TSTP", "CONT", "CHLD",
    "TTIN", "TTOU", "TINT", "XCPU", "XFSZ",
I 20
    "VTALRM", "PROF", "WINCH", "USR1", "USR2"
E 20
E 18
};

/*
D 18
 * Map a signal name to a number.
E 18
I 18
 * Get the signal number associated with a given name.
 * The name is first translated to upper case if necessary.
E 18
 */
D 18
public signalname(s)
E 18
I 18

public integer siglookup (s)
E 18
String s;
{
D 18
	register String *p;
E 18
I 18
    register char *p, *q;
    char buf[100];
    integer i;
E 18

I 16
D 18
	if (strneq(s, "SIG", 3))
	    s += 3;
E 16
	for (p = signames; p < &signames[NSIG]; p++)
		if (*p && streq(*p, s))
			return (p - signames);
	error("%s: Unknown signal.", s);
E 18
I 18
    p = s;
    q = buf;
    while (*p != '\0') {
	if (*p >= 'a' and *p <= 'z') {
	    *q = (*p - 'a') + 'A';
	} else {
	    *q = *p;
	}
	++p;
	++q;
    }
    *q = '\0';
    p = buf;
    if (buf[0] == 'S' and buf[1] == 'I' and buf[2] == 'G') {
	p += 3;
    }
    i = 1;
    for (;;) {
	if (i >= sizeof(signames) div sizeof(signames[0])) {
	    error("signal \"%s\" unknown", s);
	    i = 0;
	    break;
	}
	if (signames[i] != nil and streq(signames[i], p)) {
	    break;
	}
	++i;
    }
    return i;
E 18
}

/*
D 18
 * Print all signals being ignored by the
 * debugger.  These signals are auotmatically
E 18
I 18
 * Print all signals being ignored by the debugger.
 * These signals are auotmatically
E 18
 * passed on to the debugged process.
 */
D 16
public printsigsignored(vec)
long vec;
E 16
I 16
D 18
public printsigsignored(p)
E 18
I 18

public printsigsignored (p)
E 18
Process p;
E 16
{
D 16
	register Integer s;
	String sep = "";
E 16
D 18

E 18
D 16
	for (s = 1; s < NSIG; s++)
		if ((vec & bit(s)) && signames[s]) {
			printf("%s%s", sep, signames[s]);
			sep = " ";
		}
	if (*sep != '\0') {
		putchar('\n');
		fflush(stdout);
	}
E 16
I 16
    printsigs(~p->sigset);
E 16
}

/*
 * Print all signals being intercepted by
 * the debugger for the specified process.
 */
I 18

E 18
D 16
public printsigscaught(vec)
long vec;
E 16
I 16
public printsigscaught(p)
Process p;
E 16
{
D 16
	register Integer s;
	String sep = "";
E 16
D 18

E 18
D 16
	for (s = 1; s < NSIG; s++)
		if ((vec & bit(s)) == 0 && signames[s]) {
			printf("%s%s", sep, signames[s]);
			sep = " ";
		}
	if (*sep != '\0') {
		putchar('\n');
		fflush(stdout);
	}
E 16
I 16
    printsigs(p->sigset);
E 16
}

I 16
D 18
private printsigs(vec)
register Integer vec;
E 18
I 18
private printsigs (set)
integer set;
E 18
{
D 18
    register Integer s;
    String sep = "";
E 18
I 18
    integer s;
    char separator[2];
E 18

D 18
    for (s = 1; s < NSIG; s++)
	if (vec & bit(s) && signames[s]) {
	    printf("%s%s", sep, signames[s]);
	    sep = " ";
E 18
I 18
    separator[0] = '\0';
    for (s = 1; s < sizeof(signames) div sizeof(signames[0]); s++) {
	if (set & setrep(s)) {
	    if (signames[s] != nil) {
		printf("%s%s", separator, signames[s]);
		separator[0] = ' ';
		separator[1] = '\0';
	    }
E 18
	}
D 18
    if (*sep != '\0') {
E 18
I 18
    }
    if (separator[0] == ' ') {
E 18
	putchar('\n');
D 18
	fflush(stdout);
E 18
    }
}
E 16
E 15
E 1
