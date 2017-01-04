h20657
s 00007/00004/00253
d D 5.9 88/06/11 18:25:01 karels 16 15
c use bigger buffer, line up output
e
s 00015/00003/00242
d D 5.8 88/02/16 18:39:41 bostic 15 14
c add Berkeley specific headers
e
s 00032/00012/00213
d D 5.7 86/05/15 11:06:16 karels 14 13
c fixes
e
s 00007/00006/00218
d D 5.6 86/04/24 09:23:42 karels 13 12
c wait a bit for fragmented responses
e
s 00002/00002/00222
d D 5.5 86/03/28 15:09:24 karels 12 11
c what happened to this?
e
s 00001/00001/00223
d D 5.4 86/02/12 18:55:18 karels 11 10
c oops
e
s 00059/00034/00165
d D 5.3 86/02/12 16:43:05 karels 10 9
c accept dot-notation host addresses, -n for query
e
s 00008/00016/00191
d D 5.2 85/11/04 13:19:22 karels 9 8
c update
e
s 00008/00002/00199
d D 5.1 85/06/07 09:33:06 dist 8 7
c Add copyright
e
s 00060/00006/00141
d D 4.7 85/06/06 14:10:40 karels 7 6
c subnet addressing (old style)
e
s 00037/00015/00110
d D 4.6 83/12/21 14:23:36 karels 6 5
c upgrade to 4.2; headers in ..; query looks for multiple responses
c from a host.
e
s 00002/00043/00123
d D 4.5 82/10/07 18:10:58 sam 5 4
c use routines added to libc.a
e
s 00003/00003/00163
d D 4.4 82/10/06 17:57:37 sam 4 3
c more args to get* routines
e
s 00066/00013/00100
d D 4.3 82/10/06 14:34:02 sam 3 2
c convert to new library
e
s 00001/00001/00112
d D 4.2 82/05/24 08:56:21 sam 2 1
c checking wrong return value from rhost
e
s 00113/00000/00000
d D 4.1 82/05/22 22:26:17 sam 1 0
c date and time created 82/05/22 22:26:17 by sam
e
u
U
t
T
I 8
/*
 * Copyright (c) 1980 Regents of the University of California.
D 15
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 15
I 15
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 15
 */

E 8
I 1
#ifndef lint
I 15
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
E 15
D 8
static char sccsid[] = "%W% %G%";
#endif
E 8
I 8
static char sccsid[] = "%W% (Berkeley) %G%";
D 15
#endif not lint
E 15
I 15
#endif /* not lint */
E 15
E 8

#include <sys/param.h>
#include <sys/protosw.h>
#include <sys/socket.h>
D 6
#include <net/in.h>
E 6
I 6
#include <sys/time.h>
#include <netinet/in.h>
E 6
#include <errno.h>
#include <stdio.h>
I 3
#include <netdb.h>
E 3
D 6
#include "rip.h"
E 6
I 6
D 9
#include "../protocol.h"
E 9
I 9
#include <protocols/routed.h>
E 9
E 6

I 6
D 13
#define	WTIME	5		/* Time to wait for responses */
E 13
I 13
#define	WTIME	5		/* Time to wait for all responses */
#define	STIME	500000		/* usec to wait for another response */
E 13

E 6
D 3
struct	sockaddr_in myaddr = { AF_INET };

E 3
int	s;
I 7
int	timedout, timeout();
E 7
char	packet[MAXPACKETSIZE];
I 7
extern int errno;
I 10
int	nflag;
E 10
E 7
D 3
char	*raddr();
E 3

