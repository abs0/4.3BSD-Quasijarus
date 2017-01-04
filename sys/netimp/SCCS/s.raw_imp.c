h22254
s 00011/00006/00095
d D 7.4 88/06/29 16:58:13 bostic 25 24
c install approved copyright notice
e
s 00001/00001/00100
d D 7.3 88/05/26 09:43:37 karels 24 23
c lint
e
s 00009/00003/00092
d D 7.2 88/02/08 10:30:18 karels 23 22
c new copyrights; new IMP interface with H/W, using cb_output rather
c than cb_start (so can start RFNM timer when packet goes out, and output is
c round-robin by destination)
e
s 00001/00001/00094
d D 7.1 86/06/04 23:56:56 mckusick 22 21
c 4.3BSD release version
e
s 00007/00001/00088
d D 6.5 85/06/08 12:32:50 mckusick 21 20
c Add copyright
e
s 00006/00005/00083
d D 6.4 85/03/19 16:19:04 karels 20 19
c move net addresses from interface layer into protocols
e
s 00002/00008/00086
d D 6.3 85/02/28 14:27:39 karels 19 18
c mods for Classs B,C support, RFNM fixes from BRL
e
s 00007/00007/00087
d D 6.2 84/08/29 16:18:02 bloom 18 17
c Change to include files.  No more ../h
e
s 00000/00000/00094
d D 6.1 83/07/29 07:15:38 sam 17 16
c 4.2 distribution
e
s 00001/00000/00093
d D 4.16 83/06/30 01:17:21 sam 16 15
c revised raw code
e
s 00005/00003/00088
d D 4.15 83/02/10 22:17:23 sam 15 14
c remove /usr/include dependencies
e
s 00001/00001/00090
d D 4.14 82/10/21 21:22:55 root 14 13
c lint
e
s 00003/00003/00088
d D 4.13 82/10/09 05:46:33 wnj 13 12
c localize header files
e
s 00000/00001/00091
d D 4.12 82/06/20 00:54:53 sam 12 11
c purge COUNT stuff now that we can use gprof
e
s 00005/00001/00087
d D 4.11 82/04/11 15:51:37 sam 11 10
c sundry patches to raw code after rewrite
e
s 00021/00015/00067
d D 4.10 82/04/10 23:41:30 sam 10 9
c purge so_addr from socket structure and start cleaning up raw code
e
s 00006/00060/00076
d D 4.9 82/03/28 14:23:13 sam 9 8
c convert interfaces to sockaddr's and add hooks for routing
e
s 00001/00001/00135
d D 4.8 82/03/13 12:52:26 sam 8 7
c lint
e
s 00001/00001/00135
d D 4.7 82/03/05 14:07:04 wnj 7 6
c minor fixes
e
s 00002/00000/00134
d D 4.6 82/02/16 17:32:50 root 6 5
c remove implink restrictions to allow eavesdropping
e
s 00000/00002/00134
d D 4.5 82/02/16 17:06:58 root 5 4
c remove printf
e
s 00006/00006/00130
d D 4.4 82/02/15 11:07:40 root 4 3
c change names to be more "raw"
e
s 00026/00014/00110
d D 4.3 82/02/12 15:17:37 wnj 3 2
c closer to a working imp driver
e
s 00009/00009/00115
d D 4.2 82/02/01 22:49:47 sam 2 1
c cleanup before start of testing
e
s 00124/00000/00000
d D 4.1 82/02/01 12:59:39 root 1 0
c date and time created 82/02/01 12:59:39 by root
e
u
U
t
T
I 1
D 21
/*	%M%	%I%	%E%	*/
E 21
I 21
/*
D 22
 * Copyright (c) 1982 Regents of the University of California.
E 22
I 22
D 23
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 22
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 23
I 23
D 25
 * Copyright (c) 1982,1986,1988 Regents of the University of California.
E 25
I 25
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 25
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 25
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 25
I 25
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
E 25
E 23
 *
 *	%W% (Berkeley) %G%
 */
E 21

D 18
#include "../h/param.h"
#include "../h/mbuf.h"
#include "../h/socket.h"
#include "../h/protosw.h"
#include "../h/socketvar.h"
I 15
#include "../h/errno.h"
E 18
I 18
#include "param.h"
#include "mbuf.h"
#include "socket.h"
#include "protosw.h"
#include "socketvar.h"
#include "errno.h"
E 18

#include "../net/if.h"
I 16
#include "../net/route.h"
E 16
#include "../net/raw_cb.h"

