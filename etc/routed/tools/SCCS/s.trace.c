h57922
s 00010/00004/00091
d D 5.4 88/02/16 18:39:43 bostic 7 6
c add Berkeley specific headers
e
s 00009/00005/00086
d D 5.3 86/02/12 16:43:12 karels 6 5
c accept dot-notation host addresses, -n for query
e
s 00001/00001/00090
d D 5.2 85/11/04 13:19:29 karels 5 4
c update
e
s 00014/00002/00077
d D 5.1 85/06/04 16:41:44 dist 4 3
c Add copyright
e
s 00014/00008/00065
d D 4.3 83/12/21 14:23:42 karels 3 2
c upgrade to 4.2; headers in ..; query looks for multiple responses
c from a host.
e
s 00012/00003/00061
d D 4.2 82/10/06 14:34:32 sam 2 1
c convert to new library
e
s 00064/00000/00000
d D 4.1 82/06/17 11:05:44 sam 1 0
c date and time created 82/06/17 11:05:44 by sam
e
u
U
t
T
I 4
/*
 * Copyright (c) 1983 Regents of the University of California.
D 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
 */

E 4
I 1
#ifndef lint
D 4
static char sccsid[] = "%W% %G%";
#endif
E 4
I 4
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
D 7
#endif not lint
E 7
I 7
#endif /* not lint */
E 7

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 7
#endif not lint
E 7
I 7
#endif /* not lint */
E 7
E 4

#include <sys/param.h>
#include <sys/protosw.h>
#include <sys/socket.h>
D 3
#include <net/in.h>
E 3
I 3
#include <netinet/in.h>
E 3
#include <errno.h>
#include <stdio.h>
I 2
#include <netdb.h>
E 2
D 3
#include "rip.h"
E 3
I 3
D 5
#include "../protocol.h"
E 5
I 5
#include <protocols/routed.h>
E 5
E 3

struct	sockaddr_in myaddr = { AF_INET, IPPORT_RESERVED-1 };
I 3
char	packet[MAXPACKETSIZE];
E 3

main(argc, argv)
	int argc;
	char *argv[];
{
	int size, s;
	struct sockaddr from;
	struct sockaddr_in router;
D 3
	char packet[MAXPACKETSIZE];
E 3
	register struct rip *msg = (struct rip *)packet;
I 2
	struct hostent *hp;
	struct servent *sp;
E 2
	
	if (argc < 3) {
usage:
		printf("usage: trace cmd machines,\n");
		printf("cmd either \"on filename\", or \"off\"\n");
		exit(1);
	}
I 3
	s = socket(AF_INET, SOCK_DGRAM, 0);
	if (s < 0) {
		perror("socket");
		exit(2);
	}
E 3
#ifdef vax || pdp11
	myaddr.sin_port = htons(myaddr.sin_port);
#endif
D 3
	s = socket(SOCK_DGRAM, 0, &myaddr, 0);
	if (s < 0) {
		perror("socket");
E 3
I 3
	if (bind(s, &myaddr, sizeof(myaddr)) < 0) {
		perror("bind");
E 3
		exit(2);
	}
I 3

E 3
	argv++, argc--;
	msg->rip_cmd = strcmp(*argv, "on") == 0 ?
		RIPCMD_TRACEON : RIPCMD_TRACEOFF;
I 3
	msg->rip_vers = RIPVERSION;
E 3
	argv++, argc--;
	size = sizeof (int);
	if (msg->rip_cmd == RIPCMD_TRACEON) {
		strcpy(msg->rip_tracefile, *argv);
		size += strlen(*argv);
		argv++, argc--;
	}
	if (argc == 0)
		goto usage;
	bzero((char *)&router, sizeof (router));
	router.sin_family = AF_INET;
D 2
	router.sin_port = htons(IPPORT_ROUTESERVER);
E 2
I 2
	sp = getservbyname("router", "udp");
	if (sp == 0) {
		printf("udp/router: service unknown\n");
		exit(1);
	}
D 3
	router.sin_port = htons(sp->s_port);
E 3
I 3
	router.sin_port = sp->s_port;
E 3
E 2
	while (argc > 0) {
D 2
		router.sin_addr.s_addr = rhost(argv);
		if (router.sin_addr.s_addr == -1) {
E 2
I 2
D 6
		hp = gethostbyname(*argv);
		if (hp == 0) {
E 2
			printf("%s: unknown\n", *argv);
			continue;
E 6
I 6
		router.sin_family = AF_INET;
		router.sin_addr.s_addr = inet_addr(*argv);
		if (router.sin_addr.s_addr == -1) {
			hp = gethostbyname(*argv);
			if (hp == 0) {
				printf("%s: unknown\n", *argv);
				exit(1);
			}
			bcopy(hp->h_addr, &router.sin_addr, hp->h_length);
E 6
		}
I 2
D 6
		bcopy(hp->h_addr, &router.sin_addr, hp->h_length);
E 6
E 2
D 3
		if (send(s, &router, packet, size) < 0)
E 3
I 3
		if (sendto(s, packet, size, 0, &router, sizeof(router)) < 0)
E 3
			perror(*argv);
		argv++, argc--;
	}
}
E 1
