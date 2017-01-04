h14517
s 00025/00012/00165
d D 5.5 86/02/14 18:28:17 sklower 5 4
c 1.) Fixes from Nesheim viz pt to pt timeouts;
c 2.) Getting rid of ns_netof, to make common for Gould, CCI
e
s 00015/00008/00162
d D 5.4 85/09/17 21:40:00 sklower 4 3
c use syslog instead of perror, ignore remote requests unless specifically asked,
c handle requests from net 0.
e
s 00033/00007/00137
d D 5.3 85/08/16 21:49:12 sklower 3 2
c This version Aug 16th -- source directory moved to /usr/src/etc/XNSrouted;
c includes fix to response to request for specific net, and adds copyright notices
e
s 00064/00100/00080
d D 5.2 85/08/16 20:44:00 sklower 2 1
c status as of 4.3 alpha tape
e
s 00180/00000/00000
d D 5.1 85/08/16 20:22:47 sklower 1 0
c date and time created 85/08/16 20:22:47 by sklower
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
 * Includes material written at Cornell University by Bill Nesheim,
 * by permission of the author.
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
#include <net/if.h>
#include <nlist.h>
I 2
#include <syslog.h>
E 2

struct	interface *ifnet;
D 2
int	kmem = -1;
E 2
int	lookforinterfaces = 1;
int	performnlist = 1;
I 5
int	gateway = 0;
E 5
int	externalinterfaces = 0;		/* # of remote and local interfaces */
D 5
int	gateway = 0;		/* 1 if we are a gateway to parts beyond */
E 5
char ether_broadcast_addr[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

D 2
struct nlist nl[] = {
#define	N_IFNET		0
	{ "_ifnet" },
	{ "" },
};
E 2

/*
D 2
 * Probe the kernel through /dev/kmem to find the network
 * interfaces which have configured themselves.  If the
 * interface is present but not yet up (for example an
E 2
I 2
 * Find the network interfaces which have configured themselves.
 * If the interface is present but not yet up (for example an
E 2
 * ARPANET IMP), set the lookforinterfaces flag so we'll
 * come back later and look again.
 */
ifinit()
{
D 2
	struct interface *ifp;
	struct ifnet ifs, *next;
	char name[32], *cp, *index();
	int j,iffound;
	struct sockaddr ifaddr, ifdstaddr;
	struct sockaddr_xn *sxn;
E 2
I 2
	struct interface ifs, *ifp;
	int s, n;
D 4
	char buf[BUFSIZ];
E 4
        struct ifconf ifc;
I 4
	char buf[(sizeof (struct ifreq ) * 20)];
E 4
        struct ifreq ifreq, *ifr;
	u_long i;
E 2

D 2
	if (performnlist) {
		nlist("/vmunix", nl);
		if (nl[N_IFNET].n_value == 0) {
			printf("ifnet: not in namelist\n");
			goto bad;
		}
		performnlist = 0;
E 2
I 2
	if ((s = socket(AF_NS, SOCK_DGRAM, 0)) < 0) {
		syslog(LOG_ERR, "socket: %m");
		exit(1);
E 2
	}
D 2
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
E 2
I 2
        ifc.ifc_len = sizeof (buf);
        ifc.ifc_buf = buf;
        if (ioctl(s, SIOCGIFCONF, (char *)&ifc) < 0) {
                syslog(LOG_ERR, "ioctl (get interface configuration)");
		close(s);
                return (0);
        }
        ifr = ifc.ifc_req;
E 2
	lookforinterfaces = 0;
D 2
	while (next) {
		if (lseek(kmem, (long)next, 0) == -1 ||
		    read(kmem, (char *)&ifs, sizeof (ifs)) != sizeof (ifs)) {
			perror("read");
			goto bad;
		}
		next = ifs.if_next;
		if ((ifs.if_flags & IFF_UP) == 0) {
E 2
I 2
        for (n = ifc.ifc_len / sizeof (struct ifreq); n > 0; n--, ifr++) {
		bzero((char *)&ifs, sizeof(ifs));
		ifs.int_addr = ifr->ifr_addr;
		ifreq = *ifr;
                if (ioctl(s, SIOCGIFFLAGS, (char *)&ifreq) < 0) {
                        syslog(LOG_ERR, "ioctl (get interface flags)");
                        continue;
                }
		ifs.int_flags = ifreq.ifr_flags | IFF_INTERFACE;
		if ((ifs.int_flags & IFF_UP) == 0 ||
		    ifr->ifr_addr.sa_family == AF_UNSPEC) {
E 2
			lookforinterfaces = 1;
			continue;
		}
I 4
D 5
#ifdef notdef
E 4
D 2
		/* Only interested in af XNS */
		iffound = 0;
		for( j = 0; j < NIFADDR; j++) {
		    if (ifs.if_addr[j].sa_family != AF_XNS)
		    	continue;
		    /* already known to us? */
		    if (if_ifwithaddr(&ifs.if_addr[j]))
			continue; 
		    ifaddr = ifs.if_addr[j];
		    ifdstaddr = ifs.if_dstaddr[j];
		    iffound++;
E 2
I 2
		/* already known to us? */
D 3
		if (if_ifwithaddr(&ifs.int_addr))
			continue;
E 3
I 3
D 4
		/*if (if_ifwithaddr(&ifs.int_addr))
			continue;*/
E 3
		/* argh, this'll have to change sometime */
E 4
I 4
		/* We can have more than one point to point link
		   with the same local address.
		   It is not clear what this was guarding against
		   anyway.
		if (if_ifwithaddr(ifr->ifr_addr))
			continue;
		   */
#endif
E 5
E 4
		if (ifs.int_addr.sa_family != AF_NS)
			continue;
                if (ifs.int_flags & IFF_POINTOPOINT) {
                        if (ioctl(s, SIOCGIFDSTADDR, (char *)&ifreq) < 0) {
D 4
                                syslog(LOG_ERR, "ioctl (get dstaddr)");
E 4
I 4
                                syslog(LOG_ERR, "ioctl (get dstaddr): %m");
E 4
                                continue;
			}
			ifs.int_dstaddr = ifreq.ifr_dstaddr;
E 2
		}
D 2
		if (!iffound) continue;
		
E 2
I 2
                if (ifs.int_flags & IFF_BROADCAST) {
                        if (ioctl(s, SIOCGIFBRDADDR, (char *)&ifreq) < 0) {
D 4
                                syslog(LOG_ERR, "ioctl (get broadaddr)");
E 4
I 4
                                syslog(LOG_ERR, "ioctl (get broadaddr: %m");
E 4
                                continue;
                        }
			ifs.int_broadaddr = ifreq.ifr_broadaddr;
		}
I 5
		/* 
		 * already known to us? 
		 * what makes a POINTOPOINT if unique is its dst addr,
		 * NOT its source address 
		 */
		if ( ((ifs.int_flags & IFF_POINTOPOINT) &&
			if_ifwithdstaddr(&ifs.int_dstaddr)) ||
			( ((ifs.int_flags & IFF_POINTOPOINT) == 0) &&
			if_ifwithaddr(&ifs.int_addr)))
			continue;
E 5
		/* no one cares about software loopback interfaces */
D 5
		if (strcmp(ifr->ifr_name,"lo0")==0)
E 5
I 5
		if (strncmp(ifr->ifr_name,"lo", 2)==0)
E 5
			continue;
E 2
		ifp = (struct interface *)malloc(sizeof (struct interface));
		if (ifp == 0) {
D 4
			printf("routed: out of memory\n");
E 4
I 4
			syslog(LOG_ERR,"XNSrouted: out of memory\n");
E 4
			break;
		}
I 2
		*ifp = ifs;
E 2
		/*
		 * Count the # of directly connected networks
		 * and point to point links which aren't looped
		 * back to ourself.  This is used below to
		 * decide if we should be a routing ``supplier''.
		 */
D 2
		if ((ifs.if_flags & IFF_POINTOPOINT) == 0 ||
		    if_ifwithaddr(ifdstaddr) == 0)
E 2
I 2
		if ((ifs.int_flags & IFF_POINTOPOINT) == 0 ||
		    if_ifwithaddr(&ifs.int_dstaddr) == 0)
E 2
			externalinterfaces++;
I 5
		/*
		 * If we have a point-to-point link, we want to act
		 * as a supplier even if it's our only interface,
		 * as that's the only way our peer on the other end
		 * can tell that the link is up.
		 */
		if ((ifs.int_flags & IFF_POINTOPOINT) && supplier < 0)
			supplier = 1;
E 5
D 2
		if ((ifs.if_flags & IFF_LOCAL) == 0 && gateway == 0) {
			/*
			 * If we have an interface to a non-local network,
			 * we are a candidate for use as a gateway.
			 */
			gateway = 1;
		}
		lseek(kmem, ifs.if_name, 0);
		read(kmem, name, sizeof (name));
		name[sizeof (name) - 1] = '\0';
		cp = index(name, '\0');
		*cp++ = ifs.if_unit + '0';
		*cp = '\0';
		ifp->int_name = malloc(strlen(name) + 1);
E 2
I 2
		ifp->int_name = malloc(strlen(ifr->ifr_name) + 1);
E 2
		if (ifp->int_name == 0) {
D 4
			fprintf(stderr, "routed: ifinit: out of memory\n");
E 4
I 4
			syslog(LOG_ERR,"XNSrouted: out of memory\n");
E 4
			goto bad;		/* ??? */
		}
D 2
		strcpy(ifp->int_name, name);
		ifp->int_flags = (ifs.if_flags & 0x1ff) | IFF_INTERFACE;
		ifp->int_addr = ifaddr;
		/* this works because broadaddr overlaps dstaddr */
		ifp->int_broadaddr = ifdstaddr;
E 2
I 2
		strcpy(ifp->int_name, ifr->ifr_name);
E 2
		ifp->int_metric = 0;
		ifp->int_next = ifnet;
D 2
		/* 
		 * Now arrange for a socket to listen on.
		 * This nonsense is necessary because of the stupidity
		 * of the raw socket code.
		 */
		/* listen on our own address... */
		sxn = (struct sockaddr_xn *) &ifp->int_addr;
		sxn->sxn_addr.xn_socket = htons(IDPPORT_RIF);
		ifp->int_ripsock[0] = getsocket(AF_XNS, SOCK_RAW, IDPPROTO_RIF, sxn);
		/* AND on our broadcast address if we have one */
		if (ifp->int_flags & IFF_BROADCAST) {
		    sxn = (struct sockaddr_xn *)  &ifp->int_broadaddr ;
		    sxn->sxn_addr.xn_socket = htons(IDPPORT_RIF);
		    ifp->int_ripsock[1] = getsocket(AF_XNS, SOCK_RAW, IDPPROTO_RIF, sxn);
		}
E 2
		ifnet = ifp;
		traceinit(ifp);
		addrouteforif(ifp);
	}
	if (externalinterfaces > 1 && supplier < 0)
		supplier = 1;
I 2
	close(s);
E 2
	return;
bad:
	sleep(60);
D 2
	for(j = 3; j < 32; j++) close(j);
E 2
I 2
	close(s);
I 4
	sleep(60);
E 4
E 2
	execv("/etc/XNSrouted", argv0);
	_exit(0177);
}

addrouteforif(ifp)
	struct interface *ifp;
{
D 2
	struct sockaddr_xn net;
E 2
I 2
	struct sockaddr_ns net;
E 2
	struct sockaddr *dst;
	int state, metric;
	struct rt_entry *rt;

D 3
	if (ifp->int_flags & IFF_POINTOPOINT)
E 3
I 3
	if (ifp->int_flags & IFF_POINTOPOINT) {
		int (*match)();
		register struct interface *ifp2 = ifnet;
		register struct interface *ifprev = ifnet;
		
E 3
		dst = &ifp->int_dstaddr;
D 3
	else {
E 3
I 3

		/* Search for interfaces with the same net */
		ifp->int_sq.n = ifp->int_sq.p = &(ifp->int_sq);
		match = afswitch[dst->sa_family].af_netmatch;
		if (match)
		for (ifp2 = ifnet; ifp2; ifp2 =ifp2->int_next) {
			if (ifp->int_flags & IFF_POINTOPOINT == 0)
				continue;
			if ((*match)(&ifp2->int_dstaddr,&ifp->int_dstaddr)) {
				insque(&ifp2->int_sq,&ifp->int_sq);
				break;
			}
		}
	} else {
E 3
D 2
		bzero(&net, sizeof (net));
		net.sxn_family = AF_XNS;
		xnnet(net.sxn_addr.xn_net) = xnnet(((struct sockaddr_xn *)(&ifp->int_addr))->sxn_addr.xn_net);
		dst = (struct sockaddr *)&net;
E 2
I 2
		dst = &ifp->int_broadaddr;
E 2
	}
	rt = rtlookup(dst);
D 2
	rtadd(dst, &ifp->int_addr, ifp->int_metric,
		ifp->int_flags & (IFF_INTERFACE|IFF_PASSIVE|IFF_REMOTE));
E 2
	if (rt)
		rtdelete(rt);
I 5
	if (tracing)
		fprintf(stderr, "Adding route to interface %s\n", ifp->int_name);
	if (ifp->int_transitions++ > 0)
		syslog(LOG_ERR, "re-installing interface %s", ifp->int_name);
E 5
I 2
	rtadd(dst, &ifp->int_addr, ifp->int_metric,
		ifp->int_flags & (IFF_INTERFACE|IFF_PASSIVE|IFF_REMOTE));
E 2
}
I 5

E 5
D 2

E 2
D 3

E 3
E 1
