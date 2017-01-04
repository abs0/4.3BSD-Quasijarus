h05538
s 00011/00006/00291
d D 7.3 88/06/29 17:13:14 bostic 10 9
c install approved copyright notice
e
s 00010/00004/00287
d D 7.2 88/01/20 15:15:08 sklower 9 8
c Change licensing/use notice.
e
s 00001/00001/00290
d D 7.1 86/06/05 00:36:04 mckusick 8 7
c 4.3BSD release version
e
s 00010/00008/00281
d D 6.7 86/02/03 17:31:50 sklower 7 6
c remove ns_netof (non-portable), add zero and broadcast ns nets to compare to.
e
s 00052/00044/00237
d D 6.6 85/11/09 15:57:12 sklower 6 5
c change the way pt to pt links are handle to be closer to inet
c to allow net(addr)!=net(dstaddr); also change interface to rtinit so that
c renaming pt to pt links will delete existing routes.
e
s 00025/00007/00256
d D 6.5 85/09/26 16:09:44 sklower 5 4
c make ns_iaonnetof smarter about point to point links, and think about the issue of longs which need to be long aligned.
e
s 00001/00001/00262
d D 6.4 85/08/09 11:35:00 sklower 4 3
c 
e
s 00025/00031/00238
d D 6.3 85/07/31 13:01:36 sklower 3 2
c Allow non super users to run ifconfig to get state of interface.
e
s 00007/00001/00262
d D 6.2 85/06/08 12:49:25 mckusick 2 1
c Add copyright
e
s 00263/00000/00000
d D 6.1 85/05/30 19:10:50 sklower 1 0
c date and time created 85/05/30 19:10:50 by sklower
e
u
U
t
T
I 1
D 2
/*      %M%     %I%     %E%     */
E 2
I 2
/*
D 6
 * Copyright (c) 1982 Regents of the University of California.
E 6
I 6
D 8
 * Copyright (c) 1984, 1985 Regents of the University of California.
E 8
I 8
D 9
 * Copyright (c) 1984, 1985, 1986 Regents of the University of California.
E 8
E 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 9
I 9
 * Copyright (c) 1984, 1985, 1986, 1987 Regents of the University of California.
 * All rights reserved.
E 9
 *
D 9
 *	%W% (Berkeley) %G%
E 9
I 9
 * Redistribution and use in source and binary forms are permitted
D 10
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
I 10
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
E 10
 *
D 10
 *      %W% (Berkeley) %G%
E 10
I 10
 *	%W% (Berkeley) %G%
E 10
E 9
 */
E 2

#include "param.h"
#include "mbuf.h"
#include "ioctl.h"
#include "protosw.h"
#include "socket.h"
#include "socketvar.h"
#include "uio.h"
#include "dir.h"
#include "user.h"


#include "../net/if.h"
#include "../net/route.h"
#include "../net/af.h"

#include "ns.h"
#include "ns_if.h"

#ifdef NS

struct ns_ifaddr *ns_ifaddr;

ns_hash(sns, hp)
	register struct sockaddr_ns *sns;
	struct afhash *hp;
{
	register long hash = 0;
	register u_short *s =  sns->sns_addr.x_host.s_host;
I 7
	union {
		union ns_net	net_e;
		long		long_e;
	} net;
E 7

D 7
	hp->afh_nethash = ns_netof(sns->sns_addr);
E 7
I 7
	net.net_e = sns->sns_addr.x_net;
	hp->afh_nethash = net.long_e;
E 7
	hash = *s++; hash <<= 8; hash += *s++; hash <<= 8; hash += *s;
	hp->afh_hosthash =  hash;
}


ns_netmatch(sns1, sns2)
	struct sockaddr_ns *sns1, *sns2;
{

D 7
	return (ns_netof(sns1->sns_addr) == ns_netof(sns2->sns_addr));
E 7
I 7
	return (ns_neteq(sns1->sns_addr, sns2->sns_addr));
E 7
}

/*
 * Generic internet control operations (ioctl's).
 */