E 15
D 13
#include "../net/in.h"
#include "../net/in_systm.h"
E 13
I 13
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
I 20
#include "../netinet/in_var.h"
E 20
E 13
D 15
#include "../net/if.h"
E 15
D 13
#include "../net/if_imp.h"
E 13
I 13
D 18
#include "../netimp/if_imp.h"
E 18
I 18
#include "if_imp.h"
E 18
E 13
D 15
#include "../net/raw_cb.h"
D 7
#include "/usr/include/errno.h"
E 7
I 7
D 10
#include "../errno.h"
E 10
I 10
#include <errno.h>
E 15
E 10
E 7

/*
 * Raw interface to IMP.
 */

D 9
/*ARGSUSED*/
D 4
imp_ctlinput(m)
E 4
I 4
rimp_ctlinput(m)
E 4
	struct mbuf *m;
{
D 4
COUNT(IMP_CTLINPUT);
E 4
I 4
COUNT(RIMP_CTLINPUT);
E 4
}

E 9
I 9
D 10
struct	sockaddr_in rawimpaddr = { AF_IMPLINK };
E 10
E 9
/*
 * Generate IMP leader and pass packet to impoutput.
 * The user must create a skeletal leader in order to
 * communicate message type, message subtype, etc.
 * We fill in holes where needed and verify parameters
 * supplied by user.
 */
D 4
imp_output(m, so)		/* too close to impoutput */
E 4
I 4
rimp_output(m, so)
E 4
	register struct mbuf *m;
	struct socket *so;
{
	struct mbuf *n;
D 10
	int len;
E 10
I 10
	int len, error = 0;
E 10
D 2
	register struct imp_leader *il;
E 2
I 2
	register struct imp_leader *ip;
E 2
	register struct sockaddr_in *sin;
	register struct rawcb *rp = sotorawcb(so);
I 3
D 20
	struct ifnet *ifp;
E 20
I 20
	struct in_ifaddr *ia;
E 20
	struct control_leader *cp;
E 3

D 4
COUNT(IMP_OUTPUT);
E 4
I 4
D 12
COUNT(RIMP_OUTPUT);
E 12
E 4
	/*
	 * Verify user has supplied necessary space
	 * for the leader and check parameters in it.
	 */
D 3
	if ((m->m_off > MMAXOFF || m->m_len < sizeof(struct imp_leader)) &&
	    (m = m_pullup(m, sizeof(struct imp_leader))) == 0)
		goto bad;
E 3
I 3
	if ((m->m_off > MMAXOFF || m->m_len < sizeof(struct control_leader)) &&
D 10
	    (m = m_pullup(m, sizeof(struct control_leader))) == 0)
		return (0);
E 10
I 10
	    (m = m_pullup(m, sizeof(struct control_leader))) == 0) {
		error = EMSGSIZE;	/* XXX */
		goto bad;
	}
E 10
	cp = mtod(m, struct control_leader *);
	if (cp->dl_mtype == IMPTYPE_DATA)
		if (m->m_len < sizeof(struct imp_leader) &&
D 10
		    (m = m_pullup(m, sizeof(struct imp_leader))) == 0)
			return (0);
E 10
I 10
		    (m = m_pullup(m, sizeof(struct imp_leader))) == 0) {
			error = EMSGSIZE;	/* XXX */
			goto bad;
		}
E 10
E 3
D 2
	il = mtod(m, struct imp_leader *);
	if (il->il_format != IMP_NFF)
E 2
I 2
	ip = mtod(m, struct imp_leader *);
D 10
	if (ip->il_format != IMP_NFF)
E 10
I 10
	if (ip->il_format != IMP_NFF) {
		error = EMSGSIZE;		/* XXX */
E 10
E 2
		goto bad;
I 10
	}
E 10
I 6
#ifdef notdef
E 6
D 2
	if (il->il_link != IMPLINK_IP &&
	    (il->il_link < IMPLINK_LOWEXPER || il->il_link > IMPLINK_HIGHEXPER))
E 2
I 2
	if (ip->il_link != IMPLINK_IP &&
D 10
	    (ip->il_link < IMPLINK_LOWEXPER || ip->il_link > IMPLINK_HIGHEXPER))
E 10
I 10
	    (ip->il_link<IMPLINK_LOWEXPER || ip->il_link>IMPLINK_HIGHEXPER)) {
		error = EPERM;
E 10
E 2
		goto bad;
I 10
	}
E 10
I 6
#endif
E 6

	/*
	 * Fill in IMP leader -- impoutput refrains from rebuilding
	 * the leader when it sees the protocol family PF_IMPLINK.
	 * (message size calculated by walking through mbuf's)
	 */
	for (len = 0, n = m; n; n = n->m_next)
		len += n->m_len;
D 2
	il->il_length = len << 3;
E 2
I 2
D 3
	ip->il_length = len << 3;
