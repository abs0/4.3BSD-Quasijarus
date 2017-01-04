h29350
s 00010/00000/00043
d D 5.2 86/11/03 21:25:47 mckusick 7 6
c update for tahoe
e
s 00005/00001/00038
d D 5.1 85/06/07 22:54:18 kre 6 5
c Add copyright
e
s 00006/00002/00033
d D 1.2 85/05/09 23:08:13 libs 5 1
c call f77_abort() instead of abort() to get consistent error handling
c and dumps only when wanted.
e
s 00007/00002/00033
d R 1.2 85/05/06 17:27:40 libs 4 1
c Change all calls to abort() to f77_abort() so get dumps only when wanted.
e
s 00006/00002/00033
d R 1.2 85/05/06 17:03:44 libs 3 1
c Change all calls to abort() to f77_abort() and have f77_abort() 
c call abort() for dump only when environment and load flags so specify.
e
s 00001/00001/00034
d R 1.2 85/05/06 14:13:54 libs 2 1
c Change all calls to abort() to f77_abort() and have f77_abort() 
c call abort() for dump only when environment and load flags so specify.
e
s 00035/00000/00000
d D 1.1 83/01/21 11:20:10 dlw 1 0
c date and time created 83/01/21 11:20:10 by dlw
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
I 7
#ifdef tahoe
#include <tahoemath/FP.h>
#endif tahoe
E 7
E 5

z_div(c, a, b)
dcomplex *a, *b, *c;
{
double ratio, den;
double abr, abi;

I 7
#ifndef tahoe
E 7
if( (abr = b->dreal) < 0.)
	abr = - abr;
if( (abi = b->dimag) < 0.)
	abi = - abi;
I 7
#else tahoe
if( (abr = b->dreal) < 0.)
	*((long int *)&abr) ^= SIGN_BIT;
if( (abi = b->dimag) < 0.)
	*((long int *)&abi) ^= SIGN_BIT;
#endif tahoe
E 7
if( abr <= abi )
	{
D 5
	if(abi == 0)
		abort(); /* fatal("complex division by zero"); */
E 5
I 5
	if(abi == 0) {
		fprintf( stderr, "Double complex division by zero\n" );
		f77_abort(EDOM);
	}
E 5
	ratio = b->dreal / b->dimag ;
	den = b->dimag * (1 + ratio*ratio);
	c->dreal = (a->dreal*ratio + a->dimag) / den;
	c->dimag = (a->dimag*ratio - a->dreal) / den;
	}

else
	{
	ratio = b->dimag / b->dreal ;
	den = b->dreal * (1 + ratio*ratio);
	c->dreal = (a->dreal + a->dimag*ratio) / den;
	c->dimag = (a->dimag - a->dreal*ratio) / den;
	}

}
E 1
