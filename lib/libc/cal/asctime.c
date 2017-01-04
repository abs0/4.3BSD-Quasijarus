#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "@(#)asctime.c	5.1 (IFCTF) 2012/06/21";
#endif LIBC_SCCS and not lint

#include <stdio.h>
#include <time.h>

static char weekdays[] = "SunMonTueWedThuFriSat";
static char months[] = "JanFebMarAprMayJunJulAugSepOctNovDec";

char *
asctime(tm)
	register struct tm *tm;
{
	static char result[26];

	(void) sprintf(result, "%.3s %.3s%3d %02d:%02d:%02d %d\n",
		weekdays + tm->tm_wday * 3,
		months + tm->tm_mon * 3, tm->tm_mday,
		tm->tm_hour, tm->tm_min, tm->tm_sec,
		tm->tm_year + 1900);
	return result;
}
