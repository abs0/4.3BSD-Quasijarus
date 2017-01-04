h51630
s 00005/00005/00054
d D 1.2 2013/01/19 23:30:12 msokolov 2 1
c converted to use calend_long
e
s 00059/00000/00000
d D 1.1 2012/06/23 05:21:50 msokolov 1 0
c date and time created 2012/06/23 05:21:50 by msokolov
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
 * A new mjdtojulian() implementation that works
 * exactly like the new mjdtogreg().
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
#include <calendardefs.h>
#include <ctslcal.h>
#include "doylut.h"

#define	JULIAN_1860_03_01	482

mjdtojulian(mjd, date)
D 2
	long mjd;
E 2
I 2
	calend_long mjd;
E 2
	struct calendar_date *date;
{
D 2
	register long cycles;
E 2
I 2
	register calend_long cycles;
E 2
	register int year, day;

D 2
	cycles = mjd / 1461L;
	day = mjd - cycles * 1461L;
E 2
I 2
	cycles = mjd / JULIAN_CYCLE;
	day = mjd - cycles * JULIAN_CYCLE;
E 2
	/* rebase it from 1858-11-05 (MJD 0 in Julian) to 1860-03-01 */
	day -= JULIAN_1860_03_01;
	/* fix for possible center division and for the rebase in one swoop */
	while (day < 0) {	/* loop will execute at most twice */
		cycles--;
D 2
		day += 1461;
E 2
I 2
		day += JULIAN_CYCLE;
E 2
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
E 1
