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
 *	@(#)if_pppipcp.c	7.4 (Berkeley) 4/15/07
 */

/*
 * PPP IP Control Protocol (IPCP, RFC 1332) implementation
 *
 * Our automaton here is an abbreviated version of the global PPP/LCP one.
 */

#include "ppp.h"
#if NPPP > 0 && defined(INET)

#include "param.h"
#include "mbuf.h"
#include "buf.h"
#include "dkstat.h"
#include "socket.h"
#include "ioctl.h"
#include "file.h"
#include "tty.h"
#include "errno.h"
#include "syslog.h"

#include "if.h"
#include "netisr.h"
#include "route.h"
#include "if_hdlc.h"
#include "if_ppp.h"
#include "if_pppvar.h"

#include "../netinet/in.h"
#include "../netinet/in_systm.h"
#include "../netinet/in_var.h"
#include "../netinet/ip.h"

#include "if_pppipcp.h"

#include "netmon.h"

struct pppipcp_softc pppipcp_softc[NPPP];
struct ifqueue pppipcpinq;
u_char pppipcp_packet_id;

char *pppipcp_states[] = {
	"INITIAL",
	"(unused)",
	"(unused)",
	"STOPPED",
	"(unused)",
	"STOPPING",
	"REQSENT",
	"ACKRCVD",
	"ACKSENT",
	"OPENED",
	"PAUSED"
};

pppipcp_open(pp, ia)
	register struct ppp_softc *pp;
	register struct in_ifaddr *ia;
{
	register struct pppipcp_softc *ipcp = &pppipcp_softc[pp->pp_if.if_unit];

	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: Open event to IPCP automaton\n",
			pp->pp_if.if_unit);
	switch (ipcp->ipcp_state) {
	case PPPIPCP_STATE_INITIAL:
		ipcp->ipcp_ia = ia;
	case PPPIPCP_STATE_STOPPED:
	case PPPIPCP_STATE_STOPPING:
	case PPPIPCP_STATE_PAUSED:
		pppipcp_init_negot(ipcp);
		pppipcp_send_confreq(pp, ipcp);
		pppipcp_statechg(ipcp, PPPIPCP_STATE_REQSENT);
	}
}

pppipcp_statechg(ipcp, newstate)
	register struct pppipcp_softc *ipcp;
	register int newstate;
{
	ipcp->ipcp_state = newstate;
	if (ipcp->ipcp_ia->ia_ifp->if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: IPCP in %s state\n",
			ipcp->ipcp_ia->ia_ifp->if_unit,
			pppipcp_states[newstate]);
#if NNETMON > 0
	netmon_ifevent(ipcp->ipcp_ia->ia_ifp);
#endif
}

/* Reset IPCP negotiation state to initial */
pppipcp_init_negot(ipcp)
	register struct pppipcp_softc *ipcp;
{
	register struct in_ifaddr *ia = ipcp->ipcp_ia;

	if (ipcp->ipcp_ia->ia_ifp->if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: starting IPCP negotiation\n",
			ipcp->ipcp_ia->ia_ifp->if_unit);
	ipcp->ipcp_negstate = IPCPNEGOT_SENDIPADDRS;
	if (!((struct sockaddr_in *)&ia->ia_addr)->sin_addr.s_addr ||
	    !((struct sockaddr_in *)&ia->ia_dstaddr)->sin_addr.s_addr)
		ipcp->ipcp_negstate |= IPCPNEGOT_NEEDIPADDRS;
}

/* Routines to send standard IPCP packets */
pppipcp_send_confreq(pp, ipcp)
	register struct ppp_softc *pp;
	register struct pppipcp_softc *ipcp;
{
	register struct in_ifaddr *ia = ipcp->ipcp_ia;
	register struct mbuf *m;
	register struct pppipcp_header *ih;
	register char *cp;

	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: sending IPCP Configure-Req\n",
			pp->pp_if.if_unit);
	MGET(m, M_DONTWAIT, MT_DATA);
	if (m == 0) {
		ipcp->ipcp_timer = pp->pp_restimer;
		pp->pp_if.if_timer = 1;
		return;
	}
	/*
	 * Leave room for an HDLC header as the phy output routine will almost
	 * certainly want to add one.
	 */
	m->m_off = MMINOFF + sizeof(struct hdlc_header);
	ih = mtod(m, struct pppipcp_header *);
	ih->ipcph_code = PPPIPCP_CONFREQ;
	ih->ipcph_id = ++pppipcp_packet_id;
	cp = (char *) (ih + 1);

	/* Now add the options we want */
	if (ipcp->ipcp_negstate & IPCPNEGOT_SENDIPADDRS) {
		if (pp->pp_if.if_flags & IFF_DEBUG)
			log(LOG_DEBUG,
				"ppp%d: requesting IP addresses 0x%x -> 0x%x\n",
				pp->pp_if.if_unit,
				ntohl(((struct sockaddr_in *)&ia->ia_addr)
					->sin_addr.s_addr),
				ntohl(((struct sockaddr_in *)&ia->ia_dstaddr)
					->sin_addr.s_addr));
		*cp++ = IPCPOPT_IPADDRS;
		*cp++ = 10;
		*(struct in_addr *) cp = ((struct sockaddr_in *)&ia->ia_addr)
						->sin_addr;
		cp += sizeof(struct in_addr);
		*(struct in_addr *) cp = ((struct sockaddr_in *)&ia->ia_dstaddr)
						->sin_addr;
		cp += sizeof(struct in_addr);
	}
	if (ipcp->ipcp_negstate & IPCPNEGOT_SENDIPADDR) {
		if (pp->pp_if.if_flags & IFF_DEBUG)
			log(LOG_DEBUG,
				"ppp%d: requesting IP address 0x%x\n",
				pp->pp_if.if_unit,
				ntohl(((struct sockaddr_in *)&ia->ia_addr)
					->sin_addr.s_addr));
		*cp++ = IPCPOPT_IPADDR;
		*cp++ = 6;
		*(struct in_addr *) cp = ((struct sockaddr_in *)&ia->ia_addr)
						->sin_addr;
		cp += sizeof(struct in_addr);
	}

	/* Set the length and send it! */
	m->m_len = cp - (char *) ih;
	ih->ipcph_len = htons(m->m_len);
	ipcp->ipcp_lastreqid = ih->ipcph_id;
	(*pp->pp_hw->phw_output)(pp, m, PPPPROTO_IPCP);
	ipcp->ipcp_timer = pp->pp_restimer;
	pp->pp_if.if_timer = 1;
}

/* Send a configure response (Ack, Nak, or Reject) with options */
pppipcp_send_confresp(pp, ipcp, code, id, opt)
	register struct ppp_softc *pp;
	register struct pppipcp_softc *ipcp;
	int code;
	u_char id;
	struct mbuf *opt;
{
	register struct mbuf *m, *mh;
	register struct pppipcp_header *ih;
	register int len;

