h11012
s 00000/00006/00091
d D 5.2 87/03/02 14:38:44 mckusick 3 2
c delete incorrect copyright notice
e
s 00009/00001/00088
d D 5.1 85/04/30 13:02:45 dist 2 1
c Add copyright
e
s 00089/00000/00000
d D 4.1 82/12/25 10:50:32 sam 1 0
c date and time created 82/12/25 10:50:32 by sam
e
u
U
t
T
I 1
D 2
/*	%W%	%G%	*/
E 2
I 2
D 3
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 3
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 2

#include <mp.h>
mult(a,b,c) struct mint *a,*b,*c;
{	struct mint x,y,z;
	int sign;
	sign = 1;
	x.val=a->val;
	y.val=b->val;
	z.len=0;
	if(a->len<0)
	{	x.len= -a->len;
		sign= -sign;
	}
	else	x.len=a->len;
	if(b->len<0)
	{	y.len= -b->len;
		sign= -sign;
	}
	else	y.len=b->len;
	if(x.len<y.len) m_mult(&y,&x,&z);
	else m_mult(&x,&y,&z);
	xfree(c);
	if(sign<0) c->len= -z.len;
	else c->len=z.len;
	if(c->len==0) shfree(z.val);
	else c->val=z.val;
	return;
}
#define S2 x=a->val[j];
#define S3 x=x*b->val[i-j];
#define S4 tradd(&carry,&sum,x);
#define S5 c->val[i]=sum.yy.low&077777;
#define S6 sum.xx=sum.xx>>15;
#define S7 sum.yy.high=carry;
m_mult(a,b,c) struct mint *a,*b,*c;
{	long x;
	union {long xx; struct half yy;} sum;
	int carry;
	int i,j;
	c->val=xalloc(a->len+b->len,"m_mult");
	sum.xx=0;
	for(i=0;i<b->len;i++)
	{	carry=0;
		for(j=0;j<i+1;j++)
		{	S2
			S3
			S4
		}
		S5
		S6
		S7
	}
	for(;i<a->len;i++)
	{	carry=0;
		for(j=i-b->len+1;j<i+1;j++)
		{	S2
			S3
			S4
		}
		S5
		S6
		S7
	}
	for(;i<a->len+b->len;i++)
	{	carry=0;
		for(j=i-b->len+1;j<a->len;j++)
		{	S2
			S3
			S4
		}
		S5
		S6
		S7
	}
	if(c->val[i-1]!=0)
		c->len=a->len+b->len;
	else	c->len=a->len+b->len-1;
	return;
}
tradd(a,b,c) long c; int *a; union g {long xx; struct half yy;} *b;
{
	b->xx= b->xx+c;
	if(b->yy.high&0100000)
	{	b->yy.high= b->yy.high&077777;
		*a += 1;
	}
	return;
}
E 1
