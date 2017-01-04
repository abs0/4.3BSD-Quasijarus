h41857
s 00008/00002/00075
d D 5.1 85/06/06 11:50:15 dist 3 2
c Add copyright
e
s 00045/00037/00032
d D 1.2 82/02/11 23:55:41 linton 2 1
c modified to use "printwhere" from process/pstatus.c rather than 
c printing out "line N in file F" itself
e
s 00069/00000/00000
d D 1.1 82/01/18 19:21:07 linton 1 0
c date and time created 82/01/18 19:21:07 by linton
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
 * Print a list of currently active blocks starting with most recent.
 */

#include "defs.h"
#include "runtime.h"
#include "frame.rep"
#include "sym.h"
#include "machine.h"
#include "object.h"
#include "mappings.h"

where()
{
D 2
	FRAME *frp;
	ADDRESS prevpc;
	LINENO line;
	SYM *f;
E 2
I 2
    FRAME *frp;
    ADDRESS prevpc;
    LINENO line;
    SYM *f;
E 2

D 2
	if (pc == 0) {
		error("program is not active");
	}
	prevpc = pc;
	for (frp = curframe(); frp != NIL; frp = nextframe(frp)) {
		f = whatblock(entry(frp));
		line = srcline(prevpc);
		printf("%s", name(f));
		printparams(f, frp);
		printf(", line %d\n", line);
		prevpc = frp->save_pc;
	}
E 2
I 2
    if (pc == 0) {
	error("program is not active");
    }
    prevpc = pc;
    for (frp = curframe(); frp != NIL; frp = nextframe(frp)) {
	f = whatblock(entry(frp));
E 2
	line = srcline(prevpc);
D 2
	printf("%s, line %d\n", name(program), line);
E 2
I 2
	printf("%s", name(f));
	printparams(f, frp);
	printf(", ");
	printwhere(line, srcfilename(prevpc));
	printf("\n");
	prevpc = frp->save_pc;
    }
    line = srcline(prevpc);
    printf("%s, ", name(program));
    printwhere(line, srcfilename(prevpc));
    printf("\n");
E 2
}

/*
 * Dump the world to the given file.
 * Like "where", but variables are dumped also.
 */

dump()
{
D 2
	FRAME *frp;
	ADDRESS prevpc;
	LINENO line;
	SYM *f;
E 2
I 2
    FRAME *frp;
    ADDRESS prevpc;
    LINENO line;
    SYM *f;
E 2

D 2
	if (pc == 0) {
		error("program is not active");
	}
	prevpc = pc;
	for (frp = curframe(); frp != NIL; frp = nextframe(frp)) {
		f = whatblock(entry(frp));
		line = srcline(prevpc);
		prevpc = frp->save_pc;
		printf("%s", name(f));
		printparams(f, frp);
		printf(", line %d\n", line);
		dumpvars(f, frp);
		putchar('\n');
	}
E 2
I 2
    if (pc == 0) {
	error("program is not active");
    }
    prevpc = pc;
    for (frp = curframe(); frp != NIL; frp = nextframe(frp)) {
	f = whatblock(entry(frp));
E 2
	line = srcline(prevpc);
D 2
	printf("%s, line %d\n", name(program), line);
	dumpvars(program, NIL);
E 2
I 2
	printf("%s", name(f));
	printparams(f, frp);
	printf(", ");
	printwhere(line, srcfilename(prevpc));
	printf("\n");
	dumpvars(f, frp);
	putchar('\n');
	prevpc = frp->save_pc;
    }
    line = srcline(prevpc);
    printf("%s, ", name(program));
    printwhere(line, srcfilename(prevpc));
    printf("\n");
    dumpvars(program, NIL);
E 2
}
E 1
