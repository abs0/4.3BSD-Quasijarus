h49880
s 00008/00007/01498
d D 7.8 2011/10/09 04:45:57 msokolov 8 7
c bug in Echo-Request handling would crash the kernel
e
s 00001/00001/01504
d D 7.7 08/04/06 17:18:07 msokolov 7 6
c typo in IFF_DEBUG output message
e
s 00061/00001/01444
d D 7.6 08/04/05 08:26:23 msokolov 6 5
c authentication hooks implemented
e
s 00013/00011/01432
d D 7.5 07/04/15 05:11:08 msokolov 5 4
c fixed race condition with Up/Down events
e
s 00009/00000/01434
d D 7.4 02/07/23 23:57:34 msokolov 4 3
c fix one memory leak and one logic oversight
e
s 00169/00017/01265
d D 7.3 02/07/21 12:37:44 msokolov 3 2
c minor buglets, better PERSIST handling, more diagnostic output
e
s 00129/00040/01153
d D 7.2 02/07/20 15:07:27 msokolov 2 1
c first working version (2 ppp's connected with null-modem reach OPENED)
c add diagnostic output
e
s 01193/00000/00000
d D 7.1 02/07/11 10:56:33 msokolov 1 0
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
 * PPP (RFC 1661) Line Control Protocol implementation
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
D 2
#include "malloc.h"
E 2
I 2
#include "syslog.h"
E 2

#include "if.h"
#include "netisr.h"
#include "route.h"
#include "if_hdlc.h"
#include "if_ppp.h"
#include "if_pppvar.h"

u_char ppplcp_packet_id;

/* Reset LCP negotiation state to initial */
ppplcp_init_negot(pp)
	register struct ppp_softc *pp;
{
I 2
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: starting LCP negotiation\n",
			pp->pp_if.if_unit);
E 2
	pp->pp_lcpnegot = LCPNEGOT_ASKACCM | LCPNEGOT_ASKMRU;
	if (pp->pp_hw->phw_caps & PPP_PHYCAPS_WANTRECVACCOMP)
		pp->pp_lcpnegot |= LCPNEGOT_ASKACCOMP;
	if (pp->pp_hw->phw_caps & PPP_PHYCAPS_WANTRECVPROTCOMP)
		pp->pp_lcpnegot |= LCPNEGOT_ASKPROTCOMP;
	pp->pp_agreedmru = pp->pp_desmru;
	pp->pp_laccm = 0;
I 6
	pp->pp_authpeer_index = 0;
E 6
}

/* Routines to send standard LCP packets */
ppplcp_send_confreq(pp)
	register struct ppp_softc *pp;
{
	register struct mbuf *m;
	register struct ppplcp_header *lh;
	register char *cp;

I 2
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: sending LCP Configure-Req\n",
			pp->pp_if.if_unit);
E 2
	MGET(m, M_DONTWAIT, MT_DATA);
	if (m == 0) {
		pp->pp_if.if_timer = pp->pp_restimer;
		return;
	}
	/*
	 * Leave room for an HDLC header as the phy output routine will almost
	 * certainly want to add one.
	 */
	m->m_off = MMINOFF + sizeof(struct hdlc_header);
	lh = mtod(m, struct ppplcp_header *);
	lh->lcp_code = PPPLCP_CONFREQ;
	lh->lcp_id = ++ppplcp_packet_id;
	cp = (char *) (lh + 1);

	/* Now add the options we want */
	if (pp->pp_lcpnegot & LCPNEGOT_ASKMRU) {
I 3
		if (pp->pp_if.if_flags & IFF_DEBUG)
			log(LOG_DEBUG, "ppp%d: requesting MRU %d\n",
				pp->pp_if.if_unit, pp->pp_agreedmru);
E 3
		*cp++ = LCPOPT_MRU;
D 2
		*cp++ = 2;
E 2
I 2
		*cp++ = 4;
E 2
		*(u_short *) cp = htons(pp->pp_agreedmru);
		cp += sizeof(u_short);
	}
	if (pp->pp_lcpnegot & LCPNEGOT_ASKACCM) {
I 3
		if (pp->pp_if.if_flags & IFF_DEBUG)
			log(LOG_DEBUG, "ppp%d: requesting ACCM %x\n",
				pp->pp_if.if_unit, pp->pp_laccm);
E 3
		*cp++ = LCPOPT_ACCM;
		*cp++ = 6;
		*(u_long *) cp = htonl(pp->pp_laccm);
		cp += sizeof(u_long);
	}
	if (pp->pp_lcpnegot & LCPNEGOT_ASKPROTCOMP) {
I 3
		if (pp->pp_if.if_flags & IFF_DEBUG)
			log(LOG_DEBUG, "ppp%d: requesting PFC\n",
				pp->pp_if.if_unit);
E 3
		*cp++ = LCPOPT_PROTCOMP;
		*cp++ = 2;
	}
	if (pp->pp_lcpnegot & LCPNEGOT_ASKACCOMP) {
I 3
		if (pp->pp_if.if_flags & IFF_DEBUG)
			log(LOG_DEBUG, "ppp%d: requesting ACFC\n",
				pp->pp_if.if_unit);
E 3
		*cp++ = LCPOPT_ACCOMP;
		*cp++ = 2;
	}

	/* Set the length and send it! */
	m->m_len = cp - (char *) lh;
	lh->lcp_len = htons(m->m_len);
	pp->pp_lastreqid = lh->lcp_id;
	(*pp->pp_hw->phw_output)(pp, m, PPPPROTO_LCP);
D 3
	pp->pp_restcnt--;
E 3
I 3
	if (!(pp->pp_flags & PPP_FLAGS_PERSIST))
		pp->pp_restcnt--;
E 3
	pp->pp_if.if_timer = pp->pp_restimer;
}

/* Send a configure response (Ack, Nak, or Reject) with options */
ppplcp_send_confresp(pp, code, id, opt)
	register struct ppp_softc *pp;
	int code;
	u_char id;
	struct mbuf *opt;
{
	register struct mbuf *m, *mh;
	register struct ppplcp_header *lh;
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
	mh->m_len = sizeof(struct ppplcp_header);
	lh = mtod(mh, struct ppplcp_header *);
	lh->lcp_code = code;
	lh->lcp_id = id;

	/* Now add the options. Make sure that the MTU is not exceeded. */
	mh->m_next = opt;
D 2
	for (m = mh, len = 0; m; m->m_next)
E 2
I 2
	for (m = mh, len = 0; m; m = m->m_next)
E 2
		len += m->m_len;
	if (len > PPP_DEFAULT_MTU) {
		m_freem(mh);
		return(EMSGSIZE);
	}
	lh->lcp_len = htons(len);
	return ((*pp->pp_hw->phw_output)(pp, mh, PPPPROTO_LCP));
}

