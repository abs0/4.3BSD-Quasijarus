h50712
s 00007/00001/00016
d D 5.1 85/06/07 23:22:17 kre 2 1
c Add copyright
e
s 00017/00000/00000
d D 1.1 81/02/18 21:49:27 dlw 1 0
c date and time created 81/02/18 21:49:27 by dlw
e
u
U
t
T
I 1
/*
D 2
char id_ierrno[] = "%W%";
E 2
I 2
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 2
 *
I 2
 *	%W%	%G%
 */

/*
E 2
 * return the current value of the system error register
 *
 * calling sequence:
 *	ier = ierrno()
 * where:
 *	ier will receive the current value of errno
 */

extern int errno;

long ierrno_()
{
	return((long)errno);
}
E 1