I 4
/* ARGSUSED */
E 4
ns_control(so, cmd, data, ifp)
	struct socket *so;
	int cmd;
	caddr_t data;
	register struct ifnet *ifp;
{
	register struct ifreq *ifr = (struct ifreq *)data;
	register struct ns_ifaddr *ia;
	struct ifaddr *ifa;
	struct mbuf *m;
D 4
	int error;
E 4

D 3
	if (!suser())
		return (u.u_error);

E 3
	/*
	 * Find address for this interface, if it exists.
	 */
I 3
D 6
	if (ifp==0)
E 6
I 6
	if (ifp == 0)
E 6
		return (EADDRNOTAVAIL);
E 3
	for (ia = ns_ifaddr; ia; ia = ia->ia_next)
		if (ia->ia_ifp == ifp)
			break;

	switch (cmd) {

	case SIOCGIFADDR:
I 3
		if (ia == (struct ns_ifaddr *)0)
			return (EADDRNOTAVAIL);
		ifr->ifr_addr = ia->ia_addr;
		return (0);


E 3
	case SIOCGIFBRDADDR:
I 3
		if (ia == (struct ns_ifaddr *)0)
			return (EADDRNOTAVAIL);
		if ((ifp->if_flags & IFF_BROADCAST) == 0)
			return (EINVAL);
		ifr->ifr_dstaddr = ia->ia_broadaddr;
		return (0);

E 3
	case SIOCGIFDSTADDR:
		if (ia == (struct ns_ifaddr *)0)
			return (EADDRNOTAVAIL);
D 3
		break;
E 3
I 3
		if ((ifp->if_flags & IFF_POINTOPOINT) == 0)
			return (EINVAL);
		ifr->ifr_dstaddr = ia->ia_dstaddr;
		return (0);
	}
E 3

I 3
	if (!suser())
		return (u.u_error);

	switch (cmd) {

E 3
D 6
	case SIOCSIFDSTADDR:
		return (EOPNOTSUPP);

E 6
	case SIOCSIFADDR:
I 6
	case SIOCSIFDSTADDR:
E 6
		if (ia == (struct ns_ifaddr *)0) {
			m = m_getclr(M_WAIT, MT_IFADDR);
			if (m == (struct mbuf *)NULL)
				return (ENOBUFS);
			if (ia = ns_ifaddr) {
				for ( ; ia->ia_next; ia = ia->ia_next)
					;
				ia->ia_next = mtod(m, struct ns_ifaddr *);
			} else
				ns_ifaddr = mtod(m, struct ns_ifaddr *);
			ia = mtod(m, struct ns_ifaddr *);
			if (ifa = ifp->if_addrlist) {
				for ( ; ifa->ifa_next; ifa = ifa->ifa_next)
					;
				ifa->ifa_next = (struct ifaddr *) ia;
			} else
				ifp->if_addrlist = (struct ifaddr *) ia;
			ia->ia_ifp = ifp;
			IA_SNS(ia)->sns_family = AF_NS;
		}
I 6
	}

	switch (cmd) {

	case SIOCSIFDSTADDR:
		if ((ifp->if_flags & IFF_POINTOPOINT) == 0)
			return (EINVAL);
		if (ia->ia_flags & IFA_ROUTE) {
			rtinit(&ia->ia_dstaddr, &ia->ia_addr,
				(int)SIOCDELRT, RTF_HOST);
			ia->ia_flags &= ~IFA_ROUTE;
		}
		if (ifp->if_ioctl) {
			int error = (*ifp->if_ioctl)(ifp, SIOCSIFDSTADDR, ia);
			if (error)
				return (error);
		}
		ia->ia_dstaddr = ifr->ifr_dstaddr;
		return (0);

	case SIOCSIFADDR:
E 6
D 3
		break;
	}

	switch (cmd) {

	case SIOCGIFADDR:
		ifr->ifr_addr = ia->ia_addr;
		break;

	case SIOCGIFBRDADDR:
		if (ia == (struct ns_ifaddr *)0)
			return (EADDRNOTAVAIL);
		if ((ifp->if_flags & IFF_BROADCAST) == 0)
			return (EINVAL);
		ifr->ifr_dstaddr = ia->ia_broadaddr;
		break;

	case SIOCGIFDSTADDR:
		if (ia == (struct ns_ifaddr *)0)
			return (EADDRNOTAVAIL);
		if ((ifp->if_flags & IFF_POINTOPOINT) == 0)
			return (EINVAL);
		ifr->ifr_dstaddr = ia->ia_dstaddr;
		break;

	case SIOCSIFADDR:
E 3
		return
		    (ns_ifinit(ifp, ia, (struct sockaddr_ns *)&ifr->ifr_addr));

	default:
		if (ifp->if_ioctl == 0)
			return (EOPNOTSUPP);
		return ((*ifp->if_ioctl)(ifp, cmd, data));
	}
D 3
	return (0);
E 3
}

