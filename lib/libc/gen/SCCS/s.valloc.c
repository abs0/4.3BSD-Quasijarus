h23715
s 00002/00002/00020
d D 5.2 86/03/09 20:01:20 donn 5 4
c added LIBC_SCCS condition for sccs ids
e
s 00007/00001/00015
d D 5.1 85/05/30 10:53:14 dist 4 3
c Add copyright
e
s 00004/00002/00012
d D 4.3 83/07/01 18:33:06 sam 3 2
c include fixes
e
s 00004/00005/00010
d D 4.2 83/07/01 04:02:33 sam 2 1
c delete valign.h in favor of sys call
e
s 00015/00000/00000
d D 4.1 80/12/21 16:40:28 wnj 1 0
c date and time created 80/12/21 16:40:28 by wnj
e
u
U
t
T
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 4
I 1
D 2
/* %W% (Berkeley) %G% */
#include <valign.h>
E 2
I 2
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
D 5
#ifndef lint
E 5
I 5
#if defined(LIBC_SCCS) && !defined(lint)
E 5
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif
E 4
I 4
D 5
#endif not lint
E 5
I 5
#endif LIBC_SCCS and not lint
E 5
E 4
E 3
E 2

char	*malloc();

char *
valloc(i)
	int i;
{
D 2
	char *cp = malloc(i + (VALSIZ-1));
	int j;
E 2
I 2
	int valsiz = getpagesize(), j;
D 3
	char *cp = malloc(i + (valsize-1));
E 3
I 3
	char *cp = malloc(i + (valsiz-1));
E 3
E 2

D 2
	j = ((int)cp + (VALSIZ-1)) &~ (VALSIZ-1);
E 2
I 2
	j = ((int)cp + (valsiz-1)) &~ (valsiz-1);
E 2
	return ((char *)j);
}
E 1
