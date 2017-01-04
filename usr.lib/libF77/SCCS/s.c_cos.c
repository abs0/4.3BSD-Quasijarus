h43188
s 00005/00001/00013
d D 5.1 85/06/07 21:35:52 kre 2 1
c Add copyright
e
s 00014/00000/00000
d D 1.1 83/01/21 11:07:56 dlw 1 0
c date and time created 83/01/21 11:07:56 by dlw
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

c_cos(r, z)
complex *r, *z;
{
double sin(), cos(), sinh(), cosh();

r->real = cos(z->real) * cosh(z->imag);
r->imag = - sin(z->real) * sinh(z->imag);
}
E 1
