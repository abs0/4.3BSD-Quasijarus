h05259
s 00010/00005/00149
d D 7.4 88/06/27 18:59:33 bostic 34 33
c install approved copyright notice
e
s 00008/00002/00146
d D 7.3 87/12/30 11:57:29 bostic 33 32
c add Berkeley header
e
s 00002/00004/00146
d D 7.2 86/10/28 22:31:18 karels 32 31
c merge in tahoe
e
s 00000/00000/00150
d D 7.1 86/06/04 23:53:04 mckusick 31 30
c 4.3BSD release version
e
s 00002/00002/00148
d D 6.10 86/06/04 23:48:45 karels 30 29
c use the right include
e
s 00001/00000/00149
d D 6.9 86/02/06 14:18:03 karels 29 28
c add LOOPBACK flag, interface metric
e
s 00000/00003/00149
d D 6.8 85/12/19 16:12:54 karels 28 27
c rm bbnnet; rm PUP
e
s 00031/00007/00121
d D 6.7 85/09/16 21:07:12 karels 27 26
c move to net directory; prepend ifp to packet for protocols;
c INET || BBNNET
e
s 00007/00001/00121
d D 6.6 85/06/08 12:37:07 mckusick 26 25
c Add copyright
e
s 00000/00002/00122
d D 6.5 85/05/30 09:02:32 karels 25 24
c delete extraneous definitions
e
s 00018/00000/00106
d D 6.4 85/04/27 11:55:12 sklower 24 23
c add NS protocol stuff
e
s 00006/00018/00100
d D 6.3 85/03/18 15:27:45 karels 23 22
c move protocol addresses and address initialization to protocol layer
e
s 00010/00010/00108
d D 6.2 84/08/29 15:35:47 bloom 22 21
c Include file changes.  No more ../h
e
s 00000/00000/00118
d D 6.1 83/07/29 07:11:05 sam 21 20
c 4.2 distribution
e
s 00036/00003/00082
d D 4.19 83/06/13 00:27:15 sam 20 19
c ioctls
e
s 00003/00001/00082
d D 4.18 83/05/27 13:45:04 sam 19 18
c local host can't be zero, that's a broadcast
e
s 00003/00001/00080
d D 4.17 83/05/15 17:20:24 sam 18 17
c one more time, this time mtpr.h is vax specific
e
s 00008/00005/00073
d D 4.16 83/02/11 08:09:59 sam 17 15
c remove /usr/include dependencies
e
s 00008/00005/00073
d R 4.16 83/02/10 22:10:55 sam 16 15
c remove /usr/include dependencies
e
s 00001/00001/00077
d D 4.15 82/10/13 22:43:59 root 15 14
c move mtpr.h to vax directory
e
s 00005/00004/00073
d D 4.14 82/10/09 05:44:39 wnj 14 13
c localize header files
e
s 00000/00002/00077
d D 4.13 82/06/20 00:53:11 sam 13 12
c purge COUNT stuff now that we can use gprof
e
s 00001/00001/00078
d D 4.12 82/06/12 23:18:54 wnj 12 11
c now the routing code might wokr
e
s 00001/00000/00078
d D 4.11 82/04/16 14:49:45 sam 11 10
c missing include
e
s 00003/00003/00075
d D 4.10 82/04/13 20:41:06 feldman 10 9
c fixed error returns
e
s 00004/00000/00074
d D 4.9 82/03/30 11:32:00 sam 9 8
c with routing, but not forwarding
e
s 00013/00009/00061
d D 4.8 82/03/28 14:21:59 sam 8 7
c convert interfaces to sockaddr's and add hooks for routing
e
s 00001/00001/00069
d D 4.7 82/03/19 01:48:57 wnj 7 6
c fix to use only one soft intr for net thereby fixing bug in raw sockets
e
s 00010/00002/00060
d D 4.6 82/03/15 04:43:49 wnj 6 5
c interfac queueing, restrictions on packets, tcp keep alives done 
c properly, bug fix to raw
e
s 00001/00001/00061
d D 4.5 81/12/22 23:11:26 root 5 4
c LONET->127
e
s 00001/00001/00061
d D 4.4 81/12/07 22:02:03 wnj 4 3
c MTU allow for headers
e
s 00004/00001/00058
d D 4.3 81/12/03 17:29:18 wnj 3 2
c cleanup
e
s 00001/00001/00058
d D 4.2 81/12/02 16:58:23 wnj 2 1
c yet more lint
e
s 00059/00000/00000
d D 4.1 81/11/29 22:18:03 wnj 1 0
c date and time created 81/11/29 22:18:03 by wnj
e
u
U
t
T
I 1
D 26
/*	%M%	%I%	%E%	*/
E 26
I 26
/*
D 30
 * Copyright (c) 1982 Regents of the University of California.
E 30
I 30
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 30
D 33
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 33
I 33
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 34
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 34
I 34
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
E 34
E 33
 *
 *	%W% (Berkeley) %G%
 */
