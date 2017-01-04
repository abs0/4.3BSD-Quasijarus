h61713
s 00005/00001/00039
d D 5.1 85/06/07 22:31:36 kre 2 1
c Add copyright
e
s 00040/00000/00000
d D 1.1 83/01/21 11:18:53 dlw 1 0
c date and time created 83/01/21 11:18:53 by dlw
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

int s_cmp(a, b, la, lb)	/* compare two strings */
register char *a, *b;
long int la, lb;
{
register char *aend, *bend;
aend = a + la;
bend = b + lb;

if(la <= lb)
	{
	while(a < aend)
		if(*a != *b)
			return( *a - *b );
		else
			{ ++a; ++b; }

	while(b < bend)
		if(*b != ' ')
			return( ' ' - *b );
		else	++b;
	}

else
	{
	while(b < bend)
		if(*a == *b)
			{ ++a; ++b; }
		else
			return( *a - *b );
	while(a < aend)
		if(*a != ' ')
			return(*a - ' ');
		else	++a;
	}
return(0);
}
E 1
