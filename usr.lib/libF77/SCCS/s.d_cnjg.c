h59156
s 00011/00000/00016
d D 5.2 86/11/03 20:56:01 mckusick 3 2
c update for tahoe
e
s 00005/00001/00011
d D 5.1 85/06/07 21:40:47 kre 2 1
c Add copyright
e
s 00012/00000/00000
d D 1.1 83/01/21 11:09:17 dlw 1 0
c date and time created 83/01/21 11:09:17 by dlw
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
#endif tahoe
E 3

d_cnjg(r, z)
dcomplex *r, *z;
{
r->dreal = z->dreal;
I 3
#ifndef tahoe
E 3
r->dimag = - z->dimag;
I 3
#else tahoe
r->dimag = z->dimag;
if (z->dimag == 0.0)
	return;
else
	*(unsigned long *)&(z->dimag) ^= SIGN_BIT;
#endif tahoe
E 3
}
E 1
