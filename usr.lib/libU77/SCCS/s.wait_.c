h03116
s 00007/00001/00026
d D 5.1 85/06/07 23:31:49 kre 2 1
c Add copyright
e
s 00027/00000/00000
d D 1.1 81/02/19 18:13:45 dlw 1 0
c date and time created 81/02/19 18:13:45 by dlw
e
u
U
t
T
I 1
/*
D 2
char id_wait[] = "%W%";
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
 * wait for a child to die
 *
 * calling sequence:
 *	integer wait, status, chilid
 *	chilid = wait(status)
 * where:
 *	chilid will be	- >0 if child process id
 *			- <0 if (negative of) system error code
 *	status will contain the exit status of the child
 *		(see wait(2))
 */

extern int errno;

long wait_(status)
long *status;
{
	int stat;
	int chid = wait(&stat);
	if (chid < 0)
		return((long)(-errno));
	*status = (long)stat;
	return((long)chid);
}
E 1
