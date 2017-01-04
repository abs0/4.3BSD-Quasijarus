h30072
s 00010/00005/00220
d D 5.5 86/02/14 18:28:01 sklower 5 4
c 1.) Fixes from Nesheim viz pt to pt timeouts;
c 2.) Getting rid of ns_netof, to make common for Gould, CCI
e
s 00022/00031/00203
d D 5.4 85/09/17 21:42:08 sklower 4 3
c latest changes from nesheim@cornell:
c use syslog instead of perror, ignore remote requests unless specifically asked,
c handle requests from net 0.
e
s 00035/00017/00199
d D 5.3 85/08/16 21:48:58 sklower 3 2
c This version Aug 16th -- source directory moved to /usr/src/etc/XNSrouted;
c includes fix to response to request for specific net, and adds copyright notices
e
s 00043/00038/00173
d D 5.2 85/08/16 20:43:49 sklower 2 1
c status as of 4.3 alpha tape
e
s 00211/00000/00000
d D 5.1 85/08/16 20:22:41 sklower 1 0
c date and time created 85/08/16 20:22:41 by sklower
e
u
U
t
T
I 3
/*
 * Copyright (c) 1985 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 * Includes material written at Cornell University by Bill Nesheim
 * with permission of the author.
 */

E 3
I 1
#ifndef lint
D 3
static char rcsid[] = "$Header$";
#endif
E 3
I 3
char copyright[] =
D 5
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 5
I 5
"@(#) Copyright (c) 1983 Regents of the University of California.\n\
E 5
 All rights reserved.\n";
#endif not lint
E 3

I 3
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 3
/*
 * XNS Routing Information Protocol Daemon
 */
#include "defs.h"
#include <sys/ioctl.h>
#include <sys/time.h>

#include <net/if.h>

#include <errno.h>
#include <nlist.h>
#include <signal.h>
I 2
D 4
#include <syslog.h>
E 4
E 2

int	supplier = -1;		/* process should supply updates */
extern int gateway;

struct	rip *msg = (struct rip *) &packet[sizeof (struct idp)]; 
int	hup(), fkexit();

