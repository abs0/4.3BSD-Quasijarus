h47079
s 00010/00005/00031
d D 5.5 88/06/27 18:28:11 bostic 8 7
c install approved copyright notice
e
s 00009/00003/00027
d D 5.4 88/03/07 21:07:39 bostic 7 6
c add Berkeley specific headers
e
s 00001/00000/00029
d D 5.3 87/10/01 14:39:53 bostic 6 5
c return u_long, not int; bug report 4.3BSD/lib/37
e
s 00002/00002/00027
d D 5.2 86/03/09 20:11:14 donn 5 4
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00020
d D 5.1 85/05/30 11:15:25 dist 4 3
c Add copyright
e
s 00008/00013/00013
d D 4.3 82/11/14 13:57:27 sam 3 2
c merge of 4.1b and 4.1c
e
s 00001/00001/00025
d D 4.2 82/10/07 18:28:14 sam 2 1
c names all wrong
e
s 00026/00000/00000
d D 4.1 82/10/07 16:40:03 sam 1 0
c date and time created 82/10/07 16:40:03 by sam
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
 * Copyright (c) 1983 Regents of the University of California.
D 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
E 7
 */

D 5
#ifndef lint
E 5
I 5
#if defined(LIBC_SCCS) && !defined(lint)
E 5
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif not lint
E 5
I 5
D 7
#endif LIBC_SCCS and not lint
E 7
I 7
#endif /* LIBC_SCCS and not lint */
E 7
E 5
E 4

#include <sys/types.h>
D 3
#include <net/in.h>
E 3
I 3
#include <netinet/in.h>
E 3

/*
 * Return the network number from an internet
 * address; handles class a/b/c network #'s.
 */
I 6
u_long
E 6
D 2
in_netof(in)
E 2
I 2
inet_netof(in)
E 2
	struct in_addr in;
{
D 3
#if vax || pdp11
	register u_long net;
E 3
I 3
	register u_long i = ntohl(in.s_addr);
E 3

D 3
	if ((in.s_addr&IN_CLASSA) == 0)
		return (in.s_addr & IN_CLASSA_NET);
	if ((in.s_addr&IN_CLASSB) == 0)
		return ((int)htons((u_short)(in.s_addr & IN_CLASSB_NET)));
	net = htonl((u_long)(in.s_addr & IN_CLASSC_NET));
	net >>= 8;
	return ((int)net);
#else
	return (IN_NETOF(in));
#endif
E 3
I 3
	if (IN_CLASSA(i))
		return (((i)&IN_CLASSA_NET) >> IN_CLASSA_NSHIFT);
	else if (IN_CLASSB(i))
		return (((i)&IN_CLASSB_NET) >> IN_CLASSB_NSHIFT);
	else
		return (((i)&IN_CLASSC_NET) >> IN_CLASSC_NSHIFT);
E 3
}
E 1
