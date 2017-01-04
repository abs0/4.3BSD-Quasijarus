h40065
s 00000/00006/00050
d D 5.3 87/03/02 14:38:38 mckusick 4 3
c delete incorrect copyright notice
e
s 00001/00001/00055
d D 5.2 86/03/13 18:40:58 donn 3 2
c lint -- argument count for xalloc
e
s 00009/00001/00047
d D 5.1 85/04/30 13:02:27 dist 2 1
c Add copyright
e
s 00048/00000/00000
d D 4.1 82/12/25 10:50:27 sam 1 0
c date and time created 82/12/25 10:50:27 by sam
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
D 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 4
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 2

#include <mp.h>
gcd(a,b,c) MINT *a,*b,*c;
{	MINT x,y,z,w;
	x.len=y.len=z.len=w.len=0;
	move(a,&x);
	move(b,&y);
	while(y.len!=0)
	{	mdiv(&x,&y,&w,&z);
		move(&y,&x);
		move(&z,&y);
	}
	move(&x,c);
	xfree(&x);
	xfree(&y);
	xfree(&z);
	xfree(&w);
	return;
}
invert(a, b, c) MINT *a, *b, *c;
{	MINT x, y, z, w, Anew, Aold;
	int i = 0;
	x.len = y.len = z.len = w.len = Aold.len = 0;
	Anew.len = 1;
D 3
	Anew.val = xalloc(1);
E 3
I 3
	Anew.val = xalloc(1, "invert");
E 3
	*Anew.val = 1;
	move(b, &x);
	move(a, &y);
	while(y.len != 0)
	{	mdiv(&x, &y, &w, &z);
		move(&Anew, &x);
		mult(&w, &Anew, &Anew);
		madd(&Anew, &Aold, &Anew);
		move(&x, &Aold);
		move(&y, &x);
		move(&z, &y);
		i++;
	}
	move(&Aold, c);
	if( (i&01) == 0) msub(b, c, c);
	xfree(&x);
	xfree(&y);
	xfree(&z);
	xfree(&w);
	xfree(&Aold);
	xfree(&Anew);
}
E 1
