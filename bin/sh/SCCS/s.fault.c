h10521
s 00003/00001/00115
d D 4.3 83/08/11 20:19:21 sam 3 2
c standardize sccs keyword lines
e
s 00006/00001/00110
d D 4.2 83/06/10 23:37:58 sam 2 1
c new signals make read's restarted, thus must setjmp/longjmp to get 
c prompt reprinted when an interrupt is hit while sitting at the prompt
e
s 00111/00000/00000
d D 4.1 82/05/07 19:37:37 mckusick 1 0
c date and time created 82/05/07 19:37:37 by mckusick
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
#ifndef lint
static char sccsid[] = "%W% %G%";
#endif
E 3

#
/*
 * UNIX shell
 *
 * S. R. Bourne
 * Bell Telephone Laboratories
 *
 */

#include	"defs.h"


STRING		trapcom[MAXTRAP];
BOOL		trapflg[MAXTRAP];
I 2
BOOL		trapjmp[MAXTRAP];
E 2

/* ========	fault handling routines	   ======== */


VOID	fault(sig)
	REG INT		sig;
{
	REG INT		flag;

D 2
	signal(sig,fault);
E 2
	IF sig==MEMF
	THEN	IF setbrk(brkincr) == -1
		THEN	error(nospace);
		FI
	ELIF sig==ALARM
	THEN	IF flags&waiting
		THEN	done();
		FI
	ELSE	flag = (trapcom[sig] ? TRAPSET : SIGSET);
		trapnote |= flag;
		trapflg[sig] |= flag;
I 2
	FI
	IF trapjmp[sig] ANDF sig==INTR
	THEN
		trapjmp[sig] = 0;
		longjmp(INTbuf, 1);
E 2
	FI
}

stdsigs()
{
	ignsig(QUIT);
	getsig(INTR);
	getsig(MEMF);
	getsig(ALARM);
}

ignsig(n)
{
	REG INT		s, i;

	IF (s=signal(i=n,1)&01)==0
	THEN	trapflg[i] |= SIGMOD;
	FI
	return(s);
}

getsig(n)
{
	REG INT		i;

	IF trapflg[i=n]&SIGMOD ORF ignsig(i)==0
	THEN	signal(i,fault);
	FI
}

oldsigs()
{
	REG INT		i;
	REG STRING	t;

	i=MAXTRAP;
	WHILE i--
	DO  t=trapcom[i];
	    IF t==0 ORF *t
	    THEN clrsig(i);
	    FI
	    trapflg[i]=0;
	OD
	trapnote=0;
}

clrsig(i)
	INT		i;
{
	free(trapcom[i]); trapcom[i]=0;
	IF trapflg[i]&SIGMOD
	THEN	signal(i,fault);
		trapflg[i] &= ~SIGMOD;
	FI
}

chktrap()
{
	/* check for traps */
	REG INT		i=MAXTRAP;
	REG STRING	t;

	trapnote &= ~TRAPSET;
	WHILE --i
	DO IF trapflg[i]&TRAPSET
	   THEN trapflg[i] &= ~TRAPSET;
		IF t=trapcom[i]
		THEN	INT	savxit=exitval;
			execexp(t,0);
			exitval=savxit; exitset();
		FI
	   FI
	OD
}
E 1