	/* Construct the header for the response we want to send */
	MGET(mh, M_DONTWAIT, MT_HEADER);
	if (mh == 0) {
		m_freem(opt);
		return(ENOBUFS);
	}
	/*
	 * Leave room for an HDLC header as the phy output routine will almost
	 * certainly want to add one.
	 */
	mh->m_off = MMINOFF + sizeof(struct hdlc_header);
	mh->m_len = sizeof(struct pppipcp_header);
	ih = mtod(mh, struct pppipcp_header *);
	ih->ipcph_code = code;
	ih->ipcph_id = id;

	/* Now add the options. Make sure that the MTU is not exceeded. */
	mh->m_next = opt;
	for (m = mh, len = 0; m; m = m->m_next)
		len += m->m_len;
	if (len > pp->pp_if.if_mtu) {
		m_freem(mh);
		return(EMSGSIZE);
	}
	ih->ipcph_len = htons(len);
	return ((*pp->pp_hw->phw_output)(pp, mh, PPPPROTO_IPCP));
}

pppipcp_send_termreq(pp, ipcp)
	register struct ppp_softc *pp;
	register struct pppipcp_softc *ipcp;
{
	register struct mbuf *m;
	register struct pppipcp_header *ih;

	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: sending IPCP Terminate-Req\n",
			pp->pp_if.if_unit);
	MGET(m, M_DONTWAIT, MT_DATA);
	if (m == 0) {
		ipcp->ipcp_timer = pp->pp_restimer;
		pp->pp_if.if_timer = 1;
		return;
	}
	/*
	 * Leave room for an HDLC header as the phy output routine will almost
	 * certainly want to add one.
	 */
	m->m_off = MMINOFF + sizeof(struct hdlc_header);
	m->m_len = sizeof(struct pppipcp_header);
	ih = mtod(m, struct pppipcp_header *);
	ih->ipcph_code = PPPIPCP_TERMREQ;
	ih->ipcph_id = ++pppipcp_packet_id;
	ih->ipcph_len = htons(sizeof(struct pppipcp_header));
	(*pp->pp_hw->phw_output)(pp, m, PPPPROTO_IPCP);
	ipcp->ipcp_restcnt--;
	ipcp->ipcp_timer = pp->pp_restimer;
	pp->pp_if.if_timer = 1;
}

/*
 * A Terminate-Ack is always sent in response to some received packet. We want
 * the original packet so that we can extract the ID field from it, which we
 * must match on response. Since we are to dispose of the original packet, we
 * use the opportunity to reuse its first mbuf for our response.
 */
pppipcp_send_termack(pp, ipcp, op)
	register struct ppp_softc *pp;
	register struct pppipcp_softc *ipcp;
	struct mbuf *op;
{
	register struct mbuf *m, *n;
	register struct pppipcp_header *ih;
	u_char id;

	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: sending IPCP Terminate-Ack\n",
			pp->pp_if.if_unit);
	/* Dispose of the original packet */
	ih = mtod(op, struct pppipcp_header *);
	id = ih->ipcph_id;
	m = op;
	if (m->m_next) {
		m_freem(m->m_next);
		m->m_next = 0;
	}
	if (M_HASCL(m)) {
		n = MTOCL(m);
		MCLFREE(n);
	}
	/* Generate the Terminate-Ack */
	m->m_off = MMINOFF + sizeof(struct hdlc_header);
	m->m_len = sizeof(struct pppipcp_header);
	ih = mtod(m, struct pppipcp_header *);
	ih->ipcph_code = PPPIPCP_TERMACK;
	ih->ipcph_id = id;
	ih->ipcph_len = htons(sizeof(struct pppipcp_header));
	(*pp->pp_hw->phw_output)(pp, m, PPPPROTO_IPCP);
}

/* Send a Code-Reject in response to an offending packet and dispose of it */
pppipcp_send_coderej(pp, ipcp, op)
	register struct ppp_softc *pp;
	register struct pppipcp_softc *ipcp;
	struct mbuf *op;
{
	register struct mbuf *m, *mh;
	register struct pppipcp_header *ih;
	register int len;

	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: sending IPCP Code-Reject\n",
			pp->pp_if.if_unit);
	/* Construct the header for the Code-Reject we want to send */
	MGET(mh, M_DONTWAIT, MT_HEADER);
	if (mh == 0) {
		m_freem(op);
		return;
	}
	/*
	 * Leave room for an HDLC header as the phy output routine will almost
	 * certainly want to add one.
	 */
	mh->m_off = MMINOFF + sizeof(struct hdlc_header);
	mh->m_len = sizeof(struct pppipcp_header);
	ih = mtod(mh, struct pppipcp_header *);
	ih->ipcph_code = PPPIPCP_CODEREJ;
	ih->ipcph_id = ++pppipcp_packet_id;
	/* Now add the offending packet to the response, trimming it to MTU */
	mh->m_next = op;
	for (m = mh, len = 0; m; m = m->m_next) {
		if (len + m->m_len > pp->pp_if.if_mtu)
			m->m_len = pp->pp_if.if_mtu - len;
		len += m->m_len;
		if (m->m_next && len == pp->pp_if.if_mtu) {
			m_freem(m->m_next);
			m->m_next = 0;
		}
	}
	ih->ipcph_len = htons(len);
	(*pp->pp_hw->phw_output)(pp, mh, PPPPROTO_IPCP);
}

/*
 * Process received IPCP packets.
 * Runs at pppctl software interrupt time (at splnet).
 */
pppipcp_inprocess()
{
	register struct ppp_softc *pp;
	register struct mbuf *m, *n;
	register struct pppipcp_header *ih;
	register int len, indlen;
	struct pppipcp_softc *ipcp;
	int s;

next:	s = splimp();
	IF_DEQUEUE(&pppipcpinq, m);
	splx(s);
	if (m == 0)
		return;
	pp = *(mtod(m, struct ppp_softc **));
	IF_ADJ(m);
	pp->pp_busy = 1;
	if (!(pp->pp_flags & PPP_FLAGS_UP)) {
		m_freem(m);
		goto free;
	}

	/* Process this packet */
	if (m->m_len < sizeof(struct pppipcp_header) &&
	    (m = m_pullup(m, sizeof(struct pppipcp_header))) == 0)
		goto free;
	ih = mtod(m, struct pppipcp_header *);
	/* Validate the indicated length and trim any padding */
	indlen = ntohs(ih->ipcph_len);
	if (indlen < sizeof(struct pppipcp_header)) {
		m_freem(m);
		goto free;
	}
	for (n = m, len = 0; n; n = n->m_next) {
		if (len + n->m_len > indlen)
			n->m_len = indlen - len;
		len += n->m_len;
		if (n->m_next && len == indlen) {
			m_freem(n->m_next);
			n->m_next = 0;
		}
	}
	if (len < indlen) {
		m_freem(m);
		goto free;
	}

	/* Dispatch by type. All handling routines dispose of the packet. */
	ipcp = &pppipcp_softc[pp->pp_if.if_unit];
	switch (ih->ipcph_code) {
	case PPPIPCP_CONFREQ:
		pppipcp_handle_confreq(pp, ipcp, m);
		break;
	case PPPIPCP_CONFACK:
		pppipcp_handle_confack(pp, ipcp, m);
		break;
	case PPPIPCP_CONFNAK:
		pppipcp_handle_confnak(pp, ipcp, m);
		break;
	case PPPIPCP_CONFREJ:
		pppipcp_handle_confrej(pp, ipcp, m);
		break;
	case PPPIPCP_TERMREQ:
		pppipcp_handle_termreq(pp, ipcp, m);
		break;
	case PPPIPCP_TERMACK:
		pppipcp_handle_termack(pp, ipcp, m);
		break;
	case PPPIPCP_CODEREJ:
		pppipcp_handle_coderej(pp, ipcp, m);
		break;
	default:
		pppipcp_send_coderej(pp, ipcp, m);
	}
free:	pp->pp_busy = 0;
	goto next;
}

