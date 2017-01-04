/*
 * IFCTF Calendar and Time Systems Library
 * International Free Computing Task Force
 *
 * Routine to convert MJD to Gregorian date, extended to
 * handle proleptic Gregorian dates as well.  One can pass
 * every possible value of the long int type used for the MJD,
 * and this routine will produce the correct Gregorian date
 * (official or proleptic) for that MJD number.
 *
 * I have replaced my original algorithm with a variant inspired
 * by djb's MJD->Gregorian function from libtai-0.60.
 */

#ifndef lint
static char sccsid[] = "@(#)mjdtogreg.c	1.6 (IFCTF) 2013/01/19";
#endif

#include <sys/types.h>
#include <ctslcal.h>
#include <calendardefs.h>
#include "doylut.h"

#define	MJD_2000_03_01	51604

mjdtogreg(mjd, date)
	calend_long mjd;
	struct calendar_date *date;
{
	register calend_long day, big_cycles;
	register int year, quot;

	big_cycles = mjd / GREG400Y;
	day = mjd - big_cycles * GREG400Y;
	/* rebase it from 1858-11-17 to 2000-03-01 */
	day -= MJD_2000_03_01;
	/* fix for possible center division and for the rebase in one swoop */
	while (day < 0) {	/* loop will execute at most twice */
		big_cycles--;
		day += GREG400Y;
	}

	if (day == (GREG400Y - 1)) {
		year = 399;
		day = 365;
	} else {
		quot = day / (JULIAN_CENTURY - 1);
		year = quot * 100;
		day -= quot * (JULIAN_CENTURY - 1);
		quot = day / JULIAN_CYCLE;
		year += quot * 4;
		day -= (calend_long)quot * JULIAN_CYCLE;
		if (day == 1460) {
			year += 3;
			day = 365;
		} else {
			quot = (int)day / 365;
			year += quot;
			day -= quot * 365;
		}
	}

	date->month = __roman_doy_lut[day].month;
	date->day = __roman_doy_lut[day].day;
	if (day >= MAR_THRU_DEC) {
		year++;
		day -= MAR_THRU_DEC;
	} else {
		if (year & 3 || year == 100 || year == 200 || year == 300)
			day += (31 + 28);
		else
			day += (31 + 29);
	}
	date->year = 2000 + big_cycles * 400 + year;
	date->doy = day;
	return 0;
}
