h43944
s 00010/00005/00312
d D 7.4 88/06/27 18:59:41 bostic 50 49
c install approved copyright notice
e
s 00008/00002/00309
d D 7.3 87/12/30 11:57:38 bostic 49 48
c add Berkeley header
e
s 00001/00001/00310
d D 7.2 86/10/28 22:31:23 karels 48 47
c merge in tahoe
e
s 00001/00001/00310
d D 7.1 86/06/04 23:41:56 mckusick 47 46
c 4.3BSD release version
e
s 00001/00001/00310
d D 6.13 86/02/23 23:22:58 karels 46 45
c lint
e
s 00000/00018/00311
d D 6.12 86/02/03 20:11:44 karels 45 44
c consolidate route caching, manipulation in IP
e
s 00010/00010/00319
d D 6.11 86/02/02 20:24:38 karels 44 43
c use socket DONTROUTE flag instead of that in rcb_flags
c (there's a way to set it)
e
s 00002/00001/00327
d D 6.10 85/11/19 19:21:34 karels 43 42
c don't free ioctl commands, they don't make good pointers
e
s 00001/00000/00327
d D 6.9 85/10/17 11:59:19 karels 42 41
c can't listen on raw socket, but don't panic
e
s 00007/00001/00320
d D 6.8 85/06/08 12:27:14 mckusick 41 40
c Add copyright
e
s 00004/00006/00317
d D 6.7 85/06/02 23:38:03 karels 40 39
c allow raw socket of any protocol if family has wildcard entry,
c with actual protocol number in raw_cb instead of protosw
e
s 00014/00017/00309
d D 6.6 85/05/30 23:01:56 karels 39 37
c don't free header before finished looking at it; lose 4 gotos
e
s 00012/00016/00310
d R 6.6 85/05/27 21:55:41 karels 38 37
c don't free header mbuf until finished with it; lose 4 goto's
e
s 00011/00011/00315
d D 6.5 84/08/28 17:39:09 bloom 37 35
c fix header includes.  no more ../h
e
s 00007/00007/00319
d R 6.5 84/08/28 17:13:41 bloom 36 35
c Change include paths.  No more ../h.
e
s 00002/00001/00324
d D 6.4 84/08/21 10:20:54 karels 35 34
c change protocol family number in protosw to pointer to domain
e
s 00006/00001/00319
d D 6.3 84/08/20 16:37:41 karels 34 33
c add sostat
e
s 00009/00009/00311
d D 6.2 84/07/26 17:07:56 bloom 33 32
c Fix mbuf handling for unsupported operations
e
s 00000/00000/00320
d D 6.1 83/07/29 07:08:48 sam 32 31
c 4.2 distribution
e
s 00006/00000/00314
d D 4.31 83/07/25 21:54:13 sam 31 30
c getpeer
e
s 00000/00002/00314
d D 4.30 83/06/30 01:21:27 sam 30 29
c it works, don't delete
e
s 00019/00000/00297
d D 4.29 83/06/30 01:14:37 sam 29 28
c routing for raw stuff
e
s 00015/00009/00282
d D 4.28 83/06/14 22:10:47 sam 28 27
c socketpair
e
s 00003/00001/00288
d D 4.27 83/06/12 19:47:29 sam 27 26
c revamp network ioctls; add IFF_NOTRAILERS
e
s 00055/00022/00234
d D 4.26 83/05/27 13:56:41 sam 26 25
c lint and wnj changes
e
s 00004/00002/00252
d D 4.25 83/02/10 22:01:00 sam 25 24
c remove /usr/include dependencies
e
s 00001/00002/00253
d D 4.24 83/01/13 18:33:11 sam 24 23
c no more opt parameter to usrreq
e
s 00001/00001/00254
d D 4.23 82/12/14 17:13:50 sam 23 22
c typed mbufs
e
s 00001/00001/00254
d D 4.22 82/10/20 03:15:34 root 22 21
c lint
e
s 00000/00002/00255
d D 4.21 82/10/20 01:19:47 root 21 20
c lint
e
s 00003/00001/00254
d D 4.20 82/10/17 22:16:23 root 20 19
c lint
e
s 00012/00012/00243
d D 4.19 82/10/09 05:40:24 wnj 19 18
c header file dependencies fixed up and untested changes to raw interface
e
s 00001/00001/00254
d D 4.18 82/07/24 18:21:27 root 18 17
c from calder
e
s 00000/00005/00255
d D 4.17 82/06/20 00:55:06 sam 17 16
c purge COUNT stuff now that we can use gprof
e
s 00003/00000/00257
d D 4.16 82/04/25 18:35:52 sam 16 15
c icmp works with tcp and friends
e
s 00015/00008/00242
d D 4.15 82/04/24 20:38:36 sam 15 14
c icmp and ctlinput working -- missing protocol specific ctlinput's
e
s 00007/00024/00243
d D 4.14 82/04/11 15:51:44 sam 14 13
c sundry patches to raw code after rewrite
e
s 00039/00044/00228
d D 4.13 82/04/10 23:41:42 sam 13 12
c purge so_addr from socket structure and start cleaning up raw code
e
s 00001/00001/00271
d D 4.12 82/04/10 18:26:50 sam 12 11
c invert output path to pass back error indications
e
s 00001/00001/00271
d D 4.11 82/03/19 01:49:13 wnj 11 10
c fix to use only one soft intr for net thereby fixing bug in raw sockets
e
s 00012/00003/00260
d D 4.10 82/03/15 04:44:31 wnj 10 9
c interfac queueing, restrictions on packets, tcp keep alives done 
c properly, bug fix to raw
e
s 00001/00001/00262
d D 4.9 82/03/13 12:52:39 sam 9 8
c lint
e
s 00007/00003/00256
d D 4.8 82/03/05 14:07:13 wnj 8 7
c minor fixes
e
s 00009/00005/00250
d D 4.7 82/02/02 19:38:09 sam 7 6
c eliminate passing structures on the stack
e
s 00019/00019/00236
d D 4.6 82/02/01 17:50:29 sam 6 5
c raw interfaces brought up to date
e
s 00203/00018/00052
d D 4.5 82/01/24 18:35:57 wnj 5 4
c early versions
e
s 00001/00001/00069
d D 4.4 82/01/19 07:30:04 root 4 3
c m_get(0) -> m_get(M_DONTWAIT)
e
s 00000/00001/00070
d D 4.3 81/12/03 17:30:05 wnj 3 2
c cleanup
e
s 00000/00001/00071
d D 4.2 81/12/02 16:58:56 wnj 2 1
c yet more lint
e
s 00072/00000/00000
d D 4.1 81/11/29 22:17:03 wnj 1 0
c date and time created 81/11/29 22:17:03 by wnj
e
u
U
t
T
I 1
D 41
/*	%M%	%I%	%E%	*/
E 41
I 41
/*
D 47
 * Copyright (c) 1980 Regents of the University of California.
E 47
I 47
 * Copyright (c) 1980, 1986 Regents of the University of California.
E 47
D 49
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 49
I 49
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 50
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 50
I 50
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
E 50
E 49
 *
 *	%W% (Berkeley) %G%
 */
E 41

D 37
#include "../h/param.h"
#include "../h/mbuf.h"
I 35
#include "../h/domain.h"
E 35
I 5
#include "../h/protosw.h"
E 5
#include "../h/socket.h"
#include "../h/socketvar.h"
D 20
#include "../h/mtpr.h"
E 20
I 20
D 25
#include "../vax/mtpr.h"
E 25
I 25
#include "../h/errno.h"
E 37
I 37
#include "param.h"
#include "mbuf.h"
#include "domain.h"
#include "protosw.h"
#include "socket.h"
#include "socketvar.h"
#include "errno.h"
E 37

E 25
E 20
D 19
#include "../net/in.h"
#include "../net/in_systm.h"
E 19
D 37
#include "../net/if.h"
I 29
#include "../net/route.h"
E 29
I 19
#include "../net/netisr.h"
E 19
I 5
#include "../net/raw_cb.h"
E 37
I 37
#include "if.h"
#include "route.h"
#include "netisr.h"
#include "raw_cb.h"
E 37
D 8
#include "/usr/include/errno.h"
E 8
I 8
D 13
#include "../errno.h"
E 13
I 13
D 25
#include <errno.h>
E 25
I 25

D 48
#include "../vax/mtpr.h"
E 48
I 48
#include "../machine/mtpr.h"
E 48
E 25
E 13
E 8
E 5

I 10
D 21
int	rawqmaxlen = IFQ_MAXLEN;

E 21
E 10
/*
I 5
 * Initialize raw connection block q.
D 10
*/
E 10
I 10
 */
E 10
raw_init()
{
I 10

E 10
D 17
COUNT(RAW_INIT);
E 17
	rawcb.rcb_next = rawcb.rcb_prev = &rawcb;
I 10
	rawintrq.ifq_maxlen = IFQ_MAXLEN;
E 10
}

/*
E 5
 * Raw protocol interface.
 */
D 5
raw_input(m, pf, af)
	struct mbuf *m;
E 5
I 5
D 6
raw_input(m0, pf, af)
E 6
I 6
D 13
raw_input(m0, pf, daf, saf)
E 13
I 13
D 14
raw_input(m0, proto, dst, src)
E 14
I 14
raw_input(m0, proto, src, dst)
E 14
E 13
E 6
	struct mbuf *m0;
E 5
D 7
	struct sockproto pf;
D 6
	struct sockaddr af;
E 6
I 6
	struct sockaddr daf, saf;
E 7
I 7
D 13
	struct sockproto *pf;
	struct sockaddr *daf, *saf;
E 13
I 13
	struct sockproto *proto;
D 14
	struct sockaddr *dst, *src;
E 14
I 14
	struct sockaddr *src, *dst;
E 14
E 13
E 7
E 6
{
D 5
	struct mbuf *mh;
E 5
I 5
	register struct mbuf *m;
	struct raw_header *rh;
E 5
D 2
	struct sockproto *pfp;
E 2
	int s;

I 7
D 17
COUNT(RAW_INPUT);
E 17
E 7
D 4
	mh = m_get(0);
E 4
I 4
D 5
	mh = m_get(M_DONTWAIT);
E 4
	if (mh == 0)
		goto drop;
	mh->m_next = m;
	mh->m_off = MMINOFF + sizeof (struct sockproto);
	*mtod(m, struct sockaddr *) = af;
	mh->m_off = MMINOFF;
	*mtod(m, struct sockproto *) = pf;
	mh->m_len = sizeof (struct sockproto) + sizeof (struct sockaddr);
E 5
I 5
	/*
	 * Rip off an mbuf for a generic header.
	 */
D 23
	m = m_get(M_DONTWAIT);
E 23
I 23
	m = m_get(M_DONTWAIT, MT_HEADER);
E 23
	if (m == 0) {
		m_freem(m0);
		return;
	}
	m->m_next = m0;
D 19
	m->m_off = MMINOFF;
E 19
	m->m_len = sizeof(struct raw_header);
	rh = mtod(m, struct raw_header *);
D 6
	rh->raw_address = af;
E 6
I 6
D 7
	rh->raw_dst = daf;
	rh->raw_src = saf;
E 6
	rh->raw_protocol = pf;
E 7
I 7
D 13
	rh->raw_dst = *daf;
	rh->raw_src = *saf;
	rh->raw_protocol = *pf;
E 13
I 13
	rh->raw_dst = *dst;
	rh->raw_src = *src;
	rh->raw_proto = *proto;
E 13
E 7

	/*
	 * Header now contains enough info to decide
	 * which socket to place packet in (if any).
	 * Queue it up for the raw protocol process
	 * running at software interrupt level.
	 */
E 5
	s = splimp();
D 5
	IF_ENQUEUE(&rawintrq, mh);
E 5
I 5
D 10
	IF_ENQUEUE(&rawintrq, m);
E 10
I 10
	if (IF_QFULL(&rawintrq))
		m_freem(m);
	else
		IF_ENQUEUE(&rawintrq, m);
E 10
E 5
	splx(s);
D 11
	setrawintr();
E 11
I 11
	schednetisr(NETISR_RAW);
E 11
D 5
	return;
drop:
	m_freem(m);
E 5
}

I 5
/*
 * Raw protocol input routine.  Process packets entered
 * into the queue at interrupt time.  Find the socket
 * associated with the packet(s) and move them over.  If
 * nothing exists for this packet, drop it.
 */
E 5
rawintr()
{
	int s;
	struct mbuf *m;
I 5
	register struct rawcb *rp;
D 13
	register struct socket *so;
	register struct protosw *pr;
	register struct sockproto *sp;
	register struct sockaddr *sa;
I 6
	struct raw_header *rawp;
E 13
I 13
D 14
	register struct sockaddr *laddr;
E 14
D 40
	register struct protosw *lproto;
E 40
D 14
	struct raw_header *rh;
E 14
I 14
	register struct raw_header *rh;
E 14
E 13
E 6
	struct socket *last;
E 5

D 17
COUNT(RAWINTR);
E 17
next:
	s = splimp();
D 3
/*###45 [cc] rawintrq undefined %%%*/
E 3
	IF_DEQUEUE(&rawintrq, m);
	splx(s);
	if (m == 0)
		return;
D 5
	/* ... */
	goto drop;
E 5
I 5
D 6
	sp = &(mtod(m, struct raw_header *)->raw_protocol);
	sa = &(mtod(m, struct raw_header *)->raw_address);
E 6
I 6
D 13
	rawp = mtod(m, struct raw_header *);
	sp = &rawp->raw_protocol;
	sa = &rawp->raw_dst;
E 13
I 13
	rh = mtod(m, struct raw_header *);
E 13
E 6
D 14

	/*
	 * Find the appropriate socket(s) in which to place this
	 * packet.  This is done by matching the protocol and
	 * address information prepended by raw_input against
	 * the info stored in the control block structures.
	 */
E 14
	last = 0;
	for (rp = rawcb.rcb_next; rp != &rawcb; rp = rp->rcb_next) {
D 13
		so = rp->rcb_socket;
		pr = so->so_proto;
D 6

		if (so->so_options & SO_DEBUG) {
			printf("rawintr: sp=<%d,%d>, af=<%d,%x>\n",
			 sp->sp_family, sp->sp_protocol, sa->sa_family,
			 ((struct sockaddr_in *)sa)->sin_addr);
			printf("pr=<%d,%d>\n", pr->pr_family, pr->pr_protocol);
		}
E 6
		if (pr->pr_family != sp->sp_family ||
D 8
		    pr->pr_protocol != sp->sp_protocol)
E 8
I 8
		    (pr->pr_protocol && pr->pr_protocol != sp->sp_protocol))
E 13
I 13
D 40
		lproto = rp->rcb_socket->so_proto;
D 35
		if (lproto->pr_family != rh->raw_proto.sp_family)
E 35
I 35
		if (lproto->pr_domain->dom_family != rh->raw_proto.sp_family)
E 40
I 40
		if (rp->rcb_proto.sp_family != rh->raw_proto.sp_family)
E 40
E 35
E 13
E 8
			continue;
D 6
		printf("rawintr: so=<%d,%x>\n", so->so_addr.sa_family,
			((struct sockaddr_in *)&so->so_addr)->sin_addr);
E 6
D 8
		if (sa->sa_family != so->so_addr.sa_family)
E 8
I 8
D 13
		if (so->so_addr.sa_family && 
		    sa->sa_family != so->so_addr.sa_family)
E 13
I 13
D 40
		if (lproto->pr_protocol &&
		    lproto->pr_protocol != rh->raw_proto.sp_protocol)
E 40
I 40
		if (rp->rcb_proto.sp_protocol  &&
		    rp->rcb_proto.sp_protocol != rh->raw_proto.sp_protocol)
E 40
E 13
E 8
			continue;
I 13
D 14
		laddr = &rp->rcb_laddr;
		if (laddr->sa_family &&
		    laddr->sa_family != rh->raw_dst.sa_family)
			continue;
E 14
E 13
		/*
		 * We assume the lower level routines have
		 * placed the address in a canonical format
D 13
		 * suitable for a structure comparison. Packets
		 * are duplicated for each receiving socket.
I 7
		 *
		 * SHOULD HAVE A NUMBER OF MECHANISMS FOR
		 * MATCHING BASED ON rcb_flags
E 13
I 13
		 * suitable for a structure comparison.
E 13
E 7
		 */
I 14
#define equal(a1, a2) \
	(bcmp((caddr_t)&(a1), (caddr_t)&(a2), sizeof (struct sockaddr)) == 0)
E 14
D 13
		if ((rp->rcb_flags & RAW_ADDR) &&
		    bcmp(sa->sa_data, so->so_addr.sa_data, 14) != 0)
E 13
I 13
		if ((rp->rcb_flags & RAW_LADDR) &&
D 14
		    bcmp(laddr->sa_data, rh->raw_dst.sa_data, 14) != 0)
E 14
I 14
		    !equal(rp->rcb_laddr, rh->raw_dst))
E 14
E 13
			continue;
I 13
		if ((rp->rcb_flags & RAW_FADDR) &&
D 14
		    bcmp(rp->rcb_faddr.sa_data, rh->raw_src.sa_data, 14) != 0)
E 14
I 14
		    !equal(rp->rcb_faddr, rh->raw_src))
