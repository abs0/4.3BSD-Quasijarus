h15925
s 00009/00003/00184
d D 5.6 88/02/16 18:50:48 bostic 9 8
c add Berkeley specific headers
e
s 00004/00004/00183
d D 5.5 87/05/28 11:26:05 karels 8 7
c rework interface metrics to invert perspective; other misc. fixes
e
s 00019/00010/00168
d D 5.4 86/06/03 16:32:21 karels 7 6
c try again; can't block subnet 0 with internal "network" route
e
s 00022/00011/00156
d D 5.3 86/05/30 13:56:11 karels 6 5
c don't send net route to subnet gw's unless on subnet 0;
c a few checks for imposters; bug fix in "external" route configuration;
c rm loopback net defn.
e
s 00065/00000/00102
d D 5.2 86/04/20 23:34:04 karels 5 4
c changes to allow subnets to remain local, propogate net route
c where subnets don't go, and allow external routes from /etc/gateways
c to block routed from installing routes from elsewhere
e
s 00009/00002/00093
d D 5.1 85/06/04 16:35:15 dist 4 3
c Add copyright
e
s 00040/00062/00055
d D 4.3 85/06/03 09:50:20 karels 3 2
c new subnets
e
s 00052/00035/00065
d D 4.2 84/05/01 13:30:59 karels 2 1
c efficiency, corresponds with kernel again
e
s 00100/00000/00000
d D 4.1 84/04/16 08:52:57 karels 1 0
c date and time created 84/04/16 08:52:57 by karels
e
u
U
t
T
I 4
/*
 * Copyright (c) 1983 Regents of the University of California.
D 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 9
I 9
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
 */

E 4
I 1
#ifndef lint
D 4
static char *sccsid[] = "%W% (Berkeley) %G%";
#endif
E 4
I 4
static char sccsid[] = "%W% (Berkeley) %G%";
D 9
#endif not lint
E 9
I 9
#endif /* not lint */
E 9

E 4
/*
 * Temporarily, copy these routines from the kernel,
 * as we need to know about subnets.
 */
#include "defs.h"

I 3
extern struct interface *ifnet;

E 3
/*
D 3
 * Formulate an Internet address from network + host.  Used in
 * building addresses stored in the ifnet structure.
E 3
I 3
 * Formulate an Internet address from network + host.
E 3
 */
struct in_addr
D 3
if_makeaddr(net, host)
	int net, host;
E 3
I 3
inet_makeaddr(net, host)
	u_long net, host;
E 3
{
I 3
	register struct interface *ifp;
	register u_long mask;
E 3
	u_long addr;

D 3
	if (net < IN_CLASSA_MAX)
		addr = (net << IN_CLASSA_NSHIFT) | host;
	else if (net < IN_CLASSB_MAX)
		addr = (net << IN_CLASSB_NSHIFT) | host;
E 3
I 3
	if (IN_CLASSA(net))
		mask = IN_CLASSA_HOST;
	else if (IN_CLASSB(net))
		mask = IN_CLASSB_HOST;
E 3
	else
D 3
		addr = (net << IN_CLASSC_NSHIFT) | host;
E 3
I 3
		mask = IN_CLASSC_HOST;
	for (ifp = ifnet; ifp; ifp = ifp->int_next)
		if ((ifp->int_netmask & net) == ifp->int_net) {
			mask = ~ifp->int_subnetmask;
			break;
		}
	addr = net | (host & mask);
E 3
	addr = htonl(addr);
	return (*(struct in_addr *)&addr);
}

/*
 * Return the network number from an internet address.
 */
inet_netof(in)
	struct in_addr in;
{
	register u_long i = ntohl(in.s_addr);
D 2
	register net;
E 2
I 2
D 3
	register u_long net, subnet;
E 3
I 3
	register u_long net;
E 3
	register struct interface *ifp;
D 3
	extern struct interface *ifnet;
E 3
E 2

D 3
	if (IN_CLASSA(i)) {
D 2
		net = ((i)&IN_CLASSA_NET) >> IN_CLASSA_NSHIFT;
		if (IN_SUBNETA(i) && inet_localnet(net))
			return (((i)&IN_CLASSA_SUBNET) >> IN_CLASSA_SUBNSHIFT);
		else
E 2
I 2
		net = (i & IN_CLASSA_NET) >> IN_CLASSA_NSHIFT;
		if (IN_SUBNETA(i)) {
			subnet = (i & IN_CLASSA_SUBNET) >> IN_CLASSA_SUBNSHIFT;
			/* Fall through and check whether a subnet */
		} else
E 2
			return (net);
	} else if (IN_CLASSB(i)) {
D 2
		net = ((i)&IN_CLASSB_NET) >> IN_CLASSB_NSHIFT;
		if (IN_SUBNETB(i) && inet_localnet(net))
			return (((i)&IN_CLASSB_SUBNET) >> IN_CLASSB_SUBNSHIFT);
		else
E 2
I 2
		net = (i & IN_CLASSB_NET) >> IN_CLASSB_NSHIFT;
		if (IN_SUBNETB(i)) {
			subnet = (i & IN_CLASSB_SUBNET) >> IN_CLASSB_SUBNSHIFT;
			/* Fall through and check whether a subnet */
		} else
E 2
			return (net);
	} else {
D 2
		return (((i)&IN_CLASSC_NET) >> IN_CLASSC_NSHIFT);
E 2
I 2
		return ((i & IN_CLASSC_NET) >> IN_CLASSC_NSHIFT);
E 2
	}
E 3
I 3
	if (IN_CLASSA(i))
		net = i & IN_CLASSA_NET;
	else if (IN_CLASSB(i))
		net = i & IN_CLASSB_NET;
	else
		net = i & IN_CLASSC_NET;
E 3
I 2

