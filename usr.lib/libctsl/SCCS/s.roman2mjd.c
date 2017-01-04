h23352
s 00002/00002/00042
d D 1.2 2013/01/19 23:30:13 msokolov 2 1
c converted to use calend_long
e
s 00044/00000/00000
d D 1.1 2012/06/23 05:21:51 msokolov 1 0
c date and time created 2012/06/23 05:21:51 by msokolov
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
 * Some common code and tables used by gregtomjd() and juliantomjd()
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <caldate.h>

static int montodoyn[12] =
	{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
static int montodoyl[12] =
	{0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};

__romantomjd_prelim(date, yrtn, doyrtn, isgreg)
	register struct calendar_date *date;
D 2
	long *yrtn;
E 2
I 2
	calend_long *yrtn;
E 2
	int *doyrtn;
{
	register int q, m, *mt;
D 2
	register long year;
E 2
I 2
	register calend_long year;
E 2

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
E 1
