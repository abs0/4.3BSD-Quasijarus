h46233
s 00011/00006/00415
d D 7.3 88/06/29 17:13:27 bostic 16 15
c install approved copyright notice
e
s 00010/00004/00411
d D 7.2 88/01/20 15:15:20 sklower 15 14
c Change licensing/use notice.
e
s 00001/00001/00414
d D 7.1 86/06/05 00:37:14 mckusick 14 13
c 4.3BSD release version
e
s 00000/00001/00415
d D 6.13 86/03/04 19:46:34 sklower 13 12
c Shut Lint Up.
e
s 00000/00012/00416
d D 6.12 85/12/19 16:17:13 karels 12 11
c rm bbnnet
e
s 00032/00014/00396
d D 6.11 85/11/09 15:57:54 sklower 11 10
c change the way pt to pt links are handle to be closer to inet
c to allow net(addr)!=net(dstaddr); also change interface to rtinit so that
c renaming pt to pt links will delete existing routes.
e
s 00005/00001/00405
d D 6.10 85/10/15 10:30:05 mckusick 10 9
c fix uninitialized pointer in nsip_rtchange. (check in by sklower).
e
s 00073/00003/00333
d D 6.9 85/10/01 14:54:54 sklower 9 8
c Make ns_ip psuedo interfaces re-usable, add ctlinput stuff to reap
c dead routes.
e
s 00010/00000/00326
d D 6.8 85/09/17 10:31:26 karels 8 7
c changed my mind, need ip_stripoptions again
e
s 00028/00019/00298
d D 6.7 85/09/06 17:16:28 karels 7 6
c base level changes for interface tracing
e
s 00012/00000/00305
d D 6.6 85/08/23 12:54:31 walsh 6 5
c avoid berk tcp dependencies
e
s 00008/00016/00297
d D 6.5 85/08/09 11:35:19 sklower 5 4
c 
e
s 00011/00004/00302
d D 6.4 85/07/26 13:59:53 sklower 4 3
c change IPPROTO_PUP to IPPROTO_IDP,  add another pullup if ridding ip options.
e
s 00002/00000/00304
d D 6.3 85/07/02 22:20:40 sklower 3 2
c preserve garbage byte on ip encapsulation.
e
s 00007/00001/00297
d D 6.2 85/06/08 12:50:51 mckusick 2 1
c Add copyright
e
s 00298/00000/00000
d D 6.1 85/05/30 19:10:57 sklower 1 0
c date and time created 85/05/30 19:10:57 by sklower
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
D 9
 * Copyright (c) 1982 Regents of the University of California.
E 9
I 9
D 14
 * Copyright (c) 1985 Regents of the University of California.
E 14
I 14
D 15
 * Copyright (c) 1985, 1986 Regents of the University of California.
E 14
E 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 15
I 15
 * Copyright (c) 1984, 1985, 1986, 1987 Regents of the University of California.
 * All rights reserved.
E 15
 *
D 15
 *	%W% (Berkeley) %G%
E 15
I 15
 * Redistribution and use in source and binary forms are permitted
D 16
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 16
I 16
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
E 16
 *
D 16
 *      %W% (Berkeley) %G%
E 16
I 16
 *	%W% (Berkeley) %G%
E 16
E 15
 */
E 2

/*
 * Software interface driver for encapsulating ns in ip.
 */

#ifdef NSIP
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "socket.h"
I 5
#include "socketvar.h"
E 5
#include "errno.h"
#include "ioctl.h"
I 9
#include "protosw.h"
E 9

#include "../net/if.h"
#include "../net/netisr.h"
#include "../net/route.h"

#include "../netinet/in.h"
#include "../netinet/in_systm.h"
#include "../netinet/in_var.h"
#include "../netinet/ip.h"
#include "../netinet/ip_var.h"

#ifdef vax
#include "../vax/mtpr.h"
#endif

#include "../netns/ns.h"
#include "../netns/ns_if.h"
#include "../netns/idp.h"

