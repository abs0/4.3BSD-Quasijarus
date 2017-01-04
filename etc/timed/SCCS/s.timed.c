h06864
s 00010/00005/00621
d D 2.14 88/06/18 14:08:27 bostic 18 17
c install approved copyright notice
e
s 00010/00004/00616
d D 2.13 87/12/23 14:30:19 bostic 17 16
c append Berkeley header; NASA wants a copy
e
s 00001/00001/00619
d D 2.12 87/04/06 11:48:33 bostic 16 15
c printf format/argument mismatch
e
s 00018/00008/00602
d D 2.11 87/03/04 15:56:19 karels 15 14
c don't hold icmp socket open when not using it
e
s 00005/00007/00605
d D 2.10 86/06/02 10:58:15 bloom 14 13
x 11
c move fork back -- closed file descriptors that should be open
e
s 00013/00014/00597
d D 2.9 86/05/28 20:10:07 bloom 13 12
c lint cleanup (fix sequence number problem)
e
s 00004/00005/00607
d D 2.8 86/05/27 15:58:21 karels 12 11
c toss MAXSEQ
e
s 00021/00022/00591
d D 2.7 86/05/27 15:36:11 karels 11 10
c delay fork until set up
e
s 00004/00002/00609
d D 2.6 86/05/15 08:47:17 bloom 10 9
c only one call to openlog needed, need to know if we just received a quit
e
s 00058/00014/00553
d D 2.5 86/04/26 22:46:25 bloom 9 8
c allow multiple -n flags, add -i flag from Kirk Smith (ks@ef.purdue.edu)
e
s 00208/00141/00359
d D 2.4 86/04/11 18:17:00 bloom 8 7
c major work on multiple network code (Kirk Smith, ks@ef.purdue.edu)
e
s 00001/00000/00499
d D 2.3 86/02/17 13:18:11 bloom 7 6
c clean hostlist when going from master to slave (from ks@purdue)
e
s 00001/00001/00498
d D 2.2 86/02/05 18:30:22 bloom 6 5
c fix typo
e
s 00198/00106/00301
d D 2.1 85/12/10 13:07:34 bloom 5 4
c Multi network support
e
s 00002/00006/00405
d D 1.4 85/10/29 11:44:18 bloom 4 3
c simplify code for getting date string
e
s 00002/00002/00409
d D 1.3 85/10/05 22:18:41 bloom 3 2
c fix bug that caused -M to be ignored
e
s 00103/00070/00308
d D 1.2 85/09/18 19:58:18 bloom 2 1
c move constants, fix syslog messages, fix nflag code, detach from terminal,
c fix bug which allowed a slave to respond as master in certain circumstances,
c fix casual (by gusella)
e
s 00378/00000/00000
d D 1.1 85/06/22 22:08:00 gusella 1 0
c date and time created 85/06/22 22:08:00 by gusella
e
u
U
t
T
I 1
/*
D 11
D 14
 * Copyright (c) 1983 Regents of the University of California.
E 14
I 14
 * Copyright (c) 1985 Regents of the University of California.
E 14
E 11
I 11
 * Copyright (c) 1985 Regents of the University of California.
E 11
D 17
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 17
I 17
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 18
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 18
I 18
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
E 18
E 17
 */

#ifndef lint
char copyright[] =
D 11
D 14
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 14
I 14
"%Z% Copyright (c) 1985 Regents of the University of California.\n\
E 14
E 11
I 11
"@(#) Copyright (c) 1985 Regents of the University of California.\n\
E 11
 All rights reserved.\n";
D 17
#endif not lint
E 17
I 17
#endif /* not lint */
E 17

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 17
#endif not lint
E 17
I 17
#endif /* not lint */
E 17

#include "globals.h"
#define TSPTYPES
#include <protocols/timed.h>
#include <net/if.h>
#include <sys/file.h>
#include <sys/ioctl.h>
#include <setjmp.h>

D 2
#define OFF		0
#define ON		1
#define SLAVE		0
#define MASTER		1
#define MAXRANDOM	2147483648	/* 2**31, max random number */

E 2
int id;
int trace;
D 15
int sock, sock_raw;
E 15
I 15
int sock, sock_raw = -1;
E 15
D 5
int status;     			/* either MASTER or SLAVE */
E 5
I 5
int status = 0;
E 5
int backoff;
int slvcount;				/* no. of slaves controlled by master */
int machup;
u_short sequence;			/* sequence number */
long delay1;
long delay2;
I 13
long random();
E 13
D 2
char hostname[32];
E 2
I 2
char hostname[MAXHOSTNAMELEN];
E 2
D 5
struct in_addr broadcastaddr;		/* local net broadcast address */
I 2
u_long netmask, mynet = 0;		/* my network number & netmask */
E 2
struct sockaddr_in server;
E 5
struct host hp[NHOSTS];
D 5
char *fj;
E 5
I 5
char tracefile[] = "/usr/adm/timed.log";
E 5
FILE *fd;
jmp_buf jmpenv;
I 5
struct netinfo *nettab = NULL;
I 8
int nslavenets;		/* Number of networks were I could be a slave */
int nmasternets;	/* Number of networks were I could be a master */
int nignorednets;	/* Number of ignored networks */
int nnets;		/* Number of networks I am connected to */
struct netinfo *slavenet;
struct netinfo *firstslavenet();
int Mflag;
I 10
int justquit = 0;

