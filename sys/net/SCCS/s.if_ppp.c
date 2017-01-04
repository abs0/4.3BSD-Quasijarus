h08109
s 00016/00002/00794
d D 7.11 08/04/05 08:26:27 msokolov 11 10
c authentication hooks implemented
e
s 00010/00006/00786
d D 7.10 08/02/18 04:16:37 msokolov 10 9
c hooks for pppaux unknown protocols Rx
e
s 00047/00000/00745
d D 7.9 07/04/15 05:11:12 msokolov 9 8
c fixed race condition with Up/Down events
e
s 00014/00000/00731
d D 7.8 02/08/02 23:39:22 msokolov 8 7
c notify netmon on state transitions
e
s 00008/00000/00723
d D 7.7 02/07/23 23:55:48 msokolov 7 6
c add SIOCPPPGETIPCPS
e
s 00002/00002/00721
d D 7.6 02/07/23 19:36:36 msokolov 6 5
c pass ifa to pppipcp_open
e
s 00090/00000/00633
d D 7.5 02/07/22 21:10:31 msokolov 5 4
c add ioctls for fine control of PPP features/quirks
e
s 00003/00011/00630
d D 7.4 02/07/21 12:37:42 msokolov 4 3
c minor buglets, better PERSIST handling, more diagnostic output
e
s 00050/00020/00591
d D 7.3 02/07/20 15:07:25 msokolov 3 2
c first working version (2 ppp's connected with null-modem reach OPENED)
c add diagnostic output
e
s 00001/00000/00610
d D 7.2 02/07/19 22:05:14 msokolov 2 1
c add pppasync_init() call to pppattach
e
s 00610/00000/00000
d D 7.1 02/07/11 10:56:31 msokolov 1 0
c ppp module base written, compiles
e
u
U
t
T
I 1
/*
 * Copyright (c) 1987 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
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
 *
 *	%W% (Berkeley) %G%
 */

/*
 * PPP (RFC 1661) interface module
 *
 * This module implements the PPP protocol and provides a configured number of
 * ppp interfaces to the network subsystem. It does not, however, talk to any
 * hardware. Instead, in order to use the ppp module one must attach it to a
 * backend interface that provides the physical layer functions. The attachment
 * mechanism is determined by the latter.
 *
 * Written by Michael Sokolov, Quasijarus Project, International Free Computing
 * Task Force.
I 9
 *
 * Designed to run at splnet.
E 9
 */

#include "ppp.h"
#if NPPP > 0

#include "param.h"
#include "mbuf.h"
#include "buf.h"
#include "dkstat.h"
#include "socket.h"
#include "ioctl.h"
#include "file.h"
#include "tty.h"
#include "errno.h"
D 3
#include "malloc.h"
E 3
I 3
#include "syslog.h"
E 3

#include "if.h"
#include "netisr.h"
#include "route.h"
#include "if_hdlc.h"
#include "if_ppp.h"
#include "if_pppvar.h"

#if INET
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
#include "../netinet/in_var.h"
#include "../netinet/ip.h"
#include "if_pppipcp.h"
#endif

#include "../machine/mtpr.h"

I 10
#include "pppaux.h"
E 10
I 8
#include "netmon.h"

E 8
struct ppp_softc ppp_softc[NPPP];
struct ifqueue ppplcpinq, pppunkq;

I 3
char *ppp_states[] = {
	"INITIAL",
	"STARTING",
	"CLOSED",
	"STOPPED",
	"CLOSING",
	"STOPPING",
	"REQSENT",
	"ACKRCVD",
	"ACKSENT",
	"OPENED"
};

E 3
int pppoutput(), pppioctl(), ppptimer();

/*
 * Called from boot code to establish ppp interfaces.
 */
pppattach()
{
	register struct ppp_softc *pp;
	register int i = 0;

	for (pp = ppp_softc; i < NPPP; pp++) {
		pp->pp_if.if_name = "ppp";
		pp->pp_if.if_unit = i++;
		pp->pp_if.if_mtu = PPP_DEFAULT_MTU;
		pp->pp_if.if_flags = IFF_POINTOPOINT;
		pp->pp_if.if_ioctl = pppioctl;
		pp->pp_if.if_output = pppoutput;
		pp->pp_if.if_watchdog = ppptimer;
		pp->pp_if.if_snd.ifq_maxlen = IFQ_MAXLEN;
		pp->pp_restimer = 2;
		pp->pp_maxconf = 10;
		pp->pp_maxterm = 2;
		if_attach(&pp->pp_if);
	}
	ppplcpinq.ifq_maxlen = IFQ_MAXLEN;
	pppunkq.ifq_maxlen = IFQ_MAXLEN;
#ifdef INET
	pppipcpinq.ifq_maxlen = IFQ_MAXLEN;
#endif
I 2
	pppasync_init();
I 10
#if NPPPAUX
	pppaux_init();
#endif
E 10
E 2
}

/*
 * The following routines implement the interface automaton events defined in
 * RFC 1661 section 4.3. They must be called at splnet or higher.
I 9
 *
 * pppup() and pppdown() are particularly tricky. They are called from PHY
 * hardware interrupt handlers, and since most of this module runs at splnet,
 * we are not protected against a race condition with Up/Down events.
 * Solution: it's a kludge. Whenever the rest of the module gets ready to
 * operate on an interface, it sets pp_busy in addition to splnet.
 * pppup() and pppdown() check pp_busy and if set, they don't do their job and
 * set pp_pending_updn instead (1 for pending Up, -1 for pending Down).
 * They also schedule a netisr.  Our netisr then handles them.
E 9
 */
pppup(pp)
	register struct ppp_softc *pp;
{
I 3
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: Up event to automaton\n",
			pp->pp_if.if_unit);
I 9
	if (pp->pp_busy) {
		pp->pp_pending_updn = 1;
		schednetisr(NETISR_PPPCTL);
		return;
	}
	pp->pp_pending_updn = 0;
E 9
E 3
	switch (pp->pp_state) {
	case PPP_STATE_INITIAL:
		if (pp->pp_flags & PPP_FLAGS_PERSIST) {
			ppplcp_init_negot(pp);
			pp->pp_restcnt = pp->pp_maxconf;
			ppplcp_send_confreq(pp);
D 3
			pppstatechg(PPP_STATE_REQSENT);
E 3
I 3
			pppstatechg(pp, PPP_STATE_REQSENT);
E 3
		}
		if (pp->pp_flags & PPP_FLAGS_PASSIVE)
D 3
			pppstatechg(PPP_STATE_STOPPED);
E 3
I 3
			pppstatechg(pp, PPP_STATE_STOPPED);
E 3
		break;
	case PPP_STATE_STARTING:
		ppplcp_init_negot(pp);
		pp->pp_restcnt = pp->pp_maxconf;
		ppplcp_send_confreq(pp);
D 3
		pppstatechg(PPP_STATE_REQSENT);
E 3
I 3
		pppstatechg(pp, PPP_STATE_REQSENT);
E 3
		break;
	case PPP_STATE_STOPPED:
		if (pp->pp_flags & PPP_FLAGS_PERSIST) {
			ppplcp_init_negot(pp);
			pp->pp_restcnt = pp->pp_maxconf;
			ppplcp_send_confreq(pp);
D 3
			pppstatechg(PPP_STATE_REQSENT);
E 3
I 3
			pppstatechg(pp, PPP_STATE_REQSENT);
E 3
		}
		break;
	}
}

