h49102
s 00001/00001/00200
d D 5.5 87/04/06 14:50:02 bostic 5 4
c printf arg/format mismatch
e
s 00005/00002/00196
d D 5.4 86/02/14 19:27:08 sklower 4 3
c acknowledge contribution of Nesheim@Cornell
e
s 00021/00019/00177
d D 5.3 86/02/14 19:24:43 sklower 3 2
c make it so that you don't have to laboriously type broaddr;
c also make portable to CCI, Gould.
e
s 00018/00010/00178
d D 5.2 85/08/16 22:22:28 sklower 2 1
c provide means to ask for a specific network at cost of querying multiple hosts.
e
s 00188/00000/00000
d D 5.1 85/08/12 15:13:48 sklower 1 0
c date and time created 85/08/12 15:13:48 by sklower
e
u
U
t
T
I 1
/*
D 2
 * Copyright (c) 1980 Regents of the University of California.
E 2
I 2
D 4
 * Copyright (c) 1983 Regents of the University of California.
E 4
I 4
 * Copyright (c) 1983, 1986 Regents of the University of California.
E 4
E 2
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
I 4
 *
 * This file include significant work done at Cornell University
 * by Bill Nesheim.  That work included by permission.
E 4
 */

#ifndef lint
D 2
static char sccsid[] = "@(#)query.c	5.1 (Berkeley) 6/7/85";
E 2
I 2
char copyright[] =
D 4
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 4
I 4
"%Z% Copyright (c) 1983, 1986 Regents of the University of California.\n\
E 4
 All rights reserved.\n";
E 2
#endif not lint

I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 2
#include <sys/param.h>
#include <sys/protosw.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netns/ns.h>
#include <netns/idp.h>
#include <errno.h>
#include <stdio.h>
#include <netdb.h>
#include "../protocol.h"
#define IDPPORT_RIF 1
D 3
#define xnnet(p)	(*(long *)&(p))
E 3

#define	WTIME	5		/* Time to wait for responses */

