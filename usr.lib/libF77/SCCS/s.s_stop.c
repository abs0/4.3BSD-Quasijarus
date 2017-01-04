h45114
s 00005/00001/00022
d D 5.1 85/06/07 22:36:19 kre 2 1
c Add copyright
e
s 00023/00000/00000
d D 1.1 83/01/21 11:19:09 dlw 1 0
c date and time created 83/01/21 11:19:09 by dlw
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

#include <stdio.h>

s_stop(s, n)
char *s;
long int n;
{
int i;

if(n > 0)
	{
	fprintf(stderr, "STOP: ");
	for(i = 0; i<n ; i++)
		putc(*s++, stderr);
	putc('\n', stderr);
	}
f_exit();
_cleanup();
exit(0);
}
E 1
