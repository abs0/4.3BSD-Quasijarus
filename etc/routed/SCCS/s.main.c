h37701
s 00019/00007/00199
d D 5.13 88/05/31 11:52:55 karels 27 26
c new tracing
e
s 00011/00005/00195
d D 5.12 88/02/16 18:50:53 bostic 26 25
c add Berkeley specific headers
e
s 00005/00004/00195
d D 5.11 87/05/28 11:26:09 karels 25 24
c rework interface metrics to invert perspective; other misc. fixes
e
s 00000/00000/00199
d D 5.10 87/04/20 12:21:16 karels 24 23
x 22
c put back LOG_UPTO; it's not obsolete, there's no replacement!
c (and logmask takes a MASK!)
e
s 00004/00001/00195
d D 5.9 87/04/20 11:55:14 karels 23 22
c reorder startup so static routes to subnets work right;
c 
e
s 00003/00003/00193
d D 5.8 86/11/24 18:36:19 eric 22 21
c drop LOG_UPTO -- obsolete interface
e
s 00000/00001/00196
d D 5.7 86/04/20 23:34:16 karels 21 20
c changes to allow subnets to remain local, propogate net route
c where subnets don't go, and allow external routes from /etc/gateways
c to block routed from installing routes from elsewhere
e
s 00008/00001/00189
d D 5.6 86/02/23 19:34:13 karels 20 19
c don't rely on AF_MAX (comes from kernel include): check for nil explicitly,
c use our own idea of table size.  Use syslog to (optionally) log bad packets.
c Don't respond to routing inquiries from a router unless we are suppliers
c (really want to respondto everything but broadcasts, but haven't got
c the "to" address.)
e
s 00001/00001/00189
d D 5.5 86/01/06 14:12:04 mckusick 19 18
c check for error on socket()
e
s 00006/00013/00184
d D 5.4 85/11/21 19:55:42 karels 18 17
c don't bother waiting if socket, bind fail
e
s 00001/00001/00196
d D 5.3 85/09/17 18:49:30 eric 17 16
c facilities in syslog
e
s 00004/00005/00193
d D 5.2 85/09/16 17:31:30 sklower 16 15
c call to socket had one too many args, other small fixups.
e
s 00013/00001/00185
d D 5.1 85/06/04 16:36:13 dist 15 14
c Add copyright
e
s 00005/00008/00181
d D 4.13 85/06/03 09:50:36 karels 14 13
c new subnets
e
s 00000/00021/00189
d D 4.12 85/02/25 13:46:47 karels 13 12
c remove 4.1a compat
e
s 00014/00003/00196
d D 4.11 84/12/20 18:04:04 karels 12 10
c syslog for interface transitions; broadcast all unreachable before exit
e
s 00004/00000/00199
d R 4.11 84/08/29 15:06:34 karels 11 10
c add SO_BROADCAST option on socket
e
s 00013/00001/00186
d D 4.10 84/04/10 21:40:08 karels 10 9
c subnet routing
e
s 00002/00000/00185
d D 4.9 84/04/09 15:05:18 karels 9 8
c many cleanups; avoid interface timing out; put it back asap
e
s 00003/00001/00182
d D 4.8 83/07/01 23:59:45 sam 8 7
c include fix
e
s 00005/00004/00178
d D 4.7 83/06/12 02:46:21 sam 7 6
c new signals
e
s 00000/00002/00182
d D 4.6 83/06/01 16:26:49 sam 6 5
c notyet has come
e
s 00007/00002/00177
d D 4.5 83/05/25 17:50:50 sam 5 4
c protocol change; byte swap those fields which need it;  also add 
c a version stamp to allow future changes
e
s 00006/00002/00173
d D 4.4 83/01/31 14:49:19 sam 4 3
c don't close sockets when divorcing tty
e
s 00026/00018/00149
d D 4.3 83/01/31 14:18:35 sam 3 2
c add stdout tracing of all packets
e
s 00063/00045/00104
d D 4.2 83/01/11 14:38:19 sam 2 1
c 4.1c conversion contortions
e
s 00149/00000/00000
d D 4.1 82/11/02 22:28:04 sam 1 0
c date and time created 82/11/02 22:28:04 by sam
e
u
U
t
T
I 15
/*
D 27
 * Copyright (c) 1983 Regents of the University of California.
E 27
I 27
 * Copyright (c) 1983, 1988 Regents of the University of California.
E 27
D 26
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 26
I 26
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 26
 */