pppdown(pp)
	register struct ppp_softc *pp;
{
I 3
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: Down event to automaton\n",
			pp->pp_if.if_unit);
I 9
	if (pp->pp_busy) {
		pp->pp_pending_updn = -1;
		schednetisr(NETISR_PPPCTL);
		return;
	}
	pp->pp_pending_updn = 0;
E 9
E 3
	if (pp->pp_flags & PPP_FLAGS_PERSIST) {
D 3
		pppstatechg(PPP_STATE_STARTING);
E 3
I 3
		pppstatechg(pp, PPP_STATE_STARTING);
E 3
		(*pp->pp_hw->phw_up)(pp);
	} else {
D 3
		pppstatechg(PPP_STATE_INITIAL);
E 3
I 3
		pppstatechg(pp, PPP_STATE_INITIAL);
E 3
		(*pp->pp_hw->phw_down)(pp);
	}
}

pppopen(pp)
	register struct ppp_softc *pp;
{
	register int t;

I 3
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: Open event to automaton\n",
			pp->pp_if.if_unit);
E 3
	switch (pp->pp_state) {
	case PPP_STATE_INITIAL:
		(*pp->pp_hw->phw_up)(pp);
		t = (*pp->pp_hw->phw_check)(pp);
		if (t) {
			ppplcp_init_negot(pp);
			pp->pp_restcnt = pp->pp_maxconf;
			ppplcp_send_confreq(pp);
D 3
			pppstatechg(PPP_STATE_REQSENT);
E 3
I 3
			pppstatechg(pp, PPP_STATE_REQSENT);
E 3
		} else
D 3
			pppstatechg(PPP_STATE_STARTING);
E 3
I 3
			pppstatechg(pp, PPP_STATE_STARTING);
E 3
		break;
	case PPP_STATE_STARTING:
		break;
	case PPP_STATE_CLOSED:
	case PPP_STATE_STOPPED:
	case PPP_STATE_CLOSING:
	case PPP_STATE_STOPPING:
		ppplcp_init_negot(pp);
		pp->pp_restcnt = pp->pp_maxconf;
		ppplcp_send_confreq(pp);
D 3
		pppstatechg(PPP_STATE_REQSENT);
E 3
I 3
		pppstatechg(pp, PPP_STATE_REQSENT);
E 3
		break;
	}
}