/*
 * Routines to handle different kinds of received IPCP packets.
 * Each routine is responsible for disposing of the packet.
 */
pppipcp_handle_confreq(pp, ipcp, m)
	register struct ppp_softc *pp;
	register struct pppipcp_softc *ipcp;
	register struct mbuf *m;
{
	struct in_ifaddr *ia = ipcp->ipcp_ia;
	u_char id;
	register int opt, optlen;
	struct mbuf *ack = 0, *ackt = 0, **ackp = &ackt;
	struct mbuf *nak = 0, *nakt = 0, **nakp = &nakt;
	struct mbuf *rej = 0, *rejt = 0, **rejp = &rejt;
	register char *cp;
	struct sockaddr_in locaddr, dstaddr;
	int seenipaddrs = 0;

	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: got IPCP Configure-Req\n",
			pp->pp_if.if_unit);
	/* See what to do with such packets in general in the current state */
	switch (ipcp->ipcp_state) {
	case PPPIPCP_STATE_INITIAL:
		/* If we have no ia, this is like CLOSED */
		if (ia) {
			pppipcp_init_negot(ipcp);
			break;
		} else {
			pppipcp_send_termack(pp, ipcp, m);
			return;
		}
	case PPPIPCP_STATE_STOPPED:
		pppipcp_init_negot(ipcp);
		break;
	case PPPIPCP_STATE_STOPPING:
		m_freem(m);
		return;
	case PPPIPCP_STATE_REQSENT:
	case PPPIPCP_STATE_ACKRCVD:
	case PPPIPCP_STATE_ACKSENT:
		break;
	case PPPIPCP_STATE_OPENED:
		pppipcp_init_negot(ipcp);
		break;
	case PPPIPCP_STATE_PAUSED:
		break;
	}

	/* OK, we are interested in this packet. Parse it. */
	id = (mtod(m, struct pppipcp_header *))->ipcph_id;
	m->m_off += sizeof(struct pppipcp_header);
	m->m_len -= sizeof(struct pppipcp_header);
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: parsing IPCP Configure-Req ID %x\n",
			pp->pp_if.if_unit, (u_long) id);

	/* Parse the options. We'll need some macros. */
#define	OPT_bogon	{ \
		m_freem(m); \
		m_freem(ackt); \
		m_freem(nakt); \
		m_freem(rejt); \
		if (pp->pp_if.if_flags & IFF_DEBUG) \
			log(LOG_DEBUG, "ppp%d: IPCP Configure-Req bogus\n", \
				pp->pp_if.if_unit); \
		pppipcp_handle_confreq_bad(pp, ipcp); \
		return; \
	}
#define	OPT_runt	{ \
		m_freem(ackt); \
		m_freem(nakt); \
		m_freem(rejt); \
		if (pp->pp_if.if_flags & IFF_DEBUG) \
			log(LOG_DEBUG, "ppp%d: IPCP Configure-Req runt\n", \
				pp->pp_if.if_unit); \
		pppipcp_handle_confreq_bad(pp, ipcp); \
		return; \
	}
#define	OPT_nobufs	{ \
		m_freem(m); \
		m_freem(ackt); \
		m_freem(nakt); \
		m_freem(rejt); \
		pppipcp_handle_confreq_bad(pp, ipcp); \
		return; \
	}
#define	OPT_input(len)	{ \
		if (m->m_len < len && (m = m_pullup(m, len)) == 0) { \
			m_freem(ackt); \
			m_freem(nakt); \
			m_freem(rejt); \
			pppipcp_handle_confreq_bad(pp, ipcp); \
			return; \
		} \
	}
#define	OPT_skip	{ \
		while (optlen) { \
			int t; \
			while (m && m->m_len == 0) \
				m = m_free(m); \
			if (m == 0) \
				OPT_runt \
			t = MIN(optlen, m->m_len); \
			m->m_off += t; \
			m->m_len -= t; \
			optlen -= t; \
		} \
	}
#define	OPT_output(r,len)	{ \
		if (r && (MLEN - r->m_len) < len) { \
			r/**/p = &r->m_next; \
			r = 0; \
		} \
		if (r == 0) { \
			MGET(r, M_DONTWAIT, MT_DATA); \
			if (r == 0) \
				OPT_nobufs \
			*r/**/p = r; \
			r->m_len = 0; \
		} \
		cp = mtod(r, char *) + r->m_len; \
		r->m_len += len; \
	}
