h17047
s 00001/00001/00083
d D 1.4 2013/01/19 23:30:06 msokolov 4 3
c converted to use calend_long
e
s 00055/00030/00029
d D 1.3 2012/06/23 08:38:03 msokolov 3 2
c revamped once again
e
s 00030/00021/00029
d D 1.2 2012/06/23 06:37:01 msokolov 2 1
c revamped for true ISO 8601
e
s 00050/00000/00000
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
D 2
 * Routine to parse Roman dates in ISO 8601 format
E 2
I 2
D 3
 * Routine to parse Gregorian dates in ISO 8601 format
 *
 * This version supports both the basic format (YYYYMMDD) and
 * the extended format (YYYY-MM-DD), and it also allows '/' or '.'
 * as separators in addition to the standard-prescribed '-'.
 * However, it enforces the following restrictions:
 * - the year must be exactly 4 digits, in range from 0000 to 9999,
 *   inclusive; (see iso8601exp.c for the expanded year range version)
 * - the same separator (or lack thereof) must be used in both
 *   separating positions, i.e., no mix-and-match;
 * - the DD digits must be followed by a non-digit for the parse
 *   to be considered successful.
E 3
I 3
 * Routine to parse Gregorian dates in ISO 8601 format,
 * features controlled by option flags.
E 3
E 2
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <ctype.h>
D 2
#include <strings.h>
#include "ctslcal.h"
E 2
I 2
#include <caldate.h>
I 3
#include <timeparse.h>
E 3
E 2

D 2
parse_iso8601_date(str, date, endp)
E 2
I 2
D 3
parse_iso_yyyymmdd(str, date, endp)
E 2
	char *str, **endp;
E 3
I 3
char *
parse_iso_date(str, date, flags)
	char *str;
E 3
	register struct calendar_date *date;
I 3
	register int flags;
E 3
{
D 2
	register char *cp, *np;
	register int bce = 0;
E 2
I 2
	register char *cp;
	register int sep;
I 3
	int sign;
D 4
	long accum;
E 4
I 4
	calend_long accum;
E 4
E 3
E 2

	cp = str;
D 2
	if (!strncasecmp(cp, "BCE", 3)) {
		cp += 3;
		bce = 1;
	}
	if (!isdigit(*cp))
E 2
I 2
D 3
	if (!isdigit(cp[0]) || !isdigit(cp[1]) || !isdigit(cp[2]) ||
	    !isdigit(cp[3]))
E 2
		return(-1);
D 2
	for (np = cp; isdigit(*cp); cp++)
		;
	date->year = atoi(np);
	if (bce)
		date->year = -date->year + 1;
	if (*cp++ != '-')
		return(-1);
E 2
I 2
	date->year = (cp[0] - '0') * 1000 + (cp[1] - '0') * 100 +
			(cp[2] - '0') * 10 + (cp[3] - '0');
	cp += 4;
	if (*cp == '-' || *cp == '/' || *cp == '.')
E 3
I 3
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
E 3
		sep = *cp++;
D 3
	else
E 3
I 3
		break;
	default:
		if (!(flags & DATE_ALLOW_NOSEP))
			return (0);
E 3
		sep = 0;
I 3
	}
E 3
E 2
	if (!isdigit(cp[0]) || !isdigit(cp[1]))
D 3
		return(-1);
E 3
I 3
		return (0);
E 3
D 2
	date->month = atoi(cp);
E 2
I 2
	date->month = (cp[0] - '0') * 10 + (cp[1] - '0');
I 3
	if (date->month < 1 || date->month > 12)
		return (0);
E 3
E 2
	cp += 2;
D 2
	if (*cp++ != '-')
E 2
I 2
	if (sep && *cp++ != sep)
E 2
D 3
		return(-1);
E 3
I 3
		return (0);
E 3
	if (!isdigit(cp[0]) || !isdigit(cp[1]))
D 3
		return(-1);
E 3
I 3
		return (0);
E 3
D 2
	date->day = atoi(cp);
E 2
I 2
	date->day = (cp[0] - '0') * 10 + (cp[1] - '0');
I 3
	if (date->day < 1 || date->day > 31)
		return (0);
E 3
E 2
	cp += 2;
I 2
D 3
	if (isdigit(*cp))
		return(-1);
E 2
	if (endp)
		*endp = cp;
	return(0);
E 3
I 3
	if (flags & PARSE_REQ_TERM && *cp)
		return (0);
	else
		return (cp);
E 3
}
E 1
