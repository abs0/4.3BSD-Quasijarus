h23062
s 00044/00050/00022
d D 5.3 88/01/24 12:34:18 bostic 4 3
c updated files; from Zhishun Alex Liu
e
s 00048/00000/00024
d D 5.2 86/11/03 21:03:40 mckusick 3 2
c update for tahoe
e
s 00005/00001/00019
d D 5.1 85/06/07 22:08:40 kre 2 1
c Add copyright
e
s 00020/00000/00000
d D 1.1 83/01/21 11:16:25 dlw 1 0
c date and time created 83/01/21 11:16:25 by dlw
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

#include "complex"

I 3
D 4
#ifndef tahoe
E 4
I 4
#ifdef tahoe

#define	C_MULEQ(A,B)	\
	t = (A).real * (B).real - (A).imag * (B).imag,\
	(A).imag = (A).real * (B).imag + (A).imag * (B).real,\
	(A).real = t	/* A *= B */

void
E 4
E 3
pow_ci(p, a, b) 	/* p = a**b  */
D 4
complex *p, *a;
long int *b;
E 4
I 4
	complex *p, *a;
	long *b;
E 4
{
D 4
dcomplex p1, a1;
E 4
I 4
	register long n = *b;
	register float t;
	complex x;
E 4

D 4
a1.dreal = a->real;
a1.dimag = a->imag;

pow_zi(&p1, &a1, b);

p->real = p1.dreal;
p->imag = p1.dimag;
E 4
I 4
	x = *a;
	p->real = (float)1, p->imag = (float)0;
	if (!n)
		return;
	if (n < 0) {
		c_div(&x, p, a);
		n = -n;
	}
	while (!(n&1)) {
		C_MULEQ(x, x);
		n >>= 1;
	}
	for (*p = x; --n > 0; C_MULEQ(*p, x))
		while (!(n&1)) {
			C_MULEQ(x, x);
			n >>= 1;
		}
E 4
}
I 3

D 4
#else tahoe
E 4
I 4
#else /* !tahoe */
E 4

I 4
extern void pow_zi();

void
E 4
pow_ci(p, a, b) 	/* p = a**b  */
D 4
complex *p, *a;
long int *b;
E 4
I 4
	complex *p, *a;
	long *b;
E 4
{
D 4
register long int n;
register float t;
complex x;
E 4
I 4
	dcomplex p1, a1;
E 4

D 4
n = *b;
p->real = 1;
p->imag = 0;
E 4
I 4
	a1.dreal = a->real;
	a1.dimag = a->imag;
E 4

D 4
if(n == 0)
	return;
if(n < 0)
	{
	n = -n;
	c_div(&x,p,a);
	}
else
	{
	x.real = a->real;
	x.imag = a->imag;
	}
E 4
I 4
	pow_zi(&p1, &a1, b);
E 4

D 4
for( ; ; )
	{
	if(n & 01)
		{
		t = p->real * x.real - p->imag * x.imag;
		p->imag = p->real * x.imag + p->imag * x.real;
		p->real = t;
		}
	if(n >>= 1)
		{
		t = x.real * x.real - x.imag * x.imag;
		x.imag = 2 * x.real * x.imag;
		x.real = t;
		}
	else
		break;
	}
E 4
I 4
	p->real = p1.dreal;
	p->imag = p1.dimag;
E 4
}
D 4
#endif tahoe
E 4
I 4

#endif /* tahoe */
E 4
E 3
E 1
