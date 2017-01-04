h32215
s 00002/00001/00073
d D 5.5 88/05/31 11:52:40 karels 22 21
c add ctime
e
s 00008/00002/00066
d D 5.4 88/02/16 18:50:45 bostic 21 20
c add Berkeley specific headers
e
s 00000/00001/00068
d D 5.3 86/05/30 13:56:03 karels 20 19
c don't send net route to subnet gw's unless on subnet 0;
c a few checks for imposters; bug fix in "external" route configuration;
c rm loopback net defn.
e
s 00001/00001/00068
d D 5.2 85/08/06 17:35:31 karels 19 18
c mv protocol.h to <protocols/routed.h>
e
s 00007/00001/00062
d D 5.1 85/06/04 16:39:11 dist 18 17
c Add copyright
e
s 00001/00001/00062
d D 4.17 85/06/03 09:50:10 karels 17 16
c new subnets
e
s 00000/00002/00063
d D 4.16 85/02/25 13:46:36 karels 16 15
c remove 4.1a compat
e
s 00001/00001/00064
d D 4.15 84/08/29 15:06:04 karels 15 14
c turn COMPAT off
e
s 00021/00173/00044
d D 4.14 83/01/11 14:37:55 sam 14 13
c 4.1c conversion contortions
e
s 00000/00003/00217
d D 4.13 82/12/24 20:35:59 sam 13 12
c insq/remq now in libc.a
e
s 00004/00001/00216
d D 4.12 82/11/14 15:16:14 sam 12 11
c convert to 4.1c directory layout
e
s 00091/00000/00126
d D 4.11 82/11/02 22:29:59 sam 11 10
c major rewrite -- too much to describe here
e
s 00047/00010/00079
d D 4.10 82/06/10 20:13:20 sam 10 9
c keep separate interface list so we just delete routes when they expire
e
s 00006/00005/00083
d D 4.9 82/06/09 21:22:02 sam 9 8
c newrouter->oldrouter and state bits mucho different
e
s 00001/00000/00087
d D 4.8 82/06/09 00:45:30 wnj 8 7
c wnj changes
e
s 00007/00006/00080
d D 4.7 82/06/08 21:54:21 wnj 7 6
c cleanup per sam
e
s 00003/00002/00083
d D 4.6 82/06/05 16:52:52 sam 6 5
c add entry for portcheck
e
s 00001/00001/00084
d D 4.5 82/05/31 19:10:24 sam 5 4
c must match entries entirely on lookup
e
s 00001/00001/00084
d D 4.4 82/05/31 16:52:06 sam 4 3
c SILENT->HIDDEN (more mnemonic?)
e
s 00026/00027/00059
d D 4.3 82/05/26 14:33:03 sam 3 2
c split state and flags; cleanup a bit more 
e
s 00026/00010/00060
d D 4.2 82/05/25 18:56:08 sam 2 1
c cleanup 
e
s 00070/00000/00000
d D 4.1 82/05/22 22:26:22 sam 1 0
c date and time created 82/05/22 22:26:22 by sam
e
u
U
t
T
I 1
D 18
/*	%M%	%I%	%E%	*/
E 18
I 18
/*
D 22
 * Copyright (c) 1983 Regents of the University of California.
E 22
I 22
 * Copyright (c) 1983, 1988 Regents of the University of California.
E 22
D 21
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 21
I 21
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 21
 *
 *	%W% (Berkeley) %G%
 */
E 18

/*
 * Internal data structure definitions for
 * user routing process.  Based on Xerox NS
 * protocol specs with mods relevant to more
 * general addressing scheme.
 */
I 11
#include <sys/types.h>
#include <sys/socket.h>
D 12
#include <net/in.h>
E 12
I 12

E 12
E 11
I 2
#include <net/route.h>
I 12
#include <netinet/in.h>
I 19
#include <protocols/routed.h>
E 19

E 12
I 11
#include <stdio.h>
#include <netdb.h>
I 12

E 12
D 14
#include "rip.h"
E 14
I 14
D 19
#include "protocol.h"
E 19
#include "trace.h"
#include "interface.h"
#include "table.h"
#include "af.h"
E 14
E 11
E 2

D 14
/*
I 11
 * Trace record format.
 */