E 10
I 9
struct nets {
	char *name;
	long net;
	struct nets *next;
} *nets = (struct nets *)0;
E 9
E 8
E 5

D 5
extern struct sockaddr_in from;

E 5
/*
 * The timedaemons synchronize the clocks of hosts in a local area network.
 * One daemon runs as master, all the others as slaves. The master
 * performs the task of computing clock differences and sends correction
 * values to the slaves. 
 * Slaves start an election to choose a new master when the latter disappears 
 * because of a machine crash, network partition, or when killed.
 * A resolution protocol is used to kill all but one of the masters
 * that happen to exist in segments of a partitioned network when the 
 * network partition is fixed.
 *
 * Authors: Riccardo Gusella & Stefano Zatti
D 5
 *
 * For problems and suggestions, please send mail to gusella@BERKELEY
E 5
 */

main(argc, argv)
int argc;
char **argv;
{
	int on;
	int ret;
	long seed;
D 8
	int Mflag;
E 8
D 9
	int nflag;
D 2
	char mastername[32];
E 2
I 2
D 8
	char mastername[MAXHOSTNAMELEN];
E 8
E 2
	char *netname;
E 9
I 9
	int nflag, iflag;
E 9
	struct timeval time;
	struct servent *srvp;
D 9
	struct netent *getnetent();
	struct netent *localnet;
E 9
D 8
	struct sockaddr_in masteraddr;
E 8
D 13
	struct tsp resp, conflict, *answer, *readmsg(), *acksend();
E 13
	long casual();
D 5
	char *malloc(), *strcpy();
E 5
	char *date();
D 2
	struct in_addr inet_makeaddr();
E 2
I 2
	int n;
D 5
	int n_addrlen;
	char *n_addr;
E 5
I 5
	int flag;
E 5
	char buf[BUFSIZ];
	struct ifconf ifc;
	struct ifreq ifreq, *ifr;
D 5
	struct sockaddr_in *sin;
E 5
I 5
	register struct netinfo *ntp;
	struct netinfo *ntip;
I 8
	struct netinfo *savefromnet;
E 8
	struct sockaddr_in server;
	u_short port;
D 13
	int havemaster = 0;
E 13
I 13
	uid_t getuid();
E 13
E 5
D 8
	
E 8
I 8

E 8
I 5
#ifdef lint
	ntip = NULL;
#endif
E 5
E 2

D 3
	Mflag = SLAVE;
E 3
I 3
	Mflag = 0;
E 3
	on = 1;
	backoff = 1;
D 5
	fj = "/usr/adm/timed.log";
E 5
	trace = OFF;
	nflag = OFF;
I 9
	iflag = OFF;
E 9
I 2
D 10
	openlog("timed", LOG_ODELAY, LOG_DAEMON);
E 10
I 10
	openlog("timed", LOG_CONS|LOG_PID, LOG_DAEMON);
E 10
E 2

	if (getuid() != 0) {
D 2
		printf("Sorry: need to be root\n");
E 2
I 2
		fprintf(stderr, "Timed: not superuser\n");
E 2
		exit(1);
	}

	while (--argc > 0 && **++argv == '-') {
		(*argv)++;
		do {
			switch (**argv) {

			case 'M':
D 3
				Mflag = MASTER; 
E 3
I 3
				Mflag = 1; 
E 3
				break;
			case 't':
				trace = ON; 
D 2
				fd = fopen(fj, "w");
				fprintf(fd, "Tracing started on: %s\n\n", 
							date());
				(void)fflush(fd);
E 2
				break;
			case 'n':
				argc--, argv++;
D 9
				nflag = ON;
				netname = *argv;
E 9
I 9
				if (iflag) {
					fprintf(stderr,
				    "timed: -i and -n make no sense together\n");
				} else {
					nflag = ON;
D 13
					addnetname(*argv, &nets);
E 13
I 13
					addnetname(*argv);
E 13
				}
E 9
				while (*(++(*argv)+1)) ;
				break;
I 9
			case 'i':
				argc--, argv++;
				if (nflag) {
					fprintf(stderr,
				    "timed: -i and -n make no sense together\n");
				} else {
					iflag = ON;
D 13
					addnetname(*argv, &nets);
E 13
I 13
					addnetname(*argv);
E 13
				}
				while (*(++(*argv)+1)) ;
				break;
E 9
			default:
				fprintf(stderr, "timed: -%c: unknown option\n", 
							**argv);
				break;
			}
		} while (*++(*argv));
	}

I 2
D 11
#ifndef DEBUG
	if (fork())
		exit(0);
	{ int s;
D 5
	  for (s = 0; s < 10; s++)
E 5
I 5
	  for (s = getdtablesize(); s >= 0; --s)
E 5
		(void) close(s);
D 5
	  (void) open("/", 0);
E 5
I 5
	  (void) open("/dev/null", 0);
E 5
	  (void) dup2(0, 1);
	  (void) dup2(0, 2);
	  s = open("/dev/tty", 2);
	  if (s >= 0) {
D 14
		(void) ioctl(s, (int)TIOCNOTTY, (char *)0);
E 14
I 14
		(void) ioctl(s, TIOCNOTTY, (char *)0);
E 14
		(void) close(s);
	  }
	}
#endif

E 11
	if (trace == ON) {
D 5
		fd = fopen(fj, "w");
E 5
I 5
		fd = fopen(tracefile, "w");
		setlinebuf(fd);
E 5
		fprintf(fd, "Tracing started on: %s\n\n", 
					date());
D 5
		(void)fflush(fd);
E 5
	}
D 10
	openlog("timed", LOG_ODELAY|LOG_CONS, LOG_DAEMON);
E 10

E 2
	srvp = getservbyname("timed", "udp");
	if (srvp == 0) {
D 2
		syslog(LOG_ERR, "udp/timed: unknown service\n");
E 2
I 2
		syslog(LOG_CRIT, "unknown service 'timed/udp'");
E 2
		exit(1);
	}
I 5
	port = srvp->s_port;
E 5
	server.sin_port = srvp->s_port;
	server.sin_family = AF_INET;
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0) {
D 2
		syslog(LOG_ERR, "timed: opening socket\n");
E 2
I 2
		syslog(LOG_ERR, "socket: %m");
E 2
		exit(1);
	}
	if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (char *)&on, 
							sizeof(on)) < 0) {
D 2
		syslog(LOG_ERR, "timed: setsockopt");
E 2
I 2
		syslog(LOG_ERR, "setsockopt: %m");
E 2
		exit(1);
	}
	if (bind(sock, &server, sizeof(server))) {
		if (errno == EADDRINUSE)
D 2
			fprintf(stderr, "timed already running\n");
E 2
I 2
		        syslog(LOG_ERR, "server already running");
E 2
		else
D 2
			syslog(LOG_ERR, "timed: bind");
E 2
I 2
		        syslog(LOG_ERR, "bind: %m");
E 2
		exit(1);
	}

	/* choose a unique seed for random number generation */
	(void)gettimeofday(&time, (struct timezone *)0);
	seed = time.tv_sec + time.tv_usec;
	srandom(seed);

