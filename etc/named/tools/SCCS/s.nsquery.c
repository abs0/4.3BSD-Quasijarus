h36706
s 00027/00008/00061
d D 4.3 99/09/28 17:18:03 msokolov 3 2
c herror takes a string, not h_errno
c add -a option to query by address
e
s 00000/00000/00069
d D 4.2 99/09/28 16:53:30 msokolov 2 1
c bump it up to 4.2
e
s 00069/00000/00000
d D 4.1 99/09/28 16:52:09 msokolov 1 0
c This SCCS file has apparently been lost, reconstructing from version 4.2
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

/*
 * Copyright (c) 1986 Regents of the University of California
 *	All Rights Reserved
 */

D 3
#include <stdio.h>
E 3
#include <sys/types.h>
D 3
#include <arpa/nameser.h>
#include <netdb.h>
E 3
#include <sys/socket.h>
#include <netinet/in.h>
I 3
#include <arpa/inet.h>
#include <arpa/nameser.h>
#include <stdio.h>
#include <netdb.h>
E 3
#include <resolv.h>

D 3
struct state orig;
E 3
extern struct state _res;
extern int h_errno;

main(c, v)
	char **v;
{
	char h[32];
	register struct hostent *hp;
	register char *s;
I 3
	int byaddr = 0;
	u_long addr;
E 3

	gethostname(h, 32);
	s = h;
I 3
	if (c > 1 && !strcmp(v[1], "-a")) {
		byaddr = 1;
		c--;
		v++;
	}
E 3
	if (c < 2) {
D 3
		fprintf(stderr, "Usage: lookup host [server]\n");
E 3
I 3
		fprintf(stderr, "Usage: lookup [-a] host [server]\n");
E 3
		exit(1);
	}
	if (c > 2)
		s = v[2];

I 3
	if (byaddr) {
		addr = inet_addr(v[1]);
		if (addr == INADDR_NONE) {
			fprintf(stderr, "%s is not a valid Internet address\n",
				v[1]);
			exit(1);
		}
	}

E 3
	hp = gethostbyname(s);
	if (hp == NULL) {
D 3
		herror(h_errno);
E 3
I 3
		herror(s);
E 3
		exit(1);
	}
	printanswer(hp);

	_res.nsaddr.sin_addr = *(struct in_addr *)hp->h_addr;
	_res.options &= ~RES_DEFNAMES;

D 3
	hp = gethostbyname(v[1]);
E 3
I 3
	if (!byaddr)
		hp = gethostbyname(v[1]);
	else
		hp = gethostbyaddr(&addr, sizeof(addr), AF_INET);
E 3
	if (hp == NULL) {
D 3
		herror(h_errno);
E 3
I 3
		herror(v[1]);
E 3
		exit(1);
	}
	printanswer(hp);
	exit(0);
}

printanswer(hp)
	register struct hostent *hp;
{
	register char **cp;
	extern char *inet_ntoa();

	printf("Name: %s\n", hp->h_name);
	printf("Address: %s\n", inet_ntoa(*(struct in_addr *)hp->h_addr));
	printf("Aliases:");
	for (cp = hp->h_aliases; cp && *cp && **cp; cp++)
		printf(" %s", *cp);
	printf("\n\n");
}
E 1
