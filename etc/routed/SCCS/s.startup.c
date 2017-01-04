h48364
s 00004/00002/00429
d D 5.13 88/06/06 16:16:29 karels 22 21
c missed a few: make default, local-loop routes have metric 1,
c as not incremented when sent; check for 0 on input (can't be right)
e
s 00020/00004/00411
d D 5.12 88/05/31 12:06:55 karels 21 20
c allow multiple pt-pt links with same source address;
c mark loopback IFF_PASSIVE; finish perspective change
e
s 00009/00003/00406
d D 5.11 88/02/16 18:50:57 bostic 20 19
c add Berkeley specific headers
e
s 00001/00001/00408
d D 5.10 87/12/12 17:55:31 karels 19 18
c don't bother to ping loopback
e
s 00070/00018/00339
d D 5.9 87/05/28 11:26:12 karels 18 17
c rework interface metrics to invert perspective; other misc. fixes
e
s 00001/00001/00356
d D 5.8 87/04/02 13:06:29 karels 17 16
c finish up interface metric code: store metric from our perspective,
c plus increment for those we send to; delete route from kernel when unreachable,
c but keep in tables to advertise deletion
e
s 00012/00012/00345
d D 5.7 86/06/03 18:31:53 karels 16 15
c delicately balanced on the point of a pin...
e
s 00004/00003/00353
d D 5.6 86/06/03 16:32:35 karels 15 14
c try again; can't block subnet 0 with internal "network" route
e
s 00004/00003/00352
d D 5.5 86/05/30 13:56:27 karels 14 13
c don't send net route to subnet gw's unless on subnet 0;
c a few checks for imposters; bug fix in "external" route configuration;
c rm loopback net defn.
e
s 00034/00003/00321
d D 5.4 86/04/20 23:34:25 karels 13 12
c changes to allow subnets to remain local, propogate net route
c where subnets don't go, and allow external routes from /etc/gateways
c to block routed from installing routes from elsewhere
e
s 00007/00004/00317
d D 5.3 86/02/07 10:05:01 karels 12 11
c 
e
s 00008/00000/00313
d D 5.2 85/11/20 14:37:50 karels 11 10
c want to act as supplier if we have only a single point-point link;
c can't run timer on any interfaces if not a supplier
e
s 00007/00001/00306
d D 5.1 85/06/04 16:37:05 dist 10 9
c Add copyright
e
s 00084/00074/00223
d D 4.9 85/06/03 09:49:43 karels 9 8
c careful with routes to interfaces; don't accidentally delete
c with addroutetoif, if route exists but we think it changes
e
s 00005/00003/00292
d D 4.8 85/02/25 13:44:54 karels 8 7
c careful about deleting route to interface in addrouteforif
e
s 00003/00000/00292
d D 4.7 84/12/20 18:04:24 karels 7 6
c syslog for interface transitions; broadcast all unreachable before exit
e
s 00001/00001/00291
d D 4.6 84/05/16 17:15:52 karels 6 5
c logic error
e
s 00034/00005/00258
d D 4.5 84/04/10 21:43:56 karels 5 4
c subnet routing; don't copy routes from the gateways files everywhere
e
s 00001/00001/00262
d D 4.4 83/05/25 17:51:04 sam 4 3
c protocol change; byte swap those fields which need it;  also add 
c a version stamp to allow future changes
e
s 00008/00006/00255
d D 4.3 83/03/10 19:13:28 sam 3 2
c from shannon
e
s 00056/00021/00205
d D 4.2 83/01/11 14:38:29 sam 2 1
c 4.1c conversion contortions
e
s 00226/00000/00000
d D 4.1 82/11/02 22:28:07 sam 1 0
c date and time created 82/11/02 22:28:07 by sam
e
u
U
t
T
I 10
/*
D 21
 * Copyright (c) 1983 Regents of the University of California.
E 21
I 21
 * Copyright (c) 1983, 1988 Regents of the University of California.
E 21
D 20
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 20
I 20
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 20
 */

E 10
I 1
#ifndef lint
D 4
static char sccsid[] = "%W% %G%";
E 4
I 4
static char sccsid[] = "%W% (Berkeley) %G%";
E 4
D 10
#endif
E 10
I 10
D 20
#endif not lint
E 20
I 20
#endif /* not lint */
E 20
E 10

/*
 * Routing Table Management Daemon
 */
D 2
#include "router.h"
E 2
I 2
#include "defs.h"
I 5
#include <sys/ioctl.h>
E 5
E 2
#include <net/if.h>
D 13
#include <nlist.h>
E 13
I 7
#include <syslog.h>
E 7

struct	interface *ifnet;
D 9
int	kmem = -1;
E 9
int	lookforinterfaces = 1;
D 13
int	performnlist = 1;
E 13
int	externalinterfaces = 0;		/* # of remote and local interfaces */
I 18
int	foundloopback;			/* valid flag for loopaddr */
struct	sockaddr loopaddr;		/* our address on loopback */
E 18
I 5
D 9
int	gateway = 0;		/* 1 if we are a gateway to parts beyond */
E 9
E 5

D 9
struct nlist nl[] = {
#define	N_IFNET		0
	{ "_ifnet" },
D 2
	0,
E 2
I 2
	{ "" },
E 2
};

E 9
/*
D 9
 * Probe the kernel through /dev/kmem to find the network
 * interfaces which have configured themselves.  If the
 * interface is present but not yet up (for example an
E 9
I 9
 * Find the network interfaces which have configured themselves.
 * If the interface is present but not yet up (for example an
E 9
 * ARPANET IMP), set the lookforinterfaces flag so we'll
 * come back later and look again.
 */
ifinit()
{
D 9
	struct interface *ifp;
	struct ifnet ifs, *next;
	char name[32], *cp, *index();
E 9
I 9
	struct interface ifs, *ifp;
	int s, n;
	char buf[BUFSIZ];
        struct ifconf ifc;
        struct ifreq ifreq, *ifr;
        struct sockaddr_in *sin;
	u_long i;
E 9

D 9
	if (performnlist) {
		nlist("/vmunix", nl);
		if (nl[N_IFNET].n_value == 0) {
			printf("ifnet: not in namelist\n");
			goto bad;
		}
		performnlist = 0;
I 5
D 6
		if (gateway)
E 6
I 6
		if (gateway > 0)
E 6
			rtdefault();
E 9
I 9
	if ((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		syslog(LOG_ERR, "socket: %m");
		exit(1);
E 9
E 5
	}
D 9
	if (kmem < 0) {
		kmem = open("/dev/kmem", 0);
		if (kmem < 0) {
			perror("/dev/kmem");
			goto bad;
		}
	}
	if (lseek(kmem, (long)nl[N_IFNET].n_value, 0) == -1 ||
	    read(kmem, (char *)&next, sizeof (next)) != sizeof (next)) {
		printf("ifnet: error reading kmem\n");
		goto bad;
	}
E 9
I 9
        ifc.ifc_len = sizeof (buf);
        ifc.ifc_buf = buf;
        if (ioctl(s, SIOCGIFCONF, (char *)&ifc) < 0) {
                syslog(LOG_ERR, "ioctl (get interface configuration)");
		close(s);
                return (0);
        }
        ifr = ifc.ifc_req;
E 9
	lookforinterfaces = 0;
D 9
	while (next) {
		if (lseek(kmem, (long)next, 0) == -1 ||
		    read(kmem, (char *)&ifs, sizeof (ifs)) != sizeof (ifs)) {
			perror("read");
			goto bad;
		}
		next = ifs.if_next;
		if ((ifs.if_flags & IFF_UP) == 0) {
E 9
I 9
        for (n = ifc.ifc_len / sizeof (struct ifreq); n > 0; n--, ifr++) {
		bzero((char *)&ifs, sizeof(ifs));
		ifs.int_addr = ifr->ifr_addr;
		ifreq = *ifr;
                if (ioctl(s, SIOCGIFFLAGS, (char *)&ifreq) < 0) {
                        syslog(LOG_ERR, "ioctl (get interface flags)");
                        continue;
                }
		ifs.int_flags = ifreq.ifr_flags | IFF_INTERFACE;
I 12
D 18
		/* no one cares about software loopback interfaces */
		if (ifs.int_flags & IFF_LOOPBACK)
			continue;
E 18
E 12
		if ((ifs.int_flags & IFF_UP) == 0 ||
		    ifr->ifr_addr.sa_family == AF_UNSPEC) {
E 9
			lookforinterfaces = 1;
			continue;
		}
D 21
		/* already known to us? */
D 9
		if (if_ifwithaddr(&ifs.if_addr))
E 9
I 9
		if (if_ifwithaddr(&ifs.int_addr))
E 21
I 21
		/*
		 * already known to us?
		 * This allows multiple point-to-point links
		 * to share a source address (possibly with one
		 * other link), but assumes that there will not be
		 * multiple links with the same destination address.
		 */
		if (ifs.int_flags & IFF_POINTOPOINT) {
			if (if_ifwithdstaddr(&ifs.int_dstaddr))
				continue;
		} else if (if_ifwithaddr(&ifs.int_addr))
E 21
E 9
			continue;
		/* argh, this'll have to change sometime */
D 9
		if (ifs.if_addr.sa_family != AF_INET)
E 9
I 9
		if (ifs.int_addr.sa_family != AF_INET)
E 9
			continue;
I 18
		if (ifs.int_flags & IFF_LOOPBACK) {
I 21
			ifs.int_flags |= IFF_PASSIVE;
E 21
			foundloopback = 1;
			loopaddr = ifs.int_addr;
			for (ifp = ifnet; ifp; ifp = ifp->int_next)
			    if (ifp->int_flags & IFF_POINTOPOINT)
				add_ptopt_localrt(ifp);
		}
E 18
I 9
                if (ifs.int_flags & IFF_POINTOPOINT) {
                        if (ioctl(s, SIOCGIFDSTADDR, (char *)&ifreq) < 0) {
                                syslog(LOG_ERR, "ioctl (get dstaddr)");
                                continue;
			}
			ifs.int_dstaddr = ifreq.ifr_dstaddr;
		}
                if (ifs.int_flags & IFF_BROADCAST) {
                        if (ioctl(s, SIOCGIFBRDADDR, (char *)&ifreq) < 0) {
                                syslog(LOG_ERR, "ioctl (get broadaddr)");
                                continue;
                        }
			ifs.int_broadaddr = ifreq.ifr_broadaddr;
		}
I 12
		if (ioctl(s, SIOCGIFMETRIC, (char *)&ifreq) < 0)
			syslog(LOG_ERR, "ioctl (get metric)");
		else
			ifs.int_metric = ifreq.ifr_metric;
I 21
		/*
		 * Use a minimum metric of one;
		 * treat the interface metric (default 0)
		 * as an increment to the hop count of one.
		 */
		ifs.int_metric++;
E 21
E 12
		if (ioctl(s, SIOCGIFNETMASK, (char *)&ifreq) < 0) {
			syslog(LOG_ERR, "ioctl (get netmask)");
			continue;
		}
		sin = (struct sockaddr_in *)&ifreq.ifr_addr;
		ifs.int_subnetmask = ntohl(sin->sin_addr.s_addr);
		sin = (struct sockaddr_in *)&ifs.int_addr;
		i = ntohl(sin->sin_addr.s_addr);
		if (IN_CLASSA(i))
			ifs.int_netmask = IN_CLASSA_NET;
		else if (IN_CLASSB(i))
			ifs.int_netmask = IN_CLASSB_NET;
		else
			ifs.int_netmask = IN_CLASSC_NET;
		ifs.int_net = i & ifs.int_netmask;
		ifs.int_subnet = i & ifs.int_subnetmask;
I 13
		if (ifs.int_subnetmask != ifs.int_netmask)
			ifs.int_flags |= IFF_SUBNET;
E 13
E 9
D 12
		/* no one cares about software loopback interfaces */
D 9
		if (ifs.if_net == LOOPBACKNET)
E 9
I 9
		if (ifs.int_net == LOOPBACKNET)
E 9
			continue;
E 12
		ifp = (struct interface *)malloc(sizeof (struct interface));
		if (ifp == 0) {
			printf("routed: out of memory\n");
			break;
		}
I 9
		*ifp = ifs;
E 9
		/*
		 * Count the # of directly connected networks
		 * and point to point links which aren't looped
		 * back to ourself.  This is used below to
		 * decide if we should be a routing ``supplier''.
		 */
D 9
		if ((ifs.if_flags & IFF_POINTOPOINT) == 0 ||
		    if_ifwithaddr(&ifs.if_dstaddr) == 0)
E 9
I 9
D 18
		if ((ifs.int_flags & IFF_POINTOPOINT) == 0 ||
		    if_ifwithaddr(&ifs.int_dstaddr) == 0)
E 18
I 18
		if ((ifs.int_flags & IFF_LOOPBACK) == 0 &&
		    ((ifs.int_flags & IFF_POINTOPOINT) == 0 ||
		    if_ifwithaddr(&ifs.int_dstaddr) == 0))
E 18
E 9
			externalinterfaces++;
I 11
		/*
		 * If we have a point-to-point link, we want to act
		 * as a supplier even if it's our only interface,
		 * as that's the only way our peer on the other end
		 * can tell that the link is up.
		 */
		if ((ifs.int_flags & IFF_POINTOPOINT) && supplier < 0)
			supplier = 1;
E 11
I 5
D 9
		if ((ifs.if_flags & IFF_LOCAL) == 0 && gateway == 0) {
			/*
			 * If we have an interface to a non-local network,
			 * we are a candidate for use as a gateway.
			 */
			gateway = 1;
			rtdefault();
		}
E 5
		lseek(kmem, ifs.if_name, 0);
		read(kmem, name, sizeof (name));
		name[sizeof (name) - 1] = '\0';
		cp = index(name, '\0');
		*cp++ = ifs.if_unit + '0';
		*cp = '\0';
		ifp->int_name = malloc(strlen(name) + 1);
E 9
I 9
		ifp->int_name = malloc(strlen(ifr->ifr_name) + 1);
E 9
		if (ifp->int_name == 0) {
			fprintf(stderr, "routed: ifinit: out of memory\n");
D 18
			goto bad;		/* ??? */
E 18
I 18
			syslog(LOG_ERR, "routed: ifinit: out of memory\n");
			return;
E 18
		}
D 9
		strcpy(ifp->int_name, name);
		ifp->int_addr = ifs.if_addr;
		ifp->int_flags = ifs.if_flags | IFF_INTERFACE;
		/* this works because broadaddr overlaps dstaddr */
		ifp->int_broadaddr = ifs.if_broadaddr;
		ifp->int_net = ifs.if_net;
E 9
I 9
		strcpy(ifp->int_name, ifr->ifr_name);
E 9
D 12
		ifp->int_metric = 0;
E 12
		ifp->int_next = ifnet;
		ifnet = ifp;
		traceinit(ifp);
		addrouteforif(ifp);
	}
	if (externalinterfaces > 1 && supplier < 0)
		supplier = 1;
I 9
	close(s);
E 9
D 18
	return;
bad:
	sleep(60);
D 2
	close(kmem), close(s), close(snoroute);
E 2
I 2
	close(kmem), close(s);
E 2
	execv("/etc/routed", argv0);
	_exit(0177);
E 18
}

I 13
/*
 * Add route for interface if not currently installed.
 * Create route to other end if a point-to-point link,
 * otherwise a route to this (sub)network.
 * INTERNET SPECIFIC.
 */
E 13
addrouteforif(ifp)
D 18
	struct interface *ifp;
E 18
I 18
	register struct interface *ifp;
E 18
{
	struct sockaddr_in net;
	struct sockaddr *dst;
D 22
	int state, metric;
E 22
I 22
	int state;
E 22
D 18
	struct rt_entry *rt;
E 18
I 18
	register struct rt_entry *rt;
E 18

	if (ifp->int_flags & IFF_POINTOPOINT)
		dst = &ifp->int_dstaddr;
	else {
		bzero((char *)&net, sizeof (net));
		net.sin_family = AF_INET;
D 9
		net.sin_addr = inet_makeaddr(ifp->int_net, INADDR_ANY);
E 9
I 9
		net.sin_addr = inet_makeaddr(ifp->int_subnet, INADDR_ANY);
E 9
		dst = (struct sockaddr *)&net;
	}
I 8
D 9
	rt = rtlookup(dst);
	if (rt && equal(&ifp->int_addr, &rt->rt_router))
E 9
I 9
	rt = rtfind(dst);
D 16
	if (rt && (rt->rt_state & RTS_INTERFACE))
E 16
I 16
	if (rt &&
	    (rt->rt_state & (RTS_INTERFACE | RTS_INTERNAL)) == RTS_INTERFACE)
E 16
E 9
		return;
E 8
I 7
D 9
	if (ifp->int_transitions++ > 0)
		syslog(LOG_ERR, "re-installing interface %s", ifp->int_name);
E 9
E 7
D 8
	rt = rtlookup(dst);
	rtadd(dst, &ifp->int_addr, ifp->int_metric,
		ifp->int_flags & (IFF_INTERFACE|IFF_PASSIVE|IFF_REMOTE));
E 8
	if (rt)
		rtdelete(rt);
I 9
D 16
	if (ifp->int_transitions++ > 0)
		syslog(LOG_ERR, "re-installing interface %s", ifp->int_name);
E 9
I 8
	rtadd(dst, &ifp->int_addr, ifp->int_metric,
D 13
		ifp->int_flags & (IFF_INTERFACE|IFF_PASSIVE|IFF_REMOTE));
E 13
I 13
	    ifp->int_flags & (IFF_INTERFACE|IFF_PASSIVE|IFF_REMOTE|IFF_SUBNET));

E 16
	/*
	 * If interface on subnetted network,
	 * install route to network as well.
	 * This is meant for external viewers.
	 */
	if ((ifp->int_flags & (IFF_SUBNET|IFF_POINTOPOINT)) == IFF_SUBNET) {
I 18
		struct in_addr subnet;

		subnet = net.sin_addr;
E 18
		net.sin_addr = inet_makeaddr(ifp->int_net, INADDR_ANY);
		rt = rtfind(dst);
D 15
		if (rt && (rt->rt_state & RTS_INTERFACE))
E 15
I 15
D 16
		if (rt && (rt->rt_state & (RTS_INTERNAL | RTS_INTERFACE)) ==
		    (RTS_INTERNAL | RTS_INTERFACE))
E 15
			return;
		rtadd(dst, &ifp->int_addr, ifp->int_metric,
D 15
		    (ifp->int_flags & (IFF_INTERFACE|IFF_PASSIVE|IFF_REMOTE) |
D 14
			RTS_INTERNAL));
E 14
I 14
			RTS_INTERNAL | RTS_SUBNET));
E 15
I 15
		    ((ifp->int_flags & (IFF_INTERFACE|IFF_REMOTE)) |
			RTS_PASSIVE | RTS_INTERNAL | RTS_SUBNET));
E 16
I 16
		if (rt == 0)
			rtadd(dst, &ifp->int_addr, ifp->int_metric,
			    ((ifp->int_flags & (IFF_INTERFACE|IFF_REMOTE)) |
D 18
				RTS_PASSIVE | RTS_INTERNAL | RTS_SUBNET));
		net.sin_addr = inet_makeaddr(ifp->int_subnet, INADDR_ANY);
E 18
I 18
			    RTS_PASSIVE | RTS_INTERNAL | RTS_SUBNET));
		else if ((rt->rt_state & (RTS_INTERNAL|RTS_SUBNET)) == 
		    (RTS_INTERNAL|RTS_SUBNET) &&
		    ifp->int_metric < rt->rt_metric)
			rtchange(rt, &rt->rt_router, ifp->int_metric);
		net.sin_addr = subnet;
E 18
E 16
E 15
E 14
	}
