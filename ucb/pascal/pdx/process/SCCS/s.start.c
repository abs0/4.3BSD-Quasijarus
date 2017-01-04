h01184
s 00041/00034/00090
d D 5.2 87/04/07 15:55:14 mckusick 9 8
c port to tahoe by Nir peleg of CCI
e
s 00008/00003/00116
d D 5.1 85/06/06 11:44:04 dist 8 7
c Add copyright
e
s 00000/00002/00119
d D 1.7 82/03/08 19:32:34 linton 7 6
c changed handling of the process not starting up so that 
c when "run < abc" is given where "abc" doesn't exist the right thing happens
e
s 00000/00003/00121
d D 1.6 82/03/08 18:54:39 linton 6 5
c put in cache initialization in at beginning of process startup 
c ("initstart") ... the cache was non-empty after a "pi" which meant 
c instruction reads were getting the wrong values
e
s 00002/00005/00122
d D 1.5 82/02/11 23:53:21 linton 5 4
c centralized the printing of a source line number and file 
c to a routine called "printwhere" in pstatus.c ... other routines 
c were modified to use this routine
e
s 00001/00000/00126
d D 1.4 82/02/10 00:17:15 linton 4 3
c SIGILL has got to be traced for catching breakpoints, 
c it seems I forgot this in my old age.
e
s 00063/00065/00063
d D 1.3 82/02/07 16:08:41 linton 3 2
c slight change in the way signals are handled -- px now gets 
c all but interrupt, trap, and iot, it is assumed px handles the errors 
c and then sends itself a trap
e
s 00025/00020/00103
d D 1.2 82/02/02 12:53:57 linton 2 1
c removed all argument handling, stuff in runcont is used; 
c modified handling of px exit conditions in the case of the implicit "-t" 
c option which is set when running under "pix" or "obj"
e
s 00123/00000/00000
d D 1.1 82/01/18 19:20:54 linton 1 0
c date and time created 82/01/18 19:20:54 by linton
e
u
U
t
T
I 1
D 8
/* Copyright (c) 1982 Regents of the University of California */
E 8
I 8
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 8

D 8
static char sccsid[] = "%Z%%M% %I% %G%";

E 8
I 8
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
I 9

E 9
E 8
/*
 * Begin execution.
 *
 * For px, pstart does a traced exec to read in px and then stop.  But we
 * want control after px has read in the obj file and before it starts
D 2
 * executing.  The "-d" option to px tells it to give us control
E 2
I 2
 * executing.  The zeroth argument to px tells it to give us control
E 2
 * by sending itself a signal just prior to interpreting.
 *
 * We set a "END_BP" breakpoint at the end of the code so that the
 * process data doesn't disappear after the program terminates.
 */

#include "defs.h"
#include <signal.h>
#include "process.h"
#include "machine.h"
I 2
#include "main.h"
E 2
#include "breakpoint.h"
#include "source.h"
#include "object.h"
#include "mappings.h"
#include "sym.h"
#include "process.rep"

D 3
#	if (isvaxpx)
#		include "pxinfo.h"
#	endif
E 3
I 3
D 9
#   if (isvaxpx)
#       include "pxinfo.h"
#   endif
E 9
I 9
#include "pxinfo.h"
E 9
E 3

D 6
LOCAL PROCESS pbuf;

