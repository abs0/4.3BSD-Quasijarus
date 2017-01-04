/*
 * IFCTF Calendar and Time Systems Library
 * International Free Computing Task Force
 *
 * Julian calendar to MJD conversion
 */

#ifndef lint
static char sccsid[] = "@(#)juliantomjd.c	1.2 (IFCTF) 2013/01/19";
#endif

#include <ctslcal.h>
#include <calendardefs.h>

#define	JULIAN_0000_01_01	-678943

calend_long
juliantomjd(jdate)
	struct calendar_date *jdate;
{
	register calend_long mjd;
	calend_long fullyear, q;
	int doy;

	__romantomjd_prelim(jdate, &fullyear, &doy, 0);
	q = fullyear >> 2;
	mjd = JULIAN_0000_01_01 + q * 1461;
	switch ((int)fullyear & 3) {
	case 3:
		mjd += 365;
		/* FALL THRU */
	case 2:
		mjd += 365;
		/* FALL THRU */
	case 1:
		mjd += 366;
	}
	mjd += doy;
	return mjd;
}