E 26

/*
 * Loopback interface driver for protocol testing and timing.
 */

D 22
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/mbuf.h"
#include "../h/socket.h"
D 14
#include "../net/in.h"
#include "../net/in_systm.h"
E 14
I 14
D 17
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
E 17
I 17
#include "../h/errno.h"
I 20
#include "../h/ioctl.h"
E 22
I 22
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "socket.h"
#include "errno.h"
#include "ioctl.h"
E 22
E 20

I 27
D 28
#ifdef	BBNNET
#define INET
#endif
E 28
E 27
E 17
E 14
#include "../net/if.h"
D 14
#include "../net/ip.h"
#include "../net/ip_var.h"
E 14
I 14
#include "../net/netisr.h"
I 17
#include "../net/route.h"

I 32
#include "../machine/mtpr.h"

E 32
D 22
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
E 17
#include "../netinet/ip.h"
#include "../netinet/ip_var.h"
E 22
I 22
D 27
#include "in.h"
#include "in_systm.h"
#include "ip.h"
#include "ip_var.h"
E 27
I 27
#ifdef	INET
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
I 30
#include "../netinet/in_var.h"
E 30
#include "../netinet/ip.h"
D 30
#include "../netinet/ip_var.h"
E 30
D 32
#endif
E 27
E 22
E 14
D 15
#include "../h/mtpr.h"
E 15
I 15
D 17
#include "../vax/mtpr.h"
E 15
I 9
#include "../net/route.h"
I 11
#include <errno.h>
E 17
I 17

D 18
#include "../machine/mtpr.h"
E 18
I 18
#ifdef vax
#include "../vax/mtpr.h"
E 32
#endif
E 18
E 17
E 11
E 9

I 24
#ifdef NS
#include "../netns/ns.h"
#include "../netns/ns_if.h"
#endif

E 24
D 5
#define	LONET	254
E 5
I 5
D 25
#define	LONET	127
I 19
#define	LOHOST	1			/* can't be 0, that's broadcast */
E 25
E 19
E 5
D 4
#define	LOMTU	1024
E 4
I 4
#define	LOMTU	(1024+512)
E 4

struct	ifnet loif;
D 20
int	looutput();
E 20
I 20
int	looutput(), loioctl();
E 20

loattach()
{
	register struct ifnet *ifp = &loif;
I 8
D 27
	register struct sockaddr_in *sin;
E 27
E 8

I 9
D 13
COUNT(LOATTACH);
E 13
E 9
I 3
	ifp->if_name = "lo";
E 3
	ifp->if_mtu = LOMTU;
I 29
	ifp->if_flags = IFF_LOOPBACK;
E 29
D 23
	ifp->if_net = LONET;
I 19
	ifp->if_host[0] = LOHOST;
E 19
I 3
D 8
	ifp->if_addr = if_makeaddr(ifp->if_net, 0);
E 8
I 8
	sin = (struct sockaddr_in *)&ifp->if_addr;
	sin->sin_family = AF_INET;
D 19
	sin->sin_addr = if_makeaddr(ifp->if_net, 0);
E 19
I 19
D 20
	sin->sin_addr = if_makeaddr(ifp->if_net, LOHOST);
E 19
	ifp->if_flags = IFF_UP;
E 20
I 20
	sin->sin_addr = if_makeaddr(LONET, LOHOST);
	ifp->if_flags = IFF_UP | IFF_RUNNING;
E 23
	ifp->if_ioctl = loioctl;
E 20
E 8
E 3
	ifp->if_output = looutput;
D 3
	ifp->if_next = ifnet;
E 3
D 2
	ifnet = ifp;
E 2
I 2
	if_attach(ifp);
I 9
D 12
	if_rtinit(ifp, RTF_DIRECT|RTF_UP);
E 12
I 12
D 23
	if_rtinit(ifp, RTF_UP);
E 23
E 12
E 9
E 2
}

