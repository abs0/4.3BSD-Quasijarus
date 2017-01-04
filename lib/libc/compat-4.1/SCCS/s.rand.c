h59964
s 00002/00002/00020
d D 5.2 86/03/09 19:23:40 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00010/00001/00012
d D 5.1 85/05/30 10:28:28 dist 2 1
c Add copyright
e
s 00013/00000/00000
d D 4.1 80/12/21 16:40:01 wnj 1 0
c date and time created 80/12/21 16:40:01 by wnj
e
u
U
t
T
I 1
D 2
/* %W% (Berkeley) %G% */
E 2
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 3
#ifndef lint
E 3
I 3
#if defined(LIBC_SCCS) && !defined(lint)
E 3
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif not lint
E 3
I 3
#endif LIBC_SCCS and not lint
E 3

E 2
static	long	randx = 1;

srand(x)
unsigned x;
{
	randx = x;
}

rand()
{
	return((randx = randx * 1103515245 + 12345) & 0x7fffffff);
}
E 1