struct	iftrace {
	time_t	ift_stamp;		/* time stamp */
	struct	sockaddr ift_who;	/* from/to */
	char	*ift_packet;		/* pointer to packet */
	short	ift_size;		/* size of packet */
	short	ift_metric;		/* metric on associated metric */
};
E 14
I 14
D 15
#define	COMPAT	1		/* stay compatible with 4.1a daemons */
E 15
I 15
D 16
/* #define	COMPAT	1		/* stay compatible with 4.1a daemons */
E 15
E 14

E 16
/*
D 14
 * Per interface packet tracing buffers.  An incoming and
 * outgoing circular buffer of packets is maintained, per
 * interface, for debugging.  Buffers are dumped whenever
 * an interface is marked down.
 */
struct	ifdebug {
	struct	iftrace *ifd_records;	/* array of trace records */
	struct	iftrace *ifd_front;	/* next empty trace record */
	struct	interface *ifd_if;	/* for locating stuff */
};

/*
E 11
I 10
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
	int	int_net;			/* network # */
I 11
	struct	ifdebug int_input, int_output;	/* packet tracing stuff */
	int	int_ipackets;			/* input packets received */
	int	int_opackets;			/* output packets sent */
	char	*int_name;			/* from kernel if structure */
	u_short	int_transitions;		/* times gone up-down */
E 11
};

/*
 * 0x1 to 0x10 are reused from the kernel's ifnet definitions,
 * the others agree with the RTS_ flags defined below
 */
#define	IFF_UP		0x1		/* interface is up */
#define	IFF_BROADCAST	0x2		/* broadcast address valid */
#define	IFF_DEBUG	0x4		/* turn on debugging */
#define	IFF_ROUTE	0x8		/* routing entry installed */
#define	IFF_POINTOPOINT	0x10		/* interface is point-to-point link */
#define	IFF_PASSIVE	0x20		/* can't tell if up/down */
#define	IFF_INTERFACE	0x40		/* hardware interface */
#define	IFF_REMOTE	0x80		/* interface isn't on this machine */

/*
E 10
D 3
 * Internal routing table structure.
 * Differs a bit from kernel tables.
E 3
I 3
 * Routing table structure; differs a bit from kernel tables.
 *
 * Note: the union below must agree in the first 4 members
 * so the ioctl's will work.
E 3
 */
