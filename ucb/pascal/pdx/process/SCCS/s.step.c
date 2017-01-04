h30559
s 00001/00047/00089
d D 5.2 87/04/07 15:55:15 mckusick 4 3
c port to tahoe by Nir peleg of CCI
e
s 00008/00003/00128
d D 5.1 85/06/06 11:45:16 dist 3 2
c Add copyright
e
s 00054/00058/00077
d D 1.2 82/02/11 23:53:25 linton 2 1
c centralized the printing of a source line number and file 
c to a routine called "printwhere" in pstatus.c ... other routines 
c were modified to use this routine
e
s 00135/00000/00000
d D 1.1 82/01/18 19:20:56 linton 1 0
c date and time created 82/01/18 19:20:56 by linton
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
 * Continue execution up to the next source line.
 *
 * We call "nextaddr" from the machine module to figure out
 * what the object address is that corresponds to the next source line.
 * If nextaddr returns -1, then the end of the program has been reached.
 *
 * There are two ways to define the next source line depending on what
 * is desired when a procedure or function call is encountered.  Step
 * stops at the beginning of the procedure or call; next skips over it.
 */

#include "defs.h"
#include "process.h"
#include "machine.h"
#include "breakpoint.h"
#include "source.h"
#include "mappings.h"
#include "process.rep"

D 2
#	if (isvax)
#		include "machine/vaxops.h"
E 2
I 2
D 4
#   if (isvax)
#       include "machine/vaxops.h"
E 2

D 2
		LOCAL ADDRESS getcall();
#	endif
E 2
I 2
	LOCAL ADDRESS getcall();
#   endif
E 2

E 4
/*
 * Stepc is what is called when the step command is given.
 * It has to play with the "isstopped" information.
 */

stepc()
{
D 2
	if (!isstopped) {
		error("can't continue execution");
	}
	isstopped = FALSE;
	dostep(FALSE);
	isstopped = TRUE;
E 2
I 2
    if (!isstopped) {
	error("can't continue execution");
    }
    isstopped = FALSE;
    dostep(FALSE);
    isstopped = TRUE;
E 2
}

next()
{
D 2
	if (!isstopped) {
		error("can't continue execution");
	}
	isstopped = FALSE;
	dostep(TRUE);
	isstopped = TRUE;
E 2
I 2
    if (!isstopped) {
	error("can't continue execution");
    }
    isstopped = FALSE;
    dostep(TRUE);
    isstopped = TRUE;
E 2
}

step()
{
D 2
	dostep(FALSE);
E 2
I 2
    dostep(FALSE);
E 2
}

/*
 * Resume execution up to the given address.  It is assumed that
 * no breakpoints exist between the current address and the one
 * we're stepping to.  This saves us from setting all the breakpoints.
 */

stepto(addr)
ADDRESS addr;
{
D 2
	setbp(addr);
	resume();
	unsetbp(addr);
	if (!isbperr()) {
		printstatus();
	}
E 2
I 2
    setbp(addr);
    resume();
    unsetbp(addr);
    if (!isbperr()) {
	printstatus();
    }
E 2
}

LOCAL dostep(isnext)
BOOLEAN isnext;
{
D 2
	register ADDRESS addr;
	register LINENO line;
	char *filename;
E 2
I 2
    register ADDRESS addr;
    register LINENO line;
D 4
    char *filename;
E 4
E 2

D 2
	addr = pc;
	do {
#		if (isvaxpx)
			addr = nextaddr(addr, isnext);
#		else
			if (isnext && (addr = getcall(addr)) != 0) {
				stepto(addr);
			} else {
				pstep(process);
				addr = process->pc;
				pc = process->pc;
				errnum = process->signo;
				if (!isbperr()) {
					printstatus();
				}
			}
#		endif
		line = linelookup(addr);
	} while (line == 0 && !ss_instructions);
	stepto(addr);
	curline = line;
	filename = srcfilename(addr);
	if (filename != cursource) {
		skimsource(filename);
	}
E 2
I 2
    addr = pc;
    do {
D 4
#       if (isvaxpx)
	    addr = nextaddr(addr, isnext);
#       else
	    if (isnext && (addr = getcall(addr)) != 0) {
		stepto(addr);
	    } else {
		pstep(process);
		addr = process->pc;
		pc = process->pc;
		errnum = process->signo;
		if (!isbperr()) {
		    printstatus();
		}
	    }
#       endif
E 4
I 4
	addr = nextaddr(addr, isnext);
E 4
	line = linelookup(addr);
    } while (line == 0 && !ss_instructions);
    stepto(addr);
    curline = line;
E 2
}
D 4

# if (isvax)

/*
 * If the current address contains a call instruction, return the
 * address of the instruction where control will return.
 *
 * This function is intentionally dependent on a particular type
 * of calling sequence.
 */

LOCAL ADDRESS getcall(addr)
ADDRESS addr;
{
D 2
	VAXOP op;
E 2
I 2
    VAXOP op;
E 2

D 2
	iread(&op, addr, sizeof(addr));
	if (op == O_CALLS) {
		return(addr + 7);
	} else {
		return(0);
	}
E 2
I 2
    iread(&op, addr, sizeof(addr));
    if (op == O_CALLS) {
	return(addr + 7);
    } else {
	return(0);
    }
E 2
}

# endif
E 4
E 1
