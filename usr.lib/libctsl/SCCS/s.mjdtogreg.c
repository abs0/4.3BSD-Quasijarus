h10638
s 00006/00006/00071
d D 1.6 2013/01/19 23:30:08 msokolov 6 5
c converted to use calend_long
e
s 00056/00061/00021
d D 1.5 2012/06/23 05:23:38 msokolov 5 4
c new design for CTSL2
e
s 00008/00003/00074
d D 1.4 2012/06/22 05:58:30 msokolov 4 3
c first round of fixes for CTSL2
e
s 00012/00012/00065
d D 1.3 2011/08/05 07:15:18 msokolov 3 2
c MJD to Roman conversion: off-by-one bug for Dec31 of leap years
e
s 00003/00003/00074
d D 1.2 05/08/26 19:20:41 msokolov 2 1
c added __ in front of roman_months_com and roman_months_bis
e
s 00077/00000/00000
d D 1.1 05/07/28 05:20:39 msokolov 1 0
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
D 5
 * Routine to convert MJD to Gregorian date
E 5
I 5
 * Routine to convert MJD to Gregorian date, extended to
 * handle proleptic Gregorian dates as well.  One can pass
 * every possible value of the long int type used for the MJD,
 * and this routine will produce the correct Gregorian date
 * (official or proleptic) for that MJD number.
 *
 * I have replaced my original algorithm with a variant inspired
 * by djb's MJD->Gregorian function from libtai-0.60.
E 5
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

I 5
#include <sys/types.h>
E 5
D 4
#include "ctslcal.h"
#include "calendardefs.h"
E 4
I 4
#include <ctslcal.h>
#include <calendardefs.h>
I 5
#include "doylut.h"
E 5
E 4

D 2
extern int roman_months_com[], roman_months_bis[];
E 2
I 2
D 5
extern int __roman_months_com[], __roman_months_bis[];
E 5
I 5
#define	MJD_2000_03_01	51604
E 5
E 2

D 5
mjdtogreg(mjd, gregdate)
E 5
I 5
mjdtogreg(mjd, date)
E 5
D 6
	long mjd;
E 6
I 6
	calend_long mjd;
E 6
D 5
	register struct calendar_date *gregdate;
E 5
I 5
	struct calendar_date *date;
E 5
{
D 5
	register long lday;
	register int i;
	register int *mt;
	int extra400s;
E 5
I 5
D 6
	register long day, big_cycles;
E 6
I 6
	register calend_long day, big_cycles;
E 6
	register int year, quot;
E 5

D 5
	if (mjd < GREG_START_MJD)
		return(-1);
	/* make it relative to 1584-01-01 */
	lday = mjd - GREG_START_MJD - 17 - 30 - 31 - 365;
I 4
	if (lday < -730) {
		/* the above addition has caused an overflow! */
		return(-2);
E 5
I 5
	big_cycles = mjd / GREG400Y;
	day = mjd - big_cycles * GREG400Y;
	/* rebase it from 1858-11-17 to 2000-03-01 */
	day -= MJD_2000_03_01;
	/* fix for possible center division and for the rebase in one swoop */
	while (day < 0) {	/* loop will execute at most twice */
		big_cycles--;
		day += GREG400Y;
E 5
	}
E 4
D 5
	if (lday < -365) {
		gregdate->year = 1582;
		lday += 730;
		extra400s = 0;
		goto gotyear;
E 5
I 5

	if (day == (GREG400Y - 1)) {
		year = 399;
		day = 365;
	} else {
D 6
		quot = day / 36524L;
E 6
I 6
		quot = day / (JULIAN_CENTURY - 1);
E 6
		year = quot * 100;
D 6
		day -= quot * 36524L;
		quot = day / 1461L;
E 6
I 6
		day -= quot * (JULIAN_CENTURY - 1);
		quot = day / JULIAN_CYCLE;
E 6
		year += quot * 4;
D 6
		day -= quot * 1461L;
E 6
I 6
		day -= (calend_long)quot * JULIAN_CYCLE;
E 6
		if (day == 1460) {
			year += 3;
			day = 365;
		} else {
			quot = (int)day / 365;
			year += quot;
			day -= quot * 365;
		}
E 5
	}
D 5
	if (lday < 0) {
		gregdate->year = 1583;
		lday += 365;
		extra400s = 0;
		goto gotyear;
E 5
I 5

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
E 5
	}
D 5
	extra400s = lday / GREG400Y;
	lday -= extra400s * GREG400Y;
	if (lday >= 115782)
		lday++;
	if (lday >= 79258)
		lday++;
	if (lday >= 42734)
		lday++;
	i = lday / 1461;	/* 4 years (365 * 3 + 366) */
	gregdate->year = 1584 + i * 4;
	lday -= i * 1461;
D 3
	if (lday >= 366) {
		gregdate->year++;
		lday -= 366;
	}
	if (lday >= 365) {
		gregdate->year++;
		lday -= 365;
	}
	if (lday >= 365) {
		gregdate->year++;
		lday -= 365;
	}
E 3
I 3
	if (lday < 366)
		goto gotyear;
	gregdate->year++;
	lday -= 366;
	if (lday < 365)
		goto gotyear;
	gregdate->year++;
	lday -= 365;
	if (lday < 365)
		goto gotyear;
	gregdate->year++;
	lday -= 365;
E 3
gotyear:
I 4
	gregdate->doy = lday;
E 4
	i = gregdate->year;
	if (i % 4 || i == 1700 || i == 1800 || i == 1900)
D 2
		mt = roman_months_com;
E 2
I 2
		mt = __roman_months_com;
E 2
	else
D 2
		mt = roman_months_bis;
E 2
I 2
		mt = __roman_months_bis;
E 2
	for (i = 1; lday >= *mt; i++, mt++)
		lday -= *mt;
	gregdate->day = lday + 1;
	gregdate->month = i;
D 4
	gregdate->year += extra400s * 400;
E 4
I 4
	gregdate->year += (long)extra400s * 400;
E 4
	return(0);
E 5
I 5
	date->year = 2000 + big_cycles * 400 + year;
	date->doy = day;
	return 0;
E 5
}
E 1
