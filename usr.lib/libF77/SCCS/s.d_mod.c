h12403
s 00001/00001/00028
d D 5.3 87/05/08 10:53:42 sam 4 3
c correct #ifdef's (from jim mckie)
e
s 00012/00001/00017
d D 5.2 86/11/03 20:58:16 mckusick 3 2
c update for tahoe
e
s 00005/00001/00013
d D 5.1 85/06/07 21:44:32 kre 2 1
c Add copyright
e
s 00014/00000/00000
d D 1.1 83/01/21 11:10:11 dlw 1 0
c date and time created 83/01/21 11:10:11 by dlw
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
I 3
#ifdef tahoe
#include <tahoemath/FP.h>
#endif tahoe
E 3

double d_mod(x,y)
double *x, *y;
{
double floor(), quotient = *x / *y;
if (quotient >= 0.0)
	quotient = floor(quotient);
D 3
else
E 3
I 3
else {
#ifndef tahoe
E 3
	quotient = -floor(-quotient);
I 3
#else tahoe
	*(unsigned long *)&quotient ^= SIGN_BIT;
	quotient = floor(quotient);
	if (quotient !=0)
		*(unsigned long *)&quotient ^= SIGN_BIT;
D 4
}
E 4
#endif tahoe
I 4
}
E 4
E 3
return(*x - (*y) * quotient );
}
E 1
