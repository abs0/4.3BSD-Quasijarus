h38164
s 00005/00001/00012
d D 5.1 85/06/07 21:35:32 kre 2 1
c Add copyright
e
s 00013/00000/00000
d D 1.1 83/01/21 11:07:48 dlw 1 0
c date and time created 83/01/21 11:07:48 by dlw
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

float c_abs(z)
complex *z;
{
double cabs();

return( cabs( z->real, z->imag ) );
}
E 1
