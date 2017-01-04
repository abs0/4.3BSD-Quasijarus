h19419
s 00001/00001/00250
d D 5.5 99/09/28 16:41:47 msokolov 5 4
c let a query for "localhost" go out to the name server
e
s 00000/00001/00251
d D 5.4 88/04/21 09:53:36 karels 4 3
c finish the fix
e
s 00014/00005/00238
d D 5.3 88/04/05 14:18:25 karels 3 2
c return NO_DATA instead of HOST_NOT_FOUND from res_search
c if we ever get a NO_DATA response; add res_querydomain debug line
e
s 00005/00009/00238
d D 5.2 88/03/29 11:13:22 karels 2 1
c don't check auth. bit on NXDOMAIN/noanswer (ready for neg. caching);
c add default error case
e
s 00247/00000/00000
d D 5.1 88/03/14 13:04:59 bostic 1 0
c date and time created 88/03/14 13:04:59 by bostic
e
u
U
f b 
t
T
I 1
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 */

#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* LIBC_SCCS and not lint */

#include <sys/param.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>
#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <strings.h>
#include <arpa/inet.h>
#include <arpa/nameser.h>
#include <resolv.h>

#if PACKETSZ > 1024
#define MAXPACKET	PACKETSZ
#else
#define MAXPACKET	1024
#endif

extern int errno;
int h_errno;

/*
 * Formulate a normal query, send, and await answer.
 * Returned answer is placed in supplied buffer "answer".
 * Perform preliminary check of answer, returning success only
 * if no error is indicated and the answer count is nonzero.
 * Return the size of the response on success, -1 on error.
 * Error number is left in h_errno.
I 2
 * Caller must parse answer and determine whether it answers the question.
E 2
 */
res_query(name, class, type, answer, anslen)
	char *name;		/* domain name */
	int class, type;	/* class and type of query */
	u_char *answer;		/* buffer to put answer */
	int anslen;		/* size of answer buffer */
{
	char buf[MAXPACKET];
	HEADER *hp;
	int n;

	if ((_res.options & RES_INIT) == 0 && res_init() == -1)
		return (-1);
#ifdef DEBUG
	if (_res.options & RES_DEBUG)
		printf("res_query(%s, %d, %d)\n", name, class, type);
#endif
	n = res_mkquery(QUERY, name, class, type, (char *)NULL, 0, NULL,
	    buf, sizeof(buf));

	if (n <= 0) {
#ifdef DEBUG
		if (_res.options & RES_DEBUG)
			printf("res_query: mkquery failed\n");
#endif
		h_errno = NO_RECOVERY;
		return (n);
	}
	n = res_send(buf, n, answer, anslen);
	if (n < 0) {
#ifdef DEBUG
		if (_res.options & RES_DEBUG)
			printf("res_query: send error\n");
#endif
		h_errno = TRY_AGAIN;
		return(n);
	}

	hp = (HEADER *) answer;
	if (hp->rcode != NOERROR || ntohs(hp->ancount) == 0) {
#ifdef DEBUG
		if (_res.options & RES_DEBUG)
			printf("rcode = %d, ancount=%d\n", hp->rcode,
			    ntohs(hp->ancount));
#endif
		switch (hp->rcode) {
			case NXDOMAIN:
D 2
				/* Check if it's an authoritive answer */
				if (hp->aa)
					h_errno = HOST_NOT_FOUND;
				else
					h_errno = TRY_AGAIN;
E 2
I 2
				h_errno = HOST_NOT_FOUND;
E 2
				break;
			case SERVFAIL:
				h_errno = TRY_AGAIN;
				break;
			case NOERROR:
D 2
				if (hp->aa)
					h_errno = NO_ADDRESS;
				else
					h_errno = TRY_AGAIN;
E 2
I 2
D 3
				h_errno = NO_ADDRESS;
E 3
I 3
				h_errno = NO_DATA;
E 3
E 2
				break;
			case FORMERR:
			case NOTIMP:
			case REFUSED:
I 2
			default:
E 2
				h_errno = NO_RECOVERY;
I 2
				break;
E 2
		}
		return (-1);
	}
	return(n);
}

/*
 * Formulate a normal query, send, and retrieve answer in supplied buffer.
 * Return the size of the response on success, -1 on error.
 * If enabled, implement search rules until answer or unrecoverable failure
 * is detected.  Error number is left in h_errno.
 * Only useful for queries in the same name hierarchy as the local host
 * (not, for example, for host address-to-name lookups in domain in-addr.arpa).
 */