/*
 * Initialize an interface's internet address
 * and routing table entry.
 */
ns_ifinit(ifp, ia, sns)
	register struct ifnet *ifp;
	register struct ns_ifaddr *ia;
	struct sockaddr_ns *sns;
{
	struct sockaddr_ns netaddr;
	register union ns_host *h = &(IA_SNS(ia)->sns_addr.x_host);
	int s = splimp(), error;

	/*
	 * The convention we shall adopt for naming is that
	 * a supplied address of zero means that "we don't care".
	 * if there is a single interface, use the address of that
	 * interface as our 6 byte host address.
	 * if there are multiple interfaces, use any address already
	 * used.
	 *
	 * If we have gotten into trouble and want to reset back to
	 * virginity, we recognize a request of the broadcast address.
	 */
	if (ns_hosteqnh(sns->sns_addr.x_host, ns_broadhost)) {
		ns_thishost = ns_zerohost;
		splx(s);
D 6
		return(EINVAL);
E 6
I 6
		return (0);
E 6
	}

	/*
	 * Delete any previous route for an old address.
	 */
D 6

E 6
	bzero((caddr_t)&netaddr, sizeof (netaddr));
	netaddr.sns_family = AF_NS;
	netaddr.sns_addr.x_host = ns_broadhost;
	netaddr.sns_addr.x_net = ia->ia_net;
	if (ia->ia_flags & IFA_ROUTE) {
		if ((ifp->if_flags & IFF_POINTOPOINT) == 0) {
D 6
		    rtinit((struct sockaddr *)&netaddr, &ia->ia_addr, -1);
E 6
I 6
		    rtinit((struct sockaddr *)&netaddr, &ia->ia_addr,
				    (int)SIOCDELRT, 0);
E 6
		} else
D 6
		    rtinit((struct sockaddr *)&ia->ia_dstaddr, &ia->ia_addr, -1);
E 6
I 6
		    rtinit(&ia->ia_dstaddr, &ia->ia_addr,
				    (int)SIOCDELRT, RTF_HOST);
E 6
	}

