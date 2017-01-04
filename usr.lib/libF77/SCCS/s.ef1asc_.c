h47137
s 00005/00001/00014
d D 5.1 85/06/07 21:53:54 kre 2 1
c Add copyright
e
s 00015/00000/00000
d D 1.1 83/01/21 11:12:06 dlw 1 0
c date and time created 83/01/21 11:12:06 by dlw
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

/* EFL support routine to copy string b to string a */

#define M	( (long) (sizeof(long) - 1) )
#define EVEN(x)	( ( (x)+ M) & (~M) )

ef1asc_(a, la, b, lb)
int *a, *b;
long int *la, *lb;
{
s_copy( (char *)a, (char *)b, EVEN(*la), *lb );
}
E 1