	/*
D 3
	 * Check whether network is a subnet of a `local' network;
E 3
I 3
	 * Check whether network is a subnet;
E 3
	 * if so, return subnet number.
	 */
D 3
	for (ifp = ifnet; ifp; ifp = ifp->int_next) {
		if (ifp->int_flags & IFF_LOCAL) {
			if (ifp->int_net == net)
				return (subnet);
			if ((ifp->int_net >> SUBNETSHIFT) == net)
				return (subnet);
		}
	}
E 3
I 3
	for (ifp = ifnet; ifp; ifp = ifp->int_next)
		if ((ifp->int_netmask & net) == ifp->int_net)
			return (i & ifp->int_subnetmask);
E 3
	return (net);
E 2
}

/*
 * Return the host portion of an internet address.
 */
inet_lnaof(in)
	struct in_addr in;
{
	register u_long i = ntohl(in.s_addr);
I 2
D 3
	register u_long net, host, subhost;
E 3
I 3
	register u_long net, host;
E 3
	register struct interface *ifp;
E 2

	if (IN_CLASSA(i)) {
D 2
		if (IN_SUBNETA(i) &&
		    inet_localnet(((i)&IN_CLASSA_NET) >> IN_CLASSA_NSHIFT))
			return ((i)&IN_CLASSA_SUBHOST);
		else
			return ((i)&IN_CLASSA_HOST);
E 2
I 2
D 3
		if (IN_SUBNETA(i)) {
			net = (i & IN_CLASSA_NET) >> IN_CLASSA_NSHIFT;
			host = i & IN_CLASSA_HOST;
			subhost = i & IN_CLASSA_SUBHOST;
			/* Fall through and check whether a subnet */
		} else
			return (i & IN_CLASSA_HOST);
E 3
I 3
		net = i & IN_CLASSA_NET;
		host = i & IN_CLASSA_HOST;
E 3
E 2
	} else if (IN_CLASSB(i)) {
D 2
		if (IN_SUBNETB(i) &&
		    inet_localnet(((i)&IN_CLASSB_NET) >> IN_CLASSB_NSHIFT))
			return ((i)&IN_CLASSB_SUBHOST);
		else
			return ((i)&IN_CLASSB_HOST);
E 2
I 2
D 3
		if (IN_SUBNETB(i)) {
			net = (i & IN_CLASSB_NET) >> IN_CLASSB_NSHIFT;
			host = i & IN_CLASSB_HOST;
			subhost = i & IN_CLASSB_SUBHOST;
			/* Fall through and check whether a subnet */
		} else
			return (i & IN_CLASSB_HOST);
E 3
I 3
		net = i & IN_CLASSB_NET;
		host = i & IN_CLASSB_HOST;
E 3
E 2
	} else {
D 2
		return ((i)&IN_CLASSC_HOST);
E 2
I 2
D 3
		return (i & IN_CLASSC_HOST);
E 3
I 3
		net = i & IN_CLASSC_NET;
		host = i & IN_CLASSC_HOST;
E 3
E 2
	}
D 2
}
E 2

D 2
/*
 * Return true if the network is a ``local'' net
 * (one for which we can interpret the host part).
 */
inet_localnet(net)
	register int net;
{
	register struct interface *ifp;
	extern struct interface *ifnet;

E 2
I 2
	/*
D 3
	 * Check whether network is a subnet of a `local' network;
E 3
I 3
	 * Check whether network is a subnet;
E 3
	 * if so, use the modified interpretation of `host'.
	 */
E 2
D 3
	for (ifp = ifnet; ifp; ifp = ifp->int_next) {
		if (ifp->int_flags & IFF_LOCAL) {
			if (ifp->int_net == net)
D 2
				return (1);
E 2
I 2
				return (subhost);
E 2
			if ((ifp->int_net >> SUBNETSHIFT) == net)
D 2
				return (1);
E 2
I 2
				return (subhost);
E 2
		}
	}
E 3
I 3
	for (ifp = ifnet; ifp; ifp = ifp->int_next)
		if ((ifp->int_netmask & net) == ifp->int_net)
			return (host &~ ifp->int_subnetmask);
E 3
D 2
	return (0);
E 2
I 2
	return (host);
E 2
}
I 5

/*
 * Return RTF_HOST if the address is
 * for an Internet host, RTF_SUBNET for a subnet,
 * 0 for a network.
 */
