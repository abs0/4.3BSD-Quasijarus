h46578
s 00013/00013/00064
d D 5.2 88/01/03 00:28:23 bostic 4 3
c neither K&R or ANSI C allow untyped function declarations
e
s 00007/00003/00070
d D 5.1 85/06/06 16:05:40 dist 3 2
c Add copyright
e
s 00001/00001/00072
d D 1.2 82/01/18 22:14:42 linton 2 1
c sccsid
e
s 00073/00000/00000
d D 1.1 82/01/18 19:02:32 linton 1 0
c date and time created 82/01/18 19:02:32 by linton
e
u
U
t
T
I 1
D 3
/* Copyright (c) 1982 Regents of the University of California */

D 2
static char sccsid[] = "%Z%%M% %I% %G%";
E 2
I 2
/* static char sccsid[] = "%Z%%M% %I% %G%"; */
E 3
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 3
E 2

/*
 * Breakpoint module definitions.
 *
 * This module contains routines that manage breakpoints at a high level.
 * This includes adding and deleting breakpoints, handling the various
 * types of breakpoints when they happen, management of conditions for
 * breakpoints, and display information after single stepping.
 */

unsigned short tracing;
unsigned short var_tracing;
unsigned short inst_tracing;

BOOLEAN isstopped;

#define ss_lines		(tracing != 0)
#define ss_variables		(var_tracing != 0)
#define ss_instructions		(inst_tracing != 0)
#define single_stepping		(ss_lines || ss_variables || ss_instructions)

/*
 * types of breakpoints
 */

typedef enum {
	ALL_ON,			/* turn TRACE on */
	ALL_OFF,		/* turn TRACE off */
	INST,			/* trace instruction (source line) */
	CALL, RETURN,		/* trace procedure/function */
	BLOCK_ON,		/* set CALL breakpoint */
	BLOCK_OFF,		/* clear CALL breakpoint */
	TERM_ON,		/* turn TRACEVAR on */
	TERM_OFF,		/* turn TRACEVAR off */
	AT_BP,			/* print expression at a line */
	STOP_BP,		/* stop execution */
	CALLPROC,		/* return from a "call"-ed procedure */
	END_BP,			/* return from program */
	STOP_ON,		/* start looking for stop condition */
	STOP_OFF,		/* stop looking for stop condition */
} BPTYPE;

/*
 * Things that are on the tracing or condition list are either
 * associated with the trace (implying printing) or stop commands.
 */

typedef enum { TRPRINT, TRSTOP } TRTYPE;

/*
 * routines available from this module
 */

D 4
addvar();		/* add a variable to the trace list */
delvar();		/* delete a variable from the trace list */
printvarnews();		/* print out variables that have changed */
trfree();		/* free the entire trace list */
addcond();		/* add a condition to the list */
delcond();		/* delete a condition from the list */
E 4
I 4
int addvar();		/* add a variable to the trace list */
int delvar();		/* delete a variable from the trace list */
int printvarnews();	/* print out variables that have changed */
int trfree();		/* free the entire trace list */
int addcond();		/* add a condition to the list */
int delcond();		/* delete a condition from the list */
E 4
BOOLEAN trcond();	/* determine if any trace condition is true */
BOOLEAN stopcond();	/* determine if any stop condition is true */

D 4
addbp();		/* add a breakpoint */
delbp();		/* delete a breakpoint, return FALSE if unsuccessful */
bpfree();		/* free all breakpoint information */
setallbps();		/* set traps for all breakpoints */
unsetallbps();		/* remove traps at all breakpoints */
E 4
I 4
int addbp();		/* add a breakpoint */
int delbp();		/* delete a breakpoint, return FALSE if unsuccessful */
int bpfree();		/* free all breakpoint information */
int setallbps();	/* set traps for all breakpoints */
int unsetallbps();	/* remove traps at all breakpoints */
E 4
BOOLEAN bpact();	/* handle a breakpoint */
D 4
fixbps();		/* destroy temporary breakpoints left after a fault */
status();		/* list items being traced */
E 4
I 4
int fixbps();		/* destroy temporary breakpoints left after a fault */
int status();		/* list items being traced */
E 4
E 1
