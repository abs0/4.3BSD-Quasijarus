h64182
s 00010/00005/00133
d D 5.5 88/06/27 16:43:49 bostic 17 16
c install approved copyright notice
e
s 00009/00003/00129
d D 5.4 88/03/07 21:10:47 bostic 16 15
c added Berkeley specific headers
e
s 00002/00002/00130
d D 5.3 86/03/09 20:32:49 donn 15 14
c added LIBC_SCCS condition for sccs ids
e
s 00005/00001/00127
d D 5.2 85/09/10 10:29:05 bloom 14 13
c modify to use new hostent structure
e
s 00009/00001/00119
d D 5.1 85/05/30 12:01:24 dist 13 12
c Add copyright
e
s 00010/00005/00110
d D 4.10 85/01/21 20:26:43 serge 12 10
c made sethostfile work with gethostbyname and gethostbyaddr
e
s 00010/00005/00110
d R 4.10 85/01/16 14:31:11 serge 11 10
c made sethostfile work with gethostbyname and gethostbyaddr
e
s 00001/00001/00114
d D 4.9 84/08/28 14:41:30 ralph 10 9
c unify dbm routine names.
e
s 00007/00001/00108
d D 4.8 84/05/17 14:17:05 ralph 9 8
c added sethostfile() so routines can be used w/ alternate host file.
e
s 00007/00007/00102
d D 4.7 83/12/21 17:42:29 karels 8 7
c rename shared data for sethostent/gethostbyname-addr and make global
e
s 00011/00006/00098
d D 4.6 83/12/21 10:47:35 ralph 7 5
c modified to leave dbm files open if sethostent(1) used.
e
s 00005/00006/00098
d R 4.6 83/12/21 10:24:09 ralph 6 5
c changed set/endhostent to set/clear stayopen for use w/ gethostnamadr.c
e
s 00010/00011/00094
d D 4.5 83/01/02 16:38:34 sam 5 4
c null pointer stuff from sun
e
s 00001/00001/00104
d D 4.4 82/12/17 17:05:46 sam 4 3
c pass port numbers around in network order 
e
s 00012/00012/00093
d D 4.3 82/11/14 13:49:25 sam 3 2
c null pointer problems
e
s 00011/00065/00094
d D 4.2 82/10/05 22:19:13 sam 2 1
c rename library routines so as not conflict with gethostname
e
s 00159/00000/00000
d D 4.1 82/08/25 21:54:01 sam 1 0
c date and time created 82/08/25 21:54:01 by sam
e
u
U
t
T
I 1
D 13
/*	%M%	%I%	%E%	*/
E 13
I 13
/*
 * Copyright (c) 1983 Regents of the University of California.
D 16
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 16
I 16
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 17
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 17
I 17
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
E 17
E 16
 */

D 15
#ifndef lint
E 15
I 15
#if defined(LIBC_SCCS) && !defined(lint)
E 15
static char sccsid[] = "%W% (Berkeley) %G%";
D 15
#endif not lint
E 15
I 15
D 16
#endif LIBC_SCCS and not lint
E 16
I 16
#endif /* LIBC_SCCS and not lint */
E 16
E 15
E 13

#include <stdio.h>
I 2
#include <sys/types.h>
E 2
#include <sys/socket.h>
#include <netdb.h>
#include <ctype.h>
I 7
#include <ndbm.h>
E 7

I 2
/*
 * Internet version.
 */
E 2
#define	MAXALIASES	35
I 2
#define	MAXADDRSIZE	14
E 2

D 4
static char HOSTDB[] = "/usr/lib/hosts";
E 4
I 4
D 9
static char HOSTDB[] = "/etc/hosts";
E 9
I 9
D 12
static char *HOSTDB = "/etc/hosts";
E 12
E 9
E 4
static FILE *hostf = NULL;
static char line[BUFSIZ+1];
I 2
static char hostaddr[MAXADDRSIZE];
E 2
static struct hostent host;
static char *host_aliases[MAXALIASES];
I 14
static char *host_addrs[] = {
	hostaddr,
	NULL
};
E 14
D 7
static int stayopen = 0;
E 7
I 7
D 8
int _stayopen = 0;
extern DBM *db;		/* set by gethostbyname(), gethostbyaddr() */
E 8
I 8
D 12
int _host_stayopen;
DBM *_host_db;		/* set by gethostbyname(), gethostbyaddr() */
E 12
I 12

