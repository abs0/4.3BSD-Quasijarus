h46986
s 00005/00001/00024
d D 5.1 85/06/07 22:35:02 kre 2 1
c Add copyright
e
s 00025/00000/00000
d D 1.1 83/01/21 11:18:56 dlw 1 0
c date and time created 83/01/21 11:18:56 by dlw
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

s_copy(a, b, la, lb)	/* assign strings:  a = b */
char *a, *b;
long int la, lb;
{
char *aend, *bend;

aend = a + la;

if(la <= lb)
	while(a < aend)
		*a++ = *b++;

else
	{
	bend = b + lb;
	while(b < bend)
		*a++ = *b++;
	while(a < aend)
		*a++ = ' ';
	}
}
E 1
