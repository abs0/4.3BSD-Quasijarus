h49828
s 00010/00005/00396
d D 6.34 88/06/27 16:42:52 bostic 60 59
c install approved copyright notice
e
s 00001/00001/00400
d D 6.33 88/04/13 09:56:08 karels 59 58
c trivia
e
s 00001/00001/00400
d D 6.32 88/04/12 21:40:12 karels 58 57
c oops
e
s 00035/00173/00366
d D 6.31 88/03/14 09:49:53 bostic 57 56
c new version from Mike Karels
e
s 00010/00004/00529
d D 6.30 88/03/14 09:43:15 bostic 56 55
c add Berkeley specific headers; checked in for Mike Karels
e
s 00003/00003/00530
d D 6.29 88/02/26 15:52:34 karels 55 54
c I give in, #ifdef on h_addr for those that are halfway to 43
e
s 00041/00035/00492
d D 6.28 88/02/18 17:36:22 karels 54 53
c maybe I'll find a way I like: try name from root even if search
c up tree fails other ways; don't try single-component names at root
c without trailing dot
e
s 00017/00007/00510
d D 6.27 87/12/11 10:51:02 bostic 53 52
c disallow names consisting entirely of digits/dots unless they 
c end in a trailing dot
e
s 00016/00006/00501
d D 6.26 87/11/19 21:05:50 karels 52 51
c change dn_skip=>dn_skipname; bigger buffer; watch for bogus non-auth non-answer
e
s 00003/00002/00504
d D 6.25 87/09/14 18:18:23 bostic 51 50
c .hostaliases: perfect match only, allow empty lines
e
s 00006/00001/00500
d D 6.24 87/08/27 17:53:31 karels 50 49
c defeat DEFNAMES if removing trailing '.'; fix typo
e
s 00006/00001/00495
d D 6.23 87/08/03 17:18:32 karels 49 48
c reject numeric hostnames without bothering the root;
c rename strcasencmp
e
s 00014/00013/00482
d D 6.22 87/07/27 17:17:10 bostic 48 47
c checked in for karels; fix NO_ADDRESS error, use C library 
c case-insensitive comparison routines rather than local ones
e
s 00014/00008/00481
d D 6.21 87/07/17 15:38:53 karels 47 46
c portability fixes from dpk
e
s 00016/00005/00473
d D 6.20 87/07/05 23:11:24 bostic 46 45
c make hostalias more paranoid about its input
e
s 00001/00000/00477
d D 6.19 87/06/30 11:36:25 karels 45 44
c clear h_errno on search in case later try succeeds
e
s 00061/00007/00416
d D 6.18 87/05/12 22:11:33 karels 44 43
c try ascending domain tree, starting with local domain,
c even if dots in name; trailing dot forces fully qualified;
c add host aliases, in file with name in environment
e
s 00003/00003/00420
d D 6.17 87/02/12 18:08:49 kjd 43 42
c Fix compatiblity problems with 4.2 and 4.3, #ifdef was wrong in version .-1
e
s 00006/00000/00417
d D 6.16 87/02/09 19:22:49 kjd 42 41
c fix for 4.2bsd
e
s 00003/00003/00414
d D 6.15 87/01/31 15:24:13 kjd 41 40
c change getshort() to _getshort()
e
s 00001/00000/00416
d D 6.14 86/10/30 14:07:25 kjd 40 39
c zero errno
e
s 00002/00001/00414
d D 6.13 86/07/16 19:13:30 sam 39 38
c correct alignment of return values; from burht@el.purdue.edu
e
s 00011/00002/00404
d D 6.12 86/05/19 22:59:24 karels 38 37
c "case-insensitive" when using /etc/hosts
e
s 00001/00002/00405
d D 6.11 86/04/15 10:16:20 kjd 37 36
c remove param.h
e
s 00007/00006/00400
d D 6.10 86/04/10 17:16:20 kjd 36 35
c lint clean up
e
s 00001/00001/00405
d D 6.9 86/03/19 19:48:02 kjd 35 34
c fix _gethtbyaddr()
e
s 00001/00001/00405
d D 6.8 86/03/19 10:19:22 kjd 34 33
c change gethostbyname to do a query of class C_IN insted of C_ANY
e
s 00001/00001/00405
d D 6.7 86/03/17 09:03:53 kjd 33 32
c move resolv.h to /usr/include
e
s 00144/00003/00262
d D 6.6 86/03/14 19:15:06 kjd 32 30
c Add old linear search of /etc/hosts for when the local name server 
c is dead, we recive a ECONNREFUSED.
e
s 00144/00003/00262
d R 6.6 86/03/13 18:59:24 kjd 31 30
c Add liner search of /etc/hosts whan we can't find a local server
e
s 00002/00002/00263
d D 6.5 86/03/09 20:34:51 donn 30 29
c added LIBC_SCCS condition for sccs ids
e
s 00004/00003/00261
d D 6.4 86/02/04 09:08:28 kjd 29 27
c Pass msglen to dn_expand
e
s 00004/00003/00261
d R 6.4 86/02/02 19:39:31 kjd 28 27
c pass msglen to dn_expand
e
s 00038/00018/00226
d D 6.3 85/11/15 10:55:13 kjd 27 26
c Add 4 Error return states and make byte order independent
e
s 00013/00003/00231
d D 6.2 85/11/04 17:54:47 kjd 26 24
c Changes for 4.2bsd from Mike@brl 
e
s 00011/00001/00233
d R 6.2 85/11/04 11:29:51 kjd 25 24
c fix for 4.2bsd from Mike@brl
e
s 00000/00000/00234
d D 6.1 85/10/31 15:30:07 kjd 24 23
c Freeze for November 1 network distribution
e
s 00031/00015/00203
d D 5.10 85/10/25 17:33:45 kjd 23 21
c Buffer alignment code for SUNs
e
s 00031/00015/00203
d R 5.10 85/10/25 16:27:13 kjd 22 21
c Buffer alignment code for SUNs
e
s 00001/00001/00217
d D 5.9 85/10/24 14:50:01 bloom 21 20
c don't let the compiler assume address of structure
e
s 00031/00006/00187
d D 5.8 85/10/10 10:07:01 bloom 20 19
c use PTR instead of inverse query for gethostbyaddr(), accept reply
e
s 00012/00000/00181
d D 5.7 85/09/14 11:19:27 bloom 19 18
c add ifdef DEBUG around debugging code
e
s 00002/00002/00179
d D 5.6 85/09/12 16:58:01 bloom 18 17
c fix which buffers are used
e
s 00049/00031/00132
d D 5.5 85/09/11 16:46:46 bloom 17 16
c implement multiple address return from gethostby* routines
e
s 00000/00109/00163
d D 5.4 85/09/03 12:13:52 bloom 16 15
c get rid of BOMBPROOFING
e
s 00127/00003/00145
d D 5.3 85/09/03 12:11:16 bloom 15 14
c checkin for kjd.  First cut at multiple address returns and BOMBPROOFING
e
s 00002/00007/00146
d D 5.2 85/09/03 12:09:37 bloom 14 13
c fix copyright notices and include paths
e
s 00009/00001/00144
d D 5.1 85/05/30 12:01:42 dist 13 12
c Add copyright
e
s 00005/00000/00140
d D 4.11 85/04/01 15:10:41 ralph 12 11
c add copyright notice
e
s 00008/00006/00132
d D 4.10 85/03/28 09:25:57 ralph 11 10
c name changes and fix return value in res_init().
e
s 00110/00089/00028
d D 4.9 85/03/25 13:51:20 ralph 10 9
c version which uses resolver & name server.
e
s 00002/00002/00115
d D 4.8 85/02/18 17:43:41 bloom 9 8
c use bcopy when alignment isn't known for portability
e
s 00039/00012/00078
d D 4.7 85/01/21 20:27:33 serge 8 6
c made sethostfile work with gethostbyname and gethostbyaddr
c also do linear search of ascii database if dbm database doesn't exist
e
s 00039/00012/00078
d R 4.7 85/01/16 14:38:07 serge 7 6
c made sethostfile work with gethostbyname and gethostbyaddr 
c also do linear search of ascii data base if dbm database doesn't exist
e
s 00004/00002/00086
d D 4.6 85/01/10 09:20:37 ralph 6 5
c make code more portable
e
s 00005/00005/00083
d D 4.5 84/08/28 14:41:36 ralph 5 4
c unify dbm routine names.
e
s 00011/00010/00077
d D 4.4 84/01/31 16:32:03 ralph 4 3
c save data in static area because dbmclose does a free().
e
s 00013/00011/00074
d D 4.3 83/12/21 17:42:34 karels 3 2
c rename shared data for sethostent/gethostbyname-addr and make global
e
s 00011/00004/00074
d D 4.2 83/12/21 10:47:40 ralph 2 1
c modified to leave dbm files open if sethostent(1) used.
e
s 00078/00000/00000
d D 4.1 83/12/05 16:13:05 ralph 1 0
c date and time created 83/12/05 16:13:05 by ralph
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
D 15
 * Copyright (c) 1983 Regents of the University of California.
