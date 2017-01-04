h08818
s 00000/00006/00150
d D 5.2 87/03/02 14:38:39 mckusick 3 2
c delete incorrect copyright notice
e
s 00009/00001/00147
d D 5.1 85/04/30 13:02:30 dist 2 1
c Add copyright
e
s 00148/00000/00000
d D 4.1 82/12/25 10:50:28 sam 1 0
c date and time created 82/12/25 10:50:28 by sam
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
m_add(a,b,c) struct mint *a,*b,*c;
{	int carry,i;
	int x;
	short *cval;
	cval=xalloc(a->len+1,"m_add");
	carry=0;
	for(i=0;i<b->len;i++)
	{	x=carry+a->val[i]+b->val[i];
		if(x&0100000)
		{	carry=1;
			cval[i]=x&077777;
		}
		else
		{	carry=0;
			cval[i]=x;
		}
	}
	for(;i<a->len;i++)
	{	x=carry+a->val[i];
		if(x&0100000) cval[i]=x&077777;
		else
		{	carry=0;
			cval[i]=x;
		}

	}
	if(carry==1)
	{	cval[i]=1;
		c->len=i+1;
	}
	else c->len=a->len;
	c->val=cval;
	if(c->len==0) shfree(cval);
	return;
}
madd(a,b,c) struct mint *a,*b,*c;
{	struct mint x,y,z;
	int sign;
	x.len=a->len;
	x.val=a->val;
	y.len=b->len;
	y.val=b->val;
	z.len=0;
	sign=1;
	if(x.len>=0)
		if(y.len>=0)
			if(x.len>=y.len) m_add(&x,&y,&z);
			else m_add(&y,&x,&z);
		else
		{	y.len= -y.len;
			msub(&x,&y,&z);
		}
	else	if(y.len<=0)
		{	x.len = -x.len;
			y.len= -y.len;
			sign= -1;
			madd(&x,&y,&z);
		}
		else
		{	x.len= -x.len;
			msub(&y,&x,&z);
		}
	 xfree(c);
	c->val=z.val;
	c->len=sign*z.len;
	return;
}
m_sub(a,b,c) struct mint *a,*b,*c;
{	int x,i;
	int borrow;
	short one;
	struct mint mone;
	one=1; mone.len= 1; mone.val= &one;
	c->val=xalloc(a->len,"m_sub");
	borrow=0;
	for(i=0;i<b->len;i++)
	{	x=borrow+a->val[i]-b->val[i];
		if(x&0100000)
		{	borrow= -1;
			c->val[i]=x&077777;
		}
		else
		{	borrow=0;
			c->val[i]=x;
		}
	}
	for(;i<a->len;i++)
	{	x=borrow+a->val[i];
		if(x&0100000) c->val[i]=x&077777;
		else
		{	borrow=0;
			c->val[i]=x;
		}
	}
	if(borrow<0)
	{	for(i=0;i<a->len;i++) c->val[i] ^= 077777;
		c->len=a->len;
		madd(c,&mone,c);
	}
	for(i=a->len-1;i>=0;--i) if(c->val[i]>0)
				{	if(borrow==0) c->len=i+1;
					else c->len= -i-1;
					return;
				}
	shfree(c->val);
	return;
}
msub(a,b,c) struct mint *a,*b,*c;
{	struct mint x,y,z;
	int sign;
	x.len=a->len;
	y.len=b->len;
	x.val=a->val;
	y.val=b->val;
	z.len=0;
	sign=1;
	if(x.len>=0)
		if(y.len>=0)
			if(x.len>=y.len) m_sub(&x,&y,&z);
			else
			{	sign= -1;
				msub(&y,&x,&z);
			}
		else
		{	y.len= -y.len;
			madd(&x,&y,&z);
		}
	else	if(y.len<=0)
		{	sign= -1;
			x.len= -x.len;
			y.len= -y.len;
			msub(&y,&x,&z);
		}
		else
		{	x.len= -x.len;
			madd(&x,&y,&z);
			sign= -1;
		}
	if(a==c && x.len!=0) xfree(a);
	else if(b==c && y.len!=0) xfree(b);
	else xfree(c);
	c->val=z.val;
	c->len=sign*z.len;
	return;
}
E 1
