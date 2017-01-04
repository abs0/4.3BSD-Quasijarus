h57545
s 00016/00000/00015
d D 5.2 86/11/03 21:00:56 mckusick 3 2
c update for tahoe
e
s 00005/00001/00010
d D 5.1 85/06/07 21:46:16 kre 2 1
c Add copyright
e
s 00011/00000/00000
d D 1.1 83/01/21 11:10:32 dlw 1 0
c date and time created 83/01/21 11:10:32 by dlw
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
#ifndef tahoe
E 3
double d_sign(a,b)
double *a, *b;
{
double x;
x = (*a >= 0 ? *a : - *a);
return( *b >= 0 ? x : -x);
}
I 3

#else tahoe

#include <tahoemath/FP.h>

double d_sign(a,b)
double *a, *b;
{
double x;
x = *a;
if ((*a < 0) || (*b < 0))
	*(unsigned long *)&x ^= SIGN_BIT;
return(x);
}
#endif tahoe
E 3
E 1
