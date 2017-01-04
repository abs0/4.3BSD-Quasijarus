h36628
s 00003/00001/00084
d D 4.2 83/08/11 20:19:09 sam 2 1
c standardize sccs keyword lines
e
s 00085/00000/00000
d D 4.1 82/05/07 19:37:22 mckusick 1 0
c date and time created 82/05/07 19:37:22 by mckusick
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
#ifndef lint
static char sccsid[] = "%W% %G%";
#endif
E 2

#
/*
 * UNIX shell
 *
 * S. R. Bourne
 * Bell Telephone Laboratories
 *
 */

#include	"defs.h"


/* ========	error handling	======== */

exitset()
{
	assnum(&exitadr,exitval);
}

sigchk()
{
	/* Find out if it is time to go away.
	 * `trapnote' is set to SIGSET when fault is seen and
	 * no trap has been set.
	 */
	IF trapnote&SIGSET
	THEN	exitsh(SIGFAIL);
	FI
}

failed(s1,s2)
	STRING	s1, s2;
{
	prp(); prs(s1); 
	IF s2
	THEN	prs(colon); prs(s2);
	FI
	newline(); exitsh(ERROR);
}

error(s)
	STRING	s;
{
	failed(s,NIL);
}

exitsh(xno)
	INT	xno;
{
	/* Arrive here from `FATAL' errors
	 *  a) exit command,
	 *  b) default trap,
	 *  c) fault with no trap set.
	 *
	 * Action is to return to command level or exit.
	 */
	exitval=xno;
	IF (flags & (forked|errflg|ttyflg)) != ttyflg
	THEN	done();
	ELSE	clearup();
		longjmp(errshell,1);
	FI
}

done()
{
	REG STRING	t;
	IF t=trapcom[0]
	THEN	trapcom[0]=0; /*should free but not long */
		execexp(t,0);
	FI
	rmtemp(0);
	exit(exitval);
}

rmtemp(base)
	IOPTR		base;
{
	WHILE iotemp>base
	DO  unlink(iotemp->ioname);
	    iotemp=iotemp->iolst;
	OD
}
E 1
