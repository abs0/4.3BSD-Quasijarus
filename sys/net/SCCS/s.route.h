h47783
s 00010/00005/00082
d D 7.4 88/06/27 18:59:46 bostic 23 22
c install approved copyright notice
e
s 00008/00002/00079
d D 7.3 87/12/30 11:57:42 bostic 22 21
c add Berkeley header
e
s 00001/00000/00080
d D 7.2 87/01/15 15:09:41 karels 21 20
c mark routes modified by redirects
e
s 00001/00001/00079
d D 7.1 86/06/04 23:42:54 mckusick 20 19
c 4.3BSD release version
e
s 00000/00001/00080
d D 6.8 86/03/12 11:28:12 karels 19 18
c rm unused
e
s 00000/00012/00081
d D 6.7 85/12/19 16:20:13 karels 18 17
c rm bbnnet
e
s 00006/00008/00087
d D 6.6 85/09/16 21:22:51 karels 17 15
c mark dynamically created routes; keep incompatibility in its place
e
s 00005/00007/00088
d R 6.6 85/09/16 21:21:27 karels 16 15
c mark dynamically created routes; keep incompatibility in its place
e
s 00014/00001/00081
d D 6.5 85/08/21 15:40:35 walsh 15 14
c need to remember gateway ping information.
e
s 00007/00001/00075
d D 6.4 85/06/08 12:28:30 mckusick 14 13
c Add copyright
e
s 00004/00000/00072
d D 6.3 84/08/29 16:07:08 karels 13 12
c bigger routing hash tables for gateways
e
s 00006/00001/00066
d D 6.2 84/05/30 16:24:56 karels 12 11
c use mask instead of urem for route hashing
e
s 00000/00000/00067
d D 6.1 83/07/29 07:08:58 sam 11 10
c 4.2 distribution
e
s 00018/00009/00049
d D 4.10 83/05/30 18:49:49 sam 10 9
c add wildcard routing and routing statistics; also routing redirects 
c can generate new routing table entries
e
s 00000/00007/00058
d D 4.9 83/05/12 14:59:31 sam 9 8
c no more routetoif (yeah)
e
s 00040/00030/00025
d D 4.8 82/06/12 23:19:56 wnj 8 7
c now the routing code might wokr
e
s 00016/00007/00039
d D 4.7 82/03/31 20:37:05 sam 7 6
c routing tried and working, add logical host stuff
e
s 00005/00003/00041
d D 4.6 82/03/30 19:57:44 sam 6 5
c routing code now operational
e
s 00002/00004/00042
d D 4.5 82/03/30 11:32:59 sam 5 4
c with routing, but not forwarding
e
s 00001/00002/00045
d D 4.4 82/03/29 14:36:02 sam 4 3
c no need for RTF_MUNGE, figured out a better way
e
s 00001/00000/00046
d D 4.3 82/03/29 11:32:58 sam 3 2
c first cut (incomplete) at routing
e
s 00003/00001/00043
d D 4.2 82/03/28 14:23:35 sam 2 1
c convert interfaces to sockaddr's and add hooks for routing
e
s 00044/00000/00000
d D 4.1 82/03/27 22:57:41 sam 1 0
c date and time created 82/03/27 22:57:41 by sam
e
u
U
f b 
t
T
I 1
D 14
/*	%M%	%I%	%E%	*/
E 14
I 14
/*
D 20
 * Copyright (c) 1980 Regents of the University of California.
E 20
I 20
 * Copyright (c) 1980, 1986 Regents of the University of California.
E 20
D 22
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 22
I 22
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 23
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 23
I 23
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
E 23
E 22
 *
D 15
 *	%W% (Berkeley) %G%
E 15
I 15
D 17
 *	@(#)route.h	6.4 (Berkeley) 6/8/85
E 17
I 17
 *	%W% (Berkeley) %G%
E 17
E 15
 */
E 14

/*
D 7
 * Structure of kernel resident routing
 * data base.  Assumption is user routing
 * daemon maintains this data base based
 * on routing information it gleans from
 * gateway protocols it listens to (e.g. GGP).
E 7
I 7
 * Kernel resident routing tables.
 * 
D 8
 * Each interface makes an entry at boot time so that
 * correspondents directly addressible can be found.
 * User programs can update this data base from information
 * stored in the file system or information gleaned from
 * routing protocol interactions with gateways.
E 8
I 8
D 17
 * The routing tables are initialized at boot time by
 * making entries for all directly connected interfaces.
E 17
I 17
 * The routing tables are initialized when interface addresses
 * are set by making entries for all directly connected interfaces.
E 17
D 10
 * Routing daemons can thereafter update the routing tables.
E 8
E 7
 *
D 7
 * TO ADD:
 *	more statistics -- smooth usage figures
E 7
I 7
 * TODO:
 *	keep statistics
E 10
D 8
 *	smooth usage figures
E 8
E 7
 */
D 8
struct rtentry {
D 5
	u_long	rt_key;			/* lookup key */
E 5
I 5
D 6
	u_long	rt_hash[2];		/* [0] for net, [1] for host */
E 6
I 6
	u_long	rt_hash;		/* for net or for host */
E 6
E 5
	struct	sockaddr rt_dst;	/* match value */
	struct	sockaddr rt_gateway;	/* who to forward to */
	short	rt_flags;		/* see below */
	short	rt_refcnt;		/* # held references */
	u_long	rt_use;			/* raw # packets forwarded */
	struct	ifnet *rt_ifp;		/* interface to use */
};
E 8