	/*
	 * Set up new addresses.
	 */
	ia->ia_addr = *(struct sockaddr *)sns;
	ia->ia_net = sns->sns_addr.x_net;
	netaddr.sns_addr.x_net = ia->ia_net;
	if (ifp->if_flags & IFF_BROADCAST) {
		ia->ia_broadaddr = * (struct sockaddr *) &netaddr;
	}
I 6

E 6
	/*
D 6
	 * Point to point links are a little touchier --
	 * We have to have an address of our own first,
	 * and will use the supplied address as that of the other end.
	 */
	if (ifp->if_flags & IFF_POINTOPOINT) {
		struct sockaddr_ns *sns2 = IA_SNS(ia);
		if (ns_hosteqnh(ns_zerohost,ns_thishost))
			return(EINVAL);
		ia->ia_dstaddr = ia->ia_addr;
		sns2->sns_addr.x_host = ns_thishost;
		sns->sns_addr.x_host = ns_thishost;
	}
	/*
E 6
	 * Give the interface a chance to initialize
	 * if this is its first address,
	 * and to validate the address if necessary.
	 */
D 6

E 6
	if (ns_hosteqnh(ns_thishost, ns_zerohost)) {
		if (ifp->if_ioctl &&
		     (error = (*ifp->if_ioctl)(ifp, SIOCSIFADDR, ia))) {
			splx(s);
			return (error);
		}
		ns_thishost = *h;
	} else if (ns_hosteqnh(sns->sns_addr.x_host, ns_zerohost)
	    || ns_hosteqnh(sns->sns_addr.x_host, ns_thishost)) {
		*h = ns_thishost;
		if (ifp->if_ioctl &&
		     (error = (*ifp->if_ioctl)(ifp, SIOCSIFADDR, ia))) {
			splx(s);
			return (error);
		}
D 6
		if(!ns_hosteqnh(ns_thishost,*h)) {
E 6
I 6
		if (!ns_hosteqnh(ns_thishost,*h)) {
E 6
			splx(s);
			return (EINVAL);
		}
	} else {
		splx(s);
D 6
		return(EINVAL);
E 6
I 6
		return (EINVAL);
E 6
	}
I 6

E 6
	/*
	 * Add route for the network.
	 */
D 6
	if ((ifp->if_flags & IFF_POINTOPOINT) == 0) {
		rtinit((struct sockaddr *)&netaddr, &ia->ia_addr, RTF_UP);
	} else
		rtinit((struct sockaddr *)&ia->ia_dstaddr, &ia->ia_addr,
E 6
I 6
	if (ifp->if_flags & IFF_POINTOPOINT)
		rtinit(&ia->ia_dstaddr, &ia->ia_addr, (int)SIOCADDRT,
E 6
			RTF_HOST|RTF_UP);
I 6
	else
		rtinit(&ia->ia_broadaddr, &ia->ia_addr, (int)SIOCADDRT,
			RTF_UP);
E 6
	ia->ia_flags |= IFA_ROUTE;
D 6
	return(0);
E 6
I 6
	return (0);
E 6
}

/*
 * Return address info for specified internet network.
 */
struct ns_ifaddr *
D 5
ns_iaonnetof(net)
	union ns_net net;
E 5
I 5
ns_iaonnetof(dst)
	register struct ns_addr *dst;
E 5
{
	register struct ns_ifaddr *ia;
I 5
	register struct ns_addr *compare;
D 6
	struct ifnet *ifp;
E 6
I 6
	register struct ifnet *ifp;
	struct ns_ifaddr *ia_maybe = 0;
E 6
D 7
	long net = ns_netof(*dst);
	static struct ns_addr laddr;
E 7
I 7
	union ns_net net = dst->x_net;
E 7
D 6
	struct ns_ifaddr *ia_maybe = 0;
E 6
E 5

D 5
#define	NtoL(x)	(*(long *)(&(x)))
	for (ia = ns_ifaddr; ia; ia = ia->ia_next)
		if (NtoL(ia->ia_net) == NtoL(net))
			return (ia);
	return ((struct ns_ifaddr *)0);
E 5
I 5
	for (ia = ns_ifaddr; ia; ia = ia->ia_next) {
D 6
		laddr.x_net = ia->ia_net;
		if (ns_netof(laddr) == net) {
			ia_maybe = ia;
			ifp = ia->ia_ifp;
			if (ifp) {
				if (ifp->if_flags & IFF_POINTOPOINT) {
					compare = &satons_addr(ia->ia_dstaddr);
					if (ns_hosteq(*dst, *compare))
						return (ia);
					else
						continue;
				} else
E 6
I 6
		if (ifp = ia->ia_ifp) {
			if (ifp->if_flags & IFF_POINTOPOINT) {
				compare = &satons_addr(ia->ia_dstaddr);
				if (ns_hosteq(*dst, *compare))
					return (ia);
D 7
				laddr.x_net = ia->ia_net;
				if (ns_netof(laddr) == net)
E 7
I 7
				if (ns_neteqnn(net, ia->ia_net))
E 7
					ia_maybe = ia;
			} else {
D 7
				laddr.x_net = ia->ia_net;
				if (ns_netof(laddr) == net)
E 7
I 7
				if (ns_neteqnn(net, ia->ia_net))
E 7
E 6
					return (ia);
			}
		}
	}
	return (ia_maybe);
E 5
}
#endif
E 1