ppplcp_send_termreq(pp)
	register struct ppp_softc *pp;
{
	register struct mbuf *m;
	register struct ppplcp_header *lh;

I 2
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: sending LCP Terminate-Req\n",
			pp->pp_if.if_unit);
E 2
	MGET(m, M_DONTWAIT, MT_DATA);
	if (m == 0) {
		pp->pp_if.if_timer = pp->pp_restimer;
		return;
	}
	/*
	 * Leave room for an HDLC header as the phy output routine will almost
	 * certainly want to add one.
	 */
	m->m_off = MMINOFF + sizeof(struct hdlc_header);
	m->m_len = sizeof(struct ppplcp_header);
	lh = mtod(m, struct ppplcp_header *);
	lh->lcp_code = PPPLCP_TERMREQ;
	lh->lcp_id = ++ppplcp_packet_id;
	lh->lcp_len = htons(sizeof(struct ppplcp_header));
	(*pp->pp_hw->phw_output)(pp, m, PPPPROTO_LCP);
	pp->pp_restcnt--;
	pp->pp_if.if_timer = pp->pp_restimer;
}

/*
 * A Terminate-Ack is always sent in response to some received packet. We want
 * the original packet so that we can extract the ID field from it, which we
 * must match on response. Since we are to dispose of the original packet, we
 * use the opportunity to reuse its first mbuf for our response.
 */
ppplcp_send_termack(pp, op)
	register struct ppp_softc *pp;
	struct mbuf *op;
{
	register struct mbuf *m, *n;
	register struct ppplcp_header *lh;
	u_char id;

I 2
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: sending LCP Terminate-Ack\n",
			pp->pp_if.if_unit);
E 2
	/* Dispose of the original packet */
	lh = mtod(op, struct ppplcp_header *);
	id = lh->lcp_id;
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
	m->m_len = sizeof(struct ppplcp_header);
	lh = mtod(m, struct ppplcp_header *);
	lh->lcp_code = PPPLCP_TERMACK;
	lh->lcp_id = id;
	lh->lcp_len = htons(sizeof(struct ppplcp_header));
	(*pp->pp_hw->phw_output)(pp, m, PPPPROTO_LCP);
}

/* Send a Code-Reject in response to an offending packet and dispose of it */
ppplcp_send_coderej(pp, op)
	register struct ppp_softc *pp;
	struct mbuf *op;
{
	register struct mbuf *m, *mh;
	register struct ppplcp_header *lh;
	register int len, mtu;

I 2
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: sending LCP Code-Reject\n",
			pp->pp_if.if_unit);
E 2
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
	mh->m_len = sizeof(struct ppplcp_header);
	lh = mtod(mh, struct ppplcp_header *);
	lh->lcp_code = PPPLCP_CODEREJ;
	lh->lcp_id = ++ppplcp_packet_id;
	/* Now add the offending packet to the response, trimming it to MTU */
	mh->m_next = op;
	if (pp->pp_state == PPP_STATE_OPENED)
		mtu = MIN(pp->pp_if.if_mtu, PPP_DEFAULT_MTU);
	else
		mtu = PPP_DEFAULT_MTU;
D 2
	for (m = mh, len = 0; m; m->m_next) {
E 2
I 2
	for (m = mh, len = 0; m; m = m->m_next) {
E 2
		if (len + m->m_len > mtu)
			m->m_len = mtu - len;
		len += m->m_len;
		if (m->m_next && len == mtu) {
			m_freem(m->m_next);
			m->m_next = 0;
		}
	}
	lh->lcp_len = htons(len);
	(*pp->pp_hw->phw_output)(pp, mh, PPPPROTO_LCP);
}

