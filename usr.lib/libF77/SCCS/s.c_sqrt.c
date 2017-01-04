h13470
s 00007/00000/00030
d D 5.2 86/11/03 20:56:00 mckusick 4 2
c update for tahoe
e
s 00004/00000/00030
d R 5.2 86/11/03 20:38:07 mckusick 3 2
c update for tahoe
e
s 00005/00001/00025
d D 5.1 85/06/07 21:37:55 kre 2 1
c Add copyright
e
s 00026/00000/00000
d D 1.1 83/01/21 11:08:37 dlw 1 0
c date and time created 83/01/21 11:08:37 by dlw
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
I 4
#ifdef tahoe
#include <tahoemath/FP.h>
#endif tahoe
E 4

c_sqrt(r, z)
complex *r, *z;
{
double mag, sqrt(), cabs();

if( (mag = cabs(z->real, z->imag)) == 0.)
	r->real = r->imag = 0.;
else if(z->real > 0)
	{
	r->real = sqrt(0.5 * (mag + z->real) );
	r->imag = z->imag / r->real / 2;
	}
else
	{
	r->imag = sqrt(0.5 * (mag - z->real) );
	if(z->imag < 0)
I 4
#ifndef tahoe
E 4
		r->imag = - r->imag;
I 4
#else tahoe
		*(unsigned long*)&(r->imag) ^= SIGN_BIT;
#endif tahoe
E 4
	r->real = z->imag / r->imag /2;
	}
}
E 1
