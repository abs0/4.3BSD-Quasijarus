/*
 * IFCTF Calendar and Time Systems Library
 * International Free Computing Task Force
 *
 * A new mjdtojulian() implementation that works
 * exactly like the new mjdtogreg().
 */

#ifndef lint
static char sccsid[] = "@(#)mjdtojulian.c	1.2 (IFCTF) 2013/01/19";
#endif

#include <sys/types.h>
#include <calendardefs.h>
#include <ctslcal.h>
#include "doylut.h"

#define	JULIAN_1860_03_01	482

mjdtojulian(mjd, date)
	calend_long mjd;
	struct calendar_date *date;
{
	register calend_long cycles;
	register int year, day;

	cycles = mjd / JULIAN_CYCLE;
	day = mjd - cycles * JULIAN_CYCLE;
	/* rebase it from 1858-11-05 (MJD 0 in Julian) to 1860-03-01 */
	day -= JULIAN_1860_03_01;
	/* fix for possible center division and for the rebase in one swoop */
	while (day < 0) {	/* loop will execute at most twice */
		cycles--;
		day += JULIAN_CYCLE;
	}

	if (day == 1460) {
		year = 3;
		day = 365;
	} else {
		year = day / 365;
		day -= year * 365;
	}

	date->month = __roman_doy_lut[day].month;
	date->day = __roman_doy_lut[day].day;
	if (day >= MAR_THRU_DEC) {
		year++;
		day -= MAR_THRU_DEC;
	} else {
		if (year)
			day += (31 + 28);
		else
			day += (31 + 29);
	}
	date->year = 1860 + cycles * 4 + year;
	date->doy = day;
	return 0;
}
