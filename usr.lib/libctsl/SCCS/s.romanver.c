h12274
s 00004/00003/00041
d D 1.7 2012/06/23 05:42:54 msokolov 7 6
c table of month lengths moved here from romanmonths.c
e
s 00002/00000/00042
d D 1.6 2012/06/23 05:37:48 msokolov 6 5
c allow proleptic Gregorian dates
e
s 00001/00020/00041
d D 1.5 2012/06/23 05:36:24 msokolov 5 4
c roman_year_bissextile() moved to romanleap.c
e
s 00004/00005/00057
d D 1.4 2012/06/22 17:55:44 msokolov 4 3
c Gregorian leap year logic: even more efficient implementation
e
s 00014/00011/00048
d D 1.3 2012/06/22 05:58:31 msokolov 3 2
c first round of fixes for CTSL2
e
s 00003/00003/00056
d D 1.2 05/08/26 19:20:42 msokolov 2 1
c added __ in front of roman_months_com and roman_months_bis
e
s 00059/00000/00000
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
 * Roman calendar date checking functions
E 5
I 5
 * Roman calendar date validation
E 5
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

D 3
#include "ctslcal.h"
E 3
I 3
#include <caldate.h>
E 3

D 2
extern int roman_months_com[], roman_months_bis[];
E 2
I 2
D 7
extern int __roman_months_com[], __roman_months_bis[];
E 7
I 7
static int months_nonl[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static int months_leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
E 7
E 2
D 5

roman_year_bissextile(year, isgreg)
	register int year;
	int isgreg;
{
D 3
	register int isbis;
E 3
I 3
D 4
	register int div25;
E 4
I 4
	register int century;
E 4
E 3

D 3
	isbis = (year % 4) == 0;
	if (isgreg) {
		if (!(year % 100)) {
			isbis = 0;
			if (!(year % 400))
				isbis = 1;
		}
	}
	return(isbis);
E 3
I 3
	if (year & 3)
		return(0);	/* plain non-leap */
	if (!isgreg)
		return(1);	/* Julian leap */
D 4
	year >>= 2;
	div25 = year / 25;
	if (!(div25 & 3))
E 4
I 4
	century = year / 100;
	if (!(century & 3))
E 4
		return(1);	/* 400 y: can't be a century non-leap */
D 4
	else if (div25 * 25 == year)
E 4
I 4
	else if (century * 100 == year)
E 4
		return(0);	/* Gregorian century non-leap */
	else
		return(1);	/* ordinary Gregorian leap year */
E 3
}
E 5

roman_date_valid(date, isgreg)
	register struct calendar_date *date;
	int isgreg;
{
	register int *mt;

	if (date->month < 1 || date->month > 12 || date->day < 1)
		return(0);
I 6
#if 0
E 6
	if (isgreg) {
		if (date->year < 1582)
			return(0);
		if (date->year == 1582) {
			if (date->month < 10)
				return(0);
			if (date->month == 10 && date->day < 15)
				return(0);
		}
	}
I 6
#endif
E 6
	if (roman_year_bissextile(date->year, isgreg))
D 2
		mt = roman_months_bis;
E 2
I 2
D 7
		mt = __roman_months_bis;
E 7
I 7
		mt = months_leap;
E 7
E 2
	else
D 2
		mt = roman_months_com;
E 2
I 2
D 7
		mt = __roman_months_com;
E 7
I 7
		mt = months_nonl;
E 7
E 2
	if (date->day > mt[date->month - 1])
		return(0);
	/* all checks passed! */
	return(1);
}
E 1
