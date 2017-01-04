/*
 * Copyright (c) 1983, 1987 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)time.h	1.3 (Berkeley) 2012/06/20
 */

#ifndef _STRUCT_TM_
#define	_STRUCT_TM_

/*
 * Structure returned by gmtime and localtime calls (see ctime(3)).
 */
struct tm {
	/* original UNIX fields */
	int	tm_sec;
	int	tm_min;
	int	tm_hour;
	int	tm_mday;
	int	tm_mon;
	int	tm_year;
	int	tm_wday;
	int	tm_yday;
	int	tm_isdst;
	/* 4.3-Tahoe (Olson & Elz) additions */
	long	tm_gmtoff;
	char	*tm_zone;
	/* Quasijarus additions */
	long	tm_mjd;
	int	tm_flags;
	long	tm_altcalendar[4];
};

/* tm_flags bits */
#define	__TM_HAS_LEGACY_DATE	1
#define	__TM_HAS_TRC_DATE	2

extern	struct tm *gmtime(), *localtime();
extern	char *asctime(), *ctime();

#endif