pppclose(pp)
	register struct ppp_softc *pp;
{
I 3
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: Close event to automaton\n",
			pp->pp_if.if_unit);
E 3
	pp->pp_flags &= ~(PPP_FLAGS_PERSIST | PPP_FLAGS_PASSIVE);
	switch (pp->pp_state) {
	case PPP_STATE_INITIAL:
	case PPP_STATE_STARTING:
		(*pp->pp_hw->phw_down)(pp);
D 3
		pppstatechg(PPP_STATE_INITIAL);
E 3
I 3
		pppstatechg(pp, PPP_STATE_INITIAL);
E 3
		break;
	case PPP_STATE_CLOSED:
	case PPP_STATE_STOPPED:
		(*pp->pp_hw->phw_down)(pp);
D 3
		pppstatechg(PPP_STATE_CLOSED);
E 3
I 3
		pppstatechg(pp, PPP_STATE_CLOSED);
E 3
		break;
	case PPP_STATE_CLOSING:
	case PPP_STATE_STOPPING:
D 3
		pppstatechg(PPP_STATE_CLOSING);
E 3
I 3
		pppstatechg(pp, PPP_STATE_CLOSING);
E 3
		break;
	case PPP_STATE_REQSENT:
	case PPP_STATE_ACKRCVD:
	case PPP_STATE_ACKSENT:
	case PPP_STATE_OPENED:
		pp->pp_restcnt = pp->pp_maxterm;
		ppplcp_send_termreq(pp);
D 3
		pppstatechg(PPP_STATE_CLOSING);
E 3
I 3
		pppstatechg(pp, PPP_STATE_CLOSING);
E 3
		break;
	}
}

