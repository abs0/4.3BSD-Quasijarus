h43193
s 00002/00000/00554
d D 5.3 87/05/11 09:24:26 mckusick 8 7
c tahoe specific code (from Jim McKie)
e
s 00085/00067/00469
d D 5.2 87/04/07 15:55:16 mckusick 7 6
c port to tahoe by Nir peleg of CCI
e
s 00008/00003/00528
d D 5.1 85/06/06 11:40:04 dist 6 5
c Add copyright
e
s 00044/00005/00487
d D 1.5 83/02/08 18:06:27 linton 5 4
c modifications for running of a sun
e
s 00001/00001/00491
d D 1.4 82/12/29 10:11:23 sam 4 3
c reg.h moved
e
s 00260/00245/00232
d D 1.3 82/03/08 18:54:28 linton 3 2
c put in cache initialization in at beginning of process startup 
c ("initstart") ... the cache was non-empty after a "pi" which meant 
c instruction reads were getting the wrong values
e
s 00003/00005/00474
d D 1.2 82/01/23 17:04:11 linton 2 1
c removed error message, it's handled elsewhere now
e
s 00479/00000/00000
d D 1.1 82/01/18 19:20:49 linton 1 0
c date and time created 82/01/18 19:20:49 by linton
e
u
U
t
T
I 6
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 6
I 5

E 5
I 1
D 6
/* Copyright (c) 1982 Regents of the University of California */

D 5
static char sccsid[] = "%Z%%M% %I% %G%";
E 5
I 5
static char sccsid[] = "@(#)ptrace.c 1.4 12/29/82";
E 6
I 6
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 6
E 5

/*
 * routines for tracing the execution of a process
 *
 * The system call "ptrace" does all the work, these
 * routines just try to interface easily to it.
 */

#include "defs.h"
#include <signal.h>
#include <sys/param.h>
D 4
#include <sys/reg.h>
E 4
I 4
#include <machine/reg.h>
E 4
#include "process.h"
#include "object.h"
#include "process.rep"

D 3
#	if (isvaxpx)
#		include "pxinfo.h"
#	endif
E 3
I 3
D 7
#   if (isvaxpx)
E 7
#       include "pxinfo.h"
D 7
#   endif
E 7
E 3

I 5
D 7
#ifndef vax
E 7
I 7
#ifdef mc68000
E 7
#	define U_PAGE 0x2400
#	define U_AR0  (14*sizeof(int))
	LOCAL int ar0val = -1;
#endif

E 5
/*
 * This magic macro enables us to look at the process' registers
 * in its user structure.  Very gross.
 */

D 3
#define regloc(reg)		(ctob(UPAGES) + ( sizeof(int) * (reg) ))
E 3
I 3
D 5
#define regloc(reg)     (ctob(UPAGES) + ( sizeof(int) * (reg) ))
E 5
I 5
D 7
#ifdef vax
E 7
I 7
#if defined(vax) || defined(tahoe)
E 7
#	define regloc(reg)     (ctob(UPAGES) + ( sizeof(int) * (reg) ))
#else
#	define regloc(reg)     (ar0val + ( sizeof(int) * (reg) ))
#endif
E 5
E 3

D 3
#define WMASK			(~(sizeof(WORD) - 1))
#define cachehash(addr)	((unsigned) ((addr >> 2) % CSIZE))
E 3
I 3
#define WMASK           (~(sizeof(WORD) - 1))
#define cachehash(addr) ((unsigned) ((addr >> 2) % CSIZE))
E 3

D 3
#define FIRSTSIG		SIGINT
#define LASTSIG			SIGQUIT
#define ischild(pid)	((pid) == 0)
#define traceme()		ptrace(0, 0, 0, 0)
#define setrep(n)		(1 << ((n)-1))
#define istraced(p)		(p->sigset&setrep(p->signo))
E 3
I 3
D 7
#define FIRSTSIG        SIGINT
#define LASTSIG         SIGQUIT
E 7
#define ischild(pid)    ((pid) == 0)
#define traceme()       ptrace(0, 0, 0, 0)
#define setrep(n)       (1 << ((n)-1))
#define istraced(p)     (p->sigset&setrep(p->signo))
E 3

/*
 * ptrace options (specified in first argument)
 */

