h56419
s 00002/00004/00013
d D 5.3 85/07/08 14:41:02 jerry 4 3
c call log10 in math lib.
e
s 00001/00001/00016
d D 5.2 85/07/08 14:31:06 jerry 3 2
c declare function as float, not double.
e
s 00005/00001/00012
d D 5.1 85/06/07 22:26:03 kre 2 1
c Add copyright
e
s 00013/00000/00000
d D 1.1 83/01/21 11:17:59 dlw 1 0
c date and time created 83/01/21 11:17:59 by dlw
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

D 4
#define log10e 0.43429448190325182765

E 4
D 3
double r_lg10(x)
E 3
I 3
float r_lg10(x)
E 3
float *x;
{
D 4
double log();
E 4
I 4
double log10();
E 4

D 4
return( log10e * log(*x) );
E 4
I 4
return( log10(*x) );
E 4
}
E 1