#define	OPT_copy(r)	{ \
		while (optlen) { \
			int t, s; \
			while (m && m->m_len == 0) \
				m = m_free(m); \
			if (m == 0) \
				OPT_runt \
			if (r && r->m_len == MLEN) { \
				r/**/p = &r->m_next; \
				r = 0; \
			} \
			if (r == 0) { \
				MGET(r, M_DONTWAIT, MT_DATA); \
				if (r == 0) \
					OPT_nobufs \
				*r/**/p = r; \
				r->m_len = 0; \
			} \
			t = MIN(optlen, m->m_len); \
			s = MIN(t, MLEN - r->m_len); \
			bcopy(mtod(m, char *), mtod(r, char *) + r->m_len, s); \
			m->m_off += s; \
			m->m_len -= s; \
			r->m_len += s; \
			optlen -= s; \
		} \
	}

	for (;;) {

		while (m && m->m_len == 0)
			m = m_free(m);
		if (m == 0)
			break;
		opt = *(mtod(m, u_char *));
		m->m_off++;
		m->m_len--;
		while (m && m->m_len == 0)
			m = m_free(m);
		if (m == 0)
			OPT_runt
		optlen = *(mtod(m, u_char *));
		m->m_off++;
		m->m_len--;
		if (optlen < 2)
			OPT_bogon
		optlen -= 2;

		/* Handle known options */
		switch (opt) {
		case IPCPOPT_IPADDRS:
			seenipaddrs++;
			if (optlen != 8) {
			    if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG,
				    "ppp%d: IPCP option IP-Addresses (bogus)\n",
				    pp->pp_if.if_unit);
			    OPT_skip
			    OPT_output(nak, 10)
			    *cp++ = IPCPOPT_IPADDRS;
			    *cp++ = 10;
			    *(struct in_addr *) cp =
			      ((struct sockaddr_in *)&ia->ia_dstaddr)->sin_addr;
			    cp += sizeof(struct in_addr);
			    *(struct in_addr *) cp =
			      ((struct sockaddr_in *)&ia->ia_addr)->sin_addr;
			    cp += sizeof(struct in_addr);
			    continue;
			}
			OPT_input(8)
			bzero(&dstaddr, sizeof(dstaddr));
			dstaddr.sin_family = AF_INET;
			dstaddr.sin_addr = *mtod(m, struct in_addr *);
			m->m_off += 4;
			bzero(&locaddr, sizeof(locaddr));
			locaddr.sin_family = AF_INET;
			locaddr.sin_addr = *mtod(m, struct in_addr *);
			m->m_off += 4;
			m->m_len -= 8;
			if (pp->pp_if.if_flags & IFF_DEBUG)
			    log(LOG_DEBUG,
			      "ppp%d: IPCP option IP-Addresses 0x%x -> 0x%x\n",
			      pp->pp_if.if_unit, ntohl(locaddr.sin_addr.s_addr),
			      ntohl(dstaddr.sin_addr.s_addr));
			if (dstaddr.sin_addr.s_addr &&
			    !((struct sockaddr_in*)&ia->ia_dstaddr)
			    ->sin_addr.s_addr && !(ia->ia_flags & IFA_ROUTE))
			      *((struct sockaddr_in*)&ia->ia_dstaddr) = dstaddr;
			if (dstaddr.sin_addr.s_addr !=
			    ((struct sockaddr_in*)&ia->ia_dstaddr)
			    ->sin_addr.s_addr) {
				OPT_output(nak, 10)
				*cp++ = IPCPOPT_IPADDRS;
				*cp++ = 10;
				*(struct in_addr *) cp =
					((struct sockaddr_in *)&ia->ia_dstaddr)
						->sin_addr;
				cp += sizeof(struct in_addr);
				*(struct in_addr *) cp =
					((struct sockaddr_in *)&ia->ia_addr)
						->sin_addr;
				cp += sizeof(struct in_addr);
				continue;
			}
			if (locaddr.sin_addr.s_addr &&
			    !((struct sockaddr_in*)&ia->ia_addr)
			    ->sin_addr.s_addr && !(ia->ia_flags & IFA_ROUTE))
				in_ifinit(&pp->pp_if, ia, &locaddr);
			if (locaddr.sin_addr.s_addr !=
			    ((struct sockaddr_in*)&ia->ia_addr)
			    ->sin_addr.s_addr) {
				OPT_output(nak, 10)
				*cp++ = IPCPOPT_IPADDRS;
				*cp++ = 10;
				*(struct in_addr *) cp =
					((struct sockaddr_in *)&ia->ia_dstaddr)
						->sin_addr;
				cp += sizeof(struct in_addr);
				*(struct in_addr *) cp =
					((struct sockaddr_in *)&ia->ia_addr)
						->sin_addr;
				cp += sizeof(struct in_addr);
				continue;
			}
			if (!locaddr.sin_addr.s_addr ||
			    !dstaddr.sin_addr.s_addr) {
				/* Neither end knows the IP addresses, stop */
				m_freem(m);
				m_freem(ackt);
				m_freem(nakt);
				m_freem(rejt);
				pppipcp_handle_ipdraw(pp, ipcp);
				return;
			}
			/* It's good! */
			if (ipcp->ipcp_negstate &
			    (IPCPNEGOT_SENDIPADDRS | IPCPNEGOT_SENDIPADDR))
				ipcp->ipcp_negstate &= ~(IPCPNEGOT_SENDIPADDRS |
					IPCPNEGOT_SENDIPADDR | IPCPNEGOT_DRAW);
			ipcp->ipcp_negstate &=
				~(IPCPNEGOT_NEEDIPADDRS | IPCPNEGOT_NEEDIPADDR);
			OPT_output(ack, 10)
			*cp++ = IPCPOPT_IPADDRS;
			*cp++ = 10;
			*(struct in_addr *) cp = dstaddr.sin_addr;
			cp += sizeof(struct in_addr);
			*(struct in_addr *) cp = locaddr.sin_addr;
			cp += sizeof(struct in_addr);
			continue;

		case IPCPOPT_IPADDR:
			seenipaddrs++;
			if (optlen != 4) {
			    if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG,
				    "ppp%d: IPCP option IP-Address (bogus)\n",
				    pp->pp_if.if_unit);
			    OPT_skip
			    OPT_output(nak, 6)
			    *cp++ = IPCPOPT_IPADDR;
			    *cp++ = 6;
			    *(struct in_addr *) cp =
			      ((struct sockaddr_in *)&ia->ia_dstaddr)->sin_addr;
			    cp += sizeof(struct in_addr);
			    continue;
			}
			OPT_input(4)
			bzero(&dstaddr, sizeof(dstaddr));
			dstaddr.sin_family = AF_INET;
			dstaddr.sin_addr = *mtod(m, struct in_addr *);
			m->m_off += 4;
			m->m_len -= 4;
			if (pp->pp_if.if_flags & IFF_DEBUG)
			    log(LOG_DEBUG,
				"ppp%d: IPCP option IP-Address 0x%x\n",
				pp->pp_if.if_unit,
				ntohl(dstaddr.sin_addr.s_addr));
			if (dstaddr.sin_addr.s_addr &&
			    !((struct sockaddr_in*)&ia->ia_dstaddr)
			    ->sin_addr.s_addr && !(ia->ia_flags & IFA_ROUTE))
			      *((struct sockaddr_in*)&ia->ia_dstaddr) = dstaddr;
			if (dstaddr.sin_addr.s_addr !=
			    ((struct sockaddr_in*)&ia->ia_dstaddr)
			    ->sin_addr.s_addr) {
				OPT_output(nak, 6)
				*cp++ = IPCPOPT_IPADDR;
				*cp++ = 6;
				*(struct in_addr *) cp =
					((struct sockaddr_in *)&ia->ia_dstaddr)
						->sin_addr;
				cp += sizeof(struct in_addr);
				continue;
			}
			if (!dstaddr.sin_addr.s_addr) {
				/* Neither end knows the IP address, stop */
				m_freem(m);
				m_freem(ackt);
				m_freem(nakt);
				m_freem(rejt);
				pppipcp_handle_ipdraw(pp, ipcp);
				return;
			}
			/* It's good! */
			ipcp->ipcp_negstate &=
				~(IPCPNEGOT_NEEDIPADDRS | IPCPNEGOT_NEEDIPADDR);
			if (ipcp->ipcp_negstate & IPCPNEGOT_SENDIPADDRS)
				ipcp->ipcp_negstate &=
				    ~(IPCPNEGOT_SENDIPADDRS | IPCPNEGOT_DRAW);
			if (!((struct sockaddr_in*)&ia->ia_addr)
			    ->sin_addr.s_addr &&
			    !(ipcp->ipcp_negstate & IPCPNEGOT_SENDIPADDR)) {
				ipcp->ipcp_negstate |= IPCPNEGOT_SENDIPADDR;
				ipcp->ipcp_negstate &= ~IPCPNEGOT_DRAW;
			}
			OPT_output(ack, 6)
			*cp++ = IPCPOPT_IPADDR;
			*cp++ = 6;
			*(struct in_addr *) cp = dstaddr.sin_addr;
			cp += sizeof(struct in_addr);
			continue;

		default:
			if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG,
				    "ppp%d: IPCP unknown option %x length %d\n",
				    pp->pp_if.if_unit, opt, optlen);
			OPT_output(rej, 2)
			*cp++ = opt;
			*cp++ = optlen;
			OPT_copy(rej)
		}
	}

	/* Append a NAK of IP-Addresses or IP-Address if necessary */
	if (ipcp->ipcp_negstate & IPCPNEGOT_NEEDIPADDRS && !seenipaddrs) {
		OPT_output(nak, 10)
		*cp++ = IPCPOPT_IPADDRS;
		*cp++ = 10;
		*(struct in_addr *) cp =
			((struct sockaddr_in *)&ia->ia_dstaddr)->sin_addr;
		cp += sizeof(struct in_addr);
		*(struct in_addr *) cp =
			((struct sockaddr_in *)&ia->ia_addr)->sin_addr;
		cp += sizeof(struct in_addr);
	}
	if (ipcp->ipcp_negstate & IPCPNEGOT_NEEDIPADDR && !seenipaddrs) {
		OPT_output(nak, 6)
		*cp++ = IPCPOPT_IPADDR;
		*cp++ = 6;
		*(struct in_addr *) cp =
			((struct sockaddr_in *)&ia->ia_dstaddr)->sin_addr;
		cp += sizeof(struct in_addr);
	}

