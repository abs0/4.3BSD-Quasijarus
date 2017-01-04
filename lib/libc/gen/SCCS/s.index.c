h59221
s 00010/00005/00025
d D 5.4 88/06/27 17:34:07 bostic 5 4
c install approved copyright notice
e
s 00023/00014/00007
d D 5.3 88/06/02 09:27:58 bostic 4 3
c rewritten from scratch; add Berkeley specific header
e
s 00002/00002/00019
d D 5.2 86/03/09 19:49:42 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00004/00001/00017
d D 5.1 85/06/05 12:25:39 mckusick 2 1
c Add copyright
e
s 00018/00000/00000
d D 4.1 80/12/21 16:39:43 wnj 1 0
c date and time created 80/12/21 16:39:43 by wnj
e
u
U
t
T
I 1
D 2
/* %W% (Berkeley) %G% */
E 2
I 2
D 3
#ifndef lint
E 3
I 3
D 4
#if defined(LIBC_SCCS) && !defined(lint)
E 3
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif not lint
E 3
I 3
#endif LIBC_SCCS and not lint
E 3

E 4
E 2
/*
D 4
 * Return the ptr in sp at which the character c appears;
 * NULL if not found
E 4
I 4
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 5
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 5
I 5
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
E 5
E 4
 */

D 4
#define	NULL	0
E 4
I 4
#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* LIBC_SCCS and not lint */
E 4

I 4
#include <stdio.h>

E 4
char *
D 4
index(sp, c)
register char *sp, c;
E 4
I 4
index(p, ch)
	register char *p, ch;
E 4
{
D 4
	do {
		if (*sp == c)
			return(sp);
	} while (*sp++);
	return(NULL);
E 4
I 4
	for (;; ++p) {
		if (*p == ch)
			return(p);
		if (!*p)
			return((char *)NULL);
	}
	/* NOTREACHED */
E 4
}
E 1
