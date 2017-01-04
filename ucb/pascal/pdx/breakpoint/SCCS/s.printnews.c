h33666
s 00008/00002/00042
d D 5.1 85/06/05 16:58:05 dist 3 2
c Add copyright
e
s 00018/00028/00026
d D 1.2 82/02/11 23:51:50 linton 2 1
c modifications for centralizing the printing of a source line 
c and file
e
s 00054/00000/00000
d D 1.1 82/01/18 19:19:57 linton 1 0
c date and time created 82/01/18 19:19:57 by linton
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
D 2
 * print out news during single step tracing
E 2
I 2
 * Print out news during single step tracing.
E 2
 *
 * We have to handle all the single stepping possibilities,
 * including combinations.  A combination of single stepping
 * by line and by instruction causes "curline" to be 0 but
 * "ss_lines" to be TRUE.  We avoid trying to print lines in this case.
 */

#include "defs.h"
#include "breakpoint.h"
#include "sym.h"
#include "source.h"
#include "object.h"
#include "mappings.h"
#include "machine.h"

printnews()
{
D 2
	if (ss_variables) {
		prvarnews();
E 2
I 2
    if (ss_variables) {
	prvarnews();
    }
    if (trcond()) {
	if (ss_lines && curline > 0) {
	    skimsource(srcfilename(pc));
	    printf("trace:  ");
	    printlines(curline, curline);
E 2
	}
D 2
	if (trcond()) {
		if (ss_lines && curline > 0) {
			printf("trace:  ");
			printlines(curline, curline);
		}
		if (ss_instructions) {
			printf("inst trace:	");
			printinst(pc, pc);
		}
E 2
I 2
	if (ss_instructions) {
	    printf("inst trace: ");
	    printinst(pc, pc);
E 2
	}
D 2
	bpact();
	if (stopcond()) {
		isstopped = TRUE;
		getsrcinfo();
		printstatus();
	}
}

getsrcinfo()
{
	char *filename;

E 2
I 2
    }
    bpact();
    if (stopcond()) {
	isstopped = TRUE;
E 2
	curline = srcline(pc);
D 2
	filename = srcfilename(pc);
	if (filename != cursource) {
		skimsource(filename);
	}
E 2
I 2
	printstatus();
    }
E 2
}
E 1
