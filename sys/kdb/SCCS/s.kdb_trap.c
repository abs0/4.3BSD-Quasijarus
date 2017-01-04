h56080
s 00011/00005/00086
d D 7.5 86/12/15 20:26:54 sam 5 4
c lint
e
s 00001/00001/00090
d D 7.4 86/11/23 13:36:07 sam 4 3
c move machine dependencies to ../machine/kdbparam.h
e
s 00010/00003/00081
d D 7.3 86/11/20 15:49:00 sam 3 2
c keep trap info around as well as current proc; move printing 
c of this stuff into machine-dependent routine
e
s 00001/00005/00083
d D 7.2 86/11/20 14:45:04 sam 2 1
c never get eof; use mnemonic for error reset
e
s 00088/00000/00000
d D 7.1 86/11/20 12:22:08 sam 1 0
c date and time created 86/11/20 12:22:08 by sam
e
u
U
t
T
I 1
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
/*
 * Copyright (c) 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 5

/*
 * Trap handler - command loop entry point.
 */
#include "../kdb/defs.h"

char	*NOEOR;

int	executing;
char	*lp;
D 2
long	maxpos;
E 2

char	lastc;
D 2
int	eof;
E 2

ADDR	userpc;
int	lastcom;

ADDR	maxoff = MAXOFF;
long	maxpos = MAXPOS;

D 3
kdb(type, sp, curproc)
	int type, *sp;
E 3
I 3
/*
 * Kdb trap handler; entered on all fatal
 * and/or debugger related traps or faults.
 */
kdb(type, code, curproc)
	int type, code;
E 3
	struct proc *curproc;
{

I 3
	var[varchk('t')] = type;
	var[varchk('c')] = code;
	var[varchk('p')] = (int)curproc;
D 5
	printtrap(type, code);
E 5
I 5
	printtrap((long)type, (long)code);
E 5
E 3
	userpc = dot = pcb.pcb_pc;
D 3
	var[varchk('t')] = (int)sp;
E 3
	switch (setexit()) {

	case SINGLE:
D 4
		pcb.pcb_psl |= TBIT;
E 4
I 4
		setsstep();		/* hardware single step */
E 4
		/* fall thru... */
	case CONTIN:
		return (1);
	case 0:
D 5
		if (nextpcs(type, 0))
E 5
I 5
		if (nextpcs(type))
E 5
			printf("breakpoint%16t");
		else
			printf("stopped at%16t");
		printpc();
		break;
	}
	if (executing)
		delbp();
	executing = 0;
	for (;;) {
		flushbuf();
		if (errflg) {
			printf("%s\n", errflg);
			errflg = 0;
		}
		if (mkfault) {
			mkfault=0;
			printc('\n');
			printf(DBNAME);
		}
		kdbwrite("kdb> ", 5);
D 5
		lp=0; rdc(); lp--;
D 2
		if (eof)
			return (1);
E 2
		command(0, lastcom);
E 5
I 5
		lp=0; (void) rdc(); lp--;
		(void) command((char *)0, lastcom);
E 5
		if (lp && lastc!='\n')
			error(NOEOR);
	}
}

/*
 * If there has been an error or a fault, take the error.
 */
chkerr()
{
	if (errflg || mkfault)
		error(errflg);
}

/*
 * An error occurred; save the message for
 * later printing, and reset to main command loop.
 */
error(n)
	char *n;
{

	errflg = n;
D 2
	reset(1);
E 2
I 2
	reset(ERROR);
E 2
}
E 1