I 16
	if (ifp->int_transitions++ > 0)
		syslog(LOG_ERR, "re-installing interface %s", ifp->int_name);
D 18
	rtadd(dst, &ifp->int_addr, ifp->int_metric,
	    ifp->int_flags & (IFF_INTERFACE|IFF_PASSIVE|IFF_REMOTE|IFF_SUBNET));
E 18
I 18
	state = ifp->int_flags &
	    (IFF_INTERFACE | IFF_PASSIVE | IFF_REMOTE | IFF_SUBNET);
	if (ifp->int_flags & IFF_POINTOPOINT &&
	    (ntohl(((struct sockaddr_in *)&ifp->int_dstaddr)->sin_addr.s_addr) &
	    ifp->int_netmask) != ifp->int_net)
		state &= ~RTS_SUBNET;
	if (ifp->int_flags & IFF_LOOPBACK)
D 19
		state |= RTS_EXTERNAL;
E 19
I 19
D 21
		state |= RTS_EXTERNAL | RTS_PASSIVE;
E 21
I 21
		state |= RTS_EXTERNAL;
E 21
E 19
	rtadd(dst, &ifp->int_addr, ifp->int_metric, state);
	if (ifp->int_flags & IFF_POINTOPOINT && foundloopback)
		add_ptopt_localrt(ifp);
}
E 18