E 15
I 15
D 17
 * Copyright (c) 1985 Regents of the University of California.
E 17
I 17
D 23
 * Copyright (c) 1983 Regents of the University of California.
E 23
I 23
D 56
 * Copyright (c) 1985 Regents of the University of California.
E 23
E 17
E 15
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 56
I 56
 * Copyright (c) 1985, 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 60
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 60
I 60
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
E 60
E 56
 */

D 30
#ifndef lint
E 30
I 30
#if defined(LIBC_SCCS) && !defined(lint)
E 30
static char sccsid[] = "%W% (Berkeley) %G%";
D 30
#endif not lint
E 30
I 30
D 56
#endif LIBC_SCCS and not lint
E 56
I 56
#endif /* LIBC_SCCS and not lint */
E 56
E 30
E 13

I 12
D 14
/*
 * Copyright (c) 1985 Regents of the University of California
 *	All Rights Reserved
 */

E 14
E 12
D 10
#include <stdio.h>
E 10
I 10
D 27
#include <sys/types.h>
E 27
I 26
D 37
#include <sys/param.h>
E 37
I 37
D 43
#include <sys/types.h>
E 43
I 43
#include <sys/param.h>
E 43
E 37
E 26
#include <sys/socket.h>
#include <netinet/in.h>
I 32
D 37
#include <sys/types.h>
E 37
#include <ctype.h>
E 32
E 10
#include <netdb.h>
D 10
#include <sys/file.h>
#include <ndbm.h>
E 10
I 10
#include <stdio.h>
I 32
#include <errno.h>
I 36
#include <arpa/inet.h>
E 36
E 32
D 14
#include <nameser.h>
#include <resolv.h>
E 14
I 14
#include <arpa/nameser.h>
D 33
#include <arpa/resolv.h>
E 33
I 33
#include <resolv.h>
E 33
E 14
E 10

#define	MAXALIASES	35
I 17
D 57
#define MAXADDRS	35
E 57
I 57
#define	MAXADDRS	35
E 57
E 17

D 8
static char HOSTDB[] = "/etc/hosts";
D 3
static DBM *db = (DBM *)NULL;
E 3
I 3
DBM *_host_db = (DBM *)NULL;
E 8
E 3
D 4
static datum curkey;
E 4
D 15
static struct hostent host;
E 15
I 15
D 17
#define XX 2
static char h_addr_buf[sizeof(struct in_addr) * XX];
static char *h_addr_ptr[XX] = {
	&h_addr_buf[0],
	&h_addr_buf[sizeof(struct in_addr)]
};
static struct hostent host = {
	NULL,		/* official name of host */
	NULL,		/* alias list */
	0,		/* host address type */
	0,		/* length of address */
	h_addr_ptr	/* list of addresses from name server */
};
E 17
I 17
static char *h_addr_ptrs[MAXADDRS + 1];

static struct hostent host;
E 17
E 15
static char *host_aliases[MAXALIASES];
I 4
static char hostbuf[BUFSIZ+1];
I 20
static struct in_addr host_addr;
I 32
static char HOSTDB[] = "/etc/hosts";
static FILE *hostf = NULL;
D 57
static char line[BUFSIZ+1];
E 57
static char hostaddr[MAXADDRS];
static char *host_addrs[2];
static int stayopen = 0;
static char *any();
E 32
E 20
E 4
I 2
D 3
extern int _stayopen;	/* set by sethostent(), cleared by endhostent() */
E 3
I 3
D 8
int _host_stayopen;	/* set by sethostent(), cleared by endhostent() */
E 8
E 3
E 2

I 52
#if PACKETSZ > 1024
D 57
#define MAXPACKET	PACKETSZ
E 57
I 57
#define	MAXPACKET	PACKETSZ
E 57
#else
D 57
#define MAXPACKET	1024
E 57
I 57
#define	MAXPACKET	1024
E 57
#endif

