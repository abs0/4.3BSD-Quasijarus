h30502
s 00000/00006/00145
d D 5.3 87/03/02 14:38:42 mckusick 5 4
c delete incorrect copyright notice
e
s 00006/00006/00145
d D 5.2 86/03/13 18:59:15 donn 4 3
c lint -- fix up type declarations, make use of 'short' in sdiv consistent
e
s 00009/00001/00142
d D 5.1 85/04/30 13:02:38 dist 3 2
c Add copyright
e
s 00001/00001/00142
d D 4.2 83/06/14 11:47:54 sam 2 1
c from td@dagobah.UUCP
e
s 00143/00000/00000
d D 4.1 82/12/25 10:50:30 sam 1 0
c date and time created 82/12/25 10:50:30 by sam
e
u
U
t
T
I 1
D 3
/*	%W%	%G%	*/
E 3
I 3
D 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 5
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 3

#include <stdio.h>
#include <mp.h>
m_in(a,b,f) MINT *a; FILE *f;
{	MINT x,y,ten;
	int sign,c;
	short qten,qy;
	xfree(a);
	sign=1;
	ten.len=1;
	ten.val= &qten;
	qten=b;
	x.len=0;
	y.len=1;
	y.val= &qy;
	while((c=getc(f))!=EOF)
	switch(c)
	{
D 4
	case '\\':	getc(f);
E 4
I 4
	case '\\':	(void)getc(f);
E 4
		continue;
	case '\t':
	case '\n': a->len *= sign;
		xfree(&x);
		return(0);
	case ' ':
		continue;
	case '-': sign = -sign;
		continue;
	default: if(c>='0' && c<= '9')
		{	qy=c-'0';
			mult(&x,&ten,a);
			madd(a,&y,a);
			move(a,&x);
			continue;
		}
		else
		{	VOID ungetc(c,stdin);
			a->len *= sign;
			return(0);
		}
	}
	return(EOF);
}
m_out(a,b,f) MINT *a; FILE *f;
{	int sign,xlen,i;
	short r;
	MINT x;
D 4
	char *obuf;
E 4
I 4
	char *obuf, *malloc();
E 4
	register char *bp;
	sign=1;
	xlen=a->len;
	if(xlen<0)
	{	xlen= -xlen;
		sign= -1;
	}
	if(xlen==0)
	{	fprintf(f,"0\n");
		return;
	}
	x.len=xlen;
	x.val=xalloc(xlen,"m_out");
	for(i=0;i<xlen;i++) x.val[i]=a->val[i];
D 4
	obuf=(char *)malloc(7*xlen);
E 4
I 4
	obuf=malloc(7*(unsigned)xlen);
E 4
	bp=obuf+7*xlen-1;
	*bp--=0;
	while(x.len>0)
	{	for(i=0;i<10&&x.len>0;i++)
D 4
		{	sdiv(&x,b,&x,&r);
E 4
I 4
		{	sdiv(&x,(short)b,&x,&r);
E 4
			*bp--=r+'0';
		}
		if(x.len>0) *bp--=' ';
	}
	if(sign==-1) *bp--='-';
	fprintf(f,"%s\n",bp+1);
	free(obuf);
	FREE(x)
	return;
}
D 4
sdiv(a,n,q,r) MINT *a,*q; short *r;
E 4
I 4
sdiv(a,n,q,r) MINT *a,*q; short n; short *r;
E 4
{	MINT x,y;
	int sign;
	sign=1;
	x.len=a->len;
	x.val=a->val;
	if(n<0)
	{	sign= -sign;
		n= -n;
	}
	if(x.len<0)
	{	sign = -sign;
		x.len= -x.len;
	}
	s_div(&x,n,&y,r);
	xfree(q);
	q->val=y.val;
	q->len=sign*y.len;
	*r = *r*sign;
	return;
}
D 4
s_div(a,n,q,r) MINT *a,*q; short *r;
E 4
I 4
s_div(a,n,q,r) MINT *a,*q; short n; short *r;
E 4
{	int qlen,i;
	long int x;
	short *qval;
	x=0;
	qlen=a->len;
	qval=xalloc(qlen,"s_div");
	for(i=qlen-1;i>=0;i--)
	{
		x=x*0100000L+a->val[i];
		qval[i]=x/n;
		x=x%n;
	}
	*r=x;
D 2
	if(qval[qlen-1]==0) qlen--;
E 2
I 2
	if(qlen && qval[qlen-1]==0) qlen--;
E 2
	q->len=qlen;
	q->val=qval;
	if(qlen==0) shfree(qval);
	return;
}
min(a) MINT *a;
{
	return(m_in(a,10,stdin));
}
omin(a) MINT *a;
{
	return(m_in(a,8,stdin));
}
mout(a) MINT *a;
{
	m_out(a,10,stdout);
}
omout(a) MINT *a;
{
	m_out(a,8,stdout);
}
fmout(a,f) MINT *a; FILE *f;
{	m_out(a,10,f);
}
fmin(a,f) MINT *a; FILE *f;
{
	return(m_in(a,10,f));
}
E 1