int	s;
int	timedout, timeout();
char	packet[MAXPACKETSIZE];
extern int errno;
struct sockaddr_ns	myaddr = {AF_NS};
I 3
D 5
char ns_ntoa();
E 5
I 5
char *ns_ntoa();
E 5
struct ns_addr ns_addr();
E 3
main(argc, argv)
int argc;
char *argv[];
{
	int cc, count, bits;
	struct sockaddr from;
	int fromlen = sizeof(from);
	struct timeval notime;
	
	if (argc < 2) {
		printf("usage: query hosts...\n");
		exit(1);
	}
	s = getsocket(SOCK_DGRAM, 0);
	if (s < 0) {
		perror("socket");
		exit(2);
	}

	argv++, argc--;
D 2
	count = argc;
	while (argc > 0) {
		query(*argv);
		argv++, argc--;
	}
E 2
I 2
	query(argv,argc);
E 2

	/*
	 * Listen for returning packets;
	 * may be more than one packet per host.
	 */
	bits = 1 << s;
	bzero(&notime, sizeof(notime));
	signal(SIGALRM, timeout);
	alarm(WTIME);
D 2
	while ((count > 0 && !timedout) ||
E 2
I 2
	while (!timedout || 
E 2
	    select(20, &bits, 0, 0, &notime) > 0) {
		struct nspacket {
			struct idp hdr;
			char	data[512];
		} response;
		cc = recvfrom(s, &response, sizeof (response), 0,
		  &from, &fromlen);
		if (cc <= 0) {
			if (cc < 0) {
				if (errno == EINTR)
					continue;
				perror("recvfrom");
				(void) close(s);
				exit(1);
			}
			continue;
		}
		rip_input(&from, response.data, cc);
		count--;
	}
}
I 3
static struct sockaddr_ns router = {AF_NS};
static struct ns_addr zero_addr;
static short allones[] = {-1, -1, -1};
E 3

D 2
query(host)
	char *host;
E 2
I 2
query(argv,argc)
char **argv;
E 2
{
D 3
	struct sockaddr_ns router;
E 3
	register struct rip *msg = (struct rip *)packet;
D 3
	long mynet;
	short work[3];
E 3
I 2
	char *host = *argv;
I 3
	struct ns_addr specific;
E 3
E 2

I 2
	argv++; argc--;
E 2
D 3
	bzero((char *)&router, sizeof (router));
	router.sns_family = AF_NS;
E 3
I 3
	router.sns_addr = ns_addr(host);
E 3
	router.sns_addr.x_port = htons(IDPPORT_RIF);
D 3
	sscanf(host, "%ld:%hx,%hx,%hx",
			&mynet,work+0, work+1, work+2);
	router.sns_addr.x_host  = *(union ns_host *)work;
	xnnet(router.sns_addr.x_net) =  htonl(mynet);
E 3
I 3
	if (ns_hosteq(zero_addr, router.sns_addr)) {
		router.sns_addr.x_host = *(union ns_host *) allones;
	}
E 3
	msg->rip_cmd = htons(RIPCMD_REQUEST);
D 3
	xnnet(msg->rip_nets[0]) = -1;
E 3
I 3
	msg->rip_nets[0].rip_dst = *(union ns_net *) allones;
E 3
	msg->rip_nets[0].rip_metric = htons(HOPCNT_INFINITY);
I 2
	if (argc > 0) {
D 3
		u_long wanted = xnnet(msg->rip_nets[0]) = htonl(atoi(*argv));
		printf("Net asked for was %d\n", ntohl(wanted));
E 3
I 3
		specific = ns_addr(*argv);
		msg->rip_nets[0].rip_dst = specific.x_net;
		specific.x_host = zero_addr.x_host;
		specific.x_port = zero_addr.x_port;
		printf("Net asked for was %s\n", ns_ntoa(specific));
E 3
	}
E 2
	if (sendto(s, packet, sizeof (struct rip), 0,
	  &router, sizeof(router)) < 0)
		perror(host);
}

/*
 * Handle an incoming routing packet.
 */
rip_input(from, msg,  size)
	struct sockaddr_ns *from;
	register struct rip *msg;
	int size;
{
	struct netinfo *n;
	char *name;
	int lna, net, subnet;
	struct hostent *hp;
	struct netent *np;
I 3
	static struct ns_addr work;
E 3

	if (htons(msg->rip_cmd) != RIPCMD_RESPONSE)
		return;
D 3
	printf("from %d:%x,%x,%x\n", 
		ntohl(xnnet(from->sns_addr.x_net)),
		from->sns_addr.x_host.s_host[0],
		from->sns_addr.x_host.s_host[1],
		from->sns_addr.x_host.s_host[2]);
E 3
I 3
	printf("from %s\n", ns_ntoa(from->sns_addr));
E 3
	size -= sizeof (struct idp);
	size -= sizeof (short);
	n = msg->rip_nets;
	while (size > 0) {
I 3
		union ns_net_u net;
E 3
		if (size < sizeof (struct netinfo))
			break;
D 3
		printf("\t%d, metric %d\n", ntohl(xnnet(n->rip_dst[0])),
E 3
I 3
		net.net_e = n->rip_dst;
		printf("\t%d, metric %d\n", ntohl(net.long_e),
E 3
			ntohs(n->rip_metric));
		size -= sizeof (struct netinfo), n++;
	}
}

timeout()
{
	timedout = 1;
}
getsocket(type, proto)
	int type, proto; 
{
	struct sockaddr_ns *sns = &myaddr;
	int domain = sns->sns_family;
	int retry, s, on = 1;

	retry = 1;
	while ((s = socket(domain, type, proto)) < 0 && retry) {
		perror("socket");
		sleep(5 * retry);
		retry <<= 1;
	}
	if (retry == 0)
		return (-1);
	while (bind(s, sns, sizeof (*sns), 0) < 0 && retry) {
		perror("bind");
		sleep(5 * retry);
		retry <<= 1;
	}
	if (retry == 0)
		return (-1);
	if (domain==AF_NS) {
		struct idp idp;
		if (setsockopt(s, 0, SO_HEADERS_ON_INPUT, &on, sizeof(on))) {
			perror("setsockopt SEE HEADERS");
			exit(1);
		}
		idp.idp_pt = NSPROTO_RI;
		if (setsockopt(s, 0, SO_DEFAULT_HEADERS, &idp, sizeof(idp))) {
			perror("setsockopt SET HEADERS");
			exit(1);
		}
	}
	if (setsockopt(s, SOL_SOCKET, SO_BROADCAST, &on, sizeof (on)) < 0) {
		perror("setsockopt SO_BROADCAST");
		exit(1);
	}
	return (s);
}
E 1
