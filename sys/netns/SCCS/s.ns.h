h14871
s 00011/00006/00114
d D 7.4 88/06/29 17:13:17 bostic 17 16
c install approved copyright notice
e
s 00010/00004/00110
d D 7.3 88/01/20 15:15:10 sklower 16 15
c Change licensing/use notice.
e
s 00000/00015/00114
d D 7.2 87/01/16 12:58:50 karels 15 14
c share ntoh? definitions
e
s 00000/00000/00129
d D 7.1 86/06/05 00:36:16 mckusick 14 13
c 4.3BSD release version
e
s 00010/00007/00119
d D 6.12 86/06/02 14:48:09 karels 13 12
c lint
e
s 00005/00000/00121
d D 6.11 86/02/14 19:11:24 sklower 12 10
c add frequently used union to kernel header file
e
s 00005/00000/00121
d R 6.11 86/02/14 19:07:43 sklower 11 10
c enshrine common way of extracting net numbers by frequently used union.
e
s 00001/00001/00120
d D 6.10 86/02/04 19:17:55 sklower 10 9
c correct dumb typo in neteqnn
e
s 00009/00003/00112
d D 6.9 86/02/03 17:31:45 sklower 9 8
c remove ns_netof (non-portable), add zero and broadcast ns nets to compare to.
e
s 00001/00000/00114
d D 6.8 85/09/26 14:46:05 sklower 8 7
c add neteq to complement hosteq and clean things up
e
s 00001/00000/00113
d D 6.7 85/09/06 15:45:11 sklower 7 6
c add option to set MTU on stream connections
e
s 00001/00000/00112
d D 6.6 85/07/26 14:01:47 sklower 6 5
c add SO_ALL_PACKETS (disable spp and error processing on DG sockets)
e
s 00001/00000/00111
d D 6.5 85/07/19 18:34:44 sklower 5 4
c add sockopt for getting a sequence number from the kernel (for PEX).
e
s 00002/00002/00109
d D 6.4 85/06/21 20:34:12 sklower 4 3
c sockaddr_ns had too much zero padding at the end
e
s 00001/00001/00110
d D 6.3 85/06/19 09:11:56 sklower 3 2
c change NS_ALLOWBROADCAST to be SO_BROADCAST , fixing broadcasts.
e
s 00007/00001/00104
d D 6.2 85/06/08 12:49:40 mckusick 2 1
c Add copyright
e
s 00105/00000/00000
d D 6.1 85/05/30 19:10:51 sklower 1 0
c date and time created 85/05/30 19:10:51 by sklower
e
u
U
t
T
I 1
D 2
/*      %M%     %I%     %E%     */
E 2
I 2
/*
D 9
 * Copyright (c) 1982 Regents of the University of California.
E 9
I 9
D 16
 * Copyright (c) 1984, 1985, 1986 Regents of the University of California.
E 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 16
I 16
 * Copyright (c) 1984, 1985, 1986, 1987 Regents of the University of California.
 * All rights reserved.
E 16
 *
D 16
 *	%W% (Berkeley) %G%
E 16
I 16
 * Redistribution and use in source and binary forms are permitted
D 17
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 17
I 17
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
E 17
 *
D 17
 *      %W% (Berkeley) %G%
E 17
I 17
 *	%W% (Berkeley) %G%
E 17
E 16
 */
E 2

/*
 * Constants and Structures defined by the Xerox Network Software
 * per "Internet Transport Protocols", XSIS 028112, December 1981
 */

/*
 * Protocols
 */
#define NSPROTO_RI	1		/* Routing Information */
#define NSPROTO_ECHO	2		/* Echo Protocol */
#define NSPROTO_ERROR	3		/* Error Protocol */
#define NSPROTO_PE	4		/* Packet Exchange */
#define NSPROTO_SPP	5		/* Sequenced Packet */
#define NSPROTO_RAW	255		/* Placemarker*/
#define NSPROTO_MAX	256		/* Placemarker*/


/*
 * Port/Socket numbers: network standard functions
 */

#define NSPORT_RI	1		/* Routing Information */
#define NSPORT_ECHO	2		/* Echo */
#define NSPORT_RE	3		/* Router Error */

