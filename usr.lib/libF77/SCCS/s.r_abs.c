h43869
s 00001/00001/00014
d D 5.2 85/07/08 14:30:50 jerry 3 2
c declare function as float, not double.
e
s 00005/00001/00010
d D 5.1 85/06/07 22:20:10 kre 2 1
c Add copyright
e
s 00011/00000/00000
d D 1.1 83/01/21 11:16:59 dlw 1 0
c date and time created 83/01/21 11:16:59 by dlw
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

D 3
double r_abs(x)
E 3
I 3
float r_abs(x)
E 3
float *x;
{
if(*x >= 0)
	return(*x);
return(- *x);
}
E 1