E 14
			continue;
E 13
D 14
		/*
		 * To avoid extraneous packet copies, we keep
		 * track of the last socket the packet should be
		 * placed in, and make copies only after finding a
		 * socket which "collides".
		 */
E 14
		if (last) {
			struct mbuf *n;
D 14

E 14
D 9
			if (n = m_copy(m->m_next, 0, M_COPYALL))
E 9
I 9
D 18
			if (n = m_copy(m->m_next, 0, (int)M_COPYALL))
E 18
I 18
D 39
			if ((n = m_copy(m->m_next, 0, (int)M_COPYALL)) == 0)
E 18
E 9
				goto nospace;
D 6
			sbappend(&last->so_rcv, n);
E 6
I 6
D 13
			if (sbappendaddr(&last->so_rcv, &rawp->raw_src, n) == 0) {
				/*
				 * Should drop notification of lost packet
				 * into this guy's queue, but...
				 */
E 13
I 13
D 26
			if (sbappendaddr(&last->so_rcv, &rh->raw_src, n)==0) {
E 26
I 26
			if (sbappendaddr(&last->so_rcv, &rh->raw_src,
			    n, (struct mbuf *)0) == 0) {
E 26
				/* should notify about lost packet */
E 13
				m_freem(n);
				goto nospace;
E 39
I 39
			if (n = m_copy(m->m_next, 0, (int)M_COPYALL)) {
				if (sbappendaddr(&last->so_rcv, &rh->raw_src,
				    n, (struct mbuf *)0) == 0)
					/* should notify about lost packet */
					m_freem(n);
				else
					sorwakeup(last);
E 39
			}
E 6
D 39
			sorwakeup(last);
E 39
		}
D 39
nospace:
E 39
D 13
		last = so;
E 13
I 13
		last = rp->rcb_socket;
E 13
	}
D 15
	if (last == 0)
		goto drop;
D 6
	m = m_free(m);		/* drop generic header */
	sbappend(&last->so_rcv, m->m_next);
E 6
I 6
D 13
	if (sbappendaddr(&last->so_rcv, &rawp->raw_src, m->m_next) == 0)
I 8
{
printf("rawintr: sbappendaddr failed\n");
E 13
I 13
	m = m_free(m);		/* header */
	if (sbappendaddr(&last->so_rcv, &rh->raw_src, m) == 0)
E 13
E 8
		goto drop;
I 8
D 13
}
E 8
	(void) m_free(m);	/* generic header */
E 13
E 6
	sorwakeup(last);
	goto next;
E 15
I 15
	if (last) {
D 39
		m = m_free(m);		/* header */
E 39
D 26
		if (sbappendaddr(&last->so_rcv, &rh->raw_src, m) == 0)
E 26
I 26
		if (sbappendaddr(&last->so_rcv, &rh->raw_src,
D 39
		    m, (struct mbuf *)0) == 0)
E 26
			goto drop;
		sorwakeup(last);
		goto next;
	}
E 15
E 5
drop:
	m_freem(m);
E 39
I 39
		    m->m_next, (struct mbuf *)0) == 0)
			m_freem(m->m_next);
		else
			sorwakeup(last);
		(void) m_free(m);		/* header */
	} else
		m_freem(m);
