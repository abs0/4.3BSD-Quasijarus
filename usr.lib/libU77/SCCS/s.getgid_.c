h45453
s 00007/00001/00015
d D 5.1 85/06/07 23:18:56 kre 2 1
c Add copyright
e
s 00016/00000/00000
d D 1.1 81/02/19 09:23:25 dlw 1 0
c date and time created 81/02/19 09:23:25 by dlw
e
u
U
t
T
I 1
/*
D 2
char id_getgid[] = "%W%";
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
 * get group id
 *
 * calling sequence:
 *	integer getgid, gid
 *	gid = getgid()
 * where:
 *	gid will be the real group id
 */

long getgid_()
{
	return((long)getgid());
}
E 1
