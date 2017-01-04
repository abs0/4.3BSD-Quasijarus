h46475
s 00011/00006/01709
d D 7.8 88/06/29 17:13:45 bostic 27 26
c install approved copyright notice
e
s 00013/00010/01702
d D 7.7 88/05/25 18:10:52 karels 26 25
c in attach, don't set sockbuf limits if set (from sonewconn); lint
e
s 00054/00054/01658
d D 7.6 88/03/12 18:13:15 karels 25 24
c we get our own copy of xxx_timer.h (I don't want to debug TCP and SPP
c simultaneously!)
e
s 00011/00011/01701
d D 7.5 88/03/03 14:34:14 sklower 24 23
c Three bug fixes from/with torek: dupacks check was one off;
c ssthresh was not scaled; the code to remove multiple acked packets was wrong;
c also some minor de-linting.
e
s 00009/00003/01703
d D 7.4 88/01/20 15:15:36 sklower 23 22
c Change licensing/use notice.
e
s 00559/00245/01147
d D 7.3 87/11/05 18:43:22 sklower 22 21
c This incorporates recent tcp strategies of Karels/Jacobson: 
c slow start, clamped rxmt, binary fixed point rtt smoothing.  Works on sun 3.X
e
s 00001/00000/01391
d D 7.2 86/10/28 23:03:04 karels 21 20
c need systm.h for insque
e
s 00001/00001/01390
d D 7.1 86/06/05 00:38:55 mckusick 20 19
c 4.3BSD release version
e
s 00005/00008/01386
d D 6.16 85/12/18 17:05:53 sklower 19 18
c if request to send oobd denied don't free mbuf twice;
c Be careful to calculate free space using signed arithmetic.
e
s 00010/00002/01384
d D 6.15 85/10/30 10:13:15 sklower 18 16
c 1.) If not using delayed acks, must still ack packets which are
c otherwise dropped as duplicates.
c 2.) Kernel should return error on illegal socket option requests.
c (or pass them further down the layers at some future date?)
e
s 00010/00002/01384
d R 6.15 85/10/29 14:24:43 sklower 17 16
c 1.) If not using delayed acks, must still ack packets which are
c otherwise dropped as duplicates.
c 2.) Kernel should return error on illegal socket option requests.
c (or pass them further down the layers at some future date?)
e
s 00007/00008/01379
d D 6.14 85/10/11 16:21:40 sklower 16 15
c Bug in deciding to retransmit a packet.
e
s 00051/00039/01336
d D 6.13 85/09/26 14:18:58 sklower 15 13
c Fix retransmisssion, out of band bugs.
e
s 00051/00039/01336
d R 6.13 85/09/26 14:09:18 sklower 14 13
c Fix retransmisssion, out of band bugs.
e
s 00045/00025/01330
d D 6.12 85/09/13 20:15:45 sklower 13 12
c 1. when raising windows, let those frozen out know
c 2. allow an option for two way shakes instead of three way shakes on open
c 3. clear OOB indications, but not on peeks
c 4. make sure that when calculating windows it does so with signed arith.
e
s 00044/00017/01311
d D 6.11 85/09/07 13:05:23 sklower 12 10
c Pay lip service to interface tracing, ctlinput now expects 
c sockaddrs in response to imp stuff, add option for larger mtu's (default 
c is now and was supposed to be 576 bytes).
e
s 00087/00051/01277
d R 6.11 85/09/06 18:35:12 sklower 11 10
c Do Something with interface tracing & fix ctlinput routines.
e
s 00002/00001/01326
d D 6.10 85/08/23 12:26:44 walsh 10 9
c replaced tcpexprexmtbackoff with sppexprexmtbackoff for bbn net code
e
s 00000/00001/01327
d D 6.9 85/08/23 12:17:36 walsh 9 8
c removed reverence to Berk TCP variable so can compile with BBN stuff
e
s 00051/00036/01277
d D 6.8 85/08/17 13:30:06 sklower 8 7
c bug dealing with fragmented or insufficient data in writes in packet mode, but oodles of niggling
c formatting pick-picks from chris torek@maryland.
e
s 00021/00018/01292
d D 6.7 85/08/09 11:34:39 sklower 7 6
c 
e
s 00010/00007/01300
d D 6.6 85/07/26 15:46:30 sklower 6 5
c Do pullups on input (from chris@maryland).
e
s 00058/00022/01249
d D 6.5 85/07/19 18:58:33 sklower 5 4
c checkpoint recent work:
c 1.) Find out more detail about dropped retransmissions that are recieved.
c 2.) Make sure one connection refused from a machine doesn't shutdown all other
c     dialogues in progres.
c 3.) Fixes concering Out-Of-Band data.
e
s 00003/00001/01268
d D 6.4 85/06/19 09:10:12 sklower 4 3
c fix mbuf leak in smallest way, check in for 4.3 betas
e
s 00042/00023/01227
d D 6.3 85/06/17 18:34:28 sklower 3 2
c Check that m_get or m_copy don't give NULL in every instance.
e
s 00007/00001/01243
d D 6.2 85/06/08 12:52:39 mckusick 2 1
c Add copyright
e
s 01244/00000/00000
d D 6.1 85/05/30 19:11:13 sklower 1 0
c date and time created 85/05/30 19:11:13 by sklower
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
D 18
 * Copyright (c) 1982 Regents of the University of California.
E 18
I 18
D 20
 * Copyright (c) 1984, 1985 Regents of the University of California.
E 20
I 20
D 22
 * Copyright (c) 1984, 1985, 1986 Regents of the University of California.
E 22
I 22
 * Copyright (c) 1984, 1985, 1986, 1987 Regents of the University of California.
E 22
E 20
E 18
D 23
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 23
I 23
 * All rights reserved.
E 23
 *
D 23
 *	%W% (Berkeley) %G%
E 23
I 23
 * Redistribution and use in source and binary forms are permitted
D 27
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 27
I 27
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
E 27
 *
D 27
 *      %W% (Berkeley) %G%
E 27
I 27
 *	%W% (Berkeley) %G%
E 27
E 23
 */
E 2

#include "param.h"
I 21
#include "systm.h"
E 21
#include "dir.h"
#include "user.h"
#include "mbuf.h"
#include "protosw.h"
#include "socket.h"
#include "socketvar.h"
#include "errno.h"

#include "../net/if.h"
#include "../net/route.h"
#include "../netinet/tcp_fsm.h"
D 25
#include "../netinet/tcp_timer.h"
E 25

#include "ns.h"
#include "ns_pcb.h"
#include "idp.h"
#include "idp_var.h"
#include "ns_error.h"
#include "sp.h"
#include "spidp.h"
I 25
#include "spp_timer.h"
E 25
#include "spp_var.h"
#include "spp_debug.h"

/*
 * SP protocol implementation.
 */
spp_init()
{

	spp_iss = 1; /* WRONG !! should fish it out of TODR */
}
struct spidp spp_savesi;
int traceallspps = 0;
extern int sppconsdebug;
D 12

E 12
int spp_hardnosed;
I 15
int spp_use_delack = 0;
E 15
D 5
spp_input(m, nsp)
	register struct nspcb *nsp;
E 5
I 5
D 6
spp_input(m)
E 6
I 6
D 12
spp_input(m, nsp)
E 12
I 12

/*ARGSUSED*/
spp_input(m, nsp, ifp)
E 12
E 6
E 5
	register struct mbuf *m;