D 12
	sequence = casual((long)1, (long)MAXSEQ);     /* initial seq number */
E 12
I 12
	sequence = random();     /* initial seq number */
E 12

	/* rounds kernel variable time to multiple of 5 ms. */
	time.tv_sec = 0;
	time.tv_usec = -((time.tv_usec/1000) % 5) * 1000;
	(void)adjtime(&time, (struct timeval *)0);

	id = getpid();

	if (gethostname(hostname, sizeof(hostname) - 1) < 0) {
D 2
		syslog(LOG_ERR, "timed: gethostname: %m");
E 2
I 2
		syslog(LOG_ERR, "gethostname: %m");
E 2
		exit(1);
	}
	hp[0].name = hostname;

D 9
	if (nflag) {
		localnet = getnetbyname(netname);
		if (localnet == NULL) {
D 2
			syslog(LOG_ERR, "timed: getnetbyname: %m");
E 2
I 2
			syslog(LOG_ERR, "getnetbyname: unknown net %s",
				netname);
E 2
			exit(1);
E 9
I 9
	if (nflag || iflag) {
		struct netent *getnetent();
		struct netent *n;
		struct nets *np;
		for ( np = nets ; np ; np = np->next) {
			n = getnetbyname(np->name);
			if (n == NULL) {
				syslog(LOG_ERR, "getnetbyname: unknown net %s",
					np->name);
				exit(1);
			}
			np->net = n->n_net;
E 9
		}
D 2
		if (localnet == NULL) {
			syslog(LOG_ERR, "timed: no network: %m");
			exit(1);
E 2
I 2
	}
	ifc.ifc_len = sizeof(buf);
	ifc.ifc_buf = buf;
D 13
	if (ioctl(sock, (int)SIOCGIFCONF, (char *)&ifc) < 0) {
E 13
I 13
	if (ioctl(sock, SIOCGIFCONF, (char *)&ifc) < 0) {
E 13
		syslog(LOG_ERR, "get interface configuration: %m");
		exit(1);
	}
D 5
	ifr = ifc.ifc_req;
	for (n = ifc.ifc_len/sizeof(struct ifreq); n > 0; n--, ifr++) {
E 5
I 5
	n = ifc.ifc_len/sizeof(struct ifreq);
	ntp = NULL;
	for (ifr = ifc.ifc_req; n > 0; n--, ifr++) {
		if (ifr->ifr_addr.sa_family != AF_INET)
			continue;
E 5
		ifreq = *ifr;
I 5
		if (ntp == NULL)
			ntp = (struct netinfo *)malloc(sizeof(struct netinfo));
		ntp->my_addr = 
			((struct sockaddr_in *)&ifreq.ifr_addr)->sin_addr;
E 5
D 13
		if (ioctl(sock, (int)SIOCGIFFLAGS, 
E 13
I 13
		if (ioctl(sock, SIOCGIFFLAGS, 
E 13
					(char *)&ifreq) < 0) {
			syslog(LOG_ERR, "get interface flags: %m");
			continue;
E 2
		}
D 2
		broadcastaddr = inet_makeaddr(localnet->n_net,INADDR_BROADCAST);
	} else {
		int n;
		int n_addrlen;
		char *n_addr;
		char buf[BUFSIZ];
		struct ifconf ifc;
		struct ifreq ifreq, *ifr;
		struct sockaddr_in *sin;
	
		ifc.ifc_len = sizeof(buf);
		ifc.ifc_buf = buf;
		if (ioctl(sock, (int)SIOCGIFCONF, (char *)&ifc) < 0) {
			syslog(LOG_ERR, "timed: (get interface configuration)");
			exit(1);
E 2
I 2
		if ((ifreq.ifr_flags & IFF_UP) == 0 ||
D 5
			(ifreq.ifr_flags & IFF_BROADCAST) == 0) {
E 5
I 5
			((ifreq.ifr_flags & IFF_BROADCAST) == 0 &&
			(ifreq.ifr_flags & IFF_POINTOPOINT) == 0)) {
E 5
			continue;
E 2
		}
I 5
		if (ifreq.ifr_flags & IFF_BROADCAST)
			flag = 1;
		else
			flag = 0;
E 5
D 2
		ifr = ifc.ifc_req;
		for (n = ifc.ifc_len/sizeof(struct ifreq); n > 0; n--, ifr++) {
			ifreq = *ifr;
			if (ioctl(sock, (int)SIOCGIFFLAGS, 
						(char *)&ifreq) < 0) {
				syslog(LOG_ERR, "timed: (get interface flags)");
				continue;
E 2
I 2
D 13
		if (ioctl(sock, (int)SIOCGIFNETMASK, 
E 13
I 13
		if (ioctl(sock, SIOCGIFNETMASK, 
E 13
					(char *)&ifreq) < 0) {
D 5
			syslog(LOG_ERR, "get broadaddr: %m");
E 5
I 5
			syslog(LOG_ERR, "get netmask: %m");
E 5
			continue;
		}
D 5
		netmask = ((struct sockaddr_in *)
E 5
I 5
		ntp->mask = ((struct sockaddr_in *)
E 5
			&ifreq.ifr_addr)->sin_addr.s_addr;
D 5
		if (ioctl(sock, (int)SIOCGIFBRDADDR, 
					(char *)&ifreq) < 0) {
			syslog(LOG_ERR, "get broadaddr: %m");
			continue;
E 5
I 5
		if (flag) {
D 13
			if (ioctl(sock, (int)SIOCGIFBRDADDR, 
E 13
I 13
			if (ioctl(sock, SIOCGIFBRDADDR, 
E 13
						(char *)&ifreq) < 0) {
				syslog(LOG_ERR, "get broadaddr: %m");
				continue;
			}
			ntp->dest_addr = *(struct sockaddr_in *)&ifreq.ifr_broadaddr;
		} else {
D 13
			if (ioctl(sock, (int)SIOCGIFDSTADDR, 
E 13
I 13
			if (ioctl(sock, SIOCGIFDSTADDR, 
E 13
						(char *)&ifreq) < 0) {
				syslog(LOG_ERR, "get destaddr: %m");
				continue;
			}
			ntp->dest_addr = *(struct sockaddr_in *)&ifreq.ifr_dstaddr;
E 5
		}
D 5
		n_addrlen = sizeof(ifr->ifr_addr);
		n_addr = (char *)malloc((unsigned)n_addrlen);
		bcopy((char *)&ifreq.ifr_broadaddr, n_addr, n_addrlen);
		sin = (struct sockaddr_in *)n_addr;
		broadcastaddr = sin->sin_addr;
E 5
I 5
		ntp->dest_addr.sin_port = port;
E 5
D 9
		if (nflag) {
E 9
I 9
		if (nflag || iflag) {
E 9
			u_long addr, mask;
I 9
			struct nets *n;
E 9

D 5
			addr = ntohl(broadcastaddr.s_addr);
			mask = ntohl(netmask);
E 5
I 5
			addr = ntohl(ntp->dest_addr.sin_addr.s_addr);
			mask = ntohl(ntp->mask);
E 5
			while ((mask & 1) == 0) {
				addr >>= 1;
				mask >>= 1;
E 2
			}
D 2
			if ((ifreq.ifr_flags & IFF_UP) == 0 ||
		    		(ifreq.ifr_flags & IFF_BROADCAST) == 0) {
E 2
I 2
D 9
			if (addr != localnet->n_net)
E 9
I 9
			for (n = nets ; n ; n = n->next)
				if (addr == n->net)
					break;
			if (nflag && !n || iflag && n)
E 9
E 2
				continue;
D 2
			}
			if (ioctl(sock, (int)SIOCGIFBRDADDR, 
						(char *)&ifreq) < 0) {
				syslog(LOG_ERR, "timed: (get broadaddr)");
				continue;
			}
			n_addrlen = sizeof(ifr->ifr_addr);
			n_addr = (char *)malloc((unsigned)n_addrlen);
			bcopy((char *)&ifreq.ifr_broadaddr, n_addr, n_addrlen);
			sin = (struct sockaddr_in *)n_addr;
			broadcastaddr = sin->sin_addr;
			break;
E 2
		}
I 2
D 5
		mynet = netmask & broadcastaddr.s_addr;
		break;
E 5
I 5
		ntp->net = ntp->mask & ntp->dest_addr.sin_addr.s_addr;
		ntp->next = NULL;
		if (nettab == NULL) {
			nettab = ntp;
		} else {
			ntip->next = ntp;
		}
		ntip = ntp;
		ntp = NULL;
E 5
E 2
	}
I 2
D 5
	if (!mynet) {
E 5
I 5
	if (ntp)
		(void) free((char *)ntp);
	if (nettab == NULL) {
E 5
		syslog(LOG_ERR, "No network usable");
		exit(1);
	}
E 2

I 5
D 8
	for(ntp = nettab; ntp != NULL; ntp = ntp->next) {
		/* look for master */
		resp.tsp_type = TSP_MASTERREQ;
		(void)strcpy(resp.tsp_name, hostname);
		answer = acksend(&resp, &ntp->dest_addr, (char *)ANYADDR, 
		    TSP_MASTERACK, ntp);
		if (answer == NULL) {
			/*
			 * Various conditions can cause conflict: race between
			 * two just started timedaemons when no master is
			 * present, or timedaemon started during an election.
			 * Conservative approach is taken: give up and became a
			 * slave postponing election of a master until first
			 * timer expires.
			 */
			time.tv_sec = time.tv_usec = 0;
			answer = readmsg(TSP_MASTERREQ, (char *)ANYADDR,
			    &time, ntp);
			if (answer != NULL) {
				if (!havemaster) {
					ntp->status = SLAVE;
					status |= SLAVE;
					havemaster++;
				} else
					ntp->status = IGNORE;
				continue;
			}
	
			time.tv_sec = time.tv_usec = 0;
			answer = readmsg(TSP_MASTERUP, (char *)ANYADDR,
			    &time, ntp);
			if (answer != NULL) {
				if (!havemaster) {
					ntp->status = SLAVE;
					status |= SLAVE;
					havemaster++;
				} else
					ntp->status = IGNORE;
				continue;
			}
	
			time.tv_sec = time.tv_usec = 0;
			answer = readmsg(TSP_ELECTION, (char *)ANYADDR,
			    &time, ntp);
			if (answer != NULL) {
				if (!havemaster) {
					ntp->status = SLAVE;
					status |= SLAVE;
					havemaster++;
				} else
					ntp->status = IGNORE;
				continue;
			}
			ntp->status = MASTER;
			status |= MASTER;
		} else {
			if (!havemaster) {
				ntp->status = SLAVE;
				status |= SLAVE;
				havemaster++;
			} else
				ntp->status = IGNORE;
			(void)strcpy(mastername, answer->tsp_name);
			masteraddr = from;

			/*
			 * If network has been partitioned, there might be other
			 * masters; tell the one we have just acknowledged that 
			 * it has to gain control over the others. 
			 */
			time.tv_sec = 0;
			time.tv_usec = 300000;
			answer = readmsg(TSP_MASTERACK, (char *)ANYADDR, &time,
			    ntp);
			/*
			 * checking also not to send CONFLICT to ack'ed master
			 * due to duplicated MASTERACKs
			 */
			if (answer != NULL && 
			    strcmp(answer->tsp_name, mastername) != 0) {
				conflict.tsp_type = TSP_CONFLICT;
				(void)strcpy(conflict.tsp_name, hostname);
				if (acksend(&conflict, &masteraddr, mastername,
				    TSP_ACK, (struct netinfo *)NULL) == NULL) {
					syslog(LOG_ERR, 
					    "error on sending TSP_CONFLICT");
					exit(1);
				}
			}
		}
	}
E 8
I 8
	for (ntp = nettab; ntp != NULL; ntp = ntp->next)
		lookformaster(ntp);
	setstatus();
	/*
	 * Take care of some basic initialization.
	 */
E 8
E 5
	/* us. delay to be used in response to broadcast */
	delay1 = casual((long)10000, 200000);	

	/* election timer delay in secs. */
	delay2 = casual((long)MINTOUT, (long)MAXTOUT);
I 11
#ifndef DEBUG
	if (fork())
		exit(0);
	{ int s;
	  for (s = getdtablesize(); s >= 0; --s)
		(void) close(s);
	  (void) open("/dev/null", 0);
	  (void) dup2(0, 1);
	  (void) dup2(0, 2);
	  s = open("/dev/tty", 2);
	  if (s >= 0) {
D 13
		(void) ioctl(s, (int)TIOCNOTTY, (char *)0);
E 13
I 13
D 14
		(void) ioctl(s, TIOCNOTTY, (char *)0);
E 14
E 13
		(void) close(s);
	  }
	}
#endif
E 11

I 11

E 11
D 5
	/* look for master */
	resp.tsp_type = TSP_MASTERREQ;
	(void)strcpy(resp.tsp_name, hostname);
	answer = acksend(&resp, (char *)ANYADDR, TSP_MASTERACK);
	if (answer == NULL) {
		status = MASTER;
	} else {
		status = SLAVE;
		(void)strcpy(mastername, answer->tsp_name);
		masteraddr = from;

		/*
		 * If network has been partitioned, there might be other
		 * masters; tell the one we have just acknowledged that 
		 * it has to gain control over the others. 
		 */
		time.tv_sec = 0;
		time.tv_usec = 300000;
		answer = readmsg(TSP_MASTERACK, (char *)ANYADDR, &time);
		/*
		 * checking also not to send CONFLICT to ack'ed master
		 * due to duplicated MASTERACKs
		 */
		if (answer != NULL && 
				strcmp(answer->tsp_name, mastername) != 0) {
			conflict.tsp_type = TSP_CONFLICT;
			(void)strcpy(conflict.tsp_name, hostname);
			server = masteraddr;
			if (acksend(&conflict, (char *)mastername, 
							TSP_ACK) == NULL) {
D 2
				syslog(LOG_ERR, "timed: error on sending TSP_CONFLICT\n");
E 2
I 2
				syslog(LOG_ERR, "error on sending TSP_CONFLICT");
E 2
				exit(1);
			}
		}
	}
E 5
	if (Mflag) {
D 15
		/* open raw socket used to measure time differences */
		sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP); 
		if (sock_raw < 0)  {
D 2
			fprintf(stderr, "timed: opening raw socket");
E 2
I 2
			syslog(LOG_ERR, "opening raw socket: %m");
E 2
			exit (1);
		}

E 15
		/*
		 * number (increased by 1) of slaves controlled by master: 
		 * used in master.c, candidate.c, networkdelta.c, and 
		 * correct.c 
		 */
		slvcount = 1;
D 8

E 8
D 5
		/*
		 * Various conditions can cause conflict: race between
		 * two just started timedaemons when no master is present,
		 * or timedaemon started during an election.
		 * Conservative approach is taken: give up and became a
		 * slave postponing election of a master until first
		 * timer expires.
		 */
		if (status == MASTER) {
			time.tv_sec = time.tv_usec = 0;
			answer = readmsg(TSP_MASTERREQ, (char *)ANYADDR, &time);
			if (answer != NULL) {
				status = SLAVE;
				goto startd;
			}
	
			time.tv_sec = time.tv_usec = 0;
			answer = readmsg(TSP_MASTERUP, (char *)ANYADDR, &time);
			if (answer != NULL) {
				status = SLAVE;
				goto startd;
			}
	
			time.tv_sec = time.tv_usec = 0;
			answer = readmsg(TSP_ELECTION, (char *)ANYADDR, &time);
			if (answer != NULL) 
				status = SLAVE;
		}
startd:
E 5
		ret = setjmp(jmpenv);
I 8

E 8
		switch (ret) {

		case 0: 
I 8
			makeslave(firstslavenet());
			setstatus();
E 8
			break;
		case 1: 
D 8
			/* from slave */
D 5
			status = election();
E 5
I 5
			for (ntp = nettab; ntp != NULL; ntp = ntp->next) {
D 6
				if (ntp->status = SLAVE)
E 6
I 6
				if (ntp->status == SLAVE)
E 6
					break;
			}
			ntp->status = election(ntp);
			status = 0;
			for (ntp = nettab; ntp != NULL; ntp = ntp->next) {
				status |= ntp->status;
			}
			status &= ~IGNORE;
E 8
I 8
			/* Just lost our master */
			setstatus();
			slavenet->status = election(slavenet);
			checkignorednets();
			setstatus();
			if (slavenet->status == MASTER)
				makeslave(firstslavenet());
			else
				makeslave(slavenet);
			setstatus();
E 8
E 5
			break;
		case 2:
D 8
			/* from master */
D 5
			status = SLAVE;
E 5
I 5
			havemaster = 0;
			for (ntp = nettab; ntp != NULL; ntp = ntp->next) {
				if ((from.sin_addr.s_addr & ntp->mask) ==
				    ntp->net) {
					ntp->status = SLAVE;
I 7
					rmnetmachs(ntp);
E 7
					break;
				}
			}
			status = 0;
			for (ntp = nettab; ntp != NULL; ntp = ntp->next) {
				status |= ntp->status;
			}
			status &= ~IGNORE;
E 8
I 8
			/* Just been told to quit */
			fromnet->status = SLAVE;
			setstatus();
			savefromnet = fromnet;
			rmnetmachs(fromnet);
			checkignorednets();
			if (slavenet)
				makeslave(slavenet);
			else
				makeslave(savefromnet);
			setstatus();
I 10
			justquit = 1;
E 10
E 8
E 5
			break;
I 8
			
E 8
		default:
			/* this should not happen */
D 2
			syslog(LOG_ERR, 
				"timed: error on return from longjmp\n");
E 2
I 2
			syslog(LOG_ERR, "Attempt to enter invalid state");
E 2
			break;
		}
			
I 15
		if (status & MASTER) {
			/* open raw socket used to measure time differences */
			if (sock_raw == -1) {
			    sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP); 
			    if (sock_raw < 0)  {
				    syslog(LOG_ERR, "opening raw socket: %m");
				    exit (1);
			    }
			}
		} else {
			/* sock_raw is not being used now */
			if (sock_raw != -1) {
			    (void)close(sock_raw);
			    sock_raw = -1;
			}
		}

E 15
D 2
		if (status) 
E 2
I 2
		if (status == MASTER) 
E 2
			master();
		else 
			slave();
	} else {
I 2
D 5
		status = SLAVE;
E 5
E 2
		/* if Mflag is not set timedaemon is forced to act as a slave */
I 5
		status = SLAVE;
D 8
		ntip = NULL;
		for(ntp = nettab; ntp != NULL; ntp = ntp->next) {
			if (ntp->status & (SLAVE|MASTER)) {
				if (ntip == NULL) {
					ntip = ntp;
					ntp->status = SLAVE;
				} else {
					ntp->status = IGNORE;
				}
			}
		}
E 8
I 8
D 11
D 14
		makeslave(firstslavenet());
E 14
E 11
E 8
E 5
		if (setjmp(jmpenv)) {
D 8
			resp.tsp_type = TSP_SLAVEUP;
I 5
			resp.tsp_vers = TSPVERSION;
E 5
			(void)strcpy(resp.tsp_name, hostname);
D 5
			broadcast(&resp);
E 5
I 5
			bytenetorder(&resp);
			if (sendto(sock, (char *)&resp, sizeof(struct tsp), 0,
			    &ntip->dest_addr, sizeof(struct sockaddr_in)) < 0) {
				syslog(LOG_ERR, "sendto: %m");
E 8
I 8
			setstatus();
			checkignorednets();
D 11
D 14
			makeslave(firstslavenet());
E 14
E 11
		}
I 14
		makeslave(firstslavenet());
E 14
I 11
		makeslave(firstslavenet());
E 11
		for (ntp = nettab; ntp != NULL; ntp = ntp->next)
			if (ntp->status == MASTER)
				ntp->status = IGNORE;
		setstatus();
		slave();
	}
}

/*
 * Try to become master over ignored nets..
 */
checkignorednets()
{
	register struct netinfo *ntp;
	for (ntp = nettab; ntp != NULL; ntp = ntp->next)
		if (ntp->status == IGNORE)
			lookformaster(ntp);
}

lookformaster(ntp)
	register struct netinfo *ntp;
{
	struct tsp resp, conflict, *answer, *readmsg(), *acksend();
	struct timeval time;
	char mastername[MAXHOSTNAMELEN];
	struct sockaddr_in masteraddr;

	ntp->status = SLAVE;
	/* look for master */
	resp.tsp_type = TSP_MASTERREQ;
	(void)strcpy(resp.tsp_name, hostname);
	answer = acksend(&resp, &ntp->dest_addr, (char *)ANYADDR, 
	    TSP_MASTERACK, ntp);
	if (answer == NULL) {
		/*
		 * Various conditions can cause conflict: race between
		 * two just started timedaemons when no master is
		 * present, or timedaemon started during an election.
		 * Conservative approach is taken: give up and became a
		 * slave postponing election of a master until first
		 * timer expires.
		 */
		time.tv_sec = time.tv_usec = 0;
		answer = readmsg(TSP_MASTERREQ, (char *)ANYADDR,
		    &time, ntp);
		if (answer != NULL) {
			ntp->status = SLAVE;
			return;
		}

		time.tv_sec = time.tv_usec = 0;
		answer = readmsg(TSP_MASTERUP, (char *)ANYADDR,
		    &time, ntp);
		if (answer != NULL) {
			ntp->status = SLAVE;
			return;
		}

		time.tv_sec = time.tv_usec = 0;
		answer = readmsg(TSP_ELECTION, (char *)ANYADDR,
		    &time, ntp);
		if (answer != NULL) {
			ntp->status = SLAVE;
			return;
		}
		ntp->status = MASTER;
	} else {
		(void)strcpy(mastername, answer->tsp_name);
		masteraddr = from;

		/*
		 * If network has been partitioned, there might be other
		 * masters; tell the one we have just acknowledged that 
		 * it has to gain control over the others. 
		 */
		time.tv_sec = 0;
		time.tv_usec = 300000;
		answer = readmsg(TSP_MASTERACK, (char *)ANYADDR, &time,
		    ntp);
		/*
		 * checking also not to send CONFLICT to ack'ed master
		 * due to duplicated MASTERACKs
		 */
		if (answer != NULL && 
		    strcmp(answer->tsp_name, mastername) != 0) {
			conflict.tsp_type = TSP_CONFLICT;
			(void)strcpy(conflict.tsp_name, hostname);
			if (acksend(&conflict, &masteraddr, mastername,
			    TSP_ACK, (struct netinfo *)NULL) == NULL) {
				syslog(LOG_ERR, 
				    "error on sending TSP_CONFLICT");
E 8
				exit(1);
			}
E 5
		}
D 8
		slave();
E 8
	}
I 8
}
/*
 * based on the current network configuration, set the status, and count
 * networks;
 */
setstatus()
{
	register struct netinfo *ntp;

	status = 0;
	nmasternets = nslavenets = nnets = nignorednets = 0;
	if (trace)
		fprintf(fd, "Net status:\n");
	for (ntp = nettab; ntp != NULL; ntp = ntp->next) {
D 13
		switch (ntp->status) {
E 13
I 13
		switch ((int)ntp->status) {
E 13
		  case MASTER:
			nmasternets++;
			break;
		  case SLAVE:
			nslavenets++;
			break;
		  case IGNORE:
			nignorednets++;
			break;
		}
		if (trace) {
			fprintf(fd, "\t%-16s", inet_ntoa(ntp->net));
D 13
			switch (ntp->status) {
E 13
I 13
			switch ((int)ntp->status) {
E 13
			  case MASTER:
				fprintf(fd, "MASTER\n");
				break;
			  case SLAVE:
				fprintf(fd, "SLAVE\n");
				break;
			  case IGNORE:
				fprintf(fd, "IGNORE\n");
				break;
			  default:
D 16
				fprintf(fd, "invalid state %d\n");
E 16
I 16
				fprintf(fd, "invalid state %d\n",(int)ntp->status);
E 16
				break;
			}
		}
		nnets++;
		status |= ntp->status;
	}
	status &= ~IGNORE;
	if (trace)
		fprintf(fd,
		      "\tnets = %d, masters = %d, slaves = %d, ignored = %d\n",
		      nnets, nmasternets, nslavenets, nignorednets);
}

makeslave(net)
	struct netinfo *net;
{
	register struct netinfo *ntp;

	for (ntp = nettab; ntp != NULL; ntp = ntp->next)
		if (ntp->status == SLAVE && ntp != net)
			ntp->status = IGNORE;
	slavenet = net;
}
	
struct netinfo *
firstslavenet()
{
	register struct netinfo *ntp;

	for (ntp = nettab; ntp != NULL; ntp = ntp->next)
		if (ntp->status == SLAVE)
			return (ntp);
	return ((struct netinfo *)0);
E 8
}

D 11
D 14
/* 
E 14
I 14
/*
E 14
E 11
I 11
/*
E 11
 * `casual' returns a random number in the range [inf, sup]
 */

D 5
long casual(inf, sup)
E 5
I 5
long
casual(inf, sup)
E 5
long inf;
long sup;
{
	float value;
D 13
	long random();
E 13

D 2
	value = (float)random();
	value /= MAXRANDOM;
	if (value < 0) 
		value = -value;
E 2
I 2
	value = (float)(random() & 0x7fffffff) / 0x7fffffff;
E 2
	return(inf + (sup - inf) * value);
}

D 2
char *date()
E 2
I 2
char *
date()
E 2
{
D 12
	char	*ret;
E 12
D 4
	char    *asctime();
E 4
I 4
	char    *ctime();
E 4
	struct	timeval tv;
D 4
	struct	tm *localtime();
	struct  tm *tp;
E 4

	(void)gettimeofday(&tv, (struct timezone *)0);
D 4
	tp = localtime((time_t *)&tv.tv_sec);
	ret = asctime(tp);
	ret[19] = '\0';
E 4
I 4
D 12
	ret = ctime(&tv.tv_sec);
E 4
	return(ret);
E 12
I 12
	return (ctime(&tv.tv_sec));
E 12
I 9
}

addnetname(name)
	char *name;
{
D 12
	struct nets **netlist = &nets;
E 12
I 12
	register struct nets **netlist = &nets;

E 12
	while (*netlist)
		netlist = &((*netlist)->next);
	*netlist = (struct nets *)malloc(sizeof **netlist);
	if (*netlist == (struct nets *)0) {
		syslog(LOG_ERR, "malloc failed");
		exit(1);
	}
D 13
	bzero(*netlist, sizeof(**netlist));
E 13
I 13
	bzero((char *)*netlist, sizeof(**netlist));
E 13
	(*netlist)->name = name;
E 9
}
E 1
