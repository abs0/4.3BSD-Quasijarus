h44060
s 00010/00005/00455
d D 7.9 88/06/29 17:06:31 bostic 37 36
c install approved copyright notice
e
s 00002/00001/00458
d D 7.8 88/05/26 09:38:20 karels 36 35
c lint
e
s 00000/00007/00459
d D 7.7 88/04/03 17:34:47 karels 35 34
c netbroadcast should always be all-ones
e
s 00008/00002/00458
d D 7.6 87/12/07 17:45:09 bostic 34 33
c use Berkeley specific header
e
s 00027/00003/00433
d D 7.5 87/06/04 21:48:40 karels 33 32
c add class D, experimental; don't forward those, net 0 or loopback
e
s 00009/00011/00427
d D 7.4 87/03/30 20:51:40 karels 32 31
c get this right
e
s 00013/00004/00425
d D 7.3 87/02/19 16:49:58 karels 31 30
c liberalize interpretation of in_broadcast to avoid responding
c to most UDP broadcasts
e
s 00001/00001/00428
d D 7.2 86/11/23 20:30:52 karels 30 29
c yow
e
s 00001/00001/00428
d D 7.1 86/06/05 00:25:07 mckusick 29 28
c 4.3BSD release version
e
s 00042/00020/00387
d D 6.15 86/04/13 21:42:01 karels 28 27
c delete old routes properly, use route to host for loopback
e
s 00001/00001/00406
d D 6.14 86/03/04 13:58:55 karels 27 25
c ... but need to set dstaddr before addr, or garbage routes installed
e
s 00001/00001/00406
d R 6.14 86/02/27 00:42:59 karels 26 25
c Sorry, do the dstaddr first
e
s 00009/00002/00398
d D 6.13 86/02/23 23:23:24 karels 25 24
c lint
e
s 00032/00029/00368
d D 6.12 86/02/21 15:25:18 karels 24 23
c reorder code for interface initialization so that nothing is modified
c if the interface can't initialize (in particular, not net or subnet)
e
s 00007/00004/00390
d D 6.11 85/11/09 15:52:27 sklower 23 22
c in rtinit, allow for deleting pt to pt hosts, by requiring
c new argument, rather than overloading flags.
e
s 00009/00000/00385
d D 6.10 85/10/14 17:19:55 karels 22 21
c recognize other attempts to broadcast
e
s 00012/00006/00373
d D 6.9 85/09/16 22:43:11 karels 21 20
c simplifications; count external interfaces; typos
e
s 00007/00001/00372
d D 6.8 85/06/08 12:37:23 mckusick 20 19
c Add copyright
e
s 00001/00000/00372
d D 6.7 85/04/16 09:57:23 karels 19 18
c missing return
e
s 00276/00104/00096
d D 6.6 85/03/18 15:50:08 karels 18 17
c move net addresses from interface to protocol layer;
c ioctls (PRU_CONTROL) move to protocol, new ioctls to get/set netmask,
c broadcast addr
e
s 00030/00000/00170
d D 6.5 84/10/19 15:02:36 karels 17 16
c bind local address according to routing (caching the route);
c pick maximum seg sizes (offered and accepted) based on interface mtu,
c with default if not local
e
s 00007/00007/00163
d D 6.4 84/08/29 15:35:51 bloom 16 15
c Include file changes.  No more ../h
e
s 00062/00034/00108
d D 6.3 84/04/24 17:28:24 karels 15 14
c fix to subnet routing (for initial calculation of if_net's)
e
s 00053/00012/00089
d D 6.2 84/04/12 11:31:54 karels 14 13
c subnet routing
e
s 00000/00000/00101
d D 6.1 83/07/29 07:11:08 sam 13 12
c 4.2 distribution
e
s 00002/00002/00099
d D 4.12 83/03/14 14:52:09 sam 12 11
c didn't match class b & c nets correctly
e
s 00000/00002/00101
d D 4.11 82/11/13 23:11:27 sam 11 10
c merge 4.1b with 4.1c
e
s 00003/00014/00100
d D 4.10 82/10/30 13:02:37 root 10 9
c get rid of conditional htons/ntohs etc
e
s 00002/00002/00112
d D 4.9 82/10/21 21:05:33 root 9 8
c lint
e
s 00002/00000/00112
d D 4.8 82/10/20 03:16:05 root 8 7
c lint
e
s 00015/00012/00097
d D 4.7 82/10/20 01:22:04 root 7 6
c lint
e
s 00001/00001/00108
d D 4.6 82/10/17 22:47:12 root 6 5
c lint
e
s 00028/00013/00081
d D 4.5 82/10/17 14:54:23 root 5 4
c fix lint
e
s 00002/00002/00092
d D 4.4 82/10/09 05:44:46 wnj 4 3
c localize header files
e
s 00000/00004/00094
d D 4.3 82/06/20 00:53:47 sam 3 2
c purge COUNT stuff now that we can use gprof
e
s 00002/00000/00096
d D 4.2 82/06/13 23:01:23 sam 2 1
c add class a/b/c net #'s and purge logical host kludge code
e
s 00096/00000/00000
d D 4.1 82/06/13 14:10:27 sam 1 0
c date and time created 82/06/13 14:10:27 by sam
e
u
U
t
T
I 1
D 20
/*	%M%	%I%	%E%	*/
E 20
I 20
/*
D 29
 * Copyright (c) 1982 Regents of the University of California.
E 29
I 29
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 29
D 34
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 34
I 34
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 37
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 37
I 37
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 37
E 34
 *
 *	%W% (Berkeley) %G%
 */
E 20

D 16
#include "../h/param.h"
#include "../h/mbuf.h"
#include "../h/protosw.h"
#include "../h/socket.h"
#include "../h/socketvar.h"
D 4
#include "../net/in.h"
#include "../net/in_systm.h"
E 4
I 4
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
E 16
I 16
#include "param.h"
I 18
#include "ioctl.h"
E 18
#include "mbuf.h"
#include "protosw.h"
#include "socket.h"
#include "socketvar.h"
D 18
#include "in.h"
E 18
I 18
#include "uio.h"
#include "dir.h"
#include "user.h"
E 18
#include "in_systm.h"
E 16
E 4
I 2
#include "../net/if.h"
#include "../net/route.h"
E 2
#include "../net/af.h"
I 18
#include "in.h"
#include "in_var.h"
E 18

#ifdef INET
inet_hash(sin, hp)
	register struct sockaddr_in *sin;
	struct afhash *hp;
{
I 18
	register u_long n;
E 18
I 5

E 5
D 3
COUNT(INET_HASH);
E 3
D 18
	hp->afh_nethash = in_netof(sin->sin_addr);
E 18
I 18
	n = in_netof(sin->sin_addr);
	if (n)
	    while ((n & 0xff) == 0)
		n >>= 8;
	hp->afh_nethash = n;
E 18
D 7
	hp->afh_hosthash = ntohl(sin->sin_addr.s_addr);
E 7
I 7
D 10
	hp->afh_hosthash = sin->sin_addr.s_addr;
#if vax || pdp11 || ns16032
	hp->afh_hosthash = ntohl((u_long)hp->afh_hosthash);
D 9
#else
E 9
I 9
#endif
E 10
I 10
	hp->afh_hosthash = ntohl(sin->sin_addr.s_addr);
E 10
E 9
E 7
D 5
	if (hp->afh_hosthash < 0)
		hp->afh_hosthash = -hp->afh_hosthash;
E 5
}

inet_netmatch(sin1, sin2)
	struct sockaddr_in *sin1, *sin2;
{
I 5

E 5
D 3
COUNT(INET_NETMATCH);
E 3
D 12
	return (sin1->sin_addr.s_net == sin2->sin_addr.s_net);
E 12
I 12
	return (in_netof(sin1->sin_addr) == in_netof(sin2->sin_addr));
E 12
}

/*
D 18
 * Formulate an Internet address from network + host.  Used in
 * building addresses stored in the ifnet structure.
E 18
I 18
 * Formulate an Internet address from network + host.
E 18
 */
struct in_addr
D 18
if_makeaddr(net, host)
	int net, host;
E 18
I 18
in_makeaddr(net, host)
	u_long net, host;
E 18
{
I 18
	register struct in_ifaddr *ia;
	register u_long mask;
E 18
	u_long addr;

D 3
COUNT(IF_MAKEADDR);
E 3
D 14
	if (net < 128)
E 14
I 14
D 18
	if (net < IN_CLASSA_MAX)
E 14
D 5
		addr = (net << 24) | host;
E 5
I 5
D 7
		addr = (net << IN_CLASSANSHIFT) | host;
E 7
I 7
		addr = (net << IN_CLASSA_NSHIFT) | host;
E 7
E 5
D 14
	else if (net < 65536)
E 14
I 14
	else if (net < IN_CLASSB_MAX)
E 14
D 5
		addr = (net << 16) | host;
E 5
I 5
D 7
		addr = (net << IN_CLASSBNSHIFT) | host;
E 7
I 7
		addr = (net << IN_CLASSB_NSHIFT) | host;
E 18
I 18
	if (IN_CLASSA(net))
		mask = IN_CLASSA_HOST;
	else if (IN_CLASSB(net))
		mask = IN_CLASSB_HOST;
E 18
E 7
E 5
	else
D 5
		addr = (net << 8) | host;
#ifdef vax
E 5
I 5
D 7
		addr = (net << IN_CLASSCNSHIFT) | host;
E 7
I 7
D 18
		addr = (net << IN_CLASSC_NSHIFT) | host;
E 7
D 10
#ifdef vax || pdp11 || ns16032
E 10
E 5
	addr = htonl(addr);
E 18
I 18
		mask = IN_CLASSC_HOST;
	for (ia = in_ifaddr; ia; ia = ia->ia_next)
		if ((ia->ia_netmask & net) == ia->ia_net) {
			mask = ~ia->ia_subnetmask;
			break;
		}
	addr = htonl(net | (host & mask));
E 18
D 10
#endif
E 10
	return (*(struct in_addr *)&addr);
}

/*
D 5
 * Return the network number from an internet
 * address; handles class a/b/c network #'s.
E 5
I 5
 * Return the network number from an internet address.
E 5
 */
I 21
u_long
E 21
in_netof(in)
	struct in_addr in;
{
I 5
D 7
	register u_int i = in.s_addr;
E 7
I 7
D 10
	register u_long i = in.s_addr;
E 10
I 10
	register u_long i = ntohl(in.s_addr);
I 14
D 15
	register net;
E 15
I 15
D 18
	register u_long net, subnet;
	register struct ifnet *ifp;
E 18
I 18
	register u_long net;
	register struct in_ifaddr *ia;
E 18
E 15
E 14
E 10
E 7
E 5

D 5
	return (IN_NETOF(in));
E 5
I 5
D 10
#ifdef vax || pdp11 || ns16032
	i = ntohl(i);
#endif
E 10
D 14
	if (IN_CLASSA(i))
D 7
		return (((i)&IN_CLASSANET) >> IN_CLASSANSHIFT);
E 7
I 7
		return (((i)&IN_CLASSA_NET) >> IN_CLASSA_NSHIFT);
E 7
	else if (IN_CLASSB(i))
D 7
		return (((i)&IN_CLASSBNET) >> IN_CLASSBNSHIFT);
E 7
I 7
		return (((i)&IN_CLASSB_NET) >> IN_CLASSB_NSHIFT);
E 7
	else
E 14
I 14
D 18
	if (IN_CLASSA(i)) {
D 15
		net = ((i)&IN_CLASSA_NET) >> IN_CLASSA_NSHIFT;
		if (in_localnet(net) && IN_SUBNETA(i))
			return (((i)&IN_CLASSA_SUBNET) >> IN_CLASSA_SUBNSHIFT);
		else
E 15
I 15
		net = (i & IN_CLASSA_NET) >> IN_CLASSA_NSHIFT;
		if (IN_SUBNETA(i)) {
			subnet = (i & IN_CLASSA_SUBNET) >> IN_CLASSA_SUBNSHIFT;
			/* Fall through and check whether a subnet */
		} else
E 15
			return (net);
	} else if (IN_CLASSB(i)) {
D 15
		net = ((i)&IN_CLASSB_NET) >> IN_CLASSB_NSHIFT;
		if (in_localnet(net) && IN_SUBNETB(i))
			return (((i)&IN_CLASSB_SUBNET) >> IN_CLASSB_SUBNSHIFT);
		else
E 15
I 15
		net = (i & IN_CLASSB_NET) >> IN_CLASSB_NSHIFT;
		if (IN_SUBNETB(i)) {
			subnet = (i & IN_CLASSB_SUBNET) >> IN_CLASSB_SUBNSHIFT;
			/* Fall through and check whether a subnet */
		} else
E 15
			return (net);
	} else {
E 14
D 7
		return (((i)&IN_CLASSCNET) >> IN_CLASSCNSHIFT);
E 7
I 7
D 15
		return (((i)&IN_CLASSC_NET) >> IN_CLASSC_NSHIFT);
E 15
I 15
		return ((i & IN_CLASSC_NET) >> IN_CLASSC_NSHIFT);
E 15
I 14
	}
E 18
I 18
	if (IN_CLASSA(i))
		net = i & IN_CLASSA_NET;
	else if (IN_CLASSB(i))
		net = i & IN_CLASSB_NET;
D 33
	else
E 33
I 33
	else if (IN_CLASSC(i))
E 33
		net = i & IN_CLASSC_NET;
I 33
	else
		return (0);
E 33
E 18
I 15

	/*
D 18
	 * Check whether network is a subnet of a `local' network;
E 18
I 18
	 * Check whether network is a subnet;
E 18
	 * if so, return subnet number.
	 */
D 18
	for (ifp = ifnet; ifp; ifp = ifp->if_next) {
		if (ifp->if_addr.sa_family != AF_INET)
			continue;
		if (ifp->if_flags & IFF_LOCAL) {
			if (ifp->if_net == net)
				return (subnet);
			if ((ifp->if_net >> SUBNETSHIFT) == net)
				return (subnet);
			/*
			 * Hack for use in setting if_net initially.
			 */
			if (ifp->if_net == 0) {
				register struct sockaddr_in *sin;
				sin = (struct sockaddr_in *) &ifp->if_addr;
				if (sin->sin_addr.s_addr == in.s_addr)
					return (subnet);
			}
		}
	}
E 18
I 18
	for (ia = in_ifaddr; ia; ia = ia->ia_next)
D 21
		if ((ia->ia_netmask & net) == ia->ia_net)
E 21
I 21
		if (net == ia->ia_net)
E 21
			return (i & ia->ia_subnetmask);
E 18
	return (net);
E 15
E 14
E 7
E 5
}

I 8
D 9
#ifndef notdef
E 9
I 9
D 11
#ifdef notdef
E 11
E 9
E 8
/*
D 5
 * Return the local network address portion of an
 * internet address; handles class a/b/c network
 * number formats.
E 5
I 5
 * Return the host portion of an internet address.
E 5
 */
I 25
u_long
E 25
in_lnaof(in)
	struct in_addr in;
{
I 5
D 7
	register u_int i = in.s_addr;
E 7
I 7
D 10
	register u_long i = in.s_addr;
E 10
I 10
	register u_long i = ntohl(in.s_addr);
I 15
D 18
	register u_long net, host, subhost;
	register struct ifnet *ifp;
E 18
I 18
	register u_long net, host;
	register struct in_ifaddr *ia;
E 18
E 15
E 10
E 7
E 5

D 5
	return (IN_LNAOF(in));
E 5
I 5
D 10
#ifdef vax || pdp11 || ns16032
	i = ntohl(i);
#endif
E 10
D 14
	if (IN_CLASSA(i))
D 7
		return ((i)&IN_CLASSAHOST);
E 7
I 7
		return ((i)&IN_CLASSA_HOST);
E 7
	else if (IN_CLASSB(i))
D 7
		return ((i)&IN_CLASSBHOST);
E 7
I 7
		return ((i)&IN_CLASSB_HOST);
E 7
	else
E 14
I 14
	if (IN_CLASSA(i)) {
D 15
		if (IN_SUBNETA(i) &&
		    in_localnet(((i)&IN_CLASSA_NET) >> IN_CLASSA_NSHIFT))
			return ((i)&IN_CLASSA_SUBHOST);
		else
			return ((i)&IN_CLASSA_HOST);
E 15
I 15
D 18
		if (IN_SUBNETA(i)) {
			net = (i & IN_CLASSA_NET) >> IN_CLASSA_NSHIFT;
			host = i & IN_CLASSA_HOST;
			subhost = i & IN_CLASSA_SUBHOST;
			/* Fall through and check whether a subnet */
		} else
			return (i & IN_CLASSA_HOST);
E 18
I 18
		net = i & IN_CLASSA_NET;
		host = i & IN_CLASSA_HOST;
E 18
E 15
	} else if (IN_CLASSB(i)) {
D 15
		if (IN_SUBNETB(i) &&
		    in_localnet(((i)&IN_CLASSB_NET) >> IN_CLASSB_NSHIFT) )
			return ((i)&IN_CLASSB_SUBHOST);
		else
			return ((i)&IN_CLASSB_HOST);
E 15
I 15
D 18
		if (IN_SUBNETB(i)) {
			net = (i & IN_CLASSB_NET) >> IN_CLASSB_NSHIFT;
			host = i & IN_CLASSB_HOST;
			subhost = i & IN_CLASSB_SUBHOST;
			/* Fall through and check whether a subnet */
		} else
			return (i & IN_CLASSB_HOST);
E 18
I 18
		net = i & IN_CLASSB_NET;
		host = i & IN_CLASSB_HOST;
E 18
E 15
D 33
	} else {
E 33
I 33
	} else if (IN_CLASSC(i)) {
E 33
E 14
D 7
		return ((i)&IN_CLASSCHOST);
E 7
I 7
D 15
		return ((i)&IN_CLASSC_HOST);
E 15
I 15
D 18
		return (i & IN_CLASSC_HOST);
E 18
I 18
		net = i & IN_CLASSC_NET;
		host = i & IN_CLASSC_HOST;
E 18
E 15
I 14
D 33
	}
E 33
I 33
	} else
		return (i);
E 33
D 15
}
E 15

