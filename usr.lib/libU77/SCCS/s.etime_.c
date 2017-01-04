h28216
s 00007/00001/00031
d D 5.1 85/06/07 23:13:15 kre 2 1
c Add copyright
e
s 00032/00000/00000
d D 1.1 81/02/11 22:16:05 dlw 1 0
c date and time created 81/02/11 22:16:05 by dlw
e
u
U
t
T
I 1
/*
D 2
char id_etime[] = "%W%";
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
 * Return the elapsed execution time for this process.
 *
 * calling sequence:
 * 	real time(2)
 * 	call etime (time)
 * where:
 * 	the 2 element array, time, will receive the user and system
 * 	elapsed time since the start of execution.
 *
 *	This routine can be called as function, and returns the sum of
 *	user and system times. The time array argument must always be given.
 *
 *	The resolution for all timing is 1/60 second.
 */

#include <sys/types.h>
#include <sys/times.h>

struct tb { float usrtime; float systime; };

float
etime_(et) struct tb *et;
{	struct tms clock;

	times(&clock);
	et->usrtime = (float) clock.tms_utime / 60.0;
	et->systime = (float) clock.tms_stime / 60.0;
	return(et->usrtime + et->systime);
}
E 1
