h37432
s 00008/00014/00197
d D 5.2 87/04/07 15:55:12 mckusick 7 6
c port to tahoe by Nir peleg of CCI
e
s 00008/00002/00203
d D 5.1 85/06/06 11:43:13 dist 6 5
c Add copyright
e
s 00001/00001/00204
d D 1.5 82/03/15 18:23:39 linton 5 4
c initialization of the "process" variable, this really should be 
c a PROCESS rather than a PROCESS *.
e
s 00010/00003/00195
d D 1.4 82/03/08 19:32:28 linton 4 3
c changed handling of the process not starting up so that 
c when "run < abc" is given where "abc" doesn't exist the right thing happens
e
s 00069/00066/00129
d D 1.3 82/03/08 18:54:43 linton 3 2
c put in cache initialization in at beginning of process startup 
c ("initstart") ... the cache was non-empty after a "pi" which meant 
c instruction reads were getting the wrong values
e
s 00055/00022/00140
d D 1.2 82/02/02 12:50:04 linton 2 1
c argument handling in conjunction with passing things to px
e
s 00162/00000/00000
d D 1.1 82/01/18 19:20:53 linton 1 0
c date and time created 82/01/18 19:20:53 by linton
e
u
U
t
T
I 1
D 6
/* Copyright (c) 1982 Regents of the University of California */
E 6
I 6
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 6

D 6
static char sccsid[] = "%Z%%M% %I% %G%";
E 6
I 6
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 6

/*
D 2
 * execution management
E 2
I 2
 * Execution management.
E 2
 */

#include "defs.h"
#include <signal.h>
#include "process.h"
#include "machine.h"
#include "object.h"
I 2
#include "main.h"
E 2
#include "breakpoint.h"
#include "command.h"
#include "process.rep"

D 2
#define MAXNARGS 10			/* maximum number of arguments to RUN */
E 2
I 2
D 3
#define MAXNARGS 100		/* maximum number of arguments to RUN */
E 3
I 3
#define MAXNARGS 100        /* maximum number of arguments to RUN */
E 3
E 2

D 2
typedef char *string;
E 2
I 2
typedef char *String;
E 2

LOCAL BOOLEAN just_started;
LOCAL int argc;
D 2
LOCAL string argv[MAXNARGS];
LOCAL string infile;
LOCAL string outfile;
E 2
I 2
LOCAL String argv[MAXNARGS];
LOCAL String infile;
LOCAL String outfile;
I 3
LOCAL PROCESS pbuf;
I 5
PROCESS *process = &pbuf;
E 5
E 3
E 2

/*
D 2
 * initialize the argument list
E 2
I 2
 * This is a px-related kludge to deal with the possibility
 * of object code magically coming from a tmp file.
E 2
 */

I 2
LOCAL String mode;
LOCAL String realname;

setargs(m, r)
char *m, *r;
{
D 3
	mode = m;
	realname = r;
E 3
I 3
    mode = m;
    realname = r;
E 3
}

/*
 * Initialize the argument list.
 */

E 2
arginit()
{
D 3
	infile = NIL;
	outfile = NIL;
#	if (isvaxpx)
D 2
		argv[0] = "px";
		argv[1] = "-d";
		argv[2] = objname;
		argc = 3;
E 2
I 2
		argv[0] = mode;
		argv[1] = objname;
		if (option('t') && realname == NIL) {
			argc = 2;
		} else {
			argv[2] = realname;
			argc = 3;
		}
E 2
#	else
		argv[0] = objname;
		argc = 1;
#	endif
E 3
I 3
    infile = NIL;
    outfile = NIL;
D 7
#   if (isvaxpx)
	argv[0] = mode;
	argv[1] = objname;
	if (option('t') && realname == NIL) {
	    argc = 2;
	} else {
	    argv[2] = realname;
	    argc = 3;
	}
#   else
	argv[0] = objname;
	argc = 1;
#   endif
E 7
I 7
    argv[0] = mode;
    argv[1] = objname;
    if (option('t') && realname == NIL) {
	argc = 2;
    } else {
	argv[2] = realname;
	argc = 3;
    }
E 7
E 3
}

/*
D 2
 * add an argument to the list for the debuggee
E 2
I 2
 * Add an argument to the list for the debuggee.
E 2
 */

newarg(arg)
D 2
string arg;
E 2
I 2
String arg;
E 2
{
D 3
	if (argc >= MAXNARGS) {
D 2
		error("too many arguments");
E 2
I 2
		error("too many arguments to run");
E 2
	}
	argv[argc++] = arg;
E 3
I 3
    if (argc >= MAXNARGS) {
	error("too many arguments to run");
    }
    argv[argc++] = arg;
E 3
}

