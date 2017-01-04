h58395
s 00010/00005/00367
d D 2.5 88/06/18 14:08:09 bostic 7 6
c install approved copyright notice
e
s 00009/00003/00363
d D 2.4 87/12/23 14:30:03 bostic 6 5
c append Berkeley header; NASA wants a copy
e
s 00001/00001/00365
d D 2.3 86/11/18 20:13:45 bostic 5 4
c bug report 4.3BSD/etc/15
e
s 00003/00003/00363
d D 2.2 86/04/21 15:42:14 bloom 4 3
c delete arg from measure(), change timeout for measure()
e
s 00011/00009/00355
d D 2.1 85/12/10 13:06:32 bloom 3 2
c Multi network support
e
s 00001/00022/00363
d D 1.2 85/09/18 10:15:27 bloom 2 1
c wrong way to determine if timed is running, use MAXHOSTNAMELEN constant, 
c move other constants to header file
e
s 00385/00000/00000
d D 1.1 85/06/27 13:18:18 gusella 1 0
c date and time created 85/06/27 13:18:18 by gusella
e
u
U
t
T
I 1
/*
 * Copyright (c) 1983 Regents of the University of California.
D 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
E 6
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 6
#endif not lint
E 6
I 6
#endif /* not lint */
E 6

#include "timedc.h"
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#define TSPTYPES
#include <protocols/timed.h>
#include <sys/file.h>

D 2
#define OFF	0
#define ON	1

E 2
int id;
int sock;
int sock_raw;
D 2
char hostname[32];
E 2
I 2
char hostname[MAXHOSTNAMELEN];
E 2
struct hostent *hp, *gethostbyname();
struct sockaddr_in server;
extern int measure_delta;
int bytenetorder(), bytehostorder();
char *strcpy();

/*
 * Clockdiff computes the difference between the time of the machine on 
 * which it is called and the time of the machines given as argument.
 * The time differences measured by clockdiff are obtained using a sequence
 * of ICMP TSTAMP messages which are returned to the sender by the IP module
 * in the remote machine.
 * In order to compare clocks of machines in different time zones, the time 
 * is transmitted (as a 32-bit value) in milliseconds since midnight UT. 
 * If a hosts uses a different time format, it should set the high order
 * bit of the 32-bit quantity it transmits.
 * However, VMS apparently transmits the time in milliseconds since midnight
 * local time (rather than GMT) without setting the high order bit. 
 * Furthermore, it does not understand daylight-saving time.  This makes 
 * clockdiff behaving inconsistently with hosts running VMS.
 *
 * In order to reduce the sensitivity to the variance of message transmission 
 * time, clockdiff sends a sequence of messages.  Yet, measures between 
 * two `distant' hosts can be affected by a small error. The error can, however,
 * be reduced by increasing the number of messages sent in each measurement.
 */