pppstatechg(pp, newstate)
	register struct ppp_softc *pp;
	register int newstate;
{
	register int up = 0;

	if (pp->pp_state != PPP_STATE_OPENED && newstate == PPP_STATE_OPENED) {
		pp->pp_if.if_mtu = MIN(pp->pp_desmtu, pp->pp_agreedmtu);
		up++;
	}
	if (pp->pp_state == PPP_STATE_OPENED && newstate != PPP_STATE_OPENED)
		ppp_is_down(pp);
	pp->pp_state = newstate;
I 3
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: in %s state\n", pp->pp_if.if_unit,
			ppp_states[newstate]);
E 3
	if (newstate == PPP_STATE_INITIAL)
		pp->pp_if.if_flags &= ~IFF_RUNNING;
	else
D 4
		pp->pp_if.if_flags != IFF_RUNNING;
E 4
I 4
		pp->pp_if.if_flags |= IFF_RUNNING;
I 8
#if NNETMON > 0
	netmon_ifevent(&pp->pp_if);
#endif
E 8
E 4
D 11
	if (up)
		ppp_is_up(pp);
E 11
I 11
	if (up) {
		if (pp->pp_peerconf & PEERCONF_NEEDAUTH
		    || pp->pp_authpeer_nprotos)
			; /* authentication needs to be handled in user mode */
		else
			ppp_is_up(pp);
	}
E 11
}

/* PPP link in the Network-Layer Protocol Phase (RFC 1661 sec 3.6) */
ppp_is_up(pp)
	register struct ppp_softc *pp;
{
	register struct ifaddr *ifa;

	pp->pp_flags |= PPP_FLAGS_UP;
	pp->pp_if.if_flags |= IFF_UP;
I 3
	log(LOG_NOTICE, "ppp%d: link is UP\n", pp->pp_if.if_unit);
E 3
	for (ifa = pp->pp_if.if_addrlist; ifa; ifa = ifa->ifa_next)
		switch (ifa->ifa_addr.sa_family) {

#ifdef INET
		case AF_INET:
D 6
			pppipcp_open(pp);
E 6
I 6
			pppipcp_open(pp, ifa);
E 6
			break;
#endif

		}
I 8
#if NNETMON > 0
	netmon_ifevent(&pp->pp_if);
#endif
E 8
}

/* Leaving the Opened state */
ppp_is_down(pp)
	register struct ppp_softc *pp;
{
	if_down(&pp->pp_if);
	pp->pp_flags &= ~PPP_FLAGS_UP;
#ifdef INET
	pppipcp_softc[pp->pp_if.if_unit].ipcp_state = PPPIPCP_STATE_INITIAL;
#endif
I 3
	log(LOG_NOTICE, "ppp%d: link is DOWN\n", pp->pp_if.if_unit);
I 8
#if NNETMON > 0
	netmon_ifevent(&pp->pp_if);
#endif
E 8
E 3
}

/*
 * Immediately reset all interface state without going through otherwise
 * required closing steps. Used, for example, when detaching the ppp module
 * from the underlying if. Must be called at splnet or above.
 */
pppreset(pp)
	register struct ppp_softc *pp;
{
	if (pp->pp_if.if_flags & IFF_UP)
		if_down(&pp->pp_if);
	pp->pp_if.if_flags &= ~IFF_RUNNING;
	pp->pp_state = PPP_STATE_INITIAL;
	pp->pp_flags = 0;
I 11
	pp->pp_authself_nprotos = 0;
	pp->pp_authpeer_nprotos = 0;
E 11
#ifdef INET
	pppipcp_softc[pp->pp_if.if_unit].ipcp_state = PPPIPCP_STATE_INITIAL;
I 8
#endif
I 9
	pp->pp_pending_updn = 0;
E 9
#if NNETMON > 0
	netmon_ifevent(&pp->pp_if);
E 8
#endif
}

