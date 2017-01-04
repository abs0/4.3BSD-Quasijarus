h10205
s 00011/00006/00546
d D 7.4 88/06/29 17:13:11 bostic 17 16
c install approved copyright notice
e
s 00002/00002/00550
d D 7.3 88/05/26 09:38:36 karels 16 15
c lint
e
s 00009/00003/00543
d D 7.2 88/01/20 15:15:04 sklower 15 14
c Change licensing/use notice.
e
s 00001/00001/00545
d D 7.1 86/06/05 00:35:43 mckusick 14 13
c 4.3BSD release version
e
s 00005/00003/00541
d D 6.12 86/02/03 17:31:55 sklower 13 12
c remove ns_netof (non-portable), add zero and broadcast ns nets to compare to.
e
s 00009/00002/00535
d D 6.11 85/10/30 10:16:04 sklower 12 10
c Kernel should return error on illegal socket option requests.
c (or pass them further down the layers at some future date?)
e
s 00008/00001/00536
d R 6.11 85/10/29 14:23:18 sklower 11 10
c Kernel should return error on illegal socket option requests.
c (or pass them further down the layers at some future date?)
e
s 00037/00008/00500
d D 6.10 85/09/26 15:18:02 sklower 10 9
c fix route caching (which had been causing packets to go out on the
c wrong interface).
e
s 00001/00001/00507
d D 6.9 85/09/11 13:07:27 sklower 9 8
c loop looking for interface address doesn't advance.
e
s 00015/00004/00493
d D 6.8 85/09/06 18:35:05 sklower 8 7
c Do Something with interface tracing & fix ctlinput routines.
e
s 00002/00002/00495
d D 6.7 85/08/09 11:34:29 sklower 7 6
c 
e
s 00009/00006/00488
d D 6.6 85/07/26 15:48:44 sklower 6 5
c new option to suppress error processing on DG sockets.
e
s 00043/00002/00451
d D 6.5 85/07/19 18:38:20 sklower 5 4
c 1. add routine to drop individual connections rather than using wholesale idpabort.
c 2. add sockopt to set and get sequence id's for PEX protocol.
e
s 00017/00013/00436
d D 6.4 85/06/16 12:34:07 sklower 4 3
c check to make sure m_get returns non-null in every instance.
e
s 00007/00001/00442
d D 6.3 85/06/08 12:48:51 mckusick 3 2
c Add copyright
e
s 00007/00008/00436
d D 6.2 85/05/31 14:23:18 sklower 2 1
c plug mbuf leak from torek@maryland; restrict raw sockets to suser.
e
s 00444/00000/00000
d D 6.1 85/05/30 19:10:47 sklower 1 0
c date and time created 85/05/30 19:10:47 by sklower
e
u
U
t
T
I 1
D 3
/*      %M%     %I%     %E%     */
E 3
I 3
/*
D 12
 * Copyright (c) 1982 Regents of the University of California.
E 12
I 12
D 13
 * Copyright (c) 1984,1985 Regents of the University of California.
E 13
I 13
D 14
 * Copyright (c) 1984, 1985 Regents of the University of California.
E 14
I 14
D 15
 * Copyright (c) 1984, 1985, 1986 Regents of the University of California.
E 14
E 13
E 12
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 15
I 15
 * Copyright (c) 1984, 1985, 1986, 1987 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 17
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 17
I 17
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
E 17
E 15
 *
D 4
 *	%W% (Berkeley) %G%
E 4
I 4
D 17
 *      %W% (Berkeley) %G%
E 17
I 17
 *	%W% (Berkeley) %G%
E 17
E 4
 */
E 3

#include "param.h"
#include "dir.h"
#include "user.h"
#include "mbuf.h"
#include "protosw.h"
#include "socket.h"
#include "socketvar.h"
#include "errno.h"
#include "stat.h"

#include "../net/if.h"
#include "../net/route.h"

#include "ns.h"
#include "ns_pcb.h"
I 8
#include "ns_if.h"
E 8
#include "idp.h"
#include "idp_var.h"
#include "ns_error.h"

/*
 * IDP protocol implementation.
 */

struct	sockaddr_ns idp_ns = { AF_NS };

I 5
/*
 *  This may also be called for raw listeners.
 */