I 6
D 12
#ifdef BBNNET
#include "../bbnnet/in_pcb.h"
#include "../bbnnet/nopcb.h"
#endif

E 12
E 6
struct ifnet_en {
	struct ifnet ifen_ifnet;
	struct route ifen_route;
	struct in_addr ifen_src;
	struct in_addr ifen_dst;
};

int	nsipoutput(), nsipioctl();
#define LOMTU	(1024+512);

struct ifnet nsipif;
D 13
union ns_net nsip_net;
E 13
struct mbuf *nsip_list;		/* list of all hosts and gateways or
					broadcast addrs */

struct mbuf *
nsipattach()
{
	register struct mbuf *m = m_getclr(M_DONTWAIT, MT_PCB);
	register struct ifnet *ifp;
D 5
	register struct sockaddr_in *sin;
E 5

D 11
	if (m==0) return (0);
E 11
I 11
	if (m == NULL) return (NULL);
E 11
	m->m_off = MMINOFF;
	m->m_len = sizeof(struct ifnet_en);
	m->m_next = nsip_list;
	nsip_list = m;
	ifp = mtod(m, struct ifnet *);

	ifp->if_name = "nsip";
	ifp->if_mtu = LOMTU;
	ifp->if_ioctl = nsipioctl;
	ifp->if_output = nsipoutput;
	ifp->if_flags = IFF_POINTOPOINT;
	ifp->if_unit = nsipif.if_unit++;
	if_attach(ifp);
D 11
	return(dtom(ifp));
E 11
I 11
	return (dtom(ifp));
E 11
}


/*
 * Process an ioctl request.
 */
/* ARGSUSED */
nsipioctl(ifp, cmd, data)
	register struct ifnet *ifp;
	int cmd;
	caddr_t data;
{
	int error = 0;
I 9
	struct ifreq *ifr;
E 9

	switch (cmd) {

	case SIOCSIFADDR:
		ifp->if_flags |= IFF_UP;
I 11
		/* fall into: */

	case SIOCSIFDSTADDR:
E 11
		/*
		 * Everything else is done at a higher level.
		 */
		break;

I 9
	case SIOCSIFFLAGS:
		ifr = (struct ifreq *)data;
		if ((ifr->ifr_flags & IFF_UP) == 0)
			error = nsip_free(ifp);


E 9
	default:
		error = EINVAL;
	}
	return (error);
}

struct mbuf *nsip_badlen;
struct mbuf *nsip_lastin;
int nsip_hold_input;

D 7
idpip_input(m0)
	struct mbuf *m0;
E 7
I 7
idpip_input(m, ifp)
	register struct mbuf *m;
	struct ifnet *ifp;
