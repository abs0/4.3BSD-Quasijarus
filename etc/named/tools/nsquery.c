#ifndef lint
static char sccsid[] = "@(#)nsquery.c	4.3 (Berkeley) 9/28/99";
#endif

/*
 * Copyright (c) 1986 Regents of the University of California
 *	All Rights Reserved
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <arpa/nameser.h>
#include <stdio.h>
#include <netdb.h>
#include <resolv.h>

extern struct state _res;
extern int h_errno;

main(c, v)
	char **v;
{
	char h[32];
	register struct hostent *hp;
	register char *s;
	int byaddr = 0;
	u_long addr;

	gethostname(h, 32);
	s = h;
	if (c > 1 && !strcmp(v[1], "-a")) {
		byaddr = 1;
		c--;
		v++;
	}
	if (c < 2) {
		fprintf(stderr, "Usage: lookup [-a] host [server]\n");
		exit(1);
	}
	if (c > 2)
		s = v[2];

	if (byaddr) {
		addr = inet_addr(v[1]);
		if (addr == INADDR_NONE) {
			fprintf(stderr, "%s is not a valid Internet address\n",
				v[1]);
			exit(1);
		}
	}

	hp = gethostbyname(s);
	if (hp == NULL) {
		herror(s);
		exit(1);
	}
	printanswer(hp);

	_res.nsaddr.sin_addr = *(struct in_addr *)hp->h_addr;
	_res.options &= ~RES_DEFNAMES;

	if (!byaddr)
		hp = gethostbyname(v[1]);
	else
		hp = gethostbyaddr(&addr, sizeof(addr), AF_INET);
	if (hp == NULL) {
		herror(v[1]);
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