clockdiff(argc, argv)
int argc;
char *argv[];
{
	int measure_status;
	struct timeval ack;
	int measure();

	if(argc < 2)  {
		printf("Usage: clockdiff host ... \n");
		return;
	}

	id = getpid();
	(void)gethostname(hostname,sizeof(hostname));

	while (argc > 1) {
		argc--; argv++;
		hp = gethostbyname(*argv);
		if (hp == NULL) {
			printf("%s: unknown host\n", *argv);
			continue;
		}
		server.sin_family = hp->h_addrtype;
		bcopy(hp->h_addr, &(server.sin_addr.s_addr), hp->h_length); 
D 4
		ack.tv_sec = 1;
		ack.tv_usec = 500000;
D 3
		if ((measure_status = measure(&ack, OFF)) < 0) {
E 3
I 3
		if ((measure_status = measure(&ack, &server, OFF)) < 0) {
E 4
I 4
		ack.tv_sec = 10;
		ack.tv_usec = 0;
		if ((measure_status = measure(&ack, &server)) < 0) {
E 4
E 3
			perror("measure");
			return;
		}
		switch (measure_status) {

		case HOSTDOWN:
			printf("%s is down\n", hp->h_name);
			continue;
			break;
		case NONSTDTIME:
			printf("%s time transmitted in a non-standard format\n",						 hp->h_name);
			continue;
			break;
		case UNREACHABLE:
			printf("%s is unreachable\n", hp->h_name);
			continue;
			break;
		default:
			break;
		}

		if (measure_delta > 0)
			printf("time on %s is %d ms. ahead of time on %s\n", 
						hp->h_name, measure_delta,
						hostname);
		else
			if (measure_delta == 0)
		      		printf("%s and %s have the same time\n", 
						hp->h_name, hostname);
			else
		      	     printf("time on %s is %d ms. behind time on %s\n",
					hp->h_name, -measure_delta, hostname);
	}
	return;
}
/*
 * finds location of master timedaemon
 */

msite(argc)
int argc;
{
	int length;
D 3
	int cc, ready, found;
E 3
I 3
	int cc;
	fd_set ready;
E 3
	struct sockaddr_in dest;
	struct timeval tout;
	struct sockaddr_in from;
	struct tsp msg;
	struct servent *srvp;

	if (argc != 1) {
		printf("Usage: msite\n");
		return;
	}

D 2
	(void) open("/etc/timed", O_WRONLY, 01700);
	if (errno != ETXTBSY) {
		printf("No timed on this machine\n");
		return;
	}

E 2
	srvp = getservbyname("timed", "udp");
	if (srvp == 0) {
		fprintf(stderr, "udp/timed: unknown service\n");
		return;
	}	
	dest.sin_port = srvp->s_port;
	dest.sin_family = AF_INET;

	(void)gethostname(hostname,sizeof(hostname));
	hp = gethostbyname(hostname);
	if (hp == NULL) {
		perror("gethostbyname");
		return;
	}
	bcopy(hp->h_addr, &dest.sin_addr.s_addr, hp->h_length);

	(void)strcpy(msg.tsp_name, hostname);
	msg.tsp_type = TSP_MSITE;
	msg.tsp_vers = TSPVERSION;
	bytenetorder(&msg);
	length = sizeof(struct sockaddr_in);
	if (sendto(sock, (char *)&msg, sizeof(struct tsp), 0, 
						&dest, length) < 0) {
		perror("sendto");
		return;
	}

	tout.tv_sec = 15;
	tout.tv_usec = 0;
D 3
	ready = 1<<sock;
	found = select(20, &ready, (int *)0, (int *)0, &tout);
	if (found) {
E 3
I 3
	FD_ZERO(&ready);
	FD_SET(sock, &ready);
	if (select(FD_SETSIZE, &ready, (fd_set *)0, (fd_set *)0, &tout)) {
E 3
		length = sizeof(struct sockaddr_in);
		cc = recvfrom(sock, (char *)&msg, sizeof(struct tsp), 0, 
							&from, &length);
		if (cc < 0) {
			perror("recvfrom");
			return;
		}
		bytehostorder(&msg);
		if (msg.tsp_type == TSP_ACK)
			printf("master timedaemon runs on %s\n", msg.tsp_name);
		else
			printf("received wrong ack: %s\n", 
						tsptype[msg.tsp_type]);
	} else
		printf("communication error\n");
}

/*
 * quits timedc
 */

quit()
{
	exit(0);
}

#define MAXH	4	/* max no. of hosts where election can occur */

/*
 * Causes the election timer to expire on the selected hosts
 * It sends just one udp message per machine, relying on
 * reliability of communication channel.
 */

testing(argc, argv)
int argc;
char *argv[];
{
	int length;
	int nhosts;
	struct servent *srvp;
	struct sockaddr_in sin[MAXH];
	struct tsp msg;

	if(argc < 2)  {
		printf("Usage: testing host ...\n");
		return;
	}

D 2
	(void) open("/etc/timed", O_WRONLY, 01700);
	if (errno != ETXTBSY) {
		printf("No timed on this machine\n");
		return;
	}

E 2
	srvp = getservbyname("timed", "udp");
	if (srvp == 0) {
		fprintf(stderr, "udp/timed: unknown service\n");
		return;
	}	

	nhosts = 0;
	while (argc > 1) {
		argc--; argv++;
		hp = gethostbyname(*argv);
		if (hp == NULL) {
D 5
			printf("%s: unknown host %s\n", *argv);
E 5
I 5
			printf("%s: unknown host\n", *argv);
E 5
			argc--; argv++;
			continue;
		}
		sin[nhosts].sin_port = srvp->s_port;
		sin[nhosts].sin_family = hp->h_addrtype;
		bcopy(hp->h_addr, &(sin[nhosts].sin_addr.s_addr), hp->h_length);
		if (++nhosts == MAXH)
			break;
	}

	msg.tsp_type = TSP_TEST;
	msg.tsp_vers = TSPVERSION;
	(void)gethostname(hostname, sizeof(hostname));
	(void)strcpy(msg.tsp_name, hostname);
	bytenetorder(&msg);	/* it is not really necessary here */
	while (nhosts-- > 0) {
		length = sizeof(struct sockaddr_in);
		if (sendto(sock, (char *)&msg, sizeof(struct tsp), 0, 
						&sin[nhosts], length) < 0) {
			perror("sendto");
			return;
		}
	}
}

/*
 * Enables or disables tracing on local timedaemon
 */

tracing(argc, argv)
int argc;
char *argv[];
{
	int onflag;
	int length;
D 3
	int cc, ready, found;
E 3
I 3
	int cc;
	fd_set ready;
E 3
	struct sockaddr_in dest;
	struct timeval tout;
	struct sockaddr_in from;
	struct tsp msg;
	struct servent *srvp;

	if (argc != 2) {
		printf("Usage: tracing { on | off }\n");
D 2
		return;
	}

	(void) open("/etc/timed", O_WRONLY, 01700);
	if (errno != ETXTBSY) {
		printf("No timed on this machine\n");
E 2
		return;
	}

	srvp = getservbyname("timed", "udp");
	if (srvp == 0) {
		fprintf(stderr, "udp/timed: unknown service\n");
		return;
	}	
	dest.sin_port = srvp->s_port;
	dest.sin_family = AF_INET;

	(void)gethostname(hostname,sizeof(hostname));
	hp = gethostbyname(hostname);
	bcopy(hp->h_addr, &dest.sin_addr.s_addr, hp->h_length);

	if (strcmp(argv[1], "on") == 0) {
		msg.tsp_type = TSP_TRACEON;
		onflag = ON;
	} else {
		msg.tsp_type = TSP_TRACEOFF;
		onflag = OFF;
	}

	(void)strcpy(msg.tsp_name, hostname);
	msg.tsp_vers = TSPVERSION;
	bytenetorder(&msg);
	length = sizeof(struct sockaddr_in);
	if (sendto(sock, (char *)&msg, sizeof(struct tsp), 0, 
						&dest, length) < 0) {
		perror("sendto");
		return;
	}

	tout.tv_sec = 5;
	tout.tv_usec = 0;
D 3
	ready = 1<<sock;
	found = select(20, &ready, (int *)0, (int *)0, &tout);
	if (found) {
E 3
I 3
	FD_ZERO(&ready);
	FD_SET(sock, &ready);
	if (select(FD_SETSIZE, &ready, (fd_set *)0, (fd_set *)0, &tout)) {
E 3
		length = sizeof(struct sockaddr_in);
		cc = recvfrom(sock, (char *)&msg, sizeof(struct tsp), 0, 
							&from, &length);
		if (cc < 0) {
			perror("recvfrom");
			return;
		}
		bytehostorder(&msg);
		if (msg.tsp_type == TSP_ACK)
			if (onflag)
				printf("timed tracing enabled\n");
			else
				printf("timed tracing disabled\n");
		else
			printf("wrong ack received: %s\n", 
						tsptype[msg.tsp_type]);
	} else
		printf("communication error\n");
}

priv_resources()
{
	int port;
	struct sockaddr_in sin;

	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0) {
		perror("opening socket");
		return(-1);
	}

	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = 0;
	for (port = IPPORT_RESERVED - 1; port > IPPORT_RESERVED / 2; port--) {
		sin.sin_port = htons((u_short)port);
		if (bind(sock, (struct sockaddr *)&sin, sizeof (sin)) >= 0)
			break;
		if (errno != EADDRINUSE && errno != EADDRNOTAVAIL) {
			perror("bind");
			(void) close(sock);
			return(-1);
		}
	}
	if (port == IPPORT_RESERVED / 2) {
		fprintf(stderr, "all reserved ports in use\n");
		(void) close(sock);
		return(-1);
	}

	sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP); 
	if (sock_raw < 0)  {
		perror("opening raw socket");
		(void) close(sock_raw);
		return(-1);
	}
	return(1);
}
E 1
