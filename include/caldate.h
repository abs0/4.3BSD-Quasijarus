/*
 * IFCTF Calendar and Time Systems Library
 * International Free Computing Task Force
 *
 * Generic calendar date structure definition
 *
 *	@(#)caldate.h	1.2 (IFCTF) 2013/01/19
 */

#ifndef _CALDATE_
#define	_CALDATE_

/* calend_long is defined in mjdtime.h too; look there for the explanation */
#ifndef calend_long
#define	calend_long	long
#endif

/*
 * Whatever numbers they use, virtually all human calendars have years,
 * months and days.  The following structure reflects this.
 */
struct calendar_date {
	calend_long	year;
	int		month;
	int		day;
	int		doy;	/* day of year */
};

#endif
