h38726
s 00007/00001/00035
d D 5.1 85/06/07 23:23:36 kre 3 2
c Add copyright
e
s 00007/00003/00029
d D 1.2 83/04/30 16:59:56 dlw 2 1
c changed to use MAXPATHLEN. DLW
e
s 00032/00000/00000
d D 1.1 81/02/19 10:54:52 dlw 1 0
c date and time created 81/02/19 10:54:52 by dlw
e
u
U
t
T
I 1
/*
D 3
char id_link[] = "%W%";
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
 * make a link to an existing file
 *
 * calling sequence:
 *	ierror = link(name1, name2)
 * where:
 *	name1 is the pathname of an existing file
 *	name2 is a pathname to be linked to file name1
 *	ierror will be 0 if successful; a system error code otherwise.
 */

#include "../libI77/f_errno.h"
I 2
#include <sys/param.h>
#ifndef	MAXPATHLEN
#define MAXPATHLEN	128
#endif
E 2

long link_(name1, name2, n1len, n2len)
char *name1, *name2;
long n1len, n2len;
{
D 2
	char buf1[128];
	char buf2[128];
E 2
I 2
	char buf1[MAXPATHLEN];
	char buf2[MAXPATHLEN];
E 2

	if (n1len >= sizeof buf1 || n2len >= sizeof buf2)
		return((long)(errno=F_ERARG));
	g_char(name1, n1len, buf1);
	g_char(name2, n2len, buf2);
D 2
	if (buf2[0] == '\0')
E 2
I 2
	if (buf1[0] == '\0' || buf2[0] == '\0')
E 2
		return((long)(errno=F_ERARG));
	if (link(buf1, buf2) != 0)
		return((long)errno);
	return(0L);
}
E 1
