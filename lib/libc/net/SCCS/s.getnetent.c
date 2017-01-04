h60669
s 00010/00005/00109
d D 5.5 88/06/27 17:12:55 bostic 13 12
c install approved copyright notice
e
s 00009/00003/00105
d D 5.4 88/03/07 21:17:03 bostic 12 11
c added Berkeley specific header
e
s 00004/00003/00104
d D 5.3 86/05/19 04:56:54 lepreau 11 10
c make "stayopen" flags work right
e
s 00002/00002/00105
d D 5.2 86/03/09 20:25:26 donn 10 9
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00098
d D 5.1 85/05/30 12:02:46 dist 9 8
c Add copyright
e
s 00001/00000/00098
d D 4.8 83/05/23 01:22:21 sam 8 7
c now need types.h
e
s 00010/00011/00088
d D 4.7 83/01/02 16:38:37 sam 7 6
c null pointer stuff from sun
e
s 00001/00001/00098
d D 4.6 82/12/17 17:05:52 sam 6 5
c pass port numbers around in network order 
e
s 00013/00011/00086
d D 4.5 82/11/14 13:49:31 sam 5 4
c null pointer problems
e
s 00001/00001/00096
d D 4.4 82/10/07 17:11:35 sam 4 3
c network #'s aren't the same as host addresses (dumby)
e
s 00001/00000/00096
d D 4.3 82/10/06 17:50:34 sam 3 2
c follow address type specificationbs
e
s 00001/00064/00095
d D 4.2 82/10/05 22:19:24 sam 2 1
c rename library routines so as not conflict with gethostname
e
s 00159/00000/00000
d D 4.1 82/08/25 21:54:05 sam 1 0
c date and time created 82/08/25 21:54:05 by sam
e
u
U
t
T
I 1
D 9
/*	%M%	%I%	%E%	*/
E 9
I 9
/*
 * Copyright (c) 1983 Regents of the University of California.
D 12
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 12
I 12
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 13
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 13
I 13
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
E 13
E 12
 */

D 10
#ifndef lint
E 10
I 10
#if defined(LIBC_SCCS) && !defined(lint)
E 10
static char sccsid[] = "%W% (Berkeley) %G%";
D 10
#endif not lint
E 10
I 10
D 12
#endif LIBC_SCCS and not lint
E 12
I 12
#endif /* LIBC_SCCS and not lint */
E 12
E 10
E 9

#include <stdio.h>
I 8
#include <sys/types.h>
E 8
#include <sys/socket.h>
#include <netdb.h>
#include <ctype.h>

#define	MAXALIASES	35

D 6
static char *NETDB = "/usr/lib/networks";
E 6
I 6
static char NETDB[] = "/etc/networks";
E 6
static FILE *netf = NULL;
static char line[BUFSIZ+1];
static struct netent net;
static char *net_aliases[MAXALIASES];
D 11
static int stayopen = 0;
E 11
I 11
int _net_stayopen;
E 11
D 2
static unsigned long value();
E 2
static char *any();

setnetent(f)
	int f;
{
	if (netf == NULL)
		netf = fopen(NETDB, "r" );
	else
		rewind(netf);
D 11
	stayopen |= f;
E 11
I 11
	_net_stayopen |= f;
E 11
}

endnetent()
{
D 11
	if (netf && !stayopen) {
E 11
I 11
	if (netf) {
E 11
		fclose(netf);
		netf = NULL;
	}
I 11
	_net_stayopen = 0;
E 11
}

struct netent *
getnetent()
{
	char *p;
	register char *cp, **q;

	if (netf == NULL && (netf = fopen(NETDB, "r" )) == NULL)
		return (NULL);
again:
	p = fgets(line, BUFSIZ, netf);
	if (p == NULL)
		return (NULL);
	if (*p == '#')
		goto again;
	cp = any(p, "#\n");
	if (cp == NULL)
		goto again;
	*cp = '\0';
	net.n_name = p;
	cp = any(p, " \t");
	if (cp == NULL)
		goto again;
	*cp++ = '\0';
	while (*cp == ' ' || *cp == '\t')
		cp++;
	p = any(cp, " \t");
	if (p != NULL)
		*p++ = '\0';
D 2
	net.n_net = value(cp);
E 2
I 2
D 4
	net.n_net = inet_addr(cp);
E 4
I 4
	net.n_net = inet_network(cp);
E 4
I 3
	net.n_addrtype = AF_INET;
E 3
E 2
D 5
	net.n_aliases = net_aliases;
	q = net_aliases, cp = p;
	while (*cp) {
		if (*cp == ' ' || *cp == '\t') {
			cp++;
			continue;
E 5
I 5
	q = net.n_aliases = net_aliases;
D 7
	if (p != NULL) {
E 7
I 7
	if (p != NULL) 
E 7
		cp = p;
D 7
		while (*cp) {
			if (*cp == ' ' || *cp == '\t') {
				cp++;
				continue;
			}
			if (q < &net_aliases[MAXALIASES - 1])
				*q++ = cp;
			cp = any(cp, " \t");
			if (*cp != NULL)
				*cp++ = '\0';
E 7
I 7
	while (cp && *cp) {
		if (*cp == ' ' || *cp == '\t') {
			cp++;
			continue;
E 7
E 5
		}
I 7
		if (q < &net_aliases[MAXALIASES - 1])
			*q++ = cp;
		cp = any(cp, " \t");
		if (cp != NULL)
			*cp++ = '\0';
E 7
D 5
		if (q < &net_aliases[MAXALIASES - 1])
			*q++ = cp;
		cp = any(cp, " \t");
		if (*cp != NULL)
			*cp++ = '\0';
E 5
	}
	*q = NULL;
	return (&net);
D 2
}

static unsigned long
value(cp)
	register char *cp;
{
	register unsigned long val, base, n;
	register char c;
	unsigned long parts[4], *pp = parts;

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
		/*
		 * Internet format:
		 *	a.b.c.d
		 *	a.b.c	(with c treated as 16-bits)
		 *	a.b	(with b treated as 24 bits)
		 */
		if (pp >= parts + 4)
			return (-1);
		*pp++ = val, cp++;
		goto again;
	}
	if (*cp && !isspace(*cp))
		return (-1);
	n = pp - parts;
	if (n > 0) {
		if (n > 4)
			return (-1);
		*pp++ = val; n++;
		val = parts[0];
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
	}
	return (val);
E 2
}

static char *
any(cp, match)
	register char *cp;
	char *match;
{
	register char *mp, c;

	while (c = *cp) {
		for (mp = match; *mp; mp++)
			if (*mp == c)
				return (cp);
		cp++;
	}
	return ((char *)0);
}
E 1
