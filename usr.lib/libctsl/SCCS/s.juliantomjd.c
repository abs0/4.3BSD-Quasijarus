h06259
s 00003/00003/00037
d D 1.2 2013/01/19 23:30:11 msokolov 2 1
c converted to use calend_long
e
s 00040/00000/00000
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
 * Julian calendar to MJD conversion
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <ctslcal.h>
#include <calendardefs.h>

#define	JULIAN_0000_01_01	-678943

D 2
long
E 2
I 2
calend_long
E 2
juliantomjd(jdate)
	struct calendar_date *jdate;
{
D 2
	register long mjd;
	long fullyear, q;
E 2
I 2
	register calend_long mjd;
	calend_long fullyear, q;
E 2
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
E 1