main(argc, argv)
	int argc;
	char *argv[];
{
I 2
	int cc;
E 2
	struct sockaddr from;
	u_char retry;
D 2
	int selectbits;
	struct interface *ifp;
	extern struct interface *ifnet;
E 2
	
	argv0 = argv;
I 2
D 3
	addr.sns_family = AF_NS;
	addr.sns_port = htons(IDPPORT_RIF);
	s = getsocket(SOCK_DGRAM, 0, &addr);
	if (s < 0)
		exit(1);
E 3
E 2
	argv++, argc--;
	while (argc > 0 && **argv == '-') {
		if (strcmp(*argv, "-s") == 0) {
			supplier = 1;
			argv++, argc--;
			continue;
		}
		if (strcmp(*argv, "-q") == 0) {
			supplier = 0;
			argv++, argc--;
			continue;
		}
I 4
		if (strcmp(*argv, "-R") == 0) {
			noteremoterequests++;
			argv++, argc--;
			continue;
		}
E 4
		if (strcmp(*argv, "-t") == 0) {
			tracepackets++;
			argv++, argc--;
			ftrace = stderr;
			tracing = 1; 
			continue;
		}
		if (strcmp(*argv, "-g") == 0) {
			gateway = 1;
			argv++, argc--;
			continue;
		}
		if (strcmp(*argv, "-l") == 0) {
			gateway = -1;
			argv++, argc--;
			continue;
		}
		fprintf(stderr,
			"usage: xnsrouted [ -s ] [ -q ] [ -t ] [ -g ] [ -l ]\n");
		exit(1);
	}
	
I 4
	
E 4
#ifndef DEBUG
	if (!tracepackets) {
		int t;

		if (fork())
			exit(0);
		for (t = 0; t < 20; t++)
			(void) close(t);
		(void) open("/", 0);
		(void) dup2(0, 1);
		(void) dup2(0, 2);
		t = open("/dev/tty", 2);
		if (t >= 0) {
			ioctl(t, TIOCNOTTY, (char *)0);
			(void) close(t);
		}
	}
#endif
I 4
	openlog("XNSrouted", LOG_PID, LOG_DAEMON);

I 5
	ns_anynet.s_net[0] = -1; ns_anynet.s_net[1] = -1;
E 5
E 4
I 3
	addr.sns_family = AF_NS;
	addr.sns_port = htons(IDPPORT_RIF);
	s = getsocket(SOCK_DGRAM, 0, &addr);
	if (s < 0)
		exit(1);
E 3
	/*
	 * Any extra argument is considered
	 * a tracing log file.
	 */
	if (argc > 0)
		traceon(*argv);
	/*
	 * Collect an initial view of the world by
	 * snooping in the kernel.  Then, send a request packet on all
	 * directly connected networks to find out what
	 * everyone else thinks.
	 */
	rtinit();
	ifinit();
	if (supplier < 0)
		supplier = 0;
	/* request the state of the world */
	msg->rip_cmd = htons(RIPCMD_REQUEST);
D 2
	xnnet(msg->rip_nets[0].rip_dst) = htonl(DSTNETS_ALL);
E 2
I 2
D 5
	xnnet(msg->rip_nets[0].rip_dst[0]) = htonl(DSTNETS_ALL);
E 5
I 5
	msg->rip_nets[0].rip_dst = ns_anynet;
E 5
E 2
	msg->rip_nets[0].rip_metric =  htons(HOPCNT_INFINITY);
	toall(sendmsg);
	signal(SIGALRM, timer);
	signal(SIGHUP, hup);
	signal(SIGINT, hup);
	signal(SIGEMT, fkexit);
	timer();
	
D 2
	/*
	 * Listen for RIF packets on all interfaces
	 */
	selectbits = 0;
	for( ifp = ifnet; ifp!=0; ifp = ifp->int_next) {
		selectbits |= 1 << ifp->int_ripsock[0];
		selectbits |= 1 << ifp->int_ripsock[1];
	}
E 2

D 4
	for (;;) {
		int ibits;
		register int n;

D 2
		ibits = selectbits;
E 2
I 2
		/*ibits = 1 << s;
E 2
		n = select(20, &ibits, 0, 0, 0);
D 2
		if (n < 0) {
			if(errno != EINTR) {
				perror("main:select");
				exit(1);
			}
E 2
I 2
		if (n < 0)
E 2
			continue;
D 2
		}
		for( ifp = ifnet; ifp!=0; ifp = ifp->int_next) {
		    /* take RIF packet off interface */
		    for(n = 0; n < 2; n++)
			if(ibits & (1 << ifp->int_ripsock[n]))
				process(ifp->int_ripsock[n]);
		}
E 2
I 2
		if (ibits & (1 << s)) */
			process(s);
		/* handle ICMP redirects */
E 2
	}
E 4
I 4
	for (;;) 
		process(s);
	
E 4
}

