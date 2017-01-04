h61591
s 00001/00001/00114
d D 5.7 07/12/14 19:56:10 msokolov 12 11
c off by 1 error allowed 4 dots (5 parts) resulting in a buffer overflow
e
s 00010/00005/00105
d D 5.6 88/06/27 18:28:07 bostic 11 10
c install approved copyright notice
e
s 00009/00003/00101
d D 5.5 88/03/07 21:07:35 bostic 10 9
c add Berkeley specific headers
e
s 00003/00003/00101
d D 5.4 87/10/01 14:31:59 bostic 9 8
c INADDR_NONE, not -1; bug report 4.3BSD/lib/22
e
s 00006/00004/00098
d D 5.3 87/06/03 10:45:30 bostic 8 7
c bug report 4.3BSD/lib/65
e
s 00002/00002/00100
d D 5.2 86/03/09 20:10:47 donn 7 6
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00093
d D 5.1 85/05/30 11:14:40 dist 6 5
c Add copyright
e
s 00001/00001/00093
d D 4.5 82/11/14 13:57:09 sam 5 4
c merge of 4.1b and 4.1c
e
s 00001/00001/00093
d D 4.4 82/10/07 16:59:40 sam 4 3
c too much trouble to type it properly
e
s 00040/00019/00054
d D 4.3 82/10/07 16:13:20 sam 3 2
c rewrite a bit to be more lucid
e
s 00004/00000/00069
d D 4.2 82/10/05 22:19:48 sam 2 1
c rename library routines so as not conflict with gethostname
e
s 00069/00000/00000
d D 4.1 82/10/05 17:14:04 sam 1 0
c date and time created 82/10/05 17:14:04 by sam
e
u
U
t
T
I 1
D 6
/*	%M%	%I%	%E%	*/
E 6
I 6
/*
 * Copyright (c) 1983 Regents of the University of California.
D 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
I 10
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 11
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 11
I 11
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
E 11
E 10
 */

D 7
#ifndef lint
E 7
I 7
#if defined(LIBC_SCCS) && !defined(lint)
E 7
static char sccsid[] = "%W% (Berkeley) %G%";
D 7
#endif not lint
E 7
I 7
D 10
#endif LIBC_SCCS and not lint
E 10
I 10
#endif /* LIBC_SCCS and not lint */
E 10
E 7
E 6
I 2

#include <sys/types.h>
#include <ctype.h>
I 3
D 5
#include <net/in.h>
E 5
I 5
#include <netinet/in.h>
E 5
E 3

E 2
/*
 * Internet address interpretation routine.
 * All the network library routines call this
 * routine to interpret entries in the data bases
 * which are expected to be an address.
I 3
 * The value returned is in network order.
E 3
 */
D 3
u_long
E 3
I 3
D 4
struct in_addr
E 4
I 4
u_long
E 4
E 3
inet_addr(cp)
	register char *cp;
{
D 3
	register unsigned long val, base, n;
E 3
I 3
	register u_long val, base, n;
E 3
	register char c;
D 3
	unsigned long parts[4], *pp = parts;
E 3
I 3
	u_long parts[4], *pp = parts;
E 3

again:
I 3
	/*
	 * Collect number up to ``.''.
	 * Values are specified as for C:
	 * 0x=hex, 0=octal, other=decimal.
	 */
E 3
	val = 0; base = 10;
D 8
	if (*cp == '0')
		base = 8, cp++;
	if (*cp == 'x' || *cp == 'X')
		base = 16, cp++;
E 8
I 8
	if (*cp == '0') {
		if (*++cp == 'x' || *cp == 'X')
			base = 16, cp++;
		else
			base = 8;
	}
E 8
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
		/*
		 * Internet format:
		 *	a.b.c.d
		 *	a.b.c	(with c treated as 16-bits)
		 *	a.b	(with b treated as 24 bits)
		 */
D 12
		if (pp >= parts + 4)
E 12
I 12
		if (pp >= parts + 3)
E 12
D 9
			return (-1);
E 9
I 9
			return (INADDR_NONE);
E 9
		*pp++ = val, cp++;
		goto again;
	}
I 3
	/*
	 * Check for trailing characters.
	 */
E 3
	if (*cp && !isspace(*cp))
D 9
		return (-1);
E 9
I 9
		return (INADDR_NONE);
E 9
I 3
	*pp++ = val;
	/*
	 * Concoct the address according to
	 * the number of parts specified.
	 */
E 3
	n = pp - parts;
D 3
	if (n > 0) {
		if (n > 4)
			return (-1);
		*pp++ = val; n++;
E 3
I 3
	switch (n) {

	case 1:				/* a -- 32 bits */
E 3
		val = parts[0];
D 3
		if (n > 1)
			val <<= 24;
		if (n > 2)
			val |= (parts[1] & 0xff) << 16;
		if (n > 3)
			val |= (parts[2] & 0xff) << 8;
		if (n > 1)
			val |= parts[n - 1];
#if vax || pdp11
		val = htonl(val);
#endif
E 3
I 3
		break;

	case 2:				/* a.b -- 8.24 bits */
		val = (parts[0] << 24) | (parts[1] & 0xffffff);
		break;

	case 3:				/* a.b.c -- 8.8.16 bits */
		val = (parts[0] << 24) | ((parts[1] & 0xff) << 16) |
			(parts[2] & 0xffff);
		break;

	case 4:				/* a.b.c.d -- 8.8.8.8 bits */
		val = (parts[0] << 24) | ((parts[1] & 0xff) << 16) |
		      ((parts[2] & 0xff) << 8) | (parts[3] & 0xff);
		break;

	default:
D 9
		return (-1);
E 9
I 9
		return (INADDR_NONE);
E 9
E 3
	}
I 3
	val = htonl(val);
E 3
	return (val);
}
D 3

E 3
E 1