E 39
	goto next;
}

I 20
/*ARGSUSED*/
E 20
I 15
raw_ctlinput(cmd, arg)
	int cmd;
D 46
	caddr_t arg;
E 46
I 46
	struct sockaddr *arg;
E 46
{
D 17
COUNT(RAW_CTLINPUT);
E 17
I 16

	if (cmd < 0 || cmd > PRC_NCMDS)
		return;
I 20
	/* INCOMPLETE */
E 20
E 16
}

E 15
/*ARGSUSED*/
D 19
raw_usrreq(so, req, m, addr)
E 19
I 19
D 24
raw_usrreq(so, req, m, nam, opt)
E 24
I 24
D 26
raw_usrreq(so, req, m, nam)
E 26
I 26
raw_usrreq(so, req, m, nam, rights)
E 26
E 24
E 19
	struct socket *so;
	int req;
D 19
	struct mbuf *m;
	caddr_t addr;
E 19
I 19
D 26
	struct mbuf *m, *nam;
E 26
I 26
	struct mbuf *m, *nam, *rights;
E 26
D 24
	struct socketopt *opt;
E 24
E 19
{
I 5
	register struct rawcb *rp = sotorawcb(so);
D 26
	int error = 0;
E 26
I 26
	register int error = 0;
E 26
E 5

I 43
	if (req == PRU_CONTROL)
		return (EOPNOTSUPP);
E 43
D 17
COUNT(RAW_USRREQ);
E 17
I 5
D 6
	if (so->so_options & SO_DEBUG)
		printf("raw_usrreq: req=%d\n");
E 6
D 26
	if (rp == 0 && req != PRU_ATTACH)
		return (EINVAL);
E 5

E 26
I 26
	if (rights && rights->m_len) {
		error = EOPNOTSUPP;
		goto release;
	}
	if (rp == 0 && req != PRU_ATTACH) {
		error = EINVAL;
		goto release;
	}
E 26
I 5
	switch (req) {

	/*
	 * Allocate a raw control block and fill in the
	 * necessary info to allow packets to be routed to
	 * the appropriate raw interface routine.
	 */
	case PRU_ATTACH:
I 10
D 26
		if ((so->so_state & SS_PRIV) == 0)
D 15
			return (EPERM);
E 15
I 15
			return (EACCES);
E 15
E 10
		if (rp)
D 10
			return (EINVAL);;
E 10
I 10
			return (EINVAL);
E 26
I 26
		if ((so->so_state & SS_PRIV) == 0) {
			error = EACCES;
D 28
			goto release;
E 28
I 28
			break;
E 28
		}
		if (rp) {
			error = EINVAL;
D 28
			goto release;
E 28
I 28
			break;
E 28
		}
E 26
E 10
D 19
		error = raw_attach(so, (struct sockaddr *)addr);
E 19
I 19
D 40
		error = raw_attach(so);
E 40
I 40
		error = raw_attach(so, (int)nam);
E 40
E 19
		break;

	/*
	 * Destroy state just before socket deallocation.
	 * Flush data or not depending on the options.
	 */
	case PRU_DETACH:
D 26
		if (rp == 0)
			return (ENOTCONN);
E 26
I 26
		if (rp == 0) {
			error = ENOTCONN;
D 28
			goto release;
E 28
I 28
			break;
E 28
		}
E 26
		raw_detach(rp);
		break;

	/*
	 * If a socket isn't bound to a single address,
	 * the raw input routine will hand it anything
	 * within that protocol family (assuming there's
	 * nothing else around it should go to). 
	 */
	case PRU_CONNECT:
D 13
		if (rp->rcb_flags & RAW_ADDR)
E 13
I 13
D 26
		if (rp->rcb_flags & RAW_FADDR)
E 13
			return (EISCONN);
E 26
I 26
		if (rp->rcb_flags & RAW_FADDR) {
			error = EISCONN;
D 28
			goto release;
E 28
I 28
			break;
E 28
		}
E 26
D 19
		raw_connaddr(rp, (struct sockaddr *)addr);
E 19
I 19
		raw_connaddr(rp, nam);
E 19
		soisconnected(so);
		break;

I 28
	case PRU_CONNECT2:
		error = EOPNOTSUPP;
		goto release;

E 28
I 26
	case PRU_BIND:
		if (rp->rcb_flags & RAW_LADDR) {
			error = EINVAL;			/* XXX */
D 28
			goto release;
E 28
I 28
			break;
E 28
		}
		error = raw_bind(so, nam);
		break;

E 26
	case PRU_DISCONNECT:
D 13
		if ((rp->rcb_flags & RAW_ADDR) == 0)
E 13
I 13
D 26
		if ((rp->rcb_flags & RAW_FADDR) == 0)
E 13
			return (ENOTCONN);
E 26
I 26
		if ((rp->rcb_flags & RAW_FADDR) == 0) {
			error = ENOTCONN;
D 28
			goto release;
E 28
I 28
			break;
E 28
		}
I 29
D 45
		if (rp->rcb_route.ro_rt)
			rtfree(rp->rcb_route.ro_rt);
E 45
E 29
E 26
		raw_disconnect(rp);
		soisdisconnected(so);
		break;

	/*
	 * Mark the connection as being incapable of further input.
	 */
	case PRU_SHUTDOWN:
		socantsendmore(so);
		break;

	/*
	 * Ship a packet out.  The appropriate raw output
	 * routine handles any massaging necessary.
	 */
	case PRU_SEND:
D 19
		if (addr) {
E 19
I 19
		if (nam) {
E 19
D 13
			if (rp->rcb_flags & RAW_ADDR)
E 13
I 13
D 26
			if (rp->rcb_flags & RAW_FADDR)
E 13
				return (EISCONN);
E 26
I 26
			if (rp->rcb_flags & RAW_FADDR) {
				error = EISCONN;
D 28
				goto release;
E 28
I 28
				break;
E 28
			}
E 26
D 19
			raw_connaddr(rp, (struct sockaddr *)addr);
E 19
I 19
			raw_connaddr(rp, nam);
E 19
D 13
		} else if ((rp->rcb_flags & RAW_ADDR) == 0)
E 13
I 13
D 26
		} else if ((rp->rcb_flags & RAW_FADDR) == 0)
E 13
			return (ENOTCONN);
E 26
I 26
		} else if ((rp->rcb_flags & RAW_FADDR) == 0) {
			error = ENOTCONN;
D 28
			goto release;
E 28
I 28
			break;
E 28
D 45
		}
I 29
D 30
#ifdef notdef
E 30
		/*
		 * Check for routing.  If new foreign address, or
		 * no route presently in use, try to allocate new
		 * route.  On failure, just hand packet to output
		 * routine anyway in case it can handle it.
		 */
D 44
		if ((rp->rcb_flags & RAW_DONTROUTE) == 0)
			if (!equal(rp->rcb_faddr, rp->rcb_route.ro_dst) ||
			    rp->rcb_route.ro_rt == 0) {
D 33
				if (rp->rcb_route.ro_rt)
					rtfree(rp->rcb_route.ro_rt);
E 33
I 33
				if (rp->rcb_route.ro_rt) {
					RTFREE(rp->rcb_route.ro_rt);
					rp->rcb_route.ro_rt = NULL;
				}
E 33
				rp->rcb_route.ro_dst = rp->rcb_faddr;
				rtalloc(&rp->rcb_route);
			}
E 44
I 44
		if ((!equal(rp->rcb_faddr, rp->rcb_route.ro_dst) ||
		    (so->so_options & SO_DONTROUTE)) && rp->rcb_route.ro_rt) {
			RTFREE(rp->rcb_route.ro_rt);
			rp->rcb_route.ro_rt = NULL;
		}
		if ((so->so_options & SO_DONTROUTE) == 0 &&
		    rp->rcb_route.ro_rt == 0) {
			rp->rcb_route.ro_dst = rp->rcb_faddr;
			rtalloc(&rp->rcb_route);
E 45
		}
E 44
D 30
#endif
E 30
E 29
E 26
D 12
		(void) (*so->so_proto->pr_output)(m, so);
E 12
I 12
		error = (*so->so_proto->pr_output)(m, so);
I 26
		m = NULL;
E 26
E 12
D 19
		if (addr)
E 19
I 19
		if (nam)
E 19
D 13
			rp->rcb_flags &= ~RAW_ADDR;
E 13
I 13
			rp->rcb_flags &= ~RAW_FADDR;
E 13
		break;

	case PRU_ABORT:
		raw_disconnect(rp);
		sofree(so);
		soisdisconnected(so);
		break;

I 34
	case PRU_SENSE:
		/*
		 * stat: don't bother with a blocksize.
		 */
		return (0);

E 34
I 27
D 33
	case PRU_CONTROL:
D 28
		return (EOPNOTSUPP);
E 28
I 28
		m = NULL;
		error = EOPNOTSUPP;
		break;
E 28

E 33
E 27
	/*
	 * Not supported.
	 */
D 33
	case PRU_ACCEPT:
E 33
I 33
D 43
	case PRU_CONTROL:
E 43
	case PRU_RCVOOB:
E 33
	case PRU_RCVD:
D 27
	case PRU_CONTROL:
E 27
D 34
	case PRU_SENSE:
E 34
D 33
	case PRU_RCVOOB:
E 33
I 33
		return(EOPNOTSUPP);

I 42
	case PRU_LISTEN:
E 42
	case PRU_ACCEPT:
E 33
	case PRU_SENDOOB:
		error = EOPNOTSUPP;
I 13
		break;

	case PRU_SOCKADDR:
D 19
		bcopy(addr, (caddr_t)&rp->rcb_laddr, sizeof (struct sockaddr));
E 19
I 19
D 22
		bcopy((caddr_t)&rp->rcb_laddr, mtod(nam, struct sockaddr *),
E 22
I 22
		bcopy((caddr_t)&rp->rcb_laddr, mtod(nam, caddr_t),
E 22
		    sizeof (struct sockaddr));
		nam->m_len = sizeof (struct sockaddr);
E 19
E 13
		break;

I 31
	case PRU_PEERADDR:
		bcopy((caddr_t)&rp->rcb_faddr, mtod(nam, caddr_t),
		    sizeof (struct sockaddr));
		nam->m_len = sizeof (struct sockaddr);
		break;

E 31
	default:
		panic("raw_usrreq");
	}
I 26
release:
	if (m != NULL)
		m_freem(m);
E 26
	return (error);
E 5
}
E 1
