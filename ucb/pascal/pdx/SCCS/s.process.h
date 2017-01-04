h52657
s 00017/00017/00020
d D 5.2 88/01/03 00:33:23 bostic 7 6
c neither K&R or ANSI C allow untyped function declarations
e
s 00007/00003/00030
d D 5.1 85/06/06 16:09:54 dist 6 5
c Add copyright
e
s 00002/00001/00031
d D 1.5 82/02/11 23:49:59 linton 5 4
c addition of "printwhere" routine
e
s 00001/00001/00031
d D 1.4 82/01/23 14:29:15 linton 4 3
c start <- initstart
e
s 00002/00001/00030
d D 1.3 82/01/20 17:03:21 linton 3 2
c added setargs
e
s 00001/00001/00030
d D 1.2 82/01/18 22:15:09 linton 2 1
c sccsid
e
s 00031/00000/00000
d D 1.1 82/01/18 19:02:45 linton 1 0
c date and time created 82/01/18 19:02:45 by linton
e
u
U
t
T
I 1
D 6
/* Copyright (c) 1982 Regents of the University of California */

D 2
static char sccsid[] = "%Z%%M% %I% %G%";
E 2
I 2
/* static char sccsid[] = "%Z%%M% %I% %G%"; */
E 6
I 6
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 6
E 2

/*
 * Definitions for process module.
 *
 * This module contains the routines to manage the execution and
 * tracing of the debuggee process.
 */

typedef struct process PROCESS;

PROCESS *process;

D 4
start();		/* start up process */
E 4
I 4
D 5
initstart();	/* initial process start up */
E 5
I 5
D 7
initstart();		/* initial process start up */
E 5
E 4
run();			/* start program running */
D 3
arginit();		/* initialize for program arguments */
E 3
I 3
arginit();		/* initialize program arguments */
setargs();		/* special argument handling */
E 3
newarg();		/* add a new argument to list for program */
inarg();		/* set standard input for program */
outarg();		/* set standard output for program */
cont();			/* continue execution where last left off */
step();			/* single step */
stepc();		/* single step command */
stepto();		/* execute up to a given address */
next();			/* single step, skip over calls */
endprogram();		/* note the termination of the program */
printstatus();		/* print current error */
I 5
printwhere();		/* print current source line and file */
E 7
I 7
int initstart();	/* initial process start up */
int run();		/* start program running */
int arginit();		/* initialize program arguments */
int setargs();		/* special argument handling */
int newarg();		/* add a new argument to list for program */
int inarg();		/* set standard input for program */
int outarg();		/* set standard output for program */
int cont();		/* continue execution where last left off */
int step();		/* single step */
int stepc();		/* single step command */
int stepto();		/* execute up to a given address */
int next();		/* single step, skip over calls */
int endprogram();	/* note the termination of the program */
int printstatus();	/* print current error */
int printwhere();	/* print current source line and file */
E 7
E 5
BOOLEAN isfinished();	/* TRUE if process has terminated */
D 7
iread(), dread();	/* read from the process' address space */
iwrite(), dwrite();	/* write to the process' address space */
E 7
I 7
int iread(), dread();	/* read from the process' address space */
int iwrite(), dwrite();	/* write to the process' address space */
E 7
E 1
