h20959
s 00000/00006/00044
d D 5.2 87/03/02 14:38:46 mckusick 3 2
c delete incorrect copyright notice
e
s 00009/00001/00041
d D 5.1 85/04/30 13:02:48 dist 2 1
c Add copyright
e
s 00042/00000/00000
d D 4.1 82/12/25 10:50:33 sam 1 0
c date and time created 82/12/25 10:50:33 by sam
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
pow(a,b,c,d) MINT *a,*b,*c,*d;
{	int i,j,n;
	MINT x,y;
	x.len=y.len=0;
	xfree(d);
	d->len=1;
	d->val=xalloc(1,"pow");
	*d->val=1;
	for(j=0;j<b->len;j++)
	{	n=b->val[b->len-j-1];
		for(i=0;i<15;i++)
		{	mult(d,d,&x);
			mdiv(&x,c,&y,d);
			if((n=n<<1)&0100000)
			{	mult(a,d,&x);
				mdiv(&x,c,&y,d);
			}
		}
	}
	xfree(&x);
	xfree(&y);
	return;
}
rpow(a,n,b) MINT *a,*b;
{	MINT x,y;
	int i;
	x.len=1;
	x.val=xalloc(1,"rpow");
	*x.val=n;
	y.len=n*a->len+4;
	y.val=xalloc(y.len,"rpow2");
	for(i=0;i<y.len;i++) y.val[i]=0;
	y.val[y.len-1]=010000;
	xfree(b);
	pow(a,&x,&y,b);
	xfree(&x);
	xfree(&y);
	return;
}
E 1
