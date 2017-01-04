h23325
s 00017/00000/00000
d D 1.1 88/06/08 15:14:35 jak 1 0
c date and time created 88/06/08 15:14:35 by jak
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%G%";
#endif not lint

#include <stdio.h>

getnum()
{
	int c, n;

	n = 0;
	while ((c=getchar()) >= '0' && c <= '9')
		n = n*10 + c - '0';
	if (c == EOF)
		return(-1);
	return(n);
}
E 1
