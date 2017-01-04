h02538
s 00001/00000/00229
d D 7.6 02/08/02 22:10:37 msokolov 39 38
c add declaration for ifunit(), it's useful to others
e
s 00001/00000/00228
d D 7.5 02/07/12 19:46:07 msokolov 38 37
c add IFF_NOFCS flag (no frame check sequence at the end)
e
s 00003/00000/00225
d D 7.4 02/07/08 00:04:59 msokolov 37 36
c add variable MTU support
e
s 00010/00005/00215
d D 7.3 88/06/27 18:59:29 bostic 36 35
c install approved copyright notice
e
s 00008/00002/00212
d D 7.2 87/12/30 11:57:25 bostic 35 34
c add Berkeley header
e
s 00001/00001/00213
d D 7.1 86/06/04 23:39:30 mckusick 34 33
c 4.3BSD release version
e
s 00001/00004/00213
d D 6.14 86/06/02 14:27:12 karels 33 32
c rm unused (for lint)
e
s 00003/00000/00214
d D 6.13 86/05/14 16:36:13 karels 32 31
c reserved values
e
s 00001/00000/00213
d D 6.12 86/04/19 23:08:55 karels 31 30
c add ifa_ifwithdstaddr declaration
e
s 00005/00002/00208
d D 6.11 86/02/06 14:18:27 karels 30 29
c add LOOPBACK flag, interface metric
e
s 00005/00016/00205
d D 6.10 86/01/24 18:29:49 karels 29 28
c move arp stuff to if_arp.h
e
s 00001/00001/00220
d D 6.9 85/12/19 16:20:17 karels 28 27
c rm bbnnet
e
s 00027/00001/00194
d D 6.8 85/09/16 21:08:56 karels 27 26
c prepend ifp to input packets, providing interface to extract
c or delete when dequeueing; INET || BBNNET
e
s 00007/00001/00188
d D 6.7 85/06/08 12:26:20 mckusick 26 25
c Add copyright
e
s 00023/00016/00166
d D 6.6 85/03/19 16:00:22 karels 25 24
c move net addresses from interface layer into protocols,
c supply generic ifaddr struct
e
s 00002/00000/00180
d D 6.5 84/04/13 10:34:36 karels 24 23
c add ioctl to determine if broadcast address (for subnets)
e
s 00001/00000/00179
d D 6.4 84/04/06 16:58:54 karels 23 22
c add IFF_LOCAL
e
s 00014/00000/00165
d D 6.3 84/03/20 15:23:19 karels 22 21
c new ARP
e
s 00001/00000/00164
d D 6.2 83/08/28 00:00:12 sam 21 20
c add bit for disabling ARP
e
s 00000/00000/00164
d D 6.1 83/07/29 07:08:37 sam 20 19
c 4.2 distribution
e
s 00001/00000/00163
d D 4.19 83/06/12 23:09:32 sam 19 18
c more parts to the ioctls
e
s 00010/00004/00153
d D 4.18 83/06/12 19:47:24 sam 18 17
c revamp network ioctls; add IFF_NOTRAILERS
e
s 00033/00000/00124
d D 4.17 83/03/15 18:24:35 sam 17 16
c socket ioctls
e
s 00001/00001/00123
d D 4.16 82/10/31 14:56:12 root 16 15
c s/ubareset/reset/
e
s 00003/00000/00121
d D 4.15 82/06/23 21:10:04 sam 15 14
c added watchdog routines
e
s 00003/00001/00118
d D 4.14 82/06/13 22:59:45 sam 14 13
c add class a/b/c net #'s and purge logical host kludge code
e
s 00009/00003/00110
d D 4.13 82/05/24 17:15:33 wnj 13 12
c pt-pt, loopback can transmit, fixed en bug that bugged sam
e
s 00001/00000/00112
d D 4.12 82/03/30 11:31:16 sam 12 11
c with routing, but not forwarding
e
s 00016/00011/00096
d D 4.11 82/03/28 14:20:53 sam 11 10
c convert interfaces to sockaddr's and add hooks for routing
e
s 00001/00001/00106
d D 4.10 82/03/19 00:09:38 root 10 9
c move rawintrq defn first
e
s 00010/00000/00097
d D 4.9 82/03/15 04:43:09 wnj 9 8
c interfac queueing, restrictions on packets, tcp keep alives done 
c properly, bug fix to raw
e
s 00003/00000/00094
d D 4.8 82/03/09 17:39:18 root 8 7
c handle broadcast packets
e
s 00004/00000/00090
d D 4.7 82/01/24 18:36:37 wnj 7 6
c IF_PREPEND
e
s 00005/00002/00085
d D 4.6 81/12/03 17:28:58 wnj 6 5
c cleanup
e
s 00002/00001/00085
d D 4.5 81/12/02 16:57:58 wnj 5 4
c yet more lint
e
s 00042/00009/00044
d D 4.4 81/11/29 21:58:32 wnj 4 3
c lint and interface cleanups
e
s 00035/00015/00018
d D 4.3 81/11/26 11:55:48 wnj 3 2
c before carry to ARPAVAX
e
s 00001/00000/00032
d D 4.2 81/11/20 00:46:31 wnj 2 1
c linted
e
s 00032/00000/00000
d D 4.1 81/11/18 16:51:57 wnj 1 0
c date and time created 81/11/18 16:51:57 by wnj
e
u
U
t
T
I 1
D 26
/*	%M%	%I%	%E%	*/
E 26
I 26
/*
D 29
 * Copyright (c) 1980 Regents of the University of California.
E 29
I 29
D 34
 * Copyright (c) 1982 Regents of the University of California.
E 34
I 34
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 34
E 29
D 35
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 35
I 35
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 36
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 36
I 36
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
E 36
E 35
 *
 *	%W% (Berkeley) %G%
 */
