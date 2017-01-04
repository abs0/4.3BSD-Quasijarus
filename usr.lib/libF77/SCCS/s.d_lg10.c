h61988
s 00001/00001/00014
d D 5.3 85/08/08 09:36:01 bloom 5 3
c log10 was not declared as returning a double
e
s 00001/00001/00014
d R 5.3 85/08/08 09:35:07 bloom 4 3
c log10 was declared as returning a double
e
s 00001/00003/00014
d D 5.2 85/07/08 14:41:07 jerry 3 2
c call log10 in math lib.
e
s 00005/00001/00012
d D 5.1 85/06/07 21:43:52 kre 2 1
c Add copyright
e
s 00013/00000/00000
d D 1.1 83/01/21 11:10:01 dlw 1 0
c date and time created 83/01/21 11:10:01 by dlw
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
#define log10e 0.43429448190325182765

E 3
double d_lg10(x)
double *x;
{
D 5
double log();
E 5
I 5
double log10();
E 5

D 3
return( log10e * log(*x) );
E 3
I 3
return( log10(*x) );
E 3
}
E 1
