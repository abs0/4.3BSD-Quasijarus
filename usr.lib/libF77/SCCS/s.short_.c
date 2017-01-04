h49185
s 00005/00001/00017
d D 5.1 85/06/07 22:36:51 kre 2 1
c Add copyright
e
s 00018/00000/00000
d D 1.1 83/01/21 12:33:31 dlw 1 0
c date and time created 83/01/21 12:33:31 by dlw
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

/*
 * convert long ints to short.
 *
 * used as follows:
 *	integer*2 short
 *	...
 *	call mysub(short(ivar))
 * where:
 *	mysub expects to receive an integer*2 arg and ivar is integer*4
 */

short short_(i)
long *i;
{	return((short)*i);	}
E 1
