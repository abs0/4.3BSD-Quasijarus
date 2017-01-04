h39853
s 00005/00005/00023
d D 5.3 88/01/03 00:33:19 bostic 6 5
c neither K&R or ANSI C allow untyped function declarations
e
s 00000/00001/00028
d D 5.2 87/04/07 15:51:42 mckusick 5 4
c port for tahoe from Nir peleg of CCI
e
s 00007/00003/00022
d D 5.1 85/06/06 16:07:24 dist 4 3
c Add copyright
e
s 00001/00000/00024
d D 1.3 82/03/08 19:31:10 linton 3 2
c added entry "isendofproc"
e
s 00001/00001/00023
d D 1.2 82/01/18 22:14:53 linton 2 1
c sccsid
e
s 00024/00000/00000
d D 1.1 82/01/18 19:02:36 linton 1 0
c date and time created 82/01/18 19:02:36 by linton
e
u
U
t
T
I 1
D 4
/* Copyright (c) 1982 Regents of the University of California */

D 2
static char sccsid[] = "%Z%%M% %I% %G%";
E 2
I 2
/* static char sccsid[] = "%Z%%M% %I% %G%"; */
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 4
E 2

/*
 * Definitions for the machine module.
 *
 * This module has the low level machine interface.  This consists
 * mostly of dealing with machine instructions and also setting
 * and unsetting breakpoints.
 */

ADDRESS pc;			/* current program counter */
LINENO curline;			/* line number associated with pc */
SYM *curfunc;			/* pointer to active function symbol */
D 5
short errnum;			/* current error number */
E 5

D 6
setbp();			/* set a breakpoint */
unsetbp();			/* unset a breakpoint */
E 6
I 6
int setbp();			/* set a breakpoint */
int unsetbp();			/* unset a breakpoint */
E 6
BOOLEAN isbperr();		/* test if a breakpoint has occurred */
D 6
printerror();			/* print out an execution error message */
E 6
I 6
int printerror();		/* print out an execution error message */
E 6
ADDRESS nextaddr();		/* address of next line to be executed */
I 3
BOOLEAN isendofproc();		/* test if address is at end of procedure */
E 3
D 6
printinst(), printninst();	/* print the instruction at a given address */
printdata(), printndata();	/* print the contents of a given data address */
E 6
I 6
int printinst(), printninst();	/* print the instruction at a given address */
int printdata(), printndata();	/* print the contents of a given data address */
E 6
E 1
