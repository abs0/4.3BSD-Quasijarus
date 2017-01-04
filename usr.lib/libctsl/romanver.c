/*
 * IFCTF Calendar and Time Systems Library
 * International Free Computing Task Force
 *
 * Roman calendar date validation
 */

#ifndef lint
static char sccsid[] = "@(#)romanver.c	1.7 (IFCTF) 2012/06/23";
#endif

#include <caldate.h>

static int months_nonl[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static int months_leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

roman_date_valid(date, isgreg)
	register struct calendar_date *date;
	int isgreg;
{
	register int *mt;

	if (date->month < 1 || date->month > 12 || date->day < 1)
		return(0);
#if 0
	if (isgreg) {
		if (date->year < 1582)
			return(0);
		if (date->year == 1582) {
			if (date->month < 10)
				return(0);
			if (date->month == 10 && date->day < 15)
				return(0);
		}
	}
#endif
	if (roman_year_bissextile(date->year, isgreg))
		mt = months_leap;
	else
		mt = months_nonl;
	if (date->day > mt[date->month - 1])
		return(0);
	/* all checks passed! */
	return(1);
}
