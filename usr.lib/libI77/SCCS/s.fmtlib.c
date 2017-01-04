h56464
s 00007/00001/00090
d D 5.1 85/06/07 23:47:50 kre 4 3
c Add copyright
e
s 00072/00042/00019
d D 1.3 81/11/05 22:57:52 dlw 3 2
c rearranged code to produce fast runtime object. DLW
e
s 00000/00000/00061
d D 1.2 81/02/20 18:30:43 dlw 2 1
c changed to F_ER codes. DLW
e
s 00061/00000/00000
d D 1.1 81/02/18 18:01:19 dlw 1 0
c date and time created 81/02/18 18:01:19 by dlw
e
u
U
t
T
I 1
/*
D 4
char id_fmtlib[] = "%W%";
E 4
I 4
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
 *
I 4
 *	%W%	%G%
 */

/*
E 4
 * integer to ascii conversion
I 3
 *
 * This code has been rearranged to produce optimized runtime code.
E 3
 */

#include "fio.h"

D 3
char	_digit[] = "0123456789abcdefghijklmnopqrstuvwxyz";
E 3
I 3
static char	_digit[] = "0123456789abcdefghijklmnopqrstuvwxyz";
static char	_icv_buf[MAXINTLENGTH+1];
#define		_mask	0x7fffffff
E 3

D 3
char *icvt(value,ndigit,sign) long value; int *ndigit,*sign;
E 3
I 3
char *
icvt(value, ndigit, sign)
long	value;
int	*ndigit;
int	*sign;
E 3
{
D 3
	static char buf[MAXINTLENGTH+1];
	register int i;
	long kludge, rem, mask = 0x7fffffff;
	int one = 1;
	char c;
E 3
I 3
	register long	val = value;
	register long	rad = radix;
	register char	*b = &_icv_buf[MAXINTLENGTH];
	register char	*d = _digit;
	register long	tmp1;
	register int	tmp2;
	long	rem;
	long	kludge;
E 3

D 3
	if (value == 0)
	{	*sign=0;
		*ndigit=one;
		buf[MAXINTLENGTH]='0';
		return(&buf[MAXINTLENGTH]);
E 3
I 3
	if (val == 0)
	{
		*--b = '0';
		*sign = 0;
		*ndigit = 1;
		return(b);
E 3
	}
D 3
	else if (signit)	/* signed */
E 3
I 3

	if (signit && (*sign = (val < 0)))	/* signed conversion */
E 3
	{
D 3
		*sign = (value < 0);
		c = (int)(value % radix);
		value /= radix;
		if (*sign)
		{	value = -value;
			c = -c;
		}
E 3
I 3
		/*
		 * It is necessary to do the first divide
		 * before the absolute value, for the case -2^31
		 *
		 * This is actually what is being done...
		 * tmp1 = (int)(val % rad);
		 * val /= rad;
		 * val = -val
		 * *--b = d[-tmp1];
		 */
		tmp1 = val / rad;
		*--b = d[(tmp1 * rad) - val];
		val = -tmp1;
E 3
	}
D 3
	else			/* unsigned */
	{	*sign = 0;
		if (value < 0)
		{	/* ALL THIS IS TO SIMULATE UNSIGNED MOD & DIV */
			kludge = mask - (radix - one);
			value &= mask;
			rem = (kludge % radix) + (value % radix);
			value = (kludge / radix) + (value / radix)
				 + (rem / radix) + one;
			c = (int)(rem % radix);
E 3
I 3
	else				/* unsigned conversion */
	{
		*sign = 0;
		if (val < 0)
		{	/* ALL THIS IS TO SIMULATE UNSIGNED LONG MOD & DIV */
			kludge = _mask - (rad - 1);
			val &= _mask;
			/*
			 * This is really what's being done...
			 * rem = (kludge % rad) + (val % rad);
			 * val = (kludge / rad) + (val / rad) + (rem / rad) + 1;
			 * *--b = d[rem % rad];
			 */
			tmp1 = kludge / rad;
			tmp2 = val / rad;
			rem = (kludge - (tmp1 * rad)) + (val - (tmp2 * rad));
			val = ++tmp1 + tmp2;
			tmp1 = rem / rad;
			val += tmp1;
			*--b = d[rem - (tmp1 * rad)];
E 3
		}
D 3
		else
		{
			c = (int)(value % radix);
			value /= radix;
		}
E 3
	}
D 3
	*(buf+MAXINTLENGTH) = _digit[c];
	for(i=MAXINTLENGTH-one; value!=0; i--)
E 3
I 3

	while (val)
E 3
	{
D 3
		c = (int)(value % radix);
		*(buf+i) = _digit[c];
		value /= radix;
E 3
I 3
		/*
		 * This is really what's being done ...
		 * *--b = d[val % rad];
		 * val /= rad;
		 */
		tmp1 = val / rad;
		*--b = d[val - (tmp1 * rad)];
		val = tmp1;
E 3
	}
D 3
	*ndigit = MAXINTLENGTH - i;
	return(&buf[i+one]);
E 3
I 3

	*ndigit = (&_icv_buf[MAXINTLENGTH] - b);
	return(b);
E 3
}
E 1
