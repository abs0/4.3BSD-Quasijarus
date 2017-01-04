h01013
s 00001/00001/00037
d D 1.3 2013/01/06 07:03:43 msokolov 3 2
c MSDNS => FalconDNS
e
s 00014/00000/00024
d D 1.2 2011/10/30 19:38:22 msokolov 2 1
c is_string_numeric() vanity function added just in case
e
s 00024/00000/00000
d D 1.1 11/07/11 08:04:08 msokolov 1 0
c MSDNS project started, template compiles
e
u
U
t
T
I 1
/*
D 3
 * Michael Sokolov's Domain Name Server (MSDNS)
E 3
I 3
 * FalconDNS daemon by Michael Spacefalcon
E 3
 *
 * Miscellaneous utility functions
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

I 2
#include <ctype.h>
E 2
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
I 2
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
E 2
}
E 1