I 18
/*
 * Add route to local end of point-to-point using loopback.
 * If a route to this network is being sent to neighbors on other nets,
 * mark this route as subnet so we don't have to propagate it too.
 */
add_ptopt_localrt(ifp)
	register struct interface *ifp;
{
	struct rt_entry *rt;
	struct sockaddr *dst;
	struct sockaddr_in net;
	int state;

	state = RTS_INTERFACE | RTS_PASSIVE;

	/* look for route to logical network */
	bzero((char *)&net, sizeof (net));
	net.sin_family = AF_INET;
	net.sin_addr = inet_makeaddr(ifp->int_net, INADDR_ANY);
	dst = (struct sockaddr *)&net;
	rt = rtfind(dst);
	if (rt && rt->rt_state & RTS_INTERNAL)
		state |= RTS_SUBNET;

	dst = &ifp->int_addr;
	if (rt = rtfind(dst)) {
		if (rt && rt->rt_state & RTS_INTERFACE)
			return;
		rtdelete(rt);
	}
D 22
	rtadd(dst, &loopaddr, 0, state);
E 22
I 22
	rtadd(dst, &loopaddr, 1, state);
E 22
E 18
E 16
E 13
E 8
}

/*
 * As a concession to the ARPANET we read a list of gateways
 * from /etc/gateways and add them to our tables.  This file
 * exists at each ARPANET gateway and indicates a set of ``remote''
 * gateways (i.e. a gateway which we can't immediately determine
 * if it's present or not as we can do for those directly connected
 * at the hardware level).  If a gateway is marked ``passive''
 * in the file, then we assume it doesn't have a routing process
 * of our design and simply assume it's always present.  Those
 * not marked passive are treated as if they were directly
 * connected -- they're added into the interface list so we'll
 * send them routing updates.
I 18
 *
 * PASSIVE ENTRIES AREN'T NEEDED OR USED ON GATEWAYS RUNNING EGP.
E 18
 */
