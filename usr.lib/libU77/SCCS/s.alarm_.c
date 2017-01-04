h13738
s 00007/00001/00031
d D 5.1 85/06/07 23:10:56 kre 2 1
c Add copyright
e
s 00032/00000/00000
d D 1.1 82/01/07 12:19:43 dlw 1 0
c date and time created 82/01/07 12:19:43 by dlw
e
u
U
t
T
I 1
/*
D 2
char id_alarm[] = "%W%";
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
 * set an alarm time, arrange for user specified action, and return.
 *
 * calling sequence:
 *	integer	flag
 *	external alfunc
 *	lastiv = alarm (intval, alfunc)
 * where:
 *	intval	= the alarm interval in seconds; 0 turns off the alarm.
 *	alfunc	= the function to be called after the alarm interval,
 *
 *	The returned value will be the time remaining on the last alarm.
 */

#include <signal.h>

long alarm_(sec, proc)
long	*sec;
int	(* proc)();
{
	register long	lt;

	lt = alarm(1000);	/* time to maneuver */

	if (*sec)
		signal(SIGALRM, proc);

	alarm(*sec);
	return(lt);
}
E 1
