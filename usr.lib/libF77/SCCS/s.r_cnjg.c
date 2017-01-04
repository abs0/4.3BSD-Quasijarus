h37118
s 00005/00001/00011
d D 5.1 85/06/07 22:22:46 kre 2 1
c Add copyright
e
s 00012/00000/00000
d D 1.1 83/01/21 11:17:22 dlw 1 0
c date and time created 83/01/21 11:17:22 by dlw
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

r_cnjg(r, z)
complex *r, *z;
{
r->real = z->real;
r->imag = - z->imag;
}
E 1