E 52
I 23
typedef union {
D 57
    HEADER qb1;
D 52
    char qb2[PACKETSZ];
E 52
I 52
    char qb2[MAXPACKET];
E 57
I 57
    HEADER hdr;
    u_char buf[MAXPACKET];
E 57
E 52
} querybuf;
E 23
I 15
D 16
#ifdef BOMBPROOFING
#include <ndbm.h>
DBM *_host_db = NULL;
int	_host_stayopen = 0;
int	_host_bombed;
struct hostent *_oldgethostbyname(), *_oldgethostbyaddr();
#endif BOMBPROOFING
E 16

I 23
static union {
    long al;
    char ac;
} align;


I 27
int h_errno;
I 32
extern errno;
E 32

E 27
E 23
E 15
I 8
D 10
/*
 * The following is shared with gethostent.c
 */
extern	char *_host_file;
DBM	*_host_db = (DBM *)NULL;
int	_host_stayopen;	/* set by sethostent(), cleared by endhostent() */

E 10
E 8
static struct hostent *
D 10
fetchhost(key)
	datum key;
E 10
I 10
D 57
getanswer(msg, msglen, iquery)
	char *msg;
	int msglen, iquery;
E 57
I 57
getanswer(answer, anslen, iquery)
	querybuf *answer;
	int anslen;
	int iquery;
