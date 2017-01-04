h58115
s 00003/00001/00056
d D 4.2 83/08/11 20:20:27 sam 2 1
c standardize sccs keyword lines
e
s 00057/00000/00000
d D 4.1 82/05/07 19:39:22 mckusick 1 0
c date and time created 82/05/07 19:39:22 by mckusick
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


/* ========	general purpose string handling ======== */


STRING	movstr(a,b)
	REG STRING	a, b;
{
	WHILE *b++ = *a++ DONE
	return(--b);
}

INT	any(c,s)
	REG CHAR	c;
	STRING		s;
{
	REG CHAR d;

	WHILE d = *s++
	DO	IF d==c
		THEN	return(TRUE);
		FI
	OD
	return(FALSE);
}

INT	cf(s1, s2)
	REG STRING s1, s2;
{
	WHILE *s1++ == *s2
	DO	IF *s2++==0
		THEN	return(0);
		FI
	OD
	return(*--s1 - *s2);
}

INT	length(as)
	STRING as;
{
	REG STRING s;

	IF s=as THEN WHILE *s++ DONE FI
	return(s-as);
}
E 1