E 3
I 3
D 8
	ip->il_length = htons(len << 3);
E 8
I 8
	ip->il_length = htons((u_short)(len << 3));
E 8
E 3
E 2
D 10
	sin = (struct sockaddr_in *)&rp->rcb_addr;
E 10
I 10
	sin = (struct sockaddr_in *)&rp->rcb_faddr;
I 11
D 19
#ifdef notdef
E 11
E 10
D 2
	il->il_network = sin->sin_addr.s_net;
	il->il_host = sin->sin_addr.s_host;
	il->il_imp = sin->sin_addr.s_imp;
E 2
I 2
	ip->il_network = sin->sin_addr.s_net;
I 11
#else
	ip->il_network = 0;
#endif
E 11
	ip->il_host = sin->sin_addr.s_host;
	ip->il_imp = sin->sin_addr.s_imp;
E 19
I 19
D 20
	imp_addr_to_leader( ip, sin->sin_addr.s_addr );	/* BRL */
E 20
I 20
D 24
	imp_addr_to_leader(ip, sin->sin_addr.s_addr);	/* BRL */
E 24
I 24
	imp_addr_to_leader((struct control_leader *)ip, sin->sin_addr.s_addr);
E 24
E 20
E 19
I 3
D 5
printf("imp_output: net=%x, host=%x, imp=%x\n", ip->il_network, ip->il_host,
ip->il_impno);
E 5
D 9
	ifp = if_ifonnetof(sin->sin_addr);
	if (ifp == 0) {
		ifp = if_gatewayfor(sin->sin_addr);
		if (ifp == 0)
			goto bad;
	}
	return (impoutput(ifp, m, PF_IMPLINK));
E 9
I 9
	/* no routing here */
D 11
	ifp = if_ifonnetof(ip->il_network);
E 11
I 11
D 14
	ifp = if_ifonnetof(sin->sin_addr.s_net);
E 14
I 14
D 19
	ifp = if_ifonnetof((int)sin->sin_addr.s_net);
E 19
I 19
D 20
	ifp = if_ifonnetof(in_netof(sin->sin_addr));
E 19
E 14
E 11
D 10
	if (ifp == 0)
		goto bad;
	return (impoutput(ifp, m, (struct sockaddr *)&rawimpaddr));
E 9
E 3
E 2

E 10
I 10
	if (ifp)
		return (impoutput(ifp, m, (struct sockaddr *)sin));
E 20
I 20
	ia = in_iaonnetof(in_netof(sin->sin_addr));
	if (ia)
		return (impoutput(ia->ia_ifp, m, (struct sockaddr *)sin));
E 20
	error = ENETUNREACH;
E 10
D 3
	return (impoutput((struct ifnet *)rp->rcb_pcb, m, PF_IMPLINK));

E 3
bad:
	m_freem(m);
D 10
	return (0);
E 10
I 10
	return (error);
E 10
D 9
}

/*
 * Intercept operations required to
 * maintain interface pointer used on output.
 */
D 4
imp_usrreq(so, req, m, addr)
E 4
I 4
rimp_usrreq(so, req, m, addr)
E 4
	struct socket *so;
	int req;
	struct mbuf *m;
	caddr_t addr;
{
	register struct rawcb *rp = sotorawcb(so);
I 3
	register struct sockaddr_in *sin;
	register struct ifnet *ifp;
E 3

D 4
COUNT(IMP_USRREQ);
E 4
I 4
COUNT(RIMP_USRREQ);
E 4
	if (rp == 0 && req != PRU_ATTACH)
		return (EINVAL);

	switch (req) {

	/*
D 3
	 * Verify address has an interface to go with it
	 * and record information for use in output routine.
E 3
I 3
	 * Verify address has an interface to go with it.
E 3
	 */
D 3
	case PRU_SEND:
	case PRU_CONNECT: {
		register struct sockaddr_in *sin;
		register struct ifnet *ifp;

E 3
I 3
	case PRU_CONNECT:
		if (rp->rcb_pcb)
			return (EISCONN);
E 3
		sin = (struct sockaddr_in *)addr;
		ifp = if_ifonnetof(sin->sin_addr);
		if (ifp == 0) {
			ifp = if_gatewayfor(sin->sin_addr);
			if (ifp == 0)
				return (EADDRNOTAVAIL);	/* XXX */
		}
		rp->rcb_pcb = (caddr_t)ifp;
		break;
D 3
		}
E 3

	case PRU_DISCONNECT:
		rp->rcb_pcb = 0;
		break;

	case PRU_CONTROL:
		return (EOPNOTSUPP);
	}
	return (raw_usrreq(so, req, m, addr));
E 9
}
E 1