/* This is the main packet input directly from the hardware interrupt. */
pppinput(pp, m, proto)
	register struct ppp_softc *pp;
	register struct mbuf *m;
	register int proto;
{
	register struct ifqueue *inq;
	register struct mbuf *mh;
	int fhdr = 0, isr, s;

	switch (proto) {

	case PPPPROTO_LCP:
		if (pp->pp_state == PPP_STATE_INITIAL) {
			m_freem(m);
			return;
		}
		isr = NETISR_PPPCTL;
		inq = &ppplcpinq;
		break;

#ifdef INET
	case PPPPROTO_IP:
		if (pppipcp_softc[pp->pp_if.if_unit].ipcp_state !=
		    PPPIPCP_STATE_OPENED) {
			m_freem(m);
			return;
		}
		isr = NETISR_IP;
		inq = &ipintrq;
		break;
	case PPPPROTO_IPCP:
		if (!(pp->pp_flags & PPP_FLAGS_UP)) {
			m_freem(m);
			return;
		}
		isr = NETISR_PPPCTL;
		inq = &pppipcpinq;
		break;
#endif

	default:
		if (pp->pp_state != PPP_STATE_OPENED) {
			m_freem(m);
			return;
		}
		isr = NETISR_PPPCTL;
		inq = &pppunkq;
		fhdr++;
	}

	mh = m_get(M_DONTWAIT, MT_HEADER);
	if (mh == 0) {
		m_freem(m);
		return;
	}
	mh->m_next = m;
	mh->m_off = MMINOFF;
	mh->m_len = sizeof (struct ifnet *);
	*(mtod(mh, struct ifnet **)) = &pp->pp_if;

	if (fhdr) {
		struct hdlc_header *hh;

		hh = (struct hdlc_header *)
				(mtod(mh, char *) + sizeof(struct ifnet *));
		hh->hdlc_address = PPP_FRAME_ADDR;
		hh->hdlc_control = PPP_FRAME_CONTROL;
D 10
		hh->hdlc_type = htons(proto);
E 10
I 10
		hh->hdlc_type = proto;
E 10
		mh->m_len += sizeof(struct hdlc_header);
	}

	s = splimp();
	if (IF_QFULL(inq)) {
		IF_DROP(inq);
		splx(s);
		m_freem(mh);
		return;
	}
	IF_ENQUEUE(inq, mh);
	splx(s);
	schednetisr(isr);
}

/*
 * pppctl software interrupt routine. All non-time-critical control packet
 * processing happens here.
 */
pppctlintr()
{
	/* We just call our processing modules that want to run at this time */
I 9
	ppp_deferred_updown();
E 9
	ppplcp_inprocess();
#ifdef INET
	pppipcp_inprocess();
#endif
	ppp_unknown_process();
}

I 9
ppp_deferred_updown()
{
	int i, s;
	register struct ppp_softc *pp;
	register int updn;

	for (i = 0, pp = ppp_softc; i < NPPP; i++, pp++)
		if (pp->pp_pending_updn) {
			s = splimp();
			updn = pp->pp_pending_updn;
			if (updn > 0)
				pppup(pp);
			else if (updn < 0)
				pppdown(pp);
			splx(s);
		}
}

E 9
/* Output routine visible to the network layer */
pppoutput(ifp, m, dst)
	struct ifnet *ifp;
	register struct mbuf *m;
	struct sockaddr *dst;
{
	register int proto, error;
	register struct ppp_softc *pp = (struct ppp_softc *) ifp;
	struct hdlc_header *hh;

	if (pp->pp_state != PPP_STATE_OPENED) {
		error = ENETDOWN;
bad:		m_freem(m);
		return(error);
	}
	switch (dst->sa_family) {

#ifdef INET
	case AF_INET:
		if (pppipcp_softc[pp->pp_if.if_unit].ipcp_state !=
		    PPPIPCP_STATE_OPENED) {
			error = ENETDOWN;
			goto bad;
		}
		proto = PPPPROTO_IP;
		break;
#endif

	case AF_UNSPEC:
		hh = (struct hdlc_header *)dst->sa_data;
		proto = hh->hdlc_type;
		break;

	default:
		printf("ppp%d: can't handle af%d\n", ifp->if_unit,
			dst->sa_family);
		error = EAFNOSUPPORT;
		goto bad;
	}

