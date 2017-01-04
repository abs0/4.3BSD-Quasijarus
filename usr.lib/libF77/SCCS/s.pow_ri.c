h53752
s 00029/00031/00014
d D 5.4 88/01/24 12:34:20 bostic 5 4
c updated files; from Zhishun Alex Liu
e
s 00005/00006/00040
d D 5.3 86/11/03 21:10:14 mckusick 4 3
c update for tahoe
e
s 00006/00002/00040
d D 5.2 85/07/09 15:33:56 jerry 3 2
c do store in global to force convert to float despite C bug.
e
s 00005/00001/00037
d D 5.1 85/06/07 22:19:05 kre 2 1
c Add copyright
e
s 00038/00000/00000
d D 1.1 83/01/21 11:16:47 dlw 1 0
c date and time created 83/01/21 11:16:47 by dlw
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
D 4
float flt_retval;

E 4
E 3
D 5
float pow_ri(ap, bp)
float *ap;
long int *bp;
E 5
I 5
#ifdef tahoe
#define	double	float
#endif /* tahoe */

float
pow_ri(ap, bp)
	float *ap;
	long *bp;
E 5
{
D 5
double pow, x;
long int n;
E 5
I 5
	register long n = *bp;
#ifdef tahoe
	register
#endif /* tahoe */
	double y, x = *ap;
E 5

D 5
pow = 1;
x = *ap;
n = *bp;

if(n != 0)
	{
	if(n < 0)
		{
		if(x == 0)
			{
D 3
			return(pow);
E 3
I 3
D 4
			flt_retval = pow;
			return(flt_retval);
E 4
I 4
			return(pow);
E 4
E 3
			}
E 5
I 5
	if (!n)
		return((double)1);
	if (n < 0) {
		x = (double)1 / x;
E 5
		n = -n;
D 5
		x = 1/x;
		}
I 4
	if (x == 0)
		return(0);

E 4
	for( ; ; )
		{
		if(n & 01)
			pow *= x;
		if(n >>= 1)
E 5
I 5
	}
	while (!(n&1)) {
		x *= x;
		n >>= 1;
	}
	for (y = x; --n > 0; y *= x)
		while (!(n&1)) {
E 5
			x *= x;
D 5
		else
			break;
E 5
I 5
			n >>= 1;
E 5
		}
D 5
	}
D 3
return(pow);
E 3
I 3
D 4
flt_retval = pow;
return(flt_retval);
E 4
I 4
return(pow);
E 5
I 5
	return(y);
E 5
E 4
E 3
}
I 5
#ifdef tahoe
#undef double
#endif /* tahoe */
E 5
E 1