/* Send a Protocol-Reject in response to offending packet and dispose of it */
ppplcp_send_protrej(pp, proto, op)
	register struct ppp_softc *pp;
	int proto;
	struct mbuf *op;
{
	register struct mbuf *m, *mh;
	register struct ppplcp_header *lh;
	register int len, mtu;

I 2
	if (pp->pp_if.if_flags & IFF_DEBUG)
D 3
		log(LOG_DEBUG, "ppp%d: sending LCP Protocol-Reject\n",
			pp->pp_if.if_unit);
E 3
I 3
		log(LOG_DEBUG,
			"ppp%d: sending LCP Protocol-Reject (protocol %x)\n",
			pp->pp_if.if_unit, proto);
E 3
E 2
	/* Construct the header for the Protocol-Reject we want to send */
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
	mh->m_len = sizeof(struct ppplcp_header) + sizeof(u_short);
	lh = mtod(mh, struct ppplcp_header *);
	lh->lcp_code = PPPLCP_PROTREJ;
	lh->lcp_id = ++ppplcp_packet_id;
	*(u_short *) (lh + 1) = proto;
	/* Now add the offending packet to the response, trimming it to MTU */
	mh->m_next = op;
	mtu = MIN(pp->pp_if.if_mtu, PPP_DEFAULT_MTU);
D 2
	for (m = mh, len = 0; m; m->m_next) {
E 2
I 2
	for (m = mh, len = 0; m; m = m->m_next) {
E 2
		if (len + m->m_len > mtu)
			m->m_len = mtu - len;
		len += m->m_len;
		if (m->m_next && len == mtu) {
			m_freem(m->m_next);
			m->m_next = 0;
		}
	}
	lh->lcp_len = htons(len);
	(*pp->pp_hw->phw_output)(pp, mh, PPPPROTO_LCP);
}

/*
 * Process received LCP packets.
 * Runs at pppctl software interrupt time (at splnet).
 */
ppplcp_inprocess()
{
	register struct ppp_softc *pp;
	register struct mbuf *m, *n;
	register struct ppplcp_header *lh;
	register int len, indlen;
	int s;

next:	s = splimp();
	IF_DEQUEUE(&ppplcpinq, m);
	splx(s);
	if (m == 0)
		return;
	pp = *(mtod(m, struct ppp_softc **));
	IF_ADJ(m);
	if (pp->pp_state == PPP_STATE_INITIAL) {
		m_freem(m);
		goto next;
	}

	/* Process this packet */
	if (m->m_len < sizeof(struct ppplcp_header) &&
	    (m = m_pullup(m, sizeof(struct ppplcp_header))) == 0)
		goto next;
	lh = mtod(m, struct ppplcp_header *);
	/* Validate the indicated length and trim any padding */
	indlen = ntohs(lh->lcp_len);
	if (indlen < sizeof(struct ppplcp_header)) {
		m_freem(m);
		goto next;
	}
D 2
	for (n = m, len = 0; n; n->m_next) {
E 2
I 2
	for (n = m, len = 0; n; n = n->m_next) {
E 2
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
		goto next;
	}

	/* Dispatch by type. All handling routines dispose of the packet. */
I 5
	pp->pp_busy = 1;
E 5
	switch (lh->lcp_code) {
	case PPPLCP_CONFREQ:
		ppplcp_handle_confreq(pp, m);
D 5
		goto next;
E 5
I 5
		break;
E 5
	case PPPLCP_CONFACK:
		ppplcp_handle_confack(pp, m);
D 5
		goto next;
E 5
I 5
		break;
E 5
	case PPPLCP_CONFNAK:
		ppplcp_handle_confnak(pp, m);
D 5
		goto next;
E 5
I 5
		break;
E 5
	case PPPLCP_CONFREJ:
		ppplcp_handle_confrej(pp, m);
D 5
		goto next;
E 5
I 5
		break;
E 5
	case PPPLCP_TERMREQ:
		ppplcp_handle_termreq(pp, m);
D 5
		goto next;
E 5
I 5
		break;
E 5
	case PPPLCP_TERMACK:
		ppplcp_handle_termack(pp, m);
D 5
		goto next;
E 5
I 5
		break;
E 5
	case PPPLCP_CODEREJ:
		ppplcp_handle_coderej(pp, m);
D 5
		goto next;
E 5
I 5
		break;
E 5
	case PPPLCP_PROTREJ:
		ppplcp_handle_protrej(pp, m);
D 5
		goto next;
E 5
I 5
		break;
E 5
	case PPPLCP_ECHOREQ:
		ppplcp_handle_echoreq(pp, m);
D 5
		goto next;
E 5
I 5
		break;
E 5
	case PPPLCP_ECHORPLY:
	case PPPLCP_DISCARDREQ:
		m_freem(m);
D 5
		goto next;
E 5
I 5
		break;
E 5
	default:
		ppplcp_send_coderej(pp, m);
D 5
		goto next;
E 5
	}
I 5
	pp->pp_busy = 0;
	goto next;
E 5
}

/*
 * Routines to handle different kinds of received LCP packets.
 * Each routine is responsible for disposing of the packet.
 */
ppplcp_handle_confreq(pp, m)
	register struct ppp_softc *pp;
	register struct mbuf *m;
{
	u_char id;
	register int opt, optlen;
	struct mbuf *ack = 0, *ackt = 0, **ackp = &ackt;
	struct mbuf *nak = 0, *nakt = 0, **nakp = &nakt;
	struct mbuf *rej = 0, *rejt = 0, **rejp = &rejt;
	register char *cp;
I 6
	int i;
E 6

I 2
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: got LCP Configure-Req\n",
			pp->pp_if.if_unit);
E 2
	/* See what to do with such packets in general in the current state */
	switch (pp->pp_state) {
	case PPP_STATE_INITIAL:
		m_freem(m);
		return;
	case PPP_STATE_STARTING:
		break;
	case PPP_STATE_CLOSED:
		ppplcp_send_termack(pp, m);
		return;
	case PPP_STATE_STOPPED:
		break;
	case PPP_STATE_CLOSING:
	case PPP_STATE_STOPPING:
		m_freem(m);
		return;
	case PPP_STATE_REQSENT:
	case PPP_STATE_ACKRCVD:
	case PPP_STATE_ACKSENT:
		break;
	case PPP_STATE_OPENED:
		ppp_is_down(pp);
		break;
	}

	/* OK, we are interested in this packet. Parse it. */
	id = (mtod(m, struct ppplcp_header *))->lcp_id;
	m->m_off += sizeof(struct ppplcp_header);
	m->m_len -= sizeof(struct ppplcp_header);
I 2
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: parsing LCP Configure-Req ID %x\n",
			pp->pp_if.if_unit, (u_long) id);
E 2
	/* Before we parse the options, initialise the defaults */
	pp->pp_peerconf = 0;
	pp->pp_agreedmtu = PPP_DEFAULT_MTU;
	if (pp->pp_hw->phw_caps & PPP_PHYCAPS_OKSENDACCM)
		pp->pp_raccm = 0xFFFFFFFF;
	else
		pp->pp_raccm = 0;

	/* Parse the options. We'll need some macros. */
#define	OPT_bogon	{ \
		m_freem(m); \
		m_freem(ackt); \
		m_freem(nakt); \
		m_freem(rejt); \
I 2
		if (pp->pp_if.if_flags & IFF_DEBUG) \
			log(LOG_DEBUG, "ppp%d: LCP Configure-Req bogus\n", \
				pp->pp_if.if_unit); \
E 2
		ppplcp_handle_confreq_bad(pp); \
		return; \
	}
#define	OPT_runt	{ \
		m_freem(ackt); \
		m_freem(nakt); \
		m_freem(rejt); \
I 2
		if (pp->pp_if.if_flags & IFF_DEBUG) \
D 3
			log(LOG_DEBUG, "ppp%d: LCP Configure-Req bogus\n", \
E 3
I 3
			log(LOG_DEBUG, "ppp%d: LCP Configure-Req runt\n", \
E 3
				pp->pp_if.if_unit); \
E 2
		ppplcp_handle_confreq_bad(pp); \
		return; \
	}
#define	OPT_nobufs	{ \
		m_freem(m); \
		m_freem(ackt); \
		m_freem(nakt); \
		m_freem(rejt); \
		ppplcp_handle_confreq_bad(pp); \
		return; \
	}
#define	OPT_input(len)	{ \
		if (m->m_len < len && (m = m_pullup(m, len)) == 0) { \
			m_freem(ackt); \
			m_freem(nakt); \
			m_freem(rejt); \
			ppplcp_handle_confreq_bad(pp); \
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
		case LCPOPT_MRU:
			if (optlen != 2) {
I 3
				if (pp->pp_if.if_flags & IFF_DEBUG)
					log(LOG_DEBUG,
					    "ppp%d: LCP option MRU (bogus)\n",
					    pp->pp_if.if_unit);
E 3
				OPT_skip
				OPT_output(nak, 4)
				*cp++ = LCPOPT_MRU;
				*cp++ = 4;
				*(u_short *) cp = htons(pp->pp_desmtu);
				continue;
			}
			OPT_input(2)
			pp->pp_agreedmtu = ntohs(*(mtod(m, u_short *)));
			m->m_off += 2;
			m->m_len -= 2;
I 3
			if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG, "ppp%d: LCP option MRU %d\n",
					pp->pp_if.if_unit, pp->pp_agreedmtu);