D 15
/*
 * Return true if the network is a ``local'' net
 * (one for which we can interpret the host part).
 */
in_localnet(net)
	register int net;
{
	register struct ifnet *ifp;

E 15
I 15
	/*
D 18
	 * Check whether network is a subnet of a `local' network;
E 18
I 18
	 * Check whether network is a subnet;
E 18
	 * if so, use the modified interpretation of `host'.
	 */
E 15
D 18
	for (ifp = ifnet; ifp; ifp = ifp->if_next) {
		if (ifp->if_addr.sa_family != AF_INET)
			continue;
		if (ifp->if_flags & IFF_LOCAL) {
			if (ifp->if_net == net)
D 15
				return (1);
E 15
I 15
			    return (subhost);
E 15
			if ((ifp->if_net >> SUBNETSHIFT) == net)
D 15
				return (1);
E 15
I 15
			    return (subhost);
E 15
		}
	}
E 18
I 18
	for (ia = in_ifaddr; ia; ia = ia->ia_next)
D 21
		if ((ia->ia_netmask & net) == ia->ia_net)
E 21
I 21
		if (net == ia->ia_net)
E 21
			return (host &~ ia->ia_subnetmask);
E 18
D 15
	return (0);
E 15
I 15
	return (host);
E 15
E 14
E 7
E 5
}
I 8
D 11
#endif
E 11
E 8

