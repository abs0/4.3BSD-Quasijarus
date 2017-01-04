h45325
s 00008/00001/00056
d D 5.1 85/06/04 16:39:48 dist 12 11
c Add copyright
e
s 00000/00000/00057
d D 4.11 84/04/09 15:05:30 karels 11 10
c many cleanups; avoid interface timing out; put it back asap
e
s 00001/00001/00056
d D 4.10 83/08/11 23:09:27 sam 10 9
c standardize sccs keyword lines
e
s 00007/00001/00050
d D 4.9 83/05/25 17:51:00 sam 9 8
c protocol change; byte swap those fields which need it;  also add 
c a version stamp to allow future changes
e
s 00000/00001/00051
d D 4.8 82/08/18 12:09:34 sam 8 7
c port id moved to in.h
e
s 00001/00001/00051
d D 4.7 82/06/10 20:12:14 sam 7 6
c bill must've changed the timer value
e
s 00010/00004/00042
d D 4.6 82/06/09 21:21:22 sam 6 5
c include table of strings for printing out packet types
e
s 00005/00005/00041
d D 4.5 82/06/09 00:45:03 wnj 5 4
c wnj changes
e
s 00008/00001/00038
d D 4.4 82/06/05 16:52:35 sam 4 3
c add trace packets
e
s 00006/00002/00033
d D 4.3 82/05/26 14:25:14 sam 3 2
c turn maximum packet size down so postel doesn't complain
e
s 00003/00001/00032
d D 4.2 82/05/24 19:26:22 sam 2 1
c add interval for checking "down" interfaces
e
s 00033/00000/00000
d D 4.1 82/05/22 22:26:19 sam 1 0
c date and time created 82/05/22 22:26:19 by sam
e
u
U
t
T
I 1
D 10
/*	%M%	%E%	%I%	*/
E 10
I 10
D 12
/*	%M%	%I%	%E%	*/
E 12
I 12
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

E 12
E 10
/*
 * Routing Information Protocol
I 3
 *
 * Derived from Xerox NS Routing Information Protocol
 * by changing 32-bit net numbers to sockaddr's and
 * padding stuff to 32-bit boundaries.
E 3
 */
I 9
#define	RIPVERSION	1

E 9
struct netinfo {
	struct	sockaddr rip_dst;	/* destination net/host */
	int	rip_metric;		/* cost of route */
};

struct rip {
	u_char	rip_cmd;		/* request/response */
D 9
	u_char	rip_res1[3];		/* pad to 32-bit boundary */
E 9
I 9
	u_char	rip_vers;		/* protocol version # */
	u_char	rip_res1[2];		/* pad to 32-bit boundary */
E 9
D 4
	struct	netinfo rip_nets[1];	/* variable length... */
E 4
I 4
	union {
		struct	netinfo ru_nets[1];	/* variable length... */
		char	ru_tracefile[1];	/* ditto ... */
	} ripun;
#define	rip_nets	ripun.ru_nets
#define	rip_tracefile	ripun.ru_tracefile
E 4
};
 
I 9
/*
 * Packet types.
 */
E 9
D 6
#define	RIPCMD_REQUEST		0x1	/* want info */
#define	RIPCMD_RESPONSE		0x2	/* responding to request */
I 4
#define	RIPCMD_TRACEON		0x3	/* turn tracing on */
#define	RIPCMD_TRACEOFF		0x4	/* turn it off */
E 6
I 6
#define	RIPCMD_REQUEST		1	/* want info */
#define	RIPCMD_RESPONSE		2	/* responding to request */
#define	RIPCMD_TRACEON		3	/* turn tracing on */
#define	RIPCMD_TRACEOFF		4	/* turn it off */

#define	RIPCMD_MAX		5
#ifdef RIPCMDS
char *ripcmds[RIPCMD_MAX] =
  { "#0", "REQUEST", "RESPONSE", "TRACEON", "TRACEOFF" };
#endif
E 6
E 4

D 8
#define IPPORT_ROUTESERVER 	520	/* well-known port */
E 8
#define	HOPCNT_INFINITY		16	/* per Xerox NS */
D 3
#define	MAXPACKETSIZE		1024	/* max broadcast size */
E 3
I 3
#define	MAXPACKETSIZE		512	/* max broadcast size */
E 3

/*
D 3
 * Timer values used in managing the routing table "cache".
E 3
I 3
 * Timer values used in managing the routing table.
E 3
 * Every update forces an entry's timer to be reset.  After
 * EXPIRE_TIME without updates, the entry is marked invalid,
 * but held onto until GARBAGE_TIME so that others may
D 2
 * see it "be deleted".
E 2
I 2
D 5
 * see it "be deleted".  If there's a reason to look for network
 * interface transitions do so every CHECK_INTERVAL seconds.
E 5
I 5
 * see it "be deleted".
E 5
E 2
 */
#define	TIMER_RATE		30	/* alarm clocks every 30 seconds */
D 5
#define	GARBAGE_TIME		210	/* time to garbage collect */
#define	EXPIRE_TIME		180	/* time to mark entry invalid */
E 5
I 5

E 5
#define	SUPPLY_INTERVAL		30	/* time to supply tables */
I 2
D 5
#define	CHECK_INTERVAL		300	/* time to check for new interfaces */
E 5
I 5

#define	EXPIRE_TIME		180	/* time to mark entry invalid */
D 7
#define	GARBAGE_TIME		210	/* time to garbage collect */
E 7
I 7
#define	GARBAGE_TIME		240	/* time to garbage collect */
E 7
E 5
E 2
E 1