#undef	OPT_bogon
#undef	OPT_runt
#undef	OPT_nobufs
#undef	OPT_input
#undef	OPT_skip
#undef	OPT_output
#undef	OPT_copy

	/* Outcome */
	if (rejt == 0 && nakt == 0) {		/* Good */
		if (pp->pp_if.if_flags & IFF_DEBUG)
			log(LOG_DEBUG, "ppp%d: sending IPCP Configure-Ack\n",
				pp->pp_if.if_unit);
		if (!pppipcp_send_confresp(pp, ipcp, PPPIPCP_CONFACK, id, ackt))
			pppipcp_handle_confreq_good(pp, ipcp);
		else
			pppipcp_handle_confreq_bad(pp, ipcp);
	} else {				/* Bad */
		m_freem(ackt);
		if (rejt) {
			if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG,
				    "ppp%d: sending IPCP Configure-Reject\n",
				    pp->pp_if.if_unit);
			pppipcp_send_confresp(pp, ipcp, PPPIPCP_CONFREJ, id,
						rejt);
		}
		if (nakt) {
			if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG,
					"ppp%d: sending IPCP Configure-Nak\n",
					pp->pp_if.if_unit);
			pppipcp_send_confresp(pp, ipcp, PPPIPCP_CONFNAK, id,
						nakt);
		}
		pppipcp_handle_confreq_bad(pp, ipcp);
	}
}

/* The following two routines handle RFC 1661 RCR+ and RCR- events */
pppipcp_handle_confreq_good(pp, ipcp)
	register struct ppp_softc *pp;
	register struct pppipcp_softc *ipcp;
{
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: IPCP Configure-Req good\n",
			pp->pp_if.if_unit);
	switch (ipcp->ipcp_state) {
	case PPPIPCP_STATE_INITIAL:
	case PPPIPCP_STATE_STOPPED:
	case PPPIPCP_STATE_OPENED:
	case PPPIPCP_STATE_PAUSED:
		pppipcp_send_confreq(pp, ipcp);
	case PPPIPCP_STATE_REQSENT:
		pppipcp_statechg(ipcp, PPPIPCP_STATE_ACKSENT);
		break;
	case PPPIPCP_STATE_ACKRCVD:
		pppipcp_statechg(ipcp, PPPIPCP_STATE_OPENED);
		break;
	}
}

pppipcp_handle_confreq_bad(pp, ipcp)
	register struct ppp_softc *pp;
	register struct pppipcp_softc *ipcp;
{
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: IPCP Configure-Req bad\n",
			pp->pp_if.if_unit);
	switch (ipcp->ipcp_state) {
	case PPPIPCP_STATE_INITIAL:
	case PPPIPCP_STATE_STOPPED:
	case PPPIPCP_STATE_OPENED:
		pppipcp_send_confreq(pp, ipcp);
	case PPPIPCP_STATE_ACKSENT:
		pppipcp_statechg(ipcp, PPPIPCP_STATE_REQSENT);
	}
}

pppipcp_handle_confack(pp, ipcp, m)
	register struct ppp_softc *pp;
	register struct pppipcp_softc *ipcp;
	struct mbuf *m;
{
	register struct in_ifaddr *ia = ipcp->ipcp_ia;

	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: got IPCP Configure-Ack\n",
			pp->pp_if.if_unit);
	switch (ipcp->ipcp_state) {
	case PPPIPCP_STATE_INITIAL:
		/* If we have no ia, this is like CLOSED */
		if (ia)
			m_freem(m);
		else
			pppipcp_send_termack(pp, ipcp, m);
		return;
	case PPPIPCP_STATE_STOPPED:
		pppipcp_send_termack(pp, ipcp, m);
		return;
	case PPPIPCP_STATE_REQSENT:
		if (mtod(m, struct pppipcp_header *)->ipcph_id ==
		    ipcp->ipcp_lastreqid && pppipcp_check_ipdraw(pp, ipcp)) {
			ipcp->ipcp_timer = pp->pp_restimer;
			pp->pp_if.if_timer = 1;
			pppipcp_statechg(ipcp, PPPIPCP_STATE_ACKRCVD);
		}
		m_freem(m);
		return;
	case PPPIPCP_STATE_ACKSENT:
		if (mtod(m, struct pppipcp_header *)->ipcph_id ==
		    ipcp->ipcp_lastreqid && pppipcp_check_ipdraw(pp, ipcp))
			pppipcp_statechg(ipcp, PPPIPCP_STATE_OPENED);
		m_freem(m);
		return;
	default:
		m_freem(m);
		return;
	}
}

/*
 * If we got a Configure-Ack, check for an IP draw (peer acked our zeros
 * instead of providing us with IP addresses).
 */
