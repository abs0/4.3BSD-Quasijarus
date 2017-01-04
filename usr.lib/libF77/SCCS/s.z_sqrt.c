h11426
s 00008/00000/00030
d D 5.2 86/11/03 21:28:37 mckusick 3 2
c update for tahoe
e
s 00005/00001/00025
d D 5.1 85/06/07 22:56:20 kre 2 1
c Add copyright
e
s 00026/00000/00000
d D 1.1 83/01/21 11:21:04 dlw 1 0
c date and time created 83/01/21 11:21:04 by dlw
e
u
U
t
T
I 1
/*
D 2
 *	"%W%"
E 2
I 2
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W%	%G%
E 2
 */

#include "complex"
I 3
#ifdef tahoe
#include <tahoemath/FP.h>
#define cabs zabs
#endif tahoe
E 3

z_sqrt(r, z)
dcomplex *r, *z;
{
double mag, sqrt(), cabs();

if( (mag = cabs(z->dreal, z->dimag)) == 0.)
	r->dreal = r->dimag = 0.;
else if(z->dreal > 0)
	{
	r->dreal = sqrt(0.5 * (mag + z->dreal) );
	r->dimag = z->dimag / r->dreal / 2;
	}
else
	{
	r->dimag = sqrt(0.5 * (mag - z->dreal) );
	if(z->dimag < 0)
I 3
#ifndef tahoe
E 3
		r->dimag = - r->dimag;
I 3
#else tahoe
		*((long int *)&r->dimag) ^= SIGN_BIT;
#endif tahoe
E 3
	r->dreal = z->dimag / r->dimag / 2;
	}
}
E 1
