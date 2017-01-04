h50693
s 00018/00008/00044
d D 5.2 87/04/07 15:53:32 mckusick 5 4
c port to tahoe by Nir peleg of CCI
e
s 00008/00002/00044
d D 5.1 85/06/06 08:18:38 dist 4 3
c Add copyright
e
s 00022/00028/00024
d D 1.3 82/02/11 23:56:29 linton 3 2
c modified to usd "printwhere" from process/pstatus.c rather than 
c printing out "line N in file F" itself
e
s 00001/00008/00051
d D 1.2 82/01/23 17:02:34 linton 2 1
c remove call to iîét() under option('r'), this is now in resume()
e
s 0009/00000/00000
d D 1.1 82/01/18 19:20:17 linton 1 0
c date and time created 82/01/18 19:20:17 by linton
e
u
U
t
T
I 1
D 4
/* Copyright (c) 1982 Regents of the University of California */
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 4

D 4
static char sccsid[] = "%Z%%M% %I% %G%";
E 4
I 4
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 4

/*
D 2
 * print out an execution time error
 *
 * Have to check if the -r option was specified; if so then
 * the object file information hasn't been read in yet.
E 2
I 2
 * Print out an execution time error.
E 2
 */

#include "defs.h"
#include <signal.h>
#include "machine.h"
D 2
#include "main.h"
E 2
#include "sym.h"
#include "process.h"
#include "source.h"
#include "object.h"
#include "mappings.h"
#include "pxerrors.h"
#include "process/process.rep"

I 5
#ifdef tahoe
BOOLEAN shouldrestart;
#endif

E 5
printerror()
{
D 3
	register PROCESS *p;
	char *filename;
	int c;
E 3
I 3
    register PROCESS *p;
D 5
    char *filename;
    int c;
E 5
E 3

D 3
	p = process;
	if (p->signo != ESIGNAL && p->signo != SIGINT) {
		error("signal %d at px pc %d, lc %d", p->signo, p->pc, pc);
E 3
I 3
    p = process;
    if (p->signo != ESIGNAL && p->signo != SIGINT) {
	error("signal %d at px pc %d, lc %d", p->signo, p->pc, pc);
    }
    curline = srcline(pc);
    curfunc = whatblock(pc);
    skimsource(srcfilename(pc));
    if (p->signo == ESIGNAL) {
	printf("\nerror at ");
	printwhere(curline, cursource);
D 5
	if (errnum != 0) {
	    printf(":  %s", pxerrmsg[errnum]);
E 3
D 2
	}
	if (option('r')) {
		init();
E 2
	}
E 5
I 5
        putchar('\n');
        printlines(curline, curline);
#ifdef tahoe
	/*
	 * this px is no good; it is easier to kill it and start
	 * a new one than to make it recover...
	 * make runtime/callproc.c know it too.
	 */
	shouldrestart = TRUE;
#endif
        erecover();
E 5
D 3
	curline = srcline(pc);
	curfunc = whatblock(pc);
	if ((filename = srcfilename(pc)) != cursource) {
		skimsource(filename);
	}
	if (p->signo == ESIGNAL) {
		printf("\nerror at line %d", curline);
		if (nlhdr.nfiles > 1) {
			printf("in file %s", cursource);
		}
		if (errnum != 0) {
			printf(":  %s", pxerrmsg[errnum]);
		}
	} else {
		printf("\n\ninterrupt at line %d", curline);
		if (nlhdr.nfiles > 1) {
			printf(" in file %s", cursource);
		}
	}
	putchar('\n');
	printlines(curline, curline);
	erecover();
E 3
I 3
    } else {
	printf("\n\ninterrupt at ");
	printwhere(curline, cursource);
I 5
        putchar('\n');
        printlines(curline, curline);
        erecover();
E 5
    }
D 5
    putchar('\n');
    printlines(curline, curline);
    erecover();
E 5
E 3
}
E 1
