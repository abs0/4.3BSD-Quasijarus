h03595
s 00001/00001/00312
d D 5.13 88/06/06 16:16:33 karels 24 23
c missed a few: make default, local-loop routes have metric 1,
c as not incremented when sent; check for 0 on input (can't be right)
e
s 00044/00030/00269
d D 5.12 88/05/31 12:13:10 karels 23 22
c fix up tracing info; add default, but disable for now (could cause
c suboptimal routes or confusion when used in input() for route compression)
e
s 00009/00003/00290
d D 5.11 88/02/16 18:51:00 bostic 22 21
c add Berkeley specific headers
e
s 00070/00043/00223
d D 5.10 87/05/28 11:26:15 karels 21 20
c rework interface metrics to invert perspective; other misc. fixes
e
s 00002/00001/00264
d D 5.9 87/05/15 13:37:16 karels 20 19
c minor fixes
e
s 00012/00011/00253
d D 5.8 87/04/27 12:12:06 karels 19 18
c checking was too strict for internal routes
e
s 00025/00009/00239
d D 5.7 87/04/02 13:06:33 karels 18 17
c finish up interface metric code: store metric from our perspective,
c plus increment for those we send to; delete route from kernel when unreachable,
c but keep in tables to advertise deletion
e
s 00008/00004/00240
d D 5.6 86/10/30 20:36:17 karels 17 16
c delay deletion from internal tables when cur router deletes
c (so can advertise deletion)
e
s 00006/00006/00238
d D 5.5 86/05/28 20:16:32 karels 16 15
c print old if, not new, when dropping interface
e
s 00001/00001/00243
d D 5.4 86/04/24 14:47:38 karels 15 14
c off by one (paren)
e
s 00021/00023/00223
d D 5.3 86/04/20 23:34:38 karels 14 13
c changes to allow subnets to remain local, propogate net route
c where subnets don't go, and allow external routes from /etc/gateways
c to block routed from installing routes from elsewhere
e
s 00003/00003/00243
d D 5.2 86/02/23 19:34:27 karels 13 12
c don't rely on AF_MAX (comes from kernel include): check for nil explicitly,
c use our own idea of table size.  Use syslog to (optionally) log bad packets.
c Don't respond to routing inquiries from a router unless we are suppliers
c (really want to respondto everything but broadcasts, but haven't got
c the "to" address.)
e
s 00007/00001/00239
d D 5.1 85/06/04 16:37:37 dist 12 11
c Add copyright
e
s 00004/00002/00236
d D 4.11 85/02/25 11:24:29 karels 11 10
c clear RTF_GATEWAY when changing back to interface
e
s 00010/00001/00228
d D 4.10 84/12/20 18:04:43 karels 10 9
c syslog for interface transitions; broadcast all unreachable before exit
e
s 00001/00001/00228
d D 4.9 84/05/03 14:20:22 karels 9 8
c fix error in 4.7
e
s 00007/00007/00222
d D 4.8 84/05/03 13:46:06 karels 8 7
c optimizations: simplify inet_checkhost, use faster hashing,
c in-line expansions of ntohl et al.
e
s 00031/00018/00198
d D 4.7 84/04/10 21:44:06 karels 7 6
c subnet routing; don't copy routes from the gateways files everywhere
e
s 00034/00013/00182
d D 4.6 84/04/09 15:05:39 karels 6 5
c many cleanups; avoid interface timing out; put it back asap
e
s 00005/00004/00190
d D 4.5 84/03/07 21:56:28 karels 5 4
c more consistency checks; watch those unsigned moduli
e
s 00013/00001/00181
d D 4.4 83/09/25 19:24:29 sam 4 3
c add kludge for people that don't understand what /etc/gateways is for
e
s 00001/00001/00181
d D 4.3 83/05/25 17:51:12 sam 3 2
c protocol change; byte swap those fields which need it;  also add 
c a version stamp to allow future changes
e
s 00001/00001/00181
d D 4.2 83/01/11 14:38:38 sam 2 1
c 4.1c conversion contortions
e
s 00182/00000/00000
d D 4.1 82/11/02 22:28:08 sam 1 0
c date and time created 82/11/02 22:28:08 by sam
e
u
U
t
T
I 12
/*
D 23
 * Copyright (c) 1983 Regents of the University of California.
E 23
I 23
 * Copyright (c) 1983, 1988 Regents of the University of California.
E 23
D 22
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 22
I 22
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 22
 */

E 12
I 1
#ifndef lint
D 3
static char sccsid[] = "%W% %G%";
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
E 3
D 12
#endif
E 12
I 12
D 22
#endif not lint
E 22
I 22
#endif /* not lint */
E 22
E 12

/*
 * Routing Table Management Daemon
 */
D 2
#include "router.h"
E 2
I 2
#include "defs.h"
E 2
#include <sys/ioctl.h>
#include <errno.h>
I 10
D 23
#include <syslog.h>
E 23
I 23
#include <sys/syslog.h>
E 23
E 10

#ifndef DEBUG
#define	DEBUG	0
#endif

int	install = !DEBUG;		/* if 1 call kernel */

/*
 * Lookup dst in the tables for an exact match.
 */
struct rt_entry *
rtlookup(dst)
	struct sockaddr *dst;
{
	register struct rt_entry *rt;
	register struct rthash *rh;
D 5
	register int hash;
E 5
I 5
	register u_int hash;
E 5
	struct afhash h;
	int doinghost = 1;

D 13
	if (dst->sa_family >= AF_MAX)
E 13
I 13
	if (dst->sa_family >= af_max)
E 13
		return (0);
	(*afswitch[dst->sa_family].af_hash)(dst, &h);
	hash = h.afh_hosthash;
D 8
	rh = &hosthash[hash % ROUTEHASHSIZ];
E 8
I 8
	rh = &hosthash[hash & ROUTEHASHMASK];
E 8
again:
	for (rt = rh->rt_forw; rt != (struct rt_entry *)rh; rt = rt->rt_forw) {
		if (rt->rt_hash != hash)
			continue;
		if (equal(&rt->rt_dst, dst))
			return (rt);
	}
	if (doinghost) {
		doinghost = 0;
		hash = h.afh_nethash;
D 8
		rh = &nethash[hash % ROUTEHASHSIZ];
E 8
I 8
		rh = &nethash[hash & ROUTEHASHMASK];
E 8
		goto again;
	}
	return (0);
}

I 23
struct sockaddr wildcard;	/* zero valued cookie for wildcard searches */

E 23
/*
 * Find a route to dst as the kernel would.
 */
struct rt_entry *
rtfind(dst)
	struct sockaddr *dst;
{
	register struct rt_entry *rt;
	register struct rthash *rh;
D 5
	register int hash;
E 5
I 5
	register u_int hash;
E 5
	struct afhash h;
	int af = dst->sa_family;
	int doinghost = 1, (*match)();

D 13
	if (af >= AF_MAX)
E 13
I 13
	if (af >= af_max)
E 13
		return (0);
	(*afswitch[af].af_hash)(dst, &h);
	hash = h.afh_hosthash;
D 8
	rh = &hosthash[hash % ROUTEHASHSIZ];
E 8
I 8
	rh = &hosthash[hash & ROUTEHASHMASK];
E 8

again:
	for (rt = rh->rt_forw; rt != (struct rt_entry *)rh; rt = rt->rt_forw) {
		if (rt->rt_hash != hash)
			continue;
		if (doinghost) {
			if (equal(&rt->rt_dst, dst))
				return (rt);
		} else {
			if (rt->rt_dst.sa_family == af &&
			    (*match)(&rt->rt_dst, dst))
				return (rt);
		}
	}
	if (doinghost) {
		doinghost = 0;
		hash = h.afh_nethash;
D 8
		rh = &nethash[hash % ROUTEHASHSIZ];
E 8
I 8
		rh = &nethash[hash & ROUTEHASHMASK];
E 8
		match = afswitch[af].af_netmatch;
		goto again;
	}
I 23
#ifdef notyet
	/*
	 * Check for wildcard gateway, by convention network 0.
	 */
	if (dst != &wildcard) {
		dst = &wildcard, hash = 0;
		goto again;
	}
#endif
E 23
	return (0);
}

rtadd(dst, gate, metric, state)
	struct sockaddr *dst, *gate;
	int metric, state;
{
	struct afhash h;
	register struct rt_entry *rt;
	struct rthash *rh;
D 5
	int af = dst->sa_family, flags, hash;
E 5
I 5
D 19
	int af = dst->sa_family, flags;
E 19
I 19
D 21
	int af = dst->sa_family, flags, ifmetric;
E 21
I 21
	int af = dst->sa_family, flags;
E 21
E 19
	u_int hash;
E 5

D 13
	if (af >= AF_MAX)
E 13
I 13
	if (af >= af_max)
E 13
		return;
	(*afswitch[af].af_hash)(dst, &h);
D 5
	flags = (*afswitch[af].af_checkhost)(dst) ? RTF_HOST : 0;
E 5
I 5
D 14
	flags = (*afswitch[af].af_ishost)(dst) ? RTF_HOST : 0;
E 14
I 14
	flags = (*afswitch[af].af_rtflags)(dst);
	/*
	 * Subnet flag isn't visible to kernel, move to state.	XXX
	 */
	if (flags & RTF_SUBNET) {
		state |= RTS_SUBNET;
		flags &= ~RTF_SUBNET;
	}
E 14
E 5
	if (flags & RTF_HOST) {
		hash = h.afh_hosthash;
D 8
		rh = &hosthash[hash % ROUTEHASHSIZ];
E 8
I 8
		rh = &hosthash[hash & ROUTEHASHMASK];
E 8
	} else {
		hash = h.afh_nethash;
D 8
		rh = &nethash[hash % ROUTEHASHSIZ];
E 8
I 8
		rh = &nethash[hash & ROUTEHASHMASK];
E 8
	}
	rt = (struct rt_entry *)malloc(sizeof (*rt));
	if (rt == 0)
		return;
	rt->rt_hash = hash;
	rt->rt_dst = *dst;
	rt->rt_router = *gate;
D 18
	rt->rt_metric = metric;
E 18
	rt->rt_timer = 0;
	rt->rt_flags = RTF_UP | flags;
	rt->rt_state = state | RTS_CHANGED;
D 14
	rt->rt_ifp = if_ifwithnet(&rt->rt_router);
E 14
I 14
	rt->rt_ifp = if_ifwithdstaddr(&rt->rt_router);
	if (rt->rt_ifp == 0)
		rt->rt_ifp = if_ifwithnet(&rt->rt_router);
E 14
D 18
	if (metric)
E 18
I 18
D 19
	if (rt->rt_ifp == 0) {
		if (dst->sa_family < af_max && gate->sa_family < af_max)
			syslog(LOG_ERR,
		   "route to net/host %s goes through unreachable gateway %s\n",
			   (*afswitch[dst->sa_family].af_format)(dst),
			   (*afswitch[gate->sa_family].af_format)(gate));
		free((char *)rt);
		return;
	}
E 19
I 19
D 21
	if (rt->rt_ifp)
		ifmetric = rt->rt_ifp->int_metric;
	else
		ifmetric = 0;
E 21
E 19
	if ((state & RTS_INTERFACE) == 0)
E 18
		rt->rt_flags |= RTF_GATEWAY;
I 18
D 21
	/*
	 * Set rt_ifmetric to the amount by which we
	 * increment the route when sending it to others.
	 */
	if (state & RTS_INTERFACE) {
		rt->rt_metric = 0;
		rt->rt_ifmetric = metric + 1;
	} else {
		rt->rt_metric = metric;
D 19
		rt->rt_ifmetric = rt->rt_ifp->int_metric + 1;
E 19
I 19
		rt->rt_ifmetric = ifmetric + 1;
E 19
	}
E 21
I 21
	rt->rt_metric = metric;
E 21
E 18
	insque(rt, rh);
D 23
	TRACE_ACTION(ADD, rt);
E 23
I 23
	TRACE_ACTION("ADD", rt);
E 23
D 4
	if (install && ioctl(s, SIOCADDRT, (char *)&rt->rt_rt) < 0)
E 4
I 4
	/*
	 * If the ioctl fails because the gateway is unreachable
	 * from this host, discard the entry.  This should only
	 * occur because of an incorrect entry in /etc/gateways.
	 */
D 14
	if (install && ioctl(s, SIOCADDRT, (char *)&rt->rt_rt) < 0) {
E 14
I 14
	if (install && (rt->rt_state & (RTS_INTERNAL | RTS_EXTERNAL)) == 0 &&
	    ioctl(s, SIOCADDRT, (char *)&rt->rt_rt) < 0) {
I 19
D 21
		if (errno != EEXIST &&
		    dst->sa_family < af_max && gate->sa_family < af_max)
E 21
I 21
		if (errno != EEXIST && gate->sa_family < af_max)
E 21
			syslog(LOG_ERR,
			"adding route to net/host %s through gateway %s: %m\n",
			   (*afswitch[dst->sa_family].af_format)(dst),
			   (*afswitch[gate->sa_family].af_format)(gate));
E 19
E 14
E 4
		perror("SIOCADDRT");
I 4
		if (errno == ENETUNREACH) {
D 23
			TRACE_ACTION(DELETE, rt);
E 23
I 23
			TRACE_ACTION("DELETE", rt);
E 23
			remque(rt);
			free((char *)rt);
		}
	}
E 4
}

rtchange(rt, gate, metric)
	struct rt_entry *rt;
	struct sockaddr *gate;
	short metric;
{
D 17
	int doioctl = 0, metricchanged = 0;
E 17
I 17
D 21
	int doioctl = 0, metricchanged = 0, delete = 0;
E 21
I 21
D 23
	int add = 0, delete = 0, metricchanged = 0;
E 23
I 23
	int add = 0, delete = 0;
E 23
E 21
E 17
	struct rtentry oldroute;
I 6
D 7
#define	NDEBUG
#ifdef	NDEBUG
	int turntraceoff = 0;
#endif
E 7
E 6

D 14
	if (!equal(&rt->rt_router, gate))
E 14
I 14
D 21
	if (!equal(&rt->rt_router, gate) && (rt->rt_state & RTS_INTERNAL) == 0)
E 14
		doioctl++;
D 6
	if (metric != rt->rt_metric) {
E 6
I 6
D 17
	if (metric != rt->rt_metric)
E 17
I 17
	if (metric != rt->rt_metric) {
E 17
E 6
		metricchanged++;
I 17
		if (metric == HOPCNT_INFINITY)
E 21
I 21
	if ((rt->rt_state & RTS_INTERNAL) == 0) {
		/*
		 * If changing to different router, we need to add
		 * new route and delete old one if in the kernel.
		 * If the router is the same, we need to delete
		 * the route if has become unreachable, or re-add
		 * it if it had been unreachable.
		 */
		if (!equal(&rt->rt_router, gate)) {
			add++;
			if (rt->rt_metric != HOPCNT_INFINITY)
				delete++;
		} else if (metric == HOPCNT_INFINITY)
E 21
			delete++;
I 21
		else if (rt->rt_metric == HOPCNT_INFINITY)
			add++;
E 21
	}
E 17
D 6
		rt->rt_metric = metric;
	}
E 6
D 21
	if (doioctl || metricchanged) {
E 21
I 21
D 23
	if (metric != rt->rt_metric)
		metricchanged++;
	if (delete || metricchanged)
E 21
D 6
		TRACE_ACTION(CHANGE, rt);
E 6
I 6
D 7
#ifdef	NDEBUG
		if (rt->rt_state & RTS_INTERFACE) {
		    if (!tracing) {
			traceon("/usr/adm/routed.log");
			turntraceoff = 1;
			fprintf(ftrace, "**** Changing route from interface\n");
			fprintf(ftrace, "rt_timer = %d\n", rt->rt_timer);
		    }
		}
#endif
E 7
		TRACE_ACTION(CHANGE FROM, rt);
E 23
I 23
	if (!equal(&rt->rt_router, gate)) {
		TRACE_ACTION("CHANGE FROM ", rt);
	} else if (metric != rt->rt_metric)
		TRACE_NEWMETRIC(rt, metric);
	if (delete)
		oldroute = rt->rt_rt;
E 23
I 16
D 18
		if ((rt->rt_state & RTS_INTERFACE) && metric) {
E 18
I 18
D 21
		if ((rt->rt_state & RTS_INTERFACE) &&
		    metric > rt->rt_ifp->int_metric) {
E 18
			rt->rt_state &= ~RTS_INTERFACE;
E 21
I 21
	if ((rt->rt_state & RTS_INTERFACE) && delete) {
		rt->rt_state &= ~RTS_INTERFACE;
D 23
		if (add)
E 21
I 18
			rt->rt_flags |= RTF_GATEWAY;
I 21
		if (metric > rt->rt_metric && delete &&
		    (rt->rt_state & RTS_INTERNAL) == 0)
E 21
E 18
			syslog(LOG_ERR,
				"changing route from interface %s (timed out)",
				rt->rt_ifp->int_name);
E 23
I 23
		rt->rt_flags |= RTF_GATEWAY;
		if (metric > rt->rt_metric && delete)
			syslog(LOG_ERR, "%s route to interface %s (timed out)",
			    add? "changing" : "deleting",
			    rt->rt_ifp->int_name);
E 23
D 21
		}
E 16
D 18
		if (doioctl) {
E 18
I 18
D 20
		if (doioctl || delete) {
E 20
I 20
		if (doioctl || delete)
E 20
E 18
			oldroute = rt->rt_rt;
I 20
		if (doioctl) {
E 20
			rt->rt_router = *gate;
I 14
			rt->rt_ifp = if_ifwithdstaddr(&rt->rt_router);
			if (rt->rt_ifp == 0)
				rt->rt_ifp = if_ifwithnet(&rt->rt_router);
E 14
		}
		rt->rt_metric = metric;
D 10
		rt->rt_state &= ~RTS_INTERFACE;
E 10
I 10
D 16
		if ((rt->rt_state & RTS_INTERFACE) && metric) {
			rt->rt_state &= ~RTS_INTERFACE;
			syslog(LOG_ERR,
D 11
				"deleting route to interface %s (timed out)",
E 11
I 11
				"changing route from interface %s (timed out)",
E 11
				rt->rt_ifp->int_name);
		}
E 16
E 10
D 18
		if (metric)
D 11
			rt->rt_state |= RTF_GATEWAY;
E 11
I 11
			rt->rt_flags |= RTF_GATEWAY;
		else
			rt->rt_flags &= ~RTF_GATEWAY;
E 18
E 11
E 6
		rt->rt_state |= RTS_CHANGED;
I 6
		TRACE_ACTION(CHANGE TO, rt);
E 21
E 6
	}
D 6
	if (doioctl) {
		oldroute = rt->rt_rt;
		rt->rt_router = *gate;
		if (install) {
			if (ioctl(s, SIOCADDRT, (char *)&rt->rt_rt) < 0)
				perror("SIOCADDRT");
			if (ioctl(s, SIOCDELRT, (char *)&oldroute) < 0)
				perror("SIOCDELRT");
		}
E 6
I 6
D 17
	if (doioctl && install) {
E 17
I 17
D 21
	if (doioctl && install)
E 21
I 21
D 23
	if (delete)
		oldroute = rt->rt_rt;
E 23
	if (add) {
		rt->rt_router = *gate;
		rt->rt_ifp = if_ifwithdstaddr(&rt->rt_router);
		if (rt->rt_ifp == 0)
			rt->rt_ifp = if_ifwithnet(&rt->rt_router);
	}
	rt->rt_metric = metric;
	rt->rt_state |= RTS_CHANGED;
D 23
	if (add || metricchanged)
		TRACE_ACTION(CHANGE TO, rt);
E 23
I 23
	if (add)
		TRACE_ACTION("CHANGE TO   ", rt);
E 23
	if (add && install)
E 21
E 17
		if (ioctl(s, SIOCADDRT, (char *)&rt->rt_rt) < 0)
			perror("SIOCADDRT");
I 17
D 21
	if ((doioctl || delete) && install)
E 21
I 21
	if (delete && install)
E 21
E 17
		if (ioctl(s, SIOCDELRT, (char *)&oldroute) < 0)
			perror("SIOCDELRT");
E 6
D 17
	}
E 17
I 6
D 7
#ifdef	NDEBUG
	if (turntraceoff)
		traceoff();
#endif
E 7
E 6
}

rtdelete(rt)
	struct rt_entry *rt;
{
I 4

I 10
D 21
	if (rt->rt_state & RTS_INTERFACE)
E 21
I 21
D 23
	if ((rt->rt_state & (RTS_INTERFACE|RTS_INTERNAL)) == RTS_INTERFACE)
E 21
		syslog(LOG_ERR, "deleting route to interface %s (timed out)",
			rt->rt_ifp->int_name);
E 10
E 4
	TRACE_ACTION(DELETE, rt);
D 14
	if (install && ioctl(s, SIOCDELRT, (char *)&rt->rt_rt))
E 14
I 14
D 15
	if (install && (rt->rt_state & (RTS_INTERNAL | RTS_EXTERNAL) == 0) &&
E 15
I 15
	if (install && (rt->rt_state & (RTS_INTERNAL | RTS_EXTERNAL)) == 0 &&
I 17
D 18
	    rt->rt_metric != HOPCNT_INFINITY &&
E 18
E 17
E 15
	    ioctl(s, SIOCDELRT, (char *)&rt->rt_rt))
E 14
		perror("SIOCDELRT");
E 23
I 23
	TRACE_ACTION("DELETE", rt);
	if (rt->rt_metric < HOPCNT_INFINITY) {
	    if ((rt->rt_state & (RTS_INTERFACE|RTS_INTERNAL)) == RTS_INTERFACE)
		syslog(LOG_ERR,
		    "deleting route to interface %s? (timed out?)",
		    rt->rt_ifp->int_name);
	    if (install &&
		(rt->rt_state & (RTS_INTERNAL | RTS_EXTERNAL)) == 0 &&
		ioctl(s, SIOCDELRT, (char *)&rt->rt_rt))
		    perror("SIOCDELRT");
	}
E 23
	remque(rt);
	free((char *)rt);
I 21
}

rtdeleteall(s)
	int s;
{
	register struct rthash *rh;
	register struct rt_entry *rt;
	struct rthash *base = hosthash;
	int doinghost = 1;

again:
	for (rh = base; rh < &base[ROUTEHASHSIZ]; rh++) {
		rt = rh->rt_forw;
		for (; rt != (struct rt_entry *)rh; rt = rt->rt_forw) {
D 23
			if (rt->rt_state & RTS_INTERFACE)
E 23
I 23
			if (rt->rt_state & RTS_INTERFACE ||
			    rt->rt_metric >= HOPCNT_INFINITY)
E 23
				continue;
D 23
			TRACE_ACTION(DELETE, rt);
E 23
I 23
			TRACE_ACTION("DELETE", rt);
E 23
			if ((rt->rt_state & (RTS_INTERNAL|RTS_EXTERNAL)) == 0 &&
			    ioctl(s, SIOCDELRT, (char *)&rt->rt_rt))
				perror("SIOCDELRT");
		}
	}
	if (doinghost) {
		doinghost = 0;
		base = nethash;
		goto again;
	}
D 23
	hup(s);
E 23
I 23
	exit(s);
E 23
E 21
I 7
}

/*
 * If we have an interface to the wide, wide world,
 * add an entry for an Internet default route (wildcard) to the internal
 * tables and advertise it.  This route is not added to the kernel routes,
 * but this entry prevents us from listening to other people's defaults
 * and installing them in the kernel here.
 */
rtdefault()
{
D 14
	struct afhash h;
	register struct rt_entry *rt;
	struct rthash *rh;
E 14
	extern struct sockaddr inet_default;

D 14
	rt = (struct rt_entry *)malloc(sizeof (*rt));
	if (rt == 0)
		return;
D 9
	rt->rt_hash = h.afh_nethash;
E 9
	rt->rt_dst = inet_default;
	rt->rt_router = rt->rt_dst;
	(*afswitch[AF_INET].af_hash)(&rt->rt_dst, &h);
D 8
	rh = &nethash[h.afh_nethash % ROUTEHASHSIZ];
E 8
I 8
	rh = &nethash[h.afh_nethash & ROUTEHASHMASK];
I 9
	rt->rt_hash = h.afh_nethash;
E 9
E 8
	rt->rt_metric = 0;
	rt->rt_timer = 0;
	rt->rt_flags = RTF_UP | RTF_GATEWAY;
	rt->rt_state = RTS_CHANGED | RTS_PASSIVE;
	rt->rt_ifp = 0;
	insque(rt, rh);
	TRACE_ACTION(ADD, rt);
E 14
I 14
D 24
	rtadd(&inet_default, &inet_default, 0,
E 24
I 24
	rtadd(&inet_default, &inet_default, 1,
E 24
		RTS_CHANGED | RTS_PASSIVE | RTS_INTERNAL);
E 14
E 7
}

rtinit()
{
	register struct rthash *rh;

	for (rh = nethash; rh < &nethash[ROUTEHASHSIZ]; rh++)
		rh->rt_forw = rh->rt_back = (struct rt_entry *)rh;
	for (rh = hosthash; rh < &hosthash[ROUTEHASHSIZ]; rh++)
		rh->rt_forw = rh->rt_back = (struct rt_entry *)rh;
}
E 1
