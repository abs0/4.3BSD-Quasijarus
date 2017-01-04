h02810
s 00009/00004/00020
d D 1.2 2013/01/19 21:39:22 msokolov 2 1
c changes for calend_long
e
s 00024/00000/00000
d D 1.1 2012/06/22 04:29:37 msokolov 1 0
c date and time created 2012/06/22 04:29:37 by msokolov
e
u
U
t
T
I 1
/*
 * IFCTF Calendar and Time Systems Library
 * International Free Computing Task Force
 *
 * Generic calendar date structure definition
 *
 *	%W% (IFCTF) %E%
 */

#ifndef _CALDATE_
#define	_CALDATE_

I 2
/* calend_long is defined in mjdtime.h too; look there for the explanation */
#ifndef calend_long
#define	calend_long	long
#endif

E 2
/*
 * Whatever numbers they use, virtually all human calendars have years,
 * months and days.  The following structure reflects this.
 */
struct calendar_date {
D 2
	long	year;
	int	month;
	int	day;
	int	doy;	/* day of year */
E 2
I 2
	calend_long	year;
	int		month;
	int		day;
	int		doy;	/* day of year */
E 2
};

#endif
E 1
