h29685
s 00013/00000/00000
d D 5.1 2012/06/21 00:31:27 msokolov 1 0
c date and time created 2012/06/21 00:31:27 by msokolov
e
u
U
t
T
I 1
#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "%W% (IFCTF) %E%";
#endif LIBC_SCCS and not lint

#include <sys/types.h>
#include <time.h>

char *
ctime(timeptr)
	caddr_t timeptr;	/* opaque pointer */
{
	return asctime(localtime(timeptr));
}
E 1
