h25369
s 00016/00000/00000
d D 4.1 83/06/27 14:43:15 sam 1 0
c date and time created 83/06/27 14:43:15 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include <stdio.h>
dot(xi,yi,dx,n,pat)
int  pat[];
{
	int i;
	putc('d',stdout);
	putsi(xi);
	putsi(yi);
	putsi(dx);
	putsi(n);
	for(i=0; i<n; i++)putsi(pat[i]);
}
E 1
