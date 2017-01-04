h52937
s 00005/00005/00115
d D 5.5 86/02/14 18:28:10 sklower 5 4
c 1.) Fixes from Nesheim viz pt to pt timeouts;
c 2.) Getting rid of ns_netof, to make common for Gould, CCI
e
s 00012/00001/00108
d D 5.4 85/11/20 14:57:48 sklower 4 3
c Make changes to allow for split nets on pt to pt interfaces.
e
s 00021/00004/00088
d D 5.3 85/08/16 21:49:08 sklower 3 2
c This version Aug 16th -- source directory moved to /usr/src/etc/XNSrouted;
c includes fix to response to request for specific net, and adds copyright notices
e
s 00007/00007/00085
d D 5.2 85/08/16 20:43:56 sklower 2 1
c status as of 4.3 alpha tape
e
s 00092/00000/00000
d D 5.1 85/08/16 20:22:43 sklower 1 0
c date and time created 85/08/16 20:22:43 by sklower
e
u
U
t
T
I 4
/*
 * Copyright (c) 1985 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 * Includes material written at Cornell University by Bill Nesheim,
 * by permission of the author.
 */

E 4
I 1
#ifndef lint
D 4
static char sccsid[] = "@(#)output.c	4.5 (Berkeley) 4/9/84";
E 4
I 4
static char sccsid[] = "%W% (Berkeley) %G%";
E 4
#endif

/*
 * Routing Table Management Daemon
 */
#include "defs.h"

/*
 * Apply the function "f" to all non-passive
 * interfaces.  If the interface supports the
 * use of broadcasting use it, otherwise address
 * the output to the known router.
 */
toall(f)
	int (*f)();
{
	register struct interface *ifp;
	register struct sockaddr *dst;
	register int flags;
	extern struct interface *ifnet;

	for (ifp = ifnet; ifp; ifp = ifp->int_next) {
		if (ifp->int_flags & IFF_PASSIVE)
			continue;
		dst = ifp->int_flags & IFF_BROADCAST ? &ifp->int_broadaddr :
		      ifp->int_flags & IFF_POINTOPOINT ? &ifp->int_dstaddr :
		      &ifp->int_addr;
		flags = ifp->int_flags & IFF_INTERFACE ? MSG_DONTROUTE : 0;
		(*f)(dst, flags, ifp);
	}
}

/*
 * Output a preformed packet.
 */
/*ARGSUSED*/
sendmsg(dst, flags, ifp)
	struct sockaddr *dst;
	int flags;
	struct interface *ifp;
{

D 2
	(*afswitch[dst->sa_family].af_output)(ifp->int_ripsock[0], flags,
		dst, sizeof (struct rip));
E 2
I 2
	(*afswitch[dst->sa_family].af_output)
		(flags, dst, sizeof (struct rip));
E 2
	TRACE_OUTPUT(ifp, dst, sizeof (struct rip));
}

/*
 * Supply dst with the contents of the routing tables.
 * If this won't fit in one packet, chop it up into several.
 */
supply(dst, flags, ifp)
	struct sockaddr *dst;
	int flags;
	struct interface *ifp;
{
	register struct rt_entry *rt;
D 3
	struct netinfo *n = msg->rip_nets;
E 3
	register struct rthash *rh;
I 3
	register struct netinfo *nn;
	register struct netinfo *n = msg->rip_nets;
E 3
	struct rthash *base = hosthash;
D 3
	int doinghost = 1, size;
E 3
D 2
	struct sockaddr_xn *sxn =  (struct sockaddr_xn *) dst;
E 2
I 2
	struct sockaddr_ns *sns =  (struct sockaddr_ns *) dst;
E 2
	int (*output)() = afswitch[dst->sa_family].af_output;
I 3
	int doinghost = 1, size, metric;
D 5
	long net;
E 5
I 5
	union ns_net net;
E 5
E 3

	msg->rip_cmd = ntohs(RIPCMD_RESPONSE);
again:
	for (rh = base; rh < &base[ROUTEHASHSIZ]; rh++)
	for (rt = rh->rt_forw; rt != (struct rt_entry *)rh; rt = rt->rt_forw) {
		size = (char *)n - (char *)msg;
		if (size > MAXPACKETSIZE - sizeof (struct netinfo)) {
D 2
			(*output)(ifp->int_ripsock[0], flags, dst, size);
E 2
I 2
			(*output)(flags, dst, size);
E 2
			TRACE_OUTPUT(ifp, dst, size);
			n = msg->rip_nets;
		}
D 2
		sxn = (struct sockaddr_xn *)&rt->rt_dst;
		xnnet(n->rip_dst) = xnnet(((struct sockaddr_xn *)&rt->rt_dst)->sxn_addr.xn_net);
E 2
I 2
		sns = (struct sockaddr_ns *)&rt->rt_dst;
I 4
	        if ((rt->rt_flags & (RTF_HOST|RTF_GATEWAY)) == RTF_HOST)
			sns = (struct sockaddr_ns *)&rt->rt_router;
E 4
D 3
		xnnet(n->rip_dst[0]) = ns_netof(sns->sns_addr);
E 2
		n->rip_metric = htons(min(rt->rt_metric + 1, HOPCNT_INFINITY));
E 3
I 3
		metric = min(rt->rt_metric + 1, HOPCNT_INFINITY);
D 5
		net = ns_netof(sns->sns_addr);
E 5
I 5
		net = sns->sns_addr.x_net;
E 5
		/*
		 * Make sure that we don't put out a two net entries
		 * for a pt to pt link (one for the G route, one for the if)
		 * This is a kludge, and won't work if there are lots of nets.
		 */
		for (nn = msg->rip_nets; nn < n; nn++) {
D 5
			if(net == xnnet(nn->rip_dst[0])) {
				if(metric < ntohs(nn->rip_metric))
E 5
I 5
			if (ns_neteqnn(net, nn->rip_dst)) {
				if (metric < ntohs(nn->rip_metric))
E 5
					nn->rip_metric = htons(metric);
				goto next;
			}
		}
D 5
		xnnet(n->rip_dst[0]) = net;
E 5
I 5
		n->rip_dst = net;
E 5
		n->rip_metric = htons(metric);
E 3
		n++;
I 3
	next:;
E 3
	}
	if (doinghost) {
		doinghost = 0;
		base = nethash;
		goto again;
	}
	if (n != msg->rip_nets) {
		size = (char *)n - (char *)msg;
D 2
		(*output)(ifp->int_ripsock[0], flags, dst, size);
E 2
I 2
		(*output)(flags, dst, size);
E 2
		TRACE_OUTPUT(ifp, dst, size);
	}
}
E 1
