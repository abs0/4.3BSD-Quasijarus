h00638
s 00001/00001/00075
d D 5.6 07/12/14 19:56:12 msokolov 8 7
c off by 1 error allowed 4 dots (5 parts) resulting in a buffer overflow
e
s 00010/00005/00066
d D 5.5 88/06/27 18:28:12 bostic 7 6
c install approved copyright notice
e
s 00009/00003/00062
d D 5.4 88/03/07 21:07:40 bostic 6 5
c add Berkeley specific headers
e
s 00004/00003/00061
d D 5.3 87/10/01 14:33:18 bostic 5 4
c INADDR_NONE, not -1; bug report 4.3BSD/lib/22
e
s 00002/00002/00062
d D 5.2 86/03/09 20:11:24 donn 4 3
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00055
d D 5.1 85/05/30 11:15:40 dist 3 2
c Add copyright
e
s 00001/00000/00055
d D 4.2 82/10/07 17:09:49 sam 2 1
c forgot i
e
s 00055/00000/00000
d D 4.1 82/10/07 17:08:21 sam 1 0
c date and time created 82/10/07 17:08:21 by sam
e
u
U
t
T
I 1
D 3
/*	%W%	%G%	*/
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

#include <sys/types.h>
I 5
#include <netinet/in.h>
E 5
#include <ctype.h>

/*
 * Internet network address interpretation routine.
 * The library routines call this routine to interpret
 * network numbers.
 */
u_long
inet_network(cp)
	register char *cp;
{
	register u_long val, base, n;
	register char c;
	u_long parts[4], *pp = parts;
I 2
	register int i;
E 2

again:
	val = 0; base = 10;
	if (*cp == '0')
		base = 8, cp++;
	if (*cp == 'x' || *cp == 'X')
		base = 16, cp++;
	while (c = *cp) {
		if (isdigit(c)) {
			val = (val * base) + (c - '0');
			cp++;
			continue;
		}
		if (base == 16 && isxdigit(c)) {
			val = (val << 4) + (c + 10 - (islower(c) ? 'a' : 'A'));
			cp++;
			continue;
		}
		break;
	}
	if (*cp == '.') {
D 8
		if (pp >= parts + 4)
E 8
I 8
		if (pp >= parts + 3)
E 8
D 5
			return (-1);
E 5
I 5
			return (INADDR_NONE);
E 5
		*pp++ = val, cp++;
		goto again;
	}
	if (*cp && !isspace(*cp))
D 5
		return (-1);
E 5
I 5
		return (INADDR_NONE);
E 5
	*pp++ = val;
	n = pp - parts;
	if (n > 4)
D 5
		return (-1);
E 5
I 5
		return (INADDR_NONE);
E 5
	for (val = 0, i = 0; i < n; i++) {
		val <<= 8;
		val |= parts[i] & 0xff;
	}
	return (val);
}
E 1