	return((*pp->pp_hw->phw_output)(pp, m, proto));
}

/* Timer routine called whenever pp_if.if_timer reaches zero. */
ppptimer(unit)
	int unit;
{
	register struct ppp_softc *pp = &ppp_softc[unit];
	int s = splnet();

I 9
	pp->pp_busy = 1;
E 9
	switch (pp->pp_state) {
	case PPP_STATE_STOPPED:
		if (pp->pp_flags & PPP_FLAGS_PERSIST) {
			ppplcp_init_negot(pp);
			pp->pp_restcnt = pp->pp_maxconf;
			ppplcp_send_confreq(pp);
D 3
			pppstatechg(PPP_STATE_REQSENT);
E 3
I 3
			pppstatechg(pp, PPP_STATE_REQSENT);
E 3
		}
		break;
	case PPP_STATE_CLOSING:
		if (pp->pp_restcnt)
			ppplcp_send_termreq(pp);
		else {
D 3
			pppstatechg(PPP_STATE_CLOSED);
E 3
I 3
			pppstatechg(pp, PPP_STATE_CLOSED);
E 3
			(*pp->pp_hw->phw_down)(pp);
		}
		break;
	case PPP_STATE_STOPPING:
		if (pp->pp_restcnt)
			ppplcp_send_termreq(pp);
		else {
D 3
			pppstatechg(PPP_STATE_STOPPED);
E 3
I 3
			pppstatechg(pp, PPP_STATE_STOPPED);
E 3
			if (pp->pp_flags & PPP_FLAGS_PERSIST) {
				pp->pp_if.if_timer = 2;
				break;
			}
			if (pp->pp_flags & PPP_FLAGS_PASSIVE)
				break;
			(*pp->pp_hw->phw_down)(pp);
		}
		break;
	case PPP_STATE_REQSENT:
D 4
		if (pp->pp_restcnt)
E 4
I 4
		if (pp->pp_restcnt || pp->pp_flags & PPP_FLAGS_PERSIST)
E 4
			ppplcp_send_confreq(pp);
		else {
D 3
			pppstatechg(PPP_STATE_STOPPED);
E 3
I 3
			pppstatechg(pp, PPP_STATE_STOPPED);
E 3
D 4
			if (pp->pp_flags & PPP_FLAGS_PERSIST) {
				pp->pp_if.if_timer = 2;
				break;
			}
E 4
			if (pp->pp_flags & PPP_FLAGS_PASSIVE)
				break;
			(*pp->pp_hw->phw_down)(pp);
		}
		break;
	case PPP_STATE_ACKRCVD:
		pp->pp_restcnt = pp->pp_maxconf;
		ppplcp_send_confreq(pp);
D 3
		pppstatechg(PPP_STATE_REQSENT);
E 3
I 3
		pppstatechg(pp, PPP_STATE_REQSENT);
E 3
		break;
	case PPP_STATE_ACKSENT:
D 4
		if (pp->pp_restcnt)
E 4
I 4
		if (pp->pp_restcnt || pp->pp_flags & PPP_FLAGS_PERSIST)
E 4
			ppplcp_send_confreq(pp);
		else {
D 3
			pppstatechg(PPP_STATE_STOPPED);
E 3
I 3
			pppstatechg(pp, PPP_STATE_STOPPED);
E 3
D 4
			if (pp->pp_flags & PPP_FLAGS_PERSIST) {
				pp->pp_if.if_timer = 2;
				break;
			}
E 4
			if (pp->pp_flags & PPP_FLAGS_PASSIVE)
				break;
			(*pp->pp_hw->phw_down)(pp);
		}
		break;
	case PPP_STATE_OPENED:
#ifdef INET
		pppipcp_timer(pp);
#endif
		break;
	}
I 9
	pp->pp_busy = 0;
E 9
	splx(s);
}

