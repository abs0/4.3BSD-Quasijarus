h37336
s 00005/00001/00010
d D 5.1 85/06/07 22:04:48 kre 2 1
c Add copyright
e
s 00011/00000/00000
d D 1.1 83/01/21 11:15:51 dlw 1 0
c date and time created 83/01/21 11:15:51 by dlw
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

long int i_sign(a,b)
long int *a, *b;
{
long int x;
x = (*a >= 0 ? *a : - *a);
return( *b >= 0 ? x : -x);
}
E 1
