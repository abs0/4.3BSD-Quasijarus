h36589
s 00010/00005/00030
d D 5.6 88/06/27 17:12:53 bostic 9 8
c install approved copyright notice
e
s 00009/00003/00026
d D 5.5 88/03/07 21:17:00 bostic 8 7
c added Berkeley specific header
e
s 00002/00001/00027
d D 5.4 87/09/30 10:50:40 bostic 7 6
c net is a long; bug report 4.3BSD/lib/35
e
s 00005/00002/00023
d D 5.3 86/05/19 04:56:48 lepreau 6 5
c make "stayopen" flags work right
e
s 00002/00002/00023
d D 5.2 86/03/09 20:25:03 donn 5 4
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00016
d D 5.1 85/05/30 12:02:02 dist 4 3
c Add copyright
e
s 00003/00003/00014
d D 4.3 82/10/06 17:50:31 sam 3 2
c follow address type specificationbs
e
s 00001/00001/00016
d D 4.2 82/10/05 22:19:17 sam 2 1
c rename library routines so as not conflict with gethostname
e
s 00017/00000/00000
d D 4.1 82/08/25 21:54:04 sam 1 0
c date and time created 82/08/25 21:54:04 by sam
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
D 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
I 8
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
E 8
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
D 8
#endif LIBC_SCCS and not lint
E 8
I 8
#endif /* LIBC_SCCS and not lint */
E 8
E 5
E 4

#include <netdb.h>

I 6
extern int _net_stayopen;

E 6
struct netent *
D 2
getnetaddr(net)
E 2
I 2
D 3
getnetbyaddr(net)
E 2
	register int net;
E 3
I 3
getnetbyaddr(net, type)
D 7
	register int net, type;
E 7
I 7
	register long net;
	register int type;
E 7
E 3
{
	register struct netent *p;

D 6
	setnetent(0);
E 6
I 6
	setnetent(_net_stayopen);
E 6
	while (p = getnetent())
D 3
		if (p->n_net == net)
E 3
I 3
		if (p->n_addrtype == type && p->n_net == net)
E 3
			break;
D 6
	endnetent();
E 6
I 6
	if (!_net_stayopen)
		endnetent();
E 6
	return (p);
}
E 1