E 3
			if (pp->pp_agreedmtu >= IF_MINMTU) {
				OPT_output(ack, 4)
				*cp++ = LCPOPT_MRU;
				*cp++ = 4;
				*(u_short *) cp = htons(pp->pp_agreedmtu);
			} else {
				OPT_output(nak, 4)
				*cp++ = LCPOPT_MRU;
				*cp++ = 4;
				*(u_short *) cp = htons(IF_MINMTU);
			}
			continue;

		case LCPOPT_ACCM:
			if (optlen != 4) {
I 3
				if (pp->pp_if.if_flags & IFF_DEBUG)
					log(LOG_DEBUG,
					    "ppp%d: LCP option ACCM (bogus)\n",
					    pp->pp_if.if_unit);
E 3
				OPT_skip
				OPT_output(nak, 6)
				*cp++ = LCPOPT_ACCM;
				*cp++ = 6;
				*(u_long *) cp = htonl(0);
				continue;
			}
			OPT_input(4)
			pp->pp_raccm = htonl(*(mtod(m, u_long *)));
			m->m_off += 4;
			m->m_len -= 4;
D 3
			if (pp->pp_raccm == 0 &&
E 3
I 3
			if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG, "ppp%d: LCP option ACCM %x\n",
					pp->pp_if.if_unit, pp->pp_raccm);
			if (pp->pp_raccm == 0 ||
E 3
			    pp->pp_hw->phw_caps & PPP_PHYCAPS_OKSENDACCM) {
				OPT_output(ack, 6)
				*cp++ = LCPOPT_ACCM;
				*cp++ = 6;
				*(u_long *) cp = htonl(pp->pp_raccm);
			} else {
				OPT_output(nak, 6)
				*cp++ = LCPOPT_ACCM;
				*cp++ = 6;
				*(u_long *) cp = htonl(0);
			}
			continue;

I 6
		case LCPOPT_AUTHTYPE:
			if (!pp->pp_authself_nprotos) {
				if (pp->pp_if.if_flags & IFF_DEBUG)
					log(LOG_DEBUG,
		"ppp%d: LCP authentication option requested, unsupported\n",
					    pp->pp_if.if_unit);
				goto unsupported;
			}
			pp->pp_peerconf |= PEERCONF_NEEDAUTH;
			if (optlen < 2 || optlen > 2+PPP_AUTH_MAXP) {
				if (pp->pp_if.if_flags & IFF_DEBUG)
					log(LOG_DEBUG,
				"ppp%d: LCP authentication option (bogus)\n",
					    pp->pp_if.if_unit);
				OPT_skip
			auth_suggest:
			    optlen = 4 +
				pp->pp_authself_protos[0].authproto_nparambytes;
			    OPT_output(nak, optlen)
			    *cp++ = LCPOPT_AUTHTYPE;
			    *cp++ = optlen;
			    optlen -= 2;
			    bcopy(&pp->pp_authself_protos[0].authproto_proto,
				cp, optlen);
			    continue;
			}
			OPT_input(optlen)
			for (i = 0; i < pp->pp_authself_nprotos; i++) {
			    if (optlen != 2 +
				pp->pp_authself_protos[i].authproto_nparambytes)
					continue;
			    if (bcmp(mtod(m, u_char *),
				&pp->pp_authself_protos[i].authproto_proto,
				optlen))
					continue;
			    if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG,
			    "ppp%d: LCP authentication option, protocol #%d\n",
					pp->pp_if.if_unit, i);
			    pp->pp_authself_index = i;
			    OPT_output(ack, 2)
			    *cp++ = opt;
			    *cp++ = optlen + 2;
			    OPT_copy(ack)
			    break;
			}
			if (i == pp->pp_authself_nprotos) {
			    if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG,
D 7
			    "ppp%d: LCP authentication option, unknwon proto\n",
E 7
I 7
			    "ppp%d: LCP authentication option, unknown proto\n",
E 7
					pp->pp_if.if_unit);
			    m->m_off += optlen;
			    m->m_len -= optlen;
			    goto auth_suggest;
			}
			continue;

E 6
		case LCPOPT_PROTCOMP:
			if (optlen) {
I 3
				if (pp->pp_if.if_flags & IFF_DEBUG)
					log(LOG_DEBUG,
					    "ppp%d: LCP option PFC (bogus)\n",
					    pp->pp_if.if_unit);
E 3
				OPT_skip
				OPT_output(nak, 2)
				*cp++ = LCPOPT_PROTCOMP;
				*cp++ = 2;
				continue;
			}
I 3
			if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG, "ppp%d: LCP option PFC\n",
					pp->pp_if.if_unit);
E 3
			pp->pp_peerconf |= PEERCONF_OKPROTCOMP;
			OPT_output(ack, 2)
			*cp++ = LCPOPT_PROTCOMP;
			*cp++ = 2;
			continue;

		case LCPOPT_ACCOMP:
			if (optlen) {
I 3
				if (pp->pp_if.if_flags & IFF_DEBUG)
					log(LOG_DEBUG,
					    "ppp%d: LCP option ACFC (bogus)\n",
					    pp->pp_if.if_unit);
E 3
				OPT_skip
				OPT_output(nak, 2)
				*cp++ = LCPOPT_ACCOMP;
				*cp++ = 2;
				continue;
			}
I 3
			if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG, "ppp%d: LCP option ACFC\n",
					pp->pp_if.if_unit);
E 3
			pp->pp_peerconf |= PEERCONF_OKACCOMP;
			OPT_output(ack, 2)
			*cp++ = LCPOPT_ACCOMP;
			*cp++ = 2;
			continue;

		default:
I 3
			if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG,
				    "ppp%d: LCP unknown option %x length %d\n",
				    pp->pp_if.if_unit, opt, optlen);
I 6
		unsupported:
E 6
E 3
			OPT_output(rej, 2)
			*cp++ = opt;
D 6
			*cp++ = optlen;
E 6
I 6
			*cp++ = optlen + 2;
E 6
			OPT_copy(rej)
		}
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
I 2
		if (pp->pp_if.if_flags & IFF_DEBUG)
			log(LOG_DEBUG, "ppp%d: sending LCP Configure-Ack\n",
				pp->pp_if.if_unit);
