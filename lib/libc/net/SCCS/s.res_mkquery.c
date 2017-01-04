h49035
s 00001/00001/00199
d D 6.8 99/09/28 16:41:46 msokolov 19 18
c let a query for "localhost" go out to the name server
e
s 00009/00003/00191
d D 6.7 88/03/07 21:17:23 bostic 18 17
c added Berkeley specific header
e
s 00004/00004/00190
d D 6.6 87/10/22 17:43:26 bostic 17 16
c ANSI C; sprintf now returns an int.
e
s 00000/00002/00194
d D 6.5 87/08/03 17:40:48 bostic 16 15
c karels; completion queries deleted
e
s 00036/00041/00160
d D 6.4 86/11/10 15:36:14 kjd 15 14
c fixes for dynamic updates from Mike Schwartz@washington
e
s 00001/00001/00200
d D 6.3 86/03/17 09:07:02 kjd 14 13
c move resolv.h to /usr/include
e
s 00002/00002/00199
d D 6.2 86/03/09 20:36:12 donn 13 12
c added LIBC_SCCS condition for sccs ids
e
s 00000/00000/00201
d D 6.1 85/10/31 15:29:49 kjd 12 11
c Freeze for November 1 network distribution
e
s 00002/00000/00199
d D 5.6 85/10/25 16:20:26 kjd 11 10
c declare sprintf as extern for SUNs
e
s 00002/00002/00197
d D 5.5 85/10/10 11:39:53 kjd 10 9
c Fix to get this to run on a SUN from smoot@ut-sally
e
s 00004/00001/00195
d D 5.4 85/09/14 11:21:05 bloom 9 8
c add ifdef DEBUG around debugging code, res_init() now returns a value
e
s 00002/00002/00194
d D 5.3 85/07/29 18:02:53 kjd 8 7
c Move /usr/include/nameser.h & resolv.h to /usr/include/arpa
e
s 00003/00003/00193
d D 5.2 85/07/16 11:03:14 kjd 7 6
c Change HTONS to standard htons()
e
s 00007/00004/00189
d D 5.1 85/05/30 12:06:42 dist 6 5
c Add copyright
e
s 00005/00000/00188
d D 4.5 85/04/01 15:11:19 ralph 5 4
c add copyright notice
e
s 00002/00002/00186
d D 4.4 85/03/28 09:26:07 ralph 4 3
c name changes and fix return value in res_init().
e
s 00015/00013/00173
d D 4.3 85/03/27 14:58:32 ralph 3 2
c make more machine independent.
e
s 00004/00005/00182
d D 4.2 85/03/15 16:11:07 ralph 2 1
c changed single label to names not ending in '.' as local.
e
s 00187/00000/00000
d D 4.1 85/03/01 10:42:18 ralph 1 0
c date and time created 85/03/01 10:42:18 by ralph
e
u
U
t
T
I 1
D 6
/*	%M%	%I%	%E%	*/

E 6
I 5
/*
D 6
 * Copyright (c) 1985 Regents of the University of California
 *	All Rights Reserved
E 6
I 6
 * Copyright (c) 1985 Regents of the University of California.
D 18
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 18
I 18
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 18
E 6
 */
I 6

D 13
#ifndef lint
E 13
I 13
#if defined(LIBC_SCCS) && !defined(lint)
E 13
static char sccsid[] = "%W% (Berkeley) %G%";
D 13
#endif not lint
E 13
I 13
D 18
#endif LIBC_SCCS and not lint
E 18
I 18
#endif /* LIBC_SCCS and not lint */
E 18
E 13
E 6

E 5
#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
D 8
#include <nameser.h>
#include <resolv.h>
E 8
I 8
#include <arpa/nameser.h>
D 14
#include <arpa/resolv.h>
E 14
I 14
#include <resolv.h>
E 14
E 8

I 11
D 17
extern	char *sprintf();

E 17
E 11
/*
 * Form all types of queries.
 * Returns the size of the result or -1.
 */
