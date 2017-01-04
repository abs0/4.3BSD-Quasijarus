h10909
s 00007/00001/00026
d D 5.1 85/06/07 23:21:52 kre 3 2
c Add copyright
e
s 00001/00001/00026
d D 1.2 83/07/01 22:51:35 wnj 2 1
c fix includes
e
s 00027/00000/00000
d D 1.1 81/02/10 13:55:31 dlw 1 0
c date and time created 81/02/10 13:55:31 by dlw
e
u
U
t
T
I 1
/*
D 3
char id_idate[] = "%W%";
E 3
I 3
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
 *
I 3
 *	%W%	%G%
 */

/*
E 3
 * return date in numerical form
 *
 * calling sequence:
 *	integer iarray(3)
 *	call idate(iarray)
 * where:
 *	iarray will receive the current date; day, mon, year.
 */

#include <sys/types.h>
D 2
#include <time.h>
E 2
I 2
#include <sys/time.h>
E 2

idate_(iar)
struct { long iday; long imon; long iyer; } *iar;
{
	struct tm *localtime(), *lclt;
	long int time(), t;

	t = time(0);
	lclt = localtime(&t);
	iar->iday = lclt->tm_mday;
	iar->imon = lclt->tm_mon + 1;
	iar->iyer = lclt->tm_year + 1900;
}
E 1
