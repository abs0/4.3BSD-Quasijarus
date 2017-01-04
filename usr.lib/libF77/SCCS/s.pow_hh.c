h14068
s 00043/00014/00017
d D 5.2 85/06/26 18:46:38 jerry 3 2
c point in fixes already in pow_ii.c
e
s 00005/00001/00026
d D 5.1 85/06/07 22:18:18 kre 2 1
c Add copyright
e
s 00027/00000/00000
d D 1.1 83/01/21 11:16:37 dlw 1 0
c date and time created 83/01/21 11:16:37 by dlw
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

short pow_hh(ap, bp)
short *ap, *bp;
{
D 3
short pow, x, n;
E 3
I 3
	short int pow, x, n;
E 3

D 3
pow = 1;
x = *ap;
n = *bp;
E 3
I 3
	pow = 1;
	x = *ap;
	n = *bp;
E 3

D 3
if(n < 0)
	{ }
else if(n > 0)
	for( ; ; )
E 3
I 3
	if (n == 0)
		return ( 1L );

	if (x == 0)
	{
		if( n > 0 )
			return ( 0L );
		else
			return ( 1/x );
	}

	if (x == 1)
		return ( 1L );

	if (x == -1)
	{
		if (n < 0)
E 3
		{
D 3
		if(n & 01)
			pow *= x;
		if(n >>= 1)
			x *= x;
E 3
I 3
			if (n < -2)
				n += 2;
			n = -n;
		}
		if (n % 2 == 0)
			return ( 1L );
E 3
		else
D 3
			break;
E 3
I 3
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
E 3
		}
D 3
return(pow);
E 3
I 3
	else
		pow = 0;

	return(pow);
E 3
}
E 1