E 26

/*
D 3
 * Structure defining a network interface.
E 3
I 3
D 4
 * Definitions for network interfaces.
E 4
I 4
 * Structures defining a network interface, providing a packet
 * transport mechanism (ala level 0 of the PUP protocols).
 *
 * Each interface accepts output datagrams of a specified maximum
 * length, and provides higher level routines with input datagrams
 * received from its medium.
 *
 * Output occurs when the routine if_output is called, with three parameters:
D 11
 *	(*ifp->if_output)(ifp, m, pf)
 * Here m is the mbuf chain to be sent and pf is the protocol family
 * of the internetwork datagram format in which the data is wrapped
 * (e.g. PF_PUP or PF_INET).  The output routine encapsulates the
 * supplied datagram if necessary, and then transmits it on its medium.
E 11
I 11
 *	(*ifp->if_output)(ifp, m, dst)
 * Here m is the mbuf chain to be sent and dst is the destination address.
 * The output routine encapsulates the supplied datagram if necessary,
 * and then transmits it on its medium.
E 11
 *
 * On input, each interface unwraps the data received by it, and either
 * places it on the input queue of a internetwork datagram routine
 * and posts the associated software interrupt, or passes the datagram to a raw
 * packet input routine.
 *
D 11
 * Routines exist for locating interfaces by their internet addresses
E 11
I 11
 * Routines exist for locating interfaces by their addresses
E 11
 * or for locating a interface on a certain network, as well as more general
 * routing and gateway routines maintaining information used to locate
D 11
 * interfaces.  These routines live in the files if.c and ip_ggp.c.
E 11
I 11
 * interfaces.  These routines live in the files if.c and route.c
E 11
E 4
 */
D 4
struct ifqueue {
	struct	mbuf *ifq_head;
	struct	mbuf *ifq_tail;
};
E 4

/*
 * Structure defining a queue for a network interface.
E 3
 *
 * (Would like to call this struct ``if'', but C isn't PL/1.)
I 14
D 25
 *
 * EVENTUALLY PURGE if_net AND if_host FROM STRUCTURE
E 25
E 14
 */
