h49253
s 00010/00005/00111
d D 5.6 88/06/27 17:13:04 bostic 11 10
c install approved copyright notice
e
s 00009/00003/00107
d D 5.5 88/03/07 21:17:11 bostic 10 9
c added Berkeley specific header
e
s 00001/00000/00109
d D 5.4 87/09/04 17:13:11 mckusick 9 8
c add <sys/param.h> to define hton (4.3BSD/lib/89)
e
s 00004/00003/00105
d D 5.3 86/05/19 04:57:11 lepreau 8 7
c make "stayopen" flags work right
e
s 00002/00002/00106
d D 5.2 86/03/09 20:26:46 donn 7 6
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00099
d D 5.1 85/05/30 12:04:19 dist 6 5
c Add copyright
e
s 00010/00011/00090
d D 4.5 83/01/02 16:38:44 sam 5 4
c null pointer stuff from sun
e
s 00003/00002/00098
d D 4.4 82/12/17 17:06:05 sam 4 3
c pass port numbers around in network order 
e
s 00012/00012/00088
d D 4.3 82/11/14 13:49:39 sam 3 2
c null pointer problems
e
s 00000/00001/00100
d D 4.2 82/10/05 22:19:45 sam 2 1
c rename library routines so as not conflict with gethostname
e
s 00101/00000/00000
d D 4.1 82/08/25 21:54:14 sam 1 0
c date and time created 82/08/25 21:54:14 by sam
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

#include <stdio.h>
I 9
#include <sys/param.h>
E 9
I 4
#include <sys/types.h>
E 4
#include <sys/socket.h>
#include <netdb.h>
#include <ctype.h>

#define	MAXALIASES	35

D 4
static char SERVDB[] = "/usr/lib/services";
E 4
I 4
static char SERVDB[] = "/etc/services";
E 4
static FILE *servf = NULL;
static char line[BUFSIZ+1];
static struct servent serv;
static char *serv_aliases[MAXALIASES];
D 8
static int stayopen = 0;
E 8
D 2
static unsigned long value();
E 2
static char *any();
I 8
int _serv_stayopen;
E 8

setservent(f)
	int f;
{
	if (servf == NULL)
		servf = fopen(SERVDB, "r" );
	else
		rewind(servf);
D 8
	stayopen |= f;
E 8
I 8
	_serv_stayopen |= f;
E 8
}

endservent()
{
D 8
	if (servf && !stayopen) {
E 8
I 8
	if (servf) {
E 8
		fclose(servf);
		servf = NULL;
	}
I 8
	_serv_stayopen = 0;
E 8
}

struct servent *
getservent()
{
	char *p;
	register char *cp, **q;

	if (servf == NULL && (servf = fopen(SERVDB, "r" )) == NULL)
		return (NULL);
again:
	if ((p = fgets(line, BUFSIZ, servf)) == NULL)
		return (NULL);
	if (*p == '#')
		goto again;
	cp = any(p, "#\n");
	if (cp == NULL)
		goto again;
	*cp = '\0';
	serv.s_name = p;
	p = any(p, " \t");
	if (p == NULL)
		goto again;
	*p++ = '\0';
	while (*p == ' ' || *p == '\t')
		p++;
	cp = any(p, ",/");
	if (cp == NULL)
		goto again;
	*cp++ = '\0';
D 4
	serv.s_port = atoi(p);
E 4
I 4
	serv.s_port = htons((u_short)atoi(p));
E 4
	serv.s_proto = cp;
I 3
	q = serv.s_aliases = serv_aliases;
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
	serv.s_aliases = serv_aliases;
	q = serv_aliases;
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
			if (q < &serv_aliases[MAXALIASES - 1])
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
		if (q < &serv_aliases[MAXALIASES - 1])
			*q++ = cp;
		cp = any(cp, " \t");
		if (cp != NULL)
			*cp++ = '\0';
E 5
D 3
		if (q < &serv_aliases[MAXALIASES - 1])
			*q++ = cp;
		cp = any(cp, " \t");
		if (*cp != NULL)
			*cp++ = '\0';
E 3
	}
	*q = NULL;
	return (&serv);
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