E 2
		if (ppplcp_send_confresp(pp, PPPLCP_CONFACK, id, ackt) == 0)
			ppplcp_handle_confreq_good(pp);
		else
			ppplcp_handle_confreq_bad(pp);
	} else {				/* Bad */
I 4
		m_freem(ackt);
E 4
D 2
		if (rejt)
E 2
I 2
		if (rejt) {
			if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG,
					"ppp%d: sending LCP Configure-Reject\n",
					pp->pp_if.if_unit);
E 2
			ppplcp_send_confresp(pp, PPPLCP_CONFREJ, id, rejt);
D 2
		if (nakt)
E 2
I 2
		}
		if (nakt) {
			if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG,
					"ppp%d: sending LCP Configure-Nak\n",
					pp->pp_if.if_unit);
E 2
			ppplcp_send_confresp(pp, PPPLCP_CONFNAK, id, nakt);
I 2
		}
E 2
		ppplcp_handle_confreq_bad(pp);
	}
}

/* The following two routines handle RFC 1661 RCR+ and RCR- events */
ppplcp_handle_confreq_good(pp)
	register struct ppp_softc *pp;
{
I 2
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: LCP Configure-Req good\n",
			pp->pp_if.if_unit);
E 2
	switch (pp->pp_state) {
	case PPP_STATE_STARTING:
	case PPP_STATE_STOPPED:
	case PPP_STATE_OPENED:
		ppplcp_init_negot(pp);
		pp->pp_restcnt = pp->pp_maxconf;
		ppplcp_send_confreq(pp);
	case PPP_STATE_REQSENT:
D 2
		pppstatechg(PPP_STATE_ACKSENT);
E 2
I 2
		pppstatechg(pp, PPP_STATE_ACKSENT);
E 2
		break;
	case PPP_STATE_ACKRCVD:
D 2
		pppstatechg(PPP_STATE_OPENED);
E 2
I 2
		pppstatechg(pp, PPP_STATE_OPENED);
E 2
		break;
	}
}

ppplcp_handle_confreq_bad(pp)
	register struct ppp_softc *pp;
{
I 2
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: LCP Configure-Req bad\n",
			pp->pp_if.if_unit);
E 2
	switch (pp->pp_state) {
	case PPP_STATE_STARTING:
	case PPP_STATE_STOPPED:
	case PPP_STATE_OPENED:
		ppplcp_init_negot(pp);
		pp->pp_restcnt = pp->pp_maxconf;
		ppplcp_send_confreq(pp);
	case PPP_STATE_ACKSENT:
D 2
		pppstatechg(PPP_STATE_REQSENT);
E 2
I 2
		pppstatechg(pp, PPP_STATE_REQSENT);
E 2
	}
}

ppplcp_handle_confack(pp, m)
	register struct ppp_softc *pp;
	struct mbuf *m;
{
I 2
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: got LCP Configure-Ack\n",
			pp->pp_if.if_unit);
E 2
	switch (pp->pp_state) {
	case PPP_STATE_CLOSED:
	case PPP_STATE_STOPPED:
		ppplcp_send_termack(pp, m);
		return;
	case PPP_STATE_REQSENT:
		if (mtod(m, struct ppplcp_header *)->lcp_id ==
		    pp->pp_lastreqid) {
			pp->pp_if.if_timer = pp->pp_restimer;
D 2
			pppstatechg(PPP_STATE_ACKRCVD);
E 2
I 2
			pppstatechg(pp, PPP_STATE_ACKRCVD);
E 2
		}
		m_freem(m);
		return;
	case PPP_STATE_ACKSENT:
		if (mtod(m, struct ppplcp_header *)->lcp_id ==
		    pp->pp_lastreqid)
D 2
			pppstatechg(PPP_STATE_OPENED);
E 2
I 2
			pppstatechg(pp, PPP_STATE_OPENED);
E 2
		m_freem(m);
		return;
	default:
		m_freem(m);
		return;
	}
}

ppplcp_handle_confnak(pp, m)
	register struct ppp_softc *pp;
	register struct mbuf *m;
{
	register int opt, optlen, chg = 0;

I 2
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: got LCP Configure-Nak\n",
			pp->pp_if.if_unit);
E 2
	switch (pp->pp_state) {
	case PPP_STATE_CLOSED:
	case PPP_STATE_STOPPED:
		ppplcp_send_termack(pp, m);
		return;
	case PPP_STATE_REQSENT:
		if (mtod(m, struct ppplcp_header *)->lcp_id == pp->pp_lastreqid)
			break;
		m_freem(m);
		return;
	case PPP_STATE_ACKRCVD:
		m_freem(m);
		pp->pp_restcnt = pp->pp_maxconf;
		ppplcp_send_confreq(pp);
D 2
		pppstatechg(PPP_STATE_REQSENT);
E 2
I 2
		pppstatechg(pp, PPP_STATE_REQSENT);
E 2
		return;
	case PPP_STATE_ACKSENT:
		if (mtod(m, struct ppplcp_header *)->lcp_id == pp->pp_lastreqid)
			break;
		m_freem(m);
		return;
	case PPP_STATE_OPENED:
		m_freem(m);
		ppplcp_init_negot(pp);
		pp->pp_restcnt = pp->pp_maxconf;
		ppplcp_send_confreq(pp);
D 2
		pppstatechg(PPP_STATE_REQSENT);
E 2
I 2
		pppstatechg(pp, PPP_STATE_REQSENT);
E 2
		return;
	default:
		m_freem(m);
		return;
	}

	/* This is a negative response to our request. Process the options. */
I 2
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: parsing LCP Configure-Nak\n",
			pp->pp_if.if_unit);
E 2
	m->m_off += sizeof(struct ppplcp_header);
	m->m_len -= sizeof(struct ppplcp_header);

I 3
#define	OPT_bogon	{ \
		m_freem(m); \
		if (pp->pp_if.if_flags & IFF_DEBUG) \
			log(LOG_DEBUG, "ppp%d: LCP Configure-Nak bogus\n", \
				pp->pp_if.if_unit); \
		goto outcome; \
	}
#define	OPT_runt	{ \
		if (pp->pp_if.if_flags & IFF_DEBUG) \
			log(LOG_DEBUG, "ppp%d: LCP Configure-Nak runt\n", \
				pp->pp_if.if_unit); \
		goto outcome; \
	}
E 3
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
D 3
				goto outcome; \
E 3
I 3
				OPT_runt \
E 3
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
D 3
			break;
E 3
I 3
			OPT_runt
E 3
		optlen = *mtod(m, u_char *);
		m->m_off++;
		m->m_len--;
D 3
		if (optlen < 2) {
			m_freem(m);
			break;
		}
E 3
I 3
		if (optlen < 2)
			OPT_bogon
