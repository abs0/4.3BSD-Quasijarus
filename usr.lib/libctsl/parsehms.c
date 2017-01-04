/*
 * IFCTF Calendar and Time Systems Library
 * International Free Computing Task Force
 *
 * Routine to parse HH:MM:SS times
 */

#ifndef lint
static char sccsid[] = "@(#)parsehms.c	1.1 (IFCTF) 2012/06/23";
#endif

#include <sys/types.h>
#include <ctype.h>
#include <mjdtime.h>
#include <timeparse.h>

char *
parse_hms_time(str, sexa, flags)
	char *str;
	register struct sexatime *sexa;
	register int flags;
{
	register char *cp;
	register int sep;

	cp = str;
	if (!isdigit(cp[0]) || !isdigit(cp[1]))
		return (0);
	sexa->hh = (cp[0] - '0') * 10 + (cp[1] - '0');
	if (sexa->hh > (flags & TIME_ALLOW_LEAPHOUR ? 24 : 23))
		return (0);
	cp += 2;
	if (*cp == ':') {
		cp++;
		sep = 1;
	} else {
		if (!(flags & TIME_ALLOW_NOSEP))
			return (0);
		sep = 0;
	}
	if (!isdigit(cp[0]) || !isdigit(cp[1]))
		return (0);
	sexa->mm = (cp[0] - '0') * 10 + (cp[1] - '0');
	if (sexa->mm > 59)
		return (0);
	cp += 2;
	if (sep) {
		if (*cp != ':') {
			if (flags & TIME_ALLOW_NOSEC) {
				sexa->ss = 0;
				goto end;
			}
			return (0);
		}
		cp++;
	} else if (flags & TIME_ALLOW_NOSEC && !isdigit(*cp)) {
		sexa->ss = 0;
		goto end;
	}
	if (!isdigit(cp[0]) || !isdigit(cp[1]))
		return (0);
	sexa->ss = (cp[0] - '0') * 10 + (cp[1] - '0');
	if (sexa->ss > (flags & TIME_ALLOW_LEAPSEC ? 60 : 59))
		return (0);
	cp += 2;
end:	if (flags & PARSE_REQ_TERM && *cp)
		return (0);
	else
		return (cp);
}
