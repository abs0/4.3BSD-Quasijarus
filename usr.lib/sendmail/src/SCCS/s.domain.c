h01710
s 00021/00001/00263
d D 5.18 89/01/01 13:26:14 phil 19 18
c Add getcanonname using gethostbyname if NAMED_BIND undefined.
e
s 00015/00001/00249
d D 5.17 88/12/28 19:45:42 bostic 18 17
c add NO_WILDCARD_MX #define
e
s 00032/00009/00218
d D 5.16 88/09/20 23:45:11 eric 17 16
c some cleanup of I option handling
e
s 00012/00011/00215
d D 5.15 88/06/30 14:58:51 bostic 16 15
c install approved copyright notice
e
s 00001/00001/00225
d D 5.14 88/05/03 17:13:42 bostic 15 14
c change T_ANY to T_CNAME; fix match where sites have *.domain for
c MX records
e
s 00001/00001/00225
d D 5.13 88/04/19 13:42:02 bostic 14 13
c change NO_ADDRESS to NO_DATA
e
s 00103/00170/00123
d D 5.12 88/04/01 15:33:06 bostic 13 11
c redo getcanonname and getmxrr for new name server
e
s 00104/00171/00122
d R 5.12 88/04/01 15:30:51 bostic 12 11
c redo getmxrr and getcanonname for new name server
e
s 00003/00009/00290
d D 5.11 88/03/24 09:00:16 bostic 11 10
c MXDOMAIN is always in place
e
s 00021/00016/00278
d D 5.10 88/03/24 08:49:38 bostic 10 9
c add Berkeley specific header
e
s 00007/00019/00287
d D 5.9 88/03/24 08:48:14 bostic 9 8
c use the C library/resolver's version of getshort
e
s 00001/00001/00305
d D 5.8 88/03/13 18:21:58 bostic 8 7
c replace sameword with strcasecmp
e
s 00004/00004/00302
d D 5.7 87/12/12 09:31:34 bostic 7 6
c dn_skip -> dn_skipname
e
s 00013/00002/00293
d D 5.6 87/02/03 20:49:45 eric 6 5
c do it right
e
s 00003/00002/00292
d D 5.5 87/02/03 20:44:00 eric 5 4
c pass sending hostname correctly back via the $s macro (broken sometime
c earlier); hack around some name server changes
e
s 00002/00001/00292
d D 5.4 86/07/25 17:11:00 bloom 4 3
c move the include of sendmail.h so MXDOMAIN can come from it
e
s 00101/00000/00192
d D 5.3 86/07/21 10:30:06 bloom 3 2
c hack for Jeeves being broken, replace gethostbyname by a specific 
c routine for canonicalizing hostnames
e
s 00054/00014/00138
d D 5.2 86/07/10 15:41:06 bloom 2 1
c totally implement rfc974 in getmxrr(), just return a list of hosts
e
s 00152/00000/00000
d D 5.1 86/07/01 14:40:44 bloom 1 0
c Name Server MX support from Satz@su-sierra
e
u
U
t
T
I 1
/*
I 16
 * Copyright (c) 1986 Eric P. Allman
E 16
D 10
**  Sendmail
**  Copyright (c) 1986  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1986 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/
E 10
I 10
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 16
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *  Sendmail
 *  Copyright (c) 1986  Eric P. Allman
 *  Berkeley, California
E 16
I 16
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
E 16
 */
E 10

I 17
#include <sendmail.h>

E 17
I 4
D 13
#include "sendmail.h"
E 13
I 13
D 16
#include <sendmail.h>
E 13