D 3
#define UREAD	3		/* read from process's user structure */
#define UWRITE	6		/* write to process's user structure */
#define IREAD	1		/* read from process's instruction space */
#define IWRITE	4		/* write to process's instruction space */
#define DREAD	2		/* read from process's data space */
#define DWRITE	5		/* write to process's data space */
#define CONT	7		/* continue stopped process */
#define SSTEP	9		/* continue for approximately one instruction */
#define PKILL	8		/* terminate the process */
E 3
I 3
#define UREAD   3       /* read from process's user structure */
#define UWRITE  6       /* write to process's user structure */
#define IREAD   1       /* read from process's instruction space */
#define IWRITE  4       /* write to process's instruction space */
#define DREAD   2       /* read from process's data space */
#define DWRITE  5       /* write to process's data space */
#define CONT    7       /* continue stopped process */
#define SSTEP   9       /* continue for approximately one instruction */
#define PKILL   8       /* terminate the process */
E 3

/*
 * Start up a new process by forking and exec-ing the
 * given argument list, returning when the process is loaded
 * and ready to execute.  The PROCESS information (pointed to
 * by the first argument) is appropriately filled.
 *
 * If the given PROCESS structure is associated with an already running
 * process, we terminate it.
 */

/* VARARGS2 */
D 2
pstart(p, argv, infile, outfile)
E 2
I 2
pstart(p, cmd, argv, infile, outfile)
E 2
PROCESS *p;
I 2
char *cmd;
E 2
char **argv;
char *infile;
char *outfile;
{
D 3
	int status;
	FILE *in, *out;
E 3
I 3
    int status;
    FILE *in, *out;
E 3

D 3
	if (p->pid != 0) {					/* child already running? */
		ptrace(PKILL, p->pid, 0, 0);	/* ... kill it! */
E 3
I 3
    if (p->pid != 0) {                  /* child already running? */
	ptrace(PKILL, p->pid, 0, 0);    /* ... kill it! */
    }
I 8
#ifdef tahoe
E 8
I 7
    INTFP = (ADDRESS)0;
I 8
#endif tahoe
E 8
E 7
    psigtrace(p, SIGTRAP, TRUE);
    if ((p->pid = fork()) == -1) {
	panic("can't fork");
    }
    if (ischild(p->pid)) {
	traceme();
	if (infile != NIL) {
	    if ((in = fopen(infile, "r")) == NIL) {
		printf("can't read %s\n", infile);
		exit(1);
	    }
	    fswap(0, fileno(in));
E 3
	}
D 3
	psigtrace(p, SIGTRAP, TRUE);
	if ((p->pid = fork()) == -1) {
		panic("can't fork");
E 3
I 3
	if (outfile != NIL) {
	    if ((out = fopen(outfile, "w")) == NIL) {
		printf("can't write %s\n", outfile);
		exit(1);
	    }
	    fswap(1, fileno(out));
E 3
	}
D 3
	if (ischild(p->pid)) {
		traceme();
		if (infile != NIL) {
			if ((in = fopen(infile, "r")) == NIL) {
				printf("can't read %s\n", infile);
				exit(1);
			}
			fswap(0, fileno(in));
		}
		if (outfile != NIL) {
			if ((out = fopen(outfile, "w")) == NIL) {
				printf("can't write %s\n", outfile);
				exit(1);
			}
			fswap(1, fileno(out));
		}
D 2
		execvp(argv[0], argv);
E 2
I 2
		execvp(cmd, argv);
E 2
		panic("can't exec %s", argv[0]);
	}
	pwait(p->pid, &status);
	getinfo(p, status);
E 3
I 3
	execvp(cmd, argv);
	panic("can't exec %s", argv[0]);
    }
    pwait(p->pid, &status);
    getinfo(p, status);
E 3
D 2
	if (p->status != STOPPED) {
		error("program could not begin execution");
	}
E 2
}

/*
 * Continue a stopped process.  The argument points to a PROCESS structure.
 * Before the process is restarted it's user area is modified according to
 * the values in the structure.  When this routine finishes,
 * the structure has the new values from the process's user area.
 *
 * Pcont terminates when the process stops with a signal pending that
 * is being traced (via psigtrace), or when the process terminates.
 */

pcont(p)
PROCESS *p;
{
D 3
	int status;
E 3
I 3
    int status;
E 3

D 3
	if (p->pid == 0) {
		error("program not active");
E 3
I 3
    if (p->pid == 0) {
	error("program not active");
    }
    do {
	setinfo(p);
	sigs_off();
	if (ptrace(CONT, p->pid, p->pc, p->signo) < 0) {
	    panic("can't continue process");
E 3
	}
D 3
	do {
		setinfo(p);
		sigs_off();
		if (ptrace(CONT, p->pid, p->pc, p->signo) < 0) {
			panic("can't continue process");
		}
		pwait(p->pid, &status);
		sigs_on();
		getinfo(p, status);
	} while (p->status == STOPPED && !istraced(p));
E 3
I 3
	pwait(p->pid, &status);
	sigs_on();
	getinfo(p, status);
    } while (p->status == STOPPED && !istraced(p));
E 3
}

/*
 * single step as best ptrace can
 */

pstep(p)
PROCESS *p;
{
D 3
	int status;
E 3
I 3
    int status;
E 3

D 3
	setinfo(p);
	sigs_off();
	ptrace(SSTEP, p->pid, p->pc, p->signo);
	pwait(p->pid, &status);
	sigs_on();
	getinfo(p, status);
E 3
I 3
    setinfo(p);
    sigs_off();
    ptrace(SSTEP, p->pid, p->pc, p->signo);
    pwait(p->pid, &status);
    sigs_on();
    getinfo(p, status);
E 3
}

/*
 * Return from execution when the given signal is pending.
 */

psigtrace(p, sig, sw)
PROCESS *p;
int sig;
int sw;
{
D 3
	if (sw) {
		p->sigset |= setrep(sig);
	} else {
		p->sigset &= ~setrep(sig);
	}
E 3
I 3
    if (sw) {
	p->sigset |= setrep(sig);
    } else {
	p->sigset &= ~setrep(sig);
    }
E 3
}

/*
 * Don't catch any signals.
 * Particularly useful when letting a process finish uninhibited (i.e. px).
 */

unsetsigtraces(p)
PROCESS *p;
{
D 3
	p->sigset = 0;
E 3
I 3
    p->sigset = 0;
E 3
}

/*
 * turn off attention to signals not being caught
 */

typedef int INTFUNC();

D 7
LOCAL INTFUNC *sigfunc[NSIG];
E 7
I 7
LOCAL INTFUNC *onintr, *onquit;
E 7

LOCAL sigs_off()
{
D 3
	register int i;
E 3
I 3
D 7
    register int i;
E 3

D 3
	for (i = FIRSTSIG; i < LASTSIG; i++) {
		if (i != SIGKILL) {
			sigfunc[i] = signal(i, SIG_IGN);
		}
E 3
I 3
    for (i = FIRSTSIG; i < LASTSIG; i++) {
	if (i != SIGKILL) {
	    sigfunc[i] = signal(i, SIG_IGN);
E 3
	}
I 3
    }
E 7
I 7
    onintr = signal(SIGINT, SIG_IGN);
    onquit = signal(SIGQUIT, SIG_IGN);
E 7
E 3
}

/*
 * turn back on attention to signals
 */

LOCAL sigs_on()
{
D 3
	register int i;
E 3
I 3
D 7
    register int i;
E 3

D 3
	for (i = FIRSTSIG; i < LASTSIG; i++) {
		if (i != SIGKILL) {
			signal(i, sigfunc[i]);
		}
E 3
I 3
    for (i = FIRSTSIG; i < LASTSIG; i++) {
	if (i != SIGKILL) {
	    signal(i, sigfunc[i]);
E 3
	}
I 3
    }
E 7
I 7
    (void) signal(SIGINT, onintr);
    (void) signal(SIGQUIT, onquit);
E 7
E 3
}

/*
 * get PROCESS information from process's user area
 */

D 5
LOCAL int rloc[] ={
D 3
	R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11,
E 3
I 3
    R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11,
E 3
};
E 5
I 5
#if vax
    LOCAL int rloc[] ={
	R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11,
    };
D 7
#else
E 7
I 7
#endif
#if tahoe
E 7
    LOCAL int rloc[] ={
I 7
	R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12,
    };
#endif
#if mc68000
    LOCAL int rloc[] ={
E 7
	R0, R1, R2, R3, R4, R5, R6, R7, AR0, AR1, AR2, AR3, AR4, AR5,
    };
#endif
E 5

LOCAL getinfo(p, status)
register PROCESS *p;
register int status;
{
D 3
	register int i;
E 3
I 3
    register int i;
E 3

D 3
	p->signo = (status&0177);
	p->exitval = ((status >> 8)&0377);
	if (p->signo == STOPPED) {
		p->status = p->signo;
		p->signo = p->exitval;
		p->exitval = 0;
	} else {
		p->status = FINISHED;
		return;
	}
	for (i = 0; i < NREG; i++) {
		p->reg[i] = ptrace(UREAD, p->pid, regloc(rloc[i]), 0);
		p->oreg[i] = p->reg[i];
	}
	p->fp = p->ofp = ptrace(UREAD, p->pid, regloc(FP), 0);
	p->ap = p->oap = ptrace(UREAD, p->pid, regloc(AP), 0);
	p->sp = p->osp = ptrace(UREAD, p->pid, regloc(SP), 0);
	p->pc = p->opc = ptrace(UREAD, p->pid, regloc(PC), 0);
E 3
I 3
    p->signo = (status&0177);
    p->exitval = ((status >> 8)&0377);
    if (p->signo == STOPPED) {
	p->status = p->signo;
	p->signo = p->exitval;
	p->exitval = 0;
    } else {
	p->status = FINISHED;
	return;
    }
I 5
D 7
#ifndef vax
E 7
I 7
#if !defined(vax) && !defined(tahoe)
E 7
    if (ar0val < 0){
	ar0val = ptrace(UREAD, p->pid, U_AR0, 0);
	ar0val -= U_PAGE;
    }
#endif
E 5
    for (i = 0; i < NREG; i++) {
	p->reg[i] = ptrace(UREAD, p->pid, regloc(rloc[i]), 0);
	p->oreg[i] = p->reg[i];
    }
I 5
D 7
#ifdef vax
E 7
I 7
#if defined(vax) || defined(tahoe)
E 7
E 5
    p->fp = p->ofp = ptrace(UREAD, p->pid, regloc(FP), 0);
D 7
    p->ap = p->oap = ptrace(UREAD, p->pid, regloc(AP), 0);
E 7
    p->sp = p->osp = ptrace(UREAD, p->pid, regloc(SP), 0);
    p->pc = p->opc = ptrace(UREAD, p->pid, regloc(PC), 0);
I 5
D 7
#else
E 7
I 7
#endif
#ifdef vax
    p->ap = p->oap = ptrace(UREAD, p->pid, regloc(AP), 0);
#endif
#ifdef mc68000
E 7
    p->fp = p->ofp = ptrace(UREAD, p->pid, regloc(AR6), 0);
    p->ap = p->oap = p->fp;
    p->sp = p->osp = ptrace(UREAD, p->pid, regloc(SP), 0);
    p->pc = p->opc = ptrace(UREAD, p->pid, regloc(PC), 0);
#endif
E 5
E 3
}

/*
 * set process's user area information from given PROCESS structure
 */

LOCAL setinfo(p)
register PROCESS *p;
{
D 3
	register int i;
	register int r;
E 3
I 3
    register int i;
    register int r;
E 3

D 3
	if (istraced(p)) {
		p->signo = 0;
E 3
I 3
    if (istraced(p)) {
	p->signo = 0;
    }
    for (i = 0; i < NREG; i++) {
	if ((r = p->reg[i]) != p->oreg[i]) {
	    ptrace(UWRITE, p->pid, regloc(rloc[i]), r);
E 3
	}
D 3
	for (i = 0; i < NREG; i++) {
		if ((r = p->reg[i]) != p->oreg[i]) {
			ptrace(UWRITE, p->pid, regloc(rloc[i]), r);
		}
	}
	if ((r = p->fp) != p->ofp) {
		ptrace(UWRITE, p->pid, regloc(FP), r);
	}
	if ((r = p->sp) != p->osp) {
		ptrace(UWRITE, p->pid, regloc(SP), r);
	}
	if ((r = p->ap) != p->oap) {
		ptrace(UWRITE, p->pid, regloc(AP), r);
	}
	if ((r = p->pc) != p->opc) {
		ptrace(UWRITE, p->pid, regloc(PC), r);
	}
E 3
I 3
    }
I 5
D 7
#if vax
E 7
I 7
#if vax || tahoe
E 7
E 5
    if ((r = p->fp) != p->ofp) {
	ptrace(UWRITE, p->pid, regloc(FP), r);
    }
D 7
    if ((r = p->sp) != p->osp) {
	ptrace(UWRITE, p->pid, regloc(SP), r);
    }
E 7
I 7
#endif
#if vax
E 7
    if ((r = p->ap) != p->oap) {
	ptrace(UWRITE, p->pid, regloc(AP), r);
    }
I 5
D 7
#else
E 7
I 7
#endif
#if mc68000
E 7
    if ((r = p->fp) != p->ofp) {
	ptrace(UWRITE, p->pid, regloc(AR6), r);
    }
I 7
#endif
E 7
    if ((r = p->sp) != p->osp) {
	ptrace(UWRITE, p->pid, regloc(SP), r);
    }
D 7
#endif
E 7
E 5
    if ((r = p->pc) != p->opc) {
	ptrace(UWRITE, p->pid, regloc(PC), r);
    }
E 3
}

/*
 * Structure for reading and writing by words, but dealing with bytes.
 */

typedef union {
D 3
	WORD pword;
	BYTE pbyte[sizeof(WORD)];
E 3
I 3
    WORD pword;
    BYTE pbyte[sizeof(WORD)];
E 3
} PWORD;

/*
 * Read (write) from (to) the process' address space.
 * We must deal with ptrace's inability to look anywhere other
 * than at a word boundary.
 */

LOCAL WORD fetch();
LOCAL store();

pio(p, op, seg, buff, addr, nbytes)
PROCESS *p;
PIO_OP op;
PIO_SEG seg;
char *buff;
ADDRESS addr;
int nbytes;
{
D 3
	register int i;
	register ADDRESS newaddr;
	register char *cp;
	char *bufend;
	PWORD w;
	ADDRESS wordaddr;
	int byteoff;
E 3
I 3
D 7
    register int i;
E 7
I 7
    register int i, k;
E 7
    register ADDRESS newaddr;
    register char *cp;
    char *bufend;
    PWORD w;
    ADDRESS wordaddr;
    int byteoff;
E 3

D 3
	if (p->status != STOPPED) {
		error("program is not active");
E 3
I 3
    if (p->status != STOPPED) {
	error("program is not active");
    }
    cp = buff;
    newaddr = addr;
    wordaddr = (newaddr&WMASK);
    if (wordaddr != newaddr) {
	w.pword = fetch(p, seg, wordaddr);
	for (i = newaddr - wordaddr; i<sizeof(WORD) && nbytes>0; i++) {
	    if (op == PREAD) {
		*cp++ = w.pbyte[i];
	    } else {
		w.pbyte[i] = *cp++;
	    }
	    nbytes--;
E 3
	}
D 3
	cp = buff;
	newaddr = addr;
	wordaddr = (newaddr&WMASK);
	if (wordaddr != newaddr) {
		w.pword = fetch(p, seg, wordaddr);
		for (i = newaddr - wordaddr; i<sizeof(WORD) && nbytes>0; i++) {
			if (op == PREAD) {
				*cp++ = w.pbyte[i];
			} else {
				w.pbyte[i] = *cp++;
			}
			nbytes--;
		}
		if (op == PWRITE) {
			store(p, seg, wordaddr, w.pword);
		}
		newaddr = wordaddr + sizeof(WORD);
E 3
I 3
	if (op == PWRITE) {
	    store(p, seg, wordaddr, w.pword);
E 3
	}
D 3
	byteoff = (nbytes&(~WMASK));
	nbytes -= byteoff;
	bufend = cp + nbytes;
	while (cp < bufend) {
		if (op == PREAD) {
			*((WORD *) cp) = fetch(p, seg, newaddr);
		} else {
			store(p, seg, newaddr, *((WORD *) cp));
		}
		cp += sizeof(WORD);
		newaddr += sizeof(WORD);
E 3
I 3
	newaddr = wordaddr + sizeof(WORD);
    }
    byteoff = (nbytes&(~WMASK));
    nbytes -= byteoff;
    bufend = cp + nbytes;
    while (cp < bufend) {
	if (op == PREAD) {
D 7
	    *((WORD *) cp) = fetch(p, seg, newaddr);
E 7
I 7
	    w.pword = fetch(p, seg, newaddr);
	    for (k = 0; k < sizeof(WORD); k++) {
		*cp++ = w.pbyte[k];
	    }
E 7
	} else {
D 7
	    store(p, seg, newaddr, *((WORD *) cp));
E 7
I 7
	    for (k = 0; k < sizeof(WORD); k++) {
		w.pbyte[k] = *cp++;
	    }
	    store(p, seg, newaddr, w.pword);
E 7
E 3
	}
D 3
	if (byteoff > 0) {
		w.pword = fetch(p, seg, newaddr);
		for (i = 0; i < byteoff; i++) {
			if (op == PREAD) {
				*cp++ = w.pbyte[i];
			} else {
				w.pbyte[i] = *cp++;
			}
		}
		if (op == PWRITE) {
			store(p, seg, newaddr, w.pword);
		}
E 3
I 3
D 7
	cp += sizeof(WORD);
E 7
	newaddr += sizeof(WORD);
    }
    if (byteoff > 0) {
	w.pword = fetch(p, seg, newaddr);
	for (i = 0; i < byteoff; i++) {
	    if (op == PREAD) {
		*cp++ = w.pbyte[i];
	    } else {
		w.pbyte[i] = *cp++;
	    }
E 3
	}
I 3
	if (op == PWRITE) {
	    store(p, seg, newaddr, w.pword);
	}
    }
E 3
}

/*
 * Get a word from a process at the given address.
 * The address is assumed to be on a word boundary.
 *
 * We use a simple cache scheme to avoid redundant references to
 * the instruction space (which is assumed to be pure).  In the
 * case of px, the "instruction" space lies between ENDOFF and
 * ENDOFF + objsize.
 *
 * It is necessary to use a write-through scheme so that
 * breakpoints right next to each other don't interfere.
 */

LOCAL WORD fetch(p, seg, addr)
PROCESS *p;
PIO_SEG seg;
register int addr;
{
D 3
	register CACHEWORD *wp;
	register WORD w;
E 3
I 3
    register CACHEWORD *wp;
    register WORD w;
E 3

D 3
	switch (seg) {
		case TEXTSEG:
#			if (isvaxpx)
				panic("tried to fetch from px i-space");
				/* NOTREACHED */
#			else
				wp = &p->word[cachehash(addr)];
				if (addr == 0 || wp->addr != addr) {
					w = ptrace(IREAD, p->pid, addr, 0);
					wp->addr = addr;
					wp->val = w;
				} else {
					w = wp->val;
				}
				break;
#			endif
E 3
I 3
    switch (seg) {
	case TEXTSEG:
D 7
#           if (isvaxpx)
		panic("tried to fetch from px i-space");
		/* NOTREACHED */
#           else
E 7
I 7
	    panic("tried to fetch from px i-space");
	    /* NOTREACHED */

	case DATASEG:
	    if (addr >= ENDOFF && addr < ENDOFF + objsize) {
E 7
		wp = &p->word[cachehash(addr)];
		if (addr == 0 || wp->addr != addr) {
D 7
		    w = ptrace(IREAD, p->pid, addr, 0);
E 7
I 7
		    w = ptrace(DREAD, p->pid, addr, 0);
E 7
		    wp->addr = addr;
		    wp->val = w;
		} else {
		    w = wp->val;
		}
D 7
		break;
#           endif
E 3

D 3
		case DATASEG:
#			if (isvaxpx)
				if (addr >= ENDOFF && addr < ENDOFF + objsize) {
					wp = &p->word[cachehash(addr)];
					if (addr == 0 || wp->addr != addr) {
						w = ptrace(DREAD, p->pid, addr, 0);
						wp->addr = addr;
						wp->val = w;
					} else {
						w = wp->val;
					}
				} else {
					w = ptrace(DREAD, p->pid, addr, 0);
				}
#			else
				w = ptrace(DREAD, p->pid, addr, 0);
#			endif
			break;
E 3
I 3
	case DATASEG:
#           if (isvaxpx)
		if (addr >= ENDOFF && addr < ENDOFF + objsize) {
		    wp = &p->word[cachehash(addr)];
		    if (addr == 0 || wp->addr != addr) {
			w = ptrace(DREAD, p->pid, addr, 0);
			wp->addr = addr;
			wp->val = w;
		    } else {
			w = wp->val;
		    }
		} else {
		    w = ptrace(DREAD, p->pid, addr, 0);
		}
#           else
E 7
I 7
	    } else {
E 7
		w = ptrace(DREAD, p->pid, addr, 0);
D 7
#           endif
E 7
I 7
	    }
E 7
	    break;
E 3

D 3
		default:
			panic("fetch: bad seg %d", seg);
			/* NOTREACHED */
	}
	return(w);
E 3
I 3
	default:
	    panic("fetch: bad seg %d", seg);
	    /* NOTREACHED */
    }
    return(w);
E 3
}

/*
 * Put a word into the process' address space at the given address.
 * The address is assumed to be on a word boundary.
 */

LOCAL store(p, seg, addr, data)
PROCESS *p;
PIO_SEG seg;
int addr;
WORD data;
{
D 3
	register CACHEWORD *wp;
E 3
I 3
    register CACHEWORD *wp;
E 3

D 3
	switch (seg) {
		case TEXTSEG:
			wp = &p->word[cachehash(addr)];
			wp->addr = addr;
			wp->val = data;
			ptrace(IWRITE, p->pid, addr, data);
			break;
E 3
I 3
    switch (seg) {
	case TEXTSEG:
	    wp = &p->word[cachehash(addr)];
	    wp->addr = addr;
	    wp->val = data;
	    ptrace(IWRITE, p->pid, addr, data);
	    break;
E 3

D 3
		case DATASEG:
#			if (isvaxpx)
				if (addr >= ENDOFF && addr < ENDOFF + objsize) {
					wp = &p->word[cachehash(addr)];
					wp->addr = addr;
					wp->val = data;
				}
#			endif
			ptrace(DWRITE, p->pid, addr, data);
			break;
E 3
I 3
	case DATASEG:
D 7
#           if (isvaxpx)
		if (addr >= ENDOFF && addr < ENDOFF + objsize) {
		    wp = &p->word[cachehash(addr)];
		    wp->addr = addr;
		    wp->val = data;
		}
#           endif
E 7
I 7
	    if (addr >= ENDOFF && addr < ENDOFF + objsize) {
		wp = &p->word[cachehash(addr)];
		wp->addr = addr;
		wp->val = data;
	    }
E 7
	    ptrace(DWRITE, p->pid, addr, data);
	    break;
E 3

D 3
		default:
			panic("store: bad seg %d", seg);
			/*NOTREACHED*/
	}
E 3
I 3
	default:
	    panic("store: bad seg %d", seg);
	    /*NOTREACHED*/
    }
E 3
}

/*
I 3
 * Initialize the instruction cache for a process.
 * This is particularly necessary after the program has been remade.
 */

initcache(process)
PROCESS *process;
{
    register int i;

    for (i = 0; i < CSIZE; i++) {
	process->word[i].addr = 0;
    }
}

/*
E 3
 * Swap file numbers so as to redirect standard input and output.
 */

LOCAL fswap(oldfd, newfd)
int oldfd;
int newfd;
{
D 3
	if (oldfd != newfd) {
		close(oldfd);
		dup(newfd);
		close(newfd);
	}
E 3
I 3
    if (oldfd != newfd) {
	close(oldfd);
	dup(newfd);
	close(newfd);
    }
E 3
}
I 7

#ifdef tahoe
BOOLEAN didret;

void
chkret(p, status)
PROCESS *p;
int status;
{
	if (((status == (SIGILL << 8) | STOPPED) ||
	    (status == (SIGTRAP << 8) | STOPPED))) {
		didret = FALSE;
	} else {
		didret = TRUE;
	}
}

void
doret(p)
PROCESS *p;
{
	register count = 0;

	if (!didret) {
	    do {
		if (++count > 5) {
		    panic("px would not return to interpreter");
		}
		p->pc = RETLOC;
		pstep(p);
	    } while(INTFP && p->fp != INTFP);
	    didret = TRUE;
	}
}
#endif
E 7
E 1
