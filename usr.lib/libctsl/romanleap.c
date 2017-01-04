/*
 * IFCTF Calendar and Time Systems Library
 * International Free Computing Task Force
 *
 * Roman calendar leap year checking function
 */

#ifndef lint
static char sccsid[] = "@(#)romanleap.c	1.2 (IFCTF) 2013/01/19";
#endif

#include <caldate.h>	/* for calend_long */

roman_year_bissextile(year, isgreg)
	register calend_long year;
	int isgreg;
{
	register calend_long century;

	if ((int)year & 3)
		return(0);	/* plain non-leap */
	if (!isgreg)
		return(1);	/* Julian leap */
	century = year / 100;
	if (!((int)century & 3))
		return(1);	/* 400 y: can't be a century non-leap */
	else if (century * 100 == year)
		return(0);	/* Gregorian century non-leap */
	else
		return(1);	/* ordinary Gregorian leap year */
}