D 2
struct rt_hash {
E 2
I 2
struct rthash {
E 2
	struct	rt_entry *rt_forw;
	struct	rt_entry *rt_back;
};

struct rt_entry {
	struct	rt_entry *rt_forw;
	struct	rt_entry *rt_back;
D 2
	u_long	rt_hash;		/* for net or for host */
	struct	sockaddr rt_dst;	/* match value */
	struct	sockaddr rt_gateway;	/* who to forward to */
	short	rt_flags;		/* see below */
	short	rt_retry;		/* # ioctl retries */
	int	rt_timer;		/* for invalidation */
	int	rt_metric;		/* hop count of route */
	struct	ifnet *rt_ifp;		/* corresponding interface */
E 2
I 2
	union {
		struct	rtentry rtu_rt;
		struct {
			u_long	rtu_hash;
			struct	sockaddr rtu_dst;
D 7
			struct	sockaddr rtu_gateway;
E 7
I 7
			struct	sockaddr rtu_router;
E 7
			short	rtu_flags;
D 7
			short	rtu_retry;
D 3
			int	rtu_timer;
E 3
I 3
			short	rtu_timer;
E 7
			short	rtu_state;
I 7
			int	rtu_timer;
E 7
E 3
			int	rtu_metric;
D 10
			struct	ifnet *rtu_ifp;
I 7
D 9
			struct	sockaddr rtu_newrouter;
E 9
I 9
			struct	sockaddr rtu_oldrouter;
E 10
I 10
			struct	interface *rtu_ifp;
E 10
E 9
E 7
		} rtu_entry;
	} rt_rtu;
E 2
};

I 2
#define	rt_rt		rt_rtu.rtu_rt			/* pass to ioctl */
#define	rt_hash		rt_rtu.rtu_entry.rtu_hash	/* for net or host */
#define	rt_dst		rt_rtu.rtu_entry.rtu_dst	/* match value */
D 7
#define	rt_gateway	rt_rtu.rtu_entry.rtu_gateway	/* who to forward to */
E 7
I 7
#define	rt_router	rt_rtu.rtu_entry.rtu_router	/* who to forward to */
E 7
D 3
#define	rt_flags	rt_rtu.rtu_entry.rtu_flags	/* see below */
E 3
I 3
#define	rt_flags	rt_rtu.rtu_entry.rtu_flags	/* kernel flags */
E 3
D 7
#define	rt_retry	rt_rtu.rtu_entry.rtu_retry	/* retries of ioctl */
E 7
#define	rt_timer	rt_rtu.rtu_entry.rtu_timer	/* for invalidation */
I 3
#define	rt_state	rt_rtu.rtu_entry.rtu_state	/* see below */
E 3
#define	rt_metric	rt_rtu.rtu_entry.rtu_metric	/* cost of route */
#define	rt_ifp		rt_rtu.rtu_entry.rtu_ifp	/* interface to take */
I 7
D 9
#define	rt_newrouter	rt_rtu.rtu_entry.rtu_newrouter	/* for change's */
E 9
I 9
D 10
#define	rt_oldrouter	rt_rtu.rtu_entry.rtu_oldrouter	/* for change's */
E 10
E 9
E 7

E 2
#define	ROUTEHASHSIZ	19

/*
D 3
 * Flags used by routing process are not
 * interpreted by kernel.
E 3
I 3
 * "State" of routing table entry.
E 3
 */
D 3
#define	RTF_DELRT	0x8		/* delete pending */
#define	RTF_CHGRT	0x10		/* change command pending */
#define	RTF_ADDRT	0x20		/* add command pending */
#define	RTF_SILENT	0x40		/* don't send to router */
E 3
I 3
D 10
#define	RTS_DELRT	0x1		/* delete pending */
#define	RTS_CHGRT	0x2		/* change command pending */
#define	RTS_ADDRT	0x4		/* add command pending */
D 4
#define	RTS_SILENT	0x8		/* don't send to router */
E 4
I 4
D 7
#define	RTS_HIDDEN	0x8		/* don't send to router */
E 7
I 7
D 9
#define	RTS_PASSIVE	0x8		/* don't send to router */
#define	RTS_INTERFACE	0x10		/* route is for an interface */
I 8
#define	RTS_GLOBAL	0x20		/* entry is non-local, don't lose it */
E 9
I 9
#define	RTS_PASSIVE	0x8		/* don't time out route */
#define	RTS_DONTDELETE	0x10		/* don't remove route if timed out */
#define	RTS_DONTROUTE	0x20		/* don't route outgoing packets */
#define	RTS_HIDDEN	0x40		/* deleted but still reclaimable */
E 10
I 10
#define	RTS_CHANGED	0x1		/* route has been altered recently */
#define	RTS_PASSIVE	0x20		/* don't time out route */
#define	RTS_INTERFACE	0x40		/* route is for network interface */
#define	RTS_REMOTE	0x80		/* route is for ``remote'' entity */
E 10
E 9
E 8
E 7
E 4
E 3

D 2
struct	rt_hash nethash[ROUTEHASHSIZ], hosthash[ROUTEHASHSIZ];
E 2
I 2
struct	rthash nethash[ROUTEHASHSIZ], hosthash[ROUTEHASHSIZ];
E 2
D 5
struct	rt_entry *rtlookup();
E 5
I 5
struct	rt_entry *rtlookup(), *rtfind();
E 5

/*
D 3
 * Per address family routines.  Hash returns hash key based
 * on address; netmatch verifies net # matching, output interprets
 * an address in preparation for sending; portmatch interprets
 * an address in verifying incoming packets were sent from the
 * appropriate port; checkhost is used to decide whether an
 * address is for a host, or for a network (e.g. broadcast);
 * canon purges any extraneous stuff from a sender's address
 * before pattern matching is performed (e.g. Internet ports).
E 3
I 3
 * Per address family routines.
E 3
 */
struct afswitch {
D 3
	int	(*af_hash)();
	int	(*af_netmatch)();
	int	(*af_output)();
	int	(*af_portmatch)();
	int	(*af_checkhost)();
	int	(*af_canon)();
E 3
I 3
	int	(*af_hash)();		/* returns keys based on address */
	int	(*af_netmatch)();	/* verifies net # matching */
	int	(*af_output)();		/* interprets address for sending */
D 6
	int	(*af_portmatch)();	/* interprets address on receipt */
E 6
I 6
	int	(*af_portmatch)();	/* packet from some other router? */
	int	(*af_portcheck)();	/* packet from priviledged peer? */
E 6
	int	(*af_checkhost)();	/* tells if address for host or net */
D 6
	int	(*af_canon)();		/* purges extraneous part of address */
E 6
I 6
	int	(*af_canon)();		/* canonicalize address for compares */
E 6
E 3
};

I 3
/*
 * Structure returned by af_hash routines.
 */
E 3
struct afhash {
D 3
	u_int	afh_hosthash;
	u_int	afh_nethash;
E 3
I 3
	u_int	afh_hosthash;		/* host based hash */
	u_int	afh_nethash;		/* network based hash */
E 3
};

D 3
struct	afswitch afswitch[AF_MAX];
E 3
I 3
struct	afswitch afswitch[AF_MAX];	/* table proper */
I 10

/*
E 14
 * When we find any interfaces marked down we rescan the
 * kernel every CHECK_INTERVAL seconds to see if they've
 * come up.
 */
#define	CHECK_INTERVAL	(1*60)
I 11

D 17
#define	LOOPBACKNET	0177
E 17
I 17
D 20
#define	LOOPBACKNET	0x7f000000	/* 127.0.0.0 */
E 20
E 17
D 13
/* casts to keep lint happy */
#define	insque(q,p)	_insque((caddr_t)q,(caddr_t)p)
#define	remque(q)	_remque((caddr_t)q)
E 13
#define equal(a1, a2) \
	(bcmp((caddr_t)(a1), (caddr_t)(a2), sizeof (struct sockaddr)) == 0)
#define	min(a,b)	((a)>(b)?(b):(a))

D 14
struct	sockaddr_in routingaddr;
struct	sockaddr_in noroutingaddr;
E 14
I 14
struct	sockaddr_in addr;	/* address of daemon's socket */
E 14

D 14
int	s;
int	snoroute;		/* socket with no routing */
E 14
I 14
int	s;			/* source and sink of all data */
E 14
int	kmem;
int	supplier;		/* process should supply updates */
int	install;		/* if 1 call kernel */
D 14
int	lookforinterfaces;
int	performnlist;
E 14
I 14
int	lookforinterfaces;	/* if 1 probe kernel for new up interfaces */
int	performnlist;		/* if 1 check if /vmunix has changed */
E 14
int	externalinterfaces;	/* # of remote and local interfaces */
D 14
int	timeval;
E 14
I 14
int	timeval;		/* local idea of time */
E 14

D 14
/*
 * Packet tracing stuff.
 */
int	tracing;		/* on/off */
FILE	*ftrace;		/* output trace file */
#define	TRACE_ACTION(action, route) \
	{ if (tracing) \
		traceaction(ftrace, "action", route); \
	}
#define	TRACE_INPUT(ifp, from, size) \
	{ if (tracing) { \
		ifp = if_iflookup(from); \
		if (ifp) \
			trace(&ifp->int_input, from, packet, size, \
				ifp->int_metric); \
	  } \
	}
#define	TRACE_OUTPUT(ifp, to, size) \
	{ if (tracing) \
		trace(&ifp->int_output, to, packet, size, ifp->int_metric); \
	}

E 14
char	packet[MAXPACKETSIZE+1];
struct	rip *msg;

char	**argv0;
struct	servent *sp;

D 14
struct	in_addr inet_makeaddr();
struct	interface *if_ifwithaddr(), *if_ifwithnet(), *if_iflookup();
extern	char *malloc(), *sys_errlist[];
extern	int errno, exit();
E 14
I 14
extern	char *sys_errlist[];
extern	int errno;
E 14

D 14
int	sendmsg(), supply();
int	timer(), cleanup();
E 14
I 14
struct	in_addr inet_makeaddr();
int	inet_addr();
char	*malloc();
I 22
char	*ctime();
E 22
int	exit();
int	sendmsg();
int	supply();
int	timer();
int	cleanup();
E 14
E 11
E 10
E 3
E 1
