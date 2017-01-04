h00885
s 00006/00005/00095
d D 1.4 2012/06/22 05:58:29 msokolov 4 3
c first round of fixes for CTSL2
e
s 00013/00012/00087
d D 1.3 2011/08/05 07:15:17 msokolov 3 2
c MJD to Roman conversion: off-by-one bug for Dec31 of leap years
e
s 00005/00005/00094
d D 1.2 05/08/26 19:20:40 msokolov 2 1
c added __ in front of roman_months_com and roman_months_bis
e
s 00099/00000/00000
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
 * Julian calendar linearization functions
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

D 4
#include "ctslcal.h"
#include "calendardefs.h"
E 4
I 4
#include <ctslcal.h>
#include <calendardefs.h>
E 4

D 2
extern int roman_months_com[], roman_months_bis[];
E 2
I 2
extern int __roman_months_com[], __roman_months_bis[];
E 2

long
linearize_julian_date(jdate)
	register struct calendar_date *jdate;
{
	register long lday;
	register int i, *mt;

	i = jdate->year;
	while (i % 4)
		i--;
D 4
	lday = (i / 4) * 1461;
E 4
I 4
	lday = (i / 4) * 1461L;
E 4
	i = jdate->year - i;
	switch (i) {
	case 0:
D 2
		mt = roman_months_bis;
E 2
I 2
		mt = __roman_months_bis;
E 2
		break;
	case 3:
		lday += 365;
		/* FALL THRU */
	case 2:
		lday += 365;
		/* FALL THRU */
	case 1:
D 2
		mt = roman_months_com;
E 2
I 2
		mt = __roman_months_com;
E 2
		lday += 366;
	}
	for (i = 1; i < jdate->month; i++)
		lday += *mt++;
	lday += jdate->day - 1;
	return(lday);
}

long
juliantomjd(jdate)
	struct calendar_date *jdate;
{
	return(linearize_julian_date(jdate) - JCLD_MJD_OFFSET);
}

delinearize_julian_date(linear, date)
	long linear;
	register struct calendar_date *date;
{
	register int i, j, *mt;

D 4
	i = linear / 1461;
	j = linear - i * 1461;
E 4
I 4
	i = linear / 1461L;
	j = linear - i * 1461L;
E 4
	/* C does not guarantee center or floor division */
	if (j < 0) {
		i--;
		j += 1461;
	}
	date->year = i * 4;
D 3
	if (j >= 366) {
		date->year++;
		j -= 366;
	}
	if (j >= 365) {
		date->year++;
		j -= 365;
	}
	if (j >= 365) {
		date->year++;
		j -= 365;
	}
E 3
I 3
	if (j < 366)
		goto gotyear;
	date->year++;
	j -= 366;
	if (j < 365)
		goto gotyear;
	date->year++;
	j -= 365;
	if (j < 365)
		goto gotyear;
	date->year++;
	j -= 365;
gotyear:
I 4
	date->doy = j;
E 4
E 3
	if (date->year % 4)
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
	for (i = 1; j >= *mt; i++, mt++)
		j -= *mt;
	date->day = j + 1;
	date->month = i;
	return(0);
}

mjdtojulian(mjd, jdate)
	long mjd;
	struct calendar_date *jdate;
{
	delinearize_julian_date(mjd + JCLD_MJD_OFFSET, jdate);
	return(0);
}
E 1
