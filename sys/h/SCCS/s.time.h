h46473
s 00010/00001/00060
d D 7.3 2012/06/16 07:50:53 msokolov 11 10
c Y2038: time_t is now an unsigned long
e
s 00005/00000/00056
d D 7.2 00/04/10 20:33:42 msokolov 10 9
c put in multiple inclusion guards, this header file is far too common
e
s 00001/00001/00055
d D 7.1 86/06/04 23:29:20 mckusick 9 8
c 4.3BSD release version
e
s 00001/00000/00055
d D 6.4 85/06/24 00:11:41 kre 8 7
c Added defn of DST_CAN
e
s 00007/00001/00048
d D 6.3 85/06/08 15:09:32 mckusick 7 6
c Add copyright
e
s 00001/00017/00048
d D 6.2 85/03/13 16:28:34 mckusick 6 5
c break out user part of time.h
e
s 00000/00000/00065
d D 6.1 83/07/29 06:14:20 sam 5 4
c 4.2 distribution
e
s 00004/00001/00061
d D 4.4 83/07/09 14:37:48 sam 4 3
c keep europe happy
e
s 00002/00000/00060
d D 4.3 83/06/10 21:26:21 sam 3 2
c let others know
e
s 00001/00000/00059
d D 4.2 83/05/21 16:02:21 sam 2 1
c bloody australian time zone
e
s 00059/00000/00000
d D 4.1 83/02/10 18:32:26 sam 1 0
c date and time created 83/02/10 18:32:26 by sam
e
u
U
t
T
I 1
D 7
/*	%M%	%I%	%E%	*/
E 7
I 7
/*
D 9
 * Copyright (c) 1982 Regents of the University of California.
E 9
I 9
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
D 11
 *	%W% (Berkeley) %G%
E 11
I 11
 *	%W% (Berkeley) %E%
E 11
 */
E 7

I 10
#ifndef _TIME_
#define	_TIME_

E 10
/*
 * Structure returned by gettimeofday(2) system call,
 * and used in other calls.
 */
struct timeval {
	long	tv_sec;		/* seconds */
	long	tv_usec;	/* and microseconds */
I 11
};

/*
 * Unsigned version of struct timeval created in preparation
 * for the upcoming Y2038 crisis.
 */
struct utimeval {
	unsigned long	tv_sec;
	unsigned long	tv_usec;
E 11
};

struct timezone {
	int	tz_minuteswest;	/* minutes west of Greenwich */
	int	tz_dsttime;	/* type of dst correction */
};
#define	DST_NONE	0	/* not on dst */
D 4
#define	DST_USA		1	/* usa style dst */
E 4
I 4
#define	DST_USA		1	/* USA style dst */
E 4
I 2
#define	DST_AUST	2	/* Australian style dst */
I 4
#define	DST_WET		3	/* Western European dst */
#define	DST_MET		4	/* Middle European dst */
#define	DST_EET		5	/* Eastern European dst */
I 8
#define	DST_CAN		6	/* Canada */
E 8
E 4
E 2

/*
 * Operations on timevals.
I 3
 *
 * NB: timercmp does not work for >= or <=.
E 3
 */
#define	timerisset(tvp)		((tvp)->tv_sec || (tvp)->tv_usec)
#define	timercmp(tvp, uvp, cmp)	\
	((tvp)->tv_sec cmp (uvp)->tv_sec || \
	 (tvp)->tv_sec == (uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#define	timerclear(tvp)		(tvp)->tv_sec = (tvp)->tv_usec = 0

/*
 * Names of the interval timers, and structure
 * defining a timer setting.
 */
#define	ITIMER_REAL	0
#define	ITIMER_VIRTUAL	1
#define	ITIMER_PROF	2

struct	itimerval {
	struct	timeval it_interval;	/* timer interval */
	struct	timeval it_value;	/* current value */
};

D 6
/*
 * Structure returned by gmtime and localtime calls (see ctime(3)).
 */
struct tm {
	int	tm_sec;
	int	tm_min;
	int	tm_hour;
	int	tm_mday;
	int	tm_mon;
	int	tm_year;
	int	tm_wday;
	int	tm_yday;
	int	tm_isdst;
};

E 6
#ifndef KERNEL
D 6
extern	struct tm *gmtime(), *localtime();
extern	char *asctime(), *ctime();
E 6
I 6
#include <time.h>
I 10
#endif

E 10
E 6
#endif
E 1