E 3
		optlen -= 2;

		/* Handle known options */
		switch (opt) {
		case LCPOPT_MRU: {
			int mru;

			if (optlen != 2) {
I 3
				if (pp->pp_if.if_flags & IFF_DEBUG)
					log(LOG_DEBUG,
					    "ppp%d: LCP option MRU (bogus)\n",
					    pp->pp_if.if_unit);
E 3
				OPT_skip
				continue;
			}
			OPT_input(2)
			mru = ntohs(*mtod(m, u_short *));
			m->m_off += 2;
			m->m_len -= 2;
I 3
			if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG, "ppp%d: LCP option MRU %d\n",
					pp->pp_if.if_unit, mru);
I 4
			if (!(pp->pp_lcpnegot & LCPNEGOT_ASKMRU)) {
				pp->pp_lcpnegot |= LCPNEGOT_ASKMRU;
				chg++;
			}
E 4
E 3
			if (mru < IF_MINMTU)
				mru = IF_MINMTU;
			if (mru > pp->pp_hw->phw_mru)
				mru = pp->pp_hw->phw_mru;
			if (mru != pp->pp_agreedmru) {
				pp->pp_agreedmru = mru;
				chg++;
			}
			continue;
		}

		case LCPOPT_ACCM: {
			u_long accm;

			if (optlen != 4) {
I 3
				if (pp->pp_if.if_flags & IFF_DEBUG)
					log(LOG_DEBUG,
					    "ppp%d: LCP option ACCM (bogus)\n",
					    pp->pp_if.if_unit);
E 3
				OPT_skip
				continue;
			}
			OPT_input(4)
			accm = ntohl(*mtod(m, u_long *));
			m->m_off += 4;
			m->m_len -= 4;
I 3
			if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG, "ppp%d: LCP option ACCM %d\n",
					pp->pp_if.if_unit, accm);
I 4
			if (!(pp->pp_lcpnegot & LCPNEGOT_ASKACCM)) {
				pp->pp_lcpnegot |= LCPNEGOT_ASKACCM;
				chg++;
			}
E 4
E 3
			if (!(pp->pp_hw->phw_caps & PPP_PHYCAPS_OKRECVACCM))
				continue;
			if (accm != pp->pp_laccm) {
				pp->pp_laccm = accm;
				chg++;
			}
			continue;
		}

I 3
		case LCPOPT_PROTCOMP:
			if (optlen) {
				if (pp->pp_if.if_flags & IFF_DEBUG)
					log(LOG_DEBUG,
					    "ppp%d: LCP option PFC (bogus)\n",
					    pp->pp_if.if_unit);
				OPT_skip
				continue;
			}
			if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG, "ppp%d: LCP option PFC\n",
					pp->pp_if.if_unit);
			if (!(pp->pp_hw->phw_caps & PPP_PHYCAPS_OKRECVPROTCOMP))
				continue;
			if (!(pp->pp_lcpnegot & LCPNEGOT_ASKPROTCOMP)) {
				pp->pp_lcpnegot |= LCPNEGOT_ASKPROTCOMP;
				chg++;
			}
			continue;

		case LCPOPT_ACCOMP:
			if (optlen) {
				if (pp->pp_if.if_flags & IFF_DEBUG)
					log(LOG_DEBUG,
					    "ppp%d: LCP option ACFC (bogus)\n",
					    pp->pp_if.if_unit);
				OPT_skip
				continue;
			}
			if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG, "ppp%d: LCP option ACFC\n",
					pp->pp_if.if_unit);
			if (!(pp->pp_hw->phw_caps & PPP_PHYCAPS_OKRECVACCOMP))
				continue;
			if (!(pp->pp_lcpnegot & LCPNEGOT_ASKACCOMP)) {
				pp->pp_lcpnegot |= LCPNEGOT_ASKACCOMP;
				chg++;
			}
			continue;

E 3
		default:
I 3
			if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG,
				    "ppp%d: LCP unknown option %x length %d\n",
				    pp->pp_if.if_unit, opt, optlen);
E 3
			OPT_skip
		}
	}
I 3
#undef	OPT_bogon
#undef	OPT_runt
E 3
#undef	OPT_input
#undef	OPT_skip
D 2
outcome:
E 2

D 2
	if (chg)
		pp->pp_lcpnegot &= ~LCPNEGOT_DRAW;
	else if (pp->pp_lcpnegot & LCPNEGOT_DRAW) {
		pp->pp_restcnt = pp->pp_maxterm;
		ppplcp_send_termreq(pp);
		pppstatechg(PPP_STATE_STOPPING);
		return;
	} else
		pp->pp_lcpnegot |= LCPNEGOT_DRAW;
	pp->pp_restcnt = pp->pp_maxconf;
	ppplcp_send_confreq(pp);
E 2
I 2
outcome:
	ppplcp_handle_confnakrej_outcome(pp, chg);
E 2
}

ppplcp_handle_confrej(pp, m)
	register struct ppp_softc *pp;
	register struct mbuf *m;
{
	register int opt, optlen, chg = 0;

I 2
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: got LCP Configure-Reject\n",
			pp->pp_if.if_unit);
E 2
	switch (pp->pp_state) {
	case PPP_STATE_CLOSED:
	case PPP_STATE_STOPPED:
		ppplcp_send_termack(pp, m);
		return;
	case PPP_STATE_REQSENT:
		if (mtod(m, struct ppplcp_header *)->lcp_id == pp->pp_lastreqid)
			break;
		m_freem(m);
		return;
	case PPP_STATE_ACKRCVD:
		m_freem(m);
		pp->pp_restcnt = pp->pp_maxconf;
		ppplcp_send_confreq(pp);
D 2
		pppstatechg(PPP_STATE_REQSENT);
E 2
I 2
		pppstatechg(pp, PPP_STATE_REQSENT);
E 2
		return;
	case PPP_STATE_ACKSENT:
		if (mtod(m, struct ppplcp_header *)->lcp_id == pp->pp_lastreqid)
			break;
		m_freem(m);
		return;
	case PPP_STATE_OPENED:
		m_freem(m);
		ppplcp_init_negot(pp);
		pp->pp_restcnt = pp->pp_maxconf;
		ppplcp_send_confreq(pp);
D 2
		pppstatechg(PPP_STATE_REQSENT);
E 2
I 2
		pppstatechg(pp, PPP_STATE_REQSENT);
E 2
		return;
	default:
		m_freem(m);
		return;
	}

	/* This is a negative response to our request. Process the options. */
I 2
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: parsing LCP Configure-Reject\n",
			pp->pp_if.if_unit);
E 2
	m->m_off += sizeof(struct ppplcp_header);
	m->m_len -= sizeof(struct ppplcp_header);