E 6
start(argv, infile, outfile)
char **argv;
char *infile, *outfile;
{
D 2
	char *pargv[4];
#	if (isvaxpx)
		TRAPARGS *ap, t;
#	endif
E 2
I 2
D 3
	char *cmd;
E 3
I 3
    char *cmd;
E 3
E 2

D 3
	process = &pbuf;
	setsigtrace();
D 2
	if (argv == NIL) {
		argv = pargv;
#		if (isvaxpx)
			pargv[0] = "px";
			pargv[1] = "-d";
			pargv[2] = objname;
			pargv[3] = NIL;
#		else
			pargv[0] = objname;
			pargv[1] = NIL;
#		endif
	}
	pstart(process, argv, infile, outfile);
E 2
I 2
#	if (isvaxpx)
		cmd = "px";
#	else
		cmd = argv[0];
#	endif
	pstart(process, cmd, argv, infile, outfile);
E 2
	if (process->status == STOPPED) {
#		if (isvaxpx)
I 2
			TRAPARGS *ap, t;
E 3
I 3
D 6
    process = &pbuf;
E 6
    setsigtrace();
D 9
#   if (isvaxpx)
	cmd = "px";
#   else
	cmd = argv[0];
#   endif
E 9
I 9
    cmd = "/usr/ucb/px";
E 9
    pstart(process, cmd, argv, infile, outfile);
    if (process->status == STOPPED) {
D 9
#       if (isvaxpx)
	    TRAPARGS *ap, t;
E 9
I 9
	TRAPARGS *ap, t;
E 9
E 3

E 2
D 3
			pcont(process);
			if (process->status != STOPPED) {
D 2
				panic("px exited with %d", process->exitval);
E 2
I 2
				if (option('t')) {
					quit(process->exitval);
				} else {
					panic("px exited with %d", process->exitval);
				}
E 2
			}
			dread(&ap, process->fp + 2*sizeof(int), sizeof(ap));
			dread(&t, ap, sizeof(TRAPARGS));
			if (t.nargs != 5) {
D 2
				panic("start: args out of sync");
E 2
I 2
				if (option('t')) {
					unsetsigtraces(process);
					pcont(process);
					quit(process->exitval);
				} else {
					panic("start: args out of sync");
				}
E 2
			}
			DISPLAY = t.disp;
			DP = t.dp;
			ENDOFF = t.objstart;
			PCADDRP = t.pcaddrp;
			LOOPADDR = t.loopaddr;
#		endif
		pc = 0;
		curfunc = program;
		if (objsize != 0) {
			addbp(lastaddr(), END_BP, NIL, NIL, NIL, 0);
E 3
I 3
D 9
	    pcont(process);
	    if (process->status != STOPPED) {
		if (option('t')) {
		    quit(process->exitval);
		} else {
		    panic("px exited with %d", process->exitval);
E 3
		}
E 9
I 9
	pcont(process);
	if (process->status != STOPPED) {
	    if (option('t')) {
		quit(process->exitval);
	    } else {
		panic("px exited with %d", process->exitval);
E 9
I 2
D 3
	} else {
		panic("could not start program");
E 3
I 3
	    }
D 9
	    dread(&ap, process->fp + 2*sizeof(int), sizeof(ap));
	    dread(&t, ap, sizeof(TRAPARGS));
	    if (t.nargs != 5) {
		if (option('t')) {
		    unsetsigtraces(process);
		    pcont(process);
		    quit(process->exitval);
		} else {
		    panic("start: args out of sync");
		}
E 9
I 9
	}
#ifdef tahoe
	dread(&ap, process->fp, sizeof(ap));
	ap = (TRAPARGS *)((unsigned)ap - 4);
	dread(&RETLOC, process->fp - 8, sizeof(RETLOC));
#else
	dread(&ap, process->fp + 2*sizeof(int), sizeof(ap));
#endif
	dread(&t, ap, sizeof(TRAPARGS));

#define NARGS 5
#ifdef tahoe
#	define STKNARGS (sizeof(int)*(NARGS+1))
#	define NARGLOC  t.trp_removed
#else
#	define STKNARGS (NARGS)
#	define NARGLOC  t.nargs
#endif
	if (NARGLOC != STKNARGS) {
	    if (option('t')) {
		unsetsigtraces(process);
		pcont(process);
		quit(process->exitval);
	    } else {
		panic("start: args out of sync");
E 9
	    }
D 9
	    DISPLAY = t.disp;
	    DP = t.dp;
	    ENDOFF = t.objstart;
	    PCADDRP = t.pcaddrp;
	    LOOPADDR = t.loopaddr;
#       endif
E 9
I 9
	}
	DISPLAY = t.disp;
	DP = t.dp;
	ENDOFF = t.objstart;
	PCADDRP = t.pcaddrp;
	LOOPADDR = t.loopaddr;
E 9
	pc = 0;
	curfunc = program;
	if (objsize != 0) {
	    addbp(lastaddr(), END_BP, NIL, NIL, NIL, 0);
E 3
E 2
	}
I 3
D 7
    } else {
	panic("could not start program");
E 7
    }
E 3
}

/*
 * Note the termination of the program.  We do this so as to avoid
 * having the process exit, which would make the values of variables
 * inaccessible.
 *
 * Although the END_BP should really be deleted, it is taken
 * care of by fixbps the next time the program runs.
 */

endprogram()
{
D 3
	char *filename;
E 3
I 3
D 5
    char *filename;
E 3

E 5
D 3
	if (ss_variables) {
		prvarnews();
	}
	printf("\nexecution completed\n");
	curfunc = program;
	if ((filename = srcfilename(pc)) != cursource) {
		skimsource(filename);
	}
	curline = lastlinenum;
	erecover();
E 3
I 3
    if (ss_variables) {
	prvarnews();
    }
    printf("\nexecution completed\n");
    curfunc = program;
D 5
    if ((filename = srcfilename(pc)) != cursource) {
	skimsource(filename);
    }
E 5
I 5
    skimsource(srcfilename(pc));
E 5
    curline = lastlinenum;
    erecover();
E 3
}

/*
 * set up what signals we want to trace
 */

LOCAL setsigtrace()
{
D 3
	register int i;
	register PROCESS *p;
E 3
I 3
D 9
    register int i;
E 9
    register PROCESS *p;
E 3

D 3
	p = process;
	for (i = 1; i < NSIG; i++) {
		psigtrace(p, i, TRUE);
	}
	psigtrace(p, SIGHUP, FALSE);
	psigtrace(p, SIGKILL, FALSE);
E 3
I 3
    p = process;
    psigtrace(p, SIGINT, TRUE);
    psigtrace(p, SIGTRAP, TRUE);
    psigtrace(p, SIGIOT, TRUE);
I 4
    psigtrace(p, SIGILL, TRUE);
I 5
    psigtrace(p, SIGBUS, TRUE);
E 5
E 4
E 3
}
E 1
