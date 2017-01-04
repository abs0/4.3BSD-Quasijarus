h46859
s 00005/00001/00025
d D 5.1 85/06/07 21:56:46 kre 2 1
c Add copyright
e
s 00026/00000/00000
d D 1.1 83/01/21 11:13:17 dlw 1 0
c date and time created 83/01/21 11:13:17 by dlw
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

short h_indx(a, b, la, lb)
char *a, *b;
long int la, lb;
{
int i, n;
char *s, *t, *bend;

n = la - lb + 1;
bend = b + lb;

for(i = 0 ; i < n ; ++i)
	{
	s = a + i;
	t = b;
	while(t < bend)
		if(*s++ != *t++)
			goto no;
	return(i+1);
	no: ;
	}
return(0);
}
E 1
