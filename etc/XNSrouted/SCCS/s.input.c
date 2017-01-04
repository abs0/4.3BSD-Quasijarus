h26293
s 00012/00010/00150
d D 5.6 86/02/14 18:27:52 sklower 7 6
c 1.) Fixes from Nesheim viz pt to pt timeouts;
c 2.) Getting rid of ns_netof, to make common for Gould, CCI
e
s 00001/00001/00159
d D 5.5 85/11/20 14:57:43 sklower 6 5
c Make changes to allow for split nets on pt to pt interfaces.
e
s 00005/00005/00155
d D 5.4 85/09/17 21:42:05 sklower 5 4
c latest changes from nesheim@cornell:
c use syslog instead of perror, ignore remote requests unless specifically asked,
c handle requests from net 0.
e
s 00040/00010/00120
d D 5.3 85/08/16 22:38:17 sklower 4 2
c This version Aug 16th -- source directory moved to /usr/src/etc/XNSrouted;
c includes fix to response to request for specific net, and adds copyright notices
e
s 00045/00010/00120
d R 5.3 85/08/16 21:48:53 sklower 3 2
c This version Aug 16th -- source directory moved to /usr/src/etc/XNSrouted;
c includes fix to response to request for specific net, and adds copyright notices
e
s 00024/00020/00106
d D 5.2 85/08/16 20:43:43 sklower 2 1
c status as of 4.3 alpha tape
e
s 00126/00000/00000
d D 5.1 85/08/16 20:22:38 sklower 1 0
c date and time created 85/08/16 20:22:38 by sklower
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
static char rcsid[] = "$Header$";
#endif
E 4
I 4
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 4

/*
 * XNS Routing Table Management Daemon
 */
#include "defs.h"

struct sockaddr *
xns_nettosa(net)
D 7
u_short *net;
E 7
I 7
union ns_net net;
E 7
{
D 2
	static struct sockaddr_xn sxn;
E 2
I 2
	static struct sockaddr_ns sxn;
	extern char ether_broadcast_addr[6];
E 2
	
D 2
	bzero(&sxn, sizeof (struct sockaddr_xn));
	sxn.sxn_family = AF_XNS;
	xnnet(sxn.sxn_addr.xn_net) = xnnet(net);
E 2
I 2
	bzero(&sxn, sizeof (struct sockaddr_ns));
	sxn.sns_family = AF_NS;
D 7
	xnnet(sxn.sns_addr.x_net) = xnnet(net[0]);
E 7
I 7
	sxn.sns_addr.x_net = net;
E 7
	sxn.sns_addr.x_host = *(union ns_host *)ether_broadcast_addr;
E 2
	return( (struct sockaddr *)&sxn);
	
}

/*
 * Process a newly received packet.
 */
