h03762
s 00008/00002/00061
d D 5.4 88/02/16 18:50:52 bostic 7 6
c add Berkeley specific headers
e
s 00002/00000/00061
d D 5.3 86/04/20 23:34:13 karels 6 5
c changes to allow subnets to remain local, propogate net route
c where subnets don't go, and allow external routes from /etc/gateways
c to block routed from installing routes from elsewhere
e
s 00001/00001/00060
d D 5.2 86/02/07 10:05:45 karels 5 4
c resync with kernel, add metric and IFF_LOOPBACK
e
s 00007/00001/00054
d D 5.1 85/06/04 16:39:31 dist 4 3
c Add copyright
e
s 00007/00003/00048
d D 4.3 85/06/03 09:50:31 karels 3 2
c new subnets
e
s 00007/00005/00044
d D 4.2 84/04/09 15:29:31 karels 2 1
c subnet routing
e
s 00049/00000/00000
d D 4.1 83/01/11 14:35:35 sam 1 0
c date and time created 83/01/11 14:35:35 by sam
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
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
 *
 *	%W% (Berkeley) %G%
 */
E 4

/*
 * Routing table management daemon.
 */

/*
 * An ``interface'' is similar to an ifnet structure,
 * except it doesn't contain q'ing info, and it also
 * handles ``logical'' interfaces (remote gateways
 * that we want to keep polling even if they go down).
 * The list of interfaces which we maintain is used
 * in supplying the gratuitous routing table updates.
 */
struct interface {
	struct	interface *int_next;
	struct	sockaddr int_addr;		/* address on this host */
	union {
		struct	sockaddr intu_broadaddr;
		struct	sockaddr intu_dstaddr;
	} int_intu;
#define	int_broadaddr	int_intu.intu_broadaddr	/* broadcast address */
#define	int_dstaddr	int_intu.intu_dstaddr	/* other end of p-to-p link */
	int	int_metric;			/* init's routing entry */
	int	int_flags;			/* see below */
D 3
	int	int_net;			/* network # */
E 3
I 3
	/* START INTERNET SPECIFIC */
	u_long	int_net;			/* network # */
	u_long	int_netmask;			/* net mask for addr */
	u_long	int_subnet;			/* subnet # */
	u_long	int_subnetmask;			/* subnet mask for addr */
	/* END INTERNET SPECIFIC */
E 3
	struct	ifdebug int_input, int_output;	/* packet tracing stuff */
	int	int_ipackets;			/* input packets received */
	int	int_opackets;			/* output packets sent */
	char	*int_name;			/* from kernel if structure */
	u_short	int_transitions;		/* times gone up-down */
};

/*
D 2
 * 0x1 to 0x10 are reused from the kernel's ifnet definitions,
 * the others agree with the RTS_ flags defined below
E 2
I 2
D 3
 * 0x1 to 0x100 are reused from the kernel's ifnet definitions,
E 3
I 3
 * 0x1 to 0x10 are reused from the kernel's ifnet definitions,
E 3
 * the others agree with the RTS_ flags defined elsewhere.
E 2
 */
#define	IFF_UP		0x1		/* interface is up */
#define	IFF_BROADCAST	0x2		/* broadcast address valid */
#define	IFF_DEBUG	0x4		/* turn on debugging */
D 5
#define	IFF_ROUTE	0x8		/* routing entry installed */
E 5
I 5
#define	IFF_LOOPBACK	0x8		/* software loopback net */
E 5
#define	IFF_POINTOPOINT	0x10		/* interface is point-to-point link */
D 2
#define	IFF_PASSIVE	0x20		/* can't tell if up/down */
#define	IFF_INTERFACE	0x40		/* hardware interface */
#define	IFF_REMOTE	0x80		/* interface isn't on this machine */
E 2
I 2
D 3
#define	IFF_LOCAL	0x100		/* local network, host part encoded */
E 3

I 6
#define	IFF_SUBNET	0x1000		/* interface on subnetted network */
E 6
#define	IFF_PASSIVE	0x2000		/* can't tell if up/down */
#define	IFF_INTERFACE	0x4000		/* hardware interface */
#define	IFF_REMOTE	0x8000		/* interface isn't on this machine */
E 2

struct	interface *if_ifwithaddr();
I 6
struct	interface *if_ifwithdstaddr();
E 6
struct	interface *if_ifwithnet();
struct	interface *if_iflookup();
E 1
