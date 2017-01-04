h61554
s 00010/00005/00029
d D 5.4 88/06/27 18:25:39 bostic 4 3
c install approved copyright notice
e
s 00026/00015/00008
d D 5.3 88/06/02 09:32:16 bostic 3 2
c copy in Berkeley copyrighted versions
e
s 00002/00002/00021
d D 5.2 86/03/09 19:35:12 donn 2 1
c added LIBC_SCCS condition for sccs ids
e
s 00023/00000/00000
d D 5.1 85/08/04 08:08:32 kre 1 0
c date and time created 85/08/04 08:08:32 by kre
e
u
U
t
T
I 1
D 2
#ifndef lint
E 2
I 2
D 3
#if defined(LIBC_SCCS) && !defined(lint)
E 2
static char sccsid[] = "%W% (Berkeley) %E%";
D 2
#endif not lint
E 2
I 2
#endif LIBC_SCCS and not lint
E 2

E 3
/*
D 3
 * Return the ptr in sp at which the character c appears;
 * NULL if not found
E 3
I 3
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 3
 *
D 3
 * this routine is just "index" renamed.
E 3
I 3
 * Redistribution and use in source and binary forms are permitted
D 4
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 4
I 4
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 4
E 3
 */

D 3
#define	NULL	0
E 3
I 3
#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* LIBC_SCCS and not lint */
E 3

I 3
#ifdef notdef
static char sccsid[] = "@(#)index.c	5.3 (Berkeley) 6/2/88";
#endif

#include <stdio.h>

E 3
char *
D 3
strchr(sp, c)
register char *sp, c;
E 3
I 3
strchr(p, ch)
	register char *p, ch;
E 3
{
D 3
	do {
		if (*sp == c)
			return(sp);
	} while (*sp++);
	return(NULL);
E 3
I 3
	for (;; ++p) {
		if (*p == ch)
			return(p);
		if (!*p)
			return((char *)NULL);
	}
	/* NOTREACHED */
E 3
}
E 1
