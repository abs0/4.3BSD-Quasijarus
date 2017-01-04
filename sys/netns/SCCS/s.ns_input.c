h52034
s 00011/00006/00469
d D 7.4 88/06/29 17:13:23 bostic 19 18
c install approved copyright notice
e
s 00001/00001/00474
d D 7.3 88/05/04 11:45:31 sklower 18 16
c checksum adjustment problem reported by sun.COM, fixed by me.
e
s 00003/00004/00471
d R 7.3 88/05/03 17:32:55 sklower 17 16
c checksum adjustment problem reported by sun.COM, fixed by me.
e
s 00010/00004/00465
d D 7.2 88/01/20 15:15:18 sklower 16 15
c Change licensing/use notice.
e
s 00001/00001/00468
d D 7.1 86/06/05 00:36:55 mckusick 15 14
c 4.3BSD release version
e
s 00001/00001/00468
d D 6.13 86/06/02 14:48:31 karels 14 13
c lint
e
s 00009/00005/00460
d D 6.12 86/02/03 17:32:03 sklower 13 12
c remove ns_netof (non-portable), add zero and broadcast ns nets to compare to.
e
s 00035/00004/00430
d D 6.11 85/09/26 15:00:10 sklower 12 11
c when debugging output, trace which interface you sent it out on.
e
s 00016/00008/00418
d D 6.10 85/09/06 18:34:56 sklower 11 10
c Do Something with interface tracing & fix ctlinput routines.
e
s 00002/00001/00424
d D 6.9 85/09/06 18:13:44 karels 10 9
c fetch interface pointer with packet
e
s 00006/00005/00419
d D 6.8 85/08/09 11:35:11 sklower 9 8
c 
e
s 00025/00018/00399
d D 6.7 85/07/26 15:48:24 sklower 8 7
c new option to suppress error processing on DG sockets.
e
s 00031/00029/00386
d D 6.6 85/07/19 19:07:19 sklower 7 6
c 1.) Make sure that one connection refused error doesn't blow
c   all correspondents to the same machhine away.
c 2.) Rearrange who looks up the nspcb.
c 3.) I don't like this the way I left it, but need to check everything in at
c     a semi-consistent state.
e
s 00003/00003/00412
d D 6.5 85/06/21 20:27:45 sklower 6 5
c forwarded packets were freed incorrectly by the forwarding routine.
e
s 00009/00005/00406
d D 6.4 85/06/16 12:50:32 sklower 5 3
c routing for pt to pt hosts requires that port # be 0, turn checksumming on by default.
e
s 00001/00000/00411
d R 6.4 85/06/16 12:09:18 sklower 4 3
c routing for pt to pt hosts demands that port # be 0 in sockaddr.
e
s 00007/00001/00404
d D 6.3 85/06/08 12:50:32 mckusick 3 2
c Add copyright
e
s 00084/00070/00321
d D 6.2 85/06/01 15:38:32 sklower 2 1
c changes to directed broadcasts, per Bill Nesheim@Cornell.
e
s 00391/00000/00000
d D 6.1 85/05/30 19:10:56 sklower 1 0
c date and time created 85/05/30 19:10:56 by sklower
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
/*
D 13
 * Copyright (c) 1982 Regents of the University of California.
E 13
I 13
D 15
 * Copyright (c) 1984, 1985 Regents of the University of California.
E 15
I 15
D 16
 * Copyright (c) 1984, 1985, 1986 Regents of the University of California.
E 15
E 13
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 16
I 16
 * Copyright (c) 1984, 1985, 1986, 1987 Regents of the University of California.
 * All rights reserved.
E 16
 *
D 16
 *	%W% (Berkeley) %G%
E 16
I 16
 * Redistribution and use in source and binary forms are permitted
D 19
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 19
I 19
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
E 19
 *
D 19
 *      %W% (Berkeley) %G%
E 19
I 19
 *	%W% (Berkeley) %G%
E 19
E 16
 */
E 3

#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "domain.h"
#include "protosw.h"
#include "socket.h"
#include "socketvar.h"
#include "errno.h"
#include "time.h"
#include "kernel.h"

#include "../net/if.h"
#include "../net/route.h"
#include "../net/raw_cb.h"

#include "ns.h"
#include "ns_if.h"
#include "ns_pcb.h"
#include "idp.h"
#include "idp_var.h"
#include "ns_error.h"

/*
 * NS initialization.
 */
