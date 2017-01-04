h45647
s 00010/00005/00460
d D 4.9 88/06/18 14:34:37 bostic 11 10
c install approved copyright notice
e
s 00019/00001/00446
d D 4.8 88/03/07 21:01:26 bostic 10 9
c add Berkeley specific header
e
s 00005/00002/00442
d D 4.7 87/09/16 17:35:54 bostic 9 8
c fix for big endians; bug report 4.3BSD/etc/30
e
s 00008/00002/00436
d D 4.6 86/10/30 21:32:03 karels 8 6
c print "to" address in case dest. multihomed
e
s 00008/00002/00436
d R 4.6 86/10/30 21:28:16 karels 7 6
c print "to" address in case multihomed
e
s 00017/00004/00421
d D 4.5 86/04/14 09:22:44 karels 6 5
c ICMP raw now passes back IP header
e
s 00003/00002/00422
d D 4.4 85/10/21 17:45:12 karels 5 4
c handle (rare) carry bug
e
s 00055/00088/00369
d D 4.3 85/08/06 19:31:37 karels 4 2
c miscellaneous cleanups; changes from Muus
e
s 00052/00088/00369
d R 4.3 85/08/06 19:29:15 karels 3 2
c cleanups and mods from Muus
e
s 00088/00040/00369
d D 4.2 85/04/29 13:31:25 karels 2 1
c local mods
e
s 00409/00000/00000
d D 4.1 85/04/29 12:20:39 karels 1 0
c from Mike Muus
e
u
U
t
T
I 10
/*
 * Copyright (c) 1987 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 11
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 11
I 11
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
E 11
 */

E 10
I 2
#ifndef lint
I 10
char copyright[] =
"%Z% Copyright (c) 1987 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
E 10
static char sccsid[] = "%W% (Berkeley) %G%";
D 10
#endif
E 10
I 10
#endif /* not lint */
E 10

E 2
I 1
/*
 *			P I N G . C
 *
 * Using the InterNet Control Message Protocol (ICMP) "ECHO" facility,
 * measure round-trip-delays and packet loss across network paths.
 *
 * Author -
 *	Mike Muuss
 *	U. S. Army Ballistic Research Laboratory
 *	December, 1983
I 2
 * Modified at Uc Berkeley
E 2
 *
D 2
 * Target System -
 *	4.2 BSD with MIT and BRL fixes to /sys/netinet/ip_icmp.c et.al.
 *
E 2
 * Status -
 *	Public Domain.  Distribution Unlimited.
 *
 * Bugs -
D 2
 *	Divide by zero if no packets return.
E 2
 *	More statistics could always be gathered.
 *	This program has to run SUID to ROOT to access the ICMP socket.
 */

#include <stdio.h>
#include <errno.h>
#include <sys/time.h>

#include <sys/param.h>
#include <sys/socket.h>
#include <sys/file.h>

#include <netinet/in_systm.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>

I 2
#define	MAXWAIT		10	/* max time to wait for response, sec. */
E 2
D 4
char	ttyobuf[4096];
E 4
I 4
#define	MAXPACKET	4096	/* max packet size */
#ifndef MAXHOSTNAMELEN
#define MAXHOSTNAMELEN	64
#endif
E 4

I 2
int	verbose;
E 2
D 4
u_char	packet[1024];
E 4
I 4
u_char	packet[MAXPACKET];
E 4
int	options;
extern	int errno;

int s;			/* Socket file descriptor */
struct hostent *hp;	/* Pointer to host info */
struct timezone tz;	/* leftover */

struct sockaddr whereto;/* Who to ping */
int datalen;		/* How much data */

D 2
char usage[] = "Usage:  ping [-d] host [data size]\n";
E 2
I 2
D 4
char usage[] = "Usage:  ping [-drv] host [data size]\n";
E 4
I 4
char usage[] = "Usage:  ping [-drv] host [data size] [npackets]\n";
E 4
E 2