E 16
E 4
I 2
D 10
#ifndef MXDOMAIN
E 10
E 2
#ifndef lint
I 2
D 10
static char	SccsId[] = "%W% (Berkeley) %G% (no MXDOMAIN)";
#endif not lint
#else MXDOMAIN
E 10
I 10
D 11
#ifdef MXDOMAIN
static char sccsid[] = "%W% (Berkeley) %G% (with MXDOMAIN)";
#else
static char sccsid[] = "%W% (Berkeley) %G% (without MXDOMAIN)";
#endif
E 11
I 11
D 17
static char sccsid[] = "%W% (Berkeley) %G%";
E 17
I 17
#ifdef NAMED_BIND
static char sccsid[] = "%W% (Berkeley) %G% (with name server)";
#else
static char sccsid[] = "%W% (Berkeley) %G% (without name server)";
#endif
E 17
E 11
#endif /* not lint */
E 10

I 16
D 17
#include <sendmail.h>
E 17
I 17
#ifdef NAMED_BIND

E 17
E 16
D 10
#ifndef lint
E 2
static char	SccsId[] = "%W% (Berkeley) %G%";
#endif not lint

E 10
I 10
D 11
#ifdef MXDOMAIN
E 11
E 10
D 13
# include <sys/param.h>
D 2
# include <netinet/in.h>
E 2
I 2
D 4
# include "sendmail.h"
E 4
E 2
# include <arpa/nameser.h>
# include <resolv.h>
D 2
# include <stdio.h>
E 2
# include <netdb.h>
E 13
I 13
#include <sys/param.h>
I 17
#include <errno.h>
E 17
#include <arpa/nameser.h>
#include <resolv.h>
#include <netdb.h>
E 13

typedef union {
	HEADER qb1;
	char qb2[PACKETSZ];
} querybuf;

D 5
static char hostbuf[BUFSIZ];
E 5
I 5
D 13
static char	hostbuf[BUFSIZ];
int		h_errno;
I 6
D 9
extern u_short	getshort();
E 9
I 9
extern u_short	_getshort();
E 13
I 13
static char hostbuf[MAXMXHOSTS*PACKETSZ];
E 13
E 9
E 6
E 5

D 5
int h_errno;
E 5
I 5
D 6
# define getshort	_getshort	/* XXX hack attack! */
E 5

E 6
D 2
getmxrr(host, mxhosts, maxmx)
E 2
I 2
D 13
getmxrr(host, mxhosts, maxmx, localhost)
E 2
	char *host, **mxhosts;
	int maxmx;
I 2
	char *localhost;
E 13
I 13
getmxrr(host, mxhosts, localhost, rcode)
	char *host, **mxhosts, *localhost;
	int *rcode;
