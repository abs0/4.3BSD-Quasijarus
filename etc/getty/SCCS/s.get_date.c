h58207
s 00001/00001/00057
d D 5.2 87/10/22 11:11:41 bostic 3 2
c ANSI C; sprintf now returns an int.
e
s 00008/00002/00050
d D 5.1 85/04/29 12:08:03 dist 2 1
c Add copyright
e
s 00052/00000/00000
d D 4.1 85/02/05 08:44:43 ralph 1 0
c date and time created 85/02/05 08:44:43 by ralph
e
u
U
t
T
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 2
I 1
#ifndef lint
D 2
static char sccsid[] = "%W% (Berkeley) %E%";
#endif
E 2
I 2
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 2

#include <stdio.h>
#include <sys/time.h>

static char *days[] = {
	"Sun", "Mon", "Tues", "Wed", "Thurs", "Fri", "Sat"
};

static char *months[] = {
	"Jan", "Feb", "Mar", "Apr", "May", "June",
	"July", "Aug", "Sept", "Oct", "Nov", "Dec"
};

#define AM "am"
#define PM "pm"

get_date(datebuffer)
	char *datebuffer;
{
	struct tm *localtime(), *tmp;
	struct timeval tv;
	int realhour;
	char *zone;

	gettimeofday(&tv, 0);
	tmp = localtime(&tv.tv_sec);

	realhour = tmp->tm_hour;
	zone = AM;			/* default to morning */
	if (tmp->tm_hour == 0)
		realhour = 12;		/* midnight */
	else if (tmp->tm_hour == 12)
		zone = PM;		/* noon */
	else if (tmp->tm_hour >= 13 && tmp->tm_hour <= 23) { /* afternoon */
		realhour = realhour - 12;
		zone = PM;
	}
	
	/* format is '8:10pm on Sunday, 16 Sept 1973' */

D 3
	sprintf(datebuffer, "%d:%02d%s on %s, %d %s %d",
E 3
I 3
	(void)sprintf(datebuffer, "%d:%02d%s on %s, %d %s %d",
E 3
		realhour,
		tmp->tm_min,
		zone,
		days[tmp->tm_wday],
		tmp->tm_mday,
		months[tmp->tm_mon],
		1900 + tmp->tm_year);
}
E 1
