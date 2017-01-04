h23299
s 00124/00000/00000
d D 7.1 07/05/18 19:48:03 msokolov 1 0
c date and time created 07/05/18 19:48:03 by msokolov
e
u
U
t
T
I 1
/*
 * This is a 4.3BSD-Quasijarus kernel source file.
 *
 *	%W% (Berkeley) %G%
 */

#include "param.h"
#include "mbuf.h"
#include "protosw.h"
#include "socket.h"
#include "socketvar.h"
#include "errno.h"
#include "syslog.h"

#include "../net/if.h"

#include "in.h"
#include "in_systm.h"
#include "in_var.h"
#include "if_ether.h"
#include "ip.h"
#include "gre.h"

#if GRETERM
/*
 * This module implements GRE tunnel termination.
 * It receives IP datagrams addressed to this host with IPPROTO_GRE,
 * strips the IP delivery and GRE headers, extracts the IP payload
 * packet and puts it back on ipintrq.
 */

int greterm_debug = 0;

gre_input(m, ifp)
	register struct mbuf *m;
	struct ifnet *ifp;
{
	register struct ip *ip;
	register u_short *gre;
	int grelen, grehlen;
	u_short flags;
	register struct mbuf *n;
	int s;

	/* Strip the IP delivery header first */
	ip = mtod(m, struct ip *);
	grelen = ip->ip_len;		/* may need this for GRE checksum */
	m_adj(m, ip->ip_hl << 2);
	/*
	 * Now get the GRE header.
	 * It has variable length, but we are only interested in the
	 * first longword, which is the minimum length.
	 */
	if (m->m_off > MMAXOFF || m->m_len < 4) {
		m = m_pullup(m, 4);
		if (!m) {
			if (greterm_debug)
				log(LOG_DEBUG,
				"greterm: packet too short for GRE header\n");
			return;
		}
	}
	gre = mtod(m, u_short *);
	/* process GRE flags */
	grehlen = 4;
	flags = ntohs(gre[0]);
	if (flags & GREFLAGS_C) {
		grehlen += 4;
		if (in_cksum(m, grelen)) {
			if (greterm_debug)
				log(LOG_DEBUG, "greterm: bad checksum\n");
			m_freem(m);
			return;
		}
	}
	if (flags & GREFLAGS_R) {
		if (greterm_debug)
			log(LOG_DEBUG, "greterm: GRE routing not supported\n");
		m_freem(m);
		return;
	}
	/* we ignore the key and sequence # if they are present */
	if (flags & GREFLAGS_K)
		grehlen += 4;
	if (flags & GREFLAGS_S)
		grehlen += 4;
	/* is the payload IP? */
	if (ntohs(gre[1]) != ETHERTYPE_IP) {
		if (greterm_debug)
			log(LOG_DEBUG,
				"greterm: payload protocol %x is not IP\n",
				ntohs(gre[1]));
		m_freem(m);
		return;
	}
	/*
	 * Done with the GRE header, strip it and put the payload
	 * IP datagram back on ipintrq.
	 * We use a trick to put ifp in place of the GRE header.
	 */
	if (grehlen != sizeof(struct ifnet *)) {
		m_adj(m, grehlen);
		n = m_get(M_DONTWAIT, MT_HEADER);
		if (n == 0) {
			m_freem(m);
			return;
		}
		n->m_next = m;
		n->m_off = MMINOFF;
		n->m_len = sizeof (struct ifnet *);
		m = n;
	}
	*mtod(m, struct ifnet **) = ifp;
	/* back on ipintrq! */
	s = splimp();
	IF_ENQUEUE(&ipintrq, m);
	splx(s);
	/*
	 * No need to raise the network interrupt because we are called
	 * from ipintr() which always drains ipintrq completely before
	 * returning.
	 */
}
#endif
E 1
