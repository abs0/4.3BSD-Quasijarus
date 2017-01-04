h08772
s 00007/00001/00023
d D 5.1 85/06/07 23:23:20 kre 2 1
c Add copyright
e
s 00024/00000/00000
d D 1.1 81/02/19 18:57:02 dlw 1 0
c date and time created 81/02/19 18:57:02 by dlw
e
u
U
t
T
I 1
/*
D 2
char id_kill[] = "%W%";
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
 * send a signal to a process
 *
 * calling sequence:
 *	ierror = kill(pid, signum)
 * where:
 *	pid must be the process id of one of the user's processes
 *	signum must be a valid signal number (see signal(2))
 *	ierror will be 0 if successful; an error code otherwise.
 */

#include "../libI77/f_errno.h"

long kill_(pid, signum)
long *pid, *signum;
{
	if (*pid < 0 || *pid > 32767L || *signum < 1 || *signum > 16)
		return((long)(errno=F_ERARG));
	if (kill((int)*pid, (int)*signum) != 0)
		return((long)errno);
	return(0L);
}
E 1