E 13
E 2
{
D 13

E 13
I 13
	extern int h_errno;
	register u_char *eom, *cp;
	register int i, j, n, nmx;
	register char *bp;
E 13
	HEADER *hp;
D 13
	char *eom, *bp, *cp;
	querybuf buf, answer;
	int n, n1, i, j, nmx, ancount, qdcount, buflen;
I 2
	int seenlocal;
E 2
	u_short prefer[BUFSIZ];
D 2
	u_short pref, type, class;
E 2
I 2
	u_short pref, localpref, type, class;
E 13
I 13
	querybuf answer;
	int ancount, qdcount, buflen, seenlocal;
	u_short pref, localpref, type, prefer[MAXMXHOSTS];
E 13
E 2

I 18
	errno = 0;
E 18
D 13
	n = res_mkquery(QUERY, host, C_IN, T_MX, (char *)NULL, 0, NULL,
		(char *)&buf, sizeof(buf));
E 13
I 13
	n = res_search(host, C_IN, T_MX, (char *)&answer, sizeof(answer));
E 13
D 17
	if (n < 0) {
E 17
I 17
	if (n < 0)
	{
E 17
#ifdef DEBUG
D 13
		if (tTd(8, 1) || _res.options & RES_DEBUG)
			printf("res_mkquery failed\n");
E 13
I 13
		if (tTd(8, 1))
			printf("getmxrr: res_search failed (errno=%d, h_errno=%d)\n",
			    errno, h_errno);
E 13
#endif
D 2
		return(-1);
E 2
I 2
D 13
		h_errno = NO_RECOVERY;
		return(-2);
E 2
	}
	n = res_send((char *)&buf, n, (char *)&answer, sizeof(answer));
	if (n < 0) {
#ifdef DEBUG
		if (tTd(8, 1) || _res.options & RES_DEBUG)
			printf("res_send failed\n");
#endif
		h_errno = TRY_AGAIN;
		return (-1);
	}
	eom = (char *)&answer + n;
	/*
	 * find first satisfactory answer
	 */
	hp = (HEADER *) &answer;
	ancount = ntohs(hp->ancount);
	qdcount = ntohs(hp->qdcount);
	if (hp->rcode != NOERROR || ancount == 0) {
#ifdef DEBUG
		if (tTd(8, 1) || _res.options & RES_DEBUG)
			printf("rcode = %d, ancount=%d\n", hp->rcode, ancount);
#endif
		switch (hp->rcode) {
			case NXDOMAIN:
				/* Check if it's an authoritive answer */
D 2
				if (hp->aa)
E 2
I 2
				if (hp->aa) {
E 2
					h_errno = HOST_NOT_FOUND;
D 2
				else
E 2
I 2
					return(-3);
				} else {
E 2
					h_errno = TRY_AGAIN;
D 2
				break;
E 2
I 2
					return(-1);
				}
E 2
			case SERVFAIL:
				h_errno = TRY_AGAIN;
D 2
				break;
E 2
I 2
				return(-1);
I 3
#ifdef OLDJEEVES
			/*
			 * Jeeves (TOPS-20 server) still does not
			 * support MX records.  For the time being,
			 * we must accept FORMERRs as the same as
			 * NOERROR.
			 */
			case FORMERR:
D 11
#endif OLDJEEVES
E 11
I 11
#endif
E 11
E 3
E 2
			case NOERROR:
D 2
				h_errno = NO_ADDRESS;
				break;
E 2
I 2
				(void) strcpy(hostbuf, host);
				mxhosts[0] = hostbuf;
				return(1);
I 3
#ifndef OLDJEEVES
E 3
E 2
			case FORMERR:
I 3
D 11
#endif OLDJEEVES
E 11
I 11
#endif
E 11
E 3
			case NOTIMP:
			case REFUSED:
				h_errno = NO_RECOVERY;
I 2
				return(-2);
E 13
I 13
D 17
		switch(h_errno) {
D 14
		case NO_ADDRESS:
E 14
I 14
		case NO_DATA:
E 14
		case NO_RECOVERY:
E 17
I 17
		switch (h_errno)
		{
		  case NO_DATA:
		  case NO_RECOVERY:
			/* no MX data on this host */
E 17
			goto punt;
D 17
		case HOST_NOT_FOUND:
E 17
I 17

		  case HOST_NOT_FOUND:
			/* the host just doesn't exist */
E 17
			*rcode = EX_NOHOST;
			break;
D 17
		case TRY_AGAIN:
E 17
I 17

		  case TRY_AGAIN:
			/* couldn't connect to the name server */
			if (!UseNameServer && errno == ECONNREFUSED)
				goto punt;

			/* it might come up later; better queue it up */
E 17
			*rcode = EX_TEMPFAIL;
			break;
E 13
E 2
		}
D 13
		return (-1);
E 13
I 13
D 17
		return(-1);
E 17
I 17

		/* irreconcilable differences */
		return (-1);
E 17
E 13
	}
D 13
	bp = hostbuf;
E 13
I 13

	/* find first satisfactory answer */
	hp = (HEADER *)&answer;
	cp = (u_char *)&answer + sizeof(HEADER);
	eom = (u_char *)&answer + n;
	for (qdcount = ntohs(hp->qdcount); qdcount--; cp += n + QFIXEDSZ)
		if ((n = dn_skipname(cp, eom)) < 0)
			goto punt;
E 13
	nmx = 0;
I 2
	seenlocal = 0;
E 2
	buflen = sizeof(hostbuf);
D 13
	cp = (char *)&answer + sizeof(HEADER);
	if (qdcount) {
D 7
		cp += dn_skip(cp) + QFIXEDSZ;
E 7
I 7
		cp += dn_skipname(cp, eom) + QFIXEDSZ;
E 7
		while (--qdcount > 0)
D 7
			cp += dn_skip(cp) + QFIXEDSZ;
E 7
I 7
			cp += dn_skipname(cp, eom) + QFIXEDSZ;
E 7
	}
	while (--ancount >= 0 && cp < eom && nmx < maxmx) {
E 13
I 13
	bp = hostbuf;
	ancount = ntohs(hp->ancount);
	while (--ancount >= 0 && cp < eom && nmx < MAXMXHOSTS) {
E 13
		if ((n = dn_expand((char *)&answer, eom, cp, bp, buflen)) < 0)
			break;
		cp += n;
D 9
		type = getshort(cp);
E 9
I 9
D 13
		type = _getshort(cp);
E 9
 		cp += sizeof(u_short);
I 2
		/*
E 2
D 9
		class = getshort(cp);
E 9
I 9
		class = _getshort(cp);
E 9
I 2
		*/
E 13
I 13
		GETSHORT(type, cp);
E 13
E 2
 		cp += sizeof(u_short) + sizeof(u_long);
D 9
		n = getshort(cp);
E 9
I 9
D 13
		n = _getshort(cp);
E 9
		cp += sizeof(u_short);
E 13
I 13
		GETSHORT(n, cp);
E 13
		if (type != T_MX)  {
#ifdef DEBUG
			if (tTd(8, 1) || _res.options & RES_DEBUG)
				printf("unexpected answer type %d, size %d\n",
D 13
					type, n);
E 13
I 13
				    type, n);
E 13
#endif
			cp += n;
			continue;
		}
D 9
		pref = getshort(cp);
E 9
I 9
D 13
		pref = _getshort(cp);
E 9
		cp += sizeof(u_short);
E 13
I 13
		GETSHORT(pref, cp);
E 13
		if ((n = dn_expand((char *)&answer, eom, cp, bp, buflen)) < 0)
			break;
I 2
		cp += n;
D 8
		if (sameword(bp, localhost))
E 8
I 8
D 13
		if (!strcasecmp(bp, localhost))
E 8
		{
E 13
I 13
		if (!strcasecmp(bp, localhost)) {
			if (seenlocal == 0 || pref < localpref)
				localpref = pref;
E 13
			seenlocal = 1;
D 13
			localpref = pref;
E 13
			continue;
		}
E 2
		prefer[nmx] = pref;
		mxhosts[nmx++] = bp;
D 13
		n1 = strlen(bp)+1;
		bp += n1;
		buflen -= n1;
E 13
I 13
		n = strlen(bp) + 1;
		bp += n;
		buflen -= n;
E 13
D 2
		cp += n;
E 2
	}
D 2
	if (nmx == 0)
		return(-1);
E 2
I 2
	if (nmx == 0) {
D 13
		(void) strcpy(hostbuf, host);
		mxhosts[0] = hostbuf;
E 13
I 13
punt:		mxhosts[0] = strcpy(hostbuf, host);
E 13
		return(1);
	}
I 13

E 13
E 2
	/* sort the records */
	for (i = 0; i < nmx; i++) {
		for (j = i + 1; j < nmx; j++) {
D 18
			if (prefer[i] > prefer[j]) {
E 18
I 18
			if (prefer[i] > prefer[j] ||
			    (prefer[i] == prefer[j] && rand() % 1 == 0)) {
E 18
D 13
				int temp;
				char *temp1;
E 13
I 13
				register int temp;
				register char *temp1;
E 13

				temp = prefer[i];
				prefer[i] = prefer[j];
				prefer[j] = temp;
				temp1 = mxhosts[i];
				mxhosts[i] = mxhosts[j];
				mxhosts[j] = temp1;
			}
		}
I 2
D 13
		if (seenlocal && (prefer[i] >= localpref))
		{
			nmx = i;
E 13
I 13
		if (seenlocal && prefer[i] >= localpref) {
E 13
			/*
D 13
			 * We are the first MX, might as well try delivering
			 * since nobody is supposed to have more info.
E 13
I 13
			 * truncate higher pref part of list; if we're
			 * the best choice left, we should have realized
			 * awhile ago that this was a local delivery.
E 13
			 */
D 13
			if (nmx == 0)
			{
				(void) strcpy(hostbuf, host);
				mxhosts[0] = hostbuf;
				return(1);
E 13
I 13
			if (i == 0) {
				*rcode = EX_CONFIG;
				return(-1);
E 13
			}
I 13
			nmx = i;
E 13
			break;
		}
E 2
	}
	return(nmx);
I 3
}

D 13

E 13
getcanonname(host, hbsize)
	char *host;
	int hbsize;
{
D 13

E 13
I 13
	register u_char *eom, *cp;
	register int n; 
E 13
	HEADER *hp;
D 13
	char *eom, *cp;
	querybuf buf, answer;
	int n, ancount, qdcount;
E 13
I 13
	querybuf answer;
E 13
	u_short type;
D 13
	char nbuf[BUFSIZ];
	int first;
E 13
I 13
	int first, ancount, qdcount, loopcnt;
	char nbuf[PACKETSZ];
E 13

D 13
	n = res_mkquery(QUERY, host, C_IN, T_ANY, (char *)NULL, 0, NULL,
		(char *)&buf, sizeof(buf));
E 13
I 13
	loopcnt = 0;
loop:
I 18
	/*
	 * Use query type of ANY if possible (NO_WILDCARD_MX), which will
	 * find types CNAME, A, and MX, and will cause all existing records
	 * to be cached by our local server.  If there is (might be) a
	 * wildcard MX record in the local domain or its parents that are
	 * searched, we can't use ANY; it would cause fully-qualified names
	 * to match as names in a local domain.
	 */
# ifdef NO_WILDCARD_MX
	n = res_search(host, C_IN, T_ANY, (char *)&answer, sizeof(answer));
# else
E 18
D 15
	n = res_search(host, C_IN, T_ANY, (char *)&answer, sizeof(answer));
E 15
I 15
	n = res_search(host, C_IN, T_CNAME, (char *)&answer, sizeof(answer));
I 18
# endif
E 18
E 15
E 13
	if (n < 0) {
#ifdef DEBUG
D 13
		if (tTd(8, 1) || _res.options & RES_DEBUG)
			printf("res_mkquery failed\n");
E 13
I 13
		if (tTd(8, 1))
			printf("getcanonname:  res_search failed (errno=%d, h_errno=%d)\n",
			    errno, h_errno);
E 13
#endif
D 13
		h_errno = NO_RECOVERY;
E 13
		return;
	}
D 13
	n = res_send((char *)&buf, n, (char *)&answer, sizeof(answer));
	if (n < 0) {
#ifdef DEBUG
		if (tTd(8, 1) || _res.options & RES_DEBUG)
			printf("res_send failed\n");
#endif
		h_errno = TRY_AGAIN;
		return;
	}
	eom = (char *)&answer + n;
	/*
	 * find first satisfactory answer
	 */
	hp = (HEADER *) &answer;
E 13
I 13

	/* find first satisfactory answer */
	hp = (HEADER *)&answer;
E 13
	ancount = ntohs(hp->ancount);
D 13
	qdcount = ntohs(hp->qdcount);
	/*
	 * We don't care about errors here, only if we got an answer
	 */
E 13
I 13

	/* we don't care about errors here, only if we got an answer */
E 13
	if (ancount == 0) {
#ifdef DEBUG
D 13
		if (tTd(8, 1) || _res.options & RES_DEBUG)
E 13
I 13
		if (tTd(8, 1))
E 13
			printf("rcode = %d, ancount=%d\n", hp->rcode, ancount);
#endif
		return;
	}
D 13
	cp = (char *)&answer + sizeof(HEADER);
	if (qdcount) {
D 7
		cp += dn_skip(cp) + QFIXEDSZ;
E 7
I 7
		cp += dn_skipname(cp, eom) + QFIXEDSZ;
E 7
		while (--qdcount > 0)
D 7
			cp += dn_skip(cp) + QFIXEDSZ;
E 7
I 7
			cp += dn_skipname(cp, eom) + QFIXEDSZ;
E 7
	}
	first = 1;
	while (--ancount >= 0 && cp < eom) {
E 13
I 13
	cp = (u_char *)&answer + sizeof(HEADER);
	eom = (u_char *)&answer + n;
	for (qdcount = ntohs(hp->qdcount); qdcount--; cp += n + QFIXEDSZ)
		if ((n = dn_skipname(cp, eom)) < 0)
			return;

	/*
	 * just in case someone puts a CNAME record after another record,
	 * check all records for CNAME; otherwise, just take the first
	 * name found.
	 */
	for (first = 1; --ancount >= 0 && cp < eom; cp += n) {
E 13
		if ((n = dn_expand((char *)&answer, eom, cp, nbuf,
		    sizeof(nbuf))) < 0)
			break;
D 13
		if (first) {
E 13
I 13
		if (first) {			/* XXX */
E 13
			(void)strncpy(host, nbuf, hbsize);
			host[hbsize - 1] = '\0';
			first = 0;
		}
		cp += n;
D 9
		type = getshort(cp);
E 9
I 9
D 13
		type = _getshort(cp);
E 9
 		cp += sizeof(u_short);
E 13
I 13
		GETSHORT(type, cp);
E 13
 		cp += sizeof(u_short) + sizeof(u_long);
D 9
		n = getshort(cp);
E 9
I 9
D 13
		n = _getshort(cp);
E 9
		cp += sizeof(u_short);
E 13
I 13
		GETSHORT(n, cp);
E 13
		if (type == T_CNAME)  {
			/*
D 13
			 * Assume that only one cname will be found.  More
			 * than one is undefined.
E 13
I 13
			 * assume that only one cname will be found.  More
			 * than one is undefined.  Copy so that if dn_expand
			 * fails, `host' is still okay.
E 13
			 */
			if ((n = dn_expand((char *)&answer, eom, cp, nbuf,
			    sizeof(nbuf))) < 0)
				break;
D 13
			(void)strncpy(host, nbuf, hbsize);
E 13
I 13
			(void)strncpy(host, nbuf, hbsize); /* XXX */
E 13
			host[hbsize - 1] = '\0';
D 13
			getcanonname(host, hbsize);
			break;
E 13
I 13
			if (++loopcnt > 8)	/* never be more than 1 */
				return;
			goto loop;
E 13
		}
D 13
		cp += n;
E 13
	}
D 13
	return;
E 13
E 3
}
I 17

D 19
#endif /* NAMED_BIND */
E 19
I 19
#else /* not NAMED_BIND */

#include <netdb.h>

getcanonname(host, hbsize)
	char *host;
	int hbsize;
{
	struct hostent *hp;

	hp = gethostbyname(host);
	if (hp == NULL)
		return;

	if (strlen(hp->h_name) >= hbsize)
		return;

	(void) strcpy(host, hp->h_name);
}

#endif /* not NAMED_BIND */
E 19
E 17
I 6
D 9

u_short
getshort(msgp)
	char *msgp;
{
	register u_char *p = (u_char *) msgp;
	register int u;

	u = *p++ << 8;
	return ((u_short)(u | *p));
}

E 9
E 6
I 2
D 11
#endif MXDOMAIN
E 11
E 2
E 1
