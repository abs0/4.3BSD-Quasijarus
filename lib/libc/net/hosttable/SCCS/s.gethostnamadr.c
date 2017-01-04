h27147
s 00010/00005/00146
d D 5.7 88/06/27 16:43:51 bostic 21 20
c install approved copyright notice
e
s 00009/00003/00142
d D 5.6 88/03/07 21:10:48 bostic 20 19
c added Berkeley specific headers
e
s 00002/00002/00143
d D 5.5 86/03/09 20:33:06 donn 19 18
c added LIBC_SCCS condition for sccs ids
e
s 00008/00000/00137
d D 5.4 86/01/09 23:21:45 kjd 18 17
c Add h_errno error status return
e
s 00014/00004/00123
d D 5.3 85/12/10 18:29:38 kjd 17 16
c Add case insensitivity to gethostbyname() from Jay Lepreau
e
s 00002/00000/00125
d D 5.2 85/09/10 10:29:09 bloom 16 14
c modify to use new hostent structure
e
s 00014/00108/00017
d R 5.2 85/07/19 18:12:25 kjd 15 14
c Split gethostnamadr.c into 3 files one for each routine 
c gethostbyname(), gethostbyaddr() and getanswer()
e
s 00009/00001/00116
d D 5.1 85/06/06 09:00:43 bloom 14 9
c add copyright notice
e
s 00009/00001/00144
d R 5.1 85/05/30 12:01:42 dist 13 12
c Add copyright
e
s 00005/00000/00140
d R 4.11 85/04/01 15:10:41 ralph 12 11
c add copyright notice
e
s 00008/00006/00132
d R 4.10 85/03/28 09:25:57 ralph 11 10
c name changes and fix return value in res_init().
e
s 00110/00089/00028
d R 4.9 85/03/25 13:51:20 ralph 10 9
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
D 14
/*	%M%	%I%	%E%	*/
E 14
I 14
/*
 * Copyright (c) 1983 Regents of the University of California.
D 20
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 20
I 20
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 21
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 21
I 21
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
E 21
E 20
 */

D 19
#ifndef lint
E 19
I 19
#if defined(LIBC_SCCS) && !defined(lint)
E 19
static char sccsid[] = "%W% (Berkeley) %G%";
D 19
#endif not lint
E 19
I 19
D 20
#endif LIBC_SCCS and not lint
E 20
I 20
#endif /* LIBC_SCCS and not lint */
E 20
E 19
E 14

#include <stdio.h>
#include <netdb.h>
#include <sys/file.h>
#include <ndbm.h>
I 17
#include <ctype.h>
E 17

#define	MAXALIASES	35

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
static struct hostent host;
static char *host_aliases[MAXALIASES];
I 4
static char hostbuf[BUFSIZ+1];
I 16
static char *host_addrs[2];
E 16
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

I 18
int h_errno;

E 18
I 8
/*
 * The following is shared with gethostent.c
 */
extern	char *_host_file;
DBM	*_host_db = (DBM *)NULL;
int	_host_stayopen;	/* set by sethostent(), cleared by endhostent() */

E 8
static struct hostent *
fetchhost(key)
	datum key;
{
D 4
        register char *cp, **ap;
E 4
I 4
        register char *cp, *tp, **ap;
E 4
D 9
	register int naliases;
E 9
I 9
	int naliases;
E 9

D 4
        curkey = key;
        if (curkey.dptr == 0)
E 4
I 4
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
	}
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
I 16
	host.h_addr_list = host_addrs;
E 16
E 6
D 4
	host.h_addr = cp;
E 4
I 4
	host.h_addr = tp;
	bcopy(cp, tp, host.h_length);
E 4
        return (&host);
}

struct hostent *
gethostbyname(nam)
D 8
	char *nam;
E 8
I 8
	register char *nam;
E 8
{
D 8
        datum key;
E 8
	register struct hostent *hp;
I 8
	register char **cp;
        datum key;
I 17
	char lowname[128];
	register char *lp = lowname;
	
	while (*nam)
		if (isupper(*nam))
			*lp++ = tolower(*nam++);
		else
			*lp++ = *nam++;
	*lp = '\0';
E 17
E 8

D 2
        if ((db = ndbmopen(HOSTDB, O_RDONLY)) == (DBM *)0)
E 2
I 2
D 3
	if (db == (DBM *)0 && (db = ndbmopen(HOSTDB, O_RDONLY)) == (DBM *)0)
E 3
I 3
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
D 17
			if (strcmp(hp->h_name, nam) == 0)
E 17
I 17
			if (strcmp(hp->h_name, lowname) == 0)
E 17
				break;
			for (cp = hp->h_aliases; cp != 0 && *cp != 0; cp++)
D 17
				if (strcmp(*cp, nam) == 0)
E 17
I 17
				if (strcmp(*cp, lowname) == 0)
E 17
					goto found;
		}
	found:
		if (!_host_stayopen)
			endhostent();
		return (hp);
	}
E 8
D 17
        key.dptr = nam;
        key.dsize = strlen(nam);
E 17
I 17
        key.dptr = lowname;
        key.dsize = strlen(lowname);
E 17
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
I 18
	if ( hp == NULL)
		h_errno = HOST_NOT_FOUND;
E 18
E 2
        return (hp);
}

struct hostent *
D 8
gethostbyaddr(addr, length)
E 8
I 8
gethostbyaddr(addr, length, type)
E 8
	char *addr;
D 8
	int length;
E 8
I 8
	register int length;
	register int type;
E 8
{
D 8
        datum key;
E 8
	register struct hostent *hp;
I 8
        datum key;
E 8

D 2
        if ((db = ndbmopen(HOSTDB, O_RDONLY)) == (DBM *)0)
E 2
I 2
D 3
	if (db == (DBM *)0 && (db = ndbmopen(HOSTDB, O_RDONLY)) == (DBM *)0)
E 3
I 3
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
I 18
		if ( hp == NULL)
			h_errno = HOST_NOT_FOUND;
E 18
		return (hp);
	}
E 8
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
I 18
	if ( hp == NULL)
		h_errno = HOST_NOT_FOUND;
E 18
E 2
        return (hp);
}
E 1
