/*
 * Behold the simplicity and beauty with which gmtime()
 * can be implemented using the new Quasijarus time handling
 * building blocks.
 */

#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "@(#)gmtime.c	5.1 (IFCTF) 2012/06/20";
#endif LIBC_SCCS and not lint

#include <sys/types.h>
#include <mjdtime.h>
#include <time.h>

struct tm *
gmtime(timeptr)
	caddr_t timeptr;	/* opaque pointer */
{
	struct mjdtime mjdtime;
	static struct tm tm;

	unix2mjdtime(timeptr, &mjdtime);
	tm.tm_mjd = mjdtime.mjd;
	tm.tm_gmtoff = 0;
	tm.tm_isdst = 0;
	tm.tm_zone = "GMT";	/* _not_ UTC! */
	sexatime(mjdtime.fract, &tm);
	tm.tm_wday = mjd2weekday(mjdtime.mjd);
	_mjd2greg(&tm);
	tm.tm_flags = __TM_HAS_LEGACY_DATE;
	return &tm;
}