/* Process received packets with unknown protocol at pppctl soft intr time */
ppp_unknown_process()
{
	register struct ppp_softc *pp;
	register struct mbuf *m, *m2;
	struct hdlc_header *hh;
	int s, proto;

next:	s = splimp();
	IF_DEQUEUE(&pppunkq, m);
	splx(s);
	if (m == 0)
		return;
	pp = *(mtod(m, struct ppp_softc **));
	IF_ADJ(m);
	if (pp->pp_state != PPP_STATE_OPENED) {
		m_freem(m);
		goto next;
	}
	hh = mtod(m, struct hdlc_header *);
D 10
	proto = ntohs(hh->hdlc_type);
E 10
I 10
	proto = hh->hdlc_type;
E 10

D 10
	/*
	 * TODO: Allow passing unknown protocols to userland handlers
	 * via raw sockets.
	 */
E 10
I 10
#if NPPPAUX
	if (pppaux_input(pp, m, proto))
		goto next;
#endif
E 10

	/*
	 * We don't know anything about it and must send the peer a
	 * Protocol-Reject. We need to give the offending packet to
	 * ppplcp_send_protrej which disposes of it.
	 */
	m->m_off += sizeof(struct hdlc_header);
	m->m_len -= sizeof(struct hdlc_header);
	if (m->m_len == 0) {
		MFREE(m, m2);
		m = m2;
	}
	ppplcp_send_protrej(pp, proto, m);
	goto next;
}

/*
 * Process an ioctl request.
 */
