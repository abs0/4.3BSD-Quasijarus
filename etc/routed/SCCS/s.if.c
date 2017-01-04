h40868
s 00009/00003/00118
d D 5.4 88/02/16 18:50:46 bostic 8 7
c add Berkeley specific headers
e
s 00003/00000/00118
d D 5.3 86/04/20 23:33:59 karels 7 6
c changes to allow subnets to remain local, propogate net route
c where subnets don't go, and allow external routes from /etc/gateways
c to block routed from installing routes from elsewhere
e
s 00002/00002/00116
d D 5.2 86/02/23 19:33:54 karels 6 5
c don't rely on AF_MAX (comes from kernel include): check for nil explicitly,
c use our own idea of table size.  Use syslog to (optionally) log bad packets.
c Don't respond to routing inquiries from a router unless we are suppliers
c (really want to respondto everything but broadcasts, but haven't got
c the "to" address.)
e
s 00007/00001/00111
d D 5.1 85/06/04 16:34:52 dist 5 4
c Add copyright
e
s 00019/00001/00093
d D 4.4 84/12/20 18:01:19 karels 4 3
c add if_ifwithdstaddr
e
s 00001/00001/00093
d D 4.3 83/05/25 17:50:41 sam 3 2
c protocol change; byte swap those fields which need it;  also add 
c a version stamp to allow future changes
e
s 00001/00001/00093
d D 4.2 83/01/11 14:38:08 sam 2 1
c 4.1c conversion contortions
e
s 00094/00000/00000
d D 4.1 82/11/02 22:28:02 sam 1 0
c date and time created 82/11/02 22:28:02 by sam
e
u
U
t
T
I 5
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
 */

E 5
I 1
#ifndef lint
D 3
static char sccsid[] = "%W% %G%";
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
E 3
D 5
#endif
E 5
I 5
D 8
#endif not lint
E 8
I 8
#endif /* not lint */
E 8
E 5

/*
 * Routing Table Management Daemon
 */
D 2
#include "router.h"
E 2
I 2
#include "defs.h"
E 2

extern	struct interface *ifnet;

/*
D 4
 * Find the interface with address add.
E 4
I 4
 * Find the interface with address addr.
E 4
 */
struct interface *
if_ifwithaddr(addr)
	struct sockaddr *addr;
{
	register struct interface *ifp;

#define	same(a1, a2) \
	(bcmp((caddr_t)((a1)->sa_data), (caddr_t)((a2)->sa_data), 14) == 0)
	for (ifp = ifnet; ifp; ifp = ifp->int_next) {
		if (ifp->int_flags & IFF_REMOTE)
			continue;
		if (ifp->int_addr.sa_family != addr->sa_family)
			continue;
		if (same(&ifp->int_addr, addr))
			break;
		if ((ifp->int_flags & IFF_BROADCAST) &&
		    same(&ifp->int_broadaddr, addr))
I 4
			break;
	}
	return (ifp);
}

/*
 * Find the point-to-point interface with destination address addr.
 */
struct interface *
if_ifwithdstaddr(addr)
	struct sockaddr *addr;
{
	register struct interface *ifp;

	for (ifp = ifnet; ifp; ifp = ifp->int_next) {
		if ((ifp->int_flags & IFF_POINTOPOINT) == 0)
			continue;
		if (same(&ifp->int_dstaddr, addr))
E 4
			break;
	}
	return (ifp);
}

/*
 * Find the interface on the network 
 * of the specified address.
 */
struct interface *
if_ifwithnet(addr)
	register struct sockaddr *addr;
{
	register struct interface *ifp;
	register int af = addr->sa_family;
	register int (*netmatch)();

D 6
	if (af >= AF_MAX)
E 6
I 6
	if (af >= af_max)
E 6
		return (0);
	netmatch = afswitch[af].af_netmatch;
	for (ifp = ifnet; ifp; ifp = ifp->int_next) {
		if (ifp->int_flags & IFF_REMOTE)
			continue;
		if (af != ifp->int_addr.sa_family)
			continue;
		if ((*netmatch)(addr, &ifp->int_addr))
			break;
	}
	return (ifp);
}

/*
 * Find an interface from which the specified address
 * should have come from.  Used for figuring out which
 * interface a packet came in on -- for tracing.
 */
struct interface *
if_iflookup(addr)
	struct sockaddr *addr;
{
	register struct interface *ifp, *maybe;
	register int af = addr->sa_family;
	register int (*netmatch)();

D 6
	if (af >= AF_MAX)
E 6
I 6
	if (af >= af_max)
E 6
		return (0);
	maybe = 0;
	netmatch = afswitch[af].af_netmatch;
	for (ifp = ifnet; ifp; ifp = ifp->int_next) {
		if (ifp->int_addr.sa_family != af)
			continue;
		if (same(&ifp->int_addr, addr))
			break;
		if ((ifp->int_flags & IFF_BROADCAST) &&
		    same(&ifp->int_broadaddr, addr))
			break;
I 7
		if ((ifp->int_flags & IFF_POINTOPOINT) &&
		    same(&ifp->int_dstaddr, addr))
			break;
E 7
		if (maybe == 0 && (*netmatch)(addr, &ifp->int_addr))
			maybe = ifp;
	}
	if (ifp == 0)
		ifp = maybe;
	return (ifp);
}
E 1