pppipcp_check_ipdraw(pp, ipcp)
	register struct ppp_softc *pp;
	register struct pppipcp_softc *ipcp;
{
	register struct in_ifaddr *ia = ipcp->ipcp_ia;

	/* At this point both addresses in the ia must be set. */
	if (((struct sockaddr_in*)&ia->ia_addr)->sin_addr.s_addr &&
	    ((struct sockaddr_in*)&ia->ia_dstaddr)->sin_addr.s_addr)
		return(1);
	else {
		pppipcp_handle_ipdraw(pp, ipcp);
		return(0);
	}
}

pppipcp_handle_confnak(pp, ipcp, m)
	register struct ppp_softc *pp;
	register struct pppipcp_softc *ipcp;
	register struct mbuf *m;
{
	struct in_ifaddr *ia = ipcp->ipcp_ia;
	register int opt, optlen, chg = 0;
	struct sockaddr_in locaddr, dstaddr;

	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: got IPCP Configure-Nak\n",
			pp->pp_if.if_unit);
	switch (ipcp->ipcp_state) {
	case PPPIPCP_STATE_INITIAL:
	case PPPIPCP_STATE_STOPPED:
		pppipcp_send_termack(pp, ipcp, m);
		return;
	case PPPIPCP_STATE_REQSENT:
		if (mtod(m, struct pppipcp_header *)->ipcph_id ==
		    ipcp->ipcp_lastreqid)
			break;
		m_freem(m);
		return;
	case PPPIPCP_STATE_ACKRCVD:
		m_freem(m);
		pppipcp_send_confreq(pp, ipcp);
		pppipcp_statechg(ipcp, PPPIPCP_STATE_REQSENT);
		return;
	case PPPIPCP_STATE_ACKSENT:
		if (mtod(m, struct pppipcp_header *)->ipcph_id ==
		    ipcp->ipcp_lastreqid)
			break;
		m_freem(m);
		return;
	case PPPIPCP_STATE_OPENED:
		m_freem(m);
		pppipcp_init_negot(ipcp);
		pppipcp_send_confreq(pp, ipcp);
		pppipcp_statechg(ipcp, PPPIPCP_STATE_REQSENT);
		return;
	default:
		m_freem(m);
		return;
	}

	/* This is a negative response to our request. Process the options. */
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: parsing IPCP Configure-Nak\n",
			pp->pp_if.if_unit);
	m->m_off += sizeof(struct pppipcp_header);
	m->m_len -= sizeof(struct pppipcp_header);

#define	OPT_bogon	{ \
		m_freem(m); \
		if (pp->pp_if.if_flags & IFF_DEBUG) \
			log(LOG_DEBUG, "ppp%d: IPCP Configure-Nak bogus\n", \
				pp->pp_if.if_unit); \
		goto outcome; \
	}
#define	OPT_runt	{ \
		if (pp->pp_if.if_flags & IFF_DEBUG) \
			log(LOG_DEBUG, "ppp%d: IPCP Configure-Nak runt\n", \
				pp->pp_if.if_unit); \
		goto outcome; \
	}
#define	OPT_input(len)	{ \
		if (m->m_len < len && (m = m_pullup(m, len)) == 0) \
			goto outcome; \
	}
#define	OPT_skip	{ \
		while (optlen) { \
			int t; \
			while (m && m->m_len == 0) \
				m = m_free(m); \
			if (m == 0) \
				OPT_runt \
			t = MIN(optlen, m->m_len); \
			m->m_off += t; \
			m->m_len -= t; \
			optlen -= t; \
		} \
	}

	for (;;) {

		while (m && m->m_len == 0)
			m = m_free(m);
		if (m == 0)
			break;
		opt = *mtod(m, u_char *);
		m->m_off++;
		m->m_len--;
		while (m && m->m_len == 0)
			m = m_free(m);
		if (m == 0)
			OPT_runt
		optlen = *mtod(m, u_char *);
		m->m_off++;
		m->m_len--;
		if (optlen < 2)
			OPT_bogon
		optlen -= 2;

		/* Handle known options */
		switch (opt) {
		case IPCPOPT_IPADDRS:
			if (optlen != 8) {
			    if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG,
				    "ppp%d: IPCP option IP-Addresses (bogus)\n",
				    pp->pp_if.if_unit);
			    OPT_skip
			    continue;
			}
			OPT_input(8)
			bzero(&locaddr, sizeof(locaddr));
			locaddr.sin_family = AF_INET;
			locaddr.sin_addr = *mtod(m, struct in_addr *);
			m->m_off += 4;
			bzero(&dstaddr, sizeof(dstaddr));
			dstaddr.sin_family = AF_INET;
			dstaddr.sin_addr = *mtod(m, struct in_addr *);
			m->m_off += 4;
			m->m_len -= 8;
			if (pp->pp_if.if_flags & IFF_DEBUG)
			    log(LOG_DEBUG,
			      "ppp%d: IPCP option IP-Addresses 0x%x -> 0x%x\n",
			      pp->pp_if.if_unit, ntohl(locaddr.sin_addr.s_addr),
			      ntohl(dstaddr.sin_addr.s_addr));
			if (dstaddr.sin_addr.s_addr &&
			    !((struct sockaddr_in*)&ia->ia_dstaddr)
			    ->sin_addr.s_addr && !(ia->ia_flags & IFA_ROUTE)) {
			      *((struct sockaddr_in*)&ia->ia_dstaddr) = dstaddr;
			      chg++;
			}
			if (locaddr.sin_addr.s_addr &&
			    !((struct sockaddr_in*)&ia->ia_addr)
			    ->sin_addr.s_addr && !(ia->ia_flags & IFA_ROUTE)) {
				in_ifinit(&pp->pp_if, ia, &locaddr);
				chg++;
			}
			if (!((struct sockaddr_in*)&ia->ia_addr)
			    ->sin_addr.s_addr ||
			    !((struct sockaddr_in*)&ia->ia_dstaddr)
			    ->sin_addr.s_addr) {
				m_freem(m);
				pppipcp_handle_ipdraw(pp, ipcp);
				return;
			}
			ipcp->ipcp_negstate &=
				~(IPCPNEGOT_NEEDIPADDRS | IPCPNEGOT_NEEDIPADDR);
			if (!(ipcp->ipcp_negstate & IPCPNEGOT_SENDIPADDRS)) {
				ipcp->ipcp_negstate |= IPCPNEGOT_SENDIPADDRS;
				ipcp->ipcp_negstate &= ~IPCPNEGOT_SENDIPADDR;
				chg++;
			}
			continue;

		case IPCPOPT_IPADDR:
			if (optlen != 4) {
			    if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG,
				    "ppp%d: IPCP option IP-Address (bogus)\n",
				    pp->pp_if.if_unit);
			    OPT_skip
			    continue;
			}
			OPT_input(4)
			bzero(&locaddr, sizeof(locaddr));
			locaddr.sin_family = AF_INET;
			locaddr.sin_addr = *mtod(m, struct in_addr *);
			m->m_off += 4;
			m->m_len -= 4;
			if (pp->pp_if.if_flags & IFF_DEBUG)
			    log(LOG_DEBUG,
				"ppp%d: IPCP option IP-Address 0x%x\n",
				pp->pp_if.if_unit,
				ntohl(locaddr.sin_addr.s_addr));
			if (!((struct sockaddr_in*)&ia->ia_dstaddr)
			    ->sin_addr.s_addr) {
				ipcp->ipcp_negstate |= IPCPNEGOT_NEEDIPADDR;
				ipcp->ipcp_negstate &= ~IPCPNEGOT_NEEDIPADDRS;
				pppipcp_statechg(PPPIPCP_STATE_PAUSED);
				continue;
			}
			if (locaddr.sin_addr.s_addr &&
			    !((struct sockaddr_in*)&ia->ia_addr)
			    ->sin_addr.s_addr && !(ia->ia_flags & IFA_ROUTE)) {
				in_ifinit(&pp->pp_if, ia, &locaddr);
				chg++;
			}
			if (!((struct sockaddr_in*)&ia->ia_addr)
			    ->sin_addr.s_addr) {
				m_freem(m);
				pppipcp_handle_ipdraw(pp, ipcp);
				return;
			}
			ipcp->ipcp_negstate &=
				~(IPCPNEGOT_NEEDIPADDRS | IPCPNEGOT_NEEDIPADDR);
			if (!(ipcp->ipcp_negstate & IPCPNEGOT_SENDIPADDR)) {
				ipcp->ipcp_negstate |= IPCPNEGOT_SENDIPADDR;
				ipcp->ipcp_negstate &= ~IPCPNEGOT_SENDIPADDRS;
				chg++;
			}
			continue;

		default:
			if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG,
				    "ppp%d: IPCP unknown option %x length %d\n",
				    pp->pp_if.if_unit, opt, optlen);
			OPT_skip
		}
	}