E 57
E 10
{
D 4
        register char *cp, **ap;
E 4
I 4
D 10
        register char *cp, *tp, **ap;
E 4
D 9
	register int naliases;
E 9
I 9
	int naliases;
E 10
I 10
	register HEADER *hp;
D 57
	register char *cp;
E 57
I 57
	register u_char *cp;
E 57
	register int n;
D 23
	char answer[PACKETSZ];
E 23
I 23
D 57
	querybuf answer;
E 23
	char *eom, *bp, **ap;
E 57
I 57
	u_char *eom;
	char *bp, **ap;
E 57
D 20
	int type, class, ancount, buflen;
E 20
I 20
D 36
	int type, class, ancount, qdcount, buflen;
E 20
I 17
	int haveanswer, getclass;
E 36
I 36
	int type, class, buflen, ancount, qdcount;
	int haveanswer, getclass = C_ANY;
E 36
	char **hap;
E 17
E 10
E 9

I 15
D 16
#ifdef BOMBPROOFING
	_host_bombed = 0;
#endif BOMBPROOFING
E 16
E 15
D 4
        curkey = key;
        if (curkey.dptr == 0)
E 4
I 4
D 10
        if (key.dptr == 0)
E 4
                return ((struct hostent *)NULL);
D 3
	key = dbmfetch(db, curkey);
E 3
I 3
D 4
	key = dbmfetch(_host_db, curkey);
E 4
I 4
D 5
	key = dbmfetch(_host_db, key);
E 5
I 5
	key = dbm_fetch(_host_db, key);
E 5
E 4
E 3
	if (key.dptr == 0)
                return ((struct hostent *)NULL);
        cp = key.dptr;
D 4
	host.h_name = cp;
	while (*cp++)
E 4
I 4
	tp = hostbuf;
	host.h_name = tp;
	while (*tp++ = *cp++)
E 4
		;
D 9
	naliases = *(int *)cp; cp += sizeof (int);
E 9
I 9
	bcopy(cp, (char *)&naliases, sizeof(int)); cp += sizeof (int);
E 9
	for (ap = host_aliases; naliases > 0; naliases--) {
D 4
		*ap++ = cp;
		while (*cp++)
E 4
I 4
		*ap++ = tp;
		while (*tp++ = *cp++)
E 4
			;
E 10
I 10
D 11
	n = sendquery(msg, msglen, answer, sizeof(answer));
E 11
I 11
D 23
	n = res_send(msg, msglen, answer, sizeof(answer));
E 23
I 23
D 57
	n = res_send(msg, msglen, (char *)&answer, sizeof(answer));
E 23
E 11
	if (n < 0) {
I 19
#ifdef DEBUG
I 32
		int terrno;
		terrno = errno;
E 32
E 19
		if (_res.options & RES_DEBUG)
D 11
			printf("sendquery failed\n");
E 11
I 11
			printf("res_send failed\n");
I 32
		errno = terrno;
E 32
I 19
#endif
I 27
		h_errno = TRY_AGAIN;
E 27
E 19
I 15
D 16
#ifdef BOMBPROOFING
		_host_bombed++;
#endif BOMBPROOFING
E 16
E 15
E 11
D 54
		return (NULL);
E 54
I 54
		return ((struct hostent *) NULL);
E 54
E 10
	}
D 10
	*ap = (char *)NULL;
	host.h_aliases = host_aliases;
D 6
	host.h_addrtype = *(int *)cp; cp += sizeof (int);
	host.h_length = *(int *)cp; cp += sizeof (int);
E 6
I 6
	bcopy(cp, (char *)&host.h_addrtype, sizeof (int));
	cp += sizeof (int);
	bcopy(cp, (char *)&host.h_length, sizeof (int));
	cp += sizeof (int);
E 6
D 4
	host.h_addr = cp;
E 4
I 4
	host.h_addr = tp;
	bcopy(cp, tp, host.h_length);
E 4
        return (&host);
E 10
I 10
D 23
	eom = answer + n;
E 23
I 23
	eom = (char *)&answer + n;
E 57
I 57
	eom = answer->buf + anslen;
E 57
E 23
	/*
	 * find first satisfactory answer
	 */
D 23
	hp = (HEADER *) answer;
E 23
I 23
D 57
	hp = (HEADER *) &answer;
E 57
I 57
	hp = &answer->hdr;
E 57
E 23
	ancount = ntohs(hp->ancount);
I 20
	qdcount = ntohs(hp->qdcount);
E 20
D 57
	if (hp->rcode != NOERROR || ancount == 0) {
I 19
#ifdef DEBUG
E 19
		if (_res.options & RES_DEBUG)
			printf("rcode = %d, ancount=%d\n", hp->rcode, ancount);
I 19
#endif
I 27
		switch (hp->rcode) {
			case NXDOMAIN:
				/* Check if it's an authoritive answer */
				if (hp->aa)
					h_errno = HOST_NOT_FOUND;
				else
					h_errno = TRY_AGAIN;
				break;
			case SERVFAIL:
				h_errno = TRY_AGAIN;
				break;
			case NOERROR:
D 52
				h_errno = NO_ADDRESS;
E 52
I 52
				if (hp->aa)
					h_errno = NO_ADDRESS;
				else
					h_errno = TRY_AGAIN;
E 52
				break;
			case FORMERR:
			case NOTIMP:
			case REFUSED:
				h_errno = NO_RECOVERY;
		}
E 27
E 19
I 15
D 16
#ifdef BOMBPROOFING
		if (!(hp->rcode == NOERROR && ancount == 0))
			_host_bombed++;
#endif BOMBPROOFING
E 16
E 15
D 54
		return (NULL);
E 54
I 54
		return ((struct hostent *) NULL);
E 54
	}
E 57
	bp = hostbuf;
	buflen = sizeof(hostbuf);
D 17
	ap = host_aliases;
E 17
D 23
	cp = answer + sizeof(HEADER);
E 23
I 23
D 57
	cp = (char *)&answer + sizeof(HEADER);
E 57
I 57
	cp = answer->buf + sizeof(HEADER);
E 57
E 23
D 20
	if (hp->qdcount) {
E 20
I 20
	if (qdcount) {
E 20
		if (iquery) {
D 23
			if ((n = dn_expand(answer, cp, bp, buflen)) < 0)
E 23
I 23
D 26
			if ((n = dn_expand((char *)&answer, cp, bp, buflen)) < 
0)
E 26
I 26
D 27
			if ((n = dn_expand((char *)&answer, cp, bp, buflen)) <0)
E 27
I 27
D 29
			if ((n = dn_expand((char *)&answer, cp, bp, buflen)) < 0) {
E 29
I 29
D 57
			if ((n = dn_expand((char *)&answer, eom,
E 57
I 57
			if ((n = dn_expand((char *)answer->buf, eom,
E 57
			     cp, bp, buflen)) < 0) {
E 29
				h_errno = NO_RECOVERY;
E 27
E 26
E 23
D 54
				return (NULL);
E 54
I 54
				return ((struct hostent *) NULL);
E 54
I 27
			}
E 27
			cp += n + QFIXEDSZ;
			host.h_name = bp;
			n = strlen(bp) + 1;
			bp += n;
			buflen -= n;
		} else
D 52
			cp += dn_skip(cp) + QFIXEDSZ;
E 52
I 52
			cp += dn_skipname(cp, eom) + QFIXEDSZ;
E 52
I 20
		while (--qdcount > 0)
D 52
			cp += dn_skip(cp) + QFIXEDSZ;
E 52
I 52
			cp += dn_skipname(cp, eom) + QFIXEDSZ;
E 52
E 20
D 27
	} else if (iquery)
E 27
I 27
	} else if (iquery) {
		if (hp->aa)
			h_errno = HOST_NOT_FOUND;
		else
			h_errno = TRY_AGAIN;
E 27
D 54
		return (NULL);
E 54
I 54
		return ((struct hostent *) NULL);
E 54
I 27
	}
E 27
I 17
	ap = host_aliases;
	host.h_aliases = host_aliases;
	hap = h_addr_ptrs;
I 42
D 43
#ifdef BSD4_3
E 43
I 43
D 55
#if BSD >= 43
E 55
I 55
#if BSD >= 43 || defined(h_addr)	/* new-style hostent structure */
E 55
E 43
E 42
I 26
D 27
#ifdef BSD4_3
E 27
E 26
	host.h_addr_list = h_addr_ptrs;
I 42
D 47
#else
	host.h_addr = h_addr_ptrs[0];
E 47
#endif
E 42
I 26
D 27
#endif
E 27
E 26
	haveanswer = 0;
E 17
	while (--ancount >= 0 && cp < eom) {
D 23
		if ((n = dn_expand(answer, cp, bp, buflen)) < 0)
E 23
I 23
D 29
		if ((n = dn_expand((char *)&answer, cp, bp, buflen)) < 0)
E 29
I 29
D 57
		if ((n = dn_expand((char *)&answer, eom, cp, bp, buflen)) < 0)
E 57
I 57
		if ((n = dn_expand((char *)answer->buf, eom, cp, bp, buflen)) < 0)
E 57
E 29
E 23
D 17
			return (NULL);
E 17
I 17
			break;
E 17
		cp += n;
D 41
		type = getshort(cp);
E 41
I 41
		type = _getshort(cp);
E 41
 		cp += sizeof(u_short);
D 41
		class = getshort(cp);
E 41
I 41
		class = _getshort(cp);
E 41
 		cp += sizeof(u_short) + sizeof(u_long);
D 41
		n = getshort(cp);
E 41
I 41
		n = _getshort(cp);
E 41
		cp += sizeof(u_short);
		if (type == T_CNAME) {
			cp += n;
			if (ap >= &host_aliases[MAXALIASES-1])
				continue;
			*ap++ = bp;
			n = strlen(bp) + 1;
			bp += n;
			buflen -= n;
			continue;
		}
I 20
D 57
		if (type == T_PTR) {
D 23
			if ((n = dn_expand(answer, cp, bp, buflen)) < 0) {
E 23
I 23
D 29
			if ((n = dn_expand((char *)&answer, cp, bp, buflen)) < 
E 29
I 29
D 36
			if ((n = dn_expand((char *)&answer, eom, cp, bp, buflen)) < 
E 29
0) {
E 36
I 36
			if ((n = dn_expand((char *)&answer, eom,
E 57
I 57
		if (iquery && type == T_PTR) {
			if ((n = dn_expand((char *)answer->buf, eom,
E 57
			    cp, bp, buflen)) < 0) {
E 36
E 23
				cp += n;
				continue;
			}
			cp += n;
			host.h_name = bp;
I 26
D 27
#ifdef BSD4_3
E 27
E 26
			return(&host);
I 26
D 27
#else
			haveanswer++;
			break;
#endif
E 27
E 26
		}
E 20
D 17
		if (type != T_A || n != 4) {
E 17
I 17
D 57
		if (type != T_A)  {
E 57
I 57
		if (iquery || type != T_A)  {
E 57
I 19
#ifdef DEBUG
E 19
E 17
			if (_res.options & RES_DEBUG)
				printf("unexpected answer type %d, size %d\n",
					type, n);
I 19
#endif
E 19
I 17
			cp += n;
E 17
			continue;
		}
D 17
		if (!iquery) {
			host.h_name = bp;
			bp += strlen(bp) + 1;
E 17
I 17
		if (haveanswer) {
			if (n != host.h_length) {
				cp += n;
				continue;
			}
			if (class != getclass) {
				cp += n;
				continue;
			}
		} else {
			host.h_length = n;
			getclass = class;
D 26
			host.h_addrtype = C_IN ? AF_INET : AF_UNSPEC;
E 26
I 26
			host.h_addrtype = (class == C_IN) ? AF_INET : AF_UNSPEC;
E 26
			if (!iquery) {
				host.h_name = bp;
				bp += strlen(bp) + 1;
			}
E 17
		}
I 23

D 39
		bp += ((u_long)bp % sizeof(align));
E 39
I 39
D 47
		bp += (sizeof(align) - ((u_long)bp % sizeof(align))) &~
		    sizeof(align);
E 47
I 47
		bp += sizeof(align) - ((u_long)bp % sizeof(align));
E 47
E 39

E 23
D 17
		*ap = NULL;
		host.h_aliases = host_aliases;
		host.h_addrtype = class == C_IN ? AF_INET : AF_UNSPEC;
E 17
		if (bp + n >= &hostbuf[sizeof(hostbuf)]) {
I 19
#ifdef DEBUG
E 19
			if (_res.options & RES_DEBUG)
				printf("size (%d) too big\n", n);
I 19
#endif
E 19
D 17
			return (NULL);
E 17
I 17
			break;
E 17
		}
D 17
		bcopy(cp, host.h_addr = bp, host.h_length = n);
		return (&host);
E 17
I 17
		bcopy(cp, *hap++ = bp, n);
		bp +=n;
		cp += n;
		haveanswer++;
E 17
	}
D 17
	return (NULL);
E 17
I 17
	if (haveanswer) {
		*ap = NULL;
I 47
D 55
#if BSD >= 43
E 55
I 55
#if BSD >= 43 || defined(h_addr)	/* new-style hostent structure */
E 55
E 47
		*hap = NULL;
I 47
#else
		host.h_addr = h_addr_ptrs[0];
#endif
E 47
I 26
D 27
#ifndef BSD4_3
		host.h_addr = h_addr_ptrs[0]; 
#endif
E 27
E 26
		return (&host);
D 27
	} else
E 27
I 27
	} else {
		h_errno = TRY_AGAIN;
E 27
D 54
		return (NULL);
E 54
I 54
		return ((struct hostent *) NULL);
E 54
I 27
	}
E 27
E 17
E 10
}

struct hostent *
D 10
gethostbyname(nam)
D 8
	char *nam;
E 8
I 8
	register char *nam;
E 10
I 10
gethostbyname(name)
	char *name;
E 10
E 8
{
I 44
D 57
	register char *cp, **domain;
E 57
I 57
	querybuf buf;
	register char *cp;
E 57
E 44
D 8
        datum key;
E 8
D 10
	register struct hostent *hp;
I 8
	register char **cp;
        datum key;
E 10
I 10
	int n;
I 17
D 23
	char buf[BUFSIZ+1];
E 23
I 23
D 44
	querybuf buf;
I 32
	register struct hostent *hp;
E 44
I 44
D 59
	struct hostent *hp, *gethostdomain();
E 59
I 59
	struct hostent *hp;
E 59
D 57
	char *hostalias();
E 57
E 44
	extern struct hostent *_gethtbyname();
E 32
E 23
E 17
I 15
D 16
#ifdef BOMBPROOFING
	register struct hostent *hp;
#endif BOMBPROOFING
E 16
E 15
E 10
E 8

I 44
D 57
	if (!(_res.options & RES_INIT) && res_init() == -1)
D 54
		return (NULL);
E 54
I 54
		return ((struct hostent *) NULL);
E 57
E 54
I 49
D 53
	if (isdigit(name[0])) {
		h_errno = HOST_NOT_FOUND;
		return (NULL);
	
	}
E 53
I 53
	/*
	 * disallow names consisting only of digits/dots, unless
	 * they end in a dot.
	 */
	if (isdigit(name[0]))
		for (cp = name;; ++cp) {
			if (!*cp) {
				if (*--cp == '.')
					break;
				h_errno = HOST_NOT_FOUND;
D 54
				return (NULL);
E 54
I 54
				return ((struct hostent *) NULL);
E 54
			}
			if (!isdigit(*cp) && *cp != '.') 
				break;
		}
E 53
E 49
E 44
I 40
D 57
	errno = 0;
E 40
D 2
        if ((db = ndbmopen(HOSTDB, O_RDONLY)) == (DBM *)0)
E 2
I 2
D 3
	if (db == (DBM *)0 && (db = ndbmopen(HOSTDB, O_RDONLY)) == (DBM *)0)
E 3
I 3
D 10
	if ((_host_db == (DBM *)NULL)
D 5
	  && ((_host_db = ndbmopen(HOSTDB, O_RDONLY)) == (DBM *)NULL))
E 5
I 5
D 8
	  && ((_host_db = dbm_open(HOSTDB, O_RDONLY)) == (DBM *)NULL))
E 5
E 3
E 2
                return ((struct hostent *)NULL);
E 8
I 8
	  && ((_host_db = dbm_open(_host_file, O_RDONLY)) == (DBM *)NULL)) {
		sethostent(_host_stayopen);
		while (hp = gethostent()) {
			if (strcmp(hp->h_name, nam) == 0)
				break;
			for (cp = hp->h_aliases; cp != 0 && *cp != 0; cp++)
				if (strcmp(*cp, nam) == 0)
					goto found;
		}
	found:
		if (!_host_stayopen)
			endhostent();
		return (hp);
E 10
I 10
D 11
	n = mkquery(QUERY, name, C_ANY, T_A, NULL, 0, NULL, hostbuf, sizeof(hostbuf));
E 11
I 11
D 17
	n = res_mkquery(QUERY, name, C_ANY, T_A, NULL, 0, NULL,
E 17
I 17
D 34
	n = res_mkquery(QUERY, name, C_ANY, T_A, (char *)NULL, 0, NULL,
E 34
I 34
D 44
	n = res_mkquery(QUERY, name, C_IN, T_A, (char *)NULL, 0, NULL,
E 44
I 44
	for (cp = name, n = 0; *cp; cp++)
		if (*cp == '.')
			n++;
D 47
	if ((n && cp[-1] == '.') || (_res.options & RES_DEFNAMES) == 0) {
		cp[-1] = 0;
E 47
I 47
D 54
	if ((n && *--cp == '.') || (_res.options & RES_DEFNAMES) == 0) {
I 50
		int defflag = _res.options & RES_DEFNAMES;

		_res.options &= ~RES_DEFNAMES;			/* XXX */
E 50
		if (n && *cp == '.')
D 53
			*cp = 0;
E 53
I 53
			*cp = '\0';
E 53
E 47
		hp = gethostdomain(name, (char *)NULL);
D 47
		cp[-1] = '.';
E 47
I 47
D 50
		if (n && cp == 0)
E 50
I 50
D 53
		if (n && *cp == 0)
E 53
I 53
		if (n && *cp == '\0')
E 53
E 50
			*cp = '.';
I 50
		if (defflag)
			_res.options |= RES_DEFNAMES;
E 50
E 47
		return (hp);
	}
E 54
	if (n == 0 && (cp = hostalias(name)))
		return (gethostdomain(cp, (char *)NULL));
D 54
	for (domain = _res.dnsrch; *domain; domain++) {
E 54
I 54
	if ((n == 0 || *--cp != '.') && (_res.options & RES_DEFNAMES))
	    for (domain = _res.dnsrch; *domain; domain++) {
E 54
		hp = gethostdomain(name, *domain);
		if (hp)
			return (hp);
I 48
		/*
		 * If no server present, use host table.
		 * If host isn't found in this domain,
		 * keep trying higher domains in the search list
		 * (if that's enabled).
D 54
		 * On a NO_ADDRESS error, keep trying,
		 * or a wildcard MX entry could keep us from finding
E 54
I 54
		 * On a NO_ADDRESS error, keep trying, otherwise
		 * a wildcard MX entry could keep us from finding
E 54
		 * host entries higher in the domain.
I 54
		 * If we get some other error (non-authoritative negative
		 * answer or server failure), then stop searching up,
		 * but try the input name below in case it's fully-qualified.
E 54
		 */
E 48
		if (errno == ECONNREFUSED)
			return (_gethtbyname(name));
D 48
		if (h_errno != HOST_NOT_FOUND ||
E 48
I 48
D 54
		if ((h_errno != HOST_NOT_FOUND &&
		    h_errno != NO_ADDRESS) ||
E 54
I 54
		if ((h_errno != HOST_NOT_FOUND && h_errno != NO_ADDRESS) ||
E 54
E 48
		    (_res.options & RES_DNSRCH) == 0)
D 54
			return (NULL);
E 54
I 54
			break;
E 54
I 45
		h_errno = 0;
E 45
	}
D 54
	return (gethostdomain(name, (char *)NULL));
E 54
I 54
	/*
	 * If the search/default failed, try the name as fully-qualified,
	 * but only if it contained at least one dot (even trailing).
	 */
	if (n)
		return (gethostdomain(name, (char *)NULL));
	return ((struct hostent *) NULL);
E 54
}
E 57

D 57
static struct hostent *
gethostdomain(name, domain)
	char *name, *domain;
{
	querybuf buf;
	char nbuf[2*MAXDNAME+2];
I 54
	char *longname = nbuf;
E 54
	int n;

D 47
	sprintf(nbuf, "%.*s.%.*s", MAXDNAME, name, MAXDNAME, domain);
E 47
I 47
D 54
	if (domain == NULL)
D 52
		sprintf(nbuf, "%.*s", MAXDNAME, name);
E 52
I 52
		(void)sprintf(nbuf, "%.*s", MAXDNAME, name);
E 52
	else
E 54
I 54
	if (domain == NULL) {
		/*
		 * Check for trailing '.';
		 * copy without '.' if present.
		 */
		n = strlen(name) - 1;
		if (name[n] == '.' && n < sizeof(nbuf) - 1) {
			bcopy(name, nbuf, n);
			nbuf[n] = '\0';
		} else
			longname = name;
	} else
E 54
D 52
		sprintf(nbuf, "%.*s.%.*s", MAXDNAME, name, MAXDNAME, domain);
E 52
I 52
		(void)sprintf(nbuf, "%.*s.%.*s",
		    MAXDNAME, name, MAXDNAME, domain);
E 52
E 47
D 54
	n = res_mkquery(QUERY, nbuf, C_IN, T_A, (char *)NULL, 0, NULL,
E 54
I 54
	n = res_mkquery(QUERY, longname, C_IN, T_A, (char *)NULL, 0, NULL,
E 54
E 44
E 34
E 17
D 18
		hostbuf, sizeof(hostbuf));
E 18
I 18
D 23
		buf, sizeof(buf));
E 23
I 23
		(char *)&buf, sizeof(buf));
E 23
E 18
E 11
	if (n < 0) {
E 57
I 57
	if ((n = res_search(name, C_IN, T_A, buf.buf, sizeof(buf))) < 0) {
E 57
I 19
#ifdef DEBUG
E 19
		if (_res.options & RES_DEBUG)
D 11
			printf("mkquery failed\n");
E 11
I 11
D 57
			printf("res_mkquery failed\n");
E 57
I 57
			printf("res_search failed\n");
E 57
I 19
#endif
E 19
E 11
D 54
		return (NULL);
E 54
I 54
D 57
		return ((struct hostent *) NULL);
E 57
I 57
		if (errno == ECONNREFUSED)
			return (_gethtbyname(name));
		else
			return ((struct hostent *) NULL);
E 57
E 54
I 15
D 16
#ifndef BOMBPROOFING
E 16
E 15
E 10
	}
E 8
D 10
        key.dptr = nam;
        key.dsize = strlen(nam);
	hp = fetchhost(key);
D 2
	ndbmclose(db);
E 2
I 2
D 3
	if (!_stayopen) {
		ndbmclose(db);
		db = (DBM *)NULL;
E 3
I 3
	if (!_host_stayopen) {
D 5
		ndbmclose(_host_db);
E 5
I 5
		dbm_close(_host_db);
E 5
		_host_db = (DBM *)NULL;
E 3
	}
E 2
        return (hp);
E 10
I 10
D 15
	return (getanswer(hostbuf, n, 0));
E 15
I 15
D 17
	return(getanswer(hostbuf, n, 0));
E 17
I 17
D 23
	return(getanswer(buf, n, 0));
E 23
I 23
D 32
	return(getanswer((char *)&buf, n, 0));
E 32
I 32
D 44
	hp = getanswer((char *)&buf, n, 0);
	if (hp == NULL && errno == ECONNREFUSED)
		hp = _gethtbyname(name);
	return(hp);
E 44
I 44
D 57
	return (getanswer((char *)&buf, n, 0));
E 57
I 57
	return (getanswer(&buf, n, 0));
E 57
E 44
E 32
E 23
E 17
D 16
#else
	} else
		hp = getanswer(hostbuf, n, 0);
	if (n < 0 || (hp == NULL && _host_bombed))
		return (_oldgethostbyname(name));
	else
		return (hp);
#endif BOMBPROOFING
E 16
E 15
E 10
}

struct hostent *
D 8
gethostbyaddr(addr, length)
E 8
I 8
D 10
gethostbyaddr(addr, length, type)
E 10
I 10
gethostbyaddr(addr, len, type)
E 10
E 8
	char *addr;
D 8
	int length;
E 8
I 8
D 10
	register int length;
	register int type;
E 10
I 10
	int len, type;
E 10
E 8
{
D 8
        datum key;
E 8
D 10
	register struct hostent *hp;
I 8
        datum key;
E 10
I 10
	int n;
I 17
D 23
	char buf[BUFSIZ+1];
E 23
I 23
	querybuf buf;
E 23
I 20
	register struct hostent *hp;
	char qbuf[MAXDNAME];
E 20
E 17
I 15
D 16
#ifdef BOMBPROOFING
	register struct hostent *hp;
#endif BOMBPROOFING
E 16
E 15
E 10
E 8
D 32

E 32
I 32
	extern struct hostent *_gethtbyaddr();
	
E 32
D 2
        if ((db = ndbmopen(HOSTDB, O_RDONLY)) == (DBM *)0)
E 2
I 2
D 3
	if (db == (DBM *)0 && (db = ndbmopen(HOSTDB, O_RDONLY)) == (DBM *)0)
E 3
I 3
D 10
	if ((_host_db == (DBM *)NULL)
D 5
	  && ((_host_db = ndbmopen(HOSTDB, O_RDONLY)) == (DBM *)NULL))
E 5
I 5
D 8
	  && ((_host_db = dbm_open(HOSTDB, O_RDONLY)) == (DBM *)NULL))
E 5
E 3
E 2
                return ((struct hostent *)NULL);
E 8
I 8
	  && ((_host_db = dbm_open(_host_file, O_RDONLY)) == (DBM *)NULL)) {
		sethostent(_host_stayopen);
		while (hp = gethostent()) {
			if (hp->h_addrtype == type && hp->h_length == length
			    && bcmp(hp->h_addr, addr, length) == 0)
				break;
		}
		if (!_host_stayopen)
			endhostent();
		return (hp);
E 10
I 10
	if (type != AF_INET)
D 54
		return (NULL);
E 54
I 54
		return ((struct hostent *) NULL);
E 54
D 11
	n = mkquery(IQUERY, NULL, C_IN, T_A, addr, len, NULL, hostbuf, sizeof(hostbuf));
E 11
I 11
D 17
	n = res_mkquery(IQUERY, NULL, C_IN, T_A, addr, len, NULL,
E 17
I 17
D 20
	n = res_mkquery(IQUERY, (char *)NULL, C_IN, T_A, addr, len, NULL,
E 20
I 20
	(void)sprintf(qbuf, "%d.%d.%d.%d.in-addr.arpa",
D 27
		(*(unsigned *)addr >> 24 & 0xff),
		(*(unsigned *)addr >> 16 & 0xff),
		(*(unsigned *)addr >> 8 & 0xff),
		(*(unsigned *)addr & 0xff));
E 27
I 27
		((unsigned)addr[3] & 0xff),
		((unsigned)addr[2] & 0xff),
		((unsigned)addr[1] & 0xff),
		((unsigned)addr[0] & 0xff));
E 27
D 36
	n = res_mkquery(QUERY, qbuf, C_IN, T_PTR, NULL, 0, NULL,
E 36
I 36
D 57
	n = res_mkquery(QUERY, qbuf, C_IN, T_PTR, (char *)NULL, 0, NULL,
E 36
E 20
E 17
D 18
		hostbuf, sizeof(hostbuf));
E 18
I 18
D 23
		buf, sizeof(buf));
E 23
I 23
		(char *)&buf, sizeof(buf));
E 57
I 57
	n = res_query(qbuf, C_IN, T_PTR, (char *)&buf, sizeof(buf));
E 57
E 23
E 18
E 11
	if (n < 0) {
I 19
#ifdef DEBUG
E 19
		if (_res.options & RES_DEBUG)
D 11
			printf("mkquery failed\n");
E 11
I 11
D 57
			printf("res_mkquery failed\n");
E 57
I 57
			printf("res_query failed\n");
E 57
I 19
#endif
I 57
		if (errno == ECONNREFUSED)
D 58
			hp = _gethtbyaddr(addr, len, type);
E 58
I 58
			return (_gethtbyaddr(addr, len, type));
E 58
E 57
E 19
E 11
D 54
		return (NULL);
E 54
I 54
		return ((struct hostent *) NULL);
E 54
I 15
D 16
#ifndef BOMBPROOFING
E 16
E 15
E 10
	}
E 8
D 10
        key.dptr = addr;
        key.dsize = length;
	hp = fetchhost(key);
D 2
	ndbmclose(db);
E 2
I 2
D 3
	if (!_stayopen) {
		ndbmclose(db);
		db = (DBM *)NULL;
E 3
I 3
	if (!_host_stayopen) {
D 5
		ndbmclose(_host_db);
E 5
I 5
		dbm_close(_host_db);
E 5
		_host_db = (DBM *)NULL;
E 3
	}
E 2
        return (hp);
E 10
I 10
D 17
	return (getanswer(hostbuf, n, 1));
E 17
I 17
D 20
	return(getanswer(buf, n, 1));
E 20
I 20
D 23
	if ((hp = getanswer(buf, n, 1)) == NULL)
E 23
I 23
D 32
	if ((hp = getanswer((char *)&buf, n, 1)) == NULL)
E 32
I 32
D 57
	hp = getanswer((char *)&buf, n, 1);
	if (hp == NULL && errno == ECONNREFUSED)
		hp = _gethtbyaddr(addr, len, type);
E 57
I 57
	hp = getanswer(&buf, n, 1);
E 57
	if (hp == NULL)
E 32
E 23
D 54
		return(NULL);
E 54
I 54
		return ((struct hostent *) NULL);
E 54
	hp->h_addrtype = type;
	hp->h_length = len;
D 21
	h_addr_ptrs[0] = (char *)host_addr;
E 21
I 21
	h_addr_ptrs[0] = (char *)&host_addr;
E 21
	h_addr_ptrs[1] = (char *)0;
	host_addr = *(struct in_addr *)addr;
	return(hp);
E 20
E 17
I 15
D 16
#else
	} else
		hp = getanswer(hostbuf, n, 1);
	if (n < 0 || (hp == NULL && _host_bombed))
		return (_oldgethostbyaddr(addr));
	else
		return (hp);
#endif BOMBPROOFING
E 16
E 15
E 10
}
I 23

I 44
D 57
char *
hostalias(name)
	register char *name;
{
I 46
	register char *C1, *C2;
E 46
	FILE *fp;
D 46
	char *file, *getenv();
E 46
I 46
	char *file, *getenv(), *strcpy(), *strncpy();
	char buf[BUFSIZ];
E 46
	static char abuf[MAXDNAME];
D 46
	char nbuf[MAXDNAME];
	int n;
E 46

	file = getenv("HOSTALIASES");
	if (file == NULL || (fp = fopen(file, "r")) == NULL)
		return (NULL);
D 46
	while ((n = fscanf(fp, "%s %s\n", nbuf, abuf)) != EOF)
		if (strcmp(nbuf, name) == 0) {
E 46
I 46
	buf[sizeof(buf) - 1] = '\0';
	while (fgets(buf, sizeof(buf), fp)) {
		for (C1 = buf; *C1 && !isspace(*C1); ++C1);
D 51
		if (!*C1 || *C1 == '\n')
E 51
I 51
		if (!*C1)
E 51
			break;
D 48
		if (!strncmp(buf, name, C1 - buf)) {
E 48
I 48
D 49
		if (!strcasencmp(buf, name, C1 - buf)) {
E 49
I 49
D 51
		if (!strncasecmp(buf, name, C1 - buf)) {
E 51
I 51
		*C1 = '\0';
		if (!strcasecmp(buf, name)) {
E 51
E 49
E 48
			while (isspace(*++C1));
			if (!*C1)
				break;
			for (C2 = C1 + 1; *C2 && !isspace(*C2); ++C2);
			abuf[sizeof(abuf) - 1] = *C2 = '\0';
			(void)strncpy(abuf, C1, sizeof(abuf) - 1);
E 46
			fclose(fp);
			return (abuf);
		}
I 46
	}
E 46
	fclose(fp);
	return (NULL);
}
E 44
I 32

E 57
_sethtent(f)
	int f;
{
	if (hostf == NULL)
		hostf = fopen(HOSTDB, "r" );
	else
		rewind(hostf);
	stayopen |= f;
}

_endhtent()
{
	if (hostf && !stayopen) {
D 36
		fclose(hostf);
E 36
I 36
		(void) fclose(hostf);
E 36
		hostf = NULL;
	}
}

struct hostent *
_gethtent()
{
	char *p;
	register char *cp, **q;

	if (hostf == NULL && (hostf = fopen(HOSTDB, "r" )) == NULL)
		return (NULL);
again:
D 57
	if ((p = fgets(line, BUFSIZ, hostf)) == NULL)
E 57
I 57
	if ((p = fgets(hostbuf, BUFSIZ, hostf)) == NULL)
E 57
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
	/* THIS STUFF IS INTERNET SPECIFIC */
I 42
D 43
#ifdef BSD4_3
E 43
I 43
D 55
#if	BSD >= 43
E 55
I 55
#if BSD >= 43 || defined(h_addr)	/* new-style hostent structure */
E 55
E 43
E 42
	host.h_addr_list = host_addrs;
I 42
#endif
E 42
	host.h_addr = hostaddr;
	*((u_long *)host.h_addr) = inet_addr(p);
	host.h_length = sizeof (u_long);
	host.h_addrtype = AF_INET;
	while (*cp == ' ' || *cp == '\t')
		cp++;
	host.h_name = cp;
	q = host.h_aliases = host_aliases;
	cp = any(cp, " \t");
	if (cp != NULL) 
		*cp++ = '\0';
	while (cp && *cp) {
		if (*cp == ' ' || *cp == '\t') {
			cp++;
			continue;
		}
		if (q < &host_aliases[MAXALIASES - 1])
			*q++ = cp;
		cp = any(cp, " \t");
		if (cp != NULL)
			*cp++ = '\0';
	}
	*q = NULL;
	return (&host);
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

struct hostent *
_gethtbyname(name)
	char *name;
{
	register struct hostent *p;
	register char **cp;
I 38
D 48
	char lowname[128];
	register char *lp = lowname;
E 48
	
D 48
	while (*name)
		if (isupper(*name))
			*lp++ = tolower(*name++);
		else
			*lp++ = *name++;
	*lp = '\0';
E 38

E 48
	_sethtent(0);
	while (p = _gethtent()) {
D 38
		if (strcmp(p->h_name, name) == 0)
E 38
I 38
D 48
		if (strcmp(p->h_name, lowname) == 0)
E 48
I 48
		if (strcasecmp(p->h_name, name) == 0)
E 48
E 38
			break;
		for (cp = p->h_aliases; *cp != 0; cp++)
D 38
			if (strcmp(*cp, name) == 0)
E 38
I 38
D 48
			if (strcmp(*cp, lowname) == 0)
E 48
I 48
			if (strcasecmp(*cp, name) == 0)
E 48
E 38
				goto found;
	}
found:
	_endhtent();
	return (p);
}

struct hostent *
_gethtbyaddr(addr, len, type)
	char *addr;
	int len, type;
{
	register struct hostent *p;

	_sethtent(0);
	while (p = _gethtent())
D 35
		if (p->h_addrtype == type && bcmp(p->h_addr, addr, len))
E 35
I 35
		if (p->h_addrtype == type && !bcmp(p->h_addr, addr, len))
E 35
			break;
	_endhtent();
	return (p);
}
E 32
E 23
I 15
D 20

D 16
#ifdef BOMBPROOFING
static
struct hostent *
_oldgethostbyname(name)
	register char *name;
{
	register struct hostent *hp;
	register char **cp;
        datum key;

	if ((_host_db == (DBM *)NULL)
	  && ((_host_db = dbm_open(_host_file, O_RDONLY)) == (DBM *)NULL)) {
		sethostent(_host_stayopen);
		while (hp = gethostent()) {
			if (strcmp(hp->h_name, nam) == 0)
				break;
			for (cp = hp->h_aliases; cp != 0 && *cp != 0; cp++)
				if (strcmp(*cp, nam) == 0)
					goto found;
		}
	found:
		if (!_host_stayopen)
			endhostent();
		return (hp);
	}
        key.dptr = nam;
        key.dsize = strlen(nam);
	hp = fetchhost(key);
	if (!_host_stayopen) {
		dbm_close(_host_db);
		_host_db = (DBM *)NULL;
	}
        return (hp);
}


static
struct hostent *
_oldgethostbyaddr(addr, len, type)
	char *addr;
	register int len, type;
{

	register struct hostent *hp;
        datum key;

	if ((_host_db == (DBM *)NULL)
	  && ((_host_db = dbm_open(_host_file, O_RDONLY)) == (DBM *)NULL)) {
		sethostent(_host_stayopen);
		while (hp = gethostent()) {
			if (hp->h_addrtype == type && hp->h_length == length
			    && bcmp(hp->h_addr, addr, length) == 0)
				break;
		}
		if (!_host_stayopen)
			endhostent();
		return (hp);
	}
        key.dptr = addr;
        key.dsize = length;
	hp = fetchhost(key);
	if (!_host_stayopen) {
		dbm_close(_host_db);
		_host_db = (DBM *)NULL;
	}
        return (hp);
}
#endif BOMBPROOFING
E 16

E 20
E 15
E 1