struct ifnet {
I 6
	char	*if_name;		/* name, e.g. ``en'' or ``lo'' */
E 6
	short	if_unit;		/* sub-unit for lower level driver */
D 3
	short	if_flags;		/* state flags */
E 3
	short	if_mtu;			/* maximum transmission unit */
D 14
	short	if_net;			/* network number of interface */
E 14
I 14
D 25
	int	if_net;			/* network number of interface */
E 25
E 14
I 11
	short	if_flags;		/* up/down, broadcast, etc. */
I 15
	short	if_timer;		/* time 'til if_watchdog called */
I 30
	int	if_metric;		/* routing metric (external only) */
E 30
E 15
E 11
I 3
D 25
	int	if_host[2];		/* local net host number */
E 3
D 11
	struct	in_addr if_addr;	/* internet address of interface */
I 8
	struct	in_addr if_broadaddr;	/* broadcast address of interface */
E 11
I 11
D 13
	struct	sockaddr if_addr;	/* internet address of interface */
	struct	sockaddr if_broadaddr;	/* broadcast address of interface */
E 13
I 13
	struct	sockaddr if_addr;	/* address of interface */
	union {
		struct	sockaddr ifu_broadaddr;
		struct	sockaddr ifu_dstaddr;
	} if_ifu;
#define	if_broadaddr	if_ifu.ifu_broadaddr	/* broadcast address */
#define	if_dstaddr	if_ifu.ifu_dstaddr	/* other end of p-to-p link */
E 25
I 25
	struct	ifaddr *if_addrlist;	/* linked list of addresses per if */
E 25
E 13
E 11
E 8
D 3
	struct ifbuf {
		short	ib_mbcnt;	/* mbufs on chain */
		short	ib_mbhiwat;	/* mbufs permitted on chain */
		struct	mbuf *ib_hd;	/* head of chain */
		struct	mbuf *ib_tl;	/* tail of chain */
	} if_snd, if_rcv;
	struct ifsw {
		int	(*if_output)();		/* output routine */
		int	(*if_ubareset)();	/* uba reset routine */
	} *if_sw;
E 3
I 3
D 4
	struct	ifqueue if_snd;		/* output queue */
E 4
I 4
	struct	ifqueue {
		struct	mbuf *ifq_head;
		struct	mbuf *ifq_tail;
I 9
		int	ifq_len;
		int	ifq_maxlen;
		int	ifq_drops;
E 9
	} if_snd;			/* output queue */
/* procedure handles */
	int	(*if_init)();		/* init routine */
E 4
	int	(*if_output)();		/* output routine */
I 18
	int	(*if_ioctl)();		/* ioctl routine */
E 18
D 16
	int	(*if_ubareset)();	/* uba reset routine */
E 16
I 16
	int	(*if_reset)();		/* bus reset routine */
E 16
I 15
	int	(*if_watchdog)();	/* timer routine */
E 15
D 4
	int	if_collisions;
	int	if_ierrors;
	int	if_oerrors;
E 4
I 4
/* generic interface statistics */
I 6
	int	if_ipackets;		/* packets received on interface */
	int	if_ierrors;		/* input errors on interface */
	int	if_opackets;		/* packets sent on interface */
	int	if_oerrors;		/* output errors on interface */
E 6
	int	if_collisions;		/* collisions on csma interfaces */
D 6
	int	if_ierrors;		/* input errors */
	int	if_oerrors;		/* output errors */
E 6
/* end statistics */
E 4
E 3
I 2
	struct	ifnet *if_next;
E 2
};

I 11
#define	IFF_UP		0x1		/* interface is up */
#define	IFF_BROADCAST	0x2		/* broadcast address valid */
#define	IFF_DEBUG	0x4		/* turn on debugging */
I 12
D 13
#define	IFF_ROUTE	0x8		/* routine entry installed */
E 13
I 13
D 25
#define	IFF_ROUTE	0x8		/* routing entry installed */
E 25
I 25
D 30
/* was	IFF_ROUTE	0x8		/* routing entry installed */
E 30
I 30
#define	IFF_LOOPBACK	0x8		/* is a loopback net */
E 30
E 25
#define	IFF_POINTOPOINT	0x10		/* interface is point-to-point link */
I 18
#define	IFF_NOTRAILERS	0x20		/* avoid use of trailers */
I 19
#define	IFF_RUNNING	0x40		/* resources allocated */
I 21
#define	IFF_NOARP	0x80		/* no address resolution protocol */
I 32
/* next two not supported now, but reserved: */
#define	IFF_PROMISC	0x100		/* receive all packets */
#define	IFF_ALLMULTI	0x200		/* receive all multicast packets */
I 38
#define	IFF_NOFCS	0x400		/* no frame check sequence at the end */
E 38
E 32
I 23
D 25
#define	IFF_LOCAL	0x100		/* local network, host part encoded */
E 25
I 25
D 30
					/* flags set internally only: */
E 30
I 30
/* flags set internally only: */
E 30
#define	IFF_CANTCHANGE	(IFF_BROADCAST | IFF_POINTOPOINT | IFF_RUNNING)
E 25
E 23
E 21
E 19
E 18
E 13
E 12