I 8
/*
 * A route consists of a destination address and a reference
 * to a routing entry.  These are often held by protocols
 * in their control blocks, e.g. inpcb.
 */
E 8
struct route {
	struct	rtentry *ro_rt;
	struct	sockaddr ro_dst;
D 8
	caddr_t	ro_pcb;			/* back pointer? */
E 8
I 8
D 17
#ifdef notdef
	caddr_t	ro_pcb;			/* not used yet */
#endif
E 17
E 8
};
I 8
D 9
#ifdef KERNEL
/*
 * The route ``routetoif'' is a special atom passed to the output routines
 * to implement the SO_DONTROUTE option.
 */
struct	route routetoif;
#endif
E 9
E 8

/*
D 8
 * Flags and host/network status.
E 8
I 8
 * We distinguish between routes to hosts and routes to networks,
 * preferring the former if available.  For each route we infer
 * the interface to use from the gateway address supplied when
 * the route was entered.  Routes that forward packets through
 * gateways are marked so that the output routines know to address the
 * gateway rather than the ultimate destination.
E 8
 */
I 8
struct rtentry {
	u_long	rt_hash;		/* to speed lookups */
	struct	sockaddr rt_dst;	/* key */
	struct	sockaddr rt_gateway;	/* value */
	short	rt_flags;		/* up/down?, host/net */
	short	rt_refcnt;		/* # held references */
	u_long	rt_use;			/* raw # packets forwarded */
	struct	ifnet *rt_ifp;		/* the answer: interface to use */
I 17
D 18
#ifdef BBNNET
E 17
I 15
	union {				/* domain specific info */
D 17
#ifdef INET
E 17
	    struct {
		int in_rt_pc;		/* count of pings not answered */
	    } rt_in_data;

#define	irt_pings	rt_data.rt_in_data.in_rt_pc
#define irt_gdown	rt_data.rt_in_data.in_rt_pc

D 17
#endif
E 17
	    char rt_dummy[32];
	} rt_data;
I 17
#endif
E 18
E 17
E 15
};
D 10
#ifdef KERNEL
#define	RTHASHSIZ	7
struct	mbuf *rthost[RTHASHSIZ];
struct	mbuf *rtnet[RTHASHSIZ];
#endif
E 10

E 8
D 2
#define	RTS_UP		0x1		/* route useable */
E 2
I 2
#define	RTF_UP		0x1		/* route useable */
E 2
D 4
#define	RTF_MUNGE	0x2		/* munge packet src address */
I 3
#define	RTF_DIRECT	0x4		/* destination is a neighbor */
E 4
I 4
D 8
#define	RTF_DIRECT	0x2		/* destination is a neighbor */
E 8
I 8
#define	RTF_GATEWAY	0x2		/* destination is a gateway */
E 8
I 6
#define	RTF_HOST	0x4		/* host entry (net otherwise) */
I 15
D 19
#define RTF_REINSTATE	0x8		/* re-instate route after timeout */
E 19
I 17
#define	RTF_DYNAMIC	0x10		/* created dynamically (by redirect) */
I 21
#define	RTF_MODIFIED	0x20		/* modified dynamically (by redirect) */
E 21
E 17
E 15
I 7

I 10
/*
 * Routing statistics.
 */
struct	rtstat {
	short	rts_badredirect;	/* bogus redirect calls */
	short	rts_dynamic;		/* routes created by redirects */
	short	rts_newgateway;		/* routes modified by redirects */
	short	rts_unreach;		/* lookups which failed */
	short	rts_wildcard;		/* lookups satisfied by a wildcard */
};

#ifdef KERNEL
E 10
#define	RTFREE(rt) \
	if ((rt)->rt_refcnt == 1) \
		rtfree(rt); \
	else \
		(rt)->rt_refcnt--;
I 10

I 13
#ifdef	GATEWAY
#define	RTHASHSIZ	64
#else
E 13
D 12
#define	RTHASHSIZ	7
E 12
I 12
#define	RTHASHSIZ	8
I 13
#endif
E 13
#if	(RTHASHSIZ & (RTHASHSIZ - 1)) == 0
#define RTHASHMOD(h)	((h) & (RTHASHSIZ - 1))
#else
#define RTHASHMOD(h)	((h) % RTHASHSIZ)
#endif
E 12
struct	mbuf *rthost[RTHASHSIZ];
struct	mbuf *rtnet[RTHASHSIZ];
struct	rtstat	rtstat;
#endif
E 10
E 7
E 6
E 4
E 3
D 8

#ifdef KERNEL
/*
 * Lookup are hashed by a key.  Each hash bucket
 * consists of a linked list of mbuf's
 * containing routing entries.  Dead entries are
 * reclaimed along with mbufs.
 */
D 6
#define	RTHASHSIZ	16
D 5
struct mbuf *routehash[RTHASHSIZ];
I 2

struct	rtentry *reroute();
E 5
I 5
struct	mbuf *routehash[RTHASHSIZ];
E 6
I 6
#define	RTHASHSIZ	7
struct	mbuf *rthost[RTHASHSIZ];
struct	mbuf *rtnet[RTHASHSIZ];
E 6
E 5
E 2
#endif
E 8
E 1
