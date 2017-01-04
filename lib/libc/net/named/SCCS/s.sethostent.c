h29184
s 00010/00005/00035
d D 6.5 88/06/27 16:42:55 bostic 7 6
c install approved copyright notice
e
s 00009/00003/00031
d D 6.4 88/03/07 21:09:15 bostic 6 5
c add Berkeley specific header
e
s 00011/00008/00023
d D 6.3 86/04/10 16:19:58 kjd 5 4
c have sethostent and endhostent use TCP connections
e
s 00002/00002/00029
d D 6.2 86/03/09 20:36:48 donn 4 3
c added LIBC_SCCS condition for sccs ids
e
s 00000/00000/00031
d D 6.1 85/10/31 15:30:02 kjd 3 2
c Freeze for November 1 network distribution
e
s 00014/00001/00017
d D 1.2 85/09/10 10:35:07 bloom 2 1
c add sethostfile and make it lint
e
s 00018/00000/00000
d D 1.1 85/09/09 14:06:58 bloom 1 0
c date and time created 85/09/09 14:06:58 by bloom
e
u
U
t
T
I 1
/*
 * Copyright (c) 1985 Regents of the University of California.
D 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
E 6
 */

D 4
#ifndef lint
E 4
I 4
#if defined(LIBC_SCCS) && !defined(lint)
E 4
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif not lint
E 4
I 4
D 6
#endif LIBC_SCCS and not lint
E 6
I 6
#endif /* LIBC_SCCS and not lint */
E 6
E 4

D 5
/*
 * These are dummy routines to allow old programs that used /etc/hosts
 * to compile and work with the BIND name server
 */
E 5
I 5
#include <sys/types.h>
#include <arpa/nameser.h>
#include <netinet/in.h>
#include <resolv.h>
E 5

D 2
sethostent()	{}
E 2
I 2
sethostent(stayopen)
{
D 5
#ifdef lint
stayopen = stayopen;
#endif
E 5
I 5
	if (stayopen)
		_res.options |= RES_STAYOPEN | RES_USEVC;
E 5
}
E 2

D 5
endhostent()	{}
E 5
I 5
endhostent()
{
	_res.options &= ~(RES_STAYOPEN | RES_USEVC);
	_res_close();
}
E 5
I 2

sethostfile(name)
char *name;
{
#ifdef lint
name = name;
#endif
}
E 2
E 1