E 15
I 1
#ifndef lint
I 15
char copyright[] =
D 20
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 20
I 20
D 26
"@(#) Copyright (c) 1983 Regents of the University of California.\n\
E 26
I 26
D 27
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 27
I 27
"%Z% Copyright (c) 1983, 1988 Regents of the University of California.\n\
E 27
E 26
E 20
 All rights reserved.\n";
D 26
#endif not lint
E 26
I 26
#endif /* not lint */
E 26

#ifndef lint
E 15
D 5
static char sccsid[] = "%W% %G%";
E 5
I 5
static char sccsid[] = "%W% (Berkeley) %G%";
E 5
D 15
#endif
E 15
I 15
D 26
#endif not lint
E 26
I 26
#endif /* not lint */
E 26
E 15

/*
 * Routing Table Management Daemon
 */
D 2
#include "router.h"
E 2
I 2
#include "defs.h"
E 2
#include <sys/ioctl.h>
I 8
#include <sys/time.h>

E 8
#include <net/if.h>
I 8

E 8
D 27
#include <errno.h>
D 21
#include <nlist.h>
E 21
#include <signal.h>
I 12
#include <syslog.h>
E 27
I 27
#include <sys/errno.h>
#include <sys/signal.h>
#include <sys/syslog.h>
E 27
E 12
D 8
#include <time.h>
E 8

int	supplier = -1;		/* process should supply updates */
I 10
D 14
extern int gateway;
E 14
I 14
int	gateway = 0;		/* 1 if we are a gateway to parts beyond */
I 25
int	debug = 0;
E 25
E 14
E 10

struct	rip *msg = (struct rip *)packet;
I 9
D 25
int	hup();
E 25
I 25
D 27
int	hup(), rtdeleteall();
E 27
I 27
int	hup(), rtdeleteall(), sigtrace();
E 27
E 25
E 9

