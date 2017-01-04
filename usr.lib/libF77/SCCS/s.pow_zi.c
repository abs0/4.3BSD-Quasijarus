h46919
s 00025/00036/00017
d D 5.2 88/01/24 12:34:21 bostic 3 2
c updated files; from Zhishun Alex Liu
e
s 00005/00001/00048
d D 5.1 85/06/07 22:19:20 kre 2 1
c Add copyright
e
s 00049/00000/00000
d D 1.1 83/01/21 11:16:51 dlw 1 0
c date and time created 83/01/21 11:16:51 by dlw
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
#define	Z_MULEQ(A,B)	\
	t = (A).dreal * (B).dreal - (A).dimag * (B).dimag,\
	(A).dimag = (A).dreal * (B).dimag + (A).dimag * (B).dreal,\
	(A).dreal = t	/* A *= B */

void
E 3
pow_zi(p, a, b) 	/* p = a**b  */
D 3
dcomplex *p, *a;
long int *b;
E 3
I 3
	dcomplex *p, *a;
	long int *b;
E 3
{
D 3
long int n;
double t;
dcomplex x;
E 3
I 3
	register long n = *b;
	double t;
	dcomplex x;
E 3

D 3
n = *b;
p->dreal = 1;
p->dimag = 0;

if(n == 0)
	return;
if(n < 0)
	{
	n = -n;
	z_div(&x, p, a);
E 3
I 3
	x = *a;
	p->dreal = (double)1, p->dimag = (double)0;
	if (!n)
		return;
	if (n < 0) {
		z_div(&x, p, a);
		n = -n;
E 3
	}
D 3
else
	{
	x.dreal = a->dreal;
	x.dimag = a->dimag;
E 3
I 3
	while (!(n&1)) {
		Z_MULEQ(x, x);
		n >>= 1;
E 3
	}
D 3

for( ; ; )
	{
	if(n & 01)
		{
		t = p->dreal * x.dreal - p->dimag * x.dimag;
		p->dimag = p->dreal * x.dimag + p->dimag * x.dreal;
		p->dreal = t;
E 3
I 3
	for (*p = x; --n > 0; Z_MULEQ(*p, x))
		while (!(n&1)) {
			Z_MULEQ(x, x);
			n >>= 1;
E 3
		}
D 3
	if(n >>= 1)
		{
		t = x.dreal * x.dreal - x.dimag * x.dimag;
		x.dimag = 2 * x.dreal * x.dimag;
		x.dreal = t;
		}
	else
		break;
	}
E 3
}
E 1