#undef	OPT_bogon
#undef	OPT_runt
#undef	OPT_input
#undef	OPT_skip

outcome:
	pppipcp_handle_confnakrej_outcome(pp, ipcp, chg);
}

pppipcp_handle_confrej(pp, ipcp, m)
	register struct ppp_softc *pp;
	register struct pppipcp_softc *ipcp;
	register struct mbuf *m;
{
	struct in_ifaddr *ia = ipcp->ipcp_ia;
	register int opt, optlen, chg = 0;

	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: got IPCP Configure-Reject\n",
			pp->pp_if.if_unit);
	switch (ipcp->ipcp_state) {
	case PPPIPCP_STATE_INITIAL:
	case PPPIPCP_STATE_STOPPED:
		pppipcp_send_termack(pp, ipcp, m);
		return;
	case PPPIPCP_STATE_REQSENT:
		if (mtod(m, struct pppipcp_header *)->ipcph_id ==
		    ipcp->ipcp_lastreqid)
			break;
		m_freem(m);
		return;
	case PPPIPCP_STATE_ACKRCVD:
		m_freem(m);
		pppipcp_send_confreq(pp, ipcp);
		pppipcp_statechg(ipcp, PPPIPCP_STATE_REQSENT);
		return;
	case PPPIPCP_STATE_ACKSENT:
		if (mtod(m, struct pppipcp_header *)->ipcph_id ==
		    ipcp->ipcp_lastreqid)
			break;
		m_freem(m);
		return;
	case PPPIPCP_STATE_OPENED:
		m_freem(m);
		pppipcp_init_negot(ipcp);
		pppipcp_send_confreq(pp, ipcp);
		pppipcp_statechg(ipcp, PPPIPCP_STATE_REQSENT);
		return;
	default:
		m_freem(m);
		return;
	}

	/* This is a negative response to our request. Process the options. */
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: parsing IPCP Configure-Reject\n",
			pp->pp_if.if_unit);
	m->m_off += sizeof(struct pppipcp_header);
	m->m_len -= sizeof(struct pppipcp_header);

#define	OPT_bogon	{ \
		m_freem(m); \
		if (pp->pp_if.if_flags & IFF_DEBUG) \
			log(LOG_DEBUG, "ppp%d: IPCP Configure-Reject bogus\n", \
				pp->pp_if.if_unit); \
		goto outcome; \
	}
#define	OPT_runt	{ \
		if (pp->pp_if.if_flags & IFF_DEBUG) \
			log(LOG_DEBUG, "ppp%d: IPCP Configure-Reject runt\n", \
				pp->pp_if.if_unit); \
		goto outcome; \
	}
#define	OPT_skip	{ \
		while (optlen) { \
			int t; \
			while (m && m->m_len == 0) \
				m = m_free(m); \
			if (m == 0) \
				OPT_runt \
			t = MIN(optlen, m->m_len); \
			m->m_off += t; \
			m->m_len -= t; \
			optlen -= t; \
		} \
	}

	for (;;) {

		while (m && m->m_len == 0)
			m = m_free(m);
		if (m == 0)
			break;
		opt = *mtod(m, u_char *);
		m->m_off++;
		m->m_len--;
		while (m && m->m_len == 0)
			m = m_free(m);
		if (m == 0)
			OPT_runt
		optlen = *mtod(m, u_char *);
		m->m_off++;
		m->m_len--;
		if (optlen < 2)
			OPT_bogon
		optlen -= 2;

		/* Handle known options */
		switch (opt) {
		case IPCPOPT_IPADDRS:
			if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG,
					"ppp%d: IPCP option IP-Addresses\n",
					pp->pp_if.if_unit);
			OPT_skip
			if (ipcp->ipcp_negstate & IPCPNEGOT_SENDIPADDRS) {
				ipcp->ipcp_negstate &= ~IPCPNEGOT_SENDIPADDRS;
				chg++;
			}
			ipcp->ipcp_negstate &= ~IPCPNEGOT_NEEDIPADDRS;
			if (!((struct sockaddr_in*)&ia->ia_dstaddr)
			    ->sin_addr.s_addr) {
				ipcp->ipcp_negstate |= IPCPNEGOT_NEEDIPADDR;
				pppipcp_statechg(PPPIPCP_STATE_PAUSED);
				continue;
			}
			if (!((struct sockaddr_in*)&ia->ia_addr)
			    ->sin_addr.s_addr) {
				m_freem(m);
				pppipcp_handle_ipdraw(pp, ipcp);
				return;
			}
			continue;

		case IPCPOPT_IPADDR:
			if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG,
					"ppp%d: IPCP option IP-Address\n",
					pp->pp_if.if_unit);
			OPT_skip
			if (ipcp->ipcp_negstate & IPCPNEGOT_SENDIPADDR) {
				ipcp->ipcp_negstate &= ~IPCPNEGOT_SENDIPADDR;
				chg++;
			}
			if (!((struct sockaddr_in*)&ia->ia_addr)
			    ->sin_addr.s_addr) {
				m_freem(m);
				pppipcp_handle_ipdraw(pp, ipcp);
				return;
			}
			continue;

		default:
			if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG,
					"ppp%d: IPCP unknown option %x\n",
					pp->pp_if.if_unit, opt);
			OPT_skip
		}
	}
