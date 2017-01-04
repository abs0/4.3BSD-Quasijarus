h40752
s 00002/00002/00035
d D 5.2 86/03/09 20:00:55 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00028
d D 5.1 85/06/05 12:42:53 mckusick 2 1
c Add copyright
e
s 00029/00000/00000
d D 1.1 85/03/14 17:52:57 serge 1 0
c date and time created 85/03/14 17:52:57 by serge
e
u
U
t
T
I 1
D 2
/* %W%	(Berkeley)	%G% */
E 2
I 2
/*
 * Copyright (c) 1985 Regents of the University of California.
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

#include <sys/time.h>

#define	USPS	1000000		/* # of microseconds in a second */

/*
 * Generate a SIGALRM signal in ``usecs'' microseconds.
 * If ``reload'' is non-zero, keep generating SIGALRM
 * every ``reload'' microseconds after the first signal.
 */
unsigned
ualarm(usecs, reload)
	register unsigned usecs;
	register unsigned reload;
{
	struct itimerval new, old;

	new.it_interval.tv_usec = reload % USPS;
	new.it_interval.tv_sec = reload / USPS;
	
	new.it_value.tv_usec = usecs % USPS;
	new.it_value.tv_sec = usecs / USPS;

	if (setitimer(ITIMER_REAL, &new, &old) == 0)
		return (old.it_value.tv_sec * USPS + old.it_value.tv_usec);
	/* else */
		return (-1);
}
E 1
