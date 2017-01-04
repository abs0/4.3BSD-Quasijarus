/*
 * IFCTF Calendar and Time Systems Library
 * International Free Computing Task Force
 *
 * Some common code and tables used by gregtomjd() and juliantomjd()
 */

#ifndef lint
static char sccsid[] = "@(#)roman2mjd.c	1.2 (IFCTF) 2013/01/19";
#endif

#include <caldate.h>

static int montodoyn[12] =
	{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
static int montodoyl[12] =
	{0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};

__romantomjd_prelim(date, yrtn, doyrtn, isgreg)
	register struct calendar_date *date;
	calend_long *yrtn;
	int *doyrtn;
{
	register int q, m, *mt;
	register calend_long year;

	m = date->month - 1;
	if (m < 0 || m > 11) {
		q = date->month / 12;
		m = date->month - q * 12 - 1;
		if (m < 0) {
			m += 12;
			q--;
		}
		year = date->year + q;
	} else
		year = date->year;
	*yrtn = year;
	if (roman_year_bissextile(year, isgreg))
		mt = montodoyl;
	else
		mt = montodoyn;
	*doyrtn = mt[m] + date->day - 1;
}