pppioctl(ifp, cmd, data)
	register struct ifnet *ifp;
	int cmd;
	caddr_t data;
{
	register struct ppp_softc *pp = (struct ppp_softc *) ifp;
	struct ifreq *ifr;
	struct ifaddr *ifa;
	int s = splnet(), error = 0;
I 5
	int i;
E 5

I 9
	pp->pp_busy = 1;
E 9
	switch (cmd) {

	case SIOCSIFADDR:
	case SIOCSIFDSTADDR:
		ifa = (struct ifaddr *) data;
		if (ifa->ifa_addr.sa_family && ifa->ifa_dstaddr.sa_family &&
		    pp->pp_hw) {
			pppopen(pp);
			if (pp->pp_flags & PPP_FLAGS_UP)
			switch (ifa->ifa_addr.sa_family) {

#ifdef INET
			case AF_INET:
D 6
				pppipcp_open(pp);
E 6
I 6
				pppipcp_open(pp, ifa);
E 6
				break;
#endif

			}
		}
		break;

	case SIOCSIFFLAGS:
		if (ifp->if_flags & IFF_UP) {
			if (!(pp->pp_flags & PPP_FLAGS_UP)) {
				ifp->if_flags &= ~IFF_UP;
				if (pp->pp_hw)
					pppopen(pp);
				else
					error = ENETDOWN;
			}
		} else {
			if (pp->pp_hw)
				pppclose(pp);
		}
		break;

	case SIOCSIFMTU:
		ifr = (struct ifreq *) data;
		if (ifr->ifr_mtu < IF_MINMTU) {
			error = EINVAL;
			break;
		}
		if (pp->pp_hw) {
			pp->pp_desmtu = MIN(ifr->ifr_mtu, pp->pp_hw->phw_mtu);
			pp->pp_desmru = MIN(ifr->ifr_mtu, pp->pp_hw->phw_mru);
			if (pp->pp_state == PPP_STATE_OPENED)
				ifp->if_mtu = MIN(pp->pp_desmtu,
							pp->pp_agreedmtu);
		} else
			ifp->if_mtu = ifr->ifr_mtu;
		break;

I 5
	case SIOCPPPGETSTATE:
		ifr = (struct ifreq *) data;
		ifr->ifr_data = (caddr_t) (u_long) pp->pp_state;
		break;

	case SIOCPPPGETFLAGS:
		ifr = (struct ifreq *) data;
		ifr->ifr_data = (caddr_t) (u_long) pp->pp_flags;
		break;

	case SIOCPPPGRESTIM:
		ifr = (struct ifreq *) data;
		ifr->ifr_data = (caddr_t) (u_long) pp->pp_restimer;
		break;

	case SIOCPPPSRESTIM:
		ifr = (struct ifreq *) data;
		i = (int) ifr->ifr_data;
		if (i >= 1 && i <= SHRT_MAX)
			pp->pp_restimer = i;
		else
			error = EINVAL;
		break;

	case SIOCPPPGMAXCONF:
		ifr = (struct ifreq *) data;
		ifr->ifr_data = (caddr_t) (u_long) pp->pp_maxconf;
		break;

	case SIOCPPPSMAXCONF:
		ifr = (struct ifreq *) data;
		i = (int) ifr->ifr_data;
		if (i >= 1 && i <= SHRT_MAX)
			pp->pp_maxconf = i;
		else
			error = EINVAL;
		break;

	case SIOCPPPGMAXTERM:
		ifr = (struct ifreq *) data;
		ifr->ifr_data = (caddr_t) (u_long) pp->pp_maxterm;
		break;

	case SIOCPPPSMAXTERM:
		ifr = (struct ifreq *) data;
		i = (int) ifr->ifr_data;
		if (i >= 1 && i <= SHRT_MAX)
			pp->pp_maxterm = i;
		else
			error = EINVAL;
		break;

	case SIOCPPPSPECACT:
		ifr = (struct ifreq *) data;
		error = pppioctl_specact(pp, (int) ifr->ifr_data);
		break;

I 7
#ifdef INET
	case SIOCPPPGETIPCPS:
		ifr = (struct ifreq *) data;
		ifr->ifr_data = (caddr_t) (u_long)
				pppipcp_softc[pp->pp_if.if_unit].ipcp_state;
		break;
#endif

E 7
E 5
	default:
		error = EINVAL;
	}
I 9
	pp->pp_busy = 0;
E 9
	splx(s);
	return (error);
I 5
}

/*
 * Process an ioctl special action request.
 */
pppioctl_specact(pp, act)
	register struct ppp_softc *pp;
	int act;
{
	switch (act) {
	case PPPACT_RESET:
		pppreset(pp);
		return(0);
	case PPPACT_RECOVDEFAULT:
		pp->pp_flags &= ~(PPP_FLAGS_PERSIST | PPP_FLAGS_PASSIVE);
		return(0);
	case PPPACT_RECOVPERSIST:
		pp->pp_flags |= PPP_FLAGS_PERSIST;
		pp->pp_flags &= ~PPP_FLAGS_PASSIVE;
		if (pp->pp_hw)
			pppopen(pp);
		return(0);
	case PPPACT_RECOVPASSIVE:
		pp->pp_flags |= PPP_FLAGS_PASSIVE;
		pp->pp_flags &= ~PPP_FLAGS_PERSIST;
		if (pp->pp_state == PPP_STATE_INITIAL && pp->pp_hw &&
		    (*pp->pp_hw->phw_check)(pp))
			pppstatechg(pp, PPP_STATE_STOPPED);
		return(0);
I 11
	case PPPACT_AUTHDONE:
		if (pp->pp_state == PPP_STATE_OPENED) {
			if (!(pp->pp_flags & PPP_FLAGS_UP))
				ppp_is_up(pp);
			return(0);
		} else
			return(ENETDOWN);
E 11
	default:
		return(EINVAL);
	}
E 5
}
#endif
E 1
