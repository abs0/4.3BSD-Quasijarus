h04272
s 00005/00001/00038
d D 5.1 85/06/07 21:36:15 kre 6 5
c Add copyright
e
s 00006/00002/00033
d D 1.2 85/05/09 23:08:03 libs 5 1
c call f77_abort() instead of abort() to get consistent error handling
c and dumps only when wanted.
e
s 00007/00002/00033
d R 1.2 85/05/06 17:27:33 libs 4 1
c Change all calls to abort() to f77_abort() so get dumps only when wanted.
e
s 00006/00002/00033
d R 1.2 85/05/06 17:03:28 libs 3 1
c Change all calls to abort() to f77_abort() and have f77_abort() 
c call abort() for dump only when environment and load flags so specify.
e
s 00001/00001/00034
d R 1.2 85/05/06 14:13:39 libs 2 1
c Change all calls to abort() to f77_abort() and have f77_abort() 
c call abort() for dump only when environment and load flags so specify.
e
s 00035/00000/00000
d D 1.1 83/01/21 11:08:07 dlw 1 0
c date and time created 83/01/21 11:08:07 by dlw
e
u
U
t
T
I 1
/*
D 6
 *	"%W%"
E 6
I 6
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W%	%G%
E 6
 */

#include "complex"
I 5
#include <stdio.h>
#include <errno.h>
E 5

c_div(c, a, b)
complex *a, *b, *c;
{
double ratio, den;
double abr, abi;

if( (abr = b->real) < 0.)
	abr = - abr;
if( (abi = b->imag) < 0.)
	abi = - abi;
if( abr <= abi )
	{
D 5
	if(abi == 0)
		abort(); /* fatal("complex division by zero"); */
E 5
I 5
	if(abi == 0) {
		fprintf(stderr,"complex division by zero\n");
		f77_abort(EDOM);
	}
E 5
	ratio = b->real / b->imag ;
	den = b->imag * (1 + ratio*ratio);
	c->real = (a->real*ratio + a->imag) / den;
	c->imag = (a->imag*ratio - a->real) / den;
	}

else
	{
	ratio = b->imag / b->real ;
	den = b->real * (1 + ratio*ratio);
	c->real = (a->real + a->imag*ratio) / den;
	c->imag = (a->imag - a->real*ratio) / den;
	}

}
E 1
