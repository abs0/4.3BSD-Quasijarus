h19973
s 00010/00005/00035
d D 5.5 88/06/27 17:12:54 bostic 7 6
c install approved copyright notice
e
s 00009/00003/00031
d D 5.4 88/03/07 21:17:02 bostic 6 5
c added Berkeley specific header
e
s 00005/00002/00029
d D 5.3 86/05/19 04:56:51 lepreau 5 4
c make "stayopen" flags work right
e
s 00002/00002/00029
d D 5.2 86/03/09 20:25:15 donn 4 3
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00022
d D 5.1 85/05/30 12:02:29 dist 3 2
c Add copyright
e
s 00001/00001/00022
d D 4.2 82/10/05 22:19:20 sam 2 1
c rename library routines so as not conflict with gethostname
e
s 00023/00000/00000
d D 4.1 82/08/25 21:54:07 sam 1 0
c date and time created 82/08/25 21:54:07 by sam
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
/*
 * Copyright (c) 1983 Regents of the University of California.
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
E 3

#include <netdb.h>

I 5
extern int _net_stayopen;

E 5
struct netent *
D 2
getnetname(name)
E 2
I 2
getnetbyname(name)
E 2
	register char *name;
{
	register struct netent *p;
	register char **cp;

D 5
	setnetent(0);
E 5
I 5
	setnetent(_net_stayopen);
E 5
	while (p = getnetent()) {
		if (strcmp(p->n_name, name) == 0)
			break;
		for (cp = p->n_aliases; *cp != 0; cp++)
			if (strcmp(*cp, name) == 0)
				goto found;
	}
found:
D 5
	endnetent();
E 5
I 5
	if (!_net_stayopen)
		endnetent();
E 5
	return (p);
}
E 1
