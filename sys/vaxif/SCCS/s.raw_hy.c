h60743
s 00021/00001/00071
d D 7.2 88/08/04 15:25:14 bostic 7 6
c add Berkeley specific copyright
e
s 00000/00000/00072
d D 7.1 86/06/05 17:13:00 mckusick 6 5
c 4.3BSD release version
e
s 00000/00001/00072
d D 6.5 86/02/20 17:18:33 karels 5 4
c lint
e
s 00000/00003/00073
d D 6.4 85/12/19 15:49:33 karels 4 3
c rm bbnnet
e
s 00003/00000/00073
d D 6.3 85/10/24 10:08:44 bloom 3 2
c add "#if N?? > 0" 
e
s 00009/00006/00064
d D 6.2 85/09/16 22:35:57 karels 2 1
c convert to 4.3
e
s 00070/00000/00000
d D 6.1 85/06/24 15:42:59 karels 1 0
c from Glaser
e
u
U
t
T
I 1
/*
D 7
 *	%W%	%G%
E 7
I 7
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 7
 *
I 7
 * This code is derived from software contributed to Berkeley by
 * Tektronix Inc.
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
E 7
D 2
 * 4.2 BSD Unix kernel - NSC HYPERchannel support
 * NEEDS WORK FOR 4.3
E 2
I 2
 * 4.3 BSD Unix kernel - NSC HYPERchannel support
E 2
 *
 * $Header: raw_hy.c,v 3.1 84/02/15 04:27:44 steveg Exp $
 * $Locker:  $
 *
 * Copyright (c) 1984, Tektronix Inc.
 * All Rights Reserved
 *
 */

I 3
#include "hy.h"
#if NHY > 0
E 3

#include "param.h"
#include "mbuf.h"
#include "socket.h"
#include "protosw.h"
#include "socketvar.h"
#include "errno.h"

#include "../net/if.h"
#include "../net/route.h"
#include "../net/raw_cb.h"

I 2
D 4
#ifdef	BBNNET
#define	INET
#endif
E 4
E 2
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
I 2
#include "../netinet/in_var.h"
E 2
#include "if_hy.h"

/*
 * Raw interface to HYPERchannel.
 */

/*
 * Generate HYPERchannel leader and pass packet to hyoutput.
 * The user must create a skeletal leader in order to
 * communicate message type, message subtype, etc.
 * We don't really check the header supplied by the user.
 */
rhy_output(m, so)
	register struct mbuf *m;
	struct socket *so;
{
D 5
	struct mbuf *n;
E 5
	int error = 0;
	register struct sockaddr_in *sin;
	register struct rawcb *rp = sotorawcb(so);
D 2
	struct ifnet *ifp;
E 2
I 2
	struct in_ifaddr *ia;
E 2

	/*
	 * Verify user has supplied necessary space
	 * for the header.
	 */
	if ((m->m_off > MMAXOFF || m->m_len < sizeof(struct hym_hdr)) &&
	    (m = m_pullup(m, sizeof(struct hym_hdr))) == 0) {
		error = EMSGSIZE;	/* XXX */
		goto bad;
	}

	sin = (struct sockaddr_in *)&rp->rcb_faddr;
	/* no routing here */
D 2
	ifp = if_ifonnetof((int)sin->sin_addr.s_net);
	if (ifp)
		return (hyoutput(ifp, m, (struct sockaddr *)sin));
E 2
I 2
	ia = in_iaonnetof(in_netof(sin->sin_addr));
	if (ia)
		return (hyoutput(ia->ia_ifp, m, (struct sockaddr *)sin));
E 2
	error = ENETUNREACH;
bad:
	m_freem(m);
	return (error);
}
I 3
#endif
E 3
E 1
