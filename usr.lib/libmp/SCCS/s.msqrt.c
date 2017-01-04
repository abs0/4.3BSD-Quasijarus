h24745
s 00000/00006/00041
d D 5.2 87/03/02 14:38:43 mckusick 3 2
c delete incorrect copyright notice
e
s 00009/00001/00038
d D 5.1 85/04/30 13:02:42 dist 2 1
c Add copyright
e
s 00039/00000/00000
d D 4.1 82/12/25 10:50:31 sam 1 0
c date and time created 82/12/25 10:50:31 by sam
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
msqrt(a,b,r) MINT *a,*b,*r;
{	MINT x,junk,y;
	int j;
	x.len=junk.len=y.len=0;
	if(a->len<0) fatal("msqrt: neg arg");
	if(a->len==0)
	{	b->len=0;
		r->len=0;
		return(0);
	}
	if(a->len%2==1) x.len=(1+a->len)/2;
	else x.len=1+a->len/2;
	x.val=xalloc(x.len,"msqrt");
	for(j=0;j<x.len;x.val[j++]=0);
	if(a->len%2==1) x.val[x.len-1]=0400;
	else x.val[x.len-1]=1;
	xfree(b);
	xfree(r);
loop:
	mdiv(a,&x,&y,&junk);
	xfree(&junk);
	madd(&x,&y,&y);
	sdiv(&y,2,&y,(short *)&j);
	if(mcmp(&x,&y)>0)
	{	xfree(&x);
		move(&y,&x);
		xfree(&y);
		goto loop;
	}
	xfree(&y);
	move(&x,b);
	mult(&x,&x,&x);
	msub(a,&x,r);
	xfree(&x);
	return(r->len);
}
E 1
