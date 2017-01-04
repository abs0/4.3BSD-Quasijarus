/*
 * IFCTF Calendar and Time Systems Library
 * International Free Computing Task Force
 *
 * Routine to convert Gregorian date to MJD
 *
 * This version supports a proleptic Gregorian calendar - such support
 * is required for full ISO 8601 dates, and is consistent with the general
 * philosophy of providing mechanism rather than policy.
 */

#ifndef lint
static char sccsid[] = "@(#)gregtomjd.c	1.7 (IFCTF) 2013/01/19";
#endif

#include <ctslcal.h>
#include <calendardefs.h>

#define	MJD_0000_01_01_PG	-678941		/* proleptic Gregorian */

calend_long
gregtomjd(gregdate)
	struct calendar_date *gregdate;
{
	register calend_long mjd;
	register int year, i;
	calend_long fullyear, q;
	int doy;

	__romantomjd_prelim(gregdate, &fullyear, &doy, 1);
	mjd = MJD_0000_01_01_PG;
	q = fullyear / 400;
	mjd += q * GREG400Y;
	year = fullyear - q * 400;
	if (year < 0) {
		year += 400;
		mjd -= GREG400Y;
	}
	if (year < 100) {
		i = 0;
		goto gotbase;
	}
	i = 100;
	mjd += JULIAN_CENTURY;
	if (year >= 200) {
		i = 200;
		mjd += JULIAN_CENTURY - 1;
	}
	if (year >= 300) {
		i = 300;
		mjd += JULIAN_CENTURY - 1;
	}
	if (year == i)
		goto gotyear;
	mjd--;
gotbase:
	year -= i;
	i = year / 4;
	mjd += (calend_long)i * JULIAN_CYCLE;
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
	mjd += doy;
	return(mjd);
}