union ns_host	ns_thishost;
union ns_host	ns_zerohost;
union ns_host	ns_broadhost;
I 13
union ns_net	ns_zeronet;
union ns_net	ns_broadnet;
E 13

D 13
static char allones[] = {-1, -1, -1, -1, -1, -1};
E 13
I 13
static u_short allones[] = {-1, -1, -1};
E 13

struct nspcb nspcb;
struct nspcb nsrawpcb;

struct ifqueue	nsintrq;
int	nsqmaxlen = IFQ_MAXLEN;

D 5
int	idpcksum = 0;
E 5
I 5
int	idpcksum = 1;
I 7
long	ns_pexseq;
E 7
E 5

ns_init()
{
I 7
	extern struct timeval time;

E 7
	ns_broadhost = * (union ns_host *) allones;
I 13
	ns_broadnet = * (union ns_net *) allones;
E 13
	nspcb.nsp_next = nspcb.nsp_prev = &nspcb;
	nsrawpcb.nsp_next = nsrawpcb.nsp_prev = &nsrawpcb;
	nsintrq.ifq_maxlen = nsqmaxlen;
I 7
	ns_pexseq = time.tv_usec;
E 7
}

/*
 * Idp input routine.  Pass to next level.
 */
int nsintr_getpck = 0;
int nsintr_swtch = 0;
nsintr()
{
	register struct idp *idp;
	register struct mbuf *m;
D 8
	struct nspcb *nsp;
E 8
I 8
	register struct nspcb *nsp;
I 10
	struct ifnet *ifp;
E 10
E 8
	struct mbuf *m0;
	register int i;
	int len, s, error;
	char oddpacketp;

next:
	/*
	 * Get next datagram off input queue and get IDP header
	 * in first mbuf.
	 */
	s = splimp();
D 10
	IF_DEQUEUE(&nsintrq, m);
E 10
I 10
	IF_DEQUEUEIF(&nsintrq, m, ifp);
E 10
	splx(s);
	nsintr_getpck++;
	if (m == 0)
		return;
	if ((m->m_off > MMAXOFF || m->m_len < sizeof (struct idp)) &&
	    (m = m_pullup(m, sizeof (struct idp))) == 0) {
		idpstat.idps_toosmall++;
		goto next;
	}

	/*
	 * Give any raw listeners a crack at the packet
	 */
	for (nsp = nsrawpcb.nsp_next; nsp != &nsrawpcb; nsp = nsp->nsp_next) {
D 9
		struct mbuf *m1 = m_copy(m, 0, M_COPYALL);
E 9
I 9
		struct mbuf *m1 = m_copy(m, 0, (int)M_COPYALL);
E 9
D 11
		if (m1) idp_input(m1, nsp);
E 11
I 11
		if (m1) idp_input(m1, nsp, ifp);
E 11
	}

	idp = mtod(m, struct idp *);
	len = ntohs(idp->idp_len);
	if (oddpacketp = len & 1) {
		len++;		/* If this packet is of odd length,
				   preserve garbage byte for checksum */
	}

	/*
	 * Check that the amount of data in the buffers
	 * is as at least much as the IDP header would have us expect.
	 * Trim mbufs if longer than we expect.
	 * Drop packet if shorter than we expect.
	 */
	i = -len;
	m0 = m;
	for (;;) {
		i += m->m_len;
		if (m->m_next == 0)
			break;
		m = m->m_next;
	}
	if (i != 0) {
		if (i < 0) {
			idpstat.idps_tooshort++;
			m = m0;
			goto bad;
		}
		if (i <= m->m_len)
			m->m_len -= i;
		else
			m_adj(m0, -i);
	}
	m = m0;
	if (idpcksum && ((i = idp->idp_sum)!=0xffff)) {
		idp->idp_sum = 0;
		if (i != (idp->idp_sum = ns_cksum(m,len))) {
			idpstat.idps_badsum++;
I 7
			idp->idp_sum = i;
E 7
			if (ns_hosteqnh(ns_thishost, idp->idp_dna.x_host))
				error = NS_ERR_BADSUM;
			else
				error = NS_ERR_BADSUM_T;
			ns_error(m, error, 0);
			goto next;
		}
	}
	/*
	 * Is this a directed broadcast?
	 */
	if (ns_hosteqnh(ns_broadhost,idp->idp_dna.x_host)) {
D 13
		if ((ns_netof(idp->idp_dna)!=ns_netof(idp->idp_sna)) &&
		   (ns_netof(idp->idp_dna)!=-1) && (ns_netof(idp->idp_sna)!=0)
		   && (ns_netof(idp->idp_dna)!=0)) {
E 13
I 13
		if ((!ns_neteq(idp->idp_dna, idp->idp_sna)) &&
		    (!ns_neteqnn(idp->idp_dna.x_net, ns_broadnet)) &&
		    (!ns_neteqnn(idp->idp_sna.x_net, ns_zeronet)) &&
		    (!ns_neteqnn(idp->idp_dna.x_net, ns_zeronet)) ) {
E 13
			/*
D 2
			 * Look to see if I need to eat this packet as well.
E 2
I 2
			 * Look to see if I need to eat this packet.
			 * Algorithm is to forward all young packets
			 * and prematurely age any packets which will
			 * by physically broadcasted.
			 * Any very old packets eaten without forwarding
			 * would die anyway.
			 *
			 * Suggestion of Bill Nesheim, Cornell U.
E 2
			 */
D 2
			struct ns_ifaddr *ia =
					ns_iaonnetof(idp->idp_dna.x_net);
			if (ia) {
				m = m_copy(m, 0, M_COPYALL);
			} else
				m = NULL;
			idp_forward(idp);
			if (m==NULL)
E 2
I 2
D 5
			if(idp->idp_tc < NS_MAXHOPS) {
E 5
I 5
			if (idp->idp_tc < NS_MAXHOPS) {
E 5
				idp_forward(idp);
E 2
				goto next;
D 2
			idp = mtod(m, struct idp *);
E 2
I 2
			}
E 2
		}
	/*
	 * Is this our packet? If not, forward.
	 */
	} else if (!ns_hosteqnh(ns_thishost,idp->idp_dna.x_host)) {
		idp_forward(idp);
		goto next;
	}
I 7
D 8
	if (oddpacketp) {
		m_adj(m0, -1);
	}
E 8
I 8
	/*
	 * Locate pcb for datagram.
	 */
	nsp = ns_pcblookup(&idp->idp_sna, idp->idp_dna.x_port, NS_WILDCARD);
	/*
	 * Switch out to protocol's input routine.
	 */
	nsintr_swtch++;
	if (nsp) {
		if (oddpacketp) {
			m_adj(m0, -1);
		}
		if ((nsp->nsp_flags & NSP_ALL_PACKETS)==0)
			switch (idp->idp_pt) {
E 8
E 7

D 7
	/*
	 * Locate pcb for datagram.
	 */
	nsp = ns_pcblookup(&idp->idp_sna, idp->idp_dna.x_port, NS_WILDCARD);


E 7
D 8
	 /*
	  * Switch out to protocol's input routine.
	  */
E 8
I 8
			    case NSPROTO_SPP:
D 11
				    spp_input(m,nsp);
E 11
I 11
				    spp_input(m, nsp, ifp);
E 11
				    goto next;
E 8

D 7
	nsintr_swtch++;
	if (nsp) {
		if (oddpacketp) {
			m_adj(m0, -1);
		}
		switch (idp->idp_pt) {
E 7
I 7
D 8
	switch (idp->idp_pt) {
E 7
I 5

E 5
D 7
			case NSPROTO_SPP:
				spp_input(m,nsp);
				break;
E 7
I 7
		case NSPROTO_SPP:
			spp_input(m);
			break;
E 7
I 5

E 5
D 7
			case NSPROTO_ERROR:
				ns_err_input(m);
				break;
			default:
				idp_input(m,nsp);
		}
	} else {
		/* don't send ERROR response for multicast packet */
		if (idp->idp_dna.x_host.c_host[0] & 1)
			goto bad;
		ns_error(m, NS_ERR_NOSOCK, 0);
E 7
I 7
		case NSPROTO_ERROR:
			ns_err_input(m);
			break;
		default:
			idp_input(m, 0);
E 8
I 8
			    case NSPROTO_ERROR:
				    ns_err_input(m);
				    goto next;
			}
D 11
		idp_input(m,nsp);
E 11
I 11
		idp_input(m, nsp, ifp);
E 11
	} else {
		ns_error(m, NS_ERR_NOSOCK, 0);
E 8
E 7
	}
	goto next;

bad:
	m_freem(m);
	goto next;
}

u_char nsctlerrmap[PRC_NCMDS] = {
	ECONNABORTED,	ECONNABORTED,	0,		0,
	0,		0,		EHOSTDOWN,	EHOSTUNREACH,
	ENETUNREACH,	EHOSTUNREACH,	ECONNREFUSED,	ECONNREFUSED,
	EMSGSIZE,	0,		0,		0,
	0,		0,		0,		0
};

I 7
idp_donosocks = 1;

E 7
idp_ctlinput(cmd, arg)
	int cmd;
	caddr_t arg;
{
	struct ns_addr *ns;
I 7
	struct nspcb *nsp;
	struct ns_errp *errp;
E 7
	int idp_abort();
I 9
	extern struct nspcb *idp_drop();
E 9
	int type;

	if (cmd < 0 || cmd > PRC_NCMDS)
		return;
	if (nsctlerrmap[cmd] == 0)
		return;		/* XXX */
	type = NS_ERR_UNREACH_HOST;
D 11
	if (cmd == PRC_IFDOWN)
		ns = &((struct sockaddr_ns *)arg)->sns_addr;
	else if (cmd == PRC_HOSTDEAD || cmd == PRC_HOSTUNREACH)
		ns = (struct ns_addr *)arg;
	else {
E 11
I 11
	switch (cmd) {
		struct sockaddr_ns *sns;

	case PRC_IFDOWN:
	case PRC_HOSTDEAD:
	case PRC_HOSTUNREACH:
		sns = (struct sockaddr_ns *)arg;
		if (sns->sns_family != AF_INET)
			return;
		ns = &sns->sns_addr;
		break;

	default:
E 11
D 7
		ns = &((struct ns_errp *)arg)->ns_err_idp.idp_dna;
		type = ((struct ns_errp *)arg)->ns_err_num;
E 7
I 7
		errp = (struct ns_errp *)arg;
		ns = &errp->ns_err_idp.idp_dna;
		type = errp->ns_err_num;
E 7
D 9
		type = ntohs(type);
E 9
I 9
		type = ntohs((u_short)type);
E 9
	}
	switch (type) {
I 5

E 5
	case NS_ERR_UNREACH_HOST:
D 7
	case NS_ERR_NOSOCK:
E 7
D 9
		ns_pcbnotify(ns, (int)nsctlerrmap[cmd], idp_abort, 0);
E 9
I 9
		ns_pcbnotify(ns, (int)nsctlerrmap[cmd], idp_abort, (long)0);
E 9
I 7
		break;

	case NS_ERR_NOSOCK:
		nsp = ns_pcblookup(ns, errp->ns_err_idp.idp_sna.x_port,
			NS_WILDCARD);
		if(nsp && idp_donosocks && ! ns_nullhost(nsp->nsp_faddr))
D 9
			idp_drop(nsp, (int)nsctlerrmap[cmd]);
E 9
I 9
			(void) idp_drop(nsp, (int)nsctlerrmap[cmd]);
E 9
E 7
	}
}

int	idpprintfs = 0;
int	idpforwarding = 1;
/*
 * Forward a packet.  If some error occurs return the sender
 * an error packet.  Note we can't always generate a meaningful
 * error message because the NS errors don't have a large enough repetoire
 * of codes and types.
 */
struct route idp_droute;
struct route idp_sroute;

idp_forward(idp)
	register struct idp *idp;
{
	register int error, type, code;
D 2
	struct mbuf *mopt, *mcopy;
E 2
I 2
	struct mbuf *mcopy = NULL;
	int agedelta = 1;
	int flags = NS_FORWARDING;
	int ok_there = 0;
	int ok_back = 0;
E 2

	if (idpprintfs) {
		printf("forward: src ");
		ns_printhost(&idp->idp_sna);
		printf(", dst ");
		ns_printhost(&idp->idp_dna);
		printf("hop count %d\n", idp->idp_tc);
	}
	if (idpforwarding == 0) {
		/* can't tell difference between net and host */
		type = NS_ERR_UNREACH_HOST, code = 0;
		goto senderror;
	}
	idp->idp_tc++;
	if (idp->idp_tc > NS_MAXHOPS) {
		type = NS_ERR_TOO_OLD, code = 0;
		goto senderror;
	}
I 2
	/*
	 * Save at most 42 bytes of the packet in case
	 * we need to generate an NS error message to the src.
	 */
D 14
	mcopy = m_copy(dtom(idp), 0, imin(ntohs(idp->idp_len), 42));
E 14
I 14
	mcopy = m_copy(dtom(idp), 0, imin((int)ntohs(idp->idp_len), 42));
E 14

D 5
	if((ok_there = idp_do_route(&idp->idp_dna,&idp_droute))==0) {
E 5
I 5
	if ((ok_there = idp_do_route(&idp->idp_dna,&idp_droute))==0) {
E 5
		type = NS_ERR_UNREACH_HOST, code = 0;
		goto senderror;
	}
	/*
	 * Here we think about  forwarding  broadcast packets,
	 * so we try to insure that it doesn't go back out
	 * on the interface it came in on.  Also, if we
	 * are going to physically broadcast this, let us
	 * age the packet so we can eat it safely the second time around.
	 */
	if (idp->idp_dna.x_host.c_host[0] & 0x1) {
D 12
		struct ns_ifaddr *ia = ns_iaonnetof(idp->idp_dna.x_net);
E 12
I 12
		struct ns_ifaddr *ia = ns_iaonnetof(&idp->idp_dna);
E 12
		struct ifnet *ifp;
		if (ia) {
			/* I'm gonna hafta eat this packet */
			agedelta += NS_MAXHOPS - idp->idp_tc;
			idp->idp_tc = NS_MAXHOPS;
		}
		if ((ok_back = idp_do_route(&idp->idp_sna,&idp_sroute))==0) {
			/* error = ENETUNREACH; He'll never get it! */
			m_freem(dtom(idp));
			goto cleanup;
		}
		if (idp_droute.ro_rt &&
		    (ifp=idp_droute.ro_rt->rt_ifp) &&
		    idp_sroute.ro_rt &&
		    (ifp!=idp_sroute.ro_rt->rt_ifp)) {
			flags |= NS_ALLOWBROADCAST;
		} else {
			type = NS_ERR_UNREACH_HOST, code = 0;
			goto senderror;
		}
	}
E 2
	/* need to adjust checksum */
	if (idp->idp_sum!=0xffff) {
		union bytes {
			u_char c[4];
			u_short s[2];
			long l;
		} x;
		register int shift;
D 2
		x.l = 0; x.c[0] = 1;
E 2
I 2
		x.l = 0; x.c[0] = agedelta;
E 2
		shift = (((((int)ntohs(idp->idp_len))+1)>>1)-2) & 0xf;
D 18
		x.l = idp->idp_sum + (x.l << shift);
E 18
I 18
		x.l = idp->idp_sum + (x.s[0] << shift);
E 18
		x.l = x.s[0] + x.s[1];
		x.l = x.s[0] + x.s[1];
		if (x.l==0xffff) idp->idp_sum = 0; else idp->idp_sum = x.l;
	}
D 2
	mopt = m_get(M_DONTWAIT, MT_DATA);
	if (mopt == NULL) {
		m_freem(dtom(idp));
		return;
	}
E 2
I 2
	if ((error = ns_output(dtom(idp), &idp_droute, flags)) && 
	    (mcopy!=NULL)) {
		idp = mtod(mcopy, struct idp *);
		type = NS_ERR_UNSPEC_T, code = 0;
		switch (error) {
E 2

D 2
	/*
	 * Save at most 42 bytes of the packet in case
	 * we need to generate an NS error message to the src.
	 */
	mcopy = m_copy(dtom(idp), 0, imin(ntohs(idp->idp_len), 42));
E 2
I 2
		case ENETUNREACH:
		case EHOSTDOWN:
		case EHOSTUNREACH:
		case ENETDOWN:
		case EPERM:
			type = NS_ERR_UNREACH_HOST;
			break;
E 2

D 2
	if ((idp->idp_dna.x_host.c_host[0] & 0x1) == 0)
		error = ns_output(dtom(idp), (struct route *)0, NS_FORWARDING);
	/*
	 * Here we are about to forward a broadcast packet,
	 * so we try to insure that it doesn't go back out
	 * on the interface it came in on.
	 */
	else if (idp_do_route(&idp->idp_dna,&idp_droute)) {
		if (idp_do_route(&idp->idp_sna,&idp_sroute)) {
		    struct ifnet *ifp;
E 2
I 2
		case EMSGSIZE:
			type = NS_ERR_TOO_BIG;
			code = 576; /* too hard to figure out mtu here */
			break;
E 2

D 2
		    if (idp_droute.ro_rt &&
			(ifp=idp_droute.ro_rt->rt_ifp) &&
		        idp_sroute.ro_rt &&
			(ifp!=idp_sroute.ro_rt->rt_ifp)) {
				error = ns_output(dtom(idp), &idp_droute,
					      NS_FORWARDING|NS_ALLOWBROADCAST);
		    }
		    idp_undo_route(&idp_sroute);
E 2
I 2
		case ENOBUFS:
			type = NS_ERR_UNSPEC_T;
			break;
E 2
		}
I 6
		mcopy = NULL;
	senderror:
		ns_error(dtom(idp), type, code);
E 6
D 2
		idp_undo_route(&idp_droute);
E 2
	}
D 2

	if (error == 0) {
		if (mcopy)
			m_freem(mcopy);
		return;
	}
	if (mcopy == NULL)
		return;
	idp = mtod(mcopy, struct idp *);
	type = NS_ERR_UNSPEC_T, code = 0;
	switch (error) {

	case ENETUNREACH:
	case EHOSTDOWN:
	case EHOSTUNREACH:
	case ENETDOWN:
	case EPERM:
		type = NS_ERR_UNREACH_HOST;
		break;

	case EMSGSIZE:
		type = NS_ERR_TOO_BIG;
		code = 576; /* too hard to figure out mtu here */
		break;

	case ENOBUFS:
		type = NS_ERR_UNSPEC_T;
		break;
	}
E 2
D 6
senderror:
	ns_error(dtom(idp), type, code);
I 2
	mcopy = NULL;
E 6
cleanup:
	if (ok_there)
		idp_undo_route(&idp_droute);
	if (ok_back)
		idp_undo_route(&idp_sroute);
	if (mcopy != NULL)
		m_freem(mcopy);
E 2
}

idp_do_route(src, ro)
struct ns_addr *src;
struct route *ro;
{
	
	struct sockaddr_ns *dst;

	bzero((caddr_t)ro, sizeof (*ro));
	dst = (struct sockaddr_ns *)&ro->ro_dst;

	dst->sns_family = AF_NS;
	dst->sns_addr = *src;
I 5
	dst->sns_addr.x_port = 0;
E 5
	rtalloc(ro);
	if (ro->ro_rt == 0 || ro->ro_rt->rt_ifp == 0) {
D 5
		return(0);
E 5
I 5
		return (0);
E 5
	}
	ro->ro_rt->rt_use++;
D 5
	return(1);
E 5
I 5
	return (1);
E 5
}

idp_undo_route(ro)
register struct route *ro;
{
	if (ro->ro_rt) {RTFREE(ro->ro_rt);}
}
D 12
ns_watch_output(m)
E 12
I 12
static union ns_net
ns_zeronet;

ns_watch_output(m, ifp)
E 12
struct mbuf *m;
I 12
struct ifnet *ifp;
E 12
{
	register struct nspcb *nsp;
I 12
	register struct ifaddr *ia;
E 12
	/*
	 * Give any raw listeners a crack at the packet
	 */
	for (nsp = nsrawpcb.nsp_next; nsp != &nsrawpcb; nsp = nsp->nsp_next) {
D 9
		struct mbuf *m1 = m_copy(m, 0, M_COPYALL);
E 9
I 9
D 12
		struct mbuf *m1 = m_copy(m, 0, (int)M_COPYALL);
E 9
		if (m1) idp_input(m1, nsp);
E 12
I 12
		struct mbuf *m0 = m_copy(m, 0, (int)M_COPYALL);
		if (m0) {
			struct mbuf *m1 = m_get(M_DONTWAIT, MT_DATA);

			if(m1 == NULL)
				m_freem(m0);
			else {
				register struct idp *idp;

				m1->m_off = MMINOFF;
				m1->m_len = sizeof (*idp);
				m1->m_next = m0;
				idp = mtod(m1, struct idp *);
				idp->idp_sna.x_net = ns_zeronet;
				idp->idp_sna.x_host = ns_thishost;
				if (ifp && (ifp->if_flags & IFF_POINTOPOINT))
				    for(ia = ifp->if_addrlist; ia;
							ia = ia->ifa_next) {
					if (ia->ifa_addr.sa_family==AF_NS) {
					    idp->idp_sna = 
						satons_addr(ia->ifa_dstaddr);
					    break;
					}
				    }
				idp->idp_len = 0xffff;
				idp_input(m1, nsp, ifp);
			}
		}
E 12
	}
}
E 1