main(argc, argv)
	int argc;
	char *argv[];
{
	int cc;
	struct sockaddr from;
I 2
	u_char retry;
D 13
#ifdef COMPAT
	int snoroute;
#endif
E 13
E 2
	
	argv0 = argv;
I 12
D 16
	openlog("routed", LOG_PID, 0);
E 16
I 16
D 17
	openlog("routed", LOG_PID | LOG_ODELAY, 0);
E 17
I 17
	openlog("routed", LOG_PID | LOG_ODELAY, LOG_DAEMON);
I 20
D 22
	setlogmask(LOG_UPTO(LOG_WARNING));
E 22
I 22
	setlogmask(LOG_WARNING);
E 22
E 20
E 17
E 16
E 12
D 3
#ifndef DEBUG
	if (fork())
		exit(0);
	for (cc = 0; cc < 10; cc++)
		(void) close(cc);
	(void) open("/", 0);
	(void) dup2(0, 1);
	(void) dup2(0, 2);
	{ int t = open("/dev/tty", 2);
	  if (t >= 0) {
		ioctl(t, TIOCNOTTY, (char *)0);
		(void) close(t);
	  }
	}
#endif
E 3
D 2
	if (tracing)
		traceon("/etc/routerlog");

	/*
	 * We use two sockets.  One for which outgoing
	 * packets are routed and for which they're not.
	 * The latter allows us to delete routing table
	 * entries in the kernel for network interfaces
	 * attached to our host which we believe are down
	 * while still polling it to see when/if it comes
	 * back up.  With the new ipc interface we'll be
	 * able to specify ``don't route'' as an option
	 * to send, but until then we utilize a second port.
	 */
E 2
	sp = getservbyname("router", "udp");
D 2
	if (sp == 0) {
		fprintf(stderr, "routed: udp/router: unknown service\n");
E 2
I 2
	if (sp == NULL) {
		fprintf(stderr, "routed: router/udp: unknown service\n");
E 2
		exit(1);
	}
D 2
	routingaddr.sin_family = AF_INET;
	routingaddr.sin_port = htons(sp->s_port);
	noroutingaddr.sin_family = AF_INET;
	noroutingaddr.sin_port = htons(sp->s_port + 1);
again:
	s = socket(SOCK_DGRAM, 0, &routingaddr, 0);
	if (s < 0) {
		perror("socket");
		sleep(30);
		goto again;
	}
again2:
	snoroute = socket(SOCK_DGRAM, 0, &noroutingaddr, SO_DONTROUTE);
	if (snoroute < 0) {
		perror("socket");
		sleep(30);
		goto again2;
	}
E 2
I 2
	addr.sin_family = AF_INET;
	addr.sin_port = sp->s_port;
	s = getsocket(AF_INET, SOCK_DGRAM, &addr);
	if (s < 0)
		exit(1);
D 13
#ifdef COMPAT
	bzero(&addr, sizeof (addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(ntohs(sp->s_port) + 1);
	snoroute = getsocket(AF_INET, SOCK_DGRAM, &addr);
	if (snoroute < 0)
		exit(1);
#endif
E 13
E 2
	argv++, argc--;
	while (argc > 0 && **argv == '-') {
D 3
		if (!strcmp(*argv, "-s") == 0) {
E 3
I 3
		if (strcmp(*argv, "-s") == 0) {
E 3
			supplier = 1;
			argv++, argc--;
			continue;
		}
D 3
		if (!strcmp(*argv, "-q") == 0) {
E 3
I 3
		if (strcmp(*argv, "-q") == 0) {
E 3
			supplier = 0;
			argv++, argc--;
			continue;
		}
D 2
		goto usage;
	}
	if (argc > 0) {
usage:
E 2
D 3
		fprintf(stderr, "usage: routed [ -s ] [ -q ]\n");
E 3
I 3
		if (strcmp(*argv, "-t") == 0) {
D 27
			tracepackets++;
E 27
I 27
			if (tracehistory == 0)
				tracehistory++;
			else {
				tracehistory = 0;
				tracepackets++;
			}
E 27
I 20
D 22
			setlogmask(LOG_UPTO(LOG_DEBUG));
E 22
I 22
			setlogmask(LOG_DEBUG);
E 22
			argv++, argc--;
			continue;
		}
		if (strcmp(*argv, "-d") == 0) {
I 25
			debug++;
E 25
D 22
			setlogmask(LOG_UPTO(LOG_DEBUG));
E 22
I 22
			setlogmask(LOG_DEBUG);
E 22
E 20
			argv++, argc--;
			continue;
		}
D 10
		fprintf(stderr, "usage: routed [ -s ] [ -q ] [ -t ]\n");
E 10
I 10
		if (strcmp(*argv, "-g") == 0) {
			gateway = 1;
			argv++, argc--;
			continue;
		}
D 14
		if (strcmp(*argv, "-l") == 0) {
			gateway = -1;
			argv++, argc--;
			continue;
		}
E 14
		fprintf(stderr,
D 14
			"usage: routed [ -s ] [ -q ] [ -t ] [ -g ] [ -l ]\n");
E 14
I 14
			"usage: routed [ -s ] [ -q ] [ -t ] [ -g ]\n");
E 14
E 10
E 3
		exit(1);
	}
I 3
D 25
#ifndef DEBUG
	if (!tracepackets) {
E 25
I 25
	if (tracepackets == 0 && debug == 0) {
E 25
		int t;

		if (fork())
			exit(0);
D 4
		for (cc = 0; cc < 10; cc++)
			(void) close(cc);
E 4
I 4
		for (t = 0; t < 20; t++)
			if (t != s)
D 13
#ifdef COMPAT
D 5
			    if (t != snoroute)
E 5
I 5
				if (t != snoroute)
E 5
#endif
E 13
D 16
				(void) close(cc);
E 16
I 16
				(void) close(t);
E 16
E 4
		(void) open("/", 0);
		(void) dup2(0, 1);
		(void) dup2(0, 2);
		t = open("/dev/tty", 2);
		if (t >= 0) {
			ioctl(t, TIOCNOTTY, (char *)0);
			(void) close(t);
		}
	}
D 25
#endif
E 25
E 3
	/*
I 2
	 * Any extra argument is considered
	 * a tracing log file.
	 */
	if (argc > 0)
		traceon(*argv);
	/*
E 2
	 * Collect an initial view of the world by
D 14
	 * snooping in the kernel and the gateway kludge
E 14
I 14
	 * checking the interface configuration and the gateway kludge
E 14
	 * file.  Then, send a request packet on all
	 * directly connected networks to find out what
	 * everyone else thinks.
	 */
	rtinit();
D 23
	gwkludge();
E 23
	ifinit();
I 23
	gwkludge();
E 23
I 14
	if (gateway > 0)
		rtdefault();
E 14
	if (supplier < 0)
		supplier = 0;
	msg->rip_cmd = RIPCMD_REQUEST;
I 5
	msg->rip_vers = RIPVERSION;
E 5
	msg->rip_nets[0].rip_dst.sa_family = AF_UNSPEC;
	msg->rip_nets[0].rip_metric = HOPCNT_INFINITY;
I 5
D 6
#ifdef notyet
E 6
	msg->rip_nets[0].rip_dst.sa_family = htons(AF_UNSPEC);
	msg->rip_nets[0].rip_metric = htonl(HOPCNT_INFINITY);
D 6
#endif
E 6
E 5
	toall(sendmsg);
D 7
	sigset(SIGALRM, timer);
E 7
I 7
	signal(SIGALRM, timer);
I 9
	signal(SIGHUP, hup);
I 12
	signal(SIGTERM, hup);
I 25
	signal(SIGINT, rtdeleteall);
I 27
	signal(SIGUSR1, sigtrace);
	signal(SIGUSR2, sigtrace);
E 27
E 25
E 12
E 9
E 7
	timer();

D 2
#define	INFINITY	1000000
E 2
	for (;;) {
		int ibits;
		register int n;

D 2
		ibits = (1 << s) | (1 << snoroute);
		n = select(32, &ibits, 0, INFINITY);
E 2
I 2
		ibits = 1 << s;
D 13
#ifdef COMPAT
		ibits |= 1 << snoroute;
#endif
E 13
		n = select(20, &ibits, 0, 0, 0);
E 2
		if (n < 0)
			continue;
		if (ibits & (1 << s))
			process(s);
I 2
D 13
#ifdef COMPAT
E 2
		if (ibits & (1 << snoroute))
			process(snoroute);
I 2
#endif
E 13
		/* handle ICMP redirects */
E 2
	}
}

process(fd)
	int fd;
{
D 2
	register int cc;
E 2
	struct sockaddr from;
I 2
D 7
	int fromlen = sizeof (from), cc;
E 7
I 7
	int fromlen = sizeof (from), cc, omask;
I 27
	time_t now;
E 27
E 7
E 2

D 2
	cc = receive(fd, &from, packet, sizeof (packet));
E 2
I 2
	cc = recvfrom(fd, packet, sizeof (packet), 0, &from, &fromlen);
E 2
	if (cc <= 0) {
		if (cc < 0 && errno != EINTR)
D 2
			perror("receive");
E 2
I 2
			perror("recvfrom");
E 2
		return;
	}
I 2
	if (fromlen != sizeof (struct sockaddr_in))
		return;
I 27
	if (traceactions && !tracepackets) {
		(void) time(&now);
		curtime = ctime(&now);
	}
E 27
E 2
D 7
	sighold(SIGALRM);
E 7
I 7
D 16
#define	mask(s)	(1<<((s)-1))
	omask = sigblock(mask(SIGALRM));
E 16
I 16
	omask = sigblock(sigmask(SIGALRM));
E 16
E 7
	rip_input(&from, cc);
D 7
	sigrelse(SIGALRM);
E 7
I 7
	sigsetmask(omask);
E 7
I 2
}

getsocket(domain, type, sin)
	int domain, type;
	struct sockaddr_in *sin;
{
D 12
	int retry, s;
E 12
I 12
D 18
	int retry, s, on = 1;
E 18
I 18
	int s, on = 1;
E 18
E 12

D 18
	retry = 1;
D 16
	while ((s = socket(domain, type, 0, 0)) < 0 && retry) {
E 16
I 16
	while ((s = socket(domain, type, 0)) < 0 && retry) {
E 18
I 18
D 19
	if (s = socket(domain, type, 0)) {
E 19
I 19
	if ((s = socket(domain, type, 0)) < 0) {
E 19
E 18
E 16
		perror("socket");
D 18
		sleep(5 * retry);
		retry <<= 1;
	}
D 12
	if (retry == 0)
E 12
I 12
	if (retry == 0) {
E 18
		syslog(LOG_ERR, "socket: %m");
E 12
		return (-1);
I 12
	}
	if (setsockopt(s, SOL_SOCKET, SO_BROADCAST, &on, sizeof (on)) < 0) {
		syslog(LOG_ERR, "setsockopt SO_BROADCAST: %m");
D 18
		exit(1);
E 18
I 18
		close(s);
		return (-1);
E 18
	}
I 23
	on = 48*1024;
	if (setsockopt(s, SOL_SOCKET, SO_RCVBUF, &on, sizeof (on)) < 0)
		syslog(LOG_ERR, "setsockopt SO_RCVBUF: %m");
E 23
E 12
D 18
	while (bind(s, sin, sizeof (*sin), 0) < 0 && retry) {
E 18
I 18
	if (bind(s, sin, sizeof (*sin), 0) < 0) {
E 18
		perror("bind");
D 18
		sleep(5 * retry);
		retry <<= 1;
	}
D 12
	if (retry == 0)
E 12
I 12
	if (retry == 0) {
E 18
		syslog(LOG_ERR, "bind: %m");
I 18
		close(s);
E 18
E 12
		return (-1);
I 12
	}
E 12
	return (s);
E 2
}
E 1