#undef	OPT_bogon
#undef	OPT_runt
#undef	OPT_skip

outcome:
	pppipcp_handle_confnakrej_outcome(pp, ipcp, chg);
}

pppipcp_handle_confnakrej_outcome(pp, ipcp, chg)
	register struct ppp_softc *pp;
	register struct pppipcp_softc *ipcp;
	int chg;
{
	if (ipcp->ipcp_state == PPPIPCP_STATE_PAUSED) {
		ipcp->ipcp_negstate &= ~IPCPNEGOT_DRAW;
		return;
	}
	if (chg) {
		if (pp->pp_if.if_flags & IFF_DEBUG)
			log(LOG_DEBUG, "ppp%d: IPCP options adjusted\n",
				pp->pp_if.if_unit);
		ipcp->ipcp_negstate &= ~IPCPNEGOT_DRAW;
	} else if (ipcp->ipcp_negstate & IPCPNEGOT_DRAW) {
		if (pp->pp_if.if_flags & IFF_DEBUG)
			log(LOG_DEBUG,
				"ppp%d: no agreement, stopping\n",
				pp->pp_if.if_unit);
		ipcp->ipcp_restcnt = pp->pp_maxterm;
		pppipcp_send_termreq(pp, ipcp);
		pppipcp_statechg(ipcp, PPPIPCP_STATE_STOPPING);
		return;
	} else {
		if (pp->pp_if.if_flags & IFF_DEBUG)
			log(LOG_DEBUG,
				"ppp%d: no agreement, give them one last try\n",
				pp->pp_if.if_unit);
		ipcp->ipcp_negstate |= IPCPNEGOT_DRAW;
	}
	pppipcp_send_confreq(pp, ipcp);
}

/* Neither end knows the IP addresses, stop */
pppipcp_handle_ipdraw(pp, ipcp)
	register struct ppp_softc *pp;
	register struct pppipcp_softc *ipcp;
{
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG,
			"ppp%d: neither end knows the IP addresses, stopping\n",
			pp->pp_if.if_unit);
	ipcp->ipcp_restcnt = pp->pp_maxterm;
	pppipcp_send_termreq(pp, ipcp);
	pppipcp_statechg(ipcp, PPPIPCP_STATE_STOPPING);
}

pppipcp_handle_termreq(pp, ipcp, m)
	register struct ppp_softc *pp;
	register struct pppipcp_softc *ipcp;
	struct mbuf *m;
{
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: got IPCP Terminate-Req\n",
			pp->pp_if.if_unit);
	switch (ipcp->ipcp_state) {
	case PPPIPCP_STATE_INITIAL:
	case PPPIPCP_STATE_STOPPED:
	case PPPIPCP_STATE_STOPPING:
		pppipcp_send_termack(pp, ipcp, m);
		return;
	case PPPIPCP_STATE_REQSENT:
	case PPPIPCP_STATE_ACKRCVD:
	case PPPIPCP_STATE_ACKSENT:
	case PPPIPCP_STATE_OPENED:
	case PPPIPCP_STATE_PAUSED:
		pppipcp_send_termack(pp, ipcp, m);
		ipcp->ipcp_restcnt = 0;
		ipcp->ipcp_timer = pp->pp_restimer;
		pp->pp_if.if_timer = 1;
		pppipcp_statechg(ipcp, PPPIPCP_STATE_STOPPING);
		return;
	default:
		m_freem(m);
		return;
	}
}

pppipcp_handle_termack(pp, ipcp, m)
	register struct ppp_softc *pp;
	register struct pppipcp_softc *ipcp;
	struct mbuf *m;
{
	m_freem(m);
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: got IPCP Terminate-Ack\n",
			pp->pp_if.if_unit);
	switch (ipcp->ipcp_state) {
	case PPPIPCP_STATE_STOPPING:
		pppipcp_statechg(ipcp, PPPIPCP_STATE_STOPPED);
		break;
	case PPPIPCP_STATE_ACKRCVD:
		pppipcp_send_confreq(pp, ipcp);
		pppipcp_statechg(ipcp, PPPIPCP_STATE_REQSENT);
		break;
	case PPPIPCP_STATE_OPENED:
	case PPPIPCP_STATE_PAUSED:
		pppipcp_init_negot(ipcp);
		pppipcp_send_confreq(pp, ipcp);
		pppipcp_statechg(ipcp, PPPIPCP_STATE_REQSENT);
		break;
	}
}

pppipcp_handle_coderej(pp, ipcp, m)
	register struct ppp_softc *pp;
	register struct pppipcp_softc *ipcp;
	register struct mbuf *m;
{
	register int code;

	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: got IPCP Code-Reject\n",
			pp->pp_if.if_unit);
	m->m_off += sizeof(struct pppipcp_header);
	m->m_len -= sizeof(struct pppipcp_header);
	while (m && m->m_len == 0)
		m = m_free(m);
	if (m == 0)
		return;
	code = *mtod(m, u_char *);
	m_freem(m);
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: IPCP code %x rejected by peer\n",
			pp->pp_if.if_unit, code);
	switch (code) {
	case PPPIPCP_CONFREQ:
	case PPPIPCP_CONFACK:
	case PPPIPCP_CONFNAK:
	case PPPIPCP_CONFREJ:
	case PPPIPCP_TERMREQ:
	case PPPIPCP_TERMACK:
		pppipcp_statechg(ipcp, PPPIPCP_STATE_STOPPED);
	}
}

pppipcp_timer(pp)
	register struct ppp_softc *pp;
{
	register struct pppipcp_softc *ipcp = &pppipcp_softc[pp->pp_if.if_unit];

	if (!ipcp->ipcp_timer)
		return;
	if (--ipcp->ipcp_timer) {
		pp->pp_if.if_timer = 1;
		return;
	}
	switch (ipcp->ipcp_state) {
	case PPPIPCP_STATE_STOPPING:
		if (ipcp->ipcp_restcnt)
			pppipcp_send_termreq(pp, ipcp);
		else
			pppipcp_statechg(ipcp, PPPIPCP_STATE_STOPPED);
		break;
	case PPPIPCP_STATE_REQSENT:
		pppipcp_send_confreq(pp, ipcp);
		break;
	case PPPIPCP_STATE_ACKRCVD:
		pppipcp_send_confreq(pp, ipcp);
		pppipcp_statechg(ipcp, PPPIPCP_STATE_REQSENT);
		break;
	case PPPIPCP_STATE_ACKSENT:
		pppipcp_send_confreq(pp, ipcp);
		break;
	}
}

pppipcp_handle_protrej(pp)
	struct ppp_softc *pp;
{
	pppipcp_statechg(&pppipcp_softc[pp->pp_if.if_unit],
				PPPIPCP_STATE_STOPPED);
}
#endif
