h22077
s 00010/00005/00153
d D 7.4 88/06/29 17:07:10 bostic 31 30
c install approved copyright notice
e
s 00008/00002/00150
d D 7.3 87/12/07 17:45:56 bostic 30 29
c use Berkeley specific header
e
s 00001/00001/00151
d D 7.2 87/06/20 12:32:17 mckusick 29 28
c check for null mbuf ptr before freeing (4.3BSD/sys/{130,131,133})
e
s 00001/00001/00151
d D 7.1 86/06/05 00:28:54 mckusick 28 27
c 4.3BSD release version
e
s 00002/00002/00150
d D 6.8 86/02/23 23:25:05 karels 27 26
c lint
e
s 00052/00002/00100
d D 6.7 86/02/02 20:23:43 karels 26 25
c support options for raw ip
e
s 00007/00001/00095
d D 6.6 85/06/08 12:41:20 mckusick 25 24
c Add copyright
e
s 00001/00001/00095
d D 6.5 85/06/02 23:39:06 karels 24 23
c raw protocol number from raw_cb instead of protosw
e
s 00010/00010/00086
d D 6.4 84/08/29 15:36:53 bloom 23 22
c Include file changes.  No more ../h
e
s 00001/00000/00095
d D 6.3 84/07/31 17:59:30 karels 22 21
c clear ip_tos on output
e
s 00001/00000/00094
d D 6.2 83/12/15 14:58:09 karels 21 20
c must clear ip_off before output (don't want IP_DF)
e
s 00000/00000/00094
d D 6.1 83/07/29 07:12:00 sam 20 19
c 4.2 distribution
e
s 00005/00005/00089
d D 4.19 83/06/30 01:22:13 sam 19 18
c raw routing
e
s 00002/00001/00092
d D 4.18 83/05/12 15:04:24 sam 18 17
c fix ip packet forwarding to not stomp on headers when fragmented;
e
s 00005/00003/00088
d D 4.17 83/02/10 22:11:44 sam 17 16
c remove /usr/include dependencies
e
s 00001/00001/00090
d D 4.16 82/12/14 17:15:37 sam 16 15
c typed mbufs
e
s 00000/00001/00091
d D 4.15 82/10/17 14:55:42 root 15 14
c fix lint
e
s 00004/00004/00088
d D 4.14 82/10/09 05:46:42 wnj 14 13
c localize header files
e
s 00000/00002/00092
d D 4.13 82/06/20 00:54:57 sam 13 12
c purge COUNT stuff now that we can use gprof
e
s 00010/00016/00084
d D 4.12 82/06/12 23:19:43 wnj 12 11
c now the routing code might wokr
e
s 00002/00002/00098
d D 4.11 82/04/11 15:51:40 sam 11 10
c sundry patches to raw code after rewrite
e
s 00028/00010/00072
d D 4.10 82/04/10 23:41:34 sam 10 9
c purge so_addr from socket structure and start cleaning up raw code
e
s 00004/00041/00078
d D 4.9 82/03/28 14:23:19 sam 9 8
c convert interfaces to sockaddr's and add hooks for routing
e
s 00001/00001/00118
d D 4.8 82/03/15 04:44:27 wnj 8 7
c interfac queueing, restrictions on packets, tcp keep alives done 
c properly, bug fix to raw
e
s 00003/00002/00116
d D 4.7 82/03/13 12:52:30 sam 7 6
c lint
e
s 00001/00003/00117
d D 4.6 82/03/12 16:15:02 sam 6 5
c lint
e
s 00001/00001/00119
d D 4.5 82/03/05 10:20:31 root 5 4
c move location of errno.h
e
s 00005/00002/00115
d D 4.4 82/02/02 19:40:23 sam 4 3
c pass structures by reference
e
s 00005/00006/00112
d D 4.3 82/02/01 17:50:36 sam 3 2
c raw interfaces brought up to date
e
s 00078/00018/00040
d D 4.2 82/01/24 18:36:02 wnj 2 1
c early versions
e
s 00058/00000/00000
d D 4.1 81/11/29 22:19:36 wnj 1 0
c date and time created 81/11/29 22:19:36 by wnj
e
u
U
t
T
I 1
D 25
/*	%M%	%I%	%E%	*/
E 25
I 25
/*
D 28
 * Copyright (c) 1982 Regents of the University of California.
E 28
I 28
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 28
D 30
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 30
I 30
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 31
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 31
I 31
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
E 31
E 30
 *
 *	%W% (Berkeley) %G%
 */
E 25

D 23
#include "../h/param.h"
#include "../h/mbuf.h"
#include "../h/socket.h"
I 2
#include "../h/protosw.h"
E 2
#include "../h/socketvar.h"
I 17
#include "../h/errno.h"
E 23
I 23
#include "param.h"
#include "mbuf.h"
#include "socket.h"
#include "protosw.h"
#include "socketvar.h"
#include "errno.h"
E 23

E 17
I 10
#include "../net/if.h"
I 17
D 19
#include "../net/raw_cb.h"
E 19
#include "../net/route.h"
I 19
#include "../net/raw_cb.h"
E 19

E 17
E 10
D 14
#include "../net/in.h"
#include "../net/in_systm.h"
I 2
#include "../net/ip.h"
#include "../net/ip_var.h"
E 14
I 14
D 23
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
#include "../netinet/ip.h"
#include "../netinet/ip_var.h"
E 23
I 23
#include "in.h"
#include "in_systm.h"
#include "ip.h"
#include "ip_var.h"
E 23
E 14
D 17
#include "../net/raw_cb.h"
I 12
#include "../net/route.h"
E 12
D 5
#include "/usr/include/errno.h"
E 5
I 5
D 10
#include "../errno.h"
E 10
I 10
#include <errno.h>
E 17
E 10
E 5
E 2

/*
D 2
 * Raw protocol interface.
E 2
I 2
 * Raw interface to IP protocol.
E 2
 */
D 2
/*ARGSUSED*/
E 2
I 2

D 3
static struct sockaddr_in ripaddr = { PF_INET };
E 3
I 3
D 9
static struct sockaddr_in ripdst = { PF_INET };
static struct sockaddr_in ripsrc = { PF_INET };
E 3
static struct sockproto ripproto = { AF_INET };
E 9
I 9
D 19
static struct sockaddr_in ripdst = { AF_INET };
static struct sockaddr_in ripsrc = { AF_INET };
static struct sockproto ripproto = { PF_INET };
E 19
I 19
struct	sockaddr_in ripdst = { AF_INET };
struct	sockaddr_in ripsrc = { AF_INET };
struct	sockproto ripproto = { PF_INET };
E 19
E 9
D 10

E 10
/*
 * Setup generic address and protocol structures
 * for raw_input routine, then pass them along with
 * mbuf chain.
 */
E 2
rip_input(m)
	struct mbuf *m;
{
I 2
	register struct ip *ip = mtod(m, struct ip *);
D 6
	struct sockaddr_in sin;
	struct sockproto sp;
E 6
E 2

D 13
COUNT(RIP_INPUT);
E 13
D 2

	/* call raw_input with prepared parameters */
E 2
I 2
	ripproto.sp_protocol = ip->ip_p;
D 3
	ripaddr.sin_addr = ip->ip_dst;
	raw_input(m, ripproto, ripaddr);
E 3
I 3
	ripdst.sin_addr = ip->ip_dst;
	ripsrc.sin_addr = ip->ip_src;
D 4
	raw_input(m, ripproto, ripdst, ripsrc);
E 4
I 4
D 7
	raw_input(m, &ripproto, &ripdst, &ripsrc);
E 7
I 7
D 11
	raw_input(m, &ripproto, (struct sockaddr *)&ripdst,
	  (struct sockaddr *)&ripsrc);
E 11
I 11
	raw_input(m, &ripproto, (struct sockaddr *)&ripsrc,
	  (struct sockaddr *)&ripdst);
E 11
E 7
E 4
E 3
E 2
}

D 9
/*ARGSUSED*/
rip_ctlinput(m)
	struct mbuf *m;
{
D 2

E 2
COUNT(RIP_CTLINPUT);
D 2

E 2
}

E 9
D 2
/*ARGSUSED*/
rip_output(m)
	struct mbuf *m;
E 2
I 2
/*
 * Generate IP header and pass packet to ip_output.
 * Tack on options user may have setup with control call.
 */
rip_output(m0, so)
	struct mbuf *m0;
	struct socket *so;
E 2
{
I 2
	register struct mbuf *m;
	register struct ip *ip;
D 10
	register int len = 0;
	register struct rawcb *rp = sotorawcb(so);
E 10
I 10
	int len = 0, error;
	struct rawcb *rp = sotorawcb(so);
D 15
	struct ifnet *ifp;
E 15
D 12
	struct sockaddr_in *src;
E 12
I 12
	struct sockaddr_in *sin;
E 12
E 10
E 2

D 13
COUNT(RIP_OUTPUT);
E 13
D 2

E 2
I 2
D 3
	if (so->so_options & SO_DEBUG)
		printf("rip_output\n");
E 3
	/*
	 * Calculate data length and get an mbuf
	 * for IP header.
	 */
	for (m = m0; m; m = m->m_next)
		len += m->m_len;
D 16
	m = m_get(M_DONTWAIT);
E 16
I 16
	m = m_get(M_DONTWAIT, MT_HEADER);
E 16
	if (m == 0) {
D 4
		(void) m_freem(m);
E 4
I 4
D 10
		m_freem(m);
E 4
D 6
		return;
E 6
I 6
		return (0);
E 10
I 10
		error = ENOBUFS;
		goto bad;
E 10
E 6
	}
	
	/*
	 * Fill in IP header as needed.
	 */
	m->m_off = MMAXOFF - sizeof(struct ip);
	m->m_len = sizeof(struct ip);
	m->m_next = m0;
	ip = mtod(m, struct ip *);
I 22
	ip->ip_tos = 0;
E 22
I 21
	ip->ip_off = 0;
E 21
D 24
	ip->ip_p = so->so_proto->pr_protocol;
E 24
I 24
	ip->ip_p = rp->rcb_proto.sp_protocol;
E 24
	ip->ip_len = sizeof(struct ip) + len;
D 10
	ip->ip_dst =
		((struct sockaddr_in *)&rp->rcb_addr)->sin_addr;
	ip->ip_src =
		((struct sockaddr_in *)&so->so_addr)->sin_addr;
E 10
I 10
D 12
	ip->ip_dst = ((struct sockaddr_in *)&rp->rcb_faddr)->sin_addr;
	/* local address may not be specified -- XXX */
	ifp = if_ifonnetof(ip->ip_dst.s_net);
	if (ifp == 0) {
		error = ENETUNREACH;
		goto bad;
	}
	if (rp->rcb_flags & RAW_LADDR)
		src = (struct sockaddr_in *)&rp->rcb_laddr;
	else {
		if (ifp->if_addr.sa_family != AF_INET) {
E 12
I 12
	if (rp->rcb_flags & RAW_LADDR) {
		sin = (struct sockaddr_in *)&rp->rcb_laddr;
		if (sin->sin_family != AF_INET) {
E 12
			error = EAFNOSUPPORT;
			goto bad;
		}
D 12
		src = (struct sockaddr_in *)&ifp->if_addr;
	}
	ip->ip_src = src->sin_addr;
E 12
I 12
		ip->ip_src.s_addr = sin->sin_addr.s_addr;
	} else
		ip->ip_src.s_addr = 0;
	ip->ip_dst = ((struct sockaddr_in *)&rp->rcb_faddr)->sin_addr;
E 12
E 10
	ip->ip_ttl = MAXTTL;
D 3
printf("ip=<p=%d,len=%d,dst=%x,src=%x>\n",ip->ip_p,ip->ip_len,ip->ip_dst,ip->ip_src);
E 3
D 7
	return (ip_output(m, 0));
E 7
I 7
D 8
	return (ip_output(m, (struct mbuf *)0));
E 8
I 8
D 9
	return (ip_output(m, (struct mbuf *)0, 1));
E 8
E 7
E 2
}

D 2
/*ARGSUSED*/
E 2
I 2
/*
 * Intercept control operations related to
 * handling of IP options.  Otherwise,
 * just pass things on to the raw_usrreq
 * routine for setup and tear down of
 * raw control block data structures.
 */
E 2
rip_usrreq(so, req, m, addr)
	struct socket *so;
	int req;
	struct mbuf *m;
	caddr_t addr;
{
I 2
	register struct rawcb *rp = sotorawcb(so);
E 2

COUNT(RAW_USRREQ);
I 2
	if (rp == 0 && req != PRU_ATTACH)
		return (EINVAL);
E 2

D 2
}

rip_slowtimo()
{

COUNT(RIP_SLOWTIMO);

E 2
I 2
	switch (req) {
	
I 4
	/*
	 * SHOULD HAVE CONTROL TO SET PROTOCOL NUMBER (e.g. GGP)
	 */
E 4
	case PRU_CONTROL:
		return (EOPNOTSUPP);
	}
	return (raw_usrreq(so, req, m, addr));
E 9
I 9
D 12
	return (ip_output(m, (struct mbuf *)0, 0, 1));
E 12
I 12
D 18
	return (ip_output(m, (struct mbuf *)0, &routetoif, 1));
E 18
I 18
D 19
	return (ip_output(m, (struct mbuf *)0, (struct route *)0, 
E 19
I 19
D 26
	return (ip_output(m, (struct mbuf *)0, &rp->rcb_route, 
E 19
	   IP_ROUTETOIF|IP_ALLOWBROADCAST));
E 26
I 26
	return (ip_output(m, rp->rcb_options, &rp->rcb_route, 
	   (so->so_options & SO_DONTROUTE) | IP_ALLOWBROADCAST));
E 26
E 18
E 12
I 10
bad:
	m_freem(m);
I 26
	return (error);
}

/*
 * Raw IP socket option processing.
 */
rip_ctloutput(op, so, level, optname, m)
	int op;
	struct socket *so;
	int level, optname;
	struct mbuf **m;
{
	int error = 0;
	register struct rawcb *rp = sotorawcb(so);

	if (level != IPPROTO_IP)
		error = EINVAL;
	else switch (op) {

	case PRCO_SETOPT:
		switch (optname) {
		case IP_OPTIONS:
			return (ip_pcbopts(&rp->rcb_options, *m));

		default:
			error = EINVAL;
			break;
		}
		break;

	case PRCO_GETOPT:
		switch (optname) {
		case IP_OPTIONS:
			*m = m_get(M_WAIT, MT_SOOPTS);
			if (rp->rcb_options) {
				(*m)->m_off = rp->rcb_options->m_off;
				(*m)->m_len = rp->rcb_options->m_len;
				bcopy(mtod(rp->rcb_options, caddr_t),
D 27
				    mtod(*m, caddr_t), (*m)->m_len);
E 27
I 27
				    mtod(*m, caddr_t), (unsigned)(*m)->m_len);
E 27
			} else
				(*m)->m_len = 0;
			break;
		default:
			error = EINVAL;
			break;
		}
		break;
	}
D 29
	if (op == PRCO_SETOPT)
E 29
I 29
	if (op == PRCO_SETOPT && *m)
E 29
D 27
		m_free(*m);
E 27
I 27
		(void)m_free(*m);
E 27
E 26
	return (error);
E 10
E 9
E 2
}
E 1