E 7
{
	register struct ip *ip;
	register struct idp *idp;
D 7
	register struct mbuf *m;
E 7
	register struct ifqueue *ifq = &nsintrq;
	int len, s;

D 11
	if(nsip_hold_input) {
		if(nsip_lastin) {
E 11
I 11
	if (nsip_hold_input) {
		if (nsip_lastin) {
E 11
D 5
			m_free(nsip_lastin);
E 5
I 5
			m_freem(nsip_lastin);
E 5
		}
D 5
		nsip_lastin = m_copy(m0, 0, M_COPYALL);
E 5
I 5
D 7
		nsip_lastin = m_copy(m0, 0, (int)M_COPYALL);
E 7
I 7
		nsip_lastin = m_copy(m, 0, (int)M_COPYALL);
E 7
E 5
	}
	/*
	 * Get IP and IDP header together in first mbuf.
	 */
	nsipif.if_ipackets++;
D 7
	m = m0;
E 7
	s = sizeof (struct ip) + sizeof (struct idp);
	if ((m->m_off > MMAXOFF || m->m_len < s) &&
D 11
	    (m = m_pullup(m, s))==0) {
E 11
I 11
	    (m = m_pullup(m, s)) == 0) {
E 11
		nsipif.if_ierrors++;
		return;
	}
	ip = mtod(m, struct ip *);
I 10
D 12
#ifndef	BBNNET
E 12
E 10
I 8
	if (ip->ip_hl > (sizeof (struct ip) >> 2)) {
		ip_stripoptions(ip, (struct mbuf *)0);
		if (m->m_len < s) {
D 11
			if ((m = m_pullup(m, s))==0) {
E 11
I 11
			if ((m = m_pullup(m, s)) == 0) {
E 11
				nsipif.if_ierrors++;
				return;
			}
			ip = mtod(m, struct ip *);
		}
	}
I 10
D 12
#endif
E 12
E 10
E 8
I 6
D 7
#ifndef BBNNET
E 6
D 4
	if (ip->ip_hl > (sizeof (struct ip) >> 2))
E 4
I 4
	if (ip->ip_hl > (sizeof (struct ip) >> 2)) {
E 4
		ip_stripoptions(ip, (struct mbuf *)0);
I 4
		if (m->m_len < s) {
			if ((m = m_pullup(m, s))==0) {
				nsipif.if_ierrors++;
				return;
			}
			ip = mtod(m, struct ip *);
		}
	}
I 6
#endif
E 7
E 6
E 4

	/*
	 * Make mbuf data length reflect IDP length.
	 * If not enough data to reflect IDP length, drop.
	 */
	m->m_off += sizeof (struct ip);
	m->m_len -= sizeof (struct ip);
	idp = mtod(m, struct idp *);
	len = ntohs(idp->idp_len);
I 3
	if (len & 1) len++;		/* Preserve Garbage Byte */
E 3
	if (ip->ip_len != len) {
		if (len > ip->ip_len) {
			nsipif.if_ierrors++;
D 11
			if(nsip_badlen) m_freem(nsip_badlen);
E 11
I 11
			if (nsip_badlen) m_freem(nsip_badlen);
E 11
			nsip_badlen = m;
			return;
		}
D 4
		m_adj(m, len - ip->ip_len);
		/* ip->ip_len = len; */
E 4
I 4
		/* Any extra will be trimmed off by the NS routines */
E 4
	}
I 7

E 7
	/*
I 7
	 * Place interface pointer before the data
	 * for the receiving protocol.
	 */
	if (m->m_off >= MMINOFF + sizeof(struct ifnet *)) {
		m->m_off -= sizeof(struct ifnet *);
		m->m_len += sizeof(struct ifnet *);
	} else {
		struct mbuf *n;

		n = m_get(M_DONTWAIT, MT_HEADER);
		if (n == (struct mbuf *)0)
			goto bad;
		n->m_off = MMINOFF;
		n->m_len = sizeof(struct ifnet *);
		n->m_next = m;
		m = n;
	}
	*(mtod(m, struct ifnet **)) = ifp;

	/*
E 7
	 * Deliver to NS
	 */
	s = splimp();
	if (IF_QFULL(ifq)) {
		IF_DROP(ifq);
D 7
		m_freem(m0);
E 7
I 7
bad:
		m_freem(m);
E 7
		splx(s);
D 5
		return (ENOBUFS);
E 5
I 5
		return;
E 5
	}
D 7
	IF_ENQUEUE(ifq, m0);
E 7
I 7
	IF_ENQUEUE(ifq, m);
E 7
	schednetisr(NETISR_NS);
	splx(s);
D 5
	return (0);
bad:
	m_freem(m);
	return (0);
E 5
I 5
	return;
E 5
}

I 5
/* ARGSUSED */
E 5
nsipoutput(ifn, m0, dst)
	struct ifnet_en *ifn;
	struct mbuf *m0;
	struct sockaddr *dst;
{

	register struct mbuf *m = dtom(ifn);
	register struct ip *ip;
	register struct route *ro = &(ifn->ifen_route);
	register int len = 0;
D 5
	struct in_addr in_src, in_dst;
E 5
	register struct idp *idp = mtod(m0, struct idp *);
	int error;

	if (m->m_len != sizeof(struct ifnet_en)) {
		printf("nsipoutput: bad dst ifp %x\n", ifn);
		goto bad;
	}
	ifn->ifen_ifnet.if_opackets++;
	nsipif.if_opackets++;


	/*
	 * Calculate data length and make space
	 * for IP header.
	 */
	len =  ntohs(idp->idp_len);
I 3
	if (len & 1) len++;		/* Preserve Garbage Byte */
E 3
	m = m0;
D 11
	if(m->m_off < MMINOFF + sizeof (struct ip)) {
E 11
I 11
	if (m->m_off < MMINOFF + sizeof (struct ip)) {
E 11
		m = m_get(M_DONTWAIT, MT_HEADER);
		if (m == 0) {
			m_freem(m0);
			return (ENOBUFS);
		}
		m->m_off = MMAXOFF - sizeof (struct ip);
		m->m_len = sizeof (struct ip);
		m->m_next = m0;
	} else {
		m->m_off -= sizeof (struct ip);
		m->m_len += sizeof (struct ip);
	}
	/*
	 * Fill in IP header.
	 */
	ip = mtod(m, struct ip *);
	*(long *)ip = 0;
D 4
	ip->ip_p = IPPROTO_PUP;
E 4
I 4
	ip->ip_p = IPPROTO_IDP;
E 4
	ip->ip_src = ifn->ifen_src;
	ip->ip_dst = ifn->ifen_dst;
I 6
D 12
#ifdef BBNNET
	ip->ip_tos = 0;
	NOPCB_IPSEND(m, len, 0, error);
#else
E 12
E 6
	ip->ip_len = (u_short)len + sizeof (struct ip);
	ip->ip_ttl = MAXTTL;

	/*
	 * Output final datagram.
	 */
	error =  (ip_output(m, (struct mbuf *)0, ro, SO_BROADCAST));
I 6
D 12
#endif
E 12
E 6
	if (error) {
		ifn->ifen_ifnet.if_oerrors++;
		ifn->ifen_ifnet.if_ierrors = error;
	}
	return (error);
bad:
	m_freem(m0);
D 11
	return(ENETUNREACH);
E 11
I 11
	return (ENETUNREACH);
E 11
}

struct ifreq ifr = {"nsip0"};

nsip_route(m)
	register struct mbuf *m;
{
	register struct nsip_req *rq = mtod(m, struct nsip_req *);
	struct sockaddr_ns *ns_dst = (struct sockaddr_ns *)&rq->rq_ns;
	struct sockaddr_in *ip_dst = (struct sockaddr_in *)&rq->rq_ip;
D 5
	int flags = rq->rq_flags;
	struct ifnet *ifp;
E 5
	struct route ro;
	struct ifnet_en *ifn;
D 5
	int error;
	struct sockaddr_in *dst;
E 5
	struct sockaddr_in *src;
I 11

E 11
	/*
D 11
	 * First, determine if we can get to the destination
E 11
I 11
	 * First, make sure we already have an ns address:
E 11
	 */
I 11
	if (ns_hosteqnh(ns_thishost, ns_zerohost))
		return (EADDRNOTAVAIL);
	/*
	 * Now, determine if we can get to the destination
	 */
E 11
	bzero((caddr_t)&ro, sizeof (ro));
	ro.ro_dst = *(struct sockaddr *)ip_dst;
D 5
	dst = (struct sockaddr_in *)& ro.ro_dst;
E 5
	rtalloc(&ro);
D 5
	if (ro.ro_rt == 0 || (ifp = ro.ro_rt->rt_ifp) == 0) {
E 5
I 5
	if (ro.ro_rt == 0 || ro.ro_rt->rt_ifp == 0) {
E 5
		return (ENETUNREACH);
	}
I 11

E 11
	/*
	 * And see how he's going to get back to us:
I 11
	 * i.e., what return ip address do we use?
E 11
	 */
	{
		register struct in_ifaddr *ia;
		struct ifnet *ifp = ro.ro_rt->rt_ifp;

		for (ia = in_ifaddr; ia; ia = ia->ia_next)
			if (ia->ia_ifp == ifp)
				break;
		if (ia == 0)
			ia = in_ifaddr;
		if (ia == 0) {
I 11
			RTFREE(ro.ro_rt);
E 11
			return (EADDRNOTAVAIL);
		}
		src = (struct sockaddr_in *)&ia->ia_addr;
	}
I 11

E 11
	/*
D 9
	 * Is there space?
E 9
I 9
	 * Is there a free (pseudo-)interface or space?
E 9
	 */
D 9
	m = nsipattach();
E 9
I 9
	for (m = nsip_list; m; m = m->m_next) {
		struct ifnet *ifp = mtod(m, struct ifnet *);
		if ((ifp->if_flags & IFF_UP) == 0)
			break;
	}
	if (m == (struct mbuf *) 0)
		m = nsipattach();
E 9
D 11
	if (m==NULL) {return (ENOBUFS);}
E 11
I 11
	if (m == NULL) {
		RTFREE(ro.ro_rt);
		return (ENOBUFS);
	}
E 11
	ifn = mtod(m, struct ifnet_en *);

D 11
	ro.ro_rt->rt_use++;
E 11
	ifn->ifen_route = ro;
	ifn->ifen_dst =  ip_dst->sin_addr;
	ifn->ifen_src = src->sin_addr;

	/*
	 * now configure this as a point to point link
	 */
	ifr.ifr_name[4] = '0' + nsipif.if_unit - 1;
	ifr.ifr_dstaddr = * (struct sockaddr *) ns_dst;
D 5
	return(ns_control((struct socket *)0, SIOCSIFADDR, (caddr_t)&ifr,
E 5
I 5
D 11
	return(ns_control((struct socket *)0, (int)SIOCSIFADDR, (caddr_t)&ifr,
E 11
I 11
	(void)ns_control((struct socket *)0, (int)SIOCSIFDSTADDR, (caddr_t)&ifr,
			(struct ifnet *)ifn);
	satons_addr(ifr.ifr_addr).x_host = ns_thishost;
	return (ns_control((struct socket *)0, (int)SIOCSIFADDR, (caddr_t)&ifr,
E 11
E 5
			(struct ifnet *)ifn));
I 9
}

nsip_free(ifp)
struct ifnet *ifp;
{
	register struct ifnet_en *ifn = (struct ifnet_en *)ifp;
	struct route *ro = & ifn->ifen_route;

	if (ro->ro_rt) {
		RTFREE(ro->ro_rt);
		ro->ro_rt = 0;
	}
	ifp->if_flags &= ~IFF_UP;
	return (0);
}

nsip_ctlinput(cmd, sa)
	int cmd;
	struct sockaddr *sa;
{
	extern u_char inetctlerrmap[];
	struct sockaddr_in *sin;
	int in_rtchange();

D 11
	if ((unsigned)cmd > PRC_NCMDS)
E 11
I 11
	if ((unsigned)cmd >= PRC_NCMDS)
E 11
		return;
	if (sa->sa_family != AF_INET && sa->sa_family != AF_IMPLINK)
		return;
	sin = (struct sockaddr_in *)sa;
	if (sin->sin_addr.s_addr == INADDR_ANY)
		return;

	switch (cmd) {

	case PRC_ROUTEDEAD:
	case PRC_REDIRECT_NET:
	case PRC_REDIRECT_HOST:
	case PRC_REDIRECT_TOSNET:
	case PRC_REDIRECT_TOSHOST:
		nsip_rtchange(&sin->sin_addr);
		break;
	}
}

nsip_rtchange(dst)
	register struct in_addr *dst;
{
	register struct mbuf *m;
	register struct ifnet_en *ifn;

D 10
	for (m = nsip_list; m; m = m->m_next)
E 10
I 10
	for (m = nsip_list; m; m = m->m_next) {
		ifn = mtod(m, struct ifnet_en *);
E 10
		if (ifn->ifen_dst.s_addr == dst->s_addr &&
			ifn->ifen_route.ro_rt) {
				RTFREE(ifn->ifen_route.ro_rt);
				ifn->ifen_route.ro_rt = 0;
		}
I 10
	}
E 10
E 9
}
#endif
E 1
