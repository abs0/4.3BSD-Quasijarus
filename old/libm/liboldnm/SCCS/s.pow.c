h04367
s 00010/00000/00037
d D 5.1 85/05/08 12:37:09 dist 2 1
c Create SCCS file, add copyright
e
s 00037/00000/00000
d D 1.1 85/05/08 12:21:54 dist 1 0
c date and time created 85/05/08 12:21:54 by dist
e
u
U
t
T
I 1
/*
I 2
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

/*
E 2
	computes a^b.
	uses log and exp
*/

#include	<errno.h>
int errno;
double log(), exp();

double
pow(arg1,arg2)
double arg1, arg2;
{
	double temp;
	long l;

	asm("	bispsw	$0xe0");
	if(arg1 <= 0.) {
		if(arg1 == 0.) {
			if(arg2 <= 0.)
				goto domain;
			return(0.);
		}
		l = arg2;
		if(l != arg2)
			goto domain;
		temp = exp(arg2 * log(-arg1));
		if(l & 1)
			temp = -temp;
		return(temp);
	}
	return(exp(arg2 * log(arg1)));

domain:
	errno = EDOM;
	return(0.);
}
E 1
