h31847
s 00000/00004/00085
d D 5.2 87/04/07 15:55:08 mckusick 5 4
c port to tahoe by Nir peleg of CCI
e
s 00008/00003/00081
d D 5.1 85/06/06 11:38:18 dist 4 3
c Add copyright
e
s 00047/00030/00037
d D 1.3 82/02/11 23:53:17 linton 3 2
c centralized the printing of a source line number and file 
c to a routine called "printwhere" in pstatus.c ... other routines 
c were modified to use this routine
e
s 00001/00001/00066
d D 1.2 82/02/02 12:47:22 linton 2 1
c changed call to exit to a call to quit
e
s 00067/00000/00000
d D 1.1 82/01/18 19:20:44 linton 1 0
c date and time created 82/01/18 19:20:44 by linton
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
 * process status routines
 */

#include "defs.h"
#include <signal.h>
#include "process.h"
#include "machine.h"
#include "breakpoint.h"
#include "source.h"
#include "object.h"
#include "process.rep"

/*
 * Print the status of the process.
 * This routine does not return.
 */

printstatus()
{
D 3
	if (process->signo == SIGINT) {
		isstopped = TRUE;
		printerror();
E 3
I 3
    if (process->signo == SIGINT) {
	isstopped = TRUE;
	printerror();
    }
    if (isbperr() && isstopped) {
	skimsource(srcfilename(pc));
	printf("stopped at ");
	printwhere(curline, cursource);
	putchar('\n');
	if (curline > 0) {
	    printlines(curline, curline);
	} else {
	    printinst(pc, pc);
E 3
	}
D 3
	if (isbperr() && isstopped) {
		printf("stopped at ");
		if (curline > 0) {
			printf("line %d", curline);
			if (nlhdr.nfiles > 1) {
				printf(" in file %s", cursource);
			}
			putchar('\n');
			printlines(curline, curline);
		} else {
#			if (isvaxpx)
				printf("location %d\n", pc);
#			else
				printf("location 0x%x\n", pc);
#			endif
			printinst(pc, pc);
		}
		erecover();
E 3
I 3
	erecover();
    } else {
	isstopped = FALSE;
	fixbps();
	fixintr();
	if (process->status == FINISHED) {
	    quit(0);
E 3
	} else {
D 3
		isstopped = FALSE;
		fixbps();
		fixintr();
		if (process->status == FINISHED) {
D 2
			exit(0);
E 2
I 2
			quit(0);
E 2
		} else {
			printerror();
		}
E 3
I 3
	    printerror();
E 3
	}
I 3
    }
E 3
}

I 3

E 3
/*
I 3
 * Print out the "line N [in file F]" information that accompanies
 * messages in various places.
 */

printwhere(lineno, filename)
LINENO lineno;
char *filename;
{
    if (lineno > 0) {
	printf("line %d", lineno);
	if (nlhdr.nfiles > 1) {
	    printf(" in file %s", filename);
	}
    } else {
D 5
#	if (isvaxpx)
E 5
	    printf("location %d\n", pc);
D 5
#	else
	    printf("location 0x%x\n", pc);
#	endif
E 5
    }
}

/*
E 3
 * Return TRUE if the process is finished.
 */

BOOLEAN isfinished(p)
PROCESS *p;
{
D 3
	return(p->status == FINISHED);
E 3
I 3
    return(p->status == FINISHED);
E 3
}
E 1