gwkludge()
{
	struct sockaddr_in dst, gate;
	FILE *fp;
	char *type, *dname, *gname, *qual, buf[BUFSIZ];
	struct interface *ifp;
D 14
	int metric;
E 14
I 14
	int metric, n;
E 14
I 5
	struct rt_entry route;
E 5

	fp = fopen("/etc/gateways", "r");
	if (fp == NULL)
		return;
	qual = buf;
	dname = buf + 64;
	gname = buf + ((BUFSIZ - 64) / 3);
	type = buf + (((BUFSIZ - 64) * 2) / 3);
	bzero((char *)&dst, sizeof (dst));
	bzero((char *)&gate, sizeof (gate));
I 5
	bzero((char *)&route, sizeof(route));
E 5
D 2
	dst.sin_family = gate.sin_family = AF_INET;
E 2
D 17
	/* format: {net | host} XX gateway XX metric DD [passive]\n */
E 17
I 17
/* format: {net | host} XX gateway XX metric DD [passive | external]\n */
E 17
#define	readentry(fp) \
	fscanf((fp), "%s %s gateway %s metric %d %s\n", \
		type, dname, gname, &metric, qual)
	for (;;) {
D 2
		struct hostent *host;
		struct netent *net;

E 2
D 14
		if (readentry(fp) == EOF)
E 14
I 14
		if ((n = readentry(fp)) == EOF)
E 14
			break;
D 2
		if (strcmp(type, "net") == 0) {
			net = getnetbyname(dname);
			if (net == 0 || net->n_addrtype != AF_INET)
				continue;
			dst.sin_addr = inet_makeaddr(net->n_net, INADDR_ANY);
		} else if (strcmp(type, "host") == 0) {
			host = gethostbyname(dname);
			if (host == 0)
				continue;
			bcopy(host->h_addr, &dst.sin_addr, host->h_length);
		} else
E 2
I 2
		if (!getnetorhostname(type, dname, &dst))
E 2
			continue;
D 2
		host = gethostbyname(gname);
		if (host == 0)
E 2
I 2
		if (!gethostnameornumber(gname, &gate))
E 2
			continue;
I 22
		if (metric == 0)			/* XXX */
			metric = 1;
E 22
I 5
		if (strcmp(qual, "passive") == 0) {
			/*
			 * Passive entries aren't placed in our tables,
			 * only the kernel's, so we don't copy all of the
			 * external routing information within a net.
			 * Internal machines should use the default
			 * route to a suitable gateway (like us).
			 */
			route.rt_dst = *(struct sockaddr *) &dst;
			route.rt_router = *(struct sockaddr *) &gate;
			route.rt_flags = RTF_UP;
			if (strcmp(type, "host") == 0)
				route.rt_flags |= RTF_HOST;
			if (metric)
				route.rt_flags |= RTF_GATEWAY;
			(void) ioctl(s, SIOCADDRT, (char *)&route.rt_rt);
			continue;
I 13
		}
		if (strcmp(qual, "external") == 0) {
			/*
			 * Entries marked external are handled
			 * by other means, e.g. EGP,
			 * and are placed in our tables only
			 * to prevent overriding them
			 * with something else.
			 */
			rtadd(&dst, &gate, metric, RTS_EXTERNAL|RTS_PASSIVE);
I 14
			continue;
E 14
E 13
		}
		/* assume no duplicate entries */
		externalinterfaces++;
E 5
D 2
		bcopy(host->h_addr, &gate.sin_addr, host->h_length);
E 2
		ifp = (struct interface *)malloc(sizeof (*ifp));
		bzero((char *)ifp, sizeof (*ifp));
		ifp->int_flags = IFF_REMOTE;
		/* can't identify broadcast capability */
		ifp->int_net = inet_netof(dst.sin_addr);
		if (strcmp(type, "host") == 0) {
			ifp->int_flags |= IFF_POINTOPOINT;
			ifp->int_dstaddr = *((struct sockaddr *)&dst);
		}
D 5
		if (strcmp(qual, "passive") == 0)
			ifp->int_flags |= IFF_PASSIVE;
		else
			/* assume no duplicate entries */
			externalinterfaces++;
E 5
		ifp->int_addr = *((struct sockaddr *)&gate);
		ifp->int_metric = metric;
		ifp->int_next = ifnet;
		ifnet = ifp;
		addrouteforif(ifp);
	}
	fclose(fp);
I 2
}

