h47644
s 00011/00006/00314
d D 7.5 88/06/29 17:13:31 bostic 13 12
c install approved copyright notice
e
s 00000/00001/00320
d D 7.4 88/05/22 14:58:34 karels 12 11
c lint
e
s 00010/00004/00311
d D 7.3 88/01/20 15:15:25 sklower 11 10
c Change licensing/use notice.
e
s 00039/00051/00276
d D 7.2 87/12/12 23:23:50 karels 10 9
c checked in for sklower (it must work by now)
e
s 00001/00001/00326
d D 7.1 86/06/05 00:37:41 mckusick 9 8
c 4.3BSD release version
e
s 00002/00000/00325
d D 6.8 86/06/02 14:48:41 karels 8 7
c lint
e
s 00002/00001/00323
d D 6.7 86/02/21 17:14:03 sklower 7 6
c when you route around a dead interface, don't uses its net number
e
s 00001/00001/00323
d D 6.6 86/02/03 17:40:45 sklower 6 5
c Correct erroneous copyright information.
e
s 00036/00015/00288
d D 6.5 85/09/26 15:54:37 sklower 5 4
c handle route caching here.  
e
s 00002/00002/00301
d D 6.4 85/08/09 11:35:29 sklower 4 3
c 
e
s 00007/00004/00296
d D 6.3 85/07/04 20:18:29 sklower 3 2
c Bug in choosing net for return address.
e
s 00007/00001/00293
d D 6.2 85/06/08 12:51:22 mckusick 2 1
c Add copyright
e
s 00294/00000/00000
d D 6.1 85/05/30 19:11:01 sklower 1 0
c date and time created 85/05/30 19:11:01 by sklower
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
/*
D 6
 * Copyright (c) 1982 Regents of the University of California.
E 6
I 6
D 9
 * Copyright (c) 1984, 1985 Regents of the University of California.
E 9
I 9
D 11
 * Copyright (c) 1984, 1985, 1986 Regents of the University of California.
E 9
E 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 11
I 11
 * Copyright (c) 1984, 1985, 1986, 1987 Regents of the University of California.
 * All rights reserved.
E 11
 *
D 11
 *	%W% (Berkeley) %G%
E 11
I 11
 * Redistribution and use in source and binary forms are permitted
D 13
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 13
I 13
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
E 13
 *
D 13
 *      %W% (Berkeley) %G%
E 13
I 13
 *	%W% (Berkeley) %G%
E 13
E 11
 */
E 2

#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "mbuf.h"
#include "socket.h"
#include "socketvar.h"
#include "../net/if.h"
#include "../net/route.h"
#include "protosw.h"

#include "ns.h"
#include "ns_if.h"
#include "ns_pcb.h"

struct	ns_addr zerons_addr;

ns_pcballoc(so, head)
	struct socket *so;
D 4
	struct nsp *head;
E 4
I 4
	struct nspcb *head;
E 4
{
	struct mbuf *m;
	register struct nspcb *nsp;

	m = m_getclr(M_DONTWAIT, MT_PCB);
	if (m == NULL)
		return (ENOBUFS);
	nsp = mtod(m, struct nspcb *);
	nsp->nsp_socket = so;
	insque(nsp, head);
	so->so_pcb = (caddr_t)nsp;
	return (0);
}
	
ns_pcbbind(nsp, nam)
	register struct nspcb *nsp;
	struct mbuf *nam;
{
	register struct sockaddr_ns *sns;
	u_short lport = 0;

	if(nsp->nsp_lport || !ns_nullhost(nsp->nsp_laddr))
		return (EINVAL);
	if (nam == 0)
		goto noname;
	sns = mtod(nam, struct sockaddr_ns *);
	if (nam->m_len != sizeof (*sns))
		return (EINVAL);
	if (!ns_nullhost(sns->sns_addr)) {
		int tport = sns->sns_port;

		sns->sns_port = 0;		/* yech... */
		if (ifa_ifwithaddr((struct sockaddr *)sns) == 0)
			return (EADDRNOTAVAIL);
		sns->sns_port = tport;
	}
	lport = sns->sns_port;
	if (lport) {
		u_short aport = ntohs(lport);

		if (aport < NSPORT_RESERVED && u.u_uid != 0)
			return (EACCES);
		if (ns_pcblookup(&zerons_addr, lport, 0))
			return (EADDRINUSE);
	}
	nsp->nsp_laddr = sns->sns_addr;
noname:
	if (lport == 0)
		do {
			if (nspcb.nsp_lport++ < NSPORT_RESERVED)
				nspcb.nsp_lport = NSPORT_RESERVED;
			lport = htons(nspcb.nsp_lport);
		} while (ns_pcblookup(&zerons_addr, lport, 0));
	nsp->nsp_lport = lport;
	return (0);
}