I 25
#ifndef SUBNETSARELOCAL
#define	SUBNETSARELOCAL	1
#endif
int subnetsarelocal = SUBNETSARELOCAL;
E 25
/*
I 17
D 18
 * Return 1 if an internet address is for a ``local'' host.
E 18
I 18
 * Return 1 if an internet address is for a ``local'' host
D 21
 * (one to which we have a connection).
E 21
I 21
D 25
 * (one to which we have a connection through a local logical net).
E 25
I 25
 * (one to which we have a connection).  If subnetsarelocal
 * is true, this includes other subnets of the local net.
 * Otherwise, it includes only the directly-connected (sub)nets.
E 25
E 21
E 18
 */
in_localaddr(in)
	struct in_addr in;
{
	register u_long i = ntohl(in.s_addr);
D 32
	register u_long net;
E 32
D 18
	register struct ifnet *ifp;
E 18
I 18
	register struct in_ifaddr *ia;
E 18

D 32
	if (IN_CLASSA(i))
D 18
		net = (i & IN_CLASSA_NET) >> IN_CLASSA_NSHIFT;
E 18
I 18
		net = i & IN_CLASSA_NET;
E 18
	else if (IN_CLASSB(i))
D 18
		net = (i & IN_CLASSB_NET) >> IN_CLASSB_NSHIFT;
E 18
I 18
		net = i & IN_CLASSB_NET;
E 18
	else
D 18
		net = (i & IN_CLASSC_NET) >> IN_CLASSC_NSHIFT;
E 18
I 18
		net = i & IN_CLASSC_NET;
E 18

D 18
	for (ifp = ifnet; ifp; ifp = ifp->if_next) {
		if (ifp->if_addr.sa_family != AF_INET)
			continue;
		if (ifp->if_flags & IFF_LOCAL) {
			if (ifp->if_net == net)
				return (1);
			if ((ifp->if_net >> SUBNETSHIFT) == net)
				return (1);
E 18
I 18
	for (ia = in_ifaddr; ia; ia = ia->ia_next)
D 21
		if ((ia->ia_netmask & net) == ia->ia_net)
E 21
I 21
D 25
		if (net == ia->ia_net)
E 25
I 25
D 30
		if (net == subnetsarelocal ? ia->ia_net : ia->ia_subnet)
E 30
I 30
		if (net == (subnetsarelocal ? ia->ia_net : ia->ia_subnet))
E 30
E 25
E 21
			return (1);
E 32
I 32
	if (subnetsarelocal) {
		for (ia = in_ifaddr; ia; ia = ia->ia_next)
			if ((i & ia->ia_netmask) == ia->ia_net)
				return (1);
	} else {
		for (ia = in_ifaddr; ia; ia = ia->ia_next)
			if ((i & ia->ia_subnetmask) == ia->ia_subnet)
				return (1);
	}
E 32
	return (0);
I 33
}

/*
 * Determine whether an IP address is in a reserved set of addresses
 * that may not be forwarded, or whether datagrams to that destination
 * may be forwarded.
 */
in_canforward(in)
	struct in_addr in;
{
	register u_long i = ntohl(in.s_addr);
	register u_long net;

	if (IN_EXPERIMENTAL(i))
		return (0);
	if (IN_CLASSA(i)) {
		net = i & IN_CLASSA_NET;
		if (net == 0 || net == IN_LOOPBACKNET)
			return (0);
	}
	return (1);
E 33
}

I 21
int	in_interfaces;		/* number of external internet interfaces */
extern	struct ifnet loif;

E 21
/*
 * Generic internet control operations (ioctl's).
 * Ifp is 0 if not an interface-specific ioctl.
 */
I 21
/* ARGSUSED */
E 21
in_control(so, cmd, data, ifp)
	struct socket *so;
	int cmd;
	caddr_t data;
	register struct ifnet *ifp;
{
	register struct ifreq *ifr = (struct ifreq *)data;
	register struct in_ifaddr *ia = 0;
I 22
D 35
	u_long tmp;
E 35
E 22
	struct ifaddr *ifa;
	struct mbuf *m;
	int error;

	/*
	 * Find address for this interface, if it exists.
	 */
	if (ifp)
		for (ia = in_ifaddr; ia; ia = ia->ia_next)
			if (ia->ia_ifp == ifp)
				break;

	switch (cmd) {

D 24
	case SIOCGIFADDR:
	case SIOCGIFBRDADDR:
	case SIOCGIFDSTADDR:
	case SIOCGIFNETMASK:
		if (ia == (struct in_ifaddr *)0)
			return (EADDRNOTAVAIL);
		break;

E 24
	case SIOCSIFADDR:
D 24
	case SIOCSIFDSTADDR:
	case SIOCSIFBRDADDR:
E 24
	case SIOCSIFNETMASK:
I 27
	case SIOCSIFDSTADDR:
E 27
		if (!suser())
			return (u.u_error);

		if (ifp == 0)
			panic("in_control");
		if (ia == (struct in_ifaddr *)0) {
			m = m_getclr(M_WAIT, MT_IFADDR);
			if (m == (struct mbuf *)NULL)
				return (ENOBUFS);
			if (ia = in_ifaddr) {
				for ( ; ia->ia_next; ia = ia->ia_next)
					;
				ia->ia_next = mtod(m, struct in_ifaddr *);
			} else
				in_ifaddr = mtod(m, struct in_ifaddr *);
			ia = mtod(m, struct in_ifaddr *);
			if (ifa = ifp->if_addrlist) {
				for ( ; ifa->ifa_next; ifa = ifa->ifa_next)
					;
				ifa->ifa_next = (struct ifaddr *) ia;
			} else
				ifp->if_addrlist = (struct ifaddr *) ia;
			ia->ia_ifp = ifp;
			IA_SIN(ia)->sin_family = AF_INET;
I 21
			if (ifp != &loif)
				in_interfaces++;
E 21
E 18
		}
I 18
		break;
I 24

	case SIOCSIFBRDADDR:
D 27
	case SIOCSIFDSTADDR:
E 27
		if (!suser())
			return (u.u_error);
		/* FALLTHROUGH */

	default:
		if (ia == (struct in_ifaddr *)0)
			return (EADDRNOTAVAIL);
		break;
E 24
E 18
	}
I 18

	switch (cmd) {

	case SIOCGIFADDR:
		ifr->ifr_addr = ia->ia_addr;
		break;

	case SIOCGIFBRDADDR:
		if ((ifp->if_flags & IFF_BROADCAST) == 0)
			return (EINVAL);
		ifr->ifr_dstaddr = ia->ia_broadaddr;
		break;

	case SIOCGIFDSTADDR:
		if ((ifp->if_flags & IFF_POINTOPOINT) == 0)
			return (EINVAL);
		ifr->ifr_dstaddr = ia->ia_dstaddr;
		break;

	case SIOCGIFNETMASK:
#define	satosin(sa)	((struct sockaddr_in *)(sa))
		satosin(&ifr->ifr_addr)->sin_family = AF_INET;
		satosin(&ifr->ifr_addr)->sin_addr.s_addr = htonl(ia->ia_subnetmask);
		break;

	case SIOCSIFDSTADDR:
I 28
	    {
		struct sockaddr oldaddr;

E 28
		if ((ifp->if_flags & IFF_POINTOPOINT) == 0)
			return (EINVAL);
I 28
		oldaddr = ia->ia_dstaddr;
		ia->ia_dstaddr = ifr->ifr_dstaddr;
E 28
		if (ifp->if_ioctl &&
D 21
		    (error = (*ifp->if_ioctl)(ifp, SIOCSIFADDR, ia)))
E 21
I 21
D 28
		    (error = (*ifp->if_ioctl)(ifp, SIOCSIFDSTADDR, ia)))
E 28
I 28
		    (error = (*ifp->if_ioctl)(ifp, SIOCSIFDSTADDR, ia))) {
			ia->ia_dstaddr = oldaddr;
E 28
E 21
			return (error);
D 28
		ia->ia_dstaddr = ifr->ifr_dstaddr;
E 28
I 28
		}
		if (ia->ia_flags & IFA_ROUTE) {
			rtinit(&oldaddr, &ia->ia_addr, (int)SIOCDELRT,
			    RTF_HOST);
			rtinit(&ia->ia_dstaddr, &ia->ia_addr, (int)SIOCADDRT,
			    RTF_HOST|RTF_UP);
		}
	    }
E 28
		break;

	case SIOCSIFBRDADDR:
		if ((ifp->if_flags & IFF_BROADCAST) == 0)
			return (EINVAL);
		ia->ia_broadaddr = ifr->ifr_broadaddr;
I 22
D 35
		tmp = ntohl(satosin(&ia->ia_broadaddr)->sin_addr.s_addr);
		if ((tmp &~ ia->ia_subnetmask) == ~ia->ia_subnetmask)
			tmp |= ~ia->ia_netmask;
		else if ((tmp &~ ia->ia_subnetmask) == 0)
			tmp &= ia->ia_netmask;
		ia->ia_netbroadcast.s_addr = htonl(tmp);
E 35
E 22
		break;

	case SIOCSIFADDR:
D 36
		return (in_ifinit(ifp, ia, &ifr->ifr_addr));
E 36
I 36
		return (in_ifinit(ifp, ia,
		    (struct sockaddr_in *) &ifr->ifr_addr));
E 36
D 21
		break;
E 21

	case SIOCSIFNETMASK:
		ia->ia_subnetmask = ntohl(satosin(&ifr->ifr_addr)->sin_addr.s_addr);
		break;

	default:
		if (ifp == 0 || ifp->if_ioctl == 0)
			return (EOPNOTSUPP);
		return ((*ifp->if_ioctl)(ifp, cmd, data));
	}
E 18
	return (0);
}