E 11
I 4
/*
 * Output queues (ifp->if_snd) and internetwork datagram level (pup level 1)
 * input routines have queues of messages stored on ifqueue structures
 * (defined above).  Entries are added to and deleted from these structures
 * by these macros, which should be called with ipl raised to splimp().
 */
I 9
#define	IF_QFULL(ifq)		((ifq)->ifq_len >= (ifq)->ifq_maxlen)
#define	IF_DROP(ifq)		((ifq)->ifq_drops++)
E 9
E 4
D 3
/* bits in if_flags */
#define	IF_OACTIVE	1		/* output in progress */
E 3
I 3
#define	IF_ENQUEUE(ifq, m) { \
	(m)->m_act = 0; \
	if ((ifq)->ifq_tail == 0) \
D 5
		(ifq)->ifq_head = (ifq)->ifq_tail =  m; \
E 5
I 5
		(ifq)->ifq_head = m; \
E 5
	else \
		(ifq)->ifq_tail->m_act = m; \
I 5
	(ifq)->ifq_tail = m; \
I 9
	(ifq)->ifq_len++; \
E 9
E 5
}
I 7
#define	IF_PREPEND(ifq, m) { \
	(m)->m_act = (ifq)->ifq_head; \
I 8
	if ((ifq)->ifq_tail == 0) \
		(ifq)->ifq_tail = (m); \
E 8
	(ifq)->ifq_head = (m); \
I 9
	(ifq)->ifq_len++; \
E 9
}
I 27
/*
 * Packets destined for level-1 protocol input routines
 * have a pointer to the receiving interface prepended to the data.
 * IF_DEQUEUEIF extracts and returns this pointer when dequeueing the packet.
 * IF_ADJ should be used otherwise to adjust for its presence.
 */
#define	IF_ADJ(m) { \
	(m)->m_off += sizeof(struct ifnet *); \
	(m)->m_len -= sizeof(struct ifnet *); \
	if ((m)->m_len == 0) { \
		struct mbuf *n; \
		MFREE((m), n); \
		(m) = n; \
	} \
}
#define	IF_DEQUEUEIF(ifq, m, ifp) { \
	(m) = (ifq)->ifq_head; \
	if (m) { \
		if (((ifq)->ifq_head = (m)->m_act) == 0) \
			(ifq)->ifq_tail = 0; \
		(m)->m_act = 0; \
		(ifq)->ifq_len--; \
		(ifp) = *(mtod((m), struct ifnet **)); \
		IF_ADJ(m); \
	} \
}
E 27
E 7
#define	IF_DEQUEUE(ifq, m) { \
	(m) = (ifq)->ifq_head; \
	if (m) { \
		if (((ifq)->ifq_head = (m)->m_act) == 0) \
			(ifq)->ifq_tail = 0; \
		(m)->m_act = 0; \
I 9
		(ifq)->ifq_len--; \
E 9
	} \
}
I 9

#define	IFQ_MAXLEN	50
I 15
#define	IFNET_SLOWHZ	1		/* granularity is 1 second */
I 37
#define	IF_MINMTU	576		/* min we'll allow for variable MTU */
E 37
E 15
E 9
E 3

I 17
/*
I 25
 * The ifaddr structure contains information about one address
 * of an interface.  They are maintained by the different address families,
 * are allocated and attached when an address is set, and are linked
 * together so all addresses for an interface can be located.
 */
struct ifaddr {
	struct	sockaddr ifa_addr;	/* address of interface */
	union {
		struct	sockaddr ifu_broadaddr;
		struct	sockaddr ifu_dstaddr;
	} ifa_ifu;
#define	ifa_broadaddr	ifa_ifu.ifu_broadaddr	/* broadcast address */
#define	ifa_dstaddr	ifa_ifu.ifu_dstaddr	/* other end of p-to-p link */
	struct	ifnet *ifa_ifp;		/* back-pointer to interface */
	struct	ifaddr *ifa_next;	/* next address for interface */
};

/*
E 25
D 18
 * Interface request structure used by socket
 * ioctl's SIOCSIFxxxx (set interface parameter)
 * and SIOCGIFxxxx (get parameter).
E 18
I 18
 * Interface request structure used for socket
 * ioctl's.  All interface ioctl's must have parameter
 * definitions which begin with ifr_name.  The
 * remainder may be interface specific.
E 18
 */