/*
D 2
 * set the standard input for the debuggee
E 2
I 2
 * Set the standard input for the debuggee.
E 2
 */

inarg(filename)
D 2
string filename;
E 2
I 2
String filename;
E 2
{
D 3
	if (infile != NIL) {
		error("multiple input redirects");
	}
	infile = filename;
E 3
I 3
    if (infile != NIL) {
	error("multiple input redirects");
    }
    infile = filename;
E 3
}

/*
D 2
 * set the standard output for the debuggee
 * should probably check to avoid overwriting an existing file
E 2
I 2
 * Set the standard output for the debuggee.
 * Probably should check to avoid overwriting an existing file.
E 2
 */

outarg(filename)
D 2
string filename;
E 2
I 2
String filename;
E 2
{
D 3
	if (outfile != NIL) {
		error("multiple output redirect");
	}
	outfile = filename;
E 3
I 3
    if (outfile != NIL) {
	error("multiple output redirect");
    }
    outfile = filename;
E 3
}

/*
D 2
 * run starts debuggee executing
E 2
I 2
 * Initial start of the process.  The idea is to get it to the point
 * where the object code has been loaded but execution has not begun.
E 2
 */

I 2
initstart()
{
D 3
	arginit();
	argv[argc] = NIL;
	start(argv, infile, outfile);
E 3
I 3
    arginit();
    argv[argc] = NIL;
D 5
    process = &pbuf;
E 5
    initcache(process);
    start(argv, infile, outfile);
I 4
    if (process->status != STOPPED) {
	panic("could not start program");
    }
E 4
E 3
}

/*
 * Run starts debuggee executing.
 */

E 2
run()
{
D 3
	fixbps();
	curline = 0;
I 2
	argv[argc] = NIL;
E 2
	start(argv, infile, outfile);
	just_started = TRUE;
	isstopped = FALSE;
	cont();
E 3
I 3
    fixbps();
    curline = 0;
    argv[argc] = NIL;
    start(argv, infile, outfile);
D 4
    just_started = TRUE;
    isstopped = FALSE;
    cont();
E 4
I 4
    if (process->status == STOPPED) {
	just_started = TRUE;
	isstopped = FALSE;
	cont();
    } else if (option('r')) {
	panic("could not start program");
    }
E 4
E 3
}

/*
D 2
 * continue execution wherever we left off
E 2
I 2
 * Continue execution wherever we left off.
E 2
 *
 * Note that this routine never returns.  Eventually bpact() will fail
 * and we'll call printstatus or step will call it.
 */

typedef int INTFUNC();

LOCAL INTFUNC *dbintr;
LOCAL intr();

D 3
#define succeeds	== TRUE
#define fails		== FALSE
E 3
I 3
D 7
#define succeeds    == TRUE
E 7
#define fails       == FALSE
E 3

cont()
{
D 3
	dbintr = signal(SIGINT, &intr);
	if (just_started) {
		just_started = FALSE;
E 3
I 3
    dbintr = signal(SIGINT, intr);
    if (just_started) {
	just_started = FALSE;
    } else {
	if (!isstopped) {
	    error("can't continue execution");
	}
	isstopped = FALSE;
	step();
    }
    for (;;) {
	if (single_stepping) {
	    printnews();
E 3
	} else {
D 3
		if (!isstopped) {
			error("can't continue execution");
		}
		isstopped = FALSE;
		step();
E 3
I 3
	    setallbps();
	    resume();
	    unsetallbps();
	    if (bpact() fails) {
		printstatus();
	    }
E 3
	}
D 3
	for (;;) {
		if (single_stepping) {
			printnews();
		} else {
			setallbps();
			resume();
			unsetallbps();
			if (bpact() fails) {
				printstatus();
			}
		}
		step();
	}
D 2
	/*NOTREACHED*/
E 2
I 2
	/* NOTREACHED */
E 3
I 3
	step();
    }
    /* NOTREACHED */
E 3
E 2
}

/*
 * This routine is called if we get an interrupt while "running" px
 * but actually in the debugger.  Could happen, for example, while
 * processing breakpoints.
 *
 * We basically just want to keep going; the assumption is
 * that when the process resumes it will get the interrupt
 * which will then be handled.
 */

LOCAL intr()
{
D 3
	signal(SIGINT, &intr);
E 3
I 3
    signal(SIGINT, intr);
E 3
}

fixintr()
{
D 3
	signal(SIGINT, &dbintr);
E 3
I 3
    signal(SIGINT, dbintr);
E 3
}
E 1
