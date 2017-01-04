h51927
s 00007/00001/00068
d D 4.3 84/05/05 21:50:55 mckusick 4 3
c fixes from Lou Salkind at NYU
e
s 00021/00022/00048
d D 4.2 83/07/31 23:02:16 sam 3 2
c update to run under 4.2bsd; reformat to my style (or a reasonable 
c facimile thereof); major hacking on signal handling for 4.2 signal interface
e
s 00000/00000/00070
d D 4.1 82/05/12 11:13:53 rrh 2 1
c sync to release 4.1
e
s 00070/00000/00000
d D 1.1 82/05/12 11:03:19 rrh 1 0
c date and time created 82/05/12 11:03:19 by rrh
e
u
U
t
T
I 4
#ifndef	lint
E 4
I 1
D 3
static char sccsid[] = "	%M%	%I%	%E%	";
E 3
I 3
static char sccsid[] = "%W%  %E%";
I 4
#endif
E 4
E 3

I 4
/* From Lou Salkind: compat/RCS/dosig.c,v 1.2 84/01/31 13:34:17 */

E 4
D 3
#define FBSD
/*	Handle signal trapping from version 6 or version 7 compatability
 *	mode programs.
E 3
I 3
/*
 * Handle signal trapping from version 6 or
 * version 7 compatability mode programs.
E 3
 *	Art Wetzel	November 1979
 */
I 3

E 3
#ifdef TRACE
#include <stdio.h>
#endif
#include <signal.h>
#include "defs.h"
I 3

I 4
int sigtrapped;
E 4
E 3
unsigned int  sigvals[NSIG+1];
I 3

E 3
/* actual catch point for all signals */
D 3
#ifdef FBSD
sigcatch(signum,faultcode,myaddr,stpc,stps) int signum;
#else
sigcatch(signum) int signum;
#endif
E 3
I 3
sigcatch(signum, faultcode, scp)
	int signum, faultcode;
	struct sigcontext *scp;
E 3
{
	unsigned short *pcptr;
	extern getregs();
	if(incompat) {
		/* hurry up and get the registers before they are destroyed */
		getregs();
	} else {
		/* we were in native mode simulating a sys call */
		/* set it up with the old values */
		dosig(signum, pc);
		/* go back where we were doing the sys call */
		return(0);
	}
	/* figure out the pc */
D 3
#ifdef FBSD
	pcptr = (unsigned short *) &stpc;
#else
	pcptr = (unsigned short *)((char *)&pcptr + 20);
#endif
E 3
I 3
	pcptr = (unsigned short *) &scp->sc_pc;
E 3
	pc = (unsigned short *) *pcptr;
	/* get the psl with condition codes */
D 3
	/* requires UNIX-32V patch to not clear out condition codes */
#ifdef FBSD
	psl = 0x83c00000 | (stps & 017);
#else
	psl = 0x83c00000 | (*(pcptr - 6) & 017);
#endif
E 3
I 3
	psl = 0x83c00000 | (scp->sc_ps & 017);
E 3
	/* actually do the thing */
D 3
	if(sigvals[signum] != (unsigned int)SIG_DFL && (sigvals[signum] & (unsigned int)SIG_IGN) == 0)
E 3
I 3
	if (sigvals[signum] != (unsigned int)SIG_DFL &&
	    (sigvals[signum] & (unsigned int)SIG_IGN) == 0)
E 3
		dosig(signum, pc);
	/* go back to compatability mode and the signal routine there */
I 3
	sigsetmask(scp->sc_mask);
E 3
	incompat++;
	compat();
}
I 3

E 3
/* routine to set up pdp11 space for return from a signal */
D 3
dosig(signum, from) {
E 3
I 3
dosig(signum, from)
	int signum, from;
{
E 3
	unsigned short *sp;
I 3

E 3
#ifdef TRACE
	fprintf(stderr,"Caught sig %d from 0%o -> 0%o\n",signum,(pc-1),*(pc-1));
#endif
I 4
	sigtrapped = 1;
E 4
	/* where is the stack */
	sp = (unsigned short *)regs[6];
	/* stack up psw condition codes so rti works */
	*(--sp) = psl & 017;
	/* stack pc */
	*(--sp) = (unsigned short)(int)pc;
	/* reset stack pointer */
	regs[6] = (unsigned short)(int)sp;
	/* reset pc to signal catching routine */
	pc = (unsigned short *)sigvals[signum];
I 3
D 4
	signal(signum, SIG_DFL);
E 4
I 4
/*	signal(signum, SIG_DFL); */
E 4
E 3
}
E 1
