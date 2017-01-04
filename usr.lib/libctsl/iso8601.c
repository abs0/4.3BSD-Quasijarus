/*
 * IFCTF Calendar and Time Systems Library
 * International Free Computing Task Force
 *
 * Routine to parse Gregorian dates in ISO 8601 format,
 * features controlled by option flags.
 */

#ifndef lint
static char sccsid[] = "@(#)iso8601.c	1.4 (IFCTF) 2013/01/19";
#endif

#include <ctype.h>
#include <caldate.h>
#include <timeparse.h>

char *
parse_iso_date(str, date, flags)
	char *str;
	register struct calendar_date *date;
	register int flags;
{
	register char *cp;
	register int sep;
	int sign;
	calend_long accum;

	cp = str;
	if (flags & DATE_ALLOW_EXPYEAR) {
		if (*cp == '+' || *cp == '-')
			sign = *cp++;
		else
			sign = '+';
		if (!isdigit(*cp))
			return (0);
		for (accum = sep = 0; isdigit(*cp); sep++) {
			if (sep >= 7)
				return (0);
			accum = accum * 10 + (*cp++ - '0');
		}
		if (sign == '-')
			accum = -accum;
		date->year = accum;
	} else {
		if (!isdigit(cp[0]) || !isdigit(cp[1]) || !isdigit(cp[2]) ||
		    !isdigit(cp[3]))
			return (0);
		date->year = (cp[0] - '0') * 1000 + (cp[1] - '0') * 100 +
				(cp[2] - '0') * 10 + (cp[3] - '0');
		cp += 4;
	}
	switch (*cp) {
	case '/':
	case '.':
		if (!(flags & DATE_ALLOW_ALTSEP))
			return (0);
		/* FALL THRU */
	case '-':
		sep = *cp++;
		break;
	default:
		if (!(flags & DATE_ALLOW_NOSEP))
			return (0);
		sep = 0;
	}
	if (!isdigit(cp[0]) || !isdigit(cp[1]))
		return (0);
	date->month = (cp[0] - '0') * 10 + (cp[1] - '0');
	if (date->month < 1 || date->month > 12)
		return (0);
	cp += 2;
	if (sep && *cp++ != sep)
		return (0);
	if (!isdigit(cp[0]) || !isdigit(cp[1]))
		return (0);
	date->day = (cp[0] - '0') * 10 + (cp[1] - '0');
	if (date->day < 1 || date->day > 31)
		return (0);
	cp += 2;
	if (flags & PARSE_REQ_TERM && *cp)
		return (0);
	else
		return (cp);
}