rip_input(from, size)
	struct sockaddr *from;
	int size;
{
	struct rt_entry *rt;
	struct netinfo *n;
	struct interface *ifp;
	int newsize;
	struct afswitch *afp;

	
I 2
	ifp = 0;
E 2
	TRACE_INPUT(ifp, from, size);
	if (from->sa_family >= AF_MAX)
		return;
	afp = &afswitch[from->sa_family];
	
D 2
	/* are we talking to ourselves? */
	if (ifp = if_ifwithaddr(from)) {
		rt = rtfind(from);
		if (rt == 0 || (rt->rt_state & RTS_INTERFACE) == 0)
			addrouteforif(ifp);
		else
			rt->rt_timer = 0;
		return;
	}
	
E 2
	size -= sizeof (u_short)	/* command */;
	n = msg->rip_nets;

	switch (ntohs(msg->rip_cmd)) {

	case RIPCMD_REQUEST:
D 4
		/* Be quiet if we don't have anything interesting to talk about */
		if (!supplier) return;	
E 4
		newsize = 0;
		while (size > 0) {
			if (size < sizeof (struct netinfo))
				break;
			size -= sizeof (struct netinfo);

			/* 
			 * A single entry with rip_dst == DSTNETS_ALL and
			 * metric ``infinity'' means ``all routes''.
			 */
D 2
			if (ntohl(xnnet(n->rip_dst)) == DSTNETS_ALL &&
		            ntohs(n->rip_metric) == HOPCNT_INFINITY && size == 0) {
				if(ifp = if_ifwithnet(from))
				    supply(from, 0, ifp);
E 2
I 2
D 7
			if (ntohl(xnnet(n->rip_dst[0])) == DSTNETS_ALL &&
E 7
I 7
			if (ns_neteqnn(n->rip_dst, ns_anynet) &&
E 7
		            ntohs(n->rip_metric) == HOPCNT_INFINITY &&
			    size == 0) {
				ifp = if_ifwithnet(from);
				supply(from, 0, ifp);
E 2
				return;
			}
			/*
			 * request for specific nets
			 */
			rt = rtlookup(xns_nettosa(n->rip_dst));
I 4
D 5
			if (tracepackets > 1) {
E 5
I 5
			if (ftrace) {
E 5
				fprintf(ftrace,
D 7
					"specific request for %d",
					ntohl(xnnet(n->rip_dst[0])));
E 7
I 7
					"specific request for %s",
					xns_nettoa(n->rip_dst));
E 7
				fprintf(ftrace,
D 7
					"yields route %x",
E 7
I 7
					" yields route %x\n",
E 7
					rt);
			}
E 4
			n->rip_metric = htons( rt == 0 ? HOPCNT_INFINITY :
				min(rt->rt_metric+1, HOPCNT_INFINITY));
D 7
			n++, newsize += sizeof (struct netinfo);
E 7
I 7
			n++;
		        newsize += sizeof (struct netinfo);
E 7
		}
		if (newsize > 0) {
			msg->rip_cmd = htons(RIPCMD_RESPONSE);
			newsize += sizeof (u_short);
			/* should check for if with dstaddr(from) first */
D 4
			if(ifp = if_ifwithnet(from))
D 2
			    (*afp->af_output)(ifp->int_ripsock[0], 0, from, newsize);
E 2
I 2
			    (*afp->af_output)(0, from, newsize);
E 4
I 4
D 5
			(ifp = if_ifwithnet(from));
E 5
			(*afp->af_output)(0, from, newsize);
D 5
			if (tracepackets > 1) {
E 5
I 5
D 7
			(ifp = if_ifwithnet(from));
E 7
I 7
			ifp = if_ifwithnet(from);
			TRACE_OUTPUT(ifp, from, newsize);
E 7
			if (ftrace) {
E 5
				fprintf(ftrace,
D 7
					", request arriving on interface %x\n",
					ifp);
E 7
I 7
					"request arrived on interface %s\n",
					ifp->int_name);
E 7
			}
E 4
E 2
		}
		return;

	case RIPCMD_RESPONSE:
		/* verify message came from a router */
		if ((*afp->af_portmatch)(from) == 0)
			return;
I 2
		(*afp->af_canon)(from);
		/* are we talking to ourselves? */
		if (ifp = if_ifwithaddr(from)) {
			rt = rtfind(from);
			if (rt == 0 || (rt->rt_state & RTS_INTERFACE) == 0)
				addrouteforif(ifp);
			else
				rt->rt_timer = 0;
			return;
		}
E 2
D 4
		/* update timer for interface on which the packet arrived */
		if ((rt = rtfind(from)) && (rt->rt_state & RTS_INTERFACE))
E 4
I 4
		/* Update timer for interface on which the packet arrived.
		 * If from other end of a point-to-point link that isn't
		 * in the routing tables, (re-)add the route.
		 */
		if ((rt = rtfind(from)) && (rt->rt_state & RTS_INTERFACE)) {
D 5
			if(tracepackets > 1) fprintf(ftrace, "Got route\n");
E 5
I 5
			if(ftrace) fprintf(ftrace, "Got route\n");
E 5
E 4
			rt->rt_timer = 0;
I 4
		} else if (ifp = if_ifwithdstaddr(from)) {
D 5
			if(tracepackets > 1) fprintf(ftrace, "Got partner\n");
E 5
I 5
			if(ftrace) fprintf(ftrace, "Got partner\n");
E 5
			addrouteforif(ifp);
		}
E 4
		for (; size > 0; size -= sizeof (struct netinfo), n++) {
I 4
			struct sockaddr *sa;
E 4
			if (size < sizeof (struct netinfo))
				break;
D 6
			if ((unsigned) ntohs(n->rip_metric) > HOPCNT_INFINITY)
E 6
I 6
			if ((unsigned) ntohs(n->rip_metric) >= HOPCNT_INFINITY)
E 6
				continue;
D 2
			rt = rtlookup(xns_nettosa(n->rip_dst));
E 2
I 2
D 4
			rt = rtfind(xns_nettosa(n->rip_dst));
E 4
I 4
			rt = rtfind(sa = xns_nettosa(n->rip_dst));
E 4
E 2
			if (rt == 0) {
D 4
				rtadd(xns_nettosa(n->rip_dst), from, ntohs(n->rip_metric), 0);
E 4
I 4
				rtadd(sa, from, ntohs(n->rip_metric), 0);
E 4
				continue;
			}

			/*
			 * Update if from gateway and different,
			 * from anywhere and shorter, or getting stale and equivalent.
			 */
			if ((equal(from, &rt->rt_router) &&
			    ntohs(n->rip_metric) != rt->rt_metric ) ||
			    (unsigned) ntohs(n->rip_metric) < rt->rt_metric ||
			    (rt->rt_timer > (EXPIRE_TIME/2) &&
			    rt->rt_metric == ntohs(n->rip_metric))) {
				rtchange(rt, from, ntohs(n->rip_metric));
				rt->rt_timer = 0;
			}
		}
		return;
	}
}
E 1
