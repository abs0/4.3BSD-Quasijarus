h33780
s 00007/00001/00036
d D 5.1 85/06/07 23:27:57 kre 3 2
c Add copyright
e
s 00006/00002/00031
d D 1.2 83/04/30 17:04:21 dlw 2 1
c changed to use MAXPATHLEN. DLW
e
s 00033/00000/00000
d D 1.1 83/04/25 11:25:23 dlw 1 0
c date and time created 83/04/25 11:25:23 by dlw
e
u
U
t
T
I 1
/*
D 3
char	id_rename[] = "%W%";
E 3
I 3
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
 *
I 3
 *	%W%	%G%
 */

/*
E 3
 * rename a file atomically
 *
 * synopsis:
 *	integer function rename (from, to)
 *	character*(*) from, to
 *
 * where:
 *	return value will be zero normally, an error number otherwise.
 */

#include "../libI77/f_errno.h"
I 2
#include <sys/param.h>
#ifndef	MAXPATHLEN
#define MAXPATHLEN	128
#endif
E 2

long
rename_ (from, to, frlen, tolen)
char	*from, *to;
long	frlen, tolen;
{
D 2
	char	frbuf[256];
	char	tobuf[256];
E 2
I 2
	char	frbuf[MAXPATHLEN];
	char	tobuf[MAXPATHLEN];
E 2

	if (frlen <= 0 || tolen <= 0 || *from == ' ' || *to == ' ')
		return ((long)(errno = F_ERARG));
	if (frlen >= sizeof frbuf || tolen >= sizeof tobuf)
		return ((long)(errno = F_ERARG));
	g_char (from, frlen, frbuf);
	g_char (to, tolen, tobuf);
	if (rename (from, to) != 0)
		return ((long)errno);
	return (0L);
}
E 1