I 3
#define	OPT_bogon	{ \
		m_freem(m); \
		if (pp->pp_if.if_flags & IFF_DEBUG) \
			log(LOG_DEBUG, "ppp%d: LCP Configure-Reject bogus\n", \
				pp->pp_if.if_unit); \
		goto outcome; \
	}
#define	OPT_runt	{ \
		if (pp->pp_if.if_flags & IFF_DEBUG) \
			log(LOG_DEBUG, "ppp%d: LCP Configure-Reject runt\n", \
				pp->pp_if.if_unit); \
		goto outcome; \
	}
E 3
#define	OPT_skip	{ \
		while (optlen) { \
			int t; \
			while (m && m->m_len == 0) \
				m = m_free(m); \
			if (m == 0) \
D 3
				goto outcome; \
E 3
I 3
				OPT_runt \
E 3
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
D 3
			break;
E 3
I 3
			OPT_runt
E 3
		optlen = *mtod(m, u_char *);
		m->m_off++;
		m->m_len--;
D 3
		if (optlen < 2) {
			m_freem(m);
			break;
		}
E 3
I 3
		if (optlen < 2)
			OPT_bogon
E 3
		optlen -= 2;

		/* Handle known options */
		switch (opt) {
		case LCPOPT_MRU:
I 3
			if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG, "ppp%d: LCP option MRU\n",
					pp->pp_if.if_unit);
E 3
			OPT_skip
			if (pp->pp_lcpnegot & LCPNEGOT_ASKMRU) {
				pp->pp_lcpnegot &= ~LCPNEGOT_ASKMRU;
				chg++;
			}
			pp->pp_agreedmru = PPP_DEFAULT_MTU;
			continue;

		case LCPOPT_ACCM:
I 3
			if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG, "ppp%d: LCP option ACCM\n",
					pp->pp_if.if_unit);
E 3
			OPT_skip
			if (pp->pp_lcpnegot & LCPNEGOT_ASKACCM) {
				pp->pp_lcpnegot &= ~LCPNEGOT_ASKACCM;
				chg++;
			}
			if (pp->pp_hw->phw_caps & PPP_PHYCAPS_OKRECVACCM)
				pp->pp_laccm = 0xFFFFFFFF;
			else
				pp->pp_laccm = 0;
			continue;

		case LCPOPT_PROTCOMP:
I 3
			if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG, "ppp%d: LCP option PFC\n",
					pp->pp_if.if_unit);
E 3
			OPT_skip
			if (pp->pp_lcpnegot & LCPNEGOT_ASKPROTCOMP) {
				pp->pp_lcpnegot &= ~LCPNEGOT_ASKPROTCOMP;
				chg++;
			}
			continue;

		case LCPOPT_ACCOMP:
I 3
			if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG, "ppp%d: LCP option ACFC\n",
					pp->pp_if.if_unit);
E 3
			OPT_skip
			if (pp->pp_lcpnegot & LCPNEGOT_ASKACCOMP) {
				pp->pp_lcpnegot &= ~LCPNEGOT_ASKACCOMP;
				chg++;
			}
			continue;

		default:
I 3
			if (pp->pp_if.if_flags & IFF_DEBUG)
				log(LOG_DEBUG,
					"ppp%d: LCP unknown option %x\n",
					pp->pp_if.if_unit, opt);
E 3
			OPT_skip
		}
	}
I 3
#undef	OPT_bogon
#undef	OPT_runt
E 3
#undef	OPT_skip
I 2

E 2
outcome:
I 2
	ppplcp_handle_confnakrej_outcome(pp, chg);
}
E 2

D 2
	if (chg)
E 2
I 2
ppplcp_handle_confnakrej_outcome(pp, chg)
	register struct ppp_softc *pp;
	int chg;
{
	if (chg) {
		if (pp->pp_if.if_flags & IFF_DEBUG)
			log(LOG_DEBUG, "ppp%d: LCP options adjusted\n",
				pp->pp_if.if_unit);
E 2
		pp->pp_lcpnegot &= ~LCPNEGOT_DRAW;
D 2
	else if (pp->pp_lcpnegot & LCPNEGOT_DRAW) {
E 2
I 2
	} else if (pp->pp_lcpnegot & LCPNEGOT_DRAW) {
		if (pp->pp_if.if_flags & IFF_DEBUG)
			log(LOG_DEBUG,
				"ppp%d: no agreement, stopping\n",
				pp->pp_if.if_unit);
E 2
		pp->pp_restcnt = pp->pp_maxterm;
		ppplcp_send_termreq(pp);
D 2
		pppstatechg(PPP_STATE_STOPPING);
E 2
I 2
		pppstatechg(pp, PPP_STATE_STOPPING);
E 2
		return;
D 2
	} else
E 2
I 2
	} else {
		if (pp->pp_if.if_flags & IFF_DEBUG)
			log(LOG_DEBUG,
				"ppp%d: no agreement, give them one last try\n",
				pp->pp_if.if_unit);
E 2
		pp->pp_lcpnegot |= LCPNEGOT_DRAW;
I 2
	}
E 2
	pp->pp_restcnt = pp->pp_maxconf;
	ppplcp_send_confreq(pp);
}

ppplcp_handle_termreq(pp, m)
	register struct ppp_softc *pp;
	struct mbuf *m;
{
I 2
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: got LCP Terminate-Req\n",
			pp->pp_if.if_unit);
E 2
	switch (pp->pp_state) {
	case PPP_STATE_CLOSED:
	case PPP_STATE_STOPPED:
	case PPP_STATE_CLOSING:
	case PPP_STATE_STOPPING:
		ppplcp_send_termack(pp, m);
		return;
	case PPP_STATE_REQSENT:
	case PPP_STATE_ACKRCVD:
	case PPP_STATE_ACKSENT:
	case PPP_STATE_OPENED:
		ppplcp_send_termack(pp, m);
		pp->pp_restcnt = 0;
D 2
		pppstatechg(PPP_STATE_STOPPING);
E 2
I 2
		pp->pp_if.if_timer = pp->pp_restimer;
		pppstatechg(pp, PPP_STATE_STOPPING);
E 2
		return;
	default:
		m_freem(m);
		return;
	}
}

ppplcp_handle_termack(pp, m)
	register struct ppp_softc *pp;
	struct mbuf *m;
{
	m_freem(m);
I 2
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: got LCP Terminate-Ack\n",
			pp->pp_if.if_unit);
