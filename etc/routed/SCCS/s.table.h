h22151
s 00008/00002/00074
d D 5.5 88/02/16 18:50:59 bostic 8 7
c add Berkeley specific headers
e
s 00000/00000/00076
d D 5.4 87/05/28 11:26:14 karels 7 6
c rework interface metrics to invert perspective; other misc. fixes
e
s 00002/00000/00074
d D 5.3 87/04/02 13:06:31 karels 6 5
c finish up interface metric code: store metric from our perspective,
c plus increment for those we send to; delete route from kernel when unreachable,
c but keep in tables to advertise deletion
e
s 00008/00000/00066
d D 5.2 86/04/20 23:34:35 karels 5 4
c changes to allow subnets to remain local, propogate net route
c where subnets don't go, and allow external routes from /etc/gateways
c to block routed from installing routes from elsewhere
e
s 00007/00001/00059
d D 5.1 85/06/04 16:40:07 dist 4 3
c Add copyright
e
s 00002/00001/00058
d D 4.3 84/05/03 13:46:01 karels 3 2
c optimizations: simplify inet_checkhost, use faster hashing,
c in-line expansions of ntohl et al.
e
s 00003/00003/00056
d D 4.2 84/04/09 15:05:34 karels 2 1
c many cleanups; avoid interface timing out; put it back asap
e
s 00059/00000/00000
d D 4.1 83/01/11 14:35:37 sam 1 0
c date and time created 83/01/11 14:35:37 by sam
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
D 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
I 8
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
 *
 *	%W% (Berkeley) %G%
 */
E 4

/*
 * Routing table management daemon.
 */

/*
 * Routing table structure; differs a bit from kernel tables.
 *
 * Note: the union below must agree in the first 4 members
 * so the ioctl's will work.
 */
struct rthash {
	struct	rt_entry *rt_forw;
	struct	rt_entry *rt_back;
};

struct rt_entry {
	struct	rt_entry *rt_forw;
	struct	rt_entry *rt_back;
	union {
		struct	rtentry rtu_rt;
		struct {
			u_long	rtu_hash;
			struct	sockaddr rtu_dst;
			struct	sockaddr rtu_router;
			short	rtu_flags;
			short	rtu_state;
			int	rtu_timer;
			int	rtu_metric;
I 6
			int	rtu_ifmetric;
E 6
			struct	interface *rtu_ifp;
		} rtu_entry;
	} rt_rtu;
};

#define	rt_rt		rt_rtu.rtu_rt			/* pass to ioctl */
#define	rt_hash		rt_rtu.rtu_entry.rtu_hash	/* for net or host */
#define	rt_dst		rt_rtu.rtu_entry.rtu_dst	/* match value */
#define	rt_router	rt_rtu.rtu_entry.rtu_router	/* who to forward to */
#define	rt_flags	rt_rtu.rtu_entry.rtu_flags	/* kernel flags */
#define	rt_timer	rt_rtu.rtu_entry.rtu_timer	/* for invalidation */
#define	rt_state	rt_rtu.rtu_entry.rtu_state	/* see below */
#define	rt_metric	rt_rtu.rtu_entry.rtu_metric	/* cost of route */
I 6
#define	rt_ifmetric	rt_rtu.rtu_entry.rtu_ifmetric	/* cost of route if */
E 6
#define	rt_ifp		rt_rtu.rtu_entry.rtu_ifp	/* interface to take */

D 3
#define	ROUTEHASHSIZ	19
E 3
I 3
#define	ROUTEHASHSIZ	32		/* must be a power of 2 */
#define	ROUTEHASHMASK	(ROUTEHASHSIZ - 1)
E 3

/*
 * "State" of routing table entry.
 */
#define	RTS_CHANGED	0x1		/* route has been altered recently */
I 5
#define	RTS_EXTERNAL	0x2		/* extern info, not installed or sent */
#define	RTS_INTERNAL	0x4		/* internal route, not installed */
E 5
D 2
#define	RTS_PASSIVE	0x20		/* don't time out route */
#define	RTS_INTERFACE	0x40		/* route is for network interface */
#define	RTS_REMOTE	0x80		/* route is for ``remote'' entity */
E 2
I 2
#define	RTS_PASSIVE	IFF_PASSIVE	/* don't time out route */
#define	RTS_INTERFACE	IFF_INTERFACE	/* route is for network interface */
#define	RTS_REMOTE	IFF_REMOTE	/* route is for ``remote'' entity */
I 5
#define	RTS_SUBNET	IFF_SUBNET	/* route is for network subnet */

/*
 * Flags are same as kernel, with this addition for af_rtflags:
 */
#define	RTF_SUBNET	0x8000		/* pseudo: route to subnet */
E 5
E 2

struct	rthash nethash[ROUTEHASHSIZ];
struct	rthash hosthash[ROUTEHASHSIZ];
struct	rt_entry *rtlookup();
struct	rt_entry *rtfind();
E 1
