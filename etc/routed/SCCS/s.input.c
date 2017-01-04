h05926
s 00013/00001/00250
d D 5.17 88/06/06 16:16:24 karels 29 28
c missed a few: make default, local-loop routes have metric 1,
c as not incremented when sent; check for 0 on input (can't be right)
e
s 00022/00012/00229
d D 5.16 88/05/31 14:20:33 karels 28 27
c minor fixes, aborted changes, test for imposters claiming to be our
c loopback address
e
s 00009/00003/00232
d D 5.15 88/02/16 18:50:50 bostic 27 26
c add Berkeley specific headers
e
s 00004/00002/00231
d D 5.14 87/12/12 17:58:42 karels 26 25
c passive routes aren't trusted
e
s 00006/00006/00227
d D 5.13 87/06/15 15:35:29 karels 25 24
c watch out for metric > infinity
e
s 00025/00006/00208
d D 5.12 87/05/28 11:26:07 karels 24 23
c rework interface metrics to invert perspective; other misc. fixes
e
s 00001/00001/00213
d D 5.11 87/05/15 13:37:14 karels 23 22
c minor fixes
e
s 00005/00002/00209
d D 5.10 87/04/02 13:06:26 karels 22 21
c finish up interface metric code: store metric from our perspective,
c plus increment for those we send to; delete route from kernel when unreachable,
c but keep in tables to advertise deletion
e
s 00010/00002/00201
d D 5.9 86/11/03 11:49:43 karels 21 20
c fix tests for bogus routers to reject addresses on shared,
c non-broadcast, non-pt to pt network unless listed in /etc/gateways
e
s 00002/00001/00201
d D 5.8 86/11/02 19:52:40 karels 20 19
c lose the unreachables after one timeout
e
s 00009/00007/00193
d D 5.7 86/10/30 20:36:14 karels 19 18
c delay deletion from internal tables when cur router deletes
c (so can advertise deletion)
e
s 00003/00001/00197
d D 5.6 86/06/03 16:32:29 karels 18 17
c try again; can't block subnet 0 with internal "network" route
e
s 00016/00001/00182
d D 5.5 86/05/30 13:56:16 karels 17 16
c don't send net route to subnet gw's unless on subnet 0;
c a few checks for imposters; bug fix in "external" route configuration;
c rm loopback net defn.
e
s 00001/00001/00182
d D 5.4 86/04/20 23:34:08 karels 16 15
c changes to allow subnets to remain local, propogate net route
c where subnets don't go, and allow external routes from /etc/gateways
c to block routed from installing routes from elsewhere
e
s 00008/00004/00175
d D 5.3 86/03/10 20:13:54 karels 15 14
c don't call (null)->hash; if not supplying table dump to query for all,
c don't send anything
e
s 00027/00006/00152
d D 5.2 86/02/23 19:33:57 karels 14 13
c don't rely on AF_MAX (comes from kernel include): check for nil explicitly,
c use our own idea of table size.  Use syslog to (optionally) log bad packets.
c Don't respond to routing inquiries from a router unless we are suppliers
c (really want to respondto everything but broadcasts, but haven't got
c the "to" address.)
e
s 00007/00001/00151
d D 5.1 85/06/04 16:35:35 dist 13 12
c Add copyright
e
s 00012/00006/00140
d D 4.12 85/06/03 09:47:40 karels 12 11
c infinite hopcount means delete the route
e
s 00006/00004/00140
d D 4.11 85/02/25 11:22:38 karels 11 10
c reset timer when gateway is heard from
e
s 00007/00001/00137
d D 4.10 84/12/20 18:05:19 karels 10 9
c reinstall point-to-point interface when it reappears
e
s 00003/00000/00135
d D 4.9 84/07/24 09:05:25 karels 9 8
c check each route according to its address family, not the sender's
e
s 00004/00003/00131
d D 4.8 84/04/10 14:17:26 karels 8 7
c minor efficiency
e
s 00006/00003/00128
d D 4.7 84/04/09 15:05:12 karels 7 6
c many cleanups; avoid interface timing out; put it back asap
e
s 00004/00002/00127
d D 4.6 84/03/07 21:56:25 karels 6 5
c more consistency checks; watch those unsigned moduli
e
s 00000/00006/00129
d D 4.5 83/06/01 16:26:45 sam 5 4
c notyet has come
e
s 00022/00001/00113
d D 4.4 83/05/25 17:50:45 sam 4 3
c protocol change; byte swap those fields which need it;  also add 
c a version stamp to allow future changes
e
s 00001/00001/00113
d D 4.3 83/05/01 08:24:39 sam 3 2
c from pugs@sun
e
s 00001/00001/00113
d D 4.2 83/01/11 14:38:14 sam 2 1
c 4.1c conversion contortions
e
s 00114/00000/00000
d D 4.1 82/11/02 22:28:03 sam 1 0
c date and time created 82/11/02 22:28:03 by sam
e
u
U
t
T
I 13
/*
D 28
 * Copyright (c) 1983 Regents of the University of California.
E 28
I 28
 * Copyright (c) 1983, 1988 Regents of the University of California.
E 28
D 27
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 27
I 27
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 27
 */

E 13
I 1
#ifndef lint
D 4
static char sccsid[] = "%W% %G%";
E 4
I 4
static char sccsid[] = "%W% (Berkeley) %G%";
E 4
D 13
#endif
E 13
I 13
D 27
#endif not lint
E 27
I 27
#endif /* not lint */
E 27
E 13

/*
 * Routing Table Management Daemon
 */
D 2
#include "router.h"
E 2
I 2
#include "defs.h"
I 14
#include <sys/syslog.h>
E 14
E 2

/*
 * Process a newly received packet.
 */
rip_input(from, size)
	struct sockaddr *from;
	int size;
{
D 12
	struct rt_entry *rt;
	struct netinfo *n;
D 11
	struct interface *ifp;
E 11
I 11
	struct interface *ifp, *if_ifwithdstaddr();
E 12
I 12
	register struct rt_entry *rt;
	register struct netinfo *n;
	register struct interface *ifp;
	struct interface *if_ifwithdstaddr();
E 12
E 11
	int newsize;
D 12
	struct afswitch *afp;
E 12
I 12
	register struct afswitch *afp;
I 19
D 29
	static struct sockaddr badfrom;
E 29
I 29
	static struct sockaddr badfrom, badfrom2;
E 29
E 19
E 12

	ifp = 0;
	TRACE_INPUT(ifp, from, size);
D 14
	if (from->sa_family >= AF_MAX)
E 14
I 14
	if (from->sa_family >= af_max ||
	    (afp = &afswitch[from->sa_family])->af_hash == (int (*)())0) {
		syslog(LOG_INFO,
	 "\"from\" address in unsupported address family (%d), cmd %d\n",
		    from->sa_family, msg->rip_cmd);
E 14
		return;
D 14
	afp = &afswitch[from->sa_family];
E 14
I 14
	}
E 14
	switch (msg->rip_cmd) {

	case RIPCMD_REQUEST:
		newsize = 0;
		size -= 4 * sizeof (char);
		n = msg->rip_nets;
		while (size > 0) {
			if (size < sizeof (struct netinfo))
				break;
			size -= sizeof (struct netinfo);

I 4
D 5
#ifdef notyet
E 5
			if (msg->rip_vers > 0) {
				n->rip_dst.sa_family =
					ntohs(n->rip_dst.sa_family);
				n->rip_metric = ntohl(n->rip_metric);
			}
D 5
#endif
E 5
E 4
			/* 
			 * A single entry with sa_family == AF_UNSPEC and
			 * metric ``infinity'' means ``all routes''.
I 14
			 * We respond to routers only if we are acting
			 * as a supplier, or to anyone other than a router
			 * (eg, query).
E 14
			 */
			if (n->rip_dst.sa_family == AF_UNSPEC &&
D 14
			    n->rip_metric == HOPCNT_INFINITY && size == 0) {
E 14
I 14
D 15
			    n->rip_metric == HOPCNT_INFINITY && size == 0 &&
			    (supplier || (*afp->af_portcheck)(from) == 0)) {
E 14
				supply(from, 0, ifp);
E 15
I 15
			    n->rip_metric == HOPCNT_INFINITY && size == 0) {
			    	if (supplier || (*afp->af_portmatch)(from) == 0)
D 16
					supply(from, 0, ifp);
E 16
I 16
					supply(from, 0, 0);
E 16
E 15
				return;
			}
D 15
			rt = rtlookup(&n->rip_dst);
E 15
I 15
			if (n->rip_dst.sa_family < af_max &&
			    afswitch[n->rip_dst.sa_family].af_hash)
				rt = rtlookup(&n->rip_dst);
			else
				rt = 0;
E 15
			n->rip_metric = rt == 0 ? HOPCNT_INFINITY :
D 25
				min(rt->rt_metric+1, HOPCNT_INFINITY);
E 25
I 25
				min(rt->rt_metric + 1, HOPCNT_INFINITY);
E 25
I 4
D 5
#ifdef notyet
E 5
			if (msg->rip_vers > 0) {
				n->rip_dst.sa_family =
					htons(n->rip_dst.sa_family);
				n->rip_metric = htonl(n->rip_metric);
			}
D 5
#endif
E 5
E 4
			n++, newsize += sizeof (struct netinfo);
		}
		if (newsize > 0) {
			msg->rip_cmd = RIPCMD_RESPONSE;
			newsize += sizeof (int);
D 3
			(*afp->af_output)(s, from, newsize);
E 3
I 3
			(*afp->af_output)(s, 0, from, newsize);
E 3
		}
		return;

	case RIPCMD_TRACEON:
	case RIPCMD_TRACEOFF:
D 7
		/* verify message came from a priviledged port */
E 7
I 7
		/* verify message came from a privileged port */
E 7
		if ((*afp->af_portcheck)(from) == 0)
			return;
I 17
D 21
		if (if_iflookup(from) == 0) {
E 21
I 21
		if ((ifp = if_iflookup(from)) == 0 || (ifp->int_flags &
D 26
		    (IFF_BROADCAST | IFF_POINTOPOINT | IFF_REMOTE)) == 0) {
E 26
I 26
		    (IFF_BROADCAST | IFF_POINTOPOINT | IFF_REMOTE)) == 0 ||
		    ifp->int_flags & IFF_PASSIVE) {
E 26
E 21
			syslog(LOG_ERR, "trace command from unknown router, %s",
D 19
			   (*afswitch[from->sa_family].af_format)(from));
E 19
I 19
			    (*afswitch[from->sa_family].af_format)(from));
E 19
			return;
		}
E 17
		packet[size] = '\0';
		if (msg->rip_cmd == RIPCMD_TRACEON)
			traceon(msg->rip_tracefile);
		else
			traceoff();
		return;

	case RIPCMD_RESPONSE:
		/* verify message came from a router */
		if ((*afp->af_portmatch)(from) == 0)
			return;
		(*afp->af_canon)(from);
		/* are we talking to ourselves? */
		ifp = if_ifwithaddr(from);
		if (ifp) {
I 28
			if (ifp->int_flags & IFF_PASSIVE) {
				syslog(LOG_ERR,
				  "bogus input (from passive interface, %s)",
				  (*afswitch[from->sa_family].af_format)(from));
				return;
			}
E 28
			rt = rtfind(from);
D 7
			if (rt == 0)
E 7
I 7
D 24
			if (rt == 0 || (rt->rt_state & RTS_INTERFACE) == 0)
E 24
I 24
			if (rt == 0 || ((rt->rt_state & RTS_INTERFACE) == 0) &&
			    rt->rt_metric >= ifp->int_metric) 
E 24
E 7
				addrouteforif(ifp);
			else
				rt->rt_timer = 0;
			return;
		}
I 7
D 10
		/* update timer for interface on which the packet arrived */
E 10
I 10
		/*
		 * Update timer for interface on which the packet arrived.
		 * If from other end of a point-to-point link that isn't
		 * in the routing tables, (re-)add the route.
		 */
E 10
D 17
		if ((rt = rtfind(from)) && (rt->rt_state & RTS_INTERFACE))
E 17
I 17
		if ((rt = rtfind(from)) &&
		    (rt->rt_state & (RTS_INTERFACE | RTS_REMOTE)))
E 17
			rt->rt_timer = 0;
I 10
D 24
		else if (ifp = if_ifwithdstaddr(from))
E 24
I 24
		else if ((ifp = if_ifwithdstaddr(from)) &&
		    (rt == 0 || rt->rt_metric >= ifp->int_metric))
E 24
			addrouteforif(ifp);
I 17
D 21
		else if (if_iflookup(from) == 0) {
E 21
I 21
		/*
		 * "Authenticate" router from which message originated.
		 * We accept routing packets from routers directly connected
		 * via broadcast or point-to-point networks,
		 * and from those listed in /etc/gateways.
		 */
		if ((ifp = if_iflookup(from)) == 0 || (ifp->int_flags &
D 26
		    (IFF_BROADCAST | IFF_POINTOPOINT | IFF_REMOTE)) == 0) {
E 26
I 26
		    (IFF_BROADCAST | IFF_POINTOPOINT | IFF_REMOTE)) == 0 ||
		    ifp->int_flags & IFF_PASSIVE) {
E 26
E 21
D 19
			syslog(LOG_ERR, "packet from unknown router, %s",
			   (*afswitch[from->sa_family].af_format)(from));
E 19
I 19
			if (bcmp((char *)from, (char *)&badfrom,
			    sizeof(badfrom)) != 0) {
				syslog(LOG_ERR,
				  "packet from unknown router, %s",
				  (*afswitch[from->sa_family].af_format)(from));
				badfrom = *from;
			}
E 19
			return;
		}
E 17
E 10
E 7
		size -= 4 * sizeof (char);
		n = msg->rip_nets;
		for (; size > 0; size -= sizeof (struct netinfo), n++) {
			if (size < sizeof (struct netinfo))
				break;
I 4
D 5
#ifdef notyet
E 5
			if (msg->rip_vers > 0) {
				n->rip_dst.sa_family =
					ntohs(n->rip_dst.sa_family);
				n->rip_metric = ntohl(n->rip_metric);
			}
D 5
#endif
E 5
E 4
D 6
			if (n->rip_metric >= HOPCNT_INFINITY)
E 6
I 6
D 12
			if ((unsigned) n->rip_metric >= HOPCNT_INFINITY)
E 12
I 12
D 25
			if ((unsigned) n->rip_metric > HOPCNT_INFINITY)
E 12
E 6
				continue;
E 25
I 9
D 14
			if (n->rip_dst.sa_family >= AF_MAX)
E 14
I 14
			if (n->rip_dst.sa_family >= af_max ||
			    (afp = &afswitch[n->rip_dst.sa_family])->af_hash ==
			    (int (*)())0) {
				syslog(LOG_INFO,
		"route in unsupported address family (%d), from %s (af %d)\n",
				   n->rip_dst.sa_family,
				   (*afswitch[from->sa_family].af_format)(from),
				   from->sa_family);
E 14
				continue;
D 14
			afp = &afswitch[n->rip_dst.sa_family];
E 9
I 6
			if (((*afp->af_checkhost)(&n->rip_dst)) == 0)
E 14
I 14
			}
			if (((*afp->af_checkhost)(&n->rip_dst)) == 0) {
				syslog(LOG_DEBUG,
				    "bad host in route from %s (af %d)\n",
				   (*afswitch[from->sa_family].af_format)(from),
				   from->sa_family);
I 29
				continue;
			}
			if (n->rip_metric == 0 ||
			    (unsigned) n->rip_metric > HOPCNT_INFINITY) {
				if (bcmp((char *)from, (char *)&badfrom2,
				    sizeof(badfrom2)) != 0) {
					syslog(LOG_ERR,
					    "bad metric (%d) from %s\n",
					    n->rip_metric,
				  (*afswitch[from->sa_family].af_format)(from));
					badfrom2 = *from;
				}
E 29
E 14
				continue;
I 14
			}
I 24
			/*
			 * Adjust metric according to incoming interface.
			 */
D 25
			if ((unsigned)n->rip_metric < HOPCNT_INFINITY)
E 25
I 25
			if ((unsigned) n->rip_metric < HOPCNT_INFINITY)
E 25
				n->rip_metric += ifp->int_metric;
I 25
			if ((unsigned) n->rip_metric > HOPCNT_INFINITY)
				n->rip_metric = HOPCNT_INFINITY;
E 25
E 24
E 14
E 6
			rt = rtlookup(&n->rip_dst);
D 18
			if (rt == 0) {
E 18
I 18
			if (rt == 0 ||
			    (rt->rt_state & (RTS_INTERNAL|RTS_INTERFACE)) ==
			    (RTS_INTERNAL|RTS_INTERFACE)) {
I 24
				/*
				 * If we're hearing a logical network route
				 * back from a peer to which we sent it,
				 * ignore it.
				 */
				if (rt && rt->rt_state & RTS_SUBNET &&
				    (*afp->af_sendroute)(rt, from))
					continue;
D 28
				/*
				 * Look for an equivalent route that includes
				 * this one before adding this route.
				 */
E 24
E 18
I 17
				rt = rtfind(&n->rip_dst);
D 24
				if (rt && equal(from, &rt->rt_router) &&
D 23
				    rt->rt_metric == n->rip_metric)
E 23
I 23
				    rt->rt_metric <= n->rip_metric)
E 24
I 24
				if (rt && equal(from, &rt->rt_router))
E 24
E 23
					continue;
E 17
D 12
				rtadd(&n->rip_dst, from, n->rip_metric, 0);
E 12
I 12
				if (n->rip_metric < HOPCNT_INFINITY)
E 28
I 28
				if ((unsigned)n->rip_metric < HOPCNT_INFINITY) {
				    /*
				     * Look for an equivalent route that
				     * includes this one before adding
				     * this route.
				     */
				    rt = rtfind(&n->rip_dst);
				    if (rt && equal(from, &rt->rt_router))
					    continue;
E 28
				    rtadd(&n->rip_dst, from, n->rip_metric, 0);
I 28
				}
E 28
E 12
				continue;
			}

			/*
D 8
			 * Update if from gateway, shorter, or getting
			 * stale and equivalent.
E 8
I 8
			 * Update if from gateway and different,
D 28
			 * shorter, or getting stale and equivalent.
E 28
I 28
			 * shorter, or equivalent but old route
			 * is getting stale.
E 28
E 8
			 */
D 8
			if (equal(from, &rt->rt_router) ||
E 8
I 8
D 11
			if ((equal(from, &rt->rt_router) &&
			    n->rip_metric != rt->rt_metric ) ||
E 8
D 6
			    n->rip_metric < rt->rt_metric ||
E 6
I 6
D 7
			    (unsigned) n->rip_metric < rt->rt_metric ||
E 7
I 7
			    (unsigned) (n->rip_metric) < rt->rt_metric ||
E 11
I 11
			if (equal(from, &rt->rt_router)) {
I 12
D 19
				if (n->rip_metric == HOPCNT_INFINITY) {
					rtdelete(rt);
					continue;
				}
E 19
E 12
D 22
				if (n->rip_metric != rt->rt_metric)
E 22
I 22
				if (n->rip_metric != rt->rt_metric) {
E 22
					rtchange(rt, from, n->rip_metric);
I 28
					rt->rt_timer = 0;
E 28
D 20
				rt->rt_timer = 0;
E 20
I 20
D 22
				if (rt->rt_metric < HOPCNT_INFINITY)
E 22
I 22
D 24
					if (rt->rt_metric == HOPCNT_INFINITY)
E 24
I 24
					if (rt->rt_metric >= HOPCNT_INFINITY)
E 24
						rt->rt_timer =
						    GARBAGE_TIME - EXPIRE_TIME;
				} else if (rt->rt_metric < HOPCNT_INFINITY)
E 22
					rt->rt_timer = 0;
E 20
D 25
			} else if ((unsigned) (n->rip_metric) < rt->rt_metric ||
E 25
I 25
			} else if ((unsigned) n->rip_metric < rt->rt_metric ||
E 25
E 11
E 7
E 6
D 28
			    (rt->rt_timer > (EXPIRE_TIME/2) &&
D 24
			    rt->rt_metric == n->rip_metric)) {
E 24
I 24
			    rt->rt_metric == n->rip_metric &&
E 28
I 28
			    (rt->rt_metric == n->rip_metric &&
			    rt->rt_timer > (EXPIRE_TIME/2) &&
E 28
D 25
			    n->rip_metric < HOPCNT_INFINITY)) {
E 25
I 25
			    (unsigned) n->rip_metric < HOPCNT_INFINITY)) {
E 25
E 24
				rtchange(rt, from, n->rip_metric);
				rt->rt_timer = 0;
			}
		}
		return;
	}
}
E 1