/*
 * Ports < NSPORT_RESERVED are reserved for priveleged
 * processes (e.g. root).
 */
#define NSPORT_RESERVED		3000

/* flags passed to ns_output as last parameter */

#define	NS_FORWARDING		0x1	/* most of idp header exists */
#define	NS_ROUTETOIF		0x10	/* same as SO_DONTROUTE */
D 3
#define	NS_ALLOWBROADCAST	SS_PRIV	/* can send broadcast packets */
E 3
I 3
#define	NS_ALLOWBROADCAST	SO_BROADCAST	/* can send broadcast packets */
E 3

#define NS_MAXHOPS		15

/* flags passed to get/set socket option */
#define	SO_HEADERS_ON_INPUT	1
#define	SO_HEADERS_ON_OUTPUT	2
#define	SO_DEFAULT_HEADERS	3
#define	SO_LAST_HEADER		4
#define	SO_NSIP_ROUTE		5
I 5
#define SO_SEQNO		6
I 6
#define	SO_ALL_PACKETS		7
I 7
#define SO_MTU			8
E 7
E 6
E 5


/*
 * NS addressing
 */
union ns_host {
	u_char	c_host[6];
	u_short	s_host[3];
};

union ns_net {
	u_char	c_net[4];
	u_short	s_net[2];
};

I 12
union ns_net_u {
	union ns_net	net_e;
	u_long		long_e;
};

E 12
struct ns_addr {
	union ns_net	x_net;
	union ns_host	x_host;
	u_short	x_port;
};

/*
 * Socket address, Xerox style
 */
struct sockaddr_ns {
D 4
	short		sns_family;
E 4
I 4
	u_short		sns_family;
E 4
	struct ns_addr	sns_addr;
D 4
	char		sns_zero[4];
E 4
I 4
	char		sns_zero[2];
E 4
};
#define sns_port sns_addr.x_port

D 9
#define ns_netof(a) (*(long *) & ((a).x_net))
I 8
#define ns_neteq(a,b) (ns_netof(a) == ns_netof(b))
E 9
I 9
#ifdef vax
#define ns_netof(a) (*(long *) & ((a).x_net)) /* XXX - not needed */
#endif
#define ns_neteqnn(a,b) (((a).s_net[0]==(b).s_net[0]) && \
D 10
					((a).s_net[0]==(b).s_net[0]))
E 10
I 10
					((a).s_net[1]==(b).s_net[1]))
E 10
#define ns_neteq(a,b) ns_neteqnn((a).x_net, (b).x_net)
E 9
E 8
#define satons_addr(sa)	(((struct sockaddr_ns *)&(sa))->sns_addr)
#define ns_hosteqnh(s,t) ((s).s_host[0] == (t).s_host[0] && \
	(s).s_host[1] == (t).s_host[1] && (s).s_host[2] == (t).s_host[2])
#define ns_hosteq(s,t) (ns_hosteqnh((s).x_host,(t).x_host))
#define ns_nullhost(x) (((x).x_host.s_host[0]==0) && \
	((x).x_host.s_host[1]==0) && ((x).x_host.s_host[2]==0))

D 13
#if !defined(vax)
#if !defined(INET)
E 13
I 13
D 15
#if !defined(vax) && !defined(ntohl) && !defined(lint)
E 13
/*
 * Macros for number representation conversion.
 */
#define	ntohl(x)	(x)
#define	ntohs(x)	(x)
#define	htonl(x)	(x)
#define	htons(x)	(x)
#endif
I 13

#if !defined(ntohl) && (defined(vax) || defined(lint))
u_short	ntohs(), htons();
u_long	ntohl(), htonl();
E 13
#endif

E 15
#ifdef KERNEL
extern struct domain nsdomain;
D 13
extern union ns_host ns_thishost;
extern union ns_host ns_zerohost;
extern union ns_host ns_broadhost;
I 9
extern union ns_net ns_zeronet;
extern union ns_net ns_broadnet;
E 13
I 13
union ns_host ns_thishost;
union ns_host ns_zerohost;
union ns_host ns_broadhost;
union ns_net ns_zeronet;
union ns_net ns_broadnet;
E 13
E 9
u_short ns_cksum();
#endif
E 1