inet_rtflags(sin)
	struct sockaddr_in *sin;
{
	register u_long i = ntohl(sin->sin_addr.s_addr);
	register u_long net, host;
	register struct interface *ifp;

	if (IN_CLASSA(i)) {
		net = i & IN_CLASSA_NET;
		host = i & IN_CLASSA_HOST;
	} else if (IN_CLASSB(i)) {
		net = i & IN_CLASSB_NET;
		host = i & IN_CLASSB_HOST;
	} else {
		net = i & IN_CLASSC_NET;
		host = i & IN_CLASSC_HOST;
	}

D 7
	if (host == 0)
		return (0);	/* network */
E 7
	/*
	 * Check whether this network is subnetted;
	 * if so, check whether this is a subnet or a host.
	 */
	for (ifp = ifnet; ifp; ifp = ifp->int_next)
		if (net == ifp->int_net) {
D 7
			if ((host &~ ifp->int_subnetmask) == 0)
E 7
I 7
			if (host &~ ifp->int_subnetmask)
				return (RTF_HOST);
			else if (ifp->int_subnetmask != ifp->int_netmask)
E 7
				return (RTF_SUBNET);
			else
D 7
				return (RTF_HOST);
E 7
I 7
				return (0);		/* network */
E 7
		}
D 7
	return (RTF_HOST);
E 7
I 7
	if (host == 0)
		return (0);	/* network */
	else
		return (RTF_HOST);
E 7
}

/*
D 7
 * Return true if a route to subnet rtsin should be sent to dst.
E 7
I 7
D 8
 * Return true if a route to subnet of route rt should be sent to dst.
E 7
 * Send it only if dst is on the same logical network,
D 7
 * or the route turns out to be for the net (aka subnet 0).
E 7
I 7
 * or the route is the "internal" route for the net.
E 8
I 8
 * Return true if a route to subnet/host of route rt should be sent to dst.
 * Send it only if dst is on the same logical network if not "internal",
 * otherwise only if the route is the "internal" route for the logical net.
E 8
E 7
 */
D 6
inet_sendsubnet(rtsin, dst)
	struct sockaddr_in *rtsin, *dst;
E 6
I 6
D 8
inet_sendsubnet(rt, dst)
E 8
I 8
inet_sendroute(rt, dst)
E 8
	struct rt_entry *rt;
	struct sockaddr_in *dst;
E 6
{
D 6
	register u_long rt = ntohl(rtsin->sin_addr.s_addr);
E 6
I 6
	register u_long r =
	    ntohl(((struct sockaddr_in *)&rt->rt_dst)->sin_addr.s_addr);
E 6
	register u_long d = ntohl(dst->sin_addr.s_addr);

D 6
	if (IN_CLASSA(rt)) {
		if ((rt & IN_CLASSA_HOST) == 0)
E 6
I 6
	if (IN_CLASSA(r)) {
		if ((r & IN_CLASSA_NET) == (d & IN_CLASSA_NET)) {
			if ((r & IN_CLASSA_HOST) == 0)
				return ((rt->rt_state & RTS_INTERNAL) == 0);
E 6
			return (1);
D 6
		return ((rt & IN_CLASSA_NET) == (d & IN_CLASSA_NET));
	} else if (IN_CLASSB(rt)) {
		if ((rt & IN_CLASSB_HOST) == 0)
E 6
I 6
		}
D 7
		return ((r & IN_CLASSA_HOST) == 0);
E 7
I 7
		if (r & IN_CLASSA_HOST)
			return (0);
		return ((rt->rt_state & RTS_INTERNAL) != 0);
E 7
	} else if (IN_CLASSB(r)) {
		if ((r & IN_CLASSB_NET) == (d & IN_CLASSB_NET)) {
			if ((r & IN_CLASSB_HOST) == 0)
				return ((rt->rt_state & RTS_INTERNAL) == 0);
E 6
			return (1);
D 6
		return ((rt & IN_CLASSB_NET) == (d & IN_CLASSB_NET));
E 6
I 6
		}
D 7
		return ((r & IN_CLASSB_HOST) == 0);
E 7
I 7
		if (r & IN_CLASSB_HOST)
			return (0);
		return ((rt->rt_state & RTS_INTERNAL) != 0);
E 7
E 6
	} else {
D 6
		if ((rt & IN_CLASSC_HOST) == 0)
E 6
I 6
		if ((r & IN_CLASSC_NET) == (d & IN_CLASSC_NET)) {
			if ((r & IN_CLASSC_HOST) == 0)
				return ((rt->rt_state & RTS_INTERNAL) == 0);
E 6
			return (1);
D 6
		return ((rt & IN_CLASSC_NET) == (d & IN_CLASSC_NET));
E 6
I 6
		}
D 7
		return ((r & IN_CLASSC_HOST) == 0);
E 7
I 7
		if (r & IN_CLASSC_HOST)
			return (0);
		return ((rt->rt_state & RTS_INTERNAL) != 0);
E 7
E 6
	}
}
E 5
E 1