char *hostname;
D 4
char hnamebuf[64];
E 4
I 4
char hnamebuf[MAXHOSTNAMELEN];
I 8
char *inet_ntoa();
E 8
E 4

D 2
int ntransmitted = 1;		/* sequence # for outbound packets = #sent */
E 2
I 2
int npackets;
int ntransmitted = 0;		/* sequence # for outbound packets = #sent */
E 2
int ident;

int nreceived = 0;		/* # of packets we got back */
I 2
int timing = 0;
E 2
int tmin = 999999999;
int tmax = 0;
int tsum = 0;			/* sum of all times, for doing average */
D 2
int finish();
E 2
I 2
int finish(), catcher();
E 2

/*
 * 			M A I N
 */
main(argc, argv)
char *argv[];
{
	struct sockaddr_in from;
	char **av = argv;
I 8
	char *toaddr = NULL;
E 8
	struct sockaddr_in *to = (struct sockaddr_in *) &whereto;
I 2
	int on = 1;
I 4
	struct protoent *proto;
E 4
E 2

D 2
	if (argc > 0 && !strcmp(argv[0], "-d"))  {
		options |= SO_DEBUG;
E 2
I 2
	argc--, av++;
	while (argc > 0 && *av[0] == '-') {
		while (*++av[0]) switch (*av[0]) {
			case 'd':
				options |= SO_DEBUG;
				break;
			case 'r':
				options |= SO_DONTROUTE;
				break;
			case 'v':
				verbose++;
				break;
		}
E 2
		argc--, av++;
	}
D 2
	
	if( argc < 2 || argc > 3 )  {
E 2
I 2
	if( argc < 1)  {
E 2
		printf(usage);
		exit(1);
	}

	bzero( (char *)&whereto, sizeof(struct sockaddr) );
D 2
	hp = gethostbyname(av[1]);
E 2
I 2
D 4
	hp = gethostbyname(av[0]);
E 2
	if (hp) {
		to->sin_family = hp->h_addrtype;
		bcopy(hp->h_addr, (caddr_t)&to->sin_addr, hp->h_length);
		hostname = hp->h_name;
E 4
I 4
	to->sin_family = AF_INET;
	to->sin_addr.s_addr = inet_addr(av[0]);
	if (to->sin_addr.s_addr != -1) {
		strcpy(hnamebuf, av[0]);
		hostname = hnamebuf;
E 4
	} else {
D 4
		to->sin_family = AF_INET;
		to->sin_addr.s_addr = inet_addr(av[1]);
		if (to->sin_addr.s_addr == -1) {
			printf("%s: unknown host %s\n", argv[0], av[1]);
			return;
E 4
I 4
		hp = gethostbyname(av[0]);
		if (hp) {
			to->sin_family = hp->h_addrtype;
			bcopy(hp->h_addr, (caddr_t)&to->sin_addr, hp->h_length);
			hostname = hp->h_name;
I 8
			toaddr = inet_ntoa(to->sin_addr.s_addr);
E 8
		} else {
			printf("%s: unknown host %s\n", argv[0], av[0]);
			exit(1);
E 4
		}
D 2
		strcpy(hnamebuf, argv[1]);
E 2
I 2
D 4
		strcpy(hnamebuf, av[1]);
E 2
		hostname = hnamebuf;
E 4
	}

D 2
	if( argc == 3 )
		datalen = atoi( argv[2] );
E 2
I 2
	if( argc >= 2 )
		datalen = atoi( av[1] );
E 2
	else
		datalen = 64-8;
I 4
	if (datalen > MAXPACKET) {
		fprintf(stderr, "ping: packet size too large\n");
		exit(1);
	}
E 4
I 2
	if (datalen >= sizeof(struct timeval))
		timing = 1;
	if (argc > 2)
		npackets = atoi(av[2]);
E 2

	ident = getpid() & 0xFFFF;

D 2
	while ((s = socket(AF_INET, SOCK_RAW, 0, 0)) < 0) {
E 2
I 2
D 4
	if ((s = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
E 4
I 4
	if ((proto = getprotobyname("icmp")) == NULL) {
		fprintf(stderr, "icmp: unknown protocol\n");
		exit(10);
	}
	if ((s = socket(AF_INET, SOCK_RAW, proto->p_proto)) < 0) {
E 4
E 2
		perror("ping: socket");
D 2
		sleep(5);
E 2
I 2
		exit(5);
E 2
	}
I 2
	if (options & SO_DEBUG)
		setsockopt(s, SOL_SOCKET, SO_DEBUG, &on, sizeof(on));
	if (options & SO_DONTROUTE)
		setsockopt(s, SOL_SOCKET, SO_DONTROUTE, &on, sizeof(on));
E 2

D 8
	printf("PING %s: %d data bytes\n", hostname, datalen );
E 8
I 8
	printf("PING %s", hostname);
	if (toaddr)
		printf(" (%s)", toaddr);
	printf(": %d data bytes\n", datalen);
				
E 8

D 4
	setbuffer( stdout, ttyobuf, sizeof(ttyobuf) );
E 4
I 4
	setlinebuf( stdout );
E 4

	signal( SIGINT, finish );
I 2
	signal(SIGALRM, catcher);
E 2

	catcher();	/* start things going */

	for (;;) {
		int len = sizeof (packet);
		int fromlen = sizeof (from);
		int cc;

D 2
		/* cc = recvfrom(s, buf, len, flags, from, fromlen) */
		if ( (cc=recvfrom(s, packet, len, 0, &from, fromlen)) < 0) {
E 2
I 2
		if ( (cc=recvfrom(s, packet, len, 0, &from, &fromlen)) < 0) {
E 2
			if( errno == EINTR )
				continue;
			perror("ping: recvfrom");
			continue;
		}
		pr_pack( packet, cc, &from );
I 2
		if (npackets && nreceived >= npackets)
			finish();
E 2
	}
	/*NOTREACHED*/
}

/*
 * 			C A T C H E R
 * 
 * This routine causes another PING to be transmitted, and then
 * schedules another SIGALRM for 1 second from now.
 * 
 * Bug -
 * 	Our sense of time will slowly skew (ie, packets will not be launched
 * 	exactly at 1-second intervals).  This does not affect the quality
 *	of the delay and loss statistics.
 */
catcher()
{
D 2
	signal( SIGALRM, catcher );
E 2
I 2
	int waittime;

E 2
	pinger();
D 2
	alarm(1);
E 2
I 2
	if (npackets == 0 || ntransmitted < npackets)
		alarm(1);
	else {
		if (nreceived) {
			waittime = 2 * tmax / 1000;
			if (waittime == 0)
				waittime = 1;
		} else
			waittime = MAXWAIT;
		signal(SIGALRM, finish);
		alarm(waittime);
	}
E 2
}

/*
 * 			P I N G E R
 * 
 * Compose and transmit an ICMP ECHO REQUEST packet.  The IP packet
 * will be added on by the kernel.  The ID field is our UNIX process ID,
 * and the sequence number is an ascending integer.  The first 8 bytes
 * of the data portion are used to hold a UNIX "timeval" struct in VAX
 * byte-order, to compute the round-trip time.
 */
pinger()
{
D 4
	static u_char outpack[1024];
E 4
I 4
	static u_char outpack[MAXPACKET];
E 4
	register struct icmp *icp = (struct icmp *) outpack;
	int i, cc;
	register struct timeval *tp = (struct timeval *) &outpack[8];
	register u_char *datap = &outpack[8+sizeof(struct timeval)];

	icp->icmp_type = ICMP_ECHO;
	icp->icmp_code = 0;
	icp->icmp_cksum = 0;
	icp->icmp_seq = ntransmitted++;
	icp->icmp_id = ident;		/* ID */

	cc = datalen+8;			/* skips ICMP portion */

D 2
	gettimeofday( tp, &tz );
E 2
I 2
	if (timing)
		gettimeofday( tp, &tz );
E 2

	for( i=8; i<datalen; i++)	/* skip 8 for time */
		*datap++ = i;

	/* Compute ICMP checksum here */
	icp->icmp_cksum = in_cksum( icp, cc );

	/* cc = sendto(s, msg, len, flags, to, tolen) */
	i = sendto( s, outpack, cc, 0, &whereto, sizeof(struct sockaddr) );

	if( i < 0 || i != cc )  {
		if( i<0 )  perror("sendto");
		printf("ping: wrote %s %d chars, ret=%d\n",
			hostname, cc, i );
		fflush(stdout);
	}
}

/*
 * 			P R _ T Y P E
 *
 * Convert an ICMP "type" field to a printable string.
 */
char *
pr_type( t )
register int t;
{
	static char *ttab[] = {
		"Echo Reply",
		"ICMP 1",
		"ICMP 2",
		"Dest Unreachable",
		"Source Quence",
		"Redirect",
		"ICMP 6",
		"ICMP 7",
		"Echo",
		"ICMP 9",
		"ICMP 10",
		"Time Exceeded",
		"Parameter Problem",
		"Timestamp",
		"Timestamp Reply",
		"Info Request",
		"Info Reply"
	};

	if( t < 0 || t > 16 )
		return("OUT-OF-RANGE");

	return(ttab[t]);
}

/*
 *			P R _ P A C K
 *
 * Print out the packet, if it came from us.  This logic is necessary
 * because ALL readers of the ICMP socket get a copy of ALL ICMP packets
 * which arrive ('tis only fair).  This permits multiple copies of this
 * program to be run without having intermingled output (or statistics!).
 */
D 6
pr_pack( icp, cc, from )
register struct icmp *icp;
E 6
I 6
pr_pack( buf, cc, from )
char *buf;
E 6
int cc;
struct sockaddr_in *from;
{
I 6
	struct ip *ip;
	register struct icmp *icp;
E 6
	register long *lp = (long *) packet;
	register int i;
	struct timeval tv;
D 6
	struct timeval *tp = (struct timeval *) &packet[8];
	int triptime;
E 6
I 6
	struct timeval *tp;
	int hlen, triptime;
E 6
I 4
D 8
	char *inet_ntoa();
E 8
E 4

	from->sin_addr.s_addr = ntohl( from->sin_addr.s_addr );
	gettimeofday( &tv, &tz );

I 6
	ip = (struct ip *) buf;
	hlen = ip->ip_hl << 2;
	if (cc < hlen + ICMP_MINLEN) {
		if (verbose)
			printf("packet too short (%d bytes) from %s\n", cc,
				inet_ntoa(ntohl(from->sin_addr.s_addr)));
		return;
	}
	cc -= hlen;
	icp = (struct icmp *)(buf + hlen);
E 6
	if( icp->icmp_type != ICMP_ECHOREPLY )  {
D 2
		printf("%d bytes from x%x: ", cc, from->sin_addr.s_addr);
		printf("icmp_type=%d (%s)\n",
			icp->icmp_type, pr_type(icp->icmp_type) );
		for( i=0; i<12; i++)
E 2
I 2
		if (verbose) {
D 4
			printf("%d bytes from x%x: ", cc, from->sin_addr.s_addr);
E 4
I 4
			printf("%d bytes from %s: ", cc,
				inet_ntoa(ntohl(from->sin_addr.s_addr)));
E 4
			printf("icmp_type=%d (%s)\n",
				icp->icmp_type, pr_type(icp->icmp_type) );
			for( i=0; i<12; i++)
E 2
D 4
			printf("x%2.2x: x%8.8x\n", i*sizeof(long), *lp++ );
E 4
I 4
			    printf("x%2.2x: x%8.8x\n", i*sizeof(long), *lp++ );
E 4
D 2
		printf("icmp_code=%d\n", icp->icmp_code );
E 2
I 2
			printf("icmp_code=%d\n", icp->icmp_code );
D 4
			fflush(stdout);
E 4
		}
		return;
E 2
	}
	if( icp->icmp_id != ident )
		return;			/* 'Twas not our ECHO */

I 6
	tp = (struct timeval *)&icp->icmp_data[0];
E 6
D 4
	printf("%d bytes from x%x: ", cc, from->sin_addr.s_addr);
E 4
I 4
	printf("%d bytes from %s: ", cc,
		inet_ntoa(ntohl(from->sin_addr.s_addr)));
E 4
	printf("icmp_seq=%d. ", icp->icmp_seq );
D 2
	tvsub( &tv, tp );
	triptime = tv.tv_sec*1000+(tv.tv_usec/1000);
	printf("time=%d. ms\n", triptime );
E 2
I 2
	if (timing) {
		tvsub( &tv, tp );
		triptime = tv.tv_sec*1000+(tv.tv_usec/1000);
		printf("time=%d. ms\n", triptime );
		tsum += triptime;
		if( triptime < tmin )
			tmin = triptime;
		if( triptime > tmax )
			tmax = triptime;
	} else
		putchar('\n');
E 2
	nreceived++;
D 2
	tsum += triptime;
	if( triptime < tmin )
		tmin = triptime;
	if( triptime > tmax )
		tmax = triptime;
E 2
D 4
	fflush(stdout);
E 4
}


/*
 *			I N _ C K S U M
 *
D 4
 * Checksum routine for Internet Protocol family headers (VAX Version).
E 4
I 4
 * Checksum routine for Internet Protocol family headers (C Version)
E 4
 *
D 4
 * Shamelessly pilfered from /sys/vax/in_cksum.c, with all the MBUF stuff
 * ripped out.
E 4
 */
I 2
D 4
#if vax
E 4
E 2
in_cksum(addr, len)
u_short *addr;
int len;
{
D 4
	register int nleft = len;	/* on vax, (user mode), r11 */
	register int xxx;		/* on vax, (user mode), r10 */
	register u_short *w = addr;	/* on vax, known to be r9 */
	register int sum = 0;		/* on vax, known to be r8 */
E 4
I 4
	register int nleft = len;
	register u_short *w = addr;
	register u_short answer;
	register int sum = 0;
I 9
	u_short odd_byte = 0;
E 9
E 4

D 4

E 4
	/*
D 4
	 * Force to long boundary so we do longword aligned
	 * memory operations.  It is too hard to do byte
	 * adjustment, do only word adjustment.
E 4
I 4
	 *  Our algorithm is simple, using a 32 bit accumulator (sum),
	 *  we add sequential 16 bit words to it, and at the end, fold
	 *  back all the carry bits from the top 16 bits into the lower
	 *  16 bits.
E 4
	 */
D 4
	if (((int)w&0x2) && nleft >= 2) {
E 4
I 4
	while( nleft > 1 )  {
E 4
		sum += *w++;
		nleft -= 2;
	}
D 4
	/*
	 * Do as much of the checksum as possible 32 bits at at time.
	 * In fact, this loop is unrolled to make overhead from
	 * branches &c small.
	 *
	 * We can do a 16 bit ones complement sum 32 bits at a time
	 * because the 32 bit register is acting as two 16 bit
	 * registers for adding, with carries from the low added
	 * into the high (by normal carry-chaining) and carries
	 * from the high carried into the low on the next word
	 * by use of the adwc instruction.  This lets us run
	 * this loop at almost memory speed.
	 *
	 * Here there is the danger of high order carry out, and
	 * we carefully use adwc.
	 */
	while ((nleft -= 32) >= 0) {
#undef ADD
		asm("clrl r0");		/* clears carry */
#define ADD		asm("adwc (r9)+,r8;");
		ADD; ADD; ADD; ADD; ADD; ADD; ADD; ADD;
		asm("adwc $0,r8");
	}
	nleft += 32;
	while ((nleft -= 8) >= 0) {
		asm("clrl r0");
		ADD; ADD;
		asm("adwc $0,r8");
	}
	nleft += 8;
	/*
	 * Now eliminate the possibility of carry-out's by
	 * folding back to a 16 bit number (adding high and
	 * low parts together.)  Then mop up trailing words
	 * and maybe an odd byte.
	 */
	{ asm("ashl $-16,r8,r0; addw2 r0,r8");
	  asm("adwc $0,r8; movzwl r8,r8"); }
	while ((nleft -= 2) >= 0) {
		asm("movzwl (r9)+,r0; addl2 r0,r8");
	}
	if (nleft == -1) {
E 4
I 4

	/* mop up an odd byte, if necessary */
D 9
	if( nleft == 1 )
E 4
		sum += *(u_char *)w;
E 9
I 9
	if( nleft == 1 ) {
		*(u_char *)(&odd_byte) = *(u_char *)w;
		sum += odd_byte;
	}
E 9
D 4
	}
E 4

	/*
D 4
	 * Add together high and low parts of sum
	 * and carry to get cksum.
	 * Have to be careful to not drop the last
	 * carry here.
E 4
I 4
	 * add back carry outs from top 16 bits to low 16 bits
E 4
	 */
D 4
	{ asm("ashl $-16,r8,r0; addw2 r0,r8; adwc $0,r8");
	  asm("mcoml r8,r8; movzwl r8,r8"); }
	return (sum);
E 4
I 4
D 5
	sum += (sum >> 16);	/* add hi 16 to low 16 */
	answer = ~sum;		/* truncate to 16 bits */
E 5
I 5
	sum = (sum >> 16) + (sum & 0xffff);	/* add hi 16 to low 16 */
	sum += (sum >> 16);			/* add carry */
	answer = ~sum;				/* truncate to 16 bits */
E 5
	return (answer);
E 4
}
I 2
D 4
#endif vax
E 4
E 2

/*
 * 			T V S U B
 * 
 * Subtract 2 timeval structs:  out = out - in.
 * 
 * Out is assumed to be >= in.
 */
tvsub( out, in )
register struct timeval *out, *in;
{
	if( (out->tv_usec -= in->tv_usec) < 0 )   {
		out->tv_sec--;
		out->tv_usec += 1000000;
	}
	out->tv_sec -= in->tv_sec;
}

/*
 *			F I N I S H
 *
 * Print out statistics, and give up.
 * Heavily buffered STDIO is used here, so that all the statistics
 * will be written with 1 sys-write call.  This is nice when more
 * than one copy of the program is running on a terminal;  it prevents
 * the statistics output from becomming intermingled.
 */
finish()
{
D 2
	ntransmitted--;		/* we will never hear the last one */

E 2
	printf("\n----%s PING Statistics----\n", hostname );
	printf("%d packets transmitted, ", ntransmitted );
	printf("%d packets received, ", nreceived );
D 2
	printf("%d%% packet loss\n",
E 2
I 2
	if (ntransmitted)
	    printf("%d%% packet loss",
E 2
		(int) (((ntransmitted-nreceived)*100) / ntransmitted ) );
D 2
	printf("round-trip (ms)  min/avg/max = %d/%d/%d\n",
E 2
I 2
	printf("\n");
	if (nreceived && timing)
	    printf("round-trip (ms)  min/avg/max = %d/%d/%d\n",
E 2
		tmin,
		tsum / nreceived,
		tmax );
	fflush(stdout);
	exit(0);
}
D 2

E 2
E 1