D 6
{
E 6
I 5
	register struct nspcb *nsp;
I 12
	struct ifnet *ifp;
E 12
I 6
{
E 6
E 5
	register struct sppcb *cb;
	register struct spidp *si = mtod(m, struct spidp *);
	register struct socket *so;
D 7
	int len; short ostate;
E 7
I 7
	short ostate;
E 7
	int dropsocket = 0;


I 22
	sppstat.spps_rcvtotal++;
E 22
I 5
D 6
	/*
	 * Locate pcb for datagram.
	 */
	nsp = ns_pcblookup(&si->si_sna, si->si_dna.x_port, NS_WILDCARD);
E 6
D 8
	if (nsp==0) {
E 8
I 8
	if (nsp == 0) {
E 8
D 6
		ns_error(m, NS_ERR_NOSOCK, 0);
E 6
I 6
		panic("No nspcb in spp_input\n");
E 6
		return;
	}
E 5

	cb = nstosppcb(nsp);
	if (cb == 0) goto bad;

I 6
	if (m->m_len < sizeof(*si)) {
D 8
		if ((m = m_pullup(m, sizeof(*si)))==0) {
E 8
I 8
		if ((m = m_pullup(m, sizeof(*si))) == 0) {
E 8
D 22
			spp_istat.hdrops++;
E 22
I 22
			sppstat.spps_rcvshort++;
E 22
			return;
		}
		si = mtod(m, struct spidp *);
	}
E 6
	si->si_seq = ntohs(si->si_seq);
	si->si_ack = ntohs(si->si_ack);
	si->si_alo = ntohs(si->si_alo);

	so = nsp->nsp_socket;
	if (so->so_options & SO_DEBUG || traceallspps) {
		ostate = cb->s_state;
		spp_savesi = *si;
	}
	if (so->so_options & SO_ACCEPTCONN) {
I 22
		struct sppcb *ocb = cb;
D 26
		struct socket *oso = so;
E 26
I 26

E 26
E 22
		so = sonewconn(so);
		if (so == 0) {
D 22
			spp_istat.nonucn++;
E 22
			goto drop;
		}
		/*
		 * This is ugly, but ....
		 *
		 * Mark socket as temporary until we're
		 * committed to keeping it.  The code at
		 * ``drop'' and ``dropwithreset'' check the
		 * flag dropsocket to see if the temporary
		 * socket created here should be discarded.
		 * We mark the socket as discardable until
		 * we're committed to it below in TCPS_LISTEN.
		 */
		dropsocket++;
		nsp = (struct nspcb *)so->so_pcb;
		nsp->nsp_laddr = si->si_dna;
		cb = nstosppcb(nsp);
I 22
		cb->s_mtu = ocb->s_mtu;		/* preserve sockopts */
		cb->s_flags = ocb->s_flags;	/* preserve sockopts */
D 26
		if (so->so_snd.sb_hiwat != oso->so_snd.sb_hiwat) /*XXX*/
			sbreserve(&so->so_snd, oso->so_snd.sb_hiwat);
		if (so->so_rcv.sb_hiwat != oso->so_rcv.sb_hiwat) /*XXX*/
			sbreserve(&so->so_rcv, oso->so_rcv.sb_hiwat);
E 26
E 22
		cb->s_state = TCPS_LISTEN;
	}

	/*
	 * Packet received on connection.
	 * reset idle time and keep-alive timer;
	 */
	cb->s_idle = 0;
D 25
	cb->s_timer[TCPT_KEEP] = TCPTV_KEEP;
E 25
I 25
	cb->s_timer[SPPT_KEEP] = SPPTV_KEEP;
E 25

	switch (cb->s_state) {
I 3

E 3
	case TCPS_LISTEN:{
		struct mbuf *am;
		register struct sockaddr_ns *sns;
		struct ns_addr laddr;

		/*
		 * If somebody here was carying on a conversation
		 * and went away, and his pen pal thinks he can
		 * still talk, we get the misdirected packet.
		 */
		if (spp_hardnosed && (si->si_did != 0 || si->si_seq != 0)) {
			spp_istat.gonawy++;
			goto dropwithreset;
		}
		am = m_get(M_DONTWAIT, MT_SONAME);
		if (am == NULL)
			goto drop;
		am->m_len = sizeof (struct sockaddr_ns);
		sns = mtod(am, struct sockaddr_ns *);
		sns->sns_family = AF_NS;
		sns->sns_addr = si->si_sna;
		laddr = nsp->nsp_laddr;
		if (ns_nullhost(laddr))
			nsp->nsp_laddr = si->si_dna;
		if (ns_pcbconnect(nsp, am)) {
			nsp->nsp_laddr = laddr;
			(void) m_free(am);
			spp_istat.noconn++;
			goto drop;
		}
		(void) m_free(am);
D 13
		cb->s_state = TCPS_SYN_RECEIVED;
E 13
		spp_template(cb);
I 13
		dropsocket = 0;		/* committed to socket */
E 13
		cb->s_did = si->si_sid;
		cb->s_rack = si->si_ack;
		cb->s_ralo = si->si_alo;
D 13
		cb->s_flags |= SF_AK;
		cb->s_timer[TCPT_KEEP] = TCPTV_KEEP;
		dropsocket = 0;		/* committed to socket */
E 13
I 13
#define THREEWAYSHAKE
#ifdef THREEWAYSHAKE
		cb->s_state = TCPS_SYN_RECEIVED;
D 22
		cb->s_force = 1 + TCPT_REXMT;
		cb->s_timer[TCPT_REXMT] = 2 * TCPTV_MIN;
E 22
I 22
D 25
		cb->s_force = 1 + TCPT_KEEP;
E 25
I 25
		cb->s_force = 1 + SPPT_KEEP;
E 25
		sppstat.spps_accepts++;
D 25
		cb->s_timer[TCPT_KEEP] = TCPTV_KEEP;
E 25
I 25
		cb->s_timer[SPPT_KEEP] = SPPTV_KEEP;
E 25
E 22
E 13
		}
		break;
I 13
	/*
	 * This state means that we have heard a response
	 * to our acceptance of their connection
	 * It is probably logically unnecessary in this
	 * implementation.
	 */
D 22
	 case TCPS_SYN_RECEIVED:
E 22
I 22
	 case TCPS_SYN_RECEIVED: {
E 22
		if (si->si_did!=cb->s_sid) {
			spp_istat.wrncon++;
			goto drop;
		}
#endif
		nsp->nsp_fport =  si->si_sport;
D 25
		cb->s_timer[TCPT_REXMT] = 0;
		cb->s_timer[TCPT_KEEP] = TCPTV_KEEP;
E 25
I 25
		cb->s_timer[SPPT_REXMT] = 0;
		cb->s_timer[SPPT_KEEP] = SPPTV_KEEP;
E 25
		soisconnected(so);
		cb->s_state = TCPS_ESTABLISHED;
I 22
		sppstat.spps_accepts++;
		}
E 22
		break;
E 13

	/*
	 * This state means that we have gotten a response
	 * to our attempt to establish a connection.
D 5
	 * We fill in the data from the other side
	 * (Telling which port to send to instead of the well-
	 * known one we might have to in the first place )
E 5
I 5
	 * We fill in the data from the other side,
	 * telling us which port to respond to, instead of the well-
	 * known one we might have sent to in the first place.
E 5
	 * We also require that this is a response to our
D 5
	 * connection id, and that it should be a system packet,
	 * containing no data.
E 5
I 5
	 * connection id.
E 5
	 */
	case TCPS_SYN_SENT:
		if (si->si_did!=cb->s_sid) {
			spp_istat.notme++;
			goto drop;
		}
I 22
		sppstat.spps_connects++;
E 22
		cb->s_did = si->si_sid;
		cb->s_rack = si->si_ack;
		cb->s_ralo = si->si_alo;
		cb->s_dport = nsp->nsp_fport =  si->si_sport;
D 25
		cb->s_timer[TCPT_REXMT] = 0;
E 25
I 25
		cb->s_timer[SPPT_REXMT] = 0;
E 25
D 22
		cb->s_flags |= SF_AK;
E 22
I 22
		cb->s_flags |= SF_ACKNOW;
E 22
		soisconnected(so);
		cb->s_state = TCPS_ESTABLISHED;
I 22
		/* Use roundtrip time of connection request for initial rtt */
		if (cb->s_rtt) {
			cb->s_srtt = cb->s_rtt << 3;
			cb->s_rttvar = cb->s_rtt << 1;
D 25
			TCPT_RANGESET(cb->s_rxtcur,
E 25
I 25
			SPPT_RANGESET(cb->s_rxtcur,
E 25
			    ((cb->s_srtt >> 2) + cb->s_rttvar) >> 1,
D 25
			    TCPTV_MIN, TCPTV_REXMTMAX);
E 25
I 25
			    SPPTV_MIN, SPPTV_REXMTMAX);
E 25
			    cb->s_rtt = 0;
		}
E 22
D 13
		break;
	/*
	 * This state means that we have heard a response
	 * to our acceptance of their connection
	 * It is probably logically unnecessary in this
	 * implementation.
	 */
	 case TCPS_SYN_RECEIVED:
		if (si->si_did!=cb->s_sid) {
			spp_istat.wrncon++;
			goto drop;
		}
		nsp->nsp_fport =  si->si_sport;
		cb->s_timer[TCPT_REXMT] = 0;
		cb->s_timer[TCPT_KEEP] = TCPTV_KEEP;
		soisconnected(so);
		cb->s_state = TCPS_ESTABLISHED;
E 13
	}
	if (so->so_options & SO_DEBUG || traceallspps)
D 7
		spp_trace(SA_INPUT, ostate, cb, &spp_savesi, 0);
E 7
I 7
		spp_trace(SA_INPUT, (u_char)ostate, cb, &spp_savesi, 0);
E 7

	m->m_len -= sizeof (struct idp);
	m->m_off += sizeof (struct idp);

D 15
	if (spp_reass(cb,si)) {
E 15
I 15
	if (spp_reass(cb, si)) {
E 15
D 5
		spp_istat.bdreas++;
E 5
D 18
		goto drop;
E 18
I 18
D 24
		m_freem(m);
E 24
I 24
		(void) m_freem(m);
E 24
E 18
	}
D 7
	spp_output(cb,(struct mbuf *)0);
E 7
I 7
D 15
	(void) spp_output(cb,(struct mbuf *)0);
E 15
I 15
D 22
	(void) spp_output(cb, (struct mbuf *)0);
E 22
I 22
	if (cb->s_force || (cb->s_flags & (SF_ACKNOW|SF_WIN|SF_RXT)))
		(void) spp_output(cb, (struct mbuf *)0);
	cb->s_flags &= ~(SF_WIN|SF_RXT);
E 22
E 15
E 7
	return;

dropwithreset:
	if (dropsocket)
		(void) soabort(so);
	si->si_seq = ntohs(si->si_seq);
	si->si_ack = ntohs(si->si_ack);
	si->si_alo = ntohs(si->si_alo);
	ns_error(dtom(si), NS_ERR_NOSOCK, 0);
	if (cb->s_nspcb->nsp_socket->so_options & SO_DEBUG || traceallspps)
D 7
		spp_trace(SA_DROP, ostate, cb, &spp_savesi, 0);
E 7
I 7
		spp_trace(SA_DROP, (u_char)ostate, cb, &spp_savesi, 0);
E 7
	return;

drop:
bad:
D 5
	if (cb->s_nspcb->nsp_socket->so_options & SO_DEBUG || traceallspps)
E 5
I 5
D 8
	if (cb==0 || cb->s_nspcb->nsp_socket->so_options & SO_DEBUG || traceallspps)
E 8
I 8
D 22
	if (cb == 0 || cb->s_nspcb->nsp_socket->so_options & SO_DEBUG || traceallspps)
E 22
I 22
	if (cb == 0 || cb->s_nspcb->nsp_socket->so_options & SO_DEBUG ||
            traceallspps)
E 22
E 8
E 5
D 7
		spp_trace(SA_DROP, ostate, cb, &spp_savesi, 0);
E 7
I 7
		spp_trace(SA_DROP, (u_char)ostate, cb, &spp_savesi, 0);
E 7
	m_freem(m);
}

I 22
int spprexmtthresh = 3;

E 22
/*
 * This is structurally similar to the tcp reassembly routine
 * but its function is somewhat different:  It merely queues
 * packets up, and suppresses duplicates.
 */
D 15
spp_reass(cb,si)
E 15
I 15
spp_reass(cb, si)
E 15
register struct sppcb *cb;
register struct spidp *si;
{
	register struct spidp_q *q;
	register struct mbuf *m;
D 22
	struct socket *so = cb->s_nspcb->nsp_socket;
	struct sockbuf *sb = & (so->so_rcv);
E 22
I 22
	register struct socket *so = cb->s_nspcb->nsp_socket;
E 22
	char packetp = cb->s_flags & SF_HI;
I 22
	int incr;
E 22
	char wakeup = 0;

D 22

E 22
D 8
	if (si==SI(0))
E 8
I 8
	if (si == SI(0))
E 8
		goto present;
	/*
	 * Update our news from them.
	 */
	if (si->si_cc & SP_SA)
D 15
		cb->s_flags |= SF_DELACK;
	if (SSEQ_GT(si->si_ack,cb->s_rack)) {
E 15
I 15
D 22
		cb->s_flags |= (spp_use_delack ? SF_DELACK : SF_AK);
	if (SSEQ_GT(si->si_ack, cb->s_rack)) {
E 15
		cb->s_rack = si->si_ack;
D 15
		cb->s_timer[TCPT_REXMT] = 0;

E 15
		/*
I 15
		 * If there are other packets outstanding,
		 * restart the timer for them.
		 */
		if (SSEQ_GEQ(cb->s_snt, si->si_ack)) {
			TCPT_RANGESET(cb->s_timer[TCPT_REXMT],
				tcp_beta * cb->s_srtt, TCPTV_MIN,
				TCPTV_MAX);
			cb->s_rxtshift = 0;
E 22
I 22
		cb->s_flags |= (spp_use_delack ? SF_DELACK : SF_ACKNOW);
	if (SSEQ_GT(si->si_alo, cb->s_ralo))
		cb->s_flags |= SF_WIN;
	if (SSEQ_LEQ(si->si_ack, cb->s_rack)) {
D 24
		if ((si->si_cc & SP_SP) && cb->s_rack != cb->s_smax) {
E 24
I 24
		if ((si->si_cc & SP_SP) && cb->s_rack != (cb->s_smax + 1)) {
E 24
			sppstat.spps_rcvdupack++;
			/*
			 * If this is a completely duplicate ack
			 * and other conditions hold, we assume
			 * a packet has been dropped and retransmit
			 * it exactly as in tcp_input().
			 */
			if (si->si_ack != cb->s_rack ||
			    si->si_alo != cb->s_ralo)
				cb->s_dupacks = 0;
			else if (++cb->s_dupacks == spprexmtthresh) {
				u_short onxt = cb->s_snxt;
				int cwnd = cb->s_cwnd;

				cb->s_snxt = si->si_ack;
				cb->s_cwnd = CUNIT;
D 25
				cb->s_force = 1 + TCPT_REXMT;
E 25
I 25
				cb->s_force = 1 + SPPT_REXMT;
E 25
D 24
				(void) spp_output(cb, 0);
E 24
I 24
				(void) spp_output(cb, (struct mbuf *)0);
E 24
D 25
				cb->s_timer[TCPT_REXMT] = cb->s_rxtcur;
E 25
I 25
				cb->s_timer[SPPT_REXMT] = cb->s_rxtcur;
E 25
				cb->s_rtt = 0;
				if (cwnd >= 4 * CUNIT)
					cb->s_cwnd = cwnd / 2;
				if (SSEQ_GT(onxt, cb->s_snxt))
					cb->s_snxt = onxt;
				return (1);
			}
E 22
		} else
D 22
			cb->s_timer[TCPT_REXMT] = 0;
		/*
E 15
		 * If transmit timer is running and timed sequence
		 * number was acked, update smoothed round trip time.
		 */
		if (cb->s_rtt && SSEQ_GT(si->si_ack, cb->s_rtseq)) {
			if (cb->s_srtt == 0)
				cb->s_srtt = cb->s_rtt;
			else
				cb->s_srtt =
				    tcp_alpha * cb->s_srtt +
				    (1 - tcp_alpha) * cb->s_rtt;
			cb->s_rtt = 0;
		}
E 22
I 22
			cb->s_dupacks = 0;
		goto update_window;
E 22
	}
D 15
	if (SSEQ_GT(si->si_alo,cb->s_ralo)) {
E 15
I 15
D 22
	if (SSEQ_GT(si->si_alo, cb->s_ralo)) {
E 15
		cb->s_ralo = si->si_alo;
		cb->s_timer[TCPT_PERSIST] = 0;
E 22
I 22
	cb->s_dupacks = 0;
	/*
	 * If our correspondent acknowledges data we haven't sent
	 * TCP would drop the packet after acking.  We'll be a little
	 * more permissive
	 */
	if (SSEQ_GT(si->si_ack, (cb->s_smax + 1))) {
		sppstat.spps_rcvacktoomuch++;
		si->si_ack = cb->s_smax + 1;
E 22
	}
I 22
	sppstat.spps_rcvackpack++;
E 22
	/*
D 22
	 * If this is a system packet, we don't need to
	 * queue it up, and won't update acknowledge #
E 22
I 22
	 * If transmit timer is running and timed sequence
	 * number was acked, update smoothed round trip time.
	 * See discussion of algorithm in tcp_input.c
E 22
	 */
D 4
	if (si->si_cc & SP_SP)
E 4
I 4
D 22
	if (si->si_cc & SP_SP) {
		m_freem(dtom(si));
E 4
D 3
		return(0);
E 3
I 3
		return (0);
E 22
I 22
	if (cb->s_rtt && SSEQ_GT(si->si_ack, cb->s_rtseq)) {
		sppstat.spps_rttupdated++;
		if (cb->s_srtt != 0) {
			register short delta;
			delta = cb->s_rtt - (cb->s_srtt >> 3);
			if ((cb->s_srtt += delta) <= 0)
				cb->s_srtt = 1;
			if (delta < 0)
				delta = -delta;
			delta -= (cb->s_rttvar >> 2);
			if ((cb->s_rttvar += delta) <= 0)
				cb->s_rttvar = 1;
		} else {
			/*
			 * No rtt measurement yet
			 */
			cb->s_srtt = cb->s_rtt << 3;
			cb->s_rttvar = cb->s_rtt << 1;
		}
		cb->s_rtt = 0;
		cb->s_rxtshift = 0;
D 25
		TCPT_RANGESET(cb->s_rxtcur,
E 25
I 25
		SPPT_RANGESET(cb->s_rxtcur,
E 25
			((cb->s_srtt >> 2) + cb->s_rttvar) >> 1,
D 25
			TCPTV_MIN, TCPTV_REXMTMAX);
E 25
I 25
			SPPTV_MIN, SPPTV_REXMTMAX);
E 25
E 22
I 4
	}
E 4
E 3
D 22

E 22
	/*
D 22
	 * If this packet number has a sequence number less
	 * than that of the first packet not yet seen coming
	 * from them, this must be a duplicate, so drop.
E 22
I 22
	 * If all outstanding data is acked, stop retransmit
	 * timer and remember to restart (more output or persist).
	 * If there is more data to be acked, restart retransmit
	 * timer, using current (possibly backed-off) value;
E 22
	 */
D 5
	if (SSEQ_LT(si->si_seq,cb->s_ack))
E 5
I 5
D 15
	if (SSEQ_LT(si->si_seq,cb->s_ack)) {
E 15
I 15
D 22
	if (SSEQ_LT(si->si_seq, cb->s_ack)) {
E 15
		spp_istat.bdreas++;
D 8
		if (si->si_seq==cb->s_ack-1)
E 8
I 8
		if (si->si_seq == cb->s_ack-1)
E 8
			spp_istat.lstdup++;
E 5
D 3
		return(1);
E 3
I 3
		return (1);
E 22
I 22
	if (si->si_ack == cb->s_smax + 1) {
D 25
		cb->s_timer[TCPT_REXMT] = 0;
E 25
I 25
		cb->s_timer[SPPT_REXMT] = 0;
E 25
		cb->s_flags |= SF_RXT;
D 25
	} else if (cb->s_timer[TCPT_PERSIST] == 0)
		cb->s_timer[TCPT_REXMT] = cb->s_rxtcur;
E 25
I 25
	} else if (cb->s_timer[SPPT_PERSIST] == 0)
		cb->s_timer[SPPT_REXMT] = cb->s_rxtcur;
E 25
	/*
	 * When new data is acked, open the congestion window.
	 * If the window gives us less than ssthresh packets
	 * in flight, open exponentially (maxseg at a time).
	 * Otherwise open linearly (maxseg^2 / cwnd at a time).
	 */
	incr = CUNIT;
	if (cb->s_cwnd > cb->s_ssthresh)
		incr = MAX(incr * incr / cb->s_cwnd, 1);
	cb->s_cwnd = MIN(cb->s_cwnd + incr, cb->s_cwmx);
	/*
	 * Trim Acked data from output queue.
	 */
D 24
	for (m = so->so_snd.sb_mb; m; m = m->m_act) {
E 24
I 24
	while ((m = so->so_snd.sb_mb) != NULL) {
E 24
		if (SSEQ_LT((mtod(m, struct spidp *))->si_seq, si->si_ack))
			sbdroprecord(&so->so_snd);
		else
			break;
E 22
I 5
	}
I 22
	if ((so->so_snd.sb_flags & SB_WAIT) || so->so_snd.sb_sel)
		 sowwakeup(so);
	cb->s_rack = si->si_ack;
update_window:
	if (SSEQ_LT(cb->s_snxt, cb->s_rack))
		cb->s_snxt = cb->s_rack;
	if (SSEQ_LT(cb->s_swl1, si->si_seq) || cb->s_swl1 == si->si_seq &&
	    (SSEQ_LT(cb->s_swl2, si->si_ack) ||
	     cb->s_swl2 == si->si_ack && SSEQ_LT(cb->s_ralo, si->si_alo))) {
		/* keep track of pure window updates */
		if ((si->si_cc & SP_SP) && cb->s_swl2 == si->si_ack
		    && SSEQ_LT(cb->s_ralo, si->si_alo)) {
			sppstat.spps_rcvwinupd++;
			sppstat.spps_rcvdupack--;
		}
		cb->s_ralo = si->si_alo;
		cb->s_swl1 = si->si_seq;
		cb->s_swl2 = si->si_ack;
		cb->s_swnd = (1 + si->si_alo - si->si_ack);
		if (cb->s_swnd > cb->s_smxw)
			cb->s_smxw = cb->s_swnd;
		cb->s_flags |= SF_WIN;
	}
E 22
E 5
E 3
	/*
	 * If this packet number is higher than that which
	 * we have allocated refuse it, unless urgent
	 */
D 15
	if (SSEQ_GT(si->si_seq,cb->s_alo) && (!(si->si_cc & SP_OB))) {
I 5
		spp_istat.notyet++;
E 5
D 3
		return(1);
E 3
I 3
		return (1);
E 15
I 15
	if (SSEQ_GT(si->si_seq, cb->s_alo)) {
I 22
		if (si->si_cc & SP_SP) {
			sppstat.spps_rcvwinprobe++;
			return (1);
		} else
			sppstat.spps_rcvpackafterwin++;
E 22
		if (si->si_cc & SP_OB) {
			if (SSEQ_GT(si->si_seq, cb->s_alo + 60)) {
				ns_error(dtom(si), NS_ERR_FULLUP, 0);
				return (0);
			} /* else queue this packet; */
		} else {
I 22
			/*register struct socket *so = cb->s_nspcb->nsp_socket;
			if (so->so_state && SS_NOFDREF) {
				ns_error(dtom(si), NS_ERR_NOSOCK, 0);
				(void)spp_close(cb);
			} else
				       would crash system*/
E 22
			spp_istat.notyet++;
D 22
			return (1);
E 22
I 22
			ns_error(dtom(si), NS_ERR_FULLUP, 0);
			return (0);
E 22
		}
E 15
E 3
	}
D 15
	/*
	 * If this packet is urgent, inform process
	 */
	if (si->si_cc & SP_OB) {
		cb->s_iobc = ((char *)si)[1 + sizeof(*si)];
		sohasoutofband(so);
	}
E 15
D 22

E 22
	/*
I 22
	 * If this is a system packet, we don't need to
	 * queue it up, and won't update acknowledge #
	 */
	if (si->si_cc & SP_SP) {
		return (1);
	}
	/*
	 * We have already seen this packet, so drop.
	 */
	if (SSEQ_LT(si->si_seq, cb->s_ack)) {
		spp_istat.bdreas++;
		sppstat.spps_rcvduppack++;
		if (si->si_seq == cb->s_ack - 1)
			spp_istat.lstdup++;
		return (1);
	}
	/*
E 22
	 * Loop through all packets queued up to insert in
	 * appropriate sequence.
	 */
D 22

E 22
	for (q = cb->s_q.si_next; q!=&cb->s_q; q = q->si_next) {
D 3
	    if (si->si_seq==SI(q)->si_seq) return(1); /*duplicate */
E 3
I 3
D 8
	    if (si->si_seq==SI(q)->si_seq) return (1); /*duplicate */
E 8
I 8
D 22
	    if (si->si_seq == SI(q)->si_seq) return (1); /*duplicate */
E 8
E 3
D 15
	    if (SSEQ_LT(si->si_seq,SI(q)->si_seq)) break;
E 15
I 15
	    if (SSEQ_LT(si->si_seq, SI(q)->si_seq)) break;
E 22
I 22
		if (si->si_seq == SI(q)->si_seq) {
			sppstat.spps_rcvduppack++;
			return (1);
		}
		if (SSEQ_LT(si->si_seq, SI(q)->si_seq)) {
			sppstat.spps_rcvoopack++;
			break;
		}
E 22
E 15
	}
D 15
	insque(si,q->si_prev);
		
E 15
I 15
	insque(si, q->si_prev);
	/*
	 * If this packet is urgent, inform process
	 */
	if (si->si_cc & SP_OB) {
		cb->s_iobc = ((char *)si)[1 + sizeof(*si)];
		sohasoutofband(so);
		cb->s_oobflags |= SF_IOOB;
	}
E 15
present:
#define SPINC sizeof(struct sphdr)
	/*
	 * Loop through all packets queued up to update acknowledge
	 * number, and present all acknowledged data to user;
	 * If in packet interface mode, show packet headers.
	 */
	for (q = cb->s_q.si_next; q!=&cb->s_q; q = q->si_next) {
D 8
		  if (SI(q)->si_seq==cb->s_ack) {
E 8
I 8
		  if (SI(q)->si_seq == cb->s_ack) {
E 8
			cb->s_ack++;
			m = dtom(q);
			if (SI(q)->si_cc & SP_OB) {
I 15
				cb->s_oobflags &= ~SF_IOOB;
E 15
D 22
				if (sb->sb_cc)
					so->so_oobmark = sb->sb_cc;
E 22
I 22
				if (so->so_rcv.sb_cc)
					so->so_oobmark = so->so_rcv.sb_cc;
E 22
				else
					so->so_state |= SS_RCVATMARK;
			}
			q = q->si_prev;
			remque(q->si_next);
			wakeup = 1;
I 22
			sppstat.spps_rcvpack++;
E 22
			if (packetp) {
D 15
				sbappendrecord(sb,m);
E 15
I 15
D 22
				sbappendrecord(sb, m);
E 22
I 22
				sbappendrecord(&so->so_rcv, m);
E 22
E 15
			} else {
				cb->s_rhdr = *mtod(m, struct sphdr *);
				m->m_off += SPINC;
				m->m_len -= SPINC;
D 15
				sbappend(sb,m);
E 15
I 15
D 22
				sbappend(sb, m);
E 22
I 22
				sbappend(&so->so_rcv, m);
E 22
E 15
			}
		  } else
			break;
	}
	if (wakeup) sorwakeup(so);
D 3
	return(0);
E 3
I 3
	return (0);
E 3
}

spp_ctlinput(cmd, arg)
	int cmd;
	caddr_t arg;
{
	struct ns_addr *na;
	extern u_char nsctlerrmap[];
D 22
	extern spp_abort();
E 22
I 22
	extern spp_abort(), spp_quench();
E 22
I 7
	extern struct nspcb *idp_drop();
E 7
I 5
	struct ns_errp *errp;
	struct nspcb *nsp;
I 12
	struct sockaddr_ns *sns;
E 12
E 5
	int type;

	if (cmd < 0 || cmd > PRC_NCMDS)
		return;
	type = NS_ERR_UNREACH_HOST;

	switch (cmd) {
I 3

E 3
	case PRC_ROUTEDEAD:
D 22
	case PRC_QUENCH:
		break;
E 22
I 22
		return;
E 22

	case PRC_IFDOWN:
D 12
		na = &((struct sockaddr_ns *)arg)->sns_addr;
		break;

E 12
	case PRC_HOSTDEAD:
	case PRC_HOSTUNREACH:
D 12
		na = (struct ns_addr *)arg;
E 12
I 12
		sns = (struct sockaddr_ns *)arg;
		if (sns->sns_family != AF_NS)
			return;
		na = &sns->sns_addr;
E 12
		break;

	default:
D 5
		na = &((struct ns_errp *)arg)->ns_err_idp.idp_dna;
		type = ((struct ns_errp *)arg)->ns_err_num;
E 5
I 5
		errp = (struct ns_errp *)arg;
		na = &errp->ns_err_idp.idp_dna;
		type = errp->ns_err_num;
E 5
D 7
		type = ntohs(type);
E 7
I 7
		type = ntohs((u_short)type);
E 7
	}
	switch (type) {
I 3

E 3
	case NS_ERR_UNREACH_HOST:
D 5
	case NS_ERR_NOSOCK:
		ns_pcbnotify(na, (int)nsctlerrmap[cmd],
				spp_abort, (long) 0);
E 5
I 5
		ns_pcbnotify(na, (int)nsctlerrmap[cmd], spp_abort, (long) 0);
E 5
		break;
I 3

E 3
	case NS_ERR_TOO_BIG:
D 5
		ns_pcbnotify(na, 0, spp_abort, (long)arg);
E 5
I 5
	case NS_ERR_NOSOCK:
		nsp = ns_pcblookup(na, errp->ns_err_idp.idp_sna.x_port,
			NS_WILDCARD);
		if (nsp) {
			if(nsp->nsp_pcb)
D 7
				spp_drop(nsp->nsp_pcb, (int)nsctlerrmap[cmd]);
E 7
I 7
				(void) spp_drop((struct sppcb *)nsp->nsp_pcb,
						(int)nsctlerrmap[cmd]);
E 7
			else
D 7
				idp_drop(nsp, (int)nsctlerrmap[cmd]);
E 7
I 7
				(void) idp_drop(nsp, (int)nsctlerrmap[cmd]);
E 7
		}
I 22
		break;

	case NS_ERR_FULLUP:
		ns_pcbnotify(na, 0, spp_quench, (long) 0);
E 22
E 5
	}
}
I 22
/*
 * When a source quench is received, close congestion window
 * to one packet.  We will gradually open it again as we proceed.
 */
spp_quench(nsp)
	struct nspcb *nsp;
{
	struct sppcb *cb = nstosppcb(nsp);
E 22

I 22
	if (cb)
		cb->s_cwnd = CUNIT;
}

E 22
I 7
#ifdef notdef
E 7
int
spp_fixmtu(nsp)
register struct nspcb *nsp;
{
	register struct sppcb *cb = (struct sppcb *)(nsp->nsp_pcb);
	register struct mbuf *m;
	register struct spidp *si;
	struct ns_errp *ep;
	struct sockbuf *sb;
	int badseq, len;
	struct mbuf *firstbad, *m0;

	if (cb) {
		/* 
		 * The notification that we have sent
		 * too much is bad news -- we will
		 * have to go through queued up so far
		 * splitting ones which are too big and
		 * reassigning sequence numbers and checksums.
		 * we should then retransmit all packets from
		 * one above the offending packet to the last one
		 * we had sent (or our allocation)
		 * then the offending one so that the any queued
		 * data at our destination will be discarded.
		 */
		 ep = (struct ns_errp *)nsp->nsp_notify_param;
		 sb = &nsp->nsp_socket->so_snd;
		 cb->s_mtu = ep->ns_err_param;
		 badseq = SI(&ep->ns_err_idp)->si_seq;
		 for (m = sb->sb_mb; m; m = m->m_act) {
			si = mtod(m, struct spidp *);
			if (si->si_seq == badseq)
				break;
		 }
D 8
		 if (m==0) return;
E 8
I 8
		 if (m == 0) return;
E 8
		 firstbad = m;
		 /*for (;;) {*/
			/* calculate length */
			for (m0 = m, len = 0; m ; m = m->m_next)
				len += m->m_len;
			if (len > cb->s_mtu) {
			}
		/* FINISH THIS
		} */
	}
}
I 7
#endif
E 7

D 22
int spp_output_cnt = 0;
I 5

E 22
E 5
spp_output(cb, m0)
	register struct sppcb *cb;
	struct mbuf *m0;
{
	struct socket *so = cb->s_nspcb->nsp_socket;
	register struct mbuf *m;
	register struct spidp *si = (struct spidp *) 0;
D 22
	register struct sockbuf *sb = &(so->so_snd);
	register int len = 0;
D 7
	int flags, debit, mtu = cb->s_mtu;
E 7
I 7
D 12
	int mtu = cb->s_mtu;
E 12
E 7
D 8
	int error = 0; u_short lookfor = 0;
E 8
I 8
	int error = 0;
E 22
I 22
	register struct sockbuf *sb = &so->so_snd;
	int len = 0, win, rcv_win;
	short span, off;
D 24
	u_short alo, oalo;
E 24
I 24
	u_short alo;
E 24
D 26
	int error = 0, idle, sendalot;
E 26
I 26
	int error = 0, sendalot;
#ifdef notdef
	int idle;
#endif
E 26
E 22
D 24
	u_short lookfor = 0;
E 24
E 8
	struct mbuf *mprev;
	extern int idpcksum;

D 8
	if (m0)
	{
E 8
I 8
	if (m0) {
I 12
		int mtu = cb->s_mtu;
		int datalen;
		/*
		 * Make sure that packet isn't too big.
		 */
E 12
E 8
		for (m = m0; m ; m = m->m_next) {
			mprev = m;
			len += m->m_len;
		}
D 12
		if (len > mtu) {
E 12
I 12
		datalen = (cb->s_flags & SF_HO) ?
				len - sizeof (struct sphdr) : len;
		if (datalen > mtu) {
E 12
			if (cb->s_flags & SF_PI) {
				m_freem(m0);
D 3
				return(EMSGSIZE);
E 3
I 3
				return (EMSGSIZE);
E 3
			} else {
D 24
				int off = 0;
E 24
I 12
				int oldEM = cb->s_cc & SP_EM;

				cb->s_cc &= ~SP_EM;
E 12
				while (len > mtu) {
D 24
					m = m_copy(m0, off, mtu);
E 24
I 24
					m = m_copy(m0, 0, mtu);
E 24
I 3
D 8
					if (m==NULL) {
E 8
I 8
					if (m == NULL) {
E 8
D 12
						m_freem(m0);
						return (ENOBUFS);
E 12
I 12
						error = ENOBUFS;
						goto bad_copy;
E 12
					}
E 3
					error = spp_output(cb, m);
					if (error) {
I 12
					bad_copy:
						cb->s_cc |= oldEM;
E 12
						m_freem(m0);
D 3
						return(error);
E 3
I 3
D 12
						return (error);
E 12
I 12
						return(error);
E 12
E 3
					}
					m_adj(m0, mtu);
					len -= mtu;
				}
I 12
				cb->s_cc |= oldEM;
E 12
			}
		}
I 8
		/*
		 * Force length even, by adding a "garbage byte" if
		 * necessary.
		 */
E 8
		if (len & 1) {
I 5
			m = mprev;
E 5
D 8
			if (m->m_len + m->m_off < MMAXOFF) {
E 8
I 8
			if (m->m_len + m->m_off < MMAXOFF)
E 8
				m->m_len++;
D 8
			} else {
E 8
I 8
			else {
E 8
				struct mbuf *m1 = m_get(M_DONTWAIT, MT_DATA);

				if (m1 == 0) {
					m_freem(m0);
					return (ENOBUFS);
				}
				m1->m_len = 1;
				m1->m_off = MMAXOFF - 1;
D 8
				mprev->m_next = m1;
E 8
I 8
				m->m_next = m1;
E 8
			}
		}
		m = m_get(M_DONTWAIT, MT_HEADER);
		if (m == 0) {
			m_freem(m0);
D 3
			return(ENOBUFS);
E 3
I 3
			return (ENOBUFS);
E 3
		}
D 12

E 12
		/*
		 * Fill in mbuf with extended SP header
		 * and addresses and length put into network format.
I 19
		 * Long align so prepended ip headers will work on Gould.
E 19
		 */
D 19
		m->m_off = MMAXOFF - sizeof (struct spidp);
E 19
I 19
		m->m_off = MMAXOFF - sizeof (struct spidp) - 2;
E 19
		m->m_len = sizeof (struct spidp);
		m->m_next = m0;
		si = mtod(m, struct spidp *);
D 22
		*si = cb->s_shdr;
E 22
I 22
		si->si_i = *cb->s_idp;
		si->si_s = cb->s_shdr;
E 22
		if ((cb->s_flags & SF_PI) && (cb->s_flags & SF_HO)) {
D 8
			register struct sphdr *sh = mtod(m0, struct sphdr *);
E 8
I 8
			register struct sphdr *sh;
			if (m0->m_len < sizeof (*sh)) {
				if((m0 = m_pullup(m0, sizeof(*sh))) == NULL) {
					(void) m_free(m);
					m_freem(m0);
					return (EINVAL);
				}
				m->m_next = m0;
			}
			sh = mtod(m0, struct sphdr *);
E 8
			si->si_dt = sh->sp_dt;
			si->si_cc |= sh->sp_cc & SP_EM;
			m0->m_len -= sizeof (*sh);
			m0->m_off += sizeof (*sh);
			len -= sizeof (*sh);
		}
		len += sizeof(*si);
I 5
		if (cb->s_oobflags & SF_SOOB) {
			/*
			 * Per jqj@cornell:
			 * make sure OB packets convey exactly 1 byte.
			 * If the packet is 1 byte or larger, we
			 * have already guaranted there to be at least
			 * one garbage byte for the checksum, and
			 * extra bytes shouldn't hurt!
D 8
			 * 
E 8
			 */
			if (len > sizeof(*si)) {
				si->si_cc |= SP_OB;
				len = (1 + sizeof(*si));
			}
		}
E 5
D 7
		si->si_len = htons(len);
E 7
I 7
		si->si_len = htons((u_short)len);
E 7
		/*
		 * queue stuff up for output
		 */
D 15
		sbappendrecord(sb,m);
E 15
I 15
		sbappendrecord(sb, m);
E 15
		cb->s_seq++;
	}
I 26
#ifdef notdef
E 26
I 22
	idle = (cb->s_smax == (cb->s_rack - 1));
I 26
#endif
E 26
again:
	sendalot = 0;
	off = cb->s_snxt - cb->s_rack;
	win = MIN(cb->s_swnd, (cb->s_cwnd/CUNIT));

E 22
D 7
output:
E 7
	/*
D 22
	 * update window
E 22
I 22
	 * If in persist timeout with window of 0, send a probe.
	 * Otherwise, if window is small but nonzero
	 * and timer expired, send what we can and go into
	 * transmit state.
E 22
	 */
D 22
	{
D 7
		register struct sockbuf *sb = &so->so_rcv;
		int credit = ((sb->sb_mbmax - sb->sb_mbcnt) / cb->s_mtu);
E 7
I 7
		register struct sockbuf *sb2 = &so->so_rcv;
D 13
		int credit = ((sb2->sb_mbmax - sb2->sb_mbcnt) / cb->s_mtu);
E 7
		int alo = cb->s_ack + credit;
E 13
I 13
D 19
		int credit = ((sb2->sb_mbmax - sb2->sb_mbcnt) /
E 19
I 19
		int credit = ((((int)sb2->sb_mbmax) - (int)sb2->sb_mbcnt) /
E 19
						((short)cb->s_mtu));
		int alo = cb->s_ack + (credit > 0 ? credit : 0) - 1;
E 22
I 22
D 25
	if (cb->s_force == 1 + TCPT_PERSIST) {
E 25
I 25
	if (cb->s_force == 1 + SPPT_PERSIST) {
E 25
		if (win != 0) {
D 25
			cb->s_timer[TCPT_PERSIST] = 0;
E 25
I 25
			cb->s_timer[SPPT_PERSIST] = 0;
E 25
			cb->s_rxtshift = 0;
		}
	}
	span = cb->s_seq - cb->s_rack;
	len = MIN(span, win) - off;
E 22
E 13

D 8
		if (cb->s_alo < alo) cb->s_alo = alo;
E 8
I 8
D 13
		if (cb->s_alo < alo)
E 13
I 13
D 22
		if (cb->s_alo < alo) {
			/* If the amount we are raising the window
			   is more than his remaining headroom, tell
			   him about it.  In particular, if he is at
			   his limit, any amount at all will do! */
			u_short raise = alo - cb->s_alo;
			u_short headroom = 1 + cb->s_alo - cb->s_ack;

			if(SSEQ_LT(headroom, raise))
				cb->s_flags |= SF_AK;
E 13
			cb->s_alo = alo;
E 22
I 22
	if (len < 0) {
		/*
		 * Window shrank after we went into it.
		 * If window shrank to 0, cancel pending
		 * restransmission and pull s_snxt back
		 * to (closed) window.  We will enter persist
		 * state below.  If the widndow didn't close completely,
		 * just wait for an ACK.
		 */
		len = 0;
		if (win == 0) {
D 25
			cb->s_timer[TCPT_REXMT] = 0;
E 25
I 25
			cb->s_timer[SPPT_REXMT] = 0;
E 25
			cb->s_snxt = cb->s_rack;
E 22
I 13
		}
E 13
E 8
	}
I 22
	if (len > 1)
		sendalot = 1;
	rcv_win = sbspace(&so->so_rcv);
E 22

I 22
	/*
	 * Send if we owe peer an ACK.
	 */
E 22
	if (cb->s_oobflags & SF_SOOB) {
		/*
		 * must transmit this out of band packet
		 */
		cb->s_oobflags &= ~ SF_SOOB;
D 22
	} else {
		/*
		 * Decide what to transmit:
D 16
		 * If we have a new packet, send that
		 * (So long as it is in our allocation)
E 16
		 * If it is time to retransmit a packet,
		 * send that.
I 16
		 * If we have a new packet, send that
		 * (So long as it is in our allocation)
E 16
		 * Otherwise, see if it time to bang on them
		 * to ask for our current allocation.
		 */
D 16
		if (SSEQ_LT(cb->s_snt, cb->s_ralo))
			lookfor = cb->s_snt + 1;
D 8
		else if (cb->s_force==(1+TCPT_REXMT)) {
E 8
I 8
		else if (cb->s_force == (1+TCPT_REXMT)) {
E 16
I 16
		if (cb->s_force == (1+TCPT_REXMT)) {
E 16
E 8
			lookfor = cb->s_rack;
I 16
		} else if (SSEQ_LT(cb->s_snt, cb->s_ralo)) {
			lookfor = cb->s_snt + 1;
E 16
		} else if (SSEQ_LT(cb->s_ralo, cb->s_seq)) {
			lookfor = 0;
D 8
			if (cb->s_timer[TCPT_PERSIST]==0) {
E 8
I 8
			if (cb->s_timer[TCPT_PERSIST] == 0) {
E 8
				spp_setpersist(cb);
I 8
				/* tcp has cb->s_rxtshift = 0; here */
E 8
			}
E 22
I 22
		sendalot = 1;
		sppstat.spps_sndurg++;
		goto found;
	}
	if (cb->s_flags & SF_ACKNOW)
		goto send;
	if (cb->s_state < TCPS_ESTABLISHED)
		goto send;
	/*
	 * Silly window can't happen in spp.
	 * Code from tcp deleted.
	 */
	if (len)
		goto send;
	/*
	 * Compare available window to amount of window
	 * known to peer (as advertised window less
	 * next expected input.)  If the difference is at least two
	 * packets or at least 35% of the mximum possible window,
	 * then want to send a window update to peer.
	 */
	if (rcv_win > 0) {
		u_short delta =  1 + cb->s_alo - cb->s_ack;
		int adv = rcv_win - (delta * cb->s_mtu);
		
		if ((so->so_rcv.sb_cc == 0 && adv >= (2 * cb->s_mtu)) ||
		    (100 * adv / so->so_rcv.sb_hiwat >= 35)) {
			sppstat.spps_sndwinup++;
			cb->s_flags |= SF_ACKNOW;
			goto send;
E 22
		}
D 22
		m = sb->sb_mb;
D 8
		while( m ) {
E 8
I 8
		while (m) {
E 22
I 22

	}
	/*
	 * Many comments from tcp_output.c are appropriate here
	 * including . . .
	 * If send window is too small, there is data to transmit, and no
	 * retransmit or persist is pending, then go to persist state.
	 * If nothing happens soon, send when timer expires:
	 * if window is nonzero, transmit what we can,
	 * otherwise send a probe.
	 */
D 25
	if (so->so_snd.sb_cc && cb->s_timer[TCPT_REXMT] == 0 &&
		cb->s_timer[TCPT_PERSIST] == 0) {
E 25
I 25
	if (so->so_snd.sb_cc && cb->s_timer[SPPT_REXMT] == 0 &&
		cb->s_timer[SPPT_PERSIST] == 0) {
E 25
			cb->s_rxtshift = 0;
			spp_setpersist(cb);
	}
	/*
	 * No reason to send a packet, just return.
	 */
	cb->s_outx = 1;
	return (0);

send:
	/*
	 * Find requested packet.
	 */
	si = 0;
	if (len > 0) {
		cb->s_want = cb->s_snxt;
		for (m = sb->sb_mb; m; m = m->m_act) {
E 22
E 8
			si = mtod(m, struct spidp *);
D 22
			m = m->m_act;
			if (SSEQ_LT(si->si_seq, cb->s_rack)) {
				if ((sb->sb_flags & SB_WAIT)
				     || so->so_snd.sb_sel)
					 sowwakeup(so);
				sbdroprecord(sb);
				si = 0;
				continue;
			} 
			if (SSEQ_LT(si->si_seq, lookfor))
				continue;
			break;
E 22
I 22
			if (SSEQ_LEQ(cb->s_snxt, si->si_seq))
				break;
E 22
		}
D 8
		if (si && (si->si_seq != lookfor)) si = 0;
E 8
I 8
D 22
		if (si && (si->si_seq != lookfor))
			si = 0;
E 22
I 22
	found:
		if (si) {
			if (si->si_seq == cb->s_snxt)
					cb->s_snxt++;
				else
					sppstat.spps_sndvoid++, si = 0;
		}
E 22
E 8
	}
D 22
	cb->s_want = lookfor;
E 22
I 22
	/*
	 * update window
	 */
	if (rcv_win < 0)
		rcv_win = 0;
D 24
	oalo = alo = cb->s_ack - 1 + (rcv_win / ((short)cb->s_mtu));
E 24
I 24
	alo = cb->s_ack - 1 + (rcv_win / ((short)cb->s_mtu));
E 24
	if (SSEQ_LT(alo, cb->s_alo)) 
		alo = cb->s_alo;
E 22

	if (si) {
		/*
		 * must make a copy of this packet for
		 * idp_output to monkey with
		 */
D 8
		 m = dtom(si);
D 3
		 m0 = m_copy(m, 0, M_COPYALL);
		 m = m0;
E 3
I 3
D 7
		 m = m_copy(m, 0, M_COPYALL);
E 7
I 7
		 m = m_copy(m, 0, (int)M_COPYALL);
E 7
		 if (m==NULL)
E 8
I 8
D 22
		 m = m_copy(dtom(si), 0, (int)M_COPYALL);
		 if (m == NULL)
E 22
I 22
		m = m_copy(dtom(si), 0, (int)M_COPYALL);
		if (m == NULL) {
E 22
E 8
			return (ENOBUFS);
D 22
		 m0 = m;
E 3
		 si = mtod(m, struct spidp *);
	} else if (cb->s_force || cb->s_flags & SF_AK) {
E 22
I 22
		}
		m0 = m;
		si = mtod(m, struct spidp *);
		if (SSEQ_LT(si->si_seq, cb->s_smax))
			sppstat.spps_sndrexmitpack++;
		else
			sppstat.spps_sndpack++;
	} else if (cb->s_force || cb->s_flags & SF_ACKNOW) {
E 22
		/*
		 * Must send an acknowledgement or a probe
		 */
I 22
		if (cb->s_force)
			sppstat.spps_sndprobe++;
		if (cb->s_flags & SF_ACKNOW)
			sppstat.spps_sndacks++;
E 22
		m = m_get(M_DONTWAIT, MT_HEADER);
D 22
		if (m == 0)
E 22
I 22
		if (m == 0) {
E 22
D 3
			return(ENOBUFS);
E 3
I 3
			return (ENOBUFS);
I 22
		}
E 22
E 3
		/*
		 * Fill in mbuf with extended SP header
		 * and addresses and length put into network format.
I 22
		 * Allign beginning of packet to long to prepend
		 * ifp's on loopback, or NSIP encaspulation for fussy cpu's.
E 22
		 */
D 22
		m->m_off = MMAXOFF - sizeof (struct spidp);
E 22
I 22
		m->m_off = MMAXOFF - sizeof (struct spidp) - 2;
E 22
		m->m_len = sizeof (*si);
		m->m_next = 0;
		si = mtod(m, struct spidp *);
D 22
		*si = cb->s_shdr;
		si->si_seq = cb->s_snt + 1;
E 22
I 22
		si->si_i = *cb->s_idp;
		si->si_s = cb->s_shdr;
		si->si_seq = cb->s_smax + 1;
E 22
D 5
		len = sizeof (*si);
		si->si_len = htons((u_short)len);
E 5
I 5
		si->si_len = htons(sizeof (*si));
E 5
		si->si_cc |= SP_SP;
I 22
	} else {
		cb->s_outx = 3;
		if (so->so_options & SO_DEBUG || traceallspps)
			spp_trace(SA_OUTPUT, cb->s_state, cb, si, 0);
		return (0);
E 22
D 15
		cb->s_flags &= ~SF_AK;
E 15
	}
	/*
	 * Stuff checksum and output datagram.
	 */
D 22
	if (si) {
I 15
		if (cb->s_flags & (SF_AK|SF_DELACK))
			cb->s_flags &= ~(SF_AK|SF_DELACK);
E 15
		/*
		 * If we are almost out of allocation
		 * or one of the timers has gone off
		 * request an ack.
		 */
D 8
		if (SSEQ_GEQ(cb->s_seq,cb->s_ralo))
E 8
I 8
		if (SSEQ_GEQ(cb->s_seq, cb->s_ralo))
E 8
			si->si_cc |= SP_SA;
		if (cb->s_force) {
			si->si_cc |= SP_SA;
			cb->s_force = 0;
		}
D 5
		/* if this is a new packet (and not a system packet)
		 * and we are not currently timing anything
		 * time this one and ask for an ack
E 5
I 5
D 8
		/* If this is a new packet (and not a system packet),
E 8
I 8
		/*
		 * If this is a new packet (and not a system packet),
E 8
		 * and we are not currently timing anything,
		 * time this one and ask for an ack.
E 5
		 */
D 8
		if (SSEQ_LT(cb->s_snt,si->si_seq) &&
		   (!(si->si_cc & SP_SP))) {
E 8
I 8
		if (SSEQ_LT(cb->s_snt, si->si_seq) && (!(si->si_cc & SP_SP))) {
E 8
			cb->s_snt = si->si_seq;
D 8
			if (cb->s_rtt==0) {
E 8
I 8
			if (cb->s_rtt == 0) {
E 8
				cb->s_rtseq = si->si_seq;
				cb->s_rtt = 1;
				si->si_cc |= SP_SA;
E 22
I 22
	if ((si->si_cc & SP_SP) == 0) {
D 25
		if (cb->s_force != (1 + TCPT_PERSIST) ||
		    cb->s_timer[TCPT_PERSIST] == 0) {
E 25
I 25
		if (cb->s_force != (1 + SPPT_PERSIST) ||
		    cb->s_timer[SPPT_PERSIST] == 0) {
E 25
			/*
			 * If this is a new packet and we are not currently 
			 * timing anything, time this one.
			 */
			if (SSEQ_LT(cb->s_smax, si->si_seq)) {
				cb->s_smax = si->si_seq;
				if (cb->s_rtt == 0) {
					sppstat.spps_segstimed++;
					cb->s_rtseq = si->si_seq;
					cb->s_rtt = 1;
				}
E 22
			}
			/*
D 22
			 * If the retransmit timer has not been set
			 * and this is a real packet
			 * then start the retransmit timer
E 22
I 22
			 * Set rexmt timer if not currently set,
			 * Initial value for retransmit timer is smoothed
			 * round-trip time + 2 * round-trip time variance.
			 * Initialize shift counter which is used for backoff
			 * of retransmit time.
E 22
			 */
D 8
			if (cb->s_timer[TCPT_REXMT]==0) {
E 8
I 8
D 22
			if (cb->s_timer[TCPT_REXMT] == 0) {
E 8
				TCPT_RANGESET(cb->s_timer[TCPT_REXMT],
					tcp_beta * cb->s_srtt, TCPTV_MIN,
					TCPTV_MAX);
				cb->s_rxtshift = 0;
E 22
I 22
D 25
			if (cb->s_timer[TCPT_REXMT] == 0 &&
E 25
I 25
			if (cb->s_timer[SPPT_REXMT] == 0 &&
E 25
			    cb->s_snxt != cb->s_rack) {
D 25
				cb->s_timer[TCPT_REXMT] = cb->s_rxtcur;
				if (cb->s_timer[TCPT_PERSIST]) {
					cb->s_timer[TCPT_PERSIST] = 0;
E 25
I 25
				cb->s_timer[SPPT_REXMT] = cb->s_rxtcur;
				if (cb->s_timer[SPPT_PERSIST]) {
					cb->s_timer[SPPT_PERSIST] = 0;
E 25
					cb->s_rxtshift = 0;
				}
E 22
			}
I 22
		} else if (SSEQ_LT(cb->s_smax, si->si_seq)) {
			cb->s_smax = si->si_seq;
E 22
		}
I 22
	} else if (cb->s_state < TCPS_ESTABLISHED) {
		if (cb->s_rtt == 0)
			cb->s_rtt = 1; /* Time initial handshake */
D 25
		if (cb->s_timer[TCPT_REXMT] == 0)
			cb->s_timer[TCPT_REXMT] = cb->s_rxtcur;
E 25
I 25
		if (cb->s_timer[SPPT_REXMT] == 0)
			cb->s_timer[SPPT_REXMT] = cb->s_rxtcur;
E 25
	}
	{
		/*
		 * Do not request acks when we ack their data packets or
		 * when we do a gratuitous window update.
		 */
		if (((si->si_cc & SP_SP) == 0) || cb->s_force)
				si->si_cc |= SP_SA;
E 22
		si->si_seq = htons(si->si_seq);
D 22
		si->si_alo = htons(cb->s_alo);
E 22
I 22
		si->si_alo = htons(alo);
E 22
		si->si_ack = htons(cb->s_ack);

		if (idpcksum) {
			si->si_sum = 0;
I 5
			len = ntohs(si->si_len);
E 5
D 8
			len = ((len - 1) | 1) + 1;
E 8
I 8
			if (len & 1)
				len++;
E 8
			si->si_sum = ns_cksum(dtom(si), len);
		} else
			si->si_sum = 0xffff;

I 22
		cb->s_outx = 4;
E 22
		if (so->so_options & SO_DEBUG || traceallspps)
			spp_trace(SA_OUTPUT, cb->s_state, cb, si, 0);
D 22
		spp_output_cnt++;
E 22
I 22

E 22
		if (so->so_options & SO_DONTROUTE)
			error = ns_output(m, (struct route *)0, NS_ROUTETOIF);
		else
			error = ns_output(m, &cb->s_nspcb->nsp_route, 0);
D 22
		if (traceallspps && sppconsdebug) {
			printf("spp_out: %x\n", error);
		}
D 3
		return(error);
E 3
I 3
D 16
		return (error);
E 16
I 16
		if (so->so_options & SO_DEBUG || traceallspps)
			spp_trace(SA_OUTPUT, cb->s_state, cb, si, 0);
E 22
E 16
E 3
	}
D 16
	if (so->so_options & SO_DEBUG || traceallspps)
		spp_trace(SA_OUTPUT, cb->s_state, cb, si, 0);
E 16
D 3
	return(error);
E 3
I 3
D 22
	return (error);
E 22
I 22
	if (error) {
		return (error);
	}
	sppstat.spps_sndtotal++;
	/*
	 * Data sent (as far as we can tell).
	 * If this advertises a larger window than any other segment,
	 * then remember the size of the advertized window.
	 * Any pending ACK has now been sent.
	 */
	cb->s_force = 0;
	cb->s_flags &= ~(SF_ACKNOW|SF_DELACK);
	if (SSEQ_GT(alo, cb->s_alo))
		cb->s_alo = alo;
	if (sendalot)
		goto again;
	cb->s_outx = 5;
	return (0);
E 22
E 3
}

I 22
int spp_do_persist_panics = 0;

spp_setpersist(cb)
	register struct sppcb *cb;
{
	register t = ((cb->s_srtt >> 2) + cb->s_rttvar) >> 1;
	extern int spp_backoff[];

D 25
	if (cb->s_timer[TCPT_REXMT] && spp_do_persist_panics)
E 25
I 25
	if (cb->s_timer[SPPT_REXMT] && spp_do_persist_panics)
E 25
		panic("spp_output REXMT");
	/*
	 * Start/restart persistance timer.
	 */
D 25
	TCPT_RANGESET(cb->s_timer[TCPT_PERSIST],
E 25
I 25
	SPPT_RANGESET(cb->s_timer[SPPT_PERSIST],
E 25
	    t*spp_backoff[cb->s_rxtshift],
D 25
	    TCPTV_PERSMIN, TCPTV_PERSMAX);
	if (cb->s_rxtshift < TCP_MAXRXTSHIFT)
E 25
I 25
	    SPPTV_PERSMIN, SPPTV_PERSMAX);
	if (cb->s_rxtshift < SPP_MAXRXTSHIFT)
E 25
		cb->s_rxtshift++;
}
E 22
/*ARGSUSED*/
spp_ctloutput(req, so, level, name, value)
	int req;
	struct socket *so;
	int name;
	struct mbuf **value;
{
	register struct mbuf *m;
	struct nspcb *nsp = sotonspcb(so);
	register struct sppcb *cb;
	int mask, error = 0;

	if (level != NSPROTO_SPP) {
		/* This will have to be changed when we do more general
		   stacking of protocols */
D 3
		return(idp_ctloutput(req, so, level, name, value));
E 3
I 3
		return (idp_ctloutput(req, so, level, name, value));
E 3
	}
	if (nsp == NULL) {
		error = EINVAL;
		goto release;
	} else
		cb = nstosppcb(nsp);

	switch (req) {
I 3

E 3
	case PRCO_GETOPT:
D 3
		if (value==NULL) {
			error = EINVAL;
			goto release;
		}
E 3
I 3
D 8
		if (value==NULL)
E 8
I 8
		if (value == NULL)
E 8
			return (EINVAL);
E 3
		m = m_get(M_DONTWAIT, MT_DATA);
I 3
D 8
		if (m==NULL)
E 8
I 8
		if (m == NULL)
E 8
			return (ENOBUFS);
E 3
		switch (name) {
I 3

E 3
		case SO_HEADERS_ON_INPUT:
			mask = SF_HI;
			goto get_flags;
I 3

E 3
		case SO_HEADERS_ON_OUTPUT:
			mask = SF_HO;
		get_flags:
			m->m_len = sizeof(short);
			m->m_off = MMAXOFF - sizeof(short);
			*mtod(m, short *) = cb->s_flags & mask;
			break;
I 3

I 12
		case SO_MTU:
			m->m_len = sizeof(u_short);
			m->m_off = MMAXOFF - sizeof(short);
			*mtod(m, short *) = cb->s_mtu;
			break;

E 12
E 3
		case SO_LAST_HEADER:
			m->m_len = sizeof(struct sphdr);
			m->m_off = MMAXOFF - sizeof(struct sphdr);
			*mtod(m, struct sphdr *) = cb->s_rhdr;
			break;
I 3

E 3
		case SO_DEFAULT_HEADERS:
			m->m_len = sizeof(struct spidp);
			m->m_off = MMAXOFF - sizeof(struct sphdr);
D 22
			*mtod(m, struct sphdr *) = cb->s_shdr.si_s;
E 22
I 22
			*mtod(m, struct sphdr *) = cb->s_shdr;
E 22
I 18
			break;

		default:
			error = EINVAL;
E 18
		}
		*value = m;
		break;
I 3

E 3
	case PRCO_SETOPT:
I 12
		if (value == 0 || *value == 0) {
			error = EINVAL;
			break;
		}
E 12
		switch (name) {
D 7
			int mask, *ok;
E 7
I 7
			int *ok;
E 7

		case SO_HEADERS_ON_INPUT:
			mask = SF_HI;
			goto set_head;
I 3

E 3
		case SO_HEADERS_ON_OUTPUT:
			mask = SF_HO;
		set_head:
D 12
			if (value && *value) {
E 12
I 12
			if (cb->s_flags & SF_PI) {
E 12
				ok = mtod(*value, int *);
				if (*ok)
					cb->s_flags |= mask;
				else
					cb->s_flags &= ~mask;
			} else error = EINVAL;
			break;
I 3

I 12
		case SO_MTU:
			cb->s_mtu = *(mtod(*value, u_short *));
			break;

E 12
E 3
		case SO_DEFAULT_HEADERS:
			{
				register struct sphdr *sp
						= mtod(*value, struct sphdr *);
				cb->s_dt = sp->sp_dt;
				cb->s_cc = sp->sp_cc & SP_EM;
			}
I 18
			break;

		default:
			error = EINVAL;
E 18
		}
D 12
		if (value && *value)
			m_freem(*value);
E 12
I 12
		m_freem(*value);
E 12
		break;
	}
	release:
D 3
		return(error);
E 3
I 3
		return (error);
E 3
}

/*ARGSUSED*/
spp_usrreq(so, req, m, nam, rights)
	struct socket *so;
	int req;
	struct mbuf *m, *nam, *rights;
{
	struct nspcb *nsp = sotonspcb(so);
	register struct sppcb *cb;
	int s = splnet();
	int error = 0, ostate;
I 22
	struct mbuf *mm;
	register struct sockbuf *sb;
E 22

	if (req == PRU_CONTROL)
                return (ns_control(so, (int)m, (caddr_t)nam,
			(struct ifnet *)rights));
	if (rights && rights->m_len) {
		error = EINVAL;
		goto release;
	}
	if (nsp == NULL) {
		if (req != PRU_ATTACH) {
			error = EINVAL;
			goto release;
		}
	} else
		cb = nstosppcb(nsp);

	ostate = cb ? cb->s_state : 0;

	switch (req) {
I 3

E 3
	case PRU_ATTACH:
		if (nsp != NULL) {
			error = EISCONN;
			break;
		}
		error = ns_pcballoc(so, &nspcb);
		if (error)
			break;
D 22
		error = soreserve(so, 2048, 2048);
E 22
I 22
D 26
		error = soreserve(so, 3072, 3072);
E 22
		if (error)
			break;
E 26
I 26
		if (so->so_snd.sb_hiwat == 0 || so->so_rcv.sb_hiwat == 0) {
			error = soreserve(so, (u_long) 3072, (u_long) 3072);
			if (error)
				break;
		}
E 26
		nsp = sotonspcb(so);
D 22
		{
D 15
			struct mbuf *mm = m_getclr(M_DONTWAIT,MT_PCB);
E 15
I 15
			struct mbuf *mm = m_getclr(M_DONTWAIT, MT_PCB);
E 22
E 15

D 8
			if (mm==NULL) {
E 8
I 8
D 22
			if (mm == NULL) {
E 8
				error = ENOBUFS;
				break;
			}
			cb = mtod(mm, struct sppcb *);
			cb->s_state = TCPS_LISTEN;
D 5
			cb->s_flags = SF_HI | SF_HO;
E 5
			cb->s_snt = -1;
			cb->s_q.si_next = cb->s_q.si_prev = &cb->s_q;
			cb->s_nspcb = nsp;
			nsp->nsp_pcb = (caddr_t) cb; 
E 22
I 22
		mm = m_getclr(M_DONTWAIT, MT_PCB);
		sb = &so->so_snd;

		if (mm == NULL) {
			error = ENOBUFS;
			break;
E 22
		}
I 22
		cb = mtod(mm, struct sppcb *);
		mm = m_getclr(M_DONTWAIT, MT_HEADER);
		if (mm == NULL) {
D 26
			m_free(dtom(m));
E 26
I 26
			(void) m_free(dtom(m));
E 26
			error = ENOBUFS;
			break;
		}
		cb->s_idp = mtod(mm, struct idp *);
		cb->s_state = TCPS_LISTEN;
		cb->s_smax = -1;
		cb->s_swl1 = -1;
		cb->s_q.si_next = cb->s_q.si_prev = &cb->s_q;
		cb->s_nspcb = nsp;
		cb->s_mtu = 576 - sizeof (struct spidp);
		cb->s_cwnd = sbspace(sb) * CUNIT / cb->s_mtu;
		cb->s_ssthresh = cb->s_cwnd;
		cb->s_cwmx = sb->sb_mbmax * CUNIT /
				(2 * sizeof (struct spidp));
		/* Above is recomputed when connecting to account
		   for changed buffering or mtu's */
D 25
		cb->s_rtt = TCPTV_SRTTBASE;
		cb->s_rttvar = TCPTV_SRTTDFLT << 2;
		TCPT_RANGESET(cb->s_rxtcur,
		    ((TCPTV_SRTTBASE >> 2) + (TCPTV_SRTTDFLT << 2)) >> 1,
		    TCPTV_MIN, TCPTV_REXMTMAX);
E 25
I 25
		cb->s_rtt = SPPTV_SRTTBASE;
		cb->s_rttvar = SPPTV_SRTTDFLT << 2;
		SPPT_RANGESET(cb->s_rxtcur,
		    ((SPPTV_SRTTBASE >> 2) + (SPPTV_SRTTDFLT << 2)) >> 1,
		    SPPTV_MIN, SPPTV_REXMTMAX);
E 25
		nsp->nsp_pcb = (caddr_t) cb; 
E 22
		break;

	case PRU_DETACH:
		if (nsp == NULL) {
			error = ENOTCONN;
			break;
		}
		if (cb->s_state > TCPS_LISTEN)
			cb = spp_disconnect(cb);
		else
			cb = spp_close(cb);
		break;

	case PRU_BIND:
		error = ns_pcbbind(nsp, nam);
		break;

	case PRU_LISTEN:
		if (nsp->nsp_lport == 0)
			error = ns_pcbbind(nsp, (struct mbuf *)0);
		if (error == 0)
			cb->s_state = TCPS_LISTEN;
		break;

	/*
	 * Initiate connection to peer.
	 * Enter SYN_SENT state, and mark socket as connecting.
	 * Start keep-alive timer, setup prototype header,
	 * Send initial system packet requesting connection.
	 */
	case PRU_CONNECT:
		if (nsp->nsp_lport == 0) {
			error = ns_pcbbind(nsp, (struct mbuf *)0);
			if (error)
				break;
		}
		error = ns_pcbconnect(nsp, nam);
		if (error)
			break;
		soisconnecting(so);
I 22
		sppstat.spps_connattempt++;
E 22
		cb->s_state = TCPS_SYN_SENT;
		cb->s_did = 0;
		spp_template(cb);
D 25
		cb->s_timer[TCPT_KEEP] = TCPTV_KEEP;
		cb->s_force = 1 + TCPTV_KEEP;
E 25
I 25
		cb->s_timer[SPPT_KEEP] = SPPTV_KEEP;
		cb->s_force = 1 + SPPTV_KEEP;
E 25
		/*
		 * Other party is required to respond to
		 * the port I send from, but he is not
		 * required to answer from where I am sending to,
		 * so allow wildcarding.
		 * original port I am sending to is still saved in
		 * cb->s_dport.
		 */
		nsp->nsp_fport = 0;
		error = spp_output(cb, (struct mbuf *) 0);
		break;

	case PRU_CONNECT2:
		error = EOPNOTSUPP;
		break;

	/*
	 * We may decide later to implement connection closing
	 * handshaking at the spp level optionally.
	 * here is the hook to do it:
	 */
	case PRU_DISCONNECT:
		cb = spp_disconnect(cb);
		break;

	/*
	 * Accept a connection.  Essentially all the work is
	 * done at higher levels; just return the address
	 * of the peer, storing through addr.
	 */
	case PRU_ACCEPT: {
		struct sockaddr_ns *sns = mtod(nam, struct sockaddr_ns *);

		nam->m_len = sizeof (struct sockaddr_ns);
		sns->sns_family = AF_NS;
		sns->sns_addr = nsp->nsp_faddr;
		break;
		}

	case PRU_SHUTDOWN:
		socantsendmore(so);
		cb = spp_usrclosed(cb);
		if (cb)
			error = spp_output(cb, (struct mbuf *) 0);
		break;

	/*
	 * After a receive, possibly send acknowledgment
	 * updating allocation.
	 */
	case PRU_RCVD:
I 22
		cb->s_flags |= SF_RVD;
E 22
		(void) spp_output(cb, (struct mbuf *) 0);
I 22
		cb->s_flags &= ~SF_RVD;
E 22
		break;

D 19
	case PRU_SEND:
		error = spp_output(cb, m);
		m = NULL;
		break;

E 19
	case PRU_ABORT:
D 7
		spp_drop(cb, ECONNABORTED);
E 7
I 7
		(void) spp_drop(cb, ECONNABORTED);
E 7
		break;

	case PRU_SENSE:
	case PRU_CONTROL:
		m = NULL;
		error = EOPNOTSUPP;
		break;

	case PRU_RCVOOB:
I 13
D 15
		if (so->so_oobmark == 0 &&
		    (so->so_state & SS_RCVATMARK) == 0) {
			error = EINVAL;
E 15
I 15
		if ((cb->s_oobflags & SF_IOOB) || so->so_oobmark ||
		    (so->so_state & SS_RCVATMARK)) {
			m->m_len = 1;
			*mtod(m, caddr_t) = cb->s_iobc;
E 15
			break;
		}
E 13
D 15
		if ( ! (cb->s_oobflags & SF_IOOB) ) {
			error = EWOULDBLOCK;
			break;
		}
		m->m_len = 1;
		*mtod(m, caddr_t) = cb->s_iobc;
D 13
		cb->s_oobflags &= ~ SF_IOOB;
E 13
I 13
		if (((int)nam & MSG_PEEK) == 0)
			cb->s_oobflags &= ~ SF_IOOB;
E 15
I 15
		error = EINVAL;
E 15
E 13
		break;

	case PRU_SENDOOB:
		if (sbspace(&so->so_snd) < -512) {
D 19
			m_freem(m);
E 19
			error = ENOBUFS;
			break;
		}
		cb->s_oobflags |= SF_SOOB;
I 19
		/* fall into */
	case PRU_SEND:
E 19
		error = spp_output(cb, m);
		m = NULL;
D 15
		cb->s_oobflags &= ~SF_SOOB;
E 15
		break;

	case PRU_SOCKADDR:
		ns_setsockaddr(nsp, nam);
		break;

	case PRU_PEERADDR:
		ns_setpeeraddr(nsp, nam);
		break;

	case PRU_SLOWTIMO:
		cb = spp_timers(cb, (int)nam);
I 22
		req |= ((int)nam) << 8;
E 22
		break;

	case PRU_FASTTIMO:
	case PRU_PROTORCV:
	case PRU_PROTOSEND:
		error =  EOPNOTSUPP;
		break;

	default:
		panic("sp_usrreq");
	}
	if (cb && (so->so_options & SO_DEBUG || traceallspps))
D 7
		spp_trace(SA_USER, ostate, cb, (struct sphdr *)0, req);
E 7
I 7
		spp_trace(SA_USER, (u_char)ostate, cb, (struct spidp *)0, req);
E 7
release:
	if (m != NULL)
		m_freem(m);
	splx(s);
	return (error);
}

spp_usrreq_sp(so, req, m, nam, rights)
	struct socket *so;
	int req;
	struct mbuf *m, *nam, *rights;
{
	int error = spp_usrreq(so, req, m, nam, rights);

D 8
	if (req==PRU_ATTACH && error==0) {
E 8
I 8
	if (req == PRU_ATTACH && error == 0) {
E 8
		struct nspcb *nsp = sotonspcb(so);
		((struct sppcb *)nsp->nsp_pcb)->s_flags |=
					(SF_HI | SF_HO | SF_PI);
	}
D 3
	return(error);
E 3
I 3
	return (error);
E 3
}

/*
 * Create template to be used to send spp packets on a connection.
 * Called after host entry created, fills
 * in a skeletal spp header (choosing connection id),
 * minimizing the amount of work necessary when the connection is used.
 */
spp_template(cb)
D 22
	struct sppcb *cb;
E 22
I 22
	register struct sppcb *cb;
E 22
{
	register struct nspcb *nsp = cb->s_nspcb;
D 22
	register struct spidp *n = &(cb->s_shdr);
E 22
I 22
	register struct idp *idp = cb->s_idp;
	register struct sockbuf *sb = &(nsp->nsp_socket->so_snd);
E 22

D 12
	cb->s_mtu = 1024;
E 12
I 12
D 22
	cb->s_mtu = 576 - sizeof (struct spidp);
E 12
	n->si_pt = NSPROTO_SPP;
	n->si_sna = nsp->nsp_laddr;
	n->si_dna = nsp->nsp_faddr;
	n->si_sid = htons(spp_iss);
E 22
I 22
	idp->idp_pt = NSPROTO_SPP;
	idp->idp_sna = nsp->nsp_laddr;
	idp->idp_dna = nsp->nsp_faddr;
	cb->s_sid = htons(spp_iss);
E 22
	spp_iss += SPP_ISSINCR/2;
D 22
	n->si_alo = 1;
E 22
I 22
	cb->s_alo = 1;
	cb->s_cwnd = (sbspace(sb) * CUNIT) / cb->s_mtu;
	cb->s_ssthresh = cb->s_cwnd; /* Try to expand fast to full complement
					of large packets */
	cb->s_cwmx = (sb->sb_mbmax * CUNIT) / (2 * sizeof(struct spidp));
	cb->s_cwmx = MAX(cb->s_cwmx, cb->s_cwnd);
		/* But allow for lots of little packets as well */
E 22
}

/*
 * Close a SPIP control block:
 *	discard spp control block itself
 *	discard ns protocol control block
 *	wake up any sleepers
 */
struct sppcb *
spp_close(cb)
	register struct sppcb *cb;
{
	register struct spidp_q *s;
	struct nspcb *nsp = cb->s_nspcb;
	struct socket *so = nsp->nsp_socket;
	register struct mbuf *m;

	s = cb->s_q.si_next;
	while (s != &(cb->s_q)) {
		s = s->si_next;
		m = dtom(s->si_prev);
		remque(s->si_prev);
		m_freem(m);
	}
I 22
	(void) m_free(dtom(cb->s_idp));
E 22
	(void) m_free(dtom(cb));
	nsp->nsp_pcb = 0;
	soisdisconnected(so);
	ns_pcbdetach(nsp);
I 22
	sppstat.spps_closed++;
E 22
D 3
	return((struct sppcb *)0);
E 3
I 3
	return ((struct sppcb *)0);
E 3
}
/*
 *	Someday we may do level 3 handshaking
 *	to close a connection or send a xerox style error.
 *	For now, just close.
 */
struct sppcb *
spp_usrclosed(cb)
	register struct sppcb *cb;
{
D 3
	return(spp_close(cb));
E 3
I 3
	return (spp_close(cb));
E 3
}
struct sppcb *
spp_disconnect(cb)
	register struct sppcb *cb;
{
D 3
	return(spp_close(cb));
E 3
I 3
	return (spp_close(cb));
E 3
}
/*
 * Drop connection, reporting
 * the specified error.
 */
struct sppcb *
spp_drop(cb, errno)
	register struct sppcb *cb;
	int errno;
{
	struct socket *so = cb->s_nspcb->nsp_socket;

	/*
	 * someday, in the xerox world
	 * we will generate error protocol packets
	 * announcing that the socket has gone away.
	 */
D 22
	/*if (TCPS_HAVERCVDSYN(tp->t_state)) {
		tp->t_state = TCPS_CLOSED;
		(void) tcp_output(tp);
	}*/
E 22
I 22
	if (TCPS_HAVERCVDSYN(cb->s_state)) {
		sppstat.spps_drops++;
		cb->s_state = TCPS_CLOSED;
		/*(void) tcp_output(cb);*/
	} else
		sppstat.spps_conndrops++;
E 22
	so->so_error = errno;
	return (spp_close(cb));
}

spp_abort(nsp)
	struct nspcb *nsp;
{

D 7
	spp_close((struct sppcb *)nsp->nsp_pcb);
E 7
I 7
	(void) spp_close((struct sppcb *)nsp->nsp_pcb);
E 7
}

D 22
spp_setpersist(cb)
	register struct sppcb *cb;
{

	/*if (cb->s_timer[TCPT_REXMT])
		panic("spp_output REXMT");*/
	/*
	 * Start/restart persistance timer.
	 */
	TCPT_RANGESET(cb->s_timer[TCPT_PERSIST],
	    ((int)(tcp_beta * cb->s_srtt)) << cb->s_rxtshift,
	    TCPTV_PERSMIN, TCPTV_MAX);
	cb->s_rxtshift++;
	if (cb->s_rxtshift >= TCP_MAXRXTSHIFT)
		cb->s_rxtshift = 0;
}
E 22
I 22
D 24
long	spp_backoff[TCP_MAXRXTSHIFT+1] =
E 24
I 24
D 25
int	spp_backoff[TCP_MAXRXTSHIFT+1] =
E 25
I 25
int	spp_backoff[SPP_MAXRXTSHIFT+1] =
E 25
E 24
    { 1, 2, 4, 8, 16, 32, 64, 64, 64, 64, 64, 64, 64 };
E 22
/*
 * Fast timeout routine for processing delayed acks
 */
D 22
int spp_ftcnt;
E 22
spp_fasttimo()
{
	register struct nspcb *nsp;
	register struct sppcb *cb;
	int s = splnet();

	nsp = nspcb.nsp_next;
D 22
	spp_ftcnt++;
E 22
	if (nsp)
	for (; nsp != &nspcb; nsp = nsp->nsp_next)
		if ((cb = (struct sppcb *)nsp->nsp_pcb) &&
		    (cb->s_flags & SF_DELACK)) {
			cb->s_flags &= ~SF_DELACK;
D 22
			cb->s_flags |= SF_AK;
E 22
I 22
			cb->s_flags |= SF_ACKNOW;
			sppstat.spps_delack++;
E 22
			(void) spp_output(cb, (struct mbuf *) 0);
		}
	splx(s);
}

/*
 * spp protocol timeout routine called every 500 ms.
 * Updates the timers in all active pcb's and
 * causes finite state machine actions if timers expire.
 */
spp_slowtimo()
{
	register struct nspcb *ip, *ipnxt;
	register struct sppcb *cb;
	int s = splnet();
	register int i;

	/*
	 * Search through tcb's and update active timers.
	 */
	ip = nspcb.nsp_next;
	if (ip == 0) {
		splx(s);
		return;
	}
	while (ip != &nspcb) {
		cb = nstosppcb(ip);
		ipnxt = ip->nsp_next;
		if (cb == 0)
			goto tpgone;
D 25
		for (i = 0; i < TCPT_NTIMERS; i++) {
E 25
I 25
		for (i = 0; i < SPPT_NTIMERS; i++) {
E 25
			if (cb->s_timer[i] && --cb->s_timer[i] == 0) {
				(void) spp_usrreq(cb->s_nspcb->nsp_socket,
				    PRU_SLOWTIMO, (struct mbuf *)0,
				    (struct mbuf *)i, (struct mbuf *)0);
				if (ipnxt->nsp_prev != ip)
					goto tpgone;
			}
		}
		cb->s_idle++;
		if (cb->s_rtt)
			cb->s_rtt++;
tpgone:
		ip = ipnxt;
	}
	spp_iss += SPP_ISSINCR/PR_SLOWHZ;		/* increment iss */
	splx(s);
}
D 22

float	spp_backoff[TCP_MAXRXTSHIFT] =
    { 1.0, 1.2, 1.4, 1.7, 2.0, 3.0, 5.0, 8.0, 16.0, 32.0 };
I 10
int sppexprexmtbackoff = 0;
E 22
E 10
D 9
extern int tcpexprexmtbackoff;
E 9
/*
D 12
 * TCP timer processing.
E 12
I 12
 * SPP timer processing.
E 12
 */
struct sppcb *
spp_timers(cb, timer)
	register struct sppcb *cb;
	int timer;
{
I 22
	long rexmt;
	int win;
E 22

	cb->s_force = 1 + timer;
	switch (timer) {

	/*
D 22
	 * 2 MSL timeout in shutdown went off.  Delete connection
E 22
I 22
	 * 2 MSL timeout in shutdown went off.  TCP deletes connection
E 22
	 * control block.
	 */
D 25
	case TCPT_2MSL:
D 22
		cb = spp_close(cb);
E 22
I 22
		printf("spp: TCPT_2MSL went off for no reason\n");
E 25
I 25
	case SPPT_2MSL:
		printf("spp: SPPT_2MSL went off for no reason\n");
E 25
		cb->s_timer[timer] = 0;
E 22
		break;

	/*
	 * Retransmission timer went off.  Message has not
	 * been acked within retransmit interval.  Back off
D 22
	 * to a longer retransmit interval and retransmit all
	 * unacknowledged messages in the window.
E 22
I 22
	 * to a longer retransmit interval and retransmit one packet.
E 22
	 */
D 25
	case TCPT_REXMT:
D 22
		cb->s_rxtshift++;
		if (cb->s_rxtshift > TCP_MAXRXTSHIFT) {
E 22
I 22
		if (++cb->s_rxtshift > TCP_MAXRXTSHIFT) {
			cb->s_rxtshift = TCP_MAXRXTSHIFT;
E 25
I 25
	case SPPT_REXMT:
		if (++cb->s_rxtshift > SPP_MAXRXTSHIFT) {
			cb->s_rxtshift = SPP_MAXRXTSHIFT;
E 25
			sppstat.spps_timeoutdrop++;
E 22
			cb = spp_drop(cb, ETIMEDOUT);
			break;
		}
D 22
		(void) spp_output(cb, (struct mbuf *) 0);
		TCPT_RANGESET(cb->s_timer[TCPT_REXMT],
		    (int)cb->s_srtt, TCPTV_MIN, TCPTV_MAX);
D 10
		if (tcpexprexmtbackoff) {
E 10
I 10
		if (sppexprexmtbackoff) {
E 10
			TCPT_RANGESET(cb->s_timer[TCPT_REXMT],
			    cb->s_timer[TCPT_REXMT] << cb->s_rxtshift,
			    TCPTV_MIN, TCPTV_MAX);
		} else {
			TCPT_RANGESET(cb->s_timer[TCPT_REXMT],
			    cb->s_timer[TCPT_REXMT] *
			        spp_backoff[cb->s_rxtshift - 1],
			    TCPTV_MIN, TCPTV_MAX);
E 22
I 22
		sppstat.spps_rexmttimeo++;
		rexmt = ((cb->s_srtt >> 2) + cb->s_rttvar) >> 1;
		rexmt *= spp_backoff[cb->s_rxtshift];
D 25
		TCPT_RANGESET(cb->s_rxtcur, rexmt, TCPTV_MIN, TCPTV_REXMTMAX);
		cb->s_timer[TCPT_REXMT] = cb->s_rxtcur;
E 25
I 25
		SPPT_RANGESET(cb->s_rxtcur, rexmt, SPPTV_MIN, SPPTV_REXMTMAX);
		cb->s_timer[SPPT_REXMT] = cb->s_rxtcur;
E 25
		/*
		 * If we have backed off fairly far, our srtt
		 * estimate is probably bogus.  Clobber it
		 * so we'll take the next rtt measurement as our srtt;
		 * move the current srtt into rttvar to keep the current
		 * retransmit times until then.
		 */
D 25
		if (cb->s_rxtshift > TCP_MAXRXTSHIFT / 4 ) {
E 25
I 25
		if (cb->s_rxtshift > SPP_MAXRXTSHIFT / 4 ) {
E 25
			cb->s_rttvar += (cb->s_srtt >> 2);
			cb->s_srtt = 0;
E 22
		}
I 22
		cb->s_snxt = cb->s_rack;
		/*
		 * If timing a packet, stop the timer.
		 */
		cb->s_rtt = 0;
		/*
		 * See very long discussion in tcp_timer.c about congestion
		 * window and sstrhesh
		 */
		win = MIN(cb->s_swnd, (cb->s_cwnd/CUNIT)) / 2;
		if (win < 2)
			win = 2;
		cb->s_cwnd = CUNIT;
D 24
		cb->s_ssthresh = win;
E 24
I 24
		cb->s_ssthresh = win * CUNIT;
E 24
		(void) spp_output(cb, (struct mbuf *) 0);
E 22
		break;

	/*
	 * Persistance timer into zero window.
	 * Force a probe to be sent.
	 */
D 25
	case TCPT_PERSIST:
E 25
I 25
	case SPPT_PERSIST:
E 25
D 22
		(void) spp_output(cb, (struct mbuf *) 0);
E 22
I 22
		sppstat.spps_persisttimeo++;
E 22
		spp_setpersist(cb);
I 22
		(void) spp_output(cb, (struct mbuf *) 0);
E 22
		break;

	/*
	 * Keep-alive timer went off; send something
	 * or drop connection if idle for too long.
	 */
D 25
	case TCPT_KEEP:
E 25
I 25
	case SPPT_KEEP:
E 25
I 22
		sppstat.spps_keeptimeo++;
E 22
		if (cb->s_state < TCPS_ESTABLISHED)
			goto dropit;
		if (cb->s_nspcb->nsp_socket->so_options & SO_KEEPALIVE) {
D 25
		    	if (cb->s_idle >= TCPTV_MAXIDLE)
E 25
I 25
		    	if (cb->s_idle >= SPPTV_MAXIDLE)
E 25
				goto dropit;
I 22
			sppstat.spps_keepprobe++;
E 22
			(void) spp_output(cb, (struct mbuf *) 0);
		} else
			cb->s_idle = 0;
D 25
		cb->s_timer[TCPT_KEEP] = TCPTV_KEEP;
E 25
I 25
		cb->s_timer[SPPT_KEEP] = SPPTV_KEEP;
E 25
		break;
	dropit:
I 22
		sppstat.spps_keepdrops++;
E 22
		cb = spp_drop(cb, ETIMEDOUT);
		break;
	}
	return (cb);
}
I 24
#ifndef lint
E 24
I 22
int SppcbSize = sizeof (struct sppcb);
int NspcbSize = sizeof (struct nspcb);
I 24
#endif lint
E 24
E 22
E 1