getnetorhostname(type, name, sin)
	char *type, *name;
	struct sockaddr_in *sin;
{

	if (strcmp(type, "net") == 0) {
		struct netent *np = getnetbyname(name);
		int n;

D 3
		if (np->n_addrtype != AF_INET)
			return (0);
E 3
		if (np == 0)
			n = inet_network(name);
D 3
		else
E 3
I 3
		else {
			if (np->n_addrtype != AF_INET)
				return (0);
E 3
			n = np->n_net;
I 9
			/*
			 * getnetbyname returns right-adjusted value.
			 */
			if (n < 128)
				n <<= IN_CLASSA_NSHIFT;
			else if (n < 65536)
				n <<= IN_CLASSB_NSHIFT;
			else
				n <<= IN_CLASSC_NSHIFT;
E 9
I 3
		}
E 3
		sin->sin_family = AF_INET;
		sin->sin_addr = inet_makeaddr(n, INADDR_ANY);
		return (1);
	}
	if (strcmp(type, "host") == 0) {
		struct hostent *hp = gethostbyname(name);

D 3
		if (hp->h_addrtype != AF_INET)
			return (0);
E 3
		if (hp == 0)
			sin->sin_addr.s_addr = inet_addr(name);
D 3
		else
E 3
I 3
		else {
			if (hp->h_addrtype != AF_INET)
				return (0);
E 3
			bcopy(hp->h_addr, &sin->sin_addr, hp->h_length);
I 3
		}
E 3
		sin->sin_family = AF_INET;
		return (1);
	}
	return (0);
}

gethostnameornumber(name, sin)
	char *name;
	struct sockaddr_in *sin;
{
	struct hostent *hp;

	hp = gethostbyname(name);
	if (hp) {
		bcopy(hp->h_addr, &sin->sin_addr, hp->h_length);
		sin->sin_family = hp->h_addrtype;
		return (1);
	}
	sin->sin_addr.s_addr = inet_addr(name);
	sin->sin_family = AF_INET;
	return (sin->sin_addr.s_addr != -1);
E 2
}
E 1
