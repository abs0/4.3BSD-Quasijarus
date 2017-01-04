h16515
s 00007/00001/00032
d D 5.1 85/06/07 23:31:28 kre 3 2
c Add copyright
e
s 00005/00001/00028
d D 1.2 83/04/30 17:30:29 dlw 2 1
c changed to use MAXPATHLEN. DLW
e
s 00029/00000/00000
d D 1.1 81/02/19 10:55:13 dlw 1 0
c date and time created 81/02/19 10:55:13 by dlw
e
u
U
t
T
I 1
/*
D 3
char id_unlink[] = "%W%";
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
 * unlink (remove) a file
 *
 * calling sequence:
 *	integer unlink
 *	ierror = unlink(filename)
 * where:
 *	ierror will be a returned status (0 == OK)
 *	filename is the file to be unlinked
 */

#include "../libI77/f_errno.h"
I 2
#include <sys/param.h>
#ifndef	MAXPATHLEN
#define MAXPATHLEN	128
#endif
E 2

long
unlink_(fname, namlen)
char *fname;
long namlen;
{
D 2
	char buf[128];
E 2
I 2
	char buf[MAXPATHLEN];
E 2

	if (namlen >= sizeof buf)
		return((long)(errno=F_ERARG));
	g_char(fname, namlen, buf);
	if (unlink(buf) != 0)
		return((long)errno);
	return(0L);
}
E 1
