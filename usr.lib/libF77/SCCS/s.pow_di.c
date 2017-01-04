h19926
s 00019/00031/00014
d D 5.3 88/01/19 08:56:41 bostic 4 3
c fix infinite loop bug; from Zhishun Alex Liu
e
s 00003/00000/00042
d D 5.2 86/11/03 21:04:44 mckusick 3 2
c update for tahoe
e
s 00005/00001/00037
d D 5.1 85/06/07 22:09:18 kre 2 1
c Add copyright
e
s 00038/00000/00000
d D 1.1 83/01/21 11:16:34 dlw 1 0
c date and time created 83/01/21 11:16:34 by dlw
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
double pow_di(ap, bp)
double *ap;
long int *bp;
E 4
I 4
double
pow_di(ap, bp)
	double *ap;
	long *bp;
E 4
{
D 4
double pow, x;
long int n;
E 4
I 4
	register long n = *bp;
	double y, x = *ap;
E 4

D 4
pow = 1;
x = *ap;
n = *bp;

if(n != 0)
	{
	if(n < 0)
		{
		if(x == 0)
			{
			return(pow);
			}
E 4
I 4
	if (!n)
		return((double)1);
	if (n < 0) {
		x = (double)1 / x;
E 4
		n = -n;
D 4
		x = 1/x;
		}
I 3
	if (x == 0)
		return(0);

E 3
	for( ; ; )
		{
		if(n & 01)
			pow *= x;
		if(n >>= 1)
E 4
I 4
	}
	while (!(n&1)) {
		x *= x;
		n >>= 1;
	}
	for (y = x; --n > 0; y *= x)
		while (!(n&1)) {
E 4
			x *= x;
D 4
		else
			break;
E 4
I 4
			n >>= 1;
E 4
		}
D 4
	}
return(pow);
E 4
I 4
	return(y);
E 4
}
E 1
