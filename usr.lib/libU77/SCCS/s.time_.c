h48086
s 00007/00001/00017
d D 5.1 85/06/07 23:30:26 kre 2 1
c Add copyright
e
s 00018/00000/00000
d D 1.1 81/02/18 21:48:38 dlw 1 0
c date and time created 81/02/18 21:48:38 by dlw
e
u
U
t
T
I 1
/*
D 2
char id_time[] = "%W%";
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
 * return the current time as an integer
 *
 * calling sequence:
 *	integer time
 *	i = time()
 * where:
 *	i will receive the current GMT in seconds.
 */

long time();

long time_()
{
	return(time(0));
}
E 1
