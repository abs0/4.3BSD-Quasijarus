h07092
s 00011/00005/00073
d D 7.2 86/12/15 20:26:50 sam 2 1
c lint
e
s 00078/00000/00000
d D 7.1 86/11/20 12:22:05 sam 1 0
c date and time created 86/11/20 12:22:05 by sam
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
/*
 * Copyright (c) 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 2

#include "../kdb/defs.h"

char	*NOBKPT;
char	*SZBKPT;
char	*EXBKPT;
char	*BADMOD;

/* breakpoints */
BKPTR	bkpthead;

char	*lp;
char	lastc;
D 2

E 2
I 2
extern	char *kdbmalloc();
E 2
long	loopcnt;

/* sub process control */

subpcs(modif)
{
	register check, runmode;
	register BKPTR bkptr;
	register char *comptr;

	loopcnt=cntval;
	switch (modif) {

		/* delete breakpoint */
	case 'd': case 'D':
D 2
		if (bkptr=scanbkpt(dot)) {
E 2
I 2
		if (bkptr=scanbkpt((ADDR)dot)) {
E 2
			bkptr->flag=0;
			return;
		}
		error(NOBKPT);

		/* set breakpoint */
	case 'b': case 'B':
D 2
		if (bkptr=scanbkpt(dot))
E 2
I 2
		if (bkptr=scanbkpt((ADDR)dot))
E 2
			bkptr->flag=0;
		for (bkptr=bkpthead; bkptr; bkptr=bkptr->nxtbkpt)
			if (bkptr->flag == 0)
				break;
		if (bkptr==0) {
			bkptr=(BKPTR)kdbmalloc(sizeof *bkptr);
			if (bkptr == (BKPTR)-1)
				error(SZBKPT);
			bkptr->nxtbkpt=bkpthead;
			bkpthead=bkptr;
		}
		bkptr->loc = dot;
		bkptr->initcnt = bkptr->count = cntval;
		bkptr->flag = BKPTSET;
D 2
		check=MAXCOM-1; comptr=bkptr->comm; rdc(); lp--;
E 2
I 2
		check=MAXCOM-1; comptr=bkptr->comm; (void) rdc(); lp--;
E 2
		do
			*comptr++ = readchar();
		while (check-- && lastc!=EOR);
		*comptr=0; lp--;
		if (check)
			return;
		error(EXBKPT);

		/* single step */
	case 's': case 'S':
		runmode=SINGLE;
		break;

		/* continue */
	case 'c': case 'C':
		runmode=CONTIN;
		break;

	default:
		error(BADMOD);
	}
	if (loopcnt>0)
		runpcs(runmode, 0);
}
E 1
