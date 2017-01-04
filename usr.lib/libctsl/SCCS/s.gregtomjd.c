h64656
s 00007/00007/00069
d D 1.7 2013/01/19 23:30:07 msokolov 7 6
c converted to use calend_long
e
s 00009/00014/00067
d D 1.6 2012/06/23 05:22:52 msokolov 6 5
c new design for CTSL2
e
s 00001/00001/00080
d D 1.5 2012/06/23 03:45:18 msokolov 5 4
c bugfix
e
s 00023/00023/00058
d D 1.4 2012/06/22 22:55:57 msokolov 4 3
c proleptic Gregorian calendar support a la ISO 8601
e
s 00008/00008/00073
d D 1.3 2012/06/22 05:58:28 msokolov 3 2
c first round of fixes for CTSL2
e
s 00003/00003/00078
d D 1.2 05/08/26 19:20:39 msokolov 2 1
c added __ in front of roman_months_com and roman_months_bis
e
s 00081/00000/00000
d D 1.1 05/07/28 05:20:38 msokolov 1 0
c started SCCS
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
 * Routine to convert Gregorian date to MJD
I 4
 *
 * This version supports a proleptic Gregorian calendar - such support
 * is required for full ISO 8601 dates, and is consistent with the general
 * philosophy of providing mechanism rather than policy.
E 4
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

D 3
#include "ctslcal.h"
#include "calendardefs.h"
E 3
I 3
#include <ctslcal.h>
#include <calendardefs.h>
E 3

I 4
#define	MJD_0000_01_01_PG	-678941		/* proleptic Gregorian */

E 4
D 2
extern int roman_months_com[], roman_months_bis[];
E 2
I 2
D 6
extern int __roman_months_com[], __roman_months_bis[];
E 2

E 6
D 7
long
E 7
I 7
calend_long
E 7
gregtomjd(gregdate)
D 6
	register struct calendar_date *gregdate;
E 6
I 6
	struct calendar_date *gregdate;
E 6
{
D 7
	register long mjd;
E 7
I 7
	register calend_long mjd;
E 7
D 6
	register int year, i, *mt;
E 6
I 6
	register int year, i;
D 7
	long fullyear, q;
E 7
I 7
	calend_long fullyear, q;
E 7
	int doy;
E 6

I 6
	__romantomjd_prelim(gregdate, &fullyear, &doy, 1);
E 6
D 4
	mjd = GREG_START_MJD - 31 - 28 - 31 - 30 - 31 - 30 - 31 - 31 - 30 - 14;
D 3
	year = gregdate->year;
	if (year >= 2000) {
		i = (year - 1600) / 400;
E 3
I 3
	if (gregdate->year >= 2000) {
		i = (gregdate->year - 1600) / 400;
E 3
		mjd += i * GREG400Y;
D 3
		year -= i * 400;
	}
E 3
I 3
		year = gregdate->year - (long)i * 400;
	} else
		year = gregdate->year;
E 3
	i = 1582;
	if (year == i)
		goto gotyear;
	i++;
	mjd += 365;
	if (year == i)
		goto gotyear;
	i++;
	mjd += 365;
	if (year < 1700)
E 4
I 4
	mjd = MJD_0000_01_01_PG;
D 6
	i = gregdate->year / 400;
	mjd += i * GREG400Y;
	year = gregdate->year - (long)i * 400;
E 6
I 6
	q = fullyear / 400;
	mjd += q * GREG400Y;
	year = fullyear - q * 400;
E 6
	if (year < 0) {
		year += 400;
D 5
		mjd += GREG400Y;
E 5
I 5
		mjd -= GREG400Y;
E 5
	}
	if (year < 100) {
		i = 0;
E 4
		goto gotbase;
D 4
	i = 1700;
D 3
	mjd += (365 * 3 + 366) * 29;
E 3
I 3
	mjd += (long) (365 * 3 + 366) * 29;
E 3
	if (year >= 1800) {
		i = 1800;
E 4
I 4
	}
	i = 100;
D 7
	mjd += (long) (365 * 3 + 366) * 25;
E 7
I 7
	mjd += JULIAN_CENTURY;
E 7
	if (year >= 200) {
		i = 200;
E 4
D 7
		mjd += (long) (365 * 3 + 366) * 25 - 1;
E 7
I 7
		mjd += JULIAN_CENTURY - 1;
E 7
	}
D 4
	if (year >= 1900) {
		i = 1900;
E 4
I 4
	if (year >= 300) {
		i = 300;
E 4
D 7
		mjd += (long) (365 * 3 + 366) * 25 - 1;
E 7
I 7
		mjd += JULIAN_CENTURY - 1;
E 7
	}
	if (year == i)
		goto gotyear;
	mjd--;
gotbase:
	year -= i;
	i = year / 4;
D 7
	mjd += i * (long) (365 * 3 + 366);
E 7
I 7
	mjd += (calend_long)i * JULIAN_CYCLE;
E 7
	year -= i * 4;
	if (year) {
		year--;
		mjd += 366;
	}
	if (year) {
		year--;
		mjd += 365;
	}
	if (year) {
		year--;
		mjd += 365;
	}
gotyear:
D 6
	if (roman_year_bissextile(gregdate->year, 1))
D 2
		mt = roman_months_bis;
E 2
I 2
		mt = __roman_months_bis;
E 2
	else
D 2
		mt = roman_months_com;
E 2
I 2
		mt = __roman_months_com;
E 2
	for (i = 1; i < gregdate->month; i++)
		mjd += *mt++;
	mjd += gregdate->day - 1;
E 6
I 6
	mjd += doy;
E 6
	return(mjd);
}
E 1