E 2
	switch (pp->pp_state) {
	case PPP_STATE_CLOSING:
D 2
		pppstatechg(PPP_STATE_CLOSED);
E 2
I 2
		pppstatechg(pp, PPP_STATE_CLOSED);
E 2
		(*pp->pp_hw->phw_down)(pp);
		break;
	case PPP_STATE_STOPPING:
D 2
		pppstatechg(PPP_STATE_STOPPED);
E 2
I 2
		pppstatechg(pp, PPP_STATE_STOPPED);
E 2
		if (pp->pp_flags & PPP_FLAGS_PERSIST) {
			pp->pp_if.if_timer = 2;
			break;
		}
		if (pp->pp_flags & PPP_FLAGS_PASSIVE)
			break;
		(*pp->pp_hw->phw_down)(pp);
		break;
	case PPP_STATE_ACKRCVD:
		pp->pp_restcnt = pp->pp_maxconf;
		ppplcp_send_confreq(pp);
D 2
		pppstatechg(PPP_STATE_REQSENT);
E 2
I 2
		pppstatechg(pp, PPP_STATE_REQSENT);
E 2
		break;
	case PPP_STATE_OPENED:
		ppplcp_init_negot(pp);
		pp->pp_restcnt = pp->pp_maxconf;
		ppplcp_send_confreq(pp);
D 2
		pppstatechg(PPP_STATE_REQSENT);
E 2
I 2
		pppstatechg(pp, PPP_STATE_REQSENT);
E 2
		break;
	}
}

ppplcp_handle_coderej(pp, m)
	register struct ppp_softc *pp;
	register struct mbuf *m;
{
	register int code;

I 2
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: got LCP Code-Reject\n",
			pp->pp_if.if_unit);
E 2
	m->m_off += sizeof(struct ppplcp_header);
	m->m_len -= sizeof(struct ppplcp_header);
	while (m && m->m_len == 0)
		m = m_free(m);
	if (m == 0)
		return;
	code = *mtod(m, u_char *);
	m_freem(m);
I 3
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: LCP code %x rejected by peer\n",
			pp->pp_if.if_unit, code);
E 3
	switch (code) {
	case PPPLCP_CONFREQ:
	case PPPLCP_CONFACK:
	case PPPLCP_CONFNAK:
	case PPPLCP_CONFREJ:
	case PPPLCP_TERMREQ:
	case PPPLCP_TERMACK:
		ppplcp_handle_fatalerr(pp);
	}
}

ppplcp_handle_protrej(pp, m)
	register struct ppp_softc *pp;
	register struct mbuf *m;
{
	register int proto;

I 2
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: got LCP Protocol-Reject\n",
			pp->pp_if.if_unit);
E 2
	m->m_off += sizeof(struct ppplcp_header);
	m->m_len -= sizeof(struct ppplcp_header);
	while (m && m->m_len == 0)
		m = m_free(m);
	if (m == 0)
		return;
	proto = *mtod(m, u_char *) << 8;
	m->m_off++;
	m->m_len--;
	while (m && m->m_len == 0)
		m = m_free(m);
	if (m == 0)
		return;
	proto |= *mtod(m, u_char *);
	m_freem(m);
I 3
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: protocol %x rejected by peer\n",
			pp->pp_if.if_unit, proto);
E 3
	if (proto == PPPPROTO_LCP) {
		ppplcp_handle_fatalerr(pp);
		return;
	}

	if (pp->pp_state != PPP_STATE_OPENED)
		return;
	switch (proto) {

#ifdef INET
	case PPPPROTO_IP:
	case PPPPROTO_IPCP:
		pppipcp_handle_protrej(pp);
		break;
#endif

	}
}

/* This is the RFC 1661 RXJ- event. */
ppplcp_handle_fatalerr(pp)
	register struct ppp_softc *pp;
{
I 2
	if (pp->pp_if.if_flags & IFF_DEBUG)
		log(LOG_DEBUG, "ppp%d: fatal protocol error, shutting down\n",
			pp->pp_if.if_unit);
E 2
	switch (pp->pp_state) {
	case PPP_STATE_CLOSING:
D 2
		pppstatechg(PPP_STATE_CLOSED);
E 2
I 2
		pppstatechg(pp, PPP_STATE_CLOSED);
E 2
		(*pp->pp_hw->phw_down)(pp);
		break;
	case PPP_STATE_STOPPING:
	case PPP_STATE_REQSENT:
	case PPP_STATE_ACKRCVD:
	case PPP_STATE_ACKSENT:
	case PPP_STATE_OPENED:
D 2
		pppstatechg(PPP_STATE_STOPPED);
E 2
I 2
		pppstatechg(pp, PPP_STATE_STOPPED);
E 2
		if (pp->pp_flags & PPP_FLAGS_PERSIST) {
			pp->pp_if.if_timer = 2;
			break;
		}
		if (pp->pp_flags & PPP_FLAGS_PASSIVE)
			break;
		(*pp->pp_hw->phw_down)(pp);
		break;
	}
}

ppplcp_handle_echoreq(pp, m)
	register struct ppp_softc *pp;
	register struct mbuf *m;
{
	register struct ppplcp_header *lh;
I 8
	register struct mbuf *mt;
E 8
	register int len;

	if (pp->pp_state != PPP_STATE_OPENED) {
		m_freem(m);
		return;
	}
	/* Turn it into an Echo-Reply */
	if (m->m_len < sizeof(struct ppplcp_header) + sizeof(u_long) &&
	    !(m = m_pullup(m, sizeof(struct ppplcp_header) + sizeof(u_long))))
		return;
	lh = mtod(m, struct ppplcp_header *);
	lh->lcp_code = PPPLCP_ECHORPLY;
	*(u_long *) (lh + 1) = 0;
	/* Make sure it doesn't exceed the MTU (trim if necessary) */
D 8
	for (len = 0; m; m->m_next) {
		if (len + m->m_len > pp->pp_if.if_mtu)
			m->m_len = pp->pp_if.if_mtu - len;
		len += m->m_len;
		if (m->m_next && len == pp->pp_if.if_mtu) {
			m_freem(m->m_next);
			m->m_next = 0;
E 8
I 8
	for (mt = m, len = 0; mt; mt = mt->m_next) {
		if (len + mt->m_len > pp->pp_if.if_mtu)
			mt->m_len = pp->pp_if.if_mtu - len;
		len += mt->m_len;
		if (mt->m_next && len == pp->pp_if.if_mtu) {
			m_freem(mt->m_next);
			mt->m_next = 0;
E 8
		}
	}
	lh->lcp_len = htons(len);
	(*pp->pp_hw->phw_output)(pp, m, PPPPROTO_LCP);
}
#endif
E 1
