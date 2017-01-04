/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * Miscellaneous utility functions
 */

#ifndef lint
static char sccsid[] = "@(#)util.c	1.3 (IFCTF) 2013/01/06";
#endif

#include <ctype.h>
#include <syslog.h>

extern char *malloc();

char *
myalloc(size)
{
	char *ptr;

	ptr = malloc(size);
	if (!ptr)
		syslog(LOG_ALERT, "malloc failed: %m");
	return(ptr);
}

is_string_numeric(s)
	register char *s;
{
	register int c;

	if (!isdigit(*s++))
		return(0);
	while (c = *s++)
		if (!isdigit(c))
			return(0);
	return(1);
}