/*
 * Connect from a socket to a specified address.
 * Both address and port must be specified in argument sns.
 * If don't have a local address for this socket yet,
 * then pick one.
 */
ns_pcbconnect(nsp, nam)
	struct nspcb *nsp;
	struct mbuf *nam;
{
	struct ns_ifaddr *ia;
D 5
	struct sockaddr_ns *ifaddr;
E 5
	register struct sockaddr_ns *sns = mtod(nam, struct sockaddr_ns *);
I 10
D 12
	struct sockaddr_ns *ifaddr;
E 12
E 10
I 5
	register struct ns_addr *dst;
E 5

	if (nam->m_len != sizeof (*sns))
		return (EINVAL);
	if (sns->sns_family != AF_NS)
		return (EAFNOSUPPORT);
	if (sns->sns_port==0 || ns_nullhost(sns->sns_addr))
		return (EADDRNOTAVAIL);
D 10
	if (ns_nullhost(nsp->nsp_laddr) &&
D 5
	    ((*(long *)&nsp->nsp_lastnet)!=ns_netof(sns->sns_addr))) {
		ia = (struct ns_ifaddr *)ifa_ifwithnet((struct sockaddr *)sns);
		if (ia == 0) {
			register struct route *ro;
			struct ifnet *ifp;
E 5
I 5
	    (!ns_neteq(nsp->nsp_lastdst, sns->sns_addr))) {
E 10
I 10
	if (ns_nullhost(nsp->nsp_laddr)) {
E 10
		register struct route *ro;
		struct ifnet *ifp;
I 10
		/* 
		 * If route is known or can be allocated now,
		 * our src addr is taken from the i/f, else punt.
		 */
E 10
		ro = &nsp->nsp_route;
		dst = &satons_addr(ro->ro_dst);
E 5

I 5
D 10
		ia = ns_iaonnetof(&sns->sns_addr);
D 7
		if (ia == 0) {
E 7
I 7
		if (ia == 0 ||
			(ia->ia_ifp->if_flags & IFF_UP) == 0) {
E 7
E 5
			/* 
			 * If route is known or can be allocated now,
			 * our src addr is taken from the i/f, else punt.
			 */
D 5
			ro = &nsp->nsp_route;
#define	satosns(sa)	((struct sockaddr_ns *)(sa))
E 5
			if (ro->ro_rt &&
D 5
				!ns_hosteq(satosns(&ro->ro_dst)->sns_addr,
					sns->sns_addr)) {
E 5
I 5
				!ns_hosteq(*dst, sns->sns_addr)) {
E 10
I 10
		ia = (struct ns_ifaddr *)0;
		if (ro->ro_rt) {
		    if ((!ns_neteq(nsp->nsp_lastdst, sns->sns_addr)) ||
			((ifp = ro->ro_rt->rt_ifp) &&
			 (ifp->if_flags & IFF_POINTOPOINT) &&
			 (!ns_hosteq(nsp->nsp_lastdst, sns->sns_addr))) ||
			(nsp->nsp_socket->so_options & SO_DONTROUTE)) {
E 10
E 5
				RTFREE(ro->ro_rt);
				ro->ro_rt = (struct rtentry *)0;
			}
D 10
			if ((ro->ro_rt == (struct rtentry *)0) ||
			    (ifp = ro->ro_rt->rt_ifp) == (struct ifnet *)0) {
				/* No route yet, so try to acquire one */
				ro->ro_dst.sa_family = AF_NS;
D 3
				((struct sockaddr_ns *) &ro->ro_dst)->sns_addr =
E 3
I 3
D 5
				satosns(&ro->ro_dst)->sns_addr =
E 3
					sns->sns_addr;
E 5
I 5
				*dst = sns->sns_addr;
				dst->x_port = 0;
E 5
				rtalloc(ro);
				if (ro->ro_rt == 0)
D 3
					ia = (struct ns_ifaddr *) 0;
E 3
I 3
					ifp = (struct ifnet *)0;
E 3
				else
D 3
				    for (ia = ns_ifaddr; ia; ia = ia->ia_next)
E 3
I 3
					ifp = ro->ro_rt->rt_ifp;
			}
			if (ifp) {
				for (ia = ns_ifaddr; ia; ia = ia->ia_next)
E 3
					if (ia->ia_ifp == ifp)
					    break;
			}
E 10
I 10
		}
		if ((nsp->nsp_socket->so_options & SO_DONTROUTE) == 0 && /*XXX*/
		    (ro->ro_rt == (struct rtentry *)0 ||
		     ro->ro_rt->rt_ifp == (struct ifnet *)0)) {
			    /* No route yet, so try to acquire one */
			    ro->ro_dst.sa_family = AF_NS;
			    *dst = sns->sns_addr;
			    dst->x_port = 0;
			    rtalloc(ro);
		}
		/*
		 * If we found a route, use the address
		 * corresponding to the outgoing interface
		 */
		if (ro->ro_rt && (ifp = ro->ro_rt->rt_ifp))
			for (ia = ns_ifaddr; ia; ia = ia->ia_next)
				if (ia->ia_ifp == ifp)
					break;
		if (ia == 0) {
			u_short fport = sns->sns_addr.x_port;
			sns->sns_addr.x_port = 0;
			ia = (struct ns_ifaddr *)
				ifa_ifwithdstaddr((struct sockaddr *)sns);
			sns->sns_addr.x_port = fport;
E 10
			if (ia == 0)
I 10
				ia = ns_iaonnetof(&sns->sns_addr);
			if (ia == 0)
E 10
				ia = ns_ifaddr;
			if (ia == 0)
				return (EADDRNOTAVAIL);
I 5
D 10
		} else if (ro->ro_rt) {
			if (ns_neteq(*dst, sns->sns_addr)) {
				/*
				 * This assume that we have no GH
				 * type routes.
				 */
				if (ro->ro_rt->rt_flags & RTF_HOST) {
					if (!ns_hosteq(*dst, sns->sns_addr))
						goto re_route;

				}
				if ((ro->ro_rt->rt_flags & RTF_GATEWAY) == 0) {
					dst->x_host = sns->sns_addr.x_host;
				}
				/* 
				 * Otherwise, we go through the same gateway
				 * and dst is already set up.
				 */
			} else {
			re_route:
				RTFREE(ro->ro_rt);
				ro->ro_rt = (struct rtentry *)0;
			}
E 10
E 5
		}
D 3
		ifaddr = (struct sockaddr_ns *)&ia->ia_addr;
E 3
I 3
D 5
		ifaddr = satosns(&ia->ia_addr);
E 3
		nsp->nsp_laddr.x_net = ifaddr->sns_addr.x_net;
		nsp->nsp_lastnet = sns->sns_addr.x_net;
E 5
I 5
		nsp->nsp_laddr.x_net = satons_addr(ia->ia_addr).x_net;
		nsp->nsp_lastdst = sns->sns_addr;
E 5
	}
	if (ns_pcblookup(&sns->sns_addr, nsp->nsp_lport, 0))
		return (EADDRINUSE);
	if (ns_nullhost(nsp->nsp_laddr)) {
		if (nsp->nsp_lport == 0)
D 4
			ns_pcbbind(nsp, (struct mbuf *)0);
E 4
I 4
			(void) ns_pcbbind(nsp, (struct mbuf *)0);
E 4
		nsp->nsp_laddr.x_host = ns_thishost;
	}
	nsp->nsp_faddr = sns->sns_addr;
	/* Includes nsp->nsp_fport = sns->sns_port; */
	return (0);
}

ns_pcbdisconnect(nsp)
	struct nspcb *nsp;
{

	nsp->nsp_faddr = zerons_addr;
	if (nsp->nsp_socket->so_state & SS_NOFDREF)
		ns_pcbdetach(nsp);
}

ns_pcbdetach(nsp)
	struct nspcb *nsp;
{
	struct socket *so = nsp->nsp_socket;

	so->so_pcb = 0;
	sofree(so);
	if (nsp->nsp_route.ro_rt)
		rtfree(nsp->nsp_route.ro_rt);
	remque(nsp);
	(void) m_free(dtom(nsp));
}

ns_setsockaddr(nsp, nam)
	register struct nspcb *nsp;
	struct mbuf *nam;
{
	register struct sockaddr_ns *sns = mtod(nam, struct sockaddr_ns *);
	
	nam->m_len = sizeof (*sns);
	sns = mtod(nam, struct sockaddr_ns *);
	bzero((caddr_t)sns, sizeof (*sns));
	sns->sns_family = AF_NS;
	sns->sns_addr = nsp->nsp_laddr;
}

ns_setpeeraddr(nsp, nam)
	register struct nspcb *nsp;
	struct mbuf *nam;
{
	register struct sockaddr_ns *sns = mtod(nam, struct sockaddr_ns *);
	
	nam->m_len = sizeof (*sns);
	sns = mtod(nam, struct sockaddr_ns *);
	bzero((caddr_t)sns, sizeof (*sns));
	sns->sns_family = AF_NS;
	sns->sns_addr  = nsp->nsp_faddr;
}

/*
 * Pass some notification to all connections of a protocol
 * associated with address dst.  Call the
 * protocol specific routine to handle each connection.
 * Also pass an extra paramter via the nspcb. (which may in fact
 * be a parameter list!)
 */
ns_pcbnotify(dst, errno, notify, param)
	register struct ns_addr *dst;
	long param;
	int errno, (*notify)();
{
	register struct nspcb *nsp, *oinp;
	int s = splimp();

	for (nsp = (&nspcb)->nsp_next; nsp != (&nspcb);) {
		if (!ns_hosteq(*dst,nsp->nsp_faddr)) {
	next:
			nsp = nsp->nsp_next;
			continue;
		}
		if (nsp->nsp_socket == 0)
			goto next;
		if (errno) 
			nsp->nsp_socket->so_error = errno;
		oinp = nsp;
		nsp = nsp->nsp_next;
		oinp->nsp_notify_param = param;
		(*notify)(oinp);
	}
	splx(s);
}

I 8
#ifdef notdef
E 8
/*
 * After a routing change, flush old routing
 * and allocate a (hopefully) better one.
 */
ns_rtchange(nsp)
	struct nspcb *nsp;
{
	if (nsp->nsp_route.ro_rt) {
		rtfree(nsp->nsp_route.ro_rt);
		nsp->nsp_route.ro_rt = 0;
		/*
		 * A new route can be allocated the next time
		 * output is attempted.
		 */
	}
	/* SHOULD NOTIFY HIGHER-LEVEL PROTOCOLS */
}
I 8
#endif
E 8

struct nspcb *
ns_pcblookup(faddr, lport, wildp)
	struct ns_addr *faddr;
	u_short lport;
{
	register struct nspcb *nsp, *match = 0;
	int matchwild = 3, wildcard;
	u_short fport;

	fport = faddr->x_port;
	for (nsp = (&nspcb)->nsp_next; nsp != (&nspcb); nsp = nsp->nsp_next) {
		if (nsp->nsp_lport != lport)
			continue;
		wildcard = 0;
		if (ns_nullhost(nsp->nsp_faddr)) {
			if (!ns_nullhost(*faddr))
				wildcard++;
		} else {
			if (ns_nullhost(*faddr))
				wildcard++;
			else {
				if (!ns_hosteq(nsp->nsp_faddr, *faddr))
					continue;
				if( nsp->nsp_fport != fport) {
					if(nsp->nsp_fport != 0)
						continue;
					else
						wildcard++;
				}
			}
		}
		if (wildcard && wildp==0)
			continue;
		if (wildcard < matchwild) {
			match = nsp;
			matchwild = wildcard;
			if (wildcard == 0)
				break;
		}
	}
	return (match);
}
E 1
