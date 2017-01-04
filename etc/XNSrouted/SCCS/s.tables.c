h09810
s 00009/00005/00213
d D 5.6 86/12/30 14:36:37 karels 6 5
c don't print useless messages
e
s 00015/00004/00203
d D 5.5 86/02/14 18:28:32 sklower 5 4
c 1.) Fixes from Nesheim viz pt to pt timeouts;
c 2.) Getting rid of ns_netof, to make common for Gould, CCI
e
s 00004/00004/00203
d D 5.4 85/09/17 21:42:13 sklower 4 3
c latest changes from nesheim@cornell:
c use syslog instead of perror, ignore remote requests unless specifically asked,
c handle requests from net 0.
e
s 00014/00005/00193
d D 5.3 85/08/16 21:49:22 sklower 3 2
c This version Aug 16th -- source directory moved to /usr/src/etc/XNSrouted;
c includes fix to response to request for specific net, and adds copyright notices
e
s 00006/00011/00192
d D 5.2 85/08/16 20:44:10 sklower 2 1
c status as of 4.3 alpha tape
e
s 00203/00000/00000
d D 5.1 85/08/16 20:22:53 sklower 1 0
c date and time created 85/08/16 20:22:53 by sklower
e
u
U
t
T
I 3
/*
 * Copyright (c) 1985 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 */


E 3
I 1
#ifndef lint
D 3
static char rcsid[] = "$Header$";
#endif
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 3

/*
 * Routing Table Management Daemon
 */
#include "defs.h"
#include <sys/ioctl.h>
#include <errno.h>

#ifndef DEBUG
#define	DEBUG	0
#endif

I 6
extern	char *xns_ntoa();

E 6
int	install = !DEBUG;		/* if 1 call kernel */
D 2
static  int	s;			/* for routing table ioctl's */
E 2
I 2
int	delete = 1;
E 2
/*
 * Lookup dst in the tables for an exact match.
 */
struct rt_entry *
rtlookup(dst)
	struct sockaddr *dst;
{
	register struct rt_entry *rt;
	register struct rthash *rh;
	register u_int hash;
	struct afhash h;
	int doinghost = 1;

	if (dst->sa_family >= AF_MAX)
		return (0);
	(*afswitch[dst->sa_family].af_hash)(dst, &h);
	hash = h.afh_hosthash;
	rh = &hosthash[hash & ROUTEHASHMASK];
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
		rh = &nethash[hash & ROUTEHASHMASK];
		goto again;
	}
	return (0);
}

/*
 * Find a route to dst as the kernel would.
 */
struct rt_entry *
rtfind(dst)
	struct sockaddr *dst;
{
	register struct rt_entry *rt;
	register struct rthash *rh;
	register u_int hash;
	struct afhash h;
	int af = dst->sa_family;
	int doinghost = 1, (*match)();

	if (af >= AF_MAX)
		return (0);
	(*afswitch[af].af_hash)(dst, &h);
	hash = h.afh_hosthash;
	rh = &hosthash[hash & ROUTEHASHMASK];

again:
	for (rt = rh->rt_forw; rt != (struct rt_entry *)rh; rt = rt->rt_forw) {
		if (rt->rt_hash != hash)
			continue;
		if (doinghost) {
			if (equal(&rt->rt_dst, dst))
				return (rt);
I 3
		} else {
			if (rt->rt_dst.sa_family == af &&
			    (*match)(&rt->rt_dst, dst))
				return (rt);
E 3
D 2
		} else {
			if (rt->rt_dst.sa_family == af &&
			    (*match)(&rt->rt_dst, dst))
				return (rt);
E 2
		}
I 2
D 3
		if (rt->rt_dst.sa_family == af &&
		    (*match)(&rt->rt_dst, dst))
			return (rt);
E 3
E 2
	}
	if (doinghost) {
		doinghost = 0;
		hash = h.afh_nethash;
		rh = &nethash[hash & ROUTEHASHMASK];
		match = afswitch[af].af_netmatch;
		goto again;
	}
	return (0);
}