struct	ifreq {
D 18
	char	ifr_name[16];		/* name of interface (e.g. "ec0") */
E 18
I 18
#define	IFNAMSIZ	16
	char	ifr_name[IFNAMSIZ];		/* if name, e.g. "en0" */
E 18
	union {
		struct	sockaddr ifru_addr;
		struct	sockaddr ifru_dstaddr;
I 24
		struct	sockaddr ifru_broadaddr;
E 24
		short	ifru_flags;
I 30
		int	ifru_metric;
I 37
		short	ifru_mtu;
E 37
E 30
I 18
		caddr_t	ifru_data;
E 18
	} ifr_ifru;
#define	ifr_addr	ifr_ifru.ifru_addr	/* address */
#define	ifr_dstaddr	ifr_ifru.ifru_dstaddr	/* other end of p-to-p link */
I 24
#define	ifr_broadaddr	ifr_ifru.ifru_broadaddr	/* broadcast address */
E 24
#define	ifr_flags	ifr_ifru.ifru_flags	/* flags */
I 30
#define	ifr_metric	ifr_ifru.ifru_metric	/* metric */
I 37
#define	ifr_mtu		ifr_ifru.ifru_mtu	/* MTU */
E 37
E 30
I 18
#define	ifr_data	ifr_ifru.ifru_data	/* for use by interface */
E 18
};

/*
 * Structure used in SIOCGIFCONF request.
 * Used to retrieve interface configuration
 * for machine (useful for programs which
 * must know all networks accessible).
 */
struct	ifconf {
	int	ifc_len;		/* size of associated buffer */
	union {
		caddr_t	ifcu_buf;
		struct	ifreq *ifcu_req;
	} ifc_ifcu;
#define	ifc_buf	ifc_ifcu.ifcu_buf	/* buffer address */
#define	ifc_req	ifc_ifcu.ifcu_req	/* array of structures returned */
};

I 22
D 29
/*
 * ARP ioctl request
 */
struct arpreq {
	struct sockaddr	arp_pa;		/* protocol address */
	struct sockaddr	arp_ha;		/* hardware address */
	int	arp_flags;		/* flags */
};
/*  arp_flags and at_flags field values */
#define	ATF_INUSE	1	/* entry in use */
#define ATF_COM		2	/* completed entry (enaddr valid) */
#define	ATF_PERM	4	/* permanent entry */
#define	ATF_PUBL	8	/* publish entry (respond for other host) */

E 29
E 22
E 17
#ifdef KERNEL
I 29
#include "../net/if_arp.h"
E 29
I 10
D 11
struct	ifqueue rawintrq;		/* raw packet input queue */
E 11
E 10
I 3
D 27
#ifdef INET
E 27
I 27
D 28
#if defined(INET) || defined(BBNNET)
E 28
I 28
D 33
#ifdef INET
E 28
E 27
struct	ifqueue	ipintrq;		/* ip packet input queue */
#endif
E 33
I 11
struct	ifqueue rawintrq;		/* raw packet input queue */
E 11
I 4
D 10
struct	ifqueue rawintrq;		/* raw packet input queue */
E 10
E 4
E 3
struct	ifnet *ifnet;
D 3
struct	ifnet *if_ifwithaddr(), *if_ifonnetof();
E 3
I 3
D 11
struct	ifnet *if_ifwithaddr(), *if_ifonnetof(), *if_gatewayfor();
E 11
I 11
D 25
struct	ifnet *if_ifwithaddr(), *if_ifwithnet(), *if_ifwithaf();
struct	ifnet *if_ifonnetof();
E 11
I 4
struct	in_addr if_makeaddr();
E 25
I 25
D 33
struct	ifaddr *ifa_ifwithaddr(), *ifa_ifwithnet(), *ifa_ifwithaf();
E 33
I 33
struct	ifaddr *ifa_ifwithaddr(), *ifa_ifwithnet();
E 33
I 31
struct	ifaddr *ifa_ifwithdstaddr();
I 39
struct	ifnet *ifunit();
E 39
E 31
E 25
E 4
E 3
D 29
#endif
E 29
I 29
#else KERNEL
#include <net/if_arp.h>
#endif KERNEL
E 29
E 1
