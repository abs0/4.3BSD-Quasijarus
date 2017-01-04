h58136
s 00010/00001/00106
d D 5.1 85/06/05 08:44:01 dist 3 2
c Add copyright
e
s 00002/00002/00105
d D 1.2 83/04/28 15:04:49 mckusick 2 1
c convert to work on 4.1c
e
s 00107/00000/00000
d D 1.1 80/10/13 17:30:33 root 1 0
c date and time created 80/10/13 17:30:33 by root
e
u
U
t
T
I 1
D 3
static	char *sccsid = "%W% (Berkeley) %G%";
E 3
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 3
D 2
#include <sys/types.h>
#include <time.h>
E 2
I 2
#include "include.4.1/sys/types.h"
#include "include.4.1/time.h"
E 2
/*
 * Convert a ctime(3) format string into a system format date.
 * Return the date thus calculated.
 *
 * Return -1 if the string is not in ctime format.
 */

/*
 * Offsets into the ctime string to various parts.
 */

#define	E_MONTH		4
#define	E_DAY		8
#define	E_HOUR		11
#define	E_MINUTE	14
#define	E_SECOND	17
#define	E_YEAR		20

time_t unctime(str)
	char *str;
{
	struct tm then;
	char dbuf[30];
	time_t emitl();

	if (strlen(str) != 25)
		str[25] = 0;
	strcpy(dbuf, str);
	dbuf[E_MONTH+3] = 0;
	if ( (then.tm_mon = lookup(&dbuf[E_MONTH])) < 0)
		return(-1);;
	then.tm_mday = atoi(&dbuf[E_DAY]);
	then.tm_hour = atoi(&dbuf[E_HOUR]);
	then.tm_min = atoi(&dbuf[E_MINUTE]);
	then.tm_sec = atoi(&dbuf[E_SECOND]);
	then.tm_year = atoi(&dbuf[E_YEAR]) - 1900;
	return(emitl(&then));
}

static char months[] =
	"JanFebMarAprMayJunJulAugSepOctNovDec";

static
lookup(str)
	char *str;
{
	register char *cp, *cp2;

	for (cp = months, cp2 = str; *cp != 0; cp += 3)
		if (strncmp(cp, cp2, 3) == 0)
			return((cp-months) / 3);
	return(-1);
}
/*
 * Routine to convert a localtime(3) format date back into
 * a system format date.
 *
 *	Use a binary search.
 */

struct tm *localtime();

time_t emitl(dp)
	struct tm *dp;
{
	time_t conv;
	register int i, bit;
	struct tm dcopy;

	dcopy = *dp;
	dp = &dcopy;
	conv = 0;
	for (i = 31; i >= 0; i--) {
		bit = 1 << i;
		conv |= bit;
		if (dcmp(localtime(&conv), dp) > 0)
			conv &= ~bit;
	}
	return(conv);
}

/*
 * Compare two localtime dates, return result.
 */

#define DECIDE(a) \
	if (dp->a > dp2->a) \
		return(1); \
	if (dp->a < dp2->a) \
		return(-1)

static
dcmp(dp, dp2)
	register struct tm *dp, *dp2;
{

	DECIDE(tm_year);
	DECIDE(tm_mon);
	DECIDE(tm_mday);
	DECIDE(tm_hour);
	DECIDE(tm_min);
	DECIDE(tm_sec);
	return(0);
}
E 1
