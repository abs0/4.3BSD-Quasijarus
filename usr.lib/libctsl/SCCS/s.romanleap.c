h12181
s 00006/00004/00025
d D 1.2 2013/01/19 23:30:10 msokolov 2 1
c converted to use calend_long
e
s 00029/00000/00000
d D 1.1 2012/06/23 05:35:30 msokolov 1 0
c split from romanver.c
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
 * Roman calendar leap year checking function
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

I 2
#include <caldate.h>	/* for calend_long */

E 2
roman_year_bissextile(year, isgreg)
D 2
	register int year;
E 2
I 2
	register calend_long year;
E 2
	int isgreg;
{
D 2
	register int century;
E 2
I 2
	register calend_long century;
E 2

D 2
	if (year & 3)
E 2
I 2
	if ((int)year & 3)
E 2
		return(0);	/* plain non-leap */
	if (!isgreg)
		return(1);	/* Julian leap */
	century = year / 100;
D 2
	if (!(century & 3))
E 2
I 2
	if (!((int)century & 3))
E 2
		return(1);	/* 400 y: can't be a century non-leap */
	else if (century * 100 == year)
		return(0);	/* Gregorian century non-leap */
	else
		return(1);	/* ordinary Gregorian leap year */
}
E 1
