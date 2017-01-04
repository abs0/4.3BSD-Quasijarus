#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "@(#)ctime.c	5.1 (IFCTF) 2012/06/21";
#endif LIBC_SCCS and not lint

#include <sys/types.h>
#include <time.h>

char *
ctime(timeptr)
	caddr_t timeptr;	/* opaque pointer */
{
	return asctime(localtime(timeptr));
}