D 4
mkquery(op, dname, class, type, data, datalen, newrr, buf, buflen)
E 4
I 4
res_mkquery(op, dname, class, type, data, datalen, newrr, buf, buflen)
E 4
	int op;			/* opcode of query */
	char *dname;		/* domain name */
	int class, type;	/* class and type of query */
	char *data;		/* resource record data */
	int datalen;		/* length of data */
	struct rrec *newrr;	/* new rr for modify or append */
	char *buf;		/* buffer to put query */
	int buflen;		/* size of buffer */
{
	register HEADER *hp;
	register char *cp;
	register int n;
	char dnbuf[MAXDNAME];
	char *dnptrs[10], **dpp, **lastdnptr;
I 3
	extern char *index();
E 3
D 2
	extern char *index();
E 2

I 9
#ifdef DEBUG
E 9
	if (_res.options & RES_DEBUG)
D 4
		printf("mkquery(%d, %s, %d, %d)\n", op, dname, class, type);
E 4
I 4
		printf("res_mkquery(%d, %s, %d, %d)\n", op, dname, class, type);
I 9
D 10
#endif
E 10
I 10
#endif DEBUG
E 10
E 9
E 4
	/*
	 * Initialize header fields.
	 */
	hp = (HEADER *) buf;
	hp->id = htons(++_res.id);
	hp->opcode = op;
	hp->qr = hp->aa = hp->tc = hp->ra = 0;
	hp->pr = (_res.options & RES_PRIMARY) != 0;
	hp->rd = (_res.options & RES_RECURSE) != 0;
	hp->rcode = NOERROR;
	hp->qdcount = 0;
	hp->ancount = 0;
	hp->nscount = 0;
	hp->arcount = 0;
	cp = buf + sizeof(HEADER);
	buflen -= sizeof(HEADER);
	dpp = dnptrs;
	*dpp++ = buf;
	*dpp++ = NULL;
D 2
	lastdnptr = dnptrs + sizeof(dnptrs);
E 2
I 2
	lastdnptr = dnptrs + sizeof(dnptrs)/sizeof(dnptrs[0]);
E 2
	/*
D 2
	 * If the domain name consists of a single label, then
E 2
I 2
D 3
	 * If the domain name does not end in '.', then
E 3
I 3
	 * If the domain name contains no dots (single label), then
E 3
E 2
	 * append the default domain name to the one given.
	 */
D 2
	if ((_res.options & RES_DEFNAMES) && dname[0] != '\0' &&
	    index(dname, '.') == NULL) {
E 2
I 2
D 3
	if ((_res.options & RES_DEFNAMES) && (n = strlen(dname)) > 0 &&
	    dname[n - 1] != '.') {
E 3
I 3
D 10
	if ((_res.options & RES_DEFNAMES) && dname[0] != '\0' &&
E 10
I 10
	if ((_res.options & RES_DEFNAMES) && dname != 0 && dname[0] != '\0' &&
E 10
D 19
	    index(dname, '.') == NULL) {
E 19
I 19
	    index(dname, '.') == NULL && strcasecmp(dname, "localhost")) {
E 19
E 3
E 2
		if (!(_res.options & RES_INIT))
D 9
			res_init();
E 9
I 9
			if (res_init() == -1)
				return(-1);
E 9
D 17
		if (_res.defdname[0] != '\0')
			dname = sprintf(dnbuf, "%s.%s", dname, _res.defdname);
E 17
I 17
		if (_res.defdname[0] != '\0') {
			(void)sprintf(dnbuf, "%s.%s", dname, _res.defdname);
			dname = dnbuf;
		}
E 17
	}
	/*
	 * perform opcode specific processing
	 */
	switch (op) {
	case QUERY:
D 16
	case CQUERYM:
	case CQUERYU:
E 16
		buflen -= QFIXEDSZ;
		if ((n = dn_comp(dname, cp, buflen, dnptrs, lastdnptr)) < 0)
			return (-1);
		cp += n;
		buflen -= n;
D 3
		*((u_short *)cp) = htons(type);
E 3
I 3
		putshort(type, cp);
E 3
		cp += sizeof(u_short);
D 3
		*((u_short *)cp) = htons(class);
E 3
I 3
		putshort(class, cp);
E 3
		cp += sizeof(u_short);
D 7
		hp->qdcount = HTONS(1);
E 7
I 7
		hp->qdcount = htons(1);
E 7
		if (op == QUERY || data == NULL)
			break;
		/*
		 * Make an additional record for completion domain.
		 */
I 3
		buflen -= RRFIXEDSZ;
E 3
		if ((n = dn_comp(data, cp, buflen, dnptrs, lastdnptr)) < 0)
			return (-1);
		cp += n;
		buflen -= n;
D 3
		*((u_short *)cp) = htons(T_NULL);
E 3
I 3
		putshort(T_NULL, cp);
E 3
		cp += sizeof(u_short);
D 3
		*((u_short *)cp) = htons(class);
E 3
I 3
		putshort(class, cp);
E 3
		cp += sizeof(u_short);
D 3
		*((u_long *)cp) = 0;
E 3
I 3
		putlong(0, cp);
E 3
		cp += sizeof(u_long);
D 3
		*((u_short *)cp) = 0;
E 3
I 3
		putshort(0, cp);
E 3
		cp += sizeof(u_short);
D 7
		hp->arcount = HTONS(1);
E 7
I 7
		hp->arcount = htons(1);
E 7
		break;

	case IQUERY:
		/*
		 * Initialize answer section
		 */
		if (buflen < 1 + RRFIXEDSZ + datalen)
			return (-1);
		*cp++ = '\0';	/* no domain name */
D 3
		*((u_short *)cp) = htons(type);
E 3
I 3
		putshort(type, cp);
E 3
		cp += sizeof(u_short);
D 3
		*((u_short *)cp) = htons(class);
E 3
I 3
		putshort(class, cp);
E 3
		cp += sizeof(u_short);
D 3
		*((u_long *)cp) = 0;
E 3
I 3
		putlong(0, cp);
E 3
		cp += sizeof(u_long);
D 3
		*((u_short *)cp) = htons(datalen);
E 3
I 3
		putshort(datalen, cp);
E 3
		cp += sizeof(u_short);
		if (datalen) {
			bcopy(data, cp, datalen);
			cp += datalen;
		}
D 7
		hp->ancount = HTONS(1);
E 7
I 7
		hp->ancount = htons(1);
E 7
		break;

D 15
#ifdef notdef
E 15
I 15
#ifdef ALLOW_UPDATES
	/*
	 * For UPDATEM/UPDATEMA, do UPDATED/UPDATEDA followed by UPDATEA
	 * (Record to be modified is followed by its replacement in msg.)
	 */
	case UPDATEM:
	case UPDATEMA:

E 15
	case UPDATED:
		/*
D 15
		 * Put record to be added or deleted in additional section
E 15
I 15
		 * The res code for UPDATED and UPDATEDA is the same; user
		 * calls them differently: specifies data for UPDATED; server
		 * ignores data if specified for UPDATEDA.
E 15
		 */
I 15
	case UPDATEDA:
E 15
		buflen -= RRFIXEDSZ + datalen;
D 15
		if ((n = dn_comp(dname, cp, buflen, NULL, NULL)) < 0)
E 15
I 15
		if ((n = dn_comp(dname, cp, buflen, dnptrs, lastdnptr)) < 0)
E 15
			return (-1);
		cp += n;
D 15
		*((u_short *)cp) = htons(type);
		cp += sizeof(u_short);
		*((u_short *)cp) = htons(class);
		cp += sizeof(u_short);
		*((u_long *)cp) = 0;
E 15
I 15
		putshort(type, cp);
                cp += sizeof(u_short);
                putshort(class, cp);
                cp += sizeof(u_short);
		putlong(0, cp);
E 15
		cp += sizeof(u_long);
D 15
		*((u_short *)cp) = htons(datalen);
		cp += sizeof(u_short);
E 15
I 15
		putshort(datalen, cp);
                cp += sizeof(u_short);
E 15
		if (datalen) {
			bcopy(data, cp, datalen);
			cp += datalen;
		}
D 15
		break;
E 15
I 15
		if ( (op == UPDATED) || (op == UPDATEDA) ) {
			hp->ancount = htons(0);
			break;
		}
		/* Else UPDATEM/UPDATEMA, so drop into code for UPDATEA */
E 15

D 15
	case UPDATEM:
		/*
		 * Record to be modified followed by its replacement
		 */
E 15
I 15
	case UPDATEA:	/* Add new resource record */
E 15
		buflen -= RRFIXEDSZ + datalen;
		if ((n = dn_comp(dname, cp, buflen, dnptrs, lastdnptr)) < 0)
			return (-1);
		cp += n;
D 15
		*((u_short *)cp) = htons(type);
		cp += sizeof(u_short);
		*((u_short *)cp) = htons(class);
		cp += sizeof(u_short);
		*((u_long *)cp) = 0;
E 15
I 15
		putshort(newrr->r_type, cp);
                cp += sizeof(u_short);
                putshort(newrr->r_class, cp);
                cp += sizeof(u_short);
		putlong(0, cp);
E 15
		cp += sizeof(u_long);
D 15
		*((u_short *)cp) = htons(datalen);
		cp += sizeof(u_short);
		if (datalen) {
			bcopy(data, cp, datalen);
			cp += datalen;
		}

	case UPDATEA:
		buflen -= RRFIXEDSZ + newrr->r_size;
		if ((n = dn_comp(dname, cp, buflen, dnptrs, lastdnptr)) < 0)
			return (-1);
		cp += n;
		*((u_short *)cp) = htons(newrr->r_type);
		cp += sizeof(u_short);
		*((u_short *)cp) = htons(newrr->r_type);
		cp += sizeof(u_short);
		*((u_long *)cp) = htonl(newrr->r_ttl);
		cp += sizeof(u_long);
		*((u_short *)cp) = htons(newrr->r_size);
		cp += sizeof(u_short);
E 15
I 15
		putshort(newrr->r_size, cp);
                cp += sizeof(u_short);
E 15
		if (newrr->r_size) {
			bcopy(newrr->r_data, cp, newrr->r_size);
			cp += newrr->r_size;
		}
I 15
		hp->ancount = htons(0);
E 15
		break;
D 15
#endif
E 15
I 15

#endif ALLOW_UPDATES
E 15
	}
	return (cp - buf);
}
E 1