res_search(name, class, type, answer, anslen)
	char *name;		/* domain name */
	int class, type;	/* class and type of query */
	u_char *answer;		/* buffer to put answer */
	int anslen;		/* size of answer */
{
	register char *cp, **domain;
D 3
	int n, ret;
E 3
I 3
	int n, ret, got_nodata = 0;
E 3
	char *hostalias();

	if ((_res.options & RES_INIT) == 0 && res_init() == -1)
		return (-1);

	errno = 0;
I 3
	h_errno = HOST_NOT_FOUND;		/* default, if we never query */
E 3
	for (cp = name, n = 0; *cp; cp++)
		if (*cp == '.')
			n++;
	if (n == 0 && (cp = hostalias(name)))
		return (res_query(cp, class, type, answer, anslen));

	if ((n == 0 || *--cp != '.') && (_res.options & RES_DEFNAMES))
	    for (domain = _res.dnsrch; *domain; domain++) {
		ret = res_querydomain(name, *domain, class, type,
		    answer, anslen);
		if (ret > 0)
			return (ret);
		/*
		 * If no server present, give up.
		 * If name isn't found in this domain,
		 * keep trying higher domains in the search list
		 * (if that's enabled).
D 3
		 * On a NO_ADDRESS error, keep trying, otherwise
E 3
I 3
		 * On a NO_DATA error, keep trying, otherwise
E 3
		 * a wildcard entry of another type could keep us
		 * from finding this entry higher in the domain.
		 * If we get some other error (non-authoritative negative
		 * answer or server failure), then stop searching up,
		 * but try the input name below in case it's fully-qualified.
		 */
		if (errno == ECONNREFUSED) {
			h_errno = TRY_AGAIN;
			return (-1);
		}
D 3
		if ((h_errno != HOST_NOT_FOUND && h_errno != NO_ADDRESS) ||
E 3
I 3
		if (h_errno == NO_DATA)
			got_nodata++;
		if ((h_errno != HOST_NOT_FOUND && h_errno != NO_DATA) ||
E 3
		    (_res.options & RES_DNSRCH) == 0)
			break;
D 4
		h_errno = 0;
E 4
	}
	/*
	 * If the search/default failed, try the name as fully-qualified,
	 * but only if it contained at least one dot (even trailing).
	 */
D 5
	if (n)
E 5
I 5
	if (n || !strcasecmp(name, "localhost"))
E 5
		return (res_querydomain(name, (char *)NULL, class, type,
		    answer, anslen));
D 3
	h_errno = HOST_NOT_FOUND;
E 3
I 3
	if (got_nodata)
		h_errno = NO_DATA;
E 3
	return (-1);
}

/*
 * Perform a call on res_query on the concatenation of name and domain,
 * removing a trailing dot from name if domain is NULL.
 */
res_querydomain(name, domain, class, type, answer, anslen)
	char *name, *domain;
	int class, type;	/* class and type of query */
	u_char *answer;		/* buffer to put answer */
	int anslen;		/* size of answer */
{
	char nbuf[2*MAXDNAME+2];
	char *longname = nbuf;
	int n;

I 3
#ifdef DEBUG
	if (_res.options & RES_DEBUG)
		printf("res_querydomain(%s, %s, %d, %d)\n",
		    name, domain, class, type);
#endif
E 3
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
		(void)sprintf(nbuf, "%.*s.%.*s",
		    MAXDNAME, name, MAXDNAME, domain);

	return (res_query(longname, class, type, answer, anslen));
}

char *
hostalias(name)
	register char *name;
{
	register char *C1, *C2;
	FILE *fp;
	char *file, *getenv(), *strcpy(), *strncpy();
	char buf[BUFSIZ];
	static char abuf[MAXDNAME];

	file = getenv("HOSTALIASES");
	if (file == NULL || (fp = fopen(file, "r")) == NULL)
		return (NULL);
	buf[sizeof(buf) - 1] = '\0';
	while (fgets(buf, sizeof(buf), fp)) {
		for (C1 = buf; *C1 && !isspace(*C1); ++C1);
		if (!*C1)
			break;
		*C1 = '\0';
		if (!strcasecmp(buf, name)) {
			while (isspace(*++C1));
			if (!*C1)
				break;
			for (C2 = C1 + 1; *C2 && !isspace(*C2); ++C2);
			abuf[sizeof(abuf) - 1] = *C2 = '\0';
			(void)strncpy(abuf, C1, sizeof(abuf) - 1);
			fclose(fp);
			return (abuf);
		}
	}
	fclose(fp);
	return (NULL);
}
E 1
