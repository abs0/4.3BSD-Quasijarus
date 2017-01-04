h32234
s 00003/00001/00018
d D 4.2 83/08/11 20:20:19 sam 2 1
c standardize sccs keyword lines
e
s 00019/00000/00000
d D 4.1 82/05/07 19:39:00 mckusick 1 0
c date and time created 82/05/07 19:39:00 by mckusick
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
 *	UNIX shell
 *
 *	S. R. Bourne
 *	Bell Telephone Laboratories
 *
 */

#include	"defs.h"

setbrk(incr)
{
	REG BYTPTR	a=sbrk(incr);
	brkend=a+incr;
	return(a);
}
E 1