/*
E 17
D 18
 * Initialize an interface's routing
 * table entry according to the network.
 * INTERNET SPECIFIC.
E 18
I 18
 * Initialize an interface's internet address
 * and routing table entry.
E 18
 */
D 18
if_rtinit(ifp, flags)
E 18
I 18
in_ifinit(ifp, ia, sin)
E 18
	register struct ifnet *ifp;
D 18
	int flags;
E 18
I 18
	register struct in_ifaddr *ia;
	struct sockaddr_in *sin;
E 18
{
D 18
	struct sockaddr_in sin;
E 18
I 18
	register u_long i = ntohl(sin->sin_addr.s_addr);
D 24
	struct sockaddr_in netaddr;
E 24
I 24
D 28
	struct sockaddr_in tmpaddr;
E 28
I 28
	struct sockaddr oldaddr;
	struct sockaddr_in netaddr;
E 28
E 24
	int s = splimp(), error;
E 18

D 3
COUNT(IF_RTINIT);
E 3
D 18
	if (ifp->if_flags & IFF_ROUTE)
		return;
	bzero((caddr_t)&sin, sizeof (sin));
	sin.sin_family = AF_INET;
D 12
	sin.sin_addr = if_makeaddr(ifp->if_net, 0);
E 12
I 12
	sin.sin_addr = if_makeaddr(ifp->if_net, INADDR_ANY);
E 12
D 6
	rtinit(&sin, &ifp->if_addr, flags);
E 6
I 6
	rtinit((struct sockaddr *)&sin, &ifp->if_addr, flags);
E 18
I 18
D 24
	bzero((caddr_t)&netaddr, sizeof (netaddr));
	netaddr.sin_family = AF_INET;
E 24
I 24
D 28
	tmpaddr = *(struct sockaddr_in *)&ia->ia_addr;
E 28
I 28
	oldaddr = ia->ia_addr;
E 28
	ia->ia_addr = *(struct sockaddr *)sin;

E 24
	/*
I 24
	 * Give the interface a chance to initialize
	 * if this is its first address,
	 * and to validate the address if necessary.
	 */
	if (ifp->if_ioctl && (error = (*ifp->if_ioctl)(ifp, SIOCSIFADDR, ia))) {
		splx(s);
D 28
		ia->ia_addr = *(struct sockaddr *)&tmpaddr;
E 28
I 28
		ia->ia_addr = oldaddr;
E 28
		return (error);
	}

D 28
	bzero((caddr_t)&tmpaddr, sizeof (tmpaddr));
	tmpaddr.sin_family = AF_INET;
E 28
	/*
E 24
	 * Delete any previous route for an old address.
	 */
I 28
	bzero((caddr_t)&netaddr, sizeof (netaddr));
	netaddr.sin_family = AF_INET;
E 28
	if (ia->ia_flags & IFA_ROUTE) {
D 28
		if ((ifp->if_flags & IFF_POINTOPOINT) == 0) {
D 24
		    netaddr.sin_addr = in_makeaddr(ia->ia_subnet, INADDR_ANY);
D 23
		    rtinit((struct sockaddr *)&netaddr, &ia->ia_addr, -1);
E 23
I 23
		    rtinit((struct sockaddr *)&netaddr, &ia->ia_addr, 
E 24
I 24
		    tmpaddr.sin_addr = in_makeaddr(ia->ia_subnet, INADDR_ANY);
		    rtinit((struct sockaddr *)&tmpaddr, &ia->ia_addr, 
E 28
I 28
		if (ifp->if_flags & IFF_LOOPBACK)
			rtinit(&oldaddr, &oldaddr, (int)SIOCDELRT, RTF_HOST);
		else if (ifp->if_flags & IFF_POINTOPOINT)
			rtinit(&ia->ia_dstaddr, &oldaddr, (int)SIOCDELRT,
			    RTF_HOST);
		else {
			netaddr.sin_addr = in_makeaddr(ia->ia_subnet,
			    INADDR_ANY);
			rtinit((struct sockaddr *)&netaddr, &oldaddr, 
E 28
E 24
			    (int)SIOCDELRT, 0);
E 23
D 28
		} else
D 23
		    rtinit((struct sockaddr *)&ia->ia_dstaddr, &ia->ia_addr, -1);
E 23
I 23
		    rtinit((struct sockaddr *)&ia->ia_dstaddr, &ia->ia_addr,
			    (int)SIOCDELRT, RTF_HOST);
E 28
I 28
		}
E 28
E 23
		ia->ia_flags &= ~IFA_ROUTE;
	}
D 24
	ia->ia_addr = *(struct sockaddr *)sin;
E 24
	if (IN_CLASSA(i))
		ia->ia_netmask = IN_CLASSA_NET;
	else if (IN_CLASSB(i))
		ia->ia_netmask = IN_CLASSB_NET;
	else
		ia->ia_netmask = IN_CLASSC_NET;
	ia->ia_net = i & ia->ia_netmask;
	/*
	 * The subnet mask includes at least the standard network part,
	 * but may already have been set to a larger value.
	 */
	ia->ia_subnetmask |= ia->ia_netmask;
	ia->ia_subnet = i & ia->ia_subnetmask;
	if (ifp->if_flags & IFF_BROADCAST) {
		ia->ia_broadaddr.sa_family = AF_INET;
		((struct sockaddr_in *)(&ia->ia_broadaddr))->sin_addr =
			in_makeaddr(ia->ia_subnet, INADDR_BROADCAST);
I 22
		ia->ia_netbroadcast.s_addr =
		    htonl(ia->ia_net | (INADDR_BROADCAST &~ ia->ia_netmask));
E 22
	}
D 24

	/*
	 * Give the interface a chance to initialize
	 * if this is its first address,
	 * and to validate the address if necessary.
	 */
	if (ifp->if_ioctl && (error = (*ifp->if_ioctl)(ifp, SIOCSIFADDR, ia))) {
		splx(s);
		bzero((caddr_t)&ia->ia_addr, sizeof(ia->ia_addr));
		return (error);
	}
E 24
D 31
	splx(s);
E 31
	/*
	 * Add route for the network.
	 */
D 28
	if ((ifp->if_flags & IFF_POINTOPOINT) == 0) {
D 24
		netaddr.sin_addr = in_makeaddr(ia->ia_subnet, INADDR_ANY);
D 23
		rtinit((struct sockaddr *)&netaddr, &ia->ia_addr, RTF_UP);
E 23
I 23
		rtinit((struct sockaddr *)&netaddr, &ia->ia_addr,
E 24
I 24
		tmpaddr.sin_addr = in_makeaddr(ia->ia_subnet, INADDR_ANY);
		rtinit((struct sockaddr *)&tmpaddr, &ia->ia_addr,
E 24
			(int)SIOCADDRT, RTF_UP);
E 23
	} else
		rtinit((struct sockaddr *)&ia->ia_dstaddr, &ia->ia_addr,
D 23
			RTF_HOST|RTF_UP);
E 23
I 23
			(int)SIOCADDRT, RTF_HOST|RTF_UP);
E 28
I 28
	if (ifp->if_flags & IFF_LOOPBACK)
		rtinit(&ia->ia_addr, &ia->ia_addr, (int)SIOCADDRT,
		    RTF_HOST|RTF_UP);
	else if (ifp->if_flags & IFF_POINTOPOINT)
		rtinit(&ia->ia_dstaddr, &ia->ia_addr, (int)SIOCADDRT,
		    RTF_HOST|RTF_UP);
	else {
		netaddr.sin_addr = in_makeaddr(ia->ia_subnet, INADDR_ANY);
		rtinit((struct sockaddr *)&netaddr, &ia->ia_addr,
		    (int)SIOCADDRT, RTF_UP);
	}
E 28
E 23
	ia->ia_flags |= IFA_ROUTE;
I 31
	splx(s);
E 31
I 19
	return (0);
E 19
}

/*
 * Return address info for specified internet network.
 */
struct in_ifaddr *
in_iaonnetof(net)
	u_long net;
{
	register struct in_ifaddr *ia;

	for (ia = in_ifaddr; ia; ia = ia->ia_next)
		if (ia->ia_subnet == net)
			return (ia);
	return ((struct in_ifaddr *)0);
}

/*
D 31
 * Return 1 if the address is a local broadcast address.
E 31
I 31
 * Return 1 if the address might be a local broadcast address.
E 31
 */
in_broadcast(in)
	struct in_addr in;
{
	register struct in_ifaddr *ia;
I 31
	u_long t;
E 31

	/*
	 * Look through the list of addresses for a match
	 * with a broadcast address.
	 */
	for (ia = in_ifaddr; ia; ia = ia->ia_next)
D 31
	    if (((struct sockaddr_in *)&ia->ia_broadaddr)->sin_addr.s_addr ==
		in.s_addr && (ia->ia_ifp->if_flags & IFF_BROADCAST))
E 31
I 31
	    if (ia->ia_ifp->if_flags & IFF_BROADCAST) {
		if (satosin(&ia->ia_broadaddr)->sin_addr.s_addr == in.s_addr)
E 31
		     return (1);
I 31
		/*
		 * Check for old-style (host 0) broadcast.
		 */
		if ((t = ntohl(in.s_addr)) == ia->ia_subnet || t == ia->ia_net)
		    return (1);
	}
	if (in.s_addr == INADDR_BROADCAST || in.s_addr == INADDR_ANY)
		return (1);
E 31
	return (0);
E 18
E 6
}
#endif
E 1
