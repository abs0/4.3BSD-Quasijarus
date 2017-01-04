h30226
s 00016/00001/00026
d D 1.3 2012/06/20 18:34:39 msokolov 3 2
c brave Quasijarus extension
e
s 00009/00001/00018
d D 1.2 87/03/04 17:28:35 bostic 2 1
c added Robert Elz's additions for new time package
e
s 00019/00000/00000
d D 1.1 85/03/13 16:30:25 mckusick 1 0
c date and time created 85/03/13 16:30:25 by mckusick
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
/*
 * Copyright (c) 1983, 1987 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
D 3
 *	%W% (Berkeley) %G%
E 3
I 3
 *	%W% (Berkeley) %E%
E 3
 */
E 2

I 3
#ifndef _STRUCT_TM_
#define	_STRUCT_TM_

E 3
/*
 * Structure returned by gmtime and localtime calls (see ctime(3)).
 */
struct tm {
I 3
	/* original UNIX fields */
E 3
	int	tm_sec;
	int	tm_min;
	int	tm_hour;
	int	tm_mday;
	int	tm_mon;
	int	tm_year;
	int	tm_wday;
	int	tm_yday;
	int	tm_isdst;
I 3
	/* 4.3-Tahoe (Olson & Elz) additions */
E 3
I 2
	long	tm_gmtoff;
	char	*tm_zone;
I 3
	/* Quasijarus additions */
	long	tm_mjd;
	int	tm_flags;
	long	tm_altcalendar[4];
E 3
E 2
};

I 3
/* tm_flags bits */
#define	__TM_HAS_LEGACY_DATE	1
#define	__TM_HAS_TRC_DATE	2

E 3
extern	struct tm *gmtime(), *localtime();
extern	char *asctime(), *ctime();
I 3

#endif
E 3
E 1