E 5
D 2
int
idp_input_panic = 1;
E 2
D 8
idp_input(m, nsp)
E 8
I 8
idp_input(m, nsp, ifp)
E 8
	struct mbuf *m;
	register struct nspcb *nsp;
I 8
	struct ifnet *ifp;
E 8
{
	register struct idp *idp = mtod(m, struct idp *);
D 2
	if (idp_input_panic) {
		if ((nsp==0) || ((idp->idp_pt==5) && (!(nsp->nsp_flags&NSP_RAWIN))))
			panic("Impossible idp_input");
	}
E 2
I 2
D 5
	if (nsp==0)
		panic("Impossible idp_input");
E 5
E 2

I 5
D 8
	if (nsp==0) {
E 8
I 8
	if (nsp==0)
E 8
D 6
		nsp = ns_pcblookup(&idp->idp_sna,
					idp->idp_dna.x_port, NS_WILDCARD);
		if (nsp==0) {
			ns_error(m, NS_ERR_NOSOCK, 0);
			return;
		}
E 6
I 6
		panic("No nspcb");
E 6
D 8
	}

E 8
E 5
	/*
	 * Construct sockaddr format source address.
	 * Stuff source address and datagram in user buffer.
	 */
	idp_ns.sns_addr = idp->idp_sna;
I 8
D 10
	if (ns_netof(idp->idp_sna)==0) {
E 10
I 10
D 13
	if (ns_netof(idp->idp_sna)==0 && ifp) {
E 13
I 13
	if (ns_neteqnn(idp->idp_sna.x_net, ns_zeronet) && ifp) {
E 13
E 10
		register struct ifaddr *ia;

D 9
		for (ia = ifp->if_addrlist; ia; ia->ifa_next) {
E 9
I 9
		for (ia = ifp->if_addrlist; ia; ia = ia->ifa_next) {
E 9
			if (ia->ifa_addr.sa_family == AF_NS) {
				idp_ns.sns_addr.x_net =
					IA_SNS(ia)->sns_addr.x_net;
				break;
			}
		}
	}
E 8
	nsp->nsp_rpt = idp->idp_pt;
	if ( ! (nsp->nsp_flags & NSP_RAWIN) ) {
		m->m_len -= sizeof (struct idp);
		m->m_off += sizeof (struct idp);
	}
	if (sbappendaddr(&nsp->nsp_socket->so_rcv, (struct sockaddr *)&idp_ns,
	    m, (struct mbuf *)0) == 0)
		goto bad;
	sorwakeup(nsp->nsp_socket);
	return;
bad:
	m_freem(m);
}

idp_abort(nsp)
	struct nspcb *nsp;
{
	struct socket *so = nsp->nsp_socket;

	ns_pcbdisconnect(nsp);
	soisdisconnected(so);
}
I 5
/*
 * Drop connection, reporting
 * the specified error.
 */
struct nspcb *
idp_drop(nsp, errno)
	register struct nspcb *nsp;
	int errno;
{
	struct socket *so = nsp->nsp_socket;
E 5

I 5
	/*
	 * someday, in the xerox world
	 * we will generate error protocol packets
	 * announcing that the socket has gone away.
	 */
	/*if (TCPS_HAVERCVDSYN(tp->t_state)) {
		tp->t_state = TCPS_CLOSED;
		(void) tcp_output(tp);
	}*/
	so->so_error = errno;
	ns_pcbdisconnect(nsp);
	soisdisconnected(so);
}

I 10
int noIdpRoute;
E 10
E 5
idp_output(nsp, m0)
	struct nspcb *nsp;
	struct mbuf *m0;
{
	register struct mbuf *m;
	register struct idp *idp;
	register struct socket *so;
	register int len = 0;
	register struct route *ro;
	struct mbuf *mprev;
	extern int idpcksum;

	/*
	 * Calculate data length.
	 */
	for (m = m0; m; m = m->m_next) {
		mprev = m;
		len += m->m_len;
	}
	/*
	 * Make sure packet is actually of even length.
	 */
	
	if (len & 1) {
		m = mprev;
		if (m->m_len + m->m_off < MMAXOFF) {
			m->m_len++;
		} else {
			struct mbuf *m1 = m_get(M_DONTWAIT, MT_DATA);

D 2
			if (m1 == 0) return (ENOBUFS);
E 2
I 2
			if (m1 == 0) {
				m_freem(m0);
				return (ENOBUFS);
			}
E 2
			m1->m_len = 1;
			m1->m_off = MMAXOFF - 1;
			* mtod(m1, char *) = 0;
			m->m_next = m1;
		}
	}

	/*
	 * Fill in mbuf with extended IDP header
	 * and addresses and length put into network format.
	 */
	if (nsp->nsp_flags & NSP_RAWOUT) {
		m = m0;
		idp = mtod(m, struct idp *);
	} else {
		m = m_get(M_DONTWAIT, MT_HEADER);
		if (m == 0) {
			m_freem(m0);
			return (ENOBUFS);
		}
D 13
		m->m_off = MMAXOFF - sizeof (struct idp);
E 13
I 13
		m->m_off = MMAXOFF - sizeof (struct idp) - 2;
				/* adjust to start on longword bdry
				   for NSIP on gould */
E 13
		m->m_len = sizeof (struct idp);
		m->m_next = m0;
		idp = mtod(m, struct idp *);
		idp->idp_tc = 0;
		idp->idp_pt = nsp->nsp_dpt;
		idp->idp_sna = nsp->nsp_laddr;
		idp->idp_dna = nsp->nsp_faddr;
		len += sizeof (struct idp);
	}

	idp->idp_len = htons((u_short)len);

	if (idpcksum) {
		idp->idp_sum = 0;
		len = ((len - 1) | 1) + 1;
		idp->idp_sum = ns_cksum(m, len);
	} else
		idp->idp_sum = 0xffff;

	/*
	 * Output datagram.
	 */
	so = nsp->nsp_socket;
	if (so->so_options & SO_DONTROUTE)
		return (ns_output(m, (struct route *)0,
		    (so->so_options & SO_BROADCAST) | NS_ROUTETOIF));
	/*
	 * Use cached route for previous datagram if
D 10
	 * this is also to the same destination. 
E 10
I 10
	 * possible.  If the previous net was the same
	 * and the interface was a broadcast medium, or
	 * if the previous destination was identical,
	 * then we are ok.
E 10
	 *
	 * NB: We don't handle broadcasts because that
	 *     would require 3 subroutine calls.
	 */
	ro = &nsp->nsp_route;
D 10
	if (ro->ro_rt &&
		((*(long *)&nsp->nsp_lastnet)!=ns_netof(idp->idp_dna)) &&
		!(ns_hosteq(satons_addr(ro->ro_dst), idp->idp_dna))) {
		RTFREE(ro->ro_rt);
		ro->ro_rt = (struct rtentry *)0;
		nsp->nsp_lastnet = idp->idp_dna.x_net;
E 10
I 10
#ifdef ancient_history
	/*
	 * I think that this will all be handled in ns_pcbconnect!
	 */
	if (ro->ro_rt) {
		if(ns_neteq(nsp->nsp_lastdst, idp->idp_dna)) {
			/*
			 * This assumes we have no GH type routes
			 */
			if (ro->ro_rt->rt_flags & RTF_HOST) {
				if (!ns_hosteq(nsp->nsp_lastdst, idp->idp_dna))
					goto re_route;

			}
			if ((ro->ro_rt->rt_flags & RTF_GATEWAY) == 0) {
				register struct ns_addr *dst =
						&satons_addr(ro->ro_dst);
				dst->x_host = idp->idp_dna.x_host;
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
	}
I 10
	nsp->nsp_lastdst = idp->idp_dna;
#endif ancient_history
	if (noIdpRoute) ro = 0;
E 10
	return (ns_output(m, ro, so->so_options & SO_BROADCAST));
}
D 7
/*ARGSUSED*/
E 7
I 7
/* ARGSUSED */
E 7
idp_ctloutput(req, so, level, name, value)
	int req, level;
	struct socket *so;
	int name;
	struct mbuf **value;
{
	register struct mbuf *m;
	struct nspcb *nsp = sotonspcb(so);
	int mask, error = 0;
I 5
	extern long ns_pexseq;
E 5

D 4
	if (nsp == NULL) {
		error = EINVAL;
		goto release;
	}
E 4
I 4
	if (nsp == NULL)
		return (EINVAL);
E 4

	switch (req) {
I 4

E 4
	case PRCO_GETOPT:
D 4
		if (value==NULL) {
			error = EINVAL;
			goto release;
		}
E 4
I 4
		if (value==NULL)
			return (EINVAL);
E 4
		m = m_get(M_DONTWAIT, MT_DATA);
I 4
		if (m==NULL)
			return (ENOBUFS);
E 4
		switch (name) {
I 4

I 6
		case SO_ALL_PACKETS:
			mask = NSP_ALL_PACKETS;
			goto get_flags;

E 6
E 4
		case SO_HEADERS_ON_INPUT:
			mask = NSP_RAWIN;
			goto get_flags;
I 4
			
E 4
		case SO_HEADERS_ON_OUTPUT:
			mask = NSP_RAWOUT;
		get_flags:
			m->m_len = sizeof(short);
			m->m_off = MMAXOFF - sizeof(short);
			*mtod(m, short *) = nsp->nsp_flags & mask;
			break;
I 4

E 4
		case SO_DEFAULT_HEADERS:
			m->m_len = sizeof(struct idp);
			m->m_off = MMAXOFF - sizeof(struct idp);
			{
				register struct idp *idp = mtod(m, struct idp *);
				idp->idp_len = 0;
				idp->idp_sum = 0;
				idp->idp_tc = 0;
				idp->idp_pt = nsp->nsp_dpt;
				idp->idp_dna = nsp->nsp_faddr;
				idp->idp_sna = nsp->nsp_laddr;
			}
I 5
			break;

		case SO_SEQNO:
			m->m_len = sizeof(long);
			m->m_off = MMAXOFF - sizeof(long);
			*mtod(m, long *) = ns_pexseq++;
I 12
			break;

		default:
			error = EINVAL;
E 12
E 5
		}
		*value = m;
		break;
I 4

E 4
	case PRCO_SETOPT:
		switch (name) {
D 7
			int mask, *ok;
E 7
I 7
			int *ok;
E 7
I 6

		case SO_ALL_PACKETS:
			mask = NSP_ALL_PACKETS;
			goto set_head;
E 6

		case SO_HEADERS_ON_INPUT:
			mask = NSP_RAWIN;
			goto set_head;
I 4

E 4
		case SO_HEADERS_ON_OUTPUT:
			mask = NSP_RAWOUT;
		set_head:
			if (value && *value) {
				ok = mtod(*value, int *);
				if (*ok)
					nsp->nsp_flags |= mask;
				else
					nsp->nsp_flags &= ~mask;
			} else error = EINVAL;
			break;
I 4

E 4
		case SO_DEFAULT_HEADERS:
			{
				register struct idp *idp
				    = mtod(*value, struct idp *);
				nsp->nsp_dpt = idp->idp_pt;
			}
D 12
#ifdef NSIP
E 12
			break;
I 12
#ifdef NSIP
E 12
I 4

E 4
		case SO_NSIP_ROUTE:
			error = nsip_route(*value);
I 12
			break;
E 12
D 4
			break;
E 4
#endif NSIP
I 12
		default:
			error = EINVAL;
E 12
		}
		if (value && *value)
			m_freem(*value);
		break;
	}
D 4
	release:
		return(error);
E 4
I 4
	return (error);
E 4
}

/*ARGSUSED*/
idp_usrreq(so, req, m, nam, rights)
	struct socket *so;
	int req;
	struct mbuf *m, *nam, *rights;
{
	struct nspcb *nsp = sotonspcb(so);
	int error = 0;

	if (req == PRU_CONTROL)
                return (ns_control(so, (int)m, (caddr_t)nam,
			(struct ifnet *)rights));
	if (rights && rights->m_len) {
		error = EINVAL;
		goto release;
	}
	if (nsp == NULL && req != PRU_ATTACH) {
		error = EINVAL;
		goto release;
	}
	switch (req) {

	case PRU_ATTACH:
		if (nsp != NULL) {
			error = EINVAL;
			break;
		}
		error = ns_pcballoc(so, &nspcb);
		if (error)
			break;
D 16
		error = soreserve(so, 2048, 2048);
E 16
I 16
		error = soreserve(so, (u_long) 2048, (u_long) 2048);
E 16
		if (error)
			break;
		break;

	case PRU_DETACH:
		if (nsp == NULL) {
			error = ENOTCONN;
			break;
		}
		ns_pcbdetach(nsp);
		break;

	case PRU_BIND:
		error = ns_pcbbind(nsp, nam);
		break;

	case PRU_LISTEN:
		error = EOPNOTSUPP;
		break;

	case PRU_CONNECT:
		if (!ns_nullhost(nsp->nsp_faddr)) {
			error = EISCONN;
			break;
		}
		error = ns_pcbconnect(nsp, nam);
		if (error == 0)
			soisconnected(so);
		break;

	case PRU_CONNECT2:
		error = EOPNOTSUPP;
		break;

	case PRU_ACCEPT:
		error = EOPNOTSUPP;
		break;

	case PRU_DISCONNECT:
		if (ns_nullhost(nsp->nsp_faddr)) {
			error = ENOTCONN;
			break;
		}
		ns_pcbdisconnect(nsp);
		soisdisconnected(so);
		break;

	case PRU_SHUTDOWN:
		socantsendmore(so);
		break;

	case PRU_SEND:
	{
		struct ns_addr laddr;
		int s;

		if (nam) {
			laddr = nsp->nsp_laddr;
			if (!ns_nullhost(nsp->nsp_faddr)) {
				error = EISCONN;
				break;
			}
			/*
			 * Must block input while temporarily connected.
			 */
			s = splnet();
			error = ns_pcbconnect(nsp, nam);
			if (error) {
				splx(s);
				break;
			}
		} else {
			if (ns_nullhost(nsp->nsp_faddr)) {
				error = ENOTCONN;
				break;
			}
		}
		error = idp_output(nsp, m);
		m = NULL;
		if (nam) {
			ns_pcbdisconnect(nsp);
			splx(s);
			nsp->nsp_laddr.x_host = laddr.x_host;
			nsp->nsp_laddr.x_port = laddr.x_port;
		}
	}
		break;

	case PRU_ABORT:
		ns_pcbdetach(nsp);
		sofree(so);
		soisdisconnected(so);
		break;

	case PRU_SOCKADDR:
		ns_setsockaddr(nsp, nam);
		break;

	case PRU_PEERADDR:
		ns_setpeeraddr(nsp, nam);
		break;

	case PRU_SENSE:
		/*
		 * stat: don't bother with a blocksize.
		 */
		return (0);

	case PRU_SENDOOB:
	case PRU_FASTTIMO:
	case PRU_SLOWTIMO:
	case PRU_PROTORCV:
	case PRU_PROTOSEND:
		error =  EOPNOTSUPP;
		break;

	case PRU_CONTROL:
	case PRU_RCVD:
	case PRU_RCVOOB:
		return (EOPNOTSUPP);	/* do not free mbuf's */

	default:
		panic("idp_usrreq");
	}
release:
	if (m != NULL)
		m_freem(m);
	return (error);
}
/*ARGSUSED*/
idp_raw_usrreq(so, req, m, nam, rights)
	struct socket *so;
	int req;
	struct mbuf *m, *nam, *rights;
{
	int error = 0;
	struct nspcb *nsp = sotonspcb(so);
	extern struct nspcb nsrawpcb;

	switch (req) {

	case PRU_ATTACH:

D 2
		if (nsp != NULL) {
E 2
I 2
		if (!suser() || (nsp != NULL)) {
E 2
			error = EINVAL;
			break;
		}
		error = ns_pcballoc(so, &nsrawpcb);
		if (error)
			break;
D 16
		error = soreserve(so, 2048, 2048);
E 16
I 16
		error = soreserve(so, (u_long) 2048, (u_long) 2048);
E 16
		if (error)
			break;
		nsp = sotonspcb(so);
		nsp->nsp_faddr.x_host = ns_broadhost;
		nsp->nsp_flags = NSP_RAWIN | NSP_RAWOUT;
		break;
	default:
		error = idp_usrreq(so, req, m, nam, rights);
	}
D 4
	return(error);
E 4
I 4
	return (error);
E 4
}

E 1