rtadd(dst, gate, metric, state)
	struct sockaddr *dst, *gate;
	int metric, state;
{
	struct afhash h;
	register struct rt_entry *rt;
	struct rthash *rh;
	int af = dst->sa_family, flags;
	u_int hash;

	if (af >= AF_MAX)
		return;
	(*afswitch[af].af_hash)(dst, &h);
	flags = (*afswitch[af].af_ishost)(dst) ? RTF_HOST : 0;
	if (flags & RTF_HOST) {
		hash = h.afh_hosthash;
		rh = &hosthash[hash & ROUTEHASHMASK];
	} else {
		hash = h.afh_nethash;
		rh = &nethash[hash & ROUTEHASHMASK];
	}
	rt = (struct rt_entry *)malloc(sizeof (*rt));
	if (rt == 0)
		return;
	rt->rt_hash = hash;
	rt->rt_dst = *dst;
	rt->rt_router = *gate;
	rt->rt_metric = metric;
	rt->rt_timer = 0;
	rt->rt_flags = RTF_UP | flags;
	rt->rt_state = state | RTS_CHANGED;
	rt->rt_ifp = if_ifwithnet(&rt->rt_router);
	if (metric)
		rt->rt_flags |= RTF_GATEWAY;
	insque(rt, rh);
	TRACE_ACTION(ADD, rt);
	/*
	 * If the ioctl fails because the gateway is unreachable
	 * from this host, discard the entry.  This should only
	 * occur because of an incorrect entry in /etc/gateways.
	 */
	if (install && ioctl(s, SIOCADDRT, (char *)&rt->rt_rt) < 0) {
D 4
		perror("SIOCADDRT");
E 4
I 4
D 6
		syslog(LOG_ERR,"SIOCADDRT: %m");
E 6
I 6
		if (errno != EEXIST)
			perror("SIOCADDRT");
E 6
E 4
		if (errno == ENETUNREACH) {
			TRACE_ACTION(DELETE, rt);
			remque(rt);
			free((char *)rt);
		}
	}
}

rtchange(rt, gate, metric)
	struct rt_entry *rt;
	struct sockaddr *gate;
	short metric;
{
	int doioctl = 0, metricchanged = 0;
	struct rtentry oldroute;

	if (!equal(&rt->rt_router, gate))
		doioctl++;
	if (metric != rt->rt_metric)
		metricchanged++;
	if (doioctl || metricchanged) {
		TRACE_ACTION(CHANGE FROM, rt);
		if (doioctl) {
			oldroute = rt->rt_rt;
			rt->rt_router = *gate;
		}
		rt->rt_metric = metric;
D 5
		rt->rt_state &= ~RTS_INTERFACE;
E 5
I 5
		if ((rt->rt_state & RTS_INTERFACE) && metric) {
			rt->rt_state &= ~RTS_INTERFACE;
			syslog(LOG_ERR,
				"changing route from interface %s (timed out)",
				rt->rt_ifp->int_name);
		}
E 5
		if (metric)
D 5
			rt->rt_state |= RTF_GATEWAY;
E 5
I 5
			rt->rt_flags |= RTF_GATEWAY;
		else
			rt->rt_flags &= ~RTF_GATEWAY;
E 5
		rt->rt_state |= RTS_CHANGED;
		TRACE_ACTION(CHANGE TO, rt);
	}
	if (doioctl && install) {
		if (ioctl(s, SIOCADDRT, (char *)&rt->rt_rt) < 0)
D 4
			perror("SIOCADDRT");
E 4
I 4
D 6
			syslog(LOG_ERR,"SIOCADDRT %m");
E 4
I 2
		if (delete)
E 2
		if (ioctl(s, SIOCDELRT, (char *)&oldroute) < 0)
D 4
			perror("SIOCDELRT");
E 4
I 4
			syslog(LOG_ERR,"SIOCDELRT %m");
E 6
I 6
		  syslog(LOG_ERR, "SIOCADDRT dst %s, gw %s: %m",
		   xns_ntoa(&((struct sockaddr_ns *)&rt->rt_dst)->sns_addr),
		   xns_ntoa(&((struct sockaddr_ns *)&rt->rt_router)->sns_addr));
		if (delete && ioctl(s, SIOCDELRT, (char *)&oldroute) < 0)
			perror("SIOCDELRT");
E 6
E 4
	}
}

rtdelete(rt)
	struct rt_entry *rt;
{

I 5
	if (rt->rt_state & RTS_INTERFACE) {
		syslog(LOG_ERR, "deleting route to interface %s (timed out)",
			rt->rt_ifp->int_name);
	}
E 5
	TRACE_ACTION(DELETE, rt);
D 2
	if (install && ioctl(s, SIOCDELRT, (char *)&rt->rt_rt))
E 2
I 2
D 5
	if (install && delete && ioctl(s, SIOCDELRT, (char *)&rt->rt_rt))
E 2
D 4
		perror("SIOCDELRT");
E 4
I 4
		syslog(LOG_ERR,"SIOCDELR %m");
E 5
I 5
	if (install && ioctl(s, SIOCDELRT, (char *)&rt->rt_rt))
		perror("SIOCDELRT");
E 5
E 4
	remque(rt);
	free((char *)rt);
}

rtinit()
{
	register struct rthash *rh;

	for (rh = nethash; rh < &nethash[ROUTEHASHSIZ]; rh++)
		rh->rt_forw = rh->rt_back = (struct rt_entry *)rh;
	for (rh = hosthash; rh < &hosthash[ROUTEHASHSIZ]; rh++)
		rh->rt_forw = rh->rt_back = (struct rt_entry *)rh;
D 2
		
	if ((s = socket(AF_XNS, SOCK_RAW, IDPPROTO_RAW)) < 0) {
		perror("socket");
		exit(1);
	}
E 2
}
E 1
