h39115
s 00006/00002/00058
d D 5.3 85/06/26 18:46:18 jerry 5 4
c fix 0**(neg) to give 1/0 as stand. says
e
s 00001/00001/00059
d D 5.2 85/06/07 23:01:43 kre 4 3
c fix botch in previous delta
e
s 00005/00001/00055
d D 5.1 85/06/07 22:18:42 kre 3 2
c Add copyright
e
s 00043/00014/00013
d D 1.2 83/04/15 09:23:15 dlw 2 1
c corrections by Bob Corbett. DLW
e
s 00027/00000/00000
d D 1.1 83/01/21 11:16:42 dlw 1 0
c date and time created 83/01/21 11:16:42 by dlw
e
u
U
t
T
I 1
/*
D 3
 *	"%W%"
E 3
I 3
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
I 2
 *
I 3
 *	%W%	%G%
D 4
 */
E 4
I 4
 *
E 4
E 3
 *  Corrections by Robert P. Corbett, 1983 March 2
 *  Revised to restore portability, 1983 March 4
E 2
 */

I 2

E 2
long int pow_ii(ap, bp)
long int *ap, *bp;
{
D 2
long int pow, x, n;
E 2
I 2
	long int pow, x, n;
D 5
	int zero = 0;
E 5
E 2

D 2
pow = 1;
x = *ap;
n = *bp;
E 2
I 2
	pow = 1;
	x = *ap;
	n = *bp;
E 2

D 2
if(n < 0)
	{ }
else if(n > 0)
	for( ; ; )
E 2
I 2
	if (n == 0)
		return ( 1L );

	if (x == 0)
D 5
		return ( 0L );
E 5
I 5
	{
		if( n > 0 )
			return ( 0L );
		else
			return ( 1/x );
	}
E 5

	if (x == 1)
		return ( 1L );

	if (x == -1)
	{
		if (n < 0)
E 2
		{
D 2
		if(n & 01)
			pow *= x;
		if(n >>= 1)
			x *= x;
E 2
I 2
			if (n < -2)
				n += 2;
			n = -n;
		}
		if (n % 2 == 0)
			return ( 1L );
E 2
		else
D 2
			break;
E 2
I 2
			return ( -1L );
	}

	if (n > 0)
		for( ; ; )
		{
			if(n & 01)
				pow *= x;
			if(n >>= 1)
				x *= x;
			else
				break;
E 2
		}
D 2
return(pow);
E 2
I 2
	else
		pow = 0;

	return(pow);
E 2
}
E 1