main(argc, argv)
	int argc;
	char *argv[];
{
D 6
	int cc, count;
E 6
I 6
D 13
	int cc, count, bits;
E 13
I 13
D 14
	int cc, bits;
E 14
I 14
	int cc, count, bits;
E 14
E 13
E 6
	struct sockaddr from;
I 6
D 16
	int fromlen = sizeof(from);
E 16
I 16
	int fromlen = sizeof(from), size = 32*1024;
E 16
D 13
	struct timeval notime;
E 13
I 13
	struct timeval shorttime;
E 13
E 6
	
	if (argc < 2) {
D 10
		printf("usage: query hosts...\n");
E 10
I 10
usage:
		printf("usage: query [ -n ] hosts...\n");
E 10
		exit(1);
	}
D 3
	s = socket(SOCK_DGRAM, 0, &myaddr, 0);
E 3
I 3
D 6
	s = socket(SOCK_DGRAM, 0, 0, 0);
E 6
I 6
	s = socket(AF_INET, SOCK_DGRAM, 0);
E 6
E 3
	if (s < 0) {
		perror("socket");
		exit(2);
	}
I 16
	if (setsockopt(s, SOL_SOCKET, SO_RCVBUF, &size, sizeof(size)) < 0)
		perror("setsockopt SO_RCVBUF");
E 16
I 6

E 6
	argv++, argc--;
I 10
	if (*argv[0] == '-') {
D 11
		switch (*argv[1]) {
E 11
I 11
		switch (argv[0][1]) {
E 11
		case 'n':
			nflag++;
			break;
		default:
			goto usage;
		}
		argc--, argv++;
	}
E 10
D 13
	count = argc;
E 13
	while (argc > 0) {
		query(*argv);
I 14
		count++;
E 14
		argv++, argc--;
	}

	/*
D 6
	 * Listen for returning packets
E 6
I 6
	 * Listen for returning packets;
	 * may be more than one packet per host.
E 6
	 */
D 6
	while (count > 0) {
		cc = receive(s, &from, packet, sizeof (packet));
E 6
I 6
	bits = 1 << s;
D 13
	bzero(&notime, sizeof(notime));
E 13
I 13
	bzero(&shorttime, sizeof(shorttime));
	shorttime.tv_usec = STIME;
E 13
D 7
	while (count > 0 || select(20, &bits, 0, 0, &notime) > 0) {
E 7
I 7
	signal(SIGALRM, timeout);
	alarm(WTIME);
	while ((count > 0 && !timedout) ||
D 13
	    select(20, &bits, 0, 0, &notime) > 0) {
E 13
I 13
	    select(20, &bits, 0, 0, &shorttime) > 0) {
E 13
E 7
		cc = recvfrom(s, packet, sizeof (packet), 0,
		  &from, &fromlen);
E 6
		if (cc <= 0) {
			if (cc < 0) {
I 7
				if (errno == EINTR)
					continue;
E 7
D 6
				perror("receive");
E 6
I 6
				perror("recvfrom");
E 6
				(void) close(s);
				exit(1);
			}
			continue;
		}
		rip_input(&from, cc);
		count--;
	}
I 16
	exit (count > 0 ? count : 0);
E 16
}

query(host)
	char *host;
{
	struct sockaddr_in router;
	register struct rip *msg = (struct rip *)packet;
I 3
	struct hostent *hp;
	struct servent *sp;
E 3

	bzero((char *)&router, sizeof (router));
D 3
	router.sin_addr.s_addr = rhost(&host);
D 2
	if (router.sin_addr.s_addr == 0) {
E 2
I 2
	if (router.sin_addr.s_addr == -1) {
E 3
I 3
D 10
	hp = gethostbyname(host);
	if (hp == 0) {
E 3
E 2
		printf("%s: unknown\n", host);
		exit(1);
	}
I 3
	bcopy(hp->h_addr, &router.sin_addr, hp->h_length);
E 10
E 3
	router.sin_family = AF_INET;
I 10
	router.sin_addr.s_addr = inet_addr(host);
	if (router.sin_addr.s_addr == -1) {
		hp = gethostbyname(host);
		if (hp == 0) {
			printf("%s: unknown\n", host);
			exit(1);
		}
		bcopy(hp->h_addr, &router.sin_addr, hp->h_length);
	}
E 10
D 3
	router.sin_port = htons(IPPORT_ROUTESERVER);
E 3
I 3
	sp = getservbyname("router", "udp");
	if (sp == 0) {
		printf("udp/router: service unknown\n");
		exit(1);
	}
D 6
	router.sin_port = htons(sp->s_port);
E 6
I 6
	router.sin_port = sp->s_port;
E 6
E 3
	msg->rip_cmd = RIPCMD_REQUEST;
D 6
	msg->rip_nets[0].rip_dst.sa_family = AF_UNSPEC;
	msg->rip_nets[0].rip_metric = HOPCNT_INFINITY;
	if (send(s, &router, packet, sizeof (struct rip)) < 0)
E 6
I 6
	msg->rip_vers = RIPVERSION;
	msg->rip_nets[0].rip_dst.sa_family = htons(AF_UNSPEC);
	msg->rip_nets[0].rip_metric = htonl(HOPCNT_INFINITY);
	if (sendto(s, packet, sizeof (struct rip), 0,
	  &router, sizeof(router)) < 0)
E 6
		perror(host);
}

/*
 * Handle an incoming routing packet.
 */
rip_input(from, size)
	struct sockaddr_in *from;
	int size;
{
	register struct rip *msg = (struct rip *)packet;
D 14
	struct netinfo *n;
E 14
I 14
	register struct netinfo *n;
E 14
	char *name;
I 7
	int lna, net, subnet;
E 7
I 3
	struct hostent *hp;
	struct netent *np;
E 3

	if (msg->rip_cmd != RIPCMD_RESPONSE)
		return;
D 3
	name = raddr(from->sin_addr);
	if (name == 0)
		name = "???";
E 3
I 3
D 4
	hp = gethostbyaddr(&from->sin_addr, sizeof (struct in_addr));
E 4
I 4
D 10
	hp = gethostbyaddr(&from->sin_addr, sizeof (struct in_addr), AF_INET);
E 4
	name = hp == 0 ? "???" : hp->h_name;
E 3
D 6
	printf("from %s(%x):\n", name, from->sin_addr);
E 6
I 6
D 9
	printf("from %s(%s):\n", name, inet_ntoa(from->sin_addr));
E 9
I 9
	printf("%d bytes from %s(%s):\n", size, name,
		inet_ntoa(from->sin_addr));
E 10
I 10
D 12
	printf("%d bytes from ");
E 12
I 12
	printf("%d bytes from ", size);
E 12
	if (nflag)
		printf("%s:\n", inet_ntoa(from->sin_addr));
	else {
		hp = gethostbyaddr(&from->sin_addr, sizeof (struct in_addr),
			AF_INET);
		name = hp == 0 ? "???" : hp->h_name;
		printf("%s(%s):\n", name, inet_ntoa(from->sin_addr));
	}
E 10
E 9
E 6
	size -= sizeof (int);
	n = msg->rip_nets;
	while (size > 0) {
D 14
		register struct sockaddr_in *sin;
E 14
I 14
	    if (size < sizeof (struct netinfo))
		    break;
	    if (msg->rip_vers > 0) {
		    n->rip_dst.sa_family =
			    ntohs(n->rip_dst.sa_family);
		    n->rip_metric = ntohl(n->rip_metric);
	    }
	    switch (n->rip_dst.sa_family) {
E 14

D 14
		if (size < sizeof (struct netinfo))
			break;
I 6
		if (msg->rip_vers > 0) {
			n->rip_dst.sa_family =
				ntohs(n->rip_dst.sa_family);
			n->rip_metric = ntohl(n->rip_metric);
		}
E 14
I 14
	    case AF_INET:
		{ register struct sockaddr_in *sin;

E 14
E 6
		sin = (struct sockaddr_in *)&n->rip_dst;
D 3
		name = raddr(sin->sin_addr);
		if (name == 0)
			name = "???";
E 3
I 3
D 5
		if (in_lnaof(sin->sin_addr) == INADDR_ANY) {
D 4
			np = getnetbyaddr(in_netof(sin->sin_addr));
E 4
I 4
			np = getnetbyaddr(in_netof(sin->sin_addr), AF_INET);
E 5
I 5
D 7
		if (inet_lnaof(sin->sin_addr) == INADDR_ANY) {
			np = getnetbyaddr(inet_netof(sin->sin_addr), AF_INET);
E 5
E 4
			name = np ? np->n_name : "???";
E 7
I 7
		net = inet_netof(sin->sin_addr);
		subnet = inet_subnetof(sin->sin_addr);
		lna = inet_lnaof(sin->sin_addr);
		name = "???";
D 10
		if (lna == INADDR_ANY) {
			np = getnetbyaddr(net, AF_INET);
			if (np)
				name = np->n_name;
			else if (net == 0)
				name = "default";
		} else if ((subnet != net) && ((lna & 0xff) == 0) &&
		    (np = getnetbyaddr(subnet, AF_INET))) {
			struct in_addr subnaddr, inet_makeaddr();
E 10
I 10
		if (!nflag) {
D 14
			if (lna == INADDR_ANY) {
E 14
I 14
			if (sin->sin_addr.s_addr == 0)
				name = "default";
			else if (lna == INADDR_ANY) {
E 14
				np = getnetbyaddr(net, AF_INET);
				if (np)
					name = np->n_name;
				else if (net == 0)
					name = "default";
D 12
			} else if ((subnet != net) && ((lna & 0xff) == 0) &&
E 12
I 12
			} else if ((lna & 0xff) == 0 &&
E 12
			    (np = getnetbyaddr(subnet, AF_INET))) {
				struct in_addr subnaddr, inet_makeaddr();
E 10

D 10
			subnaddr = inet_makeaddr(subnet, INADDR_ANY);
			if (bcmp(&sin->sin_addr, &subnaddr, sizeof(subnaddr)) == 0)
				name = np->n_name;
			else
				goto host;
E 7
		} else {
I 7
host:
E 7
			hp = gethostbyaddr(&sin->sin_addr,
D 4
				sizeof (struct in_addr));
E 4
I 4
D 7
				sizeof (struct in_addr), AF_INET);
E 4
			name = hp ? hp->h_name : "???";
E 7
I 7
			    sizeof (struct in_addr), AF_INET);
			if (hp)
				name = hp->h_name;
E 7
		}
E 3
D 6
		printf("\t%s(%x), metric %d\n", name,
			sin->sin_addr, n->rip_metric);
E 6
I 6
		printf("\t%s(%s), metric %d\n", name,
			inet_ntoa(sin->sin_addr), n->rip_metric);
E 10
I 10
				subnaddr = inet_makeaddr(subnet, INADDR_ANY);
				if (bcmp(&sin->sin_addr, &subnaddr,
				    sizeof(subnaddr)) == 0)
					name = np->n_name;
				else
					goto host;
			} else {
	host:
				hp = gethostbyaddr(&sin->sin_addr,
				    sizeof (struct in_addr), AF_INET);
				if (hp)
					name = hp->h_name;
			}
D 16
			printf("\t%s(%s), metric %d\n", name,
				inet_ntoa(sin->sin_addr), n->rip_metric);
E 16
I 16
			printf("\t%-17s metric %2d name %s\n",
				inet_ntoa(sin->sin_addr), n->rip_metric, name);
E 16
		} else
D 16
			printf("\t%s, metric %d\n",
E 16
I 16
			printf("\t%-17s metric %2d\n",
E 16
				inet_ntoa(sin->sin_addr), n->rip_metric);
E 10
E 6
D 14
		size -= sizeof (struct netinfo), n++;
E 14
I 14
		break;
		}

	    default:
		{ u_short *p = (u_short *)n->rip_dst.sa_data;

		printf("\t(af %d) %x %x %x %x %x %x %x, metric %d\n",
		    p[0], p[1], p[2], p[3], p[4], p[5], p[6],
		    n->rip_dst.sa_family,
		    n->rip_metric);
		break;
		}
			
	    }
	    size -= sizeof (struct netinfo), n++;
E 14
	}
I 6
}

timeout()
{
	timedout = 1;
I 7
}

/*
 * Return the possible subnetwork number from an internet address.
D 9
 * If the address is of the form of a subnet address (most significant
 * bit of the host part is set), believe the subnet exists.
 * Otherwise, return the network number.
E 9
 * SHOULD FIND OUT WHETHER THIS IS A LOCAL NETWORK BEFORE LOOKING
 * INSIDE OF THE HOST PART.  We can only believe this if we have other
 * information (e.g., we can find a name for this number).
 */
inet_subnetof(in)
	struct in_addr in;
{
	register u_long i = ntohl(in.s_addr);

D 9
	if (IN_CLASSA(i)) {
		if (IN_SUBNETA(i))
			return ((i & IN_CLASSA_SUBNET) >> IN_CLASSA_SUBNSHIFT);
		else
			return ((i & IN_CLASSA_NET) >> IN_CLASSA_NSHIFT);
	} else if (IN_CLASSB(i)) {
		if (IN_SUBNETB(i))
			return ((i & IN_CLASSB_SUBNET) >> IN_CLASSB_SUBNSHIFT);
		else
			return ((i & IN_CLASSB_NET) >> IN_CLASSB_NSHIFT);
	} else
E 9
I 9
	if (IN_CLASSA(i))
		return ((i & IN_CLASSB_NET) >> IN_CLASSB_NSHIFT);
	else if (IN_CLASSB(i))
E 9
		return ((i & IN_CLASSC_NET) >> IN_CLASSC_NSHIFT);
I 9
	else
		return ((i & 0xffffffc0) >> 28);
E 9
E 7
E 6
I 3
D 5
}

/*
 * Return the network number from an internet
 * address; handles class a/b/c network #'s.
 */
in_netof(in)
	struct in_addr in;
{
#if vax || pdp11
	register u_long net;

	if ((in.s_addr&IN_CLASSA) == 0)
		return (in.s_addr & IN_CLASSA_NET);
	if ((in.s_addr&IN_CLASSB) == 0)
		return ((int)htons((u_short)(in.s_addr & IN_CLASSB_NET)));
	net = htonl((u_long)(in.s_addr & IN_CLASSC_NET));
	net >>= 8;
	return ((int)net);
#else
	return (IN_NETOF(in));
#endif
}

/*
 * Return the local network address portion of an
 * internet address; handles class a/b/c network
 * number formats.
 */
in_lnaof(in)
	struct in_addr in;
{
#if vax || pdp11
#define	IN_LNAOF(in) \
	(((in).s_addr&IN_CLASSA) == 0 ? (in).s_addr&IN_CLASSA_LNA : \
		((in).s_addr&IN_CLASSB) == 0 ? (in).s_addr&IN_CLASSB_LNA : \
			(in).s_addr&IN_CLASSC_LNA)
	return ((int)htonl((u_long)IN_LNAOF(in)));
#else
	return (IN_LNAOF(in));
#endif
E 5
E 3
}
E 1