/*
 * The following is shared with gethostnamadr.c
 */
char	*_host_file = "/etc/hosts";
int	_host_stayopen;
DBM	*_host_db;	/* set by gethostbyname(), gethostbyaddr() */

E 12
E 8
E 7
D 2
static unsigned long value();
E 2
static char *any();

sethostent(f)
	int f;
{
D 7
	if (hostf == NULL)
		hostf = fopen(HOSTDB, "r" );
	else
E 7
I 7
	if (hostf != NULL)
E 7
		rewind(hostf);
D 7
	stayopen |= f;
E 7
I 7
D 8
	_stayopen |= f;
E 8
I 8
	_host_stayopen |= f;
E 8
E 7
}

endhostent()
{
D 7
	if (hostf && !stayopen) {
E 7
I 7
	if (hostf) {
E 7
		fclose(hostf);
		hostf = NULL;
	}
I 7
D 8
	if (db) {
		ndbmclose(db);
		db = (DBM *)NULL;
E 8
I 8
	if (_host_db) {
D 10
		ndbmclose(_host_db);
E 10
I 10
		dbm_close(_host_db);
E 10
		_host_db = (DBM *)NULL;
E 8
	}
D 8
	_stayopen = 0;
E 8
I 8
	_host_stayopen = 0;
E 8
E 7
}

struct hostent *
gethostent()
{
	char *p;
	register char *cp, **q;

D 12
	if (hostf == NULL && (hostf = fopen(HOSTDB, "r" )) == NULL)
E 12
I 12
	if (hostf == NULL && (hostf = fopen(_host_file, "r" )) == NULL)
E 12
		return (NULL);
again:
	if ((p = fgets(line, BUFSIZ, hostf)) == NULL)
		return (NULL);
	if (*p == '#')
		goto again;
	cp = any(p, "#\n");
	if (cp == NULL)
		goto again;
	*cp = '\0';
	cp = any(p, " \t");
	if (cp == NULL)
		goto again;
	*cp++ = '\0';
D 2
	host.h_addr = value(p);
E 2
I 2
	/* THIS STUFF IS INTERNET SPECIFIC */
D 14
	host.h_addr = hostaddr;
E 14
I 14
	host.h_addr_list = host_addrs;
E 14
	*((u_long *)host.h_addr) = inet_addr(p);
	host.h_length = sizeof (u_long);
	host.h_addrtype = AF_INET;
E 2
	while (*cp == ' ' || *cp == '\t')
		cp++;
	host.h_name = cp;
D 2
	host.h_addrtype = AF_INET;
E 2
D 3
	host.h_aliases = host_aliases;
E 3
I 3
	q = host.h_aliases = host_aliases;
E 3
	cp = any(cp, " \t");
D 3
	if (cp != NULL)
E 3
I 3
D 5
	if (cp != NULL) {
E 5
I 5
	if (cp != NULL) 
E 5
E 3
		*cp++ = '\0';
D 3
	q = host_aliases;
	while (*cp) {
		if (*cp == ' ' || *cp == '\t') {
			cp++;
			continue;
E 3
I 3
D 5
		while (*cp) {
			if (*cp == ' ' || *cp == '\t') {
				cp++;
				continue;
			}
			if (q < &host_aliases[MAXALIASES - 1])
				*q++ = cp;
			cp = any(cp, " \t");
			if (*cp != NULL)
				*cp++ = '\0';
E 5
I 5
	while (cp && *cp) {
		if (*cp == ' ' || *cp == '\t') {
			cp++;
			continue;
E 5
E 3
		}
I 5
		if (q < &host_aliases[MAXALIASES - 1])
			*q++ = cp;
		cp = any(cp, " \t");
		if (cp != NULL)
			*cp++ = '\0';
E 5
D 3
		if (q < &host_aliases[MAXALIASES - 1])
			*q++ = cp;
		cp = any(cp, " \t");
		if (*cp != NULL)
			*cp++ = '\0';
E 3
	}
	*q = NULL;
	return (&host);
I 9
}

sethostfile(file)
	char *file;
{
D 12
	HOSTDB = file;
E 12
I 12
	_host_file = file;
E 12
E 9
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
