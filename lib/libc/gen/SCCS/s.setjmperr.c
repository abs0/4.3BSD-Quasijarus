h61833
s 00010/00005/00023
d D 5.4 88/06/27 17:45:38 bostic 4 3
c install approved copyright notice
e
s 00012/00007/00016
d D 5.3 88/05/23 20:43:29 bostic 3 2
c add Berkeley specific header; don't print out trailing NULL
e
s 00002/00002/00021
d D 5.2 86/03/09 21:14:12 donn 2 1
c added LIBC_SCCS condition for sccs ids
e
s 00023/00000/00000
d D 5.1 86/01/09 15:51:54 mckusick 1 0
c date and time created 86/01/09 15:51:54 by mckusick
e
u
U
t
T
I 1
/*
 * Copyright (c) 1980 Regents of the University of California.
D 3
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
I 3
 * All rights reserved.
 *
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

D 2
#ifndef lint
E 2
I 2
#if defined(LIBC_SCCS) && !defined(lint)
E 2
static char sccsid[] = "%W% (Berkeley) %G%";
D 2
#endif not lint
E 2
I 2
D 3
#endif LIBC_SCCS and not lint
E 3
I 3
#endif /* LIBC_SCCS and not lint */
E 3
E 2

D 3
#define ERRMSG	"longjmp botch\n"

E 3
/*
 * This routine is called from longjmp() when an error occurs.
 * Programs that wish to exit gracefully from this error may
 * write their own versions.
 * If this routine returns, the program is aborted.
 */
I 3

E 3
longjmperror()
{
D 3

	write(2, ERRMSG, sizeof(ERRMSG));
E 3
I 3
#define	ERRMSG	"longjmp botch\n"
	write(2, ERRMSG, sizeof(ERRMSG) - 1);
E 3
}
E 1
