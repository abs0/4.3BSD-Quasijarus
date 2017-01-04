h42234
s 00005/00001/00013
d D 5.1 85/06/07 21:37:03 kre 2 1
c Add copyright
e
s 00014/00000/00000
d D 1.1 83/01/21 11:08:26 dlw 1 0
c date and time created 83/01/21 11:08:26 by dlw
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

c_log(r, z)
complex *r, *z;
{
double log(), cabs(), atan2();

r->imag = atan2(z->imag, z->real);
r->real = log( cabs(z->real, z->imag) );
}
E 1