process(fd)
	int fd;
{
	struct sockaddr from;
	int fromlen = sizeof (from), cc, omask;
	struct idp *idp = (struct idp *)packet;

	cc = recvfrom(fd, packet, sizeof (packet), 0, &from, &fromlen);
	if (cc <= 0) {
		if (cc < 0 && errno != EINTR)
D 4
			perror("recvfrom");
E 4
I 4
			syslog("recvfrom: %m");
E 4
		return;
	}
D 3
	/* We get the IDP header in front of the RIF packet*/
E 3
D 4
	if (tracepackets > 1) {
E 4
I 4
	if (tracepackets > 1 && ftrace) {
E 4
D 3
	    fprintf(ftrace,"rcv %d bytes on %s ",
D 2
		cc, xns_ntoa(&idp->idp_dst));
	    fprintf(ftrace," from %s\n", xns_ntoa(&idp->idp_src));
E 2
I 2
		cc, xns_ntoa(&idp->idp_dna));
E 3
I 3
	    fprintf(ftrace,"rcv %d bytes on %s ", cc, xns_ntoa(&idp->idp_dna));
E 3
	    fprintf(ftrace," from %s\n", xns_ntoa(&idp->idp_sna));
E 2
	}
D 3
	
D 2
	if (xnnet(idp->idp_src.xn_net) != xnnet(idp->idp_dst.xn_net)) {
E 2
I 2
	if (ns_netof(idp->idp_sna) != ns_netof(idp->idp_dna)) {
E 2
		fprintf(ftrace, "XNSrouted: net of interface (%d) != net on ether (%d)!\n",
D 2
			ntohl(xnnet(idp->idp_dst.xn_net)),
			ntohs(xnnet(idp->idp_src.xn_net)));
E 2
I 2
			ns_netof(idp->idp_dna), ns_netof(idp->idp_sna));
E 3
I 3
D 4
	if (tracepackets > 0) {
	    if (ns_netof(idp->idp_sna) != ns_netof(idp->idp_dna)) {
		    fprintf(ftrace,
			    "XNSrouted: net of interface (%d) ",
			    ns_netof(idp->idp_dna));
		    fprintf(ftrace,
			    "!= net on ether (%d)!\n", ns_netof(idp->idp_sna));
	    }
	    if (fromlen != sizeof (struct sockaddr_ns))
		    fprintf(ftrace, "fromlen is %d instead of %d\n",
		    fromlen, sizeof (struct sockaddr_ns));
E 4
I 4
	
D 5
	if (noteremoterequests && ns_netof(idp->idp_sna) && 
	    ns_netof(idp->idp_sna) != ns_netof(idp->idp_dna)) {
		syslog(LOG_ERR, "net of interface (%d) != net on ether (%d)!\n",  ns_netof(idp->idp_dna), ns_netof(idp->idp_sna));
E 5
I 5
	if (noteremoterequests && !ns_neteqnn(idp->idp_sna.x_net, ns_zeronet)
		&& !ns_neteq(idp->idp_sna, idp->idp_dna))
	{
		syslog(LOG_ERR,
		       "net of interface (%s) != net on ether (%s)!\n",
		       xns_nettoa(idp->idp_dna.x_net),
		       xns_nettoa(idp->idp_sna.x_net));
E 5
E 4
E 3
E 2
	}
			
I 3
	/* We get the IDP header in front of the RIF packet*/
E 3
	cc -= sizeof (struct idp);
D 2
	if (fromlen != sizeof (struct sockaddr_xn))
		return;
E 2
I 2
D 3
	if (fromlen != sizeof (struct sockaddr_ns))
		fprintf(ftrace, "fromlen is %d instead of %d\n",
		fromlen, sizeof (struct sockaddr_ns));
E 3
E 2
#define	mask(s)	(1<<((s)-1))
	omask = sigblock(mask(SIGALRM));
	rip_input(&from, cc);
	sigsetmask(omask);
}

D 2
getsocket(domain, type, proto, sxn)
	int domain, type, proto;
	struct sockaddr_xn *sxn;
E 2
I 2
getsocket(type, proto, sns)
	int type, proto; 
	struct sockaddr_ns *sns;
E 2
{
D 2
	int retry, s;
E 2
I 2
	int domain = sns->sns_family;
	int retry, s, on = 1;
E 2

	retry = 1;
D 2
	while ((s = socket(domain, type, proto, 0)) < 0 && retry) {
E 2
I 2
	while ((s = socket(domain, type, proto)) < 0 && retry) {
E 2
D 4
		perror("socket");
E 4
I 4
		syslog("socket: %m");
E 4
		sleep(5 * retry);
		retry <<= 1;
	}
	if (retry == 0)
		return (-1);
D 2
	while (bind(s, sxn, sizeof (*sxn), 0) < 0 && retry) {
E 2
I 2
	while (bind(s, sns, sizeof (*sns), 0) < 0 && retry) {
E 2
D 4
		perror("bind");
E 4
I 4
		syslog("bind: %m");
E 4
		sleep(5 * retry);
		retry <<= 1;
	}
	if (retry == 0)
		return (-1);
I 2
	if (domain==AF_NS) {
		struct idp idp;
		if (setsockopt(s, 0, SO_HEADERS_ON_INPUT, &on, sizeof(on))) {
D 4
			perror("setsockopt SEE HEADERS");
E 4
I 4
			syslog("setsockopt SEE HEADERS: %m");
E 4
			exit(1);
		}
		idp.idp_pt = NSPROTO_RI;
		if (setsockopt(s, 0, SO_DEFAULT_HEADERS, &idp, sizeof(idp))) {
D 4
			perror("setsockopt SET HEADERS");
E 4
I 4
			syslog("setsockopt SET HEADER: %m");
E 4
			exit(1);
		}
	}
	if (setsockopt(s, SOL_SOCKET, SO_BROADCAST, &on, sizeof (on)) < 0) {
D 4
		perror("setsockopt SO_BROADCAST");
E 4
I 4
		syslog("setsockopt SO_BROADCAST: %m");
E 4
		exit(1);
	}
E 2
	return (s);
}

/*
 * Fork and exit on EMT-- for profiling.
 */
fkexit()
{
	if (fork() == 0)
		exit(0);
}
E 1