D 8
looutput(ifp, m0, pf)
E 8
I 8
looutput(ifp, m0, dst)
E 8
	struct ifnet *ifp;
D 27
	struct mbuf *m0;
E 27
I 27
	register struct mbuf *m0;
E 27
D 8
	int pf;
E 8
I 8
	struct sockaddr *dst;
E 8
{
D 27
	int s = splimp();
E 27
I 27
	int s;
E 27
I 6
	register struct ifqueue *ifq;
I 27
	struct mbuf *m;
E 27
E 6

I 27
	/*
	 * Place interface pointer before the data
	 * for the receiving protocol.
	 */
	if (m0->m_off <= MMAXOFF &&
	    m0->m_off >= MMINOFF + sizeof(struct ifnet *)) {
		m0->m_off -= sizeof(struct ifnet *);
		m0->m_len += sizeof(struct ifnet *);
	} else {
		MGET(m, M_DONTWAIT, MT_HEADER);
		if (m == (struct mbuf *)0)
			return (ENOBUFS);
		m->m_off = MMINOFF;
		m->m_len = sizeof(struct ifnet *);
		m->m_next = m0;
		m0 = m;
	}
	*(mtod(m0, struct ifnet **)) = ifp;
	s = splimp();
E 27
I 9
D 13
COUNT(LOOUTPUT);
E 13
E 9
I 3
	ifp->if_opackets++;
E 3
D 8
	switch (pf) {
E 8
I 8
	switch (dst->sa_family) {
E 8

#ifdef INET
D 8
	case PF_INET:
E 8
I 8
	case AF_INET:
E 8
D 6
		IF_ENQUEUE(&ipintrq, m0);
E 6
I 6
		ifq = &ipintrq;
		if (IF_QFULL(ifq)) {
			IF_DROP(ifq);
D 8
			(void) m_freem(m0);
E 8
I 8
			m_freem(m0);
E 8
			splx(s);
D 10
			return (0);
E 10
I 10
			return (ENOBUFS);
E 10
		}
		IF_ENQUEUE(ifq, m0);
E 6
D 7
		setipintr();
E 7
I 7
		schednetisr(NETISR_IP);
I 24
		break;
#endif
#ifdef NS
	case AF_NS:
		ifq = &nsintrq;
		if (IF_QFULL(ifq)) {
			IF_DROP(ifq);
			m_freem(m0);
			splx(s);
			return (ENOBUFS);
		}
		IF_ENQUEUE(ifq, m0);
		schednetisr(NETISR_NS);
E 24
E 7
		break;
#endif
D 8

E 8
	default:
		splx(s);
D 8
		printf("lo%d: can't encapsulate pf%d\n", ifp->if_unit, pf);
D 6
		m_freem(m0);
E 6
I 6
		(void) m_freem(m0);
E 8
I 8
		printf("lo%d: can't handle af%d\n", ifp->if_unit,
			dst->sa_family);
		m_freem(m0);
E 8
E 6
D 10
		return (0);
E 10
I 10
		return (EAFNOSUPPORT);
E 10
	}
I 3
	ifp->if_ipackets++;
E 3
	splx(s);
D 10
	return (1);
E 10
I 10
	return (0);
I 20
}

/*
 * Process an ioctl request.
 */
I 23
/* ARGSUSED */
E 23
loioctl(ifp, cmd, data)
	register struct ifnet *ifp;
	int cmd;
	caddr_t data;
{
D 23
	struct ifreq *ifr = (struct ifreq *)data;
	struct sockaddr_in *sin;
	int s = splimp(), error = 0;
E 23
I 23
	int error = 0;
E 23

	switch (cmd) {

	case SIOCSIFADDR:
D 23
		if (ifp->if_flags & IFF_RUNNING)
			if_rtinit(ifp, -1);	/* delete previous route */
		ifp->if_addr = ifr->ifr_addr;
		sin = (struct sockaddr_in *)&ifp->if_addr;
		ifp->if_net = in_netof(sin->sin_addr);
		ifp->if_host[0] = in_lnaof(sin->sin_addr);
		if_rtinit(ifp, RTF_UP);
E 23
I 23
		ifp->if_flags |= IFF_UP;
		/*
		 * Everything else is done at a higher level.
		 */
E 23
		break;

	default:
		error = EINVAL;
	}
D 23
	splx(s);
E 23
	return (error);
E 20
E 10
}
E 1
