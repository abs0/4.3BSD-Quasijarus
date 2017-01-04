h30885
s 00050/00025/00162
d D 5.2 87/04/07 15:55:20 mckusick 11 10
c port to tahoe by Nir peleg of CCI
e
s 00008/00003/00179
d D 5.1 85/06/06 11:42:15 dist 10 9
c Add copyright
e
s 00031/00043/00151
d D 1.9 83/02/14 21:07:04 linton 9 8
c changed to handle new px which sends itself a signal to breakpoint
e
s 00037/00015/00157
d D 1.8 83/02/08 18:03:02 linton 8 7
c modifications for running on a sun
e
s 00002/00002/00170
d D 1.7 82/05/19 20:34:54 linton 7 6
c changed "isatty" references to "isterm"
e
s 00012/00001/00160
d D 1.6 82/03/08 18:56:35 linton 6 5
c now checks if standard input is not a tty in "choose" 
c when about to ask whether or not to enter the debugger after an error 
c ... the problem was when input was redirected and an error occurred 
c pdx would read from the input that was intended for the program
e
s 00014/00004/00147
d D 1.5 82/02/17 00:30:59 linton 5 4
c muddled with "fetchpc", it now looks at the frame mask it see 
c if register 11 was saved as it wanders through the stack frames. 
c The last saved register 11 when unwinding corresponds to the 
c interpreter's pc.
e
s 00092/00106/00059
d D 1.4 82/02/07 16:08:46 linton 4 3
c slight change in the way signals are handled -- px now gets 
c all but interrupt, trap, and iot, it is assumed px handles the errors 
c and then sends itself a trap
e
s 00007/00006/00158
d D 1.3 82/02/02 12:49:01 linton 3 2
c fixed subtle frame pointer bug, made cosmetic change to how debugger is entered 
c when using "-r" or coming from pix
e
s 00001/00001/00163
d D 1.2 82/01/19 01:43:54 linton 2 1
c fixing -r option
e
s 00164/00000/00000
d D 1.1 82/01/18 19:20:51 linton 1 0
c date and time created 82/01/18 19:20:51 by linton
e
u
U
t
T
I 1
D 10
/* Copyright (c) 1982 Regents of the University of California */
E 10
I 10
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 10

D 10
static char sccsid[] = "%Z%%M% %I% %G%";

E 10
I 10
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
I 11

E 11
E 10
/*
D 9
 * resume execution, first setting appropriate registers
E 9
I 9
 * Resume execution, first setting appropriate registers.
E 9
 */

#include "defs.h"
#include <signal.h>
#include "process.h"
#include "machine.h"
#include "main.h"
#include "process.rep"
#include "runtime/frame.rep"

D 4
#	if (isvaxpx)
#		include "machine/pxerrors.h"
#		include "pxinfo.h"
#	endif
E 4
I 4
D 9
#   if (isvaxpx)
#       include "machine/pxerrors.h"
#       include "pxinfo.h"
#   endif
E 9
I 9
#include "machine/pxerrors.h"
#include "pxinfo.h"
E 9
E 4

I 8
D 11
#ifdef vax
E 11
I 11
#if defined(vax) || defined(tahoe)
E 11
E 8
D 9
LOCAL ADDRESS fetchpc();
E 9
I 9
    LOCAL ADDRESS fetchpc();
E 9
I 8
#endif
I 11
#ifdef vax
#define	PCREG	11	/* where px holds virtual pc (see interp.sed) */
#endif
#ifdef tahoe
#define	PCREG	12	/* where px holds virtual pc (see interp.sed) */
#endif
E 11
E 8

I 11
#ifdef sun
E 11
I 8
LOCAL ADDRESS *pcaddr;
I 11
#endif
E 11

E 8
/*
D 8
 * If we hit a breakpoint, px's pc points at a halt instruction,
 * this must be avoided when restarting.
E 8
I 8
 * Resume execution, set (get) pcode location counter before (after) resuming.
E 8
 */

