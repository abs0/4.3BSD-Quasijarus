h48557
s 00007/00001/00015
d D 5.1 85/06/07 23:28:17 kre 2 1
c Add copyright
e
s 00016/00000/00000
d D 1.1 81/02/19 18:12:05 dlw 1 0
c date and time created 81/02/19 18:12:05 by dlw
e
u
U
t
T
I 1
/*
D 2
char id_sleep[] = "%W%";
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
 * sleep for awhile
 *
 * calling sequence:
 *	call sleep(seconds)
 * where:
 *	seconds is an integer number of seconds to sleep (see sleep(3))
 */

sleep_(sec)
long *sec;
{
	sleep((unsigned int)*sec);
}
E 1