resume()
{
D 4
	register PROCESS *p;
	int oldsigno;
E 4
I 4
    register PROCESS *p;
D 11
    int oldsigno;
E 11
E 4

D 4
	p = process;
	do {
		if (option('e')) {
			printf("execution resumes at pc 0x%x, lc %d\n", process->pc, pc);
			fflush(stdout);
		}
		pcont(p);
#		if (isvaxpx)
			if (p->status == STOPPED) {
D 3
				if (pcframe == NIL) {
					dread(&pcframe, PCADDRP, sizeof(pcframe));
					pcframe++;
				}
E 3
				if (isbperr()) {
					pc = p->reg[11];
				} else {
I 3
					dread(&pcframe, PCADDRP, sizeof(pcframe));
					pcframe++;
E 3
					pc = fetchpc(pcframe);
				}
				pc -= (sizeof(char) + ENDOFF);
			}
#		else
			pc = process->pc;
#		endif
		if (option('e')) {
			printf("execution stops at pc 0x%x, lc %d on sig %d\n",
				process->pc, pc, p->signo);
			fflush(stdout);
		}
		if (p->status == STOPPED) {
			errnum = 0;
		}
	} while (p->signo == SIGCONT);
#	if (isvaxpx)
		oldsigno = p->signo;
		switch (p->signo) {
			case SIGFPE:
				errnum = EOVERFLOW;
				p->signo = ESIGNAL;
				break;

			case SIGSEGV:
				errnum = ESTKOVER;
				p->signo = ESIGNAL;
				break;
		}
D 2
		if (option('r')) {
E 2
I 2
		if (option('r') && oldsigno != 0) {
E 2
			p->signo = oldsigno;
			choose();
			p->signo = ESIGNAL;
		}
E 4
I 4
    p = process;
    do {
	if (option('e')) {
	    printf("execution resumes at pc 0x%x, lc %d\n", process->pc, pc);
	    fflush(stdout);
	}
	pcont(p);
D 9
#       if (isvaxpx)
D 8
	    if (p->status == STOPPED) {
E 4
		if (isbperr()) {
D 4
			p->pc++;
E 4
I 4
		    pc = p->reg[11];
		} else {
		    dread(&pcframe, PCADDRP, sizeof(pcframe));
		    pcframe++;
		    pc = fetchpc(pcframe);
E 8
I 8
#           ifdef sun
		if (pcaddr == 0) {
		    dread(&pcaddr, PCADDRP, sizeof(pcaddr));
E 9
I 9
#       ifdef sun
	    if (pcaddr == 0) {
		dread(&pcaddr, PCADDRP, sizeof(pcaddr));
	    }
	    dread(&pc, pcaddr, sizeof(pc));
D 11
#       else ifdef vax
E 11
I 11
#       else vax || tahoe
E 11
	    if (p->status == STOPPED) {
		if (isbperr()) {
D 11
		    pc = p->reg[11];
E 11
I 11
		    pc = p->reg[PCREG];
E 11
		} else {
		    dread(&pcframe, PCADDRP, sizeof(pcframe));
I 11
#ifdef tahoe
		    pcframe += 14;
#else
E 11
		    pcframe++;
I 11
#endif
E 11
		    pc = fetchpc(pcframe);
E 9
E 8
E 4
		}
D 4
#	endif
E 4
I 4
D 8
		pc -= (sizeof(char) + ENDOFF);
	    }
#       else
E 8
I 8
D 9
		dread(&pc, pcaddr, sizeof(pc));
#           else ifdef vax
		if (p->status == STOPPED) {
		    if (isbperr()) {
			pc = p->reg[11];
		    } else {
			dread(&pcframe, PCADDRP, sizeof(pcframe));
			pcframe++;
			pc = fetchpc(pcframe);
		    }
		    pc -= (sizeof(char) + ENDOFF);
		}
#           endif
#       else /* compiled code */
E 8
	    pc = process->pc;
E 9
I 9
		pc -= (sizeof(char) + ENDOFF);
	    }
E 9
#       endif
	if (option('e')) {
	    printf("execution stops at pc 0x%x, lc %d on sig %d\n",
		process->pc, pc, p->signo);
	    fflush(stdout);
	}
D 11
	if (p->status == STOPPED) {
	    errnum = 0;
	}
E 11
    } while (p->signo == SIGCONT);
D 9
#   if (isvaxpx)
	if (option('r') && p->signo != 0) {
	    choose();
	}
E 9
I 9
    if (option('r') && p->signo != 0) {
	choose();
    }
E 9
D 8
	if (isbperr()) {
	    p->pc++;
	}
E 8
I 8

    /*
     * If px implements a breakpoint by executing a halt instruction
D 9
     * (which is true on the VAX), the real pc must be incremented to
     * skip over it.  On other machines (such as SUNs), px sends itself
     * a signal and no incrementing is needed.
E 9
I 9
     * the real pc must be incremented to skip over it.
     *
     * Currently, px sends itself a signal so no incrementing is needed.
     *
	if (isbperr()) {
	    p->pc++;
	}
E 9
     */
D 9
#       ifdef vax
	    if (isbperr()) {
		p->pc++;
	    }
#       endif
E 8
#   endif
E 9
E 4
}

D 9
# if (isvaxpx)
I 8
# ifdef vax
E 9
I 9
D 11
#ifdef vax
E 11
I 11
#if defined(vax) || defined(tahoe)
E 11
E 9
E 8

/*
 * Find the location in the Pascal object where execution was suspended.
I 5
 *
 * We basically walk back through the frames looking for saved
D 11
 * register 11's.  Each time we find one, we remember it.  When we reach
E 11
I 11
 * register PCREG's.  Each time we find one, we remember it.  When we reach
E 11
 * the frame associated with the interpreter procedure, the most recently
D 11
 * saved register 11 is the one we want.
E 11
I 11
 * saved register PCREG is the one we want.
E 11
E 5
 */

typedef struct {
I 11
#ifdef vax
E 11
D 4
	int fr_handler;
	unsigned int fr_psw : 16;	/* saved psw */
	unsigned int fr_mask : 12;	/* register save mask */
	unsigned int fr_unused : 1;
	unsigned int fr_s : 1;		/* call was a calls, not callg */
	unsigned int fr_spa : 2;	/* stack pointer alignment */
	unsigned int fr_savap;		/* saved arg pointer */
	unsigned int fr_savfp;		/* saved frame pointer */
	int fr_savpc;			/* saved program counter */
E 4
I 4
    int fr_handler;
    unsigned int fr_psw : 16;   /* saved psw */
    unsigned int fr_mask : 12;  /* register save mask */
    unsigned int fr_unused : 1;
    unsigned int fr_s : 1;      /* call was a calls, not callg */
    unsigned int fr_spa : 2;    /* stack pointer alignment */
    unsigned int fr_savap;      /* saved arg pointer */
    unsigned int fr_savfp;      /* saved frame pointer */
    int fr_savpc;           /* saved program counter */
E 4
D 11
} Vaxframe;
E 11
I 11
#endif
#ifdef tahoe
    int fr_savpc;           /* saved program counter */
    unsigned short fr_mask;     /* register save mask */
    unsigned short fr_removed;  /* (nargs+1)*4 */
    unsigned int fr_savfp;      /* saved frame pointer */
#endif
} Stkframe;
E 11

I 5
#define regsaved(frame, n) ((frame.fr_mask&(1 << n)) != 0)

E 5
LOCAL ADDRESS fetchpc(framep)
ADDRESS *framep;
{
D 4
	register PROCESS *p;
	Vaxframe vframe;
	ADDRESS *savfp;
	ADDRESS r;
E 4
I 4
    register PROCESS *p;
D 11
    Vaxframe vframe;
E 11
I 11
    Stkframe sframe;
#ifdef tahoe
#define	PCREGLOC	(-1)
#else
#define	PCREGLOC	(sizeof sframe/sizeof(ADDRESS))
#endif
E 11
    ADDRESS *savfp;
    ADDRESS r;
E 4

D 4
	p = process;
	if (p->fp == (ADDRESS) framep) {
		return(p->reg[11]);
	}
	savfp = (ADDRESS *) p->fp;
E 4
I 4
    p = process;
I 5
D 11
    r = p->reg[11];
E 11
I 11
    r = p->reg[PCREG];
E 11
E 5
    if (p->fp == (ADDRESS) framep) {
D 5
	return(p->reg[11]);
E 5
I 5
	return r;
E 5
    }
    savfp = (ADDRESS *) p->fp;
D 11
    dread(&vframe, savfp, sizeof(vframe));
    while (vframe.fr_savfp != (int) framep && vframe.fr_savfp != 0) {
I 5
	if (regsaved(vframe, 11)) {
	    dread(&r, savfp + 5, sizeof(r));
E 11
I 11
#ifdef tahoe
    savfp -= 2;
#endif
    dread(&sframe, savfp, sizeof(sframe));
    while (sframe.fr_savfp != (int) framep && sframe.fr_savfp != 0) {
	if (regsaved(sframe, PCREG)) {
	    dread(&r, savfp + PCREGLOC, sizeof(r));
E 11
	    r -= sizeof(char);
	}
E 5
D 11
	savfp = (ADDRESS *) vframe.fr_savfp;
E 4
	dread(&vframe, savfp, sizeof(vframe));
E 11
I 11
	savfp = (ADDRESS *) sframe.fr_savfp;
#ifdef tahoe
	savfp -= 2;
#endif
	dread(&sframe, savfp, sizeof(sframe));
E 11
D 4
	while (vframe.fr_savfp != (int) framep && vframe.fr_savfp != 0) {
		savfp = (ADDRESS *) vframe.fr_savfp;
		dread(&vframe, savfp, sizeof(vframe));
	}
	if (vframe.fr_savfp == 0) {
		panic("resume: can't find interpreter frame 0x%x", framep);
	}
	if (vframe.fr_mask == 0) {
		r = p->reg[11];
	} else {
		dread(&r, savfp + 5, sizeof(r));
		r -= sizeof(char);
	}
	return(r);
E 4
I 4
    }
D 11
    if (vframe.fr_savfp == 0) {
E 11
I 11
    if (sframe.fr_savfp == 0) {
E 11
	panic("resume: can't find interpreter frame 0x%x", framep);
    }
D 5
    if (vframe.fr_mask == 0) {
	r = p->reg[11];
    } else {
E 5
I 5
D 11
    if (regsaved(vframe, 11)) {
E 5
	dread(&r, savfp + 5, sizeof(r));
E 11
I 11
    if (regsaved(sframe, PCREG)) {
	dread(&r, savfp + PCREGLOC, sizeof(r));
E 11
	r -= sizeof(char);
    }
    return(r);
E 4
}
I 8

D 9
# endif
E 9
I 9
#endif
E 9
E 8

/*
 * Under the -r option, we offer the opportunity to just get
 * the px traceback and not actually enter the debugger.
I 6
 *
 * If the standard input is not a tty but standard error is,
 * change standard input to be /dev/tty.
E 6
 */

LOCAL choose()
{
D 4
	register int c;
E 4
I 4
    register int c;
E 4

I 6
D 7
    if (!isatty(fileno(stdin))) {
	if (!isatty(fileno(stderr)) || freopen("/dev/tty", "r", stdin) == NIL) {
E 7
I 7
    if (!isterm(stdin)) {
	if (!isterm(stderr) || freopen("/dev/tty", "r", stdin) == NIL) {
E 7
	    unsetsigtraces(process);
	    pcont(process);
	    quit(process->exitval);
	    /* NOTREACHED */
	}
    }
E 6
D 4
	fprintf(stderr, "\nProgram error");
	if (errnum != 0) {
		fprintf(stderr, " -- %s", pxerrmsg[errnum]);
	}
	fprintf(stderr, "\nDo you wish to enter the debugger? ");
E 4
I 4
    fprintf(stderr, "\nProgram error");
D 11
    if (errnum != 0) {
	fprintf(stderr, " -- %s", pxerrmsg[errnum]);
    }
E 11
    fprintf(stderr, "\nDo you wish to enter the debugger? ");
    c = getchar();
    if (c == 'n') {
	unsetsigtraces(process);
	pcont(process);
	quit(process->exitval);
    }
D 6
    while (c != '\n') {
E 6
I 6
    while (c != '\n' && c != EOF) {
E 6
E 4
	c = getchar();
D 4
	if (c == 'n') {
		unsetsigtraces(process);
		pcont(process);
D 3
		exit(0);
E 3
I 3
		quit(process->exitval);
E 3
	}
	while (c != '\n') {
		c = getchar();
	}
D 3
	fprintf(stderr, "\nEntering debugger, type 'help' for help\n");
E 3
I 3
	fprintf(stderr, "\nEntering debugger ...");
	init();
	option('r') = FALSE;
	fprintf(stderr, " type 'help' for help.\n");
E 4
I 4
    }
    fprintf(stderr, "\nEntering debugger ...");
    init();
    option('r') = FALSE;
    fprintf(stderr, " type 'help' for help.\n");
E 4
E 3
}
D 9

# endif
E 9
E 1
